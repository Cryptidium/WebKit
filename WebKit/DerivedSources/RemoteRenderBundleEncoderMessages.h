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
#include "Connection.h"
#include "MessageNames.h"
#include "WebGPURenderBundleDescriptor.h"
#include <WebCore/WebGPUIndexFormat.h>
#include <WebCore/WebGPUIntegralTypes.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
struct WebGPUIdentifierType;
using WebGPUIdentifier = AtomicObjectIdentifier<WebGPUIdentifierType>;
}

namespace Messages {
namespace RemoteRenderBundleEncoder {

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
    return IPC::ReceiverName::RemoteRenderBundleEncoder;
}

class Destruct {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_Destruct; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Destruct()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetPipeline {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_SetPipeline; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit SetPipeline(const WebKit::WebGPUIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class SetIndexBuffer {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::IndexFormat, std::optional<WebCore::WebGPU::Size64>, std::optional<WebCore::WebGPU::Size64>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_SetIndexBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    SetIndexBuffer(const WebKit::WebGPUIdentifier& identifier, const WebCore::WebGPU::IndexFormat& indexFormat, const std::optional<WebCore::WebGPU::Size64>& offset, const std::optional<WebCore::WebGPU::Size64>& size)
        : m_identifier(identifier)
        , m_indexFormat(indexFormat)
        , m_offset(offset)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indexFormat;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_offset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::IndexFormat& m_indexFormat;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size64>& m_offset;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size64>& m_size;
};

class SetVertexBuffer {
public:
    using Arguments = std::tuple<WebCore::WebGPU::Index32, WebKit::WebGPUIdentifier, std::optional<WebCore::WebGPU::Size64>, std::optional<WebCore::WebGPU::Size64>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_SetVertexBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    SetVertexBuffer(const WebCore::WebGPU::Index32& slot, const WebKit::WebGPUIdentifier& identifier, const std::optional<WebCore::WebGPU::Size64>& offset, const std::optional<WebCore::WebGPU::Size64>& size)
        : m_slot(slot)
        , m_identifier(identifier)
        , m_offset(offset)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_slot;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_offset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Index32& m_slot;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size64>& m_offset;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size64>& m_size;
};

class UnsetVertexBuffer {
public:
    using Arguments = std::tuple<WebCore::WebGPU::Index32, std::optional<WebCore::WebGPU::Size64>, std::optional<WebCore::WebGPU::Size64>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_UnsetVertexBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UnsetVertexBuffer(const WebCore::WebGPU::Index32& slot, const std::optional<WebCore::WebGPU::Size64>& offset, const std::optional<WebCore::WebGPU::Size64>& size)
        : m_slot(slot)
        , m_offset(offset)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_slot;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_offset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Index32& m_slot;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size64>& m_offset;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size64>& m_size;
};

class Draw {
public:
    using Arguments = std::tuple<WebCore::WebGPU::Size32, std::optional<WebCore::WebGPU::Size32>, std::optional<WebCore::WebGPU::Size32>, std::optional<WebCore::WebGPU::Size32>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_Draw; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Draw(const WebCore::WebGPU::Size32& vertexCount, const std::optional<WebCore::WebGPU::Size32>& instanceCount, const std::optional<WebCore::WebGPU::Size32>& firstVertex, const std::optional<WebCore::WebGPU::Size32>& firstInstance)
        : m_vertexCount(vertexCount)
        , m_instanceCount(instanceCount)
        , m_firstVertex(firstVertex)
        , m_firstInstance(firstInstance)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_vertexCount;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_instanceCount;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstVertex;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstInstance;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size32& m_vertexCount;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size32>& m_instanceCount;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size32>& m_firstVertex;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size32>& m_firstInstance;
};

class DrawIndexed {
public:
    using Arguments = std::tuple<WebCore::WebGPU::Size32, std::optional<WebCore::WebGPU::Size32>, std::optional<WebCore::WebGPU::Size32>, std::optional<WebCore::WebGPU::SignedOffset32>, std::optional<WebCore::WebGPU::Size32>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_DrawIndexed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawIndexed(const WebCore::WebGPU::Size32& indexCount, const std::optional<WebCore::WebGPU::Size32>& instanceCount, const std::optional<WebCore::WebGPU::Size32>& firstIndex, const std::optional<WebCore::WebGPU::SignedOffset32>& baseVertex, const std::optional<WebCore::WebGPU::Size32>& firstInstance)
        : m_indexCount(indexCount)
        , m_instanceCount(instanceCount)
        , m_firstIndex(firstIndex)
        , m_baseVertex(baseVertex)
        , m_firstInstance(firstInstance)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indexCount;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_instanceCount;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstIndex;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_baseVertex;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstInstance;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size32& m_indexCount;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size32>& m_instanceCount;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size32>& m_firstIndex;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::SignedOffset32>& m_baseVertex;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size32>& m_firstInstance;
};

class DrawIndirect {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_DrawIndirect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawIndirect(const WebKit::WebGPUIdentifier& indirectBuffer, const WebCore::WebGPU::Size64& indirectOffset)
        : m_indirectBuffer(indirectBuffer)
        , m_indirectOffset(indirectOffset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indirectBuffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indirectOffset;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_indirectBuffer;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_indirectOffset;
};

class DrawIndexedIndirect {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_DrawIndexedIndirect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawIndexedIndirect(const WebKit::WebGPUIdentifier& indirectBuffer, const WebCore::WebGPU::Size64& indirectOffset)
        : m_indirectBuffer(indirectBuffer)
        , m_indirectOffset(indirectOffset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indirectBuffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indirectOffset;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_indirectBuffer;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_indirectOffset;
};

class SetBindGroup {
public:
    using Arguments = std::tuple<WebCore::WebGPU::Index32, std::optional<WebKit::WebGPUIdentifier>, std::optional<Vector<WebCore::WebGPU::BufferDynamicOffset>>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_SetBindGroup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    SetBindGroup(const WebCore::WebGPU::Index32& index, const std::optional<WebKit::WebGPUIdentifier>& identifier, const std::optional<Vector<WebCore::WebGPU::BufferDynamicOffset>>& dynamicOffsets)
        : m_index(index)
        , m_identifier(identifier)
        , m_dynamicOffsets(dynamicOffsets)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_index;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dynamicOffsets;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Index32& m_index;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebGPUIdentifier>& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<Vector<WebCore::WebGPU::BufferDynamicOffset>>& m_dynamicOffsets;
};

class PushDebugGroup {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_PushDebugGroup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit PushDebugGroup(const String& groupLabel)
        : m_groupLabel(groupLabel)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_groupLabel;
    }

private:
    const String& m_groupLabel;
};

class PopDebugGroup {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_PopDebugGroup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    PopDebugGroup()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class InsertDebugMarker {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_InsertDebugMarker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit InsertDebugMarker(const String& markerLabel)
        : m_markerLabel(markerLabel)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_markerLabel;
    }

private:
    const String& m_markerLabel;
};

class Finish {
public:
    using Arguments = std::tuple<WebKit::WebGPU::RenderBundleDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_Finish; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Finish(const WebKit::WebGPU::RenderBundleDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::RenderBundleDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class SetLabel {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderBundleEncoder_SetLabel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit SetLabel(const String& label)
        : m_label(label)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_label;
    }

private:
    const String& m_label;
};

} // namespace RemoteRenderBundleEncoder
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
