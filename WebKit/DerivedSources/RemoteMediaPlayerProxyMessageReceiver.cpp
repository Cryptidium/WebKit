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

#include "config.h"
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
#include "RemoteMediaPlayerProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
#include "MediaPlaybackTargetContextSerialized.h" // NOLINT
#endif
#if ENABLE(ENCRYPTED_MEDIA)
#include "RemoteCDMInstanceIdentifier.h" // NOLINT
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
#include "RemoteLegacyCDMSessionIdentifier.h" // NOLINT
#endif
#include "RemoteMediaPlayerConfiguration.h" // NOLINT
#include "RemoteMediaPlayerProxyMessages.h" // NOLINT
#if ENABLE(MEDIA_SOURCE)
#include "RemoteMediaSourceIdentifier.h" // NOLINT
#endif
#include "RemoteVideoFrameProxyProperties.h" // NOLINT
#include "SandboxExtension.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#if PLATFORM(COCOA)
#include <WebCore/DestinationColorSpace.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <WebCore/FloatSize.h> // NOLINT
#endif
#include <WebCore/HostingContext.h> // NOLINT
#include <WebCore/InbandTextTrackPrivate.h> // NOLINT
#include <WebCore/IntSize.h> // NOLINT
#include <WebCore/LayoutRect.h> // NOLINT
#include <WebCore/MediaPlayer.h> // NOLINT
#include <WebCore/MediaPlayerEnums.h> // NOLINT
#include <WebCore/PlatformDynamicRangeLimit.h> // NOLINT
#include <WebCore/PlatformScreen.h> // NOLINT
#include <WebCore/SecurityOriginData.h> // NOLINT
#include <WebCore/TrackBase.h> // NOLINT
#include <optional> // NOLINT
#if PLATFORM(COCOA)
#include <wtf/MachSendRight.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <wtf/MachSendRightAnnotated.h> // NOLINT
#endif
#include <wtf/MediaTime.h> // NOLINT
#include <wtf/MonotonicTime.h> // NOLINT
#include <wtf/URLHash.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteMediaPlayerProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->useGPUProcessForMediaEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteMediaPlayerProxy", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::PrepareForPlayback::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::PrepareForPlayback>(connection, decoder, this, &RemoteMediaPlayerProxy::prepareForPlayback);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::Load::name())
        return IPC::handleMessageAsync<Messages::RemoteMediaPlayerProxy::Load>(connection, decoder, this, &RemoteMediaPlayerProxy::load);
#if ENABLE(MEDIA_SOURCE)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::LoadMediaSource::name()) {
        if (!(sharedPreferences && (sharedPreferences->mediaSourceEnabled || sharedPreferences->managedMediaSourceEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::RemoteMediaPlayerProxy::LoadMediaSource>(connection, decoder, this, &RemoteMediaPlayerProxy::loadMediaSource);
    }
#endif
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::CancelLoad::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::CancelLoad>(connection, decoder, this, &RemoteMediaPlayerProxy::cancelLoad);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::PrepareToPlay::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::PrepareToPlay>(connection, decoder, this, &RemoteMediaPlayerProxy::prepareToPlay);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::Play::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::Play>(connection, decoder, this, &RemoteMediaPlayerProxy::play);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::Pause::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::Pause>(connection, decoder, this, &RemoteMediaPlayerProxy::pause);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetVolumeLocked::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetVolumeLocked>(connection, decoder, this, &RemoteMediaPlayerProxy::setVolumeLocked);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetVolume::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetVolume>(connection, decoder, this, &RemoteMediaPlayerProxy::setVolume);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetMuted::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetMuted>(connection, decoder, this, &RemoteMediaPlayerProxy::setMuted);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SeekToTarget::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SeekToTarget>(connection, decoder, this, &RemoteMediaPlayerProxy::seekToTarget);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPreload::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPreload>(connection, decoder, this, &RemoteMediaPlayerProxy::setPreload);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPrivateBrowsingMode::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPrivateBrowsingMode>(connection, decoder, this, &RemoteMediaPlayerProxy::setPrivateBrowsingMode);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPreservesPitch::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPreservesPitch>(connection, decoder, this, &RemoteMediaPlayerProxy::setPreservesPitch);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPitchCorrectionAlgorithm::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPitchCorrectionAlgorithm>(connection, decoder, this, &RemoteMediaPlayerProxy::setPitchCorrectionAlgorithm);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::PrepareForRendering::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::PrepareForRendering>(connection, decoder, this, &RemoteMediaPlayerProxy::prepareForRendering);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPageIsVisible::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPageIsVisible>(connection, decoder, this, &RemoteMediaPlayerProxy::setPageIsVisible);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetShouldMaintainAspectRatio::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetShouldMaintainAspectRatio>(connection, decoder, this, &RemoteMediaPlayerProxy::setShouldMaintainAspectRatio);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::AcceleratedRenderingStateChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::AcceleratedRenderingStateChanged>(connection, decoder, this, &RemoteMediaPlayerProxy::acceleratedRenderingStateChanged);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetShouldDisableSleep::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetShouldDisableSleep>(connection, decoder, this, &RemoteMediaPlayerProxy::setShouldDisableSleep);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetRate::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetRate>(connection, decoder, this, &RemoteMediaPlayerProxy::setRate);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::DidLoadingProgress::name())
        return IPC::handleMessageAsync<Messages::RemoteMediaPlayerProxy::DidLoadingProgress>(connection, decoder, this, &RemoteMediaPlayerProxy::didLoadingProgress);
#if ENABLE(VIDEO_PRESENTATION_MODE)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::UpdateVideoFullscreenInlineImage::name()) {
        if (!(sharedPreferences && (sharedPreferences->videoPresentationManagerEnabled || sharedPreferences->videoPresentationModeAPIEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::UpdateVideoFullscreenInlineImage>(connection, decoder, this, &RemoteMediaPlayerProxy::updateVideoFullscreenInlineImage);
    }
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetVideoFullscreenMode::name()) {
        if (!(sharedPreferences && (sharedPreferences->videoPresentationManagerEnabled || sharedPreferences->videoPresentationModeAPIEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetVideoFullscreenMode>(connection, decoder, this, &RemoteMediaPlayerProxy::setVideoFullscreenMode);
    }
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetVideoFullscreenGravity::name()) {
        if (!(sharedPreferences && (sharedPreferences->videoPresentationManagerEnabled || sharedPreferences->videoPresentationModeAPIEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetVideoFullscreenGravity>(connection, decoder, this, &RemoteMediaPlayerProxy::setVideoFullscreenGravity);
    }
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::VideoFullscreenStandbyChanged::name()) {
        if (!(sharedPreferences && (sharedPreferences->videoPresentationManagerEnabled || sharedPreferences->videoPresentationModeAPIEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::VideoFullscreenStandbyChanged>(connection, decoder, this, &RemoteMediaPlayerProxy::videoFullscreenStandbyChanged);
    }
#endif
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetBufferingPolicy::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetBufferingPolicy>(connection, decoder, this, &RemoteMediaPlayerProxy::setBufferingPolicy);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPresentationSize::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPresentationSize>(connection, decoder, this, &RemoteMediaPlayerProxy::setPresentationSize);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetVideoLayerSizeFenced::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetVideoLayerSizeFenced>(connection, decoder, this, &RemoteMediaPlayerProxy::setVideoLayerSizeFenced);
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetWirelessVideoPlaybackDisabled::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetWirelessVideoPlaybackDisabled>(connection, decoder, this, &RemoteMediaPlayerProxy::setWirelessVideoPlaybackDisabled);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetWirelessPlaybackTarget::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetWirelessPlaybackTarget>(connection, decoder, this, &RemoteMediaPlayerProxy::setWirelessPlaybackTarget);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetShouldPlayToPlaybackTarget::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetShouldPlayToPlaybackTarget>(connection, decoder, this, &RemoteMediaPlayerProxy::setShouldPlayToPlaybackTarget);
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetLegacyCDMSession::name()) {
        if (!(sharedPreferences && sharedPreferences->legacyEncryptedMediaAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetLegacyCDMSession>(connection, decoder, this, &RemoteMediaPlayerProxy::setLegacyCDMSession);
    }
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::KeyAdded::name()) {
        if (!(sharedPreferences && sharedPreferences->legacyEncryptedMediaAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::KeyAdded>(connection, decoder, this, &RemoteMediaPlayerProxy::keyAdded);
    }
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::CdmInstanceAttached::name()) {
        if (!(sharedPreferences && sharedPreferences->encryptedMediaAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::CdmInstanceAttached>(connection, decoder, this, &RemoteMediaPlayerProxy::cdmInstanceAttached);
    }
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::CdmInstanceDetached::name()) {
        if (!(sharedPreferences && sharedPreferences->encryptedMediaAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::CdmInstanceDetached>(connection, decoder, this, &RemoteMediaPlayerProxy::cdmInstanceDetached);
    }
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::AttemptToDecryptWithInstance::name()) {
        if (!(sharedPreferences && sharedPreferences->encryptedMediaAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::AttemptToDecryptWithInstance>(connection, decoder, this, &RemoteMediaPlayerProxy::attemptToDecryptWithInstance);
    }
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA) && ENABLE(ENCRYPTED_MEDIA)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetShouldContinueAfterKeyNeeded::name()) {
        if (!(sharedPreferences && sharedPreferences->legacyEncryptedMediaAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetShouldContinueAfterKeyNeeded>(connection, decoder, this, &RemoteMediaPlayerProxy::setShouldContinueAfterKeyNeeded);
    }
#endif
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::BeginSimulatedHDCPError::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::BeginSimulatedHDCPError>(connection, decoder, this, &RemoteMediaPlayerProxy::beginSimulatedHDCPError);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::EndSimulatedHDCPError::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::EndSimulatedHDCPError>(connection, decoder, this, &RemoteMediaPlayerProxy::endSimulatedHDCPError);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::NotifyActiveSourceBuffersChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::NotifyActiveSourceBuffersChanged>(connection, decoder, this, &RemoteMediaPlayerProxy::notifyActiveSourceBuffersChanged);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::ApplicationWillResignActive::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::ApplicationWillResignActive>(connection, decoder, this, &RemoteMediaPlayerProxy::applicationWillResignActive);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::ApplicationDidBecomeActive::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::ApplicationDidBecomeActive>(connection, decoder, this, &RemoteMediaPlayerProxy::applicationDidBecomeActive);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::NotifyTrackModeChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::NotifyTrackModeChanged>(connection, decoder, this, &RemoteMediaPlayerProxy::notifyTrackModeChanged);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::TracksChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::TracksChanged>(connection, decoder, this, &RemoteMediaPlayerProxy::tracksChanged);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::AudioTrackSetEnabled::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::AudioTrackSetEnabled>(connection, decoder, this, &RemoteMediaPlayerProxy::audioTrackSetEnabled);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::VideoTrackSetSelected::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::VideoTrackSetSelected>(connection, decoder, this, &RemoteMediaPlayerProxy::videoTrackSetSelected);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::TextTrackSetMode::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::TextTrackSetMode>(connection, decoder, this, &RemoteMediaPlayerProxy::textTrackSetMode);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::PerformTaskAtTime::name())
        return IPC::handleMessageAsync<Messages::RemoteMediaPlayerProxy::PerformTaskAtTime>(connection, decoder, this, &RemoteMediaPlayerProxy::performTaskAtTime);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetVideoPlaybackMetricsUpdateInterval::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetVideoPlaybackMetricsUpdateInterval>(connection, decoder, this, &RemoteMediaPlayerProxy::setVideoPlaybackMetricsUpdateInterval);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPreferredDynamicRangeMode::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPreferredDynamicRangeMode>(connection, decoder, this, &RemoteMediaPlayerProxy::setPreferredDynamicRangeMode);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPlatformDynamicRangeLimit::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPlatformDynamicRangeLimit>(connection, decoder, this, &RemoteMediaPlayerProxy::setPlatformDynamicRangeLimit);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetSceneIdentifier::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetSceneIdentifier>(connection, decoder, this, &RemoteMediaPlayerProxy::setSceneIdentifier);
#endif
#if ENABLE(WEB_AUDIO)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::CreateAudioSourceProvider::name()) {
        if (!(sharedPreferences && sharedPreferences->webAudioEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::CreateAudioSourceProvider>(connection, decoder, this, &RemoteMediaPlayerProxy::createAudioSourceProvider);
    }
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetShouldEnableAudioSourceProvider::name()) {
        if (!(sharedPreferences && sharedPreferences->webAudioEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetShouldEnableAudioSourceProvider>(connection, decoder, this, &RemoteMediaPlayerProxy::setShouldEnableAudioSourceProvider);
    }
#endif
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::PlayAtHostTime::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::PlayAtHostTime>(connection, decoder, this, &RemoteMediaPlayerProxy::playAtHostTime);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::PauseAtHostTime::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::PauseAtHostTime>(connection, decoder, this, &RemoteMediaPlayerProxy::pauseAtHostTime);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::StartVideoFrameMetadataGathering::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::StartVideoFrameMetadataGathering>(connection, decoder, this, &RemoteMediaPlayerProxy::startVideoFrameMetadataGathering);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::StopVideoFrameMetadataGathering::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::StopVideoFrameMetadataGathering>(connection, decoder, this, &RemoteMediaPlayerProxy::stopVideoFrameMetadataGathering);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::PlayerContentBoxRectChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::PlayerContentBoxRectChanged>(connection, decoder, this, &RemoteMediaPlayerProxy::playerContentBoxRectChanged);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetShouldDisableHDR::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetShouldDisableHDR>(connection, decoder, this, &RemoteMediaPlayerProxy::setShouldDisableHDR);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::RequestHostingContext::name())
        return IPC::handleMessageAsync<Messages::RemoteMediaPlayerProxy::RequestHostingContext>(connection, decoder, this, &RemoteMediaPlayerProxy::requestHostingContext);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetShouldCheckHardwareSupport::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetShouldCheckHardwareSupport>(connection, decoder, this, &RemoteMediaPlayerProxy::setShouldCheckHardwareSupport);
#if HAVE(SPATIAL_TRACKING_LABEL)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetDefaultSpatialTrackingLabel::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetDefaultSpatialTrackingLabel>(connection, decoder, this, &RemoteMediaPlayerProxy::setDefaultSpatialTrackingLabel);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetSpatialTrackingLabel::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetSpatialTrackingLabel>(connection, decoder, this, &RemoteMediaPlayerProxy::setSpatialTrackingLabel);
#endif
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetPrefersSpatialAudioExperience::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetPrefersSpatialAudioExperience>(connection, decoder, this, &RemoteMediaPlayerProxy::setPrefersSpatialAudioExperience);
#endif
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::AudioOutputDeviceChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::AudioOutputDeviceChanged>(connection, decoder, this, &RemoteMediaPlayerProxy::audioOutputDeviceChanged);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::IsInFullscreenOrPictureInPictureChanged::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::IsInFullscreenOrPictureInPictureChanged>(connection, decoder, this, &RemoteMediaPlayerProxy::isInFullscreenOrPictureInPictureChanged);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetSoundStageSize::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetSoundStageSize>(connection, decoder, this, &RemoteMediaPlayerProxy::setSoundStageSize);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::SetHasMessageClientForTesting::name())
        return IPC::handleMessage<Messages::RemoteMediaPlayerProxy::SetHasMessageClientForTesting>(connection, decoder, this, &RemoteMediaPlayerProxy::setHasMessageClientForTesting);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool RemoteMediaPlayerProxy::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(isInGPUProcess());
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->useGPUProcessForMediaEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteMediaPlayerProxy", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return false;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::IsCrossOrigin::name())
        return IPC::handleMessageSynchronous<Messages::RemoteMediaPlayerProxy::IsCrossOrigin>(connection, decoder, replyEncoder, this, &RemoteMediaPlayerProxy::isCrossOrigin);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::ErrorLog::name())
        return IPC::handleMessageSynchronous<Messages::RemoteMediaPlayerProxy::ErrorLog>(connection, decoder, replyEncoder, this, &RemoteMediaPlayerProxy::errorLog);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::AccessLog::name())
        return IPC::handleMessageSynchronous<Messages::RemoteMediaPlayerProxy::AccessLog>(connection, decoder, replyEncoder, this, &RemoteMediaPlayerProxy::accessLog);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::NativeImageForCurrentTime::name())
        return IPC::handleMessageSynchronous<Messages::RemoteMediaPlayerProxy::NativeImageForCurrentTime>(connection, decoder, replyEncoder, this, &RemoteMediaPlayerProxy::nativeImageForCurrentTime);
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::ColorSpace::name())
        return IPC::handleMessageSynchronous<Messages::RemoteMediaPlayerProxy::ColorSpace>(connection, decoder, replyEncoder, this, &RemoteMediaPlayerProxy::colorSpace);
#endif
    if (decoder.messageName() == Messages::RemoteMediaPlayerProxy::VideoFrameForCurrentTimeIfChanged::name())
        return IPC::handleMessageSynchronous<Messages::RemoteMediaPlayerProxy::VideoFrameForCurrentTimeIfChanged>(connection, decoder, replyEncoder, this, &RemoteMediaPlayerProxy::videoFrameForCurrentTimeIfChanged);
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_PrepareForPlayback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::PrepareForPlayback::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_Load>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::Load::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_Load>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::Load::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(MEDIA_SOURCE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_LoadMediaSource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::LoadMediaSource::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_LoadMediaSource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::LoadMediaSource::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_CancelLoad>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::CancelLoad::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_PrepareToPlay>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::PrepareToPlay::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_Play>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::Play::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_Pause>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::Pause::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetVolumeLocked>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetVolumeLocked::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetVolume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetVolume::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetMuted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetMuted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SeekToTarget>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SeekToTarget::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPreload>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPreload::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPrivateBrowsingMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPrivateBrowsingMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPreservesPitch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPreservesPitch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPitchCorrectionAlgorithm>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPitchCorrectionAlgorithm::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_PrepareForRendering>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::PrepareForRendering::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPageIsVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPageIsVisible::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetShouldMaintainAspectRatio>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetShouldMaintainAspectRatio::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_AcceleratedRenderingStateChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::AcceleratedRenderingStateChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetShouldDisableSleep>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetShouldDisableSleep::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetRate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetRate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_DidLoadingProgress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::DidLoadingProgress::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_DidLoadingProgress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::DidLoadingProgress::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(VIDEO_PRESENTATION_MODE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_UpdateVideoFullscreenInlineImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::UpdateVideoFullscreenInlineImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetVideoFullscreenMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetVideoFullscreenMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetVideoFullscreenGravity>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetVideoFullscreenGravity::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_VideoFullscreenStandbyChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::VideoFullscreenStandbyChanged::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetBufferingPolicy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetBufferingPolicy::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPresentationSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPresentationSize::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetVideoLayerSizeFenced>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetVideoLayerSizeFenced::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetWirelessVideoPlaybackDisabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetWirelessVideoPlaybackDisabled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetWirelessPlaybackTarget>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetWirelessPlaybackTarget::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetShouldPlayToPlaybackTarget>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetShouldPlayToPlaybackTarget::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetLegacyCDMSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetLegacyCDMSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_KeyAdded>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::KeyAdded::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(ENCRYPTED_MEDIA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_CdmInstanceAttached>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::CdmInstanceAttached::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_CdmInstanceDetached>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::CdmInstanceDetached::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_AttemptToDecryptWithInstance>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::AttemptToDecryptWithInstance::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA) && ENABLE(ENCRYPTED_MEDIA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetShouldContinueAfterKeyNeeded>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetShouldContinueAfterKeyNeeded::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_BeginSimulatedHDCPError>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::BeginSimulatedHDCPError::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_EndSimulatedHDCPError>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::EndSimulatedHDCPError::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_NotifyActiveSourceBuffersChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::NotifyActiveSourceBuffersChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_ApplicationWillResignActive>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::ApplicationWillResignActive::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_ApplicationDidBecomeActive>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::ApplicationDidBecomeActive::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_NotifyTrackModeChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::NotifyTrackModeChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_TracksChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::TracksChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_AudioTrackSetEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::AudioTrackSetEnabled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_VideoTrackSetSelected>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::VideoTrackSetSelected::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_TextTrackSetMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::TextTrackSetMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_PerformTaskAtTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::PerformTaskAtTime::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_PerformTaskAtTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::PerformTaskAtTime::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_IsCrossOrigin>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::IsCrossOrigin::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_IsCrossOrigin>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::IsCrossOrigin::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetVideoPlaybackMetricsUpdateInterval>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetVideoPlaybackMetricsUpdateInterval::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPreferredDynamicRangeMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPreferredDynamicRangeMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPlatformDynamicRangeLimit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPlatformDynamicRangeLimit::Arguments>(globalObject, decoder);
}
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_ErrorLog>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::ErrorLog::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_ErrorLog>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::ErrorLog::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_AccessLog>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::AccessLog::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_AccessLog>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::AccessLog::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetSceneIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetSceneIdentifier::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(WEB_AUDIO)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_CreateAudioSourceProvider>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::CreateAudioSourceProvider::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetShouldEnableAudioSourceProvider>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetShouldEnableAudioSourceProvider::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_NativeImageForCurrentTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::NativeImageForCurrentTime::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_NativeImageForCurrentTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::NativeImageForCurrentTime::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_ColorSpace>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::ColorSpace::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_ColorSpace>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::ColorSpace::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_VideoFrameForCurrentTimeIfChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::VideoFrameForCurrentTimeIfChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_VideoFrameForCurrentTimeIfChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::VideoFrameForCurrentTimeIfChanged::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_PlayAtHostTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::PlayAtHostTime::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_PauseAtHostTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::PauseAtHostTime::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_StartVideoFrameMetadataGathering>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::StartVideoFrameMetadataGathering::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_StopVideoFrameMetadataGathering>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::StopVideoFrameMetadataGathering::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_PlayerContentBoxRectChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::PlayerContentBoxRectChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetShouldDisableHDR>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetShouldDisableHDR::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_RequestHostingContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::RequestHostingContext::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteMediaPlayerProxy_RequestHostingContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::RequestHostingContext::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetShouldCheckHardwareSupport>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetShouldCheckHardwareSupport::Arguments>(globalObject, decoder);
}
#if HAVE(SPATIAL_TRACKING_LABEL)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetDefaultSpatialTrackingLabel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetDefaultSpatialTrackingLabel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetSpatialTrackingLabel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetSpatialTrackingLabel::Arguments>(globalObject, decoder);
}
#endif
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetPrefersSpatialAudioExperience>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetPrefersSpatialAudioExperience::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_AudioOutputDeviceChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::AudioOutputDeviceChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_IsInFullscreenOrPictureInPictureChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::IsInFullscreenOrPictureInPictureChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetSoundStageSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetSoundStageSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteMediaPlayerProxy_SetHasMessageClientForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteMediaPlayerProxy::SetHasMessageClientForTesting::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
