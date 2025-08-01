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

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include "UpdateInfo.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace WebKit {
class LayerTreeContext;
}

namespace Messages {
namespace DrawingAreaProxy {

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
    return IPC::ReceiverName::DrawingAreaProxy;
}

class EnterAcceleratedCompositingMode {
public:
    using Arguments = std::tuple<uint64_t, WebKit::LayerTreeContext>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingAreaProxy_EnterAcceleratedCompositingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnterAcceleratedCompositingMode(uint64_t backingStoreStateID, const WebKit::LayerTreeContext& context)
        : m_backingStoreStateID(backingStoreStateID)
        , m_context(context)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backingStoreStateID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
    }

private:
    uint64_t m_backingStoreStateID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::LayerTreeContext& m_context;
};

class UpdateAcceleratedCompositingMode {
public:
    using Arguments = std::tuple<uint64_t, WebKit::LayerTreeContext>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingAreaProxy_UpdateAcceleratedCompositingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateAcceleratedCompositingMode(uint64_t backingStoreStateID, const WebKit::LayerTreeContext& context)
        : m_backingStoreStateID(backingStoreStateID)
        , m_context(context)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backingStoreStateID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
    }

private:
    uint64_t m_backingStoreStateID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::LayerTreeContext& m_context;
};

class DidFirstLayerFlush {
public:
    using Arguments = std::tuple<uint64_t, WebKit::LayerTreeContext>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingAreaProxy_DidFirstLayerFlush; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFirstLayerFlush(uint64_t backingStoreStateID, const WebKit::LayerTreeContext& context)
        : m_backingStoreStateID(backingStoreStateID)
        , m_context(context)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backingStoreStateID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
    }

private:
    uint64_t m_backingStoreStateID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::LayerTreeContext& m_context;
};

class DispatchPresentationCallbacksAfterFlushingLayers {
public:
    using Arguments = std::tuple<Vector<IPC::AsyncReplyID>>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingAreaProxy_DispatchPresentationCallbacksAfterFlushingLayers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchPresentationCallbacksAfterFlushingLayers(const Vector<IPC::AsyncReplyID>& callbackIDs)
        : m_callbackIDs(callbackIDs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_callbackIDs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<IPC::AsyncReplyID>& m_callbackIDs;
};

#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
class Update {
public:
    using Arguments = std::tuple<uint64_t, WebKit::UpdateInfo>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingAreaProxy_Update; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Update(uint64_t stateID, WebKit::UpdateInfo&& updateInfo)
        : m_stateID(stateID)
        , m_updateInfo(WTFMove(updateInfo))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_stateID;
        encoder << WTFMove(m_updateInfo);
    }

private:
    uint64_t m_stateID;
    WebKit::UpdateInfo&& m_updateInfo;
};
#endif

#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
class ExitAcceleratedCompositingMode {
public:
    using Arguments = std::tuple<uint64_t, WebKit::UpdateInfo>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingAreaProxy_ExitAcceleratedCompositingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ExitAcceleratedCompositingMode(uint64_t backingStoreStateID, WebKit::UpdateInfo&& updateInfo)
        : m_backingStoreStateID(backingStoreStateID)
        , m_updateInfo(WTFMove(updateInfo))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backingStoreStateID;
        encoder << WTFMove(m_updateInfo);
    }

private:
    uint64_t m_backingStoreStateID;
    WebKit::UpdateInfo&& m_updateInfo;
};
#endif

} // namespace DrawingAreaProxy
} // namespace Messages
