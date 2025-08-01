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
#include "WebSharedWorkerObjectConnection.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "WebSharedWorkerObjectConnectionMessages.h" // NOLINT
#include <WebCore/ResourceError.h> // NOLINT
#include <WebCore/SharedWorkerObjectIdentifier.h> // NOLINT
#include <WebCore/WorkerFetchResult.h> // NOLINT
#include <WebCore/WorkerInitializationData.h> // NOLINT
#include <WebCore/WorkerOptions.h> // NOLINT
#include <wtf/URLHash.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebSharedWorkerObjectConnection::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebSharedWorkerObjectConnection::FetchScriptInClient::name())
        return IPC::handleMessageAsync<Messages::WebSharedWorkerObjectConnection::FetchScriptInClient>(connection, decoder, this, &WebSharedWorkerObjectConnection::fetchScriptInClient);
    if (decoder.messageName() == Messages::WebSharedWorkerObjectConnection::NotifyWorkerObjectOfLoadCompletion::name())
        return IPC::handleMessage<Messages::WebSharedWorkerObjectConnection::NotifyWorkerObjectOfLoadCompletion>(connection, decoder, this, &WebSharedWorkerObjectConnection::notifyWorkerObjectOfLoadCompletion);
    if (decoder.messageName() == Messages::WebSharedWorkerObjectConnection::PostErrorToWorkerObject::name())
        return IPC::handleMessage<Messages::WebSharedWorkerObjectConnection::PostErrorToWorkerObject>(connection, decoder, this, &WebSharedWorkerObjectConnection::postErrorToWorkerObject);
#if ENABLE(CONTENT_EXTENSIONS)
    if (decoder.messageName() == Messages::WebSharedWorkerObjectConnection::ReportNetworkUsageToWorkerObject::name())
        return IPC::handleMessage<Messages::WebSharedWorkerObjectConnection::ReportNetworkUsageToWorkerObject>(connection, decoder, this, &WebSharedWorkerObjectConnection::reportNetworkUsageToWorkerObject);
#endif
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebSharedWorkerObjectConnection_FetchScriptInClient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebSharedWorkerObjectConnection::FetchScriptInClient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebSharedWorkerObjectConnection_FetchScriptInClient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebSharedWorkerObjectConnection::FetchScriptInClient::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebSharedWorkerObjectConnection_NotifyWorkerObjectOfLoadCompletion>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebSharedWorkerObjectConnection::NotifyWorkerObjectOfLoadCompletion::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebSharedWorkerObjectConnection_PostErrorToWorkerObject>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebSharedWorkerObjectConnection::PostErrorToWorkerObject::Arguments>(globalObject, decoder);
}
#if ENABLE(CONTENT_EXTENSIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebSharedWorkerObjectConnection_ReportNetworkUsageToWorkerObject>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebSharedWorkerObjectConnection::ReportNetworkUsageToWorkerObject::Arguments>(globalObject, decoder);
}
#endif

}

#endif

