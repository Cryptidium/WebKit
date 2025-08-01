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
#include <span>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
class Exception;
struct WebTransportStreamIdentifierType;
using WebTransportStreamIdentifier = ObjectIdentifier<WebTransportStreamIdentifierType>;
}

namespace Messages {
namespace WebTransportSession {

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
    return IPC::ReceiverName::WebTransportSession;
}

class ReceiveDatagram {
public:
    using Arguments = std::tuple<std::span<const uint8_t>, bool, std::optional<WebCore::Exception>>;

    static IPC::MessageName name() { return IPC::MessageName::WebTransportSession_ReceiveDatagram; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReceiveDatagram(const std::span<const uint8_t>& datagram, bool withFin, const std::optional<WebCore::Exception>& exception)
        : m_datagram(datagram)
        , m_withFin(withFin)
        , m_exception(exception)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_datagram;
        encoder << m_withFin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_exception;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_datagram;
    bool m_withFin;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::Exception>& m_exception;
};

class ReceiveIncomingUnidirectionalStream {
public:
    using Arguments = std::tuple<WebCore::WebTransportStreamIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebTransportSession_ReceiveIncomingUnidirectionalStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReceiveIncomingUnidirectionalStream(const WebCore::WebTransportStreamIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebTransportStreamIdentifier& m_identifier;
};

class ReceiveBidirectionalStream {
public:
    using Arguments = std::tuple<WebCore::WebTransportStreamIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebTransportSession_ReceiveBidirectionalStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReceiveBidirectionalStream(const WebCore::WebTransportStreamIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebTransportStreamIdentifier& m_identifier;
};

class StreamReceiveBytes {
public:
    using Arguments = std::tuple<WebCore::WebTransportStreamIdentifier, std::span<const uint8_t>, bool, std::optional<WebCore::Exception>>;

    static IPC::MessageName name() { return IPC::MessageName::WebTransportSession_StreamReceiveBytes; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StreamReceiveBytes(const WebCore::WebTransportStreamIdentifier& identifier, const std::span<const uint8_t>& bytes, bool withFin, const std::optional<WebCore::Exception>& exception)
        : m_identifier(identifier)
        , m_bytes(bytes)
        , m_withFin(withFin)
        , m_exception(exception)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bytes;
        encoder << m_withFin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_exception;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebTransportStreamIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_bytes;
    bool m_withFin;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::Exception>& m_exception;
};

} // namespace WebTransportSession
} // namespace Messages
