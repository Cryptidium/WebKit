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
#include "IPCStreamTester.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "IPCStreamTesterMessages.h" // NOLINT
#include <WebCore/SharedMemory.h> // NOLINT
#include <optional> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void IPCStreamTester::didReceiveStreamMessage(IPC::StreamServerConnection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::IPCStreamTester::AsyncPing::name())
        return IPC::handleMessageAsync<Messages::IPCStreamTester::AsyncPing>(connection, decoder, this, &IPCStreamTester::asyncPing);
    if (decoder.messageName() == Messages::IPCStreamTester::EmptyMessage::name())
        return IPC::handleMessage<Messages::IPCStreamTester::EmptyMessage>(connection, decoder, this, &IPCStreamTester::emptyMessage);
    if (decoder.messageName() == Messages::IPCStreamTester::SyncMessage::name())
        return IPC::handleMessageSynchronous<Messages::IPCStreamTester::SyncMessage>(connection, decoder, this, &IPCStreamTester::syncMessage);
    if (decoder.messageName() == Messages::IPCStreamTester::SyncMessageNotStreamEncodableReply::name())
        return IPC::handleMessageSynchronous<Messages::IPCStreamTester::SyncMessageNotStreamEncodableReply>(connection, decoder, this, &IPCStreamTester::syncMessageNotStreamEncodableReply);
    if (decoder.messageName() == Messages::IPCStreamTester::SyncMessageNotStreamEncodableBoth::name())
        return IPC::handleMessageSynchronous<Messages::IPCStreamTester::SyncMessageNotStreamEncodableBoth>(connection, decoder, this, &IPCStreamTester::syncMessageNotStreamEncodableBoth);
    if (decoder.messageName() == Messages::IPCStreamTester::SyncMessageReturningSharedMemory1::name())
        return IPC::handleMessageSynchronous<Messages::IPCStreamTester::SyncMessageReturningSharedMemory1>(connection, decoder, this, &IPCStreamTester::syncMessageReturningSharedMemory1);
    if (decoder.messageName() == Messages::IPCStreamTester::SyncMessageEmptyReply::name())
        return IPC::handleMessageSynchronous<Messages::IPCStreamTester::SyncMessageEmptyReply>(connection, decoder, this, &IPCStreamTester::syncMessageEmptyReply);
    if (decoder.messageName() == Messages::IPCStreamTester::SyncCrashOnZero::name())
        return IPC::handleMessageSynchronous<Messages::IPCStreamTester::SyncCrashOnZero>(connection, decoder, this, &IPCStreamTester::syncCrashOnZero);
    if (decoder.messageName() == Messages::IPCStreamTester::CheckAutoreleasePool::name())
        return IPC::handleMessageSynchronous<Messages::IPCStreamTester::CheckAutoreleasePool>(connection, decoder, this, &IPCStreamTester::checkAutoreleasePool);
    RELEASE_LOG_ERROR(IPC, "Unhandled stream message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_SyncMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCStreamTester_SyncMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_SyncMessageNotStreamEncodableReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessageNotStreamEncodableReply::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCStreamTester_SyncMessageNotStreamEncodableReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessageNotStreamEncodableReply::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_SyncMessageNotStreamEncodableBoth>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessageNotStreamEncodableBoth::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCStreamTester_SyncMessageNotStreamEncodableBoth>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessageNotStreamEncodableBoth::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_SyncMessageReturningSharedMemory1>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessageReturningSharedMemory1::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCStreamTester_SyncMessageReturningSharedMemory1>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessageReturningSharedMemory1::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_SyncMessageEmptyReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessageEmptyReply::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCStreamTester_SyncMessageEmptyReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncMessageEmptyReply::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_SyncCrashOnZero>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncCrashOnZero::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCStreamTester_SyncCrashOnZero>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::SyncCrashOnZero::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_CheckAutoreleasePool>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::CheckAutoreleasePool::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCStreamTester_CheckAutoreleasePool>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::CheckAutoreleasePool::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_AsyncPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::AsyncPing::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::IPCStreamTester_AsyncPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::AsyncPing::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::IPCStreamTester_EmptyMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::IPCStreamTester::EmptyMessage::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(IPC_TESTING_API)
