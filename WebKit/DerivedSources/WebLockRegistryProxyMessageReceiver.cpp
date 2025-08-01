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
#include "WebLockRegistryProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "WebLockRegistryProxyMessages.h" // NOLINT
#include <WebCore/ClientOrigin.h> // NOLINT
#include <WebCore/ProcessQualified.h> // NOLINT
#include <WebCore/ScriptExecutionContextIdentifier.h> // NOLINT
#include <WebCore/WebLockIdentifier.h> // NOLINT
#include <WebCore/WebLockManagerSnapshot.h> // NOLINT
#include <WebCore/WebLockMode.h> // NOLINT
#include <wtf/ObjectIdentifier.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebLockRegistryProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->webLocksAPIEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver WebLockRegistryProxy", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebLockRegistryProxy::RequestLock::name())
        return IPC::handleMessage<Messages::WebLockRegistryProxy::RequestLock>(connection, decoder, this, &WebLockRegistryProxy::requestLock);
    if (decoder.messageName() == Messages::WebLockRegistryProxy::ReleaseLock::name())
        return IPC::handleMessage<Messages::WebLockRegistryProxy::ReleaseLock>(connection, decoder, this, &WebLockRegistryProxy::releaseLock);
    if (decoder.messageName() == Messages::WebLockRegistryProxy::AbortLockRequest::name())
        return IPC::handleMessageAsync<Messages::WebLockRegistryProxy::AbortLockRequest>(connection, decoder, this, &WebLockRegistryProxy::abortLockRequest);
    if (decoder.messageName() == Messages::WebLockRegistryProxy::Snapshot::name())
        return IPC::handleMessageAsync<Messages::WebLockRegistryProxy::Snapshot>(connection, decoder, this, &WebLockRegistryProxy::snapshot);
    if (decoder.messageName() == Messages::WebLockRegistryProxy::ClientIsGoingAway::name())
        return IPC::handleMessage<Messages::WebLockRegistryProxy::ClientIsGoingAway>(connection, decoder, this, &WebLockRegistryProxy::clientIsGoingAway);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebLockRegistryProxy_RequestLock>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebLockRegistryProxy::RequestLock::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebLockRegistryProxy_ReleaseLock>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebLockRegistryProxy::ReleaseLock::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebLockRegistryProxy_AbortLockRequest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebLockRegistryProxy::AbortLockRequest::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebLockRegistryProxy_AbortLockRequest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebLockRegistryProxy::AbortLockRequest::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebLockRegistryProxy_Snapshot>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebLockRegistryProxy::Snapshot::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebLockRegistryProxy_Snapshot>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebLockRegistryProxy::Snapshot::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebLockRegistryProxy_ClientIsGoingAway>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebLockRegistryProxy::ClientIsGoingAway::Arguments>(globalObject, decoder);
}

}

#endif

