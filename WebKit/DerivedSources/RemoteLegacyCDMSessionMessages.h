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

#if ENABLE(GPU_PROCESS) && ENABLE(LEGACY_ENCRYPTED_MEDIA)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <WebCore/LegacyCDMSession.h>
#include <wtf/Forward.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>


namespace Messages {
namespace RemoteLegacyCDMSession {

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
    return IPC::ReceiverName::RemoteLegacyCDMSession;
}

class SendMessage {
public:
    using Arguments = std::tuple<RefPtr<WebCore::SharedBuffer>, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMSession_SendMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SendMessage(const RefPtr<WebCore::SharedBuffer>& message, const String& destinationURL)
        : m_message(message)
        , m_destinationURL(destinationURL)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
        encoder << m_destinationURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::SharedBuffer>& m_message;
    const String& m_destinationURL;
};

class SendError {
public:
    using Arguments = std::tuple<WebCore::LegacyCDMSessionClient::MediaKeyErrorCode, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMSession_SendError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SendError(const WebCore::LegacyCDMSessionClient::MediaKeyErrorCode& errorCode, uint32_t systemCode)
        : m_errorCode(errorCode)
        , m_systemCode(systemCode)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_errorCode;
        encoder << m_systemCode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LegacyCDMSessionClient::MediaKeyErrorCode& m_errorCode;
    uint32_t m_systemCode;
};

} // namespace RemoteLegacyCDMSession
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(LEGACY_ENCRYPTED_MEDIA)
