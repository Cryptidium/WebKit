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
#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
#include "SourceBufferPrivateRemoteMessageReceiver.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "InitializationSegmentInfo.h" // NOLINT
#include "SourceBufferPrivateRemoteMessageReceiverMessages.h" // NOLINT
#include <WebCore/PlatformMediaError.h> // NOLINT
#include <WebCore/PlatformTimeRanges.h> // NOLINT
#include <WebCore/SharedMemory.h> // NOLINT
#include <WebCore/SourceBufferPrivateClient.h> // NOLINT
#include <wtf/Expected.h> // NOLINT
#include <wtf/MediaTime.h> // NOLINT
#include <wtf/Vector.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void SourceBufferPrivateRemoteMessageReceiver::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidReceiveInitializationSegment::name())
        return IPC::handleMessageAsync<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidReceiveInitializationSegment>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::sourceBufferPrivateDidReceiveInitializationSegment);
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::TakeOwnershipOfMemory::name())
        return IPC::handleMessage<Messages::SourceBufferPrivateRemoteMessageReceiver::TakeOwnershipOfMemory>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::takeOwnershipOfMemory);
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateHighestPresentationTimestampChanged::name())
        return IPC::handleMessage<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateHighestPresentationTimestampChanged>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::sourceBufferPrivateHighestPresentationTimestampChanged);
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateBufferedChanged::name())
        return IPC::handleMessageAsync<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateBufferedChanged>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::sourceBufferPrivateBufferedChanged);
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDurationChanged::name())
        return IPC::handleMessageAsync<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDurationChanged>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::sourceBufferPrivateDurationChanged);
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidDropSample::name())
        return IPC::handleMessage<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidDropSample>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::sourceBufferPrivateDidDropSample);
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidReceiveRenderingError::name())
        return IPC::handleMessage<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidReceiveRenderingError>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::sourceBufferPrivateDidReceiveRenderingError);
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateEvictionDataChanged::name())
        return IPC::handleMessage<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateEvictionDataChanged>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::sourceBufferPrivateEvictionDataChanged);
    if (decoder.messageName() == Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidAttach::name())
        return IPC::handleMessageAsync<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidAttach>(connection, decoder, this, &SourceBufferPrivateRemoteMessageReceiver::sourceBufferPrivateDidAttach);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveInitializationSegment>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidReceiveInitializationSegment::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveInitializationSegment>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidReceiveInitializationSegment::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_TakeOwnershipOfMemory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::TakeOwnershipOfMemory::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateHighestPresentationTimestampChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateHighestPresentationTimestampChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateBufferedChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateBufferedChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateBufferedChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateBufferedChanged::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDurationChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDurationChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDurationChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDurationChanged::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidDropSample>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidDropSample::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveRenderingError>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidReceiveRenderingError::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateEvictionDataChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateEvictionDataChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidAttach>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidAttach::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidAttach>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SourceBufferPrivateRemoteMessageReceiver::SourceBufferPrivateDidAttach::ReplyArguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
