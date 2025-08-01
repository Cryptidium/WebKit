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

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
#include "RemoteMediaSourceIdentifier.h"
#endif
#include "SandboxExtension.h"
#include <WebCore/DestinationColorSpace.h>
#include <WebCore/HostingContext.h>
#include <WebCore/TrackBase.h>
#include <wtf/Forward.h>
#include <wtf/MachSendRight.h>
#include <wtf/MediaTime.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class FloatSize;
class IntSize;
class LayoutRect;
class PlatformDynamicRangeLimit;
class SecurityOriginData;
enum class DynamicRangeMode : uint8_t;
enum class InbandTextTrackPrivateMode : uint8_t;
enum class MediaPlayerBufferingPolicy : uint8_t;
enum class MediaPlayerPitchCorrectionAlgorithm : uint8_t;
enum class MediaPlayerPreload : uint8_t;
enum class MediaPlayerSoundStageSize : uint8_t;
enum class MediaPlayerVideoGravity : uint8_t;
struct MediaPlayerLoadOptions;
struct SeekTarget;
}

namespace WebKit {
class MediaPlaybackTargetContextSerialized;
struct RemoteCDMInstanceIdentifierType;
using RemoteCDMInstanceIdentifier = ObjectIdentifier<RemoteCDMInstanceIdentifierType>;
struct RemoteLegacyCDMSessionIdentifierType;
using RemoteLegacyCDMSessionIdentifier = ObjectIdentifier<RemoteLegacyCDMSessionIdentifierType>;
struct RemoteMediaPlayerConfiguration;
struct RemoteVideoFrameProxyProperties;
}

namespace Messages {
namespace RemoteMediaPlayerProxy {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInGPUProcess());
        }
    );
#endif
    return IPC::ReceiverName::RemoteMediaPlayerProxy;
}

class PrepareForPlayback {
public:
    using Arguments = std::tuple<bool, WebCore::MediaPlayerPreload, bool, WebCore::MediaPlayerPitchCorrectionAlgorithm, bool, bool, WebCore::IntSize, float, bool, WebCore::DynamicRangeMode, WebCore::PlatformDynamicRangeLimit>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_PrepareForPlayback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PrepareForPlayback(bool privateMode, WebCore::MediaPlayerPreload preload, bool preservesPitch, WebCore::MediaPlayerPitchCorrectionAlgorithm pitchCorrectionAlgorithm, bool prepareToPlay, bool prepareForRendering, const WebCore::IntSize& presentationSize, float videoContentScale, bool isFullscreen, WebCore::DynamicRangeMode mode, const WebCore::PlatformDynamicRangeLimit& platformDynamicRangeLimit)
        : m_privateMode(privateMode)
        , m_preload(preload)
        , m_preservesPitch(preservesPitch)
        , m_pitchCorrectionAlgorithm(pitchCorrectionAlgorithm)
        , m_prepareToPlay(prepareToPlay)
        , m_prepareForRendering(prepareForRendering)
        , m_presentationSize(presentationSize)
        , m_videoContentScale(videoContentScale)
        , m_isFullscreen(isFullscreen)
        , m_mode(mode)
        , m_platformDynamicRangeLimit(platformDynamicRangeLimit)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_privateMode;
        encoder << m_preload;
        encoder << m_preservesPitch;
        encoder << m_pitchCorrectionAlgorithm;
        encoder << m_prepareToPlay;
        encoder << m_prepareForRendering;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_presentationSize;
        encoder << m_videoContentScale;
        encoder << m_isFullscreen;
        encoder << m_mode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_platformDynamicRangeLimit;
    }

private:
    bool m_privateMode;
    WebCore::MediaPlayerPreload m_preload;
    bool m_preservesPitch;
    WebCore::MediaPlayerPitchCorrectionAlgorithm m_pitchCorrectionAlgorithm;
    bool m_prepareToPlay;
    bool m_prepareForRendering;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_presentationSize;
    float m_videoContentScale;
    bool m_isFullscreen;
    WebCore::DynamicRangeMode m_mode;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PlatformDynamicRangeLimit& m_platformDynamicRangeLimit;
};

class Load {
public:
    using Arguments = std::tuple<URL, std::optional<WebKit::SandboxExtensionHandle>, WebCore::MediaPlayerLoadOptions>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_Load; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaPlayerProxy_LoadReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::RemoteMediaPlayerConfiguration>;
    using Reply = CompletionHandler<void(WebKit::RemoteMediaPlayerConfiguration&&)>;
    using Promise = WTF::NativePromise<WebKit::RemoteMediaPlayerConfiguration, IPC::Error>;
    Load(const URL& url, std::optional<WebKit::SandboxExtensionHandle>&& sandboxExtension, const WebCore::MediaPlayerLoadOptions& options)
        : m_url(url)
        , m_sandboxExtension(WTFMove(sandboxExtension))
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << WTFMove(m_sandboxExtension);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    std::optional<WebKit::SandboxExtensionHandle>&& m_sandboxExtension;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerLoadOptions& m_options;
};

#if ENABLE(MEDIA_SOURCE)
class LoadMediaSource {
public:
    using Arguments = std::tuple<URL, WebCore::MediaPlayerLoadOptions, WebKit::RemoteMediaSourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_LoadMediaSource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaPlayerProxy_LoadMediaSourceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::RemoteMediaPlayerConfiguration>;
    using Reply = CompletionHandler<void(WebKit::RemoteMediaPlayerConfiguration&&)>;
    using Promise = WTF::NativePromise<WebKit::RemoteMediaPlayerConfiguration, IPC::Error>;
    LoadMediaSource(const URL& url, const WebCore::MediaPlayerLoadOptions& options, const WebKit::RemoteMediaSourceIdentifier& mediaSourceIdentifier)
        : m_url(url)
        , m_options(options)
        , m_mediaSourceIdentifier(mediaSourceIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
        encoder << m_mediaSourceIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerLoadOptions& m_options;
    const WebKit::RemoteMediaSourceIdentifier& m_mediaSourceIdentifier;
};
#endif

class CancelLoad {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_CancelLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelLoad()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PrepareToPlay {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_PrepareToPlay; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PrepareToPlay()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Play {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_Play; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Play()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Pause {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_Pause; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Pause()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetVolumeLocked {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetVolumeLocked; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetVolumeLocked(bool volumeLocked)
        : m_volumeLocked(volumeLocked)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_volumeLocked;
    }

private:
    bool m_volumeLocked;
};

class SetVolume {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetVolume; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetVolume(double volume)
        : m_volume(volume)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_volume;
    }

private:
    double m_volume;
};

class SetMuted {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetMuted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMuted(bool muted)
        : m_muted(muted)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_muted;
    }

private:
    bool m_muted;
};

class SeekToTarget {
public:
    using Arguments = std::tuple<WebCore::SeekTarget>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SeekToTarget; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SeekToTarget(const WebCore::SeekTarget& target)
        : m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_target;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SeekTarget& m_target;
};

class SetPreload {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerPreload>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPreload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPreload(WebCore::MediaPlayerPreload preload)
        : m_preload(preload)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_preload;
    }

private:
    WebCore::MediaPlayerPreload m_preload;
};

class SetPrivateBrowsingMode {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPrivateBrowsingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPrivateBrowsingMode(bool privateMode)
        : m_privateMode(privateMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_privateMode;
    }

private:
    bool m_privateMode;
};

class SetPreservesPitch {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPreservesPitch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPreservesPitch(bool preservesPitch)
        : m_preservesPitch(preservesPitch)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_preservesPitch;
    }

private:
    bool m_preservesPitch;
};

class SetPitchCorrectionAlgorithm {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerPitchCorrectionAlgorithm>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPitchCorrectionAlgorithm; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPitchCorrectionAlgorithm(WebCore::MediaPlayerPitchCorrectionAlgorithm algorithm)
        : m_algorithm(algorithm)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_algorithm;
    }

private:
    WebCore::MediaPlayerPitchCorrectionAlgorithm m_algorithm;
};

class PrepareForRendering {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_PrepareForRendering; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PrepareForRendering()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetPageIsVisible {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPageIsVisible; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPageIsVisible(bool visible)
        : m_visible(visible)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_visible;
    }

private:
    bool m_visible;
};

class SetShouldMaintainAspectRatio {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetShouldMaintainAspectRatio; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldMaintainAspectRatio(bool maintainAspectRatio)
        : m_maintainAspectRatio(maintainAspectRatio)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_maintainAspectRatio;
    }

private:
    bool m_maintainAspectRatio;
};

class AcceleratedRenderingStateChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_AcceleratedRenderingStateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AcceleratedRenderingStateChanged(bool canBeAccelerated)
        : m_canBeAccelerated(canBeAccelerated)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_canBeAccelerated;
    }

private:
    bool m_canBeAccelerated;
};

class SetShouldDisableSleep {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetShouldDisableSleep; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldDisableSleep(bool disable)
        : m_disable(disable)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_disable;
    }

private:
    bool m_disable;
};

class SetRate {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetRate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetRate(double rate)
        : m_rate(rate)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_rate;
    }

private:
    double m_rate;
};

class DidLoadingProgress {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_DidLoadingProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaPlayerProxy_DidLoadingProgressReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    DidLoadingProgress()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(VIDEO_PRESENTATION_MODE)
class UpdateVideoFullscreenInlineImage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_UpdateVideoFullscreenInlineImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateVideoFullscreenInlineImage()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(VIDEO_PRESENTATION_MODE)
class SetVideoFullscreenMode {
public:
    using Arguments = std::tuple<WebCore::MediaPlayer::VideoFullscreenMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetVideoFullscreenMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetVideoFullscreenMode(const WebCore::MediaPlayer::VideoFullscreenMode& mode)
        : m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayer::VideoFullscreenMode& m_mode;
};
#endif

#if ENABLE(VIDEO_PRESENTATION_MODE)
class SetVideoFullscreenGravity {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerVideoGravity>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetVideoFullscreenGravity; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetVideoFullscreenGravity(WebCore::MediaPlayerVideoGravity gravity)
        : m_gravity(gravity)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_gravity;
    }

private:
    WebCore::MediaPlayerVideoGravity m_gravity;
};
#endif

#if ENABLE(VIDEO_PRESENTATION_MODE)
class VideoFullscreenStandbyChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_VideoFullscreenStandbyChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit VideoFullscreenStandbyChanged(bool standby)
        : m_standby(standby)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_standby;
    }

private:
    bool m_standby;
};
#endif

class SetBufferingPolicy {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerBufferingPolicy>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetBufferingPolicy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetBufferingPolicy(WebCore::MediaPlayerBufferingPolicy policy)
        : m_policy(policy)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_policy;
    }

private:
    WebCore::MediaPlayerBufferingPolicy m_policy;
};

class SetPresentationSize {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPresentationSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPresentationSize(const WebCore::IntSize& size)
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

#if PLATFORM(COCOA)
class SetVideoLayerSizeFenced {
public:
    using Arguments = std::tuple<WebCore::FloatSize, MachSendRightAnnotated>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetVideoLayerSizeFenced; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetVideoLayerSizeFenced(const WebCore::FloatSize& size, const MachSendRightAnnotated& sendRightAnnotated)
        : m_size(size)
        , m_sendRightAnnotated(sendRightAnnotated)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sendRightAnnotated;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
    SUPPRESS_FORWARD_DECL_MEMBER const MachSendRightAnnotated& m_sendRightAnnotated;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET)
class SetWirelessVideoPlaybackDisabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetWirelessVideoPlaybackDisabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetWirelessVideoPlaybackDisabled(bool disabled)
        : m_disabled(disabled)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_disabled;
    }

private:
    bool m_disabled;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET)
class SetWirelessPlaybackTarget {
public:
    using Arguments = std::tuple<WebKit::MediaPlaybackTargetContextSerialized>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetWirelessPlaybackTarget; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetWirelessPlaybackTarget(const WebKit::MediaPlaybackTargetContextSerialized& target)
        : m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_target;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MediaPlaybackTargetContextSerialized& m_target;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET)
class SetShouldPlayToPlaybackTarget {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetShouldPlayToPlaybackTarget; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldPlayToPlaybackTarget(bool shouldPlay)
        : m_shouldPlay(shouldPlay)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldPlay;
    }

private:
    bool m_shouldPlay;
};
#endif

#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
class SetLegacyCDMSession {
public:
    using Arguments = std::tuple<std::optional<WebKit::RemoteLegacyCDMSessionIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetLegacyCDMSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetLegacyCDMSession(const std::optional<WebKit::RemoteLegacyCDMSessionIdentifier>& instanceId)
        : m_instanceId(instanceId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_instanceId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::RemoteLegacyCDMSessionIdentifier>& m_instanceId;
};
#endif

#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
class KeyAdded {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_KeyAdded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    KeyAdded()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(ENCRYPTED_MEDIA)
class CdmInstanceAttached {
public:
    using Arguments = std::tuple<WebKit::RemoteCDMInstanceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_CdmInstanceAttached; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CdmInstanceAttached(const WebKit::RemoteCDMInstanceIdentifier& instanceId)
        : m_instanceId(instanceId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_instanceId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteCDMInstanceIdentifier& m_instanceId;
};
#endif

#if ENABLE(ENCRYPTED_MEDIA)
class CdmInstanceDetached {
public:
    using Arguments = std::tuple<WebKit::RemoteCDMInstanceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_CdmInstanceDetached; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CdmInstanceDetached(const WebKit::RemoteCDMInstanceIdentifier& instanceId)
        : m_instanceId(instanceId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_instanceId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteCDMInstanceIdentifier& m_instanceId;
};
#endif

#if ENABLE(ENCRYPTED_MEDIA)
class AttemptToDecryptWithInstance {
public:
    using Arguments = std::tuple<WebKit::RemoteCDMInstanceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_AttemptToDecryptWithInstance; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AttemptToDecryptWithInstance(const WebKit::RemoteCDMInstanceIdentifier& instanceId)
        : m_instanceId(instanceId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_instanceId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteCDMInstanceIdentifier& m_instanceId;
};
#endif

#if ENABLE(LEGACY_ENCRYPTED_MEDIA) && ENABLE(ENCRYPTED_MEDIA)
class SetShouldContinueAfterKeyNeeded {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetShouldContinueAfterKeyNeeded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldContinueAfterKeyNeeded(bool should)
        : m_should(should)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_should;
    }

private:
    bool m_should;
};
#endif

class BeginSimulatedHDCPError {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_BeginSimulatedHDCPError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BeginSimulatedHDCPError()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class EndSimulatedHDCPError {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_EndSimulatedHDCPError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EndSimulatedHDCPError()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class NotifyActiveSourceBuffersChanged {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_NotifyActiveSourceBuffersChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyActiveSourceBuffersChanged()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ApplicationWillResignActive {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_ApplicationWillResignActive; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ApplicationWillResignActive()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ApplicationDidBecomeActive {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_ApplicationDidBecomeActive; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ApplicationDidBecomeActive()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class NotifyTrackModeChanged {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_NotifyTrackModeChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyTrackModeChanged()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class TracksChanged {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_TracksChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TracksChanged()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class AudioTrackSetEnabled {
public:
    using Arguments = std::tuple<WebCore::TrackID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_AudioTrackSetEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AudioTrackSetEnabled(WebCore::TrackID trackId, bool enabled)
        : m_trackId(trackId)
        , m_enabled(enabled)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackId;
        encoder << m_enabled;
    }

private:
    WebCore::TrackID m_trackId;
    bool m_enabled;
};

class VideoTrackSetSelected {
public:
    using Arguments = std::tuple<WebCore::TrackID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_VideoTrackSetSelected; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    VideoTrackSetSelected(WebCore::TrackID trackId, bool selected)
        : m_trackId(trackId)
        , m_selected(selected)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackId;
        encoder << m_selected;
    }

private:
    WebCore::TrackID m_trackId;
    bool m_selected;
};

class TextTrackSetMode {
public:
    using Arguments = std::tuple<WebCore::TrackID, WebCore::InbandTextTrackPrivateMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_TextTrackSetMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TextTrackSetMode(WebCore::TrackID trackId, WebCore::InbandTextTrackPrivateMode mode)
        : m_trackId(trackId)
        , m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackId;
        encoder << m_mode;
    }

private:
    WebCore::TrackID m_trackId;
    WebCore::InbandTextTrackPrivateMode m_mode;
};

class PerformTaskAtTime {
public:
    using Arguments = std::tuple<MediaTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_PerformTaskAtTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaPlayerProxy_PerformTaskAtTimeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<MediaTime>>;
    using Reply = CompletionHandler<void(std::optional<MediaTime>&&)>;
    using Promise = WTF::NativePromise<std::optional<MediaTime>, IPC::Error>;
    explicit PerformTaskAtTime(const MediaTime& mediaTime)
        : m_mediaTime(mediaTime)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mediaTime;
    }

private:
    const MediaTime& m_mediaTime;
};

class IsCrossOrigin {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_IsCrossOrigin; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<bool>>;
    using Reply = CompletionHandler<void(std::optional<bool>&&)>;
    explicit IsCrossOrigin(const WebCore::SecurityOriginData& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_origin;
};

class SetVideoPlaybackMetricsUpdateInterval {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetVideoPlaybackMetricsUpdateInterval; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetVideoPlaybackMetricsUpdateInterval(double interval)
        : m_interval(interval)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_interval;
    }

private:
    double m_interval;
};

class SetPreferredDynamicRangeMode {
public:
    using Arguments = std::tuple<WebCore::DynamicRangeMode>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPreferredDynamicRangeMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPreferredDynamicRangeMode(WebCore::DynamicRangeMode mode)
        : m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
    }

private:
    WebCore::DynamicRangeMode m_mode;
};

class SetPlatformDynamicRangeLimit {
public:
    using Arguments = std::tuple<WebCore::PlatformDynamicRangeLimit>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPlatformDynamicRangeLimit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPlatformDynamicRangeLimit(const WebCore::PlatformDynamicRangeLimit& platformDynamicRangeLimit)
        : m_platformDynamicRangeLimit(platformDynamicRangeLimit)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_platformDynamicRangeLimit;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PlatformDynamicRangeLimit& m_platformDynamicRangeLimit;
};

#if PLATFORM(IOS_FAMILY)
class ErrorLog {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_ErrorLog; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    ErrorLog()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class AccessLog {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_AccessLog; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    AccessLog()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetSceneIdentifier {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetSceneIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSceneIdentifier(const String& sceneIdentifier)
        : m_sceneIdentifier(sceneIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sceneIdentifier;
    }

private:
    const String& m_sceneIdentifier;
};
#endif

#if ENABLE(WEB_AUDIO)
class CreateAudioSourceProvider {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_CreateAudioSourceProvider; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateAudioSourceProvider()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(WEB_AUDIO)
class SetShouldEnableAudioSourceProvider {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetShouldEnableAudioSourceProvider; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldEnableAudioSourceProvider(bool shouldEnable)
        : m_shouldEnable(shouldEnable)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldEnable;
    }

private:
    bool m_shouldEnable;
};
#endif

#if PLATFORM(COCOA)
class NativeImageForCurrentTime {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_NativeImageForCurrentTime; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<MachSendRight>, WebCore::DestinationColorSpace>;
    using Reply = CompletionHandler<void(std::optional<MachSendRight>&&, WebCore::DestinationColorSpace&&)>;
    NativeImageForCurrentTime()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class ColorSpace {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_ColorSpace; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DestinationColorSpace>;
    using Reply = CompletionHandler<void(WebCore::DestinationColorSpace&&)>;
    ColorSpace()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class VideoFrameForCurrentTimeIfChanged {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_VideoFrameForCurrentTimeIfChanged; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::RemoteVideoFrameProxyProperties>, bool>;
    using Reply = CompletionHandler<void(std::optional<WebKit::RemoteVideoFrameProxyProperties>&&, bool)>;
    VideoFrameForCurrentTimeIfChanged()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PlayAtHostTime {
public:
    using Arguments = std::tuple<MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_PlayAtHostTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PlayAtHostTime(const MonotonicTime& time)
        : m_time(time)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_time;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_time;
};

class PauseAtHostTime {
public:
    using Arguments = std::tuple<MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_PauseAtHostTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PauseAtHostTime(const MonotonicTime& time)
        : m_time(time)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_time;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_time;
};

class StartVideoFrameMetadataGathering {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_StartVideoFrameMetadataGathering; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartVideoFrameMetadataGathering()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StopVideoFrameMetadataGathering {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_StopVideoFrameMetadataGathering; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopVideoFrameMetadataGathering()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PlayerContentBoxRectChanged {
public:
    using Arguments = std::tuple<WebCore::LayoutRect>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_PlayerContentBoxRectChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PlayerContentBoxRectChanged(const WebCore::LayoutRect& contentRect)
        : m_contentRect(contentRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contentRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LayoutRect& m_contentRect;
};

class SetShouldDisableHDR {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetShouldDisableHDR; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldDisableHDR(bool shouldDisable)
        : m_shouldDisable(shouldDisable)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldDisable;
    }

private:
    bool m_shouldDisable;
};

class RequestHostingContext {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_RequestHostingContext; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaPlayerProxy_RequestHostingContextReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::HostingContext>;
    using Reply = CompletionHandler<void(WebCore::HostingContext&&)>;
    using Promise = WTF::NativePromise<WebCore::HostingContext, IPC::Error>;
    RequestHostingContext()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetShouldCheckHardwareSupport {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetShouldCheckHardwareSupport; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldCheckHardwareSupport(bool value)
        : m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    bool m_value;
};

#if HAVE(SPATIAL_TRACKING_LABEL)
class SetDefaultSpatialTrackingLabel {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetDefaultSpatialTrackingLabel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDefaultSpatialTrackingLabel(const String& defaultSpatialTrackingLabel)
        : m_defaultSpatialTrackingLabel(defaultSpatialTrackingLabel)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_defaultSpatialTrackingLabel;
    }

private:
    const String& m_defaultSpatialTrackingLabel;
};
#endif

#if HAVE(SPATIAL_TRACKING_LABEL)
class SetSpatialTrackingLabel {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetSpatialTrackingLabel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSpatialTrackingLabel(const String& spatialTrackingLabel)
        : m_spatialTrackingLabel(spatialTrackingLabel)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_spatialTrackingLabel;
    }

private:
    const String& m_spatialTrackingLabel;
};
#endif

#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
class SetPrefersSpatialAudioExperience {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetPrefersSpatialAudioExperience; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPrefersSpatialAudioExperience(bool value)
        : m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    bool m_value;
};
#endif

class AudioOutputDeviceChanged {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_AudioOutputDeviceChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AudioOutputDeviceChanged(const String& deviceId)
        : m_deviceId(deviceId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_deviceId;
    }

private:
    const String& m_deviceId;
};

class IsInFullscreenOrPictureInPictureChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_IsInFullscreenOrPictureInPictureChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit IsInFullscreenOrPictureInPictureChanged(bool value)
        : m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    bool m_value;
};

class SetSoundStageSize {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerSoundStageSize>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetSoundStageSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSoundStageSize(WebCore::MediaPlayerSoundStageSize value)
        : m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    WebCore::MediaPlayerSoundStageSize m_value;
};

class SetHasMessageClientForTesting {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaPlayerProxy_SetHasMessageClientForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasMessageClientForTesting(bool value)
        : m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    bool m_value;
};

} // namespace RemoteMediaPlayerProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
