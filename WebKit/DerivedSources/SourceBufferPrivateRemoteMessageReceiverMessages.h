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
#include <WebCore/SharedMemory.h>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/MediaTime.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace WebCore {
struct SourceBufferEvictionData;
}

namespace WebKit {
struct InitializationSegmentInfo;
}

namespace Messages {
namespace SourceBufferPrivateRemoteMessageReceiver {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInWebProcess());
        }
    );
#endif
    return IPC::ReceiverName::SourceBufferPrivateRemoteMessageReceiver;
}

class SourceBufferPrivateDidReceiveInitializationSegment {
public:
    using Arguments = std::tuple<WebKit::InitializationSegmentInfo>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveInitializationSegment; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveInitializationSegmentReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebCore::PlatformMediaError>>;
    using Reply = CompletionHandler<void(Expected<void, WebCore::PlatformMediaError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebCore::PlatformMediaError>, IPC::Error>;
    explicit SourceBufferPrivateDidReceiveInitializationSegment(const WebKit::InitializationSegmentInfo& segmentConfiguration)
        : m_segmentConfiguration(segmentConfiguration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_segmentConfiguration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::InitializationSegmentInfo& m_segmentConfiguration;
};

class TakeOwnershipOfMemory {
public:
    using Arguments = std::tuple<WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_TakeOwnershipOfMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TakeOwnershipOfMemory(WebCore::SharedMemory::Handle&& remoteData)
        : m_remoteData(WTFMove(remoteData))
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_remoteData);
    }

private:
    WebCore::SharedMemory::Handle&& m_remoteData;
};

class SourceBufferPrivateHighestPresentationTimestampChanged {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateHighestPresentationTimestampChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SourceBufferPrivateHighestPresentationTimestampChanged(const MediaTime& timestamp)
        : m_timestamp(timestamp)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_timestamp;
    }

private:
    const MediaTime& m_timestamp;
};

class SourceBufferPrivateBufferedChanged {
public:
    using Arguments = std::tuple<Vector<WebCore::PlatformTimeRanges>>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateBufferedChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateBufferedChangedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SourceBufferPrivateBufferedChanged(const Vector<WebCore::PlatformTimeRanges>& trackBuffers)
        : m_trackBuffers(trackBuffers)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_trackBuffers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::PlatformTimeRanges>& m_trackBuffers;
};

class SourceBufferPrivateDurationChanged {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDurationChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDurationChangedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SourceBufferPrivateDurationChanged(const MediaTime& duration)
        : m_duration(duration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_duration;
    }

private:
    const MediaTime& m_duration;
};

class SourceBufferPrivateDidDropSample {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidDropSample; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SourceBufferPrivateDidDropSample()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SourceBufferPrivateDidReceiveRenderingError {
public:
    using Arguments = std::tuple<int64_t>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveRenderingError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SourceBufferPrivateDidReceiveRenderingError(int64_t errorCode)
        : m_errorCode(errorCode)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_errorCode;
    }

private:
    int64_t m_errorCode;
};

class SourceBufferPrivateEvictionDataChanged {
public:
    using Arguments = std::tuple<WebCore::SourceBufferEvictionData>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateEvictionDataChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SourceBufferPrivateEvictionDataChanged(const WebCore::SourceBufferEvictionData& evictionData)
        : m_evictionData(evictionData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_evictionData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SourceBufferEvictionData& m_evictionData;
};

class SourceBufferPrivateDidAttach {
public:
    using Arguments = std::tuple<WebKit::InitializationSegmentInfo>;

    static IPC::MessageName name() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidAttach; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidAttachReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebCore::PlatformMediaError>>;
    using Reply = CompletionHandler<void(Expected<void, WebCore::PlatformMediaError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebCore::PlatformMediaError>, IPC::Error>;
    explicit SourceBufferPrivateDidAttach(const WebKit::InitializationSegmentInfo& segmentConfiguration)
        : m_segmentConfiguration(segmentConfiguration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_segmentConfiguration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::InitializationSegmentInfo& m_segmentConfiguration;
};

} // namespace SourceBufferPrivateRemoteMessageReceiver
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
