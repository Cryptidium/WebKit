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
#include "RemoteMediaSourceProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "RemoteMediaSourceProxyMessages.h" // NOLINT
#include "RemoteSourceBufferIdentifier.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include <WebCore/ContentType.h> // NOLINT
#include <WebCore/MediaPlayerEnums.h> // NOLINT
#include <WebCore/MediaSourceConfiguration.h> // NOLINT
#include <WebCore/MediaSourcePrivate.h> // NOLINT
#include <WebCore/PlatformTimeRanges.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/MediaTime.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteMediaSourceProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !(sharedPreferences->mediaSourceEnabled || sharedPreferences->managedMediaSourceEnabled)) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteMediaSourceProxy", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteMediaSourceProxy::DurationChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaSourceProxy::DurationChanged>(connection, decoder, this, &RemoteMediaSourceProxy::durationChanged);
    if (decoder.messageName() == Messages::RemoteMediaSourceProxy::BufferedChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaSourceProxy::BufferedChanged>(connection, decoder, this, &RemoteMediaSourceProxy::bufferedChanged);
    if (decoder.messageName() == Messages::RemoteMediaSourceProxy::SetMediaPlayerReadyState::name())
        return IPC::handleMessage<Messages::RemoteMediaSourceProxy::SetMediaPlayerReadyState>(connection, decoder, this, &RemoteMediaSourceProxy::setMediaPlayerReadyState);
    if (decoder.messageName() == Messages::RemoteMediaSourceProxy::SetTimeFudgeFactor::name())
        return IPC::handleMessage<Messages::RemoteMediaSourceProxy::SetTimeFudgeFactor>(connection, decoder, this, &RemoteMediaSourceProxy::setTimeFudgeFactor);
    if (decoder.messageName() == Messages::RemoteMediaSourceProxy::MarkEndOfStream::name())
        return IPC::handleMessage<Messages::RemoteMediaSourceProxy::MarkEndOfStream>(connection, decoder, this, &RemoteMediaSourceProxy::markEndOfStream);
    if (decoder.messageName() == Messages::RemoteMediaSourceProxy::UnmarkEndOfStream::name())
        return IPC::handleMessage<Messages::RemoteMediaSourceProxy::UnmarkEndOfStream>(connection, decoder, this, &RemoteMediaSourceProxy::unmarkEndOfStream);
    if (decoder.messageName() == Messages::RemoteMediaSourceProxy::Shutdown::name())
        return IPC::handleMessage<Messages::RemoteMediaSourceProxy::Shutdown>(connection, decoder, this, &RemoteMediaSourceProxy::shutdown);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool RemoteMediaSourceProxy::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(isInGPUProcess());
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !(sharedPreferences->mediaSourceEnabled || sharedPreferences->managedMediaSourceEnabled)) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteMediaSourceProxy", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return false;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteMediaSourceProxy::AddSourceBuffer::name())
        return IPC::handleMessageSynchronous<Messages::RemoteMediaSourceProxy::AddSourceBuffer>(connection, decoder, replyEncoder, this, &RemoteMediaSourceProxy::addSourceBuffer);
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSourceProxy_AddSourceBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::AddSourceBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaSourceProxy_AddSourceBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::AddSourceBuffer::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSourceProxy_DurationChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::DurationChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSourceProxy_BufferedChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::BufferedChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSourceProxy_SetMediaPlayerReadyState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::SetMediaPlayerReadyState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSourceProxy_SetTimeFudgeFactor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::SetTimeFudgeFactor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSourceProxy_MarkEndOfStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::MarkEndOfStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSourceProxy_UnmarkEndOfStream>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::UnmarkEndOfStream::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSourceProxy_Shutdown>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSourceProxy::Shutdown::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
