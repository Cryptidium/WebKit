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

#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_STREAM) && PLATFORM(COCOA)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#if PLATFORM(COCOA)
#include "SharedCARingBuffer.h"
#endif
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class CAAudioStreamDescription;
}

namespace WebKit {
struct AudioMediaStreamTrackRendererInternalUnitIdentifierType;
using AudioMediaStreamTrackRendererInternalUnitIdentifier = ObjectIdentifier<AudioMediaStreamTrackRendererInternalUnitIdentifierType>;
}

namespace Messages {
namespace RemoteAudioMediaStreamTrackRendererInternalUnitManager {

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
    return IPC::ReceiverName::RemoteAudioMediaStreamTrackRendererInternalUnitManager;
}

class CreateUnit {
public:
    using Arguments = std::tuple<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_CreateUnit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_CreateUnitReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::CAAudioStreamDescription>, uint64_t>;
    using Reply = CompletionHandler<void(std::optional<WebCore::CAAudioStreamDescription>&&, uint64_t)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::CAAudioStreamDescription>, uint64_t>, IPC::Error>;
    CreateUnit(const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& identifier, const String& deviceID)
        : m_identifier(identifier)
        , m_deviceID(deviceID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_deviceID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& m_identifier;
    const String& m_deviceID;
};

class DeleteUnit {
public:
    using Arguments = std::tuple<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_DeleteUnit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DeleteUnit(const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& m_identifier;
};

class StartUnit {
public:
    using Arguments = std::tuple<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier, WebKit::ConsumerSharedCARingBufferHandle, IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_StartUnit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartUnit(const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& identifier, WebKit::ConsumerSharedCARingBufferHandle&& storageHandle, const IPC::Semaphore& renderSemaphore)
        : m_identifier(identifier)
        , m_storageHandle(WTFMove(storageHandle))
        , m_renderSemaphore(renderSemaphore)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << WTFMove(m_storageHandle);
        encoder << m_renderSemaphore;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& m_identifier;
    WebKit::ConsumerSharedCARingBufferHandle&& m_storageHandle;
    const IPC::Semaphore& m_renderSemaphore;
};

class StopUnit {
public:
    using Arguments = std::tuple<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_StopUnit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StopUnit(const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifier& m_identifier;
};

class SetLastDeviceUsed {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_SetLastDeviceUsed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetLastDeviceUsed(const String& deviceID)
        : m_deviceID(deviceID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_deviceID;
    }

private:
    const String& m_deviceID;
};

} // namespace RemoteAudioMediaStreamTrackRendererInternalUnitManager
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(MEDIA_STREAM) && PLATFORM(COCOA)
