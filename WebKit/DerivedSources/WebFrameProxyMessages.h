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
class SecurityOriginData;
enum class FoundElementInRemoteFrame : bool;
enum class FocusDirection : uint8_t;
struct FocusEventData;
}

namespace Messages {
namespace WebFrameProxy {

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
    return IPC::ReceiverName::WebFrameProxy;
}

class UpdateRemoteFrameSize {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebFrameProxy_UpdateRemoteFrameSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateRemoteFrameSize(const WebCore::IntSize& size)
        : m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_size;
};

class SetAppBadge {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebFrameProxy_SetAppBadge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetAppBadge(const WebCore::SecurityOriginData& origin, const std::optional<uint64_t>& badge)
        : m_origin(origin)
        , m_badge(badge)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_badge;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_badge;
};

class FindFocusableElementDescendingIntoRemoteFrame {
public:
    using Arguments = std::tuple<WebCore::FocusDirection, WebCore::FocusEventData>;

    static IPC::MessageName name() { return IPC::MessageName::WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::FoundElementInRemoteFrame>;
    using Reply = CompletionHandler<void(WebCore::FoundElementInRemoteFrame)>;
    using Promise = WTF::NativePromise<WebCore::FoundElementInRemoteFrame, IPC::Error>;
    FindFocusableElementDescendingIntoRemoteFrame(WebCore::FocusDirection direction, const WebCore::FocusEventData& focusEventData)
        : m_direction(direction)
        , m_focusEventData(focusEventData)
    {
        ASSERT(isInWebProcess());
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

} // namespace WebFrameProxy
} // namespace Messages
