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
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/MediaTime.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
struct SeekTarget;
}

namespace Messages {
namespace MediaSourcePrivateRemoteMessageReceiver {

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
    return IPC::ReceiverName::MediaSourcePrivateRemoteMessageReceiver;
}

class ProxyWaitForTarget {
public:
    using Arguments = std::tuple<WebCore::SeekTarget>;

    static IPC::MessageName name() { return IPC::MessageName::MediaSourcePrivateRemoteMessageReceiver_ProxyWaitForTarget; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::MediaSourcePrivateRemoteMessageReceiver_ProxyWaitForTargetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<MediaTime, WebCore::PlatformMediaError>>;
    using Reply = CompletionHandler<void(Expected<MediaTime, WebCore::PlatformMediaError>&&)>;
    using Promise = WTF::NativePromise<Expected<MediaTime, WebCore::PlatformMediaError>, IPC::Error>;
    explicit ProxyWaitForTarget(const WebCore::SeekTarget& target)
        : m_target(target)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_target;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SeekTarget& m_target;
};

class ProxySeekToTime {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::MediaSourcePrivateRemoteMessageReceiver_ProxySeekToTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::MediaSourcePrivateRemoteMessageReceiver_ProxySeekToTimeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebCore::PlatformMediaError>>;
    using Reply = CompletionHandler<void(Expected<void, WebCore::PlatformMediaError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebCore::PlatformMediaError>, IPC::Error>;
    explicit ProxySeekToTime(const MediaTime& time)
        : m_time(time)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_time;
    }

private:
    const MediaTime& m_time;
};

} // namespace MediaSourcePrivateRemoteMessageReceiver
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
