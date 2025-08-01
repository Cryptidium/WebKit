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
#include "WebPage.h"

#include "WebPreferencesDefinitions.h"
#include "WebPreferencesKeys.h"
#include "WebPreferencesStore.h"
#include "WebProcess.h"
#include <WebCore/DeprecatedGlobalSettings.h>
#include <WebCore/Page.h>
#include <WebCore/Settings.h>

namespace WebKit {

void WebPage::updateSettingsGenerated(const WebPreferencesStore& store, WebCore::Settings& settings)
{
    settings.setLoadDeferringEnabled(store.getBoolValueForKey(WebPreferencesKey::loadDeferringEnabledKey()));
    settings.setAcceleratedCompositingEnabled(store.getBoolValueForKey(WebPreferencesKey::acceleratedCompositingEnabledKey()));
    settings.setAcceleratedCompositingForFixedPositionEnabled(store.getBoolValueForKey(WebPreferencesKey::acceleratedCompositingForFixedPositionEnabledKey()));
    settings.setWirelessPlaybackTargetAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::wirelessPlaybackTargetAPIEnabledKey()));
    settings.setLoadsImagesAutomatically(store.getBoolValueForKey(WebPreferencesKey::loadsImagesAutomaticallyKey()));
    settings.setLinkPreconnectEnabled(store.getBoolValueForKey(WebPreferencesKey::linkPreconnectKey()));
    settings.setWindowFocusRestricted(store.getBoolValueForKey(WebPreferencesKey::windowFocusRestrictedKey()));
    settings.setAggressiveTileRetentionEnabled(store.getBoolValueForKey(WebPreferencesKey::aggressiveTileRetentionEnabledKey()));
    settings.setAllowContentSecurityPolicySourceStarToMatchAnyProtocol(store.getBoolValueForKey(WebPreferencesKey::allowContentSecurityPolicySourceStarToMatchAnyProtocolKey()));
    settings.setAllowDisplayOfInsecureContent(store.getBoolValueForKey(WebPreferencesKey::allowDisplayOfInsecureContentKey()));
    settings.setAllowFileAccessFromFileURLs(store.getBoolValueForKey(WebPreferencesKey::allowFileAccessFromFileURLsKey()));
    settings.setAllowMultiElementImplicitSubmission(store.getBoolValueForKey(WebPreferencesKey::allowMultiElementImplicitSubmissionKey()));
#if ENABLE(MEDIA_SOURCE)
    settings.setManagedMediaSourceHighThreshold(store.getDoubleValueForKey(WebPreferencesKey::managedMediaSourceHighThresholdKey()));
#endif
    settings.setAllowRunningOfInsecureContent(store.getBoolValueForKey(WebPreferencesKey::allowRunningOfInsecureContentKey()));
#if ENABLE(MEDIA_SOURCE)
    settings.setManagedMediaSourceLowThreshold(store.getDoubleValueForKey(WebPreferencesKey::managedMediaSourceLowThresholdKey()));
#endif
#if ENABLE(MATHML)
    settings.setMathMLEnabled(store.getBoolValueForKey(WebPreferencesKey::mathMLEnabledKey()));
#endif
    settings.setMaxParseDuration(store.getDoubleValueForKey(WebPreferencesKey::maxParseDurationKey()));
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    settings.setAllowsAirPlayForMediaPlayback(store.getBoolValueForKey(WebPreferencesKey::allowsAirPlayForMediaPlaybackKey()));
#endif
    settings.setAllowsInlineMediaPlayback(store.getBoolValueForKey(WebPreferencesKey::allowsInlineMediaPlaybackKey()));
    settings.setAllowsInlineMediaPlaybackAfterFullscreen(store.getBoolValueForKey(WebPreferencesKey::allowsInlineMediaPlaybackAfterFullscreenKey()));
    settings.setAllowsPictureInPictureMediaPlayback(store.getBoolValueForKey(WebPreferencesKey::allowsPictureInPictureMediaPlaybackKey()));
#if PLATFORM(IOS_FAMILY)
    settings.setAlternateFullScreenControlDesignEnabled(store.getBoolValueForKey(WebPreferencesKey::alternateFullScreenControlDesignEnabledKey()));
#endif
    settings.setWebSocketEnabled(store.getBoolValueForKey(WebPreferencesKey::webSocketEnabledKey()));
    settings.setMediaCapabilitiesEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaCapabilitiesEnabledKey()));
    settings.setWebSecurityEnabled(store.getBoolValueForKey(WebPreferencesKey::webSecurityEnabledKey()));
    settings.setAnimatedImageAsyncDecodingEnabled(store.getBoolValueForKey(WebPreferencesKey::animatedImageAsyncDecodingEnabledKey()));
    settings.setLayoutViewportHeightExpansionFactor(store.getDoubleValueForKey(WebPreferencesKey::layoutViewportHeightExpansionFactorKey()));
    settings.setLayoutFallbackWidth(store.getUInt32ValueForKey(WebPreferencesKey::layoutFallbackWidthKey()));
    settings.setAppleMailPaginationQuirkEnabled(store.getBoolValueForKey(WebPreferencesKey::appleMailPaginationQuirkEnabledKey()));
#if ENABLE(APPLE_PAY)
    settings.setApplePayCapabilityDisclosureAllowed(store.getBoolValueForKey(WebPreferencesKey::applePayCapabilityDisclosureAllowedKey()));
#endif
#if ENABLE(APPLE_PAY)
    settings.setApplePayEnabled(store.getBoolValueForKey(WebPreferencesKey::applePayEnabledKey()));
#endif
    settings.setLargeImageAsyncDecodingEnabled(store.getBoolValueForKey(WebPreferencesKey::largeImageAsyncDecodingEnabledKey()));
    settings.setJavaScriptRuntimeFlags(static_cast<JSC::RuntimeFlags>(store.getUInt32ValueForKey(WebPreferencesKey::javaScriptRuntimeFlagsKey())));
    settings.setAsynchronousSpellCheckingEnabled(store.getBoolValueForKey(WebPreferencesKey::asynchronousSpellCheckingEnabledKey()));
    settings.setScriptMarkupEnabled(store.getBoolValueForKey(WebPreferencesKey::javaScriptMarkupEnabledKey()));
    settings.setAudioControlsScaleWithPageZoom(store.getBoolValueForKey(WebPreferencesKey::audioControlsScaleWithPageZoomKey()));
    settings.setJavaScriptCanOpenWindowsAutomatically(store.getBoolValueForKey(WebPreferencesKey::javaScriptCanOpenWindowsAutomaticallyKey()));
    settings.setAuthorAndUserStylesEnabled(store.getBoolValueForKey(WebPreferencesKey::authorAndUserStylesEnabledKey()));
#if ENABLE(WEB_AUDIO)
    settings.setWebAudioEnabled(store.getBoolValueForKey(WebPreferencesKey::webAudioEnabledKey()));
#endif
    settings.setJavaScriptCanAccessClipboard(store.getBoolValueForKey(WebPreferencesKey::javaScriptCanAccessClipboardKey()));
    settings.setWantsBalancedSetDefersLoadingBehavior(store.getBoolValueForKey(WebPreferencesKey::wantsBalancedSetDefersLoadingBehaviorKey()));
    settings.setVisualViewportEnabled(store.getBoolValueForKey(WebPreferencesKey::visualViewportEnabledKey()));
    settings.setVisibleDebugOverlayRegions(store.getUInt32ValueForKey(WebPreferencesKey::visibleDebugOverlayRegionsKey()));
#if ENABLE(VIDEO)
    settings.setVideoQualityIncludesDisplayCompositingEnabled(store.getBoolValueForKey(WebPreferencesKey::videoQualityIncludesDisplayCompositingEnabledKey()));
#endif
    settings.setBackspaceKeyNavigationEnabled(store.getBoolValueForKey(WebPreferencesKey::backspaceKeyNavigationEnabledKey()));
    settings.setMediaContentTypesRequiringHardwareSupport(store.getStringValueForKey(WebPreferencesKey::mediaContentTypesRequiringHardwareSupportKey()));
    settings.setVideoPresentationModeAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::videoPresentationModeAPIEnabledKey()));
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
    settings.setMediaControlsContextMenusEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaControlsContextMenusEnabledKey()));
#endif
    settings.setVideoPresentationManagerEnabled(store.getBoolValueForKey(WebPreferencesKey::videoPresentationManagerEnabledKey()));
    settings.setMediaControlsScaleWithPageZoom(store.getBoolValueForKey(WebPreferencesKey::mediaControlsScaleWithPageZoomKey()));
#if ENABLE(FULLSCREEN_API)
    settings.setVideoFullscreenRequiresElementFullscreen(store.getBoolValueForKey(WebPreferencesKey::videoFullscreenRequiresElementFullscreenKey()));
#endif
    settings.setMediaDataLoadsAutomatically(store.getBoolValueForKey(WebPreferencesKey::mediaDataLoadsAutomaticallyKey()));
    settings.setMediaPreferredFullscreenWidth(store.getDoubleValueForKey(WebPreferencesKey::mediaPreferredFullscreenWidthKey()));
    settings.setMediaPreloadingEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaPreloadingEnabledKey()));
    settings.setInvisibleAutoplayNotPermitted(store.getBoolValueForKey(WebPreferencesKey::invisibleAutoplayNotPermittedKey()));
#if ENABLE(MEDIA_STREAM)
    settings.setInterruptVideoOnPageVisibilityChangeEnabled(store.getBoolValueForKey(WebPreferencesKey::interruptVideoOnPageVisibilityChangeEnabledKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setInterruptAudioOnPageVisibilityChangeEnabled(store.getBoolValueForKey(WebPreferencesKey::interruptAudioOnPageVisibilityChangeEnabledKey()));
#endif
#if ENABLE(VP9)
    settings.setVP9DecoderEnabled(store.getBoolValueForKey(WebPreferencesKey::vp9DecoderEnabledKey()));
#endif
    settings.setMediaUserGestureInheritsFromDocument(store.getBoolValueForKey(WebPreferencesKey::mediaUserGestureInheritsFromDocumentKey()));
    settings.setInteractionRegionMinimumCornerRadius(store.getDoubleValueForKey(WebPreferencesKey::interactionRegionMinimumCornerRadiusKey()));
    settings.setInteractionRegionInlinePadding(store.getDoubleValueForKey(WebPreferencesKey::interactionRegionInlinePaddingKey()));
    settings.setInspectorSupportsShowingCertificate(store.getBoolValueForKey(WebPreferencesKey::inspectorSupportsShowingCertificateKey()));
    settings.setInspectorMaximumResourcesContentSize(store.getUInt32ValueForKey(WebPreferencesKey::inspectorMaximumResourcesContentSizeKey()));
    settings.setMinimumFontSize(store.getDoubleValueForKey(WebPreferencesKey::minimumFontSizeKey()));
    settings.setMinimumLogicalFontSize(store.getDoubleValueForKey(WebPreferencesKey::minimumLogicalFontSizeKey()));
#if ENABLE(TEXT_AUTOSIZING)
    settings.setMinimumZoomFontSize(store.getDoubleValueForKey(WebPreferencesKey::minimumZoomFontSizeKey()));
#endif
    settings.setMockScrollbarsControllerEnabled(store.getBoolValueForKey(WebPreferencesKey::mockScrollbarsControllerEnabledKey()));
    settings.setInlineMediaPlaybackRequiresPlaysInlineAttribute(store.getBoolValueForKey(WebPreferencesKey::inlineMediaPlaybackRequiresPlaysInlineAttributeKey()));
    settings.setIncrementalRenderingSuppressionTimeoutInSeconds(store.getDoubleValueForKey(WebPreferencesKey::incrementalRenderingSuppressionTimeoutKey()));
#if HAVE(INCREMENTAL_PDF_APIS)
    settings.setIncrementalPDFLoadingEnabled(store.getBoolValueForKey(WebPreferencesKey::incrementalPDFLoadingEnabledKey()));
#endif
    settings.setIncompleteImageBorderEnabled(store.getBoolValueForKey(WebPreferencesKey::incompleteImageBorderEnabledKey()));
    settings.setNeedsAdobeFrameReloadingQuirk(store.getBoolValueForKey(WebPreferencesKey::needsAdobeFrameReloadingQuirkKey()));
    settings.setNeedsFrameNameFallbackToIdQuirk(store.getBoolValueForKey(WebPreferencesKey::needsFrameNameFallbackToIdQuirkKey()));
    settings.setNeedsKeyboardEventDisambiguationQuirks(store.getBoolValueForKey(WebPreferencesKey::needsKeyboardEventDisambiguationQuirksKey()));
#if PLATFORM(COCOA)
    settings.setPDFPluginEnabled(store.getBoolValueForKey(WebPreferencesKey::pdfPluginEnabledKey()));
#endif
#if PLATFORM(COCOA)
    settings.setPDFPluginHUDEnabled(store.getBoolValueForKey(WebPreferencesKey::pdfPluginHUDEnabledKey()));
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    settings.setPDFPluginPageNumberIndicatorEnabled(store.getBoolValueForKey(WebPreferencesKey::pdfPluginPageNumberIndicatorEnabledKey()));
#endif
    settings.setPassiveTouchListenersAsDefaultOnDocument(store.getBoolValueForKey(WebPreferencesKey::passiveTouchListenersAsDefaultOnDocumentKey()));
    settings.setPasswordEchoDurationInSeconds(store.getDoubleValueForKey(WebPreferencesKey::passwordEchoDurationKey()));
    settings.setPasswordEchoEnabled(store.getBoolValueForKey(WebPreferencesKey::passwordEchoEnabledKey()));
    settings.setPictographFontFamily(store.getStringValueForKey(WebPreferencesKey::pictographFontFamilyKey()));
#if ENABLE(PICTURE_IN_PICTURE_API)
    settings.setPictureInPictureAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::pictureInPictureAPIEnabledKey()));
#endif
    settings.setPitchCorrectionAlgorithm(static_cast<WebCore::MediaPlayerEnums::PitchCorrectionAlgorithm>(store.getUInt32ValueForKey(WebPreferencesKey::pitchCorrectionAlgorithmKey())));
    settings.setPunchOutWhiteBackgroundsInDarkMode(store.getBoolValueForKey(WebPreferencesKey::punchOutWhiteBackgroundsInDarkModeKey()));
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
    settings.setRequiresPageVisibilityForVideoToBeNowPlaying(store.getBoolValueForKey(WebPreferencesKey::requiresPageVisibilityForVideoToBeNowPlayingKey()));
#endif
    settings.setRequiresPageVisibilityToPlayAudio(store.getBoolValueForKey(WebPreferencesKey::requiresPageVisibilityToPlayAudioKey()));
    settings.setHiddenPageCSSAnimationSuspensionEnabled(store.getBoolValueForKey(WebPreferencesKey::hiddenPageCSSAnimationSuspensionEnabledKey()));
    settings.setRequiresUserGestureForAudioPlayback(store.getBoolValueForKey(WebPreferencesKey::requiresUserGestureForAudioPlaybackKey()));
    settings.setRequiresUserGestureForVideoPlayback(store.getBoolValueForKey(WebPreferencesKey::requiresUserGestureForVideoPlaybackKey()));
    settings.setRequiresUserGestureToLoadVideo(store.getBoolValueForKey(WebPreferencesKey::requiresUserGestureToLoadVideoKey()));
#if HAVE(RUBBER_BANDING)
    settings.setRubberBandingForSubScrollableRegionsEnabled(store.getBoolValueForKey(WebPreferencesKey::rubberBandingForSubScrollableRegionsEnabledKey()));
#endif
    settings.setSampledPageTopColorMaxDifference(store.getDoubleValueForKey(WebPreferencesKey::sampledPageTopColorMaxDifferenceKey()));
    settings.setSampledPageTopColorMinHeight(store.getDoubleValueForKey(WebPreferencesKey::sampledPageTopColorMinHeightKey()));
    settings.setUsesEncodingDetector(store.getBoolValueForKey(WebPreferencesKey::usesEncodingDetectorKey()));
    settings.setSansSerifFontFamily(store.getStringValueForKey(WebPreferencesKey::sansSerifFontFamilyKey()));
    settings.setSelectTrailingWhitespaceEnabled(store.getBoolValueForKey(WebPreferencesKey::selectTrailingWhitespaceEnabledKey()));
    settings.setSerifFontFamily(store.getStringValueForKey(WebPreferencesKey::serifFontFamilyKey()));
    settings.setUsesBackForwardCache(store.getBoolValueForKey(WebPreferencesKey::usesBackForwardCacheKey()));
    settings.setUserInterfaceDirectionPolicy(static_cast<WebCore::UserInterfaceDirectionPolicy>(store.getUInt32ValueForKey(WebPreferencesKey::userInterfaceDirectionPolicyKey())));
    settings.setCaretBrowsingEnabled(store.getBoolValueForKey(WebPreferencesKey::caretBrowsingEnabledKey()));
    settings.setUseSystemAppearance(store.getBoolValueForKey(WebPreferencesKey::useSystemAppearanceKey()));
#if ENABLE(SERVICE_CONTROLS)
    settings.setServiceControlsEnabled(store.getBoolValueForKey(WebPreferencesKey::serviceControlsEnabledKey()));
#endif
    settings.setShouldAllowUserInstalledFonts(store.getBoolValueForKey(WebPreferencesKey::shouldAllowUserInstalledFontsKey()));
    settings.setColorFilterEnabled(store.getBoolValueForKey(WebPreferencesKey::colorFilterEnabledKey()));
    settings.setUsePreHTML5ParserQuirks(store.getBoolValueForKey(WebPreferencesKey::usePreHTML5ParserQuirksKey()));
    settings.setShouldConvertInvalidURLsToBlank(store.getBoolValueForKey(WebPreferencesKey::shouldConvertInvalidURLsToBlankKey()));
    settings.setShouldConvertPositionStyleOnCopy(store.getBoolValueForKey(WebPreferencesKey::shouldConvertPositionStyleOnCopyKey()));
    settings.setShouldDecidePolicyBeforeLoadingQuickLookPreview(store.getBoolValueForKey(WebPreferencesKey::shouldDecidePolicyBeforeLoadingQuickLookPreviewKey()));
#if ENABLE(VIDEO)
    settings.setShouldDisplayCaptions(store.getBoolValueForKey(WebPreferencesKey::shouldDisplayCaptionsKey()));
#endif
#if ENABLE(CONTENT_CHANGE_OBSERVER)
    settings.setContentChangeObserverEnabled(store.getBoolValueForKey(WebPreferencesKey::contentChangeObserverEnabledKey()));
#endif
    settings.setContentDispositionAttachmentSandboxEnabled(store.getBoolValueForKey(WebPreferencesKey::contentDispositionAttachmentSandboxEnabledKey()));
    settings.setForceWebGLUsesLowPower(store.getBoolValueForKey(WebPreferencesKey::forceWebGLUsesLowPowerKey()));
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
    settings.setContextMenuQRCodeDetectionEnabled(store.getBoolValueForKey(WebPreferencesKey::contextMenuQRCodeDetectionEnabledKey()));
#endif
#if ENABLE(VIDEO)
    settings.setShouldDisplaySubtitles(store.getBoolValueForKey(WebPreferencesKey::shouldDisplaySubtitlesKey()));
#endif
    settings.setForceFTPDirectoryListings(store.getBoolValueForKey(WebPreferencesKey::forceFTPDirectoryListingsKey()));
#if ENABLE(VIDEO)
    settings.setShouldDisplayTextDescriptions(store.getBoolValueForKey(WebPreferencesKey::shouldDisplayTextDescriptionsKey()));
#endif
#if ENABLE(TEXT_AUTOSIZING)
    settings.setShouldEnableTextAutosizingBoost(store.getBoolValueForKey(WebPreferencesKey::shouldEnableTextAutosizingBoostKey()));
#endif
    settings.setUseImageDocumentForSubframePDF(store.getBoolValueForKey(WebPreferencesKey::useImageDocumentForSubframePDFKey()));
    settings.setFixedFontFamily(store.getStringValueForKey(WebPreferencesKey::fixedFontFamilyKey()));
    settings.setShouldIgnoreMetaViewport(store.getBoolValueForKey(WebPreferencesKey::shouldIgnoreMetaViewportKey()));
    settings.setShouldPrintBackgrounds(store.getBoolValueForKey(WebPreferencesKey::shouldPrintBackgroundsKey()));
    settings.setCursiveFontFamily(store.getStringValueForKey(WebPreferencesKey::cursiveFontFamilyKey()));
    settings.setShouldRespectImageOrientation(store.getBoolValueForKey(WebPreferencesKey::shouldRespectImageOrientationKey()));
    settings.setShouldRestrictBaseURLSchemes(store.getBoolValueForKey(WebPreferencesKey::shouldRestrictBaseURLSchemesKey()));
    settings.setShouldSuppressTextInputFromEditingDuringProvisionalNavigation(store.getBoolValueForKey(WebPreferencesKey::shouldSuppressTextInputFromEditingDuringProvisionalNavigationKey()));
    settings.setFantasyFontFamily(store.getStringValueForKey(WebPreferencesKey::fantasyFontFamilyKey()));
    settings.setDOMPasteAllowed(store.getBoolValueForKey(WebPreferencesKey::domPasteAllowedKey()));
    settings.setShouldUseServiceWorkerShortTimeout(store.getBoolValueForKey(WebPreferencesKey::shouldUseServiceWorkerShortTimeoutKey()));
    settings.setFTPDirectoryTemplatePath(store.getStringValueForKey(WebPreferencesKey::ftpDirectoryTemplatePathKey()));
#if ENABLE(DATA_DETECTION)
    settings.setDataDetectorTypes(static_cast<WebCore::DataDetectorType>(store.getUInt32ValueForKey(WebPreferencesKey::dataDetectorTypesKey())));
#endif
    settings.setTreatsAnyTextCSSLinkAsStylesheet(store.getBoolValueForKey(WebPreferencesKey::treatsAnyTextCSSLinkAsStylesheetKey()));
    settings.setLinkPreloadEnabled(store.getBoolValueForKey(WebPreferencesKey::linkPreloadEnabledKey()));
    settings.setShowsToolTipOverTruncatedText(store.getBoolValueForKey(WebPreferencesKey::showsToolTipOverTruncatedTextKey()));
    settings.setDefaultFixedFontSize(store.getDoubleValueForKey(WebPreferencesKey::defaultFixedFontSizeKey()));
    settings.setDefaultFontSize(store.getDoubleValueForKey(WebPreferencesKey::defaultFontSizeKey()));
    settings.setDefaultTextEncodingName(store.getStringValueForKey(WebPreferencesKey::defaultTextEncodingNameKey()));
    settings.setTextInteractionEnabled(store.getBoolValueForKey(WebPreferencesKey::textInteractionEnabledKey()));
#if ENABLE(TEXT_AUTOSIZING)
    settings.setTextAutosizingEnabled(store.getBoolValueForKey(WebPreferencesKey::textAutosizingEnabledKey()));
#endif
    settings.setDeveloperExtrasEnabled(store.getBoolValueForKey(WebPreferencesKey::developerExtrasEnabledKey()));
    settings.setDeviceHeight(store.getUInt32ValueForKey(WebPreferencesKey::deviceHeightKey()));
#if ENABLE(DEVICE_ORIENTATION)
    settings.setDeviceOrientationEventEnabled(store.getBoolValueForKey(WebPreferencesKey::deviceOrientationEventEnabledKey()));
#endif
#if ENABLE(DEVICE_ORIENTATION)
    settings.setDeviceOrientationPermissionAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::deviceOrientationPermissionAPIEnabledKey()));
#endif
    settings.setDeviceWidth(store.getUInt32ValueForKey(WebPreferencesKey::deviceWidthKey()));
    settings.setShowsURLsInToolTips(store.getBoolValueForKey(WebPreferencesKey::showsURLsInToolTipsEnabledKey()));
    settings.setTextAreasAreResizable(store.getBoolValueForKey(WebPreferencesKey::textAreasAreResizableKey()));
    settings.setTemporaryTileCohortRetentionEnabled(store.getBoolValueForKey(WebPreferencesKey::temporaryTileCohortRetentionEnabledKey()));
    settings.setTelephoneNumberParsingEnabled(store.getBoolValueForKey(WebPreferencesKey::telephoneNumberParsingEnabledKey()));
    settings.setShrinksStandaloneImagesToFit(store.getBoolValueForKey(WebPreferencesKey::shrinksStandaloneImagesToFitKey()));
    settings.setDisabledAdaptationsMetaTagEnabled(store.getBoolValueForKey(WebPreferencesKey::disabledAdaptationsMetaTagEnabledKey()));
    settings.setDownloadAttributeEnabled(store.getBoolValueForKey(WebPreferencesKey::downloadAttributeEnabledKey()));
    settings.setEditableLinkBehavior(static_cast<WebCore::EditableLinkBehavior>(store.getUInt32ValueForKey(WebPreferencesKey::editableLinkBehaviorKey())));
#if USE(SYSTEM_PREVIEW)
    settings.setSystemPreviewEnabled(store.getBoolValueForKey(WebPreferencesKey::systemPreviewEnabledKey()));
#endif
    settings.setSystemLayoutDirection(static_cast<WebCore::TextDirection>(store.getUInt32ValueForKey(WebPreferencesKey::systemLayoutDirectionKey())));
    settings.setSuppressesIncrementalRendering(store.getBoolValueForKey(WebPreferencesKey::suppressesIncrementalRenderingKey()));
    settings.setStandardFontFamily(store.getStringValueForKey(WebPreferencesKey::standardFontFamilyKey()));
    settings.setEnableInheritURIQueryComponent(store.getBoolValueForKey(WebPreferencesKey::enableInheritURIQueryComponentKey()));
#if ENABLE(ENCRYPTED_MEDIA)
    settings.setEncryptedMediaAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::encryptedMediaAPIEnabledKey()));
#endif
    settings.setStandalone(store.getBoolValueForKey(WebPreferencesKey::standaloneKey()));
    settings.setSmartInsertDeleteEnabled(store.getBoolValueForKey(WebPreferencesKey::smartInsertDeleteEnabledKey()));
    settings.setSpatialNavigationEnabled(store.getBoolValueForKey(WebPreferencesKey::spatialNavigationEnabledKey()));
#if ENABLE(MEDIA_SOURCE)
    settings.setSourceBufferChangeTypeEnabled(store.getBoolValueForKey(WebPreferencesKey::sourceBufferChangeTypeEnabledKey()));
#endif
    settings.setTargetTextPseudoElementEnabled(store.getBoolValueForKey(WebPreferencesKey::targetTextPseudoElementEnabledKey()));
    settings.setThumbAndTrackPseudoElementsEnabled(store.getBoolValueForKey(WebPreferencesKey::thumbAndTrackPseudoElementsEnabledKey()));
    settings.setLinkDNSPrefetchEnabled(store.getBoolValueForKey(WebPreferencesKey::linkDNSPrefetchEnabledKey()));
    settings.setSelectShowPickerEnabled(store.getBoolValueForKey(WebPreferencesKey::selectShowPickerEnabledKey()));
    settings.setPageAtRuleMarginDescriptorsEnabled(store.getBoolValueForKey(WebPreferencesKey::pageAtRuleMarginDescriptorsEnabledKey()));
#if HAVE(AVKIT_CONTENT_SOURCE)
    settings.setAVKitContentSourceEnabled(store.getBoolValueForKey(WebPreferencesKey::isAVKitContentSourceEnabledKey()));
#endif
#if USE(CORE_IMAGE)
    settings.setAcceleratedFiltersEnabled(store.getBoolValueForKey(WebPreferencesKey::acceleratedFiltersEnabledKey()));
#endif
    settings.setAccessHandleEnabled(store.getBoolValueForKey(WebPreferencesKey::accessHandleEnabledKey()));
    settings.setDOMTestingAPIsEnabled(store.getBoolValueForKey(WebPreferencesKey::domTestingAPIsEnabledKey()));
    settings.setAllowMediaContentTypesRequiringHardwareSupportAsFallback(store.getBoolValueForKey(WebPreferencesKey::allowMediaContentTypesRequiringHardwareSupportAsFallbackKey()));
    settings.setAllowPrivacySensitiveOperationsInNonPersistentDataStores(store.getBoolValueForKey(WebPreferencesKey::allowPrivacySensitiveOperationsInNonPersistentDataStoresKey()));
#if PLATFORM(IOS_FAMILY)
    settings.setAllowViewportShrinkToFitContent(store.getBoolValueForKey(WebPreferencesKey::allowViewportShrinkToFitContentKey()));
#endif
#if ENABLE(WEBGL)
    settings.setAllowWebGLInWorkers(store.getBoolValueForKey(WebPreferencesKey::allowWebGLInWorkersKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setPerElementSpeakerSelectionEnabled(store.getBoolValueForKey(WebPreferencesKey::perElementSpeakerSelectionEnabledKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setExposeSpeakersWithoutMicrophoneEnabled(store.getBoolValueForKey(WebPreferencesKey::exposeSpeakersWithoutMicrophoneEnabledKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setExposeSpeakersEnabled(store.getBoolValueForKey(WebPreferencesKey::exposeSpeakersEnabledKey()));
#endif
    settings.setAllowTopNavigationToDataURLs(store.getBoolValueForKey(WebPreferencesKey::allowTopNavigationToDataURLsKey()));
    settings.setAllowUniversalAccessFromFileURLs(store.getBoolValueForKey(WebPreferencesKey::allowUniversalAccessFromFileURLsKey()));
#if ENABLE(WEB_ARCHIVE)
    settings.setAlwaysAllowLocalWebarchive(store.getBoolValueForKey(WebPreferencesKey::alwaysAllowLocalWebarchiveKey()));
#endif
    settings.setAppBadgeEnabled(store.getBoolValueForKey(WebPreferencesKey::appBadgeEnabledKey()));
#if ENABLE(APP_HIGHLIGHTS)
    settings.setAppHighlightsEnabled(store.getBoolValueForKey(WebPreferencesKey::appHighlightsEnabledKey()));
#endif
    settings.setAsyncFrameScrollingEnabled(store.getBoolValueForKey(WebPreferencesKey::asyncFrameScrollingEnabledKey()));
    settings.setAsyncOverflowScrollingEnabled(store.getBoolValueForKey(WebPreferencesKey::asyncOverflowScrollingEnabledKey()));
#if PLATFORM(IOS_FAMILY)
    settings.setUseAsyncUIKitInteractions(store.getBoolValueForKey(WebPreferencesKey::useAsyncUIKitInteractionsKey()));
#endif
    settings.setAsyncClipboardAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::asyncClipboardAPIEnabledKey()));
#if ENABLE(ATTACHMENT_ELEMENT)
    settings.setAttachmentWideLayoutEnabled(store.getBoolValueForKey(WebPreferencesKey::attachmentWideLayoutEnabledKey()));
#endif
#if ENABLE(VIDEO)
    settings.setExtendedAudioDescriptionsEnabled(store.getBoolValueForKey(WebPreferencesKey::extendedAudioDescriptionsEnabledKey()));
#endif
#if ENABLE(VIDEO)
    settings.setAudioDescriptionsEnabled(store.getBoolValueForKey(WebPreferencesKey::audioDescriptionsEnabledKey()));
#endif
#if ENABLE(DOM_AUDIO_SESSION)
    settings.setDOMAudioSessionEnabled(store.getBoolValueForKey(WebPreferencesKey::domAudioSessionEnabledKey()));
#endif
#if ENABLE(DOM_AUDIO_SESSION)
    settings.setDOMAudioSessionFullEnabled(store.getBoolValueForKey(WebPreferencesKey::domAudioSessionFullEnabledKey()));
#endif
    settings.setAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth(store.getBoolValueForKey(WebPreferencesKey::automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidthKey()));
    settings.setBeaconAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::beaconAPIEnabledKey()));
    settings.setBidiContentAwarePasteEnabled(store.getBoolValueForKey(WebPreferencesKey::bidiContentAwarePasteEnabledKey()));
    settings.setBroadcastChannelEnabled(store.getBoolValueForKey(WebPreferencesKey::broadcastChannelEnabledKey()));
    settings.setCSS3DTransformBackfaceVisibilityInteroperabilityEnabled(store.getBoolValueForKey(WebPreferencesKey::css3DTransformBackfaceVisibilityInteroperabilityEnabledKey()));
    settings.setCSSCounterStyleAtRuleImageSymbolsEnabled(store.getBoolValueForKey(WebPreferencesKey::cssCounterStyleAtRuleImageSymbolsEnabledKey()));
    settings.setAccentColorEnabled(store.getBoolValueForKey(WebPreferencesKey::accentColorEnabledKey()));
    settings.setCSSAnchorPositioningEnabled(store.getBoolValueForKey(WebPreferencesKey::cssAnchorPositioningEnabledKey()));
    settings.setCSSAnchorPositioningPositionVisibilityEnabled(store.getBoolValueForKey(WebPreferencesKey::cssAnchorPositioningPositionVisibilityEnabledKey()));
    settings.setDevolvableWidgetsEnabled(store.getBoolValueForKey(WebPreferencesKey::devolvableWidgetsEnabledKey()));
    settings.setCSSInputSecurityEnabled(store.getBoolValueForKey(WebPreferencesKey::cssInputSecurityEnabledKey()));
    settings.setMasonryEnabled(store.getBoolValueForKey(WebPreferencesKey::masonryEnabledKey()));
    settings.setOverscrollBehaviorEnabled(store.getBoolValueForKey(WebPreferencesKey::overscrollBehaviorEnabledKey()));
    settings.setCSSPaintingAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::cssPaintingAPIEnabledKey()));
    settings.setCSSRhythmicSizingEnabled(store.getBoolValueForKey(WebPreferencesKey::cssRhythmicSizingEnabledKey()));
    settings.setCSSScrollAnchoringEnabled(store.getBoolValueForKey(WebPreferencesKey::cssScrollAnchoringEnabledKey()));
    settings.setSpringTimingFunctionEnabled(store.getBoolValueForKey(WebPreferencesKey::springTimingFunctionEnabledKey()));
    settings.setCSSTreeCountingFunctionsEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTreeCountingFunctionsEnabledKey()));
    settings.setCSSTypedOMColorEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTypedOMColorEnabledKey()));
    settings.setCSSURLModifiersEnabled(store.getBoolValueForKey(WebPreferencesKey::cssURLModifiersEnabledKey()));
    settings.setCSSURLIntegrityModifierEnabled(store.getBoolValueForKey(WebPreferencesKey::cssURLIntegrityModifierEnabledKey()));
    settings.setCSSUnprefixedBackdropFilterEnabled(store.getBoolValueForKey(WebPreferencesKey::cssUnprefixedBackdropFilterEnabledKey()));
    settings.setCSSAppearanceBaseEnabled(store.getBoolValueForKey(WebPreferencesKey::cssAppearanceBaseEnabledKey()));
    settings.setCSSAxisRelativePositionKeywordsEnabled(store.getBoolValueForKey(WebPreferencesKey::cssAxisRelativePositionKeywordsEnabledKey()));
    settings.setCSSBackgroundClipBorderAreaEnabled(store.getBoolValueForKey(WebPreferencesKey::cssBackgroundClipBorderAreaEnabledKey()));
    settings.setCSSColorLayersEnabled(store.getBoolValueForKey(WebPreferencesKey::cssColorLayersEnabledKey()));
    settings.setCSSContrastColorEnabled(store.getBoolValueForKey(WebPreferencesKey::cssContrastColorEnabledKey()));
    settings.setCSSCornerShapeEnabled(store.getBoolValueForKey(WebPreferencesKey::cssCornerShapeEnabledKey()));
    settings.setCSSDPropertyEnabled(store.getBoolValueForKey(WebPreferencesKey::cssDPropertyEnabledKey()));
    settings.setCSSDynamicRangeLimitMixEnabled(store.getBoolValueForKey(WebPreferencesKey::cssDynamicRangeLimitMixEnabledKey()));
    settings.setCSSConstrainedDynamicRangeLimitEnabled(store.getBoolValueForKey(WebPreferencesKey::cssConstrainedDynamicRangeLimitEnabledKey()));
    settings.setCSSFieldSizingEnabled(store.getBoolValueForKey(WebPreferencesKey::cssFieldSizingEnabledKey()));
    settings.setCSSFontVariantEmojiEnabled(store.getBoolValueForKey(WebPreferencesKey::cssFontVariantEmojiEnabledKey()));
    settings.setCSSLineClampEnabled(store.getBoolValueForKey(WebPreferencesKey::cssLineClampEnabledKey()));
    settings.setCSSLineFitEdgeEnabled(store.getBoolValueForKey(WebPreferencesKey::cssLineFitEdgeEnabledKey()));
    settings.setCSSProgressFunctionEnabled(store.getBoolValueForKey(WebPreferencesKey::cssProgressFunctionEnabledKey()));
    settings.setCSSRandomFunctionEnabled(store.getBoolValueForKey(WebPreferencesKey::cssRandomFunctionEnabledKey()));
    settings.setCSSRubyAlignEnabled(store.getBoolValueForKey(WebPreferencesKey::cssRubyAlignEnabledKey()));
    settings.setCSSRubyOverhangEnabled(store.getBoolValueForKey(WebPreferencesKey::cssRubyOverhangEnabledKey()));
    settings.setCSSScrollbarColorEnabled(store.getBoolValueForKey(WebPreferencesKey::cssScrollbarColorEnabledKey()));
    settings.setCSSScrollbarGutterEnabled(store.getBoolValueForKey(WebPreferencesKey::cssScrollbarGutterEnabledKey()));
    settings.setCSSScrollbarWidthEnabled(store.getBoolValueForKey(WebPreferencesKey::cssScrollbarWidthEnabledKey()));
    settings.setCSSShapeFunctionEnabled(store.getBoolValueForKey(WebPreferencesKey::cssShapeFunctionEnabledKey()));
    settings.setCSSTextAutospaceEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTextAutospaceEnabledKey()));
    settings.setCSSTextBoxTrimEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTextBoxTrimEnabledKey()));
    settings.setCSSTextGroupAlignEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTextGroupAlignEnabledKey()));
    settings.setCSSTextJustifyEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTextJustifyEnabledKey()));
    settings.setCSSTextSpacingTrimEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTextSpacingTrimEnabledKey()));
    settings.setCSSTextUnderlinePositionLeftRightEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTextUnderlinePositionLeftRightEnabledKey()));
    settings.setCSSTextWrapPrettyEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTextWrapPrettyEnabledKey()));
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
    settings.setCSSTransformStyleSeparatedEnabled(store.getBoolValueForKey(WebPreferencesKey::cssTransformStyleSeparatedEnabledKey()));
#endif
    settings.setCacheAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::cacheAPIEnabledKey()));
    settings.setCanvasColorSpaceEnabled(store.getBoolValueForKey(WebPreferencesKey::canvasColorSpaceEnabledKey()));
    settings.setCanvasFiltersEnabled(store.getBoolValueForKey(WebPreferencesKey::canvasFiltersEnabledKey()));
    settings.setCanvasLayersEnabled(store.getBoolValueForKey(WebPreferencesKey::canvasLayersEnabledKey()));
#if USE(CA) || USE(SKIA)
    settings.setCanvasUsesAcceleratedDrawing(store.getBoolValueForKey(WebPreferencesKey::canvasUsesAcceleratedDrawingKey()));
#endif
    settings.setCanvasPixelFormatEnabled(store.getBoolValueForKey(WebPreferencesKey::canvasPixelFormatEnabledKey()));
    settings.setChildProcessDebuggabilityEnabled(store.getBoolValueForKey(WebPreferencesKey::childProcessDebuggabilityEnabledKey()));
    settings.setClearSiteDataHTTPHeaderEnabled(store.getBoolValueForKey(WebPreferencesKey::clearSiteDataHTTPHeaderEnabledKey()));
    settings.setClearSiteDataExecutionContextsSupportEnabled(store.getBoolValueForKey(WebPreferencesKey::clearSiteDataExecutionContextsSupportEnabledKey()));
    settings.setCloseWatcherEnabled(store.getBoolValueForKey(WebPreferencesKey::closeWatcherEnabledKey()));
    settings.setInputTypeColorEnabled(store.getBoolValueForKey(WebPreferencesKey::inputTypeColorEnabledKey()));
    settings.setShowDebugBorders(store.getBoolValueForKey(WebPreferencesKey::compositingBordersVisibleKey()));
    settings.setShowRepaintCounter(store.getBoolValueForKey(WebPreferencesKey::compositingRepaintCountersVisibleKey()));
    settings.setCompressionStreamEnabled(store.getBoolValueForKey(WebPreferencesKey::compressionStreamEnabledKey()));
    settings.setContactPickerAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::contactPickerAPIEnabledKey()));
    settings.setContentInsetBackgroundFillEnabled(store.getBoolValueForKey(WebPreferencesKey::contentInsetBackgroundFillEnabledKey()));
    settings.setCookieConsentAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::cookieConsentAPIEnabledKey()));
    settings.setCookieStoreManagerEnabled(store.getBoolValueForKey(WebPreferencesKey::cookieStoreManagerEnabledKey()));
    settings.setCookieStoreAPIExtendedAttributesEnabled(store.getBoolValueForKey(WebPreferencesKey::cookieStoreAPIExtendedAttributesEnabledKey()));
    settings.setCookieStoreAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::cookieStoreAPIEnabledKey()));
    settings.setCookieEnabled(store.getBoolValueForKey(WebPreferencesKey::cookieEnabledKey()));
#if PLATFORM(MAC)
    settings.setInputMethodUsesCorrectKeyEventOrder(store.getBoolValueForKey(WebPreferencesKey::inputMethodUsesCorrectKeyEventOrderKey()));
#endif
    settings.setCrossDocumentViewTransitionsEnabled(store.getBoolValueForKey(WebPreferencesKey::crossDocumentViewTransitionsEnabledKey()));
    settings.setCrossOriginEmbedderPolicyEnabled(store.getBoolValueForKey(WebPreferencesKey::crossOriginEmbedderPolicyEnabledKey()));
    settings.setCrossOriginOpenerPolicyEnabled(store.getBoolValueForKey(WebPreferencesKey::crossOriginOpenerPolicyEnabledKey()));
    settings.setDOMPasteAccessRequestsEnabled(store.getBoolValueForKey(WebPreferencesKey::domPasteAccessRequestsEnabledKey()));
    settings.setMutationEventsEnabled(store.getBoolValueForKey(WebPreferencesKey::mutationEventsEnabledKey()));
    settings.setDOMTimersThrottlingEnabled(store.getBoolValueForKey(WebPreferencesKey::domTimersThrottlingEnabledKey()));
    settings.setDataTransferItemsEnabled(store.getBoolValueForKey(WebPreferencesKey::dataTransferItemsEnabledKey()));
    settings.setDataListElementEnabled(store.getBoolValueForKey(WebPreferencesKey::dataListElementEnabledKey()));
    settings.setInputTypeDateEnabled(store.getBoolValueForKey(WebPreferencesKey::inputTypeDateEnabledKey()));
    settings.setDateTimeInputsEditableComponentsEnabled(store.getBoolValueForKey(WebPreferencesKey::dateTimeInputsEditableComponentsEnabledKey()));
#if ENABLE(DECLARATIVE_WEB_PUSH)
    settings.setDeclarativeWebPush(store.getBoolValueForKey(WebPreferencesKey::declarativeWebPushKey()));
#endif
    settings.setShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint(store.getBoolValueForKey(WebPreferencesKey::shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaintKey()));
    settings.setDeprecationReportingEnabled(store.getBoolValueForKey(WebPreferencesKey::deprecationReportingEnabledKey()));
#if ENABLE(MEDIA_SOURCE)
    settings.setDetachableMediaSourceEnabled(store.getBoolValueForKey(WebPreferencesKey::detachableMediaSourceEnabledKey()));
#endif
    settings.setUAVisualTransitionDetectionEnabled(store.getBoolValueForKey(WebPreferencesKey::uAVisualTransitionDetectionEnabledKey()));
    settings.setDiagnosticLoggingEnabled(store.getBoolValueForKey(WebPreferencesKey::diagnosticLoggingEnabledKey()));
#if ENABLE(WEB_AUTHN)
    settings.setDigitalCredentialsEnabled(store.getBoolValueForKey(WebPreferencesKey::digitalCredentialsEnabledKey()));
#endif
    settings.setDirectoryUploadEnabled(store.getBoolValueForKey(WebPreferencesKey::directoryUploadEnabledKey()));
    settings.setIsThirdPartyCookieBlockingDisabled(store.getBoolValueForKey(WebPreferencesKey::isThirdPartyCookieBlockingDisabledKey()));
    settings.setIsFirstPartyWebsiteDataRemovalDisabled(store.getBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalDisabledKey()));
    settings.setShouldDropNearSuspendedAssertionAfterDelay(store.getBoolValueForKey(WebPreferencesKey::shouldDropNearSuspendedAssertionAfterDelayKey()));
    settings.setDynamicSiteInterventionsEnabled(store.getBoolValueForKey(WebPreferencesKey::dynamicSiteInterventionsEnabledKey()));
    settings.setEmbedElementEnabled(store.getBoolValueForKey(WebPreferencesKey::embedElementEnabledKey()));
    settings.setCanvasFingerprintingQuirkEnabled(store.getBoolValueForKey(WebPreferencesKey::canvasFingerprintingQuirkEnabledKey()));
    settings.setEnableElementCurrentCSSZoom(store.getBoolValueForKey(WebPreferencesKey::enableElementCurrentCSSZoomKey()));
    settings.setICECandidateFilteringEnabled(store.getBoolValueForKey(WebPreferencesKey::iceCandidateFilteringEnabledKey()));
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    settings.setLegacyEncryptedMediaAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::legacyEncryptedMediaAPIEnabledKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setMockCaptureDevicesEnabled(store.getBoolValueForKey(WebPreferencesKey::mockCaptureDevicesEnabledKey()));
#endif
#if ENABLE(MODEL_PROCESS)
    settings.setModelProcessEnabled(store.getBoolValueForKey(WebPreferencesKey::modelProcessEnabledKey()));
#endif
#if ENABLE(PDFJS)
    settings.setPDFJSViewerEnabled(store.getBoolValueForKey(WebPreferencesKey::pdfJSViewerEnabledKey()));
#endif
    settings.setAuxclickEventEnabled(store.getBoolValueForKey(WebPreferencesKey::auxclickEventEnabledKey()));
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
    settings.setBackgroundWebContentRunningBoardThrottlingEnabled(store.getBoolValueForKey(WebPreferencesKey::backgroundWebContentRunningBoardThrottlingEnabledKey()));
#endif
    settings.setBackgroundFetchAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::backgroundFetchAPIEnabledKey()));
    settings.setNavigatorUserAgentDataJavaScriptAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::navigatorUserAgentDataJavaScriptAPIEnabledKey()));
    settings.setBlobFileAccessEnforcementEnabled(store.getBoolValueForKey(WebPreferencesKey::blobFileAccessEnforcementEnabledKey()));
    settings.setEnterKeyHintEnabled(store.getBoolValueForKey(WebPreferencesKey::enterKeyHintEnabledKey()));
    settings.setEventTimingEnabled(store.getBoolValueForKey(WebPreferencesKey::eventTimingEnabledKey()));
    settings.setEventHandlerDrivenSmoothKeyboardScrollingEnabled(store.getBoolValueForKey(WebPreferencesKey::eventHandlerDrivenSmoothKeyboardScrollingEnabledKey()));
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    settings.setMediaSessionCoordinatorEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaSessionCoordinatorEnabledKey()));
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
    settings.setMediaSessionPlaylistEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaSessionPlaylistEnabledKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setExposeCaptureDevicesAfterCaptureEnabled(store.getBoolValueForKey(WebPreferencesKey::exposeCaptureDevicesAfterCaptureEnabledKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setExposeDefaultSpeakerAsSpecificDeviceEnabled(store.getBoolValueForKey(WebPreferencesKey::exposeDefaultSpeakerAsSpecificDeviceEnabledKey()));
#endif
    settings.setFTPEnabled(store.getBoolValueForKey(WebPreferencesKey::ftpEnabledKey()));
    settings.setFileSystemEnabled(store.getBoolValueForKey(WebPreferencesKey::fileSystemEnabledKey()));
    settings.setFileSystemWritableStreamEnabled(store.getBoolValueForKey(WebPreferencesKey::fileSystemWritableStreamEnabledKey()));
    settings.setFileReaderAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::fileReaderAPIEnabledKey()));
    settings.setFilterLinkDecorationByDefaultEnabled(store.getBoolValueForKey(WebPreferencesKey::filterLinkDecorationByDefaultEnabledKey()));
    settings.setForceLockdownFontParserEnabled(store.getBoolValueForKey(WebPreferencesKey::forceLockdownFontParserEnabledKey()));
#if ENABLE(FORM_CONTROL_REFRESH)
    settings.setFormControlRefreshEnabled(store.getBoolValueForKey(WebPreferencesKey::formControlRefreshEnabledKey()));
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    settings.setIFrameResourceMonitoringTestingSettingsEnabled(store.getBoolValueForKey(WebPreferencesKey::iFrameResourceMonitoringTestingSettingsEnabledKey()));
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    settings.setIFrameResourceMonitoringEnabled(store.getBoolValueForKey(WebPreferencesKey::iFrameResourceMonitoringEnabledKey()));
#endif
#if ENABLE(FULLSCREEN_API)
    settings.setFullScreenKeyboardLock(store.getBoolValueForKey(WebPreferencesKey::fullScreenKeyboardLockKey()));
#endif
#if ENABLE(FULLSCREEN_API)
    settings.setFullScreenEnabled(store.getBoolValueForKey(WebPreferencesKey::fullScreenEnabledKey()));
#endif
#if PLATFORM(VISION)
    settings.setFullscreenSceneAspectRatioLockingEnabled(store.getBoolValueForKey(WebPreferencesKey::fullscreenSceneAspectRatioLockingEnabledKey()));
#endif
#if PLATFORM(VISION)
    settings.setFullscreenSceneDimmingEnabled(store.getBoolValueForKey(WebPreferencesKey::fullscreenSceneDimmingEnabledKey()));
#endif
#if ENABLE(GPU_PROCESS)
    settings.setBlockMediaLayerRehostingInWebContentProcess(store.getBoolValueForKey(WebPreferencesKey::blockMediaLayerRehostingInWebContentProcessKey()));
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
    settings.setManageCaptureStatusBarInGPUProcessEnabled(store.getBoolValueForKey(WebPreferencesKey::manageCaptureStatusBarInGPUProcessEnabledKey()));
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
    settings.setUseGPUProcessForWebGLEnabled(store.getBoolValueForKey(WebPreferencesKey::useGPUProcessForWebGLEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCPlatformCodecsInGPUProcessEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCPlatformCodecsInGPUProcessEnabledKey()));
#endif
#if ENABLE(GAMEPAD)
    settings.setGamepadTriggerRumbleEnabled(store.getBoolValueForKey(WebPreferencesKey::gamepadTriggerRumbleEnabledKey()));
#endif
#if ENABLE(GAMEPAD)
    settings.setGamepadVibrationActuatorEnabled(store.getBoolValueForKey(WebPreferencesKey::gamepadVibrationActuatorEnabledKey()));
#endif
#if ENABLE(GAMEPAD)
    settings.setGamepadsEnabled(store.getBoolValueForKey(WebPreferencesKey::gamepadsEnabledKey()));
#endif
#if ENABLE(VIDEO)
    settings.setGenericCueAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::genericCueAPIEnabledKey()));
#endif
    settings.setGeolocationAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::geolocationAPIEnabledKey()));
#if USE(GRAPHICS_CONTEXT_FILTERS)
    settings.setGraphicsContextFiltersEnabled(store.getBoolValueForKey(WebPreferencesKey::graphicsContextFiltersEnabledKey()));
#endif
    settings.setAcceleratedDrawingEnabled(store.getBoolValueForKey(WebPreferencesKey::acceleratedDrawingEnabledKey()));
#if ENABLE(MODEL_ELEMENT)
    settings.setModelElementEnabled(store.getBoolValueForKey(WebPreferencesKey::modelElementEnabledKey()));
#endif
    settings.setInteractiveFormValidationEnabled(store.getBoolValueForKey(WebPreferencesKey::interactiveFormValidationEnabledKey()));
#if ENABLE(VIDEO)
    settings.setMediaEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaEnabledKey()));
#endif
    settings.setInputTypeColorEnhancementsEnabled(store.getBoolValueForKey(WebPreferencesKey::inputTypeColorEnhancementsEnabledKey()));
    settings.setDetailsAutoExpandEnabled(store.getBoolValueForKey(WebPreferencesKey::detailsAutoExpandEnabledKey()));
    settings.setCommandAttributesEnabled(store.getBoolValueForKey(WebPreferencesKey::commandAttributesEnabledKey()));
    settings.setHTMLLegacyAttributeValueSerializationEnabled(store.getBoolValueForKey(WebPreferencesKey::hTMLLegacyAttributeValueSerializationEnabledKey()));
    settings.setPopoverAttributeEnabled(store.getBoolValueForKey(WebPreferencesKey::popoverAttributeEnabledKey()));
    settings.setSwitchControlEnabled(store.getBoolValueForKey(WebPreferencesKey::switchControlEnabledKey()));
    settings.setHttpsByDefault(store.getBoolValueForKey(WebPreferencesKey::httpSByDefaultEnabledKey()));
    settings.setHiddenPageDOMTimerThrottlingAutoIncreases(store.getBoolValueForKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingAutoIncreasesKey()));
    settings.setHiddenPageDOMTimerThrottlingEnabled(store.getBoolValueForKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingEnabledKey()));
#if HAVE(MATERIAL_HOSTING)
    settings.setHostedBlurMaterialInMediaControlsEnabled(store.getBoolValueForKey(WebPreferencesKey::hostedBlurMaterialInMediaControlsEnabledKey()));
#endif
    settings.setIOSurfaceLosslessCompressionEnabled(store.getBoolValueForKey(WebPreferencesKey::iOSurfaceLosslessCompressionEnabledKey()));
    settings.setItpDebugModeEnabled(store.getBoolValueForKey(WebPreferencesKey::itpDebugModeEnabledKey()));
#if ENABLE(TEXT_AUTOSIZING)
    settings.setTextAutosizingUsesIdempotentMode(store.getBoolValueForKey(WebPreferencesKey::textAutosizingUsesIdempotentModeKey()));
#endif
    settings.setIgnoreIframeEmbeddingProtectionsEnabled(store.getBoolValueForKey(WebPreferencesKey::ignoreIframeEmbeddingProtectionsEnabledKey()));
#if ENABLE(IMAGE_ANALYSIS)
    settings.setImageAnalysisDuringFindInPageEnabled(store.getBoolValueForKey(WebPreferencesKey::imageAnalysisDuringFindInPageEnabledKey()));
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    settings.setImageAnimationControlEnabled(store.getBoolValueForKey(WebPreferencesKey::imageAnimationControlEnabledKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setImageCaptureEnabled(store.getBoolValueForKey(WebPreferencesKey::imageCaptureEnabledKey()));
#endif
#if ENABLE(SERVICE_CONTROLS)
    settings.setImageControlsEnabled(store.getBoolValueForKey(WebPreferencesKey::imageControlsEnabledKey()));
#endif
    settings.setInWindowFullscreenEnabled(store.getBoolValueForKey(WebPreferencesKey::inWindowFullscreenEnabledKey()));
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
    settings.setIncludeIgnoredInCoreAXTree(store.getBoolValueForKey(WebPreferencesKey::includeIgnoredInCoreAXTreeKey()));
#endif
    settings.setIndexedDBAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::indexedDBAPIEnabledKey()));
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    settings.setInteractionRegionsEnabled(store.getBoolValueForKey(WebPreferencesKey::interactionRegionsEnabledKey()));
#endif
    settings.setScriptEnabled(store.getBoolValueForKey(WebPreferencesKey::javaScriptEnabledKey()));
    settings.setLayerBasedSVGEngineEnabled(store.getBoolValueForKey(WebPreferencesKey::layerBasedSVGEngineEnabledKey()));
    settings.setLazyIframeLoadingEnabled(store.getBoolValueForKey(WebPreferencesKey::lazyIframeLoadingEnabledKey()));
    settings.setLazyImageLoadingEnabled(store.getBoolValueForKey(WebPreferencesKey::lazyImageLoadingEnabledKey()));
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
    settings.setLegacyOverflowScrollingTouchEnabled(store.getBoolValueForKey(WebPreferencesKey::legacyOverflowScrollingTouchEnabledKey()));
#endif
    settings.setLegacyLineLayoutVisualCoverageEnabled(store.getBoolValueForKey(WebPreferencesKey::legacyLineLayoutVisualCoverageEnabledKey()));
    settings.setShowModalDialogEnabled(store.getBoolValueForKey(WebPreferencesKey::showModalDialogEnabledKey()));
#if ENABLE(MEDIA_STREAM)
    settings.setMediaCaptureRequiresSecureConnection(store.getBoolValueForKey(WebPreferencesKey::mediaCaptureRequiresSecureConnectionKey()));
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    settings.setLimitedMatroskaSupportEnabled(store.getBoolValueForKey(WebPreferencesKey::limitedMatroskaSupportEnabledKey()));
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
    settings.setLinearMediaPlayerEnabled(store.getBoolValueForKey(WebPreferencesKey::linearMediaPlayerEnabledKey()));
#endif
    settings.setLinkSanitizerEnabled(store.getBoolValueForKey(WebPreferencesKey::linkSanitizerEnabledKey()));
    settings.setLinkPreconnectEarlyHintsEnabled(store.getBoolValueForKey(WebPreferencesKey::linkPreconnectEarlyHintsEnabledKey()));
    settings.setLinkPrefetchEnabled(store.getBoolValueForKey(WebPreferencesKey::linkPrefetchEnabledKey()));
#if ENABLE(WEB_ARCHIVE)
    settings.setLoadWebArchiveWithEphemeralStorageEnabled(store.getBoolValueForKey(WebPreferencesKey::loadWebArchiveWithEphemeralStorageEnabledKey()));
#endif
    settings.setLocalFileContentSniffingEnabled(store.getBoolValueForKey(WebPreferencesKey::localFileContentSniffingEnabledKey()));
    settings.setLocalNetworkAccessEnabled(store.getBoolValueForKey(WebPreferencesKey::localNetworkAccessEnabledKey()));
    settings.setLocalStorageEnabled(store.getBoolValueForKey(WebPreferencesKey::localStorageEnabledKey()));
    settings.setLockdownFontParserEnabled(store.getBoolValueForKey(WebPreferencesKey::lockdownFontParserEnabledKey()));
    settings.setLogsPageMessagesToSystemConsoleEnabled(store.getBoolValueForKey(WebPreferencesKey::logsPageMessagesToSystemConsoleEnabledKey()));
    settings.setLoginStatusAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::loginStatusAPIEnabledKey()));
    settings.setMainContentUserGestureOverrideEnabled(store.getBoolValueForKey(WebPreferencesKey::mainContentUserGestureOverrideEnabledKey()));
#if ENABLE(MEDIA_SOURCE)
    settings.setManagedMediaSourceEnabled(store.getBoolValueForKey(WebPreferencesKey::managedMediaSourceEnabledKey()));
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
    settings.setManagedMediaSourceNeedsAirPlay(store.getBoolValueForKey(WebPreferencesKey::managedMediaSourceNeedsAirPlayKey()));
#endif
    settings.setCoreMathMLEnabled(store.getBoolValueForKey(WebPreferencesKey::coreMathMLEnabledKey()));
    settings.setMediaCapabilitiesExtensionsEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaCapabilitiesExtensionsEnabledKey()));
#if ENABLE(EXTENSION_CAPABILITIES)
    settings.setMediaCapabilityGrantsEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaCapabilityGrantsEnabledKey()));
#endif
    settings.setMediaPlaybackEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaPlaybackEnabledKey()));
#if ENABLE(MEDIA_SESSION)
    settings.setMediaSessionEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaSessionEnabledKey()));
#endif
    settings.setMediaSourceEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaSourceEnabledKey()));
#if ENABLE(MEDIA_STREAM)
    settings.setMediaDevicesEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaDevicesEnabledKey()));
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    settings.setMediaRecorderEnabledWebM(store.getBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledWebMKey()));
#endif
#if ENABLE(MEDIA_RECORDER)
    settings.setMediaRecorderEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledKey()));
#endif
    settings.setMediaSessionCaptureToggleAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaSessionCaptureToggleAPIEnabledKey()));
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
    settings.setMediaSourceInWorkerEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaSourceInWorkerEnabledKey()));
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
    settings.setMediaSourcePrefersDecompressionSession(store.getBoolValueForKey(WebPreferencesKey::mediaSourcePrefersDecompressionSessionKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setMediaStreamTrackProcessingEnabled(store.getBoolValueForKey(WebPreferencesKey::mediaStreamTrackProcessingEnabledKey()));
#endif
    settings.setMetaViewportInteractiveWidgetEnabled(store.getBoolValueForKey(WebPreferencesKey::metaViewportInteractiveWidgetEnabledKey()));
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    settings.setModelNoPortalAttributeEnabled(store.getBoolValueForKey(WebPreferencesKey::modelNoPortalAttributeEnabledKey()));
#endif
#if USE(MODERN_AVCONTENTKEYSESSION)
    settings.setShouldUseModernAVContentKeySession(store.getBoolValueForKey(WebPreferencesKey::shouldUseModernAVContentKeySessionKey()));
#endif
    settings.setMomentumScrollingAnimatorEnabled(store.getBoolValueForKey(WebPreferencesKey::momentumScrollingAnimatorEnabledKey()));
    settings.setInputTypeMonthEnabled(store.getBoolValueForKey(WebPreferencesKey::inputTypeMonthEnabledKey()));
#if ENABLE(TOUCH_EVENTS)
    settings.setMouseEventsSimulationEnabled(store.getBoolValueForKey(WebPreferencesKey::mouseEventsSimulationEnabledKey()));
#endif
#if ENABLE(MEDIA_STREAM)
    settings.setMuteCameraOnMicrophoneInterruptionEnabled(store.getBoolValueForKey(WebPreferencesKey::muteCameraOnMicrophoneInterruptionEnabledKey()));
#endif
    settings.setNavigationAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::navigationAPIEnabledKey()));
    settings.setNeedsSiteSpecificQuirks(store.getBoolValueForKey(WebPreferencesKey::needsSiteSpecificQuirksKey()));
    settings.setNeedsStorageAccessFromFileURLsQuirk(store.getBoolValueForKey(WebPreferencesKey::needsStorageAccessFromFileURLsQuirkKey()));
    settings.setFlexFormattingContextIntegrationEnabled(store.getBoolValueForKey(WebPreferencesKey::flexFormattingContextIntegrationEnabledKey()));
#if ENABLE(NOTIFICATION_EVENT)
    settings.setNotificationEventEnabled(store.getBoolValueForKey(WebPreferencesKey::notificationEventEnabledKey()));
#endif
#if ENABLE(NOTIFICATIONS)
    settings.setNotificationsEnabled(store.getBoolValueForKey(WebPreferencesKey::notificationsEnabledKey()));
#endif
    settings.setObservableEnabled(store.getBoolValueForKey(WebPreferencesKey::observableEnabledKey()));
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
    settings.setOffscreenCanvasInWorkersEnabled(store.getBoolValueForKey(WebPreferencesKey::offscreenCanvasInWorkersEnabledKey()));
#endif
#if ENABLE(OFFSCREEN_CANVAS)
    settings.setOffscreenCanvasEnabled(store.getBoolValueForKey(WebPreferencesKey::offscreenCanvasEnabledKey()));
#endif
    settings.setOpportunisticSweepingAndGarbageCollectionEnabled(store.getBoolValueForKey(WebPreferencesKey::opportunisticSweepingAndGarbageCollectionEnabledKey()));
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
    settings.setOptInPartitionedCookiesEnabled(store.getBoolValueForKey(WebPreferencesKey::optInPartitionedCookiesEnabledKey()));
#endif
    settings.setOverlappingBackingStoreProvidersEnabled(store.getBoolValueForKey(WebPreferencesKey::overlappingBackingStoreProvidersEnabledKey()));
    settings.setPermissionsAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::permissionsAPIEnabledKey()));
#if HAVE(PIP_SKIP_PREROLL)
    settings.setPictureInPicturePlaybackStateEnabled(store.getBoolValueForKey(WebPreferencesKey::pictureInPicturePlaybackStateEnabledKey()));
#endif
    settings.setGetCoalescedEventsEnabled(store.getBoolValueForKey(WebPreferencesKey::getCoalescedEventsEnabledKey()));
    settings.setGetPredictedEventsEnabled(store.getBoolValueForKey(WebPreferencesKey::getPredictedEventsEnabledKey()));
#if ENABLE(POINTER_LOCK)
    settings.setPointerLockEnabled(store.getBoolValueForKey(WebPreferencesKey::pointerLockEnabledKey()));
#endif
#if ENABLE(POINTER_LOCK)
    settings.setPointerLockOptionsEnabled(store.getBoolValueForKey(WebPreferencesKey::pointerLockOptionsEnabledKey()));
#endif
    settings.setPreferPageRenderingUpdatesNear60FPSEnabled(store.getBoolValueForKey(WebPreferencesKey::preferPageRenderingUpdatesNear60FPSEnabledKey()));
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    settings.setPreferSpatialAudioExperience(store.getBoolValueForKey(WebPreferencesKey::preferSpatialAudioExperienceKey()));
#endif
#if ENABLE(FULLSCREEN_API)
    settings.setVideoFullsceenPrefersMostVisibleHeuristic(store.getBoolValueForKey(WebPreferencesKey::videoFullsceenPrefersMostVisibleHeuristicKey()));
#endif
    settings.setPrivateClickMeasurementDebugModeEnabled(store.getBoolValueForKey(WebPreferencesKey::privateClickMeasurementDebugModeEnabledKey()));
    settings.setPrivateClickMeasurementFraudPreventionEnabled(store.getBoolValueForKey(WebPreferencesKey::privateClickMeasurementFraudPreventionEnabledKey()));
    settings.setPrivateClickMeasurementEnabled(store.getBoolValueForKey(WebPreferencesKey::privateClickMeasurementEnabledKey()));
    settings.setPrivateTokenUsageByThirdPartyEnabled(store.getBoolValueForKey(WebPreferencesKey::privateTokenUsageByThirdPartyEnabledKey()));
#if ENABLE(DAMAGE_TRACKING)
    settings.setPropagateDamagingInformation(store.getBoolValueForKey(WebPreferencesKey::propagateDamagingInformationKey()));
#endif
    settings.setPushAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::pushAPIEnabledKey()));
    settings.setLegacyPluginQuirkForMailSignaturesEnabled(store.getBoolValueForKey(WebPreferencesKey::legacyPluginQuirkForMailSignaturesEnabledKey()));
    settings.setGoogleAntiFlickerOptimizationQuirkEnabled(store.getBoolValueForKey(WebPreferencesKey::googleAntiFlickerOptimizationQuirkEnabledKey()));
    settings.setRemoteMediaSessionManagerEnabled(store.getBoolValueForKey(WebPreferencesKey::remoteMediaSessionManagerEnabledKey()));
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    settings.setRemotePlaybackEnabled(store.getBoolValueForKey(WebPreferencesKey::remotePlaybackEnabledKey()));
#endif
    settings.setRemoteSnapshottingEnabled(store.getBoolValueForKey(WebPreferencesKey::remoteSnapshottingEnabledKey()));
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    settings.setRemoveBackgroundEnabled(store.getBoolValueForKey(WebPreferencesKey::removeBackgroundEnabledKey()));
#endif
    settings.setRequestVideoFrameCallbackEnabled(store.getBoolValueForKey(WebPreferencesKey::requestVideoFrameCallbackEnabledKey()));
#if HAVE(SC_CONTENT_SHARING_PICKER)
    settings.setRequireUAGetDisplayMediaPrompt(store.getBoolValueForKey(WebPreferencesKey::requireUAGetDisplayMediaPromptKey()));
#endif
    settings.setLoginStatusAPIRequiresWebAuthnEnabled(store.getBoolValueForKey(WebPreferencesKey::loginStatusAPIRequiresWebAuthnEnabledKey()));
#if ENABLE(MEDIA_STREAM)
    settings.setSpeakerSelectionRequiresUserGesture(store.getBoolValueForKey(WebPreferencesKey::speakerSelectionRequiresUserGestureKey()));
#endif
    settings.setFullscreenRequirementForScreenOrientationLockingEnabled(store.getBoolValueForKey(WebPreferencesKey::fullscreenRequirementForScreenOrientationLockingEnabledKey()));
#if ENABLE(MEDIA_STREAM)
    settings.setGetUserMediaRequiresFocus(store.getBoolValueForKey(WebPreferencesKey::getUserMediaRequiresFocusKey()));
#endif
    settings.setResourceLoadSchedulingEnabled(store.getBoolValueForKey(WebPreferencesKey::resourceLoadSchedulingEnabledKey()));
#if ENABLE(RESOURCE_USAGE)
    settings.setResourceUsageOverlayVisible(store.getBoolValueForKey(WebPreferencesKey::resourceUsageOverlayVisibleKey()));
#endif
    settings.setRespondToThermalPressureAggressively(store.getBoolValueForKey(WebPreferencesKey::respondToThermalPressureAggressivelyKey()));
    settings.setSKAttributionEnabled(store.getBoolValueForKey(WebPreferencesKey::sKAttributionEnabledKey()));
    settings.setIsSameSiteStrictEnforcementEnabled(store.getBoolValueForKey(WebPreferencesKey::isSameSiteStrictEnforcementEnabledKey()));
    settings.setScopedCustomElementRegistryEnabled(store.getBoolValueForKey(WebPreferencesKey::scopedCustomElementRegistryEnabledKey()));
    settings.setScreenOrientationLockingAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::screenOrientationLockingAPIEnabledKey()));
    settings.setScreenOrientationAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::screenOrientationAPIEnabledKey()));
#if ENABLE(SCREEN_TIME)
    settings.setScreenTimeEnabled(store.getBoolValueForKey(WebPreferencesKey::screenTimeEnabledKey()));
#endif
    settings.setScreenWakeLockAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::screenWakeLockAPIEnabledKey()));
#if ENABLE(MEDIA_STREAM)
    settings.setScreenCaptureEnabled(store.getBoolValueForKey(WebPreferencesKey::screenCaptureEnabledKey()));
#endif
    settings.setScriptTrackingPrivacyLoggingEnabled(store.getBoolValueForKey(WebPreferencesKey::scriptTrackingPrivacyLoggingEnabledKey()));
    settings.setScrollingPerformanceTestingEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollingPerformanceTestingEnabledKey()));
    settings.setScrollToTextFragmentFeatureDetectionEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentFeatureDetectionEnabledKey()));
    settings.setScrollToTextFragmentGenerationEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentGenerationEnabledKey()));
    settings.setScrollToTextFragmentIndicatorEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentIndicatorEnabledKey()));
    settings.setScrollToTextFragmentMarkingEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentMarkingEnabledKey()));
    settings.setScrollToTextFragmentEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentEnabledKey()));
    settings.setScrollAnimatorEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollAnimatorEnabledKey()));
    settings.setScrollDrivenAnimationsEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollDrivenAnimationsEnabledKey()));
    settings.setSecureContextChecksEnabled(store.getBoolValueForKey(WebPreferencesKey::secureContextChecksEnabledKey()));
#if PLATFORM(IOS_FAMILY)
    settings.setSelectionHonorsOverflowScrolling(store.getBoolValueForKey(WebPreferencesKey::selectionHonorsOverflowScrollingKey()));
#endif
    settings.setServiceWorkerInstallEventEnabled(store.getBoolValueForKey(WebPreferencesKey::serviceWorkerInstallEventEnabledKey()));
    settings.setServiceWorkerNavigationPreloadEnabled(store.getBoolValueForKey(WebPreferencesKey::serviceWorkerNavigationPreloadEnabledKey()));
    settings.setServiceWorkersEnabled(store.getBoolValueForKey(WebPreferencesKey::serviceWorkersEnabledKey()));
    settings.setShapeDetection(store.getBoolValueForKey(WebPreferencesKey::shapeDetectionKey()));
    settings.setSiteIsolationSharedProcessEnabled(store.getBoolValueForKey(WebPreferencesKey::siteIsolationSharedProcessEnabledKey()));
    settings.setSharedWorkerEnabled(store.getBoolValueForKey(WebPreferencesKey::sharedWorkerEnabledKey()));
    settings.setShowMediaStatsContextMenuItemEnabled(store.getBoolValueForKey(WebPreferencesKey::showMediaStatsContextMenuItemEnabledKey()));
    settings.setShowFrameProcessBorders(store.getBoolValueForKey(WebPreferencesKey::showFrameProcessBordersEnabledKey()));
    settings.setSidewaysWritingModesEnabled(store.getBoolValueForKey(WebPreferencesKey::sidewaysWritingModesEnabledKey()));
    settings.setSiteIsolationEnabled(store.getBoolValueForKey(WebPreferencesKey::siteIsolationEnabledKey()));
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
    settings.setSpatialImageControlsEnabled(store.getBoolValueForKey(WebPreferencesKey::spatialImageControlsEnabledKey()));
#endif
    settings.setSpeechRecognitionEnabled(store.getBoolValueForKey(WebPreferencesKey::speechRecognitionEnabledKey()));
    settings.setSpeechSynthesisAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::speechSynthesisAPIEnabledKey()));
    settings.setStorageAPIEstimateEnabled(store.getBoolValueForKey(WebPreferencesKey::storageAPIEstimateEnabledKey()));
    settings.setStorageAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::storageAPIEnabledKey()));
    settings.setStorageBlockingPolicy(static_cast<WebCore::StorageBlockingPolicy>(store.getUInt32ValueForKey(WebPreferencesKey::storageBlockingPolicyKey())));
    settings.setSupportHDRCompositorTonemappingEnabled(store.getBoolValueForKey(WebPreferencesKey::supportHDRCompositorTonemappingEnabledKey()));
    settings.setSupportHDRDisplayEnabled(store.getBoolValueForKey(WebPreferencesKey::supportHDRDisplayEnabledKey()));
    settings.setShouldTakeNearSuspendedAssertions(store.getBoolValueForKey(WebPreferencesKey::shouldTakeNearSuspendedAssertionsKey()));
#if ENABLE(WRITING_TOOLS)
    settings.setTextAnimationsEnabled(store.getBoolValueForKey(WebPreferencesKey::textAnimationsEnabledKey()));
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    settings.setTextRecognitionInVideosEnabled(store.getBoolValueForKey(WebPreferencesKey::textRecognitionInVideosEnabledKey()));
#endif
#if ENABLE(MEDIA_SOURCE)
    settings.setTextTracksInMSEEnabled(store.getBoolValueForKey(WebPreferencesKey::textTracksInMSEEnabledKey()));
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
    settings.setThreadedAnimationResolutionEnabled(store.getBoolValueForKey(WebPreferencesKey::threadedAnimationResolutionEnabledKey()));
#endif
    settings.setShowTiledScrollingIndicator(store.getBoolValueForKey(WebPreferencesKey::tiledScrollingIndicatorVisibleKey()));
    settings.setInputTypeTimeEnabled(store.getBoolValueForKey(WebPreferencesKey::inputTypeTimeEnabledKey()));
    settings.setTopContentInsetBackgroundCanChangeAfterScrolling(store.getBoolValueForKey(WebPreferencesKey::topContentInsetBackgroundCanChangeAfterScrollingKey()));
#if ENABLE(WEBXR)
    settings.setTouchInputCompatibilityEnabled(store.getBoolValueForKey(WebPreferencesKey::touchInputCompatibilityEnabledKey()));
#endif
    settings.setTrackConfigurationEnabled(store.getBoolValueForKey(WebPreferencesKey::trackConfigurationEnabledKey()));
    settings.setTrustedTypesEnabled(store.getBoolValueForKey(WebPreferencesKey::trustedTypesEnabledKey()));
    settings.setURLPatternAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::uRLPatternAPIEnabledKey()));
    settings.setUndoManagerAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::undoManagerAPIEnabledKey()));
#if ENABLE(UNIFIED_PDF)
    settings.setUnifiedPDFEnabled(store.getBoolValueForKey(WebPreferencesKey::unifiedPDFEnabledKey()));
#endif
#if ENABLE(DAMAGE_TRACKING)
    settings.setUnifyDamagedRegions(store.getBoolValueForKey(WebPreferencesKey::unifyDamagedRegionsKey()));
#endif
    settings.setIPAddressAndLocalhostMixedContentUpgradeTestingEnabled(store.getBoolValueForKey(WebPreferencesKey::iPAddressAndLocalhostMixedContentUpgradeTestingEnabledKey()));
    settings.setUpgradeMixedContentEnabled(store.getBoolValueForKey(WebPreferencesKey::upgradeMixedContentEnabledKey()));
    settings.setUseIFCForSVGText(store.getBoolValueForKey(WebPreferencesKey::useIFCForSVGTextKey()));
#if ENABLE(MEDIA_STREAM)
    settings.setUseMicrophoneMuteStatusAPI(store.getBoolValueForKey(WebPreferencesKey::useMicrophoneMuteStatusAPIKey()));
#endif
    settings.setUseGiantTiles(store.getBoolValueForKey(WebPreferencesKey::useGiantTilesKey()));
#if ENABLE(DAMAGE_TRACKING)
    settings.setUseDamagingInformationForCompositing(store.getBoolValueForKey(WebPreferencesKey::useDamagingInformationForCompositingKey()));
#endif
    settings.setUserActivationAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::userActivationAPIEnabledKey()));
    settings.setUserGesturePromisePropagationEnabled(store.getBoolValueForKey(WebPreferencesKey::userGesturePromisePropagationEnabledKey()));
    settings.setServiceWorkersUserGestureEnabled(store.getBoolValueForKey(WebPreferencesKey::serviceWorkersUserGestureEnabledKey()));
    settings.setVerifyWindowOpenUserGestureFromUIProcess(store.getBoolValueForKey(WebPreferencesKey::verifyWindowOpenUserGestureFromUIProcessKey()));
    settings.setVerticalFormControlsEnabled(store.getBoolValueForKey(WebPreferencesKey::verticalFormControlsEnabledKey()));
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    settings.setVideoRendererProtectedFallbackDisabled(store.getBoolValueForKey(WebPreferencesKey::videoRendererProtectedFallbackDisabledKey()));
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    settings.setVideoRendererUseDecompressionSessionForProtected(store.getBoolValueForKey(WebPreferencesKey::videoRendererUseDecompressionSessionForProtectedKey()));
#endif
    settings.setViewTransitionClassesEnabled(store.getBoolValueForKey(WebPreferencesKey::viewTransitionClassesEnabledKey()));
    settings.setViewTransitionTypesEnabled(store.getBoolValueForKey(WebPreferencesKey::viewTransitionTypesEnabledKey()));
    settings.setViewTransitionsEnabled(store.getBoolValueForKey(WebPreferencesKey::viewTransitionsEnabledKey()));
#if ENABLE(IMAGE_ANALYSIS)
    settings.setVisualTranslationEnabled(store.getBoolValueForKey(WebPreferencesKey::visualTranslationEnabledKey()));
#endif
    settings.setVisualViewportAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::visualViewportAPIEnabledKey()));
#if PLATFORM(IOS_FAMILY)
    settings.setVisuallyContiguousBidiTextSelectionEnabled(store.getBoolValueForKey(WebPreferencesKey::visuallyContiguousBidiTextSelectionEnabledKey()));
#endif
    settings.setWebAPIStatisticsEnabled(store.getBoolValueForKey(WebPreferencesKey::webAPIStatisticsEnabledKey()));
    settings.setWebAPIsInShadowRealmEnabled(store.getBoolValueForKey(WebPreferencesKey::webAPIsInShadowRealmEnabledKey()));
    settings.setWebAnimationsOverallProgressPropertyEnabled(store.getBoolValueForKey(WebPreferencesKey::webAnimationsOverallProgressPropertyEnabledKey()));
    settings.setWebAnimationsCustomEffectsEnabled(store.getBoolValueForKey(WebPreferencesKey::webAnimationsCustomEffectsEnabledKey()));
    settings.setWebAnimationsCustomFrameRateEnabled(store.getBoolValueForKey(WebPreferencesKey::webAnimationsCustomFrameRateEnabledKey()));
#if ENABLE(WEB_ARCHIVE)
    settings.setWebArchiveDebugModeEnabled(store.getBoolValueForKey(WebPreferencesKey::webArchiveDebugModeEnabledKey()));
#endif
#if ENABLE(WEB_ARCHIVE)
    settings.setWebArchiveTestingModeEnabled(store.getBoolValueForKey(WebPreferencesKey::webArchiveTestingModeEnabledKey()));
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
    settings.setWebAuthenticationASEnabled(store.getBoolValueForKey(WebPreferencesKey::webAuthenticationASEnabledKey()));
#endif
#if ENABLE(WEB_AUTHN)
    settings.setWebAuthenticationEnabled(store.getBoolValueForKey(WebPreferencesKey::webAuthenticationEnabledKey()));
#endif
    settings.setWebCryptoSafeCurvesEnabled(store.getBoolValueForKey(WebPreferencesKey::webCryptoSafeCurvesEnabledKey()));
    settings.setWebCryptoX25519Enabled(store.getBoolValueForKey(WebPreferencesKey::webCryptoX25519EnabledKey()));
    settings.setWebLocksAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::webLocksAPIEnabledKey()));
    settings.setWebShareFileAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::webShareFileAPIEnabledKey()));
    settings.setWebShareEnabled(store.getBoolValueForKey(WebPreferencesKey::webShareEnabledKey()));
#if ENABLE(WEBASSEMBLY)
    settings.setWebAssemblyESMIntegrationEnabled(store.getBoolValueForKey(WebPreferencesKey::webAssemblyESMIntegrationEnabledKey()));
#endif
#if ENABLE(WEB_CODECS)
    settings.setWebCodecsAV1Enabled(store.getBoolValueForKey(WebPreferencesKey::webCodecsAV1EnabledKey()));
#endif
#if ENABLE(WEB_CODECS)
    settings.setWebCodecsAudioEnabled(store.getBoolValueForKey(WebPreferencesKey::webCodecsAudioEnabledKey()));
#endif
#if ENABLE(WEB_CODECS)
    settings.setWebCodecsHEVCEnabled(store.getBoolValueForKey(WebPreferencesKey::webCodecsHEVCEnabledKey()));
#endif
#if ENABLE(WEB_CODECS)
    settings.setWebCodecsVideoEnabled(store.getBoolValueForKey(WebPreferencesKey::webCodecsVideoEnabledKey()));
#endif
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    settings.setWebExtensionBookmarksEnabled(store.getBoolValueForKey(WebPreferencesKey::webExtensionBookmarksEnabledKey()));
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    settings.setWebExtensionSidebarEnabled(store.getBoolValueForKey(WebPreferencesKey::webExtensionSidebarEnabledKey()));
#endif
    settings.setWebGLDraftExtensionsEnabled(store.getBoolValueForKey(WebPreferencesKey::webGLDraftExtensionsEnabledKey()));
    settings.setWebGLTimerQueriesEnabled(store.getBoolValueForKey(WebPreferencesKey::webGLTimerQueriesEnabledKey()));
    settings.setWebGLEnabled(store.getBoolValueForKey(WebPreferencesKey::webGLEnabledKey()));
    settings.setWebGPUHDREnabled(store.getBoolValueForKey(WebPreferencesKey::webGPUHDREnabledKey()));
    settings.setWebXRWebGPUBindingsEnabled(store.getBoolValueForKey(WebPreferencesKey::webXRWebGPUBindingsEnabledKey()));
    settings.setWebGPUEnabled(store.getBoolValueForKey(WebPreferencesKey::webGPUEnabledKey()));
    settings.setWebInspectorEngineeringSettingsAllowed(store.getBoolValueForKey(WebPreferencesKey::webInspectorEngineeringSettingsAllowedKey()));
#if ENABLE(WEB_RTC)
    settings.setWebRTCAV1CodecEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCAV1CodecEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCDTMFEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCDTMFEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCEncodedTransformEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCEncodedTransformEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCH265CodecEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCH265CodecEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCL4SEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCL4SEnabledKey()));
#endif
    settings.setWebRTCMediaPipelineAdditionalLoggingEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCMediaPipelineAdditionalLoggingEnabledKey()));
#if ENABLE(WEB_RTC)
    settings.setLegacyWebRTCOfferOptionsEnabled(store.getBoolValueForKey(WebPreferencesKey::legacyWebRTCOfferOptionsEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setPeerConnectionVideoScalingAdaptationDisabled(store.getBoolValueForKey(WebPreferencesKey::peerConnectionVideoScalingAdaptationDisabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setPeerConnectionEnabled(store.getBoolValueForKey(WebPreferencesKey::peerConnectionEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCRemoteVideoFrameEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCRemoteVideoFrameEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCSFrameTransformEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCSFrameTransformEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCSocketsProxyingEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCSocketsProxyingEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCUDPPortRange(store.getStringValueForKey(WebPreferencesKey::webRTCUDPPortRangeKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCVP9Profile0CodecEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCVP9Profile0CodecEnabledKey()));
#endif
#if ENABLE(WEB_RTC)
    settings.setWebRTCVP9Profile2CodecEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCVP9Profile2CodecEnabledKey()));
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
    settings.setWebRTCInterfaceMonitoringViaNWEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCInterfaceMonitoringViaNWEnabledKey()));
#endif
    settings.setWebTransportEnabled(store.getBoolValueForKey(WebPreferencesKey::webTransportEnabledKey()));
#if ENABLE(WEBXR)
    settings.setWebXRAugmentedRealityModuleEnabled(store.getBoolValueForKey(WebPreferencesKey::webXRAugmentedRealityModuleEnabledKey()));
#endif
#if ENABLE(WEBXR)
    settings.setWebXREnabled(store.getBoolValueForKey(WebPreferencesKey::webXREnabledKey()));
#endif
#if ENABLE(WEBXR)
    settings.setWebXRGamepadsModuleEnabled(store.getBoolValueForKey(WebPreferencesKey::webXRGamepadsModuleEnabledKey()));
#endif
#if ENABLE(WEBXR_HANDS)
    settings.setWebXRHandInputModuleEnabled(store.getBoolValueForKey(WebPreferencesKey::webXRHandInputModuleEnabledKey()));
#endif
#if ENABLE(WEBXR_LAYERS)
    settings.setWebXRLayersAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::webXRLayersAPIEnabledKey()));
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    settings.setWebPageSpatialBackdropEnabled(store.getBoolValueForKey(WebPreferencesKey::webPageSpatialBackdropEnabledKey()));
#endif
    settings.setInputTypeWeekEnabled(store.getBoolValueForKey(WebPreferencesKey::inputTypeWeekEnabledKey()));
    settings.setWheelEventGesturesBecomeNonBlocking(store.getBoolValueForKey(WebPreferencesKey::wheelEventGesturesBecomeNonBlockingKey()));
    settings.setPassiveWheelListenersAsDefaultOnDocument(store.getBoolValueForKey(WebPreferencesKey::passiveWheelListenersAsDefaultOnDocumentKey()));
    settings.setWorkerAsynchronousURLErrorHandlingEnabled(store.getBoolValueForKey(WebPreferencesKey::workerAsynchronousURLErrorHandlingEnabledKey()));
#if PLATFORM(COCOA)
    settings.setWriteRichTextDataWhenCopyingOrDragging(store.getBoolValueForKey(WebPreferencesKey::writeRichTextDataWhenCopyingOrDraggingKey()));
#endif
#if ENABLE(WRITING_SUGGESTIONS)
    settings.setWritingSuggestionsAttributeEnabled(store.getBoolValueForKey(WebPreferencesKey::writingSuggestionsAttributeEnabledKey()));
#endif
#if ENABLE(XSLT)
    settings.setXsltEnabled(store.getBoolValueForKey(WebPreferencesKey::xSLTEnabledKey()));
#endif
    settings.setIsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled(store.getBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalLiveOnTestingEnabledKey()));
    settings.setIsFirstPartyWebsiteDataRemovalReproTestingEnabled(store.getBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalReproTestingEnabledKey()));
    settings.setAltitudeAngleEnabled(store.getBoolValueForKey(WebPreferencesKey::altitudeAngleEnabledKey()));
    settings.setAzimuthAngleEnabled(store.getBoolValueForKey(WebPreferencesKey::azimuthAngleEnabledKey()));
    settings.setInputTypeDateTimeLocalEnabled(store.getBoolValueForKey(WebPreferencesKey::inputTypeDateTimeLocalEnabledKey()));
    settings.setCaretPositionFromPointEnabled(store.getBoolValueForKey(WebPreferencesKey::caretPositionFromPointEnabledKey()));
    settings.setHiddenUntilFoundEnabled(store.getBoolValueForKey(WebPreferencesKey::hiddenUntilFoundEnabledKey()));
    settings.setHttpEquivEnabled(store.getBoolValueForKey(WebPreferencesKey::httpEquivEnabledKey()));
    settings.setShadowRootReferenceTargetEnabledForAriaOwns(store.getBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledForAriaOwnsKey()));
    settings.setShadowRootReferenceTargetEnabled(store.getBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledKey()));
    settings.setRequestIdleCallbackEnabled(store.getBoolValueForKey(WebPreferencesKey::requestIdleCallbackEnabledKey()));
    settings.setRequestStorageAccessThrowsExceptionUntilReload(store.getBoolValueForKey(WebPreferencesKey::requestStorageAccessThrowsExceptionUntilReloadKey()));
    settings.setScrollendEventEnabled(store.getBoolValueForKey(WebPreferencesKey::scrollendEventEnabledKey()));
    settings.setCSSWordBreakAutoPhraseEnabled(store.getBoolValueForKey(WebPreferencesKey::cssWordBreakAutoPhraseEnabledKey()));
}

void WebPage::updatePreferencesGenerated(const WebPreferencesStore& store)
{
    WebCore::DeprecatedGlobalSettings::setLowPowerVideoAudioBufferSizeEnabled(store.getBoolValueForKey(WebPreferencesKey::lowPowerVideoAudioBufferSizeEnabledKey()));
    WebCore::DeprecatedGlobalSettings::setMockScrollbarsEnabled(store.getBoolValueForKey(WebPreferencesKey::mockScrollbarsEnabledKey()));
#if USE(GSTREAMER)
    WebCore::DeprecatedGlobalSettings::setGStreamerEnabled(store.getBoolValueForKey(WebPreferencesKey::isGStreamerEnabledKey()));
#endif
#if USE(AVFOUNDATION)
    WebCore::DeprecatedGlobalSettings::setAVFoundationEnabled(store.getBoolValueForKey(WebPreferencesKey::isAVFoundationEnabledKey()));
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    WebCore::DeprecatedGlobalSettings::setAttachmentElementEnabled(store.getBoolValueForKey(WebPreferencesKey::attachmentElementEnabledKey()));
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    WebCore::DeprecatedGlobalSettings::setBuiltInNotificationsEnabled(store.getBoolValueForKey(WebPreferencesKey::builtInNotificationsEnabledKey()));
#endif
    WebCore::DeprecatedGlobalSettings::setCustomPasteboardDataEnabled(store.getBoolValueForKey(WebPreferencesKey::customPasteboardDataEnabledKey()));
#if PLATFORM(IOS_FAMILY)
    WebCore::DeprecatedGlobalSettings::setDisableScreenSizeOverride(store.getBoolValueForKey(WebPreferencesKey::disableScreenSizeOverrideKey()));
#endif
#if ENABLE(MODEL_ELEMENT)
    WebCore::DeprecatedGlobalSettings::setModelDocumentEnabled(store.getBoolValueForKey(WebPreferencesKey::modelDocumentEnabledKey()));
#endif
#if ENABLE(ACCESSIBILITY_ISOLATED_TREE)
    WebCore::DeprecatedGlobalSettings::setIsAccessibilityIsolatedTreeEnabled(store.getBoolValueForKey(WebPreferencesKey::isAccessibilityIsolatedTreeEnabledKey()));
#endif
#if ENABLE(AX_THREAD_TEXT_APIS)
    WebCore::DeprecatedGlobalSettings::setAccessibilityThreadTextApisEnabled(store.getBoolValueForKey(WebPreferencesKey::accessibilityThreadTextApisEnabledKey()));
#endif
    WebCore::DeprecatedGlobalSettings::setReadableByteStreamAPIEnabled(store.getBoolValueForKey(WebPreferencesKey::readableByteStreamAPIEnabledKey()));
#if HAVE(WEBCONTENTRESTRICTIONS)
    WebCore::DeprecatedGlobalSettings::setUsesWebContentRestrictionsForFilter(store.getBoolValueForKey(WebPreferencesKey::usesWebContentRestrictionsForFilterKey()));
#endif
    WebCore::DeprecatedGlobalSettings::setWebRTCAudioLatencyAdaptationEnabled(store.getBoolValueForKey(WebPreferencesKey::webRTCAudioLatencyAdaptationEnabledKey()));

    if (store.getBoolValueForKey(WebPreferencesKey::mediaPlaybackEnabledKey()))
        WebProcess::singleton().enableMediaPlayback();
}

}
