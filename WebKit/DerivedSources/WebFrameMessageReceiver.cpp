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
#include "WebFrame.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "FrameInfoData.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "ProvisionalFrameCreationParameters.h" // NOLINT
#include "WebFrameMessages.h" // NOLINT
#include <WebCore/FocusController.h> // NOLINT
#include <WebCore/FocusDirection.h> // NOLINT
#include <WebCore/FocusEventData.h> // NOLINT
#include <WebCore/IntSize.h> // NOLINT
#include <optional> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebFrame::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebFrame::GetFrameInfo::name())
        return IPC::handleMessageAsync<Messages::WebFrame::GetFrameInfo>(connection, decoder, this, &WebFrame::getFrameInfo);
    if (decoder.messageName() == Messages::WebFrame::UpdateFrameSize::name())
        return IPC::handleMessage<Messages::WebFrame::UpdateFrameSize>(connection, decoder, this, &WebFrame::updateFrameSize);
    if (decoder.messageName() == Messages::WebFrame::CreateProvisionalFrame::name())
        return IPC::handleMessage<Messages::WebFrame::CreateProvisionalFrame>(connection, decoder, this, &WebFrame::createProvisionalFrame);
    if (decoder.messageName() == Messages::WebFrame::DestroyProvisionalFrame::name())
        return IPC::handleMessage<Messages::WebFrame::DestroyProvisionalFrame>(connection, decoder, this, &WebFrame::destroyProvisionalFrame);
    if (decoder.messageName() == Messages::WebFrame::FindFocusableElementDescendingIntoRemoteFrame::name())
        return IPC::handleMessageAsync<Messages::WebFrame::FindFocusableElementDescendingIntoRemoteFrame>(connection, decoder, this, &WebFrame::findFocusableElementDescendingIntoRemoteFrame);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

void WebFrame::sendCancelReply(IPC::Connection& connection, IPC::Decoder& decoder)
{
    ASSERT(decoder.messageReceiverName() == IPC::ReceiverName::WebFrame);
    switch (decoder.messageName()) {
    case IPC::MessageName::WebFrame_GetFrameInfo: {
        auto arguments = decoder.decode<typename Messages::WebFrame::GetFrameInfo::Arguments>();
        if (!arguments) [[unlikely]]
            return;
        auto replyID = decoder.decode<IPC::AsyncReplyID>();
        if (!replyID) [[unlikely]]
            return;
        connection.sendAsyncReply<Messages::WebFrame::GetFrameInfo>(*replyID
            , IPC::AsyncReplyError<std::optional<WebKit::FrameInfoData>>::create()
        );
        return;
    }
    case IPC::MessageName::WebFrame_FindFocusableElementDescendingIntoRemoteFrame: {
        auto arguments = decoder.decode<typename Messages::WebFrame::FindFocusableElementDescendingIntoRemoteFrame::Arguments>();
        if (!arguments) [[unlikely]]
            return;
        auto replyID = decoder.decode<IPC::AsyncReplyID>();
        if (!replyID) [[unlikely]]
            return;
        connection.sendAsyncReply<Messages::WebFrame::FindFocusableElementDescendingIntoRemoteFrame>(*replyID
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

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFrame_GetFrameInfo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrame::GetFrameInfo::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebFrame_GetFrameInfo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrame::GetFrameInfo::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFrame_UpdateFrameSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrame::UpdateFrameSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFrame_CreateProvisionalFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrame::CreateProvisionalFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFrame_DestroyProvisionalFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrame::DestroyProvisionalFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFrame_FindFocusableElementDescendingIntoRemoteFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrame::FindFocusableElementDescendingIntoRemoteFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebFrame_FindFocusableElementDescendingIntoRemoteFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFrame::FindFocusableElementDescendingIntoRemoteFrame::ReplyArguments>(globalObject, decoder);
}

}

#endif

