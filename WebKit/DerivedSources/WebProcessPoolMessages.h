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
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
enum class GamepadHapticEffectType : uint8_t;
struct GamepadEffectParameters;
}

namespace WebKit {
class UserData;
}

namespace Messages {
namespace WebProcessPool {

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
    return IPC::ReceiverName::WebProcessPool;
}

class HandleMessage {
public:
    using Arguments = std::tuple<String, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_HandleMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleMessage(const String& messageName, const WebKit::UserData& messageBody)
        : m_messageName(messageName)
        , m_messageBody(messageBody)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_messageName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_messageBody;
    }

private:
    const String& m_messageName;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_messageBody;
};

class HandleSynchronousMessage {
public:
    using Arguments = std::tuple<String, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_HandleSynchronousMessage; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::UserData>;
    using Reply = CompletionHandler<void(WebKit::UserData&&)>;
    HandleSynchronousMessage(const String& messageName, const WebKit::UserData& messageBody)
        : m_messageName(messageName)
        , m_messageBody(messageBody)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_messageName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_messageBody;
    }

private:
    const String& m_messageName;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_messageBody;
};

#if ENABLE(GAMEPAD)
class StartedUsingGamepads {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_StartedUsingGamepads; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartedUsingGamepads()
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

#if ENABLE(GAMEPAD)
class StoppedUsingGamepads {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_StoppedUsingGamepads; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcessPool_StoppedUsingGamepadsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    StoppedUsingGamepads()
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

#if ENABLE(GAMEPAD)
class PlayGamepadEffect {
public:
    using Arguments = std::tuple<unsigned, String, WebCore::GamepadHapticEffectType, WebCore::GamepadEffectParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_PlayGamepadEffect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcessPool_PlayGamepadEffectReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    PlayGamepadEffect(const unsigned& gamepadIndex, const String& gamepadID, WebCore::GamepadHapticEffectType type, const WebCore::GamepadEffectParameters& parameters)
        : m_gamepadIndex(gamepadIndex)
        , m_gamepadID(gamepadID)
        , m_type(type)
        , m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gamepadIndex;
        encoder << m_gamepadID;
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_gamepadIndex;
    const String& m_gamepadID;
    WebCore::GamepadHapticEffectType m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::GamepadEffectParameters& m_parameters;
};
#endif

#if ENABLE(GAMEPAD)
class StopGamepadEffects {
public:
    using Arguments = std::tuple<unsigned, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_StopGamepadEffects; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcessPool_StopGamepadEffectsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    StopGamepadEffects(const unsigned& gamepadIndex, const String& gamepadID)
        : m_gamepadIndex(gamepadIndex)
        , m_gamepadID(gamepadID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gamepadIndex;
        encoder << m_gamepadID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_gamepadIndex;
    const String& m_gamepadID;
};
#endif

#if ENABLE(MODEL_PROCESS)
class StartedPlayingModels {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_StartedPlayingModels; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartedPlayingModels()
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

#if ENABLE(MODEL_PROCESS)
class StoppedPlayingModels {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_StoppedPlayingModels; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StoppedPlayingModels()
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

class ReportWebContentCPUTime {
public:
    using Arguments = std::tuple<Seconds, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcessPool_ReportWebContentCPUTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReportWebContentCPUTime(const Seconds& cpuTime, uint64_t activityState)
        : m_cpuTime(cpuTime)
        , m_activityState(activityState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cpuTime;
        encoder << m_activityState;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_cpuTime;
    uint64_t m_activityState;
};

} // namespace WebProcessPool
} // namespace Messages
