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
#include <WebCore/RectEdges.h>
#include <WebCore/ScrollTypes.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct DisplayUpdate;
struct RemoteUserInputEventData;
}

namespace WebKit {
class ScrollingAccelerationCurve;
class WebGestureEvent;
class WebTouchEvent;
class WebWheelEvent;
enum class WebEventType : uint8_t;
struct RemoteWebTouchEvent;
}

namespace Messages {
namespace EventDispatcher {

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
    return IPC::ReceiverName::EventDispatcher;
}

class WheelEvent {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, WebKit::WebWheelEvent, WebCore::RectEdges<WebCore::RubberBandingBehavior>>;

    static IPC::MessageName name() { return IPC::MessageName::EventDispatcher_WheelEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WheelEvent(const WebCore::PageIdentifier& pageID, const WebKit::WebWheelEvent& event, const WebCore::RectEdges<WebCore::RubberBandingBehavior>& rubberBandableEdges)
        : m_pageID(pageID)
        , m_event(event)
        , m_rubberBandableEdges(rubberBandableEdges)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rubberBandableEdges;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebWheelEvent& m_event;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RectEdges<WebCore::RubberBandingBehavior>& m_rubberBandableEdges;
};

#if ENABLE(IOS_TOUCH_EVENTS)
class TouchEvent {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, WebCore::FrameIdentifier, WebKit::WebTouchEvent>;

    static IPC::MessageName name() { return IPC::MessageName::EventDispatcher_TouchEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::EventDispatcher_TouchEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::MainThread;
    using ReplyArguments = std::tuple<bool, std::optional<WebKit::RemoteWebTouchEvent>>;
    using Reply = CompletionHandler<void(bool, std::optional<WebKit::RemoteWebTouchEvent>&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, std::optional<WebKit::RemoteWebTouchEvent>>, IPC::Error>;
    TouchEvent(const WebCore::PageIdentifier& pageID, const WebCore::FrameIdentifier& frameID, const WebKit::WebTouchEvent& event)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_event(event)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebTouchEvent& m_event;
};
#endif

#if ENABLE(MAC_GESTURE_EVENTS)
class GestureEvent {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::PageIdentifier, WebKit::WebGestureEvent>;

    static IPC::MessageName name() { return IPC::MessageName::EventDispatcher_GestureEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::EventDispatcher_GestureEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::MainThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::WebEventType>, bool, std::optional<WebCore::RemoteUserInputEventData>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::WebEventType>, bool, std::optional<WebCore::RemoteUserInputEventData>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebKit::WebEventType>, bool, std::optional<WebCore::RemoteUserInputEventData>>, IPC::Error>;
    GestureEvent(const WebCore::FrameIdentifier& frameID, const WebCore::PageIdentifier& pageID, const WebKit::WebGestureEvent& event)
        : m_frameID(frameID)
        , m_pageID(pageID)
        , m_event(event)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGestureEvent& m_event;
};
#endif

#if HAVE(DISPLAY_LINK)
class DisplayDidRefresh {
public:
    using Arguments = std::tuple<uint32_t, WebCore::DisplayUpdate, bool>;

    static IPC::MessageName name() { return IPC::MessageName::EventDispatcher_DisplayDidRefresh; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DisplayDidRefresh(uint32_t displayID, const WebCore::DisplayUpdate& update, bool sendToMainThread)
        : m_displayID(displayID)
        , m_update(update)
        , m_sendToMainThread(sendToMainThread)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_displayID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_update;
        encoder << m_sendToMainThread;
    }

private:
    uint32_t m_displayID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DisplayUpdate& m_update;
    bool m_sendToMainThread;
};
#endif

#if ENABLE(MOMENTUM_EVENT_DISPATCHER)
class SetScrollingAccelerationCurve {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebKit::ScrollingAccelerationCurve>>;

    static IPC::MessageName name() { return IPC::MessageName::EventDispatcher_SetScrollingAccelerationCurve; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetScrollingAccelerationCurve(const WebCore::PageIdentifier& pageID, const std::optional<WebKit::ScrollingAccelerationCurve>& curve)
        : m_pageID(pageID)
        , m_curve(curve)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_curve;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::ScrollingAccelerationCurve>& m_curve;
};
#endif

class PageScreenDidChange {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, uint32_t, std::optional<unsigned>>;

    static IPC::MessageName name() { return IPC::MessageName::EventDispatcher_PageScreenDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PageScreenDidChange(const WebCore::PageIdentifier& pageID, uint32_t displayID, const std::optional<unsigned>& nominalFramesPerSecond)
        : m_pageID(pageID)
        , m_displayID(displayID)
        , m_nominalFramesPerSecond(nominalFramesPerSecond)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_displayID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nominalFramesPerSecond;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    uint32_t m_displayID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<unsigned>& m_nominalFramesPerSecond;
};

} // namespace EventDispatcher
} // namespace Messages
