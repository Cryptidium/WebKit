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

#if PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(MEDIA_STREAM)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <WebCore/HostingContext.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
class IntSize;
}

namespace WebKit {
struct SampleBufferDisplayLayerIdentifierType;
using SampleBufferDisplayLayerIdentifier = ObjectIdentifier<SampleBufferDisplayLayerIdentifierType>;
}

namespace Messages {
namespace RemoteSampleBufferDisplayLayerManager {

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
    return IPC::ReceiverName::RemoteSampleBufferDisplayLayerManager;
}

class CreateLayer {
public:
    using Arguments = std::tuple<WebKit::SampleBufferDisplayLayerIdentifier, bool, WebCore::IntSize, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSampleBufferDisplayLayerManager_CreateLayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteSampleBufferDisplayLayerManager_CreateLayerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::HostingContext>;
    using Reply = CompletionHandler<void(WebCore::HostingContext&&)>;
    using Promise = WTF::NativePromise<WebCore::HostingContext, IPC::Error>;
    CreateLayer(const WebKit::SampleBufferDisplayLayerIdentifier& id, bool hideRootLayer, const WebCore::IntSize& size, bool shouldMaintainAspectRatio, bool canShowWhileLocked)
        : m_id(id)
        , m_hideRootLayer(hideRootLayer)
        , m_size(size)
        , m_shouldMaintainAspectRatio(shouldMaintainAspectRatio)
        , m_canShowWhileLocked(canShowWhileLocked)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_hideRootLayer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
        encoder << m_shouldMaintainAspectRatio;
        encoder << m_canShowWhileLocked;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::SampleBufferDisplayLayerIdentifier& m_id;
    bool m_hideRootLayer;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_size;
    bool m_shouldMaintainAspectRatio;
    bool m_canShowWhileLocked;
};

class ReleaseLayer {
public:
    using Arguments = std::tuple<WebKit::SampleBufferDisplayLayerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteSampleBufferDisplayLayerManager_ReleaseLayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseLayer(const WebKit::SampleBufferDisplayLayerIdentifier& id)
        : m_id(id)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::SampleBufferDisplayLayerIdentifier& m_id;
};

} // namespace RemoteSampleBufferDisplayLayerManager
} // namespace Messages

#endif // PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(MEDIA_STREAM)
