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

#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
#include "RemoteSourceBufferIdentifier.h"
#endif
#include <wtf/Forward.h>
#include <wtf/MediaTime.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
class ContentType;
class PlatformTimeRanges;
enum class MediaPlayerReadyState : uint8_t;
enum class MediaSourcePrivateAddStatus : uint8_t;
enum class MediaSourcePrivateEndOfStreamStatus : uint8_t;
struct MediaSourceConfiguration;
}

namespace Messages {
namespace RemoteMediaSourceProxy {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInGPUProcess());
        }
    );
#endif
    return IPC::ReceiverName::RemoteMediaSourceProxy;
}

class AddSourceBuffer {
public:
    using Arguments = std::tuple<WebCore::ContentType, WebCore::MediaSourceConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSourceProxy_AddSourceBuffer; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::MediaSourcePrivateAddStatus, std::optional<WebKit::RemoteSourceBufferIdentifier>>;
    using Reply = CompletionHandler<void(WebCore::MediaSourcePrivateAddStatus, std::optional<WebKit::RemoteSourceBufferIdentifier>&&)>;
    AddSourceBuffer(const WebCore::ContentType& contentType, const WebCore::MediaSourceConfiguration& configuration)
        : m_contentType(contentType)
        , m_configuration(configuration)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contentType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ContentType& m_contentType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaSourceConfiguration& m_configuration;
};

class DurationChanged {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSourceProxy_DurationChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DurationChanged(const MediaTime& duration)
        : m_duration(duration)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_duration;
    }

private:
    const MediaTime& m_duration;
};

class BufferedChanged {
public:
    using Arguments = std::tuple<WebCore::PlatformTimeRanges>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSourceProxy_BufferedChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit BufferedChanged(const WebCore::PlatformTimeRanges& buffered)
        : m_buffered(buffered)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_buffered;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PlatformTimeRanges& m_buffered;
};

class SetMediaPlayerReadyState {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerReadyState>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSourceProxy_SetMediaPlayerReadyState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMediaPlayerReadyState(WebCore::MediaPlayerReadyState readyState)
        : m_readyState(readyState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_readyState;
    }

private:
    WebCore::MediaPlayerReadyState m_readyState;
};

class SetTimeFudgeFactor {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSourceProxy_SetTimeFudgeFactor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetTimeFudgeFactor(const MediaTime& fudgeFactor)
        : m_fudgeFactor(fudgeFactor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_fudgeFactor;
    }

private:
    const MediaTime& m_fudgeFactor;
};

class MarkEndOfStream {
public:
    using Arguments = std::tuple<WebCore::MediaSourcePrivateEndOfStreamStatus>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSourceProxy_MarkEndOfStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MarkEndOfStream(WebCore::MediaSourcePrivateEndOfStreamStatus status)
        : m_status(status)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_status;
    }

private:
    WebCore::MediaSourcePrivateEndOfStreamStatus m_status;
};

class UnmarkEndOfStream {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSourceProxy_UnmarkEndOfStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UnmarkEndOfStream()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Shutdown {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaSourceProxy_Shutdown; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Shutdown()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

} // namespace RemoteMediaSourceProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
