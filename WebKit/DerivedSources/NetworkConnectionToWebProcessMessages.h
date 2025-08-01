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
#include "NetworkResourceLoadParameters.h"
#include "SandboxExtension.h"
#include <WebCore/NetworkLoadInformation.h>
#include <WebCore/ProcessQualified.h>
#include <WebCore/RTCDataChannelIdentifier.h>
#include <WebCore/ScriptExecutionContextIdentifier.h>
#include <WebCore/SharedBuffer.h>
#include <optional>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/OptionSet.h>
#include <wtf/Ref.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/Seconds.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
class LoginStatus;
class MockContentFilterSettings;
class NetworkLoadMetrics;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct PushSubscriptionIdentifierType;
using PushSubscriptionIdentifier = ObjectIdentifier<PushSubscriptionIdentifierType>;
class RegistrableDomain;
class ResourceError;
struct ResourceLoaderIdentifierType;
using ResourceLoaderIdentifier = AtomicObjectIdentifier<ResourceLoaderIdentifierType>;
class ResourceRequest;
class ResourceResponse;
class SecurityOriginData;
class Site;
struct WebSocketIdentifierType;
using WebSocketIdentifier = AtomicObjectIdentifier<WebSocketIdentifierType>;
enum class FromDownloadAttribute : bool;
enum class IncludeSecureCookies : bool;
enum class RequiresScriptTrackingPrivacy : bool;
enum class ShouldPartitionCookie : bool;
enum class StorageAccessScope : bool;
enum class IsLoggedIn : uint8_t;
enum class LoadSchedulingMode : uint8_t;
enum class StoredCredentialsPolicy : uint8_t;
struct ClientOrigin;
struct Cookie;
struct CookieStoreGetOptions;
struct MessagePortIdentifier;
struct MessageWithMessagePorts;
struct PolicyContainer;
struct RequestStorageAccessResult;
struct SameSiteInfo;
}

namespace WebKit {
struct DownloadIDType;
using DownloadID = ObjectIdentifier<DownloadIDType>;
struct MessageBatchIdentifierType;
using MessageBatchIdentifier = ObjectIdentifier<MessageBatchIdentifierType>;
struct NetworkResourceLoadIdentifierType;
using NetworkResourceLoadIdentifier = ObjectIdentifier<NetworkResourceLoadIdentifierType>;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
struct WebTransportSessionIdentifierType;
using WebTransportSessionIdentifier = ObjectIdentifier<WebTransportSessionIdentifierType>;
enum class NavigatingToAppBoundDomain : bool;
struct CoreIPCAuditToken;
}

namespace Messages {
namespace NetworkConnectionToWebProcess {

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
    return IPC::ReceiverName::NetworkConnectionToWebProcess;
}

class ScheduleResourceLoad {
public:
    using Arguments = std::tuple<WebKit::NetworkResourceLoadParameters, std::optional<WebKit::NetworkResourceLoadIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_ScheduleResourceLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ScheduleResourceLoad(WebKit::NetworkResourceLoadParameters&& resourceLoadParameters, const std::optional<WebKit::NetworkResourceLoadIdentifier>& existingLoaderToResume)
        : m_resourceLoadParameters(WTFMove(resourceLoadParameters))
        , m_existingLoaderToResume(existingLoaderToResume)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_resourceLoadParameters);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_existingLoaderToResume;
    }

private:
    WebKit::NetworkResourceLoadParameters&& m_resourceLoadParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::NetworkResourceLoadIdentifier>& m_existingLoaderToResume;
};

class PerformSynchronousLoad {
public:
    using Arguments = std::tuple<WebKit::NetworkResourceLoadParameters>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_PerformSynchronousLoad; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ResourceError, WebCore::ResourceResponse, Vector<uint8_t>>;
    using Reply = CompletionHandler<void(WebCore::ResourceError&&, WebCore::ResourceResponse&&, Vector<uint8_t>&&)>;
    explicit PerformSynchronousLoad(WebKit::NetworkResourceLoadParameters&& resourceLoadParameters)
        : m_resourceLoadParameters(WTFMove(resourceLoadParameters))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_resourceLoadParameters);
    }

private:
    WebKit::NetworkResourceLoadParameters&& m_resourceLoadParameters;
};

class TestProcessIncomingSyncMessagesWhenWaitingForSyncReply {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit TestProcessIncomingSyncMessagesWhenWaitingForSyncReply(const WebKit::WebPageProxyIdentifier& pageID)
        : m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
};

class LoadPing {
public:
    using Arguments = std::tuple<WebKit::NetworkResourceLoadParameters>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_LoadPing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit LoadPing(WebKit::NetworkResourceLoadParameters&& resourceLoadParameters)
        : m_resourceLoadParameters(WTFMove(resourceLoadParameters))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_resourceLoadParameters);
    }

private:
    WebKit::NetworkResourceLoadParameters&& m_resourceLoadParameters;
};

class RemoveLoadIdentifier {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RemoveLoadIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveLoadIdentifier(const WebCore::ResourceLoaderIdentifier& resourceLoadIdentifier)
        : m_resourceLoadIdentifier(resourceLoadIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceLoadIdentifier;
};

class PageLoadCompleted {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_PageLoadCompleted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PageLoadCompleted(const WebCore::PageIdentifier& webPageID)
        : m_webPageID(webPageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_webPageID;
};

class BrowsingContextRemoved {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_BrowsingContextRemoved; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BrowsingContextRemoved(const WebKit::WebPageProxyIdentifier& webPageProxyID, const WebCore::PageIdentifier& webPageID, const WebCore::FrameIdentifier& webFrameID)
        : m_webPageProxyID(webPageProxyID)
        , m_webPageID(webPageID)
        , m_webFrameID(webFrameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webFrameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_webPageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_webFrameID;
};

class PrefetchDNS {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_PrefetchDNS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PrefetchDNS(const String& hostname)
        : m_hostname(hostname)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hostname;
    }

private:
    const String& m_hostname;
};

class SendH2Ping {
public:
    using Arguments = std::tuple<WebKit::NetworkResourceLoadParameters>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SendH2Ping; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_SendH2PingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Seconds, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<Seconds, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<Seconds, WebCore::ResourceError>, IPC::Error>;
    explicit SendH2Ping(WebKit::NetworkResourceLoadParameters&& parameters)
        : m_parameters(WTFMove(parameters))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_parameters);
    }

private:
    WebKit::NetworkResourceLoadParameters&& m_parameters;
};

class PreconnectTo {
public:
    using Arguments = std::tuple<std::optional<WebCore::ResourceLoaderIdentifier>, WebKit::NetworkResourceLoadParameters>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_PreconnectTo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PreconnectTo(const std::optional<WebCore::ResourceLoaderIdentifier>& preconnectionIdentifier, WebKit::NetworkResourceLoadParameters&& loadParameters)
        : m_preconnectionIdentifier(preconnectionIdentifier)
        , m_loadParameters(WTFMove(loadParameters))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_preconnectionIdentifier;
        encoder << WTFMove(m_loadParameters);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ResourceLoaderIdentifier>& m_preconnectionIdentifier;
    WebKit::NetworkResourceLoadParameters&& m_loadParameters;
};

class IsResourceLoadFinished {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_IsResourceLoadFinished; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_IsResourceLoadFinishedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit IsResourceLoadFinished(const WebCore::ResourceLoaderIdentifier& resourceLoadIdentifier)
        : m_resourceLoadIdentifier(resourceLoadIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceLoadIdentifier;
};

class StartDownload {
public:
    using Arguments = std::tuple<WebKit::DownloadID, WebCore::ResourceRequest, std::optional<WebCore::SecurityOriginData>, std::optional<WebKit::NavigatingToAppBoundDomain>, String, WebCore::FromDownloadAttribute, std::optional<WebCore::FrameIdentifier>, std::optional<WebCore::PageIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_StartDownload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartDownload(const WebKit::DownloadID& downloadID, const WebCore::ResourceRequest& request, const std::optional<WebCore::SecurityOriginData>& topOrigin, std::optional<WebKit::NavigatingToAppBoundDomain> isNavigatingToAppBoundDomain, const String& suggestedName, WebCore::FromDownloadAttribute fromDownloadAttribute, const std::optional<WebCore::FrameIdentifier>& frameID, const std::optional<WebCore::PageIdentifier>& pageID)
        : m_downloadID(downloadID)
        , m_request(request)
        , m_topOrigin(topOrigin)
        , m_isNavigatingToAppBoundDomain(isNavigatingToAppBoundDomain)
        , m_suggestedName(suggestedName)
        , m_fromDownloadAttribute(fromDownloadAttribute)
        , m_frameID(frameID)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_downloadID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        encoder << m_isNavigatingToAppBoundDomain;
        encoder << m_suggestedName;
        encoder << m_fromDownloadAttribute;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DownloadID& m_downloadID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
    std::optional<WebKit::NavigatingToAppBoundDomain> m_isNavigatingToAppBoundDomain;
    const String& m_suggestedName;
    WebCore::FromDownloadAttribute m_fromDownloadAttribute;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PageIdentifier>& m_pageID;
};

class ConvertMainResourceLoadToDownload {
public:
    using Arguments = std::tuple<std::optional<WebCore::ResourceLoaderIdentifier>, WebKit::DownloadID, WebCore::ResourceRequest, std::optional<WebCore::SecurityOriginData>, WebCore::ResourceResponse, std::optional<WebKit::NavigatingToAppBoundDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_ConvertMainResourceLoadToDownload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ConvertMainResourceLoadToDownload(const std::optional<WebCore::ResourceLoaderIdentifier>& mainResourceLoadIdentifier, const WebKit::DownloadID& downloadID, const WebCore::ResourceRequest& request, const std::optional<WebCore::SecurityOriginData>& topOrigin, const WebCore::ResourceResponse& response, std::optional<WebKit::NavigatingToAppBoundDomain> isNavigatingToAppBoundDomain)
        : m_mainResourceLoadIdentifier(mainResourceLoadIdentifier)
        , m_downloadID(downloadID)
        , m_request(request)
        , m_topOrigin(topOrigin)
        , m_response(response)
        , m_isNavigatingToAppBoundDomain(isNavigatingToAppBoundDomain)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mainResourceLoadIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_downloadID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        encoder << m_isNavigatingToAppBoundDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ResourceLoaderIdentifier>& m_mainResourceLoadIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DownloadID& m_downloadID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    std::optional<WebKit::NavigatingToAppBoundDomain> m_isNavigatingToAppBoundDomain;
};

class CookiesForDOM {
public:
    using Arguments = std::tuple<URL, WebCore::SameSiteInfo, URL, WebCore::FrameIdentifier, WebCore::PageIdentifier, WebCore::IncludeSecureCookies, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CookiesForDOM; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, bool>;
    using Reply = CompletionHandler<void(String&&, bool)>;
    CookiesForDOM(const URL& firstParty, const WebCore::SameSiteInfo& sameSiteInfo, const URL& url, const WebCore::FrameIdentifier& frameID, const WebCore::PageIdentifier& pageID, WebCore::IncludeSecureCookies includeSecureCookies, const WebKit::WebPageProxyIdentifier& webPageProxyID)
        : m_firstParty(firstParty)
        , m_sameSiteInfo(sameSiteInfo)
        , m_url(url)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_includeSecureCookies(includeSecureCookies)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sameSiteInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_includeSecureCookies;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SameSiteInfo& m_sameSiteInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    WebCore::IncludeSecureCookies m_includeSecureCookies;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
};

class SetCookiesFromDOM {
public:
    using Arguments = std::tuple<URL, WebCore::SameSiteInfo, URL, WebCore::FrameIdentifier, WebCore::PageIdentifier, String, WebCore::RequiresScriptTrackingPrivacy, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SetCookiesFromDOM; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetCookiesFromDOM(const URL& firstParty, const WebCore::SameSiteInfo& sameSiteInfo, const URL& url, const WebCore::FrameIdentifier& frameID, const WebCore::PageIdentifier& pageID, const String& cookieString, WebCore::RequiresScriptTrackingPrivacy requiresScriptTrackingPrivacy, const WebKit::WebPageProxyIdentifier& webPageProxyID)
        : m_firstParty(firstParty)
        , m_sameSiteInfo(sameSiteInfo)
        , m_url(url)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_cookieString(cookieString)
        , m_requiresScriptTrackingPrivacy(requiresScriptTrackingPrivacy)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sameSiteInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_cookieString;
        encoder << m_requiresScriptTrackingPrivacy;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SameSiteInfo& m_sameSiteInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    const String& m_cookieString;
    WebCore::RequiresScriptTrackingPrivacy m_requiresScriptTrackingPrivacy;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
};

class CookiesEnabledSync {
public:
    using Arguments = std::tuple<URL, URL, std::optional<WebCore::FrameIdentifier>, std::optional<WebCore::PageIdentifier>, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CookiesEnabledSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    CookiesEnabledSync(const URL& firstParty, const URL& url, const std::optional<WebCore::FrameIdentifier>& frameID, const std::optional<WebCore::PageIdentifier>& pageID, const WebKit::WebPageProxyIdentifier& webPageProxyID)
        : m_firstParty(firstParty)
        , m_url(url)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PageIdentifier>& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
};

class CookiesEnabled {
public:
    using Arguments = std::tuple<URL, URL, std::optional<WebCore::FrameIdentifier>, std::optional<WebCore::PageIdentifier>, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CookiesEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_CookiesEnabledReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    CookiesEnabled(const URL& firstParty, const URL& url, const std::optional<WebCore::FrameIdentifier>& frameID, const std::optional<WebCore::PageIdentifier>& pageID, const WebKit::WebPageProxyIdentifier& webPageProxyID)
        : m_firstParty(firstParty)
        , m_url(url)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PageIdentifier>& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
};

class CookieRequestHeaderFieldValue {
public:
    using Arguments = std::tuple<URL, WebCore::SameSiteInfo, URL, std::optional<WebCore::FrameIdentifier>, std::optional<WebCore::PageIdentifier>, WebCore::IncludeSecureCookies, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CookieRequestHeaderFieldValue; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, bool>;
    using Reply = CompletionHandler<void(String&&, bool)>;
    CookieRequestHeaderFieldValue(const URL& firstParty, const WebCore::SameSiteInfo& sameSiteInfo, const URL& url, const std::optional<WebCore::FrameIdentifier>& frameID, const std::optional<WebCore::PageIdentifier>& pageID, WebCore::IncludeSecureCookies includeSecureCookies, const std::optional<WebKit::WebPageProxyIdentifier>& webPageProxyID)
        : m_firstParty(firstParty)
        , m_sameSiteInfo(sameSiteInfo)
        , m_url(url)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_includeSecureCookies(includeSecureCookies)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sameSiteInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_includeSecureCookies;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SameSiteInfo& m_sameSiteInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PageIdentifier>& m_pageID;
    WebCore::IncludeSecureCookies m_includeSecureCookies;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_webPageProxyID;
};

class SetRawCookie {
public:
    using Arguments = std::tuple<URL, URL, WebCore::Cookie, WebCore::ShouldPartitionCookie>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SetRawCookie; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetRawCookie(const URL& firstParty, const URL& url, const WebCore::Cookie& cookie, WebCore::ShouldPartitionCookie shouldPartitionCookie)
        : m_firstParty(firstParty)
        , m_url(url)
        , m_cookie(cookie)
        , m_shouldPartitionCookie(shouldPartitionCookie)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookie;
        encoder << m_shouldPartitionCookie;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Cookie& m_cookie;
    WebCore::ShouldPartitionCookie m_shouldPartitionCookie;
};

class GetRawCookies {
public:
    using Arguments = std::tuple<URL, WebCore::SameSiteInfo, URL, std::optional<WebCore::FrameIdentifier>, std::optional<WebCore::PageIdentifier>, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_GetRawCookies; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::Cookie>>;
    using Reply = CompletionHandler<void(Vector<WebCore::Cookie>&&)>;
    GetRawCookies(const URL& firstParty, const WebCore::SameSiteInfo& sameSiteInfo, const URL& url, const std::optional<WebCore::FrameIdentifier>& frameID, const std::optional<WebCore::PageIdentifier>& pageID, const std::optional<WebKit::WebPageProxyIdentifier>& webPageProxyID)
        : m_firstParty(firstParty)
        , m_sameSiteInfo(sameSiteInfo)
        , m_url(url)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sameSiteInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SameSiteInfo& m_sameSiteInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PageIdentifier>& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_webPageProxyID;
};

class DeleteCookie {
public:
    using Arguments = std::tuple<URL, URL, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_DeleteCookie; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_DeleteCookieReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteCookie(const URL& firstParty, const URL& url, const String& cookieName)
        : m_firstParty(firstParty)
        , m_url(url)
        , m_cookieName(cookieName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << m_cookieName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    const String& m_cookieName;
};

class DomCookiesForHost {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_DomCookiesForHost; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::Cookie>>;
    using Reply = CompletionHandler<void(Vector<WebCore::Cookie>&&)>;
    explicit DomCookiesForHost(const URL& host)
        : m_host(host)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_host;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_host;
};

class CookiesForDOMAsync {
public:
    using Arguments = std::tuple<URL, WebCore::SameSiteInfo, URL, std::optional<WebCore::FrameIdentifier>, std::optional<WebCore::PageIdentifier>, WebCore::IncludeSecureCookies, WebCore::CookieStoreGetOptions, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CookiesForDOMAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_CookiesForDOMAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<WebCore::Cookie>>>;
    using Reply = CompletionHandler<void(std::optional<Vector<WebCore::Cookie>>&&)>;
    using Promise = WTF::NativePromise<std::optional<Vector<WebCore::Cookie>>, IPC::Error>;
    CookiesForDOMAsync(const URL& firstParty, const WebCore::SameSiteInfo& sameSiteInfo, const URL& url, const std::optional<WebCore::FrameIdentifier>& frameID, const std::optional<WebCore::PageIdentifier>& pageID, WebCore::IncludeSecureCookies includeSecureCookies, const WebCore::CookieStoreGetOptions& options, const std::optional<WebKit::WebPageProxyIdentifier>& webPageProxyID)
        : m_firstParty(firstParty)
        , m_sameSiteInfo(sameSiteInfo)
        , m_url(url)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_includeSecureCookies(includeSecureCookies)
        , m_options(options)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sameSiteInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_includeSecureCookies;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SameSiteInfo& m_sameSiteInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PageIdentifier>& m_pageID;
    WebCore::IncludeSecureCookies m_includeSecureCookies;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CookieStoreGetOptions& m_options;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_webPageProxyID;
};

class SetCookieFromDOMAsync {
public:
    using Arguments = std::tuple<URL, WebCore::SameSiteInfo, URL, std::optional<WebCore::FrameIdentifier>, std::optional<WebCore::PageIdentifier>, WebCore::Cookie, WebCore::RequiresScriptTrackingPrivacy, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SetCookieFromDOMAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_SetCookieFromDOMAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    SetCookieFromDOMAsync(const URL& firstParty, const WebCore::SameSiteInfo& sameSiteInfo, const URL& url, const std::optional<WebCore::FrameIdentifier>& frameID, const std::optional<WebCore::PageIdentifier>& pageID, const WebCore::Cookie& cookie, WebCore::RequiresScriptTrackingPrivacy requiresScriptTrackingPrivacy, const std::optional<WebKit::WebPageProxyIdentifier>& webPageProxyID)
        : m_firstParty(firstParty)
        , m_sameSiteInfo(sameSiteInfo)
        , m_url(url)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_cookie(cookie)
        , m_requiresScriptTrackingPrivacy(requiresScriptTrackingPrivacy)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sameSiteInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookie;
        encoder << m_requiresScriptTrackingPrivacy;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SameSiteInfo& m_sameSiteInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PageIdentifier>& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Cookie& m_cookie;
    WebCore::RequiresScriptTrackingPrivacy m_requiresScriptTrackingPrivacy;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_webPageProxyID;
};

#if HAVE(COOKIE_CHANGE_LISTENER_API)
class SubscribeToCookieChangeNotifications {
public:
    using Arguments = std::tuple<URL, URL, WebCore::FrameIdentifier, WebCore::PageIdentifier, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SubscribeToCookieChangeNotifications; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_SubscribeToCookieChangeNotificationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    SubscribeToCookieChangeNotifications(const URL& url, const URL& firstParty, const WebCore::FrameIdentifier& frameID, const WebCore::PageIdentifier& pageID, const WebKit::WebPageProxyIdentifier& webPageProxyID)
        : m_url(url)
        , m_firstParty(firstParty)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstParty;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_firstParty;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
};
#endif

#if HAVE(COOKIE_CHANGE_LISTENER_API)
class UnsubscribeFromCookieChangeNotifications {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_UnsubscribeFromCookieChangeNotifications; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UnsubscribeFromCookieChangeNotifications(const String& host)
        : m_host(host)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_host;
    }

private:
    const String& m_host;
};
#endif

class RegisterInternalFileBlobURL {
public:
    using Arguments = std::tuple<URL, String, String, WebKit::SandboxExtensionHandle, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterInternalFileBlobURL; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterInternalFileBlobURL(const URL& url, const String& path, const String& replacementPath, WebKit::SandboxExtensionHandle&& extensionHandle, const String& contentType)
        : m_url(url)
        , m_path(path)
        , m_replacementPath(replacementPath)
        , m_extensionHandle(WTFMove(extensionHandle))
        , m_contentType(contentType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << m_path;
        encoder << m_replacementPath;
        encoder << WTFMove(m_extensionHandle);
        encoder << m_contentType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    const String& m_path;
    const String& m_replacementPath;
    WebKit::SandboxExtensionHandle&& m_extensionHandle;
    const String& m_contentType;
};

class RegisterInternalBlobURL {
public:
    using Arguments = std::tuple<URL, Vector<WebCore::BlobPart>, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterInternalBlobURL; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterInternalBlobURL(const URL& url, const Vector<WebCore::BlobPart>& blobParts, const String& contentType)
        : m_url(url)
        , m_blobParts(blobParts)
        , m_contentType(contentType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_blobParts;
        encoder << m_contentType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::BlobPart>& m_blobParts;
    const String& m_contentType;
};

class RegisterBlobURL {
public:
    using Arguments = std::tuple<URL, URL, WebCore::PolicyContainer, std::optional<WebCore::SecurityOriginData>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterBlobURL; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterBlobURL(const URL& url, const URL& srcURL, const WebCore::PolicyContainer& policyContainer, const std::optional<WebCore::SecurityOriginData>& topOrigin)
        : m_url(url)
        , m_srcURL(srcURL)
        , m_policyContainer(policyContainer)
        , m_topOrigin(topOrigin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_policyContainer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_srcURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PolicyContainer& m_policyContainer;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
};

class RegisterInternalBlobURLOptionallyFileBacked {
public:
    using Arguments = std::tuple<URL, URL, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterInternalBlobURLOptionallyFileBacked; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterInternalBlobURLOptionallyFileBacked(const URL& url, const URL& srcURL, const String& fileBackedPath, const String& contentType)
        : m_url(url)
        , m_srcURL(srcURL)
        , m_fileBackedPath(fileBackedPath)
        , m_contentType(contentType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcURL;
        encoder << m_fileBackedPath;
        encoder << m_contentType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_srcURL;
    const String& m_fileBackedPath;
    const String& m_contentType;
};

class RegisterInternalBlobURLForSlice {
public:
    using Arguments = std::tuple<URL, URL, int64_t, int64_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterInternalBlobURLForSlice; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterInternalBlobURLForSlice(const URL& url, const URL& srcURL, int64_t start, int64_t end, const String& contentType)
        : m_url(url)
        , m_srcURL(srcURL)
        , m_start(start)
        , m_end(end)
        , m_contentType(contentType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_srcURL;
        encoder << m_start;
        encoder << m_end;
        encoder << m_contentType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_srcURL;
    int64_t m_start;
    int64_t m_end;
    const String& m_contentType;
};

class UnregisterBlobURL {
public:
    using Arguments = std::tuple<URL, std::optional<WebCore::SecurityOriginData>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_UnregisterBlobURL; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UnregisterBlobURL(const URL& url, const std::optional<WebCore::SecurityOriginData>& topOrigin)
        : m_url(url)
        , m_topOrigin(topOrigin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
};

class BlobType {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_BlobType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    explicit BlobType(const URL& url)
        : m_url(url)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class BlobSize {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_BlobSize; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    explicit BlobSize(const URL& url)
        : m_url(url)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class WriteBlobsToTemporaryFilesForIndexedDB {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_WriteBlobsToTemporaryFilesForIndexedDB; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_WriteBlobsToTemporaryFilesForIndexedDBReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    using Promise = WTF::NativePromise<Vector<String>, IPC::Error>;
    explicit WriteBlobsToTemporaryFilesForIndexedDB(const Vector<String>& blobURLs)
        : m_blobURLs(blobURLs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_blobURLs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_blobURLs;
};

class RegisterBlobURLHandle {
public:
    using Arguments = std::tuple<URL, std::optional<WebCore::SecurityOriginData>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterBlobURLHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterBlobURLHandle(const URL& url, const std::optional<WebCore::SecurityOriginData>& topOrigin)
        : m_url(url)
        , m_topOrigin(topOrigin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
};

class UnregisterBlobURLHandle {
public:
    using Arguments = std::tuple<URL, std::optional<WebCore::SecurityOriginData>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_UnregisterBlobURLHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UnregisterBlobURLHandle(const URL& url, const std::optional<WebCore::SecurityOriginData>& topOrigin)
        : m_url(url)
        , m_topOrigin(topOrigin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
};

class RegisterBlobPathForTesting {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterBlobPathForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterBlobPathForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit RegisterBlobPathForTesting(const String& path)
        : m_path(path)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_path;
    }

private:
    const String& m_path;
};

class SetCaptureExtraNetworkLoadMetricsEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SetCaptureExtraNetworkLoadMetricsEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCaptureExtraNetworkLoadMetricsEnabled(bool enabled)
        : m_enabled(enabled)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enabled;
    }

private:
    bool m_enabled;
};

class CreateSocketChannel {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest, String, WebCore::WebSocketIdentifier, WebKit::WebPageProxyIdentifier, std::optional<WebCore::FrameIdentifier>, std::optional<WebCore::PageIdentifier>, WebCore::ClientOrigin, bool, bool, OptionSet<WebCore::AdvancedPrivacyProtections>, WebCore::StoredCredentialsPolicy>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CreateSocketChannel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateSocketChannel(const WebCore::ResourceRequest& request, const String& protocol, const WebCore::WebSocketIdentifier& identifier, const WebKit::WebPageProxyIdentifier& webPageProxyID, const std::optional<WebCore::FrameIdentifier>& frameID, const std::optional<WebCore::PageIdentifier>& pageID, const WebCore::ClientOrigin& clientOrigin, bool hadMainFrameMainResourcePrivateRelayed, bool allowPrivacyProxy, const OptionSet<WebCore::AdvancedPrivacyProtections>& protections, WebCore::StoredCredentialsPolicy storedCredentialsPolicy)
        : m_request(request)
        , m_protocol(protocol)
        , m_identifier(identifier)
        , m_webPageProxyID(webPageProxyID)
        , m_frameID(frameID)
        , m_pageID(pageID)
        , m_clientOrigin(clientOrigin)
        , m_hadMainFrameMainResourcePrivateRelayed(hadMainFrameMainResourcePrivateRelayed)
        , m_allowPrivacyProxy(allowPrivacyProxy)
        , m_protections(protections)
        , m_storedCredentialsPolicy(storedCredentialsPolicy)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        encoder << m_protocol;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientOrigin;
        encoder << m_hadMainFrameMainResourcePrivateRelayed;
        encoder << m_allowPrivacyProxy;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_protections;
        encoder << m_storedCredentialsPolicy;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    const String& m_protocol;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebSocketIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PageIdentifier>& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_clientOrigin;
    bool m_hadMainFrameMainResourcePrivateRelayed;
    bool m_allowPrivacyProxy;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::AdvancedPrivacyProtections>& m_protections;
    WebCore::StoredCredentialsPolicy m_storedCredentialsPolicy;
};

class ClearPageSpecificData {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_ClearPageSpecificData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ClearPageSpecificData(const WebCore::PageIdentifier& pageID)
        : m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
};

class RemoveStorageAccessForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RemoveStorageAccessForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveStorageAccessForFrame(const WebCore::FrameIdentifier& frameID, const WebCore::PageIdentifier& pageID)
        : m_frameID(frameID)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
};

class LogUserInteraction {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_LogUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit LogUserInteraction(const WebCore::RegistrableDomain& domain)
        : m_domain(domain)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
};

class ResourceLoadStatisticsUpdated {
public:
    using Arguments = std::tuple<Vector<WebCore::ResourceLoadStatistics>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_ResourceLoadStatisticsUpdated; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_ResourceLoadStatisticsUpdatedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ResourceLoadStatisticsUpdated(const Vector<WebCore::ResourceLoadStatistics>& statistics)
        : m_statistics(statistics)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_statistics;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::ResourceLoadStatistics>& m_statistics;
};

class HasStorageAccess {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain, WebCore::RegistrableDomain, WebCore::FrameIdentifier, WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_HasStorageAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_HasStorageAccessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    HasStorageAccess(const WebCore::RegistrableDomain& subFrameDomain, const WebCore::RegistrableDomain& topFrameDomain, const WebCore::FrameIdentifier& frameID, const WebCore::PageIdentifier& pageID)
        : m_subFrameDomain(subFrameDomain)
        , m_topFrameDomain(topFrameDomain)
        , m_frameID(frameID)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
};

class RequestStorageAccess {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain, WebCore::RegistrableDomain, WebCore::FrameIdentifier, WebCore::PageIdentifier, WebKit::WebPageProxyIdentifier, WebCore::StorageAccessScope>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RequestStorageAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_RequestStorageAccessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::RequestStorageAccessResult>;
    using Reply = CompletionHandler<void(WebCore::RequestStorageAccessResult&&)>;
    using Promise = WTF::NativePromise<WebCore::RequestStorageAccessResult, IPC::Error>;
    RequestStorageAccess(const WebCore::RegistrableDomain& subFrameDomain, const WebCore::RegistrableDomain& topFrameDomain, const WebCore::FrameIdentifier& frameID, const WebCore::PageIdentifier& webPageID, const WebKit::WebPageProxyIdentifier& webPageProxyID, WebCore::StorageAccessScope scope)
        : m_subFrameDomain(subFrameDomain)
        , m_topFrameDomain(topFrameDomain)
        , m_frameID(frameID)
        , m_webPageID(webPageID)
        , m_webPageProxyID(webPageProxyID)
        , m_scope(scope)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
        encoder << m_scope;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_webPageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
    WebCore::StorageAccessScope m_scope;
};

class StorageAccessQuirkForTopFrameDomain {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_StorageAccessQuirkForTopFrameDomain; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_StorageAccessQuirkForTopFrameDomainReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::RegistrableDomain>>;
    using Reply = CompletionHandler<void(Vector<WebCore::RegistrableDomain>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::RegistrableDomain>, IPC::Error>;
    explicit StorageAccessQuirkForTopFrameDomain(const URL& topFrameURL)
        : m_topFrameURL(topFrameURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_topFrameURL;
};

class RequestStorageAccessUnderOpener {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain, WebCore::PageIdentifier, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RequestStorageAccessUnderOpener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestStorageAccessUnderOpener(const WebCore::RegistrableDomain& domainInNeedOfStorageAccess, const WebCore::PageIdentifier& openerPageID, const WebCore::RegistrableDomain& openerDomain)
        : m_domainInNeedOfStorageAccess(domainInNeedOfStorageAccess)
        , m_openerPageID(openerPageID)
        , m_openerDomain(openerDomain)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domainInNeedOfStorageAccess;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_openerPageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_openerDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domainInNeedOfStorageAccess;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_openerPageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_openerDomain;
};

class AddOriginAccessAllowListEntry {
public:
    using Arguments = std::tuple<String, String, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_AddOriginAccessAllowListEntry; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddOriginAccessAllowListEntry(const String& sourceOrigin, const String& destinationProtocol, const String& destinationHost, bool allowDestinationSubdomains)
        : m_sourceOrigin(sourceOrigin)
        , m_destinationProtocol(destinationProtocol)
        , m_destinationHost(destinationHost)
        , m_allowDestinationSubdomains(allowDestinationSubdomains)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sourceOrigin;
        encoder << m_destinationProtocol;
        encoder << m_destinationHost;
        encoder << m_allowDestinationSubdomains;
    }

private:
    const String& m_sourceOrigin;
    const String& m_destinationProtocol;
    const String& m_destinationHost;
    bool m_allowDestinationSubdomains;
};

class RemoveOriginAccessAllowListEntry {
public:
    using Arguments = std::tuple<String, String, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RemoveOriginAccessAllowListEntry; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveOriginAccessAllowListEntry(const String& sourceOrigin, const String& destinationProtocol, const String& destinationHost, bool allowDestinationSubdomains)
        : m_sourceOrigin(sourceOrigin)
        , m_destinationProtocol(destinationProtocol)
        , m_destinationHost(destinationHost)
        , m_allowDestinationSubdomains(allowDestinationSubdomains)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sourceOrigin;
        encoder << m_destinationProtocol;
        encoder << m_destinationHost;
        encoder << m_allowDestinationSubdomains;
    }

private:
    const String& m_sourceOrigin;
    const String& m_destinationProtocol;
    const String& m_destinationHost;
    bool m_allowDestinationSubdomains;
};

class ResetOriginAccessAllowLists {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_ResetOriginAccessAllowLists; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResetOriginAccessAllowLists()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetNetworkLoadInformationResponse {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_GetNetworkLoadInformationResponse; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ResourceResponse>;
    using Reply = CompletionHandler<void(WebCore::ResourceResponse&&)>;
    explicit GetNetworkLoadInformationResponse(const WebCore::ResourceLoaderIdentifier& resourceLoadIdentifier)
        : m_resourceLoadIdentifier(resourceLoadIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceLoadIdentifier;
};

class GetNetworkLoadIntermediateInformation {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_GetNetworkLoadIntermediateInformation; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::NetworkTransactionInformation>>;
    using Reply = CompletionHandler<void(Vector<WebCore::NetworkTransactionInformation>&&)>;
    explicit GetNetworkLoadIntermediateInformation(const WebCore::ResourceLoaderIdentifier& resourceLoadIdentifier)
        : m_resourceLoadIdentifier(resourceLoadIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceLoadIdentifier;
};

class TakeNetworkLoadInformationMetrics {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_TakeNetworkLoadInformationMetrics; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::NetworkLoadMetrics>;
    using Reply = CompletionHandler<void(WebCore::NetworkLoadMetrics&&)>;
    explicit TakeNetworkLoadInformationMetrics(const WebCore::ResourceLoaderIdentifier& resourceLoadIdentifier)
        : m_resourceLoadIdentifier(resourceLoadIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceLoadIdentifier;
};

class EstablishSWContextConnection {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::Site, std::optional<WebCore::ScriptExecutionContextIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_EstablishSWContextConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_EstablishSWContextConnectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    EstablishSWContextConnection(const WebKit::WebPageProxyIdentifier& webPageProxyID, const WebCore::Site& site, const std::optional<WebCore::ScriptExecutionContextIdentifier>& serviceWorkerPageIdentifier)
        : m_webPageProxyID(webPageProxyID)
        , m_site(site)
        , m_serviceWorkerPageIdentifier(serviceWorkerPageIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_site;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerPageIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Site& m_site;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ScriptExecutionContextIdentifier>& m_serviceWorkerPageIdentifier;
};

class CloseSWContextConnection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CloseSWContextConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CloseSWContextConnection()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PingPongForServiceWorkers {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_PingPongForServiceWorkers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_PingPongForServiceWorkersReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    PingPongForServiceWorkers()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class EstablishSharedWorkerContextConnection {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::Site>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_EstablishSharedWorkerContextConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_EstablishSharedWorkerContextConnectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    EstablishSharedWorkerContextConnection(const WebKit::WebPageProxyIdentifier& webPageProxyID, const WebCore::Site& site)
        : m_webPageProxyID(webPageProxyID)
        , m_site(site)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_site;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Site& m_site;
};

class CloseSharedWorkerContextConnection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CloseSharedWorkerContextConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CloseSharedWorkerContextConnection()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CreateRTCProvider {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CreateRTCProvider; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_CreateRTCProviderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    CreateRTCProvider()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(WEB_RTC)
class ConnectToRTCDataChannelRemoteSource {
public:
    using Arguments = std::tuple<WebCore::RTCDataChannelIdentifier, WebCore::RTCDataChannelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_ConnectToRTCDataChannelRemoteSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_ConnectToRTCDataChannelRemoteSourceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<bool>>;
    using Reply = CompletionHandler<void(std::optional<bool>&&)>;
    using Promise = WTF::NativePromise<std::optional<bool>, IPC::Error>;
    ConnectToRTCDataChannelRemoteSource(const WebCore::RTCDataChannelIdentifier& source, const WebCore::RTCDataChannelIdentifier& handler)
        : m_source(source)
        , m_handler(handler)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_source;
        encoder << m_handler;
    }

private:
    const WebCore::RTCDataChannelIdentifier& m_source;
    const WebCore::RTCDataChannelIdentifier& m_handler;
};
#endif

class CreateNewMessagePortChannel {
public:
    using Arguments = std::tuple<WebCore::MessagePortIdentifier, WebCore::MessagePortIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CreateNewMessagePortChannel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateNewMessagePortChannel(const WebCore::MessagePortIdentifier& port1, const WebCore::MessagePortIdentifier& port2)
        : m_port1(port1)
        , m_port2(port2)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_port1;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_port2;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_port1;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_port2;
};

class EntangleLocalPortInThisProcessToRemote {
public:
    using Arguments = std::tuple<WebCore::MessagePortIdentifier, WebCore::MessagePortIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_EntangleLocalPortInThisProcessToRemote; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EntangleLocalPortInThisProcessToRemote(const WebCore::MessagePortIdentifier& local, const WebCore::MessagePortIdentifier& remote)
        : m_local(local)
        , m_remote(remote)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_local;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remote;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_local;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_remote;
};

class MessagePortDisentangled {
public:
    using Arguments = std::tuple<WebCore::MessagePortIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_MessagePortDisentangled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MessagePortDisentangled(const WebCore::MessagePortIdentifier& local)
        : m_local(local)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_local;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_local;
};

class MessagePortClosed {
public:
    using Arguments = std::tuple<WebCore::MessagePortIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_MessagePortClosed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MessagePortClosed(const WebCore::MessagePortIdentifier& local)
        : m_local(local)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_local;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_local;
};

class TakeAllMessagesForPort {
public:
    using Arguments = std::tuple<WebCore::MessagePortIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_TakeAllMessagesForPort; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_TakeAllMessagesForPortReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::MessageWithMessagePorts>, std::optional<WebKit::MessageBatchIdentifier>>;
    using Reply = CompletionHandler<void(Vector<WebCore::MessageWithMessagePorts>&&, std::optional<WebKit::MessageBatchIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<WebCore::MessageWithMessagePorts>, std::optional<WebKit::MessageBatchIdentifier>>, IPC::Error>;
    explicit TakeAllMessagesForPort(const WebCore::MessagePortIdentifier& port)
        : m_port(port)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_port;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_port;
};

class PostMessageToRemote {
public:
    using Arguments = std::tuple<WebCore::MessageWithMessagePorts, WebCore::MessagePortIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_PostMessageToRemote; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostMessageToRemote(const WebCore::MessageWithMessagePorts& message, const WebCore::MessagePortIdentifier& remote)
        : m_message(message)
        , m_remote(remote)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remote;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessageWithMessagePorts& m_message;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_remote;
};

class DidDeliverMessagePortMessages {
public:
    using Arguments = std::tuple<WebKit::MessageBatchIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_DidDeliverMessagePortMessages; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDeliverMessagePortMessages(const WebKit::MessageBatchIdentifier& messageBatchIdentifier)
        : m_messageBatchIdentifier(messageBatchIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_messageBatchIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MessageBatchIdentifier& m_messageBatchIdentifier;
};

class RegisterURLSchemesAsCORSEnabled {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_RegisterURLSchemesAsCORSEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemesAsCORSEnabled(const Vector<String>& schemes)
        : m_schemes(schemes)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_schemes;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_schemes;
};

class SetCORSDisablingPatterns {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SetCORSDisablingPatterns; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetCORSDisablingPatterns(const WebCore::PageIdentifier& pageIdentifier, const Vector<String>& patterns)
        : m_pageIdentifier(pageIdentifier)
        , m_patterns(patterns)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_patterns;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_patterns;
};

#if PLATFORM(MAC)
class GetProcessDisplayName {
public:
    using Arguments = std::tuple<WebKit::CoreIPCAuditToken>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_GetProcessDisplayName; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_GetProcessDisplayNameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit GetProcessDisplayName(const WebKit::CoreIPCAuditToken& auditToken)
        : m_auditToken(auditToken)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_auditToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::CoreIPCAuditToken& m_auditToken;
};
#endif

#if PLATFORM(MAC)
class UpdateActivePages {
public:
    using Arguments = std::tuple<String, Vector<String>, WebKit::CoreIPCAuditToken>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_UpdateActivePages; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateActivePages(const String& name, const Vector<String>& activePagesOrigins, const WebKit::CoreIPCAuditToken& auditToken)
        : m_name(name)
        , m_activePagesOrigins(activePagesOrigins)
        , m_auditToken(auditToken)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_activePagesOrigins;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_auditToken;
    }

private:
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_activePagesOrigins;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::CoreIPCAuditToken& m_auditToken;
};
#endif

#if (PLATFORM(MAC) && ENABLE(LAUNCHSERVICES_SANDBOX_EXTENSION_BLOCKING))
class CheckInWebProcess {
public:
    using Arguments = std::tuple<WebKit::CoreIPCAuditToken>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_CheckInWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CheckInWebProcess(const WebKit::CoreIPCAuditToken& auditToken)
        : m_auditToken(auditToken)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_auditToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::CoreIPCAuditToken& m_auditToken;
};
#endif

class SetResourceLoadSchedulingMode {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, WebCore::LoadSchedulingMode>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SetResourceLoadSchedulingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetResourceLoadSchedulingMode(const WebCore::PageIdentifier& webPageID, WebCore::LoadSchedulingMode mode)
        : m_webPageID(webPageID)
        , m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageID;
        encoder << m_mode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_webPageID;
    WebCore::LoadSchedulingMode m_mode;
};

class PrioritizeResourceLoads {
public:
    using Arguments = std::tuple<Vector<WebCore::ResourceLoaderIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_PrioritizeResourceLoads; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PrioritizeResourceLoads(const Vector<WebCore::ResourceLoaderIdentifier>& loadIdentifiers)
        : m_loadIdentifiers(loadIdentifiers)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_loadIdentifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::ResourceLoaderIdentifier>& m_loadIdentifiers;
};

#if ENABLE(CONTENT_FILTERING)
class InstallMockContentFilter {
public:
    using Arguments = std::tuple<WebCore::MockContentFilterSettings>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_InstallMockContentFilter; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit InstallMockContentFilter(const WebCore::MockContentFilterSettings& settings)
        : m_settings(settings)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_settings;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MockContentFilterSettings& m_settings;
};
#endif

class UseRedirectionForCurrentNavigation {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_UseRedirectionForCurrentNavigation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UseRedirectionForCurrentNavigation(const WebCore::ResourceLoaderIdentifier& resourceLoadIdentifier, const WebCore::ResourceResponse& response)
        : m_resourceLoadIdentifier(resourceLoadIdentifier)
        , m_response(response)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceLoadIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

#if ENABLE(DECLARATIVE_WEB_PUSH)
class NavigatorSubscribeToPushService {
public:
    using Arguments = std::tuple<URL, Vector<uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_NavigatorSubscribeToPushService; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_NavigatorSubscribeToPushServiceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::PushSubscriptionData, WebCore::ExceptionData>, IPC::Error>;
    NavigatorSubscribeToPushService(const URL& scopeURL, const Vector<uint8_t>& applicationServerKey)
        : m_scopeURL(scopeURL)
        , m_applicationServerKey(applicationServerKey)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_applicationServerKey;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint8_t>& m_applicationServerKey;
};
#endif

#if ENABLE(DECLARATIVE_WEB_PUSH)
class NavigatorUnsubscribeFromPushService {
public:
    using Arguments = std::tuple<URL, WebCore::PushSubscriptionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_NavigatorUnsubscribeFromPushService; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_NavigatorUnsubscribeFromPushServiceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<bool, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebCore::ExceptionData>, IPC::Error>;
    NavigatorUnsubscribeFromPushService(const URL& scopeURL, const WebCore::PushSubscriptionIdentifier& pushSubscriptionIdentifier)
        : m_scopeURL(scopeURL)
        , m_pushSubscriptionIdentifier(pushSubscriptionIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pushSubscriptionIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PushSubscriptionIdentifier& m_pushSubscriptionIdentifier;
};
#endif

#if ENABLE(DECLARATIVE_WEB_PUSH)
class NavigatorGetPushSubscription {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_NavigatorGetPushSubscription; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_NavigatorGetPushSubscriptionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::PushSubscriptionData>, WebCore::ExceptionData>, IPC::Error>;
    explicit NavigatorGetPushSubscription(const URL& scopeURL)
        : m_scopeURL(scopeURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
};
#endif

#if ENABLE(DECLARATIVE_WEB_PUSH)
class NavigatorGetPushPermissionState {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_NavigatorGetPushPermissionState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_NavigatorGetPushPermissionStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<uint8_t, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<uint8_t, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<uint8_t, WebCore::ExceptionData>, IPC::Error>;
    explicit NavigatorGetPushPermissionState(const URL& scopeURL)
        : m_scopeURL(scopeURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scopeURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scopeURL;
};
#endif

class InitializeWebTransportSession {
public:
    using Arguments = std::tuple<URL, WebKit::WebPageProxyIdentifier, WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_InitializeWebTransportSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_InitializeWebTransportSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::WebTransportSessionIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::WebTransportSessionIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::WebTransportSessionIdentifier>, IPC::Error>;
    InitializeWebTransportSession(const URL& url, const WebKit::WebPageProxyIdentifier& pageID, const WebCore::ClientOrigin& clientOrigin)
        : m_url(url)
        , m_pageID(pageID)
        , m_clientOrigin(clientOrigin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientOrigin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_clientOrigin;
};

class DestroyWebTransportSession {
public:
    using Arguments = std::tuple<WebKit::WebTransportSessionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_DestroyWebTransportSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DestroyWebTransportSession(const WebKit::WebTransportSessionIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebTransportSessionIdentifier& m_identifier;
};

class ClearFrameLoadRecordsForStorageAccess {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_ClearFrameLoadRecordsForStorageAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ClearFrameLoadRecordsForStorageAccess(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class LoadImageForDecoding {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest, WebKit::WebPageProxyIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_LoadImageForDecoding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_LoadImageForDecodingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Ref<WebCore::FragmentedSharedBuffer>, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<Ref<WebCore::FragmentedSharedBuffer>, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<Ref<WebCore::FragmentedSharedBuffer>, WebCore::ResourceError>, IPC::Error>;
    LoadImageForDecoding(const WebCore::ResourceRequest& request, const WebKit::WebPageProxyIdentifier& pageID, uint64_t maximumBytesFromNetwork)
        : m_request(request)
        , m_pageID(pageID)
        , m_maximumBytesFromNetwork(maximumBytesFromNetwork)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_maximumBytesFromNetwork;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    uint64_t m_maximumBytesFromNetwork;
};

class SetLoginStatus {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain, WebCore::IsLoggedIn, std::optional<WebCore::LoginStatus>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_SetLoginStatus; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_SetLoginStatusReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetLoginStatus(const WebCore::RegistrableDomain& domain, WebCore::IsLoggedIn loggedInStatus, const std::optional<WebCore::LoginStatus>& lastAuthentication)
        : m_domain(domain)
        , m_loggedInStatus(loggedInStatus)
        , m_lastAuthentication(lastAuthentication)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
        encoder << m_loggedInStatus;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lastAuthentication;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
    WebCore::IsLoggedIn m_loggedInStatus;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::LoginStatus>& m_lastAuthentication;
};

class IsLoggedIn {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_IsLoggedIn; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_IsLoggedInReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit IsLoggedIn(const WebCore::RegistrableDomain& domain)
        : m_domain(domain)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
};

#if ENABLE(CONTENT_EXTENSIONS)
class ShouldOffloadIFrameForHost {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkConnectionToWebProcess_ShouldOffloadIFrameForHost; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkConnectionToWebProcess_ShouldOffloadIFrameForHostReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit ShouldOffloadIFrameForHost(const String& host)
        : m_host(host)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_host;
    }

private:
    const String& m_host;
};
#endif

} // namespace NetworkConnectionToWebProcess
} // namespace Messages
