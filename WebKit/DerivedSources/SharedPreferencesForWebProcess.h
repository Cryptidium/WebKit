/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2024 Apple Inc. All rights reserved.
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

namespace WebKit {

struct WebPreferencesStore;

struct SharedPreferencesForWebProcess {
    uint64_t version { 0 };
    bool allowTestOnlyIPC : 1 { false };
    bool webSocketEnabled : 1 { false };
#if ENABLE(APPLE_PAY)
    bool applePayEnabled : 1 { false };
#endif
#if ENABLE(WEB_AUDIO)
    bool webAudioEnabled : 1 { false };
#endif
    bool videoPresentationModeAPIEnabled : 1 { false };
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
    bool mediaControlsContextMenusEnabled : 1 { false };
#endif
    bool videoPresentationManagerEnabled : 1 { false };
#if ENABLE(FULLSCREEN_API)
    bool videoFullscreenRequiresElementFullscreen : 1 { false };
#endif
    bool usesSingleWebProcess : 1 { false };
#if ENABLE(DEVICE_ORIENTATION)
    bool deviceOrientationEventEnabled : 1 { false };
#endif
#if ENABLE(DEVICE_ORIENTATION)
    bool deviceOrientationPermissionAPIEnabled : 1 { false };
#endif
#if USE(SYSTEM_PREVIEW)
    bool systemPreviewEnabled : 1 { false };
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    bool encryptedMediaAPIEnabled : 1 { false };
#endif
    bool allowPrivacySensitiveOperationsInNonPersistentDataStores : 1 { false };
    bool appBadgeEnabled : 1 { false };
#if ENABLE(ATTACHMENT_ELEMENT)
    bool attachmentElementEnabled : 1 { false };
#endif
    bool broadcastChannelEnabled : 1 { false };
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    bool builtInNotificationsEnabled : 1 { false };
#endif
    bool canvasPixelFormatEnabled : 1 { false };
    bool inputTypeColorEnabled : 1 { false };
    bool contactPickerAPIEnabled : 1 { false };
    bool cookieConsentAPIEnabled : 1 { false };
    bool cookieStoreManagerEnabled : 1 { false };
#if PLATFORM(MAC)
    bool inputMethodUsesCorrectKeyEventOrder : 1 { false };
#endif
    bool dataListElementEnabled : 1 { false };
    bool inputTypeDateEnabled : 1 { false };
#if ENABLE(WEB_AUTHN)
    bool digitalCredentialsEnabled : 1 { false };
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
    bool useCGDisplayListsForDOMRendering : 1 { false };
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    bool legacyEncryptedMediaAPIEnabled : 1 { false };
#endif
#if ENABLE(MODEL_PROCESS)
    bool modelProcessEnabled : 1 { false };
#endif
    bool backgroundFetchAPIEnabled : 1 { false };
    bool blobFileAccessEnforcementEnabled : 1 { false };
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    bool mediaSessionCoordinatorEnabled : 1 { false };
#endif
    bool fileSystemEnabled : 1 { false };
    bool fileSystemWritableStreamEnabled : 1 { false };
    bool forceLockdownFontParserEnabled : 1 { false };
#if ENABLE(FULLSCREEN_API)
    bool fullScreenEnabled : 1 { false };
#endif
#if ENABLE(GPU_PROCESS)
    bool useGPUProcessForDOMRenderingEnabled : 1 { false };
#endif
#if ENABLE(GPU_PROCESS)
    bool useGPUProcessForMediaEnabled : 1 { false };
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
    bool useGPUProcessForWebGLEnabled : 1 { false };
#endif
#if ENABLE(GAMEPAD)
    bool gamepadsEnabled : 1 { false };
#endif
    bool geolocationAPIEnabled : 1 { false };
#if ENABLE(MODEL_ELEMENT)
    bool modelElementEnabled : 1 { false };
#endif
    bool inputTypeColorEnhancementsEnabled : 1 { false };
    bool ignoreIframeEmbeddingProtectionsEnabled : 1 { false };
    bool indexedDBAPIEnabled : 1 { false };
    bool lockdownFontParserEnabled : 1 { false };
#if ENABLE(MEDIA_SOURCE)
    bool managedMediaSourceEnabled : 1 { false };
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
    bool mediaCapabilityGrantsEnabled : 1 { false };
#endif
    bool mediaPlaybackEnabled : 1 { false };
#if ENABLE(MEDIA_SESSION)
    bool mediaSessionEnabled : 1 { false };
#endif
    bool mediaSourceEnabled : 1 { false };
#if ENABLE(MEDIA_RECORDER_WEBM)
    bool mediaRecorderEnabledWebM : 1 { false };
#endif
#if ENABLE(MEDIA_RECORDER)
    bool mediaRecorderEnabled : 1 { false };
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
    bool mediaSourcePrefersDecompressionSession : 1 { false };
#endif
    bool inputTypeMonthEnabled : 1 { false };
#if ENABLE(NOTIFICATION_EVENT)
    bool notificationEventEnabled : 1 { false };
#endif
#if ENABLE(NOTIFICATIONS)
    bool notificationsEnabled : 1 { false };
#endif
    bool permissionsAPIEnabled : 1 { false };
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    bool preferSpatialAudioExperience : 1 { false };
#endif
    bool pushAPIEnabled : 1 { false };
    bool remoteMediaSessionManagerEnabled : 1 { false };
    bool loginStatusAPIRequiresWebAuthnEnabled : 1 { false };
    bool screenOrientationAPIEnabled : 1 { false };
    bool serviceWorkerNavigationPreloadEnabled : 1 { false };
    bool serviceWorkersEnabled : 1 { false };
    bool shapeDetection : 1 { false };
    bool siteIsolationSharedProcessEnabled : 1 { false };
    bool sharedWorkerEnabled : 1 { false };
    bool siteIsolationEnabled : 1 { false };
    bool speechRecognitionEnabled : 1 { false };
    bool speechSynthesisAPIEnabled : 1 { false };
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    bool textRecognitionInVideosEnabled : 1 { false };
#endif
    bool inputTypeTimeEnabled : 1 { false };
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
    bool useAVCaptureDeviceRotationCoordinatorAPI : 1 { false };
#endif
#if HAVE(WEBCONTENTRESTRICTIONS)
    bool usesWebContentRestrictionsForFilter : 1 { false };
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    bool videoRendererProtectedFallbackDisabled : 1 { false };
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    bool videoRendererUseDecompressionSessionForProtected : 1 { false };
#endif
#if ENABLE(WEB_AUTHN)
    bool webAuthenticationEnabled : 1 { false };
#endif
    bool webLocksAPIEnabled : 1 { false };
    bool webShareEnabled : 1 { false };
#if ENABLE(WEB_CODECS)
    bool webCodecsVideoEnabled : 1 { false };
#endif
    bool webGLEnabled : 1 { false };
    bool webGPUHDREnabled : 1 { false };
    bool webXRWebGPUBindingsEnabled : 1 { false };
    bool webGPUEnabled : 1 { false };
#if ENABLE(WEB_RTC)
    bool peerConnectionEnabled : 1 { false };
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
    bool webRTCInterfaceMonitoringViaNWEnabled : 1 { false };
#endif
    bool webTransportEnabled : 1 { false };
#if ENABLE(WEBXR)
    bool webXREnabled : 1 { false };
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    bool webPageSpatialBackdropEnabled : 1 { false };
#endif
    bool inputTypeWeekEnabled : 1 { false };
    bool inputTypeDateTimeLocalEnabled : 1 { false };
    bool shadowRootReferenceTargetEnabledForAriaOwns : 1 { false };
    bool shadowRootReferenceTargetEnabled : 1 { false };

    bool operator==(const SharedPreferencesForWebProcess&) const = default;
};

SharedPreferencesForWebProcess sharedPreferencesForWebProcess(const WebPreferencesStore&);
bool updateSharedPreferencesForWebProcess(SharedPreferencesForWebProcess&, const WebPreferencesStore&);

} // namespace WebKit
