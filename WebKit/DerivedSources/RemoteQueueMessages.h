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
#include "WebGPUExtent3D.h"
#include "WebGPUImageCopyExternalImage.h"
#include "WebGPUImageCopyTexture.h"
#include "WebGPUImageCopyTextureTagged.h"
#include "WebGPUImageDataLayout.h"
#include <WebCore/SharedMemory.h>
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
namespace RemoteQueue {

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
    return IPC::ReceiverName::RemoteQueue;
}

class Destruct {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_Destruct; }
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

class Submit {
public:
    using Arguments = std::tuple<Vector<WebKit::WebGPUIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_Submit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit Submit(const Vector<WebKit::WebGPUIdentifier>& commandBuffers)
        : m_commandBuffers(commandBuffers)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_commandBuffers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebGPUIdentifier>& m_commandBuffers;
};

class OnSubmittedWorkDone {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_OnSubmittedWorkDone; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteQueue_OnSubmittedWorkDoneReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    OnSubmittedWorkDone()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class WriteBufferWithCopy {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64, Vector<uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_WriteBufferWithCopy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    WriteBufferWithCopy(const WebKit::WebGPUIdentifier& identifier, const WebCore::WebGPU::Size64& bufferOffset, const Vector<uint8_t>& data)
        : m_identifier(identifier)
        , m_bufferOffset(bufferOffset)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bufferOffset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_bufferOffset;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint8_t>& m_data;
};

class WriteBuffer {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::WebGPU::Size64, std::optional<WebCore::SharedMemory::Handle>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_WriteBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteQueue_WriteBufferReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    WriteBuffer(const WebKit::WebGPUIdentifier& identifier, const WebCore::WebGPU::Size64& bufferOffset, std::optional<WebCore::SharedMemory::Handle>&& data)
        : m_identifier(identifier)
        , m_bufferOffset(bufferOffset)
        , m_data(WTFMove(data))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bufferOffset;
        encoder << WTFMove(m_data);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::Size64& m_bufferOffset;
    std::optional<WebCore::SharedMemory::Handle>&& m_data;
};

class WriteTexture {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ImageCopyTexture, std::optional<WebCore::SharedMemory::Handle>, WebKit::WebGPU::ImageDataLayout, WebKit::WebGPU::Extent3D>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_WriteTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteQueue_WriteTextureReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    WriteTexture(const WebKit::WebGPU::ImageCopyTexture& destination, std::optional<WebCore::SharedMemory::Handle>&& dataHandle, const WebKit::WebGPU::ImageDataLayout& imageDataLayout, const WebKit::WebGPU::Extent3D& size)
        : m_destination(destination)
        , m_dataHandle(WTFMove(dataHandle))
        , m_imageDataLayout(imageDataLayout)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destination;
        encoder << WTFMove(m_dataHandle);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageDataLayout;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyTexture& m_destination;
    std::optional<WebCore::SharedMemory::Handle>&& m_dataHandle;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageDataLayout& m_imageDataLayout;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::Extent3D& m_size;
};

class WriteTextureWithCopy {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ImageCopyTexture, Vector<uint8_t>, WebKit::WebGPU::ImageDataLayout, WebKit::WebGPU::Extent3D>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_WriteTextureWithCopy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    WriteTextureWithCopy(const WebKit::WebGPU::ImageCopyTexture& destination, const Vector<uint8_t>& data, const WebKit::WebGPU::ImageDataLayout& imageDataLayout, const WebKit::WebGPU::Extent3D& size)
        : m_destination(destination)
        , m_data(data)
        , m_imageDataLayout(imageDataLayout)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destination;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageDataLayout;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyTexture& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint8_t>& m_data;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageDataLayout& m_imageDataLayout;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::Extent3D& m_size;
};

class CopyExternalImageToTexture {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ImageCopyExternalImage, WebKit::WebGPU::ImageCopyTextureTagged, WebKit::WebGPU::Extent3D>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_CopyExternalImageToTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyExternalImageToTexture(const WebKit::WebGPU::ImageCopyExternalImage& source, const WebKit::WebGPU::ImageCopyTextureTagged& destination, const WebKit::WebGPU::Extent3D& copySize)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyExternalImage& m_source;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ImageCopyTextureTagged& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::Extent3D& m_copySize;
};

class SetLabel {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteQueue_SetLabel; }
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

} // namespace RemoteQueue
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
