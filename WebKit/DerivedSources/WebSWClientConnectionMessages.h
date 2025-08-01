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
#include <WebCore/SharedMemory.h>
#include <wtf/Forward.h>
#include <wtf/HashSet.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class SharedBufferReference;
}

namespace WebCore {
class ResourceError;
struct ServiceWorkerIdentifierType;
using ServiceWorkerIdentifier = AtomicObjectIdentifier<ServiceWorkerIdentifierType>;
struct ServiceWorkerJobIdentifierType;
using ServiceWorkerJobIdentifier = AtomicObjectIdentifier<ServiceWorkerJobIdentifierType>;
struct ServiceWorkerRegistrationIdentifierType;
using ServiceWorkerRegistrationIdentifier = AtomicObjectIdentifier<ServiceWorkerRegistrationIdentifierType>;
class ServiceWorkerRegistrationKey;
enum class ShouldNotifyWhenResolved : bool;
enum class FetchOptionsCache : uint8_t;
enum class ServiceWorkerRegistrationState : uint8_t;
enum class ServiceWorkerState : uint8_t;
enum class ServiceWorkerUpdateViaCache : uint8_t;
struct BackgroundFetchInformation;
struct ExceptionData;
struct MessageWithMessagePorts;
struct ServiceWorkerClientData;
struct ServiceWorkerData;
struct ServiceWorkerRegistrationData;
}

namespace WebKit {
struct RetrieveRecordResponseBodyCallbackIdentifierType;
using RetrieveRecordResponseBodyCallbackIdentifier = ObjectIdentifier<RetrieveRecordResponseBodyCallbackIdentifierType>;
}

namespace Messages {
namespace WebSWClientConnection {

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
    return IPC::ReceiverName::WebSWClientConnection;
}

class JobRejectedInServer {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerJobIdentifier, WebCore::ExceptionData>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_JobRejectedInServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    JobRejectedInServer(const WebCore::ServiceWorkerJobIdentifier& jobDataIdentifier, const WebCore::ExceptionData& exception)
        : m_jobDataIdentifier(jobDataIdentifier)
        , m_exception(exception)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobDataIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_exception;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerJobIdentifier& m_jobDataIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ExceptionData& m_exception;
};

class RegistrationJobResolvedInServer {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerJobIdentifier, WebCore::ServiceWorkerRegistrationData, WebCore::ShouldNotifyWhenResolved>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_RegistrationJobResolvedInServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegistrationJobResolvedInServer(const WebCore::ServiceWorkerJobIdentifier& jobDataIdentifier, const WebCore::ServiceWorkerRegistrationData& registration, WebCore::ShouldNotifyWhenResolved shouldNotifyWhenResolved)
        : m_jobDataIdentifier(jobDataIdentifier)
        , m_registration(registration)
        , m_shouldNotifyWhenResolved(shouldNotifyWhenResolved)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobDataIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registration;
        encoder << m_shouldNotifyWhenResolved;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerJobIdentifier& m_jobDataIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationData& m_registration;
    WebCore::ShouldNotifyWhenResolved m_shouldNotifyWhenResolved;
};

class StartScriptFetchForServer {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerJobIdentifier, WebCore::ServiceWorkerRegistrationKey, WebCore::FetchOptionsCache>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_StartScriptFetchForServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartScriptFetchForServer(const WebCore::ServiceWorkerJobIdentifier& jobDataIdentifier, const WebCore::ServiceWorkerRegistrationKey& registrationKey, WebCore::FetchOptionsCache cachePolicy)
        : m_jobDataIdentifier(jobDataIdentifier)
        , m_registrationKey(registrationKey)
        , m_cachePolicy(cachePolicy)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_jobDataIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationKey;
        encoder << m_cachePolicy;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerJobIdentifier& m_jobDataIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationKey& m_registrationKey;
    WebCore::FetchOptionsCache m_cachePolicy;
};

class UpdateRegistrationState {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, WebCore::ServiceWorkerRegistrationState, std::optional<WebCore::ServiceWorkerData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_UpdateRegistrationState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateRegistrationState(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, WebCore::ServiceWorkerRegistrationState state, const std::optional<WebCore::ServiceWorkerData>& serviceWorkerIdentifier)
        : m_identifier(identifier)
        , m_state(state)
        , m_serviceWorkerIdentifier(serviceWorkerIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_state;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    WebCore::ServiceWorkerRegistrationState m_state;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ServiceWorkerData>& m_serviceWorkerIdentifier;
};

class UpdateWorkerState {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerIdentifier, WebCore::ServiceWorkerState>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_UpdateWorkerState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateWorkerState(const WebCore::ServiceWorkerIdentifier& serviceWorkerIdentifier, WebCore::ServiceWorkerState state)
        : m_serviceWorkerIdentifier(serviceWorkerIdentifier)
        , m_state(state)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerIdentifier;
        encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerIdentifier& m_serviceWorkerIdentifier;
    WebCore::ServiceWorkerState m_state;
};

class FireUpdateFoundEvent {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_FireUpdateFoundEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FireUpdateFoundEvent(const WebCore::ServiceWorkerRegistrationIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
};

class SetRegistrationLastUpdateTime {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_SetRegistrationLastUpdateTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetRegistrationLastUpdateTime(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, const WallTime& lastUpdateTime)
        : m_identifier(identifier)
        , m_lastUpdateTime(lastUpdateTime)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lastUpdateTime;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_lastUpdateTime;
};

class SetRegistrationUpdateViaCache {
public:
    using Arguments = std::tuple<WebCore::ServiceWorkerRegistrationIdentifier, WebCore::ServiceWorkerUpdateViaCache>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_SetRegistrationUpdateViaCache; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetRegistrationUpdateViaCache(const WebCore::ServiceWorkerRegistrationIdentifier& identifier, WebCore::ServiceWorkerUpdateViaCache updateViaCache)
        : m_identifier(identifier)
        , m_updateViaCache(updateViaCache)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_updateViaCache;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationIdentifier& m_identifier;
    WebCore::ServiceWorkerUpdateViaCache m_updateViaCache;
};

class NotifyClientsOfControllerChange {
public:
    using Arguments = std::tuple<HashSet<WebCore::ScriptExecutionContextIdentifier>, std::optional<WebCore::ServiceWorkerData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_NotifyClientsOfControllerChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyClientsOfControllerChange(const HashSet<WebCore::ScriptExecutionContextIdentifier>& contextIdentifiers, const std::optional<WebCore::ServiceWorkerData>& newController)
        : m_contextIdentifiers(contextIdentifiers)
        , m_newController(newController)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contextIdentifiers;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newController;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<WebCore::ScriptExecutionContextIdentifier>& m_contextIdentifiers;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ServiceWorkerData>& m_newController;
};

class UpdateBackgroundFetchRegistration {
public:
    using Arguments = std::tuple<WebCore::BackgroundFetchInformation>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_UpdateBackgroundFetchRegistration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateBackgroundFetchRegistration(const WebCore::BackgroundFetchInformation& information)
        : m_information(information)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_information;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::BackgroundFetchInformation& m_information;
};

class SetSWOriginTableIsImported {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_SetSWOriginTableIsImported; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetSWOriginTableIsImported()
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetSWOriginTableSharedMemory {
public:
    using Arguments = std::tuple<WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_SetSWOriginTableSharedMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSWOriginTableSharedMemory(WebCore::SharedMemory::Handle&& handle)
        : m_handle(WTFMove(handle))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handle);
    }

private:
    WebCore::SharedMemory::Handle&& m_handle;
};

class PostMessageToServiceWorkerClient {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier, WebCore::MessageWithMessagePorts, WebCore::ServiceWorkerData, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_PostMessageToServiceWorkerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostMessageToServiceWorkerClient(const WebCore::ScriptExecutionContextIdentifier& destinationContextIdentifier, const WebCore::MessageWithMessagePorts& message, const WebCore::ServiceWorkerData& source, const String& sourceOrigin)
        : m_destinationContextIdentifier(destinationContextIdentifier)
        , m_message(message)
        , m_source(source)
        , m_sourceOrigin(sourceOrigin)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_destinationContextIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_source;
        encoder << m_sourceOrigin;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_destinationContextIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessageWithMessagePorts& m_message;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerData& m_source;
    const String& m_sourceOrigin;
};

class SetServiceWorkerClientIsControlled {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier, WebCore::ServiceWorkerRegistrationData>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_SetServiceWorkerClientIsControlled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWClientConnection_SetServiceWorkerClientIsControlledReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    SetServiceWorkerClientIsControlled(const WebCore::ScriptExecutionContextIdentifier& workerIdentifier, const WebCore::ServiceWorkerRegistrationData& data)
        : m_workerIdentifier(workerIdentifier)
        , m_data(data)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_workerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_workerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ServiceWorkerRegistrationData& m_data;
};

class FocusServiceWorkerClient {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_FocusServiceWorkerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebSWClientConnection_FocusServiceWorkerClientReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ServiceWorkerClientData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ServiceWorkerClientData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ServiceWorkerClientData>, IPC::Error>;
    explicit FocusServiceWorkerClient(const WebCore::ScriptExecutionContextIdentifier& clientIdentifier)
        : m_clientIdentifier(clientIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_clientIdentifier;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_clientIdentifier;
};

class NotifyRecordResponseBodyChunk {
public:
    using Arguments = std::tuple<WebKit::RetrieveRecordResponseBodyCallbackIdentifier, IPC::SharedBufferReference>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_NotifyRecordResponseBodyChunk; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyRecordResponseBodyChunk(const WebKit::RetrieveRecordResponseBodyCallbackIdentifier& identifier, const IPC::SharedBufferReference& data)
        : m_identifier(identifier)
        , m_data(data)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RetrieveRecordResponseBodyCallbackIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::SharedBufferReference& m_data;
};

class NotifyRecordResponseBodyEnd {
public:
    using Arguments = std::tuple<WebKit::RetrieveRecordResponseBodyCallbackIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_NotifyRecordResponseBodyEnd; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyRecordResponseBodyEnd(const WebKit::RetrieveRecordResponseBodyCallbackIdentifier& identifier, const WebCore::ResourceError& error)
        : m_identifier(identifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RetrieveRecordResponseBodyCallbackIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

#if ENABLE(CONTENT_EXTENSIONS)
class ReportNetworkUsageToWorkerClient {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebSWClientConnection_ReportNetworkUsageToWorkerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReportNetworkUsageToWorkerClient(const WebCore::ScriptExecutionContextIdentifier& destinationContextIdentifier, uint64_t bytesTransferredOverNetworkDelta)
        : m_destinationContextIdentifier(destinationContextIdentifier)
        , m_bytesTransferredOverNetworkDelta(bytesTransferredOverNetworkDelta)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_destinationContextIdentifier;
        encoder << m_bytesTransferredOverNetworkDelta;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_destinationContextIdentifier;
    uint64_t m_bytesTransferredOverNetworkDelta;
};
#endif

} // namespace WebSWClientConnection
} // namespace Messages
