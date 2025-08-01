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

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <WebCore/SharedMemory.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace IPC {
class SharedBufferReference;
}

namespace WebCore {
class NetworkLoadMetrics;
class ResourceError;
class ResourceRequest;
class ResourceResponse;
enum class ShouldContinuePolicyCheck : bool;
}

namespace WebKit {
struct RemoteMediaResourceIdentifierType;
using RemoteMediaResourceIdentifier = ObjectIdentifier<RemoteMediaResourceIdentifierType>;
}

namespace Messages {
namespace RemoteMediaResourceManager {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInGPUProcess());
        }
    );
#endif
    return IPC::ReceiverName::RemoteMediaResourceManager;
}

class ResponseReceived {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier, WebCore::ResourceResponse, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaResourceManager_ResponseReceived; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaResourceManager_ResponseReceivedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ShouldContinuePolicyCheck>;
    using Reply = CompletionHandler<void(WebCore::ShouldContinuePolicyCheck)>;
    using Promise = WTF::NativePromise<WebCore::ShouldContinuePolicyCheck, IPC::Error>;
    ResponseReceived(const WebKit::RemoteMediaResourceIdentifier& identifier, const WebCore::ResourceResponse& response, bool didPassAccessControlCheck)
        : m_identifier(identifier)
        , m_response(response)
        , m_didPassAccessControlCheck(didPassAccessControlCheck)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        encoder << m_didPassAccessControlCheck;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    bool m_didPassAccessControlCheck;
};

class RedirectReceived {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier, WebCore::ResourceRequest, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaResourceManager_RedirectReceived; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaResourceManager_RedirectReceivedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ResourceRequest>;
    using Reply = CompletionHandler<void(WebCore::ResourceRequest&&)>;
    using Promise = WTF::NativePromise<WebCore::ResourceRequest, IPC::Error>;
    RedirectReceived(const WebKit::RemoteMediaResourceIdentifier& identifier, const WebCore::ResourceRequest& request, const WebCore::ResourceResponse& response)
        : m_identifier(identifier)
        , m_request(request)
        , m_response(response)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

class DataSent {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaResourceManager_DataSent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DataSent(const WebKit::RemoteMediaResourceIdentifier& identifier, uint64_t bytesSent, uint64_t totalBytesToBeSent)
        : m_identifier(identifier)
        , m_bytesSent(bytesSent)
        , m_totalBytesToBeSent(totalBytesToBeSent)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_bytesSent;
        encoder << m_totalBytesToBeSent;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_identifier;
    uint64_t m_bytesSent;
    uint64_t m_totalBytesToBeSent;
};

class DataReceived {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier, IPC::SharedBufferReference>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaResourceManager_DataReceived; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaResourceManager_DataReceivedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::SharedMemory::Handle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::SharedMemory::Handle>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::SharedMemory::Handle>, IPC::Error>;
    DataReceived(const WebKit::RemoteMediaResourceIdentifier& identifier, const IPC::SharedBufferReference& data)
        : m_identifier(identifier)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::SharedBufferReference& m_data;
};

class AccessControlCheckFailed {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaResourceManager_AccessControlCheckFailed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AccessControlCheckFailed(const WebKit::RemoteMediaResourceIdentifier& identifier, const WebCore::ResourceError& error)
        : m_identifier(identifier)
        , m_error(error)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class LoadFailed {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaResourceManager_LoadFailed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LoadFailed(const WebKit::RemoteMediaResourceIdentifier& identifier, const WebCore::ResourceError& error)
        : m_identifier(identifier)
        , m_error(error)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class LoadFinished {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier, WebCore::NetworkLoadMetrics>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaResourceManager_LoadFinished; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LoadFinished(const WebKit::RemoteMediaResourceIdentifier& identifier, const WebCore::NetworkLoadMetrics& metrics)
        : m_identifier(identifier)
        , m_metrics(metrics)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_metrics;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NetworkLoadMetrics& m_metrics;
};

} // namespace RemoteMediaResourceManager
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
