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
#if ENABLE(MEDIA_SESSION_COORDINATOR)
#include "RemoteMediaSessionCoordinator.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "RemoteMediaSessionCoordinatorMessages.h" // NOLINT
#include <WebCore/MediaSessionCoordinatorState.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/MonotonicTime.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteMediaSessionCoordinator::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteMediaSessionCoordinator::SeekSessionToTime::name())
        return IPC::handleMessageAsync<Messages::RemoteMediaSessionCoordinator::SeekSessionToTime>(connection, decoder, this, &RemoteMediaSessionCoordinator::seekSessionToTime);
    if (decoder.messageName() == Messages::RemoteMediaSessionCoordinator::PlaySession::name())
        return IPC::handleMessageAsync<Messages::RemoteMediaSessionCoordinator::PlaySession>(connection, decoder, this, &RemoteMediaSessionCoordinator::playSession);
    if (decoder.messageName() == Messages::RemoteMediaSessionCoordinator::PauseSession::name())
        return IPC::handleMessageAsync<Messages::RemoteMediaSessionCoordinator::PauseSession>(connection, decoder, this, &RemoteMediaSessionCoordinator::pauseSession);
    if (decoder.messageName() == Messages::RemoteMediaSessionCoordinator::SetSessionTrack::name())
        return IPC::handleMessageAsync<Messages::RemoteMediaSessionCoordinator::SetSessionTrack>(connection, decoder, this, &RemoteMediaSessionCoordinator::setSessionTrack);
    if (decoder.messageName() == Messages::RemoteMediaSessionCoordinator::CoordinatorStateChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaSessionCoordinator::CoordinatorStateChanged>(connection, decoder, this, &RemoteMediaSessionCoordinator::coordinatorStateChanged);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSessionCoordinator_SeekSessionToTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::SeekSessionToTime::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaSessionCoordinator_SeekSessionToTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::SeekSessionToTime::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSessionCoordinator_PlaySession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::PlaySession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaSessionCoordinator_PlaySession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::PlaySession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSessionCoordinator_PauseSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::PauseSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaSessionCoordinator_PauseSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::PauseSession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSessionCoordinator_SetSessionTrack>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::SetSessionTrack::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaSessionCoordinator_SetSessionTrack>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::SetSessionTrack::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaSessionCoordinator_CoordinatorStateChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaSessionCoordinator::CoordinatorStateChanged::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(MEDIA_SESSION_COORDINATOR)
