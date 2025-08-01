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
#include "ArrayReferenceTuple.h"
#include "BufferIdentifierSet.h"
#include "Connection.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "PrepareBackingStoreBuffersData.h"
#include "RemoteImageBufferSetIdentifier.h"
#include "RenderingUpdateID.h"
#include <WebCore/BarcodeDetectorOptionsInterface.h>
#include <WebCore/BarcodeFormatInterface.h>
#include <WebCore/DestinationColorSpace.h>
#include <WebCore/FaceDetectorOptionsInterface.h>
#include <WebCore/GlyphBufferMembers.h>
#include <WebCore/RenderingMode.h>
#include <WebCore/ShareableBitmapHandle.h>
#include <utility>
#include <wtf/Forward.h>
#include <wtf/OptionSet.h>
#include <wtf/Ref.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace WebCore {
class FloatPoint;
class FloatSize;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct RenderingResourceIdentifierType;
using RenderingResourceIdentifier = AtomicObjectIdentifier<RenderingResourceIdentifierType>;
struct SnapshotIdentifierType;
using SnapshotIdentifier = AtomicObjectIdentifier<SnapshotIdentifierType>;
enum class FontSmoothingMode : uint8_t;
struct FontCustomPlatformSerializedData;
struct FontInternalAttributes;
struct FontPlatformDataAttributes;
struct ImageBufferFormat;
struct ImageBufferResourceLimits;
}

namespace WebKit {
struct MarkSurfacesAsVolatileRequestIdentifierType;
using MarkSurfacesAsVolatileRequestIdentifier = ObjectIdentifier<MarkSurfacesAsVolatileRequestIdentifierType>;
struct RemoteDisplayListRecorderIdentifierType;
using RemoteDisplayListRecorderIdentifier = AtomicObjectIdentifier<RemoteDisplayListRecorderIdentifierType>;
struct RemoteSerializedImageBufferIdentifierType;
using RemoteSerializedImageBufferIdentifier = AtomicObjectIdentifier<RemoteSerializedImageBufferIdentifierType>;
struct ShapeDetectionIdentifierType;
using ShapeDetectionIdentifier = ObjectIdentifier<ShapeDetectionIdentifierType>;
}

namespace Messages {
namespace RemoteRenderingBackend {

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
    return IPC::ReceiverName::RemoteRenderingBackend;
}

class CreateImageBuffer {
public:
    using Arguments = std::tuple<WebCore::FloatSize, WebCore::RenderingMode, WebCore::RenderingPurpose, float, WebCore::DestinationColorSpace, WebCore::ImageBufferFormat, WebCore::RenderingResourceIdentifier, WebKit::RemoteDisplayListRecorderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CreateImageBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateImageBuffer(const WebCore::FloatSize& logicalSize, const WebCore::RenderingMode& renderingMode, const WebCore::RenderingPurpose& renderingPurpose, float resolutionScale, const WebCore::DestinationColorSpace& colorSpace, const WebCore::ImageBufferFormat& bufferFormat, const WebCore::RenderingResourceIdentifier& identifier, const WebKit::RemoteDisplayListRecorderIdentifier& contextIdentifier)
        : m_logicalSize(logicalSize)
        , m_renderingMode(renderingMode)
        , m_renderingPurpose(renderingPurpose)
        , m_resolutionScale(resolutionScale)
        , m_colorSpace(colorSpace)
        , m_bufferFormat(bufferFormat)
        , m_identifier(identifier)
        , m_contextIdentifier(contextIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_logicalSize;
        encoder << m_renderingMode;
        encoder << m_renderingPurpose;
        encoder << m_resolutionScale;
        encoder << m_colorSpace;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bufferFormat;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contextIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_logicalSize;
    const WebCore::RenderingMode& m_renderingMode;
    const WebCore::RenderingPurpose& m_renderingPurpose;
    float m_resolutionScale;
    const WebCore::DestinationColorSpace& m_colorSpace;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ImageBufferFormat& m_bufferFormat;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteDisplayListRecorderIdentifier& m_contextIdentifier;
};

class ReleaseImageBuffer {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseImageBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseImageBuffer(const WebCore::RenderingResourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class GetImageBufferResourceLimitsForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_GetImageBufferResourceLimitsForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteRenderingBackend_GetImageBufferResourceLimitsForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ImageBufferResourceLimits>;
    using Reply = CompletionHandler<void(WebCore::ImageBufferResourceLimits&&)>;
    using Promise = WTF::NativePromise<WebCore::ImageBufferResourceLimits, IPC::Error>;
    GetImageBufferResourceLimitsForTesting()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DestroyGetPixelBufferSharedMemory {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_DestroyGetPixelBufferSharedMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DestroyGetPixelBufferSharedMemory()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CacheNativeImage {
public:
    using Arguments = std::tuple<WebCore::ShareableBitmapHandle, WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CacheNativeImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    CacheNativeImage(WebCore::ShareableBitmapHandle&& handle, const WebCore::RenderingResourceIdentifier& renderingResourceIdentifier)
        : m_handle(WTFMove(handle))
        , m_renderingResourceIdentifier(renderingResourceIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handle);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderingResourceIdentifier;
    }

private:
    WebCore::ShareableBitmapHandle&& m_handle;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_renderingResourceIdentifier;
};

class ReleaseNativeImage {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseNativeImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseNativeImage(const WebCore::RenderingResourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class CacheFont {
public:
    using Arguments = std::tuple<WebCore::FontInternalAttributes, WebCore::FontPlatformDataAttributes, std::optional<WebCore::RenderingResourceIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CacheFont; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    CacheFont(const WebCore::FontInternalAttributes& data, const WebCore::FontPlatformDataAttributes& platformData, const std::optional<WebCore::RenderingResourceIdentifier>& renderingResourceIdentifier)
        : m_data(data)
        , m_platformData(platformData)
        , m_renderingResourceIdentifier(renderingResourceIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_platformData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderingResourceIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FontInternalAttributes& m_data;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FontPlatformDataAttributes& m_platformData;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::RenderingResourceIdentifier>& m_renderingResourceIdentifier;
};

class ReleaseFont {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseFont; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseFont(const WebCore::RenderingResourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class CacheFontCustomPlatformData {
public:
    using Arguments = std::tuple<WebCore::FontCustomPlatformSerializedData>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CacheFontCustomPlatformData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    explicit CacheFontCustomPlatformData(const WebCore::FontCustomPlatformSerializedData& fontCustomPlatformData)
        : m_fontCustomPlatformData(fontCustomPlatformData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fontCustomPlatformData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FontCustomPlatformSerializedData& m_fontCustomPlatformData;
};

class ReleaseFontCustomPlatformData {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseFontCustomPlatformData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseFontCustomPlatformData(const WebCore::RenderingResourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class CacheDecomposedGlyphs {
public:
    using Arguments = std::tuple<IPC::ArrayReferenceTuple<WebCore::GlyphBufferGlyph, WebCore::FloatSize>, WebCore::FloatPoint, WebCore::FontSmoothingMode, WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CacheDecomposedGlyphs; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CacheDecomposedGlyphs(const IPC::ArrayReferenceTuple<WebCore::GlyphBufferGlyph, WebCore::FloatSize>& glyphsAdvances, const WebCore::FloatPoint& localAnchor, WebCore::FontSmoothingMode smoothingMode, const WebCore::RenderingResourceIdentifier& identifier)
        : m_glyphsAdvances(glyphsAdvances)
        , m_localAnchor(localAnchor)
        , m_smoothingMode(smoothingMode)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_glyphsAdvances;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_localAnchor;
        encoder << m_smoothingMode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::ArrayReferenceTuple<WebCore::GlyphBufferGlyph, WebCore::FloatSize>& m_glyphsAdvances;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_localAnchor;
    WebCore::FontSmoothingMode m_smoothingMode;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class ReleaseDecomposedGlyphs {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseDecomposedGlyphs; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit ReleaseDecomposedGlyphs(const WebCore::RenderingResourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class CacheGradient {
public:
    using Arguments = std::tuple<Ref<WebCore::Gradient>, WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CacheGradient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CacheGradient(const Ref<WebCore::Gradient>& gradient, const WebCore::RenderingResourceIdentifier& identifier)
        : m_gradient(gradient)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gradient;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::Gradient>& m_gradient;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class ReleaseGradient {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseGradient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseGradient(const WebCore::RenderingResourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class CacheFilter {
public:
    using Arguments = std::tuple<Ref<WebCore::Filter>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CacheFilter; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    explicit CacheFilter(const Ref<WebCore::Filter>& filter)
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

class ReleaseFilter {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseFilter; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseFilter(const WebCore::RenderingResourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
};

class ReleaseMemory {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ReleaseMemory()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ReleaseNativeImages {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseNativeImages; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ReleaseNativeImages()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CreateImageBufferSet {
public:
    using Arguments = std::tuple<WebKit::RemoteImageBufferSetIdentifier, WebKit::RemoteDisplayListRecorderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CreateImageBufferSet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateImageBufferSet(const WebKit::RemoteImageBufferSetIdentifier& identifier, const WebKit::RemoteDisplayListRecorderIdentifier& contextIdentifier)
        : m_identifier(identifier)
        , m_contextIdentifier(contextIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contextIdentifier;
    }

private:
    const WebKit::RemoteImageBufferSetIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteDisplayListRecorderIdentifier& m_contextIdentifier;
};

class ReleaseImageBufferSet {
public:
    using Arguments = std::tuple<WebKit::RemoteImageBufferSetIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseImageBufferSet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseImageBufferSet(const WebKit::RemoteImageBufferSetIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
    }

private:
    const WebKit::RemoteImageBufferSetIdentifier& m_identifier;
};

#if PLATFORM(COCOA)
class PrepareImageBufferSetsForDisplay {
public:
    using Arguments = std::tuple<Vector<WebKit::ImageBufferSetPrepareBufferForDisplayInputData>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_PrepareImageBufferSetsForDisplay; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit PrepareImageBufferSetsForDisplay(const Vector<WebKit::ImageBufferSetPrepareBufferForDisplayInputData>& swapBuffersInput)
        : m_swapBuffersInput(swapBuffersInput)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_swapBuffersInput;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::ImageBufferSetPrepareBufferForDisplayInputData>& m_swapBuffersInput;
};
#endif

#if PLATFORM(COCOA)
class PrepareImageBufferSetsForDisplaySync {
public:
    using Arguments = std::tuple<Vector<WebKit::ImageBufferSetPrepareBufferForDisplayInputData>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_PrepareImageBufferSetsForDisplaySync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::SwapBuffersDisplayRequirement>>;
    using Reply = CompletionHandler<void(Vector<WebKit::SwapBuffersDisplayRequirement>&&)>;
    explicit PrepareImageBufferSetsForDisplaySync(const Vector<WebKit::ImageBufferSetPrepareBufferForDisplayInputData>& swapBuffersInput)
        : m_swapBuffersInput(swapBuffersInput)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_swapBuffersInput;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::ImageBufferSetPrepareBufferForDisplayInputData>& m_swapBuffersInput;
};
#endif

class MarkSurfacesVolatile {
public:
    using Arguments = std::tuple<WebKit::MarkSurfacesAsVolatileRequestIdentifier, Vector<std::pair<WebKit::RemoteImageBufferSetIdentifier, OptionSet<WebKit::BufferInSetType>>>, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_MarkSurfacesVolatile; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MarkSurfacesVolatile(const WebKit::MarkSurfacesAsVolatileRequestIdentifier& requestIdentifier, const Vector<std::pair<WebKit::RemoteImageBufferSetIdentifier, OptionSet<WebKit::BufferInSetType>>>& renderingResourceIdentifiers, bool forcePurge)
        : m_requestIdentifier(requestIdentifier)
        , m_renderingResourceIdentifiers(renderingResourceIdentifiers)
        , m_forcePurge(forcePurge)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderingResourceIdentifiers;
        encoder << m_forcePurge;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MarkSurfacesAsVolatileRequestIdentifier& m_requestIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::pair<WebKit::RemoteImageBufferSetIdentifier, OptionSet<WebKit::BufferInSetType>>>& m_renderingResourceIdentifiers;
    bool m_forcePurge;
};

class FinalizeRenderingUpdate {
public:
    using Arguments = std::tuple<WebKit::RenderingUpdateID>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_FinalizeRenderingUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FinalizeRenderingUpdate(const WebKit::RenderingUpdateID& renderingUpdateID)
        : m_renderingUpdateID(renderingUpdateID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_renderingUpdateID;
    }

private:
    const WebKit::RenderingUpdateID& m_renderingUpdateID;
};

#if USE(GRAPHICS_LAYER_WC)
class Flush {
public:
    using Arguments = std::tuple<IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_Flush; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    explicit Flush(const IPC::Semaphore& semaphore)
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

class MoveToSerializedBuffer {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebKit::RemoteSerializedImageBufferIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_MoveToSerializedBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MoveToSerializedBuffer(const WebCore::RenderingResourceIdentifier& identifier, const WebKit::RemoteSerializedImageBufferIdentifier& serializedIdentifier)
        : m_identifier(identifier)
        , m_serializedIdentifier(serializedIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serializedIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteSerializedImageBufferIdentifier& m_serializedIdentifier;
};

class MoveToImageBuffer {
public:
    using Arguments = std::tuple<WebKit::RemoteSerializedImageBufferIdentifier, WebCore::RenderingResourceIdentifier, WebKit::RemoteDisplayListRecorderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_MoveToImageBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    MoveToImageBuffer(const WebKit::RemoteSerializedImageBufferIdentifier& identifier, const WebCore::RenderingResourceIdentifier& imageBufferIdentifier, const WebKit::RemoteDisplayListRecorderIdentifier& contextIdentifier)
        : m_identifier(identifier)
        , m_imageBufferIdentifier(imageBufferIdentifier)
        , m_contextIdentifier(contextIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageBufferIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contextIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteSerializedImageBufferIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_imageBufferIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteDisplayListRecorderIdentifier& m_contextIdentifier;
};

#if PLATFORM(COCOA)
class DidDrawRemoteToPDF {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, WebCore::RenderingResourceIdentifier, WebCore::SnapshotIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_DidDrawRemoteToPDF; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DidDrawRemoteToPDF(const WebCore::PageIdentifier& pageID, const WebCore::RenderingResourceIdentifier& imageBufferIdentifier, const WebCore::SnapshotIdentifier& snapshotIdentifier)
        : m_pageID(pageID)
        , m_imageBufferIdentifier(imageBufferIdentifier)
        , m_snapshotIdentifier(snapshotIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageBufferIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_snapshotIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_imageBufferIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SnapshotIdentifier& m_snapshotIdentifier;
};
#endif

class CreateRemoteBarcodeDetector {
public:
    using Arguments = std::tuple<WebKit::ShapeDetectionIdentifier, WebCore::ShapeDetection::BarcodeDetectorOptions>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CreateRemoteBarcodeDetector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateRemoteBarcodeDetector(const WebKit::ShapeDetectionIdentifier& identifier, const WebCore::ShapeDetection::BarcodeDetectorOptions& barcodeDetectorOptions)
        : m_identifier(identifier)
        , m_barcodeDetectorOptions(barcodeDetectorOptions)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_barcodeDetectorOptions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ShapeDetectionIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ShapeDetection::BarcodeDetectorOptions& m_barcodeDetectorOptions;
};

class ReleaseRemoteBarcodeDetector {
public:
    using Arguments = std::tuple<WebKit::ShapeDetectionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseRemoteBarcodeDetector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseRemoteBarcodeDetector(const WebKit::ShapeDetectionIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ShapeDetectionIdentifier& m_identifier;
};

class GetRemoteBarcodeDetectorSupportedFormats {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_GetRemoteBarcodeDetectorSupportedFormats; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteRenderingBackend_GetRemoteBarcodeDetectorSupportedFormatsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::ShapeDetection::BarcodeFormat>>;
    using Reply = CompletionHandler<void(Vector<WebCore::ShapeDetection::BarcodeFormat>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::ShapeDetection::BarcodeFormat>, IPC::Error>;
    GetRemoteBarcodeDetectorSupportedFormats()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CreateRemoteFaceDetector {
public:
    using Arguments = std::tuple<WebKit::ShapeDetectionIdentifier, WebCore::ShapeDetection::FaceDetectorOptions>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CreateRemoteFaceDetector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateRemoteFaceDetector(const WebKit::ShapeDetectionIdentifier& identifier, const WebCore::ShapeDetection::FaceDetectorOptions& faceDetectorOptions)
        : m_identifier(identifier)
        , m_faceDetectorOptions(faceDetectorOptions)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_faceDetectorOptions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ShapeDetectionIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ShapeDetection::FaceDetectorOptions& m_faceDetectorOptions;
};

class ReleaseRemoteFaceDetector {
public:
    using Arguments = std::tuple<WebKit::ShapeDetectionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseRemoteFaceDetector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseRemoteFaceDetector(const WebKit::ShapeDetectionIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ShapeDetectionIdentifier& m_identifier;
};

class CreateRemoteTextDetector {
public:
    using Arguments = std::tuple<WebKit::ShapeDetectionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_CreateRemoteTextDetector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateRemoteTextDetector(const WebKit::ShapeDetectionIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ShapeDetectionIdentifier& m_identifier;
};

class ReleaseRemoteTextDetector {
public:
    using Arguments = std::tuple<WebKit::ShapeDetectionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteRenderingBackend_ReleaseRemoteTextDetector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ReleaseRemoteTextDetector(const WebKit::ShapeDetectionIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ShapeDetectionIdentifier& m_identifier;
};

} // namespace RemoteRenderingBackend
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
