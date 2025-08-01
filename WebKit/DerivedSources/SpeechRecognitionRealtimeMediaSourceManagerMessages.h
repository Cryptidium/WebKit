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

#if ENABLE(MEDIA_STREAM)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
class CaptureDevice;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct RealtimeMediaSourceIdentifierType;
using RealtimeMediaSourceIdentifier = ObjectIdentifier<RealtimeMediaSourceIdentifierType>;
}

namespace Messages {
namespace SpeechRecognitionRealtimeMediaSourceManager {

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
    return IPC::ReceiverName::SpeechRecognitionRealtimeMediaSourceManager;
}

class CreateSource {
public:
    using Arguments = std::tuple<WebCore::RealtimeMediaSourceIdentifier, WebCore::CaptureDevice, WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionRealtimeMediaSourceManager_CreateSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateSource(const WebCore::RealtimeMediaSourceIdentifier& identifier, const WebCore::CaptureDevice& device, const WebCore::PageIdentifier& pageIdentifier)
        : m_identifier(identifier)
        , m_device(device)
        , m_pageIdentifier(pageIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_device;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RealtimeMediaSourceIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CaptureDevice& m_device;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageIdentifier;
};

class DeleteSource {
public:
    using Arguments = std::tuple<WebCore::RealtimeMediaSourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionRealtimeMediaSourceManager_DeleteSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DeleteSource(const WebCore::RealtimeMediaSourceIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RealtimeMediaSourceIdentifier& m_identifier;
};

class Start {
public:
    using Arguments = std::tuple<WebCore::RealtimeMediaSourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionRealtimeMediaSourceManager_Start; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit Start(const WebCore::RealtimeMediaSourceIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RealtimeMediaSourceIdentifier& m_identifier;
};

class Stop {
public:
    using Arguments = std::tuple<WebCore::RealtimeMediaSourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionRealtimeMediaSourceManager_Stop; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit Stop(const WebCore::RealtimeMediaSourceIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RealtimeMediaSourceIdentifier& m_identifier;
};

} // namespace SpeechRecognitionRealtimeMediaSourceManager
} // namespace Messages

#endif // ENABLE(MEDIA_STREAM)
