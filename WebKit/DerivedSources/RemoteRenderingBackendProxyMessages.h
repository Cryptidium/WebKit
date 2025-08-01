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

#if ENABLE(GPU_PROCESS)

#include "ArgumentCoders.h"
#include "BufferIdentifierSet.h"
#include "Connection.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "RemoteImageBufferSetIdentifier.h"
#include "RenderingUpdateID.h"
#include <utility>
#include <wtf/Forward.h>
#include <wtf/OptionSet.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace WebKit {
struct MarkSurfacesAsVolatileRequestIdentifierType;
using MarkSurfacesAsVolatileRequestIdentifier = ObjectIdentifier<MarkSurfacesAsVolatileRequestIdentifierType>;
}

namespace Messages {
namespace RemoteRenderingBackendProxy {

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
    return IPC::ReceiverName::RemoteRenderingBackendProxy;
}

class DidFinalizeRenderingUpdate {
public:
    using Arguments = std::tuple<WebKit::RenderingUpdateID>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackendProxy_DidFinalizeRenderingUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFinalizeRenderingUpdate(const WebKit::RenderingUpdateID& didRenderingUpdateID)
        : m_didRenderingUpdateID(didRenderingUpdateID)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_didRenderingUpdateID;
    }

private:
    const WebKit::RenderingUpdateID& m_didRenderingUpdateID;
};

class DidInitialize {
public:
    using Arguments = std::tuple<IPC::Semaphore, IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackendProxy_DidInitialize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidInitialize(const IPC::Semaphore& wakeUpSemaphore, const IPC::Semaphore& clientWaitSemaphore)
        : m_wakeUpSemaphore(wakeUpSemaphore)
        , m_clientWaitSemaphore(clientWaitSemaphore)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_wakeUpSemaphore;
        encoder << m_clientWaitSemaphore;
    }

private:
    const IPC::Semaphore& m_wakeUpSemaphore;
    const IPC::Semaphore& m_clientWaitSemaphore;
};

class DidMarkLayersAsVolatile {
public:
    using Arguments = std::tuple<WebKit::MarkSurfacesAsVolatileRequestIdentifier, Vector<std::pair<WebKit::RemoteImageBufferSetIdentifier, OptionSet<WebKit::BufferInSetType>>>, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackendProxy_DidMarkLayersAsVolatile; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidMarkLayersAsVolatile(const WebKit::MarkSurfacesAsVolatileRequestIdentifier& requestIdentifier, const Vector<std::pair<WebKit::RemoteImageBufferSetIdentifier, OptionSet<WebKit::BufferInSetType>>>& markedBufferSets, bool didMarkAllLayersAsVolatile)
        : m_requestIdentifier(requestIdentifier)
        , m_markedBufferSets(markedBufferSets)
        , m_didMarkAllLayersAsVolatile(didMarkAllLayersAsVolatile)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_markedBufferSets;
        encoder << m_didMarkAllLayersAsVolatile;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MarkSurfacesAsVolatileRequestIdentifier& m_requestIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::pair<WebKit::RemoteImageBufferSetIdentifier, OptionSet<WebKit::BufferInSetType>>>& m_markedBufferSets;
    bool m_didMarkAllLayersAsVolatile;
};

} // namespace RemoteRenderingBackendProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
