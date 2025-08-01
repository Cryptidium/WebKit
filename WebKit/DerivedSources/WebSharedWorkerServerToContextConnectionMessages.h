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
#include <wtf/text/WTFString.h>

namespace WebCore {
struct SharedWorkerIdentifierType;
using SharedWorkerIdentifier = ObjectIdentifier<SharedWorkerIdentifierType>;
}

namespace Messages {
namespace WebSharedWorkerServerToContextConnection {

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
    return IPC::ReceiverName::WebSharedWorkerServerToContextConnection;
}

class PostErrorToWorkerObject {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerIdentifier, String, int, int, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerServerToContextConnection_PostErrorToWorkerObject; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostErrorToWorkerObject(const WebCore::SharedWorkerIdentifier& sharedWorkerIdentifier, const String& errorMessage, const int& lineNumber, const int& columnNumber, const String& sourceURL, bool isErrorEvent)
        : m_sharedWorkerIdentifier(sharedWorkerIdentifier)
        , m_errorMessage(errorMessage)
        , m_lineNumber(lineNumber)
        , m_columnNumber(columnNumber)
        , m_sourceURL(sourceURL)
        , m_isErrorEvent(isErrorEvent)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerIdentifier;
        encoder << m_errorMessage;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_columnNumber;
        encoder << m_sourceURL;
        encoder << m_isErrorEvent;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerIdentifier& m_sharedWorkerIdentifier;
    const String& m_errorMessage;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_lineNumber;
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_columnNumber;
    const String& m_sourceURL;
    bool m_isErrorEvent;
};

class SharedWorkerTerminated {
public:
    using Arguments = std::tuple<WebCore::SharedWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSharedWorkerServerToContextConnection_SharedWorkerTerminated; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SharedWorkerTerminated(const WebCore::SharedWorkerIdentifier& sharedWorkerIdentifier)
        : m_sharedWorkerIdentifier(sharedWorkerIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedWorkerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SharedWorkerIdentifier& m_sharedWorkerIdentifier;
};

} // namespace WebSharedWorkerServerToContextConnection
} // namespace Messages
