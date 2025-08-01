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

#if ENABLE(MODEL_PROCESS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
class FloatPoint3D;
struct LayerHostingContextIdentifierType;
using LayerHostingContextIdentifier = ObjectIdentifier<LayerHostingContextIdentifierType>;
class TransformationMatrix;
}

namespace Messages {
namespace ModelProcessModelPlayer {

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
    return IPC::ReceiverName::ModelProcessModelPlayer;
}

class DidCreateLayer {
public:
    using Arguments = std::tuple<WebCore::LayerHostingContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessModelPlayer_DidCreateLayer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidCreateLayer(const WebCore::LayerHostingContextIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LayerHostingContextIdentifier& m_identifier;
};

class DidFinishLoading {
public:
    using Arguments = std::tuple<WebCore::FloatPoint3D, WebCore::FloatPoint3D>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessModelPlayer_DidFinishLoading; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishLoading(const WebCore::FloatPoint3D& center, const WebCore::FloatPoint3D& extents)
        : m_center(center)
        , m_extents(extents)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_center;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_extents;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint3D& m_center;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint3D& m_extents;
};

class DidFailLoading {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessModelPlayer_DidFailLoading; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFailLoading()
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidUpdateEntityTransform {
public:
    using Arguments = std::tuple<WebCore::TransformationMatrix>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessModelPlayer_DidUpdateEntityTransform; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidUpdateEntityTransform(const WebCore::TransformationMatrix& transform)
        : m_transform(transform)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transform;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TransformationMatrix& m_transform;
};

class DidUpdateAnimationPlaybackState {
public:
    using Arguments = std::tuple<bool, double, Seconds, Seconds, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessModelPlayer_DidUpdateAnimationPlaybackState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidUpdateAnimationPlaybackState(bool isPaused, double playbackRate, const Seconds& duration, const Seconds& currentTime, const MonotonicTime& clockTimestamp)
        : m_isPaused(isPaused)
        , m_playbackRate(playbackRate)
        , m_duration(duration)
        , m_currentTime(currentTime)
        , m_clockTimestamp(clockTimestamp)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isPaused;
        encoder << m_playbackRate;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_duration;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_currentTime;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clockTimestamp;
    }

private:
    bool m_isPaused;
    double m_playbackRate;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_duration;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_currentTime;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_clockTimestamp;
};

class DidFinishEnvironmentMapLoading {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessModelPlayer_DidFinishEnvironmentMapLoading; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFinishEnvironmentMapLoading(bool succeeded)
        : m_succeeded(succeeded)
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_succeeded;
    }

private:
    bool m_succeeded;
};

class DidUnload {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::ModelProcessModelPlayer_DidUnload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidUnload()
    {
        ASSERT(isInModelProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

} // namespace ModelProcessModelPlayer
} // namespace Messages

#endif // ENABLE(MODEL_PROCESS)
