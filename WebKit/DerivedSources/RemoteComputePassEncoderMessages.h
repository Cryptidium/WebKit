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
namespace RemoteComputePassEncoder {

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
    return IPC::ReceiverName::RemoteComputePassEncoder;
}

class Destruct {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_Destruct; }
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_SetPipeline; }
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

class Dispatch {
public:
    using Arguments = std::tuple<WebCore::WebGPU::Size32, WebCore::WebGPU::Size32, WebCore::WebGPU::Size32>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_Dispatch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Dispatch(const WebCore::WebGPU::Size32& workgroupCountX, const WebCore::WebGPU::Size32& workgroupCountY, const WebCore::WebGPU::Size32& workgroupCountZ)
        : m_workgroupCountX(workgroupCountX)
        , m_workgroupCountY(workgroupCountY)
        , m_workgroupCountZ(workgroupCountZ)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workgroupCountX;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workgroupCountY;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workgroupCountZ;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size32& m_workgroupCountX;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size32& m_workgroupCountY;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size32& m_workgroupCountZ;
};

class DispatchIndirect {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_DispatchIndirect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DispatchIndirect(const WebKit::WebGPUIdentifier& indirectBuffer, const WebCore::WebGPU::Size64& indirectOffset)
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

class End {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_End; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    End()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetBindGroup {
public:
    using Arguments = std::tuple<WebCore::WebGPU::Index32, std::optional<WebKit::WebGPUIdentifier>, std::optional<Vector<WebCore::WebGPU::BufferDynamicOffset>>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_SetBindGroup; }
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_PushDebugGroup; }
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_PopDebugGroup; }
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_InsertDebugMarker; }
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

class SetLabel {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteComputePassEncoder_SetLabel; }
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

} // namespace RemoteComputePassEncoder
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
