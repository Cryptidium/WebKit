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
#include <WebCore/ProcessQualified.h>
#include <WebCore/ScriptExecutionContextIdentifier.h>
#include <optional>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace JSC {
enum class MessageLevel : uint8_t;
enum class MessageSource : uint8_t;
}

namespace WebCore {
struct ServiceWorkerIdentifierType;
using ServiceWorkerIdentifier = AtomicObjectIdentifier<ServiceWorkerIdentifierType>;
struct ExceptionData;
struct MessageWithMessagePorts;
struct ServiceWorkerClientData;
struct ServiceWorkerClientQueryOptions;
struct ServiceWorkerImportedScript;
struct ServiceWorkerJobDataIdentifier;
}

namespace Messages {
namespace WebSWServerToContextConnection {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInNetworkProcess());
        }
    );
#endif
    return IPC::ReceiverName::WebSWServerToContextConnection;
}

class ScriptContextFailedToStart {
public:
    using Arguments = std::tuple<std::optional<WebCore::ServiceWorkerJobDataIdentifier>, WebCore::ServiceWorkerIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_ScriptContextFailedToStart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ScriptContextFailedToStart(const std::optional<WebCore::ServiceWorkerJobDataIdentifier>& jobDataIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const String& message)
        : m_jobDataIdentifier(jobDataIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobDataIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ServiceWorkerJobDataIdentifier>& m_jobDataIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    const String& m_message;
};

class ScriptContextStarted {
public:
    using Arguments = std::tuple<std::optional<WebCore::ServiceWorkerJobDataIdentifier>, WebCore::ServiceWorkerIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_ScriptContextStarted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ScriptContextStarted(const std::optional<WebCore::ServiceWorkerJobDataIdentifier>& jobDataIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, bool doesHandleFetch)
        : m_jobDataIdentifier(jobDataIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_doesHandleFetch(doesHandleFetch)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobDataIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_doesHandleFetch;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ServiceWorkerJobDataIdentifier>& m_jobDataIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    bool m_doesHandleFetch;
};

class DidFinishInstall {
public:
    using Arguments = std::tuple<std::optional<WebCore::ServiceWorkerJobDataIdentifier>, WebCore::ServiceWorkerIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_DidFinishInstall; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishInstall(const std::optional<WebCore::ServiceWorkerJobDataIdentifier>& jobDataIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, bool wasSuccessful)
        : m_jobDataIdentifier(jobDataIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_wasSuccessful(wasSuccessful)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobDataIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_wasSuccessful;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ServiceWorkerJobDataIdentifier>& m_jobDataIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    bool m_wasSuccessful;
};

class DidFinishActivation {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_DidFinishActivation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFinishActivation(const WebCore::ServiceWorkerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};

class SetServiceWorkerHasPendingEvents {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_SetServiceWorkerHasPendingEvents; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetServiceWorkerHasPendingEvents(const WebCore::ServiceWorkerIdentifier& identifier, bool hasPendingEvents)
        : m_identifier(identifier)
        , m_hasPendingEvents(hasPendingEvents)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_hasPendingEvents;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    bool m_hasPendingEvents;
};

class SkipWaiting {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_SkipWaiting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerToContextConnection_SkipWaitingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SkipWaiting(const WebCore::ServiceWorkerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};

class WorkerTerminated {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_WorkerTerminated; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit WorkerTerminated(const WebCore::ServiceWorkerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};

class FindClientByVisibleIdentifier {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_FindClientByVisibleIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerToContextConnection_FindClientByVisibleIdentifierReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ServiceWorkerClientData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ServiceWorkerClientData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ServiceWorkerClientData>, IPC::Error>;
    FindClientByVisibleIdentifier(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const String& clientIdentifier)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_clientIdentifier(clientIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_clientIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    const String& m_clientIdentifier;
};

class MatchAll {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::ServiceWorkerClientQueryOptions>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_MatchAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerToContextConnection_MatchAllReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::ServiceWorkerClientData>>;
    using Reply = CompletionHandler<void(Vector<WebCore::ServiceWorkerClientData>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::ServiceWorkerClientData>, IPC::Error>;
    MatchAll(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const WebCore::ServiceWorkerClientQueryOptions& options)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerClientQueryOptions& m_options;
};

class Claim {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_Claim; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerToContextConnection_ClaimReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ExceptionData>, IPC::Error>;
    explicit Claim(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
};

class Focus {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_Focus; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerToContextConnection_FocusReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ServiceWorkerClientData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ServiceWorkerClientData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ServiceWorkerClientData>, IPC::Error>;
    explicit Focus(const WebCore::ScriptExecutionContextIdentifier& serviceWorkerClientIdentifier)
        : m_serviceWorkerClientIdentifier(serviceWorkerClientIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_serviceWorkerClientIdentifier;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_serviceWorkerClientIdentifier;
};

class Navigate {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier, WebCore::ServiceWorkerIdentifier, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_Navigate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerToContextConnection_NavigateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::ServiceWorkerClientData>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::ServiceWorkerClientData>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::ServiceWorkerClientData>, WebCore::ExceptionData>, IPC::Error>;
    Navigate(const WebCore::ScriptExecutionContextIdentifier& clientIdentifier, const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, const URL& url)
        : m_clientIdentifier(clientIdentifier)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_url(url)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_clientIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_clientIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class SetScriptResource {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, URL, WebCore::ServiceWorkerImportedScript>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_SetScriptResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetScriptResource(const WebCore::ServiceWorkerIdentifier& identifier, const URL& scriptURL, const WebCore::ServiceWorkerImportedScript& script)
        : m_identifier(identifier)
        , m_scriptURL(scriptURL)
        , m_script(script)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scriptURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_script;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_scriptURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerImportedScript& m_script;
};

class PostMessageToServiceWorkerClient {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier, WebCore::MessageWithMessagePorts, WebCore::ServiceWorkerIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_PostMessageToServiceWorkerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostMessageToServiceWorkerClient(const WebCore::ScriptExecutionContextIdentifier& destination, const WebCore::MessageWithMessagePorts& message, const WebCore::ServiceWorkerIdentifier& source, const String& sourceOrigin)
        : m_destination(destination)
        , m_message(message)
        , m_source(source)
        , m_sourceOrigin(sourceOrigin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_destination;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_source;
        encoder << m_sourceOrigin;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_destination;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessageWithMessagePorts& m_message;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_source;
    const String& m_sourceOrigin;
};

class DidFailHeartBeatCheck {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_DidFailHeartBeatCheck; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFailHeartBeatCheck(const WebCore::ServiceWorkerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
};

class SetAsInspected {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_SetAsInspected; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetAsInspected(const WebCore::ServiceWorkerIdentifier& identifier, bool isInspected)
        : m_identifier(identifier)
        , m_isInspected(isInspected)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_isInspected;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    bool m_isInspected;
};

class OpenWindow {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_OpenWindow; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWServerToContextConnection_OpenWindowReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::ServiceWorkerClientData>, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::ServiceWorkerClientData>, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::ServiceWorkerClientData>, WebCore::ExceptionData>, IPC::Error>;
    OpenWindow(const WebCore::ServiceWorkerIdentifier& identifier, const URL& url)
        : m_identifier(identifier)
        , m_url(url)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class ReportConsoleMessage {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, JSC::MessageSource, JSC::MessageLevel, String, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWServerToContextConnection_ReportConsoleMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReportConsoleMessage(const WebCore::ServiceWorkerIdentifier& identifier, JSC::MessageSource messageSource, JSC::MessageLevel messageLevel, const String& message, uint64_t requestIdentifier)
        : m_identifier(identifier)
        , m_messageSource(messageSource)
        , m_messageLevel(messageLevel)
        , m_message(message)
        , m_requestIdentifier(requestIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_messageSource;
        encoder << m_messageLevel;
        encoder << m_message;
        encoder << m_requestIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_identifier;
    JSC::MessageSource m_messageSource;
    JSC::MessageLevel m_messageLevel;
    const String& m_message;
    uint64_t m_requestIdentifier;
};

} // namespace WebSWServerToContextConnection
} // namespace Messages
