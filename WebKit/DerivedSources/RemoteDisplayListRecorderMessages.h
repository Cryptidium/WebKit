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
#include "Connection.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "SharedVideoFrame.h"
#include <WebCore/ColorTypes.h>
#include <WebCore/ControlStyle.h>
#include <WebCore/GlyphBufferMembers.h>
#include <WebCore/GraphicsStyle.h>
#include <WebCore/GraphicsTypes.h>
#include <WebCore/PathSegmentData.h>
#include <WebCore/Pattern.h>
#include <WebCore/SharedMemory.h>
#include <span>
#include <wtf/FixedVector.h>
#include <wtf/Forward.h>
#include <wtf/Ref.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace WebCore {
class AffineTransform;
class Color;
class FloatPoint;
class FloatRect;
class FloatRoundedRect;
class FloatSize;
class IntSize;
class Path;
class PathSegment;
struct RenderingResourceIdentifierType;
using RenderingResourceIdentifier = AtomicObjectIdentifier<RenderingResourceIdentifierType>;
enum class RequiresClipToRect : bool;
enum class WindRule : bool;
enum class BlendMode : uint8_t;
enum class CompositeOperator : uint8_t;
enum class FontSmoothingMode : uint8_t;
enum class InterpolationQuality : uint8_t;
enum class LineCap : uint8_t;
enum class LineJoin : uint8_t;
enum class StrokeStyle : uint8_t;
struct CompositeMode;
struct DocumentMarkerLineStyle;
struct GraphicsDropShadow;
struct ImageOrientation;
struct ImagePaintingOptions;
}

namespace Messages {
namespace RemoteDisplayListRecorder {

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
    return IPC::ReceiverName::RemoteDisplayListRecorder;
}

class Save {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_Save; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    Save()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Restore {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_Restore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    Restore()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Translate {
public:
    using Arguments = std::tuple<float, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_Translate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    Translate(float x, float y)
        : m_x(x)
        , m_y(y)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_x;
        encoder << m_y;
    }

private:
    float m_x;
    float m_y;
};

class Rotate {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_Rotate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit Rotate(float angle)
        : m_angle(angle)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_angle;
    }

private:
    float m_angle;
};

class Scale {
public:
    using Arguments = std::tuple<WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_Scale; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit Scale(const WebCore::FloatSize& scale)
        : m_scale(scale)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scale;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_scale;
};

class SetCTM {
public:
    using Arguments = std::tuple<WebCore::AffineTransform>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetCTM; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetCTM(const WebCore::AffineTransform& ctm)
        : m_ctm(ctm)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ctm;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_ctm;
};

class ConcatCTM {
public:
    using Arguments = std::tuple<WebCore::AffineTransform>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ConcatCTM; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit ConcatCTM(const WebCore::AffineTransform& ctm)
        : m_ctm(ctm)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ctm;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_ctm;
};

class SetFillPackedColor {
public:
    using Arguments = std::tuple<WebCore::PackedColor::RGBA>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetFillPackedColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetFillPackedColor(const WebCore::PackedColor::RGBA& color)
        : m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PackedColor::RGBA& m_color;
};

class SetFillColor {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetFillColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetFillColor(const WebCore::Color& color)
        : m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

class SetFillCachedGradient {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::AffineTransform>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetFillCachedGradient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    SetFillCachedGradient(const WebCore::RenderingResourceIdentifier& gradientIdentifier, const WebCore::AffineTransform& spaceTransform)
        : m_gradientIdentifier(gradientIdentifier)
        , m_spaceTransform(spaceTransform)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gradientIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_spaceTransform;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_gradientIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_spaceTransform;
};

class SetFillGradient {
public:
    using Arguments = std::tuple<Ref<WebCore::Gradient>, WebCore::AffineTransform>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetFillGradient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    SetFillGradient(const Ref<WebCore::Gradient>& gradient, const WebCore::AffineTransform& spaceTransform)
        : m_gradient(gradient)
        , m_spaceTransform(spaceTransform)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gradient;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_spaceTransform;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::Gradient>& m_gradient;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_spaceTransform;
};

class SetFillPattern {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::PatternParameters>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetFillPattern; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    SetFillPattern(const WebCore::RenderingResourceIdentifier& tileImageIdentifier, const WebCore::PatternParameters& pattern)
        : m_tileImageIdentifier(tileImageIdentifier)
        , m_pattern(pattern)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tileImageIdentifier;
        encoder << m_pattern;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_tileImageIdentifier;
    const WebCore::PatternParameters& m_pattern;
};

class SetFillRule {
public:
    using Arguments = std::tuple<WebCore::WindRule>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetFillRule; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetFillRule(WebCore::WindRule rule)
        : m_rule(rule)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_rule;
    }

private:
    WebCore::WindRule m_rule;
};

class SetStrokePackedColor {
public:
    using Arguments = std::tuple<WebCore::PackedColor::RGBA>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStrokePackedColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetStrokePackedColor(const WebCore::PackedColor::RGBA& color)
        : m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PackedColor::RGBA& m_color;
};

class SetStrokeColor {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStrokeColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetStrokeColor(const WebCore::Color& color)
        : m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

class SetStrokeCachedGradient {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::AffineTransform>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStrokeCachedGradient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    SetStrokeCachedGradient(const WebCore::RenderingResourceIdentifier& gradientIdentifier, const WebCore::AffineTransform& spaceTransform)
        : m_gradientIdentifier(gradientIdentifier)
        , m_spaceTransform(spaceTransform)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gradientIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_spaceTransform;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_gradientIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_spaceTransform;
};

class SetStrokeGradient {
public:
    using Arguments = std::tuple<Ref<WebCore::Gradient>, WebCore::AffineTransform>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStrokeGradient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    SetStrokeGradient(const Ref<WebCore::Gradient>& gradient, const WebCore::AffineTransform& spaceTransform)
        : m_gradient(gradient)
        , m_spaceTransform(spaceTransform)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gradient;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_spaceTransform;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::Gradient>& m_gradient;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_spaceTransform;
};

class SetStrokePattern {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::PatternParameters>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStrokePattern; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    SetStrokePattern(const WebCore::RenderingResourceIdentifier& tileImageIdentifier, const WebCore::PatternParameters& pattern)
        : m_tileImageIdentifier(tileImageIdentifier)
        , m_pattern(pattern)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tileImageIdentifier;
        encoder << m_pattern;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_tileImageIdentifier;
    const WebCore::PatternParameters& m_pattern;
};

class SetStrokePackedColorAndThickness {
public:
    using Arguments = std::tuple<WebCore::PackedColor::RGBA, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStrokePackedColorAndThickness; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    SetStrokePackedColorAndThickness(const WebCore::PackedColor::RGBA& color, float thickness)
        : m_color(color)
        , m_thickness(thickness)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
        encoder << m_thickness;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PackedColor::RGBA& m_color;
    float m_thickness;
};

class SetStrokeThickness {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStrokeThickness; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetStrokeThickness(float thickness)
        : m_thickness(thickness)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_thickness;
    }

private:
    float m_thickness;
};

class SetStrokeStyle {
public:
    using Arguments = std::tuple<WebCore::StrokeStyle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStrokeStyle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetStrokeStyle(WebCore::StrokeStyle style)
        : m_style(style)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_style;
    }

private:
    WebCore::StrokeStyle m_style;
};

class SetCompositeMode {
public:
    using Arguments = std::tuple<WebCore::CompositeMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetCompositeMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetCompositeMode(const WebCore::CompositeMode& mode)
        : m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CompositeMode& m_mode;
};

class SetDropShadow {
public:
    using Arguments = std::tuple<std::optional<WebCore::GraphicsDropShadow>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetDropShadow; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetDropShadow(const std::optional<WebCore::GraphicsDropShadow>& dropShadow)
        : m_dropShadow(dropShadow)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dropShadow;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::GraphicsDropShadow>& m_dropShadow;
};

class SetStyle {
public:
    using Arguments = std::tuple<std::optional<WebCore::GraphicsStyle>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetStyle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetStyle(const std::optional<WebCore::GraphicsStyle>& style)
        : m_style(style)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_style;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::GraphicsStyle>& m_style;
};

class SetAlpha {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetAlpha; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetAlpha(float alpha)
        : m_alpha(alpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_alpha;
    }

private:
    float m_alpha;
};

class SetTextDrawingMode {
public:
    using Arguments = std::tuple<WebCore::TextDrawingModeFlags>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetTextDrawingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetTextDrawingMode(const WebCore::TextDrawingModeFlags& mode)
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
    const WebCore::TextDrawingModeFlags& m_mode;
};

class SetImageInterpolationQuality {
public:
    using Arguments = std::tuple<WebCore::InterpolationQuality>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetImageInterpolationQuality; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetImageInterpolationQuality(WebCore::InterpolationQuality quality)
        : m_quality(quality)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_quality;
    }

private:
    WebCore::InterpolationQuality m_quality;
};

class SetShouldAntialias {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetShouldAntialias; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetShouldAntialias(bool shouldAntialias)
        : m_shouldAntialias(shouldAntialias)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldAntialias;
    }

private:
    bool m_shouldAntialias;
};

class SetShouldSmoothFonts {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetShouldSmoothFonts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetShouldSmoothFonts(bool shouldSmooth)
        : m_shouldSmooth(shouldSmooth)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldSmooth;
    }

private:
    bool m_shouldSmooth;
};

class SetShouldSubpixelQuantizeFonts {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetShouldSubpixelQuantizeFonts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetShouldSubpixelQuantizeFonts(bool shouldQuantize)
        : m_shouldQuantize(shouldQuantize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldQuantize;
    }

private:
    bool m_shouldQuantize;
};

class SetShadowsIgnoreTransforms {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetShadowsIgnoreTransforms; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetShadowsIgnoreTransforms(bool shouldIgnore)
        : m_shouldIgnore(shouldIgnore)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldIgnore;
    }

private:
    bool m_shouldIgnore;
};

class SetDrawLuminanceMask {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetDrawLuminanceMask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetDrawLuminanceMask(bool shouldDraw)
        : m_shouldDraw(shouldDraw)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldDraw;
    }

private:
    bool m_shouldDraw;
};

class SetLineCap {
public:
    using Arguments = std::tuple<WebCore::LineCap>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetLineCap; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetLineCap(WebCore::LineCap lineCap)
        : m_lineCap(lineCap)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_lineCap;
    }

private:
    WebCore::LineCap m_lineCap;
};

class SetLineDash {
public:
    using Arguments = std::tuple<FixedVector<double>, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetLineDash; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    SetLineDash(const FixedVector<double>& dashArray, float dashOffset)
        : m_dashArray(dashArray)
        , m_dashOffset(dashOffset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dashArray;
        encoder << m_dashOffset;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const FixedVector<double>& m_dashArray;
    float m_dashOffset;
};

class SetLineJoin {
public:
    using Arguments = std::tuple<WebCore::LineJoin>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetLineJoin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetLineJoin(WebCore::LineJoin lineJoin)
        : m_lineJoin(lineJoin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_lineJoin;
    }

private:
    WebCore::LineJoin m_lineJoin;
};

class SetMiterLimit {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetMiterLimit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit SetMiterLimit(float limit)
        : m_limit(limit)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_limit;
    }

private:
    float m_limit;
};

class Clip {
public:
    using Arguments = std::tuple<WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_Clip; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit Clip(const WebCore::FloatRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
};

class ClipRoundedRect {
public:
    using Arguments = std::tuple<WebCore::FloatRoundedRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ClipRoundedRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ClipRoundedRect(const WebCore::FloatRoundedRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRoundedRect& m_rect;
};

class ClipOut {
public:
    using Arguments = std::tuple<WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ClipOut; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ClipOut(const WebCore::FloatRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
};

class ClipOutRoundedRect {
public:
    using Arguments = std::tuple<WebCore::FloatRoundedRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ClipOutRoundedRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ClipOutRoundedRect(const WebCore::FloatRoundedRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRoundedRect& m_rect;
};

class ClipToImageBuffer {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ClipToImageBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClipToImageBuffer(const WebCore::RenderingResourceIdentifier& renderingResourceIdentifier, const WebCore::FloatRect& destinationRect)
        : m_renderingResourceIdentifier(renderingResourceIdentifier)
        , m_destinationRect(destinationRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderingResourceIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_renderingResourceIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_destinationRect;
};

class ClipOutToPath {
public:
    using Arguments = std::tuple<WebCore::Path>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ClipOutToPath; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ClipOutToPath(const WebCore::Path& path)
        : m_path(path)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_path;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Path& m_path;
};

class ClipPath {
public:
    using Arguments = std::tuple<WebCore::Path, WebCore::WindRule>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ClipPath; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ClipPath(const WebCore::Path& path, WebCore::WindRule windRule)
        : m_path(path)
        , m_windRule(windRule)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_path;
        encoder << m_windRule;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Path& m_path;
    WebCore::WindRule m_windRule;
};

class ResetClip {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ResetClip; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ResetClip()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DrawGlyphs {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, IPC::ArrayReferenceTuple<WebCore::GlyphBufferGlyph, WebCore::FloatSize>, WebCore::FloatPoint, WebCore::FontSmoothingMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawGlyphs; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawGlyphs(const WebCore::RenderingResourceIdentifier& fontIdentifier, const IPC::ArrayReferenceTuple<WebCore::GlyphBufferGlyph, WebCore::FloatSize>& glyphsAdvances, const WebCore::FloatPoint& localAnchor, WebCore::FontSmoothingMode smoothingMode)
        : m_fontIdentifier(fontIdentifier)
        , m_glyphsAdvances(glyphsAdvances)
        , m_localAnchor(localAnchor)
        , m_smoothingMode(smoothingMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fontIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_glyphsAdvances;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_localAnchor;
        encoder << m_smoothingMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_fontIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::ArrayReferenceTuple<WebCore::GlyphBufferGlyph, WebCore::FloatSize>& m_glyphsAdvances;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_localAnchor;
    WebCore::FontSmoothingMode m_smoothingMode;
};

class DrawDecomposedGlyphs {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::RenderingResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawDecomposedGlyphs; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawDecomposedGlyphs(const WebCore::RenderingResourceIdentifier& fontIdentifier, const WebCore::RenderingResourceIdentifier& decomposedGlyphsIdentifier)
        : m_fontIdentifier(fontIdentifier)
        , m_decomposedGlyphsIdentifier(decomposedGlyphsIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fontIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_decomposedGlyphsIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_fontIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_decomposedGlyphsIdentifier;
};

class DrawFilteredImageBuffer {
public:
    using Arguments = std::tuple<std::optional<WebCore::RenderingResourceIdentifier>, WebCore::FloatRect, Ref<WebCore::Filter>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawFilteredImageBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawFilteredImageBuffer(const std::optional<WebCore::RenderingResourceIdentifier>& sourceImageIdentifier, const WebCore::FloatRect& sourceImageRect, const Ref<WebCore::Filter>& filter)
        : m_sourceImageIdentifier(sourceImageIdentifier)
        , m_sourceImageRect(sourceImageRect)
        , m_filter(filter)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourceImageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourceImageRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_filter;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::RenderingResourceIdentifier>& m_sourceImageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_sourceImageRect;
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::Filter>& m_filter;
};

class DrawImageBuffer {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::FloatRect, WebCore::FloatRect, WebCore::ImagePaintingOptions>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawImageBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawImageBuffer(const WebCore::RenderingResourceIdentifier& imageBufferIdentifier, const WebCore::FloatRect& destinationRect, const WebCore::FloatRect& srcRect, const WebCore::ImagePaintingOptions& options)
        : m_imageBufferIdentifier(imageBufferIdentifier)
        , m_destinationRect(destinationRect)
        , m_srcRect(srcRect)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageBufferIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_imageBufferIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_destinationRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_srcRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ImagePaintingOptions& m_options;
};

class DrawNativeImage {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::FloatRect, WebCore::FloatRect, WebCore::ImagePaintingOptions>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawNativeImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawNativeImage(const WebCore::RenderingResourceIdentifier& imageIdentifier, const WebCore::FloatRect& destRect, const WebCore::FloatRect& srcRect, const WebCore::ImagePaintingOptions& options)
        : m_imageIdentifier(imageIdentifier)
        , m_destRect(destRect)
        , m_srcRect(srcRect)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_imageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_destRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_srcRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ImagePaintingOptions& m_options;
};

class DrawSystemImage {
public:
    using Arguments = std::tuple<Ref<WebCore::SystemImage>, WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawSystemImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawSystemImage(const Ref<WebCore::SystemImage>& systemImage, const WebCore::FloatRect& destinationRect)
        : m_systemImage(systemImage)
        , m_destinationRect(destinationRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_systemImage;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::SystemImage>& m_systemImage;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_destinationRect;
};

class DrawPatternNativeImage {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::FloatRect, WebCore::FloatRect, WebCore::AffineTransform, WebCore::FloatPoint, WebCore::FloatSize, WebCore::ImagePaintingOptions>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawPatternNativeImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawPatternNativeImage(const WebCore::RenderingResourceIdentifier& imageIdentifier, const WebCore::FloatRect& destRect, const WebCore::FloatRect& tileRect, const WebCore::AffineTransform& transform, const WebCore::FloatPoint& phase, const WebCore::FloatSize& spacing, const WebCore::ImagePaintingOptions& options)
        : m_imageIdentifier(imageIdentifier)
        , m_destRect(destRect)
        , m_tileRect(tileRect)
        , m_transform(transform)
        , m_phase(phase)
        , m_spacing(spacing)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tileRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transform;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_phase;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_spacing;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_imageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_destRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_tileRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_transform;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_phase;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_spacing;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ImagePaintingOptions& m_options;
};

class DrawPatternImageBuffer {
public:
    using Arguments = std::tuple<WebCore::RenderingResourceIdentifier, WebCore::FloatRect, WebCore::FloatRect, WebCore::AffineTransform, WebCore::FloatPoint, WebCore::FloatSize, WebCore::ImagePaintingOptions>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawPatternImageBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawPatternImageBuffer(const WebCore::RenderingResourceIdentifier& imageIdentifier, const WebCore::FloatRect& destRect, const WebCore::FloatRect& tileRect, const WebCore::AffineTransform& transform, const WebCore::FloatPoint& phase, const WebCore::FloatSize& spacing, const WebCore::ImagePaintingOptions& options)
        : m_imageIdentifier(imageIdentifier)
        , m_destRect(destRect)
        , m_tileRect(tileRect)
        , m_transform(transform)
        , m_phase(phase)
        , m_spacing(spacing)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tileRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transform;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_phase;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_spacing;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RenderingResourceIdentifier& m_imageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_destRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_tileRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_transform;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_phase;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_spacing;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ImagePaintingOptions& m_options;
};

class BeginTransparencyLayer {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_BeginTransparencyLayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit BeginTransparencyLayer(float opacity)
        : m_opacity(opacity)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_opacity;
    }

private:
    float m_opacity;
};

class BeginTransparencyLayerWithCompositeMode {
public:
    using Arguments = std::tuple<WebCore::CompositeMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_BeginTransparencyLayerWithCompositeMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit BeginTransparencyLayerWithCompositeMode(const WebCore::CompositeMode& compositeMode)
        : m_compositeMode(compositeMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_compositeMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CompositeMode& m_compositeMode;
};

class EndTransparencyLayer {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_EndTransparencyLayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    EndTransparencyLayer()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DrawRect {
public:
    using Arguments = std::tuple<WebCore::FloatRect, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawRect(const WebCore::FloatRect& rect, float borderThickness)
        : m_rect(rect)
        , m_borderThickness(borderThickness)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        encoder << m_borderThickness;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    float m_borderThickness;
};

class DrawLine {
public:
    using Arguments = std::tuple<WebCore::FloatPoint, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawLine; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawLine(const WebCore::FloatPoint& point1, const WebCore::FloatPoint& point2)
        : m_point1(point1)
        , m_point2(point2)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point1;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point2;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point1;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point2;
};

class DrawLinesForText {
public:
    using Arguments = std::tuple<WebCore::FloatPoint, float, std::span<const WebCore::FloatSegment>, bool, bool, WebCore::StrokeStyle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawLinesForText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawLinesForText(const WebCore::FloatPoint& point, float thickness, const std::span<const WebCore::FloatSegment>& lineSegments, bool printing, bool doubleLines, WebCore::StrokeStyle strokeStyle)
        : m_point(point)
        , m_thickness(thickness)
        , m_lineSegments(lineSegments)
        , m_printing(printing)
        , m_doubleLines(doubleLines)
        , m_strokeStyle(strokeStyle)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_thickness;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineSegments;
        encoder << m_printing;
        encoder << m_doubleLines;
        encoder << m_strokeStyle;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point;
    float m_thickness;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const WebCore::FloatSegment>& m_lineSegments;
    bool m_printing;
    bool m_doubleLines;
    WebCore::StrokeStyle m_strokeStyle;
};

class DrawDotsForDocumentMarker {
public:
    using Arguments = std::tuple<WebCore::FloatRect, WebCore::DocumentMarkerLineStyle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawDotsForDocumentMarker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawDotsForDocumentMarker(const WebCore::FloatRect& rect, const WebCore::DocumentMarkerLineStyle& style)
        : m_rect(rect)
        , m_style(style)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_style;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DocumentMarkerLineStyle& m_style;
};

class DrawEllipse {
public:
    using Arguments = std::tuple<WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawEllipse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DrawEllipse(const WebCore::FloatRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
};

class DrawPath {
public:
    using Arguments = std::tuple<WebCore::Path>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawPath; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit DrawPath(const WebCore::Path& path)
        : m_path(path)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_path;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Path& m_path;
};

class DrawFocusRingPath {
public:
    using Arguments = std::tuple<WebCore::Path, float, WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawFocusRingPath; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawFocusRingPath(const WebCore::Path& path, float outlineWidth, const WebCore::Color& color)
        : m_path(path)
        , m_outlineWidth(outlineWidth)
        , m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_path;
        encoder << m_outlineWidth;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Path& m_path;
    float m_outlineWidth;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

class DrawFocusRingRects {
public:
    using Arguments = std::tuple<Vector<WebCore::FloatRect>, float, float, WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawFocusRingRects; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawFocusRingRects(const Vector<WebCore::FloatRect>& rects, float outlineOffset, float outlineWidth, const WebCore::Color& color)
        : m_rects(rects)
        , m_outlineOffset(outlineOffset)
        , m_outlineWidth(outlineWidth)
        , m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rects;
        encoder << m_outlineOffset;
        encoder << m_outlineWidth;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::FloatRect>& m_rects;
    float m_outlineOffset;
    float m_outlineWidth;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

class FillRect {
public:
    using Arguments = std::tuple<WebCore::FloatRect, WebCore::RequiresClipToRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FillRect(const WebCore::FloatRect& rect, WebCore::RequiresClipToRect requiresClipToRect)
        : m_rect(rect)
        , m_requiresClipToRect(requiresClipToRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        encoder << m_requiresClipToRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    WebCore::RequiresClipToRect m_requiresClipToRect;
};

class FillRectWithColor {
public:
    using Arguments = std::tuple<WebCore::FloatRect, WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillRectWithColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FillRectWithColor(const WebCore::FloatRect& rect, const WebCore::Color& color)
        : m_rect(rect)
        , m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

class FillRectWithGradient {
public:
    using Arguments = std::tuple<WebCore::FloatRect, Ref<WebCore::Gradient>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillRectWithGradient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FillRectWithGradient(const WebCore::FloatRect& rect, const Ref<WebCore::Gradient>& gradient)
        : m_rect(rect)
        , m_gradient(gradient)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gradient;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::Gradient>& m_gradient;
};

class FillRectWithGradientAndSpaceTransform {
public:
    using Arguments = std::tuple<WebCore::FloatRect, Ref<WebCore::Gradient>, WebCore::AffineTransform, WebCore::RequiresClipToRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillRectWithGradientAndSpaceTransform; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FillRectWithGradientAndSpaceTransform(const WebCore::FloatRect& rect, const Ref<WebCore::Gradient>& gradient, const WebCore::AffineTransform& transform, WebCore::RequiresClipToRect requiresClipToRect)
        : m_rect(rect)
        , m_gradient(gradient)
        , m_transform(transform)
        , m_requiresClipToRect(requiresClipToRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gradient;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transform;
        encoder << m_requiresClipToRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::Gradient>& m_gradient;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AffineTransform& m_transform;
    WebCore::RequiresClipToRect m_requiresClipToRect;
};

class FillCompositedRect {
public:
    using Arguments = std::tuple<WebCore::FloatRect, WebCore::Color, WebCore::CompositeOperator, WebCore::BlendMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillCompositedRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FillCompositedRect(const WebCore::FloatRect& rect, const WebCore::Color& color, WebCore::CompositeOperator op, WebCore::BlendMode blendMode)
        : m_rect(rect)
        , m_color(color)
        , m_op(op)
        , m_blendMode(blendMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
        encoder << m_op;
        encoder << m_blendMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
    WebCore::CompositeOperator m_op;
    WebCore::BlendMode m_blendMode;
};

class FillRoundedRect {
public:
    using Arguments = std::tuple<WebCore::FloatRoundedRect, WebCore::Color, WebCore::BlendMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillRoundedRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FillRoundedRect(const WebCore::FloatRoundedRect& rect, const WebCore::Color& color, WebCore::BlendMode blendMode)
        : m_rect(rect)
        , m_color(color)
        , m_blendMode(blendMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
        encoder << m_blendMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRoundedRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
    WebCore::BlendMode m_blendMode;
};

class FillRectWithRoundedHole {
public:
    using Arguments = std::tuple<WebCore::FloatRect, WebCore::FloatRoundedRect, WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillRectWithRoundedHole; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    FillRectWithRoundedHole(const WebCore::FloatRect& rect, const WebCore::FloatRoundedRect& roundedHoleRect, const WebCore::Color& color)
        : m_rect(rect)
        , m_roundedHoleRect(roundedHoleRect)
        , m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_roundedHoleRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRoundedRect& m_roundedHoleRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

#if ENABLE(INLINE_PATH_DATA)
class FillLine {
public:
    using Arguments = std::tuple<WebCore::PathDataLine>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillLine; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FillLine(const WebCore::PathDataLine& line)
        : m_line(line)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_line;
    }

private:
    const WebCore::PathDataLine& m_line;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class FillArc {
public:
    using Arguments = std::tuple<WebCore::PathArc>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillArc; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FillArc(const WebCore::PathArc& arc)
        : m_arc(arc)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arc;
    }

private:
    const WebCore::PathArc& m_arc;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class FillClosedArc {
public:
    using Arguments = std::tuple<WebCore::PathClosedArc>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillClosedArc; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FillClosedArc(const WebCore::PathClosedArc& closedArc)
        : m_closedArc(closedArc)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_closedArc;
    }

private:
    const WebCore::PathClosedArc& m_closedArc;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class FillQuadCurve {
public:
    using Arguments = std::tuple<WebCore::PathDataQuadCurve>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillQuadCurve; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FillQuadCurve(const WebCore::PathDataQuadCurve& curve)
        : m_curve(curve)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_curve;
    }

private:
    const WebCore::PathDataQuadCurve& m_curve;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class FillBezierCurve {
public:
    using Arguments = std::tuple<WebCore::PathDataBezierCurve>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillBezierCurve; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FillBezierCurve(const WebCore::PathDataBezierCurve& curve)
        : m_curve(curve)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_curve;
    }

private:
    const WebCore::PathDataBezierCurve& m_curve;
};
#endif

class FillPathSegment {
public:
    using Arguments = std::tuple<WebCore::PathSegment>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillPathSegment; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit FillPathSegment(const WebCore::PathSegment& segment)
        : m_segment(segment)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_segment;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PathSegment& m_segment;
};

class FillPath {
public:
    using Arguments = std::tuple<WebCore::Path>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillPath; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FillPath(const WebCore::Path& path)
        : m_path(path)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_path;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Path& m_path;
};

class FillEllipse {
public:
    using Arguments = std::tuple<WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_FillEllipse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit FillEllipse(const WebCore::FloatRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
};

class StrokeRect {
public:
    using Arguments = std::tuple<WebCore::FloatRect, float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokeRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    StrokeRect(const WebCore::FloatRect& rect, float lineWidth)
        : m_rect(rect)
        , m_lineWidth(lineWidth)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        encoder << m_lineWidth;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    float m_lineWidth;
};

#if ENABLE(INLINE_PATH_DATA)
class StrokeLine {
public:
    using Arguments = std::tuple<WebCore::PathDataLine>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokeLine; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit StrokeLine(const WebCore::PathDataLine& line)
        : m_line(line)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_line;
    }

private:
    const WebCore::PathDataLine& m_line;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class StrokeLineWithColorAndThickness {
public:
    using Arguments = std::tuple<WebCore::PathDataLine, std::optional<WebCore::PackedColor::RGBA>, std::optional<float>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokeLineWithColorAndThickness; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    StrokeLineWithColorAndThickness(const WebCore::PathDataLine& line, const std::optional<WebCore::PackedColor::RGBA>& strokeColor, const std::optional<float>& strokeThickness)
        : m_line(line)
        , m_strokeColor(strokeColor)
        , m_strokeThickness(strokeThickness)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_line;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_strokeColor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_strokeThickness;
    }

private:
    const WebCore::PathDataLine& m_line;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PackedColor::RGBA>& m_strokeColor;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<float>& m_strokeThickness;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class StrokeArc {
public:
    using Arguments = std::tuple<WebCore::PathArc>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokeArc; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit StrokeArc(const WebCore::PathArc& arc)
        : m_arc(arc)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arc;
    }

private:
    const WebCore::PathArc& m_arc;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class StrokeClosedArc {
public:
    using Arguments = std::tuple<WebCore::PathClosedArc>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokeClosedArc; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit StrokeClosedArc(const WebCore::PathClosedArc& closedArc)
        : m_closedArc(closedArc)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_closedArc;
    }

private:
    const WebCore::PathClosedArc& m_closedArc;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class StrokeQuadCurve {
public:
    using Arguments = std::tuple<WebCore::PathDataQuadCurve>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokeQuadCurve; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit StrokeQuadCurve(const WebCore::PathDataQuadCurve& curve)
        : m_curve(curve)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_curve;
    }

private:
    const WebCore::PathDataQuadCurve& m_curve;
};
#endif

#if ENABLE(INLINE_PATH_DATA)
class StrokeBezierCurve {
public:
    using Arguments = std::tuple<WebCore::PathDataBezierCurve>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokeBezierCurve; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit StrokeBezierCurve(const WebCore::PathDataBezierCurve& curve)
        : m_curve(curve)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_curve;
    }

private:
    const WebCore::PathDataBezierCurve& m_curve;
};
#endif

class StrokePathSegment {
public:
    using Arguments = std::tuple<WebCore::PathSegment>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokePathSegment; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit StrokePathSegment(const WebCore::PathSegment& segment)
        : m_segment(segment)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_segment;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PathSegment& m_segment;
};

class StrokePath {
public:
    using Arguments = std::tuple<WebCore::Path>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokePath; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit StrokePath(const WebCore::Path& path)
        : m_path(path)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_path;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Path& m_path;
};

class StrokeEllipse {
public:
    using Arguments = std::tuple<WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_StrokeEllipse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = true;

    explicit StrokeEllipse(const WebCore::FloatRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
};

class ClearRect {
public:
    using Arguments = std::tuple<WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ClearRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ClearRect(const WebCore::FloatRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
};

class DrawControlPart {
public:
    using Arguments = std::tuple<Ref<WebCore::ControlPart>, WebCore::FloatRoundedRect, float, WebCore::ControlStyle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawControlPart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    DrawControlPart(const Ref<WebCore::ControlPart>& part, const WebCore::FloatRoundedRect& borderRect, float deviceScaleFactor, const WebCore::ControlStyle& style)
        : m_part(part)
        , m_borderRect(borderRect)
        , m_deviceScaleFactor(deviceScaleFactor)
        , m_style(style)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_part;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_borderRect;
        encoder << m_deviceScaleFactor;
        encoder << m_style;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::ControlPart>& m_part;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRoundedRect& m_borderRect;
    float m_deviceScaleFactor;
    const WebCore::ControlStyle& m_style;
};

#if USE(CG)
class ApplyStrokePattern {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ApplyStrokePattern; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ApplyStrokePattern()
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

#if USE(CG)
class ApplyFillPattern {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ApplyFillPattern; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    ApplyFillPattern()
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

class ApplyDeviceScaleFactor {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_ApplyDeviceScaleFactor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit ApplyDeviceScaleFactor(float scaleFactor)
        : m_scaleFactor(scaleFactor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scaleFactor;
    }

private:
    float m_scaleFactor;
};

class BeginPage {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_BeginPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit BeginPage(const WebCore::IntSize& pageSize)
        : m_pageSize(pageSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_pageSize;
};

class EndPage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_EndPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    EndPage()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetURLForRect {
public:
    using Arguments = std::tuple<URL, WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetURLForRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    SetURLForRect(const URL& link, const WebCore::FloatRect& destRect)
        : m_link(link)
        , m_destRect(destRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_link;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_link;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_destRect;
};

#if PLATFORM(COCOA) && ENABLE(VIDEO)
class DrawVideoFrame {
public:
    using Arguments = std::tuple<WebKit::SharedVideoFrame, WebCore::FloatRect, WebCore::ImageOrientation, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_DrawVideoFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    DrawVideoFrame(WebKit::SharedVideoFrame&& frame, const WebCore::FloatRect& rect, const WebCore::ImageOrientation& orientation, bool shouldDiscardAlpha)
        : m_frame(WTFMove(frame))
        , m_rect(rect)
        , m_orientation(orientation)
        , m_shouldDiscardAlpha(shouldDiscardAlpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_frame);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_orientation;
        encoder << m_shouldDiscardAlpha;
    }

private:
    WebKit::SharedVideoFrame&& m_frame;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ImageOrientation& m_orientation;
    bool m_shouldDiscardAlpha;
};
#endif

#if PLATFORM(COCOA) && ENABLE(VIDEO)
class SetSharedVideoFrameSemaphore {
public:
    using Arguments = std::tuple<IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetSharedVideoFrameSemaphore; }
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

#if PLATFORM(COCOA) && ENABLE(VIDEO)
class SetSharedVideoFrameMemory {
public:
    using Arguments = std::tuple<WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDisplayListRecorder_SetSharedVideoFrameMemory; }
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

} // namespace RemoteDisplayListRecorder
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
