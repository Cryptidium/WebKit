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

#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
struct RemoteCDMIdentifierType;
using RemoteCDMIdentifier = ObjectIdentifier<RemoteCDMIdentifierType>;
struct RemoteCDMInstanceIdentifierType;
using RemoteCDMInstanceIdentifier = ObjectIdentifier<RemoteCDMInstanceIdentifierType>;
struct RemoteCDMInstanceSessionIdentifierType;
using RemoteCDMInstanceSessionIdentifier = ObjectIdentifier<RemoteCDMInstanceSessionIdentifierType>;
struct RemoteCDMConfiguration;
}

namespace Messages {
namespace RemoteCDMFactoryProxy {

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
    return IPC::ReceiverName::RemoteCDMFactoryProxy;
}

class CreateCDM {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMFactoryProxy_CreateCDM; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::RemoteCDMIdentifier>, WebKit::RemoteCDMConfiguration>;
    using Reply = CompletionHandler<void(std::optional<WebKit::RemoteCDMIdentifier>&&, WebKit::RemoteCDMConfiguration&&)>;
    CreateCDM(const String& keySystem, const String& mediaKeysHashSalt)
        : m_keySystem(keySystem)
        , m_mediaKeysHashSalt(mediaKeysHashSalt)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_keySystem;
        encoder << m_mediaKeysHashSalt;
    }

private:
    const String& m_keySystem;
    const String& m_mediaKeysHashSalt;
};

class SupportsKeySystem {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMFactoryProxy_SupportsKeySystem; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit SupportsKeySystem(const String& keySystem)
        : m_keySystem(keySystem)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_keySystem;
    }

private:
    const String& m_keySystem;
};

class RemoveInstance {
public:
    using Arguments = std::tuple<WebKit::RemoteCDMInstanceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMFactoryProxy_RemoveInstance; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveInstance(const WebKit::RemoteCDMInstanceIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteCDMInstanceIdentifier& m_identifier;
};

class RemoveSession {
public:
    using Arguments = std::tuple<WebKit::RemoteCDMInstanceSessionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMFactoryProxy_RemoveSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveSession(const WebKit::RemoteCDMInstanceSessionIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteCDMInstanceSessionIdentifier& m_identifier;
};

} // namespace RemoteCDMFactoryProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
