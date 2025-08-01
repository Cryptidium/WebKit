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

#include "config.h"
#if ENABLE(GPU_PROCESS)
#include "RemoteDisplayListRecorder.h"

#include "ArgumentCoders.h" // NOLINT
#include "ArrayReferenceTuple.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if PLATFORM(COCOA) && ENABLE(VIDEO)
#include "IPCSemaphore.h" // NOLINT
#endif
#include "RemoteDisplayListRecorderMessages.h" // NOLINT
#if PLATFORM(COCOA) && ENABLE(VIDEO)
#include "SharedVideoFrame.h" // NOLINT
#endif
#include <WebCore/AffineTransform.h> // NOLINT
#include <WebCore/Color.h> // NOLINT
#include <WebCore/ColorTypes.h> // NOLINT
#include <WebCore/ControlPart.h> // NOLINT
#include <WebCore/ControlStyle.h> // NOLINT
#include <WebCore/Filter.h> // NOLINT
#include <WebCore/FloatPoint.h> // NOLINT
#include <WebCore/FloatRect.h> // NOLINT
#include <WebCore/FloatRoundedRect.h> // NOLINT
#include <WebCore/FloatSegment.h> // NOLINT
#include <WebCore/FloatSize.h> // NOLINT
#include <WebCore/GlyphBufferMembers.h> // NOLINT
#include <WebCore/Gradient.h> // NOLINT
#include <WebCore/GraphicsContext.h> // NOLINT
#include <WebCore/GraphicsStyle.h> // NOLINT
#include <WebCore/GraphicsTypes.h> // NOLINT
#if PLATFORM(COCOA) && ENABLE(VIDEO)
#include <WebCore/ImageOrientation.h> // NOLINT
#endif
#include <WebCore/ImagePaintingOptions.h> // NOLINT
#include <WebCore/IntSize.h> // NOLINT
#include <WebCore/Path.h> // NOLINT
#include <WebCore/PathSegment.h> // NOLINT
#if ENABLE(INLINE_PATH_DATA)
#include <WebCore/PathSegmentData.h> // NOLINT
#endif
#include <WebCore/Pattern.h> // NOLINT
#include <WebCore/RenderingResourceIdentifier.h> // NOLINT
#if PLATFORM(COCOA) && ENABLE(VIDEO)
#include <WebCore/SharedMemory.h> // NOLINT
#endif
#include <WebCore/SystemImage.h> // NOLINT
#include <WebCore/WindRule.h> // NOLINT
#include <optional> // NOLINT
#include <span> // NOLINT
#include <wtf/FixedVector.h> // NOLINT
#include <wtf/Ref.h> // NOLINT
#include <wtf/URLHash.h> // NOLINT
#include <wtf/Vector.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteDisplayListRecorder::didReceiveStreamMessage(IPC::StreamServerConnection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::Save::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::Save>(connection, decoder, this, &RemoteDisplayListRecorder::save);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::Restore::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::Restore>(connection, decoder, this, &RemoteDisplayListRecorder::restore);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::Translate::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::Translate>(connection, decoder, this, &RemoteDisplayListRecorder::translate);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::Rotate::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::Rotate>(connection, decoder, this, &RemoteDisplayListRecorder::rotate);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::Scale::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::Scale>(connection, decoder, this, &RemoteDisplayListRecorder::scale);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetCTM::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetCTM>(connection, decoder, this, &RemoteDisplayListRecorder::setCTM);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ConcatCTM::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ConcatCTM>(connection, decoder, this, &RemoteDisplayListRecorder::concatCTM);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetFillPackedColor::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetFillPackedColor>(connection, decoder, this, &RemoteDisplayListRecorder::setFillPackedColor);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetFillColor::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetFillColor>(connection, decoder, this, &RemoteDisplayListRecorder::setFillColor);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetFillCachedGradient::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetFillCachedGradient>(connection, decoder, this, &RemoteDisplayListRecorder::setFillCachedGradient);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetFillGradient::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetFillGradient>(connection, decoder, this, &RemoteDisplayListRecorder::setFillGradient);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetFillPattern::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetFillPattern>(connection, decoder, this, &RemoteDisplayListRecorder::setFillPattern);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetFillRule::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetFillRule>(connection, decoder, this, &RemoteDisplayListRecorder::setFillRule);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStrokePackedColor::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStrokePackedColor>(connection, decoder, this, &RemoteDisplayListRecorder::setStrokePackedColor);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStrokeColor::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStrokeColor>(connection, decoder, this, &RemoteDisplayListRecorder::setStrokeColor);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStrokeCachedGradient::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStrokeCachedGradient>(connection, decoder, this, &RemoteDisplayListRecorder::setStrokeCachedGradient);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStrokeGradient::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStrokeGradient>(connection, decoder, this, &RemoteDisplayListRecorder::setStrokeGradient);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStrokePattern::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStrokePattern>(connection, decoder, this, &RemoteDisplayListRecorder::setStrokePattern);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStrokePackedColorAndThickness::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStrokePackedColorAndThickness>(connection, decoder, this, &RemoteDisplayListRecorder::setStrokePackedColorAndThickness);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStrokeThickness::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStrokeThickness>(connection, decoder, this, &RemoteDisplayListRecorder::setStrokeThickness);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStrokeStyle::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStrokeStyle>(connection, decoder, this, &RemoteDisplayListRecorder::setStrokeStyle);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetCompositeMode::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetCompositeMode>(connection, decoder, this, &RemoteDisplayListRecorder::setCompositeMode);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetDropShadow::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetDropShadow>(connection, decoder, this, &RemoteDisplayListRecorder::setDropShadow);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetStyle::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetStyle>(connection, decoder, this, &RemoteDisplayListRecorder::setStyle);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetAlpha::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetAlpha>(connection, decoder, this, &RemoteDisplayListRecorder::setAlpha);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetTextDrawingMode::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetTextDrawingMode>(connection, decoder, this, &RemoteDisplayListRecorder::setTextDrawingMode);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetImageInterpolationQuality::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetImageInterpolationQuality>(connection, decoder, this, &RemoteDisplayListRecorder::setImageInterpolationQuality);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetShouldAntialias::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetShouldAntialias>(connection, decoder, this, &RemoteDisplayListRecorder::setShouldAntialias);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetShouldSmoothFonts::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetShouldSmoothFonts>(connection, decoder, this, &RemoteDisplayListRecorder::setShouldSmoothFonts);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetShouldSubpixelQuantizeFonts::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetShouldSubpixelQuantizeFonts>(connection, decoder, this, &RemoteDisplayListRecorder::setShouldSubpixelQuantizeFonts);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetShadowsIgnoreTransforms::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetShadowsIgnoreTransforms>(connection, decoder, this, &RemoteDisplayListRecorder::setShadowsIgnoreTransforms);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetDrawLuminanceMask::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetDrawLuminanceMask>(connection, decoder, this, &RemoteDisplayListRecorder::setDrawLuminanceMask);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetLineCap::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetLineCap>(connection, decoder, this, &RemoteDisplayListRecorder::setLineCap);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetLineDash::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetLineDash>(connection, decoder, this, &RemoteDisplayListRecorder::setLineDash);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetLineJoin::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetLineJoin>(connection, decoder, this, &RemoteDisplayListRecorder::setLineJoin);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetMiterLimit::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetMiterLimit>(connection, decoder, this, &RemoteDisplayListRecorder::setMiterLimit);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::Clip::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::Clip>(connection, decoder, this, &RemoteDisplayListRecorder::clip);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ClipRoundedRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ClipRoundedRect>(connection, decoder, this, &RemoteDisplayListRecorder::clipRoundedRect);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ClipOut::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ClipOut>(connection, decoder, this, &RemoteDisplayListRecorder::clipOut);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ClipOutRoundedRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ClipOutRoundedRect>(connection, decoder, this, &RemoteDisplayListRecorder::clipOutRoundedRect);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ClipToImageBuffer::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ClipToImageBuffer>(connection, decoder, this, &RemoteDisplayListRecorder::clipToImageBuffer);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ClipOutToPath::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ClipOutToPath>(connection, decoder, this, &RemoteDisplayListRecorder::clipOutToPath);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ClipPath::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ClipPath>(connection, decoder, this, &RemoteDisplayListRecorder::clipPath);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ResetClip::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ResetClip>(connection, decoder, this, &RemoteDisplayListRecorder::resetClip);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawGlyphs::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawGlyphs>(connection, decoder, this, &RemoteDisplayListRecorder::drawGlyphs);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawDecomposedGlyphs::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawDecomposedGlyphs>(connection, decoder, this, &RemoteDisplayListRecorder::drawDecomposedGlyphs);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawFilteredImageBuffer::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawFilteredImageBuffer>(connection, decoder, this, &RemoteDisplayListRecorder::drawFilteredImageBuffer);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawImageBuffer::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawImageBuffer>(connection, decoder, this, &RemoteDisplayListRecorder::drawImageBuffer);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawNativeImage::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawNativeImage>(connection, decoder, this, &RemoteDisplayListRecorder::drawNativeImage);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawSystemImage::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawSystemImage>(connection, decoder, this, &RemoteDisplayListRecorder::drawSystemImage);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawPatternNativeImage::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawPatternNativeImage>(connection, decoder, this, &RemoteDisplayListRecorder::drawPatternNativeImage);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawPatternImageBuffer::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawPatternImageBuffer>(connection, decoder, this, &RemoteDisplayListRecorder::drawPatternImageBuffer);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::BeginTransparencyLayer::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::BeginTransparencyLayer>(connection, decoder, this, &RemoteDisplayListRecorder::beginTransparencyLayer);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::BeginTransparencyLayerWithCompositeMode::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::BeginTransparencyLayerWithCompositeMode>(connection, decoder, this, &RemoteDisplayListRecorder::beginTransparencyLayerWithCompositeMode);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::EndTransparencyLayer::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::EndTransparencyLayer>(connection, decoder, this, &RemoteDisplayListRecorder::endTransparencyLayer);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawRect>(connection, decoder, this, &RemoteDisplayListRecorder::drawRect);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawLine::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawLine>(connection, decoder, this, &RemoteDisplayListRecorder::drawLine);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawLinesForText::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawLinesForText>(connection, decoder, this, &RemoteDisplayListRecorder::drawLinesForText);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawDotsForDocumentMarker::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawDotsForDocumentMarker>(connection, decoder, this, &RemoteDisplayListRecorder::drawDotsForDocumentMarker);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawEllipse::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawEllipse>(connection, decoder, this, &RemoteDisplayListRecorder::drawEllipse);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawPath::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawPath>(connection, decoder, this, &RemoteDisplayListRecorder::drawPath);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawFocusRingPath::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawFocusRingPath>(connection, decoder, this, &RemoteDisplayListRecorder::drawFocusRingPath);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawFocusRingRects::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawFocusRingRects>(connection, decoder, this, &RemoteDisplayListRecorder::drawFocusRingRects);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillRect>(connection, decoder, this, &RemoteDisplayListRecorder::fillRect);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillRectWithColor::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillRectWithColor>(connection, decoder, this, &RemoteDisplayListRecorder::fillRectWithColor);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillRectWithGradient::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillRectWithGradient>(connection, decoder, this, &RemoteDisplayListRecorder::fillRectWithGradient);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillRectWithGradientAndSpaceTransform::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillRectWithGradientAndSpaceTransform>(connection, decoder, this, &RemoteDisplayListRecorder::fillRectWithGradientAndSpaceTransform);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillCompositedRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillCompositedRect>(connection, decoder, this, &RemoteDisplayListRecorder::fillCompositedRect);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillRoundedRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillRoundedRect>(connection, decoder, this, &RemoteDisplayListRecorder::fillRoundedRect);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillRectWithRoundedHole::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillRectWithRoundedHole>(connection, decoder, this, &RemoteDisplayListRecorder::fillRectWithRoundedHole);
#if ENABLE(INLINE_PATH_DATA)
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillLine::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillLine>(connection, decoder, this, &RemoteDisplayListRecorder::fillLine);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillArc::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillArc>(connection, decoder, this, &RemoteDisplayListRecorder::fillArc);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillClosedArc::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillClosedArc>(connection, decoder, this, &RemoteDisplayListRecorder::fillClosedArc);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillQuadCurve::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillQuadCurve>(connection, decoder, this, &RemoteDisplayListRecorder::fillQuadCurve);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillBezierCurve::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillBezierCurve>(connection, decoder, this, &RemoteDisplayListRecorder::fillBezierCurve);
#endif
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillPathSegment::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillPathSegment>(connection, decoder, this, &RemoteDisplayListRecorder::fillPathSegment);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillPath::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillPath>(connection, decoder, this, &RemoteDisplayListRecorder::fillPath);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::FillEllipse::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::FillEllipse>(connection, decoder, this, &RemoteDisplayListRecorder::fillEllipse);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokeRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokeRect>(connection, decoder, this, &RemoteDisplayListRecorder::strokeRect);
#if ENABLE(INLINE_PATH_DATA)
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokeLine::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokeLine>(connection, decoder, this, &RemoteDisplayListRecorder::strokeLine);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokeLineWithColorAndThickness::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokeLineWithColorAndThickness>(connection, decoder, this, &RemoteDisplayListRecorder::strokeLineWithColorAndThickness);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokeArc::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokeArc>(connection, decoder, this, &RemoteDisplayListRecorder::strokeArc);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokeClosedArc::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokeClosedArc>(connection, decoder, this, &RemoteDisplayListRecorder::strokeClosedArc);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokeQuadCurve::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokeQuadCurve>(connection, decoder, this, &RemoteDisplayListRecorder::strokeQuadCurve);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokeBezierCurve::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokeBezierCurve>(connection, decoder, this, &RemoteDisplayListRecorder::strokeBezierCurve);
#endif
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokePathSegment::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokePathSegment>(connection, decoder, this, &RemoteDisplayListRecorder::strokePathSegment);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokePath::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokePath>(connection, decoder, this, &RemoteDisplayListRecorder::strokePath);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::StrokeEllipse::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::StrokeEllipse>(connection, decoder, this, &RemoteDisplayListRecorder::strokeEllipse);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ClearRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ClearRect>(connection, decoder, this, &RemoteDisplayListRecorder::clearRect);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawControlPart::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawControlPart>(connection, decoder, this, &RemoteDisplayListRecorder::drawControlPart);
#if USE(CG)
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ApplyStrokePattern::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ApplyStrokePattern>(connection, decoder, this, &RemoteDisplayListRecorder::applyStrokePattern);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ApplyFillPattern::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ApplyFillPattern>(connection, decoder, this, &RemoteDisplayListRecorder::applyFillPattern);
#endif
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::ApplyDeviceScaleFactor::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::ApplyDeviceScaleFactor>(connection, decoder, this, &RemoteDisplayListRecorder::applyDeviceScaleFactor);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::BeginPage::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::BeginPage>(connection, decoder, this, &RemoteDisplayListRecorder::beginPage);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::EndPage::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::EndPage>(connection, decoder, this, &RemoteDisplayListRecorder::endPage);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetURLForRect::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetURLForRect>(connection, decoder, this, &RemoteDisplayListRecorder::setURLForRect);
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::DrawVideoFrame::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::DrawVideoFrame>(connection, decoder, this, &RemoteDisplayListRecorder::drawVideoFrame);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetSharedVideoFrameSemaphore::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetSharedVideoFrameSemaphore>(connection, decoder, this, &RemoteDisplayListRecorder::setSharedVideoFrameSemaphore);
    if (decoder.messageName() == Messages::RemoteDisplayListRecorder::SetSharedVideoFrameMemory::name())
        return IPC::handleMessage<Messages::RemoteDisplayListRecorder::SetSharedVideoFrameMemory>(connection, decoder, this, &RemoteDisplayListRecorder::setSharedVideoFrameMemory);
#endif
    RELEASE_LOG_ERROR(IPC, "Unhandled stream message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_Save>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::Save::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_Restore>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::Restore::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_Translate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::Translate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_Rotate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::Rotate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_Scale>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::Scale::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetCTM>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetCTM::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ConcatCTM>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ConcatCTM::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetFillPackedColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetFillPackedColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetFillColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetFillColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetFillCachedGradient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetFillCachedGradient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetFillGradient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetFillGradient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetFillPattern>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetFillPattern::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetFillRule>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetFillRule::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStrokePackedColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStrokePackedColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStrokeColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStrokeColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStrokeCachedGradient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStrokeCachedGradient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStrokeGradient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStrokeGradient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStrokePattern>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStrokePattern::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStrokePackedColorAndThickness>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStrokePackedColorAndThickness::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStrokeThickness>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStrokeThickness::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStrokeStyle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStrokeStyle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetCompositeMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetCompositeMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetDropShadow>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetDropShadow::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetStyle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetStyle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetAlpha>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetAlpha::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetTextDrawingMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetTextDrawingMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetImageInterpolationQuality>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetImageInterpolationQuality::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetShouldAntialias>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetShouldAntialias::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetShouldSmoothFonts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetShouldSmoothFonts::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetShouldSubpixelQuantizeFonts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetShouldSubpixelQuantizeFonts::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetShadowsIgnoreTransforms>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetShadowsIgnoreTransforms::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetDrawLuminanceMask>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetDrawLuminanceMask::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetLineCap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetLineCap::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetLineDash>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetLineDash::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetLineJoin>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetLineJoin::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetMiterLimit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetMiterLimit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_Clip>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::Clip::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ClipRoundedRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ClipRoundedRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ClipOut>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ClipOut::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ClipOutRoundedRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ClipOutRoundedRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ClipToImageBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ClipToImageBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ClipOutToPath>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ClipOutToPath::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ClipPath>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ClipPath::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ResetClip>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ResetClip::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawGlyphs>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawGlyphs::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawDecomposedGlyphs>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawDecomposedGlyphs::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawFilteredImageBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawFilteredImageBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawImageBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawImageBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawNativeImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawNativeImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawSystemImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawSystemImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawPatternNativeImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawPatternNativeImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawPatternImageBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawPatternImageBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_BeginTransparencyLayer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::BeginTransparencyLayer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_BeginTransparencyLayerWithCompositeMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::BeginTransparencyLayerWithCompositeMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_EndTransparencyLayer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::EndTransparencyLayer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawLine>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawLine::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawLinesForText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawLinesForText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawDotsForDocumentMarker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawDotsForDocumentMarker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawEllipse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawEllipse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawPath>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawPath::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawFocusRingPath>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawFocusRingPath::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawFocusRingRects>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawFocusRingRects::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillRectWithColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillRectWithColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillRectWithGradient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillRectWithGradient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillRectWithGradientAndSpaceTransform>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillRectWithGradientAndSpaceTransform::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillCompositedRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillCompositedRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillRoundedRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillRoundedRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillRectWithRoundedHole>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillRectWithRoundedHole::Arguments>(globalObject, decoder);
}
#if ENABLE(INLINE_PATH_DATA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillLine>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillLine::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillArc>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillArc::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillClosedArc>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillClosedArc::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillQuadCurve>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillQuadCurve::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillBezierCurve>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillBezierCurve::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillPathSegment>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillPathSegment::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillPath>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillPath::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_FillEllipse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::FillEllipse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokeRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokeRect::Arguments>(globalObject, decoder);
}
#if ENABLE(INLINE_PATH_DATA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokeLine>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokeLine::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokeLineWithColorAndThickness>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokeLineWithColorAndThickness::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokeArc>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokeArc::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokeClosedArc>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokeClosedArc::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokeQuadCurve>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokeQuadCurve::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokeBezierCurve>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokeBezierCurve::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokePathSegment>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokePathSegment::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokePath>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokePath::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_StrokeEllipse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::StrokeEllipse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ClearRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ClearRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawControlPart>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawControlPart::Arguments>(globalObject, decoder);
}
#if USE(CG)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ApplyStrokePattern>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ApplyStrokePattern::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ApplyFillPattern>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ApplyFillPattern::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_ApplyDeviceScaleFactor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::ApplyDeviceScaleFactor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_BeginPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::BeginPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_EndPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::EndPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetURLForRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetURLForRect::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA) && ENABLE(VIDEO)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_DrawVideoFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::DrawVideoFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetSharedVideoFrameSemaphore>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetSharedVideoFrameSemaphore::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDisplayListRecorder_SetSharedVideoFrameMemory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDisplayListRecorder::SetSharedVideoFrameMemory::Arguments>(globalObject, decoder);
}
#endif

}

#endif


#endif // ENABLE(GPU_PROCESS)
