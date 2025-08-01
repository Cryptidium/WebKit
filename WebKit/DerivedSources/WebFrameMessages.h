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

namespace WebCore {
class IntSize;
enum class FoundElementInRemoteFrame : bool;
enum class FocusDirection : uint8_t;
struct FocusEventData;
}

namespace WebKit {
struct FrameInfoData;
struct ProvisionalFrameCreationParameters;
}

namespace Messages {
namespace WebFrame {

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
    return IPC::ReceiverName::WebFrame;
}

class GetFrameInfo {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebFrame_GetFrameInfo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebFrame_GetFrameInfoReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::FrameInfoData>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::FrameInfoData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::FrameInfoData>, IPC::Error>;
    GetFrameInfo()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class UpdateFrameSize {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebFrame_UpdateFrameSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateFrameSize(const WebCore::IntSize& newSize)
        : m_newSize(newSize)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_newSize;
};

class CreateProvisionalFrame {
public:
    using Arguments = std::tuple<WebKit::ProvisionalFrameCreationParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebFrame_CreateProvisionalFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CreateProvisionalFrame(const WebKit::ProvisionalFrameCreationParameters& creationParameters)
        : m_creationParameters(creationParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_creationParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ProvisionalFrameCreationParameters& m_creationParameters;
};

class DestroyProvisionalFrame {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebFrame_DestroyProvisionalFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DestroyProvisionalFrame()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class FindFocusableElementDescendingIntoRemoteFrame {
public:
    using Arguments = std::tuple<WebCore::FocusDirection, WebCore::FocusEventData>;

    static IPC::MessageName name() { return IPC::MessageName::WebFrame_FindFocusableElementDescendingIntoRemoteFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebFrame_FindFocusableElementDescendingIntoRemoteFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::FoundElementInRemoteFrame>;
    using Reply = CompletionHandler<void(WebCore::FoundElementInRemoteFrame)>;
    using Promise = WTF::NativePromise<WebCore::FoundElementInRemoteFrame, IPC::Error>;
    FindFocusableElementDescendingIntoRemoteFrame(WebCore::FocusDirection direction, const WebCore::FocusEventData& focusEventData)
        : m_direction(direction)
        , m_focusEventData(focusEventData)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_direction;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_focusEventData;
    }

private:
    WebCore::FocusDirection m_direction;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FocusEventData& m_focusEventData;
};

} // namespace WebFrame
} // namespace Messages
