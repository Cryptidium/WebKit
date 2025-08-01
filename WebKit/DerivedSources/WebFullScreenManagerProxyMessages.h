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

#if ENABLE(FULLSCREEN_API)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "FullScreenMediaDetails.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
class IntRect;
}

namespace Messages {
namespace WebFullScreenManagerProxy {

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
    return IPC::ReceiverName::WebFullScreenManagerProxy;
}

class EnterFullScreen {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, bool, WebKit::FullScreenMediaDetails>;

    static IPC::MessageName name() { return IPC::MessageName::WebFullScreenManagerProxy_EnterFullScreen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebFullScreenManagerProxy_EnterFullScreenReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    EnterFullScreen(const WebCore::FrameIdentifier& frameID, bool blocksReturnToFullscreenFromPictureInPicture, WebKit::FullScreenMediaDetails&& mediaDetails)
        : m_frameID(frameID)
        , m_blocksReturnToFullscreenFromPictureInPicture(blocksReturnToFullscreenFromPictureInPicture)
        , m_mediaDetails(WTFMove(mediaDetails))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_blocksReturnToFullscreenFromPictureInPicture;
        encoder << WTFMove(m_mediaDetails);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    bool m_blocksReturnToFullscreenFromPictureInPicture;
    WebKit::FullScreenMediaDetails&& m_mediaDetails;
};

#if ENABLE(QUICKLOOK_FULLSCREEN)
class UpdateImageSource {
public:
    using Arguments = std::tuple<WebKit::FullScreenMediaDetails>;

    static IPC::MessageName name() { return IPC::MessageName::WebFullScreenManagerProxy_UpdateImageSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateImageSource(WebKit::FullScreenMediaDetails&& mediaDetails)
        : m_mediaDetails(WTFMove(mediaDetails))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_mediaDetails);
    }

private:
    WebKit::FullScreenMediaDetails&& m_mediaDetails;
};
#endif

class ExitFullScreen {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebFullScreenManagerProxy_ExitFullScreen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebFullScreenManagerProxy_ExitFullScreenReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ExitFullScreen()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class BeganEnterFullScreen {
public:
    using Arguments = std::tuple<WebCore::IntRect, WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebFullScreenManagerProxy_BeganEnterFullScreen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebFullScreenManagerProxy_BeganEnterFullScreenReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    BeganEnterFullScreen(const WebCore::IntRect& initialRect, const WebCore::IntRect& finalRect)
        : m_initialRect(initialRect)
        , m_finalRect(finalRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initialRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_finalRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_initialRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_finalRect;
};

class BeganExitFullScreen {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::IntRect, WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebFullScreenManagerProxy_BeganExitFullScreen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebFullScreenManagerProxy_BeganExitFullScreenReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    BeganExitFullScreen(const WebCore::FrameIdentifier& frameID, const WebCore::IntRect& initialRect, const WebCore::IntRect& finalRect)
        : m_frameID(frameID)
        , m_initialRect(initialRect)
        , m_finalRect(finalRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initialRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_finalRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_initialRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_finalRect;
};

class Close {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebFullScreenManagerProxy_Close; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Close()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

} // namespace WebFullScreenManagerProxy
} // namespace Messages

#endif // ENABLE(FULLSCREEN_API)
