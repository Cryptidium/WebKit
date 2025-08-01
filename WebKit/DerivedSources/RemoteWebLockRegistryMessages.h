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
#include <WebCore/ProcessQualified.h>
#include <WebCore/ScriptExecutionContextIdentifier.h>
#include <WebCore/WebLockIdentifier.h>
#include <wtf/Forward.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>


namespace Messages {
namespace RemoteWebLockRegistry {

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
    return IPC::ReceiverName::RemoteWebLockRegistry;
}

class DidCompleteLockRequest {
public:
    using Arguments = std::tuple<WebCore::WebLockIdentifier, WebCore::ScriptExecutionContextIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteWebLockRegistry_DidCompleteLockRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCompleteLockRequest(const WebCore::WebLockIdentifier& lockIdentifier, const WebCore::ScriptExecutionContextIdentifier& clientID, bool success)
        : m_lockIdentifier(lockIdentifier)
        , m_clientID(clientID)
        , m_success(success)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_lockIdentifier;
        encoder << m_clientID;
        encoder << m_success;
    }

private:
    const WebCore::WebLockIdentifier& m_lockIdentifier;
    const WebCore::ScriptExecutionContextIdentifier& m_clientID;
    bool m_success;
};

class DidStealLock {
public:
    using Arguments = std::tuple<WebCore::WebLockIdentifier, WebCore::ScriptExecutionContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteWebLockRegistry_DidStealLock; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStealLock(const WebCore::WebLockIdentifier& lockIdentifier, const WebCore::ScriptExecutionContextIdentifier& clientID)
        : m_lockIdentifier(lockIdentifier)
        , m_clientID(clientID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_lockIdentifier;
        encoder << m_clientID;
    }

private:
    const WebCore::WebLockIdentifier& m_lockIdentifier;
    const WebCore::ScriptExecutionContextIdentifier& m_clientID;
};

} // namespace RemoteWebLockRegistry
} // namespace Messages
