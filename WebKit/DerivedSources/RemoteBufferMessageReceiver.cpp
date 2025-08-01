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
#include "RemoteBuffer.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "RemoteBufferMessages.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include <WebCore/SharedMemory.h> // NOLINT
#include <WebCore/WebGPUIntegralTypes.h> // NOLINT
#include <WebCore/WebGPUMapMode.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/Vector.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteBuffer::didReceiveStreamMessage(IPC::StreamServerConnection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->webGPUEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteBuffer", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteBuffer::MapAsync::name())
        return IPC::handleMessageAsync<Messages::RemoteBuffer::MapAsync>(connection, decoder, this, &RemoteBuffer::mapAsync);
    if (decoder.messageName() == Messages::RemoteBuffer::Copy::name())
        return IPC::handleMessageAsync<Messages::RemoteBuffer::Copy>(connection, decoder, this, &RemoteBuffer::copy);
    if (decoder.messageName() == Messages::RemoteBuffer::CopyWithCopy::name())
        return IPC::handleMessage<Messages::RemoteBuffer::CopyWithCopy>(connection, decoder, this, &RemoteBuffer::copyWithCopy);
    if (decoder.messageName() == Messages::RemoteBuffer::Unmap::name())
        return IPC::handleMessage<Messages::RemoteBuffer::Unmap>(connection, decoder, this, &RemoteBuffer::unmap);
    if (decoder.messageName() == Messages::RemoteBuffer::Destroy::name())
        return IPC::handleMessage<Messages::RemoteBuffer::Destroy>(connection, decoder, this, &RemoteBuffer::destroy);
    if (decoder.messageName() == Messages::RemoteBuffer::Destruct::name())
        return IPC::handleMessage<Messages::RemoteBuffer::Destruct>(connection, decoder, this, &RemoteBuffer::destruct);
    if (decoder.messageName() == Messages::RemoteBuffer::SetLabel::name())
        return IPC::handleMessage<Messages::RemoteBuffer::SetLabel>(connection, decoder, this, &RemoteBuffer::setLabel);
    if (decoder.messageName() == Messages::RemoteBuffer::GetMappedRange::name())
        return IPC::handleMessageSynchronous<Messages::RemoteBuffer::GetMappedRange>(connection, decoder, this, &RemoteBuffer::getMappedRange);
    RELEASE_LOG_ERROR(IPC, "Unhandled stream message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteBuffer_GetMappedRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::GetMappedRange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteBuffer_GetMappedRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::GetMappedRange::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteBuffer_MapAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::MapAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteBuffer_MapAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::MapAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteBuffer_Copy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::Copy::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteBuffer_Copy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::Copy::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteBuffer_CopyWithCopy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::CopyWithCopy::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteBuffer_Unmap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::Unmap::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteBuffer_Destroy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::Destroy::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteBuffer_Destruct>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::Destruct::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteBuffer_SetLabel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteBuffer::SetLabel::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS)
