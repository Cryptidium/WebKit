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

#pragma once

#if ENABLE(MEDIA_SESSION_COORDINATOR)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
enum class MediaSessionPlaybackState : uint8_t;
enum class MediaSessionReadyState : uint8_t;
struct ExceptionData;
struct MediaPositionState;
}

namespace Messages {
namespace RemoteMediaSessionCoordinatorProxy {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(!isInAuxiliaryProcess());
        }
    );
#endif
    return IPC::ReceiverName::RemoteMediaSessionCoordinatorProxy;
}

class Join {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_Join; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_JoinReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    Join()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Leave {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_Leave; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Leave()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CoordinateSeekTo {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_CoordinateSeekTo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_CoordinateSeekToReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    explicit CoordinateSeekTo(double time)
        : m_time(time)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_time;
    }

private:
    double m_time;
};

class CoordinatePlay {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_CoordinatePlay; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_CoordinatePlayReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    CoordinatePlay()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CoordinatePause {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_CoordinatePause; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_CoordinatePauseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    CoordinatePause()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CoordinateSetTrack {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_CoordinateSetTrack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_CoordinateSetTrackReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    explicit CoordinateSetTrack(const String& trackIdentifier)
        : m_trackIdentifier(trackIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackIdentifier;
    }

private:
    const String& m_trackIdentifier;
};

class PositionStateChanged {
public:
    using Arguments = std::tuple<std::optional<WebCore::MediaPositionState>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_PositionStateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PositionStateChanged(const std::optional<WebCore::MediaPositionState>& state)
        : m_state(state)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::MediaPositionState>& m_state;
};

class ReadyStateChanged {
public:
    using Arguments = std::tuple<WebCore::MediaSessionReadyState>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_ReadyStateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReadyStateChanged(WebCore::MediaSessionReadyState state)
        : m_state(state)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_state;
    }

private:
    WebCore::MediaSessionReadyState m_state;
};

class PlaybackStateChanged {
public:
    using Arguments = std::tuple<WebCore::MediaSessionPlaybackState>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_PlaybackStateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PlaybackStateChanged(WebCore::MediaSessionPlaybackState state)
        : m_state(state)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_state;
    }

private:
    WebCore::MediaSessionPlaybackState m_state;
};

class TrackIdentifierChanged {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSessionCoordinatorProxy_TrackIdentifierChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TrackIdentifierChanged(const String& trackIdentifier)
        : m_trackIdentifier(trackIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackIdentifier;
    }

private:
    const String& m_trackIdentifier;
};

} // namespace RemoteMediaSessionCoordinatorProxy
} // namespace Messages

#endif // ENABLE(MEDIA_SESSION_COORDINATOR)
