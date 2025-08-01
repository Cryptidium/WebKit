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
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class ResourceError;
struct WorkerFetchResult;
struct WorkerInitializationData;
struct WorkerOptions;
}

namespace Messages {
namespace WebSharedWorkerObjectConnection {

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
    return IPC::ReceiverName::WebSharedWorkerObjectConnection;
}

class FetchScriptInClient {
public:
    using Arguments = std::tuple<URL, WebCore::SharedWorkerObjectIdentifier, WebCore::WorkerOptions>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerObjectConnection_FetchScriptInClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSharedWorkerObjectConnection_FetchScriptInClientReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::WorkerFetchResult, WebCore::WorkerInitializationData>;
    using Reply = CompletionHandler<void(WebCore::WorkerFetchResult&&, WebCore::WorkerInitializationData&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebCore::WorkerFetchResult, WebCore::WorkerInitializationData>, IPC::Error>;
    FetchScriptInClient(const URL& url, const WebCore::SharedWorkerObjectIdentifier& sharedWorkerObjectIdentifier, const WebCore::WorkerOptions& workerOptions)
        : m_url(url)
        , m_sharedWorkerObjectIdentifier(sharedWorkerObjectIdentifier)
        , m_workerOptions(workerOptions)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << m_sharedWorkerObjectIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_workerOptions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    const WebCore::SharedWorkerObjectIdentifier& m_sharedWorkerObjectIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WorkerOptions& m_workerOptions;
};

class NotifyWorkerObjectOfLoadCompletion {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerObjectIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerObjectConnection_NotifyWorkerObjectOfLoadCompletion; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyWorkerObjectOfLoadCompletion(const WebCore::SharedWorkerObjectIdentifier& sharedWorkerObjectIdentifier, const WebCore::ResourceError& error)
        : m_sharedWorkerObjectIdentifier(sharedWorkerObjectIdentifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sharedWorkerObjectIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    const WebCore::SharedWorkerObjectIdentifier& m_sharedWorkerObjectIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class PostErrorToWorkerObject {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerObjectIdentifier, String, int, int, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerObjectConnection_PostErrorToWorkerObject; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostErrorToWorkerObject(const WebCore::SharedWorkerObjectIdentifier& sharedWorkerObjectIdentifier, const String& errorMessage, const int& lineNumber, const int& columnNumber, const String& sourceURL, bool isErrorEvent)
        : m_sharedWorkerObjectIdentifier(sharedWorkerObjectIdentifier)
        , m_errorMessage(errorMessage)
        , m_lineNumber(lineNumber)
        , m_columnNumber(columnNumber)
        , m_sourceURL(sourceURL)
        , m_isErrorEvent(isErrorEvent)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sharedWorkerObjectIdentifier;
        encoder << m_errorMessage;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_columnNumber;
        encoder << m_sourceURL;
        encoder << m_isErrorEvent;
    }

private:
    const WebCore::SharedWorkerObjectIdentifier& m_sharedWorkerObjectIdentifier;
    const String& m_errorMessage;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_lineNumber;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_columnNumber;
    const String& m_sourceURL;
    bool m_isErrorEvent;
};

#if ENABLE(CONTENT_EXTENSIONS)
class ReportNetworkUsageToWorkerObject {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerObjectIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerObjectConnection_ReportNetworkUsageToWorkerObject; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReportNetworkUsageToWorkerObject(const WebCore::SharedWorkerObjectIdentifier& sharedWorkerObjectIdentifier, uint64_t bytesTransferredOverNetwork)
        : m_sharedWorkerObjectIdentifier(sharedWorkerObjectIdentifier)
        , m_bytesTransferredOverNetwork(bytesTransferredOverNetwork)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sharedWorkerObjectIdentifier;
        encoder << m_bytesTransferredOverNetwork;
    }

private:
    const WebCore::SharedWorkerObjectIdentifier& m_sharedWorkerObjectIdentifier;
    uint64_t m_bytesTransferredOverNetwork;
};
#endif

} // namespace WebSharedWorkerObjectConnection
} // namespace Messages
