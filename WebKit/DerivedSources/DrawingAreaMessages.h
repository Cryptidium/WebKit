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
#include <WebCore/DestinationColorSpace.h>
#include <WebCore/PlatformLayerIdentifier.h>
#include <wtf/Forward.h>
#include <wtf/MachSendRight.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class FloatPoint;
class FloatRect;
class IntSize;
}

namespace Messages {
namespace DrawingArea {

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
    return IPC::ReceiverName::DrawingArea;
}

#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
class UpdateGeometry {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_UpdateGeometry; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::DrawingArea_UpdateGeometryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit UpdateGeometry(const WebCore::IntSize& size)
        : m_size(size)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_size;
};
#endif

#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
class ForceUpdate {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_ForceUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ForceUpdate()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
class DidDiscardBackingStore {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_DidDiscardBackingStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidDiscardBackingStore()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class SetDeviceScaleFactor {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_SetDeviceScaleFactor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::DrawingArea_SetDeviceScaleFactorReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetDeviceScaleFactor(float deviceScaleFactor)
        : m_deviceScaleFactor(deviceScaleFactor)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_deviceScaleFactor;
    }

private:
    float m_deviceScaleFactor;
};

class DisplayDidRefresh {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_DisplayDidRefresh; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DisplayDidRefresh()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(COCOA)
class UpdateGeometry {
public:
    using Arguments = std::tuple<WebCore::IntSize, bool, MachSendRight>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_UpdateGeometry; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::DrawingArea_UpdateGeometryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UpdateGeometry(const WebCore::IntSize& viewSize, bool flushSynchronously, MachSendRight&& fencePort)
        : m_viewSize(viewSize)
        , m_flushSynchronously(flushSynchronously)
        , m_fencePort(WTFMove(fencePort))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_viewSize;
        encoder << m_flushSynchronously;
        encoder << WTFMove(m_fencePort);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_viewSize;
    bool m_flushSynchronously;
    MachSendRight&& m_fencePort;
};
#endif

#if PLATFORM(COCOA)
class SetColorSpace {
public:
    using Arguments = std::tuple<std::optional<WebCore::DestinationColorSpace>>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_SetColorSpace; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetColorSpace(const std::optional<WebCore::DestinationColorSpace>& colorSpace)
        : m_colorSpace(colorSpace)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_colorSpace;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::DestinationColorSpace>& m_colorSpace;
};
#endif

#if PLATFORM(COCOA)
class SetViewExposedRect {
public:
    using Arguments = std::tuple<std::optional<WebCore::FloatRect>>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_SetViewExposedRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetViewExposedRect(const std::optional<WebCore::FloatRect>& viewExposedRect)
        : m_viewExposedRect(viewExposedRect)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_viewExposedRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatRect>& m_viewExposedRect;
};
#endif

#if PLATFORM(COCOA)
class AcceleratedAnimationDidStart {
public:
    using Arguments = std::tuple<WebCore::PlatformLayerIdentifier, String, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_AcceleratedAnimationDidStart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AcceleratedAnimationDidStart(const WebCore::PlatformLayerIdentifier& layerID, const String& key, const MonotonicTime& startTime)
        : m_layerID(layerID)
        , m_key(key)
        , m_startTime(startTime)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_layerID;
        encoder << m_key;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_startTime;
    }

private:
    const WebCore::PlatformLayerIdentifier& m_layerID;
    const String& m_key;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_startTime;
};
#endif

#if PLATFORM(COCOA)
class AcceleratedAnimationDidEnd {
public:
    using Arguments = std::tuple<WebCore::PlatformLayerIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_AcceleratedAnimationDidEnd; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AcceleratedAnimationDidEnd(const WebCore::PlatformLayerIdentifier& layerID, const String& key)
        : m_layerID(layerID)
        , m_key(key)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_layerID;
        encoder << m_key;
    }

private:
    const WebCore::PlatformLayerIdentifier& m_layerID;
    const String& m_key;
};
#endif

#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
class DispatchAfterEnsuringDrawing {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_DispatchAfterEnsuringDrawing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::DrawingArea_DispatchAfterEnsuringDrawingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DispatchAfterEnsuringDrawing()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(GRAPHICS_LAYER_WC)
class UpdateGeometryWC {
public:
    using Arguments = std::tuple<uint64_t, WebCore::IntSize, float, float>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_UpdateGeometryWC; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateGeometryWC(uint64_t backingStoreStateID, const WebCore::IntSize& viewSize, float deviceScaleFactor, float intrinsicDeviceScaleFactor)
        : m_backingStoreStateID(backingStoreStateID)
        , m_viewSize(viewSize)
        , m_deviceScaleFactor(deviceScaleFactor)
        , m_intrinsicDeviceScaleFactor(intrinsicDeviceScaleFactor)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backingStoreStateID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_viewSize;
        encoder << m_deviceScaleFactor;
        encoder << m_intrinsicDeviceScaleFactor;
    }

private:
    uint64_t m_backingStoreStateID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_viewSize;
    float m_deviceScaleFactor;
    float m_intrinsicDeviceScaleFactor;
};
#endif

#if PLATFORM(COCOA) || PLATFORM(GTK)
class AdjustTransientZoom {
public:
    using Arguments = std::tuple<double, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_AdjustTransientZoom; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AdjustTransientZoom(double scale, const WebCore::FloatPoint& origin)
        : m_scale(scale)
        , m_origin(origin)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scale;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    double m_scale;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_origin;
};
#endif

#if PLATFORM(COCOA) || PLATFORM(GTK)
class CommitTransientZoom {
public:
    using Arguments = std::tuple<double, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::DrawingArea_CommitTransientZoom; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::DrawingArea_CommitTransientZoomReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    CommitTransientZoom(double scale, const WebCore::FloatPoint& origin)
        : m_scale(scale)
        , m_origin(origin)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scale;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    double m_scale;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_origin;
};
#endif

} // namespace DrawingArea
} // namespace Messages
