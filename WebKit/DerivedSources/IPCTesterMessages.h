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

#if ENABLE(IPC_TESTING_API)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "ConnectionHandle.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "StreamServerConnection.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct ExceptionData;
}

namespace WebKit {
struct IPCConnectionTesterIdentifierType;
using IPCConnectionTesterIdentifier = ObjectIdentifier<IPCConnectionTesterIdentifierType>;
struct IPCStreamTesterIdentifierType;
using IPCStreamTesterIdentifier = ObjectIdentifier<IPCStreamTesterIdentifierType>;
}

namespace Messages {
namespace IPCTester {

static inline IPC::ReceiverName messageReceiverName()
{
    return IPC::ReceiverName::IPCTester;
}

class StartMessageTesting {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_StartMessageTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StartMessageTesting(const String& driverName)
        : m_driverName(driverName)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_driverName;
    }

private:
    const String& m_driverName;
};

class StopMessageTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_StopMessageTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    StopMessageTesting()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CreateStreamTester {
public:
    using Arguments = std::tuple<WebKit::IPCStreamTesterIdentifier, IPC::StreamServerConnectionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_CreateStreamTester; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateStreamTester(const WebKit::IPCStreamTesterIdentifier& identifier, IPC::StreamServerConnectionHandle&& serverConnection)
        : m_identifier(identifier)
        , m_serverConnection(WTFMove(serverConnection))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << WTFMove(m_serverConnection);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::IPCStreamTesterIdentifier& m_identifier;
    IPC::StreamServerConnectionHandle&& m_serverConnection;
};

class ReleaseStreamTester {
public:
    using Arguments = std::tuple<WebKit::IPCStreamTesterIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_ReleaseStreamTester; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    explicit ReleaseStreamTester(const WebKit::IPCStreamTesterIdentifier& identifier)
        : m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::IPCStreamTesterIdentifier& m_identifier;
};

class CreateConnectionTester {
public:
    using Arguments = std::tuple<WebKit::IPCConnectionTesterIdentifier, IPC::ConnectionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_CreateConnectionTester; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateConnectionTester(const WebKit::IPCConnectionTesterIdentifier& identifier, IPC::ConnectionHandle&& connection)
        : m_identifier(identifier)
        , m_connection(WTFMove(connection))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << WTFMove(m_connection);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::IPCConnectionTesterIdentifier& m_identifier;
    IPC::ConnectionHandle&& m_connection;
};

class CreateConnectionTesterAndSendAsyncMessages {
public:
    using Arguments = std::tuple<WebKit::IPCConnectionTesterIdentifier, IPC::ConnectionHandle, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_CreateConnectionTesterAndSendAsyncMessages; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateConnectionTesterAndSendAsyncMessages(const WebKit::IPCConnectionTesterIdentifier& identifier, IPC::ConnectionHandle&& connection, uint32_t messageCount)
        : m_identifier(identifier)
        , m_connection(WTFMove(connection))
        , m_messageCount(messageCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << WTFMove(m_connection);
        encoder << m_messageCount;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::IPCConnectionTesterIdentifier& m_identifier;
    IPC::ConnectionHandle&& m_connection;
    uint32_t m_messageCount;
};

class ReleaseConnectionTester {
public:
    using Arguments = std::tuple<WebKit::IPCConnectionTesterIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_ReleaseConnectionTester; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    explicit ReleaseConnectionTester(const WebKit::IPCConnectionTesterIdentifier& identifier)
        : m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::IPCConnectionTesterIdentifier& m_identifier;
};

class SendSameSemaphoreBack {
public:
    using Arguments = std::tuple<IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_SendSameSemaphoreBack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendSameSemaphoreBack(const IPC::Semaphore& semaphore)
        : m_semaphore(semaphore)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_semaphore;
    }

private:
    const IPC::Semaphore& m_semaphore;
};

class SendSemaphoreBackAndSignalProtocol {
public:
    using Arguments = std::tuple<IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_SendSemaphoreBackAndSignalProtocol; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendSemaphoreBackAndSignalProtocol(const IPC::Semaphore& semaphore)
        : m_semaphore(semaphore)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_semaphore;
    }

private:
    const IPC::Semaphore& m_semaphore;
};

class AsyncPing {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_AsyncPing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::IPCTester_AsyncPingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    using Promise = WTF::NativePromise<uint32_t, IPC::Error>;
    explicit AsyncPing(uint32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    uint32_t m_value;
};

class SyncPing {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_SyncPing; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    explicit SyncPing(uint32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    uint32_t m_value;
};

class SyncPingEmptyReply {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_SyncPingEmptyReply; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    explicit SyncPingEmptyReply(uint32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    uint32_t m_value;
};

class SendAsyncMessageToReceiver {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_SendAsyncMessageToReceiver; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendAsyncMessageToReceiver(uint32_t arg0)
        : m_arg0(arg0)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_arg0;
    }

private:
    uint32_t m_arg0;
};

class AsyncOptionalExceptionData {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::IPCTester_AsyncOptionalExceptionData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::IPCTester_AsyncOptionalExceptionDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>, String>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&, String&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::ExceptionData>, String>, IPC::Error>;
    explicit AsyncOptionalExceptionData(bool sendEngaged)
        : m_sendEngaged(sendEngaged)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sendEngaged;
    }

private:
    bool m_sendEngaged;
};

} // namespace IPCTester
} // namespace Messages

#endif // ENABLE(IPC_TESTING_API)
