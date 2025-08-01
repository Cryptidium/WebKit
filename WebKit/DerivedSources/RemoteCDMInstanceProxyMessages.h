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

#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/Ref.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
enum class CDMInstanceAllowDistinctiveIdentifiers : bool;
enum class CDMInstanceAllowPersistentState : bool;
enum class CDMInstanceSuccessValue : bool;
struct CDMKeySystemConfiguration;
}

namespace WebKit {
struct RemoteCDMInstanceSessionIdentifierType;
using RemoteCDMInstanceSessionIdentifier = ObjectIdentifier<RemoteCDMInstanceSessionIdentifierType>;
}

namespace Messages {
namespace RemoteCDMInstanceProxy {

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
    return IPC::ReceiverName::RemoteCDMInstanceProxy;
}

class CreateSession {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceProxy_CreateSession; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::RemoteCDMInstanceSessionIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::RemoteCDMInstanceSessionIdentifier>&&)>;
    explicit CreateSession(uint64_t logIdentifier)
        : m_logIdentifier(logIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_logIdentifier;
    }

private:
    uint64_t m_logIdentifier;
};

class InitializeWithConfiguration {
public:
    using Arguments = std::tuple<WebCore::CDMKeySystemConfiguration, WebCore::CDMInstanceAllowDistinctiveIdentifiers, WebCore::CDMInstanceAllowPersistentState>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceProxy_InitializeWithConfiguration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteCDMInstanceProxy_InitializeWithConfigurationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::CDMInstanceSuccessValue>;
    using Reply = CompletionHandler<void(WebCore::CDMInstanceSuccessValue)>;
    using Promise = WTF::NativePromise<WebCore::CDMInstanceSuccessValue, IPC::Error>;
    InitializeWithConfiguration(const WebCore::CDMKeySystemConfiguration& configuration, WebCore::CDMInstanceAllowDistinctiveIdentifiers distinctiveIdentifiersAllowed, WebCore::CDMInstanceAllowPersistentState persistentStateAllowed)
        : m_configuration(configuration)
        , m_distinctiveIdentifiersAllowed(distinctiveIdentifiersAllowed)
        , m_persistentStateAllowed(persistentStateAllowed)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
        encoder << m_distinctiveIdentifiersAllowed;
        encoder << m_persistentStateAllowed;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CDMKeySystemConfiguration& m_configuration;
    WebCore::CDMInstanceAllowDistinctiveIdentifiers m_distinctiveIdentifiersAllowed;
    WebCore::CDMInstanceAllowPersistentState m_persistentStateAllowed;
};

class SetServerCertificate {
public:
    using Arguments = std::tuple<Ref<WebCore::SharedBuffer>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceProxy_SetServerCertificate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteCDMInstanceProxy_SetServerCertificateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::CDMInstanceSuccessValue>;
    using Reply = CompletionHandler<void(WebCore::CDMInstanceSuccessValue)>;
    using Promise = WTF::NativePromise<WebCore::CDMInstanceSuccessValue, IPC::Error>;
    explicit SetServerCertificate(const Ref<WebCore::SharedBuffer>& certificate)
        : m_certificate(certificate)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_certificate;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::SharedBuffer>& m_certificate;
};

class SetStorageDirectory {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceProxy_SetStorageDirectory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetStorageDirectory(const String& directory)
        : m_directory(directory)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_directory;
    }

private:
    const String& m_directory;
};

} // namespace RemoteCDMInstanceProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
