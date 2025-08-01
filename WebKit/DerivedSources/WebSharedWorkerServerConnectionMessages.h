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
#include <WebCore/SharedWorkerObjectIdentifier.h>
#include <WebCore/TransferredMessagePort.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
struct SharedWorkerKey;
struct WorkerOptions;
}

namespace Messages {
namespace WebSharedWorkerServerConnection {

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
    return IPC::ReceiverName::WebSharedWorkerServerConnection;
}

class RequestSharedWorker {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerKey, WebCore::SharedWorkerObjectIdentifier, WebCore::TransferredMessagePort, WebCore::WorkerOptions>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerServerConnection_RequestSharedWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestSharedWorker(const WebCore::SharedWorkerKey& sharedWorkerKey, const WebCore::SharedWorkerObjectIdentifier& sharedWorkerObjectIdentifier, const WebCore::TransferredMessagePort& port, const WebCore::WorkerOptions& workerOptions)
        : m_sharedWorkerKey(sharedWorkerKey)
        , m_sharedWorkerObjectIdentifier(sharedWorkerObjectIdentifier)
        , m_port(port)
        , m_workerOptions(workerOptions)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerKey;
        encoder << m_sharedWorkerObjectIdentifier;
        encoder << m_port;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workerOptions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerKey& m_sharedWorkerKey;
    const WebCore::SharedWorkerObjectIdentifier& m_sharedWorkerObjectIdentifier;
    const WebCore::TransferredMessagePort& m_port;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WorkerOptions& m_workerOptions;
};

class SharedWorkerObjectIsGoingAway {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerKey, WebCore::SharedWorkerObjectIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerServerConnection_SharedWorkerObjectIsGoingAway; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SharedWorkerObjectIsGoingAway(const WebCore::SharedWorkerKey& sharedWorkerKey, const WebCore::SharedWorkerObjectIdentifier& sharedWorkerObjectIdentifier)
        : m_sharedWorkerKey(sharedWorkerKey)
        , m_sharedWorkerObjectIdentifier(sharedWorkerObjectIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerKey;
        encoder << m_sharedWorkerObjectIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerKey& m_sharedWorkerKey;
    const WebCore::SharedWorkerObjectIdentifier& m_sharedWorkerObjectIdentifier;
};

class SuspendForBackForwardCache {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerKey, WebCore::SharedWorkerObjectIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerServerConnection_SuspendForBackForwardCache; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SuspendForBackForwardCache(const WebCore::SharedWorkerKey& sharedWorkerKey, const WebCore::SharedWorkerObjectIdentifier& sharedWorkerObjectIdentifier)
        : m_sharedWorkerKey(sharedWorkerKey)
        , m_sharedWorkerObjectIdentifier(sharedWorkerObjectIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerKey;
        encoder << m_sharedWorkerObjectIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerKey& m_sharedWorkerKey;
    const WebCore::SharedWorkerObjectIdentifier& m_sharedWorkerObjectIdentifier;
};

class ResumeForBackForwardCache {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerKey, WebCore::SharedWorkerObjectIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerServerConnection_ResumeForBackForwardCache; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResumeForBackForwardCache(const WebCore::SharedWorkerKey& sharedWorkerKey, const WebCore::SharedWorkerObjectIdentifier& sharedWorkerObjectIdentifier)
        : m_sharedWorkerKey(sharedWorkerKey)
        , m_sharedWorkerObjectIdentifier(sharedWorkerObjectIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerKey;
        encoder << m_sharedWorkerObjectIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerKey& m_sharedWorkerKey;
    const WebCore::SharedWorkerObjectIdentifier& m_sharedWorkerObjectIdentifier;
};

} // namespace WebSharedWorkerServerConnection
} // namespace Messages
