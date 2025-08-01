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

#if ENABLE(GPU_PROCESS) && USE(AUDIO_SESSION)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
enum class AudioSessionMayResume : bool;
enum class AudioSessionCategory : uint8_t;
enum class AudioSessionMode : uint8_t;
enum class AudioSessionSoundStageSize : uint8_t;
enum class RouteSharingPolicy : uint8_t;
}

namespace Messages {
namespace RemoteAudioSessionProxy {

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
    return IPC::ReceiverName::RemoteAudioSessionProxy;
}

class SetCategory {
public:
    using Arguments = std::tuple<WebCore::AudioSessionCategory, WebCore::AudioSessionMode, WebCore::RouteSharingPolicy>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_SetCategory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetCategory(WebCore::AudioSessionCategory type, WebCore::AudioSessionMode mode, WebCore::RouteSharingPolicy policy)
        : m_type(type)
        , m_mode(mode)
        , m_policy(policy)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        encoder << m_mode;
        encoder << m_policy;
    }

private:
    WebCore::AudioSessionCategory m_type;
    WebCore::AudioSessionMode m_mode;
    WebCore::RouteSharingPolicy m_policy;
};

class SetPreferredBufferSize {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_SetPreferredBufferSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPreferredBufferSize(uint64_t preferredBufferSize)
        : m_preferredBufferSize(preferredBufferSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_preferredBufferSize;
    }

private:
    uint64_t m_preferredBufferSize;
};

class TryToSetActive {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_TryToSetActive; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit TryToSetActive(bool active)
        : m_active(active)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_active;
    }

private:
    bool m_active;
};

class SetIsPlayingToBluetoothOverride {
public:
    using Arguments = std::tuple<std::optional<bool>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_SetIsPlayingToBluetoothOverride; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIsPlayingToBluetoothOverride(const std::optional<bool>& value)
        : m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<bool>& m_value;
};

class TriggerBeginInterruptionForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_TriggerBeginInterruptionForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TriggerBeginInterruptionForTesting()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class TriggerEndInterruptionForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_TriggerEndInterruptionForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TriggerEndInterruptionForTesting()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class BeginInterruptionRemote {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_BeginInterruptionRemote; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BeginInterruptionRemote()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class EndInterruptionRemote {
public:
    using Arguments = std::tuple<WebCore::AudioSessionMayResume>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_EndInterruptionRemote; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit EndInterruptionRemote(WebCore::AudioSessionMayResume flags)
        : m_flags(flags)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_flags;
    }

private:
    WebCore::AudioSessionMayResume m_flags;
};

class SetSceneIdentifier {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_SetSceneIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSceneIdentifier(const String& sceneIdentifier)
        : m_sceneIdentifier(sceneIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sceneIdentifier;
    }

private:
    const String& m_sceneIdentifier;
};

class SetSoundStageSize {
public:
    using Arguments = std::tuple<WebCore::AudioSessionSoundStageSize>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteAudioSessionProxy_SetSoundStageSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSoundStageSize(WebCore::AudioSessionSoundStageSize size)
        : m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_size;
    }

private:
    WebCore::AudioSessionSoundStageSize m_size;
};

} // namespace RemoteAudioSessionProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && USE(AUDIO_SESSION)
