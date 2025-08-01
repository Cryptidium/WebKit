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
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
}

namespace WebKit {
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
}

namespace Messages {
namespace ModelConnectionToWebProcess {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInModelProcess());
        }
    );
#endif
    return IPC::ReceiverName::ModelConnectionToWebProcess;
}

#if HAVE(VISIBILITY_PROPAGATION_VIEW)
class CreateVisibilityPropagationContextForPage {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::ModelConnectionToWebProcess_CreateVisibilityPropagationContextForPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateVisibilityPropagationContextForPage(const WebKit::WebPageProxyIdentifier& pageProxyID, const WebCore::PageIdentifier& pageID, bool canShowWhileLocked)
        : m_pageProxyID(pageProxyID)
        , m_pageID(pageID)
        , m_canShowWhileLocked(canShowWhileLocked)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_canShowWhileLocked;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    bool m_canShowWhileLocked;
};
#endif

#if HAVE(VISIBILITY_PROPAGATION_VIEW)
class DestroyVisibilityPropagationContextForPage {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::ModelConnectionToWebProcess_DestroyVisibilityPropagationContextForPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DestroyVisibilityPropagationContextForPage(const WebKit::WebPageProxyIdentifier& pageProxyID, const WebCore::PageIdentifier& pageID)
        : m_pageProxyID(pageProxyID)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
};
#endif

class ConfigureLoggingChannel {
public:
    using Arguments = std::tuple<String, WTFLogChannelState, WTFLogLevel>;

    static IPC::MessageName name() { return IPC::MessageName::ModelConnectionToWebProcess_ConfigureLoggingChannel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ConfigureLoggingChannel(const String& channelName, WTFLogChannelState state, WTFLogLevel level)
        : m_channelName(channelName)
        , m_state(state)
        , m_level(level)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_channelName;
        encoder << m_state;
        encoder << m_level;
    }

private:
    const String& m_channelName;
    WTFLogChannelState m_state;
    WTFLogLevel m_level;
};

} // namespace ModelConnectionToWebProcess
} // namespace Messages

#endif // ENABLE(MODEL_PROCESS)
