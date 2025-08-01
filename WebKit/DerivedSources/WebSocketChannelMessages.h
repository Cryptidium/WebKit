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
#include <wtf/text/WTFString.h>

namespace WebCore {
class ResourceRequest;
class ResourceResponse;
}

namespace Messages {
namespace WebSocketChannel {

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
    return IPC::ReceiverName::WebSocketChannel;
}

class DidConnect {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSocketChannel_DidConnect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidConnect(const String& subprotocol, const String& extensions)
        : m_subprotocol(subprotocol)
        , m_extensions(extensions)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_subprotocol;
        encoder << m_extensions;
    }

private:
    const String& m_subprotocol;
    const String& m_extensions;
};

class DidClose {
public:
    using Arguments = std::tuple<unsigned short, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSocketChannel_DidClose; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidClose(const unsigned short& code, const String& reason)
        : m_code(code)
        , m_reason(reason)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_code;
        encoder << m_reason;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned short& m_code;
    const String& m_reason;
};

class DidReceiveText {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSocketChannel_DidReceiveText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveText(const String& message)
        : m_message(message)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
    }

private:
    const String& m_message;
};

class DidReceiveBinaryData {
public:
    using Arguments = std::tuple<std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSocketChannel_DidReceiveBinaryData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveBinaryData(const std::span<const uint8_t>& data)
        : m_data(data)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class DidReceiveMessageError {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSocketChannel_DidReceiveMessageError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveMessageError(const String& errorMessage)
        : m_errorMessage(errorMessage)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_errorMessage;
    }

private:
    const String& m_errorMessage;
};

class DidSendHandshakeRequest {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebSocketChannel_DidSendHandshakeRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidSendHandshakeRequest(const WebCore::ResourceRequest& request)
        : m_request(request)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
};

class DidReceiveHandshakeResponse {
public:
    using Arguments = std::tuple<WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebSocketChannel_DidReceiveHandshakeResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveHandshakeResponse(const WebCore::ResourceResponse& response)
        : m_response(response)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

} // namespace WebSocketChannel
} // namespace Messages
