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
#include "WebPageTesting.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "WebPageTestingMessages.h" // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebPageTesting::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebPageTesting::IsLayerTreeFrozen::name())
        return IPC::handleMessageAsync<Messages::WebPageTesting::IsLayerTreeFrozen>(connection, decoder, this, &WebPageTesting::isLayerTreeFrozen);
    if (decoder.messageName() == Messages::WebPageTesting::SetPermissionLevel::name())
        return IPC::handleMessage<Messages::WebPageTesting::SetPermissionLevel>(connection, decoder, this, &WebPageTesting::setPermissionLevel);
#if ENABLE(NOTIFICATIONS)
    if (decoder.messageName() == Messages::WebPageTesting::ClearNotificationPermissionState::name())
        return IPC::handleMessage<Messages::WebPageTesting::ClearNotificationPermissionState>(connection, decoder, this, &WebPageTesting::clearNotificationPermissionState);
#endif
    if (decoder.messageName() == Messages::WebPageTesting::ClearWheelEventTestMonitor::name())
        return IPC::handleMessage<Messages::WebPageTesting::ClearWheelEventTestMonitor>(connection, decoder, this, &WebPageTesting::clearWheelEventTestMonitor);
    if (decoder.messageName() == Messages::WebPageTesting::ResetStateBetweenTests::name())
        return IPC::handleMessage<Messages::WebPageTesting::ResetStateBetweenTests>(connection, decoder, this, &WebPageTesting::resetStateBetweenTests);
    if (decoder.messageName() == Messages::WebPageTesting::SetObscuredContentInsets::name())
        return IPC::handleMessageAsync<Messages::WebPageTesting::SetObscuredContentInsets>(connection, decoder, this, &WebPageTesting::setObscuredContentInsets);
    if (decoder.messageName() == Messages::WebPageTesting::ClearCachedBackForwardListCounts::name())
        return IPC::handleMessageAsync<Messages::WebPageTesting::ClearCachedBackForwardListCounts>(connection, decoder, this, &WebPageTesting::clearCachedBackForwardListCounts);
    if (decoder.messageName() == Messages::WebPageTesting::SetTracksRepaints::name())
        return IPC::handleMessageAsync<Messages::WebPageTesting::SetTracksRepaints>(connection, decoder, this, &WebPageTesting::setTracksRepaints);
    if (decoder.messageName() == Messages::WebPageTesting::DisplayAndTrackRepaints::name())
        return IPC::handleMessageAsync<Messages::WebPageTesting::DisplayAndTrackRepaints>(connection, decoder, this, &WebPageTesting::displayAndTrackRepaints);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool WebPageTesting::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(isInWebProcess());
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebPageTesting::IsEditingCommandEnabled::name())
        return IPC::handleMessageSynchronous<Messages::WebPageTesting::IsEditingCommandEnabled>(connection, decoder, replyEncoder, this, &WebPageTesting::isEditingCommandEnabled);
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_IsLayerTreeFrozen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::IsLayerTreeFrozen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageTesting_IsLayerTreeFrozen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::IsLayerTreeFrozen::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_SetPermissionLevel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::SetPermissionLevel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_IsEditingCommandEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::IsEditingCommandEnabled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageTesting_IsEditingCommandEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::IsEditingCommandEnabled::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(NOTIFICATIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_ClearNotificationPermissionState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::ClearNotificationPermissionState::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_ClearWheelEventTestMonitor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::ClearWheelEventTestMonitor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_ResetStateBetweenTests>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::ResetStateBetweenTests::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_SetObscuredContentInsets>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::SetObscuredContentInsets::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageTesting_SetObscuredContentInsets>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::SetObscuredContentInsets::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_ClearCachedBackForwardListCounts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::ClearCachedBackForwardListCounts::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageTesting_ClearCachedBackForwardListCounts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::ClearCachedBackForwardListCounts::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_SetTracksRepaints>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::SetTracksRepaints::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageTesting_SetTracksRepaints>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::SetTracksRepaints::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageTesting_DisplayAndTrackRepaints>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::DisplayAndTrackRepaints::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageTesting_DisplayAndTrackRepaints>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageTesting::DisplayAndTrackRepaints::ReplyArguments>(globalObject, decoder);
}

}

#endif

