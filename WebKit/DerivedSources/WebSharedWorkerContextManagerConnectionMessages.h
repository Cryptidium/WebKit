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
#include <WebCore/TransferredMessagePort.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct SharedWorkerIdentifierType;
using SharedWorkerIdentifier = ObjectIdentifier<SharedWorkerIdentifierType>;
struct ClientOrigin;
struct WorkerFetchResult;
struct WorkerInitializationData;
struct WorkerOptions;
}

namespace WebKit {
struct WebPreferencesStore;
}

namespace Messages {
namespace WebSharedWorkerContextManagerConnection {

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
    return IPC::ReceiverName::WebSharedWorkerContextManagerConnection;
}

class LaunchSharedWorker {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin, WebCore::SharedWorkerIdentifier, WebCore::WorkerOptions, WebCore::WorkerFetchResult, WebCore::WorkerInitializationData>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_LaunchSharedWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LaunchSharedWorker(const WebCore::ClientOrigin& origin, const WebCore::SharedWorkerIdentifier& sharedWorkerIdentifier, const WebCore::WorkerOptions& workerOptions, const WebCore::WorkerFetchResult& workerFetchResult, const WebCore::WorkerInitializationData& workerInitializationData)
        : m_origin(origin)
        , m_sharedWorkerIdentifier(sharedWorkerIdentifier)
        , m_workerOptions(workerOptions)
        , m_workerFetchResult(workerFetchResult)
        , m_workerInitializationData(workerInitializationData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workerOptions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workerFetchResult;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workerInitializationData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerIdentifier& m_sharedWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WorkerOptions& m_workerOptions;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WorkerFetchResult& m_workerFetchResult;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WorkerInitializationData& m_workerInitializationData;
};

class PostConnectEvent {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerIdentifier, WebCore::TransferredMessagePort, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_PostConnectEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_PostConnectEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    PostConnectEvent(const WebCore::SharedWorkerIdentifier& sharedWorkerIdentifier, const WebCore::TransferredMessagePort& port, const String& sourceOrigin)
        : m_sharedWorkerIdentifier(sharedWorkerIdentifier)
        , m_port(port)
        , m_sourceOrigin(sourceOrigin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerIdentifier;
        encoder << m_port;
        encoder << m_sourceOrigin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerIdentifier& m_sharedWorkerIdentifier;
    const WebCore::TransferredMessagePort& m_port;
    const String& m_sourceOrigin;
};

class TerminateSharedWorker {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_TerminateSharedWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TerminateSharedWorker(const WebCore::SharedWorkerIdentifier& sharedWorkerIdentifier)
        : m_sharedWorkerIdentifier(sharedWorkerIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerIdentifier& m_sharedWorkerIdentifier;
};

class UpdatePreferencesStore {
public:
    using Arguments = std::tuple<WebKit::WebPreferencesStore>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_UpdatePreferencesStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdatePreferencesStore(const WebKit::WebPreferencesStore& store)
        : m_store(store)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_store;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPreferencesStore& m_store;
};

class SetUserAgent {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_SetUserAgent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUserAgent(const String& userAgent)
        : m_userAgent(userAgent)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_userAgent;
    }

private:
    const String& m_userAgent;
};

class Close {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_Close; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Close()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SuspendSharedWorker {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_SuspendSharedWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SuspendSharedWorker(const WebCore::SharedWorkerIdentifier& sharedWorkerIdentifier)
        : m_sharedWorkerIdentifier(sharedWorkerIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerIdentifier& m_sharedWorkerIdentifier;
};

class ResumeSharedWorker {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerContextManagerConnection_ResumeSharedWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ResumeSharedWorker(const WebCore::SharedWorkerIdentifier& sharedWorkerIdentifier)
        : m_sharedWorkerIdentifier(sharedWorkerIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerIdentifier& m_sharedWorkerIdentifier;
};

} // namespace WebSharedWorkerContextManagerConnection
} // namespace Messages
