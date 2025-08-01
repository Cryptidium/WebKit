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
#if ENABLE(IPC_TESTING_API)
#include "IPCTester.h"

#include "ArgumentCoders.h" // NOLINT
#include "ConnectionHandle.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "IPCConnectionTesterIdentifier.h" // NOLINT
#include "IPCSemaphore.h" // NOLINT
#include "IPCStreamTesterIdentifier.h" // NOLINT
#include "IPCTesterMessages.h" // NOLINT
#include "StreamServerConnection.h" // NOLINT
#include <WebCore/ExceptionData.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void IPCTester::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::IPCTester::StartMessageTesting::name())
        return IPC::handleMessage<Messages::IPCTester::StartMessageTesting>(connection, decoder, this, &IPCTester::startMessageTesting);
    if (decoder.messageName() == Messages::IPCTester::CreateStreamTester::name())
        return IPC::handleMessage<Messages::IPCTester::CreateStreamTester>(connection, decoder, this, &IPCTester::createStreamTester);
    if (decoder.messageName() == Messages::IPCTester::CreateConnectionTester::name())
        return IPC::handleMessage<Messages::IPCTester::CreateConnectionTester>(connection, decoder, this, &IPCTester::createConnectionTester);
    if (decoder.messageName() == Messages::IPCTester::CreateConnectionTesterAndSendAsyncMessages::name())
        return IPC::handleMessage<Messages::IPCTester::CreateConnectionTesterAndSendAsyncMessages>(connection, decoder, this, &IPCTester::createConnectionTesterAndSendAsyncMessages);
    if (decoder.messageName() == Messages::IPCTester::SendSameSemaphoreBack::name())
        return IPC::handleMessage<Messages::IPCTester::SendSameSemaphoreBack>(connection, decoder, this, &IPCTester::sendSameSemaphoreBack);
    if (decoder.messageName() == Messages::IPCTester::SendSemaphoreBackAndSignalProtocol::name())
        return IPC::handleMessage<Messages::IPCTester::SendSemaphoreBackAndSignalProtocol>(connection, decoder, this, &IPCTester::sendSemaphoreBackAndSignalProtocol);
    if (decoder.messageName() == Messages::IPCTester::AsyncPing::name())
        return IPC::handleMessageAsync<Messages::IPCTester::AsyncPing>(connection, decoder, this, &IPCTester::asyncPing);
    if (decoder.messageName() == Messages::IPCTester::SendAsyncMessageToReceiver::name())
        return IPC::handleMessage<Messages::IPCTester::SendAsyncMessageToReceiver>(connection, decoder, this, &IPCTester::sendAsyncMessageToReceiver);
    if (decoder.messageName() == Messages::IPCTester::AsyncOptionalExceptionData::name())
        return IPC::handleMessageAsync<Messages::IPCTester::AsyncOptionalExceptionData>(connection, decoder, this, &IPCTester::asyncOptionalExceptionData);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool IPCTester::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::IPCTester::StopMessageTesting::name())
        return IPC::handleMessageSynchronous<Messages::IPCTester::StopMessageTesting>(connection, decoder, replyEncoder, this, &IPCTester::stopMessageTesting);
    if (decoder.messageName() == Messages::IPCTester::ReleaseStreamTester::name())
        return IPC::handleMessageSynchronous<Messages::IPCTester::ReleaseStreamTester>(connection, decoder, replyEncoder, this, &IPCTester::releaseStreamTester);
    if (decoder.messageName() == Messages::IPCTester::ReleaseConnectionTester::name())
        return IPC::handleMessageSynchronous<Messages::IPCTester::ReleaseConnectionTester>(connection, decoder, replyEncoder, this, &IPCTester::releaseConnectionTester);
    if (decoder.messageName() == Messages::IPCTester::SyncPing::name())
        return IPC::handleMessageSynchronous<Messages::IPCTester::SyncPing>(connection, decoder, replyEncoder, this, &IPCTester::syncPing);
    if (decoder.messageName() == Messages::IPCTester::SyncPingEmptyReply::name())
        return IPC::handleMessageSynchronous<Messages::IPCTester::SyncPingEmptyReply>(connection, decoder, replyEncoder, this, &IPCTester::syncPingEmptyReply);
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_StartMessageTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::StartMessageTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_StopMessageTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::StopMessageTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCTester_StopMessageTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::StopMessageTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_CreateStreamTester>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::CreateStreamTester::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_ReleaseStreamTester>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::ReleaseStreamTester::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCTester_ReleaseStreamTester>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::ReleaseStreamTester::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_CreateConnectionTester>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::CreateConnectionTester::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_CreateConnectionTesterAndSendAsyncMessages>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::CreateConnectionTesterAndSendAsyncMessages::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_ReleaseConnectionTester>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::ReleaseConnectionTester::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCTester_ReleaseConnectionTester>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::ReleaseConnectionTester::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_SendSameSemaphoreBack>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::SendSameSemaphoreBack::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_SendSemaphoreBackAndSignalProtocol>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::SendSemaphoreBackAndSignalProtocol::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_AsyncPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::AsyncPing::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCTester_AsyncPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::AsyncPing::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_SyncPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::SyncPing::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCTester_SyncPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::SyncPing::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_SyncPingEmptyReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::SyncPingEmptyReply::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCTester_SyncPingEmptyReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::SyncPingEmptyReply::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_SendAsyncMessageToReceiver>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::SendAsyncMessageToReceiver::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCTester_AsyncOptionalExceptionData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::AsyncOptionalExceptionData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCTester_AsyncOptionalExceptionData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCTester::AsyncOptionalExceptionData::ReplyArguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(IPC_TESTING_API)
