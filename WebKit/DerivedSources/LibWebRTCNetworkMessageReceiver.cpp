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
#if USE(LIBWEBRTC)
#include "LibWebRTCNetwork.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "LibWebRTCNetworkMessages.h" // NOLINT
#include "RTCNetwork.h" // NOLINT
#include <WebCore/LibWebRTCSocketIdentifier.h> // NOLINT
#include <span> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void LibWebRTCNetwork::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::LibWebRTCNetwork::SignalReadPacket::name())
        return IPC::handleMessage<Messages::LibWebRTCNetwork::SignalReadPacket>(connection, decoder, this, &LibWebRTCNetwork::signalReadPacket);
    if (decoder.messageName() == Messages::LibWebRTCNetwork::SignalSentPacket::name())
        return IPC::handleMessage<Messages::LibWebRTCNetwork::SignalSentPacket>(connection, decoder, this, &LibWebRTCNetwork::signalSentPacket);
    if (decoder.messageName() == Messages::LibWebRTCNetwork::SignalAddressReady::name())
        return IPC::handleMessage<Messages::LibWebRTCNetwork::SignalAddressReady>(connection, decoder, this, &LibWebRTCNetwork::signalAddressReady);
    if (decoder.messageName() == Messages::LibWebRTCNetwork::SignalConnect::name())
        return IPC::handleMessage<Messages::LibWebRTCNetwork::SignalConnect>(connection, decoder, this, &LibWebRTCNetwork::signalConnect);
    if (decoder.messageName() == Messages::LibWebRTCNetwork::SignalClose::name())
        return IPC::handleMessage<Messages::LibWebRTCNetwork::SignalClose>(connection, decoder, this, &LibWebRTCNetwork::signalClose);
    if (decoder.messageName() == Messages::LibWebRTCNetwork::SignalUsedInterface::name())
        return IPC::handleMessage<Messages::LibWebRTCNetwork::SignalUsedInterface>(connection, decoder, this, &LibWebRTCNetwork::signalUsedInterface);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::LibWebRTCNetwork_SignalReadPacket>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::LibWebRTCNetwork::SignalReadPacket::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::LibWebRTCNetwork_SignalSentPacket>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::LibWebRTCNetwork::SignalSentPacket::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::LibWebRTCNetwork_SignalAddressReady>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::LibWebRTCNetwork::SignalAddressReady::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::LibWebRTCNetwork_SignalConnect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::LibWebRTCNetwork::SignalConnect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::LibWebRTCNetwork_SignalClose>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::LibWebRTCNetwork::SignalClose::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::LibWebRTCNetwork_SignalUsedInterface>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::LibWebRTCNetwork::SignalUsedInterface::Arguments>(globalObject, decoder);
}

}

#endif


#endif // USE(LIBWEBRTC)
