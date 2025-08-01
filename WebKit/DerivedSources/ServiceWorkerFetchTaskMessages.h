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
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace IPC {
class FormDataReference;
class SharedBufferReference;
}

namespace WebCore {
class NetworkLoadMetrics;
class ResourceError;
class ResourceResponse;
}

namespace Messages {
namespace ServiceWorkerFetchTask {

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
    return IPC::ReceiverName::ServiceWorkerFetchTask;
}

class DidNotHandle {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_DidNotHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidNotHandle()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidFail {
public:
    using Arguments = std::tuple<WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_DidFail; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFail(const WebCore::ResourceError& error)
        : m_error(error)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class DidReceiveRedirectResponse {
public:
    using Arguments = std::tuple<WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_DidReceiveRedirectResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveRedirectResponse(const WebCore::ResourceResponse& response)
        : m_response(response)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

class DidReceiveResponse {
public:
    using Arguments = std::tuple<WebCore::ResourceResponse, bool>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_DidReceiveResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveResponse(const WebCore::ResourceResponse& response, bool needsContinueDidReceiveResponseMessage)
        : m_response(response)
        , m_needsContinueDidReceiveResponseMessage(needsContinueDidReceiveResponseMessage)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        encoder << m_needsContinueDidReceiveResponseMessage;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    bool m_needsContinueDidReceiveResponseMessage;
};

class DidReceiveData {
public:
    using Arguments = std::tuple<IPC::SharedBufferReference>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_DidReceiveData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveData(const IPC::SharedBufferReference& data)
        : m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::SharedBufferReference& m_data;
};

class DidReceiveFormData {
public:
    using Arguments = std::tuple<IPC::FormDataReference>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_DidReceiveFormData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveFormData(const IPC::FormDataReference& data)
        : m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::FormDataReference& m_data;
};

class DidFinish {
public:
    using Arguments = std::tuple<WebCore::NetworkLoadMetrics>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_DidFinish; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFinish(const WebCore::NetworkLoadMetrics& metrics)
        : m_metrics(metrics)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_metrics;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NetworkLoadMetrics& m_metrics;
};

class UsePreload {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_UsePreload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UsePreload()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class WorkerClosed {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ServiceWorkerFetchTask_WorkerClosed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WorkerClosed()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

} // namespace ServiceWorkerFetchTask
} // namespace Messages
