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
#include "WebFrameProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "WebFrameProxyMessages.h" // NOLINT
#include <WebCore/FocusController.h> // NOLINT
#include <WebCore/FocusDirection.h> // NOLINT
#include <WebCore/FocusEventData.h> // NOLINT
#include <WebCore/IntSize.h> // NOLINT
#include <WebCore/SecurityOriginData.h> // NOLINT
#include <optional> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebFrameProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebFrameProxy::UpdateRemoteFrameSize::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebFrameProxy::UpdateRemoteFrameSize>(connection, decoder, this, &WebFrameProxy::updateRemoteFrameSize);
    }
    if (decoder.messageName() == Messages::WebFrameProxy::SetAppBadge::name()) {
        if (!(sharedPreferences && sharedPreferences->appBadgeEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebFrameProxy::SetAppBadge>(connection, decoder, this, &WebFrameProxy::setAppBadge);
    }
    if (decoder.messageName() == Messages::WebFrameProxy::FindFocusableElementDescendingIntoRemoteFrame::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebFrameProxy::FindFocusableElementDescendingIntoRemoteFrame>(connection, decoder, this, &WebFrameProxy::findFocusableElementDescendingIntoRemoteFrame);
    }
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

void WebFrameProxy::sendCancelReply(IPC::Connection& connection, IPC::Decoder& decoder)
{
    ASSERT(decoder.messageReceiverName() == IPC::ReceiverName::WebFrameProxy);
    switch (decoder.messageName()) {
    case IPC::MessageName::WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrame: {
        auto arguments = decoder.decode<typename Messages::WebFrameProxy::FindFocusableElementDescendingIntoRemoteFrame::Arguments>();
        if (!arguments) [[unlikely]]
            return;
        auto replyID = decoder.decode<IPC::AsyncReplyID>();
        if (!replyID) [[unlikely]]
            return;
        connection.sendAsyncReply<Messages::WebFrameProxy::FindFocusableElementDescendingIntoRemoteFrame>(*replyID
            , IPC::AsyncReplyError<WebCore::FoundElementInRemoteFrame>::create()
        );
        return;
    }
    default:
        // No reply to send.
        return;
    }
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFrameProxy_UpdateRemoteFrameSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrameProxy::UpdateRemoteFrameSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFrameProxy_SetAppBadge>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrameProxy::SetAppBadge::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrameProxy::FindFocusableElementDescendingIntoRemoteFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrameProxy::FindFocusableElementDescendingIntoRemoteFrame::ReplyArguments>(globalObject, decoder);
}

}

#endif

