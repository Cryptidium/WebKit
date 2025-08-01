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

#if ENABLE(MEDIA_STREAM)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#if PLATFORM(COCOA)
#include "SharedCARingBuffer.h"
#endif
#include <wtf/Forward.h>
#include <wtf/MediaTime.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
class CAAudioStreamDescription;
struct RealtimeMediaSourceIdentifierType;
using RealtimeMediaSourceIdentifier = ObjectIdentifier<RealtimeMediaSourceIdentifierType>;
}

namespace Messages {
namespace SpeechRecognitionRemoteRealtimeMediaSourceManager {

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
    return IPC::ReceiverName::SpeechRecognitionRemoteRealtimeMediaSourceManager;
}

class RemoteAudioSamplesAvailable {
public:
    using Arguments = std::tuple<WebCore::RealtimeMediaSourceIdentifier, MediaTime, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteAudioSamplesAvailable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoteAudioSamplesAvailable(const WebCore::RealtimeMediaSourceIdentifier& identifier, const MediaTime& time, uint64_t numberOfFrames)
        : m_identifier(identifier)
        , m_time(time)
        , m_numberOfFrames(numberOfFrames)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_time;
        encoder << m_numberOfFrames;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RealtimeMediaSourceIdentifier& m_identifier;
    const MediaTime& m_time;
    uint64_t m_numberOfFrames;
};

class RemoteCaptureFailed {
public:
    using Arguments = std::tuple<WebCore::RealtimeMediaSourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteCaptureFailed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoteCaptureFailed(const WebCore::RealtimeMediaSourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RealtimeMediaSourceIdentifier& m_identifier;
};

class RemoteSourceStopped {
public:
    using Arguments = std::tuple<WebCore::RealtimeMediaSourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteSourceStopped; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoteSourceStopped(const WebCore::RealtimeMediaSourceIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RealtimeMediaSourceIdentifier& m_identifier;
};

#if PLATFORM(COCOA)
class SetStorage {
public:
    using Arguments = std::tuple<WebCore::RealtimeMediaSourceIdentifier, WebKit::ConsumerSharedCARingBufferHandle, WebCore::CAAudioStreamDescription>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionRemoteRealtimeMediaSourceManager_SetStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetStorage(const WebCore::RealtimeMediaSourceIdentifier& identifier, WebKit::ConsumerSharedCARingBufferHandle&& storageHandle, const WebCore::CAAudioStreamDescription& description)
        : m_identifier(identifier)
        , m_storageHandle(WTFMove(storageHandle))
        , m_description(description)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << WTFMove(m_storageHandle);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_description;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RealtimeMediaSourceIdentifier& m_identifier;
    WebKit::ConsumerSharedCARingBufferHandle&& m_storageHandle;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CAAudioStreamDescription& m_description;
};
#endif

} // namespace SpeechRecognitionRemoteRealtimeMediaSourceManager
} // namespace Messages

#endif // ENABLE(MEDIA_STREAM)
