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

#pragma once

#include <wtf/RefCounted.h>
#include <wtf/WeakPtr.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class Page;

class InternalSettingsGenerated : public RefCounted<InternalSettingsGenerated> {
public:
    explicit InternalSettingsGenerated(Page*);
    virtual ~InternalSettingsGenerated();

    void resetToConsistentState();

    void setAVKitContentSourceEnabled(bool aVKitContentSourceEnabled);
    void setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled);
    void setAcceleratedCompositingForFixedPositionEnabled(bool acceleratedCompositingForFixedPositionEnabled);
    void setAcceleratedDrawingEnabled(bool acceleratedDrawingEnabled);
    void setAcceleratedFiltersEnabled(bool acceleratedFiltersEnabled);
    void setAccentColorEnabled(bool accentColorEnabled);
    void setAccessHandleEnabled(bool accessHandleEnabled);
    void setAggressiveTileRetentionEnabled(bool aggressiveTileRetentionEnabled);
    void setAllowAnimationControlsOverride(bool allowAnimationControlsOverride);
    void setAllowContentSecurityPolicySourceStarToMatchAnyProtocol(bool allowContentSecurityPolicySourceStarToMatchAnyProtocol);
    void setAllowDisplayOfInsecureContent(bool allowDisplayOfInsecureContent);
    void setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs);
    void setAllowMediaContentTypesRequiringHardwareSupportAsFallback(bool allowMediaContentTypesRequiringHardwareSupportAsFallback);
    void setAllowMultiElementImplicitSubmission(bool allowMultiElementImplicitSubmission);
    void setAllowPrivacySensitiveOperationsInNonPersistentDataStores(bool allowPrivacySensitiveOperationsInNonPersistentDataStores);
    void setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent);
    void setAllowTopNavigationToDataURLs(bool allowTopNavigationToDataURLs);
    void setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs);
    void setAllowViewportShrinkToFitContent(bool allowViewportShrinkToFitContent);
    void setAllowWebGLInWorkers(bool allowWebGLInWorkers);
    void setAllowsAirPlayForMediaPlayback(bool allowsAirPlayForMediaPlayback);
    void setAllowsInlineMediaPlayback(bool allowsInlineMediaPlayback);
    void setAllowsInlineMediaPlaybackAfterFullscreen(bool allowsInlineMediaPlaybackAfterFullscreen);
    void setAllowsPictureInPictureMediaPlayback(bool allowsPictureInPictureMediaPlayback);
    void setAlternateFullScreenControlDesignEnabled(bool alternateFullScreenControlDesignEnabled);
    void setAltitudeAngleEnabled(bool altitudeAngleEnabled);
    void setAlwaysAllowLocalWebarchive(bool alwaysAllowLocalWebarchive);
    void setAnimatedImageAsyncDecodingEnabled(bool animatedImageAsyncDecodingEnabled);
    void setAnimatedImageDebugCanvasDrawingEnabled(bool animatedImageDebugCanvasDrawingEnabled);
    void setAppBadgeEnabled(bool appBadgeEnabled);
    void setAppHighlightsEnabled(bool appHighlightsEnabled);
    void setAppleMailPaginationQuirkEnabled(bool appleMailPaginationQuirkEnabled);
    void setApplePayCapabilityDisclosureAllowed(bool applePayCapabilityDisclosureAllowed);
    void setApplePayEnabled(bool applePayEnabled);
    void setAsyncClipboardAPIEnabled(bool asyncClipboardAPIEnabled);
    void setAsyncFrameScrollingEnabled(bool asyncFrameScrollingEnabled);
    void setAsyncOverflowScrollingEnabled(bool asyncOverflowScrollingEnabled);
    void setAsynchronousSpellCheckingEnabled(bool asynchronousSpellCheckingEnabled);
    void setAttachmentWideLayoutEnabled(bool attachmentWideLayoutEnabled);
    void setAudioControlsScaleWithPageZoom(bool audioControlsScaleWithPageZoom);
    void setAudioDescriptionsEnabled(bool audioDescriptionsEnabled);
    void setAuthorAndUserStylesEnabled(bool authorAndUserStylesEnabled);
    void setAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth(bool automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth);
    void setAutoscrollForDragAndDropEnabled(bool autoscrollForDragAndDropEnabled);
    void setAuxclickEventEnabled(bool auxclickEventEnabled);
    void setAzimuthAngleEnabled(bool azimuthAngleEnabled);
    void setBackgroundFetchAPIEnabled(bool backgroundFetchAPIEnabled);
    void setBackgroundShouldExtendBeyondPage(bool backgroundShouldExtendBeyondPage);
    void setBackgroundWebContentRunningBoardThrottlingEnabled(bool backgroundWebContentRunningBoardThrottlingEnabled);
    void setBackspaceKeyNavigationEnabled(bool backspaceKeyNavigationEnabled);
    void setBeaconAPIEnabled(bool beaconAPIEnabled);
    void setBidiContentAwarePasteEnabled(bool bidiContentAwarePasteEnabled);
    void setBlobFileAccessEnforcementEnabled(bool blobFileAccessEnforcementEnabled);
    void setBlockMediaLayerRehostingInWebContentProcess(bool blockMediaLayerRehostingInWebContentProcess);
    void setBroadcastChannelEnabled(bool broadcastChannelEnabled);
    void setCacheAPIEnabled(bool cacheAPIEnabled);
    void setCanvasColorSpaceEnabled(bool canvasColorSpaceEnabled);
    void setCanvasFiltersEnabled(bool canvasFiltersEnabled);
    void setCanvasFingerprintingQuirkEnabled(bool canvasFingerprintingQuirkEnabled);
    void setCanvasLayersEnabled(bool canvasLayersEnabled);
    void setCanvasPixelFormatEnabled(bool canvasPixelFormatEnabled);
    void setCanvasUsesAcceleratedDrawing(bool canvasUsesAcceleratedDrawing);
    void setCaretBrowsingEnabled(bool caretBrowsingEnabled);
    void setCaretPositionFromPointEnabled(bool caretPositionFromPointEnabled);
    void setChildProcessDebuggabilityEnabled(bool childProcessDebuggabilityEnabled);
    void setClearSiteDataExecutionContextsSupportEnabled(bool clearSiteDataExecutionContextsSupportEnabled);
    void setClearSiteDataHTTPHeaderEnabled(bool clearSiteDataHTTPHeaderEnabled);
    void setClientCoordinatesRelativeToLayoutViewport(bool clientCoordinatesRelativeToLayoutViewport);
    void setCloseWatcherEnabled(bool closeWatcherEnabled);
    void setColorFilterEnabled(bool colorFilterEnabled);
    void setCommandAttributesEnabled(bool commandAttributesEnabled);
    void setCompressionStreamEnabled(bool compressionStreamEnabled);
    void setContactPickerAPIEnabled(bool contactPickerAPIEnabled);
    void setContentChangeObserverEnabled(bool contentChangeObserverEnabled);
    void setContentDispositionAttachmentSandboxEnabled(bool contentDispositionAttachmentSandboxEnabled);
    void setContentInsetBackgroundFillEnabled(bool contentInsetBackgroundFillEnabled);
    void setContextMenuQRCodeDetectionEnabled(bool contextMenuQRCodeDetectionEnabled);
    void setCookieConsentAPIEnabled(bool cookieConsentAPIEnabled);
    void setCookieEnabled(bool cookieEnabled);
    void setCookieStoreAPIEnabled(bool cookieStoreAPIEnabled);
    void setCookieStoreAPIExtendedAttributesEnabled(bool cookieStoreAPIExtendedAttributesEnabled);
    void setCookieStoreManagerEnabled(bool cookieStoreManagerEnabled);
    void setCoreMathMLEnabled(bool coreMathMLEnabled);
    void setCrossDocumentViewTransitionsEnabled(bool crossDocumentViewTransitionsEnabled);
    void setCrossOriginCheckInGetMatchedCSSRulesDisabled(bool crossOriginCheckInGetMatchedCSSRulesDisabled);
    void setCrossOriginEmbedderPolicyEnabled(bool crossOriginEmbedderPolicyEnabled);
    void setCrossOriginOpenerPolicyEnabled(bool crossOriginOpenerPolicyEnabled);
    void setCSS3DTransformBackfaceVisibilityInteroperabilityEnabled(bool css3DTransformBackfaceVisibilityInteroperabilityEnabled);
    void setCSSAnchorPositioningEnabled(bool cssAnchorPositioningEnabled);
    void setCSSAnchorPositioningPositionVisibilityEnabled(bool cssAnchorPositioningPositionVisibilityEnabled);
    void setCSSAppearanceBaseEnabled(bool cssAppearanceBaseEnabled);
    void setCSSAxisRelativePositionKeywordsEnabled(bool cssAxisRelativePositionKeywordsEnabled);
    void setCSSBackgroundClipBorderAreaEnabled(bool cssBackgroundClipBorderAreaEnabled);
    void setCSSColorLayersEnabled(bool cssColorLayersEnabled);
    void setCSSConstrainedDynamicRangeLimitEnabled(bool cssConstrainedDynamicRangeLimitEnabled);
    void setCSSContrastColorEnabled(bool cssContrastColorEnabled);
    void setCSSCornerShapeEnabled(bool cssCornerShapeEnabled);
    void setCSSCounterStyleAtRuleImageSymbolsEnabled(bool cssCounterStyleAtRuleImageSymbolsEnabled);
    void setCSSDPropertyEnabled(bool cssDPropertyEnabled);
    void setCSSDynamicRangeLimitMixEnabled(bool cssDynamicRangeLimitMixEnabled);
    void setCSSFieldSizingEnabled(bool cssFieldSizingEnabled);
    void setCSSFontVariantEmojiEnabled(bool cssFontVariantEmojiEnabled);
    void setCSSInputSecurityEnabled(bool cssInputSecurityEnabled);
    void setCSSLineClampEnabled(bool cssLineClampEnabled);
    void setCSSLineFitEdgeEnabled(bool cssLineFitEdgeEnabled);
    void setCSSPaintingAPIEnabled(bool cssPaintingAPIEnabled);
    void setCSSProgressFunctionEnabled(bool cssProgressFunctionEnabled);
    void setCSSRandomFunctionEnabled(bool cssRandomFunctionEnabled);
    void setCSSRhythmicSizingEnabled(bool cssRhythmicSizingEnabled);
    void setCSSRubyAlignEnabled(bool cssRubyAlignEnabled);
    void setCSSRubyOverhangEnabled(bool cssRubyOverhangEnabled);
    void setCSSScrollAnchoringEnabled(bool cssScrollAnchoringEnabled);
    void setCSSScrollbarColorEnabled(bool cssScrollbarColorEnabled);
    void setCSSScrollbarGutterEnabled(bool cssScrollbarGutterEnabled);
    void setCSSScrollbarWidthEnabled(bool cssScrollbarWidthEnabled);
    void setCSSShapeFunctionEnabled(bool cssShapeFunctionEnabled);
    void setCSSTextAutospaceEnabled(bool cssTextAutospaceEnabled);
    void setCSSTextBoxTrimEnabled(bool cssTextBoxTrimEnabled);
    void setCSSTextGroupAlignEnabled(bool cssTextGroupAlignEnabled);
    void setCSSTextJustifyEnabled(bool cssTextJustifyEnabled);
    void setCSSTextSpacingTrimEnabled(bool cssTextSpacingTrimEnabled);
    void setCSSTextUnderlinePositionLeftRightEnabled(bool cssTextUnderlinePositionLeftRightEnabled);
    void setCSSTextWrapPrettyEnabled(bool cssTextWrapPrettyEnabled);
    void setCSSTransformStyleSeparatedEnabled(bool cssTransformStyleSeparatedEnabled);
    void setCSSTreeCountingFunctionsEnabled(bool cssTreeCountingFunctionsEnabled);
    void setCSSTypedOMColorEnabled(bool cssTypedOMColorEnabled);
    void setCSSURLIntegrityModifierEnabled(bool cssURLIntegrityModifierEnabled);
    void setCSSURLModifiersEnabled(bool cssURLModifiersEnabled);
    void setCSSUnprefixedBackdropFilterEnabled(bool cssUnprefixedBackdropFilterEnabled);
    void setCSSWordBreakAutoPhraseEnabled(bool cssWordBreakAutoPhraseEnabled);
    void setCursiveFontFamily(const String& cursiveFontFamily);
    void setDataListElementEnabled(bool dataListElementEnabled);
    void setDataTransferItemsEnabled(bool dataTransferItemsEnabled);
    void setDateTimeInputsEditableComponentsEnabled(bool dateTimeInputsEditableComponentsEnabled);
    void setDeclarativeWebPush(bool declarativeWebPush);
    void setDefaultFixedFontSize(double defaultFixedFontSize);
    void setDefaultFontSize(double defaultFontSize);
    void setDefaultTextEncodingName(const String& defaultTextEncodingName);
    void setDefaultVideoPosterURL(const String& defaultVideoPosterURL);
    void setDeprecationReportingEnabled(bool deprecationReportingEnabled);
    void setDetachableMediaSourceEnabled(bool detachableMediaSourceEnabled);
    void setDetailsAutoExpandEnabled(bool detailsAutoExpandEnabled);
    void setDeveloperExtrasEnabled(bool developerExtrasEnabled);
    void setDeviceHeight(uint32_t deviceHeight);
    void setDeviceOrientationEventEnabled(bool deviceOrientationEventEnabled);
    void setDeviceOrientationPermissionAPIEnabled(bool deviceOrientationPermissionAPIEnabled);
    void setDeviceWidth(uint32_t deviceWidth);
    void setDevolvableWidgetsEnabled(bool devolvableWidgetsEnabled);
    void setDiagnosticLoggingEnabled(bool diagnosticLoggingEnabled);
    void setDigitalCredentialsEnabled(bool digitalCredentialsEnabled);
    void setDirectoryUploadEnabled(bool directoryUploadEnabled);
    void setDisabledAdaptationsMetaTagEnabled(bool disabledAdaptationsMetaTagEnabled);
    void setDOMAudioSessionEnabled(bool domAudioSessionEnabled);
    void setDOMAudioSessionFullEnabled(bool domAudioSessionFullEnabled);
    void setDOMPasteAccessRequestsEnabled(bool domPasteAccessRequestsEnabled);
    void setDOMPasteAllowed(bool domPasteAllowed);
    void setDOMTestingAPIsEnabled(bool domTestingAPIsEnabled);
    void setDOMTimersThrottlingEnabled(bool domTimersThrottlingEnabled);
    void setDownloadAttributeEnabled(bool downloadAttributeEnabled);
    void setDynamicSiteInterventionsEnabled(bool dynamicSiteInterventionsEnabled);
    void setEmbedElementEnabled(bool embedElementEnabled);
    void setEnableElementCurrentCSSZoom(bool enableElementCurrentCSSZoom);
    void setEnableInheritURIQueryComponent(bool enableInheritURIQueryComponent);
    void setEncryptedMediaAPIEnabled(bool encryptedMediaAPIEnabled);
    void setEnterKeyHintEnabled(bool enterKeyHintEnabled);
    void setEventHandlerDrivenSmoothKeyboardScrollingEnabled(bool eventHandlerDrivenSmoothKeyboardScrollingEnabled);
    void setEventTimingEnabled(bool eventTimingEnabled);
    void setExposeCaptureDevicesAfterCaptureEnabled(bool exposeCaptureDevicesAfterCaptureEnabled);
    void setExposeDefaultSpeakerAsSpecificDeviceEnabled(bool exposeDefaultSpeakerAsSpecificDeviceEnabled);
    void setExposeSpeakersEnabled(bool exposeSpeakersEnabled);
    void setExposeSpeakersWithoutMicrophoneEnabled(bool exposeSpeakersWithoutMicrophoneEnabled);
    void setExtendedAudioDescriptionsEnabled(bool extendedAudioDescriptionsEnabled);
    void setFantasyFontFamily(const String& fantasyFontFamily);
    void setFileReaderAPIEnabled(bool fileReaderAPIEnabled);
    void setFileSystemEnabled(bool fileSystemEnabled);
    void setFileSystemWritableStreamEnabled(bool fileSystemWritableStreamEnabled);
    void setFilterLinkDecorationByDefaultEnabled(bool filterLinkDecorationByDefaultEnabled);
    void setFixedBackgroundsPaintRelativeToDocument(bool fixedBackgroundsPaintRelativeToDocument);
    void setFixedElementsLayoutRelativeToFrame(bool fixedElementsLayoutRelativeToFrame);
    void setFixedFontFamily(const String& fixedFontFamily);
    void setFlexFormattingContextIntegrationEnabled(bool flexFormattingContextIntegrationEnabled);
    void setFontFallbackPrefersPictographs(bool fontFallbackPrefersPictographs);
    void setForceCompositingMode(bool forceCompositingMode);
    void setForceFTPDirectoryListings(bool forceFTPDirectoryListings);
    void setForceLockdownFontParserEnabled(bool forceLockdownFontParserEnabled);
    void setForceWebGLUsesLowPower(bool forceWebGLUsesLowPower);
    void setFormControlRefreshEnabled(bool formControlRefreshEnabled);
    void setFTPDirectoryTemplatePath(const String& ftpDirectoryTemplatePath);
    void setFTPEnabled(bool ftpEnabled);
    void setFullScreenEnabled(bool fullScreenEnabled);
    void setFullScreenKeyboardLock(bool fullScreenKeyboardLock);
    void setFullscreenRequirementForScreenOrientationLockingEnabled(bool fullscreenRequirementForScreenOrientationLockingEnabled);
    void setFullscreenSceneAspectRatioLockingEnabled(bool fullscreenSceneAspectRatioLockingEnabled);
    void setFullscreenSceneDimmingEnabled(bool fullscreenSceneDimmingEnabled);
    void setGamepadTriggerRumbleEnabled(bool gamepadTriggerRumbleEnabled);
    void setGamepadVibrationActuatorEnabled(bool gamepadVibrationActuatorEnabled);
    void setGamepadsEnabled(bool gamepadsEnabled);
    void setGenericCueAPIEnabled(bool genericCueAPIEnabled);
    void setGeolocationAPIEnabled(bool geolocationAPIEnabled);
    void setGeolocationFloorLevelEnabled(bool geolocationFloorLevelEnabled);
    void setGetCoalescedEventsEnabled(bool getCoalescedEventsEnabled);
    void setGetPredictedEventsEnabled(bool getPredictedEventsEnabled);
    void setGetUserMediaRequiresFocus(bool getUserMediaRequiresFocus);
    void setGoogleAntiFlickerOptimizationQuirkEnabled(bool googleAntiFlickerOptimizationQuirkEnabled);
    void setGraphicsContextFiltersEnabled(bool graphicsContextFiltersEnabled);
    void setHiddenPageCSSAnimationSuspensionEnabled(bool hiddenPageCSSAnimationSuspensionEnabled);
    void setHiddenPageDOMTimerThrottlingAutoIncreases(bool hiddenPageDOMTimerThrottlingAutoIncreases);
    void setHiddenPageDOMTimerThrottlingEnabled(bool hiddenPageDOMTimerThrottlingEnabled);
    void setHiddenUntilFoundEnabled(bool hiddenUntilFoundEnabled);
    void setHostedBlurMaterialInMediaControlsEnabled(bool hostedBlurMaterialInMediaControlsEnabled);
    void setHTMLLegacyAttributeValueSerializationEnabled(bool htmlLegacyAttributeValueSerializationEnabled);
    void setHttpEquivEnabled(bool httpEquivEnabled);
    void setHttpsByDefault(bool httpsByDefault);
    void setIFrameResourceMonitoringEnabled(bool iFrameResourceMonitoringEnabled);
    void setIFrameResourceMonitoringTestingSettingsEnabled(bool iFrameResourceMonitoringTestingSettingsEnabled);
    void setIOSurfaceLosslessCompressionEnabled(bool iOSurfaceLosslessCompressionEnabled);
    void setIPAddressAndLocalhostMixedContentUpgradeTestingEnabled(bool iPAddressAndLocalhostMixedContentUpgradeTestingEnabled);
    void setICECandidateFilteringEnabled(bool iceCandidateFilteringEnabled);
    void setIdempotentModeAutosizingOnlyHonorsPercentages(bool idempotentModeAutosizingOnlyHonorsPercentages);
    void setIgnoreIframeEmbeddingProtectionsEnabled(bool ignoreIframeEmbeddingProtectionsEnabled);
    void setImageAnalysisDuringFindInPageEnabled(bool imageAnalysisDuringFindInPageEnabled);
    void setImageAnimationControlEnabled(bool imageAnimationControlEnabled);
    void setImageCaptureEnabled(bool imageCaptureEnabled);
    void setImageControlsEnabled(bool imageControlsEnabled);
    void setImageSubsamplingEnabled(bool imageSubsamplingEnabled);
    void setImagesEnabled(bool imagesEnabled);
    void setInWindowFullscreenEnabled(bool inWindowFullscreenEnabled);
    void setIncludeIgnoredInCoreAXTree(bool includeIgnoredInCoreAXTree);
    void setIncompleteImageBorderEnabled(bool incompleteImageBorderEnabled);
    void setIncrementalPDFLoadingEnabled(bool incrementalPDFLoadingEnabled);
    void setIncrementalRenderingSuppressionTimeoutInSeconds(double incrementalRenderingSuppressionTimeoutInSeconds);
    void setIndexedDBAPIEnabled(bool indexedDBAPIEnabled);
    void setInlineMediaPlaybackRequiresPlaysInlineAttribute(bool inlineMediaPlaybackRequiresPlaysInlineAttribute);
    void setInputMethodUsesCorrectKeyEventOrder(bool inputMethodUsesCorrectKeyEventOrder);
    void setInputTypeColorEnabled(bool inputTypeColorEnabled);
    void setInputTypeColorEnhancementsEnabled(bool inputTypeColorEnhancementsEnabled);
    void setInputTypeDateEnabled(bool inputTypeDateEnabled);
    void setInputTypeDateTimeLocalEnabled(bool inputTypeDateTimeLocalEnabled);
    void setInputTypeMonthEnabled(bool inputTypeMonthEnabled);
    void setInputTypeTimeEnabled(bool inputTypeTimeEnabled);
    void setInputTypeWeekEnabled(bool inputTypeWeekEnabled);
    void setInspectorMaximumResourcesContentSize(uint32_t inspectorMaximumResourcesContentSize);
    void setInspectorSupportsShowingCertificate(bool inspectorSupportsShowingCertificate);
    void setInteractionRegionInlinePadding(double interactionRegionInlinePadding);
    void setInteractionRegionMinimumCornerRadius(double interactionRegionMinimumCornerRadius);
    void setInteractionRegionsEnabled(bool interactionRegionsEnabled);
    void setInteractiveFormValidationEnabled(bool interactiveFormValidationEnabled);
    void setInterruptAudioOnPageVisibilityChangeEnabled(bool interruptAudioOnPageVisibilityChangeEnabled);
    void setInterruptVideoOnPageVisibilityChangeEnabled(bool interruptVideoOnPageVisibilityChangeEnabled);
    void setInvisibleAutoplayNotPermitted(bool invisibleAutoplayNotPermitted);
    void setIsFirstPartyWebsiteDataRemovalDisabled(bool isFirstPartyWebsiteDataRemovalDisabled);
    void setIsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled(bool isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled);
    void setIsFirstPartyWebsiteDataRemovalReproTestingEnabled(bool isFirstPartyWebsiteDataRemovalReproTestingEnabled);
    void setIsPerActivityStateCPUUsageMeasurementEnabled(bool isPerActivityStateCPUUsageMeasurementEnabled);
    void setIsPostBackgroundingCPUUsageMeasurementEnabled(bool isPostBackgroundingCPUUsageMeasurementEnabled);
    void setIsPostBackgroundingMemoryUsageMeasurementEnabled(bool isPostBackgroundingMemoryUsageMeasurementEnabled);
    void setIsPostLoadCPUUsageMeasurementEnabled(bool isPostLoadCPUUsageMeasurementEnabled);
    void setIsPostLoadMemoryUsageMeasurementEnabled(bool isPostLoadMemoryUsageMeasurementEnabled);
    void setIsSameSiteStrictEnforcementEnabled(bool isSameSiteStrictEnforcementEnabled);
    void setIsThirdPartyCookieBlockingDisabled(bool isThirdPartyCookieBlockingDisabled);
    void setItpDebugModeEnabled(bool itpDebugModeEnabled);
    void setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard);
    void setJavaScriptCanOpenWindowsAutomatically(bool javaScriptCanOpenWindowsAutomatically);
    void setLangAttributeAwareFormControlUIEnabled(bool langAttributeAwareFormControlUIEnabled);
    void setLargeImageAsyncDecodingEnabled(bool largeImageAsyncDecodingEnabled);
    void setLayerBasedSVGEngineEnabled(bool layerBasedSVGEngineEnabled);
    void setLayoutFallbackWidth(uint32_t layoutFallbackWidth);
    void setLayoutViewportHeightExpansionFactor(double layoutViewportHeightExpansionFactor);
    void setLazyIframeLoadingEnabled(bool lazyIframeLoadingEnabled);
    void setLazyImageLoadingEnabled(bool lazyImageLoadingEnabled);
    void setLegacyEncryptedMediaAPIEnabled(bool legacyEncryptedMediaAPIEnabled);
    void setLegacyLineLayoutVisualCoverageEnabled(bool legacyLineLayoutVisualCoverageEnabled);
    void setLegacyOverflowScrollingTouchEnabled(bool legacyOverflowScrollingTouchEnabled);
    void setLegacyPluginQuirkForMailSignaturesEnabled(bool legacyPluginQuirkForMailSignaturesEnabled);
    void setLegacyWebRTCOfferOptionsEnabled(bool legacyWebRTCOfferOptionsEnabled);
    void setLimitedMatroskaSupportEnabled(bool limitedMatroskaSupportEnabled);
    void setLinearMediaPlayerEnabled(bool linearMediaPlayerEnabled);
    void setLinkDNSPrefetchEnabled(bool linkDNSPrefetchEnabled);
    void setLinkPreconnectEarlyHintsEnabled(bool linkPreconnectEarlyHintsEnabled);
    void setLinkPreconnectEnabled(bool linkPreconnectEnabled);
    void setLinkPrefetchEnabled(bool linkPrefetchEnabled);
    void setLinkPreloadEnabled(bool linkPreloadEnabled);
    void setLinkSanitizerEnabled(bool linkSanitizerEnabled);
    void setLoadDeferringEnabled(bool loadDeferringEnabled);
    void setLoadWebArchiveWithEphemeralStorageEnabled(bool loadWebArchiveWithEphemeralStorageEnabled);
    void setLoadsImagesAutomatically(bool loadsImagesAutomatically);
    void setLocalFileContentSniffingEnabled(bool localFileContentSniffingEnabled);
    void setLocalNetworkAccessEnabled(bool localNetworkAccessEnabled);
    void setLocalStorageDatabasePath(const String& localStorageDatabasePath);
    void setLocalStorageEnabled(bool localStorageEnabled);
    void setLockdownFontParserEnabled(bool lockdownFontParserEnabled);
    void setLoginStatusAPIEnabled(bool loginStatusAPIEnabled);
    void setLoginStatusAPIRequiresWebAuthnEnabled(bool loginStatusAPIRequiresWebAuthnEnabled);
    void setLogsPageMessagesToSystemConsoleEnabled(bool logsPageMessagesToSystemConsoleEnabled);
    void setMainContentUserGestureOverrideEnabled(bool mainContentUserGestureOverrideEnabled);
    void setManageCaptureStatusBarInGPUProcessEnabled(bool manageCaptureStatusBarInGPUProcessEnabled);
    void setManagedMediaSourceEnabled(bool managedMediaSourceEnabled);
    void setManagedMediaSourceHighThreshold(double managedMediaSourceHighThreshold);
    void setManagedMediaSourceLowThreshold(double managedMediaSourceLowThreshold);
    void setManagedMediaSourceNeedsAirPlay(bool managedMediaSourceNeedsAirPlay);
    void setMasonryEnabled(bool masonryEnabled);
    void setMathMLEnabled(bool mathMLEnabled);
    void setMaxParseDuration(double maxParseDuration);
    void setMaximumHTMLParserDOMTreeDepth(uint32_t maximumHTMLParserDOMTreeDepth);
    void setMaximumSourceBufferSize(uint32_t maximumSourceBufferSize);
    void setMediaCapabilitiesEnabled(bool mediaCapabilitiesEnabled);
    void setMediaCapabilitiesExtensionsEnabled(bool mediaCapabilitiesExtensionsEnabled);
    void setMediaCapabilityGrantsEnabled(bool mediaCapabilityGrantsEnabled);
    void setMediaCaptureRequiresSecureConnection(bool mediaCaptureRequiresSecureConnection);
    void setMediaControlsContextMenusEnabled(bool mediaControlsContextMenusEnabled);
    void setMediaControlsScaleWithPageZoom(bool mediaControlsScaleWithPageZoom);
    void setMediaDataLoadsAutomatically(bool mediaDataLoadsAutomatically);
    void setMediaDevicesEnabled(bool mediaDevicesEnabled);
    void setMediaEnabled(bool mediaEnabled);
    void setMediaKeysStorageDirectory(const String& mediaKeysStorageDirectory);
    void setMediaPlaybackEnabled(bool mediaPlaybackEnabled);
    void setMediaPreferredFullscreenWidth(double mediaPreferredFullscreenWidth);
    void setMediaPreloadingEnabled(bool mediaPreloadingEnabled);
    void setMediaRecorderEnabled(bool mediaRecorderEnabled);
    void setMediaRecorderEnabledWebM(bool mediaRecorderEnabledWebM);
    void setMediaSessionCaptureToggleAPIEnabled(bool mediaSessionCaptureToggleAPIEnabled);
    void setMediaSessionCoordinatorEnabled(bool mediaSessionCoordinatorEnabled);
    void setMediaSessionEnabled(bool mediaSessionEnabled);
    void setMediaSessionPlaylistEnabled(bool mediaSessionPlaylistEnabled);
    void setMediaSourceEnabled(bool mediaSourceEnabled);
    void setMediaSourceInWorkerEnabled(bool mediaSourceInWorkerEnabled);
    void setMediaSourcePrefersDecompressionSession(bool mediaSourcePrefersDecompressionSession);
    void setMediaStreamTrackProcessingEnabled(bool mediaStreamTrackProcessingEnabled);
    void setMediaTypeOverride(const String& mediaTypeOverride);
    void setMediaUserGestureInheritsFromDocument(bool mediaUserGestureInheritsFromDocument);
    void setMetaViewportInteractiveWidgetEnabled(bool metaViewportInteractiveWidgetEnabled);
    void setMinimumFontSize(double minimumFontSize);
    void setMinimumLogicalFontSize(double minimumLogicalFontSize);
    void setMinimumZoomFontSize(double minimumZoomFontSize);
    void setMockCaptureDevicesEnabled(bool mockCaptureDevicesEnabled);
    void setMockScrollbarsControllerEnabled(bool mockScrollbarsControllerEnabled);
    void setModelElementEnabled(bool modelElementEnabled);
    void setModelNoPortalAttributeEnabled(bool modelNoPortalAttributeEnabled);
    void setModelProcessEnabled(bool modelProcessEnabled);
    void setMomentumScrollingAnimatorEnabled(bool momentumScrollingAnimatorEnabled);
    void setMouseEventsSimulationEnabled(bool mouseEventsSimulationEnabled);
    void setMutationEventsEnabled(bool mutationEventsEnabled);
    void setMuteCameraOnMicrophoneInterruptionEnabled(bool muteCameraOnMicrophoneInterruptionEnabled);
    void setNavigationAPIEnabled(bool navigationAPIEnabled);
    void setNavigatorUserAgentDataJavaScriptAPIEnabled(bool navigatorUserAgentDataJavaScriptAPIEnabled);
    void setNeedsAdobeFrameReloadingQuirk(bool needsAdobeFrameReloadingQuirk);
    void setNeedsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk(bool needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk);
    void setNeedsFrameNameFallbackToIdQuirk(bool needsFrameNameFallbackToIdQuirk);
    void setNeedsKeyboardEventDisambiguationQuirks(bool needsKeyboardEventDisambiguationQuirks);
    void setNeedsSiteSpecificQuirks(bool needsSiteSpecificQuirks);
    void setNeedsStorageAccessFromFileURLsQuirk(bool needsStorageAccessFromFileURLsQuirk);
    void setNotificationEventEnabled(bool notificationEventEnabled);
    void setNotificationsEnabled(bool notificationsEnabled);
    void setObservableEnabled(bool observableEnabled);
    void setOffscreenCanvasEnabled(bool offscreenCanvasEnabled);
    void setOffscreenCanvasInWorkersEnabled(bool offscreenCanvasInWorkersEnabled);
    void setOpportunisticSweepingAndGarbageCollectionEnabled(bool opportunisticSweepingAndGarbageCollectionEnabled);
    void setOptInPartitionedCookiesEnabled(bool optInPartitionedCookiesEnabled);
    void setOverlappingBackingStoreProvidersEnabled(bool overlappingBackingStoreProvidersEnabled);
    void setOverscrollBehaviorEnabled(bool overscrollBehaviorEnabled);
    void setPageAtRuleMarginDescriptorsEnabled(bool pageAtRuleMarginDescriptorsEnabled);
    void setPassiveTouchListenersAsDefaultOnDocument(bool passiveTouchListenersAsDefaultOnDocument);
    void setPassiveWheelListenersAsDefaultOnDocument(bool passiveWheelListenersAsDefaultOnDocument);
    void setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds);
    void setPasswordEchoEnabled(bool passwordEchoEnabled);
    void setPaymentRequestEnabled(bool paymentRequestEnabled);
    void setPDFJSViewerEnabled(bool pdfJSViewerEnabled);
    void setPDFPluginEnabled(bool pdfPluginEnabled);
    void setPDFPluginHUDEnabled(bool pdfPluginHUDEnabled);
    void setPDFPluginPageNumberIndicatorEnabled(bool pdfPluginPageNumberIndicatorEnabled);
    void setPeerConnectionEnabled(bool peerConnectionEnabled);
    void setPeerConnectionVideoScalingAdaptationDisabled(bool peerConnectionVideoScalingAdaptationDisabled);
    void setPerElementSpeakerSelectionEnabled(bool perElementSpeakerSelectionEnabled);
    void setPermissionsAPIEnabled(bool permissionsAPIEnabled);
    void setPictographFontFamily(const String& pictographFontFamily);
    void setPictureInPictureAPIEnabled(bool pictureInPictureAPIEnabled);
    void setPictureInPicturePlaybackStateEnabled(bool pictureInPicturePlaybackStateEnabled);
    void setPointerLockEnabled(bool pointerLockEnabled);
    void setPointerLockOptionsEnabled(bool pointerLockOptionsEnabled);
    void setPopoverAttributeEnabled(bool popoverAttributeEnabled);
    void setPreferMIMETypeForImages(bool preferMIMETypeForImages);
    void setPreferPageRenderingUpdatesNear60FPSEnabled(bool preferPageRenderingUpdatesNear60FPSEnabled);
    void setPreferSpatialAudioExperience(bool preferSpatialAudioExperience);
    void setPreventKeyboardDOMEventDispatch(bool preventKeyboardDOMEventDispatch);
    void setPrivateClickMeasurementDebugModeEnabled(bool privateClickMeasurementDebugModeEnabled);
    void setPrivateClickMeasurementEnabled(bool privateClickMeasurementEnabled);
    void setPrivateClickMeasurementFraudPreventionEnabled(bool privateClickMeasurementFraudPreventionEnabled);
    void setPrivateTokenUsageByThirdPartyEnabled(bool privateTokenUsageByThirdPartyEnabled);
    void setPropagateDamagingInformation(bool propagateDamagingInformation);
    void setPunchOutWhiteBackgroundsInDarkMode(bool punchOutWhiteBackgroundsInDarkMode);
    void setPushAPIEnabled(bool pushAPIEnabled);
    void setRemoteMediaSessionManagerEnabled(bool remoteMediaSessionManagerEnabled);
    void setRemotePlaybackEnabled(bool remotePlaybackEnabled);
    void setRemoteSnapshottingEnabled(bool remoteSnapshottingEnabled);
    void setRemoveBackgroundEnabled(bool removeBackgroundEnabled);
    void setRequestIdleCallbackEnabled(bool requestIdleCallbackEnabled);
    void setRequestStorageAccessThrowsExceptionUntilReload(bool requestStorageAccessThrowsExceptionUntilReload);
    void setRequestVideoFrameCallbackEnabled(bool requestVideoFrameCallbackEnabled);
    void setRequireUAGetDisplayMediaPrompt(bool requireUAGetDisplayMediaPrompt);
    void setRequiresPageVisibilityForVideoToBeNowPlaying(bool requiresPageVisibilityForVideoToBeNowPlaying);
    void setRequiresPageVisibilityToPlayAudio(bool requiresPageVisibilityToPlayAudio);
    void setRequiresUserGestureForAudioPlayback(bool requiresUserGestureForAudioPlayback);
    void setRequiresUserGestureForVideoPlayback(bool requiresUserGestureForVideoPlayback);
    void setRequiresUserGestureToLoadVideo(bool requiresUserGestureToLoadVideo);
    void setResourceLoadSchedulingEnabled(bool resourceLoadSchedulingEnabled);
    void setResourceUsageOverlayVisible(bool resourceUsageOverlayVisible);
    void setRespondToThermalPressureAggressively(bool respondToThermalPressureAggressively);
    void setRubberBandingForSubScrollableRegionsEnabled(bool rubberBandingForSubScrollableRegionsEnabled);
    void setSKAttributionEnabled(bool sKAttributionEnabled);
    void setSampledPageTopColorMaxDifference(double sampledPageTopColorMaxDifference);
    void setSampledPageTopColorMinHeight(double sampledPageTopColorMinHeight);
    void setSansSerifFontFamily(const String& sansSerifFontFamily);
    void setScopedCustomElementRegistryEnabled(bool scopedCustomElementRegistryEnabled);
    void setScreenCaptureEnabled(bool screenCaptureEnabled);
    void setScreenOrientationAPIEnabled(bool screenOrientationAPIEnabled);
    void setScreenOrientationLockingAPIEnabled(bool screenOrientationLockingAPIEnabled);
    void setScreenTimeEnabled(bool screenTimeEnabled);
    void setScreenWakeLockAPIEnabled(bool screenWakeLockAPIEnabled);
    void setScriptEnabled(bool scriptEnabled);
    void setScriptMarkupEnabled(bool scriptMarkupEnabled);
    void setScriptTrackingPrivacyLoggingEnabled(bool scriptTrackingPrivacyLoggingEnabled);
    void setScrollAnimatorEnabled(bool scrollAnimatorEnabled);
    void setScrollDrivenAnimationsEnabled(bool scrollDrivenAnimationsEnabled);
    void setScrollToTextFragmentEnabled(bool scrollToTextFragmentEnabled);
    void setScrollToTextFragmentFeatureDetectionEnabled(bool scrollToTextFragmentFeatureDetectionEnabled);
    void setScrollToTextFragmentGenerationEnabled(bool scrollToTextFragmentGenerationEnabled);
    void setScrollToTextFragmentIndicatorEnabled(bool scrollToTextFragmentIndicatorEnabled);
    void setScrollToTextFragmentMarkingEnabled(bool scrollToTextFragmentMarkingEnabled);
    void setScrollendEventEnabled(bool scrollendEventEnabled);
    void setScrollingCoordinatorEnabled(bool scrollingCoordinatorEnabled);
    void setScrollingPerformanceTestingEnabled(bool scrollingPerformanceTestingEnabled);
    void setScrollingTreeIncludesFrames(bool scrollingTreeIncludesFrames);
    void setSecureContextChecksEnabled(bool secureContextChecksEnabled);
    void setSelectShowPickerEnabled(bool selectShowPickerEnabled);
    void setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled);
    void setSelectionHonorsOverflowScrolling(bool selectionHonorsOverflowScrolling);
    void setSerifFontFamily(const String& serifFontFamily);
    void setServiceControlsEnabled(bool serviceControlsEnabled);
    void setServiceWorkerInstallEventEnabled(bool serviceWorkerInstallEventEnabled);
    void setServiceWorkerNavigationPreloadEnabled(bool serviceWorkerNavigationPreloadEnabled);
    void setServiceWorkersEnabled(bool serviceWorkersEnabled);
    void setServiceWorkersUserGestureEnabled(bool serviceWorkersUserGestureEnabled);
    void setSessionStorageQuota(uint32_t sessionStorageQuota);
    void setShadowRootReferenceTargetEnabled(bool shadowRootReferenceTargetEnabled);
    void setShadowRootReferenceTargetEnabledForAriaOwns(bool shadowRootReferenceTargetEnabledForAriaOwns);
    void setShapeDetection(bool shapeDetection);
    void setSharedWorkerEnabled(bool sharedWorkerEnabled);
    void setShouldAllowUserInstalledFonts(bool shouldAllowUserInstalledFonts);
    void setShouldConvertInvalidURLsToBlank(bool shouldConvertInvalidURLsToBlank);
    void setShouldConvertPositionStyleOnCopy(bool shouldConvertPositionStyleOnCopy);
    void setShouldDecidePolicyBeforeLoadingQuickLookPreview(bool shouldDecidePolicyBeforeLoadingQuickLookPreview);
    void setShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint(bool shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint);
    void setShouldDispatchSyntheticMouseEventsWhenModifyingSelection(bool shouldDispatchSyntheticMouseEventsWhenModifyingSelection);
    void setShouldDispatchSyntheticMouseOutAfterSyntheticClick(bool shouldDispatchSyntheticMouseOutAfterSyntheticClick);
    void setShouldDisplayCaptions(bool shouldDisplayCaptions);
    void setShouldDisplaySubtitles(bool shouldDisplaySubtitles);
    void setShouldDisplayTextDescriptions(bool shouldDisplayTextDescriptions);
    void setShouldDropNearSuspendedAssertionAfterDelay(bool shouldDropNearSuspendedAssertionAfterDelay);
    void setShouldEnableTextAutosizingBoost(bool shouldEnableTextAutosizingBoost);
    void setShouldIgnoreFontLoadCompletions(bool shouldIgnoreFontLoadCompletions);
    void setShouldIgnoreMetaViewport(bool shouldIgnoreMetaViewport);
    void setShouldInjectUserScriptsInInitialEmptyDocument(bool shouldInjectUserScriptsInInitialEmptyDocument);
    void setShouldPrintBackgrounds(bool shouldPrintBackgrounds);
    void setShouldRespectImageOrientation(bool shouldRespectImageOrientation);
    void setShouldRestrictBaseURLSchemes(bool shouldRestrictBaseURLSchemes);
    void setShouldSuppressTextInputFromEditingDuringProvisionalNavigation(bool shouldSuppressTextInputFromEditingDuringProvisionalNavigation);
    void setShouldTakeNearSuspendedAssertions(bool shouldTakeNearSuspendedAssertions);
    void setShouldUseModernAVContentKeySession(bool shouldUseModernAVContentKeySession);
    void setShouldUseServiceWorkerShortTimeout(bool shouldUseServiceWorkerShortTimeout);
    void setShowDebugBorders(bool showDebugBorders);
    void setShowFrameProcessBorders(bool showFrameProcessBorders);
    void setShowMediaStatsContextMenuItemEnabled(bool showMediaStatsContextMenuItemEnabled);
    void setShowModalDialogEnabled(bool showModalDialogEnabled);
    void setShowRepaintCounter(bool showRepaintCounter);
    void setShowTiledScrollingIndicator(bool showTiledScrollingIndicator);
    void setShowsToolTipOverTruncatedText(bool showsToolTipOverTruncatedText);
    void setShowsURLsInToolTips(bool showsURLsInToolTips);
    void setShrinksStandaloneImagesToFit(bool shrinksStandaloneImagesToFit);
    void setSidewaysWritingModesEnabled(bool sidewaysWritingModesEnabled);
    void setSiteIsolationEnabled(bool siteIsolationEnabled);
    void setSiteIsolationSharedProcessEnabled(bool siteIsolationSharedProcessEnabled);
    void setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled);
    void setSourceBufferChangeTypeEnabled(bool sourceBufferChangeTypeEnabled);
    void setSpatialImageControlsEnabled(bool spatialImageControlsEnabled);
    void setSpatialNavigationEnabled(bool spatialNavigationEnabled);
    void setSpeakerSelectionRequiresUserGesture(bool speakerSelectionRequiresUserGesture);
    void setSpeechRecognitionEnabled(bool speechRecognitionEnabled);
    void setSpeechSynthesisAPIEnabled(bool speechSynthesisAPIEnabled);
    void setSpringTimingFunctionEnabled(bool springTimingFunctionEnabled);
    void setStandalone(bool standalone);
    void setStandardFontFamily(const String& standardFontFamily);
    void setStorageAPIEnabled(bool storageAPIEnabled);
    void setStorageAPIEstimateEnabled(bool storageAPIEstimateEnabled);
    void setStorageAccessAPIPerPageScopeEnabled(bool storageAccessAPIPerPageScopeEnabled);
    void setSupportHDRCompositorTonemappingEnabled(bool supportHDRCompositorTonemappingEnabled);
    void setSupportHDRDisplayEnabled(bool supportHDRDisplayEnabled);
    void setSuppressHDRShouldBeAllowedInFullscreenVideo(bool suppressHDRShouldBeAllowedInFullscreenVideo);
    void setSuppressesIncrementalRendering(bool suppressesIncrementalRendering);
    void setSwitchControlEnabled(bool switchControlEnabled);
    void setSystemPreviewEnabled(bool systemPreviewEnabled);
    void setTargetTextPseudoElementEnabled(bool targetTextPseudoElementEnabled);
    void setTelephoneNumberParsingEnabled(bool telephoneNumberParsingEnabled);
    void setTemporaryTileCohortRetentionEnabled(bool temporaryTileCohortRetentionEnabled);
    void setTextAnimationsEnabled(bool textAnimationsEnabled);
    void setTextAreasAreResizable(bool textAreasAreResizable);
    void setTextAutosizingEnabled(bool textAutosizingEnabled);
    void setTextAutosizingEnabledAtLargeInitialScale(bool textAutosizingEnabledAtLargeInitialScale);
    void setTextAutosizingUsesIdempotentMode(bool textAutosizingUsesIdempotentMode);
    void setTextAutosizingWindowSizeOverrideHeight(uint32_t textAutosizingWindowSizeOverrideHeight);
    void setTextAutosizingWindowSizeOverrideWidth(uint32_t textAutosizingWindowSizeOverrideWidth);
    void setTextInteractionEnabled(bool textInteractionEnabled);
    void setTextRecognitionInVideosEnabled(bool textRecognitionInVideosEnabled);
    void setTextTracksInMSEEnabled(bool textTracksInMSEEnabled);
    void setThreadedAnimationResolutionEnabled(bool threadedAnimationResolutionEnabled);
    void setThumbAndTrackPseudoElementsEnabled(bool thumbAndTrackPseudoElementsEnabled);
    void setTopContentInsetBackgroundCanChangeAfterScrolling(bool topContentInsetBackgroundCanChangeAfterScrolling);
    void setTouchEventDOMAttributesEnabled(bool touchEventDOMAttributesEnabled);
    void setTouchEventEmulationEnabled(bool touchEventEmulationEnabled);
    void setTouchInputCompatibilityEnabled(bool touchInputCompatibilityEnabled);
    void setTrackConfigurationEnabled(bool trackConfigurationEnabled);
    void setTreatIPAddressAsDomain(bool treatIPAddressAsDomain);
    void setTreatsAnyTextCSSLinkAsStylesheet(bool treatsAnyTextCSSLinkAsStylesheet);
    void setTrustedTypesEnabled(bool trustedTypesEnabled);
    void setUAVisualTransitionDetectionEnabled(bool uAVisualTransitionDetectionEnabled);
    void setUndoManagerAPIEnabled(bool undoManagerAPIEnabled);
    void setUnhandledPromiseRejectionToConsoleEnabled(bool unhandledPromiseRejectionToConsoleEnabled);
    void setUnifiedPDFEnabled(bool unifiedPDFEnabled);
    void setUnifiedTextCheckerEnabled(bool unifiedTextCheckerEnabled);
    void setUnifyDamagedRegions(bool unifyDamagedRegions);
    void setUpgradeMixedContentEnabled(bool upgradeMixedContentEnabled);
    void setURLPatternAPIEnabled(bool urlPatternAPIEnabled);
    void setUseAnonymousModeWhenFetchingMaskImages(bool useAnonymousModeWhenFetchingMaskImages);
    void setUseAsyncUIKitInteractions(bool useAsyncUIKitInteractions);
    void setUseDamagingInformationForCompositing(bool useDamagingInformationForCompositing);
    void setUseGPUProcessForWebGLEnabled(bool useGPUProcessForWebGLEnabled);
    void setUseGiantTiles(bool useGiantTiles);
    void setUseIFCForSVGText(bool useIFCForSVGText);
    void setUseImageDocumentForSubframePDF(bool useImageDocumentForSubframePDF);
    void setUseMicrophoneMuteStatusAPI(bool useMicrophoneMuteStatusAPI);
    void setUsePreHTML5ParserQuirks(bool usePreHTML5ParserQuirks);
    void setUseSystemAppearance(bool useSystemAppearance);
    void setUserActivationAPIEnabled(bool userActivationAPIEnabled);
    void setUserGesturePromisePropagationEnabled(bool userGesturePromisePropagationEnabled);
    void setUsesEncodingDetector(bool usesEncodingDetector);
    void setValidationMessageTimerMagnification(uint32_t validationMessageTimerMagnification);
    void setVerifyWindowOpenUserGestureFromUIProcess(bool verifyWindowOpenUserGestureFromUIProcess);
    void setVerticalFormControlsEnabled(bool verticalFormControlsEnabled);
    void setVideoFullsceenPrefersMostVisibleHeuristic(bool videoFullsceenPrefersMostVisibleHeuristic);
    void setVideoFullscreenRequiresElementFullscreen(bool videoFullscreenRequiresElementFullscreen);
    void setVideoPresentationManagerEnabled(bool videoPresentationManagerEnabled);
    void setVideoPresentationModeAPIEnabled(bool videoPresentationModeAPIEnabled);
    void setVideoQualityIncludesDisplayCompositingEnabled(bool videoQualityIncludesDisplayCompositingEnabled);
    void setVideoRendererProtectedFallbackDisabled(bool videoRendererProtectedFallbackDisabled);
    void setVideoRendererUseDecompressionSessionForProtected(bool videoRendererUseDecompressionSessionForProtected);
    void setViewTransitionClassesEnabled(bool viewTransitionClassesEnabled);
    void setViewTransitionTypesEnabled(bool viewTransitionTypesEnabled);
    void setViewTransitionsEnabled(bool viewTransitionsEnabled);
    void setVisibleDebugOverlayRegions(uint32_t visibleDebugOverlayRegions);
    void setVisualTranslationEnabled(bool visualTranslationEnabled);
    void setVisualViewportAPIEnabled(bool visualViewportAPIEnabled);
    void setVisualViewportEnabled(bool visualViewportEnabled);
    void setVisuallyContiguousBidiTextSelectionEnabled(bool visuallyContiguousBidiTextSelectionEnabled);
    void setVP9DecoderEnabled(bool vp9DecoderEnabled);
    void setWantsBalancedSetDefersLoadingBehavior(bool wantsBalancedSetDefersLoadingBehavior);
    void setWebAPIStatisticsEnabled(bool webAPIStatisticsEnabled);
    void setWebAPIsInShadowRealmEnabled(bool webAPIsInShadowRealmEnabled);
    void setWebAnimationsCustomEffectsEnabled(bool webAnimationsCustomEffectsEnabled);
    void setWebAnimationsCustomFrameRateEnabled(bool webAnimationsCustomFrameRateEnabled);
    void setWebAnimationsOverallProgressPropertyEnabled(bool webAnimationsOverallProgressPropertyEnabled);
    void setWebArchiveDebugModeEnabled(bool webArchiveDebugModeEnabled);
    void setWebArchiveTestingModeEnabled(bool webArchiveTestingModeEnabled);
    void setWebAssemblyESMIntegrationEnabled(bool webAssemblyESMIntegrationEnabled);
    void setWebAudioEnabled(bool webAudioEnabled);
    void setWebAuthenticationASEnabled(bool webAuthenticationASEnabled);
    void setWebAuthenticationEnabled(bool webAuthenticationEnabled);
    void setWebCodecsAV1Enabled(bool webCodecsAV1Enabled);
    void setWebCodecsAudioEnabled(bool webCodecsAudioEnabled);
    void setWebCodecsHEVCEnabled(bool webCodecsHEVCEnabled);
    void setWebCodecsVideoEnabled(bool webCodecsVideoEnabled);
    void setWebCryptoSafeCurvesEnabled(bool webCryptoSafeCurvesEnabled);
    void setWebCryptoX25519Enabled(bool webCryptoX25519Enabled);
    void setWebExtensionBookmarksEnabled(bool webExtensionBookmarksEnabled);
    void setWebExtensionSidebarEnabled(bool webExtensionSidebarEnabled);
    void setWebGLDraftExtensionsEnabled(bool webGLDraftExtensionsEnabled);
    void setWebGLEnabled(bool webGLEnabled);
    void setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled);
    void setWebGLTimerQueriesEnabled(bool webGLTimerQueriesEnabled);
    void setWebGPUEnabled(bool webGPUEnabled);
    void setWebGPUHDREnabled(bool webGPUHDREnabled);
    void setWebInspectorEngineeringSettingsAllowed(bool webInspectorEngineeringSettingsAllowed);
    void setWebLocksAPIEnabled(bool webLocksAPIEnabled);
    void setWebPageSpatialBackdropEnabled(bool webPageSpatialBackdropEnabled);
    void setWebRTCAV1CodecEnabled(bool webRTCAV1CodecEnabled);
    void setWebRTCDTMFEnabled(bool webRTCDTMFEnabled);
    void setWebRTCEncodedTransformEnabled(bool webRTCEncodedTransformEnabled);
    void setWebRTCEncryptionEnabled(bool webRTCEncryptionEnabled);
    void setWebRTCH265CodecEnabled(bool webRTCH265CodecEnabled);
    void setWebRTCInterfaceMonitoringViaNWEnabled(bool webRTCInterfaceMonitoringViaNWEnabled);
    void setWebRTCL4SEnabled(bool webRTCL4SEnabled);
    void setWebRTCMediaPipelineAdditionalLoggingEnabled(bool webRTCMediaPipelineAdditionalLoggingEnabled);
    void setWebRTCPlatformCodecsInGPUProcessEnabled(bool webRTCPlatformCodecsInGPUProcessEnabled);
    void setWebRTCRemoteVideoFrameEnabled(bool webRTCRemoteVideoFrameEnabled);
    void setWebRTCSFrameTransformEnabled(bool webRTCSFrameTransformEnabled);
    void setWebRTCSocketsProxyingEnabled(bool webRTCSocketsProxyingEnabled);
    void setWebRTCUDPPortRange(const String& webRTCUDPPortRange);
    void setWebRTCVP9Profile0CodecEnabled(bool webRTCVP9Profile0CodecEnabled);
    void setWebRTCVP9Profile2CodecEnabled(bool webRTCVP9Profile2CodecEnabled);
    void setWebSecurityEnabled(bool webSecurityEnabled);
    void setWebShareEnabled(bool webShareEnabled);
    void setWebShareFileAPIEnabled(bool webShareFileAPIEnabled);
    void setWebSocketEnabled(bool webSocketEnabled);
    void setWebTransportEnabled(bool webTransportEnabled);
    void setWebXRAugmentedRealityModuleEnabled(bool webXRAugmentedRealityModuleEnabled);
    void setWebXREnabled(bool webXREnabled);
    void setWebXRGamepadsModuleEnabled(bool webXRGamepadsModuleEnabled);
    void setWebXRHandInputModuleEnabled(bool webXRHandInputModuleEnabled);
    void setWebXRLayersAPIEnabled(bool webXRLayersAPIEnabled);
    void setWebXRWebGPUBindingsEnabled(bool webXRWebGPUBindingsEnabled);
    void setWebkitImageReadyEventEnabled(bool webkitImageReadyEventEnabled);
    void setWheelEventGesturesBecomeNonBlocking(bool wheelEventGesturesBecomeNonBlocking);
    void setWindowFocusRestricted(bool windowFocusRestricted);
    void setWirelessPlaybackTargetAPIEnabled(bool wirelessPlaybackTargetAPIEnabled);
    void setWorkerAsynchronousURLErrorHandlingEnabled(bool workerAsynchronousURLErrorHandlingEnabled);
    void setWriteRichTextDataWhenCopyingOrDragging(bool writeRichTextDataWhenCopyingOrDragging);
    void setWritingSuggestionsAttributeEnabled(bool writingSuggestionsAttributeEnabled);
    void setXsltEnabled(bool xsltEnabled);

private:
    WeakPtr<Page> m_page;

#if HAVE(AVKIT_CONTENT_SOURCE)
    bool m_aVKitContentSourceEnabled;
#endif
    bool m_acceleratedCompositingEnabled;
    bool m_acceleratedCompositingForFixedPositionEnabled;
    bool m_acceleratedDrawingEnabled;
#if USE(CORE_IMAGE)
    bool m_acceleratedFiltersEnabled;
#endif
    bool m_accentColorEnabled;
    bool m_accessHandleEnabled;
    bool m_aggressiveTileRetentionEnabled;
    bool m_allowAnimationControlsOverride;
    bool m_allowContentSecurityPolicySourceStarToMatchAnyProtocol;
    bool m_allowDisplayOfInsecureContent;
    bool m_allowFileAccessFromFileURLs;
    bool m_allowMediaContentTypesRequiringHardwareSupportAsFallback;
    bool m_allowMultiElementImplicitSubmission;
    bool m_allowPrivacySensitiveOperationsInNonPersistentDataStores;
    bool m_allowRunningOfInsecureContent;
    bool m_allowTopNavigationToDataURLs;
    bool m_allowUniversalAccessFromFileURLs;
#if PLATFORM(IOS_FAMILY)
    bool m_allowViewportShrinkToFitContent;
#endif
#if ENABLE(WEBGL)
    bool m_allowWebGLInWorkers;
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    bool m_allowsAirPlayForMediaPlayback;
#endif
    bool m_allowsInlineMediaPlayback;
    bool m_allowsInlineMediaPlaybackAfterFullscreen;
    bool m_allowsPictureInPictureMediaPlayback;
#if PLATFORM(IOS_FAMILY)
    bool m_alternateFullScreenControlDesignEnabled;
#endif
    bool m_altitudeAngleEnabled;
#if ENABLE(WEB_ARCHIVE)
    bool m_alwaysAllowLocalWebarchive;
#endif
    bool m_animatedImageAsyncDecodingEnabled;
    bool m_animatedImageDebugCanvasDrawingEnabled;
    bool m_appBadgeEnabled;
#if ENABLE(APP_HIGHLIGHTS)
    bool m_appHighlightsEnabled;
#endif
    bool m_appleMailPaginationQuirkEnabled;
#if ENABLE(APPLE_PAY)
    bool m_applePayCapabilityDisclosureAllowed;
#endif
#if ENABLE(APPLE_PAY)
    bool m_applePayEnabled;
#endif
    bool m_asyncClipboardAPIEnabled;
    bool m_asyncFrameScrollingEnabled;
    bool m_asyncOverflowScrollingEnabled;
    bool m_asynchronousSpellCheckingEnabled;
#if ENABLE(ATTACHMENT_ELEMENT)
    bool m_attachmentWideLayoutEnabled;
#endif
    bool m_audioControlsScaleWithPageZoom;
#if ENABLE(VIDEO)
    bool m_audioDescriptionsEnabled;
#endif
    bool m_authorAndUserStylesEnabled;
    bool m_automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth;
    bool m_autoscrollForDragAndDropEnabled;
    bool m_auxclickEventEnabled;
    bool m_azimuthAngleEnabled;
    bool m_backgroundFetchAPIEnabled;
    bool m_backgroundShouldExtendBeyondPage;
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
    bool m_backgroundWebContentRunningBoardThrottlingEnabled;
#endif
    bool m_backspaceKeyNavigationEnabled;
    bool m_beaconAPIEnabled;
    bool m_bidiContentAwarePasteEnabled;
    bool m_blobFileAccessEnforcementEnabled;
#if ENABLE(GPU_PROCESS)
    bool m_blockMediaLayerRehostingInWebContentProcess;
#endif
    bool m_broadcastChannelEnabled;
    bool m_cacheAPIEnabled;
    bool m_canvasColorSpaceEnabled;
    bool m_canvasFiltersEnabled;
    bool m_canvasFingerprintingQuirkEnabled;
    bool m_canvasLayersEnabled;
    bool m_canvasPixelFormatEnabled;
#if USE(CA) || USE(SKIA)
    bool m_canvasUsesAcceleratedDrawing;
#endif
    bool m_caretBrowsingEnabled;
    bool m_caretPositionFromPointEnabled;
    bool m_childProcessDebuggabilityEnabled;
    bool m_clearSiteDataExecutionContextsSupportEnabled;
    bool m_clearSiteDataHTTPHeaderEnabled;
    bool m_clientCoordinatesRelativeToLayoutViewport;
    bool m_closeWatcherEnabled;
    bool m_colorFilterEnabled;
    bool m_commandAttributesEnabled;
    bool m_compressionStreamEnabled;
    bool m_contactPickerAPIEnabled;
#if ENABLE(CONTENT_CHANGE_OBSERVER)
    bool m_contentChangeObserverEnabled;
#endif
    bool m_contentDispositionAttachmentSandboxEnabled;
    bool m_contentInsetBackgroundFillEnabled;
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
    bool m_contextMenuQRCodeDetectionEnabled;
#endif
    bool m_cookieConsentAPIEnabled;
    bool m_cookieEnabled;
    bool m_cookieStoreAPIEnabled;
    bool m_cookieStoreAPIExtendedAttributesEnabled;
    bool m_cookieStoreManagerEnabled;
    bool m_coreMathMLEnabled;
    bool m_crossDocumentViewTransitionsEnabled;
    bool m_crossOriginCheckInGetMatchedCSSRulesDisabled;
    bool m_crossOriginEmbedderPolicyEnabled;
    bool m_crossOriginOpenerPolicyEnabled;
    bool m_css3DTransformBackfaceVisibilityInteroperabilityEnabled;
    bool m_cssAnchorPositioningEnabled;
    bool m_cssAnchorPositioningPositionVisibilityEnabled;
    bool m_cssAppearanceBaseEnabled;
    bool m_cssAxisRelativePositionKeywordsEnabled;
    bool m_cssBackgroundClipBorderAreaEnabled;
    bool m_cssColorLayersEnabled;
    bool m_cssConstrainedDynamicRangeLimitEnabled;
    bool m_cssContrastColorEnabled;
    bool m_cssCornerShapeEnabled;
    bool m_cssCounterStyleAtRuleImageSymbolsEnabled;
    bool m_cssDPropertyEnabled;
    bool m_cssDynamicRangeLimitMixEnabled;
    bool m_cssFieldSizingEnabled;
    bool m_cssFontVariantEmojiEnabled;
    bool m_cssInputSecurityEnabled;
    bool m_cssLineClampEnabled;
    bool m_cssLineFitEdgeEnabled;
    bool m_cssPaintingAPIEnabled;
    bool m_cssProgressFunctionEnabled;
    bool m_cssRandomFunctionEnabled;
    bool m_cssRhythmicSizingEnabled;
    bool m_cssRubyAlignEnabled;
    bool m_cssRubyOverhangEnabled;
    bool m_cssScrollAnchoringEnabled;
    bool m_cssScrollbarColorEnabled;
    bool m_cssScrollbarGutterEnabled;
    bool m_cssScrollbarWidthEnabled;
    bool m_cssShapeFunctionEnabled;
    bool m_cssTextAutospaceEnabled;
    bool m_cssTextBoxTrimEnabled;
    bool m_cssTextGroupAlignEnabled;
    bool m_cssTextJustifyEnabled;
    bool m_cssTextSpacingTrimEnabled;
    bool m_cssTextUnderlinePositionLeftRightEnabled;
    bool m_cssTextWrapPrettyEnabled;
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
    bool m_cssTransformStyleSeparatedEnabled;
#endif
    bool m_cssTreeCountingFunctionsEnabled;
    bool m_cssTypedOMColorEnabled;
    bool m_cssURLIntegrityModifierEnabled;
    bool m_cssURLModifiersEnabled;
    bool m_cssUnprefixedBackdropFilterEnabled;
    bool m_cssWordBreakAutoPhraseEnabled;
    String m_cursiveFontFamily;
    bool m_dataListElementEnabled;
    bool m_dataTransferItemsEnabled;
    bool m_dateTimeInputsEditableComponentsEnabled;
#if ENABLE(DECLARATIVE_WEB_PUSH)
    bool m_declarativeWebPush;
#endif
    double m_defaultFixedFontSize;
    double m_defaultFontSize;
    String m_defaultTextEncodingName;
    String m_defaultVideoPosterURL;
    bool m_deprecationReportingEnabled;
#if ENABLE(MEDIA_SOURCE)
    bool m_detachableMediaSourceEnabled;
#endif
    bool m_detailsAutoExpandEnabled;
    bool m_developerExtrasEnabled;
    uint32_t m_deviceHeight;
#if ENABLE(DEVICE_ORIENTATION)
    bool m_deviceOrientationEventEnabled;
#endif
#if ENABLE(DEVICE_ORIENTATION)
    bool m_deviceOrientationPermissionAPIEnabled;
#endif
    uint32_t m_deviceWidth;
    bool m_devolvableWidgetsEnabled;
    bool m_diagnosticLoggingEnabled;
#if ENABLE(WEB_AUTHN)
    bool m_digitalCredentialsEnabled;
#endif
    bool m_directoryUploadEnabled;
    bool m_disabledAdaptationsMetaTagEnabled;
#if ENABLE(DOM_AUDIO_SESSION)
    bool m_domAudioSessionEnabled;
#endif
#if ENABLE(DOM_AUDIO_SESSION)
    bool m_domAudioSessionFullEnabled;
#endif
    bool m_domPasteAccessRequestsEnabled;
    bool m_domPasteAllowed;
    bool m_domTestingAPIsEnabled;
    bool m_domTimersThrottlingEnabled;
    bool m_downloadAttributeEnabled;
    bool m_dynamicSiteInterventionsEnabled;
    bool m_embedElementEnabled;
    bool m_enableElementCurrentCSSZoom;
    bool m_enableInheritURIQueryComponent;
#if ENABLE(ENCRYPTED_MEDIA)
    bool m_encryptedMediaAPIEnabled;
#endif
    bool m_enterKeyHintEnabled;
    bool m_eventHandlerDrivenSmoothKeyboardScrollingEnabled;
    bool m_eventTimingEnabled;
#if ENABLE(MEDIA_STREAM)
    bool m_exposeCaptureDevicesAfterCaptureEnabled;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_exposeDefaultSpeakerAsSpecificDeviceEnabled;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_exposeSpeakersEnabled;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_exposeSpeakersWithoutMicrophoneEnabled;
#endif
#if ENABLE(VIDEO)
    bool m_extendedAudioDescriptionsEnabled;
#endif
    String m_fantasyFontFamily;
    bool m_fileReaderAPIEnabled;
    bool m_fileSystemEnabled;
    bool m_fileSystemWritableStreamEnabled;
    bool m_filterLinkDecorationByDefaultEnabled;
    bool m_fixedBackgroundsPaintRelativeToDocument;
    bool m_fixedElementsLayoutRelativeToFrame;
    String m_fixedFontFamily;
    bool m_flexFormattingContextIntegrationEnabled;
    bool m_fontFallbackPrefersPictographs;
    bool m_forceCompositingMode;
    bool m_forceFTPDirectoryListings;
    bool m_forceLockdownFontParserEnabled;
    bool m_forceWebGLUsesLowPower;
#if ENABLE(FORM_CONTROL_REFRESH)
    bool m_formControlRefreshEnabled;
#endif
    String m_ftpDirectoryTemplatePath;
    bool m_ftpEnabled;
#if ENABLE(FULLSCREEN_API)
    bool m_fullScreenEnabled;
#endif
#if ENABLE(FULLSCREEN_API)
    bool m_fullScreenKeyboardLock;
#endif
    bool m_fullscreenRequirementForScreenOrientationLockingEnabled;
#if PLATFORM(VISION)
    bool m_fullscreenSceneAspectRatioLockingEnabled;
#endif
#if PLATFORM(VISION)
    bool m_fullscreenSceneDimmingEnabled;
#endif
#if ENABLE(GAMEPAD)
    bool m_gamepadTriggerRumbleEnabled;
#endif
#if ENABLE(GAMEPAD)
    bool m_gamepadVibrationActuatorEnabled;
#endif
#if ENABLE(GAMEPAD)
    bool m_gamepadsEnabled;
#endif
#if ENABLE(VIDEO)
    bool m_genericCueAPIEnabled;
#endif
    bool m_geolocationAPIEnabled;
    bool m_geolocationFloorLevelEnabled;
    bool m_getCoalescedEventsEnabled;
    bool m_getPredictedEventsEnabled;
#if ENABLE(MEDIA_STREAM)
    bool m_getUserMediaRequiresFocus;
#endif
    bool m_googleAntiFlickerOptimizationQuirkEnabled;
#if USE(GRAPHICS_CONTEXT_FILTERS)
    bool m_graphicsContextFiltersEnabled;
#endif
    bool m_hiddenPageCSSAnimationSuspensionEnabled;
    bool m_hiddenPageDOMTimerThrottlingAutoIncreases;
    bool m_hiddenPageDOMTimerThrottlingEnabled;
    bool m_hiddenUntilFoundEnabled;
#if HAVE(MATERIAL_HOSTING)
    bool m_hostedBlurMaterialInMediaControlsEnabled;
#endif
    bool m_htmlLegacyAttributeValueSerializationEnabled;
    bool m_httpEquivEnabled;
    bool m_httpsByDefault;
#if ENABLE(CONTENT_EXTENSIONS)
    bool m_iFrameResourceMonitoringEnabled;
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    bool m_iFrameResourceMonitoringTestingSettingsEnabled;
#endif
    bool m_iOSurfaceLosslessCompressionEnabled;
    bool m_iPAddressAndLocalhostMixedContentUpgradeTestingEnabled;
    bool m_iceCandidateFilteringEnabled;
#if ENABLE(TEXT_AUTOSIZING)
    bool m_idempotentModeAutosizingOnlyHonorsPercentages;
#endif
    bool m_ignoreIframeEmbeddingProtectionsEnabled;
#if ENABLE(IMAGE_ANALYSIS)
    bool m_imageAnalysisDuringFindInPageEnabled;
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    bool m_imageAnimationControlEnabled;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_imageCaptureEnabled;
#endif
#if ENABLE(SERVICE_CONTROLS)
    bool m_imageControlsEnabled;
#endif
    bool m_imageSubsamplingEnabled;
    bool m_imagesEnabled;
    bool m_inWindowFullscreenEnabled;
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
    bool m_includeIgnoredInCoreAXTree;
#endif
    bool m_incompleteImageBorderEnabled;
#if HAVE(INCREMENTAL_PDF_APIS)
    bool m_incrementalPDFLoadingEnabled;
#endif
    double m_incrementalRenderingSuppressionTimeoutInSeconds;
    bool m_indexedDBAPIEnabled;
    bool m_inlineMediaPlaybackRequiresPlaysInlineAttribute;
#if PLATFORM(MAC)
    bool m_inputMethodUsesCorrectKeyEventOrder;
#endif
    bool m_inputTypeColorEnabled;
    bool m_inputTypeColorEnhancementsEnabled;
    bool m_inputTypeDateEnabled;
    bool m_inputTypeDateTimeLocalEnabled;
    bool m_inputTypeMonthEnabled;
    bool m_inputTypeTimeEnabled;
    bool m_inputTypeWeekEnabled;
    uint32_t m_inspectorMaximumResourcesContentSize;
    bool m_inspectorSupportsShowingCertificate;
    double m_interactionRegionInlinePadding;
    double m_interactionRegionMinimumCornerRadius;
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    bool m_interactionRegionsEnabled;
#endif
    bool m_interactiveFormValidationEnabled;
#if ENABLE(MEDIA_STREAM)
    bool m_interruptAudioOnPageVisibilityChangeEnabled;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_interruptVideoOnPageVisibilityChangeEnabled;
#endif
    bool m_invisibleAutoplayNotPermitted;
    bool m_isFirstPartyWebsiteDataRemovalDisabled;
    bool m_isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled;
    bool m_isFirstPartyWebsiteDataRemovalReproTestingEnabled;
    bool m_isPerActivityStateCPUUsageMeasurementEnabled;
    bool m_isPostBackgroundingCPUUsageMeasurementEnabled;
    bool m_isPostBackgroundingMemoryUsageMeasurementEnabled;
    bool m_isPostLoadCPUUsageMeasurementEnabled;
    bool m_isPostLoadMemoryUsageMeasurementEnabled;
    bool m_isSameSiteStrictEnforcementEnabled;
    bool m_isThirdPartyCookieBlockingDisabled;
    bool m_itpDebugModeEnabled;
    bool m_javaScriptCanAccessClipboard;
    bool m_javaScriptCanOpenWindowsAutomatically;
    bool m_langAttributeAwareFormControlUIEnabled;
    bool m_largeImageAsyncDecodingEnabled;
    bool m_layerBasedSVGEngineEnabled;
    uint32_t m_layoutFallbackWidth;
    double m_layoutViewportHeightExpansionFactor;
    bool m_lazyIframeLoadingEnabled;
    bool m_lazyImageLoadingEnabled;
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    bool m_legacyEncryptedMediaAPIEnabled;
#endif
    bool m_legacyLineLayoutVisualCoverageEnabled;
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
    bool m_legacyOverflowScrollingTouchEnabled;
#endif
    bool m_legacyPluginQuirkForMailSignaturesEnabled;
#if ENABLE(WEB_RTC)
    bool m_legacyWebRTCOfferOptionsEnabled;
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    bool m_limitedMatroskaSupportEnabled;
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
    bool m_linearMediaPlayerEnabled;
#endif
    bool m_linkDNSPrefetchEnabled;
    bool m_linkPreconnectEarlyHintsEnabled;
    bool m_linkPreconnectEnabled;
    bool m_linkPrefetchEnabled;
    bool m_linkPreloadEnabled;
    bool m_linkSanitizerEnabled;
    bool m_loadDeferringEnabled;
#if ENABLE(WEB_ARCHIVE)
    bool m_loadWebArchiveWithEphemeralStorageEnabled;
#endif
    bool m_loadsImagesAutomatically;
    bool m_localFileContentSniffingEnabled;
    bool m_localNetworkAccessEnabled;
    String m_localStorageDatabasePath;
    bool m_localStorageEnabled;
    bool m_lockdownFontParserEnabled;
    bool m_loginStatusAPIEnabled;
    bool m_loginStatusAPIRequiresWebAuthnEnabled;
    bool m_logsPageMessagesToSystemConsoleEnabled;
    bool m_mainContentUserGestureOverrideEnabled;
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
    bool m_manageCaptureStatusBarInGPUProcessEnabled;
#endif
#if ENABLE(MEDIA_SOURCE)
    bool m_managedMediaSourceEnabled;
#endif
#if ENABLE(MEDIA_SOURCE)
    double m_managedMediaSourceHighThreshold;
#endif
#if ENABLE(MEDIA_SOURCE)
    double m_managedMediaSourceLowThreshold;
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
    bool m_managedMediaSourceNeedsAirPlay;
#endif
    bool m_masonryEnabled;
#if ENABLE(MATHML)
    bool m_mathMLEnabled;
#endif
    double m_maxParseDuration;
    uint32_t m_maximumHTMLParserDOMTreeDepth;
#if ENABLE(MEDIA_SOURCE)
    uint32_t m_maximumSourceBufferSize;
#endif
    bool m_mediaCapabilitiesEnabled;
    bool m_mediaCapabilitiesExtensionsEnabled;
#if ENABLE(EXTENSION_CAPABILITIES)
    bool m_mediaCapabilityGrantsEnabled;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_mediaCaptureRequiresSecureConnection;
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
    bool m_mediaControlsContextMenusEnabled;
#endif
    bool m_mediaControlsScaleWithPageZoom;
    bool m_mediaDataLoadsAutomatically;
#if ENABLE(MEDIA_STREAM)
    bool m_mediaDevicesEnabled;
#endif
#if ENABLE(VIDEO)
    bool m_mediaEnabled;
#endif
    String m_mediaKeysStorageDirectory;
    bool m_mediaPlaybackEnabled;
    double m_mediaPreferredFullscreenWidth;
    bool m_mediaPreloadingEnabled;
#if ENABLE(MEDIA_RECORDER)
    bool m_mediaRecorderEnabled;
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
    bool m_mediaRecorderEnabledWebM;
#endif
    bool m_mediaSessionCaptureToggleAPIEnabled;
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    bool m_mediaSessionCoordinatorEnabled;
#endif
#if ENABLE(MEDIA_SESSION)
    bool m_mediaSessionEnabled;
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
    bool m_mediaSessionPlaylistEnabled;
#endif
    bool m_mediaSourceEnabled;
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
    bool m_mediaSourceInWorkerEnabled;
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
    bool m_mediaSourcePrefersDecompressionSession;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_mediaStreamTrackProcessingEnabled;
#endif
    String m_mediaTypeOverride;
    bool m_mediaUserGestureInheritsFromDocument;
    bool m_metaViewportInteractiveWidgetEnabled;
    double m_minimumFontSize;
    double m_minimumLogicalFontSize;
#if ENABLE(TEXT_AUTOSIZING)
    double m_minimumZoomFontSize;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_mockCaptureDevicesEnabled;
#endif
    bool m_mockScrollbarsControllerEnabled;
#if ENABLE(MODEL_ELEMENT)
    bool m_modelElementEnabled;
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    bool m_modelNoPortalAttributeEnabled;
#endif
#if ENABLE(MODEL_PROCESS)
    bool m_modelProcessEnabled;
#endif
    bool m_momentumScrollingAnimatorEnabled;
#if ENABLE(TOUCH_EVENTS)
    bool m_mouseEventsSimulationEnabled;
#endif
    bool m_mutationEventsEnabled;
#if ENABLE(MEDIA_STREAM)
    bool m_muteCameraOnMicrophoneInterruptionEnabled;
#endif
    bool m_navigationAPIEnabled;
    bool m_navigatorUserAgentDataJavaScriptAPIEnabled;
    bool m_needsAdobeFrameReloadingQuirk;
    bool m_needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk;
    bool m_needsFrameNameFallbackToIdQuirk;
    bool m_needsKeyboardEventDisambiguationQuirks;
    bool m_needsSiteSpecificQuirks;
    bool m_needsStorageAccessFromFileURLsQuirk;
#if ENABLE(NOTIFICATION_EVENT)
    bool m_notificationEventEnabled;
#endif
#if ENABLE(NOTIFICATIONS)
    bool m_notificationsEnabled;
#endif
    bool m_observableEnabled;
#if ENABLE(OFFSCREEN_CANVAS)
    bool m_offscreenCanvasEnabled;
#endif
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
    bool m_offscreenCanvasInWorkersEnabled;
#endif
    bool m_opportunisticSweepingAndGarbageCollectionEnabled;
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
    bool m_optInPartitionedCookiesEnabled;
#endif
    bool m_overlappingBackingStoreProvidersEnabled;
    bool m_overscrollBehaviorEnabled;
    bool m_pageAtRuleMarginDescriptorsEnabled;
    bool m_passiveTouchListenersAsDefaultOnDocument;
    bool m_passiveWheelListenersAsDefaultOnDocument;
    double m_passwordEchoDurationInSeconds;
    bool m_passwordEchoEnabled;
#if ENABLE(PAYMENT_REQUEST)
    bool m_paymentRequestEnabled;
#endif
#if ENABLE(PDFJS)
    bool m_pdfJSViewerEnabled;
#endif
#if PLATFORM(COCOA)
    bool m_pdfPluginEnabled;
#endif
#if PLATFORM(COCOA)
    bool m_pdfPluginHUDEnabled;
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    bool m_pdfPluginPageNumberIndicatorEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_peerConnectionEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_peerConnectionVideoScalingAdaptationDisabled;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_perElementSpeakerSelectionEnabled;
#endif
    bool m_permissionsAPIEnabled;
    String m_pictographFontFamily;
#if ENABLE(PICTURE_IN_PICTURE_API)
    bool m_pictureInPictureAPIEnabled;
#endif
#if HAVE(PIP_SKIP_PREROLL)
    bool m_pictureInPicturePlaybackStateEnabled;
#endif
#if ENABLE(POINTER_LOCK)
    bool m_pointerLockEnabled;
#endif
#if ENABLE(POINTER_LOCK)
    bool m_pointerLockOptionsEnabled;
#endif
    bool m_popoverAttributeEnabled;
    bool m_preferMIMETypeForImages;
    bool m_preferPageRenderingUpdatesNear60FPSEnabled;
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    bool m_preferSpatialAudioExperience;
#endif
    bool m_preventKeyboardDOMEventDispatch;
    bool m_privateClickMeasurementDebugModeEnabled;
    bool m_privateClickMeasurementEnabled;
    bool m_privateClickMeasurementFraudPreventionEnabled;
    bool m_privateTokenUsageByThirdPartyEnabled;
#if ENABLE(DAMAGE_TRACKING)
    bool m_propagateDamagingInformation;
#endif
    bool m_punchOutWhiteBackgroundsInDarkMode;
    bool m_pushAPIEnabled;
    bool m_remoteMediaSessionManagerEnabled;
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    bool m_remotePlaybackEnabled;
#endif
    bool m_remoteSnapshottingEnabled;
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    bool m_removeBackgroundEnabled;
#endif
    bool m_requestIdleCallbackEnabled;
    bool m_requestStorageAccessThrowsExceptionUntilReload;
    bool m_requestVideoFrameCallbackEnabled;
#if HAVE(SC_CONTENT_SHARING_PICKER)
    bool m_requireUAGetDisplayMediaPrompt;
#endif
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
    bool m_requiresPageVisibilityForVideoToBeNowPlaying;
#endif
    bool m_requiresPageVisibilityToPlayAudio;
    bool m_requiresUserGestureForAudioPlayback;
    bool m_requiresUserGestureForVideoPlayback;
    bool m_requiresUserGestureToLoadVideo;
    bool m_resourceLoadSchedulingEnabled;
#if ENABLE(RESOURCE_USAGE)
    bool m_resourceUsageOverlayVisible;
#endif
    bool m_respondToThermalPressureAggressively;
#if HAVE(RUBBER_BANDING)
    bool m_rubberBandingForSubScrollableRegionsEnabled;
#endif
    bool m_sKAttributionEnabled;
    double m_sampledPageTopColorMaxDifference;
    double m_sampledPageTopColorMinHeight;
    String m_sansSerifFontFamily;
    bool m_scopedCustomElementRegistryEnabled;
#if ENABLE(MEDIA_STREAM)
    bool m_screenCaptureEnabled;
#endif
    bool m_screenOrientationAPIEnabled;
    bool m_screenOrientationLockingAPIEnabled;
#if ENABLE(SCREEN_TIME)
    bool m_screenTimeEnabled;
#endif
    bool m_screenWakeLockAPIEnabled;
    bool m_scriptEnabled;
    bool m_scriptMarkupEnabled;
    bool m_scriptTrackingPrivacyLoggingEnabled;
    bool m_scrollAnimatorEnabled;
    bool m_scrollDrivenAnimationsEnabled;
    bool m_scrollToTextFragmentEnabled;
    bool m_scrollToTextFragmentFeatureDetectionEnabled;
    bool m_scrollToTextFragmentGenerationEnabled;
    bool m_scrollToTextFragmentIndicatorEnabled;
    bool m_scrollToTextFragmentMarkingEnabled;
    bool m_scrollendEventEnabled;
    bool m_scrollingCoordinatorEnabled;
    bool m_scrollingPerformanceTestingEnabled;
    bool m_scrollingTreeIncludesFrames;
    bool m_secureContextChecksEnabled;
    bool m_selectShowPickerEnabled;
    bool m_selectTrailingWhitespaceEnabled;
#if PLATFORM(IOS_FAMILY)
    bool m_selectionHonorsOverflowScrolling;
#endif
    String m_serifFontFamily;
#if ENABLE(SERVICE_CONTROLS)
    bool m_serviceControlsEnabled;
#endif
    bool m_serviceWorkerInstallEventEnabled;
    bool m_serviceWorkerNavigationPreloadEnabled;
    bool m_serviceWorkersEnabled;
    bool m_serviceWorkersUserGestureEnabled;
    uint32_t m_sessionStorageQuota;
    bool m_shadowRootReferenceTargetEnabled;
    bool m_shadowRootReferenceTargetEnabledForAriaOwns;
    bool m_shapeDetection;
    bool m_sharedWorkerEnabled;
    bool m_shouldAllowUserInstalledFonts;
    bool m_shouldConvertInvalidURLsToBlank;
    bool m_shouldConvertPositionStyleOnCopy;
    bool m_shouldDecidePolicyBeforeLoadingQuickLookPreview;
    bool m_shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint;
    bool m_shouldDispatchSyntheticMouseEventsWhenModifyingSelection;
    bool m_shouldDispatchSyntheticMouseOutAfterSyntheticClick;
#if ENABLE(VIDEO)
    bool m_shouldDisplayCaptions;
#endif
#if ENABLE(VIDEO)
    bool m_shouldDisplaySubtitles;
#endif
#if ENABLE(VIDEO)
    bool m_shouldDisplayTextDescriptions;
#endif
    bool m_shouldDropNearSuspendedAssertionAfterDelay;
#if ENABLE(TEXT_AUTOSIZING)
    bool m_shouldEnableTextAutosizingBoost;
#endif
    bool m_shouldIgnoreFontLoadCompletions;
    bool m_shouldIgnoreMetaViewport;
    bool m_shouldInjectUserScriptsInInitialEmptyDocument;
    bool m_shouldPrintBackgrounds;
    bool m_shouldRespectImageOrientation;
    bool m_shouldRestrictBaseURLSchemes;
    bool m_shouldSuppressTextInputFromEditingDuringProvisionalNavigation;
    bool m_shouldTakeNearSuspendedAssertions;
#if USE(MODERN_AVCONTENTKEYSESSION)
    bool m_shouldUseModernAVContentKeySession;
#endif
    bool m_shouldUseServiceWorkerShortTimeout;
    bool m_showDebugBorders;
    bool m_showFrameProcessBorders;
    bool m_showMediaStatsContextMenuItemEnabled;
    bool m_showModalDialogEnabled;
    bool m_showRepaintCounter;
    bool m_showTiledScrollingIndicator;
    bool m_showsToolTipOverTruncatedText;
    bool m_showsURLsInToolTips;
    bool m_shrinksStandaloneImagesToFit;
    bool m_sidewaysWritingModesEnabled;
    bool m_siteIsolationEnabled;
    bool m_siteIsolationSharedProcessEnabled;
    bool m_smartInsertDeleteEnabled;
#if ENABLE(MEDIA_SOURCE)
    bool m_sourceBufferChangeTypeEnabled;
#endif
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
    bool m_spatialImageControlsEnabled;
#endif
    bool m_spatialNavigationEnabled;
#if ENABLE(MEDIA_STREAM)
    bool m_speakerSelectionRequiresUserGesture;
#endif
    bool m_speechRecognitionEnabled;
    bool m_speechSynthesisAPIEnabled;
    bool m_springTimingFunctionEnabled;
    bool m_standalone;
    String m_standardFontFamily;
    bool m_storageAPIEnabled;
    bool m_storageAPIEstimateEnabled;
    bool m_storageAccessAPIPerPageScopeEnabled;
    bool m_supportHDRCompositorTonemappingEnabled;
    bool m_supportHDRDisplayEnabled;
    bool m_suppressHDRShouldBeAllowedInFullscreenVideo;
    bool m_suppressesIncrementalRendering;
    bool m_switchControlEnabled;
#if USE(SYSTEM_PREVIEW)
    bool m_systemPreviewEnabled;
#endif
    bool m_targetTextPseudoElementEnabled;
    bool m_telephoneNumberParsingEnabled;
    bool m_temporaryTileCohortRetentionEnabled;
#if ENABLE(WRITING_TOOLS)
    bool m_textAnimationsEnabled;
#endif
    bool m_textAreasAreResizable;
#if ENABLE(TEXT_AUTOSIZING)
    bool m_textAutosizingEnabled;
#endif
#if ENABLE(TEXT_AUTOSIZING)
    bool m_textAutosizingEnabledAtLargeInitialScale;
#endif
#if ENABLE(TEXT_AUTOSIZING)
    bool m_textAutosizingUsesIdempotentMode;
#endif
#if ENABLE(TEXT_AUTOSIZING)
    uint32_t m_textAutosizingWindowSizeOverrideHeight;
#endif
#if ENABLE(TEXT_AUTOSIZING)
    uint32_t m_textAutosizingWindowSizeOverrideWidth;
#endif
    bool m_textInteractionEnabled;
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    bool m_textRecognitionInVideosEnabled;
#endif
#if ENABLE(MEDIA_SOURCE)
    bool m_textTracksInMSEEnabled;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
    bool m_threadedAnimationResolutionEnabled;
#endif
    bool m_thumbAndTrackPseudoElementsEnabled;
    bool m_topContentInsetBackgroundCanChangeAfterScrolling;
#if ENABLE(TOUCH_EVENTS)
    bool m_touchEventDOMAttributesEnabled;
#endif
#if ENABLE(TOUCH_EVENTS)
    bool m_touchEventEmulationEnabled;
#endif
#if ENABLE(WEBXR)
    bool m_touchInputCompatibilityEnabled;
#endif
    bool m_trackConfigurationEnabled;
    bool m_treatIPAddressAsDomain;
    bool m_treatsAnyTextCSSLinkAsStylesheet;
    bool m_trustedTypesEnabled;
    bool m_uAVisualTransitionDetectionEnabled;
    bool m_undoManagerAPIEnabled;
    bool m_unhandledPromiseRejectionToConsoleEnabled;
#if ENABLE(UNIFIED_PDF)
    bool m_unifiedPDFEnabled;
#endif
    bool m_unifiedTextCheckerEnabled;
#if ENABLE(DAMAGE_TRACKING)
    bool m_unifyDamagedRegions;
#endif
    bool m_upgradeMixedContentEnabled;
    bool m_urlPatternAPIEnabled;
    bool m_useAnonymousModeWhenFetchingMaskImages;
#if PLATFORM(IOS_FAMILY)
    bool m_useAsyncUIKitInteractions;
#endif
#if ENABLE(DAMAGE_TRACKING)
    bool m_useDamagingInformationForCompositing;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
    bool m_useGPUProcessForWebGLEnabled;
#endif
    bool m_useGiantTiles;
    bool m_useIFCForSVGText;
    bool m_useImageDocumentForSubframePDF;
#if ENABLE(MEDIA_STREAM)
    bool m_useMicrophoneMuteStatusAPI;
#endif
    bool m_usePreHTML5ParserQuirks;
    bool m_useSystemAppearance;
    bool m_userActivationAPIEnabled;
    bool m_userGesturePromisePropagationEnabled;
    bool m_usesEncodingDetector;
    uint32_t m_validationMessageTimerMagnification;
    bool m_verifyWindowOpenUserGestureFromUIProcess;
    bool m_verticalFormControlsEnabled;
#if ENABLE(FULLSCREEN_API)
    bool m_videoFullsceenPrefersMostVisibleHeuristic;
#endif
#if ENABLE(FULLSCREEN_API)
    bool m_videoFullscreenRequiresElementFullscreen;
#endif
    bool m_videoPresentationManagerEnabled;
    bool m_videoPresentationModeAPIEnabled;
#if ENABLE(VIDEO)
    bool m_videoQualityIncludesDisplayCompositingEnabled;
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    bool m_videoRendererProtectedFallbackDisabled;
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    bool m_videoRendererUseDecompressionSessionForProtected;
#endif
    bool m_viewTransitionClassesEnabled;
    bool m_viewTransitionTypesEnabled;
    bool m_viewTransitionsEnabled;
    uint32_t m_visibleDebugOverlayRegions;
#if ENABLE(IMAGE_ANALYSIS)
    bool m_visualTranslationEnabled;
#endif
    bool m_visualViewportAPIEnabled;
    bool m_visualViewportEnabled;
#if PLATFORM(IOS_FAMILY)
    bool m_visuallyContiguousBidiTextSelectionEnabled;
#endif
#if ENABLE(VP9)
    bool m_vp9DecoderEnabled;
#endif
    bool m_wantsBalancedSetDefersLoadingBehavior;
    bool m_webAPIStatisticsEnabled;
    bool m_webAPIsInShadowRealmEnabled;
    bool m_webAnimationsCustomEffectsEnabled;
    bool m_webAnimationsCustomFrameRateEnabled;
    bool m_webAnimationsOverallProgressPropertyEnabled;
#if ENABLE(WEB_ARCHIVE)
    bool m_webArchiveDebugModeEnabled;
#endif
#if ENABLE(WEB_ARCHIVE)
    bool m_webArchiveTestingModeEnabled;
#endif
#if ENABLE(WEBASSEMBLY)
    bool m_webAssemblyESMIntegrationEnabled;
#endif
#if ENABLE(WEB_AUDIO)
    bool m_webAudioEnabled;
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
    bool m_webAuthenticationASEnabled;
#endif
#if ENABLE(WEB_AUTHN)
    bool m_webAuthenticationEnabled;
#endif
#if ENABLE(WEB_CODECS)
    bool m_webCodecsAV1Enabled;
#endif
#if ENABLE(WEB_CODECS)
    bool m_webCodecsAudioEnabled;
#endif
#if ENABLE(WEB_CODECS)
    bool m_webCodecsHEVCEnabled;
#endif
#if ENABLE(WEB_CODECS)
    bool m_webCodecsVideoEnabled;
#endif
    bool m_webCryptoSafeCurvesEnabled;
    bool m_webCryptoX25519Enabled;
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    bool m_webExtensionBookmarksEnabled;
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    bool m_webExtensionSidebarEnabled;
#endif
    bool m_webGLDraftExtensionsEnabled;
    bool m_webGLEnabled;
    bool m_webGLErrorsToConsoleEnabled;
    bool m_webGLTimerQueriesEnabled;
    bool m_webGPUEnabled;
    bool m_webGPUHDREnabled;
    bool m_webInspectorEngineeringSettingsAllowed;
    bool m_webLocksAPIEnabled;
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    bool m_webPageSpatialBackdropEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCAV1CodecEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCDTMFEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCEncodedTransformEnabled;
#endif
    bool m_webRTCEncryptionEnabled;
#if ENABLE(WEB_RTC)
    bool m_webRTCH265CodecEnabled;
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
    bool m_webRTCInterfaceMonitoringViaNWEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCL4SEnabled;
#endif
    bool m_webRTCMediaPipelineAdditionalLoggingEnabled;
#if ENABLE(WEB_RTC)
    bool m_webRTCPlatformCodecsInGPUProcessEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCRemoteVideoFrameEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCSFrameTransformEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCSocketsProxyingEnabled;
#endif
#if ENABLE(WEB_RTC)
    String m_webRTCUDPPortRange;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCVP9Profile0CodecEnabled;
#endif
#if ENABLE(WEB_RTC)
    bool m_webRTCVP9Profile2CodecEnabled;
#endif
    bool m_webSecurityEnabled;
    bool m_webShareEnabled;
    bool m_webShareFileAPIEnabled;
    bool m_webSocketEnabled;
    bool m_webTransportEnabled;
#if ENABLE(WEBXR)
    bool m_webXRAugmentedRealityModuleEnabled;
#endif
#if ENABLE(WEBXR)
    bool m_webXREnabled;
#endif
#if ENABLE(WEBXR)
    bool m_webXRGamepadsModuleEnabled;
#endif
#if ENABLE(WEBXR_HANDS)
    bool m_webXRHandInputModuleEnabled;
#endif
#if ENABLE(WEBXR_LAYERS)
    bool m_webXRLayersAPIEnabled;
#endif
    bool m_webXRWebGPUBindingsEnabled;
    bool m_webkitImageReadyEventEnabled;
    bool m_wheelEventGesturesBecomeNonBlocking;
    bool m_windowFocusRestricted;
    bool m_wirelessPlaybackTargetAPIEnabled;
    bool m_workerAsynchronousURLErrorHandlingEnabled;
#if PLATFORM(COCOA)
    bool m_writeRichTextDataWhenCopyingOrDragging;
#endif
#if ENABLE(WRITING_SUGGESTIONS)
    bool m_writingSuggestionsAttributeEnabled;
#endif
#if ENABLE(XSLT)
    bool m_xsltEnabled;
#endif
};

} // namespace WebCore
