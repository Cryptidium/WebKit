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
#include "WebGPUCommandBufferDescriptor.h"
#include "WebGPUComputePassDescriptor.h"
#include "WebGPUExtent3D.h"
#include "WebGPUImageCopyBuffer.h"
#include "WebGPUImageCopyTexture.h"
#include "WebGPURenderPassDescriptor.h"
#include <WebCore/WebGPUIntegralTypes.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
struct WebGPUIdentifierType;
using WebGPUIdentifier = AtomicObjectIdentifier<WebGPUIdentifierType>;
}

namespace Messages {
namespace RemoteCommandEncoder {

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
    return IPC::ReceiverName::RemoteCommandEncoder;
}

class BeginRenderPass {
public:
    using Arguments = std::tuple<WebKit::WebGPU::RenderPassDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_BeginRenderPass; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BeginRenderPass(const WebKit::WebGPU::RenderPassDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::RenderPassDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class BeginComputePass {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebGPU::ComputePassDescriptor>, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_BeginComputePass; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BeginComputePass(const std::optional<WebKit::WebGPU::ComputePassDescriptor>& descriptor, const WebKit::WebGPUIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebGPU::ComputePassDescriptor>& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CopyBufferToBuffer {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64, WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64, WebCore::WebGPU::Size64>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_CopyBufferToBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyBufferToBuffer(const WebKit::WebGPUIdentifier& source, const WebCore::WebGPU::Size64& sourceOffset, const WebKit::WebGPUIdentifier& destination, const WebCore::WebGPU::Size64& destinationOffset, const WebCore::WebGPU::Size64& size)
        : m_source(source)
        , m_sourceOffset(sourceOffset)
        , m_destination(destination)
        , m_destinationOffset(destinationOffset)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_source;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourceOffset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destination;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationOffset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_source;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_sourceOffset;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_destinationOffset;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_size;
};

class CopyBufferToTexture {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ImageCopyBuffer, WebKit::WebGPU::ImageCopyTexture, WebKit::WebGPU::Extent3D>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_CopyBufferToTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyBufferToTexture(const WebKit::WebGPU::ImageCopyBuffer& source, const WebKit::WebGPU::ImageCopyTexture& destination, const WebKit::WebGPU::Extent3D& copySize)
        : m_source(source)
        , m_destination(destination)
        , m_copySize(copySize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_source;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destination;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_copySize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyBuffer& m_source;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyTexture& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::Extent3D& m_copySize;
};

class CopyTextureToBuffer {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ImageCopyTexture, WebKit::WebGPU::ImageCopyBuffer, WebKit::WebGPU::Extent3D>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_CopyTextureToBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyTextureToBuffer(const WebKit::WebGPU::ImageCopyTexture& source, const WebKit::WebGPU::ImageCopyBuffer& destination, const WebKit::WebGPU::Extent3D& copySize)
        : m_source(source)
        , m_destination(destination)
        , m_copySize(copySize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_source;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destination;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_copySize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyTexture& m_source;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyBuffer& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::Extent3D& m_copySize;
};

class CopyTextureToTexture {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ImageCopyTexture, WebKit::WebGPU::ImageCopyTexture, WebKit::WebGPU::Extent3D>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_CopyTextureToTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyTextureToTexture(const WebKit::WebGPU::ImageCopyTexture& source, const WebKit::WebGPU::ImageCopyTexture& destination, const WebKit::WebGPU::Extent3D& copySize)
        : m_source(source)
        , m_destination(destination)
        , m_copySize(copySize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_source;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destination;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_copySize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyTexture& m_source;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyTexture& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::Extent3D& m_copySize;
};

class ClearBuffer {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64, std::optional<WebCore::WebGPU::Size64>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_ClearBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClearBuffer(const WebKit::WebGPUIdentifier& buffer, const WebCore::WebGPU::Size64& offset, const std::optional<WebCore::WebGPU::Size64>& size)
        : m_buffer(buffer)
        , m_offset(offset)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_buffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_offset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_buffer;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_offset;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WebGPU::Size64>& m_size;
};

class Destruct {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_Destruct; }
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

class PushDebugGroup {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_PushDebugGroup; }
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_PopDebugGroup; }
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_InsertDebugMarker; }
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

class WriteTimestamp {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size32>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_WriteTimestamp; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    WriteTimestamp(const WebKit::WebGPUIdentifier& identifier, const WebCore::WebGPU::Size32& queryIndex)
        : m_identifier(identifier)
        , m_queryIndex(queryIndex)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_queryIndex;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size32& m_queryIndex;
};

class ResolveQuerySet {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size32, WebCore::WebGPU::Size32, WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_ResolveQuerySet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ResolveQuerySet(const WebKit::WebGPUIdentifier& identifier, const WebCore::WebGPU::Size32& firstQuery, const WebCore::WebGPU::Size32& queryCount, const WebKit::WebGPUIdentifier& destination, const WebCore::WebGPU::Size64& destinationOffset)
        : m_identifier(identifier)
        , m_firstQuery(firstQuery)
        , m_queryCount(queryCount)
        , m_destination(destination)
        , m_destinationOffset(destinationOffset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstQuery;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_queryCount;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destination;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationOffset;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size32& m_firstQuery;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size32& m_queryCount;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_destinationOffset;
};

class Finish {
public:
    using Arguments = std::tuple<WebKit::WebGPU::CommandBufferDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_Finish; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Finish(const WebKit::WebGPU::CommandBufferDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::CommandBufferDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class SetLabel {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCommandEncoder_SetLabel; }
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

} // namespace RemoteCommandEncoder
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
