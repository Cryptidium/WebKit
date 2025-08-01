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


namespace Messages {
namespace AuxiliaryProcess {

static inline IPC::ReceiverName messageReceiverName()
{
    return IPC::ReceiverName::AuxiliaryProcess;
}

class ShutDown {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::AuxiliaryProcess_ShutDown; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShutDown()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetProcessSuppressionEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::AuxiliaryProcess_SetProcessSuppressionEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetProcessSuppressionEnabled(bool flag)
        : m_flag(flag)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_flag;
    }

private:
    bool m_flag;
};

class MainThreadPing {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::AuxiliaryProcess_MainThreadPing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::AuxiliaryProcess_MainThreadPingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    MainThreadPing()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(CFPREFS_DIRECT_MODE)
class PreferenceDidUpdate {
public:
    using Arguments = std::tuple<String, String, std::optional<String>>;

    static IPC::MessageName name() { return IPC::MessageName::AuxiliaryProcess_PreferenceDidUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = true;

    PreferenceDidUpdate(const String& domain, const String& key, const std::optional<String>& encodedValue)
        : m_domain(domain)
        , m_key(key)
        , m_encodedValue(encodedValue)
    {
    }

    void encodeCoalescingKey(IPC::Encoder& encoder) const
    {
        encoder << m_domain;
        encoder << m_key;
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_domain;
        encoder << m_key;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_encodedValue;
    }

private:
    const String& m_domain;
    const String& m_key;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_encodedValue;
};
#endif

#if OS(LINUX)
class DidReceiveMemoryPressureEvent {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::AuxiliaryProcess_DidReceiveMemoryPressureEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveMemoryPressureEvent(bool isCritical)
        : m_isCritical(isCritical)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isCritical;
    }

private:
    bool m_isCritical;
};
#endif

} // namespace AuxiliaryProcess
} // namespace Messages
