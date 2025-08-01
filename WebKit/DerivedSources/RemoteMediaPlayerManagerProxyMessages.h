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

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct MediaPlayerClientIdentifierType;
using MediaPlayerClientIdentifier = ObjectIdentifier<MediaPlayerClientIdentifierType>;
struct MediaPlayerIdentifierType;
using MediaPlayerIdentifier = ObjectIdentifier<MediaPlayerIdentifierType>;
enum class MediaPlayerMediaEngineIdentifier : uint8_t;
enum class MediaPlayerSupportsType : uint8_t;
struct MediaEngineSupportParameters;
}

namespace WebKit {
struct RemoteMediaPlayerProxyConfiguration;
}

namespace Messages {
namespace RemoteMediaPlayerManagerProxy {

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
    return IPC::ReceiverName::RemoteMediaPlayerManagerProxy;
}

class CreateMediaPlayer {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerIdentifier, WebCore::MediaPlayerClientIdentifier, WebCore::MediaPlayerMediaEngineIdentifier, WebKit::RemoteMediaPlayerProxyConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerManagerProxy_CreateMediaPlayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateMediaPlayer(const WebCore::MediaPlayerIdentifier& identifier, const WebCore::MediaPlayerClientIdentifier& clientIdentifier, WebCore::MediaPlayerMediaEngineIdentifier remoteEngineIdentifier, const WebKit::RemoteMediaPlayerProxyConfiguration& proxyConfiguration)
        : m_identifier(identifier)
        , m_clientIdentifier(clientIdentifier)
        , m_remoteEngineIdentifier(remoteEngineIdentifier)
        , m_proxyConfiguration(proxyConfiguration)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientIdentifier;
        encoder << m_remoteEngineIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_proxyConfiguration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerClientIdentifier& m_clientIdentifier;
    WebCore::MediaPlayerMediaEngineIdentifier m_remoteEngineIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaPlayerProxyConfiguration& m_proxyConfiguration;
};

class DeleteMediaPlayer {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerManagerProxy_DeleteMediaPlayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DeleteMediaPlayer(const WebCore::MediaPlayerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerIdentifier& m_identifier;
};

class GetSupportedTypes {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerMediaEngineIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerManagerProxy_GetSupportedTypes; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    explicit GetSupportedTypes(WebCore::MediaPlayerMediaEngineIdentifier remoteEngineIdentifier)
        : m_remoteEngineIdentifier(remoteEngineIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_remoteEngineIdentifier;
    }

private:
    WebCore::MediaPlayerMediaEngineIdentifier m_remoteEngineIdentifier;
};

class SupportsTypeAndCodecs {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerMediaEngineIdentifier, WebCore::MediaEngineSupportParameters>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerManagerProxy_SupportsTypeAndCodecs; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::MediaPlayerSupportsType>;
    using Reply = CompletionHandler<void(WebCore::MediaPlayerSupportsType)>;
    SupportsTypeAndCodecs(WebCore::MediaPlayerMediaEngineIdentifier remoteEngineIdentifier, const WebCore::MediaEngineSupportParameters& type)
        : m_remoteEngineIdentifier(remoteEngineIdentifier)
        , m_type(type)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_remoteEngineIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_type;
    }

private:
    WebCore::MediaPlayerMediaEngineIdentifier m_remoteEngineIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaEngineSupportParameters& m_type;
};

class SupportsKeySystem {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerMediaEngineIdentifier, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerManagerProxy_SupportsKeySystem; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    SupportsKeySystem(WebCore::MediaPlayerMediaEngineIdentifier remoteEngineIdentifier, const String& keySystem, const String& mimeType)
        : m_remoteEngineIdentifier(remoteEngineIdentifier)
        , m_keySystem(keySystem)
        , m_mimeType(mimeType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_remoteEngineIdentifier;
        encoder << m_keySystem;
        encoder << m_mimeType;
    }

private:
    WebCore::MediaPlayerMediaEngineIdentifier m_remoteEngineIdentifier;
    const String& m_keySystem;
    const String& m_mimeType;
};

} // namespace RemoteMediaPlayerManagerProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
