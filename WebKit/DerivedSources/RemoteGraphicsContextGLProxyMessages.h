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

#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
struct RemoteGraphicsContextGLInitializationState;
}

namespace Messages {
namespace RemoteGraphicsContextGLProxy {

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
    return IPC::ReceiverName::RemoteGraphicsContextGLProxy;
}

class WasCreated {
public:
    using Arguments = std::tuple<IPC::Semaphore, IPC::Semaphore, std::optional<WebKit::RemoteGraphicsContextGLInitializationState>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGLProxy_WasCreated; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WasCreated(const IPC::Semaphore& streamWakeUpSemaphore, const IPC::Semaphore& streamClientWaitSemaphore, const std::optional<WebKit::RemoteGraphicsContextGLInitializationState>& initializationState)
        : m_streamWakeUpSemaphore(streamWakeUpSemaphore)
        , m_streamClientWaitSemaphore(streamClientWaitSemaphore)
        , m_initializationState(initializationState)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_streamWakeUpSemaphore;
        encoder << m_streamClientWaitSemaphore;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initializationState;
    }

private:
    const IPC::Semaphore& m_streamWakeUpSemaphore;
    const IPC::Semaphore& m_streamClientWaitSemaphore;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::RemoteGraphicsContextGLInitializationState>& m_initializationState;
};

class WasLost {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGLProxy_WasLost; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WasLost()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class addDebugMessage {
public:
    using Arguments = std::tuple<unsigned, unsigned, unsigned, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteGraphicsContextGLProxy_addDebugMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    addDebugMessage(const unsigned& type, const unsigned& id, const unsigned& severity, const String& message)
        : m_type(type)
        , m_id(id)
        , m_severity(severity)
        , m_message(message)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_severity;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_id;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_severity;
    const String& m_message;
};

} // namespace RemoteGraphicsContextGLProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
