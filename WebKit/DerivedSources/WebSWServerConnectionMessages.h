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
#include <WebCore/ProcessQualified.h>
#include <WebCore/ScriptExecutionContextIdentifier.h>
#include <WebCore/ServiceWorkerTypes.h>
#include <optional>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct BackgroundFetchRecordIdentifierType;
using BackgroundFetchRecordIdentifier = ObjectIdentifier<BackgroundFetchRecordIdentifierType>;
struct PushSubscriptionIdentifierType;
using PushSubscriptionIdentifier = ObjectIdentifier<PushSubscriptionIdentifierType>;
class SecurityOriginData;
struct ServiceWorkerIdentifierType;
using ServiceWorkerIdentifier = AtomicObjectIdentifier<ServiceWorkerIdentifierType>;
struct ServiceWorkerJobIdentifierType;
using ServiceWorkerJobIdentifier = AtomicObjectIdentifier<ServiceWorkerJobIdentifierType>;
struct ServiceWorkerRegistrationIdentifierType;
using ServiceWorkerRegistrationIdentifier = AtomicObjectIdentifier<ServiceWorkerRegistrationIdentifierType>;
class ServiceWorkerRegistrationKey;
struct BackgroundFetchOptions;
struct ClientOrigin;
struct ExceptionData;
struct MessageWithMessagePorts;
struct RetrieveRecordsOptions;
struct ServiceWorkerClientData;
struct ServiceWorkerJobData;
struct ServiceWorkerJobDataIdentifier;
struct ServiceWorkerRegistrationData;
struct WorkerFetchResult;
}

namespace WebKit {
struct RetrieveRecordResponseBodyCallbackIdentifierType;
using RetrieveRecordResponseBodyCallbackIdentifier = ObjectIdentifier<RetrieveRecordResponseBodyCallbackIdentifierType>;
}

namespace Messages {
namespace WebSWServerConnection {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInNetworkProcess());
        }
    );
#endif
    return IPC::ReceiverName::WebSWServerConnection;
}

class ScheduleJobInServer {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerJobData>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_ScheduleJobInServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ScheduleJobInServer(const WebCore::ServiceWorkerJobData& jobData)
        : m_jobData(jobData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerJobData& m_jobData;
};

class ScheduleUnregisterJobInServer {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerJobIdentifier, WebCore::ServiceWorkerRegistrationIdentifier, WebCore::ServiceWorkerOrClientIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_ScheduleUnregisterJobInServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_ScheduleUnregisterJobInServerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<bool, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebCore::ExceptionData>, IPC::Error>;
    ScheduleUnregisterJobInServer(const WebCore::ServiceWorkerJobIdentifier& jobIdentifier, const WebCore::ServiceWorkerRegistrationIdentifier& identifier, const WebCore::ServiceWorkerOrClientIdentifier& documentIdentifier)
        : m_jobIdentifier(jobIdentifier)
        , m_identifier(identifier)
        , m_documentIdentifier(documentIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_documentIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerJobIdentifier& m_jobIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    const WebCore::ServiceWorkerOrClientIdentifier& m_documentIdentifier;
};

class FinishFetchingScriptInServer {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerJobDataIdentifier, WebCore::ServiceWorkerRegistrationKey, WebCore::WorkerFetchResult>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_FinishFetchingScriptInServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FinishFetchingScriptInServer(const WebCore::ServiceWorkerJobDataIdentifier& jobDataIdentifier, const WebCore::ServiceWorkerRegistrationKey& registrationKey, const WebCore::WorkerFetchResult& result)
        : m_jobDataIdentifier(jobDataIdentifier)
        , m_registrationKey(registrationKey)
        , m_result(result)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobDataIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationKey;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerJobDataIdentifier& m_jobDataIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationKey& m_registrationKey;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WorkerFetchResult& m_result;
};

class AddServiceWorkerRegistrationInServer {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_AddServiceWorkerRegistrationInServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddServiceWorkerRegistrationInServer(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class RemoveServiceWorkerRegistrationInServer {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_RemoveServiceWorkerRegistrationInServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveServiceWorkerRegistrationInServer(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class PostMessageToServiceWorker {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::MessageWithMessagePorts, WebCore::ServiceWorkerOrClientIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_PostMessageToServiceWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostMessageToServiceWorker(const WebCore::ServiceWorkerIdentifier& destination, const WebCore::MessageWithMessagePorts& message, const WebCore::ServiceWorkerOrClientIdentifier& source)
        : m_destination(destination)
        , m_message(message)
        , m_source(source)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destination;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
        encoder << m_source;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessageWithMessagePorts& m_message;
    const WebCore::ServiceWorkerOrClientIdentifier& m_source;
};

class DidResolveRegistrationPromise {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationKey>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_DidResolveRegistrationPromise; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidResolveRegistrationPromise(const WebCore::ServiceWorkerRegistrationKey& key)
        : m_key(key)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_key;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationKey& m_key;
};

class MatchRegistration {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_MatchRegistration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_MatchRegistrationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ServiceWorkerRegistrationData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ServiceWorkerRegistrationData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ServiceWorkerRegistrationData>, IPC::Error>;
    MatchRegistration(const WebCore::SecurityOriginData& topOrigin, const URL& clientURL)
        : m_topOrigin(topOrigin)
        , m_clientURL(clientURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_topOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_clientURL;
};

class WhenRegistrationReady {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_WhenRegistrationReady; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_WhenRegistrationReadyReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ServiceWorkerRegistrationData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ServiceWorkerRegistrationData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ServiceWorkerRegistrationData>, IPC::Error>;
    WhenRegistrationReady(const WebCore::SecurityOriginData& topOrigin, const URL& clientURL)
        : m_topOrigin(topOrigin)
        , m_clientURL(clientURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_topOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_clientURL;
};

class GetRegistrations {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_GetRegistrations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_GetRegistrationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::ServiceWorkerRegistrationData>>;
    using Reply = CompletionHandler<void(Vector<WebCore::ServiceWorkerRegistrationData>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::ServiceWorkerRegistrationData>, IPC::Error>;
    GetRegistrations(const WebCore::SecurityOriginData& topOrigin, const URL& clientURL)
        : m_topOrigin(topOrigin)
        , m_clientURL(clientURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_topOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_clientURL;
};

class RegisterServiceWorkerClient {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin, WebCore::ServiceWorkerClientData, std::optional<WebCore::ServiceWorkerRegistrationIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_RegisterServiceWorkerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterServiceWorkerClient(const WebCore::ClientOrigin& clientOrigin, const WebCore::ServiceWorkerClientData& data, const std::optional<WebCore::ServiceWorkerRegistrationIdentifier>& controllingServiceWorkerRegistrationIdentifier, const String& userAgent)
        : m_clientOrigin(clientOrigin)
        , m_data(data)
        , m_controllingServiceWorkerRegistrationIdentifier(controllingServiceWorkerRegistrationIdentifier)
        , m_userAgent(userAgent)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_controllingServiceWorkerRegistrationIdentifier;
        encoder << m_userAgent;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_clientOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerClientData& m_data;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ServiceWorkerRegistrationIdentifier>& m_controllingServiceWorkerRegistrationIdentifier;
    const String& m_userAgent;
};

class UnregisterServiceWorkerClient {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_UnregisterServiceWorkerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UnregisterServiceWorkerClient(const WebCore::ScriptExecutionContextIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_identifier;
};

class TerminateWorkerFromClient {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_TerminateWorkerFromClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_TerminateWorkerFromClientReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit TerminateWorkerFromClient(const WebCore::ServiceWorkerIdentifier& workerIdentifier)
        : m_workerIdentifier(workerIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_workerIdentifier;
};

class WhenServiceWorkerIsTerminatedForTesting {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_WhenServiceWorkerIsTerminatedForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_WhenServiceWorkerIsTerminatedForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit WhenServiceWorkerIsTerminatedForTesting(const WebCore::ServiceWorkerIdentifier& workerIdentifier)
        : m_workerIdentifier(workerIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_workerIdentifier;
};

class SetThrottleState {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_SetThrottleState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetThrottleState(bool isThrottleable)
        : m_isThrottleable(isThrottleable)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isThrottleable;
    }

private:
    bool m_isThrottleable;
};

class StoreRegistrationsOnDisk {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_StoreRegistrationsOnDisk; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_StoreRegistrationsOnDiskReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    StoreRegistrationsOnDisk()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SubscribeToPushService {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, Vector<uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_SubscribeToPushService; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_SubscribeToPushServiceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>, IPC::Error>;
    SubscribeToPushService(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, const Vector<uint8_t>& applicationServerKey)
        : m_identifier(identifier)
        , m_applicationServerKey(applicationServerKey)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_applicationServerKey;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint8_t>& m_applicationServerKey;
};

class UnsubscribeFromPushService {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, WebCore::PushSubscriptionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_UnsubscribeFromPushService; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_UnsubscribeFromPushServiceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<bool, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebCore::ExceptionData>, IPC::Error>;
    UnsubscribeFromPushService(const WebCore::ServiceWorkerRegistrationIdentifier& serviceWorkerRegistrationIdentifier, const WebCore::PushSubscriptionIdentifier& pushSubscriptionIdentifier)
        : m_serviceWorkerRegistrationIdentifier(serviceWorkerRegistrationIdentifier)
        , m_pushSubscriptionIdentifier(pushSubscriptionIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerRegistrationIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pushSubscriptionIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_serviceWorkerRegistrationIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PushSubscriptionIdentifier& m_pushSubscriptionIdentifier;
};

class GetPushSubscription {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_GetPushSubscription; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_GetPushSubscriptionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>, IPC::Error>;
    explicit GetPushSubscription(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class GetPushPermissionState {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_GetPushPermissionState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_GetPushPermissionStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<uint8_t, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<uint8_t, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<uint8_t, WebCore::ExceptionData>, IPC::Error>;
    explicit GetPushPermissionState(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class EnableNavigationPreload {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_EnableNavigationPreload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_EnableNavigationPreloadReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    explicit EnableNavigationPreload(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class DisableNavigationPreload {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_DisableNavigationPreload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_DisableNavigationPreloadReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    explicit DisableNavigationPreload(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class SetNavigationPreloadHeaderValue {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_SetNavigationPreloadHeaderValue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_SetNavigationPreloadHeaderValueReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    SetNavigationPreloadHeaderValue(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, const String& value)
        : m_identifier(identifier)
        , m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    const String& m_value;
};

class GetNavigationPreloadState {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_GetNavigationPreloadState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_GetNavigationPreloadStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::NavigationPreloadState, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<WebCore::NavigationPreloadState, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::NavigationPreloadState, WebCore::ExceptionData>, IPC::Error>;
    explicit GetNavigationPreloadState(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class StartBackgroundFetch {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, String, Vector<WebCore::BackgroundFetchRequest>, WebCore::BackgroundFetchOptions>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_StartBackgroundFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_StartBackgroundFetchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::BackgroundFetchInformation>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::BackgroundFetchInformation>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::BackgroundFetchInformation>, WebCore::ExceptionData>, IPC::Error>;
    StartBackgroundFetch(const WebCore::ServiceWorkerRegistrationIdentifier& registrationIdentifier, const String& backgroundFetchIdentifier, const Vector<WebCore::BackgroundFetchRequest>& requests, const WebCore::BackgroundFetchOptions& options)
        : m_registrationIdentifier(registrationIdentifier)
        , m_backgroundFetchIdentifier(backgroundFetchIdentifier)
        , m_requests(requests)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationIdentifier;
        encoder << m_backgroundFetchIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requests;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_registrationIdentifier;
    const String& m_backgroundFetchIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::BackgroundFetchRequest>& m_requests;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::BackgroundFetchOptions& m_options;
};

class BackgroundFetchInformation {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_BackgroundFetchInformation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_BackgroundFetchInformationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::BackgroundFetchInformation>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::BackgroundFetchInformation>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::BackgroundFetchInformation>, WebCore::ExceptionData>, IPC::Error>;
    BackgroundFetchInformation(const WebCore::ServiceWorkerRegistrationIdentifier& registrationIdentifier, const String& backgroundFetchIdentifier)
        : m_registrationIdentifier(registrationIdentifier)
        , m_backgroundFetchIdentifier(backgroundFetchIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationIdentifier;
        encoder << m_backgroundFetchIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_registrationIdentifier;
    const String& m_backgroundFetchIdentifier;
};

class BackgroundFetchIdentifiers {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_BackgroundFetchIdentifiers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_BackgroundFetchIdentifiersReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    using Promise = WTF::NativePromise<Vector<String>, IPC::Error>;
    explicit BackgroundFetchIdentifiers(const WebCore::ServiceWorkerRegistrationIdentifier& registrationIdentifier)
        : m_registrationIdentifier(registrationIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_registrationIdentifier;
};

class AbortBackgroundFetch {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_AbortBackgroundFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_AbortBackgroundFetchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    AbortBackgroundFetch(const WebCore::ServiceWorkerRegistrationIdentifier& registrationIdentifier, const String& backgroundFetchIdentifier)
        : m_registrationIdentifier(registrationIdentifier)
        , m_backgroundFetchIdentifier(backgroundFetchIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationIdentifier;
        encoder << m_backgroundFetchIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_registrationIdentifier;
    const String& m_backgroundFetchIdentifier;
};

class MatchBackgroundFetch {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, String, WebCore::RetrieveRecordsOptions>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_MatchBackgroundFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_MatchBackgroundFetchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::BackgroundFetchRecordInformation>>;
    using Reply = CompletionHandler<void(Vector<WebCore::BackgroundFetchRecordInformation>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::BackgroundFetchRecordInformation>, IPC::Error>;
    MatchBackgroundFetch(const WebCore::ServiceWorkerRegistrationIdentifier& registrationIdentifier, const String& backgroundFetchIdentifier, const WebCore::RetrieveRecordsOptions& options)
        : m_registrationIdentifier(registrationIdentifier)
        , m_backgroundFetchIdentifier(backgroundFetchIdentifier)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationIdentifier;
        encoder << m_backgroundFetchIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_registrationIdentifier;
    const String& m_backgroundFetchIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RetrieveRecordsOptions& m_options;
};

class RetrieveRecordResponse {
public:
    using Arguments = std::tuple<WebCore::BackgroundFetchRecordIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_RetrieveRecordResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_RetrieveRecordResponseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::ResourceResponse, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<WebCore::ResourceResponse, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::ResourceResponse, WebCore::ExceptionData>, IPC::Error>;
    explicit RetrieveRecordResponse(const WebCore::BackgroundFetchRecordIdentifier& recordIdentifier)
        : m_recordIdentifier(recordIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_recordIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::BackgroundFetchRecordIdentifier& m_recordIdentifier;
};

class RetrieveRecordResponseBody {
public:
    using Arguments = std::tuple<WebCore::BackgroundFetchRecordIdentifier, WebKit::RetrieveRecordResponseBodyCallbackIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_RetrieveRecordResponseBody; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RetrieveRecordResponseBody(const WebCore::BackgroundFetchRecordIdentifier& recordIdentifier, const WebKit::RetrieveRecordResponseBodyCallbackIdentifier& callbackIdentifier)
        : m_recordIdentifier(recordIdentifier)
        , m_callbackIdentifier(callbackIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_recordIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_callbackIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::BackgroundFetchRecordIdentifier& m_recordIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RetrieveRecordResponseBodyCallbackIdentifier& m_callbackIdentifier;
};

class AddCookieChangeSubscriptions {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, Vector<WebCore::CookieChangeSubscription>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_AddCookieChangeSubscriptions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_AddCookieChangeSubscriptionsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    AddCookieChangeSubscriptions(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, const Vector<WebCore::CookieChangeSubscription>& subscriptions)
        : m_identifier(identifier)
        , m_subscriptions(subscriptions)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subscriptions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::CookieChangeSubscription>& m_subscriptions;
};

class RemoveCookieChangeSubscriptions {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, Vector<WebCore::CookieChangeSubscription>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_RemoveCookieChangeSubscriptions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_RemoveCookieChangeSubscriptionsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    RemoveCookieChangeSubscriptions(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, const Vector<WebCore::CookieChangeSubscription>& subscriptions)
        : m_identifier(identifier)
        , m_subscriptions(subscriptions)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subscriptions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::CookieChangeSubscription>& m_subscriptions;
};

class CookieChangeSubscriptions {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_CookieChangeSubscriptions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_CookieChangeSubscriptionsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebCore::CookieChangeSubscription>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebCore::CookieChangeSubscription>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebCore::CookieChangeSubscription>, WebCore::ExceptionData>, IPC::Error>;
    explicit CookieChangeSubscriptions(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class AddRoutes {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, Vector<WebCore::ServiceWorkerRoute>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_AddRoutes; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_AddRoutesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<void, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebCore::ExceptionData>, IPC::Error>;
    AddRoutes(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, const Vector<WebCore::ServiceWorkerRoute>& subscriptions)
        : m_identifier(identifier)
        , m_subscriptions(subscriptions)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subscriptions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::ServiceWorkerRoute>& m_subscriptions;
};

#if ENABLE(WEB_PUSH_NOTIFICATIONS)
class GetNotifications {
public:
    using Arguments = std::tuple<URL, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerConnection_GetNotifications; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerConnection_GetNotificationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebCore::NotificationData>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebCore::NotificationData>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebCore::NotificationData>, WebCore::ExceptionData>, IPC::Error>;
    GetNotifications(const URL& registrationURL, const String& tag)
        : m_registrationURL(registrationURL)
        , m_tag(tag)
    {
        ASSERT(isInWebProcess());
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
#endif

} // namespace WebSWServerConnection
} // namespace Messages
