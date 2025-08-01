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

namespace WebCore {
struct ModelPlayerIdentifierType;
using ModelPlayerIdentifier = ObjectIdentifier<ModelPlayerIdentifierType>;
}

namespace WebKit {
struct ModelProcessConnectionInfo;
}

namespace Messages {
namespace ModelProcessConnection {

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
    return IPC::ReceiverName::ModelProcessConnection;
}

class DidInitialize {
public:
    using Arguments = std::tuple<std::optional<WebKit::ModelProcessConnectionInfo>>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessConnection_DidInitialize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidInitialize(const std::optional<WebKit::ModelProcessConnectionInfo>& info)
        : m_info(info)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::ModelProcessConnectionInfo>& m_info;
};

class DidUnloadModelPlayer {
public:
    using Arguments = std::tuple<WebCore::ModelPlayerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessConnection_DidUnloadModelPlayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidUnloadModelPlayer(const WebCore::ModelPlayerIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ModelPlayerIdentifier& m_identifier;
};

} // namespace ModelProcessConnection
} // namespace Messages

#endif // ENABLE(MODEL_PROCESS)
