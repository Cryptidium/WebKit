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
#include <WebCore/ShareableResource.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class FormDataReference;
class SharedBufferReference;
}

namespace WTF {
class UUID;
}

namespace WebCore {
class ContentFilterUnblockHandler;
class NetworkLoadMetrics;
class ResourceError;
class ResourceRequest;
class ResourceResponse;
class SubstituteData;
}

namespace WebKit {
enum class PrivateRelayed : bool;
}

namespace Messages {
namespace WebResourceLoader {

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
    return IPC::ReceiverName::WebResourceLoader;
}

class WillSendRequest {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest, IPC::FormDataReference, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_WillSendRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebResourceLoader_WillSendRequestReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ResourceRequest, bool>;
    using Reply = CompletionHandler<void(WebCore::ResourceRequest&&, bool)>;
    using Promise = WTF::NativePromise<std::tuple<WebCore::ResourceRequest, bool>, IPC::Error>;
    WillSendRequest(const WebCore::ResourceRequest& request, const IPC::FormDataReference& requestBody, const WebCore::ResourceResponse& redirectResponse)
        : m_request(request)
        , m_requestBody(requestBody)
        , m_redirectResponse(redirectResponse)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestBody;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectResponse;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::FormDataReference& m_requestBody;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_redirectResponse;
};

class SetWorkerStart {
public:
    using Arguments = std::tuple<MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_SetWorkerStart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetWorkerStart(const MonotonicTime& value)
        : m_value(value)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_value;
};

class DidSendData {
public:
    using Arguments = std::tuple<uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_DidSendData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidSendData(uint64_t bytesSent, uint64_t totalBytesToBeSent)
        : m_bytesSent(bytesSent)
        , m_totalBytesToBeSent(totalBytesToBeSent)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bytesSent;
        encoder << m_totalBytesToBeSent;
    }

private:
    uint64_t m_bytesSent;
    uint64_t m_totalBytesToBeSent;
};

class DidReceiveResponse {
public:
    using Arguments = std::tuple<WebCore::ResourceResponse, WebKit::PrivateRelayed, bool, std::optional<WebCore::NetworkLoadMetrics>>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_DidReceiveResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveResponse(const WebCore::ResourceResponse& response, WebKit::PrivateRelayed privateRelayed, bool needsContinueDidReceiveResponseMessage, const std::optional<WebCore::NetworkLoadMetrics>& optionalNetworkLoadMetrics)
        : m_response(response)
        , m_privateRelayed(privateRelayed)
        , m_needsContinueDidReceiveResponseMessage(needsContinueDidReceiveResponseMessage)
        , m_optionalNetworkLoadMetrics(optionalNetworkLoadMetrics)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        encoder << m_privateRelayed;
        encoder << m_needsContinueDidReceiveResponseMessage;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_optionalNetworkLoadMetrics;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    WebKit::PrivateRelayed m_privateRelayed;
    bool m_needsContinueDidReceiveResponseMessage;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NetworkLoadMetrics>& m_optionalNetworkLoadMetrics;
};

class DidReceiveData {
public:
    using Arguments = std::tuple<IPC::SharedBufferReference, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_DidReceiveData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveData(const IPC::SharedBufferReference& data, uint64_t bytesTransferredOverNetwork)
        : m_data(data)
        , m_bytesTransferredOverNetwork(bytesTransferredOverNetwork)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        encoder << m_bytesTransferredOverNetwork;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::SharedBufferReference& m_data;
    uint64_t m_bytesTransferredOverNetwork;
};

class DidFinishResourceLoad {
public:
    using Arguments = std::tuple<WebCore::NetworkLoadMetrics>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_DidFinishResourceLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFinishResourceLoad(const WebCore::NetworkLoadMetrics& networkLoadMetrics)
        : m_networkLoadMetrics(networkLoadMetrics)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_networkLoadMetrics;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NetworkLoadMetrics& m_networkLoadMetrics;
};

class DidFailResourceLoad {
public:
    using Arguments = std::tuple<WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_DidFailResourceLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFailResourceLoad(const WebCore::ResourceError& error)
        : m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class DidFailServiceWorkerLoad {
public:
    using Arguments = std::tuple<WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_DidFailServiceWorkerLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFailServiceWorkerLoad(const WebCore::ResourceError& error)
        : m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class ServiceWorkerDidNotHandle {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_ServiceWorkerDidNotHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ServiceWorkerDidNotHandle()
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class UpdateResultingClientIdentifier {
public:
    using Arguments = std::tuple<WTF::UUID, WTF::UUID>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_UpdateResultingClientIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateResultingClientIdentifier(const WTF::UUID& currentIdentifier, const WTF::UUID& newIdentifier)
        : m_currentIdentifier(currentIdentifier)
        , m_newIdentifier(newIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_currentIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_currentIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_newIdentifier;
};

class DidBlockAuthenticationChallenge {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_DidBlockAuthenticationChallenge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidBlockAuthenticationChallenge()
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StopLoadingAfterXFrameOptionsOrContentSecurityPolicyDenied {
public:
    using Arguments = std::tuple<WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_StopLoadingAfterXFrameOptionsOrContentSecurityPolicyDenied; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StopLoadingAfterXFrameOptionsOrContentSecurityPolicyDenied(const WebCore::ResourceResponse& response)
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

#if ENABLE(SHAREABLE_RESOURCE)
class DidReceiveResource {
public:
    using Arguments = std::tuple<WebCore::ShareableResourceHandle>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_DidReceiveResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveResource(WebCore::ShareableResourceHandle&& resource)
        : m_resource(WTFMove(resource))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_resource);
    }

private:
    WebCore::ShareableResourceHandle&& m_resource;
};
#endif

#if ENABLE(CONTENT_FILTERING)
class ContentFilterDidBlockLoad {
public:
    using Arguments = std::tuple<WebCore::ContentFilterUnblockHandler, String, WebCore::ResourceError, URL, WebCore::SubstituteData>;

    static IPC::MessageName name() { return IPC::MessageName::WebResourceLoader_ContentFilterDidBlockLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ContentFilterDidBlockLoad(const WebCore::ContentFilterUnblockHandler& unblockHandler, const String& unblockRequestDeniedScript, const WebCore::ResourceError& error, const URL& blockedPageURL, const WebCore::SubstituteData& substituteData)
        : m_unblockHandler(unblockHandler)
        , m_unblockRequestDeniedScript(unblockRequestDeniedScript)
        , m_error(error)
        , m_blockedPageURL(blockedPageURL)
        , m_substituteData(substituteData)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_unblockHandler;
        encoder << m_unblockRequestDeniedScript;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_blockedPageURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_substituteData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ContentFilterUnblockHandler& m_unblockHandler;
    const String& m_unblockRequestDeniedScript;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_blockedPageURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SubstituteData& m_substituteData;
};
#endif

} // namespace WebResourceLoader
} // namespace Messages
