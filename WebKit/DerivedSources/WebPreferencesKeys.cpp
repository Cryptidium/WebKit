/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2017 Apple Inc. All rights reserved.
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
#include "WebPreferencesKeys.h"

#include <wtf/NeverDestroyed.h>

namespace WebKit {
namespace WebPreferencesKey {

const String& databasesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DatabasesEnabled"));
    return key;
}

const String& loadDeferringEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LoadDeferringEnabled"));
    return key;
}

const String& acceleratedCompositingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AcceleratedCompositingEnabled"));
    return key;
}

const String& acceleratedCompositingForFixedPositionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AcceleratedCompositingForFixedPositionEnabled"));
    return key;
}

const String& wirelessPlaybackTargetAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WirelessPlaybackTargetAPIEnabled"));
    return key;
}

const String& loadsImagesAutomaticallyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LoadsImagesAutomatically"));
    return key;
}

const String& linkPreconnectKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LinkPreconnect"));
    return key;
}

const String& longRunningMediaCaptureStreamRepromptIntervalInHoursKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LongRunningMediaCaptureStreamRepromptIntervalInHours"));
    return key;
}

const String& windowFocusRestrictedKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WindowFocusRestricted"));
    return key;
}

const String& aggressiveTileRetentionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AggressiveTileRetentionEnabled"));
    return key;
}

const String& allowContentSecurityPolicySourceStarToMatchAnyProtocolKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowContentSecurityPolicySourceStarToMatchAnyProtocol"));
    return key;
}

const String& allowDisplayOfInsecureContentKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowDisplayOfInsecureContent"));
    return key;
}

const String& allowFileAccessFromFileURLsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowFileAccessFromFileURLs"));
    return key;
}

const String& lowPowerVideoAudioBufferSizeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LowPowerVideoAudioBufferSizeEnabled"));
    return key;
}

const String& allowMultiElementImplicitSubmissionKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowMultiElementImplicitSubmission"));
    return key;
}

const String& managedMediaSourceHighThresholdKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ManagedMediaSourceHighThreshold"));
    return key;
}

const String& allowRunningOfInsecureContentKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowRunningOfInsecureContent"));
    return key;
}

const String& allowTestOnlyIPCKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowTestOnlyIPC"));
    return key;
}

const String& managedMediaSourceLowThresholdKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ManagedMediaSourceLowThreshold"));
    return key;
}

const String& mathMLEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MathMLEnabled"));
    return key;
}

const String& maxParseDurationKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MaxParseDuration"));
    return key;
}

const String& mediaAudioCodecIDsAllowedInLockdownModeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaAudioCodecIDsAllowedInLockdownMode"));
    return key;
}

const String& allowsAirPlayForMediaPlaybackKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowsAirPlayForMediaPlayback"));
    return key;
}

const String& allowsInlineMediaPlaybackKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowsInlineMediaPlayback"));
    return key;
}

const String& allowsInlineMediaPlaybackAfterFullscreenKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowsInlineMediaPlaybackAfterFullscreen"));
    return key;
}

const String& allowsPictureInPictureMediaPlaybackKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowsPictureInPictureMediaPlayback"));
    return key;
}

const String& alternateFullScreenControlDesignEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AlternateFullScreenControlDesignEnabled"));
    return key;
}

const String& webSocketEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebSocketEnabled"));
    return key;
}

const String& mediaCapabilitiesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaCapabilitiesEnabled"));
    return key;
}

const String& webSecurityEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebSecurityEnabled"));
    return key;
}

const String& animatedImageAsyncDecodingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AnimatedImageAsyncDecodingEnabled"));
    return key;
}

const String& layoutViewportHeightExpansionFactorKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LayoutViewportHeightExpansionFactor"));
    return key;
}

const String& layoutFallbackWidthKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LayoutFallbackWidth"));
    return key;
}

const String& appleMailPaginationQuirkEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AppleMailPaginationQuirkEnabled"));
    return key;
}

const String& applePayCapabilityDisclosureAllowedKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ApplePayCapabilityDisclosureAllowed"));
    return key;
}

const String& applePayEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ApplePayEnabled"));
    return key;
}

const String& largeImageAsyncDecodingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LargeImageAsyncDecodingEnabled"));
    return key;
}

const String& mediaCaptionFormatTypesAllowedInLockdownModeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaCaptionFormatTypesAllowedInLockdownMode"));
    return key;
}

const String& javaScriptRuntimeFlagsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("JavaScriptRuntimeFlags"));
    return key;
}

const String& asynchronousSpellCheckingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AsynchronousSpellCheckingEnabled"));
    return key;
}

const String& javaScriptMarkupEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("JavaScriptMarkupEnabled"));
    return key;
}

const String& mediaCodecTypesAllowedInLockdownModeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaCodecTypesAllowedInLockdownMode"));
    return key;
}

const String& audioControlsScaleWithPageZoomKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AudioControlsScaleWithPageZoom"));
    return key;
}

const String& javaScriptCanOpenWindowsAutomaticallyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("JavaScriptCanOpenWindowsAutomatically"));
    return key;
}

const String& authorAndUserStylesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AuthorAndUserStylesEnabled"));
    return key;
}

const String& webAudioEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAudioEnabled"));
    return key;
}

const String& javaScriptCanAccessClipboardKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("JavaScriptCanAccessClipboard"));
    return key;
}

const String& wantsBalancedSetDefersLoadingBehaviorKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WantsBalancedSetDefersLoadingBehavior"));
    return key;
}

const String& visualViewportEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VisualViewportEnabled"));
    return key;
}

const String& visibleDebugOverlayRegionsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VisibleDebugOverlayRegions"));
    return key;
}

const String& videoQualityIncludesDisplayCompositingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VideoQualityIncludesDisplayCompositingEnabled"));
    return key;
}

const String& backspaceKeyNavigationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BackspaceKeyNavigationEnabled"));
    return key;
}

const String& mediaContainerTypesAllowedInLockdownModeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaContainerTypesAllowedInLockdownMode"));
    return key;
}

const String& mediaContentTypesRequiringHardwareSupportKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaContentTypesRequiringHardwareSupport"));
    return key;
}

const String& videoPresentationModeAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VideoPresentationModeAPIEnabled"));
    return key;
}

const String& mediaControlsContextMenusEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaControlsContextMenusEnabled"));
    return key;
}

const String& videoPresentationManagerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VideoPresentationManagerEnabled"));
    return key;
}

const String& mediaControlsScaleWithPageZoomKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaControlsScaleWithPageZoom"));
    return key;
}

const String& videoFullscreenRequiresElementFullscreenKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VideoFullscreenRequiresElementFullscreen"));
    return key;
}

const String& mediaDataLoadsAutomaticallyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaDataLoadsAutomatically"));
    return key;
}

const String& mediaPreferredFullscreenWidthKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaPreferredFullscreenWidth"));
    return key;
}

const String& mediaPreloadingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaPreloadingEnabled"));
    return key;
}

const String& invisibleAutoplayNotPermittedKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InvisibleAutoplayNotPermitted"));
    return key;
}

const String& interruptVideoOnPageVisibilityChangeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InterruptVideoOnPageVisibilityChangeEnabled"));
    return key;
}

const String& interruptAudioOnPageVisibilityChangeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InterruptAudioOnPageVisibilityChangeEnabled"));
    return key;
}

const String& vp9DecoderEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VP9DecoderEnabled"));
    return key;
}

const String& mediaUserGestureInheritsFromDocumentKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaUserGestureInheritsFromDocument"));
    return key;
}

const String& mediaVideoCodecIDsAllowedInLockdownModeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaVideoCodecIDsAllowedInLockdownMode"));
    return key;
}

const String& interactionRegionMinimumCornerRadiusKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InteractionRegionMinimumCornerRadius"));
    return key;
}

const String& interactionRegionInlinePaddingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InteractionRegionInlinePadding"));
    return key;
}

const String& inspectorWindowFrameKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InspectorWindowFrame"));
    return key;
}

const String& inspectorSupportsShowingCertificateKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InspectorSupportsShowingCertificate"));
    return key;
}

const String& inspectorStartsAttachedKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InspectorStartsAttached"));
    return key;
}

const String& inspectorMaximumResourcesContentSizeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InspectorMaximumResourcesContentSize"));
    return key;
}

const String& inspectorAttachmentSideKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InspectorAttachmentSide"));
    return key;
}

const String& inspectorAttachedWidthKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InspectorAttachedWidth"));
    return key;
}

const String& inspectorAttachedHeightKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InspectorAttachedHeight"));
    return key;
}

const String& minimumFontSizeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MinimumFontSize"));
    return key;
}

const String& minimumLogicalFontSizeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MinimumLogicalFontSize"));
    return key;
}

const String& minimumZoomFontSizeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MinimumZoomFontSize"));
    return key;
}

const String& mockCaptureDevicesPromptEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MockCaptureDevicesPromptEnabled"));
    return key;
}

const String& mockScrollbarsControllerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MockScrollbarsControllerEnabled"));
    return key;
}

const String& mockScrollbarsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MockScrollbarsEnabled"));
    return key;
}

const String& inlineMediaPlaybackRequiresPlaysInlineAttributeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InlineMediaPlaybackRequiresPlaysInlineAttribute"));
    return key;
}

const String& incrementalRenderingSuppressionTimeoutKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IncrementalRenderingSuppressionTimeout"));
    return key;
}

const String& incrementalPDFLoadingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IncrementalPDFLoadingEnabled"));
    return key;
}

const String& incompleteImageBorderEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IncompleteImageBorderEnabled"));
    return key;
}

const String& needsAdobeFrameReloadingQuirkKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NeedsAdobeFrameReloadingQuirk"));
    return key;
}

const String& inactiveMediaCaptureStreamRepromptIntervalInMinutesKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InactiveMediaCaptureStreamRepromptIntervalInMinutes"));
    return key;
}

const String& needsFrameNameFallbackToIdQuirkKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NeedsFrameNameFallbackToIdQuirk"));
    return key;
}

const String& needsKeyboardEventDisambiguationQuirksKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NeedsKeyboardEventDisambiguationQuirks"));
    return key;
}

const String& pdfPluginEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PDFPluginEnabled"));
    return key;
}

const String& pdfPluginHUDEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PDFPluginHUDEnabled"));
    return key;
}

const String& pdfPluginPageNumberIndicatorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PDFPluginPageNumberIndicatorEnabled"));
    return key;
}

const String& passiveTouchListenersAsDefaultOnDocumentKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PassiveTouchListenersAsDefaultOnDocument"));
    return key;
}

const String& passwordEchoDurationKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PasswordEchoDuration"));
    return key;
}

const String& passwordEchoEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PasswordEchoEnabled"));
    return key;
}

const String& pictographFontFamilyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PictographFontFamily"));
    return key;
}

const String& pictureInPictureAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PictureInPictureAPIEnabled"));
    return key;
}

const String& pitchCorrectionAlgorithmKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PitchCorrectionAlgorithm"));
    return key;
}

const String& punchOutWhiteBackgroundsInDarkModeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PunchOutWhiteBackgroundsInDarkMode"));
    return key;
}

const String& requiresPageVisibilityForVideoToBeNowPlayingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequiresPageVisibilityForVideoToBeNowPlaying"));
    return key;
}

const String& requiresPageVisibilityToPlayAudioKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequiresPageVisibilityToPlayAudio"));
    return key;
}

const String& hiddenPageCSSAnimationSuspensionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("HiddenPageCSSAnimationSuspensionEnabled"));
    return key;
}

const String& requiresUserGestureForAudioPlaybackKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequiresUserGestureForAudioPlayback"));
    return key;
}

const String& requiresUserGestureForMediaPlaybackKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequiresUserGestureForMediaPlayback"));
    return key;
}

const String& requiresUserGestureForVideoPlaybackKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequiresUserGestureForVideoPlayback"));
    return key;
}

const String& requiresUserGestureToLoadVideoKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequiresUserGestureToLoadVideo"));
    return key;
}

const String& usesSingleWebProcessKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UsesSingleWebProcess"));
    return key;
}

const String& rubberBandingForSubScrollableRegionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RubberBandingForSubScrollableRegionsEnabled"));
    return key;
}

const String& sampledPageTopColorMaxDifferenceKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SampledPageTopColorMaxDifference"));
    return key;
}

const String& sampledPageTopColorMinHeightKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SampledPageTopColorMinHeight"));
    return key;
}

const String& usesEncodingDetectorKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UsesEncodingDetector"));
    return key;
}

const String& sansSerifFontFamilyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SansSerifFontFamily"));
    return key;
}

const String& selectTrailingWhitespaceEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SelectTrailingWhitespaceEnabled"));
    return key;
}

const String& serifFontFamilyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SerifFontFamily"));
    return key;
}

const String& usesBackForwardCacheKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UsesBackForwardCache"));
    return key;
}

const String& userInterfaceDirectionPolicyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UserInterfaceDirectionPolicy"));
    return key;
}

const String& caretBrowsingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CaretBrowsingEnabled"));
    return key;
}

const String& useSystemAppearanceKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseSystemAppearance"));
    return key;
}

const String& serviceControlsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ServiceControlsEnabled"));
    return key;
}

const String& isGStreamerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GStreamerEnabled"));
    return key;
}

const String& serviceWorkerEntitlementDisabledForTestingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ServiceWorkerEntitlementDisabledForTesting"));
    return key;
}

const String& shouldAllowUserInstalledFontsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldAllowUserInstalledFonts"));
    return key;
}

const String& colorFilterEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ColorFilterEnabled"));
    return key;
}

const String& usePreHTML5ParserQuirksKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UsePreHTML5ParserQuirks"));
    return key;
}

const String& shouldConvertInvalidURLsToBlankKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldConvertInvalidURLsToBlank"));
    return key;
}

const String& shouldConvertPositionStyleOnCopyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldConvertPositionStyleOnCopy"));
    return key;
}

const String& shouldDecidePolicyBeforeLoadingQuickLookPreviewKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldDecidePolicyBeforeLoadingQuickLookPreview"));
    return key;
}

const String& shouldDisplayCaptionsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldDisplayCaptions"));
    return key;
}

const String& contentChangeObserverEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ContentChangeObserverEnabled"));
    return key;
}

const String& contentDispositionAttachmentSandboxEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ContentDispositionAttachmentSandboxEnabled"));
    return key;
}

const String& forceWebGLUsesLowPowerKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ForceWebGLUsesLowPower"));
    return key;
}

const String& contextMenuQRCodeDetectionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ContextMenuQRCodeDetectionEnabled"));
    return key;
}

const String& shouldDisplaySubtitlesKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldDisplaySubtitles"));
    return key;
}

const String& forceFTPDirectoryListingsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ForceFTPDirectoryListings"));
    return key;
}

const String& forceCompositingModeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ForceCompositingMode"));
    return key;
}

const String& shouldDisplayTextDescriptionsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldDisplayTextDescriptions"));
    return key;
}

const String& shouldEnableTextAutosizingBoostKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldEnableTextAutosizingBoost"));
    return key;
}

const String& useImageDocumentForSubframePDFKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseImageDocumentForSubframePDF"));
    return key;
}

const String& fixedFontFamilyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FixedFontFamily"));
    return key;
}

const String& shouldIgnoreMetaViewportKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldIgnoreMetaViewport"));
    return key;
}

const String& shouldPrintBackgroundsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldPrintBackgrounds"));
    return key;
}

const String& cursiveFontFamilyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CursiveFontFamily"));
    return key;
}

const String& shouldRespectImageOrientationKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldRespectImageOrientation"));
    return key;
}

const String& shouldRestrictBaseURLSchemesKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldRestrictBaseURLSchemes"));
    return key;
}

const String& shouldSuppressTextInputFromEditingDuringProvisionalNavigationKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldSuppressTextInputFromEditingDuringProvisionalNavigation"));
    return key;
}

const String& fantasyFontFamilyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FantasyFontFamily"));
    return key;
}

const String& domPasteAllowedKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DOMPasteAllowed"));
    return key;
}

const String& shouldUseServiceWorkerShortTimeoutKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldUseServiceWorkerShortTimeout"));
    return key;
}

const String& ftpDirectoryTemplatePathKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FTPDirectoryTemplatePath"));
    return key;
}

const String& dataDetectorTypesKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DataDetectorTypes"));
    return key;
}

const String& isExtensibleSSOEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ExtensibleSSOEnabled"));
    return key;
}

const String& treatsAnyTextCSSLinkAsStylesheetKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TreatsAnyTextCSSLinkAsStylesheet"));
    return key;
}

const String& linkPreloadEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LinkPreloadEnabled"));
    return key;
}

const String& showsToolTipOverTruncatedTextKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShowsToolTipOverTruncatedText"));
    return key;
}

const String& threadedScrollingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ThreadedScrollingEnabled"));
    return key;
}

const String& defaultFixedFontSizeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DefaultFixedFontSize"));
    return key;
}

const String& defaultFontSizeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DefaultFontSize"));
    return key;
}

const String& defaultTextEncodingNameKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DefaultTextEncodingName"));
    return key;
}

const String& textInteractionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TextInteractionEnabled"));
    return key;
}

const String& textExtractionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TextExtractionEnabled"));
    return key;
}

const String& textAutosizingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TextAutosizingEnabled"));
    return key;
}

const String& developerExtrasEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DeveloperExtrasEnabled"));
    return key;
}

const String& deviceHeightKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DeviceHeight"));
    return key;
}

const String& deviceOrientationEventEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DeviceOrientationEventEnabled"));
    return key;
}

const String& deviceOrientationPermissionAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DeviceOrientationPermissionAPIEnabled"));
    return key;
}

const String& deviceWidthKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DeviceWidth"));
    return key;
}

const String& showsURLsInToolTipsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShowsURLsInToolTipsEnabled"));
    return key;
}

const String& textAreasAreResizableKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TextAreasAreResizable"));
    return key;
}

const String& temporaryTileCohortRetentionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TemporaryTileCohortRetentionEnabled"));
    return key;
}

const String& telephoneNumberParsingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TelephoneNumberParsingEnabled"));
    return key;
}

const String& shrinksStandaloneImagesToFitKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShrinksStandaloneImagesToFit"));
    return key;
}

const String& disabledAdaptationsMetaTagEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DisabledAdaptationsMetaTagEnabled"));
    return key;
}

const String& downloadAttributeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DownloadAttributeEnabled"));
    return key;
}

const String& tabsToLinksKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TabsToLinks"));
    return key;
}

const String& editableLinkBehaviorKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EditableLinkBehavior"));
    return key;
}

const String& systemPreviewEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SystemPreviewEnabled"));
    return key;
}

const String& systemLayoutDirectionKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SystemLayoutDirection"));
    return key;
}

const String& suppressesIncrementalRenderingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SuppressesIncrementalRendering"));
    return key;
}

const String& standardFontFamilyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("StandardFontFamily"));
    return key;
}

const String& enableInheritURIQueryComponentKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EnableInheritURIQueryComponent"));
    return key;
}

const String& encryptedMediaAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EncryptedMediaAPIEnabled"));
    return key;
}

const String& standaloneKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("Standalone"));
    return key;
}

const String& smartInsertDeleteEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SmartInsertDeleteEnabled"));
    return key;
}

const String& spatialNavigationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SpatialNavigationEnabled"));
    return key;
}

const String& sourceBufferChangeTypeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SourceBufferChangeTypeEnabled"));
    return key;
}

const String& targetTextPseudoElementEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TargetTextPseudoElementEnabled"));
    return key;
}

const String& thumbAndTrackPseudoElementsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ThumbAndTrackPseudoElementsEnabled"));
    return key;
}

const String& linkDNSPrefetchEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LinkDNSPrefetchEnabled"));
    return key;
}

const String& selectShowPickerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SelectShowPickerEnabled"));
    return key;
}

const String& pageAtRuleMarginDescriptorsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PageAtRuleMarginDescriptorsEnabled"));
    return key;
}

const String& isAVFoundationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AVFoundationEnabled"));
    return key;
}

const String& isAVKitContentSourceEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AVKitContentSourceEnabled"));
    return key;
}

const String& acceleratedFiltersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AcceleratedFiltersEnabled"));
    return key;
}

const String& accessHandleEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AccessHandleEnabled"));
    return key;
}

const String& domTestingAPIsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DOMTestingAPIsEnabled"));
    return key;
}

const String& allowMediaContentTypesRequiringHardwareSupportAsFallbackKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowMediaContentTypesRequiringHardwareSupportAsFallback"));
    return key;
}

const String& allowPrivacySensitiveOperationsInNonPersistentDataStoresKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowPrivacySensitiveOperationsInNonPersistentDataStores"));
    return key;
}

const String& allowViewportShrinkToFitContentKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowViewportShrinkToFitContent"));
    return key;
}

const String& allowWebGLInWorkersKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowWebGLInWorkers"));
    return key;
}

const String& perElementSpeakerSelectionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PerElementSpeakerSelectionEnabled"));
    return key;
}

const String& exposeSpeakersWithoutMicrophoneEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ExposeSpeakersWithoutMicrophoneEnabled"));
    return key;
}

const String& exposeSpeakersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ExposeSpeakersEnabled"));
    return key;
}

const String& allowTopNavigationToDataURLsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowTopNavigationToDataURLs"));
    return key;
}

const String& allowUniversalAccessFromFileURLsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AllowUniversalAccessFromFileURLs"));
    return key;
}

const String& alwaysAllowLocalWebarchiveKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AlwaysAllowLocalWebarchive"));
    return key;
}

const String& sWVPDecodersAlwaysEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SWVPDecodersAlwaysEnabled"));
    return key;
}

const String& appBadgeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AppBadgeEnabled"));
    return key;
}

const String& appHighlightsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AppHighlightsEnabled"));
    return key;
}

const String& asyncFrameScrollingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AsyncFrameScrollingEnabled"));
    return key;
}

const String& asyncOverflowScrollingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AsyncOverflowScrollingEnabled"));
    return key;
}

const String& useAsyncUIKitInteractionsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseAsyncUIKitInteractions"));
    return key;
}

const String& asyncClipboardAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AsyncClipboardAPIEnabled"));
    return key;
}

const String& attachmentElementEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AttachmentElementEnabled"));
    return key;
}

const String& attachmentWideLayoutEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AttachmentWideLayoutEnabled"));
    return key;
}

const String& extendedAudioDescriptionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ExtendedAudioDescriptionsEnabled"));
    return key;
}

const String& audioDescriptionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AudioDescriptionsEnabled"));
    return key;
}

const String& domAudioSessionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DOMAudioSessionEnabled"));
    return key;
}

const String& domAudioSessionFullEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DOMAudioSessionFullEnabled"));
    return key;
}

const String& automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidthKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth"));
    return key;
}

const String& beaconAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BeaconAPIEnabled"));
    return key;
}

const String& bidiContentAwarePasteEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BidiContentAwarePasteEnabled"));
    return key;
}

const String& blockFontServiceInWebContentSandboxKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlockFontServiceInWebContentSandbox"));
    return key;
}

const String& blockIconServicesInWebContentSandboxKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlockIconServicesInWebContentSandbox"));
    return key;
}

const String& blockMobileAssetInWebContentSandboxKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlockMobileAssetInWebContentSandbox"));
    return key;
}

const String& blockMobileGestaltInWebContentSandboxKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlockMobileGestaltInWebContentSandbox"));
    return key;
}

const String& blockOpenDirectoryInWebContentSandboxKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlockOpenDirectoryInWebContentSandbox"));
    return key;
}

const String& blockWebInspectorInWebContentSandboxKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlockWebInspectorInWebContentSandbox"));
    return key;
}

const String& broadcastChannelEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BroadcastChannelEnabled"));
    return key;
}

const String& builtInNotificationsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BuiltInNotificationsEnabled"));
    return key;
}

const String& css3DTransformBackfaceVisibilityInteroperabilityEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSS3DTransformBackfaceVisibilityInteroperabilityEnabled"));
    return key;
}

const String& cssCounterStyleAtRuleImageSymbolsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSCounterStyleAtRuleImageSymbolsEnabled"));
    return key;
}

const String& accentColorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AccentColorEnabled"));
    return key;
}

const String& cssAnchorPositioningEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSAnchorPositioningEnabled"));
    return key;
}

const String& cssAnchorPositioningPositionVisibilityEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSAnchorPositioningPositionVisibilityEnabled"));
    return key;
}

const String& devolvableWidgetsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DevolvableWidgetsEnabled"));
    return key;
}

const String& cssInputSecurityEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSInputSecurityEnabled"));
    return key;
}

const String& masonryEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MasonryEnabled"));
    return key;
}

const String& overscrollBehaviorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("OverscrollBehaviorEnabled"));
    return key;
}

const String& cssPaintingAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSPaintingAPIEnabled"));
    return key;
}

const String& cssRhythmicSizingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSRhythmicSizingEnabled"));
    return key;
}

const String& cssScrollAnchoringEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSScrollAnchoringEnabled"));
    return key;
}

const String& springTimingFunctionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SpringTimingFunctionEnabled"));
    return key;
}

const String& cssTreeCountingFunctionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTreeCountingFunctionsEnabled"));
    return key;
}

const String& cssTypedOMColorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTypedOMColorEnabled"));
    return key;
}

const String& cssURLModifiersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSURLModifiersEnabled"));
    return key;
}

const String& cssURLIntegrityModifierEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSURLIntegrityModifierEnabled"));
    return key;
}

const String& cssUnprefixedBackdropFilterEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSUnprefixedBackdropFilterEnabled"));
    return key;
}

const String& cssAppearanceBaseEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSAppearanceBaseEnabled"));
    return key;
}

const String& cssAxisRelativePositionKeywordsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSAxisRelativePositionKeywordsEnabled"));
    return key;
}

const String& cssBackgroundClipBorderAreaEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSBackgroundClipBorderAreaEnabled"));
    return key;
}

const String& cssColorLayersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSColorLayersEnabled"));
    return key;
}

const String& cssContrastColorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSContrastColorEnabled"));
    return key;
}

const String& cssCornerShapeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSCornerShapeEnabled"));
    return key;
}

const String& cssDPropertyEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSDPropertyEnabled"));
    return key;
}

const String& cssDynamicRangeLimitMixEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSDynamicRangeLimitMixEnabled"));
    return key;
}

const String& cssConstrainedDynamicRangeLimitEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSConstrainedDynamicRangeLimitEnabled"));
    return key;
}

const String& cssFieldSizingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSFieldSizingEnabled"));
    return key;
}

const String& cssFontVariantEmojiEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSFontVariantEmojiEnabled"));
    return key;
}

const String& cssLineClampEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSLineClampEnabled"));
    return key;
}

const String& cssLineFitEdgeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSLineFitEdgeEnabled"));
    return key;
}

const String& cssProgressFunctionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSProgressFunctionEnabled"));
    return key;
}

const String& cssRandomFunctionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSRandomFunctionEnabled"));
    return key;
}

const String& cssRubyAlignEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSRubyAlignEnabled"));
    return key;
}

const String& cssRubyOverhangEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSRubyOverhangEnabled"));
    return key;
}

const String& cssScrollbarColorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSScrollbarColorEnabled"));
    return key;
}

const String& cssScrollbarGutterEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSScrollbarGutterEnabled"));
    return key;
}

const String& cssScrollbarWidthEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSScrollbarWidthEnabled"));
    return key;
}

const String& cssShapeFunctionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSShapeFunctionEnabled"));
    return key;
}

const String& cssTextAutospaceEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTextAutospaceEnabled"));
    return key;
}

const String& cssTextBoxTrimEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTextBoxTrimEnabled"));
    return key;
}

const String& cssTextGroupAlignEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTextGroupAlignEnabled"));
    return key;
}

const String& cssTextJustifyEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTextJustifyEnabled"));
    return key;
}

const String& cssTextSpacingTrimEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTextSpacingTrimEnabled"));
    return key;
}

const String& cssTextUnderlinePositionLeftRightEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTextUnderlinePositionLeftRightEnabled"));
    return key;
}

const String& cssTextWrapPrettyEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTextWrapPrettyEnabled"));
    return key;
}

const String& cssTransformStyleSeparatedEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSTransformStyleSeparatedEnabled"));
    return key;
}

const String& cacheAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CacheAPIEnabled"));
    return key;
}

const String& canvasColorSpaceEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CanvasColorSpaceEnabled"));
    return key;
}

const String& canvasFiltersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CanvasFiltersEnabled"));
    return key;
}

const String& canvasLayersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CanvasLayersEnabled"));
    return key;
}

const String& canvasUsesAcceleratedDrawingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CanvasUsesAcceleratedDrawing"));
    return key;
}

const String& canvasPixelFormatEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CanvasPixelFormatEnabled"));
    return key;
}

const String& childProcessDebuggabilityEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ChildProcessDebuggabilityEnabled"));
    return key;
}

const String& clearSiteDataHTTPHeaderEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ClearSiteDataHTTPHeaderEnabled"));
    return key;
}

const String& clearSiteDataExecutionContextsSupportEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ClearSiteDataExecutionContextsSupportEnabled"));
    return key;
}

const String& closeWatcherEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CloseWatcherEnabled"));
    return key;
}

const String& inputTypeColorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InputTypeColorEnabled"));
    return key;
}

const String& compositingBordersVisibleKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CompositingBordersVisible"));
    return key;
}

const String& compositingRepaintCountersVisibleKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CompositingRepaintCountersVisible"));
    return key;
}

const String& compressionStreamEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CompressionStreamEnabled"));
    return key;
}

const String& contactPickerAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ContactPickerAPIEnabled"));
    return key;
}

const String& contentInsetBackgroundFillEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ContentInsetBackgroundFillEnabled"));
    return key;
}

const String& cookieConsentAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CookieConsentAPIEnabled"));
    return key;
}

const String& cookieStoreManagerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CookieStoreManagerEnabled"));
    return key;
}

const String& cookieStoreAPIExtendedAttributesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CookieStoreAPIExtendedAttributesEnabled"));
    return key;
}

const String& cookieStoreAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CookieStoreAPIEnabled"));
    return key;
}

const String& cookieEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CookieEnabled"));
    return key;
}

const String& inputMethodUsesCorrectKeyEventOrderKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InputMethodUsesCorrectKeyEventOrder"));
    return key;
}

const String& crossDocumentViewTransitionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CrossDocumentViewTransitionsEnabled"));
    return key;
}

const String& crossOriginEmbedderPolicyEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CrossOriginEmbedderPolicyEnabled"));
    return key;
}

const String& crossOriginOpenerPolicyEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CrossOriginOpenerPolicyEnabled"));
    return key;
}

const String& customPasteboardDataEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CustomPasteboardDataEnabled"));
    return key;
}

const String& domPasteAccessRequestsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DOMPasteAccessRequestsEnabled"));
    return key;
}

const String& mutationEventsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MutationEventsEnabled"));
    return key;
}

const String& domTimersThrottlingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DOMTimersThrottlingEnabled"));
    return key;
}

const String& zoomOnDoubleTapWhenRootKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ZoomOnDoubleTapWhenRoot"));
    return key;
}

const String& alwaysZoomOnDoubleTapKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AlwaysZoomOnDoubleTap"));
    return key;
}

const String& dataTransferItemsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DataTransferItemsEnabled"));
    return key;
}

const String& dataListElementEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DataListElementEnabled"));
    return key;
}

const String& inputTypeDateEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InputTypeDateEnabled"));
    return key;
}

const String& dateTimeInputsEditableComponentsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DateTimeInputsEditableComponentsEnabled"));
    return key;
}

const String& declarativeWebPushKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DeclarativeWebPush"));
    return key;
}

const String& shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaintKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint"));
    return key;
}

const String& deprecationReportingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DeprecationReportingEnabled"));
    return key;
}

const String& detachableMediaSourceEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DetachableMediaSourceEnabled"));
    return key;
}

const String& uAVisualTransitionDetectionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UAVisualTransitionDetectionEnabled"));
    return key;
}

const String& diagnosticLoggingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DiagnosticLoggingEnabled"));
    return key;
}

const String& digitalCredentialsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DigitalCredentialsEnabled"));
    return key;
}

const String& directoryUploadEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DirectoryUploadEnabled"));
    return key;
}

const String& isThirdPartyCookieBlockingDisabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IsThirdPartyCookieBlockingDisabled"));
    return key;
}

const String& isFirstPartyWebsiteDataRemovalDisabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IsFirstPartyWebsiteDataRemovalDisabled"));
    return key;
}

const String& disableScreenSizeOverrideKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DisableScreenSizeOverride"));
    return key;
}

const String& shouldDropNearSuspendedAssertionAfterDelayKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldDropNearSuspendedAssertionAfterDelay"));
    return key;
}

const String& useCGDisplayListsForDOMRenderingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseCGDisplayListsForDOMRendering"));
    return key;
}

const String& replayCGDisplayListsIntoBackingStoreKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ReplayCGDisplayListsIntoBackingStore"));
    return key;
}

const String& dynamicSiteInterventionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DynamicSiteInterventionsEnabled"));
    return key;
}

const String& embedElementEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EmbedElementEnabled"));
    return key;
}

const String& enableAccessibilityOnDemandKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EnableAccessibilityOnDemand"));
    return key;
}

const String& automaticLiveResizeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AutomaticLiveResizeEnabled"));
    return key;
}

const String& canvasFingerprintingQuirkEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CanvasFingerprintingQuirkEnabled"));
    return key;
}

const String& enableElementCurrentCSSZoomKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EnableElementCurrentCSSZoom"));
    return key;
}

const String& enumeratingAllNetworkInterfacesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EnumeratingAllNetworkInterfacesEnabled"));
    return key;
}

const String& enumeratingVisibleNetworkInterfacesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EnumeratingVisibleNetworkInterfacesEnabled"));
    return key;
}

const String& iceCandidateFilteringEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ICECandidateFilteringEnabled"));
    return key;
}

const String& legacyEncryptedMediaAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LegacyEncryptedMediaAPIEnabled"));
    return key;
}

const String& mockCaptureDevicesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MockCaptureDevicesEnabled"));
    return key;
}

const String& modelProcessEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ModelProcessEnabled"));
    return key;
}

const String& pdfJSViewerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PDFJSViewerEnabled"));
    return key;
}

const String& auxclickEventEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AuxclickEventEnabled"));
    return key;
}

const String& backgroundWebContentRunningBoardThrottlingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BackgroundWebContentRunningBoardThrottlingEnabled"));
    return key;
}

const String& backgroundFetchAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BackgroundFetchAPIEnabled"));
    return key;
}

const String& enableDebuggingFeaturesInSandboxKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EnableDebuggingFeaturesInSandbox"));
    return key;
}

const String& cFNetworkNetworkLoaderEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CFNetworkNetworkLoaderEnabled"));
    return key;
}

const String& experimentalSandboxEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ExperimentalSandboxEnabled"));
    return key;
}

const String& navigatorUserAgentDataJavaScriptAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NavigatorUserAgentDataJavaScriptAPIEnabled"));
    return key;
}

const String& blobFileAccessEnforcementEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlobFileAccessEnforcementEnabled"));
    return key;
}

const String& enterKeyHintEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EnterKeyHintEnabled"));
    return key;
}

const String& eventTimingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EventTimingEnabled"));
    return key;
}

const String& eventHandlerDrivenSmoothKeyboardScrollingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("EventHandlerDrivenSmoothKeyboardScrollingEnabled"));
    return key;
}

const String& mediaSessionCoordinatorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaSessionCoordinatorEnabled"));
    return key;
}

const String& mediaSessionPlaylistEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaSessionPlaylistEnabled"));
    return key;
}

const String& exposeCaptureDevicesAfterCaptureEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ExposeCaptureDevicesAfterCaptureEnabled"));
    return key;
}

const String& exposeDefaultSpeakerAsSpecificDeviceEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ExposeDefaultSpeakerAsSpecificDeviceEnabled"));
    return key;
}

const String& ftpEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FTPEnabled"));
    return key;
}

const String& preferFasterClickOverDoubleTapKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PreferFasterClickOverDoubleTap"));
    return key;
}

const String& fasterClicksEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FasterClicksEnabled"));
    return key;
}

const String& fileSystemEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FileSystemEnabled"));
    return key;
}

const String& fileSystemWritableStreamEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FileSystemWritableStreamEnabled"));
    return key;
}

const String& fileReaderAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FileReaderAPIEnabled"));
    return key;
}

const String& filterLinkDecorationByDefaultEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FilterLinkDecorationByDefaultEnabled"));
    return key;
}

const String& forceLockdownFontParserEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ForceLockdownFontParserEnabled"));
    return key;
}

const String& forceAlwaysUserScalableKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ForceAlwaysUserScalable"));
    return key;
}

const String& formControlRefreshEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FormControlRefreshEnabled"));
    return key;
}

const String& iFrameResourceMonitoringTestingSettingsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IFrameResourceMonitoringTestingSettingsEnabled"));
    return key;
}

const String& iFrameResourceMonitoringEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IFrameResourceMonitoringEnabled"));
    return key;
}

const String& fullScreenKeyboardLockKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FullScreenKeyboardLock"));
    return key;
}

const String& fullScreenEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FullScreenEnabled"));
    return key;
}

const String& fullscreenSceneAspectRatioLockingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FullscreenSceneAspectRatioLockingEnabled"));
    return key;
}

const String& fullscreenSceneDimmingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FullscreenSceneDimmingEnabled"));
    return key;
}

const String& captureAudioInGPUProcessEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CaptureAudioInGPUProcessEnabled"));
    return key;
}

const String& blockMediaLayerRehostingInWebContentProcessKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlockMediaLayerRehostingInWebContentProcess"));
    return key;
}

const String& useGPUProcessForCanvasRenderingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseGPUProcessForCanvasRenderingEnabled"));
    return key;
}

const String& manageCaptureStatusBarInGPUProcessEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ManageCaptureStatusBarInGPUProcessEnabled"));
    return key;
}

const String& useGPUProcessForDOMRenderingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseGPUProcessForDOMRenderingEnabled"));
    return key;
}

const String& useGPUProcessForMediaEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseGPUProcessForMediaEnabled"));
    return key;
}

const String& useGPUProcessForDisplayCaptureKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseGPUProcessForDisplayCapture"));
    return key;
}

const String& captureVideoInGPUProcessEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CaptureVideoInGPUProcessEnabled"));
    return key;
}

const String& useGPUProcessForWebGLEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseGPUProcessForWebGLEnabled"));
    return key;
}

const String& webRTCPlatformCodecsInGPUProcessEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCPlatformCodecsInGPUProcessEnabled"));
    return key;
}

const String& gamepadTriggerRumbleEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GamepadTriggerRumbleEnabled"));
    return key;
}

const String& gamepadVibrationActuatorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GamepadVibrationActuatorEnabled"));
    return key;
}

const String& gamepadsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GamepadsEnabled"));
    return key;
}

const String& genericCueAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GenericCueAPIEnabled"));
    return key;
}

const String& geolocationAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GeolocationAPIEnabled"));
    return key;
}

const String& graphicsContextFiltersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GraphicsContextFiltersEnabled"));
    return key;
}

const String& acceleratedDrawingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AcceleratedDrawingEnabled"));
    return key;
}

const String& modelElementEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ModelElementEnabled"));
    return key;
}

const String& modelDocumentEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ModelDocumentEnabled"));
    return key;
}

const String& interactiveFormValidationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InteractiveFormValidationEnabled"));
    return key;
}

const String& mediaEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaEnabled"));
    return key;
}

const String& inputTypeColorEnhancementsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InputTypeColorEnhancementsEnabled"));
    return key;
}

const String& detailsAutoExpandEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("DetailsAutoExpandEnabled"));
    return key;
}

const String& commandAttributesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CommandAttributesEnabled"));
    return key;
}

const String& hTMLLegacyAttributeValueSerializationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("HTMLLegacyAttributeValueSerializationEnabled"));
    return key;
}

const String& popoverAttributeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PopoverAttributeEnabled"));
    return key;
}

const String& switchControlEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SwitchControlEnabled"));
    return key;
}

const String& httpSByDefaultEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("HTTPSByDefaultEnabled"));
    return key;
}

const String& hiddenPageDOMTimerThrottlingAutoIncreasesKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("HiddenPageDOMTimerThrottlingAutoIncreases"));
    return key;
}

const String& hiddenPageDOMTimerThrottlingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("HiddenPageDOMTimerThrottlingEnabled"));
    return key;
}

const String& hostedBlurMaterialInMediaControlsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("HostedBlurMaterialInMediaControlsEnabled"));
    return key;
}

const String& blockIOKitInWebContentSandboxKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("BlockIOKitInWebContentSandbox"));
    return key;
}

const String& iOSurfaceLosslessCompressionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IOSurfaceLosslessCompressionEnabled"));
    return key;
}

const String& ipcTestingAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IPCTestingAPIEnabled"));
    return key;
}

const String& itpDebugModeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ItpDebugModeEnabled"));
    return key;
}

const String& textAutosizingUsesIdempotentModeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TextAutosizingUsesIdempotentMode"));
    return key;
}

const String& ignoreInvalidMessageWhenIPCTestingAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IgnoreInvalidMessageWhenIPCTestingAPIEnabled"));
    return key;
}

const String& ignoreIframeEmbeddingProtectionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IgnoreIframeEmbeddingProtectionsEnabled"));
    return key;
}

const String& imageAnalysisDuringFindInPageEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ImageAnalysisDuringFindInPageEnabled"));
    return key;
}

const String& imageAnimationControlEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ImageAnimationControlEnabled"));
    return key;
}

const String& imageCaptureEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ImageCaptureEnabled"));
    return key;
}

const String& imageControlsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ImageControlsEnabled"));
    return key;
}

const String& inWindowFullscreenEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InWindowFullscreenEnabled"));
    return key;
}

const String& includeIgnoredInCoreAXTreeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IncludeIgnoredInCoreAXTree"));
    return key;
}

const String& indexedDBAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IndexedDBAPIEnabled"));
    return key;
}

const String& interactionRegionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InteractionRegionsEnabled"));
    return key;
}

const String& isAccessibilityIsolatedTreeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IsAccessibilityIsolatedTreeEnabled"));
    return key;
}

const String& javaScriptEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("JavaScriptEnabled"));
    return key;
}

const String& keyboardDismissalGestureEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("KeyboardDismissalGestureEnabled"));
    return key;
}

const String& layerBasedSVGEngineEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LayerBasedSVGEngineEnabled"));
    return key;
}

const String& lazyIframeLoadingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LazyIframeLoadingEnabled"));
    return key;
}

const String& lazyImageLoadingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LazyImageLoadingEnabled"));
    return key;
}

const String& legacyOverflowScrollingTouchEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LegacyOverflowScrollingTouchEnabled"));
    return key;
}

const String& legacyLineLayoutVisualCoverageEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LegacyLineLayoutVisualCoverageEnabled"));
    return key;
}

const String& showModalDialogEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShowModalDialogEnabled"));
    return key;
}

const String& mediaCaptureRequiresSecureConnectionKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaCaptureRequiresSecureConnection"));
    return key;
}

const String& limitedMatroskaSupportEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LimitedMatroskaSupportEnabled"));
    return key;
}

const String& linearMediaPlayerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LinearMediaPlayerEnabled"));
    return key;
}

const String& linkSanitizerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LinkSanitizerEnabled"));
    return key;
}

const String& linkPreconnectEarlyHintsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LinkPreconnectEarlyHintsEnabled"));
    return key;
}

const String& linkPrefetchEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LinkPrefetchEnabled"));
    return key;
}

const String& loadWebArchiveWithEphemeralStorageEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LoadWebArchiveWithEphemeralStorageEnabled"));
    return key;
}

const String& localFileContentSniffingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LocalFileContentSniffingEnabled"));
    return key;
}

const String& localNetworkAccessEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LocalNetworkAccessEnabled"));
    return key;
}

const String& localStorageEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LocalStorageEnabled"));
    return key;
}

const String& lockdownFontParserEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LockdownFontParserEnabled"));
    return key;
}

const String& logsPageMessagesToSystemConsoleEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LogsPageMessagesToSystemConsoleEnabled"));
    return key;
}

const String& loginStatusAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LoginStatusAPIEnabled"));
    return key;
}

const String& mainContentUserGestureOverrideEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MainContentUserGestureOverrideEnabled"));
    return key;
}

const String& managedMediaSourceEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ManagedMediaSourceEnabled"));
    return key;
}

const String& managedMediaSourceNeedsAirPlayKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ManagedMediaSourceNeedsAirPlay"));
    return key;
}

const String& coreMathMLEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CoreMathMLEnabled"));
    return key;
}

const String& mediaCapabilitiesExtensionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaCapabilitiesExtensionsEnabled"));
    return key;
}

const String& mediaCapabilityGrantsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaCapabilityGrantsEnabled"));
    return key;
}

const String& mediaPlaybackEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaPlaybackEnabled"));
    return key;
}

const String& mediaSessionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaSessionEnabled"));
    return key;
}

const String& mediaSourceEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaSourceEnabled"));
    return key;
}

const String& mediaDevicesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaDevicesEnabled"));
    return key;
}

const String& mediaRecorderEnabledWebMKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaRecorderEnabledWebM"));
    return key;
}

const String& mediaRecorderEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaRecorderEnabled"));
    return key;
}

const String& mediaSessionCaptureToggleAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaSessionCaptureToggleAPIEnabled"));
    return key;
}

const String& mediaSourceInWorkerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaSourceInWorkerEnabled"));
    return key;
}

const String& mediaSourcePrefersDecompressionSessionKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaSourcePrefersDecompressionSession"));
    return key;
}

const String& mediaStreamTrackProcessingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MediaStreamTrackProcessingEnabled"));
    return key;
}

const String& metaViewportInteractiveWidgetEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MetaViewportInteractiveWidgetEnabled"));
    return key;
}

const String& modelNoPortalAttributeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ModelNoPortalAttributeEnabled"));
    return key;
}

const String& shouldUseModernAVContentKeySessionKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldUseModernAVContentKeySession"));
    return key;
}

const String& momentumScrollingAnimatorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MomentumScrollingAnimatorEnabled"));
    return key;
}

const String& inputTypeMonthEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InputTypeMonthEnabled"));
    return key;
}

const String& mouseEventsSimulationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MouseEventsSimulationEnabled"));
    return key;
}

const String& muteCameraOnMicrophoneInterruptionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("MuteCameraOnMicrophoneInterruptionEnabled"));
    return key;
}

const String& navigationAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NavigationAPIEnabled"));
    return key;
}

const String& needsInAppBrowserPrivacyQuirksKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NeedsInAppBrowserPrivacyQuirks"));
    return key;
}

const String& needsSiteSpecificQuirksKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NeedsSiteSpecificQuirks"));
    return key;
}

const String& needsStorageAccessFromFileURLsQuirkKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NeedsStorageAccessFromFileURLsQuirk"));
    return key;
}

const String& flexFormattingContextIntegrationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FlexFormattingContextIntegrationEnabled"));
    return key;
}

const String& notificationEventEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NotificationEventEnabled"));
    return key;
}

const String& notificationsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("NotificationsEnabled"));
    return key;
}

const String& observableEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ObservableEnabled"));
    return key;
}

const String& accessibilityThreadTextApisEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AccessibilityThreadTextApisEnabled"));
    return key;
}

const String& offscreenCanvasInWorkersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("OffscreenCanvasInWorkersEnabled"));
    return key;
}

const String& offscreenCanvasEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("OffscreenCanvasEnabled"));
    return key;
}

const String& opportunisticSweepingAndGarbageCollectionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("OpportunisticSweepingAndGarbageCollectionEnabled"));
    return key;
}

const String& optInPartitionedCookiesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("OptInPartitionedCookiesEnabled"));
    return key;
}

const String& overlappingBackingStoreProvidersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("OverlappingBackingStoreProvidersEnabled"));
    return key;
}

const String& overlayRegionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("OverlayRegionsEnabled"));
    return key;
}

const String& pageVisibilityBasedProcessSuppressionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PageVisibilityBasedProcessSuppressionEnabled"));
    return key;
}

const String& permissionsAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PermissionsAPIEnabled"));
    return key;
}

const String& photoPickerPrefersOriginalImageFormatKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PhotoPickerPrefersOriginalImageFormat"));
    return key;
}

const String& pictureInPicturePlaybackStateEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PictureInPicturePlaybackStateEnabled"));
    return key;
}

const String& getCoalescedEventsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GetCoalescedEventsEnabled"));
    return key;
}

const String& getPredictedEventsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GetPredictedEventsEnabled"));
    return key;
}

const String& pointerLockEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PointerLockEnabled"));
    return key;
}

const String& pointerLockOptionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PointerLockOptionsEnabled"));
    return key;
}

const String& preferPageRenderingUpdatesNear60FPSEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PreferPageRenderingUpdatesNear60FPSEnabled"));
    return key;
}

const String& preferSpatialAudioExperienceKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PreferSpatialAudioExperience"));
    return key;
}

const String& videoFullsceenPrefersMostVisibleHeuristicKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VideoFullsceenPrefersMostVisibleHeuristic"));
    return key;
}

const String& privateClickMeasurementDebugModeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PrivateClickMeasurementDebugModeEnabled"));
    return key;
}

const String& privateClickMeasurementFraudPreventionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PrivateClickMeasurementFraudPreventionEnabled"));
    return key;
}

const String& privateClickMeasurementEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PrivateClickMeasurementEnabled"));
    return key;
}

const String& privateTokenUsageByThirdPartyEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PrivateTokenUsageByThirdPartyEnabled"));
    return key;
}

const String& propagateDamagingInformationKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PropagateDamagingInformation"));
    return key;
}

const String& pushAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PushAPIEnabled"));
    return key;
}

const String& legacyPluginQuirkForMailSignaturesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LegacyPluginQuirkForMailSignaturesEnabled"));
    return key;
}

const String& googleAntiFlickerOptimizationQuirkEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GoogleAntiFlickerOptimizationQuirkEnabled"));
    return key;
}

const String& readableByteStreamAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ReadableByteStreamAPIEnabled"));
    return key;
}

const String& remoteMediaSessionManagerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RemoteMediaSessionManagerEnabled"));
    return key;
}

const String& remotePlaybackEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RemotePlaybackEnabled"));
    return key;
}

const String& remoteSnapshottingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RemoteSnapshottingEnabled"));
    return key;
}

const String& removeBackgroundEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RemoveBackgroundEnabled"));
    return key;
}

const String& requestVideoFrameCallbackEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequestVideoFrameCallbackEnabled"));
    return key;
}

const String& requireUAGetDisplayMediaPromptKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequireUAGetDisplayMediaPrompt"));
    return key;
}

const String& loginStatusAPIRequiresWebAuthnEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LoginStatusAPIRequiresWebAuthnEnabled"));
    return key;
}

const String& speakerSelectionRequiresUserGestureKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SpeakerSelectionRequiresUserGesture"));
    return key;
}

const String& fullscreenRequirementForScreenOrientationLockingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("FullscreenRequirementForScreenOrientationLockingEnabled"));
    return key;
}

const String& getUserMediaRequiresFocusKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("GetUserMediaRequiresFocus"));
    return key;
}

const String& resourceLoadSchedulingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ResourceLoadSchedulingEnabled"));
    return key;
}

const String& resourceUsageOverlayVisibleKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ResourceUsageOverlayVisible"));
    return key;
}

const String& respondToThermalPressureAggressivelyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RespondToThermalPressureAggressively"));
    return key;
}

const String& sKAttributionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SKAttributionEnabled"));
    return key;
}

const String& safeBrowsingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SafeBrowsingEnabled"));
    return key;
}

const String& isSameSiteStrictEnforcementEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IsSameSiteStrictEnforcementEnabled"));
    return key;
}

const String& scopedCustomElementRegistryEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScopedCustomElementRegistryEnabled"));
    return key;
}

const String& screenOrientationLockingAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScreenOrientationLockingAPIEnabled"));
    return key;
}

const String& screenOrientationAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScreenOrientationAPIEnabled"));
    return key;
}

const String& screenTimeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScreenTimeEnabled"));
    return key;
}

const String& screenWakeLockAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScreenWakeLockAPIEnabled"));
    return key;
}

const String& screenCaptureEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScreenCaptureEnabled"));
    return key;
}

const String& scriptTrackingPrivacyLoggingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScriptTrackingPrivacyLoggingEnabled"));
    return key;
}

const String& scriptTrackingPrivacyProtectionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScriptTrackingPrivacyProtectionsEnabled"));
    return key;
}

const String& scrollingPerformanceTestingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollingPerformanceTestingEnabled"));
    return key;
}

const String& scrollToTextFragmentFeatureDetectionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollToTextFragmentFeatureDetectionEnabled"));
    return key;
}

const String& scrollToTextFragmentGenerationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollToTextFragmentGenerationEnabled"));
    return key;
}

const String& scrollToTextFragmentIndicatorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollToTextFragmentIndicatorEnabled"));
    return key;
}

const String& scrollToTextFragmentMarkingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollToTextFragmentMarkingEnabled"));
    return key;
}

const String& scrollToTextFragmentEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollToTextFragmentEnabled"));
    return key;
}

const String& scrollAnimatorEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollAnimatorEnabled"));
    return key;
}

const String& scrollDrivenAnimationsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollDrivenAnimationsEnabled"));
    return key;
}

const String& secureContextChecksEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SecureContextChecksEnabled"));
    return key;
}

const String& selectionFlippingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SelectionFlippingEnabled"));
    return key;
}

const String& selectionHonorsOverflowScrollingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SelectionHonorsOverflowScrolling"));
    return key;
}

const String& serviceWorkerInstallEventEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ServiceWorkerInstallEventEnabled"));
    return key;
}

const String& serviceWorkerNavigationPreloadEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ServiceWorkerNavigationPreloadEnabled"));
    return key;
}

const String& serviceWorkersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ServiceWorkersEnabled"));
    return key;
}

const String& shapeDetectionKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShapeDetection"));
    return key;
}

const String& siteIsolationSharedProcessEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SiteIsolationSharedProcessEnabled"));
    return key;
}

const String& sharedWorkerEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SharedWorkerEnabled"));
    return key;
}

const String& showMediaStatsContextMenuItemEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShowMediaStatsContextMenuItemEnabled"));
    return key;
}

const String& showFrameProcessBordersEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShowFrameProcessBordersEnabled"));
    return key;
}

const String& sidewaysWritingModesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SidewaysWritingModesEnabled"));
    return key;
}

const String& siteIsolationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SiteIsolationEnabled"));
    return key;
}

const String& spatialImageControlsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SpatialImageControlsEnabled"));
    return key;
}

const String& speechRecognitionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SpeechRecognitionEnabled"));
    return key;
}

const String& speechSynthesisAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SpeechSynthesisAPIEnabled"));
    return key;
}

const String& storageAPIEstimateEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("StorageAPIEstimateEnabled"));
    return key;
}

const String& storageAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("StorageAPIEnabled"));
    return key;
}

const String& storageBlockingPolicyKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("StorageBlockingPolicy"));
    return key;
}

const String& supportHDRCompositorTonemappingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SupportHDRCompositorTonemappingEnabled"));
    return key;
}

const String& supportHDRDisplayEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("SupportHDRDisplayEnabled"));
    return key;
}

const String& processSwapOnCrossSiteNavigationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ProcessSwapOnCrossSiteNavigationEnabled"));
    return key;
}

const String& shouldTakeNearSuspendedAssertionsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShouldTakeNearSuspendedAssertions"));
    return key;
}

const String& textAnimationsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TextAnimationsEnabled"));
    return key;
}

const String& textRecognitionInVideosEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TextRecognitionInVideosEnabled"));
    return key;
}

const String& textTracksInMSEEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TextTracksInMSEEnabled"));
    return key;
}

const String& threadedAnimationResolutionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ThreadedAnimationResolutionEnabled"));
    return key;
}

const String& tiledScrollingIndicatorVisibleKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TiledScrollingIndicatorVisible"));
    return key;
}

const String& inputTypeTimeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InputTypeTimeEnabled"));
    return key;
}

const String& topContentInsetBackgroundCanChangeAfterScrollingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TopContentInsetBackgroundCanChangeAfterScrolling"));
    return key;
}

const String& touchInputCompatibilityEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TouchInputCompatibilityEnabled"));
    return key;
}

const String& trackConfigurationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TrackConfigurationEnabled"));
    return key;
}

const String& trustedTypesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("TrustedTypesEnabled"));
    return key;
}

const String& uRLPatternAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("URLPatternAPIEnabled"));
    return key;
}

const String& undoManagerAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UndoManagerAPIEnabled"));
    return key;
}

const String& unifiedPDFEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UnifiedPDFEnabled"));
    return key;
}

const String& unifyDamagedRegionsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UnifyDamagedRegions"));
    return key;
}

const String& iPAddressAndLocalhostMixedContentUpgradeTestingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IPAddressAndLocalhostMixedContentUpgradeTestingEnabled"));
    return key;
}

const String& upgradeKnownHostsToHTTPSEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UpgradeKnownHostsToHTTPSEnabled"));
    return key;
}

const String& upgradeMixedContentEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UpgradeMixedContentEnabled"));
    return key;
}

const String& useARKitForModelKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseARKitForModel"));
    return key;
}

const String& useAVCaptureDeviceRotationCoordinatorAPIKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseAVCaptureDeviceRotationCoordinatorAPI"));
    return key;
}

const String& useIFCForSVGTextKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseIFCForSVGText"));
    return key;
}

const String& useMicrophoneMuteStatusAPIKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseMicrophoneMuteStatusAPI"));
    return key;
}

const String& useSceneKitForModelKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseSceneKitForModel"));
    return key;
}

const String& useGiantTilesKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseGiantTiles"));
    return key;
}

const String& useDamagingInformationForCompositingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UseDamagingInformationForCompositing"));
    return key;
}

const String& userActivationAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UserActivationAPIEnabled"));
    return key;
}

const String& userGesturePromisePropagationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UserGesturePromisePropagationEnabled"));
    return key;
}

const String& usesWebContentRestrictionsForFilterKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("UsesWebContentRestrictionsForFilter"));
    return key;
}

const String& serviceWorkersUserGestureEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ServiceWorkersUserGestureEnabled"));
    return key;
}

const String& verifyWindowOpenUserGestureFromUIProcessKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VerifyWindowOpenUserGestureFromUIProcess"));
    return key;
}

const String& verticalFormControlsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VerticalFormControlsEnabled"));
    return key;
}

const String& videoRendererProtectedFallbackDisabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VideoRendererProtectedFallbackDisabled"));
    return key;
}

const String& videoRendererUseDecompressionSessionForProtectedKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VideoRendererUseDecompressionSessionForProtected"));
    return key;
}

const String& viewTransitionClassesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ViewTransitionClassesEnabled"));
    return key;
}

const String& viewTransitionTypesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ViewTransitionTypesEnabled"));
    return key;
}

const String& viewTransitionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ViewTransitionsEnabled"));
    return key;
}

const String& viewGestureDebuggingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ViewGestureDebuggingEnabled"));
    return key;
}

const String& visualTranslationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VisualTranslationEnabled"));
    return key;
}

const String& visualViewportAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VisualViewportAPIEnabled"));
    return key;
}

const String& visuallyContiguousBidiTextSelectionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("VisuallyContiguousBidiTextSelectionEnabled"));
    return key;
}

const String& webAPIStatisticsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAPIStatisticsEnabled"));
    return key;
}

const String& webAPIsInShadowRealmEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAPIsInShadowRealmEnabled"));
    return key;
}

const String& webAnimationsOverallProgressPropertyEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAnimationsOverallProgressPropertyEnabled"));
    return key;
}

const String& webAnimationsCustomEffectsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAnimationsCustomEffectsEnabled"));
    return key;
}

const String& webAnimationsCustomFrameRateEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAnimationsCustomFrameRateEnabled"));
    return key;
}

const String& webArchiveDebugModeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebArchiveDebugModeEnabled"));
    return key;
}

const String& webArchiveTestingModeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebArchiveTestingModeEnabled"));
    return key;
}

const String& webAuthenticationASEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAuthenticationASEnabled"));
    return key;
}

const String& webAuthenticationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAuthenticationEnabled"));
    return key;
}

const String& webCryptoSafeCurvesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebCryptoSafeCurvesEnabled"));
    return key;
}

const String& webCryptoX25519EnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebCryptoX25519Enabled"));
    return key;
}

const String& webLocksAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebLocksAPIEnabled"));
    return key;
}

const String& webShareFileAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebShareFileAPIEnabled"));
    return key;
}

const String& webShareEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebShareEnabled"));
    return key;
}

const String& webAssemblyESMIntegrationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebAssemblyESMIntegrationEnabled"));
    return key;
}

const String& webCodecsAV1EnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebCodecsAV1Enabled"));
    return key;
}

const String& webCodecsAudioEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebCodecsAudioEnabled"));
    return key;
}

const String& webCodecsHEVCEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebCodecsHEVCEnabled"));
    return key;
}

const String& webCodecsVideoEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebCodecsVideoEnabled"));
    return key;
}

const String& webExtensionBookmarksEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebExtensionBookmarksEnabled"));
    return key;
}

const String& webExtensionSidebarEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebExtensionSidebarEnabled"));
    return key;
}

const String& webGLDraftExtensionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebGLDraftExtensionsEnabled"));
    return key;
}

const String& webGLTimerQueriesEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebGLTimerQueriesEnabled"));
    return key;
}

const String& webGLEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebGLEnabled"));
    return key;
}

const String& webGPUHDREnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebGPUHDREnabled"));
    return key;
}

const String& webXRWebGPUBindingsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebXRWebGPUBindingsEnabled"));
    return key;
}

const String& webGPUEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebGPUEnabled"));
    return key;
}

const String& webInspectorEngineeringSettingsAllowedKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebInspectorEngineeringSettingsAllowed"));
    return key;
}

const String& webRTCAV1CodecEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCAV1CodecEnabled"));
    return key;
}

const String& webRTCAudioLatencyAdaptationEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCAudioLatencyAdaptationEnabled"));
    return key;
}

const String& webRTCDTMFEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCDTMFEnabled"));
    return key;
}

const String& webRTCEncodedTransformEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCEncodedTransformEnabled"));
    return key;
}

const String& webRTCH264HardwareEncoderEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCH264HardwareEncoderEnabled"));
    return key;
}

const String& webRTCH265CodecEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCH265CodecEnabled"));
    return key;
}

const String& webRTCL4SEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCL4SEnabled"));
    return key;
}

const String& webRTCMediaPipelineAdditionalLoggingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCMediaPipelineAdditionalLoggingEnabled"));
    return key;
}

const String& legacyWebRTCOfferOptionsEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("LegacyWebRTCOfferOptionsEnabled"));
    return key;
}

const String& peerConnectionVideoScalingAdaptationDisabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PeerConnectionVideoScalingAdaptationDisabled"));
    return key;
}

const String& peerConnectionEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PeerConnectionEnabled"));
    return key;
}

const String& webRTCRemoteVideoFrameEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCRemoteVideoFrameEnabled"));
    return key;
}

const String& webRTCSFrameTransformEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCSFrameTransformEnabled"));
    return key;
}

const String& webRTCSocketsProxyingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCSocketsProxyingEnabled"));
    return key;
}

const String& webRTCUDPPortRangeKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCUDPPortRange"));
    return key;
}

const String& webRTCVP9Profile0CodecEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCVP9Profile0CodecEnabled"));
    return key;
}

const String& webRTCVP9Profile2CodecEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCVP9Profile2CodecEnabled"));
    return key;
}

const String& webRTCInterfaceMonitoringViaNWEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebRTCInterfaceMonitoringViaNWEnabled"));
    return key;
}

const String& webTransportEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebTransportEnabled"));
    return key;
}

const String& webXRAugmentedRealityModuleEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebXRAugmentedRealityModuleEnabled"));
    return key;
}

const String& webXREnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebXREnabled"));
    return key;
}

const String& webXRGamepadsModuleEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebXRGamepadsModuleEnabled"));
    return key;
}

const String& webXRHandInputModuleEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebXRHandInputModuleEnabled"));
    return key;
}

const String& webXRLayersAPIEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebXRLayersAPIEnabled"));
    return key;
}

const String& webPageSpatialBackdropEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WebPageSpatialBackdropEnabled"));
    return key;
}

const String& inputTypeWeekEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InputTypeWeekEnabled"));
    return key;
}

const String& wheelEventGesturesBecomeNonBlockingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WheelEventGesturesBecomeNonBlocking"));
    return key;
}

const String& passiveWheelListenersAsDefaultOnDocumentKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("PassiveWheelListenersAsDefaultOnDocument"));
    return key;
}

const String& workerAsynchronousURLErrorHandlingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WorkerAsynchronousURLErrorHandlingEnabled"));
    return key;
}

const String& writeRichTextDataWhenCopyingOrDraggingKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WriteRichTextDataWhenCopyingOrDragging"));
    return key;
}

const String& writingSuggestionsAttributeEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("WritingSuggestionsAttributeEnabled"));
    return key;
}

const String& xSLTEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("XSLTEnabled"));
    return key;
}

const String& isFirstPartyWebsiteDataRemovalLiveOnTestingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled"));
    return key;
}

const String& isFirstPartyWebsiteDataRemovalReproTestingEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("IsFirstPartyWebsiteDataRemovalReproTestingEnabled"));
    return key;
}

const String& altitudeAngleEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AltitudeAngleEnabled"));
    return key;
}

const String& azimuthAngleEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("AzimuthAngleEnabled"));
    return key;
}

const String& inputTypeDateTimeLocalEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("InputTypeDateTimeLocalEnabled"));
    return key;
}

const String& caretPositionFromPointEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CaretPositionFromPointEnabled"));
    return key;
}

const String& hiddenUntilFoundEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("HiddenUntilFoundEnabled"));
    return key;
}

const String& httpEquivEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("HTTPEquivEnabled"));
    return key;
}

const String& shadowRootReferenceTargetEnabledForAriaOwnsKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShadowRootReferenceTargetEnabledForAriaOwns"));
    return key;
}

const String& shadowRootReferenceTargetEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ShadowRootReferenceTargetEnabled"));
    return key;
}

const String& requestIdleCallbackEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequestIdleCallbackEnabled"));
    return key;
}

const String& requestStorageAccessThrowsExceptionUntilReloadKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("RequestStorageAccessThrowsExceptionUntilReload"));
    return key;
}

const String& scrollendEventEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("ScrollendEventEnabled"));
    return key;
}

const String& cssWordBreakAutoPhraseEnabledKey()
{
    static NeverDestroyed<String> key(MAKE_STATIC_STRING_IMPL("CSSWordBreakAutoPhraseEnabled"));
    return key;
}


} // namespace WebPreferencesKey
} // namespace WebKit
