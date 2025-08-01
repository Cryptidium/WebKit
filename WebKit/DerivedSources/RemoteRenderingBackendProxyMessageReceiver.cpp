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
#include "RemoteRenderingBackendProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "BufferIdentifierSet.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "IPCSemaphore.h" // NOLINT
#include "MarkSurfacesAsVolatileRequestIdentifier.h" // NOLINT
#include "RemoteImageBufferSetIdentifier.h" // NOLINT
#include "RemoteRenderingBackendProxyMessages.h" // NOLINT
#include "RenderingUpdateID.h" // NOLINT
#include <utility> // NOLINT
#include <wtf/OptionSet.h> // NOLINT
#include <wtf/Vector.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteRenderingBackendProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteRenderingBackendProxy::DidFinalizeRenderingUpdate::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackendProxy::DidFinalizeRenderingUpdate>(connection, decoder, this, &RemoteRenderingBackendProxy::didFinalizeRenderingUpdate);
    if (decoder.messageName() == Messages::RemoteRenderingBackendProxy::DidInitialize::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackendProxy::DidInitialize>(connection, decoder, this, &RemoteRenderingBackendProxy::didInitialize);
    if (decoder.messageName() == Messages::RemoteRenderingBackendProxy::DidMarkLayersAsVolatile::name())
        return IPC::handleMessage<Messages::RemoteRenderingBackendProxy::DidMarkLayersAsVolatile>(connection, decoder, this, &RemoteRenderingBackendProxy::didMarkLayersAsVolatile);
    if (dispatchMessage(connection, decoder))
        return;
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool RemoteRenderingBackendProxy::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(isInWebProcess());
    Ref protectedThis { *this };
    if (dispatchSyncMessage(connection, decoder, replyEncoder))
        return true;
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackendProxy_DidFinalizeRenderingUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackendProxy::DidFinalizeRenderingUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackendProxy_DidInitialize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackendProxy::DidInitialize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteRenderingBackendProxy_DidMarkLayersAsVolatile>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteRenderingBackendProxy::DidMarkLayersAsVolatile::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS)
