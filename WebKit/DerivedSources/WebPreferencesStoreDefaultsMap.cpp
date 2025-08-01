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
#include "WebPreferencesStore.h"

#include "WebKit2Initialize.h"
#include "WebPreferencesDefinitions.h"
#include "WebPreferencesKeys.h"
#include <wtf/NeverDestroyed.h>

// FIXME: These should added via options in WebPreferences.yaml, rather than hardcoded.
#include <WebCore/DeprecatedGlobalSettings.h>
#include <WebCore/LibWebRTCProvider.h>
#include <WebCore/SecurityOrigin.h>
#include <WebCore/Settings.h>
#include <pal/text/TextEncodingRegistry.h>

namespace WebKit {
using namespace WebCore;

WebPreferencesStore::ValueMap& WebPreferencesStore::defaults()
{
    InitializeWebKit2();
    static NeverDestroyed<ValueMap> defaults;

    if (defaults.get().isEmpty()) {
        defaults.get().set(WebPreferencesKey::databasesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DatabasesEnabled)));
        defaults.get().set(WebPreferencesKey::loadDeferringEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LoadDeferringEnabled)));
        defaults.get().set(WebPreferencesKey::acceleratedCompositingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AcceleratedCompositingEnabled)));
        defaults.get().set(WebPreferencesKey::acceleratedCompositingForFixedPositionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AcceleratedCompositingForFixedPositionEnabled)));
        defaults.get().set(WebPreferencesKey::wirelessPlaybackTargetAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WirelessPlaybackTargetAPIEnabled)));
        defaults.get().set(WebPreferencesKey::loadsImagesAutomaticallyKey(), Value(bool(DEFAULT_VALUE_FOR_LoadsImagesAutomatically)));
        defaults.get().set(WebPreferencesKey::linkPreconnectKey(), Value(bool(DEFAULT_VALUE_FOR_LinkPreconnect)));
        defaults.get().set(WebPreferencesKey::longRunningMediaCaptureStreamRepromptIntervalInHoursKey(), Value(double(DEFAULT_VALUE_FOR_LongRunningMediaCaptureStreamRepromptIntervalInHours)));
        defaults.get().set(WebPreferencesKey::windowFocusRestrictedKey(), Value(bool(DEFAULT_VALUE_FOR_WindowFocusRestricted)));
        defaults.get().set(WebPreferencesKey::aggressiveTileRetentionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AggressiveTileRetentionEnabled)));
        defaults.get().set(WebPreferencesKey::allowContentSecurityPolicySourceStarToMatchAnyProtocolKey(), Value(bool(DEFAULT_VALUE_FOR_AllowContentSecurityPolicySourceStarToMatchAnyProtocol)));
        defaults.get().set(WebPreferencesKey::allowDisplayOfInsecureContentKey(), Value(bool(DEFAULT_VALUE_FOR_AllowDisplayOfInsecureContent)));
        defaults.get().set(WebPreferencesKey::allowFileAccessFromFileURLsKey(), Value(bool(DEFAULT_VALUE_FOR_AllowFileAccessFromFileURLs)));
        defaults.get().set(WebPreferencesKey::lowPowerVideoAudioBufferSizeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LowPowerVideoAudioBufferSizeEnabled)));
        defaults.get().set(WebPreferencesKey::allowMultiElementImplicitSubmissionKey(), Value(bool(DEFAULT_VALUE_FOR_AllowMultiElementImplicitSubmission)));
#if ENABLE(MEDIA_SOURCE)
        defaults.get().set(WebPreferencesKey::managedMediaSourceHighThresholdKey(), Value(double(DEFAULT_VALUE_FOR_ManagedMediaSourceHighThreshold)));
#endif
        defaults.get().set(WebPreferencesKey::allowRunningOfInsecureContentKey(), Value(bool(DEFAULT_VALUE_FOR_AllowRunningOfInsecureContent)));
        defaults.get().set(WebPreferencesKey::allowTestOnlyIPCKey(), Value(bool(DEFAULT_VALUE_FOR_AllowTestOnlyIPC)));
#if ENABLE(MEDIA_SOURCE)
        defaults.get().set(WebPreferencesKey::managedMediaSourceLowThresholdKey(), Value(double(DEFAULT_VALUE_FOR_ManagedMediaSourceLowThreshold)));
#endif
#if ENABLE(MATHML)
        defaults.get().set(WebPreferencesKey::mathMLEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MathMLEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::maxParseDurationKey(), Value(double(DEFAULT_VALUE_FOR_MaxParseDuration)));
        defaults.get().set(WebPreferencesKey::mediaAudioCodecIDsAllowedInLockdownModeKey(), Value(DEFAULT_VALUE_FOR_MediaAudioCodecIDsAllowedInLockdownMode));
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
        defaults.get().set(WebPreferencesKey::allowsAirPlayForMediaPlaybackKey(), Value(bool(DEFAULT_VALUE_FOR_AllowsAirPlayForMediaPlayback)));
#endif
        defaults.get().set(WebPreferencesKey::allowsInlineMediaPlaybackKey(), Value(bool(DEFAULT_VALUE_FOR_AllowsInlineMediaPlayback)));
        defaults.get().set(WebPreferencesKey::allowsInlineMediaPlaybackAfterFullscreenKey(), Value(bool(DEFAULT_VALUE_FOR_AllowsInlineMediaPlaybackAfterFullscreen)));
        defaults.get().set(WebPreferencesKey::allowsPictureInPictureMediaPlaybackKey(), Value(bool(DEFAULT_VALUE_FOR_AllowsPictureInPictureMediaPlayback)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::alternateFullScreenControlDesignEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AlternateFullScreenControlDesignEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::webSocketEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebSocketEnabled)));
        defaults.get().set(WebPreferencesKey::mediaCapabilitiesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaCapabilitiesEnabled)));
        defaults.get().set(WebPreferencesKey::webSecurityEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebSecurityEnabled)));
        defaults.get().set(WebPreferencesKey::animatedImageAsyncDecodingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AnimatedImageAsyncDecodingEnabled)));
        defaults.get().set(WebPreferencesKey::layoutViewportHeightExpansionFactorKey(), Value(double(DEFAULT_VALUE_FOR_LayoutViewportHeightExpansionFactor)));
        defaults.get().set(WebPreferencesKey::layoutFallbackWidthKey(), Value(uint32_t(DEFAULT_VALUE_FOR_LayoutFallbackWidth)));
        defaults.get().set(WebPreferencesKey::appleMailPaginationQuirkEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AppleMailPaginationQuirkEnabled)));
#if ENABLE(APPLE_PAY)
        defaults.get().set(WebPreferencesKey::applePayCapabilityDisclosureAllowedKey(), Value(bool(DEFAULT_VALUE_FOR_ApplePayCapabilityDisclosureAllowed)));
#endif
#if ENABLE(APPLE_PAY)
        defaults.get().set(WebPreferencesKey::applePayEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ApplePayEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::largeImageAsyncDecodingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LargeImageAsyncDecodingEnabled)));
        defaults.get().set(WebPreferencesKey::mediaCaptionFormatTypesAllowedInLockdownModeKey(), Value(DEFAULT_VALUE_FOR_MediaCaptionFormatTypesAllowedInLockdownMode));
        defaults.get().set(WebPreferencesKey::javaScriptRuntimeFlagsKey(), Value(uint32_t(DEFAULT_VALUE_FOR_JavaScriptRuntimeFlags)));
        defaults.get().set(WebPreferencesKey::asynchronousSpellCheckingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AsynchronousSpellCheckingEnabled)));
        defaults.get().set(WebPreferencesKey::javaScriptMarkupEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_JavaScriptMarkupEnabled)));
        defaults.get().set(WebPreferencesKey::mediaCodecTypesAllowedInLockdownModeKey(), Value(DEFAULT_VALUE_FOR_MediaCodecTypesAllowedInLockdownMode));
        defaults.get().set(WebPreferencesKey::audioControlsScaleWithPageZoomKey(), Value(bool(DEFAULT_VALUE_FOR_AudioControlsScaleWithPageZoom)));
        defaults.get().set(WebPreferencesKey::javaScriptCanOpenWindowsAutomaticallyKey(), Value(bool(DEFAULT_VALUE_FOR_JavaScriptCanOpenWindowsAutomatically)));
        defaults.get().set(WebPreferencesKey::authorAndUserStylesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AuthorAndUserStylesEnabled)));
#if ENABLE(WEB_AUDIO)
        defaults.get().set(WebPreferencesKey::webAudioEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAudioEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::javaScriptCanAccessClipboardKey(), Value(bool(DEFAULT_VALUE_FOR_JavaScriptCanAccessClipboard)));
        defaults.get().set(WebPreferencesKey::wantsBalancedSetDefersLoadingBehaviorKey(), Value(bool(DEFAULT_VALUE_FOR_WantsBalancedSetDefersLoadingBehavior)));
        defaults.get().set(WebPreferencesKey::visualViewportEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VisualViewportEnabled)));
        defaults.get().set(WebPreferencesKey::visibleDebugOverlayRegionsKey(), Value(uint32_t(DEFAULT_VALUE_FOR_VisibleDebugOverlayRegions)));
#if ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::videoQualityIncludesDisplayCompositingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VideoQualityIncludesDisplayCompositingEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::backspaceKeyNavigationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_BackspaceKeyNavigationEnabled)));
        defaults.get().set(WebPreferencesKey::mediaContainerTypesAllowedInLockdownModeKey(), Value(DEFAULT_VALUE_FOR_MediaContainerTypesAllowedInLockdownMode));
        defaults.get().set(WebPreferencesKey::mediaContentTypesRequiringHardwareSupportKey(), Value(DEFAULT_VALUE_FOR_MediaContentTypesRequiringHardwareSupport));
        defaults.get().set(WebPreferencesKey::videoPresentationModeAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VideoPresentationModeAPIEnabled)));
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
        defaults.get().set(WebPreferencesKey::mediaControlsContextMenusEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaControlsContextMenusEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::videoPresentationManagerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VideoPresentationManagerEnabled)));
        defaults.get().set(WebPreferencesKey::mediaControlsScaleWithPageZoomKey(), Value(bool(DEFAULT_VALUE_FOR_MediaControlsScaleWithPageZoom)));
#if ENABLE(FULLSCREEN_API)
        defaults.get().set(WebPreferencesKey::videoFullscreenRequiresElementFullscreenKey(), Value(bool(DEFAULT_VALUE_FOR_VideoFullscreenRequiresElementFullscreen)));
#endif
        defaults.get().set(WebPreferencesKey::mediaDataLoadsAutomaticallyKey(), Value(bool(DEFAULT_VALUE_FOR_MediaDataLoadsAutomatically)));
        defaults.get().set(WebPreferencesKey::mediaPreferredFullscreenWidthKey(), Value(double(DEFAULT_VALUE_FOR_MediaPreferredFullscreenWidth)));
        defaults.get().set(WebPreferencesKey::mediaPreloadingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaPreloadingEnabled)));
        defaults.get().set(WebPreferencesKey::invisibleAutoplayNotPermittedKey(), Value(bool(DEFAULT_VALUE_FOR_InvisibleAutoplayNotPermitted)));
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::interruptVideoOnPageVisibilityChangeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InterruptVideoOnPageVisibilityChangeEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::interruptAudioOnPageVisibilityChangeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InterruptAudioOnPageVisibilityChangeEnabled)));
#endif
#if ENABLE(VP9)
        defaults.get().set(WebPreferencesKey::vp9DecoderEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VP9DecoderEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::mediaUserGestureInheritsFromDocumentKey(), Value(bool(DEFAULT_VALUE_FOR_MediaUserGestureInheritsFromDocument)));
        defaults.get().set(WebPreferencesKey::mediaVideoCodecIDsAllowedInLockdownModeKey(), Value(DEFAULT_VALUE_FOR_MediaVideoCodecIDsAllowedInLockdownMode));
        defaults.get().set(WebPreferencesKey::interactionRegionMinimumCornerRadiusKey(), Value(double(DEFAULT_VALUE_FOR_InteractionRegionMinimumCornerRadius)));
        defaults.get().set(WebPreferencesKey::interactionRegionInlinePaddingKey(), Value(double(DEFAULT_VALUE_FOR_InteractionRegionInlinePadding)));
        defaults.get().set(WebPreferencesKey::inspectorWindowFrameKey(), Value(DEFAULT_VALUE_FOR_InspectorWindowFrame));
        defaults.get().set(WebPreferencesKey::inspectorSupportsShowingCertificateKey(), Value(bool(DEFAULT_VALUE_FOR_InspectorSupportsShowingCertificate)));
        defaults.get().set(WebPreferencesKey::inspectorStartsAttachedKey(), Value(bool(DEFAULT_VALUE_FOR_InspectorStartsAttached)));
        defaults.get().set(WebPreferencesKey::inspectorMaximumResourcesContentSizeKey(), Value(uint32_t(DEFAULT_VALUE_FOR_InspectorMaximumResourcesContentSize)));
        defaults.get().set(WebPreferencesKey::inspectorAttachmentSideKey(), Value(uint32_t(DEFAULT_VALUE_FOR_InspectorAttachmentSide)));
        defaults.get().set(WebPreferencesKey::inspectorAttachedWidthKey(), Value(uint32_t(DEFAULT_VALUE_FOR_InspectorAttachedWidth)));
        defaults.get().set(WebPreferencesKey::inspectorAttachedHeightKey(), Value(uint32_t(DEFAULT_VALUE_FOR_InspectorAttachedHeight)));
        defaults.get().set(WebPreferencesKey::minimumFontSizeKey(), Value(double(DEFAULT_VALUE_FOR_MinimumFontSize)));
        defaults.get().set(WebPreferencesKey::minimumLogicalFontSizeKey(), Value(double(DEFAULT_VALUE_FOR_MinimumLogicalFontSize)));
#if ENABLE(TEXT_AUTOSIZING)
        defaults.get().set(WebPreferencesKey::minimumZoomFontSizeKey(), Value(double(DEFAULT_VALUE_FOR_MinimumZoomFontSize)));
#endif
        defaults.get().set(WebPreferencesKey::mockCaptureDevicesPromptEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MockCaptureDevicesPromptEnabled)));
        defaults.get().set(WebPreferencesKey::mockScrollbarsControllerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MockScrollbarsControllerEnabled)));
        defaults.get().set(WebPreferencesKey::mockScrollbarsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MockScrollbarsEnabled)));
        defaults.get().set(WebPreferencesKey::inlineMediaPlaybackRequiresPlaysInlineAttributeKey(), Value(bool(DEFAULT_VALUE_FOR_InlineMediaPlaybackRequiresPlaysInlineAttribute)));
        defaults.get().set(WebPreferencesKey::incrementalRenderingSuppressionTimeoutKey(), Value(double(DEFAULT_VALUE_FOR_IncrementalRenderingSuppressionTimeout)));
#if HAVE(INCREMENTAL_PDF_APIS)
        defaults.get().set(WebPreferencesKey::incrementalPDFLoadingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IncrementalPDFLoadingEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::incompleteImageBorderEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IncompleteImageBorderEnabled)));
        defaults.get().set(WebPreferencesKey::needsAdobeFrameReloadingQuirkKey(), Value(bool(DEFAULT_VALUE_FOR_NeedsAdobeFrameReloadingQuirk)));
        defaults.get().set(WebPreferencesKey::inactiveMediaCaptureStreamRepromptIntervalInMinutesKey(), Value(double(DEFAULT_VALUE_FOR_InactiveMediaCaptureStreamRepromptIntervalInMinutes)));
        defaults.get().set(WebPreferencesKey::needsFrameNameFallbackToIdQuirkKey(), Value(bool(DEFAULT_VALUE_FOR_NeedsFrameNameFallbackToIdQuirk)));
        defaults.get().set(WebPreferencesKey::needsKeyboardEventDisambiguationQuirksKey(), Value(bool(DEFAULT_VALUE_FOR_NeedsKeyboardEventDisambiguationQuirks)));
#if PLATFORM(COCOA)
        defaults.get().set(WebPreferencesKey::pdfPluginEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PDFPluginEnabled)));
#endif
#if PLATFORM(COCOA)
        defaults.get().set(WebPreferencesKey::pdfPluginHUDEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PDFPluginHUDEnabled)));
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
        defaults.get().set(WebPreferencesKey::pdfPluginPageNumberIndicatorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PDFPluginPageNumberIndicatorEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::passiveTouchListenersAsDefaultOnDocumentKey(), Value(bool(DEFAULT_VALUE_FOR_PassiveTouchListenersAsDefaultOnDocument)));
        defaults.get().set(WebPreferencesKey::passwordEchoDurationKey(), Value(double(DEFAULT_VALUE_FOR_PasswordEchoDuration)));
        defaults.get().set(WebPreferencesKey::passwordEchoEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PasswordEchoEnabled)));
        defaults.get().set(WebPreferencesKey::pictographFontFamilyKey(), Value(DEFAULT_VALUE_FOR_PictographFontFamily));
#if ENABLE(PICTURE_IN_PICTURE_API)
        defaults.get().set(WebPreferencesKey::pictureInPictureAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PictureInPictureAPIEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::pitchCorrectionAlgorithmKey(), Value(uint32_t(DEFAULT_VALUE_FOR_PitchCorrectionAlgorithm)));
        defaults.get().set(WebPreferencesKey::punchOutWhiteBackgroundsInDarkModeKey(), Value(bool(DEFAULT_VALUE_FOR_PunchOutWhiteBackgroundsInDarkMode)));
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
        defaults.get().set(WebPreferencesKey::requiresPageVisibilityForVideoToBeNowPlayingKey(), Value(bool(DEFAULT_VALUE_FOR_RequiresPageVisibilityForVideoToBeNowPlaying)));
#endif
        defaults.get().set(WebPreferencesKey::requiresPageVisibilityToPlayAudioKey(), Value(bool(DEFAULT_VALUE_FOR_RequiresPageVisibilityToPlayAudio)));
        defaults.get().set(WebPreferencesKey::hiddenPageCSSAnimationSuspensionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_HiddenPageCSSAnimationSuspensionEnabled)));
        defaults.get().set(WebPreferencesKey::requiresUserGestureForAudioPlaybackKey(), Value(bool(DEFAULT_VALUE_FOR_RequiresUserGestureForAudioPlayback)));
        defaults.get().set(WebPreferencesKey::requiresUserGestureForMediaPlaybackKey(), Value(bool(DEFAULT_VALUE_FOR_RequiresUserGestureForMediaPlayback)));
        defaults.get().set(WebPreferencesKey::requiresUserGestureForVideoPlaybackKey(), Value(bool(DEFAULT_VALUE_FOR_RequiresUserGestureForVideoPlayback)));
        defaults.get().set(WebPreferencesKey::requiresUserGestureToLoadVideoKey(), Value(bool(DEFAULT_VALUE_FOR_RequiresUserGestureToLoadVideo)));
        defaults.get().set(WebPreferencesKey::usesSingleWebProcessKey(), Value(bool(DEFAULT_VALUE_FOR_UsesSingleWebProcess)));
#if HAVE(RUBBER_BANDING)
        defaults.get().set(WebPreferencesKey::rubberBandingForSubScrollableRegionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_RubberBandingForSubScrollableRegionsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::sampledPageTopColorMaxDifferenceKey(), Value(double(DEFAULT_VALUE_FOR_SampledPageTopColorMaxDifference)));
        defaults.get().set(WebPreferencesKey::sampledPageTopColorMinHeightKey(), Value(double(DEFAULT_VALUE_FOR_SampledPageTopColorMinHeight)));
        defaults.get().set(WebPreferencesKey::usesEncodingDetectorKey(), Value(bool(DEFAULT_VALUE_FOR_UsesEncodingDetector)));
        defaults.get().set(WebPreferencesKey::sansSerifFontFamilyKey(), Value(DEFAULT_VALUE_FOR_SansSerifFontFamily));
        defaults.get().set(WebPreferencesKey::selectTrailingWhitespaceEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SelectTrailingWhitespaceEnabled)));
        defaults.get().set(WebPreferencesKey::serifFontFamilyKey(), Value(DEFAULT_VALUE_FOR_SerifFontFamily));
        defaults.get().set(WebPreferencesKey::usesBackForwardCacheKey(), Value(bool(DEFAULT_VALUE_FOR_UsesBackForwardCache)));
        defaults.get().set(WebPreferencesKey::userInterfaceDirectionPolicyKey(), Value(uint32_t(DEFAULT_VALUE_FOR_UserInterfaceDirectionPolicy)));
        defaults.get().set(WebPreferencesKey::caretBrowsingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CaretBrowsingEnabled)));
        defaults.get().set(WebPreferencesKey::useSystemAppearanceKey(), Value(bool(DEFAULT_VALUE_FOR_UseSystemAppearance)));
#if ENABLE(SERVICE_CONTROLS)
        defaults.get().set(WebPreferencesKey::serviceControlsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ServiceControlsEnabled)));
#endif
#if USE(GSTREAMER)
        defaults.get().set(WebPreferencesKey::isGStreamerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GStreamerEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::serviceWorkerEntitlementDisabledForTestingKey(), Value(bool(DEFAULT_VALUE_FOR_ServiceWorkerEntitlementDisabledForTesting)));
        defaults.get().set(WebPreferencesKey::shouldAllowUserInstalledFontsKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldAllowUserInstalledFonts)));
        defaults.get().set(WebPreferencesKey::colorFilterEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ColorFilterEnabled)));
        defaults.get().set(WebPreferencesKey::usePreHTML5ParserQuirksKey(), Value(bool(DEFAULT_VALUE_FOR_UsePreHTML5ParserQuirks)));
        defaults.get().set(WebPreferencesKey::shouldConvertInvalidURLsToBlankKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldConvertInvalidURLsToBlank)));
        defaults.get().set(WebPreferencesKey::shouldConvertPositionStyleOnCopyKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldConvertPositionStyleOnCopy)));
        defaults.get().set(WebPreferencesKey::shouldDecidePolicyBeforeLoadingQuickLookPreviewKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldDecidePolicyBeforeLoadingQuickLookPreview)));
#if ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::shouldDisplayCaptionsKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldDisplayCaptions)));
#endif
#if ENABLE(CONTENT_CHANGE_OBSERVER)
        defaults.get().set(WebPreferencesKey::contentChangeObserverEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ContentChangeObserverEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::contentDispositionAttachmentSandboxEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ContentDispositionAttachmentSandboxEnabled)));
        defaults.get().set(WebPreferencesKey::forceWebGLUsesLowPowerKey(), Value(bool(DEFAULT_VALUE_FOR_ForceWebGLUsesLowPower)));
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
        defaults.get().set(WebPreferencesKey::contextMenuQRCodeDetectionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ContextMenuQRCodeDetectionEnabled)));
#endif
#if ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::shouldDisplaySubtitlesKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldDisplaySubtitles)));
#endif
        defaults.get().set(WebPreferencesKey::forceFTPDirectoryListingsKey(), Value(bool(DEFAULT_VALUE_FOR_ForceFTPDirectoryListings)));
        defaults.get().set(WebPreferencesKey::forceCompositingModeKey(), Value(bool(DEFAULT_VALUE_FOR_ForceCompositingMode)));
#if ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::shouldDisplayTextDescriptionsKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldDisplayTextDescriptions)));
#endif
#if ENABLE(TEXT_AUTOSIZING)
        defaults.get().set(WebPreferencesKey::shouldEnableTextAutosizingBoostKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldEnableTextAutosizingBoost)));
#endif
        defaults.get().set(WebPreferencesKey::useImageDocumentForSubframePDFKey(), Value(bool(DEFAULT_VALUE_FOR_UseImageDocumentForSubframePDF)));
        defaults.get().set(WebPreferencesKey::fixedFontFamilyKey(), Value(DEFAULT_VALUE_FOR_FixedFontFamily));
        defaults.get().set(WebPreferencesKey::shouldIgnoreMetaViewportKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldIgnoreMetaViewport)));
        defaults.get().set(WebPreferencesKey::shouldPrintBackgroundsKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldPrintBackgrounds)));
        defaults.get().set(WebPreferencesKey::cursiveFontFamilyKey(), Value(DEFAULT_VALUE_FOR_CursiveFontFamily));
        defaults.get().set(WebPreferencesKey::shouldRespectImageOrientationKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldRespectImageOrientation)));
        defaults.get().set(WebPreferencesKey::shouldRestrictBaseURLSchemesKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldRestrictBaseURLSchemes)));
        defaults.get().set(WebPreferencesKey::shouldSuppressTextInputFromEditingDuringProvisionalNavigationKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldSuppressTextInputFromEditingDuringProvisionalNavigation)));
        defaults.get().set(WebPreferencesKey::fantasyFontFamilyKey(), Value(DEFAULT_VALUE_FOR_FantasyFontFamily));
        defaults.get().set(WebPreferencesKey::domPasteAllowedKey(), Value(bool(DEFAULT_VALUE_FOR_DOMPasteAllowed)));
        defaults.get().set(WebPreferencesKey::shouldUseServiceWorkerShortTimeoutKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldUseServiceWorkerShortTimeout)));
        defaults.get().set(WebPreferencesKey::ftpDirectoryTemplatePathKey(), Value(DEFAULT_VALUE_FOR_FTPDirectoryTemplatePath));
#if ENABLE(DATA_DETECTION)
        defaults.get().set(WebPreferencesKey::dataDetectorTypesKey(), Value(uint32_t(DEFAULT_VALUE_FOR_DataDetectorTypes)));
#endif
#if HAVE(APP_SSO)
        defaults.get().set(WebPreferencesKey::isExtensibleSSOEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ExtensibleSSOEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::treatsAnyTextCSSLinkAsStylesheetKey(), Value(bool(DEFAULT_VALUE_FOR_TreatsAnyTextCSSLinkAsStylesheet)));
        defaults.get().set(WebPreferencesKey::linkPreloadEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LinkPreloadEnabled)));
        defaults.get().set(WebPreferencesKey::showsToolTipOverTruncatedTextKey(), Value(bool(DEFAULT_VALUE_FOR_ShowsToolTipOverTruncatedText)));
        defaults.get().set(WebPreferencesKey::threadedScrollingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ThreadedScrollingEnabled)));
        defaults.get().set(WebPreferencesKey::defaultFixedFontSizeKey(), Value(double(DEFAULT_VALUE_FOR_DefaultFixedFontSize)));
        defaults.get().set(WebPreferencesKey::defaultFontSizeKey(), Value(double(DEFAULT_VALUE_FOR_DefaultFontSize)));
        defaults.get().set(WebPreferencesKey::defaultTextEncodingNameKey(), Value(DEFAULT_VALUE_FOR_DefaultTextEncodingName));
        defaults.get().set(WebPreferencesKey::textInteractionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TextInteractionEnabled)));
        defaults.get().set(WebPreferencesKey::textExtractionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TextExtractionEnabled)));
#if ENABLE(TEXT_AUTOSIZING)
        defaults.get().set(WebPreferencesKey::textAutosizingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TextAutosizingEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::developerExtrasEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DeveloperExtrasEnabled)));
        defaults.get().set(WebPreferencesKey::deviceHeightKey(), Value(uint32_t(DEFAULT_VALUE_FOR_DeviceHeight)));
#if ENABLE(DEVICE_ORIENTATION)
        defaults.get().set(WebPreferencesKey::deviceOrientationEventEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DeviceOrientationEventEnabled)));
#endif
#if ENABLE(DEVICE_ORIENTATION)
        defaults.get().set(WebPreferencesKey::deviceOrientationPermissionAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DeviceOrientationPermissionAPIEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::deviceWidthKey(), Value(uint32_t(DEFAULT_VALUE_FOR_DeviceWidth)));
        defaults.get().set(WebPreferencesKey::showsURLsInToolTipsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ShowsURLsInToolTipsEnabled)));
        defaults.get().set(WebPreferencesKey::textAreasAreResizableKey(), Value(bool(DEFAULT_VALUE_FOR_TextAreasAreResizable)));
        defaults.get().set(WebPreferencesKey::temporaryTileCohortRetentionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TemporaryTileCohortRetentionEnabled)));
        defaults.get().set(WebPreferencesKey::telephoneNumberParsingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TelephoneNumberParsingEnabled)));
        defaults.get().set(WebPreferencesKey::shrinksStandaloneImagesToFitKey(), Value(bool(DEFAULT_VALUE_FOR_ShrinksStandaloneImagesToFit)));
        defaults.get().set(WebPreferencesKey::disabledAdaptationsMetaTagEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DisabledAdaptationsMetaTagEnabled)));
        defaults.get().set(WebPreferencesKey::downloadAttributeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DownloadAttributeEnabled)));
        defaults.get().set(WebPreferencesKey::tabsToLinksKey(), Value(bool(DEFAULT_VALUE_FOR_TabsToLinks)));
        defaults.get().set(WebPreferencesKey::editableLinkBehaviorKey(), Value(uint32_t(DEFAULT_VALUE_FOR_EditableLinkBehavior)));
#if USE(SYSTEM_PREVIEW)
        defaults.get().set(WebPreferencesKey::systemPreviewEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SystemPreviewEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::systemLayoutDirectionKey(), Value(uint32_t(DEFAULT_VALUE_FOR_SystemLayoutDirection)));
        defaults.get().set(WebPreferencesKey::suppressesIncrementalRenderingKey(), Value(bool(DEFAULT_VALUE_FOR_SuppressesIncrementalRendering)));
        defaults.get().set(WebPreferencesKey::standardFontFamilyKey(), Value(DEFAULT_VALUE_FOR_StandardFontFamily));
        defaults.get().set(WebPreferencesKey::enableInheritURIQueryComponentKey(), Value(bool(DEFAULT_VALUE_FOR_EnableInheritURIQueryComponent)));
#if ENABLE(ENCRYPTED_MEDIA)
        defaults.get().set(WebPreferencesKey::encryptedMediaAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_EncryptedMediaAPIEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::standaloneKey(), Value(bool(DEFAULT_VALUE_FOR_Standalone)));
        defaults.get().set(WebPreferencesKey::smartInsertDeleteEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SmartInsertDeleteEnabled)));
        defaults.get().set(WebPreferencesKey::spatialNavigationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SpatialNavigationEnabled)));
#if ENABLE(MEDIA_SOURCE)
        defaults.get().set(WebPreferencesKey::sourceBufferChangeTypeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SourceBufferChangeTypeEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::targetTextPseudoElementEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TargetTextPseudoElementEnabled)));
        defaults.get().set(WebPreferencesKey::thumbAndTrackPseudoElementsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ThumbAndTrackPseudoElementsEnabled)));
        defaults.get().set(WebPreferencesKey::linkDNSPrefetchEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LinkDNSPrefetchEnabled)));
        defaults.get().set(WebPreferencesKey::selectShowPickerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SelectShowPickerEnabled)));
        defaults.get().set(WebPreferencesKey::pageAtRuleMarginDescriptorsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PageAtRuleMarginDescriptorsEnabled)));
#if USE(AVFOUNDATION)
        defaults.get().set(WebPreferencesKey::isAVFoundationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AVFoundationEnabled)));
#endif
#if HAVE(AVKIT_CONTENT_SOURCE)
        defaults.get().set(WebPreferencesKey::isAVKitContentSourceEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AVKitContentSourceEnabled)));
#endif
#if USE(CORE_IMAGE)
        defaults.get().set(WebPreferencesKey::acceleratedFiltersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AcceleratedFiltersEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::accessHandleEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AccessHandleEnabled)));
        defaults.get().set(WebPreferencesKey::domTestingAPIsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DOMTestingAPIsEnabled)));
        defaults.get().set(WebPreferencesKey::allowMediaContentTypesRequiringHardwareSupportAsFallbackKey(), Value(bool(DEFAULT_VALUE_FOR_AllowMediaContentTypesRequiringHardwareSupportAsFallback)));
        defaults.get().set(WebPreferencesKey::allowPrivacySensitiveOperationsInNonPersistentDataStoresKey(), Value(bool(DEFAULT_VALUE_FOR_AllowPrivacySensitiveOperationsInNonPersistentDataStores)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::allowViewportShrinkToFitContentKey(), Value(bool(DEFAULT_VALUE_FOR_AllowViewportShrinkToFitContent)));
#endif
#if ENABLE(WEBGL)
        defaults.get().set(WebPreferencesKey::allowWebGLInWorkersKey(), Value(bool(DEFAULT_VALUE_FOR_AllowWebGLInWorkers)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::perElementSpeakerSelectionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PerElementSpeakerSelectionEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::exposeSpeakersWithoutMicrophoneEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ExposeSpeakersWithoutMicrophoneEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::exposeSpeakersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ExposeSpeakersEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::allowTopNavigationToDataURLsKey(), Value(bool(DEFAULT_VALUE_FOR_AllowTopNavigationToDataURLs)));
        defaults.get().set(WebPreferencesKey::allowUniversalAccessFromFileURLsKey(), Value(bool(DEFAULT_VALUE_FOR_AllowUniversalAccessFromFileURLs)));
#if ENABLE(WEB_ARCHIVE)
        defaults.get().set(WebPreferencesKey::alwaysAllowLocalWebarchiveKey(), Value(bool(DEFAULT_VALUE_FOR_AlwaysAllowLocalWebarchive)));
#endif
#if ENABLE(VP9)
        defaults.get().set(WebPreferencesKey::sWVPDecodersAlwaysEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SWVPDecodersAlwaysEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::appBadgeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AppBadgeEnabled)));
#if ENABLE(APP_HIGHLIGHTS)
        defaults.get().set(WebPreferencesKey::appHighlightsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AppHighlightsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::asyncFrameScrollingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AsyncFrameScrollingEnabled)));
        defaults.get().set(WebPreferencesKey::asyncOverflowScrollingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AsyncOverflowScrollingEnabled)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::useAsyncUIKitInteractionsKey(), Value(bool(DEFAULT_VALUE_FOR_UseAsyncUIKitInteractions)));
#endif
        defaults.get().set(WebPreferencesKey::asyncClipboardAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AsyncClipboardAPIEnabled)));
#if ENABLE(ATTACHMENT_ELEMENT)
        defaults.get().set(WebPreferencesKey::attachmentElementEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AttachmentElementEnabled)));
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
        defaults.get().set(WebPreferencesKey::attachmentWideLayoutEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AttachmentWideLayoutEnabled)));
#endif
#if ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::extendedAudioDescriptionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ExtendedAudioDescriptionsEnabled)));
#endif
#if ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::audioDescriptionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AudioDescriptionsEnabled)));
#endif
#if ENABLE(DOM_AUDIO_SESSION)
        defaults.get().set(WebPreferencesKey::domAudioSessionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DOMAudioSessionEnabled)));
#endif
#if ENABLE(DOM_AUDIO_SESSION)
        defaults.get().set(WebPreferencesKey::domAudioSessionFullEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DOMAudioSessionFullEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidthKey(), Value(bool(DEFAULT_VALUE_FOR_AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth)));
        defaults.get().set(WebPreferencesKey::beaconAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_BeaconAPIEnabled)));
        defaults.get().set(WebPreferencesKey::bidiContentAwarePasteEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_BidiContentAwarePasteEnabled)));
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        defaults.get().set(WebPreferencesKey::blockFontServiceInWebContentSandboxKey(), Value(bool(DEFAULT_VALUE_FOR_BlockFontServiceInWebContentSandbox)));
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        defaults.get().set(WebPreferencesKey::blockIconServicesInWebContentSandboxKey(), Value(bool(DEFAULT_VALUE_FOR_BlockIconServicesInWebContentSandbox)));
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        defaults.get().set(WebPreferencesKey::blockMobileAssetInWebContentSandboxKey(), Value(bool(DEFAULT_VALUE_FOR_BlockMobileAssetInWebContentSandbox)));
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(IOS)
        defaults.get().set(WebPreferencesKey::blockMobileGestaltInWebContentSandboxKey(), Value(bool(DEFAULT_VALUE_FOR_BlockMobileGestaltInWebContentSandbox)));
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
        defaults.get().set(WebPreferencesKey::blockOpenDirectoryInWebContentSandboxKey(), Value(bool(DEFAULT_VALUE_FOR_BlockOpenDirectoryInWebContentSandbox)));
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        defaults.get().set(WebPreferencesKey::blockWebInspectorInWebContentSandboxKey(), Value(bool(DEFAULT_VALUE_FOR_BlockWebInspectorInWebContentSandbox)));
#endif
        defaults.get().set(WebPreferencesKey::broadcastChannelEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_BroadcastChannelEnabled)));
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
        defaults.get().set(WebPreferencesKey::builtInNotificationsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_BuiltInNotificationsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::css3DTransformBackfaceVisibilityInteroperabilityEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSS3DTransformBackfaceVisibilityInteroperabilityEnabled)));
        defaults.get().set(WebPreferencesKey::cssCounterStyleAtRuleImageSymbolsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSCounterStyleAtRuleImageSymbolsEnabled)));
        defaults.get().set(WebPreferencesKey::accentColorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AccentColorEnabled)));
        defaults.get().set(WebPreferencesKey::cssAnchorPositioningEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSAnchorPositioningEnabled)));
        defaults.get().set(WebPreferencesKey::cssAnchorPositioningPositionVisibilityEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSAnchorPositioningPositionVisibilityEnabled)));
        defaults.get().set(WebPreferencesKey::devolvableWidgetsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DevolvableWidgetsEnabled)));
        defaults.get().set(WebPreferencesKey::cssInputSecurityEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSInputSecurityEnabled)));
        defaults.get().set(WebPreferencesKey::masonryEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MasonryEnabled)));
        defaults.get().set(WebPreferencesKey::overscrollBehaviorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_OverscrollBehaviorEnabled)));
        defaults.get().set(WebPreferencesKey::cssPaintingAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSPaintingAPIEnabled)));
        defaults.get().set(WebPreferencesKey::cssRhythmicSizingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSRhythmicSizingEnabled)));
        defaults.get().set(WebPreferencesKey::cssScrollAnchoringEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSScrollAnchoringEnabled)));
        defaults.get().set(WebPreferencesKey::springTimingFunctionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SpringTimingFunctionEnabled)));
        defaults.get().set(WebPreferencesKey::cssTreeCountingFunctionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTreeCountingFunctionsEnabled)));
        defaults.get().set(WebPreferencesKey::cssTypedOMColorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTypedOMColorEnabled)));
        defaults.get().set(WebPreferencesKey::cssURLModifiersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSURLModifiersEnabled)));
        defaults.get().set(WebPreferencesKey::cssURLIntegrityModifierEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSURLIntegrityModifierEnabled)));
        defaults.get().set(WebPreferencesKey::cssUnprefixedBackdropFilterEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSUnprefixedBackdropFilterEnabled)));
        defaults.get().set(WebPreferencesKey::cssAppearanceBaseEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSAppearanceBaseEnabled)));
        defaults.get().set(WebPreferencesKey::cssAxisRelativePositionKeywordsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSAxisRelativePositionKeywordsEnabled)));
        defaults.get().set(WebPreferencesKey::cssBackgroundClipBorderAreaEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSBackgroundClipBorderAreaEnabled)));
        defaults.get().set(WebPreferencesKey::cssColorLayersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSColorLayersEnabled)));
        defaults.get().set(WebPreferencesKey::cssContrastColorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSContrastColorEnabled)));
        defaults.get().set(WebPreferencesKey::cssCornerShapeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSCornerShapeEnabled)));
        defaults.get().set(WebPreferencesKey::cssDPropertyEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSDPropertyEnabled)));
        defaults.get().set(WebPreferencesKey::cssDynamicRangeLimitMixEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSDynamicRangeLimitMixEnabled)));
        defaults.get().set(WebPreferencesKey::cssConstrainedDynamicRangeLimitEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSConstrainedDynamicRangeLimitEnabled)));
        defaults.get().set(WebPreferencesKey::cssFieldSizingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSFieldSizingEnabled)));
        defaults.get().set(WebPreferencesKey::cssFontVariantEmojiEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSFontVariantEmojiEnabled)));
        defaults.get().set(WebPreferencesKey::cssLineClampEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSLineClampEnabled)));
        defaults.get().set(WebPreferencesKey::cssLineFitEdgeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSLineFitEdgeEnabled)));
        defaults.get().set(WebPreferencesKey::cssProgressFunctionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSProgressFunctionEnabled)));
        defaults.get().set(WebPreferencesKey::cssRandomFunctionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSRandomFunctionEnabled)));
        defaults.get().set(WebPreferencesKey::cssRubyAlignEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSRubyAlignEnabled)));
        defaults.get().set(WebPreferencesKey::cssRubyOverhangEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSRubyOverhangEnabled)));
        defaults.get().set(WebPreferencesKey::cssScrollbarColorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSScrollbarColorEnabled)));
        defaults.get().set(WebPreferencesKey::cssScrollbarGutterEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSScrollbarGutterEnabled)));
        defaults.get().set(WebPreferencesKey::cssScrollbarWidthEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSScrollbarWidthEnabled)));
        defaults.get().set(WebPreferencesKey::cssShapeFunctionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSShapeFunctionEnabled)));
        defaults.get().set(WebPreferencesKey::cssTextAutospaceEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTextAutospaceEnabled)));
        defaults.get().set(WebPreferencesKey::cssTextBoxTrimEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTextBoxTrimEnabled)));
        defaults.get().set(WebPreferencesKey::cssTextGroupAlignEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTextGroupAlignEnabled)));
        defaults.get().set(WebPreferencesKey::cssTextJustifyEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTextJustifyEnabled)));
        defaults.get().set(WebPreferencesKey::cssTextSpacingTrimEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTextSpacingTrimEnabled)));
        defaults.get().set(WebPreferencesKey::cssTextUnderlinePositionLeftRightEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTextUnderlinePositionLeftRightEnabled)));
        defaults.get().set(WebPreferencesKey::cssTextWrapPrettyEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTextWrapPrettyEnabled)));
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
        defaults.get().set(WebPreferencesKey::cssTransformStyleSeparatedEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSTransformStyleSeparatedEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::cacheAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CacheAPIEnabled)));
        defaults.get().set(WebPreferencesKey::canvasColorSpaceEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CanvasColorSpaceEnabled)));
        defaults.get().set(WebPreferencesKey::canvasFiltersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CanvasFiltersEnabled)));
        defaults.get().set(WebPreferencesKey::canvasLayersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CanvasLayersEnabled)));
#if USE(CA) || USE(SKIA)
        defaults.get().set(WebPreferencesKey::canvasUsesAcceleratedDrawingKey(), Value(bool(DEFAULT_VALUE_FOR_CanvasUsesAcceleratedDrawing)));
#endif
        defaults.get().set(WebPreferencesKey::canvasPixelFormatEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CanvasPixelFormatEnabled)));
        defaults.get().set(WebPreferencesKey::childProcessDebuggabilityEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ChildProcessDebuggabilityEnabled)));
        defaults.get().set(WebPreferencesKey::clearSiteDataHTTPHeaderEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ClearSiteDataHTTPHeaderEnabled)));
        defaults.get().set(WebPreferencesKey::clearSiteDataExecutionContextsSupportEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ClearSiteDataExecutionContextsSupportEnabled)));
        defaults.get().set(WebPreferencesKey::closeWatcherEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CloseWatcherEnabled)));
        defaults.get().set(WebPreferencesKey::inputTypeColorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InputTypeColorEnabled)));
        defaults.get().set(WebPreferencesKey::compositingBordersVisibleKey(), Value(bool(DEFAULT_VALUE_FOR_CompositingBordersVisible)));
        defaults.get().set(WebPreferencesKey::compositingRepaintCountersVisibleKey(), Value(bool(DEFAULT_VALUE_FOR_CompositingRepaintCountersVisible)));
        defaults.get().set(WebPreferencesKey::compressionStreamEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CompressionStreamEnabled)));
        defaults.get().set(WebPreferencesKey::contactPickerAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ContactPickerAPIEnabled)));
        defaults.get().set(WebPreferencesKey::contentInsetBackgroundFillEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ContentInsetBackgroundFillEnabled)));
        defaults.get().set(WebPreferencesKey::cookieConsentAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CookieConsentAPIEnabled)));
        defaults.get().set(WebPreferencesKey::cookieStoreManagerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CookieStoreManagerEnabled)));
        defaults.get().set(WebPreferencesKey::cookieStoreAPIExtendedAttributesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CookieStoreAPIExtendedAttributesEnabled)));
        defaults.get().set(WebPreferencesKey::cookieStoreAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CookieStoreAPIEnabled)));
        defaults.get().set(WebPreferencesKey::cookieEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CookieEnabled)));
#if PLATFORM(MAC)
        defaults.get().set(WebPreferencesKey::inputMethodUsesCorrectKeyEventOrderKey(), Value(bool(DEFAULT_VALUE_FOR_InputMethodUsesCorrectKeyEventOrder)));
#endif
        defaults.get().set(WebPreferencesKey::crossDocumentViewTransitionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CrossDocumentViewTransitionsEnabled)));
        defaults.get().set(WebPreferencesKey::crossOriginEmbedderPolicyEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CrossOriginEmbedderPolicyEnabled)));
        defaults.get().set(WebPreferencesKey::crossOriginOpenerPolicyEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CrossOriginOpenerPolicyEnabled)));
        defaults.get().set(WebPreferencesKey::customPasteboardDataEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CustomPasteboardDataEnabled)));
        defaults.get().set(WebPreferencesKey::domPasteAccessRequestsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DOMPasteAccessRequestsEnabled)));
        defaults.get().set(WebPreferencesKey::mutationEventsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MutationEventsEnabled)));
        defaults.get().set(WebPreferencesKey::domTimersThrottlingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DOMTimersThrottlingEnabled)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::zoomOnDoubleTapWhenRootKey(), Value(bool(DEFAULT_VALUE_FOR_ZoomOnDoubleTapWhenRoot)));
#endif
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::alwaysZoomOnDoubleTapKey(), Value(bool(DEFAULT_VALUE_FOR_AlwaysZoomOnDoubleTap)));
#endif
        defaults.get().set(WebPreferencesKey::dataTransferItemsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DataTransferItemsEnabled)));
        defaults.get().set(WebPreferencesKey::dataListElementEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DataListElementEnabled)));
        defaults.get().set(WebPreferencesKey::inputTypeDateEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InputTypeDateEnabled)));
        defaults.get().set(WebPreferencesKey::dateTimeInputsEditableComponentsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DateTimeInputsEditableComponentsEnabled)));
#if ENABLE(DECLARATIVE_WEB_PUSH)
        defaults.get().set(WebPreferencesKey::declarativeWebPushKey(), Value(bool(DEFAULT_VALUE_FOR_DeclarativeWebPush)));
#endif
        defaults.get().set(WebPreferencesKey::shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaintKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint)));
        defaults.get().set(WebPreferencesKey::deprecationReportingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DeprecationReportingEnabled)));
#if ENABLE(MEDIA_SOURCE)
        defaults.get().set(WebPreferencesKey::detachableMediaSourceEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DetachableMediaSourceEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::uAVisualTransitionDetectionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UAVisualTransitionDetectionEnabled)));
        defaults.get().set(WebPreferencesKey::diagnosticLoggingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DiagnosticLoggingEnabled)));
#if ENABLE(WEB_AUTHN)
        defaults.get().set(WebPreferencesKey::digitalCredentialsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DigitalCredentialsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::directoryUploadEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DirectoryUploadEnabled)));
        defaults.get().set(WebPreferencesKey::isThirdPartyCookieBlockingDisabledKey(), Value(bool(DEFAULT_VALUE_FOR_IsThirdPartyCookieBlockingDisabled)));
        defaults.get().set(WebPreferencesKey::isFirstPartyWebsiteDataRemovalDisabledKey(), Value(bool(DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalDisabled)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::disableScreenSizeOverrideKey(), Value(bool(DEFAULT_VALUE_FOR_DisableScreenSizeOverride)));
#endif
        defaults.get().set(WebPreferencesKey::shouldDropNearSuspendedAssertionAfterDelayKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldDropNearSuspendedAssertionAfterDelay)));
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        defaults.get().set(WebPreferencesKey::useCGDisplayListsForDOMRenderingKey(), Value(bool(DEFAULT_VALUE_FOR_UseCGDisplayListsForDOMRendering)));
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        defaults.get().set(WebPreferencesKey::replayCGDisplayListsIntoBackingStoreKey(), Value(bool(DEFAULT_VALUE_FOR_ReplayCGDisplayListsIntoBackingStore)));
#endif
        defaults.get().set(WebPreferencesKey::dynamicSiteInterventionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DynamicSiteInterventionsEnabled)));
        defaults.get().set(WebPreferencesKey::embedElementEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_EmbedElementEnabled)));
#if PLATFORM(MAC)
        defaults.get().set(WebPreferencesKey::enableAccessibilityOnDemandKey(), Value(bool(DEFAULT_VALUE_FOR_EnableAccessibilityOnDemand)));
#endif
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::automaticLiveResizeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AutomaticLiveResizeEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::canvasFingerprintingQuirkEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CanvasFingerprintingQuirkEnabled)));
        defaults.get().set(WebPreferencesKey::enableElementCurrentCSSZoomKey(), Value(bool(DEFAULT_VALUE_FOR_EnableElementCurrentCSSZoom)));
        defaults.get().set(WebPreferencesKey::enumeratingAllNetworkInterfacesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_EnumeratingAllNetworkInterfacesEnabled)));
        defaults.get().set(WebPreferencesKey::enumeratingVisibleNetworkInterfacesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_EnumeratingVisibleNetworkInterfacesEnabled)));
        defaults.get().set(WebPreferencesKey::iceCandidateFilteringEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ICECandidateFilteringEnabled)));
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
        defaults.get().set(WebPreferencesKey::legacyEncryptedMediaAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LegacyEncryptedMediaAPIEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::mockCaptureDevicesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MockCaptureDevicesEnabled)));
#endif
#if ENABLE(MODEL_PROCESS)
        defaults.get().set(WebPreferencesKey::modelProcessEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ModelProcessEnabled)));
#endif
#if ENABLE(PDFJS)
        defaults.get().set(WebPreferencesKey::pdfJSViewerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PDFJSViewerEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::auxclickEventEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AuxclickEventEnabled)));
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
        defaults.get().set(WebPreferencesKey::backgroundWebContentRunningBoardThrottlingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_BackgroundWebContentRunningBoardThrottlingEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::backgroundFetchAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_BackgroundFetchAPIEnabled)));
#if HAVE(SANDBOX_STATE_FLAGS)
        defaults.get().set(WebPreferencesKey::enableDebuggingFeaturesInSandboxKey(), Value(bool(DEFAULT_VALUE_FOR_EnableDebuggingFeaturesInSandbox)));
#endif
#if HAVE(NETWORK_LOADER)
        defaults.get().set(WebPreferencesKey::cFNetworkNetworkLoaderEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CFNetworkNetworkLoaderEnabled)));
#endif
#if HAVE(MACH_BOOTSTRAP_EXTENSION) || HAVE(SANDBOX_STATE_FLAGS)
        defaults.get().set(WebPreferencesKey::experimentalSandboxEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ExperimentalSandboxEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::navigatorUserAgentDataJavaScriptAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_NavigatorUserAgentDataJavaScriptAPIEnabled)));
        defaults.get().set(WebPreferencesKey::blobFileAccessEnforcementEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_BlobFileAccessEnforcementEnabled)));
        defaults.get().set(WebPreferencesKey::enterKeyHintEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_EnterKeyHintEnabled)));
        defaults.get().set(WebPreferencesKey::eventTimingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_EventTimingEnabled)));
        defaults.get().set(WebPreferencesKey::eventHandlerDrivenSmoothKeyboardScrollingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_EventHandlerDrivenSmoothKeyboardScrollingEnabled)));
#if ENABLE(MEDIA_SESSION_COORDINATOR)
        defaults.get().set(WebPreferencesKey::mediaSessionCoordinatorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaSessionCoordinatorEnabled)));
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
        defaults.get().set(WebPreferencesKey::mediaSessionPlaylistEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaSessionPlaylistEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::exposeCaptureDevicesAfterCaptureEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ExposeCaptureDevicesAfterCaptureEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::exposeDefaultSpeakerAsSpecificDeviceEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ExposeDefaultSpeakerAsSpecificDeviceEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::ftpEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FTPEnabled)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::preferFasterClickOverDoubleTapKey(), Value(bool(DEFAULT_VALUE_FOR_PreferFasterClickOverDoubleTap)));
#endif
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::fasterClicksEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FasterClicksEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::fileSystemEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FileSystemEnabled)));
        defaults.get().set(WebPreferencesKey::fileSystemWritableStreamEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FileSystemWritableStreamEnabled)));
        defaults.get().set(WebPreferencesKey::fileReaderAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FileReaderAPIEnabled)));
        defaults.get().set(WebPreferencesKey::filterLinkDecorationByDefaultEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FilterLinkDecorationByDefaultEnabled)));
        defaults.get().set(WebPreferencesKey::forceLockdownFontParserEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ForceLockdownFontParserEnabled)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::forceAlwaysUserScalableKey(), Value(bool(DEFAULT_VALUE_FOR_ForceAlwaysUserScalable)));
#endif
#if ENABLE(FORM_CONTROL_REFRESH)
        defaults.get().set(WebPreferencesKey::formControlRefreshEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FormControlRefreshEnabled)));
#endif
#if ENABLE(CONTENT_EXTENSIONS)
        defaults.get().set(WebPreferencesKey::iFrameResourceMonitoringTestingSettingsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IFrameResourceMonitoringTestingSettingsEnabled)));
#endif
#if ENABLE(CONTENT_EXTENSIONS)
        defaults.get().set(WebPreferencesKey::iFrameResourceMonitoringEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IFrameResourceMonitoringEnabled)));
#endif
#if ENABLE(FULLSCREEN_API)
        defaults.get().set(WebPreferencesKey::fullScreenKeyboardLockKey(), Value(bool(DEFAULT_VALUE_FOR_FullScreenKeyboardLock)));
#endif
#if ENABLE(FULLSCREEN_API)
        defaults.get().set(WebPreferencesKey::fullScreenEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FullScreenEnabled)));
#endif
#if PLATFORM(VISION)
        defaults.get().set(WebPreferencesKey::fullscreenSceneAspectRatioLockingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FullscreenSceneAspectRatioLockingEnabled)));
#endif
#if PLATFORM(VISION)
        defaults.get().set(WebPreferencesKey::fullscreenSceneDimmingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FullscreenSceneDimmingEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::captureAudioInGPUProcessEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CaptureAudioInGPUProcessEnabled)));
#endif
#if ENABLE(GPU_PROCESS)
        defaults.get().set(WebPreferencesKey::blockMediaLayerRehostingInWebContentProcessKey(), Value(bool(DEFAULT_VALUE_FOR_BlockMediaLayerRehostingInWebContentProcess)));
#endif
#if ENABLE(GPU_PROCESS) && !(PLATFORM(GTK) || PLATFORM(WPE))
        defaults.get().set(WebPreferencesKey::useGPUProcessForCanvasRenderingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UseGPUProcessForCanvasRenderingEnabled)));
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::manageCaptureStatusBarInGPUProcessEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ManageCaptureStatusBarInGPUProcessEnabled)));
#endif
#if ENABLE(GPU_PROCESS)
        defaults.get().set(WebPreferencesKey::useGPUProcessForDOMRenderingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UseGPUProcessForDOMRenderingEnabled)));
#endif
#if ENABLE(GPU_PROCESS)
        defaults.get().set(WebPreferencesKey::useGPUProcessForMediaEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UseGPUProcessForMediaEnabled)));
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
        defaults.get().set(WebPreferencesKey::useGPUProcessForDisplayCaptureKey(), Value(bool(DEFAULT_VALUE_FOR_UseGPUProcessForDisplayCapture)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::captureVideoInGPUProcessEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CaptureVideoInGPUProcessEnabled)));
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
        defaults.get().set(WebPreferencesKey::useGPUProcessForWebGLEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UseGPUProcessForWebGLEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCPlatformCodecsInGPUProcessEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCPlatformCodecsInGPUProcessEnabled)));
#endif
#if ENABLE(GAMEPAD)
        defaults.get().set(WebPreferencesKey::gamepadTriggerRumbleEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GamepadTriggerRumbleEnabled)));
#endif
#if ENABLE(GAMEPAD)
        defaults.get().set(WebPreferencesKey::gamepadVibrationActuatorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GamepadVibrationActuatorEnabled)));
#endif
#if ENABLE(GAMEPAD)
        defaults.get().set(WebPreferencesKey::gamepadsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GamepadsEnabled)));
#endif
#if ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::genericCueAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GenericCueAPIEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::geolocationAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GeolocationAPIEnabled)));
#if USE(GRAPHICS_CONTEXT_FILTERS)
        defaults.get().set(WebPreferencesKey::graphicsContextFiltersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GraphicsContextFiltersEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::acceleratedDrawingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AcceleratedDrawingEnabled)));
#if ENABLE(MODEL_ELEMENT)
        defaults.get().set(WebPreferencesKey::modelElementEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ModelElementEnabled)));
#endif
#if ENABLE(MODEL_ELEMENT)
        defaults.get().set(WebPreferencesKey::modelDocumentEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ModelDocumentEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::interactiveFormValidationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InteractiveFormValidationEnabled)));
#if ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::mediaEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::inputTypeColorEnhancementsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InputTypeColorEnhancementsEnabled)));
        defaults.get().set(WebPreferencesKey::detailsAutoExpandEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_DetailsAutoExpandEnabled)));
        defaults.get().set(WebPreferencesKey::commandAttributesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CommandAttributesEnabled)));
        defaults.get().set(WebPreferencesKey::hTMLLegacyAttributeValueSerializationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_HTMLLegacyAttributeValueSerializationEnabled)));
        defaults.get().set(WebPreferencesKey::popoverAttributeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PopoverAttributeEnabled)));
        defaults.get().set(WebPreferencesKey::switchControlEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SwitchControlEnabled)));
        defaults.get().set(WebPreferencesKey::httpSByDefaultEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_HTTPSByDefaultEnabled)));
        defaults.get().set(WebPreferencesKey::hiddenPageDOMTimerThrottlingAutoIncreasesKey(), Value(bool(DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingAutoIncreases)));
        defaults.get().set(WebPreferencesKey::hiddenPageDOMTimerThrottlingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingEnabled)));
#if HAVE(MATERIAL_HOSTING)
        defaults.get().set(WebPreferencesKey::hostedBlurMaterialInMediaControlsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_HostedBlurMaterialInMediaControlsEnabled)));
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
        defaults.get().set(WebPreferencesKey::blockIOKitInWebContentSandboxKey(), Value(bool(DEFAULT_VALUE_FOR_BlockIOKitInWebContentSandbox)));
#endif
        defaults.get().set(WebPreferencesKey::iOSurfaceLosslessCompressionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IOSurfaceLosslessCompressionEnabled)));
#if ENABLE(IPC_TESTING_API)
        defaults.get().set(WebPreferencesKey::ipcTestingAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IPCTestingAPIEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::itpDebugModeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ItpDebugModeEnabled)));
#if ENABLE(TEXT_AUTOSIZING)
        defaults.get().set(WebPreferencesKey::textAutosizingUsesIdempotentModeKey(), Value(bool(DEFAULT_VALUE_FOR_TextAutosizingUsesIdempotentMode)));
#endif
#if ENABLE(IPC_TESTING_API)
        defaults.get().set(WebPreferencesKey::ignoreInvalidMessageWhenIPCTestingAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IgnoreInvalidMessageWhenIPCTestingAPIEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::ignoreIframeEmbeddingProtectionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IgnoreIframeEmbeddingProtectionsEnabled)));
#if ENABLE(IMAGE_ANALYSIS)
        defaults.get().set(WebPreferencesKey::imageAnalysisDuringFindInPageEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ImageAnalysisDuringFindInPageEnabled)));
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
        defaults.get().set(WebPreferencesKey::imageAnimationControlEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ImageAnimationControlEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::imageCaptureEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ImageCaptureEnabled)));
#endif
#if ENABLE(SERVICE_CONTROLS)
        defaults.get().set(WebPreferencesKey::imageControlsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ImageControlsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::inWindowFullscreenEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InWindowFullscreenEnabled)));
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
        defaults.get().set(WebPreferencesKey::includeIgnoredInCoreAXTreeKey(), Value(bool(DEFAULT_VALUE_FOR_IncludeIgnoredInCoreAXTree)));
#endif
        defaults.get().set(WebPreferencesKey::indexedDBAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IndexedDBAPIEnabled)));
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
        defaults.get().set(WebPreferencesKey::interactionRegionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InteractionRegionsEnabled)));
#endif
#if ENABLE(ACCESSIBILITY_ISOLATED_TREE)
        defaults.get().set(WebPreferencesKey::isAccessibilityIsolatedTreeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IsAccessibilityIsolatedTreeEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::javaScriptEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_JavaScriptEnabled)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::keyboardDismissalGestureEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_KeyboardDismissalGestureEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::layerBasedSVGEngineEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LayerBasedSVGEngineEnabled)));
        defaults.get().set(WebPreferencesKey::lazyIframeLoadingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LazyIframeLoadingEnabled)));
        defaults.get().set(WebPreferencesKey::lazyImageLoadingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LazyImageLoadingEnabled)));
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
        defaults.get().set(WebPreferencesKey::legacyOverflowScrollingTouchEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LegacyOverflowScrollingTouchEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::legacyLineLayoutVisualCoverageEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LegacyLineLayoutVisualCoverageEnabled)));
        defaults.get().set(WebPreferencesKey::showModalDialogEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ShowModalDialogEnabled)));
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::mediaCaptureRequiresSecureConnectionKey(), Value(bool(DEFAULT_VALUE_FOR_MediaCaptureRequiresSecureConnection)));
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
        defaults.get().set(WebPreferencesKey::limitedMatroskaSupportEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LimitedMatroskaSupportEnabled)));
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
        defaults.get().set(WebPreferencesKey::linearMediaPlayerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LinearMediaPlayerEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::linkSanitizerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LinkSanitizerEnabled)));
        defaults.get().set(WebPreferencesKey::linkPreconnectEarlyHintsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LinkPreconnectEarlyHintsEnabled)));
        defaults.get().set(WebPreferencesKey::linkPrefetchEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LinkPrefetchEnabled)));
#if ENABLE(WEB_ARCHIVE)
        defaults.get().set(WebPreferencesKey::loadWebArchiveWithEphemeralStorageEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LoadWebArchiveWithEphemeralStorageEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::localFileContentSniffingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LocalFileContentSniffingEnabled)));
        defaults.get().set(WebPreferencesKey::localNetworkAccessEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LocalNetworkAccessEnabled)));
        defaults.get().set(WebPreferencesKey::localStorageEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LocalStorageEnabled)));
        defaults.get().set(WebPreferencesKey::lockdownFontParserEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LockdownFontParserEnabled)));
        defaults.get().set(WebPreferencesKey::logsPageMessagesToSystemConsoleEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LogsPageMessagesToSystemConsoleEnabled)));
        defaults.get().set(WebPreferencesKey::loginStatusAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LoginStatusAPIEnabled)));
        defaults.get().set(WebPreferencesKey::mainContentUserGestureOverrideEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MainContentUserGestureOverrideEnabled)));
#if ENABLE(MEDIA_SOURCE)
        defaults.get().set(WebPreferencesKey::managedMediaSourceEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ManagedMediaSourceEnabled)));
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
        defaults.get().set(WebPreferencesKey::managedMediaSourceNeedsAirPlayKey(), Value(bool(DEFAULT_VALUE_FOR_ManagedMediaSourceNeedsAirPlay)));
#endif
        defaults.get().set(WebPreferencesKey::coreMathMLEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CoreMathMLEnabled)));
        defaults.get().set(WebPreferencesKey::mediaCapabilitiesExtensionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaCapabilitiesExtensionsEnabled)));
#if ENABLE(EXTENSION_CAPABILITIES)
        defaults.get().set(WebPreferencesKey::mediaCapabilityGrantsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaCapabilityGrantsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::mediaPlaybackEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaPlaybackEnabled)));
#if ENABLE(MEDIA_SESSION)
        defaults.get().set(WebPreferencesKey::mediaSessionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaSessionEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::mediaSourceEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaSourceEnabled)));
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::mediaDevicesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaDevicesEnabled)));
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
        defaults.get().set(WebPreferencesKey::mediaRecorderEnabledWebMKey(), Value(bool(DEFAULT_VALUE_FOR_MediaRecorderEnabledWebM)));
#endif
#if ENABLE(MEDIA_RECORDER)
        defaults.get().set(WebPreferencesKey::mediaRecorderEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaRecorderEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::mediaSessionCaptureToggleAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaSessionCaptureToggleAPIEnabled)));
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
        defaults.get().set(WebPreferencesKey::mediaSourceInWorkerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaSourceInWorkerEnabled)));
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
        defaults.get().set(WebPreferencesKey::mediaSourcePrefersDecompressionSessionKey(), Value(bool(DEFAULT_VALUE_FOR_MediaSourcePrefersDecompressionSession)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::mediaStreamTrackProcessingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MediaStreamTrackProcessingEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::metaViewportInteractiveWidgetEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MetaViewportInteractiveWidgetEnabled)));
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
        defaults.get().set(WebPreferencesKey::modelNoPortalAttributeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ModelNoPortalAttributeEnabled)));
#endif
#if USE(MODERN_AVCONTENTKEYSESSION)
        defaults.get().set(WebPreferencesKey::shouldUseModernAVContentKeySessionKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldUseModernAVContentKeySession)));
#endif
        defaults.get().set(WebPreferencesKey::momentumScrollingAnimatorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MomentumScrollingAnimatorEnabled)));
        defaults.get().set(WebPreferencesKey::inputTypeMonthEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InputTypeMonthEnabled)));
#if ENABLE(TOUCH_EVENTS)
        defaults.get().set(WebPreferencesKey::mouseEventsSimulationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MouseEventsSimulationEnabled)));
#endif
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::muteCameraOnMicrophoneInterruptionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_MuteCameraOnMicrophoneInterruptionEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::navigationAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_NavigationAPIEnabled)));
#if ENABLE(APP_BOUND_DOMAINS)
        defaults.get().set(WebPreferencesKey::needsInAppBrowserPrivacyQuirksKey(), Value(bool(DEFAULT_VALUE_FOR_NeedsInAppBrowserPrivacyQuirks)));
#endif
        defaults.get().set(WebPreferencesKey::needsSiteSpecificQuirksKey(), Value(bool(DEFAULT_VALUE_FOR_NeedsSiteSpecificQuirks)));
        defaults.get().set(WebPreferencesKey::needsStorageAccessFromFileURLsQuirkKey(), Value(bool(DEFAULT_VALUE_FOR_NeedsStorageAccessFromFileURLsQuirk)));
        defaults.get().set(WebPreferencesKey::flexFormattingContextIntegrationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FlexFormattingContextIntegrationEnabled)));
#if ENABLE(NOTIFICATION_EVENT)
        defaults.get().set(WebPreferencesKey::notificationEventEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_NotificationEventEnabled)));
#endif
#if ENABLE(NOTIFICATIONS)
        defaults.get().set(WebPreferencesKey::notificationsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_NotificationsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::observableEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ObservableEnabled)));
#if ENABLE(AX_THREAD_TEXT_APIS)
        defaults.get().set(WebPreferencesKey::accessibilityThreadTextApisEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AccessibilityThreadTextApisEnabled)));
#endif
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
        defaults.get().set(WebPreferencesKey::offscreenCanvasInWorkersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_OffscreenCanvasInWorkersEnabled)));
#endif
#if ENABLE(OFFSCREEN_CANVAS)
        defaults.get().set(WebPreferencesKey::offscreenCanvasEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_OffscreenCanvasEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::opportunisticSweepingAndGarbageCollectionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_OpportunisticSweepingAndGarbageCollectionEnabled)));
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
        defaults.get().set(WebPreferencesKey::optInPartitionedCookiesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_OptInPartitionedCookiesEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::overlappingBackingStoreProvidersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_OverlappingBackingStoreProvidersEnabled)));
#if ENABLE(OVERLAY_REGIONS_IN_EVENT_REGION)
        defaults.get().set(WebPreferencesKey::overlayRegionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_OverlayRegionsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::pageVisibilityBasedProcessSuppressionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PageVisibilityBasedProcessSuppressionEnabled)));
        defaults.get().set(WebPreferencesKey::permissionsAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PermissionsAPIEnabled)));
#if HAVE(PHOTOS_UI)
        defaults.get().set(WebPreferencesKey::photoPickerPrefersOriginalImageFormatKey(), Value(bool(DEFAULT_VALUE_FOR_PhotoPickerPrefersOriginalImageFormat)));
#endif
#if HAVE(PIP_SKIP_PREROLL)
        defaults.get().set(WebPreferencesKey::pictureInPicturePlaybackStateEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PictureInPicturePlaybackStateEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::getCoalescedEventsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GetCoalescedEventsEnabled)));
        defaults.get().set(WebPreferencesKey::getPredictedEventsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GetPredictedEventsEnabled)));
#if ENABLE(POINTER_LOCK)
        defaults.get().set(WebPreferencesKey::pointerLockEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PointerLockEnabled)));
#endif
#if ENABLE(POINTER_LOCK)
        defaults.get().set(WebPreferencesKey::pointerLockOptionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PointerLockOptionsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::preferPageRenderingUpdatesNear60FPSEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PreferPageRenderingUpdatesNear60FPSEnabled)));
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
        defaults.get().set(WebPreferencesKey::preferSpatialAudioExperienceKey(), Value(bool(DEFAULT_VALUE_FOR_PreferSpatialAudioExperience)));
#endif
#if ENABLE(FULLSCREEN_API)
        defaults.get().set(WebPreferencesKey::videoFullsceenPrefersMostVisibleHeuristicKey(), Value(bool(DEFAULT_VALUE_FOR_VideoFullsceenPrefersMostVisibleHeuristic)));
#endif
        defaults.get().set(WebPreferencesKey::privateClickMeasurementDebugModeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PrivateClickMeasurementDebugModeEnabled)));
        defaults.get().set(WebPreferencesKey::privateClickMeasurementFraudPreventionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PrivateClickMeasurementFraudPreventionEnabled)));
        defaults.get().set(WebPreferencesKey::privateClickMeasurementEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PrivateClickMeasurementEnabled)));
        defaults.get().set(WebPreferencesKey::privateTokenUsageByThirdPartyEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PrivateTokenUsageByThirdPartyEnabled)));
#if ENABLE(DAMAGE_TRACKING)
        defaults.get().set(WebPreferencesKey::propagateDamagingInformationKey(), Value(bool(DEFAULT_VALUE_FOR_PropagateDamagingInformation)));
#endif
        defaults.get().set(WebPreferencesKey::pushAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PushAPIEnabled)));
        defaults.get().set(WebPreferencesKey::legacyPluginQuirkForMailSignaturesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LegacyPluginQuirkForMailSignaturesEnabled)));
        defaults.get().set(WebPreferencesKey::googleAntiFlickerOptimizationQuirkEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_GoogleAntiFlickerOptimizationQuirkEnabled)));
        defaults.get().set(WebPreferencesKey::readableByteStreamAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ReadableByteStreamAPIEnabled)));
        defaults.get().set(WebPreferencesKey::remoteMediaSessionManagerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_RemoteMediaSessionManagerEnabled)));
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
        defaults.get().set(WebPreferencesKey::remotePlaybackEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_RemotePlaybackEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::remoteSnapshottingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_RemoteSnapshottingEnabled)));
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
        defaults.get().set(WebPreferencesKey::removeBackgroundEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_RemoveBackgroundEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::requestVideoFrameCallbackEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_RequestVideoFrameCallbackEnabled)));
#if HAVE(SC_CONTENT_SHARING_PICKER)
        defaults.get().set(WebPreferencesKey::requireUAGetDisplayMediaPromptKey(), Value(bool(DEFAULT_VALUE_FOR_RequireUAGetDisplayMediaPrompt)));
#endif
        defaults.get().set(WebPreferencesKey::loginStatusAPIRequiresWebAuthnEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LoginStatusAPIRequiresWebAuthnEnabled)));
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::speakerSelectionRequiresUserGestureKey(), Value(bool(DEFAULT_VALUE_FOR_SpeakerSelectionRequiresUserGesture)));
#endif
        defaults.get().set(WebPreferencesKey::fullscreenRequirementForScreenOrientationLockingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_FullscreenRequirementForScreenOrientationLockingEnabled)));
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::getUserMediaRequiresFocusKey(), Value(bool(DEFAULT_VALUE_FOR_GetUserMediaRequiresFocus)));
#endif
        defaults.get().set(WebPreferencesKey::resourceLoadSchedulingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ResourceLoadSchedulingEnabled)));
#if ENABLE(RESOURCE_USAGE)
        defaults.get().set(WebPreferencesKey::resourceUsageOverlayVisibleKey(), Value(bool(DEFAULT_VALUE_FOR_ResourceUsageOverlayVisible)));
#endif
        defaults.get().set(WebPreferencesKey::respondToThermalPressureAggressivelyKey(), Value(bool(DEFAULT_VALUE_FOR_RespondToThermalPressureAggressively)));
        defaults.get().set(WebPreferencesKey::sKAttributionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SKAttributionEnabled)));
        defaults.get().set(WebPreferencesKey::safeBrowsingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SafeBrowsingEnabled)));
        defaults.get().set(WebPreferencesKey::isSameSiteStrictEnforcementEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IsSameSiteStrictEnforcementEnabled)));
        defaults.get().set(WebPreferencesKey::scopedCustomElementRegistryEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScopedCustomElementRegistryEnabled)));
        defaults.get().set(WebPreferencesKey::screenOrientationLockingAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScreenOrientationLockingAPIEnabled)));
        defaults.get().set(WebPreferencesKey::screenOrientationAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScreenOrientationAPIEnabled)));
#if ENABLE(SCREEN_TIME)
        defaults.get().set(WebPreferencesKey::screenTimeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScreenTimeEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::screenWakeLockAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScreenWakeLockAPIEnabled)));
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::screenCaptureEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScreenCaptureEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::scriptTrackingPrivacyLoggingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScriptTrackingPrivacyLoggingEnabled)));
        defaults.get().set(WebPreferencesKey::scriptTrackingPrivacyProtectionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScriptTrackingPrivacyProtectionsEnabled)));
        defaults.get().set(WebPreferencesKey::scrollingPerformanceTestingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollingPerformanceTestingEnabled)));
        defaults.get().set(WebPreferencesKey::scrollToTextFragmentFeatureDetectionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollToTextFragmentFeatureDetectionEnabled)));
        defaults.get().set(WebPreferencesKey::scrollToTextFragmentGenerationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollToTextFragmentGenerationEnabled)));
        defaults.get().set(WebPreferencesKey::scrollToTextFragmentIndicatorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollToTextFragmentIndicatorEnabled)));
        defaults.get().set(WebPreferencesKey::scrollToTextFragmentMarkingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollToTextFragmentMarkingEnabled)));
        defaults.get().set(WebPreferencesKey::scrollToTextFragmentEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollToTextFragmentEnabled)));
        defaults.get().set(WebPreferencesKey::scrollAnimatorEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollAnimatorEnabled)));
        defaults.get().set(WebPreferencesKey::scrollDrivenAnimationsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollDrivenAnimationsEnabled)));
        defaults.get().set(WebPreferencesKey::secureContextChecksEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SecureContextChecksEnabled)));
        defaults.get().set(WebPreferencesKey::selectionFlippingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SelectionFlippingEnabled)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::selectionHonorsOverflowScrollingKey(), Value(bool(DEFAULT_VALUE_FOR_SelectionHonorsOverflowScrolling)));
#endif
        defaults.get().set(WebPreferencesKey::serviceWorkerInstallEventEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ServiceWorkerInstallEventEnabled)));
        defaults.get().set(WebPreferencesKey::serviceWorkerNavigationPreloadEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ServiceWorkerNavigationPreloadEnabled)));
        defaults.get().set(WebPreferencesKey::serviceWorkersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ServiceWorkersEnabled)));
        defaults.get().set(WebPreferencesKey::shapeDetectionKey(), Value(bool(DEFAULT_VALUE_FOR_ShapeDetection)));
        defaults.get().set(WebPreferencesKey::siteIsolationSharedProcessEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SiteIsolationSharedProcessEnabled)));
        defaults.get().set(WebPreferencesKey::sharedWorkerEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SharedWorkerEnabled)));
        defaults.get().set(WebPreferencesKey::showMediaStatsContextMenuItemEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ShowMediaStatsContextMenuItemEnabled)));
        defaults.get().set(WebPreferencesKey::showFrameProcessBordersEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ShowFrameProcessBordersEnabled)));
        defaults.get().set(WebPreferencesKey::sidewaysWritingModesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SidewaysWritingModesEnabled)));
        defaults.get().set(WebPreferencesKey::siteIsolationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SiteIsolationEnabled)));
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
        defaults.get().set(WebPreferencesKey::spatialImageControlsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SpatialImageControlsEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::speechRecognitionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SpeechRecognitionEnabled)));
        defaults.get().set(WebPreferencesKey::speechSynthesisAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SpeechSynthesisAPIEnabled)));
        defaults.get().set(WebPreferencesKey::storageAPIEstimateEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_StorageAPIEstimateEnabled)));
        defaults.get().set(WebPreferencesKey::storageAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_StorageAPIEnabled)));
        defaults.get().set(WebPreferencesKey::storageBlockingPolicyKey(), Value(uint32_t(DEFAULT_VALUE_FOR_StorageBlockingPolicy)));
        defaults.get().set(WebPreferencesKey::supportHDRCompositorTonemappingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SupportHDRCompositorTonemappingEnabled)));
        defaults.get().set(WebPreferencesKey::supportHDRDisplayEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_SupportHDRDisplayEnabled)));
        defaults.get().set(WebPreferencesKey::processSwapOnCrossSiteNavigationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ProcessSwapOnCrossSiteNavigationEnabled)));
        defaults.get().set(WebPreferencesKey::shouldTakeNearSuspendedAssertionsKey(), Value(bool(DEFAULT_VALUE_FOR_ShouldTakeNearSuspendedAssertions)));
#if ENABLE(WRITING_TOOLS)
        defaults.get().set(WebPreferencesKey::textAnimationsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TextAnimationsEnabled)));
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
        defaults.get().set(WebPreferencesKey::textRecognitionInVideosEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TextRecognitionInVideosEnabled)));
#endif
#if ENABLE(MEDIA_SOURCE)
        defaults.get().set(WebPreferencesKey::textTracksInMSEEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TextTracksInMSEEnabled)));
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
        defaults.get().set(WebPreferencesKey::threadedAnimationResolutionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ThreadedAnimationResolutionEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::tiledScrollingIndicatorVisibleKey(), Value(bool(DEFAULT_VALUE_FOR_TiledScrollingIndicatorVisible)));
        defaults.get().set(WebPreferencesKey::inputTypeTimeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InputTypeTimeEnabled)));
        defaults.get().set(WebPreferencesKey::topContentInsetBackgroundCanChangeAfterScrollingKey(), Value(bool(DEFAULT_VALUE_FOR_TopContentInsetBackgroundCanChangeAfterScrolling)));
#if ENABLE(WEBXR)
        defaults.get().set(WebPreferencesKey::touchInputCompatibilityEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TouchInputCompatibilityEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::trackConfigurationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TrackConfigurationEnabled)));
        defaults.get().set(WebPreferencesKey::trustedTypesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_TrustedTypesEnabled)));
        defaults.get().set(WebPreferencesKey::uRLPatternAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_URLPatternAPIEnabled)));
        defaults.get().set(WebPreferencesKey::undoManagerAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UndoManagerAPIEnabled)));
#if ENABLE(UNIFIED_PDF)
        defaults.get().set(WebPreferencesKey::unifiedPDFEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UnifiedPDFEnabled)));
#endif
#if ENABLE(DAMAGE_TRACKING)
        defaults.get().set(WebPreferencesKey::unifyDamagedRegionsKey(), Value(bool(DEFAULT_VALUE_FOR_UnifyDamagedRegions)));
#endif
        defaults.get().set(WebPreferencesKey::iPAddressAndLocalhostMixedContentUpgradeTestingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IPAddressAndLocalhostMixedContentUpgradeTestingEnabled)));
        defaults.get().set(WebPreferencesKey::upgradeKnownHostsToHTTPSEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UpgradeKnownHostsToHTTPSEnabled)));
        defaults.get().set(WebPreferencesKey::upgradeMixedContentEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UpgradeMixedContentEnabled)));
#if ENABLE(ARKIT_INLINE_PREVIEW)
        defaults.get().set(WebPreferencesKey::useARKitForModelKey(), Value(bool(DEFAULT_VALUE_FOR_UseARKitForModel)));
#endif
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
        defaults.get().set(WebPreferencesKey::useAVCaptureDeviceRotationCoordinatorAPIKey(), Value(bool(DEFAULT_VALUE_FOR_UseAVCaptureDeviceRotationCoordinatorAPI)));
#endif
        defaults.get().set(WebPreferencesKey::useIFCForSVGTextKey(), Value(bool(DEFAULT_VALUE_FOR_UseIFCForSVGText)));
#if ENABLE(MEDIA_STREAM)
        defaults.get().set(WebPreferencesKey::useMicrophoneMuteStatusAPIKey(), Value(bool(DEFAULT_VALUE_FOR_UseMicrophoneMuteStatusAPI)));
#endif
#if HAVE(SCENEKIT)
        defaults.get().set(WebPreferencesKey::useSceneKitForModelKey(), Value(bool(DEFAULT_VALUE_FOR_UseSceneKitForModel)));
#endif
        defaults.get().set(WebPreferencesKey::useGiantTilesKey(), Value(bool(DEFAULT_VALUE_FOR_UseGiantTiles)));
#if ENABLE(DAMAGE_TRACKING)
        defaults.get().set(WebPreferencesKey::useDamagingInformationForCompositingKey(), Value(bool(DEFAULT_VALUE_FOR_UseDamagingInformationForCompositing)));
#endif
        defaults.get().set(WebPreferencesKey::userActivationAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UserActivationAPIEnabled)));
        defaults.get().set(WebPreferencesKey::userGesturePromisePropagationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_UserGesturePromisePropagationEnabled)));
#if HAVE(WEBCONTENTRESTRICTIONS)
        defaults.get().set(WebPreferencesKey::usesWebContentRestrictionsForFilterKey(), Value(bool(DEFAULT_VALUE_FOR_UsesWebContentRestrictionsForFilter)));
#endif
        defaults.get().set(WebPreferencesKey::serviceWorkersUserGestureEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ServiceWorkersUserGestureEnabled)));
        defaults.get().set(WebPreferencesKey::verifyWindowOpenUserGestureFromUIProcessKey(), Value(bool(DEFAULT_VALUE_FOR_VerifyWindowOpenUserGestureFromUIProcess)));
        defaults.get().set(WebPreferencesKey::verticalFormControlsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VerticalFormControlsEnabled)));
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        defaults.get().set(WebPreferencesKey::videoRendererProtectedFallbackDisabledKey(), Value(bool(DEFAULT_VALUE_FOR_VideoRendererProtectedFallbackDisabled)));
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        defaults.get().set(WebPreferencesKey::videoRendererUseDecompressionSessionForProtectedKey(), Value(bool(DEFAULT_VALUE_FOR_VideoRendererUseDecompressionSessionForProtected)));
#endif
        defaults.get().set(WebPreferencesKey::viewTransitionClassesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ViewTransitionClassesEnabled)));
        defaults.get().set(WebPreferencesKey::viewTransitionTypesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ViewTransitionTypesEnabled)));
        defaults.get().set(WebPreferencesKey::viewTransitionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ViewTransitionsEnabled)));
        defaults.get().set(WebPreferencesKey::viewGestureDebuggingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ViewGestureDebuggingEnabled)));
#if ENABLE(IMAGE_ANALYSIS)
        defaults.get().set(WebPreferencesKey::visualTranslationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VisualTranslationEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::visualViewportAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VisualViewportAPIEnabled)));
#if PLATFORM(IOS_FAMILY)
        defaults.get().set(WebPreferencesKey::visuallyContiguousBidiTextSelectionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_VisuallyContiguousBidiTextSelectionEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::webAPIStatisticsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAPIStatisticsEnabled)));
        defaults.get().set(WebPreferencesKey::webAPIsInShadowRealmEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAPIsInShadowRealmEnabled)));
        defaults.get().set(WebPreferencesKey::webAnimationsOverallProgressPropertyEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAnimationsOverallProgressPropertyEnabled)));
        defaults.get().set(WebPreferencesKey::webAnimationsCustomEffectsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAnimationsCustomEffectsEnabled)));
        defaults.get().set(WebPreferencesKey::webAnimationsCustomFrameRateEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAnimationsCustomFrameRateEnabled)));
#if ENABLE(WEB_ARCHIVE)
        defaults.get().set(WebPreferencesKey::webArchiveDebugModeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebArchiveDebugModeEnabled)));
#endif
#if ENABLE(WEB_ARCHIVE)
        defaults.get().set(WebPreferencesKey::webArchiveTestingModeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebArchiveTestingModeEnabled)));
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
        defaults.get().set(WebPreferencesKey::webAuthenticationASEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAuthenticationASEnabled)));
#endif
#if ENABLE(WEB_AUTHN)
        defaults.get().set(WebPreferencesKey::webAuthenticationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAuthenticationEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::webCryptoSafeCurvesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebCryptoSafeCurvesEnabled)));
        defaults.get().set(WebPreferencesKey::webCryptoX25519EnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebCryptoX25519Enabled)));
        defaults.get().set(WebPreferencesKey::webLocksAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebLocksAPIEnabled)));
        defaults.get().set(WebPreferencesKey::webShareFileAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebShareFileAPIEnabled)));
        defaults.get().set(WebPreferencesKey::webShareEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebShareEnabled)));
#if ENABLE(WEBASSEMBLY)
        defaults.get().set(WebPreferencesKey::webAssemblyESMIntegrationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebAssemblyESMIntegrationEnabled)));
#endif
#if ENABLE(WEB_CODECS)
        defaults.get().set(WebPreferencesKey::webCodecsAV1EnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebCodecsAV1Enabled)));
#endif
#if ENABLE(WEB_CODECS)
        defaults.get().set(WebPreferencesKey::webCodecsAudioEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebCodecsAudioEnabled)));
#endif
#if ENABLE(WEB_CODECS)
        defaults.get().set(WebPreferencesKey::webCodecsHEVCEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebCodecsHEVCEnabled)));
#endif
#if ENABLE(WEB_CODECS)
        defaults.get().set(WebPreferencesKey::webCodecsVideoEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebCodecsVideoEnabled)));
#endif
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
        defaults.get().set(WebPreferencesKey::webExtensionBookmarksEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebExtensionBookmarksEnabled)));
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
        defaults.get().set(WebPreferencesKey::webExtensionSidebarEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebExtensionSidebarEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::webGLDraftExtensionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebGLDraftExtensionsEnabled)));
        defaults.get().set(WebPreferencesKey::webGLTimerQueriesEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebGLTimerQueriesEnabled)));
        defaults.get().set(WebPreferencesKey::webGLEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebGLEnabled)));
        defaults.get().set(WebPreferencesKey::webGPUHDREnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebGPUHDREnabled)));
        defaults.get().set(WebPreferencesKey::webXRWebGPUBindingsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebXRWebGPUBindingsEnabled)));
        defaults.get().set(WebPreferencesKey::webGPUEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebGPUEnabled)));
        defaults.get().set(WebPreferencesKey::webInspectorEngineeringSettingsAllowedKey(), Value(bool(DEFAULT_VALUE_FOR_WebInspectorEngineeringSettingsAllowed)));
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCAV1CodecEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCAV1CodecEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::webRTCAudioLatencyAdaptationEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCAudioLatencyAdaptationEnabled)));
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCDTMFEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCDTMFEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCEncodedTransformEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCEncodedTransformEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCH264HardwareEncoderEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCH264HardwareEncoderEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCH265CodecEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCH265CodecEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCL4SEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCL4SEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::webRTCMediaPipelineAdditionalLoggingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCMediaPipelineAdditionalLoggingEnabled)));
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::legacyWebRTCOfferOptionsEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_LegacyWebRTCOfferOptionsEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::peerConnectionVideoScalingAdaptationDisabledKey(), Value(bool(DEFAULT_VALUE_FOR_PeerConnectionVideoScalingAdaptationDisabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::peerConnectionEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_PeerConnectionEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCRemoteVideoFrameEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCRemoteVideoFrameEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCSFrameTransformEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCSFrameTransformEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCSocketsProxyingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCSocketsProxyingEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCUDPPortRangeKey(), Value(DEFAULT_VALUE_FOR_WebRTCUDPPortRange));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCVP9Profile0CodecEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCVP9Profile0CodecEnabled)));
#endif
#if ENABLE(WEB_RTC)
        defaults.get().set(WebPreferencesKey::webRTCVP9Profile2CodecEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCVP9Profile2CodecEnabled)));
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
        defaults.get().set(WebPreferencesKey::webRTCInterfaceMonitoringViaNWEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebRTCInterfaceMonitoringViaNWEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::webTransportEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebTransportEnabled)));
#if ENABLE(WEBXR)
        defaults.get().set(WebPreferencesKey::webXRAugmentedRealityModuleEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebXRAugmentedRealityModuleEnabled)));
#endif
#if ENABLE(WEBXR)
        defaults.get().set(WebPreferencesKey::webXREnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebXREnabled)));
#endif
#if ENABLE(WEBXR)
        defaults.get().set(WebPreferencesKey::webXRGamepadsModuleEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebXRGamepadsModuleEnabled)));
#endif
#if ENABLE(WEBXR_HANDS)
        defaults.get().set(WebPreferencesKey::webXRHandInputModuleEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebXRHandInputModuleEnabled)));
#endif
#if ENABLE(WEBXR_LAYERS)
        defaults.get().set(WebPreferencesKey::webXRLayersAPIEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebXRLayersAPIEnabled)));
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
        defaults.get().set(WebPreferencesKey::webPageSpatialBackdropEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WebPageSpatialBackdropEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::inputTypeWeekEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InputTypeWeekEnabled)));
        defaults.get().set(WebPreferencesKey::wheelEventGesturesBecomeNonBlockingKey(), Value(bool(DEFAULT_VALUE_FOR_WheelEventGesturesBecomeNonBlocking)));
        defaults.get().set(WebPreferencesKey::passiveWheelListenersAsDefaultOnDocumentKey(), Value(bool(DEFAULT_VALUE_FOR_PassiveWheelListenersAsDefaultOnDocument)));
        defaults.get().set(WebPreferencesKey::workerAsynchronousURLErrorHandlingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WorkerAsynchronousURLErrorHandlingEnabled)));
#if PLATFORM(COCOA)
        defaults.get().set(WebPreferencesKey::writeRichTextDataWhenCopyingOrDraggingKey(), Value(bool(DEFAULT_VALUE_FOR_WriteRichTextDataWhenCopyingOrDragging)));
#endif
#if ENABLE(WRITING_SUGGESTIONS)
        defaults.get().set(WebPreferencesKey::writingSuggestionsAttributeEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_WritingSuggestionsAttributeEnabled)));
#endif
#if ENABLE(XSLT)
        defaults.get().set(WebPreferencesKey::xSLTEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_XSLTEnabled)));
#endif
        defaults.get().set(WebPreferencesKey::isFirstPartyWebsiteDataRemovalLiveOnTestingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled)));
        defaults.get().set(WebPreferencesKey::isFirstPartyWebsiteDataRemovalReproTestingEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalReproTestingEnabled)));
        defaults.get().set(WebPreferencesKey::altitudeAngleEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AltitudeAngleEnabled)));
        defaults.get().set(WebPreferencesKey::azimuthAngleEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_AzimuthAngleEnabled)));
        defaults.get().set(WebPreferencesKey::inputTypeDateTimeLocalEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_InputTypeDateTimeLocalEnabled)));
        defaults.get().set(WebPreferencesKey::caretPositionFromPointEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CaretPositionFromPointEnabled)));
        defaults.get().set(WebPreferencesKey::hiddenUntilFoundEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_HiddenUntilFoundEnabled)));
        defaults.get().set(WebPreferencesKey::httpEquivEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_HTTPEquivEnabled)));
        defaults.get().set(WebPreferencesKey::shadowRootReferenceTargetEnabledForAriaOwnsKey(), Value(bool(DEFAULT_VALUE_FOR_ShadowRootReferenceTargetEnabledForAriaOwns)));
        defaults.get().set(WebPreferencesKey::shadowRootReferenceTargetEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ShadowRootReferenceTargetEnabled)));
        defaults.get().set(WebPreferencesKey::requestIdleCallbackEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_RequestIdleCallbackEnabled)));
        defaults.get().set(WebPreferencesKey::requestStorageAccessThrowsExceptionUntilReloadKey(), Value(bool(DEFAULT_VALUE_FOR_RequestStorageAccessThrowsExceptionUntilReload)));
        defaults.get().set(WebPreferencesKey::scrollendEventEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_ScrollendEventEnabled)));
        defaults.get().set(WebPreferencesKey::cssWordBreakAutoPhraseEnabledKey(), Value(bool(DEFAULT_VALUE_FOR_CSSWordBreakAutoPhraseEnabled)));
    }

    return defaults;
}

} // namespace WebKit
