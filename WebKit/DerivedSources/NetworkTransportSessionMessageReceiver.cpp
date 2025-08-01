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
#include "NetworkTransportSession.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "NetworkTransportSessionMessages.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "WebTransportSession.h" // NOLINT
#include <WebCore/Exception.h> // NOLINT
#include <optional> // NOLINT
#include <span> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void NetworkTransportSession::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->webTransportEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver NetworkTransportSession", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::NetworkTransportSession::SendDatagram::name())
        return IPC::handleMessageAsync<Messages::NetworkTransportSession::SendDatagram>(connection, decoder, this, &NetworkTransportSession::sendDatagram);
    if (decoder.messageName() == Messages::NetworkTransportSession::CreateOutgoingUnidirectionalStream::name())
        return IPC::handleMessageAsync<Messages::NetworkTransportSession::CreateOutgoingUnidirectionalStream>(connection, decoder, this, &NetworkTransportSession::createOutgoingUnidirectionalStream);
    if (decoder.messageName() == Messages::NetworkTransportSession::CreateBidirectionalStream::name())
        return IPC::handleMessageAsync<Messages::NetworkTransportSession::CreateBidirectionalStream>(connection, decoder, this, &NetworkTransportSession::createBidirectionalStream);
    if (decoder.messageName() == Messages::NetworkTransportSession::StreamSendBytes::name())
        return IPC::handleMessageAsync<Messages::NetworkTransportSession::StreamSendBytes>(connection, decoder, this, &NetworkTransportSession::streamSendBytes);
    if (decoder.messageName() == Messages::NetworkTransportSession::CancelReceiveStream::name())
        return IPC::handleMessage<Messages::NetworkTransportSession::CancelReceiveStream>(connection, decoder, this, &NetworkTransportSession::cancelReceiveStream);
    if (decoder.messageName() == Messages::NetworkTransportSession::CancelSendStream::name())
        return IPC::handleMessage<Messages::NetworkTransportSession::CancelSendStream>(connection, decoder, this, &NetworkTransportSession::cancelSendStream);
    if (decoder.messageName() == Messages::NetworkTransportSession::DestroyStream::name())
        return IPC::handleMessage<Messages::NetworkTransportSession::DestroyStream>(connection, decoder, this, &NetworkTransportSession::destroyStream);
    if (decoder.messageName() == Messages::NetworkTransportSession::Terminate::name())
        return IPC::handleMessage<Messages::NetworkTransportSession::Terminate>(connection, decoder, this, &NetworkTransportSession::terminate);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkTransportSession_SendDatagram>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::SendDatagram::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NetworkTransportSession_SendDatagram>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::SendDatagram::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkTransportSession_CreateOutgoingUnidirectionalStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::CreateOutgoingUnidirectionalStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NetworkTransportSession_CreateOutgoingUnidirectionalStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::CreateOutgoingUnidirectionalStream::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkTransportSession_CreateBidirectionalStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::CreateBidirectionalStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NetworkTransportSession_CreateBidirectionalStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::CreateBidirectionalStream::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkTransportSession_StreamSendBytes>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::StreamSendBytes::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NetworkTransportSession_StreamSendBytes>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::StreamSendBytes::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkTransportSession_CancelReceiveStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::CancelReceiveStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkTransportSession_CancelSendStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::CancelSendStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkTransportSession_DestroyStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::DestroyStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkTransportSession_Terminate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkTransportSession::Terminate::Arguments>(globalObject, decoder);
}

}

#endif

