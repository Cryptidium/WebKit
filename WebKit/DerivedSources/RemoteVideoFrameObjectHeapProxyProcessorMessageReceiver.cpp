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
#if PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
#include "RemoteVideoFrameObjectHeapProxyProcessor.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "IPCSemaphore.h" // NOLINT
#include "RemoteVideoFrameIdentifier.h" // NOLINT
#include "RemoteVideoFrameObjectHeapProxyProcessorMessages.h" // NOLINT
#include "SharedVideoFrame.h" // NOLINT
#include <WebCore/SharedMemory.h> // NOLINT
#include <optional> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteVideoFrameObjectHeapProxyProcessor::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteVideoFrameObjectHeapProxyProcessor::SetSharedVideoFrameSemaphore::name())
        return IPC::handleMessage<Messages::RemoteVideoFrameObjectHeapProxyProcessor::SetSharedVideoFrameSemaphore>(connection, decoder, this, &RemoteVideoFrameObjectHeapProxyProcessor::setSharedVideoFrameSemaphore);
    if (decoder.messageName() == Messages::RemoteVideoFrameObjectHeapProxyProcessor::SetSharedVideoFrameMemory::name())
        return IPC::handleMessage<Messages::RemoteVideoFrameObjectHeapProxyProcessor::SetSharedVideoFrameMemory>(connection, decoder, this, &RemoteVideoFrameObjectHeapProxyProcessor::setSharedVideoFrameMemory);
    if (decoder.messageName() == Messages::RemoteVideoFrameObjectHeapProxyProcessor::NewVideoFrameBuffer::name())
        return IPC::handleMessage<Messages::RemoteVideoFrameObjectHeapProxyProcessor::NewVideoFrameBuffer>(connection, decoder, this, &RemoteVideoFrameObjectHeapProxyProcessor::newVideoFrameBuffer);
    if (decoder.messageName() == Messages::RemoteVideoFrameObjectHeapProxyProcessor::NewConvertedVideoFrameBuffer::name())
        return IPC::handleMessage<Messages::RemoteVideoFrameObjectHeapProxyProcessor::NewConvertedVideoFrameBuffer>(connection, decoder, this, &RemoteVideoFrameObjectHeapProxyProcessor::newConvertedVideoFrameBuffer);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteVideoFrameObjectHeapProxyProcessor_SetSharedVideoFrameSemaphore>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteVideoFrameObjectHeapProxyProcessor::SetSharedVideoFrameSemaphore::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteVideoFrameObjectHeapProxyProcessor_SetSharedVideoFrameMemory>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteVideoFrameObjectHeapProxyProcessor::SetSharedVideoFrameMemory::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteVideoFrameObjectHeapProxyProcessor_NewVideoFrameBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteVideoFrameObjectHeapProxyProcessor::NewVideoFrameBuffer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteVideoFrameObjectHeapProxyProcessor_NewConvertedVideoFrameBuffer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteVideoFrameObjectHeapProxyProcessor::NewConvertedVideoFrameBuffer::Arguments>(globalObject, decoder);
}

}

#endif


#endif // PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
