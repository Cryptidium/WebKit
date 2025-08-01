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
#include "WebInspectorBackendProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "WebInspectorBackendProxyMessages.h" // NOLINT
#include <WebCore/InspectorBackendClient.h> // NOLINT
#include <optional> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebInspectorBackendProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebInspectorBackendProxy::RequestOpenLocalInspectorFrontend::name())
        return IPC::handleMessage<Messages::WebInspectorBackendProxy::RequestOpenLocalInspectorFrontend>(connection, decoder, this, &WebInspectorBackendProxy::requestOpenLocalInspectorFrontend);
    if (decoder.messageName() == Messages::WebInspectorBackendProxy::DidClose::name())
        return IPC::handleMessage<Messages::WebInspectorBackendProxy::DidClose>(connection, decoder, this, &WebInspectorBackendProxy::didClose);
    if (decoder.messageName() == Messages::WebInspectorBackendProxy::BringToFront::name())
        return IPC::handleMessage<Messages::WebInspectorBackendProxy::BringToFront>(connection, decoder, this, &WebInspectorBackendProxy::bringToFront);
    if (decoder.messageName() == Messages::WebInspectorBackendProxy::ElementSelectionChanged::name())
        return IPC::handleMessage<Messages::WebInspectorBackendProxy::ElementSelectionChanged>(connection, decoder, this, &WebInspectorBackendProxy::elementSelectionChanged);
    if (decoder.messageName() == Messages::WebInspectorBackendProxy::TimelineRecordingChanged::name())
        return IPC::handleMessage<Messages::WebInspectorBackendProxy::TimelineRecordingChanged>(connection, decoder, this, &WebInspectorBackendProxy::timelineRecordingChanged);
    if (decoder.messageName() == Messages::WebInspectorBackendProxy::SetDeveloperPreferenceOverride::name())
        return IPC::handleMessage<Messages::WebInspectorBackendProxy::SetDeveloperPreferenceOverride>(connection, decoder, this, &WebInspectorBackendProxy::setDeveloperPreferenceOverride);
#if ENABLE(INSPECTOR_NETWORK_THROTTLING)
    if (decoder.messageName() == Messages::WebInspectorBackendProxy::SetEmulatedConditions::name())
        return IPC::handleMessage<Messages::WebInspectorBackendProxy::SetEmulatedConditions>(connection, decoder, this, &WebInspectorBackendProxy::setEmulatedConditions);
#endif
    if (decoder.messageName() == Messages::WebInspectorBackendProxy::AttachAvailabilityChanged::name())
        return IPC::handleMessage<Messages::WebInspectorBackendProxy::AttachAvailabilityChanged>(connection, decoder, this, &WebInspectorBackendProxy::attachAvailabilityChanged);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebInspectorBackendProxy_RequestOpenLocalInspectorFrontend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebInspectorBackendProxy::RequestOpenLocalInspectorFrontend::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebInspectorBackendProxy_DidClose>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebInspectorBackendProxy::DidClose::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebInspectorBackendProxy_BringToFront>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebInspectorBackendProxy::BringToFront::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebInspectorBackendProxy_ElementSelectionChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebInspectorBackendProxy::ElementSelectionChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebInspectorBackendProxy_TimelineRecordingChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebInspectorBackendProxy::TimelineRecordingChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebInspectorBackendProxy_SetDeveloperPreferenceOverride>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebInspectorBackendProxy::SetDeveloperPreferenceOverride::Arguments>(globalObject, decoder);
}
#if ENABLE(INSPECTOR_NETWORK_THROTTLING)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebInspectorBackendProxy_SetEmulatedConditions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebInspectorBackendProxy::SetEmulatedConditions::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebInspectorBackendProxy_AttachAvailabilityChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebInspectorBackendProxy::AttachAvailabilityChanged::Arguments>(globalObject, decoder);
}

}

#endif

