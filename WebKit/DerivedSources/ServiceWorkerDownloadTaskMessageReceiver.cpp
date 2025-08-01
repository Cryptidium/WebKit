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
#include "ServiceWorkerDownloadTask.h"

#include "Decoder.h" // NOLINT
#include "FormDataReference.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "ServiceWorkerDownloadTaskMessages.h" // NOLINT
#include "SharedBufferReference.h" // NOLINT
#include <WebCore/ResourceError.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void ServiceWorkerDownloadTask::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::ServiceWorkerDownloadTask::DidFail::name())
        return IPC::handleMessage<Messages::ServiceWorkerDownloadTask::DidFail>(connection, decoder, this, &ServiceWorkerDownloadTask::didFail);
    if (decoder.messageName() == Messages::ServiceWorkerDownloadTask::DidReceiveData::name())
        return IPC::handleMessage<Messages::ServiceWorkerDownloadTask::DidReceiveData>(connection, decoder, this, &ServiceWorkerDownloadTask::didReceiveData);
    if (decoder.messageName() == Messages::ServiceWorkerDownloadTask::DidReceiveFormData::name())
        return IPC::handleMessage<Messages::ServiceWorkerDownloadTask::DidReceiveFormData>(connection, decoder, this, &ServiceWorkerDownloadTask::didReceiveFormData);
    if (decoder.messageName() == Messages::ServiceWorkerDownloadTask::DidFinish::name())
        return IPC::handleMessage<Messages::ServiceWorkerDownloadTask::DidFinish>(connection, decoder, this, &ServiceWorkerDownloadTask::didFinish);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ServiceWorkerDownloadTask_DidFail>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ServiceWorkerDownloadTask::DidFail::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ServiceWorkerDownloadTask_DidReceiveData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ServiceWorkerDownloadTask::DidReceiveData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ServiceWorkerDownloadTask_DidReceiveFormData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ServiceWorkerDownloadTask::DidReceiveFormData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ServiceWorkerDownloadTask_DidFinish>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ServiceWorkerDownloadTask::DidFinish::Arguments>(globalObject, decoder);
}

}

#endif

