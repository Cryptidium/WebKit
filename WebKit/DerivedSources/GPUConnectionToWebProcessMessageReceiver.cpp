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
#include "GPUConnectionToWebProcess.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "GPUConnectionToWebProcessMessages.h" // NOLINT
#if ENABLE(WEBGL)
#include "GraphicsContextGLIdentifier.h" // NOLINT
#endif
#include "HandleMessage.h" // NOLINT
#include "MediaOverridesForTesting.h" // NOLINT
#include "RemoteAudioHardwareListenerIdentifier.h" // NOLINT
#if USE(AUDIO_SESSION)
#include "RemoteAudioSessionConfiguration.h" // NOLINT
#endif
#include "RemoteRemoteCommandListenerIdentifier.h" // NOLINT
#include "RenderingBackendIdentifier.h" // NOLINT
#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
#include "SampleBufferDisplayLayerIdentifier.h" // NOLINT
#endif
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "StreamServerConnection.h" // NOLINT
#if USE(GRAPHICS_LAYER_WC)
#include "WCLayerTreeHostIdentifier.h" // NOLINT
#endif
#include "WebGPUIdentifier.h" // NOLINT
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
#include "WebPageProxyIdentifier.h" // NOLINT
#endif
#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
#include <WebCore/FloatRect.h> // NOLINT
#endif
#if ENABLE(WEBGL)
#include <WebCore/GraphicsContextGLAttributes.h> // NOLINT
#endif
#include <WebCore/NowPlayingInfo.h> // NOLINT
#if ENABLE(EXTENSION_CAPABILITIES) || HAVE(VISIBILITY_PROPAGATION_VIEW)
#include <WebCore/PageIdentifier.h> // NOLINT
#endif
#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
#include <optional> // NOLINT
#endif
#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
#include <wtf/MachSendRightAnnotated.h> // NOLINT
#endif
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void GPUConnectionToWebProcess::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::CreateRenderingBackend::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::CreateRenderingBackend>(connection, decoder, this, &GPUConnectionToWebProcess::createRenderingBackend);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::ReleaseRenderingBackend::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::ReleaseRenderingBackend>(connection, decoder, this, &GPUConnectionToWebProcess::releaseRenderingBackend);
#if ENABLE(WEBGL)
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::CreateGraphicsContextGL::name()) {
        if (!(sharedPreferences && (sharedPreferences->webGLEnabled && sharedPreferences->useGPUProcessForWebGLEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::CreateGraphicsContextGL>(connection, decoder, this, &GPUConnectionToWebProcess::createGraphicsContextGL);
    }
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::ReleaseGraphicsContextGL::name()) {
        if (!(sharedPreferences && (sharedPreferences->webGLEnabled && sharedPreferences->useGPUProcessForWebGLEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::ReleaseGraphicsContextGL>(connection, decoder, this, &GPUConnectionToWebProcess::releaseGraphicsContextGL);
    }
#endif
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::CreateGPU::name()) {
        if (!(sharedPreferences && sharedPreferences->webGPUEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::CreateGPU>(connection, decoder, this, &GPUConnectionToWebProcess::createGPU);
    }
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::ReleaseGPU::name()) {
        if (!(sharedPreferences && sharedPreferences->webGPUEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::ReleaseGPU>(connection, decoder, this, &GPUConnectionToWebProcess::releaseGPU);
    }
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::ClearNowPlayingInfo::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::ClearNowPlayingInfo>(connection, decoder, this, &GPUConnectionToWebProcess::clearNowPlayingInfo);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::SetNowPlayingInfo::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::SetNowPlayingInfo>(connection, decoder, this, &GPUConnectionToWebProcess::setNowPlayingInfo);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::EnsureMediaSessionHelper::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::EnsureMediaSessionHelper>(connection, decoder, this, &GPUConnectionToWebProcess::ensureMediaSessionHelper);
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::CreateVisibilityPropagationContextForPage::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::CreateVisibilityPropagationContextForPage>(connection, decoder, this, &GPUConnectionToWebProcess::createVisibilityPropagationContextForPage);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::DestroyVisibilityPropagationContextForPage::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::DestroyVisibilityPropagationContextForPage>(connection, decoder, this, &GPUConnectionToWebProcess::destroyVisibilityPropagationContextForPage);
#endif
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::SetMediaOverridesForTesting::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::SetMediaOverridesForTesting>(connection, decoder, this, &GPUConnectionToWebProcess::setMediaOverridesForTesting);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::CreateAudioHardwareListener::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::CreateAudioHardwareListener>(connection, decoder, this, &GPUConnectionToWebProcess::createAudioHardwareListener);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::ReleaseAudioHardwareListener::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::ReleaseAudioHardwareListener>(connection, decoder, this, &GPUConnectionToWebProcess::releaseAudioHardwareListener);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::CreateRemoteCommandListener::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::CreateRemoteCommandListener>(connection, decoder, this, &GPUConnectionToWebProcess::createRemoteCommandListener);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::ReleaseRemoteCommandListener::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::ReleaseRemoteCommandListener>(connection, decoder, this, &GPUConnectionToWebProcess::releaseRemoteCommandListener);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::ConfigureLoggingChannel::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::ConfigureLoggingChannel>(connection, decoder, this, &GPUConnectionToWebProcess::configureLoggingChannel);
#if USE(GRAPHICS_LAYER_WC)
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::CreateWCLayerTreeHost::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::CreateWCLayerTreeHost>(connection, decoder, this, &GPUConnectionToWebProcess::createWCLayerTreeHost);
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::ReleaseWCLayerTreeHost::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::ReleaseWCLayerTreeHost>(connection, decoder, this, &GPUConnectionToWebProcess::releaseWCLayerTreeHost);
#endif
#if ENABLE(MEDIA_SOURCE)
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::EnableMockMediaSource::name()) {
        if (!(sharedPreferences && (sharedPreferences->mediaSourceEnabled || sharedPreferences->managedMediaSourceEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::EnableMockMediaSource>(connection, decoder, this, &GPUConnectionToWebProcess::enableMockMediaSource);
    }
#endif
#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::UpdateSampleBufferDisplayLayerBoundsAndPosition::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::UpdateSampleBufferDisplayLayerBoundsAndPosition>(connection, decoder, this, &GPUConnectionToWebProcess::updateSampleBufferDisplayLayerBoundsAndPosition);
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::SetMediaEnvironment::name())
        return IPC::handleMessage<Messages::GPUConnectionToWebProcess::SetMediaEnvironment>(connection, decoder, this, &GPUConnectionToWebProcess::setMediaEnvironment);
#endif
    if (dispatchMessage(connection, decoder))
        return;
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool GPUConnectionToWebProcess::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(isInGPUProcess());
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
#if USE(AUDIO_SESSION)
    if (decoder.messageName() == Messages::GPUConnectionToWebProcess::EnsureAudioSession::name() && sharedPreferences && (sharedPreferences->useGPUProcessForMediaEnabled && sharedPreferences->mediaPlaybackEnabled))
        return IPC::handleMessageSynchronous<Messages::GPUConnectionToWebProcess::EnsureAudioSession>(connection, decoder, replyEncoder, this, &GPUConnectionToWebProcess::ensureAudioSession);
#endif
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

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_CreateRenderingBackend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::CreateRenderingBackend::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_ReleaseRenderingBackend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::ReleaseRenderingBackend::Arguments>(globalObject, decoder);
}
#if ENABLE(WEBGL)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_CreateGraphicsContextGL>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::CreateGraphicsContextGL::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_ReleaseGraphicsContextGL>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::ReleaseGraphicsContextGL::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_CreateGPU>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::CreateGPU::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_ReleaseGPU>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::ReleaseGPU::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_ClearNowPlayingInfo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::ClearNowPlayingInfo::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_SetNowPlayingInfo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::SetNowPlayingInfo::Arguments>(globalObject, decoder);
}
#if USE(AUDIO_SESSION)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_EnsureAudioSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::EnsureAudioSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUConnectionToWebProcess_EnsureAudioSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::EnsureAudioSession::ReplyArguments>(globalObject, decoder);
}
#endif
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_EnsureMediaSessionHelper>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::EnsureMediaSessionHelper::Arguments>(globalObject, decoder);
}
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_CreateVisibilityPropagationContextForPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::CreateVisibilityPropagationContextForPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_DestroyVisibilityPropagationContextForPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::DestroyVisibilityPropagationContextForPage::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_SetMediaOverridesForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::SetMediaOverridesForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_CreateAudioHardwareListener>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::CreateAudioHardwareListener::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_ReleaseAudioHardwareListener>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::ReleaseAudioHardwareListener::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_CreateRemoteCommandListener>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::CreateRemoteCommandListener::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_ReleaseRemoteCommandListener>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::ReleaseRemoteCommandListener::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_ConfigureLoggingChannel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::ConfigureLoggingChannel::Arguments>(globalObject, decoder);
}
#if USE(GRAPHICS_LAYER_WC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_CreateWCLayerTreeHost>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::CreateWCLayerTreeHost::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_ReleaseWCLayerTreeHost>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::ReleaseWCLayerTreeHost::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(MEDIA_SOURCE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_EnableMockMediaSource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::EnableMockMediaSource::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_UpdateSampleBufferDisplayLayerBoundsAndPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::UpdateSampleBufferDisplayLayerBoundsAndPosition::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUConnectionToWebProcess_SetMediaEnvironment>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUConnectionToWebProcess::SetMediaEnvironment::Arguments>(globalObject, decoder);
}
#endif

}

#endif


#endif // ENABLE(GPU_PROCESS)
