/*
 * Copyright (C) 2021-2023 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#if ENABLE(GPU_PROCESS)
#include "GPUProcess.h"

#include "ArgumentCoders.h" // NOLINT
#include "ConnectionHandle.h" // NOLINT
#if HAVE(AUDIT_TOKEN) || PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
#include "CoreIPCAuditToken.h" // NOLINT
#endif
#include "Decoder.h" // NOLINT
#include "GPUProcessConnectionParameters.h" // NOLINT
#include "GPUProcessCreationParameters.h" // NOLINT
#include "GPUProcessMessages.h" // NOLINT
#include "GPUProcessPreferences.h" // NOLINT
#include "GPUProcessSessionParameters.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "SandboxExtension.h" // NOLINT
#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
#include "SharedBufferReference.h" // NOLINT
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
#include "SharedFileHandle.h" // NOLINT
#endif
#include "SharedPreferencesForWebProcess.h" // NOLINT
#if HAVE(SCREEN_CAPTURE_KIT)
#include <WebCore/CaptureDevice.h> // NOLINT
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
#include <WebCore/DisplayCapturePromptType.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/IntDegrees.h> // NOLINT
#endif
#if ENABLE(VIDEO)
#include <WebCore/MediaPlayerIdentifier.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/MockMediaDevice.h> // NOLINT
#endif
#if HAVE(AUDIT_TOKEN)
#include <WebCore/PageIdentifier.h> // NOLINT
#endif
#include <WebCore/ProcessIdentifier.h> // NOLINT
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN)) || ENABLE(WEBXR)
#include <WebCore/ProcessIdentity.h> // NOLINT
#endif
#if PLATFORM(MAC)
#include <WebCore/ScreenProperties.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/SecurityOriginData.h> // NOLINT
#endif
#if ENABLE(VIDEO)
#include <WebCore/ShareableBitmapHandle.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/VideoFrame.h> // NOLINT
#endif
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN)) || ENABLE(VIDEO) || ENABLE(WEBXR) || HAVE(AUDIT_TOKEN) || HAVE(SCREEN_CAPTURE_KIT) || PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
#include <optional> // NOLINT
#endif
#include <pal/SessionID.h> // NOLINT
#if USE(EXTENSIONKIT)
#include <span> // NOLINT
#endif
#include <wtf/MonotonicTime.h> // NOLINT
#include <wtf/Vector.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void GPUProcess::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::GPUProcess::InitializeGPUProcess::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::InitializeGPUProcess>(connection, decoder, this, &GPUProcess::initializeGPUProcess);
    if (decoder.messageName() == Messages::GPUProcess::CreateGPUConnectionToWebProcess::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::CreateGPUConnectionToWebProcess>(connection, decoder, this, &GPUProcess::createGPUConnectionToWebProcess);
    if (decoder.messageName() == Messages::GPUProcess::SharedPreferencesForWebProcessDidChange::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::SharedPreferencesForWebProcessDidChange>(connection, decoder, this, &GPUProcess::sharedPreferencesForWebProcessDidChange);
    if (decoder.messageName() == Messages::GPUProcess::UpdateGPUProcessPreferences::name())
        return IPC::handleMessage<Messages::GPUProcess::UpdateGPUProcessPreferences>(connection, decoder, this, &GPUProcess::updateGPUProcessPreferences);
    if (decoder.messageName() == Messages::GPUProcess::UpdateSandboxAccess::name())
        return IPC::handleMessage<Messages::GPUProcess::UpdateSandboxAccess>(connection, decoder, this, &GPUProcess::updateSandboxAccess);
    if (decoder.messageName() == Messages::GPUProcess::PrepareToSuspend::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::PrepareToSuspend>(connection, decoder, this, &GPUProcess::prepareToSuspend);
    if (decoder.messageName() == Messages::GPUProcess::ProcessDidResume::name())
        return IPC::handleMessage<Messages::GPUProcess::ProcessDidResume>(connection, decoder, this, &GPUProcess::processDidResume);
    if (decoder.messageName() == Messages::GPUProcess::AddSession::name())
        return IPC::handleMessage<Messages::GPUProcess::AddSession>(connection, decoder, this, &GPUProcess::addSession);
    if (decoder.messageName() == Messages::GPUProcess::RemoveSession::name())
        return IPC::handleMessage<Messages::GPUProcess::RemoveSession>(connection, decoder, this, &GPUProcess::removeSession);
#if ENABLE(MEDIA_STREAM)
    if (decoder.messageName() == Messages::GPUProcess::SetMockCaptureDevicesEnabled::name())
        return IPC::handleMessage<Messages::GPUProcess::SetMockCaptureDevicesEnabled>(connection, decoder, this, &GPUProcess::setMockCaptureDevicesEnabled);
    if (decoder.messageName() == Messages::GPUProcess::SetOrientationForMediaCapture::name())
        return IPC::handleMessage<Messages::GPUProcess::SetOrientationForMediaCapture>(connection, decoder, this, &GPUProcess::setOrientationForMediaCapture);
    if (decoder.messageName() == Messages::GPUProcess::RotationAngleForCaptureDeviceChanged::name())
        return IPC::handleMessage<Messages::GPUProcess::RotationAngleForCaptureDeviceChanged>(connection, decoder, this, &GPUProcess::rotationAngleForCaptureDeviceChanged);
    if (decoder.messageName() == Messages::GPUProcess::UpdateCaptureAccess::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::UpdateCaptureAccess>(connection, decoder, this, &GPUProcess::updateCaptureAccess);
    if (decoder.messageName() == Messages::GPUProcess::UpdateCaptureOrigin::name())
        return IPC::handleMessage<Messages::GPUProcess::UpdateCaptureOrigin>(connection, decoder, this, &GPUProcess::updateCaptureOrigin);
    if (decoder.messageName() == Messages::GPUProcess::AddMockMediaDevice::name())
        return IPC::handleMessage<Messages::GPUProcess::AddMockMediaDevice>(connection, decoder, this, &GPUProcess::addMockMediaDevice);
    if (decoder.messageName() == Messages::GPUProcess::ClearMockMediaDevices::name())
        return IPC::handleMessage<Messages::GPUProcess::ClearMockMediaDevices>(connection, decoder, this, &GPUProcess::clearMockMediaDevices);
    if (decoder.messageName() == Messages::GPUProcess::RemoveMockMediaDevice::name())
        return IPC::handleMessage<Messages::GPUProcess::RemoveMockMediaDevice>(connection, decoder, this, &GPUProcess::removeMockMediaDevice);
    if (decoder.messageName() == Messages::GPUProcess::SetMockMediaDeviceIsEphemeral::name())
        return IPC::handleMessage<Messages::GPUProcess::SetMockMediaDeviceIsEphemeral>(connection, decoder, this, &GPUProcess::setMockMediaDeviceIsEphemeral);
    if (decoder.messageName() == Messages::GPUProcess::ResetMockMediaDevices::name())
        return IPC::handleMessage<Messages::GPUProcess::ResetMockMediaDevices>(connection, decoder, this, &GPUProcess::resetMockMediaDevices);
    if (decoder.messageName() == Messages::GPUProcess::SetMockCaptureDevicesInterrupted::name())
        return IPC::handleMessage<Messages::GPUProcess::SetMockCaptureDevicesInterrupted>(connection, decoder, this, &GPUProcess::setMockCaptureDevicesInterrupted);
    if (decoder.messageName() == Messages::GPUProcess::TriggerMockCaptureConfigurationChange::name())
        return IPC::handleMessage<Messages::GPUProcess::TriggerMockCaptureConfigurationChange>(connection, decoder, this, &GPUProcess::triggerMockCaptureConfigurationChange);
    if (decoder.messageName() == Messages::GPUProcess::SetShouldListenToVoiceActivity::name())
        return IPC::handleMessage<Messages::GPUProcess::SetShouldListenToVoiceActivity>(connection, decoder, this, &GPUProcess::setShouldListenToVoiceActivity);
    if (decoder.messageName() == Messages::GPUProcess::EnableMicrophoneMuteStatusAPI::name())
        return IPC::handleMessage<Messages::GPUProcess::EnableMicrophoneMuteStatusAPI>(connection, decoder, this, &GPUProcess::enableMicrophoneMuteStatusAPI);
#endif
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::GPUProcess::SetScreenProperties::name())
        return IPC::handleMessage<Messages::GPUProcess::SetScreenProperties>(connection, decoder, this, &GPUProcess::setScreenProperties);
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
    if (decoder.messageName() == Messages::GPUProcess::PromptForGetDisplayMedia::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::PromptForGetDisplayMedia>(connection, decoder, this, &GPUProcess::promptForGetDisplayMedia);
    if (decoder.messageName() == Messages::GPUProcess::CancelGetDisplayMediaPrompt::name())
        return IPC::handleMessage<Messages::GPUProcess::CancelGetDisplayMediaPrompt>(connection, decoder, this, &GPUProcess::cancelGetDisplayMediaPrompt);
#endif
#if ENABLE(VIDEO)
    if (decoder.messageName() == Messages::GPUProcess::RequestBitmapImageForCurrentTime::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::RequestBitmapImageForCurrentTime>(connection, decoder, this, &GPUProcess::requestBitmapImageForCurrentTime);
#endif
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::GPUProcess::OpenDirectoryCacheInvalidated::name())
        return IPC::handleMessage<Messages::GPUProcess::OpenDirectoryCacheInvalidated>(connection, decoder, this, &GPUProcess::openDirectoryCacheInvalidated);
#endif
#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
    if (decoder.messageName() == Messages::GPUProcess::ConsumeAudioComponentRegistrations::name())
        return IPC::handleMessage<Messages::GPUProcess::ConsumeAudioComponentRegistrations>(connection, decoder, this, &GPUProcess::consumeAudioComponentRegistrations);
#endif
#if HAVE(POWERLOG_TASK_MODE_QUERY)
    if (decoder.messageName() == Messages::GPUProcess::EnablePowerLogging::name())
        return IPC::handleMessage<Messages::GPUProcess::EnablePowerLogging>(connection, decoder, this, &GPUProcess::enablePowerLogging);
#endif
    if (decoder.messageName() == Messages::GPUProcess::UserPreferredLanguagesChanged::name())
        return IPC::handleMessage<Messages::GPUProcess::UserPreferredLanguagesChanged>(connection, decoder, this, &GPUProcess::userPreferredLanguagesChanged);
    if (decoder.messageName() == Messages::GPUProcess::WebProcessConnectionCountForTesting::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::WebProcessConnectionCountForTesting>(connection, decoder, this, &GPUProcess::webProcessConnectionCountForTesting);
#if USE(EXTENSIONKIT)
    if (decoder.messageName() == Messages::GPUProcess::ResolveBookmarkDataForCacheDirectory::name())
        return IPC::handleMessage<Messages::GPUProcess::ResolveBookmarkDataForCacheDirectory>(connection, decoder, this, &GPUProcess::resolveBookmarkDataForCacheDirectory);
#endif
#if ENABLE(WEBXR)
    if (decoder.messageName() == Messages::GPUProcess::WebXRPromptAccepted::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::WebXRPromptAccepted>(connection, decoder, this, &GPUProcess::webXRPromptAccepted);
#endif
#if HAVE(AUDIT_TOKEN)
    if (decoder.messageName() == Messages::GPUProcess::SetPresentingApplicationAuditToken::name())
        return IPC::handleMessage<Messages::GPUProcess::SetPresentingApplicationAuditToken>(connection, decoder, this, &GPUProcess::setPresentingApplicationAuditToken);
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    if (decoder.messageName() == Messages::GPUProcess::RequestSharedSimulationConnection::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::RequestSharedSimulationConnection>(connection, decoder, this, &GPUProcess::requestSharedSimulationConnection);
#endif
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    if (decoder.messageName() == Messages::GPUProcess::CreateMemoryAttributionIDForTask::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::CreateMemoryAttributionIDForTask>(connection, decoder, this, &GPUProcess::createMemoryAttributionIDForTask);
    if (decoder.messageName() == Messages::GPUProcess::UnregisterMemoryAttributionID::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::UnregisterMemoryAttributionID>(connection, decoder, this, &GPUProcess::unregisterMemoryAttributionID);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::GPUProcess::PostWillTakeSnapshotNotification::name())
        return IPC::handleMessageAsync<Messages::GPUProcess::PostWillTakeSnapshotNotification>(connection, decoder, this, &GPUProcess::postWillTakeSnapshotNotification);
    if (decoder.messageName() == Messages::GPUProcess::RegisterFonts::name())
        return IPC::handleMessage<Messages::GPUProcess::RegisterFonts>(connection, decoder, this, &GPUProcess::registerFonts);
#endif
    AuxiliaryProcess::didReceiveMessage(connection, decoder);
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_InitializeGPUProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::InitializeGPUProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_InitializeGPUProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::InitializeGPUProcess::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_CreateGPUConnectionToWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::CreateGPUConnectionToWebProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_CreateGPUConnectionToWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::CreateGPUConnectionToWebProcess::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_SharedPreferencesForWebProcessDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SharedPreferencesForWebProcessDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_SharedPreferencesForWebProcessDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SharedPreferencesForWebProcessDidChange::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_UpdateGPUProcessPreferences>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::UpdateGPUProcessPreferences::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_UpdateSandboxAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::UpdateSandboxAccess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_PrepareToSuspend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::PrepareToSuspend::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_PrepareToSuspend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::PrepareToSuspend::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_ProcessDidResume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::ProcessDidResume::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_AddSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::AddSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_RemoveSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::RemoveSession::Arguments>(globalObject, decoder);
}
#if ENABLE(MEDIA_STREAM)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_SetMockCaptureDevicesEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SetMockCaptureDevicesEnabled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_SetOrientationForMediaCapture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SetOrientationForMediaCapture::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_RotationAngleForCaptureDeviceChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::RotationAngleForCaptureDeviceChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_UpdateCaptureAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::UpdateCaptureAccess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_UpdateCaptureAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::UpdateCaptureAccess::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_UpdateCaptureOrigin>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::UpdateCaptureOrigin::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_AddMockMediaDevice>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::AddMockMediaDevice::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_ClearMockMediaDevices>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::ClearMockMediaDevices::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_RemoveMockMediaDevice>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::RemoveMockMediaDevice::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_SetMockMediaDeviceIsEphemeral>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SetMockMediaDeviceIsEphemeral::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_ResetMockMediaDevices>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::ResetMockMediaDevices::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_SetMockCaptureDevicesInterrupted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SetMockCaptureDevicesInterrupted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_TriggerMockCaptureConfigurationChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::TriggerMockCaptureConfigurationChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_SetShouldListenToVoiceActivity>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SetShouldListenToVoiceActivity::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_EnableMicrophoneMuteStatusAPI>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::EnableMicrophoneMuteStatusAPI::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_SetScreenProperties>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SetScreenProperties::Arguments>(globalObject, decoder);
}
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_PromptForGetDisplayMedia>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::PromptForGetDisplayMedia::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_PromptForGetDisplayMedia>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::PromptForGetDisplayMedia::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_CancelGetDisplayMediaPrompt>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::CancelGetDisplayMediaPrompt::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(VIDEO)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_RequestBitmapImageForCurrentTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::RequestBitmapImageForCurrentTime::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_RequestBitmapImageForCurrentTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::RequestBitmapImageForCurrentTime::ReplyArguments>(globalObject, decoder);
}
#endif
#if PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_OpenDirectoryCacheInvalidated>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::OpenDirectoryCacheInvalidated::Arguments>(globalObject, decoder);
}
#endif
#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_ConsumeAudioComponentRegistrations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::ConsumeAudioComponentRegistrations::Arguments>(globalObject, decoder);
}
#endif
#if HAVE(POWERLOG_TASK_MODE_QUERY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_EnablePowerLogging>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::EnablePowerLogging::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_UserPreferredLanguagesChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::UserPreferredLanguagesChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_WebProcessConnectionCountForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::WebProcessConnectionCountForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_WebProcessConnectionCountForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::WebProcessConnectionCountForTesting::ReplyArguments>(globalObject, decoder);
}
#if USE(EXTENSIONKIT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_ResolveBookmarkDataForCacheDirectory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::ResolveBookmarkDataForCacheDirectory::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(WEBXR)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_WebXRPromptAccepted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::WebXRPromptAccepted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_WebXRPromptAccepted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::WebXRPromptAccepted::ReplyArguments>(globalObject, decoder);
}
#endif
#if HAVE(AUDIT_TOKEN)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_SetPresentingApplicationAuditToken>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::SetPresentingApplicationAuditToken::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_RequestSharedSimulationConnection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::RequestSharedSimulationConnection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_RequestSharedSimulationConnection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::RequestSharedSimulationConnection::ReplyArguments>(globalObject, decoder);
}
#endif
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_CreateMemoryAttributionIDForTask>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::CreateMemoryAttributionIDForTask::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_CreateMemoryAttributionIDForTask>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::CreateMemoryAttributionIDForTask::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_UnregisterMemoryAttributionID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::UnregisterMemoryAttributionID::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_UnregisterMemoryAttributionID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::UnregisterMemoryAttributionID::ReplyArguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_PostWillTakeSnapshotNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::PostWillTakeSnapshotNotification::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcess_PostWillTakeSnapshotNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::PostWillTakeSnapshotNotification::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcess_RegisterFonts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcess::RegisterFonts::Arguments>(globalObject, decoder);
}
#endif

}

#endif


#endif // ENABLE(GPU_PROCESS)
