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
#if ENABLE(WEBXR)
#include "PlatformXRSystem.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "PlatformXRSystemMessages.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "XRDeviceInfo.h" // NOLINT
#if USE(OPENXR)
#include "XRDeviceLayer.h" // NOLINT
#endif
#include <WebCore/PlatformXR.h> // NOLINT
#include <WebCore/SecurityOriginData.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/Vector.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void PlatformXRSystem::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess(connection);
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->webXREnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver PlatformXRSystem", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::PlatformXRSystem::EnumerateImmersiveXRDevices::name())
        return IPC::handleMessageAsync<Messages::PlatformXRSystem::EnumerateImmersiveXRDevices>(connection, decoder, this, &PlatformXRSystem::enumerateImmersiveXRDevices);
    if (decoder.messageName() == Messages::PlatformXRSystem::RequestPermissionOnSessionFeatures::name())
        return IPC::handleMessageAsync<Messages::PlatformXRSystem::RequestPermissionOnSessionFeatures>(connection, decoder, this, &PlatformXRSystem::requestPermissionOnSessionFeatures);
    if (decoder.messageName() == Messages::PlatformXRSystem::InitializeTrackingAndRendering::name())
        return IPC::handleMessage<Messages::PlatformXRSystem::InitializeTrackingAndRendering>(connection, decoder, this, &PlatformXRSystem::initializeTrackingAndRendering);
    if (decoder.messageName() == Messages::PlatformXRSystem::ShutDownTrackingAndRendering::name())
        return IPC::handleMessage<Messages::PlatformXRSystem::ShutDownTrackingAndRendering>(connection, decoder, this, &PlatformXRSystem::shutDownTrackingAndRendering);
    if (decoder.messageName() == Messages::PlatformXRSystem::RequestFrame::name())
        return IPC::handleMessageAsync<Messages::PlatformXRSystem::RequestFrame>(connection, decoder, this, &PlatformXRSystem::requestFrame);
#if USE(OPENXR)
    if (decoder.messageName() == Messages::PlatformXRSystem::CreateLayerProjection::name())
        return IPC::handleMessage<Messages::PlatformXRSystem::CreateLayerProjection>(connection, decoder, this, &PlatformXRSystem::createLayerProjection);
    if (decoder.messageName() == Messages::PlatformXRSystem::SubmitFrame::name())
        return IPC::handleMessage<Messages::PlatformXRSystem::SubmitFrame>(connection, decoder, this, &PlatformXRSystem::submitFrame);
#endif
#if !USE(OPENXR)
    if (decoder.messageName() == Messages::PlatformXRSystem::SubmitFrame::name())
        return IPC::handleMessage<Messages::PlatformXRSystem::SubmitFrame>(connection, decoder, this, &PlatformXRSystem::submitFrame);
#endif
    if (decoder.messageName() == Messages::PlatformXRSystem::DidCompleteShutdownTriggeredBySystem::name())
        return IPC::handleMessage<Messages::PlatformXRSystem::DidCompleteShutdownTriggeredBySystem>(connection, decoder, this, &PlatformXRSystem::didCompleteShutdownTriggeredBySystem);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_EnumerateImmersiveXRDevices>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::EnumerateImmersiveXRDevices::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PlatformXRSystem_EnumerateImmersiveXRDevices>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::EnumerateImmersiveXRDevices::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_RequestPermissionOnSessionFeatures>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::RequestPermissionOnSessionFeatures::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PlatformXRSystem_RequestPermissionOnSessionFeatures>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::RequestPermissionOnSessionFeatures::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_InitializeTrackingAndRendering>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::InitializeTrackingAndRendering::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_ShutDownTrackingAndRendering>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::ShutDownTrackingAndRendering::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_RequestFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::RequestFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PlatformXRSystem_RequestFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::RequestFrame::ReplyArguments>(globalObject, decoder);
}
#if USE(OPENXR)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_CreateLayerProjection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::CreateLayerProjection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_SubmitFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::SubmitFrame::Arguments>(globalObject, decoder);
}
#endif
#if !USE(OPENXR)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_SubmitFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::SubmitFrame::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PlatformXRSystem_DidCompleteShutdownTriggeredBySystem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PlatformXRSystem::DidCompleteShutdownTriggeredBySystem::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(WEBXR)
