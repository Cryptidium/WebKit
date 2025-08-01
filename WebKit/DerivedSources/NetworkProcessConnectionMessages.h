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
#include <WebCore/RTCDataChannelIdentifier.h>
#include <WebCore/ShareableResource.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace JSC {
enum class MessageLevel : uint8_t;
enum class MessageSource : uint8_t;
}

namespace WebCore {
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
class ResourceError;
struct ResourceLoaderIdentifierType;
using ResourceLoaderIdentifier = AtomicObjectIdentifier<ResourceLoaderIdentifierType>;
class ResourceRequest;
class ResourceResponse;
enum class HTTPCookieAcceptPolicy : uint8_t;
struct MessagePortIdentifier;
}

namespace Messages {
namespace NetworkProcessConnection {

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
    return IPC::ReceiverName::NetworkProcessConnection;
}

#if ENABLE(SHAREABLE_RESOURCE)
class DidCacheResource {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest, WebCore::ShareableResourceHandle>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_DidCacheResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCacheResource(const WebCore::ResourceRequest& request, WebCore::ShareableResourceHandle&& resource)
        : m_request(request)
        , m_resource(WTFMove(resource))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        encoder << WTFMove(m_resource);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    WebCore::ShareableResourceHandle&& m_resource;
};
#endif

class DidFinishPingLoad {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier, WebCore::ResourceError, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_DidFinishPingLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishPingLoad(const WebCore::ResourceLoaderIdentifier& pingLoadIdentifier, const WebCore::ResourceError& error, const WebCore::ResourceResponse& response)
        : m_pingLoadIdentifier(pingLoadIdentifier)
        , m_error(error)
        , m_response(response)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pingLoadIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_pingLoadIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

class DidFinishPreconnection {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_DidFinishPreconnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishPreconnection(const WebCore::ResourceLoaderIdentifier& preconnectionIdentifier, const WebCore::ResourceError& error)
        : m_preconnectionIdentifier(preconnectionIdentifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_preconnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_preconnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class SetOnLineState {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_SetOnLineState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetOnLineState(bool isOnLine)
        : m_isOnLine(isOnLine)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isOnLine;
    }

private:
    bool m_isOnLine;
};

class CookieAcceptPolicyChanged {
public:
    using Arguments = std::tuple<WebCore::HTTPCookieAcceptPolicy>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_CookieAcceptPolicyChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CookieAcceptPolicyChanged(WebCore::HTTPCookieAcceptPolicy policy)
        : m_policy(policy)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_policy;
    }

private:
    WebCore::HTTPCookieAcceptPolicy m_policy;
};

class UpdateCachedCookiesEnabled {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_UpdateCachedCookiesEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateCachedCookiesEnabled()
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if HAVE(COOKIE_CHANGE_LISTENER_API)
class CookiesAdded {
public:
    using Arguments = std::tuple<String, Vector<WebCore::Cookie>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_CookiesAdded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CookiesAdded(const String& host, const Vector<WebCore::Cookie>& cookies)
        : m_host(host)
        , m_cookies(cookies)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_host;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookies;
    }

private:
    const String& m_host;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::Cookie>& m_cookies;
};
#endif

#if HAVE(COOKIE_CHANGE_LISTENER_API)
class CookiesDeleted {
public:
    using Arguments = std::tuple<String, Vector<WebCore::Cookie>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_CookiesDeleted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CookiesDeleted(const String& host, const Vector<WebCore::Cookie>& cookies)
        : m_host(host)
        , m_cookies(cookies)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_host;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookies;
    }

private:
    const String& m_host;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::Cookie>& m_cookies;
};
#endif

#if HAVE(COOKIE_CHANGE_LISTENER_API)
class AllCookiesDeleted {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_AllCookiesDeleted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AllCookiesDeleted()
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

#if ENABLE(WEB_RTC)
class ConnectToRTCDataChannelRemoteSource {
public:
    using Arguments = std::tuple<WebCore::RTCDataChannelIdentifier, WebCore::RTCDataChannelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_ConnectToRTCDataChannelRemoteSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkProcessConnection_ConnectToRTCDataChannelRemoteSourceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<bool>>;
    using Reply = CompletionHandler<void(std::optional<bool>&&)>;
    using Promise = WTF::NativePromise<std::optional<bool>, IPC::Error>;
    ConnectToRTCDataChannelRemoteSource(const WebCore::RTCDataChannelIdentifier& source, const WebCore::RTCDataChannelIdentifier& handler)
        : m_source(source)
        , m_handler(handler)
    {
        ASSERT(isInNetworkProcess());
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

class MessagesAvailableForPort {
public:
    using Arguments = std::tuple<WebCore::MessagePortIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_MessagesAvailableForPort; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MessagesAvailableForPort(const WebCore::MessagePortIdentifier& port)
        : m_port(port)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_port;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessagePortIdentifier& m_port;
};

class BroadcastConsoleMessage {
public:
    using Arguments = std::tuple<JSC::MessageSource, JSC::MessageLevel, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_BroadcastConsoleMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BroadcastConsoleMessage(JSC::MessageSource messageSource, JSC::MessageLevel messageLevel, const String& message)
        : m_messageSource(messageSource)
        , m_messageLevel(messageLevel)
        , m_message(message)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_messageSource;
        encoder << m_messageLevel;
        encoder << m_message;
    }

private:
    JSC::MessageSource m_messageSource;
    JSC::MessageLevel m_messageLevel;
    const String& m_message;
};

class LoadCancelledDownloadRedirectRequestInFrame {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest, WebCore::FrameIdentifier, WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkProcessConnection_LoadCancelledDownloadRedirectRequestInFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LoadCancelledDownloadRedirectRequestInFrame(const WebCore::ResourceRequest& request, const WebCore::FrameIdentifier& frameID, const WebCore::PageIdentifier& pageID)
        : m_request(request)
        , m_frameID(frameID)
        , m_pageID(pageID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
};

} // namespace NetworkProcessConnection
} // namespace Messages
