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

#if PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(VIDEO)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "SharedVideoFrame.h"
#include <WebCore/SharedMemory.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebKit {
struct RemoteVideoFrameIdentifierType;
using RemoteVideoFrameIdentifier = AtomicObjectIdentifier<RemoteVideoFrameIdentifierType>;
}

namespace Messages {
namespace RemoteVideoFrameObjectHeapProxyProcessor {

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
    return IPC::ReceiverName::RemoteVideoFrameObjectHeapProxyProcessor;
}

class SetSharedVideoFrameSemaphore {
public:
    using Arguments = std::tuple<IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteVideoFrameObjectHeapProxyProcessor_SetSharedVideoFrameSemaphore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSharedVideoFrameSemaphore(const IPC::Semaphore& semaphore)
        : m_semaphore(semaphore)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_semaphore;
    }

private:
    const IPC::Semaphore& m_semaphore;
};

class SetSharedVideoFrameMemory {
public:
    using Arguments = std::tuple<WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteVideoFrameObjectHeapProxyProcessor_SetSharedVideoFrameMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSharedVideoFrameMemory(WebCore::SharedMemory::Handle&& storageHandle)
        : m_storageHandle(WTFMove(storageHandle))
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_storageHandle);
    }

private:
    WebCore::SharedMemory::Handle&& m_storageHandle;
};

class NewVideoFrameBuffer {
public:
    using Arguments = std::tuple<WebKit::RemoteVideoFrameIdentifier, std::optional<WebKit::SharedVideoFrame::Buffer>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteVideoFrameObjectHeapProxyProcessor_NewVideoFrameBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NewVideoFrameBuffer(const WebKit::RemoteVideoFrameIdentifier& identifier, std::optional<WebKit::SharedVideoFrame::Buffer>&& frame)
        : m_identifier(identifier)
        , m_frame(WTFMove(frame))
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << WTFMove(m_frame);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteVideoFrameIdentifier& m_identifier;
    std::optional<WebKit::SharedVideoFrame::Buffer>&& m_frame;
};

class NewConvertedVideoFrameBuffer {
public:
    using Arguments = std::tuple<std::optional<WebKit::SharedVideoFrame::Buffer>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteVideoFrameObjectHeapProxyProcessor_NewConvertedVideoFrameBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit NewConvertedVideoFrameBuffer(std::optional<WebKit::SharedVideoFrame::Buffer>&& frame)
        : m_frame(WTFMove(frame))
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_frame);
    }

private:
    std::optional<WebKit::SharedVideoFrame::Buffer>&& m_frame;
};

} // namespace RemoteVideoFrameObjectHeapProxyProcessor
} // namespace Messages

#endif // PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
