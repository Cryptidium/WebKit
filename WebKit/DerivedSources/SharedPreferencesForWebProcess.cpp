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

#include "config.h"
#include "SharedPreferencesForWebProcess.h"

#include "WebPreferencesKeys.h"
#include "WebPreferencesStore.h"

namespace WebKit {

SharedPreferencesForWebProcess sharedPreferencesForWebProcess(const WebPreferencesStore& preferencesStore)
{
    SharedPreferencesForWebProcess sharedPreferences;
        sharedPreferences.allowTestOnlyIPC = preferencesStore.getBoolValueForKey(WebPreferencesKey::allowTestOnlyIPCKey());
        sharedPreferences.webSocketEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webSocketEnabledKey());
#if ENABLE(APPLE_PAY)
        sharedPreferences.applePayEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::applePayEnabledKey());
#endif
#if ENABLE(WEB_AUDIO)
        sharedPreferences.webAudioEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webAudioEnabledKey());
#endif
        sharedPreferences.videoPresentationModeAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::videoPresentationModeAPIEnabledKey());
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
        sharedPreferences.mediaControlsContextMenusEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaControlsContextMenusEnabledKey());
#endif
        sharedPreferences.videoPresentationManagerEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::videoPresentationManagerEnabledKey());
#if ENABLE(FULLSCREEN_API)
        sharedPreferences.videoFullscreenRequiresElementFullscreen = preferencesStore.getBoolValueForKey(WebPreferencesKey::videoFullscreenRequiresElementFullscreenKey());
#endif
        sharedPreferences.usesSingleWebProcess = preferencesStore.getBoolValueForKey(WebPreferencesKey::usesSingleWebProcessKey());
#if ENABLE(DEVICE_ORIENTATION)
        sharedPreferences.deviceOrientationEventEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::deviceOrientationEventEnabledKey());
#endif
#if ENABLE(DEVICE_ORIENTATION)
        sharedPreferences.deviceOrientationPermissionAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::deviceOrientationPermissionAPIEnabledKey());
#endif
#if USE(SYSTEM_PREVIEW)
        sharedPreferences.systemPreviewEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::systemPreviewEnabledKey());
#endif
#if ENABLE(ENCRYPTED_MEDIA)
        sharedPreferences.encryptedMediaAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::encryptedMediaAPIEnabledKey());
#endif
        sharedPreferences.allowPrivacySensitiveOperationsInNonPersistentDataStores = preferencesStore.getBoolValueForKey(WebPreferencesKey::allowPrivacySensitiveOperationsInNonPersistentDataStoresKey());
        sharedPreferences.appBadgeEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::appBadgeEnabledKey());
#if ENABLE(ATTACHMENT_ELEMENT)
        sharedPreferences.attachmentElementEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::attachmentElementEnabledKey());
#endif
        sharedPreferences.broadcastChannelEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::broadcastChannelEnabledKey());
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
        sharedPreferences.builtInNotificationsEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::builtInNotificationsEnabledKey());
#endif
        sharedPreferences.canvasPixelFormatEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::canvasPixelFormatEnabledKey());
        sharedPreferences.inputTypeColorEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeColorEnabledKey());
        sharedPreferences.contactPickerAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::contactPickerAPIEnabledKey());
        sharedPreferences.cookieConsentAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::cookieConsentAPIEnabledKey());
        sharedPreferences.cookieStoreManagerEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::cookieStoreManagerEnabledKey());
#if PLATFORM(MAC)
        sharedPreferences.inputMethodUsesCorrectKeyEventOrder = preferencesStore.getBoolValueForKey(WebPreferencesKey::inputMethodUsesCorrectKeyEventOrderKey());
#endif
        sharedPreferences.dataListElementEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::dataListElementEnabledKey());
        sharedPreferences.inputTypeDateEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeDateEnabledKey());
#if ENABLE(WEB_AUTHN)
        sharedPreferences.digitalCredentialsEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::digitalCredentialsEnabledKey());
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
        sharedPreferences.useCGDisplayListsForDOMRendering = preferencesStore.getBoolValueForKey(WebPreferencesKey::useCGDisplayListsForDOMRenderingKey());
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
        sharedPreferences.legacyEncryptedMediaAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::legacyEncryptedMediaAPIEnabledKey());
#endif
#if ENABLE(MODEL_PROCESS)
        sharedPreferences.modelProcessEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::modelProcessEnabledKey());
#endif
        sharedPreferences.backgroundFetchAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::backgroundFetchAPIEnabledKey());
        sharedPreferences.blobFileAccessEnforcementEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::blobFileAccessEnforcementEnabledKey());
#if ENABLE(MEDIA_SESSION_COORDINATOR)
        sharedPreferences.mediaSessionCoordinatorEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaSessionCoordinatorEnabledKey());
#endif
        sharedPreferences.fileSystemEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::fileSystemEnabledKey());
        sharedPreferences.fileSystemWritableStreamEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::fileSystemWritableStreamEnabledKey());
        sharedPreferences.forceLockdownFontParserEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::forceLockdownFontParserEnabledKey());
#if ENABLE(FULLSCREEN_API)
        sharedPreferences.fullScreenEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::fullScreenEnabledKey());
#endif
#if ENABLE(GPU_PROCESS)
        sharedPreferences.useGPUProcessForDOMRenderingEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::useGPUProcessForDOMRenderingEnabledKey());
#endif
#if ENABLE(GPU_PROCESS)
        sharedPreferences.useGPUProcessForMediaEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::useGPUProcessForMediaEnabledKey());
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
        sharedPreferences.useGPUProcessForWebGLEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::useGPUProcessForWebGLEnabledKey());
#endif
#if ENABLE(GAMEPAD)
        sharedPreferences.gamepadsEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::gamepadsEnabledKey());
#endif
        sharedPreferences.geolocationAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::geolocationAPIEnabledKey());
#if ENABLE(MODEL_ELEMENT)
        sharedPreferences.modelElementEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::modelElementEnabledKey());
#endif
        sharedPreferences.inputTypeColorEnhancementsEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeColorEnhancementsEnabledKey());
        sharedPreferences.ignoreIframeEmbeddingProtectionsEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::ignoreIframeEmbeddingProtectionsEnabledKey());
        sharedPreferences.indexedDBAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::indexedDBAPIEnabledKey());
        sharedPreferences.lockdownFontParserEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::lockdownFontParserEnabledKey());
#if ENABLE(MEDIA_SOURCE)
        sharedPreferences.managedMediaSourceEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::managedMediaSourceEnabledKey());
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
        sharedPreferences.mediaCapabilityGrantsEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaCapabilityGrantsEnabledKey());
#endif
        sharedPreferences.mediaPlaybackEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaPlaybackEnabledKey());
#if ENABLE(MEDIA_SESSION)
        sharedPreferences.mediaSessionEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaSessionEnabledKey());
#endif
        sharedPreferences.mediaSourceEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaSourceEnabledKey());
#if ENABLE(MEDIA_RECORDER_WEBM)
        sharedPreferences.mediaRecorderEnabledWebM = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledWebMKey());
#endif
#if ENABLE(MEDIA_RECORDER)
        sharedPreferences.mediaRecorderEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledKey());
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
        sharedPreferences.mediaSourcePrefersDecompressionSession = preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaSourcePrefersDecompressionSessionKey());
#endif
        sharedPreferences.inputTypeMonthEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeMonthEnabledKey());
#if ENABLE(NOTIFICATION_EVENT)
        sharedPreferences.notificationEventEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::notificationEventEnabledKey());
#endif
#if ENABLE(NOTIFICATIONS)
        sharedPreferences.notificationsEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::notificationsEnabledKey());
#endif
        sharedPreferences.permissionsAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::permissionsAPIEnabledKey());
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
        sharedPreferences.preferSpatialAudioExperience = preferencesStore.getBoolValueForKey(WebPreferencesKey::preferSpatialAudioExperienceKey());
#endif
        sharedPreferences.pushAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::pushAPIEnabledKey());
        sharedPreferences.remoteMediaSessionManagerEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::remoteMediaSessionManagerEnabledKey());
        sharedPreferences.loginStatusAPIRequiresWebAuthnEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::loginStatusAPIRequiresWebAuthnEnabledKey());
        sharedPreferences.screenOrientationAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::screenOrientationAPIEnabledKey());
        sharedPreferences.serviceWorkerNavigationPreloadEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::serviceWorkerNavigationPreloadEnabledKey());
        sharedPreferences.serviceWorkersEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::serviceWorkersEnabledKey());
        sharedPreferences.shapeDetection = preferencesStore.getBoolValueForKey(WebPreferencesKey::shapeDetectionKey());
        sharedPreferences.siteIsolationSharedProcessEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::siteIsolationSharedProcessEnabledKey());
        sharedPreferences.sharedWorkerEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::sharedWorkerEnabledKey());
        sharedPreferences.siteIsolationEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::siteIsolationEnabledKey());
        sharedPreferences.speechRecognitionEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::speechRecognitionEnabledKey());
        sharedPreferences.speechSynthesisAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::speechSynthesisAPIEnabledKey());
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
        sharedPreferences.textRecognitionInVideosEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::textRecognitionInVideosEnabledKey());
#endif
        sharedPreferences.inputTypeTimeEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeTimeEnabledKey());
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
        sharedPreferences.useAVCaptureDeviceRotationCoordinatorAPI = preferencesStore.getBoolValueForKey(WebPreferencesKey::useAVCaptureDeviceRotationCoordinatorAPIKey());
#endif
#if HAVE(WEBCONTENTRESTRICTIONS)
        sharedPreferences.usesWebContentRestrictionsForFilter = preferencesStore.getBoolValueForKey(WebPreferencesKey::usesWebContentRestrictionsForFilterKey());
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        sharedPreferences.videoRendererProtectedFallbackDisabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::videoRendererProtectedFallbackDisabledKey());
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
        sharedPreferences.videoRendererUseDecompressionSessionForProtected = preferencesStore.getBoolValueForKey(WebPreferencesKey::videoRendererUseDecompressionSessionForProtectedKey());
#endif
#if ENABLE(WEB_AUTHN)
        sharedPreferences.webAuthenticationEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webAuthenticationEnabledKey());
#endif
        sharedPreferences.webLocksAPIEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webLocksAPIEnabledKey());
        sharedPreferences.webShareEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webShareEnabledKey());
#if ENABLE(WEB_CODECS)
        sharedPreferences.webCodecsVideoEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webCodecsVideoEnabledKey());
#endif
        sharedPreferences.webGLEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webGLEnabledKey());
        sharedPreferences.webGPUHDREnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webGPUHDREnabledKey());
        sharedPreferences.webXRWebGPUBindingsEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webXRWebGPUBindingsEnabledKey());
        sharedPreferences.webGPUEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webGPUEnabledKey());
#if ENABLE(WEB_RTC)
        sharedPreferences.peerConnectionEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::peerConnectionEnabledKey());
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
        sharedPreferences.webRTCInterfaceMonitoringViaNWEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webRTCInterfaceMonitoringViaNWEnabledKey());
#endif
        sharedPreferences.webTransportEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webTransportEnabledKey());
#if ENABLE(WEBXR)
        sharedPreferences.webXREnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webXREnabledKey());
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
        sharedPreferences.webPageSpatialBackdropEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::webPageSpatialBackdropEnabledKey());
#endif
        sharedPreferences.inputTypeWeekEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeWeekEnabledKey());
        sharedPreferences.inputTypeDateTimeLocalEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeDateTimeLocalEnabledKey());
        sharedPreferences.shadowRootReferenceTargetEnabledForAriaOwns = preferencesStore.getBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledForAriaOwnsKey());
        sharedPreferences.shadowRootReferenceTargetEnabled = preferencesStore.getBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledKey());
    return sharedPreferences;
}

bool updateSharedPreferencesForWebProcess(SharedPreferencesForWebProcess& sharedPreferences, const WebPreferencesStore& preferencesStore)
{
    bool didChange = false;
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::allowTestOnlyIPCKey()) && !sharedPreferences.allowTestOnlyIPC) {
        sharedPreferences.allowTestOnlyIPC = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webSocketEnabledKey()) && !sharedPreferences.webSocketEnabled) {
        sharedPreferences.webSocketEnabled = true;
        didChange = true;
    }
#if ENABLE(APPLE_PAY)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::applePayEnabledKey()) && !sharedPreferences.applePayEnabled) {
        sharedPreferences.applePayEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(WEB_AUDIO)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webAudioEnabledKey()) && !sharedPreferences.webAudioEnabled) {
        sharedPreferences.webAudioEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::videoPresentationModeAPIEnabledKey()) && !sharedPreferences.videoPresentationModeAPIEnabled) {
        sharedPreferences.videoPresentationModeAPIEnabled = true;
        didChange = true;
    }
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaControlsContextMenusEnabledKey()) && !sharedPreferences.mediaControlsContextMenusEnabled) {
        sharedPreferences.mediaControlsContextMenusEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::videoPresentationManagerEnabledKey()) && !sharedPreferences.videoPresentationManagerEnabled) {
        sharedPreferences.videoPresentationManagerEnabled = true;
        didChange = true;
    }
#if ENABLE(FULLSCREEN_API)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::videoFullscreenRequiresElementFullscreenKey()) && !sharedPreferences.videoFullscreenRequiresElementFullscreen) {
        sharedPreferences.videoFullscreenRequiresElementFullscreen = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::usesSingleWebProcessKey()) && !sharedPreferences.usesSingleWebProcess) {
        sharedPreferences.usesSingleWebProcess = true;
        didChange = true;
    }
#if ENABLE(DEVICE_ORIENTATION)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::deviceOrientationEventEnabledKey()) && !sharedPreferences.deviceOrientationEventEnabled) {
        sharedPreferences.deviceOrientationEventEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(DEVICE_ORIENTATION)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::deviceOrientationPermissionAPIEnabledKey()) && !sharedPreferences.deviceOrientationPermissionAPIEnabled) {
        sharedPreferences.deviceOrientationPermissionAPIEnabled = true;
        didChange = true;
    }
#endif
#if USE(SYSTEM_PREVIEW)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::systemPreviewEnabledKey()) && !sharedPreferences.systemPreviewEnabled) {
        sharedPreferences.systemPreviewEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::encryptedMediaAPIEnabledKey()) && !sharedPreferences.encryptedMediaAPIEnabled) {
        sharedPreferences.encryptedMediaAPIEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::allowPrivacySensitiveOperationsInNonPersistentDataStoresKey()) && !sharedPreferences.allowPrivacySensitiveOperationsInNonPersistentDataStores) {
        sharedPreferences.allowPrivacySensitiveOperationsInNonPersistentDataStores = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::appBadgeEnabledKey()) && !sharedPreferences.appBadgeEnabled) {
        sharedPreferences.appBadgeEnabled = true;
        didChange = true;
    }
#if ENABLE(ATTACHMENT_ELEMENT)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::attachmentElementEnabledKey()) && !sharedPreferences.attachmentElementEnabled) {
        sharedPreferences.attachmentElementEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::broadcastChannelEnabledKey()) && !sharedPreferences.broadcastChannelEnabled) {
        sharedPreferences.broadcastChannelEnabled = true;
        didChange = true;
    }
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::builtInNotificationsEnabledKey()) && !sharedPreferences.builtInNotificationsEnabled) {
        sharedPreferences.builtInNotificationsEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::canvasPixelFormatEnabledKey()) && !sharedPreferences.canvasPixelFormatEnabled) {
        sharedPreferences.canvasPixelFormatEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeColorEnabledKey()) && !sharedPreferences.inputTypeColorEnabled) {
        sharedPreferences.inputTypeColorEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::contactPickerAPIEnabledKey()) && !sharedPreferences.contactPickerAPIEnabled) {
        sharedPreferences.contactPickerAPIEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::cookieConsentAPIEnabledKey()) && !sharedPreferences.cookieConsentAPIEnabled) {
        sharedPreferences.cookieConsentAPIEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::cookieStoreManagerEnabledKey()) && !sharedPreferences.cookieStoreManagerEnabled) {
        sharedPreferences.cookieStoreManagerEnabled = true;
        didChange = true;
    }
#if PLATFORM(MAC)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::inputMethodUsesCorrectKeyEventOrderKey()) && !sharedPreferences.inputMethodUsesCorrectKeyEventOrder) {
        sharedPreferences.inputMethodUsesCorrectKeyEventOrder = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::dataListElementEnabledKey()) && !sharedPreferences.dataListElementEnabled) {
        sharedPreferences.dataListElementEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeDateEnabledKey()) && !sharedPreferences.inputTypeDateEnabled) {
        sharedPreferences.inputTypeDateEnabled = true;
        didChange = true;
    }
#if ENABLE(WEB_AUTHN)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::digitalCredentialsEnabledKey()) && !sharedPreferences.digitalCredentialsEnabled) {
        sharedPreferences.digitalCredentialsEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::useCGDisplayListsForDOMRenderingKey()) && !sharedPreferences.useCGDisplayListsForDOMRendering) {
        sharedPreferences.useCGDisplayListsForDOMRendering = true;
        didChange = true;
    }
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::legacyEncryptedMediaAPIEnabledKey()) && !sharedPreferences.legacyEncryptedMediaAPIEnabled) {
        sharedPreferences.legacyEncryptedMediaAPIEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(MODEL_PROCESS)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::modelProcessEnabledKey()) && !sharedPreferences.modelProcessEnabled) {
        sharedPreferences.modelProcessEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::backgroundFetchAPIEnabledKey()) && !sharedPreferences.backgroundFetchAPIEnabled) {
        sharedPreferences.backgroundFetchAPIEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::blobFileAccessEnforcementEnabledKey()) && !sharedPreferences.blobFileAccessEnforcementEnabled) {
        sharedPreferences.blobFileAccessEnforcementEnabled = true;
        didChange = true;
    }
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaSessionCoordinatorEnabledKey()) && !sharedPreferences.mediaSessionCoordinatorEnabled) {
        sharedPreferences.mediaSessionCoordinatorEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::fileSystemEnabledKey()) && !sharedPreferences.fileSystemEnabled) {
        sharedPreferences.fileSystemEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::fileSystemWritableStreamEnabledKey()) && !sharedPreferences.fileSystemWritableStreamEnabled) {
        sharedPreferences.fileSystemWritableStreamEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::forceLockdownFontParserEnabledKey()) && !sharedPreferences.forceLockdownFontParserEnabled) {
        sharedPreferences.forceLockdownFontParserEnabled = true;
        didChange = true;
    }
#if ENABLE(FULLSCREEN_API)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::fullScreenEnabledKey()) && !sharedPreferences.fullScreenEnabled) {
        sharedPreferences.fullScreenEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(GPU_PROCESS)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::useGPUProcessForDOMRenderingEnabledKey()) && !sharedPreferences.useGPUProcessForDOMRenderingEnabled) {
        sharedPreferences.useGPUProcessForDOMRenderingEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(GPU_PROCESS)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::useGPUProcessForMediaEnabledKey()) && !sharedPreferences.useGPUProcessForMediaEnabled) {
        sharedPreferences.useGPUProcessForMediaEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::useGPUProcessForWebGLEnabledKey()) && !sharedPreferences.useGPUProcessForWebGLEnabled) {
        sharedPreferences.useGPUProcessForWebGLEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(GAMEPAD)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::gamepadsEnabledKey()) && !sharedPreferences.gamepadsEnabled) {
        sharedPreferences.gamepadsEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::geolocationAPIEnabledKey()) && !sharedPreferences.geolocationAPIEnabled) {
        sharedPreferences.geolocationAPIEnabled = true;
        didChange = true;
    }
#if ENABLE(MODEL_ELEMENT)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::modelElementEnabledKey()) && !sharedPreferences.modelElementEnabled) {
        sharedPreferences.modelElementEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeColorEnhancementsEnabledKey()) && !sharedPreferences.inputTypeColorEnhancementsEnabled) {
        sharedPreferences.inputTypeColorEnhancementsEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::ignoreIframeEmbeddingProtectionsEnabledKey()) && !sharedPreferences.ignoreIframeEmbeddingProtectionsEnabled) {
        sharedPreferences.ignoreIframeEmbeddingProtectionsEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::indexedDBAPIEnabledKey()) && !sharedPreferences.indexedDBAPIEnabled) {
        sharedPreferences.indexedDBAPIEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::lockdownFontParserEnabledKey()) && !sharedPreferences.lockdownFontParserEnabled) {
        sharedPreferences.lockdownFontParserEnabled = true;
        didChange = true;
    }
#if ENABLE(MEDIA_SOURCE)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::managedMediaSourceEnabledKey()) && !sharedPreferences.managedMediaSourceEnabled) {
        sharedPreferences.managedMediaSourceEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaCapabilityGrantsEnabledKey()) && !sharedPreferences.mediaCapabilityGrantsEnabled) {
        sharedPreferences.mediaCapabilityGrantsEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaPlaybackEnabledKey()) && !sharedPreferences.mediaPlaybackEnabled) {
        sharedPreferences.mediaPlaybackEnabled = true;
        didChange = true;
    }
#if ENABLE(MEDIA_SESSION)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaSessionEnabledKey()) && !sharedPreferences.mediaSessionEnabled) {
        sharedPreferences.mediaSessionEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaSourceEnabledKey()) && !sharedPreferences.mediaSourceEnabled) {
        sharedPreferences.mediaSourceEnabled = true;
        didChange = true;
    }
#if ENABLE(MEDIA_RECORDER_WEBM)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledWebMKey()) && !sharedPreferences.mediaRecorderEnabledWebM) {
        sharedPreferences.mediaRecorderEnabledWebM = true;
        didChange = true;
    }
#endif
#if ENABLE(MEDIA_RECORDER)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledKey()) && !sharedPreferences.mediaRecorderEnabled) {
        sharedPreferences.mediaRecorderEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(MEDIA_SOURCE) && USE(AVFOUNDATION)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::mediaSourcePrefersDecompressionSessionKey()) && !sharedPreferences.mediaSourcePrefersDecompressionSession) {
        sharedPreferences.mediaSourcePrefersDecompressionSession = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeMonthEnabledKey()) && !sharedPreferences.inputTypeMonthEnabled) {
        sharedPreferences.inputTypeMonthEnabled = true;
        didChange = true;
    }
#if ENABLE(NOTIFICATION_EVENT)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::notificationEventEnabledKey()) && !sharedPreferences.notificationEventEnabled) {
        sharedPreferences.notificationEventEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(NOTIFICATIONS)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::notificationsEnabledKey()) && !sharedPreferences.notificationsEnabled) {
        sharedPreferences.notificationsEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::permissionsAPIEnabledKey()) && !sharedPreferences.permissionsAPIEnabled) {
        sharedPreferences.permissionsAPIEnabled = true;
        didChange = true;
    }
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::preferSpatialAudioExperienceKey()) && !sharedPreferences.preferSpatialAudioExperience) {
        sharedPreferences.preferSpatialAudioExperience = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::pushAPIEnabledKey()) && !sharedPreferences.pushAPIEnabled) {
        sharedPreferences.pushAPIEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::remoteMediaSessionManagerEnabledKey()) && !sharedPreferences.remoteMediaSessionManagerEnabled) {
        sharedPreferences.remoteMediaSessionManagerEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::loginStatusAPIRequiresWebAuthnEnabledKey()) && !sharedPreferences.loginStatusAPIRequiresWebAuthnEnabled) {
        sharedPreferences.loginStatusAPIRequiresWebAuthnEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::screenOrientationAPIEnabledKey()) && !sharedPreferences.screenOrientationAPIEnabled) {
        sharedPreferences.screenOrientationAPIEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::serviceWorkerNavigationPreloadEnabledKey()) && !sharedPreferences.serviceWorkerNavigationPreloadEnabled) {
        sharedPreferences.serviceWorkerNavigationPreloadEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::serviceWorkersEnabledKey()) && !sharedPreferences.serviceWorkersEnabled) {
        sharedPreferences.serviceWorkersEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::shapeDetectionKey()) && !sharedPreferences.shapeDetection) {
        sharedPreferences.shapeDetection = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::siteIsolationSharedProcessEnabledKey()) && !sharedPreferences.siteIsolationSharedProcessEnabled) {
        sharedPreferences.siteIsolationSharedProcessEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::sharedWorkerEnabledKey()) && !sharedPreferences.sharedWorkerEnabled) {
        sharedPreferences.sharedWorkerEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::siteIsolationEnabledKey()) && !sharedPreferences.siteIsolationEnabled) {
        sharedPreferences.siteIsolationEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::speechRecognitionEnabledKey()) && !sharedPreferences.speechRecognitionEnabled) {
        sharedPreferences.speechRecognitionEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::speechSynthesisAPIEnabledKey()) && !sharedPreferences.speechSynthesisAPIEnabled) {
        sharedPreferences.speechSynthesisAPIEnabled = true;
        didChange = true;
    }
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::textRecognitionInVideosEnabledKey()) && !sharedPreferences.textRecognitionInVideosEnabled) {
        sharedPreferences.textRecognitionInVideosEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeTimeEnabledKey()) && !sharedPreferences.inputTypeTimeEnabled) {
        sharedPreferences.inputTypeTimeEnabled = true;
        didChange = true;
    }
#if HAVE(AVCAPTUREDEVICEROTATIONCOORDINATOR)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::useAVCaptureDeviceRotationCoordinatorAPIKey()) && !sharedPreferences.useAVCaptureDeviceRotationCoordinatorAPI) {
        sharedPreferences.useAVCaptureDeviceRotationCoordinatorAPI = true;
        didChange = true;
    }
#endif
#if HAVE(WEBCONTENTRESTRICTIONS)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::usesWebContentRestrictionsForFilterKey()) && !sharedPreferences.usesWebContentRestrictionsForFilter) {
        sharedPreferences.usesWebContentRestrictionsForFilter = true;
        didChange = true;
    }
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::videoRendererProtectedFallbackDisabledKey()) && !sharedPreferences.videoRendererProtectedFallbackDisabled) {
        sharedPreferences.videoRendererProtectedFallbackDisabled = true;
        didChange = true;
    }
#endif
#if USE(MODERN_AVCONTENTKEYSESSION_WITH_VTDECOMPRESSIONSESSION)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::videoRendererUseDecompressionSessionForProtectedKey()) && !sharedPreferences.videoRendererUseDecompressionSessionForProtected) {
        sharedPreferences.videoRendererUseDecompressionSessionForProtected = true;
        didChange = true;
    }
#endif
#if ENABLE(WEB_AUTHN)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webAuthenticationEnabledKey()) && !sharedPreferences.webAuthenticationEnabled) {
        sharedPreferences.webAuthenticationEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webLocksAPIEnabledKey()) && !sharedPreferences.webLocksAPIEnabled) {
        sharedPreferences.webLocksAPIEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webShareEnabledKey()) && !sharedPreferences.webShareEnabled) {
        sharedPreferences.webShareEnabled = true;
        didChange = true;
    }
#if ENABLE(WEB_CODECS)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webCodecsVideoEnabledKey()) && !sharedPreferences.webCodecsVideoEnabled) {
        sharedPreferences.webCodecsVideoEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webGLEnabledKey()) && !sharedPreferences.webGLEnabled) {
        sharedPreferences.webGLEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webGPUHDREnabledKey()) && !sharedPreferences.webGPUHDREnabled) {
        sharedPreferences.webGPUHDREnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webXRWebGPUBindingsEnabledKey()) && !sharedPreferences.webXRWebGPUBindingsEnabled) {
        sharedPreferences.webXRWebGPUBindingsEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webGPUEnabledKey()) && !sharedPreferences.webGPUEnabled) {
        sharedPreferences.webGPUEnabled = true;
        didChange = true;
    }
#if ENABLE(WEB_RTC)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::peerConnectionEnabledKey()) && !sharedPreferences.peerConnectionEnabled) {
        sharedPreferences.peerConnectionEnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(WEB_RTC) && PLATFORM(COCOA)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webRTCInterfaceMonitoringViaNWEnabledKey()) && !sharedPreferences.webRTCInterfaceMonitoringViaNWEnabled) {
        sharedPreferences.webRTCInterfaceMonitoringViaNWEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webTransportEnabledKey()) && !sharedPreferences.webTransportEnabled) {
        sharedPreferences.webTransportEnabled = true;
        didChange = true;
    }
#if ENABLE(WEBXR)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webXREnabledKey()) && !sharedPreferences.webXREnabled) {
        sharedPreferences.webXREnabled = true;
        didChange = true;
    }
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::webPageSpatialBackdropEnabledKey()) && !sharedPreferences.webPageSpatialBackdropEnabled) {
        sharedPreferences.webPageSpatialBackdropEnabled = true;
        didChange = true;
    }
#endif
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeWeekEnabledKey()) && !sharedPreferences.inputTypeWeekEnabled) {
        sharedPreferences.inputTypeWeekEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::inputTypeDateTimeLocalEnabledKey()) && !sharedPreferences.inputTypeDateTimeLocalEnabled) {
        sharedPreferences.inputTypeDateTimeLocalEnabled = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledForAriaOwnsKey()) && !sharedPreferences.shadowRootReferenceTargetEnabledForAriaOwns) {
        sharedPreferences.shadowRootReferenceTargetEnabledForAriaOwns = true;
        didChange = true;
    }
    if (preferencesStore.getBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledKey()) && !sharedPreferences.shadowRootReferenceTargetEnabled) {
        sharedPreferences.shadowRootReferenceTargetEnabled = true;
        didChange = true;
    }
    return didChange;
}

} // namespace WebKit
