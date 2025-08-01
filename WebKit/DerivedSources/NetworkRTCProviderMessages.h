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

#if USE(LIBWEBRTC)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include "RTCNetwork.h"
#include <span>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct LibWebRTCSocketIdentifierType;
using LibWebRTCSocketIdentifier = AtomicObjectIdentifier<LibWebRTCSocketIdentifierType>;
class RegistrableDomain;
}

namespace WebKit {
struct LibWebRTCResolverIdentifierType;
using LibWebRTCResolverIdentifier = AtomicObjectIdentifier<LibWebRTCResolverIdentifierType>;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
struct RTCPacketOptions;
}

namespace Messages {
namespace NetworkRTCProvider {

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
    return IPC::ReceiverName::NetworkRTCProvider;
}

class CreateUDPSocket {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, WebKit::WebRTCNetwork::SocketAddress, uint16_t, uint16_t, WebKit::WebPageProxyIdentifier, bool, bool, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkRTCProvider_CreateUDPSocket; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateUDPSocket(const WebCore::LibWebRTCSocketIdentifier& identifier, const WebKit::WebRTCNetwork::SocketAddress& localAddress, uint16_t minPort, uint16_t maxPort, const WebKit::WebPageProxyIdentifier& pageIdentifier, bool isFirstParty, bool isRelayDisabled, const WebCore::RegistrableDomain& domain)
        : m_identifier(identifier)
        , m_localAddress(localAddress)
        , m_minPort(minPort)
        , m_maxPort(maxPort)
        , m_pageIdentifier(pageIdentifier)
        , m_isFirstParty(isFirstParty)
        , m_isRelayDisabled(isRelayDisabled)
        , m_domain(domain)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_localAddress;
        encoder << m_minPort;
        encoder << m_maxPort;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        encoder << m_isFirstParty;
        encoder << m_isRelayDisabled;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebRTCNetwork::SocketAddress& m_localAddress;
    uint16_t m_minPort;
    uint16_t m_maxPort;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    bool m_isFirstParty;
    bool m_isRelayDisabled;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
};

class CreateClientTCPSocket {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, WebKit::WebRTCNetwork::SocketAddress, WebKit::WebRTCNetwork::SocketAddress, String, int, WebKit::WebPageProxyIdentifier, bool, bool, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkRTCProvider_CreateClientTCPSocket; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateClientTCPSocket(const WebCore::LibWebRTCSocketIdentifier& identifier, const WebKit::WebRTCNetwork::SocketAddress& localAddress, const WebKit::WebRTCNetwork::SocketAddress& remoteAddress, const String& userAgent, const int& options, const WebKit::WebPageProxyIdentifier& pageIdentifier, bool isFirstParty, bool isRelayDisabled, const WebCore::RegistrableDomain& domain)
        : m_identifier(identifier)
        , m_localAddress(localAddress)
        , m_remoteAddress(remoteAddress)
        , m_userAgent(userAgent)
        , m_options(options)
        , m_pageIdentifier(pageIdentifier)
        , m_isFirstParty(isFirstParty)
        , m_isRelayDisabled(isRelayDisabled)
        , m_domain(domain)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_localAddress;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remoteAddress;
        encoder << m_userAgent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        encoder << m_isFirstParty;
        encoder << m_isRelayDisabled;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebRTCNetwork::SocketAddress& m_localAddress;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebRTCNetwork::SocketAddress& m_remoteAddress;
    const String& m_userAgent;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_options;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    bool m_isFirstParty;
    bool m_isRelayDisabled;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
};

class CreateResolver {
public:
    using Arguments = std::tuple<WebKit::LibWebRTCResolverIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkRTCProvider_CreateResolver; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateResolver(const WebKit::LibWebRTCResolverIdentifier& identifier, const String& address)
        : m_identifier(identifier)
        , m_address(address)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_address;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::LibWebRTCResolverIdentifier& m_identifier;
    const String& m_address;
};

class StopResolver {
public:
    using Arguments = std::tuple<WebKit::LibWebRTCResolverIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkRTCProvider_StopResolver; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StopResolver(const WebKit::LibWebRTCResolverIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::LibWebRTCResolverIdentifier& m_identifier;
};

#if PLATFORM(COCOA)
class GetInterfaceName {
public:
    using Arguments = std::tuple<URL, WebKit::WebPageProxyIdentifier, bool, bool, WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkRTCProvider_GetInterfaceName; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkRTCProvider_GetInterfaceNameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    GetInterfaceName(const URL& url, const WebKit::WebPageProxyIdentifier& pageIdentifier, bool isFirstParty, bool isRelayDisabled, const WebCore::RegistrableDomain& domain)
        : m_url(url)
        , m_pageIdentifier(pageIdentifier)
        , m_isFirstParty(isFirstParty)
        , m_isRelayDisabled(isRelayDisabled)
        , m_domain(domain)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        encoder << m_isFirstParty;
        encoder << m_isRelayDisabled;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageIdentifier;
    bool m_isFirstParty;
    bool m_isRelayDisabled;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
};
#endif

class SendToSocket {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, std::span<const uint8_t>, WebKit::WebRTCNetwork::SocketAddress, WebKit::RTCPacketOptions>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkRTCProvider_SendToSocket; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SendToSocket(const WebCore::LibWebRTCSocketIdentifier& identifier, const std::span<const uint8_t>& data, const WebKit::WebRTCNetwork::SocketAddress& address, const WebKit::RTCPacketOptions& options)
        : m_identifier(identifier)
        , m_data(data)
        , m_address(address)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_address;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebRTCNetwork::SocketAddress& m_address;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RTCPacketOptions& m_options;
};

class CloseSocket {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkRTCProvider_CloseSocket; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CloseSocket(const WebCore::LibWebRTCSocketIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_identifier;
};

class SetSocketOption {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, int, int>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkRTCProvider_SetSocketOption; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetSocketOption(const WebCore::LibWebRTCSocketIdentifier& identifier, const int& option, const int& value)
        : m_identifier(identifier)
        , m_option(option)
        , m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_option;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_option;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_value;
};

} // namespace NetworkRTCProvider
} // namespace Messages

#endif // USE(LIBWEBRTC)
