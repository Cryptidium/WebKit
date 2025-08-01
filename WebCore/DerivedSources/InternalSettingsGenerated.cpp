/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2017-2020 Apple Inc. All rights reserved.
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
#include "InternalSettingsGenerated.h"

#include "Page.h"
#include "Settings.h"

namespace WebCore {

InternalSettingsGenerated::InternalSettingsGenerated(Page* page)
    : m_page(page)
#if HAVE(AVKIT_CONTENT_SOURCE)
    , m_aVKitContentSourceEnabled(page->settings().aVKitContentSourceEnabled())
#endif
    , m_acceleratedCompositingEnabled(page->settings().acceleratedCompositingEnabled())
    , m_acceleratedCompositingForFixedPositionEnabled(page->settings().acceleratedCompositingForFixedPositionEnabled())
    , m_acceleratedDrawingEnabled(page->settings().acceleratedDrawingEnabled())
#if USE(CORE_IMAGE)
    , m_acceleratedFiltersEnabled(page->settings().acceleratedFiltersEnabled())
#endif
    , m_accentColorEnabled(page->settings().accentColorEnabled())
    , m_accessHandleEnabled(page->settings().accessHandleEnabled())
    , m_aggressiveTileRetentionEnabled(page->settings().aggressiveTileRetentionEnabled())
    , m_allowAnimationControlsOverride(page->settings().allowAnimationControlsOverride())
    , m_allowContentSecurityPolicySourceStarToMatchAnyProtocol(page->settings().allowContentSecurityPolicySourceStarToMatchAnyProtocol())
    , m_allowDisplayOfInsecureContent(page->settings().allowDisplayOfInsecureContent())
    , m_allowFileAccessFromFileURLs(page->settings().allowFileAccessFromFileURLs())
    , m_allowMediaContentTypesRequiringHardwareSupportAsFallback(page->settings().allowMediaContentTypesRequiringHardwareSupportAsFallback())
    , m_allowMultiElementImplicitSubmission(page->settings().allowMultiElementImplicitSubmission())
    , m_allowPrivacySensitiveOperationsInNonPersistentDataStores(page->settings().allowPrivacySensitiveOperationsInNonPersistentDataStores())
    , m_allowRunningOfInsecureContent(page->settings().allowRunningOfInsecureContent())
    , m_allowTopNavigationToDataURLs(page->settings().allowTopNavigationToDataURLs())
    , m_allowUniversalAccessFromFileURLs(page->settings().allowUniversalAccessFromFileURLs())
#if PLATFORM(IOS_FAMILY)
    , m_allowViewportShrinkToFitContent(page->settings().allowViewportShrinkToFitContent())
#endif
#if ENABLE(WEBGL)
    , m_allowWebGLInWorkers(page->settings().allowWebGLInWorkers())
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    , m_allowsAirPlayForMediaPlayback(page->settings().allowsAirPlayForMediaPlayback())
#endif
    , m_allowsInlineMediaPlayback(page->settings().allowsInlineMediaPlayback())
    , m_allowsInlineMediaPlaybackAfterFullscreen(page->settings().allowsInlineMediaPlaybackAfterFullscreen())
    , m_allowsPictureInPictureMediaPlayback(page->settings().allowsPictureInPictureMediaPlayback())
#if PLATFORM(IOS_FAMILY)
    , m_alternateFullScreenControlDesignEnabled(page->settings().alternateFullScreenControlDesignEnabled())
#endif
    , m_altitudeAngleEnabled(page->settings().altitudeAngleEnabled())
#if ENABLE(WEB_ARCHIVE)
    , m_alwaysAllowLocalWebarchive(page->settings().alwaysAllowLocalWebarchive())
#endif
    , m_animatedImageAsyncDecodingEnabled(page->settings().animatedImageAsyncDecodingEnabled())
    , m_animatedImageDebugCanvasDrawingEnabled(page->settings().animatedImageDebugCanvasDrawingEnabled())
    , m_appBadgeEnabled(page->settings().appBadgeEnabled())
#if ENABLE(APP_HIGHLIGHTS)
    , m_appHighlightsEnabled(page->settings().appHighlightsEnabled())
#endif
    , m_appleMailPaginationQuirkEnabled(page->settings().appleMailPaginationQuirkEnabled())
#if ENABLE(APPLE_PAY)
    , m_applePayCapabilityDisclosureAllowed(page->settings().applePayCapabilityDisclosureAllowed())
#endif
#if ENABLE(APPLE_PAY)
    , m_applePayEnabled(page->settings().applePayEnabled())
#endif
    , m_asyncClipboardAPIEnabled(page->settings().asyncClipboardAPIEnabled())
    , m_asyncFrameScrollingEnabled(page->settings().asyncFrameScrollingEnabled())
    , m_asyncOverflowScrollingEnabled(page->settings().asyncOverflowScrollingEnabled())
    , m_asynchronousSpellCheckingEnabled(page->settings().asynchronousSpellCheckingEnabled())
#if ENABLE(ATTACHMENT_ELEMENT)
    , m_attachmentWideLayoutEnabled(page->settings().attachmentWideLayoutEnabled())
#endif
    , m_audioControlsScaleWithPageZoom(page->settings().audioControlsScaleWithPageZoom())
#if ENABLE(VIDEO)
    , m_audioDescriptionsEnabled(page->settings().audioDescriptionsEnabled())
#endif
    , m_authorAndUserStylesEnabled(page->settings().authorAndUserStylesEnabled())
    , m_automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth(page->settings().automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth())
    , m_autoscrollForDragAndDropEnabled(page->settings().autoscrollForDragAndDropEnabled())
    , m_auxclickEventEnabled(page->settings().auxclickEventEnabled())
    , m_azimuthAngleEnabled(page->settings().azimuthAngleEnabled())
    , m_backgroundFetchAPIEnabled(page->settings().backgroundFetchAPIEnabled())
    , m_backgroundShouldExtendBeyondPage(page->settings().backgroundShouldExtendBeyondPage())
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
    , m_backgroundWebContentRunningBoardThrottlingEnabled(page->settings().backgroundWebContentRunningBoardThrottlingEnabled())
#endif
    , m_backspaceKeyNavigationEnabled(page->settings().backspaceKeyNavigationEnabled())
    , m_beaconAPIEnabled(page->settings().beaconAPIEnabled())
    , m_bidiContentAwarePasteEnabled(page->settings().bidiContentAwarePasteEnabled())
    , m_blobFileAccessEnforcementEnabled(page->settings().blobFileAccessEnforcementEnabled())
#if ENABLE(GPU_PROCESS)
    , m_blockMediaLayerRehostingInWebContentProcess(page->settings().blockMediaLayerRehostingInWebContentProcess())
#endif
    , m_broadcastChannelEnabled(page->settings().broadcastChannelEnabled())
    , m_cacheAPIEnabled(page->settings().cacheAPIEnabled())
    , m_canvasColorSpaceEnabled(page->settings().canvasColorSpaceEnabled())
    , m_canvasFiltersEnabled(page->settings().canvasFiltersEnabled())
    , m_canvasFingerprintingQuirkEnabled(page->settings().canvasFingerprintingQuirkEnabled())
    , m_canvasLayersEnabled(page->settings().canvasLayersEnabled())
    , m_canvasPixelFormatEnabled(page->settings().canvasPixelFormatEnabled())
#if USE(CA) || USE(SKIA)
    , m_canvasUsesAcceleratedDrawing(page->settings().canvasUsesAcceleratedDrawing())
#endif
    , m_caretBrowsingEnabled(page->settings().caretBrowsingEnabled())
    , m_caretPositionFromPointEnabled(page->settings().caretPositionFromPointEnabled())
    , m_childProcessDebuggabilityEnabled(page->settings().childProcessDebuggabilityEnabled())
    , m_clearSiteDataExecutionContextsSupportEnabled(page->settings().clearSiteDataExecutionContextsSupportEnabled())
    , m_clearSiteDataHTTPHeaderEnabled(page->settings().clearSiteDataHTTPHeaderEnabled())
    , m_clientCoordinatesRelativeToLayoutViewport(page->settings().clientCoordinatesRelativeToLayoutViewport())
    , m_closeWatcherEnabled(page->settings().closeWatcherEnabled())
    , m_colorFilterEnabled(page->settings().colorFilterEnabled())
    , m_commandAttributesEnabled(page->settings().commandAttributesEnabled())
    , m_compressionStreamEnabled(page->settings().compressionStreamEnabled())
    , m_contactPickerAPIEnabled(page->settings().contactPickerAPIEnabled())
#if ENABLE(CONTENT_CHANGE_OBSERVER)
    , m_contentChangeObserverEnabled(page->settings().contentChangeObserverEnabled())
#endif
    , m_contentDispositionAttachmentSandboxEnabled(page->settings().contentDispositionAttachmentSandboxEnabled())
    , m_contentInsetBackgroundFillEnabled(page->settings().contentInsetBackgroundFillEnabled())
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
    , m_contextMenuQRCodeDetectionEnabled(page->settings().contextMenuQRCodeDetectionEnabled())
#endif
    , m_cookieConsentAPIEnabled(page->settings().cookieConsentAPIEnabled())
    , m_cookieEnabled(page->settings().cookieEnabled())
    , m_cookieStoreAPIEnabled(page->settings().cookieStoreAPIEnabled())
    , m_cookieStoreAPIExtendedAttributesEnabled(page->settings().cookieStoreAPIExtendedAttributesEnabled())
    , m_cookieStoreManagerEnabled(page->settings().cookieStoreManagerEnabled())
    , m_coreMathMLEnabled(page->settings().coreMathMLEnabled())
    , m_crossDocumentViewTransitionsEnabled(page->settings().crossDocumentViewTransitionsEnabled())
    , m_crossOriginCheckInGetMatchedCSSRulesDisabled(page->settings().crossOriginCheckInGetMatchedCSSRulesDisabled())
    , m_crossOriginEmbedderPolicyEnabled(page->settings().crossOriginEmbedderPolicyEnabled())
    , m_crossOriginOpenerPolicyEnabled(page->settings().crossOriginOpenerPolicyEnabled())
    , m_css3DTransformBackfaceVisibilityInteroperabilityEnabled(page->settings().css3DTransformBackfaceVisibilityInteroperabilityEnabled())
    , m_cssAnchorPositioningEnabled(page->settings().cssAnchorPositioningEnabled())
    , m_cssAnchorPositioningPositionVisibilityEnabled(page->settings().cssAnchorPositioningPositionVisibilityEnabled())
    , m_cssAppearanceBaseEnabled(page->settings().cssAppearanceBaseEnabled())
    , m_cssAxisRelativePositionKeywordsEnabled(page->settings().cssAxisRelativePositionKeywordsEnabled())
    , m_cssBackgroundClipBorderAreaEnabled(page->settings().cssBackgroundClipBorderAreaEnabled())
    , m_cssColorLayersEnabled(page->settings().cssColorLayersEnabled())
    , m_cssConstrainedDynamicRangeLimitEnabled(page->settings().cssConstrainedDynamicRangeLimitEnabled())
    , m_cssContrastColorEnabled(page->settings().cssContrastColorEnabled())
    , m_cssCornerShapeEnabled(page->settings().cssCornerShapeEnabled())
    , m_cssCounterStyleAtRuleImageSymbolsEnabled(page->settings().cssCounterStyleAtRuleImageSymbolsEnabled())
    , m_cssDPropertyEnabled(page->settings().cssDPropertyEnabled())
    , m_cssDynamicRangeLimitMixEnabled(page->settings().cssDynamicRangeLimitMixEnabled())
    , m_cssFieldSizingEnabled(page->settings().cssFieldSizingEnabled())
    , m_cssFontVariantEmojiEnabled(page->settings().cssFontVariantEmojiEnabled())
    , m_cssInputSecurityEnabled(page->settings().cssInputSecurityEnabled())
    , m_cssLineClampEnabled(page->settings().cssLineClampEnabled())
    , m_cssLineFitEdgeEnabled(page->settings().cssLineFitEdgeEnabled())
    , m_cssPaintingAPIEnabled(page->settings().cssPaintingAPIEnabled())
    , m_cssProgressFunctionEnabled(page->settings().cssProgressFunctionEnabled())
    , m_cssRandomFunctionEnabled(page->settings().cssRandomFunctionEnabled())
    , m_cssRhythmicSizingEnabled(page->settings().cssRhythmicSizingEnabled())
    , m_cssRubyAlignEnabled(page->settings().cssRubyAlignEnabled())
    , m_cssRubyOverhangEnabled(page->settings().cssRubyOverhangEnabled())
    , m_cssScrollAnchoringEnabled(page->settings().cssScrollAnchoringEnabled())
    , m_cssScrollbarColorEnabled(page->settings().cssScrollbarColorEnabled())
    , m_cssScrollbarGutterEnabled(page->settings().cssScrollbarGutterEnabled())
    , m_cssScrollbarWidthEnabled(page->settings().cssScrollbarWidthEnabled())
    , m_cssShapeFunctionEnabled(page->settings().cssShapeFunctionEnabled())
    , m_cssTextAutospaceEnabled(page->settings().cssTextAutospaceEnabled())
    , m_cssTextBoxTrimEnabled(page->settings().cssTextBoxTrimEnabled())
    , m_cssTextGroupAlignEnabled(page->settings().cssTextGroupAlignEnabled())
    , m_cssTextJustifyEnabled(page->settings().cssTextJustifyEnabled())
    , m_cssTextSpacingTrimEnabled(page->settings().cssTextSpacingTrimEnabled())
    , m_cssTextUnderlinePositionLeftRightEnabled(page->settings().cssTextUnderlinePositionLeftRightEnabled())
    , m_cssTextWrapPrettyEnabled(page->settings().cssTextWrapPrettyEnabled())
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
    , m_cssTransformStyleSeparatedEnabled(page->settings().cssTransformStyleSeparatedEnabled())
#endif
    , m_cssTreeCountingFunctionsEnabled(page->settings().cssTreeCountingFunctionsEnabled())
    , m_cssTypedOMColorEnabled(page->settings().cssTypedOMColorEnabled())
    , m_cssURLIntegrityModifierEnabled(page->settings().cssURLIntegrityModifierEnabled())
    , m_cssURLModifiersEnabled(page->settings().cssURLModifiersEnabled())
    , m_cssUnprefixedBackdropFilterEnabled(page->settings().cssUnprefixedBackdropFilterEnabled())
    , m_cssWordBreakAutoPhraseEnabled(page->settings().cssWordBreakAutoPhraseEnabled())
    , m_cursiveFontFamily(page->settings().cursiveFontFamily())
    , m_dataListElementEnabled(page->settings().dataListElementEnabled())
    , m_dataTransferItemsEnabled(page->settings().dataTransferItemsEnabled())
    , m_dateTimeInputsEditableComponentsEnabled(page->settings().dateTimeInputsEditableComponentsEnabled())
#if ENABLE(DECLARATIVE_WEB_PUSH)
    , m_declarativeWebPush(page->settings().declarativeWebPush())
#endif
    , m_defaultFixedFontSize(page->settings().defaultFixedFontSize())
    , m_defaultFontSize(page->settings().defaultFontSize())
    , m_defaultTextEncodingName(page->settings().defaultTextEncodingName())
    , m_defaultVideoPosterURL(page->settings().defaultVideoPosterURL())
    , m_deprecationReportingEnabled(page->settings().deprecationReportingEnabled())
#if ENABLE(MEDIA_SOURCE)
    , m_detachableMediaSourceEnabled(page->settings().detachableMediaSourceEnabled())
#endif
    , m_detailsAutoExpandEnabled(page->settings().detailsAutoExpandEnabled())
    , m_developerExtrasEnabled(page->settings().developerExtrasEnabled())
    , m_deviceHeight(page->settings().deviceHeight())
#if ENABLE(DEVICE_ORIENTATION)
    , m_deviceOrientationEventEnabled(page->settings().deviceOrientationEventEnabled())
#endif
#if ENABLE(DEVICE_ORIENTATION)
    , m_deviceOrientationPermissionAPIEnabled(page->settings().deviceOrientationPermissionAPIEnabled())
#endif
    , m_deviceWidth(page->settings().deviceWidth())
    , m_devolvableWidgetsEnabled(page->settings().devolvableWidgetsEnabled())
    , m_diagnosticLoggingEnabled(page->settings().diagnosticLoggingEnabled())
#if ENABLE(WEB_AUTHN)
    , m_digitalCredentialsEnabled(page->settings().digitalCredentialsEnabled())
#endif
    , m_directoryUploadEnabled(page->settings().directoryUploadEnabled())
    , m_disabledAdaptationsMetaTagEnabled(page->settings().disabledAdaptationsMetaTagEnabled())
#if ENABLE(DOM_AUDIO_SESSION)
    , m_domAudioSessionEnabled(page->settings().domAudioSessionEnabled())
#endif
#if ENABLE(DOM_AUDIO_SESSION)
    , m_domAudioSessionFullEnabled(page->settings().domAudioSessionFullEnabled())
#endif
    , m_domPasteAccessRequestsEnabled(page->settings().domPasteAccessRequestsEnabled())
    , m_domPasteAllowed(page->settings().domPasteAllowed())
    , m_domTestingAPIsEnabled(page->settings().domTestingAPIsEnabled())
    , m_domTimersThrottlingEnabled(page->settings().domTimersThrottlingEnabled())
    , m_downloadAttributeEnabled(page->settings().downloadAttributeEnabled())
    , m_dynamicSiteInterventionsEnabled(page->settings().dynamicSiteInterventionsEnabled())
    , m_embedElementEnabled(page->settings().embedElementEnabled())
    , m_enableElementCurrentCSSZoom(page->settings().enableElementCurrentCSSZoom())
    , m_enableInheritURIQueryComponent(page->settings().enableInheritURIQueryComponent())
#if ENABLE(ENCRYPTED_MEDIA)
    , m_encryptedMediaAPIEnabled(page->settings().encryptedMediaAPIEnabled())
#endif
    , m_enterKeyHintEnabled(page->settings().enterKeyHintEnabled())
    , m_eventHandlerDrivenSmoothKeyboardScrollingEnabled(page->settings().eventHandlerDrivenSmoothKeyboardScrollingEnabled())
    , m_eventTimingEnabled(page->settings().eventTimingEnabled())
#if ENABLE(MEDIA_STREAM)
    , m_exposeCaptureDevicesAfterCaptureEnabled(page->settings().exposeCaptureDevicesAfterCaptureEnabled())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_exposeDefaultSpeakerAsSpecificDeviceEnabled(page->settings().exposeDefaultSpeakerAsSpecificDeviceEnabled())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_exposeSpeakersEnabled(page->settings().exposeSpeakersEnabled())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_exposeSpeakersWithoutMicrophoneEnabled(page->settings().exposeSpeakersWithoutMicrophoneEnabled())
#endif
#if ENABLE(VIDEO)
    , m_extendedAudioDescriptionsEnabled(page->settings().extendedAudioDescriptionsEnabled())
#endif
    , m_fantasyFontFamily(page->settings().fantasyFontFamily())
    , m_fileReaderAPIEnabled(page->settings().fileReaderAPIEnabled())
    , m_fileSystemEnabled(page->settings().fileSystemEnabled())
    , m_fileSystemWritableStreamEnabled(page->settings().fileSystemWritableStreamEnabled())
    , m_filterLinkDecorationByDefaultEnabled(page->settings().filterLinkDecorationByDefaultEnabled())
    , m_fixedBackgroundsPaintRelativeToDocument(page->settings().fixedBackgroundsPaintRelativeToDocument())
    , m_fixedElementsLayoutRelativeToFrame(page->settings().fixedElementsLayoutRelativeToFrame())
    , m_fixedFontFamily(page->settings().fixedFontFamily())
    , m_flexFormattingContextIntegrationEnabled(page->settings().flexFormattingContextIntegrationEnabled())
    , m_fontFallbackPrefersPictographs(page->settings().fontFallbackPrefersPictographs())
    , m_forceCompositingMode(page->settings().forceCompositingMode())
    , m_forceFTPDirectoryListings(page->settings().forceFTPDirectoryListings())
    , m_forceLockdownFontParserEnabled(page->settings().forceLockdownFontParserEnabled())
    , m_forceWebGLUsesLowPower(page->settings().forceWebGLUsesLowPower())
#if ENABLE(FORM_CONTROL_REFRESH)
    , m_formControlRefreshEnabled(page->settings().formControlRefreshEnabled())
#endif
    , m_ftpDirectoryTemplatePath(page->settings().ftpDirectoryTemplatePath())
    , m_ftpEnabled(page->settings().ftpEnabled())
#if ENABLE(FULLSCREEN_API)
    , m_fullScreenEnabled(page->settings().fullScreenEnabled())
#endif
#if ENABLE(FULLSCREEN_API)
    , m_fullScreenKeyboardLock(page->settings().fullScreenKeyboardLock())
#endif
    , m_fullscreenRequirementForScreenOrientationLockingEnabled(page->settings().fullscreenRequirementForScreenOrientationLockingEnabled())
#if PLATFORM(VISION)
    , m_fullscreenSceneAspectRatioLockingEnabled(page->settings().fullscreenSceneAspectRatioLockingEnabled())
#endif
#if PLATFORM(VISION)
    , m_fullscreenSceneDimmingEnabled(page->settings().fullscreenSceneDimmingEnabled())
#endif
#if ENABLE(GAMEPAD)
    , m_gamepadTriggerRumbleEnabled(page->settings().gamepadTriggerRumbleEnabled())
#endif
#if ENABLE(GAMEPAD)
    , m_gamepadVibrationActuatorEnabled(page->settings().gamepadVibrationActuatorEnabled())
#endif
#if ENABLE(GAMEPAD)
    , m_gamepadsEnabled(page->settings().gamepadsEnabled())
#endif
#if ENABLE(VIDEO)
    , m_genericCueAPIEnabled(page->settings().genericCueAPIEnabled())
#endif
    , m_geolocationAPIEnabled(page->settings().geolocationAPIEnabled())
    , m_geolocationFloorLevelEnabled(page->settings().geolocationFloorLevelEnabled())
    , m_getCoalescedEventsEnabled(page->settings().getCoalescedEventsEnabled())
    , m_getPredictedEventsEnabled(page->settings().getPredictedEventsEnabled())
#if ENABLE(MEDIA_STREAM)
    , m_getUserMediaRequiresFocus(page->settings().getUserMediaRequiresFocus())
#endif
    , m_googleAntiFlickerOptimizationQuirkEnabled(page->settings().googleAntiFlickerOptimizationQuirkEnabled())
#if USE(GRAPHICS_CONTEXT_FILTERS)
    , m_graphicsContextFiltersEnabled(page->settings().graphicsContextFiltersEnabled())
#endif
    , m_hiddenPageCSSAnimationSuspensionEnabled(page->settings().hiddenPageCSSAnimationSuspensionEnabled())
    , m_hiddenPageDOMTimerThrottlingAutoIncreases(page->settings().hiddenPageDOMTimerThrottlingAutoIncreases())
    , m_hiddenPageDOMTimerThrottlingEnabled(page->settings().hiddenPageDOMTimerThrottlingEnabled())
    , m_hiddenUntilFoundEnabled(page->settings().hiddenUntilFoundEnabled())
#if HAVE(MATERIAL_HOSTING)
    , m_hostedBlurMaterialInMediaControlsEnabled(page->settings().hostedBlurMaterialInMediaControlsEnabled())
#endif
    , m_htmlLegacyAttributeValueSerializationEnabled(page->settings().htmlLegacyAttributeValueSerializationEnabled())
    , m_httpEquivEnabled(page->settings().httpEquivEnabled())
    , m_httpsByDefault(page->settings().httpsByDefault())
#if ENABLE(CONTENT_EXTENSIONS)
    , m_iFrameResourceMonitoringEnabled(page->settings().iFrameResourceMonitoringEnabled())
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    , m_iFrameResourceMonitoringTestingSettingsEnabled(page->settings().iFrameResourceMonitoringTestingSettingsEnabled())
#endif
    , m_iOSurfaceLosslessCompressionEnabled(page->settings().iOSurfaceLosslessCompressionEnabled())
    , m_iPAddressAndLocalhostMixedContentUpgradeTestingEnabled(page->settings().iPAddressAndLocalhostMixedContentUpgradeTestingEnabled())
    , m_iceCandidateFilteringEnabled(page->settings().iceCandidateFilteringEnabled())
#if ENABLE(TEXT_AUTOSIZING)
    , m_idempotentModeAutosizingOnlyHonorsPercentages(page->settings().idempotentModeAutosizingOnlyHonorsPercentages())
#endif
    , m_ignoreIframeEmbeddingProtectionsEnabled(page->settings().ignoreIframeEmbeddingProtectionsEnabled())
#if ENABLE(IMAGE_ANALYSIS)
    , m_imageAnalysisDuringFindInPageEnabled(page->settings().imageAnalysisDuringFindInPageEnabled())
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    , m_imageAnimationControlEnabled(page->settings().imageAnimationControlEnabled())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_imageCaptureEnabled(page->settings().imageCaptureEnabled())
#endif
#if ENABLE(SERVICE_CONTROLS)
    , m_imageControlsEnabled(page->settings().imageControlsEnabled())
#endif
    , m_imageSubsamplingEnabled(page->settings().imageSubsamplingEnabled())
    , m_imagesEnabled(page->settings().areImagesEnabled())
    , m_inWindowFullscreenEnabled(page->settings().inWindowFullscreenEnabled())
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
    , m_includeIgnoredInCoreAXTree(page->settings().includeIgnoredInCoreAXTree())
#endif
    , m_incompleteImageBorderEnabled(page->settings().incompleteImageBorderEnabled())
#if HAVE(INCREMENTAL_PDF_APIS)
    , m_incrementalPDFLoadingEnabled(page->settings().incrementalPDFLoadingEnabled())
#endif
    , m_incrementalRenderingSuppressionTimeoutInSeconds(page->settings().incrementalRenderingSuppressionTimeoutInSeconds())
    , m_indexedDBAPIEnabled(page->settings().indexedDBAPIEnabled())
    , m_inlineMediaPlaybackRequiresPlaysInlineAttribute(page->settings().inlineMediaPlaybackRequiresPlaysInlineAttribute())
#if PLATFORM(MAC)
    , m_inputMethodUsesCorrectKeyEventOrder(page->settings().inputMethodUsesCorrectKeyEventOrder())
#endif
    , m_inputTypeColorEnabled(page->settings().inputTypeColorEnabled())
    , m_inputTypeColorEnhancementsEnabled(page->settings().inputTypeColorEnhancementsEnabled())
    , m_inputTypeDateEnabled(page->settings().inputTypeDateEnabled())
    , m_inputTypeDateTimeLocalEnabled(page->settings().inputTypeDateTimeLocalEnabled())
    , m_inputTypeMonthEnabled(page->settings().inputTypeMonthEnabled())
    , m_inputTypeTimeEnabled(page->settings().inputTypeTimeEnabled())
    , m_inputTypeWeekEnabled(page->settings().inputTypeWeekEnabled())
    , m_inspectorMaximumResourcesContentSize(page->settings().inspectorMaximumResourcesContentSize())
    , m_inspectorSupportsShowingCertificate(page->settings().inspectorSupportsShowingCertificate())
    , m_interactionRegionInlinePadding(page->settings().interactionRegionInlinePadding())
    , m_interactionRegionMinimumCornerRadius(page->settings().interactionRegionMinimumCornerRadius())
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    , m_interactionRegionsEnabled(page->settings().interactionRegionsEnabled())
#endif
    , m_interactiveFormValidationEnabled(page->settings().interactiveFormValidationEnabled())
#if ENABLE(MEDIA_STREAM)
    , m_interruptAudioOnPageVisibilityChangeEnabled(page->settings().interruptAudioOnPageVisibilityChangeEnabled())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_interruptVideoOnPageVisibilityChangeEnabled(page->settings().interruptVideoOnPageVisibilityChangeEnabled())
#endif
    , m_invisibleAutoplayNotPermitted(page->settings().invisibleAutoplayNotPermitted())
    , m_isFirstPartyWebsiteDataRemovalDisabled(page->settings().isFirstPartyWebsiteDataRemovalDisabled())
    , m_isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled(page->settings().isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled())
    , m_isFirstPartyWebsiteDataRemovalReproTestingEnabled(page->settings().isFirstPartyWebsiteDataRemovalReproTestingEnabled())
    , m_isPerActivityStateCPUUsageMeasurementEnabled(page->settings().isPerActivityStateCPUUsageMeasurementEnabled())
    , m_isPostBackgroundingCPUUsageMeasurementEnabled(page->settings().isPostBackgroundingCPUUsageMeasurementEnabled())
    , m_isPostBackgroundingMemoryUsageMeasurementEnabled(page->settings().isPostBackgroundingMemoryUsageMeasurementEnabled())
    , m_isPostLoadCPUUsageMeasurementEnabled(page->settings().isPostLoadCPUUsageMeasurementEnabled())
    , m_isPostLoadMemoryUsageMeasurementEnabled(page->settings().isPostLoadMemoryUsageMeasurementEnabled())
    , m_isSameSiteStrictEnforcementEnabled(page->settings().isSameSiteStrictEnforcementEnabled())
    , m_isThirdPartyCookieBlockingDisabled(page->settings().isThirdPartyCookieBlockingDisabled())
    , m_itpDebugModeEnabled(page->settings().itpDebugModeEnabled())
    , m_javaScriptCanAccessClipboard(page->settings().javaScriptCanAccessClipboard())
    , m_javaScriptCanOpenWindowsAutomatically(page->settings().javaScriptCanOpenWindowsAutomatically())
    , m_langAttributeAwareFormControlUIEnabled(page->settings().langAttributeAwareFormControlUIEnabled())
    , m_largeImageAsyncDecodingEnabled(page->settings().largeImageAsyncDecodingEnabled())
    , m_layerBasedSVGEngineEnabled(page->settings().layerBasedSVGEngineEnabled())
    , m_layoutFallbackWidth(page->settings().layoutFallbackWidth())
    , m_layoutViewportHeightExpansionFactor(page->settings().layoutViewportHeightExpansionFactor())
    , m_lazyIframeLoadingEnabled(page->settings().lazyIframeLoadingEnabled())
    , m_lazyImageLoadingEnabled(page->settings().lazyImageLoadingEnabled())
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    , m_legacyEncryptedMediaAPIEnabled(page->settings().legacyEncryptedMediaAPIEnabled())
#endif
    , m_legacyLineLayoutVisualCoverageEnabled(page->settings().legacyLineLayoutVisualCoverageEnabled())
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
    , m_legacyOverflowScrollingTouchEnabled(page->settings().legacyOverflowScrollingTouchEnabled())
#endif
    , m_legacyPluginQuirkForMailSignaturesEnabled(page->settings().legacyPluginQuirkForMailSignaturesEnabled())
#if ENABLE(WEB_RTC)
    , m_legacyWebRTCOfferOptionsEnabled(page->settings().legacyWebRTCOfferOptionsEnabled())
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    , m_limitedMatroskaSupportEnabled(page->settings().limitedMatroskaSupportEnabled())
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
    , m_linearMediaPlayerEnabled(page->settings().linearMediaPlayerEnabled())
#endif
    , m_linkDNSPrefetchEnabled(page->settings().linkDNSPrefetchEnabled())
    , m_linkPreconnectEarlyHintsEnabled(page->settings().linkPreconnectEarlyHintsEnabled())
    , m_linkPreconnectEnabled(page->settings().linkPreconnectEnabled())
    , m_linkPrefetchEnabled(page->settings().linkPrefetchEnabled())
    , m_linkPreloadEnabled(page->settings().linkPreloadEnabled())
    , m_linkSanitizerEnabled(page->settings().linkSanitizerEnabled())
    , m_loadDeferringEnabled(page->settings().loadDeferringEnabled())
#if ENABLE(WEB_ARCHIVE)
    , m_loadWebArchiveWithEphemeralStorageEnabled(page->settings().loadWebArchiveWithEphemeralStorageEnabled())
#endif
    , m_loadsImagesAutomatically(page->settings().loadsImagesAutomatically())
    , m_localFileContentSniffingEnabled(page->settings().localFileContentSniffingEnabled())
    , m_localNetworkAccessEnabled(page->settings().localNetworkAccessEnabled())
    , m_localStorageDatabasePath(page->settings().localStorageDatabasePath())
    , m_localStorageEnabled(page->settings().localStorageEnabled())
    , m_lockdownFontParserEnabled(page->settings().lockdownFontParserEnabled())
    , m_loginStatusAPIEnabled(page->settings().loginStatusAPIEnabled())
    , m_loginStatusAPIRequiresWebAuthnEnabled(page->settings().loginStatusAPIRequiresWebAuthnEnabled())
    , m_logsPageMessagesToSystemConsoleEnabled(page->settings().logsPageMessagesToSystemConsoleEnabled())
    , m_mainContentUserGestureOverrideEnabled(page->settings().mainContentUserGestureOverrideEnabled())
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
    , m_manageCaptureStatusBarInGPUProcessEnabled(page->settings().manageCaptureStatusBarInGPUProcessEnabled())
#endif
#if ENABLE(MEDIA_SOURCE)
    , m_managedMediaSourceEnabled(page->settings().managedMediaSourceEnabled())
#endif
#if ENABLE(MEDIA_SOURCE)
    , m_managedMediaSourceHighThreshold(page->settings().managedMediaSourceHighThreshold())
#endif
#if ENABLE(MEDIA_SOURCE)
    , m_managedMediaSourceLowThreshold(page->settings().managedMediaSourceLowThreshold())
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
    , m_managedMediaSourceNeedsAirPlay(page->settings().managedMediaSourceNeedsAirPlay())
#endif
    , m_masonryEnabled(page->settings().masonryEnabled())
#if ENABLE(MATHML)
    , m_mathMLEnabled(page->settings().mathMLEnabled())
#endif
    , m_maxParseDuration(page->settings().maxParseDuration())
    , m_maximumHTMLParserDOMTreeDepth(page->settings().maximumHTMLParserDOMTreeDepth())
#if ENABLE(MEDIA_SOURCE)
    , m_maximumSourceBufferSize(page->settings().maximumSourceBufferSize())
#endif
    , m_mediaCapabilitiesEnabled(page->settings().mediaCapabilitiesEnabled())
    , m_mediaCapabilitiesExtensionsEnabled(page->settings().mediaCapabilitiesExtensionsEnabled())
#if ENABLE(EXTENSION_CAPABILITIES)
    , m_mediaCapabilityGrantsEnabled(page->settings().mediaCapabilityGrantsEnabled())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_mediaCaptureRequiresSecureConnection(page->settings().mediaCaptureRequiresSecureConnection())
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
    , m_mediaControlsContextMenusEnabled(page->settings().mediaControlsContextMenusEnabled())
#endif
    , m_mediaControlsScaleWithPageZoom(page->settings().mediaControlsScaleWithPageZoom())
    , m_mediaDataLoadsAutomatically(page->settings().mediaDataLoadsAutomatically())
#if ENABLE(MEDIA_STREAM)
    , m_mediaDevicesEnabled(page->settings().mediaDevicesEnabled())
#endif
#if ENABLE(VIDEO)
    , m_mediaEnabled(page->settings().mediaEnabled())
#endif
    , m_mediaKeysStorageDirectory(page->settings().mediaKeysStorageDirectory())
    , m_mediaPlaybackEnabled(page->settings().mediaPlaybackEnabled())
    , m_mediaPreferredFullscreenWidth(page->settings().mediaPreferredFullscreenWidth())
    , m_mediaPreloadingEnabled(page->settings().mediaPreloadingEnabled())
#if ENABLE(MEDIA_RECORDER)
    , m_mediaRecorderEnabled(page->settings().mediaRecorderEnabled())
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    , m_mediaRecorderEnabledWebM(page->settings().mediaRecorderEnabledWebM())
#endif
    , m_mediaSessionCaptureToggleAPIEnabled(page->settings().mediaSessionCaptureToggleAPIEnabled())
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    , m_mediaSessionCoordinatorEnabled(page->settings().mediaSessionCoordinatorEnabled())
#endif
#if ENABLE(MEDIA_SESSION)
    , m_mediaSessionEnabled(page->settings().mediaSessionEnabled())
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
    , m_mediaSessionPlaylistEnabled(page->settings().mediaSessionPlaylistEnabled())
#endif
    , m_mediaSourceEnabled(page->settings().mediaSourceEnabled())
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
    , m_mediaSourceInWorkerEnabled(page->settings().mediaSourceInWorkerEnabled())
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
    , m_mediaSourcePrefersDecompressionSession(page->settings().mediaSourcePrefersDecompressionSession())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_mediaStreamTrackProcessingEnabled(page->settings().mediaStreamTrackProcessingEnabled())
#endif
    , m_mediaTypeOverride(page->settings().mediaTypeOverride())
    , m_mediaUserGestureInheritsFromDocument(page->settings().mediaUserGestureInheritsFromDocument())
    , m_metaViewportInteractiveWidgetEnabled(page->settings().metaViewportInteractiveWidgetEnabled())
    , m_minimumFontSize(page->settings().minimumFontSize())
    , m_minimumLogicalFontSize(page->settings().minimumLogicalFontSize())
#if ENABLE(TEXT_AUTOSIZING)
    , m_minimumZoomFontSize(page->settings().minimumZoomFontSize())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_mockCaptureDevicesEnabled(page->settings().mockCaptureDevicesEnabled())
#endif
    , m_mockScrollbarsControllerEnabled(page->settings().mockScrollbarsControllerEnabled())
#if ENABLE(MODEL_ELEMENT)
    , m_modelElementEnabled(page->settings().modelElementEnabled())
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    , m_modelNoPortalAttributeEnabled(page->settings().modelNoPortalAttributeEnabled())
#endif
#if ENABLE(MODEL_PROCESS)
    , m_modelProcessEnabled(page->settings().modelProcessEnabled())
#endif
    , m_momentumScrollingAnimatorEnabled(page->settings().momentumScrollingAnimatorEnabled())
#if ENABLE(TOUCH_EVENTS)
    , m_mouseEventsSimulationEnabled(page->settings().mouseEventsSimulationEnabled())
#endif
    , m_mutationEventsEnabled(page->settings().mutationEventsEnabled())
#if ENABLE(MEDIA_STREAM)
    , m_muteCameraOnMicrophoneInterruptionEnabled(page->settings().muteCameraOnMicrophoneInterruptionEnabled())
#endif
    , m_navigationAPIEnabled(page->settings().navigationAPIEnabled())
    , m_navigatorUserAgentDataJavaScriptAPIEnabled(page->settings().navigatorUserAgentDataJavaScriptAPIEnabled())
    , m_needsAdobeFrameReloadingQuirk(page->settings().needsAcrobatFrameReloadingQuirk())
    , m_needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk(page->settings().needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk())
    , m_needsFrameNameFallbackToIdQuirk(page->settings().needsFrameNameFallbackToIdQuirk())
    , m_needsKeyboardEventDisambiguationQuirks(page->settings().needsKeyboardEventDisambiguationQuirks())
    , m_needsSiteSpecificQuirks(page->settings().needsSiteSpecificQuirks())
    , m_needsStorageAccessFromFileURLsQuirk(page->settings().needsStorageAccessFromFileURLsQuirk())
#if ENABLE(NOTIFICATION_EVENT)
    , m_notificationEventEnabled(page->settings().notificationEventEnabled())
#endif
#if ENABLE(NOTIFICATIONS)
    , m_notificationsEnabled(page->settings().notificationsEnabled())
#endif
    , m_observableEnabled(page->settings().observableEnabled())
#if ENABLE(OFFSCREEN_CANVAS)
    , m_offscreenCanvasEnabled(page->settings().offscreenCanvasEnabled())
#endif
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
    , m_offscreenCanvasInWorkersEnabled(page->settings().offscreenCanvasInWorkersEnabled())
#endif
    , m_opportunisticSweepingAndGarbageCollectionEnabled(page->settings().opportunisticSweepingAndGarbageCollectionEnabled())
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
    , m_optInPartitionedCookiesEnabled(page->settings().optInPartitionedCookiesEnabled())
#endif
    , m_overlappingBackingStoreProvidersEnabled(page->settings().overlappingBackingStoreProvidersEnabled())
    , m_overscrollBehaviorEnabled(page->settings().overscrollBehaviorEnabled())
    , m_pageAtRuleMarginDescriptorsEnabled(page->settings().pageAtRuleMarginDescriptorsEnabled())
    , m_passiveTouchListenersAsDefaultOnDocument(page->settings().passiveTouchListenersAsDefaultOnDocument())
    , m_passiveWheelListenersAsDefaultOnDocument(page->settings().passiveWheelListenersAsDefaultOnDocument())
    , m_passwordEchoDurationInSeconds(page->settings().passwordEchoDurationInSeconds())
    , m_passwordEchoEnabled(page->settings().passwordEchoEnabled())
#if ENABLE(PAYMENT_REQUEST)
    , m_paymentRequestEnabled(page->settings().paymentRequestEnabled())
#endif
#if ENABLE(PDFJS)
    , m_pdfJSViewerEnabled(page->settings().pdfJSViewerEnabled())
#endif
#if PLATFORM(COCOA)
    , m_pdfPluginEnabled(page->settings().pdfPluginEnabled())
#endif
#if PLATFORM(COCOA)
    , m_pdfPluginHUDEnabled(page->settings().pdfPluginHUDEnabled())
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    , m_pdfPluginPageNumberIndicatorEnabled(page->settings().pdfPluginPageNumberIndicatorEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_peerConnectionEnabled(page->settings().peerConnectionEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_peerConnectionVideoScalingAdaptationDisabled(page->settings().peerConnectionVideoScalingAdaptationDisabled())
#endif
#if ENABLE(MEDIA_STREAM)
    , m_perElementSpeakerSelectionEnabled(page->settings().perElementSpeakerSelectionEnabled())
#endif
    , m_permissionsAPIEnabled(page->settings().permissionsAPIEnabled())
    , m_pictographFontFamily(page->settings().pictographFontFamily())
#if ENABLE(PICTURE_IN_PICTURE_API)
    , m_pictureInPictureAPIEnabled(page->settings().pictureInPictureAPIEnabled())
#endif
#if HAVE(PIP_SKIP_PREROLL)
    , m_pictureInPicturePlaybackStateEnabled(page->settings().pictureInPicturePlaybackStateEnabled())
#endif
#if ENABLE(POINTER_LOCK)
    , m_pointerLockEnabled(page->settings().pointerLockEnabled())
#endif
#if ENABLE(POINTER_LOCK)
    , m_pointerLockOptionsEnabled(page->settings().pointerLockOptionsEnabled())
#endif
    , m_popoverAttributeEnabled(page->settings().popoverAttributeEnabled())
    , m_preferMIMETypeForImages(page->settings().preferMIMETypeForImages())
    , m_preferPageRenderingUpdatesNear60FPSEnabled(page->settings().preferPageRenderingUpdatesNear60FPSEnabled())
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    , m_preferSpatialAudioExperience(page->settings().preferSpatialAudioExperience())
#endif
    , m_preventKeyboardDOMEventDispatch(page->settings().preventKeyboardDOMEventDispatch())
    , m_privateClickMeasurementDebugModeEnabled(page->settings().privateClickMeasurementDebugModeEnabled())
    , m_privateClickMeasurementEnabled(page->settings().privateClickMeasurementEnabled())
    , m_privateClickMeasurementFraudPreventionEnabled(page->settings().privateClickMeasurementFraudPreventionEnabled())
    , m_privateTokenUsageByThirdPartyEnabled(page->settings().privateTokenUsageByThirdPartyEnabled())
#if ENABLE(DAMAGE_TRACKING)
    , m_propagateDamagingInformation(page->settings().propagateDamagingInformation())
#endif
    , m_punchOutWhiteBackgroundsInDarkMode(page->settings().punchOutWhiteBackgroundsInDarkMode())
    , m_pushAPIEnabled(page->settings().pushAPIEnabled())
    , m_remoteMediaSessionManagerEnabled(page->settings().remoteMediaSessionManagerEnabled())
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    , m_remotePlaybackEnabled(page->settings().remotePlaybackEnabled())
#endif
    , m_remoteSnapshottingEnabled(page->settings().remoteSnapshottingEnabled())
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    , m_removeBackgroundEnabled(page->settings().removeBackgroundEnabled())
#endif
    , m_requestIdleCallbackEnabled(page->settings().requestIdleCallbackEnabled())
    , m_requestStorageAccessThrowsExceptionUntilReload(page->settings().requestStorageAccessThrowsExceptionUntilReload())
    , m_requestVideoFrameCallbackEnabled(page->settings().requestVideoFrameCallbackEnabled())
#if HAVE(SC_CONTENT_SHARING_PICKER)
    , m_requireUAGetDisplayMediaPrompt(page->settings().requireUAGetDisplayMediaPrompt())
#endif
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
    , m_requiresPageVisibilityForVideoToBeNowPlaying(page->settings().requiresPageVisibilityForVideoToBeNowPlaying())
#endif
    , m_requiresPageVisibilityToPlayAudio(page->settings().requiresPageVisibilityToPlayAudio())
    , m_requiresUserGestureForAudioPlayback(page->settings().requiresUserGestureForAudioPlayback())
    , m_requiresUserGestureForVideoPlayback(page->settings().requiresUserGestureForVideoPlayback())
    , m_requiresUserGestureToLoadVideo(page->settings().requiresUserGestureToLoadVideo())
    , m_resourceLoadSchedulingEnabled(page->settings().resourceLoadSchedulingEnabled())
#if ENABLE(RESOURCE_USAGE)
    , m_resourceUsageOverlayVisible(page->settings().resourceUsageOverlayVisible())
#endif
    , m_respondToThermalPressureAggressively(page->settings().respondToThermalPressureAggressively())
#if HAVE(RUBBER_BANDING)
    , m_rubberBandingForSubScrollableRegionsEnabled(page->settings().rubberBandingForSubScrollableRegionsEnabled())
#endif
    , m_sKAttributionEnabled(page->settings().sKAttributionEnabled())
    , m_sampledPageTopColorMaxDifference(page->settings().sampledPageTopColorMaxDifference())
    , m_sampledPageTopColorMinHeight(page->settings().sampledPageTopColorMinHeight())
    , m_sansSerifFontFamily(page->settings().sansSerifFontFamily())
    , m_scopedCustomElementRegistryEnabled(page->settings().scopedCustomElementRegistryEnabled())
#if ENABLE(MEDIA_STREAM)
    , m_screenCaptureEnabled(page->settings().screenCaptureEnabled())
#endif
    , m_screenOrientationAPIEnabled(page->settings().screenOrientationAPIEnabled())
    , m_screenOrientationLockingAPIEnabled(page->settings().screenOrientationLockingAPIEnabled())
#if ENABLE(SCREEN_TIME)
    , m_screenTimeEnabled(page->settings().screenTimeEnabled())
#endif
    , m_screenWakeLockAPIEnabled(page->settings().screenWakeLockAPIEnabled())
    , m_scriptEnabled(page->settings().isScriptEnabled())
    , m_scriptMarkupEnabled(page->settings().scriptMarkupEnabled())
    , m_scriptTrackingPrivacyLoggingEnabled(page->settings().scriptTrackingPrivacyLoggingEnabled())
    , m_scrollAnimatorEnabled(page->settings().scrollAnimatorEnabled())
    , m_scrollDrivenAnimationsEnabled(page->settings().scrollDrivenAnimationsEnabled())
    , m_scrollToTextFragmentEnabled(page->settings().scrollToTextFragmentEnabled())
    , m_scrollToTextFragmentFeatureDetectionEnabled(page->settings().scrollToTextFragmentFeatureDetectionEnabled())
    , m_scrollToTextFragmentGenerationEnabled(page->settings().scrollToTextFragmentGenerationEnabled())
    , m_scrollToTextFragmentIndicatorEnabled(page->settings().scrollToTextFragmentIndicatorEnabled())
    , m_scrollToTextFragmentMarkingEnabled(page->settings().scrollToTextFragmentMarkingEnabled())
    , m_scrollendEventEnabled(page->settings().scrollendEventEnabled())
    , m_scrollingCoordinatorEnabled(page->settings().scrollingCoordinatorEnabled())
    , m_scrollingPerformanceTestingEnabled(page->settings().scrollingPerformanceTestingEnabled())
    , m_scrollingTreeIncludesFrames(page->settings().scrollingTreeIncludesFrames())
    , m_secureContextChecksEnabled(page->settings().secureContextChecksEnabled())
    , m_selectShowPickerEnabled(page->settings().selectShowPickerEnabled())
    , m_selectTrailingWhitespaceEnabled(page->settings().selectTrailingWhitespaceEnabled())
#if PLATFORM(IOS_FAMILY)
    , m_selectionHonorsOverflowScrolling(page->settings().selectionHonorsOverflowScrolling())
#endif
    , m_serifFontFamily(page->settings().serifFontFamily())
#if ENABLE(SERVICE_CONTROLS)
    , m_serviceControlsEnabled(page->settings().serviceControlsEnabled())
#endif
    , m_serviceWorkerInstallEventEnabled(page->settings().serviceWorkerInstallEventEnabled())
    , m_serviceWorkerNavigationPreloadEnabled(page->settings().serviceWorkerNavigationPreloadEnabled())
    , m_serviceWorkersEnabled(page->settings().serviceWorkersEnabled())
    , m_serviceWorkersUserGestureEnabled(page->settings().serviceWorkersUserGestureEnabled())
    , m_sessionStorageQuota(page->settings().sessionStorageQuota())
    , m_shadowRootReferenceTargetEnabled(page->settings().shadowRootReferenceTargetEnabled())
    , m_shadowRootReferenceTargetEnabledForAriaOwns(page->settings().shadowRootReferenceTargetEnabledForAriaOwns())
    , m_shapeDetection(page->settings().shapeDetection())
    , m_sharedWorkerEnabled(page->settings().sharedWorkerEnabled())
    , m_shouldAllowUserInstalledFonts(page->settings().shouldAllowUserInstalledFonts())
    , m_shouldConvertInvalidURLsToBlank(page->settings().shouldConvertInvalidURLsToBlank())
    , m_shouldConvertPositionStyleOnCopy(page->settings().shouldConvertPositionStyleOnCopy())
    , m_shouldDecidePolicyBeforeLoadingQuickLookPreview(page->settings().shouldDecidePolicyBeforeLoadingQuickLookPreview())
    , m_shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint(page->settings().shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint())
    , m_shouldDispatchSyntheticMouseEventsWhenModifyingSelection(page->settings().shouldDispatchSyntheticMouseEventsWhenModifyingSelection())
    , m_shouldDispatchSyntheticMouseOutAfterSyntheticClick(page->settings().shouldDispatchSyntheticMouseOutAfterSyntheticClick())
#if ENABLE(VIDEO)
    , m_shouldDisplayCaptions(page->settings().shouldDisplayCaptions())
#endif
#if ENABLE(VIDEO)
    , m_shouldDisplaySubtitles(page->settings().shouldDisplaySubtitles())
#endif
#if ENABLE(VIDEO)
    , m_shouldDisplayTextDescriptions(page->settings().shouldDisplayTextDescriptions())
#endif
    , m_shouldDropNearSuspendedAssertionAfterDelay(page->settings().shouldDropNearSuspendedAssertionAfterDelay())
#if ENABLE(TEXT_AUTOSIZING)
    , m_shouldEnableTextAutosizingBoost(page->settings().shouldEnableTextAutosizingBoost())
#endif
    , m_shouldIgnoreFontLoadCompletions(page->settings().shouldIgnoreFontLoadCompletions())
    , m_shouldIgnoreMetaViewport(page->settings().shouldIgnoreMetaViewport())
    , m_shouldInjectUserScriptsInInitialEmptyDocument(page->settings().shouldInjectUserScriptsInInitialEmptyDocument())
    , m_shouldPrintBackgrounds(page->settings().shouldPrintBackgrounds())
    , m_shouldRespectImageOrientation(page->settings().shouldRespectImageOrientation())
    , m_shouldRestrictBaseURLSchemes(page->settings().shouldRestrictBaseURLSchemes())
    , m_shouldSuppressTextInputFromEditingDuringProvisionalNavigation(page->settings().shouldSuppressTextInputFromEditingDuringProvisionalNavigation())
    , m_shouldTakeNearSuspendedAssertions(page->settings().shouldTakeNearSuspendedAssertions())
#if USE(MODERN_AVCONTENTKEYSESSION)
    , m_shouldUseModernAVContentKeySession(page->settings().shouldUseModernAVContentKeySession())
#endif
    , m_shouldUseServiceWorkerShortTimeout(page->settings().shouldUseServiceWorkerShortTimeout())
    , m_showDebugBorders(page->settings().showDebugBorders())
    , m_showFrameProcessBorders(page->settings().showFrameProcessBorders())
    , m_showMediaStatsContextMenuItemEnabled(page->settings().showMediaStatsContextMenuItemEnabled())
    , m_showModalDialogEnabled(page->settings().showModalDialogEnabled())
    , m_showRepaintCounter(page->settings().showRepaintCounter())
    , m_showTiledScrollingIndicator(page->settings().showTiledScrollingIndicator())
    , m_showsToolTipOverTruncatedText(page->settings().showsToolTipOverTruncatedText())
    , m_showsURLsInToolTips(page->settings().showsURLsInToolTips())
    , m_shrinksStandaloneImagesToFit(page->settings().shrinksStandaloneImagesToFit())
    , m_sidewaysWritingModesEnabled(page->settings().sidewaysWritingModesEnabled())
    , m_siteIsolationEnabled(page->settings().siteIsolationEnabled())
    , m_siteIsolationSharedProcessEnabled(page->settings().siteIsolationSharedProcessEnabled())
    , m_smartInsertDeleteEnabled(page->settings().smartInsertDeleteEnabled())
#if ENABLE(MEDIA_SOURCE)
    , m_sourceBufferChangeTypeEnabled(page->settings().sourceBufferChangeTypeEnabled())
#endif
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
    , m_spatialImageControlsEnabled(page->settings().spatialImageControlsEnabled())
#endif
    , m_spatialNavigationEnabled(page->settings().spatialNavigationEnabled())
#if ENABLE(MEDIA_STREAM)
    , m_speakerSelectionRequiresUserGesture(page->settings().speakerSelectionRequiresUserGesture())
#endif
    , m_speechRecognitionEnabled(page->settings().speechRecognitionEnabled())
    , m_speechSynthesisAPIEnabled(page->settings().speechSynthesisAPIEnabled())
    , m_springTimingFunctionEnabled(page->settings().springTimingFunctionEnabled())
    , m_standalone(page->settings().standalone())
    , m_standardFontFamily(page->settings().standardFontFamily())
    , m_storageAPIEnabled(page->settings().storageAPIEnabled())
    , m_storageAPIEstimateEnabled(page->settings().storageAPIEstimateEnabled())
    , m_storageAccessAPIPerPageScopeEnabled(page->settings().storageAccessAPIPerPageScopeEnabled())
    , m_supportHDRCompositorTonemappingEnabled(page->settings().supportHDRCompositorTonemappingEnabled())
    , m_supportHDRDisplayEnabled(page->settings().supportHDRDisplayEnabled())
    , m_suppressHDRShouldBeAllowedInFullscreenVideo(page->settings().suppressHDRShouldBeAllowedInFullscreenVideo())
    , m_suppressesIncrementalRendering(page->settings().suppressesIncrementalRendering())
    , m_switchControlEnabled(page->settings().switchControlEnabled())
#if USE(SYSTEM_PREVIEW)
    , m_systemPreviewEnabled(page->settings().systemPreviewEnabled())
#endif
    , m_targetTextPseudoElementEnabled(page->settings().targetTextPseudoElementEnabled())
    , m_telephoneNumberParsingEnabled(page->settings().telephoneNumberParsingEnabled())
    , m_temporaryTileCohortRetentionEnabled(page->settings().temporaryTileCohortRetentionEnabled())
#if ENABLE(WRITING_TOOLS)
    , m_textAnimationsEnabled(page->settings().textAnimationsEnabled())
#endif
    , m_textAreasAreResizable(page->settings().textAreasAreResizable())
#if ENABLE(TEXT_AUTOSIZING)
    , m_textAutosizingEnabled(page->settings().textAutosizingEnabled())
#endif
#if ENABLE(TEXT_AUTOSIZING)
    , m_textAutosizingEnabledAtLargeInitialScale(page->settings().textAutosizingEnabledAtLargeInitialScale())
#endif
#if ENABLE(TEXT_AUTOSIZING)
    , m_textAutosizingUsesIdempotentMode(page->settings().textAutosizingUsesIdempotentMode())
#endif
#if ENABLE(TEXT_AUTOSIZING)
    , m_textAutosizingWindowSizeOverrideHeight(page->settings().textAutosizingWindowSizeOverrideHeight())
#endif
#if ENABLE(TEXT_AUTOSIZING)
    , m_textAutosizingWindowSizeOverrideWidth(page->settings().textAutosizingWindowSizeOverrideWidth())
#endif
    , m_textInteractionEnabled(page->settings().textInteractionEnabled())
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    , m_textRecognitionInVideosEnabled(page->settings().textRecognitionInVideosEnabled())
#endif
#if ENABLE(MEDIA_SOURCE)
    , m_textTracksInMSEEnabled(page->settings().textTracksInMSEEnabled())
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
    , m_threadedAnimationResolutionEnabled(page->settings().threadedAnimationResolutionEnabled())
#endif
    , m_thumbAndTrackPseudoElementsEnabled(page->settings().thumbAndTrackPseudoElementsEnabled())
    , m_topContentInsetBackgroundCanChangeAfterScrolling(page->settings().topContentInsetBackgroundCanChangeAfterScrolling())
#if ENABLE(TOUCH_EVENTS)
    , m_touchEventDOMAttributesEnabled(page->settings().touchEventDOMAttributesEnabled())
#endif
#if ENABLE(TOUCH_EVENTS)
    , m_touchEventEmulationEnabled(page->settings().isTouchEventEmulationEnabled())
#endif
#if ENABLE(WEBXR)
    , m_touchInputCompatibilityEnabled(page->settings().touchInputCompatibilityEnabled())
#endif
    , m_trackConfigurationEnabled(page->settings().trackConfigurationEnabled())
    , m_treatIPAddressAsDomain(page->settings().treatIPAddressAsDomain())
    , m_treatsAnyTextCSSLinkAsStylesheet(page->settings().treatsAnyTextCSSLinkAsStylesheet())
    , m_trustedTypesEnabled(page->settings().trustedTypesEnabled())
    , m_uAVisualTransitionDetectionEnabled(page->settings().uAVisualTransitionDetectionEnabled())
    , m_undoManagerAPIEnabled(page->settings().undoManagerAPIEnabled())
    , m_unhandledPromiseRejectionToConsoleEnabled(page->settings().unhandledPromiseRejectionToConsoleEnabled())
#if ENABLE(UNIFIED_PDF)
    , m_unifiedPDFEnabled(page->settings().unifiedPDFEnabled())
#endif
    , m_unifiedTextCheckerEnabled(page->settings().unifiedTextCheckerEnabled())
#if ENABLE(DAMAGE_TRACKING)
    , m_unifyDamagedRegions(page->settings().unifyDamagedRegions())
#endif
    , m_upgradeMixedContentEnabled(page->settings().upgradeMixedContentEnabled())
    , m_urlPatternAPIEnabled(page->settings().urlPatternAPIEnabled())
    , m_useAnonymousModeWhenFetchingMaskImages(page->settings().useAnonymousModeWhenFetchingMaskImages())
#if PLATFORM(IOS_FAMILY)
    , m_useAsyncUIKitInteractions(page->settings().useAsyncUIKitInteractions())
#endif
#if ENABLE(DAMAGE_TRACKING)
    , m_useDamagingInformationForCompositing(page->settings().useDamagingInformationForCompositing())
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
    , m_useGPUProcessForWebGLEnabled(page->settings().useGPUProcessForWebGLEnabled())
#endif
    , m_useGiantTiles(page->settings().useGiantTiles())
    , m_useIFCForSVGText(page->settings().useIFCForSVGText())
    , m_useImageDocumentForSubframePDF(page->settings().useImageDocumentForSubframePDF())
#if ENABLE(MEDIA_STREAM)
    , m_useMicrophoneMuteStatusAPI(page->settings().useMicrophoneMuteStatusAPI())
#endif
    , m_usePreHTML5ParserQuirks(page->settings().usePreHTML5ParserQuirks())
    , m_useSystemAppearance(page->settings().useSystemAppearance())
    , m_userActivationAPIEnabled(page->settings().userActivationAPIEnabled())
    , m_userGesturePromisePropagationEnabled(page->settings().userGesturePromisePropagationEnabled())
    , m_usesEncodingDetector(page->settings().usesEncodingDetector())
    , m_validationMessageTimerMagnification(page->settings().validationMessageTimerMagnification())
    , m_verifyWindowOpenUserGestureFromUIProcess(page->settings().verifyWindowOpenUserGestureFromUIProcess())
    , m_verticalFormControlsEnabled(page->settings().verticalFormControlsEnabled())
#if ENABLE(FULLSCREEN_API)
    , m_videoFullsceenPrefersMostVisibleHeuristic(page->settings().videoFullsceenPrefersMostVisibleHeuristic())
#endif
#if ENABLE(FULLSCREEN_API)
    , m_videoFullscreenRequiresElementFullscreen(page->settings().videoFullscreenRequiresElementFullscreen())
#endif
    , m_videoPresentationManagerEnabled(page->settings().videoPresentationManagerEnabled())
    , m_videoPresentationModeAPIEnabled(page->settings().videoPresentationModeAPIEnabled())
#if ENABLE(VIDEO)
    , m_videoQualityIncludesDisplayCompositingEnabled(page->settings().videoQualityIncludesDisplayCompositingEnabled())
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    , m_videoRendererProtectedFallbackDisabled(page->settings().videoRendererProtectedFallbackDisabled())
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    , m_videoRendererUseDecompressionSessionForProtected(page->settings().videoRendererUseDecompressionSessionForProtected())
#endif
    , m_viewTransitionClassesEnabled(page->settings().viewTransitionClassesEnabled())
    , m_viewTransitionTypesEnabled(page->settings().viewTransitionTypesEnabled())
    , m_viewTransitionsEnabled(page->settings().viewTransitionsEnabled())
    , m_visibleDebugOverlayRegions(page->settings().visibleDebugOverlayRegions())
#if ENABLE(IMAGE_ANALYSIS)
    , m_visualTranslationEnabled(page->settings().visualTranslationEnabled())
#endif
    , m_visualViewportAPIEnabled(page->settings().visualViewportAPIEnabled())
    , m_visualViewportEnabled(page->settings().visualViewportEnabled())
#if PLATFORM(IOS_FAMILY)
    , m_visuallyContiguousBidiTextSelectionEnabled(page->settings().visuallyContiguousBidiTextSelectionEnabled())
#endif
#if ENABLE(VP9)
    , m_vp9DecoderEnabled(page->settings().vp9DecoderEnabled())
#endif
    , m_wantsBalancedSetDefersLoadingBehavior(page->settings().wantsBalancedSetDefersLoadingBehavior())
    , m_webAPIStatisticsEnabled(page->settings().webAPIStatisticsEnabled())
    , m_webAPIsInShadowRealmEnabled(page->settings().webAPIsInShadowRealmEnabled())
    , m_webAnimationsCustomEffectsEnabled(page->settings().webAnimationsCustomEffectsEnabled())
    , m_webAnimationsCustomFrameRateEnabled(page->settings().webAnimationsCustomFrameRateEnabled())
    , m_webAnimationsOverallProgressPropertyEnabled(page->settings().webAnimationsOverallProgressPropertyEnabled())
#if ENABLE(WEB_ARCHIVE)
    , m_webArchiveDebugModeEnabled(page->settings().webArchiveDebugModeEnabled())
#endif
#if ENABLE(WEB_ARCHIVE)
    , m_webArchiveTestingModeEnabled(page->settings().webArchiveTestingModeEnabled())
#endif
#if ENABLE(WEBASSEMBLY)
    , m_webAssemblyESMIntegrationEnabled(page->settings().webAssemblyESMIntegrationEnabled())
#endif
#if ENABLE(WEB_AUDIO)
    , m_webAudioEnabled(page->settings().webAudioEnabled())
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
    , m_webAuthenticationASEnabled(page->settings().webAuthenticationASEnabled())
#endif
#if ENABLE(WEB_AUTHN)
    , m_webAuthenticationEnabled(page->settings().webAuthenticationEnabled())
#endif
#if ENABLE(WEB_CODECS)
    , m_webCodecsAV1Enabled(page->settings().webCodecsAV1Enabled())
#endif
#if ENABLE(WEB_CODECS)
    , m_webCodecsAudioEnabled(page->settings().webCodecsAudioEnabled())
#endif
#if ENABLE(WEB_CODECS)
    , m_webCodecsHEVCEnabled(page->settings().webCodecsHEVCEnabled())
#endif
#if ENABLE(WEB_CODECS)
    , m_webCodecsVideoEnabled(page->settings().webCodecsVideoEnabled())
#endif
    , m_webCryptoSafeCurvesEnabled(page->settings().webCryptoSafeCurvesEnabled())
    , m_webCryptoX25519Enabled(page->settings().webCryptoX25519Enabled())
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    , m_webExtensionBookmarksEnabled(page->settings().webExtensionBookmarksEnabled())
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    , m_webExtensionSidebarEnabled(page->settings().webExtensionSidebarEnabled())
#endif
    , m_webGLDraftExtensionsEnabled(page->settings().webGLDraftExtensionsEnabled())
    , m_webGLEnabled(page->settings().webGLEnabled())
    , m_webGLErrorsToConsoleEnabled(page->settings().webGLErrorsToConsoleEnabled())
    , m_webGLTimerQueriesEnabled(page->settings().webGLTimerQueriesEnabled())
    , m_webGPUEnabled(page->settings().webGPUEnabled())
    , m_webGPUHDREnabled(page->settings().webGPUHDREnabled())
    , m_webInspectorEngineeringSettingsAllowed(page->settings().webInspectorEngineeringSettingsAllowed())
    , m_webLocksAPIEnabled(page->settings().webLocksAPIEnabled())
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    , m_webPageSpatialBackdropEnabled(page->settings().webPageSpatialBackdropEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCAV1CodecEnabled(page->settings().webRTCAV1CodecEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCDTMFEnabled(page->settings().webRTCDTMFEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCEncodedTransformEnabled(page->settings().webRTCEncodedTransformEnabled())
#endif
    , m_webRTCEncryptionEnabled(page->settings().webRTCEncryptionEnabled())
#if ENABLE(WEB_RTC)
    , m_webRTCH265CodecEnabled(page->settings().webRTCH265CodecEnabled())
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
    , m_webRTCInterfaceMonitoringViaNWEnabled(page->settings().webRTCInterfaceMonitoringViaNWEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCL4SEnabled(page->settings().webRTCL4SEnabled())
#endif
    , m_webRTCMediaPipelineAdditionalLoggingEnabled(page->settings().webRTCMediaPipelineAdditionalLoggingEnabled())
#if ENABLE(WEB_RTC)
    , m_webRTCPlatformCodecsInGPUProcessEnabled(page->settings().webRTCPlatformCodecsInGPUProcessEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCRemoteVideoFrameEnabled(page->settings().webRTCRemoteVideoFrameEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCSFrameTransformEnabled(page->settings().webRTCSFrameTransformEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCSocketsProxyingEnabled(page->settings().webRTCSocketsProxyingEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCUDPPortRange(page->settings().webRTCUDPPortRange())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCVP9Profile0CodecEnabled(page->settings().webRTCVP9Profile0CodecEnabled())
#endif
#if ENABLE(WEB_RTC)
    , m_webRTCVP9Profile2CodecEnabled(page->settings().webRTCVP9Profile2CodecEnabled())
#endif
    , m_webSecurityEnabled(page->settings().webSecurityEnabled())
    , m_webShareEnabled(page->settings().webShareEnabled())
    , m_webShareFileAPIEnabled(page->settings().webShareFileAPIEnabled())
    , m_webSocketEnabled(page->settings().webSocketEnabled())
    , m_webTransportEnabled(page->settings().webTransportEnabled())
#if ENABLE(WEBXR)
    , m_webXRAugmentedRealityModuleEnabled(page->settings().webXRAugmentedRealityModuleEnabled())
#endif
#if ENABLE(WEBXR)
    , m_webXREnabled(page->settings().webXREnabled())
#endif
#if ENABLE(WEBXR)
    , m_webXRGamepadsModuleEnabled(page->settings().webXRGamepadsModuleEnabled())
#endif
#if ENABLE(WEBXR_HANDS)
    , m_webXRHandInputModuleEnabled(page->settings().webXRHandInputModuleEnabled())
#endif
#if ENABLE(WEBXR_LAYERS)
    , m_webXRLayersAPIEnabled(page->settings().webXRLayersAPIEnabled())
#endif
    , m_webXRWebGPUBindingsEnabled(page->settings().webXRWebGPUBindingsEnabled())
    , m_webkitImageReadyEventEnabled(page->settings().webkitImageReadyEventEnabled())
    , m_wheelEventGesturesBecomeNonBlocking(page->settings().wheelEventGesturesBecomeNonBlocking())
    , m_windowFocusRestricted(page->settings().windowFocusRestricted())
    , m_wirelessPlaybackTargetAPIEnabled(page->settings().wirelessPlaybackTargetAPIEnabled())
    , m_workerAsynchronousURLErrorHandlingEnabled(page->settings().workerAsynchronousURLErrorHandlingEnabled())
#if PLATFORM(COCOA)
    , m_writeRichTextDataWhenCopyingOrDragging(page->settings().writeRichTextDataWhenCopyingOrDragging())
#endif
#if ENABLE(WRITING_SUGGESTIONS)
    , m_writingSuggestionsAttributeEnabled(page->settings().writingSuggestionsAttributeEnabled())
#endif
#if ENABLE(XSLT)
    , m_xsltEnabled(page->settings().isXSLTEnabled())
#endif
{
}

InternalSettingsGenerated::~InternalSettingsGenerated()
{
}

void InternalSettingsGenerated::resetToConsistentState()
{
#if HAVE(AVKIT_CONTENT_SOURCE)
    m_page->settings().setAVKitContentSourceEnabled(m_aVKitContentSourceEnabled);
#endif
    m_page->settings().setAcceleratedCompositingEnabled(m_acceleratedCompositingEnabled);
    m_page->settings().setAcceleratedCompositingForFixedPositionEnabled(m_acceleratedCompositingForFixedPositionEnabled);
    m_page->settings().setAcceleratedDrawingEnabled(m_acceleratedDrawingEnabled);
#if USE(CORE_IMAGE)
    m_page->settings().setAcceleratedFiltersEnabled(m_acceleratedFiltersEnabled);
#endif
    m_page->settings().setAccentColorEnabled(m_accentColorEnabled);
    m_page->settings().setAccessHandleEnabled(m_accessHandleEnabled);
    m_page->settings().setAggressiveTileRetentionEnabled(m_aggressiveTileRetentionEnabled);
    m_page->settings().setAllowAnimationControlsOverride(m_allowAnimationControlsOverride);
    m_page->settings().setAllowContentSecurityPolicySourceStarToMatchAnyProtocol(m_allowContentSecurityPolicySourceStarToMatchAnyProtocol);
    m_page->settings().setAllowDisplayOfInsecureContent(m_allowDisplayOfInsecureContent);
    m_page->settings().setAllowFileAccessFromFileURLs(m_allowFileAccessFromFileURLs);
    m_page->settings().setAllowMediaContentTypesRequiringHardwareSupportAsFallback(m_allowMediaContentTypesRequiringHardwareSupportAsFallback);
    m_page->settings().setAllowMultiElementImplicitSubmission(m_allowMultiElementImplicitSubmission);
    m_page->settings().setAllowPrivacySensitiveOperationsInNonPersistentDataStores(m_allowPrivacySensitiveOperationsInNonPersistentDataStores);
    m_page->settings().setAllowRunningOfInsecureContent(m_allowRunningOfInsecureContent);
    m_page->settings().setAllowTopNavigationToDataURLs(m_allowTopNavigationToDataURLs);
    m_page->settings().setAllowUniversalAccessFromFileURLs(m_allowUniversalAccessFromFileURLs);
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setAllowViewportShrinkToFitContent(m_allowViewportShrinkToFitContent);
#endif
#if ENABLE(WEBGL)
    m_page->settings().setAllowWebGLInWorkers(m_allowWebGLInWorkers);
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    m_page->settings().setAllowsAirPlayForMediaPlayback(m_allowsAirPlayForMediaPlayback);
#endif
    m_page->settings().setAllowsInlineMediaPlayback(m_allowsInlineMediaPlayback);
    m_page->settings().setAllowsInlineMediaPlaybackAfterFullscreen(m_allowsInlineMediaPlaybackAfterFullscreen);
    m_page->settings().setAllowsPictureInPictureMediaPlayback(m_allowsPictureInPictureMediaPlayback);
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setAlternateFullScreenControlDesignEnabled(m_alternateFullScreenControlDesignEnabled);
#endif
    m_page->settings().setAltitudeAngleEnabled(m_altitudeAngleEnabled);
#if ENABLE(WEB_ARCHIVE)
    m_page->settings().setAlwaysAllowLocalWebarchive(m_alwaysAllowLocalWebarchive);
#endif
    m_page->settings().setAnimatedImageAsyncDecodingEnabled(m_animatedImageAsyncDecodingEnabled);
    m_page->settings().setAnimatedImageDebugCanvasDrawingEnabled(m_animatedImageDebugCanvasDrawingEnabled);
    m_page->settings().setAppBadgeEnabled(m_appBadgeEnabled);
#if ENABLE(APP_HIGHLIGHTS)
    m_page->settings().setAppHighlightsEnabled(m_appHighlightsEnabled);
#endif
    m_page->settings().setAppleMailPaginationQuirkEnabled(m_appleMailPaginationQuirkEnabled);
#if ENABLE(APPLE_PAY)
    m_page->settings().setApplePayCapabilityDisclosureAllowed(m_applePayCapabilityDisclosureAllowed);
#endif
#if ENABLE(APPLE_PAY)
    m_page->settings().setApplePayEnabled(m_applePayEnabled);
#endif
    m_page->settings().setAsyncClipboardAPIEnabled(m_asyncClipboardAPIEnabled);
    m_page->settings().setAsyncFrameScrollingEnabled(m_asyncFrameScrollingEnabled);
    m_page->settings().setAsyncOverflowScrollingEnabled(m_asyncOverflowScrollingEnabled);
    m_page->settings().setAsynchronousSpellCheckingEnabled(m_asynchronousSpellCheckingEnabled);
#if ENABLE(ATTACHMENT_ELEMENT)
    m_page->settings().setAttachmentWideLayoutEnabled(m_attachmentWideLayoutEnabled);
#endif
    m_page->settings().setAudioControlsScaleWithPageZoom(m_audioControlsScaleWithPageZoom);
#if ENABLE(VIDEO)
    m_page->settings().setAudioDescriptionsEnabled(m_audioDescriptionsEnabled);
#endif
    m_page->settings().setAuthorAndUserStylesEnabled(m_authorAndUserStylesEnabled);
    m_page->settings().setAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth(m_automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth);
    m_page->settings().setAutoscrollForDragAndDropEnabled(m_autoscrollForDragAndDropEnabled);
    m_page->settings().setAuxclickEventEnabled(m_auxclickEventEnabled);
    m_page->settings().setAzimuthAngleEnabled(m_azimuthAngleEnabled);
    m_page->settings().setBackgroundFetchAPIEnabled(m_backgroundFetchAPIEnabled);
    m_page->settings().setBackgroundShouldExtendBeyondPage(m_backgroundShouldExtendBeyondPage);
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
    m_page->settings().setBackgroundWebContentRunningBoardThrottlingEnabled(m_backgroundWebContentRunningBoardThrottlingEnabled);
#endif
    m_page->settings().setBackspaceKeyNavigationEnabled(m_backspaceKeyNavigationEnabled);
    m_page->settings().setBeaconAPIEnabled(m_beaconAPIEnabled);
    m_page->settings().setBidiContentAwarePasteEnabled(m_bidiContentAwarePasteEnabled);
    m_page->settings().setBlobFileAccessEnforcementEnabled(m_blobFileAccessEnforcementEnabled);
#if ENABLE(GPU_PROCESS)
    m_page->settings().setBlockMediaLayerRehostingInWebContentProcess(m_blockMediaLayerRehostingInWebContentProcess);
#endif
    m_page->settings().setBroadcastChannelEnabled(m_broadcastChannelEnabled);
    m_page->settings().setCacheAPIEnabled(m_cacheAPIEnabled);
    m_page->settings().setCanvasColorSpaceEnabled(m_canvasColorSpaceEnabled);
    m_page->settings().setCanvasFiltersEnabled(m_canvasFiltersEnabled);
    m_page->settings().setCanvasFingerprintingQuirkEnabled(m_canvasFingerprintingQuirkEnabled);
    m_page->settings().setCanvasLayersEnabled(m_canvasLayersEnabled);
    m_page->settings().setCanvasPixelFormatEnabled(m_canvasPixelFormatEnabled);
#if USE(CA) || USE(SKIA)
    m_page->settings().setCanvasUsesAcceleratedDrawing(m_canvasUsesAcceleratedDrawing);
#endif
    m_page->settings().setCaretBrowsingEnabled(m_caretBrowsingEnabled);
    m_page->settings().setCaretPositionFromPointEnabled(m_caretPositionFromPointEnabled);
    m_page->settings().setChildProcessDebuggabilityEnabled(m_childProcessDebuggabilityEnabled);
    m_page->settings().setClearSiteDataExecutionContextsSupportEnabled(m_clearSiteDataExecutionContextsSupportEnabled);
    m_page->settings().setClearSiteDataHTTPHeaderEnabled(m_clearSiteDataHTTPHeaderEnabled);
    m_page->settings().setClientCoordinatesRelativeToLayoutViewport(m_clientCoordinatesRelativeToLayoutViewport);
    m_page->settings().setCloseWatcherEnabled(m_closeWatcherEnabled);
    m_page->settings().setColorFilterEnabled(m_colorFilterEnabled);
    m_page->settings().setCommandAttributesEnabled(m_commandAttributesEnabled);
    m_page->settings().setCompressionStreamEnabled(m_compressionStreamEnabled);
    m_page->settings().setContactPickerAPIEnabled(m_contactPickerAPIEnabled);
#if ENABLE(CONTENT_CHANGE_OBSERVER)
    m_page->settings().setContentChangeObserverEnabled(m_contentChangeObserverEnabled);
#endif
    m_page->settings().setContentDispositionAttachmentSandboxEnabled(m_contentDispositionAttachmentSandboxEnabled);
    m_page->settings().setContentInsetBackgroundFillEnabled(m_contentInsetBackgroundFillEnabled);
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
    m_page->settings().setContextMenuQRCodeDetectionEnabled(m_contextMenuQRCodeDetectionEnabled);
#endif
    m_page->settings().setCookieConsentAPIEnabled(m_cookieConsentAPIEnabled);
    m_page->settings().setCookieEnabled(m_cookieEnabled);
    m_page->settings().setCookieStoreAPIEnabled(m_cookieStoreAPIEnabled);
    m_page->settings().setCookieStoreAPIExtendedAttributesEnabled(m_cookieStoreAPIExtendedAttributesEnabled);
    m_page->settings().setCookieStoreManagerEnabled(m_cookieStoreManagerEnabled);
    m_page->settings().setCoreMathMLEnabled(m_coreMathMLEnabled);
    m_page->settings().setCrossDocumentViewTransitionsEnabled(m_crossDocumentViewTransitionsEnabled);
    m_page->settings().setCrossOriginCheckInGetMatchedCSSRulesDisabled(m_crossOriginCheckInGetMatchedCSSRulesDisabled);
    m_page->settings().setCrossOriginEmbedderPolicyEnabled(m_crossOriginEmbedderPolicyEnabled);
    m_page->settings().setCrossOriginOpenerPolicyEnabled(m_crossOriginOpenerPolicyEnabled);
    m_page->settings().setCSS3DTransformBackfaceVisibilityInteroperabilityEnabled(m_css3DTransformBackfaceVisibilityInteroperabilityEnabled);
    m_page->settings().setCSSAnchorPositioningEnabled(m_cssAnchorPositioningEnabled);
    m_page->settings().setCSSAnchorPositioningPositionVisibilityEnabled(m_cssAnchorPositioningPositionVisibilityEnabled);
    m_page->settings().setCSSAppearanceBaseEnabled(m_cssAppearanceBaseEnabled);
    m_page->settings().setCSSAxisRelativePositionKeywordsEnabled(m_cssAxisRelativePositionKeywordsEnabled);
    m_page->settings().setCSSBackgroundClipBorderAreaEnabled(m_cssBackgroundClipBorderAreaEnabled);
    m_page->settings().setCSSColorLayersEnabled(m_cssColorLayersEnabled);
    m_page->settings().setCSSConstrainedDynamicRangeLimitEnabled(m_cssConstrainedDynamicRangeLimitEnabled);
    m_page->settings().setCSSContrastColorEnabled(m_cssContrastColorEnabled);
    m_page->settings().setCSSCornerShapeEnabled(m_cssCornerShapeEnabled);
    m_page->settings().setCSSCounterStyleAtRuleImageSymbolsEnabled(m_cssCounterStyleAtRuleImageSymbolsEnabled);
    m_page->settings().setCSSDPropertyEnabled(m_cssDPropertyEnabled);
    m_page->settings().setCSSDynamicRangeLimitMixEnabled(m_cssDynamicRangeLimitMixEnabled);
    m_page->settings().setCSSFieldSizingEnabled(m_cssFieldSizingEnabled);
    m_page->settings().setCSSFontVariantEmojiEnabled(m_cssFontVariantEmojiEnabled);
    m_page->settings().setCSSInputSecurityEnabled(m_cssInputSecurityEnabled);
    m_page->settings().setCSSLineClampEnabled(m_cssLineClampEnabled);
    m_page->settings().setCSSLineFitEdgeEnabled(m_cssLineFitEdgeEnabled);
    m_page->settings().setCSSPaintingAPIEnabled(m_cssPaintingAPIEnabled);
    m_page->settings().setCSSProgressFunctionEnabled(m_cssProgressFunctionEnabled);
    m_page->settings().setCSSRandomFunctionEnabled(m_cssRandomFunctionEnabled);
    m_page->settings().setCSSRhythmicSizingEnabled(m_cssRhythmicSizingEnabled);
    m_page->settings().setCSSRubyAlignEnabled(m_cssRubyAlignEnabled);
    m_page->settings().setCSSRubyOverhangEnabled(m_cssRubyOverhangEnabled);
    m_page->settings().setCSSScrollAnchoringEnabled(m_cssScrollAnchoringEnabled);
    m_page->settings().setCSSScrollbarColorEnabled(m_cssScrollbarColorEnabled);
    m_page->settings().setCSSScrollbarGutterEnabled(m_cssScrollbarGutterEnabled);
    m_page->settings().setCSSScrollbarWidthEnabled(m_cssScrollbarWidthEnabled);
    m_page->settings().setCSSShapeFunctionEnabled(m_cssShapeFunctionEnabled);
    m_page->settings().setCSSTextAutospaceEnabled(m_cssTextAutospaceEnabled);
    m_page->settings().setCSSTextBoxTrimEnabled(m_cssTextBoxTrimEnabled);
    m_page->settings().setCSSTextGroupAlignEnabled(m_cssTextGroupAlignEnabled);
    m_page->settings().setCSSTextJustifyEnabled(m_cssTextJustifyEnabled);
    m_page->settings().setCSSTextSpacingTrimEnabled(m_cssTextSpacingTrimEnabled);
    m_page->settings().setCSSTextUnderlinePositionLeftRightEnabled(m_cssTextUnderlinePositionLeftRightEnabled);
    m_page->settings().setCSSTextWrapPrettyEnabled(m_cssTextWrapPrettyEnabled);
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
    m_page->settings().setCSSTransformStyleSeparatedEnabled(m_cssTransformStyleSeparatedEnabled);
#endif
    m_page->settings().setCSSTreeCountingFunctionsEnabled(m_cssTreeCountingFunctionsEnabled);
    m_page->settings().setCSSTypedOMColorEnabled(m_cssTypedOMColorEnabled);
    m_page->settings().setCSSURLIntegrityModifierEnabled(m_cssURLIntegrityModifierEnabled);
    m_page->settings().setCSSURLModifiersEnabled(m_cssURLModifiersEnabled);
    m_page->settings().setCSSUnprefixedBackdropFilterEnabled(m_cssUnprefixedBackdropFilterEnabled);
    m_page->settings().setCSSWordBreakAutoPhraseEnabled(m_cssWordBreakAutoPhraseEnabled);
    m_page->settings().setCursiveFontFamily(m_cursiveFontFamily);
    m_page->settings().setDataListElementEnabled(m_dataListElementEnabled);
    m_page->settings().setDataTransferItemsEnabled(m_dataTransferItemsEnabled);
    m_page->settings().setDateTimeInputsEditableComponentsEnabled(m_dateTimeInputsEditableComponentsEnabled);
#if ENABLE(DECLARATIVE_WEB_PUSH)
    m_page->settings().setDeclarativeWebPush(m_declarativeWebPush);
#endif
    m_page->settings().setDefaultFixedFontSize(m_defaultFixedFontSize);
    m_page->settings().setDefaultFontSize(m_defaultFontSize);
    m_page->settings().setDefaultTextEncodingName(m_defaultTextEncodingName);
    m_page->settings().setDefaultVideoPosterURL(m_defaultVideoPosterURL);
    m_page->settings().setDeprecationReportingEnabled(m_deprecationReportingEnabled);
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setDetachableMediaSourceEnabled(m_detachableMediaSourceEnabled);
#endif
    m_page->settings().setDetailsAutoExpandEnabled(m_detailsAutoExpandEnabled);
    m_page->settings().setDeveloperExtrasEnabled(m_developerExtrasEnabled);
    m_page->settings().setDeviceHeight(m_deviceHeight);
#if ENABLE(DEVICE_ORIENTATION)
    m_page->settings().setDeviceOrientationEventEnabled(m_deviceOrientationEventEnabled);
#endif
#if ENABLE(DEVICE_ORIENTATION)
    m_page->settings().setDeviceOrientationPermissionAPIEnabled(m_deviceOrientationPermissionAPIEnabled);
#endif
    m_page->settings().setDeviceWidth(m_deviceWidth);
    m_page->settings().setDevolvableWidgetsEnabled(m_devolvableWidgetsEnabled);
    m_page->settings().setDiagnosticLoggingEnabled(m_diagnosticLoggingEnabled);
#if ENABLE(WEB_AUTHN)
    m_page->settings().setDigitalCredentialsEnabled(m_digitalCredentialsEnabled);
#endif
    m_page->settings().setDirectoryUploadEnabled(m_directoryUploadEnabled);
    m_page->settings().setDisabledAdaptationsMetaTagEnabled(m_disabledAdaptationsMetaTagEnabled);
#if ENABLE(DOM_AUDIO_SESSION)
    m_page->settings().setDOMAudioSessionEnabled(m_domAudioSessionEnabled);
#endif
#if ENABLE(DOM_AUDIO_SESSION)
    m_page->settings().setDOMAudioSessionFullEnabled(m_domAudioSessionFullEnabled);
#endif
    m_page->settings().setDOMPasteAccessRequestsEnabled(m_domPasteAccessRequestsEnabled);
    m_page->settings().setDOMPasteAllowed(m_domPasteAllowed);
    m_page->settings().setDOMTestingAPIsEnabled(m_domTestingAPIsEnabled);
    m_page->settings().setDOMTimersThrottlingEnabled(m_domTimersThrottlingEnabled);
    m_page->settings().setDownloadAttributeEnabled(m_downloadAttributeEnabled);
    m_page->settings().setDynamicSiteInterventionsEnabled(m_dynamicSiteInterventionsEnabled);
    m_page->settings().setEmbedElementEnabled(m_embedElementEnabled);
    m_page->settings().setEnableElementCurrentCSSZoom(m_enableElementCurrentCSSZoom);
    m_page->settings().setEnableInheritURIQueryComponent(m_enableInheritURIQueryComponent);
#if ENABLE(ENCRYPTED_MEDIA)
    m_page->settings().setEncryptedMediaAPIEnabled(m_encryptedMediaAPIEnabled);
#endif
    m_page->settings().setEnterKeyHintEnabled(m_enterKeyHintEnabled);
    m_page->settings().setEventHandlerDrivenSmoothKeyboardScrollingEnabled(m_eventHandlerDrivenSmoothKeyboardScrollingEnabled);
    m_page->settings().setEventTimingEnabled(m_eventTimingEnabled);
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setExposeCaptureDevicesAfterCaptureEnabled(m_exposeCaptureDevicesAfterCaptureEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setExposeDefaultSpeakerAsSpecificDeviceEnabled(m_exposeDefaultSpeakerAsSpecificDeviceEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setExposeSpeakersEnabled(m_exposeSpeakersEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setExposeSpeakersWithoutMicrophoneEnabled(m_exposeSpeakersWithoutMicrophoneEnabled);
#endif
#if ENABLE(VIDEO)
    m_page->settings().setExtendedAudioDescriptionsEnabled(m_extendedAudioDescriptionsEnabled);
#endif
    m_page->settings().setFantasyFontFamily(m_fantasyFontFamily);
    m_page->settings().setFileReaderAPIEnabled(m_fileReaderAPIEnabled);
    m_page->settings().setFileSystemEnabled(m_fileSystemEnabled);
    m_page->settings().setFileSystemWritableStreamEnabled(m_fileSystemWritableStreamEnabled);
    m_page->settings().setFilterLinkDecorationByDefaultEnabled(m_filterLinkDecorationByDefaultEnabled);
    m_page->settings().setFixedBackgroundsPaintRelativeToDocument(m_fixedBackgroundsPaintRelativeToDocument);
    m_page->settings().setFixedElementsLayoutRelativeToFrame(m_fixedElementsLayoutRelativeToFrame);
    m_page->settings().setFixedFontFamily(m_fixedFontFamily);
    m_page->settings().setFlexFormattingContextIntegrationEnabled(m_flexFormattingContextIntegrationEnabled);
    m_page->settings().setFontFallbackPrefersPictographs(m_fontFallbackPrefersPictographs);
    m_page->settings().setForceCompositingMode(m_forceCompositingMode);
    m_page->settings().setForceFTPDirectoryListings(m_forceFTPDirectoryListings);
    m_page->settings().setForceLockdownFontParserEnabled(m_forceLockdownFontParserEnabled);
    m_page->settings().setForceWebGLUsesLowPower(m_forceWebGLUsesLowPower);
#if ENABLE(FORM_CONTROL_REFRESH)
    m_page->settings().setFormControlRefreshEnabled(m_formControlRefreshEnabled);
#endif
    m_page->settings().setFTPDirectoryTemplatePath(m_ftpDirectoryTemplatePath);
    m_page->settings().setFTPEnabled(m_ftpEnabled);
#if ENABLE(FULLSCREEN_API)
    m_page->settings().setFullScreenEnabled(m_fullScreenEnabled);
#endif
#if ENABLE(FULLSCREEN_API)
    m_page->settings().setFullScreenKeyboardLock(m_fullScreenKeyboardLock);
#endif
    m_page->settings().setFullscreenRequirementForScreenOrientationLockingEnabled(m_fullscreenRequirementForScreenOrientationLockingEnabled);
#if PLATFORM(VISION)
    m_page->settings().setFullscreenSceneAspectRatioLockingEnabled(m_fullscreenSceneAspectRatioLockingEnabled);
#endif
#if PLATFORM(VISION)
    m_page->settings().setFullscreenSceneDimmingEnabled(m_fullscreenSceneDimmingEnabled);
#endif
#if ENABLE(GAMEPAD)
    m_page->settings().setGamepadTriggerRumbleEnabled(m_gamepadTriggerRumbleEnabled);
#endif
#if ENABLE(GAMEPAD)
    m_page->settings().setGamepadVibrationActuatorEnabled(m_gamepadVibrationActuatorEnabled);
#endif
#if ENABLE(GAMEPAD)
    m_page->settings().setGamepadsEnabled(m_gamepadsEnabled);
#endif
#if ENABLE(VIDEO)
    m_page->settings().setGenericCueAPIEnabled(m_genericCueAPIEnabled);
#endif
    m_page->settings().setGeolocationAPIEnabled(m_geolocationAPIEnabled);
    m_page->settings().setGeolocationFloorLevelEnabled(m_geolocationFloorLevelEnabled);
    m_page->settings().setGetCoalescedEventsEnabled(m_getCoalescedEventsEnabled);
    m_page->settings().setGetPredictedEventsEnabled(m_getPredictedEventsEnabled);
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setGetUserMediaRequiresFocus(m_getUserMediaRequiresFocus);
#endif
    m_page->settings().setGoogleAntiFlickerOptimizationQuirkEnabled(m_googleAntiFlickerOptimizationQuirkEnabled);
#if USE(GRAPHICS_CONTEXT_FILTERS)
    m_page->settings().setGraphicsContextFiltersEnabled(m_graphicsContextFiltersEnabled);
#endif
    m_page->settings().setHiddenPageCSSAnimationSuspensionEnabled(m_hiddenPageCSSAnimationSuspensionEnabled);
    m_page->settings().setHiddenPageDOMTimerThrottlingAutoIncreases(m_hiddenPageDOMTimerThrottlingAutoIncreases);
    m_page->settings().setHiddenPageDOMTimerThrottlingEnabled(m_hiddenPageDOMTimerThrottlingEnabled);
    m_page->settings().setHiddenUntilFoundEnabled(m_hiddenUntilFoundEnabled);
#if HAVE(MATERIAL_HOSTING)
    m_page->settings().setHostedBlurMaterialInMediaControlsEnabled(m_hostedBlurMaterialInMediaControlsEnabled);
#endif
    m_page->settings().setHTMLLegacyAttributeValueSerializationEnabled(m_htmlLegacyAttributeValueSerializationEnabled);
    m_page->settings().setHttpEquivEnabled(m_httpEquivEnabled);
    m_page->settings().setHttpsByDefault(m_httpsByDefault);
#if ENABLE(CONTENT_EXTENSIONS)
    m_page->settings().setIFrameResourceMonitoringEnabled(m_iFrameResourceMonitoringEnabled);
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    m_page->settings().setIFrameResourceMonitoringTestingSettingsEnabled(m_iFrameResourceMonitoringTestingSettingsEnabled);
#endif
    m_page->settings().setIOSurfaceLosslessCompressionEnabled(m_iOSurfaceLosslessCompressionEnabled);
    m_page->settings().setIPAddressAndLocalhostMixedContentUpgradeTestingEnabled(m_iPAddressAndLocalhostMixedContentUpgradeTestingEnabled);
    m_page->settings().setICECandidateFilteringEnabled(m_iceCandidateFilteringEnabled);
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setIdempotentModeAutosizingOnlyHonorsPercentages(m_idempotentModeAutosizingOnlyHonorsPercentages);
#endif
    m_page->settings().setIgnoreIframeEmbeddingProtectionsEnabled(m_ignoreIframeEmbeddingProtectionsEnabled);
#if ENABLE(IMAGE_ANALYSIS)
    m_page->settings().setImageAnalysisDuringFindInPageEnabled(m_imageAnalysisDuringFindInPageEnabled);
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    m_page->settings().setImageAnimationControlEnabled(m_imageAnimationControlEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setImageCaptureEnabled(m_imageCaptureEnabled);
#endif
#if ENABLE(SERVICE_CONTROLS)
    m_page->settings().setImageControlsEnabled(m_imageControlsEnabled);
#endif
    m_page->settings().setImageSubsamplingEnabled(m_imageSubsamplingEnabled);
    m_page->settings().setImagesEnabled(m_imagesEnabled);
    m_page->settings().setInWindowFullscreenEnabled(m_inWindowFullscreenEnabled);
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
    m_page->settings().setIncludeIgnoredInCoreAXTree(m_includeIgnoredInCoreAXTree);
#endif
    m_page->settings().setIncompleteImageBorderEnabled(m_incompleteImageBorderEnabled);
#if HAVE(INCREMENTAL_PDF_APIS)
    m_page->settings().setIncrementalPDFLoadingEnabled(m_incrementalPDFLoadingEnabled);
#endif
    m_page->settings().setIncrementalRenderingSuppressionTimeoutInSeconds(m_incrementalRenderingSuppressionTimeoutInSeconds);
    m_page->settings().setIndexedDBAPIEnabled(m_indexedDBAPIEnabled);
    m_page->settings().setInlineMediaPlaybackRequiresPlaysInlineAttribute(m_inlineMediaPlaybackRequiresPlaysInlineAttribute);
#if PLATFORM(MAC)
    m_page->settings().setInputMethodUsesCorrectKeyEventOrder(m_inputMethodUsesCorrectKeyEventOrder);
#endif
    m_page->settings().setInputTypeColorEnabled(m_inputTypeColorEnabled);
    m_page->settings().setInputTypeColorEnhancementsEnabled(m_inputTypeColorEnhancementsEnabled);
    m_page->settings().setInputTypeDateEnabled(m_inputTypeDateEnabled);
    m_page->settings().setInputTypeDateTimeLocalEnabled(m_inputTypeDateTimeLocalEnabled);
    m_page->settings().setInputTypeMonthEnabled(m_inputTypeMonthEnabled);
    m_page->settings().setInputTypeTimeEnabled(m_inputTypeTimeEnabled);
    m_page->settings().setInputTypeWeekEnabled(m_inputTypeWeekEnabled);
    m_page->settings().setInspectorMaximumResourcesContentSize(m_inspectorMaximumResourcesContentSize);
    m_page->settings().setInspectorSupportsShowingCertificate(m_inspectorSupportsShowingCertificate);
    m_page->settings().setInteractionRegionInlinePadding(m_interactionRegionInlinePadding);
    m_page->settings().setInteractionRegionMinimumCornerRadius(m_interactionRegionMinimumCornerRadius);
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    m_page->settings().setInteractionRegionsEnabled(m_interactionRegionsEnabled);
#endif
    m_page->settings().setInteractiveFormValidationEnabled(m_interactiveFormValidationEnabled);
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setInterruptAudioOnPageVisibilityChangeEnabled(m_interruptAudioOnPageVisibilityChangeEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setInterruptVideoOnPageVisibilityChangeEnabled(m_interruptVideoOnPageVisibilityChangeEnabled);
#endif
    m_page->settings().setInvisibleAutoplayNotPermitted(m_invisibleAutoplayNotPermitted);
    m_page->settings().setIsFirstPartyWebsiteDataRemovalDisabled(m_isFirstPartyWebsiteDataRemovalDisabled);
    m_page->settings().setIsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled(m_isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled);
    m_page->settings().setIsFirstPartyWebsiteDataRemovalReproTestingEnabled(m_isFirstPartyWebsiteDataRemovalReproTestingEnabled);
    m_page->settings().setIsPerActivityStateCPUUsageMeasurementEnabled(m_isPerActivityStateCPUUsageMeasurementEnabled);
    m_page->settings().setIsPostBackgroundingCPUUsageMeasurementEnabled(m_isPostBackgroundingCPUUsageMeasurementEnabled);
    m_page->settings().setIsPostBackgroundingMemoryUsageMeasurementEnabled(m_isPostBackgroundingMemoryUsageMeasurementEnabled);
    m_page->settings().setIsPostLoadCPUUsageMeasurementEnabled(m_isPostLoadCPUUsageMeasurementEnabled);
    m_page->settings().setIsPostLoadMemoryUsageMeasurementEnabled(m_isPostLoadMemoryUsageMeasurementEnabled);
    m_page->settings().setIsSameSiteStrictEnforcementEnabled(m_isSameSiteStrictEnforcementEnabled);
    m_page->settings().setIsThirdPartyCookieBlockingDisabled(m_isThirdPartyCookieBlockingDisabled);
    m_page->settings().setItpDebugModeEnabled(m_itpDebugModeEnabled);
    m_page->settings().setJavaScriptCanAccessClipboard(m_javaScriptCanAccessClipboard);
    m_page->settings().setJavaScriptCanOpenWindowsAutomatically(m_javaScriptCanOpenWindowsAutomatically);
    m_page->settings().setLangAttributeAwareFormControlUIEnabled(m_langAttributeAwareFormControlUIEnabled);
    m_page->settings().setLargeImageAsyncDecodingEnabled(m_largeImageAsyncDecodingEnabled);
    m_page->settings().setLayerBasedSVGEngineEnabled(m_layerBasedSVGEngineEnabled);
    m_page->settings().setLayoutFallbackWidth(m_layoutFallbackWidth);
    m_page->settings().setLayoutViewportHeightExpansionFactor(m_layoutViewportHeightExpansionFactor);
    m_page->settings().setLazyIframeLoadingEnabled(m_lazyIframeLoadingEnabled);
    m_page->settings().setLazyImageLoadingEnabled(m_lazyImageLoadingEnabled);
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    m_page->settings().setLegacyEncryptedMediaAPIEnabled(m_legacyEncryptedMediaAPIEnabled);
#endif
    m_page->settings().setLegacyLineLayoutVisualCoverageEnabled(m_legacyLineLayoutVisualCoverageEnabled);
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
    m_page->settings().setLegacyOverflowScrollingTouchEnabled(m_legacyOverflowScrollingTouchEnabled);
#endif
    m_page->settings().setLegacyPluginQuirkForMailSignaturesEnabled(m_legacyPluginQuirkForMailSignaturesEnabled);
#if ENABLE(WEB_RTC)
    m_page->settings().setLegacyWebRTCOfferOptionsEnabled(m_legacyWebRTCOfferOptionsEnabled);
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    m_page->settings().setLimitedMatroskaSupportEnabled(m_limitedMatroskaSupportEnabled);
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
    m_page->settings().setLinearMediaPlayerEnabled(m_linearMediaPlayerEnabled);
#endif
    m_page->settings().setLinkDNSPrefetchEnabled(m_linkDNSPrefetchEnabled);
    m_page->settings().setLinkPreconnectEarlyHintsEnabled(m_linkPreconnectEarlyHintsEnabled);
    m_page->settings().setLinkPreconnectEnabled(m_linkPreconnectEnabled);
    m_page->settings().setLinkPrefetchEnabled(m_linkPrefetchEnabled);
    m_page->settings().setLinkPreloadEnabled(m_linkPreloadEnabled);
    m_page->settings().setLinkSanitizerEnabled(m_linkSanitizerEnabled);
    m_page->settings().setLoadDeferringEnabled(m_loadDeferringEnabled);
#if ENABLE(WEB_ARCHIVE)
    m_page->settings().setLoadWebArchiveWithEphemeralStorageEnabled(m_loadWebArchiveWithEphemeralStorageEnabled);
#endif
    m_page->settings().setLoadsImagesAutomatically(m_loadsImagesAutomatically);
    m_page->settings().setLocalFileContentSniffingEnabled(m_localFileContentSniffingEnabled);
    m_page->settings().setLocalNetworkAccessEnabled(m_localNetworkAccessEnabled);
    m_page->settings().setLocalStorageDatabasePath(m_localStorageDatabasePath);
    m_page->settings().setLocalStorageEnabled(m_localStorageEnabled);
    m_page->settings().setLockdownFontParserEnabled(m_lockdownFontParserEnabled);
    m_page->settings().setLoginStatusAPIEnabled(m_loginStatusAPIEnabled);
    m_page->settings().setLoginStatusAPIRequiresWebAuthnEnabled(m_loginStatusAPIRequiresWebAuthnEnabled);
    m_page->settings().setLogsPageMessagesToSystemConsoleEnabled(m_logsPageMessagesToSystemConsoleEnabled);
    m_page->settings().setMainContentUserGestureOverrideEnabled(m_mainContentUserGestureOverrideEnabled);
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
    m_page->settings().setManageCaptureStatusBarInGPUProcessEnabled(m_manageCaptureStatusBarInGPUProcessEnabled);
#endif
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setManagedMediaSourceEnabled(m_managedMediaSourceEnabled);
#endif
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setManagedMediaSourceHighThreshold(m_managedMediaSourceHighThreshold);
#endif
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setManagedMediaSourceLowThreshold(m_managedMediaSourceLowThreshold);
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
    m_page->settings().setManagedMediaSourceNeedsAirPlay(m_managedMediaSourceNeedsAirPlay);
#endif
    m_page->settings().setMasonryEnabled(m_masonryEnabled);
#if ENABLE(MATHML)
    m_page->settings().setMathMLEnabled(m_mathMLEnabled);
#endif
    m_page->settings().setMaxParseDuration(m_maxParseDuration);
    m_page->settings().setMaximumHTMLParserDOMTreeDepth(m_maximumHTMLParserDOMTreeDepth);
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setMaximumSourceBufferSize(m_maximumSourceBufferSize);
#endif
    m_page->settings().setMediaCapabilitiesEnabled(m_mediaCapabilitiesEnabled);
    m_page->settings().setMediaCapabilitiesExtensionsEnabled(m_mediaCapabilitiesExtensionsEnabled);
#if ENABLE(EXTENSION_CAPABILITIES)
    m_page->settings().setMediaCapabilityGrantsEnabled(m_mediaCapabilityGrantsEnabled);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMediaCaptureRequiresSecureConnection(m_mediaCaptureRequiresSecureConnection);
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
    m_page->settings().setMediaControlsContextMenusEnabled(m_mediaControlsContextMenusEnabled);
#endif
    m_page->settings().setMediaControlsScaleWithPageZoom(m_mediaControlsScaleWithPageZoom);
    m_page->settings().setMediaDataLoadsAutomatically(m_mediaDataLoadsAutomatically);
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMediaDevicesEnabled(m_mediaDevicesEnabled);
#endif
#if ENABLE(VIDEO)
    m_page->settings().setMediaEnabled(m_mediaEnabled);
#endif
    m_page->settings().setMediaKeysStorageDirectory(m_mediaKeysStorageDirectory);
    m_page->settings().setMediaPlaybackEnabled(m_mediaPlaybackEnabled);
    m_page->settings().setMediaPreferredFullscreenWidth(m_mediaPreferredFullscreenWidth);
    m_page->settings().setMediaPreloadingEnabled(m_mediaPreloadingEnabled);
#if ENABLE(MEDIA_RECORDER)
    m_page->settings().setMediaRecorderEnabled(m_mediaRecorderEnabled);
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    m_page->settings().setMediaRecorderEnabledWebM(m_mediaRecorderEnabledWebM);
#endif
    m_page->settings().setMediaSessionCaptureToggleAPIEnabled(m_mediaSessionCaptureToggleAPIEnabled);
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    m_page->settings().setMediaSessionCoordinatorEnabled(m_mediaSessionCoordinatorEnabled);
#endif
#if ENABLE(MEDIA_SESSION)
    m_page->settings().setMediaSessionEnabled(m_mediaSessionEnabled);
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
    m_page->settings().setMediaSessionPlaylistEnabled(m_mediaSessionPlaylistEnabled);
#endif
    m_page->settings().setMediaSourceEnabled(m_mediaSourceEnabled);
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
    m_page->settings().setMediaSourceInWorkerEnabled(m_mediaSourceInWorkerEnabled);
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
    m_page->settings().setMediaSourcePrefersDecompressionSession(m_mediaSourcePrefersDecompressionSession);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMediaStreamTrackProcessingEnabled(m_mediaStreamTrackProcessingEnabled);
#endif
    m_page->settings().setMediaTypeOverride(m_mediaTypeOverride);
    m_page->settings().setMediaUserGestureInheritsFromDocument(m_mediaUserGestureInheritsFromDocument);
    m_page->settings().setMetaViewportInteractiveWidgetEnabled(m_metaViewportInteractiveWidgetEnabled);
    m_page->settings().setMinimumFontSize(m_minimumFontSize);
    m_page->settings().setMinimumLogicalFontSize(m_minimumLogicalFontSize);
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setMinimumZoomFontSize(m_minimumZoomFontSize);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMockCaptureDevicesEnabled(m_mockCaptureDevicesEnabled);
#endif
    m_page->settings().setMockScrollbarsControllerEnabled(m_mockScrollbarsControllerEnabled);
#if ENABLE(MODEL_ELEMENT)
    m_page->settings().setModelElementEnabled(m_modelElementEnabled);
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    m_page->settings().setModelNoPortalAttributeEnabled(m_modelNoPortalAttributeEnabled);
#endif
#if ENABLE(MODEL_PROCESS)
    m_page->settings().setModelProcessEnabled(m_modelProcessEnabled);
#endif
    m_page->settings().setMomentumScrollingAnimatorEnabled(m_momentumScrollingAnimatorEnabled);
#if ENABLE(TOUCH_EVENTS)
    m_page->settings().setMouseEventsSimulationEnabled(m_mouseEventsSimulationEnabled);
#endif
    m_page->settings().setMutationEventsEnabled(m_mutationEventsEnabled);
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMuteCameraOnMicrophoneInterruptionEnabled(m_muteCameraOnMicrophoneInterruptionEnabled);
#endif
    m_page->settings().setNavigationAPIEnabled(m_navigationAPIEnabled);
    m_page->settings().setNavigatorUserAgentDataJavaScriptAPIEnabled(m_navigatorUserAgentDataJavaScriptAPIEnabled);
    m_page->settings().setNeedsAdobeFrameReloadingQuirk(m_needsAdobeFrameReloadingQuirk);
    m_page->settings().setNeedsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk(m_needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk);
    m_page->settings().setNeedsFrameNameFallbackToIdQuirk(m_needsFrameNameFallbackToIdQuirk);
    m_page->settings().setNeedsKeyboardEventDisambiguationQuirks(m_needsKeyboardEventDisambiguationQuirks);
    m_page->settings().setNeedsSiteSpecificQuirks(m_needsSiteSpecificQuirks);
    m_page->settings().setNeedsStorageAccessFromFileURLsQuirk(m_needsStorageAccessFromFileURLsQuirk);
#if ENABLE(NOTIFICATION_EVENT)
    m_page->settings().setNotificationEventEnabled(m_notificationEventEnabled);
#endif
#if ENABLE(NOTIFICATIONS)
    m_page->settings().setNotificationsEnabled(m_notificationsEnabled);
#endif
    m_page->settings().setObservableEnabled(m_observableEnabled);
#if ENABLE(OFFSCREEN_CANVAS)
    m_page->settings().setOffscreenCanvasEnabled(m_offscreenCanvasEnabled);
#endif
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
    m_page->settings().setOffscreenCanvasInWorkersEnabled(m_offscreenCanvasInWorkersEnabled);
#endif
    m_page->settings().setOpportunisticSweepingAndGarbageCollectionEnabled(m_opportunisticSweepingAndGarbageCollectionEnabled);
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
    m_page->settings().setOptInPartitionedCookiesEnabled(m_optInPartitionedCookiesEnabled);
#endif
    m_page->settings().setOverlappingBackingStoreProvidersEnabled(m_overlappingBackingStoreProvidersEnabled);
    m_page->settings().setOverscrollBehaviorEnabled(m_overscrollBehaviorEnabled);
    m_page->settings().setPageAtRuleMarginDescriptorsEnabled(m_pageAtRuleMarginDescriptorsEnabled);
    m_page->settings().setPassiveTouchListenersAsDefaultOnDocument(m_passiveTouchListenersAsDefaultOnDocument);
    m_page->settings().setPassiveWheelListenersAsDefaultOnDocument(m_passiveWheelListenersAsDefaultOnDocument);
    m_page->settings().setPasswordEchoDurationInSeconds(m_passwordEchoDurationInSeconds);
    m_page->settings().setPasswordEchoEnabled(m_passwordEchoEnabled);
#if ENABLE(PAYMENT_REQUEST)
    m_page->settings().setPaymentRequestEnabled(m_paymentRequestEnabled);
#endif
#if ENABLE(PDFJS)
    m_page->settings().setPDFJSViewerEnabled(m_pdfJSViewerEnabled);
#endif
#if PLATFORM(COCOA)
    m_page->settings().setPDFPluginEnabled(m_pdfPluginEnabled);
#endif
#if PLATFORM(COCOA)
    m_page->settings().setPDFPluginHUDEnabled(m_pdfPluginHUDEnabled);
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    m_page->settings().setPDFPluginPageNumberIndicatorEnabled(m_pdfPluginPageNumberIndicatorEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setPeerConnectionEnabled(m_peerConnectionEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setPeerConnectionVideoScalingAdaptationDisabled(m_peerConnectionVideoScalingAdaptationDisabled);
#endif
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setPerElementSpeakerSelectionEnabled(m_perElementSpeakerSelectionEnabled);
#endif
    m_page->settings().setPermissionsAPIEnabled(m_permissionsAPIEnabled);
    m_page->settings().setPictographFontFamily(m_pictographFontFamily);
#if ENABLE(PICTURE_IN_PICTURE_API)
    m_page->settings().setPictureInPictureAPIEnabled(m_pictureInPictureAPIEnabled);
#endif
#if HAVE(PIP_SKIP_PREROLL)
    m_page->settings().setPictureInPicturePlaybackStateEnabled(m_pictureInPicturePlaybackStateEnabled);
#endif
#if ENABLE(POINTER_LOCK)
    m_page->settings().setPointerLockEnabled(m_pointerLockEnabled);
#endif
#if ENABLE(POINTER_LOCK)
    m_page->settings().setPointerLockOptionsEnabled(m_pointerLockOptionsEnabled);
#endif
    m_page->settings().setPopoverAttributeEnabled(m_popoverAttributeEnabled);
    m_page->settings().setPreferMIMETypeForImages(m_preferMIMETypeForImages);
    m_page->settings().setPreferPageRenderingUpdatesNear60FPSEnabled(m_preferPageRenderingUpdatesNear60FPSEnabled);
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    m_page->settings().setPreferSpatialAudioExperience(m_preferSpatialAudioExperience);
#endif
    m_page->settings().setPreventKeyboardDOMEventDispatch(m_preventKeyboardDOMEventDispatch);
    m_page->settings().setPrivateClickMeasurementDebugModeEnabled(m_privateClickMeasurementDebugModeEnabled);
    m_page->settings().setPrivateClickMeasurementEnabled(m_privateClickMeasurementEnabled);
    m_page->settings().setPrivateClickMeasurementFraudPreventionEnabled(m_privateClickMeasurementFraudPreventionEnabled);
    m_page->settings().setPrivateTokenUsageByThirdPartyEnabled(m_privateTokenUsageByThirdPartyEnabled);
#if ENABLE(DAMAGE_TRACKING)
    m_page->settings().setPropagateDamagingInformation(m_propagateDamagingInformation);
#endif
    m_page->settings().setPunchOutWhiteBackgroundsInDarkMode(m_punchOutWhiteBackgroundsInDarkMode);
    m_page->settings().setPushAPIEnabled(m_pushAPIEnabled);
    m_page->settings().setRemoteMediaSessionManagerEnabled(m_remoteMediaSessionManagerEnabled);
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    m_page->settings().setRemotePlaybackEnabled(m_remotePlaybackEnabled);
#endif
    m_page->settings().setRemoteSnapshottingEnabled(m_remoteSnapshottingEnabled);
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    m_page->settings().setRemoveBackgroundEnabled(m_removeBackgroundEnabled);
#endif
    m_page->settings().setRequestIdleCallbackEnabled(m_requestIdleCallbackEnabled);
    m_page->settings().setRequestStorageAccessThrowsExceptionUntilReload(m_requestStorageAccessThrowsExceptionUntilReload);
    m_page->settings().setRequestVideoFrameCallbackEnabled(m_requestVideoFrameCallbackEnabled);
#if HAVE(SC_CONTENT_SHARING_PICKER)
    m_page->settings().setRequireUAGetDisplayMediaPrompt(m_requireUAGetDisplayMediaPrompt);
#endif
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
    m_page->settings().setRequiresPageVisibilityForVideoToBeNowPlaying(m_requiresPageVisibilityForVideoToBeNowPlaying);
#endif
    m_page->settings().setRequiresPageVisibilityToPlayAudio(m_requiresPageVisibilityToPlayAudio);
    m_page->settings().setRequiresUserGestureForAudioPlayback(m_requiresUserGestureForAudioPlayback);
    m_page->settings().setRequiresUserGestureForVideoPlayback(m_requiresUserGestureForVideoPlayback);
    m_page->settings().setRequiresUserGestureToLoadVideo(m_requiresUserGestureToLoadVideo);
    m_page->settings().setResourceLoadSchedulingEnabled(m_resourceLoadSchedulingEnabled);
#if ENABLE(RESOURCE_USAGE)
    m_page->settings().setResourceUsageOverlayVisible(m_resourceUsageOverlayVisible);
#endif
    m_page->settings().setRespondToThermalPressureAggressively(m_respondToThermalPressureAggressively);
#if HAVE(RUBBER_BANDING)
    m_page->settings().setRubberBandingForSubScrollableRegionsEnabled(m_rubberBandingForSubScrollableRegionsEnabled);
#endif
    m_page->settings().setSKAttributionEnabled(m_sKAttributionEnabled);
    m_page->settings().setSampledPageTopColorMaxDifference(m_sampledPageTopColorMaxDifference);
    m_page->settings().setSampledPageTopColorMinHeight(m_sampledPageTopColorMinHeight);
    m_page->settings().setSansSerifFontFamily(m_sansSerifFontFamily);
    m_page->settings().setScopedCustomElementRegistryEnabled(m_scopedCustomElementRegistryEnabled);
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setScreenCaptureEnabled(m_screenCaptureEnabled);
#endif
    m_page->settings().setScreenOrientationAPIEnabled(m_screenOrientationAPIEnabled);
    m_page->settings().setScreenOrientationLockingAPIEnabled(m_screenOrientationLockingAPIEnabled);
#if ENABLE(SCREEN_TIME)
    m_page->settings().setScreenTimeEnabled(m_screenTimeEnabled);
#endif
    m_page->settings().setScreenWakeLockAPIEnabled(m_screenWakeLockAPIEnabled);
    m_page->settings().setScriptEnabled(m_scriptEnabled);
    m_page->settings().setScriptMarkupEnabled(m_scriptMarkupEnabled);
    m_page->settings().setScriptTrackingPrivacyLoggingEnabled(m_scriptTrackingPrivacyLoggingEnabled);
    m_page->settings().setScrollAnimatorEnabled(m_scrollAnimatorEnabled);
    m_page->settings().setScrollDrivenAnimationsEnabled(m_scrollDrivenAnimationsEnabled);
    m_page->settings().setScrollToTextFragmentEnabled(m_scrollToTextFragmentEnabled);
    m_page->settings().setScrollToTextFragmentFeatureDetectionEnabled(m_scrollToTextFragmentFeatureDetectionEnabled);
    m_page->settings().setScrollToTextFragmentGenerationEnabled(m_scrollToTextFragmentGenerationEnabled);
    m_page->settings().setScrollToTextFragmentIndicatorEnabled(m_scrollToTextFragmentIndicatorEnabled);
    m_page->settings().setScrollToTextFragmentMarkingEnabled(m_scrollToTextFragmentMarkingEnabled);
    m_page->settings().setScrollendEventEnabled(m_scrollendEventEnabled);
    m_page->settings().setScrollingCoordinatorEnabled(m_scrollingCoordinatorEnabled);
    m_page->settings().setScrollingPerformanceTestingEnabled(m_scrollingPerformanceTestingEnabled);
    m_page->settings().setScrollingTreeIncludesFrames(m_scrollingTreeIncludesFrames);
    m_page->settings().setSecureContextChecksEnabled(m_secureContextChecksEnabled);
    m_page->settings().setSelectShowPickerEnabled(m_selectShowPickerEnabled);
    m_page->settings().setSelectTrailingWhitespaceEnabled(m_selectTrailingWhitespaceEnabled);
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setSelectionHonorsOverflowScrolling(m_selectionHonorsOverflowScrolling);
#endif
    m_page->settings().setSerifFontFamily(m_serifFontFamily);
#if ENABLE(SERVICE_CONTROLS)
    m_page->settings().setServiceControlsEnabled(m_serviceControlsEnabled);
#endif
    m_page->settings().setServiceWorkerInstallEventEnabled(m_serviceWorkerInstallEventEnabled);
    m_page->settings().setServiceWorkerNavigationPreloadEnabled(m_serviceWorkerNavigationPreloadEnabled);
    m_page->settings().setServiceWorkersEnabled(m_serviceWorkersEnabled);
    m_page->settings().setServiceWorkersUserGestureEnabled(m_serviceWorkersUserGestureEnabled);
    m_page->settings().setSessionStorageQuota(m_sessionStorageQuota);
    m_page->settings().setShadowRootReferenceTargetEnabled(m_shadowRootReferenceTargetEnabled);
    m_page->settings().setShadowRootReferenceTargetEnabledForAriaOwns(m_shadowRootReferenceTargetEnabledForAriaOwns);
    m_page->settings().setShapeDetection(m_shapeDetection);
    m_page->settings().setSharedWorkerEnabled(m_sharedWorkerEnabled);
    m_page->settings().setShouldAllowUserInstalledFonts(m_shouldAllowUserInstalledFonts);
    m_page->settings().setShouldConvertInvalidURLsToBlank(m_shouldConvertInvalidURLsToBlank);
    m_page->settings().setShouldConvertPositionStyleOnCopy(m_shouldConvertPositionStyleOnCopy);
    m_page->settings().setShouldDecidePolicyBeforeLoadingQuickLookPreview(m_shouldDecidePolicyBeforeLoadingQuickLookPreview);
    m_page->settings().setShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint(m_shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint);
    m_page->settings().setShouldDispatchSyntheticMouseEventsWhenModifyingSelection(m_shouldDispatchSyntheticMouseEventsWhenModifyingSelection);
    m_page->settings().setShouldDispatchSyntheticMouseOutAfterSyntheticClick(m_shouldDispatchSyntheticMouseOutAfterSyntheticClick);
#if ENABLE(VIDEO)
    m_page->settings().setShouldDisplayCaptions(m_shouldDisplayCaptions);
#endif
#if ENABLE(VIDEO)
    m_page->settings().setShouldDisplaySubtitles(m_shouldDisplaySubtitles);
#endif
#if ENABLE(VIDEO)
    m_page->settings().setShouldDisplayTextDescriptions(m_shouldDisplayTextDescriptions);
#endif
    m_page->settings().setShouldDropNearSuspendedAssertionAfterDelay(m_shouldDropNearSuspendedAssertionAfterDelay);
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setShouldEnableTextAutosizingBoost(m_shouldEnableTextAutosizingBoost);
#endif
    m_page->settings().setShouldIgnoreFontLoadCompletions(m_shouldIgnoreFontLoadCompletions);
    m_page->settings().setShouldIgnoreMetaViewport(m_shouldIgnoreMetaViewport);
    m_page->settings().setShouldInjectUserScriptsInInitialEmptyDocument(m_shouldInjectUserScriptsInInitialEmptyDocument);
    m_page->settings().setShouldPrintBackgrounds(m_shouldPrintBackgrounds);
    m_page->settings().setShouldRespectImageOrientation(m_shouldRespectImageOrientation);
    m_page->settings().setShouldRestrictBaseURLSchemes(m_shouldRestrictBaseURLSchemes);
    m_page->settings().setShouldSuppressTextInputFromEditingDuringProvisionalNavigation(m_shouldSuppressTextInputFromEditingDuringProvisionalNavigation);
    m_page->settings().setShouldTakeNearSuspendedAssertions(m_shouldTakeNearSuspendedAssertions);
#if USE(MODERN_AVCONTENTKEYSESSION)
    m_page->settings().setShouldUseModernAVContentKeySession(m_shouldUseModernAVContentKeySession);
#endif
    m_page->settings().setShouldUseServiceWorkerShortTimeout(m_shouldUseServiceWorkerShortTimeout);
    m_page->settings().setShowDebugBorders(m_showDebugBorders);
    m_page->settings().setShowFrameProcessBorders(m_showFrameProcessBorders);
    m_page->settings().setShowMediaStatsContextMenuItemEnabled(m_showMediaStatsContextMenuItemEnabled);
    m_page->settings().setShowModalDialogEnabled(m_showModalDialogEnabled);
    m_page->settings().setShowRepaintCounter(m_showRepaintCounter);
    m_page->settings().setShowTiledScrollingIndicator(m_showTiledScrollingIndicator);
    m_page->settings().setShowsToolTipOverTruncatedText(m_showsToolTipOverTruncatedText);
    m_page->settings().setShowsURLsInToolTips(m_showsURLsInToolTips);
    m_page->settings().setShrinksStandaloneImagesToFit(m_shrinksStandaloneImagesToFit);
    m_page->settings().setSidewaysWritingModesEnabled(m_sidewaysWritingModesEnabled);
    m_page->settings().setSiteIsolationEnabled(m_siteIsolationEnabled);
    m_page->settings().setSiteIsolationSharedProcessEnabled(m_siteIsolationSharedProcessEnabled);
    m_page->settings().setSmartInsertDeleteEnabled(m_smartInsertDeleteEnabled);
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setSourceBufferChangeTypeEnabled(m_sourceBufferChangeTypeEnabled);
#endif
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
    m_page->settings().setSpatialImageControlsEnabled(m_spatialImageControlsEnabled);
#endif
    m_page->settings().setSpatialNavigationEnabled(m_spatialNavigationEnabled);
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setSpeakerSelectionRequiresUserGesture(m_speakerSelectionRequiresUserGesture);
#endif
    m_page->settings().setSpeechRecognitionEnabled(m_speechRecognitionEnabled);
    m_page->settings().setSpeechSynthesisAPIEnabled(m_speechSynthesisAPIEnabled);
    m_page->settings().setSpringTimingFunctionEnabled(m_springTimingFunctionEnabled);
    m_page->settings().setStandalone(m_standalone);
    m_page->settings().setStandardFontFamily(m_standardFontFamily);
    m_page->settings().setStorageAPIEnabled(m_storageAPIEnabled);
    m_page->settings().setStorageAPIEstimateEnabled(m_storageAPIEstimateEnabled);
    m_page->settings().setStorageAccessAPIPerPageScopeEnabled(m_storageAccessAPIPerPageScopeEnabled);
    m_page->settings().setSupportHDRCompositorTonemappingEnabled(m_supportHDRCompositorTonemappingEnabled);
    m_page->settings().setSupportHDRDisplayEnabled(m_supportHDRDisplayEnabled);
    m_page->settings().setSuppressHDRShouldBeAllowedInFullscreenVideo(m_suppressHDRShouldBeAllowedInFullscreenVideo);
    m_page->settings().setSuppressesIncrementalRendering(m_suppressesIncrementalRendering);
    m_page->settings().setSwitchControlEnabled(m_switchControlEnabled);
#if USE(SYSTEM_PREVIEW)
    m_page->settings().setSystemPreviewEnabled(m_systemPreviewEnabled);
#endif
    m_page->settings().setTargetTextPseudoElementEnabled(m_targetTextPseudoElementEnabled);
    m_page->settings().setTelephoneNumberParsingEnabled(m_telephoneNumberParsingEnabled);
    m_page->settings().setTemporaryTileCohortRetentionEnabled(m_temporaryTileCohortRetentionEnabled);
#if ENABLE(WRITING_TOOLS)
    m_page->settings().setTextAnimationsEnabled(m_textAnimationsEnabled);
#endif
    m_page->settings().setTextAreasAreResizable(m_textAreasAreResizable);
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingEnabled(m_textAutosizingEnabled);
#endif
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingEnabledAtLargeInitialScale(m_textAutosizingEnabledAtLargeInitialScale);
#endif
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingUsesIdempotentMode(m_textAutosizingUsesIdempotentMode);
#endif
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingWindowSizeOverrideHeight(m_textAutosizingWindowSizeOverrideHeight);
#endif
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingWindowSizeOverrideWidth(m_textAutosizingWindowSizeOverrideWidth);
#endif
    m_page->settings().setTextInteractionEnabled(m_textInteractionEnabled);
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    m_page->settings().setTextRecognitionInVideosEnabled(m_textRecognitionInVideosEnabled);
#endif
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setTextTracksInMSEEnabled(m_textTracksInMSEEnabled);
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
    m_page->settings().setThreadedAnimationResolutionEnabled(m_threadedAnimationResolutionEnabled);
#endif
    m_page->settings().setThumbAndTrackPseudoElementsEnabled(m_thumbAndTrackPseudoElementsEnabled);
    m_page->settings().setTopContentInsetBackgroundCanChangeAfterScrolling(m_topContentInsetBackgroundCanChangeAfterScrolling);
#if ENABLE(TOUCH_EVENTS)
    m_page->settings().setTouchEventDOMAttributesEnabled(m_touchEventDOMAttributesEnabled);
#endif
#if ENABLE(TOUCH_EVENTS)
    m_page->settings().setTouchEventEmulationEnabled(m_touchEventEmulationEnabled);
#endif
#if ENABLE(WEBXR)
    m_page->settings().setTouchInputCompatibilityEnabled(m_touchInputCompatibilityEnabled);
#endif
    m_page->settings().setTrackConfigurationEnabled(m_trackConfigurationEnabled);
    m_page->settings().setTreatIPAddressAsDomain(m_treatIPAddressAsDomain);
    m_page->settings().setTreatsAnyTextCSSLinkAsStylesheet(m_treatsAnyTextCSSLinkAsStylesheet);
    m_page->settings().setTrustedTypesEnabled(m_trustedTypesEnabled);
    m_page->settings().setUAVisualTransitionDetectionEnabled(m_uAVisualTransitionDetectionEnabled);
    m_page->settings().setUndoManagerAPIEnabled(m_undoManagerAPIEnabled);
    m_page->settings().setUnhandledPromiseRejectionToConsoleEnabled(m_unhandledPromiseRejectionToConsoleEnabled);
#if ENABLE(UNIFIED_PDF)
    m_page->settings().setUnifiedPDFEnabled(m_unifiedPDFEnabled);
#endif
    m_page->settings().setUnifiedTextCheckerEnabled(m_unifiedTextCheckerEnabled);
#if ENABLE(DAMAGE_TRACKING)
    m_page->settings().setUnifyDamagedRegions(m_unifyDamagedRegions);
#endif
    m_page->settings().setUpgradeMixedContentEnabled(m_upgradeMixedContentEnabled);
    m_page->settings().setURLPatternAPIEnabled(m_urlPatternAPIEnabled);
    m_page->settings().setUseAnonymousModeWhenFetchingMaskImages(m_useAnonymousModeWhenFetchingMaskImages);
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setUseAsyncUIKitInteractions(m_useAsyncUIKitInteractions);
#endif
#if ENABLE(DAMAGE_TRACKING)
    m_page->settings().setUseDamagingInformationForCompositing(m_useDamagingInformationForCompositing);
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
    m_page->settings().setUseGPUProcessForWebGLEnabled(m_useGPUProcessForWebGLEnabled);
#endif
    m_page->settings().setUseGiantTiles(m_useGiantTiles);
    m_page->settings().setUseIFCForSVGText(m_useIFCForSVGText);
    m_page->settings().setUseImageDocumentForSubframePDF(m_useImageDocumentForSubframePDF);
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setUseMicrophoneMuteStatusAPI(m_useMicrophoneMuteStatusAPI);
#endif
    m_page->settings().setUsePreHTML5ParserQuirks(m_usePreHTML5ParserQuirks);
    m_page->settings().setUseSystemAppearance(m_useSystemAppearance);
    m_page->settings().setUserActivationAPIEnabled(m_userActivationAPIEnabled);
    m_page->settings().setUserGesturePromisePropagationEnabled(m_userGesturePromisePropagationEnabled);
    m_page->settings().setUsesEncodingDetector(m_usesEncodingDetector);
    m_page->settings().setValidationMessageTimerMagnification(m_validationMessageTimerMagnification);
    m_page->settings().setVerifyWindowOpenUserGestureFromUIProcess(m_verifyWindowOpenUserGestureFromUIProcess);
    m_page->settings().setVerticalFormControlsEnabled(m_verticalFormControlsEnabled);
#if ENABLE(FULLSCREEN_API)
    m_page->settings().setVideoFullsceenPrefersMostVisibleHeuristic(m_videoFullsceenPrefersMostVisibleHeuristic);
#endif
#if ENABLE(FULLSCREEN_API)
    m_page->settings().setVideoFullscreenRequiresElementFullscreen(m_videoFullscreenRequiresElementFullscreen);
#endif
    m_page->settings().setVideoPresentationManagerEnabled(m_videoPresentationManagerEnabled);
    m_page->settings().setVideoPresentationModeAPIEnabled(m_videoPresentationModeAPIEnabled);
#if ENABLE(VIDEO)
    m_page->settings().setVideoQualityIncludesDisplayCompositingEnabled(m_videoQualityIncludesDisplayCompositingEnabled);
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    m_page->settings().setVideoRendererProtectedFallbackDisabled(m_videoRendererProtectedFallbackDisabled);
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    m_page->settings().setVideoRendererUseDecompressionSessionForProtected(m_videoRendererUseDecompressionSessionForProtected);
#endif
    m_page->settings().setViewTransitionClassesEnabled(m_viewTransitionClassesEnabled);
    m_page->settings().setViewTransitionTypesEnabled(m_viewTransitionTypesEnabled);
    m_page->settings().setViewTransitionsEnabled(m_viewTransitionsEnabled);
    m_page->settings().setVisibleDebugOverlayRegions(m_visibleDebugOverlayRegions);
#if ENABLE(IMAGE_ANALYSIS)
    m_page->settings().setVisualTranslationEnabled(m_visualTranslationEnabled);
#endif
    m_page->settings().setVisualViewportAPIEnabled(m_visualViewportAPIEnabled);
    m_page->settings().setVisualViewportEnabled(m_visualViewportEnabled);
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setVisuallyContiguousBidiTextSelectionEnabled(m_visuallyContiguousBidiTextSelectionEnabled);
#endif
#if ENABLE(VP9)
    m_page->settings().setVP9DecoderEnabled(m_vp9DecoderEnabled);
#endif
    m_page->settings().setWantsBalancedSetDefersLoadingBehavior(m_wantsBalancedSetDefersLoadingBehavior);
    m_page->settings().setWebAPIStatisticsEnabled(m_webAPIStatisticsEnabled);
    m_page->settings().setWebAPIsInShadowRealmEnabled(m_webAPIsInShadowRealmEnabled);
    m_page->settings().setWebAnimationsCustomEffectsEnabled(m_webAnimationsCustomEffectsEnabled);
    m_page->settings().setWebAnimationsCustomFrameRateEnabled(m_webAnimationsCustomFrameRateEnabled);
    m_page->settings().setWebAnimationsOverallProgressPropertyEnabled(m_webAnimationsOverallProgressPropertyEnabled);
#if ENABLE(WEB_ARCHIVE)
    m_page->settings().setWebArchiveDebugModeEnabled(m_webArchiveDebugModeEnabled);
#endif
#if ENABLE(WEB_ARCHIVE)
    m_page->settings().setWebArchiveTestingModeEnabled(m_webArchiveTestingModeEnabled);
#endif
#if ENABLE(WEBASSEMBLY)
    m_page->settings().setWebAssemblyESMIntegrationEnabled(m_webAssemblyESMIntegrationEnabled);
#endif
#if ENABLE(WEB_AUDIO)
    m_page->settings().setWebAudioEnabled(m_webAudioEnabled);
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
    m_page->settings().setWebAuthenticationASEnabled(m_webAuthenticationASEnabled);
#endif
#if ENABLE(WEB_AUTHN)
    m_page->settings().setWebAuthenticationEnabled(m_webAuthenticationEnabled);
#endif
#if ENABLE(WEB_CODECS)
    m_page->settings().setWebCodecsAV1Enabled(m_webCodecsAV1Enabled);
#endif
#if ENABLE(WEB_CODECS)
    m_page->settings().setWebCodecsAudioEnabled(m_webCodecsAudioEnabled);
#endif
#if ENABLE(WEB_CODECS)
    m_page->settings().setWebCodecsHEVCEnabled(m_webCodecsHEVCEnabled);
#endif
#if ENABLE(WEB_CODECS)
    m_page->settings().setWebCodecsVideoEnabled(m_webCodecsVideoEnabled);
#endif
    m_page->settings().setWebCryptoSafeCurvesEnabled(m_webCryptoSafeCurvesEnabled);
    m_page->settings().setWebCryptoX25519Enabled(m_webCryptoX25519Enabled);
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    m_page->settings().setWebExtensionBookmarksEnabled(m_webExtensionBookmarksEnabled);
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    m_page->settings().setWebExtensionSidebarEnabled(m_webExtensionSidebarEnabled);
#endif
    m_page->settings().setWebGLDraftExtensionsEnabled(m_webGLDraftExtensionsEnabled);
    m_page->settings().setWebGLEnabled(m_webGLEnabled);
    m_page->settings().setWebGLErrorsToConsoleEnabled(m_webGLErrorsToConsoleEnabled);
    m_page->settings().setWebGLTimerQueriesEnabled(m_webGLTimerQueriesEnabled);
    m_page->settings().setWebGPUEnabled(m_webGPUEnabled);
    m_page->settings().setWebGPUHDREnabled(m_webGPUHDREnabled);
    m_page->settings().setWebInspectorEngineeringSettingsAllowed(m_webInspectorEngineeringSettingsAllowed);
    m_page->settings().setWebLocksAPIEnabled(m_webLocksAPIEnabled);
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    m_page->settings().setWebPageSpatialBackdropEnabled(m_webPageSpatialBackdropEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCAV1CodecEnabled(m_webRTCAV1CodecEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCDTMFEnabled(m_webRTCDTMFEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCEncodedTransformEnabled(m_webRTCEncodedTransformEnabled);
#endif
    m_page->settings().setWebRTCEncryptionEnabled(m_webRTCEncryptionEnabled);
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCH265CodecEnabled(m_webRTCH265CodecEnabled);
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
    m_page->settings().setWebRTCInterfaceMonitoringViaNWEnabled(m_webRTCInterfaceMonitoringViaNWEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCL4SEnabled(m_webRTCL4SEnabled);
#endif
    m_page->settings().setWebRTCMediaPipelineAdditionalLoggingEnabled(m_webRTCMediaPipelineAdditionalLoggingEnabled);
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCPlatformCodecsInGPUProcessEnabled(m_webRTCPlatformCodecsInGPUProcessEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCRemoteVideoFrameEnabled(m_webRTCRemoteVideoFrameEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCSFrameTransformEnabled(m_webRTCSFrameTransformEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCSocketsProxyingEnabled(m_webRTCSocketsProxyingEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCUDPPortRange(m_webRTCUDPPortRange);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCVP9Profile0CodecEnabled(m_webRTCVP9Profile0CodecEnabled);
#endif
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCVP9Profile2CodecEnabled(m_webRTCVP9Profile2CodecEnabled);
#endif
    m_page->settings().setWebSecurityEnabled(m_webSecurityEnabled);
    m_page->settings().setWebShareEnabled(m_webShareEnabled);
    m_page->settings().setWebShareFileAPIEnabled(m_webShareFileAPIEnabled);
    m_page->settings().setWebSocketEnabled(m_webSocketEnabled);
    m_page->settings().setWebTransportEnabled(m_webTransportEnabled);
#if ENABLE(WEBXR)
    m_page->settings().setWebXRAugmentedRealityModuleEnabled(m_webXRAugmentedRealityModuleEnabled);
#endif
#if ENABLE(WEBXR)
    m_page->settings().setWebXREnabled(m_webXREnabled);
#endif
#if ENABLE(WEBXR)
    m_page->settings().setWebXRGamepadsModuleEnabled(m_webXRGamepadsModuleEnabled);
#endif
#if ENABLE(WEBXR_HANDS)
    m_page->settings().setWebXRHandInputModuleEnabled(m_webXRHandInputModuleEnabled);
#endif
#if ENABLE(WEBXR_LAYERS)
    m_page->settings().setWebXRLayersAPIEnabled(m_webXRLayersAPIEnabled);
#endif
    m_page->settings().setWebXRWebGPUBindingsEnabled(m_webXRWebGPUBindingsEnabled);
    m_page->settings().setWebkitImageReadyEventEnabled(m_webkitImageReadyEventEnabled);
    m_page->settings().setWheelEventGesturesBecomeNonBlocking(m_wheelEventGesturesBecomeNonBlocking);
    m_page->settings().setWindowFocusRestricted(m_windowFocusRestricted);
    m_page->settings().setWirelessPlaybackTargetAPIEnabled(m_wirelessPlaybackTargetAPIEnabled);
    m_page->settings().setWorkerAsynchronousURLErrorHandlingEnabled(m_workerAsynchronousURLErrorHandlingEnabled);
#if PLATFORM(COCOA)
    m_page->settings().setWriteRichTextDataWhenCopyingOrDragging(m_writeRichTextDataWhenCopyingOrDragging);
#endif
#if ENABLE(WRITING_SUGGESTIONS)
    m_page->settings().setWritingSuggestionsAttributeEnabled(m_writingSuggestionsAttributeEnabled);
#endif
#if ENABLE(XSLT)
    m_page->settings().setXsltEnabled(m_xsltEnabled);
#endif
}

void InternalSettingsGenerated::setAVKitContentSourceEnabled(bool aVKitContentSourceEnabled)
{
#if HAVE(AVKIT_CONTENT_SOURCE)
    m_page->settings().setAVKitContentSourceEnabled(aVKitContentSourceEnabled);
#else
    UNUSED_PARAM(aVKitContentSourceEnabled);
#endif
}

void InternalSettingsGenerated::setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled)
{
    m_page->settings().setAcceleratedCompositingEnabled(acceleratedCompositingEnabled);
}

void InternalSettingsGenerated::setAcceleratedCompositingForFixedPositionEnabled(bool acceleratedCompositingForFixedPositionEnabled)
{
    m_page->settings().setAcceleratedCompositingForFixedPositionEnabled(acceleratedCompositingForFixedPositionEnabled);
}

void InternalSettingsGenerated::setAcceleratedDrawingEnabled(bool acceleratedDrawingEnabled)
{
    m_page->settings().setAcceleratedDrawingEnabled(acceleratedDrawingEnabled);
}

void InternalSettingsGenerated::setAcceleratedFiltersEnabled(bool acceleratedFiltersEnabled)
{
#if USE(CORE_IMAGE)
    m_page->settings().setAcceleratedFiltersEnabled(acceleratedFiltersEnabled);
#else
    UNUSED_PARAM(acceleratedFiltersEnabled);
#endif
}

void InternalSettingsGenerated::setAccentColorEnabled(bool accentColorEnabled)
{
    m_page->settings().setAccentColorEnabled(accentColorEnabled);
}

void InternalSettingsGenerated::setAccessHandleEnabled(bool accessHandleEnabled)
{
    m_page->settings().setAccessHandleEnabled(accessHandleEnabled);
}

void InternalSettingsGenerated::setAggressiveTileRetentionEnabled(bool aggressiveTileRetentionEnabled)
{
    m_page->settings().setAggressiveTileRetentionEnabled(aggressiveTileRetentionEnabled);
}

void InternalSettingsGenerated::setAllowAnimationControlsOverride(bool allowAnimationControlsOverride)
{
    m_page->settings().setAllowAnimationControlsOverride(allowAnimationControlsOverride);
}

void InternalSettingsGenerated::setAllowContentSecurityPolicySourceStarToMatchAnyProtocol(bool allowContentSecurityPolicySourceStarToMatchAnyProtocol)
{
    m_page->settings().setAllowContentSecurityPolicySourceStarToMatchAnyProtocol(allowContentSecurityPolicySourceStarToMatchAnyProtocol);
}

void InternalSettingsGenerated::setAllowDisplayOfInsecureContent(bool allowDisplayOfInsecureContent)
{
    m_page->settings().setAllowDisplayOfInsecureContent(allowDisplayOfInsecureContent);
}

void InternalSettingsGenerated::setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs)
{
    m_page->settings().setAllowFileAccessFromFileURLs(allowFileAccessFromFileURLs);
}

void InternalSettingsGenerated::setAllowMediaContentTypesRequiringHardwareSupportAsFallback(bool allowMediaContentTypesRequiringHardwareSupportAsFallback)
{
    m_page->settings().setAllowMediaContentTypesRequiringHardwareSupportAsFallback(allowMediaContentTypesRequiringHardwareSupportAsFallback);
}

void InternalSettingsGenerated::setAllowMultiElementImplicitSubmission(bool allowMultiElementImplicitSubmission)
{
    m_page->settings().setAllowMultiElementImplicitSubmission(allowMultiElementImplicitSubmission);
}

void InternalSettingsGenerated::setAllowPrivacySensitiveOperationsInNonPersistentDataStores(bool allowPrivacySensitiveOperationsInNonPersistentDataStores)
{
    m_page->settings().setAllowPrivacySensitiveOperationsInNonPersistentDataStores(allowPrivacySensitiveOperationsInNonPersistentDataStores);
}

void InternalSettingsGenerated::setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent)
{
    m_page->settings().setAllowRunningOfInsecureContent(allowRunningOfInsecureContent);
}

void InternalSettingsGenerated::setAllowTopNavigationToDataURLs(bool allowTopNavigationToDataURLs)
{
    m_page->settings().setAllowTopNavigationToDataURLs(allowTopNavigationToDataURLs);
}

void InternalSettingsGenerated::setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs)
{
    m_page->settings().setAllowUniversalAccessFromFileURLs(allowUniversalAccessFromFileURLs);
}

void InternalSettingsGenerated::setAllowViewportShrinkToFitContent(bool allowViewportShrinkToFitContent)
{
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setAllowViewportShrinkToFitContent(allowViewportShrinkToFitContent);
#else
    UNUSED_PARAM(allowViewportShrinkToFitContent);
#endif
}

void InternalSettingsGenerated::setAllowWebGLInWorkers(bool allowWebGLInWorkers)
{
#if ENABLE(WEBGL)
    m_page->settings().setAllowWebGLInWorkers(allowWebGLInWorkers);
#else
    UNUSED_PARAM(allowWebGLInWorkers);
#endif
}

void InternalSettingsGenerated::setAllowsAirPlayForMediaPlayback(bool allowsAirPlayForMediaPlayback)
{
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    m_page->settings().setAllowsAirPlayForMediaPlayback(allowsAirPlayForMediaPlayback);
#else
    UNUSED_PARAM(allowsAirPlayForMediaPlayback);
#endif
}

void InternalSettingsGenerated::setAllowsInlineMediaPlayback(bool allowsInlineMediaPlayback)
{
    m_page->settings().setAllowsInlineMediaPlayback(allowsInlineMediaPlayback);
}

void InternalSettingsGenerated::setAllowsInlineMediaPlaybackAfterFullscreen(bool allowsInlineMediaPlaybackAfterFullscreen)
{
    m_page->settings().setAllowsInlineMediaPlaybackAfterFullscreen(allowsInlineMediaPlaybackAfterFullscreen);
}

void InternalSettingsGenerated::setAllowsPictureInPictureMediaPlayback(bool allowsPictureInPictureMediaPlayback)
{
    m_page->settings().setAllowsPictureInPictureMediaPlayback(allowsPictureInPictureMediaPlayback);
}

void InternalSettingsGenerated::setAlternateFullScreenControlDesignEnabled(bool alternateFullScreenControlDesignEnabled)
{
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setAlternateFullScreenControlDesignEnabled(alternateFullScreenControlDesignEnabled);
#else
    UNUSED_PARAM(alternateFullScreenControlDesignEnabled);
#endif
}

void InternalSettingsGenerated::setAltitudeAngleEnabled(bool altitudeAngleEnabled)
{
    m_page->settings().setAltitudeAngleEnabled(altitudeAngleEnabled);
}

void InternalSettingsGenerated::setAlwaysAllowLocalWebarchive(bool alwaysAllowLocalWebarchive)
{
#if ENABLE(WEB_ARCHIVE)
    m_page->settings().setAlwaysAllowLocalWebarchive(alwaysAllowLocalWebarchive);
#else
    UNUSED_PARAM(alwaysAllowLocalWebarchive);
#endif
}

void InternalSettingsGenerated::setAnimatedImageAsyncDecodingEnabled(bool animatedImageAsyncDecodingEnabled)
{
    m_page->settings().setAnimatedImageAsyncDecodingEnabled(animatedImageAsyncDecodingEnabled);
}

void InternalSettingsGenerated::setAnimatedImageDebugCanvasDrawingEnabled(bool animatedImageDebugCanvasDrawingEnabled)
{
    m_page->settings().setAnimatedImageDebugCanvasDrawingEnabled(animatedImageDebugCanvasDrawingEnabled);
}

void InternalSettingsGenerated::setAppBadgeEnabled(bool appBadgeEnabled)
{
    m_page->settings().setAppBadgeEnabled(appBadgeEnabled);
}

void InternalSettingsGenerated::setAppHighlightsEnabled(bool appHighlightsEnabled)
{
#if ENABLE(APP_HIGHLIGHTS)
    m_page->settings().setAppHighlightsEnabled(appHighlightsEnabled);
#else
    UNUSED_PARAM(appHighlightsEnabled);
#endif
}

void InternalSettingsGenerated::setAppleMailPaginationQuirkEnabled(bool appleMailPaginationQuirkEnabled)
{
    m_page->settings().setAppleMailPaginationQuirkEnabled(appleMailPaginationQuirkEnabled);
}

void InternalSettingsGenerated::setApplePayCapabilityDisclosureAllowed(bool applePayCapabilityDisclosureAllowed)
{
#if ENABLE(APPLE_PAY)
    m_page->settings().setApplePayCapabilityDisclosureAllowed(applePayCapabilityDisclosureAllowed);
#else
    UNUSED_PARAM(applePayCapabilityDisclosureAllowed);
#endif
}

void InternalSettingsGenerated::setApplePayEnabled(bool applePayEnabled)
{
#if ENABLE(APPLE_PAY)
    m_page->settings().setApplePayEnabled(applePayEnabled);
#else
    UNUSED_PARAM(applePayEnabled);
#endif
}

void InternalSettingsGenerated::setAsyncClipboardAPIEnabled(bool asyncClipboardAPIEnabled)
{
    m_page->settings().setAsyncClipboardAPIEnabled(asyncClipboardAPIEnabled);
}

void InternalSettingsGenerated::setAsyncFrameScrollingEnabled(bool asyncFrameScrollingEnabled)
{
    m_page->settings().setAsyncFrameScrollingEnabled(asyncFrameScrollingEnabled);
}

void InternalSettingsGenerated::setAsyncOverflowScrollingEnabled(bool asyncOverflowScrollingEnabled)
{
    m_page->settings().setAsyncOverflowScrollingEnabled(asyncOverflowScrollingEnabled);
}

void InternalSettingsGenerated::setAsynchronousSpellCheckingEnabled(bool asynchronousSpellCheckingEnabled)
{
    m_page->settings().setAsynchronousSpellCheckingEnabled(asynchronousSpellCheckingEnabled);
}

void InternalSettingsGenerated::setAttachmentWideLayoutEnabled(bool attachmentWideLayoutEnabled)
{
#if ENABLE(ATTACHMENT_ELEMENT)
    m_page->settings().setAttachmentWideLayoutEnabled(attachmentWideLayoutEnabled);
#else
    UNUSED_PARAM(attachmentWideLayoutEnabled);
#endif
}

void InternalSettingsGenerated::setAudioControlsScaleWithPageZoom(bool audioControlsScaleWithPageZoom)
{
    m_page->settings().setAudioControlsScaleWithPageZoom(audioControlsScaleWithPageZoom);
}

void InternalSettingsGenerated::setAudioDescriptionsEnabled(bool audioDescriptionsEnabled)
{
#if ENABLE(VIDEO)
    m_page->settings().setAudioDescriptionsEnabled(audioDescriptionsEnabled);
#else
    UNUSED_PARAM(audioDescriptionsEnabled);
#endif
}

void InternalSettingsGenerated::setAuthorAndUserStylesEnabled(bool authorAndUserStylesEnabled)
{
    m_page->settings().setAuthorAndUserStylesEnabled(authorAndUserStylesEnabled);
}

void InternalSettingsGenerated::setAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth(bool automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth)
{
    m_page->settings().setAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth(automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth);
}

void InternalSettingsGenerated::setAutoscrollForDragAndDropEnabled(bool autoscrollForDragAndDropEnabled)
{
    m_page->settings().setAutoscrollForDragAndDropEnabled(autoscrollForDragAndDropEnabled);
}

void InternalSettingsGenerated::setAuxclickEventEnabled(bool auxclickEventEnabled)
{
    m_page->settings().setAuxclickEventEnabled(auxclickEventEnabled);
}

void InternalSettingsGenerated::setAzimuthAngleEnabled(bool azimuthAngleEnabled)
{
    m_page->settings().setAzimuthAngleEnabled(azimuthAngleEnabled);
}

void InternalSettingsGenerated::setBackgroundFetchAPIEnabled(bool backgroundFetchAPIEnabled)
{
    m_page->settings().setBackgroundFetchAPIEnabled(backgroundFetchAPIEnabled);
}

void InternalSettingsGenerated::setBackgroundShouldExtendBeyondPage(bool backgroundShouldExtendBeyondPage)
{
    m_page->settings().setBackgroundShouldExtendBeyondPage(backgroundShouldExtendBeyondPage);
}

void InternalSettingsGenerated::setBackgroundWebContentRunningBoardThrottlingEnabled(bool backgroundWebContentRunningBoardThrottlingEnabled)
{
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
    m_page->settings().setBackgroundWebContentRunningBoardThrottlingEnabled(backgroundWebContentRunningBoardThrottlingEnabled);
#else
    UNUSED_PARAM(backgroundWebContentRunningBoardThrottlingEnabled);
#endif
}

void InternalSettingsGenerated::setBackspaceKeyNavigationEnabled(bool backspaceKeyNavigationEnabled)
{
    m_page->settings().setBackspaceKeyNavigationEnabled(backspaceKeyNavigationEnabled);
}

void InternalSettingsGenerated::setBeaconAPIEnabled(bool beaconAPIEnabled)
{
    m_page->settings().setBeaconAPIEnabled(beaconAPIEnabled);
}

void InternalSettingsGenerated::setBidiContentAwarePasteEnabled(bool bidiContentAwarePasteEnabled)
{
    m_page->settings().setBidiContentAwarePasteEnabled(bidiContentAwarePasteEnabled);
}

void InternalSettingsGenerated::setBlobFileAccessEnforcementEnabled(bool blobFileAccessEnforcementEnabled)
{
    m_page->settings().setBlobFileAccessEnforcementEnabled(blobFileAccessEnforcementEnabled);
}

void InternalSettingsGenerated::setBlockMediaLayerRehostingInWebContentProcess(bool blockMediaLayerRehostingInWebContentProcess)
{
#if ENABLE(GPU_PROCESS)
    m_page->settings().setBlockMediaLayerRehostingInWebContentProcess(blockMediaLayerRehostingInWebContentProcess);
#else
    UNUSED_PARAM(blockMediaLayerRehostingInWebContentProcess);
#endif
}

void InternalSettingsGenerated::setBroadcastChannelEnabled(bool broadcastChannelEnabled)
{
    m_page->settings().setBroadcastChannelEnabled(broadcastChannelEnabled);
}

void InternalSettingsGenerated::setCacheAPIEnabled(bool cacheAPIEnabled)
{
    m_page->settings().setCacheAPIEnabled(cacheAPIEnabled);
}

void InternalSettingsGenerated::setCanvasColorSpaceEnabled(bool canvasColorSpaceEnabled)
{
    m_page->settings().setCanvasColorSpaceEnabled(canvasColorSpaceEnabled);
}

void InternalSettingsGenerated::setCanvasFiltersEnabled(bool canvasFiltersEnabled)
{
    m_page->settings().setCanvasFiltersEnabled(canvasFiltersEnabled);
}

void InternalSettingsGenerated::setCanvasFingerprintingQuirkEnabled(bool canvasFingerprintingQuirkEnabled)
{
    m_page->settings().setCanvasFingerprintingQuirkEnabled(canvasFingerprintingQuirkEnabled);
}

void InternalSettingsGenerated::setCanvasLayersEnabled(bool canvasLayersEnabled)
{
    m_page->settings().setCanvasLayersEnabled(canvasLayersEnabled);
}

void InternalSettingsGenerated::setCanvasPixelFormatEnabled(bool canvasPixelFormatEnabled)
{
    m_page->settings().setCanvasPixelFormatEnabled(canvasPixelFormatEnabled);
}

void InternalSettingsGenerated::setCanvasUsesAcceleratedDrawing(bool canvasUsesAcceleratedDrawing)
{
#if USE(CA) || USE(SKIA)
    m_page->settings().setCanvasUsesAcceleratedDrawing(canvasUsesAcceleratedDrawing);
#else
    UNUSED_PARAM(canvasUsesAcceleratedDrawing);
#endif
}

void InternalSettingsGenerated::setCaretBrowsingEnabled(bool caretBrowsingEnabled)
{
    m_page->settings().setCaretBrowsingEnabled(caretBrowsingEnabled);
}

void InternalSettingsGenerated::setCaretPositionFromPointEnabled(bool caretPositionFromPointEnabled)
{
    m_page->settings().setCaretPositionFromPointEnabled(caretPositionFromPointEnabled);
}

void InternalSettingsGenerated::setChildProcessDebuggabilityEnabled(bool childProcessDebuggabilityEnabled)
{
    m_page->settings().setChildProcessDebuggabilityEnabled(childProcessDebuggabilityEnabled);
}

void InternalSettingsGenerated::setClearSiteDataExecutionContextsSupportEnabled(bool clearSiteDataExecutionContextsSupportEnabled)
{
    m_page->settings().setClearSiteDataExecutionContextsSupportEnabled(clearSiteDataExecutionContextsSupportEnabled);
}

void InternalSettingsGenerated::setClearSiteDataHTTPHeaderEnabled(bool clearSiteDataHTTPHeaderEnabled)
{
    m_page->settings().setClearSiteDataHTTPHeaderEnabled(clearSiteDataHTTPHeaderEnabled);
}

void InternalSettingsGenerated::setClientCoordinatesRelativeToLayoutViewport(bool clientCoordinatesRelativeToLayoutViewport)
{
    m_page->settings().setClientCoordinatesRelativeToLayoutViewport(clientCoordinatesRelativeToLayoutViewport);
}

void InternalSettingsGenerated::setCloseWatcherEnabled(bool closeWatcherEnabled)
{
    m_page->settings().setCloseWatcherEnabled(closeWatcherEnabled);
}

void InternalSettingsGenerated::setColorFilterEnabled(bool colorFilterEnabled)
{
    m_page->settings().setColorFilterEnabled(colorFilterEnabled);
}

void InternalSettingsGenerated::setCommandAttributesEnabled(bool commandAttributesEnabled)
{
    m_page->settings().setCommandAttributesEnabled(commandAttributesEnabled);
}

void InternalSettingsGenerated::setCompressionStreamEnabled(bool compressionStreamEnabled)
{
    m_page->settings().setCompressionStreamEnabled(compressionStreamEnabled);
}

void InternalSettingsGenerated::setContactPickerAPIEnabled(bool contactPickerAPIEnabled)
{
    m_page->settings().setContactPickerAPIEnabled(contactPickerAPIEnabled);
}

void InternalSettingsGenerated::setContentChangeObserverEnabled(bool contentChangeObserverEnabled)
{
#if ENABLE(CONTENT_CHANGE_OBSERVER)
    m_page->settings().setContentChangeObserverEnabled(contentChangeObserverEnabled);
#else
    UNUSED_PARAM(contentChangeObserverEnabled);
#endif
}

void InternalSettingsGenerated::setContentDispositionAttachmentSandboxEnabled(bool contentDispositionAttachmentSandboxEnabled)
{
    m_page->settings().setContentDispositionAttachmentSandboxEnabled(contentDispositionAttachmentSandboxEnabled);
}

void InternalSettingsGenerated::setContentInsetBackgroundFillEnabled(bool contentInsetBackgroundFillEnabled)
{
    m_page->settings().setContentInsetBackgroundFillEnabled(contentInsetBackgroundFillEnabled);
}

void InternalSettingsGenerated::setContextMenuQRCodeDetectionEnabled(bool contextMenuQRCodeDetectionEnabled)
{
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
    m_page->settings().setContextMenuQRCodeDetectionEnabled(contextMenuQRCodeDetectionEnabled);
#else
    UNUSED_PARAM(contextMenuQRCodeDetectionEnabled);
#endif
}

void InternalSettingsGenerated::setCookieConsentAPIEnabled(bool cookieConsentAPIEnabled)
{
    m_page->settings().setCookieConsentAPIEnabled(cookieConsentAPIEnabled);
}

void InternalSettingsGenerated::setCookieEnabled(bool cookieEnabled)
{
    m_page->settings().setCookieEnabled(cookieEnabled);
}

void InternalSettingsGenerated::setCookieStoreAPIEnabled(bool cookieStoreAPIEnabled)
{
    m_page->settings().setCookieStoreAPIEnabled(cookieStoreAPIEnabled);
}

void InternalSettingsGenerated::setCookieStoreAPIExtendedAttributesEnabled(bool cookieStoreAPIExtendedAttributesEnabled)
{
    m_page->settings().setCookieStoreAPIExtendedAttributesEnabled(cookieStoreAPIExtendedAttributesEnabled);
}

void InternalSettingsGenerated::setCookieStoreManagerEnabled(bool cookieStoreManagerEnabled)
{
    m_page->settings().setCookieStoreManagerEnabled(cookieStoreManagerEnabled);
}

void InternalSettingsGenerated::setCoreMathMLEnabled(bool coreMathMLEnabled)
{
    m_page->settings().setCoreMathMLEnabled(coreMathMLEnabled);
}

void InternalSettingsGenerated::setCrossDocumentViewTransitionsEnabled(bool crossDocumentViewTransitionsEnabled)
{
    m_page->settings().setCrossDocumentViewTransitionsEnabled(crossDocumentViewTransitionsEnabled);
}

void InternalSettingsGenerated::setCrossOriginCheckInGetMatchedCSSRulesDisabled(bool crossOriginCheckInGetMatchedCSSRulesDisabled)
{
    m_page->settings().setCrossOriginCheckInGetMatchedCSSRulesDisabled(crossOriginCheckInGetMatchedCSSRulesDisabled);
}

void InternalSettingsGenerated::setCrossOriginEmbedderPolicyEnabled(bool crossOriginEmbedderPolicyEnabled)
{
    m_page->settings().setCrossOriginEmbedderPolicyEnabled(crossOriginEmbedderPolicyEnabled);
}

void InternalSettingsGenerated::setCrossOriginOpenerPolicyEnabled(bool crossOriginOpenerPolicyEnabled)
{
    m_page->settings().setCrossOriginOpenerPolicyEnabled(crossOriginOpenerPolicyEnabled);
}

void InternalSettingsGenerated::setCSS3DTransformBackfaceVisibilityInteroperabilityEnabled(bool css3DTransformBackfaceVisibilityInteroperabilityEnabled)
{
    m_page->settings().setCSS3DTransformBackfaceVisibilityInteroperabilityEnabled(css3DTransformBackfaceVisibilityInteroperabilityEnabled);
}

void InternalSettingsGenerated::setCSSAnchorPositioningEnabled(bool cssAnchorPositioningEnabled)
{
    m_page->settings().setCSSAnchorPositioningEnabled(cssAnchorPositioningEnabled);
}

void InternalSettingsGenerated::setCSSAnchorPositioningPositionVisibilityEnabled(bool cssAnchorPositioningPositionVisibilityEnabled)
{
    m_page->settings().setCSSAnchorPositioningPositionVisibilityEnabled(cssAnchorPositioningPositionVisibilityEnabled);
}

void InternalSettingsGenerated::setCSSAppearanceBaseEnabled(bool cssAppearanceBaseEnabled)
{
    m_page->settings().setCSSAppearanceBaseEnabled(cssAppearanceBaseEnabled);
}

void InternalSettingsGenerated::setCSSAxisRelativePositionKeywordsEnabled(bool cssAxisRelativePositionKeywordsEnabled)
{
    m_page->settings().setCSSAxisRelativePositionKeywordsEnabled(cssAxisRelativePositionKeywordsEnabled);
}

void InternalSettingsGenerated::setCSSBackgroundClipBorderAreaEnabled(bool cssBackgroundClipBorderAreaEnabled)
{
    m_page->settings().setCSSBackgroundClipBorderAreaEnabled(cssBackgroundClipBorderAreaEnabled);
}

void InternalSettingsGenerated::setCSSColorLayersEnabled(bool cssColorLayersEnabled)
{
    m_page->settings().setCSSColorLayersEnabled(cssColorLayersEnabled);
}

void InternalSettingsGenerated::setCSSConstrainedDynamicRangeLimitEnabled(bool cssConstrainedDynamicRangeLimitEnabled)
{
    m_page->settings().setCSSConstrainedDynamicRangeLimitEnabled(cssConstrainedDynamicRangeLimitEnabled);
}

void InternalSettingsGenerated::setCSSContrastColorEnabled(bool cssContrastColorEnabled)
{
    m_page->settings().setCSSContrastColorEnabled(cssContrastColorEnabled);
}

void InternalSettingsGenerated::setCSSCornerShapeEnabled(bool cssCornerShapeEnabled)
{
    m_page->settings().setCSSCornerShapeEnabled(cssCornerShapeEnabled);
}

void InternalSettingsGenerated::setCSSCounterStyleAtRuleImageSymbolsEnabled(bool cssCounterStyleAtRuleImageSymbolsEnabled)
{
    m_page->settings().setCSSCounterStyleAtRuleImageSymbolsEnabled(cssCounterStyleAtRuleImageSymbolsEnabled);
}

void InternalSettingsGenerated::setCSSDPropertyEnabled(bool cssDPropertyEnabled)
{
    m_page->settings().setCSSDPropertyEnabled(cssDPropertyEnabled);
}

void InternalSettingsGenerated::setCSSDynamicRangeLimitMixEnabled(bool cssDynamicRangeLimitMixEnabled)
{
    m_page->settings().setCSSDynamicRangeLimitMixEnabled(cssDynamicRangeLimitMixEnabled);
}

void InternalSettingsGenerated::setCSSFieldSizingEnabled(bool cssFieldSizingEnabled)
{
    m_page->settings().setCSSFieldSizingEnabled(cssFieldSizingEnabled);
}

void InternalSettingsGenerated::setCSSFontVariantEmojiEnabled(bool cssFontVariantEmojiEnabled)
{
    m_page->settings().setCSSFontVariantEmojiEnabled(cssFontVariantEmojiEnabled);
}

void InternalSettingsGenerated::setCSSInputSecurityEnabled(bool cssInputSecurityEnabled)
{
    m_page->settings().setCSSInputSecurityEnabled(cssInputSecurityEnabled);
}

void InternalSettingsGenerated::setCSSLineClampEnabled(bool cssLineClampEnabled)
{
    m_page->settings().setCSSLineClampEnabled(cssLineClampEnabled);
}

void InternalSettingsGenerated::setCSSLineFitEdgeEnabled(bool cssLineFitEdgeEnabled)
{
    m_page->settings().setCSSLineFitEdgeEnabled(cssLineFitEdgeEnabled);
}

void InternalSettingsGenerated::setCSSPaintingAPIEnabled(bool cssPaintingAPIEnabled)
{
    m_page->settings().setCSSPaintingAPIEnabled(cssPaintingAPIEnabled);
}

void InternalSettingsGenerated::setCSSProgressFunctionEnabled(bool cssProgressFunctionEnabled)
{
    m_page->settings().setCSSProgressFunctionEnabled(cssProgressFunctionEnabled);
}

void InternalSettingsGenerated::setCSSRandomFunctionEnabled(bool cssRandomFunctionEnabled)
{
    m_page->settings().setCSSRandomFunctionEnabled(cssRandomFunctionEnabled);
}

void InternalSettingsGenerated::setCSSRhythmicSizingEnabled(bool cssRhythmicSizingEnabled)
{
    m_page->settings().setCSSRhythmicSizingEnabled(cssRhythmicSizingEnabled);
}

void InternalSettingsGenerated::setCSSRubyAlignEnabled(bool cssRubyAlignEnabled)
{
    m_page->settings().setCSSRubyAlignEnabled(cssRubyAlignEnabled);
}

void InternalSettingsGenerated::setCSSRubyOverhangEnabled(bool cssRubyOverhangEnabled)
{
    m_page->settings().setCSSRubyOverhangEnabled(cssRubyOverhangEnabled);
}

void InternalSettingsGenerated::setCSSScrollAnchoringEnabled(bool cssScrollAnchoringEnabled)
{
    m_page->settings().setCSSScrollAnchoringEnabled(cssScrollAnchoringEnabled);
}

void InternalSettingsGenerated::setCSSScrollbarColorEnabled(bool cssScrollbarColorEnabled)
{
    m_page->settings().setCSSScrollbarColorEnabled(cssScrollbarColorEnabled);
}

void InternalSettingsGenerated::setCSSScrollbarGutterEnabled(bool cssScrollbarGutterEnabled)
{
    m_page->settings().setCSSScrollbarGutterEnabled(cssScrollbarGutterEnabled);
}

void InternalSettingsGenerated::setCSSScrollbarWidthEnabled(bool cssScrollbarWidthEnabled)
{
    m_page->settings().setCSSScrollbarWidthEnabled(cssScrollbarWidthEnabled);
}

void InternalSettingsGenerated::setCSSShapeFunctionEnabled(bool cssShapeFunctionEnabled)
{
    m_page->settings().setCSSShapeFunctionEnabled(cssShapeFunctionEnabled);
}

void InternalSettingsGenerated::setCSSTextAutospaceEnabled(bool cssTextAutospaceEnabled)
{
    m_page->settings().setCSSTextAutospaceEnabled(cssTextAutospaceEnabled);
}

void InternalSettingsGenerated::setCSSTextBoxTrimEnabled(bool cssTextBoxTrimEnabled)
{
    m_page->settings().setCSSTextBoxTrimEnabled(cssTextBoxTrimEnabled);
}

void InternalSettingsGenerated::setCSSTextGroupAlignEnabled(bool cssTextGroupAlignEnabled)
{
    m_page->settings().setCSSTextGroupAlignEnabled(cssTextGroupAlignEnabled);
}

void InternalSettingsGenerated::setCSSTextJustifyEnabled(bool cssTextJustifyEnabled)
{
    m_page->settings().setCSSTextJustifyEnabled(cssTextJustifyEnabled);
}

void InternalSettingsGenerated::setCSSTextSpacingTrimEnabled(bool cssTextSpacingTrimEnabled)
{
    m_page->settings().setCSSTextSpacingTrimEnabled(cssTextSpacingTrimEnabled);
}

void InternalSettingsGenerated::setCSSTextUnderlinePositionLeftRightEnabled(bool cssTextUnderlinePositionLeftRightEnabled)
{
    m_page->settings().setCSSTextUnderlinePositionLeftRightEnabled(cssTextUnderlinePositionLeftRightEnabled);
}

void InternalSettingsGenerated::setCSSTextWrapPrettyEnabled(bool cssTextWrapPrettyEnabled)
{
    m_page->settings().setCSSTextWrapPrettyEnabled(cssTextWrapPrettyEnabled);
}

void InternalSettingsGenerated::setCSSTransformStyleSeparatedEnabled(bool cssTransformStyleSeparatedEnabled)
{
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
    m_page->settings().setCSSTransformStyleSeparatedEnabled(cssTransformStyleSeparatedEnabled);
#else
    UNUSED_PARAM(cssTransformStyleSeparatedEnabled);
#endif
}

void InternalSettingsGenerated::setCSSTreeCountingFunctionsEnabled(bool cssTreeCountingFunctionsEnabled)
{
    m_page->settings().setCSSTreeCountingFunctionsEnabled(cssTreeCountingFunctionsEnabled);
}

void InternalSettingsGenerated::setCSSTypedOMColorEnabled(bool cssTypedOMColorEnabled)
{
    m_page->settings().setCSSTypedOMColorEnabled(cssTypedOMColorEnabled);
}

void InternalSettingsGenerated::setCSSURLIntegrityModifierEnabled(bool cssURLIntegrityModifierEnabled)
{
    m_page->settings().setCSSURLIntegrityModifierEnabled(cssURLIntegrityModifierEnabled);
}

void InternalSettingsGenerated::setCSSURLModifiersEnabled(bool cssURLModifiersEnabled)
{
    m_page->settings().setCSSURLModifiersEnabled(cssURLModifiersEnabled);
}

void InternalSettingsGenerated::setCSSUnprefixedBackdropFilterEnabled(bool cssUnprefixedBackdropFilterEnabled)
{
    m_page->settings().setCSSUnprefixedBackdropFilterEnabled(cssUnprefixedBackdropFilterEnabled);
}

void InternalSettingsGenerated::setCSSWordBreakAutoPhraseEnabled(bool cssWordBreakAutoPhraseEnabled)
{
    m_page->settings().setCSSWordBreakAutoPhraseEnabled(cssWordBreakAutoPhraseEnabled);
}

void InternalSettingsGenerated::setCursiveFontFamily(const String& cursiveFontFamily)
{
    m_page->settings().setCursiveFontFamily(cursiveFontFamily);
}

void InternalSettingsGenerated::setDataListElementEnabled(bool dataListElementEnabled)
{
    m_page->settings().setDataListElementEnabled(dataListElementEnabled);
}

void InternalSettingsGenerated::setDataTransferItemsEnabled(bool dataTransferItemsEnabled)
{
    m_page->settings().setDataTransferItemsEnabled(dataTransferItemsEnabled);
}

void InternalSettingsGenerated::setDateTimeInputsEditableComponentsEnabled(bool dateTimeInputsEditableComponentsEnabled)
{
    m_page->settings().setDateTimeInputsEditableComponentsEnabled(dateTimeInputsEditableComponentsEnabled);
}

void InternalSettingsGenerated::setDeclarativeWebPush(bool declarativeWebPush)
{
#if ENABLE(DECLARATIVE_WEB_PUSH)
    m_page->settings().setDeclarativeWebPush(declarativeWebPush);
#else
    UNUSED_PARAM(declarativeWebPush);
#endif
}

void InternalSettingsGenerated::setDefaultFixedFontSize(double defaultFixedFontSize)
{
    m_page->settings().setDefaultFixedFontSize(defaultFixedFontSize);
}

void InternalSettingsGenerated::setDefaultFontSize(double defaultFontSize)
{
    m_page->settings().setDefaultFontSize(defaultFontSize);
}

void InternalSettingsGenerated::setDefaultTextEncodingName(const String& defaultTextEncodingName)
{
    m_page->settings().setDefaultTextEncodingName(defaultTextEncodingName);
}

void InternalSettingsGenerated::setDefaultVideoPosterURL(const String& defaultVideoPosterURL)
{
    m_page->settings().setDefaultVideoPosterURL(defaultVideoPosterURL);
}

void InternalSettingsGenerated::setDeprecationReportingEnabled(bool deprecationReportingEnabled)
{
    m_page->settings().setDeprecationReportingEnabled(deprecationReportingEnabled);
}

void InternalSettingsGenerated::setDetachableMediaSourceEnabled(bool detachableMediaSourceEnabled)
{
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setDetachableMediaSourceEnabled(detachableMediaSourceEnabled);
#else
    UNUSED_PARAM(detachableMediaSourceEnabled);
#endif
}

void InternalSettingsGenerated::setDetailsAutoExpandEnabled(bool detailsAutoExpandEnabled)
{
    m_page->settings().setDetailsAutoExpandEnabled(detailsAutoExpandEnabled);
}

void InternalSettingsGenerated::setDeveloperExtrasEnabled(bool developerExtrasEnabled)
{
    m_page->settings().setDeveloperExtrasEnabled(developerExtrasEnabled);
}

void InternalSettingsGenerated::setDeviceHeight(uint32_t deviceHeight)
{
    m_page->settings().setDeviceHeight(deviceHeight);
}

void InternalSettingsGenerated::setDeviceOrientationEventEnabled(bool deviceOrientationEventEnabled)
{
#if ENABLE(DEVICE_ORIENTATION)
    m_page->settings().setDeviceOrientationEventEnabled(deviceOrientationEventEnabled);
#else
    UNUSED_PARAM(deviceOrientationEventEnabled);
#endif
}

void InternalSettingsGenerated::setDeviceOrientationPermissionAPIEnabled(bool deviceOrientationPermissionAPIEnabled)
{
#if ENABLE(DEVICE_ORIENTATION)
    m_page->settings().setDeviceOrientationPermissionAPIEnabled(deviceOrientationPermissionAPIEnabled);
#else
    UNUSED_PARAM(deviceOrientationPermissionAPIEnabled);
#endif
}

void InternalSettingsGenerated::setDeviceWidth(uint32_t deviceWidth)
{
    m_page->settings().setDeviceWidth(deviceWidth);
}

void InternalSettingsGenerated::setDevolvableWidgetsEnabled(bool devolvableWidgetsEnabled)
{
    m_page->settings().setDevolvableWidgetsEnabled(devolvableWidgetsEnabled);
}

void InternalSettingsGenerated::setDiagnosticLoggingEnabled(bool diagnosticLoggingEnabled)
{
    m_page->settings().setDiagnosticLoggingEnabled(diagnosticLoggingEnabled);
}

void InternalSettingsGenerated::setDigitalCredentialsEnabled(bool digitalCredentialsEnabled)
{
#if ENABLE(WEB_AUTHN)
    m_page->settings().setDigitalCredentialsEnabled(digitalCredentialsEnabled);
#else
    UNUSED_PARAM(digitalCredentialsEnabled);
#endif
}

void InternalSettingsGenerated::setDirectoryUploadEnabled(bool directoryUploadEnabled)
{
    m_page->settings().setDirectoryUploadEnabled(directoryUploadEnabled);
}

void InternalSettingsGenerated::setDisabledAdaptationsMetaTagEnabled(bool disabledAdaptationsMetaTagEnabled)
{
    m_page->settings().setDisabledAdaptationsMetaTagEnabled(disabledAdaptationsMetaTagEnabled);
}

void InternalSettingsGenerated::setDOMAudioSessionEnabled(bool domAudioSessionEnabled)
{
#if ENABLE(DOM_AUDIO_SESSION)
    m_page->settings().setDOMAudioSessionEnabled(domAudioSessionEnabled);
#else
    UNUSED_PARAM(domAudioSessionEnabled);
#endif
}

void InternalSettingsGenerated::setDOMAudioSessionFullEnabled(bool domAudioSessionFullEnabled)
{
#if ENABLE(DOM_AUDIO_SESSION)
    m_page->settings().setDOMAudioSessionFullEnabled(domAudioSessionFullEnabled);
#else
    UNUSED_PARAM(domAudioSessionFullEnabled);
#endif
}

void InternalSettingsGenerated::setDOMPasteAccessRequestsEnabled(bool domPasteAccessRequestsEnabled)
{
    m_page->settings().setDOMPasteAccessRequestsEnabled(domPasteAccessRequestsEnabled);
}

void InternalSettingsGenerated::setDOMPasteAllowed(bool domPasteAllowed)
{
    m_page->settings().setDOMPasteAllowed(domPasteAllowed);
}

void InternalSettingsGenerated::setDOMTestingAPIsEnabled(bool domTestingAPIsEnabled)
{
    m_page->settings().setDOMTestingAPIsEnabled(domTestingAPIsEnabled);
}

void InternalSettingsGenerated::setDOMTimersThrottlingEnabled(bool domTimersThrottlingEnabled)
{
    m_page->settings().setDOMTimersThrottlingEnabled(domTimersThrottlingEnabled);
}

void InternalSettingsGenerated::setDownloadAttributeEnabled(bool downloadAttributeEnabled)
{
    m_page->settings().setDownloadAttributeEnabled(downloadAttributeEnabled);
}

void InternalSettingsGenerated::setDynamicSiteInterventionsEnabled(bool dynamicSiteInterventionsEnabled)
{
    m_page->settings().setDynamicSiteInterventionsEnabled(dynamicSiteInterventionsEnabled);
}

void InternalSettingsGenerated::setEmbedElementEnabled(bool embedElementEnabled)
{
    m_page->settings().setEmbedElementEnabled(embedElementEnabled);
}

void InternalSettingsGenerated::setEnableElementCurrentCSSZoom(bool enableElementCurrentCSSZoom)
{
    m_page->settings().setEnableElementCurrentCSSZoom(enableElementCurrentCSSZoom);
}

void InternalSettingsGenerated::setEnableInheritURIQueryComponent(bool enableInheritURIQueryComponent)
{
    m_page->settings().setEnableInheritURIQueryComponent(enableInheritURIQueryComponent);
}

void InternalSettingsGenerated::setEncryptedMediaAPIEnabled(bool encryptedMediaAPIEnabled)
{
#if ENABLE(ENCRYPTED_MEDIA)
    m_page->settings().setEncryptedMediaAPIEnabled(encryptedMediaAPIEnabled);
#else
    UNUSED_PARAM(encryptedMediaAPIEnabled);
#endif
}

void InternalSettingsGenerated::setEnterKeyHintEnabled(bool enterKeyHintEnabled)
{
    m_page->settings().setEnterKeyHintEnabled(enterKeyHintEnabled);
}

void InternalSettingsGenerated::setEventHandlerDrivenSmoothKeyboardScrollingEnabled(bool eventHandlerDrivenSmoothKeyboardScrollingEnabled)
{
    m_page->settings().setEventHandlerDrivenSmoothKeyboardScrollingEnabled(eventHandlerDrivenSmoothKeyboardScrollingEnabled);
}

void InternalSettingsGenerated::setEventTimingEnabled(bool eventTimingEnabled)
{
    m_page->settings().setEventTimingEnabled(eventTimingEnabled);
}

void InternalSettingsGenerated::setExposeCaptureDevicesAfterCaptureEnabled(bool exposeCaptureDevicesAfterCaptureEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setExposeCaptureDevicesAfterCaptureEnabled(exposeCaptureDevicesAfterCaptureEnabled);
#else
    UNUSED_PARAM(exposeCaptureDevicesAfterCaptureEnabled);
#endif
}

void InternalSettingsGenerated::setExposeDefaultSpeakerAsSpecificDeviceEnabled(bool exposeDefaultSpeakerAsSpecificDeviceEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setExposeDefaultSpeakerAsSpecificDeviceEnabled(exposeDefaultSpeakerAsSpecificDeviceEnabled);
#else
    UNUSED_PARAM(exposeDefaultSpeakerAsSpecificDeviceEnabled);
#endif
}

void InternalSettingsGenerated::setExposeSpeakersEnabled(bool exposeSpeakersEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setExposeSpeakersEnabled(exposeSpeakersEnabled);
#else
    UNUSED_PARAM(exposeSpeakersEnabled);
#endif
}

void InternalSettingsGenerated::setExposeSpeakersWithoutMicrophoneEnabled(bool exposeSpeakersWithoutMicrophoneEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setExposeSpeakersWithoutMicrophoneEnabled(exposeSpeakersWithoutMicrophoneEnabled);
#else
    UNUSED_PARAM(exposeSpeakersWithoutMicrophoneEnabled);
#endif
}

void InternalSettingsGenerated::setExtendedAudioDescriptionsEnabled(bool extendedAudioDescriptionsEnabled)
{
#if ENABLE(VIDEO)
    m_page->settings().setExtendedAudioDescriptionsEnabled(extendedAudioDescriptionsEnabled);
#else
    UNUSED_PARAM(extendedAudioDescriptionsEnabled);
#endif
}

void InternalSettingsGenerated::setFantasyFontFamily(const String& fantasyFontFamily)
{
    m_page->settings().setFantasyFontFamily(fantasyFontFamily);
}

void InternalSettingsGenerated::setFileReaderAPIEnabled(bool fileReaderAPIEnabled)
{
    m_page->settings().setFileReaderAPIEnabled(fileReaderAPIEnabled);
}

void InternalSettingsGenerated::setFileSystemEnabled(bool fileSystemEnabled)
{
    m_page->settings().setFileSystemEnabled(fileSystemEnabled);
}

void InternalSettingsGenerated::setFileSystemWritableStreamEnabled(bool fileSystemWritableStreamEnabled)
{
    m_page->settings().setFileSystemWritableStreamEnabled(fileSystemWritableStreamEnabled);
}

void InternalSettingsGenerated::setFilterLinkDecorationByDefaultEnabled(bool filterLinkDecorationByDefaultEnabled)
{
    m_page->settings().setFilterLinkDecorationByDefaultEnabled(filterLinkDecorationByDefaultEnabled);
}

void InternalSettingsGenerated::setFixedBackgroundsPaintRelativeToDocument(bool fixedBackgroundsPaintRelativeToDocument)
{
    m_page->settings().setFixedBackgroundsPaintRelativeToDocument(fixedBackgroundsPaintRelativeToDocument);
}

void InternalSettingsGenerated::setFixedElementsLayoutRelativeToFrame(bool fixedElementsLayoutRelativeToFrame)
{
    m_page->settings().setFixedElementsLayoutRelativeToFrame(fixedElementsLayoutRelativeToFrame);
}

void InternalSettingsGenerated::setFixedFontFamily(const String& fixedFontFamily)
{
    m_page->settings().setFixedFontFamily(fixedFontFamily);
}

void InternalSettingsGenerated::setFlexFormattingContextIntegrationEnabled(bool flexFormattingContextIntegrationEnabled)
{
    m_page->settings().setFlexFormattingContextIntegrationEnabled(flexFormattingContextIntegrationEnabled);
}

void InternalSettingsGenerated::setFontFallbackPrefersPictographs(bool fontFallbackPrefersPictographs)
{
    m_page->settings().setFontFallbackPrefersPictographs(fontFallbackPrefersPictographs);
}

void InternalSettingsGenerated::setForceCompositingMode(bool forceCompositingMode)
{
    m_page->settings().setForceCompositingMode(forceCompositingMode);
}

void InternalSettingsGenerated::setForceFTPDirectoryListings(bool forceFTPDirectoryListings)
{
    m_page->settings().setForceFTPDirectoryListings(forceFTPDirectoryListings);
}

void InternalSettingsGenerated::setForceLockdownFontParserEnabled(bool forceLockdownFontParserEnabled)
{
    m_page->settings().setForceLockdownFontParserEnabled(forceLockdownFontParserEnabled);
}

void InternalSettingsGenerated::setForceWebGLUsesLowPower(bool forceWebGLUsesLowPower)
{
    m_page->settings().setForceWebGLUsesLowPower(forceWebGLUsesLowPower);
}

void InternalSettingsGenerated::setFormControlRefreshEnabled(bool formControlRefreshEnabled)
{
#if ENABLE(FORM_CONTROL_REFRESH)
    m_page->settings().setFormControlRefreshEnabled(formControlRefreshEnabled);
#else
    UNUSED_PARAM(formControlRefreshEnabled);
#endif
}

void InternalSettingsGenerated::setFTPDirectoryTemplatePath(const String& ftpDirectoryTemplatePath)
{
    m_page->settings().setFTPDirectoryTemplatePath(ftpDirectoryTemplatePath);
}

void InternalSettingsGenerated::setFTPEnabled(bool ftpEnabled)
{
    m_page->settings().setFTPEnabled(ftpEnabled);
}

void InternalSettingsGenerated::setFullScreenEnabled(bool fullScreenEnabled)
{
#if ENABLE(FULLSCREEN_API)
    m_page->settings().setFullScreenEnabled(fullScreenEnabled);
#else
    UNUSED_PARAM(fullScreenEnabled);
#endif
}

void InternalSettingsGenerated::setFullScreenKeyboardLock(bool fullScreenKeyboardLock)
{
#if ENABLE(FULLSCREEN_API)
    m_page->settings().setFullScreenKeyboardLock(fullScreenKeyboardLock);
#else
    UNUSED_PARAM(fullScreenKeyboardLock);
#endif
}

void InternalSettingsGenerated::setFullscreenRequirementForScreenOrientationLockingEnabled(bool fullscreenRequirementForScreenOrientationLockingEnabled)
{
    m_page->settings().setFullscreenRequirementForScreenOrientationLockingEnabled(fullscreenRequirementForScreenOrientationLockingEnabled);
}

void InternalSettingsGenerated::setFullscreenSceneAspectRatioLockingEnabled(bool fullscreenSceneAspectRatioLockingEnabled)
{
#if PLATFORM(VISION)
    m_page->settings().setFullscreenSceneAspectRatioLockingEnabled(fullscreenSceneAspectRatioLockingEnabled);
#else
    UNUSED_PARAM(fullscreenSceneAspectRatioLockingEnabled);
#endif
}

void InternalSettingsGenerated::setFullscreenSceneDimmingEnabled(bool fullscreenSceneDimmingEnabled)
{
#if PLATFORM(VISION)
    m_page->settings().setFullscreenSceneDimmingEnabled(fullscreenSceneDimmingEnabled);
#else
    UNUSED_PARAM(fullscreenSceneDimmingEnabled);
#endif
}

void InternalSettingsGenerated::setGamepadTriggerRumbleEnabled(bool gamepadTriggerRumbleEnabled)
{
#if ENABLE(GAMEPAD)
    m_page->settings().setGamepadTriggerRumbleEnabled(gamepadTriggerRumbleEnabled);
#else
    UNUSED_PARAM(gamepadTriggerRumbleEnabled);
#endif
}

void InternalSettingsGenerated::setGamepadVibrationActuatorEnabled(bool gamepadVibrationActuatorEnabled)
{
#if ENABLE(GAMEPAD)
    m_page->settings().setGamepadVibrationActuatorEnabled(gamepadVibrationActuatorEnabled);
#else
    UNUSED_PARAM(gamepadVibrationActuatorEnabled);
#endif
}

void InternalSettingsGenerated::setGamepadsEnabled(bool gamepadsEnabled)
{
#if ENABLE(GAMEPAD)
    m_page->settings().setGamepadsEnabled(gamepadsEnabled);
#else
    UNUSED_PARAM(gamepadsEnabled);
#endif
}

void InternalSettingsGenerated::setGenericCueAPIEnabled(bool genericCueAPIEnabled)
{
#if ENABLE(VIDEO)
    m_page->settings().setGenericCueAPIEnabled(genericCueAPIEnabled);
#else
    UNUSED_PARAM(genericCueAPIEnabled);
#endif
}

void InternalSettingsGenerated::setGeolocationAPIEnabled(bool geolocationAPIEnabled)
{
    m_page->settings().setGeolocationAPIEnabled(geolocationAPIEnabled);
}

void InternalSettingsGenerated::setGeolocationFloorLevelEnabled(bool geolocationFloorLevelEnabled)
{
    m_page->settings().setGeolocationFloorLevelEnabled(geolocationFloorLevelEnabled);
}

void InternalSettingsGenerated::setGetCoalescedEventsEnabled(bool getCoalescedEventsEnabled)
{
    m_page->settings().setGetCoalescedEventsEnabled(getCoalescedEventsEnabled);
}

void InternalSettingsGenerated::setGetPredictedEventsEnabled(bool getPredictedEventsEnabled)
{
    m_page->settings().setGetPredictedEventsEnabled(getPredictedEventsEnabled);
}

void InternalSettingsGenerated::setGetUserMediaRequiresFocus(bool getUserMediaRequiresFocus)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setGetUserMediaRequiresFocus(getUserMediaRequiresFocus);
#else
    UNUSED_PARAM(getUserMediaRequiresFocus);
#endif
}

void InternalSettingsGenerated::setGoogleAntiFlickerOptimizationQuirkEnabled(bool googleAntiFlickerOptimizationQuirkEnabled)
{
    m_page->settings().setGoogleAntiFlickerOptimizationQuirkEnabled(googleAntiFlickerOptimizationQuirkEnabled);
}

void InternalSettingsGenerated::setGraphicsContextFiltersEnabled(bool graphicsContextFiltersEnabled)
{
#if USE(GRAPHICS_CONTEXT_FILTERS)
    m_page->settings().setGraphicsContextFiltersEnabled(graphicsContextFiltersEnabled);
#else
    UNUSED_PARAM(graphicsContextFiltersEnabled);
#endif
}

void InternalSettingsGenerated::setHiddenPageCSSAnimationSuspensionEnabled(bool hiddenPageCSSAnimationSuspensionEnabled)
{
    m_page->settings().setHiddenPageCSSAnimationSuspensionEnabled(hiddenPageCSSAnimationSuspensionEnabled);
}

void InternalSettingsGenerated::setHiddenPageDOMTimerThrottlingAutoIncreases(bool hiddenPageDOMTimerThrottlingAutoIncreases)
{
    m_page->settings().setHiddenPageDOMTimerThrottlingAutoIncreases(hiddenPageDOMTimerThrottlingAutoIncreases);
}

void InternalSettingsGenerated::setHiddenPageDOMTimerThrottlingEnabled(bool hiddenPageDOMTimerThrottlingEnabled)
{
    m_page->settings().setHiddenPageDOMTimerThrottlingEnabled(hiddenPageDOMTimerThrottlingEnabled);
}

void InternalSettingsGenerated::setHiddenUntilFoundEnabled(bool hiddenUntilFoundEnabled)
{
    m_page->settings().setHiddenUntilFoundEnabled(hiddenUntilFoundEnabled);
}

void InternalSettingsGenerated::setHostedBlurMaterialInMediaControlsEnabled(bool hostedBlurMaterialInMediaControlsEnabled)
{
#if HAVE(MATERIAL_HOSTING)
    m_page->settings().setHostedBlurMaterialInMediaControlsEnabled(hostedBlurMaterialInMediaControlsEnabled);
#else
    UNUSED_PARAM(hostedBlurMaterialInMediaControlsEnabled);
#endif
}

void InternalSettingsGenerated::setHTMLLegacyAttributeValueSerializationEnabled(bool htmlLegacyAttributeValueSerializationEnabled)
{
    m_page->settings().setHTMLLegacyAttributeValueSerializationEnabled(htmlLegacyAttributeValueSerializationEnabled);
}

void InternalSettingsGenerated::setHttpEquivEnabled(bool httpEquivEnabled)
{
    m_page->settings().setHttpEquivEnabled(httpEquivEnabled);
}

void InternalSettingsGenerated::setHttpsByDefault(bool httpsByDefault)
{
    m_page->settings().setHttpsByDefault(httpsByDefault);
}

void InternalSettingsGenerated::setIFrameResourceMonitoringEnabled(bool iFrameResourceMonitoringEnabled)
{
#if ENABLE(CONTENT_EXTENSIONS)
    m_page->settings().setIFrameResourceMonitoringEnabled(iFrameResourceMonitoringEnabled);
#else
    UNUSED_PARAM(iFrameResourceMonitoringEnabled);
#endif
}

void InternalSettingsGenerated::setIFrameResourceMonitoringTestingSettingsEnabled(bool iFrameResourceMonitoringTestingSettingsEnabled)
{
#if ENABLE(CONTENT_EXTENSIONS)
    m_page->settings().setIFrameResourceMonitoringTestingSettingsEnabled(iFrameResourceMonitoringTestingSettingsEnabled);
#else
    UNUSED_PARAM(iFrameResourceMonitoringTestingSettingsEnabled);
#endif
}

void InternalSettingsGenerated::setIOSurfaceLosslessCompressionEnabled(bool iOSurfaceLosslessCompressionEnabled)
{
    m_page->settings().setIOSurfaceLosslessCompressionEnabled(iOSurfaceLosslessCompressionEnabled);
}

void InternalSettingsGenerated::setIPAddressAndLocalhostMixedContentUpgradeTestingEnabled(bool iPAddressAndLocalhostMixedContentUpgradeTestingEnabled)
{
    m_page->settings().setIPAddressAndLocalhostMixedContentUpgradeTestingEnabled(iPAddressAndLocalhostMixedContentUpgradeTestingEnabled);
}

void InternalSettingsGenerated::setICECandidateFilteringEnabled(bool iceCandidateFilteringEnabled)
{
    m_page->settings().setICECandidateFilteringEnabled(iceCandidateFilteringEnabled);
}

void InternalSettingsGenerated::setIdempotentModeAutosizingOnlyHonorsPercentages(bool idempotentModeAutosizingOnlyHonorsPercentages)
{
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setIdempotentModeAutosizingOnlyHonorsPercentages(idempotentModeAutosizingOnlyHonorsPercentages);
#else
    UNUSED_PARAM(idempotentModeAutosizingOnlyHonorsPercentages);
#endif
}

void InternalSettingsGenerated::setIgnoreIframeEmbeddingProtectionsEnabled(bool ignoreIframeEmbeddingProtectionsEnabled)
{
    m_page->settings().setIgnoreIframeEmbeddingProtectionsEnabled(ignoreIframeEmbeddingProtectionsEnabled);
}

void InternalSettingsGenerated::setImageAnalysisDuringFindInPageEnabled(bool imageAnalysisDuringFindInPageEnabled)
{
#if ENABLE(IMAGE_ANALYSIS)
    m_page->settings().setImageAnalysisDuringFindInPageEnabled(imageAnalysisDuringFindInPageEnabled);
#else
    UNUSED_PARAM(imageAnalysisDuringFindInPageEnabled);
#endif
}

void InternalSettingsGenerated::setImageAnimationControlEnabled(bool imageAnimationControlEnabled)
{
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    m_page->settings().setImageAnimationControlEnabled(imageAnimationControlEnabled);
#else
    UNUSED_PARAM(imageAnimationControlEnabled);
#endif
}

void InternalSettingsGenerated::setImageCaptureEnabled(bool imageCaptureEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setImageCaptureEnabled(imageCaptureEnabled);
#else
    UNUSED_PARAM(imageCaptureEnabled);
#endif
}

void InternalSettingsGenerated::setImageControlsEnabled(bool imageControlsEnabled)
{
#if ENABLE(SERVICE_CONTROLS)
    m_page->settings().setImageControlsEnabled(imageControlsEnabled);
#else
    UNUSED_PARAM(imageControlsEnabled);
#endif
}

void InternalSettingsGenerated::setImageSubsamplingEnabled(bool imageSubsamplingEnabled)
{
    m_page->settings().setImageSubsamplingEnabled(imageSubsamplingEnabled);
}

void InternalSettingsGenerated::setImagesEnabled(bool imagesEnabled)
{
    m_page->settings().setImagesEnabled(imagesEnabled);
}

void InternalSettingsGenerated::setInWindowFullscreenEnabled(bool inWindowFullscreenEnabled)
{
    m_page->settings().setInWindowFullscreenEnabled(inWindowFullscreenEnabled);
}

void InternalSettingsGenerated::setIncludeIgnoredInCoreAXTree(bool includeIgnoredInCoreAXTree)
{
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
    m_page->settings().setIncludeIgnoredInCoreAXTree(includeIgnoredInCoreAXTree);
#else
    UNUSED_PARAM(includeIgnoredInCoreAXTree);
#endif
}

void InternalSettingsGenerated::setIncompleteImageBorderEnabled(bool incompleteImageBorderEnabled)
{
    m_page->settings().setIncompleteImageBorderEnabled(incompleteImageBorderEnabled);
}

void InternalSettingsGenerated::setIncrementalPDFLoadingEnabled(bool incrementalPDFLoadingEnabled)
{
#if HAVE(INCREMENTAL_PDF_APIS)
    m_page->settings().setIncrementalPDFLoadingEnabled(incrementalPDFLoadingEnabled);
#else
    UNUSED_PARAM(incrementalPDFLoadingEnabled);
#endif
}

void InternalSettingsGenerated::setIncrementalRenderingSuppressionTimeoutInSeconds(double incrementalRenderingSuppressionTimeoutInSeconds)
{
    m_page->settings().setIncrementalRenderingSuppressionTimeoutInSeconds(incrementalRenderingSuppressionTimeoutInSeconds);
}

void InternalSettingsGenerated::setIndexedDBAPIEnabled(bool indexedDBAPIEnabled)
{
    m_page->settings().setIndexedDBAPIEnabled(indexedDBAPIEnabled);
}

void InternalSettingsGenerated::setInlineMediaPlaybackRequiresPlaysInlineAttribute(bool inlineMediaPlaybackRequiresPlaysInlineAttribute)
{
    m_page->settings().setInlineMediaPlaybackRequiresPlaysInlineAttribute(inlineMediaPlaybackRequiresPlaysInlineAttribute);
}

void InternalSettingsGenerated::setInputMethodUsesCorrectKeyEventOrder(bool inputMethodUsesCorrectKeyEventOrder)
{
#if PLATFORM(MAC)
    m_page->settings().setInputMethodUsesCorrectKeyEventOrder(inputMethodUsesCorrectKeyEventOrder);
#else
    UNUSED_PARAM(inputMethodUsesCorrectKeyEventOrder);
#endif
}

void InternalSettingsGenerated::setInputTypeColorEnabled(bool inputTypeColorEnabled)
{
    m_page->settings().setInputTypeColorEnabled(inputTypeColorEnabled);
}

void InternalSettingsGenerated::setInputTypeColorEnhancementsEnabled(bool inputTypeColorEnhancementsEnabled)
{
    m_page->settings().setInputTypeColorEnhancementsEnabled(inputTypeColorEnhancementsEnabled);
}

void InternalSettingsGenerated::setInputTypeDateEnabled(bool inputTypeDateEnabled)
{
    m_page->settings().setInputTypeDateEnabled(inputTypeDateEnabled);
}

void InternalSettingsGenerated::setInputTypeDateTimeLocalEnabled(bool inputTypeDateTimeLocalEnabled)
{
    m_page->settings().setInputTypeDateTimeLocalEnabled(inputTypeDateTimeLocalEnabled);
}

void InternalSettingsGenerated::setInputTypeMonthEnabled(bool inputTypeMonthEnabled)
{
    m_page->settings().setInputTypeMonthEnabled(inputTypeMonthEnabled);
}

void InternalSettingsGenerated::setInputTypeTimeEnabled(bool inputTypeTimeEnabled)
{
    m_page->settings().setInputTypeTimeEnabled(inputTypeTimeEnabled);
}

void InternalSettingsGenerated::setInputTypeWeekEnabled(bool inputTypeWeekEnabled)
{
    m_page->settings().setInputTypeWeekEnabled(inputTypeWeekEnabled);
}

void InternalSettingsGenerated::setInspectorMaximumResourcesContentSize(uint32_t inspectorMaximumResourcesContentSize)
{
    m_page->settings().setInspectorMaximumResourcesContentSize(inspectorMaximumResourcesContentSize);
}

void InternalSettingsGenerated::setInspectorSupportsShowingCertificate(bool inspectorSupportsShowingCertificate)
{
    m_page->settings().setInspectorSupportsShowingCertificate(inspectorSupportsShowingCertificate);
}

void InternalSettingsGenerated::setInteractionRegionInlinePadding(double interactionRegionInlinePadding)
{
    m_page->settings().setInteractionRegionInlinePadding(interactionRegionInlinePadding);
}

void InternalSettingsGenerated::setInteractionRegionMinimumCornerRadius(double interactionRegionMinimumCornerRadius)
{
    m_page->settings().setInteractionRegionMinimumCornerRadius(interactionRegionMinimumCornerRadius);
}

void InternalSettingsGenerated::setInteractionRegionsEnabled(bool interactionRegionsEnabled)
{
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    m_page->settings().setInteractionRegionsEnabled(interactionRegionsEnabled);
#else
    UNUSED_PARAM(interactionRegionsEnabled);
#endif
}

void InternalSettingsGenerated::setInteractiveFormValidationEnabled(bool interactiveFormValidationEnabled)
{
    m_page->settings().setInteractiveFormValidationEnabled(interactiveFormValidationEnabled);
}

void InternalSettingsGenerated::setInterruptAudioOnPageVisibilityChangeEnabled(bool interruptAudioOnPageVisibilityChangeEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setInterruptAudioOnPageVisibilityChangeEnabled(interruptAudioOnPageVisibilityChangeEnabled);
#else
    UNUSED_PARAM(interruptAudioOnPageVisibilityChangeEnabled);
#endif
}

void InternalSettingsGenerated::setInterruptVideoOnPageVisibilityChangeEnabled(bool interruptVideoOnPageVisibilityChangeEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setInterruptVideoOnPageVisibilityChangeEnabled(interruptVideoOnPageVisibilityChangeEnabled);
#else
    UNUSED_PARAM(interruptVideoOnPageVisibilityChangeEnabled);
#endif
}

void InternalSettingsGenerated::setInvisibleAutoplayNotPermitted(bool invisibleAutoplayNotPermitted)
{
    m_page->settings().setInvisibleAutoplayNotPermitted(invisibleAutoplayNotPermitted);
}

void InternalSettingsGenerated::setIsFirstPartyWebsiteDataRemovalDisabled(bool isFirstPartyWebsiteDataRemovalDisabled)
{
    m_page->settings().setIsFirstPartyWebsiteDataRemovalDisabled(isFirstPartyWebsiteDataRemovalDisabled);
}

void InternalSettingsGenerated::setIsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled(bool isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled)
{
    m_page->settings().setIsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled(isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled);
}

void InternalSettingsGenerated::setIsFirstPartyWebsiteDataRemovalReproTestingEnabled(bool isFirstPartyWebsiteDataRemovalReproTestingEnabled)
{
    m_page->settings().setIsFirstPartyWebsiteDataRemovalReproTestingEnabled(isFirstPartyWebsiteDataRemovalReproTestingEnabled);
}

void InternalSettingsGenerated::setIsPerActivityStateCPUUsageMeasurementEnabled(bool isPerActivityStateCPUUsageMeasurementEnabled)
{
    m_page->settings().setIsPerActivityStateCPUUsageMeasurementEnabled(isPerActivityStateCPUUsageMeasurementEnabled);
}

void InternalSettingsGenerated::setIsPostBackgroundingCPUUsageMeasurementEnabled(bool isPostBackgroundingCPUUsageMeasurementEnabled)
{
    m_page->settings().setIsPostBackgroundingCPUUsageMeasurementEnabled(isPostBackgroundingCPUUsageMeasurementEnabled);
}

void InternalSettingsGenerated::setIsPostBackgroundingMemoryUsageMeasurementEnabled(bool isPostBackgroundingMemoryUsageMeasurementEnabled)
{
    m_page->settings().setIsPostBackgroundingMemoryUsageMeasurementEnabled(isPostBackgroundingMemoryUsageMeasurementEnabled);
}

void InternalSettingsGenerated::setIsPostLoadCPUUsageMeasurementEnabled(bool isPostLoadCPUUsageMeasurementEnabled)
{
    m_page->settings().setIsPostLoadCPUUsageMeasurementEnabled(isPostLoadCPUUsageMeasurementEnabled);
}

void InternalSettingsGenerated::setIsPostLoadMemoryUsageMeasurementEnabled(bool isPostLoadMemoryUsageMeasurementEnabled)
{
    m_page->settings().setIsPostLoadMemoryUsageMeasurementEnabled(isPostLoadMemoryUsageMeasurementEnabled);
}

void InternalSettingsGenerated::setIsSameSiteStrictEnforcementEnabled(bool isSameSiteStrictEnforcementEnabled)
{
    m_page->settings().setIsSameSiteStrictEnforcementEnabled(isSameSiteStrictEnforcementEnabled);
}

void InternalSettingsGenerated::setIsThirdPartyCookieBlockingDisabled(bool isThirdPartyCookieBlockingDisabled)
{
    m_page->settings().setIsThirdPartyCookieBlockingDisabled(isThirdPartyCookieBlockingDisabled);
}

void InternalSettingsGenerated::setItpDebugModeEnabled(bool itpDebugModeEnabled)
{
    m_page->settings().setItpDebugModeEnabled(itpDebugModeEnabled);
}

void InternalSettingsGenerated::setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard)
{
    m_page->settings().setJavaScriptCanAccessClipboard(javaScriptCanAccessClipboard);
}

void InternalSettingsGenerated::setJavaScriptCanOpenWindowsAutomatically(bool javaScriptCanOpenWindowsAutomatically)
{
    m_page->settings().setJavaScriptCanOpenWindowsAutomatically(javaScriptCanOpenWindowsAutomatically);
}

void InternalSettingsGenerated::setLangAttributeAwareFormControlUIEnabled(bool langAttributeAwareFormControlUIEnabled)
{
    m_page->settings().setLangAttributeAwareFormControlUIEnabled(langAttributeAwareFormControlUIEnabled);
}

void InternalSettingsGenerated::setLargeImageAsyncDecodingEnabled(bool largeImageAsyncDecodingEnabled)
{
    m_page->settings().setLargeImageAsyncDecodingEnabled(largeImageAsyncDecodingEnabled);
}

void InternalSettingsGenerated::setLayerBasedSVGEngineEnabled(bool layerBasedSVGEngineEnabled)
{
    m_page->settings().setLayerBasedSVGEngineEnabled(layerBasedSVGEngineEnabled);
}

void InternalSettingsGenerated::setLayoutFallbackWidth(uint32_t layoutFallbackWidth)
{
    m_page->settings().setLayoutFallbackWidth(layoutFallbackWidth);
}

void InternalSettingsGenerated::setLayoutViewportHeightExpansionFactor(double layoutViewportHeightExpansionFactor)
{
    m_page->settings().setLayoutViewportHeightExpansionFactor(layoutViewportHeightExpansionFactor);
}

void InternalSettingsGenerated::setLazyIframeLoadingEnabled(bool lazyIframeLoadingEnabled)
{
    m_page->settings().setLazyIframeLoadingEnabled(lazyIframeLoadingEnabled);
}

void InternalSettingsGenerated::setLazyImageLoadingEnabled(bool lazyImageLoadingEnabled)
{
    m_page->settings().setLazyImageLoadingEnabled(lazyImageLoadingEnabled);
}

void InternalSettingsGenerated::setLegacyEncryptedMediaAPIEnabled(bool legacyEncryptedMediaAPIEnabled)
{
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    m_page->settings().setLegacyEncryptedMediaAPIEnabled(legacyEncryptedMediaAPIEnabled);
#else
    UNUSED_PARAM(legacyEncryptedMediaAPIEnabled);
#endif
}

void InternalSettingsGenerated::setLegacyLineLayoutVisualCoverageEnabled(bool legacyLineLayoutVisualCoverageEnabled)
{
    m_page->settings().setLegacyLineLayoutVisualCoverageEnabled(legacyLineLayoutVisualCoverageEnabled);
}

void InternalSettingsGenerated::setLegacyOverflowScrollingTouchEnabled(bool legacyOverflowScrollingTouchEnabled)
{
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
    m_page->settings().setLegacyOverflowScrollingTouchEnabled(legacyOverflowScrollingTouchEnabled);
#else
    UNUSED_PARAM(legacyOverflowScrollingTouchEnabled);
#endif
}

void InternalSettingsGenerated::setLegacyPluginQuirkForMailSignaturesEnabled(bool legacyPluginQuirkForMailSignaturesEnabled)
{
    m_page->settings().setLegacyPluginQuirkForMailSignaturesEnabled(legacyPluginQuirkForMailSignaturesEnabled);
}

void InternalSettingsGenerated::setLegacyWebRTCOfferOptionsEnabled(bool legacyWebRTCOfferOptionsEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setLegacyWebRTCOfferOptionsEnabled(legacyWebRTCOfferOptionsEnabled);
#else
    UNUSED_PARAM(legacyWebRTCOfferOptionsEnabled);
#endif
}

void InternalSettingsGenerated::setLimitedMatroskaSupportEnabled(bool limitedMatroskaSupportEnabled)
{
#if ENABLE(MEDIA_RECORDER_WEBM)
    m_page->settings().setLimitedMatroskaSupportEnabled(limitedMatroskaSupportEnabled);
#else
    UNUSED_PARAM(limitedMatroskaSupportEnabled);
#endif
}

void InternalSettingsGenerated::setLinearMediaPlayerEnabled(bool linearMediaPlayerEnabled)
{
#if ENABLE(LINEAR_MEDIA_PLAYER)
    m_page->settings().setLinearMediaPlayerEnabled(linearMediaPlayerEnabled);
#else
    UNUSED_PARAM(linearMediaPlayerEnabled);
#endif
}

void InternalSettingsGenerated::setLinkDNSPrefetchEnabled(bool linkDNSPrefetchEnabled)
{
    m_page->settings().setLinkDNSPrefetchEnabled(linkDNSPrefetchEnabled);
}

void InternalSettingsGenerated::setLinkPreconnectEarlyHintsEnabled(bool linkPreconnectEarlyHintsEnabled)
{
    m_page->settings().setLinkPreconnectEarlyHintsEnabled(linkPreconnectEarlyHintsEnabled);
}

void InternalSettingsGenerated::setLinkPreconnectEnabled(bool linkPreconnectEnabled)
{
    m_page->settings().setLinkPreconnectEnabled(linkPreconnectEnabled);
}

void InternalSettingsGenerated::setLinkPrefetchEnabled(bool linkPrefetchEnabled)
{
    m_page->settings().setLinkPrefetchEnabled(linkPrefetchEnabled);
}

void InternalSettingsGenerated::setLinkPreloadEnabled(bool linkPreloadEnabled)
{
    m_page->settings().setLinkPreloadEnabled(linkPreloadEnabled);
}

void InternalSettingsGenerated::setLinkSanitizerEnabled(bool linkSanitizerEnabled)
{
    m_page->settings().setLinkSanitizerEnabled(linkSanitizerEnabled);
}

void InternalSettingsGenerated::setLoadDeferringEnabled(bool loadDeferringEnabled)
{
    m_page->settings().setLoadDeferringEnabled(loadDeferringEnabled);
}

void InternalSettingsGenerated::setLoadWebArchiveWithEphemeralStorageEnabled(bool loadWebArchiveWithEphemeralStorageEnabled)
{
#if ENABLE(WEB_ARCHIVE)
    m_page->settings().setLoadWebArchiveWithEphemeralStorageEnabled(loadWebArchiveWithEphemeralStorageEnabled);
#else
    UNUSED_PARAM(loadWebArchiveWithEphemeralStorageEnabled);
#endif
}

void InternalSettingsGenerated::setLoadsImagesAutomatically(bool loadsImagesAutomatically)
{
    m_page->settings().setLoadsImagesAutomatically(loadsImagesAutomatically);
}

void InternalSettingsGenerated::setLocalFileContentSniffingEnabled(bool localFileContentSniffingEnabled)
{
    m_page->settings().setLocalFileContentSniffingEnabled(localFileContentSniffingEnabled);
}

void InternalSettingsGenerated::setLocalNetworkAccessEnabled(bool localNetworkAccessEnabled)
{
    m_page->settings().setLocalNetworkAccessEnabled(localNetworkAccessEnabled);
}

void InternalSettingsGenerated::setLocalStorageDatabasePath(const String& localStorageDatabasePath)
{
    m_page->settings().setLocalStorageDatabasePath(localStorageDatabasePath);
}

void InternalSettingsGenerated::setLocalStorageEnabled(bool localStorageEnabled)
{
    m_page->settings().setLocalStorageEnabled(localStorageEnabled);
}

void InternalSettingsGenerated::setLockdownFontParserEnabled(bool lockdownFontParserEnabled)
{
    m_page->settings().setLockdownFontParserEnabled(lockdownFontParserEnabled);
}

void InternalSettingsGenerated::setLoginStatusAPIEnabled(bool loginStatusAPIEnabled)
{
    m_page->settings().setLoginStatusAPIEnabled(loginStatusAPIEnabled);
}

void InternalSettingsGenerated::setLoginStatusAPIRequiresWebAuthnEnabled(bool loginStatusAPIRequiresWebAuthnEnabled)
{
    m_page->settings().setLoginStatusAPIRequiresWebAuthnEnabled(loginStatusAPIRequiresWebAuthnEnabled);
}

void InternalSettingsGenerated::setLogsPageMessagesToSystemConsoleEnabled(bool logsPageMessagesToSystemConsoleEnabled)
{
    m_page->settings().setLogsPageMessagesToSystemConsoleEnabled(logsPageMessagesToSystemConsoleEnabled);
}

void InternalSettingsGenerated::setMainContentUserGestureOverrideEnabled(bool mainContentUserGestureOverrideEnabled)
{
    m_page->settings().setMainContentUserGestureOverrideEnabled(mainContentUserGestureOverrideEnabled);
}

void InternalSettingsGenerated::setManageCaptureStatusBarInGPUProcessEnabled(bool manageCaptureStatusBarInGPUProcessEnabled)
{
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
    m_page->settings().setManageCaptureStatusBarInGPUProcessEnabled(manageCaptureStatusBarInGPUProcessEnabled);
#else
    UNUSED_PARAM(manageCaptureStatusBarInGPUProcessEnabled);
#endif
}

void InternalSettingsGenerated::setManagedMediaSourceEnabled(bool managedMediaSourceEnabled)
{
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setManagedMediaSourceEnabled(managedMediaSourceEnabled);
#else
    UNUSED_PARAM(managedMediaSourceEnabled);
#endif
}

void InternalSettingsGenerated::setManagedMediaSourceHighThreshold(double managedMediaSourceHighThreshold)
{
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setManagedMediaSourceHighThreshold(managedMediaSourceHighThreshold);
#else
    UNUSED_PARAM(managedMediaSourceHighThreshold);
#endif
}

void InternalSettingsGenerated::setManagedMediaSourceLowThreshold(double managedMediaSourceLowThreshold)
{
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setManagedMediaSourceLowThreshold(managedMediaSourceLowThreshold);
#else
    UNUSED_PARAM(managedMediaSourceLowThreshold);
#endif
}

void InternalSettingsGenerated::setManagedMediaSourceNeedsAirPlay(bool managedMediaSourceNeedsAirPlay)
{
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
    m_page->settings().setManagedMediaSourceNeedsAirPlay(managedMediaSourceNeedsAirPlay);
#else
    UNUSED_PARAM(managedMediaSourceNeedsAirPlay);
#endif
}

void InternalSettingsGenerated::setMasonryEnabled(bool masonryEnabled)
{
    m_page->settings().setMasonryEnabled(masonryEnabled);
}

void InternalSettingsGenerated::setMathMLEnabled(bool mathMLEnabled)
{
#if ENABLE(MATHML)
    m_page->settings().setMathMLEnabled(mathMLEnabled);
#else
    UNUSED_PARAM(mathMLEnabled);
#endif
}

void InternalSettingsGenerated::setMaxParseDuration(double maxParseDuration)
{
    m_page->settings().setMaxParseDuration(maxParseDuration);
}

void InternalSettingsGenerated::setMaximumHTMLParserDOMTreeDepth(uint32_t maximumHTMLParserDOMTreeDepth)
{
    m_page->settings().setMaximumHTMLParserDOMTreeDepth(maximumHTMLParserDOMTreeDepth);
}

void InternalSettingsGenerated::setMaximumSourceBufferSize(uint32_t maximumSourceBufferSize)
{
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setMaximumSourceBufferSize(maximumSourceBufferSize);
#else
    UNUSED_PARAM(maximumSourceBufferSize);
#endif
}

void InternalSettingsGenerated::setMediaCapabilitiesEnabled(bool mediaCapabilitiesEnabled)
{
    m_page->settings().setMediaCapabilitiesEnabled(mediaCapabilitiesEnabled);
}

void InternalSettingsGenerated::setMediaCapabilitiesExtensionsEnabled(bool mediaCapabilitiesExtensionsEnabled)
{
    m_page->settings().setMediaCapabilitiesExtensionsEnabled(mediaCapabilitiesExtensionsEnabled);
}

void InternalSettingsGenerated::setMediaCapabilityGrantsEnabled(bool mediaCapabilityGrantsEnabled)
{
#if ENABLE(EXTENSION_CAPABILITIES)
    m_page->settings().setMediaCapabilityGrantsEnabled(mediaCapabilityGrantsEnabled);
#else
    UNUSED_PARAM(mediaCapabilityGrantsEnabled);
#endif
}

void InternalSettingsGenerated::setMediaCaptureRequiresSecureConnection(bool mediaCaptureRequiresSecureConnection)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMediaCaptureRequiresSecureConnection(mediaCaptureRequiresSecureConnection);
#else
    UNUSED_PARAM(mediaCaptureRequiresSecureConnection);
#endif
}

void InternalSettingsGenerated::setMediaControlsContextMenusEnabled(bool mediaControlsContextMenusEnabled)
{
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
    m_page->settings().setMediaControlsContextMenusEnabled(mediaControlsContextMenusEnabled);
#else
    UNUSED_PARAM(mediaControlsContextMenusEnabled);
#endif
}

void InternalSettingsGenerated::setMediaControlsScaleWithPageZoom(bool mediaControlsScaleWithPageZoom)
{
    m_page->settings().setMediaControlsScaleWithPageZoom(mediaControlsScaleWithPageZoom);
}

void InternalSettingsGenerated::setMediaDataLoadsAutomatically(bool mediaDataLoadsAutomatically)
{
    m_page->settings().setMediaDataLoadsAutomatically(mediaDataLoadsAutomatically);
}

void InternalSettingsGenerated::setMediaDevicesEnabled(bool mediaDevicesEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMediaDevicesEnabled(mediaDevicesEnabled);
#else
    UNUSED_PARAM(mediaDevicesEnabled);
#endif
}

void InternalSettingsGenerated::setMediaEnabled(bool mediaEnabled)
{
#if ENABLE(VIDEO)
    m_page->settings().setMediaEnabled(mediaEnabled);
#else
    UNUSED_PARAM(mediaEnabled);
#endif
}

void InternalSettingsGenerated::setMediaKeysStorageDirectory(const String& mediaKeysStorageDirectory)
{
    m_page->settings().setMediaKeysStorageDirectory(mediaKeysStorageDirectory);
}

void InternalSettingsGenerated::setMediaPlaybackEnabled(bool mediaPlaybackEnabled)
{
    m_page->settings().setMediaPlaybackEnabled(mediaPlaybackEnabled);
}

void InternalSettingsGenerated::setMediaPreferredFullscreenWidth(double mediaPreferredFullscreenWidth)
{
    m_page->settings().setMediaPreferredFullscreenWidth(mediaPreferredFullscreenWidth);
}

void InternalSettingsGenerated::setMediaPreloadingEnabled(bool mediaPreloadingEnabled)
{
    m_page->settings().setMediaPreloadingEnabled(mediaPreloadingEnabled);
}

void InternalSettingsGenerated::setMediaRecorderEnabled(bool mediaRecorderEnabled)
{
#if ENABLE(MEDIA_RECORDER)
    m_page->settings().setMediaRecorderEnabled(mediaRecorderEnabled);
#else
    UNUSED_PARAM(mediaRecorderEnabled);
#endif
}

void InternalSettingsGenerated::setMediaRecorderEnabledWebM(bool mediaRecorderEnabledWebM)
{
#if ENABLE(MEDIA_RECORDER_WEBM)
    m_page->settings().setMediaRecorderEnabledWebM(mediaRecorderEnabledWebM);
#else
    UNUSED_PARAM(mediaRecorderEnabledWebM);
#endif
}

void InternalSettingsGenerated::setMediaSessionCaptureToggleAPIEnabled(bool mediaSessionCaptureToggleAPIEnabled)
{
    m_page->settings().setMediaSessionCaptureToggleAPIEnabled(mediaSessionCaptureToggleAPIEnabled);
}

void InternalSettingsGenerated::setMediaSessionCoordinatorEnabled(bool mediaSessionCoordinatorEnabled)
{
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    m_page->settings().setMediaSessionCoordinatorEnabled(mediaSessionCoordinatorEnabled);
#else
    UNUSED_PARAM(mediaSessionCoordinatorEnabled);
#endif
}

void InternalSettingsGenerated::setMediaSessionEnabled(bool mediaSessionEnabled)
{
#if ENABLE(MEDIA_SESSION)
    m_page->settings().setMediaSessionEnabled(mediaSessionEnabled);
#else
    UNUSED_PARAM(mediaSessionEnabled);
#endif
}

void InternalSettingsGenerated::setMediaSessionPlaylistEnabled(bool mediaSessionPlaylistEnabled)
{
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
    m_page->settings().setMediaSessionPlaylistEnabled(mediaSessionPlaylistEnabled);
#else
    UNUSED_PARAM(mediaSessionPlaylistEnabled);
#endif
}

void InternalSettingsGenerated::setMediaSourceEnabled(bool mediaSourceEnabled)
{
    m_page->settings().setMediaSourceEnabled(mediaSourceEnabled);
}

void InternalSettingsGenerated::setMediaSourceInWorkerEnabled(bool mediaSourceInWorkerEnabled)
{
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
    m_page->settings().setMediaSourceInWorkerEnabled(mediaSourceInWorkerEnabled);
#else
    UNUSED_PARAM(mediaSourceInWorkerEnabled);
#endif
}

void InternalSettingsGenerated::setMediaSourcePrefersDecompressionSession(bool mediaSourcePrefersDecompressionSession)
{
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
    m_page->settings().setMediaSourcePrefersDecompressionSession(mediaSourcePrefersDecompressionSession);
#else
    UNUSED_PARAM(mediaSourcePrefersDecompressionSession);
#endif
}

void InternalSettingsGenerated::setMediaStreamTrackProcessingEnabled(bool mediaStreamTrackProcessingEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMediaStreamTrackProcessingEnabled(mediaStreamTrackProcessingEnabled);
#else
    UNUSED_PARAM(mediaStreamTrackProcessingEnabled);
#endif
}

void InternalSettingsGenerated::setMediaTypeOverride(const String& mediaTypeOverride)
{
    m_page->settings().setMediaTypeOverride(mediaTypeOverride);
}

void InternalSettingsGenerated::setMediaUserGestureInheritsFromDocument(bool mediaUserGestureInheritsFromDocument)
{
    m_page->settings().setMediaUserGestureInheritsFromDocument(mediaUserGestureInheritsFromDocument);
}

void InternalSettingsGenerated::setMetaViewportInteractiveWidgetEnabled(bool metaViewportInteractiveWidgetEnabled)
{
    m_page->settings().setMetaViewportInteractiveWidgetEnabled(metaViewportInteractiveWidgetEnabled);
}

void InternalSettingsGenerated::setMinimumFontSize(double minimumFontSize)
{
    m_page->settings().setMinimumFontSize(minimumFontSize);
}

void InternalSettingsGenerated::setMinimumLogicalFontSize(double minimumLogicalFontSize)
{
    m_page->settings().setMinimumLogicalFontSize(minimumLogicalFontSize);
}

void InternalSettingsGenerated::setMinimumZoomFontSize(double minimumZoomFontSize)
{
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setMinimumZoomFontSize(minimumZoomFontSize);
#else
    UNUSED_PARAM(minimumZoomFontSize);
#endif
}

void InternalSettingsGenerated::setMockCaptureDevicesEnabled(bool mockCaptureDevicesEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMockCaptureDevicesEnabled(mockCaptureDevicesEnabled);
#else
    UNUSED_PARAM(mockCaptureDevicesEnabled);
#endif
}

void InternalSettingsGenerated::setMockScrollbarsControllerEnabled(bool mockScrollbarsControllerEnabled)
{
    m_page->settings().setMockScrollbarsControllerEnabled(mockScrollbarsControllerEnabled);
}

void InternalSettingsGenerated::setModelElementEnabled(bool modelElementEnabled)
{
#if ENABLE(MODEL_ELEMENT)
    m_page->settings().setModelElementEnabled(modelElementEnabled);
#else
    UNUSED_PARAM(modelElementEnabled);
#endif
}

void InternalSettingsGenerated::setModelNoPortalAttributeEnabled(bool modelNoPortalAttributeEnabled)
{
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    m_page->settings().setModelNoPortalAttributeEnabled(modelNoPortalAttributeEnabled);
#else
    UNUSED_PARAM(modelNoPortalAttributeEnabled);
#endif
}

void InternalSettingsGenerated::setModelProcessEnabled(bool modelProcessEnabled)
{
#if ENABLE(MODEL_PROCESS)
    m_page->settings().setModelProcessEnabled(modelProcessEnabled);
#else
    UNUSED_PARAM(modelProcessEnabled);
#endif
}

void InternalSettingsGenerated::setMomentumScrollingAnimatorEnabled(bool momentumScrollingAnimatorEnabled)
{
    m_page->settings().setMomentumScrollingAnimatorEnabled(momentumScrollingAnimatorEnabled);
}

void InternalSettingsGenerated::setMouseEventsSimulationEnabled(bool mouseEventsSimulationEnabled)
{
#if ENABLE(TOUCH_EVENTS)
    m_page->settings().setMouseEventsSimulationEnabled(mouseEventsSimulationEnabled);
#else
    UNUSED_PARAM(mouseEventsSimulationEnabled);
#endif
}

void InternalSettingsGenerated::setMutationEventsEnabled(bool mutationEventsEnabled)
{
    m_page->settings().setMutationEventsEnabled(mutationEventsEnabled);
}

void InternalSettingsGenerated::setMuteCameraOnMicrophoneInterruptionEnabled(bool muteCameraOnMicrophoneInterruptionEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setMuteCameraOnMicrophoneInterruptionEnabled(muteCameraOnMicrophoneInterruptionEnabled);
#else
    UNUSED_PARAM(muteCameraOnMicrophoneInterruptionEnabled);
#endif
}

void InternalSettingsGenerated::setNavigationAPIEnabled(bool navigationAPIEnabled)
{
    m_page->settings().setNavigationAPIEnabled(navigationAPIEnabled);
}

void InternalSettingsGenerated::setNavigatorUserAgentDataJavaScriptAPIEnabled(bool navigatorUserAgentDataJavaScriptAPIEnabled)
{
    m_page->settings().setNavigatorUserAgentDataJavaScriptAPIEnabled(navigatorUserAgentDataJavaScriptAPIEnabled);
}

void InternalSettingsGenerated::setNeedsAdobeFrameReloadingQuirk(bool needsAdobeFrameReloadingQuirk)
{
    m_page->settings().setNeedsAdobeFrameReloadingQuirk(needsAdobeFrameReloadingQuirk);
}

void InternalSettingsGenerated::setNeedsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk(bool needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk)
{
    m_page->settings().setNeedsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk(needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk);
}

void InternalSettingsGenerated::setNeedsFrameNameFallbackToIdQuirk(bool needsFrameNameFallbackToIdQuirk)
{
    m_page->settings().setNeedsFrameNameFallbackToIdQuirk(needsFrameNameFallbackToIdQuirk);
}

void InternalSettingsGenerated::setNeedsKeyboardEventDisambiguationQuirks(bool needsKeyboardEventDisambiguationQuirks)
{
    m_page->settings().setNeedsKeyboardEventDisambiguationQuirks(needsKeyboardEventDisambiguationQuirks);
}

void InternalSettingsGenerated::setNeedsSiteSpecificQuirks(bool needsSiteSpecificQuirks)
{
    m_page->settings().setNeedsSiteSpecificQuirks(needsSiteSpecificQuirks);
}

void InternalSettingsGenerated::setNeedsStorageAccessFromFileURLsQuirk(bool needsStorageAccessFromFileURLsQuirk)
{
    m_page->settings().setNeedsStorageAccessFromFileURLsQuirk(needsStorageAccessFromFileURLsQuirk);
}

void InternalSettingsGenerated::setNotificationEventEnabled(bool notificationEventEnabled)
{
#if ENABLE(NOTIFICATION_EVENT)
    m_page->settings().setNotificationEventEnabled(notificationEventEnabled);
#else
    UNUSED_PARAM(notificationEventEnabled);
#endif
}

void InternalSettingsGenerated::setNotificationsEnabled(bool notificationsEnabled)
{
#if ENABLE(NOTIFICATIONS)
    m_page->settings().setNotificationsEnabled(notificationsEnabled);
#else
    UNUSED_PARAM(notificationsEnabled);
#endif
}

void InternalSettingsGenerated::setObservableEnabled(bool observableEnabled)
{
    m_page->settings().setObservableEnabled(observableEnabled);
}

void InternalSettingsGenerated::setOffscreenCanvasEnabled(bool offscreenCanvasEnabled)
{
#if ENABLE(OFFSCREEN_CANVAS)
    m_page->settings().setOffscreenCanvasEnabled(offscreenCanvasEnabled);
#else
    UNUSED_PARAM(offscreenCanvasEnabled);
#endif
}

void InternalSettingsGenerated::setOffscreenCanvasInWorkersEnabled(bool offscreenCanvasInWorkersEnabled)
{
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
    m_page->settings().setOffscreenCanvasInWorkersEnabled(offscreenCanvasInWorkersEnabled);
#else
    UNUSED_PARAM(offscreenCanvasInWorkersEnabled);
#endif
}

void InternalSettingsGenerated::setOpportunisticSweepingAndGarbageCollectionEnabled(bool opportunisticSweepingAndGarbageCollectionEnabled)
{
    m_page->settings().setOpportunisticSweepingAndGarbageCollectionEnabled(opportunisticSweepingAndGarbageCollectionEnabled);
}

void InternalSettingsGenerated::setOptInPartitionedCookiesEnabled(bool optInPartitionedCookiesEnabled)
{
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
    m_page->settings().setOptInPartitionedCookiesEnabled(optInPartitionedCookiesEnabled);
#else
    UNUSED_PARAM(optInPartitionedCookiesEnabled);
#endif
}

void InternalSettingsGenerated::setOverlappingBackingStoreProvidersEnabled(bool overlappingBackingStoreProvidersEnabled)
{
    m_page->settings().setOverlappingBackingStoreProvidersEnabled(overlappingBackingStoreProvidersEnabled);
}

void InternalSettingsGenerated::setOverscrollBehaviorEnabled(bool overscrollBehaviorEnabled)
{
    m_page->settings().setOverscrollBehaviorEnabled(overscrollBehaviorEnabled);
}

void InternalSettingsGenerated::setPageAtRuleMarginDescriptorsEnabled(bool pageAtRuleMarginDescriptorsEnabled)
{
    m_page->settings().setPageAtRuleMarginDescriptorsEnabled(pageAtRuleMarginDescriptorsEnabled);
}

void InternalSettingsGenerated::setPassiveTouchListenersAsDefaultOnDocument(bool passiveTouchListenersAsDefaultOnDocument)
{
    m_page->settings().setPassiveTouchListenersAsDefaultOnDocument(passiveTouchListenersAsDefaultOnDocument);
}

void InternalSettingsGenerated::setPassiveWheelListenersAsDefaultOnDocument(bool passiveWheelListenersAsDefaultOnDocument)
{
    m_page->settings().setPassiveWheelListenersAsDefaultOnDocument(passiveWheelListenersAsDefaultOnDocument);
}

void InternalSettingsGenerated::setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds)
{
    m_page->settings().setPasswordEchoDurationInSeconds(passwordEchoDurationInSeconds);
}

void InternalSettingsGenerated::setPasswordEchoEnabled(bool passwordEchoEnabled)
{
    m_page->settings().setPasswordEchoEnabled(passwordEchoEnabled);
}

void InternalSettingsGenerated::setPaymentRequestEnabled(bool paymentRequestEnabled)
{
#if ENABLE(PAYMENT_REQUEST)
    m_page->settings().setPaymentRequestEnabled(paymentRequestEnabled);
#else
    UNUSED_PARAM(paymentRequestEnabled);
#endif
}

void InternalSettingsGenerated::setPDFJSViewerEnabled(bool pdfJSViewerEnabled)
{
#if ENABLE(PDFJS)
    m_page->settings().setPDFJSViewerEnabled(pdfJSViewerEnabled);
#else
    UNUSED_PARAM(pdfJSViewerEnabled);
#endif
}

void InternalSettingsGenerated::setPDFPluginEnabled(bool pdfPluginEnabled)
{
#if PLATFORM(COCOA)
    m_page->settings().setPDFPluginEnabled(pdfPluginEnabled);
#else
    UNUSED_PARAM(pdfPluginEnabled);
#endif
}

void InternalSettingsGenerated::setPDFPluginHUDEnabled(bool pdfPluginHUDEnabled)
{
#if PLATFORM(COCOA)
    m_page->settings().setPDFPluginHUDEnabled(pdfPluginHUDEnabled);
#else
    UNUSED_PARAM(pdfPluginHUDEnabled);
#endif
}

void InternalSettingsGenerated::setPDFPluginPageNumberIndicatorEnabled(bool pdfPluginPageNumberIndicatorEnabled)
{
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    m_page->settings().setPDFPluginPageNumberIndicatorEnabled(pdfPluginPageNumberIndicatorEnabled);
#else
    UNUSED_PARAM(pdfPluginPageNumberIndicatorEnabled);
#endif
}

void InternalSettingsGenerated::setPeerConnectionEnabled(bool peerConnectionEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setPeerConnectionEnabled(peerConnectionEnabled);
#else
    UNUSED_PARAM(peerConnectionEnabled);
#endif
}

void InternalSettingsGenerated::setPeerConnectionVideoScalingAdaptationDisabled(bool peerConnectionVideoScalingAdaptationDisabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setPeerConnectionVideoScalingAdaptationDisabled(peerConnectionVideoScalingAdaptationDisabled);
#else
    UNUSED_PARAM(peerConnectionVideoScalingAdaptationDisabled);
#endif
}

void InternalSettingsGenerated::setPerElementSpeakerSelectionEnabled(bool perElementSpeakerSelectionEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setPerElementSpeakerSelectionEnabled(perElementSpeakerSelectionEnabled);
#else
    UNUSED_PARAM(perElementSpeakerSelectionEnabled);
#endif
}

void InternalSettingsGenerated::setPermissionsAPIEnabled(bool permissionsAPIEnabled)
{
    m_page->settings().setPermissionsAPIEnabled(permissionsAPIEnabled);
}

void InternalSettingsGenerated::setPictographFontFamily(const String& pictographFontFamily)
{
    m_page->settings().setPictographFontFamily(pictographFontFamily);
}

void InternalSettingsGenerated::setPictureInPictureAPIEnabled(bool pictureInPictureAPIEnabled)
{
#if ENABLE(PICTURE_IN_PICTURE_API)
    m_page->settings().setPictureInPictureAPIEnabled(pictureInPictureAPIEnabled);
#else
    UNUSED_PARAM(pictureInPictureAPIEnabled);
#endif
}

void InternalSettingsGenerated::setPictureInPicturePlaybackStateEnabled(bool pictureInPicturePlaybackStateEnabled)
{
#if HAVE(PIP_SKIP_PREROLL)
    m_page->settings().setPictureInPicturePlaybackStateEnabled(pictureInPicturePlaybackStateEnabled);
#else
    UNUSED_PARAM(pictureInPicturePlaybackStateEnabled);
#endif
}

void InternalSettingsGenerated::setPointerLockEnabled(bool pointerLockEnabled)
{
#if ENABLE(POINTER_LOCK)
    m_page->settings().setPointerLockEnabled(pointerLockEnabled);
#else
    UNUSED_PARAM(pointerLockEnabled);
#endif
}

void InternalSettingsGenerated::setPointerLockOptionsEnabled(bool pointerLockOptionsEnabled)
{
#if ENABLE(POINTER_LOCK)
    m_page->settings().setPointerLockOptionsEnabled(pointerLockOptionsEnabled);
#else
    UNUSED_PARAM(pointerLockOptionsEnabled);
#endif
}

void InternalSettingsGenerated::setPopoverAttributeEnabled(bool popoverAttributeEnabled)
{
    m_page->settings().setPopoverAttributeEnabled(popoverAttributeEnabled);
}

void InternalSettingsGenerated::setPreferMIMETypeForImages(bool preferMIMETypeForImages)
{
    m_page->settings().setPreferMIMETypeForImages(preferMIMETypeForImages);
}

void InternalSettingsGenerated::setPreferPageRenderingUpdatesNear60FPSEnabled(bool preferPageRenderingUpdatesNear60FPSEnabled)
{
    m_page->settings().setPreferPageRenderingUpdatesNear60FPSEnabled(preferPageRenderingUpdatesNear60FPSEnabled);
}

void InternalSettingsGenerated::setPreferSpatialAudioExperience(bool preferSpatialAudioExperience)
{
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    m_page->settings().setPreferSpatialAudioExperience(preferSpatialAudioExperience);
#else
    UNUSED_PARAM(preferSpatialAudioExperience);
#endif
}

void InternalSettingsGenerated::setPreventKeyboardDOMEventDispatch(bool preventKeyboardDOMEventDispatch)
{
    m_page->settings().setPreventKeyboardDOMEventDispatch(preventKeyboardDOMEventDispatch);
}

void InternalSettingsGenerated::setPrivateClickMeasurementDebugModeEnabled(bool privateClickMeasurementDebugModeEnabled)
{
    m_page->settings().setPrivateClickMeasurementDebugModeEnabled(privateClickMeasurementDebugModeEnabled);
}

void InternalSettingsGenerated::setPrivateClickMeasurementEnabled(bool privateClickMeasurementEnabled)
{
    m_page->settings().setPrivateClickMeasurementEnabled(privateClickMeasurementEnabled);
}

void InternalSettingsGenerated::setPrivateClickMeasurementFraudPreventionEnabled(bool privateClickMeasurementFraudPreventionEnabled)
{
    m_page->settings().setPrivateClickMeasurementFraudPreventionEnabled(privateClickMeasurementFraudPreventionEnabled);
}

void InternalSettingsGenerated::setPrivateTokenUsageByThirdPartyEnabled(bool privateTokenUsageByThirdPartyEnabled)
{
    m_page->settings().setPrivateTokenUsageByThirdPartyEnabled(privateTokenUsageByThirdPartyEnabled);
}

void InternalSettingsGenerated::setPropagateDamagingInformation(bool propagateDamagingInformation)
{
#if ENABLE(DAMAGE_TRACKING)
    m_page->settings().setPropagateDamagingInformation(propagateDamagingInformation);
#else
    UNUSED_PARAM(propagateDamagingInformation);
#endif
}

void InternalSettingsGenerated::setPunchOutWhiteBackgroundsInDarkMode(bool punchOutWhiteBackgroundsInDarkMode)
{
    m_page->settings().setPunchOutWhiteBackgroundsInDarkMode(punchOutWhiteBackgroundsInDarkMode);
}

void InternalSettingsGenerated::setPushAPIEnabled(bool pushAPIEnabled)
{
    m_page->settings().setPushAPIEnabled(pushAPIEnabled);
}

void InternalSettingsGenerated::setRemoteMediaSessionManagerEnabled(bool remoteMediaSessionManagerEnabled)
{
    m_page->settings().setRemoteMediaSessionManagerEnabled(remoteMediaSessionManagerEnabled);
}

void InternalSettingsGenerated::setRemotePlaybackEnabled(bool remotePlaybackEnabled)
{
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    m_page->settings().setRemotePlaybackEnabled(remotePlaybackEnabled);
#else
    UNUSED_PARAM(remotePlaybackEnabled);
#endif
}

void InternalSettingsGenerated::setRemoteSnapshottingEnabled(bool remoteSnapshottingEnabled)
{
    m_page->settings().setRemoteSnapshottingEnabled(remoteSnapshottingEnabled);
}

void InternalSettingsGenerated::setRemoveBackgroundEnabled(bool removeBackgroundEnabled)
{
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    m_page->settings().setRemoveBackgroundEnabled(removeBackgroundEnabled);
#else
    UNUSED_PARAM(removeBackgroundEnabled);
#endif
}

void InternalSettingsGenerated::setRequestIdleCallbackEnabled(bool requestIdleCallbackEnabled)
{
    m_page->settings().setRequestIdleCallbackEnabled(requestIdleCallbackEnabled);
}

void InternalSettingsGenerated::setRequestStorageAccessThrowsExceptionUntilReload(bool requestStorageAccessThrowsExceptionUntilReload)
{
    m_page->settings().setRequestStorageAccessThrowsExceptionUntilReload(requestStorageAccessThrowsExceptionUntilReload);
}

void InternalSettingsGenerated::setRequestVideoFrameCallbackEnabled(bool requestVideoFrameCallbackEnabled)
{
    m_page->settings().setRequestVideoFrameCallbackEnabled(requestVideoFrameCallbackEnabled);
}

void InternalSettingsGenerated::setRequireUAGetDisplayMediaPrompt(bool requireUAGetDisplayMediaPrompt)
{
#if HAVE(SC_CONTENT_SHARING_PICKER)
    m_page->settings().setRequireUAGetDisplayMediaPrompt(requireUAGetDisplayMediaPrompt);
#else
    UNUSED_PARAM(requireUAGetDisplayMediaPrompt);
#endif
}

void InternalSettingsGenerated::setRequiresPageVisibilityForVideoToBeNowPlaying(bool requiresPageVisibilityForVideoToBeNowPlaying)
{
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
    m_page->settings().setRequiresPageVisibilityForVideoToBeNowPlaying(requiresPageVisibilityForVideoToBeNowPlaying);
#else
    UNUSED_PARAM(requiresPageVisibilityForVideoToBeNowPlaying);
#endif
}

void InternalSettingsGenerated::setRequiresPageVisibilityToPlayAudio(bool requiresPageVisibilityToPlayAudio)
{
    m_page->settings().setRequiresPageVisibilityToPlayAudio(requiresPageVisibilityToPlayAudio);
}

void InternalSettingsGenerated::setRequiresUserGestureForAudioPlayback(bool requiresUserGestureForAudioPlayback)
{
    m_page->settings().setRequiresUserGestureForAudioPlayback(requiresUserGestureForAudioPlayback);
}

void InternalSettingsGenerated::setRequiresUserGestureForVideoPlayback(bool requiresUserGestureForVideoPlayback)
{
    m_page->settings().setRequiresUserGestureForVideoPlayback(requiresUserGestureForVideoPlayback);
}

void InternalSettingsGenerated::setRequiresUserGestureToLoadVideo(bool requiresUserGestureToLoadVideo)
{
    m_page->settings().setRequiresUserGestureToLoadVideo(requiresUserGestureToLoadVideo);
}

void InternalSettingsGenerated::setResourceLoadSchedulingEnabled(bool resourceLoadSchedulingEnabled)
{
    m_page->settings().setResourceLoadSchedulingEnabled(resourceLoadSchedulingEnabled);
}

void InternalSettingsGenerated::setResourceUsageOverlayVisible(bool resourceUsageOverlayVisible)
{
#if ENABLE(RESOURCE_USAGE)
    m_page->settings().setResourceUsageOverlayVisible(resourceUsageOverlayVisible);
#else
    UNUSED_PARAM(resourceUsageOverlayVisible);
#endif
}

void InternalSettingsGenerated::setRespondToThermalPressureAggressively(bool respondToThermalPressureAggressively)
{
    m_page->settings().setRespondToThermalPressureAggressively(respondToThermalPressureAggressively);
}

void InternalSettingsGenerated::setRubberBandingForSubScrollableRegionsEnabled(bool rubberBandingForSubScrollableRegionsEnabled)
{
#if HAVE(RUBBER_BANDING)
    m_page->settings().setRubberBandingForSubScrollableRegionsEnabled(rubberBandingForSubScrollableRegionsEnabled);
#else
    UNUSED_PARAM(rubberBandingForSubScrollableRegionsEnabled);
#endif
}

void InternalSettingsGenerated::setSKAttributionEnabled(bool sKAttributionEnabled)
{
    m_page->settings().setSKAttributionEnabled(sKAttributionEnabled);
}

void InternalSettingsGenerated::setSampledPageTopColorMaxDifference(double sampledPageTopColorMaxDifference)
{
    m_page->settings().setSampledPageTopColorMaxDifference(sampledPageTopColorMaxDifference);
}

void InternalSettingsGenerated::setSampledPageTopColorMinHeight(double sampledPageTopColorMinHeight)
{
    m_page->settings().setSampledPageTopColorMinHeight(sampledPageTopColorMinHeight);
}

void InternalSettingsGenerated::setSansSerifFontFamily(const String& sansSerifFontFamily)
{
    m_page->settings().setSansSerifFontFamily(sansSerifFontFamily);
}

void InternalSettingsGenerated::setScopedCustomElementRegistryEnabled(bool scopedCustomElementRegistryEnabled)
{
    m_page->settings().setScopedCustomElementRegistryEnabled(scopedCustomElementRegistryEnabled);
}

void InternalSettingsGenerated::setScreenCaptureEnabled(bool screenCaptureEnabled)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setScreenCaptureEnabled(screenCaptureEnabled);
#else
    UNUSED_PARAM(screenCaptureEnabled);
#endif
}

void InternalSettingsGenerated::setScreenOrientationAPIEnabled(bool screenOrientationAPIEnabled)
{
    m_page->settings().setScreenOrientationAPIEnabled(screenOrientationAPIEnabled);
}

void InternalSettingsGenerated::setScreenOrientationLockingAPIEnabled(bool screenOrientationLockingAPIEnabled)
{
    m_page->settings().setScreenOrientationLockingAPIEnabled(screenOrientationLockingAPIEnabled);
}

void InternalSettingsGenerated::setScreenTimeEnabled(bool screenTimeEnabled)
{
#if ENABLE(SCREEN_TIME)
    m_page->settings().setScreenTimeEnabled(screenTimeEnabled);
#else
    UNUSED_PARAM(screenTimeEnabled);
#endif
}

void InternalSettingsGenerated::setScreenWakeLockAPIEnabled(bool screenWakeLockAPIEnabled)
{
    m_page->settings().setScreenWakeLockAPIEnabled(screenWakeLockAPIEnabled);
}

void InternalSettingsGenerated::setScriptEnabled(bool scriptEnabled)
{
    m_page->settings().setScriptEnabled(scriptEnabled);
}

void InternalSettingsGenerated::setScriptMarkupEnabled(bool scriptMarkupEnabled)
{
    m_page->settings().setScriptMarkupEnabled(scriptMarkupEnabled);
}

void InternalSettingsGenerated::setScriptTrackingPrivacyLoggingEnabled(bool scriptTrackingPrivacyLoggingEnabled)
{
    m_page->settings().setScriptTrackingPrivacyLoggingEnabled(scriptTrackingPrivacyLoggingEnabled);
}

void InternalSettingsGenerated::setScrollAnimatorEnabled(bool scrollAnimatorEnabled)
{
    m_page->settings().setScrollAnimatorEnabled(scrollAnimatorEnabled);
}

void InternalSettingsGenerated::setScrollDrivenAnimationsEnabled(bool scrollDrivenAnimationsEnabled)
{
    m_page->settings().setScrollDrivenAnimationsEnabled(scrollDrivenAnimationsEnabled);
}

void InternalSettingsGenerated::setScrollToTextFragmentEnabled(bool scrollToTextFragmentEnabled)
{
    m_page->settings().setScrollToTextFragmentEnabled(scrollToTextFragmentEnabled);
}

void InternalSettingsGenerated::setScrollToTextFragmentFeatureDetectionEnabled(bool scrollToTextFragmentFeatureDetectionEnabled)
{
    m_page->settings().setScrollToTextFragmentFeatureDetectionEnabled(scrollToTextFragmentFeatureDetectionEnabled);
}

void InternalSettingsGenerated::setScrollToTextFragmentGenerationEnabled(bool scrollToTextFragmentGenerationEnabled)
{
    m_page->settings().setScrollToTextFragmentGenerationEnabled(scrollToTextFragmentGenerationEnabled);
}

void InternalSettingsGenerated::setScrollToTextFragmentIndicatorEnabled(bool scrollToTextFragmentIndicatorEnabled)
{
    m_page->settings().setScrollToTextFragmentIndicatorEnabled(scrollToTextFragmentIndicatorEnabled);
}

void InternalSettingsGenerated::setScrollToTextFragmentMarkingEnabled(bool scrollToTextFragmentMarkingEnabled)
{
    m_page->settings().setScrollToTextFragmentMarkingEnabled(scrollToTextFragmentMarkingEnabled);
}

void InternalSettingsGenerated::setScrollendEventEnabled(bool scrollendEventEnabled)
{
    m_page->settings().setScrollendEventEnabled(scrollendEventEnabled);
}

void InternalSettingsGenerated::setScrollingCoordinatorEnabled(bool scrollingCoordinatorEnabled)
{
    m_page->settings().setScrollingCoordinatorEnabled(scrollingCoordinatorEnabled);
}

void InternalSettingsGenerated::setScrollingPerformanceTestingEnabled(bool scrollingPerformanceTestingEnabled)
{
    m_page->settings().setScrollingPerformanceTestingEnabled(scrollingPerformanceTestingEnabled);
}

void InternalSettingsGenerated::setScrollingTreeIncludesFrames(bool scrollingTreeIncludesFrames)
{
    m_page->settings().setScrollingTreeIncludesFrames(scrollingTreeIncludesFrames);
}

void InternalSettingsGenerated::setSecureContextChecksEnabled(bool secureContextChecksEnabled)
{
    m_page->settings().setSecureContextChecksEnabled(secureContextChecksEnabled);
}

void InternalSettingsGenerated::setSelectShowPickerEnabled(bool selectShowPickerEnabled)
{
    m_page->settings().setSelectShowPickerEnabled(selectShowPickerEnabled);
}

void InternalSettingsGenerated::setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled)
{
    m_page->settings().setSelectTrailingWhitespaceEnabled(selectTrailingWhitespaceEnabled);
}

void InternalSettingsGenerated::setSelectionHonorsOverflowScrolling(bool selectionHonorsOverflowScrolling)
{
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setSelectionHonorsOverflowScrolling(selectionHonorsOverflowScrolling);
#else
    UNUSED_PARAM(selectionHonorsOverflowScrolling);
#endif
}

void InternalSettingsGenerated::setSerifFontFamily(const String& serifFontFamily)
{
    m_page->settings().setSerifFontFamily(serifFontFamily);
}

void InternalSettingsGenerated::setServiceControlsEnabled(bool serviceControlsEnabled)
{
#if ENABLE(SERVICE_CONTROLS)
    m_page->settings().setServiceControlsEnabled(serviceControlsEnabled);
#else
    UNUSED_PARAM(serviceControlsEnabled);
#endif
}

void InternalSettingsGenerated::setServiceWorkerInstallEventEnabled(bool serviceWorkerInstallEventEnabled)
{
    m_page->settings().setServiceWorkerInstallEventEnabled(serviceWorkerInstallEventEnabled);
}

void InternalSettingsGenerated::setServiceWorkerNavigationPreloadEnabled(bool serviceWorkerNavigationPreloadEnabled)
{
    m_page->settings().setServiceWorkerNavigationPreloadEnabled(serviceWorkerNavigationPreloadEnabled);
}

void InternalSettingsGenerated::setServiceWorkersEnabled(bool serviceWorkersEnabled)
{
    m_page->settings().setServiceWorkersEnabled(serviceWorkersEnabled);
}

void InternalSettingsGenerated::setServiceWorkersUserGestureEnabled(bool serviceWorkersUserGestureEnabled)
{
    m_page->settings().setServiceWorkersUserGestureEnabled(serviceWorkersUserGestureEnabled);
}

void InternalSettingsGenerated::setSessionStorageQuota(uint32_t sessionStorageQuota)
{
    m_page->settings().setSessionStorageQuota(sessionStorageQuota);
}

void InternalSettingsGenerated::setShadowRootReferenceTargetEnabled(bool shadowRootReferenceTargetEnabled)
{
    m_page->settings().setShadowRootReferenceTargetEnabled(shadowRootReferenceTargetEnabled);
}

void InternalSettingsGenerated::setShadowRootReferenceTargetEnabledForAriaOwns(bool shadowRootReferenceTargetEnabledForAriaOwns)
{
    m_page->settings().setShadowRootReferenceTargetEnabledForAriaOwns(shadowRootReferenceTargetEnabledForAriaOwns);
}

void InternalSettingsGenerated::setShapeDetection(bool shapeDetection)
{
    m_page->settings().setShapeDetection(shapeDetection);
}

void InternalSettingsGenerated::setSharedWorkerEnabled(bool sharedWorkerEnabled)
{
    m_page->settings().setSharedWorkerEnabled(sharedWorkerEnabled);
}

void InternalSettingsGenerated::setShouldAllowUserInstalledFonts(bool shouldAllowUserInstalledFonts)
{
    m_page->settings().setShouldAllowUserInstalledFonts(shouldAllowUserInstalledFonts);
}

void InternalSettingsGenerated::setShouldConvertInvalidURLsToBlank(bool shouldConvertInvalidURLsToBlank)
{
    m_page->settings().setShouldConvertInvalidURLsToBlank(shouldConvertInvalidURLsToBlank);
}

void InternalSettingsGenerated::setShouldConvertPositionStyleOnCopy(bool shouldConvertPositionStyleOnCopy)
{
    m_page->settings().setShouldConvertPositionStyleOnCopy(shouldConvertPositionStyleOnCopy);
}

void InternalSettingsGenerated::setShouldDecidePolicyBeforeLoadingQuickLookPreview(bool shouldDecidePolicyBeforeLoadingQuickLookPreview)
{
    m_page->settings().setShouldDecidePolicyBeforeLoadingQuickLookPreview(shouldDecidePolicyBeforeLoadingQuickLookPreview);
}

void InternalSettingsGenerated::setShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint(bool shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint)
{
    m_page->settings().setShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint(shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint);
}

void InternalSettingsGenerated::setShouldDispatchSyntheticMouseEventsWhenModifyingSelection(bool shouldDispatchSyntheticMouseEventsWhenModifyingSelection)
{
    m_page->settings().setShouldDispatchSyntheticMouseEventsWhenModifyingSelection(shouldDispatchSyntheticMouseEventsWhenModifyingSelection);
}

void InternalSettingsGenerated::setShouldDispatchSyntheticMouseOutAfterSyntheticClick(bool shouldDispatchSyntheticMouseOutAfterSyntheticClick)
{
    m_page->settings().setShouldDispatchSyntheticMouseOutAfterSyntheticClick(shouldDispatchSyntheticMouseOutAfterSyntheticClick);
}

void InternalSettingsGenerated::setShouldDisplayCaptions(bool shouldDisplayCaptions)
{
#if ENABLE(VIDEO)
    m_page->settings().setShouldDisplayCaptions(shouldDisplayCaptions);
#else
    UNUSED_PARAM(shouldDisplayCaptions);
#endif
}

void InternalSettingsGenerated::setShouldDisplaySubtitles(bool shouldDisplaySubtitles)
{
#if ENABLE(VIDEO)
    m_page->settings().setShouldDisplaySubtitles(shouldDisplaySubtitles);
#else
    UNUSED_PARAM(shouldDisplaySubtitles);
#endif
}

void InternalSettingsGenerated::setShouldDisplayTextDescriptions(bool shouldDisplayTextDescriptions)
{
#if ENABLE(VIDEO)
    m_page->settings().setShouldDisplayTextDescriptions(shouldDisplayTextDescriptions);
#else
    UNUSED_PARAM(shouldDisplayTextDescriptions);
#endif
}

void InternalSettingsGenerated::setShouldDropNearSuspendedAssertionAfterDelay(bool shouldDropNearSuspendedAssertionAfterDelay)
{
    m_page->settings().setShouldDropNearSuspendedAssertionAfterDelay(shouldDropNearSuspendedAssertionAfterDelay);
}

void InternalSettingsGenerated::setShouldEnableTextAutosizingBoost(bool shouldEnableTextAutosizingBoost)
{
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setShouldEnableTextAutosizingBoost(shouldEnableTextAutosizingBoost);
#else
    UNUSED_PARAM(shouldEnableTextAutosizingBoost);
#endif
}

void InternalSettingsGenerated::setShouldIgnoreFontLoadCompletions(bool shouldIgnoreFontLoadCompletions)
{
    m_page->settings().setShouldIgnoreFontLoadCompletions(shouldIgnoreFontLoadCompletions);
}

void InternalSettingsGenerated::setShouldIgnoreMetaViewport(bool shouldIgnoreMetaViewport)
{
    m_page->settings().setShouldIgnoreMetaViewport(shouldIgnoreMetaViewport);
}

void InternalSettingsGenerated::setShouldInjectUserScriptsInInitialEmptyDocument(bool shouldInjectUserScriptsInInitialEmptyDocument)
{
    m_page->settings().setShouldInjectUserScriptsInInitialEmptyDocument(shouldInjectUserScriptsInInitialEmptyDocument);
}

void InternalSettingsGenerated::setShouldPrintBackgrounds(bool shouldPrintBackgrounds)
{
    m_page->settings().setShouldPrintBackgrounds(shouldPrintBackgrounds);
}

void InternalSettingsGenerated::setShouldRespectImageOrientation(bool shouldRespectImageOrientation)
{
    m_page->settings().setShouldRespectImageOrientation(shouldRespectImageOrientation);
}

void InternalSettingsGenerated::setShouldRestrictBaseURLSchemes(bool shouldRestrictBaseURLSchemes)
{
    m_page->settings().setShouldRestrictBaseURLSchemes(shouldRestrictBaseURLSchemes);
}

void InternalSettingsGenerated::setShouldSuppressTextInputFromEditingDuringProvisionalNavigation(bool shouldSuppressTextInputFromEditingDuringProvisionalNavigation)
{
    m_page->settings().setShouldSuppressTextInputFromEditingDuringProvisionalNavigation(shouldSuppressTextInputFromEditingDuringProvisionalNavigation);
}

void InternalSettingsGenerated::setShouldTakeNearSuspendedAssertions(bool shouldTakeNearSuspendedAssertions)
{
    m_page->settings().setShouldTakeNearSuspendedAssertions(shouldTakeNearSuspendedAssertions);
}

void InternalSettingsGenerated::setShouldUseModernAVContentKeySession(bool shouldUseModernAVContentKeySession)
{
#if USE(MODERN_AVCONTENTKEYSESSION)
    m_page->settings().setShouldUseModernAVContentKeySession(shouldUseModernAVContentKeySession);
#else
    UNUSED_PARAM(shouldUseModernAVContentKeySession);
#endif
}

void InternalSettingsGenerated::setShouldUseServiceWorkerShortTimeout(bool shouldUseServiceWorkerShortTimeout)
{
    m_page->settings().setShouldUseServiceWorkerShortTimeout(shouldUseServiceWorkerShortTimeout);
}

void InternalSettingsGenerated::setShowDebugBorders(bool showDebugBorders)
{
    m_page->settings().setShowDebugBorders(showDebugBorders);
}

void InternalSettingsGenerated::setShowFrameProcessBorders(bool showFrameProcessBorders)
{
    m_page->settings().setShowFrameProcessBorders(showFrameProcessBorders);
}

void InternalSettingsGenerated::setShowMediaStatsContextMenuItemEnabled(bool showMediaStatsContextMenuItemEnabled)
{
    m_page->settings().setShowMediaStatsContextMenuItemEnabled(showMediaStatsContextMenuItemEnabled);
}

void InternalSettingsGenerated::setShowModalDialogEnabled(bool showModalDialogEnabled)
{
    m_page->settings().setShowModalDialogEnabled(showModalDialogEnabled);
}

void InternalSettingsGenerated::setShowRepaintCounter(bool showRepaintCounter)
{
    m_page->settings().setShowRepaintCounter(showRepaintCounter);
}

void InternalSettingsGenerated::setShowTiledScrollingIndicator(bool showTiledScrollingIndicator)
{
    m_page->settings().setShowTiledScrollingIndicator(showTiledScrollingIndicator);
}

void InternalSettingsGenerated::setShowsToolTipOverTruncatedText(bool showsToolTipOverTruncatedText)
{
    m_page->settings().setShowsToolTipOverTruncatedText(showsToolTipOverTruncatedText);
}

void InternalSettingsGenerated::setShowsURLsInToolTips(bool showsURLsInToolTips)
{
    m_page->settings().setShowsURLsInToolTips(showsURLsInToolTips);
}

void InternalSettingsGenerated::setShrinksStandaloneImagesToFit(bool shrinksStandaloneImagesToFit)
{
    m_page->settings().setShrinksStandaloneImagesToFit(shrinksStandaloneImagesToFit);
}

void InternalSettingsGenerated::setSidewaysWritingModesEnabled(bool sidewaysWritingModesEnabled)
{
    m_page->settings().setSidewaysWritingModesEnabled(sidewaysWritingModesEnabled);
}

void InternalSettingsGenerated::setSiteIsolationEnabled(bool siteIsolationEnabled)
{
    m_page->settings().setSiteIsolationEnabled(siteIsolationEnabled);
}

void InternalSettingsGenerated::setSiteIsolationSharedProcessEnabled(bool siteIsolationSharedProcessEnabled)
{
    m_page->settings().setSiteIsolationSharedProcessEnabled(siteIsolationSharedProcessEnabled);
}

void InternalSettingsGenerated::setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled)
{
    m_page->settings().setSmartInsertDeleteEnabled(smartInsertDeleteEnabled);
}

void InternalSettingsGenerated::setSourceBufferChangeTypeEnabled(bool sourceBufferChangeTypeEnabled)
{
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setSourceBufferChangeTypeEnabled(sourceBufferChangeTypeEnabled);
#else
    UNUSED_PARAM(sourceBufferChangeTypeEnabled);
#endif
}

void InternalSettingsGenerated::setSpatialImageControlsEnabled(bool spatialImageControlsEnabled)
{
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
    m_page->settings().setSpatialImageControlsEnabled(spatialImageControlsEnabled);
#else
    UNUSED_PARAM(spatialImageControlsEnabled);
#endif
}

void InternalSettingsGenerated::setSpatialNavigationEnabled(bool spatialNavigationEnabled)
{
    m_page->settings().setSpatialNavigationEnabled(spatialNavigationEnabled);
}

void InternalSettingsGenerated::setSpeakerSelectionRequiresUserGesture(bool speakerSelectionRequiresUserGesture)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setSpeakerSelectionRequiresUserGesture(speakerSelectionRequiresUserGesture);
#else
    UNUSED_PARAM(speakerSelectionRequiresUserGesture);
#endif
}

void InternalSettingsGenerated::setSpeechRecognitionEnabled(bool speechRecognitionEnabled)
{
    m_page->settings().setSpeechRecognitionEnabled(speechRecognitionEnabled);
}

void InternalSettingsGenerated::setSpeechSynthesisAPIEnabled(bool speechSynthesisAPIEnabled)
{
    m_page->settings().setSpeechSynthesisAPIEnabled(speechSynthesisAPIEnabled);
}

void InternalSettingsGenerated::setSpringTimingFunctionEnabled(bool springTimingFunctionEnabled)
{
    m_page->settings().setSpringTimingFunctionEnabled(springTimingFunctionEnabled);
}

void InternalSettingsGenerated::setStandalone(bool standalone)
{
    m_page->settings().setStandalone(standalone);
}

void InternalSettingsGenerated::setStandardFontFamily(const String& standardFontFamily)
{
    m_page->settings().setStandardFontFamily(standardFontFamily);
}

void InternalSettingsGenerated::setStorageAPIEnabled(bool storageAPIEnabled)
{
    m_page->settings().setStorageAPIEnabled(storageAPIEnabled);
}

void InternalSettingsGenerated::setStorageAPIEstimateEnabled(bool storageAPIEstimateEnabled)
{
    m_page->settings().setStorageAPIEstimateEnabled(storageAPIEstimateEnabled);
}

void InternalSettingsGenerated::setStorageAccessAPIPerPageScopeEnabled(bool storageAccessAPIPerPageScopeEnabled)
{
    m_page->settings().setStorageAccessAPIPerPageScopeEnabled(storageAccessAPIPerPageScopeEnabled);
}

void InternalSettingsGenerated::setSupportHDRCompositorTonemappingEnabled(bool supportHDRCompositorTonemappingEnabled)
{
    m_page->settings().setSupportHDRCompositorTonemappingEnabled(supportHDRCompositorTonemappingEnabled);
}

void InternalSettingsGenerated::setSupportHDRDisplayEnabled(bool supportHDRDisplayEnabled)
{
    m_page->settings().setSupportHDRDisplayEnabled(supportHDRDisplayEnabled);
}

void InternalSettingsGenerated::setSuppressHDRShouldBeAllowedInFullscreenVideo(bool suppressHDRShouldBeAllowedInFullscreenVideo)
{
    m_page->settings().setSuppressHDRShouldBeAllowedInFullscreenVideo(suppressHDRShouldBeAllowedInFullscreenVideo);
}

void InternalSettingsGenerated::setSuppressesIncrementalRendering(bool suppressesIncrementalRendering)
{
    m_page->settings().setSuppressesIncrementalRendering(suppressesIncrementalRendering);
}

void InternalSettingsGenerated::setSwitchControlEnabled(bool switchControlEnabled)
{
    m_page->settings().setSwitchControlEnabled(switchControlEnabled);
}

void InternalSettingsGenerated::setSystemPreviewEnabled(bool systemPreviewEnabled)
{
#if USE(SYSTEM_PREVIEW)
    m_page->settings().setSystemPreviewEnabled(systemPreviewEnabled);
#else
    UNUSED_PARAM(systemPreviewEnabled);
#endif
}

void InternalSettingsGenerated::setTargetTextPseudoElementEnabled(bool targetTextPseudoElementEnabled)
{
    m_page->settings().setTargetTextPseudoElementEnabled(targetTextPseudoElementEnabled);
}

void InternalSettingsGenerated::setTelephoneNumberParsingEnabled(bool telephoneNumberParsingEnabled)
{
    m_page->settings().setTelephoneNumberParsingEnabled(telephoneNumberParsingEnabled);
}

void InternalSettingsGenerated::setTemporaryTileCohortRetentionEnabled(bool temporaryTileCohortRetentionEnabled)
{
    m_page->settings().setTemporaryTileCohortRetentionEnabled(temporaryTileCohortRetentionEnabled);
}

void InternalSettingsGenerated::setTextAnimationsEnabled(bool textAnimationsEnabled)
{
#if ENABLE(WRITING_TOOLS)
    m_page->settings().setTextAnimationsEnabled(textAnimationsEnabled);
#else
    UNUSED_PARAM(textAnimationsEnabled);
#endif
}

void InternalSettingsGenerated::setTextAreasAreResizable(bool textAreasAreResizable)
{
    m_page->settings().setTextAreasAreResizable(textAreasAreResizable);
}

void InternalSettingsGenerated::setTextAutosizingEnabled(bool textAutosizingEnabled)
{
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingEnabled(textAutosizingEnabled);
#else
    UNUSED_PARAM(textAutosizingEnabled);
#endif
}

void InternalSettingsGenerated::setTextAutosizingEnabledAtLargeInitialScale(bool textAutosizingEnabledAtLargeInitialScale)
{
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingEnabledAtLargeInitialScale(textAutosizingEnabledAtLargeInitialScale);
#else
    UNUSED_PARAM(textAutosizingEnabledAtLargeInitialScale);
#endif
}

void InternalSettingsGenerated::setTextAutosizingUsesIdempotentMode(bool textAutosizingUsesIdempotentMode)
{
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingUsesIdempotentMode(textAutosizingUsesIdempotentMode);
#else
    UNUSED_PARAM(textAutosizingUsesIdempotentMode);
#endif
}

void InternalSettingsGenerated::setTextAutosizingWindowSizeOverrideHeight(uint32_t textAutosizingWindowSizeOverrideHeight)
{
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingWindowSizeOverrideHeight(textAutosizingWindowSizeOverrideHeight);
#else
    UNUSED_PARAM(textAutosizingWindowSizeOverrideHeight);
#endif
}

void InternalSettingsGenerated::setTextAutosizingWindowSizeOverrideWidth(uint32_t textAutosizingWindowSizeOverrideWidth)
{
#if ENABLE(TEXT_AUTOSIZING)
    m_page->settings().setTextAutosizingWindowSizeOverrideWidth(textAutosizingWindowSizeOverrideWidth);
#else
    UNUSED_PARAM(textAutosizingWindowSizeOverrideWidth);
#endif
}

void InternalSettingsGenerated::setTextInteractionEnabled(bool textInteractionEnabled)
{
    m_page->settings().setTextInteractionEnabled(textInteractionEnabled);
}

void InternalSettingsGenerated::setTextRecognitionInVideosEnabled(bool textRecognitionInVideosEnabled)
{
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    m_page->settings().setTextRecognitionInVideosEnabled(textRecognitionInVideosEnabled);
#else
    UNUSED_PARAM(textRecognitionInVideosEnabled);
#endif
}

void InternalSettingsGenerated::setTextTracksInMSEEnabled(bool textTracksInMSEEnabled)
{
#if ENABLE(MEDIA_SOURCE)
    m_page->settings().setTextTracksInMSEEnabled(textTracksInMSEEnabled);
#else
    UNUSED_PARAM(textTracksInMSEEnabled);
#endif
}

void InternalSettingsGenerated::setThreadedAnimationResolutionEnabled(bool threadedAnimationResolutionEnabled)
{
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
    m_page->settings().setThreadedAnimationResolutionEnabled(threadedAnimationResolutionEnabled);
#else
    UNUSED_PARAM(threadedAnimationResolutionEnabled);
#endif
}

void InternalSettingsGenerated::setThumbAndTrackPseudoElementsEnabled(bool thumbAndTrackPseudoElementsEnabled)
{
    m_page->settings().setThumbAndTrackPseudoElementsEnabled(thumbAndTrackPseudoElementsEnabled);
}

void InternalSettingsGenerated::setTopContentInsetBackgroundCanChangeAfterScrolling(bool topContentInsetBackgroundCanChangeAfterScrolling)
{
    m_page->settings().setTopContentInsetBackgroundCanChangeAfterScrolling(topContentInsetBackgroundCanChangeAfterScrolling);
}

void InternalSettingsGenerated::setTouchEventDOMAttributesEnabled(bool touchEventDOMAttributesEnabled)
{
#if ENABLE(TOUCH_EVENTS)
    m_page->settings().setTouchEventDOMAttributesEnabled(touchEventDOMAttributesEnabled);
#else
    UNUSED_PARAM(touchEventDOMAttributesEnabled);
#endif
}

void InternalSettingsGenerated::setTouchEventEmulationEnabled(bool touchEventEmulationEnabled)
{
#if ENABLE(TOUCH_EVENTS)
    m_page->settings().setTouchEventEmulationEnabled(touchEventEmulationEnabled);
#else
    UNUSED_PARAM(touchEventEmulationEnabled);
#endif
}

void InternalSettingsGenerated::setTouchInputCompatibilityEnabled(bool touchInputCompatibilityEnabled)
{
#if ENABLE(WEBXR)
    m_page->settings().setTouchInputCompatibilityEnabled(touchInputCompatibilityEnabled);
#else
    UNUSED_PARAM(touchInputCompatibilityEnabled);
#endif
}

void InternalSettingsGenerated::setTrackConfigurationEnabled(bool trackConfigurationEnabled)
{
    m_page->settings().setTrackConfigurationEnabled(trackConfigurationEnabled);
}

void InternalSettingsGenerated::setTreatIPAddressAsDomain(bool treatIPAddressAsDomain)
{
    m_page->settings().setTreatIPAddressAsDomain(treatIPAddressAsDomain);
}

void InternalSettingsGenerated::setTreatsAnyTextCSSLinkAsStylesheet(bool treatsAnyTextCSSLinkAsStylesheet)
{
    m_page->settings().setTreatsAnyTextCSSLinkAsStylesheet(treatsAnyTextCSSLinkAsStylesheet);
}

void InternalSettingsGenerated::setTrustedTypesEnabled(bool trustedTypesEnabled)
{
    m_page->settings().setTrustedTypesEnabled(trustedTypesEnabled);
}

void InternalSettingsGenerated::setUAVisualTransitionDetectionEnabled(bool uAVisualTransitionDetectionEnabled)
{
    m_page->settings().setUAVisualTransitionDetectionEnabled(uAVisualTransitionDetectionEnabled);
}

void InternalSettingsGenerated::setUndoManagerAPIEnabled(bool undoManagerAPIEnabled)
{
    m_page->settings().setUndoManagerAPIEnabled(undoManagerAPIEnabled);
}

void InternalSettingsGenerated::setUnhandledPromiseRejectionToConsoleEnabled(bool unhandledPromiseRejectionToConsoleEnabled)
{
    m_page->settings().setUnhandledPromiseRejectionToConsoleEnabled(unhandledPromiseRejectionToConsoleEnabled);
}

void InternalSettingsGenerated::setUnifiedPDFEnabled(bool unifiedPDFEnabled)
{
#if ENABLE(UNIFIED_PDF)
    m_page->settings().setUnifiedPDFEnabled(unifiedPDFEnabled);
#else
    UNUSED_PARAM(unifiedPDFEnabled);
#endif
}

void InternalSettingsGenerated::setUnifiedTextCheckerEnabled(bool unifiedTextCheckerEnabled)
{
    m_page->settings().setUnifiedTextCheckerEnabled(unifiedTextCheckerEnabled);
}

void InternalSettingsGenerated::setUnifyDamagedRegions(bool unifyDamagedRegions)
{
#if ENABLE(DAMAGE_TRACKING)
    m_page->settings().setUnifyDamagedRegions(unifyDamagedRegions);
#else
    UNUSED_PARAM(unifyDamagedRegions);
#endif
}

void InternalSettingsGenerated::setUpgradeMixedContentEnabled(bool upgradeMixedContentEnabled)
{
    m_page->settings().setUpgradeMixedContentEnabled(upgradeMixedContentEnabled);
}

void InternalSettingsGenerated::setURLPatternAPIEnabled(bool urlPatternAPIEnabled)
{
    m_page->settings().setURLPatternAPIEnabled(urlPatternAPIEnabled);
}

void InternalSettingsGenerated::setUseAnonymousModeWhenFetchingMaskImages(bool useAnonymousModeWhenFetchingMaskImages)
{
    m_page->settings().setUseAnonymousModeWhenFetchingMaskImages(useAnonymousModeWhenFetchingMaskImages);
}

void InternalSettingsGenerated::setUseAsyncUIKitInteractions(bool useAsyncUIKitInteractions)
{
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setUseAsyncUIKitInteractions(useAsyncUIKitInteractions);
#else
    UNUSED_PARAM(useAsyncUIKitInteractions);
#endif
}

void InternalSettingsGenerated::setUseDamagingInformationForCompositing(bool useDamagingInformationForCompositing)
{
#if ENABLE(DAMAGE_TRACKING)
    m_page->settings().setUseDamagingInformationForCompositing(useDamagingInformationForCompositing);
#else
    UNUSED_PARAM(useDamagingInformationForCompositing);
#endif
}

void InternalSettingsGenerated::setUseGPUProcessForWebGLEnabled(bool useGPUProcessForWebGLEnabled)
{
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
    m_page->settings().setUseGPUProcessForWebGLEnabled(useGPUProcessForWebGLEnabled);
#else
    UNUSED_PARAM(useGPUProcessForWebGLEnabled);
#endif
}

void InternalSettingsGenerated::setUseGiantTiles(bool useGiantTiles)
{
    m_page->settings().setUseGiantTiles(useGiantTiles);
}

void InternalSettingsGenerated::setUseIFCForSVGText(bool useIFCForSVGText)
{
    m_page->settings().setUseIFCForSVGText(useIFCForSVGText);
}

void InternalSettingsGenerated::setUseImageDocumentForSubframePDF(bool useImageDocumentForSubframePDF)
{
    m_page->settings().setUseImageDocumentForSubframePDF(useImageDocumentForSubframePDF);
}

void InternalSettingsGenerated::setUseMicrophoneMuteStatusAPI(bool useMicrophoneMuteStatusAPI)
{
#if ENABLE(MEDIA_STREAM)
    m_page->settings().setUseMicrophoneMuteStatusAPI(useMicrophoneMuteStatusAPI);
#else
    UNUSED_PARAM(useMicrophoneMuteStatusAPI);
#endif
}

void InternalSettingsGenerated::setUsePreHTML5ParserQuirks(bool usePreHTML5ParserQuirks)
{
    m_page->settings().setUsePreHTML5ParserQuirks(usePreHTML5ParserQuirks);
}

void InternalSettingsGenerated::setUseSystemAppearance(bool useSystemAppearance)
{
    m_page->settings().setUseSystemAppearance(useSystemAppearance);
}

void InternalSettingsGenerated::setUserActivationAPIEnabled(bool userActivationAPIEnabled)
{
    m_page->settings().setUserActivationAPIEnabled(userActivationAPIEnabled);
}

void InternalSettingsGenerated::setUserGesturePromisePropagationEnabled(bool userGesturePromisePropagationEnabled)
{
    m_page->settings().setUserGesturePromisePropagationEnabled(userGesturePromisePropagationEnabled);
}

void InternalSettingsGenerated::setUsesEncodingDetector(bool usesEncodingDetector)
{
    m_page->settings().setUsesEncodingDetector(usesEncodingDetector);
}

void InternalSettingsGenerated::setValidationMessageTimerMagnification(uint32_t validationMessageTimerMagnification)
{
    m_page->settings().setValidationMessageTimerMagnification(validationMessageTimerMagnification);
}

void InternalSettingsGenerated::setVerifyWindowOpenUserGestureFromUIProcess(bool verifyWindowOpenUserGestureFromUIProcess)
{
    m_page->settings().setVerifyWindowOpenUserGestureFromUIProcess(verifyWindowOpenUserGestureFromUIProcess);
}

void InternalSettingsGenerated::setVerticalFormControlsEnabled(bool verticalFormControlsEnabled)
{
    m_page->settings().setVerticalFormControlsEnabled(verticalFormControlsEnabled);
}

void InternalSettingsGenerated::setVideoFullsceenPrefersMostVisibleHeuristic(bool videoFullsceenPrefersMostVisibleHeuristic)
{
#if ENABLE(FULLSCREEN_API)
    m_page->settings().setVideoFullsceenPrefersMostVisibleHeuristic(videoFullsceenPrefersMostVisibleHeuristic);
#else
    UNUSED_PARAM(videoFullsceenPrefersMostVisibleHeuristic);
#endif
}

void InternalSettingsGenerated::setVideoFullscreenRequiresElementFullscreen(bool videoFullscreenRequiresElementFullscreen)
{
#if ENABLE(FULLSCREEN_API)
    m_page->settings().setVideoFullscreenRequiresElementFullscreen(videoFullscreenRequiresElementFullscreen);
#else
    UNUSED_PARAM(videoFullscreenRequiresElementFullscreen);
#endif
}

void InternalSettingsGenerated::setVideoPresentationManagerEnabled(bool videoPresentationManagerEnabled)
{
    m_page->settings().setVideoPresentationManagerEnabled(videoPresentationManagerEnabled);
}

void InternalSettingsGenerated::setVideoPresentationModeAPIEnabled(bool videoPresentationModeAPIEnabled)
{
    m_page->settings().setVideoPresentationModeAPIEnabled(videoPresentationModeAPIEnabled);
}

void InternalSettingsGenerated::setVideoQualityIncludesDisplayCompositingEnabled(bool videoQualityIncludesDisplayCompositingEnabled)
{
#if ENABLE(VIDEO)
    m_page->settings().setVideoQualityIncludesDisplayCompositingEnabled(videoQualityIncludesDisplayCompositingEnabled);
#else
    UNUSED_PARAM(videoQualityIncludesDisplayCompositingEnabled);
#endif
}

void InternalSettingsGenerated::setVideoRendererProtectedFallbackDisabled(bool videoRendererProtectedFallbackDisabled)
{
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    m_page->settings().setVideoRendererProtectedFallbackDisabled(videoRendererProtectedFallbackDisabled);
#else
    UNUSED_PARAM(videoRendererProtectedFallbackDisabled);
#endif
}

void InternalSettingsGenerated::setVideoRendererUseDecompressionSessionForProtected(bool videoRendererUseDecompressionSessionForProtected)
{
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    m_page->settings().setVideoRendererUseDecompressionSessionForProtected(videoRendererUseDecompressionSessionForProtected);
#else
    UNUSED_PARAM(videoRendererUseDecompressionSessionForProtected);
#endif
}

void InternalSettingsGenerated::setViewTransitionClassesEnabled(bool viewTransitionClassesEnabled)
{
    m_page->settings().setViewTransitionClassesEnabled(viewTransitionClassesEnabled);
}

void InternalSettingsGenerated::setViewTransitionTypesEnabled(bool viewTransitionTypesEnabled)
{
    m_page->settings().setViewTransitionTypesEnabled(viewTransitionTypesEnabled);
}

void InternalSettingsGenerated::setViewTransitionsEnabled(bool viewTransitionsEnabled)
{
    m_page->settings().setViewTransitionsEnabled(viewTransitionsEnabled);
}

void InternalSettingsGenerated::setVisibleDebugOverlayRegions(uint32_t visibleDebugOverlayRegions)
{
    m_page->settings().setVisibleDebugOverlayRegions(visibleDebugOverlayRegions);
}

void InternalSettingsGenerated::setVisualTranslationEnabled(bool visualTranslationEnabled)
{
#if ENABLE(IMAGE_ANALYSIS)
    m_page->settings().setVisualTranslationEnabled(visualTranslationEnabled);
#else
    UNUSED_PARAM(visualTranslationEnabled);
#endif
}

void InternalSettingsGenerated::setVisualViewportAPIEnabled(bool visualViewportAPIEnabled)
{
    m_page->settings().setVisualViewportAPIEnabled(visualViewportAPIEnabled);
}

void InternalSettingsGenerated::setVisualViewportEnabled(bool visualViewportEnabled)
{
    m_page->settings().setVisualViewportEnabled(visualViewportEnabled);
}

void InternalSettingsGenerated::setVisuallyContiguousBidiTextSelectionEnabled(bool visuallyContiguousBidiTextSelectionEnabled)
{
#if PLATFORM(IOS_FAMILY)
    m_page->settings().setVisuallyContiguousBidiTextSelectionEnabled(visuallyContiguousBidiTextSelectionEnabled);
#else
    UNUSED_PARAM(visuallyContiguousBidiTextSelectionEnabled);
#endif
}

void InternalSettingsGenerated::setVP9DecoderEnabled(bool vp9DecoderEnabled)
{
#if ENABLE(VP9)
    m_page->settings().setVP9DecoderEnabled(vp9DecoderEnabled);
#else
    UNUSED_PARAM(vp9DecoderEnabled);
#endif
}

void InternalSettingsGenerated::setWantsBalancedSetDefersLoadingBehavior(bool wantsBalancedSetDefersLoadingBehavior)
{
    m_page->settings().setWantsBalancedSetDefersLoadingBehavior(wantsBalancedSetDefersLoadingBehavior);
}

void InternalSettingsGenerated::setWebAPIStatisticsEnabled(bool webAPIStatisticsEnabled)
{
    m_page->settings().setWebAPIStatisticsEnabled(webAPIStatisticsEnabled);
}

void InternalSettingsGenerated::setWebAPIsInShadowRealmEnabled(bool webAPIsInShadowRealmEnabled)
{
    m_page->settings().setWebAPIsInShadowRealmEnabled(webAPIsInShadowRealmEnabled);
}

void InternalSettingsGenerated::setWebAnimationsCustomEffectsEnabled(bool webAnimationsCustomEffectsEnabled)
{
    m_page->settings().setWebAnimationsCustomEffectsEnabled(webAnimationsCustomEffectsEnabled);
}

void InternalSettingsGenerated::setWebAnimationsCustomFrameRateEnabled(bool webAnimationsCustomFrameRateEnabled)
{
    m_page->settings().setWebAnimationsCustomFrameRateEnabled(webAnimationsCustomFrameRateEnabled);
}

void InternalSettingsGenerated::setWebAnimationsOverallProgressPropertyEnabled(bool webAnimationsOverallProgressPropertyEnabled)
{
    m_page->settings().setWebAnimationsOverallProgressPropertyEnabled(webAnimationsOverallProgressPropertyEnabled);
}

void InternalSettingsGenerated::setWebArchiveDebugModeEnabled(bool webArchiveDebugModeEnabled)
{
#if ENABLE(WEB_ARCHIVE)
    m_page->settings().setWebArchiveDebugModeEnabled(webArchiveDebugModeEnabled);
#else
    UNUSED_PARAM(webArchiveDebugModeEnabled);
#endif
}

void InternalSettingsGenerated::setWebArchiveTestingModeEnabled(bool webArchiveTestingModeEnabled)
{
#if ENABLE(WEB_ARCHIVE)
    m_page->settings().setWebArchiveTestingModeEnabled(webArchiveTestingModeEnabled);
#else
    UNUSED_PARAM(webArchiveTestingModeEnabled);
#endif
}

void InternalSettingsGenerated::setWebAssemblyESMIntegrationEnabled(bool webAssemblyESMIntegrationEnabled)
{
#if ENABLE(WEBASSEMBLY)
    m_page->settings().setWebAssemblyESMIntegrationEnabled(webAssemblyESMIntegrationEnabled);
#else
    UNUSED_PARAM(webAssemblyESMIntegrationEnabled);
#endif
}

void InternalSettingsGenerated::setWebAudioEnabled(bool webAudioEnabled)
{
#if ENABLE(WEB_AUDIO)
    m_page->settings().setWebAudioEnabled(webAudioEnabled);
#else
    UNUSED_PARAM(webAudioEnabled);
#endif
}

void InternalSettingsGenerated::setWebAuthenticationASEnabled(bool webAuthenticationASEnabled)
{
#if HAVE(WEB_AUTHN_AS_MODERN)
    m_page->settings().setWebAuthenticationASEnabled(webAuthenticationASEnabled);
#else
    UNUSED_PARAM(webAuthenticationASEnabled);
#endif
}

void InternalSettingsGenerated::setWebAuthenticationEnabled(bool webAuthenticationEnabled)
{
#if ENABLE(WEB_AUTHN)
    m_page->settings().setWebAuthenticationEnabled(webAuthenticationEnabled);
#else
    UNUSED_PARAM(webAuthenticationEnabled);
#endif
}

void InternalSettingsGenerated::setWebCodecsAV1Enabled(bool webCodecsAV1Enabled)
{
#if ENABLE(WEB_CODECS)
    m_page->settings().setWebCodecsAV1Enabled(webCodecsAV1Enabled);
#else
    UNUSED_PARAM(webCodecsAV1Enabled);
#endif
}

void InternalSettingsGenerated::setWebCodecsAudioEnabled(bool webCodecsAudioEnabled)
{
#if ENABLE(WEB_CODECS)
    m_page->settings().setWebCodecsAudioEnabled(webCodecsAudioEnabled);
#else
    UNUSED_PARAM(webCodecsAudioEnabled);
#endif
}

void InternalSettingsGenerated::setWebCodecsHEVCEnabled(bool webCodecsHEVCEnabled)
{
#if ENABLE(WEB_CODECS)
    m_page->settings().setWebCodecsHEVCEnabled(webCodecsHEVCEnabled);
#else
    UNUSED_PARAM(webCodecsHEVCEnabled);
#endif
}

void InternalSettingsGenerated::setWebCodecsVideoEnabled(bool webCodecsVideoEnabled)
{
#if ENABLE(WEB_CODECS)
    m_page->settings().setWebCodecsVideoEnabled(webCodecsVideoEnabled);
#else
    UNUSED_PARAM(webCodecsVideoEnabled);
#endif
}

void InternalSettingsGenerated::setWebCryptoSafeCurvesEnabled(bool webCryptoSafeCurvesEnabled)
{
    m_page->settings().setWebCryptoSafeCurvesEnabled(webCryptoSafeCurvesEnabled);
}

void InternalSettingsGenerated::setWebCryptoX25519Enabled(bool webCryptoX25519Enabled)
{
    m_page->settings().setWebCryptoX25519Enabled(webCryptoX25519Enabled);
}

void InternalSettingsGenerated::setWebExtensionBookmarksEnabled(bool webExtensionBookmarksEnabled)
{
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    m_page->settings().setWebExtensionBookmarksEnabled(webExtensionBookmarksEnabled);
#else
    UNUSED_PARAM(webExtensionBookmarksEnabled);
#endif
}

void InternalSettingsGenerated::setWebExtensionSidebarEnabled(bool webExtensionSidebarEnabled)
{
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    m_page->settings().setWebExtensionSidebarEnabled(webExtensionSidebarEnabled);
#else
    UNUSED_PARAM(webExtensionSidebarEnabled);
#endif
}

void InternalSettingsGenerated::setWebGLDraftExtensionsEnabled(bool webGLDraftExtensionsEnabled)
{
    m_page->settings().setWebGLDraftExtensionsEnabled(webGLDraftExtensionsEnabled);
}

void InternalSettingsGenerated::setWebGLEnabled(bool webGLEnabled)
{
    m_page->settings().setWebGLEnabled(webGLEnabled);
}

void InternalSettingsGenerated::setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled)
{
    m_page->settings().setWebGLErrorsToConsoleEnabled(webGLErrorsToConsoleEnabled);
}

void InternalSettingsGenerated::setWebGLTimerQueriesEnabled(bool webGLTimerQueriesEnabled)
{
    m_page->settings().setWebGLTimerQueriesEnabled(webGLTimerQueriesEnabled);
}

void InternalSettingsGenerated::setWebGPUEnabled(bool webGPUEnabled)
{
    m_page->settings().setWebGPUEnabled(webGPUEnabled);
}

void InternalSettingsGenerated::setWebGPUHDREnabled(bool webGPUHDREnabled)
{
    m_page->settings().setWebGPUHDREnabled(webGPUHDREnabled);
}

void InternalSettingsGenerated::setWebInspectorEngineeringSettingsAllowed(bool webInspectorEngineeringSettingsAllowed)
{
    m_page->settings().setWebInspectorEngineeringSettingsAllowed(webInspectorEngineeringSettingsAllowed);
}

void InternalSettingsGenerated::setWebLocksAPIEnabled(bool webLocksAPIEnabled)
{
    m_page->settings().setWebLocksAPIEnabled(webLocksAPIEnabled);
}

void InternalSettingsGenerated::setWebPageSpatialBackdropEnabled(bool webPageSpatialBackdropEnabled)
{
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    m_page->settings().setWebPageSpatialBackdropEnabled(webPageSpatialBackdropEnabled);
#else
    UNUSED_PARAM(webPageSpatialBackdropEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCAV1CodecEnabled(bool webRTCAV1CodecEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCAV1CodecEnabled(webRTCAV1CodecEnabled);
#else
    UNUSED_PARAM(webRTCAV1CodecEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCDTMFEnabled(bool webRTCDTMFEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCDTMFEnabled(webRTCDTMFEnabled);
#else
    UNUSED_PARAM(webRTCDTMFEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCEncodedTransformEnabled(bool webRTCEncodedTransformEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCEncodedTransformEnabled(webRTCEncodedTransformEnabled);
#else
    UNUSED_PARAM(webRTCEncodedTransformEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCEncryptionEnabled(bool webRTCEncryptionEnabled)
{
    m_page->settings().setWebRTCEncryptionEnabled(webRTCEncryptionEnabled);
}

void InternalSettingsGenerated::setWebRTCH265CodecEnabled(bool webRTCH265CodecEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCH265CodecEnabled(webRTCH265CodecEnabled);
#else
    UNUSED_PARAM(webRTCH265CodecEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCInterfaceMonitoringViaNWEnabled(bool webRTCInterfaceMonitoringViaNWEnabled)
{
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
    m_page->settings().setWebRTCInterfaceMonitoringViaNWEnabled(webRTCInterfaceMonitoringViaNWEnabled);
#else
    UNUSED_PARAM(webRTCInterfaceMonitoringViaNWEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCL4SEnabled(bool webRTCL4SEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCL4SEnabled(webRTCL4SEnabled);
#else
    UNUSED_PARAM(webRTCL4SEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCMediaPipelineAdditionalLoggingEnabled(bool webRTCMediaPipelineAdditionalLoggingEnabled)
{
    m_page->settings().setWebRTCMediaPipelineAdditionalLoggingEnabled(webRTCMediaPipelineAdditionalLoggingEnabled);
}

void InternalSettingsGenerated::setWebRTCPlatformCodecsInGPUProcessEnabled(bool webRTCPlatformCodecsInGPUProcessEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCPlatformCodecsInGPUProcessEnabled(webRTCPlatformCodecsInGPUProcessEnabled);
#else
    UNUSED_PARAM(webRTCPlatformCodecsInGPUProcessEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCRemoteVideoFrameEnabled(bool webRTCRemoteVideoFrameEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCRemoteVideoFrameEnabled(webRTCRemoteVideoFrameEnabled);
#else
    UNUSED_PARAM(webRTCRemoteVideoFrameEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCSFrameTransformEnabled(bool webRTCSFrameTransformEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCSFrameTransformEnabled(webRTCSFrameTransformEnabled);
#else
    UNUSED_PARAM(webRTCSFrameTransformEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCSocketsProxyingEnabled(bool webRTCSocketsProxyingEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCSocketsProxyingEnabled(webRTCSocketsProxyingEnabled);
#else
    UNUSED_PARAM(webRTCSocketsProxyingEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCUDPPortRange(const String& webRTCUDPPortRange)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCUDPPortRange(webRTCUDPPortRange);
#else
    UNUSED_PARAM(webRTCUDPPortRange);
#endif
}

void InternalSettingsGenerated::setWebRTCVP9Profile0CodecEnabled(bool webRTCVP9Profile0CodecEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCVP9Profile0CodecEnabled(webRTCVP9Profile0CodecEnabled);
#else
    UNUSED_PARAM(webRTCVP9Profile0CodecEnabled);
#endif
}

void InternalSettingsGenerated::setWebRTCVP9Profile2CodecEnabled(bool webRTCVP9Profile2CodecEnabled)
{
#if ENABLE(WEB_RTC)
    m_page->settings().setWebRTCVP9Profile2CodecEnabled(webRTCVP9Profile2CodecEnabled);
#else
    UNUSED_PARAM(webRTCVP9Profile2CodecEnabled);
#endif
}

void InternalSettingsGenerated::setWebSecurityEnabled(bool webSecurityEnabled)
{
    m_page->settings().setWebSecurityEnabled(webSecurityEnabled);
}

void InternalSettingsGenerated::setWebShareEnabled(bool webShareEnabled)
{
    m_page->settings().setWebShareEnabled(webShareEnabled);
}

void InternalSettingsGenerated::setWebShareFileAPIEnabled(bool webShareFileAPIEnabled)
{
    m_page->settings().setWebShareFileAPIEnabled(webShareFileAPIEnabled);
}

void InternalSettingsGenerated::setWebSocketEnabled(bool webSocketEnabled)
{
    m_page->settings().setWebSocketEnabled(webSocketEnabled);
}

void InternalSettingsGenerated::setWebTransportEnabled(bool webTransportEnabled)
{
    m_page->settings().setWebTransportEnabled(webTransportEnabled);
}

void InternalSettingsGenerated::setWebXRAugmentedRealityModuleEnabled(bool webXRAugmentedRealityModuleEnabled)
{
#if ENABLE(WEBXR)
    m_page->settings().setWebXRAugmentedRealityModuleEnabled(webXRAugmentedRealityModuleEnabled);
#else
    UNUSED_PARAM(webXRAugmentedRealityModuleEnabled);
#endif
}

void InternalSettingsGenerated::setWebXREnabled(bool webXREnabled)
{
#if ENABLE(WEBXR)
    m_page->settings().setWebXREnabled(webXREnabled);
#else
    UNUSED_PARAM(webXREnabled);
#endif
}

void InternalSettingsGenerated::setWebXRGamepadsModuleEnabled(bool webXRGamepadsModuleEnabled)
{
#if ENABLE(WEBXR)
    m_page->settings().setWebXRGamepadsModuleEnabled(webXRGamepadsModuleEnabled);
#else
    UNUSED_PARAM(webXRGamepadsModuleEnabled);
#endif
}

void InternalSettingsGenerated::setWebXRHandInputModuleEnabled(bool webXRHandInputModuleEnabled)
{
#if ENABLE(WEBXR_HANDS)
    m_page->settings().setWebXRHandInputModuleEnabled(webXRHandInputModuleEnabled);
#else
    UNUSED_PARAM(webXRHandInputModuleEnabled);
#endif
}

void InternalSettingsGenerated::setWebXRLayersAPIEnabled(bool webXRLayersAPIEnabled)
{
#if ENABLE(WEBXR_LAYERS)
    m_page->settings().setWebXRLayersAPIEnabled(webXRLayersAPIEnabled);
#else
    UNUSED_PARAM(webXRLayersAPIEnabled);
#endif
}

void InternalSettingsGenerated::setWebXRWebGPUBindingsEnabled(bool webXRWebGPUBindingsEnabled)
{
    m_page->settings().setWebXRWebGPUBindingsEnabled(webXRWebGPUBindingsEnabled);
}

void InternalSettingsGenerated::setWebkitImageReadyEventEnabled(bool webkitImageReadyEventEnabled)
{
    m_page->settings().setWebkitImageReadyEventEnabled(webkitImageReadyEventEnabled);
}

void InternalSettingsGenerated::setWheelEventGesturesBecomeNonBlocking(bool wheelEventGesturesBecomeNonBlocking)
{
    m_page->settings().setWheelEventGesturesBecomeNonBlocking(wheelEventGesturesBecomeNonBlocking);
}

void InternalSettingsGenerated::setWindowFocusRestricted(bool windowFocusRestricted)
{
    m_page->settings().setWindowFocusRestricted(windowFocusRestricted);
}

void InternalSettingsGenerated::setWirelessPlaybackTargetAPIEnabled(bool wirelessPlaybackTargetAPIEnabled)
{
    m_page->settings().setWirelessPlaybackTargetAPIEnabled(wirelessPlaybackTargetAPIEnabled);
}

void InternalSettingsGenerated::setWorkerAsynchronousURLErrorHandlingEnabled(bool workerAsynchronousURLErrorHandlingEnabled)
{
    m_page->settings().setWorkerAsynchronousURLErrorHandlingEnabled(workerAsynchronousURLErrorHandlingEnabled);
}

void InternalSettingsGenerated::setWriteRichTextDataWhenCopyingOrDragging(bool writeRichTextDataWhenCopyingOrDragging)
{
#if PLATFORM(COCOA)
    m_page->settings().setWriteRichTextDataWhenCopyingOrDragging(writeRichTextDataWhenCopyingOrDragging);
#else
    UNUSED_PARAM(writeRichTextDataWhenCopyingOrDragging);
#endif
}

void InternalSettingsGenerated::setWritingSuggestionsAttributeEnabled(bool writingSuggestionsAttributeEnabled)
{
#if ENABLE(WRITING_SUGGESTIONS)
    m_page->settings().setWritingSuggestionsAttributeEnabled(writingSuggestionsAttributeEnabled);
#else
    UNUSED_PARAM(writingSuggestionsAttributeEnabled);
#endif
}

void InternalSettingsGenerated::setXsltEnabled(bool xsltEnabled)
{
#if ENABLE(XSLT)
    m_page->settings().setXsltEnabled(xsltEnabled);
#else
    UNUSED_PARAM(xsltEnabled);
#endif
}

} // namespace WebCore
