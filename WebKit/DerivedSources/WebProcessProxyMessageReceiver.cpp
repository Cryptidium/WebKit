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
#include "WebProcessProxy.h"

#include "ArgumentCoders.h" // NOLINT
#if ENABLE(GPU_PROCESS) || ENABLE(MODEL_PROCESS)
#include "ConnectionHandle.h" // NOLINT
#endif
#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
#include "CoreIPCAuditToken.h" // NOLINT
#endif
#include "Decoder.h" // NOLINT
#if HAVE(DISPLAY_LINK)
#include "DisplayLinkObserverID.h" // NOLINT
#endif
#if ENABLE(GPU_PROCESS)
#include "GPUProcessConnectionIdentifier.h" // NOLINT
#endif
#include "HandleMessage.h" // NOLINT
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
#include "IPCSemaphore.h" // NOLINT
#endif
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && !ENABLE(STREAMING_IPC_IN_LOG_FORWARDING)) || (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
#include "LogStreamIdentifier.h" // NOLINT
#endif
#if ENABLE(MODEL_PROCESS)
#include "ModelProcessConnectionParameters.h" // NOLINT
#endif
#include "NetworkProcessConnectionInfo.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
#include "StreamServerConnection.h" // NOLINT
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
#include "UserMessage.h" // NOLINT
#endif
#include "WebProcessProxyMessages.h" // NOLINT
#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
#include <WebCore/CaptionUserPreferences.h> // NOLINT
#endif
#include <WebCore/CryptoKeyData.h> // NOLINT
#if ENABLE(NOTIFICATION_EVENT)
#include <WebCore/NotificationData.h> // NOLINT
#endif
#include <WebCore/PageIdentifier.h> // NOLINT
#include <WebCore/PrewarmInformation.h> // NOLINT
#include <WebCore/RegistrableDomain.h> // NOLINT
#include <WebCore/SecurityOriginData.h> // NOLINT
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
#include <WebCore/ServiceWorkerIdentifier.h> // NOLINT
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
#include <WebCore/ServiceWorkerTypes.h> // NOLINT
#endif
#include <WebCore/UserGestureTokenIdentifier.h> // NOLINT
#include <WebCore/WrappedCryptoKey.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/MemoryPressureHandler.h> // NOLINT
#if ENABLE(NOTIFICATION_EVENT) || ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
#include <wtf/URLHash.h> // NOLINT
#endif
#include <wtf/Vector.h> // NOLINT
#if ENABLE(NOTIFICATION_EVENT) || ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA) || HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK) || PLATFORM(COCOA)
#include <wtf/text/WTFString.h> // NOLINT
#endif

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebProcessProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebProcessProxy::DidDestroyUserGestureToken::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DidDestroyUserGestureToken>(connection, decoder, this, &WebProcessProxy::didDestroyUserGestureToken);
    if (decoder.messageName() == Messages::WebProcessProxy::EnableSuddenTermination::name())
        return IPC::handleMessage<Messages::WebProcessProxy::EnableSuddenTermination>(connection, decoder, this, &WebProcessProxy::enableSuddenTermination);
    if (decoder.messageName() == Messages::WebProcessProxy::DisableSuddenTermination::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DisableSuddenTermination>(connection, decoder, this, &WebProcessProxy::disableSuddenTermination);
#if ENABLE(GPU_PROCESS)
    if (decoder.messageName() == Messages::WebProcessProxy::CreateGPUProcessConnection::name())
        return IPC::handleMessage<Messages::WebProcessProxy::CreateGPUProcessConnection>(connection, decoder, this, &WebProcessProxy::createGPUProcessConnection);
    if (decoder.messageName() == Messages::WebProcessProxy::GPUProcessConnectionDidBecomeUnresponsive::name())
        return IPC::handleMessage<Messages::WebProcessProxy::GPUProcessConnectionDidBecomeUnresponsive>(connection, decoder, this, &WebProcessProxy::gpuProcessConnectionDidBecomeUnresponsive);
#endif
#if ENABLE(MODEL_PROCESS)
    if (decoder.messageName() == Messages::WebProcessProxy::CreateModelProcessConnection::name())
        return IPC::handleMessage<Messages::WebProcessProxy::CreateModelProcessConnection>(connection, decoder, this, &WebProcessProxy::createModelProcessConnection);
#endif
    if (decoder.messageName() == Messages::WebProcessProxy::DidExceedActiveMemoryLimit::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DidExceedActiveMemoryLimit>(connection, decoder, this, &WebProcessProxy::didExceedActiveMemoryLimit);
    if (decoder.messageName() == Messages::WebProcessProxy::DidExceedInactiveMemoryLimit::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DidExceedInactiveMemoryLimit>(connection, decoder, this, &WebProcessProxy::didExceedInactiveMemoryLimit);
    if (decoder.messageName() == Messages::WebProcessProxy::DidExceedMemoryFootprintThreshold::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DidExceedMemoryFootprintThreshold>(connection, decoder, this, &WebProcessProxy::didExceedMemoryFootprintThreshold);
    if (decoder.messageName() == Messages::WebProcessProxy::DidExceedCPULimit::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DidExceedCPULimit>(connection, decoder, this, &WebProcessProxy::didExceedCPULimit);
    if (decoder.messageName() == Messages::WebProcessProxy::StopResponsivenessTimer::name())
        return IPC::handleMessage<Messages::WebProcessProxy::StopResponsivenessTimer>(connection, decoder, this, &WebProcessProxy::stopResponsivenessTimer);
    if (decoder.messageName() == Messages::WebProcessProxy::DidReceiveBackgroundResponsivenessPing::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DidReceiveBackgroundResponsivenessPing>(connection, decoder, this, &WebProcessProxy::didReceiveBackgroundResponsivenessPing);
    if (decoder.messageName() == Messages::WebProcessProxy::MemoryPressureStatusChanged::name())
        return IPC::handleMessage<Messages::WebProcessProxy::MemoryPressureStatusChanged>(connection, decoder, this, &WebProcessProxy::memoryPressureStatusChanged);
    if (decoder.messageName() == Messages::WebProcessProxy::DidCollectPrewarmInformation::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DidCollectPrewarmInformation>(connection, decoder, this, &WebProcessProxy::didCollectPrewarmInformation);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebProcessProxy::CacheMediaMIMETypes::name())
        return IPC::handleMessage<Messages::WebProcessProxy::CacheMediaMIMETypes>(connection, decoder, this, &WebProcessProxy::cacheMediaMIMETypes);
#endif
#if HAVE(DISPLAY_LINK)
    if (decoder.messageName() == Messages::WebProcessProxy::StartDisplayLink::name())
        return IPC::handleMessage<Messages::WebProcessProxy::StartDisplayLink>(connection, decoder, this, &WebProcessProxy::startDisplayLink);
    if (decoder.messageName() == Messages::WebProcessProxy::StopDisplayLink::name())
        return IPC::handleMessage<Messages::WebProcessProxy::StopDisplayLink>(connection, decoder, this, &WebProcessProxy::stopDisplayLink);
    if (decoder.messageName() == Messages::WebProcessProxy::SetDisplayLinkPreferredFramesPerSecond::name())
        return IPC::handleMessage<Messages::WebProcessProxy::SetDisplayLinkPreferredFramesPerSecond>(connection, decoder, this, &WebProcessProxy::setDisplayLinkPreferredFramesPerSecond);
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    if (decoder.messageName() == Messages::WebProcessProxy::SendMessageToWebContext::name())
        return IPC::handleMessage<Messages::WebProcessProxy::SendMessageToWebContext>(connection, decoder, this, &WebProcessProxy::sendMessageToWebContext);
    if (decoder.messageName() == Messages::WebProcessProxy::SendMessageToWebContextWithReply::name())
        return IPC::handleMessageAsync<Messages::WebProcessProxy::SendMessageToWebContextWithReply>(connection, decoder, this, &WebProcessProxy::sendMessageToWebContextWithReply);
#endif
    if (decoder.messageName() == Messages::WebProcessProxy::CreateSpeechRecognitionServer::name()) {
        if (!(sharedPreferences && sharedPreferences->speechRecognitionEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebProcessProxy::CreateSpeechRecognitionServer>(connection, decoder, this, &WebProcessProxy::createSpeechRecognitionServer);
    }
    if (decoder.messageName() == Messages::WebProcessProxy::DestroySpeechRecognitionServer::name()) {
        if (!(sharedPreferences && sharedPreferences->speechRecognitionEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebProcessProxy::DestroySpeechRecognitionServer>(connection, decoder, this, &WebProcessProxy::destroySpeechRecognitionServer);
    }
    if (decoder.messageName() == Messages::WebProcessProxy::SystemBeep::name())
        return IPC::handleMessage<Messages::WebProcessProxy::SystemBeep>(connection, decoder, this, &WebProcessProxy::systemBeep);
#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
    if (decoder.messageName() == Messages::WebProcessProxy::SetCaptionDisplayMode::name())
        return IPC::handleMessage<Messages::WebProcessProxy::SetCaptionDisplayMode>(connection, decoder, this, &WebProcessProxy::setCaptionDisplayMode);
    if (decoder.messageName() == Messages::WebProcessProxy::SetCaptionLanguage::name())
        return IPC::handleMessage<Messages::WebProcessProxy::SetCaptionLanguage>(connection, decoder, this, &WebProcessProxy::setCaptionLanguage);
#endif
#if ENABLE(NOTIFICATION_EVENT)
    if (decoder.messageName() == Messages::WebProcessProxy::GetNotifications::name()) {
        if (!(sharedPreferences && sharedPreferences->notificationEventEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebProcessProxy::GetNotifications>(connection, decoder, this, &WebProcessProxy::getNotifications);
    }
#endif
    if (decoder.messageName() == Messages::WebProcessProxy::SetAppBadgeFromWorker::name()) {
        if (!(sharedPreferences && sharedPreferences->appBadgeEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebProcessProxy::SetAppBadgeFromWorker>(connection, decoder, this, &WebProcessProxy::setAppBadgeFromWorker);
    }
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
    if (decoder.messageName() == Messages::WebProcessProxy::SetupLogStream::name())
        return IPC::handleMessageAsync<Messages::WebProcessProxy::SetupLogStream>(connection, decoder, this, &WebProcessProxy::setupLogStream);
#endif
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && !ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
    if (decoder.messageName() == Messages::WebProcessProxy::SetupLogStream::name())
        return IPC::handleMessageAsync<Messages::WebProcessProxy::SetupLogStream>(connection, decoder, this, &WebProcessProxy::setupLogStream);
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebProcessProxy::CreateServiceWorkerDebuggable::name())
        return IPC::handleMessageAsync<Messages::WebProcessProxy::CreateServiceWorkerDebuggable>(connection, decoder, this, &WebProcessProxy::createServiceWorkerDebuggable);
    if (decoder.messageName() == Messages::WebProcessProxy::DeleteServiceWorkerDebuggable::name())
        return IPC::handleMessage<Messages::WebProcessProxy::DeleteServiceWorkerDebuggable>(connection, decoder, this, &WebProcessProxy::deleteServiceWorkerDebuggable);
    if (decoder.messageName() == Messages::WebProcessProxy::SendMessageToInspector::name())
        return IPC::handleMessage<Messages::WebProcessProxy::SendMessageToInspector>(connection, decoder, this, &WebProcessProxy::sendMessageToInspector);
#endif
    if (dispatchMessage(connection, decoder))
        return;
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool WebProcessProxy::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(!isInAuxiliaryProcess());
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebProcessProxy::ShouldTerminate::name())
        return IPC::handleMessageSynchronous<Messages::WebProcessProxy::ShouldTerminate>(connection, decoder, replyEncoder, this, &WebProcessProxy::shouldTerminate);
    if (decoder.messageName() == Messages::WebProcessProxy::GetNetworkProcessConnection::name())
        return IPC::handleMessageSynchronous<Messages::WebProcessProxy::GetNetworkProcessConnection>(connection, decoder, replyEncoder, this, &WebProcessProxy::getNetworkProcessConnection);
    if (decoder.messageName() == Messages::WebProcessProxy::WaitForSharedPreferencesForWebProcessToSync::name())
        return IPC::handleMessageSynchronous<Messages::WebProcessProxy::WaitForSharedPreferencesForWebProcessToSync>(connection, decoder, replyEncoder, this, &WebProcessProxy::waitForSharedPreferencesForWebProcessToSync);
#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
    if (decoder.messageName() == Messages::WebProcessProxy::IsAXAuthenticated::name())
        return IPC::handleMessageSynchronous<Messages::WebProcessProxy::IsAXAuthenticated>(connection, decoder, replyEncoder, this, &WebProcessProxy::isAXAuthenticated);
#endif
    if (decoder.messageName() == Messages::WebProcessProxy::SerializeAndWrapCryptoKey::name())
        return IPC::handleMessageSynchronous<Messages::WebProcessProxy::SerializeAndWrapCryptoKey>(connection, decoder, replyEncoder, this, &WebProcessProxy::serializeAndWrapCryptoKey);
    if (decoder.messageName() == Messages::WebProcessProxy::UnwrapCryptoKey::name())
        return IPC::handleMessageSynchronous<Messages::WebProcessProxy::UnwrapCryptoKey>(connection, decoder, replyEncoder, this, &WebProcessProxy::unwrapCryptoKey);
    if (dispatchSyncMessage(connection, decoder, replyEncoder))
        return true;
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DidDestroyUserGestureToken>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DidDestroyUserGestureToken::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_ShouldTerminate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::ShouldTerminate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_ShouldTerminate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::ShouldTerminate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_EnableSuddenTermination>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::EnableSuddenTermination::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DisableSuddenTermination>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DisableSuddenTermination::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_GetNetworkProcessConnection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::GetNetworkProcessConnection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_GetNetworkProcessConnection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::GetNetworkProcessConnection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_WaitForSharedPreferencesForWebProcessToSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::WaitForSharedPreferencesForWebProcessToSync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_WaitForSharedPreferencesForWebProcessToSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::WaitForSharedPreferencesForWebProcessToSync::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(GPU_PROCESS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_CreateGPUProcessConnection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::CreateGPUProcessConnection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_GPUProcessConnectionDidBecomeUnresponsive>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::GPUProcessConnectionDidBecomeUnresponsive::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(MODEL_PROCESS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_CreateModelProcessConnection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::CreateModelProcessConnection::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DidExceedActiveMemoryLimit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DidExceedActiveMemoryLimit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DidExceedInactiveMemoryLimit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DidExceedInactiveMemoryLimit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DidExceedMemoryFootprintThreshold>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DidExceedMemoryFootprintThreshold::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DidExceedCPULimit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DidExceedCPULimit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_StopResponsivenessTimer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::StopResponsivenessTimer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DidReceiveBackgroundResponsivenessPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DidReceiveBackgroundResponsivenessPing::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_MemoryPressureStatusChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::MemoryPressureStatusChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DidCollectPrewarmInformation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DidCollectPrewarmInformation::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_CacheMediaMIMETypes>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::CacheMediaMIMETypes::Arguments>(globalObject, decoder);
}
#endif
#if HAVE(DISPLAY_LINK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_StartDisplayLink>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::StartDisplayLink::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_StopDisplayLink>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::StopDisplayLink::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SetDisplayLinkPreferredFramesPerSecond>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SetDisplayLinkPreferredFramesPerSecond::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SendMessageToWebContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SendMessageToWebContext::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SendMessageToWebContextWithReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SendMessageToWebContextWithReply::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_SendMessageToWebContextWithReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SendMessageToWebContextWithReply::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_CreateSpeechRecognitionServer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::CreateSpeechRecognitionServer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DestroySpeechRecognitionServer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DestroySpeechRecognitionServer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SystemBeep>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SystemBeep::Arguments>(globalObject, decoder);
}
#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_IsAXAuthenticated>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::IsAXAuthenticated::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_IsAXAuthenticated>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::IsAXAuthenticated::ReplyArguments>(globalObject, decoder);
}
#endif
#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SetCaptionDisplayMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SetCaptionDisplayMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SetCaptionLanguage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SetCaptionLanguage::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(NOTIFICATION_EVENT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_GetNotifications>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::GetNotifications::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_GetNotifications>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::GetNotifications::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SetAppBadgeFromWorker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SetAppBadgeFromWorker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SerializeAndWrapCryptoKey>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SerializeAndWrapCryptoKey::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_SerializeAndWrapCryptoKey>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SerializeAndWrapCryptoKey::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_UnwrapCryptoKey>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::UnwrapCryptoKey::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_UnwrapCryptoKey>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::UnwrapCryptoKey::ReplyArguments>(globalObject, decoder);
}
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SetupLogStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SetupLogStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_SetupLogStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SetupLogStream::ReplyArguments>(globalObject, decoder);
}
#endif
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && !ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SetupLogStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SetupLogStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_SetupLogStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SetupLogStream::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_CreateServiceWorkerDebuggable>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::CreateServiceWorkerDebuggable::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessProxy_CreateServiceWorkerDebuggable>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::CreateServiceWorkerDebuggable::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_DeleteServiceWorkerDebuggable>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::DeleteServiceWorkerDebuggable::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessProxy_SendMessageToInspector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessProxy::SendMessageToInspector::Arguments>(globalObject, decoder);
}
#endif

}

#endif

