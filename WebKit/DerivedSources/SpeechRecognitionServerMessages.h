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

namespace WebCore {
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
struct SpeechRecognitionConnectionClientIdentifierType;
using SpeechRecognitionConnectionClientIdentifier = ObjectIdentifier<SpeechRecognitionConnectionClientIdentifierType>;
struct ClientOrigin;
}

namespace WebKit {
struct FrameInfoData;
}

namespace Messages {
namespace SpeechRecognitionServer {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(!isInAuxiliaryProcess());
        }
    );
#endif
    return IPC::ReceiverName::SpeechRecognitionServer;
}

class Start {
public:
    using Arguments = std::tuple<WebCore::SpeechRecognitionConnectionClientIdentifier, String, bool, bool, uint64_t, WebCore::ClientOrigin, WebCore::FrameIdentifier, WebKit::FrameInfoData>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionServer_Start; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Start(const WebCore::SpeechRecognitionConnectionClientIdentifier& identifier, const String& lang, bool continuous, bool interimResults, uint64_t maxAlternatives, const WebCore::ClientOrigin& origin, const WebCore::FrameIdentifier& mainFrameIdentifier, const WebKit::FrameInfoData& frameInfo)
        : m_identifier(identifier)
        , m_lang(lang)
        , m_continuous(continuous)
        , m_interimResults(interimResults)
        , m_maxAlternatives(maxAlternatives)
        , m_origin(origin)
        , m_mainFrameIdentifier(mainFrameIdentifier)
        , m_frameInfo(frameInfo)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_lang;
        encoder << m_continuous;
        encoder << m_interimResults;
        encoder << m_maxAlternatives;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mainFrameIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SpeechRecognitionConnectionClientIdentifier& m_identifier;
    const String& m_lang;
    bool m_continuous;
    bool m_interimResults;
    uint64_t m_maxAlternatives;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_mainFrameIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
};

class Stop {
public:
    using Arguments = std::tuple<WebCore::SpeechRecognitionConnectionClientIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionServer_Stop; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit Stop(const WebCore::SpeechRecognitionConnectionClientIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SpeechRecognitionConnectionClientIdentifier& m_identifier;
};

class Abort {
public:
    using Arguments = std::tuple<WebCore::SpeechRecognitionConnectionClientIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionServer_Abort; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit Abort(const WebCore::SpeechRecognitionConnectionClientIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SpeechRecognitionConnectionClientIdentifier& m_identifier;
};

class Invalidate {
public:
    using Arguments = std::tuple<WebCore::SpeechRecognitionConnectionClientIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::SpeechRecognitionServer_Invalidate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit Invalidate(const WebCore::SpeechRecognitionConnectionClientIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SpeechRecognitionConnectionClientIdentifier& m_identifier;
};

} // namespace SpeechRecognitionServer
} // namespace Messages
