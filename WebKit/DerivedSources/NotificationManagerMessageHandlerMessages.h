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

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/UUID.h>
#include <wtf/Vector.h>

namespace WTF {
class UUID;
}

namespace WebCore {
class SecurityOriginData;
enum class PushPermissionState : uint8_t;
struct NotificationData;
}

namespace Messages {
namespace NotificationManagerMessageHandler {

static inline IPC::ReceiverName messageReceiverName()
{
    return IPC::ReceiverName::NotificationManagerMessageHandler;
}

#if ENABLE(NOTIFICATIONS)
class ShowNotification {
public:
    using Arguments = std::tuple<WebCore::NotificationData, RefPtr<WebCore::NotificationResources>>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_ShowNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NotificationManagerMessageHandler_ShowNotificationReply; }
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
#endif

#if ENABLE(NOTIFICATIONS)
class CancelNotification {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, WTF::UUID>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_CancelNotification; }
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
#endif

#if ENABLE(NOTIFICATIONS)
class ClearNotifications {
public:
    using Arguments = std::tuple<Vector<WTF::UUID>>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_ClearNotifications; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ClearNotifications(const Vector<WTF::UUID>& notificationIDs)
        : m_notificationIDs(notificationIDs)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_notificationIDs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WTF::UUID>& m_notificationIDs;
};
#endif

#if ENABLE(NOTIFICATIONS)
class DidDestroyNotification {
public:
    using Arguments = std::tuple<WTF::UUID>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_DidDestroyNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDestroyNotification(const WTF::UUID& notificationID)
        : m_notificationID(notificationID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_notificationID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_notificationID;
};
#endif

#if ENABLE(NOTIFICATIONS)
class PageWasNotifiedOfNotificationPermission {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_PageWasNotifiedOfNotificationPermission; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PageWasNotifiedOfNotificationPermission()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(NOTIFICATIONS)
class RequestPermission {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_RequestPermission; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NotificationManagerMessageHandler_RequestPermissionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit RequestPermission(const WebCore::SecurityOriginData& origin)
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
#endif

#if ENABLE(WEB_PUSH_NOTIFICATIONS)
class SetAppBadge {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_SetAppBadge; }
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
#endif

#if ENABLE(WEB_PUSH_NOTIFICATIONS)
class GetPermissionState {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_GetPermissionState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NotificationManagerMessageHandler_GetPermissionStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::PushPermissionState>;
    using Reply = CompletionHandler<void(WebCore::PushPermissionState)>;
    using Promise = WTF::NativePromise<WebCore::PushPermissionState, IPC::Error>;
    explicit GetPermissionState(const WebCore::SecurityOriginData& origin)
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
#endif

#if ENABLE(WEB_PUSH_NOTIFICATIONS)
class GetPermissionStateSync {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::NotificationManagerMessageHandler_GetPermissionStateSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::PushPermissionState>;
    using Reply = CompletionHandler<void(WebCore::PushPermissionState)>;
    explicit GetPermissionStateSync(const WebCore::SecurityOriginData& origin)
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
#endif

} // namespace NotificationManagerMessageHandler
} // namespace Messages
