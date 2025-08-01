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
#include <WebCore/SourceBufferPrivate.h>
#include <WebCore/TrackBase.h>
#include <utility>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/MediaTime.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace IPC {
class SharedBufferReference;
}

namespace WebCore {
class ContentType;
struct SeekTarget;
struct SourceBufferEvictionData;
}

namespace Messages {
namespace RemoteSourceBufferProxy {

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
    return IPC::ReceiverName::RemoteSourceBufferProxy;
}

class SetActive {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetActive; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetActive(bool active)
        : m_active(active)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_active;
    }

private:
    bool m_active;
};

class CanSwitchToType {
public:
    using Arguments = std::tuple<WebCore::ContentType>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_CanSwitchToType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit CanSwitchToType(const WebCore::ContentType& contentType)
        : m_contentType(contentType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contentType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ContentType& m_contentType;
};

class SetMode {
public:
    using Arguments = std::tuple<WebCore::SourceBufferAppendMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMode(const WebCore::SourceBufferAppendMode& appendMode)
        : m_appendMode(appendMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_appendMode;
    }

private:
    const WebCore::SourceBufferAppendMode& m_appendMode;
};

class Append {
public:
    using Arguments = std::tuple<IPC::SharedBufferReference>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_Append; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteSourceBufferProxy_AppendReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebCore::PlatformMediaError>, MediaTime>;
    using Reply = CompletionHandler<void(Expected<void, WebCore::PlatformMediaError>&&, MediaTime&&)>;
    using Promise = WTF::NativePromise<std::tuple<Expected<void, WebCore::PlatformMediaError>, MediaTime>, IPC::Error>;
    explicit Append(const IPC::SharedBufferReference& data)
        : m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::SharedBufferReference& m_data;
};

class Abort {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_Abort; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Abort()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ResetParserState {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_ResetParserState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResetParserState()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RemovedFromMediaSource {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_RemovedFromMediaSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemovedFromMediaSource()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetMediaSourceEnded {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetMediaSourceEnded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMediaSourceEnded(bool isEnded)
        : m_isEnded(isEnded)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isEnded;
    }

private:
    bool m_isEnded;
};

class StartChangingType {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_StartChangingType; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartChangingType()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class AddTrackBuffer {
public:
    using Arguments = std::tuple<WebCore::TrackID>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_AddTrackBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddTrackBuffer(WebCore::TrackID trackID)
        : m_trackID(trackID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
    }

private:
    WebCore::TrackID m_trackID;
};

class ResetTrackBuffers {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_ResetTrackBuffers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResetTrackBuffers()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ClearTrackBuffers {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_ClearTrackBuffers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearTrackBuffers()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetAllTrackBuffersNeedRandomAccess {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetAllTrackBuffersNeedRandomAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetAllTrackBuffersNeedRandomAccess()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RemoveCodedFrames {
public:
    using Arguments = std::tuple<MediaTime, MediaTime, MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_RemoveCodedFrames; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteSourceBufferProxy_RemoveCodedFramesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    RemoveCodedFrames(const MediaTime& start, const MediaTime& end, const MediaTime& currentTime)
        : m_start(start)
        , m_end(end)
        , m_currentTime(currentTime)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_start;
        encoder << m_end;
        encoder << m_currentTime;
    }

private:
    const MediaTime& m_start;
    const MediaTime& m_end;
    const MediaTime& m_currentTime;
};

class EvictCodedFrames {
public:
    using Arguments = std::tuple<uint64_t, MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_EvictCodedFrames; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::PlatformTimeRanges>, WebCore::SourceBufferEvictionData>;
    using Reply = CompletionHandler<void(Vector<WebCore::PlatformTimeRanges>&&, WebCore::SourceBufferEvictionData&&)>;
    EvictCodedFrames(uint64_t newDataSize, const MediaTime& currentTime)
        : m_newDataSize(newDataSize)
        , m_currentTime(currentTime)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_newDataSize;
        encoder << m_currentTime;
    }

private:
    uint64_t m_newDataSize;
    const MediaTime& m_currentTime;
};

class AsyncEvictCodedFrames {
public:
    using Arguments = std::tuple<uint64_t, MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_AsyncEvictCodedFrames; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AsyncEvictCodedFrames(uint64_t newDataSize, const MediaTime& currentTime)
        : m_newDataSize(newDataSize)
        , m_currentTime(currentTime)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_newDataSize;
        encoder << m_currentTime;
    }

private:
    uint64_t m_newDataSize;
    const MediaTime& m_currentTime;
};

class ReenqueueMediaIfNeeded {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_ReenqueueMediaIfNeeded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReenqueueMediaIfNeeded(const MediaTime& currentMediaTime)
        : m_currentMediaTime(currentMediaTime)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_currentMediaTime;
    }

private:
    const MediaTime& m_currentMediaTime;
};

class SetGroupStartTimestamp {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetGroupStartTimestamp; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetGroupStartTimestamp(const MediaTime& timestamp)
        : m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_timestamp;
    }

private:
    const MediaTime& m_timestamp;
};

class SetGroupStartTimestampToEndTimestamp {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetGroupStartTimestampToEndTimestamp; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetGroupStartTimestampToEndTimestamp()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetShouldGenerateTimestamps {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetShouldGenerateTimestamps; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldGenerateTimestamps(bool shouldGenerateTimestamps)
        : m_shouldGenerateTimestamps(shouldGenerateTimestamps)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldGenerateTimestamps;
    }

private:
    bool m_shouldGenerateTimestamps;
};

class ResetTimestampOffsetInTrackBuffers {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_ResetTimestampOffsetInTrackBuffers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResetTimestampOffsetInTrackBuffers()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetTimestampOffset {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetTimestampOffset; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetTimestampOffset(const MediaTime& timestampOffset)
        : m_timestampOffset(timestampOffset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_timestampOffset;
    }

private:
    const MediaTime& m_timestampOffset;
};

class SetAppendWindowStart {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetAppendWindowStart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAppendWindowStart(const MediaTime& appendWindowStart)
        : m_appendWindowStart(appendWindowStart)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_appendWindowStart;
    }

private:
    const MediaTime& m_appendWindowStart;
};

class SetAppendWindowEnd {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetAppendWindowEnd; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAppendWindowEnd(const MediaTime& appendWindowEnd)
        : m_appendWindowEnd(appendWindowEnd)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_appendWindowEnd;
    }

private:
    const MediaTime& m_appendWindowEnd;
};

class SetMaximumBufferSize {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetMaximumBufferSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteSourceBufferProxy_SetMaximumBufferSizeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetMaximumBufferSize(uint64_t size)
        : m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_size;
    }

private:
    uint64_t m_size;
};

class ComputeSeekTime {
public:
    using Arguments = std::tuple<WebCore::SeekTarget>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_ComputeSeekTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteSourceBufferProxy_ComputeSeekTimeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<MediaTime, WebCore::PlatformMediaError>>;
    using Reply = CompletionHandler<void(Expected<MediaTime, WebCore::PlatformMediaError>&&)>;
    using Promise = WTF::NativePromise<Expected<MediaTime, WebCore::PlatformMediaError>, IPC::Error>;
    explicit ComputeSeekTime(const WebCore::SeekTarget& target)
        : m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_target;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SeekTarget& m_target;
};

class SeekToTime {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SeekToTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SeekToTime(const MediaTime& time)
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
    const MediaTime& m_time;
};

class UpdateTrackIds {
public:
    using Arguments = std::tuple<Vector<std::pair<WebCore::TrackID, WebCore::TrackID>>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_UpdateTrackIds; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateTrackIds(const Vector<std::pair<WebCore::TrackID, WebCore::TrackID>>& identifierPairs)
        : m_identifierPairs(identifierPairs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifierPairs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::pair<WebCore::TrackID, WebCore::TrackID>>& m_identifierPairs;
};

class BufferedSamplesForTrackId {
public:
    using Arguments = std::tuple<WebCore::TrackID>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_BufferedSamplesForTrackId; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteSourceBufferProxy_BufferedSamplesForTrackIdReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::SourceBufferPrivate::SamplesPromise::Result>;
    using Reply = CompletionHandler<void(WebCore::SourceBufferPrivate::SamplesPromise::Result&&)>;
    using Promise = WTF::NativePromise<WebCore::SourceBufferPrivate::SamplesPromise::Result, IPC::Error>;
    explicit BufferedSamplesForTrackId(WebCore::TrackID trackID)
        : m_trackID(trackID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
    }

private:
    WebCore::TrackID m_trackID;
};

class EnqueuedSamplesForTrackID {
public:
    using Arguments = std::tuple<WebCore::TrackID>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_EnqueuedSamplesForTrackID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteSourceBufferProxy_EnqueuedSamplesForTrackIDReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::SourceBufferPrivate::SamplesPromise::Result>;
    using Reply = CompletionHandler<void(WebCore::SourceBufferPrivate::SamplesPromise::Result&&)>;
    using Promise = WTF::NativePromise<WebCore::SourceBufferPrivate::SamplesPromise::Result, IPC::Error>;
    explicit EnqueuedSamplesForTrackID(WebCore::TrackID trackID)
        : m_trackID(trackID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
    }

private:
    WebCore::TrackID m_trackID;
};

class MemoryPressure {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_MemoryPressure; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MemoryPressure(const MediaTime& currentTime)
        : m_currentTime(currentTime)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_currentTime;
    }

private:
    const MediaTime& m_currentTime;
};

class Detach {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_Detach; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Detach()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Attach {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_Attach; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Attach()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetMaximumQueueDepthForTrackID {
public:
    using Arguments = std::tuple<WebCore::TrackID, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_SetMaximumQueueDepthForTrackID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetMaximumQueueDepthForTrackID(WebCore::TrackID trackID, uint64_t depth)
        : m_trackID(trackID)
        , m_depth(depth)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        encoder << m_depth;
    }

private:
    WebCore::TrackID m_trackID;
    uint64_t m_depth;
};

class MinimumUpcomingPresentationTimeForTrackID {
public:
    using Arguments = std::tuple<WebCore::TrackID>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSourceBufferProxy_MinimumUpcomingPresentationTimeForTrackID; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<MediaTime>;
    using Reply = CompletionHandler<void(MediaTime&&)>;
    explicit MinimumUpcomingPresentationTimeForTrackID(WebCore::TrackID trackID)
        : m_trackID(trackID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
    }

private:
    WebCore::TrackID m_trackID;
};

} // namespace RemoteSourceBufferProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
