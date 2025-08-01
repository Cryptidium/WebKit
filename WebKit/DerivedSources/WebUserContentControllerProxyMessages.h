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
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
class JavaScriptEvaluationResult;
struct ScriptMessageHandlerIdentifierType;
using ScriptMessageHandlerIdentifier = ObjectIdentifier<ScriptMessageHandlerIdentifierType>;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
struct FrameInfoData;
}

namespace Messages {
namespace WebUserContentControllerProxy {

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
    return IPC::ReceiverName::WebUserContentControllerProxy;
}

class DidPostMessage {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::FrameInfoData, WebKit::ScriptMessageHandlerIdentifier, WebKit::JavaScriptEvaluationResult>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentControllerProxy_DidPostMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebUserContentControllerProxy_DidPostMessageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::JavaScriptEvaluationResult, String>>;
    using Reply = CompletionHandler<void(Expected<WebKit::JavaScriptEvaluationResult, String>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::JavaScriptEvaluationResult, String>, IPC::Error>;
    DidPostMessage(const WebKit::WebPageProxyIdentifier& pageID, const WebKit::FrameInfoData& frameInfoData, const WebKit::ScriptMessageHandlerIdentifier& messageHandlerID, const WebKit::JavaScriptEvaluationResult& message)
        : m_pageID(pageID)
        , m_frameInfoData(frameInfoData)
        , m_messageHandlerID(messageHandlerID)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfoData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_messageHandlerID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfoData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ScriptMessageHandlerIdentifier& m_messageHandlerID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::JavaScriptEvaluationResult& m_message;
};

} // namespace WebUserContentControllerProxy
} // namespace Messages
