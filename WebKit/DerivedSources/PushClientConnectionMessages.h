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

#pragma once

#if ENABLE(WEB_PUSH_NOTIFICATIONS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include "PushMessageForTesting.h"
#include "WebPushDaemonConnectionConfiguration.h"
#include <optional>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WTF {
class UUID;
}

namespace WebCore {
struct PushSubscriptionIdentifierType;
using PushSubscriptionIdentifier = ObjectIdentifier<PushSubscriptionIdentifierType>;
class SecurityOriginData;
enum class PushPermissionState : uint8_t;
struct NotificationData;
}

namespace WebKit {
struct WebPushMessage;
}

namespace Messages {
namespace PushClientConnection {

static inline IPC::ReceiverName messageReceiverName()
{
    return IPC::ReceiverName::PushClientConnection;
}

class SetPushAndNotificationsEnabledForOrigin {
public:
    using Arguments = std::tuple<String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_SetPushAndNotificationsEnabledForOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_SetPushAndNotificationsEnabledForOriginReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPushAndNotificationsEnabledForOrigin(const String& originString, bool enabled)
        : m_originString(originString)
        , m_enabled(enabled)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_originString;
        encoder << m_enabled;
    }

private:
    const String& m_originString;
    bool m_enabled;
};

class GetPendingPushMessage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_GetPendingPushMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_GetPendingPushMessageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::WebPushMessage>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::WebPushMessage>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::WebPushMessage>, IPC::Error>;
    GetPendingPushMessage()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetPendingPushMessages {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_GetPendingPushMessages; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_GetPendingPushMessagesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::WebPushMessage>>;
    using Reply = CompletionHandler<void(Vector<WebKit::WebPushMessage>&&)>;
    using Promise = WTF::NativePromise<Vector<WebKit::WebPushMessage>, IPC::Error>;
    GetPendingPushMessages()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class InitializeConnection {
public:
    using Arguments = std::tuple<WebKit::WebPushD::WebPushDaemonConnectionConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_InitializeConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit InitializeConnection(const WebKit::WebPushD::WebPushDaemonConnectionConfiguration& configuration)
        : m_configuration(configuration)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPushD::WebPushDaemonConnectionConfiguration& m_configuration;
};

class InjectPushMessageForTesting {
public:
    using Arguments = std::tuple<WebKit::WebPushD::PushMessageForTesting>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_InjectPushMessageForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_InjectPushMessageForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit InjectPushMessageForTesting(const WebKit::WebPushD::PushMessageForTesting& message)
        : m_message(message)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPushD::PushMessageForTesting& m_message;
};

class InjectEncryptedPushMessageForTesting {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_InjectEncryptedPushMessageForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_InjectEncryptedPushMessageForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit InjectEncryptedPushMessageForTesting(const String& encryptedMessage)
        : m_encryptedMessage(encryptedMessage)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_encryptedMessage;
    }

private:
    const String& m_encryptedMessage;
};

class SubscribeToPushService {
public:
    using Arguments = std::tuple<URL, Vector<uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_SubscribeToPushService; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_SubscribeToPushServiceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>, IPC::Error>;
    SubscribeToPushService(const URL& scopeURL, const Vector<uint8_t>& vapidPublicKey)
        : m_scopeURL(scopeURL)
        , m_vapidPublicKey(vapidPublicKey)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_vapidPublicKey;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint8_t>& m_vapidPublicKey;
};

class UnsubscribeFromPushService {
public:
    using Arguments = std::tuple<URL, std::optional<WebCore::PushSubscriptionIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_UnsubscribeFromPushService; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_UnsubscribeFromPushServiceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<bool, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebCore::ExceptionData>, IPC::Error>;
    UnsubscribeFromPushService(const URL& scopeURL, const std::optional<WebCore::PushSubscriptionIdentifier>& identifier)
        : m_scopeURL(scopeURL)
        , m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PushSubscriptionIdentifier>& m_identifier;
};

class GetPushSubscription {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_GetPushSubscription; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_GetPushSubscriptionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>, IPC::Error>;
    explicit GetPushSubscription(const URL& scopeURL)
        : m_scopeURL(scopeURL)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
};

class GetPushPermissionState {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_GetPushPermissionState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_GetPushPermissionStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::PushPermissionState>;
    using Reply = CompletionHandler<void(WebCore::PushPermissionState)>;
    using Promise = WTF::NativePromise<WebCore::PushPermissionState, IPC::Error>;
    explicit GetPushPermissionState(const WebCore::SecurityOriginData& origin)
        : m_origin(origin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
};

class IncrementSilentPushCount {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_IncrementSilentPushCount; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_IncrementSilentPushCountReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<unsigned>;
    using Reply = CompletionHandler<void(unsigned&&)>;
    using Promise = WTF::NativePromise<unsigned, IPC::Error>;
    explicit IncrementSilentPushCount(const WebCore::SecurityOriginData& origin)
        : m_origin(origin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
};

class RemoveAllPushSubscriptions {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_RemoveAllPushSubscriptions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_RemoveAllPushSubscriptionsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<unsigned>;
    using Reply = CompletionHandler<void(unsigned&&)>;
    using Promise = WTF::NativePromise<unsigned, IPC::Error>;
    RemoveAllPushSubscriptions()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RemovePushSubscriptionsForOrigin {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_RemovePushSubscriptionsForOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_RemovePushSubscriptionsForOriginReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<unsigned>;
    using Reply = CompletionHandler<void(unsigned&&)>;
    using Promise = WTF::NativePromise<unsigned, IPC::Error>;
    explicit RemovePushSubscriptionsForOrigin(const WebCore::SecurityOriginData& origin)
        : m_origin(origin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
};

class SetPublicTokenForTesting {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_SetPublicTokenForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_SetPublicTokenForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetPublicTokenForTesting(const String& token)
        : m_token(token)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_token;
    }

private:
    const String& m_token;
};

class GetPushTopicsForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_GetPushTopicsForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_GetPushTopicsForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>, Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&, Vector<String>&&)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<String>, Vector<String>>, IPC::Error>;
    GetPushTopicsForTesting()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ShowNotification {
public:
    using Arguments = std::tuple<WebCore::NotificationData, RefPtr<WebCore::NotificationResources>>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_ShowNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_ShowNotificationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ShowNotification(const WebCore::NotificationData& notificationData, const RefPtr<WebCore::NotificationResources>& notificationResources)
        : m_notificationData(notificationData)
        , m_notificationResources(notificationResources)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_notificationData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_notificationResources;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NotificationData& m_notificationData;
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::NotificationResources>& m_notificationResources;
};

class GetNotifications {
public:
    using Arguments = std::tuple<URL, String>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_GetNotifications; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_GetNotificationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebCore::NotificationData>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebCore::NotificationData>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebCore::NotificationData>, WebCore::ExceptionData>, IPC::Error>;
    GetNotifications(const URL& registrationURL, const String& tag)
        : m_registrationURL(registrationURL)
        , m_tag(tag)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationURL;
        encoder << m_tag;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_registrationURL;
    const String& m_tag;
};

class CancelNotification {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, WTF::UUID>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_CancelNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelNotification(const WebCore::SecurityOriginData& origin, const WTF::UUID& notificationID)
        : m_origin(origin)
        , m_notificationID(notificationID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_notificationID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_notificationID;
};

class RequestPushPermission {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_RequestPushPermission; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_RequestPushPermissionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit RequestPushPermission(const WebCore::SecurityOriginData& origin)
        : m_origin(origin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
};

class SetAppBadge {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_SetAppBadge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetAppBadge(const WebCore::SecurityOriginData& origin, const std::optional<uint64_t>& badge)
        : m_origin(origin)
        , m_badge(badge)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_badge;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_badge;
};

class GetAppBadgeForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_GetAppBadgeForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_GetAppBadgeForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<uint64_t>>;
    using Reply = CompletionHandler<void(std::optional<uint64_t>&&)>;
    using Promise = WTF::NativePromise<std::optional<uint64_t>, IPC::Error>;
    GetAppBadgeForTesting()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetServiceWorkerIsBeingInspected {
public:
    using Arguments = std::tuple<URL, bool>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_SetServiceWorkerIsBeingInspected; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_SetServiceWorkerIsBeingInspectedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetServiceWorkerIsBeingInspected(const URL& scopeURL, bool isInspected)
        : m_scopeURL(scopeURL)
        , m_isInspected(isInspected)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
        encoder << m_isInspected;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
    bool m_isInspected;
};

class SetProtocolVersionForTesting {
public:
    using Arguments = std::tuple<unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::PushClientConnection_SetProtocolVersionForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PushClientConnection_SetProtocolVersionForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetProtocolVersionForTesting(const unsigned& version)
        : m_version(version)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_version;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_version;
};

} // namespace PushClientConnection
} // namespace Messages

#endif // ENABLE(WEB_PUSH_NOTIFICATIONS)
