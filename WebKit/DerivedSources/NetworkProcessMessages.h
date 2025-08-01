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
#include "ConnectionHandle.h"
#include "MessageNames.h"
#include "NetworkProcessCreationParameters.h"
#include "SandboxExtension.h"
#include "WebsiteDataStoreParameters.h"
#include <WebCore/CrossSiteNavigationDataTransfer.h>
#include <WebCore/NotificationPayload.h>
#include <WebCore/ProcessIdentifier.h>
#include <optional>
#include <span>
#include <utility>
#include <wtf/Forward.h>
#include <wtf/HashMap.h>
#include <wtf/HashSet.h>
#include <wtf/OptionSet.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/UUID.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class FormDataReference;
}

namespace PAL {
class SessionID;
}

namespace WTF {
class UUID;
}

namespace WebCore {
class CertificateInfo;
class CurlProxySettings;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
class PrivateClickMeasurement;
struct ProcessIdentifierType;
using ProcessIdentifier = ObjectIdentifier<ProcessIdentifierType>;
class RegistrableDomain;
class ResourceRequest;
class SecurityOriginData;
enum class NotificationEventType : bool;
enum class SameSiteStrictEnforcementEnabled : bool;
enum class FirstPartyWebsiteDataRemovalMode : uint8_t;
enum class HTTPCookieAcceptPolicy : uint8_t;
enum class PushPermissionState : uint8_t;
enum class StoredCredentialsPolicy : uint8_t;
enum class ThirdPartyCookieBlockingMode : uint8_t;
struct ClientOrigin;
struct NotificationData;
struct SoupNetworkProxySettings;
}

namespace WebKit {
struct DataTaskIdentifierType;
using DataTaskIdentifier = ObjectIdentifier<DataTaskIdentifierType>;
struct DownloadIDType;
using DownloadID = ObjectIdentifier<DownloadIDType>;
struct QuotaIncreaseRequestIdentifierType;
using QuotaIncreaseRequestIdentifier = AtomicObjectIdentifier<QuotaIncreaseRequestIdentifierType>;
class WebPageNetworkParameters;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
enum class CallDownloadDidStart : bool;
enum class DidFilterKnownLinkDecoration : bool;
enum class LoadedWebArchive : bool;
enum class NavigatingToAppBoundDomain : bool;
enum class ShouldGrandfatherStatistics : bool;
enum class UseDownloadPlaceholder : bool;
enum class CacheModel : uint8_t;
enum class RemoteWorkerType : uint8_t;
struct AppPrivacyReportTestingData;
struct BackgroundFetchState;
struct NetworkProcessConnectionParameters;
struct SharedPreferencesForWebProcess;
struct WebPushMessage;
struct WebsiteData;
}

namespace Messages {
namespace NetworkProcess {

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
    return IPC::ReceiverName::NetworkProcess;
}

class InitializeNetworkProcess {
public:
    using Arguments = std::tuple<WebKit::NetworkProcessCreationParameters>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_InitializeNetworkProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_InitializeNetworkProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit InitializeNetworkProcess(WebKit::NetworkProcessCreationParameters&& processCreationParameters)
        : m_processCreationParameters(WTFMove(processCreationParameters))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_processCreationParameters);
    }

private:
    WebKit::NetworkProcessCreationParameters&& m_processCreationParameters;
};

class CreateNetworkConnectionToWebProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, PAL::SessionID, WebKit::NetworkProcessConnectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_CreateNetworkConnectionToWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_CreateNetworkConnectionToWebProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::ConnectionHandle>, WebCore::HTTPCookieAcceptPolicy>;
    using Reply = CompletionHandler<void(std::optional<IPC::ConnectionHandle>&&, WebCore::HTTPCookieAcceptPolicy)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<IPC::ConnectionHandle>, WebCore::HTTPCookieAcceptPolicy>, IPC::Error>;
    CreateNetworkConnectionToWebProcess(const WebCore::ProcessIdentifier& processIdentifier, const PAL::SessionID& sessionID, const WebKit::NetworkProcessConnectionParameters& parameters)
        : m_processIdentifier(processIdentifier)
        , m_sessionID(sessionID)
        , m_parameters(parameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::NetworkProcessConnectionParameters& m_parameters;
};

class SharedPreferencesForWebProcessDidChange {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebKit::SharedPreferencesForWebProcess>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SharedPreferencesForWebProcessDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SharedPreferencesForWebProcessDidChangeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SharedPreferencesForWebProcessDidChange(const WebCore::ProcessIdentifier& processIdentifier, const WebKit::SharedPreferencesForWebProcess& sharedPreferencesForWebProcess)
        : m_processIdentifier(processIdentifier)
        , m_sharedPreferencesForWebProcess(sharedPreferencesForWebProcess)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedPreferencesForWebProcess;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::SharedPreferencesForWebProcess& m_sharedPreferencesForWebProcess;
};

class AddAllowedFirstPartyForCookies {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::RegistrableDomain, WebKit::LoadedWebArchive>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AddAllowedFirstPartyForCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_AddAllowedFirstPartyForCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    AddAllowedFirstPartyForCookies(const WebCore::ProcessIdentifier& processIdentifier, const WebCore::RegistrableDomain& firstPartyForCookies, WebKit::LoadedWebArchive loadedWebArchive)
        : m_processIdentifier(processIdentifier)
        , m_firstPartyForCookies(firstPartyForCookies)
        , m_loadedWebArchive(loadedWebArchive)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstPartyForCookies;
        encoder << m_loadedWebArchive;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_firstPartyForCookies;
    WebKit::LoadedWebArchive m_loadedWebArchive;
};

#if USE(SOUP)
class SetIgnoreTLSErrors {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetIgnoreTLSErrors; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetIgnoreTLSErrors(const PAL::SessionID& sessionID, bool ignoreTLSErrors)
        : m_sessionID(sessionID)
        , m_ignoreTLSErrors(ignoreTLSErrors)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_ignoreTLSErrors;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_ignoreTLSErrors;
};
#endif

#if USE(SOUP)
class UserPreferredLanguagesChanged {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_UserPreferredLanguagesChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UserPreferredLanguagesChanged(const Vector<String>& languages)
        : m_languages(languages)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_languages;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_languages;
};
#endif

#if USE(SOUP)
class SetNetworkProxySettings {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::SoupNetworkProxySettings>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetNetworkProxySettings; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetNetworkProxySettings(const PAL::SessionID& sessionID, const WebCore::SoupNetworkProxySettings& settings)
        : m_sessionID(sessionID)
        , m_settings(settings)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_settings;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SoupNetworkProxySettings& m_settings;
};
#endif

#if USE(SOUP)
class PrefetchDNS {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_PrefetchDNS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PrefetchDNS(const String& hostname)
        : m_hostname(hostname)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hostname;
    }

private:
    const String& m_hostname;
};
#endif

#if USE(SOUP)
class SetPersistentCredentialStorageEnabled {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPersistentCredentialStorageEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetPersistentCredentialStorageEnabled(const PAL::SessionID& sessionID, bool enabled)
        : m_sessionID(sessionID)
        , m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_enabled;
};
#endif

#if USE(CURL)
class SetNetworkProxySettings {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::CurlProxySettings>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetNetworkProxySettings; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetNetworkProxySettings(const PAL::SessionID& sessionID, const WebCore::CurlProxySettings& settings)
        : m_sessionID(sessionID)
        , m_settings(settings)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_settings;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CurlProxySettings& m_settings;
};
#endif

class AddWebsiteDataStore {
public:
    using Arguments = std::tuple<WebKit::WebsiteDataStoreParameters>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AddWebsiteDataStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddWebsiteDataStore(WebKit::WebsiteDataStoreParameters&& websiteDataStoreParameters)
        : m_websiteDataStoreParameters(WTFMove(websiteDataStoreParameters))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_websiteDataStoreParameters);
    }

private:
    WebKit::WebsiteDataStoreParameters&& m_websiteDataStoreParameters;
};

class DestroySession {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DestroySession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_DestroySessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit DestroySession(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class EnsureSessionWithDataStoreIdentifierRemoved {
public:
    using Arguments = std::tuple<WTF::UUID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_EnsureSessionWithDataStoreIdentifierRemoved; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_EnsureSessionWithDataStoreIdentifierRemovedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit EnsureSessionWithDataStoreIdentifierRemoved(const WTF::UUID& identifier)
        : m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_identifier;
};

class FetchWebsiteData {
public:
    using Arguments = std::tuple<PAL::SessionID, OptionSet<WebKit::WebsiteDataType>, OptionSet<WebKit::WebsiteDataFetchOption>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_FetchWebsiteData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_FetchWebsiteDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::WebsiteData>;
    using Reply = CompletionHandler<void(WebKit::WebsiteData&&)>;
    using Promise = WTF::NativePromise<WebKit::WebsiteData, IPC::Error>;
    FetchWebsiteData(const PAL::SessionID& sessionID, const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes, const OptionSet<WebKit::WebsiteDataFetchOption>& fetchOptions)
        : m_sessionID(sessionID)
        , m_websiteDataTypes(websiteDataTypes)
        , m_fetchOptions(fetchOptions)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fetchOptions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataFetchOption>& m_fetchOptions;
};

class DeleteWebsiteData {
public:
    using Arguments = std::tuple<PAL::SessionID, OptionSet<WebKit::WebsiteDataType>, WallTime, HashSet<WebCore::ProcessIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DeleteWebsiteData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_DeleteWebsiteDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteWebsiteData(const PAL::SessionID& sessionID, const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes, const WallTime& modifiedSince, const HashSet<WebCore::ProcessIdentifier>& activeWebProcesses)
        : m_sessionID(sessionID)
        , m_websiteDataTypes(websiteDataTypes)
        , m_modifiedSince(modifiedSince)
        , m_activeWebProcesses(activeWebProcesses)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiedSince;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_activeWebProcesses;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_modifiedSince;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<WebCore::ProcessIdentifier>& m_activeWebProcesses;
};

class DeleteWebsiteDataForOrigins {
public:
    using Arguments = std::tuple<PAL::SessionID, OptionSet<WebKit::WebsiteDataType>, Vector<WebCore::SecurityOriginData>, Vector<String>, Vector<String>, Vector<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DeleteWebsiteDataForOrigins; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_DeleteWebsiteDataForOriginsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteWebsiteDataForOrigins(const PAL::SessionID& sessionID, const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes, const Vector<WebCore::SecurityOriginData>& origins, const Vector<String>& cookieHostNames, const Vector<String>& HSTSCacheHostNames, const Vector<WebCore::RegistrableDomain>& registrableDomains)
        : m_sessionID(sessionID)
        , m_websiteDataTypes(websiteDataTypes)
        , m_origins(origins)
        , m_cookieHostNames(cookieHostNames)
        , m_HSTSCacheHostNames(HSTSCacheHostNames)
        , m_registrableDomains(registrableDomains)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origins;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookieHostNames;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_HSTSCacheHostNames;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrableDomains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::SecurityOriginData>& m_origins;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_cookieHostNames;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_HSTSCacheHostNames;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::RegistrableDomain>& m_registrableDomains;
};

class RenameOriginInWebsiteData {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::SecurityOriginData, WebCore::SecurityOriginData, OptionSet<WebKit::WebsiteDataType>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RenameOriginInWebsiteData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_RenameOriginInWebsiteDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    RenameOriginInWebsiteData(const PAL::SessionID& sessionID, const WebCore::SecurityOriginData& oldOrigin, const WebCore::SecurityOriginData& newOrigin, const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes)
        : m_sessionID(sessionID)
        , m_oldOrigin(oldOrigin)
        , m_newOrigin(newOrigin)
        , m_websiteDataTypes(websiteDataTypes)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_oldOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_oldOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_newOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
};

class WebsiteDataOriginDirectoryForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::ClientOrigin, OptionSet<WebKit::WebsiteDataType>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_WebsiteDataOriginDirectoryForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_WebsiteDataOriginDirectoryForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    WebsiteDataOriginDirectoryForTesting(const PAL::SessionID& sessionID, const WebCore::ClientOrigin& origin, const OptionSet<WebKit::WebsiteDataType>& websiteDataType)
        : m_sessionID(sessionID)
        , m_origin(origin)
        , m_websiteDataType(websiteDataType)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataType;
};

class DownloadRequest {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::DownloadID, WebCore::ResourceRequest, std::optional<WebCore::SecurityOriginData>, std::optional<WebKit::NavigatingToAppBoundDomain>, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DownloadRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DownloadRequest(const PAL::SessionID& sessionID, const WebKit::DownloadID& downloadID, const WebCore::ResourceRequest& request, const std::optional<WebCore::SecurityOriginData>& topOrigin, std::optional<WebKit::NavigatingToAppBoundDomain> isNavigatingToAppBoundDomain, const String& suggestedFilename)
        : m_sessionID(sessionID)
        , m_downloadID(downloadID)
        , m_request(request)
        , m_topOrigin(topOrigin)
        , m_isNavigatingToAppBoundDomain(isNavigatingToAppBoundDomain)
        , m_suggestedFilename(suggestedFilename)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_downloadID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        encoder << m_isNavigatingToAppBoundDomain;
        encoder << m_suggestedFilename;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DownloadID& m_downloadID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
    std::optional<WebKit::NavigatingToAppBoundDomain> m_isNavigatingToAppBoundDomain;
    const String& m_suggestedFilename;
};

class ResumeDownload {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::DownloadID, std::span<const uint8_t>, String, WebKit::SandboxExtensionHandle, WebKit::CallDownloadDidStart, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResumeDownload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResumeDownload(const PAL::SessionID& sessionID, const WebKit::DownloadID& downloadID, const std::span<const uint8_t>& resumeData, const String& path, WebKit::SandboxExtensionHandle&& sandboxExtensionHandle, WebKit::CallDownloadDidStart callDownloadDidStart, const std::span<const uint8_t>& activityAccessToken)
        : m_sessionID(sessionID)
        , m_downloadID(downloadID)
        , m_resumeData(resumeData)
        , m_path(path)
        , m_sandboxExtensionHandle(WTFMove(sandboxExtensionHandle))
        , m_callDownloadDidStart(callDownloadDidStart)
        , m_activityAccessToken(activityAccessToken)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_downloadID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resumeData;
        encoder << m_path;
        encoder << WTFMove(m_sandboxExtensionHandle);
        encoder << m_callDownloadDidStart;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_activityAccessToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DownloadID& m_downloadID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_resumeData;
    const String& m_path;
    WebKit::SandboxExtensionHandle&& m_sandboxExtensionHandle;
    WebKit::CallDownloadDidStart m_callDownloadDidStart;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_activityAccessToken;
};

class CancelDownload {
public:
    using Arguments = std::tuple<WebKit::DownloadID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_CancelDownload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_CancelDownloadReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::span<const uint8_t>>;
    using Reply = CompletionHandler<void(std::span<const uint8_t>&&)>;
    using Promise = WTF::NativePromise<std::span<const uint8_t>, IPC::Error>;
    explicit CancelDownload(const WebKit::DownloadID& downloadID)
        : m_downloadID(downloadID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_downloadID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DownloadID& m_downloadID;
};

#if (PLATFORM(COCOA) && HAVE(MODERN_DOWNLOADPROGRESS))
class PublishDownloadProgress {
public:
    using Arguments = std::tuple<WebKit::DownloadID, URL, std::span<const uint8_t>, WebKit::UseDownloadPlaceholder, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_PublishDownloadProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PublishDownloadProgress(const WebKit::DownloadID& downloadID, const URL& url, const std::span<const uint8_t>& bookmarkData, WebKit::UseDownloadPlaceholder useDownloadPlaceholder, const std::span<const uint8_t>& activityAccessToken)
        : m_downloadID(downloadID)
        , m_url(url)
        , m_bookmarkData(bookmarkData)
        , m_useDownloadPlaceholder(useDownloadPlaceholder)
        , m_activityAccessToken(activityAccessToken)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_downloadID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bookmarkData;
        encoder << m_useDownloadPlaceholder;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_activityAccessToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DownloadID& m_downloadID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_bookmarkData;
    WebKit::UseDownloadPlaceholder m_useDownloadPlaceholder;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_activityAccessToken;
};
#endif

#if (PLATFORM(COCOA) && !HAVE(MODERN_DOWNLOADPROGRESS))
class PublishDownloadProgress {
public:
    using Arguments = std::tuple<WebKit::DownloadID, URL, WebKit::SandboxExtensionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_PublishDownloadProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PublishDownloadProgress(const WebKit::DownloadID& downloadID, const URL& url, WebKit::SandboxExtensionHandle&& sandboxExtensionHandle)
        : m_downloadID(downloadID)
        , m_url(url)
        , m_sandboxExtensionHandle(WTFMove(sandboxExtensionHandle))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_downloadID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << WTFMove(m_sandboxExtensionHandle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DownloadID& m_downloadID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    WebKit::SandboxExtensionHandle&& m_sandboxExtensionHandle;
};
#endif

class DataTaskWithRequest {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, PAL::SessionID, WebCore::ResourceRequest, std::optional<WebCore::SecurityOriginData>, IPC::FormDataReference>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DataTaskWithRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_DataTaskWithRequestReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::DataTaskIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::DataTaskIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::DataTaskIdentifier>, IPC::Error>;
    DataTaskWithRequest(const WebKit::WebPageProxyIdentifier& pageID, const PAL::SessionID& sessionID, const WebCore::ResourceRequest& request, const std::optional<WebCore::SecurityOriginData>& topOrigin, const IPC::FormDataReference& requestBody)
        : m_pageID(pageID)
        , m_sessionID(sessionID)
        , m_request(request)
        , m_topOrigin(topOrigin)
        , m_requestBody(requestBody)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestBody;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::FormDataReference& m_requestBody;
};

class CancelDataTask {
public:
    using Arguments = std::tuple<WebKit::DataTaskIdentifier, PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_CancelDataTask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_CancelDataTaskReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    CancelDataTask(const WebKit::DataTaskIdentifier& taskIdentifier, const PAL::SessionID& sessionID)
        : m_taskIdentifier(taskIdentifier)
        , m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_taskIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DataTaskIdentifier& m_taskIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class ApplicationDidEnterBackground {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ApplicationDidEnterBackground; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ApplicationDidEnterBackground()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ApplicationWillEnterForeground {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ApplicationWillEnterForeground; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ApplicationWillEnterForeground()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class FlushCookies {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_FlushCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_FlushCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit FlushCookies(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

#if !PLATFORM(COCOA)
class AllowSpecificHTTPSCertificateForHost {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::CertificateInfo, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AllowSpecificHTTPSCertificateForHost; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AllowSpecificHTTPSCertificateForHost(const PAL::SessionID& sessionID, const WebCore::CertificateInfo& certificate, const String& host)
        : m_sessionID(sessionID)
        , m_certificate(certificate)
        , m_host(host)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_certificate;
        encoder << m_host;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CertificateInfo& m_certificate;
    const String& m_host;
};
#endif

class AllowTLSCertificateChainForLocalPCMTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::CertificateInfo>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AllowTLSCertificateChainForLocalPCMTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AllowTLSCertificateChainForLocalPCMTesting(const PAL::SessionID& sessionID, const WebCore::CertificateInfo& certificate)
        : m_sessionID(sessionID)
        , m_certificate(certificate)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_certificate;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CertificateInfo& m_certificate;
};

class SetCacheModel {
public:
    using Arguments = std::tuple<WebKit::CacheModel>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetCacheModel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCacheModel(WebKit::CacheModel cacheModel)
        : m_cacheModel(cacheModel)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheModel;
    }

private:
    WebKit::CacheModel m_cacheModel;
};

class SetCacheModelSynchronouslyForTesting {
public:
    using Arguments = std::tuple<WebKit::CacheModel>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetCacheModelSynchronouslyForTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    explicit SetCacheModelSynchronouslyForTesting(WebKit::CacheModel cacheModel)
        : m_cacheModel(cacheModel)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheModel;
    }

private:
    WebKit::CacheModel m_cacheModel;
};

class ProcessWillSuspendImminentlyForTestingSync {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ProcessWillSuspendImminentlyForTestingSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    ProcessWillSuspendImminentlyForTestingSync()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PrepareToSuspend {
public:
    using Arguments = std::tuple<bool, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_PrepareToSuspend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_PrepareToSuspendReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PrepareToSuspend(bool isSuspensionImminent, const MonotonicTime& estimatedSuspendTime)
        : m_isSuspensionImminent(isSuspensionImminent)
        , m_estimatedSuspendTime(estimatedSuspendTime)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isSuspensionImminent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_estimatedSuspendTime;
    }

private:
    bool m_isSuspensionImminent;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_estimatedSuspendTime;
};

class ProcessDidResume {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ProcessDidResume; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ProcessDidResume(bool forForegroundActivity)
        : m_forForegroundActivity(forForegroundActivity)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_forForegroundActivity;
    }

private:
    bool m_forForegroundActivity;
};

class NotifyMediaStreamingActivity {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_NotifyMediaStreamingActivity; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit NotifyMediaStreamingActivity(bool activity)
        : m_activity(activity)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_activity;
    }

private:
    bool m_activity;
};

class PreconnectTo {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier, WebCore::ResourceRequest, WebCore::StoredCredentialsPolicy, std::optional<WebKit::NavigatingToAppBoundDomain>, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_PreconnectTo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PreconnectTo(const PAL::SessionID& sessionID, const WebKit::WebPageProxyIdentifier& webPageProxyID, const WebCore::PageIdentifier& webPageID, const WebCore::ResourceRequest& request, WebCore::StoredCredentialsPolicy storedCredentialsPolicy, std::optional<WebKit::NavigatingToAppBoundDomain> isNavigatingToAppBoundDomain, uint64_t requiredCookiesVersion)
        : m_sessionID(sessionID)
        , m_webPageProxyID(webPageProxyID)
        , m_webPageID(webPageID)
        , m_request(request)
        , m_storedCredentialsPolicy(storedCredentialsPolicy)
        , m_isNavigatingToAppBoundDomain(isNavigatingToAppBoundDomain)
        , m_requiredCookiesVersion(requiredCookiesVersion)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        encoder << m_storedCredentialsPolicy;
        encoder << m_isNavigatingToAppBoundDomain;
        encoder << m_requiredCookiesVersion;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_webPageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    WebCore::StoredCredentialsPolicy m_storedCredentialsPolicy;
    std::optional<WebKit::NavigatingToAppBoundDomain> m_isNavigatingToAppBoundDomain;
    uint64_t m_requiredCookiesVersion;
};

class SetInspectionForServiceWorkersAllowed {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetInspectionForServiceWorkersAllowed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetInspectionForServiceWorkersAllowed(const PAL::SessionID& sessionID, bool inspectable)
        : m_sessionID(sessionID)
        , m_inspectable(inspectable)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_inspectable;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_inspectable;
};

class ClearPrevalentResource {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClearPrevalentResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClearPrevalentResourceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ClearPrevalentResource(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
};

class ClearUserInteraction {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClearUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClearUserInteractionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ClearUserInteraction(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
};

class DumpResourceLoadStatistics {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DumpResourceLoadStatistics; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_DumpResourceLoadStatisticsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit DumpResourceLoadStatistics(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetTrackingPreventionEnabled {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetTrackingPreventionEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetTrackingPreventionEnabled(const PAL::SessionID& sessionID, bool enabled)
        : m_sessionID(sessionID)
        , m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_enabled;
};

class UpdateStorageAccessPromptQuirks {
public:
    using Arguments = std::tuple<Vector<WebCore::OrganizationStorageAccessPromptQuirk>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_UpdateStorageAccessPromptQuirks; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateStorageAccessPromptQuirks(const Vector<WebCore::OrganizationStorageAccessPromptQuirk>& organizationStorageAccessQuirks)
        : m_organizationStorageAccessQuirks(organizationStorageAccessQuirks)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_organizationStorageAccessQuirks;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::OrganizationStorageAccessPromptQuirk>& m_organizationStorageAccessQuirks;
};

class SetResourceLoadStatisticsLogTestingEvent {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetResourceLoadStatisticsLogTestingEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetResourceLoadStatisticsLogTestingEvent(bool enabled)
        : m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enabled;
    }

private:
    bool m_enabled;
};

class UpdatePrevalentDomainsToBlockCookiesFor {
public:
    using Arguments = std::tuple<PAL::SessionID, Vector<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_UpdatePrevalentDomainsToBlockCookiesFor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_UpdatePrevalentDomainsToBlockCookiesForReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UpdatePrevalentDomainsToBlockCookiesFor(const PAL::SessionID& sessionID, const Vector<WebCore::RegistrableDomain>& domainsToBlock)
        : m_sessionID(sessionID)
        , m_domainsToBlock(domainsToBlock)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domainsToBlock;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::RegistrableDomain>& m_domainsToBlock;
};

class IsGrandfathered {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_IsGrandfathered; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_IsGrandfatheredReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsGrandfathered(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& targetDomain)
        : m_sessionID(sessionID)
        , m_targetDomain(targetDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_targetDomain;
};

class IsPrevalentResource {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_IsPrevalentResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_IsPrevalentResourceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsPrevalentResource(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& targetDomain)
        : m_sessionID(sessionID)
        , m_targetDomain(targetDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_targetDomain;
};

class IsVeryPrevalentResource {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_IsVeryPrevalentResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_IsVeryPrevalentResourceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsVeryPrevalentResource(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& targetDomain)
        : m_sessionID(sessionID)
        , m_targetDomain(targetDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_targetDomain;
};

class SetLastSeen {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetLastSeen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetLastSeenReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetLastSeen(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain, const Seconds& seconds)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
        , m_seconds(seconds)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_seconds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_seconds;
};

class MergeStatisticForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain, WebCore::RegistrableDomain, Seconds, bool, Seconds, bool, bool, bool, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_MergeStatisticForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_MergeStatisticForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    MergeStatisticForTesting(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain, const WebCore::RegistrableDomain& topFrameDomain1, const WebCore::RegistrableDomain& topFrameDomain2, const Seconds& lastSeen, bool hadUserInteraction, const Seconds& mostRecentUserInteraction, bool isGrandfathered, bool isPrevalent, bool isVeryPrevalent, uint64_t dataRecordsRemoved)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
        , m_topFrameDomain1(topFrameDomain1)
        , m_topFrameDomain2(topFrameDomain2)
        , m_lastSeen(lastSeen)
        , m_hadUserInteraction(hadUserInteraction)
        , m_mostRecentUserInteraction(mostRecentUserInteraction)
        , m_isGrandfathered(isGrandfathered)
        , m_isPrevalent(isPrevalent)
        , m_isVeryPrevalent(isVeryPrevalent)
        , m_dataRecordsRemoved(dataRecordsRemoved)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain1;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain2;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lastSeen;
        encoder << m_hadUserInteraction;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mostRecentUserInteraction;
        encoder << m_isGrandfathered;
        encoder << m_isPrevalent;
        encoder << m_isVeryPrevalent;
        encoder << m_dataRecordsRemoved;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain1;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain2;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_lastSeen;
    bool m_hadUserInteraction;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_mostRecentUserInteraction;
    bool m_isGrandfathered;
    bool m_isPrevalent;
    bool m_isVeryPrevalent;
    uint64_t m_dataRecordsRemoved;
};

class InsertExpiredStatisticForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, uint64_t, bool, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_InsertExpiredStatisticForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_InsertExpiredStatisticForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    InsertExpiredStatisticForTesting(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain, uint64_t numberOfOperatingDaysPassed, bool hadUserInteraction, bool isScheduledForAllButCookieDataRemoval, bool isPrevalent)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
        , m_numberOfOperatingDaysPassed(numberOfOperatingDaysPassed)
        , m_hadUserInteraction(hadUserInteraction)
        , m_isScheduledForAllButCookieDataRemoval(isScheduledForAllButCookieDataRemoval)
        , m_isPrevalent(isPrevalent)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
        encoder << m_numberOfOperatingDaysPassed;
        encoder << m_hadUserInteraction;
        encoder << m_isScheduledForAllButCookieDataRemoval;
        encoder << m_isPrevalent;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
    uint64_t m_numberOfOperatingDaysPassed;
    bool m_hadUserInteraction;
    bool m_isScheduledForAllButCookieDataRemoval;
    bool m_isPrevalent;
};

class SetPrevalentResource {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrevalentResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPrevalentResourceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPrevalentResource(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
};

class SetPrevalentResourceForDebugMode {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrevalentResourceForDebugMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPrevalentResourceForDebugModeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPrevalentResourceForDebugMode(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
};

class IsResourceLoadStatisticsEphemeral {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_IsResourceLoadStatisticsEphemeral; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_IsResourceLoadStatisticsEphemeralReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit IsResourceLoadStatisticsEphemeral(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class HadUserInteraction {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_HadUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_HadUserInteractionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    HadUserInteraction(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
};

class IsRelationshipOnlyInDatabaseOnce {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_IsRelationshipOnlyInDatabaseOnce; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_IsRelationshipOnlyInDatabaseOnceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsRelationshipOnlyInDatabaseOnce(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& subDomain, const WebCore::RegistrableDomain& topDomain)
        : m_sessionID(sessionID)
        , m_subDomain(subDomain)
        , m_topDomain(topDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topDomain;
};

class HasLocalStorage {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_HasLocalStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_HasLocalStorageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    HasLocalStorage(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
};

class GetAllStorageAccessEntries {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_GetAllStorageAccessEntries; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_GetAllStorageAccessEntriesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    using Promise = WTF::NativePromise<Vector<String>, IPC::Error>;
    explicit GetAllStorageAccessEntries(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class IsRegisteredAsRedirectingTo {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_IsRegisteredAsRedirectingTo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_IsRegisteredAsRedirectingToReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsRegisteredAsRedirectingTo(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& redirectedFromDomain, const WebCore::RegistrableDomain& redirectedToDomain)
        : m_sessionID(sessionID)
        , m_redirectedFromDomain(redirectedFromDomain)
        , m_redirectedToDomain(redirectedToDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectedFromDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectedToDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_redirectedFromDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_redirectedToDomain;
};

class IsRegisteredAsSubFrameUnder {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_IsRegisteredAsSubFrameUnder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_IsRegisteredAsSubFrameUnderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsRegisteredAsSubFrameUnder(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& subFrameDomain, const WebCore::RegistrableDomain& topFrameDomain)
        : m_sessionID(sessionID)
        , m_subFrameDomain(subFrameDomain)
        , m_topFrameDomain(topFrameDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
};

class IsRegisteredAsSubresourceUnder {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_IsRegisteredAsSubresourceUnder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_IsRegisteredAsSubresourceUnderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsRegisteredAsSubresourceUnder(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& subresourceDomain, const WebCore::RegistrableDomain& topFrameDomain)
        : m_sessionID(sessionID)
        , m_subresourceDomain(subresourceDomain)
        , m_topFrameDomain(topFrameDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subresourceDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subresourceDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
};

class DomainIDExistsInDatabase {
public:
    using Arguments = std::tuple<PAL::SessionID, int>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DomainIDExistsInDatabase; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_DomainIDExistsInDatabaseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    DomainIDExistsInDatabase(const PAL::SessionID& sessionID, const int& domainID)
        : m_sessionID(sessionID)
        , m_domainID(domainID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domainID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_domainID;
};

class LogFrameNavigation {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain, WebCore::RegistrableDomain, bool, bool, Seconds, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_LogFrameNavigation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogFrameNavigation(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& targetDomain, const WebCore::RegistrableDomain& topFrameDomain, const WebCore::RegistrableDomain& sourceDomain, bool isRedirect, bool isMainFrame, const Seconds& delayAfterMainFrameDocumentLoad, bool wasPotentiallyInitiatedByUser)
        : m_sessionID(sessionID)
        , m_targetDomain(targetDomain)
        , m_topFrameDomain(topFrameDomain)
        , m_sourceDomain(sourceDomain)
        , m_isRedirect(isRedirect)
        , m_isMainFrame(isMainFrame)
        , m_delayAfterMainFrameDocumentLoad(delayAfterMainFrameDocumentLoad)
        , m_wasPotentiallyInitiatedByUser(wasPotentiallyInitiatedByUser)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourceDomain;
        encoder << m_isRedirect;
        encoder << m_isMainFrame;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_delayAfterMainFrameDocumentLoad;
        encoder << m_wasPotentiallyInitiatedByUser;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_targetDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_sourceDomain;
    bool m_isRedirect;
    bool m_isMainFrame;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_delayAfterMainFrameDocumentLoad;
    bool m_wasPotentiallyInitiatedByUser;
};

class LogUserInteraction {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_LogUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_LogUserInteractionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    LogUserInteraction(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& topFrameDomain)
        : m_sessionID(sessionID)
        , m_topFrameDomain(topFrameDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
};

class ResetParametersToDefaultValues {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResetParametersToDefaultValues; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ResetParametersToDefaultValuesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ResetParametersToDefaultValues(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class ScheduleClearInMemoryAndPersistent {
public:
    using Arguments = std::tuple<PAL::SessionID, std::optional<WallTime>, WebKit::ShouldGrandfatherStatistics>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ScheduleClearInMemoryAndPersistent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ScheduleClearInMemoryAndPersistentReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ScheduleClearInMemoryAndPersistent(const PAL::SessionID& sessionID, const std::optional<WallTime>& modifiedSince, WebKit::ShouldGrandfatherStatistics shouldGrandfather)
        : m_sessionID(sessionID)
        , m_modifiedSince(modifiedSince)
        , m_shouldGrandfather(shouldGrandfather)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiedSince;
        encoder << m_shouldGrandfather;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WallTime>& m_modifiedSince;
    WebKit::ShouldGrandfatherStatistics m_shouldGrandfather;
};

class ScheduleCookieBlockingUpdate {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ScheduleCookieBlockingUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ScheduleCookieBlockingUpdateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ScheduleCookieBlockingUpdate(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class ScheduleStatisticsAndDataRecordsProcessing {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ScheduleStatisticsAndDataRecordsProcessing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ScheduleStatisticsAndDataRecordsProcessingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ScheduleStatisticsAndDataRecordsProcessing(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class StatisticsDatabaseHasAllTables {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_StatisticsDatabaseHasAllTables; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_StatisticsDatabaseHasAllTablesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit StatisticsDatabaseHasAllTables(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetCacheMaxAgeCapForPrevalentResources {
public:
    using Arguments = std::tuple<PAL::SessionID, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetCacheMaxAgeCapForPrevalentResources; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetCacheMaxAgeCapForPrevalentResourcesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetCacheMaxAgeCapForPrevalentResources(const PAL::SessionID& sessionID, const Seconds& seconds)
        : m_sessionID(sessionID)
        , m_seconds(seconds)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_seconds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_seconds;
};

class SetGrandfathered {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetGrandfathered; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetGrandfatheredReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetGrandfathered(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain, bool isGrandfathered)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
        , m_isGrandfathered(isGrandfathered)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
        encoder << m_isGrandfathered;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
    bool m_isGrandfathered;
};

class GetResourceLoadStatisticsDataSummary {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_GetResourceLoadStatisticsDataSummary; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_GetResourceLoadStatisticsDataSummaryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::ITPThirdPartyData>>;
    using Reply = CompletionHandler<void(Vector<WebKit::ITPThirdPartyData>&&)>;
    using Promise = WTF::NativePromise<Vector<WebKit::ITPThirdPartyData>, IPC::Error>;
    explicit GetResourceLoadStatisticsDataSummary(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetGrandfatheringTime {
public:
    using Arguments = std::tuple<PAL::SessionID, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetGrandfatheringTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetGrandfatheringTimeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetGrandfatheringTime(const PAL::SessionID& sessionID, const Seconds& seconds)
        : m_sessionID(sessionID)
        , m_seconds(seconds)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_seconds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_seconds;
};

class SetMaxStatisticsEntries {
public:
    using Arguments = std::tuple<PAL::SessionID, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetMaxStatisticsEntries; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetMaxStatisticsEntriesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetMaxStatisticsEntries(const PAL::SessionID& sessionID, uint64_t maximumEntryCount)
        : m_sessionID(sessionID)
        , m_maximumEntryCount(maximumEntryCount)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_maximumEntryCount;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    uint64_t m_maximumEntryCount;
};

class SetMinimumTimeBetweenDataRecordsRemoval {
public:
    using Arguments = std::tuple<PAL::SessionID, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetMinimumTimeBetweenDataRecordsRemoval; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetMinimumTimeBetweenDataRecordsRemovalReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetMinimumTimeBetweenDataRecordsRemoval(const PAL::SessionID& sessionID, const Seconds& seconds)
        : m_sessionID(sessionID)
        , m_seconds(seconds)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_seconds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_seconds;
};

class SetPruneEntriesDownTo {
public:
    using Arguments = std::tuple<PAL::SessionID, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPruneEntriesDownTo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPruneEntriesDownToReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPruneEntriesDownTo(const PAL::SessionID& sessionID, uint64_t maximumEntryCount)
        : m_sessionID(sessionID)
        , m_maximumEntryCount(maximumEntryCount)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_maximumEntryCount;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    uint64_t m_maximumEntryCount;
};

class SetShouldClassifyResourcesBeforeDataRecordsRemoval {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetShouldClassifyResourcesBeforeDataRecordsRemoval; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetShouldClassifyResourcesBeforeDataRecordsRemovalReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetShouldClassifyResourcesBeforeDataRecordsRemoval(const PAL::SessionID& sessionID, bool value)
        : m_sessionID(sessionID)
        , m_value(value)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_value;
};

class SetResourceLoadStatisticsTimeAdvanceForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetResourceLoadStatisticsTimeAdvanceForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetResourceLoadStatisticsTimeAdvanceForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetResourceLoadStatisticsTimeAdvanceForTesting(const PAL::SessionID& sessionID, const Seconds& time)
        : m_sessionID(sessionID)
        , m_time(time)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_time;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_time;
};

class SetIsRunningResourceLoadStatisticsTest {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetIsRunningResourceLoadStatisticsTest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetIsRunningResourceLoadStatisticsTestReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetIsRunningResourceLoadStatisticsTest(const PAL::SessionID& sessionID, bool value)
        : m_sessionID(sessionID)
        , m_value(value)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_value;
};

class SetResourceLoadStatisticsDebugMode {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetResourceLoadStatisticsDebugMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetResourceLoadStatisticsDebugModeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetResourceLoadStatisticsDebugMode(const PAL::SessionID& sessionID, bool debugMode)
        : m_sessionID(sessionID)
        , m_debugMode(debugMode)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_debugMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_debugMode;
};

class SetVeryPrevalentResource {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetVeryPrevalentResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetVeryPrevalentResourceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetVeryPrevalentResource(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& resourceDomain)
        : m_sessionID(sessionID)
        , m_resourceDomain(resourceDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_resourceDomain;
};

class SetSubframeUnderTopFrameDomain {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetSubframeUnderTopFrameDomain; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetSubframeUnderTopFrameDomainReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetSubframeUnderTopFrameDomain(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& subFrameDomain, const WebCore::RegistrableDomain& topFrameDomain)
        : m_sessionID(sessionID)
        , m_subFrameDomain(subFrameDomain)
        , m_topFrameDomain(topFrameDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
};

class SetSubresourceUnderTopFrameDomain {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetSubresourceUnderTopFrameDomain; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetSubresourceUnderTopFrameDomainReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetSubresourceUnderTopFrameDomain(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& subresourceDomain, const WebCore::RegistrableDomain& topFrameDomain)
        : m_sessionID(sessionID)
        , m_subresourceDomain(subresourceDomain)
        , m_topFrameDomain(topFrameDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subresourceDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subresourceDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
};

class SetSubresourceUniqueRedirectTo {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetSubresourceUniqueRedirectTo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetSubresourceUniqueRedirectToReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetSubresourceUniqueRedirectTo(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& subresourceDomain, const WebCore::RegistrableDomain& redirectedToDomain)
        : m_sessionID(sessionID)
        , m_subresourceDomain(subresourceDomain)
        , m_redirectedToDomain(redirectedToDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subresourceDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectedToDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subresourceDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_redirectedToDomain;
};

class SetSubresourceUniqueRedirectFrom {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetSubresourceUniqueRedirectFrom; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetSubresourceUniqueRedirectFromReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetSubresourceUniqueRedirectFrom(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& subresourceDomain, const WebCore::RegistrableDomain& redirectedFromDomain)
        : m_sessionID(sessionID)
        , m_subresourceDomain(subresourceDomain)
        , m_redirectedFromDomain(redirectedFromDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subresourceDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectedFromDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subresourceDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_redirectedFromDomain;
};

class SetTimeToLiveUserInteraction {
public:
    using Arguments = std::tuple<PAL::SessionID, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetTimeToLiveUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetTimeToLiveUserInteractionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetTimeToLiveUserInteraction(const PAL::SessionID& sessionID, const Seconds& seconds)
        : m_sessionID(sessionID)
        , m_seconds(seconds)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_seconds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_seconds;
};

class SetTopFrameUniqueRedirectTo {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetTopFrameUniqueRedirectTo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetTopFrameUniqueRedirectToReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetTopFrameUniqueRedirectTo(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& topFrameDomain, const WebCore::RegistrableDomain& redirectedToDomain)
        : m_sessionID(sessionID)
        , m_topFrameDomain(topFrameDomain)
        , m_redirectedToDomain(redirectedToDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectedToDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_redirectedToDomain;
};

class SetTopFrameUniqueRedirectFrom {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetTopFrameUniqueRedirectFrom; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetTopFrameUniqueRedirectFromReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetTopFrameUniqueRedirectFrom(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& topFrameDomain, const WebCore::RegistrableDomain& redirectedFromDomain)
        : m_sessionID(sessionID)
        , m_topFrameDomain(topFrameDomain)
        , m_redirectedFromDomain(redirectedFromDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectedFromDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_redirectedFromDomain;
};

class ResetCacheMaxAgeCapForPrevalentResources {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResetCacheMaxAgeCapForPrevalentResources; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ResetCacheMaxAgeCapForPrevalentResourcesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ResetCacheMaxAgeCapForPrevalentResources(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class DidCommitCrossSiteLoadWithDataTransfer {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain, OptionSet<WebCore::CrossSiteNavigationDataTransferFlag>, WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier, WebKit::DidFilterKnownLinkDecoration>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DidCommitCrossSiteLoadWithDataTransfer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCommitCrossSiteLoadWithDataTransfer(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& fromDomain, const WebCore::RegistrableDomain& toDomain, const OptionSet<WebCore::CrossSiteNavigationDataTransferFlag>& navigationDataTransfer, const WebKit::WebPageProxyIdentifier& webPageProxyID, const WebCore::PageIdentifier& webPageID, WebKit::DidFilterKnownLinkDecoration didFilterKnownLinkDecoration)
        : m_sessionID(sessionID)
        , m_fromDomain(fromDomain)
        , m_toDomain(toDomain)
        , m_navigationDataTransfer(navigationDataTransfer)
        , m_webPageProxyID(webPageProxyID)
        , m_webPageID(webPageID)
        , m_didFilterKnownLinkDecoration(didFilterKnownLinkDecoration)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fromDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_toDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationDataTransfer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageID;
        encoder << m_didFilterKnownLinkDecoration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_fromDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_toDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::CrossSiteNavigationDataTransferFlag>& m_navigationDataTransfer;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_webPageID;
    WebKit::DidFilterKnownLinkDecoration m_didFilterKnownLinkDecoration;
};

class SetCrossSiteLoadWithLinkDecorationForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, WebCore::RegistrableDomain, WebKit::DidFilterKnownLinkDecoration>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetCrossSiteLoadWithLinkDecorationForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetCrossSiteLoadWithLinkDecorationForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetCrossSiteLoadWithLinkDecorationForTesting(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& fromDomain, const WebCore::RegistrableDomain& toDomain, WebKit::DidFilterKnownLinkDecoration didFilterKnownLinkDecoration)
        : m_sessionID(sessionID)
        , m_fromDomain(fromDomain)
        , m_toDomain(toDomain)
        , m_didFilterKnownLinkDecoration(didFilterKnownLinkDecoration)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fromDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_toDomain;
        encoder << m_didFilterKnownLinkDecoration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_fromDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_toDomain;
    WebKit::DidFilterKnownLinkDecoration m_didFilterKnownLinkDecoration;
};

class ResetCrossSiteLoadsWithLinkDecorationForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResetCrossSiteLoadsWithLinkDecorationForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ResetCrossSiteLoadsWithLinkDecorationForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ResetCrossSiteLoadsWithLinkDecorationForTesting(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class GrantStorageAccessForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, Vector<WebCore::RegistrableDomain>, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_GrantStorageAccessForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_GrantStorageAccessForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    GrantStorageAccessForTesting(const PAL::SessionID& sessionID, const Vector<WebCore::RegistrableDomain>& subFrameDomain, const WebCore::RegistrableDomain& topFrameDomain)
        : m_sessionID(sessionID)
        , m_subFrameDomain(subFrameDomain)
        , m_topFrameDomain(topFrameDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::RegistrableDomain>& m_subFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
};

class DeleteCookiesForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DeleteCookiesForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_DeleteCookiesForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteCookiesForTesting(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& domain, bool includeHttpOnlyCookies)
        : m_sessionID(sessionID)
        , m_domain(domain)
        , m_includeHttpOnlyCookies(includeHttpOnlyCookies)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
        encoder << m_includeHttpOnlyCookies;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
    bool m_includeHttpOnlyCookies;
};

class HasIsolatedSession {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_HasIsolatedSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_HasIsolatedSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    HasIsolatedSession(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& domain)
        : m_sessionID(sessionID)
        , m_domain(domain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
};

class CloseITPDatabase {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_CloseITPDatabase; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_CloseITPDatabaseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit CloseITPDatabase(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

#if ENABLE(APP_BOUND_DOMAINS)
class SetAppBoundDomainsForResourceLoadStatistics {
public:
    using Arguments = std::tuple<PAL::SessionID, HashSet<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetAppBoundDomainsForResourceLoadStatistics; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetAppBoundDomainsForResourceLoadStatisticsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetAppBoundDomainsForResourceLoadStatistics(const PAL::SessionID& sessionID, const HashSet<WebCore::RegistrableDomain>& appBoundDomains)
        : m_sessionID(sessionID)
        , m_appBoundDomains(appBoundDomains)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_appBoundDomains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<WebCore::RegistrableDomain>& m_appBoundDomains;
};
#endif

#if ENABLE(MANAGED_DOMAINS)
class SetManagedDomainsForResourceLoadStatistics {
public:
    using Arguments = std::tuple<PAL::SessionID, HashSet<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetManagedDomainsForResourceLoadStatistics; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetManagedDomainsForResourceLoadStatisticsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetManagedDomainsForResourceLoadStatistics(const PAL::SessionID& sessionID, const HashSet<WebCore::RegistrableDomain>& appBoundDomains)
        : m_sessionID(sessionID)
        , m_appBoundDomains(appBoundDomains)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_appBoundDomains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<WebCore::RegistrableDomain>& m_appBoundDomains;
};
#endif

class SetShouldDowngradeReferrerForTesting {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetShouldDowngradeReferrerForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetShouldDowngradeReferrerForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetShouldDowngradeReferrerForTesting(bool enabled)
        : m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enabled;
    }

private:
    bool m_enabled;
};

class SetThirdPartyCookieBlockingMode {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::ThirdPartyCookieBlockingMode>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetThirdPartyCookieBlockingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetThirdPartyCookieBlockingModeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetThirdPartyCookieBlockingMode(const PAL::SessionID& sessionID, WebCore::ThirdPartyCookieBlockingMode blockingMode)
        : m_sessionID(sessionID)
        , m_blockingMode(blockingMode)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_blockingMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    WebCore::ThirdPartyCookieBlockingMode m_blockingMode;
};

class SetShouldEnbleSameSiteStrictEnforcementForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::SameSiteStrictEnforcementEnabled>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetShouldEnbleSameSiteStrictEnforcementForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetShouldEnbleSameSiteStrictEnforcementForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetShouldEnbleSameSiteStrictEnforcementForTesting(const PAL::SessionID& sessionID, WebCore::SameSiteStrictEnforcementEnabled enabled)
        : m_sessionID(sessionID)
        , m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    WebCore::SameSiteStrictEnforcementEnabled m_enabled;
};

class SetFirstPartyWebsiteDataRemovalModeForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::FirstPartyWebsiteDataRemovalMode>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetFirstPartyWebsiteDataRemovalModeForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetFirstPartyWebsiteDataRemovalModeForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetFirstPartyWebsiteDataRemovalModeForTesting(const PAL::SessionID& sessionID, WebCore::FirstPartyWebsiteDataRemovalMode mode)
        : m_sessionID(sessionID)
        , m_mode(mode)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_mode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    WebCore::FirstPartyWebsiteDataRemovalMode m_mode;
};

class SetToSameSiteStrictCookiesForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetToSameSiteStrictCookiesForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetToSameSiteStrictCookiesForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetToSameSiteStrictCookiesForTesting(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& domain)
        : m_sessionID(sessionID)
        , m_domain(domain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
};

class SetFirstPartyHostCNAMEDomainForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, String, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetFirstPartyHostCNAMEDomainForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetFirstPartyHostCNAMEDomainForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetFirstPartyHostCNAMEDomainForTesting(const PAL::SessionID& sessionID, const String& firstPartyHost, const WebCore::RegistrableDomain& cnameDomain)
        : m_sessionID(sessionID)
        , m_firstPartyHost(firstPartyHost)
        , m_cnameDomain(cnameDomain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_firstPartyHost;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cnameDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_firstPartyHost;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_cnameDomain;
};

class SetThirdPartyCNAMEDomainForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetThirdPartyCNAMEDomainForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetThirdPartyCNAMEDomainForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetThirdPartyCNAMEDomainForTesting(const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& domain)
        : m_sessionID(sessionID)
        , m_domain(domain)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
};

class SetPrivateClickMeasurementDebugMode {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementDebugMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetPrivateClickMeasurementDebugMode(const PAL::SessionID& sessionID, bool debugMode)
        : m_sessionID(sessionID)
        , m_debugMode(debugMode)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_debugMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_debugMode;
};

class SetShouldSendPrivateTokenIPCForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetShouldSendPrivateTokenIPCForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetShouldSendPrivateTokenIPCForTesting(const PAL::SessionID& sessionID, bool enabled)
        : m_sessionID(sessionID)
        , m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_enabled;
};

#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES)
class SetOptInCookiePartitioningEnabled {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetOptInCookiePartitioningEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetOptInCookiePartitioningEnabled(const PAL::SessionID& sessionID, bool enabled)
        : m_sessionID(sessionID)
        , m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_enabled;
};
#endif

class SetSessionIsControlledByAutomation {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetSessionIsControlledByAutomation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetSessionIsControlledByAutomation(const PAL::SessionID& sessionID, bool controlled)
        : m_sessionID(sessionID)
        , m_controlled(controlled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_controlled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_controlled;
};

class RegisterURLSchemeAsSecure {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RegisterURLSchemeAsSecure; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsSecure(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class RegisterURLSchemeAsBypassingContentSecurityPolicy {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RegisterURLSchemeAsBypassingContentSecurityPolicy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsBypassingContentSecurityPolicy(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class RegisterURLSchemeAsLocal {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RegisterURLSchemeAsLocal; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsLocal(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

#if ENABLE(ALL_LEGACY_REGISTERED_SPECIAL_URL_SCHEMES)
class RegisterURLSchemeAsNoAccess {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RegisterURLSchemeAsNoAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsNoAccess(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};
#endif

class SyncLocalStorage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SyncLocalStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SyncLocalStorageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SyncLocalStorage()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StoreServiceWorkerRegistrations {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_StoreServiceWorkerRegistrations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_StoreServiceWorkerRegistrationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit StoreServiceWorkerRegistrations(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class StorePrivateClickMeasurement {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::PrivateClickMeasurement>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_StorePrivateClickMeasurement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StorePrivateClickMeasurement(const PAL::SessionID& sessionID, const WebCore::PrivateClickMeasurement& privateClickMeasurement)
        : m_sessionID(sessionID)
        , m_privateClickMeasurement(privateClickMeasurement)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_privateClickMeasurement;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PrivateClickMeasurement& m_privateClickMeasurement;
};

class DumpPrivateClickMeasurement {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DumpPrivateClickMeasurement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_DumpPrivateClickMeasurementReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit DumpPrivateClickMeasurement(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class ClearPrivateClickMeasurement {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClearPrivateClickMeasurement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClearPrivateClickMeasurementReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ClearPrivateClickMeasurement(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetPrivateClickMeasurementOverrideTimerForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementOverrideTimerForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementOverrideTimerForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPrivateClickMeasurementOverrideTimerForTesting(const PAL::SessionID& sessionID, bool value)
        : m_sessionID(sessionID)
        , m_value(value)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_value;
};

class MarkAttributedPrivateClickMeasurementsAsExpiredForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_MarkAttributedPrivateClickMeasurementsAsExpiredForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_MarkAttributedPrivateClickMeasurementsAsExpiredForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit MarkAttributedPrivateClickMeasurementsAsExpiredForTesting(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetPrivateClickMeasurementEphemeralMeasurementForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementEphemeralMeasurementForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementEphemeralMeasurementForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPrivateClickMeasurementEphemeralMeasurementForTesting(const PAL::SessionID& sessionID, bool value)
        : m_sessionID(sessionID)
        , m_value(value)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_value;
};

class SimulatePrivateClickMeasurementSessionRestart {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SimulatePrivateClickMeasurementSessionRestart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SimulatePrivateClickMeasurementSessionRestartReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SimulatePrivateClickMeasurementSessionRestart(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetPrivateClickMeasurementTokenPublicKeyURLForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementTokenPublicKeyURLForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementTokenPublicKeyURLForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPrivateClickMeasurementTokenPublicKeyURLForTesting(const PAL::SessionID& sessionID, const URL& url)
        : m_sessionID(sessionID)
        , m_url(url)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class SetPrivateClickMeasurementTokenSignatureURLForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementTokenSignatureURLForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementTokenSignatureURLForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPrivateClickMeasurementTokenSignatureURLForTesting(const PAL::SessionID& sessionID, const URL& url)
        : m_sessionID(sessionID)
        , m_url(url)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class SetPrivateClickMeasurementAttributionReportURLsForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, URL, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementAttributionReportURLsForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementAttributionReportURLsForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPrivateClickMeasurementAttributionReportURLsForTesting(const PAL::SessionID& sessionID, const URL& sourceURL, const URL& destinationURL)
        : m_sessionID(sessionID)
        , m_sourceURL(sourceURL)
        , m_destinationURL(destinationURL)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourceURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_sourceURL;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_destinationURL;
};

class MarkPrivateClickMeasurementsAsExpiredForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_MarkPrivateClickMeasurementsAsExpiredForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_MarkPrivateClickMeasurementsAsExpiredForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit MarkPrivateClickMeasurementsAsExpiredForTesting(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetPCMFraudPreventionValuesForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, String, String, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPCMFraudPreventionValuesForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPCMFraudPreventionValuesForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPCMFraudPreventionValuesForTesting(const PAL::SessionID& sessionID, const String& secretToken, const String& unlinkableToken, const String& signature, const String& keyID)
        : m_sessionID(sessionID)
        , m_secretToken(secretToken)
        , m_unlinkableToken(unlinkableToken)
        , m_signature(signature)
        , m_keyID(keyID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_secretToken;
        encoder << m_unlinkableToken;
        encoder << m_signature;
        encoder << m_keyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_secretToken;
    const String& m_unlinkableToken;
    const String& m_signature;
    const String& m_keyID;
};

class SetPrivateClickMeasurementAppBundleIDForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementAppBundleIDForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPrivateClickMeasurementAppBundleIDForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPrivateClickMeasurementAppBundleIDForTesting(const PAL::SessionID& sessionID, const String& appBundleIDForTesting)
        : m_sessionID(sessionID)
        , m_appBundleIDForTesting(appBundleIDForTesting)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_appBundleIDForTesting;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_appBundleIDForTesting;
};

class ClosePCMDatabase {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClosePCMDatabase; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClosePCMDatabaseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ClosePCMDatabase(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetServiceWorkerFetchTimeoutForTesting {
public:
    using Arguments = std::tuple<Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetServiceWorkerFetchTimeoutForTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    explicit SetServiceWorkerFetchTimeoutForTesting(const Seconds& seconds)
        : m_seconds(seconds)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_seconds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_seconds;
};

class ResetServiceWorkerFetchTimeoutForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResetServiceWorkerFetchTimeoutForTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    ResetServiceWorkerFetchTimeoutForTesting()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class TerminateIdleServiceWorkers {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_TerminateIdleServiceWorkers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_TerminateIdleServiceWorkersReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit TerminateIdleServiceWorkers(const WebCore::ProcessIdentifier& processIdentifier)
        : m_processIdentifier(processIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
};

class ResetQuota {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResetQuota; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ResetQuotaReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ResetQuota(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetOriginQuotaRatioEnabledForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetOriginQuotaRatioEnabledForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetOriginQuotaRatioEnabledForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetOriginQuotaRatioEnabledForTesting(const PAL::SessionID& sessionID, bool enabled)
        : m_sessionID(sessionID)
        , m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_enabled;
};

#if PLATFORM(IOS_FAMILY)
class SetBackupExclusionPeriodForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetBackupExclusionPeriodForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetBackupExclusionPeriodForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetBackupExclusionPeriodForTesting(const PAL::SessionID& sessionID, const Seconds& period)
        : m_sessionID(sessionID)
        , m_period(period)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_period;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_period;
};
#endif

class ResetStoragePersistedState {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResetStoragePersistedState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ResetStoragePersistedStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ResetStoragePersistedState(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class CloneSessionStorageForWebPage {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::WebPageProxyIdentifier, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_CloneSessionStorageForWebPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CloneSessionStorageForWebPage(const PAL::SessionID& sessionID, const WebKit::WebPageProxyIdentifier& sourcePage, const WebKit::WebPageProxyIdentifier& destinationPage)
        : m_sessionID(sessionID)
        , m_sourcePage(sourcePage)
        , m_destinationPage(destinationPage)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourcePage;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationPage;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_sourcePage;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_destinationPage;
};

class DidIncreaseQuota {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::ClientOrigin, WebKit::QuotaIncreaseRequestIdentifier, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DidIncreaseQuota; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidIncreaseQuota(const PAL::SessionID& sessionID, const WebCore::ClientOrigin& origin, const WebKit::QuotaIncreaseRequestIdentifier& identifier, const std::optional<uint64_t>& newQuota)
        : m_sessionID(sessionID)
        , m_origin(origin)
        , m_identifier(identifier)
        , m_newQuota(newQuota)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newQuota;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::QuotaIncreaseRequestIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_newQuota;
};

#if ENABLE(APP_BOUND_DOMAINS)
class HasAppBoundSession {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_HasAppBoundSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_HasAppBoundSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit HasAppBoundSession(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};
#endif

#if ENABLE(APP_BOUND_DOMAINS)
class ClearAppBoundSession {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClearAppBoundSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClearAppBoundSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ClearAppBoundSession(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};
#endif

#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
class DisableServiceWorkerEntitlement {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_DisableServiceWorkerEntitlement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DisableServiceWorkerEntitlement()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
class ClearServiceWorkerEntitlementOverride {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClearServiceWorkerEntitlementOverride; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClearServiceWorkerEntitlementOverrideReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ClearServiceWorkerEntitlementOverride()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class UpdateBundleIdentifier {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_UpdateBundleIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_UpdateBundleIdentifierReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit UpdateBundleIdentifier(const String& bundleIdentifier)
        : m_bundleIdentifier(bundleIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bundleIdentifier;
    }

private:
    const String& m_bundleIdentifier;
};

class ClearBundleIdentifier {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClearBundleIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClearBundleIdentifierReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ClearBundleIdentifier()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(COCOA)
class AppPrivacyReportTestingData {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AppPrivacyReportTestingData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_AppPrivacyReportTestingDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::AppPrivacyReportTestingData>;
    using Reply = CompletionHandler<void(WebKit::AppPrivacyReportTestingData&&)>;
    using Promise = WTF::NativePromise<WebKit::AppPrivacyReportTestingData, IPC::Error>;
    explicit AppPrivacyReportTestingData(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};
#endif

#if PLATFORM(COCOA)
class ClearAppPrivacyReportTestingData {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClearAppPrivacyReportTestingData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClearAppPrivacyReportTestingDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ClearAppPrivacyReportTestingData(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};
#endif

class AddWebPageNetworkParameters {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::WebPageProxyIdentifier, WebKit::WebPageNetworkParameters>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AddWebPageNetworkParameters; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddWebPageNetworkParameters(const PAL::SessionID& sessionID, const WebKit::WebPageProxyIdentifier& pageID, const WebKit::WebPageNetworkParameters& parameters)
        : m_sessionID(sessionID)
        , m_pageID(pageID)
        , m_parameters(parameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageNetworkParameters& m_parameters;
};

class RemoveWebPageNetworkParameters {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RemoveWebPageNetworkParameters; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveWebPageNetworkParameters(const PAL::SessionID& sessionID, const WebKit::WebPageProxyIdentifier& pageID)
        : m_sessionID(sessionID)
        , m_pageID(pageID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
};

class CountNonDefaultSessionSets {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_CountNonDefaultSessionSets; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_CountNonDefaultSessionSetsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    using Promise = WTF::NativePromise<uint64_t, IPC::Error>;
    explicit CountNonDefaultSessionSets(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class AllowFileAccessFromWebProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AllowFileAccessFromWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_AllowFileAccessFromWebProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    AllowFileAccessFromWebProcess(const WebCore::ProcessIdentifier& processIdentifier, const String& url)
        : m_processIdentifier(processIdentifier)
        , m_url(url)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    const String& m_url;
};

class AllowFilesAccessFromWebProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AllowFilesAccessFromWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = true;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_AllowFilesAccessFromWebProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    AllowFilesAccessFromWebProcess(const WebCore::ProcessIdentifier& processIdentifier, const Vector<String>& urls)
        : m_processIdentifier(processIdentifier)
        , m_urls(urls)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_urls;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_urls;
};

class TerminateRemoteWorkerContextConnectionWhenPossible {
public:
    using Arguments = std::tuple<WebKit::RemoteWorkerType, PAL::SessionID, WebCore::RegistrableDomain, WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_TerminateRemoteWorkerContextConnectionWhenPossible; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TerminateRemoteWorkerContextConnectionWhenPossible(WebKit::RemoteWorkerType workerType, const PAL::SessionID& sessionID, const WebCore::RegistrableDomain& registrableDomain, const WebCore::ProcessIdentifier& processIdentifier)
        : m_workerType(workerType)
        , m_sessionID(sessionID)
        , m_registrableDomain(registrableDomain)
        , m_processIdentifier(processIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_workerType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrableDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
    }

private:
    WebKit::RemoteWorkerType m_workerType;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_registrableDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
};

class RunningOrTerminatingServiceWorkerCountForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RunningOrTerminatingServiceWorkerCountForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_RunningOrTerminatingServiceWorkerCountForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<unsigned>;
    using Reply = CompletionHandler<void(unsigned&&)>;
    using Promise = WTF::NativePromise<unsigned, IPC::Error>;
    explicit RunningOrTerminatingServiceWorkerCountForTesting(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class GetPendingPushMessage {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_GetPendingPushMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_GetPendingPushMessageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::WebPushMessage>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::WebPushMessage>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::WebPushMessage>, IPC::Error>;
    explicit GetPendingPushMessage(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class GetPendingPushMessages {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_GetPendingPushMessages; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_GetPendingPushMessagesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::WebPushMessage>>;
    using Reply = CompletionHandler<void(Vector<WebKit::WebPushMessage>&&)>;
    using Promise = WTF::NativePromise<Vector<WebKit::WebPushMessage>, IPC::Error>;
    explicit GetPendingPushMessages(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class ProcessPushMessage {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::WebPushMessage, WebCore::PushPermissionState, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ProcessPushMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ProcessPushMessageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, std::optional<WebCore::NotificationPayload>>;
    using Reply = CompletionHandler<void(bool, std::optional<WebCore::NotificationPayload>&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, std::optional<WebCore::NotificationPayload>>, IPC::Error>;
    ProcessPushMessage(const PAL::SessionID& sessionID, const WebKit::WebPushMessage& pushMessage, WebCore::PushPermissionState pushPermissionState, bool builtInNotificationsEnabled)
        : m_sessionID(sessionID)
        , m_pushMessage(pushMessage)
        , m_pushPermissionState(pushPermissionState)
        , m_builtInNotificationsEnabled(builtInNotificationsEnabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pushMessage;
        encoder << m_pushPermissionState;
        encoder << m_builtInNotificationsEnabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPushMessage& m_pushMessage;
    WebCore::PushPermissionState m_pushPermissionState;
    bool m_builtInNotificationsEnabled;
};

class ProcessNotificationEvent {
public:
    using Arguments = std::tuple<WebCore::NotificationData, WebCore::NotificationEventType>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ProcessNotificationEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ProcessNotificationEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    ProcessNotificationEvent(const WebCore::NotificationData& data, WebCore::NotificationEventType eventType)
        : m_data(data)
        , m_eventType(eventType)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        encoder << m_eventType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NotificationData& m_data;
    WebCore::NotificationEventType m_eventType;
};

class GetAllBackgroundFetchIdentifiers {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_GetAllBackgroundFetchIdentifiers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_GetAllBackgroundFetchIdentifiersReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    using Promise = WTF::NativePromise<Vector<String>, IPC::Error>;
    explicit GetAllBackgroundFetchIdentifiers(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class GetBackgroundFetchState {
public:
    using Arguments = std::tuple<PAL::SessionID, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_GetBackgroundFetchState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_GetBackgroundFetchStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::BackgroundFetchState>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::BackgroundFetchState>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::BackgroundFetchState>, IPC::Error>;
    GetBackgroundFetchState(const PAL::SessionID& sessionID, const String& identifier)
        : m_sessionID(sessionID)
        , m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_identifier;
};

class AbortBackgroundFetch {
public:
    using Arguments = std::tuple<PAL::SessionID, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_AbortBackgroundFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_AbortBackgroundFetchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    AbortBackgroundFetch(const PAL::SessionID& sessionID, const String& identifier)
        : m_sessionID(sessionID)
        , m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_identifier;
};

class PauseBackgroundFetch {
public:
    using Arguments = std::tuple<PAL::SessionID, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_PauseBackgroundFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_PauseBackgroundFetchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PauseBackgroundFetch(const PAL::SessionID& sessionID, const String& identifier)
        : m_sessionID(sessionID)
        , m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_identifier;
};

class ResumeBackgroundFetch {
public:
    using Arguments = std::tuple<PAL::SessionID, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResumeBackgroundFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ResumeBackgroundFetchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ResumeBackgroundFetch(const PAL::SessionID& sessionID, const String& identifier)
        : m_sessionID(sessionID)
        , m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_identifier;
};

class ClickBackgroundFetch {
public:
    using Arguments = std::tuple<PAL::SessionID, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClickBackgroundFetch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ClickBackgroundFetchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ClickBackgroundFetch(const PAL::SessionID& sessionID, const String& identifier)
        : m_sessionID(sessionID)
        , m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_identifier;
};

class SetPushAndNotificationsEnabledForOrigin {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::SecurityOriginData, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPushAndNotificationsEnabledForOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_SetPushAndNotificationsEnabledForOriginReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetPushAndNotificationsEnabledForOrigin(const PAL::SessionID& sessionID, const WebCore::SecurityOriginData& origin, bool enabled)
        : m_sessionID(sessionID)
        , m_origin(origin)
        , m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
    bool m_enabled;
};

class RemovePushSubscriptionsForOrigin {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RemovePushSubscriptionsForOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_RemovePushSubscriptionsForOriginReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<unsigned>;
    using Reply = CompletionHandler<void(unsigned&&)>;
    using Promise = WTF::NativePromise<unsigned, IPC::Error>;
    RemovePushSubscriptionsForOrigin(const PAL::SessionID& sessionID, const WebCore::SecurityOriginData& origin)
        : m_sessionID(sessionID)
        , m_origin(origin)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
};

class HasPushSubscriptionForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_HasPushSubscriptionForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_HasPushSubscriptionForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    HasPushSubscriptionForTesting(const PAL::SessionID& sessionID, const URL& scopeURL)
        : m_sessionID(sessionID)
        , m_scopeURL(scopeURL)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
};

#if ENABLE(INSPECTOR_NETWORK_THROTTLING)
class SetEmulatedConditions {
public:
    using Arguments = std::tuple<PAL::SessionID, std::optional<int64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetEmulatedConditions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetEmulatedConditions(const PAL::SessionID& sessionID, const std::optional<int64_t>& bytesPerSecondLimit)
        : m_sessionID(sessionID)
        , m_bytesPerSecondLimit(bytesPerSecondLimit)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bytesPerSecondLimit;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<int64_t>& m_bytesPerSecondLimit;
};
#endif

#if HAVE(NW_PROXY_CONFIG)
class ClearProxyConfigData {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ClearProxyConfigData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ClearProxyConfigData(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};
#endif

#if HAVE(NW_PROXY_CONFIG)
class SetProxyConfigData {
public:
    using Arguments = std::tuple<PAL::SessionID, Vector<std::pair<Vector<uint8_t>, std::optional<WTF::UUID>>>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetProxyConfigData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetProxyConfigData(const PAL::SessionID& sessionID, const Vector<std::pair<Vector<uint8_t>, std::optional<WTF::UUID>>>& proxyConfigurations)
        : m_sessionID(sessionID)
        , m_proxyConfigurations(proxyConfigurations)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_proxyConfigurations;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::pair<Vector<uint8_t>, std::optional<WTF::UUID>>>& m_proxyConfigurations;
};
#endif

class SetStorageSiteValidationEnabled {
public:
    using Arguments = std::tuple<PAL::SessionID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetStorageSiteValidationEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetStorageSiteValidationEnabled(const PAL::SessionID& sessionID, bool enabled)
        : m_sessionID(sessionID)
        , m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_enabled;
};

class SetPersistedDomains {
public:
    using Arguments = std::tuple<PAL::SessionID, HashSet<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetPersistedDomains; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetPersistedDomains(const PAL::SessionID& sessionsID, const HashSet<WebCore::RegistrableDomain>& domains)
        : m_sessionsID(sessionsID)
        , m_domains(domains)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionsID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionsID;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<WebCore::RegistrableDomain>& m_domains;
};

class GetAppBadgeForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_GetAppBadgeForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_GetAppBadgeForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<uint64_t>>;
    using Reply = CompletionHandler<void(std::optional<uint64_t>&&)>;
    using Promise = WTF::NativePromise<std::optional<uint64_t>, IPC::Error>;
    explicit GetAppBadgeForTesting(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class FetchLocalStorage {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_FetchLocalStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_FetchLocalStorageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<HashMap<WebCore::ClientOrigin, HashMap<String, String>>>>;
    using Reply = CompletionHandler<void(std::optional<HashMap<WebCore::ClientOrigin, HashMap<String, String>>>&&)>;
    using Promise = WTF::NativePromise<std::optional<HashMap<WebCore::ClientOrigin, HashMap<String, String>>>, IPC::Error>;
    explicit FetchLocalStorage(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class RestoreLocalStorage {
public:
    using Arguments = std::tuple<PAL::SessionID, HashMap<WebCore::ClientOrigin, HashMap<String, String>>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RestoreLocalStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_RestoreLocalStorageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    RestoreLocalStorage(const PAL::SessionID& sessionID, const HashMap<WebCore::ClientOrigin, HashMap<String, String>>& localStorageMap)
        : m_sessionID(sessionID)
        , m_localStorageMap(localStorageMap)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_localStorageMap;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<WebCore::ClientOrigin, HashMap<String, String>>& m_localStorageMap;
};

class FetchSessionStorage {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_FetchSessionStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_FetchSessionStorageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<HashMap<WebCore::ClientOrigin, HashMap<String, String>>>>;
    using Reply = CompletionHandler<void(std::optional<HashMap<WebCore::ClientOrigin, HashMap<String, String>>>&&)>;
    using Promise = WTF::NativePromise<std::optional<HashMap<WebCore::ClientOrigin, HashMap<String, String>>>, IPC::Error>;
    FetchSessionStorage(const PAL::SessionID& sessionID, const WebKit::WebPageProxyIdentifier& pageID)
        : m_sessionID(sessionID)
        , m_pageID(pageID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
};

class RestoreSessionStorage {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::WebPageProxyIdentifier, HashMap<WebCore::ClientOrigin, HashMap<String, String>>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_RestoreSessionStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_RestoreSessionStorageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    RestoreSessionStorage(const PAL::SessionID& sessionID, const WebKit::WebPageProxyIdentifier& pageID, const HashMap<WebCore::ClientOrigin, HashMap<String, String>>& localStorageMap)
        : m_sessionID(sessionID)
        , m_pageID(pageID)
        , m_localStorageMap(localStorageMap)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_localStorageMap;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<WebCore::ClientOrigin, HashMap<String, String>>& m_localStorageMap;
};

class SetShouldRelaxThirdPartyCookieBlockingForPage {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetShouldRelaxThirdPartyCookieBlockingForPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldRelaxThirdPartyCookieBlockingForPage(const WebKit::WebPageProxyIdentifier& pageID)
        : m_pageID(pageID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
};

#if ENABLE(CONTENT_EXTENSIONS)
class ResetResourceMonitorThrottlerForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_ResetResourceMonitorThrottlerForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcess_ResetResourceMonitorThrottlerForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ResetResourceMonitorThrottlerForTesting(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};
#endif

class SetDefaultRequestTimeoutInterval {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcess_SetDefaultRequestTimeoutInterval; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDefaultRequestTimeoutInterval(double timeoutInterval)
        : m_timeoutInterval(timeoutInterval)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_timeoutInterval;
    }

private:
    double m_timeoutInterval;
};

} // namespace NetworkProcess
} // namespace Messages
