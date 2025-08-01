/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2017-2023 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "WebPreferences.h"

#include "WebKit2Initialize.h"
#include "WebPreferencesDefinitions.h"
#include "WebPreferencesKeys.h"
#include <wtf/ExperimentalFeatureNames.h>
#include <wtf/NeverDestroyed.h>

namespace WebKit {

const Vector<RefPtr<API::Object>>& WebPreferences::features()
{
    InitializeWebKit2();
    static NeverDestroyed<Vector<RefPtr<API::Object>>> features(std::initializer_list<RefPtr<API::Object>> {
        API::Feature::create(""""_s, "DatabasesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DatabasesEnabled, false),
        API::Feature::create(""""_s, "LoadDeferringEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_LoadDeferringEnabled, false),
        API::Feature::create(""""_s, "AcceleratedCompositingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AcceleratedCompositingEnabled, false),
        API::Feature::create(""""_s, "AcceleratedCompositingForFixedPositionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AcceleratedCompositingForFixedPositionEnabled, false),
        API::Feature::create(""""_s, "WirelessPlaybackTargetAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_WirelessPlaybackTargetAPIEnabled, false),
        API::Feature::create(""""_s, "LoadsImagesAutomatically"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_LoadsImagesAutomatically, false),
        API::Feature::create(""""_s, "LinkPreconnect"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_LinkPreconnect, false),
        API::Feature::create(""""_s, "WindowFocusRestricted"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_WindowFocusRestricted, false),
        API::Feature::create(""""_s, "AggressiveTileRetentionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AggressiveTileRetentionEnabled, false),
        API::Feature::create(""""_s, "AllowContentSecurityPolicySourceStarToMatchAnyProtocol"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowContentSecurityPolicySourceStarToMatchAnyProtocol, false),
        API::Feature::create(""""_s, "AllowDisplayOfInsecureContent"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowDisplayOfInsecureContent, false),
        API::Feature::create(""""_s, "AllowFileAccessFromFileURLs"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowFileAccessFromFileURLs, false),
        API::Feature::create(""""_s, "LowPowerVideoAudioBufferSizeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_LowPowerVideoAudioBufferSizeEnabled, false),
        API::Feature::create(""""_s, "AllowMultiElementImplicitSubmission"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowMultiElementImplicitSubmission, false),
        API::Feature::create(""""_s, "AllowRunningOfInsecureContent"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowRunningOfInsecureContent, false),
        API::Feature::create(""""_s, "AllowTestOnlyIPC"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowTestOnlyIPC, false),
#if ENABLE(MATHML)
        API::Feature::create(""""_s, "MathMLEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MathMLEnabled, false),
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
        API::Feature::create(""""_s, "AllowsAirPlayForMediaPlayback"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowsAirPlayForMediaPlayback, false),
#endif
        API::Feature::create(""""_s, "AllowsInlineMediaPlayback"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowsInlineMediaPlayback, false),
        API::Feature::create(""""_s, "AllowsInlineMediaPlaybackAfterFullscreen"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowsInlineMediaPlaybackAfterFullscreen, false),
        API::Feature::create(""""_s, "AllowsPictureInPictureMediaPlayback"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowsPictureInPictureMediaPlayback, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create(""""_s, "AlternateFullScreenControlDesignEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AlternateFullScreenControlDesignEnabled, false),
#endif
        API::Feature::create(""""_s, "WebSocketEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_WebSocketEnabled, false),
        API::Feature::create(""""_s, "MediaCapabilitiesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MediaCapabilitiesEnabled, false),
        API::Feature::create(""""_s, "WebSecurityEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_WebSecurityEnabled, false),
        API::Feature::create(""""_s, "AnimatedImageAsyncDecodingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AnimatedImageAsyncDecodingEnabled, false),
        API::Feature::create(""""_s, "AppleMailPaginationQuirkEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AppleMailPaginationQuirkEnabled, false),
#if ENABLE(APPLE_PAY)
        API::Feature::create(""""_s, "ApplePayCapabilityDisclosureAllowed"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ApplePayCapabilityDisclosureAllowed, false),
#endif
#if ENABLE(APPLE_PAY)
        API::Feature::create(""""_s, "ApplePayEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ApplePayEnabled, false),
#endif
        API::Feature::create(""""_s, "LargeImageAsyncDecodingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_LargeImageAsyncDecodingEnabled, false),
        API::Feature::create(""""_s, "AsynchronousSpellCheckingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AsynchronousSpellCheckingEnabled, false),
        API::Feature::create(""""_s, "JavaScriptMarkupEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_JavaScriptMarkupEnabled, false),
        API::Feature::create(""""_s, "AudioControlsScaleWithPageZoom"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::Media, """"_s, DEFAULT_VALUE_FOR_AudioControlsScaleWithPageZoom, false),
        API::Feature::create(""""_s, "JavaScriptCanOpenWindowsAutomatically"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_JavaScriptCanOpenWindowsAutomatically, false),
        API::Feature::create(""""_s, "AuthorAndUserStylesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AuthorAndUserStylesEnabled, false),
#if ENABLE(WEB_AUDIO)
        API::Feature::create(""""_s, "WebAudioEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_WebAudioEnabled, false),
#endif
        API::Feature::create(""""_s, "JavaScriptCanAccessClipboard"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_JavaScriptCanAccessClipboard, false),
        API::Feature::create(""""_s, "WantsBalancedSetDefersLoadingBehavior"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_WantsBalancedSetDefersLoadingBehavior, false),
        API::Feature::create(""""_s, "VisualViewportEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_VisualViewportEnabled, false),
#if ENABLE(VIDEO)
        API::Feature::create(""""_s, "VideoQualityIncludesDisplayCompositingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_VideoQualityIncludesDisplayCompositingEnabled, false),
#endif
        API::Feature::create(""""_s, "BackspaceKeyNavigationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_BackspaceKeyNavigationEnabled, false),
        API::Feature::create(""""_s, "VideoPresentationModeAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_VideoPresentationModeAPIEnabled, false),
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
        API::Feature::create(""""_s, "MediaControlsContextMenusEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MediaControlsContextMenusEnabled, false),
#endif
        API::Feature::create(""""_s, "VideoPresentationManagerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_VideoPresentationManagerEnabled, false),
        API::Feature::create(""""_s, "MediaControlsScaleWithPageZoom"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MediaControlsScaleWithPageZoom, false),
#if ENABLE(FULLSCREEN_API)
        API::Feature::create(""""_s, "VideoFullscreenRequiresElementFullscreen"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_VideoFullscreenRequiresElementFullscreen, false),
#endif
        API::Feature::create(""""_s, "MediaDataLoadsAutomatically"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MediaDataLoadsAutomatically, false),
        API::Feature::create(""""_s, "MediaPreloadingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MediaPreloadingEnabled, false),
        API::Feature::create(""""_s, "InvisibleAutoplayNotPermitted"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_InvisibleAutoplayNotPermitted, false),
#if ENABLE(MEDIA_STREAM)
        API::Feature::create(""""_s, "InterruptVideoOnPageVisibilityChangeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_InterruptVideoOnPageVisibilityChangeEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create(""""_s, "InterruptAudioOnPageVisibilityChangeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_InterruptAudioOnPageVisibilityChangeEnabled, false),
#endif
#if ENABLE(VP9)
        API::Feature::create(""""_s, "VP9DecoderEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_VP9DecoderEnabled, false),
#endif
        API::Feature::create(""""_s, "MediaUserGestureInheritsFromDocument"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MediaUserGestureInheritsFromDocument, false),
        API::Feature::create(""""_s, "InspectorSupportsShowingCertificate"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_InspectorSupportsShowingCertificate, false),
        API::Feature::create(""""_s, "InspectorStartsAttached"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_InspectorStartsAttached, false),
        API::Feature::create(""""_s, "MockCaptureDevicesPromptEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MockCaptureDevicesPromptEnabled, false),
        API::Feature::create(""""_s, "MockScrollbarsControllerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MockScrollbarsControllerEnabled, false),
        API::Feature::create(""""_s, "MockScrollbarsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_MockScrollbarsEnabled, false),
        API::Feature::create(""""_s, "InlineMediaPlaybackRequiresPlaysInlineAttribute"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_InlineMediaPlaybackRequiresPlaysInlineAttribute, false),
#if HAVE(INCREMENTAL_PDF_APIS)
        API::Feature::create(""""_s, "IncrementalPDFLoadingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_IncrementalPDFLoadingEnabled, false),
#endif
        API::Feature::create(""""_s, "IncompleteImageBorderEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_IncompleteImageBorderEnabled, false),
        API::Feature::create(""""_s, "NeedsAdobeFrameReloadingQuirk"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_NeedsAdobeFrameReloadingQuirk, false),
        API::Feature::create(""""_s, "NeedsFrameNameFallbackToIdQuirk"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_NeedsFrameNameFallbackToIdQuirk, false),
        API::Feature::create(""""_s, "NeedsKeyboardEventDisambiguationQuirks"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_NeedsKeyboardEventDisambiguationQuirks, false),
#if PLATFORM(COCOA)
        API::Feature::create(""""_s, "PDFPluginEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_PDFPluginEnabled, false),
#endif
#if PLATFORM(COCOA)
        API::Feature::create(""""_s, "PDFPluginHUDEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_PDFPluginHUDEnabled, false),
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
        API::Feature::create(""""_s, "PDFPluginPageNumberIndicatorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_PDFPluginPageNumberIndicatorEnabled, false),
#endif
        API::Feature::create(""""_s, "PassiveTouchListenersAsDefaultOnDocument"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_PassiveTouchListenersAsDefaultOnDocument, false),
        API::Feature::create(""""_s, "PasswordEchoEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_PasswordEchoEnabled, false),
#if ENABLE(PICTURE_IN_PICTURE_API)
        API::Feature::create(""""_s, "PictureInPictureAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_PictureInPictureAPIEnabled, false),
#endif
        API::Feature::create(""""_s, "PunchOutWhiteBackgroundsInDarkMode"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_PunchOutWhiteBackgroundsInDarkMode, false),
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
        API::Feature::create(""""_s, "RequiresPageVisibilityForVideoToBeNowPlaying"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_RequiresPageVisibilityForVideoToBeNowPlaying, false),
#endif
        API::Feature::create(""""_s, "RequiresPageVisibilityToPlayAudio"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_RequiresPageVisibilityToPlayAudio, false),
        API::Feature::create(""""_s, "HiddenPageCSSAnimationSuspensionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_HiddenPageCSSAnimationSuspensionEnabled, false),
        API::Feature::create(""""_s, "RequiresUserGestureForAudioPlayback"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_RequiresUserGestureForAudioPlayback, false),
        API::Feature::create(""""_s, "RequiresUserGestureForMediaPlayback"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_RequiresUserGestureForMediaPlayback, false),
        API::Feature::create(""""_s, "RequiresUserGestureForVideoPlayback"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_RequiresUserGestureForVideoPlayback, false),
        API::Feature::create(""""_s, "RequiresUserGestureToLoadVideo"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_RequiresUserGestureToLoadVideo, false),
        API::Feature::create(""""_s, "UsesSingleWebProcess"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_UsesSingleWebProcess, false),
#if HAVE(RUBBER_BANDING)
        API::Feature::create(""""_s, "RubberBandingForSubScrollableRegionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_RubberBandingForSubScrollableRegionsEnabled, false),
#endif
        API::Feature::create(""""_s, "UsesEncodingDetector"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_UsesEncodingDetector, false),
        API::Feature::create(""""_s, "SelectTrailingWhitespaceEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_SelectTrailingWhitespaceEnabled, false),
        API::Feature::create(""""_s, "UsesBackForwardCache"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_UsesBackForwardCache, false),
        API::Feature::create(""""_s, "CaretBrowsingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_CaretBrowsingEnabled, false),
        API::Feature::create(""""_s, "UseSystemAppearance"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_UseSystemAppearance, false),
#if ENABLE(SERVICE_CONTROLS)
        API::Feature::create(""""_s, "ServiceControlsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ServiceControlsEnabled, false),
#endif
#if USE(GSTREAMER)
        API::Feature::create(""""_s, "GStreamerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_GStreamerEnabled, false),
#endif
        API::Feature::create(""""_s, "ServiceWorkerEntitlementDisabledForTesting"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ServiceWorkerEntitlementDisabledForTesting, false),
        API::Feature::create(""""_s, "ShouldAllowUserInstalledFonts"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldAllowUserInstalledFonts, false),
        API::Feature::create(""""_s, "ColorFilterEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ColorFilterEnabled, false),
        API::Feature::create(""""_s, "UsePreHTML5ParserQuirks"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_UsePreHTML5ParserQuirks, false),
        API::Feature::create(""""_s, "ShouldConvertInvalidURLsToBlank"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldConvertInvalidURLsToBlank, false),
        API::Feature::create(""""_s, "ShouldConvertPositionStyleOnCopy"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldConvertPositionStyleOnCopy, false),
        API::Feature::create(""""_s, "ShouldDecidePolicyBeforeLoadingQuickLookPreview"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldDecidePolicyBeforeLoadingQuickLookPreview, false),
#if ENABLE(VIDEO)
        API::Feature::create(""""_s, "ShouldDisplayCaptions"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldDisplayCaptions, false),
#endif
#if ENABLE(CONTENT_CHANGE_OBSERVER)
        API::Feature::create(""""_s, "ContentChangeObserverEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ContentChangeObserverEnabled, false),
#endif
        API::Feature::create(""""_s, "ContentDispositionAttachmentSandboxEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ContentDispositionAttachmentSandboxEnabled, false),
        API::Feature::create(""""_s, "ForceWebGLUsesLowPower"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ForceWebGLUsesLowPower, false),
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
        API::Feature::create(""""_s, "ContextMenuQRCodeDetectionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ContextMenuQRCodeDetectionEnabled, false),
#endif
#if ENABLE(VIDEO)
        API::Feature::create(""""_s, "ShouldDisplaySubtitles"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldDisplaySubtitles, false),
#endif
        API::Feature::create(""""_s, "ForceFTPDirectoryListings"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ForceFTPDirectoryListings, false),
        API::Feature::create(""""_s, "ForceCompositingMode"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ForceCompositingMode, false),
#if ENABLE(VIDEO)
        API::Feature::create(""""_s, "ShouldDisplayTextDescriptions"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldDisplayTextDescriptions, false),
#endif
#if ENABLE(TEXT_AUTOSIZING)
        API::Feature::create(""""_s, "ShouldEnableTextAutosizingBoost"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldEnableTextAutosizingBoost, false),
#endif
        API::Feature::create(""""_s, "UseImageDocumentForSubframePDF"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_UseImageDocumentForSubframePDF, false),
        API::Feature::create(""""_s, "ShouldIgnoreMetaViewport"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldIgnoreMetaViewport, false),
        API::Feature::create(""""_s, "ShouldPrintBackgrounds"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldPrintBackgrounds, false),
        API::Feature::create(""""_s, "ShouldRespectImageOrientation"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldRespectImageOrientation, false),
        API::Feature::create(""""_s, "ShouldRestrictBaseURLSchemes"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldRestrictBaseURLSchemes, false),
        API::Feature::create(""""_s, "ShouldSuppressTextInputFromEditingDuringProvisionalNavigation"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldSuppressTextInputFromEditingDuringProvisionalNavigation, false),
        API::Feature::create(""""_s, "DOMPasteAllowed"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DOMPasteAllowed, false),
        API::Feature::create(""""_s, "ShouldUseServiceWorkerShortTimeout"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShouldUseServiceWorkerShortTimeout, false),
#if HAVE(APP_SSO)
        API::Feature::create(""""_s, "ExtensibleSSOEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ExtensibleSSOEnabled, false),
#endif
        API::Feature::create(""""_s, "TreatsAnyTextCSSLinkAsStylesheet"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_TreatsAnyTextCSSLinkAsStylesheet, false),
        API::Feature::create(""""_s, "LinkPreloadEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_LinkPreloadEnabled, false),
        API::Feature::create(""""_s, "ShowsToolTipOverTruncatedText"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShowsToolTipOverTruncatedText, false),
        API::Feature::create(""""_s, "ThreadedScrollingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ThreadedScrollingEnabled, false),
        API::Feature::create(""""_s, "TextInteractionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_TextInteractionEnabled, false),
        API::Feature::create(""""_s, "TextExtractionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_TextExtractionEnabled, false),
#if ENABLE(TEXT_AUTOSIZING)
        API::Feature::create(""""_s, "TextAutosizingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_TextAutosizingEnabled, false),
#endif
        API::Feature::create(""""_s, "DeveloperExtrasEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DeveloperExtrasEnabled, false),
#if ENABLE(DEVICE_ORIENTATION)
        API::Feature::create(""""_s, "DeviceOrientationEventEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DeviceOrientationEventEnabled, false),
#endif
#if ENABLE(DEVICE_ORIENTATION)
        API::Feature::create(""""_s, "DeviceOrientationPermissionAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DeviceOrientationPermissionAPIEnabled, false),
#endif
        API::Feature::create(""""_s, "ShowsURLsInToolTipsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShowsURLsInToolTipsEnabled, false),
        API::Feature::create(""""_s, "TextAreasAreResizable"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_TextAreasAreResizable, false),
        API::Feature::create(""""_s, "TemporaryTileCohortRetentionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_TemporaryTileCohortRetentionEnabled, false),
        API::Feature::create(""""_s, "TelephoneNumberParsingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_TelephoneNumberParsingEnabled, false),
        API::Feature::create(""""_s, "ShrinksStandaloneImagesToFit"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShrinksStandaloneImagesToFit, false),
        API::Feature::create(""""_s, "DisabledAdaptationsMetaTagEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DisabledAdaptationsMetaTagEnabled, false),
        API::Feature::create(""""_s, "DownloadAttributeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DownloadAttributeEnabled, false),
        API::Feature::create(""""_s, "TabsToLinks"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_TabsToLinks, false),
#if USE(SYSTEM_PREVIEW)
        API::Feature::create(""""_s, "SystemPreviewEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_SystemPreviewEnabled, false),
#endif
        API::Feature::create(""""_s, "SuppressesIncrementalRendering"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_SuppressesIncrementalRendering, false),
        API::Feature::create(""""_s, "EnableInheritURIQueryComponent"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_EnableInheritURIQueryComponent, false),
#if ENABLE(ENCRYPTED_MEDIA)
        API::Feature::create(""""_s, "EncryptedMediaAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_EncryptedMediaAPIEnabled, false),
#endif
        API::Feature::create(""""_s, "Standalone"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_Standalone, false),
        API::Feature::create(""""_s, "SmartInsertDeleteEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_SmartInsertDeleteEnabled, false),
        API::Feature::create(""""_s, "SpatialNavigationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_SpatialNavigationEnabled, false),
#if ENABLE(MEDIA_SOURCE)
        API::Feature::create(""""_s, "SourceBufferChangeTypeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_SourceBufferChangeTypeEnabled, false),
#endif
        API::Feature::create("::target-text pseudo-element"""_s, "TargetTextPseudoElementEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable the ::target-text CSS pseudo-element"""_s, DEFAULT_VALUE_FOR_TargetTextPseudoElementEnabled, false),
        API::Feature::create("::thumb and ::track pseudo-elements"""_s, "ThumbAndTrackPseudoElementsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable support for CSS ::thumb and ::track pseudo-elements"""_s, DEFAULT_VALUE_FOR_ThumbAndTrackPseudoElementsEnabled, false),
        API::Feature::create("<link rel=dns-prefetch>"""_s, "LinkDNSPrefetchEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Networking, "Enable <link rel=dns-prefetch>"""_s, DEFAULT_VALUE_FOR_LinkDNSPrefetchEnabled, false),
        API::Feature::create("<select> showPicker() method"""_s, "SelectShowPickerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable showPicker() method on <select>"""_s, DEFAULT_VALUE_FOR_SelectShowPickerEnabled, false),
        API::Feature::create("@page CSS at-rule margin descriptors"""_s, "PageAtRuleMarginDescriptorsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for @page margin descriptors"""_s, DEFAULT_VALUE_FOR_PageAtRuleMarginDescriptorsEnabled, false),
#if USE(AVFOUNDATION)
        API::Feature::create("AVFoundation"""_s, "AVFoundationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable AVFoundation"""_s, DEFAULT_VALUE_FOR_AVFoundationEnabled, false),
#endif
#if HAVE(AVKIT_CONTENT_SOURCE)
        API::Feature::create("AVKit Content Source"""_s, "AVKitContentSourceEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::None, "Enable AVKit Content Source"""_s, DEFAULT_VALUE_FOR_AVKitContentSourceEnabled, false),
#endif
#if USE(CORE_IMAGE)
        API::Feature::create("Accelerated Filter Rendering"""_s, "AcceleratedFiltersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::None, "Accelerated CSS and SVG filter rendering"""_s, DEFAULT_VALUE_FOR_AcceleratedFiltersEnabled, false),
#endif
        API::Feature::create("AccessHandle API"""_s, "AccessHandleEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::DOM, "Enable AccessHandle API"""_s, DEFAULT_VALUE_FOR_AccessHandleEnabled, false),
        API::Feature::create("Additional Testing APIs for DOM Objects"""_s, "DOMTestingAPIsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable additional testing APIs for DOM objects"""_s, DEFAULT_VALUE_FOR_DOMTestingAPIsEnabled, false),
        API::Feature::create("Allow Media Content Types Requirining Hardware As Fallback"""_s, "AllowMediaContentTypesRequiringHardwareSupportAsFallback"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Allow Media Content Types Requirining Hardware As Fallback"""_s, DEFAULT_VALUE_FOR_AllowMediaContentTypesRequiringHardwareSupportAsFallback, false),
        API::Feature::create("Allow Privacy-Sensitive Operations in Non-Persistent Data Stores"""_s, "AllowPrivacySensitiveOperationsInNonPersistentDataStores"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Allow Privacy-Sensitive Operations in Non-Persistent Data Stores"""_s, DEFAULT_VALUE_FOR_AllowPrivacySensitiveOperationsInNonPersistentDataStores, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Allow Viewport Shrink to Fit Content"""_s, "AllowViewportShrinkToFitContent"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Allow the viewport shrink to fit content heuristic when appropriate"""_s, DEFAULT_VALUE_FOR_AllowViewportShrinkToFitContent, false),
#endif
#if ENABLE(WEBGL)
        API::Feature::create("Allow WebGL in Web Workers"""_s, "AllowWebGLInWorkers"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, """"_s, DEFAULT_VALUE_FOR_AllowWebGLInWorkers, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Allow per media element speaker device selection"""_s, "PerElementSpeakerSelectionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Allow per media element speaker device selection"""_s, DEFAULT_VALUE_FOR_PerElementSpeakerSelectionEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Allow selection of speaker device without related microphone"""_s, "ExposeSpeakersWithoutMicrophoneEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Allow selection of speaker device without related microphone"""_s, DEFAULT_VALUE_FOR_ExposeSpeakersWithoutMicrophoneEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Allow speaker device selection"""_s, "ExposeSpeakersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Allow speaker device selection"""_s, DEFAULT_VALUE_FOR_ExposeSpeakersEnabled, false),
#endif
        API::Feature::create("Allow top navigation to data: URLs"""_s, "AllowTopNavigationToDataURLs"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_AllowTopNavigationToDataURLs, false),
        API::Feature::create("Allow universal access from file: URLs"""_s, "AllowUniversalAccessFromFileURLs"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Security, """"_s, DEFAULT_VALUE_FOR_AllowUniversalAccessFromFileURLs, false),
#if ENABLE(WEB_ARCHIVE)
        API::Feature::create("Always allow loading local Web Archive"""_s, "AlwaysAllowLocalWebarchive"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable always allowing loading local Web Archive"""_s, DEFAULT_VALUE_FOR_AlwaysAllowLocalWebarchive, false),
#endif
#if ENABLE(VP9)
        API::Feature::create("Always enable VPx software decoders"""_s, "SWVPDecodersAlwaysEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Always enable VPx software decoders"""_s, DEFAULT_VALUE_FOR_SWVPDecodersAlwaysEnabled, false),
#endif
        API::Feature::create("App Badge"""_s, "AppBadgeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Enable App Badge"""_s, DEFAULT_VALUE_FOR_AppBadgeEnabled, false),
#if ENABLE(APP_HIGHLIGHTS)
        API::Feature::create("App Highlights"""_s, "AppHighlightsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::CSS, "Enable App Highlights"""_s, DEFAULT_VALUE_FOR_AppHighlightsEnabled, false),
#endif
        API::Feature::create("Async Frame Scrolling"""_s, "AsyncFrameScrollingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Perform frame scrolling off the main thread"""_s, DEFAULT_VALUE_FOR_AsyncFrameScrollingEnabled, false),
        API::Feature::create("Async Overflow Scrolling"""_s, "AsyncOverflowScrollingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Perform overflow scrolling off the main thread"""_s, DEFAULT_VALUE_FOR_AsyncOverflowScrollingEnabled, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Async UIKit Interactions"""_s, "UseAsyncUIKitInteractions"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Use Async UIKit Interactions"""_s, DEFAULT_VALUE_FOR_UseAsyncUIKitInteractions, false),
#endif
        API::Feature::create("Async clipboard API"""_s, "AsyncClipboardAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable the async clipboard API"""_s, DEFAULT_VALUE_FOR_AsyncClipboardAPIEnabled, false),
#if ENABLE(ATTACHMENT_ELEMENT)
        API::Feature::create("Attachment Element"""_s, "AttachmentElementEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Allow the insertion of attachment elements"""_s, DEFAULT_VALUE_FOR_AttachmentElementEnabled, false),
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
        API::Feature::create("Attachment wide-layout styling"""_s, "AttachmentWideLayoutEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Use horizontal wide-layout attachment style, requires Attachment Element"""_s, DEFAULT_VALUE_FOR_AttachmentWideLayoutEnabled, false),
#endif
#if ENABLE(VIDEO)
        API::Feature::create("Audio descriptions for video - Extended"""_s, "ExtendedAudioDescriptionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::Media, "Enable extended audio descriptions for video"""_s, DEFAULT_VALUE_FOR_ExtendedAudioDescriptionsEnabled, false),
#endif
#if ENABLE(VIDEO)
        API::Feature::create("Audio descriptions for video - Standard"""_s, "AudioDescriptionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::Media, "Enable standard audio descriptions for video"""_s, DEFAULT_VALUE_FOR_AudioDescriptionsEnabled, false),
#endif
#if ENABLE(DOM_AUDIO_SESSION)
        API::Feature::create("AudioSession API"""_s, "DOMAudioSessionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable AudioSession API"""_s, DEFAULT_VALUE_FOR_DOMAudioSessionEnabled, false),
#endif
#if ENABLE(DOM_AUDIO_SESSION)
        API::Feature::create("AudioSession full API"""_s, "DOMAudioSessionFullEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Enable AudioSession full API"""_s, DEFAULT_VALUE_FOR_DOMAudioSessionFullEnabled, false),
#endif
        API::Feature::create("Automatically Adjust View Scale"""_s, "AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Automatically Adjust View Scale to Fit Min. Effective Device Width"""_s, DEFAULT_VALUE_FOR_AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth, false),
        API::Feature::create("Beacon API"""_s, "BeaconAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Beacon API"""_s, DEFAULT_VALUE_FOR_BeaconAPIEnabled, false),
        API::Feature::create("Bidi Content Aware Paste"""_s, "BidiContentAwarePasteEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Bidi content aware paste"""_s, DEFAULT_VALUE_FOR_BidiContentAwarePasteEnabled, false),
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        API::Feature::create("Block Font service in the WebContent sandbox"""_s, "BlockFontServiceInWebContentSandbox"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Block Font service in the WebContent sandbox"""_s, DEFAULT_VALUE_FOR_BlockFontServiceInWebContentSandbox, false),
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        API::Feature::create("Block Icon services in the WebContent sandbox"""_s, "BlockIconServicesInWebContentSandbox"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Block Icon services in the WebContent sandbox"""_s, DEFAULT_VALUE_FOR_BlockIconServicesInWebContentSandbox, false),
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        API::Feature::create("Block MobileAsset service in the WebContent sandbox"""_s, "BlockMobileAssetInWebContentSandbox"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Block MobileAsset service in the WebContent sandbox"""_s, DEFAULT_VALUE_FOR_BlockMobileAssetInWebContentSandbox, false),
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(IOS)
        API::Feature::create("Block MobileGestalt service in the WebContent sandbox"""_s, "BlockMobileGestaltInWebContentSandbox"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Block MobileGestalt service in the WebContent sandbox"""_s, DEFAULT_VALUE_FOR_BlockMobileGestaltInWebContentSandbox, false),
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        API::Feature::create("Block OpenDirectory service in the WebContent sandbox"""_s, "BlockOpenDirectoryInWebContentSandbox"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Block OpenDirectory service in the WebContent sandbox"""_s, DEFAULT_VALUE_FOR_BlockOpenDirectoryInWebContentSandbox, false),
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        API::Feature::create("Block WebInspector service in the WebContent sandbox"""_s, "BlockWebInspectorInWebContentSandbox"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Block WebInspector service in the WebContent sandbox"""_s, DEFAULT_VALUE_FOR_BlockWebInspectorInWebContentSandbox, false),
#endif
        API::Feature::create("BroadcastChannel API"""_s, "BroadcastChannelEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "BroadcastChannel API"""_s, DEFAULT_VALUE_FOR_BroadcastChannelEnabled, false),
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
        API::Feature::create("Built-In Web Notifications"""_s, "BuiltInNotificationsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Enable built-in WebKit managed notifications"""_s, DEFAULT_VALUE_FOR_BuiltInNotificationsEnabled, false),
#endif
        API::Feature::create("CSS 3D Transform Interoperability for backface-visibility"""_s, "CSS3DTransformBackfaceVisibilityInteroperabilityEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::CSS, "Enable 3D transform behavior for backface-visibility that is specification-compliant but backwards incompatible"""_s, DEFAULT_VALUE_FOR_CSS3DTransformBackfaceVisibilityInteroperabilityEnabled, false),
        API::Feature::create("CSS @counter-style <image> symbols"""_s, "CSSCounterStyleAtRuleImageSymbolsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable support for <image> symbols in CSS @counter-style rules"""_s, DEFAULT_VALUE_FOR_CSSCounterStyleAtRuleImageSymbolsEnabled, false),
        API::Feature::create("CSS Accent Color"""_s, "AccentColorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable accent-color CSS property"""_s, DEFAULT_VALUE_FOR_AccentColorEnabled, false),
        API::Feature::create("CSS Anchor Positioning"""_s, "CSSAnchorPositioningEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable CSS Anchor Positioning (except position-visibility)"""_s, DEFAULT_VALUE_FOR_CSSAnchorPositioningEnabled, false),
        API::Feature::create("CSS Anchor Positioning: position-visibility"""_s, "CSSAnchorPositioningPositionVisibilityEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable position-visibility specified in CSS Anchor Positioning"""_s, DEFAULT_VALUE_FOR_CSSAnchorPositioningPositionVisibilityEnabled, false),
        API::Feature::create("CSS Devolvable Widgets"""_s, "DevolvableWidgetsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for devolvable widgets"""_s, DEFAULT_VALUE_FOR_DevolvableWidgetsEnabled, false),
        API::Feature::create("CSS Input Security"""_s, "CSSInputSecurityEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable input-security CSS property"""_s, DEFAULT_VALUE_FOR_CSSInputSecurityEnabled, false),
        API::Feature::create("CSS Masonry Layout"""_s, "MasonryEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::CSS, "Enable Masonry Layout for CSS Grid"""_s, DEFAULT_VALUE_FOR_MasonryEnabled, false),
        API::Feature::create("CSS Overscroll Behavior"""_s, "OverscrollBehaviorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable CSS overscroll-behavior"""_s, DEFAULT_VALUE_FOR_OverscrollBehaviorEnabled, false),
        API::Feature::create("CSS Painting API"""_s, "CSSPaintingAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable the CSS Painting API"""_s, DEFAULT_VALUE_FOR_CSSPaintingAPIEnabled, false),
        API::Feature::create("CSS Rhythmic Sizing"""_s, "CSSRhythmicSizingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable CSS Rhythmic Sizing properties"""_s, DEFAULT_VALUE_FOR_CSSRhythmicSizingEnabled, false),
        API::Feature::create("CSS Scroll Anchoring"""_s, "CSSScrollAnchoringEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable CSS Scroll Anchoring"""_s, DEFAULT_VALUE_FOR_CSSScrollAnchoringEnabled, false),
        API::Feature::create("CSS Spring Animations"""_s, "SpringTimingFunctionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::CSS, "CSS Spring Animation prototype"""_s, DEFAULT_VALUE_FOR_SpringTimingFunctionEnabled, false),
        API::Feature::create("CSS Tree Counting Functions"""_s, "CSSTreeCountingFunctionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for CSS Values and Units Module Level 5 tree counting functions sibling-count() and sibling-index()"""_s, DEFAULT_VALUE_FOR_CSSTreeCountingFunctionsEnabled, false),
        API::Feature::create("CSS Typed OM: Color Support"""_s, "CSSTypedOMColorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable the CSS Typed OM Color support"""_s, DEFAULT_VALUE_FOR_CSSTypedOMColorEnabled, false),
        API::Feature::create("CSS URL Modifiers"""_s, "CSSURLModifiersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for CSS Values and Units Module Level 5 URL modifiers"""_s, DEFAULT_VALUE_FOR_CSSURLModifiersEnabled, false),
        API::Feature::create("CSS URL Modifiers: integrity()"""_s, "CSSURLIntegrityModifierEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable support for CSS Values and Units Module Level 5 URL integrity() modifier"""_s, DEFAULT_VALUE_FOR_CSSURLIntegrityModifierEnabled, false),
        API::Feature::create("CSS Unprefixed Backdrop Filter"""_s, "CSSUnprefixedBackdropFilterEnabled"_s, API::FeatureConstant<API::FeatureStatus::Backdropfilter_feature_status>{}, API::FeatureCategory::CSS, "Enable unprefixed backdrop-filter CSS property"""_s, DEFAULT_VALUE_FOR_CSSUnprefixedBackdropFilterEnabled, false),
        API::Feature::create("CSS appearance: base"""_s, "CSSAppearanceBaseEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable base value for CSS appearance"""_s, DEFAULT_VALUE_FOR_CSSAppearanceBaseEnabled, false),
        API::Feature::create("CSS axis relative keywords in <position>"""_s, "CSSAxisRelativePositionKeywordsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for CSS Values and Units Module Level 5 axis relative keywords in <position>"""_s, DEFAULT_VALUE_FOR_CSSAxisRelativePositionKeywordsEnabled, false),
        API::Feature::create("CSS background-clip: border-area"""_s, "CSSBackgroundClipBorderAreaEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable the border-area value for background-clip"""_s, DEFAULT_VALUE_FOR_CSSBackgroundClipBorderAreaEnabled, false),
        API::Feature::create("CSS color-layers()"""_s, "CSSColorLayersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::CSS, "Enable support for CSS color-layers()"""_s, DEFAULT_VALUE_FOR_CSSColorLayersEnabled, false),
        API::Feature::create("CSS contrast-color()"""_s, "CSSContrastColorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for CSS Color Module Level 5 contrast-color()"""_s, DEFAULT_VALUE_FOR_CSSContrastColorEnabled, false),
        API::Feature::create("CSS corner-shape property"""_s, "CSSCornerShapeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable support for CSS corner-shape property"""_s, DEFAULT_VALUE_FOR_CSSCornerShapeEnabled, false),
        API::Feature::create("CSS d property"""_s, "CSSDPropertyEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::CSS, "Enable support for the CSS d property and SVG d presentation attribute"""_s, DEFAULT_VALUE_FOR_CSSDPropertyEnabled, false),
        API::Feature::create("CSS dynamic-range-limit-mix()"""_s, "CSSDynamicRangeLimitMixEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable support for CSS dynamic-range-limit-mix(), but animation stays unsupported"""_s, DEFAULT_VALUE_FOR_CSSDynamicRangeLimitMixEnabled, false),
        API::Feature::create("CSS dynamic-range-limit: constrained"""_s, "CSSConstrainedDynamicRangeLimitEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable support for CSS dynamic-range-limit value constrained"""_s, DEFAULT_VALUE_FOR_CSSConstrainedDynamicRangeLimitEnabled, false),
        API::Feature::create("CSS field-sizing property"""_s, "CSSFieldSizingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::CSS, "Enable field-sizing CSS property"""_s, DEFAULT_VALUE_FOR_CSSFieldSizingEnabled, false),
        API::Feature::create("CSS font-variant-emoji property"""_s, "CSSFontVariantEmojiEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable the font-variant-emoji CSS property"""_s, DEFAULT_VALUE_FOR_CSSFontVariantEmojiEnabled, false),
        API::Feature::create("CSS line-clamp"""_s, "CSSLineClampEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::CSS, "Enable CSS line-clamp"""_s, DEFAULT_VALUE_FOR_CSSLineClampEnabled, false),
        API::Feature::create("CSS line-fit-edge"""_s, "CSSLineFitEdgeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::CSS, "Enable CSS line-fit-edge"""_s, DEFAULT_VALUE_FOR_CSSLineFitEdgeEnabled, false),
        API::Feature::create("CSS progress()"""_s, "CSSProgressFunctionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for CSS Values and Units Module Level 5 progress()"""_s, DEFAULT_VALUE_FOR_CSSProgressFunctionEnabled, false),
        API::Feature::create("CSS random()"""_s, "CSSRandomFunctionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::CSS, "Enable support for CSS Values and Units Module Level 5 random()"""_s, DEFAULT_VALUE_FOR_CSSRandomFunctionEnabled, false),
        API::Feature::create("CSS ruby-align property"""_s, "CSSRubyAlignEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable ruby-align"""_s, DEFAULT_VALUE_FOR_CSSRubyAlignEnabled, false),
        API::Feature::create("CSS ruby-overhang property"""_s, "CSSRubyOverhangEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable ruby-overhang"""_s, DEFAULT_VALUE_FOR_CSSRubyOverhangEnabled, false),
        API::Feature::create("CSS scrollbar-color property"""_s, "CSSScrollbarColorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable scrollbar-color CSS property"""_s, DEFAULT_VALUE_FOR_CSSScrollbarColorEnabled, false),
        API::Feature::create("CSS scrollbar-gutter property"""_s, "CSSScrollbarGutterEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable scrollbar-gutter CSS property"""_s, DEFAULT_VALUE_FOR_CSSScrollbarGutterEnabled, false),
        API::Feature::create("CSS scrollbar-width property"""_s, "CSSScrollbarWidthEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable scrollbar-width CSS property"""_s, DEFAULT_VALUE_FOR_CSSScrollbarWidthEnabled, false),
        API::Feature::create("CSS shape() function"""_s, "CSSShapeFunctionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable the CSS shape() function"""_s, DEFAULT_VALUE_FOR_CSSShapeFunctionEnabled, false),
        API::Feature::create("CSS text-autospace property"""_s, "CSSTextAutospaceEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable the property text-autospace, defined in CSS Text 4"""_s, DEFAULT_VALUE_FOR_CSSTextAutospaceEnabled, false),
        API::Feature::create("CSS text-box-trim property"""_s, "CSSTextBoxTrimEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable text-box-trim"""_s, DEFAULT_VALUE_FOR_CSSTextBoxTrimEnabled, false),
        API::Feature::create("CSS text-group-align property"""_s, "CSSTextGroupAlignEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable text-group-align CSS property"""_s, DEFAULT_VALUE_FOR_CSSTextGroupAlignEnabled, false),
        API::Feature::create("CSS text-justify property"""_s, "CSSTextJustifyEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable the property text-justify, defined in CSS Text 3"""_s, DEFAULT_VALUE_FOR_CSSTextJustifyEnabled, false),
        API::Feature::create("CSS text-spacing-trim property"""_s, "CSSTextSpacingTrimEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable the property text-spacing-trim, defined in CSS Text 4"""_s, DEFAULT_VALUE_FOR_CSSTextSpacingTrimEnabled, false),
        API::Feature::create("CSS text-underline-position: left right"""_s, "CSSTextUnderlinePositionLeftRightEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable the property text-underline-position left and right value support"""_s, DEFAULT_VALUE_FOR_CSSTextUnderlinePositionLeftRightEnabled, false),
        API::Feature::create("CSS text-wrap: pretty"""_s, "CSSTextWrapPrettyEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable the pretty value for text-wrap-style"""_s, DEFAULT_VALUE_FOR_CSSTextWrapPrettyEnabled, false),
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
        API::Feature::create("CSS transform-style: separated"""_s, "CSSTransformStyleSeparatedEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable transform-style: separated property to access the separated graphics layer"""_s, DEFAULT_VALUE_FOR_CSSTransformStyleSeparatedEnabled, false),
#endif
        API::Feature::create("Cache API"""_s, "CacheAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Cache API"""_s, DEFAULT_VALUE_FOR_CacheAPIEnabled, false),
        API::Feature::create("Canvas Color Spaces"""_s, "CanvasColorSpaceEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable use of predefined canvas color spaces"""_s, DEFAULT_VALUE_FOR_CanvasColorSpaceEnabled, false),
        API::Feature::create("Canvas Filters"""_s, "CanvasFiltersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Canvas Filters"""_s, DEFAULT_VALUE_FOR_CanvasFiltersEnabled, false),
        API::Feature::create("Canvas Layers"""_s, "CanvasLayersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable Canvas Layers"""_s, DEFAULT_VALUE_FOR_CanvasLayersEnabled, false),
#if USE(CA) || USE(SKIA)
        API::Feature::create("Canvas uses accelerated drawing"""_s, "CanvasUsesAcceleratedDrawing"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_CanvasUsesAcceleratedDrawing, false),
#endif
        API::Feature::create("CanvasRenderingContext2DSettings.pixelFormat"""_s, "CanvasPixelFormatEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Allow different pixel formats in 2D canvas"""_s, DEFAULT_VALUE_FOR_CanvasPixelFormatEnabled, false),
        API::Feature::create("Child Process Debuggability"""_s, "ChildProcessDebuggabilityEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable stopping child processes with a debugger"""_s, DEFAULT_VALUE_FOR_ChildProcessDebuggabilityEnabled, false),
        API::Feature::create("Clear-Site-Data HTTP Header"""_s, "ClearSiteDataHTTPHeaderEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Networking, "Enable Clear-Site-Data HTTP Header support"""_s, DEFAULT_VALUE_FOR_ClearSiteDataHTTPHeaderEnabled, false),
        API::Feature::create("Clear-Site-Data: 'executionContexts' support"""_s, "ClearSiteDataExecutionContextsSupportEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Networking, "Enable Clear-Site-Data: 'executionContexts' support"""_s, DEFAULT_VALUE_FOR_ClearSiteDataExecutionContextsSupportEnabled, false),
        API::Feature::create("Close Watcher API"""_s, "CloseWatcherEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::HTML, "Enable Close Watcher API"""_s, DEFAULT_VALUE_FOR_CloseWatcherEnabled, false),
        API::Feature::create("Color Inputs"""_s, "InputTypeColorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable input elements of type color"""_s, DEFAULT_VALUE_FOR_InputTypeColorEnabled, false),
        API::Feature::create("Compositing borders visible"""_s, "CompositingBordersVisible"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_CompositingBordersVisible, false),
        API::Feature::create("Compositing repaint counters visible"""_s, "CompositingRepaintCountersVisible"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_CompositingRepaintCountersVisible, false),
        API::Feature::create("Compression Stream API"""_s, "CompressionStreamEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Compression Stream API"""_s, DEFAULT_VALUE_FOR_CompressionStreamEnabled, false),
        API::Feature::create("Contact Picker API"""_s, "ContactPickerAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable the Contact Picker API"""_s, DEFAULT_VALUE_FOR_ContactPickerAPIEnabled, false),
        API::Feature::create("Content Inset Background Fill"""_s, "ContentInsetBackgroundFillEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Fill content insets with background colors"""_s, DEFAULT_VALUE_FOR_ContentInsetBackgroundFillEnabled, false),
        API::Feature::create("Cookie Consent API"""_s, "CookieConsentAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Enable cookie consent API"""_s, DEFAULT_VALUE_FOR_CookieConsentAPIEnabled, false),
        API::Feature::create("Cookie Store API CookieStoreManager"""_s, "CookieStoreManagerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable Cookie Store API CookieStoreManager which controls cookie change subscriptions for Service Workers"""_s, DEFAULT_VALUE_FOR_CookieStoreManagerEnabled, false),
        API::Feature::create("Cookie Store API Extended Attributes"""_s, "CookieStoreAPIExtendedAttributesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable Extended Attributes of the Cookie Store API"""_s, DEFAULT_VALUE_FOR_CookieStoreAPIExtendedAttributesEnabled, false),
        API::Feature::create("Cookie Store API"""_s, "CookieStoreAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Cookie Store API"""_s, DEFAULT_VALUE_FOR_CookieStoreAPIEnabled, false),
        API::Feature::create("Cookies Enabled"""_s, "CookieEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_CookieEnabled, false),
#if PLATFORM(MAC)
        API::Feature::create("Correct key event ordering with composition events"""_s, "InputMethodUsesCorrectKeyEventOrder"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, """"_s, DEFAULT_VALUE_FOR_InputMethodUsesCorrectKeyEventOrder, false),
#endif
        API::Feature::create("Cross document view-transitions"""_s, "CrossDocumentViewTransitionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for view-transitions cross-document"""_s, DEFAULT_VALUE_FOR_CrossDocumentViewTransitionsEnabled, false),
        API::Feature::create("Cross-Origin-Embedder-Policy (COEP) header"""_s, "CrossOriginEmbedderPolicyEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Security, "Support for Cross-Origin-Embedder-Policy (COEP) header"""_s, DEFAULT_VALUE_FOR_CrossOriginEmbedderPolicyEnabled, false),
        API::Feature::create("Cross-Origin-Opener-Policy (COOP) header"""_s, "CrossOriginOpenerPolicyEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Security, "Support for Cross-Origin-Opener-Policy (COOP) header"""_s, DEFAULT_VALUE_FOR_CrossOriginOpenerPolicyEnabled, false),
        API::Feature::create("Custom pasteboard data"""_s, "CustomPasteboardDataEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable custom clipboard types and better security model for clipboard API."""_s, DEFAULT_VALUE_FOR_CustomPasteboardDataEnabled, false),
        API::Feature::create("DOM Paste Access Requests"""_s, "DOMPasteAccessRequestsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable DOM Paste Access Requests"""_s, DEFAULT_VALUE_FOR_DOMPasteAccessRequestsEnabled, false),
        API::Feature::create("DOM mutation events"""_s, "MutationEventsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, """"_s, DEFAULT_VALUE_FOR_MutationEventsEnabled, false),
        API::Feature::create("DOM timer throttling enabled"""_s, "DOMTimersThrottlingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DOMTimersThrottlingEnabled, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("DTTZ also when root"""_s, "ZoomOnDoubleTapWhenRoot"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Double taps zoom, even if we dispatched a click on the root nodes"""_s, DEFAULT_VALUE_FOR_ZoomOnDoubleTapWhenRoot, false),
#endif
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("DTTZ always"""_s, "AlwaysZoomOnDoubleTap"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Double taps zoom, even if we dispatched a click anywhere"""_s, DEFAULT_VALUE_FOR_AlwaysZoomOnDoubleTap, false),
#endif
        API::Feature::create("Data Transfer Items"""_s, "DataTransferItemsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enables DataTransferItem in the clipboard API"""_s, DEFAULT_VALUE_FOR_DataTransferItemsEnabled, false),
        API::Feature::create("DataList Element"""_s, "DataListElementEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable datalist elements"""_s, DEFAULT_VALUE_FOR_DataListElementEnabled, false),
        API::Feature::create("Date Input"""_s, "InputTypeDateEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable input elements of type date"""_s, DEFAULT_VALUE_FOR_InputTypeDateEnabled, false),
        API::Feature::create("Date/Time inputs have editable components"""_s, "DateTimeInputsEditableComponentsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable multiple editable components in date/time inputs"""_s, DEFAULT_VALUE_FOR_DateTimeInputsEditableComponentsEnabled, false),
#if ENABLE(DECLARATIVE_WEB_PUSH)
        API::Feature::create("Declarative Web Push"""_s, "DeclarativeWebPush"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Declarative Web Push"""_s, DEFAULT_VALUE_FOR_DeclarativeWebPush, false),
#endif
        API::Feature::create("Defer async scripts until DOMContentLoaded or first-paint"""_s, "ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Defer async scripts until DOMContentLoaded or first-paint"""_s, DEFAULT_VALUE_FOR_ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint, false),
        API::Feature::create("Deprecation Reporting"""_s, "DeprecationReportingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable Deprecation Reporting"""_s, DEFAULT_VALUE_FOR_DeprecationReportingEnabled, false),
#if ENABLE(MEDIA_SOURCE)
        API::Feature::create("Detachable Media Source"""_s, "DetachableMediaSourceEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Media, "Detachable Media Source API"""_s, DEFAULT_VALUE_FOR_DetachableMediaSourceEnabled, false),
#endif
        API::Feature::create("Detect UA visual transitions"""_s, "UAVisualTransitionDetectionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable detection of UA visual transitions"""_s, DEFAULT_VALUE_FOR_UAVisualTransitionDetectionEnabled, false),
        API::Feature::create("Diagnostic logging enabled"""_s, "DiagnosticLoggingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DiagnosticLoggingEnabled, false),
#if ENABLE(WEB_AUTHN)
        API::Feature::create("Digital Credentials API"""_s, "DigitalCredentialsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable the Digital Credentials API"""_s, DEFAULT_VALUE_FOR_DigitalCredentialsEnabled, false),
#endif
        API::Feature::create("Directory Upload"""_s, "DirectoryUploadEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "input.webkitdirectory / dataTransferItem.webkitGetAsEntry()"""_s, DEFAULT_VALUE_FOR_DirectoryUploadEnabled, false),
        API::Feature::create("Disable Full 3rd-Party Cookie Blocking (ITP)"""_s, "IsThirdPartyCookieBlockingDisabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Privacy, "Disable full third-party cookie blocking when Intelligent Tracking Prevention is enabled"""_s, DEFAULT_VALUE_FOR_IsThirdPartyCookieBlockingDisabled, false),
        API::Feature::create("Disable Removal of Non-Cookie Data After 7 Days of No User Interaction (ITP)"""_s, "IsFirstPartyWebsiteDataRemovalDisabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Privacy, "Disable removal of all non-cookie website data after seven days of no user interaction when Intelligent Tracking Prevention is enabled"""_s, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalDisabled, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Disable screen size override"""_s, "DisableScreenSizeOverride"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_DisableScreenSizeOverride, false),
#endif
        API::Feature::create("Drop Near-Suspended Assertion After Delay"""_s, "ShouldDropNearSuspendedAssertionAfterDelay"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Causes processes to fully suspend after a delay"""_s, DEFAULT_VALUE_FOR_ShouldDropNearSuspendedAssertionAfterDelay, false),
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        API::Feature::create("Dynamic Content Scaling: DOM Rendering"""_s, "UseCGDisplayListsForDOMRendering"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Use Dynamic Content Scaling for DOM rendering"""_s, DEFAULT_VALUE_FOR_UseCGDisplayListsForDOMRendering, false),
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        API::Feature::create("Dynamic Content Scaling: Replay for Testing"""_s, "ReplayCGDisplayListsIntoBackingStore"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Replay Dynamic Content Scaling Display Lists into layer contents for testing"""_s, DEFAULT_VALUE_FOR_ReplayCGDisplayListsIntoBackingStore, false),
#endif
        API::Feature::create("Dynamic Site Interventions"""_s, "DynamicSiteInterventionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::None, "Enable dynamic site interventions for broken websites"""_s, DEFAULT_VALUE_FOR_DynamicSiteInterventionsEnabled, false),
        API::Feature::create("Embed Element"""_s, "EmbedElementEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Embed Element"""_s, DEFAULT_VALUE_FOR_EmbedElementEnabled, false),
#if PLATFORM(MAC)
        API::Feature::create("Enable Accessibility On Demand"""_s, "EnableAccessibilityOnDemand"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Enable Accessibility On Demand"""_s, DEFAULT_VALUE_FOR_EnableAccessibilityOnDemand, false),
#endif
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Enable Automatic Live Resize"""_s, "AutomaticLiveResizeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Automatically synchronize web view resize with painting"""_s, DEFAULT_VALUE_FOR_AutomaticLiveResizeEnabled, false),
#endif
        API::Feature::create("Enable Canvas fingerprinting-related quirk"""_s, "CanvasFingerprintingQuirkEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, """"_s, DEFAULT_VALUE_FOR_CanvasFingerprintingQuirkEnabled, false),
        API::Feature::create("Enable Element.currentCSSZoom"""_s, "EnableElementCurrentCSSZoom"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::DOM, "Enable Element.currentCSSZoom"""_s, DEFAULT_VALUE_FOR_EnableElementCurrentCSSZoom, false),
        API::Feature::create("Enable Enumerating All Network Interfaces"""_s, "EnumeratingAllNetworkInterfacesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_EnumeratingAllNetworkInterfacesEnabled, false),
        API::Feature::create("Enable Enumerating Visible Network Interfaces"""_s, "EnumeratingVisibleNetworkInterfacesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_EnumeratingVisibleNetworkInterfacesEnabled, false),
        API::Feature::create("Enable ICE Candidate Filtering"""_s, "ICECandidateFilteringEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable ICE Candidate Filtering"""_s, DEFAULT_VALUE_FOR_ICECandidateFilteringEnabled, false),
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
        API::Feature::create("Enable Legacy EME API"""_s, "LegacyEncryptedMediaAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable legacy EME API"""_s, DEFAULT_VALUE_FOR_LegacyEncryptedMediaAPIEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Enable Mock Capture Devices"""_s, "MockCaptureDevicesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable Mock Capture Devices"""_s, DEFAULT_VALUE_FOR_MockCaptureDevicesEnabled, false),
#endif
#if ENABLE(MODEL_PROCESS)
        API::Feature::create("Enable Model Process"""_s, "ModelProcessEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Load <model> content in a separate process"""_s, DEFAULT_VALUE_FOR_ModelProcessEnabled, false),
#endif
#if ENABLE(PDFJS)
        API::Feature::create("Enable PDF.js viewer"""_s, "PDFJSViewerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::HTML, "Enable PDF.js viewer"""_s, DEFAULT_VALUE_FOR_PDFJSViewerEnabled, false),
#endif
        API::Feature::create("Enable `auxclick` event"""_s, "AuxclickEventEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable the `auxclick` UI event"""_s, DEFAULT_VALUE_FOR_AuxclickEventEnabled, false),
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
        API::Feature::create("Enable background web content throttling via RunningBoard"""_s, "BackgroundWebContentRunningBoardThrottlingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::Networking, "Enable background web content throttling via RunningBoard"""_s, DEFAULT_VALUE_FOR_BackgroundWebContentRunningBoardThrottlingEnabled, false),
#endif
        API::Feature::create("Enable background-fetch API"""_s, "BackgroundFetchAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Networking, "Enable background-fetch API"""_s, DEFAULT_VALUE_FOR_BackgroundFetchAPIEnabled, false),
#if HAVE(SANDBOX_STATE_FLAGS)
        API::Feature::create("Enable debugging features in sandbox"""_s, "EnableDebuggingFeaturesInSandbox"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Security, "Enable debugging features in sandbox"""_s, DEFAULT_VALUE_FOR_EnableDebuggingFeaturesInSandbox, false),
#endif
#if HAVE(NETWORK_LOADER)
        API::Feature::create("Enable experimental network loader"""_s, "CFNetworkNetworkLoaderEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Networking, "Enable experimental network loader"""_s, DEFAULT_VALUE_FOR_CFNetworkNetworkLoaderEnabled, false),
#endif
#if HAVE(MACH_BOOTSTRAP_EXTENSION) || HAVE(SANDBOX_STATE_FLAGS)
        API::Feature::create("Enable experimental sandbox features"""_s, "ExperimentalSandboxEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Security, "Enable experimental sandbox features"""_s, DEFAULT_VALUE_FOR_ExperimentalSandboxEnabled, false),
#endif
        API::Feature::create("Enable the navigator.userAgentData JavaScript API"""_s, "NavigatorUserAgentDataJavaScriptAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, """"_s, DEFAULT_VALUE_FOR_NavigatorUserAgentDataJavaScriptAPIEnabled, false),
        API::Feature::create("Enforce blob backed file access valid for web process"""_s, "BlobFileAccessEnforcementEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::Security, "Validate file backed blobs were created by the correct web process"""_s, DEFAULT_VALUE_FOR_BlobFileAccessEnforcementEnabled, false),
        API::Feature::create("Enter Key Hint"""_s, "EnterKeyHintEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable the enterKeyHint HTML attribute"""_s, DEFAULT_VALUE_FOR_EnterKeyHintEnabled, false),
        API::Feature::create("Event Timing API"""_s, "EventTimingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable the Event Timing API and supporting instrumentation"""_s, DEFAULT_VALUE_FOR_EventTimingEnabled, false),
        API::Feature::create("EventHandler driven smooth keyboard scrolling"""_s, "EventHandlerDrivenSmoothKeyboardScrollingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable EventHandler driven smooth keyboard scrolling"""_s, DEFAULT_VALUE_FOR_EventHandlerDrivenSmoothKeyboardScrollingEnabled, false),
#if ENABLE(MEDIA_SESSION_COORDINATOR)
        API::Feature::create("Experimental MediaSession coordinator API"""_s, "MediaSessionCoordinatorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable experimental MediaSession coordinator API"""_s, DEFAULT_VALUE_FOR_MediaSessionCoordinatorEnabled, false),
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
        API::Feature::create("Experimental MediaSession playlist API"""_s, "MediaSessionPlaylistEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable experimental MediaSession playlist API"""_s, DEFAULT_VALUE_FOR_MediaSessionPlaylistEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Expose all capture devices when one is used"""_s, "ExposeCaptureDevicesAfterCaptureEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Expose all capture devices when one is used"""_s, DEFAULT_VALUE_FOR_ExposeCaptureDevicesAfterCaptureEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Expose the system default speaker as a specific device"""_s, "ExposeDefaultSpeakerAsSpecificDeviceEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Expose the system default speaker as a specific device"""_s, DEFAULT_VALUE_FOR_ExposeDefaultSpeakerAsSpecificDeviceEnabled, false),
#endif
        API::Feature::create("FTP support enabled"""_s, "FTPEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Networking, "FTP support enabled"""_s, DEFAULT_VALUE_FOR_FTPEnabled, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Fast clicks beat DTTZ"""_s, "PreferFasterClickOverDoubleTap"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Prefer a faster click over a double tap"""_s, DEFAULT_VALUE_FOR_PreferFasterClickOverDoubleTap, false),
#endif
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Fast clicks"""_s, "FasterClicksEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Support faster clicks on zoomable pages"""_s, DEFAULT_VALUE_FOR_FasterClicksEnabled, false),
#endif
        API::Feature::create("File System API"""_s, "FileSystemEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::DOM, "Enable File System API"""_s, DEFAULT_VALUE_FOR_FileSystemEnabled, false),
        API::Feature::create("File System WritableStream"""_s, "FileSystemWritableStreamEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable File System WritableStream API"""_s, DEFAULT_VALUE_FOR_FileSystemWritableStreamEnabled, false),
        API::Feature::create("FileReader API"""_s, "FileReaderAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "FileReader API"""_s, DEFAULT_VALUE_FOR_FileReaderAPIEnabled, false),
        API::Feature::create("Filter Link Decoration"""_s, "FilterLinkDecorationByDefaultEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::Networking, "Enable Filtering Link Decoration"""_s, DEFAULT_VALUE_FOR_FilterLinkDecorationByDefaultEnabled, false),
        API::Feature::create("Force Lockdown Mode Safe Font Parser"""_s, "ForceLockdownFontParserEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Security, "Forcing the Lockdown Mode Safe Font Parser independently from Lockdown Mode state"""_s, DEFAULT_VALUE_FOR_ForceLockdownFontParserEnabled, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Force always user-scalable"""_s, "ForceAlwaysUserScalable"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ForceAlwaysUserScalable, false),
#endif
#if ENABLE(FORM_CONTROL_REFRESH)
        API::Feature::create("Form control refresh for Cocoa platforms"""_s, "FormControlRefreshEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable form control refresh for Cocoa platforms"""_s, DEFAULT_VALUE_FOR_FormControlRefreshEnabled, false),
#endif
#if ENABLE(CONTENT_EXTENSIONS)
        API::Feature::create("Frame Resource Monitoring Settings For Testing"""_s, "IFrameResourceMonitoringTestingSettingsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Use Resource Monitoring Settings for testing"""_s, DEFAULT_VALUE_FOR_IFrameResourceMonitoringTestingSettingsEnabled, false),
#endif
#if ENABLE(CONTENT_EXTENSIONS)
        API::Feature::create("Frame Resource Monitoring Support"""_s, "IFrameResourceMonitoringEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Enable Usage Monitoring of Frame Resource Support"""_s, DEFAULT_VALUE_FOR_IFrameResourceMonitoringEnabled, false),
#endif
#if ENABLE(FULLSCREEN_API)
        API::Feature::create("Fullscreen API based Keyboard Lock"""_s, "FullScreenKeyboardLock"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Fullscreen API based Keyboard Lock"""_s, DEFAULT_VALUE_FOR_FullScreenKeyboardLock, false),
#endif
#if ENABLE(FULLSCREEN_API)
        API::Feature::create("Fullscreen API"""_s, "FullScreenEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Fullscreen API"""_s, DEFAULT_VALUE_FOR_FullScreenEnabled, EXPERIMENTAL_FULLSCREEN_API_HIDDEN),
#endif
#if PLATFORM(VISION)
        API::Feature::create("Fullscreen scene aspect ratio locking"""_s, "FullscreenSceneAspectRatioLockingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable scene aspect ratio locking in Fullscreen"""_s, DEFAULT_VALUE_FOR_FullscreenSceneAspectRatioLockingEnabled, false),
#endif
#if PLATFORM(VISION)
        API::Feature::create("Fullscreen scene dimming"""_s, "FullscreenSceneDimmingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable scene dimming in Fullscreen"""_s, DEFAULT_VALUE_FOR_FullscreenSceneDimmingEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("GPU Process: Audio Capture"""_s, "CaptureAudioInGPUProcessEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable audio capture in GPU Process"""_s, DEFAULT_VALUE_FOR_CaptureAudioInGPUProcessEnabled, false),
#endif
#if ENABLE(GPU_PROCESS)
        API::Feature::create("GPU Process: Block Media Layer Re-hosting"""_s, "BlockMediaLayerRehostingInWebContentProcess"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "GPU Process: Block Media Layer Re-hosting in WebContent process"""_s, DEFAULT_VALUE_FOR_BlockMediaLayerRehostingInWebContentProcess, false),
#endif
#if ENABLE(GPU_PROCESS) && !(PLATFORM(GTK) || PLATFORM(WPE))
        API::Feature::create("GPU Process: Canvas Rendering"""_s, "UseGPUProcessForCanvasRenderingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable canvas rendering in GPU Process"""_s, DEFAULT_VALUE_FOR_UseGPUProcessForCanvasRenderingEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
        API::Feature::create("GPU Process: Capture Status Bar management"""_s, "ManageCaptureStatusBarInGPUProcessEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable Capture Status Bar management in GPU Process"""_s, DEFAULT_VALUE_FOR_ManageCaptureStatusBarInGPUProcessEnabled, false),
#endif
#if ENABLE(GPU_PROCESS)
        API::Feature::create("GPU Process: DOM Rendering"""_s, "UseGPUProcessForDOMRenderingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable DOM rendering in GPU Process"""_s, DEFAULT_VALUE_FOR_UseGPUProcessForDOMRenderingEnabled, false),
#endif
#if ENABLE(GPU_PROCESS)
        API::Feature::create("GPU Process: Media"""_s, "UseGPUProcessForMediaEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Do all media loading and playback in the GPU Process"""_s, DEFAULT_VALUE_FOR_UseGPUProcessForMediaEnabled, false),
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
        API::Feature::create("GPU Process: Screen and Window capture"""_s, "UseGPUProcessForDisplayCapture"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Display capture in GPU Process"""_s, DEFAULT_VALUE_FOR_UseGPUProcessForDisplayCapture, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("GPU Process: Video Capture"""_s, "CaptureVideoInGPUProcessEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable video capture in GPU Process"""_s, DEFAULT_VALUE_FOR_CaptureVideoInGPUProcessEnabled, false),
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
        API::Feature::create("GPU Process: WebGL"""_s, "UseGPUProcessForWebGLEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Process all WebGL operations in GPU Process"""_s, DEFAULT_VALUE_FOR_UseGPUProcessForWebGLEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("GPU Process: WebRTC Platform Codecs"""_s, "WebRTCPlatformCodecsInGPUProcessEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable WebRTC Platform Codecs in GPU Process"""_s, DEFAULT_VALUE_FOR_WebRTCPlatformCodecsInGPUProcessEnabled, false),
#endif
#if ENABLE(GAMEPAD)
        API::Feature::create("Gamepad trigger vibration support"""_s, "GamepadTriggerRumbleEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Support for Gamepad trigger vibration"""_s, DEFAULT_VALUE_FOR_GamepadTriggerRumbleEnabled, false),
#endif
#if ENABLE(GAMEPAD)
        API::Feature::create("Gamepad.vibrationActuator support"""_s, "GamepadVibrationActuatorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Support for Gamepad.vibrationActuator"""_s, DEFAULT_VALUE_FOR_GamepadVibrationActuatorEnabled, false),
#endif
#if ENABLE(GAMEPAD)
        API::Feature::create("Gamepads"""_s, "GamepadsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Web Gamepad API support"""_s, DEFAULT_VALUE_FOR_GamepadsEnabled, false),
#endif
#if ENABLE(VIDEO)
        API::Feature::create("Generic Text Track Cue API"""_s, "GenericCueAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable Generic Text Track Cue API"""_s, DEFAULT_VALUE_FOR_GenericCueAPIEnabled, false),
#endif
        API::Feature::create("Geolocation API"""_s, "GeolocationAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable Geolocation API"""_s, DEFAULT_VALUE_FOR_GeolocationAPIEnabled, false),
#if USE(GRAPHICS_CONTEXT_FILTERS)
        API::Feature::create("GraphicsContext Filter Rendering"""_s, "GraphicsContextFiltersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "GraphicsContext Filter Rendering"""_s, DEFAULT_VALUE_FOR_GraphicsContextFiltersEnabled, false),
#endif
        API::Feature::create("GraphicsLayer accelerated drawing"""_s, "AcceleratedDrawingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable GraphicsLayer accelerated drawing"""_s, DEFAULT_VALUE_FOR_AcceleratedDrawingEnabled, false),
#if ENABLE(MODEL_ELEMENT)
        API::Feature::create("HTML <model> element"""_s, "ModelElementEnabled"_s, API::FeatureConstant<API::FeatureStatus::Modelelement_feature_status>{}, API::FeatureCategory::HTML, "Enable HTML <model> element"""_s, DEFAULT_VALUE_FOR_ModelElementEnabled, false),
#endif
#if ENABLE(MODEL_ELEMENT)
        API::Feature::create("HTML <model> elements for stand-alone document"""_s, "ModelDocumentEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::HTML, "Enable HTML <model> element for model documents"""_s, DEFAULT_VALUE_FOR_ModelDocumentEnabled, false),
#endif
        API::Feature::create("HTML Interactive Form Validation"""_s, "InteractiveFormValidationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "HTML interactive form validation"""_s, DEFAULT_VALUE_FOR_InteractiveFormValidationEnabled, false),
#if ENABLE(VIDEO)
        API::Feature::create("HTML Media Elements"""_s, "MediaEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable HTML media elements <audio>, <video> and <track>"""_s, DEFAULT_VALUE_FOR_MediaEnabled, false),
#endif
        API::Feature::create("HTML alpha and colorspace attribute support for color inputs"""_s, "InputTypeColorEnhancementsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::HTML, "Enable HTML alpha and colorspace attribute support for input elements of type color"""_s, DEFAULT_VALUE_FOR_InputTypeColorEnhancementsEnabled, false),
        API::Feature::create("HTML auto-expanding <details>"""_s, "DetailsAutoExpandEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::HTML, "Enable HTML auto-expanding <details>"""_s, DEFAULT_VALUE_FOR_DetailsAutoExpandEnabled, false),
        API::Feature::create("HTML command & commandfor attributes"""_s, "CommandAttributesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::HTML, "Enable HTML command & commandfor attribute support"""_s, DEFAULT_VALUE_FOR_CommandAttributesEnabled, false),
        API::Feature::create("HTML legacy attribute value serialization"""_s, "HTMLLegacyAttributeValueSerializationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable HTML legacy attribute value serialization"""_s, DEFAULT_VALUE_FOR_HTMLLegacyAttributeValueSerializationEnabled, false),
        API::Feature::create("HTML popover attribute"""_s, "PopoverAttributeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::HTML, "Enable HTML popover attribute support"""_s, DEFAULT_VALUE_FOR_PopoverAttributeEnabled, false),
        API::Feature::create("HTML switch control"""_s, "SwitchControlEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::HTML, "Enable HTML switch control"""_s, DEFAULT_VALUE_FOR_SwitchControlEnabled, false),
        API::Feature::create("HTTPS-by-default (HTTPS-First)"""_s, "HTTPSByDefaultEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Security, "Enable HTTPS-by-default (HTTPS-First)"""_s, DEFAULT_VALUE_FOR_HTTPSByDefaultEnabled, false),
        API::Feature::create("Hidden page DOM timer throttling auto-increases"""_s, "HiddenPageDOMTimerThrottlingAutoIncreases"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingAutoIncreases, false),
        API::Feature::create("Hidden page DOM timer throttling"""_s, "HiddenPageDOMTimerThrottlingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable hidden page DOM timer throttling"""_s, DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingEnabled, false),
#if HAVE(MATERIAL_HOSTING)
        API::Feature::create("Hosted blur material in media controls"""_s, "HostedBlurMaterialInMediaControlsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable hosted blur material in media controls"""_s, DEFAULT_VALUE_FOR_HostedBlurMaterialInMediaControlsEnabled, false),
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        API::Feature::create("IOKit blocking in the WebContent sandbox"""_s, "BlockIOKitInWebContentSandbox"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Block IOKit access in the WebContent sandbox"""_s, DEFAULT_VALUE_FOR_BlockIOKitInWebContentSandbox, false),
#endif
        API::Feature::create("IOSurface Lossless Compression"""_s, "IOSurfaceLosslessCompressionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Use losslessly compressed IOSurfaces"""_s, DEFAULT_VALUE_FOR_IOSurfaceLosslessCompressionEnabled, false),
#if ENABLE(IPC_TESTING_API)
        API::Feature::create("IPC Testing API"""_s, "IPCTestingAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Security, "Enable IPC Testing API for JavaScript"""_s, DEFAULT_VALUE_FOR_IPCTestingAPIEnabled, false),
#endif
        API::Feature::create("ITP Debug Mode"""_s, "ItpDebugModeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Privacy, "Intelligent Tracking Prevention Debug Mode"""_s, DEFAULT_VALUE_FOR_ItpDebugModeEnabled, false),
#if ENABLE(TEXT_AUTOSIZING)
        API::Feature::create("Idempotent Text Autosizing"""_s, "TextAutosizingUsesIdempotentMode"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Use idempotent text autosizing mode"""_s, DEFAULT_VALUE_FOR_TextAutosizingUsesIdempotentMode, false),
#endif
#if ENABLE(IPC_TESTING_API)
        API::Feature::create("Ignore Invalid IPC Messages For Testing"""_s, "IgnoreInvalidMessageWhenIPCTestingAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Security, "Prevents invalid IPC messages from terminating the caller"""_s, DEFAULT_VALUE_FOR_IgnoreInvalidMessageWhenIPCTestingAPIEnabled, false),
#endif
        API::Feature::create("Ignore iframe Embedding Protections"""_s, "IgnoreIframeEmbeddingProtectionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Security, "Ignores X-Frame-Options and CSP ancestors"""_s, DEFAULT_VALUE_FOR_IgnoreIframeEmbeddingProtectionsEnabled, false),
#if ENABLE(IMAGE_ANALYSIS)
        API::Feature::create("Image Analysis for Find-in-Page"""_s, "ImageAnalysisDuringFindInPageEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::None, "Trigger image analysis when performing Find-in-Page"""_s, DEFAULT_VALUE_FOR_ImageAnalysisDuringFindInPageEnabled, false),
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
        API::Feature::create("Image Animation Control"""_s, "ImageAnimationControlEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Animation, "Enable controls for image animations"""_s, DEFAULT_VALUE_FOR_ImageAnimationControlEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Image Capture API"""_s, "ImageCaptureEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Media, "Enable Image Capture API"""_s, DEFAULT_VALUE_FOR_ImageCaptureEnabled, false),
#endif
#if ENABLE(SERVICE_CONTROLS)
        API::Feature::create("Image Controls"""_s, "ImageControlsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Enable image controls"""_s, DEFAULT_VALUE_FOR_ImageControlsEnabled, false),
#endif
        API::Feature::create("In-Window Fullscreen"""_s, "InWindowFullscreenEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable In-Window Fullscreen"""_s, DEFAULT_VALUE_FOR_InWindowFullscreenEnabled, false),
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
        API::Feature::create("Include ignored elements in core accessibility tree"""_s, "IncludeIgnoredInCoreAXTree"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "When true, accessibility-is-ignored is not used to build the core, platform-agnostic accessibility tree, and instead is expected to be applied at any platform-exposed layer."""_s, DEFAULT_VALUE_FOR_IncludeIgnoredInCoreAXTree, false),
#endif
        API::Feature::create("IndexedDB API"""_s, "IndexedDBAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "IndexedDB API"""_s, DEFAULT_VALUE_FOR_IndexedDBAPIEnabled, false),
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
        API::Feature::create("Interaction Regions"""_s, "InteractionRegionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Generate and visualize interaction regions"""_s, DEFAULT_VALUE_FOR_InteractionRegionsEnabled, false),
#endif
#if ENABLE(ACCESSIBILITY_ISOLATED_TREE)
        API::Feature::create("Isolated Accessibility Tree Mode"""_s, "IsAccessibilityIsolatedTreeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable an accessibility hierarchy for VoiceOver that can be accessed on a secondary thread for improved performance"""_s, DEFAULT_VALUE_FOR_IsAccessibilityIsolatedTreeEnabled, false),
#endif
        API::Feature::create("JavaScript"""_s, "JavaScriptEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable JavaScript"""_s, DEFAULT_VALUE_FOR_JavaScriptEnabled, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Keyboard Dismissal Gesture"""_s, "KeyboardDismissalGestureEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable the keyboard dismissal gesture"""_s, DEFAULT_VALUE_FOR_KeyboardDismissalGestureEnabled, false),
#endif
        API::Feature::create("Layer-based SVG Engine (LBSE)"""_s, "LayerBasedSVGEngineEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::None, "Enable next-generation layer-based SVG Engine (LBSE)"""_s, DEFAULT_VALUE_FOR_LayerBasedSVGEngineEnabled, false),
        API::Feature::create("Lazy iframe loading"""_s, "LazyIframeLoadingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::HTML, "Enable lazy iframe loading support"""_s, DEFAULT_VALUE_FOR_LazyIframeLoadingEnabled, false),
        API::Feature::create("Lazy image loading"""_s, "LazyImageLoadingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::HTML, "Enable lazy image loading support"""_s, DEFAULT_VALUE_FOR_LazyImageLoadingEnabled, false),
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
        API::Feature::create("Legacy -webkit-overflow-scrolling property"""_s, "LegacyOverflowScrollingTouchEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Support the legacy -webkit-overflow-scrolling CSS property"""_s, DEFAULT_VALUE_FOR_LegacyOverflowScrollingTouchEnabled, false),
#endif
        API::Feature::create("Legacy line layout visual coverage"""_s, "LegacyLineLayoutVisualCoverageEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable legacy line layout visual coverage"""_s, DEFAULT_VALUE_FOR_LegacyLineLayoutVisualCoverageEnabled, false),
        API::Feature::create("Legacy showModalDialog() API"""_s, "ShowModalDialogEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::DOM, "Legacy showModalDialog() API"""_s, DEFAULT_VALUE_FOR_ShowModalDialogEnabled, false),
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Limit Media Capture to Secure Sites"""_s, "MediaCaptureRequiresSecureConnection"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Limit Media Capture to Secure Sites"""_s, DEFAULT_VALUE_FOR_MediaCaptureRequiresSecureConnection, false),
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
        API::Feature::create("Limited Matroska Support"""_s, "LimitedMatroskaSupportEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Media, "Enable H264 and PCM with WebM Player and MediaRecorder"""_s, DEFAULT_VALUE_FOR_LimitedMatroskaSupportEnabled, false),
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
        API::Feature::create("Linear Media Player"""_s, "LinearMediaPlayerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable LinearMediaPlayer for fullscreen video"""_s, DEFAULT_VALUE_FOR_LinearMediaPlayerEnabled, false),
#endif
        API::Feature::create("Link Sanitizer"""_s, "LinkSanitizerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::Networking, "Enable link sanitizer"""_s, DEFAULT_VALUE_FOR_LinkSanitizerEnabled, false),
        API::Feature::create("Link rel=preconnect via HTTP early hints"""_s, "LinkPreconnectEarlyHintsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Networking, "Enable link rel=preconnect via early hints"""_s, DEFAULT_VALUE_FOR_LinkPreconnectEarlyHintsEnabled, false),
        API::Feature::create("LinkPrefetch"""_s, "LinkPrefetchEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Networking, "Enable LinkedPrefetch"""_s, DEFAULT_VALUE_FOR_LinkPrefetchEnabled, false),
#if ENABLE(WEB_ARCHIVE)
        API::Feature::create("Load Web Archive with ephemeral storage"""_s, "LoadWebArchiveWithEphemeralStorageEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable loading web archive with ephemeral storage"""_s, DEFAULT_VALUE_FOR_LoadWebArchiveWithEphemeralStorageEnabled, false),
#endif
        API::Feature::create("Local File Content Sniffing"""_s, "LocalFileContentSniffingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Enable Local File Content Sniffing"""_s, DEFAULT_VALUE_FOR_LocalFileContentSniffingEnabled, false),
        API::Feature::create("Local Network Access"""_s, "LocalNetworkAccessEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::None, "Enable Local Network Access"""_s, DEFAULT_VALUE_FOR_LocalNetworkAccessEnabled, false),
        API::Feature::create("Local Storage"""_s, "LocalStorageEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable Local Storage"""_s, DEFAULT_VALUE_FOR_LocalStorageEnabled, false),
        API::Feature::create("Lockdown Mode Safe Fonts"""_s, "LockdownFontParserEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Security, "Try parsing Web fonts with safe font parser in Lockdown Mode"""_s, DEFAULT_VALUE_FOR_LockdownFontParserEnabled, false),
        API::Feature::create("Log page messages to system console"""_s, "LogsPageMessagesToSystemConsoleEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable logging page messages to system console"""_s, DEFAULT_VALUE_FOR_LogsPageMessagesToSystemConsoleEnabled, false),
        API::Feature::create("Login Status API"""_s, "LoginStatusAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable the proposed Login Status API"""_s, DEFAULT_VALUE_FOR_LoginStatusAPIEnabled, false),
        API::Feature::create("Main content user gesture override"""_s, "MainContentUserGestureOverrideEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable main content user gesture override"""_s, DEFAULT_VALUE_FOR_MainContentUserGestureOverrideEnabled, false),
#if ENABLE(MEDIA_SOURCE)
        API::Feature::create("Managed Media Source API"""_s, "ManagedMediaSourceEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Managed Media Source API"""_s, DEFAULT_VALUE_FOR_ManagedMediaSourceEnabled, false),
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
        API::Feature::create("Managed Media Source Requires AirPlay source"""_s, "ManagedMediaSourceNeedsAirPlay"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Managed Media Source Requires AirPlay source"""_s, DEFAULT_VALUE_FOR_ManagedMediaSourceNeedsAirPlay, false),
#endif
        API::Feature::create("MathML Core"""_s, "CoreMathMLEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Disable features removed from the MathML Core spec."""_s, DEFAULT_VALUE_FOR_CoreMathMLEnabled, false),
        API::Feature::create("Media Capabilities Extensions"""_s, "MediaCapabilitiesExtensionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Media Capabilities Extensions"""_s, DEFAULT_VALUE_FOR_MediaCapabilitiesExtensionsEnabled, false),
#if ENABLE(EXTENSION_CAPABILITIES)
        API::Feature::create("Media Capability Grants"""_s, "MediaCapabilityGrantsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable granting and revoking of media capabilities"""_s, DEFAULT_VALUE_FOR_MediaCapabilityGrantsEnabled, false),
#endif
        API::Feature::create("Media Playback Functionalities"""_s, "MediaPlaybackEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable media playback functionalities"""_s, DEFAULT_VALUE_FOR_MediaPlaybackEnabled, false),
#if ENABLE(MEDIA_SESSION)
        API::Feature::create("Media Session API"""_s, "MediaSessionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Media Session API"""_s, DEFAULT_VALUE_FOR_MediaSessionEnabled, false),
#endif
        API::Feature::create("Media Source API"""_s, "MediaSourceEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::Media, "Media Source API"""_s, DEFAULT_VALUE_FOR_MediaSourceEnabled, false),
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Media devices"""_s, "MediaDevicesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable media devices"""_s, DEFAULT_VALUE_FOR_MediaDevicesEnabled, false),
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
        API::Feature::create("MediaRecorder WebM"""_s, "MediaRecorderEnabledWebM"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Media, "Enable WebM support with MediaRecorder"""_s, DEFAULT_VALUE_FOR_MediaRecorderEnabledWebM, false),
#endif
#if ENABLE(MEDIA_RECORDER)
        API::Feature::create("MediaRecorder"""_s, "MediaRecorderEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "MediaRecorder"""_s, DEFAULT_VALUE_FOR_MediaRecorderEnabled, false),
#endif
        API::Feature::create("MediaSession capture related API"""_s, "MediaSessionCaptureToggleAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Media, "Enable MediaSession capture related API"""_s, DEFAULT_VALUE_FOR_MediaSessionCaptureToggleAPIEnabled, false),
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
        API::Feature::create("MediaSource in a Worker"""_s, "MediaSourceInWorkerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Media, "MediaSource in a Worker"""_s, DEFAULT_VALUE_FOR_MediaSourceInWorkerEnabled, false),
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
        API::Feature::create("MediaSource prefers DecompressionSession"""_s, "MediaSourcePrefersDecompressionSession"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Media, "MediaSource prefers DecompressionSession"""_s, DEFAULT_VALUE_FOR_MediaSourcePrefersDecompressionSession, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("MediaStreamTrack Processing"""_s, "MediaStreamTrackProcessingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable MediaStreamTrack Processing"""_s, DEFAULT_VALUE_FOR_MediaStreamTrackProcessingEnabled, false),
#endif
        API::Feature::create("Meta Viewport Interactive Widget"""_s, "MetaViewportInteractiveWidgetEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enable the interactive-widget attribute on the viewport meta element"""_s, DEFAULT_VALUE_FOR_MetaViewportInteractiveWidgetEnabled, false),
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
        API::Feature::create("Model noportal attribute"""_s, "ModelNoPortalAttributeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::None, "Enable Model noportal attribute support"""_s, DEFAULT_VALUE_FOR_ModelNoPortalAttributeEnabled, false),
#endif
#if USE(MODERN_AVCONTENTKEYSESSION)
        API::Feature::create("Modern AVContentKeySession"""_s, "ShouldUseModernAVContentKeySession"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Use modern AVContentKeySession"""_s, DEFAULT_VALUE_FOR_ShouldUseModernAVContentKeySession, false),
#endif
        API::Feature::create("Momentum Scrolling Animator"""_s, "MomentumScrollingAnimatorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Generate momentum events in WebKit instead of using those delivered by the system"""_s, DEFAULT_VALUE_FOR_MomentumScrollingAnimatorEnabled, false),
        API::Feature::create("Month Input"""_s, "InputTypeMonthEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable input elements of type month"""_s, DEFAULT_VALUE_FOR_InputTypeMonthEnabled, false),
#if ENABLE(TOUCH_EVENTS)
        API::Feature::create("Mouse events simulation"""_s, "MouseEventsSimulationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable mouse events dispatch along with touch events on iOS"""_s, DEFAULT_VALUE_FOR_MouseEventsSimulationEnabled, false),
#endif
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Mute Camera on Microphone Interruption"""_s, "MuteCameraOnMicrophoneInterruptionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Mute Camera on Microphone Interruption"""_s, DEFAULT_VALUE_FOR_MuteCameraOnMicrophoneInterruptionEnabled, false),
#endif
        API::Feature::create("Navigation API"""_s, "NavigationAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable Navigation API"""_s, DEFAULT_VALUE_FOR_NavigationAPIEnabled, false),
#if ENABLE(APP_BOUND_DOMAINS)
        API::Feature::create("Needs In-App Browser Privacy Quirks"""_s, "NeedsInAppBrowserPrivacyQuirks"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable quirks needed to support In-App Browser privacy"""_s, DEFAULT_VALUE_FOR_NeedsInAppBrowserPrivacyQuirks, false),
#endif
        API::Feature::create("Needs Site-Specific Quirks"""_s, "NeedsSiteSpecificQuirks"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable site-specific quirks"""_s, DEFAULT_VALUE_FOR_NeedsSiteSpecificQuirks, false),
        API::Feature::create("Needs storage access from file URLs quirk"""_s, "NeedsStorageAccessFromFileURLsQuirk"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_NeedsStorageAccessFromFileURLsQuirk, false),
        API::Feature::create("Next-generation flex layout integration (FFC)"""_s, "FlexFormattingContextIntegrationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable next-generation flex layout integration (FFC)"""_s, DEFAULT_VALUE_FOR_FlexFormattingContextIntegrationEnabled, false),
#if ENABLE(NOTIFICATION_EVENT)
        API::Feature::create("NotificationEvent support"""_s, "NotificationEventEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "NotificationEvent and ServiceWorkerRegistration.showNotification() support"""_s, DEFAULT_VALUE_FOR_NotificationEventEnabled, false),
#endif
#if ENABLE(NOTIFICATIONS)
        API::Feature::create("Notifications"""_s, "NotificationsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable the Notifications API"""_s, DEFAULT_VALUE_FOR_NotificationsEnabled, false),
#endif
        API::Feature::create("Observable API"""_s, "ObservableEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Support for the Observable API"""_s, DEFAULT_VALUE_FOR_ObservableEnabled, false),
#if ENABLE(AX_THREAD_TEXT_APIS)
        API::Feature::create("Off Main-Thread Accessibility Text APIs"""_s, "AccessibilityThreadTextApisEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Serve accessibility text APIs off the main-thread"""_s, DEFAULT_VALUE_FOR_AccessibilityThreadTextApisEnabled, false),
#endif
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
        API::Feature::create("OffscreenCanvas in Workers"""_s, "OffscreenCanvasInWorkersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Support for the OffscreenCanvas APIs in Workers"""_s, DEFAULT_VALUE_FOR_OffscreenCanvasInWorkersEnabled, false),
#endif
#if ENABLE(OFFSCREEN_CANVAS)
        API::Feature::create("OffscreenCanvas"""_s, "OffscreenCanvasEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Support for the OffscreenCanvas APIs"""_s, DEFAULT_VALUE_FOR_OffscreenCanvasEnabled, false),
#endif
        API::Feature::create("Opportunistic Sweeping and GC"""_s, "OpportunisticSweepingAndGarbageCollectionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Javascript, "Enable Opportunistic Sweeping and GC"""_s, DEFAULT_VALUE_FOR_OpportunisticSweepingAndGarbageCollectionEnabled, false),
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
        API::Feature::create("Opt-in partitioned cookies (CHIPS)"""_s, "OptInPartitionedCookiesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable opt-in partitioned cookies"""_s, DEFAULT_VALUE_FOR_OptInPartitionedCookiesEnabled, false),
#endif
        API::Feature::create("Overlapping backing stores"""_s, "OverlappingBackingStoreProvidersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable overlapping backing stores compositor optimization"""_s, DEFAULT_VALUE_FOR_OverlappingBackingStoreProvidersEnabled, false),
#if ENABLE(OVERLAY_REGIONS_IN_EVENT_REGION)
        API::Feature::create("Overlay Regions"""_s, "OverlayRegionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Generate and visualize overlay regions"""_s, DEFAULT_VALUE_FOR_OverlayRegionsEnabled, false),
#endif
        API::Feature::create("Page visibility-based process suppression"""_s, "PageVisibilityBasedProcessSuppressionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable page visibility-based process suppression"""_s, DEFAULT_VALUE_FOR_PageVisibilityBasedProcessSuppressionEnabled, false),
        API::Feature::create("Permissions API"""_s, "PermissionsAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Permissions API"""_s, DEFAULT_VALUE_FOR_PermissionsAPIEnabled, false),
#if HAVE(PHOTOS_UI)
        API::Feature::create("Photo Picker Prefers Original Image Format"""_s, "PhotoPickerPrefersOriginalImageFormat"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Prefer the original image format when selecting photos for file upload"""_s, DEFAULT_VALUE_FOR_PhotoPickerPrefersOriginalImageFormat, false),
#endif
#if HAVE(PIP_SKIP_PREROLL)
        API::Feature::create("Picture-in-Picture Playback State Enabled"""_s, "PictureInPicturePlaybackStateEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Picture-in-Picture Playback State Enabled"""_s, DEFAULT_VALUE_FOR_PictureInPicturePlaybackStateEnabled, false),
#endif
        API::Feature::create("Pointer Events getCoalescedEvents API"""_s, "GetCoalescedEventsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable the `getCoalescedEvents` function of the Pointer Events API"""_s, DEFAULT_VALUE_FOR_GetCoalescedEventsEnabled, false),
        API::Feature::create("Pointer Events getPredictedEvents API"""_s, "GetPredictedEventsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable the `getPredictedEvents` function of the Pointer Events API"""_s, DEFAULT_VALUE_FOR_GetPredictedEventsEnabled, false),
#if ENABLE(POINTER_LOCK)
        API::Feature::create("Pointer Lock API"""_s, "PointerLockEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable the Pointer Lock API"""_s, DEFAULT_VALUE_FOR_PointerLockEnabled, false),
#endif
#if ENABLE(POINTER_LOCK)
        API::Feature::create("Pointer Lock Options"""_s, "PointerLockOptionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Element.requestPointerLock(options) and promise support."""_s, DEFAULT_VALUE_FOR_PointerLockOptionsEnabled, false),
#endif
        API::Feature::create("Prefer Page Rendering Updates near 60fps"""_s, "PreferPageRenderingUpdatesNear60FPSEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Prefer page rendering updates near 60 frames per second rather than using the display's refresh rate"""_s, DEFAULT_VALUE_FOR_PreferPageRenderingUpdatesNear60FPSEnabled, false),
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
        API::Feature::create("Prefer Spatial Audio Experience over Spatial Tracking Labels"""_s, "PreferSpatialAudioExperience"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Prefer Spatial Audio Experience over Spatial Tracking Labels"""_s, DEFAULT_VALUE_FOR_PreferSpatialAudioExperience, false),
#endif
#if ENABLE(FULLSCREEN_API)
        API::Feature::create("Prefers most visible video in element fullscreen."""_s, "VideoFullsceenPrefersMostVisibleHeuristic"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Prefers most visible video in element fullscreen."""_s, DEFAULT_VALUE_FOR_VideoFullsceenPrefersMostVisibleHeuristic, false),
#endif
        API::Feature::create("Private Click Measurement Debug Mode"""_s, "PrivateClickMeasurementDebugModeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Privacy, "Enable Private Click Measurement Debug Mode"""_s, DEFAULT_VALUE_FOR_PrivateClickMeasurementDebugModeEnabled, false),
        API::Feature::create("Private Click Measurement Fraud Prevention"""_s, "PrivateClickMeasurementFraudPreventionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Privacy, "Enable Private Click Measurement Fraud Prevention"""_s, DEFAULT_VALUE_FOR_PrivateClickMeasurementFraudPreventionEnabled, false),
        API::Feature::create("Private Click Measurement"""_s, "PrivateClickMeasurementEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable Private Click Measurement for Cross-Site Link Navigations"""_s, DEFAULT_VALUE_FOR_PrivateClickMeasurementEnabled, false),
        API::Feature::create("Private Token usage by third party"""_s, "PrivateTokenUsageByThirdPartyEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Privacy, "Enable private token usage by third party"""_s, DEFAULT_VALUE_FOR_PrivateTokenUsageByThirdPartyEnabled, false),
#if ENABLE(DAMAGE_TRACKING)
        API::Feature::create("Propagate Damaging Information"""_s, "PropagateDamagingInformation"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Propagate Damaging Information"""_s, DEFAULT_VALUE_FOR_PropagateDamagingInformation, false),
#endif
        API::Feature::create("Push API"""_s, "PushAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::DOM, "Enable Push API"""_s, DEFAULT_VALUE_FOR_PushAPIEnabled, false),
        API::Feature::create("Quirk to get Mail to load signatures correctly with WebKitLegacy"""_s, "LegacyPluginQuirkForMailSignaturesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Quirk to get Mail to load signatures correctly with WebKitLegacy"""_s, DEFAULT_VALUE_FOR_LegacyPluginQuirkForMailSignaturesEnabled, false),
        API::Feature::create("Quirk to prevent delayed initial painting on sites using Google's Anti-Flicker optimization"""_s, "GoogleAntiFlickerOptimizationQuirkEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Quirk to prevent delayed initial painting on sites using Google's Anti-Flicker optimization"""_s, DEFAULT_VALUE_FOR_GoogleAntiFlickerOptimizationQuirkEnabled, false),
        API::Feature::create("ReadableByteStream"""_s, "ReadableByteStreamAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable Readable Byte Streams"""_s, DEFAULT_VALUE_FOR_ReadableByteStreamAPIEnabled, false),
        API::Feature::create("Remote MediaSessionManager"""_s, "RemoteMediaSessionManagerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::Media, "Enable MediaSessionManager in the GPU process"""_s, DEFAULT_VALUE_FOR_RemoteMediaSessionManagerEnabled, false),
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
        API::Feature::create("Remote Playback API"""_s, "RemotePlaybackEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable Remote Playback API"""_s, DEFAULT_VALUE_FOR_RemotePlaybackEnabled, false),
#endif
        API::Feature::create("Remote Snapshotting"""_s, "RemoteSnapshottingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, """"_s, DEFAULT_VALUE_FOR_RemoteSnapshottingEnabled, false),
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
        API::Feature::create("Remove Background"""_s, "RemoveBackgroundEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable Remove Background"""_s, DEFAULT_VALUE_FOR_RemoveBackgroundEnabled, false),
#endif
        API::Feature::create("RequestVideoFrameCallback"""_s, "RequestVideoFrameCallbackEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable RequestVideoFrameCallback API"""_s, DEFAULT_VALUE_FOR_RequestVideoFrameCallbackEnabled, false),
#if HAVE(SC_CONTENT_SHARING_PICKER)
        API::Feature::create("Require User Agent getDisplayMedia prompt"""_s, "RequireUAGetDisplayMediaPrompt"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Require and use User Agent getDisplayMedia prompt"""_s, DEFAULT_VALUE_FOR_RequireUAGetDisplayMediaPrompt, false),
#endif
        API::Feature::create("Require WebAuthn with the Login Status API"""_s, "LoginStatusAPIRequiresWebAuthnEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Require a recent WebAuthn authentication to set login status"""_s, DEFAULT_VALUE_FOR_LoginStatusAPIRequiresWebAuthnEnabled, false),
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Require a user gesture for speaker selection"""_s, "SpeakerSelectionRequiresUserGesture"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Require a user gesture for speaker selection"""_s, DEFAULT_VALUE_FOR_SpeakerSelectionRequiresUserGesture, false),
#endif
        API::Feature::create("Require being in Fullscreen to lock screen orientation"""_s, "FullscreenRequirementForScreenOrientationLockingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Require being in Fullscreen to lock screen orientation"""_s, DEFAULT_VALUE_FOR_FullscreenRequirementForScreenOrientationLockingEnabled, false),
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Require focus to start getUserMedia"""_s, "GetUserMediaRequiresFocus"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Require focus to start getUserMedia"""_s, DEFAULT_VALUE_FOR_GetUserMediaRequiresFocus, false),
#endif
        API::Feature::create("Resource Load Scheduling"""_s, "ResourceLoadSchedulingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Network process side priority and visibility based resource load scheduling"""_s, DEFAULT_VALUE_FOR_ResourceLoadSchedulingEnabled, false),
#if ENABLE(RESOURCE_USAGE)
        API::Feature::create("Resource usage overlay"""_s, "ResourceUsageOverlayVisible"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Make resource usage overlay visible"""_s, DEFAULT_VALUE_FOR_ResourceUsageOverlayVisible, false),
#endif
        API::Feature::create("Respond to thermal pressure aggressively"""_s, "RespondToThermalPressureAggressively"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable responding to thermal pressure aggressively"""_s, DEFAULT_VALUE_FOR_RespondToThermalPressureAggressively, false),
        API::Feature::create("SKAttribution"""_s, "SKAttributionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "SKAttribution"""_s, DEFAULT_VALUE_FOR_SKAttributionEnabled, false),
        API::Feature::create("Safe Browsing"""_s, "SafeBrowsingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable Safe Browsing"""_s, DEFAULT_VALUE_FOR_SafeBrowsingEnabled, false),
        API::Feature::create("SameSite strict enforcement (ITP)"""_s, "IsSameSiteStrictEnforcementEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::Privacy, "Enable SameSite strict enforcement to mitigate bounce tracking"""_s, DEFAULT_VALUE_FOR_IsSameSiteStrictEnforcementEnabled, false),
        API::Feature::create("Scoped custom element registry"""_s, "ScopedCustomElementRegistryEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable scoped custom element registry"""_s, DEFAULT_VALUE_FOR_ScopedCustomElementRegistryEnabled, false),
        API::Feature::create("Screen Orientation API (Locking / Unlocking)"""_s, "ScreenOrientationLockingAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable Screen Orientation API (Locking / Unlocking)"""_s, DEFAULT_VALUE_FOR_ScreenOrientationLockingAPIEnabled, false),
        API::Feature::create("Screen Orientation API"""_s, "ScreenOrientationAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Screen Orientation API"""_s, DEFAULT_VALUE_FOR_ScreenOrientationAPIEnabled, false),
#if ENABLE(SCREEN_TIME)
        API::Feature::create("Screen Time"""_s, "ScreenTimeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable Screen Time"""_s, DEFAULT_VALUE_FOR_ScreenTimeEnabled, false),
#endif
        API::Feature::create("Screen Wake Lock API"""_s, "ScreenWakeLockAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Screen Wake Lock API"""_s, DEFAULT_VALUE_FOR_ScreenWakeLockAPIEnabled, false),
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("ScreenCapture"""_s, "ScreenCaptureEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable ScreenCapture"""_s, DEFAULT_VALUE_FOR_ScreenCaptureEnabled, false),
#endif
        API::Feature::create("Script Tracking Privacy Logging"""_s, "ScriptTrackingPrivacyLoggingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Script tracking privacy logging enabled"""_s, DEFAULT_VALUE_FOR_ScriptTrackingPrivacyLoggingEnabled, false),
        API::Feature::create("Script Tracking Privacy Protections"""_s, "ScriptTrackingPrivacyProtectionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Script tracking privacy protections enabled"""_s, DEFAULT_VALUE_FOR_ScriptTrackingPrivacyProtectionsEnabled, false),
        API::Feature::create("Scroll Performance Testing Enabled"""_s, "ScrollingPerformanceTestingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enable behaviors used by scrolling performance tests"""_s, DEFAULT_VALUE_FOR_ScrollingPerformanceTestingEnabled, false),
        API::Feature::create("Scroll To Text Fragment Feature Detection"""_s, "ScrollToTextFragmentFeatureDetectionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Scroll To Text Fragment Feature Detection"""_s, DEFAULT_VALUE_FOR_ScrollToTextFragmentFeatureDetectionEnabled, false),
        API::Feature::create("Scroll To Text Fragment Generation"""_s, "ScrollToTextFragmentGenerationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Scroll To Text Fragment Generation Menu"""_s, DEFAULT_VALUE_FOR_ScrollToTextFragmentGenerationEnabled, false),
        API::Feature::create("Scroll To Text Fragment Indicator"""_s, "ScrollToTextFragmentIndicatorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable Scroll To Text Fragment Indicator"""_s, DEFAULT_VALUE_FOR_ScrollToTextFragmentIndicatorEnabled, false),
        API::Feature::create("Scroll To Text Fragment Marking"""_s, "ScrollToTextFragmentMarkingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable Scroll To Text Fragment Marking"""_s, DEFAULT_VALUE_FOR_ScrollToTextFragmentMarkingEnabled, false),
        API::Feature::create("Scroll To Text Fragment"""_s, "ScrollToTextFragmentEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Scroll To Text Fragment"""_s, DEFAULT_VALUE_FOR_ScrollToTextFragmentEnabled, false),
        API::Feature::create("Scroll animator"""_s, "ScrollAnimatorEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable scroll animator"""_s, DEFAULT_VALUE_FOR_ScrollAnimatorEnabled, false),
        API::Feature::create("Scroll-driven Animations"""_s, "ScrollDrivenAnimationsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Animation, "Enable Scroll-driven Animations"""_s, DEFAULT_VALUE_FOR_ScrollDrivenAnimationsEnabled, false),
        API::Feature::create("Secure Context Checks"""_s, "SecureContextChecksEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Security, "Allow access to HTTPS-only Web APIs over HTTP"""_s, DEFAULT_VALUE_FOR_SecureContextChecksEnabled, false),
        API::Feature::create("Selection Flipping"""_s, "SelectionFlippingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable Selection Flipping"""_s, DEFAULT_VALUE_FOR_SelectionFlippingEnabled, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Selection Honors Overflow Scrolling"""_s, "SelectionHonorsOverflowScrolling"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Selection honors overflow scrolling"""_s, DEFAULT_VALUE_FOR_SelectionHonorsOverflowScrolling, false),
#endif
        API::Feature::create("Service Worker Install Event"""_s, "ServiceWorkerInstallEventEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Networking, "Enable Service Worker Install Event API"""_s, DEFAULT_VALUE_FOR_ServiceWorkerInstallEventEnabled, false),
        API::Feature::create("Service Worker Navigation Preload"""_s, "ServiceWorkerNavigationPreloadEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Networking, "Enable Service Worker Navigation Preload API"""_s, DEFAULT_VALUE_FOR_ServiceWorkerNavigationPreloadEnabled, false),
        API::Feature::create("Service Workers"""_s, "ServiceWorkersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Service Workers"""_s, DEFAULT_VALUE_FOR_ServiceWorkersEnabled, false),
        API::Feature::create("Shape Detection API"""_s, "ShapeDetection"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Enable the Shape Detection API"""_s, DEFAULT_VALUE_FOR_ShapeDetection, false),
        API::Feature::create("Shared process for Site Isolation"""_s, "SiteIsolationSharedProcessEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::Security, "Put cross-site frames in a shared Web process"""_s, DEFAULT_VALUE_FOR_SiteIsolationSharedProcessEnabled, false),
        API::Feature::create("SharedWorker"""_s, "SharedWorkerEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enabled SharedWorker API"""_s, DEFAULT_VALUE_FOR_SharedWorkerEnabled, false),
        API::Feature::create("Show Media Stats"""_s, "ShowMediaStatsContextMenuItemEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Media, "Adds a 'Media Stats' context menu item to <video> when the Develop menu is enabled"""_s, DEFAULT_VALUE_FOR_ShowMediaStatsContextMenuItemEnabled, false),
        API::Feature::create("Show frame process borders"""_s, "ShowFrameProcessBordersEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_ShowFrameProcessBordersEnabled, false),
        API::Feature::create("Sideways writing modes"""_s, "SidewaysWritingModesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::CSS, "Enable support for sideways writing modes"""_s, DEFAULT_VALUE_FOR_SidewaysWritingModesEnabled, false),
        API::Feature::create("Site Isolation"""_s, "SiteIsolationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::Security, "Put cross-origin iframes in a different process"""_s, DEFAULT_VALUE_FOR_SiteIsolationEnabled, false),
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
        API::Feature::create("Spatial image controls API"""_s, "SpatialImageControlsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Spatial image controls API"""_s, DEFAULT_VALUE_FOR_SpatialImageControlsEnabled, false),
#endif
        API::Feature::create("SpeechRecognition API"""_s, "SpeechRecognitionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable SpeechRecognition of WebSpeech API"""_s, DEFAULT_VALUE_FOR_SpeechRecognitionEnabled, false),
        API::Feature::create("SpeechSynthesis API"""_s, "SpeechSynthesisAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "SpeechSynthesis API"""_s, DEFAULT_VALUE_FOR_SpeechSynthesisAPIEnabled, false),
        API::Feature::create("Storage API Estimate"""_s, "StorageAPIEstimateEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Storage API Estimate"""_s, DEFAULT_VALUE_FOR_StorageAPIEstimateEnabled, false),
        API::Feature::create("Storage API"""_s, "StorageAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Storage API"""_s, DEFAULT_VALUE_FOR_StorageAPIEnabled, false),
        API::Feature::create("Support HDR Compositor tonemapping"""_s, "SupportHDRCompositorTonemappingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Support HDR tonemapping during compositing"""_s, DEFAULT_VALUE_FOR_SupportHDRCompositorTonemappingEnabled, false),
        API::Feature::create("Support HDR Display"""_s, "SupportHDRDisplayEnabled"_s, API::FeatureConstant<API::FeatureStatus::Supporthdrdisplay_feature_status>{}, API::FeatureCategory::Media, "Support HDR Display"""_s, DEFAULT_VALUE_FOR_SupportHDRDisplayEnabled, false),
        API::Feature::create("Swap Processes on Cross-Site Navigation"""_s, "ProcessSwapOnCrossSiteNavigationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Networking, "Swap WebContent Processes on cross-site navigations"""_s, DEFAULT_VALUE_FOR_ProcessSwapOnCrossSiteNavigationEnabled, false),
        API::Feature::create("Take WebKit:NearSuspended assertions on background web content processes"""_s, "ShouldTakeNearSuspendedAssertions"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Take WebKit:NearSuspended assertions on background web content processes"""_s, DEFAULT_VALUE_FOR_ShouldTakeNearSuspendedAssertions, false),
#if ENABLE(WRITING_TOOLS)
        API::Feature::create("Text Animations"""_s, "TextAnimationsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Text Animations"""_s, DEFAULT_VALUE_FOR_TextAnimationsEnabled, false),
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
        API::Feature::create("Text Recognition in Videos"""_s, "TextRecognitionInVideosEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable Text Recognition in Videos"""_s, DEFAULT_VALUE_FOR_TextRecognitionInVideosEnabled, false),
#endif
#if ENABLE(MEDIA_SOURCE)
        API::Feature::create("Text Tracks in MSE"""_s, "TextTracksInMSEEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Enable Text Tracks in Media Source Extension"""_s, DEFAULT_VALUE_FOR_TextTracksInMSEEnabled, false),
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
        API::Feature::create("Threaded animation resolution"""_s, "ThreadedAnimationResolutionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::Animation, "Run accelerated animations on a separate thread"""_s, DEFAULT_VALUE_FOR_ThreadedAnimationResolutionEnabled, false),
#endif
        API::Feature::create("Tiled scrolling indicator"""_s, "TiledScrollingIndicatorVisible"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Make tiled scrolling indicator visible"""_s, DEFAULT_VALUE_FOR_TiledScrollingIndicatorVisible, false),
        API::Feature::create("Time Input"""_s, "InputTypeTimeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable input elements of type time"""_s, DEFAULT_VALUE_FOR_InputTypeTimeEnabled, false),
        API::Feature::create("Top Content Inset Background Can Change After Scrolling"""_s, "TopContentInsetBackgroundCanChangeAfterScrolling"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Top content inset background can change after scrolling"""_s, DEFAULT_VALUE_FOR_TopContentInsetBackgroundCanChangeAfterScrolling, false),
#if ENABLE(WEBXR)
        API::Feature::create("Touch Input Compatibility"""_s, "TouchInputCompatibilityEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Touch Input Compatibility"""_s, DEFAULT_VALUE_FOR_TouchInputCompatibilityEnabled, false),
#endif
        API::Feature::create("Track Configuration API"""_s, "TrackConfigurationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Track Configuration API"""_s, DEFAULT_VALUE_FOR_TrackConfigurationEnabled, false),
        API::Feature::create("Trusted Types"""_s, "TrustedTypesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Trusted Types"""_s, DEFAULT_VALUE_FOR_TrustedTypesEnabled, false),
        API::Feature::create("URL Pattern API"""_s, "URLPatternAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable URL Pattern API"""_s, DEFAULT_VALUE_FOR_URLPatternAPIEnabled, false),
        API::Feature::create("UndoManager DOM API"""_s, "UndoManagerAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Enable the UndoManager DOM API"""_s, DEFAULT_VALUE_FOR_UndoManagerAPIEnabled, false),
#if ENABLE(UNIFIED_PDF)
        API::Feature::create("Unified PDF Viewer"""_s, "UnifiedPDFEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Security, "Enable Unified PDF Viewer"""_s, DEFAULT_VALUE_FOR_UnifiedPDFEnabled, false),
#endif
#if ENABLE(DAMAGE_TRACKING)
        API::Feature::create("Unify Damaged Regions"""_s, "UnifyDamagedRegions"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Unify Damaged Regions"""_s, DEFAULT_VALUE_FOR_UnifyDamagedRegions, false),
#endif
        API::Feature::create("Upgrade IP addresses and localhost in mixed content"""_s, "IPAddressAndLocalhostMixedContentUpgradeTestingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Security, "Enable Upgrading IP addresses and localhost in mixed content"""_s, DEFAULT_VALUE_FOR_IPAddressAndLocalhostMixedContentUpgradeTestingEnabled, false),
        API::Feature::create("Upgrade known hosts to HTTPS"""_s, "UpgradeKnownHostsToHTTPSEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Networking, "Upgrade known hosts to HTTPS"""_s, DEFAULT_VALUE_FOR_UpgradeKnownHostsToHTTPSEnabled, false),
        API::Feature::create("Upgrade upgradable mixed content"""_s, "UpgradeMixedContentEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Networking, "Upgrade upgradable mixed content"""_s, DEFAULT_VALUE_FOR_UpgradeMixedContentEnabled, false),
#if ENABLE(ARKIT_INLINE_PREVIEW)
        API::Feature::create("Use ARKit for <model>"""_s, "UseARKitForModel"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Use ARKit for <model>"""_s, DEFAULT_VALUE_FOR_UseARKitForModel, false),
#endif
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
        API::Feature::create("Use AVCaptureDeviceRotationCoordinator API"""_s, "UseAVCaptureDeviceRotationCoordinatorAPI"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Use AVCaptureDeviceRotationCoordinator API"""_s, DEFAULT_VALUE_FOR_UseAVCaptureDeviceRotationCoordinatorAPI, false),
#endif
        API::Feature::create("Use IFC for SVG text"""_s, "UseIFCForSVGText"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Use IFC for SVG text rendering"""_s, DEFAULT_VALUE_FOR_UseIFCForSVGText, false),
#if ENABLE(MEDIA_STREAM)
        API::Feature::create("Use Microphone Mute Status API"""_s, "UseMicrophoneMuteStatusAPI"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Use Microphone Mute Status API"""_s, DEFAULT_VALUE_FOR_UseMicrophoneMuteStatusAPI, false),
#endif
#if HAVE(SCENEKIT)
        API::Feature::create("Use SceneKit for <model>"""_s, "UseSceneKitForModel"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::None, "Use SceneKit for <model>"""_s, DEFAULT_VALUE_FOR_UseSceneKitForModel, false),
#endif
        API::Feature::create("Use giant tiles"""_s, "UseGiantTiles"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_UseGiantTiles, false),
#if ENABLE(DAMAGE_TRACKING)
        API::Feature::create("Use the Damaging Information to optimize compositing"""_s, "UseDamagingInformationForCompositing"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Use the Damaging Information to optimize compositing"""_s, DEFAULT_VALUE_FOR_UseDamagingInformationForCompositing, false),
#endif
        API::Feature::create("User Activation API"""_s, "UserActivationAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable User Activation API"""_s, DEFAULT_VALUE_FOR_UserActivationAPIEnabled, false),
        API::Feature::create("UserGesture Promise Propagation"""_s, "UserGesturePromisePropagationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "UserGesture Promise Propagation"""_s, DEFAULT_VALUE_FOR_UserGesturePromisePropagationEnabled, false),
#if HAVE(WEBCONTENTRESTRICTIONS)
        API::Feature::create("Uses WebContentRestriction framework for content filter"""_s, "UsesWebContentRestrictionsForFilter"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, """"_s, DEFAULT_VALUE_FOR_UsesWebContentRestrictionsForFilter, false),
#endif
        API::Feature::create("Validate UserGesture requirements in Service Workers"""_s, "ServiceWorkersUserGestureEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Validate UserGesture requirements in Service Workers"""_s, DEFAULT_VALUE_FOR_ServiceWorkersUserGestureEnabled, false),
        API::Feature::create("Verify window.open user gesture"""_s, "VerifyWindowOpenUserGestureFromUIProcess"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Security, "Verifies that the user gesture for window.open came from the UI process"""_s, DEFAULT_VALUE_FOR_VerifyWindowOpenUserGestureFromUIProcess, false),
        API::Feature::create("Vertical form control support"""_s, "VerticalFormControlsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::HTML, "Enable support for form controls in vertical writing mode"""_s, DEFAULT_VALUE_FOR_VerticalFormControlsEnabled, false),
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        API::Feature::create("VideoMediaSampleRenderer fallback to AVSBDL for protected content disabled"""_s, "VideoRendererProtectedFallbackDisabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Media, "VideoMediaSampleRenderer fallback to AVSBDL for protected content disabled"""_s, DEFAULT_VALUE_FOR_VideoRendererProtectedFallbackDisabled, false),
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        API::Feature::create("VideoMediaSampleRenderer use DecompressionSession for protected content"""_s, "VideoRendererUseDecompressionSessionForProtected"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::Media, "VideoMediaSampleRenderer use DecompressionSession for protected content"""_s, DEFAULT_VALUE_FOR_VideoRendererUseDecompressionSessionForProtected, false),
#endif
        API::Feature::create("View Transition Classes"""_s, "ViewTransitionClassesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Animation, "Support specifying classes for view transitions"""_s, DEFAULT_VALUE_FOR_ViewTransitionClassesEnabled, false),
        API::Feature::create("View Transition Types"""_s, "ViewTransitionTypesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Animation, "Support specifying types for view transitions"""_s, DEFAULT_VALUE_FOR_ViewTransitionTypesEnabled, false),
        API::Feature::create("View Transitions"""_s, "ViewTransitionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Animation, "Enable the View Transitions API"""_s, DEFAULT_VALUE_FOR_ViewTransitionsEnabled, false),
        API::Feature::create("View gesture debugging"""_s, "ViewGestureDebuggingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable view gesture debugging"""_s, DEFAULT_VALUE_FOR_ViewGestureDebuggingEnabled, false),
#if ENABLE(IMAGE_ANALYSIS)
        API::Feature::create("Visual Translation"""_s, "VisualTranslationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable Visual Translation"""_s, DEFAULT_VALUE_FOR_VisualTranslationEnabled, false),
#endif
        API::Feature::create("Visual Viewport API"""_s, "VisualViewportAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable Visual Viewport API"""_s, DEFAULT_VALUE_FOR_VisualViewportAPIEnabled, false),
#if PLATFORM(IOS_FAMILY)
        API::Feature::create("Visually Contiguous Bidi Selection"""_s, "VisuallyContiguousBidiTextSelectionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Visually contiguous bidi selection"""_s, DEFAULT_VALUE_FOR_VisuallyContiguousBidiTextSelectionEnabled, false),
#endif
        API::Feature::create("Web API Statistics"""_s, "WebAPIStatisticsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Enable Web API Statistics"""_s, DEFAULT_VALUE_FOR_WebAPIStatisticsEnabled, false),
        API::Feature::create("Web APIs in ShadowRealm"""_s, "WebAPIsInShadowRealmEnabled"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "Enable Web APIs to be exposed in ShadowRealm"""_s, DEFAULT_VALUE_FOR_WebAPIsInShadowRealmEnabled, false),
        API::Feature::create("Web Animations 'overallProgress' property"""_s, "WebAnimationsOverallProgressPropertyEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Animation, "Support for Animation's overallProgress property"""_s, DEFAULT_VALUE_FOR_WebAnimationsOverallProgressPropertyEnabled, false),
        API::Feature::create("Web Animations custom effects"""_s, "WebAnimationsCustomEffectsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Animation, "Support for the CustomEffect interface"""_s, DEFAULT_VALUE_FOR_WebAnimationsCustomEffectsEnabled, false),
        API::Feature::create("Web Animations custom frame rate"""_s, "WebAnimationsCustomFrameRateEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Animation, "Support for specifying a custom frame rate for Web Animations"""_s, DEFAULT_VALUE_FOR_WebAnimationsCustomFrameRateEnabled, false),
#if ENABLE(WEB_ARCHIVE)
        API::Feature::create("Web Archive debug mode"""_s, "WebArchiveDebugModeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable web archive debug mode"""_s, DEFAULT_VALUE_FOR_WebArchiveDebugModeEnabled, false),
#endif
#if ENABLE(WEB_ARCHIVE)
        API::Feature::create("Web Archive testing mode"""_s, "WebArchiveTestingModeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, "Enable web archive testing mode"""_s, DEFAULT_VALUE_FOR_WebArchiveTestingModeEnabled, false),
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
        API::Feature::create("Web Authentication AuthenticationServices"""_s, "WebAuthenticationASEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable Modern Web Authentication support though AuthenticationServices"""_s, DEFAULT_VALUE_FOR_WebAuthenticationASEnabled, false),
#endif
#if ENABLE(WEB_AUTHN)
        API::Feature::create("Web Authentication"""_s, "WebAuthenticationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable Web Authentication support"""_s, DEFAULT_VALUE_FOR_WebAuthenticationEnabled, false),
#endif
        API::Feature::create("Web Crypto Safe Curves"""_s, "WebCryptoSafeCurvesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Web Crypto Safe Curves"""_s, DEFAULT_VALUE_FOR_WebCryptoSafeCurvesEnabled, false),
        API::Feature::create("Web Crypto X25519 algorithm"""_s, "WebCryptoX25519Enabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable Web Crypto X25519 algorithm"""_s, DEFAULT_VALUE_FOR_WebCryptoX25519Enabled, false),
        API::Feature::create("Web Locks API"""_s, "WebLocksAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Web Locks API"""_s, DEFAULT_VALUE_FOR_WebLocksAPIEnabled, false),
        API::Feature::create("Web Share API Level 2"""_s, "WebShareFileAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable level 2 of Web Share API"""_s, DEFAULT_VALUE_FOR_WebShareFileAPIEnabled, false),
        API::Feature::create("Web Share"""_s, "WebShareEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable support for share sheet via Web Share API"""_s, DEFAULT_VALUE_FOR_WebShareEnabled, false),
#if ENABLE(WEBASSEMBLY)
        API::Feature::create("WebAssembly ES module integration support"""_s, "WebAssemblyESMIntegrationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Javascript, "Support for allowing WebAssembly modules to integrate as ES modules"""_s, DEFAULT_VALUE_FOR_WebAssemblyESMIntegrationEnabled, false),
#endif
#if ENABLE(WEB_CODECS)
        API::Feature::create("WebCodecs AV1 codec"""_s, "WebCodecsAV1Enabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::Media, "Enable WebCodecs AV1 codec"""_s, DEFAULT_VALUE_FOR_WebCodecsAV1Enabled, false),
#endif
#if ENABLE(WEB_CODECS)
        API::Feature::create("WebCodecs Audio API"""_s, "WebCodecsAudioEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::Media, "Enable WebCodecs Audio API"""_s, DEFAULT_VALUE_FOR_WebCodecsAudioEnabled, false),
#endif
#if ENABLE(WEB_CODECS)
        API::Feature::create("WebCodecs HEVC codec"""_s, "WebCodecsHEVCEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable WebCodecs HEVC codec"""_s, DEFAULT_VALUE_FOR_WebCodecsHEVCEnabled, false),
#endif
#if ENABLE(WEB_CODECS)
        API::Feature::create("WebCodecs Video API"""_s, "WebCodecsVideoEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable WebCodecs Video API"""_s, DEFAULT_VALUE_FOR_WebCodecsVideoEnabled, false),
#endif
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
        API::Feature::create("WebExtension Bookmarks API"""_s, "WebExtensionBookmarksEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Extensions, "Enable support for WebExtensions using the Bookmarks API"""_s, DEFAULT_VALUE_FOR_WebExtensionBookmarksEnabled, false),
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
        API::Feature::create("WebExtension sidebarAction and sidePanel APIs"""_s, "WebExtensionSidebarEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Extensions, "Enable support for WebExtensions using the sidebarAction / sidePanel family of APIs"""_s, DEFAULT_VALUE_FOR_WebExtensionSidebarEnabled, false),
#endif
        API::Feature::create("WebGL Draft Extensions"""_s, "WebGLDraftExtensionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable WebGL extensions that are still in draft status"""_s, DEFAULT_VALUE_FOR_WebGLDraftExtensionsEnabled, false),
        API::Feature::create("WebGL Timer Queries"""_s, "WebGLTimerQueriesEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::DOM, "Enable WebGL extensions that provide GPU timer queries"""_s, DEFAULT_VALUE_FOR_WebGLTimerQueriesEnabled, false),
        API::Feature::create("WebGL"""_s, "WebGLEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable WebGL"""_s, DEFAULT_VALUE_FOR_WebGLEnabled, false),
        API::Feature::create("WebGPU support for HDR"""_s, "WebGPUHDREnabled"_s, API::FeatureConstant<API::FeatureStatus::Webgpuhdr_feature_status>{}, API::FeatureCategory::DOM, "WebGPU High Dynamic Range through canvas configuration tone mapping mode"""_s, DEFAULT_VALUE_FOR_WebGPUHDREnabled, false),
        API::Feature::create("WebGPU support for WebXR"""_s, "WebXRWebGPUBindingsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Webgpu_webxr_feature_status>{}, API::FeatureCategory::DOM, "Adds WebGPU support for WebXR"""_s, DEFAULT_VALUE_FOR_WebXRWebGPUBindingsEnabled, false),
        API::Feature::create("WebGPU"""_s, "WebGPUEnabled"_s, API::FeatureConstant<API::FeatureStatus::Webgpu_feature_status>{}, API::FeatureCategory::DOM, "Enable WebGPU"""_s, DEFAULT_VALUE_FOR_WebGPUEnabled, false),
        API::Feature::create("WebInspector engineering settings allowed"""_s, "WebInspectorEngineeringSettingsAllowed"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::DOM, """"_s, DEFAULT_VALUE_FOR_WebInspectorEngineeringSettingsAllowed, false),
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC AV1 codec"""_s, "WebRTCAV1CodecEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::Media, "Enable WebRTC AV1 codec"""_s, DEFAULT_VALUE_FOR_WebRTCAV1CodecEnabled, false),
#endif
        API::Feature::create("WebRTC Audio Latency Adaptation"""_s, "WebRTCAudioLatencyAdaptationEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable WebRTC Audio Latency Adaptation"""_s, DEFAULT_VALUE_FOR_WebRTCAudioLatencyAdaptationEnabled, false),
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC DTMF"""_s, "WebRTCDTMFEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable WebRTC DTMF"""_s, DEFAULT_VALUE_FOR_WebRTCDTMFEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC Encoded Transform API"""_s, "WebRTCEncodedTransformEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable WebRTC Encoded Transform API"""_s, DEFAULT_VALUE_FOR_WebRTCEncodedTransformEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC H264 Hardware encoder"""_s, "WebRTCH264HardwareEncoderEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable H264 Hardware encoder"""_s, DEFAULT_VALUE_FOR_WebRTCH264HardwareEncoderEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC HEVC codec"""_s, "WebRTCH265CodecEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable WebRTC HEVC codec"""_s, DEFAULT_VALUE_FOR_WebRTCH265CodecEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC L4S support"""_s, "WebRTCL4SEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Enable WebRTC L4S support"""_s, DEFAULT_VALUE_FOR_WebRTCL4SEnabled, false),
#endif
        API::Feature::create("WebRTC Media Pipeline Additional Logging"""_s, "WebRTCMediaPipelineAdditionalLoggingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable WebRTC Media Pipeline Additional Logging"""_s, DEFAULT_VALUE_FOR_WebRTCMediaPipelineAdditionalLoggingEnabled, false),
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC Peer Connection Legacy Offer options"""_s, "LegacyWebRTCOfferOptionsEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable RTCPeerConnection Legacy offer options (offerToReceiveAudio, offerToReceiveVideo)"""_s, DEFAULT_VALUE_FOR_LegacyWebRTCOfferOptionsEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC Peer Connection Video Scaling Adaptation"""_s, "PeerConnectionVideoScalingAdaptationDisabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Disable RTCPeerConnection Video Scaling Adaptation"""_s, DEFAULT_VALUE_FOR_PeerConnectionVideoScalingAdaptationDisabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC Peer Connection"""_s, "PeerConnectionEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable RTCPeerConnection"""_s, DEFAULT_VALUE_FOR_PeerConnectionEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC Remote Video Frame"""_s, "WebRTCRemoteVideoFrameEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable WebRTC Remote Video Frame"""_s, DEFAULT_VALUE_FOR_WebRTCRemoteVideoFrameEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC SFrame Transform API"""_s, "WebRTCSFrameTransformEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Media, "Enable WebRTC SFrame Transform API"""_s, DEFAULT_VALUE_FOR_WebRTCSFrameTransformEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC Sockets Proxying"""_s, "WebRTCSocketsProxyingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable WebRTC Sockets Proxying"""_s, DEFAULT_VALUE_FOR_WebRTCSocketsProxyingEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC VP9 profile 0 codec"""_s, "WebRTCVP9Profile0CodecEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable WebRTC VP9 profile 0 codec"""_s, DEFAULT_VALUE_FOR_WebRTCVP9Profile0CodecEnabled, false),
#endif
#if ENABLE(WEB_RTC)
        API::Feature::create("WebRTC VP9 profile 2 codec"""_s, "WebRTCVP9Profile2CodecEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::Media, "Enable WebRTC VP9 profile 2 codec"""_s, DEFAULT_VALUE_FOR_WebRTCVP9Profile2CodecEnabled, false),
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
        API::Feature::create("WebRTC interface monitoring via NW"""_s, "WebRTCInterfaceMonitoringViaNWEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::Media, "Enable WebRTC interface monitoring via NW"""_s, DEFAULT_VALUE_FOR_WebRTCInterfaceMonitoringViaNWEnabled, false),
#endif
        API::Feature::create("WebTransport"""_s, "WebTransportEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::Networking, "Enable WebTransport"""_s, DEFAULT_VALUE_FOR_WebTransportEnabled, false),
#if ENABLE(WEBXR)
        API::Feature::create("WebXR Augmented Reality Module"""_s, "WebXRAugmentedRealityModuleEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Adds support for the WebXR Augmented Reality Module"""_s, DEFAULT_VALUE_FOR_WebXRAugmentedRealityModuleEnabled, false),
#endif
#if ENABLE(WEBXR)
        API::Feature::create("WebXR Device API"""_s, "WebXREnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Adds support for accessing virtual reality (VR) and augmented reality (AR) devices, including sensors and head-mounted displays, on the Web"""_s, DEFAULT_VALUE_FOR_WebXREnabled, false),
#endif
#if ENABLE(WEBXR)
        API::Feature::create("WebXR Gamepads Module"""_s, "WebXRGamepadsModuleEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Adds support for the WebXR Gamepads Module"""_s, DEFAULT_VALUE_FOR_WebXRGamepadsModuleEnabled, false),
#endif
#if ENABLE(WEBXR_HANDS)
        API::Feature::create("WebXR Hand Input Module"""_s, "WebXRHandInputModuleEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Adds support for the Hands Input Module for WebXR"""_s, DEFAULT_VALUE_FOR_WebXRHandInputModuleEnabled, false),
#endif
#if ENABLE(WEBXR_LAYERS)
        API::Feature::create("WebXR Layers API"""_s, "WebXRLayersAPIEnabled"_s, API::FeatureConstant<API::FeatureStatus::Webxr_layers_feature_status>{}, API::FeatureCategory::DOM, "Adds support for the WebXR Layers API"""_s, DEFAULT_VALUE_FOR_WebXRLayersAPIEnabled, false),
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
        API::Feature::create("Website environments"""_s, "WebPageSpatialBackdropEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::HTML, "Enable website environments"""_s, DEFAULT_VALUE_FOR_WebPageSpatialBackdropEnabled, false),
#endif
        API::Feature::create("Week Input"""_s, "InputTypeWeekEnabled"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Enable input elements of type week"""_s, DEFAULT_VALUE_FOR_InputTypeWeekEnabled, false),
        API::Feature::create("Wheel Event gestures become non-blocking"""_s, "WheelEventGesturesBecomeNonBlocking"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "preventDefault() is only allowed on the first wheel event in a gesture"""_s, DEFAULT_VALUE_FOR_WheelEventGesturesBecomeNonBlocking, false),
        API::Feature::create("Wheel Event listeners on the root made passive"""_s, "PassiveWheelListenersAsDefaultOnDocument"_s, API::FeatureConstant<API::FeatureStatus::Embedder>{}, API::FeatureCategory::None, "Force wheel event listeners registered on the window, document or body to be passive"""_s, DEFAULT_VALUE_FOR_PassiveWheelListenersAsDefaultOnDocument, false),
        API::Feature::create("Worker asynchronous URL error handling"""_s, "WorkerAsynchronousURLErrorHandlingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::DOM, "Worker asynchronous URL error handling"""_s, DEFAULT_VALUE_FOR_WorkerAsynchronousURLErrorHandlingEnabled, false),
#if PLATFORM(COCOA)
        API::Feature::create("Write RTF on Copy"""_s, "WriteRichTextDataWhenCopyingOrDragging"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Write RTF, RTFD and attributed strings to the pasteboard when copying or dragging"""_s, DEFAULT_VALUE_FOR_WriteRichTextDataWhenCopyingOrDragging, false),
#endif
#if ENABLE(WRITING_SUGGESTIONS)
        API::Feature::create("Writing Suggestions"""_s, "WritingSuggestionsAttributeEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable the writingsuggestions attribute"""_s, DEFAULT_VALUE_FOR_WritingSuggestionsAttributeEnabled, false),
#endif
#if ENABLE(XSLT)
        API::Feature::create("XSLT Support Enabled"""_s, "XSLTEnabled"_s, API::FeatureConstant<API::FeatureStatus::Internal>{}, API::FeatureCategory::None, "Enables support for XSLT"""_s, DEFAULT_VALUE_FOR_XSLTEnabled, false),
#endif
        API::Feature::create("[ITP Live-On] 1 Hour Timeout For Non-Cookie Data Removal"""_s, "IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Privacy, "Remove all non-cookie website data after just one hour of no user interaction when Intelligent Tracking Prevention is enabled"""_s, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled, false),
        API::Feature::create("[ITP Repro] 30 Second Timeout For Non-Cookie Data Removal"""_s, "IsFirstPartyWebsiteDataRemovalReproTestingEnabled"_s, API::FeatureConstant<API::FeatureStatus::Developer>{}, API::FeatureCategory::Privacy, "Remove all non-cookie website data after just 30 seconds of no user interaction when Intelligent Tracking Prevention is enabled"""_s, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalReproTestingEnabled, false),
        API::Feature::create("altitudeAngle PointerEvent Property"""_s, "AltitudeAngleEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable the `altitudeAngle` property of the PointerEvents API"""_s, DEFAULT_VALUE_FOR_AltitudeAngleEnabled, false),
        API::Feature::create("azimuthAngle PointerEvent Property"""_s, "AzimuthAngleEnabled"_s, API::FeatureConstant<API::FeatureStatus::Stable>{}, API::FeatureCategory::DOM, "Enable the `azimuthAngle` property of the PointerEvents API"""_s, DEFAULT_VALUE_FOR_AzimuthAngleEnabled, false),
        API::Feature::create("datetime-local Inputs"""_s, "InputTypeDateTimeLocalEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable input elements of type datetime-local"""_s, DEFAULT_VALUE_FOR_InputTypeDateTimeLocalEnabled, false),
        API::Feature::create("document.caretPositionFromPoint() API"""_s, "CaretPositionFromPointEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable document.caretPositionFromPoint() API"""_s, DEFAULT_VALUE_FOR_CaretPositionFromPointEnabled, false),
        API::Feature::create("hidden=until-found"""_s, "HiddenUntilFoundEnabled"_s, API::FeatureConstant<API::FeatureStatus::Preview>{}, API::FeatureCategory::HTML, "Enable support for hidden=until-found"""_s, DEFAULT_VALUE_FOR_HiddenUntilFoundEnabled, false),
        API::Feature::create("http-equiv"""_s, "HTTPEquivEnabled"_s, API::FeatureConstant<API::FeatureStatus::Mature>{}, API::FeatureCategory::None, "Enable http-equiv attribute"""_s, DEFAULT_VALUE_FOR_HTTPEquivEnabled, false),
        API::Feature::create("referenceTarget support for aria-owns"""_s, "ShadowRootReferenceTargetEnabledForAriaOwns"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable referenceTarget support for aria-owns and ariaOwnsElements"""_s, DEFAULT_VALUE_FOR_ShadowRootReferenceTargetEnabledForAriaOwns, false),
        API::Feature::create("referenceTarget"""_s, "ShadowRootReferenceTargetEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable setting a referenceTarget on shadow roots"""_s, DEFAULT_VALUE_FOR_ShadowRootReferenceTargetEnabled, false),
        API::Feature::create("requestIdleCallback"""_s, "RequestIdleCallbackEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable requestIdleCallback support"""_s, DEFAULT_VALUE_FOR_RequestIdleCallbackEnabled, false),
        API::Feature::create("requestStorageAccess throws execption until reload"""_s, "RequestStorageAccessThrowsExceptionUntilReload"_s, API::FeatureConstant<API::FeatureStatus::Unstable>{}, API::FeatureCategory::DOM, "requestStorageAccess throws execption until reload"""_s, DEFAULT_VALUE_FOR_RequestStorageAccessThrowsExceptionUntilReload, false),
        API::Feature::create("scrollend event"""_s, "ScrollendEventEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::DOM, "Enable scrollend event"""_s, DEFAULT_VALUE_FOR_ScrollendEventEnabled, false),
        API::Feature::create("word-break: auto-phrase enabled"""_s, "CSSWordBreakAutoPhraseEnabled"_s, API::FeatureConstant<API::FeatureStatus::Testable>{}, API::FeatureCategory::CSS, "Enables the auto-phrase value of the word-break CSS property"""_s, DEFAULT_VALUE_FOR_CSSWordBreakAutoPhraseEnabled, false),
    });

    return features;
}

bool WebPreferences::isFeatureEnabled(const API::Feature& feature) const
{
    struct FeatureGetterMapping {
        ASCIILiteral name;
        bool (WebPreferences::*function) () const;
    };

    static FeatureGetterMapping getters[] = {
        { "DatabasesEnabled"_s, &WebPreferences::databasesEnabled },
        { "LoadDeferringEnabled"_s, &WebPreferences::loadDeferringEnabled },
        { "AcceleratedCompositingEnabled"_s, &WebPreferences::acceleratedCompositingEnabled },
        { "AcceleratedCompositingForFixedPositionEnabled"_s, &WebPreferences::acceleratedCompositingForFixedPositionEnabled },
        { "WirelessPlaybackTargetAPIEnabled"_s, &WebPreferences::wirelessPlaybackTargetAPIEnabled },
        { "LoadsImagesAutomatically"_s, &WebPreferences::loadsImagesAutomatically },
        { "LinkPreconnect"_s, &WebPreferences::linkPreconnect },
        { "WindowFocusRestricted"_s, &WebPreferences::windowFocusRestricted },
        { "AggressiveTileRetentionEnabled"_s, &WebPreferences::aggressiveTileRetentionEnabled },
        { "AllowContentSecurityPolicySourceStarToMatchAnyProtocol"_s, &WebPreferences::allowContentSecurityPolicySourceStarToMatchAnyProtocol },
        { "AllowDisplayOfInsecureContent"_s, &WebPreferences::allowDisplayOfInsecureContent },
        { "AllowFileAccessFromFileURLs"_s, &WebPreferences::allowFileAccessFromFileURLs },
        { "LowPowerVideoAudioBufferSizeEnabled"_s, &WebPreferences::lowPowerVideoAudioBufferSizeEnabled },
        { "AllowMultiElementImplicitSubmission"_s, &WebPreferences::allowMultiElementImplicitSubmission },
        { "AllowRunningOfInsecureContent"_s, &WebPreferences::allowRunningOfInsecureContent },
        { "AllowTestOnlyIPC"_s, &WebPreferences::allowTestOnlyIPC },
#if ENABLE(MATHML)
        { "MathMLEnabled"_s, &WebPreferences::mathMLEnabled },
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
        { "AllowsAirPlayForMediaPlayback"_s, &WebPreferences::allowsAirPlayForMediaPlayback },
#endif
        { "AllowsInlineMediaPlayback"_s, &WebPreferences::allowsInlineMediaPlayback },
        { "AllowsInlineMediaPlaybackAfterFullscreen"_s, &WebPreferences::allowsInlineMediaPlaybackAfterFullscreen },
        { "AllowsPictureInPictureMediaPlayback"_s, &WebPreferences::allowsPictureInPictureMediaPlayback },
#if PLATFORM(IOS_FAMILY)
        { "AlternateFullScreenControlDesignEnabled"_s, &WebPreferences::alternateFullScreenControlDesignEnabled },
#endif
        { "WebSocketEnabled"_s, &WebPreferences::webSocketEnabled },
        { "MediaCapabilitiesEnabled"_s, &WebPreferences::mediaCapabilitiesEnabled },
        { "WebSecurityEnabled"_s, &WebPreferences::webSecurityEnabled },
        { "AnimatedImageAsyncDecodingEnabled"_s, &WebPreferences::animatedImageAsyncDecodingEnabled },
        { "AppleMailPaginationQuirkEnabled"_s, &WebPreferences::appleMailPaginationQuirkEnabled },
#if ENABLE(APPLE_PAY)
        { "ApplePayCapabilityDisclosureAllowed"_s, &WebPreferences::applePayCapabilityDisclosureAllowed },
#endif
#if ENABLE(APPLE_PAY)
        { "ApplePayEnabled"_s, &WebPreferences::applePayEnabled },
#endif
        { "LargeImageAsyncDecodingEnabled"_s, &WebPreferences::largeImageAsyncDecodingEnabled },
        { "AsynchronousSpellCheckingEnabled"_s, &WebPreferences::asynchronousSpellCheckingEnabled },
        { "JavaScriptMarkupEnabled"_s, &WebPreferences::javaScriptMarkupEnabled },
        { "AudioControlsScaleWithPageZoom"_s, &WebPreferences::audioControlsScaleWithPageZoom },
        { "JavaScriptCanOpenWindowsAutomatically"_s, &WebPreferences::javaScriptCanOpenWindowsAutomatically },
        { "AuthorAndUserStylesEnabled"_s, &WebPreferences::authorAndUserStylesEnabled },
#if ENABLE(WEB_AUDIO)
        { "WebAudioEnabled"_s, &WebPreferences::webAudioEnabled },
#endif
        { "JavaScriptCanAccessClipboard"_s, &WebPreferences::javaScriptCanAccessClipboard },
        { "WantsBalancedSetDefersLoadingBehavior"_s, &WebPreferences::wantsBalancedSetDefersLoadingBehavior },
        { "VisualViewportEnabled"_s, &WebPreferences::visualViewportEnabled },
#if ENABLE(VIDEO)
        { "VideoQualityIncludesDisplayCompositingEnabled"_s, &WebPreferences::videoQualityIncludesDisplayCompositingEnabled },
#endif
        { "BackspaceKeyNavigationEnabled"_s, &WebPreferences::backspaceKeyNavigationEnabled },
        { "VideoPresentationModeAPIEnabled"_s, &WebPreferences::videoPresentationModeAPIEnabled },
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
        { "MediaControlsContextMenusEnabled"_s, &WebPreferences::mediaControlsContextMenusEnabled },
#endif
        { "VideoPresentationManagerEnabled"_s, &WebPreferences::videoPresentationManagerEnabled },
        { "MediaControlsScaleWithPageZoom"_s, &WebPreferences::mediaControlsScaleWithPageZoom },
#if ENABLE(FULLSCREEN_API)
        { "VideoFullscreenRequiresElementFullscreen"_s, &WebPreferences::videoFullscreenRequiresElementFullscreen },
#endif
        { "MediaDataLoadsAutomatically"_s, &WebPreferences::mediaDataLoadsAutomatically },
        { "MediaPreloadingEnabled"_s, &WebPreferences::mediaPreloadingEnabled },
        { "InvisibleAutoplayNotPermitted"_s, &WebPreferences::invisibleAutoplayNotPermitted },
#if ENABLE(MEDIA_STREAM)
        { "InterruptVideoOnPageVisibilityChangeEnabled"_s, &WebPreferences::interruptVideoOnPageVisibilityChangeEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "InterruptAudioOnPageVisibilityChangeEnabled"_s, &WebPreferences::interruptAudioOnPageVisibilityChangeEnabled },
#endif
#if ENABLE(VP9)
        { "VP9DecoderEnabled"_s, &WebPreferences::vp9DecoderEnabled },
#endif
        { "MediaUserGestureInheritsFromDocument"_s, &WebPreferences::mediaUserGestureInheritsFromDocument },
        { "InspectorSupportsShowingCertificate"_s, &WebPreferences::inspectorSupportsShowingCertificate },
        { "InspectorStartsAttached"_s, &WebPreferences::inspectorStartsAttached },
        { "MockCaptureDevicesPromptEnabled"_s, &WebPreferences::mockCaptureDevicesPromptEnabled },
        { "MockScrollbarsControllerEnabled"_s, &WebPreferences::mockScrollbarsControllerEnabled },
        { "MockScrollbarsEnabled"_s, &WebPreferences::mockScrollbarsEnabled },
        { "InlineMediaPlaybackRequiresPlaysInlineAttribute"_s, &WebPreferences::inlineMediaPlaybackRequiresPlaysInlineAttribute },
#if HAVE(INCREMENTAL_PDF_APIS)
        { "IncrementalPDFLoadingEnabled"_s, &WebPreferences::incrementalPDFLoadingEnabled },
#endif
        { "IncompleteImageBorderEnabled"_s, &WebPreferences::incompleteImageBorderEnabled },
        { "NeedsAdobeFrameReloadingQuirk"_s, &WebPreferences::needsAdobeFrameReloadingQuirk },
        { "NeedsFrameNameFallbackToIdQuirk"_s, &WebPreferences::needsFrameNameFallbackToIdQuirk },
        { "NeedsKeyboardEventDisambiguationQuirks"_s, &WebPreferences::needsKeyboardEventDisambiguationQuirks },
#if PLATFORM(COCOA)
        { "PDFPluginEnabled"_s, &WebPreferences::pdfPluginEnabled },
#endif
#if PLATFORM(COCOA)
        { "PDFPluginHUDEnabled"_s, &WebPreferences::pdfPluginHUDEnabled },
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
        { "PDFPluginPageNumberIndicatorEnabled"_s, &WebPreferences::pdfPluginPageNumberIndicatorEnabled },
#endif
        { "PassiveTouchListenersAsDefaultOnDocument"_s, &WebPreferences::passiveTouchListenersAsDefaultOnDocument },
        { "PasswordEchoEnabled"_s, &WebPreferences::passwordEchoEnabled },
#if ENABLE(PICTURE_IN_PICTURE_API)
        { "PictureInPictureAPIEnabled"_s, &WebPreferences::pictureInPictureAPIEnabled },
#endif
        { "PunchOutWhiteBackgroundsInDarkMode"_s, &WebPreferences::punchOutWhiteBackgroundsInDarkMode },
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
        { "RequiresPageVisibilityForVideoToBeNowPlaying"_s, &WebPreferences::requiresPageVisibilityForVideoToBeNowPlaying },
#endif
        { "RequiresPageVisibilityToPlayAudio"_s, &WebPreferences::requiresPageVisibilityToPlayAudio },
        { "HiddenPageCSSAnimationSuspensionEnabled"_s, &WebPreferences::hiddenPageCSSAnimationSuspensionEnabled },
        { "RequiresUserGestureForAudioPlayback"_s, &WebPreferences::requiresUserGestureForAudioPlayback },
        { "RequiresUserGestureForMediaPlayback"_s, &WebPreferences::requiresUserGestureForMediaPlayback },
        { "RequiresUserGestureForVideoPlayback"_s, &WebPreferences::requiresUserGestureForVideoPlayback },
        { "RequiresUserGestureToLoadVideo"_s, &WebPreferences::requiresUserGestureToLoadVideo },
        { "UsesSingleWebProcess"_s, &WebPreferences::usesSingleWebProcess },
#if HAVE(RUBBER_BANDING)
        { "RubberBandingForSubScrollableRegionsEnabled"_s, &WebPreferences::rubberBandingForSubScrollableRegionsEnabled },
#endif
        { "UsesEncodingDetector"_s, &WebPreferences::usesEncodingDetector },
        { "SelectTrailingWhitespaceEnabled"_s, &WebPreferences::selectTrailingWhitespaceEnabled },
        { "UsesBackForwardCache"_s, &WebPreferences::usesBackForwardCache },
        { "CaretBrowsingEnabled"_s, &WebPreferences::caretBrowsingEnabled },
        { "UseSystemAppearance"_s, &WebPreferences::useSystemAppearance },
#if ENABLE(SERVICE_CONTROLS)
        { "ServiceControlsEnabled"_s, &WebPreferences::serviceControlsEnabled },
#endif
#if USE(GSTREAMER)
        { "GStreamerEnabled"_s, &WebPreferences::isGStreamerEnabled },
#endif
        { "ServiceWorkerEntitlementDisabledForTesting"_s, &WebPreferences::serviceWorkerEntitlementDisabledForTesting },
        { "ShouldAllowUserInstalledFonts"_s, &WebPreferences::shouldAllowUserInstalledFonts },
        { "ColorFilterEnabled"_s, &WebPreferences::colorFilterEnabled },
        { "UsePreHTML5ParserQuirks"_s, &WebPreferences::usePreHTML5ParserQuirks },
        { "ShouldConvertInvalidURLsToBlank"_s, &WebPreferences::shouldConvertInvalidURLsToBlank },
        { "ShouldConvertPositionStyleOnCopy"_s, &WebPreferences::shouldConvertPositionStyleOnCopy },
        { "ShouldDecidePolicyBeforeLoadingQuickLookPreview"_s, &WebPreferences::shouldDecidePolicyBeforeLoadingQuickLookPreview },
#if ENABLE(VIDEO)
        { "ShouldDisplayCaptions"_s, &WebPreferences::shouldDisplayCaptions },
#endif
#if ENABLE(CONTENT_CHANGE_OBSERVER)
        { "ContentChangeObserverEnabled"_s, &WebPreferences::contentChangeObserverEnabled },
#endif
        { "ContentDispositionAttachmentSandboxEnabled"_s, &WebPreferences::contentDispositionAttachmentSandboxEnabled },
        { "ForceWebGLUsesLowPower"_s, &WebPreferences::forceWebGLUsesLowPower },
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
        { "ContextMenuQRCodeDetectionEnabled"_s, &WebPreferences::contextMenuQRCodeDetectionEnabled },
#endif
#if ENABLE(VIDEO)
        { "ShouldDisplaySubtitles"_s, &WebPreferences::shouldDisplaySubtitles },
#endif
        { "ForceFTPDirectoryListings"_s, &WebPreferences::forceFTPDirectoryListings },
        { "ForceCompositingMode"_s, &WebPreferences::forceCompositingMode },
#if ENABLE(VIDEO)
        { "ShouldDisplayTextDescriptions"_s, &WebPreferences::shouldDisplayTextDescriptions },
#endif
#if ENABLE(TEXT_AUTOSIZING)
        { "ShouldEnableTextAutosizingBoost"_s, &WebPreferences::shouldEnableTextAutosizingBoost },
#endif
        { "UseImageDocumentForSubframePDF"_s, &WebPreferences::useImageDocumentForSubframePDF },
        { "ShouldIgnoreMetaViewport"_s, &WebPreferences::shouldIgnoreMetaViewport },
        { "ShouldPrintBackgrounds"_s, &WebPreferences::shouldPrintBackgrounds },
        { "ShouldRespectImageOrientation"_s, &WebPreferences::shouldRespectImageOrientation },
        { "ShouldRestrictBaseURLSchemes"_s, &WebPreferences::shouldRestrictBaseURLSchemes },
        { "ShouldSuppressTextInputFromEditingDuringProvisionalNavigation"_s, &WebPreferences::shouldSuppressTextInputFromEditingDuringProvisionalNavigation },
        { "DOMPasteAllowed"_s, &WebPreferences::domPasteAllowed },
        { "ShouldUseServiceWorkerShortTimeout"_s, &WebPreferences::shouldUseServiceWorkerShortTimeout },
#if HAVE(APP_SSO)
        { "ExtensibleSSOEnabled"_s, &WebPreferences::isExtensibleSSOEnabled },
#endif
        { "TreatsAnyTextCSSLinkAsStylesheet"_s, &WebPreferences::treatsAnyTextCSSLinkAsStylesheet },
        { "LinkPreloadEnabled"_s, &WebPreferences::linkPreloadEnabled },
        { "ShowsToolTipOverTruncatedText"_s, &WebPreferences::showsToolTipOverTruncatedText },
        { "ThreadedScrollingEnabled"_s, &WebPreferences::threadedScrollingEnabled },
        { "TextInteractionEnabled"_s, &WebPreferences::textInteractionEnabled },
        { "TextExtractionEnabled"_s, &WebPreferences::textExtractionEnabled },
#if ENABLE(TEXT_AUTOSIZING)
        { "TextAutosizingEnabled"_s, &WebPreferences::textAutosizingEnabled },
#endif
        { "DeveloperExtrasEnabled"_s, &WebPreferences::developerExtrasEnabled },
#if ENABLE(DEVICE_ORIENTATION)
        { "DeviceOrientationEventEnabled"_s, &WebPreferences::deviceOrientationEventEnabled },
#endif
#if ENABLE(DEVICE_ORIENTATION)
        { "DeviceOrientationPermissionAPIEnabled"_s, &WebPreferences::deviceOrientationPermissionAPIEnabled },
#endif
        { "ShowsURLsInToolTipsEnabled"_s, &WebPreferences::showsURLsInToolTipsEnabled },
        { "TextAreasAreResizable"_s, &WebPreferences::textAreasAreResizable },
        { "TemporaryTileCohortRetentionEnabled"_s, &WebPreferences::temporaryTileCohortRetentionEnabled },
        { "TelephoneNumberParsingEnabled"_s, &WebPreferences::telephoneNumberParsingEnabled },
        { "ShrinksStandaloneImagesToFit"_s, &WebPreferences::shrinksStandaloneImagesToFit },
        { "DisabledAdaptationsMetaTagEnabled"_s, &WebPreferences::disabledAdaptationsMetaTagEnabled },
        { "DownloadAttributeEnabled"_s, &WebPreferences::downloadAttributeEnabled },
        { "TabsToLinks"_s, &WebPreferences::tabsToLinks },
#if USE(SYSTEM_PREVIEW)
        { "SystemPreviewEnabled"_s, &WebPreferences::systemPreviewEnabled },
#endif
        { "SuppressesIncrementalRendering"_s, &WebPreferences::suppressesIncrementalRendering },
        { "EnableInheritURIQueryComponent"_s, &WebPreferences::enableInheritURIQueryComponent },
#if ENABLE(ENCRYPTED_MEDIA)
        { "EncryptedMediaAPIEnabled"_s, &WebPreferences::encryptedMediaAPIEnabled },
#endif
        { "Standalone"_s, &WebPreferences::standalone },
        { "SmartInsertDeleteEnabled"_s, &WebPreferences::smartInsertDeleteEnabled },
        { "SpatialNavigationEnabled"_s, &WebPreferences::spatialNavigationEnabled },
#if ENABLE(MEDIA_SOURCE)
        { "SourceBufferChangeTypeEnabled"_s, &WebPreferences::sourceBufferChangeTypeEnabled },
#endif
        { "TargetTextPseudoElementEnabled"_s, &WebPreferences::targetTextPseudoElementEnabled },
        { "ThumbAndTrackPseudoElementsEnabled"_s, &WebPreferences::thumbAndTrackPseudoElementsEnabled },
        { "LinkDNSPrefetchEnabled"_s, &WebPreferences::linkDNSPrefetchEnabled },
        { "SelectShowPickerEnabled"_s, &WebPreferences::selectShowPickerEnabled },
        { "PageAtRuleMarginDescriptorsEnabled"_s, &WebPreferences::pageAtRuleMarginDescriptorsEnabled },
#if USE(AVFOUNDATION)
        { "AVFoundationEnabled"_s, &WebPreferences::isAVFoundationEnabled },
#endif
#if HAVE(AVKIT_CONTENT_SOURCE)
        { "AVKitContentSourceEnabled"_s, &WebPreferences::isAVKitContentSourceEnabled },
#endif
#if USE(CORE_IMAGE)
        { "AcceleratedFiltersEnabled"_s, &WebPreferences::acceleratedFiltersEnabled },
#endif
        { "AccessHandleEnabled"_s, &WebPreferences::accessHandleEnabled },
        { "DOMTestingAPIsEnabled"_s, &WebPreferences::domTestingAPIsEnabled },
        { "AllowMediaContentTypesRequiringHardwareSupportAsFallback"_s, &WebPreferences::allowMediaContentTypesRequiringHardwareSupportAsFallback },
        { "AllowPrivacySensitiveOperationsInNonPersistentDataStores"_s, &WebPreferences::allowPrivacySensitiveOperationsInNonPersistentDataStores },
#if PLATFORM(IOS_FAMILY)
        { "AllowViewportShrinkToFitContent"_s, &WebPreferences::allowViewportShrinkToFitContent },
#endif
#if ENABLE(WEBGL)
        { "AllowWebGLInWorkers"_s, &WebPreferences::allowWebGLInWorkers },
#endif
#if ENABLE(MEDIA_STREAM)
        { "PerElementSpeakerSelectionEnabled"_s, &WebPreferences::perElementSpeakerSelectionEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ExposeSpeakersWithoutMicrophoneEnabled"_s, &WebPreferences::exposeSpeakersWithoutMicrophoneEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ExposeSpeakersEnabled"_s, &WebPreferences::exposeSpeakersEnabled },
#endif
        { "AllowTopNavigationToDataURLs"_s, &WebPreferences::allowTopNavigationToDataURLs },
        { "AllowUniversalAccessFromFileURLs"_s, &WebPreferences::allowUniversalAccessFromFileURLs },
#if ENABLE(WEB_ARCHIVE)
        { "AlwaysAllowLocalWebarchive"_s, &WebPreferences::alwaysAllowLocalWebarchive },
#endif
#if ENABLE(VP9)
        { "SWVPDecodersAlwaysEnabled"_s, &WebPreferences::sWVPDecodersAlwaysEnabled },
#endif
        { "AppBadgeEnabled"_s, &WebPreferences::appBadgeEnabled },
#if ENABLE(APP_HIGHLIGHTS)
        { "AppHighlightsEnabled"_s, &WebPreferences::appHighlightsEnabled },
#endif
        { "AsyncFrameScrollingEnabled"_s, &WebPreferences::asyncFrameScrollingEnabled },
        { "AsyncOverflowScrollingEnabled"_s, &WebPreferences::asyncOverflowScrollingEnabled },
#if PLATFORM(IOS_FAMILY)
        { "UseAsyncUIKitInteractions"_s, &WebPreferences::useAsyncUIKitInteractions },
#endif
        { "AsyncClipboardAPIEnabled"_s, &WebPreferences::asyncClipboardAPIEnabled },
#if ENABLE(ATTACHMENT_ELEMENT)
        { "AttachmentElementEnabled"_s, &WebPreferences::attachmentElementEnabled },
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
        { "AttachmentWideLayoutEnabled"_s, &WebPreferences::attachmentWideLayoutEnabled },
#endif
#if ENABLE(VIDEO)
        { "ExtendedAudioDescriptionsEnabled"_s, &WebPreferences::extendedAudioDescriptionsEnabled },
#endif
#if ENABLE(VIDEO)
        { "AudioDescriptionsEnabled"_s, &WebPreferences::audioDescriptionsEnabled },
#endif
#if ENABLE(DOM_AUDIO_SESSION)
        { "DOMAudioSessionEnabled"_s, &WebPreferences::domAudioSessionEnabled },
#endif
#if ENABLE(DOM_AUDIO_SESSION)
        { "DOMAudioSessionFullEnabled"_s, &WebPreferences::domAudioSessionFullEnabled },
#endif
        { "AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth"_s, &WebPreferences::automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth },
        { "BeaconAPIEnabled"_s, &WebPreferences::beaconAPIEnabled },
        { "BidiContentAwarePasteEnabled"_s, &WebPreferences::bidiContentAwarePasteEnabled },
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        { "BlockFontServiceInWebContentSandbox"_s, &WebPreferences::blockFontServiceInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        { "BlockIconServicesInWebContentSandbox"_s, &WebPreferences::blockIconServicesInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        { "BlockMobileAssetInWebContentSandbox"_s, &WebPreferences::blockMobileAssetInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(IOS)
        { "BlockMobileGestaltInWebContentSandbox"_s, &WebPreferences::blockMobileGestaltInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        { "BlockOpenDirectoryInWebContentSandbox"_s, &WebPreferences::blockOpenDirectoryInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        { "BlockWebInspectorInWebContentSandbox"_s, &WebPreferences::blockWebInspectorInWebContentSandbox },
#endif
        { "BroadcastChannelEnabled"_s, &WebPreferences::broadcastChannelEnabled },
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
        { "BuiltInNotificationsEnabled"_s, &WebPreferences::builtInNotificationsEnabled },
#endif
        { "CSS3DTransformBackfaceVisibilityInteroperabilityEnabled"_s, &WebPreferences::css3DTransformBackfaceVisibilityInteroperabilityEnabled },
        { "CSSCounterStyleAtRuleImageSymbolsEnabled"_s, &WebPreferences::cssCounterStyleAtRuleImageSymbolsEnabled },
        { "AccentColorEnabled"_s, &WebPreferences::accentColorEnabled },
        { "CSSAnchorPositioningEnabled"_s, &WebPreferences::cssAnchorPositioningEnabled },
        { "CSSAnchorPositioningPositionVisibilityEnabled"_s, &WebPreferences::cssAnchorPositioningPositionVisibilityEnabled },
        { "DevolvableWidgetsEnabled"_s, &WebPreferences::devolvableWidgetsEnabled },
        { "CSSInputSecurityEnabled"_s, &WebPreferences::cssInputSecurityEnabled },
        { "MasonryEnabled"_s, &WebPreferences::masonryEnabled },
        { "OverscrollBehaviorEnabled"_s, &WebPreferences::overscrollBehaviorEnabled },
        { "CSSPaintingAPIEnabled"_s, &WebPreferences::cssPaintingAPIEnabled },
        { "CSSRhythmicSizingEnabled"_s, &WebPreferences::cssRhythmicSizingEnabled },
        { "CSSScrollAnchoringEnabled"_s, &WebPreferences::cssScrollAnchoringEnabled },
        { "SpringTimingFunctionEnabled"_s, &WebPreferences::springTimingFunctionEnabled },
        { "CSSTreeCountingFunctionsEnabled"_s, &WebPreferences::cssTreeCountingFunctionsEnabled },
        { "CSSTypedOMColorEnabled"_s, &WebPreferences::cssTypedOMColorEnabled },
        { "CSSURLModifiersEnabled"_s, &WebPreferences::cssURLModifiersEnabled },
        { "CSSURLIntegrityModifierEnabled"_s, &WebPreferences::cssURLIntegrityModifierEnabled },
        { "CSSUnprefixedBackdropFilterEnabled"_s, &WebPreferences::cssUnprefixedBackdropFilterEnabled },
        { "CSSAppearanceBaseEnabled"_s, &WebPreferences::cssAppearanceBaseEnabled },
        { "CSSAxisRelativePositionKeywordsEnabled"_s, &WebPreferences::cssAxisRelativePositionKeywordsEnabled },
        { "CSSBackgroundClipBorderAreaEnabled"_s, &WebPreferences::cssBackgroundClipBorderAreaEnabled },
        { "CSSColorLayersEnabled"_s, &WebPreferences::cssColorLayersEnabled },
        { "CSSContrastColorEnabled"_s, &WebPreferences::cssContrastColorEnabled },
        { "CSSCornerShapeEnabled"_s, &WebPreferences::cssCornerShapeEnabled },
        { "CSSDPropertyEnabled"_s, &WebPreferences::cssDPropertyEnabled },
        { "CSSDynamicRangeLimitMixEnabled"_s, &WebPreferences::cssDynamicRangeLimitMixEnabled },
        { "CSSConstrainedDynamicRangeLimitEnabled"_s, &WebPreferences::cssConstrainedDynamicRangeLimitEnabled },
        { "CSSFieldSizingEnabled"_s, &WebPreferences::cssFieldSizingEnabled },
        { "CSSFontVariantEmojiEnabled"_s, &WebPreferences::cssFontVariantEmojiEnabled },
        { "CSSLineClampEnabled"_s, &WebPreferences::cssLineClampEnabled },
        { "CSSLineFitEdgeEnabled"_s, &WebPreferences::cssLineFitEdgeEnabled },
        { "CSSProgressFunctionEnabled"_s, &WebPreferences::cssProgressFunctionEnabled },
        { "CSSRandomFunctionEnabled"_s, &WebPreferences::cssRandomFunctionEnabled },
        { "CSSRubyAlignEnabled"_s, &WebPreferences::cssRubyAlignEnabled },
        { "CSSRubyOverhangEnabled"_s, &WebPreferences::cssRubyOverhangEnabled },
        { "CSSScrollbarColorEnabled"_s, &WebPreferences::cssScrollbarColorEnabled },
        { "CSSScrollbarGutterEnabled"_s, &WebPreferences::cssScrollbarGutterEnabled },
        { "CSSScrollbarWidthEnabled"_s, &WebPreferences::cssScrollbarWidthEnabled },
        { "CSSShapeFunctionEnabled"_s, &WebPreferences::cssShapeFunctionEnabled },
        { "CSSTextAutospaceEnabled"_s, &WebPreferences::cssTextAutospaceEnabled },
        { "CSSTextBoxTrimEnabled"_s, &WebPreferences::cssTextBoxTrimEnabled },
        { "CSSTextGroupAlignEnabled"_s, &WebPreferences::cssTextGroupAlignEnabled },
        { "CSSTextJustifyEnabled"_s, &WebPreferences::cssTextJustifyEnabled },
        { "CSSTextSpacingTrimEnabled"_s, &WebPreferences::cssTextSpacingTrimEnabled },
        { "CSSTextUnderlinePositionLeftRightEnabled"_s, &WebPreferences::cssTextUnderlinePositionLeftRightEnabled },
        { "CSSTextWrapPrettyEnabled"_s, &WebPreferences::cssTextWrapPrettyEnabled },
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
        { "CSSTransformStyleSeparatedEnabled"_s, &WebPreferences::cssTransformStyleSeparatedEnabled },
#endif
        { "CacheAPIEnabled"_s, &WebPreferences::cacheAPIEnabled },
        { "CanvasColorSpaceEnabled"_s, &WebPreferences::canvasColorSpaceEnabled },
        { "CanvasFiltersEnabled"_s, &WebPreferences::canvasFiltersEnabled },
        { "CanvasLayersEnabled"_s, &WebPreferences::canvasLayersEnabled },
#if USE(CA) || USE(SKIA)
        { "CanvasUsesAcceleratedDrawing"_s, &WebPreferences::canvasUsesAcceleratedDrawing },
#endif
        { "CanvasPixelFormatEnabled"_s, &WebPreferences::canvasPixelFormatEnabled },
        { "ChildProcessDebuggabilityEnabled"_s, &WebPreferences::childProcessDebuggabilityEnabled },
        { "ClearSiteDataHTTPHeaderEnabled"_s, &WebPreferences::clearSiteDataHTTPHeaderEnabled },
        { "ClearSiteDataExecutionContextsSupportEnabled"_s, &WebPreferences::clearSiteDataExecutionContextsSupportEnabled },
        { "CloseWatcherEnabled"_s, &WebPreferences::closeWatcherEnabled },
        { "InputTypeColorEnabled"_s, &WebPreferences::inputTypeColorEnabled },
        { "CompositingBordersVisible"_s, &WebPreferences::compositingBordersVisible },
        { "CompositingRepaintCountersVisible"_s, &WebPreferences::compositingRepaintCountersVisible },
        { "CompressionStreamEnabled"_s, &WebPreferences::compressionStreamEnabled },
        { "ContactPickerAPIEnabled"_s, &WebPreferences::contactPickerAPIEnabled },
        { "ContentInsetBackgroundFillEnabled"_s, &WebPreferences::contentInsetBackgroundFillEnabled },
        { "CookieConsentAPIEnabled"_s, &WebPreferences::cookieConsentAPIEnabled },
        { "CookieStoreManagerEnabled"_s, &WebPreferences::cookieStoreManagerEnabled },
        { "CookieStoreAPIExtendedAttributesEnabled"_s, &WebPreferences::cookieStoreAPIExtendedAttributesEnabled },
        { "CookieStoreAPIEnabled"_s, &WebPreferences::cookieStoreAPIEnabled },
        { "CookieEnabled"_s, &WebPreferences::cookieEnabled },
#if PLATFORM(MAC)
        { "InputMethodUsesCorrectKeyEventOrder"_s, &WebPreferences::inputMethodUsesCorrectKeyEventOrder },
#endif
        { "CrossDocumentViewTransitionsEnabled"_s, &WebPreferences::crossDocumentViewTransitionsEnabled },
        { "CrossOriginEmbedderPolicyEnabled"_s, &WebPreferences::crossOriginEmbedderPolicyEnabled },
        { "CrossOriginOpenerPolicyEnabled"_s, &WebPreferences::crossOriginOpenerPolicyEnabled },
        { "CustomPasteboardDataEnabled"_s, &WebPreferences::customPasteboardDataEnabled },
        { "DOMPasteAccessRequestsEnabled"_s, &WebPreferences::domPasteAccessRequestsEnabled },
        { "MutationEventsEnabled"_s, &WebPreferences::mutationEventsEnabled },
        { "DOMTimersThrottlingEnabled"_s, &WebPreferences::domTimersThrottlingEnabled },
#if PLATFORM(IOS_FAMILY)
        { "ZoomOnDoubleTapWhenRoot"_s, &WebPreferences::zoomOnDoubleTapWhenRoot },
#endif
#if PLATFORM(IOS_FAMILY)
        { "AlwaysZoomOnDoubleTap"_s, &WebPreferences::alwaysZoomOnDoubleTap },
#endif
        { "DataTransferItemsEnabled"_s, &WebPreferences::dataTransferItemsEnabled },
        { "DataListElementEnabled"_s, &WebPreferences::dataListElementEnabled },
        { "InputTypeDateEnabled"_s, &WebPreferences::inputTypeDateEnabled },
        { "DateTimeInputsEditableComponentsEnabled"_s, &WebPreferences::dateTimeInputsEditableComponentsEnabled },
#if ENABLE(DECLARATIVE_WEB_PUSH)
        { "DeclarativeWebPush"_s, &WebPreferences::declarativeWebPush },
#endif
        { "ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint"_s, &WebPreferences::shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint },
        { "DeprecationReportingEnabled"_s, &WebPreferences::deprecationReportingEnabled },
#if ENABLE(MEDIA_SOURCE)
        { "DetachableMediaSourceEnabled"_s, &WebPreferences::detachableMediaSourceEnabled },
#endif
        { "UAVisualTransitionDetectionEnabled"_s, &WebPreferences::uAVisualTransitionDetectionEnabled },
        { "DiagnosticLoggingEnabled"_s, &WebPreferences::diagnosticLoggingEnabled },
#if ENABLE(WEB_AUTHN)
        { "DigitalCredentialsEnabled"_s, &WebPreferences::digitalCredentialsEnabled },
#endif
        { "DirectoryUploadEnabled"_s, &WebPreferences::directoryUploadEnabled },
        { "IsThirdPartyCookieBlockingDisabled"_s, &WebPreferences::isThirdPartyCookieBlockingDisabled },
        { "IsFirstPartyWebsiteDataRemovalDisabled"_s, &WebPreferences::isFirstPartyWebsiteDataRemovalDisabled },
#if PLATFORM(IOS_FAMILY)
        { "DisableScreenSizeOverride"_s, &WebPreferences::disableScreenSizeOverride },
#endif
        { "ShouldDropNearSuspendedAssertionAfterDelay"_s, &WebPreferences::shouldDropNearSuspendedAssertionAfterDelay },
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        { "UseCGDisplayListsForDOMRendering"_s, &WebPreferences::useCGDisplayListsForDOMRendering },
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        { "ReplayCGDisplayListsIntoBackingStore"_s, &WebPreferences::replayCGDisplayListsIntoBackingStore },
#endif
        { "DynamicSiteInterventionsEnabled"_s, &WebPreferences::dynamicSiteInterventionsEnabled },
        { "EmbedElementEnabled"_s, &WebPreferences::embedElementEnabled },
#if PLATFORM(MAC)
        { "EnableAccessibilityOnDemand"_s, &WebPreferences::enableAccessibilityOnDemand },
#endif
#if PLATFORM(IOS_FAMILY)
        { "AutomaticLiveResizeEnabled"_s, &WebPreferences::automaticLiveResizeEnabled },
#endif
        { "CanvasFingerprintingQuirkEnabled"_s, &WebPreferences::canvasFingerprintingQuirkEnabled },
        { "EnableElementCurrentCSSZoom"_s, &WebPreferences::enableElementCurrentCSSZoom },
        { "EnumeratingAllNetworkInterfacesEnabled"_s, &WebPreferences::enumeratingAllNetworkInterfacesEnabled },
        { "EnumeratingVisibleNetworkInterfacesEnabled"_s, &WebPreferences::enumeratingVisibleNetworkInterfacesEnabled },
        { "ICECandidateFilteringEnabled"_s, &WebPreferences::iceCandidateFilteringEnabled },
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
        { "LegacyEncryptedMediaAPIEnabled"_s, &WebPreferences::legacyEncryptedMediaAPIEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "MockCaptureDevicesEnabled"_s, &WebPreferences::mockCaptureDevicesEnabled },
#endif
#if ENABLE(MODEL_PROCESS)
        { "ModelProcessEnabled"_s, &WebPreferences::modelProcessEnabled },
#endif
#if ENABLE(PDFJS)
        { "PDFJSViewerEnabled"_s, &WebPreferences::pdfJSViewerEnabled },
#endif
        { "AuxclickEventEnabled"_s, &WebPreferences::auxclickEventEnabled },
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
        { "BackgroundWebContentRunningBoardThrottlingEnabled"_s, &WebPreferences::backgroundWebContentRunningBoardThrottlingEnabled },
#endif
        { "BackgroundFetchAPIEnabled"_s, &WebPreferences::backgroundFetchAPIEnabled },
#if HAVE(SANDBOX_STATE_FLAGS)
        { "EnableDebuggingFeaturesInSandbox"_s, &WebPreferences::enableDebuggingFeaturesInSandbox },
#endif
#if HAVE(NETWORK_LOADER)
        { "CFNetworkNetworkLoaderEnabled"_s, &WebPreferences::cFNetworkNetworkLoaderEnabled },
#endif
#if HAVE(MACH_BOOTSTRAP_EXTENSION) || HAVE(SANDBOX_STATE_FLAGS)
        { "ExperimentalSandboxEnabled"_s, &WebPreferences::experimentalSandboxEnabled },
#endif
        { "NavigatorUserAgentDataJavaScriptAPIEnabled"_s, &WebPreferences::navigatorUserAgentDataJavaScriptAPIEnabled },
        { "BlobFileAccessEnforcementEnabled"_s, &WebPreferences::blobFileAccessEnforcementEnabled },
        { "EnterKeyHintEnabled"_s, &WebPreferences::enterKeyHintEnabled },
        { "EventTimingEnabled"_s, &WebPreferences::eventTimingEnabled },
        { "EventHandlerDrivenSmoothKeyboardScrollingEnabled"_s, &WebPreferences::eventHandlerDrivenSmoothKeyboardScrollingEnabled },
#if ENABLE(MEDIA_SESSION_COORDINATOR)
        { "MediaSessionCoordinatorEnabled"_s, &WebPreferences::mediaSessionCoordinatorEnabled },
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
        { "MediaSessionPlaylistEnabled"_s, &WebPreferences::mediaSessionPlaylistEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ExposeCaptureDevicesAfterCaptureEnabled"_s, &WebPreferences::exposeCaptureDevicesAfterCaptureEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ExposeDefaultSpeakerAsSpecificDeviceEnabled"_s, &WebPreferences::exposeDefaultSpeakerAsSpecificDeviceEnabled },
#endif
        { "FTPEnabled"_s, &WebPreferences::ftpEnabled },
#if PLATFORM(IOS_FAMILY)
        { "PreferFasterClickOverDoubleTap"_s, &WebPreferences::preferFasterClickOverDoubleTap },
#endif
#if PLATFORM(IOS_FAMILY)
        { "FasterClicksEnabled"_s, &WebPreferences::fasterClicksEnabled },
#endif
        { "FileSystemEnabled"_s, &WebPreferences::fileSystemEnabled },
        { "FileSystemWritableStreamEnabled"_s, &WebPreferences::fileSystemWritableStreamEnabled },
        { "FileReaderAPIEnabled"_s, &WebPreferences::fileReaderAPIEnabled },
        { "FilterLinkDecorationByDefaultEnabled"_s, &WebPreferences::filterLinkDecorationByDefaultEnabled },
        { "ForceLockdownFontParserEnabled"_s, &WebPreferences::forceLockdownFontParserEnabled },
#if PLATFORM(IOS_FAMILY)
        { "ForceAlwaysUserScalable"_s, &WebPreferences::forceAlwaysUserScalable },
#endif
#if ENABLE(FORM_CONTROL_REFRESH)
        { "FormControlRefreshEnabled"_s, &WebPreferences::formControlRefreshEnabled },
#endif
#if ENABLE(CONTENT_EXTENSIONS)
        { "IFrameResourceMonitoringTestingSettingsEnabled"_s, &WebPreferences::iFrameResourceMonitoringTestingSettingsEnabled },
#endif
#if ENABLE(CONTENT_EXTENSIONS)
        { "IFrameResourceMonitoringEnabled"_s, &WebPreferences::iFrameResourceMonitoringEnabled },
#endif
#if ENABLE(FULLSCREEN_API)
        { "FullScreenKeyboardLock"_s, &WebPreferences::fullScreenKeyboardLock },
#endif
#if ENABLE(FULLSCREEN_API)
        { "FullScreenEnabled"_s, &WebPreferences::fullScreenEnabled },
#endif
#if PLATFORM(VISION)
        { "FullscreenSceneAspectRatioLockingEnabled"_s, &WebPreferences::fullscreenSceneAspectRatioLockingEnabled },
#endif
#if PLATFORM(VISION)
        { "FullscreenSceneDimmingEnabled"_s, &WebPreferences::fullscreenSceneDimmingEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "CaptureAudioInGPUProcessEnabled"_s, &WebPreferences::captureAudioInGPUProcessEnabled },
#endif
#if ENABLE(GPU_PROCESS)
        { "BlockMediaLayerRehostingInWebContentProcess"_s, &WebPreferences::blockMediaLayerRehostingInWebContentProcess },
#endif
#if ENABLE(GPU_PROCESS) && !(PLATFORM(GTK) || PLATFORM(WPE))
        { "UseGPUProcessForCanvasRenderingEnabled"_s, &WebPreferences::useGPUProcessForCanvasRenderingEnabled },
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
        { "ManageCaptureStatusBarInGPUProcessEnabled"_s, &WebPreferences::manageCaptureStatusBarInGPUProcessEnabled },
#endif
#if ENABLE(GPU_PROCESS)
        { "UseGPUProcessForDOMRenderingEnabled"_s, &WebPreferences::useGPUProcessForDOMRenderingEnabled },
#endif
#if ENABLE(GPU_PROCESS)
        { "UseGPUProcessForMediaEnabled"_s, &WebPreferences::useGPUProcessForMediaEnabled },
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
        { "UseGPUProcessForDisplayCapture"_s, &WebPreferences::useGPUProcessForDisplayCapture },
#endif
#if ENABLE(MEDIA_STREAM)
        { "CaptureVideoInGPUProcessEnabled"_s, &WebPreferences::captureVideoInGPUProcessEnabled },
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
        { "UseGPUProcessForWebGLEnabled"_s, &WebPreferences::useGPUProcessForWebGLEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCPlatformCodecsInGPUProcessEnabled"_s, &WebPreferences::webRTCPlatformCodecsInGPUProcessEnabled },
#endif
#if ENABLE(GAMEPAD)
        { "GamepadTriggerRumbleEnabled"_s, &WebPreferences::gamepadTriggerRumbleEnabled },
#endif
#if ENABLE(GAMEPAD)
        { "GamepadVibrationActuatorEnabled"_s, &WebPreferences::gamepadVibrationActuatorEnabled },
#endif
#if ENABLE(GAMEPAD)
        { "GamepadsEnabled"_s, &WebPreferences::gamepadsEnabled },
#endif
#if ENABLE(VIDEO)
        { "GenericCueAPIEnabled"_s, &WebPreferences::genericCueAPIEnabled },
#endif
        { "GeolocationAPIEnabled"_s, &WebPreferences::geolocationAPIEnabled },
#if USE(GRAPHICS_CONTEXT_FILTERS)
        { "GraphicsContextFiltersEnabled"_s, &WebPreferences::graphicsContextFiltersEnabled },
#endif
        { "AcceleratedDrawingEnabled"_s, &WebPreferences::acceleratedDrawingEnabled },
#if ENABLE(MODEL_ELEMENT)
        { "ModelElementEnabled"_s, &WebPreferences::modelElementEnabled },
#endif
#if ENABLE(MODEL_ELEMENT)
        { "ModelDocumentEnabled"_s, &WebPreferences::modelDocumentEnabled },
#endif
        { "InteractiveFormValidationEnabled"_s, &WebPreferences::interactiveFormValidationEnabled },
#if ENABLE(VIDEO)
        { "MediaEnabled"_s, &WebPreferences::mediaEnabled },
#endif
        { "InputTypeColorEnhancementsEnabled"_s, &WebPreferences::inputTypeColorEnhancementsEnabled },
        { "DetailsAutoExpandEnabled"_s, &WebPreferences::detailsAutoExpandEnabled },
        { "CommandAttributesEnabled"_s, &WebPreferences::commandAttributesEnabled },
        { "HTMLLegacyAttributeValueSerializationEnabled"_s, &WebPreferences::hTMLLegacyAttributeValueSerializationEnabled },
        { "PopoverAttributeEnabled"_s, &WebPreferences::popoverAttributeEnabled },
        { "SwitchControlEnabled"_s, &WebPreferences::switchControlEnabled },
        { "HTTPSByDefaultEnabled"_s, &WebPreferences::httpSByDefaultEnabled },
        { "HiddenPageDOMTimerThrottlingAutoIncreases"_s, &WebPreferences::hiddenPageDOMTimerThrottlingAutoIncreases },
        { "HiddenPageDOMTimerThrottlingEnabled"_s, &WebPreferences::hiddenPageDOMTimerThrottlingEnabled },
#if HAVE(MATERIAL_HOSTING)
        { "HostedBlurMaterialInMediaControlsEnabled"_s, &WebPreferences::hostedBlurMaterialInMediaControlsEnabled },
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        { "BlockIOKitInWebContentSandbox"_s, &WebPreferences::blockIOKitInWebContentSandbox },
#endif
        { "IOSurfaceLosslessCompressionEnabled"_s, &WebPreferences::iOSurfaceLosslessCompressionEnabled },
#if ENABLE(IPC_TESTING_API)
        { "IPCTestingAPIEnabled"_s, &WebPreferences::ipcTestingAPIEnabled },
#endif
        { "ItpDebugModeEnabled"_s, &WebPreferences::itpDebugModeEnabled },
#if ENABLE(TEXT_AUTOSIZING)
        { "TextAutosizingUsesIdempotentMode"_s, &WebPreferences::textAutosizingUsesIdempotentMode },
#endif
#if ENABLE(IPC_TESTING_API)
        { "IgnoreInvalidMessageWhenIPCTestingAPIEnabled"_s, &WebPreferences::ignoreInvalidMessageWhenIPCTestingAPIEnabled },
#endif
        { "IgnoreIframeEmbeddingProtectionsEnabled"_s, &WebPreferences::ignoreIframeEmbeddingProtectionsEnabled },
#if ENABLE(IMAGE_ANALYSIS)
        { "ImageAnalysisDuringFindInPageEnabled"_s, &WebPreferences::imageAnalysisDuringFindInPageEnabled },
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
        { "ImageAnimationControlEnabled"_s, &WebPreferences::imageAnimationControlEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ImageCaptureEnabled"_s, &WebPreferences::imageCaptureEnabled },
#endif
#if ENABLE(SERVICE_CONTROLS)
        { "ImageControlsEnabled"_s, &WebPreferences::imageControlsEnabled },
#endif
        { "InWindowFullscreenEnabled"_s, &WebPreferences::inWindowFullscreenEnabled },
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
        { "IncludeIgnoredInCoreAXTree"_s, &WebPreferences::includeIgnoredInCoreAXTree },
#endif
        { "IndexedDBAPIEnabled"_s, &WebPreferences::indexedDBAPIEnabled },
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
        { "InteractionRegionsEnabled"_s, &WebPreferences::interactionRegionsEnabled },
#endif
#if ENABLE(ACCESSIBILITY_ISOLATED_TREE)
        { "IsAccessibilityIsolatedTreeEnabled"_s, &WebPreferences::isAccessibilityIsolatedTreeEnabled },
#endif
        { "JavaScriptEnabled"_s, &WebPreferences::javaScriptEnabled },
#if PLATFORM(IOS_FAMILY)
        { "KeyboardDismissalGestureEnabled"_s, &WebPreferences::keyboardDismissalGestureEnabled },
#endif
        { "LayerBasedSVGEngineEnabled"_s, &WebPreferences::layerBasedSVGEngineEnabled },
        { "LazyIframeLoadingEnabled"_s, &WebPreferences::lazyIframeLoadingEnabled },
        { "LazyImageLoadingEnabled"_s, &WebPreferences::lazyImageLoadingEnabled },
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
        { "LegacyOverflowScrollingTouchEnabled"_s, &WebPreferences::legacyOverflowScrollingTouchEnabled },
#endif
        { "LegacyLineLayoutVisualCoverageEnabled"_s, &WebPreferences::legacyLineLayoutVisualCoverageEnabled },
        { "ShowModalDialogEnabled"_s, &WebPreferences::showModalDialogEnabled },
#if ENABLE(MEDIA_STREAM)
        { "MediaCaptureRequiresSecureConnection"_s, &WebPreferences::mediaCaptureRequiresSecureConnection },
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
        { "LimitedMatroskaSupportEnabled"_s, &WebPreferences::limitedMatroskaSupportEnabled },
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
        { "LinearMediaPlayerEnabled"_s, &WebPreferences::linearMediaPlayerEnabled },
#endif
        { "LinkSanitizerEnabled"_s, &WebPreferences::linkSanitizerEnabled },
        { "LinkPreconnectEarlyHintsEnabled"_s, &WebPreferences::linkPreconnectEarlyHintsEnabled },
        { "LinkPrefetchEnabled"_s, &WebPreferences::linkPrefetchEnabled },
#if ENABLE(WEB_ARCHIVE)
        { "LoadWebArchiveWithEphemeralStorageEnabled"_s, &WebPreferences::loadWebArchiveWithEphemeralStorageEnabled },
#endif
        { "LocalFileContentSniffingEnabled"_s, &WebPreferences::localFileContentSniffingEnabled },
        { "LocalNetworkAccessEnabled"_s, &WebPreferences::localNetworkAccessEnabled },
        { "LocalStorageEnabled"_s, &WebPreferences::localStorageEnabled },
        { "LockdownFontParserEnabled"_s, &WebPreferences::lockdownFontParserEnabled },
        { "LogsPageMessagesToSystemConsoleEnabled"_s, &WebPreferences::logsPageMessagesToSystemConsoleEnabled },
        { "LoginStatusAPIEnabled"_s, &WebPreferences::loginStatusAPIEnabled },
        { "MainContentUserGestureOverrideEnabled"_s, &WebPreferences::mainContentUserGestureOverrideEnabled },
#if ENABLE(MEDIA_SOURCE)
        { "ManagedMediaSourceEnabled"_s, &WebPreferences::managedMediaSourceEnabled },
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
        { "ManagedMediaSourceNeedsAirPlay"_s, &WebPreferences::managedMediaSourceNeedsAirPlay },
#endif
        { "CoreMathMLEnabled"_s, &WebPreferences::coreMathMLEnabled },
        { "MediaCapabilitiesExtensionsEnabled"_s, &WebPreferences::mediaCapabilitiesExtensionsEnabled },
#if ENABLE(EXTENSION_CAPABILITIES)
        { "MediaCapabilityGrantsEnabled"_s, &WebPreferences::mediaCapabilityGrantsEnabled },
#endif
        { "MediaPlaybackEnabled"_s, &WebPreferences::mediaPlaybackEnabled },
#if ENABLE(MEDIA_SESSION)
        { "MediaSessionEnabled"_s, &WebPreferences::mediaSessionEnabled },
#endif
        { "MediaSourceEnabled"_s, &WebPreferences::mediaSourceEnabled },
#if ENABLE(MEDIA_STREAM)
        { "MediaDevicesEnabled"_s, &WebPreferences::mediaDevicesEnabled },
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
        { "MediaRecorderEnabledWebM"_s, &WebPreferences::mediaRecorderEnabledWebM },
#endif
#if ENABLE(MEDIA_RECORDER)
        { "MediaRecorderEnabled"_s, &WebPreferences::mediaRecorderEnabled },
#endif
        { "MediaSessionCaptureToggleAPIEnabled"_s, &WebPreferences::mediaSessionCaptureToggleAPIEnabled },
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
        { "MediaSourceInWorkerEnabled"_s, &WebPreferences::mediaSourceInWorkerEnabled },
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
        { "MediaSourcePrefersDecompressionSession"_s, &WebPreferences::mediaSourcePrefersDecompressionSession },
#endif
#if ENABLE(MEDIA_STREAM)
        { "MediaStreamTrackProcessingEnabled"_s, &WebPreferences::mediaStreamTrackProcessingEnabled },
#endif
        { "MetaViewportInteractiveWidgetEnabled"_s, &WebPreferences::metaViewportInteractiveWidgetEnabled },
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
        { "ModelNoPortalAttributeEnabled"_s, &WebPreferences::modelNoPortalAttributeEnabled },
#endif
#if USE(MODERN_AVCONTENTKEYSESSION)
        { "ShouldUseModernAVContentKeySession"_s, &WebPreferences::shouldUseModernAVContentKeySession },
#endif
        { "MomentumScrollingAnimatorEnabled"_s, &WebPreferences::momentumScrollingAnimatorEnabled },
        { "InputTypeMonthEnabled"_s, &WebPreferences::inputTypeMonthEnabled },
#if ENABLE(TOUCH_EVENTS)
        { "MouseEventsSimulationEnabled"_s, &WebPreferences::mouseEventsSimulationEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "MuteCameraOnMicrophoneInterruptionEnabled"_s, &WebPreferences::muteCameraOnMicrophoneInterruptionEnabled },
#endif
        { "NavigationAPIEnabled"_s, &WebPreferences::navigationAPIEnabled },
#if ENABLE(APP_BOUND_DOMAINS)
        { "NeedsInAppBrowserPrivacyQuirks"_s, &WebPreferences::needsInAppBrowserPrivacyQuirks },
#endif
        { "NeedsSiteSpecificQuirks"_s, &WebPreferences::needsSiteSpecificQuirks },
        { "NeedsStorageAccessFromFileURLsQuirk"_s, &WebPreferences::needsStorageAccessFromFileURLsQuirk },
        { "FlexFormattingContextIntegrationEnabled"_s, &WebPreferences::flexFormattingContextIntegrationEnabled },
#if ENABLE(NOTIFICATION_EVENT)
        { "NotificationEventEnabled"_s, &WebPreferences::notificationEventEnabled },
#endif
#if ENABLE(NOTIFICATIONS)
        { "NotificationsEnabled"_s, &WebPreferences::notificationsEnabled },
#endif
        { "ObservableEnabled"_s, &WebPreferences::observableEnabled },
#if ENABLE(AX_THREAD_TEXT_APIS)
        { "AccessibilityThreadTextApisEnabled"_s, &WebPreferences::accessibilityThreadTextApisEnabled },
#endif
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
        { "OffscreenCanvasInWorkersEnabled"_s, &WebPreferences::offscreenCanvasInWorkersEnabled },
#endif
#if ENABLE(OFFSCREEN_CANVAS)
        { "OffscreenCanvasEnabled"_s, &WebPreferences::offscreenCanvasEnabled },
#endif
        { "OpportunisticSweepingAndGarbageCollectionEnabled"_s, &WebPreferences::opportunisticSweepingAndGarbageCollectionEnabled },
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
        { "OptInPartitionedCookiesEnabled"_s, &WebPreferences::optInPartitionedCookiesEnabled },
#endif
        { "OverlappingBackingStoreProvidersEnabled"_s, &WebPreferences::overlappingBackingStoreProvidersEnabled },
#if ENABLE(OVERLAY_REGIONS_IN_EVENT_REGION)
        { "OverlayRegionsEnabled"_s, &WebPreferences::overlayRegionsEnabled },
#endif
        { "PageVisibilityBasedProcessSuppressionEnabled"_s, &WebPreferences::pageVisibilityBasedProcessSuppressionEnabled },
        { "PermissionsAPIEnabled"_s, &WebPreferences::permissionsAPIEnabled },
#if HAVE(PHOTOS_UI)
        { "PhotoPickerPrefersOriginalImageFormat"_s, &WebPreferences::photoPickerPrefersOriginalImageFormat },
#endif
#if HAVE(PIP_SKIP_PREROLL)
        { "PictureInPicturePlaybackStateEnabled"_s, &WebPreferences::pictureInPicturePlaybackStateEnabled },
#endif
        { "GetCoalescedEventsEnabled"_s, &WebPreferences::getCoalescedEventsEnabled },
        { "GetPredictedEventsEnabled"_s, &WebPreferences::getPredictedEventsEnabled },
#if ENABLE(POINTER_LOCK)
        { "PointerLockEnabled"_s, &WebPreferences::pointerLockEnabled },
#endif
#if ENABLE(POINTER_LOCK)
        { "PointerLockOptionsEnabled"_s, &WebPreferences::pointerLockOptionsEnabled },
#endif
        { "PreferPageRenderingUpdatesNear60FPSEnabled"_s, &WebPreferences::preferPageRenderingUpdatesNear60FPSEnabled },
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
        { "PreferSpatialAudioExperience"_s, &WebPreferences::preferSpatialAudioExperience },
#endif
#if ENABLE(FULLSCREEN_API)
        { "VideoFullsceenPrefersMostVisibleHeuristic"_s, &WebPreferences::videoFullsceenPrefersMostVisibleHeuristic },
#endif
        { "PrivateClickMeasurementDebugModeEnabled"_s, &WebPreferences::privateClickMeasurementDebugModeEnabled },
        { "PrivateClickMeasurementFraudPreventionEnabled"_s, &WebPreferences::privateClickMeasurementFraudPreventionEnabled },
        { "PrivateClickMeasurementEnabled"_s, &WebPreferences::privateClickMeasurementEnabled },
        { "PrivateTokenUsageByThirdPartyEnabled"_s, &WebPreferences::privateTokenUsageByThirdPartyEnabled },
#if ENABLE(DAMAGE_TRACKING)
        { "PropagateDamagingInformation"_s, &WebPreferences::propagateDamagingInformation },
#endif
        { "PushAPIEnabled"_s, &WebPreferences::pushAPIEnabled },
        { "LegacyPluginQuirkForMailSignaturesEnabled"_s, &WebPreferences::legacyPluginQuirkForMailSignaturesEnabled },
        { "GoogleAntiFlickerOptimizationQuirkEnabled"_s, &WebPreferences::googleAntiFlickerOptimizationQuirkEnabled },
        { "ReadableByteStreamAPIEnabled"_s, &WebPreferences::readableByteStreamAPIEnabled },
        { "RemoteMediaSessionManagerEnabled"_s, &WebPreferences::remoteMediaSessionManagerEnabled },
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
        { "RemotePlaybackEnabled"_s, &WebPreferences::remotePlaybackEnabled },
#endif
        { "RemoteSnapshottingEnabled"_s, &WebPreferences::remoteSnapshottingEnabled },
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
        { "RemoveBackgroundEnabled"_s, &WebPreferences::removeBackgroundEnabled },
#endif
        { "RequestVideoFrameCallbackEnabled"_s, &WebPreferences::requestVideoFrameCallbackEnabled },
#if HAVE(SC_CONTENT_SHARING_PICKER)
        { "RequireUAGetDisplayMediaPrompt"_s, &WebPreferences::requireUAGetDisplayMediaPrompt },
#endif
        { "LoginStatusAPIRequiresWebAuthnEnabled"_s, &WebPreferences::loginStatusAPIRequiresWebAuthnEnabled },
#if ENABLE(MEDIA_STREAM)
        { "SpeakerSelectionRequiresUserGesture"_s, &WebPreferences::speakerSelectionRequiresUserGesture },
#endif
        { "FullscreenRequirementForScreenOrientationLockingEnabled"_s, &WebPreferences::fullscreenRequirementForScreenOrientationLockingEnabled },
#if ENABLE(MEDIA_STREAM)
        { "GetUserMediaRequiresFocus"_s, &WebPreferences::getUserMediaRequiresFocus },
#endif
        { "ResourceLoadSchedulingEnabled"_s, &WebPreferences::resourceLoadSchedulingEnabled },
#if ENABLE(RESOURCE_USAGE)
        { "ResourceUsageOverlayVisible"_s, &WebPreferences::resourceUsageOverlayVisible },
#endif
        { "RespondToThermalPressureAggressively"_s, &WebPreferences::respondToThermalPressureAggressively },
        { "SKAttributionEnabled"_s, &WebPreferences::sKAttributionEnabled },
        { "SafeBrowsingEnabled"_s, &WebPreferences::safeBrowsingEnabled },
        { "IsSameSiteStrictEnforcementEnabled"_s, &WebPreferences::isSameSiteStrictEnforcementEnabled },
        { "ScopedCustomElementRegistryEnabled"_s, &WebPreferences::scopedCustomElementRegistryEnabled },
        { "ScreenOrientationLockingAPIEnabled"_s, &WebPreferences::screenOrientationLockingAPIEnabled },
        { "ScreenOrientationAPIEnabled"_s, &WebPreferences::screenOrientationAPIEnabled },
#if ENABLE(SCREEN_TIME)
        { "ScreenTimeEnabled"_s, &WebPreferences::screenTimeEnabled },
#endif
        { "ScreenWakeLockAPIEnabled"_s, &WebPreferences::screenWakeLockAPIEnabled },
#if ENABLE(MEDIA_STREAM)
        { "ScreenCaptureEnabled"_s, &WebPreferences::screenCaptureEnabled },
#endif
        { "ScriptTrackingPrivacyLoggingEnabled"_s, &WebPreferences::scriptTrackingPrivacyLoggingEnabled },
        { "ScriptTrackingPrivacyProtectionsEnabled"_s, &WebPreferences::scriptTrackingPrivacyProtectionsEnabled },
        { "ScrollingPerformanceTestingEnabled"_s, &WebPreferences::scrollingPerformanceTestingEnabled },
        { "ScrollToTextFragmentFeatureDetectionEnabled"_s, &WebPreferences::scrollToTextFragmentFeatureDetectionEnabled },
        { "ScrollToTextFragmentGenerationEnabled"_s, &WebPreferences::scrollToTextFragmentGenerationEnabled },
        { "ScrollToTextFragmentIndicatorEnabled"_s, &WebPreferences::scrollToTextFragmentIndicatorEnabled },
        { "ScrollToTextFragmentMarkingEnabled"_s, &WebPreferences::scrollToTextFragmentMarkingEnabled },
        { "ScrollToTextFragmentEnabled"_s, &WebPreferences::scrollToTextFragmentEnabled },
        { "ScrollAnimatorEnabled"_s, &WebPreferences::scrollAnimatorEnabled },
        { "ScrollDrivenAnimationsEnabled"_s, &WebPreferences::scrollDrivenAnimationsEnabled },
        { "SecureContextChecksEnabled"_s, &WebPreferences::secureContextChecksEnabled },
        { "SelectionFlippingEnabled"_s, &WebPreferences::selectionFlippingEnabled },
#if PLATFORM(IOS_FAMILY)
        { "SelectionHonorsOverflowScrolling"_s, &WebPreferences::selectionHonorsOverflowScrolling },
#endif
        { "ServiceWorkerInstallEventEnabled"_s, &WebPreferences::serviceWorkerInstallEventEnabled },
        { "ServiceWorkerNavigationPreloadEnabled"_s, &WebPreferences::serviceWorkerNavigationPreloadEnabled },
        { "ServiceWorkersEnabled"_s, &WebPreferences::serviceWorkersEnabled },
        { "ShapeDetection"_s, &WebPreferences::shapeDetection },
        { "SiteIsolationSharedProcessEnabled"_s, &WebPreferences::siteIsolationSharedProcessEnabled },
        { "SharedWorkerEnabled"_s, &WebPreferences::sharedWorkerEnabled },
        { "ShowMediaStatsContextMenuItemEnabled"_s, &WebPreferences::showMediaStatsContextMenuItemEnabled },
        { "ShowFrameProcessBordersEnabled"_s, &WebPreferences::showFrameProcessBordersEnabled },
        { "SidewaysWritingModesEnabled"_s, &WebPreferences::sidewaysWritingModesEnabled },
        { "SiteIsolationEnabled"_s, &WebPreferences::siteIsolationEnabled },
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
        { "SpatialImageControlsEnabled"_s, &WebPreferences::spatialImageControlsEnabled },
#endif
        { "SpeechRecognitionEnabled"_s, &WebPreferences::speechRecognitionEnabled },
        { "SpeechSynthesisAPIEnabled"_s, &WebPreferences::speechSynthesisAPIEnabled },
        { "StorageAPIEstimateEnabled"_s, &WebPreferences::storageAPIEstimateEnabled },
        { "StorageAPIEnabled"_s, &WebPreferences::storageAPIEnabled },
        { "SupportHDRCompositorTonemappingEnabled"_s, &WebPreferences::supportHDRCompositorTonemappingEnabled },
        { "SupportHDRDisplayEnabled"_s, &WebPreferences::supportHDRDisplayEnabled },
        { "ProcessSwapOnCrossSiteNavigationEnabled"_s, &WebPreferences::processSwapOnCrossSiteNavigationEnabled },
        { "ShouldTakeNearSuspendedAssertions"_s, &WebPreferences::shouldTakeNearSuspendedAssertions },
#if ENABLE(WRITING_TOOLS)
        { "TextAnimationsEnabled"_s, &WebPreferences::textAnimationsEnabled },
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
        { "TextRecognitionInVideosEnabled"_s, &WebPreferences::textRecognitionInVideosEnabled },
#endif
#if ENABLE(MEDIA_SOURCE)
        { "TextTracksInMSEEnabled"_s, &WebPreferences::textTracksInMSEEnabled },
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
        { "ThreadedAnimationResolutionEnabled"_s, &WebPreferences::threadedAnimationResolutionEnabled },
#endif
        { "TiledScrollingIndicatorVisible"_s, &WebPreferences::tiledScrollingIndicatorVisible },
        { "InputTypeTimeEnabled"_s, &WebPreferences::inputTypeTimeEnabled },
        { "TopContentInsetBackgroundCanChangeAfterScrolling"_s, &WebPreferences::topContentInsetBackgroundCanChangeAfterScrolling },
#if ENABLE(WEBXR)
        { "TouchInputCompatibilityEnabled"_s, &WebPreferences::touchInputCompatibilityEnabled },
#endif
        { "TrackConfigurationEnabled"_s, &WebPreferences::trackConfigurationEnabled },
        { "TrustedTypesEnabled"_s, &WebPreferences::trustedTypesEnabled },
        { "URLPatternAPIEnabled"_s, &WebPreferences::uRLPatternAPIEnabled },
        { "UndoManagerAPIEnabled"_s, &WebPreferences::undoManagerAPIEnabled },
#if ENABLE(UNIFIED_PDF)
        { "UnifiedPDFEnabled"_s, &WebPreferences::unifiedPDFEnabled },
#endif
#if ENABLE(DAMAGE_TRACKING)
        { "UnifyDamagedRegions"_s, &WebPreferences::unifyDamagedRegions },
#endif
        { "IPAddressAndLocalhostMixedContentUpgradeTestingEnabled"_s, &WebPreferences::iPAddressAndLocalhostMixedContentUpgradeTestingEnabled },
        { "UpgradeKnownHostsToHTTPSEnabled"_s, &WebPreferences::upgradeKnownHostsToHTTPSEnabled },
        { "UpgradeMixedContentEnabled"_s, &WebPreferences::upgradeMixedContentEnabled },
#if ENABLE(ARKIT_INLINE_PREVIEW)
        { "UseARKitForModel"_s, &WebPreferences::useARKitForModel },
#endif
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
        { "UseAVCaptureDeviceRotationCoordinatorAPI"_s, &WebPreferences::useAVCaptureDeviceRotationCoordinatorAPI },
#endif
        { "UseIFCForSVGText"_s, &WebPreferences::useIFCForSVGText },
#if ENABLE(MEDIA_STREAM)
        { "UseMicrophoneMuteStatusAPI"_s, &WebPreferences::useMicrophoneMuteStatusAPI },
#endif
#if HAVE(SCENEKIT)
        { "UseSceneKitForModel"_s, &WebPreferences::useSceneKitForModel },
#endif
        { "UseGiantTiles"_s, &WebPreferences::useGiantTiles },
#if ENABLE(DAMAGE_TRACKING)
        { "UseDamagingInformationForCompositing"_s, &WebPreferences::useDamagingInformationForCompositing },
#endif
        { "UserActivationAPIEnabled"_s, &WebPreferences::userActivationAPIEnabled },
        { "UserGesturePromisePropagationEnabled"_s, &WebPreferences::userGesturePromisePropagationEnabled },
#if HAVE(WEBCONTENTRESTRICTIONS)
        { "UsesWebContentRestrictionsForFilter"_s, &WebPreferences::usesWebContentRestrictionsForFilter },
#endif
        { "ServiceWorkersUserGestureEnabled"_s, &WebPreferences::serviceWorkersUserGestureEnabled },
        { "VerifyWindowOpenUserGestureFromUIProcess"_s, &WebPreferences::verifyWindowOpenUserGestureFromUIProcess },
        { "VerticalFormControlsEnabled"_s, &WebPreferences::verticalFormControlsEnabled },
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        { "VideoRendererProtectedFallbackDisabled"_s, &WebPreferences::videoRendererProtectedFallbackDisabled },
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        { "VideoRendererUseDecompressionSessionForProtected"_s, &WebPreferences::videoRendererUseDecompressionSessionForProtected },
#endif
        { "ViewTransitionClassesEnabled"_s, &WebPreferences::viewTransitionClassesEnabled },
        { "ViewTransitionTypesEnabled"_s, &WebPreferences::viewTransitionTypesEnabled },
        { "ViewTransitionsEnabled"_s, &WebPreferences::viewTransitionsEnabled },
        { "ViewGestureDebuggingEnabled"_s, &WebPreferences::viewGestureDebuggingEnabled },
#if ENABLE(IMAGE_ANALYSIS)
        { "VisualTranslationEnabled"_s, &WebPreferences::visualTranslationEnabled },
#endif
        { "VisualViewportAPIEnabled"_s, &WebPreferences::visualViewportAPIEnabled },
#if PLATFORM(IOS_FAMILY)
        { "VisuallyContiguousBidiTextSelectionEnabled"_s, &WebPreferences::visuallyContiguousBidiTextSelectionEnabled },
#endif
        { "WebAPIStatisticsEnabled"_s, &WebPreferences::webAPIStatisticsEnabled },
        { "WebAPIsInShadowRealmEnabled"_s, &WebPreferences::webAPIsInShadowRealmEnabled },
        { "WebAnimationsOverallProgressPropertyEnabled"_s, &WebPreferences::webAnimationsOverallProgressPropertyEnabled },
        { "WebAnimationsCustomEffectsEnabled"_s, &WebPreferences::webAnimationsCustomEffectsEnabled },
        { "WebAnimationsCustomFrameRateEnabled"_s, &WebPreferences::webAnimationsCustomFrameRateEnabled },
#if ENABLE(WEB_ARCHIVE)
        { "WebArchiveDebugModeEnabled"_s, &WebPreferences::webArchiveDebugModeEnabled },
#endif
#if ENABLE(WEB_ARCHIVE)
        { "WebArchiveTestingModeEnabled"_s, &WebPreferences::webArchiveTestingModeEnabled },
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
        { "WebAuthenticationASEnabled"_s, &WebPreferences::webAuthenticationASEnabled },
#endif
#if ENABLE(WEB_AUTHN)
        { "WebAuthenticationEnabled"_s, &WebPreferences::webAuthenticationEnabled },
#endif
        { "WebCryptoSafeCurvesEnabled"_s, &WebPreferences::webCryptoSafeCurvesEnabled },
        { "WebCryptoX25519Enabled"_s, &WebPreferences::webCryptoX25519Enabled },
        { "WebLocksAPIEnabled"_s, &WebPreferences::webLocksAPIEnabled },
        { "WebShareFileAPIEnabled"_s, &WebPreferences::webShareFileAPIEnabled },
        { "WebShareEnabled"_s, &WebPreferences::webShareEnabled },
#if ENABLE(WEBASSEMBLY)
        { "WebAssemblyESMIntegrationEnabled"_s, &WebPreferences::webAssemblyESMIntegrationEnabled },
#endif
#if ENABLE(WEB_CODECS)
        { "WebCodecsAV1Enabled"_s, &WebPreferences::webCodecsAV1Enabled },
#endif
#if ENABLE(WEB_CODECS)
        { "WebCodecsAudioEnabled"_s, &WebPreferences::webCodecsAudioEnabled },
#endif
#if ENABLE(WEB_CODECS)
        { "WebCodecsHEVCEnabled"_s, &WebPreferences::webCodecsHEVCEnabled },
#endif
#if ENABLE(WEB_CODECS)
        { "WebCodecsVideoEnabled"_s, &WebPreferences::webCodecsVideoEnabled },
#endif
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
        { "WebExtensionBookmarksEnabled"_s, &WebPreferences::webExtensionBookmarksEnabled },
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
        { "WebExtensionSidebarEnabled"_s, &WebPreferences::webExtensionSidebarEnabled },
#endif
        { "WebGLDraftExtensionsEnabled"_s, &WebPreferences::webGLDraftExtensionsEnabled },
        { "WebGLTimerQueriesEnabled"_s, &WebPreferences::webGLTimerQueriesEnabled },
        { "WebGLEnabled"_s, &WebPreferences::webGLEnabled },
        { "WebGPUHDREnabled"_s, &WebPreferences::webGPUHDREnabled },
        { "WebXRWebGPUBindingsEnabled"_s, &WebPreferences::webXRWebGPUBindingsEnabled },
        { "WebGPUEnabled"_s, &WebPreferences::webGPUEnabled },
        { "WebInspectorEngineeringSettingsAllowed"_s, &WebPreferences::webInspectorEngineeringSettingsAllowed },
#if ENABLE(WEB_RTC)
        { "WebRTCAV1CodecEnabled"_s, &WebPreferences::webRTCAV1CodecEnabled },
#endif
        { "WebRTCAudioLatencyAdaptationEnabled"_s, &WebPreferences::webRTCAudioLatencyAdaptationEnabled },
#if ENABLE(WEB_RTC)
        { "WebRTCDTMFEnabled"_s, &WebPreferences::webRTCDTMFEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCEncodedTransformEnabled"_s, &WebPreferences::webRTCEncodedTransformEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCH264HardwareEncoderEnabled"_s, &WebPreferences::webRTCH264HardwareEncoderEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCH265CodecEnabled"_s, &WebPreferences::webRTCH265CodecEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCL4SEnabled"_s, &WebPreferences::webRTCL4SEnabled },
#endif
        { "WebRTCMediaPipelineAdditionalLoggingEnabled"_s, &WebPreferences::webRTCMediaPipelineAdditionalLoggingEnabled },
#if ENABLE(WEB_RTC)
        { "LegacyWebRTCOfferOptionsEnabled"_s, &WebPreferences::legacyWebRTCOfferOptionsEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "PeerConnectionVideoScalingAdaptationDisabled"_s, &WebPreferences::peerConnectionVideoScalingAdaptationDisabled },
#endif
#if ENABLE(WEB_RTC)
        { "PeerConnectionEnabled"_s, &WebPreferences::peerConnectionEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCRemoteVideoFrameEnabled"_s, &WebPreferences::webRTCRemoteVideoFrameEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCSFrameTransformEnabled"_s, &WebPreferences::webRTCSFrameTransformEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCSocketsProxyingEnabled"_s, &WebPreferences::webRTCSocketsProxyingEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCVP9Profile0CodecEnabled"_s, &WebPreferences::webRTCVP9Profile0CodecEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCVP9Profile2CodecEnabled"_s, &WebPreferences::webRTCVP9Profile2CodecEnabled },
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
        { "WebRTCInterfaceMonitoringViaNWEnabled"_s, &WebPreferences::webRTCInterfaceMonitoringViaNWEnabled },
#endif
        { "WebTransportEnabled"_s, &WebPreferences::webTransportEnabled },
#if ENABLE(WEBXR)
        { "WebXRAugmentedRealityModuleEnabled"_s, &WebPreferences::webXRAugmentedRealityModuleEnabled },
#endif
#if ENABLE(WEBXR)
        { "WebXREnabled"_s, &WebPreferences::webXREnabled },
#endif
#if ENABLE(WEBXR)
        { "WebXRGamepadsModuleEnabled"_s, &WebPreferences::webXRGamepadsModuleEnabled },
#endif
#if ENABLE(WEBXR_HANDS)
        { "WebXRHandInputModuleEnabled"_s, &WebPreferences::webXRHandInputModuleEnabled },
#endif
#if ENABLE(WEBXR_LAYERS)
        { "WebXRLayersAPIEnabled"_s, &WebPreferences::webXRLayersAPIEnabled },
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
        { "WebPageSpatialBackdropEnabled"_s, &WebPreferences::webPageSpatialBackdropEnabled },
#endif
        { "InputTypeWeekEnabled"_s, &WebPreferences::inputTypeWeekEnabled },
        { "WheelEventGesturesBecomeNonBlocking"_s, &WebPreferences::wheelEventGesturesBecomeNonBlocking },
        { "PassiveWheelListenersAsDefaultOnDocument"_s, &WebPreferences::passiveWheelListenersAsDefaultOnDocument },
        { "WorkerAsynchronousURLErrorHandlingEnabled"_s, &WebPreferences::workerAsynchronousURLErrorHandlingEnabled },
#if PLATFORM(COCOA)
        { "WriteRichTextDataWhenCopyingOrDragging"_s, &WebPreferences::writeRichTextDataWhenCopyingOrDragging },
#endif
#if ENABLE(WRITING_SUGGESTIONS)
        { "WritingSuggestionsAttributeEnabled"_s, &WebPreferences::writingSuggestionsAttributeEnabled },
#endif
#if ENABLE(XSLT)
        { "XSLTEnabled"_s, &WebPreferences::xSLTEnabled },
#endif
        { "IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled"_s, &WebPreferences::isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled },
        { "IsFirstPartyWebsiteDataRemovalReproTestingEnabled"_s, &WebPreferences::isFirstPartyWebsiteDataRemovalReproTestingEnabled },
        { "AltitudeAngleEnabled"_s, &WebPreferences::altitudeAngleEnabled },
        { "AzimuthAngleEnabled"_s, &WebPreferences::azimuthAngleEnabled },
        { "InputTypeDateTimeLocalEnabled"_s, &WebPreferences::inputTypeDateTimeLocalEnabled },
        { "CaretPositionFromPointEnabled"_s, &WebPreferences::caretPositionFromPointEnabled },
        { "HiddenUntilFoundEnabled"_s, &WebPreferences::hiddenUntilFoundEnabled },
        { "HTTPEquivEnabled"_s, &WebPreferences::httpEquivEnabled },
        { "ShadowRootReferenceTargetEnabledForAriaOwns"_s, &WebPreferences::shadowRootReferenceTargetEnabledForAriaOwns },
        { "ShadowRootReferenceTargetEnabled"_s, &WebPreferences::shadowRootReferenceTargetEnabled },
        { "RequestIdleCallbackEnabled"_s, &WebPreferences::requestIdleCallbackEnabled },
        { "RequestStorageAccessThrowsExceptionUntilReload"_s, &WebPreferences::requestStorageAccessThrowsExceptionUntilReload },
        { "ScrollendEventEnabled"_s, &WebPreferences::scrollendEventEnabled },
        { "CSSWordBreakAutoPhraseEnabled"_s, &WebPreferences::cssWordBreakAutoPhraseEnabled },
    };

    const String& key = feature.key();

    for (auto& getter : getters) {
        if (key == getter.name)
            return (this->*getter.function)();
    }

    return false;
}

void WebPreferences::setFeatureEnabled(const API::Feature& feature, bool value)
{
    setFeatureEnabledForKey(feature.key(), value);
}

void WebPreferences::setFeatureEnabledForKey(const String& key, bool value)
{
    struct FeatureSetterMapping {
        ASCIILiteral name;
        void (WebPreferences::*function) (const bool&);
    };

    static FeatureSetterMapping setters[] = {
        { "DatabasesEnabled"_s, &WebPreferences::setDatabasesEnabled },
        { "LoadDeferringEnabled"_s, &WebPreferences::setLoadDeferringEnabled },
        { "AcceleratedCompositingEnabled"_s, &WebPreferences::setAcceleratedCompositingEnabled },
        { "AcceleratedCompositingForFixedPositionEnabled"_s, &WebPreferences::setAcceleratedCompositingForFixedPositionEnabled },
        { "WirelessPlaybackTargetAPIEnabled"_s, &WebPreferences::setWirelessPlaybackTargetAPIEnabled },
        { "LoadsImagesAutomatically"_s, &WebPreferences::setLoadsImagesAutomatically },
        { "LinkPreconnect"_s, &WebPreferences::setLinkPreconnect },
        { "WindowFocusRestricted"_s, &WebPreferences::setWindowFocusRestricted },
        { "AggressiveTileRetentionEnabled"_s, &WebPreferences::setAggressiveTileRetentionEnabled },
        { "AllowContentSecurityPolicySourceStarToMatchAnyProtocol"_s, &WebPreferences::setAllowContentSecurityPolicySourceStarToMatchAnyProtocol },
        { "AllowDisplayOfInsecureContent"_s, &WebPreferences::setAllowDisplayOfInsecureContent },
        { "AllowFileAccessFromFileURLs"_s, &WebPreferences::setAllowFileAccessFromFileURLs },
        { "LowPowerVideoAudioBufferSizeEnabled"_s, &WebPreferences::setLowPowerVideoAudioBufferSizeEnabled },
        { "AllowMultiElementImplicitSubmission"_s, &WebPreferences::setAllowMultiElementImplicitSubmission },
        { "AllowRunningOfInsecureContent"_s, &WebPreferences::setAllowRunningOfInsecureContent },
        { "AllowTestOnlyIPC"_s, &WebPreferences::setAllowTestOnlyIPC },
#if ENABLE(MATHML)
        { "MathMLEnabled"_s, &WebPreferences::setMathMLEnabled },
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
        { "AllowsAirPlayForMediaPlayback"_s, &WebPreferences::setAllowsAirPlayForMediaPlayback },
#endif
        { "AllowsInlineMediaPlayback"_s, &WebPreferences::setAllowsInlineMediaPlayback },
        { "AllowsInlineMediaPlaybackAfterFullscreen"_s, &WebPreferences::setAllowsInlineMediaPlaybackAfterFullscreen },
        { "AllowsPictureInPictureMediaPlayback"_s, &WebPreferences::setAllowsPictureInPictureMediaPlayback },
#if PLATFORM(IOS_FAMILY)
        { "AlternateFullScreenControlDesignEnabled"_s, &WebPreferences::setAlternateFullScreenControlDesignEnabled },
#endif
        { "WebSocketEnabled"_s, &WebPreferences::setWebSocketEnabled },
        { "MediaCapabilitiesEnabled"_s, &WebPreferences::setMediaCapabilitiesEnabled },
        { "WebSecurityEnabled"_s, &WebPreferences::setWebSecurityEnabled },
        { "AnimatedImageAsyncDecodingEnabled"_s, &WebPreferences::setAnimatedImageAsyncDecodingEnabled },
        { "AppleMailPaginationQuirkEnabled"_s, &WebPreferences::setAppleMailPaginationQuirkEnabled },
#if ENABLE(APPLE_PAY)
        { "ApplePayCapabilityDisclosureAllowed"_s, &WebPreferences::setApplePayCapabilityDisclosureAllowed },
#endif
#if ENABLE(APPLE_PAY)
        { "ApplePayEnabled"_s, &WebPreferences::setApplePayEnabled },
#endif
        { "LargeImageAsyncDecodingEnabled"_s, &WebPreferences::setLargeImageAsyncDecodingEnabled },
        { "AsynchronousSpellCheckingEnabled"_s, &WebPreferences::setAsynchronousSpellCheckingEnabled },
        { "JavaScriptMarkupEnabled"_s, &WebPreferences::setJavaScriptMarkupEnabled },
        { "AudioControlsScaleWithPageZoom"_s, &WebPreferences::setAudioControlsScaleWithPageZoom },
        { "JavaScriptCanOpenWindowsAutomatically"_s, &WebPreferences::setJavaScriptCanOpenWindowsAutomatically },
        { "AuthorAndUserStylesEnabled"_s, &WebPreferences::setAuthorAndUserStylesEnabled },
#if ENABLE(WEB_AUDIO)
        { "WebAudioEnabled"_s, &WebPreferences::setWebAudioEnabled },
#endif
        { "JavaScriptCanAccessClipboard"_s, &WebPreferences::setJavaScriptCanAccessClipboard },
        { "WantsBalancedSetDefersLoadingBehavior"_s, &WebPreferences::setWantsBalancedSetDefersLoadingBehavior },
        { "VisualViewportEnabled"_s, &WebPreferences::setVisualViewportEnabled },
#if ENABLE(VIDEO)
        { "VideoQualityIncludesDisplayCompositingEnabled"_s, &WebPreferences::setVideoQualityIncludesDisplayCompositingEnabled },
#endif
        { "BackspaceKeyNavigationEnabled"_s, &WebPreferences::setBackspaceKeyNavigationEnabled },
        { "VideoPresentationModeAPIEnabled"_s, &WebPreferences::setVideoPresentationModeAPIEnabled },
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
        { "MediaControlsContextMenusEnabled"_s, &WebPreferences::setMediaControlsContextMenusEnabled },
#endif
        { "VideoPresentationManagerEnabled"_s, &WebPreferences::setVideoPresentationManagerEnabled },
        { "MediaControlsScaleWithPageZoom"_s, &WebPreferences::setMediaControlsScaleWithPageZoom },
#if ENABLE(FULLSCREEN_API)
        { "VideoFullscreenRequiresElementFullscreen"_s, &WebPreferences::setVideoFullscreenRequiresElementFullscreen },
#endif
        { "MediaDataLoadsAutomatically"_s, &WebPreferences::setMediaDataLoadsAutomatically },
        { "MediaPreloadingEnabled"_s, &WebPreferences::setMediaPreloadingEnabled },
        { "InvisibleAutoplayNotPermitted"_s, &WebPreferences::setInvisibleAutoplayNotPermitted },
#if ENABLE(MEDIA_STREAM)
        { "InterruptVideoOnPageVisibilityChangeEnabled"_s, &WebPreferences::setInterruptVideoOnPageVisibilityChangeEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "InterruptAudioOnPageVisibilityChangeEnabled"_s, &WebPreferences::setInterruptAudioOnPageVisibilityChangeEnabled },
#endif
#if ENABLE(VP9)
        { "VP9DecoderEnabled"_s, &WebPreferences::setVP9DecoderEnabled },
#endif
        { "MediaUserGestureInheritsFromDocument"_s, &WebPreferences::setMediaUserGestureInheritsFromDocument },
        { "InspectorSupportsShowingCertificate"_s, &WebPreferences::setInspectorSupportsShowingCertificate },
        { "InspectorStartsAttached"_s, &WebPreferences::setInspectorStartsAttached },
        { "MockCaptureDevicesPromptEnabled"_s, &WebPreferences::setMockCaptureDevicesPromptEnabled },
        { "MockScrollbarsControllerEnabled"_s, &WebPreferences::setMockScrollbarsControllerEnabled },
        { "MockScrollbarsEnabled"_s, &WebPreferences::setMockScrollbarsEnabled },
        { "InlineMediaPlaybackRequiresPlaysInlineAttribute"_s, &WebPreferences::setInlineMediaPlaybackRequiresPlaysInlineAttribute },
#if HAVE(INCREMENTAL_PDF_APIS)
        { "IncrementalPDFLoadingEnabled"_s, &WebPreferences::setIncrementalPDFLoadingEnabled },
#endif
        { "IncompleteImageBorderEnabled"_s, &WebPreferences::setIncompleteImageBorderEnabled },
        { "NeedsAdobeFrameReloadingQuirk"_s, &WebPreferences::setNeedsAdobeFrameReloadingQuirk },
        { "NeedsFrameNameFallbackToIdQuirk"_s, &WebPreferences::setNeedsFrameNameFallbackToIdQuirk },
        { "NeedsKeyboardEventDisambiguationQuirks"_s, &WebPreferences::setNeedsKeyboardEventDisambiguationQuirks },
#if PLATFORM(COCOA)
        { "PDFPluginEnabled"_s, &WebPreferences::setPDFPluginEnabled },
#endif
#if PLATFORM(COCOA)
        { "PDFPluginHUDEnabled"_s, &WebPreferences::setPDFPluginHUDEnabled },
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
        { "PDFPluginPageNumberIndicatorEnabled"_s, &WebPreferences::setPDFPluginPageNumberIndicatorEnabled },
#endif
        { "PassiveTouchListenersAsDefaultOnDocument"_s, &WebPreferences::setPassiveTouchListenersAsDefaultOnDocument },
        { "PasswordEchoEnabled"_s, &WebPreferences::setPasswordEchoEnabled },
#if ENABLE(PICTURE_IN_PICTURE_API)
        { "PictureInPictureAPIEnabled"_s, &WebPreferences::setPictureInPictureAPIEnabled },
#endif
        { "PunchOutWhiteBackgroundsInDarkMode"_s, &WebPreferences::setPunchOutWhiteBackgroundsInDarkMode },
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
        { "RequiresPageVisibilityForVideoToBeNowPlaying"_s, &WebPreferences::setRequiresPageVisibilityForVideoToBeNowPlaying },
#endif
        { "RequiresPageVisibilityToPlayAudio"_s, &WebPreferences::setRequiresPageVisibilityToPlayAudio },
        { "HiddenPageCSSAnimationSuspensionEnabled"_s, &WebPreferences::setHiddenPageCSSAnimationSuspensionEnabled },
        { "RequiresUserGestureForAudioPlayback"_s, &WebPreferences::setRequiresUserGestureForAudioPlayback },
        { "RequiresUserGestureForMediaPlayback"_s, &WebPreferences::setRequiresUserGestureForMediaPlayback },
        { "RequiresUserGestureForVideoPlayback"_s, &WebPreferences::setRequiresUserGestureForVideoPlayback },
        { "RequiresUserGestureToLoadVideo"_s, &WebPreferences::setRequiresUserGestureToLoadVideo },
        { "UsesSingleWebProcess"_s, &WebPreferences::setUsesSingleWebProcess },
#if HAVE(RUBBER_BANDING)
        { "RubberBandingForSubScrollableRegionsEnabled"_s, &WebPreferences::setRubberBandingForSubScrollableRegionsEnabled },
#endif
        { "UsesEncodingDetector"_s, &WebPreferences::setUsesEncodingDetector },
        { "SelectTrailingWhitespaceEnabled"_s, &WebPreferences::setSelectTrailingWhitespaceEnabled },
        { "UsesBackForwardCache"_s, &WebPreferences::setUsesBackForwardCache },
        { "CaretBrowsingEnabled"_s, &WebPreferences::setCaretBrowsingEnabled },
        { "UseSystemAppearance"_s, &WebPreferences::setUseSystemAppearance },
#if ENABLE(SERVICE_CONTROLS)
        { "ServiceControlsEnabled"_s, &WebPreferences::setServiceControlsEnabled },
#endif
#if USE(GSTREAMER)
        { "GStreamerEnabled"_s, &WebPreferences::setGStreamerEnabled },
#endif
        { "ServiceWorkerEntitlementDisabledForTesting"_s, &WebPreferences::setServiceWorkerEntitlementDisabledForTesting },
        { "ShouldAllowUserInstalledFonts"_s, &WebPreferences::setShouldAllowUserInstalledFonts },
        { "ColorFilterEnabled"_s, &WebPreferences::setColorFilterEnabled },
        { "UsePreHTML5ParserQuirks"_s, &WebPreferences::setUsePreHTML5ParserQuirks },
        { "ShouldConvertInvalidURLsToBlank"_s, &WebPreferences::setShouldConvertInvalidURLsToBlank },
        { "ShouldConvertPositionStyleOnCopy"_s, &WebPreferences::setShouldConvertPositionStyleOnCopy },
        { "ShouldDecidePolicyBeforeLoadingQuickLookPreview"_s, &WebPreferences::setShouldDecidePolicyBeforeLoadingQuickLookPreview },
#if ENABLE(VIDEO)
        { "ShouldDisplayCaptions"_s, &WebPreferences::setShouldDisplayCaptions },
#endif
#if ENABLE(CONTENT_CHANGE_OBSERVER)
        { "ContentChangeObserverEnabled"_s, &WebPreferences::setContentChangeObserverEnabled },
#endif
        { "ContentDispositionAttachmentSandboxEnabled"_s, &WebPreferences::setContentDispositionAttachmentSandboxEnabled },
        { "ForceWebGLUsesLowPower"_s, &WebPreferences::setForceWebGLUsesLowPower },
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
        { "ContextMenuQRCodeDetectionEnabled"_s, &WebPreferences::setContextMenuQRCodeDetectionEnabled },
#endif
#if ENABLE(VIDEO)
        { "ShouldDisplaySubtitles"_s, &WebPreferences::setShouldDisplaySubtitles },
#endif
        { "ForceFTPDirectoryListings"_s, &WebPreferences::setForceFTPDirectoryListings },
        { "ForceCompositingMode"_s, &WebPreferences::setForceCompositingMode },
#if ENABLE(VIDEO)
        { "ShouldDisplayTextDescriptions"_s, &WebPreferences::setShouldDisplayTextDescriptions },
#endif
#if ENABLE(TEXT_AUTOSIZING)
        { "ShouldEnableTextAutosizingBoost"_s, &WebPreferences::setShouldEnableTextAutosizingBoost },
#endif
        { "UseImageDocumentForSubframePDF"_s, &WebPreferences::setUseImageDocumentForSubframePDF },
        { "ShouldIgnoreMetaViewport"_s, &WebPreferences::setShouldIgnoreMetaViewport },
        { "ShouldPrintBackgrounds"_s, &WebPreferences::setShouldPrintBackgrounds },
        { "ShouldRespectImageOrientation"_s, &WebPreferences::setShouldRespectImageOrientation },
        { "ShouldRestrictBaseURLSchemes"_s, &WebPreferences::setShouldRestrictBaseURLSchemes },
        { "ShouldSuppressTextInputFromEditingDuringProvisionalNavigation"_s, &WebPreferences::setShouldSuppressTextInputFromEditingDuringProvisionalNavigation },
        { "DOMPasteAllowed"_s, &WebPreferences::setDOMPasteAllowed },
        { "ShouldUseServiceWorkerShortTimeout"_s, &WebPreferences::setShouldUseServiceWorkerShortTimeout },
#if HAVE(APP_SSO)
        { "ExtensibleSSOEnabled"_s, &WebPreferences::setExtensibleSSOEnabled },
#endif
        { "TreatsAnyTextCSSLinkAsStylesheet"_s, &WebPreferences::setTreatsAnyTextCSSLinkAsStylesheet },
        { "LinkPreloadEnabled"_s, &WebPreferences::setLinkPreloadEnabled },
        { "ShowsToolTipOverTruncatedText"_s, &WebPreferences::setShowsToolTipOverTruncatedText },
        { "ThreadedScrollingEnabled"_s, &WebPreferences::setThreadedScrollingEnabled },
        { "TextInteractionEnabled"_s, &WebPreferences::setTextInteractionEnabled },
        { "TextExtractionEnabled"_s, &WebPreferences::setTextExtractionEnabled },
#if ENABLE(TEXT_AUTOSIZING)
        { "TextAutosizingEnabled"_s, &WebPreferences::setTextAutosizingEnabled },
#endif
        { "DeveloperExtrasEnabled"_s, &WebPreferences::setDeveloperExtrasEnabled },
#if ENABLE(DEVICE_ORIENTATION)
        { "DeviceOrientationEventEnabled"_s, &WebPreferences::setDeviceOrientationEventEnabled },
#endif
#if ENABLE(DEVICE_ORIENTATION)
        { "DeviceOrientationPermissionAPIEnabled"_s, &WebPreferences::setDeviceOrientationPermissionAPIEnabled },
#endif
        { "ShowsURLsInToolTipsEnabled"_s, &WebPreferences::setShowsURLsInToolTipsEnabled },
        { "TextAreasAreResizable"_s, &WebPreferences::setTextAreasAreResizable },
        { "TemporaryTileCohortRetentionEnabled"_s, &WebPreferences::setTemporaryTileCohortRetentionEnabled },
        { "TelephoneNumberParsingEnabled"_s, &WebPreferences::setTelephoneNumberParsingEnabled },
        { "ShrinksStandaloneImagesToFit"_s, &WebPreferences::setShrinksStandaloneImagesToFit },
        { "DisabledAdaptationsMetaTagEnabled"_s, &WebPreferences::setDisabledAdaptationsMetaTagEnabled },
        { "DownloadAttributeEnabled"_s, &WebPreferences::setDownloadAttributeEnabled },
        { "TabsToLinks"_s, &WebPreferences::setTabsToLinks },
#if USE(SYSTEM_PREVIEW)
        { "SystemPreviewEnabled"_s, &WebPreferences::setSystemPreviewEnabled },
#endif
        { "SuppressesIncrementalRendering"_s, &WebPreferences::setSuppressesIncrementalRendering },
        { "EnableInheritURIQueryComponent"_s, &WebPreferences::setEnableInheritURIQueryComponent },
#if ENABLE(ENCRYPTED_MEDIA)
        { "EncryptedMediaAPIEnabled"_s, &WebPreferences::setEncryptedMediaAPIEnabled },
#endif
        { "Standalone"_s, &WebPreferences::setStandalone },
        { "SmartInsertDeleteEnabled"_s, &WebPreferences::setSmartInsertDeleteEnabled },
        { "SpatialNavigationEnabled"_s, &WebPreferences::setSpatialNavigationEnabled },
#if ENABLE(MEDIA_SOURCE)
        { "SourceBufferChangeTypeEnabled"_s, &WebPreferences::setSourceBufferChangeTypeEnabled },
#endif
        { "TargetTextPseudoElementEnabled"_s, &WebPreferences::setTargetTextPseudoElementEnabled },
        { "ThumbAndTrackPseudoElementsEnabled"_s, &WebPreferences::setThumbAndTrackPseudoElementsEnabled },
        { "LinkDNSPrefetchEnabled"_s, &WebPreferences::setLinkDNSPrefetchEnabled },
        { "SelectShowPickerEnabled"_s, &WebPreferences::setSelectShowPickerEnabled },
        { "PageAtRuleMarginDescriptorsEnabled"_s, &WebPreferences::setPageAtRuleMarginDescriptorsEnabled },
#if USE(AVFOUNDATION)
        { "AVFoundationEnabled"_s, &WebPreferences::setAVFoundationEnabled },
#endif
#if HAVE(AVKIT_CONTENT_SOURCE)
        { "AVKitContentSourceEnabled"_s, &WebPreferences::setAVKitContentSourceEnabled },
#endif
#if USE(CORE_IMAGE)
        { "AcceleratedFiltersEnabled"_s, &WebPreferences::setAcceleratedFiltersEnabled },
#endif
        { "AccessHandleEnabled"_s, &WebPreferences::setAccessHandleEnabled },
        { "DOMTestingAPIsEnabled"_s, &WebPreferences::setDOMTestingAPIsEnabled },
        { "AllowMediaContentTypesRequiringHardwareSupportAsFallback"_s, &WebPreferences::setAllowMediaContentTypesRequiringHardwareSupportAsFallback },
        { "AllowPrivacySensitiveOperationsInNonPersistentDataStores"_s, &WebPreferences::setAllowPrivacySensitiveOperationsInNonPersistentDataStores },
#if PLATFORM(IOS_FAMILY)
        { "AllowViewportShrinkToFitContent"_s, &WebPreferences::setAllowViewportShrinkToFitContent },
#endif
#if ENABLE(WEBGL)
        { "AllowWebGLInWorkers"_s, &WebPreferences::setAllowWebGLInWorkers },
#endif
#if ENABLE(MEDIA_STREAM)
        { "PerElementSpeakerSelectionEnabled"_s, &WebPreferences::setPerElementSpeakerSelectionEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ExposeSpeakersWithoutMicrophoneEnabled"_s, &WebPreferences::setExposeSpeakersWithoutMicrophoneEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ExposeSpeakersEnabled"_s, &WebPreferences::setExposeSpeakersEnabled },
#endif
        { "AllowTopNavigationToDataURLs"_s, &WebPreferences::setAllowTopNavigationToDataURLs },
        { "AllowUniversalAccessFromFileURLs"_s, &WebPreferences::setAllowUniversalAccessFromFileURLs },
#if ENABLE(WEB_ARCHIVE)
        { "AlwaysAllowLocalWebarchive"_s, &WebPreferences::setAlwaysAllowLocalWebarchive },
#endif
#if ENABLE(VP9)
        { "SWVPDecodersAlwaysEnabled"_s, &WebPreferences::setSWVPDecodersAlwaysEnabled },
#endif
        { "AppBadgeEnabled"_s, &WebPreferences::setAppBadgeEnabled },
#if ENABLE(APP_HIGHLIGHTS)
        { "AppHighlightsEnabled"_s, &WebPreferences::setAppHighlightsEnabled },
#endif
        { "AsyncFrameScrollingEnabled"_s, &WebPreferences::setAsyncFrameScrollingEnabled },
        { "AsyncOverflowScrollingEnabled"_s, &WebPreferences::setAsyncOverflowScrollingEnabled },
#if PLATFORM(IOS_FAMILY)
        { "UseAsyncUIKitInteractions"_s, &WebPreferences::setUseAsyncUIKitInteractions },
#endif
        { "AsyncClipboardAPIEnabled"_s, &WebPreferences::setAsyncClipboardAPIEnabled },
#if ENABLE(ATTACHMENT_ELEMENT)
        { "AttachmentElementEnabled"_s, &WebPreferences::setAttachmentElementEnabled },
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
        { "AttachmentWideLayoutEnabled"_s, &WebPreferences::setAttachmentWideLayoutEnabled },
#endif
#if ENABLE(VIDEO)
        { "ExtendedAudioDescriptionsEnabled"_s, &WebPreferences::setExtendedAudioDescriptionsEnabled },
#endif
#if ENABLE(VIDEO)
        { "AudioDescriptionsEnabled"_s, &WebPreferences::setAudioDescriptionsEnabled },
#endif
#if ENABLE(DOM_AUDIO_SESSION)
        { "DOMAudioSessionEnabled"_s, &WebPreferences::setDOMAudioSessionEnabled },
#endif
#if ENABLE(DOM_AUDIO_SESSION)
        { "DOMAudioSessionFullEnabled"_s, &WebPreferences::setDOMAudioSessionFullEnabled },
#endif
        { "AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth"_s, &WebPreferences::setAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth },
        { "BeaconAPIEnabled"_s, &WebPreferences::setBeaconAPIEnabled },
        { "BidiContentAwarePasteEnabled"_s, &WebPreferences::setBidiContentAwarePasteEnabled },
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        { "BlockFontServiceInWebContentSandbox"_s, &WebPreferences::setBlockFontServiceInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        { "BlockIconServicesInWebContentSandbox"_s, &WebPreferences::setBlockIconServicesInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        { "BlockMobileAssetInWebContentSandbox"_s, &WebPreferences::setBlockMobileAssetInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(IOS)
        { "BlockMobileGestaltInWebContentSandbox"_s, &WebPreferences::setBlockMobileGestaltInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        { "BlockOpenDirectoryInWebContentSandbox"_s, &WebPreferences::setBlockOpenDirectoryInWebContentSandbox },
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        { "BlockWebInspectorInWebContentSandbox"_s, &WebPreferences::setBlockWebInspectorInWebContentSandbox },
#endif
        { "BroadcastChannelEnabled"_s, &WebPreferences::setBroadcastChannelEnabled },
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
        { "BuiltInNotificationsEnabled"_s, &WebPreferences::setBuiltInNotificationsEnabled },
#endif
        { "CSS3DTransformBackfaceVisibilityInteroperabilityEnabled"_s, &WebPreferences::setCSS3DTransformBackfaceVisibilityInteroperabilityEnabled },
        { "CSSCounterStyleAtRuleImageSymbolsEnabled"_s, &WebPreferences::setCSSCounterStyleAtRuleImageSymbolsEnabled },
        { "AccentColorEnabled"_s, &WebPreferences::setAccentColorEnabled },
        { "CSSAnchorPositioningEnabled"_s, &WebPreferences::setCSSAnchorPositioningEnabled },
        { "CSSAnchorPositioningPositionVisibilityEnabled"_s, &WebPreferences::setCSSAnchorPositioningPositionVisibilityEnabled },
        { "DevolvableWidgetsEnabled"_s, &WebPreferences::setDevolvableWidgetsEnabled },
        { "CSSInputSecurityEnabled"_s, &WebPreferences::setCSSInputSecurityEnabled },
        { "MasonryEnabled"_s, &WebPreferences::setMasonryEnabled },
        { "OverscrollBehaviorEnabled"_s, &WebPreferences::setOverscrollBehaviorEnabled },
        { "CSSPaintingAPIEnabled"_s, &WebPreferences::setCSSPaintingAPIEnabled },
        { "CSSRhythmicSizingEnabled"_s, &WebPreferences::setCSSRhythmicSizingEnabled },
        { "CSSScrollAnchoringEnabled"_s, &WebPreferences::setCSSScrollAnchoringEnabled },
        { "SpringTimingFunctionEnabled"_s, &WebPreferences::setSpringTimingFunctionEnabled },
        { "CSSTreeCountingFunctionsEnabled"_s, &WebPreferences::setCSSTreeCountingFunctionsEnabled },
        { "CSSTypedOMColorEnabled"_s, &WebPreferences::setCSSTypedOMColorEnabled },
        { "CSSURLModifiersEnabled"_s, &WebPreferences::setCSSURLModifiersEnabled },
        { "CSSURLIntegrityModifierEnabled"_s, &WebPreferences::setCSSURLIntegrityModifierEnabled },
        { "CSSUnprefixedBackdropFilterEnabled"_s, &WebPreferences::setCSSUnprefixedBackdropFilterEnabled },
        { "CSSAppearanceBaseEnabled"_s, &WebPreferences::setCSSAppearanceBaseEnabled },
        { "CSSAxisRelativePositionKeywordsEnabled"_s, &WebPreferences::setCSSAxisRelativePositionKeywordsEnabled },
        { "CSSBackgroundClipBorderAreaEnabled"_s, &WebPreferences::setCSSBackgroundClipBorderAreaEnabled },
        { "CSSColorLayersEnabled"_s, &WebPreferences::setCSSColorLayersEnabled },
        { "CSSContrastColorEnabled"_s, &WebPreferences::setCSSContrastColorEnabled },
        { "CSSCornerShapeEnabled"_s, &WebPreferences::setCSSCornerShapeEnabled },
        { "CSSDPropertyEnabled"_s, &WebPreferences::setCSSDPropertyEnabled },
        { "CSSDynamicRangeLimitMixEnabled"_s, &WebPreferences::setCSSDynamicRangeLimitMixEnabled },
        { "CSSConstrainedDynamicRangeLimitEnabled"_s, &WebPreferences::setCSSConstrainedDynamicRangeLimitEnabled },
        { "CSSFieldSizingEnabled"_s, &WebPreferences::setCSSFieldSizingEnabled },
        { "CSSFontVariantEmojiEnabled"_s, &WebPreferences::setCSSFontVariantEmojiEnabled },
        { "CSSLineClampEnabled"_s, &WebPreferences::setCSSLineClampEnabled },
        { "CSSLineFitEdgeEnabled"_s, &WebPreferences::setCSSLineFitEdgeEnabled },
        { "CSSProgressFunctionEnabled"_s, &WebPreferences::setCSSProgressFunctionEnabled },
        { "CSSRandomFunctionEnabled"_s, &WebPreferences::setCSSRandomFunctionEnabled },
        { "CSSRubyAlignEnabled"_s, &WebPreferences::setCSSRubyAlignEnabled },
        { "CSSRubyOverhangEnabled"_s, &WebPreferences::setCSSRubyOverhangEnabled },
        { "CSSScrollbarColorEnabled"_s, &WebPreferences::setCSSScrollbarColorEnabled },
        { "CSSScrollbarGutterEnabled"_s, &WebPreferences::setCSSScrollbarGutterEnabled },
        { "CSSScrollbarWidthEnabled"_s, &WebPreferences::setCSSScrollbarWidthEnabled },
        { "CSSShapeFunctionEnabled"_s, &WebPreferences::setCSSShapeFunctionEnabled },
        { "CSSTextAutospaceEnabled"_s, &WebPreferences::setCSSTextAutospaceEnabled },
        { "CSSTextBoxTrimEnabled"_s, &WebPreferences::setCSSTextBoxTrimEnabled },
        { "CSSTextGroupAlignEnabled"_s, &WebPreferences::setCSSTextGroupAlignEnabled },
        { "CSSTextJustifyEnabled"_s, &WebPreferences::setCSSTextJustifyEnabled },
        { "CSSTextSpacingTrimEnabled"_s, &WebPreferences::setCSSTextSpacingTrimEnabled },
        { "CSSTextUnderlinePositionLeftRightEnabled"_s, &WebPreferences::setCSSTextUnderlinePositionLeftRightEnabled },
        { "CSSTextWrapPrettyEnabled"_s, &WebPreferences::setCSSTextWrapPrettyEnabled },
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
        { "CSSTransformStyleSeparatedEnabled"_s, &WebPreferences::setCSSTransformStyleSeparatedEnabled },
#endif
        { "CacheAPIEnabled"_s, &WebPreferences::setCacheAPIEnabled },
        { "CanvasColorSpaceEnabled"_s, &WebPreferences::setCanvasColorSpaceEnabled },
        { "CanvasFiltersEnabled"_s, &WebPreferences::setCanvasFiltersEnabled },
        { "CanvasLayersEnabled"_s, &WebPreferences::setCanvasLayersEnabled },
#if USE(CA) || USE(SKIA)
        { "CanvasUsesAcceleratedDrawing"_s, &WebPreferences::setCanvasUsesAcceleratedDrawing },
#endif
        { "CanvasPixelFormatEnabled"_s, &WebPreferences::setCanvasPixelFormatEnabled },
        { "ChildProcessDebuggabilityEnabled"_s, &WebPreferences::setChildProcessDebuggabilityEnabled },
        { "ClearSiteDataHTTPHeaderEnabled"_s, &WebPreferences::setClearSiteDataHTTPHeaderEnabled },
        { "ClearSiteDataExecutionContextsSupportEnabled"_s, &WebPreferences::setClearSiteDataExecutionContextsSupportEnabled },
        { "CloseWatcherEnabled"_s, &WebPreferences::setCloseWatcherEnabled },
        { "InputTypeColorEnabled"_s, &WebPreferences::setInputTypeColorEnabled },
        { "CompositingBordersVisible"_s, &WebPreferences::setCompositingBordersVisible },
        { "CompositingRepaintCountersVisible"_s, &WebPreferences::setCompositingRepaintCountersVisible },
        { "CompressionStreamEnabled"_s, &WebPreferences::setCompressionStreamEnabled },
        { "ContactPickerAPIEnabled"_s, &WebPreferences::setContactPickerAPIEnabled },
        { "ContentInsetBackgroundFillEnabled"_s, &WebPreferences::setContentInsetBackgroundFillEnabled },
        { "CookieConsentAPIEnabled"_s, &WebPreferences::setCookieConsentAPIEnabled },
        { "CookieStoreManagerEnabled"_s, &WebPreferences::setCookieStoreManagerEnabled },
        { "CookieStoreAPIExtendedAttributesEnabled"_s, &WebPreferences::setCookieStoreAPIExtendedAttributesEnabled },
        { "CookieStoreAPIEnabled"_s, &WebPreferences::setCookieStoreAPIEnabled },
        { "CookieEnabled"_s, &WebPreferences::setCookieEnabled },
#if PLATFORM(MAC)
        { "InputMethodUsesCorrectKeyEventOrder"_s, &WebPreferences::setInputMethodUsesCorrectKeyEventOrder },
#endif
        { "CrossDocumentViewTransitionsEnabled"_s, &WebPreferences::setCrossDocumentViewTransitionsEnabled },
        { "CrossOriginEmbedderPolicyEnabled"_s, &WebPreferences::setCrossOriginEmbedderPolicyEnabled },
        { "CrossOriginOpenerPolicyEnabled"_s, &WebPreferences::setCrossOriginOpenerPolicyEnabled },
        { "CustomPasteboardDataEnabled"_s, &WebPreferences::setCustomPasteboardDataEnabled },
        { "DOMPasteAccessRequestsEnabled"_s, &WebPreferences::setDOMPasteAccessRequestsEnabled },
        { "MutationEventsEnabled"_s, &WebPreferences::setMutationEventsEnabled },
        { "DOMTimersThrottlingEnabled"_s, &WebPreferences::setDOMTimersThrottlingEnabled },
#if PLATFORM(IOS_FAMILY)
        { "ZoomOnDoubleTapWhenRoot"_s, &WebPreferences::setZoomOnDoubleTapWhenRoot },
#endif
#if PLATFORM(IOS_FAMILY)
        { "AlwaysZoomOnDoubleTap"_s, &WebPreferences::setAlwaysZoomOnDoubleTap },
#endif
        { "DataTransferItemsEnabled"_s, &WebPreferences::setDataTransferItemsEnabled },
        { "DataListElementEnabled"_s, &WebPreferences::setDataListElementEnabled },
        { "InputTypeDateEnabled"_s, &WebPreferences::setInputTypeDateEnabled },
        { "DateTimeInputsEditableComponentsEnabled"_s, &WebPreferences::setDateTimeInputsEditableComponentsEnabled },
#if ENABLE(DECLARATIVE_WEB_PUSH)
        { "DeclarativeWebPush"_s, &WebPreferences::setDeclarativeWebPush },
#endif
        { "ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint"_s, &WebPreferences::setShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint },
        { "DeprecationReportingEnabled"_s, &WebPreferences::setDeprecationReportingEnabled },
#if ENABLE(MEDIA_SOURCE)
        { "DetachableMediaSourceEnabled"_s, &WebPreferences::setDetachableMediaSourceEnabled },
#endif
        { "UAVisualTransitionDetectionEnabled"_s, &WebPreferences::setUAVisualTransitionDetectionEnabled },
        { "DiagnosticLoggingEnabled"_s, &WebPreferences::setDiagnosticLoggingEnabled },
#if ENABLE(WEB_AUTHN)
        { "DigitalCredentialsEnabled"_s, &WebPreferences::setDigitalCredentialsEnabled },
#endif
        { "DirectoryUploadEnabled"_s, &WebPreferences::setDirectoryUploadEnabled },
        { "IsThirdPartyCookieBlockingDisabled"_s, &WebPreferences::setIsThirdPartyCookieBlockingDisabled },
        { "IsFirstPartyWebsiteDataRemovalDisabled"_s, &WebPreferences::setIsFirstPartyWebsiteDataRemovalDisabled },
#if PLATFORM(IOS_FAMILY)
        { "DisableScreenSizeOverride"_s, &WebPreferences::setDisableScreenSizeOverride },
#endif
        { "ShouldDropNearSuspendedAssertionAfterDelay"_s, &WebPreferences::setShouldDropNearSuspendedAssertionAfterDelay },
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        { "UseCGDisplayListsForDOMRendering"_s, &WebPreferences::setUseCGDisplayListsForDOMRendering },
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        { "ReplayCGDisplayListsIntoBackingStore"_s, &WebPreferences::setReplayCGDisplayListsIntoBackingStore },
#endif
        { "DynamicSiteInterventionsEnabled"_s, &WebPreferences::setDynamicSiteInterventionsEnabled },
        { "EmbedElementEnabled"_s, &WebPreferences::setEmbedElementEnabled },
#if PLATFORM(MAC)
        { "EnableAccessibilityOnDemand"_s, &WebPreferences::setEnableAccessibilityOnDemand },
#endif
#if PLATFORM(IOS_FAMILY)
        { "AutomaticLiveResizeEnabled"_s, &WebPreferences::setAutomaticLiveResizeEnabled },
#endif
        { "CanvasFingerprintingQuirkEnabled"_s, &WebPreferences::setCanvasFingerprintingQuirkEnabled },
        { "EnableElementCurrentCSSZoom"_s, &WebPreferences::setEnableElementCurrentCSSZoom },
        { "EnumeratingAllNetworkInterfacesEnabled"_s, &WebPreferences::setEnumeratingAllNetworkInterfacesEnabled },
        { "EnumeratingVisibleNetworkInterfacesEnabled"_s, &WebPreferences::setEnumeratingVisibleNetworkInterfacesEnabled },
        { "ICECandidateFilteringEnabled"_s, &WebPreferences::setICECandidateFilteringEnabled },
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
        { "LegacyEncryptedMediaAPIEnabled"_s, &WebPreferences::setLegacyEncryptedMediaAPIEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "MockCaptureDevicesEnabled"_s, &WebPreferences::setMockCaptureDevicesEnabled },
#endif
#if ENABLE(MODEL_PROCESS)
        { "ModelProcessEnabled"_s, &WebPreferences::setModelProcessEnabled },
#endif
#if ENABLE(PDFJS)
        { "PDFJSViewerEnabled"_s, &WebPreferences::setPDFJSViewerEnabled },
#endif
        { "AuxclickEventEnabled"_s, &WebPreferences::setAuxclickEventEnabled },
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
        { "BackgroundWebContentRunningBoardThrottlingEnabled"_s, &WebPreferences::setBackgroundWebContentRunningBoardThrottlingEnabled },
#endif
        { "BackgroundFetchAPIEnabled"_s, &WebPreferences::setBackgroundFetchAPIEnabled },
#if HAVE(SANDBOX_STATE_FLAGS)
        { "EnableDebuggingFeaturesInSandbox"_s, &WebPreferences::setEnableDebuggingFeaturesInSandbox },
#endif
#if HAVE(NETWORK_LOADER)
        { "CFNetworkNetworkLoaderEnabled"_s, &WebPreferences::setCFNetworkNetworkLoaderEnabled },
#endif
#if HAVE(MACH_BOOTSTRAP_EXTENSION) || HAVE(SANDBOX_STATE_FLAGS)
        { "ExperimentalSandboxEnabled"_s, &WebPreferences::setExperimentalSandboxEnabled },
#endif
        { "NavigatorUserAgentDataJavaScriptAPIEnabled"_s, &WebPreferences::setNavigatorUserAgentDataJavaScriptAPIEnabled },
        { "BlobFileAccessEnforcementEnabled"_s, &WebPreferences::setBlobFileAccessEnforcementEnabled },
        { "EnterKeyHintEnabled"_s, &WebPreferences::setEnterKeyHintEnabled },
        { "EventTimingEnabled"_s, &WebPreferences::setEventTimingEnabled },
        { "EventHandlerDrivenSmoothKeyboardScrollingEnabled"_s, &WebPreferences::setEventHandlerDrivenSmoothKeyboardScrollingEnabled },
#if ENABLE(MEDIA_SESSION_COORDINATOR)
        { "MediaSessionCoordinatorEnabled"_s, &WebPreferences::setMediaSessionCoordinatorEnabled },
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
        { "MediaSessionPlaylistEnabled"_s, &WebPreferences::setMediaSessionPlaylistEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ExposeCaptureDevicesAfterCaptureEnabled"_s, &WebPreferences::setExposeCaptureDevicesAfterCaptureEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ExposeDefaultSpeakerAsSpecificDeviceEnabled"_s, &WebPreferences::setExposeDefaultSpeakerAsSpecificDeviceEnabled },
#endif
        { "FTPEnabled"_s, &WebPreferences::setFTPEnabled },
#if PLATFORM(IOS_FAMILY)
        { "PreferFasterClickOverDoubleTap"_s, &WebPreferences::setPreferFasterClickOverDoubleTap },
#endif
#if PLATFORM(IOS_FAMILY)
        { "FasterClicksEnabled"_s, &WebPreferences::setFasterClicksEnabled },
#endif
        { "FileSystemEnabled"_s, &WebPreferences::setFileSystemEnabled },
        { "FileSystemWritableStreamEnabled"_s, &WebPreferences::setFileSystemWritableStreamEnabled },
        { "FileReaderAPIEnabled"_s, &WebPreferences::setFileReaderAPIEnabled },
        { "FilterLinkDecorationByDefaultEnabled"_s, &WebPreferences::setFilterLinkDecorationByDefaultEnabled },
        { "ForceLockdownFontParserEnabled"_s, &WebPreferences::setForceLockdownFontParserEnabled },
#if PLATFORM(IOS_FAMILY)
        { "ForceAlwaysUserScalable"_s, &WebPreferences::setForceAlwaysUserScalable },
#endif
#if ENABLE(FORM_CONTROL_REFRESH)
        { "FormControlRefreshEnabled"_s, &WebPreferences::setFormControlRefreshEnabled },
#endif
#if ENABLE(CONTENT_EXTENSIONS)
        { "IFrameResourceMonitoringTestingSettingsEnabled"_s, &WebPreferences::setIFrameResourceMonitoringTestingSettingsEnabled },
#endif
#if ENABLE(CONTENT_EXTENSIONS)
        { "IFrameResourceMonitoringEnabled"_s, &WebPreferences::setIFrameResourceMonitoringEnabled },
#endif
#if ENABLE(FULLSCREEN_API)
        { "FullScreenKeyboardLock"_s, &WebPreferences::setFullScreenKeyboardLock },
#endif
#if ENABLE(FULLSCREEN_API)
        { "FullScreenEnabled"_s, &WebPreferences::setFullScreenEnabled },
#endif
#if PLATFORM(VISION)
        { "FullscreenSceneAspectRatioLockingEnabled"_s, &WebPreferences::setFullscreenSceneAspectRatioLockingEnabled },
#endif
#if PLATFORM(VISION)
        { "FullscreenSceneDimmingEnabled"_s, &WebPreferences::setFullscreenSceneDimmingEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "CaptureAudioInGPUProcessEnabled"_s, &WebPreferences::setCaptureAudioInGPUProcessEnabled },
#endif
#if ENABLE(GPU_PROCESS)
        { "BlockMediaLayerRehostingInWebContentProcess"_s, &WebPreferences::setBlockMediaLayerRehostingInWebContentProcess },
#endif
#if ENABLE(GPU_PROCESS) && !(PLATFORM(GTK) || PLATFORM(WPE))
        { "UseGPUProcessForCanvasRenderingEnabled"_s, &WebPreferences::setUseGPUProcessForCanvasRenderingEnabled },
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
        { "ManageCaptureStatusBarInGPUProcessEnabled"_s, &WebPreferences::setManageCaptureStatusBarInGPUProcessEnabled },
#endif
#if ENABLE(GPU_PROCESS)
        { "UseGPUProcessForDOMRenderingEnabled"_s, &WebPreferences::setUseGPUProcessForDOMRenderingEnabled },
#endif
#if ENABLE(GPU_PROCESS)
        { "UseGPUProcessForMediaEnabled"_s, &WebPreferences::setUseGPUProcessForMediaEnabled },
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
        { "UseGPUProcessForDisplayCapture"_s, &WebPreferences::setUseGPUProcessForDisplayCapture },
#endif
#if ENABLE(MEDIA_STREAM)
        { "CaptureVideoInGPUProcessEnabled"_s, &WebPreferences::setCaptureVideoInGPUProcessEnabled },
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
        { "UseGPUProcessForWebGLEnabled"_s, &WebPreferences::setUseGPUProcessForWebGLEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCPlatformCodecsInGPUProcessEnabled"_s, &WebPreferences::setWebRTCPlatformCodecsInGPUProcessEnabled },
#endif
#if ENABLE(GAMEPAD)
        { "GamepadTriggerRumbleEnabled"_s, &WebPreferences::setGamepadTriggerRumbleEnabled },
#endif
#if ENABLE(GAMEPAD)
        { "GamepadVibrationActuatorEnabled"_s, &WebPreferences::setGamepadVibrationActuatorEnabled },
#endif
#if ENABLE(GAMEPAD)
        { "GamepadsEnabled"_s, &WebPreferences::setGamepadsEnabled },
#endif
#if ENABLE(VIDEO)
        { "GenericCueAPIEnabled"_s, &WebPreferences::setGenericCueAPIEnabled },
#endif
        { "GeolocationAPIEnabled"_s, &WebPreferences::setGeolocationAPIEnabled },
#if USE(GRAPHICS_CONTEXT_FILTERS)
        { "GraphicsContextFiltersEnabled"_s, &WebPreferences::setGraphicsContextFiltersEnabled },
#endif
        { "AcceleratedDrawingEnabled"_s, &WebPreferences::setAcceleratedDrawingEnabled },
#if ENABLE(MODEL_ELEMENT)
        { "ModelElementEnabled"_s, &WebPreferences::setModelElementEnabled },
#endif
#if ENABLE(MODEL_ELEMENT)
        { "ModelDocumentEnabled"_s, &WebPreferences::setModelDocumentEnabled },
#endif
        { "InteractiveFormValidationEnabled"_s, &WebPreferences::setInteractiveFormValidationEnabled },
#if ENABLE(VIDEO)
        { "MediaEnabled"_s, &WebPreferences::setMediaEnabled },
#endif
        { "InputTypeColorEnhancementsEnabled"_s, &WebPreferences::setInputTypeColorEnhancementsEnabled },
        { "DetailsAutoExpandEnabled"_s, &WebPreferences::setDetailsAutoExpandEnabled },
        { "CommandAttributesEnabled"_s, &WebPreferences::setCommandAttributesEnabled },
        { "HTMLLegacyAttributeValueSerializationEnabled"_s, &WebPreferences::setHTMLLegacyAttributeValueSerializationEnabled },
        { "PopoverAttributeEnabled"_s, &WebPreferences::setPopoverAttributeEnabled },
        { "SwitchControlEnabled"_s, &WebPreferences::setSwitchControlEnabled },
        { "HTTPSByDefaultEnabled"_s, &WebPreferences::setHTTPSByDefaultEnabled },
        { "HiddenPageDOMTimerThrottlingAutoIncreases"_s, &WebPreferences::setHiddenPageDOMTimerThrottlingAutoIncreases },
        { "HiddenPageDOMTimerThrottlingEnabled"_s, &WebPreferences::setHiddenPageDOMTimerThrottlingEnabled },
#if HAVE(MATERIAL_HOSTING)
        { "HostedBlurMaterialInMediaControlsEnabled"_s, &WebPreferences::setHostedBlurMaterialInMediaControlsEnabled },
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        { "BlockIOKitInWebContentSandbox"_s, &WebPreferences::setBlockIOKitInWebContentSandbox },
#endif
        { "IOSurfaceLosslessCompressionEnabled"_s, &WebPreferences::setIOSurfaceLosslessCompressionEnabled },
#if ENABLE(IPC_TESTING_API)
        { "IPCTestingAPIEnabled"_s, &WebPreferences::setIPCTestingAPIEnabled },
#endif
        { "ItpDebugModeEnabled"_s, &WebPreferences::setItpDebugModeEnabled },
#if ENABLE(TEXT_AUTOSIZING)
        { "TextAutosizingUsesIdempotentMode"_s, &WebPreferences::setTextAutosizingUsesIdempotentMode },
#endif
#if ENABLE(IPC_TESTING_API)
        { "IgnoreInvalidMessageWhenIPCTestingAPIEnabled"_s, &WebPreferences::setIgnoreInvalidMessageWhenIPCTestingAPIEnabled },
#endif
        { "IgnoreIframeEmbeddingProtectionsEnabled"_s, &WebPreferences::setIgnoreIframeEmbeddingProtectionsEnabled },
#if ENABLE(IMAGE_ANALYSIS)
        { "ImageAnalysisDuringFindInPageEnabled"_s, &WebPreferences::setImageAnalysisDuringFindInPageEnabled },
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
        { "ImageAnimationControlEnabled"_s, &WebPreferences::setImageAnimationControlEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "ImageCaptureEnabled"_s, &WebPreferences::setImageCaptureEnabled },
#endif
#if ENABLE(SERVICE_CONTROLS)
        { "ImageControlsEnabled"_s, &WebPreferences::setImageControlsEnabled },
#endif
        { "InWindowFullscreenEnabled"_s, &WebPreferences::setInWindowFullscreenEnabled },
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
        { "IncludeIgnoredInCoreAXTree"_s, &WebPreferences::setIncludeIgnoredInCoreAXTree },
#endif
        { "IndexedDBAPIEnabled"_s, &WebPreferences::setIndexedDBAPIEnabled },
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
        { "InteractionRegionsEnabled"_s, &WebPreferences::setInteractionRegionsEnabled },
#endif
#if ENABLE(ACCESSIBILITY_ISOLATED_TREE)
        { "IsAccessibilityIsolatedTreeEnabled"_s, &WebPreferences::setIsAccessibilityIsolatedTreeEnabled },
#endif
        { "JavaScriptEnabled"_s, &WebPreferences::setJavaScriptEnabled },
#if PLATFORM(IOS_FAMILY)
        { "KeyboardDismissalGestureEnabled"_s, &WebPreferences::setKeyboardDismissalGestureEnabled },
#endif
        { "LayerBasedSVGEngineEnabled"_s, &WebPreferences::setLayerBasedSVGEngineEnabled },
        { "LazyIframeLoadingEnabled"_s, &WebPreferences::setLazyIframeLoadingEnabled },
        { "LazyImageLoadingEnabled"_s, &WebPreferences::setLazyImageLoadingEnabled },
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
        { "LegacyOverflowScrollingTouchEnabled"_s, &WebPreferences::setLegacyOverflowScrollingTouchEnabled },
#endif
        { "LegacyLineLayoutVisualCoverageEnabled"_s, &WebPreferences::setLegacyLineLayoutVisualCoverageEnabled },
        { "ShowModalDialogEnabled"_s, &WebPreferences::setShowModalDialogEnabled },
#if ENABLE(MEDIA_STREAM)
        { "MediaCaptureRequiresSecureConnection"_s, &WebPreferences::setMediaCaptureRequiresSecureConnection },
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
        { "LimitedMatroskaSupportEnabled"_s, &WebPreferences::setLimitedMatroskaSupportEnabled },
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
        { "LinearMediaPlayerEnabled"_s, &WebPreferences::setLinearMediaPlayerEnabled },
#endif
        { "LinkSanitizerEnabled"_s, &WebPreferences::setLinkSanitizerEnabled },
        { "LinkPreconnectEarlyHintsEnabled"_s, &WebPreferences::setLinkPreconnectEarlyHintsEnabled },
        { "LinkPrefetchEnabled"_s, &WebPreferences::setLinkPrefetchEnabled },
#if ENABLE(WEB_ARCHIVE)
        { "LoadWebArchiveWithEphemeralStorageEnabled"_s, &WebPreferences::setLoadWebArchiveWithEphemeralStorageEnabled },
#endif
        { "LocalFileContentSniffingEnabled"_s, &WebPreferences::setLocalFileContentSniffingEnabled },
        { "LocalNetworkAccessEnabled"_s, &WebPreferences::setLocalNetworkAccessEnabled },
        { "LocalStorageEnabled"_s, &WebPreferences::setLocalStorageEnabled },
        { "LockdownFontParserEnabled"_s, &WebPreferences::setLockdownFontParserEnabled },
        { "LogsPageMessagesToSystemConsoleEnabled"_s, &WebPreferences::setLogsPageMessagesToSystemConsoleEnabled },
        { "LoginStatusAPIEnabled"_s, &WebPreferences::setLoginStatusAPIEnabled },
        { "MainContentUserGestureOverrideEnabled"_s, &WebPreferences::setMainContentUserGestureOverrideEnabled },
#if ENABLE(MEDIA_SOURCE)
        { "ManagedMediaSourceEnabled"_s, &WebPreferences::setManagedMediaSourceEnabled },
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
        { "ManagedMediaSourceNeedsAirPlay"_s, &WebPreferences::setManagedMediaSourceNeedsAirPlay },
#endif
        { "CoreMathMLEnabled"_s, &WebPreferences::setCoreMathMLEnabled },
        { "MediaCapabilitiesExtensionsEnabled"_s, &WebPreferences::setMediaCapabilitiesExtensionsEnabled },
#if ENABLE(EXTENSION_CAPABILITIES)
        { "MediaCapabilityGrantsEnabled"_s, &WebPreferences::setMediaCapabilityGrantsEnabled },
#endif
        { "MediaPlaybackEnabled"_s, &WebPreferences::setMediaPlaybackEnabled },
#if ENABLE(MEDIA_SESSION)
        { "MediaSessionEnabled"_s, &WebPreferences::setMediaSessionEnabled },
#endif
        { "MediaSourceEnabled"_s, &WebPreferences::setMediaSourceEnabled },
#if ENABLE(MEDIA_STREAM)
        { "MediaDevicesEnabled"_s, &WebPreferences::setMediaDevicesEnabled },
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
        { "MediaRecorderEnabledWebM"_s, &WebPreferences::setMediaRecorderEnabledWebM },
#endif
#if ENABLE(MEDIA_RECORDER)
        { "MediaRecorderEnabled"_s, &WebPreferences::setMediaRecorderEnabled },
#endif
        { "MediaSessionCaptureToggleAPIEnabled"_s, &WebPreferences::setMediaSessionCaptureToggleAPIEnabled },
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
        { "MediaSourceInWorkerEnabled"_s, &WebPreferences::setMediaSourceInWorkerEnabled },
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
        { "MediaSourcePrefersDecompressionSession"_s, &WebPreferences::setMediaSourcePrefersDecompressionSession },
#endif
#if ENABLE(MEDIA_STREAM)
        { "MediaStreamTrackProcessingEnabled"_s, &WebPreferences::setMediaStreamTrackProcessingEnabled },
#endif
        { "MetaViewportInteractiveWidgetEnabled"_s, &WebPreferences::setMetaViewportInteractiveWidgetEnabled },
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
        { "ModelNoPortalAttributeEnabled"_s, &WebPreferences::setModelNoPortalAttributeEnabled },
#endif
#if USE(MODERN_AVCONTENTKEYSESSION)
        { "ShouldUseModernAVContentKeySession"_s, &WebPreferences::setShouldUseModernAVContentKeySession },
#endif
        { "MomentumScrollingAnimatorEnabled"_s, &WebPreferences::setMomentumScrollingAnimatorEnabled },
        { "InputTypeMonthEnabled"_s, &WebPreferences::setInputTypeMonthEnabled },
#if ENABLE(TOUCH_EVENTS)
        { "MouseEventsSimulationEnabled"_s, &WebPreferences::setMouseEventsSimulationEnabled },
#endif
#if ENABLE(MEDIA_STREAM)
        { "MuteCameraOnMicrophoneInterruptionEnabled"_s, &WebPreferences::setMuteCameraOnMicrophoneInterruptionEnabled },
#endif
        { "NavigationAPIEnabled"_s, &WebPreferences::setNavigationAPIEnabled },
#if ENABLE(APP_BOUND_DOMAINS)
        { "NeedsInAppBrowserPrivacyQuirks"_s, &WebPreferences::setNeedsInAppBrowserPrivacyQuirks },
#endif
        { "NeedsSiteSpecificQuirks"_s, &WebPreferences::setNeedsSiteSpecificQuirks },
        { "NeedsStorageAccessFromFileURLsQuirk"_s, &WebPreferences::setNeedsStorageAccessFromFileURLsQuirk },
        { "FlexFormattingContextIntegrationEnabled"_s, &WebPreferences::setFlexFormattingContextIntegrationEnabled },
#if ENABLE(NOTIFICATION_EVENT)
        { "NotificationEventEnabled"_s, &WebPreferences::setNotificationEventEnabled },
#endif
#if ENABLE(NOTIFICATIONS)
        { "NotificationsEnabled"_s, &WebPreferences::setNotificationsEnabled },
#endif
        { "ObservableEnabled"_s, &WebPreferences::setObservableEnabled },
#if ENABLE(AX_THREAD_TEXT_APIS)
        { "AccessibilityThreadTextApisEnabled"_s, &WebPreferences::setAccessibilityThreadTextApisEnabled },
#endif
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
        { "OffscreenCanvasInWorkersEnabled"_s, &WebPreferences::setOffscreenCanvasInWorkersEnabled },
#endif
#if ENABLE(OFFSCREEN_CANVAS)
        { "OffscreenCanvasEnabled"_s, &WebPreferences::setOffscreenCanvasEnabled },
#endif
        { "OpportunisticSweepingAndGarbageCollectionEnabled"_s, &WebPreferences::setOpportunisticSweepingAndGarbageCollectionEnabled },
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
        { "OptInPartitionedCookiesEnabled"_s, &WebPreferences::setOptInPartitionedCookiesEnabled },
#endif
        { "OverlappingBackingStoreProvidersEnabled"_s, &WebPreferences::setOverlappingBackingStoreProvidersEnabled },
#if ENABLE(OVERLAY_REGIONS_IN_EVENT_REGION)
        { "OverlayRegionsEnabled"_s, &WebPreferences::setOverlayRegionsEnabled },
#endif
        { "PageVisibilityBasedProcessSuppressionEnabled"_s, &WebPreferences::setPageVisibilityBasedProcessSuppressionEnabled },
        { "PermissionsAPIEnabled"_s, &WebPreferences::setPermissionsAPIEnabled },
#if HAVE(PHOTOS_UI)
        { "PhotoPickerPrefersOriginalImageFormat"_s, &WebPreferences::setPhotoPickerPrefersOriginalImageFormat },
#endif
#if HAVE(PIP_SKIP_PREROLL)
        { "PictureInPicturePlaybackStateEnabled"_s, &WebPreferences::setPictureInPicturePlaybackStateEnabled },
#endif
        { "GetCoalescedEventsEnabled"_s, &WebPreferences::setGetCoalescedEventsEnabled },
        { "GetPredictedEventsEnabled"_s, &WebPreferences::setGetPredictedEventsEnabled },
#if ENABLE(POINTER_LOCK)
        { "PointerLockEnabled"_s, &WebPreferences::setPointerLockEnabled },
#endif
#if ENABLE(POINTER_LOCK)
        { "PointerLockOptionsEnabled"_s, &WebPreferences::setPointerLockOptionsEnabled },
#endif
        { "PreferPageRenderingUpdatesNear60FPSEnabled"_s, &WebPreferences::setPreferPageRenderingUpdatesNear60FPSEnabled },
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
        { "PreferSpatialAudioExperience"_s, &WebPreferences::setPreferSpatialAudioExperience },
#endif
#if ENABLE(FULLSCREEN_API)
        { "VideoFullsceenPrefersMostVisibleHeuristic"_s, &WebPreferences::setVideoFullsceenPrefersMostVisibleHeuristic },
#endif
        { "PrivateClickMeasurementDebugModeEnabled"_s, &WebPreferences::setPrivateClickMeasurementDebugModeEnabled },
        { "PrivateClickMeasurementFraudPreventionEnabled"_s, &WebPreferences::setPrivateClickMeasurementFraudPreventionEnabled },
        { "PrivateClickMeasurementEnabled"_s, &WebPreferences::setPrivateClickMeasurementEnabled },
        { "PrivateTokenUsageByThirdPartyEnabled"_s, &WebPreferences::setPrivateTokenUsageByThirdPartyEnabled },
#if ENABLE(DAMAGE_TRACKING)
        { "PropagateDamagingInformation"_s, &WebPreferences::setPropagateDamagingInformation },
#endif
        { "PushAPIEnabled"_s, &WebPreferences::setPushAPIEnabled },
        { "LegacyPluginQuirkForMailSignaturesEnabled"_s, &WebPreferences::setLegacyPluginQuirkForMailSignaturesEnabled },
        { "GoogleAntiFlickerOptimizationQuirkEnabled"_s, &WebPreferences::setGoogleAntiFlickerOptimizationQuirkEnabled },
        { "ReadableByteStreamAPIEnabled"_s, &WebPreferences::setReadableByteStreamAPIEnabled },
        { "RemoteMediaSessionManagerEnabled"_s, &WebPreferences::setRemoteMediaSessionManagerEnabled },
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
        { "RemotePlaybackEnabled"_s, &WebPreferences::setRemotePlaybackEnabled },
#endif
        { "RemoteSnapshottingEnabled"_s, &WebPreferences::setRemoteSnapshottingEnabled },
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
        { "RemoveBackgroundEnabled"_s, &WebPreferences::setRemoveBackgroundEnabled },
#endif
        { "RequestVideoFrameCallbackEnabled"_s, &WebPreferences::setRequestVideoFrameCallbackEnabled },
#if HAVE(SC_CONTENT_SHARING_PICKER)
        { "RequireUAGetDisplayMediaPrompt"_s, &WebPreferences::setRequireUAGetDisplayMediaPrompt },
#endif
        { "LoginStatusAPIRequiresWebAuthnEnabled"_s, &WebPreferences::setLoginStatusAPIRequiresWebAuthnEnabled },
#if ENABLE(MEDIA_STREAM)
        { "SpeakerSelectionRequiresUserGesture"_s, &WebPreferences::setSpeakerSelectionRequiresUserGesture },
#endif
        { "FullscreenRequirementForScreenOrientationLockingEnabled"_s, &WebPreferences::setFullscreenRequirementForScreenOrientationLockingEnabled },
#if ENABLE(MEDIA_STREAM)
        { "GetUserMediaRequiresFocus"_s, &WebPreferences::setGetUserMediaRequiresFocus },
#endif
        { "ResourceLoadSchedulingEnabled"_s, &WebPreferences::setResourceLoadSchedulingEnabled },
#if ENABLE(RESOURCE_USAGE)
        { "ResourceUsageOverlayVisible"_s, &WebPreferences::setResourceUsageOverlayVisible },
#endif
        { "RespondToThermalPressureAggressively"_s, &WebPreferences::setRespondToThermalPressureAggressively },
        { "SKAttributionEnabled"_s, &WebPreferences::setSKAttributionEnabled },
        { "SafeBrowsingEnabled"_s, &WebPreferences::setSafeBrowsingEnabled },
        { "IsSameSiteStrictEnforcementEnabled"_s, &WebPreferences::setIsSameSiteStrictEnforcementEnabled },
        { "ScopedCustomElementRegistryEnabled"_s, &WebPreferences::setScopedCustomElementRegistryEnabled },
        { "ScreenOrientationLockingAPIEnabled"_s, &WebPreferences::setScreenOrientationLockingAPIEnabled },
        { "ScreenOrientationAPIEnabled"_s, &WebPreferences::setScreenOrientationAPIEnabled },
#if ENABLE(SCREEN_TIME)
        { "ScreenTimeEnabled"_s, &WebPreferences::setScreenTimeEnabled },
#endif
        { "ScreenWakeLockAPIEnabled"_s, &WebPreferences::setScreenWakeLockAPIEnabled },
#if ENABLE(MEDIA_STREAM)
        { "ScreenCaptureEnabled"_s, &WebPreferences::setScreenCaptureEnabled },
#endif
        { "ScriptTrackingPrivacyLoggingEnabled"_s, &WebPreferences::setScriptTrackingPrivacyLoggingEnabled },
        { "ScriptTrackingPrivacyProtectionsEnabled"_s, &WebPreferences::setScriptTrackingPrivacyProtectionsEnabled },
        { "ScrollingPerformanceTestingEnabled"_s, &WebPreferences::setScrollingPerformanceTestingEnabled },
        { "ScrollToTextFragmentFeatureDetectionEnabled"_s, &WebPreferences::setScrollToTextFragmentFeatureDetectionEnabled },
        { "ScrollToTextFragmentGenerationEnabled"_s, &WebPreferences::setScrollToTextFragmentGenerationEnabled },
        { "ScrollToTextFragmentIndicatorEnabled"_s, &WebPreferences::setScrollToTextFragmentIndicatorEnabled },
        { "ScrollToTextFragmentMarkingEnabled"_s, &WebPreferences::setScrollToTextFragmentMarkingEnabled },
        { "ScrollToTextFragmentEnabled"_s, &WebPreferences::setScrollToTextFragmentEnabled },
        { "ScrollAnimatorEnabled"_s, &WebPreferences::setScrollAnimatorEnabled },
        { "ScrollDrivenAnimationsEnabled"_s, &WebPreferences::setScrollDrivenAnimationsEnabled },
        { "SecureContextChecksEnabled"_s, &WebPreferences::setSecureContextChecksEnabled },
        { "SelectionFlippingEnabled"_s, &WebPreferences::setSelectionFlippingEnabled },
#if PLATFORM(IOS_FAMILY)
        { "SelectionHonorsOverflowScrolling"_s, &WebPreferences::setSelectionHonorsOverflowScrolling },
#endif
        { "ServiceWorkerInstallEventEnabled"_s, &WebPreferences::setServiceWorkerInstallEventEnabled },
        { "ServiceWorkerNavigationPreloadEnabled"_s, &WebPreferences::setServiceWorkerNavigationPreloadEnabled },
        { "ServiceWorkersEnabled"_s, &WebPreferences::setServiceWorkersEnabled },
        { "ShapeDetection"_s, &WebPreferences::setShapeDetection },
        { "SiteIsolationSharedProcessEnabled"_s, &WebPreferences::setSiteIsolationSharedProcessEnabled },
        { "SharedWorkerEnabled"_s, &WebPreferences::setSharedWorkerEnabled },
        { "ShowMediaStatsContextMenuItemEnabled"_s, &WebPreferences::setShowMediaStatsContextMenuItemEnabled },
        { "ShowFrameProcessBordersEnabled"_s, &WebPreferences::setShowFrameProcessBordersEnabled },
        { "SidewaysWritingModesEnabled"_s, &WebPreferences::setSidewaysWritingModesEnabled },
        { "SiteIsolationEnabled"_s, &WebPreferences::setSiteIsolationEnabled },
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
        { "SpatialImageControlsEnabled"_s, &WebPreferences::setSpatialImageControlsEnabled },
#endif
        { "SpeechRecognitionEnabled"_s, &WebPreferences::setSpeechRecognitionEnabled },
        { "SpeechSynthesisAPIEnabled"_s, &WebPreferences::setSpeechSynthesisAPIEnabled },
        { "StorageAPIEstimateEnabled"_s, &WebPreferences::setStorageAPIEstimateEnabled },
        { "StorageAPIEnabled"_s, &WebPreferences::setStorageAPIEnabled },
        { "SupportHDRCompositorTonemappingEnabled"_s, &WebPreferences::setSupportHDRCompositorTonemappingEnabled },
        { "SupportHDRDisplayEnabled"_s, &WebPreferences::setSupportHDRDisplayEnabled },
        { "ProcessSwapOnCrossSiteNavigationEnabled"_s, &WebPreferences::setProcessSwapOnCrossSiteNavigationEnabled },
        { "ShouldTakeNearSuspendedAssertions"_s, &WebPreferences::setShouldTakeNearSuspendedAssertions },
#if ENABLE(WRITING_TOOLS)
        { "TextAnimationsEnabled"_s, &WebPreferences::setTextAnimationsEnabled },
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
        { "TextRecognitionInVideosEnabled"_s, &WebPreferences::setTextRecognitionInVideosEnabled },
#endif
#if ENABLE(MEDIA_SOURCE)
        { "TextTracksInMSEEnabled"_s, &WebPreferences::setTextTracksInMSEEnabled },
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
        { "ThreadedAnimationResolutionEnabled"_s, &WebPreferences::setThreadedAnimationResolutionEnabled },
#endif
        { "TiledScrollingIndicatorVisible"_s, &WebPreferences::setTiledScrollingIndicatorVisible },
        { "InputTypeTimeEnabled"_s, &WebPreferences::setInputTypeTimeEnabled },
        { "TopContentInsetBackgroundCanChangeAfterScrolling"_s, &WebPreferences::setTopContentInsetBackgroundCanChangeAfterScrolling },
#if ENABLE(WEBXR)
        { "TouchInputCompatibilityEnabled"_s, &WebPreferences::setTouchInputCompatibilityEnabled },
#endif
        { "TrackConfigurationEnabled"_s, &WebPreferences::setTrackConfigurationEnabled },
        { "TrustedTypesEnabled"_s, &WebPreferences::setTrustedTypesEnabled },
        { "URLPatternAPIEnabled"_s, &WebPreferences::setURLPatternAPIEnabled },
        { "UndoManagerAPIEnabled"_s, &WebPreferences::setUndoManagerAPIEnabled },
#if ENABLE(UNIFIED_PDF)
        { "UnifiedPDFEnabled"_s, &WebPreferences::setUnifiedPDFEnabled },
#endif
#if ENABLE(DAMAGE_TRACKING)
        { "UnifyDamagedRegions"_s, &WebPreferences::setUnifyDamagedRegions },
#endif
        { "IPAddressAndLocalhostMixedContentUpgradeTestingEnabled"_s, &WebPreferences::setIPAddressAndLocalhostMixedContentUpgradeTestingEnabled },
        { "UpgradeKnownHostsToHTTPSEnabled"_s, &WebPreferences::setUpgradeKnownHostsToHTTPSEnabled },
        { "UpgradeMixedContentEnabled"_s, &WebPreferences::setUpgradeMixedContentEnabled },
#if ENABLE(ARKIT_INLINE_PREVIEW)
        { "UseARKitForModel"_s, &WebPreferences::setUseARKitForModel },
#endif
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
        { "UseAVCaptureDeviceRotationCoordinatorAPI"_s, &WebPreferences::setUseAVCaptureDeviceRotationCoordinatorAPI },
#endif
        { "UseIFCForSVGText"_s, &WebPreferences::setUseIFCForSVGText },
#if ENABLE(MEDIA_STREAM)
        { "UseMicrophoneMuteStatusAPI"_s, &WebPreferences::setUseMicrophoneMuteStatusAPI },
#endif
#if HAVE(SCENEKIT)
        { "UseSceneKitForModel"_s, &WebPreferences::setUseSceneKitForModel },
#endif
        { "UseGiantTiles"_s, &WebPreferences::setUseGiantTiles },
#if ENABLE(DAMAGE_TRACKING)
        { "UseDamagingInformationForCompositing"_s, &WebPreferences::setUseDamagingInformationForCompositing },
#endif
        { "UserActivationAPIEnabled"_s, &WebPreferences::setUserActivationAPIEnabled },
        { "UserGesturePromisePropagationEnabled"_s, &WebPreferences::setUserGesturePromisePropagationEnabled },
#if HAVE(WEBCONTENTRESTRICTIONS)
        { "UsesWebContentRestrictionsForFilter"_s, &WebPreferences::setUsesWebContentRestrictionsForFilter },
#endif
        { "ServiceWorkersUserGestureEnabled"_s, &WebPreferences::setServiceWorkersUserGestureEnabled },
        { "VerifyWindowOpenUserGestureFromUIProcess"_s, &WebPreferences::setVerifyWindowOpenUserGestureFromUIProcess },
        { "VerticalFormControlsEnabled"_s, &WebPreferences::setVerticalFormControlsEnabled },
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        { "VideoRendererProtectedFallbackDisabled"_s, &WebPreferences::setVideoRendererProtectedFallbackDisabled },
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        { "VideoRendererUseDecompressionSessionForProtected"_s, &WebPreferences::setVideoRendererUseDecompressionSessionForProtected },
#endif
        { "ViewTransitionClassesEnabled"_s, &WebPreferences::setViewTransitionClassesEnabled },
        { "ViewTransitionTypesEnabled"_s, &WebPreferences::setViewTransitionTypesEnabled },
        { "ViewTransitionsEnabled"_s, &WebPreferences::setViewTransitionsEnabled },
        { "ViewGestureDebuggingEnabled"_s, &WebPreferences::setViewGestureDebuggingEnabled },
#if ENABLE(IMAGE_ANALYSIS)
        { "VisualTranslationEnabled"_s, &WebPreferences::setVisualTranslationEnabled },
#endif
        { "VisualViewportAPIEnabled"_s, &WebPreferences::setVisualViewportAPIEnabled },
#if PLATFORM(IOS_FAMILY)
        { "VisuallyContiguousBidiTextSelectionEnabled"_s, &WebPreferences::setVisuallyContiguousBidiTextSelectionEnabled },
#endif
        { "WebAPIStatisticsEnabled"_s, &WebPreferences::setWebAPIStatisticsEnabled },
        { "WebAPIsInShadowRealmEnabled"_s, &WebPreferences::setWebAPIsInShadowRealmEnabled },
        { "WebAnimationsOverallProgressPropertyEnabled"_s, &WebPreferences::setWebAnimationsOverallProgressPropertyEnabled },
        { "WebAnimationsCustomEffectsEnabled"_s, &WebPreferences::setWebAnimationsCustomEffectsEnabled },
        { "WebAnimationsCustomFrameRateEnabled"_s, &WebPreferences::setWebAnimationsCustomFrameRateEnabled },
#if ENABLE(WEB_ARCHIVE)
        { "WebArchiveDebugModeEnabled"_s, &WebPreferences::setWebArchiveDebugModeEnabled },
#endif
#if ENABLE(WEB_ARCHIVE)
        { "WebArchiveTestingModeEnabled"_s, &WebPreferences::setWebArchiveTestingModeEnabled },
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
        { "WebAuthenticationASEnabled"_s, &WebPreferences::setWebAuthenticationASEnabled },
#endif
#if ENABLE(WEB_AUTHN)
        { "WebAuthenticationEnabled"_s, &WebPreferences::setWebAuthenticationEnabled },
#endif
        { "WebCryptoSafeCurvesEnabled"_s, &WebPreferences::setWebCryptoSafeCurvesEnabled },
        { "WebCryptoX25519Enabled"_s, &WebPreferences::setWebCryptoX25519Enabled },
        { "WebLocksAPIEnabled"_s, &WebPreferences::setWebLocksAPIEnabled },
        { "WebShareFileAPIEnabled"_s, &WebPreferences::setWebShareFileAPIEnabled },
        { "WebShareEnabled"_s, &WebPreferences::setWebShareEnabled },
#if ENABLE(WEBASSEMBLY)
        { "WebAssemblyESMIntegrationEnabled"_s, &WebPreferences::setWebAssemblyESMIntegrationEnabled },
#endif
#if ENABLE(WEB_CODECS)
        { "WebCodecsAV1Enabled"_s, &WebPreferences::setWebCodecsAV1Enabled },
#endif
#if ENABLE(WEB_CODECS)
        { "WebCodecsAudioEnabled"_s, &WebPreferences::setWebCodecsAudioEnabled },
#endif
#if ENABLE(WEB_CODECS)
        { "WebCodecsHEVCEnabled"_s, &WebPreferences::setWebCodecsHEVCEnabled },
#endif
#if ENABLE(WEB_CODECS)
        { "WebCodecsVideoEnabled"_s, &WebPreferences::setWebCodecsVideoEnabled },
#endif
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
        { "WebExtensionBookmarksEnabled"_s, &WebPreferences::setWebExtensionBookmarksEnabled },
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
        { "WebExtensionSidebarEnabled"_s, &WebPreferences::setWebExtensionSidebarEnabled },
#endif
        { "WebGLDraftExtensionsEnabled"_s, &WebPreferences::setWebGLDraftExtensionsEnabled },
        { "WebGLTimerQueriesEnabled"_s, &WebPreferences::setWebGLTimerQueriesEnabled },
        { "WebGLEnabled"_s, &WebPreferences::setWebGLEnabled },
        { "WebGPUHDREnabled"_s, &WebPreferences::setWebGPUHDREnabled },
        { "WebXRWebGPUBindingsEnabled"_s, &WebPreferences::setWebXRWebGPUBindingsEnabled },
        { "WebGPUEnabled"_s, &WebPreferences::setWebGPUEnabled },
        { "WebInspectorEngineeringSettingsAllowed"_s, &WebPreferences::setWebInspectorEngineeringSettingsAllowed },
#if ENABLE(WEB_RTC)
        { "WebRTCAV1CodecEnabled"_s, &WebPreferences::setWebRTCAV1CodecEnabled },
#endif
        { "WebRTCAudioLatencyAdaptationEnabled"_s, &WebPreferences::setWebRTCAudioLatencyAdaptationEnabled },
#if ENABLE(WEB_RTC)
        { "WebRTCDTMFEnabled"_s, &WebPreferences::setWebRTCDTMFEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCEncodedTransformEnabled"_s, &WebPreferences::setWebRTCEncodedTransformEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCH264HardwareEncoderEnabled"_s, &WebPreferences::setWebRTCH264HardwareEncoderEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCH265CodecEnabled"_s, &WebPreferences::setWebRTCH265CodecEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCL4SEnabled"_s, &WebPreferences::setWebRTCL4SEnabled },
#endif
        { "WebRTCMediaPipelineAdditionalLoggingEnabled"_s, &WebPreferences::setWebRTCMediaPipelineAdditionalLoggingEnabled },
#if ENABLE(WEB_RTC)
        { "LegacyWebRTCOfferOptionsEnabled"_s, &WebPreferences::setLegacyWebRTCOfferOptionsEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "PeerConnectionVideoScalingAdaptationDisabled"_s, &WebPreferences::setPeerConnectionVideoScalingAdaptationDisabled },
#endif
#if ENABLE(WEB_RTC)
        { "PeerConnectionEnabled"_s, &WebPreferences::setPeerConnectionEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCRemoteVideoFrameEnabled"_s, &WebPreferences::setWebRTCRemoteVideoFrameEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCSFrameTransformEnabled"_s, &WebPreferences::setWebRTCSFrameTransformEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCSocketsProxyingEnabled"_s, &WebPreferences::setWebRTCSocketsProxyingEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCVP9Profile0CodecEnabled"_s, &WebPreferences::setWebRTCVP9Profile0CodecEnabled },
#endif
#if ENABLE(WEB_RTC)
        { "WebRTCVP9Profile2CodecEnabled"_s, &WebPreferences::setWebRTCVP9Profile2CodecEnabled },
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
        { "WebRTCInterfaceMonitoringViaNWEnabled"_s, &WebPreferences::setWebRTCInterfaceMonitoringViaNWEnabled },
#endif
        { "WebTransportEnabled"_s, &WebPreferences::setWebTransportEnabled },
#if ENABLE(WEBXR)
        { "WebXRAugmentedRealityModuleEnabled"_s, &WebPreferences::setWebXRAugmentedRealityModuleEnabled },
#endif
#if ENABLE(WEBXR)
        { "WebXREnabled"_s, &WebPreferences::setWebXREnabled },
#endif
#if ENABLE(WEBXR)
        { "WebXRGamepadsModuleEnabled"_s, &WebPreferences::setWebXRGamepadsModuleEnabled },
#endif
#if ENABLE(WEBXR_HANDS)
        { "WebXRHandInputModuleEnabled"_s, &WebPreferences::setWebXRHandInputModuleEnabled },
#endif
#if ENABLE(WEBXR_LAYERS)
        { "WebXRLayersAPIEnabled"_s, &WebPreferences::setWebXRLayersAPIEnabled },
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
        { "WebPageSpatialBackdropEnabled"_s, &WebPreferences::setWebPageSpatialBackdropEnabled },
#endif
        { "InputTypeWeekEnabled"_s, &WebPreferences::setInputTypeWeekEnabled },
        { "WheelEventGesturesBecomeNonBlocking"_s, &WebPreferences::setWheelEventGesturesBecomeNonBlocking },
        { "PassiveWheelListenersAsDefaultOnDocument"_s, &WebPreferences::setPassiveWheelListenersAsDefaultOnDocument },
        { "WorkerAsynchronousURLErrorHandlingEnabled"_s, &WebPreferences::setWorkerAsynchronousURLErrorHandlingEnabled },
#if PLATFORM(COCOA)
        { "WriteRichTextDataWhenCopyingOrDragging"_s, &WebPreferences::setWriteRichTextDataWhenCopyingOrDragging },
#endif
#if ENABLE(WRITING_SUGGESTIONS)
        { "WritingSuggestionsAttributeEnabled"_s, &WebPreferences::setWritingSuggestionsAttributeEnabled },
#endif
#if ENABLE(XSLT)
        { "XSLTEnabled"_s, &WebPreferences::setXSLTEnabled },
#endif
        { "IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled"_s, &WebPreferences::setIsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled },
        { "IsFirstPartyWebsiteDataRemovalReproTestingEnabled"_s, &WebPreferences::setIsFirstPartyWebsiteDataRemovalReproTestingEnabled },
        { "AltitudeAngleEnabled"_s, &WebPreferences::setAltitudeAngleEnabled },
        { "AzimuthAngleEnabled"_s, &WebPreferences::setAzimuthAngleEnabled },
        { "InputTypeDateTimeLocalEnabled"_s, &WebPreferences::setInputTypeDateTimeLocalEnabled },
        { "CaretPositionFromPointEnabled"_s, &WebPreferences::setCaretPositionFromPointEnabled },
        { "HiddenUntilFoundEnabled"_s, &WebPreferences::setHiddenUntilFoundEnabled },
        { "HTTPEquivEnabled"_s, &WebPreferences::setHTTPEquivEnabled },
        { "ShadowRootReferenceTargetEnabledForAriaOwns"_s, &WebPreferences::setShadowRootReferenceTargetEnabledForAriaOwns },
        { "ShadowRootReferenceTargetEnabled"_s, &WebPreferences::setShadowRootReferenceTargetEnabled },
        { "RequestIdleCallbackEnabled"_s, &WebPreferences::setRequestIdleCallbackEnabled },
        { "RequestStorageAccessThrowsExceptionUntilReload"_s, &WebPreferences::setRequestStorageAccessThrowsExceptionUntilReload },
        { "ScrollendEventEnabled"_s, &WebPreferences::setScrollendEventEnabled },
        { "CSSWordBreakAutoPhraseEnabled"_s, &WebPreferences::setCSSWordBreakAutoPhraseEnabled },
    };

    for (auto& setter : setters) {
        if (key == setter.name) {
            (this->*setter.function)(value);
            return;
        }
    }
}

void WebPreferences::enableAllExperimentalFeatures()
{
    UpdateBatch batch(*this);
    setTargetTextPseudoElementEnabled(true);
    setThumbAndTrackPseudoElementsEnabled(true);
    setLinkDNSPrefetchEnabled(true);
    setSelectShowPickerEnabled(true);
    setPageAtRuleMarginDescriptorsEnabled(true);
    setAccessHandleEnabled(true);
#if ENABLE(WEBGL)
    setAllowWebGLInWorkers(true);
#endif
    setAsyncClipboardAPIEnabled(true);
#if ENABLE(VIDEO)
    setExtendedAudioDescriptionsEnabled(true);
#endif
#if ENABLE(VIDEO)
    setAudioDescriptionsEnabled(true);
#endif
#if ENABLE(DOM_AUDIO_SESSION)
    setDOMAudioSessionEnabled(true);
#endif
#if ENABLE(DOM_AUDIO_SESSION)
    setDOMAudioSessionFullEnabled(true);
#endif
    setBeaconAPIEnabled(true);
    setBroadcastChannelEnabled(true);
    setCSS3DTransformBackfaceVisibilityInteroperabilityEnabled(true);
    setCSSCounterStyleAtRuleImageSymbolsEnabled(true);
    setAccentColorEnabled(true);
    setCSSAnchorPositioningEnabled(true);
    setCSSAnchorPositioningPositionVisibilityEnabled(true);
    setDevolvableWidgetsEnabled(true);
    setCSSInputSecurityEnabled(true);
    setMasonryEnabled(true);
    setOverscrollBehaviorEnabled(true);
    setCSSPaintingAPIEnabled(true);
    setCSSRhythmicSizingEnabled(true);
    setCSSScrollAnchoringEnabled(true);
    setCSSTreeCountingFunctionsEnabled(true);
    setCSSTypedOMColorEnabled(true);
    setCSSURLModifiersEnabled(true);
    setCSSURLIntegrityModifierEnabled(true);
    setCSSAppearanceBaseEnabled(true);
    setCSSAxisRelativePositionKeywordsEnabled(true);
    setCSSBackgroundClipBorderAreaEnabled(true);
    setCSSColorLayersEnabled(true);
    setCSSContrastColorEnabled(true);
    setCSSCornerShapeEnabled(true);
    setCSSDPropertyEnabled(true);
    setCSSDynamicRangeLimitMixEnabled(true);
    setCSSConstrainedDynamicRangeLimitEnabled(true);
    setCSSFieldSizingEnabled(true);
    setCSSFontVariantEmojiEnabled(true);
    setCSSLineClampEnabled(true);
    setCSSProgressFunctionEnabled(true);
    setCSSRandomFunctionEnabled(true);
    setCSSRubyAlignEnabled(true);
    setCSSRubyOverhangEnabled(true);
    setCSSScrollbarColorEnabled(true);
    setCSSScrollbarGutterEnabled(true);
    setCSSScrollbarWidthEnabled(true);
    setCSSShapeFunctionEnabled(true);
    setCSSTextAutospaceEnabled(true);
    setCSSTextBoxTrimEnabled(true);
    setCSSTextGroupAlignEnabled(true);
    setCSSTextJustifyEnabled(true);
    setCSSTextSpacingTrimEnabled(true);
    setCSSTextUnderlinePositionLeftRightEnabled(true);
    setCSSTextWrapPrettyEnabled(true);
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
    setCSSTransformStyleSeparatedEnabled(true);
#endif
    setCanvasColorSpaceEnabled(true);
    setCanvasFiltersEnabled(true);
    setCanvasLayersEnabled(true);
    setClearSiteDataHTTPHeaderEnabled(true);
    setClearSiteDataExecutionContextsSupportEnabled(true);
    setCloseWatcherEnabled(true);
    setInputTypeColorEnabled(true);
    setCompressionStreamEnabled(true);
    setContactPickerAPIEnabled(true);
    setCookieStoreManagerEnabled(true);
    setCookieStoreAPIExtendedAttributesEnabled(true);
    setCookieStoreAPIEnabled(true);
#if PLATFORM(MAC)
    setInputMethodUsesCorrectKeyEventOrder(true);
#endif
    setCrossDocumentViewTransitionsEnabled(true);
    setCrossOriginEmbedderPolicyEnabled(true);
    setCrossOriginOpenerPolicyEnabled(true);
    setMutationEventsEnabled(true);
    setDataListElementEnabled(true);
    setInputTypeDateEnabled(true);
#if ENABLE(DECLARATIVE_WEB_PUSH)
    setDeclarativeWebPush(true);
#endif
    setShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint(true);
    setDeprecationReportingEnabled(true);
    setUAVisualTransitionDetectionEnabled(true);
#if ENABLE(WEB_AUTHN)
    setDigitalCredentialsEnabled(true);
#endif
    setEmbedElementEnabled(true);
    setCanvasFingerprintingQuirkEnabled(true);
    setEnableElementCurrentCSSZoom(true);
#if ENABLE(MODEL_PROCESS)
    setModelProcessEnabled(true);
#endif
#if ENABLE(PDFJS)
    setPDFJSViewerEnabled(true);
#endif
    setAuxclickEventEnabled(true);
    setBackgroundFetchAPIEnabled(true);
#if HAVE(NETWORK_LOADER)
    setCFNetworkNetworkLoaderEnabled(true);
#endif
    setEventTimingEnabled(true);
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    setMediaSessionCoordinatorEnabled(true);
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
    setMediaSessionPlaylistEnabled(true);
#endif
    setFileSystemEnabled(true);
    setFileSystemWritableStreamEnabled(true);
    setFilterLinkDecorationByDefaultEnabled(true);
#if ENABLE(FULLSCREEN_API)
    setFullScreenKeyboardLock(true);
#endif
#if ENABLE(GPU_PROCESS) && !(PLATFORM(GTK) || PLATFORM(WPE))
    setUseGPUProcessForCanvasRenderingEnabled(true);
#endif
#if ENABLE(GPU_PROCESS)
    setUseGPUProcessForDOMRenderingEnabled(true);
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
    setUseGPUProcessForDisplayCapture(true);
#endif
#if ENABLE(GAMEPAD)
    setGamepadTriggerRumbleEnabled(true);
#endif
#if ENABLE(GAMEPAD)
    setGamepadVibrationActuatorEnabled(true);
#endif
#if ENABLE(VIDEO)
    setGenericCueAPIEnabled(true);
#endif
#if USE(GRAPHICS_CONTEXT_FILTERS)
    setGraphicsContextFiltersEnabled(true);
#endif
#if ENABLE(MODEL_ELEMENT)
    setModelDocumentEnabled(true);
#endif
    setInputTypeColorEnhancementsEnabled(true);
    setDetailsAutoExpandEnabled(true);
    setCommandAttributesEnabled(true);
    setPopoverAttributeEnabled(true);
    setSwitchControlEnabled(true);
    setHTTPSByDefaultEnabled(true);
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    setImageAnimationControlEnabled(true);
#endif
#if ENABLE(MEDIA_STREAM)
    setImageCaptureEnabled(true);
#endif
    setJavaScriptEnabled(true);
    setLazyIframeLoadingEnabled(true);
    setLazyImageLoadingEnabled(true);
    setLinkPreconnectEarlyHintsEnabled(true);
    setLinkPrefetchEnabled(true);
#if ENABLE(WEB_ARCHIVE)
    setLoadWebArchiveWithEphemeralStorageEnabled(true);
#endif
    setLocalStorageEnabled(true);
    setLockdownFontParserEnabled(true);
    setLoginStatusAPIEnabled(true);
#if ENABLE(MEDIA_SOURCE)
    setManagedMediaSourceEnabled(true);
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
    setManagedMediaSourceNeedsAirPlay(true);
#endif
    setMediaCapabilitiesExtensionsEnabled(true);
#if ENABLE(MEDIA_SESSION)
    setMediaSessionEnabled(true);
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    setMediaRecorderEnabledWebM(true);
#endif
#if ENABLE(MEDIA_RECORDER)
    setMediaRecorderEnabled(true);
#endif
    setMediaSessionCaptureToggleAPIEnabled(true);
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
    setMediaSourceInWorkerEnabled(true);
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
    setMediaSourcePrefersDecompressionSession(true);
#endif
#if ENABLE(MEDIA_STREAM)
    setMediaStreamTrackProcessingEnabled(true);
#endif
    setMetaViewportInteractiveWidgetEnabled(true);
    setNavigationAPIEnabled(true);
    setFlexFormattingContextIntegrationEnabled(true);
#if ENABLE(NOTIFICATIONS)
    setNotificationsEnabled(true);
#endif
    setObservableEnabled(true);
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
    setOffscreenCanvasInWorkersEnabled(true);
#endif
#if ENABLE(OFFSCREEN_CANVAS)
    setOffscreenCanvasEnabled(true);
#endif
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
    setOptInPartitionedCookiesEnabled(true);
#endif
    setOverlappingBackingStoreProvidersEnabled(true);
#if ENABLE(OVERLAY_REGIONS_IN_EVENT_REGION)
    setOverlayRegionsEnabled(true);
#endif
    setPermissionsAPIEnabled(true);
    setGetCoalescedEventsEnabled(true);
    setGetPredictedEventsEnabled(true);
#if ENABLE(POINTER_LOCK)
    setPointerLockOptionsEnabled(true);
#endif
    setPreferPageRenderingUpdatesNear60FPSEnabled(true);
#if ENABLE(FULLSCREEN_API)
    setVideoFullsceenPrefersMostVisibleHeuristic(true);
#endif
    setPrivateClickMeasurementFraudPreventionEnabled(true);
    setPrivateTokenUsageByThirdPartyEnabled(true);
#if ENABLE(DAMAGE_TRACKING)
    setPropagateDamagingInformation(true);
#endif
    setGoogleAntiFlickerOptimizationQuirkEnabled(true);
    setReadableByteStreamAPIEnabled(true);
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    setRemotePlaybackEnabled(true);
#endif
    setRemoteSnapshottingEnabled(true);
    setRequestVideoFrameCallbackEnabled(true);
    setScopedCustomElementRegistryEnabled(true);
    setScreenOrientationLockingAPIEnabled(true);
    setScreenOrientationAPIEnabled(true);
    setScreenWakeLockAPIEnabled(true);
#if ENABLE(MEDIA_STREAM)
    setScreenCaptureEnabled(true);
#endif
    setScrollToTextFragmentFeatureDetectionEnabled(true);
    setScrollToTextFragmentGenerationEnabled(true);
    setScrollToTextFragmentEnabled(true);
    setScrollDrivenAnimationsEnabled(true);
    setServiceWorkerInstallEventEnabled(true);
    setServiceWorkerNavigationPreloadEnabled(true);
    setServiceWorkersEnabled(true);
    setShapeDetection(true);
    setSharedWorkerEnabled(true);
    setSidewaysWritingModesEnabled(true);
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
    setSpatialImageControlsEnabled(true);
#endif
    setSpeechRecognitionEnabled(true);
    setStorageAPIEstimateEnabled(true);
    setStorageAPIEnabled(true);
    setSupportHDRCompositorTonemappingEnabled(true);
    setProcessSwapOnCrossSiteNavigationEnabled(true);
#if ENABLE(MEDIA_SOURCE)
    setTextTracksInMSEEnabled(true);
#endif
    setInputTypeTimeEnabled(true);
#if ENABLE(WEBXR)
    setTouchInputCompatibilityEnabled(true);
#endif
    setTrackConfigurationEnabled(true);
    setTrustedTypesEnabled(true);
    setURLPatternAPIEnabled(true);
#if ENABLE(UNIFIED_PDF)
    setUnifiedPDFEnabled(true);
#endif
    setIPAddressAndLocalhostMixedContentUpgradeTestingEnabled(true);
    setUpgradeMixedContentEnabled(true);
#if ENABLE(MEDIA_STREAM)
    setUseMicrophoneMuteStatusAPI(true);
#endif
#if ENABLE(DAMAGE_TRACKING)
    setUseDamagingInformationForCompositing(true);
#endif
    setUserActivationAPIEnabled(true);
    setVerifyWindowOpenUserGestureFromUIProcess(true);
    setVerticalFormControlsEnabled(true);
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    setVideoRendererProtectedFallbackDisabled(true);
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    setVideoRendererUseDecompressionSessionForProtected(true);
#endif
    setViewTransitionClassesEnabled(true);
    setViewTransitionTypesEnabled(true);
    setViewTransitionsEnabled(true);
    setVisualViewportAPIEnabled(true);
    setWebAnimationsOverallProgressPropertyEnabled(true);
    setWebAnimationsCustomEffectsEnabled(true);
    setWebAnimationsCustomFrameRateEnabled(true);
    setWebCryptoSafeCurvesEnabled(true);
    setWebCryptoX25519Enabled(true);
    setWebLocksAPIEnabled(true);
    setWebShareFileAPIEnabled(true);
#if ENABLE(WEBASSEMBLY)
    setWebAssemblyESMIntegrationEnabled(true);
#endif
#if ENABLE(WEB_CODECS)
    setWebCodecsAV1Enabled(true);
#endif
#if ENABLE(WEB_CODECS)
    setWebCodecsAudioEnabled(true);
#endif
#if ENABLE(WEB_CODECS)
    setWebCodecsHEVCEnabled(true);
#endif
#if ENABLE(WEB_CODECS)
    setWebCodecsVideoEnabled(true);
#endif
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    setWebExtensionBookmarksEnabled(true);
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    setWebExtensionSidebarEnabled(true);
#endif
    setWebGLDraftExtensionsEnabled(true);
    setWebGLEnabled(true);
#if ENABLE(WEB_RTC)
    setWebRTCAV1CodecEnabled(true);
#endif
#if ENABLE(WEB_RTC)
    setWebRTCEncodedTransformEnabled(true);
#endif
#if ENABLE(WEB_RTC)
    setWebRTCH265CodecEnabled(true);
#endif
#if ENABLE(WEB_RTC)
    setWebRTCL4SEnabled(true);
#endif
#if ENABLE(WEB_RTC)
    setWebRTCSFrameTransformEnabled(true);
#endif
#if ENABLE(WEB_RTC)
    setWebRTCVP9Profile2CodecEnabled(true);
#endif
    setWebTransportEnabled(true);
#if ENABLE(WEBXR)
    setWebXRAugmentedRealityModuleEnabled(true);
#endif
#if ENABLE(WEBXR)
    setWebXREnabled(true);
#endif
#if ENABLE(WEBXR)
    setWebXRGamepadsModuleEnabled(true);
#endif
#if ENABLE(WEBXR_HANDS)
    setWebXRHandInputModuleEnabled(true);
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    setWebPageSpatialBackdropEnabled(true);
#endif
    setWheelEventGesturesBecomeNonBlocking(true);
    setWorkerAsynchronousURLErrorHandlingEnabled(true);
#if ENABLE(WRITING_SUGGESTIONS)
    setWritingSuggestionsAttributeEnabled(true);
#endif
    setAltitudeAngleEnabled(true);
    setAzimuthAngleEnabled(true);
    setInputTypeDateTimeLocalEnabled(true);
    setCaretPositionFromPointEnabled(true);
    setHiddenUntilFoundEnabled(true);
    setHTTPEquivEnabled(true);
    setShadowRootReferenceTargetEnabledForAriaOwns(true);
    setShadowRootReferenceTargetEnabled(true);
    setRequestIdleCallbackEnabled(true);
    setScrollendEventEnabled(true);
    setCSSWordBreakAutoPhraseEnabled(true);
}

void WebPreferences::resetAllInternalDebugFeatures()
{
    UpdateBatch batch(*this);
#if HAVE(AVKIT_CONTENT_SOURCE)
    setAVKitContentSourceEnabled(DEFAULT_VALUE_FOR_AVKitContentSourceEnabled);
#endif
#if USE(CORE_IMAGE)
    setAcceleratedFiltersEnabled(DEFAULT_VALUE_FOR_AcceleratedFiltersEnabled);
#endif
    setDOMTestingAPIsEnabled(DEFAULT_VALUE_FOR_DOMTestingAPIsEnabled);
#if PLATFORM(IOS_FAMILY)
    setAllowViewportShrinkToFitContent(DEFAULT_VALUE_FOR_AllowViewportShrinkToFitContent);
#endif
#if ENABLE(MEDIA_STREAM)
    setPerElementSpeakerSelectionEnabled(DEFAULT_VALUE_FOR_PerElementSpeakerSelectionEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    setExposeSpeakersWithoutMicrophoneEnabled(DEFAULT_VALUE_FOR_ExposeSpeakersWithoutMicrophoneEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    setExposeSpeakersEnabled(DEFAULT_VALUE_FOR_ExposeSpeakersEnabled);
#endif
#if ENABLE(WEB_ARCHIVE)
    setAlwaysAllowLocalWebarchive(DEFAULT_VALUE_FOR_AlwaysAllowLocalWebarchive);
#endif
#if ENABLE(VP9)
    setSWVPDecodersAlwaysEnabled(DEFAULT_VALUE_FOR_SWVPDecodersAlwaysEnabled);
#endif
    setAppBadgeEnabled(DEFAULT_VALUE_FOR_AppBadgeEnabled);
#if ENABLE(APP_HIGHLIGHTS)
    setAppHighlightsEnabled(DEFAULT_VALUE_FOR_AppHighlightsEnabled);
#endif
    setAsyncFrameScrollingEnabled(DEFAULT_VALUE_FOR_AsyncFrameScrollingEnabled);
    setAsyncOverflowScrollingEnabled(DEFAULT_VALUE_FOR_AsyncOverflowScrollingEnabled);
#if PLATFORM(IOS_FAMILY)
    setUseAsyncUIKitInteractions(DEFAULT_VALUE_FOR_UseAsyncUIKitInteractions);
#endif
    setAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth(DEFAULT_VALUE_FOR_AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth);
    setBidiContentAwarePasteEnabled(DEFAULT_VALUE_FOR_BidiContentAwarePasteEnabled);
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
    setBlockFontServiceInWebContentSandbox(DEFAULT_VALUE_FOR_BlockFontServiceInWebContentSandbox);
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
    setBlockIconServicesInWebContentSandbox(DEFAULT_VALUE_FOR_BlockIconServicesInWebContentSandbox);
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
    setBlockMobileAssetInWebContentSandbox(DEFAULT_VALUE_FOR_BlockMobileAssetInWebContentSandbox);
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(IOS)
    setBlockMobileGestaltInWebContentSandbox(DEFAULT_VALUE_FOR_BlockMobileGestaltInWebContentSandbox);
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
    setBlockOpenDirectoryInWebContentSandbox(DEFAULT_VALUE_FOR_BlockOpenDirectoryInWebContentSandbox);
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
    setBlockWebInspectorInWebContentSandbox(DEFAULT_VALUE_FOR_BlockWebInspectorInWebContentSandbox);
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    setBuiltInNotificationsEnabled(DEFAULT_VALUE_FOR_BuiltInNotificationsEnabled);
#endif
    setSpringTimingFunctionEnabled(DEFAULT_VALUE_FOR_SpringTimingFunctionEnabled);
    setCSSLineFitEdgeEnabled(DEFAULT_VALUE_FOR_CSSLineFitEdgeEnabled);
    setCanvasPixelFormatEnabled(DEFAULT_VALUE_FOR_CanvasPixelFormatEnabled);
    setChildProcessDebuggabilityEnabled(DEFAULT_VALUE_FOR_ChildProcessDebuggabilityEnabled);
    setCompositingBordersVisible(DEFAULT_VALUE_FOR_CompositingBordersVisible);
    setCompositingRepaintCountersVisible(DEFAULT_VALUE_FOR_CompositingRepaintCountersVisible);
    setContentInsetBackgroundFillEnabled(DEFAULT_VALUE_FOR_ContentInsetBackgroundFillEnabled);
    setCookieConsentAPIEnabled(DEFAULT_VALUE_FOR_CookieConsentAPIEnabled);
    setDOMPasteAccessRequestsEnabled(DEFAULT_VALUE_FOR_DOMPasteAccessRequestsEnabled);
#if PLATFORM(IOS_FAMILY)
    setZoomOnDoubleTapWhenRoot(DEFAULT_VALUE_FOR_ZoomOnDoubleTapWhenRoot);
#endif
#if PLATFORM(IOS_FAMILY)
    setAlwaysZoomOnDoubleTap(DEFAULT_VALUE_FOR_AlwaysZoomOnDoubleTap);
#endif
#if PLATFORM(IOS_FAMILY)
    setDisableScreenSizeOverride(DEFAULT_VALUE_FOR_DisableScreenSizeOverride);
#endif
    setShouldDropNearSuspendedAssertionAfterDelay(DEFAULT_VALUE_FOR_ShouldDropNearSuspendedAssertionAfterDelay);
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
    setUseCGDisplayListsForDOMRendering(DEFAULT_VALUE_FOR_UseCGDisplayListsForDOMRendering);
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
    setReplayCGDisplayListsIntoBackingStore(DEFAULT_VALUE_FOR_ReplayCGDisplayListsIntoBackingStore);
#endif
    setDynamicSiteInterventionsEnabled(DEFAULT_VALUE_FOR_DynamicSiteInterventionsEnabled);
#if PLATFORM(MAC)
    setEnableAccessibilityOnDemand(DEFAULT_VALUE_FOR_EnableAccessibilityOnDemand);
#endif
#if PLATFORM(IOS_FAMILY)
    setAutomaticLiveResizeEnabled(DEFAULT_VALUE_FOR_AutomaticLiveResizeEnabled);
#endif
    setEnumeratingAllNetworkInterfacesEnabled(DEFAULT_VALUE_FOR_EnumeratingAllNetworkInterfacesEnabled);
    setEnumeratingVisibleNetworkInterfacesEnabled(DEFAULT_VALUE_FOR_EnumeratingVisibleNetworkInterfacesEnabled);
    setICECandidateFilteringEnabled(DEFAULT_VALUE_FOR_ICECandidateFilteringEnabled);
#if ENABLE(MEDIA_STREAM)
    setMockCaptureDevicesEnabled(DEFAULT_VALUE_FOR_MockCaptureDevicesEnabled);
#endif
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
    setBackgroundWebContentRunningBoardThrottlingEnabled(DEFAULT_VALUE_FOR_BackgroundWebContentRunningBoardThrottlingEnabled);
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
    setEnableDebuggingFeaturesInSandbox(DEFAULT_VALUE_FOR_EnableDebuggingFeaturesInSandbox);
#endif
#if HAVE(MACH_BOOTSTRAP_EXTENSION) || HAVE(SANDBOX_STATE_FLAGS)
    setExperimentalSandboxEnabled(DEFAULT_VALUE_FOR_ExperimentalSandboxEnabled);
#endif
    setNavigatorUserAgentDataJavaScriptAPIEnabled(DEFAULT_VALUE_FOR_NavigatorUserAgentDataJavaScriptAPIEnabled);
    setEnterKeyHintEnabled(DEFAULT_VALUE_FOR_EnterKeyHintEnabled);
    setEventHandlerDrivenSmoothKeyboardScrollingEnabled(DEFAULT_VALUE_FOR_EventHandlerDrivenSmoothKeyboardScrollingEnabled);
#if ENABLE(MEDIA_STREAM)
    setExposeCaptureDevicesAfterCaptureEnabled(DEFAULT_VALUE_FOR_ExposeCaptureDevicesAfterCaptureEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    setExposeDefaultSpeakerAsSpecificDeviceEnabled(DEFAULT_VALUE_FOR_ExposeDefaultSpeakerAsSpecificDeviceEnabled);
#endif
#if PLATFORM(IOS_FAMILY)
    setPreferFasterClickOverDoubleTap(DEFAULT_VALUE_FOR_PreferFasterClickOverDoubleTap);
#endif
#if PLATFORM(IOS_FAMILY)
    setFasterClicksEnabled(DEFAULT_VALUE_FOR_FasterClicksEnabled);
#endif
    setForceLockdownFontParserEnabled(DEFAULT_VALUE_FOR_ForceLockdownFontParserEnabled);
#if PLATFORM(IOS_FAMILY)
    setForceAlwaysUserScalable(DEFAULT_VALUE_FOR_ForceAlwaysUserScalable);
#endif
#if ENABLE(FORM_CONTROL_REFRESH)
    setFormControlRefreshEnabled(DEFAULT_VALUE_FOR_FormControlRefreshEnabled);
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    setIFrameResourceMonitoringTestingSettingsEnabled(DEFAULT_VALUE_FOR_IFrameResourceMonitoringTestingSettingsEnabled);
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    setIFrameResourceMonitoringEnabled(DEFAULT_VALUE_FOR_IFrameResourceMonitoringEnabled);
#endif
#if PLATFORM(VISION)
    setFullscreenSceneAspectRatioLockingEnabled(DEFAULT_VALUE_FOR_FullscreenSceneAspectRatioLockingEnabled);
#endif
#if PLATFORM(VISION)
    setFullscreenSceneDimmingEnabled(DEFAULT_VALUE_FOR_FullscreenSceneDimmingEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    setCaptureAudioInGPUProcessEnabled(DEFAULT_VALUE_FOR_CaptureAudioInGPUProcessEnabled);
#endif
#if ENABLE(GPU_PROCESS)
    setBlockMediaLayerRehostingInWebContentProcess(DEFAULT_VALUE_FOR_BlockMediaLayerRehostingInWebContentProcess);
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
    setManageCaptureStatusBarInGPUProcessEnabled(DEFAULT_VALUE_FOR_ManageCaptureStatusBarInGPUProcessEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    setCaptureVideoInGPUProcessEnabled(DEFAULT_VALUE_FOR_CaptureVideoInGPUProcessEnabled);
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
    setUseGPUProcessForWebGLEnabled(DEFAULT_VALUE_FOR_UseGPUProcessForWebGLEnabled);
#endif
    setAcceleratedDrawingEnabled(DEFAULT_VALUE_FOR_AcceleratedDrawingEnabled);
    setHTMLLegacyAttributeValueSerializationEnabled(DEFAULT_VALUE_FOR_HTMLLegacyAttributeValueSerializationEnabled);
#if HAVE(MATERIAL_HOSTING)
    setHostedBlurMaterialInMediaControlsEnabled(DEFAULT_VALUE_FOR_HostedBlurMaterialInMediaControlsEnabled);
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
    setBlockIOKitInWebContentSandbox(DEFAULT_VALUE_FOR_BlockIOKitInWebContentSandbox);
#endif
    setIOSurfaceLosslessCompressionEnabled(DEFAULT_VALUE_FOR_IOSurfaceLosslessCompressionEnabled);
#if ENABLE(IPC_TESTING_API)
    setIPCTestingAPIEnabled(DEFAULT_VALUE_FOR_IPCTestingAPIEnabled);
#endif
#if ENABLE(IPC_TESTING_API)
    setIgnoreInvalidMessageWhenIPCTestingAPIEnabled(DEFAULT_VALUE_FOR_IgnoreInvalidMessageWhenIPCTestingAPIEnabled);
#endif
    setIgnoreIframeEmbeddingProtectionsEnabled(DEFAULT_VALUE_FOR_IgnoreIframeEmbeddingProtectionsEnabled);
#if ENABLE(IMAGE_ANALYSIS)
    setImageAnalysisDuringFindInPageEnabled(DEFAULT_VALUE_FOR_ImageAnalysisDuringFindInPageEnabled);
#endif
#if ENABLE(SERVICE_CONTROLS)
    setImageControlsEnabled(DEFAULT_VALUE_FOR_ImageControlsEnabled);
#endif
    setInWindowFullscreenEnabled(DEFAULT_VALUE_FOR_InWindowFullscreenEnabled);
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
    setIncludeIgnoredInCoreAXTree(DEFAULT_VALUE_FOR_IncludeIgnoredInCoreAXTree);
#endif
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    setInteractionRegionsEnabled(DEFAULT_VALUE_FOR_InteractionRegionsEnabled);
#endif
#if PLATFORM(IOS_FAMILY)
    setKeyboardDismissalGestureEnabled(DEFAULT_VALUE_FOR_KeyboardDismissalGestureEnabled);
#endif
    setLayerBasedSVGEngineEnabled(DEFAULT_VALUE_FOR_LayerBasedSVGEngineEnabled);
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
    setLegacyOverflowScrollingTouchEnabled(DEFAULT_VALUE_FOR_LegacyOverflowScrollingTouchEnabled);
#endif
    setLegacyLineLayoutVisualCoverageEnabled(DEFAULT_VALUE_FOR_LegacyLineLayoutVisualCoverageEnabled);
#if ENABLE(MEDIA_STREAM)
    setMediaCaptureRequiresSecureConnection(DEFAULT_VALUE_FOR_MediaCaptureRequiresSecureConnection);
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
    setLinearMediaPlayerEnabled(DEFAULT_VALUE_FOR_LinearMediaPlayerEnabled);
#endif
    setLinkSanitizerEnabled(DEFAULT_VALUE_FOR_LinkSanitizerEnabled);
    setLocalFileContentSniffingEnabled(DEFAULT_VALUE_FOR_LocalFileContentSniffingEnabled);
    setLocalNetworkAccessEnabled(DEFAULT_VALUE_FOR_LocalNetworkAccessEnabled);
    setLogsPageMessagesToSystemConsoleEnabled(DEFAULT_VALUE_FOR_LogsPageMessagesToSystemConsoleEnabled);
    setCoreMathMLEnabled(DEFAULT_VALUE_FOR_CoreMathMLEnabled);
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    setModelNoPortalAttributeEnabled(DEFAULT_VALUE_FOR_ModelNoPortalAttributeEnabled);
#endif
#if USE(MODERN_AVCONTENTKEYSESSION)
    setShouldUseModernAVContentKeySession(DEFAULT_VALUE_FOR_ShouldUseModernAVContentKeySession);
#endif
    setMomentumScrollingAnimatorEnabled(DEFAULT_VALUE_FOR_MomentumScrollingAnimatorEnabled);
#if ENABLE(TOUCH_EVENTS)
    setMouseEventsSimulationEnabled(DEFAULT_VALUE_FOR_MouseEventsSimulationEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    setMuteCameraOnMicrophoneInterruptionEnabled(DEFAULT_VALUE_FOR_MuteCameraOnMicrophoneInterruptionEnabled);
#endif
#if ENABLE(APP_BOUND_DOMAINS)
    setNeedsInAppBrowserPrivacyQuirks(DEFAULT_VALUE_FOR_NeedsInAppBrowserPrivacyQuirks);
#endif
#if ENABLE(NOTIFICATION_EVENT)
    setNotificationEventEnabled(DEFAULT_VALUE_FOR_NotificationEventEnabled);
#endif
    setOpportunisticSweepingAndGarbageCollectionEnabled(DEFAULT_VALUE_FOR_OpportunisticSweepingAndGarbageCollectionEnabled);
    setPageVisibilityBasedProcessSuppressionEnabled(DEFAULT_VALUE_FOR_PageVisibilityBasedProcessSuppressionEnabled);
#if HAVE(PHOTOS_UI)
    setPhotoPickerPrefersOriginalImageFormat(DEFAULT_VALUE_FOR_PhotoPickerPrefersOriginalImageFormat);
#endif
#if HAVE(PIP_SKIP_PREROLL)
    setPictureInPicturePlaybackStateEnabled(DEFAULT_VALUE_FOR_PictureInPicturePlaybackStateEnabled);
#endif
#if ENABLE(POINTER_LOCK)
    setPointerLockEnabled(DEFAULT_VALUE_FOR_PointerLockEnabled);
#endif
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    setPreferSpatialAudioExperience(DEFAULT_VALUE_FOR_PreferSpatialAudioExperience);
#endif
    setLegacyPluginQuirkForMailSignaturesEnabled(DEFAULT_VALUE_FOR_LegacyPluginQuirkForMailSignaturesEnabled);
    setRemoteMediaSessionManagerEnabled(DEFAULT_VALUE_FOR_RemoteMediaSessionManagerEnabled);
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    setRemoveBackgroundEnabled(DEFAULT_VALUE_FOR_RemoveBackgroundEnabled);
#endif
#if HAVE(SC_CONTENT_SHARING_PICKER)
    setRequireUAGetDisplayMediaPrompt(DEFAULT_VALUE_FOR_RequireUAGetDisplayMediaPrompt);
#endif
    setLoginStatusAPIRequiresWebAuthnEnabled(DEFAULT_VALUE_FOR_LoginStatusAPIRequiresWebAuthnEnabled);
#if ENABLE(MEDIA_STREAM)
    setSpeakerSelectionRequiresUserGesture(DEFAULT_VALUE_FOR_SpeakerSelectionRequiresUserGesture);
#endif
#if ENABLE(MEDIA_STREAM)
    setGetUserMediaRequiresFocus(DEFAULT_VALUE_FOR_GetUserMediaRequiresFocus);
#endif
    setResourceLoadSchedulingEnabled(DEFAULT_VALUE_FOR_ResourceLoadSchedulingEnabled);
#if ENABLE(RESOURCE_USAGE)
    setResourceUsageOverlayVisible(DEFAULT_VALUE_FOR_ResourceUsageOverlayVisible);
#endif
    setRespondToThermalPressureAggressively(DEFAULT_VALUE_FOR_RespondToThermalPressureAggressively);
    setIsSameSiteStrictEnforcementEnabled(DEFAULT_VALUE_FOR_IsSameSiteStrictEnforcementEnabled);
#if ENABLE(SCREEN_TIME)
    setScreenTimeEnabled(DEFAULT_VALUE_FOR_ScreenTimeEnabled);
#endif
    setScriptTrackingPrivacyLoggingEnabled(DEFAULT_VALUE_FOR_ScriptTrackingPrivacyLoggingEnabled);
    setScriptTrackingPrivacyProtectionsEnabled(DEFAULT_VALUE_FOR_ScriptTrackingPrivacyProtectionsEnabled);
    setScrollingPerformanceTestingEnabled(DEFAULT_VALUE_FOR_ScrollingPerformanceTestingEnabled);
    setSecureContextChecksEnabled(DEFAULT_VALUE_FOR_SecureContextChecksEnabled);
#if PLATFORM(IOS_FAMILY)
    setSelectionHonorsOverflowScrolling(DEFAULT_VALUE_FOR_SelectionHonorsOverflowScrolling);
#endif
    setSiteIsolationSharedProcessEnabled(DEFAULT_VALUE_FOR_SiteIsolationSharedProcessEnabled);
    setShowFrameProcessBordersEnabled(DEFAULT_VALUE_FOR_ShowFrameProcessBordersEnabled);
    setSiteIsolationEnabled(DEFAULT_VALUE_FOR_SiteIsolationEnabled);
    setShouldTakeNearSuspendedAssertions(DEFAULT_VALUE_FOR_ShouldTakeNearSuspendedAssertions);
#if ENABLE(WRITING_TOOLS)
    setTextAnimationsEnabled(DEFAULT_VALUE_FOR_TextAnimationsEnabled);
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    setTextRecognitionInVideosEnabled(DEFAULT_VALUE_FOR_TextRecognitionInVideosEnabled);
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
    setThreadedAnimationResolutionEnabled(DEFAULT_VALUE_FOR_ThreadedAnimationResolutionEnabled);
#endif
    setTiledScrollingIndicatorVisible(DEFAULT_VALUE_FOR_TiledScrollingIndicatorVisible);
    setTopContentInsetBackgroundCanChangeAfterScrolling(DEFAULT_VALUE_FOR_TopContentInsetBackgroundCanChangeAfterScrolling);
    setUndoManagerAPIEnabled(DEFAULT_VALUE_FOR_UndoManagerAPIEnabled);
#if ENABLE(DAMAGE_TRACKING)
    setUnifyDamagedRegions(DEFAULT_VALUE_FOR_UnifyDamagedRegions);
#endif
    setUpgradeKnownHostsToHTTPSEnabled(DEFAULT_VALUE_FOR_UpgradeKnownHostsToHTTPSEnabled);
#if ENABLE(ARKIT_INLINE_PREVIEW)
    setUseARKitForModel(DEFAULT_VALUE_FOR_UseARKitForModel);
#endif
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
    setUseAVCaptureDeviceRotationCoordinatorAPI(DEFAULT_VALUE_FOR_UseAVCaptureDeviceRotationCoordinatorAPI);
#endif
    setUseIFCForSVGText(DEFAULT_VALUE_FOR_UseIFCForSVGText);
#if HAVE(SCENEKIT)
    setUseSceneKitForModel(DEFAULT_VALUE_FOR_UseSceneKitForModel);
#endif
    setUserGesturePromisePropagationEnabled(DEFAULT_VALUE_FOR_UserGesturePromisePropagationEnabled);
#if HAVE(WEBCONTENTRESTRICTIONS)
    setUsesWebContentRestrictionsForFilter(DEFAULT_VALUE_FOR_UsesWebContentRestrictionsForFilter);
#endif
    setServiceWorkersUserGestureEnabled(DEFAULT_VALUE_FOR_ServiceWorkersUserGestureEnabled);
#if ENABLE(IMAGE_ANALYSIS)
    setVisualTranslationEnabled(DEFAULT_VALUE_FOR_VisualTranslationEnabled);
#endif
#if PLATFORM(IOS_FAMILY)
    setVisuallyContiguousBidiTextSelectionEnabled(DEFAULT_VALUE_FOR_VisuallyContiguousBidiTextSelectionEnabled);
#endif
    setWebAPIStatisticsEnabled(DEFAULT_VALUE_FOR_WebAPIStatisticsEnabled);
    setWebAPIsInShadowRealmEnabled(DEFAULT_VALUE_FOR_WebAPIsInShadowRealmEnabled);
#if ENABLE(WEB_ARCHIVE)
    setWebArchiveTestingModeEnabled(DEFAULT_VALUE_FOR_WebArchiveTestingModeEnabled);
#endif
    setWebInspectorEngineeringSettingsAllowed(DEFAULT_VALUE_FOR_WebInspectorEngineeringSettingsAllowed);
    setWebRTCAudioLatencyAdaptationEnabled(DEFAULT_VALUE_FOR_WebRTCAudioLatencyAdaptationEnabled);
#if ENABLE(WEB_RTC)
    setWebRTCDTMFEnabled(DEFAULT_VALUE_FOR_WebRTCDTMFEnabled);
#endif
#if ENABLE(WEB_RTC)
    setWebRTCH264HardwareEncoderEnabled(DEFAULT_VALUE_FOR_WebRTCH264HardwareEncoderEnabled);
#endif
    setWebRTCMediaPipelineAdditionalLoggingEnabled(DEFAULT_VALUE_FOR_WebRTCMediaPipelineAdditionalLoggingEnabled);
#if ENABLE(WEB_RTC)
    setWebRTCRemoteVideoFrameEnabled(DEFAULT_VALUE_FOR_WebRTCRemoteVideoFrameEnabled);
#endif
#if ENABLE(WEB_RTC)
    setWebRTCSocketsProxyingEnabled(DEFAULT_VALUE_FOR_WebRTCSocketsProxyingEnabled);
#endif
#if ENABLE(WEB_RTC)
    setWebRTCVP9Profile0CodecEnabled(DEFAULT_VALUE_FOR_WebRTCVP9Profile0CodecEnabled);
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
    setWebRTCInterfaceMonitoringViaNWEnabled(DEFAULT_VALUE_FOR_WebRTCInterfaceMonitoringViaNWEnabled);
#endif
#if PLATFORM(COCOA)
    setWriteRichTextDataWhenCopyingOrDragging(DEFAULT_VALUE_FOR_WriteRichTextDataWhenCopyingOrDragging);
#endif
#if ENABLE(XSLT)
    setXSLTEnabled(DEFAULT_VALUE_FOR_XSLTEnabled);
#endif
    setRequestStorageAccessThrowsExceptionUntilReload(DEFAULT_VALUE_FOR_RequestStorageAccessThrowsExceptionUntilReload);
}

void WebPreferences::disableRichJavaScriptFeatures()
{
    UpdateBatch batch(*this);
#if ENABLE(APPLE_PAY)
    setApplePayEnabled(false);
#endif
#if ENABLE(WEB_AUDIO)
    setWebAudioEnabled(false);
#endif
#if ENABLE(DEVICE_ORIENTATION)
    setDeviceOrientationEventEnabled(false);
#endif
    setAppBadgeEnabled(false);
#if ENABLE(WEB_AUTHN)
    setDigitalCredentialsEnabled(false);
#endif
#if ENABLE(GAMEPAD)
    setGamepadsEnabled(false);
#endif
    setGeolocationAPIEnabled(false);
#if ENABLE(NOTIFICATIONS)
    setNotificationsEnabled(false);
#endif
    setScreenOrientationAPIEnabled(false);
    setShapeDetection(false);
    setSpeechRecognitionEnabled(false);
    setSpeechSynthesisAPIEnabled(false);
    setWebLocksAPIEnabled(false);
    setWebShareEnabled(false);
#if ENABLE(WEB_CODECS)
    setWebCodecsVideoEnabled(false);
#endif
    setWebGLEnabled(false);
    setWebGPUEnabled(false);
#if ENABLE(WEB_RTC)
    setPeerConnectionEnabled(false);
#endif
}

void WebPreferences::disableMediaPlaybackRelatedFeatures()
{
    UpdateBatch batch(*this);
#if ENABLE(WEB_AUDIO)
    setWebAudioEnabled(false);
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
    setMediaControlsContextMenusEnabled(false);
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    setEncryptedMediaAPIEnabled(false);
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    setLegacyEncryptedMediaAPIEnabled(false);
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    setMediaSessionCoordinatorEnabled(false);
#endif
#if ENABLE(GPU_PROCESS)
    setUseGPUProcessForMediaEnabled(false);
#endif
#if ENABLE(MEDIA_SOURCE)
    setManagedMediaSourceEnabled(false);
#endif
    setMediaPlaybackEnabled(false);
    setMediaSourceEnabled(false);
#if ENABLE(MEDIA_RECORDER)
    setMediaRecorderEnabled(false);
#endif
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
    setMediaSourceInWorkerEnabled(false);
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    setTextRecognitionInVideosEnabled(false);
#endif
#if ENABLE(WEB_CODECS)
    setWebCodecsVideoEnabled(false);
#endif
#if ENABLE(WEB_RTC)
    setPeerConnectionEnabled(false);
#endif
}

}
