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

#if ENABLE(MODEL_PROCESS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "LayerHostingContext.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace IPC {
class SharedFileHandle;
}

namespace WebCore {
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct ProcessIdentifierType;
using ProcessIdentifier = ObjectIdentifier<ProcessIdentifierType>;
}

namespace WebKit {
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
}

namespace Messages {
namespace ModelProcessProxy {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(!isInAuxiliaryProcess());
        }
    );
#endif
    return IPC::ReceiverName::ModelProcessProxy;
}

class TerminateWebProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessProxy_TerminateWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TerminateWebProcess(const WebCore::ProcessIdentifier& webProcessIdentifier)
        : m_webProcessIdentifier(webProcessIdentifier)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webProcessIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_webProcessIdentifier;
};

#if HAVE(VISIBILITY_PROPAGATION_VIEW)
class DidCreateContextForVisibilityPropagation {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier, WebKit::LayerHostingContextID>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessProxy_DidCreateContextForVisibilityPropagation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCreateContextForVisibilityPropagation(const WebKit::WebPageProxyIdentifier& pageProxyID, const WebCore::PageIdentifier& pageID, const WebKit::LayerHostingContextID& contextID)
        : m_pageProxyID(pageProxyID)
        , m_pageID(pageID)
        , m_contextID(contextID)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_contextID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    const WebKit::LayerHostingContextID& m_contextID;
};
#endif

class ProcessIsReadyToExit {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessProxy_ProcessIsReadyToExit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProcessIsReadyToExit()
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(VISION) && ENABLE(GPU_PROCESS)
class RequestSharedSimulationConnection {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessProxy_RequestSharedSimulationConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::ModelProcessProxy_RequestSharedSimulationConnectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::SharedFileHandle>>;
    using Reply = CompletionHandler<void(std::optional<IPC::SharedFileHandle>&&)>;
    using Promise = WTF::NativePromise<std::optional<IPC::SharedFileHandle>, IPC::Error>;
    explicit RequestSharedSimulationConnection(const WebCore::ProcessIdentifier& webProcessIdentifier)
        : m_webProcessIdentifier(webProcessIdentifier)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webProcessIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_webProcessIdentifier;
};
#endif

} // namespace ModelProcessProxy
} // namespace Messages

#endif // ENABLE(MODEL_PROCESS)
