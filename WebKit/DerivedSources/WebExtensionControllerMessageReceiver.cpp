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
#if ENABLE(WK_WEB_EXTENSIONS)
#include "WebExtensionController.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "WebExtensionControllerMessages.h" // NOLINT
#include "WebExtensionFrameParameters.h" // NOLINT
#include "WebPageProxyIdentifier.h" // NOLINT
#include <wtf/WallTime.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebExtensionController::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebExtensionController::DidStartProvisionalLoadForFrame::name()) {
        if (!hasLoadedContexts(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::DidStartProvisionalLoadForFrame>(connection, decoder, this, &WebExtensionController::didStartProvisionalLoadForFrame);
    }
    if (decoder.messageName() == Messages::WebExtensionController::DidCommitLoadForFrame::name()) {
        if (!hasLoadedContexts(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::DidCommitLoadForFrame>(connection, decoder, this, &WebExtensionController::didCommitLoadForFrame);
    }
    if (decoder.messageName() == Messages::WebExtensionController::DidFinishLoadForFrame::name()) {
        if (!hasLoadedContexts(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::DidFinishLoadForFrame>(connection, decoder, this, &WebExtensionController::didFinishLoadForFrame);
    }
    if (decoder.messageName() == Messages::WebExtensionController::DidFailLoadForFrame::name()) {
        if (!hasLoadedContexts(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::DidFailLoadForFrame>(connection, decoder, this, &WebExtensionController::didFailLoadForFrame);
    }
    if (decoder.messageName() == Messages::WebExtensionController::TestResult::name()) {
        if (!inTestingMode(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::TestResult>(connection, decoder, this, &WebExtensionController::testResult);
    }
    if (decoder.messageName() == Messages::WebExtensionController::TestEqual::name()) {
        if (!inTestingMode(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::TestEqual>(connection, decoder, this, &WebExtensionController::testEqual);
    }
    if (decoder.messageName() == Messages::WebExtensionController::TestLogMessage::name()) {
        if (!inTestingMode(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::TestLogMessage>(connection, decoder, this, &WebExtensionController::testLogMessage);
    }
    if (decoder.messageName() == Messages::WebExtensionController::TestSentMessage::name()) {
        if (!inTestingMode(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::TestSentMessage>(connection, decoder, this, &WebExtensionController::testSentMessage);
    }
    if (decoder.messageName() == Messages::WebExtensionController::TestAdded::name()) {
        if (!inTestingMode(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::TestAdded>(connection, decoder, this, &WebExtensionController::testAdded);
    }
    if (decoder.messageName() == Messages::WebExtensionController::TestStarted::name()) {
        if (!inTestingMode(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::TestStarted>(connection, decoder, this, &WebExtensionController::testStarted);
    }
    if (decoder.messageName() == Messages::WebExtensionController::TestFinished::name()) {
        if (!inTestingMode(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionController::TestFinished>(connection, decoder, this, &WebExtensionController::testFinished);
    }
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_DidStartProvisionalLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::DidStartProvisionalLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_DidCommitLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::DidCommitLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_DidFinishLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::DidFinishLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_DidFailLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::DidFailLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_TestResult>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::TestResult::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_TestEqual>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::TestEqual::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_TestLogMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::TestLogMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_TestSentMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::TestSentMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_TestAdded>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::TestAdded::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_TestStarted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::TestStarted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionController_TestFinished>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionController::TestFinished::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(WK_WEB_EXTENSIONS)
