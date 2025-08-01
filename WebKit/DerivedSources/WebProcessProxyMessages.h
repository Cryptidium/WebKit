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
#include "ConnectionHandle.h"
#include "DisplayLinkObserverID.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "ModelProcessConnectionParameters.h"
#include "StreamServerConnection.h"
#include <WebCore/UserGestureTokenIdentifier.h>
#include <wtf/Forward.h>
#include <wtf/MemoryPressureHandler.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
class RegistrableDomain;
class SecurityOriginData;
struct ServiceWorkerIdentifierType;
using ServiceWorkerIdentifier = AtomicObjectIdentifier<ServiceWorkerIdentifierType>;
enum class ServiceWorkerIsInspectable : bool;
enum class CaptionUserPreferencesDisplayMode : uint8_t;
struct CryptoKeyData;
struct PrewarmInformation;
struct WrappedCryptoKey;
}

namespace WebKit {
struct GPUProcessConnectionIdentifierType;
using GPUProcessConnectionIdentifier = AtomicObjectIdentifier<GPUProcessConnectionIdentifierType>;
struct LogStreamIdentifierType;
using LogStreamIdentifier = AtomicObjectIdentifier<LogStreamIdentifierType>;
struct CoreIPCAuditToken;
struct NetworkProcessConnectionInfo;
struct UserMessage;
}

namespace Messages {
namespace WebProcessProxy {

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
    return IPC::ReceiverName::WebProcessProxy;
}

class DidDestroyUserGestureToken {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, WebCore::UserGestureTokenIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DidDestroyUserGestureToken; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidDestroyUserGestureToken(const WebCore::PageIdentifier& pageID, const WebCore::UserGestureTokenIdentifier& userGestureTokenID)
        : m_pageID(pageID)
        , m_userGestureTokenID(userGestureTokenID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_userGestureTokenID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    const WebCore::UserGestureTokenIdentifier& m_userGestureTokenID;
};

class ShouldTerminate {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_ShouldTerminate; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    ShouldTerminate()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class EnableSuddenTermination {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_EnableSuddenTermination; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnableSuddenTermination()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DisableSuddenTermination {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DisableSuddenTermination; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DisableSuddenTermination()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetNetworkProcessConnection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_GetNetworkProcessConnection; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::NetworkProcessConnectionInfo>;
    using Reply = CompletionHandler<void(WebKit::NetworkProcessConnectionInfo&&)>;
    GetNetworkProcessConnection()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class WaitForSharedPreferencesForWebProcessToSync {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_WaitForSharedPreferencesForWebProcessToSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit WaitForSharedPreferencesForWebProcessToSync(uint64_t sharedPreferencesVersion)
        : m_sharedPreferencesVersion(sharedPreferencesVersion)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sharedPreferencesVersion;
    }

private:
    uint64_t m_sharedPreferencesVersion;
};

#if ENABLE(GPU_PROCESS)
class CreateGPUProcessConnection {
public:
    using Arguments = std::tuple<WebKit::GPUProcessConnectionIdentifier, IPC::ConnectionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_CreateGPUProcessConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateGPUProcessConnection(const WebKit::GPUProcessConnectionIdentifier& identifier, IPC::ConnectionHandle&& connectionHandle)
        : m_identifier(identifier)
        , m_connectionHandle(WTFMove(connectionHandle))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << WTFMove(m_connectionHandle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::GPUProcessConnectionIdentifier& m_identifier;
    IPC::ConnectionHandle&& m_connectionHandle;
};
#endif

#if ENABLE(GPU_PROCESS)
class GPUProcessConnectionDidBecomeUnresponsive {
public:
    using Arguments = std::tuple<WebKit::GPUProcessConnectionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_GPUProcessConnectionDidBecomeUnresponsive; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit GPUProcessConnectionDidBecomeUnresponsive(const WebKit::GPUProcessConnectionIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::GPUProcessConnectionIdentifier& m_identifier;
};
#endif

#if ENABLE(MODEL_PROCESS)
class CreateModelProcessConnection {
public:
    using Arguments = std::tuple<IPC::ConnectionHandle, WebKit::ModelProcessConnectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_CreateModelProcessConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateModelProcessConnection(IPC::ConnectionHandle&& connectionIdentifier, WebKit::ModelProcessConnectionParameters&& parameters)
        : m_connectionIdentifier(WTFMove(connectionIdentifier))
        , m_parameters(WTFMove(parameters))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_connectionIdentifier);
        encoder << WTFMove(m_parameters);
    }

private:
    IPC::ConnectionHandle&& m_connectionIdentifier;
    WebKit::ModelProcessConnectionParameters&& m_parameters;
};
#endif

class DidExceedActiveMemoryLimit {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DidExceedActiveMemoryLimit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidExceedActiveMemoryLimit()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidExceedInactiveMemoryLimit {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DidExceedInactiveMemoryLimit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidExceedInactiveMemoryLimit()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidExceedMemoryFootprintThreshold {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DidExceedMemoryFootprintThreshold; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidExceedMemoryFootprintThreshold(uint64_t footprint)
        : m_footprint(footprint)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_footprint;
    }

private:
    uint64_t m_footprint;
};

class DidExceedCPULimit {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DidExceedCPULimit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidExceedCPULimit()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StopResponsivenessTimer {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_StopResponsivenessTimer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopResponsivenessTimer()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidReceiveBackgroundResponsivenessPing {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DidReceiveBackgroundResponsivenessPing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveBackgroundResponsivenessPing()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class MemoryPressureStatusChanged {
public:
    using Arguments = std::tuple<WTF::SystemMemoryPressureStatus>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_MemoryPressureStatusChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MemoryPressureStatusChanged(const WTF::SystemMemoryPressureStatus& status)
        : m_status(status)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_status;
    }

private:
    const WTF::SystemMemoryPressureStatus& m_status;
};

class DidCollectPrewarmInformation {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain, WebCore::PrewarmInformation>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DidCollectPrewarmInformation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCollectPrewarmInformation(const WebCore::RegistrableDomain& domain, const WebCore::PrewarmInformation& prewarmInformation)
        : m_domain(domain)
        , m_prewarmInformation(prewarmInformation)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_prewarmInformation;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_domain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PrewarmInformation& m_prewarmInformation;
};

#if PLATFORM(COCOA)
class CacheMediaMIMETypes {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_CacheMediaMIMETypes; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CacheMediaMIMETypes(const Vector<String>& types)
        : m_types(types)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_types;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_types;
};
#endif

#if HAVE(DISPLAY_LINK)
class StartDisplayLink {
public:
    using Arguments = std::tuple<WebKit::DisplayLinkObserverID, uint32_t, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_StartDisplayLink; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartDisplayLink(const WebKit::DisplayLinkObserverID& observerID, uint32_t displayID, const unsigned& preferredFramesPerSecond)
        : m_observerID(observerID)
        , m_displayID(displayID)
        , m_preferredFramesPerSecond(preferredFramesPerSecond)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_observerID;
        encoder << m_displayID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_preferredFramesPerSecond;
    }

private:
    const WebKit::DisplayLinkObserverID& m_observerID;
    uint32_t m_displayID;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_preferredFramesPerSecond;
};
#endif

#if HAVE(DISPLAY_LINK)
class StopDisplayLink {
public:
    using Arguments = std::tuple<WebKit::DisplayLinkObserverID, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_StopDisplayLink; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopDisplayLink(const WebKit::DisplayLinkObserverID& observerID, uint32_t displayID)
        : m_observerID(observerID)
        , m_displayID(displayID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_observerID;
        encoder << m_displayID;
    }

private:
    const WebKit::DisplayLinkObserverID& m_observerID;
    uint32_t m_displayID;
};
#endif

#if HAVE(DISPLAY_LINK)
class SetDisplayLinkPreferredFramesPerSecond {
public:
    using Arguments = std::tuple<WebKit::DisplayLinkObserverID, uint32_t, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SetDisplayLinkPreferredFramesPerSecond; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetDisplayLinkPreferredFramesPerSecond(const WebKit::DisplayLinkObserverID& observerID, uint32_t displayID, const unsigned& preferredFramesPerSecond)
        : m_observerID(observerID)
        , m_displayID(displayID)
        , m_preferredFramesPerSecond(preferredFramesPerSecond)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_observerID;
        encoder << m_displayID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_preferredFramesPerSecond;
    }

private:
    const WebKit::DisplayLinkObserverID& m_observerID;
    uint32_t m_displayID;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_preferredFramesPerSecond;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class SendMessageToWebContext {
public:
    using Arguments = std::tuple<WebKit::UserMessage>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SendMessageToWebContext; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendMessageToWebContext(const WebKit::UserMessage& userMessage)
        : m_userMessage(userMessage)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMessage;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserMessage& m_userMessage;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class SendMessageToWebContextWithReply {
public:
    using Arguments = std::tuple<WebKit::UserMessage>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SendMessageToWebContextWithReply; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcessProxy_SendMessageToWebContextWithReplyReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::UserMessage>;
    using Reply = CompletionHandler<void(WebKit::UserMessage&&)>;
    using Promise = WTF::NativePromise<WebKit::UserMessage, IPC::Error>;
    explicit SendMessageToWebContextWithReply(const WebKit::UserMessage& userMessage)
        : m_userMessage(userMessage)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMessage;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserMessage& m_userMessage;
};
#endif

class CreateSpeechRecognitionServer {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_CreateSpeechRecognitionServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CreateSpeechRecognitionServer(const WebCore::PageIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_identifier;
};

class DestroySpeechRecognitionServer {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DestroySpeechRecognitionServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DestroySpeechRecognitionServer(const WebCore::PageIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_identifier;
};

class SystemBeep {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SystemBeep; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SystemBeep()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
class IsAXAuthenticated {
public:
    using Arguments = std::tuple<WebKit::CoreIPCAuditToken>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_IsAXAuthenticated; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit IsAXAuthenticated(const WebKit::CoreIPCAuditToken& auditToken)
        : m_auditToken(auditToken)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_auditToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::CoreIPCAuditToken& m_auditToken;
};
#endif

#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
class SetCaptionDisplayMode {
public:
    using Arguments = std::tuple<WebCore::CaptionUserPreferencesDisplayMode>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SetCaptionDisplayMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCaptionDisplayMode(WebCore::CaptionUserPreferencesDisplayMode mode)
        : m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
    }

private:
    WebCore::CaptionUserPreferencesDisplayMode m_mode;
};
#endif

#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
class SetCaptionLanguage {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SetCaptionLanguage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCaptionLanguage(const String& language)
        : m_language(language)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_language;
    }

private:
    const String& m_language;
};
#endif

#if ENABLE(NOTIFICATION_EVENT)
class GetNotifications {
public:
    using Arguments = std::tuple<URL, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_GetNotifications; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcessProxy_GetNotificationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::NotificationData>>;
    using Reply = CompletionHandler<void(Vector<WebCore::NotificationData>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::NotificationData>, IPC::Error>;
    GetNotifications(const URL& registrationURL, const String& tag)
        : m_registrationURL(registrationURL)
        , m_tag(tag)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationURL;
        encoder << m_tag;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_registrationURL;
    const String& m_tag;
};
#endif

class SetAppBadgeFromWorker {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SetAppBadgeFromWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetAppBadgeFromWorker(const WebCore::SecurityOriginData& origin, const std::optional<uint64_t>& badge)
        : m_origin(origin)
        , m_badge(badge)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_badge;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_badge;
};

class SerializeAndWrapCryptoKey {
public:
    using Arguments = std::tuple<WebCore::CryptoKeyData>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SerializeAndWrapCryptoKey; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<uint8_t>>>;
    using Reply = CompletionHandler<void(std::optional<Vector<uint8_t>>&&)>;
    explicit SerializeAndWrapCryptoKey(const WebCore::CryptoKeyData& key)
        : m_key(key)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_key;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CryptoKeyData& m_key;
};

class UnwrapCryptoKey {
public:
    using Arguments = std::tuple<WebCore::WrappedCryptoKey>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_UnwrapCryptoKey; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<uint8_t>>>;
    using Reply = CompletionHandler<void(std::optional<Vector<uint8_t>>&&)>;
    explicit UnwrapCryptoKey(const WebCore::WrappedCryptoKey& wrappedKey)
        : m_wrappedKey(wrappedKey)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_wrappedKey;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WrappedCryptoKey& m_wrappedKey;
};

#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
class SetupLogStream {
public:
    using Arguments = std::tuple<uint32_t, IPC::StreamServerConnectionHandle, WebKit::LogStreamIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SetupLogStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcessProxy_SetupLogStreamReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<IPC::Semaphore, IPC::Semaphore>;
    using Reply = CompletionHandler<void(IPC::Semaphore&&, IPC::Semaphore&&)>;
    using Promise = WTF::NativePromise<std::tuple<IPC::Semaphore, IPC::Semaphore>, IPC::Error>;
    SetupLogStream(uint32_t pid, IPC::StreamServerConnectionHandle&& serverConnection, const WebKit::LogStreamIdentifier& identifier)
        : m_pid(pid)
        , m_serverConnection(WTFMove(serverConnection))
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pid;
        encoder << WTFMove(m_serverConnection);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    uint32_t m_pid;
    IPC::StreamServerConnectionHandle&& m_serverConnection;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::LogStreamIdentifier& m_identifier;
};
#endif

#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && !ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
class SetupLogStream {
public:
    using Arguments = std::tuple<uint32_t, WebKit::LogStreamIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SetupLogStream; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcessProxy_SetupLogStreamReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetupLogStream(uint32_t pid, const WebKit::LogStreamIdentifier& identifier)
        : m_pid(pid)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    uint32_t m_pid;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::LogStreamIdentifier& m_identifier;
};
#endif

#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
class CreateServiceWorkerDebuggable {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, URL, WebCore::ServiceWorkerIsInspectable>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_CreateServiceWorkerDebuggable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcessProxy_CreateServiceWorkerDebuggableReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    CreateServiceWorkerDebuggable(const WebCore::ServiceWorkerIdentifier& identifier, const URL& url, WebCore::ServiceWorkerIsInspectable isInspectable)
        : m_identifier(identifier)
        , m_url(url)
        , m_isInspectable(isInspectable)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << m_isInspectable;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    WebCore::ServiceWorkerIsInspectable m_isInspectable;
};
#endif

#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
class DeleteServiceWorkerDebuggable {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_DeleteServiceWorkerDebuggable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DeleteServiceWorkerDebuggable(const WebCore::ServiceWorkerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};
#endif

#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
class SendMessageToInspector {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessProxy_SendMessageToInspector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SendMessageToInspector(const WebCore::ServiceWorkerIdentifier& identifier, const String& message)
        : m_identifier(identifier)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    const String& m_message;
};
#endif

} // namespace WebProcessProxy
} // namespace Messages
