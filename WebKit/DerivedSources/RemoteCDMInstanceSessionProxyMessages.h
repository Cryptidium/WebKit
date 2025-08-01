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
#include <utility>
#include <wtf/Forward.h>
#include <wtf/Ref.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
enum class CDMKeyGroupingStrategy : bool;
enum class CDMInstanceSessionLoadFailure : uint8_t;
enum class CDMSessionType : uint8_t;
}

namespace Messages {
namespace RemoteCDMInstanceSessionProxy {

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
    return IPC::ReceiverName::RemoteCDMInstanceSessionProxy;
}

class SetLogIdentifier {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_SetLogIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetLogIdentifier(uint64_t logIdentifier)
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

class RequestLicense {
public:
    using Arguments = std::tuple<WebCore::CDMSessionType, WebCore::CDMKeyGroupingStrategy, AtomString, RefPtr<WebCore::SharedBuffer>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_RequestLicense; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_RequestLicenseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>, String, bool, bool>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&, String&&, bool, bool)>;
    using Promise = WTF::NativePromise<std::tuple<RefPtr<WebCore::SharedBuffer>, String, bool, bool>, IPC::Error>;
    RequestLicense(WebCore::CDMSessionType type, WebCore::CDMKeyGroupingStrategy keyGroupingStrategy, const AtomString& initDataType, const RefPtr<WebCore::SharedBuffer>& initData)
        : m_type(type)
        , m_keyGroupingStrategy(keyGroupingStrategy)
        , m_initDataType(initDataType)
        , m_initData(initData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        encoder << m_keyGroupingStrategy;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initDataType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initData;
    }

private:
    WebCore::CDMSessionType m_type;
    WebCore::CDMKeyGroupingStrategy m_keyGroupingStrategy;
    SUPPRESS_FORWARD_DECL_MEMBER const AtomString& m_initDataType;
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::SharedBuffer>& m_initData;
};

class UpdateLicense {
public:
    using Arguments = std::tuple<String, WebCore::CDMSessionType, RefPtr<WebCore::SharedBuffer>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_UpdateLicense; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_UpdateLicenseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, std::optional<Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>>, std::optional<double>, std::optional<std::pair<WebCore::CDMMessageType, Ref<WebCore::SharedBuffer>>>, bool>;
    using Reply = CompletionHandler<void(bool, std::optional<Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>>&&, std::optional<double>&&, std::optional<std::pair<WebCore::CDMMessageType, Ref<WebCore::SharedBuffer>>>&&, bool)>;
    using Promise = WTF::NativePromise<std::tuple<bool, std::optional<Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>>, std::optional<double>, std::optional<std::pair<WebCore::CDMMessageType, Ref<WebCore::SharedBuffer>>>, bool>, IPC::Error>;
    UpdateLicense(const String& sessionId, WebCore::CDMSessionType type, const RefPtr<WebCore::SharedBuffer>& response)
        : m_sessionId(sessionId)
        , m_type(type)
        , m_response(response)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sessionId;
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    const String& m_sessionId;
    WebCore::CDMSessionType m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::SharedBuffer>& m_response;
};

class LoadSession {
public:
    using Arguments = std::tuple<WebCore::CDMSessionType, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_LoadSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_LoadSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>>, std::optional<double>, std::optional<std::pair<WebCore::CDMMessageType, Ref<WebCore::SharedBuffer>>>, bool, WebCore::CDMInstanceSessionLoadFailure>;
    using Reply = CompletionHandler<void(std::optional<Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>>&&, std::optional<double>&&, std::optional<std::pair<WebCore::CDMMessageType, Ref<WebCore::SharedBuffer>>>&&, bool, WebCore::CDMInstanceSessionLoadFailure)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>>, std::optional<double>, std::optional<std::pair<WebCore::CDMMessageType, Ref<WebCore::SharedBuffer>>>, bool, WebCore::CDMInstanceSessionLoadFailure>, IPC::Error>;
    LoadSession(WebCore::CDMSessionType type, const String& sessionId, const String& origin)
        : m_type(type)
        , m_sessionId(sessionId)
        , m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        encoder << m_sessionId;
        encoder << m_origin;
    }

private:
    WebCore::CDMSessionType m_type;
    const String& m_sessionId;
    const String& m_origin;
};

class CloseSession {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_CloseSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_CloseSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit CloseSession(const String& sessionId)
        : m_sessionId(sessionId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sessionId;
    }

private:
    const String& m_sessionId;
};

class RemoveSessionData {
public:
    using Arguments = std::tuple<String, WebCore::CDMSessionType>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_RemoveSessionData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_RemoveSessionDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>, RefPtr<WebCore::SharedBuffer>, bool>;
    using Reply = CompletionHandler<void(Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>&&, RefPtr<WebCore::SharedBuffer>&&, bool)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<std::pair<Ref<WebCore::SharedBuffer>, WebCore::CDMKeyStatus>>, RefPtr<WebCore::SharedBuffer>, bool>, IPC::Error>;
    RemoveSessionData(const String& sessionId, WebCore::CDMSessionType type)
        : m_sessionId(sessionId)
        , m_type(type)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sessionId;
        encoder << m_type;
    }

private:
    const String& m_sessionId;
    WebCore::CDMSessionType m_type;
};

class StoreRecordOfKeyUsage {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteCDMInstanceSessionProxy_StoreRecordOfKeyUsage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StoreRecordOfKeyUsage(const String& sessionId)
        : m_sessionId(sessionId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sessionId;
    }

private:
    const String& m_sessionId;
};

} // namespace RemoteCDMInstanceSessionProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
