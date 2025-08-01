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

#if ENABLE(GPU_PROCESS) && ENABLE(LEGACY_ENCRYPTED_MEDIA)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct MediaPlayerIdentifierType;
using MediaPlayerIdentifier = ObjectIdentifier<MediaPlayerIdentifierType>;
}

namespace WebKit {
struct RemoteLegacyCDMIdentifierType;
using RemoteLegacyCDMIdentifier = ObjectIdentifier<RemoteLegacyCDMIdentifierType>;
struct RemoteLegacyCDMSessionIdentifierType;
using RemoteLegacyCDMSessionIdentifier = ObjectIdentifier<RemoteLegacyCDMSessionIdentifierType>;
}

namespace Messages {
namespace RemoteLegacyCDMFactoryProxy {

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
    return IPC::ReceiverName::RemoteLegacyCDMFactoryProxy;
}

class CreateCDM {
public:
    using Arguments = std::tuple<String, std::optional<WebCore::MediaPlayerIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMFactoryProxy_CreateCDM; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::RemoteLegacyCDMIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::RemoteLegacyCDMIdentifier>&&)>;
    CreateCDM(const String& keySystem, const std::optional<WebCore::MediaPlayerIdentifier>& playerId)
        : m_keySystem(keySystem)
        , m_playerId(playerId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_keySystem;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_playerId;
    }

private:
    const String& m_keySystem;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::MediaPlayerIdentifier>& m_playerId;
};

class SupportsKeySystem {
public:
    using Arguments = std::tuple<String, std::optional<String>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMFactoryProxy_SupportsKeySystem; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    SupportsKeySystem(const String& keySystem, const std::optional<String>& mimeType)
        : m_keySystem(keySystem)
        , m_mimeType(mimeType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_keySystem;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mimeType;
    }

private:
    const String& m_keySystem;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_mimeType;
};

class RemoveSession {
public:
    using Arguments = std::tuple<WebKit::RemoteLegacyCDMSessionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMFactoryProxy_RemoveSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteLegacyCDMFactoryProxy_RemoveSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit RemoveSession(const WebKit::RemoteLegacyCDMSessionIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteLegacyCDMSessionIdentifier& m_identifier;
};

} // namespace RemoteLegacyCDMFactoryProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(LEGACY_ENCRYPTED_MEDIA)
