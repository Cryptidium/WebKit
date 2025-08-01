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

namespace WebCore {
enum class PermissionQuerySource : uint8_t;
enum class PermissionState : uint8_t;
struct ClientOrigin;
struct PermissionDescriptor;
}

namespace WebKit {
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
}

namespace Messages {
namespace WebPermissionControllerProxy {

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
    return IPC::ReceiverName::WebPermissionControllerProxy;
}

class Query {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin, WebCore::PermissionDescriptor, std::optional<WebKit::WebPageProxyIdentifier>, WebCore::PermissionQuerySource>;

    static IPC::MessageName name() { return IPC::MessageName::WebPermissionControllerProxy_Query; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPermissionControllerProxy_QueryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::PermissionState>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::PermissionState>)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::PermissionState>, IPC::Error>;
    Query(const WebCore::ClientOrigin& origin, const WebCore::PermissionDescriptor& descriptor, const std::optional<WebKit::WebPageProxyIdentifier>& identifier, WebCore::PermissionQuerySource source)
        : m_origin(origin)
        , m_descriptor(descriptor)
        , m_identifier(identifier)
        , m_source(source)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_source;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PermissionDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_identifier;
    WebCore::PermissionQuerySource m_source;
};

} // namespace WebPermissionControllerProxy
} // namespace Messages
