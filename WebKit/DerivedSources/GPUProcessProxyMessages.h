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
#include "LayerHostingContext.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct ProcessIdentifierType;
using ProcessIdentifier = ObjectIdentifier<ProcessIdentifierType>;
struct SnapshotIdentifierType;
using SnapshotIdentifier = AtomicObjectIdentifier<SnapshotIdentifierType>;
}

namespace WebKit {
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
}

namespace Messages {
namespace GPUProcessProxy {

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
    return IPC::ReceiverName::GPUProcessProxy;
}

#if HAVE(VISIBILITY_PROPAGATION_VIEW)
class DidCreateContextForVisibilityPropagation {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier, WebKit::LayerHostingContextID>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_DidCreateContextForVisibilityPropagation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCreateContextForVisibilityPropagation(const WebKit::WebPageProxyIdentifier& pageProxyID, const WebCore::PageIdentifier& pageID, const WebKit::LayerHostingContextID& contextID)
        : m_pageProxyID(pageProxyID)
        , m_pageID(pageID)
        , m_contextID(contextID)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_contextID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    const WebKit::LayerHostingContextID& m_contextID;
};
#endif

#if ENABLE(VP9)
class SetHasVP9HardwareDecoder {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_SetHasVP9HardwareDecoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasVP9HardwareDecoder(bool hasVP9HardwareDecoder)
        : m_hasVP9HardwareDecoder(hasVP9HardwareDecoder)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasVP9HardwareDecoder;
    }

private:
    bool m_hasVP9HardwareDecoder;
};
#endif

#if ENABLE(AV1)
class SetHasAV1HardwareDecoder {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_SetHasAV1HardwareDecoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasAV1HardwareDecoder(bool hasAV1HardwareDecoder)
        : m_hasAV1HardwareDecoder(hasAV1HardwareDecoder)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasAV1HardwareDecoder;
    }

private:
    bool m_hasAV1HardwareDecoder;
};
#endif

#if ENABLE(MEDIA_STREAM)
class VoiceActivityDetected {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_VoiceActivityDetected; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    VoiceActivityDetected()
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

#if ENABLE(MEDIA_STREAM)
class StartMonitoringCaptureDeviceRotation {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_StartMonitoringCaptureDeviceRotation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartMonitoringCaptureDeviceRotation(const WebCore::PageIdentifier& pageID, const String& devicePersistentId)
        : m_pageID(pageID)
        , m_devicePersistentId(devicePersistentId)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_devicePersistentId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    const String& m_devicePersistentId;
};
#endif

#if ENABLE(MEDIA_STREAM)
class StopMonitoringCaptureDeviceRotation {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_StopMonitoringCaptureDeviceRotation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopMonitoringCaptureDeviceRotation(const WebCore::PageIdentifier& pageID, const String& devicePersistentId)
        : m_pageID(pageID)
        , m_devicePersistentId(devicePersistentId)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_devicePersistentId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    const String& m_devicePersistentId;
};
#endif

#if ENABLE(MEDIA_STREAM)
class MicrophoneMuteStatusChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_MicrophoneMuteStatusChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MicrophoneMuteStatusChanged(bool isMuting)
        : m_isMuting(isMuting)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isMuting;
    }

private:
    bool m_isMuting;
};
#endif

#if (ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY))
class StatusBarWasTapped {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_StatusBarWasTapped; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcessProxy_StatusBarWasTappedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    StatusBarWasTapped()
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

class ProcessIsReadyToExit {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_ProcessIsReadyToExit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProcessIsReadyToExit()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class TerminateWebProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_TerminateWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TerminateWebProcess(const WebCore::ProcessIdentifier& webProcessIdentifier)
        : m_webProcessIdentifier(webProcessIdentifier)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webProcessIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_webProcessIdentifier;
};

#if PLATFORM(COCOA)
class DidDrawRemoteToPDF {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, RefPtr<WebCore::SharedBuffer>, WebCore::SnapshotIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcessProxy_DidDrawRemoteToPDF; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidDrawRemoteToPDF(const WebCore::PageIdentifier& pageID, const RefPtr<WebCore::SharedBuffer>& data, const WebCore::SnapshotIdentifier& snapshotIdentifier)
        : m_pageID(pageID)
        , m_data(data)
        , m_snapshotIdentifier(snapshotIdentifier)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_snapshotIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::SharedBuffer>& m_data;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SnapshotIdentifier& m_snapshotIdentifier;
};
#endif

} // namespace GPUProcessProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
