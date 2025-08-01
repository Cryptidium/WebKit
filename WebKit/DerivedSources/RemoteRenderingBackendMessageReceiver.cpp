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
#include "RemoteRenderingBackend.h"

#include "ArgumentCoders.h" // NOLINT
#include "ArrayReferenceTuple.h" // NOLINT
#include "BufferIdentifierSet.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if USE(GRAPHICS_LAYER_WC)
#include "IPCSemaphore.h" // NOLINT
#endif
#include "MarkSurfacesAsVolatileRequestIdentifier.h" // NOLINT
#if PLATFORM(COCOA)
#include "PrepareBackingStoreBuffersData.h" // NOLINT
#endif
#include "RemoteDisplayListRecorderIdentifier.h" // NOLINT
#include "RemoteImageBufferSetIdentifier.h" // NOLINT
#include "RemoteRenderingBackendMessages.h" // NOLINT
#include "RemoteSerializedImageBufferIdentifier.h" // NOLINT
#include "RenderingUpdateID.h" // NOLINT
#include "ShapeDetectionIdentifier.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#if PLATFORM(COCOA)
#include "SwapBuffersDisplayRequirement.h" // NOLINT
#endif
#include <WebCore/BarcodeDetectorOptionsInterface.h> // NOLINT
#include <WebCore/BarcodeFormatInterface.h> // NOLINT
#include <WebCore/DestinationColorSpace.h> // NOLINT
#include <WebCore/FaceDetectorOptionsInterface.h> // NOLINT
#include <WebCore/Filter.h> // NOLINT
#include <WebCore/FloatPoint.h> // NOLINT
#include <WebCore/FloatSize.h> // NOLINT
#include <WebCore/Font.h> // NOLINT
#include <WebCore/FontCustomPlatformData.h> // NOLINT
#include <WebCore/FontPlatformData.h> // NOLINT
#include <WebCore/GlyphBufferMembers.h> // NOLINT
#include <WebCore/Gradient.h> // NOLINT
#include <WebCore/GraphicsTypes.h> // NOLINT
#include <WebCore/ImageBufferFormat.h> // NOLINT
#include <WebCore/ImageBufferResourceLimits.h> // NOLINT
#if PLATFORM(COCOA)
#include <WebCore/PageIdentifier.h> // NOLINT
#endif
#include <WebCore/RenderingMode.h> // NOLINT
#include <WebCore/RenderingResourceIdentifier.h> // NOLINT
#include <WebCore/ShareableBitmapHandle.h> // NOLINT
#if PLATFORM(COCOA)
#include <WebCore/SnapshotIdentifier.h> // NOLINT
#endif
#include <optional> // NOLINT
#include <utility> // NOLINT
#include <wtf/OptionSet.h> // NOLINT
#include <wtf/Ref.h> // NOLINT
#include <wtf/Vector.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteRenderingBackend::didReceiveStreamMessage(IPC::StreamServerConnection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CreateImageBuffer::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CreateImageBuffer>(connection, decoder, this, &RemoteRenderingBackend::createImageBuffer);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseImageBuffer::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseImageBuffer>(connection, decoder, this, &RemoteRenderingBackend::releaseImageBuffer);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::GetImageBufferResourceLimitsForTesting::name())
        return IPC::handleMessageAsync<Messages::RemoteRenderingBackend::GetImageBufferResourceLimitsForTesting>(connection, decoder, this, &RemoteRenderingBackend::getImageBufferResourceLimitsForTesting);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::DestroyGetPixelBufferSharedMemory::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::DestroyGetPixelBufferSharedMemory>(connection, decoder, this, &RemoteRenderingBackend::destroyGetPixelBufferSharedMemory);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CacheNativeImage::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CacheNativeImage>(connection, decoder, this, &RemoteRenderingBackend::cacheNativeImage);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseNativeImage::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseNativeImage>(connection, decoder, this, &RemoteRenderingBackend::releaseNativeImage);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CacheFont::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CacheFont>(connection, decoder, this, &RemoteRenderingBackend::cacheFont);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseFont::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseFont>(connection, decoder, this, &RemoteRenderingBackend::releaseFont);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CacheFontCustomPlatformData::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CacheFontCustomPlatformData>(connection, decoder, this, &RemoteRenderingBackend::cacheFontCustomPlatformData);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseFontCustomPlatformData::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseFontCustomPlatformData>(connection, decoder, this, &RemoteRenderingBackend::releaseFontCustomPlatformData);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CacheDecomposedGlyphs::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CacheDecomposedGlyphs>(connection, decoder, this, &RemoteRenderingBackend::cacheDecomposedGlyphs);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseDecomposedGlyphs::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseDecomposedGlyphs>(connection, decoder, this, &RemoteRenderingBackend::releaseDecomposedGlyphs);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CacheGradient::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CacheGradient>(connection, decoder, this, &RemoteRenderingBackend::cacheGradient);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseGradient::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseGradient>(connection, decoder, this, &RemoteRenderingBackend::releaseGradient);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CacheFilter::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CacheFilter>(connection, decoder, this, &RemoteRenderingBackend::cacheFilter);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseFilter::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseFilter>(connection, decoder, this, &RemoteRenderingBackend::releaseFilter);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseMemory::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseMemory>(connection, decoder, this, &RemoteRenderingBackend::releaseMemory);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseNativeImages::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseNativeImages>(connection, decoder, this, &RemoteRenderingBackend::releaseNativeImages);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CreateImageBufferSet::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CreateImageBufferSet>(connection, decoder, this, &RemoteRenderingBackend::createImageBufferSet);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseImageBufferSet::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseImageBufferSet>(connection, decoder, this, &RemoteRenderingBackend::releaseImageBufferSet);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::RemoteRenderingBackend::PrepareImageBufferSetsForDisplay::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::PrepareImageBufferSetsForDisplay>(connection, decoder, this, &RemoteRenderingBackend::prepareImageBufferSetsForDisplay);
#endif
    if (decoder.messageName() == Messages::RemoteRenderingBackend::MarkSurfacesVolatile::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::MarkSurfacesVolatile>(connection, decoder, this, &RemoteRenderingBackend::markSurfacesVolatile);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::FinalizeRenderingUpdate::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::FinalizeRenderingUpdate>(connection, decoder, this, &RemoteRenderingBackend::finalizeRenderingUpdate);
#if USE(GRAPHICS_LAYER_WC)
    if (decoder.messageName() == Messages::RemoteRenderingBackend::Flush::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::Flush>(connection, decoder, this, &RemoteRenderingBackend::flush);
#endif
    if (decoder.messageName() == Messages::RemoteRenderingBackend::MoveToSerializedBuffer::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::MoveToSerializedBuffer>(connection, decoder, this, &RemoteRenderingBackend::moveToSerializedBuffer);
    if (decoder.messageName() == Messages::RemoteRenderingBackend::MoveToImageBuffer::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::MoveToImageBuffer>(connection, decoder, this, &RemoteRenderingBackend::moveToImageBuffer);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::RemoteRenderingBackend::DidDrawRemoteToPDF::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackend::DidDrawRemoteToPDF>(connection, decoder, this, &RemoteRenderingBackend::didDrawRemoteToPDF);
#endif
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CreateRemoteBarcodeDetector::name()) {
        if (!(sharedPreferences && sharedPreferences->shapeDetection)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CreateRemoteBarcodeDetector>(connection, decoder, this, &RemoteRenderingBackend::createRemoteBarcodeDetector);
    }
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseRemoteBarcodeDetector::name()) {
        if (!(sharedPreferences && sharedPreferences->shapeDetection)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseRemoteBarcodeDetector>(connection, decoder, this, &RemoteRenderingBackend::releaseRemoteBarcodeDetector);
    }
    if (decoder.messageName() == Messages::RemoteRenderingBackend::GetRemoteBarcodeDetectorSupportedFormats::name()) {
        if (!(sharedPreferences && sharedPreferences->shapeDetection)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::RemoteRenderingBackend::GetRemoteBarcodeDetectorSupportedFormats>(connection, decoder, this, &RemoteRenderingBackend::getRemoteBarcodeDetectorSupportedFormats);
    }
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CreateRemoteFaceDetector::name()) {
        if (!(sharedPreferences && sharedPreferences->shapeDetection)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CreateRemoteFaceDetector>(connection, decoder, this, &RemoteRenderingBackend::createRemoteFaceDetector);
    }
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseRemoteFaceDetector::name()) {
        if (!(sharedPreferences && sharedPreferences->shapeDetection)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseRemoteFaceDetector>(connection, decoder, this, &RemoteRenderingBackend::releaseRemoteFaceDetector);
    }
    if (decoder.messageName() == Messages::RemoteRenderingBackend::CreateRemoteTextDetector::name()) {
        if (!(sharedPreferences && sharedPreferences->shapeDetection)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteRenderingBackend::CreateRemoteTextDetector>(connection, decoder, this, &RemoteRenderingBackend::createRemoteTextDetector);
    }
    if (decoder.messageName() == Messages::RemoteRenderingBackend::ReleaseRemoteTextDetector::name()) {
        if (!(sharedPreferences && sharedPreferences->shapeDetection)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteRenderingBackend::ReleaseRemoteTextDetector>(connection, decoder, this, &RemoteRenderingBackend::releaseRemoteTextDetector);
    }
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::RemoteRenderingBackend::PrepareImageBufferSetsForDisplaySync::name())
        return IPC::handleMessageSynchronous<Messages::RemoteRenderingBackend::PrepareImageBufferSetsForDisplaySync>(connection, decoder, this, &RemoteRenderingBackend::prepareImageBufferSetsForDisplaySync);
#endif
    RELEASE_LOG_ERROR(IPC, "Unhandled stream message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CreateImageBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CreateImageBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseImageBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseImageBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_GetImageBufferResourceLimitsForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::GetImageBufferResourceLimitsForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteRenderingBackend_GetImageBufferResourceLimitsForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::GetImageBufferResourceLimitsForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_DestroyGetPixelBufferSharedMemory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::DestroyGetPixelBufferSharedMemory::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CacheNativeImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CacheNativeImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseNativeImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseNativeImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CacheFont>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CacheFont::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseFont>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseFont::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CacheFontCustomPlatformData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CacheFontCustomPlatformData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseFontCustomPlatformData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseFontCustomPlatformData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CacheDecomposedGlyphs>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CacheDecomposedGlyphs::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseDecomposedGlyphs>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseDecomposedGlyphs::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CacheGradient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CacheGradient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseGradient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseGradient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CacheFilter>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CacheFilter::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseFilter>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseFilter::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseMemory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseMemory::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseNativeImages>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseNativeImages::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CreateImageBufferSet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CreateImageBufferSet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseImageBufferSet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseImageBufferSet::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_PrepareImageBufferSetsForDisplay>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::PrepareImageBufferSetsForDisplay::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_PrepareImageBufferSetsForDisplaySync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::PrepareImageBufferSetsForDisplaySync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteRenderingBackend_PrepareImageBufferSetsForDisplaySync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::PrepareImageBufferSetsForDisplaySync::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_MarkSurfacesVolatile>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::MarkSurfacesVolatile::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_FinalizeRenderingUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::FinalizeRenderingUpdate::Arguments>(globalObject, decoder);
}
#if USE(GRAPHICS_LAYER_WC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_Flush>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::Flush::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_MoveToSerializedBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::MoveToSerializedBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_MoveToImageBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::MoveToImageBuffer::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_DidDrawRemoteToPDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::DidDrawRemoteToPDF::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CreateRemoteBarcodeDetector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CreateRemoteBarcodeDetector::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseRemoteBarcodeDetector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseRemoteBarcodeDetector::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_GetRemoteBarcodeDetectorSupportedFormats>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::GetRemoteBarcodeDetectorSupportedFormats::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteRenderingBackend_GetRemoteBarcodeDetectorSupportedFormats>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::GetRemoteBarcodeDetectorSupportedFormats::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CreateRemoteFaceDetector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CreateRemoteFaceDetector::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseRemoteFaceDetector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseRemoteFaceDetector::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_CreateRemoteTextDetector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::CreateRemoteTextDetector::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackend_ReleaseRemoteTextDetector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackend::ReleaseRemoteTextDetector::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS)
