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

#if ENABLE(GPU_PROCESS) && ENABLE(WEB_AUDIO)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#if PLATFORM(COCOA)
#include "SharedCARingBuffer.h"
#endif
#include <WebCore/SharedMemory.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
struct RemoteAudioDestinationIdentifierType;
using RemoteAudioDestinationIdentifier = ObjectIdentifier<RemoteAudioDestinationIdentifierType>;
}

namespace Messages {
namespace RemoteAudioDestinationManager {

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
    return IPC::ReceiverName::RemoteAudioDestinationManager;
}

class CreateAudioDestination {
public:
    using Arguments = std::tuple<WebKit::RemoteAudioDestinationIdentifier, String, uint32_t, uint32_t, float, float, IPC::Semaphore, WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioDestinationManager_CreateAudioDestination; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteAudioDestinationManager_CreateAudioDestinationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    using Promise = WTF::NativePromise<uint64_t, IPC::Error>;
    CreateAudioDestination(const WebKit::RemoteAudioDestinationIdentifier& identifier, const String& inputDeviceId, uint32_t numberOfInputChannels, uint32_t numberOfOutputChannels, float sampleRate, float hardwareSampleRate, const IPC::Semaphore& renderSemaphore, WebCore::SharedMemory::Handle&& frameCount)
        : m_identifier(identifier)
        , m_inputDeviceId(inputDeviceId)
        , m_numberOfInputChannels(numberOfInputChannels)
        , m_numberOfOutputChannels(numberOfOutputChannels)
        , m_sampleRate(sampleRate)
        , m_hardwareSampleRate(hardwareSampleRate)
        , m_renderSemaphore(renderSemaphore)
        , m_frameCount(WTFMove(frameCount))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_inputDeviceId;
        encoder << m_numberOfInputChannels;
        encoder << m_numberOfOutputChannels;
        encoder << m_sampleRate;
        encoder << m_hardwareSampleRate;
        encoder << m_renderSemaphore;
        encoder << WTFMove(m_frameCount);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteAudioDestinationIdentifier& m_identifier;
    const String& m_inputDeviceId;
    uint32_t m_numberOfInputChannels;
    uint32_t m_numberOfOutputChannels;
    float m_sampleRate;
    float m_hardwareSampleRate;
    const IPC::Semaphore& m_renderSemaphore;
    WebCore::SharedMemory::Handle&& m_frameCount;
};

class DeleteAudioDestination {
public:
    using Arguments = std::tuple<WebKit::RemoteAudioDestinationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioDestinationManager_DeleteAudioDestination; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DeleteAudioDestination(const WebKit::RemoteAudioDestinationIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteAudioDestinationIdentifier& m_identifier;
};

class StartAudioDestination {
public:
    using Arguments = std::tuple<WebKit::RemoteAudioDestinationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioDestinationManager_StartAudioDestination; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteAudioDestinationManager_StartAudioDestinationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, uint64_t>;
    using Reply = CompletionHandler<void(bool, uint64_t)>;
    using Promise = WTF::NativePromise<std::tuple<bool, uint64_t>, IPC::Error>;
    explicit StartAudioDestination(const WebKit::RemoteAudioDestinationIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteAudioDestinationIdentifier& m_identifier;
};

class StopAudioDestination {
public:
    using Arguments = std::tuple<WebKit::RemoteAudioDestinationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioDestinationManager_StopAudioDestination; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteAudioDestinationManager_StopAudioDestinationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit StopAudioDestination(const WebKit::RemoteAudioDestinationIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteAudioDestinationIdentifier& m_identifier;
};

#if PLATFORM(COCOA)
class AudioSamplesStorageChanged {
public:
    using Arguments = std::tuple<WebKit::RemoteAudioDestinationIdentifier, WebKit::ConsumerSharedCARingBufferHandle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioDestinationManager_AudioSamplesStorageChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AudioSamplesStorageChanged(const WebKit::RemoteAudioDestinationIdentifier& identifier, WebKit::ConsumerSharedCARingBufferHandle&& storageHandle)
        : m_identifier(identifier)
        , m_storageHandle(WTFMove(storageHandle))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << WTFMove(m_storageHandle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteAudioDestinationIdentifier& m_identifier;
    WebKit::ConsumerSharedCARingBufferHandle&& m_storageHandle;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetSceneIdentifier {
public:
    using Arguments = std::tuple<WebKit::RemoteAudioDestinationIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioDestinationManager_SetSceneIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetSceneIdentifier(const WebKit::RemoteAudioDestinationIdentifier& identifier, const String& sceneIdentifier)
        : m_identifier(identifier)
        , m_sceneIdentifier(sceneIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_sceneIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteAudioDestinationIdentifier& m_identifier;
    const String& m_sceneIdentifier;
};
#endif

} // namespace RemoteAudioDestinationManager
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(WEB_AUDIO)
