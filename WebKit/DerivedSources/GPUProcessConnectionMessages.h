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

#if ENABLE(GPU_PROCESS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "GPUProcessConnectionInfo.h"
#include "MessageNames.h"
#include <WebCore/AudioSession.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
enum class AudioSessionCategory : uint8_t;
enum class AudioSessionRoutingArbitrationError : uint8_t;
enum class PlatformMediaSessionRemoteControlCommandType : uint8_t;
struct PlatformMediaSessionRemoteCommandArgument;
}

namespace WebKit {
struct AudioMediaStreamTrackRendererInternalUnitIdentifierType;
using AudioMediaStreamTrackRendererInternalUnitIdentifier = ObjectIdentifier<AudioMediaStreamTrackRendererInternalUnitIdentifierType>;
}

namespace Messages {
namespace GPUProcessConnection {

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
    return IPC::ReceiverName::GPUProcessConnection;
}

class DidInitialize {
public:
    using Arguments = std::tuple<std::optional<WebKit::GPUProcessConnectionInfo>>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessConnection_DidInitialize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidInitialize(const std::optional<WebKit::GPUProcessConnectionInfo>& info)
        : m_info(info)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::GPUProcessConnectionInfo>& m_info;
};

class DidReceiveRemoteCommand {
public:
    using Arguments = std::tuple<WebCore::PlatformMediaSessionRemoteControlCommandType, WebCore::PlatformMediaSessionRemoteCommandArgument>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessConnection_DidReceiveRemoteCommand; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveRemoteCommand(WebCore::PlatformMediaSessionRemoteControlCommandType type, const WebCore::PlatformMediaSessionRemoteCommandArgument& argument)
        : m_type(type)
        , m_argument(argument)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_argument;
    }

private:
    WebCore::PlatformMediaSessionRemoteControlCommandType m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PlatformMediaSessionRemoteCommandArgument& m_argument;
};

#if ENABLE(ROUTING_ARBITRATION)
class BeginRoutingArbitrationWithCategory {
public:
    using Arguments = std::tuple<WebCore::AudioSessionCategory>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessConnection_BeginRoutingArbitrationWithCategory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcessConnection_BeginRoutingArbitrationWithCategoryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::AudioSessionRoutingArbitrationError, WebCore::AudioSessionRoutingArbitrationClient::DefaultRouteChanged>;
    using Reply = CompletionHandler<void(WebCore::AudioSessionRoutingArbitrationError, WebCore::AudioSessionRoutingArbitrationClient::DefaultRouteChanged)>;
    using Promise = WTF::NativePromise<std::tuple<WebCore::AudioSessionRoutingArbitrationError, WebCore::AudioSessionRoutingArbitrationClient::DefaultRouteChanged>, IPC::Error>;
    explicit BeginRoutingArbitrationWithCategory(WebCore::AudioSessionCategory category)
        : m_category(category)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_category;
    }

private:
    WebCore::AudioSessionCategory m_category;
};
#endif

#if ENABLE(ROUTING_ARBITRATION)
class EndRoutingArbitration {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessConnection_EndRoutingArbitration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EndRoutingArbitration()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(MEDIA_STREAM) && PLATFORM(COCOA)
class ResetAudioMediaStreamTrackRendererInternalUnit {
public:
    using Arguments = std::tuple<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessConnection_ResetAudioMediaStreamTrackRendererInternalUnit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ResetAudioMediaStreamTrackRendererInternalUnit(const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& m_identifier;
};
#endif

} // namespace GPUProcessConnection
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
