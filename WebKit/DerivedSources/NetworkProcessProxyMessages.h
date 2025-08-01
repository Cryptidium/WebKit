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
#include <span>
#include <wtf/Forward.h>
#include <wtf/HashMap.h>
#include <wtf/HashSet.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/OptionSet.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class FormDataReference;
}

namespace JSC {
enum class MessageLevel : uint8_t;
enum class MessageSource : uint8_t;
}

namespace PAL {
class SessionID;
}

namespace WebCore {
class AuthenticationChallenge;
class Credential;
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
struct NavigationIdentifierType;
using NavigationIdentifier = ObjectIdentifier<NavigationIdentifierType>;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct ProcessIdentifierType;
using ProcessIdentifier = ObjectIdentifier<ProcessIdentifierType>;
class RegistrableDomain;
class ResourceError;
class ResourceRequest;
class ResourceResponse;
class SecurityOriginData;
class Site;
enum class ShouldSample : bool;
enum class BrowsingContextGroupSwitchDecision : uint8_t;
struct ClientOrigin;
struct OrganizationStorageAccessPromptQuirk;
}

namespace WebKit {
struct AuthenticationChallengeIdentifierType;
using AuthenticationChallengeIdentifier = ObjectIdentifier<AuthenticationChallengeIdentifierType>;
struct DataTaskIdentifierType;
using DataTaskIdentifier = ObjectIdentifier<DataTaskIdentifierType>;
struct NetworkResourceLoadIdentifierType;
using NetworkResourceLoadIdentifier = ObjectIdentifier<NetworkResourceLoadIdentifierType>;
struct QuotaIncreaseRequestIdentifierType;
using QuotaIncreaseRequestIdentifier = AtomicObjectIdentifier<QuotaIncreaseRequestIdentifierType>;
struct UserContentControllerIdentifierType;
using UserContentControllerIdentifier = ObjectIdentifier<UserContentControllerIdentifierType>;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
enum class AuthenticationChallengeDisposition : uint8_t;
enum class BackgroundFetchChange : uint8_t;
enum class RemoteWorkerType : uint8_t;
struct ResourceLoadInfo;
}

namespace Messages {
namespace NetworkProcessProxy {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(!isInAuxiliaryProcess());
        }
    );
#endif
    return IPC::ReceiverName::NetworkProcessProxy;
}

class DidReceiveAuthenticationChallenge {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::WebPageProxyIdentifier, std::optional<WebCore::SecurityOriginData>, WebCore::AuthenticationChallenge, bool, WebKit::AuthenticationChallengeIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DidReceiveAuthenticationChallenge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveAuthenticationChallenge(const PAL::SessionID& sessionID, const WebKit::WebPageProxyIdentifier& pageID, const std::optional<WebCore::SecurityOriginData>& topOrigin, const WebCore::AuthenticationChallenge& challenge, bool negotiatedLegacyTLS, const WebKit::AuthenticationChallengeIdentifier& challengeID)
        : m_sessionID(sessionID)
        , m_pageID(pageID)
        , m_topOrigin(topOrigin)
        , m_challenge(challenge)
        , m_negotiatedLegacyTLS(negotiatedLegacyTLS)
        , m_challengeID(challengeID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_challenge;
        encoder << m_negotiatedLegacyTLS;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_challengeID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_topOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AuthenticationChallenge& m_challenge;
    bool m_negotiatedLegacyTLS;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AuthenticationChallengeIdentifier& m_challengeID;
};

class NegotiatedLegacyTLS {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_NegotiatedLegacyTLS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit NegotiatedLegacyTLS(const WebKit::WebPageProxyIdentifier& pageID)
        : m_pageID(pageID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
};

class DidNegotiateModernTLS {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DidNegotiateModernTLS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidNegotiateModernTLS(const WebKit::WebPageProxyIdentifier& pageID, const URL& url)
        : m_pageID(pageID)
        , m_url(url)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class DidBlockLoadToKnownTracker {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DidBlockLoadToKnownTracker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidBlockLoadToKnownTracker(const WebKit::WebPageProxyIdentifier& pageID, const URL& url)
        : m_pageID(pageID)
        , m_url(url)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class TestProcessIncomingSyncMessagesWhenWaitingForSyncReply {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply; }
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
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
};

class ProcessHasUnresponseServiceWorker {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ProcessHasUnresponseServiceWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ProcessHasUnresponseServiceWorker(const WebCore::ProcessIdentifier& processIdentifier)
        : m_processIdentifier(processIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
};

class LogDiagnosticMessage {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, String, String, WebCore::ShouldSample>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_LogDiagnosticMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessage(const WebKit::WebPageProxyIdentifier& pageID, const String& message, const String& description, WebCore::ShouldSample shouldSample)
        : m_pageID(pageID)
        , m_message(message)
        , m_description(description)
        , m_shouldSample(shouldSample)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_message;
        encoder << m_description;
        encoder << m_shouldSample;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    const String& m_message;
    const String& m_description;
    WebCore::ShouldSample m_shouldSample;
};

class LogDiagnosticMessageWithResult {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, String, String, uint32_t, WebCore::ShouldSample>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_LogDiagnosticMessageWithResult; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessageWithResult(const WebKit::WebPageProxyIdentifier& pageID, const String& message, const String& description, uint32_t result, WebCore::ShouldSample shouldSample)
        : m_pageID(pageID)
        , m_message(message)
        , m_description(description)
        , m_result(result)
        , m_shouldSample(shouldSample)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_message;
        encoder << m_description;
        encoder << m_result;
        encoder << m_shouldSample;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    const String& m_message;
    const String& m_description;
    uint32_t m_result;
    WebCore::ShouldSample m_shouldSample;
};

class LogDiagnosticMessageWithValue {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, String, String, double, unsigned, WebCore::ShouldSample>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_LogDiagnosticMessageWithValue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessageWithValue(const WebKit::WebPageProxyIdentifier& pageID, const String& message, const String& description, double value, const unsigned& significantFigures, WebCore::ShouldSample shouldSample)
        : m_pageID(pageID)
        , m_message(message)
        , m_description(description)
        , m_value(value)
        , m_significantFigures(significantFigures)
        , m_shouldSample(shouldSample)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_message;
        encoder << m_description;
        encoder << m_value;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_significantFigures;
        encoder << m_shouldSample;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    const String& m_message;
    const String& m_description;
    double m_value;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_significantFigures;
    WebCore::ShouldSample m_shouldSample;
};

class LogTestingEvent {
public:
    using Arguments = std::tuple<PAL::SessionID, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_LogTestingEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogTestingEvent(const PAL::SessionID& sessionID, const String& event)
        : m_sessionID(sessionID)
        , m_event(event)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_event;
};

class RequestStorageAccessConfirm {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::FrameIdentifier, WebCore::RegistrableDomain, WebCore::RegistrableDomain, std::optional<WebCore::OrganizationStorageAccessPromptQuirk>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_RequestStorageAccessConfirm; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_RequestStorageAccessConfirmReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    RequestStorageAccessConfirm(const WebKit::WebPageProxyIdentifier& pageID, const WebCore::FrameIdentifier& frameID, const WebCore::RegistrableDomain& subFrameDomain, const WebCore::RegistrableDomain& topFrameDomain, const std::optional<WebCore::OrganizationStorageAccessPromptQuirk>& organizationStorageAccessPromptQuirk)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_subFrameDomain(subFrameDomain)
        , m_topFrameDomain(topFrameDomain)
        , m_organizationStorageAccessPromptQuirk(organizationStorageAccessPromptQuirk)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_subFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topFrameDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_organizationStorageAccessPromptQuirk;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_subFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_topFrameDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::OrganizationStorageAccessPromptQuirk>& m_organizationStorageAccessPromptQuirk;
};

class DeleteWebsiteDataInUIProcessForRegistrableDomains {
public:
    using Arguments = std::tuple<PAL::SessionID, OptionSet<WebKit::WebsiteDataType>, OptionSet<WebKit::WebsiteDataFetchOption>, Vector<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DeleteWebsiteDataInUIProcessForRegistrableDomains; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_DeleteWebsiteDataInUIProcessForRegistrableDomainsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<HashSet<WebCore::RegistrableDomain>>;
    using Reply = CompletionHandler<void(HashSet<WebCore::RegistrableDomain>&&)>;
    using Promise = WTF::NativePromise<HashSet<WebCore::RegistrableDomain>, IPC::Error>;
    DeleteWebsiteDataInUIProcessForRegistrableDomains(const PAL::SessionID& sessionID, const OptionSet<WebKit::WebsiteDataType>& dataTypes, const OptionSet<WebKit::WebsiteDataFetchOption>& fetchOptions, const Vector<WebCore::RegistrableDomain>& domains)
        : m_sessionID(sessionID)
        , m_dataTypes(dataTypes)
        , m_fetchOptions(fetchOptions)
        , m_domains(domains)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dataTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fetchOptions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_dataTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataFetchOption>& m_fetchOptions;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::RegistrableDomain>& m_domains;
};

class DidCommitCrossSiteLoadWithDataTransferFromPrevalentResource {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DidCommitCrossSiteLoadWithDataTransferFromPrevalentResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidCommitCrossSiteLoadWithDataTransferFromPrevalentResource(const WebKit::WebPageProxyIdentifier& pageID)
        : m_pageID(pageID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
};

class SetDomainsWithUserInteraction {
public:
    using Arguments = std::tuple<HashSet<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_SetDomainsWithUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDomainsWithUserInteraction(const HashSet<WebCore::RegistrableDomain>& domains)
        : m_domains(domains)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<WebCore::RegistrableDomain>& m_domains;
};

class SetDomainsWithCrossPageStorageAccess {
public:
    using Arguments = std::tuple<HashMap<WebCore::RegistrableDomain, Vector<WebCore::RegistrableDomain>>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_SetDomainsWithCrossPageStorageAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_SetDomainsWithCrossPageStorageAccessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetDomainsWithCrossPageStorageAccess(const HashMap<WebCore::RegistrableDomain, Vector<WebCore::RegistrableDomain>>& domains)
        : m_domains(domains)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<WebCore::RegistrableDomain, Vector<WebCore::RegistrableDomain>>& m_domains;
};

#if ENABLE(CONTENT_EXTENSIONS)
class ContentExtensionRules {
public:
    using Arguments = std::tuple<WebKit::UserContentControllerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ContentExtensionRules; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ContentExtensionRules(const WebKit::UserContentControllerIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserContentControllerIdentifier& m_identifier;
};
#endif

class TerminateWebProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_TerminateWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TerminateWebProcess(const WebCore::ProcessIdentifier& webProcessIdentifier)
        : m_webProcessIdentifier(webProcessIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webProcessIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_webProcessIdentifier;
};

class StartServiceWorkerBackgroundProcessing {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_StartServiceWorkerBackgroundProcessing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StartServiceWorkerBackgroundProcessing(const WebCore::ProcessIdentifier& serviceWorkerProcessIdentifier)
        : m_serviceWorkerProcessIdentifier(serviceWorkerProcessIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerProcessIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_serviceWorkerProcessIdentifier;
};

class EndServiceWorkerBackgroundProcessing {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_EndServiceWorkerBackgroundProcessing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit EndServiceWorkerBackgroundProcessing(const WebCore::ProcessIdentifier& serviceWorkerProcessIdentifier)
        : m_serviceWorkerProcessIdentifier(serviceWorkerProcessIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerProcessIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_serviceWorkerProcessIdentifier;
};

class RequestBackgroundFetchPermission {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_RequestBackgroundFetchPermission; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_RequestBackgroundFetchPermissionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    RequestBackgroundFetchPermission(const PAL::SessionID& sessionID, const WebCore::ClientOrigin& origin)
        : m_sessionID(sessionID)
        , m_origin(origin)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class NotifyBackgroundFetchChange {
public:
    using Arguments = std::tuple<PAL::SessionID, String, WebKit::BackgroundFetchChange>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_NotifyBackgroundFetchChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyBackgroundFetchChange(const PAL::SessionID& sessionID, const String& backgroundFetchIdentifier, WebKit::BackgroundFetchChange change)
        : m_sessionID(sessionID)
        , m_backgroundFetchIdentifier(backgroundFetchIdentifier)
        , m_change(change)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_backgroundFetchIdentifier;
        encoder << m_change;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_backgroundFetchIdentifier;
    WebKit::BackgroundFetchChange m_change;
};

class EstablishRemoteWorkerContextConnectionToNetworkProcess {
public:
    using Arguments = std::tuple<WebKit::RemoteWorkerType, WebCore::Site, std::optional<WebCore::ProcessIdentifier>, std::optional<WebCore::ScriptExecutionContextIdentifier>, PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_EstablishRemoteWorkerContextConnectionToNetworkProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_EstablishRemoteWorkerContextConnectionToNetworkProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ProcessIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ProcessIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ProcessIdentifier>, IPC::Error>;
    EstablishRemoteWorkerContextConnectionToNetworkProcess(WebKit::RemoteWorkerType workerType, const WebCore::Site& site, const std::optional<WebCore::ProcessIdentifier>& requestingProcessIdentifier, const std::optional<WebCore::ScriptExecutionContextIdentifier>& serviceWorkerPageIdentifier, const PAL::SessionID& sessionID)
        : m_workerType(workerType)
        , m_site(site)
        , m_requestingProcessIdentifier(requestingProcessIdentifier)
        , m_serviceWorkerPageIdentifier(serviceWorkerPageIdentifier)
        , m_sessionID(sessionID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_workerType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_site;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestingProcessIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerPageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    WebKit::RemoteWorkerType m_workerType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Site& m_site;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ProcessIdentifier>& m_requestingProcessIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ScriptExecutionContextIdentifier>& m_serviceWorkerPageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class RemoteWorkerContextConnectionNoLongerNeeded {
public:
    using Arguments = std::tuple<WebKit::RemoteWorkerType, WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_RemoteWorkerContextConnectionNoLongerNeeded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoteWorkerContextConnectionNoLongerNeeded(WebKit::RemoteWorkerType workerType, const WebCore::ProcessIdentifier& identifier)
        : m_workerType(workerType)
        , m_identifier(identifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_workerType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    WebKit::RemoteWorkerType m_workerType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_identifier;
};

class RegisterRemoteWorkerClientProcess {
public:
    using Arguments = std::tuple<WebKit::RemoteWorkerType, WebCore::ProcessIdentifier, WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_RegisterRemoteWorkerClientProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterRemoteWorkerClientProcess(WebKit::RemoteWorkerType workerType, const WebCore::ProcessIdentifier& clientProcessIdentifier, const WebCore::ProcessIdentifier& remoteWorkerProcessIdentifier)
        : m_workerType(workerType)
        , m_clientProcessIdentifier(clientProcessIdentifier)
        , m_remoteWorkerProcessIdentifier(remoteWorkerProcessIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_workerType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientProcessIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remoteWorkerProcessIdentifier;
    }

private:
    WebKit::RemoteWorkerType m_workerType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_clientProcessIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_remoteWorkerProcessIdentifier;
};

class UnregisterRemoteWorkerClientProcess {
public:
    using Arguments = std::tuple<WebKit::RemoteWorkerType, WebCore::ProcessIdentifier, WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_UnregisterRemoteWorkerClientProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UnregisterRemoteWorkerClientProcess(WebKit::RemoteWorkerType workerType, const WebCore::ProcessIdentifier& clientProcessIdentifier, const WebCore::ProcessIdentifier& remoteWorkerProcessIdentifier)
        : m_workerType(workerType)
        , m_clientProcessIdentifier(clientProcessIdentifier)
        , m_remoteWorkerProcessIdentifier(remoteWorkerProcessIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_workerType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientProcessIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remoteWorkerProcessIdentifier;
    }

private:
    WebKit::RemoteWorkerType m_workerType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_clientProcessIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_remoteWorkerProcessIdentifier;
};

class SetWebProcessHasUploads {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_SetWebProcessHasUploads; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetWebProcessHasUploads(const WebCore::ProcessIdentifier& processID, bool hasUpload)
        : m_processID(processID)
        , m_hasUpload(hasUpload)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processID;
        encoder << m_hasUpload;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processID;
    bool m_hasUpload;
};

#if ENABLE(APP_BOUND_DOMAINS)
class GetAppBoundDomains {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_GetAppBoundDomains; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_GetAppBoundDomainsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<HashSet<WebCore::RegistrableDomain>>;
    using Reply = CompletionHandler<void(HashSet<WebCore::RegistrableDomain>&&)>;
    using Promise = WTF::NativePromise<HashSet<WebCore::RegistrableDomain>, IPC::Error>;
    explicit GetAppBoundDomains(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(isInNetworkProcess());
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

class IncreaseQuota {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::ClientOrigin, WebKit::QuotaIncreaseRequestIdentifier, uint64_t, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_IncreaseQuota; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    IncreaseQuota(const PAL::SessionID& sessionID, const WebCore::ClientOrigin& origin, const WebKit::QuotaIncreaseRequestIdentifier& identifier, uint64_t quota, uint64_t currentSize, uint64_t spaceRequested)
        : m_sessionID(sessionID)
        , m_origin(origin)
        , m_identifier(identifier)
        , m_quota(quota)
        , m_currentSize(currentSize)
        , m_spaceRequested(spaceRequested)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_quota;
        encoder << m_currentSize;
        encoder << m_spaceRequested;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::QuotaIncreaseRequestIdentifier& m_identifier;
    uint64_t m_quota;
    uint64_t m_currentSize;
    uint64_t m_spaceRequested;
};

class ResourceLoadDidSendRequest {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::ResourceLoadInfo, WebCore::ResourceRequest, std::optional<IPC::FormDataReference>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ResourceLoadDidSendRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidSendRequest(const WebKit::WebPageProxyIdentifier& pageIdentifier, const WebKit::ResourceLoadInfo& resourceLoadInfo, const WebCore::ResourceRequest& request, const std::optional<IPC::FormDataReference>& httpBody)
        : m_pageIdentifier(pageIdentifier)
        , m_resourceLoadInfo(resourceLoadInfo)
        , m_request(request)
        , m_httpBody(httpBody)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_httpBody;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<IPC::FormDataReference>& m_httpBody;
};

class ResourceLoadDidPerformHTTPRedirection {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::ResourceLoadInfo, WebCore::ResourceResponse, WebCore::ResourceRequest>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ResourceLoadDidPerformHTTPRedirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidPerformHTTPRedirection(const WebKit::WebPageProxyIdentifier& pageIdentifier, const WebKit::ResourceLoadInfo& resourceLoadInfo, const WebCore::ResourceResponse& resourceResponse, const WebCore::ResourceRequest& request)
        : m_pageIdentifier(pageIdentifier)
        , m_resourceLoadInfo(resourceLoadInfo)
        , m_resourceResponse(resourceResponse)
        , m_request(request)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceResponse;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_resourceResponse;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
};

class ResourceLoadDidReceiveChallenge {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::ResourceLoadInfo, WebCore::AuthenticationChallenge>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ResourceLoadDidReceiveChallenge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidReceiveChallenge(const WebKit::WebPageProxyIdentifier& pageIdentifier, const WebKit::ResourceLoadInfo& resourceLoadInfo, const WebCore::AuthenticationChallenge& challenge)
        : m_pageIdentifier(pageIdentifier)
        , m_resourceLoadInfo(resourceLoadInfo)
        , m_challenge(challenge)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_challenge;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AuthenticationChallenge& m_challenge;
};

class ResourceLoadDidReceiveResponse {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::ResourceLoadInfo, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ResourceLoadDidReceiveResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidReceiveResponse(const WebKit::WebPageProxyIdentifier& pageIdentifier, const WebKit::ResourceLoadInfo& resourceLoadInfo, const WebCore::ResourceResponse& response)
        : m_pageIdentifier(pageIdentifier)
        , m_resourceLoadInfo(resourceLoadInfo)
        , m_response(response)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

class ResourceLoadDidCompleteWithError {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::ResourceLoadInfo, WebCore::ResourceResponse, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ResourceLoadDidCompleteWithError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidCompleteWithError(const WebKit::WebPageProxyIdentifier& pageIdentifier, const WebKit::ResourceLoadInfo& resourceLoadInfo, const WebCore::ResourceResponse& response, const WebCore::ResourceError& error)
        : m_pageIdentifier(pageIdentifier)
        , m_resourceLoadInfo(resourceLoadInfo)
        , m_response(response)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class DidAllowPrivateTokenUsageByThirdPartyForTesting {
public:
    using Arguments = std::tuple<PAL::SessionID, bool, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DidAllowPrivateTokenUsageByThirdPartyForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidAllowPrivateTokenUsageByThirdPartyForTesting(const PAL::SessionID& sessionID, bool wasAllowed, const URL& resourceURL)
        : m_sessionID(sessionID)
        , m_wasAllowed(wasAllowed)
        , m_resourceURL(resourceURL)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_wasAllowed;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    bool m_wasAllowed;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_resourceURL;
};

class TriggerBrowsingContextGroupSwitchForNavigation {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::NavigationIdentifier, WebCore::BrowsingContextGroupSwitchDecision, WebCore::Site, WebKit::NetworkResourceLoadIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_TriggerBrowsingContextGroupSwitchForNavigation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_TriggerBrowsingContextGroupSwitchForNavigationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    TriggerBrowsingContextGroupSwitchForNavigation(const WebKit::WebPageProxyIdentifier& pageIdentifier, const WebCore::NavigationIdentifier& navigationID, WebCore::BrowsingContextGroupSwitchDecision browsingContextGroupSwitchDecision, const WebCore::Site& responseSite, const WebKit::NetworkResourceLoadIdentifier& existingNetworkResourceLoadIdentifierToResume)
        : m_pageIdentifier(pageIdentifier)
        , m_navigationID(navigationID)
        , m_browsingContextGroupSwitchDecision(browsingContextGroupSwitchDecision)
        , m_responseSite(responseSite)
        , m_existingNetworkResourceLoadIdentifierToResume(existingNetworkResourceLoadIdentifierToResume)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        encoder << m_browsingContextGroupSwitchDecision;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_responseSite;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_existingNetworkResourceLoadIdentifierToResume;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NavigationIdentifier& m_navigationID;
    WebCore::BrowsingContextGroupSwitchDecision m_browsingContextGroupSwitchDecision;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Site& m_responseSite;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::NetworkResourceLoadIdentifier& m_existingNetworkResourceLoadIdentifierToResume;
};

#if USE(SOUP)
class DidExceedMemoryLimit {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DidExceedMemoryLimit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidExceedMemoryLimit()
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(APPLE_PAY_REMOTE_UI_USES_SCENE)
class GetWindowSceneAndBundleIdentifierForPaymentPresentation {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_GetWindowSceneAndBundleIdentifierForPaymentPresentation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_GetWindowSceneAndBundleIdentifierForPaymentPresentationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, String>;
    using Reply = CompletionHandler<void(String&&, String&&)>;
    using Promise = WTF::NativePromise<std::tuple<String, String>, IPC::Error>;
    explicit GetWindowSceneAndBundleIdentifierForPaymentPresentation(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
};
#endif

#if ENABLE(APPLE_PAY_REMOTE_UI)
class GetPaymentCoordinatorEmbeddingUserAgent {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_GetPaymentCoordinatorEmbeddingUserAgent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_GetPaymentCoordinatorEmbeddingUserAgentReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit GetPaymentCoordinatorEmbeddingUserAgent(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
};
#endif

class DataTaskReceivedChallenge {
public:
    using Arguments = std::tuple<WebKit::DataTaskIdentifier, WebCore::AuthenticationChallenge>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DataTaskReceivedChallenge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_DataTaskReceivedChallengeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::AuthenticationChallengeDisposition, WebCore::Credential>;
    using Reply = CompletionHandler<void(WebKit::AuthenticationChallengeDisposition, WebCore::Credential&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebKit::AuthenticationChallengeDisposition, WebCore::Credential>, IPC::Error>;
    DataTaskReceivedChallenge(const WebKit::DataTaskIdentifier& identifier, const WebCore::AuthenticationChallenge& challenge)
        : m_identifier(identifier)
        , m_challenge(challenge)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_challenge;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DataTaskIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AuthenticationChallenge& m_challenge;
};

class DataTaskWillPerformHTTPRedirection {
public:
    using Arguments = std::tuple<WebKit::DataTaskIdentifier, WebCore::ResourceResponse, WebCore::ResourceRequest>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DataTaskWillPerformHTTPRedirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_DataTaskWillPerformHTTPRedirectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    DataTaskWillPerformHTTPRedirection(const WebKit::DataTaskIdentifier& identifier, const WebCore::ResourceResponse& response, const WebCore::ResourceRequest& request)
        : m_identifier(identifier)
        , m_response(response)
        , m_request(request)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DataTaskIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
};

class DataTaskDidReceiveResponse {
public:
    using Arguments = std::tuple<WebKit::DataTaskIdentifier, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DataTaskDidReceiveResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_DataTaskDidReceiveResponseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    DataTaskDidReceiveResponse(const WebKit::DataTaskIdentifier& identifier, const WebCore::ResourceResponse& response)
        : m_identifier(identifier)
        , m_response(response)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DataTaskIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

class DataTaskDidReceiveData {
public:
    using Arguments = std::tuple<WebKit::DataTaskIdentifier, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DataTaskDidReceiveData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DataTaskDidReceiveData(const WebKit::DataTaskIdentifier& identifier, const std::span<const uint8_t>& data)
        : m_identifier(identifier)
        , m_data(data)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DataTaskIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class DataTaskDidCompleteWithError {
public:
    using Arguments = std::tuple<WebKit::DataTaskIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DataTaskDidCompleteWithError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DataTaskDidCompleteWithError(const WebKit::DataTaskIdentifier& identifier, const WebCore::ResourceError& error)
        : m_identifier(identifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DataTaskIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class OpenWindowFromServiceWorker {
public:
    using Arguments = std::tuple<PAL::SessionID, String, WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_OpenWindowFromServiceWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_OpenWindowFromServiceWorkerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::PageIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::PageIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::PageIdentifier>, IPC::Error>;
    OpenWindowFromServiceWorker(const PAL::SessionID& sessionID, const String& urlString, const WebCore::SecurityOriginData& serviceWorkerOrigin)
        : m_sessionID(sessionID)
        , m_urlString(urlString)
        , m_serviceWorkerOrigin(serviceWorkerOrigin)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_urlString;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerOrigin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_urlString;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_serviceWorkerOrigin;
};

class NavigateServiceWorkerClient {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::ScriptExecutionContextIdentifier, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_NavigateServiceWorkerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_NavigateServiceWorkerClientReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::PageIdentifier>, std::optional<WebCore::FrameIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::PageIdentifier>&&, std::optional<WebCore::FrameIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::PageIdentifier>, std::optional<WebCore::FrameIdentifier>>, IPC::Error>;
    NavigateServiceWorkerClient(const WebCore::FrameIdentifier& frameIdentifier, const WebCore::ScriptExecutionContextIdentifier& documentIdentifier, const URL& url)
        : m_frameIdentifier(frameIdentifier)
        , m_documentIdentifier(documentIdentifier)
        , m_url(url)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameIdentifier;
        encoder << m_documentIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameIdentifier;
    const WebCore::ScriptExecutionContextIdentifier& m_documentIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class ReportConsoleMessage {
public:
    using Arguments = std::tuple<PAL::SessionID, URL, WebCore::SecurityOriginData, JSC::MessageSource, JSC::MessageLevel, String, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ReportConsoleMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReportConsoleMessage(const PAL::SessionID& sessionID, const URL& scriptURL, const WebCore::SecurityOriginData& serviceWorkerOrigin, JSC::MessageSource messageSource, JSC::MessageLevel messageLevel, const String& message, uint64_t requestIdentifier)
        : m_sessionID(sessionID)
        , m_scriptURL(scriptURL)
        , m_serviceWorkerOrigin(serviceWorkerOrigin)
        , m_messageSource(messageSource)
        , m_messageLevel(messageLevel)
        , m_message(message)
        , m_requestIdentifier(requestIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scriptURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerOrigin;
        encoder << m_messageSource;
        encoder << m_messageLevel;
        encoder << m_message;
        encoder << m_requestIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scriptURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_serviceWorkerOrigin;
    JSC::MessageSource m_messageSource;
    JSC::MessageLevel m_messageLevel;
    const String& m_message;
    uint64_t m_requestIdentifier;
};

class CookiesDidChange {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_CookiesDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CookiesDidChange(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class DeleteWebsiteDataInWebProcessesForOrigin {
public:
    using Arguments = std::tuple<OptionSet<WebKit::WebsiteDataType>, WebCore::ClientOrigin, PAL::SessionID, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_DeleteWebsiteDataInWebProcessesForOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_DeleteWebsiteDataInWebProcessesForOriginReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteWebsiteDataInWebProcessesForOrigin(const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes, const WebCore::ClientOrigin& origin, const PAL::SessionID& sessionID, const WebKit::WebPageProxyIdentifier& webPageProxyID)
        : m_websiteDataTypes(websiteDataTypes)
        , m_origin(origin)
        , m_sessionID(sessionID)
        , m_webPageProxyID(webPageProxyID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
};

class ReloadExecutionContextsForOrigin {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin, PAL::SessionID, std::optional<WebCore::FrameIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ReloadExecutionContextsForOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessProxy_ReloadExecutionContextsForOriginReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ReloadExecutionContextsForOrigin(const WebCore::ClientOrigin& origin, const PAL::SessionID& sessionID, const std::optional<WebCore::FrameIdentifier>& triggeringFrame)
        : m_origin(origin)
        , m_sessionID(sessionID)
        , m_triggeringFrame(triggeringFrame)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_triggeringFrame;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_triggeringFrame;
};

#if USE(RUNNINGBOARD)
class WakeUpWebProcessForIPC {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_WakeUpWebProcessForIPC; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit WakeUpWebProcessForIPC(const WebCore::ProcessIdentifier& processIdentifier)
        : m_processIdentifier(processIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
};
#endif

#if ENABLE(NETWORK_ISSUE_REPORTING)
class ReportNetworkIssue {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, URL>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessProxy_ReportNetworkIssue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReportNetworkIssue(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const URL& requestURL)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_requestURL(requestURL)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_requestURL;
};
#endif

} // namespace NetworkProcessProxy
} // namespace Messages
