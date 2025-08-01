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

#if ENABLE(WEBXR)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <WebCore/PlatformXR.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace PlatformXR {
struct FrameData;
struct RequestData;
}

namespace WebCore {
class SecurityOriginData;
}

namespace Messages {
namespace PlatformXRSystem {

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
    return IPC::ReceiverName::PlatformXRSystem;
}

class EnumerateImmersiveXRDevices {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_EnumerateImmersiveXRDevices; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PlatformXRSystem_EnumerateImmersiveXRDevicesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::XRDeviceInfo>>;
    using Reply = CompletionHandler<void(Vector<WebKit::XRDeviceInfo>&&)>;
    using Promise = WTF::NativePromise<Vector<WebKit::XRDeviceInfo>, IPC::Error>;
    EnumerateImmersiveXRDevices()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RequestPermissionOnSessionFeatures {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, PlatformXR::SessionMode, Vector<PlatformXR::SessionFeature>, Vector<PlatformXR::SessionFeature>, Vector<PlatformXR::SessionFeature>, Vector<PlatformXR::SessionFeature>, Vector<PlatformXR::SessionFeature>>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_RequestPermissionOnSessionFeatures; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PlatformXRSystem_RequestPermissionOnSessionFeaturesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<PlatformXR::SessionFeature>>>;
    using Reply = CompletionHandler<void(std::optional<Vector<PlatformXR::SessionFeature>>&&)>;
    using Promise = WTF::NativePromise<std::optional<Vector<PlatformXR::SessionFeature>>, IPC::Error>;
    RequestPermissionOnSessionFeatures(const WebCore::SecurityOriginData& origin, const PlatformXR::SessionMode& mode, const Vector<PlatformXR::SessionFeature>& granted, const Vector<PlatformXR::SessionFeature>& consentRequired, const Vector<PlatformXR::SessionFeature>& consentOptional, const Vector<PlatformXR::SessionFeature>& requiredFeaturesRequested, const Vector<PlatformXR::SessionFeature>& optionalFeaturesRequested)
        : m_origin(origin)
        , m_mode(mode)
        , m_granted(granted)
        , m_consentRequired(consentRequired)
        , m_consentOptional(consentOptional)
        , m_requiredFeaturesRequested(requiredFeaturesRequested)
        , m_optionalFeaturesRequested(optionalFeaturesRequested)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        encoder << m_mode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_granted;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_consentRequired;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_consentOptional;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requiredFeaturesRequested;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_optionalFeaturesRequested;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
    const PlatformXR::SessionMode& m_mode;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<PlatformXR::SessionFeature>& m_granted;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<PlatformXR::SessionFeature>& m_consentRequired;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<PlatformXR::SessionFeature>& m_consentOptional;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<PlatformXR::SessionFeature>& m_requiredFeaturesRequested;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<PlatformXR::SessionFeature>& m_optionalFeaturesRequested;
};

class InitializeTrackingAndRendering {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_InitializeTrackingAndRendering; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    InitializeTrackingAndRendering()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ShutDownTrackingAndRendering {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_ShutDownTrackingAndRendering; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShutDownTrackingAndRendering()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RequestFrame {
public:
    using Arguments = std::tuple<std::optional<PlatformXR::RequestData>>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_RequestFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::PlatformXRSystem_RequestFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<PlatformXR::FrameData>;
    using Reply = CompletionHandler<void(PlatformXR::FrameData&&)>;
    using Promise = WTF::NativePromise<PlatformXR::FrameData, IPC::Error>;
    explicit RequestFrame(const std::optional<PlatformXR::RequestData>& requestData)
        : m_requestData(requestData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<PlatformXR::RequestData>& m_requestData;
};

#if USE(OPENXR)
class CreateLayerProjection {
public:
    using Arguments = std::tuple<uint32_t, uint32_t, bool>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_CreateLayerProjection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateLayerProjection(uint32_t width, uint32_t height, bool alpha)
        : m_width(width)
        , m_height(height)
        , m_alpha(alpha)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_width;
        encoder << m_height;
        encoder << m_alpha;
    }

private:
    uint32_t m_width;
    uint32_t m_height;
    bool m_alpha;
};
#endif

#if USE(OPENXR)
class SubmitFrame {
public:
    using Arguments = std::tuple<Vector<WebKit::XRDeviceLayer>>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_SubmitFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SubmitFrame(const Vector<WebKit::XRDeviceLayer>& layers)
        : m_layers(layers)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_layers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::XRDeviceLayer>& m_layers;
};
#endif

#if !USE(OPENXR)
class SubmitFrame {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_SubmitFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SubmitFrame()
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

class DidCompleteShutdownTriggeredBySystem {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::PlatformXRSystem_DidCompleteShutdownTriggeredBySystem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCompleteShutdownTriggeredBySystem()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

} // namespace PlatformXRSystem
} // namespace Messages

#endif // ENABLE(WEBXR)
