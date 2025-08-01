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
#include "NotificationManagerMessageHandler.h"

#if ENABLE(NOTIFICATIONS) || ENABLE(WEB_PUSH_NOTIFICATIONS)
#include "ArgumentCoders.h" // NOLINT
#endif
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "NotificationManagerMessageHandlerMessages.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#if ENABLE(NOTIFICATIONS)
#include <WebCore/NotificationData.h> // NOLINT
#endif
#if ENABLE(NOTIFICATIONS)
#include <WebCore/NotificationResources.h> // NOLINT
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
#include <WebCore/PushPermissionState.h> // NOLINT
#endif
#if ENABLE(NOTIFICATIONS) || ENABLE(WEB_PUSH_NOTIFICATIONS)
#include <WebCore/SecurityOriginData.h> // NOLINT
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
#include <optional> // NOLINT
#endif
#if ENABLE(NOTIFICATIONS)
#include <wtf/RefCounted.h> // NOLINT
#endif
#if ENABLE(NOTIFICATIONS)
#include <wtf/UUID.h> // NOLINT
#endif
#if ENABLE(NOTIFICATIONS)
#include <wtf/Vector.h> // NOLINT
#endif

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void NotificationManagerMessageHandler::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess(connection);
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
#if ENABLE(NOTIFICATIONS)
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::ShowNotification::name()) {
        if (!(sharedPreferences && sharedPreferences->notificationsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::NotificationManagerMessageHandler::ShowNotification>(connection, decoder, this, &NotificationManagerMessageHandler::showNotification);
    }
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::CancelNotification::name()) {
        if (!(sharedPreferences && sharedPreferences->notificationsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::NotificationManagerMessageHandler::CancelNotification>(connection, decoder, this, &NotificationManagerMessageHandler::cancelNotification);
    }
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::ClearNotifications::name()) {
        if (!(sharedPreferences && sharedPreferences->notificationsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::NotificationManagerMessageHandler::ClearNotifications>(connection, decoder, this, &NotificationManagerMessageHandler::clearNotifications);
    }
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::DidDestroyNotification::name()) {
        if (!(sharedPreferences && sharedPreferences->notificationsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::NotificationManagerMessageHandler::DidDestroyNotification>(connection, decoder, this, &NotificationManagerMessageHandler::didDestroyNotification);
    }
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::PageWasNotifiedOfNotificationPermission::name()) {
        if (!(sharedPreferences && sharedPreferences->notificationsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::NotificationManagerMessageHandler::PageWasNotifiedOfNotificationPermission>(connection, decoder, this, &NotificationManagerMessageHandler::pageWasNotifiedOfNotificationPermission);
    }
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::RequestPermission::name()) {
        if (!(sharedPreferences && sharedPreferences->notificationsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::NotificationManagerMessageHandler::RequestPermission>(connection, decoder, this, &NotificationManagerMessageHandler::requestPermission);
    }
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::SetAppBadge::name()) {
        if (!(sharedPreferences && sharedPreferences->builtInNotificationsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::NotificationManagerMessageHandler::SetAppBadge>(connection, decoder, this, &NotificationManagerMessageHandler::setAppBadge);
    }
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::GetPermissionState::name()) {
        if (!(sharedPreferences && sharedPreferences->builtInNotificationsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::NotificationManagerMessageHandler::GetPermissionState>(connection, decoder, this, &NotificationManagerMessageHandler::getPermissionState);
    }
#endif
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool NotificationManagerMessageHandler::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess(connection);
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    if (decoder.messageName() == Messages::NotificationManagerMessageHandler::GetPermissionStateSync::name() && sharedPreferences && sharedPreferences->builtInNotificationsEnabled)
        return IPC::handleMessageSynchronous<Messages::NotificationManagerMessageHandler::GetPermissionStateSync>(connection, decoder, replyEncoder, this, &NotificationManagerMessageHandler::getPermissionStateSync);
#endif
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

#if ENABLE(NOTIFICATIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_ShowNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::ShowNotification::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NotificationManagerMessageHandler_ShowNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::ShowNotification::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_CancelNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::CancelNotification::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_ClearNotifications>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::ClearNotifications::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_DidDestroyNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::DidDestroyNotification::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_PageWasNotifiedOfNotificationPermission>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::PageWasNotifiedOfNotificationPermission::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_RequestPermission>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::RequestPermission::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NotificationManagerMessageHandler_RequestPermission>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::RequestPermission::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_SetAppBadge>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::SetAppBadge::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_GetPermissionState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::GetPermissionState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NotificationManagerMessageHandler_GetPermissionState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::GetPermissionState::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NotificationManagerMessageHandler_GetPermissionStateSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::GetPermissionStateSync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NotificationManagerMessageHandler_GetPermissionStateSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NotificationManagerMessageHandler::GetPermissionStateSync::ReplyArguments>(globalObject, decoder);
}
#endif

}

#endif

