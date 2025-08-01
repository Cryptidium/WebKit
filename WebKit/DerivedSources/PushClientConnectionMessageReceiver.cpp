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
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
#include "PushClientConnection.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "PushClientConnectionMessages.h" // NOLINT
#include "PushMessageForTesting.h" // NOLINT
#include "WebPushDaemonConnectionConfiguration.h" // NOLINT
#include "WebPushMessage.h" // NOLINT
#include <WebCore/ExceptionData.h> // NOLINT
#include <WebCore/NotificationData.h> // NOLINT
#include <WebCore/NotificationResources.h> // NOLINT
#include <WebCore/PushPermissionState.h> // NOLINT
#include <WebCore/PushSubscriptionData.h> // NOLINT
#include <WebCore/PushSubscriptionIdentifier.h> // NOLINT
#include <WebCore/SecurityOriginData.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/Expected.h> // NOLINT
#include <wtf/RefCounted.h> // NOLINT
#include <wtf/URLHash.h> // NOLINT
#include <wtf/UUID.h> // NOLINT
#include <wtf/Vector.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebPushD {

void PushClientConnection::didReceiveMessageWithReplyHandler(IPC::Decoder& decoder, Function<void(UniqueRef<IPC::Encoder>&&)>&& replyHandler)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::PushClientConnection::SetPushAndNotificationsEnabledForOrigin::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::SetPushAndNotificationsEnabledForOrigin>(decoder, WTFMove(replyHandler), this, &PushClientConnection::setPushAndNotificationsEnabledForOrigin);
    if (decoder.messageName() == Messages::PushClientConnection::GetPendingPushMessage::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::GetPendingPushMessage>(decoder, WTFMove(replyHandler), this, &PushClientConnection::getPendingPushMessage);
    if (decoder.messageName() == Messages::PushClientConnection::GetPendingPushMessages::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::GetPendingPushMessages>(decoder, WTFMove(replyHandler), this, &PushClientConnection::getPendingPushMessages);
    if (decoder.messageName() == Messages::PushClientConnection::InitializeConnection::name())
        return IPC::handleMessageWithoutUsingIPCConnection<Messages::PushClientConnection::InitializeConnection>(decoder, this, &PushClientConnection::initializeConnection);
    if (decoder.messageName() == Messages::PushClientConnection::InjectPushMessageForTesting::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::InjectPushMessageForTesting>(decoder, WTFMove(replyHandler), this, &PushClientConnection::injectPushMessageForTesting);
    if (decoder.messageName() == Messages::PushClientConnection::InjectEncryptedPushMessageForTesting::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::InjectEncryptedPushMessageForTesting>(decoder, WTFMove(replyHandler), this, &PushClientConnection::injectEncryptedPushMessageForTesting);
    if (decoder.messageName() == Messages::PushClientConnection::SubscribeToPushService::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::SubscribeToPushService>(decoder, WTFMove(replyHandler), this, &PushClientConnection::subscribeToPushService);
    if (decoder.messageName() == Messages::PushClientConnection::UnsubscribeFromPushService::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::UnsubscribeFromPushService>(decoder, WTFMove(replyHandler), this, &PushClientConnection::unsubscribeFromPushService);
    if (decoder.messageName() == Messages::PushClientConnection::GetPushSubscription::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::GetPushSubscription>(decoder, WTFMove(replyHandler), this, &PushClientConnection::getPushSubscription);
    if (decoder.messageName() == Messages::PushClientConnection::GetPushPermissionState::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::GetPushPermissionState>(decoder, WTFMove(replyHandler), this, &PushClientConnection::getPushPermissionState);
    if (decoder.messageName() == Messages::PushClientConnection::IncrementSilentPushCount::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::IncrementSilentPushCount>(decoder, WTFMove(replyHandler), this, &PushClientConnection::incrementSilentPushCount);
    if (decoder.messageName() == Messages::PushClientConnection::RemoveAllPushSubscriptions::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::RemoveAllPushSubscriptions>(decoder, WTFMove(replyHandler), this, &PushClientConnection::removeAllPushSubscriptions);
    if (decoder.messageName() == Messages::PushClientConnection::RemovePushSubscriptionsForOrigin::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::RemovePushSubscriptionsForOrigin>(decoder, WTFMove(replyHandler), this, &PushClientConnection::removePushSubscriptionsForOrigin);
    if (decoder.messageName() == Messages::PushClientConnection::SetPublicTokenForTesting::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::SetPublicTokenForTesting>(decoder, WTFMove(replyHandler), this, &PushClientConnection::setPublicTokenForTesting);
    if (decoder.messageName() == Messages::PushClientConnection::GetPushTopicsForTesting::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::GetPushTopicsForTesting>(decoder, WTFMove(replyHandler), this, &PushClientConnection::getPushTopicsForTesting);
    if (decoder.messageName() == Messages::PushClientConnection::ShowNotification::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::ShowNotification>(decoder, WTFMove(replyHandler), this, &PushClientConnection::showNotification);
    if (decoder.messageName() == Messages::PushClientConnection::GetNotifications::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::GetNotifications>(decoder, WTFMove(replyHandler), this, &PushClientConnection::getNotifications);
    if (decoder.messageName() == Messages::PushClientConnection::CancelNotification::name())
        return IPC::handleMessageWithoutUsingIPCConnection<Messages::PushClientConnection::CancelNotification>(decoder, this, &PushClientConnection::cancelNotification);
    if (decoder.messageName() == Messages::PushClientConnection::RequestPushPermission::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::RequestPushPermission>(decoder, WTFMove(replyHandler), this, &PushClientConnection::requestPushPermission);
    if (decoder.messageName() == Messages::PushClientConnection::SetAppBadge::name())
        return IPC::handleMessageWithoutUsingIPCConnection<Messages::PushClientConnection::SetAppBadge>(decoder, this, &PushClientConnection::setAppBadge);
    if (decoder.messageName() == Messages::PushClientConnection::GetAppBadgeForTesting::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::GetAppBadgeForTesting>(decoder, WTFMove(replyHandler), this, &PushClientConnection::getAppBadgeForTesting);
    if (decoder.messageName() == Messages::PushClientConnection::SetServiceWorkerIsBeingInspected::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::SetServiceWorkerIsBeingInspected>(decoder, WTFMove(replyHandler), this, &PushClientConnection::setServiceWorkerIsBeingInspected);
    if (decoder.messageName() == Messages::PushClientConnection::SetProtocolVersionForTesting::name())
        return IPC::handleMessageAsyncWithoutUsingIPCConnection<Messages::PushClientConnection::SetProtocolVersionForTesting>(decoder, WTFMove(replyHandler), this, &PushClientConnection::setProtocolVersionForTesting);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_SetPushAndNotificationsEnabledForOrigin>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetPushAndNotificationsEnabledForOrigin::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_SetPushAndNotificationsEnabledForOrigin>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetPushAndNotificationsEnabledForOrigin::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_GetPendingPushMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPendingPushMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_GetPendingPushMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPendingPushMessage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_GetPendingPushMessages>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPendingPushMessages::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_GetPendingPushMessages>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPendingPushMessages::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_InitializeConnection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::InitializeConnection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_InjectPushMessageForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::InjectPushMessageForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_InjectPushMessageForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::InjectPushMessageForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_InjectEncryptedPushMessageForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::InjectEncryptedPushMessageForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_InjectEncryptedPushMessageForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::InjectEncryptedPushMessageForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_SubscribeToPushService>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SubscribeToPushService::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_SubscribeToPushService>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SubscribeToPushService::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_UnsubscribeFromPushService>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::UnsubscribeFromPushService::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_UnsubscribeFromPushService>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::UnsubscribeFromPushService::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_GetPushSubscription>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPushSubscription::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_GetPushSubscription>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPushSubscription::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_GetPushPermissionState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPushPermissionState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_GetPushPermissionState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPushPermissionState::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_IncrementSilentPushCount>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::IncrementSilentPushCount::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_IncrementSilentPushCount>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::IncrementSilentPushCount::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_RemoveAllPushSubscriptions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::RemoveAllPushSubscriptions::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_RemoveAllPushSubscriptions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::RemoveAllPushSubscriptions::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_RemovePushSubscriptionsForOrigin>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::RemovePushSubscriptionsForOrigin::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_RemovePushSubscriptionsForOrigin>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::RemovePushSubscriptionsForOrigin::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_SetPublicTokenForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetPublicTokenForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_SetPublicTokenForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetPublicTokenForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_GetPushTopicsForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPushTopicsForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_GetPushTopicsForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetPushTopicsForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_ShowNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::ShowNotification::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_ShowNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::ShowNotification::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_GetNotifications>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetNotifications::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_GetNotifications>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetNotifications::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_CancelNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::CancelNotification::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_RequestPushPermission>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::RequestPushPermission::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_RequestPushPermission>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::RequestPushPermission::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_SetAppBadge>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetAppBadge::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_GetAppBadgeForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetAppBadgeForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_GetAppBadgeForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::GetAppBadgeForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_SetServiceWorkerIsBeingInspected>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetServiceWorkerIsBeingInspected::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_SetServiceWorkerIsBeingInspected>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetServiceWorkerIsBeingInspected::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::PushClientConnection_SetProtocolVersionForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetProtocolVersionForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::PushClientConnection_SetProtocolVersionForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::PushClientConnection::SetProtocolVersionForTesting::ReplyArguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(WEB_PUSH_NOTIFICATIONS)
