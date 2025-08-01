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
#include <WebCore/RTCDataChannelIdentifier.h>
#include <span>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
enum class RTCDataChannelState : uint8_t;
enum class RTCErrorDetailType : uint8_t;
}

namespace Messages {
namespace RTCDataChannelRemoteManager {

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
    return IPC::ReceiverName::RTCDataChannelRemoteManager;
}

class SendData {
public:
    using Arguments = std::tuple<WebCore::RTCDataChannelIdentifier, bool, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RTCDataChannelRemoteManager_SendData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SendData(const WebCore::RTCDataChannelIdentifier& source, bool isRaw, const std::span<const uint8_t>& text)
        : m_source(source)
        , m_isRaw(isRaw)
        , m_text(text)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_source;
        encoder << m_isRaw;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_text;
    }

private:
    const WebCore::RTCDataChannelIdentifier& m_source;
    bool m_isRaw;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_text;
};

class Close {
public:
    using Arguments = std::tuple<WebCore::RTCDataChannelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RTCDataChannelRemoteManager_Close; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit Close(const WebCore::RTCDataChannelIdentifier& source)
        : m_source(source)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_source;
    }

private:
    const WebCore::RTCDataChannelIdentifier& m_source;
};

class ChangeReadyState {
public:
    using Arguments = std::tuple<WebCore::RTCDataChannelIdentifier, WebCore::RTCDataChannelState>;

    static IPC::MessageName name() { return IPC::MessageName::RTCDataChannelRemoteManager_ChangeReadyState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ChangeReadyState(const WebCore::RTCDataChannelIdentifier& handler, WebCore::RTCDataChannelState state)
        : m_handler(handler)
        , m_state(state)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_handler;
        encoder << m_state;
    }

private:
    const WebCore::RTCDataChannelIdentifier& m_handler;
    WebCore::RTCDataChannelState m_state;
};

class ReceiveData {
public:
    using Arguments = std::tuple<WebCore::RTCDataChannelIdentifier, bool, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::RTCDataChannelRemoteManager_ReceiveData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReceiveData(const WebCore::RTCDataChannelIdentifier& handler, bool isRaw, const std::span<const uint8_t>& data)
        : m_handler(handler)
        , m_isRaw(isRaw)
        , m_data(data)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_handler;
        encoder << m_isRaw;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    const WebCore::RTCDataChannelIdentifier& m_handler;
    bool m_isRaw;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class DetectError {
public:
    using Arguments = std::tuple<WebCore::RTCDataChannelIdentifier, WebCore::RTCErrorDetailType, String>;

    static IPC::MessageName name() { return IPC::MessageName::RTCDataChannelRemoteManager_DetectError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DetectError(const WebCore::RTCDataChannelIdentifier& handler, WebCore::RTCErrorDetailType type, const String& message)
        : m_handler(handler)
        , m_type(type)
        , m_message(message)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_handler;
        encoder << m_type;
        encoder << m_message;
    }

private:
    const WebCore::RTCDataChannelIdentifier& m_handler;
    WebCore::RTCErrorDetailType m_type;
    const String& m_message;
};

class BufferedAmountIsDecreasing {
public:
    using Arguments = std::tuple<WebCore::RTCDataChannelIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::RTCDataChannelRemoteManager_BufferedAmountIsDecreasing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BufferedAmountIsDecreasing(const WebCore::RTCDataChannelIdentifier& handler, uint64_t amount)
        : m_handler(handler)
        , m_amount(amount)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_handler;
        encoder << m_amount;
    }

private:
    const WebCore::RTCDataChannelIdentifier& m_handler;
    uint64_t m_amount;
};

} // namespace RTCDataChannelRemoteManager
} // namespace Messages

#endif // ENABLE(WEB_RTC)
