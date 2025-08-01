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
#include <WebCore/NotificationPayload.h>
#include <WebCore/ServiceWorkerClientData.h>
#include <WebCore/ServiceWorkerData.h>
#include <WebCore/ServiceWorkerTypes.h>
#include <span>
#include <wtf/Forward.h>
#include <wtf/HashMap.h>
#include <wtf/OptionSet.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/URLHash.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class FormDataReference;
}

namespace WebCore {
struct FetchIdentifierType;
using FetchIdentifier = ObjectIdentifier<FetchIdentifierType>;
struct ProcessIdentifierType;
using ProcessIdentifier = ObjectIdentifier<ProcessIdentifierType>;
class ResourceError;
class ResourceRequest;
class ResourceResponse;
class ScriptBuffer;
struct ServiceWorkerIdentifierType;
using ServiceWorkerIdentifier = AtomicObjectIdentifier<ServiceWorkerIdentifierType>;
struct ServiceWorkerRegistrationIdentifierType;
using ServiceWorkerRegistrationIdentifier = AtomicObjectIdentifier<ServiceWorkerRegistrationIdentifierType>;
enum class LastNavigationWasAppInitiated : bool;
enum class NotificationEventType : bool;
enum class ServiceWorkerIsInspectable : bool;
enum class WorkerThreadMode : bool;
enum class ServiceWorkerRegistrationState : uint8_t;
enum class ServiceWorkerState : uint8_t;
enum class ServiceWorkerUpdateViaCache : uint8_t;
struct BackgroundFetchInformation;
struct FetchOptions;
struct MessageWithMessagePorts;
struct NotificationData;
struct ServiceWorkerContextData;
struct ServiceWorkerData;
}

namespace WebKit {
struct WebPreferencesStore;
}

namespace Messages {
namespace WebSWContextManagerConnection {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInWebProcess());
        }
    );
#endif
    return IPC::ReceiverName::WebSWContextManagerConnection;
}

class InstallServiceWorker {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerContextData, WebCore::ServiceWorkerData, String, WebCore::WorkerThreadMode, WebCore::ServiceWorkerIsInspectable, OptionSet<WebCore::AdvancedPrivacyProtections>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_InstallServiceWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    InstallServiceWorker(const WebCore::ServiceWorkerContextData& contextData, const WebCore::ServiceWorkerData& workerData, const String& userAgent, WebCore::WorkerThreadMode workerThreadMode, WebCore::ServiceWorkerIsInspectable inspectable, const OptionSet<WebCore::AdvancedPrivacyProtections>& protections)
        : m_contextData(contextData)
        , m_workerData(workerData)
        , m_userAgent(userAgent)
        , m_workerThreadMode(workerThreadMode)
        , m_inspectable(inspectable)
        , m_protections(protections)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contextData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workerData;
        encoder << m_userAgent;
        encoder << m_workerThreadMode;
        encoder << m_inspectable;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_protections;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerContextData& m_contextData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerData& m_workerData;
    const String& m_userAgent;
    WebCore::WorkerThreadMode m_workerThreadMode;
    WebCore::ServiceWorkerIsInspectable m_inspectable;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::AdvancedPrivacyProtections>& m_protections;
};

class UpdateAppInitiatedValue {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::LastNavigationWasAppInitiated>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_UpdateAppInitiatedValue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateAppInitiatedValue(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, WebCore::LastNavigationWasAppInitiated lastNavigationWasAppInitiated)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_lastNavigationWasAppInitiated(lastNavigationWasAppInitiated)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_lastNavigationWasAppInitiated;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    WebCore::LastNavigationWasAppInitiated m_lastNavigationWasAppInitiated;
};

class StartFetch {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier, WebCore::ResourceRequest, WebCore::FetchOptions, IPC::FormDataReference, String, bool, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_StartFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartFetch(const WebCore::ProcessIdentifier& serverConnectionIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const WebCore::FetchIdentifier& fetchIdentifier, const WebCore::ResourceRequest& request, const WebCore::FetchOptions& options, const IPC::FormDataReference& requestBody, const String& referrer, bool isServiceWorkerNavigationPreloadEnabled, const String& clientIdentifier, const String& resutlingClientIdentifier)
        : m_serverConnectionIdentifier(serverConnectionIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_fetchIdentifier(fetchIdentifier)
        , m_request(request)
        , m_options(options)
        , m_requestBody(requestBody)
        , m_referrer(referrer)
        , m_isServiceWorkerNavigationPreloadEnabled(isServiceWorkerNavigationPreloadEnabled)
        , m_clientIdentifier(clientIdentifier)
        , m_resutlingClientIdentifier(resutlingClientIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serverConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fetchIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestBody;
        encoder << m_referrer;
        encoder << m_isServiceWorkerNavigationPreloadEnabled;
        encoder << m_clientIdentifier;
        encoder << m_resutlingClientIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_serverConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FetchIdentifier& m_fetchIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FetchOptions& m_options;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::FormDataReference& m_requestBody;
    const String& m_referrer;
    bool m_isServiceWorkerNavigationPreloadEnabled;
    const String& m_clientIdentifier;
    const String& m_resutlingClientIdentifier;
};

class CancelFetch {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_CancelFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelFetch(const WebCore::ProcessIdentifier& serverConnectionIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const WebCore::FetchIdentifier& fetchIdentifier)
        : m_serverConnectionIdentifier(serverConnectionIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_fetchIdentifier(fetchIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serverConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fetchIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_serverConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FetchIdentifier& m_fetchIdentifier;
};

class ContinueDidReceiveFetchResponse {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_ContinueDidReceiveFetchResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ContinueDidReceiveFetchResponse(const WebCore::ProcessIdentifier& serverConnectionIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const WebCore::FetchIdentifier& fetchIdentifier)
        : m_serverConnectionIdentifier(serverConnectionIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_fetchIdentifier(fetchIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serverConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fetchIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_serverConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FetchIdentifier& m_fetchIdentifier;
};

class PostMessageToServiceWorker {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::MessageWithMessagePorts, WebCore::ServiceWorkerOrClientData>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_PostMessageToServiceWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostMessageToServiceWorker(const WebCore::ServiceWorkerIdentifier& destinationIdentifier, const WebCore::MessageWithMessagePorts& message, const WebCore::ServiceWorkerOrClientData& sourceData)
        : m_destinationIdentifier(destinationIdentifier)
        , m_message(message)
        , m_sourceData(sourceData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
        encoder << m_sourceData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_destinationIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessageWithMessagePorts& m_message;
    const WebCore::ServiceWorkerOrClientData& m_sourceData;
};

class FireInstallEvent {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_FireInstallEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FireInstallEvent(const WebCore::ServiceWorkerIdentifier& identifier)
        : m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};

class FireActivateEvent {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_FireActivateEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FireActivateEvent(const WebCore::ServiceWorkerIdentifier& identifier)
        : m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};

class FirePushEvent {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, std::optional<std::span<const uint8_t>>, std::optional<WebCore::NotificationPayload>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_FirePushEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWContextManagerConnection_FirePushEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, std::optional<WebCore::NotificationPayload>>;
    using Reply = CompletionHandler<void(bool, std::optional<WebCore::NotificationPayload>&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, std::optional<WebCore::NotificationPayload>>, IPC::Error>;
    FirePushEvent(const WebCore::ServiceWorkerIdentifier& identifier, const std::optional<std::span<const uint8_t>>& data, const std::optional<WebCore::NotificationPayload>& proposedPayload)
        : m_identifier(identifier)
        , m_data(data)
        , m_proposedPayload(proposedPayload)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_proposedPayload;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<std::span<const uint8_t>>& m_data;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NotificationPayload>& m_proposedPayload;
};

class FireNotificationEvent {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::NotificationData, WebCore::NotificationEventType>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_FireNotificationEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWContextManagerConnection_FireNotificationEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    FireNotificationEvent(const WebCore::ServiceWorkerIdentifier& identifier, const WebCore::NotificationData& data, WebCore::NotificationEventType type)
        : m_identifier(identifier)
        , m_data(data)
        , m_type(type)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        encoder << m_type;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NotificationData& m_data;
    WebCore::NotificationEventType m_type;
};

class FireBackgroundFetchEvent {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::BackgroundFetchInformation>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_FireBackgroundFetchEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWContextManagerConnection_FireBackgroundFetchEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    FireBackgroundFetchEvent(const WebCore::ServiceWorkerIdentifier& identifier, const WebCore::BackgroundFetchInformation& info)
        : m_identifier(identifier)
        , m_info(info)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::BackgroundFetchInformation& m_info;
};

class FireBackgroundFetchClickEvent {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::BackgroundFetchInformation>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_FireBackgroundFetchClickEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWContextManagerConnection_FireBackgroundFetchClickEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    FireBackgroundFetchClickEvent(const WebCore::ServiceWorkerIdentifier& identifier, const WebCore::BackgroundFetchInformation& info)
        : m_identifier(identifier)
        , m_info(info)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::BackgroundFetchInformation& m_info;
};

class TerminateWorker {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_TerminateWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TerminateWorker(const WebCore::ServiceWorkerIdentifier& identifier)
        : m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};

#if ENABLE(SHAREABLE_RESOURCE) && PLATFORM(COCOA)
class DidSaveScriptsToDisk {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::ScriptBuffer, HashMap<URL, WebCore::ScriptBuffer>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_DidSaveScriptsToDisk; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidSaveScriptsToDisk(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const WebCore::ScriptBuffer& script, const HashMap<URL, WebCore::ScriptBuffer>& importedScripts)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_script(script)
        , m_importedScripts(importedScripts)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_script;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_importedScripts;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ScriptBuffer& m_script;
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<URL, WebCore::ScriptBuffer>& m_importedScripts;
};
#endif

class SetUserAgent {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_SetUserAgent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUserAgent(const String& userAgent)
        : m_userAgent(userAgent)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_userAgent;
    }

private:
    const String& m_userAgent;
};

class UpdatePreferencesStore {
public:
    using Arguments = std::tuple<WebKit::WebPreferencesStore>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_UpdatePreferencesStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdatePreferencesStore(const WebKit::WebPreferencesStore& store)
        : m_store(store)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_store;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPreferencesStore& m_store;
};

class Close {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_Close; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Close()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetThrottleState {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_SetThrottleState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetThrottleState(bool isThrottleable)
        : m_isThrottleable(isThrottleable)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isThrottleable;
    }

private:
    bool m_isThrottleable;
};

class SetInspectable {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIsInspectable>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_SetInspectable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetInspectable(WebCore::ServiceWorkerIsInspectable inspectable)
        : m_inspectable(inspectable)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_inspectable;
    }

private:
    WebCore::ServiceWorkerIsInspectable m_inspectable;
};

class ConvertFetchToDownload {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_ConvertFetchToDownload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ConvertFetchToDownload(const WebCore::ProcessIdentifier& serverConnectionIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const WebCore::FetchIdentifier& identifier)
        : m_serverConnectionIdentifier(serverConnectionIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serverConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_serverConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FetchIdentifier& m_identifier;
};

class NavigationPreloadIsReady {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_NavigationPreloadIsReady; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NavigationPreloadIsReady(const WebCore::ProcessIdentifier& serverConnectionIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const WebCore::FetchIdentifier& identifier, const WebCore::ResourceResponse& response)
        : m_serverConnectionIdentifier(serverConnectionIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_identifier(identifier)
        , m_response(response)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serverConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_serverConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FetchIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

class NavigationPreloadFailed {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_NavigationPreloadFailed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NavigationPreloadFailed(const WebCore::ProcessIdentifier& serverConnectionIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const WebCore::FetchIdentifier& identifier, const WebCore::ResourceError& error)
        : m_serverConnectionIdentifier(serverConnectionIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_identifier(identifier)
        , m_error(error)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serverConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_serverConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FetchIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class UpdateRegistrationState {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, WebCore::ServiceWorkerRegistrationState, std::optional<WebCore::ServiceWorkerData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_UpdateRegistrationState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateRegistrationState(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, WebCore::ServiceWorkerRegistrationState state, const std::optional<WebCore::ServiceWorkerData>& serviceWorkerIdentifier)
        : m_identifier(identifier)
        , m_state(state)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_state;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    WebCore::ServiceWorkerRegistrationState m_state;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ServiceWorkerData>& m_serviceWorkerIdentifier;
};

class UpdateWorkerState {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::ServiceWorkerState>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_UpdateWorkerState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateWorkerState(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, WebCore::ServiceWorkerState state)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_state(state)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    WebCore::ServiceWorkerState m_state;
};

class FireUpdateFoundEvent {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_FireUpdateFoundEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FireUpdateFoundEvent(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class SetRegistrationLastUpdateTime {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_SetRegistrationLastUpdateTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetRegistrationLastUpdateTime(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, const WallTime& lastUpdateTime)
        : m_identifier(identifier)
        , m_lastUpdateTime(lastUpdateTime)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lastUpdateTime;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_lastUpdateTime;
};

class SetRegistrationUpdateViaCache {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, WebCore::ServiceWorkerUpdateViaCache>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_SetRegistrationUpdateViaCache; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetRegistrationUpdateViaCache(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, WebCore::ServiceWorkerUpdateViaCache updateViaCache)
        : m_identifier(identifier)
        , m_updateViaCache(updateViaCache)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_updateViaCache;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    WebCore::ServiceWorkerUpdateViaCache m_updateViaCache;
};

#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
class ConnectToInspector {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_ConnectToInspector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ConnectToInspector(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, bool isAutomaticConnection, bool immediatelyPause)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_isAutomaticConnection(isAutomaticConnection)
        , m_immediatelyPause(immediatelyPause)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_isAutomaticConnection;
        encoder << m_immediatelyPause;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    bool m_isAutomaticConnection;
    bool m_immediatelyPause;
};
#endif

#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
class DisconnectFromInspector {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_DisconnectFromInspector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DisconnectFromInspector(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
};
#endif

#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
class DispatchMessageFromInspector {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_DispatchMessageFromInspector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchMessageFromInspector(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const String& message)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_message(message)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    const String& m_message;
};
#endif

#if ((ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)) && ENABLE(REMOTE_INSPECTOR_SERVICE_WORKER_AUTO_INSPECTION))
class UnpauseServiceWorkerForRejectedAutomaticInspection {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWContextManagerConnection_UnpauseServiceWorkerForRejectedAutomaticInspection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UnpauseServiceWorkerForRejectedAutomaticInspection(const WebCore::ServiceWorkerIdentifier& identifier)
        : m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};
#endif

} // namespace WebSWContextManagerConnection
} // namespace Messages
