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

#if ENABLE(MODEL_PROCESS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "ConnectionHandle.h"
#include "MessageNames.h"
#include "ModelProcessConnectionParameters.h"
#include "ModelProcessCreationParameters.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace PAL {
class SessionID;
}

namespace WebCore {
struct ProcessIdentifierType;
using ProcessIdentifier = ObjectIdentifier<ProcessIdentifierType>;
}

namespace WebKit {
struct SharedPreferencesForWebProcess;
}

namespace Messages {
namespace ModelProcess {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInModelProcess());
        }
    );
#endif
    return IPC::ReceiverName::ModelProcess;
}

class InitializeModelProcess {
public:
    using Arguments = std::tuple<WebKit::ModelProcessCreationParameters>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_InitializeModelProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::ModelProcess_InitializeModelProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit InitializeModelProcess(WebKit::ModelProcessCreationParameters&& processCreationParameters)
        : m_processCreationParameters(WTFMove(processCreationParameters))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_processCreationParameters);
    }

private:
    WebKit::ModelProcessCreationParameters&& m_processCreationParameters;
};

class CreateModelConnectionToWebProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, PAL::SessionID, IPC::ConnectionHandle, WebKit::ModelProcessConnectionParameters, std::optional<String>>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_CreateModelConnectionToWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::ModelProcess_CreateModelConnectionToWebProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    CreateModelConnectionToWebProcess(const WebCore::ProcessIdentifier& processIdentifier, const PAL::SessionID& sessionID, IPC::ConnectionHandle&& connectionHandle, WebKit::ModelProcessConnectionParameters&& parameters, const std::optional<String>& attributionTaskID)
        : m_processIdentifier(processIdentifier)
        , m_sessionID(sessionID)
        , m_connectionHandle(WTFMove(connectionHandle))
        , m_parameters(WTFMove(parameters))
        , m_attributionTaskID(attributionTaskID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << WTFMove(m_connectionHandle);
        encoder << WTFMove(m_parameters);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_attributionTaskID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    IPC::ConnectionHandle&& m_connectionHandle;
    WebKit::ModelProcessConnectionParameters&& m_parameters;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_attributionTaskID;
};

class SharedPreferencesForWebProcessDidChange {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebKit::SharedPreferencesForWebProcess>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_SharedPreferencesForWebProcessDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::ModelProcess_SharedPreferencesForWebProcessDidChangeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SharedPreferencesForWebProcessDidChange(const WebCore::ProcessIdentifier& processIdentifier, const WebKit::SharedPreferencesForWebProcess& sharedPreferencesForWebProcess)
        : m_processIdentifier(processIdentifier)
        , m_sharedPreferencesForWebProcess(sharedPreferencesForWebProcess)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedPreferencesForWebProcess;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::SharedPreferencesForWebProcess& m_sharedPreferencesForWebProcess;
};

class PrepareToSuspend {
public:
    using Arguments = std::tuple<bool, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_PrepareToSuspend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::ModelProcess_PrepareToSuspendReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PrepareToSuspend(bool isSuspensionImminent, const MonotonicTime& estimatedSuspendTime)
        : m_isSuspensionImminent(isSuspensionImminent)
        , m_estimatedSuspendTime(estimatedSuspendTime)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isSuspensionImminent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_estimatedSuspendTime;
    }

private:
    bool m_isSuspensionImminent;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_estimatedSuspendTime;
};

class ProcessDidResume {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_ProcessDidResume; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProcessDidResume()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class AddSession {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_AddSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddSession(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class RemoveSession {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_RemoveSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveSession(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class WebProcessConnectionCountForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_WebProcessConnectionCountForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::ModelProcess_WebProcessConnectionCountForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    using Promise = WTF::NativePromise<uint64_t, IPC::Error>;
    WebProcessConnectionCountForTesting()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ModelPlayerCountForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcess_ModelPlayerCountForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::ModelProcess_ModelPlayerCountForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    using Promise = WTF::NativePromise<uint64_t, IPC::Error>;
    ModelPlayerCountForTesting()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

} // namespace ModelProcess
} // namespace Messages

#endif // ENABLE(MODEL_PROCESS)
