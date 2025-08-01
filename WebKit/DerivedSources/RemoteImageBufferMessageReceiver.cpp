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
#include "RemoteImageBuffer.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "RemoteImageBufferMessages.h" // NOLINT
#include <WebCore/AlphaPremultiplication.h> // NOLINT
#include <WebCore/DestinationColorSpace.h> // NOLINT
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
#include <WebCore/DynamicContentScalingDisplayList.h> // NOLINT
#endif
#include <WebCore/Filter.h> // NOLINT
#include <WebCore/ImageBufferBackend.h> // NOLINT
#include <WebCore/IntPoint.h> // NOLINT
#include <WebCore/IntSize.h> // NOLINT
#include <WebCore/PixelBuffer.h> // NOLINT
#include <WebCore/PixelBufferFormat.h> // NOLINT
#include <WebCore/ShareableBitmapHandle.h> // NOLINT
#include <WebCore/SharedMemory.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/Ref.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteImageBuffer::didReceiveStreamMessage(IPC::StreamServerConnection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteImageBuffer::PutPixelBuffer::name())
        return IPC::handleMessage<Messages::RemoteImageBuffer::PutPixelBuffer>(connection, decoder, this, &RemoteImageBuffer::putPixelBuffer);
    if (decoder.messageName() == Messages::RemoteImageBuffer::ConvertToLuminanceMask::name())
        return IPC::handleMessage<Messages::RemoteImageBuffer::ConvertToLuminanceMask>(connection, decoder, this, &RemoteImageBuffer::convertToLuminanceMask);
    if (decoder.messageName() == Messages::RemoteImageBuffer::TransformToColorSpace::name())
        return IPC::handleMessage<Messages::RemoteImageBuffer::TransformToColorSpace>(connection, decoder, this, &RemoteImageBuffer::transformToColorSpace);
    if (decoder.messageName() == Messages::RemoteImageBuffer::FlushContext::name())
        return IPC::handleMessage<Messages::RemoteImageBuffer::FlushContext>(connection, decoder, this, &RemoteImageBuffer::flushContext);
    if (decoder.messageName() == Messages::RemoteImageBuffer::GetPixelBuffer::name())
        return IPC::handleMessageSynchronous<Messages::RemoteImageBuffer::GetPixelBuffer>(connection, decoder, this, &RemoteImageBuffer::getPixelBuffer);
    if (decoder.messageName() == Messages::RemoteImageBuffer::GetPixelBufferWithNewMemory::name())
        return IPC::handleMessageSynchronous<Messages::RemoteImageBuffer::GetPixelBufferWithNewMemory>(connection, decoder, this, &RemoteImageBuffer::getPixelBufferWithNewMemory);
    if (decoder.messageName() == Messages::RemoteImageBuffer::GetShareableBitmap::name())
        return IPC::handleMessageSynchronous<Messages::RemoteImageBuffer::GetShareableBitmap>(connection, decoder, this, &RemoteImageBuffer::getShareableBitmap);
    if (decoder.messageName() == Messages::RemoteImageBuffer::FilteredNativeImage::name())
        return IPC::handleMessageSynchronous<Messages::RemoteImageBuffer::FilteredNativeImage>(connection, decoder, this, &RemoteImageBuffer::filteredNativeImage);
    if (decoder.messageName() == Messages::RemoteImageBuffer::FlushContextSync::name())
        return IPC::handleMessageSynchronous<Messages::RemoteImageBuffer::FlushContextSync>(connection, decoder, this, &RemoteImageBuffer::flushContextSync);
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
    if (decoder.messageName() == Messages::RemoteImageBuffer::DynamicContentScalingDisplayList::name())
        return IPC::handleMessageSynchronous<Messages::RemoteImageBuffer::DynamicContentScalingDisplayList>(connection, decoder, this, &RemoteImageBuffer::dynamicContentScalingDisplayList);
#endif
    RELEASE_LOG_ERROR(IPC, "Unhandled stream message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_GetPixelBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::GetPixelBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteImageBuffer_GetPixelBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::GetPixelBuffer::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_GetPixelBufferWithNewMemory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::GetPixelBufferWithNewMemory::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteImageBuffer_GetPixelBufferWithNewMemory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::GetPixelBufferWithNewMemory::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_PutPixelBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::PutPixelBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_GetShareableBitmap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::GetShareableBitmap::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteImageBuffer_GetShareableBitmap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::GetShareableBitmap::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_FilteredNativeImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::FilteredNativeImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteImageBuffer_FilteredNativeImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::FilteredNativeImage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_ConvertToLuminanceMask>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::ConvertToLuminanceMask::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_TransformToColorSpace>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::TransformToColorSpace::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_FlushContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::FlushContext::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_FlushContextSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::FlushContextSync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteImageBuffer_FlushContextSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::FlushContextSync::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteImageBuffer_DynamicContentScalingDisplayList>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::DynamicContentScalingDisplayList::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteImageBuffer_DynamicContentScalingDisplayList>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteImageBuffer::DynamicContentScalingDisplayList::ReplyArguments>(globalObject, decoder);
}
#endif

}

#endif


#endif // ENABLE(GPU_PROCESS)
