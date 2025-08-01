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
#include "GPUProcessProxy.h"

#if ENABLE(MEDIA_STREAM) || PLATFORM(COCOA)
#include "ArgumentCoders.h" // NOLINT
#endif
#include "Decoder.h" // NOLINT
#include "GPUProcessProxyMessages.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
#include "LayerHostingContext.h" // NOLINT
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
#include "WebPageProxyIdentifier.h" // NOLINT
#endif
#if ENABLE(MEDIA_STREAM) || HAVE(VISIBILITY_PROPAGATION_VIEW) || PLATFORM(COCOA)
#include <WebCore/PageIdentifier.h> // NOLINT
#endif
#include <WebCore/ProcessIdentifier.h> // NOLINT
#if PLATFORM(COCOA)
#include <WebCore/SharedBuffer.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <WebCore/SnapshotIdentifier.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <wtf/RefCounted.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <wtf/text/WTFString.h> // NOLINT
#endif

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void GPUProcessProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    if (decoder.messageName() == Messages::GPUProcessProxy::DidCreateContextForVisibilityPropagation::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::DidCreateContextForVisibilityPropagation>(connection, decoder, this, &GPUProcessProxy::didCreateContextForVisibilityPropagation);
#endif
#if ENABLE(VP9)
    if (decoder.messageName() == Messages::GPUProcessProxy::SetHasVP9HardwareDecoder::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::SetHasVP9HardwareDecoder>(connection, decoder, this, &GPUProcessProxy::setHasVP9HardwareDecoder);
#endif
#if ENABLE(AV1)
    if (decoder.messageName() == Messages::GPUProcessProxy::SetHasAV1HardwareDecoder::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::SetHasAV1HardwareDecoder>(connection, decoder, this, &GPUProcessProxy::setHasAV1HardwareDecoder);
#endif
#if ENABLE(MEDIA_STREAM)
    if (decoder.messageName() == Messages::GPUProcessProxy::VoiceActivityDetected::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::VoiceActivityDetected>(connection, decoder, this, &GPUProcessProxy::voiceActivityDetected);
    if (decoder.messageName() == Messages::GPUProcessProxy::StartMonitoringCaptureDeviceRotation::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::StartMonitoringCaptureDeviceRotation>(connection, decoder, this, &GPUProcessProxy::startMonitoringCaptureDeviceRotation);
    if (decoder.messageName() == Messages::GPUProcessProxy::StopMonitoringCaptureDeviceRotation::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::StopMonitoringCaptureDeviceRotation>(connection, decoder, this, &GPUProcessProxy::stopMonitoringCaptureDeviceRotation);
    if (decoder.messageName() == Messages::GPUProcessProxy::MicrophoneMuteStatusChanged::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::MicrophoneMuteStatusChanged>(connection, decoder, this, &GPUProcessProxy::microphoneMuteStatusChanged);
#endif
#if (ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY))
    if (decoder.messageName() == Messages::GPUProcessProxy::StatusBarWasTapped::name())
        return IPC::handleMessageAsync<Messages::GPUProcessProxy::StatusBarWasTapped>(connection, decoder, this, &GPUProcessProxy::statusBarWasTapped);
#endif
    if (decoder.messageName() == Messages::GPUProcessProxy::ProcessIsReadyToExit::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::ProcessIsReadyToExit>(connection, decoder, this, &GPUProcessProxy::processIsReadyToExit);
    if (decoder.messageName() == Messages::GPUProcessProxy::TerminateWebProcess::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::TerminateWebProcess>(connection, decoder, this, &GPUProcessProxy::terminateWebProcess);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::GPUProcessProxy::DidDrawRemoteToPDF::name())
        return IPC::handleMessage<Messages::GPUProcessProxy::DidDrawRemoteToPDF>(connection, decoder, this, &GPUProcessProxy::didDrawRemoteToPDF);
#endif
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

#if HAVE(VISIBILITY_PROPAGATION_VIEW)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_DidCreateContextForVisibilityPropagation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::DidCreateContextForVisibilityPropagation::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(VP9)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_SetHasVP9HardwareDecoder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::SetHasVP9HardwareDecoder::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(AV1)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_SetHasAV1HardwareDecoder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::SetHasAV1HardwareDecoder::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(MEDIA_STREAM)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_VoiceActivityDetected>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::VoiceActivityDetected::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_StartMonitoringCaptureDeviceRotation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::StartMonitoringCaptureDeviceRotation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_StopMonitoringCaptureDeviceRotation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::StopMonitoringCaptureDeviceRotation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_MicrophoneMuteStatusChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::MicrophoneMuteStatusChanged::Arguments>(globalObject, decoder);
}
#endif
#if (ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_StatusBarWasTapped>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::StatusBarWasTapped::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::GPUProcessProxy_StatusBarWasTapped>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::StatusBarWasTapped::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_ProcessIsReadyToExit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::ProcessIsReadyToExit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_TerminateWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::TerminateWebProcess::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::GPUProcessProxy_DidDrawRemoteToPDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::GPUProcessProxy::DidDrawRemoteToPDF::Arguments>(globalObject, decoder);
}
#endif

}

#endif


#endif // ENABLE(GPU_PROCESS)
