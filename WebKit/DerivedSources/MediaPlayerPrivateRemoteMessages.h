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
#include <WebCore/HostingContext.h>
#include <WebCore/TrackBase.h>
#include <span>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/MediaTime.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/Seconds.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class FloatSize;
class ISOWebVTTCue;
class ResourceRequest;
class SerializedPlatformDataCueValue;
enum class MediaPlayerReadyState : uint8_t;
struct GenericCueData;
struct MessageForTesting;
struct VideoFrameMetadata;
struct VideoPlaybackQualityMetrics;
}

namespace WebKit {
struct RemoteMediaResourceIdentifierType;
using RemoteMediaResourceIdentifier = ObjectIdentifier<RemoteMediaResourceIdentifierType>;
struct AudioTrackPrivateRemoteConfiguration;
struct MediaTimeUpdateData;
struct RemoteMediaPlayerState;
struct RemoteVideoFrameProxyProperties;
struct TextTrackPrivateRemoteConfiguration;
struct VideoTrackPrivateRemoteConfiguration;
}

namespace Messages {
namespace MediaPlayerPrivateRemote {

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
    return IPC::ReceiverName::MediaPlayerPrivateRemote;
}

class NetworkStateChanged {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaPlayerState>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_NetworkStateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit NetworkStateChanged(const WebKit::RemoteMediaPlayerState& state)
        : m_state(state)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaPlayerState& m_state;
};

class ReadyStateChanged {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaPlayerState, WebCore::MediaPlayerReadyState>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_ReadyStateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReadyStateChanged(const WebKit::RemoteMediaPlayerState& state, WebCore::MediaPlayerReadyState readyStat)
        : m_state(state)
        , m_readyStat(readyStat)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
        encoder << m_readyStat;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaPlayerState& m_state;
    WebCore::MediaPlayerReadyState m_readyStat;
};

class FirstVideoFrameAvailable {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_FirstVideoFrameAvailable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FirstVideoFrameAvailable()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class VolumeChanged {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_VolumeChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit VolumeChanged(double volume)
        : m_volume(volume)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_volume;
    }

private:
    double m_volume;
};

class MuteChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_MuteChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MuteChanged(bool mute)
        : m_mute(mute)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mute;
    }

private:
    bool m_mute;
};

class Seeked {
public:
    using Arguments = std::tuple<WebKit::MediaTimeUpdateData>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_Seeked; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit Seeked(const WebKit::MediaTimeUpdateData& timeData)
        : m_timeData(timeData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timeData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MediaTimeUpdateData& m_timeData;
};

class TimeChanged {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaPlayerState, WebKit::MediaTimeUpdateData>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_TimeChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TimeChanged(const WebKit::RemoteMediaPlayerState& state, const WebKit::MediaTimeUpdateData& timeData)
        : m_state(state)
        , m_timeData(timeData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timeData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaPlayerState& m_state;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MediaTimeUpdateData& m_timeData;
};

class DurationChanged {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaPlayerState>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_DurationChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DurationChanged(const WebKit::RemoteMediaPlayerState& state)
        : m_state(state)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaPlayerState& m_state;
};

class RateChanged {
public:
    using Arguments = std::tuple<double, WebKit::MediaTimeUpdateData>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RateChanged(double rate, const WebKit::MediaTimeUpdateData& timeData)
        : m_rate(rate)
        , m_timeData(timeData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_rate;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timeData;
    }

private:
    double m_rate;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MediaTimeUpdateData& m_timeData;
};

class PlaybackStateChanged {
public:
    using Arguments = std::tuple<bool, WebKit::MediaTimeUpdateData>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_PlaybackStateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PlaybackStateChanged(bool paused, const WebKit::MediaTimeUpdateData& timeData)
        : m_paused(paused)
        , m_timeData(timeData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_paused;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timeData;
    }

private:
    bool m_paused;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MediaTimeUpdateData& m_timeData;
};

class EngineFailedToLoad {
public:
    using Arguments = std::tuple<int64_t>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_EngineFailedToLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit EngineFailedToLoad(int64_t platformErrorCode)
        : m_platformErrorCode(platformErrorCode)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_platformErrorCode;
    }

private:
    int64_t m_platformErrorCode;
};

class UpdateCachedState {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaPlayerState>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_UpdateCachedState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateCachedState(const WebKit::RemoteMediaPlayerState& state)
        : m_state(state)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaPlayerState& m_state;
};

class UpdatePlaybackQualityMetrics {
public:
    using Arguments = std::tuple<WebCore::VideoPlaybackQualityMetrics>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_UpdatePlaybackQualityMetrics; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdatePlaybackQualityMetrics(const WebCore::VideoPlaybackQualityMetrics& metrics)
        : m_metrics(metrics)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_metrics;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::VideoPlaybackQualityMetrics& m_metrics;
};

class CharacteristicChanged {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaPlayerState>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_CharacteristicChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CharacteristicChanged(const WebKit::RemoteMediaPlayerState& state)
        : m_state(state)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaPlayerState& m_state;
};

class SizeChanged {
public:
    using Arguments = std::tuple<WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_SizeChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SizeChanged(const WebCore::FloatSize& naturalSize)
        : m_naturalSize(naturalSize)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_naturalSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_naturalSize;
};

class RenderingModeChanged {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RenderingModeChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RenderingModeChanged()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CurrentTimeChanged {
public:
    using Arguments = std::tuple<WebKit::MediaTimeUpdateData>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_CurrentTimeChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CurrentTimeChanged(const WebKit::MediaTimeUpdateData& timeData)
        : m_timeData(timeData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timeData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MediaTimeUpdateData& m_timeData;
};

class AddRemoteAudioTrack {
public:
    using Arguments = std::tuple<WebKit::AudioTrackPrivateRemoteConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_AddRemoteAudioTrack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddRemoteAudioTrack(const WebKit::AudioTrackPrivateRemoteConfiguration& configuration)
        : m_configuration(configuration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AudioTrackPrivateRemoteConfiguration& m_configuration;
};

class RemoveRemoteAudioTrack {
public:
    using Arguments = std::tuple<WebCore::TrackID>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoveRemoteAudioTrack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveRemoteAudioTrack(WebCore::TrackID trackID)
        : m_trackID(trackID)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
    }

private:
    WebCore::TrackID m_trackID;
};

class RemoteAudioTrackConfigurationChanged {
public:
    using Arguments = std::tuple<WebCore::TrackID, WebKit::AudioTrackPrivateRemoteConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoteAudioTrackConfigurationChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoteAudioTrackConfigurationChanged(WebCore::TrackID trackID, const WebKit::AudioTrackPrivateRemoteConfiguration& configuration)
        : m_trackID(trackID)
        , m_configuration(configuration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    WebCore::TrackID m_trackID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AudioTrackPrivateRemoteConfiguration& m_configuration;
};

class AddRemoteVideoTrack {
public:
    using Arguments = std::tuple<WebKit::VideoTrackPrivateRemoteConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_AddRemoteVideoTrack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddRemoteVideoTrack(const WebKit::VideoTrackPrivateRemoteConfiguration& configuration)
        : m_configuration(configuration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoTrackPrivateRemoteConfiguration& m_configuration;
};

class RemoveRemoteVideoTrack {
public:
    using Arguments = std::tuple<WebCore::TrackID>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoveRemoteVideoTrack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveRemoteVideoTrack(WebCore::TrackID trackID)
        : m_trackID(trackID)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
    }

private:
    WebCore::TrackID m_trackID;
};

class RemoteVideoTrackConfigurationChanged {
public:
    using Arguments = std::tuple<WebCore::TrackID, WebKit::VideoTrackPrivateRemoteConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoteVideoTrackConfigurationChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoteVideoTrackConfigurationChanged(WebCore::TrackID trackID, const WebKit::VideoTrackPrivateRemoteConfiguration& configuration)
        : m_trackID(trackID)
        , m_configuration(configuration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    WebCore::TrackID m_trackID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoTrackPrivateRemoteConfiguration& m_configuration;
};

class AddRemoteTextTrack {
public:
    using Arguments = std::tuple<WebKit::TextTrackPrivateRemoteConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_AddRemoteTextTrack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddRemoteTextTrack(const WebKit::TextTrackPrivateRemoteConfiguration& configuration)
        : m_configuration(configuration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::TextTrackPrivateRemoteConfiguration& m_configuration;
};

class RemoveRemoteTextTrack {
public:
    using Arguments = std::tuple<WebCore::TrackID>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoveRemoteTextTrack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveRemoteTextTrack(WebCore::TrackID trackID)
        : m_trackID(trackID)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
    }

private:
    WebCore::TrackID m_trackID;
};

class RemoteTextTrackConfigurationChanged {
public:
    using Arguments = std::tuple<WebCore::TrackID, WebKit::TextTrackPrivateRemoteConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoteTextTrackConfigurationChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoteTextTrackConfigurationChanged(WebCore::TrackID trackID, const WebKit::TextTrackPrivateRemoteConfiguration& configuration)
        : m_trackID(trackID)
        , m_configuration(configuration)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    WebCore::TrackID m_trackID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::TextTrackPrivateRemoteConfiguration& m_configuration;
};

class ParseWebVTTFileHeader {
public:
    using Arguments = std::tuple<WebCore::TrackID, String>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_ParseWebVTTFileHeader; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ParseWebVTTFileHeader(WebCore::TrackID trackID, const String& header)
        : m_trackID(trackID)
        , m_header(header)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        encoder << m_header;
    }

private:
    WebCore::TrackID m_trackID;
    const String& m_header;
};

class ParseWebVTTCueData {
public:
    using Arguments = std::tuple<WebCore::TrackID, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_ParseWebVTTCueData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ParseWebVTTCueData(WebCore::TrackID trackID, const std::span<const uint8_t>& data)
        : m_trackID(trackID)
        , m_data(data)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    WebCore::TrackID m_trackID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class ParseWebVTTCueDataStruct {
public:
    using Arguments = std::tuple<WebCore::TrackID, WebCore::ISOWebVTTCue>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_ParseWebVTTCueDataStruct; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ParseWebVTTCueDataStruct(WebCore::TrackID trackID, const WebCore::ISOWebVTTCue& cueData)
        : m_trackID(trackID)
        , m_cueData(cueData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cueData;
    }

private:
    WebCore::TrackID m_trackID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ISOWebVTTCue& m_cueData;
};

class AddDataCue {
public:
    using Arguments = std::tuple<WebCore::TrackID, MediaTime, MediaTime, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_AddDataCue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddDataCue(WebCore::TrackID trackID, const MediaTime& start, const MediaTime& end, const std::span<const uint8_t>& data)
        : m_trackID(trackID)
        , m_start(start)
        , m_end(end)
        , m_data(data)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        encoder << m_start;
        encoder << m_end;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    WebCore::TrackID m_trackID;
    const MediaTime& m_start;
    const MediaTime& m_end;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

#if ENABLE(DATACUE_VALUE)
class AddDataCueWithType {
public:
    using Arguments = std::tuple<WebCore::TrackID, MediaTime, MediaTime, WebCore::SerializedPlatformDataCueValue, String>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_AddDataCueWithType; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddDataCueWithType(WebCore::TrackID trackID, const MediaTime& start, const MediaTime& end, const WebCore::SerializedPlatformDataCueValue& cueData, const String& type)
        : m_trackID(trackID)
        , m_start(start)
        , m_end(end)
        , m_cueData(cueData)
        , m_type(type)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        encoder << m_start;
        encoder << m_end;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cueData;
        encoder << m_type;
    }

private:
    WebCore::TrackID m_trackID;
    const MediaTime& m_start;
    const MediaTime& m_end;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SerializedPlatformDataCueValue& m_cueData;
    const String& m_type;
};
#endif

#if ENABLE(DATACUE_VALUE)
class UpdateDataCue {
public:
    using Arguments = std::tuple<WebCore::TrackID, MediaTime, MediaTime, WebCore::SerializedPlatformDataCueValue>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_UpdateDataCue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateDataCue(WebCore::TrackID trackID, const MediaTime& start, const MediaTime& end, const WebCore::SerializedPlatformDataCueValue& cueData)
        : m_trackID(trackID)
        , m_start(start)
        , m_end(end)
        , m_cueData(cueData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        encoder << m_start;
        encoder << m_end;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cueData;
    }

private:
    WebCore::TrackID m_trackID;
    const MediaTime& m_start;
    const MediaTime& m_end;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SerializedPlatformDataCueValue& m_cueData;
};
#endif

#if ENABLE(DATACUE_VALUE)
class RemoveDataCue {
public:
    using Arguments = std::tuple<WebCore::TrackID, MediaTime, MediaTime, WebCore::SerializedPlatformDataCueValue>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoveDataCue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveDataCue(WebCore::TrackID trackID, const MediaTime& start, const MediaTime& end, const WebCore::SerializedPlatformDataCueValue& cueData)
        : m_trackID(trackID)
        , m_start(start)
        , m_end(end)
        , m_cueData(cueData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        encoder << m_start;
        encoder << m_end;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cueData;
    }

private:
    WebCore::TrackID m_trackID;
    const MediaTime& m_start;
    const MediaTime& m_end;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SerializedPlatformDataCueValue& m_cueData;
};
#endif

class AddGenericCue {
public:
    using Arguments = std::tuple<WebCore::TrackID, WebCore::GenericCueData>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_AddGenericCue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddGenericCue(WebCore::TrackID trackID, const WebCore::GenericCueData& cue)
        : m_trackID(trackID)
        , m_cue(cue)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cue;
    }

private:
    WebCore::TrackID m_trackID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::GenericCueData& m_cue;
};

class UpdateGenericCue {
public:
    using Arguments = std::tuple<WebCore::TrackID, WebCore::GenericCueData>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_UpdateGenericCue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateGenericCue(WebCore::TrackID trackID, const WebCore::GenericCueData& cue)
        : m_trackID(trackID)
        , m_cue(cue)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cue;
    }

private:
    WebCore::TrackID m_trackID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::GenericCueData& m_cue;
};

class RemoveGenericCue {
public:
    using Arguments = std::tuple<WebCore::TrackID, WebCore::GenericCueData>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoveGenericCue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveGenericCue(WebCore::TrackID trackID, const WebCore::GenericCueData& cue)
        : m_trackID(trackID)
        , m_cue(cue)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_trackID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cue;
    }

private:
    WebCore::TrackID m_trackID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::GenericCueData& m_cue;
};

class RequestResource {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier, WebCore::ResourceRequest, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RequestResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestResource(const WebKit::RemoteMediaResourceIdentifier& remoteMediaResourceIdentifier, const WebCore::ResourceRequest& request, const unsigned& options)
        : m_remoteMediaResourceIdentifier(remoteMediaResourceIdentifier)
        , m_request(request)
        , m_options(options)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remoteMediaResourceIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_remoteMediaResourceIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_options;
};

class RemoveResource {
public:
    using Arguments = std::tuple<WebKit::RemoteMediaResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_RemoveResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveResource(const WebKit::RemoteMediaResourceIdentifier& remoteMediaResourceIdentifier)
        : m_remoteMediaResourceIdentifier(remoteMediaResourceIdentifier)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remoteMediaResourceIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteMediaResourceIdentifier& m_remoteMediaResourceIdentifier;
};

class SendH2Ping {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_SendH2Ping; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::MediaPlayerPrivateRemote_SendH2PingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Seconds, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<Seconds, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<Seconds, WebCore::ResourceError>, IPC::Error>;
    explicit SendH2Ping(const URL& url)
        : m_url(url)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class ResourceNotSupported {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_ResourceNotSupported; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceNotSupported()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ActiveSourceBuffersChanged {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_ActiveSourceBuffersChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ActiveSourceBuffersChanged()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(ENCRYPTED_MEDIA)
class WaitingForKeyChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_WaitingForKeyChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit WaitingForKeyChanged(bool waitingForKey)
        : m_waitingForKey(waitingForKey)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_waitingForKey;
    }

private:
    bool m_waitingForKey;
};
#endif

#if ENABLE(ENCRYPTED_MEDIA)
class InitializationDataEncountered {
public:
    using Arguments = std::tuple<String, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_InitializationDataEncountered; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    InitializationDataEncountered(const String& initDataType, const std::span<const uint8_t>& initData)
        : m_initDataType(initDataType)
        , m_initData(initData)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_initDataType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initData;
    }

private:
    const String& m_initDataType;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_initData;
};
#endif

#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
class MediaPlayerKeyNeeded {
public:
    using Arguments = std::tuple<std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_MediaPlayerKeyNeeded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit MediaPlayerKeyNeeded(const std::span<const uint8_t>& message)
        : m_message(message)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_message;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET)
class CurrentPlaybackTargetIsWirelessChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_CurrentPlaybackTargetIsWirelessChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CurrentPlaybackTargetIsWirelessChanged(bool isCurrentPlaybackTargetWireless)
        : m_isCurrentPlaybackTargetWireless(isCurrentPlaybackTargetWireless)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isCurrentPlaybackTargetWireless;
    }

private:
    bool m_isCurrentPlaybackTargetWireless;
};
#endif

#if PLATFORM(IOS_FAMILY)
class GetRawCookies {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_GetRawCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::MediaPlayerPrivateRemote_GetRawCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::Cookie>>;
    using Reply = CompletionHandler<void(Vector<WebCore::Cookie>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::Cookie>, IPC::Error>;
    explicit GetRawCookies(const URL& url)
        : m_url(url)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};
#endif

#if PLATFORM(COCOA)
class PushVideoFrameMetadata {
public:
    using Arguments = std::tuple<WebCore::VideoFrameMetadata, WebKit::RemoteVideoFrameProxyProperties>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_PushVideoFrameMetadata; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PushVideoFrameMetadata(const WebCore::VideoFrameMetadata& metadata, const WebKit::RemoteVideoFrameProxyProperties& frameProperties)
        : m_metadata(metadata)
        , m_frameProperties(frameProperties)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_metadata;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameProperties;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::VideoFrameMetadata& m_metadata;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteVideoFrameProxyProperties& m_frameProperties;
};
#endif

#if PLATFORM(COCOA)
class LayerHostingContextChanged {
public:
    using Arguments = std::tuple<WebCore::HostingContext, WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_LayerHostingContextChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LayerHostingContextChanged(const WebCore::HostingContext& hostingContext, const WebCore::FloatSize& presentationSize)
        : m_hostingContext(hostingContext)
        , m_presentationSize(presentationSize)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hostingContext;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_presentationSize;
    }

private:
    const WebCore::HostingContext& m_hostingContext;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_presentationSize;
};
#endif

class CommitAllTransactions {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_CommitAllTransactions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::MediaPlayerPrivateRemote_CommitAllTransactionsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    CommitAllTransactions()
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ReportGPUMemoryFootprint {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_ReportGPUMemoryFootprint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReportGPUMemoryFootprint(uint64_t memoryFootPrint)
        : m_memoryFootPrint(memoryFootPrint)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_memoryFootPrint;
    }

private:
    uint64_t m_memoryFootPrint;
};

class SendInternalMessage {
public:
    using Arguments = std::tuple<WebCore::MessageForTesting>;

    static IPC::MessageName name() { return IPC::MessageName::MediaPlayerPrivateRemote_SendInternalMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendInternalMessage(const WebCore::MessageForTesting& message)
        : m_message(message)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessageForTesting& m_message;
};

} // namespace MediaPlayerPrivateRemote
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
