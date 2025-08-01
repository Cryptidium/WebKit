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

#pragma once

#include "WebPreferencesDefaultValues.h"

#define DEFAULT_VALUE_FOR_DatabasesEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_LoadDeferringEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_AcceleratedCompositingEnabled std::true_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_AcceleratedCompositingForFixedPositionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AcceleratedCompositingForFixedPositionEnabled std::false_type{}
#endif
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_WirelessPlaybackTargetAPIEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_WirelessPlaybackTargetAPIEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_LoadsImagesAutomatically std::true_type{}
#if ENABLE(SERVER_PRECONNECT)
#define DEFAULT_VALUE_FOR_LinkPreconnect std::true_type{}
#else
#define DEFAULT_VALUE_FOR_LinkPreconnect std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_LongRunningMediaCaptureStreamRepromptIntervalInHours 24
#define DEFAULT_VALUE_FOR_WindowFocusRestricted std::true_type{}
#define DEFAULT_VALUE_FOR_AggressiveTileRetentionEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_AllowContentSecurityPolicySourceStarToMatchAnyProtocol std::false_type{}
#define DEFAULT_VALUE_FOR_AllowDisplayOfInsecureContent std::false_type{}
#define DEFAULT_VALUE_FOR_AllowFileAccessFromFileURLs std::false_type{}
#define DEFAULT_VALUE_FOR_LowPowerVideoAudioBufferSizeEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_AllowMultiElementImplicitSubmission std::false_type{}
#if ENABLE(MEDIA_SOURCE)
#define DEFAULT_VALUE_FOR_ManagedMediaSourceHighThreshold 30
#endif
#define DEFAULT_VALUE_FOR_AllowRunningOfInsecureContent std::false_type{}
#define DEFAULT_VALUE_FOR_AllowTestOnlyIPC std::false_type{}
#if ENABLE(MEDIA_SOURCE)
#define DEFAULT_VALUE_FOR_ManagedMediaSourceLowThreshold 10
#endif
#if ENABLE(MATHML)
#define DEFAULT_VALUE_FOR_MathMLEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_MaxParseDuration -1
#define DEFAULT_VALUE_FOR_MediaAudioCodecIDsAllowedInLockdownMode "aac ,zaac,qaac,caac,.mp3,mp4a"_str
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
#define DEFAULT_VALUE_FOR_AllowsAirPlayForMediaPlayback std::true_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_AllowsInlineMediaPlayback std::false_type{}
#else
#define DEFAULT_VALUE_FOR_AllowsInlineMediaPlayback std::true_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_AllowsInlineMediaPlaybackAfterFullscreen std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AllowsInlineMediaPlaybackAfterFullscreen std::false_type{}
#endif
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_AllowsPictureInPictureMediaPlayback std::false_type{}
#elif PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_AllowsPictureInPictureMediaPlayback std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AllowsPictureInPictureMediaPlayback std::false_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_AlternateFullScreenControlDesignEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AlternateFullScreenControlDesignEnabled std::false_type{}
#endif
#endif
#if PLATFORM(WATCHOS)
#define DEFAULT_VALUE_FOR_WebSocketEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_WebSocketEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_MediaCapabilitiesEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_WebSecurityEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_AnimatedImageAsyncDecodingEnabled std::true_type{}
#if PLATFORM(WATCHOS) || ENABLE(FLEXIBLE_VIEW_SCALE_FACTOR)
#define DEFAULT_VALUE_FOR_LayoutViewportHeightExpansionFactor 1
#else
#define DEFAULT_VALUE_FOR_LayoutViewportHeightExpansionFactor 0
#endif
#define DEFAULT_VALUE_FOR_LayoutFallbackWidth 980
#if PLATFORM(MAC)
#define DEFAULT_VALUE_FOR_AppleMailPaginationQuirkEnabled WebKit::defaultAppleMailPaginationQuirkEnabled()
#else
#define DEFAULT_VALUE_FOR_AppleMailPaginationQuirkEnabled std::false_type{}
#endif
#if ENABLE(APPLE_PAY)
#define DEFAULT_VALUE_FOR_ApplePayCapabilityDisclosureAllowed std::true_type{}
#endif
#if ENABLE(APPLE_PAY)
#if ENABLE(APPLE_PAY_REMOTE_UI)
#define DEFAULT_VALUE_FOR_ApplePayEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ApplePayEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_LargeImageAsyncDecodingEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_MediaCaptionFormatTypesAllowedInLockdownMode "c608,wvtt"_str
#define DEFAULT_VALUE_FOR_JavaScriptRuntimeFlags 0
#define DEFAULT_VALUE_FOR_AsynchronousSpellCheckingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_JavaScriptMarkupEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_MediaCodecTypesAllowedInLockdownMode "mp4a.40,avc1"_str
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_AudioControlsScaleWithPageZoom std::true_type{}
#elif PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_AudioControlsScaleWithPageZoom std::false_type{}
#else
#define DEFAULT_VALUE_FOR_AudioControlsScaleWithPageZoom std::true_type{}
#endif
#if PLATFORM(IOS_FAMILY) || PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_JavaScriptCanOpenWindowsAutomatically std::false_type{}
#else
#define DEFAULT_VALUE_FOR_JavaScriptCanOpenWindowsAutomatically std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_AuthorAndUserStylesEnabled std::true_type{}
#if ENABLE(WEB_AUDIO)
#define DEFAULT_VALUE_FOR_WebAudioEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_JavaScriptCanAccessClipboard std::false_type{}
#define DEFAULT_VALUE_FOR_WantsBalancedSetDefersLoadingBehavior std::false_type{}
#define DEFAULT_VALUE_FOR_VisualViewportEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_VisibleDebugOverlayRegions 0
#if ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_VideoQualityIncludesDisplayCompositingEnabled std::false_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_BackspaceKeyNavigationEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_BackspaceKeyNavigationEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_MediaContainerTypesAllowedInLockdownMode "video/mp4,audio/mp4,video/x-m4v,audio/x-m4a,audio/mp3,application/x-mpegURL,application/vnd.apple.mpegURL,video/mp2t,video/iso.segment,audio/aac,audio/mpeg,audio/ac3,audio/eac3,video/mpeg2,text/vtt"_str
#define DEFAULT_VALUE_FOR_MediaContentTypesRequiringHardwareSupport ""_str
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_VideoPresentationModeAPIEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_VideoPresentationModeAPIEnabled std::true_type{}
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
#define DEFAULT_VALUE_FOR_MediaControlsContextMenusEnabled std::true_type{}
#endif
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_VideoPresentationManagerEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_VideoPresentationManagerEnabled std::false_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_MediaControlsScaleWithPageZoom std::false_type{}
#else
#define DEFAULT_VALUE_FOR_MediaControlsScaleWithPageZoom std::true_type{}
#endif
#if ENABLE(FULLSCREEN_API)
#define DEFAULT_VALUE_FOR_VideoFullscreenRequiresElementFullscreen defaultVideoFullscreenRequiresElementFullscreen()
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_MediaDataLoadsAutomatically std::false_type{}
#else
#define DEFAULT_VALUE_FOR_MediaDataLoadsAutomatically std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_MediaPreferredFullscreenWidth 960
#define DEFAULT_VALUE_FOR_MediaPreloadingEnabled std::false_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_InvisibleAutoplayNotPermitted std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InvisibleAutoplayNotPermitted std::false_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_InterruptVideoOnPageVisibilityChangeEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InterruptVideoOnPageVisibilityChangeEnabled std::false_type{}
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_InterruptAudioOnPageVisibilityChangeEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InterruptAudioOnPageVisibilityChangeEnabled std::false_type{}
#endif
#endif
#if ENABLE(VP9)
#define DEFAULT_VALUE_FOR_VP9DecoderEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_MediaUserGestureInheritsFromDocument std::false_type{}
#define DEFAULT_VALUE_FOR_MediaVideoCodecIDsAllowedInLockdownMode "avc1,zavc,qavc,cavc"_str
#define DEFAULT_VALUE_FOR_InteractionRegionMinimumCornerRadius 8
#define DEFAULT_VALUE_FOR_InteractionRegionInlinePadding 4
#define DEFAULT_VALUE_FOR_InspectorWindowFrame ""_str
#if PLATFORM(COCOA) || PLATFORM(WIN)
#define DEFAULT_VALUE_FOR_InspectorSupportsShowingCertificate std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InspectorSupportsShowingCertificate std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_InspectorStartsAttached std::true_type{}
#if PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_InspectorMaximumResourcesContentSize 50
#else
#define DEFAULT_VALUE_FOR_InspectorMaximumResourcesContentSize 200
#endif
#define DEFAULT_VALUE_FOR_InspectorAttachmentSide 0
#define DEFAULT_VALUE_FOR_InspectorAttachedWidth 750
#define DEFAULT_VALUE_FOR_InspectorAttachedHeight 500
#define DEFAULT_VALUE_FOR_MinimumFontSize 0
#define DEFAULT_VALUE_FOR_MinimumLogicalFontSize 9
#if ENABLE(TEXT_AUTOSIZING)
#if PLATFORM(WATCHOS)
#define DEFAULT_VALUE_FOR_MinimumZoomFontSize 30
#else
#define DEFAULT_VALUE_FOR_MinimumZoomFontSize 15
#endif
#endif
#define DEFAULT_VALUE_FOR_MockCaptureDevicesPromptEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_MockScrollbarsControllerEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_MockScrollbarsEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_InlineMediaPlaybackRequiresPlaysInlineAttribute std::false_type{}
#define DEFAULT_VALUE_FOR_IncrementalRenderingSuppressionTimeout 5
#if HAVE(INCREMENTAL_PDF_APIS)
#if PLATFORM(MAC)
#define DEFAULT_VALUE_FOR_IncrementalPDFLoadingEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_IncrementalPDFLoadingEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_IncompleteImageBorderEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_NeedsAdobeFrameReloadingQuirk std::false_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_InactiveMediaCaptureStreamRepromptIntervalInMinutes 1
#else
#define DEFAULT_VALUE_FOR_InactiveMediaCaptureStreamRepromptIntervalInMinutes 10
#endif
#define DEFAULT_VALUE_FOR_NeedsFrameNameFallbackToIdQuirk std::false_type{}
#define DEFAULT_VALUE_FOR_NeedsKeyboardEventDisambiguationQuirks std::false_type{}
#if PLATFORM(COCOA)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_PDFPluginEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_PDFPluginEnabled std::true_type{}
#endif
#endif
#if PLATFORM(COCOA)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_PDFPluginHUDEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_PDFPluginHUDEnabled std::true_type{}
#endif
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
#define DEFAULT_VALUE_FOR_PDFPluginPageNumberIndicatorEnabled std::true_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_PassiveTouchListenersAsDefaultOnDocument WebKit::defaultPassiveTouchListenersAsDefaultOnDocument()
#else
#define DEFAULT_VALUE_FOR_PassiveTouchListenersAsDefaultOnDocument std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_PasswordEchoDuration 2
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
#define DEFAULT_VALUE_FOR_PasswordEchoEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_PasswordEchoEnabled std::false_type{}
#endif
#if PLATFORM(COCOA) && PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_PictographFontFamily "AppleColorEmoji"_str
#elif PLATFORM(COCOA) && !PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_PictographFontFamily "Apple Color Emoji"_str
#else
#define DEFAULT_VALUE_FOR_PictographFontFamily "Times"_str
#endif
#if ENABLE(PICTURE_IN_PICTURE_API)
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_PictureInPictureAPIEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_PictureInPictureAPIEnabled std::true_type{}
#endif
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_PitchCorrectionAlgorithm static_cast<uint32_t>(WebCore::MediaPlayerEnums::PitchCorrectionAlgorithm::BestForSpeech)
#else
#define DEFAULT_VALUE_FOR_PitchCorrectionAlgorithm static_cast<uint32_t>(WebCore::MediaPlayerEnums::PitchCorrectionAlgorithm::BestAllAround)
#endif
#define DEFAULT_VALUE_FOR_PunchOutWhiteBackgroundsInDarkMode std::false_type{}
#if ENABLE(REQUIRES_PAGE_VISIBILITY_FOR_NOW_PLAYING)
#define DEFAULT_VALUE_FOR_RequiresPageVisibilityForVideoToBeNowPlaying defaultRequiresPageVisibilityForVideoToBeNowPlaying()
#endif
#define DEFAULT_VALUE_FOR_RequiresPageVisibilityToPlayAudio std::false_type{}
#if PLATFORM(COCOA) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_HiddenPageCSSAnimationSuspensionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_HiddenPageCSSAnimationSuspensionEnabled std::false_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_RequiresUserGestureForAudioPlayback std::true_type{}
#else
#define DEFAULT_VALUE_FOR_RequiresUserGestureForAudioPlayback std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_RequiresUserGestureForMediaPlayback std::false_type{}
#define DEFAULT_VALUE_FOR_RequiresUserGestureForVideoPlayback std::false_type{}
#define DEFAULT_VALUE_FOR_RequiresUserGestureToLoadVideo std::false_type{}
#define DEFAULT_VALUE_FOR_UsesSingleWebProcess std::false_type{}
#if HAVE(RUBBER_BANDING)
#define DEFAULT_VALUE_FOR_RubberBandingForSubScrollableRegionsEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_SampledPageTopColorMaxDifference 0
#define DEFAULT_VALUE_FOR_SampledPageTopColorMinHeight 0
#define DEFAULT_VALUE_FOR_UsesEncodingDetector std::false_type{}
#define DEFAULT_VALUE_FOR_SansSerifFontFamily "Helvetica"_str
#define DEFAULT_VALUE_FOR_SelectTrailingWhitespaceEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_SerifFontFamily "Times"_str
#define DEFAULT_VALUE_FOR_UsesBackForwardCache std::true_type{}
#define DEFAULT_VALUE_FOR_UserInterfaceDirectionPolicy UserInterfaceDirectionPolicy::Content
#define DEFAULT_VALUE_FOR_CaretBrowsingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_UseSystemAppearance std::false_type{}
#if ENABLE(SERVICE_CONTROLS)
#define DEFAULT_VALUE_FOR_ServiceControlsEnabled std::false_type{}
#endif
#if USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_GStreamerEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_ServiceWorkerEntitlementDisabledForTesting std::false_type{}
#define DEFAULT_VALUE_FOR_ShouldAllowUserInstalledFonts std::true_type{}
#define DEFAULT_VALUE_FOR_ColorFilterEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_UsePreHTML5ParserQuirks std::false_type{}
#define DEFAULT_VALUE_FOR_ShouldConvertInvalidURLsToBlank std::true_type{}
#define DEFAULT_VALUE_FOR_ShouldConvertPositionStyleOnCopy std::false_type{}
#define DEFAULT_VALUE_FOR_ShouldDecidePolicyBeforeLoadingQuickLookPreview std::false_type{}
#if ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_ShouldDisplayCaptions std::false_type{}
#endif
#if ENABLE(CONTENT_CHANGE_OBSERVER)
#define DEFAULT_VALUE_FOR_ContentChangeObserverEnabled std::true_type{}
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_ContentDispositionAttachmentSandboxEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ContentDispositionAttachmentSandboxEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_ForceWebGLUsesLowPower std::false_type{}
#if ENABLE(CONTEXT_MENU_QR_CODE_DETECTION)
#define DEFAULT_VALUE_FOR_ContextMenuQRCodeDetectionEnabled std::false_type{}
#endif
#if ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_ShouldDisplaySubtitles std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_ForceFTPDirectoryListings std::false_type{}
#define DEFAULT_VALUE_FOR_ForceCompositingMode std::false_type{}
#if ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_ShouldDisplayTextDescriptions std::false_type{}
#endif
#if ENABLE(TEXT_AUTOSIZING)
#define DEFAULT_VALUE_FOR_ShouldEnableTextAutosizingBoost std::false_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_UseImageDocumentForSubframePDF std::true_type{}
#else
#define DEFAULT_VALUE_FOR_UseImageDocumentForSubframePDF std::false_type{}
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_FixedFontFamily "Courier"_str
#else
#define DEFAULT_VALUE_FOR_FixedFontFamily "Courier New"_str
#endif
#define DEFAULT_VALUE_FOR_ShouldIgnoreMetaViewport std::false_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_ShouldPrintBackgrounds WebKit::defaultShouldPrintBackgrounds()
#elif PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_ShouldPrintBackgrounds std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ShouldPrintBackgrounds std::false_type{}
#endif
#if PLATFORM(COCOA) && PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_CursiveFontFamily "Snell Roundhand"_str
#elif PLATFORM(COCOA) && !PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_CursiveFontFamily "Apple Chancery"_str
#else
#define DEFAULT_VALUE_FOR_CursiveFontFamily "Comic Sans MS"_str
#endif
#if PLATFORM(IOS_FAMILY) || PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_ShouldRespectImageOrientation std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ShouldRespectImageOrientation std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_ShouldRestrictBaseURLSchemes std::false_type{}
#define DEFAULT_VALUE_FOR_ShouldSuppressTextInputFromEditingDuringProvisionalNavigation std::false_type{}
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_FantasyFontFamily "Papyrus"_str
#else
#define DEFAULT_VALUE_FOR_FantasyFontFamily "Impact"_str
#endif
#define DEFAULT_VALUE_FOR_DOMPasteAllowed std::false_type{}
#define DEFAULT_VALUE_FOR_ShouldUseServiceWorkerShortTimeout std::false_type{}
#define DEFAULT_VALUE_FOR_FTPDirectoryTemplatePath ""_str
#if ENABLE(DATA_DETECTION)
#define DEFAULT_VALUE_FOR_DataDetectorTypes static_cast<DataDetectorType>(0)
#endif
#if HAVE(APP_SSO)
#define DEFAULT_VALUE_FOR_ExtensibleSSOEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_TreatsAnyTextCSSLinkAsStylesheet std::false_type{}
#define DEFAULT_VALUE_FOR_LinkPreloadEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ShowsToolTipOverTruncatedText std::false_type{}
#define DEFAULT_VALUE_FOR_ThreadedScrollingEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_DefaultFixedFontSize 13
#define DEFAULT_VALUE_FOR_DefaultFontSize 16
#define DEFAULT_VALUE_FOR_DefaultTextEncodingName PAL::defaultTextEncodingNameForSystemLanguage()
#if PLATFORM(WATCHOS)
#define DEFAULT_VALUE_FOR_TextInteractionEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_TextInteractionEnabled std::true_type{}
#endif
#if HAVE(UIINTELLIGENCESUPPORT_FRAMEWORK)
#define DEFAULT_VALUE_FOR_TextExtractionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_TextExtractionEnabled std::false_type{}
#endif
#if ENABLE(TEXT_AUTOSIZING)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_TextAutosizingEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_TextAutosizingEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_DeveloperExtrasEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_DeviceHeight 0
#if ENABLE(DEVICE_ORIENTATION)
#define DEFAULT_VALUE_FOR_DeviceOrientationEventEnabled std::true_type{}
#endif
#if ENABLE(DEVICE_ORIENTATION)
#define DEFAULT_VALUE_FOR_DeviceOrientationPermissionAPIEnabled defaultDeviceOrientationPermissionAPIEnabled()
#endif
#define DEFAULT_VALUE_FOR_DeviceWidth 0
#define DEFAULT_VALUE_FOR_ShowsURLsInToolTipsEnabled std::false_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_TextAreasAreResizable std::false_type{}
#else
#define DEFAULT_VALUE_FOR_TextAreasAreResizable std::true_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_TemporaryTileCohortRetentionEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_TemporaryTileCohortRetentionEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_TelephoneNumberParsingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ShrinksStandaloneImagesToFit std::true_type{}
#if PLATFORM(WATCHOS)
#define DEFAULT_VALUE_FOR_DisabledAdaptationsMetaTagEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_DisabledAdaptationsMetaTagEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_DownloadAttributeEnabled std::true_type{}
#if PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_TabsToLinks std::true_type{}
#else
#define DEFAULT_VALUE_FOR_TabsToLinks std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_EditableLinkBehavior WebCore::EditableLinkBehavior::NeverLive
#if USE(SYSTEM_PREVIEW)
#define DEFAULT_VALUE_FOR_SystemPreviewEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_SystemLayoutDirection TextDirection::LTR
#define DEFAULT_VALUE_FOR_SuppressesIncrementalRendering std::false_type{}
#if PLATFORM(WATCHOS)
#define DEFAULT_VALUE_FOR_StandardFontFamily "system-ui"_str
#else
#define DEFAULT_VALUE_FOR_StandardFontFamily "Times"_str
#endif
#define DEFAULT_VALUE_FOR_EnableInheritURIQueryComponent std::false_type{}
#if ENABLE(ENCRYPTED_MEDIA)
#if PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_EncryptedMediaAPIEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_EncryptedMediaAPIEnabled std::true_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_Standalone std::false_type{}
#define DEFAULT_VALUE_FOR_SmartInsertDeleteEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_SpatialNavigationEnabled std::false_type{}
#if ENABLE(MEDIA_SOURCE)
#if USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_SourceBufferChangeTypeEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_SourceBufferChangeTypeEnabled std::true_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_TargetTextPseudoElementEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ThumbAndTrackPseudoElementsEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_LinkDNSPrefetchEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_SelectShowPickerEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_PageAtRuleMarginDescriptorsEnabled std::true_type{}
#if USE(AVFOUNDATION)
#if PLATFORM(WATCHOS)
#define DEFAULT_VALUE_FOR_AVFoundationEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_AVFoundationEnabled std::true_type{}
#endif
#endif
#if HAVE(AVKIT_CONTENT_SOURCE)
#define DEFAULT_VALUE_FOR_AVKitContentSourceEnabled std::false_type{}
#endif
#if USE(CORE_IMAGE)
#define DEFAULT_VALUE_FOR_AcceleratedFiltersEnabled std::false_type{}
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_AccessHandleEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AccessHandleEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_DOMTestingAPIsEnabled std::false_type{}
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_AllowMediaContentTypesRequiringHardwareSupportAsFallback std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AllowMediaContentTypesRequiringHardwareSupportAsFallback std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_AllowPrivacySensitiveOperationsInNonPersistentDataStores std::false_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_AllowViewportShrinkToFitContent std::true_type{}
#endif
#if ENABLE(WEBGL)
#if ENABLE(WEBGL_IN_WORKERS)
#define DEFAULT_VALUE_FOR_AllowWebGLInWorkers std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AllowWebGLInWorkers std::false_type{}
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_PerElementSpeakerSelectionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_PerElementSpeakerSelectionEnabled std::false_type{}
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_ExposeSpeakersWithoutMicrophoneEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ExposeSpeakersWithoutMicrophoneEnabled std::false_type{}
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_ExposeSpeakersEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ExposeSpeakersEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_AllowTopNavigationToDataURLs std::false_type{}
#define DEFAULT_VALUE_FOR_AllowUniversalAccessFromFileURLs std::false_type{}
#if ENABLE(WEB_ARCHIVE)
#define DEFAULT_VALUE_FOR_AlwaysAllowLocalWebarchive std::false_type{}
#endif
#if ENABLE(VP9)
#define DEFAULT_VALUE_FOR_SWVPDecodersAlwaysEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_AppBadgeEnabled std::false_type{}
#if ENABLE(APP_HIGHLIGHTS)
#define DEFAULT_VALUE_FOR_AppHighlightsEnabled std::false_type{}
#endif
#if USE(COORDINATED_GRAPHICS)
#define DEFAULT_VALUE_FOR_AsyncFrameScrollingEnabled std::true_type{}
#elif PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_AsyncFrameScrollingEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AsyncFrameScrollingEnabled std::false_type{}
#endif
#if USE(COORDINATED_GRAPHICS)
#define DEFAULT_VALUE_FOR_AsyncOverflowScrollingEnabled std::true_type{}
#elif PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_AsyncOverflowScrollingEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AsyncOverflowScrollingEnabled std::false_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_UseAsyncUIKitInteractions WebKit::defaultUseAsyncUIKitInteractions()
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_AsyncClipboardAPIEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AsyncClipboardAPIEnabled std::false_type{}
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
#define DEFAULT_VALUE_FOR_AttachmentElementEnabled std::false_type{}
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
#define DEFAULT_VALUE_FOR_AttachmentWideLayoutEnabled std::false_type{}
#endif
#if ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_ExtendedAudioDescriptionsEnabled std::false_type{}
#endif
#if ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_AudioDescriptionsEnabled std::false_type{}
#endif
#if ENABLE(DOM_AUDIO_SESSION)
#define DEFAULT_VALUE_FOR_DOMAudioSessionEnabled std::true_type{}
#endif
#if ENABLE(DOM_AUDIO_SESSION)
#define DEFAULT_VALUE_FOR_DOMAudioSessionFullEnabled std::false_type{}
#endif
#if ENABLE(FLEXIBLE_VIEW_SCALE_FACTOR)
#define DEFAULT_VALUE_FOR_AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_BeaconAPIEnabled std::true_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_BidiContentAwarePasteEnabled WebKit::defaultBidiContentAwarePasteEnabled()
#else
#define DEFAULT_VALUE_FOR_BidiContentAwarePasteEnabled std::false_type{}
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
#if ENABLE(REMOVE_XPC_AND_MACH_SANDBOX_EXTENSIONS_IN_WEBCONTENT)
#define DEFAULT_VALUE_FOR_BlockFontServiceInWebContentSandbox std::true_type{}
#else
#define DEFAULT_VALUE_FOR_BlockFontServiceInWebContentSandbox std::false_type{}
#endif
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
#if ENABLE(REMOVE_XPC_AND_MACH_SANDBOX_EXTENSIONS_IN_WEBCONTENT)
#define DEFAULT_VALUE_FOR_BlockIconServicesInWebContentSandbox std::true_type{}
#else
#define DEFAULT_VALUE_FOR_BlockIconServicesInWebContentSandbox std::false_type{}
#endif
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
#if ENABLE(REMOVE_XPC_AND_MACH_SANDBOX_EXTENSIONS_IN_WEBCONTENT)
#define DEFAULT_VALUE_FOR_BlockMobileAssetInWebContentSandbox std::true_type{}
#else
#define DEFAULT_VALUE_FOR_BlockMobileAssetInWebContentSandbox std::false_type{}
#endif
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(IOS)
#if ENABLE(REMOVE_XPC_AND_MACH_SANDBOX_EXTENSIONS_IN_WEBCONTENT)
#define DEFAULT_VALUE_FOR_BlockMobileGestaltInWebContentSandbox std::true_type{}
#else
#define DEFAULT_VALUE_FOR_BlockMobileGestaltInWebContentSandbox std::false_type{}
#endif
#endif
#if HAVE(SANDBOX_STATE_FLAGS) && PLATFORM(MAC)
#if ENABLE(REMOVE_XPC_AND_MACH_SANDBOX_EXTENSIONS_IN_WEBCONTENT)
#define DEFAULT_VALUE_FOR_BlockOpenDirectoryInWebContentSandbox std::true_type{}
#else
#define DEFAULT_VALUE_FOR_BlockOpenDirectoryInWebContentSandbox std::false_type{}
#endif
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
#define DEFAULT_VALUE_FOR_BlockWebInspectorInWebContentSandbox std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_BroadcastChannelEnabled std::true_type{}
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
#define DEFAULT_VALUE_FOR_BuiltInNotificationsEnabled defaultBuiltInNotificationsEnabled()
#endif
#define DEFAULT_VALUE_FOR_CSS3DTransformBackfaceVisibilityInteroperabilityEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSCounterStyleAtRuleImageSymbolsEnabled std::false_type{}
#if PLATFORM(COCOA) || USE(THEME_ADWAITA)
#define DEFAULT_VALUE_FOR_AccentColorEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AccentColorEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CSSAnchorPositioningEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSAnchorPositioningPositionVisibilityEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_DevolvableWidgetsEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSInputSecurityEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_MasonryEnabled std::false_type{}
#if PLATFORM(WIN)
#define DEFAULT_VALUE_FOR_OverscrollBehaviorEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_OverscrollBehaviorEnabled std::true_type{}
#endif
#if ENABLE(EXPERIMENTAL_FEATURES)
#define DEFAULT_VALUE_FOR_CSSPaintingAPIEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_CSSPaintingAPIEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CSSRhythmicSizingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSScrollAnchoringEnabled std::false_type{}
#if ENABLE(EXPERIMENTAL_FEATURES)
#define DEFAULT_VALUE_FOR_SpringTimingFunctionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_SpringTimingFunctionEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CSSTreeCountingFunctionsEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSTypedOMColorEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSURLModifiersEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSURLIntegrityModifierEnabled std::false_type{}
#if ENABLE(UNPREFIXED_BACKDROP_FILTER)
#define DEFAULT_VALUE_FOR_CSSUnprefixedBackdropFilterEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_CSSUnprefixedBackdropFilterEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CSSAppearanceBaseEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSAxisRelativePositionKeywordsEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSBackgroundClipBorderAreaEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSColorLayersEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSContrastColorEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSCornerShapeEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSDPropertyEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSDynamicRangeLimitMixEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSConstrainedDynamicRangeLimitEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSFieldSizingEnabled std::false_type{}
#if PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_CSSFontVariantEmojiEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_CSSFontVariantEmojiEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CSSLineClampEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSLineFitEdgeEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSProgressFunctionEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSRandomFunctionEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSRubyAlignEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSRubyOverhangEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSScrollbarColorEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSScrollbarGutterEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSScrollbarWidthEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSShapeFunctionEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSTextAutospaceEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSTextBoxTrimEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSTextGroupAlignEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSTextJustifyEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSTextSpacingTrimEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSTextUnderlinePositionLeftRightEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CSSTextWrapPrettyEnabled std::true_type{}
#if HAVE(CORE_ANIMATION_SEPARATED_LAYERS)
#define DEFAULT_VALUE_FOR_CSSTransformStyleSeparatedEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CacheAPIEnabled std::true_type{}
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_CanvasColorSpaceEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_CanvasColorSpaceEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CanvasFiltersEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CanvasLayersEnabled std::false_type{}
#if USE(CA) || USE(SKIA)
#define DEFAULT_VALUE_FOR_CanvasUsesAcceleratedDrawing std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_CanvasPixelFormatEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ChildProcessDebuggabilityEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ClearSiteDataHTTPHeaderEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ClearSiteDataExecutionContextsSupportEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CloseWatcherEnabled std::false_type{}
#if PLATFORM(COCOA) && !PLATFORM(WATCHOS) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_InputTypeColorEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InputTypeColorEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CompositingBordersVisible std::false_type{}
#define DEFAULT_VALUE_FOR_CompositingRepaintCountersVisible std::false_type{}
#define DEFAULT_VALUE_FOR_CompressionStreamEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ContactPickerAPIEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ContentInsetBackgroundFillEnabled WebKit::defaultContentInsetBackgroundFillEnabled()
#define DEFAULT_VALUE_FOR_CookieConsentAPIEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CookieStoreManagerEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CookieStoreAPIExtendedAttributesEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CookieStoreAPIEnabled defaultCookieStoreAPIEnabled()
#define DEFAULT_VALUE_FOR_CookieEnabled std::true_type{}
#if PLATFORM(MAC)
#define DEFAULT_VALUE_FOR_InputMethodUsesCorrectKeyEventOrder std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CrossDocumentViewTransitionsEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CrossOriginEmbedderPolicyEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_CrossOriginOpenerPolicyEnabled std::true_type{}
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE) || PLATFORM(WIN)
#define DEFAULT_VALUE_FOR_CustomPasteboardDataEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_CustomPasteboardDataEnabled std::false_type{}
#endif
#if PLATFORM(IOS) || PLATFORM(MAC) || PLATFORM(GTK) || PLATFORM(WPE) || PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_DOMPasteAccessRequestsEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_DOMPasteAccessRequestsEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_MutationEventsEnabled WebKit::defaultMutationEventsEnabled()
#define DEFAULT_VALUE_FOR_DOMTimersThrottlingEnabled std::true_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_ZoomOnDoubleTapWhenRoot std::false_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_AlwaysZoomOnDoubleTap std::false_type{}
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_DataTransferItemsEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_DataTransferItemsEnabled std::false_type{}
#endif
#if (PLATFORM(COCOA) && !PLATFORM(WATCHOS)) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_DataListElementEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_DataListElementEnabled std::false_type{}
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_InputTypeDateEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InputTypeDateEnabled std::false_type{}
#endif
#if PLATFORM(MAC) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_DateTimeInputsEditableComponentsEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_DateTimeInputsEditableComponentsEnabled std::false_type{}
#endif
#if ENABLE(DECLARATIVE_WEB_PUSH)
#define DEFAULT_VALUE_FOR_DeclarativeWebPush std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint std::true_type{}
#define DEFAULT_VALUE_FOR_DeprecationReportingEnabled std::false_type{}
#if ENABLE(MEDIA_SOURCE)
#define DEFAULT_VALUE_FOR_DetachableMediaSourceEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_UAVisualTransitionDetectionEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_DiagnosticLoggingEnabled std::false_type{}
#if ENABLE(WEB_AUTHN)
#define DEFAULT_VALUE_FOR_DigitalCredentialsEnabled WebKit::defaultDigitalCredentialsEnabled()
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_DirectoryUploadEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_DirectoryUploadEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_IsThirdPartyCookieBlockingDisabled std::false_type{}
#define DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalDisabled std::false_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_DisableScreenSizeOverride std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_ShouldDropNearSuspendedAssertionAfterDelay WebKit::defaultShouldDropNearSuspendedAssertionAfterDelay()
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
#define DEFAULT_VALUE_FOR_UseCGDisplayListsForDOMRendering std::true_type{}
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
#define DEFAULT_VALUE_FOR_ReplayCGDisplayListsIntoBackingStore std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_DynamicSiteInterventionsEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_EmbedElementEnabled std::true_type{}
#if PLATFORM(MAC)
#if ENABLE(INITIALIZE_ACCESSIBILITY_ON_DEMAND)
#define DEFAULT_VALUE_FOR_EnableAccessibilityOnDemand std::true_type{}
#else
#define DEFAULT_VALUE_FOR_EnableAccessibilityOnDemand std::false_type{}
#endif
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_AutomaticLiveResizeEnabled WebKit::defaultAutomaticLiveResizeEnabled()
#endif
#define DEFAULT_VALUE_FOR_CanvasFingerprintingQuirkEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_EnableElementCurrentCSSZoom std::false_type{}
#define DEFAULT_VALUE_FOR_EnumeratingAllNetworkInterfacesEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_EnumeratingVisibleNetworkInterfacesEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ICECandidateFilteringEnabled std::true_type{}
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
#define DEFAULT_VALUE_FOR_LegacyEncryptedMediaAPIEnabled std::true_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(IOS_FAMILY_SIMULATOR)
#define DEFAULT_VALUE_FOR_MockCaptureDevicesEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_MockCaptureDevicesEnabled std::false_type{}
#endif
#endif
#if ENABLE(MODEL_PROCESS)
#define DEFAULT_VALUE_FOR_ModelProcessEnabled std::true_type{}
#endif
#if ENABLE(PDFJS)
#if PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_PDFJSViewerEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_PDFJSViewerEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_AuxclickEventEnabled std::true_type{}
#if PLATFORM(MAC) && USE(RUNNINGBOARD)
#define DEFAULT_VALUE_FOR_BackgroundWebContentRunningBoardThrottlingEnabled WebKit::defaultRunningBoardThrottlingEnabled()
#endif
#define DEFAULT_VALUE_FOR_BackgroundFetchAPIEnabled std::false_type{}
#if HAVE(SANDBOX_STATE_FLAGS)
#define DEFAULT_VALUE_FOR_EnableDebuggingFeaturesInSandbox std::false_type{}
#endif
#if HAVE(NETWORK_LOADER)
#define DEFAULT_VALUE_FOR_CFNetworkNetworkLoaderEnabled std::false_type{}
#endif
#if HAVE(MACH_BOOTSTRAP_EXTENSION) || HAVE(SANDBOX_STATE_FLAGS)
#define DEFAULT_VALUE_FOR_ExperimentalSandboxEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_NavigatorUserAgentDataJavaScriptAPIEnabled std::false_type{}
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_BlobFileAccessEnforcementEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_BlobFileAccessEnforcementEnabled std::false_type{}
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_EnterKeyHintEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_EnterKeyHintEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_EventTimingEnabled std::false_type{}
#if PLATFORM(MAC)
#define DEFAULT_VALUE_FOR_EventHandlerDrivenSmoothKeyboardScrollingEnabled WebKit::defaultScrollAnimatorEnabled()
#else
#define DEFAULT_VALUE_FOR_EventHandlerDrivenSmoothKeyboardScrollingEnabled std::false_type{}
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
#define DEFAULT_VALUE_FOR_MediaSessionCoordinatorEnabled WebKit::defaultMediaSessionCoordinatorEnabled()
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR) && ENABLE(MEDIA_SESSION_PLAYLIST)
#define DEFAULT_VALUE_FOR_MediaSessionPlaylistEnabled WebKit::defaultMediaSessionCoordinatorEnabled()
#endif
#if ENABLE(MEDIA_STREAM)
#define DEFAULT_VALUE_FOR_ExposeCaptureDevicesAfterCaptureEnabled std::true_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#define DEFAULT_VALUE_FOR_ExposeDefaultSpeakerAsSpecificDeviceEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_FTPEnabled std::false_type{}
#if PLATFORM(IOS_FAMILY)
#if PLATFORM(IOS_FAMILY) && !PLATFORM(WATCHOS)
#define DEFAULT_VALUE_FOR_PreferFasterClickOverDoubleTap std::true_type{}
#else
#define DEFAULT_VALUE_FOR_PreferFasterClickOverDoubleTap std::false_type{}
#endif
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_FasterClicksEnabled std::true_type{}
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_FileSystemEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_FileSystemEnabled std::false_type{}
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_FileSystemWritableStreamEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_FileSystemWritableStreamEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_FileReaderAPIEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_FilterLinkDecorationByDefaultEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ForceLockdownFontParserEnabled std::false_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_ForceAlwaysUserScalable std::false_type{}
#endif
#if ENABLE(FORM_CONTROL_REFRESH)
#define DEFAULT_VALUE_FOR_FormControlRefreshEnabled std::true_type{}
#endif
#if ENABLE(CONTENT_EXTENSIONS)
#define DEFAULT_VALUE_FOR_IFrameResourceMonitoringTestingSettingsEnabled std::false_type{}
#endif
#if ENABLE(CONTENT_EXTENSIONS)
#define DEFAULT_VALUE_FOR_IFrameResourceMonitoringEnabled std::false_type{}
#endif
#if ENABLE(FULLSCREEN_API)
#define DEFAULT_VALUE_FOR_FullScreenKeyboardLock std::false_type{}
#endif
#if ENABLE(FULLSCREEN_API)
#if PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_FullScreenEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_FullScreenEnabled std::false_type{}
#endif
#endif
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_FullscreenSceneAspectRatioLockingEnabled std::true_type{}
#endif
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_FullscreenSceneDimmingEnabled std::true_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#define DEFAULT_VALUE_FOR_CaptureAudioInGPUProcessEnabled WebKit::defaultCaptureAudioInGPUProcessEnabled()
#endif
#if ENABLE(GPU_PROCESS)
#define DEFAULT_VALUE_FOR_BlockMediaLayerRehostingInWebContentProcess std::true_type{}
#endif
#if ENABLE(GPU_PROCESS) && !(PLATFORM(GTK) || PLATFORM(WPE))
#if ENABLE(GPU_PROCESS_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_UseGPUProcessForCanvasRenderingEnabled std::true_type{}
#elif USE(GRAPHICS_LAYER_WC)
#define DEFAULT_VALUE_FOR_UseGPUProcessForCanvasRenderingEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_UseGPUProcessForCanvasRenderingEnabled std::false_type{}
#endif
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_ManageCaptureStatusBarInGPUProcessEnabled WebKit::defaultManageCaptureStatusBarInGPUProcessEnabled()
#endif
#if ENABLE(GPU_PROCESS)
#define DEFAULT_VALUE_FOR_UseGPUProcessForDOMRenderingEnabled defaultUseGPUProcessForDOMRenderingEnabled()
#endif
#if ENABLE(GPU_PROCESS)
#if ENABLE(GPU_PROCESS_BY_DEFAULT) && !USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_UseGPUProcessForMediaEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_UseGPUProcessForMediaEnabled std::false_type{}
#endif
#endif
#if HAVE(SCREEN_CAPTURE_KIT)
#define DEFAULT_VALUE_FOR_UseGPUProcessForDisplayCapture std::true_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#if ENABLE(GPU_PROCESS_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_CaptureVideoInGPUProcessEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_CaptureVideoInGPUProcessEnabled std::false_type{}
#endif
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
#if ENABLE(GPU_PROCESS_BY_DEFAULT) && ENABLE(GPU_PROCESS_WEBGL_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_UseGPUProcessForWebGLEnabled std::true_type{}
#elif USE(GRAPHICS_LAYER_WC)
#define DEFAULT_VALUE_FOR_UseGPUProcessForWebGLEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_UseGPUProcessForWebGLEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_RTC)
#if ENABLE(GPU_PROCESS_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_WebRTCPlatformCodecsInGPUProcessEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebRTCPlatformCodecsInGPUProcessEnabled std::false_type{}
#endif
#endif
#if ENABLE(GAMEPAD)
#define DEFAULT_VALUE_FOR_GamepadTriggerRumbleEnabled std::false_type{}
#endif
#if ENABLE(GAMEPAD)
#define DEFAULT_VALUE_FOR_GamepadVibrationActuatorEnabled defaultGamepadVibrationActuatorEnabled()
#endif
#if ENABLE(GAMEPAD)
#define DEFAULT_VALUE_FOR_GamepadsEnabled std::true_type{}
#endif
#if ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_GenericCueAPIEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_GeolocationAPIEnabled std::true_type{}
#if USE(GRAPHICS_CONTEXT_FILTERS)
#define DEFAULT_VALUE_FOR_GraphicsContextFiltersEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_AcceleratedDrawingEnabled std::true_type{}
#if ENABLE(MODEL_ELEMENT)
#if PLATFORM(VISION) && ENABLE(MODEL_ELEMENT)
#define DEFAULT_VALUE_FOR_ModelElementEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ModelElementEnabled std::false_type{}
#endif
#endif
#if ENABLE(MODEL_ELEMENT)
#define DEFAULT_VALUE_FOR_ModelDocumentEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_InteractiveFormValidationEnabled std::true_type{}
#if ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_MediaEnabled std::true_type{}
#endif
#if PLATFORM(COCOA) && !PLATFORM(WATCHOS)
#define DEFAULT_VALUE_FOR_InputTypeColorEnhancementsEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InputTypeColorEnhancementsEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_DetailsAutoExpandEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CommandAttributesEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_HTMLLegacyAttributeValueSerializationEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_PopoverAttributeEnabled WebKit::defaultPopoverAttributeEnabled()
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_SwitchControlEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_SwitchControlEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_HTTPSByDefaultEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingAutoIncreases std::false_type{}
#if PLATFORM(COCOA) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingEnabled std::false_type{}
#endif
#if HAVE(MATERIAL_HOSTING)
#define DEFAULT_VALUE_FOR_HostedBlurMaterialInMediaControlsEnabled defaultHostedBlurMaterialInMediaControlsEnabled()
#endif
#if HAVE(SANDBOX_STATE_FLAGS)
#define DEFAULT_VALUE_FOR_BlockIOKitInWebContentSandbox std::true_type{}
#endif
#if HAVE(LOSSLESS_COMPRESSED_IOSURFACE_CG_SUPPORT)
#define DEFAULT_VALUE_FOR_IOSurfaceLosslessCompressionEnabled defaultIOSurfaceLosslessCompressionEnabled()
#else
#define DEFAULT_VALUE_FOR_IOSurfaceLosslessCompressionEnabled std::false_type{}
#endif
#if ENABLE(IPC_TESTING_API)
#define DEFAULT_VALUE_FOR_IPCTestingAPIEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_ItpDebugModeEnabled std::false_type{}
#if ENABLE(TEXT_AUTOSIZING)
#if PLATFORM(IOS_FAMILY) && !PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_TextAutosizingUsesIdempotentMode defaultTextAutosizingUsesIdempotentMode()
#else
#define DEFAULT_VALUE_FOR_TextAutosizingUsesIdempotentMode std::false_type{}
#endif
#endif
#if ENABLE(IPC_TESTING_API)
#define DEFAULT_VALUE_FOR_IgnoreInvalidMessageWhenIPCTestingAPIEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_IgnoreIframeEmbeddingProtectionsEnabled std::false_type{}
#if ENABLE(IMAGE_ANALYSIS)
#define DEFAULT_VALUE_FOR_ImageAnalysisDuringFindInPageEnabled std::false_type{}
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
#define DEFAULT_VALUE_FOR_ImageAnimationControlEnabled std::true_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_ImageCaptureEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ImageCaptureEnabled std::false_type{}
#endif
#endif
#if ENABLE(SERVICE_CONTROLS)
#define DEFAULT_VALUE_FOR_ImageControlsEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_InWindowFullscreenEnabled std::false_type{}
#if ENABLE(INCLUDE_IGNORED_IN_CORE_AX_TREE)
#define DEFAULT_VALUE_FOR_IncludeIgnoredInCoreAXTree std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_IndexedDBAPIEnabled std::true_type{}
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
#define DEFAULT_VALUE_FOR_InteractionRegionsEnabled std::true_type{}
#endif
#if ENABLE(ACCESSIBILITY_ISOLATED_TREE)
#if USE(ATSPI)
#define DEFAULT_VALUE_FOR_IsAccessibilityIsolatedTreeEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_IsAccessibilityIsolatedTreeEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_JavaScriptEnabled std::true_type{}
#if PLATFORM(IOS_FAMILY)
#if PLATFORM(APPLETV)
#define DEFAULT_VALUE_FOR_KeyboardDismissalGestureEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_KeyboardDismissalGestureEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_LayerBasedSVGEngineEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_LazyIframeLoadingEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_LazyImageLoadingEnabled std::true_type{}
#if ENABLE(WEBKIT_OVERFLOW_SCROLLING_CSS_PROPERTY)
#define DEFAULT_VALUE_FOR_LegacyOverflowScrollingTouchEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_LegacyLineLayoutVisualCoverageEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ShowModalDialogEnabled WebKit::defaultShowModalDialogEnabled()
#if ENABLE(MEDIA_STREAM)
#define DEFAULT_VALUE_FOR_MediaCaptureRequiresSecureConnection std::true_type{}
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
#define DEFAULT_VALUE_FOR_LimitedMatroskaSupportEnabled std::false_type{}
#endif
#if ENABLE(LINEAR_MEDIA_PLAYER)
#define DEFAULT_VALUE_FOR_LinearMediaPlayerEnabled WebKit::defaultLinearMediaPlayerEnabled()
#endif
#define DEFAULT_VALUE_FOR_LinkSanitizerEnabled std::false_type{}
#if ENABLE(SERVER_PRECONNECT)
#define DEFAULT_VALUE_FOR_LinkPreconnectEarlyHintsEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_LinkPreconnectEarlyHintsEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_LinkPrefetchEnabled std::false_type{}
#if ENABLE(WEB_ARCHIVE)
#define DEFAULT_VALUE_FOR_LoadWebArchiveWithEphemeralStorageEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_LocalFileContentSniffingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_LocalNetworkAccessEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_LocalStorageEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_LockdownFontParserEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_LogsPageMessagesToSystemConsoleEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_LoginStatusAPIEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_MainContentUserGestureOverrideEnabled std::false_type{}
#if ENABLE(MEDIA_SOURCE)
#define DEFAULT_VALUE_FOR_ManagedMediaSourceEnabled WebKit::defaultManagedMediaSourceEnabled()
#endif
#if ENABLE(MEDIA_SOURCE) && ENABLE(WIRELESS_PLAYBACK_TARGET)
#define DEFAULT_VALUE_FOR_ManagedMediaSourceNeedsAirPlay WebKit::defaultManagedMediaSourceNeedsAirPlay()
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_CoreMathMLEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_CoreMathMLEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_MediaCapabilitiesExtensionsEnabled std::true_type{}
#if ENABLE(EXTENSION_CAPABILITIES)
#if PLATFORM(IOS_FAMILY_SIMULATOR)
#define DEFAULT_VALUE_FOR_MediaCapabilityGrantsEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_MediaCapabilityGrantsEnabled std::true_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_MediaPlaybackEnabled std::true_type{}
#if ENABLE(MEDIA_SESSION)
#define DEFAULT_VALUE_FOR_MediaSessionEnabled std::true_type{}
#endif
#if ENABLE(MEDIA_SOURCE) && PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_MediaSourceEnabled WebKit::defaultMediaSourceEnabled()
#elif ENABLE(MEDIA_SOURCE) && !PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_MediaSourceEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_MediaSourceEnabled std::false_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_MediaDevicesEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_MediaDevicesEnabled std::false_type{}
#endif
#endif
#if ENABLE(MEDIA_RECORDER_WEBM)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_MediaRecorderEnabledWebM std::true_type{}
#else
#define DEFAULT_VALUE_FOR_MediaRecorderEnabledWebM std::false_type{}
#endif
#endif
#if ENABLE(MEDIA_RECORDER)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_MediaRecorderEnabled std::true_type{}
#elif USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_MediaRecorderEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_MediaRecorderEnabled std::false_type{}
#endif
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_MediaSessionCaptureToggleAPIEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_MediaSessionCaptureToggleAPIEnabled std::false_type{}
#endif
#if ENABLE(MEDIA_SOURCE_IN_WORKERS)
#define DEFAULT_VALUE_FOR_MediaSourceInWorkerEnabled std::true_type{}
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
#define DEFAULT_VALUE_FOR_MediaSourcePrefersDecompressionSession std::true_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_MediaStreamTrackProcessingEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_MediaStreamTrackProcessingEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_MetaViewportInteractiveWidgetEnabled std::false_type{}
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
#define DEFAULT_VALUE_FOR_ModelNoPortalAttributeEnabled std::false_type{}
#endif
#if USE(MODERN_AVCONTENTKEYSESSION)
#define DEFAULT_VALUE_FOR_ShouldUseModernAVContentKeySession std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_MomentumScrollingAnimatorEnabled std::true_type{}
#if PLATFORM(IOS_FAMILY) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_InputTypeMonthEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InputTypeMonthEnabled std::false_type{}
#endif
#if ENABLE(TOUCH_EVENTS)
#define DEFAULT_VALUE_FOR_MouseEventsSimulationEnabled std::false_type{}
#endif
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_MuteCameraOnMicrophoneInterruptionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_MuteCameraOnMicrophoneInterruptionEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_NavigationAPIEnabled std::false_type{}
#if ENABLE(APP_BOUND_DOMAINS)
#define DEFAULT_VALUE_FOR_NeedsInAppBrowserPrivacyQuirks std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_NeedsSiteSpecificQuirks std::true_type{}
#define DEFAULT_VALUE_FOR_NeedsStorageAccessFromFileURLsQuirk std::true_type{}
#define DEFAULT_VALUE_FOR_FlexFormattingContextIntegrationEnabled std::true_type{}
#if ENABLE(NOTIFICATION_EVENT)
#if ENABLE(NOTIFICATION_EVENT) && !PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_NotificationEventEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_NotificationEventEnabled std::false_type{}
#endif
#endif
#if ENABLE(NOTIFICATIONS)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_NotificationsEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_NotificationsEnabled std::true_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_ObservableEnabled std::false_type{}
#if ENABLE(AX_THREAD_TEXT_APIS)
#define DEFAULT_VALUE_FOR_AccessibilityThreadTextApisEnabled std::true_type{}
#endif
#if ENABLE(OFFSCREEN_CANVAS_IN_WORKERS)
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_OffscreenCanvasInWorkersEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_OffscreenCanvasInWorkersEnabled std::false_type{}
#endif
#endif
#if ENABLE(OFFSCREEN_CANVAS)
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_OffscreenCanvasEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_OffscreenCanvasEnabled std::false_type{}
#endif
#endif
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_OpportunisticSweepingAndGarbageCollectionEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_OpportunisticSweepingAndGarbageCollectionEnabled std::true_type{}
#endif
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES) && 0
#define DEFAULT_VALUE_FOR_OptInPartitionedCookiesEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_OverlappingBackingStoreProvidersEnabled std::true_type{}
#if ENABLE(OVERLAY_REGIONS_IN_EVENT_REGION)
#define DEFAULT_VALUE_FOR_OverlayRegionsEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_PageVisibilityBasedProcessSuppressionEnabled std::true_type{}
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_PermissionsAPIEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_PermissionsAPIEnabled std::false_type{}
#endif
#if HAVE(PHOTOS_UI)
#define DEFAULT_VALUE_FOR_PhotoPickerPrefersOriginalImageFormat std::false_type{}
#endif
#if HAVE(PIP_SKIP_PREROLL)
#define DEFAULT_VALUE_FOR_PictureInPicturePlaybackStateEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_GetCoalescedEventsEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_GetPredictedEventsEnabled std::true_type{}
#if ENABLE(POINTER_LOCK)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_PointerLockEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_PointerLockEnabled std::true_type{}
#endif
#endif
#if ENABLE(POINTER_LOCK)
#define DEFAULT_VALUE_FOR_PointerLockOptionsEnabled std::true_type{}
#endif
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_PreferPageRenderingUpdatesNear60FPSEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_PreferPageRenderingUpdatesNear60FPSEnabled std::true_type{}
#endif
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
#define DEFAULT_VALUE_FOR_PreferSpatialAudioExperience WebKit::defaultPreferSpatialAudioExperience()
#endif
#if ENABLE(FULLSCREEN_API)
#define DEFAULT_VALUE_FOR_VideoFullsceenPrefersMostVisibleHeuristic std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_PrivateClickMeasurementDebugModeEnabled std::false_type{}
#if HAVE(RSA_BSSA)
#define DEFAULT_VALUE_FOR_PrivateClickMeasurementFraudPreventionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_PrivateClickMeasurementFraudPreventionEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_PrivateClickMeasurementEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_PrivateTokenUsageByThirdPartyEnabled std::true_type{}
#if ENABLE(DAMAGE_TRACKING)
#if PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_PropagateDamagingInformation std::true_type{}
#else
#define DEFAULT_VALUE_FOR_PropagateDamagingInformation std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_PushAPIEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_LegacyPluginQuirkForMailSignaturesEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_GoogleAntiFlickerOptimizationQuirkEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ReadableByteStreamAPIEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_RemoteMediaSessionManagerEnabled std::false_type{}
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_RemotePlaybackEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_RemotePlaybackEnabled std::true_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_RemoteSnapshottingEnabled std::false_type{}
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
#define DEFAULT_VALUE_FOR_RemoveBackgroundEnabled defaultRemoveBackgroundEnabled()
#endif
#if PLATFORM(COCOA) && HAVE(AVSAMPLEBUFFERVIDEOOUTPUT)
#define DEFAULT_VALUE_FOR_RequestVideoFrameCallbackEnabled std::true_type{}
#elif USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_RequestVideoFrameCallbackEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_RequestVideoFrameCallbackEnabled std::false_type{}
#endif
#if HAVE(SC_CONTENT_SHARING_PICKER)
#define DEFAULT_VALUE_FOR_RequireUAGetDisplayMediaPrompt std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_LoginStatusAPIRequiresWebAuthnEnabled std::false_type{}
#if ENABLE(MEDIA_STREAM)
#define DEFAULT_VALUE_FOR_SpeakerSelectionRequiresUserGesture std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_FullscreenRequirementForScreenOrientationLockingEnabled std::true_type{}
#if ENABLE(MEDIA_STREAM)
#define DEFAULT_VALUE_FOR_GetUserMediaRequiresFocus std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_ResourceLoadSchedulingEnabled std::true_type{}
#if ENABLE(RESOURCE_USAGE)
#define DEFAULT_VALUE_FOR_ResourceUsageOverlayVisible std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_RespondToThermalPressureAggressively std::false_type{}
#define DEFAULT_VALUE_FOR_SKAttributionEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_SafeBrowsingEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_IsSameSiteStrictEnforcementEnabled std::false_type{}
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_ScopedCustomElementRegistryEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ScopedCustomElementRegistryEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_ScreenOrientationLockingAPIEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ScreenOrientationAPIEnabled WebKit::defaultShouldEnableScreenOrientationAPI()
#if ENABLE(SCREEN_TIME)
#define DEFAULT_VALUE_FOR_ScreenTimeEnabled defaultScreenTimeEnabled()
#endif
#define DEFAULT_VALUE_FOR_ScreenWakeLockAPIEnabled std::true_type{}
#if ENABLE(MEDIA_STREAM)
#if PLATFORM(MAC) || USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_ScreenCaptureEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ScreenCaptureEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_ScriptTrackingPrivacyLoggingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ScriptTrackingPrivacyProtectionsEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ScrollingPerformanceTestingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ScrollToTextFragmentFeatureDetectionEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ScrollToTextFragmentGenerationEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ScrollToTextFragmentIndicatorEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ScrollToTextFragmentMarkingEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ScrollToTextFragmentEnabled std::true_type{}
#if PLATFORM(MAC)
#define DEFAULT_VALUE_FOR_ScrollAnimatorEnabled WebKit::defaultScrollAnimatorEnabled()
#elif PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_ScrollAnimatorEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_ScrollAnimatorEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_ScrollDrivenAnimationsEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_SecureContextChecksEnabled std::true_type{}
#if PLATFORM(VISION)
#define DEFAULT_VALUE_FOR_SelectionFlippingEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_SelectionFlippingEnabled std::true_type{}
#endif
#if PLATFORM(IOS_FAMILY)
#if ENABLE(SELECTION_HONORS_OVERFLOW_SCROLLING_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_SelectionHonorsOverflowScrolling std::true_type{}
#else
#define DEFAULT_VALUE_FOR_SelectionHonorsOverflowScrolling std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_ServiceWorkerInstallEventEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ServiceWorkerNavigationPreloadEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ServiceWorkersEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ShapeDetection std::false_type{}
#define DEFAULT_VALUE_FOR_SiteIsolationSharedProcessEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_SharedWorkerEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ShowMediaStatsContextMenuItemEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_ShowFrameProcessBordersEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_SidewaysWritingModesEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_SiteIsolationEnabled std::false_type{}
#if ENABLE(SPATIAL_IMAGE_CONTROLS)
#define DEFAULT_VALUE_FOR_SpatialImageControlsEnabled std::false_type{}
#endif
#if HAVE(SPEECHRECOGNIZER) && ENABLE(MEDIA_STREAM)
#define DEFAULT_VALUE_FOR_SpeechRecognitionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_SpeechRecognitionEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_SpeechSynthesisAPIEnabled std::true_type{}
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_StorageAPIEstimateEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_StorageAPIEstimateEnabled std::false_type{}
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_StorageAPIEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_StorageAPIEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_StorageBlockingPolicy WebCore::StorageBlockingPolicy::BlockThirdParty
#define DEFAULT_VALUE_FOR_SupportHDRCompositorTonemappingEnabled std::false_type{}
#if ENABLE(SUPPORT_HDR_DISPLAY_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_SupportHDRDisplayEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_SupportHDRDisplayEnabled std::false_type{}
#endif
#if PLATFORM(PLAYSTATION)
#define DEFAULT_VALUE_FOR_ProcessSwapOnCrossSiteNavigationEnabled std::false_type{}
#else
#define DEFAULT_VALUE_FOR_ProcessSwapOnCrossSiteNavigationEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_ShouldTakeNearSuspendedAssertions defaultShouldTakeNearSuspendedAssertion()
#if ENABLE(WRITING_TOOLS)
#define DEFAULT_VALUE_FOR_TextAnimationsEnabled std::true_type{}
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
#define DEFAULT_VALUE_FOR_TextRecognitionInVideosEnabled defaultTextRecognitionInVideosEnabled()
#endif
#if ENABLE(MEDIA_SOURCE)
#define DEFAULT_VALUE_FOR_TextTracksInMSEEnabled std::false_type{}
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
#define DEFAULT_VALUE_FOR_ThreadedAnimationResolutionEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_TiledScrollingIndicatorVisible std::false_type{}
#if PLATFORM(COCOA) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_InputTypeTimeEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InputTypeTimeEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_TopContentInsetBackgroundCanChangeAfterScrolling WebKit::defaultTopContentInsetBackgroundCanChangeAfterScrolling()
#if ENABLE(WEBXR)
#define DEFAULT_VALUE_FOR_TouchInputCompatibilityEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_TrackConfigurationEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_TrustedTypesEnabled WebKit::defaultTrustedTypesEnabled()
#define DEFAULT_VALUE_FOR_URLPatternAPIEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_UndoManagerAPIEnabled std::false_type{}
#if ENABLE(UNIFIED_PDF)
#define DEFAULT_VALUE_FOR_UnifiedPDFEnabled WebKit::defaultUnifiedPDFEnabled()
#endif
#if ENABLE(DAMAGE_TRACKING)
#if PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_UnifyDamagedRegions std::true_type{}
#else
#define DEFAULT_VALUE_FOR_UnifyDamagedRegions std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_IPAddressAndLocalhostMixedContentUpgradeTestingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_UpgradeKnownHostsToHTTPSEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_UpgradeMixedContentEnabled std::true_type{}
#if ENABLE(ARKIT_INLINE_PREVIEW)
#define DEFAULT_VALUE_FOR_UseARKitForModel std::true_type{}
#endif
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
#if PLATFORM(APPLETV)
#define DEFAULT_VALUE_FOR_UseAVCaptureDeviceRotationCoordinatorAPI std::true_type{}
#else
#define DEFAULT_VALUE_FOR_UseAVCaptureDeviceRotationCoordinatorAPI std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_UseIFCForSVGText std::false_type{}
#if ENABLE(MEDIA_STREAM)
#define DEFAULT_VALUE_FOR_UseMicrophoneMuteStatusAPI std::false_type{}
#endif
#if HAVE(SCENEKIT)
#define DEFAULT_VALUE_FOR_UseSceneKitForModel std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_UseGiantTiles std::false_type{}
#if ENABLE(DAMAGE_TRACKING)
#define DEFAULT_VALUE_FOR_UseDamagingInformationForCompositing std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_UserActivationAPIEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_UserGesturePromisePropagationEnabled std::true_type{}
#if HAVE(WEBCONTENTRESTRICTIONS)
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
#define DEFAULT_VALUE_FOR_UsesWebContentRestrictionsForFilter std::true_type{}
#else
#define DEFAULT_VALUE_FOR_UsesWebContentRestrictionsForFilter std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_ServiceWorkersUserGestureEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_VerifyWindowOpenUserGestureFromUIProcess std::false_type{}
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_VerticalFormControlsEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_VerticalFormControlsEnabled std::false_type{}
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
#define DEFAULT_VALUE_FOR_VideoRendererProtectedFallbackDisabled std::true_type{}
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
#define DEFAULT_VALUE_FOR_VideoRendererUseDecompressionSessionForProtected std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_ViewTransitionClassesEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ViewTransitionTypesEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ViewTransitionsEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ViewGestureDebuggingEnabled std::false_type{}
#if ENABLE(IMAGE_ANALYSIS)
#define DEFAULT_VALUE_FOR_VisualTranslationEnabled defaultVisualTranslationEnabled()
#endif
#define DEFAULT_VALUE_FOR_VisualViewportAPIEnabled std::true_type{}
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_VisuallyContiguousBidiTextSelectionEnabled WebKit::defaultVisuallyContiguousBidiTextSelectionEnabled()
#endif
#define DEFAULT_VALUE_FOR_WebAPIStatisticsEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_WebAPIsInShadowRealmEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_WebAnimationsOverallProgressPropertyEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_WebAnimationsCustomEffectsEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_WebAnimationsCustomFrameRateEnabled std::false_type{}
#if ENABLE(WEB_ARCHIVE)
#define DEFAULT_VALUE_FOR_WebArchiveDebugModeEnabled std::false_type{}
#endif
#if ENABLE(WEB_ARCHIVE)
#define DEFAULT_VALUE_FOR_WebArchiveTestingModeEnabled std::false_type{}
#endif
#if HAVE(WEB_AUTHN_AS_MODERN)
#define DEFAULT_VALUE_FOR_WebAuthenticationASEnabled std::true_type{}
#endif
#if ENABLE(WEB_AUTHN)
#define DEFAULT_VALUE_FOR_WebAuthenticationEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_WebCryptoSafeCurvesEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_WebCryptoX25519Enabled std::true_type{}
#define DEFAULT_VALUE_FOR_WebLocksAPIEnabled std::true_type{}
#if PLATFORM(COCOA) && !PLATFORM(WATCHOS) && !PLATFORM(APPLETV)
#define DEFAULT_VALUE_FOR_WebShareFileAPIEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebShareFileAPIEnabled std::false_type{}
#endif
#if PLATFORM(COCOA) && !PLATFORM(WATCHOS) && !PLATFORM(APPLETV)
#define DEFAULT_VALUE_FOR_WebShareEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebShareEnabled std::false_type{}
#endif
#if ENABLE(WEBASSEMBLY)
#define DEFAULT_VALUE_FOR_WebAssemblyESMIntegrationEnabled std::false_type{}
#endif
#if ENABLE(WEB_CODECS)
#if USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_WebCodecsAV1Enabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebCodecsAV1Enabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_CODECS)
#define DEFAULT_VALUE_FOR_WebCodecsAudioEnabled std::true_type{}
#endif
#if ENABLE(WEB_CODECS)
#if USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_WebCodecsHEVCEnabled std::true_type{}
#elif PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_WebCodecsHEVCEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebCodecsHEVCEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_CODECS)
#if USE(LIBWEBRTC) && PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_WebCodecsVideoEnabled WebKit::defaultPeerConnectionEnabledAvailable()
#elif USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_WebCodecsVideoEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebCodecsVideoEnabled std::false_type{}
#endif
#endif
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
#define DEFAULT_VALUE_FOR_WebExtensionBookmarksEnabled std::false_type{}
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
#define DEFAULT_VALUE_FOR_WebExtensionSidebarEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_WebGLDraftExtensionsEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_WebGLTimerQueriesEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_WebGLEnabled std::true_type{}
#if ENABLE(WEBGPU_BY_DEFAULT) && HAVE(SUPPORT_HDR_DISPLAY)
#define DEFAULT_VALUE_FOR_WebGPUHDREnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebGPUHDREnabled std::false_type{}
#endif
#if PLATFORM(VISION) && ENABLE(WEBXR_WEBGPU_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_WebXRWebGPUBindingsEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebXRWebGPUBindingsEnabled std::false_type{}
#endif
#if ENABLE(WEBGPU_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_WebGPUEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebGPUEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_WebInspectorEngineeringSettingsAllowed std::false_type{}
#if ENABLE(WEB_RTC)
#if USE(GSTREAMER)
#define DEFAULT_VALUE_FOR_WebRTCAV1CodecEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebRTCAV1CodecEnabled std::false_type{}
#endif
#endif
#define DEFAULT_VALUE_FOR_WebRTCAudioLatencyAdaptationEnabled std::true_type{}
#if ENABLE(WEB_RTC)
#define DEFAULT_VALUE_FOR_WebRTCDTMFEnabled std::true_type{}
#endif
#if ENABLE(WEB_RTC)
#if USE(LIBWEBRTC) && PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_WebRTCEncodedTransformEnabled WebKit::defaultPeerConnectionEnabledAvailable()
#elif USE(GSTREAMER_WEBRTC)
#define DEFAULT_VALUE_FOR_WebRTCEncodedTransformEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebRTCEncodedTransformEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_RTC)
#define DEFAULT_VALUE_FOR_WebRTCH264HardwareEncoderEnabled std::true_type{}
#endif
#if ENABLE(WEB_RTC)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_WebRTCH265CodecEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebRTCH265CodecEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_RTC)
#define DEFAULT_VALUE_FOR_WebRTCL4SEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_WebRTCMediaPipelineAdditionalLoggingEnabled std::false_type{}
#if ENABLE(WEB_RTC)
#if PLATFORM(GTK) || PLATFORM(WPE)
#define DEFAULT_VALUE_FOR_LegacyWebRTCOfferOptionsEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_LegacyWebRTCOfferOptionsEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_RTC)
#define DEFAULT_VALUE_FOR_PeerConnectionVideoScalingAdaptationDisabled std::false_type{}
#endif
#if ENABLE(WEB_RTC)
#if USE(LIBWEBRTC)
#define DEFAULT_VALUE_FOR_PeerConnectionEnabled WebKit::defaultPeerConnectionEnabledAvailable()
#elif USE(GSTREAMER_WEBRTC)
#define DEFAULT_VALUE_FOR_PeerConnectionEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_PeerConnectionEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_RTC)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_WebRTCRemoteVideoFrameEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebRTCRemoteVideoFrameEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_RTC)
#define DEFAULT_VALUE_FOR_WebRTCSFrameTransformEnabled std::false_type{}
#endif
#if ENABLE(WEB_RTC)
#define DEFAULT_VALUE_FOR_WebRTCSocketsProxyingEnabled std::true_type{}
#endif
#if ENABLE(WEB_RTC)
#define DEFAULT_VALUE_FOR_WebRTCUDPPortRange "0:0"_str
#endif
#if ENABLE(WEB_RTC)
#define DEFAULT_VALUE_FOR_WebRTCVP9Profile0CodecEnabled std::true_type{}
#endif
#if ENABLE(WEB_RTC)
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_WebRTCVP9Profile2CodecEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebRTCVP9Profile2CodecEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_WebRTCInterfaceMonitoringViaNWEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_WebTransportEnabled std::false_type{}
#if ENABLE(WEBXR)
#define DEFAULT_VALUE_FOR_WebXRAugmentedRealityModuleEnabled std::false_type{}
#endif
#if ENABLE(WEBXR)
#define DEFAULT_VALUE_FOR_WebXREnabled std::true_type{}
#endif
#if ENABLE(WEBXR)
#define DEFAULT_VALUE_FOR_WebXRGamepadsModuleEnabled std::true_type{}
#endif
#if ENABLE(WEBXR_HANDS)
#define DEFAULT_VALUE_FOR_WebXRHandInputModuleEnabled std::true_type{}
#endif
#if ENABLE(WEBXR_LAYERS)
#if PLATFORM(VISION) && ENABLE(WEBXR_WEBGPU_BY_DEFAULT)
#define DEFAULT_VALUE_FOR_WebXRLayersAPIEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_WebXRLayersAPIEnabled std::false_type{}
#endif
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
#define DEFAULT_VALUE_FOR_WebPageSpatialBackdropEnabled std::false_type{}
#endif
#if PLATFORM(IOS_FAMILY) && !PLATFORM(APPLETV) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_InputTypeWeekEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InputTypeWeekEnabled std::false_type{}
#endif
#if PLATFORM(MAC)
#define DEFAULT_VALUE_FOR_WheelEventGesturesBecomeNonBlocking WebKit::defaultWheelEventGesturesBecomeNonBlocking()
#else
#define DEFAULT_VALUE_FOR_WheelEventGesturesBecomeNonBlocking std::true_type{}
#endif
#if PLATFORM(MAC)
#define DEFAULT_VALUE_FOR_PassiveWheelListenersAsDefaultOnDocument WebKit::defaultPassiveWheelListenersAsDefaultOnDocument()
#else
#define DEFAULT_VALUE_FOR_PassiveWheelListenersAsDefaultOnDocument std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_WorkerAsynchronousURLErrorHandlingEnabled std::false_type{}
#if PLATFORM(COCOA)
#if PLATFORM(IOS_FAMILY)
#define DEFAULT_VALUE_FOR_WriteRichTextDataWhenCopyingOrDragging WebKit::defaultWriteRichTextDataWhenCopyingOrDragging()
#else
#define DEFAULT_VALUE_FOR_WriteRichTextDataWhenCopyingOrDragging std::true_type{}
#endif
#endif
#if ENABLE(WRITING_SUGGESTIONS)
#define DEFAULT_VALUE_FOR_WritingSuggestionsAttributeEnabled std::true_type{}
#endif
#if ENABLE(XSLT)
#define DEFAULT_VALUE_FOR_XSLTEnabled std::true_type{}
#endif
#define DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalReproTestingEnabled std::false_type{}
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_AltitudeAngleEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AltitudeAngleEnabled std::false_type{}
#endif
#if PLATFORM(COCOA)
#define DEFAULT_VALUE_FOR_AzimuthAngleEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_AzimuthAngleEnabled std::false_type{}
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK)
#define DEFAULT_VALUE_FOR_InputTypeDateTimeLocalEnabled std::true_type{}
#else
#define DEFAULT_VALUE_FOR_InputTypeDateTimeLocalEnabled std::false_type{}
#endif
#define DEFAULT_VALUE_FOR_CaretPositionFromPointEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_HiddenUntilFoundEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_HTTPEquivEnabled std::true_type{}
#define DEFAULT_VALUE_FOR_ShadowRootReferenceTargetEnabledForAriaOwns std::false_type{}
#define DEFAULT_VALUE_FOR_ShadowRootReferenceTargetEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_RequestIdleCallbackEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_RequestStorageAccessThrowsExceptionUntilReload std::false_type{}
#define DEFAULT_VALUE_FOR_ScrollendEventEnabled std::false_type{}
#define DEFAULT_VALUE_FOR_CSSWordBreakAutoPhraseEnabled std::false_type{}

// macro(KeyUpper, KeyLower, TypeNameUpper, TypeName, DefaultValue, HumanReadableName, HumanReadableDescription)

#define FOR_EACH_WEBKIT_PREFERENCE(macro) \
    macro(DatabasesEnabled, databasesEnabled, Bool, bool, DEFAULT_VALUE_FOR_DatabasesEnabled, "", "") \
    macro(LoadDeferringEnabled, loadDeferringEnabled, Bool, bool, DEFAULT_VALUE_FOR_LoadDeferringEnabled, "", "") \
    macro(AcceleratedCompositingEnabled, acceleratedCompositingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AcceleratedCompositingEnabled, "", "") \
    macro(AcceleratedCompositingForFixedPositionEnabled, acceleratedCompositingForFixedPositionEnabled, Bool, bool, DEFAULT_VALUE_FOR_AcceleratedCompositingForFixedPositionEnabled, "", "") \
    macro(WirelessPlaybackTargetAPIEnabled, wirelessPlaybackTargetAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_WirelessPlaybackTargetAPIEnabled, "", "") \
    macro(LoadsImagesAutomatically, loadsImagesAutomatically, Bool, bool, DEFAULT_VALUE_FOR_LoadsImagesAutomatically, "", "") \
    macro(LinkPreconnect, linkPreconnect, Bool, bool, DEFAULT_VALUE_FOR_LinkPreconnect, "", "") \
    macro(LongRunningMediaCaptureStreamRepromptIntervalInHours, longRunningMediaCaptureStreamRepromptIntervalInHours, Double, double, DEFAULT_VALUE_FOR_LongRunningMediaCaptureStreamRepromptIntervalInHours, "", "") \
    macro(WindowFocusRestricted, windowFocusRestricted, Bool, bool, DEFAULT_VALUE_FOR_WindowFocusRestricted, "", "") \
    macro(AggressiveTileRetentionEnabled, aggressiveTileRetentionEnabled, Bool, bool, DEFAULT_VALUE_FOR_AggressiveTileRetentionEnabled, "", "") \
    macro(AllowContentSecurityPolicySourceStarToMatchAnyProtocol, allowContentSecurityPolicySourceStarToMatchAnyProtocol, Bool, bool, DEFAULT_VALUE_FOR_AllowContentSecurityPolicySourceStarToMatchAnyProtocol, "", "") \
    macro(AllowDisplayOfInsecureContent, allowDisplayOfInsecureContent, Bool, bool, DEFAULT_VALUE_FOR_AllowDisplayOfInsecureContent, "", "") \
    macro(AllowFileAccessFromFileURLs, allowFileAccessFromFileURLs, Bool, bool, DEFAULT_VALUE_FOR_AllowFileAccessFromFileURLs, "", "") \
    macro(LowPowerVideoAudioBufferSizeEnabled, lowPowerVideoAudioBufferSizeEnabled, Bool, bool, DEFAULT_VALUE_FOR_LowPowerVideoAudioBufferSizeEnabled, "", "") \
    macro(AllowMultiElementImplicitSubmission, allowMultiElementImplicitSubmission, Bool, bool, DEFAULT_VALUE_FOR_AllowMultiElementImplicitSubmission, "", "") \
    macro(ManagedMediaSourceHighThreshold, managedMediaSourceHighThreshold, Double, double, DEFAULT_VALUE_FOR_ManagedMediaSourceHighThreshold, "", "") \
    macro(AllowRunningOfInsecureContent, allowRunningOfInsecureContent, Bool, bool, DEFAULT_VALUE_FOR_AllowRunningOfInsecureContent, "", "") \
    macro(AllowTestOnlyIPC, allowTestOnlyIPC, Bool, bool, DEFAULT_VALUE_FOR_AllowTestOnlyIPC, "", "") \
    macro(ManagedMediaSourceLowThreshold, managedMediaSourceLowThreshold, Double, double, DEFAULT_VALUE_FOR_ManagedMediaSourceLowThreshold, "", "") \
    macro(MathMLEnabled, mathMLEnabled, Bool, bool, DEFAULT_VALUE_FOR_MathMLEnabled, "", "") \
    macro(MaxParseDuration, maxParseDuration, Double, double, DEFAULT_VALUE_FOR_MaxParseDuration, "", "") \
    macro(MediaAudioCodecIDsAllowedInLockdownMode, mediaAudioCodecIDsAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaAudioCodecIDsAllowedInLockdownMode, "", "") \
    macro(AllowsAirPlayForMediaPlayback, allowsAirPlayForMediaPlayback, Bool, bool, DEFAULT_VALUE_FOR_AllowsAirPlayForMediaPlayback, "", "") \
    macro(AllowsInlineMediaPlayback, allowsInlineMediaPlayback, Bool, bool, DEFAULT_VALUE_FOR_AllowsInlineMediaPlayback, "", "") \
    macro(AllowsInlineMediaPlaybackAfterFullscreen, allowsInlineMediaPlaybackAfterFullscreen, Bool, bool, DEFAULT_VALUE_FOR_AllowsInlineMediaPlaybackAfterFullscreen, "", "") \
    macro(AllowsPictureInPictureMediaPlayback, allowsPictureInPictureMediaPlayback, Bool, bool, DEFAULT_VALUE_FOR_AllowsPictureInPictureMediaPlayback, "", "") \
    macro(AlternateFullScreenControlDesignEnabled, alternateFullScreenControlDesignEnabled, Bool, bool, DEFAULT_VALUE_FOR_AlternateFullScreenControlDesignEnabled, "", "") \
    macro(WebSocketEnabled, webSocketEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebSocketEnabled, "", "") \
    macro(MediaCapabilitiesEnabled, mediaCapabilitiesEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaCapabilitiesEnabled, "", "") \
    macro(WebSecurityEnabled, webSecurityEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebSecurityEnabled, "", "") \
    macro(AnimatedImageAsyncDecodingEnabled, animatedImageAsyncDecodingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AnimatedImageAsyncDecodingEnabled, "", "") \
    macro(LayoutViewportHeightExpansionFactor, layoutViewportHeightExpansionFactor, Double, double, DEFAULT_VALUE_FOR_LayoutViewportHeightExpansionFactor, "", "") \
    macro(LayoutFallbackWidth, layoutFallbackWidth, UInt32, uint32_t, DEFAULT_VALUE_FOR_LayoutFallbackWidth, "", "") \
    macro(AppleMailPaginationQuirkEnabled, appleMailPaginationQuirkEnabled, Bool, bool, DEFAULT_VALUE_FOR_AppleMailPaginationQuirkEnabled, "", "") \
    macro(ApplePayCapabilityDisclosureAllowed, applePayCapabilityDisclosureAllowed, Bool, bool, DEFAULT_VALUE_FOR_ApplePayCapabilityDisclosureAllowed, "", "") \
    macro(ApplePayEnabled, applePayEnabled, Bool, bool, DEFAULT_VALUE_FOR_ApplePayEnabled, "", "") \
    macro(LargeImageAsyncDecodingEnabled, largeImageAsyncDecodingEnabled, Bool, bool, DEFAULT_VALUE_FOR_LargeImageAsyncDecodingEnabled, "", "") \
    macro(MediaCaptionFormatTypesAllowedInLockdownMode, mediaCaptionFormatTypesAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaCaptionFormatTypesAllowedInLockdownMode, "", "") \
    macro(JavaScriptRuntimeFlags, javaScriptRuntimeFlags, UInt32, uint32_t, DEFAULT_VALUE_FOR_JavaScriptRuntimeFlags, "", "") \
    macro(AsynchronousSpellCheckingEnabled, asynchronousSpellCheckingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AsynchronousSpellCheckingEnabled, "", "") \
    macro(JavaScriptMarkupEnabled, javaScriptMarkupEnabled, Bool, bool, DEFAULT_VALUE_FOR_JavaScriptMarkupEnabled, "", "") \
    macro(MediaCodecTypesAllowedInLockdownMode, mediaCodecTypesAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaCodecTypesAllowedInLockdownMode, "", "") \
    macro(AudioControlsScaleWithPageZoom, audioControlsScaleWithPageZoom, Bool, bool, DEFAULT_VALUE_FOR_AudioControlsScaleWithPageZoom, "", "") \
    macro(JavaScriptCanOpenWindowsAutomatically, javaScriptCanOpenWindowsAutomatically, Bool, bool, DEFAULT_VALUE_FOR_JavaScriptCanOpenWindowsAutomatically, "", "") \
    macro(AuthorAndUserStylesEnabled, authorAndUserStylesEnabled, Bool, bool, DEFAULT_VALUE_FOR_AuthorAndUserStylesEnabled, "", "") \
    macro(WebAudioEnabled, webAudioEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAudioEnabled, "", "") \
    macro(JavaScriptCanAccessClipboard, javaScriptCanAccessClipboard, Bool, bool, DEFAULT_VALUE_FOR_JavaScriptCanAccessClipboard, "", "") \
    macro(WantsBalancedSetDefersLoadingBehavior, wantsBalancedSetDefersLoadingBehavior, Bool, bool, DEFAULT_VALUE_FOR_WantsBalancedSetDefersLoadingBehavior, "", "") \
    macro(VisualViewportEnabled, visualViewportEnabled, Bool, bool, DEFAULT_VALUE_FOR_VisualViewportEnabled, "", "") \
    macro(VisibleDebugOverlayRegions, visibleDebugOverlayRegions, UInt32, uint32_t, DEFAULT_VALUE_FOR_VisibleDebugOverlayRegions, "", "") \
    macro(VideoQualityIncludesDisplayCompositingEnabled, videoQualityIncludesDisplayCompositingEnabled, Bool, bool, DEFAULT_VALUE_FOR_VideoQualityIncludesDisplayCompositingEnabled, "", "") \
    macro(BackspaceKeyNavigationEnabled, backspaceKeyNavigationEnabled, Bool, bool, DEFAULT_VALUE_FOR_BackspaceKeyNavigationEnabled, "", "") \
    macro(MediaContainerTypesAllowedInLockdownMode, mediaContainerTypesAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaContainerTypesAllowedInLockdownMode, "", "") \
    macro(MediaContentTypesRequiringHardwareSupport, mediaContentTypesRequiringHardwareSupport, String, String, DEFAULT_VALUE_FOR_MediaContentTypesRequiringHardwareSupport, "", "") \
    macro(VideoPresentationModeAPIEnabled, videoPresentationModeAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_VideoPresentationModeAPIEnabled, "", "") \
    macro(MediaControlsContextMenusEnabled, mediaControlsContextMenusEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaControlsContextMenusEnabled, "", "") \
    macro(VideoPresentationManagerEnabled, videoPresentationManagerEnabled, Bool, bool, DEFAULT_VALUE_FOR_VideoPresentationManagerEnabled, "", "") \
    macro(MediaControlsScaleWithPageZoom, mediaControlsScaleWithPageZoom, Bool, bool, DEFAULT_VALUE_FOR_MediaControlsScaleWithPageZoom, "", "") \
    macro(VideoFullscreenRequiresElementFullscreen, videoFullscreenRequiresElementFullscreen, Bool, bool, DEFAULT_VALUE_FOR_VideoFullscreenRequiresElementFullscreen, "", "") \
    macro(MediaDataLoadsAutomatically, mediaDataLoadsAutomatically, Bool, bool, DEFAULT_VALUE_FOR_MediaDataLoadsAutomatically, "", "") \
    macro(MediaPreferredFullscreenWidth, mediaPreferredFullscreenWidth, Double, double, DEFAULT_VALUE_FOR_MediaPreferredFullscreenWidth, "", "") \
    macro(MediaPreloadingEnabled, mediaPreloadingEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaPreloadingEnabled, "", "") \
    macro(InvisibleAutoplayNotPermitted, invisibleAutoplayNotPermitted, Bool, bool, DEFAULT_VALUE_FOR_InvisibleAutoplayNotPermitted, "", "") \
    macro(InterruptVideoOnPageVisibilityChangeEnabled, interruptVideoOnPageVisibilityChangeEnabled, Bool, bool, DEFAULT_VALUE_FOR_InterruptVideoOnPageVisibilityChangeEnabled, "", "") \
    macro(InterruptAudioOnPageVisibilityChangeEnabled, interruptAudioOnPageVisibilityChangeEnabled, Bool, bool, DEFAULT_VALUE_FOR_InterruptAudioOnPageVisibilityChangeEnabled, "", "") \
    macro(VP9DecoderEnabled, vp9DecoderEnabled, Bool, bool, DEFAULT_VALUE_FOR_VP9DecoderEnabled, "", "") \
    macro(MediaUserGestureInheritsFromDocument, mediaUserGestureInheritsFromDocument, Bool, bool, DEFAULT_VALUE_FOR_MediaUserGestureInheritsFromDocument, "", "") \
    macro(MediaVideoCodecIDsAllowedInLockdownMode, mediaVideoCodecIDsAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaVideoCodecIDsAllowedInLockdownMode, "", "") \
    macro(InteractionRegionMinimumCornerRadius, interactionRegionMinimumCornerRadius, Double, double, DEFAULT_VALUE_FOR_InteractionRegionMinimumCornerRadius, "", "") \
    macro(InteractionRegionInlinePadding, interactionRegionInlinePadding, Double, double, DEFAULT_VALUE_FOR_InteractionRegionInlinePadding, "", "") \
    macro(InspectorWindowFrame, inspectorWindowFrame, String, String, DEFAULT_VALUE_FOR_InspectorWindowFrame, "", "") \
    macro(InspectorSupportsShowingCertificate, inspectorSupportsShowingCertificate, Bool, bool, DEFAULT_VALUE_FOR_InspectorSupportsShowingCertificate, "", "") \
    macro(InspectorStartsAttached, inspectorStartsAttached, Bool, bool, DEFAULT_VALUE_FOR_InspectorStartsAttached, "", "") \
    macro(InspectorMaximumResourcesContentSize, inspectorMaximumResourcesContentSize, UInt32, uint32_t, DEFAULT_VALUE_FOR_InspectorMaximumResourcesContentSize, "", "") \
    macro(InspectorAttachmentSide, inspectorAttachmentSide, UInt32, uint32_t, DEFAULT_VALUE_FOR_InspectorAttachmentSide, "", "") \
    macro(InspectorAttachedWidth, inspectorAttachedWidth, UInt32, uint32_t, DEFAULT_VALUE_FOR_InspectorAttachedWidth, "", "") \
    macro(InspectorAttachedHeight, inspectorAttachedHeight, UInt32, uint32_t, DEFAULT_VALUE_FOR_InspectorAttachedHeight, "", "") \
    macro(MinimumFontSize, minimumFontSize, Double, double, DEFAULT_VALUE_FOR_MinimumFontSize, "", "") \
    macro(MinimumLogicalFontSize, minimumLogicalFontSize, Double, double, DEFAULT_VALUE_FOR_MinimumLogicalFontSize, "", "") \
    macro(MinimumZoomFontSize, minimumZoomFontSize, Double, double, DEFAULT_VALUE_FOR_MinimumZoomFontSize, "", "") \
    macro(MockCaptureDevicesPromptEnabled, mockCaptureDevicesPromptEnabled, Bool, bool, DEFAULT_VALUE_FOR_MockCaptureDevicesPromptEnabled, "", "") \
    macro(MockScrollbarsControllerEnabled, mockScrollbarsControllerEnabled, Bool, bool, DEFAULT_VALUE_FOR_MockScrollbarsControllerEnabled, "", "") \
    macro(MockScrollbarsEnabled, mockScrollbarsEnabled, Bool, bool, DEFAULT_VALUE_FOR_MockScrollbarsEnabled, "", "") \
    macro(InlineMediaPlaybackRequiresPlaysInlineAttribute, inlineMediaPlaybackRequiresPlaysInlineAttribute, Bool, bool, DEFAULT_VALUE_FOR_InlineMediaPlaybackRequiresPlaysInlineAttribute, "", "") \
    macro(IncrementalRenderingSuppressionTimeout, incrementalRenderingSuppressionTimeout, Double, double, DEFAULT_VALUE_FOR_IncrementalRenderingSuppressionTimeout, "", "") \
    macro(IncrementalPDFLoadingEnabled, incrementalPDFLoadingEnabled, Bool, bool, DEFAULT_VALUE_FOR_IncrementalPDFLoadingEnabled, "", "") \
    macro(IncompleteImageBorderEnabled, incompleteImageBorderEnabled, Bool, bool, DEFAULT_VALUE_FOR_IncompleteImageBorderEnabled, "", "") \
    macro(NeedsAdobeFrameReloadingQuirk, needsAdobeFrameReloadingQuirk, Bool, bool, DEFAULT_VALUE_FOR_NeedsAdobeFrameReloadingQuirk, "", "") \
    macro(InactiveMediaCaptureStreamRepromptIntervalInMinutes, inactiveMediaCaptureStreamRepromptIntervalInMinutes, Double, double, DEFAULT_VALUE_FOR_InactiveMediaCaptureStreamRepromptIntervalInMinutes, "", "") \
    macro(NeedsFrameNameFallbackToIdQuirk, needsFrameNameFallbackToIdQuirk, Bool, bool, DEFAULT_VALUE_FOR_NeedsFrameNameFallbackToIdQuirk, "", "") \
    macro(NeedsKeyboardEventDisambiguationQuirks, needsKeyboardEventDisambiguationQuirks, Bool, bool, DEFAULT_VALUE_FOR_NeedsKeyboardEventDisambiguationQuirks, "", "") \
    macro(PDFPluginEnabled, pdfPluginEnabled, Bool, bool, DEFAULT_VALUE_FOR_PDFPluginEnabled, "", "") \
    macro(PDFPluginHUDEnabled, pdfPluginHUDEnabled, Bool, bool, DEFAULT_VALUE_FOR_PDFPluginHUDEnabled, "", "") \
    macro(PDFPluginPageNumberIndicatorEnabled, pdfPluginPageNumberIndicatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_PDFPluginPageNumberIndicatorEnabled, "", "") \
    macro(PassiveTouchListenersAsDefaultOnDocument, passiveTouchListenersAsDefaultOnDocument, Bool, bool, DEFAULT_VALUE_FOR_PassiveTouchListenersAsDefaultOnDocument, "", "") \
    macro(PasswordEchoDuration, passwordEchoDuration, Double, double, DEFAULT_VALUE_FOR_PasswordEchoDuration, "", "") \
    macro(PasswordEchoEnabled, passwordEchoEnabled, Bool, bool, DEFAULT_VALUE_FOR_PasswordEchoEnabled, "", "") \
    macro(PictographFontFamily, pictographFontFamily, String, String, DEFAULT_VALUE_FOR_PictographFontFamily, "", "") \
    macro(PictureInPictureAPIEnabled, pictureInPictureAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_PictureInPictureAPIEnabled, "", "") \
    macro(PitchCorrectionAlgorithm, pitchCorrectionAlgorithm, UInt32, uint32_t, DEFAULT_VALUE_FOR_PitchCorrectionAlgorithm, "", "") \
    macro(PunchOutWhiteBackgroundsInDarkMode, punchOutWhiteBackgroundsInDarkMode, Bool, bool, DEFAULT_VALUE_FOR_PunchOutWhiteBackgroundsInDarkMode, "", "") \
    macro(RequiresPageVisibilityForVideoToBeNowPlaying, requiresPageVisibilityForVideoToBeNowPlaying, Bool, bool, DEFAULT_VALUE_FOR_RequiresPageVisibilityForVideoToBeNowPlaying, "", "") \
    macro(RequiresPageVisibilityToPlayAudio, requiresPageVisibilityToPlayAudio, Bool, bool, DEFAULT_VALUE_FOR_RequiresPageVisibilityToPlayAudio, "", "") \
    macro(HiddenPageCSSAnimationSuspensionEnabled, hiddenPageCSSAnimationSuspensionEnabled, Bool, bool, DEFAULT_VALUE_FOR_HiddenPageCSSAnimationSuspensionEnabled, "", "") \
    macro(RequiresUserGestureForAudioPlayback, requiresUserGestureForAudioPlayback, Bool, bool, DEFAULT_VALUE_FOR_RequiresUserGestureForAudioPlayback, "", "") \
    macro(RequiresUserGestureForMediaPlayback, requiresUserGestureForMediaPlayback, Bool, bool, DEFAULT_VALUE_FOR_RequiresUserGestureForMediaPlayback, "", "") \
    macro(RequiresUserGestureForVideoPlayback, requiresUserGestureForVideoPlayback, Bool, bool, DEFAULT_VALUE_FOR_RequiresUserGestureForVideoPlayback, "", "") \
    macro(RequiresUserGestureToLoadVideo, requiresUserGestureToLoadVideo, Bool, bool, DEFAULT_VALUE_FOR_RequiresUserGestureToLoadVideo, "", "") \
    macro(UsesSingleWebProcess, usesSingleWebProcess, Bool, bool, DEFAULT_VALUE_FOR_UsesSingleWebProcess, "", "") \
    macro(RubberBandingForSubScrollableRegionsEnabled, rubberBandingForSubScrollableRegionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_RubberBandingForSubScrollableRegionsEnabled, "", "") \
    macro(SampledPageTopColorMaxDifference, sampledPageTopColorMaxDifference, Double, double, DEFAULT_VALUE_FOR_SampledPageTopColorMaxDifference, "", "") \
    macro(SampledPageTopColorMinHeight, sampledPageTopColorMinHeight, Double, double, DEFAULT_VALUE_FOR_SampledPageTopColorMinHeight, "", "") \
    macro(UsesEncodingDetector, usesEncodingDetector, Bool, bool, DEFAULT_VALUE_FOR_UsesEncodingDetector, "", "") \
    macro(SansSerifFontFamily, sansSerifFontFamily, String, String, DEFAULT_VALUE_FOR_SansSerifFontFamily, "", "") \
    macro(SelectTrailingWhitespaceEnabled, selectTrailingWhitespaceEnabled, Bool, bool, DEFAULT_VALUE_FOR_SelectTrailingWhitespaceEnabled, "", "") \
    macro(SerifFontFamily, serifFontFamily, String, String, DEFAULT_VALUE_FOR_SerifFontFamily, "", "") \
    macro(UsesBackForwardCache, usesBackForwardCache, Bool, bool, DEFAULT_VALUE_FOR_UsesBackForwardCache, "", "") \
    macro(UserInterfaceDirectionPolicy, userInterfaceDirectionPolicy, UInt32, uint32_t, DEFAULT_VALUE_FOR_UserInterfaceDirectionPolicy, "", "") \
    macro(CaretBrowsingEnabled, caretBrowsingEnabled, Bool, bool, DEFAULT_VALUE_FOR_CaretBrowsingEnabled, "", "") \
    macro(UseSystemAppearance, useSystemAppearance, Bool, bool, DEFAULT_VALUE_FOR_UseSystemAppearance, "", "") \
    macro(ServiceControlsEnabled, serviceControlsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ServiceControlsEnabled, "", "") \
    macro(GStreamerEnabled, isGStreamerEnabled, Bool, bool, DEFAULT_VALUE_FOR_GStreamerEnabled, "", "") \
    macro(ServiceWorkerEntitlementDisabledForTesting, serviceWorkerEntitlementDisabledForTesting, Bool, bool, DEFAULT_VALUE_FOR_ServiceWorkerEntitlementDisabledForTesting, "", "") \
    macro(ShouldAllowUserInstalledFonts, shouldAllowUserInstalledFonts, Bool, bool, DEFAULT_VALUE_FOR_ShouldAllowUserInstalledFonts, "", "") \
    macro(ColorFilterEnabled, colorFilterEnabled, Bool, bool, DEFAULT_VALUE_FOR_ColorFilterEnabled, "", "") \
    macro(UsePreHTML5ParserQuirks, usePreHTML5ParserQuirks, Bool, bool, DEFAULT_VALUE_FOR_UsePreHTML5ParserQuirks, "", "") \
    macro(ShouldConvertInvalidURLsToBlank, shouldConvertInvalidURLsToBlank, Bool, bool, DEFAULT_VALUE_FOR_ShouldConvertInvalidURLsToBlank, "", "") \
    macro(ShouldConvertPositionStyleOnCopy, shouldConvertPositionStyleOnCopy, Bool, bool, DEFAULT_VALUE_FOR_ShouldConvertPositionStyleOnCopy, "", "") \
    macro(ShouldDecidePolicyBeforeLoadingQuickLookPreview, shouldDecidePolicyBeforeLoadingQuickLookPreview, Bool, bool, DEFAULT_VALUE_FOR_ShouldDecidePolicyBeforeLoadingQuickLookPreview, "", "") \
    macro(ShouldDisplayCaptions, shouldDisplayCaptions, Bool, bool, DEFAULT_VALUE_FOR_ShouldDisplayCaptions, "", "") \
    macro(ContentChangeObserverEnabled, contentChangeObserverEnabled, Bool, bool, DEFAULT_VALUE_FOR_ContentChangeObserverEnabled, "", "") \
    macro(ContentDispositionAttachmentSandboxEnabled, contentDispositionAttachmentSandboxEnabled, Bool, bool, DEFAULT_VALUE_FOR_ContentDispositionAttachmentSandboxEnabled, "", "") \
    macro(ForceWebGLUsesLowPower, forceWebGLUsesLowPower, Bool, bool, DEFAULT_VALUE_FOR_ForceWebGLUsesLowPower, "", "") \
    macro(ContextMenuQRCodeDetectionEnabled, contextMenuQRCodeDetectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_ContextMenuQRCodeDetectionEnabled, "", "") \
    macro(ShouldDisplaySubtitles, shouldDisplaySubtitles, Bool, bool, DEFAULT_VALUE_FOR_ShouldDisplaySubtitles, "", "") \
    macro(ForceFTPDirectoryListings, forceFTPDirectoryListings, Bool, bool, DEFAULT_VALUE_FOR_ForceFTPDirectoryListings, "", "") \
    macro(ForceCompositingMode, forceCompositingMode, Bool, bool, DEFAULT_VALUE_FOR_ForceCompositingMode, "", "") \
    macro(ShouldDisplayTextDescriptions, shouldDisplayTextDescriptions, Bool, bool, DEFAULT_VALUE_FOR_ShouldDisplayTextDescriptions, "", "") \
    macro(ShouldEnableTextAutosizingBoost, shouldEnableTextAutosizingBoost, Bool, bool, DEFAULT_VALUE_FOR_ShouldEnableTextAutosizingBoost, "", "") \
    macro(UseImageDocumentForSubframePDF, useImageDocumentForSubframePDF, Bool, bool, DEFAULT_VALUE_FOR_UseImageDocumentForSubframePDF, "", "") \
    macro(FixedFontFamily, fixedFontFamily, String, String, DEFAULT_VALUE_FOR_FixedFontFamily, "", "") \
    macro(ShouldIgnoreMetaViewport, shouldIgnoreMetaViewport, Bool, bool, DEFAULT_VALUE_FOR_ShouldIgnoreMetaViewport, "", "") \
    macro(ShouldPrintBackgrounds, shouldPrintBackgrounds, Bool, bool, DEFAULT_VALUE_FOR_ShouldPrintBackgrounds, "", "") \
    macro(CursiveFontFamily, cursiveFontFamily, String, String, DEFAULT_VALUE_FOR_CursiveFontFamily, "", "") \
    macro(ShouldRespectImageOrientation, shouldRespectImageOrientation, Bool, bool, DEFAULT_VALUE_FOR_ShouldRespectImageOrientation, "", "") \
    macro(ShouldRestrictBaseURLSchemes, shouldRestrictBaseURLSchemes, Bool, bool, DEFAULT_VALUE_FOR_ShouldRestrictBaseURLSchemes, "", "") \
    macro(ShouldSuppressTextInputFromEditingDuringProvisionalNavigation, shouldSuppressTextInputFromEditingDuringProvisionalNavigation, Bool, bool, DEFAULT_VALUE_FOR_ShouldSuppressTextInputFromEditingDuringProvisionalNavigation, "", "") \
    macro(FantasyFontFamily, fantasyFontFamily, String, String, DEFAULT_VALUE_FOR_FantasyFontFamily, "", "") \
    macro(DOMPasteAllowed, domPasteAllowed, Bool, bool, DEFAULT_VALUE_FOR_DOMPasteAllowed, "", "") \
    macro(ShouldUseServiceWorkerShortTimeout, shouldUseServiceWorkerShortTimeout, Bool, bool, DEFAULT_VALUE_FOR_ShouldUseServiceWorkerShortTimeout, "", "") \
    macro(FTPDirectoryTemplatePath, ftpDirectoryTemplatePath, String, String, DEFAULT_VALUE_FOR_FTPDirectoryTemplatePath, "", "") \
    macro(DataDetectorTypes, dataDetectorTypes, UInt32, uint32_t, DEFAULT_VALUE_FOR_DataDetectorTypes, "", "") \
    macro(ExtensibleSSOEnabled, isExtensibleSSOEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExtensibleSSOEnabled, "", "") \
    macro(TreatsAnyTextCSSLinkAsStylesheet, treatsAnyTextCSSLinkAsStylesheet, Bool, bool, DEFAULT_VALUE_FOR_TreatsAnyTextCSSLinkAsStylesheet, "", "") \
    macro(LinkPreloadEnabled, linkPreloadEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinkPreloadEnabled, "", "") \
    macro(ShowsToolTipOverTruncatedText, showsToolTipOverTruncatedText, Bool, bool, DEFAULT_VALUE_FOR_ShowsToolTipOverTruncatedText, "", "") \
    macro(ThreadedScrollingEnabled, threadedScrollingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ThreadedScrollingEnabled, "", "") \
    macro(DefaultFixedFontSize, defaultFixedFontSize, Double, double, DEFAULT_VALUE_FOR_DefaultFixedFontSize, "", "") \
    macro(DefaultFontSize, defaultFontSize, Double, double, DEFAULT_VALUE_FOR_DefaultFontSize, "", "") \
    macro(DefaultTextEncodingName, defaultTextEncodingName, String, String, DEFAULT_VALUE_FOR_DefaultTextEncodingName, "", "") \
    macro(TextInteractionEnabled, textInteractionEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextInteractionEnabled, "", "") \
    macro(TextExtractionEnabled, textExtractionEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextExtractionEnabled, "", "") \
    macro(TextAutosizingEnabled, textAutosizingEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextAutosizingEnabled, "", "") \
    macro(DeveloperExtrasEnabled, developerExtrasEnabled, Bool, bool, DEFAULT_VALUE_FOR_DeveloperExtrasEnabled, "", "") \
    macro(DeviceHeight, deviceHeight, UInt32, uint32_t, DEFAULT_VALUE_FOR_DeviceHeight, "", "") \
    macro(DeviceOrientationEventEnabled, deviceOrientationEventEnabled, Bool, bool, DEFAULT_VALUE_FOR_DeviceOrientationEventEnabled, "", "") \
    macro(DeviceOrientationPermissionAPIEnabled, deviceOrientationPermissionAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_DeviceOrientationPermissionAPIEnabled, "", "") \
    macro(DeviceWidth, deviceWidth, UInt32, uint32_t, DEFAULT_VALUE_FOR_DeviceWidth, "", "") \
    macro(ShowsURLsInToolTipsEnabled, showsURLsInToolTipsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShowsURLsInToolTipsEnabled, "", "") \
    macro(TextAreasAreResizable, textAreasAreResizable, Bool, bool, DEFAULT_VALUE_FOR_TextAreasAreResizable, "", "") \
    macro(TemporaryTileCohortRetentionEnabled, temporaryTileCohortRetentionEnabled, Bool, bool, DEFAULT_VALUE_FOR_TemporaryTileCohortRetentionEnabled, "", "") \
    macro(TelephoneNumberParsingEnabled, telephoneNumberParsingEnabled, Bool, bool, DEFAULT_VALUE_FOR_TelephoneNumberParsingEnabled, "", "") \
    macro(ShrinksStandaloneImagesToFit, shrinksStandaloneImagesToFit, Bool, bool, DEFAULT_VALUE_FOR_ShrinksStandaloneImagesToFit, "", "") \
    macro(DisabledAdaptationsMetaTagEnabled, disabledAdaptationsMetaTagEnabled, Bool, bool, DEFAULT_VALUE_FOR_DisabledAdaptationsMetaTagEnabled, "", "") \
    macro(DownloadAttributeEnabled, downloadAttributeEnabled, Bool, bool, DEFAULT_VALUE_FOR_DownloadAttributeEnabled, "", "") \
    macro(TabsToLinks, tabsToLinks, Bool, bool, DEFAULT_VALUE_FOR_TabsToLinks, "", "") \
    macro(EditableLinkBehavior, editableLinkBehavior, UInt32, uint32_t, DEFAULT_VALUE_FOR_EditableLinkBehavior, "", "") \
    macro(SystemPreviewEnabled, systemPreviewEnabled, Bool, bool, DEFAULT_VALUE_FOR_SystemPreviewEnabled, "", "") \
    macro(SystemLayoutDirection, systemLayoutDirection, UInt32, uint32_t, DEFAULT_VALUE_FOR_SystemLayoutDirection, "", "") \
    macro(SuppressesIncrementalRendering, suppressesIncrementalRendering, Bool, bool, DEFAULT_VALUE_FOR_SuppressesIncrementalRendering, "", "") \
    macro(StandardFontFamily, standardFontFamily, String, String, DEFAULT_VALUE_FOR_StandardFontFamily, "", "") \
    macro(EnableInheritURIQueryComponent, enableInheritURIQueryComponent, Bool, bool, DEFAULT_VALUE_FOR_EnableInheritURIQueryComponent, "", "") \
    macro(EncryptedMediaAPIEnabled, encryptedMediaAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_EncryptedMediaAPIEnabled, "", "") \
    macro(Standalone, standalone, Bool, bool, DEFAULT_VALUE_FOR_Standalone, "", "") \
    macro(SmartInsertDeleteEnabled, smartInsertDeleteEnabled, Bool, bool, DEFAULT_VALUE_FOR_SmartInsertDeleteEnabled, "", "") \
    macro(SpatialNavigationEnabled, spatialNavigationEnabled, Bool, bool, DEFAULT_VALUE_FOR_SpatialNavigationEnabled, "", "") \
    macro(SourceBufferChangeTypeEnabled, sourceBufferChangeTypeEnabled, Bool, bool, DEFAULT_VALUE_FOR_SourceBufferChangeTypeEnabled, "", "") \
    macro(TargetTextPseudoElementEnabled, targetTextPseudoElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_TargetTextPseudoElementEnabled, "::target-text pseudo-element", "Enable the ::target-text CSS pseudo-element") \
    macro(ThumbAndTrackPseudoElementsEnabled, thumbAndTrackPseudoElementsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ThumbAndTrackPseudoElementsEnabled, "::thumb and ::track pseudo-elements", "Enable support for CSS ::thumb and ::track pseudo-elements") \
    macro(LinkDNSPrefetchEnabled, linkDNSPrefetchEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinkDNSPrefetchEnabled, "<link rel=dns-prefetch>", "Enable <link rel=dns-prefetch>") \
    macro(SelectShowPickerEnabled, selectShowPickerEnabled, Bool, bool, DEFAULT_VALUE_FOR_SelectShowPickerEnabled, "<select> showPicker() method", "Enable showPicker() method on <select>") \
    macro(PageAtRuleMarginDescriptorsEnabled, pageAtRuleMarginDescriptorsEnabled, Bool, bool, DEFAULT_VALUE_FOR_PageAtRuleMarginDescriptorsEnabled, "@page CSS at-rule margin descriptors", "Enable support for @page margin descriptors") \
    macro(AVFoundationEnabled, isAVFoundationEnabled, Bool, bool, DEFAULT_VALUE_FOR_AVFoundationEnabled, "AVFoundation", "Enable AVFoundation") \
    macro(AVKitContentSourceEnabled, isAVKitContentSourceEnabled, Bool, bool, DEFAULT_VALUE_FOR_AVKitContentSourceEnabled, "AVKit Content Source", "Enable AVKit Content Source") \
    macro(AcceleratedFiltersEnabled, acceleratedFiltersEnabled, Bool, bool, DEFAULT_VALUE_FOR_AcceleratedFiltersEnabled, "Accelerated Filter Rendering", "Accelerated CSS and SVG filter rendering") \
    macro(AccessHandleEnabled, accessHandleEnabled, Bool, bool, DEFAULT_VALUE_FOR_AccessHandleEnabled, "AccessHandle API", "Enable AccessHandle API") \
    macro(DOMTestingAPIsEnabled, domTestingAPIsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DOMTestingAPIsEnabled, "Additional Testing APIs for DOM Objects", "Enable additional testing APIs for DOM objects") \
    macro(AllowMediaContentTypesRequiringHardwareSupportAsFallback, allowMediaContentTypesRequiringHardwareSupportAsFallback, Bool, bool, DEFAULT_VALUE_FOR_AllowMediaContentTypesRequiringHardwareSupportAsFallback, "Allow Media Content Types Requirining Hardware As Fallback", "Allow Media Content Types Requirining Hardware As Fallback") \
    macro(AllowPrivacySensitiveOperationsInNonPersistentDataStores, allowPrivacySensitiveOperationsInNonPersistentDataStores, Bool, bool, DEFAULT_VALUE_FOR_AllowPrivacySensitiveOperationsInNonPersistentDataStores, "Allow Privacy-Sensitive Operations in Non-Persistent Data Stores", "Allow Privacy-Sensitive Operations in Non-Persistent Data Stores") \
    macro(AllowViewportShrinkToFitContent, allowViewportShrinkToFitContent, Bool, bool, DEFAULT_VALUE_FOR_AllowViewportShrinkToFitContent, "Allow Viewport Shrink to Fit Content", "Allow the viewport shrink to fit content heuristic when appropriate") \
    macro(AllowWebGLInWorkers, allowWebGLInWorkers, Bool, bool, DEFAULT_VALUE_FOR_AllowWebGLInWorkers, "Allow WebGL in Web Workers", "") \
    macro(PerElementSpeakerSelectionEnabled, perElementSpeakerSelectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_PerElementSpeakerSelectionEnabled, "Allow per media element speaker device selection", "Allow per media element speaker device selection") \
    macro(ExposeSpeakersWithoutMicrophoneEnabled, exposeSpeakersWithoutMicrophoneEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExposeSpeakersWithoutMicrophoneEnabled, "Allow selection of speaker device without related microphone", "Allow selection of speaker device without related microphone") \
    macro(ExposeSpeakersEnabled, exposeSpeakersEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExposeSpeakersEnabled, "Allow speaker device selection", "Allow speaker device selection") \
    macro(AllowTopNavigationToDataURLs, allowTopNavigationToDataURLs, Bool, bool, DEFAULT_VALUE_FOR_AllowTopNavigationToDataURLs, "Allow top navigation to data: URLs", "") \
    macro(AllowUniversalAccessFromFileURLs, allowUniversalAccessFromFileURLs, Bool, bool, DEFAULT_VALUE_FOR_AllowUniversalAccessFromFileURLs, "Allow universal access from file: URLs", "") \
    macro(AlwaysAllowLocalWebarchive, alwaysAllowLocalWebarchive, Bool, bool, DEFAULT_VALUE_FOR_AlwaysAllowLocalWebarchive, "Always allow loading local Web Archive", "Enable always allowing loading local Web Archive") \
    macro(SWVPDecodersAlwaysEnabled, sWVPDecodersAlwaysEnabled, Bool, bool, DEFAULT_VALUE_FOR_SWVPDecodersAlwaysEnabled, "Always enable VPx software decoders", "Always enable VPx software decoders") \
    macro(AppBadgeEnabled, appBadgeEnabled, Bool, bool, DEFAULT_VALUE_FOR_AppBadgeEnabled, "App Badge", "Enable App Badge") \
    macro(AppHighlightsEnabled, appHighlightsEnabled, Bool, bool, DEFAULT_VALUE_FOR_AppHighlightsEnabled, "App Highlights", "Enable App Highlights") \
    macro(AsyncFrameScrollingEnabled, asyncFrameScrollingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AsyncFrameScrollingEnabled, "Async Frame Scrolling", "Perform frame scrolling off the main thread") \
    macro(AsyncOverflowScrollingEnabled, asyncOverflowScrollingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AsyncOverflowScrollingEnabled, "Async Overflow Scrolling", "Perform overflow scrolling off the main thread") \
    macro(UseAsyncUIKitInteractions, useAsyncUIKitInteractions, Bool, bool, DEFAULT_VALUE_FOR_UseAsyncUIKitInteractions, "Async UIKit Interactions", "Use Async UIKit Interactions") \
    macro(AsyncClipboardAPIEnabled, asyncClipboardAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_AsyncClipboardAPIEnabled, "Async clipboard API", "Enable the async clipboard API") \
    macro(AttachmentElementEnabled, attachmentElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_AttachmentElementEnabled, "Attachment Element", "Allow the insertion of attachment elements") \
    macro(AttachmentWideLayoutEnabled, attachmentWideLayoutEnabled, Bool, bool, DEFAULT_VALUE_FOR_AttachmentWideLayoutEnabled, "Attachment wide-layout styling", "Use horizontal wide-layout attachment style, requires Attachment Element") \
    macro(ExtendedAudioDescriptionsEnabled, extendedAudioDescriptionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExtendedAudioDescriptionsEnabled, "Audio descriptions for video - Extended", "Enable extended audio descriptions for video") \
    macro(AudioDescriptionsEnabled, audioDescriptionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_AudioDescriptionsEnabled, "Audio descriptions for video - Standard", "Enable standard audio descriptions for video") \
    macro(DOMAudioSessionEnabled, domAudioSessionEnabled, Bool, bool, DEFAULT_VALUE_FOR_DOMAudioSessionEnabled, "AudioSession API", "Enable AudioSession API") \
    macro(DOMAudioSessionFullEnabled, domAudioSessionFullEnabled, Bool, bool, DEFAULT_VALUE_FOR_DOMAudioSessionFullEnabled, "AudioSession full API", "Enable AudioSession full API") \
    macro(AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth, automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth, Bool, bool, DEFAULT_VALUE_FOR_AutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth, "Automatically Adjust View Scale", "Automatically Adjust View Scale to Fit Min. Effective Device Width") \
    macro(BeaconAPIEnabled, beaconAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_BeaconAPIEnabled, "Beacon API", "Beacon API") \
    macro(BidiContentAwarePasteEnabled, bidiContentAwarePasteEnabled, Bool, bool, DEFAULT_VALUE_FOR_BidiContentAwarePasteEnabled, "Bidi Content Aware Paste", "Bidi content aware paste") \
    macro(BlockFontServiceInWebContentSandbox, blockFontServiceInWebContentSandbox, Bool, bool, DEFAULT_VALUE_FOR_BlockFontServiceInWebContentSandbox, "Block Font service in the WebContent sandbox", "Block Font service in the WebContent sandbox") \
    macro(BlockIconServicesInWebContentSandbox, blockIconServicesInWebContentSandbox, Bool, bool, DEFAULT_VALUE_FOR_BlockIconServicesInWebContentSandbox, "Block Icon services in the WebContent sandbox", "Block Icon services in the WebContent sandbox") \
    macro(BlockMobileAssetInWebContentSandbox, blockMobileAssetInWebContentSandbox, Bool, bool, DEFAULT_VALUE_FOR_BlockMobileAssetInWebContentSandbox, "Block MobileAsset service in the WebContent sandbox", "Block MobileAsset service in the WebContent sandbox") \
    macro(BlockMobileGestaltInWebContentSandbox, blockMobileGestaltInWebContentSandbox, Bool, bool, DEFAULT_VALUE_FOR_BlockMobileGestaltInWebContentSandbox, "Block MobileGestalt service in the WebContent sandbox", "Block MobileGestalt service in the WebContent sandbox") \
    macro(BlockOpenDirectoryInWebContentSandbox, blockOpenDirectoryInWebContentSandbox, Bool, bool, DEFAULT_VALUE_FOR_BlockOpenDirectoryInWebContentSandbox, "Block OpenDirectory service in the WebContent sandbox", "Block OpenDirectory service in the WebContent sandbox") \
    macro(BlockWebInspectorInWebContentSandbox, blockWebInspectorInWebContentSandbox, Bool, bool, DEFAULT_VALUE_FOR_BlockWebInspectorInWebContentSandbox, "Block WebInspector service in the WebContent sandbox", "Block WebInspector service in the WebContent sandbox") \
    macro(BroadcastChannelEnabled, broadcastChannelEnabled, Bool, bool, DEFAULT_VALUE_FOR_BroadcastChannelEnabled, "BroadcastChannel API", "BroadcastChannel API") \
    macro(BuiltInNotificationsEnabled, builtInNotificationsEnabled, Bool, bool, DEFAULT_VALUE_FOR_BuiltInNotificationsEnabled, "Built-In Web Notifications", "Enable built-in WebKit managed notifications") \
    macro(CSS3DTransformBackfaceVisibilityInteroperabilityEnabled, css3DTransformBackfaceVisibilityInteroperabilityEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSS3DTransformBackfaceVisibilityInteroperabilityEnabled, "CSS 3D Transform Interoperability for backface-visibility", "Enable 3D transform behavior for backface-visibility that is specification-compliant but backwards incompatible") \
    macro(CSSCounterStyleAtRuleImageSymbolsEnabled, cssCounterStyleAtRuleImageSymbolsEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSCounterStyleAtRuleImageSymbolsEnabled, "CSS @counter-style <image> symbols", "Enable support for <image> symbols in CSS @counter-style rules") \
    macro(AccentColorEnabled, accentColorEnabled, Bool, bool, DEFAULT_VALUE_FOR_AccentColorEnabled, "CSS Accent Color", "Enable accent-color CSS property") \
    macro(CSSAnchorPositioningEnabled, cssAnchorPositioningEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSAnchorPositioningEnabled, "CSS Anchor Positioning", "Enable CSS Anchor Positioning (except position-visibility)") \
    macro(CSSAnchorPositioningPositionVisibilityEnabled, cssAnchorPositioningPositionVisibilityEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSAnchorPositioningPositionVisibilityEnabled, "CSS Anchor Positioning: position-visibility", "Enable position-visibility specified in CSS Anchor Positioning") \
    macro(DevolvableWidgetsEnabled, devolvableWidgetsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DevolvableWidgetsEnabled, "CSS Devolvable Widgets", "Enable support for devolvable widgets") \
    macro(CSSInputSecurityEnabled, cssInputSecurityEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSInputSecurityEnabled, "CSS Input Security", "Enable input-security CSS property") \
    macro(MasonryEnabled, masonryEnabled, Bool, bool, DEFAULT_VALUE_FOR_MasonryEnabled, "CSS Masonry Layout", "Enable Masonry Layout for CSS Grid") \
    macro(OverscrollBehaviorEnabled, overscrollBehaviorEnabled, Bool, bool, DEFAULT_VALUE_FOR_OverscrollBehaviorEnabled, "CSS Overscroll Behavior", "Enable CSS overscroll-behavior") \
    macro(CSSPaintingAPIEnabled, cssPaintingAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSPaintingAPIEnabled, "CSS Painting API", "Enable the CSS Painting API") \
    macro(CSSRhythmicSizingEnabled, cssRhythmicSizingEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSRhythmicSizingEnabled, "CSS Rhythmic Sizing", "Enable CSS Rhythmic Sizing properties") \
    macro(CSSScrollAnchoringEnabled, cssScrollAnchoringEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSScrollAnchoringEnabled, "CSS Scroll Anchoring", "Enable CSS Scroll Anchoring") \
    macro(SpringTimingFunctionEnabled, springTimingFunctionEnabled, Bool, bool, DEFAULT_VALUE_FOR_SpringTimingFunctionEnabled, "CSS Spring Animations", "CSS Spring Animation prototype") \
    macro(CSSTreeCountingFunctionsEnabled, cssTreeCountingFunctionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTreeCountingFunctionsEnabled, "CSS Tree Counting Functions", "Enable support for CSS Values and Units Module Level 5 tree counting functions sibling-count() and sibling-index()") \
    macro(CSSTypedOMColorEnabled, cssTypedOMColorEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTypedOMColorEnabled, "CSS Typed OM: Color Support", "Enable the CSS Typed OM Color support") \
    macro(CSSURLModifiersEnabled, cssURLModifiersEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSURLModifiersEnabled, "CSS URL Modifiers", "Enable support for CSS Values and Units Module Level 5 URL modifiers") \
    macro(CSSURLIntegrityModifierEnabled, cssURLIntegrityModifierEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSURLIntegrityModifierEnabled, "CSS URL Modifiers: integrity()", "Enable support for CSS Values and Units Module Level 5 URL integrity() modifier") \
    macro(CSSUnprefixedBackdropFilterEnabled, cssUnprefixedBackdropFilterEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSUnprefixedBackdropFilterEnabled, "CSS Unprefixed Backdrop Filter", "Enable unprefixed backdrop-filter CSS property") \
    macro(CSSAppearanceBaseEnabled, cssAppearanceBaseEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSAppearanceBaseEnabled, "CSS appearance: base", "Enable base value for CSS appearance") \
    macro(CSSAxisRelativePositionKeywordsEnabled, cssAxisRelativePositionKeywordsEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSAxisRelativePositionKeywordsEnabled, "CSS axis relative keywords in <position>", "Enable support for CSS Values and Units Module Level 5 axis relative keywords in <position>") \
    macro(CSSBackgroundClipBorderAreaEnabled, cssBackgroundClipBorderAreaEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSBackgroundClipBorderAreaEnabled, "CSS background-clip: border-area", "Enable the border-area value for background-clip") \
    macro(CSSColorLayersEnabled, cssColorLayersEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSColorLayersEnabled, "CSS color-layers()", "Enable support for CSS color-layers()") \
    macro(CSSContrastColorEnabled, cssContrastColorEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSContrastColorEnabled, "CSS contrast-color()", "Enable support for CSS Color Module Level 5 contrast-color()") \
    macro(CSSCornerShapeEnabled, cssCornerShapeEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSCornerShapeEnabled, "CSS corner-shape property", "Enable support for CSS corner-shape property") \
    macro(CSSDPropertyEnabled, cssDPropertyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSDPropertyEnabled, "CSS d property", "Enable support for the CSS d property and SVG d presentation attribute") \
    macro(CSSDynamicRangeLimitMixEnabled, cssDynamicRangeLimitMixEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSDynamicRangeLimitMixEnabled, "CSS dynamic-range-limit-mix()", "Enable support for CSS dynamic-range-limit-mix(), but animation stays unsupported") \
    macro(CSSConstrainedDynamicRangeLimitEnabled, cssConstrainedDynamicRangeLimitEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSConstrainedDynamicRangeLimitEnabled, "CSS dynamic-range-limit: constrained", "Enable support for CSS dynamic-range-limit value constrained") \
    macro(CSSFieldSizingEnabled, cssFieldSizingEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSFieldSizingEnabled, "CSS field-sizing property", "Enable field-sizing CSS property") \
    macro(CSSFontVariantEmojiEnabled, cssFontVariantEmojiEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSFontVariantEmojiEnabled, "CSS font-variant-emoji property", "Enable the font-variant-emoji CSS property") \
    macro(CSSLineClampEnabled, cssLineClampEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSLineClampEnabled, "CSS line-clamp", "Enable CSS line-clamp") \
    macro(CSSLineFitEdgeEnabled, cssLineFitEdgeEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSLineFitEdgeEnabled, "CSS line-fit-edge", "Enable CSS line-fit-edge") \
    macro(CSSProgressFunctionEnabled, cssProgressFunctionEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSProgressFunctionEnabled, "CSS progress()", "Enable support for CSS Values and Units Module Level 5 progress()") \
    macro(CSSRandomFunctionEnabled, cssRandomFunctionEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSRandomFunctionEnabled, "CSS random()", "Enable support for CSS Values and Units Module Level 5 random()") \
    macro(CSSRubyAlignEnabled, cssRubyAlignEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSRubyAlignEnabled, "CSS ruby-align property", "Enable ruby-align") \
    macro(CSSRubyOverhangEnabled, cssRubyOverhangEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSRubyOverhangEnabled, "CSS ruby-overhang property", "Enable ruby-overhang") \
    macro(CSSScrollbarColorEnabled, cssScrollbarColorEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSScrollbarColorEnabled, "CSS scrollbar-color property", "Enable scrollbar-color CSS property") \
    macro(CSSScrollbarGutterEnabled, cssScrollbarGutterEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSScrollbarGutterEnabled, "CSS scrollbar-gutter property", "Enable scrollbar-gutter CSS property") \
    macro(CSSScrollbarWidthEnabled, cssScrollbarWidthEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSScrollbarWidthEnabled, "CSS scrollbar-width property", "Enable scrollbar-width CSS property") \
    macro(CSSShapeFunctionEnabled, cssShapeFunctionEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSShapeFunctionEnabled, "CSS shape() function", "Enable the CSS shape() function") \
    macro(CSSTextAutospaceEnabled, cssTextAutospaceEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextAutospaceEnabled, "CSS text-autospace property", "Enable the property text-autospace, defined in CSS Text 4") \
    macro(CSSTextBoxTrimEnabled, cssTextBoxTrimEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextBoxTrimEnabled, "CSS text-box-trim property", "Enable text-box-trim") \
    macro(CSSTextGroupAlignEnabled, cssTextGroupAlignEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextGroupAlignEnabled, "CSS text-group-align property", "Enable text-group-align CSS property") \
    macro(CSSTextJustifyEnabled, cssTextJustifyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextJustifyEnabled, "CSS text-justify property", "Enable the property text-justify, defined in CSS Text 3") \
    macro(CSSTextSpacingTrimEnabled, cssTextSpacingTrimEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextSpacingTrimEnabled, "CSS text-spacing-trim property", "Enable the property text-spacing-trim, defined in CSS Text 4") \
    macro(CSSTextUnderlinePositionLeftRightEnabled, cssTextUnderlinePositionLeftRightEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextUnderlinePositionLeftRightEnabled, "CSS text-underline-position: left right", "Enable the property text-underline-position left and right value support") \
    macro(CSSTextWrapPrettyEnabled, cssTextWrapPrettyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextWrapPrettyEnabled, "CSS text-wrap: pretty", "Enable the pretty value for text-wrap-style") \
    macro(CSSTransformStyleSeparatedEnabled, cssTransformStyleSeparatedEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTransformStyleSeparatedEnabled, "CSS transform-style: separated", "Enable transform-style: separated property to access the separated graphics layer") \
    macro(CacheAPIEnabled, cacheAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_CacheAPIEnabled, "Cache API", "Cache API") \
    macro(CanvasColorSpaceEnabled, canvasColorSpaceEnabled, Bool, bool, DEFAULT_VALUE_FOR_CanvasColorSpaceEnabled, "Canvas Color Spaces", "Enable use of predefined canvas color spaces") \
    macro(CanvasFiltersEnabled, canvasFiltersEnabled, Bool, bool, DEFAULT_VALUE_FOR_CanvasFiltersEnabled, "Canvas Filters", "Canvas Filters") \
    macro(CanvasLayersEnabled, canvasLayersEnabled, Bool, bool, DEFAULT_VALUE_FOR_CanvasLayersEnabled, "Canvas Layers", "Enable Canvas Layers") \
    macro(CanvasUsesAcceleratedDrawing, canvasUsesAcceleratedDrawing, Bool, bool, DEFAULT_VALUE_FOR_CanvasUsesAcceleratedDrawing, "Canvas uses accelerated drawing", "") \
    macro(CanvasPixelFormatEnabled, canvasPixelFormatEnabled, Bool, bool, DEFAULT_VALUE_FOR_CanvasPixelFormatEnabled, "CanvasRenderingContext2DSettings.pixelFormat", "Allow different pixel formats in 2D canvas") \
    macro(ChildProcessDebuggabilityEnabled, childProcessDebuggabilityEnabled, Bool, bool, DEFAULT_VALUE_FOR_ChildProcessDebuggabilityEnabled, "Child Process Debuggability", "Enable stopping child processes with a debugger") \
    macro(ClearSiteDataHTTPHeaderEnabled, clearSiteDataHTTPHeaderEnabled, Bool, bool, DEFAULT_VALUE_FOR_ClearSiteDataHTTPHeaderEnabled, "Clear-Site-Data HTTP Header", "Enable Clear-Site-Data HTTP Header support") \
    macro(ClearSiteDataExecutionContextsSupportEnabled, clearSiteDataExecutionContextsSupportEnabled, Bool, bool, DEFAULT_VALUE_FOR_ClearSiteDataExecutionContextsSupportEnabled, "Clear-Site-Data: 'executionContexts' support", "Enable Clear-Site-Data: 'executionContexts' support") \
    macro(CloseWatcherEnabled, closeWatcherEnabled, Bool, bool, DEFAULT_VALUE_FOR_CloseWatcherEnabled, "Close Watcher API", "Enable Close Watcher API") \
    macro(InputTypeColorEnabled, inputTypeColorEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeColorEnabled, "Color Inputs", "Enable input elements of type color") \
    macro(CompositingBordersVisible, compositingBordersVisible, Bool, bool, DEFAULT_VALUE_FOR_CompositingBordersVisible, "Compositing borders visible", "") \
    macro(CompositingRepaintCountersVisible, compositingRepaintCountersVisible, Bool, bool, DEFAULT_VALUE_FOR_CompositingRepaintCountersVisible, "Compositing repaint counters visible", "") \
    macro(CompressionStreamEnabled, compressionStreamEnabled, Bool, bool, DEFAULT_VALUE_FOR_CompressionStreamEnabled, "Compression Stream API", "Enable Compression Stream API") \
    macro(ContactPickerAPIEnabled, contactPickerAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_ContactPickerAPIEnabled, "Contact Picker API", "Enable the Contact Picker API") \
    macro(ContentInsetBackgroundFillEnabled, contentInsetBackgroundFillEnabled, Bool, bool, DEFAULT_VALUE_FOR_ContentInsetBackgroundFillEnabled, "Content Inset Background Fill", "Fill content insets with background colors") \
    macro(CookieConsentAPIEnabled, cookieConsentAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_CookieConsentAPIEnabled, "Cookie Consent API", "Enable cookie consent API") \
    macro(CookieStoreManagerEnabled, cookieStoreManagerEnabled, Bool, bool, DEFAULT_VALUE_FOR_CookieStoreManagerEnabled, "Cookie Store API CookieStoreManager", "Enable Cookie Store API CookieStoreManager which controls cookie change subscriptions for Service Workers") \
    macro(CookieStoreAPIExtendedAttributesEnabled, cookieStoreAPIExtendedAttributesEnabled, Bool, bool, DEFAULT_VALUE_FOR_CookieStoreAPIExtendedAttributesEnabled, "Cookie Store API Extended Attributes", "Enable Extended Attributes of the Cookie Store API") \
    macro(CookieStoreAPIEnabled, cookieStoreAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_CookieStoreAPIEnabled, "Cookie Store API", "Enable Cookie Store API") \
    macro(CookieEnabled, cookieEnabled, Bool, bool, DEFAULT_VALUE_FOR_CookieEnabled, "Cookies Enabled", "") \
    macro(InputMethodUsesCorrectKeyEventOrder, inputMethodUsesCorrectKeyEventOrder, Bool, bool, DEFAULT_VALUE_FOR_InputMethodUsesCorrectKeyEventOrder, "Correct key event ordering with composition events", "") \
    macro(CrossDocumentViewTransitionsEnabled, crossDocumentViewTransitionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_CrossDocumentViewTransitionsEnabled, "Cross document view-transitions", "Enable support for view-transitions cross-document") \
    macro(CrossOriginEmbedderPolicyEnabled, crossOriginEmbedderPolicyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CrossOriginEmbedderPolicyEnabled, "Cross-Origin-Embedder-Policy (COEP) header", "Support for Cross-Origin-Embedder-Policy (COEP) header") \
    macro(CrossOriginOpenerPolicyEnabled, crossOriginOpenerPolicyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CrossOriginOpenerPolicyEnabled, "Cross-Origin-Opener-Policy (COOP) header", "Support for Cross-Origin-Opener-Policy (COOP) header") \
    macro(CustomPasteboardDataEnabled, customPasteboardDataEnabled, Bool, bool, DEFAULT_VALUE_FOR_CustomPasteboardDataEnabled, "Custom pasteboard data", "Enable custom clipboard types and better security model for clipboard API.") \
    macro(DOMPasteAccessRequestsEnabled, domPasteAccessRequestsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DOMPasteAccessRequestsEnabled, "DOM Paste Access Requests", "Enable DOM Paste Access Requests") \
    macro(MutationEventsEnabled, mutationEventsEnabled, Bool, bool, DEFAULT_VALUE_FOR_MutationEventsEnabled, "DOM mutation events", "") \
    macro(DOMTimersThrottlingEnabled, domTimersThrottlingEnabled, Bool, bool, DEFAULT_VALUE_FOR_DOMTimersThrottlingEnabled, "DOM timer throttling enabled", "") \
    macro(ZoomOnDoubleTapWhenRoot, zoomOnDoubleTapWhenRoot, Bool, bool, DEFAULT_VALUE_FOR_ZoomOnDoubleTapWhenRoot, "DTTZ also when root", "Double taps zoom, even if we dispatched a click on the root nodes") \
    macro(AlwaysZoomOnDoubleTap, alwaysZoomOnDoubleTap, Bool, bool, DEFAULT_VALUE_FOR_AlwaysZoomOnDoubleTap, "DTTZ always", "Double taps zoom, even if we dispatched a click anywhere") \
    macro(DataTransferItemsEnabled, dataTransferItemsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DataTransferItemsEnabled, "Data Transfer Items", "Enables DataTransferItem in the clipboard API") \
    macro(DataListElementEnabled, dataListElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_DataListElementEnabled, "DataList Element", "Enable datalist elements") \
    macro(InputTypeDateEnabled, inputTypeDateEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeDateEnabled, "Date Input", "Enable input elements of type date") \
    macro(DateTimeInputsEditableComponentsEnabled, dateTimeInputsEditableComponentsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DateTimeInputsEditableComponentsEnabled, "Date/Time inputs have editable components", "Enable multiple editable components in date/time inputs") \
    macro(DeclarativeWebPush, declarativeWebPush, Bool, bool, DEFAULT_VALUE_FOR_DeclarativeWebPush, "Declarative Web Push", "Enable Declarative Web Push") \
    macro(ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint, shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint, Bool, bool, DEFAULT_VALUE_FOR_ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint, "Defer async scripts until DOMContentLoaded or first-paint", "Defer async scripts until DOMContentLoaded or first-paint") \
    macro(DeprecationReportingEnabled, deprecationReportingEnabled, Bool, bool, DEFAULT_VALUE_FOR_DeprecationReportingEnabled, "Deprecation Reporting", "Enable Deprecation Reporting") \
    macro(DetachableMediaSourceEnabled, detachableMediaSourceEnabled, Bool, bool, DEFAULT_VALUE_FOR_DetachableMediaSourceEnabled, "Detachable Media Source", "Detachable Media Source API") \
    macro(UAVisualTransitionDetectionEnabled, uAVisualTransitionDetectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_UAVisualTransitionDetectionEnabled, "Detect UA visual transitions", "Enable detection of UA visual transitions") \
    macro(DiagnosticLoggingEnabled, diagnosticLoggingEnabled, Bool, bool, DEFAULT_VALUE_FOR_DiagnosticLoggingEnabled, "Diagnostic logging enabled", "") \
    macro(DigitalCredentialsEnabled, digitalCredentialsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DigitalCredentialsEnabled, "Digital Credentials API", "Enable the Digital Credentials API") \
    macro(DirectoryUploadEnabled, directoryUploadEnabled, Bool, bool, DEFAULT_VALUE_FOR_DirectoryUploadEnabled, "Directory Upload", "input.webkitdirectory / dataTransferItem.webkitGetAsEntry()") \
    macro(IsThirdPartyCookieBlockingDisabled, isThirdPartyCookieBlockingDisabled, Bool, bool, DEFAULT_VALUE_FOR_IsThirdPartyCookieBlockingDisabled, "Disable Full 3rd-Party Cookie Blocking (ITP)", "Disable full third-party cookie blocking when Intelligent Tracking Prevention is enabled") \
    macro(IsFirstPartyWebsiteDataRemovalDisabled, isFirstPartyWebsiteDataRemovalDisabled, Bool, bool, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalDisabled, "Disable Removal of Non-Cookie Data After 7 Days of No User Interaction (ITP)", "Disable removal of all non-cookie website data after seven days of no user interaction when Intelligent Tracking Prevention is enabled") \
    macro(DisableScreenSizeOverride, disableScreenSizeOverride, Bool, bool, DEFAULT_VALUE_FOR_DisableScreenSizeOverride, "Disable screen size override", "") \
    macro(ShouldDropNearSuspendedAssertionAfterDelay, shouldDropNearSuspendedAssertionAfterDelay, Bool, bool, DEFAULT_VALUE_FOR_ShouldDropNearSuspendedAssertionAfterDelay, "Drop Near-Suspended Assertion After Delay", "Causes processes to fully suspend after a delay") \
    macro(UseCGDisplayListsForDOMRendering, useCGDisplayListsForDOMRendering, Bool, bool, DEFAULT_VALUE_FOR_UseCGDisplayListsForDOMRendering, "Dynamic Content Scaling: DOM Rendering", "Use Dynamic Content Scaling for DOM rendering") \
    macro(ReplayCGDisplayListsIntoBackingStore, replayCGDisplayListsIntoBackingStore, Bool, bool, DEFAULT_VALUE_FOR_ReplayCGDisplayListsIntoBackingStore, "Dynamic Content Scaling: Replay for Testing", "Replay Dynamic Content Scaling Display Lists into layer contents for testing") \
    macro(DynamicSiteInterventionsEnabled, dynamicSiteInterventionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DynamicSiteInterventionsEnabled, "Dynamic Site Interventions", "Enable dynamic site interventions for broken websites") \
    macro(EmbedElementEnabled, embedElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_EmbedElementEnabled, "Embed Element", "Embed Element") \
    macro(EnableAccessibilityOnDemand, enableAccessibilityOnDemand, Bool, bool, DEFAULT_VALUE_FOR_EnableAccessibilityOnDemand, "Enable Accessibility On Demand", "Enable Accessibility On Demand") \
    macro(AutomaticLiveResizeEnabled, automaticLiveResizeEnabled, Bool, bool, DEFAULT_VALUE_FOR_AutomaticLiveResizeEnabled, "Enable Automatic Live Resize", "Automatically synchronize web view resize with painting") \
    macro(CanvasFingerprintingQuirkEnabled, canvasFingerprintingQuirkEnabled, Bool, bool, DEFAULT_VALUE_FOR_CanvasFingerprintingQuirkEnabled, "Enable Canvas fingerprinting-related quirk", "") \
    macro(EnableElementCurrentCSSZoom, enableElementCurrentCSSZoom, Bool, bool, DEFAULT_VALUE_FOR_EnableElementCurrentCSSZoom, "Enable Element.currentCSSZoom", "Enable Element.currentCSSZoom") \
    macro(EnumeratingAllNetworkInterfacesEnabled, enumeratingAllNetworkInterfacesEnabled, Bool, bool, DEFAULT_VALUE_FOR_EnumeratingAllNetworkInterfacesEnabled, "Enable Enumerating All Network Interfaces", "") \
    macro(EnumeratingVisibleNetworkInterfacesEnabled, enumeratingVisibleNetworkInterfacesEnabled, Bool, bool, DEFAULT_VALUE_FOR_EnumeratingVisibleNetworkInterfacesEnabled, "Enable Enumerating Visible Network Interfaces", "") \
    macro(ICECandidateFilteringEnabled, iceCandidateFilteringEnabled, Bool, bool, DEFAULT_VALUE_FOR_ICECandidateFilteringEnabled, "Enable ICE Candidate Filtering", "Enable ICE Candidate Filtering") \
    macro(LegacyEncryptedMediaAPIEnabled, legacyEncryptedMediaAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_LegacyEncryptedMediaAPIEnabled, "Enable Legacy EME API", "Enable legacy EME API") \
    macro(MockCaptureDevicesEnabled, mockCaptureDevicesEnabled, Bool, bool, DEFAULT_VALUE_FOR_MockCaptureDevicesEnabled, "Enable Mock Capture Devices", "Enable Mock Capture Devices") \
    macro(ModelProcessEnabled, modelProcessEnabled, Bool, bool, DEFAULT_VALUE_FOR_ModelProcessEnabled, "Enable Model Process", "Load <model> content in a separate process") \
    macro(PDFJSViewerEnabled, pdfJSViewerEnabled, Bool, bool, DEFAULT_VALUE_FOR_PDFJSViewerEnabled, "Enable PDF.js viewer", "Enable PDF.js viewer") \
    macro(AuxclickEventEnabled, auxclickEventEnabled, Bool, bool, DEFAULT_VALUE_FOR_AuxclickEventEnabled, "Enable `auxclick` event", "Enable the `auxclick` UI event") \
    macro(BackgroundWebContentRunningBoardThrottlingEnabled, backgroundWebContentRunningBoardThrottlingEnabled, Bool, bool, DEFAULT_VALUE_FOR_BackgroundWebContentRunningBoardThrottlingEnabled, "Enable background web content throttling via RunningBoard", "Enable background web content throttling via RunningBoard") \
    macro(BackgroundFetchAPIEnabled, backgroundFetchAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_BackgroundFetchAPIEnabled, "Enable background-fetch API", "Enable background-fetch API") \
    macro(EnableDebuggingFeaturesInSandbox, enableDebuggingFeaturesInSandbox, Bool, bool, DEFAULT_VALUE_FOR_EnableDebuggingFeaturesInSandbox, "Enable debugging features in sandbox", "Enable debugging features in sandbox") \
    macro(CFNetworkNetworkLoaderEnabled, cFNetworkNetworkLoaderEnabled, Bool, bool, DEFAULT_VALUE_FOR_CFNetworkNetworkLoaderEnabled, "Enable experimental network loader", "Enable experimental network loader") \
    macro(ExperimentalSandboxEnabled, experimentalSandboxEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExperimentalSandboxEnabled, "Enable experimental sandbox features", "Enable experimental sandbox features") \
    macro(NavigatorUserAgentDataJavaScriptAPIEnabled, navigatorUserAgentDataJavaScriptAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_NavigatorUserAgentDataJavaScriptAPIEnabled, "Enable the navigator.userAgentData JavaScript API", "") \
    macro(BlobFileAccessEnforcementEnabled, blobFileAccessEnforcementEnabled, Bool, bool, DEFAULT_VALUE_FOR_BlobFileAccessEnforcementEnabled, "Enforce blob backed file access valid for web process", "Validate file backed blobs were created by the correct web process") \
    macro(EnterKeyHintEnabled, enterKeyHintEnabled, Bool, bool, DEFAULT_VALUE_FOR_EnterKeyHintEnabled, "Enter Key Hint", "Enable the enterKeyHint HTML attribute") \
    macro(EventTimingEnabled, eventTimingEnabled, Bool, bool, DEFAULT_VALUE_FOR_EventTimingEnabled, "Event Timing API", "Enable the Event Timing API and supporting instrumentation") \
    macro(EventHandlerDrivenSmoothKeyboardScrollingEnabled, eventHandlerDrivenSmoothKeyboardScrollingEnabled, Bool, bool, DEFAULT_VALUE_FOR_EventHandlerDrivenSmoothKeyboardScrollingEnabled, "EventHandler driven smooth keyboard scrolling", "Enable EventHandler driven smooth keyboard scrolling") \
    macro(MediaSessionCoordinatorEnabled, mediaSessionCoordinatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSessionCoordinatorEnabled, "Experimental MediaSession coordinator API", "Enable experimental MediaSession coordinator API") \
    macro(MediaSessionPlaylistEnabled, mediaSessionPlaylistEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSessionPlaylistEnabled, "Experimental MediaSession playlist API", "Enable experimental MediaSession playlist API") \
    macro(ExposeCaptureDevicesAfterCaptureEnabled, exposeCaptureDevicesAfterCaptureEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExposeCaptureDevicesAfterCaptureEnabled, "Expose all capture devices when one is used", "Expose all capture devices when one is used") \
    macro(ExposeDefaultSpeakerAsSpecificDeviceEnabled, exposeDefaultSpeakerAsSpecificDeviceEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExposeDefaultSpeakerAsSpecificDeviceEnabled, "Expose the system default speaker as a specific device", "Expose the system default speaker as a specific device") \
    macro(FTPEnabled, ftpEnabled, Bool, bool, DEFAULT_VALUE_FOR_FTPEnabled, "FTP support enabled", "FTP support enabled") \
    macro(PreferFasterClickOverDoubleTap, preferFasterClickOverDoubleTap, Bool, bool, DEFAULT_VALUE_FOR_PreferFasterClickOverDoubleTap, "Fast clicks beat DTTZ", "Prefer a faster click over a double tap") \
    macro(FasterClicksEnabled, fasterClicksEnabled, Bool, bool, DEFAULT_VALUE_FOR_FasterClicksEnabled, "Fast clicks", "Support faster clicks on zoomable pages") \
    macro(FileSystemEnabled, fileSystemEnabled, Bool, bool, DEFAULT_VALUE_FOR_FileSystemEnabled, "File System API", "Enable File System API") \
    macro(FileSystemWritableStreamEnabled, fileSystemWritableStreamEnabled, Bool, bool, DEFAULT_VALUE_FOR_FileSystemWritableStreamEnabled, "File System WritableStream", "Enable File System WritableStream API") \
    macro(FileReaderAPIEnabled, fileReaderAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_FileReaderAPIEnabled, "FileReader API", "FileReader API") \
    macro(FilterLinkDecorationByDefaultEnabled, filterLinkDecorationByDefaultEnabled, Bool, bool, DEFAULT_VALUE_FOR_FilterLinkDecorationByDefaultEnabled, "Filter Link Decoration", "Enable Filtering Link Decoration") \
    macro(ForceLockdownFontParserEnabled, forceLockdownFontParserEnabled, Bool, bool, DEFAULT_VALUE_FOR_ForceLockdownFontParserEnabled, "Force Lockdown Mode Safe Font Parser", "Forcing the Lockdown Mode Safe Font Parser independently from Lockdown Mode state") \
    macro(ForceAlwaysUserScalable, forceAlwaysUserScalable, Bool, bool, DEFAULT_VALUE_FOR_ForceAlwaysUserScalable, "Force always user-scalable", "") \
    macro(FormControlRefreshEnabled, formControlRefreshEnabled, Bool, bool, DEFAULT_VALUE_FOR_FormControlRefreshEnabled, "Form control refresh for Cocoa platforms", "Enable form control refresh for Cocoa platforms") \
    macro(IFrameResourceMonitoringTestingSettingsEnabled, iFrameResourceMonitoringTestingSettingsEnabled, Bool, bool, DEFAULT_VALUE_FOR_IFrameResourceMonitoringTestingSettingsEnabled, "Frame Resource Monitoring Settings For Testing", "Use Resource Monitoring Settings for testing") \
    macro(IFrameResourceMonitoringEnabled, iFrameResourceMonitoringEnabled, Bool, bool, DEFAULT_VALUE_FOR_IFrameResourceMonitoringEnabled, "Frame Resource Monitoring Support", "Enable Usage Monitoring of Frame Resource Support") \
    macro(FullScreenKeyboardLock, fullScreenKeyboardLock, Bool, bool, DEFAULT_VALUE_FOR_FullScreenKeyboardLock, "Fullscreen API based Keyboard Lock", "Fullscreen API based Keyboard Lock") \
    macro(FullScreenEnabled, fullScreenEnabled, Bool, bool, DEFAULT_VALUE_FOR_FullScreenEnabled, "Fullscreen API", "Fullscreen API") \
    macro(FullscreenSceneAspectRatioLockingEnabled, fullscreenSceneAspectRatioLockingEnabled, Bool, bool, DEFAULT_VALUE_FOR_FullscreenSceneAspectRatioLockingEnabled, "Fullscreen scene aspect ratio locking", "Enable scene aspect ratio locking in Fullscreen") \
    macro(FullscreenSceneDimmingEnabled, fullscreenSceneDimmingEnabled, Bool, bool, DEFAULT_VALUE_FOR_FullscreenSceneDimmingEnabled, "Fullscreen scene dimming", "Enable scene dimming in Fullscreen") \
    macro(CaptureAudioInGPUProcessEnabled, captureAudioInGPUProcessEnabled, Bool, bool, DEFAULT_VALUE_FOR_CaptureAudioInGPUProcessEnabled, "GPU Process: Audio Capture", "Enable audio capture in GPU Process") \
    macro(BlockMediaLayerRehostingInWebContentProcess, blockMediaLayerRehostingInWebContentProcess, Bool, bool, DEFAULT_VALUE_FOR_BlockMediaLayerRehostingInWebContentProcess, "GPU Process: Block Media Layer Re-hosting", "GPU Process: Block Media Layer Re-hosting in WebContent process") \
    macro(UseGPUProcessForCanvasRenderingEnabled, useGPUProcessForCanvasRenderingEnabled, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForCanvasRenderingEnabled, "GPU Process: Canvas Rendering", "Enable canvas rendering in GPU Process") \
    macro(ManageCaptureStatusBarInGPUProcessEnabled, manageCaptureStatusBarInGPUProcessEnabled, Bool, bool, DEFAULT_VALUE_FOR_ManageCaptureStatusBarInGPUProcessEnabled, "GPU Process: Capture Status Bar management", "Enable Capture Status Bar management in GPU Process") \
    macro(UseGPUProcessForDOMRenderingEnabled, useGPUProcessForDOMRenderingEnabled, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForDOMRenderingEnabled, "GPU Process: DOM Rendering", "Enable DOM rendering in GPU Process") \
    macro(UseGPUProcessForMediaEnabled, useGPUProcessForMediaEnabled, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForMediaEnabled, "GPU Process: Media", "Do all media loading and playback in the GPU Process") \
    macro(UseGPUProcessForDisplayCapture, useGPUProcessForDisplayCapture, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForDisplayCapture, "GPU Process: Screen and Window capture", "Display capture in GPU Process") \
    macro(CaptureVideoInGPUProcessEnabled, captureVideoInGPUProcessEnabled, Bool, bool, DEFAULT_VALUE_FOR_CaptureVideoInGPUProcessEnabled, "GPU Process: Video Capture", "Enable video capture in GPU Process") \
    macro(UseGPUProcessForWebGLEnabled, useGPUProcessForWebGLEnabled, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForWebGLEnabled, "GPU Process: WebGL", "Process all WebGL operations in GPU Process") \
    macro(WebRTCPlatformCodecsInGPUProcessEnabled, webRTCPlatformCodecsInGPUProcessEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCPlatformCodecsInGPUProcessEnabled, "GPU Process: WebRTC Platform Codecs", "Enable WebRTC Platform Codecs in GPU Process") \
    macro(GamepadTriggerRumbleEnabled, gamepadTriggerRumbleEnabled, Bool, bool, DEFAULT_VALUE_FOR_GamepadTriggerRumbleEnabled, "Gamepad trigger vibration support", "Support for Gamepad trigger vibration") \
    macro(GamepadVibrationActuatorEnabled, gamepadVibrationActuatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_GamepadVibrationActuatorEnabled, "Gamepad.vibrationActuator support", "Support for Gamepad.vibrationActuator") \
    macro(GamepadsEnabled, gamepadsEnabled, Bool, bool, DEFAULT_VALUE_FOR_GamepadsEnabled, "Gamepads", "Web Gamepad API support") \
    macro(GenericCueAPIEnabled, genericCueAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_GenericCueAPIEnabled, "Generic Text Track Cue API", "Enable Generic Text Track Cue API") \
    macro(GeolocationAPIEnabled, geolocationAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_GeolocationAPIEnabled, "Geolocation API", "Enable Geolocation API") \
    macro(GraphicsContextFiltersEnabled, graphicsContextFiltersEnabled, Bool, bool, DEFAULT_VALUE_FOR_GraphicsContextFiltersEnabled, "GraphicsContext Filter Rendering", "GraphicsContext Filter Rendering") \
    macro(AcceleratedDrawingEnabled, acceleratedDrawingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AcceleratedDrawingEnabled, "GraphicsLayer accelerated drawing", "Enable GraphicsLayer accelerated drawing") \
    macro(ModelElementEnabled, modelElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_ModelElementEnabled, "HTML <model> element", "Enable HTML <model> element") \
    macro(ModelDocumentEnabled, modelDocumentEnabled, Bool, bool, DEFAULT_VALUE_FOR_ModelDocumentEnabled, "HTML <model> elements for stand-alone document", "Enable HTML <model> element for model documents") \
    macro(InteractiveFormValidationEnabled, interactiveFormValidationEnabled, Bool, bool, DEFAULT_VALUE_FOR_InteractiveFormValidationEnabled, "HTML Interactive Form Validation", "HTML interactive form validation") \
    macro(MediaEnabled, mediaEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaEnabled, "HTML Media Elements", "Enable HTML media elements <audio>, <video> and <track>") \
    macro(InputTypeColorEnhancementsEnabled, inputTypeColorEnhancementsEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeColorEnhancementsEnabled, "HTML alpha and colorspace attribute support for color inputs", "Enable HTML alpha and colorspace attribute support for input elements of type color") \
    macro(DetailsAutoExpandEnabled, detailsAutoExpandEnabled, Bool, bool, DEFAULT_VALUE_FOR_DetailsAutoExpandEnabled, "HTML auto-expanding <details>", "Enable HTML auto-expanding <details>") \
    macro(CommandAttributesEnabled, commandAttributesEnabled, Bool, bool, DEFAULT_VALUE_FOR_CommandAttributesEnabled, "HTML command & commandfor attributes", "Enable HTML command & commandfor attribute support") \
    macro(HTMLLegacyAttributeValueSerializationEnabled, hTMLLegacyAttributeValueSerializationEnabled, Bool, bool, DEFAULT_VALUE_FOR_HTMLLegacyAttributeValueSerializationEnabled, "HTML legacy attribute value serialization", "Enable HTML legacy attribute value serialization") \
    macro(PopoverAttributeEnabled, popoverAttributeEnabled, Bool, bool, DEFAULT_VALUE_FOR_PopoverAttributeEnabled, "HTML popover attribute", "Enable HTML popover attribute support") \
    macro(SwitchControlEnabled, switchControlEnabled, Bool, bool, DEFAULT_VALUE_FOR_SwitchControlEnabled, "HTML switch control", "Enable HTML switch control") \
    macro(HTTPSByDefaultEnabled, httpSByDefaultEnabled, Bool, bool, DEFAULT_VALUE_FOR_HTTPSByDefaultEnabled, "HTTPS-by-default (HTTPS-First)", "Enable HTTPS-by-default (HTTPS-First)") \
    macro(HiddenPageDOMTimerThrottlingAutoIncreases, hiddenPageDOMTimerThrottlingAutoIncreases, Bool, bool, DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingAutoIncreases, "Hidden page DOM timer throttling auto-increases", "") \
    macro(HiddenPageDOMTimerThrottlingEnabled, hiddenPageDOMTimerThrottlingEnabled, Bool, bool, DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingEnabled, "Hidden page DOM timer throttling", "Enable hidden page DOM timer throttling") \
    macro(HostedBlurMaterialInMediaControlsEnabled, hostedBlurMaterialInMediaControlsEnabled, Bool, bool, DEFAULT_VALUE_FOR_HostedBlurMaterialInMediaControlsEnabled, "Hosted blur material in media controls", "Enable hosted blur material in media controls") \
    macro(BlockIOKitInWebContentSandbox, blockIOKitInWebContentSandbox, Bool, bool, DEFAULT_VALUE_FOR_BlockIOKitInWebContentSandbox, "IOKit blocking in the WebContent sandbox", "Block IOKit access in the WebContent sandbox") \
    macro(IOSurfaceLosslessCompressionEnabled, iOSurfaceLosslessCompressionEnabled, Bool, bool, DEFAULT_VALUE_FOR_IOSurfaceLosslessCompressionEnabled, "IOSurface Lossless Compression", "Use losslessly compressed IOSurfaces") \
    macro(IPCTestingAPIEnabled, ipcTestingAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_IPCTestingAPIEnabled, "IPC Testing API", "Enable IPC Testing API for JavaScript") \
    macro(ItpDebugModeEnabled, itpDebugModeEnabled, Bool, bool, DEFAULT_VALUE_FOR_ItpDebugModeEnabled, "ITP Debug Mode", "Intelligent Tracking Prevention Debug Mode") \
    macro(TextAutosizingUsesIdempotentMode, textAutosizingUsesIdempotentMode, Bool, bool, DEFAULT_VALUE_FOR_TextAutosizingUsesIdempotentMode, "Idempotent Text Autosizing", "Use idempotent text autosizing mode") \
    macro(IgnoreInvalidMessageWhenIPCTestingAPIEnabled, ignoreInvalidMessageWhenIPCTestingAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_IgnoreInvalidMessageWhenIPCTestingAPIEnabled, "Ignore Invalid IPC Messages For Testing", "Prevents invalid IPC messages from terminating the caller") \
    macro(IgnoreIframeEmbeddingProtectionsEnabled, ignoreIframeEmbeddingProtectionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_IgnoreIframeEmbeddingProtectionsEnabled, "Ignore iframe Embedding Protections", "Ignores X-Frame-Options and CSP ancestors") \
    macro(ImageAnalysisDuringFindInPageEnabled, imageAnalysisDuringFindInPageEnabled, Bool, bool, DEFAULT_VALUE_FOR_ImageAnalysisDuringFindInPageEnabled, "Image Analysis for Find-in-Page", "Trigger image analysis when performing Find-in-Page") \
    macro(ImageAnimationControlEnabled, imageAnimationControlEnabled, Bool, bool, DEFAULT_VALUE_FOR_ImageAnimationControlEnabled, "Image Animation Control", "Enable controls for image animations") \
    macro(ImageCaptureEnabled, imageCaptureEnabled, Bool, bool, DEFAULT_VALUE_FOR_ImageCaptureEnabled, "Image Capture API", "Enable Image Capture API") \
    macro(ImageControlsEnabled, imageControlsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ImageControlsEnabled, "Image Controls", "Enable image controls") \
    macro(InWindowFullscreenEnabled, inWindowFullscreenEnabled, Bool, bool, DEFAULT_VALUE_FOR_InWindowFullscreenEnabled, "In-Window Fullscreen", "Enable In-Window Fullscreen") \
    macro(IncludeIgnoredInCoreAXTree, includeIgnoredInCoreAXTree, Bool, bool, DEFAULT_VALUE_FOR_IncludeIgnoredInCoreAXTree, "Include ignored elements in core accessibility tree", "When true, accessibility-is-ignored is not used to build the core, platform-agnostic accessibility tree, and instead is expected to be applied at any platform-exposed layer.") \
    macro(IndexedDBAPIEnabled, indexedDBAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_IndexedDBAPIEnabled, "IndexedDB API", "IndexedDB API") \
    macro(InteractionRegionsEnabled, interactionRegionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_InteractionRegionsEnabled, "Interaction Regions", "Generate and visualize interaction regions") \
    macro(IsAccessibilityIsolatedTreeEnabled, isAccessibilityIsolatedTreeEnabled, Bool, bool, DEFAULT_VALUE_FOR_IsAccessibilityIsolatedTreeEnabled, "Isolated Accessibility Tree Mode", "Enable an accessibility hierarchy for VoiceOver that can be accessed on a secondary thread for improved performance") \
    macro(JavaScriptEnabled, javaScriptEnabled, Bool, bool, DEFAULT_VALUE_FOR_JavaScriptEnabled, "JavaScript", "Enable JavaScript") \
    macro(KeyboardDismissalGestureEnabled, keyboardDismissalGestureEnabled, Bool, bool, DEFAULT_VALUE_FOR_KeyboardDismissalGestureEnabled, "Keyboard Dismissal Gesture", "Enable the keyboard dismissal gesture") \
    macro(LayerBasedSVGEngineEnabled, layerBasedSVGEngineEnabled, Bool, bool, DEFAULT_VALUE_FOR_LayerBasedSVGEngineEnabled, "Layer-based SVG Engine (LBSE)", "Enable next-generation layer-based SVG Engine (LBSE)") \
    macro(LazyIframeLoadingEnabled, lazyIframeLoadingEnabled, Bool, bool, DEFAULT_VALUE_FOR_LazyIframeLoadingEnabled, "Lazy iframe loading", "Enable lazy iframe loading support") \
    macro(LazyImageLoadingEnabled, lazyImageLoadingEnabled, Bool, bool, DEFAULT_VALUE_FOR_LazyImageLoadingEnabled, "Lazy image loading", "Enable lazy image loading support") \
    macro(LegacyOverflowScrollingTouchEnabled, legacyOverflowScrollingTouchEnabled, Bool, bool, DEFAULT_VALUE_FOR_LegacyOverflowScrollingTouchEnabled, "Legacy -webkit-overflow-scrolling property", "Support the legacy -webkit-overflow-scrolling CSS property") \
    macro(LegacyLineLayoutVisualCoverageEnabled, legacyLineLayoutVisualCoverageEnabled, Bool, bool, DEFAULT_VALUE_FOR_LegacyLineLayoutVisualCoverageEnabled, "Legacy line layout visual coverage", "Enable legacy line layout visual coverage") \
    macro(ShowModalDialogEnabled, showModalDialogEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShowModalDialogEnabled, "Legacy showModalDialog() API", "Legacy showModalDialog() API") \
    macro(MediaCaptureRequiresSecureConnection, mediaCaptureRequiresSecureConnection, Bool, bool, DEFAULT_VALUE_FOR_MediaCaptureRequiresSecureConnection, "Limit Media Capture to Secure Sites", "Limit Media Capture to Secure Sites") \
    macro(LimitedMatroskaSupportEnabled, limitedMatroskaSupportEnabled, Bool, bool, DEFAULT_VALUE_FOR_LimitedMatroskaSupportEnabled, "Limited Matroska Support", "Enable H264 and PCM with WebM Player and MediaRecorder") \
    macro(LinearMediaPlayerEnabled, linearMediaPlayerEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinearMediaPlayerEnabled, "Linear Media Player", "Enable LinearMediaPlayer for fullscreen video") \
    macro(LinkSanitizerEnabled, linkSanitizerEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinkSanitizerEnabled, "Link Sanitizer", "Enable link sanitizer") \
    macro(LinkPreconnectEarlyHintsEnabled, linkPreconnectEarlyHintsEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinkPreconnectEarlyHintsEnabled, "Link rel=preconnect via HTTP early hints", "Enable link rel=preconnect via early hints") \
    macro(LinkPrefetchEnabled, linkPrefetchEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinkPrefetchEnabled, "LinkPrefetch", "Enable LinkedPrefetch") \
    macro(LoadWebArchiveWithEphemeralStorageEnabled, loadWebArchiveWithEphemeralStorageEnabled, Bool, bool, DEFAULT_VALUE_FOR_LoadWebArchiveWithEphemeralStorageEnabled, "Load Web Archive with ephemeral storage", "Enable loading web archive with ephemeral storage") \
    macro(LocalFileContentSniffingEnabled, localFileContentSniffingEnabled, Bool, bool, DEFAULT_VALUE_FOR_LocalFileContentSniffingEnabled, "Local File Content Sniffing", "Enable Local File Content Sniffing") \
    macro(LocalNetworkAccessEnabled, localNetworkAccessEnabled, Bool, bool, DEFAULT_VALUE_FOR_LocalNetworkAccessEnabled, "Local Network Access", "Enable Local Network Access") \
    macro(LocalStorageEnabled, localStorageEnabled, Bool, bool, DEFAULT_VALUE_FOR_LocalStorageEnabled, "Local Storage", "Enable Local Storage") \
    macro(LockdownFontParserEnabled, lockdownFontParserEnabled, Bool, bool, DEFAULT_VALUE_FOR_LockdownFontParserEnabled, "Lockdown Mode Safe Fonts", "Try parsing Web fonts with safe font parser in Lockdown Mode") \
    macro(LogsPageMessagesToSystemConsoleEnabled, logsPageMessagesToSystemConsoleEnabled, Bool, bool, DEFAULT_VALUE_FOR_LogsPageMessagesToSystemConsoleEnabled, "Log page messages to system console", "Enable logging page messages to system console") \
    macro(LoginStatusAPIEnabled, loginStatusAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_LoginStatusAPIEnabled, "Login Status API", "Enable the proposed Login Status API") \
    macro(MainContentUserGestureOverrideEnabled, mainContentUserGestureOverrideEnabled, Bool, bool, DEFAULT_VALUE_FOR_MainContentUserGestureOverrideEnabled, "Main content user gesture override", "Enable main content user gesture override") \
    macro(ManagedMediaSourceEnabled, managedMediaSourceEnabled, Bool, bool, DEFAULT_VALUE_FOR_ManagedMediaSourceEnabled, "Managed Media Source API", "Managed Media Source API") \
    macro(ManagedMediaSourceNeedsAirPlay, managedMediaSourceNeedsAirPlay, Bool, bool, DEFAULT_VALUE_FOR_ManagedMediaSourceNeedsAirPlay, "Managed Media Source Requires AirPlay source", "Managed Media Source Requires AirPlay source") \
    macro(CoreMathMLEnabled, coreMathMLEnabled, Bool, bool, DEFAULT_VALUE_FOR_CoreMathMLEnabled, "MathML Core", "Disable features removed from the MathML Core spec.") \
    macro(MediaCapabilitiesExtensionsEnabled, mediaCapabilitiesExtensionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaCapabilitiesExtensionsEnabled, "Media Capabilities Extensions", "Media Capabilities Extensions") \
    macro(MediaCapabilityGrantsEnabled, mediaCapabilityGrantsEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaCapabilityGrantsEnabled, "Media Capability Grants", "Enable granting and revoking of media capabilities") \
    macro(MediaPlaybackEnabled, mediaPlaybackEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaPlaybackEnabled, "Media Playback Functionalities", "Enable media playback functionalities") \
    macro(MediaSessionEnabled, mediaSessionEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSessionEnabled, "Media Session API", "Media Session API") \
    macro(MediaSourceEnabled, mediaSourceEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSourceEnabled, "Media Source API", "Media Source API") \
    macro(MediaDevicesEnabled, mediaDevicesEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaDevicesEnabled, "Media devices", "Enable media devices") \
    macro(MediaRecorderEnabledWebM, mediaRecorderEnabledWebM, Bool, bool, DEFAULT_VALUE_FOR_MediaRecorderEnabledWebM, "MediaRecorder WebM", "Enable WebM support with MediaRecorder") \
    macro(MediaRecorderEnabled, mediaRecorderEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaRecorderEnabled, "MediaRecorder", "MediaRecorder") \
    macro(MediaSessionCaptureToggleAPIEnabled, mediaSessionCaptureToggleAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSessionCaptureToggleAPIEnabled, "MediaSession capture related API", "Enable MediaSession capture related API") \
    macro(MediaSourceInWorkerEnabled, mediaSourceInWorkerEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSourceInWorkerEnabled, "MediaSource in a Worker", "MediaSource in a Worker") \
    macro(MediaSourcePrefersDecompressionSession, mediaSourcePrefersDecompressionSession, Bool, bool, DEFAULT_VALUE_FOR_MediaSourcePrefersDecompressionSession, "MediaSource prefers DecompressionSession", "MediaSource prefers DecompressionSession") \
    macro(MediaStreamTrackProcessingEnabled, mediaStreamTrackProcessingEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaStreamTrackProcessingEnabled, "MediaStreamTrack Processing", "Enable MediaStreamTrack Processing") \
    macro(MetaViewportInteractiveWidgetEnabled, metaViewportInteractiveWidgetEnabled, Bool, bool, DEFAULT_VALUE_FOR_MetaViewportInteractiveWidgetEnabled, "Meta Viewport Interactive Widget", "Enable the interactive-widget attribute on the viewport meta element") \
    macro(ModelNoPortalAttributeEnabled, modelNoPortalAttributeEnabled, Bool, bool, DEFAULT_VALUE_FOR_ModelNoPortalAttributeEnabled, "Model noportal attribute", "Enable Model noportal attribute support") \
    macro(ShouldUseModernAVContentKeySession, shouldUseModernAVContentKeySession, Bool, bool, DEFAULT_VALUE_FOR_ShouldUseModernAVContentKeySession, "Modern AVContentKeySession", "Use modern AVContentKeySession") \
    macro(MomentumScrollingAnimatorEnabled, momentumScrollingAnimatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_MomentumScrollingAnimatorEnabled, "Momentum Scrolling Animator", "Generate momentum events in WebKit instead of using those delivered by the system") \
    macro(InputTypeMonthEnabled, inputTypeMonthEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeMonthEnabled, "Month Input", "Enable input elements of type month") \
    macro(MouseEventsSimulationEnabled, mouseEventsSimulationEnabled, Bool, bool, DEFAULT_VALUE_FOR_MouseEventsSimulationEnabled, "Mouse events simulation", "Enable mouse events dispatch along with touch events on iOS") \
    macro(MuteCameraOnMicrophoneInterruptionEnabled, muteCameraOnMicrophoneInterruptionEnabled, Bool, bool, DEFAULT_VALUE_FOR_MuteCameraOnMicrophoneInterruptionEnabled, "Mute Camera on Microphone Interruption", "Mute Camera on Microphone Interruption") \
    macro(NavigationAPIEnabled, navigationAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_NavigationAPIEnabled, "Navigation API", "Enable Navigation API") \
    macro(NeedsInAppBrowserPrivacyQuirks, needsInAppBrowserPrivacyQuirks, Bool, bool, DEFAULT_VALUE_FOR_NeedsInAppBrowserPrivacyQuirks, "Needs In-App Browser Privacy Quirks", "Enable quirks needed to support In-App Browser privacy") \
    macro(NeedsSiteSpecificQuirks, needsSiteSpecificQuirks, Bool, bool, DEFAULT_VALUE_FOR_NeedsSiteSpecificQuirks, "Needs Site-Specific Quirks", "Enable site-specific quirks") \
    macro(NeedsStorageAccessFromFileURLsQuirk, needsStorageAccessFromFileURLsQuirk, Bool, bool, DEFAULT_VALUE_FOR_NeedsStorageAccessFromFileURLsQuirk, "Needs storage access from file URLs quirk", "") \
    macro(FlexFormattingContextIntegrationEnabled, flexFormattingContextIntegrationEnabled, Bool, bool, DEFAULT_VALUE_FOR_FlexFormattingContextIntegrationEnabled, "Next-generation flex layout integration (FFC)", "Enable next-generation flex layout integration (FFC)") \
    macro(NotificationEventEnabled, notificationEventEnabled, Bool, bool, DEFAULT_VALUE_FOR_NotificationEventEnabled, "NotificationEvent support", "NotificationEvent and ServiceWorkerRegistration.showNotification() support") \
    macro(NotificationsEnabled, notificationsEnabled, Bool, bool, DEFAULT_VALUE_FOR_NotificationsEnabled, "Notifications", "Enable the Notifications API") \
    macro(ObservableEnabled, observableEnabled, Bool, bool, DEFAULT_VALUE_FOR_ObservableEnabled, "Observable API", "Support for the Observable API") \
    macro(AccessibilityThreadTextApisEnabled, accessibilityThreadTextApisEnabled, Bool, bool, DEFAULT_VALUE_FOR_AccessibilityThreadTextApisEnabled, "Off Main-Thread Accessibility Text APIs", "Serve accessibility text APIs off the main-thread") \
    macro(OffscreenCanvasInWorkersEnabled, offscreenCanvasInWorkersEnabled, Bool, bool, DEFAULT_VALUE_FOR_OffscreenCanvasInWorkersEnabled, "OffscreenCanvas in Workers", "Support for the OffscreenCanvas APIs in Workers") \
    macro(OffscreenCanvasEnabled, offscreenCanvasEnabled, Bool, bool, DEFAULT_VALUE_FOR_OffscreenCanvasEnabled, "OffscreenCanvas", "Support for the OffscreenCanvas APIs") \
    macro(OpportunisticSweepingAndGarbageCollectionEnabled, opportunisticSweepingAndGarbageCollectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_OpportunisticSweepingAndGarbageCollectionEnabled, "Opportunistic Sweeping and GC", "Enable Opportunistic Sweeping and GC") \
    macro(OptInPartitionedCookiesEnabled, optInPartitionedCookiesEnabled, Bool, bool, DEFAULT_VALUE_FOR_OptInPartitionedCookiesEnabled, "Opt-in partitioned cookies (CHIPS)", "Enable opt-in partitioned cookies") \
    macro(OverlappingBackingStoreProvidersEnabled, overlappingBackingStoreProvidersEnabled, Bool, bool, DEFAULT_VALUE_FOR_OverlappingBackingStoreProvidersEnabled, "Overlapping backing stores", "Enable overlapping backing stores compositor optimization") \
    macro(OverlayRegionsEnabled, overlayRegionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_OverlayRegionsEnabled, "Overlay Regions", "Generate and visualize overlay regions") \
    macro(PageVisibilityBasedProcessSuppressionEnabled, pageVisibilityBasedProcessSuppressionEnabled, Bool, bool, DEFAULT_VALUE_FOR_PageVisibilityBasedProcessSuppressionEnabled, "Page visibility-based process suppression", "Enable page visibility-based process suppression") \
    macro(PermissionsAPIEnabled, permissionsAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_PermissionsAPIEnabled, "Permissions API", "Enable Permissions API") \
    macro(PhotoPickerPrefersOriginalImageFormat, photoPickerPrefersOriginalImageFormat, Bool, bool, DEFAULT_VALUE_FOR_PhotoPickerPrefersOriginalImageFormat, "Photo Picker Prefers Original Image Format", "Prefer the original image format when selecting photos for file upload") \
    macro(PictureInPicturePlaybackStateEnabled, pictureInPicturePlaybackStateEnabled, Bool, bool, DEFAULT_VALUE_FOR_PictureInPicturePlaybackStateEnabled, "Picture-in-Picture Playback State Enabled", "Picture-in-Picture Playback State Enabled") \
    macro(GetCoalescedEventsEnabled, getCoalescedEventsEnabled, Bool, bool, DEFAULT_VALUE_FOR_GetCoalescedEventsEnabled, "Pointer Events getCoalescedEvents API", "Enable the `getCoalescedEvents` function of the Pointer Events API") \
    macro(GetPredictedEventsEnabled, getPredictedEventsEnabled, Bool, bool, DEFAULT_VALUE_FOR_GetPredictedEventsEnabled, "Pointer Events getPredictedEvents API", "Enable the `getPredictedEvents` function of the Pointer Events API") \
    macro(PointerLockEnabled, pointerLockEnabled, Bool, bool, DEFAULT_VALUE_FOR_PointerLockEnabled, "Pointer Lock API", "Enable the Pointer Lock API") \
    macro(PointerLockOptionsEnabled, pointerLockOptionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_PointerLockOptionsEnabled, "Pointer Lock Options", "Element.requestPointerLock(options) and promise support.") \
    macro(PreferPageRenderingUpdatesNear60FPSEnabled, preferPageRenderingUpdatesNear60FPSEnabled, Bool, bool, DEFAULT_VALUE_FOR_PreferPageRenderingUpdatesNear60FPSEnabled, "Prefer Page Rendering Updates near 60fps", "Prefer page rendering updates near 60 frames per second rather than using the display's refresh rate") \
    macro(PreferSpatialAudioExperience, preferSpatialAudioExperience, Bool, bool, DEFAULT_VALUE_FOR_PreferSpatialAudioExperience, "Prefer Spatial Audio Experience over Spatial Tracking Labels", "Prefer Spatial Audio Experience over Spatial Tracking Labels") \
    macro(VideoFullsceenPrefersMostVisibleHeuristic, videoFullsceenPrefersMostVisibleHeuristic, Bool, bool, DEFAULT_VALUE_FOR_VideoFullsceenPrefersMostVisibleHeuristic, "Prefers most visible video in element fullscreen.", "Prefers most visible video in element fullscreen.") \
    macro(PrivateClickMeasurementDebugModeEnabled, privateClickMeasurementDebugModeEnabled, Bool, bool, DEFAULT_VALUE_FOR_PrivateClickMeasurementDebugModeEnabled, "Private Click Measurement Debug Mode", "Enable Private Click Measurement Debug Mode") \
    macro(PrivateClickMeasurementFraudPreventionEnabled, privateClickMeasurementFraudPreventionEnabled, Bool, bool, DEFAULT_VALUE_FOR_PrivateClickMeasurementFraudPreventionEnabled, "Private Click Measurement Fraud Prevention", "Enable Private Click Measurement Fraud Prevention") \
    macro(PrivateClickMeasurementEnabled, privateClickMeasurementEnabled, Bool, bool, DEFAULT_VALUE_FOR_PrivateClickMeasurementEnabled, "Private Click Measurement", "Enable Private Click Measurement for Cross-Site Link Navigations") \
    macro(PrivateTokenUsageByThirdPartyEnabled, privateTokenUsageByThirdPartyEnabled, Bool, bool, DEFAULT_VALUE_FOR_PrivateTokenUsageByThirdPartyEnabled, "Private Token usage by third party", "Enable private token usage by third party") \
    macro(PropagateDamagingInformation, propagateDamagingInformation, Bool, bool, DEFAULT_VALUE_FOR_PropagateDamagingInformation, "Propagate Damaging Information", "Propagate Damaging Information") \
    macro(PushAPIEnabled, pushAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_PushAPIEnabled, "Push API", "Enable Push API") \
    macro(LegacyPluginQuirkForMailSignaturesEnabled, legacyPluginQuirkForMailSignaturesEnabled, Bool, bool, DEFAULT_VALUE_FOR_LegacyPluginQuirkForMailSignaturesEnabled, "Quirk to get Mail to load signatures correctly with WebKitLegacy", "Quirk to get Mail to load signatures correctly with WebKitLegacy") \
    macro(GoogleAntiFlickerOptimizationQuirkEnabled, googleAntiFlickerOptimizationQuirkEnabled, Bool, bool, DEFAULT_VALUE_FOR_GoogleAntiFlickerOptimizationQuirkEnabled, "Quirk to prevent delayed initial painting on sites using Google's Anti-Flicker optimization", "Quirk to prevent delayed initial painting on sites using Google's Anti-Flicker optimization") \
    macro(ReadableByteStreamAPIEnabled, readableByteStreamAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_ReadableByteStreamAPIEnabled, "ReadableByteStream", "Enable Readable Byte Streams") \
    macro(RemoteMediaSessionManagerEnabled, remoteMediaSessionManagerEnabled, Bool, bool, DEFAULT_VALUE_FOR_RemoteMediaSessionManagerEnabled, "Remote MediaSessionManager", "Enable MediaSessionManager in the GPU process") \
    macro(RemotePlaybackEnabled, remotePlaybackEnabled, Bool, bool, DEFAULT_VALUE_FOR_RemotePlaybackEnabled, "Remote Playback API", "Enable Remote Playback API") \
    macro(RemoteSnapshottingEnabled, remoteSnapshottingEnabled, Bool, bool, DEFAULT_VALUE_FOR_RemoteSnapshottingEnabled, "Remote Snapshotting", "") \
    macro(RemoveBackgroundEnabled, removeBackgroundEnabled, Bool, bool, DEFAULT_VALUE_FOR_RemoveBackgroundEnabled, "Remove Background", "Enable Remove Background") \
    macro(RequestVideoFrameCallbackEnabled, requestVideoFrameCallbackEnabled, Bool, bool, DEFAULT_VALUE_FOR_RequestVideoFrameCallbackEnabled, "RequestVideoFrameCallback", "Enable RequestVideoFrameCallback API") \
    macro(RequireUAGetDisplayMediaPrompt, requireUAGetDisplayMediaPrompt, Bool, bool, DEFAULT_VALUE_FOR_RequireUAGetDisplayMediaPrompt, "Require User Agent getDisplayMedia prompt", "Require and use User Agent getDisplayMedia prompt") \
    macro(LoginStatusAPIRequiresWebAuthnEnabled, loginStatusAPIRequiresWebAuthnEnabled, Bool, bool, DEFAULT_VALUE_FOR_LoginStatusAPIRequiresWebAuthnEnabled, "Require WebAuthn with the Login Status API", "Require a recent WebAuthn authentication to set login status") \
    macro(SpeakerSelectionRequiresUserGesture, speakerSelectionRequiresUserGesture, Bool, bool, DEFAULT_VALUE_FOR_SpeakerSelectionRequiresUserGesture, "Require a user gesture for speaker selection", "Require a user gesture for speaker selection") \
    macro(FullscreenRequirementForScreenOrientationLockingEnabled, fullscreenRequirementForScreenOrientationLockingEnabled, Bool, bool, DEFAULT_VALUE_FOR_FullscreenRequirementForScreenOrientationLockingEnabled, "Require being in Fullscreen to lock screen orientation", "Require being in Fullscreen to lock screen orientation") \
    macro(GetUserMediaRequiresFocus, getUserMediaRequiresFocus, Bool, bool, DEFAULT_VALUE_FOR_GetUserMediaRequiresFocus, "Require focus to start getUserMedia", "Require focus to start getUserMedia") \
    macro(ResourceLoadSchedulingEnabled, resourceLoadSchedulingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ResourceLoadSchedulingEnabled, "Resource Load Scheduling", "Network process side priority and visibility based resource load scheduling") \
    macro(ResourceUsageOverlayVisible, resourceUsageOverlayVisible, Bool, bool, DEFAULT_VALUE_FOR_ResourceUsageOverlayVisible, "Resource usage overlay", "Make resource usage overlay visible") \
    macro(RespondToThermalPressureAggressively, respondToThermalPressureAggressively, Bool, bool, DEFAULT_VALUE_FOR_RespondToThermalPressureAggressively, "Respond to thermal pressure aggressively", "Enable responding to thermal pressure aggressively") \
    macro(SKAttributionEnabled, sKAttributionEnabled, Bool, bool, DEFAULT_VALUE_FOR_SKAttributionEnabled, "SKAttribution", "SKAttribution") \
    macro(SafeBrowsingEnabled, safeBrowsingEnabled, Bool, bool, DEFAULT_VALUE_FOR_SafeBrowsingEnabled, "Safe Browsing", "Enable Safe Browsing") \
    macro(IsSameSiteStrictEnforcementEnabled, isSameSiteStrictEnforcementEnabled, Bool, bool, DEFAULT_VALUE_FOR_IsSameSiteStrictEnforcementEnabled, "SameSite strict enforcement (ITP)", "Enable SameSite strict enforcement to mitigate bounce tracking") \
    macro(ScopedCustomElementRegistryEnabled, scopedCustomElementRegistryEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScopedCustomElementRegistryEnabled, "Scoped custom element registry", "Enable scoped custom element registry") \
    macro(ScreenOrientationLockingAPIEnabled, screenOrientationLockingAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScreenOrientationLockingAPIEnabled, "Screen Orientation API (Locking / Unlocking)", "Enable Screen Orientation API (Locking / Unlocking)") \
    macro(ScreenOrientationAPIEnabled, screenOrientationAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScreenOrientationAPIEnabled, "Screen Orientation API", "Enable Screen Orientation API") \
    macro(ScreenTimeEnabled, screenTimeEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScreenTimeEnabled, "Screen Time", "Enable Screen Time") \
    macro(ScreenWakeLockAPIEnabled, screenWakeLockAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScreenWakeLockAPIEnabled, "Screen Wake Lock API", "Enable Screen Wake Lock API") \
    macro(ScreenCaptureEnabled, screenCaptureEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScreenCaptureEnabled, "ScreenCapture", "Enable ScreenCapture") \
    macro(ScriptTrackingPrivacyLoggingEnabled, scriptTrackingPrivacyLoggingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScriptTrackingPrivacyLoggingEnabled, "Script Tracking Privacy Logging", "Script tracking privacy logging enabled") \
    macro(ScriptTrackingPrivacyProtectionsEnabled, scriptTrackingPrivacyProtectionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScriptTrackingPrivacyProtectionsEnabled, "Script Tracking Privacy Protections", "Script tracking privacy protections enabled") \
    macro(ScrollingPerformanceTestingEnabled, scrollingPerformanceTestingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollingPerformanceTestingEnabled, "Scroll Performance Testing Enabled", "Enable behaviors used by scrolling performance tests") \
    macro(ScrollToTextFragmentFeatureDetectionEnabled, scrollToTextFragmentFeatureDetectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentFeatureDetectionEnabled, "Scroll To Text Fragment Feature Detection", "Enable Scroll To Text Fragment Feature Detection") \
    macro(ScrollToTextFragmentGenerationEnabled, scrollToTextFragmentGenerationEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentGenerationEnabled, "Scroll To Text Fragment Generation", "Enable Scroll To Text Fragment Generation Menu") \
    macro(ScrollToTextFragmentIndicatorEnabled, scrollToTextFragmentIndicatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentIndicatorEnabled, "Scroll To Text Fragment Indicator", "Enable Scroll To Text Fragment Indicator") \
    macro(ScrollToTextFragmentMarkingEnabled, scrollToTextFragmentMarkingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentMarkingEnabled, "Scroll To Text Fragment Marking", "Enable Scroll To Text Fragment Marking") \
    macro(ScrollToTextFragmentEnabled, scrollToTextFragmentEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentEnabled, "Scroll To Text Fragment", "Enable Scroll To Text Fragment") \
    macro(ScrollAnimatorEnabled, scrollAnimatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollAnimatorEnabled, "Scroll animator", "Enable scroll animator") \
    macro(ScrollDrivenAnimationsEnabled, scrollDrivenAnimationsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollDrivenAnimationsEnabled, "Scroll-driven Animations", "Enable Scroll-driven Animations") \
    macro(SecureContextChecksEnabled, secureContextChecksEnabled, Bool, bool, DEFAULT_VALUE_FOR_SecureContextChecksEnabled, "Secure Context Checks", "Allow access to HTTPS-only Web APIs over HTTP") \
    macro(SelectionFlippingEnabled, selectionFlippingEnabled, Bool, bool, DEFAULT_VALUE_FOR_SelectionFlippingEnabled, "Selection Flipping", "Enable Selection Flipping") \
    macro(SelectionHonorsOverflowScrolling, selectionHonorsOverflowScrolling, Bool, bool, DEFAULT_VALUE_FOR_SelectionHonorsOverflowScrolling, "Selection Honors Overflow Scrolling", "Selection honors overflow scrolling") \
    macro(ServiceWorkerInstallEventEnabled, serviceWorkerInstallEventEnabled, Bool, bool, DEFAULT_VALUE_FOR_ServiceWorkerInstallEventEnabled, "Service Worker Install Event", "Enable Service Worker Install Event API") \
    macro(ServiceWorkerNavigationPreloadEnabled, serviceWorkerNavigationPreloadEnabled, Bool, bool, DEFAULT_VALUE_FOR_ServiceWorkerNavigationPreloadEnabled, "Service Worker Navigation Preload", "Enable Service Worker Navigation Preload API") \
    macro(ServiceWorkersEnabled, serviceWorkersEnabled, Bool, bool, DEFAULT_VALUE_FOR_ServiceWorkersEnabled, "Service Workers", "Enable Service Workers") \
    macro(ShapeDetection, shapeDetection, Bool, bool, DEFAULT_VALUE_FOR_ShapeDetection, "Shape Detection API", "Enable the Shape Detection API") \
    macro(SiteIsolationSharedProcessEnabled, siteIsolationSharedProcessEnabled, Bool, bool, DEFAULT_VALUE_FOR_SiteIsolationSharedProcessEnabled, "Shared process for Site Isolation", "Put cross-site frames in a shared Web process") \
    macro(SharedWorkerEnabled, sharedWorkerEnabled, Bool, bool, DEFAULT_VALUE_FOR_SharedWorkerEnabled, "SharedWorker", "Enabled SharedWorker API") \
    macro(ShowMediaStatsContextMenuItemEnabled, showMediaStatsContextMenuItemEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShowMediaStatsContextMenuItemEnabled, "Show Media Stats", "Adds a 'Media Stats' context menu item to <video> when the Develop menu is enabled") \
    macro(ShowFrameProcessBordersEnabled, showFrameProcessBordersEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShowFrameProcessBordersEnabled, "Show frame process borders", "") \
    macro(SidewaysWritingModesEnabled, sidewaysWritingModesEnabled, Bool, bool, DEFAULT_VALUE_FOR_SidewaysWritingModesEnabled, "Sideways writing modes", "Enable support for sideways writing modes") \
    macro(SiteIsolationEnabled, siteIsolationEnabled, Bool, bool, DEFAULT_VALUE_FOR_SiteIsolationEnabled, "Site Isolation", "Put cross-origin iframes in a different process") \
    macro(SpatialImageControlsEnabled, spatialImageControlsEnabled, Bool, bool, DEFAULT_VALUE_FOR_SpatialImageControlsEnabled, "Spatial image controls API", "Spatial image controls API") \
    macro(SpeechRecognitionEnabled, speechRecognitionEnabled, Bool, bool, DEFAULT_VALUE_FOR_SpeechRecognitionEnabled, "SpeechRecognition API", "Enable SpeechRecognition of WebSpeech API") \
    macro(SpeechSynthesisAPIEnabled, speechSynthesisAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_SpeechSynthesisAPIEnabled, "SpeechSynthesis API", "SpeechSynthesis API") \
    macro(StorageAPIEstimateEnabled, storageAPIEstimateEnabled, Bool, bool, DEFAULT_VALUE_FOR_StorageAPIEstimateEnabled, "Storage API Estimate", "Enable Storage API Estimate") \
    macro(StorageAPIEnabled, storageAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_StorageAPIEnabled, "Storage API", "Enable Storage API") \
    macro(StorageBlockingPolicy, storageBlockingPolicy, UInt32, uint32_t, DEFAULT_VALUE_FOR_StorageBlockingPolicy, "Storage Blocking Policy", "") \
    macro(SupportHDRCompositorTonemappingEnabled, supportHDRCompositorTonemappingEnabled, Bool, bool, DEFAULT_VALUE_FOR_SupportHDRCompositorTonemappingEnabled, "Support HDR Compositor tonemapping", "Support HDR tonemapping during compositing") \
    macro(SupportHDRDisplayEnabled, supportHDRDisplayEnabled, Bool, bool, DEFAULT_VALUE_FOR_SupportHDRDisplayEnabled, "Support HDR Display", "Support HDR Display") \
    macro(ProcessSwapOnCrossSiteNavigationEnabled, processSwapOnCrossSiteNavigationEnabled, Bool, bool, DEFAULT_VALUE_FOR_ProcessSwapOnCrossSiteNavigationEnabled, "Swap Processes on Cross-Site Navigation", "Swap WebContent Processes on cross-site navigations") \
    macro(ShouldTakeNearSuspendedAssertions, shouldTakeNearSuspendedAssertions, Bool, bool, DEFAULT_VALUE_FOR_ShouldTakeNearSuspendedAssertions, "Take WebKit:NearSuspended assertions on background web content processes", "Take WebKit:NearSuspended assertions on background web content processes") \
    macro(TextAnimationsEnabled, textAnimationsEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextAnimationsEnabled, "Text Animations", "Text Animations") \
    macro(TextRecognitionInVideosEnabled, textRecognitionInVideosEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextRecognitionInVideosEnabled, "Text Recognition in Videos", "Enable Text Recognition in Videos") \
    macro(TextTracksInMSEEnabled, textTracksInMSEEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextTracksInMSEEnabled, "Text Tracks in MSE", "Enable Text Tracks in Media Source Extension") \
    macro(ThreadedAnimationResolutionEnabled, threadedAnimationResolutionEnabled, Bool, bool, DEFAULT_VALUE_FOR_ThreadedAnimationResolutionEnabled, "Threaded animation resolution", "Run accelerated animations on a separate thread") \
    macro(TiledScrollingIndicatorVisible, tiledScrollingIndicatorVisible, Bool, bool, DEFAULT_VALUE_FOR_TiledScrollingIndicatorVisible, "Tiled scrolling indicator", "Make tiled scrolling indicator visible") \
    macro(InputTypeTimeEnabled, inputTypeTimeEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeTimeEnabled, "Time Input", "Enable input elements of type time") \
    macro(TopContentInsetBackgroundCanChangeAfterScrolling, topContentInsetBackgroundCanChangeAfterScrolling, Bool, bool, DEFAULT_VALUE_FOR_TopContentInsetBackgroundCanChangeAfterScrolling, "Top Content Inset Background Can Change After Scrolling", "Top content inset background can change after scrolling") \
    macro(TouchInputCompatibilityEnabled, touchInputCompatibilityEnabled, Bool, bool, DEFAULT_VALUE_FOR_TouchInputCompatibilityEnabled, "Touch Input Compatibility", "Touch Input Compatibility") \
    macro(TrackConfigurationEnabled, trackConfigurationEnabled, Bool, bool, DEFAULT_VALUE_FOR_TrackConfigurationEnabled, "Track Configuration API", "Track Configuration API") \
    macro(TrustedTypesEnabled, trustedTypesEnabled, Bool, bool, DEFAULT_VALUE_FOR_TrustedTypesEnabled, "Trusted Types", "Enable Trusted Types") \
    macro(URLPatternAPIEnabled, uRLPatternAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_URLPatternAPIEnabled, "URL Pattern API", "Enable URL Pattern API") \
    macro(UndoManagerAPIEnabled, undoManagerAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_UndoManagerAPIEnabled, "UndoManager DOM API", "Enable the UndoManager DOM API") \
    macro(UnifiedPDFEnabled, unifiedPDFEnabled, Bool, bool, DEFAULT_VALUE_FOR_UnifiedPDFEnabled, "Unified PDF Viewer", "Enable Unified PDF Viewer") \
    macro(UnifyDamagedRegions, unifyDamagedRegions, Bool, bool, DEFAULT_VALUE_FOR_UnifyDamagedRegions, "Unify Damaged Regions", "Unify Damaged Regions") \
    macro(IPAddressAndLocalhostMixedContentUpgradeTestingEnabled, iPAddressAndLocalhostMixedContentUpgradeTestingEnabled, Bool, bool, DEFAULT_VALUE_FOR_IPAddressAndLocalhostMixedContentUpgradeTestingEnabled, "Upgrade IP addresses and localhost in mixed content", "Enable Upgrading IP addresses and localhost in mixed content") \
    macro(UpgradeKnownHostsToHTTPSEnabled, upgradeKnownHostsToHTTPSEnabled, Bool, bool, DEFAULT_VALUE_FOR_UpgradeKnownHostsToHTTPSEnabled, "Upgrade known hosts to HTTPS", "Upgrade known hosts to HTTPS") \
    macro(UpgradeMixedContentEnabled, upgradeMixedContentEnabled, Bool, bool, DEFAULT_VALUE_FOR_UpgradeMixedContentEnabled, "Upgrade upgradable mixed content", "Upgrade upgradable mixed content") \
    macro(UseARKitForModel, useARKitForModel, Bool, bool, DEFAULT_VALUE_FOR_UseARKitForModel, "Use ARKit for <model>", "Use ARKit for <model>") \
    macro(UseAVCaptureDeviceRotationCoordinatorAPI, useAVCaptureDeviceRotationCoordinatorAPI, Bool, bool, DEFAULT_VALUE_FOR_UseAVCaptureDeviceRotationCoordinatorAPI, "Use AVCaptureDeviceRotationCoordinator API", "Use AVCaptureDeviceRotationCoordinator API") \
    macro(UseIFCForSVGText, useIFCForSVGText, Bool, bool, DEFAULT_VALUE_FOR_UseIFCForSVGText, "Use IFC for SVG text", "Use IFC for SVG text rendering") \
    macro(UseMicrophoneMuteStatusAPI, useMicrophoneMuteStatusAPI, Bool, bool, DEFAULT_VALUE_FOR_UseMicrophoneMuteStatusAPI, "Use Microphone Mute Status API", "Use Microphone Mute Status API") \
    macro(UseSceneKitForModel, useSceneKitForModel, Bool, bool, DEFAULT_VALUE_FOR_UseSceneKitForModel, "Use SceneKit for <model>", "Use SceneKit for <model>") \
    macro(UseGiantTiles, useGiantTiles, Bool, bool, DEFAULT_VALUE_FOR_UseGiantTiles, "Use giant tiles", "") \
    macro(UseDamagingInformationForCompositing, useDamagingInformationForCompositing, Bool, bool, DEFAULT_VALUE_FOR_UseDamagingInformationForCompositing, "Use the Damaging Information to optimize compositing", "Use the Damaging Information to optimize compositing") \
    macro(UserActivationAPIEnabled, userActivationAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_UserActivationAPIEnabled, "User Activation API", "Enable User Activation API") \
    macro(UserGesturePromisePropagationEnabled, userGesturePromisePropagationEnabled, Bool, bool, DEFAULT_VALUE_FOR_UserGesturePromisePropagationEnabled, "UserGesture Promise Propagation", "UserGesture Promise Propagation") \
    macro(UsesWebContentRestrictionsForFilter, usesWebContentRestrictionsForFilter, Bool, bool, DEFAULT_VALUE_FOR_UsesWebContentRestrictionsForFilter, "Uses WebContentRestriction framework for content filter", "") \
    macro(ServiceWorkersUserGestureEnabled, serviceWorkersUserGestureEnabled, Bool, bool, DEFAULT_VALUE_FOR_ServiceWorkersUserGestureEnabled, "Validate UserGesture requirements in Service Workers", "Validate UserGesture requirements in Service Workers") \
    macro(VerifyWindowOpenUserGestureFromUIProcess, verifyWindowOpenUserGestureFromUIProcess, Bool, bool, DEFAULT_VALUE_FOR_VerifyWindowOpenUserGestureFromUIProcess, "Verify window.open user gesture", "Verifies that the user gesture for window.open came from the UI process") \
    macro(VerticalFormControlsEnabled, verticalFormControlsEnabled, Bool, bool, DEFAULT_VALUE_FOR_VerticalFormControlsEnabled, "Vertical form control support", "Enable support for form controls in vertical writing mode") \
    macro(VideoRendererProtectedFallbackDisabled, videoRendererProtectedFallbackDisabled, Bool, bool, DEFAULT_VALUE_FOR_VideoRendererProtectedFallbackDisabled, "VideoMediaSampleRenderer fallback to AVSBDL for protected content disabled", "VideoMediaSampleRenderer fallback to AVSBDL for protected content disabled") \
    macro(VideoRendererUseDecompressionSessionForProtected, videoRendererUseDecompressionSessionForProtected, Bool, bool, DEFAULT_VALUE_FOR_VideoRendererUseDecompressionSessionForProtected, "VideoMediaSampleRenderer use DecompressionSession for protected content", "VideoMediaSampleRenderer use DecompressionSession for protected content") \
    macro(ViewTransitionClassesEnabled, viewTransitionClassesEnabled, Bool, bool, DEFAULT_VALUE_FOR_ViewTransitionClassesEnabled, "View Transition Classes", "Support specifying classes for view transitions") \
    macro(ViewTransitionTypesEnabled, viewTransitionTypesEnabled, Bool, bool, DEFAULT_VALUE_FOR_ViewTransitionTypesEnabled, "View Transition Types", "Support specifying types for view transitions") \
    macro(ViewTransitionsEnabled, viewTransitionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ViewTransitionsEnabled, "View Transitions", "Enable the View Transitions API") \
    macro(ViewGestureDebuggingEnabled, viewGestureDebuggingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ViewGestureDebuggingEnabled, "View gesture debugging", "Enable view gesture debugging") \
    macro(VisualTranslationEnabled, visualTranslationEnabled, Bool, bool, DEFAULT_VALUE_FOR_VisualTranslationEnabled, "Visual Translation", "Enable Visual Translation") \
    macro(VisualViewportAPIEnabled, visualViewportAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_VisualViewportAPIEnabled, "Visual Viewport API", "Enable Visual Viewport API") \
    macro(VisuallyContiguousBidiTextSelectionEnabled, visuallyContiguousBidiTextSelectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_VisuallyContiguousBidiTextSelectionEnabled, "Visually Contiguous Bidi Selection", "Visually contiguous bidi selection") \
    macro(WebAPIStatisticsEnabled, webAPIStatisticsEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAPIStatisticsEnabled, "Web API Statistics", "Enable Web API Statistics") \
    macro(WebAPIsInShadowRealmEnabled, webAPIsInShadowRealmEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAPIsInShadowRealmEnabled, "Web APIs in ShadowRealm", "Enable Web APIs to be exposed in ShadowRealm") \
    macro(WebAnimationsOverallProgressPropertyEnabled, webAnimationsOverallProgressPropertyEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAnimationsOverallProgressPropertyEnabled, "Web Animations 'overallProgress' property", "Support for Animation's overallProgress property") \
    macro(WebAnimationsCustomEffectsEnabled, webAnimationsCustomEffectsEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAnimationsCustomEffectsEnabled, "Web Animations custom effects", "Support for the CustomEffect interface") \
    macro(WebAnimationsCustomFrameRateEnabled, webAnimationsCustomFrameRateEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAnimationsCustomFrameRateEnabled, "Web Animations custom frame rate", "Support for specifying a custom frame rate for Web Animations") \
    macro(WebArchiveDebugModeEnabled, webArchiveDebugModeEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebArchiveDebugModeEnabled, "Web Archive debug mode", "Enable web archive debug mode") \
    macro(WebArchiveTestingModeEnabled, webArchiveTestingModeEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebArchiveTestingModeEnabled, "Web Archive testing mode", "Enable web archive testing mode") \
    macro(WebAuthenticationASEnabled, webAuthenticationASEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAuthenticationASEnabled, "Web Authentication AuthenticationServices", "Enable Modern Web Authentication support though AuthenticationServices") \
    macro(WebAuthenticationEnabled, webAuthenticationEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAuthenticationEnabled, "Web Authentication", "Enable Web Authentication support") \
    macro(WebCryptoSafeCurvesEnabled, webCryptoSafeCurvesEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebCryptoSafeCurvesEnabled, "Web Crypto Safe Curves", "Enable Web Crypto Safe Curves") \
    macro(WebCryptoX25519Enabled, webCryptoX25519Enabled, Bool, bool, DEFAULT_VALUE_FOR_WebCryptoX25519Enabled, "Web Crypto X25519 algorithm", "Enable Web Crypto X25519 algorithm") \
    macro(WebLocksAPIEnabled, webLocksAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebLocksAPIEnabled, "Web Locks API", "Web Locks API") \
    macro(WebShareFileAPIEnabled, webShareFileAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebShareFileAPIEnabled, "Web Share API Level 2", "Enable level 2 of Web Share API") \
    macro(WebShareEnabled, webShareEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebShareEnabled, "Web Share", "Enable support for share sheet via Web Share API") \
    macro(WebAssemblyESMIntegrationEnabled, webAssemblyESMIntegrationEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAssemblyESMIntegrationEnabled, "WebAssembly ES module integration support", "Support for allowing WebAssembly modules to integrate as ES modules") \
    macro(WebCodecsAV1Enabled, webCodecsAV1Enabled, Bool, bool, DEFAULT_VALUE_FOR_WebCodecsAV1Enabled, "WebCodecs AV1 codec", "Enable WebCodecs AV1 codec") \
    macro(WebCodecsAudioEnabled, webCodecsAudioEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebCodecsAudioEnabled, "WebCodecs Audio API", "Enable WebCodecs Audio API") \
    macro(WebCodecsHEVCEnabled, webCodecsHEVCEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebCodecsHEVCEnabled, "WebCodecs HEVC codec", "Enable WebCodecs HEVC codec") \
    macro(WebCodecsVideoEnabled, webCodecsVideoEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebCodecsVideoEnabled, "WebCodecs Video API", "Enable WebCodecs Video API") \
    macro(WebExtensionBookmarksEnabled, webExtensionBookmarksEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebExtensionBookmarksEnabled, "WebExtension Bookmarks API", "Enable support for WebExtensions using the Bookmarks API") \
    macro(WebExtensionSidebarEnabled, webExtensionSidebarEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebExtensionSidebarEnabled, "WebExtension sidebarAction and sidePanel APIs", "Enable support for WebExtensions using the sidebarAction / sidePanel family of APIs") \
    macro(WebGLDraftExtensionsEnabled, webGLDraftExtensionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGLDraftExtensionsEnabled, "WebGL Draft Extensions", "Enable WebGL extensions that are still in draft status") \
    macro(WebGLTimerQueriesEnabled, webGLTimerQueriesEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGLTimerQueriesEnabled, "WebGL Timer Queries", "Enable WebGL extensions that provide GPU timer queries") \
    macro(WebGLEnabled, webGLEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGLEnabled, "WebGL", "Enable WebGL") \
    macro(WebGPUHDREnabled, webGPUHDREnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGPUHDREnabled, "WebGPU support for HDR", "WebGPU High Dynamic Range through canvas configuration tone mapping mode") \
    macro(WebXRWebGPUBindingsEnabled, webXRWebGPUBindingsEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRWebGPUBindingsEnabled, "WebGPU support for WebXR", "Adds WebGPU support for WebXR") \
    macro(WebGPUEnabled, webGPUEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGPUEnabled, "WebGPU", "Enable WebGPU") \
    macro(WebInspectorEngineeringSettingsAllowed, webInspectorEngineeringSettingsAllowed, Bool, bool, DEFAULT_VALUE_FOR_WebInspectorEngineeringSettingsAllowed, "WebInspector engineering settings allowed", "") \
    macro(WebRTCAV1CodecEnabled, webRTCAV1CodecEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCAV1CodecEnabled, "WebRTC AV1 codec", "Enable WebRTC AV1 codec") \
    macro(WebRTCAudioLatencyAdaptationEnabled, webRTCAudioLatencyAdaptationEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCAudioLatencyAdaptationEnabled, "WebRTC Audio Latency Adaptation", "Enable WebRTC Audio Latency Adaptation") \
    macro(WebRTCDTMFEnabled, webRTCDTMFEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCDTMFEnabled, "WebRTC DTMF", "Enable WebRTC DTMF") \
    macro(WebRTCEncodedTransformEnabled, webRTCEncodedTransformEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCEncodedTransformEnabled, "WebRTC Encoded Transform API", "Enable WebRTC Encoded Transform API") \
    macro(WebRTCH264HardwareEncoderEnabled, webRTCH264HardwareEncoderEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCH264HardwareEncoderEnabled, "WebRTC H264 Hardware encoder", "Enable H264 Hardware encoder") \
    macro(WebRTCH265CodecEnabled, webRTCH265CodecEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCH265CodecEnabled, "WebRTC HEVC codec", "Enable WebRTC HEVC codec") \
    macro(WebRTCL4SEnabled, webRTCL4SEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCL4SEnabled, "WebRTC L4S support", "Enable WebRTC L4S support") \
    macro(WebRTCMediaPipelineAdditionalLoggingEnabled, webRTCMediaPipelineAdditionalLoggingEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCMediaPipelineAdditionalLoggingEnabled, "WebRTC Media Pipeline Additional Logging", "Enable WebRTC Media Pipeline Additional Logging") \
    macro(LegacyWebRTCOfferOptionsEnabled, legacyWebRTCOfferOptionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_LegacyWebRTCOfferOptionsEnabled, "WebRTC Peer Connection Legacy Offer options", "Enable RTCPeerConnection Legacy offer options (offerToReceiveAudio, offerToReceiveVideo)") \
    macro(PeerConnectionVideoScalingAdaptationDisabled, peerConnectionVideoScalingAdaptationDisabled, Bool, bool, DEFAULT_VALUE_FOR_PeerConnectionVideoScalingAdaptationDisabled, "WebRTC Peer Connection Video Scaling Adaptation", "Disable RTCPeerConnection Video Scaling Adaptation") \
    macro(PeerConnectionEnabled, peerConnectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_PeerConnectionEnabled, "WebRTC Peer Connection", "Enable RTCPeerConnection") \
    macro(WebRTCRemoteVideoFrameEnabled, webRTCRemoteVideoFrameEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCRemoteVideoFrameEnabled, "WebRTC Remote Video Frame", "Enable WebRTC Remote Video Frame") \
    macro(WebRTCSFrameTransformEnabled, webRTCSFrameTransformEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCSFrameTransformEnabled, "WebRTC SFrame Transform API", "Enable WebRTC SFrame Transform API") \
    macro(WebRTCSocketsProxyingEnabled, webRTCSocketsProxyingEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCSocketsProxyingEnabled, "WebRTC Sockets Proxying", "Enable WebRTC Sockets Proxying") \
    macro(WebRTCUDPPortRange, webRTCUDPPortRange, String, String, DEFAULT_VALUE_FOR_WebRTCUDPPortRange, "WebRTC UDP Port Range", "Set a UDP port range for WebRTC. If set to 0:0, the port range is determined by the OS") \
    macro(WebRTCVP9Profile0CodecEnabled, webRTCVP9Profile0CodecEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCVP9Profile0CodecEnabled, "WebRTC VP9 profile 0 codec", "Enable WebRTC VP9 profile 0 codec") \
    macro(WebRTCVP9Profile2CodecEnabled, webRTCVP9Profile2CodecEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCVP9Profile2CodecEnabled, "WebRTC VP9 profile 2 codec", "Enable WebRTC VP9 profile 2 codec") \
    macro(WebRTCInterfaceMonitoringViaNWEnabled, webRTCInterfaceMonitoringViaNWEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCInterfaceMonitoringViaNWEnabled, "WebRTC interface monitoring via NW", "Enable WebRTC interface monitoring via NW") \
    macro(WebTransportEnabled, webTransportEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebTransportEnabled, "WebTransport", "Enable WebTransport") \
    macro(WebXRAugmentedRealityModuleEnabled, webXRAugmentedRealityModuleEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRAugmentedRealityModuleEnabled, "WebXR Augmented Reality Module", "Adds support for the WebXR Augmented Reality Module") \
    macro(WebXREnabled, webXREnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXREnabled, "WebXR Device API", "Adds support for accessing virtual reality (VR) and augmented reality (AR) devices, including sensors and head-mounted displays, on the Web") \
    macro(WebXRGamepadsModuleEnabled, webXRGamepadsModuleEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRGamepadsModuleEnabled, "WebXR Gamepads Module", "Adds support for the WebXR Gamepads Module") \
    macro(WebXRHandInputModuleEnabled, webXRHandInputModuleEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRHandInputModuleEnabled, "WebXR Hand Input Module", "Adds support for the Hands Input Module for WebXR") \
    macro(WebXRLayersAPIEnabled, webXRLayersAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRLayersAPIEnabled, "WebXR Layers API", "Adds support for the WebXR Layers API") \
    macro(WebPageSpatialBackdropEnabled, webPageSpatialBackdropEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebPageSpatialBackdropEnabled, "Website environments", "Enable website environments") \
    macro(InputTypeWeekEnabled, inputTypeWeekEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeWeekEnabled, "Week Input", "Enable input elements of type week") \
    macro(WheelEventGesturesBecomeNonBlocking, wheelEventGesturesBecomeNonBlocking, Bool, bool, DEFAULT_VALUE_FOR_WheelEventGesturesBecomeNonBlocking, "Wheel Event gestures become non-blocking", "preventDefault() is only allowed on the first wheel event in a gesture") \
    macro(PassiveWheelListenersAsDefaultOnDocument, passiveWheelListenersAsDefaultOnDocument, Bool, bool, DEFAULT_VALUE_FOR_PassiveWheelListenersAsDefaultOnDocument, "Wheel Event listeners on the root made passive", "Force wheel event listeners registered on the window, document or body to be passive") \
    macro(WorkerAsynchronousURLErrorHandlingEnabled, workerAsynchronousURLErrorHandlingEnabled, Bool, bool, DEFAULT_VALUE_FOR_WorkerAsynchronousURLErrorHandlingEnabled, "Worker asynchronous URL error handling", "Worker asynchronous URL error handling") \
    macro(WriteRichTextDataWhenCopyingOrDragging, writeRichTextDataWhenCopyingOrDragging, Bool, bool, DEFAULT_VALUE_FOR_WriteRichTextDataWhenCopyingOrDragging, "Write RTF on Copy", "Write RTF, RTFD and attributed strings to the pasteboard when copying or dragging") \
    macro(WritingSuggestionsAttributeEnabled, writingSuggestionsAttributeEnabled, Bool, bool, DEFAULT_VALUE_FOR_WritingSuggestionsAttributeEnabled, "Writing Suggestions", "Enable the writingsuggestions attribute") \
    macro(XSLTEnabled, xSLTEnabled, Bool, bool, DEFAULT_VALUE_FOR_XSLTEnabled, "XSLT Support Enabled", "Enables support for XSLT") \
    macro(IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled, isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled, Bool, bool, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled, "[ITP Live-On] 1 Hour Timeout For Non-Cookie Data Removal", "Remove all non-cookie website data after just one hour of no user interaction when Intelligent Tracking Prevention is enabled") \
    macro(IsFirstPartyWebsiteDataRemovalReproTestingEnabled, isFirstPartyWebsiteDataRemovalReproTestingEnabled, Bool, bool, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalReproTestingEnabled, "[ITP Repro] 30 Second Timeout For Non-Cookie Data Removal", "Remove all non-cookie website data after just 30 seconds of no user interaction when Intelligent Tracking Prevention is enabled") \
    macro(AltitudeAngleEnabled, altitudeAngleEnabled, Bool, bool, DEFAULT_VALUE_FOR_AltitudeAngleEnabled, "altitudeAngle PointerEvent Property", "Enable the `altitudeAngle` property of the PointerEvents API") \
    macro(AzimuthAngleEnabled, azimuthAngleEnabled, Bool, bool, DEFAULT_VALUE_FOR_AzimuthAngleEnabled, "azimuthAngle PointerEvent Property", "Enable the `azimuthAngle` property of the PointerEvents API") \
    macro(InputTypeDateTimeLocalEnabled, inputTypeDateTimeLocalEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeDateTimeLocalEnabled, "datetime-local Inputs", "Enable input elements of type datetime-local") \
    macro(CaretPositionFromPointEnabled, caretPositionFromPointEnabled, Bool, bool, DEFAULT_VALUE_FOR_CaretPositionFromPointEnabled, "document.caretPositionFromPoint() API", "Enable document.caretPositionFromPoint() API") \
    macro(HiddenUntilFoundEnabled, hiddenUntilFoundEnabled, Bool, bool, DEFAULT_VALUE_FOR_HiddenUntilFoundEnabled, "hidden=until-found", "Enable support for hidden=until-found") \
    macro(HTTPEquivEnabled, httpEquivEnabled, Bool, bool, DEFAULT_VALUE_FOR_HTTPEquivEnabled, "http-equiv", "Enable http-equiv attribute") \
    macro(ShadowRootReferenceTargetEnabledForAriaOwns, shadowRootReferenceTargetEnabledForAriaOwns, Bool, bool, DEFAULT_VALUE_FOR_ShadowRootReferenceTargetEnabledForAriaOwns, "referenceTarget support for aria-owns", "Enable referenceTarget support for aria-owns and ariaOwnsElements") \
    macro(ShadowRootReferenceTargetEnabled, shadowRootReferenceTargetEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShadowRootReferenceTargetEnabled, "referenceTarget", "Enable setting a referenceTarget on shadow roots") \
    macro(RequestIdleCallbackEnabled, requestIdleCallbackEnabled, Bool, bool, DEFAULT_VALUE_FOR_RequestIdleCallbackEnabled, "requestIdleCallback", "Enable requestIdleCallback support") \
    macro(RequestStorageAccessThrowsExceptionUntilReload, requestStorageAccessThrowsExceptionUntilReload, Bool, bool, DEFAULT_VALUE_FOR_RequestStorageAccessThrowsExceptionUntilReload, "requestStorageAccess throws execption until reload", "requestStorageAccess throws execption until reload") \
    macro(ScrollendEventEnabled, scrollendEventEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollendEventEnabled, "scrollend event", "Enable scrollend event") \
    macro(CSSWordBreakAutoPhraseEnabled, cssWordBreakAutoPhraseEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSWordBreakAutoPhraseEnabled, "word-break: auto-phrase enabled", "Enables the auto-phrase value of the word-break CSS property") \
    \


#define FOR_EACH_WEBKIT_PREFERENCE_WITH_INSPECTOR_OVERRIDE(macro) \
    macro(WebSecurityEnabled, webSecurityEnabled, bool) \
    macro(AuthorAndUserStylesEnabled, authorAndUserStylesEnabled, bool) \
    macro(CompositingBordersVisible, compositingBordersVisible, bool) \
    macro(CompositingRepaintCountersVisible, compositingRepaintCountersVisible, bool) \
    macro(ICECandidateFilteringEnabled, iceCandidateFilteringEnabled, bool) \
    macro(MockCaptureDevicesEnabled, mockCaptureDevicesEnabled, bool) \
    macro(JavaScriptEnabled, javaScriptEnabled, bool) \
    macro(MediaCaptureRequiresSecureConnection, mediaCaptureRequiresSecureConnection, bool) \
    macro(NeedsSiteSpecificQuirks, needsSiteSpecificQuirks, bool) \
    macro(ShowFrameProcessBordersEnabled, showFrameProcessBordersEnabled, bool) \
    \


#define FOR_EACH_PERSISTENT_WEBKIT_PREFERENCE(macro) \
    macro(DatabasesEnabled, databasesEnabled, Bool, bool, DEFAULT_VALUE_FOR_DatabasesEnabled, "", "") \
    macro(LoadDeferringEnabled, loadDeferringEnabled, Bool, bool, DEFAULT_VALUE_FOR_LoadDeferringEnabled, "", "") \
    macro(AcceleratedCompositingEnabled, acceleratedCompositingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AcceleratedCompositingEnabled, "", "") \
    macro(AcceleratedCompositingForFixedPositionEnabled, acceleratedCompositingForFixedPositionEnabled, Bool, bool, DEFAULT_VALUE_FOR_AcceleratedCompositingForFixedPositionEnabled, "", "") \
    macro(WirelessPlaybackTargetAPIEnabled, wirelessPlaybackTargetAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_WirelessPlaybackTargetAPIEnabled, "", "") \
    macro(LoadsImagesAutomatically, loadsImagesAutomatically, Bool, bool, DEFAULT_VALUE_FOR_LoadsImagesAutomatically, "", "") \
    macro(LinkPreconnect, linkPreconnect, Bool, bool, DEFAULT_VALUE_FOR_LinkPreconnect, "", "") \
    macro(LongRunningMediaCaptureStreamRepromptIntervalInHours, longRunningMediaCaptureStreamRepromptIntervalInHours, Double, double, DEFAULT_VALUE_FOR_LongRunningMediaCaptureStreamRepromptIntervalInHours, "", "") \
    macro(WindowFocusRestricted, windowFocusRestricted, Bool, bool, DEFAULT_VALUE_FOR_WindowFocusRestricted, "", "") \
    macro(AggressiveTileRetentionEnabled, aggressiveTileRetentionEnabled, Bool, bool, DEFAULT_VALUE_FOR_AggressiveTileRetentionEnabled, "", "") \
    macro(AllowContentSecurityPolicySourceStarToMatchAnyProtocol, allowContentSecurityPolicySourceStarToMatchAnyProtocol, Bool, bool, DEFAULT_VALUE_FOR_AllowContentSecurityPolicySourceStarToMatchAnyProtocol, "", "") \
    macro(AllowDisplayOfInsecureContent, allowDisplayOfInsecureContent, Bool, bool, DEFAULT_VALUE_FOR_AllowDisplayOfInsecureContent, "", "") \
    macro(AllowFileAccessFromFileURLs, allowFileAccessFromFileURLs, Bool, bool, DEFAULT_VALUE_FOR_AllowFileAccessFromFileURLs, "", "") \
    macro(LowPowerVideoAudioBufferSizeEnabled, lowPowerVideoAudioBufferSizeEnabled, Bool, bool, DEFAULT_VALUE_FOR_LowPowerVideoAudioBufferSizeEnabled, "", "") \
    macro(AllowMultiElementImplicitSubmission, allowMultiElementImplicitSubmission, Bool, bool, DEFAULT_VALUE_FOR_AllowMultiElementImplicitSubmission, "", "") \
    macro(ManagedMediaSourceHighThreshold, managedMediaSourceHighThreshold, Double, double, DEFAULT_VALUE_FOR_ManagedMediaSourceHighThreshold, "", "") \
    macro(AllowRunningOfInsecureContent, allowRunningOfInsecureContent, Bool, bool, DEFAULT_VALUE_FOR_AllowRunningOfInsecureContent, "", "") \
    macro(AllowTestOnlyIPC, allowTestOnlyIPC, Bool, bool, DEFAULT_VALUE_FOR_AllowTestOnlyIPC, "", "") \
    macro(ManagedMediaSourceLowThreshold, managedMediaSourceLowThreshold, Double, double, DEFAULT_VALUE_FOR_ManagedMediaSourceLowThreshold, "", "") \
    macro(MathMLEnabled, mathMLEnabled, Bool, bool, DEFAULT_VALUE_FOR_MathMLEnabled, "", "") \
    macro(MaxParseDuration, maxParseDuration, Double, double, DEFAULT_VALUE_FOR_MaxParseDuration, "", "") \
    macro(MediaAudioCodecIDsAllowedInLockdownMode, mediaAudioCodecIDsAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaAudioCodecIDsAllowedInLockdownMode, "", "") \
    macro(AllowsAirPlayForMediaPlayback, allowsAirPlayForMediaPlayback, Bool, bool, DEFAULT_VALUE_FOR_AllowsAirPlayForMediaPlayback, "", "") \
    macro(AllowsInlineMediaPlayback, allowsInlineMediaPlayback, Bool, bool, DEFAULT_VALUE_FOR_AllowsInlineMediaPlayback, "", "") \
    macro(AllowsInlineMediaPlaybackAfterFullscreen, allowsInlineMediaPlaybackAfterFullscreen, Bool, bool, DEFAULT_VALUE_FOR_AllowsInlineMediaPlaybackAfterFullscreen, "", "") \
    macro(AllowsPictureInPictureMediaPlayback, allowsPictureInPictureMediaPlayback, Bool, bool, DEFAULT_VALUE_FOR_AllowsPictureInPictureMediaPlayback, "", "") \
    macro(AlternateFullScreenControlDesignEnabled, alternateFullScreenControlDesignEnabled, Bool, bool, DEFAULT_VALUE_FOR_AlternateFullScreenControlDesignEnabled, "", "") \
    macro(WebSocketEnabled, webSocketEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebSocketEnabled, "", "") \
    macro(MediaCapabilitiesEnabled, mediaCapabilitiesEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaCapabilitiesEnabled, "", "") \
    macro(WebSecurityEnabled, webSecurityEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebSecurityEnabled, "", "") \
    macro(AnimatedImageAsyncDecodingEnabled, animatedImageAsyncDecodingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AnimatedImageAsyncDecodingEnabled, "", "") \
    macro(LayoutViewportHeightExpansionFactor, layoutViewportHeightExpansionFactor, Double, double, DEFAULT_VALUE_FOR_LayoutViewportHeightExpansionFactor, "", "") \
    macro(LayoutFallbackWidth, layoutFallbackWidth, UInt32, uint32_t, DEFAULT_VALUE_FOR_LayoutFallbackWidth, "", "") \
    macro(AppleMailPaginationQuirkEnabled, appleMailPaginationQuirkEnabled, Bool, bool, DEFAULT_VALUE_FOR_AppleMailPaginationQuirkEnabled, "", "") \
    macro(ApplePayCapabilityDisclosureAllowed, applePayCapabilityDisclosureAllowed, Bool, bool, DEFAULT_VALUE_FOR_ApplePayCapabilityDisclosureAllowed, "", "") \
    macro(ApplePayEnabled, applePayEnabled, Bool, bool, DEFAULT_VALUE_FOR_ApplePayEnabled, "", "") \
    macro(LargeImageAsyncDecodingEnabled, largeImageAsyncDecodingEnabled, Bool, bool, DEFAULT_VALUE_FOR_LargeImageAsyncDecodingEnabled, "", "") \
    macro(MediaCaptionFormatTypesAllowedInLockdownMode, mediaCaptionFormatTypesAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaCaptionFormatTypesAllowedInLockdownMode, "", "") \
    macro(JavaScriptRuntimeFlags, javaScriptRuntimeFlags, UInt32, uint32_t, DEFAULT_VALUE_FOR_JavaScriptRuntimeFlags, "", "") \
    macro(AsynchronousSpellCheckingEnabled, asynchronousSpellCheckingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AsynchronousSpellCheckingEnabled, "", "") \
    macro(JavaScriptMarkupEnabled, javaScriptMarkupEnabled, Bool, bool, DEFAULT_VALUE_FOR_JavaScriptMarkupEnabled, "", "") \
    macro(MediaCodecTypesAllowedInLockdownMode, mediaCodecTypesAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaCodecTypesAllowedInLockdownMode, "", "") \
    macro(AudioControlsScaleWithPageZoom, audioControlsScaleWithPageZoom, Bool, bool, DEFAULT_VALUE_FOR_AudioControlsScaleWithPageZoom, "", "") \
    macro(JavaScriptCanOpenWindowsAutomatically, javaScriptCanOpenWindowsAutomatically, Bool, bool, DEFAULT_VALUE_FOR_JavaScriptCanOpenWindowsAutomatically, "", "") \
    macro(AuthorAndUserStylesEnabled, authorAndUserStylesEnabled, Bool, bool, DEFAULT_VALUE_FOR_AuthorAndUserStylesEnabled, "", "") \
    macro(WebAudioEnabled, webAudioEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAudioEnabled, "", "") \
    macro(JavaScriptCanAccessClipboard, javaScriptCanAccessClipboard, Bool, bool, DEFAULT_VALUE_FOR_JavaScriptCanAccessClipboard, "", "") \
    macro(WantsBalancedSetDefersLoadingBehavior, wantsBalancedSetDefersLoadingBehavior, Bool, bool, DEFAULT_VALUE_FOR_WantsBalancedSetDefersLoadingBehavior, "", "") \
    macro(VisualViewportEnabled, visualViewportEnabled, Bool, bool, DEFAULT_VALUE_FOR_VisualViewportEnabled, "", "") \
    macro(VisibleDebugOverlayRegions, visibleDebugOverlayRegions, UInt32, uint32_t, DEFAULT_VALUE_FOR_VisibleDebugOverlayRegions, "", "") \
    macro(VideoQualityIncludesDisplayCompositingEnabled, videoQualityIncludesDisplayCompositingEnabled, Bool, bool, DEFAULT_VALUE_FOR_VideoQualityIncludesDisplayCompositingEnabled, "", "") \
    macro(BackspaceKeyNavigationEnabled, backspaceKeyNavigationEnabled, Bool, bool, DEFAULT_VALUE_FOR_BackspaceKeyNavigationEnabled, "", "") \
    macro(MediaContainerTypesAllowedInLockdownMode, mediaContainerTypesAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaContainerTypesAllowedInLockdownMode, "", "") \
    macro(MediaContentTypesRequiringHardwareSupport, mediaContentTypesRequiringHardwareSupport, String, String, DEFAULT_VALUE_FOR_MediaContentTypesRequiringHardwareSupport, "", "") \
    macro(VideoPresentationModeAPIEnabled, videoPresentationModeAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_VideoPresentationModeAPIEnabled, "", "") \
    macro(MediaControlsContextMenusEnabled, mediaControlsContextMenusEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaControlsContextMenusEnabled, "", "") \
    macro(VideoPresentationManagerEnabled, videoPresentationManagerEnabled, Bool, bool, DEFAULT_VALUE_FOR_VideoPresentationManagerEnabled, "", "") \
    macro(MediaControlsScaleWithPageZoom, mediaControlsScaleWithPageZoom, Bool, bool, DEFAULT_VALUE_FOR_MediaControlsScaleWithPageZoom, "", "") \
    macro(VideoFullscreenRequiresElementFullscreen, videoFullscreenRequiresElementFullscreen, Bool, bool, DEFAULT_VALUE_FOR_VideoFullscreenRequiresElementFullscreen, "", "") \
    macro(MediaDataLoadsAutomatically, mediaDataLoadsAutomatically, Bool, bool, DEFAULT_VALUE_FOR_MediaDataLoadsAutomatically, "", "") \
    macro(MediaPreferredFullscreenWidth, mediaPreferredFullscreenWidth, Double, double, DEFAULT_VALUE_FOR_MediaPreferredFullscreenWidth, "", "") \
    macro(MediaPreloadingEnabled, mediaPreloadingEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaPreloadingEnabled, "", "") \
    macro(InvisibleAutoplayNotPermitted, invisibleAutoplayNotPermitted, Bool, bool, DEFAULT_VALUE_FOR_InvisibleAutoplayNotPermitted, "", "") \
    macro(InterruptVideoOnPageVisibilityChangeEnabled, interruptVideoOnPageVisibilityChangeEnabled, Bool, bool, DEFAULT_VALUE_FOR_InterruptVideoOnPageVisibilityChangeEnabled, "", "") \
    macro(InterruptAudioOnPageVisibilityChangeEnabled, interruptAudioOnPageVisibilityChangeEnabled, Bool, bool, DEFAULT_VALUE_FOR_InterruptAudioOnPageVisibilityChangeEnabled, "", "") \
    macro(VP9DecoderEnabled, vp9DecoderEnabled, Bool, bool, DEFAULT_VALUE_FOR_VP9DecoderEnabled, "", "") \
    macro(MediaUserGestureInheritsFromDocument, mediaUserGestureInheritsFromDocument, Bool, bool, DEFAULT_VALUE_FOR_MediaUserGestureInheritsFromDocument, "", "") \
    macro(MediaVideoCodecIDsAllowedInLockdownMode, mediaVideoCodecIDsAllowedInLockdownMode, String, String, DEFAULT_VALUE_FOR_MediaVideoCodecIDsAllowedInLockdownMode, "", "") \
    macro(InteractionRegionMinimumCornerRadius, interactionRegionMinimumCornerRadius, Double, double, DEFAULT_VALUE_FOR_InteractionRegionMinimumCornerRadius, "", "") \
    macro(InteractionRegionInlinePadding, interactionRegionInlinePadding, Double, double, DEFAULT_VALUE_FOR_InteractionRegionInlinePadding, "", "") \
    macro(InspectorWindowFrame, inspectorWindowFrame, String, String, DEFAULT_VALUE_FOR_InspectorWindowFrame, "", "") \
    macro(InspectorSupportsShowingCertificate, inspectorSupportsShowingCertificate, Bool, bool, DEFAULT_VALUE_FOR_InspectorSupportsShowingCertificate, "", "") \
    macro(InspectorStartsAttached, inspectorStartsAttached, Bool, bool, DEFAULT_VALUE_FOR_InspectorStartsAttached, "", "") \
    macro(InspectorMaximumResourcesContentSize, inspectorMaximumResourcesContentSize, UInt32, uint32_t, DEFAULT_VALUE_FOR_InspectorMaximumResourcesContentSize, "", "") \
    macro(InspectorAttachmentSide, inspectorAttachmentSide, UInt32, uint32_t, DEFAULT_VALUE_FOR_InspectorAttachmentSide, "", "") \
    macro(InspectorAttachedWidth, inspectorAttachedWidth, UInt32, uint32_t, DEFAULT_VALUE_FOR_InspectorAttachedWidth, "", "") \
    macro(InspectorAttachedHeight, inspectorAttachedHeight, UInt32, uint32_t, DEFAULT_VALUE_FOR_InspectorAttachedHeight, "", "") \
    macro(MinimumFontSize, minimumFontSize, Double, double, DEFAULT_VALUE_FOR_MinimumFontSize, "", "") \
    macro(MinimumLogicalFontSize, minimumLogicalFontSize, Double, double, DEFAULT_VALUE_FOR_MinimumLogicalFontSize, "", "") \
    macro(MinimumZoomFontSize, minimumZoomFontSize, Double, double, DEFAULT_VALUE_FOR_MinimumZoomFontSize, "", "") \
    macro(MockCaptureDevicesPromptEnabled, mockCaptureDevicesPromptEnabled, Bool, bool, DEFAULT_VALUE_FOR_MockCaptureDevicesPromptEnabled, "", "") \
    macro(MockScrollbarsControllerEnabled, mockScrollbarsControllerEnabled, Bool, bool, DEFAULT_VALUE_FOR_MockScrollbarsControllerEnabled, "", "") \
    macro(MockScrollbarsEnabled, mockScrollbarsEnabled, Bool, bool, DEFAULT_VALUE_FOR_MockScrollbarsEnabled, "", "") \
    macro(InlineMediaPlaybackRequiresPlaysInlineAttribute, inlineMediaPlaybackRequiresPlaysInlineAttribute, Bool, bool, DEFAULT_VALUE_FOR_InlineMediaPlaybackRequiresPlaysInlineAttribute, "", "") \
    macro(IncrementalRenderingSuppressionTimeout, incrementalRenderingSuppressionTimeout, Double, double, DEFAULT_VALUE_FOR_IncrementalRenderingSuppressionTimeout, "", "") \
    macro(IncrementalPDFLoadingEnabled, incrementalPDFLoadingEnabled, Bool, bool, DEFAULT_VALUE_FOR_IncrementalPDFLoadingEnabled, "", "") \
    macro(IncompleteImageBorderEnabled, incompleteImageBorderEnabled, Bool, bool, DEFAULT_VALUE_FOR_IncompleteImageBorderEnabled, "", "") \
    macro(NeedsAdobeFrameReloadingQuirk, needsAdobeFrameReloadingQuirk, Bool, bool, DEFAULT_VALUE_FOR_NeedsAdobeFrameReloadingQuirk, "", "") \
    macro(InactiveMediaCaptureStreamRepromptIntervalInMinutes, inactiveMediaCaptureStreamRepromptIntervalInMinutes, Double, double, DEFAULT_VALUE_FOR_InactiveMediaCaptureStreamRepromptIntervalInMinutes, "", "") \
    macro(NeedsFrameNameFallbackToIdQuirk, needsFrameNameFallbackToIdQuirk, Bool, bool, DEFAULT_VALUE_FOR_NeedsFrameNameFallbackToIdQuirk, "", "") \
    macro(NeedsKeyboardEventDisambiguationQuirks, needsKeyboardEventDisambiguationQuirks, Bool, bool, DEFAULT_VALUE_FOR_NeedsKeyboardEventDisambiguationQuirks, "", "") \
    macro(PDFPluginEnabled, pdfPluginEnabled, Bool, bool, DEFAULT_VALUE_FOR_PDFPluginEnabled, "", "") \
    macro(PDFPluginHUDEnabled, pdfPluginHUDEnabled, Bool, bool, DEFAULT_VALUE_FOR_PDFPluginHUDEnabled, "", "") \
    macro(PDFPluginPageNumberIndicatorEnabled, pdfPluginPageNumberIndicatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_PDFPluginPageNumberIndicatorEnabled, "", "") \
    macro(PassiveTouchListenersAsDefaultOnDocument, passiveTouchListenersAsDefaultOnDocument, Bool, bool, DEFAULT_VALUE_FOR_PassiveTouchListenersAsDefaultOnDocument, "", "") \
    macro(PasswordEchoDuration, passwordEchoDuration, Double, double, DEFAULT_VALUE_FOR_PasswordEchoDuration, "", "") \
    macro(PasswordEchoEnabled, passwordEchoEnabled, Bool, bool, DEFAULT_VALUE_FOR_PasswordEchoEnabled, "", "") \
    macro(PictographFontFamily, pictographFontFamily, String, String, DEFAULT_VALUE_FOR_PictographFontFamily, "", "") \
    macro(PictureInPictureAPIEnabled, pictureInPictureAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_PictureInPictureAPIEnabled, "", "") \
    macro(PitchCorrectionAlgorithm, pitchCorrectionAlgorithm, UInt32, uint32_t, DEFAULT_VALUE_FOR_PitchCorrectionAlgorithm, "", "") \
    macro(PunchOutWhiteBackgroundsInDarkMode, punchOutWhiteBackgroundsInDarkMode, Bool, bool, DEFAULT_VALUE_FOR_PunchOutWhiteBackgroundsInDarkMode, "", "") \
    macro(RequiresPageVisibilityForVideoToBeNowPlaying, requiresPageVisibilityForVideoToBeNowPlaying, Bool, bool, DEFAULT_VALUE_FOR_RequiresPageVisibilityForVideoToBeNowPlaying, "", "") \
    macro(RequiresPageVisibilityToPlayAudio, requiresPageVisibilityToPlayAudio, Bool, bool, DEFAULT_VALUE_FOR_RequiresPageVisibilityToPlayAudio, "", "") \
    macro(HiddenPageCSSAnimationSuspensionEnabled, hiddenPageCSSAnimationSuspensionEnabled, Bool, bool, DEFAULT_VALUE_FOR_HiddenPageCSSAnimationSuspensionEnabled, "", "") \
    macro(RequiresUserGestureForAudioPlayback, requiresUserGestureForAudioPlayback, Bool, bool, DEFAULT_VALUE_FOR_RequiresUserGestureForAudioPlayback, "", "") \
    macro(RequiresUserGestureForMediaPlayback, requiresUserGestureForMediaPlayback, Bool, bool, DEFAULT_VALUE_FOR_RequiresUserGestureForMediaPlayback, "", "") \
    macro(RequiresUserGestureForVideoPlayback, requiresUserGestureForVideoPlayback, Bool, bool, DEFAULT_VALUE_FOR_RequiresUserGestureForVideoPlayback, "", "") \
    macro(RequiresUserGestureToLoadVideo, requiresUserGestureToLoadVideo, Bool, bool, DEFAULT_VALUE_FOR_RequiresUserGestureToLoadVideo, "", "") \
    macro(UsesSingleWebProcess, usesSingleWebProcess, Bool, bool, DEFAULT_VALUE_FOR_UsesSingleWebProcess, "", "") \
    macro(RubberBandingForSubScrollableRegionsEnabled, rubberBandingForSubScrollableRegionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_RubberBandingForSubScrollableRegionsEnabled, "", "") \
    macro(SampledPageTopColorMaxDifference, sampledPageTopColorMaxDifference, Double, double, DEFAULT_VALUE_FOR_SampledPageTopColorMaxDifference, "", "") \
    macro(SampledPageTopColorMinHeight, sampledPageTopColorMinHeight, Double, double, DEFAULT_VALUE_FOR_SampledPageTopColorMinHeight, "", "") \
    macro(UsesEncodingDetector, usesEncodingDetector, Bool, bool, DEFAULT_VALUE_FOR_UsesEncodingDetector, "", "") \
    macro(SansSerifFontFamily, sansSerifFontFamily, String, String, DEFAULT_VALUE_FOR_SansSerifFontFamily, "", "") \
    macro(SelectTrailingWhitespaceEnabled, selectTrailingWhitespaceEnabled, Bool, bool, DEFAULT_VALUE_FOR_SelectTrailingWhitespaceEnabled, "", "") \
    macro(SerifFontFamily, serifFontFamily, String, String, DEFAULT_VALUE_FOR_SerifFontFamily, "", "") \
    macro(UsesBackForwardCache, usesBackForwardCache, Bool, bool, DEFAULT_VALUE_FOR_UsesBackForwardCache, "", "") \
    macro(UserInterfaceDirectionPolicy, userInterfaceDirectionPolicy, UInt32, uint32_t, DEFAULT_VALUE_FOR_UserInterfaceDirectionPolicy, "", "") \
    macro(CaretBrowsingEnabled, caretBrowsingEnabled, Bool, bool, DEFAULT_VALUE_FOR_CaretBrowsingEnabled, "", "") \
    macro(UseSystemAppearance, useSystemAppearance, Bool, bool, DEFAULT_VALUE_FOR_UseSystemAppearance, "", "") \
    macro(ServiceControlsEnabled, serviceControlsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ServiceControlsEnabled, "", "") \
    macro(GStreamerEnabled, isGStreamerEnabled, Bool, bool, DEFAULT_VALUE_FOR_GStreamerEnabled, "", "") \
    macro(ServiceWorkerEntitlementDisabledForTesting, serviceWorkerEntitlementDisabledForTesting, Bool, bool, DEFAULT_VALUE_FOR_ServiceWorkerEntitlementDisabledForTesting, "", "") \
    macro(ShouldAllowUserInstalledFonts, shouldAllowUserInstalledFonts, Bool, bool, DEFAULT_VALUE_FOR_ShouldAllowUserInstalledFonts, "", "") \
    macro(ColorFilterEnabled, colorFilterEnabled, Bool, bool, DEFAULT_VALUE_FOR_ColorFilterEnabled, "", "") \
    macro(UsePreHTML5ParserQuirks, usePreHTML5ParserQuirks, Bool, bool, DEFAULT_VALUE_FOR_UsePreHTML5ParserQuirks, "", "") \
    macro(ShouldConvertInvalidURLsToBlank, shouldConvertInvalidURLsToBlank, Bool, bool, DEFAULT_VALUE_FOR_ShouldConvertInvalidURLsToBlank, "", "") \
    macro(ShouldConvertPositionStyleOnCopy, shouldConvertPositionStyleOnCopy, Bool, bool, DEFAULT_VALUE_FOR_ShouldConvertPositionStyleOnCopy, "", "") \
    macro(ShouldDecidePolicyBeforeLoadingQuickLookPreview, shouldDecidePolicyBeforeLoadingQuickLookPreview, Bool, bool, DEFAULT_VALUE_FOR_ShouldDecidePolicyBeforeLoadingQuickLookPreview, "", "") \
    macro(ShouldDisplayCaptions, shouldDisplayCaptions, Bool, bool, DEFAULT_VALUE_FOR_ShouldDisplayCaptions, "", "") \
    macro(ContentChangeObserverEnabled, contentChangeObserverEnabled, Bool, bool, DEFAULT_VALUE_FOR_ContentChangeObserverEnabled, "", "") \
    macro(ContentDispositionAttachmentSandboxEnabled, contentDispositionAttachmentSandboxEnabled, Bool, bool, DEFAULT_VALUE_FOR_ContentDispositionAttachmentSandboxEnabled, "", "") \
    macro(ForceWebGLUsesLowPower, forceWebGLUsesLowPower, Bool, bool, DEFAULT_VALUE_FOR_ForceWebGLUsesLowPower, "", "") \
    macro(ContextMenuQRCodeDetectionEnabled, contextMenuQRCodeDetectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_ContextMenuQRCodeDetectionEnabled, "", "") \
    macro(ShouldDisplaySubtitles, shouldDisplaySubtitles, Bool, bool, DEFAULT_VALUE_FOR_ShouldDisplaySubtitles, "", "") \
    macro(ForceFTPDirectoryListings, forceFTPDirectoryListings, Bool, bool, DEFAULT_VALUE_FOR_ForceFTPDirectoryListings, "", "") \
    macro(ForceCompositingMode, forceCompositingMode, Bool, bool, DEFAULT_VALUE_FOR_ForceCompositingMode, "", "") \
    macro(ShouldDisplayTextDescriptions, shouldDisplayTextDescriptions, Bool, bool, DEFAULT_VALUE_FOR_ShouldDisplayTextDescriptions, "", "") \
    macro(ShouldEnableTextAutosizingBoost, shouldEnableTextAutosizingBoost, Bool, bool, DEFAULT_VALUE_FOR_ShouldEnableTextAutosizingBoost, "", "") \
    macro(UseImageDocumentForSubframePDF, useImageDocumentForSubframePDF, Bool, bool, DEFAULT_VALUE_FOR_UseImageDocumentForSubframePDF, "", "") \
    macro(FixedFontFamily, fixedFontFamily, String, String, DEFAULT_VALUE_FOR_FixedFontFamily, "", "") \
    macro(ShouldIgnoreMetaViewport, shouldIgnoreMetaViewport, Bool, bool, DEFAULT_VALUE_FOR_ShouldIgnoreMetaViewport, "", "") \
    macro(ShouldPrintBackgrounds, shouldPrintBackgrounds, Bool, bool, DEFAULT_VALUE_FOR_ShouldPrintBackgrounds, "", "") \
    macro(CursiveFontFamily, cursiveFontFamily, String, String, DEFAULT_VALUE_FOR_CursiveFontFamily, "", "") \
    macro(ShouldRespectImageOrientation, shouldRespectImageOrientation, Bool, bool, DEFAULT_VALUE_FOR_ShouldRespectImageOrientation, "", "") \
    macro(ShouldRestrictBaseURLSchemes, shouldRestrictBaseURLSchemes, Bool, bool, DEFAULT_VALUE_FOR_ShouldRestrictBaseURLSchemes, "", "") \
    macro(ShouldSuppressTextInputFromEditingDuringProvisionalNavigation, shouldSuppressTextInputFromEditingDuringProvisionalNavigation, Bool, bool, DEFAULT_VALUE_FOR_ShouldSuppressTextInputFromEditingDuringProvisionalNavigation, "", "") \
    macro(FantasyFontFamily, fantasyFontFamily, String, String, DEFAULT_VALUE_FOR_FantasyFontFamily, "", "") \
    macro(DOMPasteAllowed, domPasteAllowed, Bool, bool, DEFAULT_VALUE_FOR_DOMPasteAllowed, "", "") \
    macro(ShouldUseServiceWorkerShortTimeout, shouldUseServiceWorkerShortTimeout, Bool, bool, DEFAULT_VALUE_FOR_ShouldUseServiceWorkerShortTimeout, "", "") \
    macro(FTPDirectoryTemplatePath, ftpDirectoryTemplatePath, String, String, DEFAULT_VALUE_FOR_FTPDirectoryTemplatePath, "", "") \
    macro(DataDetectorTypes, dataDetectorTypes, UInt32, uint32_t, DEFAULT_VALUE_FOR_DataDetectorTypes, "", "") \
    macro(ExtensibleSSOEnabled, isExtensibleSSOEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExtensibleSSOEnabled, "", "") \
    macro(TreatsAnyTextCSSLinkAsStylesheet, treatsAnyTextCSSLinkAsStylesheet, Bool, bool, DEFAULT_VALUE_FOR_TreatsAnyTextCSSLinkAsStylesheet, "", "") \
    macro(LinkPreloadEnabled, linkPreloadEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinkPreloadEnabled, "", "") \
    macro(ShowsToolTipOverTruncatedText, showsToolTipOverTruncatedText, Bool, bool, DEFAULT_VALUE_FOR_ShowsToolTipOverTruncatedText, "", "") \
    macro(ThreadedScrollingEnabled, threadedScrollingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ThreadedScrollingEnabled, "", "") \
    macro(DefaultFixedFontSize, defaultFixedFontSize, Double, double, DEFAULT_VALUE_FOR_DefaultFixedFontSize, "", "") \
    macro(DefaultFontSize, defaultFontSize, Double, double, DEFAULT_VALUE_FOR_DefaultFontSize, "", "") \
    macro(DefaultTextEncodingName, defaultTextEncodingName, String, String, DEFAULT_VALUE_FOR_DefaultTextEncodingName, "", "") \
    macro(TextInteractionEnabled, textInteractionEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextInteractionEnabled, "", "") \
    macro(TextExtractionEnabled, textExtractionEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextExtractionEnabled, "", "") \
    macro(TextAutosizingEnabled, textAutosizingEnabled, Bool, bool, DEFAULT_VALUE_FOR_TextAutosizingEnabled, "", "") \
    macro(DeveloperExtrasEnabled, developerExtrasEnabled, Bool, bool, DEFAULT_VALUE_FOR_DeveloperExtrasEnabled, "", "") \
    macro(DeviceHeight, deviceHeight, UInt32, uint32_t, DEFAULT_VALUE_FOR_DeviceHeight, "", "") \
    macro(DeviceOrientationEventEnabled, deviceOrientationEventEnabled, Bool, bool, DEFAULT_VALUE_FOR_DeviceOrientationEventEnabled, "", "") \
    macro(DeviceOrientationPermissionAPIEnabled, deviceOrientationPermissionAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_DeviceOrientationPermissionAPIEnabled, "", "") \
    macro(DeviceWidth, deviceWidth, UInt32, uint32_t, DEFAULT_VALUE_FOR_DeviceWidth, "", "") \
    macro(ShowsURLsInToolTipsEnabled, showsURLsInToolTipsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShowsURLsInToolTipsEnabled, "", "") \
    macro(TextAreasAreResizable, textAreasAreResizable, Bool, bool, DEFAULT_VALUE_FOR_TextAreasAreResizable, "", "") \
    macro(TemporaryTileCohortRetentionEnabled, temporaryTileCohortRetentionEnabled, Bool, bool, DEFAULT_VALUE_FOR_TemporaryTileCohortRetentionEnabled, "", "") \
    macro(TelephoneNumberParsingEnabled, telephoneNumberParsingEnabled, Bool, bool, DEFAULT_VALUE_FOR_TelephoneNumberParsingEnabled, "", "") \
    macro(ShrinksStandaloneImagesToFit, shrinksStandaloneImagesToFit, Bool, bool, DEFAULT_VALUE_FOR_ShrinksStandaloneImagesToFit, "", "") \
    macro(DisabledAdaptationsMetaTagEnabled, disabledAdaptationsMetaTagEnabled, Bool, bool, DEFAULT_VALUE_FOR_DisabledAdaptationsMetaTagEnabled, "", "") \
    macro(DownloadAttributeEnabled, downloadAttributeEnabled, Bool, bool, DEFAULT_VALUE_FOR_DownloadAttributeEnabled, "", "") \
    macro(TabsToLinks, tabsToLinks, Bool, bool, DEFAULT_VALUE_FOR_TabsToLinks, "", "") \
    macro(EditableLinkBehavior, editableLinkBehavior, UInt32, uint32_t, DEFAULT_VALUE_FOR_EditableLinkBehavior, "", "") \
    macro(SystemPreviewEnabled, systemPreviewEnabled, Bool, bool, DEFAULT_VALUE_FOR_SystemPreviewEnabled, "", "") \
    macro(SystemLayoutDirection, systemLayoutDirection, UInt32, uint32_t, DEFAULT_VALUE_FOR_SystemLayoutDirection, "", "") \
    macro(SuppressesIncrementalRendering, suppressesIncrementalRendering, Bool, bool, DEFAULT_VALUE_FOR_SuppressesIncrementalRendering, "", "") \
    macro(StandardFontFamily, standardFontFamily, String, String, DEFAULT_VALUE_FOR_StandardFontFamily, "", "") \
    macro(EnableInheritURIQueryComponent, enableInheritURIQueryComponent, Bool, bool, DEFAULT_VALUE_FOR_EnableInheritURIQueryComponent, "", "") \
    macro(EncryptedMediaAPIEnabled, encryptedMediaAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_EncryptedMediaAPIEnabled, "", "") \
    macro(Standalone, standalone, Bool, bool, DEFAULT_VALUE_FOR_Standalone, "", "") \
    macro(SmartInsertDeleteEnabled, smartInsertDeleteEnabled, Bool, bool, DEFAULT_VALUE_FOR_SmartInsertDeleteEnabled, "", "") \
    macro(SpatialNavigationEnabled, spatialNavigationEnabled, Bool, bool, DEFAULT_VALUE_FOR_SpatialNavigationEnabled, "", "") \
    macro(SourceBufferChangeTypeEnabled, sourceBufferChangeTypeEnabled, Bool, bool, DEFAULT_VALUE_FOR_SourceBufferChangeTypeEnabled, "", "") \
    macro(TargetTextPseudoElementEnabled, targetTextPseudoElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_TargetTextPseudoElementEnabled, "::target-text pseudo-element", "Enable the ::target-text CSS pseudo-element") \
    macro(LinkDNSPrefetchEnabled, linkDNSPrefetchEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinkDNSPrefetchEnabled, "<link rel=dns-prefetch>", "Enable <link rel=dns-prefetch>") \
    macro(PageAtRuleMarginDescriptorsEnabled, pageAtRuleMarginDescriptorsEnabled, Bool, bool, DEFAULT_VALUE_FOR_PageAtRuleMarginDescriptorsEnabled, "@page CSS at-rule margin descriptors", "Enable support for @page margin descriptors") \
    macro(AVFoundationEnabled, isAVFoundationEnabled, Bool, bool, DEFAULT_VALUE_FOR_AVFoundationEnabled, "AVFoundation", "Enable AVFoundation") \
    macro(AccessHandleEnabled, accessHandleEnabled, Bool, bool, DEFAULT_VALUE_FOR_AccessHandleEnabled, "AccessHandle API", "Enable AccessHandle API") \
    macro(AllowMediaContentTypesRequiringHardwareSupportAsFallback, allowMediaContentTypesRequiringHardwareSupportAsFallback, Bool, bool, DEFAULT_VALUE_FOR_AllowMediaContentTypesRequiringHardwareSupportAsFallback, "Allow Media Content Types Requirining Hardware As Fallback", "Allow Media Content Types Requirining Hardware As Fallback") \
    macro(AllowPrivacySensitiveOperationsInNonPersistentDataStores, allowPrivacySensitiveOperationsInNonPersistentDataStores, Bool, bool, DEFAULT_VALUE_FOR_AllowPrivacySensitiveOperationsInNonPersistentDataStores, "Allow Privacy-Sensitive Operations in Non-Persistent Data Stores", "Allow Privacy-Sensitive Operations in Non-Persistent Data Stores") \
    macro(AllowWebGLInWorkers, allowWebGLInWorkers, Bool, bool, DEFAULT_VALUE_FOR_AllowWebGLInWorkers, "Allow WebGL in Web Workers", "") \
    macro(AllowTopNavigationToDataURLs, allowTopNavigationToDataURLs, Bool, bool, DEFAULT_VALUE_FOR_AllowTopNavigationToDataURLs, "Allow top navigation to data: URLs", "") \
    macro(AllowUniversalAccessFromFileURLs, allowUniversalAccessFromFileURLs, Bool, bool, DEFAULT_VALUE_FOR_AllowUniversalAccessFromFileURLs, "Allow universal access from file: URLs", "") \
    macro(AsyncClipboardAPIEnabled, asyncClipboardAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_AsyncClipboardAPIEnabled, "Async clipboard API", "Enable the async clipboard API") \
    macro(AttachmentElementEnabled, attachmentElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_AttachmentElementEnabled, "Attachment Element", "Allow the insertion of attachment elements") \
    macro(AttachmentWideLayoutEnabled, attachmentWideLayoutEnabled, Bool, bool, DEFAULT_VALUE_FOR_AttachmentWideLayoutEnabled, "Attachment wide-layout styling", "Use horizontal wide-layout attachment style, requires Attachment Element") \
    macro(ExtendedAudioDescriptionsEnabled, extendedAudioDescriptionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ExtendedAudioDescriptionsEnabled, "Audio descriptions for video - Extended", "Enable extended audio descriptions for video") \
    macro(AudioDescriptionsEnabled, audioDescriptionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_AudioDescriptionsEnabled, "Audio descriptions for video - Standard", "Enable standard audio descriptions for video") \
    macro(DOMAudioSessionEnabled, domAudioSessionEnabled, Bool, bool, DEFAULT_VALUE_FOR_DOMAudioSessionEnabled, "AudioSession API", "Enable AudioSession API") \
    macro(BeaconAPIEnabled, beaconAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_BeaconAPIEnabled, "Beacon API", "Beacon API") \
    macro(BroadcastChannelEnabled, broadcastChannelEnabled, Bool, bool, DEFAULT_VALUE_FOR_BroadcastChannelEnabled, "BroadcastChannel API", "BroadcastChannel API") \
    macro(CSS3DTransformBackfaceVisibilityInteroperabilityEnabled, css3DTransformBackfaceVisibilityInteroperabilityEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSS3DTransformBackfaceVisibilityInteroperabilityEnabled, "CSS 3D Transform Interoperability for backface-visibility", "Enable 3D transform behavior for backface-visibility that is specification-compliant but backwards incompatible") \
    macro(AccentColorEnabled, accentColorEnabled, Bool, bool, DEFAULT_VALUE_FOR_AccentColorEnabled, "CSS Accent Color", "Enable accent-color CSS property") \
    macro(CSSAnchorPositioningEnabled, cssAnchorPositioningEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSAnchorPositioningEnabled, "CSS Anchor Positioning", "Enable CSS Anchor Positioning (except position-visibility)") \
    macro(DevolvableWidgetsEnabled, devolvableWidgetsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DevolvableWidgetsEnabled, "CSS Devolvable Widgets", "Enable support for devolvable widgets") \
    macro(MasonryEnabled, masonryEnabled, Bool, bool, DEFAULT_VALUE_FOR_MasonryEnabled, "CSS Masonry Layout", "Enable Masonry Layout for CSS Grid") \
    macro(OverscrollBehaviorEnabled, overscrollBehaviorEnabled, Bool, bool, DEFAULT_VALUE_FOR_OverscrollBehaviorEnabled, "CSS Overscroll Behavior", "Enable CSS overscroll-behavior") \
    macro(CSSTreeCountingFunctionsEnabled, cssTreeCountingFunctionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTreeCountingFunctionsEnabled, "CSS Tree Counting Functions", "Enable support for CSS Values and Units Module Level 5 tree counting functions sibling-count() and sibling-index()") \
    macro(CSSURLModifiersEnabled, cssURLModifiersEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSURLModifiersEnabled, "CSS URL Modifiers", "Enable support for CSS Values and Units Module Level 5 URL modifiers") \
    macro(CSSUnprefixedBackdropFilterEnabled, cssUnprefixedBackdropFilterEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSUnprefixedBackdropFilterEnabled, "CSS Unprefixed Backdrop Filter", "Enable unprefixed backdrop-filter CSS property") \
    macro(CSSAxisRelativePositionKeywordsEnabled, cssAxisRelativePositionKeywordsEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSAxisRelativePositionKeywordsEnabled, "CSS axis relative keywords in <position>", "Enable support for CSS Values and Units Module Level 5 axis relative keywords in <position>") \
    macro(CSSBackgroundClipBorderAreaEnabled, cssBackgroundClipBorderAreaEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSBackgroundClipBorderAreaEnabled, "CSS background-clip: border-area", "Enable the border-area value for background-clip") \
    macro(CSSColorLayersEnabled, cssColorLayersEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSColorLayersEnabled, "CSS color-layers()", "Enable support for CSS color-layers()") \
    macro(CSSContrastColorEnabled, cssContrastColorEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSContrastColorEnabled, "CSS contrast-color()", "Enable support for CSS Color Module Level 5 contrast-color()") \
    macro(CSSDPropertyEnabled, cssDPropertyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSDPropertyEnabled, "CSS d property", "Enable support for the CSS d property and SVG d presentation attribute") \
    macro(CSSFieldSizingEnabled, cssFieldSizingEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSFieldSizingEnabled, "CSS field-sizing property", "Enable field-sizing CSS property") \
    macro(CSSLineClampEnabled, cssLineClampEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSLineClampEnabled, "CSS line-clamp", "Enable CSS line-clamp") \
    macro(CSSProgressFunctionEnabled, cssProgressFunctionEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSProgressFunctionEnabled, "CSS progress()", "Enable support for CSS Values and Units Module Level 5 progress()") \
    macro(CSSRandomFunctionEnabled, cssRandomFunctionEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSRandomFunctionEnabled, "CSS random()", "Enable support for CSS Values and Units Module Level 5 random()") \
    macro(CSSRubyAlignEnabled, cssRubyAlignEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSRubyAlignEnabled, "CSS ruby-align property", "Enable ruby-align") \
    macro(CSSRubyOverhangEnabled, cssRubyOverhangEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSRubyOverhangEnabled, "CSS ruby-overhang property", "Enable ruby-overhang") \
    macro(CSSScrollbarGutterEnabled, cssScrollbarGutterEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSScrollbarGutterEnabled, "CSS scrollbar-gutter property", "Enable scrollbar-gutter CSS property") \
    macro(CSSScrollbarWidthEnabled, cssScrollbarWidthEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSScrollbarWidthEnabled, "CSS scrollbar-width property", "Enable scrollbar-width CSS property") \
    macro(CSSShapeFunctionEnabled, cssShapeFunctionEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSShapeFunctionEnabled, "CSS shape() function", "Enable the CSS shape() function") \
    macro(CSSTextAutospaceEnabled, cssTextAutospaceEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextAutospaceEnabled, "CSS text-autospace property", "Enable the property text-autospace, defined in CSS Text 4") \
    macro(CSSTextBoxTrimEnabled, cssTextBoxTrimEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextBoxTrimEnabled, "CSS text-box-trim property", "Enable text-box-trim") \
    macro(CSSTextUnderlinePositionLeftRightEnabled, cssTextUnderlinePositionLeftRightEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextUnderlinePositionLeftRightEnabled, "CSS text-underline-position: left right", "Enable the property text-underline-position left and right value support") \
    macro(CSSTextWrapPrettyEnabled, cssTextWrapPrettyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CSSTextWrapPrettyEnabled, "CSS text-wrap: pretty", "Enable the pretty value for text-wrap-style") \
    macro(CacheAPIEnabled, cacheAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_CacheAPIEnabled, "Cache API", "Cache API") \
    macro(CanvasColorSpaceEnabled, canvasColorSpaceEnabled, Bool, bool, DEFAULT_VALUE_FOR_CanvasColorSpaceEnabled, "Canvas Color Spaces", "Enable use of predefined canvas color spaces") \
    macro(CanvasUsesAcceleratedDrawing, canvasUsesAcceleratedDrawing, Bool, bool, DEFAULT_VALUE_FOR_CanvasUsesAcceleratedDrawing, "Canvas uses accelerated drawing", "") \
    macro(ClearSiteDataHTTPHeaderEnabled, clearSiteDataHTTPHeaderEnabled, Bool, bool, DEFAULT_VALUE_FOR_ClearSiteDataHTTPHeaderEnabled, "Clear-Site-Data HTTP Header", "Enable Clear-Site-Data HTTP Header support") \
    macro(InputTypeColorEnabled, inputTypeColorEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeColorEnabled, "Color Inputs", "Enable input elements of type color") \
    macro(CompressionStreamEnabled, compressionStreamEnabled, Bool, bool, DEFAULT_VALUE_FOR_CompressionStreamEnabled, "Compression Stream API", "Enable Compression Stream API") \
    macro(CookieStoreAPIEnabled, cookieStoreAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_CookieStoreAPIEnabled, "Cookie Store API", "Enable Cookie Store API") \
    macro(CookieEnabled, cookieEnabled, Bool, bool, DEFAULT_VALUE_FOR_CookieEnabled, "Cookies Enabled", "") \
    macro(CrossDocumentViewTransitionsEnabled, crossDocumentViewTransitionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_CrossDocumentViewTransitionsEnabled, "Cross document view-transitions", "Enable support for view-transitions cross-document") \
    macro(CrossOriginEmbedderPolicyEnabled, crossOriginEmbedderPolicyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CrossOriginEmbedderPolicyEnabled, "Cross-Origin-Embedder-Policy (COEP) header", "Support for Cross-Origin-Embedder-Policy (COEP) header") \
    macro(CrossOriginOpenerPolicyEnabled, crossOriginOpenerPolicyEnabled, Bool, bool, DEFAULT_VALUE_FOR_CrossOriginOpenerPolicyEnabled, "Cross-Origin-Opener-Policy (COOP) header", "Support for Cross-Origin-Opener-Policy (COOP) header") \
    macro(CustomPasteboardDataEnabled, customPasteboardDataEnabled, Bool, bool, DEFAULT_VALUE_FOR_CustomPasteboardDataEnabled, "Custom pasteboard data", "Enable custom clipboard types and better security model for clipboard API.") \
    macro(DOMTimersThrottlingEnabled, domTimersThrottlingEnabled, Bool, bool, DEFAULT_VALUE_FOR_DOMTimersThrottlingEnabled, "DOM timer throttling enabled", "") \
    macro(DataTransferItemsEnabled, dataTransferItemsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DataTransferItemsEnabled, "Data Transfer Items", "Enables DataTransferItem in the clipboard API") \
    macro(DataListElementEnabled, dataListElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_DataListElementEnabled, "DataList Element", "Enable datalist elements") \
    macro(InputTypeDateEnabled, inputTypeDateEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeDateEnabled, "Date Input", "Enable input elements of type date") \
    macro(DateTimeInputsEditableComponentsEnabled, dateTimeInputsEditableComponentsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DateTimeInputsEditableComponentsEnabled, "Date/Time inputs have editable components", "Enable multiple editable components in date/time inputs") \
    macro(DeclarativeWebPush, declarativeWebPush, Bool, bool, DEFAULT_VALUE_FOR_DeclarativeWebPush, "Declarative Web Push", "Enable Declarative Web Push") \
    macro(ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint, shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint, Bool, bool, DEFAULT_VALUE_FOR_ShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint, "Defer async scripts until DOMContentLoaded or first-paint", "Defer async scripts until DOMContentLoaded or first-paint") \
    macro(DetachableMediaSourceEnabled, detachableMediaSourceEnabled, Bool, bool, DEFAULT_VALUE_FOR_DetachableMediaSourceEnabled, "Detachable Media Source", "Detachable Media Source API") \
    macro(UAVisualTransitionDetectionEnabled, uAVisualTransitionDetectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_UAVisualTransitionDetectionEnabled, "Detect UA visual transitions", "Enable detection of UA visual transitions") \
    macro(DiagnosticLoggingEnabled, diagnosticLoggingEnabled, Bool, bool, DEFAULT_VALUE_FOR_DiagnosticLoggingEnabled, "Diagnostic logging enabled", "") \
    macro(DigitalCredentialsEnabled, digitalCredentialsEnabled, Bool, bool, DEFAULT_VALUE_FOR_DigitalCredentialsEnabled, "Digital Credentials API", "Enable the Digital Credentials API") \
    macro(DirectoryUploadEnabled, directoryUploadEnabled, Bool, bool, DEFAULT_VALUE_FOR_DirectoryUploadEnabled, "Directory Upload", "input.webkitdirectory / dataTransferItem.webkitGetAsEntry()") \
    macro(IsThirdPartyCookieBlockingDisabled, isThirdPartyCookieBlockingDisabled, Bool, bool, DEFAULT_VALUE_FOR_IsThirdPartyCookieBlockingDisabled, "Disable Full 3rd-Party Cookie Blocking (ITP)", "Disable full third-party cookie blocking when Intelligent Tracking Prevention is enabled") \
    macro(IsFirstPartyWebsiteDataRemovalDisabled, isFirstPartyWebsiteDataRemovalDisabled, Bool, bool, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalDisabled, "Disable Removal of Non-Cookie Data After 7 Days of No User Interaction (ITP)", "Disable removal of all non-cookie website data after seven days of no user interaction when Intelligent Tracking Prevention is enabled") \
    macro(EmbedElementEnabled, embedElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_EmbedElementEnabled, "Embed Element", "Embed Element") \
    macro(CanvasFingerprintingQuirkEnabled, canvasFingerprintingQuirkEnabled, Bool, bool, DEFAULT_VALUE_FOR_CanvasFingerprintingQuirkEnabled, "Enable Canvas fingerprinting-related quirk", "") \
    macro(EnableElementCurrentCSSZoom, enableElementCurrentCSSZoom, Bool, bool, DEFAULT_VALUE_FOR_EnableElementCurrentCSSZoom, "Enable Element.currentCSSZoom", "Enable Element.currentCSSZoom") \
    macro(LegacyEncryptedMediaAPIEnabled, legacyEncryptedMediaAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_LegacyEncryptedMediaAPIEnabled, "Enable Legacy EME API", "Enable legacy EME API") \
    macro(ModelProcessEnabled, modelProcessEnabled, Bool, bool, DEFAULT_VALUE_FOR_ModelProcessEnabled, "Enable Model Process", "Load <model> content in a separate process") \
    macro(AuxclickEventEnabled, auxclickEventEnabled, Bool, bool, DEFAULT_VALUE_FOR_AuxclickEventEnabled, "Enable `auxclick` event", "Enable the `auxclick` UI event") \
    macro(BlobFileAccessEnforcementEnabled, blobFileAccessEnforcementEnabled, Bool, bool, DEFAULT_VALUE_FOR_BlobFileAccessEnforcementEnabled, "Enforce blob backed file access valid for web process", "Validate file backed blobs were created by the correct web process") \
    macro(MediaSessionCoordinatorEnabled, mediaSessionCoordinatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSessionCoordinatorEnabled, "Experimental MediaSession coordinator API", "Enable experimental MediaSession coordinator API") \
    macro(MediaSessionPlaylistEnabled, mediaSessionPlaylistEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSessionPlaylistEnabled, "Experimental MediaSession playlist API", "Enable experimental MediaSession playlist API") \
    macro(FTPEnabled, ftpEnabled, Bool, bool, DEFAULT_VALUE_FOR_FTPEnabled, "FTP support enabled", "FTP support enabled") \
    macro(FileSystemEnabled, fileSystemEnabled, Bool, bool, DEFAULT_VALUE_FOR_FileSystemEnabled, "File System API", "Enable File System API") \
    macro(FileSystemWritableStreamEnabled, fileSystemWritableStreamEnabled, Bool, bool, DEFAULT_VALUE_FOR_FileSystemWritableStreamEnabled, "File System WritableStream", "Enable File System WritableStream API") \
    macro(FileReaderAPIEnabled, fileReaderAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_FileReaderAPIEnabled, "FileReader API", "FileReader API") \
    macro(FilterLinkDecorationByDefaultEnabled, filterLinkDecorationByDefaultEnabled, Bool, bool, DEFAULT_VALUE_FOR_FilterLinkDecorationByDefaultEnabled, "Filter Link Decoration", "Enable Filtering Link Decoration") \
    macro(FullScreenEnabled, fullScreenEnabled, Bool, bool, DEFAULT_VALUE_FOR_FullScreenEnabled, "Fullscreen API", "Fullscreen API") \
    macro(UseGPUProcessForCanvasRenderingEnabled, useGPUProcessForCanvasRenderingEnabled, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForCanvasRenderingEnabled, "GPU Process: Canvas Rendering", "Enable canvas rendering in GPU Process") \
    macro(UseGPUProcessForDOMRenderingEnabled, useGPUProcessForDOMRenderingEnabled, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForDOMRenderingEnabled, "GPU Process: DOM Rendering", "Enable DOM rendering in GPU Process") \
    macro(UseGPUProcessForMediaEnabled, useGPUProcessForMediaEnabled, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForMediaEnabled, "GPU Process: Media", "Do all media loading and playback in the GPU Process") \
    macro(UseGPUProcessForDisplayCapture, useGPUProcessForDisplayCapture, Bool, bool, DEFAULT_VALUE_FOR_UseGPUProcessForDisplayCapture, "GPU Process: Screen and Window capture", "Display capture in GPU Process") \
    macro(WebRTCPlatformCodecsInGPUProcessEnabled, webRTCPlatformCodecsInGPUProcessEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCPlatformCodecsInGPUProcessEnabled, "GPU Process: WebRTC Platform Codecs", "Enable WebRTC Platform Codecs in GPU Process") \
    macro(GamepadVibrationActuatorEnabled, gamepadVibrationActuatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_GamepadVibrationActuatorEnabled, "Gamepad.vibrationActuator support", "Support for Gamepad.vibrationActuator") \
    macro(GamepadsEnabled, gamepadsEnabled, Bool, bool, DEFAULT_VALUE_FOR_GamepadsEnabled, "Gamepads", "Web Gamepad API support") \
    macro(GenericCueAPIEnabled, genericCueAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_GenericCueAPIEnabled, "Generic Text Track Cue API", "Enable Generic Text Track Cue API") \
    macro(GeolocationAPIEnabled, geolocationAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_GeolocationAPIEnabled, "Geolocation API", "Enable Geolocation API") \
    macro(GraphicsContextFiltersEnabled, graphicsContextFiltersEnabled, Bool, bool, DEFAULT_VALUE_FOR_GraphicsContextFiltersEnabled, "GraphicsContext Filter Rendering", "GraphicsContext Filter Rendering") \
    macro(ModelElementEnabled, modelElementEnabled, Bool, bool, DEFAULT_VALUE_FOR_ModelElementEnabled, "HTML <model> element", "Enable HTML <model> element") \
    macro(InteractiveFormValidationEnabled, interactiveFormValidationEnabled, Bool, bool, DEFAULT_VALUE_FOR_InteractiveFormValidationEnabled, "HTML Interactive Form Validation", "HTML interactive form validation") \
    macro(MediaEnabled, mediaEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaEnabled, "HTML Media Elements", "Enable HTML media elements <audio>, <video> and <track>") \
    macro(InputTypeColorEnhancementsEnabled, inputTypeColorEnhancementsEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeColorEnhancementsEnabled, "HTML alpha and colorspace attribute support for color inputs", "Enable HTML alpha and colorspace attribute support for input elements of type color") \
    macro(DetailsAutoExpandEnabled, detailsAutoExpandEnabled, Bool, bool, DEFAULT_VALUE_FOR_DetailsAutoExpandEnabled, "HTML auto-expanding <details>", "Enable HTML auto-expanding <details>") \
    macro(CommandAttributesEnabled, commandAttributesEnabled, Bool, bool, DEFAULT_VALUE_FOR_CommandAttributesEnabled, "HTML command & commandfor attributes", "Enable HTML command & commandfor attribute support") \
    macro(PopoverAttributeEnabled, popoverAttributeEnabled, Bool, bool, DEFAULT_VALUE_FOR_PopoverAttributeEnabled, "HTML popover attribute", "Enable HTML popover attribute support") \
    macro(SwitchControlEnabled, switchControlEnabled, Bool, bool, DEFAULT_VALUE_FOR_SwitchControlEnabled, "HTML switch control", "Enable HTML switch control") \
    macro(HiddenPageDOMTimerThrottlingAutoIncreases, hiddenPageDOMTimerThrottlingAutoIncreases, Bool, bool, DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingAutoIncreases, "Hidden page DOM timer throttling auto-increases", "") \
    macro(HiddenPageDOMTimerThrottlingEnabled, hiddenPageDOMTimerThrottlingEnabled, Bool, bool, DEFAULT_VALUE_FOR_HiddenPageDOMTimerThrottlingEnabled, "Hidden page DOM timer throttling", "Enable hidden page DOM timer throttling") \
    macro(ItpDebugModeEnabled, itpDebugModeEnabled, Bool, bool, DEFAULT_VALUE_FOR_ItpDebugModeEnabled, "ITP Debug Mode", "Intelligent Tracking Prevention Debug Mode") \
    macro(TextAutosizingUsesIdempotentMode, textAutosizingUsesIdempotentMode, Bool, bool, DEFAULT_VALUE_FOR_TextAutosizingUsesIdempotentMode, "Idempotent Text Autosizing", "Use idempotent text autosizing mode") \
    macro(ImageAnimationControlEnabled, imageAnimationControlEnabled, Bool, bool, DEFAULT_VALUE_FOR_ImageAnimationControlEnabled, "Image Animation Control", "Enable controls for image animations") \
    macro(ImageCaptureEnabled, imageCaptureEnabled, Bool, bool, DEFAULT_VALUE_FOR_ImageCaptureEnabled, "Image Capture API", "Enable Image Capture API") \
    macro(IndexedDBAPIEnabled, indexedDBAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_IndexedDBAPIEnabled, "IndexedDB API", "IndexedDB API") \
    macro(IsAccessibilityIsolatedTreeEnabled, isAccessibilityIsolatedTreeEnabled, Bool, bool, DEFAULT_VALUE_FOR_IsAccessibilityIsolatedTreeEnabled, "Isolated Accessibility Tree Mode", "Enable an accessibility hierarchy for VoiceOver that can be accessed on a secondary thread for improved performance") \
    macro(JavaScriptEnabled, javaScriptEnabled, Bool, bool, DEFAULT_VALUE_FOR_JavaScriptEnabled, "JavaScript", "Enable JavaScript") \
    macro(LazyIframeLoadingEnabled, lazyIframeLoadingEnabled, Bool, bool, DEFAULT_VALUE_FOR_LazyIframeLoadingEnabled, "Lazy iframe loading", "Enable lazy iframe loading support") \
    macro(LazyImageLoadingEnabled, lazyImageLoadingEnabled, Bool, bool, DEFAULT_VALUE_FOR_LazyImageLoadingEnabled, "Lazy image loading", "Enable lazy image loading support") \
    macro(ShowModalDialogEnabled, showModalDialogEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShowModalDialogEnabled, "Legacy showModalDialog() API", "Legacy showModalDialog() API") \
    macro(LimitedMatroskaSupportEnabled, limitedMatroskaSupportEnabled, Bool, bool, DEFAULT_VALUE_FOR_LimitedMatroskaSupportEnabled, "Limited Matroska Support", "Enable H264 and PCM with WebM Player and MediaRecorder") \
    macro(LinkPreconnectEarlyHintsEnabled, linkPreconnectEarlyHintsEnabled, Bool, bool, DEFAULT_VALUE_FOR_LinkPreconnectEarlyHintsEnabled, "Link rel=preconnect via HTTP early hints", "Enable link rel=preconnect via early hints") \
    macro(LoadWebArchiveWithEphemeralStorageEnabled, loadWebArchiveWithEphemeralStorageEnabled, Bool, bool, DEFAULT_VALUE_FOR_LoadWebArchiveWithEphemeralStorageEnabled, "Load Web Archive with ephemeral storage", "Enable loading web archive with ephemeral storage") \
    macro(LocalStorageEnabled, localStorageEnabled, Bool, bool, DEFAULT_VALUE_FOR_LocalStorageEnabled, "Local Storage", "Enable Local Storage") \
    macro(LockdownFontParserEnabled, lockdownFontParserEnabled, Bool, bool, DEFAULT_VALUE_FOR_LockdownFontParserEnabled, "Lockdown Mode Safe Fonts", "Try parsing Web fonts with safe font parser in Lockdown Mode") \
    macro(MainContentUserGestureOverrideEnabled, mainContentUserGestureOverrideEnabled, Bool, bool, DEFAULT_VALUE_FOR_MainContentUserGestureOverrideEnabled, "Main content user gesture override", "Enable main content user gesture override") \
    macro(ManagedMediaSourceEnabled, managedMediaSourceEnabled, Bool, bool, DEFAULT_VALUE_FOR_ManagedMediaSourceEnabled, "Managed Media Source API", "Managed Media Source API") \
    macro(ManagedMediaSourceNeedsAirPlay, managedMediaSourceNeedsAirPlay, Bool, bool, DEFAULT_VALUE_FOR_ManagedMediaSourceNeedsAirPlay, "Managed Media Source Requires AirPlay source", "Managed Media Source Requires AirPlay source") \
    macro(MediaCapabilitiesExtensionsEnabled, mediaCapabilitiesExtensionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaCapabilitiesExtensionsEnabled, "Media Capabilities Extensions", "Media Capabilities Extensions") \
    macro(MediaCapabilityGrantsEnabled, mediaCapabilityGrantsEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaCapabilityGrantsEnabled, "Media Capability Grants", "Enable granting and revoking of media capabilities") \
    macro(MediaPlaybackEnabled, mediaPlaybackEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaPlaybackEnabled, "Media Playback Functionalities", "Enable media playback functionalities") \
    macro(MediaSessionEnabled, mediaSessionEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSessionEnabled, "Media Session API", "Media Session API") \
    macro(MediaSourceEnabled, mediaSourceEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSourceEnabled, "Media Source API", "Media Source API") \
    macro(MediaDevicesEnabled, mediaDevicesEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaDevicesEnabled, "Media devices", "Enable media devices") \
    macro(MediaRecorderEnabledWebM, mediaRecorderEnabledWebM, Bool, bool, DEFAULT_VALUE_FOR_MediaRecorderEnabledWebM, "MediaRecorder WebM", "Enable WebM support with MediaRecorder") \
    macro(MediaRecorderEnabled, mediaRecorderEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaRecorderEnabled, "MediaRecorder", "MediaRecorder") \
    macro(MediaSessionCaptureToggleAPIEnabled, mediaSessionCaptureToggleAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSessionCaptureToggleAPIEnabled, "MediaSession capture related API", "Enable MediaSession capture related API") \
    macro(MediaSourceInWorkerEnabled, mediaSourceInWorkerEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaSourceInWorkerEnabled, "MediaSource in a Worker", "MediaSource in a Worker") \
    macro(MediaSourcePrefersDecompressionSession, mediaSourcePrefersDecompressionSession, Bool, bool, DEFAULT_VALUE_FOR_MediaSourcePrefersDecompressionSession, "MediaSource prefers DecompressionSession", "MediaSource prefers DecompressionSession") \
    macro(MediaStreamTrackProcessingEnabled, mediaStreamTrackProcessingEnabled, Bool, bool, DEFAULT_VALUE_FOR_MediaStreamTrackProcessingEnabled, "MediaStreamTrack Processing", "Enable MediaStreamTrack Processing") \
    macro(InputTypeMonthEnabled, inputTypeMonthEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeMonthEnabled, "Month Input", "Enable input elements of type month") \
    macro(NeedsSiteSpecificQuirks, needsSiteSpecificQuirks, Bool, bool, DEFAULT_VALUE_FOR_NeedsSiteSpecificQuirks, "Needs Site-Specific Quirks", "Enable site-specific quirks") \
    macro(NeedsStorageAccessFromFileURLsQuirk, needsStorageAccessFromFileURLsQuirk, Bool, bool, DEFAULT_VALUE_FOR_NeedsStorageAccessFromFileURLsQuirk, "Needs storage access from file URLs quirk", "") \
    macro(FlexFormattingContextIntegrationEnabled, flexFormattingContextIntegrationEnabled, Bool, bool, DEFAULT_VALUE_FOR_FlexFormattingContextIntegrationEnabled, "Next-generation flex layout integration (FFC)", "Enable next-generation flex layout integration (FFC)") \
    macro(NotificationsEnabled, notificationsEnabled, Bool, bool, DEFAULT_VALUE_FOR_NotificationsEnabled, "Notifications", "Enable the Notifications API") \
    macro(AccessibilityThreadTextApisEnabled, accessibilityThreadTextApisEnabled, Bool, bool, DEFAULT_VALUE_FOR_AccessibilityThreadTextApisEnabled, "Off Main-Thread Accessibility Text APIs", "Serve accessibility text APIs off the main-thread") \
    macro(OffscreenCanvasInWorkersEnabled, offscreenCanvasInWorkersEnabled, Bool, bool, DEFAULT_VALUE_FOR_OffscreenCanvasInWorkersEnabled, "OffscreenCanvas in Workers", "Support for the OffscreenCanvas APIs in Workers") \
    macro(OffscreenCanvasEnabled, offscreenCanvasEnabled, Bool, bool, DEFAULT_VALUE_FOR_OffscreenCanvasEnabled, "OffscreenCanvas", "Support for the OffscreenCanvas APIs") \
    macro(OverlappingBackingStoreProvidersEnabled, overlappingBackingStoreProvidersEnabled, Bool, bool, DEFAULT_VALUE_FOR_OverlappingBackingStoreProvidersEnabled, "Overlapping backing stores", "Enable overlapping backing stores compositor optimization") \
    macro(PermissionsAPIEnabled, permissionsAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_PermissionsAPIEnabled, "Permissions API", "Enable Permissions API") \
    macro(GetCoalescedEventsEnabled, getCoalescedEventsEnabled, Bool, bool, DEFAULT_VALUE_FOR_GetCoalescedEventsEnabled, "Pointer Events getCoalescedEvents API", "Enable the `getCoalescedEvents` function of the Pointer Events API") \
    macro(GetPredictedEventsEnabled, getPredictedEventsEnabled, Bool, bool, DEFAULT_VALUE_FOR_GetPredictedEventsEnabled, "Pointer Events getPredictedEvents API", "Enable the `getPredictedEvents` function of the Pointer Events API") \
    macro(PointerLockOptionsEnabled, pointerLockOptionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_PointerLockOptionsEnabled, "Pointer Lock Options", "Element.requestPointerLock(options) and promise support.") \
    macro(PreferPageRenderingUpdatesNear60FPSEnabled, preferPageRenderingUpdatesNear60FPSEnabled, Bool, bool, DEFAULT_VALUE_FOR_PreferPageRenderingUpdatesNear60FPSEnabled, "Prefer Page Rendering Updates near 60fps", "Prefer page rendering updates near 60 frames per second rather than using the display's refresh rate") \
    macro(PrivateClickMeasurementDebugModeEnabled, privateClickMeasurementDebugModeEnabled, Bool, bool, DEFAULT_VALUE_FOR_PrivateClickMeasurementDebugModeEnabled, "Private Click Measurement Debug Mode", "Enable Private Click Measurement Debug Mode") \
    macro(PrivateClickMeasurementFraudPreventionEnabled, privateClickMeasurementFraudPreventionEnabled, Bool, bool, DEFAULT_VALUE_FOR_PrivateClickMeasurementFraudPreventionEnabled, "Private Click Measurement Fraud Prevention", "Enable Private Click Measurement Fraud Prevention") \
    macro(PrivateClickMeasurementEnabled, privateClickMeasurementEnabled, Bool, bool, DEFAULT_VALUE_FOR_PrivateClickMeasurementEnabled, "Private Click Measurement", "Enable Private Click Measurement for Cross-Site Link Navigations") \
    macro(PrivateTokenUsageByThirdPartyEnabled, privateTokenUsageByThirdPartyEnabled, Bool, bool, DEFAULT_VALUE_FOR_PrivateTokenUsageByThirdPartyEnabled, "Private Token usage by third party", "Enable private token usage by third party") \
    macro(PushAPIEnabled, pushAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_PushAPIEnabled, "Push API", "Enable Push API") \
    macro(GoogleAntiFlickerOptimizationQuirkEnabled, googleAntiFlickerOptimizationQuirkEnabled, Bool, bool, DEFAULT_VALUE_FOR_GoogleAntiFlickerOptimizationQuirkEnabled, "Quirk to prevent delayed initial painting on sites using Google's Anti-Flicker optimization", "Quirk to prevent delayed initial painting on sites using Google's Anti-Flicker optimization") \
    macro(RemotePlaybackEnabled, remotePlaybackEnabled, Bool, bool, DEFAULT_VALUE_FOR_RemotePlaybackEnabled, "Remote Playback API", "Enable Remote Playback API") \
    macro(RequestVideoFrameCallbackEnabled, requestVideoFrameCallbackEnabled, Bool, bool, DEFAULT_VALUE_FOR_RequestVideoFrameCallbackEnabled, "RequestVideoFrameCallback", "Enable RequestVideoFrameCallback API") \
    macro(FullscreenRequirementForScreenOrientationLockingEnabled, fullscreenRequirementForScreenOrientationLockingEnabled, Bool, bool, DEFAULT_VALUE_FOR_FullscreenRequirementForScreenOrientationLockingEnabled, "Require being in Fullscreen to lock screen orientation", "Require being in Fullscreen to lock screen orientation") \
    macro(SKAttributionEnabled, sKAttributionEnabled, Bool, bool, DEFAULT_VALUE_FOR_SKAttributionEnabled, "SKAttribution", "SKAttribution") \
    macro(SafeBrowsingEnabled, safeBrowsingEnabled, Bool, bool, DEFAULT_VALUE_FOR_SafeBrowsingEnabled, "Safe Browsing", "Enable Safe Browsing") \
    macro(ScopedCustomElementRegistryEnabled, scopedCustomElementRegistryEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScopedCustomElementRegistryEnabled, "Scoped custom element registry", "Enable scoped custom element registry") \
    macro(ScreenOrientationAPIEnabled, screenOrientationAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScreenOrientationAPIEnabled, "Screen Orientation API", "Enable Screen Orientation API") \
    macro(ScreenWakeLockAPIEnabled, screenWakeLockAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScreenWakeLockAPIEnabled, "Screen Wake Lock API", "Enable Screen Wake Lock API") \
    macro(ScreenCaptureEnabled, screenCaptureEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScreenCaptureEnabled, "ScreenCapture", "Enable ScreenCapture") \
    macro(ScrollToTextFragmentFeatureDetectionEnabled, scrollToTextFragmentFeatureDetectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentFeatureDetectionEnabled, "Scroll To Text Fragment Feature Detection", "Enable Scroll To Text Fragment Feature Detection") \
    macro(ScrollToTextFragmentGenerationEnabled, scrollToTextFragmentGenerationEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentGenerationEnabled, "Scroll To Text Fragment Generation", "Enable Scroll To Text Fragment Generation Menu") \
    macro(ScrollToTextFragmentIndicatorEnabled, scrollToTextFragmentIndicatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentIndicatorEnabled, "Scroll To Text Fragment Indicator", "Enable Scroll To Text Fragment Indicator") \
    macro(ScrollToTextFragmentMarkingEnabled, scrollToTextFragmentMarkingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentMarkingEnabled, "Scroll To Text Fragment Marking", "Enable Scroll To Text Fragment Marking") \
    macro(ScrollToTextFragmentEnabled, scrollToTextFragmentEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollToTextFragmentEnabled, "Scroll To Text Fragment", "Enable Scroll To Text Fragment") \
    macro(ScrollAnimatorEnabled, scrollAnimatorEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollAnimatorEnabled, "Scroll animator", "Enable scroll animator") \
    macro(ScrollDrivenAnimationsEnabled, scrollDrivenAnimationsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ScrollDrivenAnimationsEnabled, "Scroll-driven Animations", "Enable Scroll-driven Animations") \
    macro(SelectionFlippingEnabled, selectionFlippingEnabled, Bool, bool, DEFAULT_VALUE_FOR_SelectionFlippingEnabled, "Selection Flipping", "Enable Selection Flipping") \
    macro(ServiceWorkerNavigationPreloadEnabled, serviceWorkerNavigationPreloadEnabled, Bool, bool, DEFAULT_VALUE_FOR_ServiceWorkerNavigationPreloadEnabled, "Service Worker Navigation Preload", "Enable Service Worker Navigation Preload API") \
    macro(ServiceWorkersEnabled, serviceWorkersEnabled, Bool, bool, DEFAULT_VALUE_FOR_ServiceWorkersEnabled, "Service Workers", "Enable Service Workers") \
    macro(SharedWorkerEnabled, sharedWorkerEnabled, Bool, bool, DEFAULT_VALUE_FOR_SharedWorkerEnabled, "SharedWorker", "Enabled SharedWorker API") \
    macro(ShowMediaStatsContextMenuItemEnabled, showMediaStatsContextMenuItemEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShowMediaStatsContextMenuItemEnabled, "Show Media Stats", "Adds a 'Media Stats' context menu item to <video> when the Develop menu is enabled") \
    macro(SidewaysWritingModesEnabled, sidewaysWritingModesEnabled, Bool, bool, DEFAULT_VALUE_FOR_SidewaysWritingModesEnabled, "Sideways writing modes", "Enable support for sideways writing modes") \
    macro(SpeechRecognitionEnabled, speechRecognitionEnabled, Bool, bool, DEFAULT_VALUE_FOR_SpeechRecognitionEnabled, "SpeechRecognition API", "Enable SpeechRecognition of WebSpeech API") \
    macro(SpeechSynthesisAPIEnabled, speechSynthesisAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_SpeechSynthesisAPIEnabled, "SpeechSynthesis API", "SpeechSynthesis API") \
    macro(StorageAPIEstimateEnabled, storageAPIEstimateEnabled, Bool, bool, DEFAULT_VALUE_FOR_StorageAPIEstimateEnabled, "Storage API Estimate", "Enable Storage API Estimate") \
    macro(StorageAPIEnabled, storageAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_StorageAPIEnabled, "Storage API", "Enable Storage API") \
    macro(StorageBlockingPolicy, storageBlockingPolicy, UInt32, uint32_t, DEFAULT_VALUE_FOR_StorageBlockingPolicy, "Storage Blocking Policy", "") \
    macro(SupportHDRDisplayEnabled, supportHDRDisplayEnabled, Bool, bool, DEFAULT_VALUE_FOR_SupportHDRDisplayEnabled, "Support HDR Display", "Support HDR Display") \
    macro(ProcessSwapOnCrossSiteNavigationEnabled, processSwapOnCrossSiteNavigationEnabled, Bool, bool, DEFAULT_VALUE_FOR_ProcessSwapOnCrossSiteNavigationEnabled, "Swap Processes on Cross-Site Navigation", "Swap WebContent Processes on cross-site navigations") \
    macro(InputTypeTimeEnabled, inputTypeTimeEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeTimeEnabled, "Time Input", "Enable input elements of type time") \
    macro(TrustedTypesEnabled, trustedTypesEnabled, Bool, bool, DEFAULT_VALUE_FOR_TrustedTypesEnabled, "Trusted Types", "Enable Trusted Types") \
    macro(URLPatternAPIEnabled, uRLPatternAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_URLPatternAPIEnabled, "URL Pattern API", "Enable URL Pattern API") \
    macro(UnifiedPDFEnabled, unifiedPDFEnabled, Bool, bool, DEFAULT_VALUE_FOR_UnifiedPDFEnabled, "Unified PDF Viewer", "Enable Unified PDF Viewer") \
    macro(UpgradeMixedContentEnabled, upgradeMixedContentEnabled, Bool, bool, DEFAULT_VALUE_FOR_UpgradeMixedContentEnabled, "Upgrade upgradable mixed content", "Upgrade upgradable mixed content") \
    macro(UseGiantTiles, useGiantTiles, Bool, bool, DEFAULT_VALUE_FOR_UseGiantTiles, "Use giant tiles", "") \
    macro(UserActivationAPIEnabled, userActivationAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_UserActivationAPIEnabled, "User Activation API", "Enable User Activation API") \
    macro(VerticalFormControlsEnabled, verticalFormControlsEnabled, Bool, bool, DEFAULT_VALUE_FOR_VerticalFormControlsEnabled, "Vertical form control support", "Enable support for form controls in vertical writing mode") \
    macro(VideoRendererProtectedFallbackDisabled, videoRendererProtectedFallbackDisabled, Bool, bool, DEFAULT_VALUE_FOR_VideoRendererProtectedFallbackDisabled, "VideoMediaSampleRenderer fallback to AVSBDL for protected content disabled", "VideoMediaSampleRenderer fallback to AVSBDL for protected content disabled") \
    macro(VideoRendererUseDecompressionSessionForProtected, videoRendererUseDecompressionSessionForProtected, Bool, bool, DEFAULT_VALUE_FOR_VideoRendererUseDecompressionSessionForProtected, "VideoMediaSampleRenderer use DecompressionSession for protected content", "VideoMediaSampleRenderer use DecompressionSession for protected content") \
    macro(ViewTransitionClassesEnabled, viewTransitionClassesEnabled, Bool, bool, DEFAULT_VALUE_FOR_ViewTransitionClassesEnabled, "View Transition Classes", "Support specifying classes for view transitions") \
    macro(ViewTransitionTypesEnabled, viewTransitionTypesEnabled, Bool, bool, DEFAULT_VALUE_FOR_ViewTransitionTypesEnabled, "View Transition Types", "Support specifying types for view transitions") \
    macro(ViewTransitionsEnabled, viewTransitionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_ViewTransitionsEnabled, "View Transitions", "Enable the View Transitions API") \
    macro(ViewGestureDebuggingEnabled, viewGestureDebuggingEnabled, Bool, bool, DEFAULT_VALUE_FOR_ViewGestureDebuggingEnabled, "View gesture debugging", "Enable view gesture debugging") \
    macro(VisualViewportAPIEnabled, visualViewportAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_VisualViewportAPIEnabled, "Visual Viewport API", "Enable Visual Viewport API") \
    macro(WebAnimationsOverallProgressPropertyEnabled, webAnimationsOverallProgressPropertyEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAnimationsOverallProgressPropertyEnabled, "Web Animations 'overallProgress' property", "Support for Animation's overallProgress property") \
    macro(WebArchiveDebugModeEnabled, webArchiveDebugModeEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebArchiveDebugModeEnabled, "Web Archive debug mode", "Enable web archive debug mode") \
    macro(WebAuthenticationASEnabled, webAuthenticationASEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAuthenticationASEnabled, "Web Authentication AuthenticationServices", "Enable Modern Web Authentication support though AuthenticationServices") \
    macro(WebAuthenticationEnabled, webAuthenticationEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebAuthenticationEnabled, "Web Authentication", "Enable Web Authentication support") \
    macro(WebCryptoSafeCurvesEnabled, webCryptoSafeCurvesEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebCryptoSafeCurvesEnabled, "Web Crypto Safe Curves", "Enable Web Crypto Safe Curves") \
    macro(WebCryptoX25519Enabled, webCryptoX25519Enabled, Bool, bool, DEFAULT_VALUE_FOR_WebCryptoX25519Enabled, "Web Crypto X25519 algorithm", "Enable Web Crypto X25519 algorithm") \
    macro(WebLocksAPIEnabled, webLocksAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebLocksAPIEnabled, "Web Locks API", "Web Locks API") \
    macro(WebShareFileAPIEnabled, webShareFileAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebShareFileAPIEnabled, "Web Share API Level 2", "Enable level 2 of Web Share API") \
    macro(WebShareEnabled, webShareEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebShareEnabled, "Web Share", "Enable support for share sheet via Web Share API") \
    macro(WebCodecsAV1Enabled, webCodecsAV1Enabled, Bool, bool, DEFAULT_VALUE_FOR_WebCodecsAV1Enabled, "WebCodecs AV1 codec", "Enable WebCodecs AV1 codec") \
    macro(WebCodecsAudioEnabled, webCodecsAudioEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebCodecsAudioEnabled, "WebCodecs Audio API", "Enable WebCodecs Audio API") \
    macro(WebCodecsHEVCEnabled, webCodecsHEVCEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebCodecsHEVCEnabled, "WebCodecs HEVC codec", "Enable WebCodecs HEVC codec") \
    macro(WebCodecsVideoEnabled, webCodecsVideoEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebCodecsVideoEnabled, "WebCodecs Video API", "Enable WebCodecs Video API") \
    macro(WebGLTimerQueriesEnabled, webGLTimerQueriesEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGLTimerQueriesEnabled, "WebGL Timer Queries", "Enable WebGL extensions that provide GPU timer queries") \
    macro(WebGLEnabled, webGLEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGLEnabled, "WebGL", "Enable WebGL") \
    macro(WebGPUHDREnabled, webGPUHDREnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGPUHDREnabled, "WebGPU support for HDR", "WebGPU High Dynamic Range through canvas configuration tone mapping mode") \
    macro(WebXRWebGPUBindingsEnabled, webXRWebGPUBindingsEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRWebGPUBindingsEnabled, "WebGPU support for WebXR", "Adds WebGPU support for WebXR") \
    macro(WebGPUEnabled, webGPUEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebGPUEnabled, "WebGPU", "Enable WebGPU") \
    macro(WebRTCAV1CodecEnabled, webRTCAV1CodecEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCAV1CodecEnabled, "WebRTC AV1 codec", "Enable WebRTC AV1 codec") \
    macro(WebRTCEncodedTransformEnabled, webRTCEncodedTransformEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCEncodedTransformEnabled, "WebRTC Encoded Transform API", "Enable WebRTC Encoded Transform API") \
    macro(WebRTCH265CodecEnabled, webRTCH265CodecEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCH265CodecEnabled, "WebRTC HEVC codec", "Enable WebRTC HEVC codec") \
    macro(LegacyWebRTCOfferOptionsEnabled, legacyWebRTCOfferOptionsEnabled, Bool, bool, DEFAULT_VALUE_FOR_LegacyWebRTCOfferOptionsEnabled, "WebRTC Peer Connection Legacy Offer options", "Enable RTCPeerConnection Legacy offer options (offerToReceiveAudio, offerToReceiveVideo)") \
    macro(PeerConnectionVideoScalingAdaptationDisabled, peerConnectionVideoScalingAdaptationDisabled, Bool, bool, DEFAULT_VALUE_FOR_PeerConnectionVideoScalingAdaptationDisabled, "WebRTC Peer Connection Video Scaling Adaptation", "Disable RTCPeerConnection Video Scaling Adaptation") \
    macro(PeerConnectionEnabled, peerConnectionEnabled, Bool, bool, DEFAULT_VALUE_FOR_PeerConnectionEnabled, "WebRTC Peer Connection", "Enable RTCPeerConnection") \
    macro(WebRTCUDPPortRange, webRTCUDPPortRange, String, String, DEFAULT_VALUE_FOR_WebRTCUDPPortRange, "WebRTC UDP Port Range", "Set a UDP port range for WebRTC. If set to 0:0, the port range is determined by the OS") \
    macro(WebRTCVP9Profile2CodecEnabled, webRTCVP9Profile2CodecEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebRTCVP9Profile2CodecEnabled, "WebRTC VP9 profile 2 codec", "Enable WebRTC VP9 profile 2 codec") \
    macro(WebXREnabled, webXREnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXREnabled, "WebXR Device API", "Adds support for accessing virtual reality (VR) and augmented reality (AR) devices, including sensors and head-mounted displays, on the Web") \
    macro(WebXRGamepadsModuleEnabled, webXRGamepadsModuleEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRGamepadsModuleEnabled, "WebXR Gamepads Module", "Adds support for the WebXR Gamepads Module") \
    macro(WebXRHandInputModuleEnabled, webXRHandInputModuleEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRHandInputModuleEnabled, "WebXR Hand Input Module", "Adds support for the Hands Input Module for WebXR") \
    macro(WebXRLayersAPIEnabled, webXRLayersAPIEnabled, Bool, bool, DEFAULT_VALUE_FOR_WebXRLayersAPIEnabled, "WebXR Layers API", "Adds support for the WebXR Layers API") \
    macro(InputTypeWeekEnabled, inputTypeWeekEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeWeekEnabled, "Week Input", "Enable input elements of type week") \
    macro(WheelEventGesturesBecomeNonBlocking, wheelEventGesturesBecomeNonBlocking, Bool, bool, DEFAULT_VALUE_FOR_WheelEventGesturesBecomeNonBlocking, "Wheel Event gestures become non-blocking", "preventDefault() is only allowed on the first wheel event in a gesture") \
    macro(PassiveWheelListenersAsDefaultOnDocument, passiveWheelListenersAsDefaultOnDocument, Bool, bool, DEFAULT_VALUE_FOR_PassiveWheelListenersAsDefaultOnDocument, "Wheel Event listeners on the root made passive", "Force wheel event listeners registered on the window, document or body to be passive") \
    macro(WorkerAsynchronousURLErrorHandlingEnabled, workerAsynchronousURLErrorHandlingEnabled, Bool, bool, DEFAULT_VALUE_FOR_WorkerAsynchronousURLErrorHandlingEnabled, "Worker asynchronous URL error handling", "Worker asynchronous URL error handling") \
    macro(WritingSuggestionsAttributeEnabled, writingSuggestionsAttributeEnabled, Bool, bool, DEFAULT_VALUE_FOR_WritingSuggestionsAttributeEnabled, "Writing Suggestions", "Enable the writingsuggestions attribute") \
    macro(IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled, isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled, Bool, bool, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled, "[ITP Live-On] 1 Hour Timeout For Non-Cookie Data Removal", "Remove all non-cookie website data after just one hour of no user interaction when Intelligent Tracking Prevention is enabled") \
    macro(IsFirstPartyWebsiteDataRemovalReproTestingEnabled, isFirstPartyWebsiteDataRemovalReproTestingEnabled, Bool, bool, DEFAULT_VALUE_FOR_IsFirstPartyWebsiteDataRemovalReproTestingEnabled, "[ITP Repro] 30 Second Timeout For Non-Cookie Data Removal", "Remove all non-cookie website data after just 30 seconds of no user interaction when Intelligent Tracking Prevention is enabled") \
    macro(AltitudeAngleEnabled, altitudeAngleEnabled, Bool, bool, DEFAULT_VALUE_FOR_AltitudeAngleEnabled, "altitudeAngle PointerEvent Property", "Enable the `altitudeAngle` property of the PointerEvents API") \
    macro(AzimuthAngleEnabled, azimuthAngleEnabled, Bool, bool, DEFAULT_VALUE_FOR_AzimuthAngleEnabled, "azimuthAngle PointerEvent Property", "Enable the `azimuthAngle` property of the PointerEvents API") \
    macro(InputTypeDateTimeLocalEnabled, inputTypeDateTimeLocalEnabled, Bool, bool, DEFAULT_VALUE_FOR_InputTypeDateTimeLocalEnabled, "datetime-local Inputs", "Enable input elements of type datetime-local") \
    macro(HiddenUntilFoundEnabled, hiddenUntilFoundEnabled, Bool, bool, DEFAULT_VALUE_FOR_HiddenUntilFoundEnabled, "hidden=until-found", "Enable support for hidden=until-found") \
    macro(HTTPEquivEnabled, httpEquivEnabled, Bool, bool, DEFAULT_VALUE_FOR_HTTPEquivEnabled, "http-equiv", "Enable http-equiv attribute") \
    \


#define FOR_EACH_DEFAULT_OVERRIDABLE_WEBKIT_PREFERENCE(macro) \
    macro(VisibleDebugOverlayRegions, visibleDebugOverlayRegions, UInt32, uint32_t, DEFAULT_VALUE_FOR_VisibleDebugOverlayRegions, "", "") \
    macro(DeveloperExtrasEnabled, developerExtrasEnabled, Bool, bool, DEFAULT_VALUE_FOR_DeveloperExtrasEnabled, "", "") \
    macro(CompositingBordersVisible, compositingBordersVisible, Bool, bool, DEFAULT_VALUE_FOR_CompositingBordersVisible, "Compositing borders visible", "") \
    macro(CompositingRepaintCountersVisible, compositingRepaintCountersVisible, Bool, bool, DEFAULT_VALUE_FOR_CompositingRepaintCountersVisible, "Compositing repaint counters visible", "") \
    macro(DeclarativeWebPush, declarativeWebPush, Bool, bool, DEFAULT_VALUE_FOR_DeclarativeWebPush, "Declarative Web Push", "Enable Declarative Web Push") \
    macro(DisableScreenSizeOverride, disableScreenSizeOverride, Bool, bool, DEFAULT_VALUE_FOR_DisableScreenSizeOverride, "Disable screen size override", "") \
    macro(EnableDebuggingFeaturesInSandbox, enableDebuggingFeaturesInSandbox, Bool, bool, DEFAULT_VALUE_FOR_EnableDebuggingFeaturesInSandbox, "Enable debugging features in sandbox", "Enable debugging features in sandbox") \
    macro(ForceAlwaysUserScalable, forceAlwaysUserScalable, Bool, bool, DEFAULT_VALUE_FOR_ForceAlwaysUserScalable, "Force always user-scalable", "") \
    macro(IFrameResourceMonitoringTestingSettingsEnabled, iFrameResourceMonitoringTestingSettingsEnabled, Bool, bool, DEFAULT_VALUE_FOR_IFrameResourceMonitoringTestingSettingsEnabled, "Frame Resource Monitoring Settings For Testing", "Use Resource Monitoring Settings for testing") \
    macro(IFrameResourceMonitoringEnabled, iFrameResourceMonitoringEnabled, Bool, bool, DEFAULT_VALUE_FOR_IFrameResourceMonitoringEnabled, "Frame Resource Monitoring Support", "Enable Usage Monitoring of Frame Resource Support") \
    macro(AcceleratedDrawingEnabled, acceleratedDrawingEnabled, Bool, bool, DEFAULT_VALUE_FOR_AcceleratedDrawingEnabled, "GraphicsLayer accelerated drawing", "Enable GraphicsLayer accelerated drawing") \
    macro(LegacyLineLayoutVisualCoverageEnabled, legacyLineLayoutVisualCoverageEnabled, Bool, bool, DEFAULT_VALUE_FOR_LegacyLineLayoutVisualCoverageEnabled, "Legacy line layout visual coverage", "Enable legacy line layout visual coverage") \
    macro(LogsPageMessagesToSystemConsoleEnabled, logsPageMessagesToSystemConsoleEnabled, Bool, bool, DEFAULT_VALUE_FOR_LogsPageMessagesToSystemConsoleEnabled, "Log page messages to system console", "Enable logging page messages to system console") \
    macro(NeedsInAppBrowserPrivacyQuirks, needsInAppBrowserPrivacyQuirks, Bool, bool, DEFAULT_VALUE_FOR_NeedsInAppBrowserPrivacyQuirks, "Needs In-App Browser Privacy Quirks", "Enable quirks needed to support In-App Browser privacy") \
    macro(PreferSpatialAudioExperience, preferSpatialAudioExperience, Bool, bool, DEFAULT_VALUE_FOR_PreferSpatialAudioExperience, "Prefer Spatial Audio Experience over Spatial Tracking Labels", "Prefer Spatial Audio Experience over Spatial Tracking Labels") \
    macro(ResourceUsageOverlayVisible, resourceUsageOverlayVisible, Bool, bool, DEFAULT_VALUE_FOR_ResourceUsageOverlayVisible, "Resource usage overlay", "Make resource usage overlay visible") \
    macro(RespondToThermalPressureAggressively, respondToThermalPressureAggressively, Bool, bool, DEFAULT_VALUE_FOR_RespondToThermalPressureAggressively, "Respond to thermal pressure aggressively", "Enable responding to thermal pressure aggressively") \
    macro(ShowFrameProcessBordersEnabled, showFrameProcessBordersEnabled, Bool, bool, DEFAULT_VALUE_FOR_ShowFrameProcessBordersEnabled, "Show frame process borders", "") \
    macro(TiledScrollingIndicatorVisible, tiledScrollingIndicatorVisible, Bool, bool, DEFAULT_VALUE_FOR_TiledScrollingIndicatorVisible, "Tiled scrolling indicator", "Make tiled scrolling indicator visible") \
    macro(UsesWebContentRestrictionsForFilter, usesWebContentRestrictionsForFilter, Bool, bool, DEFAULT_VALUE_FOR_UsesWebContentRestrictionsForFilter, "Uses WebContentRestriction framework for content filter", "") \
    macro(WebInspectorEngineeringSettingsAllowed, webInspectorEngineeringSettingsAllowed, Bool, bool, DEFAULT_VALUE_FOR_WebInspectorEngineeringSettingsAllowed, "WebInspector engineering settings allowed", "") \
    \

