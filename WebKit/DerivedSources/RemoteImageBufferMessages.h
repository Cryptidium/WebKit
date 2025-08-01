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
#include <WebCore/DestinationColorSpace.h>
#include <WebCore/ShareableBitmapHandle.h>
#include <WebCore/SharedMemory.h>
#include <wtf/Forward.h>
#include <wtf/Ref.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
class DynamicContentScalingDisplayList;
class IntPoint;
class IntSize;
class PixelBufferSourceView;
enum class PreserveResolution : bool;
enum class AlphaPremultiplication : uint8_t;
struct PixelBufferFormat;
}

namespace Messages {
namespace RemoteImageBuffer {

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
    return IPC::ReceiverName::RemoteImageBuffer;
}

class GetPixelBuffer {
public:
    using Arguments = std::tuple<WebCore::PixelBufferFormat, WebCore::IntPoint, WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_GetPixelBuffer; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    GetPixelBuffer(const WebCore::PixelBufferFormat& outputFormat, const WebCore::IntPoint& srcPoint, const WebCore::IntSize& srcSize)
        : m_outputFormat(outputFormat)
        , m_srcPoint(srcPoint)
        , m_srcSize(srcSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_outputFormat;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcPoint;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PixelBufferFormat& m_outputFormat;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_srcPoint;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_srcSize;
};

class GetPixelBufferWithNewMemory {
public:
    using Arguments = std::tuple<WebCore::SharedMemory::Handle, WebCore::PixelBufferFormat, WebCore::IntPoint, WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_GetPixelBufferWithNewMemory; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    GetPixelBufferWithNewMemory(WebCore::SharedMemory::Handle&& handle, const WebCore::PixelBufferFormat& outputFormat, const WebCore::IntPoint& srcPoint, const WebCore::IntSize& srcSize)
        : m_handle(WTFMove(handle))
        , m_outputFormat(outputFormat)
        , m_srcPoint(srcPoint)
        , m_srcSize(srcSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handle);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_outputFormat;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcPoint;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcSize;
    }

private:
    WebCore::SharedMemory::Handle&& m_handle;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PixelBufferFormat& m_outputFormat;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_srcPoint;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_srcSize;
};

class PutPixelBuffer {
public:
    using Arguments = std::tuple<WebCore::PixelBufferSourceView, WebCore::IntPoint, WebCore::IntSize, WebCore::IntPoint, WebCore::AlphaPremultiplication>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_PutPixelBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    PutPixelBuffer(const WebCore::PixelBufferSourceView& pixelBuffer, const WebCore::IntPoint& srcPoint, const WebCore::IntSize& srcSize, const WebCore::IntPoint& destPoint, WebCore::AlphaPremultiplication destFormat)
        : m_pixelBuffer(pixelBuffer)
        , m_srcPoint(srcPoint)
        , m_srcSize(srcSize)
        , m_destPoint(destPoint)
        , m_destFormat(destFormat)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pixelBuffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcPoint;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcSize;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destPoint;
        encoder << m_destFormat;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PixelBufferSourceView& m_pixelBuffer;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_srcPoint;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_srcSize;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_destPoint;
    WebCore::AlphaPremultiplication m_destFormat;
};

class GetShareableBitmap {
public:
    using Arguments = std::tuple<WebCore::PreserveResolution>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_GetShareableBitmap; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&)>;
    explicit GetShareableBitmap(WebCore::PreserveResolution preserveResolution)
        : m_preserveResolution(preserveResolution)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_preserveResolution;
    }

private:
    WebCore::PreserveResolution m_preserveResolution;
};

class FilteredNativeImage {
public:
    using Arguments = std::tuple<Ref<WebCore::Filter>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_FilteredNativeImage; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&)>;
    explicit FilteredNativeImage(const Ref<WebCore::Filter>& filter)
        : m_filter(filter)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_filter;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::Filter>& m_filter;
};

class ConvertToLuminanceMask {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_ConvertToLuminanceMask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ConvertToLuminanceMask()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class TransformToColorSpace {
public:
    using Arguments = std::tuple<WebCore::DestinationColorSpace>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_TransformToColorSpace; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit TransformToColorSpace(const WebCore::DestinationColorSpace& colorSpace)
        : m_colorSpace(colorSpace)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_colorSpace;
    }

private:
    const WebCore::DestinationColorSpace& m_colorSpace;
};

class FlushContext {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_FlushContext; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FlushContext()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class FlushContextSync {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_FlushContextSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    FlushContextSync()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
class DynamicContentScalingDisplayList {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteImageBuffer_DynamicContentScalingDisplayList; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::DynamicContentScalingDisplayList>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::DynamicContentScalingDisplayList>&&)>;
    DynamicContentScalingDisplayList()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

} // namespace RemoteImageBuffer
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
