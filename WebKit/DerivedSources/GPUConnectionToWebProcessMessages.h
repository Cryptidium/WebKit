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
#include "MessageNames.h"
#include "StreamServerConnection.h"
#if USE(GRAPHICS_LAYER_WC)
#include "WCLayerTreeHostIdentifier.h"
#endif
#include <WebCore/GraphicsContextGLAttributes.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class FloatRect;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct NowPlayingInfo;
}

namespace WebKit {
struct GraphicsContextGLIdentifierType;
using GraphicsContextGLIdentifier = AtomicObjectIdentifier<GraphicsContextGLIdentifierType>;
struct RemoteAudioHardwareListenerIdentifierType;
using RemoteAudioHardwareListenerIdentifier = ObjectIdentifier<RemoteAudioHardwareListenerIdentifierType>;
struct RemoteRemoteCommandListenerIdentifierType;
using RemoteRemoteCommandListenerIdentifier = ObjectIdentifier<RemoteRemoteCommandListenerIdentifierType>;
struct RenderingBackendIdentifierType;
using RenderingBackendIdentifier = AtomicObjectIdentifier<RenderingBackendIdentifierType>;
struct SampleBufferDisplayLayerIdentifierType;
using SampleBufferDisplayLayerIdentifier = ObjectIdentifier<SampleBufferDisplayLayerIdentifierType>;
struct WebGPUIdentifierType;
using WebGPUIdentifier = AtomicObjectIdentifier<WebGPUIdentifierType>;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
struct MediaOverridesForTesting;
struct RemoteAudioSessionConfiguration;
}

namespace Messages {
namespace GPUConnectionToWebProcess {

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
    return IPC::ReceiverName::GPUConnectionToWebProcess;
}

class CreateRenderingBackend {
public:
    using Arguments = std::tuple<WebKit::RenderingBackendIdentifier, IPC::StreamServerConnectionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_CreateRenderingBackend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateRenderingBackend(const WebKit::RenderingBackendIdentifier& renderingBackendIdentifier, IPC::StreamServerConnectionHandle&& connectionHandle)
        : m_renderingBackendIdentifier(renderingBackendIdentifier)
        , m_connectionHandle(WTFMove(connectionHandle))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderingBackendIdentifier;
        encoder << WTFMove(m_connectionHandle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RenderingBackendIdentifier& m_renderingBackendIdentifier;
    IPC::StreamServerConnectionHandle&& m_connectionHandle;
};

class ReleaseRenderingBackend {
public:
    using Arguments = std::tuple<WebKit::RenderingBackendIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_ReleaseRenderingBackend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseRenderingBackend(const WebKit::RenderingBackendIdentifier& renderingBackendIdentifier)
        : m_renderingBackendIdentifier(renderingBackendIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderingBackendIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RenderingBackendIdentifier& m_renderingBackendIdentifier;
};

#if ENABLE(WEBGL)
class CreateGraphicsContextGL {
public:
    using Arguments = std::tuple<WebKit::GraphicsContextGLIdentifier, WebCore::GraphicsContextGLAttributes, WebKit::RenderingBackendIdentifier, IPC::StreamServerConnectionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_CreateGraphicsContextGL; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateGraphicsContextGL(const WebKit::GraphicsContextGLIdentifier& identifier, const WebCore::GraphicsContextGLAttributes& attributes, const WebKit::RenderingBackendIdentifier& renderingBackendIdentifier, IPC::StreamServerConnectionHandle&& serverConnection)
        : m_identifier(identifier)
        , m_attributes(attributes)
        , m_renderingBackendIdentifier(renderingBackendIdentifier)
        , m_serverConnection(WTFMove(serverConnection))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_attributes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderingBackendIdentifier;
        encoder << WTFMove(m_serverConnection);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::GraphicsContextGLIdentifier& m_identifier;
    const WebCore::GraphicsContextGLAttributes& m_attributes;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RenderingBackendIdentifier& m_renderingBackendIdentifier;
    IPC::StreamServerConnectionHandle&& m_serverConnection;
};
#endif

#if ENABLE(WEBGL)
class ReleaseGraphicsContextGL {
public:
    using Arguments = std::tuple<WebKit::GraphicsContextGLIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_ReleaseGraphicsContextGL; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseGraphicsContextGL(const WebKit::GraphicsContextGLIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::GraphicsContextGLIdentifier& m_identifier;
};
#endif

class CreateGPU {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebKit::RenderingBackendIdentifier, IPC::StreamServerConnectionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_CreateGPU; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateGPU(const WebKit::WebGPUIdentifier& identifier, const WebKit::RenderingBackendIdentifier& renderingBackendIdentifier, IPC::StreamServerConnectionHandle&& serverConnection)
        : m_identifier(identifier)
        , m_renderingBackendIdentifier(renderingBackendIdentifier)
        , m_serverConnection(WTFMove(serverConnection))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderingBackendIdentifier;
        encoder << WTFMove(m_serverConnection);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RenderingBackendIdentifier& m_renderingBackendIdentifier;
    IPC::StreamServerConnectionHandle&& m_serverConnection;
};

class ReleaseGPU {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_ReleaseGPU; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseGPU(const WebKit::WebGPUIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class ClearNowPlayingInfo {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_ClearNowPlayingInfo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearNowPlayingInfo()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetNowPlayingInfo {
public:
    using Arguments = std::tuple<WebCore::NowPlayingInfo>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_SetNowPlayingInfo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetNowPlayingInfo(const WebCore::NowPlayingInfo& nowPlayingInfo)
        : m_nowPlayingInfo(nowPlayingInfo)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nowPlayingInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NowPlayingInfo& m_nowPlayingInfo;
};

#if USE(AUDIO_SESSION)
class EnsureAudioSession {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_EnsureAudioSession; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::RemoteAudioSessionConfiguration>;
    using Reply = CompletionHandler<void(WebKit::RemoteAudioSessionConfiguration&&)>;
    EnsureAudioSession()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class EnsureMediaSessionHelper {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_EnsureMediaSessionHelper; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnsureMediaSessionHelper()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if HAVE(VISIBILITY_PROPAGATION_VIEW)
class CreateVisibilityPropagationContextForPage {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_CreateVisibilityPropagationContextForPage; }
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

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_DestroyVisibilityPropagationContextForPage; }
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

class SetMediaOverridesForTesting {
public:
    using Arguments = std::tuple<WebKit::MediaOverridesForTesting>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_SetMediaOverridesForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMediaOverridesForTesting(const WebKit::MediaOverridesForTesting& configuration)
        : m_configuration(configuration)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MediaOverridesForTesting& m_configuration;
};

class CreateAudioHardwareListener {
public:
    using Arguments = std::tuple<WebKit::RemoteAudioHardwareListenerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_CreateAudioHardwareListener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CreateAudioHardwareListener(const WebKit::RemoteAudioHardwareListenerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteAudioHardwareListenerIdentifier& m_identifier;
};

class ReleaseAudioHardwareListener {
public:
    using Arguments = std::tuple<WebKit::RemoteAudioHardwareListenerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_ReleaseAudioHardwareListener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseAudioHardwareListener(const WebKit::RemoteAudioHardwareListenerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteAudioHardwareListenerIdentifier& m_identifier;
};

class CreateRemoteCommandListener {
public:
    using Arguments = std::tuple<WebKit::RemoteRemoteCommandListenerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_CreateRemoteCommandListener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CreateRemoteCommandListener(const WebKit::RemoteRemoteCommandListenerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteRemoteCommandListenerIdentifier& m_identifier;
};

class ReleaseRemoteCommandListener {
public:
    using Arguments = std::tuple<WebKit::RemoteRemoteCommandListenerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_ReleaseRemoteCommandListener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseRemoteCommandListener(const WebKit::RemoteRemoteCommandListenerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteRemoteCommandListenerIdentifier& m_identifier;
};

class ConfigureLoggingChannel {
public:
    using Arguments = std::tuple<String, WTFLogChannelState, WTFLogLevel>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_ConfigureLoggingChannel; }
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

#if USE(GRAPHICS_LAYER_WC)
class CreateWCLayerTreeHost {
public:
    using Arguments = std::tuple<WebKit::WCLayerTreeHostIdentifier, uint64_t, bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_CreateWCLayerTreeHost; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateWCLayerTreeHost(const WebKit::WCLayerTreeHostIdentifier& identifier, uint64_t nativeWindow, bool usesOffscreenRendering)
        : m_identifier(identifier)
        , m_nativeWindow(nativeWindow)
        , m_usesOffscreenRendering(usesOffscreenRendering)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        encoder << m_nativeWindow;
        encoder << m_usesOffscreenRendering;
    }

private:
    const WebKit::WCLayerTreeHostIdentifier& m_identifier;
    uint64_t m_nativeWindow;
    bool m_usesOffscreenRendering;
};
#endif

#if USE(GRAPHICS_LAYER_WC)
class ReleaseWCLayerTreeHost {
public:
    using Arguments = std::tuple<WebKit::WCLayerTreeHostIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_ReleaseWCLayerTreeHost; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseWCLayerTreeHost(const WebKit::WCLayerTreeHostIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
    }

private:
    const WebKit::WCLayerTreeHostIdentifier& m_identifier;
};
#endif

#if ENABLE(MEDIA_SOURCE)
class EnableMockMediaSource {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_EnableMockMediaSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnableMockMediaSource()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
class UpdateSampleBufferDisplayLayerBoundsAndPosition {
public:
    using Arguments = std::tuple<WebKit::SampleBufferDisplayLayerIdentifier, WebCore::FloatRect, std::optional<MachSendRightAnnotated>>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_UpdateSampleBufferDisplayLayerBoundsAndPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateSampleBufferDisplayLayerBoundsAndPosition(const WebKit::SampleBufferDisplayLayerIdentifier& identifier, const WebCore::FloatRect& bounds, const std::optional<MachSendRightAnnotated>& fence)
        : m_identifier(identifier)
        , m_bounds(bounds)
        , m_fence(fence)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bounds;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fence;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::SampleBufferDisplayLayerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_bounds;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<MachSendRightAnnotated>& m_fence;
};
#endif

#if ENABLE(EXTENSION_CAPABILITIES)
class SetMediaEnvironment {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::GPUConnectionToWebProcess_SetMediaEnvironment; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetMediaEnvironment(const WebCore::PageIdentifier& pageIdentifier, const String& mediaEnvironment)
        : m_pageIdentifier(pageIdentifier)
        , m_mediaEnvironment(mediaEnvironment)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        encoder << m_mediaEnvironment;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageIdentifier;
    const String& m_mediaEnvironment;
};
#endif

} // namespace GPUConnectionToWebProcess
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
