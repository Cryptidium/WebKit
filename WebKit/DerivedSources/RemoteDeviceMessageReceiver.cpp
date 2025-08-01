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
#include "RemoteDevice.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if PLATFORM(COCOA) && ENABLE(VIDEO)
#include "IPCSemaphore.h" // NOLINT
#endif
#include "RemoteDeviceMessages.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "WebGPUBindGroupDescriptor.h" // NOLINT
#include "WebGPUBindGroupLayoutDescriptor.h" // NOLINT
#include "WebGPUBufferDescriptor.h" // NOLINT
#include "WebGPUCommandEncoderDescriptor.h" // NOLINT
#include "WebGPUComputePipelineDescriptor.h" // NOLINT
#include "WebGPUError.h" // NOLINT
#if PLATFORM(COCOA) && ENABLE(VIDEO)
#include "WebGPUExternalTextureDescriptor.h" // NOLINT
#endif
#include "WebGPUIdentifier.h" // NOLINT
#include "WebGPUPipelineLayoutDescriptor.h" // NOLINT
#include "WebGPUQuerySetDescriptor.h" // NOLINT
#include "WebGPURenderBundleEncoderDescriptor.h" // NOLINT
#include "WebGPURenderPipelineDescriptor.h" // NOLINT
#include "WebGPUSamplerDescriptor.h" // NOLINT
#include "WebGPUShaderModuleDescriptor.h" // NOLINT
#include "WebGPUTextureDescriptor.h" // NOLINT
#if PLATFORM(COCOA) && ENABLE(VIDEO)
#include <WebCore/MediaPlayerIdentifier.h> // NOLINT
#endif
#if PLATFORM(COCOA) && ENABLE(VIDEO)
#include <WebCore/SharedMemory.h> // NOLINT
#endif
#include <WebCore/WebGPUDeviceLostReason.h> // NOLINT
#include <WebCore/WebGPUErrorFilter.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteDevice::didReceiveStreamMessage(IPC::StreamServerConnection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->webGPUEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteDevice", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteDevice::Destroy::name())
        return IPC::handleMessage<Messages::RemoteDevice::Destroy>(connection, decoder, this, &RemoteDevice::destroy);
    if (decoder.messageName() == Messages::RemoteDevice::Destruct::name())
        return IPC::handleMessage<Messages::RemoteDevice::Destruct>(connection, decoder, this, &RemoteDevice::destruct);
    if (decoder.messageName() == Messages::RemoteDevice::CreateXRBinding::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateXRBinding>(connection, decoder, this, &RemoteDevice::createXRBinding);
    if (decoder.messageName() == Messages::RemoteDevice::CreateBuffer::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateBuffer>(connection, decoder, this, &RemoteDevice::createBuffer);
    if (decoder.messageName() == Messages::RemoteDevice::CreateTexture::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateTexture>(connection, decoder, this, &RemoteDevice::createTexture);
    if (decoder.messageName() == Messages::RemoteDevice::CreateSampler::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateSampler>(connection, decoder, this, &RemoteDevice::createSampler);
    if (decoder.messageName() == Messages::RemoteDevice::CreateBindGroupLayout::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateBindGroupLayout>(connection, decoder, this, &RemoteDevice::createBindGroupLayout);
    if (decoder.messageName() == Messages::RemoteDevice::CreatePipelineLayout::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreatePipelineLayout>(connection, decoder, this, &RemoteDevice::createPipelineLayout);
    if (decoder.messageName() == Messages::RemoteDevice::CreateBindGroup::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateBindGroup>(connection, decoder, this, &RemoteDevice::createBindGroup);
    if (decoder.messageName() == Messages::RemoteDevice::CreateShaderModule::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateShaderModule>(connection, decoder, this, &RemoteDevice::createShaderModule);
    if (decoder.messageName() == Messages::RemoteDevice::CreateComputePipeline::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateComputePipeline>(connection, decoder, this, &RemoteDevice::createComputePipeline);
    if (decoder.messageName() == Messages::RemoteDevice::CreateRenderPipeline::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateRenderPipeline>(connection, decoder, this, &RemoteDevice::createRenderPipeline);
    if (decoder.messageName() == Messages::RemoteDevice::CreateComputePipelineAsync::name())
        return IPC::handleMessageAsync<Messages::RemoteDevice::CreateComputePipelineAsync>(connection, decoder, this, &RemoteDevice::createComputePipelineAsync);
    if (decoder.messageName() == Messages::RemoteDevice::CreateRenderPipelineAsync::name())
        return IPC::handleMessageAsync<Messages::RemoteDevice::CreateRenderPipelineAsync>(connection, decoder, this, &RemoteDevice::createRenderPipelineAsync);
    if (decoder.messageName() == Messages::RemoteDevice::CreateCommandEncoder::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateCommandEncoder>(connection, decoder, this, &RemoteDevice::createCommandEncoder);
    if (decoder.messageName() == Messages::RemoteDevice::CreateRenderBundleEncoder::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateRenderBundleEncoder>(connection, decoder, this, &RemoteDevice::createRenderBundleEncoder);
    if (decoder.messageName() == Messages::RemoteDevice::CreateQuerySet::name())
        return IPC::handleMessage<Messages::RemoteDevice::CreateQuerySet>(connection, decoder, this, &RemoteDevice::createQuerySet);
    if (decoder.messageName() == Messages::RemoteDevice::PushErrorScope::name())
        return IPC::handleMessage<Messages::RemoteDevice::PushErrorScope>(connection, decoder, this, &RemoteDevice::pushErrorScope);
    if (decoder.messageName() == Messages::RemoteDevice::PopErrorScope::name())
        return IPC::handleMessageAsync<Messages::RemoteDevice::PopErrorScope>(connection, decoder, this, &RemoteDevice::popErrorScope);
    if (decoder.messageName() == Messages::RemoteDevice::ResolveUncapturedErrorEvent::name())
        return IPC::handleMessageAsync<Messages::RemoteDevice::ResolveUncapturedErrorEvent>(connection, decoder, this, &RemoteDevice::resolveUncapturedErrorEvent);
    if (decoder.messageName() == Messages::RemoteDevice::ResolveDeviceLostPromise::name())
        return IPC::handleMessageAsync<Messages::RemoteDevice::ResolveDeviceLostPromise>(connection, decoder, this, &RemoteDevice::resolveDeviceLostPromise);
    if (decoder.messageName() == Messages::RemoteDevice::SetLabel::name())
        return IPC::handleMessage<Messages::RemoteDevice::SetLabel>(connection, decoder, this, &RemoteDevice::setLabel);
    if (decoder.messageName() == Messages::RemoteDevice::PauseAllErrorReporting::name())
        return IPC::handleMessage<Messages::RemoteDevice::PauseAllErrorReporting>(connection, decoder, this, &RemoteDevice::pauseAllErrorReporting);
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    if (decoder.messageName() == Messages::RemoteDevice::SetSharedVideoFrameSemaphore::name())
        return IPC::handleMessage<Messages::RemoteDevice::SetSharedVideoFrameSemaphore>(connection, decoder, this, &RemoteDevice::setSharedVideoFrameSemaphore);
    if (decoder.messageName() == Messages::RemoteDevice::SetSharedVideoFrameMemory::name())
        return IPC::handleMessage<Messages::RemoteDevice::SetSharedVideoFrameMemory>(connection, decoder, this, &RemoteDevice::setSharedVideoFrameMemory);
    if (decoder.messageName() == Messages::RemoteDevice::ImportExternalTextureFromVideoFrame::name())
        return IPC::handleMessage<Messages::RemoteDevice::ImportExternalTextureFromVideoFrame>(connection, decoder, this, &RemoteDevice::importExternalTextureFromVideoFrame);
    if (decoder.messageName() == Messages::RemoteDevice::UpdateExternalTexture::name())
        return IPC::handleMessage<Messages::RemoteDevice::UpdateExternalTexture>(connection, decoder, this, &RemoteDevice::updateExternalTexture);
#endif
    RELEASE_LOG_ERROR(IPC, "Unhandled stream message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_Destroy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::Destroy::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_Destruct>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::Destruct::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateXRBinding>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateXRBinding::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateTexture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateTexture::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateSampler>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateSampler::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateBindGroupLayout>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateBindGroupLayout::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreatePipelineLayout>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreatePipelineLayout::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateBindGroup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateBindGroup::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateShaderModule>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateShaderModule::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateComputePipeline>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateComputePipeline::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateRenderPipeline>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateRenderPipeline::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateComputePipelineAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateComputePipelineAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteDevice_CreateComputePipelineAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateComputePipelineAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateRenderPipelineAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateRenderPipelineAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteDevice_CreateRenderPipelineAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateRenderPipelineAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateCommandEncoder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateCommandEncoder::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateRenderBundleEncoder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateRenderBundleEncoder::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_CreateQuerySet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::CreateQuerySet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_PushErrorScope>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::PushErrorScope::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_PopErrorScope>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::PopErrorScope::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteDevice_PopErrorScope>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::PopErrorScope::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_ResolveUncapturedErrorEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::ResolveUncapturedErrorEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteDevice_ResolveUncapturedErrorEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::ResolveUncapturedErrorEvent::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_ResolveDeviceLostPromise>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::ResolveDeviceLostPromise::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteDevice_ResolveDeviceLostPromise>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::ResolveDeviceLostPromise::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_SetLabel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::SetLabel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_PauseAllErrorReporting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::PauseAllErrorReporting::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA) && ENABLE(VIDEO)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_SetSharedVideoFrameSemaphore>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::SetSharedVideoFrameSemaphore::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_SetSharedVideoFrameMemory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::SetSharedVideoFrameMemory::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_ImportExternalTextureFromVideoFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::ImportExternalTextureFromVideoFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteDevice_UpdateExternalTexture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteDevice::UpdateExternalTexture::Arguments>(globalObject, decoder);
}
#endif

}

#endif


#endif // ENABLE(GPU_PROCESS)
