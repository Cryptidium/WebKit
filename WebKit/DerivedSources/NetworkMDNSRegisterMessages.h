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

#if ENABLE(WEB_RTC)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <WebCore/ProcessQualified.h>
#include <WebCore/ScriptExecutionContextIdentifier.h>
#include <wtf/Forward.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
enum class MDNSRegisterError : uint8_t;
}

namespace Messages {
namespace NetworkMDNSRegister {

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
    return IPC::ReceiverName::NetworkMDNSRegister;
}

class UnregisterMDNSNames {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkMDNSRegister_UnregisterMDNSNames; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UnregisterMDNSNames(const WebCore::ScriptExecutionContextIdentifier& documentIdentifier)
        : m_documentIdentifier(documentIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_documentIdentifier;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_documentIdentifier;
};

class RegisterMDNSName {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkMDNSRegister_RegisterMDNSName; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkMDNSRegister_RegisterMDNSNameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, std::optional<WebCore::MDNSRegisterError>>;
    using Reply = CompletionHandler<void(String&&, std::optional<WebCore::MDNSRegisterError>)>;
    using Promise = WTF::NativePromise<std::tuple<String, std::optional<WebCore::MDNSRegisterError>>, IPC::Error>;
    RegisterMDNSName(const WebCore::ScriptExecutionContextIdentifier& documentIdentifier, const String& ipAddress)
        : m_documentIdentifier(documentIdentifier)
        , m_ipAddress(ipAddress)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_documentIdentifier;
        encoder << m_ipAddress;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_documentIdentifier;
    const String& m_ipAddress;
};

} // namespace NetworkMDNSRegister
} // namespace Messages

#endif // ENABLE(WEB_RTC)
