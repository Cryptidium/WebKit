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
}

namespace Messages {
namespace LibWebRTCNetwork {

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
    return IPC::ReceiverName::LibWebRTCNetwork;
}

class SignalReadPacket {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, std::span<const uint8_t>, WebKit::WebRTCNetwork::IPAddress, uint16_t, int64_t, WebKit::WebRTCNetwork::EcnMarking>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCNetwork_SignalReadPacket; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SignalReadPacket(const WebCore::LibWebRTCSocketIdentifier& socketIdentifier, const std::span<const uint8_t>& data, const WebKit::WebRTCNetwork::IPAddress& address, uint16_t port, int64_t timestamp, const WebKit::WebRTCNetwork::EcnMarking& ecn)
        : m_socketIdentifier(socketIdentifier)
        , m_data(data)
        , m_address(address)
        , m_port(port)
        , m_timestamp(timestamp)
        , m_ecn(ecn)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_socketIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_address;
        encoder << m_port;
        encoder << m_timestamp;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ecn;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_socketIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebRTCNetwork::IPAddress& m_address;
    uint16_t m_port;
    int64_t m_timestamp;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebRTCNetwork::EcnMarking& m_ecn;
};

class SignalSentPacket {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, int64_t, int64_t>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCNetwork_SignalSentPacket; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SignalSentPacket(const WebCore::LibWebRTCSocketIdentifier& socketIdentifier, int64_t rtcPacketID, int64_t timestamp)
        : m_socketIdentifier(socketIdentifier)
        , m_rtcPacketID(rtcPacketID)
        , m_timestamp(timestamp)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_socketIdentifier;
        encoder << m_rtcPacketID;
        encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_socketIdentifier;
    int64_t m_rtcPacketID;
    int64_t m_timestamp;
};

class SignalAddressReady {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, WebKit::WebRTCNetwork::SocketAddress>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCNetwork_SignalAddressReady; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SignalAddressReady(const WebCore::LibWebRTCSocketIdentifier& socketIdentifier, const WebKit::WebRTCNetwork::SocketAddress& address)
        : m_socketIdentifier(socketIdentifier)
        , m_address(address)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_socketIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_address;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_socketIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebRTCNetwork::SocketAddress& m_address;
};

class SignalConnect {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCNetwork_SignalConnect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SignalConnect(const WebCore::LibWebRTCSocketIdentifier& socketIdentifier)
        : m_socketIdentifier(socketIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_socketIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_socketIdentifier;
};

class SignalClose {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, int>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCNetwork_SignalClose; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SignalClose(const WebCore::LibWebRTCSocketIdentifier& socketIdentifier, const int& error)
        : m_socketIdentifier(socketIdentifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_socketIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_socketIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_error;
};

class SignalUsedInterface {
public:
    using Arguments = std::tuple<WebCore::LibWebRTCSocketIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCNetwork_SignalUsedInterface; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SignalUsedInterface(const WebCore::LibWebRTCSocketIdentifier& socketIdentifier, const String& interfaceName)
        : m_socketIdentifier(socketIdentifier)
        , m_interfaceName(interfaceName)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_socketIdentifier;
        encoder << m_interfaceName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LibWebRTCSocketIdentifier& m_socketIdentifier;
    const String& m_interfaceName;
};

} // namespace LibWebRTCNetwork
} // namespace Messages

#endif // USE(LIBWEBRTC)
