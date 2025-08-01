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

#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)

#include "ArgumentCoders.h"
#include "ArrayReferenceTuple.h"
#include "Connection.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "SharedVideoFrame.h"
#if USE(GRAPHICS_LAYER_WC)
#include "WCContentBufferIdentifier.h"
#endif
#include <WebCore/DestinationColorSpace.h>
#include <WebCore/GraphicsContextGL.h>
#include <WebCore/GraphicsTypesGL.h>
#include <WebCore/SharedMemory.h>
#include <span>
#include <wtf/Forward.h>
#include <wtf/MachSendRight.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class IntRect;
class IntSize;
struct RenderingResourceIdentifierType;
using RenderingResourceIdentifier = AtomicObjectIdentifier<RenderingResourceIdentifierType>;
enum class GraphicsContextGLSurfaceBuffer : bool;
enum class GraphicsContextGLSimulatedEventForTesting : uint8_t;
struct DMABufBufferAttributes;
struct GraphicsContextGLActiveInfo;
}

namespace WebKit {
struct RemoteVideoFrameProxyProperties;
}

namespace Messages {
namespace RemoteGraphicsContextGL {

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
    return IPC::ReceiverName::RemoteGraphicsContextGL;
}

class Reshape {
public:
    using Arguments = std::tuple<int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Reshape; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Reshape(int32_t width, int32_t height)
        : m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_width;
        encoder << m_height;
    }

private:
    int32_t m_width;
    int32_t m_height;
};

#if PLATFORM(COCOA)
class PrepareForDisplay {
public:
    using Arguments = std::tuple<IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PrepareForDisplay; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isReplyStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<MachSendRight>;
    using Reply = CompletionHandler<void(MachSendRight&&)>;
    explicit PrepareForDisplay(const IPC::Semaphore& finishedFence)
        : m_finishedFence(finishedFence)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_finishedFence;
    }

private:
    const IPC::Semaphore& m_finishedFence;
};
#endif

#if USE(GRAPHICS_LAYER_WC)
class PrepareForDisplay {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PrepareForDisplay; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::WCContentBufferIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::WCContentBufferIdentifier>&&)>;
    PrepareForDisplay()
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

#if USE(GBM)
class PrepareForDisplay {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PrepareForDisplay; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t, std::optional<WebCore::DMABufBufferAttributes>, UnixFileDescriptor>;
    using Reply = CompletionHandler<void(uint64_t, std::optional<WebCore::DMABufBufferAttributes>&&, UnixFileDescriptor&&)>;
    PrepareForDisplay()
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

#if !PLATFORM(COCOA) && !USE(GRAPHICS_LAYER_WC) && !USE(GBM)
class PrepareForDisplay {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PrepareForDisplay; }
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
    PrepareForDisplay()
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

class EnsureExtensionEnabled {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_EnsureExtensionEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit EnsureExtensionEnabled(const String& extension)
        : m_extension(extension)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_extension;
    }

private:
    const String& m_extension;
};

class GetErrors {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetErrors; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<GCGLErrorCodeSet>;
    using Reply = CompletionHandler<void(GCGLErrorCodeSet&&)>;
    GetErrors()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DrawSurfaceBufferToImageBuffer {
public:
    using Arguments = std::tuple<WebCore::GraphicsContextGLSurfaceBuffer, WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawSurfaceBufferToImageBuffer; }
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
    DrawSurfaceBufferToImageBuffer(WebCore::GraphicsContextGLSurfaceBuffer buffer, const WebCore::RenderingResourceIdentifier& imageBuffer)
        : m_buffer(buffer)
        , m_imageBuffer(imageBuffer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageBuffer;
    }

private:
    WebCore::GraphicsContextGLSurfaceBuffer m_buffer;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_imageBuffer;
};

#if ENABLE(MEDIA_STREAM) || ENABLE(WEB_CODECS)
class SurfaceBufferToVideoFrame {
public:
    using Arguments = std::tuple<WebCore::GraphicsContextGLSurfaceBuffer>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_SurfaceBufferToVideoFrame; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::RemoteVideoFrameProxyProperties>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::RemoteVideoFrameProxyProperties>&&)>;
    explicit SurfaceBufferToVideoFrame(WebCore::GraphicsContextGLSurfaceBuffer buffer)
        : m_buffer(buffer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buffer;
    }

private:
    WebCore::GraphicsContextGLSurfaceBuffer m_buffer;
};
#endif

#if ENABLE(VIDEO) && PLATFORM(COCOA)
class CopyTextureFromVideoFrame {
public:
    using Arguments = std::tuple<WebKit::SharedVideoFrame, PlatformGLObject, uint32_t, int32_t, uint32_t, uint32_t, uint32_t, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CopyTextureFromVideoFrame; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    CopyTextureFromVideoFrame(WebKit::SharedVideoFrame&& frame, const PlatformGLObject& texture, uint32_t target, int32_t level, uint32_t internalFormat, uint32_t format, uint32_t type, bool premultiplyAlpha, bool flipY)
        : m_frame(WTFMove(frame))
        , m_texture(texture)
        , m_target(target)
        , m_level(level)
        , m_internalFormat(internalFormat)
        , m_format(format)
        , m_type(type)
        , m_premultiplyAlpha(premultiplyAlpha)
        , m_flipY(flipY)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_frame);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_texture;
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalFormat;
        encoder << m_format;
        encoder << m_type;
        encoder << m_premultiplyAlpha;
        encoder << m_flipY;
    }

private:
    WebKit::SharedVideoFrame&& m_frame;
    SUPPRESS_FORWARD_DECL_MEMBER const PlatformGLObject& m_texture;
    uint32_t m_target;
    int32_t m_level;
    uint32_t m_internalFormat;
    uint32_t m_format;
    uint32_t m_type;
    bool m_premultiplyAlpha;
    bool m_flipY;
};
#endif

#if ENABLE(VIDEO) && PLATFORM(COCOA)
class SetSharedVideoFrameSemaphore {
public:
    using Arguments = std::tuple<IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_SetSharedVideoFrameSemaphore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    explicit SetSharedVideoFrameSemaphore(const IPC::Semaphore& semaphore)
        : m_semaphore(semaphore)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_semaphore;
    }

private:
    const IPC::Semaphore& m_semaphore;
};
#endif

#if ENABLE(VIDEO) && PLATFORM(COCOA)
class SetSharedVideoFrameMemory {
public:
    using Arguments = std::tuple<WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_SetSharedVideoFrameMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    explicit SetSharedVideoFrameMemory(WebCore::SharedMemory::Handle&& storageHandle)
        : m_storageHandle(WTFMove(storageHandle))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_storageHandle);
    }

private:
    WebCore::SharedMemory::Handle&& m_storageHandle;
};
#endif

class SimulateEventForTesting {
public:
    using Arguments = std::tuple<WebCore::GraphicsContextGLSimulatedEventForTesting>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_SimulateEventForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit SimulateEventForTesting(WebCore::GraphicsContextGLSimulatedEventForTesting event)
        : m_event(event)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_event;
    }

private:
    WebCore::GraphicsContextGLSimulatedEventForTesting m_event;
};

class GetBufferSubDataInline {
public:
    using Arguments = std::tuple<uint32_t, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetBufferSubDataInline; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const uint8_t>>;
    using Reply = CompletionHandler<void(std::span<const uint8_t>&&)>;
    GetBufferSubDataInline(uint32_t target, uint64_t offset, uint64_t dataSize)
        : m_target(target)
        , m_offset(offset)
        , m_dataSize(dataSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_offset;
        encoder << m_dataSize;
    }

private:
    uint32_t m_target;
    uint64_t m_offset;
    uint64_t m_dataSize;
};

class GetBufferSubDataSharedMemory {
public:
    using Arguments = std::tuple<uint32_t, uint64_t, uint64_t, WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetBufferSubDataSharedMemory; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    GetBufferSubDataSharedMemory(uint32_t target, uint64_t offset, uint64_t dataSize, WebCore::SharedMemory::Handle&& handle)
        : m_target(target)
        , m_offset(offset)
        , m_dataSize(dataSize)
        , m_handle(WTFMove(handle))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_offset;
        encoder << m_dataSize;
        encoder << WTFMove(m_handle);
    }

private:
    uint32_t m_target;
    uint64_t m_offset;
    uint64_t m_dataSize;
    WebCore::SharedMemory::Handle&& m_handle;
};

class ReadPixelsInline {
public:
    using Arguments = std::tuple<WebCore::IntRect, uint32_t, uint32_t, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ReadPixelsInline; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::IntSize>, std::span<const uint8_t>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::IntSize>&&, std::span<const uint8_t>&&)>;
    ReadPixelsInline(const WebCore::IntRect& rect, uint32_t format, uint32_t type, bool packReverseRowOrder)
        : m_rect(rect)
        , m_format(format)
        , m_type(type)
        , m_packReverseRowOrder(packReverseRowOrder)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        encoder << m_format;
        encoder << m_type;
        encoder << m_packReverseRowOrder;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_rect;
    uint32_t m_format;
    uint32_t m_type;
    bool m_packReverseRowOrder;
};

class ReadPixelsSharedMemory {
public:
    using Arguments = std::tuple<WebCore::IntRect, uint32_t, uint32_t, bool, WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ReadPixelsSharedMemory; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::IntSize>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::IntSize>&&)>;
    ReadPixelsSharedMemory(const WebCore::IntRect& rect, uint32_t format, uint32_t type, bool packReverseRowOrder, WebCore::SharedMemory::Handle&& handle)
        : m_rect(rect)
        , m_format(format)
        , m_type(type)
        , m_packReverseRowOrder(packReverseRowOrder)
        , m_handle(WTFMove(handle))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        encoder << m_format;
        encoder << m_type;
        encoder << m_packReverseRowOrder;
        encoder << WTFMove(m_handle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_rect;
    uint32_t m_format;
    uint32_t m_type;
    bool m_packReverseRowOrder;
    WebCore::SharedMemory::Handle&& m_handle;
};

class MultiDrawArraysANGLE {
public:
    using Arguments = std::tuple<uint32_t, IPC::ArrayReferenceTuple<int32_t, int32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_MultiDrawArraysANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MultiDrawArraysANGLE(uint32_t mode, const IPC::ArrayReferenceTuple<int32_t, int32_t>& firstsAndCounts)
        : m_mode(mode)
        , m_firstsAndCounts(firstsAndCounts)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstsAndCounts;
    }

private:
    uint32_t m_mode;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::ArrayReferenceTuple<int32_t, int32_t>& m_firstsAndCounts;
};

class MultiDrawArraysInstancedANGLE {
public:
    using Arguments = std::tuple<uint32_t, IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_MultiDrawArraysInstancedANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MultiDrawArraysInstancedANGLE(uint32_t mode, const IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t>& firstsCountsAandInstanceCounts)
        : m_mode(mode)
        , m_firstsCountsAandInstanceCounts(firstsCountsAandInstanceCounts)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstsCountsAandInstanceCounts;
    }

private:
    uint32_t m_mode;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t>& m_firstsCountsAandInstanceCounts;
};

class MultiDrawElementsANGLE {
public:
    using Arguments = std::tuple<uint32_t, IPC::ArrayReferenceTuple<int32_t, int32_t>, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_MultiDrawElementsANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MultiDrawElementsANGLE(uint32_t mode, const IPC::ArrayReferenceTuple<int32_t, int32_t>& countsAndOffsets, uint32_t type)
        : m_mode(mode)
        , m_countsAndOffsets(countsAndOffsets)
        , m_type(type)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_countsAndOffsets;
        encoder << m_type;
    }

private:
    uint32_t m_mode;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::ArrayReferenceTuple<int32_t, int32_t>& m_countsAndOffsets;
    uint32_t m_type;
};

class MultiDrawElementsInstancedANGLE {
public:
    using Arguments = std::tuple<uint32_t, IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t>, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_MultiDrawElementsInstancedANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MultiDrawElementsInstancedANGLE(uint32_t mode, const IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t>& countsOffsetsAndInstanceCounts, uint32_t type)
        : m_mode(mode)
        , m_countsOffsetsAndInstanceCounts(countsOffsetsAndInstanceCounts)
        , m_type(type)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_countsOffsetsAndInstanceCounts;
        encoder << m_type;
    }

private:
    uint32_t m_mode;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t>& m_countsOffsetsAndInstanceCounts;
    uint32_t m_type;
};

class MultiDrawArraysInstancedBaseInstanceANGLE {
public:
    using Arguments = std::tuple<uint32_t, IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t, uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_MultiDrawArraysInstancedBaseInstanceANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MultiDrawArraysInstancedBaseInstanceANGLE(uint32_t mode, const IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t, uint32_t>& firstsCountsInstanceCountsAndBaseInstances)
        : m_mode(mode)
        , m_firstsCountsInstanceCountsAndBaseInstances(firstsCountsInstanceCountsAndBaseInstances)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstsCountsInstanceCountsAndBaseInstances;
    }

private:
    uint32_t m_mode;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t, uint32_t>& m_firstsCountsInstanceCountsAndBaseInstances;
};

class MultiDrawElementsInstancedBaseVertexBaseInstanceANGLE {
public:
    using Arguments = std::tuple<uint32_t, IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t, int32_t, uint32_t>, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_MultiDrawElementsInstancedBaseVertexBaseInstanceANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MultiDrawElementsInstancedBaseVertexBaseInstanceANGLE(uint32_t mode, const IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t, int32_t, uint32_t>& countsOffsetsInstanceCountsBaseVerticesAndBaseInstances, uint32_t type)
        : m_mode(mode)
        , m_countsOffsetsInstanceCountsBaseVerticesAndBaseInstances(countsOffsetsInstanceCountsBaseVerticesAndBaseInstances)
        , m_type(type)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_countsOffsetsInstanceCountsBaseVerticesAndBaseInstances;
        encoder << m_type;
    }

private:
    uint32_t m_mode;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::ArrayReferenceTuple<int32_t, int32_t, int32_t, int32_t, uint32_t>& m_countsOffsetsInstanceCountsBaseVerticesAndBaseInstances;
    uint32_t m_type;
};

class ActiveTexture {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ActiveTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ActiveTexture(uint32_t texture)
        : m_texture(texture)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_texture;
    }

private:
    uint32_t m_texture;
};

class AttachShader {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_AttachShader; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    AttachShader(uint32_t program, uint32_t shader)
        : m_program(program)
        , m_shader(shader)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_shader;
    }

private:
    uint32_t m_program;
    uint32_t m_shader;
};

class BindAttribLocation {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindAttribLocation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindAttribLocation(uint32_t arg0, uint32_t index, const String& name)
        : m_arg0(arg0)
        , m_index(index)
        , m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_index;
        encoder << m_name;
    }

private:
    uint32_t m_arg0;
    uint32_t m_index;
    const String& m_name;
};

class BindBuffer {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindBuffer(uint32_t target, uint32_t arg1)
        : m_target(target)
        , m_arg1(arg1)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_arg1;
    }

private:
    uint32_t m_target;
    uint32_t m_arg1;
};

class BindFramebuffer {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindFramebuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindFramebuffer(uint32_t target, uint32_t arg1)
        : m_target(target)
        , m_arg1(arg1)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_arg1;
    }

private:
    uint32_t m_target;
    uint32_t m_arg1;
};

class BindRenderbuffer {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindRenderbuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindRenderbuffer(uint32_t target, uint32_t arg1)
        : m_target(target)
        , m_arg1(arg1)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_arg1;
    }

private:
    uint32_t m_target;
    uint32_t m_arg1;
};

class BindTexture {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindTexture(uint32_t target, uint32_t arg1)
        : m_target(target)
        , m_arg1(arg1)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_arg1;
    }

private:
    uint32_t m_target;
    uint32_t m_arg1;
};

class BlendColor {
public:
    using Arguments = std::tuple<float, float, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlendColor(float red, float green, float blue, float alpha)
        : m_red(red)
        , m_green(green)
        , m_blue(blue)
        , m_alpha(alpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_red;
        encoder << m_green;
        encoder << m_blue;
        encoder << m_alpha;
    }

private:
    float m_red;
    float m_green;
    float m_blue;
    float m_alpha;
};

class BlendEquation {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendEquation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit BlendEquation(uint32_t mode)
        : m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
    }

private:
    uint32_t m_mode;
};

class BlendEquationSeparate {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendEquationSeparate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlendEquationSeparate(uint32_t modeRGB, uint32_t modeAlpha)
        : m_modeRGB(modeRGB)
        , m_modeAlpha(modeAlpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_modeRGB;
        encoder << m_modeAlpha;
    }

private:
    uint32_t m_modeRGB;
    uint32_t m_modeAlpha;
};

class BlendFunc {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendFunc; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlendFunc(uint32_t sfactor, uint32_t dfactor)
        : m_sfactor(sfactor)
        , m_dfactor(dfactor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sfactor;
        encoder << m_dfactor;
    }

private:
    uint32_t m_sfactor;
    uint32_t m_dfactor;
};

class BlendFuncSeparate {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendFuncSeparate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlendFuncSeparate(uint32_t srcRGB, uint32_t dstRGB, uint32_t srcAlpha, uint32_t dstAlpha)
        : m_srcRGB(srcRGB)
        , m_dstRGB(dstRGB)
        , m_srcAlpha(srcAlpha)
        , m_dstAlpha(dstAlpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_srcRGB;
        encoder << m_dstRGB;
        encoder << m_srcAlpha;
        encoder << m_dstAlpha;
    }

private:
    uint32_t m_srcRGB;
    uint32_t m_dstRGB;
    uint32_t m_srcAlpha;
    uint32_t m_dstAlpha;
};

class CheckFramebufferStatus {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CheckFramebufferStatus; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    explicit CheckFramebufferStatus(uint32_t target)
        : m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
    }

private:
    uint32_t m_target;
};

class Clear {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Clear; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit Clear(uint32_t mask)
        : m_mask(mask)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mask;
    }

private:
    uint32_t m_mask;
};

class ClearColor {
public:
    using Arguments = std::tuple<float, float, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClearColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClearColor(float red, float green, float blue, float alpha)
        : m_red(red)
        , m_green(green)
        , m_blue(blue)
        , m_alpha(alpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_red;
        encoder << m_green;
        encoder << m_blue;
        encoder << m_alpha;
    }

private:
    float m_red;
    float m_green;
    float m_blue;
    float m_alpha;
};

class ClearDepth {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClearDepth; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ClearDepth(float depth)
        : m_depth(depth)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_depth;
    }

private:
    float m_depth;
};

class ClearStencil {
public:
    using Arguments = std::tuple<int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClearStencil; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ClearStencil(int32_t s)
        : m_s(s)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_s;
    }

private:
    int32_t m_s;
};

class ColorMask {
public:
    using Arguments = std::tuple<bool, bool, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ColorMask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ColorMask(bool red, bool green, bool blue, bool alpha)
        : m_red(red)
        , m_green(green)
        , m_blue(blue)
        , m_alpha(alpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_red;
        encoder << m_green;
        encoder << m_blue;
        encoder << m_alpha;
    }

private:
    bool m_red;
    bool m_green;
    bool m_blue;
    bool m_alpha;
};

class CompileShader {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompileShader; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CompileShader(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class CopyTexImage2D {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CopyTexImage2D; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyTexImage2D(uint32_t target, int32_t level, uint32_t internalformat, int32_t x, int32_t y, int32_t width, int32_t height, int32_t border)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_x(x)
        , m_y(y)
        , m_width(width)
        , m_height(height)
        , m_border(border)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_x;
        encoder << m_y;
        encoder << m_width;
        encoder << m_height;
        encoder << m_border;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    uint32_t m_internalformat;
    int32_t m_x;
    int32_t m_y;
    int32_t m_width;
    int32_t m_height;
    int32_t m_border;
};

class CopyTexSubImage2D {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CopyTexSubImage2D; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyTexSubImage2D(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t x, int32_t y, int32_t width, int32_t height)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_x(x)
        , m_y(y)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_x;
        encoder << m_y;
        encoder << m_width;
        encoder << m_height;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_x;
    int32_t m_y;
    int32_t m_width;
    int32_t m_height;
};

class CreateBuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateBuffer(uint32_t buffer)
        : m_buffer(buffer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buffer;
    }

private:
    uint32_t m_buffer;
};

class CreateFramebuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateFramebuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateFramebuffer(uint32_t framebuffer)
        : m_framebuffer(framebuffer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_framebuffer;
    }

private:
    uint32_t m_framebuffer;
};

class CreateProgram {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateProgram; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateProgram(uint32_t program)
        : m_program(program)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
    }

private:
    uint32_t m_program;
};

class CreateRenderbuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateRenderbuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateRenderbuffer(uint32_t renderbuffer)
        : m_renderbuffer(renderbuffer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_renderbuffer;
    }

private:
    uint32_t m_renderbuffer;
};

class CreateShader {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateShader; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateShader(uint32_t shader, uint32_t arg0)
        : m_shader(shader)
        , m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shader;
        encoder << m_arg0;
    }

private:
    uint32_t m_shader;
    uint32_t m_arg0;
};

class CreateTexture {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateTexture(uint32_t texture)
        : m_texture(texture)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_texture;
    }

private:
    uint32_t m_texture;
};

class CullFace {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CullFace; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CullFace(uint32_t mode)
        : m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
    }

private:
    uint32_t m_mode;
};

class DeleteBuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteBuffer(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class DeleteFramebuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteFramebuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteFramebuffer(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class DeleteProgram {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteProgram; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteProgram(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class DeleteRenderbuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteRenderbuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteRenderbuffer(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class DeleteShader {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteShader; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteShader(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class DeleteTexture {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteTexture(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class DepthFunc {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DepthFunc; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DepthFunc(uint32_t func)
        : m_func(func)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_func;
    }

private:
    uint32_t m_func;
};

class DepthMask {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DepthMask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DepthMask(bool flag)
        : m_flag(flag)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_flag;
    }

private:
    bool m_flag;
};

class DepthRange {
public:
    using Arguments = std::tuple<float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DepthRange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DepthRange(float zNear, float zFar)
        : m_zNear(zNear)
        , m_zFar(zFar)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_zNear;
        encoder << m_zFar;
    }

private:
    float m_zNear;
    float m_zFar;
};

class DetachShader {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DetachShader; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DetachShader(uint32_t arg0, uint32_t arg1)
        : m_arg0(arg0)
        , m_arg1(arg1)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_arg1;
    }

private:
    uint32_t m_arg0;
    uint32_t m_arg1;
};

class Disable {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Disable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit Disable(uint32_t cap)
        : m_cap(cap)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cap;
    }

private:
    uint32_t m_cap;
};

class DisableVertexAttribArray {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DisableVertexAttribArray; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DisableVertexAttribArray(uint32_t index)
        : m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
    }

private:
    uint32_t m_index;
};

class DrawArrays {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawArrays; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawArrays(uint32_t mode, int32_t first, int32_t count)
        : m_mode(mode)
        , m_first(first)
        , m_count(count)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        encoder << m_first;
        encoder << m_count;
    }

private:
    uint32_t m_mode;
    int32_t m_first;
    int32_t m_count;
};

class DrawElements {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawElements; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawElements(uint32_t mode, int32_t count, uint32_t type, uint64_t offset)
        : m_mode(mode)
        , m_count(count)
        , m_type(type)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        encoder << m_count;
        encoder << m_type;
        encoder << m_offset;
    }

private:
    uint32_t m_mode;
    int32_t m_count;
    uint32_t m_type;
    uint64_t m_offset;
};

class Enable {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Enable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit Enable(uint32_t cap)
        : m_cap(cap)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cap;
    }

private:
    uint32_t m_cap;
};

class EnableVertexAttribArray {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_EnableVertexAttribArray; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit EnableVertexAttribArray(uint32_t index)
        : m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
    }

private:
    uint32_t m_index;
};

class Finish {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Finish; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Finish()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Flush {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Flush; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Flush()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class FramebufferRenderbuffer {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_FramebufferRenderbuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FramebufferRenderbuffer(uint32_t target, uint32_t attachment, uint32_t renderbuffertarget, uint32_t arg3)
        : m_target(target)
        , m_attachment(attachment)
        , m_renderbuffertarget(renderbuffertarget)
        , m_arg3(arg3)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_attachment;
        encoder << m_renderbuffertarget;
        encoder << m_arg3;
    }

private:
    uint32_t m_target;
    uint32_t m_attachment;
    uint32_t m_renderbuffertarget;
    uint32_t m_arg3;
};

class FramebufferTexture2D {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_FramebufferTexture2D; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FramebufferTexture2D(uint32_t target, uint32_t attachment, uint32_t textarget, uint32_t arg3, int32_t level)
        : m_target(target)
        , m_attachment(attachment)
        , m_textarget(textarget)
        , m_arg3(arg3)
        , m_level(level)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_attachment;
        encoder << m_textarget;
        encoder << m_arg3;
        encoder << m_level;
    }

private:
    uint32_t m_target;
    uint32_t m_attachment;
    uint32_t m_textarget;
    uint32_t m_arg3;
    int32_t m_level;
};

class FrontFace {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_FrontFace; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FrontFace(uint32_t mode)
        : m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
    }

private:
    uint32_t m_mode;
};

class GenerateMipmap {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GenerateMipmap; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit GenerateMipmap(uint32_t target)
        : m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
    }

private:
    uint32_t m_target;
};

class GetActiveAttrib {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetActiveAttrib; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, WebCore::GraphicsContextGLActiveInfo>;
    using Reply = CompletionHandler<void(bool, WebCore::GraphicsContextGLActiveInfo&&)>;
    GetActiveAttrib(uint32_t program, uint32_t index)
        : m_program(program)
        , m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_index;
    }

private:
    uint32_t m_program;
    uint32_t m_index;
};

class GetActiveUniform {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetActiveUniform; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, WebCore::GraphicsContextGLActiveInfo>;
    using Reply = CompletionHandler<void(bool, WebCore::GraphicsContextGLActiveInfo&&)>;
    GetActiveUniform(uint32_t program, uint32_t index)
        : m_program(program)
        , m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_index;
    }

private:
    uint32_t m_program;
    uint32_t m_index;
};

class GetAttribLocation {
public:
    using Arguments = std::tuple<uint32_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetAttribLocation; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetAttribLocation(uint32_t arg0, const String& name)
        : m_arg0(arg0)
        , m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_name;
    }

private:
    uint32_t m_arg0;
    const String& m_name;
};

class GetBufferParameteri {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetBufferParameteri; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetBufferParameteri(uint32_t target, uint32_t pname)
        : m_target(target)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_pname;
    }

private:
    uint32_t m_target;
    uint32_t m_pname;
};

class GetString {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetString; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    explicit GetString(uint32_t name)
        : m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
    }

private:
    uint32_t m_name;
};

class GetFloatv {
public:
    using Arguments = std::tuple<uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetFloatv; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const float>>;
    using Reply = CompletionHandler<void(std::span<const float>&&)>;
    GetFloatv(uint32_t pname, uint64_t valueSize)
        : m_pname(pname)
        , m_valueSize(valueSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pname;
        encoder << m_valueSize;
    }

private:
    uint32_t m_pname;
    uint64_t m_valueSize;
};

class GetIntegerv {
public:
    using Arguments = std::tuple<uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetIntegerv; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const int32_t>>;
    using Reply = CompletionHandler<void(std::span<const int32_t>&&)>;
    GetIntegerv(uint32_t pname, uint64_t valueSize)
        : m_pname(pname)
        , m_valueSize(valueSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pname;
        encoder << m_valueSize;
    }

private:
    uint32_t m_pname;
    uint64_t m_valueSize;
};

class GetIntegeri_v {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetIntegeri_v; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const int32_t, 4>>;
    using Reply = CompletionHandler<void(std::span<const int32_t, 4>&&)>;
    GetIntegeri_v(uint32_t pname, uint32_t index)
        : m_pname(pname)
        , m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pname;
        encoder << m_index;
    }

private:
    uint32_t m_pname;
    uint32_t m_index;
};

class GetInteger64 {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetInteger64; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    explicit GetInteger64(uint32_t pname)
        : m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pname;
    }

private:
    uint32_t m_pname;
};

class GetInteger64i {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetInteger64i; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    GetInteger64i(uint32_t pname, uint32_t index)
        : m_pname(pname)
        , m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pname;
        encoder << m_index;
    }

private:
    uint32_t m_pname;
    uint32_t m_index;
};

class GetProgrami {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetProgrami; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetProgrami(uint32_t program, uint32_t pname)
        : m_program(program)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_pname;
    }

private:
    uint32_t m_program;
    uint32_t m_pname;
};

class GetBooleanv {
public:
    using Arguments = std::tuple<uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetBooleanv; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const bool>>;
    using Reply = CompletionHandler<void(std::span<const bool>&&)>;
    GetBooleanv(uint32_t pname, uint64_t valueSize)
        : m_pname(pname)
        , m_valueSize(valueSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pname;
        encoder << m_valueSize;
    }

private:
    uint32_t m_pname;
    uint64_t m_valueSize;
};

class GetFramebufferAttachmentParameteri {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetFramebufferAttachmentParameteri; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetFramebufferAttachmentParameteri(uint32_t target, uint32_t attachment, uint32_t pname)
        : m_target(target)
        , m_attachment(attachment)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_attachment;
        encoder << m_pname;
    }

private:
    uint32_t m_target;
    uint32_t m_attachment;
    uint32_t m_pname;
};

class GetProgramInfoLog {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetProgramInfoLog; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    explicit GetProgramInfoLog(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class GetRenderbufferParameteri {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetRenderbufferParameteri; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetRenderbufferParameteri(uint32_t target, uint32_t pname)
        : m_target(target)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_pname;
    }

private:
    uint32_t m_target;
    uint32_t m_pname;
};

class GetShaderi {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetShaderi; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetShaderi(uint32_t arg0, uint32_t pname)
        : m_arg0(arg0)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_pname;
    }

private:
    uint32_t m_arg0;
    uint32_t m_pname;
};

class GetShaderInfoLog {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetShaderInfoLog; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    explicit GetShaderInfoLog(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class GetShaderPrecisionFormat {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetShaderPrecisionFormat; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const int32_t, 2>, GCGLint>;
    using Reply = CompletionHandler<void(std::span<const int32_t, 2>&&, GCGLint&&)>;
    GetShaderPrecisionFormat(uint32_t shaderType, uint32_t precisionType)
        : m_shaderType(shaderType)
        , m_precisionType(precisionType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shaderType;
        encoder << m_precisionType;
    }

private:
    uint32_t m_shaderType;
    uint32_t m_precisionType;
};

class GetShaderSource {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetShaderSource; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    explicit GetShaderSource(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class GetTexParameterf {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetTexParameterf; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<float>;
    using Reply = CompletionHandler<void(float)>;
    GetTexParameterf(uint32_t target, uint32_t pname)
        : m_target(target)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_pname;
    }

private:
    uint32_t m_target;
    uint32_t m_pname;
};

class GetTexParameteri {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetTexParameteri; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetTexParameteri(uint32_t target, uint32_t pname)
        : m_target(target)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_pname;
    }

private:
    uint32_t m_target;
    uint32_t m_pname;
};

class GetUniformfv {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetUniformfv; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const float>>;
    using Reply = CompletionHandler<void(std::span<const float>&&)>;
    GetUniformfv(uint32_t program, int32_t location, uint64_t valueSize)
        : m_program(program)
        , m_location(location)
        , m_valueSize(valueSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_location;
        encoder << m_valueSize;
    }

private:
    uint32_t m_program;
    int32_t m_location;
    uint64_t m_valueSize;
};

class GetUniformiv {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetUniformiv; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const int32_t>>;
    using Reply = CompletionHandler<void(std::span<const int32_t>&&)>;
    GetUniformiv(uint32_t program, int32_t location, uint64_t valueSize)
        : m_program(program)
        , m_location(location)
        , m_valueSize(valueSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_location;
        encoder << m_valueSize;
    }

private:
    uint32_t m_program;
    int32_t m_location;
    uint64_t m_valueSize;
};

class GetUniformuiv {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetUniformuiv; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const uint32_t>>;
    using Reply = CompletionHandler<void(std::span<const uint32_t>&&)>;
    GetUniformuiv(uint32_t program, int32_t location, uint64_t valueSize)
        : m_program(program)
        , m_location(location)
        , m_valueSize(valueSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_location;
        encoder << m_valueSize;
    }

private:
    uint32_t m_program;
    int32_t m_location;
    uint64_t m_valueSize;
};

class GetUniformLocation {
public:
    using Arguments = std::tuple<uint32_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetUniformLocation; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetUniformLocation(uint32_t arg0, const String& name)
        : m_arg0(arg0)
        , m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_name;
    }

private:
    uint32_t m_arg0;
    const String& m_name;
};

class GetVertexAttribOffset {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetVertexAttribOffset; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    GetVertexAttribOffset(uint32_t index, uint32_t pname)
        : m_index(index)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_pname;
    }

private:
    uint32_t m_index;
    uint32_t m_pname;
};

class Hint {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Hint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Hint(uint32_t target, uint32_t mode)
        : m_target(target)
        , m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_mode;
    }

private:
    uint32_t m_target;
    uint32_t m_mode;
};

class IsBuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsBuffer; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsBuffer(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class IsEnabled {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsEnabled; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsEnabled(uint32_t cap)
        : m_cap(cap)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cap;
    }

private:
    uint32_t m_cap;
};

class IsFramebuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsFramebuffer; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsFramebuffer(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class IsProgram {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsProgram; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsProgram(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class IsRenderbuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsRenderbuffer; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsRenderbuffer(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class IsShader {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsShader; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsShader(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class IsTexture {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsTexture; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsTexture(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class LineWidth {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_LineWidth; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit LineWidth(float arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    float m_arg0;
};

class LinkProgram {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_LinkProgram; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit LinkProgram(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class PixelStorei {
public:
    using Arguments = std::tuple<uint32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PixelStorei; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    PixelStorei(uint32_t pname, int32_t param)
        : m_pname(pname)
        , m_param(param)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pname;
        encoder << m_param;
    }

private:
    uint32_t m_pname;
    int32_t m_param;
};

class PolygonOffset {
public:
    using Arguments = std::tuple<float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PolygonOffset; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    PolygonOffset(float factor, float units)
        : m_factor(factor)
        , m_units(units)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_factor;
        encoder << m_units;
    }

private:
    float m_factor;
    float m_units;
};

class RenderbufferStorage {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_RenderbufferStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    RenderbufferStorage(uint32_t target, uint32_t internalformat, int32_t width, int32_t height)
        : m_target(target)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
    }

private:
    uint32_t m_target;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
};

class SampleCoverage {
public:
    using Arguments = std::tuple<float, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_SampleCoverage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    SampleCoverage(float value, bool invert)
        : m_value(value)
        , m_invert(invert)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
        encoder << m_invert;
    }

private:
    float m_value;
    bool m_invert;
};

class Scissor {
public:
    using Arguments = std::tuple<int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Scissor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Scissor(int32_t x, int32_t y, int32_t width, int32_t height)
        : m_x(x)
        , m_y(y)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_x;
        encoder << m_y;
        encoder << m_width;
        encoder << m_height;
    }

private:
    int32_t m_x;
    int32_t m_y;
    int32_t m_width;
    int32_t m_height;
};

class ShaderSource {
public:
    using Arguments = std::tuple<uint32_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ShaderSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ShaderSource(uint32_t arg0, const String& arg1)
        : m_arg0(arg0)
        , m_arg1(arg1)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_arg1;
    }

private:
    uint32_t m_arg0;
    const String& m_arg1;
};

class StencilFunc {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_StencilFunc; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    StencilFunc(uint32_t func, int32_t ref, uint32_t mask)
        : m_func(func)
        , m_ref(ref)
        , m_mask(mask)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_func;
        encoder << m_ref;
        encoder << m_mask;
    }

private:
    uint32_t m_func;
    int32_t m_ref;
    uint32_t m_mask;
};

class StencilFuncSeparate {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, int32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_StencilFuncSeparate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    StencilFuncSeparate(uint32_t face, uint32_t func, int32_t ref, uint32_t mask)
        : m_face(face)
        , m_func(func)
        , m_ref(ref)
        , m_mask(mask)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_face;
        encoder << m_func;
        encoder << m_ref;
        encoder << m_mask;
    }

private:
    uint32_t m_face;
    uint32_t m_func;
    int32_t m_ref;
    uint32_t m_mask;
};

class StencilMask {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_StencilMask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit StencilMask(uint32_t mask)
        : m_mask(mask)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mask;
    }

private:
    uint32_t m_mask;
};

class StencilMaskSeparate {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_StencilMaskSeparate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    StencilMaskSeparate(uint32_t face, uint32_t mask)
        : m_face(face)
        , m_mask(mask)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_face;
        encoder << m_mask;
    }

private:
    uint32_t m_face;
    uint32_t m_mask;
};

class StencilOp {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_StencilOp; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    StencilOp(uint32_t fail, uint32_t zfail, uint32_t zpass)
        : m_fail(fail)
        , m_zfail(zfail)
        , m_zpass(zpass)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_fail;
        encoder << m_zfail;
        encoder << m_zpass;
    }

private:
    uint32_t m_fail;
    uint32_t m_zfail;
    uint32_t m_zpass;
};

class StencilOpSeparate {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_StencilOpSeparate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    StencilOpSeparate(uint32_t face, uint32_t fail, uint32_t zfail, uint32_t zpass)
        : m_face(face)
        , m_fail(fail)
        , m_zfail(zfail)
        , m_zpass(zpass)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_face;
        encoder << m_fail;
        encoder << m_zfail;
        encoder << m_zpass;
    }

private:
    uint32_t m_face;
    uint32_t m_fail;
    uint32_t m_zfail;
    uint32_t m_zpass;
};

class TexParameterf {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexParameterf; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexParameterf(uint32_t target, uint32_t pname, float param)
        : m_target(target)
        , m_pname(pname)
        , m_param(param)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_pname;
        encoder << m_param;
    }

private:
    uint32_t m_target;
    uint32_t m_pname;
    float m_param;
};

class TexParameteri {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexParameteri; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexParameteri(uint32_t target, uint32_t pname, int32_t param)
        : m_target(target)
        , m_pname(pname)
        , m_param(param)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_pname;
        encoder << m_param;
    }

private:
    uint32_t m_target;
    uint32_t m_pname;
    int32_t m_param;
};

class Uniform1f {
public:
    using Arguments = std::tuple<int32_t, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform1f; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform1f(int32_t location, float x)
        : m_location(location)
        , m_x(x)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_x;
    }

private:
    int32_t m_location;
    float m_x;
};

class Uniform1fv {
public:
    using Arguments = std::tuple<int32_t, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform1fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform1fv(int32_t location, const std::span<const float>& v)
        : m_location(location)
        , m_v(v)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_v;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_v;
};

class Uniform1i {
public:
    using Arguments = std::tuple<int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform1i; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform1i(int32_t location, int32_t x)
        : m_location(location)
        , m_x(x)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_x;
    }

private:
    int32_t m_location;
    int32_t m_x;
};

class Uniform1iv {
public:
    using Arguments = std::tuple<int32_t, std::span<const int32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform1iv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform1iv(int32_t location, const std::span<const int32_t>& v)
        : m_location(location)
        , m_v(v)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_v;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const int32_t>& m_v;
};

class Uniform2f {
public:
    using Arguments = std::tuple<int32_t, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform2f; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform2f(int32_t location, float x, float y)
        : m_location(location)
        , m_x(x)
        , m_y(y)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_x;
        encoder << m_y;
    }

private:
    int32_t m_location;
    float m_x;
    float m_y;
};

class Uniform2fv {
public:
    using Arguments = std::tuple<int32_t, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform2fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform2fv(int32_t location, const std::span<const float>& v)
        : m_location(location)
        , m_v(v)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_v;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_v;
};

class Uniform2i {
public:
    using Arguments = std::tuple<int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform2i; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform2i(int32_t location, int32_t x, int32_t y)
        : m_location(location)
        , m_x(x)
        , m_y(y)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_x;
        encoder << m_y;
    }

private:
    int32_t m_location;
    int32_t m_x;
    int32_t m_y;
};

class Uniform2iv {
public:
    using Arguments = std::tuple<int32_t, std::span<const int32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform2iv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform2iv(int32_t location, const std::span<const int32_t>& v)
        : m_location(location)
        , m_v(v)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_v;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const int32_t>& m_v;
};

class Uniform3f {
public:
    using Arguments = std::tuple<int32_t, float, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform3f; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform3f(int32_t location, float x, float y, float z)
        : m_location(location)
        , m_x(x)
        , m_y(y)
        , m_z(z)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_x;
        encoder << m_y;
        encoder << m_z;
    }

private:
    int32_t m_location;
    float m_x;
    float m_y;
    float m_z;
};

class Uniform3fv {
public:
    using Arguments = std::tuple<int32_t, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform3fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform3fv(int32_t location, const std::span<const float>& v)
        : m_location(location)
        , m_v(v)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_v;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_v;
};

class Uniform3i {
public:
    using Arguments = std::tuple<int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform3i; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform3i(int32_t location, int32_t x, int32_t y, int32_t z)
        : m_location(location)
        , m_x(x)
        , m_y(y)
        , m_z(z)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_x;
        encoder << m_y;
        encoder << m_z;
    }

private:
    int32_t m_location;
    int32_t m_x;
    int32_t m_y;
    int32_t m_z;
};

class Uniform3iv {
public:
    using Arguments = std::tuple<int32_t, std::span<const int32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform3iv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform3iv(int32_t location, const std::span<const int32_t>& v)
        : m_location(location)
        , m_v(v)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_v;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const int32_t>& m_v;
};

class Uniform4f {
public:
    using Arguments = std::tuple<int32_t, float, float, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform4f; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform4f(int32_t location, float x, float y, float z, float w)
        : m_location(location)
        , m_x(x)
        , m_y(y)
        , m_z(z)
        , m_w(w)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_x;
        encoder << m_y;
        encoder << m_z;
        encoder << m_w;
    }

private:
    int32_t m_location;
    float m_x;
    float m_y;
    float m_z;
    float m_w;
};

class Uniform4fv {
public:
    using Arguments = std::tuple<int32_t, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform4fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform4fv(int32_t location, const std::span<const float>& v)
        : m_location(location)
        , m_v(v)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_v;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_v;
};

class Uniform4i {
public:
    using Arguments = std::tuple<int32_t, int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform4i; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform4i(int32_t location, int32_t x, int32_t y, int32_t z, int32_t w)
        : m_location(location)
        , m_x(x)
        , m_y(y)
        , m_z(z)
        , m_w(w)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_x;
        encoder << m_y;
        encoder << m_z;
        encoder << m_w;
    }

private:
    int32_t m_location;
    int32_t m_x;
    int32_t m_y;
    int32_t m_z;
    int32_t m_w;
};

class Uniform4iv {
public:
    using Arguments = std::tuple<int32_t, std::span<const int32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform4iv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform4iv(int32_t location, const std::span<const int32_t>& v)
        : m_location(location)
        , m_v(v)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_v;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const int32_t>& m_v;
};

class UniformMatrix2fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix2fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix2fv(int32_t location, bool transpose, const std::span<const float>& value)
        : m_location(location)
        , m_transpose(transpose)
        , m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_value;
};

class UniformMatrix3fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix3fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix3fv(int32_t location, bool transpose, const std::span<const float>& value)
        : m_location(location)
        , m_transpose(transpose)
        , m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_value;
};

class UniformMatrix4fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix4fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix4fv(int32_t location, bool transpose, const std::span<const float>& value)
        : m_location(location)
        , m_transpose(transpose)
        , m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_value;
};

class UseProgram {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UseProgram; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit UseProgram(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class ValidateProgram {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ValidateProgram; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ValidateProgram(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class VertexAttrib1f {
public:
    using Arguments = std::tuple<uint32_t, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttrib1f; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttrib1f(uint32_t index, float x)
        : m_index(index)
        , m_x(x)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_x;
    }

private:
    uint32_t m_index;
    float m_x;
};

class VertexAttrib1fv {
public:
    using Arguments = std::tuple<uint32_t, std::span<const float, 1>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttrib1fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttrib1fv(uint32_t index, const std::span<const float, 1>& values)
        : m_index(index)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_index;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float, 1>& m_values;
};

class VertexAttrib2f {
public:
    using Arguments = std::tuple<uint32_t, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttrib2f; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttrib2f(uint32_t index, float x, float y)
        : m_index(index)
        , m_x(x)
        , m_y(y)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_x;
        encoder << m_y;
    }

private:
    uint32_t m_index;
    float m_x;
    float m_y;
};

class VertexAttrib2fv {
public:
    using Arguments = std::tuple<uint32_t, std::span<const float, 2>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttrib2fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttrib2fv(uint32_t index, const std::span<const float, 2>& values)
        : m_index(index)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_index;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float, 2>& m_values;
};

class VertexAttrib3f {
public:
    using Arguments = std::tuple<uint32_t, float, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttrib3f; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttrib3f(uint32_t index, float x, float y, float z)
        : m_index(index)
        , m_x(x)
        , m_y(y)
        , m_z(z)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_x;
        encoder << m_y;
        encoder << m_z;
    }

private:
    uint32_t m_index;
    float m_x;
    float m_y;
    float m_z;
};

class VertexAttrib3fv {
public:
    using Arguments = std::tuple<uint32_t, std::span<const float, 3>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttrib3fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttrib3fv(uint32_t index, const std::span<const float, 3>& values)
        : m_index(index)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_index;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float, 3>& m_values;
};

class VertexAttrib4f {
public:
    using Arguments = std::tuple<uint32_t, float, float, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttrib4f; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttrib4f(uint32_t index, float x, float y, float z, float w)
        : m_index(index)
        , m_x(x)
        , m_y(y)
        , m_z(z)
        , m_w(w)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_x;
        encoder << m_y;
        encoder << m_z;
        encoder << m_w;
    }

private:
    uint32_t m_index;
    float m_x;
    float m_y;
    float m_z;
    float m_w;
};

class VertexAttrib4fv {
public:
    using Arguments = std::tuple<uint32_t, std::span<const float, 4>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttrib4fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttrib4fv(uint32_t index, const std::span<const float, 4>& values)
        : m_index(index)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_index;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float, 4>& m_values;
};

class VertexAttribPointer {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, bool, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttribPointer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttribPointer(uint32_t index, int32_t size, uint32_t type, bool normalized, int32_t stride, uint64_t offset)
        : m_index(index)
        , m_size(size)
        , m_type(type)
        , m_normalized(normalized)
        , m_stride(stride)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_size;
        encoder << m_type;
        encoder << m_normalized;
        encoder << m_stride;
        encoder << m_offset;
    }

private:
    uint32_t m_index;
    int32_t m_size;
    uint32_t m_type;
    bool m_normalized;
    int32_t m_stride;
    uint64_t m_offset;
};

class Viewport {
public:
    using Arguments = std::tuple<int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Viewport; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Viewport(int32_t x, int32_t y, int32_t width, int32_t height)
        : m_x(x)
        , m_y(y)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_x;
        encoder << m_y;
        encoder << m_width;
        encoder << m_height;
    }

private:
    int32_t m_x;
    int32_t m_y;
    int32_t m_width;
    int32_t m_height;
};

class BufferData0 {
public:
    using Arguments = std::tuple<uint32_t, uint64_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BufferData0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BufferData0(uint32_t target, uint64_t arg1, uint32_t usage)
        : m_target(target)
        , m_arg1(arg1)
        , m_usage(usage)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_arg1;
        encoder << m_usage;
    }

private:
    uint32_t m_target;
    uint64_t m_arg1;
    uint32_t m_usage;
};

class BufferData1 {
public:
    using Arguments = std::tuple<uint32_t, std::span<const uint8_t>, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BufferData1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BufferData1(uint32_t target, const std::span<const uint8_t>& data, uint32_t usage)
        : m_target(target)
        , m_data(data)
        , m_usage(usage)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        encoder << m_usage;
    }

private:
    uint32_t m_target;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
    uint32_t m_usage;
};

class BufferSubData {
public:
    using Arguments = std::tuple<uint32_t, uint64_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BufferSubData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BufferSubData(uint32_t target, uint64_t offset, const std::span<const uint8_t>& data)
        : m_target(target)
        , m_offset(offset)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_offset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    uint32_t m_target;
    uint64_t m_offset;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class ReadPixelsBufferObject {
public:
    using Arguments = std::tuple<WebCore::IntRect, uint32_t, uint32_t, uint64_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ReadPixelsBufferObject; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ReadPixelsBufferObject(const WebCore::IntRect& arg0, uint32_t format, uint32_t type, uint64_t offset, int32_t alignment, int32_t rowLength)
        : m_arg0(arg0)
        , m_format(format)
        , m_type(type)
        , m_offset(offset)
        , m_alignment(alignment)
        , m_rowLength(rowLength)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_arg0;
        encoder << m_format;
        encoder << m_type;
        encoder << m_offset;
        encoder << m_alignment;
        encoder << m_rowLength;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_arg0;
    uint32_t m_format;
    uint32_t m_type;
    uint64_t m_offset;
    int32_t m_alignment;
    int32_t m_rowLength;
};

class TexImage2D0 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexImage2D0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexImage2D0(uint32_t target, int32_t level, uint32_t internalformat, int32_t width, int32_t height, int32_t border, uint32_t format, uint32_t type, const std::span<const uint8_t>& pixels)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_border(border)
        , m_format(format)
        , m_type(type)
        , m_pixels(pixels)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_border;
        encoder << m_format;
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pixels;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_border;
    uint32_t m_format;
    uint32_t m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_pixels;
};

class TexImage2D1 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexImage2D1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexImage2D1(uint32_t target, int32_t level, uint32_t internalformat, int32_t width, int32_t height, int32_t border, uint32_t format, uint32_t type, uint64_t offset)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_border(border)
        , m_format(format)
        , m_type(type)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_border;
        encoder << m_format;
        encoder << m_type;
        encoder << m_offset;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_border;
    uint32_t m_format;
    uint32_t m_type;
    uint64_t m_offset;
};

class TexSubImage2D0 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexSubImage2D0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexSubImage2D0(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, uint32_t format, uint32_t type, const std::span<const uint8_t>& pixels)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_width(width)
        , m_height(height)
        , m_format(format)
        , m_type(type)
        , m_pixels(pixels)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_width;
        encoder << m_height;
        encoder << m_format;
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pixels;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_width;
    int32_t m_height;
    uint32_t m_format;
    uint32_t m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_pixels;
};

class TexSubImage2D1 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexSubImage2D1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexSubImage2D1(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, uint32_t format, uint32_t type, uint64_t offset)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_width(width)
        , m_height(height)
        , m_format(format)
        , m_type(type)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_width;
        encoder << m_height;
        encoder << m_format;
        encoder << m_type;
        encoder << m_offset;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_width;
    int32_t m_height;
    uint32_t m_format;
    uint32_t m_type;
    uint64_t m_offset;
};

class CompressedTexImage2D0 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t, int32_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompressedTexImage2D0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CompressedTexImage2D0(uint32_t target, int32_t level, uint32_t internalformat, int32_t width, int32_t height, int32_t border, int32_t imageSize, const std::span<const uint8_t>& data)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_border(border)
        , m_imageSize(imageSize)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_border;
        encoder << m_imageSize;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_border;
    int32_t m_imageSize;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class CompressedTexImage2D1 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompressedTexImage2D1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CompressedTexImage2D1(uint32_t target, int32_t level, uint32_t internalformat, int32_t width, int32_t height, int32_t border, int32_t imageSize, uint64_t offset)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_border(border)
        , m_imageSize(imageSize)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_border;
        encoder << m_imageSize;
        encoder << m_offset;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_border;
    int32_t m_imageSize;
    uint64_t m_offset;
};

class CompressedTexSubImage2D0 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, int32_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompressedTexSubImage2D0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CompressedTexSubImage2D0(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, uint32_t format, int32_t imageSize, const std::span<const uint8_t>& data)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_width(width)
        , m_height(height)
        , m_format(format)
        , m_imageSize(imageSize)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_width;
        encoder << m_height;
        encoder << m_format;
        encoder << m_imageSize;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_width;
    int32_t m_height;
    uint32_t m_format;
    int32_t m_imageSize;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class CompressedTexSubImage2D1 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompressedTexSubImage2D1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CompressedTexSubImage2D1(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, uint32_t format, int32_t imageSize, uint64_t offset)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_width(width)
        , m_height(height)
        , m_format(format)
        , m_imageSize(imageSize)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_width;
        encoder << m_height;
        encoder << m_format;
        encoder << m_imageSize;
        encoder << m_offset;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_width;
    int32_t m_height;
    uint32_t m_format;
    int32_t m_imageSize;
    uint64_t m_offset;
};

class DrawArraysInstanced {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawArraysInstanced; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawArraysInstanced(uint32_t mode, int32_t first, int32_t count, int32_t primcount)
        : m_mode(mode)
        , m_first(first)
        , m_count(count)
        , m_primcount(primcount)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        encoder << m_first;
        encoder << m_count;
        encoder << m_primcount;
    }

private:
    uint32_t m_mode;
    int32_t m_first;
    int32_t m_count;
    int32_t m_primcount;
};

class DrawElementsInstanced {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, uint64_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawElementsInstanced; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawElementsInstanced(uint32_t mode, int32_t count, uint32_t type, uint64_t offset, int32_t primcount)
        : m_mode(mode)
        , m_count(count)
        , m_type(type)
        , m_offset(offset)
        , m_primcount(primcount)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        encoder << m_count;
        encoder << m_type;
        encoder << m_offset;
        encoder << m_primcount;
    }

private:
    uint32_t m_mode;
    int32_t m_count;
    uint32_t m_type;
    uint64_t m_offset;
    int32_t m_primcount;
};

class VertexAttribDivisor {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttribDivisor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttribDivisor(uint32_t index, uint32_t divisor)
        : m_index(index)
        , m_divisor(divisor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_divisor;
    }

private:
    uint32_t m_index;
    uint32_t m_divisor;
};

class CreateVertexArray {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateVertexArray; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateVertexArray(uint32_t vertexArray)
        : m_vertexArray(vertexArray)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_vertexArray;
    }

private:
    uint32_t m_vertexArray;
};

class DeleteVertexArray {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteVertexArray; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteVertexArray(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class IsVertexArray {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsVertexArray; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsVertexArray(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class BindVertexArray {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindVertexArray; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit BindVertexArray(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class CopyBufferSubData {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint64_t, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CopyBufferSubData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyBufferSubData(uint32_t readTarget, uint32_t writeTarget, uint64_t readOffset, uint64_t writeOffset, uint64_t arg4)
        : m_readTarget(readTarget)
        , m_writeTarget(writeTarget)
        , m_readOffset(readOffset)
        , m_writeOffset(writeOffset)
        , m_arg4(arg4)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_readTarget;
        encoder << m_writeTarget;
        encoder << m_readOffset;
        encoder << m_writeOffset;
        encoder << m_arg4;
    }

private:
    uint32_t m_readTarget;
    uint32_t m_writeTarget;
    uint64_t m_readOffset;
    uint64_t m_writeOffset;
    uint64_t m_arg4;
};

class BlitFramebuffer {
public:
    using Arguments = std::tuple<int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlitFramebuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlitFramebuffer(int32_t srcX0, int32_t srcY0, int32_t srcX1, int32_t srcY1, int32_t dstX0, int32_t dstY0, int32_t dstX1, int32_t dstY1, uint32_t mask, uint32_t filter)
        : m_srcX0(srcX0)
        , m_srcY0(srcY0)
        , m_srcX1(srcX1)
        , m_srcY1(srcY1)
        , m_dstX0(dstX0)
        , m_dstY0(dstY0)
        , m_dstX1(dstX1)
        , m_dstY1(dstY1)
        , m_mask(mask)
        , m_filter(filter)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_srcX0;
        encoder << m_srcY0;
        encoder << m_srcX1;
        encoder << m_srcY1;
        encoder << m_dstX0;
        encoder << m_dstY0;
        encoder << m_dstX1;
        encoder << m_dstY1;
        encoder << m_mask;
        encoder << m_filter;
    }

private:
    int32_t m_srcX0;
    int32_t m_srcY0;
    int32_t m_srcX1;
    int32_t m_srcY1;
    int32_t m_dstX0;
    int32_t m_dstY0;
    int32_t m_dstX1;
    int32_t m_dstY1;
    uint32_t m_mask;
    uint32_t m_filter;
};

class FramebufferTextureLayer {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_FramebufferTextureLayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FramebufferTextureLayer(uint32_t target, uint32_t attachment, uint32_t texture, int32_t level, int32_t layer)
        : m_target(target)
        , m_attachment(attachment)
        , m_texture(texture)
        , m_level(level)
        , m_layer(layer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_attachment;
        encoder << m_texture;
        encoder << m_level;
        encoder << m_layer;
    }

private:
    uint32_t m_target;
    uint32_t m_attachment;
    uint32_t m_texture;
    int32_t m_level;
    int32_t m_layer;
};

class InvalidateFramebuffer {
public:
    using Arguments = std::tuple<uint32_t, std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_InvalidateFramebuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    InvalidateFramebuffer(uint32_t target, const std::span<const uint32_t>& attachments)
        : m_target(target)
        , m_attachments(attachments)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_attachments;
    }

private:
    uint32_t m_target;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_attachments;
};

class InvalidateSubFramebuffer {
public:
    using Arguments = std::tuple<uint32_t, std::span<const uint32_t>, int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_InvalidateSubFramebuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    InvalidateSubFramebuffer(uint32_t target, const std::span<const uint32_t>& attachments, int32_t x, int32_t y, int32_t width, int32_t height)
        : m_target(target)
        , m_attachments(attachments)
        , m_x(x)
        , m_y(y)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_attachments;
        encoder << m_x;
        encoder << m_y;
        encoder << m_width;
        encoder << m_height;
    }

private:
    uint32_t m_target;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_attachments;
    int32_t m_x;
    int32_t m_y;
    int32_t m_width;
    int32_t m_height;
};

class ReadBuffer {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ReadBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReadBuffer(uint32_t src)
        : m_src(src)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_src;
    }

private:
    uint32_t m_src;
};

class RenderbufferStorageMultisample {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_RenderbufferStorageMultisample; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    RenderbufferStorageMultisample(uint32_t target, int32_t samples, uint32_t internalformat, int32_t width, int32_t height)
        : m_target(target)
        , m_samples(samples)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_samples;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
    }

private:
    uint32_t m_target;
    int32_t m_samples;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
};

class TexStorage2D {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexStorage2D; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexStorage2D(uint32_t target, int32_t levels, uint32_t internalformat, int32_t width, int32_t height)
        : m_target(target)
        , m_levels(levels)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_levels;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
    }

private:
    uint32_t m_target;
    int32_t m_levels;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
};

class TexStorage3D {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexStorage3D; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexStorage3D(uint32_t target, int32_t levels, uint32_t internalformat, int32_t width, int32_t height, int32_t depth)
        : m_target(target)
        , m_levels(levels)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_levels;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
    }

private:
    uint32_t m_target;
    int32_t m_levels;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
};

class TexImage3D0 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexImage3D0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexImage3D0(uint32_t target, int32_t level, int32_t internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, uint32_t format, uint32_t type, const std::span<const uint8_t>& pixels)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
        , m_border(border)
        , m_format(format)
        , m_type(type)
        , m_pixels(pixels)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
        encoder << m_border;
        encoder << m_format;
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pixels;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
    int32_t m_border;
    uint32_t m_format;
    uint32_t m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_pixels;
};

class TexImage3D1 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexImage3D1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexImage3D1(uint32_t target, int32_t level, int32_t internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, uint32_t format, uint32_t type, uint64_t offset)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
        , m_border(border)
        , m_format(format)
        , m_type(type)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
        encoder << m_border;
        encoder << m_format;
        encoder << m_type;
        encoder << m_offset;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
    int32_t m_border;
    uint32_t m_format;
    uint32_t m_type;
    uint64_t m_offset;
};

class TexSubImage3D0 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexSubImage3D0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexSubImage3D0(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, uint32_t format, uint32_t type, const std::span<const uint8_t>& pixels)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_zoffset(zoffset)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
        , m_format(format)
        , m_type(type)
        , m_pixels(pixels)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_zoffset;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
        encoder << m_format;
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pixels;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_zoffset;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
    uint32_t m_format;
    uint32_t m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_pixels;
};

class TexSubImage3D1 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TexSubImage3D1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TexSubImage3D1(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, uint32_t format, uint32_t type, uint64_t offset)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_zoffset(zoffset)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
        , m_format(format)
        , m_type(type)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_zoffset;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
        encoder << m_format;
        encoder << m_type;
        encoder << m_offset;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_zoffset;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
    uint32_t m_format;
    uint32_t m_type;
    uint64_t m_offset;
};

class CopyTexSubImage3D {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CopyTexSubImage3D; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CopyTexSubImage3D(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t x, int32_t y, int32_t width, int32_t height)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_zoffset(zoffset)
        , m_x(x)
        , m_y(y)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_zoffset;
        encoder << m_x;
        encoder << m_y;
        encoder << m_width;
        encoder << m_height;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_zoffset;
    int32_t m_x;
    int32_t m_y;
    int32_t m_width;
    int32_t m_height;
};

class CompressedTexImage3D0 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompressedTexImage3D0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CompressedTexImage3D0(uint32_t target, int32_t level, uint32_t internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, int32_t imageSize, const std::span<const uint8_t>& data)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
        , m_border(border)
        , m_imageSize(imageSize)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
        encoder << m_border;
        encoder << m_imageSize;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
    int32_t m_border;
    int32_t m_imageSize;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class CompressedTexImage3D1 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompressedTexImage3D1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CompressedTexImage3D1(uint32_t target, int32_t level, uint32_t internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, int32_t imageSize, uint64_t offset)
        : m_target(target)
        , m_level(level)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
        , m_border(border)
        , m_imageSize(imageSize)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
        encoder << m_border;
        encoder << m_imageSize;
        encoder << m_offset;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
    int32_t m_border;
    int32_t m_imageSize;
    uint64_t m_offset;
};

class CompressedTexSubImage3D0 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, int32_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompressedTexSubImage3D0; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CompressedTexSubImage3D0(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, uint32_t format, int32_t imageSize, const std::span<const uint8_t>& data)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_zoffset(zoffset)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
        , m_format(format)
        , m_imageSize(imageSize)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_zoffset;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
        encoder << m_format;
        encoder << m_imageSize;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_zoffset;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
    uint32_t m_format;
    int32_t m_imageSize;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class CompressedTexSubImage3D1 {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CompressedTexSubImage3D1; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CompressedTexSubImage3D1(uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, uint32_t format, int32_t imageSize, uint64_t offset)
        : m_target(target)
        , m_level(level)
        , m_xoffset(xoffset)
        , m_yoffset(yoffset)
        , m_zoffset(zoffset)
        , m_width(width)
        , m_height(height)
        , m_depth(depth)
        , m_format(format)
        , m_imageSize(imageSize)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_level;
        encoder << m_xoffset;
        encoder << m_yoffset;
        encoder << m_zoffset;
        encoder << m_width;
        encoder << m_height;
        encoder << m_depth;
        encoder << m_format;
        encoder << m_imageSize;
        encoder << m_offset;
    }

private:
    uint32_t m_target;
    int32_t m_level;
    int32_t m_xoffset;
    int32_t m_yoffset;
    int32_t m_zoffset;
    int32_t m_width;
    int32_t m_height;
    int32_t m_depth;
    uint32_t m_format;
    int32_t m_imageSize;
    uint64_t m_offset;
};

class GetFragDataLocation {
public:
    using Arguments = std::tuple<uint32_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetFragDataLocation; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetFragDataLocation(uint32_t program, const String& name)
        : m_program(program)
        , m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_name;
    }

private:
    uint32_t m_program;
    const String& m_name;
};

class Uniform1ui {
public:
    using Arguments = std::tuple<int32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform1ui; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform1ui(int32_t location, uint32_t v0)
        : m_location(location)
        , m_v0(v0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_v0;
    }

private:
    int32_t m_location;
    uint32_t m_v0;
};

class Uniform2ui {
public:
    using Arguments = std::tuple<int32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform2ui; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform2ui(int32_t location, uint32_t v0, uint32_t v1)
        : m_location(location)
        , m_v0(v0)
        , m_v1(v1)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_v0;
        encoder << m_v1;
    }

private:
    int32_t m_location;
    uint32_t m_v0;
    uint32_t m_v1;
};

class Uniform3ui {
public:
    using Arguments = std::tuple<int32_t, uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform3ui; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform3ui(int32_t location, uint32_t v0, uint32_t v1, uint32_t v2)
        : m_location(location)
        , m_v0(v0)
        , m_v1(v1)
        , m_v2(v2)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_v0;
        encoder << m_v1;
        encoder << m_v2;
    }

private:
    int32_t m_location;
    uint32_t m_v0;
    uint32_t m_v1;
    uint32_t m_v2;
};

class Uniform4ui {
public:
    using Arguments = std::tuple<int32_t, uint32_t, uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform4ui; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform4ui(int32_t location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3)
        : m_location(location)
        , m_v0(v0)
        , m_v1(v1)
        , m_v2(v2)
        , m_v3(v3)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_v0;
        encoder << m_v1;
        encoder << m_v2;
        encoder << m_v3;
    }

private:
    int32_t m_location;
    uint32_t m_v0;
    uint32_t m_v1;
    uint32_t m_v2;
    uint32_t m_v3;
};

class Uniform1uiv {
public:
    using Arguments = std::tuple<int32_t, std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform1uiv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform1uiv(int32_t location, const std::span<const uint32_t>& data)
        : m_location(location)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_data;
};

class Uniform2uiv {
public:
    using Arguments = std::tuple<int32_t, std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform2uiv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform2uiv(int32_t location, const std::span<const uint32_t>& data)
        : m_location(location)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_data;
};

class Uniform3uiv {
public:
    using Arguments = std::tuple<int32_t, std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform3uiv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform3uiv(int32_t location, const std::span<const uint32_t>& data)
        : m_location(location)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_data;
};

class Uniform4uiv {
public:
    using Arguments = std::tuple<int32_t, std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_Uniform4uiv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Uniform4uiv(int32_t location, const std::span<const uint32_t>& data)
        : m_location(location)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_data;
};

class UniformMatrix2x3fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix2x3fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix2x3fv(int32_t location, bool transpose, const std::span<const float>& data)
        : m_location(location)
        , m_transpose(transpose)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_data;
};

class UniformMatrix3x2fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix3x2fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix3x2fv(int32_t location, bool transpose, const std::span<const float>& data)
        : m_location(location)
        , m_transpose(transpose)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_data;
};

class UniformMatrix2x4fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix2x4fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix2x4fv(int32_t location, bool transpose, const std::span<const float>& data)
        : m_location(location)
        , m_transpose(transpose)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_data;
};

class UniformMatrix4x2fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix4x2fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix4x2fv(int32_t location, bool transpose, const std::span<const float>& data)
        : m_location(location)
        , m_transpose(transpose)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_data;
};

class UniformMatrix3x4fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix3x4fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix3x4fv(int32_t location, bool transpose, const std::span<const float>& data)
        : m_location(location)
        , m_transpose(transpose)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_data;
};

class UniformMatrix4x3fv {
public:
    using Arguments = std::tuple<int32_t, bool, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformMatrix4x3fv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformMatrix4x3fv(int32_t location, bool transpose, const std::span<const float>& data)
        : m_location(location)
        , m_transpose(transpose)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_location;
        encoder << m_transpose;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    int32_t m_location;
    bool m_transpose;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_data;
};

class VertexAttribI4i {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttribI4i; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttribI4i(uint32_t index, int32_t x, int32_t y, int32_t z, int32_t w)
        : m_index(index)
        , m_x(x)
        , m_y(y)
        , m_z(z)
        , m_w(w)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_x;
        encoder << m_y;
        encoder << m_z;
        encoder << m_w;
    }

private:
    uint32_t m_index;
    int32_t m_x;
    int32_t m_y;
    int32_t m_z;
    int32_t m_w;
};

class VertexAttribI4iv {
public:
    using Arguments = std::tuple<uint32_t, std::span<const int32_t, 4>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttribI4iv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttribI4iv(uint32_t index, const std::span<const int32_t, 4>& values)
        : m_index(index)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_index;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const int32_t, 4>& m_values;
};

class VertexAttribI4ui {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttribI4ui; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttribI4ui(uint32_t index, uint32_t x, uint32_t y, uint32_t z, uint32_t w)
        : m_index(index)
        , m_x(x)
        , m_y(y)
        , m_z(z)
        , m_w(w)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_x;
        encoder << m_y;
        encoder << m_z;
        encoder << m_w;
    }

private:
    uint32_t m_index;
    uint32_t m_x;
    uint32_t m_y;
    uint32_t m_z;
    uint32_t m_w;
};

class VertexAttribI4uiv {
public:
    using Arguments = std::tuple<uint32_t, std::span<const uint32_t, 4>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttribI4uiv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttribI4uiv(uint32_t index, const std::span<const uint32_t, 4>& values)
        : m_index(index)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_index;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t, 4>& m_values;
};

class VertexAttribIPointer {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_VertexAttribIPointer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    VertexAttribIPointer(uint32_t index, int32_t size, uint32_t type, int32_t stride, uint64_t offset)
        : m_index(index)
        , m_size(size)
        , m_type(type)
        , m_stride(stride)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_size;
        encoder << m_type;
        encoder << m_stride;
        encoder << m_offset;
    }

private:
    uint32_t m_index;
    int32_t m_size;
    uint32_t m_type;
    int32_t m_stride;
    uint64_t m_offset;
};

class DrawRangeElements {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, int32_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawRangeElements; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawRangeElements(uint32_t mode, uint32_t start, uint32_t end, int32_t count, uint32_t type, uint64_t offset)
        : m_mode(mode)
        , m_start(start)
        , m_end(end)
        , m_count(count)
        , m_type(type)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        encoder << m_start;
        encoder << m_end;
        encoder << m_count;
        encoder << m_type;
        encoder << m_offset;
    }

private:
    uint32_t m_mode;
    uint32_t m_start;
    uint32_t m_end;
    int32_t m_count;
    uint32_t m_type;
    uint64_t m_offset;
};

class DrawBuffers {
public:
    using Arguments = std::tuple<std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawBuffers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DrawBuffers(const std::span<const uint32_t>& bufs)
        : m_bufs(bufs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bufs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_bufs;
};

class ClearBufferiv {
public:
    using Arguments = std::tuple<uint32_t, int32_t, std::span<const int32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClearBufferiv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClearBufferiv(uint32_t buffer, int32_t drawbuffer, const std::span<const int32_t>& values)
        : m_buffer(buffer)
        , m_drawbuffer(drawbuffer)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buffer;
        encoder << m_drawbuffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_buffer;
    int32_t m_drawbuffer;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const int32_t>& m_values;
};

class ClearBufferuiv {
public:
    using Arguments = std::tuple<uint32_t, int32_t, std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClearBufferuiv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClearBufferuiv(uint32_t buffer, int32_t drawbuffer, const std::span<const uint32_t>& values)
        : m_buffer(buffer)
        , m_drawbuffer(drawbuffer)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buffer;
        encoder << m_drawbuffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_buffer;
    int32_t m_drawbuffer;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_values;
};

class ClearBufferfv {
public:
    using Arguments = std::tuple<uint32_t, int32_t, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClearBufferfv; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClearBufferfv(uint32_t buffer, int32_t drawbuffer, const std::span<const float>& values)
        : m_buffer(buffer)
        , m_drawbuffer(drawbuffer)
        , m_values(values)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buffer;
        encoder << m_drawbuffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_values;
    }

private:
    uint32_t m_buffer;
    int32_t m_drawbuffer;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_values;
};

class ClearBufferfi {
public:
    using Arguments = std::tuple<uint32_t, int32_t, float, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClearBufferfi; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClearBufferfi(uint32_t buffer, int32_t drawbuffer, float depth, int32_t stencil)
        : m_buffer(buffer)
        , m_drawbuffer(drawbuffer)
        , m_depth(depth)
        , m_stencil(stencil)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buffer;
        encoder << m_drawbuffer;
        encoder << m_depth;
        encoder << m_stencil;
    }

private:
    uint32_t m_buffer;
    int32_t m_drawbuffer;
    float m_depth;
    int32_t m_stencil;
};

class CreateQuery {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateQuery; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateQuery(uint32_t query)
        : m_query(query)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
    }

private:
    uint32_t m_query;
};

class DeleteQuery {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteQuery; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteQuery(uint32_t query)
        : m_query(query)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
    }

private:
    uint32_t m_query;
};

class IsQuery {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsQuery; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsQuery(uint32_t query)
        : m_query(query)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
    }

private:
    uint32_t m_query;
};

class BeginQuery {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BeginQuery; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BeginQuery(uint32_t target, uint32_t query)
        : m_target(target)
        , m_query(query)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_query;
    }

private:
    uint32_t m_target;
    uint32_t m_query;
};

class EndQuery {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_EndQuery; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit EndQuery(uint32_t target)
        : m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
    }

private:
    uint32_t m_target;
};

class GetQuery {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetQuery; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetQuery(uint32_t target, uint32_t pname)
        : m_target(target)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_pname;
    }

private:
    uint32_t m_target;
    uint32_t m_pname;
};

class GetQueryObjectui {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetQueryObjectui; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    GetQueryObjectui(uint32_t query, uint32_t pname)
        : m_query(query)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
        encoder << m_pname;
    }

private:
    uint32_t m_query;
    uint32_t m_pname;
};

class CreateSampler {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateSampler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateSampler(uint32_t sampler)
        : m_sampler(sampler)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sampler;
    }

private:
    uint32_t m_sampler;
};

class DeleteSampler {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteSampler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteSampler(uint32_t sampler)
        : m_sampler(sampler)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sampler;
    }

private:
    uint32_t m_sampler;
};

class IsSampler {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsSampler; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsSampler(uint32_t sampler)
        : m_sampler(sampler)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sampler;
    }

private:
    uint32_t m_sampler;
};

class BindSampler {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindSampler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindSampler(uint32_t unit, uint32_t sampler)
        : m_unit(unit)
        , m_sampler(sampler)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_unit;
        encoder << m_sampler;
    }

private:
    uint32_t m_unit;
    uint32_t m_sampler;
};

class SamplerParameteri {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_SamplerParameteri; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    SamplerParameteri(uint32_t sampler, uint32_t pname, int32_t param)
        : m_sampler(sampler)
        , m_pname(pname)
        , m_param(param)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sampler;
        encoder << m_pname;
        encoder << m_param;
    }

private:
    uint32_t m_sampler;
    uint32_t m_pname;
    int32_t m_param;
};

class SamplerParameterf {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_SamplerParameterf; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    SamplerParameterf(uint32_t sampler, uint32_t pname, float param)
        : m_sampler(sampler)
        , m_pname(pname)
        , m_param(param)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sampler;
        encoder << m_pname;
        encoder << m_param;
    }

private:
    uint32_t m_sampler;
    uint32_t m_pname;
    float m_param;
};

class GetSamplerParameterf {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetSamplerParameterf; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<float>;
    using Reply = CompletionHandler<void(float)>;
    GetSamplerParameterf(uint32_t sampler, uint32_t pname)
        : m_sampler(sampler)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sampler;
        encoder << m_pname;
    }

private:
    uint32_t m_sampler;
    uint32_t m_pname;
};

class GetSamplerParameteri {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetSamplerParameteri; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetSamplerParameteri(uint32_t sampler, uint32_t pname)
        : m_sampler(sampler)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sampler;
        encoder << m_pname;
    }

private:
    uint32_t m_sampler;
    uint32_t m_pname;
};

class FenceSync {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_FenceSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    FenceSync(uint32_t condition, uint32_t flags)
        : m_condition(condition)
        , m_flags(flags)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_condition;
        encoder << m_flags;
    }

private:
    uint32_t m_condition;
    uint32_t m_flags;
};

class IsSync {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsSync(uint64_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint64_t m_arg0;
};

class DeleteSync {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteSync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteSync(uint64_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint64_t m_arg0;
};

class ClientWaitSync {
public:
    using Arguments = std::tuple<uint64_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClientWaitSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    ClientWaitSync(uint64_t arg0, uint32_t flags, uint64_t timeout)
        : m_arg0(arg0)
        , m_flags(flags)
        , m_timeout(timeout)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_flags;
        encoder << m_timeout;
    }

private:
    uint64_t m_arg0;
    uint32_t m_flags;
    uint64_t m_timeout;
};

class WaitSync {
public:
    using Arguments = std::tuple<uint64_t, uint32_t, int64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_WaitSync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    WaitSync(uint64_t arg0, uint32_t flags, int64_t timeout)
        : m_arg0(arg0)
        , m_flags(flags)
        , m_timeout(timeout)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_flags;
        encoder << m_timeout;
    }

private:
    uint64_t m_arg0;
    uint32_t m_flags;
    int64_t m_timeout;
};

class GetSynci {
public:
    using Arguments = std::tuple<uint64_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetSynci; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetSynci(uint64_t arg0, uint32_t pname)
        : m_arg0(arg0)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
        encoder << m_pname;
    }

private:
    uint64_t m_arg0;
    uint32_t m_pname;
};

class CreateTransformFeedback {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateTransformFeedback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateTransformFeedback(uint32_t transformFeedback)
        : m_transformFeedback(transformFeedback)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_transformFeedback;
    }

private:
    uint32_t m_transformFeedback;
};

class DeleteTransformFeedback {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteTransformFeedback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteTransformFeedback(uint32_t id)
        : m_id(id)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_id;
    }

private:
    uint32_t m_id;
};

class IsTransformFeedback {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsTransformFeedback; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsTransformFeedback(uint32_t id)
        : m_id(id)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_id;
    }

private:
    uint32_t m_id;
};

class BindTransformFeedback {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindTransformFeedback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindTransformFeedback(uint32_t target, uint32_t id)
        : m_target(target)
        , m_id(id)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_id;
    }

private:
    uint32_t m_target;
    uint32_t m_id;
};

class BeginTransformFeedback {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BeginTransformFeedback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit BeginTransformFeedback(uint32_t primitiveMode)
        : m_primitiveMode(primitiveMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_primitiveMode;
    }

private:
    uint32_t m_primitiveMode;
};

class EndTransformFeedback {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_EndTransformFeedback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    EndTransformFeedback()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class TransformFeedbackVaryings {
public:
    using Arguments = std::tuple<uint32_t, Vector<String>, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_TransformFeedbackVaryings; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    TransformFeedbackVaryings(uint32_t program, const Vector<String>& varyings, uint32_t bufferMode)
        : m_program(program)
        , m_varyings(varyings)
        , m_bufferMode(bufferMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_varyings;
        encoder << m_bufferMode;
    }

private:
    uint32_t m_program;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_varyings;
    uint32_t m_bufferMode;
};

class GetTransformFeedbackVarying {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetTransformFeedbackVarying; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::GraphicsContextGLActiveInfo>;
    using Reply = CompletionHandler<void(WebCore::GraphicsContextGLActiveInfo&&)>;
    GetTransformFeedbackVarying(uint32_t program, uint32_t index)
        : m_program(program)
        , m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_index;
    }

private:
    uint32_t m_program;
    uint32_t m_index;
};

class PauseTransformFeedback {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PauseTransformFeedback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    PauseTransformFeedback()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ResumeTransformFeedback {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ResumeTransformFeedback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ResumeTransformFeedback()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class BindBufferBase {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindBufferBase; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindBufferBase(uint32_t target, uint32_t index, uint32_t buffer)
        : m_target(target)
        , m_index(index)
        , m_buffer(buffer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_index;
        encoder << m_buffer;
    }

private:
    uint32_t m_target;
    uint32_t m_index;
    uint32_t m_buffer;
};

class BindBufferRange {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindBufferRange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindBufferRange(uint32_t target, uint32_t index, uint32_t buffer, uint64_t offset, uint64_t arg4)
        : m_target(target)
        , m_index(index)
        , m_buffer(buffer)
        , m_offset(offset)
        , m_arg4(arg4)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_index;
        encoder << m_buffer;
        encoder << m_offset;
        encoder << m_arg4;
    }

private:
    uint32_t m_target;
    uint32_t m_index;
    uint32_t m_buffer;
    uint64_t m_offset;
    uint64_t m_arg4;
};

class GetUniformIndices {
public:
    using Arguments = std::tuple<uint32_t, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetUniformIndices; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<uint32_t>>;
    using Reply = CompletionHandler<void(Vector<uint32_t>&&)>;
    GetUniformIndices(uint32_t program, const Vector<String>& uniformNames)
        : m_program(program)
        , m_uniformNames(uniformNames)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_uniformNames;
    }

private:
    uint32_t m_program;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_uniformNames;
};

class GetActiveUniforms {
public:
    using Arguments = std::tuple<uint32_t, Vector<uint32_t>, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetActiveUniforms; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<int32_t>>;
    using Reply = CompletionHandler<void(Vector<int32_t>&&)>;
    GetActiveUniforms(uint32_t program, const Vector<uint32_t>& uniformIndices, uint32_t pname)
        : m_program(program)
        , m_uniformIndices(uniformIndices)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_uniformIndices;
        encoder << m_pname;
    }

private:
    uint32_t m_program;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint32_t>& m_uniformIndices;
    uint32_t m_pname;
};

class GetUniformBlockIndex {
public:
    using Arguments = std::tuple<uint32_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetUniformBlockIndex; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    GetUniformBlockIndex(uint32_t program, const String& uniformBlockName)
        : m_program(program)
        , m_uniformBlockName(uniformBlockName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_uniformBlockName;
    }

private:
    uint32_t m_program;
    const String& m_uniformBlockName;
};

class GetActiveUniformBlockName {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetActiveUniformBlockName; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    GetActiveUniformBlockName(uint32_t program, uint32_t uniformBlockIndex)
        : m_program(program)
        , m_uniformBlockIndex(uniformBlockIndex)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_uniformBlockIndex;
    }

private:
    uint32_t m_program;
    uint32_t m_uniformBlockIndex;
};

class UniformBlockBinding {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_UniformBlockBinding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UniformBlockBinding(uint32_t program, uint32_t uniformBlockIndex, uint32_t uniformBlockBinding)
        : m_program(program)
        , m_uniformBlockIndex(uniformBlockIndex)
        , m_uniformBlockBinding(uniformBlockBinding)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_uniformBlockIndex;
        encoder << m_uniformBlockBinding;
    }

private:
    uint32_t m_program;
    uint32_t m_uniformBlockIndex;
    uint32_t m_uniformBlockBinding;
};

class GetActiveUniformBlockiv {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetActiveUniformBlockiv; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const int32_t>>;
    using Reply = CompletionHandler<void(std::span<const int32_t>&&)>;
    GetActiveUniformBlockiv(uint32_t program, uint32_t uniformBlockIndex, uint32_t pname, uint64_t paramsSize)
        : m_program(program)
        , m_uniformBlockIndex(uniformBlockIndex)
        , m_pname(pname)
        , m_paramsSize(paramsSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_program;
        encoder << m_uniformBlockIndex;
        encoder << m_pname;
        encoder << m_paramsSize;
    }

private:
    uint32_t m_program;
    uint32_t m_uniformBlockIndex;
    uint32_t m_pname;
    uint64_t m_paramsSize;
};

class GetTranslatedShaderSourceANGLE {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetTranslatedShaderSourceANGLE; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    explicit GetTranslatedShaderSourceANGLE(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class DrawBuffersEXT {
public:
    using Arguments = std::tuple<std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawBuffersEXT; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DrawBuffersEXT(const std::span<const uint32_t>& bufs)
        : m_bufs(bufs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bufs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_bufs;
};

class CreateQueryEXT {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateQueryEXT; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateQueryEXT(uint32_t queryEXT)
        : m_queryEXT(queryEXT)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_queryEXT;
    }

private:
    uint32_t m_queryEXT;
};

class DeleteQueryEXT {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteQueryEXT; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteQueryEXT(uint32_t query)
        : m_query(query)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
    }

private:
    uint32_t m_query;
};

class IsQueryEXT {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_IsQueryEXT; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsQueryEXT(uint32_t query)
        : m_query(query)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
    }

private:
    uint32_t m_query;
};

class BeginQueryEXT {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BeginQueryEXT; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BeginQueryEXT(uint32_t target, uint32_t query)
        : m_target(target)
        , m_query(query)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_query;
    }

private:
    uint32_t m_target;
    uint32_t m_query;
};

class EndQueryEXT {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_EndQueryEXT; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit EndQueryEXT(uint32_t target)
        : m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
    }

private:
    uint32_t m_target;
};

class QueryCounterEXT {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_QueryCounterEXT; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    QueryCounterEXT(uint32_t query, uint32_t target)
        : m_query(query)
        , m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
        encoder << m_target;
    }

private:
    uint32_t m_query;
    uint32_t m_target;
};

class GetQueryiEXT {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetQueryiEXT; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetQueryiEXT(uint32_t target, uint32_t pname)
        : m_target(target)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_pname;
    }

private:
    uint32_t m_target;
    uint32_t m_pname;
};

class GetQueryObjectiEXT {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetQueryObjectiEXT; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    GetQueryObjectiEXT(uint32_t query, uint32_t pname)
        : m_query(query)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
        encoder << m_pname;
    }

private:
    uint32_t m_query;
    uint32_t m_pname;
};

class GetQueryObjectui64EXT {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetQueryObjectui64EXT; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    GetQueryObjectui64EXT(uint32_t query, uint32_t pname)
        : m_query(query)
        , m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_query;
        encoder << m_pname;
    }

private:
    uint32_t m_query;
    uint32_t m_pname;
};

class GetInteger64EXT {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetInteger64EXT; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    explicit GetInteger64EXT(uint32_t pname)
        : m_pname(pname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pname;
    }

private:
    uint32_t m_pname;
};

class EnableiOES {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_EnableiOES; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    EnableiOES(uint32_t target, uint32_t index)
        : m_target(target)
        , m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_index;
    }

private:
    uint32_t m_target;
    uint32_t m_index;
};

class DisableiOES {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DisableiOES; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DisableiOES(uint32_t target, uint32_t index)
        : m_target(target)
        , m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_index;
    }

private:
    uint32_t m_target;
    uint32_t m_index;
};

class BlendEquationiOES {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendEquationiOES; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlendEquationiOES(uint32_t buf, uint32_t mode)
        : m_buf(buf)
        , m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buf;
        encoder << m_mode;
    }

private:
    uint32_t m_buf;
    uint32_t m_mode;
};

class BlendEquationSeparateiOES {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendEquationSeparateiOES; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlendEquationSeparateiOES(uint32_t buf, uint32_t modeRGB, uint32_t modeAlpha)
        : m_buf(buf)
        , m_modeRGB(modeRGB)
        , m_modeAlpha(modeAlpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buf;
        encoder << m_modeRGB;
        encoder << m_modeAlpha;
    }

private:
    uint32_t m_buf;
    uint32_t m_modeRGB;
    uint32_t m_modeAlpha;
};

class BlendFunciOES {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendFunciOES; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlendFunciOES(uint32_t buf, uint32_t src, uint32_t dst)
        : m_buf(buf)
        , m_src(src)
        , m_dst(dst)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buf;
        encoder << m_src;
        encoder << m_dst;
    }

private:
    uint32_t m_buf;
    uint32_t m_src;
    uint32_t m_dst;
};

class BlendFuncSeparateiOES {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BlendFuncSeparateiOES; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BlendFuncSeparateiOES(uint32_t buf, uint32_t srcRGB, uint32_t dstRGB, uint32_t srcAlpha, uint32_t dstAlpha)
        : m_buf(buf)
        , m_srcRGB(srcRGB)
        , m_dstRGB(dstRGB)
        , m_srcAlpha(srcAlpha)
        , m_dstAlpha(dstAlpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buf;
        encoder << m_srcRGB;
        encoder << m_dstRGB;
        encoder << m_srcAlpha;
        encoder << m_dstAlpha;
    }

private:
    uint32_t m_buf;
    uint32_t m_srcRGB;
    uint32_t m_dstRGB;
    uint32_t m_srcAlpha;
    uint32_t m_dstAlpha;
};

class ColorMaskiOES {
public:
    using Arguments = std::tuple<uint32_t, bool, bool, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ColorMaskiOES; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ColorMaskiOES(uint32_t buf, bool red, bool green, bool blue, bool alpha)
        : m_buf(buf)
        , m_red(red)
        , m_green(green)
        , m_blue(blue)
        , m_alpha(alpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_buf;
        encoder << m_red;
        encoder << m_green;
        encoder << m_blue;
        encoder << m_alpha;
    }

private:
    uint32_t m_buf;
    bool m_red;
    bool m_green;
    bool m_blue;
    bool m_alpha;
};

class DrawArraysInstancedBaseInstanceANGLE {
public:
    using Arguments = std::tuple<uint32_t, int32_t, int32_t, int32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawArraysInstancedBaseInstanceANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawArraysInstancedBaseInstanceANGLE(uint32_t mode, int32_t first, int32_t count, int32_t instanceCount, uint32_t baseInstance)
        : m_mode(mode)
        , m_first(first)
        , m_count(count)
        , m_instanceCount(instanceCount)
        , m_baseInstance(baseInstance)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        encoder << m_first;
        encoder << m_count;
        encoder << m_instanceCount;
        encoder << m_baseInstance;
    }

private:
    uint32_t m_mode;
    int32_t m_first;
    int32_t m_count;
    int32_t m_instanceCount;
    uint32_t m_baseInstance;
};

class DrawElementsInstancedBaseVertexBaseInstanceANGLE {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, uint64_t, int32_t, int32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DrawElementsInstancedBaseVertexBaseInstanceANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawElementsInstancedBaseVertexBaseInstanceANGLE(uint32_t mode, int32_t count, uint32_t type, uint64_t offset, int32_t instanceCount, int32_t baseVertex, uint32_t baseInstance)
        : m_mode(mode)
        , m_count(count)
        , m_type(type)
        , m_offset(offset)
        , m_instanceCount(instanceCount)
        , m_baseVertex(baseVertex)
        , m_baseInstance(baseInstance)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
        encoder << m_count;
        encoder << m_type;
        encoder << m_offset;
        encoder << m_instanceCount;
        encoder << m_baseVertex;
        encoder << m_baseInstance;
    }

private:
    uint32_t m_mode;
    int32_t m_count;
    uint32_t m_type;
    uint64_t m_offset;
    int32_t m_instanceCount;
    int32_t m_baseVertex;
    uint32_t m_baseInstance;
};

class ClipControlEXT {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ClipControlEXT; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClipControlEXT(uint32_t origin, uint32_t depth)
        : m_origin(origin)
        , m_depth(depth)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_origin;
        encoder << m_depth;
    }

private:
    uint32_t m_origin;
    uint32_t m_depth;
};

class ProvokingVertexANGLE {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_ProvokingVertexANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ProvokingVertexANGLE(uint32_t provokeMode)
        : m_provokeMode(provokeMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_provokeMode;
    }

private:
    uint32_t m_provokeMode;
};

class PolygonModeANGLE {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PolygonModeANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    PolygonModeANGLE(uint32_t face, uint32_t mode)
        : m_face(face)
        , m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_face;
        encoder << m_mode;
    }

private:
    uint32_t m_face;
    uint32_t m_mode;
};

class PolygonOffsetClampEXT {
public:
    using Arguments = std::tuple<float, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_PolygonOffsetClampEXT; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    PolygonOffsetClampEXT(float factor, float units, float clamp)
        : m_factor(factor)
        , m_units(units)
        , m_clamp(clamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_factor;
        encoder << m_units;
        encoder << m_clamp;
    }

private:
    float m_factor;
    float m_units;
    float m_clamp;
};

class RenderbufferStorageMultisampleANGLE {
public:
    using Arguments = std::tuple<uint32_t, int32_t, uint32_t, int32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_RenderbufferStorageMultisampleANGLE; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    RenderbufferStorageMultisampleANGLE(uint32_t target, int32_t samples, uint32_t internalformat, int32_t width, int32_t height)
        : m_target(target)
        , m_samples(samples)
        , m_internalformat(internalformat)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_samples;
        encoder << m_internalformat;
        encoder << m_width;
        encoder << m_height;
    }

private:
    uint32_t m_target;
    int32_t m_samples;
    uint32_t m_internalformat;
    int32_t m_width;
    int32_t m_height;
};

class GetInternalformativ {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_GetInternalformativ; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const int32_t>>;
    using Reply = CompletionHandler<void(std::span<const int32_t>&&)>;
    GetInternalformativ(uint32_t target, uint32_t internalformat, uint32_t pname, uint64_t paramsSize)
        : m_target(target)
        , m_internalformat(internalformat)
        , m_pname(pname)
        , m_paramsSize(paramsSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_internalformat;
        encoder << m_pname;
        encoder << m_paramsSize;
    }

private:
    uint32_t m_target;
    uint32_t m_internalformat;
    uint32_t m_pname;
    uint64_t m_paramsSize;
};

class SetDrawingBufferColorSpace {
public:
    using Arguments = std::tuple<WebCore::DestinationColorSpace>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_SetDrawingBufferColorSpace; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit SetDrawingBufferColorSpace(const WebCore::DestinationColorSpace& arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    const WebCore::DestinationColorSpace& m_arg0;
};

#if ENABLE(WEBXR)
class CreateExternalImage {
public:
    using Arguments = std::tuple<uint32_t, WebCore::GraphicsContextGL::ExternalImageSource, uint32_t, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateExternalImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    CreateExternalImage(uint32_t externalImage, WebCore::GraphicsContextGL::ExternalImageSource&& arg0, uint32_t internalFormat, int32_t layer)
        : m_externalImage(externalImage)
        , m_arg0(WTFMove(arg0))
        , m_internalFormat(internalFormat)
        , m_layer(layer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_externalImage;
        encoder << WTFMove(m_arg0);
        encoder << m_internalFormat;
        encoder << m_layer;
    }

private:
    uint32_t m_externalImage;
    WebCore::GraphicsContextGL::ExternalImageSource&& m_arg0;
    uint32_t m_internalFormat;
    int32_t m_layer;
};
#endif

#if ENABLE(WEBXR)
class DeleteExternalImage {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteExternalImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteExternalImage(uint32_t handle)
        : m_handle(handle)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_handle;
    }

private:
    uint32_t m_handle;
};
#endif

#if ENABLE(WEBXR)
class BindExternalImage {
public:
    using Arguments = std::tuple<uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_BindExternalImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    BindExternalImage(uint32_t target, uint32_t arg1)
        : m_target(target)
        , m_arg1(arg1)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_arg1;
    }

private:
    uint32_t m_target;
    uint32_t m_arg1;
};
#endif

#if ENABLE(WEBXR)
class CreateExternalSync {
public:
    using Arguments = std::tuple<uint32_t, WebCore::GraphicsContextGL::ExternalSyncSource>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_CreateExternalSync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    CreateExternalSync(uint32_t externalSync, WebCore::GraphicsContextGL::ExternalSyncSource&& arg0)
        : m_externalSync(externalSync)
        , m_arg0(WTFMove(arg0))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_externalSync;
        encoder << WTFMove(m_arg0);
    }

private:
    uint32_t m_externalSync;
    WebCore::GraphicsContextGL::ExternalSyncSource&& m_arg0;
};
#endif

class DeleteExternalSync {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DeleteExternalSync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DeleteExternalSync(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

#if ENABLE(WEBXR)
class EnableRequiredWebXRExtensions {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_EnableRequiredWebXRExtensions; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    EnableRequiredWebXRExtensions()
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

#if ENABLE(WEBXR)
class AddFoveation {
public:
    using Arguments = std::tuple<WebCore::IntSize, WebCore::IntSize, WebCore::IntSize, std::span<const float>, std::span<const float>, std::span<const float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_AddFoveation; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    AddFoveation(const WebCore::IntSize& physicalSizeLeft, const WebCore::IntSize& physicalSizeRight, const WebCore::IntSize& screenSize, const std::span<const float>& horizontalSamplesLeft, const std::span<const float>& verticalSamples, const std::span<const float>& horizontalSamplesRight)
        : m_physicalSizeLeft(physicalSizeLeft)
        , m_physicalSizeRight(physicalSizeRight)
        , m_screenSize(screenSize)
        , m_horizontalSamplesLeft(horizontalSamplesLeft)
        , m_verticalSamples(verticalSamples)
        , m_horizontalSamplesRight(horizontalSamplesRight)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_physicalSizeLeft;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_physicalSizeRight;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_screenSize;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_horizontalSamplesLeft;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_verticalSamples;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_horizontalSamplesRight;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_physicalSizeLeft;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_physicalSizeRight;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_screenSize;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_horizontalSamplesLeft;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_verticalSamples;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const float>& m_horizontalSamplesRight;
};
#endif

#if ENABLE(WEBXR)
class EnableFoveation {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_EnableFoveation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit EnableFoveation(uint32_t arg0)
        : m_arg0(arg0)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};
#endif

#if ENABLE(WEBXR)
class DisableFoveation {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_DisableFoveation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DisableFoveation()
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

#if ENABLE(WEBXR)
class FramebufferDiscard {
public:
    using Arguments = std::tuple<uint32_t, std::span<const uint32_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_FramebufferDiscard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FramebufferDiscard(uint32_t target, const std::span<const uint32_t>& attachments)
        : m_target(target)
        , m_attachments(attachments)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_attachments;
    }

private:
    uint32_t m_target;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint32_t>& m_attachments;
};
#endif

#if ENABLE(WEBXR)
class FramebufferResolveRenderbuffer {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGL_FramebufferResolveRenderbuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FramebufferResolveRenderbuffer(uint32_t target, uint32_t attachment, uint32_t renderbuffertarget, uint32_t arg3)
        : m_target(target)
        , m_attachment(attachment)
        , m_renderbuffertarget(renderbuffertarget)
        , m_arg3(arg3)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_target;
        encoder << m_attachment;
        encoder << m_renderbuffertarget;
        encoder << m_arg3;
    }

private:
    uint32_t m_target;
    uint32_t m_attachment;
    uint32_t m_renderbuffertarget;
    uint32_t m_arg3;
};
#endif

} // namespace RemoteGraphicsContextGL
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
