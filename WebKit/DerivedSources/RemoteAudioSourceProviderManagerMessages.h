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

#if PLATFORM(COCOA) && ENABLE(GPU_PROCESS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#if PLATFORM(COCOA)
#include "SharedCARingBuffer.h"
#endif
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
class CAAudioStreamDescription;
struct MediaPlayerIdentifierType;
using MediaPlayerIdentifier = ObjectIdentifier<MediaPlayerIdentifierType>;
}

namespace Messages {
namespace RemoteAudioSourceProviderManager {

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
    return IPC::ReceiverName::RemoteAudioSourceProviderManager;
}

class AudioStorageChanged {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerIdentifier, WebKit::ConsumerSharedCARingBufferHandle, WebCore::CAAudioStreamDescription>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSourceProviderManager_AudioStorageChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AudioStorageChanged(const WebCore::MediaPlayerIdentifier& id, WebKit::ConsumerSharedCARingBufferHandle&& storageHandle, const WebCore::CAAudioStreamDescription& description)
        : m_id(id)
        , m_storageHandle(WTFMove(storageHandle))
        , m_description(description)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << WTFMove(m_storageHandle);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_description;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerIdentifier& m_id;
    WebKit::ConsumerSharedCARingBufferHandle&& m_storageHandle;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CAAudioStreamDescription& m_description;
};

class AudioSamplesAvailable {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerIdentifier, uint64_t, uint64_t, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSourceProviderManager_AudioSamplesAvailable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AudioSamplesAvailable(const WebCore::MediaPlayerIdentifier& id, uint64_t startFrame, uint64_t numberOfFrames, bool needsFlush)
        : m_id(id)
        , m_startFrame(startFrame)
        , m_numberOfFrames(numberOfFrames)
        , m_needsFlush(needsFlush)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_startFrame;
        encoder << m_numberOfFrames;
        encoder << m_needsFlush;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerIdentifier& m_id;
    uint64_t m_startFrame;
    uint64_t m_numberOfFrames;
    bool m_needsFlush;
};

} // namespace RemoteAudioSourceProviderManager
} // namespace Messages

#endif // PLATFORM(COCOA) && ENABLE(GPU_PROCESS)
