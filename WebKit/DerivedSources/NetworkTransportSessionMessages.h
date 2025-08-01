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
namespace NetworkTransportSession {

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
    return IPC::ReceiverName::NetworkTransportSession;
}

class SendDatagram {
public:
    using Arguments = std::tuple<std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkTransportSession_SendDatagram; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkTransportSession_SendDatagramReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::Exception>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::Exception>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::Exception>, IPC::Error>;
    explicit SendDatagram(const std::span<const uint8_t>& datagram)
        : m_datagram(datagram)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_datagram;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_datagram;
};

class CreateOutgoingUnidirectionalStream {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkTransportSession_CreateOutgoingUnidirectionalStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkTransportSession_CreateOutgoingUnidirectionalStreamReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::WebTransportStreamIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::WebTransportStreamIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::WebTransportStreamIdentifier>, IPC::Error>;
    CreateOutgoingUnidirectionalStream()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CreateBidirectionalStream {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkTransportSession_CreateBidirectionalStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkTransportSession_CreateBidirectionalStreamReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::WebTransportStreamIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::WebTransportStreamIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::WebTransportStreamIdentifier>, IPC::Error>;
    CreateBidirectionalStream()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StreamSendBytes {
public:
    using Arguments = std::tuple<WebCore::WebTransportStreamIdentifier, std::span<const uint8_t>, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkTransportSession_StreamSendBytes; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkTransportSession_StreamSendBytesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::Exception>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::Exception>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::Exception>, IPC::Error>;
    StreamSendBytes(const WebCore::WebTransportStreamIdentifier& identifier, const std::span<const uint8_t>& bytes, bool withFin)
        : m_identifier(identifier)
        , m_bytes(bytes)
        , m_withFin(withFin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bytes;
        encoder << m_withFin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebTransportStreamIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_bytes;
    bool m_withFin;
};

class CancelReceiveStream {
public:
    using Arguments = std::tuple<WebCore::WebTransportStreamIdentifier, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkTransportSession_CancelReceiveStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelReceiveStream(const WebCore::WebTransportStreamIdentifier& identifier, const std::optional<uint64_t>& errorCode)
        : m_identifier(identifier)
        , m_errorCode(errorCode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_errorCode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebTransportStreamIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_errorCode;
};

class CancelSendStream {
public:
    using Arguments = std::tuple<WebCore::WebTransportStreamIdentifier, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkTransportSession_CancelSendStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelSendStream(const WebCore::WebTransportStreamIdentifier& identifier, const std::optional<uint64_t>& errorCode)
        : m_identifier(identifier)
        , m_errorCode(errorCode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_errorCode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebTransportStreamIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_errorCode;
};

class DestroyStream {
public:
    using Arguments = std::tuple<WebCore::WebTransportStreamIdentifier, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkTransportSession_DestroyStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DestroyStream(const WebCore::WebTransportStreamIdentifier& identifier, const std::optional<uint64_t>& errorCode)
        : m_identifier(identifier)
        , m_errorCode(errorCode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_errorCode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebTransportStreamIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_errorCode;
};

class Terminate {
public:
    using Arguments = std::tuple<uint32_t, CString>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkTransportSession_Terminate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Terminate(uint32_t code, const CString& reason)
        : m_code(code)
        , m_reason(reason)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_code;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_reason;
    }

private:
    uint32_t m_code;
    SUPPRESS_FORWARD_DECL_MEMBER const CString& m_reason;
};

} // namespace NetworkTransportSession
} // namespace Messages
