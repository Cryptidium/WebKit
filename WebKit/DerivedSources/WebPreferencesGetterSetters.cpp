/*
* THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
*
* Copyright (C) 2020 Apple Inc. All rights reserved.
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

#include "WebPreferencesKeys.h"

namespace WebKit {

void WebPreferences::setDatabasesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::databasesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::databasesEnabledKey(), value, false);
}

bool WebPreferences::databasesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::databasesEnabledKey());
}

void WebPreferences::deleteDatabasesEnabled()
{
    deleteKey(WebPreferencesKey::databasesEnabledKey());
}

void WebPreferences::setLoadDeferringEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::loadDeferringEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::loadDeferringEnabledKey(), value, false);
}

bool WebPreferences::loadDeferringEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::loadDeferringEnabledKey());
}

void WebPreferences::deleteLoadDeferringEnabled()
{
    deleteKey(WebPreferencesKey::loadDeferringEnabledKey());
}

void WebPreferences::setAcceleratedCompositingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::acceleratedCompositingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::acceleratedCompositingEnabledKey(), value, false);
}

bool WebPreferences::acceleratedCompositingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::acceleratedCompositingEnabledKey());
}

void WebPreferences::deleteAcceleratedCompositingEnabled()
{
    deleteKey(WebPreferencesKey::acceleratedCompositingEnabledKey());
}

void WebPreferences::setAcceleratedCompositingForFixedPositionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::acceleratedCompositingForFixedPositionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::acceleratedCompositingForFixedPositionEnabledKey(), value, false);
}

bool WebPreferences::acceleratedCompositingForFixedPositionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::acceleratedCompositingForFixedPositionEnabledKey());
}

void WebPreferences::deleteAcceleratedCompositingForFixedPositionEnabled()
{
    deleteKey(WebPreferencesKey::acceleratedCompositingForFixedPositionEnabledKey());
}

void WebPreferences::setWirelessPlaybackTargetAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::wirelessPlaybackTargetAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::wirelessPlaybackTargetAPIEnabledKey(), value, false);
}

bool WebPreferences::wirelessPlaybackTargetAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::wirelessPlaybackTargetAPIEnabledKey());
}

void WebPreferences::deleteWirelessPlaybackTargetAPIEnabled()
{
    deleteKey(WebPreferencesKey::wirelessPlaybackTargetAPIEnabledKey());
}

void WebPreferences::setLoadsImagesAutomatically(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::loadsImagesAutomaticallyKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::loadsImagesAutomaticallyKey(), value, false);
}

bool WebPreferences::loadsImagesAutomatically() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::loadsImagesAutomaticallyKey());
}

void WebPreferences::deleteLoadsImagesAutomatically()
{
    deleteKey(WebPreferencesKey::loadsImagesAutomaticallyKey());
}

void WebPreferences::setLinkPreconnect(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::linkPreconnectKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::linkPreconnectKey(), value, false);
}

bool WebPreferences::linkPreconnect() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::linkPreconnectKey());
}

void WebPreferences::deleteLinkPreconnect()
{
    deleteKey(WebPreferencesKey::linkPreconnectKey());
}

void WebPreferences::setLongRunningMediaCaptureStreamRepromptIntervalInHours(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::longRunningMediaCaptureStreamRepromptIntervalInHoursKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::longRunningMediaCaptureStreamRepromptIntervalInHoursKey(), value, false);
}

double WebPreferences::longRunningMediaCaptureStreamRepromptIntervalInHours() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::longRunningMediaCaptureStreamRepromptIntervalInHoursKey());
}

void WebPreferences::deleteLongRunningMediaCaptureStreamRepromptIntervalInHours()
{
    deleteKey(WebPreferencesKey::longRunningMediaCaptureStreamRepromptIntervalInHoursKey());
}

void WebPreferences::setWindowFocusRestricted(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::windowFocusRestrictedKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::windowFocusRestrictedKey(), value, false);
}

bool WebPreferences::windowFocusRestricted() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::windowFocusRestrictedKey());
}

void WebPreferences::deleteWindowFocusRestricted()
{
    deleteKey(WebPreferencesKey::windowFocusRestrictedKey());
}

void WebPreferences::setAggressiveTileRetentionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::aggressiveTileRetentionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::aggressiveTileRetentionEnabledKey(), value, false);
}

bool WebPreferences::aggressiveTileRetentionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::aggressiveTileRetentionEnabledKey());
}

void WebPreferences::deleteAggressiveTileRetentionEnabled()
{
    deleteKey(WebPreferencesKey::aggressiveTileRetentionEnabledKey());
}

void WebPreferences::setAllowContentSecurityPolicySourceStarToMatchAnyProtocol(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowContentSecurityPolicySourceStarToMatchAnyProtocolKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowContentSecurityPolicySourceStarToMatchAnyProtocolKey(), value, false);
}

bool WebPreferences::allowContentSecurityPolicySourceStarToMatchAnyProtocol() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowContentSecurityPolicySourceStarToMatchAnyProtocolKey());
}

void WebPreferences::deleteAllowContentSecurityPolicySourceStarToMatchAnyProtocol()
{
    deleteKey(WebPreferencesKey::allowContentSecurityPolicySourceStarToMatchAnyProtocolKey());
}

void WebPreferences::setAllowDisplayOfInsecureContent(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowDisplayOfInsecureContentKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowDisplayOfInsecureContentKey(), value, false);
}

bool WebPreferences::allowDisplayOfInsecureContent() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowDisplayOfInsecureContentKey());
}

void WebPreferences::deleteAllowDisplayOfInsecureContent()
{
    deleteKey(WebPreferencesKey::allowDisplayOfInsecureContentKey());
}

void WebPreferences::setAllowFileAccessFromFileURLs(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowFileAccessFromFileURLsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowFileAccessFromFileURLsKey(), value, false);
}

bool WebPreferences::allowFileAccessFromFileURLs() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowFileAccessFromFileURLsKey());
}

void WebPreferences::deleteAllowFileAccessFromFileURLs()
{
    deleteKey(WebPreferencesKey::allowFileAccessFromFileURLsKey());
}

void WebPreferences::setLowPowerVideoAudioBufferSizeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::lowPowerVideoAudioBufferSizeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::lowPowerVideoAudioBufferSizeEnabledKey(), value, false);
}

bool WebPreferences::lowPowerVideoAudioBufferSizeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::lowPowerVideoAudioBufferSizeEnabledKey());
}

void WebPreferences::deleteLowPowerVideoAudioBufferSizeEnabled()
{
    deleteKey(WebPreferencesKey::lowPowerVideoAudioBufferSizeEnabledKey());
}

void WebPreferences::setAllowMultiElementImplicitSubmission(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowMultiElementImplicitSubmissionKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowMultiElementImplicitSubmissionKey(), value, false);
}

bool WebPreferences::allowMultiElementImplicitSubmission() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowMultiElementImplicitSubmissionKey());
}

void WebPreferences::deleteAllowMultiElementImplicitSubmission()
{
    deleteKey(WebPreferencesKey::allowMultiElementImplicitSubmissionKey());
}

void WebPreferences::setManagedMediaSourceHighThreshold(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::managedMediaSourceHighThresholdKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::managedMediaSourceHighThresholdKey(), value, false);
}

double WebPreferences::managedMediaSourceHighThreshold() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::managedMediaSourceHighThresholdKey());
}

void WebPreferences::deleteManagedMediaSourceHighThreshold()
{
    deleteKey(WebPreferencesKey::managedMediaSourceHighThresholdKey());
}

void WebPreferences::setAllowRunningOfInsecureContent(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowRunningOfInsecureContentKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowRunningOfInsecureContentKey(), value, false);
}

bool WebPreferences::allowRunningOfInsecureContent() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowRunningOfInsecureContentKey());
}

void WebPreferences::deleteAllowRunningOfInsecureContent()
{
    deleteKey(WebPreferencesKey::allowRunningOfInsecureContentKey());
}

void WebPreferences::setAllowTestOnlyIPC(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowTestOnlyIPCKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowTestOnlyIPCKey(), value, false);
}

bool WebPreferences::allowTestOnlyIPC() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowTestOnlyIPCKey());
}

void WebPreferences::deleteAllowTestOnlyIPC()
{
    deleteKey(WebPreferencesKey::allowTestOnlyIPCKey());
}

void WebPreferences::setManagedMediaSourceLowThreshold(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::managedMediaSourceLowThresholdKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::managedMediaSourceLowThresholdKey(), value, false);
}

double WebPreferences::managedMediaSourceLowThreshold() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::managedMediaSourceLowThresholdKey());
}

void WebPreferences::deleteManagedMediaSourceLowThreshold()
{
    deleteKey(WebPreferencesKey::managedMediaSourceLowThresholdKey());
}

void WebPreferences::setMathMLEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mathMLEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mathMLEnabledKey(), value, false);
}

bool WebPreferences::mathMLEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mathMLEnabledKey());
}

void WebPreferences::deleteMathMLEnabled()
{
    deleteKey(WebPreferencesKey::mathMLEnabledKey());
}

void WebPreferences::setMaxParseDuration(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::maxParseDurationKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::maxParseDurationKey(), value, false);
}

double WebPreferences::maxParseDuration() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::maxParseDurationKey());
}

void WebPreferences::deleteMaxParseDuration()
{
    deleteKey(WebPreferencesKey::maxParseDurationKey());
}

void WebPreferences::setMediaAudioCodecIDsAllowedInLockdownMode(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::mediaAudioCodecIDsAllowedInLockdownModeKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::mediaAudioCodecIDsAllowedInLockdownModeKey(), value, false);
}

String WebPreferences::mediaAudioCodecIDsAllowedInLockdownMode() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::mediaAudioCodecIDsAllowedInLockdownModeKey());
}

void WebPreferences::deleteMediaAudioCodecIDsAllowedInLockdownMode()
{
    deleteKey(WebPreferencesKey::mediaAudioCodecIDsAllowedInLockdownModeKey());
}

void WebPreferences::setAllowsAirPlayForMediaPlayback(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowsAirPlayForMediaPlaybackKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowsAirPlayForMediaPlaybackKey(), value, false);
}

bool WebPreferences::allowsAirPlayForMediaPlayback() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowsAirPlayForMediaPlaybackKey());
}

void WebPreferences::deleteAllowsAirPlayForMediaPlayback()
{
    deleteKey(WebPreferencesKey::allowsAirPlayForMediaPlaybackKey());
}

void WebPreferences::setAllowsInlineMediaPlayback(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowsInlineMediaPlaybackKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowsInlineMediaPlaybackKey(), value, false);
}

bool WebPreferences::allowsInlineMediaPlayback() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowsInlineMediaPlaybackKey());
}

void WebPreferences::deleteAllowsInlineMediaPlayback()
{
    deleteKey(WebPreferencesKey::allowsInlineMediaPlaybackKey());
}

void WebPreferences::setAllowsInlineMediaPlaybackAfterFullscreen(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowsInlineMediaPlaybackAfterFullscreenKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowsInlineMediaPlaybackAfterFullscreenKey(), value, false);
}

bool WebPreferences::allowsInlineMediaPlaybackAfterFullscreen() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowsInlineMediaPlaybackAfterFullscreenKey());
}

void WebPreferences::deleteAllowsInlineMediaPlaybackAfterFullscreen()
{
    deleteKey(WebPreferencesKey::allowsInlineMediaPlaybackAfterFullscreenKey());
}

void WebPreferences::setAllowsPictureInPictureMediaPlayback(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowsPictureInPictureMediaPlaybackKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowsPictureInPictureMediaPlaybackKey(), value, false);
}

bool WebPreferences::allowsPictureInPictureMediaPlayback() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowsPictureInPictureMediaPlaybackKey());
}

void WebPreferences::deleteAllowsPictureInPictureMediaPlayback()
{
    deleteKey(WebPreferencesKey::allowsPictureInPictureMediaPlaybackKey());
}

void WebPreferences::setAlternateFullScreenControlDesignEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::alternateFullScreenControlDesignEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::alternateFullScreenControlDesignEnabledKey(), value, false);
}

bool WebPreferences::alternateFullScreenControlDesignEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::alternateFullScreenControlDesignEnabledKey());
}

void WebPreferences::deleteAlternateFullScreenControlDesignEnabled()
{
    deleteKey(WebPreferencesKey::alternateFullScreenControlDesignEnabledKey());
}

void WebPreferences::setWebSocketEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webSocketEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webSocketEnabledKey(), value, false);
}

bool WebPreferences::webSocketEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webSocketEnabledKey());
}

void WebPreferences::deleteWebSocketEnabled()
{
    deleteKey(WebPreferencesKey::webSocketEnabledKey());
}

void WebPreferences::setMediaCapabilitiesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaCapabilitiesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaCapabilitiesEnabledKey(), value, false);
}

bool WebPreferences::mediaCapabilitiesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaCapabilitiesEnabledKey());
}

void WebPreferences::deleteMediaCapabilitiesEnabled()
{
    deleteKey(WebPreferencesKey::mediaCapabilitiesEnabledKey());
}

void WebPreferences::setWebSecurityEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webSecurityEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webSecurityEnabledKey(), value, false);
}

bool WebPreferences::webSecurityEnabled() const
{
    if (m_webSecurityEnabledInspectorOverride)
        return m_webSecurityEnabledInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::webSecurityEnabledKey());
}

void WebPreferences::deleteWebSecurityEnabled()
{
    deleteKey(WebPreferencesKey::webSecurityEnabledKey());
}

void WebPreferences::setAnimatedImageAsyncDecodingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::animatedImageAsyncDecodingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::animatedImageAsyncDecodingEnabledKey(), value, false);
}

bool WebPreferences::animatedImageAsyncDecodingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::animatedImageAsyncDecodingEnabledKey());
}

void WebPreferences::deleteAnimatedImageAsyncDecodingEnabled()
{
    deleteKey(WebPreferencesKey::animatedImageAsyncDecodingEnabledKey());
}

void WebPreferences::setLayoutViewportHeightExpansionFactor(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::layoutViewportHeightExpansionFactorKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::layoutViewportHeightExpansionFactorKey(), value, false);
}

double WebPreferences::layoutViewportHeightExpansionFactor() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::layoutViewportHeightExpansionFactorKey());
}

void WebPreferences::deleteLayoutViewportHeightExpansionFactor()
{
    deleteKey(WebPreferencesKey::layoutViewportHeightExpansionFactorKey());
}

void WebPreferences::setLayoutFallbackWidth(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::layoutFallbackWidthKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::layoutFallbackWidthKey(), value, false);
}

uint32_t WebPreferences::layoutFallbackWidth() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::layoutFallbackWidthKey());
}

void WebPreferences::deleteLayoutFallbackWidth()
{
    deleteKey(WebPreferencesKey::layoutFallbackWidthKey());
}

void WebPreferences::setAppleMailPaginationQuirkEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::appleMailPaginationQuirkEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::appleMailPaginationQuirkEnabledKey(), value, false);
}

bool WebPreferences::appleMailPaginationQuirkEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::appleMailPaginationQuirkEnabledKey());
}

void WebPreferences::deleteAppleMailPaginationQuirkEnabled()
{
    deleteKey(WebPreferencesKey::appleMailPaginationQuirkEnabledKey());
}

void WebPreferences::setApplePayCapabilityDisclosureAllowed(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::applePayCapabilityDisclosureAllowedKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::applePayCapabilityDisclosureAllowedKey(), value, false);
}

bool WebPreferences::applePayCapabilityDisclosureAllowed() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::applePayCapabilityDisclosureAllowedKey());
}

void WebPreferences::deleteApplePayCapabilityDisclosureAllowed()
{
    deleteKey(WebPreferencesKey::applePayCapabilityDisclosureAllowedKey());
}

void WebPreferences::setApplePayEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::applePayEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::applePayEnabledKey(), value, false);
}

bool WebPreferences::applePayEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::applePayEnabledKey());
}

void WebPreferences::deleteApplePayEnabled()
{
    deleteKey(WebPreferencesKey::applePayEnabledKey());
}

void WebPreferences::setLargeImageAsyncDecodingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::largeImageAsyncDecodingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::largeImageAsyncDecodingEnabledKey(), value, false);
}

bool WebPreferences::largeImageAsyncDecodingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::largeImageAsyncDecodingEnabledKey());
}

void WebPreferences::deleteLargeImageAsyncDecodingEnabled()
{
    deleteKey(WebPreferencesKey::largeImageAsyncDecodingEnabledKey());
}

void WebPreferences::setMediaCaptionFormatTypesAllowedInLockdownMode(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::mediaCaptionFormatTypesAllowedInLockdownModeKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::mediaCaptionFormatTypesAllowedInLockdownModeKey(), value, false);
}

String WebPreferences::mediaCaptionFormatTypesAllowedInLockdownMode() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::mediaCaptionFormatTypesAllowedInLockdownModeKey());
}

void WebPreferences::deleteMediaCaptionFormatTypesAllowedInLockdownMode()
{
    deleteKey(WebPreferencesKey::mediaCaptionFormatTypesAllowedInLockdownModeKey());
}

void WebPreferences::setJavaScriptRuntimeFlags(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::javaScriptRuntimeFlagsKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::javaScriptRuntimeFlagsKey(), value, false);
}

uint32_t WebPreferences::javaScriptRuntimeFlags() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::javaScriptRuntimeFlagsKey());
}

void WebPreferences::deleteJavaScriptRuntimeFlags()
{
    deleteKey(WebPreferencesKey::javaScriptRuntimeFlagsKey());
}

void WebPreferences::setAsynchronousSpellCheckingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::asynchronousSpellCheckingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::asynchronousSpellCheckingEnabledKey(), value, false);
}

bool WebPreferences::asynchronousSpellCheckingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::asynchronousSpellCheckingEnabledKey());
}

void WebPreferences::deleteAsynchronousSpellCheckingEnabled()
{
    deleteKey(WebPreferencesKey::asynchronousSpellCheckingEnabledKey());
}

void WebPreferences::setJavaScriptMarkupEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::javaScriptMarkupEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::javaScriptMarkupEnabledKey(), value, false);
}

bool WebPreferences::javaScriptMarkupEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::javaScriptMarkupEnabledKey());
}

void WebPreferences::deleteJavaScriptMarkupEnabled()
{
    deleteKey(WebPreferencesKey::javaScriptMarkupEnabledKey());
}

void WebPreferences::setMediaCodecTypesAllowedInLockdownMode(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::mediaCodecTypesAllowedInLockdownModeKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::mediaCodecTypesAllowedInLockdownModeKey(), value, false);
}

String WebPreferences::mediaCodecTypesAllowedInLockdownMode() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::mediaCodecTypesAllowedInLockdownModeKey());
}

void WebPreferences::deleteMediaCodecTypesAllowedInLockdownMode()
{
    deleteKey(WebPreferencesKey::mediaCodecTypesAllowedInLockdownModeKey());
}

void WebPreferences::setAudioControlsScaleWithPageZoom(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::audioControlsScaleWithPageZoomKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::audioControlsScaleWithPageZoomKey(), value, false);
}

bool WebPreferences::audioControlsScaleWithPageZoom() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::audioControlsScaleWithPageZoomKey());
}

void WebPreferences::deleteAudioControlsScaleWithPageZoom()
{
    deleteKey(WebPreferencesKey::audioControlsScaleWithPageZoomKey());
}

void WebPreferences::setJavaScriptCanOpenWindowsAutomatically(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::javaScriptCanOpenWindowsAutomaticallyKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::javaScriptCanOpenWindowsAutomaticallyKey(), value, false);
}

bool WebPreferences::javaScriptCanOpenWindowsAutomatically() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::javaScriptCanOpenWindowsAutomaticallyKey());
}

void WebPreferences::deleteJavaScriptCanOpenWindowsAutomatically()
{
    deleteKey(WebPreferencesKey::javaScriptCanOpenWindowsAutomaticallyKey());
}

void WebPreferences::setAuthorAndUserStylesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::authorAndUserStylesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::authorAndUserStylesEnabledKey(), value, false);
}

bool WebPreferences::authorAndUserStylesEnabled() const
{
    if (m_authorAndUserStylesEnabledInspectorOverride)
        return m_authorAndUserStylesEnabledInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::authorAndUserStylesEnabledKey());
}

void WebPreferences::deleteAuthorAndUserStylesEnabled()
{
    deleteKey(WebPreferencesKey::authorAndUserStylesEnabledKey());
}

void WebPreferences::setWebAudioEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAudioEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAudioEnabledKey(), value, false);
}

bool WebPreferences::webAudioEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAudioEnabledKey());
}

void WebPreferences::deleteWebAudioEnabled()
{
    deleteKey(WebPreferencesKey::webAudioEnabledKey());
}

void WebPreferences::setJavaScriptCanAccessClipboard(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::javaScriptCanAccessClipboardKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::javaScriptCanAccessClipboardKey(), value, false);
}

bool WebPreferences::javaScriptCanAccessClipboard() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::javaScriptCanAccessClipboardKey());
}

void WebPreferences::deleteJavaScriptCanAccessClipboard()
{
    deleteKey(WebPreferencesKey::javaScriptCanAccessClipboardKey());
}

void WebPreferences::setWantsBalancedSetDefersLoadingBehavior(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::wantsBalancedSetDefersLoadingBehaviorKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::wantsBalancedSetDefersLoadingBehaviorKey(), value, false);
}

bool WebPreferences::wantsBalancedSetDefersLoadingBehavior() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::wantsBalancedSetDefersLoadingBehaviorKey());
}

void WebPreferences::deleteWantsBalancedSetDefersLoadingBehavior()
{
    deleteKey(WebPreferencesKey::wantsBalancedSetDefersLoadingBehaviorKey());
}

void WebPreferences::setVisualViewportEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::visualViewportEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::visualViewportEnabledKey(), value, false);
}

bool WebPreferences::visualViewportEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::visualViewportEnabledKey());
}

void WebPreferences::deleteVisualViewportEnabled()
{
    deleteKey(WebPreferencesKey::visualViewportEnabledKey());
}

void WebPreferences::setVisibleDebugOverlayRegions(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::visibleDebugOverlayRegionsKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::visibleDebugOverlayRegionsKey(), value, false);
}

uint32_t WebPreferences::visibleDebugOverlayRegions() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::visibleDebugOverlayRegionsKey());
}

void WebPreferences::deleteVisibleDebugOverlayRegions()
{
    deleteKey(WebPreferencesKey::visibleDebugOverlayRegionsKey());
}

void WebPreferences::setVideoQualityIncludesDisplayCompositingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::videoQualityIncludesDisplayCompositingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::videoQualityIncludesDisplayCompositingEnabledKey(), value, false);
}

bool WebPreferences::videoQualityIncludesDisplayCompositingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::videoQualityIncludesDisplayCompositingEnabledKey());
}

void WebPreferences::deleteVideoQualityIncludesDisplayCompositingEnabled()
{
    deleteKey(WebPreferencesKey::videoQualityIncludesDisplayCompositingEnabledKey());
}

void WebPreferences::setBackspaceKeyNavigationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::backspaceKeyNavigationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::backspaceKeyNavigationEnabledKey(), value, false);
}

bool WebPreferences::backspaceKeyNavigationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::backspaceKeyNavigationEnabledKey());
}

void WebPreferences::deleteBackspaceKeyNavigationEnabled()
{
    deleteKey(WebPreferencesKey::backspaceKeyNavigationEnabledKey());
}

void WebPreferences::setMediaContainerTypesAllowedInLockdownMode(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::mediaContainerTypesAllowedInLockdownModeKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::mediaContainerTypesAllowedInLockdownModeKey(), value, false);
}

String WebPreferences::mediaContainerTypesAllowedInLockdownMode() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::mediaContainerTypesAllowedInLockdownModeKey());
}

void WebPreferences::deleteMediaContainerTypesAllowedInLockdownMode()
{
    deleteKey(WebPreferencesKey::mediaContainerTypesAllowedInLockdownModeKey());
}

void WebPreferences::setMediaContentTypesRequiringHardwareSupport(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::mediaContentTypesRequiringHardwareSupportKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::mediaContentTypesRequiringHardwareSupportKey(), value, false);
}

String WebPreferences::mediaContentTypesRequiringHardwareSupport() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::mediaContentTypesRequiringHardwareSupportKey());
}

void WebPreferences::deleteMediaContentTypesRequiringHardwareSupport()
{
    deleteKey(WebPreferencesKey::mediaContentTypesRequiringHardwareSupportKey());
}

void WebPreferences::setVideoPresentationModeAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::videoPresentationModeAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::videoPresentationModeAPIEnabledKey(), value, false);
}

bool WebPreferences::videoPresentationModeAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::videoPresentationModeAPIEnabledKey());
}

void WebPreferences::deleteVideoPresentationModeAPIEnabled()
{
    deleteKey(WebPreferencesKey::videoPresentationModeAPIEnabledKey());
}

void WebPreferences::setMediaControlsContextMenusEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaControlsContextMenusEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaControlsContextMenusEnabledKey(), value, false);
}

bool WebPreferences::mediaControlsContextMenusEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaControlsContextMenusEnabledKey());
}

void WebPreferences::deleteMediaControlsContextMenusEnabled()
{
    deleteKey(WebPreferencesKey::mediaControlsContextMenusEnabledKey());
}

void WebPreferences::setVideoPresentationManagerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::videoPresentationManagerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::videoPresentationManagerEnabledKey(), value, false);
}

bool WebPreferences::videoPresentationManagerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::videoPresentationManagerEnabledKey());
}

void WebPreferences::deleteVideoPresentationManagerEnabled()
{
    deleteKey(WebPreferencesKey::videoPresentationManagerEnabledKey());
}

void WebPreferences::setMediaControlsScaleWithPageZoom(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaControlsScaleWithPageZoomKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaControlsScaleWithPageZoomKey(), value, false);
}

bool WebPreferences::mediaControlsScaleWithPageZoom() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaControlsScaleWithPageZoomKey());
}

void WebPreferences::deleteMediaControlsScaleWithPageZoom()
{
    deleteKey(WebPreferencesKey::mediaControlsScaleWithPageZoomKey());
}

void WebPreferences::setVideoFullscreenRequiresElementFullscreen(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::videoFullscreenRequiresElementFullscreenKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::videoFullscreenRequiresElementFullscreenKey(), value, false);
}

bool WebPreferences::videoFullscreenRequiresElementFullscreen() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::videoFullscreenRequiresElementFullscreenKey());
}

void WebPreferences::deleteVideoFullscreenRequiresElementFullscreen()
{
    deleteKey(WebPreferencesKey::videoFullscreenRequiresElementFullscreenKey());
}

void WebPreferences::setMediaDataLoadsAutomatically(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaDataLoadsAutomaticallyKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaDataLoadsAutomaticallyKey(), value, false);
}

bool WebPreferences::mediaDataLoadsAutomatically() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaDataLoadsAutomaticallyKey());
}

void WebPreferences::deleteMediaDataLoadsAutomatically()
{
    deleteKey(WebPreferencesKey::mediaDataLoadsAutomaticallyKey());
}

void WebPreferences::setMediaPreferredFullscreenWidth(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::mediaPreferredFullscreenWidthKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::mediaPreferredFullscreenWidthKey(), value, false);
}

double WebPreferences::mediaPreferredFullscreenWidth() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::mediaPreferredFullscreenWidthKey());
}

void WebPreferences::deleteMediaPreferredFullscreenWidth()
{
    deleteKey(WebPreferencesKey::mediaPreferredFullscreenWidthKey());
}

void WebPreferences::setMediaPreloadingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaPreloadingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaPreloadingEnabledKey(), value, false);
}

bool WebPreferences::mediaPreloadingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaPreloadingEnabledKey());
}

void WebPreferences::deleteMediaPreloadingEnabled()
{
    deleteKey(WebPreferencesKey::mediaPreloadingEnabledKey());
}

void WebPreferences::setInvisibleAutoplayNotPermitted(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::invisibleAutoplayNotPermittedKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::invisibleAutoplayNotPermittedKey(), value, false);
}

bool WebPreferences::invisibleAutoplayNotPermitted() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::invisibleAutoplayNotPermittedKey());
}

void WebPreferences::deleteInvisibleAutoplayNotPermitted()
{
    deleteKey(WebPreferencesKey::invisibleAutoplayNotPermittedKey());
}

void WebPreferences::setInterruptVideoOnPageVisibilityChangeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::interruptVideoOnPageVisibilityChangeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::interruptVideoOnPageVisibilityChangeEnabledKey(), value, false);
}

bool WebPreferences::interruptVideoOnPageVisibilityChangeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::interruptVideoOnPageVisibilityChangeEnabledKey());
}

void WebPreferences::deleteInterruptVideoOnPageVisibilityChangeEnabled()
{
    deleteKey(WebPreferencesKey::interruptVideoOnPageVisibilityChangeEnabledKey());
}

void WebPreferences::setInterruptAudioOnPageVisibilityChangeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::interruptAudioOnPageVisibilityChangeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::interruptAudioOnPageVisibilityChangeEnabledKey(), value, false);
}

bool WebPreferences::interruptAudioOnPageVisibilityChangeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::interruptAudioOnPageVisibilityChangeEnabledKey());
}

void WebPreferences::deleteInterruptAudioOnPageVisibilityChangeEnabled()
{
    deleteKey(WebPreferencesKey::interruptAudioOnPageVisibilityChangeEnabledKey());
}

void WebPreferences::setVP9DecoderEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::vp9DecoderEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::vp9DecoderEnabledKey(), value, false);
}

bool WebPreferences::vp9DecoderEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::vp9DecoderEnabledKey());
}

void WebPreferences::deleteVP9DecoderEnabled()
{
    deleteKey(WebPreferencesKey::vp9DecoderEnabledKey());
}

void WebPreferences::setMediaUserGestureInheritsFromDocument(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaUserGestureInheritsFromDocumentKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaUserGestureInheritsFromDocumentKey(), value, false);
}

bool WebPreferences::mediaUserGestureInheritsFromDocument() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaUserGestureInheritsFromDocumentKey());
}

void WebPreferences::deleteMediaUserGestureInheritsFromDocument()
{
    deleteKey(WebPreferencesKey::mediaUserGestureInheritsFromDocumentKey());
}

void WebPreferences::setMediaVideoCodecIDsAllowedInLockdownMode(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::mediaVideoCodecIDsAllowedInLockdownModeKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::mediaVideoCodecIDsAllowedInLockdownModeKey(), value, false);
}

String WebPreferences::mediaVideoCodecIDsAllowedInLockdownMode() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::mediaVideoCodecIDsAllowedInLockdownModeKey());
}

void WebPreferences::deleteMediaVideoCodecIDsAllowedInLockdownMode()
{
    deleteKey(WebPreferencesKey::mediaVideoCodecIDsAllowedInLockdownModeKey());
}

void WebPreferences::setInteractionRegionMinimumCornerRadius(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::interactionRegionMinimumCornerRadiusKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::interactionRegionMinimumCornerRadiusKey(), value, false);
}

double WebPreferences::interactionRegionMinimumCornerRadius() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::interactionRegionMinimumCornerRadiusKey());
}

void WebPreferences::deleteInteractionRegionMinimumCornerRadius()
{
    deleteKey(WebPreferencesKey::interactionRegionMinimumCornerRadiusKey());
}

void WebPreferences::setInteractionRegionInlinePadding(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::interactionRegionInlinePaddingKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::interactionRegionInlinePaddingKey(), value, false);
}

double WebPreferences::interactionRegionInlinePadding() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::interactionRegionInlinePaddingKey());
}

void WebPreferences::deleteInteractionRegionInlinePadding()
{
    deleteKey(WebPreferencesKey::interactionRegionInlinePaddingKey());
}

void WebPreferences::setInspectorWindowFrame(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::inspectorWindowFrameKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::inspectorWindowFrameKey(), value, false);
}

String WebPreferences::inspectorWindowFrame() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::inspectorWindowFrameKey());
}

void WebPreferences::deleteInspectorWindowFrame()
{
    deleteKey(WebPreferencesKey::inspectorWindowFrameKey());
}

void WebPreferences::setInspectorSupportsShowingCertificate(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inspectorSupportsShowingCertificateKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inspectorSupportsShowingCertificateKey(), value, false);
}

bool WebPreferences::inspectorSupportsShowingCertificate() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inspectorSupportsShowingCertificateKey());
}

void WebPreferences::deleteInspectorSupportsShowingCertificate()
{
    deleteKey(WebPreferencesKey::inspectorSupportsShowingCertificateKey());
}

void WebPreferences::setInspectorStartsAttached(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inspectorStartsAttachedKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inspectorStartsAttachedKey(), value, false);
}

bool WebPreferences::inspectorStartsAttached() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inspectorStartsAttachedKey());
}

void WebPreferences::deleteInspectorStartsAttached()
{
    deleteKey(WebPreferencesKey::inspectorStartsAttachedKey());
}

void WebPreferences::setInspectorMaximumResourcesContentSize(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::inspectorMaximumResourcesContentSizeKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::inspectorMaximumResourcesContentSizeKey(), value, false);
}

uint32_t WebPreferences::inspectorMaximumResourcesContentSize() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::inspectorMaximumResourcesContentSizeKey());
}

void WebPreferences::deleteInspectorMaximumResourcesContentSize()
{
    deleteKey(WebPreferencesKey::inspectorMaximumResourcesContentSizeKey());
}

void WebPreferences::setInspectorAttachmentSide(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::inspectorAttachmentSideKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::inspectorAttachmentSideKey(), value, false);
}

uint32_t WebPreferences::inspectorAttachmentSide() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::inspectorAttachmentSideKey());
}

void WebPreferences::deleteInspectorAttachmentSide()
{
    deleteKey(WebPreferencesKey::inspectorAttachmentSideKey());
}

void WebPreferences::setInspectorAttachedWidth(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::inspectorAttachedWidthKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::inspectorAttachedWidthKey(), value, false);
}

uint32_t WebPreferences::inspectorAttachedWidth() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::inspectorAttachedWidthKey());
}

void WebPreferences::deleteInspectorAttachedWidth()
{
    deleteKey(WebPreferencesKey::inspectorAttachedWidthKey());
}

void WebPreferences::setInspectorAttachedHeight(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::inspectorAttachedHeightKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::inspectorAttachedHeightKey(), value, false);
}

uint32_t WebPreferences::inspectorAttachedHeight() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::inspectorAttachedHeightKey());
}

void WebPreferences::deleteInspectorAttachedHeight()
{
    deleteKey(WebPreferencesKey::inspectorAttachedHeightKey());
}

void WebPreferences::setMinimumFontSize(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::minimumFontSizeKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::minimumFontSizeKey(), value, false);
}

double WebPreferences::minimumFontSize() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::minimumFontSizeKey());
}

void WebPreferences::deleteMinimumFontSize()
{
    deleteKey(WebPreferencesKey::minimumFontSizeKey());
}

void WebPreferences::setMinimumLogicalFontSize(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::minimumLogicalFontSizeKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::minimumLogicalFontSizeKey(), value, false);
}

double WebPreferences::minimumLogicalFontSize() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::minimumLogicalFontSizeKey());
}

void WebPreferences::deleteMinimumLogicalFontSize()
{
    deleteKey(WebPreferencesKey::minimumLogicalFontSizeKey());
}

void WebPreferences::setMinimumZoomFontSize(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::minimumZoomFontSizeKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::minimumZoomFontSizeKey(), value, false);
}

double WebPreferences::minimumZoomFontSize() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::minimumZoomFontSizeKey());
}

void WebPreferences::deleteMinimumZoomFontSize()
{
    deleteKey(WebPreferencesKey::minimumZoomFontSizeKey());
}

void WebPreferences::setMockCaptureDevicesPromptEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mockCaptureDevicesPromptEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mockCaptureDevicesPromptEnabledKey(), value, false);
}

bool WebPreferences::mockCaptureDevicesPromptEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mockCaptureDevicesPromptEnabledKey());
}

void WebPreferences::deleteMockCaptureDevicesPromptEnabled()
{
    deleteKey(WebPreferencesKey::mockCaptureDevicesPromptEnabledKey());
}

void WebPreferences::setMockScrollbarsControllerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mockScrollbarsControllerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mockScrollbarsControllerEnabledKey(), value, false);
}

bool WebPreferences::mockScrollbarsControllerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mockScrollbarsControllerEnabledKey());
}

void WebPreferences::deleteMockScrollbarsControllerEnabled()
{
    deleteKey(WebPreferencesKey::mockScrollbarsControllerEnabledKey());
}

void WebPreferences::setMockScrollbarsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mockScrollbarsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mockScrollbarsEnabledKey(), value, false);
}

bool WebPreferences::mockScrollbarsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mockScrollbarsEnabledKey());
}

void WebPreferences::deleteMockScrollbarsEnabled()
{
    deleteKey(WebPreferencesKey::mockScrollbarsEnabledKey());
}

void WebPreferences::setInlineMediaPlaybackRequiresPlaysInlineAttribute(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inlineMediaPlaybackRequiresPlaysInlineAttributeKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inlineMediaPlaybackRequiresPlaysInlineAttributeKey(), value, false);
}

bool WebPreferences::inlineMediaPlaybackRequiresPlaysInlineAttribute() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inlineMediaPlaybackRequiresPlaysInlineAttributeKey());
}

void WebPreferences::deleteInlineMediaPlaybackRequiresPlaysInlineAttribute()
{
    deleteKey(WebPreferencesKey::inlineMediaPlaybackRequiresPlaysInlineAttributeKey());
}

void WebPreferences::setIncrementalRenderingSuppressionTimeout(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::incrementalRenderingSuppressionTimeoutKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::incrementalRenderingSuppressionTimeoutKey(), value, false);
}

double WebPreferences::incrementalRenderingSuppressionTimeout() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::incrementalRenderingSuppressionTimeoutKey());
}

void WebPreferences::deleteIncrementalRenderingSuppressionTimeout()
{
    deleteKey(WebPreferencesKey::incrementalRenderingSuppressionTimeoutKey());
}

void WebPreferences::setIncrementalPDFLoadingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::incrementalPDFLoadingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::incrementalPDFLoadingEnabledKey(), value, false);
}

bool WebPreferences::incrementalPDFLoadingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::incrementalPDFLoadingEnabledKey());
}

void WebPreferences::deleteIncrementalPDFLoadingEnabled()
{
    deleteKey(WebPreferencesKey::incrementalPDFLoadingEnabledKey());
}

void WebPreferences::setIncompleteImageBorderEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::incompleteImageBorderEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::incompleteImageBorderEnabledKey(), value, false);
}

bool WebPreferences::incompleteImageBorderEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::incompleteImageBorderEnabledKey());
}

void WebPreferences::deleteIncompleteImageBorderEnabled()
{
    deleteKey(WebPreferencesKey::incompleteImageBorderEnabledKey());
}

void WebPreferences::setNeedsAdobeFrameReloadingQuirk(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::needsAdobeFrameReloadingQuirkKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::needsAdobeFrameReloadingQuirkKey(), value, false);
}

bool WebPreferences::needsAdobeFrameReloadingQuirk() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::needsAdobeFrameReloadingQuirkKey());
}

void WebPreferences::deleteNeedsAdobeFrameReloadingQuirk()
{
    deleteKey(WebPreferencesKey::needsAdobeFrameReloadingQuirkKey());
}

void WebPreferences::setInactiveMediaCaptureStreamRepromptIntervalInMinutes(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::inactiveMediaCaptureStreamRepromptIntervalInMinutesKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::inactiveMediaCaptureStreamRepromptIntervalInMinutesKey(), value, false);
}

double WebPreferences::inactiveMediaCaptureStreamRepromptIntervalInMinutes() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::inactiveMediaCaptureStreamRepromptIntervalInMinutesKey());
}

void WebPreferences::deleteInactiveMediaCaptureStreamRepromptIntervalInMinutes()
{
    deleteKey(WebPreferencesKey::inactiveMediaCaptureStreamRepromptIntervalInMinutesKey());
}

void WebPreferences::setNeedsFrameNameFallbackToIdQuirk(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::needsFrameNameFallbackToIdQuirkKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::needsFrameNameFallbackToIdQuirkKey(), value, false);
}

bool WebPreferences::needsFrameNameFallbackToIdQuirk() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::needsFrameNameFallbackToIdQuirkKey());
}

void WebPreferences::deleteNeedsFrameNameFallbackToIdQuirk()
{
    deleteKey(WebPreferencesKey::needsFrameNameFallbackToIdQuirkKey());
}

void WebPreferences::setNeedsKeyboardEventDisambiguationQuirks(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::needsKeyboardEventDisambiguationQuirksKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::needsKeyboardEventDisambiguationQuirksKey(), value, false);
}

bool WebPreferences::needsKeyboardEventDisambiguationQuirks() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::needsKeyboardEventDisambiguationQuirksKey());
}

void WebPreferences::deleteNeedsKeyboardEventDisambiguationQuirks()
{
    deleteKey(WebPreferencesKey::needsKeyboardEventDisambiguationQuirksKey());
}

void WebPreferences::setPDFPluginEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pdfPluginEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pdfPluginEnabledKey(), value, false);
}

bool WebPreferences::pdfPluginEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pdfPluginEnabledKey());
}

void WebPreferences::deletePDFPluginEnabled()
{
    deleteKey(WebPreferencesKey::pdfPluginEnabledKey());
}

void WebPreferences::setPDFPluginHUDEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pdfPluginHUDEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pdfPluginHUDEnabledKey(), value, false);
}

bool WebPreferences::pdfPluginHUDEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pdfPluginHUDEnabledKey());
}

void WebPreferences::deletePDFPluginHUDEnabled()
{
    deleteKey(WebPreferencesKey::pdfPluginHUDEnabledKey());
}

void WebPreferences::setPDFPluginPageNumberIndicatorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pdfPluginPageNumberIndicatorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pdfPluginPageNumberIndicatorEnabledKey(), value, false);
}

bool WebPreferences::pdfPluginPageNumberIndicatorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pdfPluginPageNumberIndicatorEnabledKey());
}

void WebPreferences::deletePDFPluginPageNumberIndicatorEnabled()
{
    deleteKey(WebPreferencesKey::pdfPluginPageNumberIndicatorEnabledKey());
}

void WebPreferences::setPassiveTouchListenersAsDefaultOnDocument(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::passiveTouchListenersAsDefaultOnDocumentKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::passiveTouchListenersAsDefaultOnDocumentKey(), value, false);
}

bool WebPreferences::passiveTouchListenersAsDefaultOnDocument() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::passiveTouchListenersAsDefaultOnDocumentKey());
}

void WebPreferences::deletePassiveTouchListenersAsDefaultOnDocument()
{
    deleteKey(WebPreferencesKey::passiveTouchListenersAsDefaultOnDocumentKey());
}

void WebPreferences::setPasswordEchoDuration(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::passwordEchoDurationKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::passwordEchoDurationKey(), value, false);
}

double WebPreferences::passwordEchoDuration() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::passwordEchoDurationKey());
}

void WebPreferences::deletePasswordEchoDuration()
{
    deleteKey(WebPreferencesKey::passwordEchoDurationKey());
}

void WebPreferences::setPasswordEchoEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::passwordEchoEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::passwordEchoEnabledKey(), value, false);
}

bool WebPreferences::passwordEchoEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::passwordEchoEnabledKey());
}

void WebPreferences::deletePasswordEchoEnabled()
{
    deleteKey(WebPreferencesKey::passwordEchoEnabledKey());
}

void WebPreferences::setPictographFontFamily(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::pictographFontFamilyKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::pictographFontFamilyKey(), value, false);
}

String WebPreferences::pictographFontFamily() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::pictographFontFamilyKey());
}

void WebPreferences::deletePictographFontFamily()
{
    deleteKey(WebPreferencesKey::pictographFontFamilyKey());
}

void WebPreferences::setPictureInPictureAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pictureInPictureAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pictureInPictureAPIEnabledKey(), value, false);
}

bool WebPreferences::pictureInPictureAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pictureInPictureAPIEnabledKey());
}

void WebPreferences::deletePictureInPictureAPIEnabled()
{
    deleteKey(WebPreferencesKey::pictureInPictureAPIEnabledKey());
}

void WebPreferences::setPitchCorrectionAlgorithm(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::pitchCorrectionAlgorithmKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::pitchCorrectionAlgorithmKey(), value, false);
}

uint32_t WebPreferences::pitchCorrectionAlgorithm() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::pitchCorrectionAlgorithmKey());
}

void WebPreferences::deletePitchCorrectionAlgorithm()
{
    deleteKey(WebPreferencesKey::pitchCorrectionAlgorithmKey());
}

void WebPreferences::setPunchOutWhiteBackgroundsInDarkMode(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::punchOutWhiteBackgroundsInDarkModeKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::punchOutWhiteBackgroundsInDarkModeKey(), value, false);
}

bool WebPreferences::punchOutWhiteBackgroundsInDarkMode() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::punchOutWhiteBackgroundsInDarkModeKey());
}

void WebPreferences::deletePunchOutWhiteBackgroundsInDarkMode()
{
    deleteKey(WebPreferencesKey::punchOutWhiteBackgroundsInDarkModeKey());
}

void WebPreferences::setRequiresPageVisibilityForVideoToBeNowPlaying(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requiresPageVisibilityForVideoToBeNowPlayingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requiresPageVisibilityForVideoToBeNowPlayingKey(), value, false);
}

bool WebPreferences::requiresPageVisibilityForVideoToBeNowPlaying() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requiresPageVisibilityForVideoToBeNowPlayingKey());
}

void WebPreferences::deleteRequiresPageVisibilityForVideoToBeNowPlaying()
{
    deleteKey(WebPreferencesKey::requiresPageVisibilityForVideoToBeNowPlayingKey());
}

void WebPreferences::setRequiresPageVisibilityToPlayAudio(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requiresPageVisibilityToPlayAudioKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requiresPageVisibilityToPlayAudioKey(), value, false);
}

bool WebPreferences::requiresPageVisibilityToPlayAudio() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requiresPageVisibilityToPlayAudioKey());
}

void WebPreferences::deleteRequiresPageVisibilityToPlayAudio()
{
    deleteKey(WebPreferencesKey::requiresPageVisibilityToPlayAudioKey());
}

void WebPreferences::setHiddenPageCSSAnimationSuspensionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::hiddenPageCSSAnimationSuspensionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::hiddenPageCSSAnimationSuspensionEnabledKey(), value, false);
}

bool WebPreferences::hiddenPageCSSAnimationSuspensionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::hiddenPageCSSAnimationSuspensionEnabledKey());
}

void WebPreferences::deleteHiddenPageCSSAnimationSuspensionEnabled()
{
    deleteKey(WebPreferencesKey::hiddenPageCSSAnimationSuspensionEnabledKey());
}

void WebPreferences::setRequiresUserGestureForAudioPlayback(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requiresUserGestureForAudioPlaybackKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requiresUserGestureForAudioPlaybackKey(), value, false);
}

bool WebPreferences::requiresUserGestureForAudioPlayback() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requiresUserGestureForAudioPlaybackKey());
}

void WebPreferences::deleteRequiresUserGestureForAudioPlayback()
{
    deleteKey(WebPreferencesKey::requiresUserGestureForAudioPlaybackKey());
}

void WebPreferences::setRequiresUserGestureForMediaPlayback(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requiresUserGestureForMediaPlaybackKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requiresUserGestureForMediaPlaybackKey(), value, false);
}

bool WebPreferences::requiresUserGestureForMediaPlayback() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requiresUserGestureForMediaPlaybackKey());
}

void WebPreferences::deleteRequiresUserGestureForMediaPlayback()
{
    deleteKey(WebPreferencesKey::requiresUserGestureForMediaPlaybackKey());
}

void WebPreferences::setRequiresUserGestureForVideoPlayback(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requiresUserGestureForVideoPlaybackKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requiresUserGestureForVideoPlaybackKey(), value, false);
}

bool WebPreferences::requiresUserGestureForVideoPlayback() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requiresUserGestureForVideoPlaybackKey());
}

void WebPreferences::deleteRequiresUserGestureForVideoPlayback()
{
    deleteKey(WebPreferencesKey::requiresUserGestureForVideoPlaybackKey());
}

void WebPreferences::setRequiresUserGestureToLoadVideo(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requiresUserGestureToLoadVideoKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requiresUserGestureToLoadVideoKey(), value, false);
}

bool WebPreferences::requiresUserGestureToLoadVideo() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requiresUserGestureToLoadVideoKey());
}

void WebPreferences::deleteRequiresUserGestureToLoadVideo()
{
    deleteKey(WebPreferencesKey::requiresUserGestureToLoadVideoKey());
}

void WebPreferences::setUsesSingleWebProcess(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::usesSingleWebProcessKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::usesSingleWebProcessKey(), value, false);
}

bool WebPreferences::usesSingleWebProcess() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::usesSingleWebProcessKey());
}

void WebPreferences::deleteUsesSingleWebProcess()
{
    deleteKey(WebPreferencesKey::usesSingleWebProcessKey());
}

void WebPreferences::setRubberBandingForSubScrollableRegionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::rubberBandingForSubScrollableRegionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::rubberBandingForSubScrollableRegionsEnabledKey(), value, false);
}

bool WebPreferences::rubberBandingForSubScrollableRegionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::rubberBandingForSubScrollableRegionsEnabledKey());
}

void WebPreferences::deleteRubberBandingForSubScrollableRegionsEnabled()
{
    deleteKey(WebPreferencesKey::rubberBandingForSubScrollableRegionsEnabledKey());
}

void WebPreferences::setSampledPageTopColorMaxDifference(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::sampledPageTopColorMaxDifferenceKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::sampledPageTopColorMaxDifferenceKey(), value, false);
}

double WebPreferences::sampledPageTopColorMaxDifference() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::sampledPageTopColorMaxDifferenceKey());
}

void WebPreferences::deleteSampledPageTopColorMaxDifference()
{
    deleteKey(WebPreferencesKey::sampledPageTopColorMaxDifferenceKey());
}

void WebPreferences::setSampledPageTopColorMinHeight(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::sampledPageTopColorMinHeightKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::sampledPageTopColorMinHeightKey(), value, false);
}

double WebPreferences::sampledPageTopColorMinHeight() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::sampledPageTopColorMinHeightKey());
}

void WebPreferences::deleteSampledPageTopColorMinHeight()
{
    deleteKey(WebPreferencesKey::sampledPageTopColorMinHeightKey());
}

void WebPreferences::setUsesEncodingDetector(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::usesEncodingDetectorKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::usesEncodingDetectorKey(), value, false);
}

bool WebPreferences::usesEncodingDetector() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::usesEncodingDetectorKey());
}

void WebPreferences::deleteUsesEncodingDetector()
{
    deleteKey(WebPreferencesKey::usesEncodingDetectorKey());
}

void WebPreferences::setSansSerifFontFamily(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::sansSerifFontFamilyKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::sansSerifFontFamilyKey(), value, false);
}

String WebPreferences::sansSerifFontFamily() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::sansSerifFontFamilyKey());
}

void WebPreferences::deleteSansSerifFontFamily()
{
    deleteKey(WebPreferencesKey::sansSerifFontFamilyKey());
}

void WebPreferences::setSelectTrailingWhitespaceEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::selectTrailingWhitespaceEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::selectTrailingWhitespaceEnabledKey(), value, false);
}

bool WebPreferences::selectTrailingWhitespaceEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::selectTrailingWhitespaceEnabledKey());
}

void WebPreferences::deleteSelectTrailingWhitespaceEnabled()
{
    deleteKey(WebPreferencesKey::selectTrailingWhitespaceEnabledKey());
}

void WebPreferences::setSerifFontFamily(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::serifFontFamilyKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::serifFontFamilyKey(), value, false);
}

String WebPreferences::serifFontFamily() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::serifFontFamilyKey());
}

void WebPreferences::deleteSerifFontFamily()
{
    deleteKey(WebPreferencesKey::serifFontFamilyKey());
}

void WebPreferences::setUsesBackForwardCache(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::usesBackForwardCacheKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::usesBackForwardCacheKey(), value, false);
}

bool WebPreferences::usesBackForwardCache() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::usesBackForwardCacheKey());
}

void WebPreferences::deleteUsesBackForwardCache()
{
    deleteKey(WebPreferencesKey::usesBackForwardCacheKey());
}

void WebPreferences::setUserInterfaceDirectionPolicy(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::userInterfaceDirectionPolicyKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::userInterfaceDirectionPolicyKey(), value, false);
}

uint32_t WebPreferences::userInterfaceDirectionPolicy() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::userInterfaceDirectionPolicyKey());
}

void WebPreferences::deleteUserInterfaceDirectionPolicy()
{
    deleteKey(WebPreferencesKey::userInterfaceDirectionPolicyKey());
}

void WebPreferences::setCaretBrowsingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::caretBrowsingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::caretBrowsingEnabledKey(), value, false);
}

bool WebPreferences::caretBrowsingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::caretBrowsingEnabledKey());
}

void WebPreferences::deleteCaretBrowsingEnabled()
{
    deleteKey(WebPreferencesKey::caretBrowsingEnabledKey());
}

void WebPreferences::setUseSystemAppearance(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useSystemAppearanceKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useSystemAppearanceKey(), value, false);
}

bool WebPreferences::useSystemAppearance() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useSystemAppearanceKey());
}

void WebPreferences::deleteUseSystemAppearance()
{
    deleteKey(WebPreferencesKey::useSystemAppearanceKey());
}

void WebPreferences::setServiceControlsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::serviceControlsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::serviceControlsEnabledKey(), value, false);
}

bool WebPreferences::serviceControlsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::serviceControlsEnabledKey());
}

void WebPreferences::deleteServiceControlsEnabled()
{
    deleteKey(WebPreferencesKey::serviceControlsEnabledKey());
}

void WebPreferences::setGStreamerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isGStreamerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isGStreamerEnabledKey(), value, false);
}

bool WebPreferences::isGStreamerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isGStreamerEnabledKey());
}

void WebPreferences::deleteGStreamerEnabled()
{
    deleteKey(WebPreferencesKey::isGStreamerEnabledKey());
}

void WebPreferences::setServiceWorkerEntitlementDisabledForTesting(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::serviceWorkerEntitlementDisabledForTestingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::serviceWorkerEntitlementDisabledForTestingKey(), value, false);
}

bool WebPreferences::serviceWorkerEntitlementDisabledForTesting() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::serviceWorkerEntitlementDisabledForTestingKey());
}

void WebPreferences::deleteServiceWorkerEntitlementDisabledForTesting()
{
    deleteKey(WebPreferencesKey::serviceWorkerEntitlementDisabledForTestingKey());
}

void WebPreferences::setShouldAllowUserInstalledFonts(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldAllowUserInstalledFontsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldAllowUserInstalledFontsKey(), value, false);
}

bool WebPreferences::shouldAllowUserInstalledFonts() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldAllowUserInstalledFontsKey());
}

void WebPreferences::deleteShouldAllowUserInstalledFonts()
{
    deleteKey(WebPreferencesKey::shouldAllowUserInstalledFontsKey());
}

void WebPreferences::setColorFilterEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::colorFilterEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::colorFilterEnabledKey(), value, false);
}

bool WebPreferences::colorFilterEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::colorFilterEnabledKey());
}

void WebPreferences::deleteColorFilterEnabled()
{
    deleteKey(WebPreferencesKey::colorFilterEnabledKey());
}

void WebPreferences::setUsePreHTML5ParserQuirks(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::usePreHTML5ParserQuirksKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::usePreHTML5ParserQuirksKey(), value, false);
}

bool WebPreferences::usePreHTML5ParserQuirks() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::usePreHTML5ParserQuirksKey());
}

void WebPreferences::deleteUsePreHTML5ParserQuirks()
{
    deleteKey(WebPreferencesKey::usePreHTML5ParserQuirksKey());
}

void WebPreferences::setShouldConvertInvalidURLsToBlank(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldConvertInvalidURLsToBlankKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldConvertInvalidURLsToBlankKey(), value, false);
}

bool WebPreferences::shouldConvertInvalidURLsToBlank() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldConvertInvalidURLsToBlankKey());
}

void WebPreferences::deleteShouldConvertInvalidURLsToBlank()
{
    deleteKey(WebPreferencesKey::shouldConvertInvalidURLsToBlankKey());
}

void WebPreferences::setShouldConvertPositionStyleOnCopy(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldConvertPositionStyleOnCopyKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldConvertPositionStyleOnCopyKey(), value, false);
}

bool WebPreferences::shouldConvertPositionStyleOnCopy() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldConvertPositionStyleOnCopyKey());
}

void WebPreferences::deleteShouldConvertPositionStyleOnCopy()
{
    deleteKey(WebPreferencesKey::shouldConvertPositionStyleOnCopyKey());
}

void WebPreferences::setShouldDecidePolicyBeforeLoadingQuickLookPreview(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldDecidePolicyBeforeLoadingQuickLookPreviewKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldDecidePolicyBeforeLoadingQuickLookPreviewKey(), value, false);
}

bool WebPreferences::shouldDecidePolicyBeforeLoadingQuickLookPreview() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldDecidePolicyBeforeLoadingQuickLookPreviewKey());
}

void WebPreferences::deleteShouldDecidePolicyBeforeLoadingQuickLookPreview()
{
    deleteKey(WebPreferencesKey::shouldDecidePolicyBeforeLoadingQuickLookPreviewKey());
}

void WebPreferences::setShouldDisplayCaptions(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldDisplayCaptionsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldDisplayCaptionsKey(), value, false);
}

bool WebPreferences::shouldDisplayCaptions() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldDisplayCaptionsKey());
}

void WebPreferences::deleteShouldDisplayCaptions()
{
    deleteKey(WebPreferencesKey::shouldDisplayCaptionsKey());
}

void WebPreferences::setContentChangeObserverEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::contentChangeObserverEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::contentChangeObserverEnabledKey(), value, false);
}

bool WebPreferences::contentChangeObserverEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::contentChangeObserverEnabledKey());
}

void WebPreferences::deleteContentChangeObserverEnabled()
{
    deleteKey(WebPreferencesKey::contentChangeObserverEnabledKey());
}

void WebPreferences::setContentDispositionAttachmentSandboxEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::contentDispositionAttachmentSandboxEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::contentDispositionAttachmentSandboxEnabledKey(), value, false);
}

bool WebPreferences::contentDispositionAttachmentSandboxEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::contentDispositionAttachmentSandboxEnabledKey());
}

void WebPreferences::deleteContentDispositionAttachmentSandboxEnabled()
{
    deleteKey(WebPreferencesKey::contentDispositionAttachmentSandboxEnabledKey());
}

void WebPreferences::setForceWebGLUsesLowPower(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::forceWebGLUsesLowPowerKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::forceWebGLUsesLowPowerKey(), value, false);
}

bool WebPreferences::forceWebGLUsesLowPower() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::forceWebGLUsesLowPowerKey());
}

void WebPreferences::deleteForceWebGLUsesLowPower()
{
    deleteKey(WebPreferencesKey::forceWebGLUsesLowPowerKey());
}

void WebPreferences::setContextMenuQRCodeDetectionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::contextMenuQRCodeDetectionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::contextMenuQRCodeDetectionEnabledKey(), value, false);
}

bool WebPreferences::contextMenuQRCodeDetectionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::contextMenuQRCodeDetectionEnabledKey());
}

void WebPreferences::deleteContextMenuQRCodeDetectionEnabled()
{
    deleteKey(WebPreferencesKey::contextMenuQRCodeDetectionEnabledKey());
}

void WebPreferences::setShouldDisplaySubtitles(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldDisplaySubtitlesKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldDisplaySubtitlesKey(), value, false);
}

bool WebPreferences::shouldDisplaySubtitles() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldDisplaySubtitlesKey());
}

void WebPreferences::deleteShouldDisplaySubtitles()
{
    deleteKey(WebPreferencesKey::shouldDisplaySubtitlesKey());
}

void WebPreferences::setForceFTPDirectoryListings(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::forceFTPDirectoryListingsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::forceFTPDirectoryListingsKey(), value, false);
}

bool WebPreferences::forceFTPDirectoryListings() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::forceFTPDirectoryListingsKey());
}

void WebPreferences::deleteForceFTPDirectoryListings()
{
    deleteKey(WebPreferencesKey::forceFTPDirectoryListingsKey());
}

void WebPreferences::setForceCompositingMode(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::forceCompositingModeKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::forceCompositingModeKey(), value, false);
}

bool WebPreferences::forceCompositingMode() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::forceCompositingModeKey());
}

void WebPreferences::deleteForceCompositingMode()
{
    deleteKey(WebPreferencesKey::forceCompositingModeKey());
}

void WebPreferences::setShouldDisplayTextDescriptions(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldDisplayTextDescriptionsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldDisplayTextDescriptionsKey(), value, false);
}

bool WebPreferences::shouldDisplayTextDescriptions() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldDisplayTextDescriptionsKey());
}

void WebPreferences::deleteShouldDisplayTextDescriptions()
{
    deleteKey(WebPreferencesKey::shouldDisplayTextDescriptionsKey());
}

void WebPreferences::setShouldEnableTextAutosizingBoost(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldEnableTextAutosizingBoostKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldEnableTextAutosizingBoostKey(), value, false);
}

bool WebPreferences::shouldEnableTextAutosizingBoost() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldEnableTextAutosizingBoostKey());
}

void WebPreferences::deleteShouldEnableTextAutosizingBoost()
{
    deleteKey(WebPreferencesKey::shouldEnableTextAutosizingBoostKey());
}

void WebPreferences::setUseImageDocumentForSubframePDF(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useImageDocumentForSubframePDFKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useImageDocumentForSubframePDFKey(), value, false);
}

bool WebPreferences::useImageDocumentForSubframePDF() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useImageDocumentForSubframePDFKey());
}

void WebPreferences::deleteUseImageDocumentForSubframePDF()
{
    deleteKey(WebPreferencesKey::useImageDocumentForSubframePDFKey());
}

void WebPreferences::setFixedFontFamily(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::fixedFontFamilyKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::fixedFontFamilyKey(), value, false);
}

String WebPreferences::fixedFontFamily() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::fixedFontFamilyKey());
}

void WebPreferences::deleteFixedFontFamily()
{
    deleteKey(WebPreferencesKey::fixedFontFamilyKey());
}

void WebPreferences::setShouldIgnoreMetaViewport(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldIgnoreMetaViewportKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldIgnoreMetaViewportKey(), value, false);
}

bool WebPreferences::shouldIgnoreMetaViewport() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldIgnoreMetaViewportKey());
}

void WebPreferences::deleteShouldIgnoreMetaViewport()
{
    deleteKey(WebPreferencesKey::shouldIgnoreMetaViewportKey());
}

void WebPreferences::setShouldPrintBackgrounds(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldPrintBackgroundsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldPrintBackgroundsKey(), value, false);
}

bool WebPreferences::shouldPrintBackgrounds() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldPrintBackgroundsKey());
}

void WebPreferences::deleteShouldPrintBackgrounds()
{
    deleteKey(WebPreferencesKey::shouldPrintBackgroundsKey());
}

void WebPreferences::setCursiveFontFamily(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::cursiveFontFamilyKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::cursiveFontFamilyKey(), value, false);
}

String WebPreferences::cursiveFontFamily() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::cursiveFontFamilyKey());
}

void WebPreferences::deleteCursiveFontFamily()
{
    deleteKey(WebPreferencesKey::cursiveFontFamilyKey());
}

void WebPreferences::setShouldRespectImageOrientation(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldRespectImageOrientationKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldRespectImageOrientationKey(), value, false);
}

bool WebPreferences::shouldRespectImageOrientation() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldRespectImageOrientationKey());
}

void WebPreferences::deleteShouldRespectImageOrientation()
{
    deleteKey(WebPreferencesKey::shouldRespectImageOrientationKey());
}

void WebPreferences::setShouldRestrictBaseURLSchemes(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldRestrictBaseURLSchemesKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldRestrictBaseURLSchemesKey(), value, false);
}

bool WebPreferences::shouldRestrictBaseURLSchemes() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldRestrictBaseURLSchemesKey());
}

void WebPreferences::deleteShouldRestrictBaseURLSchemes()
{
    deleteKey(WebPreferencesKey::shouldRestrictBaseURLSchemesKey());
}

void WebPreferences::setShouldSuppressTextInputFromEditingDuringProvisionalNavigation(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldSuppressTextInputFromEditingDuringProvisionalNavigationKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldSuppressTextInputFromEditingDuringProvisionalNavigationKey(), value, false);
}

bool WebPreferences::shouldSuppressTextInputFromEditingDuringProvisionalNavigation() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldSuppressTextInputFromEditingDuringProvisionalNavigationKey());
}

void WebPreferences::deleteShouldSuppressTextInputFromEditingDuringProvisionalNavigation()
{
    deleteKey(WebPreferencesKey::shouldSuppressTextInputFromEditingDuringProvisionalNavigationKey());
}

void WebPreferences::setFantasyFontFamily(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::fantasyFontFamilyKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::fantasyFontFamilyKey(), value, false);
}

String WebPreferences::fantasyFontFamily() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::fantasyFontFamilyKey());
}

void WebPreferences::deleteFantasyFontFamily()
{
    deleteKey(WebPreferencesKey::fantasyFontFamilyKey());
}

void WebPreferences::setDOMPasteAllowed(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::domPasteAllowedKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::domPasteAllowedKey(), value, false);
}

bool WebPreferences::domPasteAllowed() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::domPasteAllowedKey());
}

void WebPreferences::deleteDOMPasteAllowed()
{
    deleteKey(WebPreferencesKey::domPasteAllowedKey());
}

void WebPreferences::setShouldUseServiceWorkerShortTimeout(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldUseServiceWorkerShortTimeoutKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldUseServiceWorkerShortTimeoutKey(), value, false);
}

bool WebPreferences::shouldUseServiceWorkerShortTimeout() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldUseServiceWorkerShortTimeoutKey());
}

void WebPreferences::deleteShouldUseServiceWorkerShortTimeout()
{
    deleteKey(WebPreferencesKey::shouldUseServiceWorkerShortTimeoutKey());
}

void WebPreferences::setFTPDirectoryTemplatePath(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::ftpDirectoryTemplatePathKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::ftpDirectoryTemplatePathKey(), value, false);
}

String WebPreferences::ftpDirectoryTemplatePath() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::ftpDirectoryTemplatePathKey());
}

void WebPreferences::deleteFTPDirectoryTemplatePath()
{
    deleteKey(WebPreferencesKey::ftpDirectoryTemplatePathKey());
}

void WebPreferences::setDataDetectorTypes(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::dataDetectorTypesKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::dataDetectorTypesKey(), value, false);
}

uint32_t WebPreferences::dataDetectorTypes() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::dataDetectorTypesKey());
}

void WebPreferences::deleteDataDetectorTypes()
{
    deleteKey(WebPreferencesKey::dataDetectorTypesKey());
}

void WebPreferences::setExtensibleSSOEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isExtensibleSSOEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isExtensibleSSOEnabledKey(), value, false);
}

bool WebPreferences::isExtensibleSSOEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isExtensibleSSOEnabledKey());
}

void WebPreferences::deleteExtensibleSSOEnabled()
{
    deleteKey(WebPreferencesKey::isExtensibleSSOEnabledKey());
}

void WebPreferences::setTreatsAnyTextCSSLinkAsStylesheet(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::treatsAnyTextCSSLinkAsStylesheetKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::treatsAnyTextCSSLinkAsStylesheetKey(), value, false);
}

bool WebPreferences::treatsAnyTextCSSLinkAsStylesheet() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::treatsAnyTextCSSLinkAsStylesheetKey());
}

void WebPreferences::deleteTreatsAnyTextCSSLinkAsStylesheet()
{
    deleteKey(WebPreferencesKey::treatsAnyTextCSSLinkAsStylesheetKey());
}

void WebPreferences::setLinkPreloadEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::linkPreloadEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::linkPreloadEnabledKey(), value, false);
}

bool WebPreferences::linkPreloadEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::linkPreloadEnabledKey());
}

void WebPreferences::deleteLinkPreloadEnabled()
{
    deleteKey(WebPreferencesKey::linkPreloadEnabledKey());
}

void WebPreferences::setShowsToolTipOverTruncatedText(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::showsToolTipOverTruncatedTextKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::showsToolTipOverTruncatedTextKey(), value, false);
}

bool WebPreferences::showsToolTipOverTruncatedText() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::showsToolTipOverTruncatedTextKey());
}

void WebPreferences::deleteShowsToolTipOverTruncatedText()
{
    deleteKey(WebPreferencesKey::showsToolTipOverTruncatedTextKey());
}

void WebPreferences::setThreadedScrollingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::threadedScrollingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::threadedScrollingEnabledKey(), value, false);
}

bool WebPreferences::threadedScrollingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::threadedScrollingEnabledKey());
}

void WebPreferences::deleteThreadedScrollingEnabled()
{
    deleteKey(WebPreferencesKey::threadedScrollingEnabledKey());
}

void WebPreferences::setDefaultFixedFontSize(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::defaultFixedFontSizeKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::defaultFixedFontSizeKey(), value, false);
}

double WebPreferences::defaultFixedFontSize() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::defaultFixedFontSizeKey());
}

void WebPreferences::deleteDefaultFixedFontSize()
{
    deleteKey(WebPreferencesKey::defaultFixedFontSizeKey());
}

void WebPreferences::setDefaultFontSize(const double& value)
{
    if (!m_store.setDoubleValueForKey(WebPreferencesKey::defaultFontSizeKey(), value))
        return;
    updateDoubleValueForKey(WebPreferencesKey::defaultFontSizeKey(), value, false);
}

double WebPreferences::defaultFontSize() const
{
    return m_store.getDoubleValueForKey(WebPreferencesKey::defaultFontSizeKey());
}

void WebPreferences::deleteDefaultFontSize()
{
    deleteKey(WebPreferencesKey::defaultFontSizeKey());
}

void WebPreferences::setDefaultTextEncodingName(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::defaultTextEncodingNameKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::defaultTextEncodingNameKey(), value, false);
}

String WebPreferences::defaultTextEncodingName() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::defaultTextEncodingNameKey());
}

void WebPreferences::deleteDefaultTextEncodingName()
{
    deleteKey(WebPreferencesKey::defaultTextEncodingNameKey());
}

void WebPreferences::setTextInteractionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::textInteractionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::textInteractionEnabledKey(), value, false);
}

bool WebPreferences::textInteractionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::textInteractionEnabledKey());
}

void WebPreferences::deleteTextInteractionEnabled()
{
    deleteKey(WebPreferencesKey::textInteractionEnabledKey());
}

void WebPreferences::setTextExtractionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::textExtractionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::textExtractionEnabledKey(), value, false);
}

bool WebPreferences::textExtractionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::textExtractionEnabledKey());
}

void WebPreferences::deleteTextExtractionEnabled()
{
    deleteKey(WebPreferencesKey::textExtractionEnabledKey());
}

void WebPreferences::setTextAutosizingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::textAutosizingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::textAutosizingEnabledKey(), value, false);
}

bool WebPreferences::textAutosizingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::textAutosizingEnabledKey());
}

void WebPreferences::deleteTextAutosizingEnabled()
{
    deleteKey(WebPreferencesKey::textAutosizingEnabledKey());
}

void WebPreferences::setDeveloperExtrasEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::developerExtrasEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::developerExtrasEnabledKey(), value, false);
}

bool WebPreferences::developerExtrasEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::developerExtrasEnabledKey());
}

void WebPreferences::deleteDeveloperExtrasEnabled()
{
    deleteKey(WebPreferencesKey::developerExtrasEnabledKey());
}

void WebPreferences::setDeviceHeight(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::deviceHeightKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::deviceHeightKey(), value, false);
}

uint32_t WebPreferences::deviceHeight() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::deviceHeightKey());
}

void WebPreferences::deleteDeviceHeight()
{
    deleteKey(WebPreferencesKey::deviceHeightKey());
}

void WebPreferences::setDeviceOrientationEventEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::deviceOrientationEventEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::deviceOrientationEventEnabledKey(), value, false);
}

bool WebPreferences::deviceOrientationEventEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::deviceOrientationEventEnabledKey());
}

void WebPreferences::deleteDeviceOrientationEventEnabled()
{
    deleteKey(WebPreferencesKey::deviceOrientationEventEnabledKey());
}

void WebPreferences::setDeviceOrientationPermissionAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::deviceOrientationPermissionAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::deviceOrientationPermissionAPIEnabledKey(), value, false);
}

bool WebPreferences::deviceOrientationPermissionAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::deviceOrientationPermissionAPIEnabledKey());
}

void WebPreferences::deleteDeviceOrientationPermissionAPIEnabled()
{
    deleteKey(WebPreferencesKey::deviceOrientationPermissionAPIEnabledKey());
}

void WebPreferences::setDeviceWidth(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::deviceWidthKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::deviceWidthKey(), value, false);
}

uint32_t WebPreferences::deviceWidth() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::deviceWidthKey());
}

void WebPreferences::deleteDeviceWidth()
{
    deleteKey(WebPreferencesKey::deviceWidthKey());
}

void WebPreferences::setShowsURLsInToolTipsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::showsURLsInToolTipsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::showsURLsInToolTipsEnabledKey(), value, false);
}

bool WebPreferences::showsURLsInToolTipsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::showsURLsInToolTipsEnabledKey());
}

void WebPreferences::deleteShowsURLsInToolTipsEnabled()
{
    deleteKey(WebPreferencesKey::showsURLsInToolTipsEnabledKey());
}

void WebPreferences::setTextAreasAreResizable(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::textAreasAreResizableKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::textAreasAreResizableKey(), value, false);
}

bool WebPreferences::textAreasAreResizable() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::textAreasAreResizableKey());
}

void WebPreferences::deleteTextAreasAreResizable()
{
    deleteKey(WebPreferencesKey::textAreasAreResizableKey());
}

void WebPreferences::setTemporaryTileCohortRetentionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::temporaryTileCohortRetentionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::temporaryTileCohortRetentionEnabledKey(), value, false);
}

bool WebPreferences::temporaryTileCohortRetentionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::temporaryTileCohortRetentionEnabledKey());
}

void WebPreferences::deleteTemporaryTileCohortRetentionEnabled()
{
    deleteKey(WebPreferencesKey::temporaryTileCohortRetentionEnabledKey());
}

void WebPreferences::setTelephoneNumberParsingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::telephoneNumberParsingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::telephoneNumberParsingEnabledKey(), value, false);
}

bool WebPreferences::telephoneNumberParsingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::telephoneNumberParsingEnabledKey());
}

void WebPreferences::deleteTelephoneNumberParsingEnabled()
{
    deleteKey(WebPreferencesKey::telephoneNumberParsingEnabledKey());
}

void WebPreferences::setShrinksStandaloneImagesToFit(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shrinksStandaloneImagesToFitKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shrinksStandaloneImagesToFitKey(), value, false);
}

bool WebPreferences::shrinksStandaloneImagesToFit() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shrinksStandaloneImagesToFitKey());
}

void WebPreferences::deleteShrinksStandaloneImagesToFit()
{
    deleteKey(WebPreferencesKey::shrinksStandaloneImagesToFitKey());
}

void WebPreferences::setDisabledAdaptationsMetaTagEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::disabledAdaptationsMetaTagEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::disabledAdaptationsMetaTagEnabledKey(), value, false);
}

bool WebPreferences::disabledAdaptationsMetaTagEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::disabledAdaptationsMetaTagEnabledKey());
}

void WebPreferences::deleteDisabledAdaptationsMetaTagEnabled()
{
    deleteKey(WebPreferencesKey::disabledAdaptationsMetaTagEnabledKey());
}

void WebPreferences::setDownloadAttributeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::downloadAttributeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::downloadAttributeEnabledKey(), value, false);
}

bool WebPreferences::downloadAttributeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::downloadAttributeEnabledKey());
}

void WebPreferences::deleteDownloadAttributeEnabled()
{
    deleteKey(WebPreferencesKey::downloadAttributeEnabledKey());
}

void WebPreferences::setTabsToLinks(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::tabsToLinksKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::tabsToLinksKey(), value, false);
}

bool WebPreferences::tabsToLinks() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::tabsToLinksKey());
}

void WebPreferences::deleteTabsToLinks()
{
    deleteKey(WebPreferencesKey::tabsToLinksKey());
}

void WebPreferences::setEditableLinkBehavior(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::editableLinkBehaviorKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::editableLinkBehaviorKey(), value, false);
}

uint32_t WebPreferences::editableLinkBehavior() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::editableLinkBehaviorKey());
}

void WebPreferences::deleteEditableLinkBehavior()
{
    deleteKey(WebPreferencesKey::editableLinkBehaviorKey());
}

void WebPreferences::setSystemPreviewEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::systemPreviewEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::systemPreviewEnabledKey(), value, false);
}

bool WebPreferences::systemPreviewEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::systemPreviewEnabledKey());
}

void WebPreferences::deleteSystemPreviewEnabled()
{
    deleteKey(WebPreferencesKey::systemPreviewEnabledKey());
}

void WebPreferences::setSystemLayoutDirection(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::systemLayoutDirectionKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::systemLayoutDirectionKey(), value, false);
}

uint32_t WebPreferences::systemLayoutDirection() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::systemLayoutDirectionKey());
}

void WebPreferences::deleteSystemLayoutDirection()
{
    deleteKey(WebPreferencesKey::systemLayoutDirectionKey());
}

void WebPreferences::setSuppressesIncrementalRendering(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::suppressesIncrementalRenderingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::suppressesIncrementalRenderingKey(), value, false);
}

bool WebPreferences::suppressesIncrementalRendering() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::suppressesIncrementalRenderingKey());
}

void WebPreferences::deleteSuppressesIncrementalRendering()
{
    deleteKey(WebPreferencesKey::suppressesIncrementalRenderingKey());
}

void WebPreferences::setStandardFontFamily(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::standardFontFamilyKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::standardFontFamilyKey(), value, false);
}

String WebPreferences::standardFontFamily() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::standardFontFamilyKey());
}

void WebPreferences::deleteStandardFontFamily()
{
    deleteKey(WebPreferencesKey::standardFontFamilyKey());
}

void WebPreferences::setEnableInheritURIQueryComponent(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::enableInheritURIQueryComponentKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::enableInheritURIQueryComponentKey(), value, false);
}

bool WebPreferences::enableInheritURIQueryComponent() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::enableInheritURIQueryComponentKey());
}

void WebPreferences::deleteEnableInheritURIQueryComponent()
{
    deleteKey(WebPreferencesKey::enableInheritURIQueryComponentKey());
}

void WebPreferences::setEncryptedMediaAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::encryptedMediaAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::encryptedMediaAPIEnabledKey(), value, false);
}

bool WebPreferences::encryptedMediaAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::encryptedMediaAPIEnabledKey());
}

void WebPreferences::deleteEncryptedMediaAPIEnabled()
{
    deleteKey(WebPreferencesKey::encryptedMediaAPIEnabledKey());
}

void WebPreferences::setStandalone(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::standaloneKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::standaloneKey(), value, false);
}

bool WebPreferences::standalone() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::standaloneKey());
}

void WebPreferences::deleteStandalone()
{
    deleteKey(WebPreferencesKey::standaloneKey());
}

void WebPreferences::setSmartInsertDeleteEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::smartInsertDeleteEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::smartInsertDeleteEnabledKey(), value, false);
}

bool WebPreferences::smartInsertDeleteEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::smartInsertDeleteEnabledKey());
}

void WebPreferences::deleteSmartInsertDeleteEnabled()
{
    deleteKey(WebPreferencesKey::smartInsertDeleteEnabledKey());
}

void WebPreferences::setSpatialNavigationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::spatialNavigationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::spatialNavigationEnabledKey(), value, false);
}

bool WebPreferences::spatialNavigationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::spatialNavigationEnabledKey());
}

void WebPreferences::deleteSpatialNavigationEnabled()
{
    deleteKey(WebPreferencesKey::spatialNavigationEnabledKey());
}

void WebPreferences::setSourceBufferChangeTypeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::sourceBufferChangeTypeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::sourceBufferChangeTypeEnabledKey(), value, false);
}

bool WebPreferences::sourceBufferChangeTypeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::sourceBufferChangeTypeEnabledKey());
}

void WebPreferences::deleteSourceBufferChangeTypeEnabled()
{
    deleteKey(WebPreferencesKey::sourceBufferChangeTypeEnabledKey());
}

void WebPreferences::setTargetTextPseudoElementEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::targetTextPseudoElementEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::targetTextPseudoElementEnabledKey(), value, false);
}

bool WebPreferences::targetTextPseudoElementEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::targetTextPseudoElementEnabledKey());
}

void WebPreferences::deleteTargetTextPseudoElementEnabled()
{
    deleteKey(WebPreferencesKey::targetTextPseudoElementEnabledKey());
}

void WebPreferences::setThumbAndTrackPseudoElementsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::thumbAndTrackPseudoElementsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::thumbAndTrackPseudoElementsEnabledKey(), value, true);
}

bool WebPreferences::thumbAndTrackPseudoElementsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::thumbAndTrackPseudoElementsEnabledKey());
}

void WebPreferences::deleteThumbAndTrackPseudoElementsEnabled()
{
    deleteKey(WebPreferencesKey::thumbAndTrackPseudoElementsEnabledKey());
}

void WebPreferences::setLinkDNSPrefetchEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::linkDNSPrefetchEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::linkDNSPrefetchEnabledKey(), value, false);
}

bool WebPreferences::linkDNSPrefetchEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::linkDNSPrefetchEnabledKey());
}

void WebPreferences::deleteLinkDNSPrefetchEnabled()
{
    deleteKey(WebPreferencesKey::linkDNSPrefetchEnabledKey());
}

void WebPreferences::setSelectShowPickerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::selectShowPickerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::selectShowPickerEnabledKey(), value, true);
}

bool WebPreferences::selectShowPickerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::selectShowPickerEnabledKey());
}

void WebPreferences::deleteSelectShowPickerEnabled()
{
    deleteKey(WebPreferencesKey::selectShowPickerEnabledKey());
}

void WebPreferences::setPageAtRuleMarginDescriptorsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pageAtRuleMarginDescriptorsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pageAtRuleMarginDescriptorsEnabledKey(), value, false);
}

bool WebPreferences::pageAtRuleMarginDescriptorsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pageAtRuleMarginDescriptorsEnabledKey());
}

void WebPreferences::deletePageAtRuleMarginDescriptorsEnabled()
{
    deleteKey(WebPreferencesKey::pageAtRuleMarginDescriptorsEnabledKey());
}

void WebPreferences::setAVFoundationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isAVFoundationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isAVFoundationEnabledKey(), value, false);
}

bool WebPreferences::isAVFoundationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isAVFoundationEnabledKey());
}

void WebPreferences::deleteAVFoundationEnabled()
{
    deleteKey(WebPreferencesKey::isAVFoundationEnabledKey());
}

void WebPreferences::setAVKitContentSourceEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isAVKitContentSourceEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isAVKitContentSourceEnabledKey(), value, true);
}

bool WebPreferences::isAVKitContentSourceEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isAVKitContentSourceEnabledKey());
}

void WebPreferences::deleteAVKitContentSourceEnabled()
{
    deleteKey(WebPreferencesKey::isAVKitContentSourceEnabledKey());
}

void WebPreferences::setAcceleratedFiltersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::acceleratedFiltersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::acceleratedFiltersEnabledKey(), value, true);
}

bool WebPreferences::acceleratedFiltersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::acceleratedFiltersEnabledKey());
}

void WebPreferences::deleteAcceleratedFiltersEnabled()
{
    deleteKey(WebPreferencesKey::acceleratedFiltersEnabledKey());
}

void WebPreferences::setAccessHandleEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::accessHandleEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::accessHandleEnabledKey(), value, false);
}

bool WebPreferences::accessHandleEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::accessHandleEnabledKey());
}

void WebPreferences::deleteAccessHandleEnabled()
{
    deleteKey(WebPreferencesKey::accessHandleEnabledKey());
}

void WebPreferences::setDOMTestingAPIsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::domTestingAPIsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::domTestingAPIsEnabledKey(), value, true);
}

bool WebPreferences::domTestingAPIsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::domTestingAPIsEnabledKey());
}

void WebPreferences::deleteDOMTestingAPIsEnabled()
{
    deleteKey(WebPreferencesKey::domTestingAPIsEnabledKey());
}

void WebPreferences::setAllowMediaContentTypesRequiringHardwareSupportAsFallback(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowMediaContentTypesRequiringHardwareSupportAsFallbackKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowMediaContentTypesRequiringHardwareSupportAsFallbackKey(), value, false);
}

bool WebPreferences::allowMediaContentTypesRequiringHardwareSupportAsFallback() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowMediaContentTypesRequiringHardwareSupportAsFallbackKey());
}

void WebPreferences::deleteAllowMediaContentTypesRequiringHardwareSupportAsFallback()
{
    deleteKey(WebPreferencesKey::allowMediaContentTypesRequiringHardwareSupportAsFallbackKey());
}

void WebPreferences::setAllowPrivacySensitiveOperationsInNonPersistentDataStores(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowPrivacySensitiveOperationsInNonPersistentDataStoresKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowPrivacySensitiveOperationsInNonPersistentDataStoresKey(), value, false);
}

bool WebPreferences::allowPrivacySensitiveOperationsInNonPersistentDataStores() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowPrivacySensitiveOperationsInNonPersistentDataStoresKey());
}

void WebPreferences::deleteAllowPrivacySensitiveOperationsInNonPersistentDataStores()
{
    deleteKey(WebPreferencesKey::allowPrivacySensitiveOperationsInNonPersistentDataStoresKey());
}

void WebPreferences::setAllowViewportShrinkToFitContent(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowViewportShrinkToFitContentKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowViewportShrinkToFitContentKey(), value, true);
}

bool WebPreferences::allowViewportShrinkToFitContent() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowViewportShrinkToFitContentKey());
}

void WebPreferences::deleteAllowViewportShrinkToFitContent()
{
    deleteKey(WebPreferencesKey::allowViewportShrinkToFitContentKey());
}

void WebPreferences::setAllowWebGLInWorkers(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowWebGLInWorkersKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowWebGLInWorkersKey(), value, false);
}

bool WebPreferences::allowWebGLInWorkers() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowWebGLInWorkersKey());
}

void WebPreferences::deleteAllowWebGLInWorkers()
{
    deleteKey(WebPreferencesKey::allowWebGLInWorkersKey());
}

void WebPreferences::setPerElementSpeakerSelectionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::perElementSpeakerSelectionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::perElementSpeakerSelectionEnabledKey(), value, true);
}

bool WebPreferences::perElementSpeakerSelectionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::perElementSpeakerSelectionEnabledKey());
}

void WebPreferences::deletePerElementSpeakerSelectionEnabled()
{
    deleteKey(WebPreferencesKey::perElementSpeakerSelectionEnabledKey());
}

void WebPreferences::setExposeSpeakersWithoutMicrophoneEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::exposeSpeakersWithoutMicrophoneEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::exposeSpeakersWithoutMicrophoneEnabledKey(), value, true);
}

bool WebPreferences::exposeSpeakersWithoutMicrophoneEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::exposeSpeakersWithoutMicrophoneEnabledKey());
}

void WebPreferences::deleteExposeSpeakersWithoutMicrophoneEnabled()
{
    deleteKey(WebPreferencesKey::exposeSpeakersWithoutMicrophoneEnabledKey());
}

void WebPreferences::setExposeSpeakersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::exposeSpeakersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::exposeSpeakersEnabledKey(), value, true);
}

bool WebPreferences::exposeSpeakersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::exposeSpeakersEnabledKey());
}

void WebPreferences::deleteExposeSpeakersEnabled()
{
    deleteKey(WebPreferencesKey::exposeSpeakersEnabledKey());
}

void WebPreferences::setAllowTopNavigationToDataURLs(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowTopNavigationToDataURLsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowTopNavigationToDataURLsKey(), value, false);
}

bool WebPreferences::allowTopNavigationToDataURLs() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowTopNavigationToDataURLsKey());
}

void WebPreferences::deleteAllowTopNavigationToDataURLs()
{
    deleteKey(WebPreferencesKey::allowTopNavigationToDataURLsKey());
}

void WebPreferences::setAllowUniversalAccessFromFileURLs(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::allowUniversalAccessFromFileURLsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::allowUniversalAccessFromFileURLsKey(), value, false);
}

bool WebPreferences::allowUniversalAccessFromFileURLs() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::allowUniversalAccessFromFileURLsKey());
}

void WebPreferences::deleteAllowUniversalAccessFromFileURLs()
{
    deleteKey(WebPreferencesKey::allowUniversalAccessFromFileURLsKey());
}

void WebPreferences::setAlwaysAllowLocalWebarchive(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::alwaysAllowLocalWebarchiveKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::alwaysAllowLocalWebarchiveKey(), value, true);
}

bool WebPreferences::alwaysAllowLocalWebarchive() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::alwaysAllowLocalWebarchiveKey());
}

void WebPreferences::deleteAlwaysAllowLocalWebarchive()
{
    deleteKey(WebPreferencesKey::alwaysAllowLocalWebarchiveKey());
}

void WebPreferences::setSWVPDecodersAlwaysEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::sWVPDecodersAlwaysEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::sWVPDecodersAlwaysEnabledKey(), value, true);
}

bool WebPreferences::sWVPDecodersAlwaysEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::sWVPDecodersAlwaysEnabledKey());
}

void WebPreferences::deleteSWVPDecodersAlwaysEnabled()
{
    deleteKey(WebPreferencesKey::sWVPDecodersAlwaysEnabledKey());
}

void WebPreferences::setAppBadgeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::appBadgeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::appBadgeEnabledKey(), value, true);
}

bool WebPreferences::appBadgeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::appBadgeEnabledKey());
}

void WebPreferences::deleteAppBadgeEnabled()
{
    deleteKey(WebPreferencesKey::appBadgeEnabledKey());
}

void WebPreferences::setAppHighlightsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::appHighlightsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::appHighlightsEnabledKey(), value, true);
}

bool WebPreferences::appHighlightsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::appHighlightsEnabledKey());
}

void WebPreferences::deleteAppHighlightsEnabled()
{
    deleteKey(WebPreferencesKey::appHighlightsEnabledKey());
}

void WebPreferences::setAsyncFrameScrollingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::asyncFrameScrollingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::asyncFrameScrollingEnabledKey(), value, true);
}

bool WebPreferences::asyncFrameScrollingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::asyncFrameScrollingEnabledKey());
}

void WebPreferences::deleteAsyncFrameScrollingEnabled()
{
    deleteKey(WebPreferencesKey::asyncFrameScrollingEnabledKey());
}

void WebPreferences::setAsyncOverflowScrollingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::asyncOverflowScrollingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::asyncOverflowScrollingEnabledKey(), value, true);
}

bool WebPreferences::asyncOverflowScrollingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::asyncOverflowScrollingEnabledKey());
}

void WebPreferences::deleteAsyncOverflowScrollingEnabled()
{
    deleteKey(WebPreferencesKey::asyncOverflowScrollingEnabledKey());
}

void WebPreferences::setUseAsyncUIKitInteractions(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useAsyncUIKitInteractionsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useAsyncUIKitInteractionsKey(), value, true);
}

bool WebPreferences::useAsyncUIKitInteractions() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useAsyncUIKitInteractionsKey());
}

void WebPreferences::deleteUseAsyncUIKitInteractions()
{
    deleteKey(WebPreferencesKey::useAsyncUIKitInteractionsKey());
}

void WebPreferences::setAsyncClipboardAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::asyncClipboardAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::asyncClipboardAPIEnabledKey(), value, false);
}

bool WebPreferences::asyncClipboardAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::asyncClipboardAPIEnabledKey());
}

void WebPreferences::deleteAsyncClipboardAPIEnabled()
{
    deleteKey(WebPreferencesKey::asyncClipboardAPIEnabledKey());
}

void WebPreferences::setAttachmentElementEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::attachmentElementEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::attachmentElementEnabledKey(), value, false);
}

bool WebPreferences::attachmentElementEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::attachmentElementEnabledKey());
}

void WebPreferences::deleteAttachmentElementEnabled()
{
    deleteKey(WebPreferencesKey::attachmentElementEnabledKey());
}

void WebPreferences::setAttachmentWideLayoutEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::attachmentWideLayoutEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::attachmentWideLayoutEnabledKey(), value, false);
}

bool WebPreferences::attachmentWideLayoutEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::attachmentWideLayoutEnabledKey());
}

void WebPreferences::deleteAttachmentWideLayoutEnabled()
{
    deleteKey(WebPreferencesKey::attachmentWideLayoutEnabledKey());
}

void WebPreferences::setExtendedAudioDescriptionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::extendedAudioDescriptionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::extendedAudioDescriptionsEnabledKey(), value, false);
}

bool WebPreferences::extendedAudioDescriptionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::extendedAudioDescriptionsEnabledKey());
}

void WebPreferences::deleteExtendedAudioDescriptionsEnabled()
{
    deleteKey(WebPreferencesKey::extendedAudioDescriptionsEnabledKey());
}

void WebPreferences::setAudioDescriptionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::audioDescriptionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::audioDescriptionsEnabledKey(), value, false);
}

bool WebPreferences::audioDescriptionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::audioDescriptionsEnabledKey());
}

void WebPreferences::deleteAudioDescriptionsEnabled()
{
    deleteKey(WebPreferencesKey::audioDescriptionsEnabledKey());
}

void WebPreferences::setDOMAudioSessionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::domAudioSessionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::domAudioSessionEnabledKey(), value, false);
}

bool WebPreferences::domAudioSessionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::domAudioSessionEnabledKey());
}

void WebPreferences::deleteDOMAudioSessionEnabled()
{
    deleteKey(WebPreferencesKey::domAudioSessionEnabledKey());
}

void WebPreferences::setDOMAudioSessionFullEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::domAudioSessionFullEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::domAudioSessionFullEnabledKey(), value, true);
}

bool WebPreferences::domAudioSessionFullEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::domAudioSessionFullEnabledKey());
}

void WebPreferences::deleteDOMAudioSessionFullEnabled()
{
    deleteKey(WebPreferencesKey::domAudioSessionFullEnabledKey());
}

void WebPreferences::setAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidthKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidthKey(), value, true);
}

bool WebPreferences::automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidthKey());
}

void WebPreferences::deleteAutomaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidth()
{
    deleteKey(WebPreferencesKey::automaticallyAdjustsViewScaleUsingMinimumEffectiveDeviceWidthKey());
}

void WebPreferences::setBeaconAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::beaconAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::beaconAPIEnabledKey(), value, false);
}

bool WebPreferences::beaconAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::beaconAPIEnabledKey());
}

void WebPreferences::deleteBeaconAPIEnabled()
{
    deleteKey(WebPreferencesKey::beaconAPIEnabledKey());
}

void WebPreferences::setBidiContentAwarePasteEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::bidiContentAwarePasteEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::bidiContentAwarePasteEnabledKey(), value, true);
}

bool WebPreferences::bidiContentAwarePasteEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::bidiContentAwarePasteEnabledKey());
}

void WebPreferences::deleteBidiContentAwarePasteEnabled()
{
    deleteKey(WebPreferencesKey::bidiContentAwarePasteEnabledKey());
}

void WebPreferences::setBlockFontServiceInWebContentSandbox(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blockFontServiceInWebContentSandboxKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blockFontServiceInWebContentSandboxKey(), value, true);
}

bool WebPreferences::blockFontServiceInWebContentSandbox() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blockFontServiceInWebContentSandboxKey());
}

void WebPreferences::deleteBlockFontServiceInWebContentSandbox()
{
    deleteKey(WebPreferencesKey::blockFontServiceInWebContentSandboxKey());
}

void WebPreferences::setBlockIconServicesInWebContentSandbox(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blockIconServicesInWebContentSandboxKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blockIconServicesInWebContentSandboxKey(), value, true);
}

bool WebPreferences::blockIconServicesInWebContentSandbox() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blockIconServicesInWebContentSandboxKey());
}

void WebPreferences::deleteBlockIconServicesInWebContentSandbox()
{
    deleteKey(WebPreferencesKey::blockIconServicesInWebContentSandboxKey());
}

void WebPreferences::setBlockMobileAssetInWebContentSandbox(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blockMobileAssetInWebContentSandboxKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blockMobileAssetInWebContentSandboxKey(), value, true);
}

bool WebPreferences::blockMobileAssetInWebContentSandbox() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blockMobileAssetInWebContentSandboxKey());
}

void WebPreferences::deleteBlockMobileAssetInWebContentSandbox()
{
    deleteKey(WebPreferencesKey::blockMobileAssetInWebContentSandboxKey());
}

void WebPreferences::setBlockMobileGestaltInWebContentSandbox(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blockMobileGestaltInWebContentSandboxKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blockMobileGestaltInWebContentSandboxKey(), value, true);
}

bool WebPreferences::blockMobileGestaltInWebContentSandbox() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blockMobileGestaltInWebContentSandboxKey());
}

void WebPreferences::deleteBlockMobileGestaltInWebContentSandbox()
{
    deleteKey(WebPreferencesKey::blockMobileGestaltInWebContentSandboxKey());
}

void WebPreferences::setBlockOpenDirectoryInWebContentSandbox(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blockOpenDirectoryInWebContentSandboxKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blockOpenDirectoryInWebContentSandboxKey(), value, true);
}

bool WebPreferences::blockOpenDirectoryInWebContentSandbox() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blockOpenDirectoryInWebContentSandboxKey());
}

void WebPreferences::deleteBlockOpenDirectoryInWebContentSandbox()
{
    deleteKey(WebPreferencesKey::blockOpenDirectoryInWebContentSandboxKey());
}

void WebPreferences::setBlockWebInspectorInWebContentSandbox(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blockWebInspectorInWebContentSandboxKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blockWebInspectorInWebContentSandboxKey(), value, true);
}

bool WebPreferences::blockWebInspectorInWebContentSandbox() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blockWebInspectorInWebContentSandboxKey());
}

void WebPreferences::deleteBlockWebInspectorInWebContentSandbox()
{
    deleteKey(WebPreferencesKey::blockWebInspectorInWebContentSandboxKey());
}

void WebPreferences::setBroadcastChannelEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::broadcastChannelEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::broadcastChannelEnabledKey(), value, false);
}

bool WebPreferences::broadcastChannelEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::broadcastChannelEnabledKey());
}

void WebPreferences::deleteBroadcastChannelEnabled()
{
    deleteKey(WebPreferencesKey::broadcastChannelEnabledKey());
}

void WebPreferences::setBuiltInNotificationsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::builtInNotificationsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::builtInNotificationsEnabledKey(), value, true);
}

bool WebPreferences::builtInNotificationsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::builtInNotificationsEnabledKey());
}

void WebPreferences::deleteBuiltInNotificationsEnabled()
{
    deleteKey(WebPreferencesKey::builtInNotificationsEnabledKey());
}

void WebPreferences::setCSS3DTransformBackfaceVisibilityInteroperabilityEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::css3DTransformBackfaceVisibilityInteroperabilityEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::css3DTransformBackfaceVisibilityInteroperabilityEnabledKey(), value, false);
}

bool WebPreferences::css3DTransformBackfaceVisibilityInteroperabilityEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::css3DTransformBackfaceVisibilityInteroperabilityEnabledKey());
}

void WebPreferences::deleteCSS3DTransformBackfaceVisibilityInteroperabilityEnabled()
{
    deleteKey(WebPreferencesKey::css3DTransformBackfaceVisibilityInteroperabilityEnabledKey());
}

void WebPreferences::setCSSCounterStyleAtRuleImageSymbolsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssCounterStyleAtRuleImageSymbolsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssCounterStyleAtRuleImageSymbolsEnabledKey(), value, true);
}

bool WebPreferences::cssCounterStyleAtRuleImageSymbolsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssCounterStyleAtRuleImageSymbolsEnabledKey());
}

void WebPreferences::deleteCSSCounterStyleAtRuleImageSymbolsEnabled()
{
    deleteKey(WebPreferencesKey::cssCounterStyleAtRuleImageSymbolsEnabledKey());
}

void WebPreferences::setAccentColorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::accentColorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::accentColorEnabledKey(), value, false);
}

bool WebPreferences::accentColorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::accentColorEnabledKey());
}

void WebPreferences::deleteAccentColorEnabled()
{
    deleteKey(WebPreferencesKey::accentColorEnabledKey());
}

void WebPreferences::setCSSAnchorPositioningEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssAnchorPositioningEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssAnchorPositioningEnabledKey(), value, false);
}

bool WebPreferences::cssAnchorPositioningEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssAnchorPositioningEnabledKey());
}

void WebPreferences::deleteCSSAnchorPositioningEnabled()
{
    deleteKey(WebPreferencesKey::cssAnchorPositioningEnabledKey());
}

void WebPreferences::setCSSAnchorPositioningPositionVisibilityEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssAnchorPositioningPositionVisibilityEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssAnchorPositioningPositionVisibilityEnabledKey(), value, true);
}

bool WebPreferences::cssAnchorPositioningPositionVisibilityEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssAnchorPositioningPositionVisibilityEnabledKey());
}

void WebPreferences::deleteCSSAnchorPositioningPositionVisibilityEnabled()
{
    deleteKey(WebPreferencesKey::cssAnchorPositioningPositionVisibilityEnabledKey());
}

void WebPreferences::setDevolvableWidgetsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::devolvableWidgetsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::devolvableWidgetsEnabledKey(), value, false);
}

bool WebPreferences::devolvableWidgetsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::devolvableWidgetsEnabledKey());
}

void WebPreferences::deleteDevolvableWidgetsEnabled()
{
    deleteKey(WebPreferencesKey::devolvableWidgetsEnabledKey());
}

void WebPreferences::setCSSInputSecurityEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssInputSecurityEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssInputSecurityEnabledKey(), value, true);
}

bool WebPreferences::cssInputSecurityEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssInputSecurityEnabledKey());
}

void WebPreferences::deleteCSSInputSecurityEnabled()
{
    deleteKey(WebPreferencesKey::cssInputSecurityEnabledKey());
}

void WebPreferences::setMasonryEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::masonryEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::masonryEnabledKey(), value, false);
}

bool WebPreferences::masonryEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::masonryEnabledKey());
}

void WebPreferences::deleteMasonryEnabled()
{
    deleteKey(WebPreferencesKey::masonryEnabledKey());
}

void WebPreferences::setOverscrollBehaviorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::overscrollBehaviorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::overscrollBehaviorEnabledKey(), value, false);
}

bool WebPreferences::overscrollBehaviorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::overscrollBehaviorEnabledKey());
}

void WebPreferences::deleteOverscrollBehaviorEnabled()
{
    deleteKey(WebPreferencesKey::overscrollBehaviorEnabledKey());
}

void WebPreferences::setCSSPaintingAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssPaintingAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssPaintingAPIEnabledKey(), value, true);
}

bool WebPreferences::cssPaintingAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssPaintingAPIEnabledKey());
}

void WebPreferences::deleteCSSPaintingAPIEnabled()
{
    deleteKey(WebPreferencesKey::cssPaintingAPIEnabledKey());
}

void WebPreferences::setCSSRhythmicSizingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssRhythmicSizingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssRhythmicSizingEnabledKey(), value, true);
}

bool WebPreferences::cssRhythmicSizingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssRhythmicSizingEnabledKey());
}

void WebPreferences::deleteCSSRhythmicSizingEnabled()
{
    deleteKey(WebPreferencesKey::cssRhythmicSizingEnabledKey());
}

void WebPreferences::setCSSScrollAnchoringEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssScrollAnchoringEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssScrollAnchoringEnabledKey(), value, true);
}

bool WebPreferences::cssScrollAnchoringEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssScrollAnchoringEnabledKey());
}

void WebPreferences::deleteCSSScrollAnchoringEnabled()
{
    deleteKey(WebPreferencesKey::cssScrollAnchoringEnabledKey());
}

void WebPreferences::setSpringTimingFunctionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::springTimingFunctionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::springTimingFunctionEnabledKey(), value, true);
}

bool WebPreferences::springTimingFunctionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::springTimingFunctionEnabledKey());
}

void WebPreferences::deleteSpringTimingFunctionEnabled()
{
    deleteKey(WebPreferencesKey::springTimingFunctionEnabledKey());
}

void WebPreferences::setCSSTreeCountingFunctionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTreeCountingFunctionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTreeCountingFunctionsEnabledKey(), value, false);
}

bool WebPreferences::cssTreeCountingFunctionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTreeCountingFunctionsEnabledKey());
}

void WebPreferences::deleteCSSTreeCountingFunctionsEnabled()
{
    deleteKey(WebPreferencesKey::cssTreeCountingFunctionsEnabledKey());
}

void WebPreferences::setCSSTypedOMColorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTypedOMColorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTypedOMColorEnabledKey(), value, true);
}

bool WebPreferences::cssTypedOMColorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTypedOMColorEnabledKey());
}

void WebPreferences::deleteCSSTypedOMColorEnabled()
{
    deleteKey(WebPreferencesKey::cssTypedOMColorEnabledKey());
}

void WebPreferences::setCSSURLModifiersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssURLModifiersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssURLModifiersEnabledKey(), value, false);
}

bool WebPreferences::cssURLModifiersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssURLModifiersEnabledKey());
}

void WebPreferences::deleteCSSURLModifiersEnabled()
{
    deleteKey(WebPreferencesKey::cssURLModifiersEnabledKey());
}

void WebPreferences::setCSSURLIntegrityModifierEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssURLIntegrityModifierEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssURLIntegrityModifierEnabledKey(), value, true);
}

bool WebPreferences::cssURLIntegrityModifierEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssURLIntegrityModifierEnabledKey());
}

void WebPreferences::deleteCSSURLIntegrityModifierEnabled()
{
    deleteKey(WebPreferencesKey::cssURLIntegrityModifierEnabledKey());
}

void WebPreferences::setCSSUnprefixedBackdropFilterEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssUnprefixedBackdropFilterEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssUnprefixedBackdropFilterEnabledKey(), value, false);
}

bool WebPreferences::cssUnprefixedBackdropFilterEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssUnprefixedBackdropFilterEnabledKey());
}

void WebPreferences::deleteCSSUnprefixedBackdropFilterEnabled()
{
    deleteKey(WebPreferencesKey::cssUnprefixedBackdropFilterEnabledKey());
}

void WebPreferences::setCSSAppearanceBaseEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssAppearanceBaseEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssAppearanceBaseEnabledKey(), value, true);
}

bool WebPreferences::cssAppearanceBaseEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssAppearanceBaseEnabledKey());
}

void WebPreferences::deleteCSSAppearanceBaseEnabled()
{
    deleteKey(WebPreferencesKey::cssAppearanceBaseEnabledKey());
}

void WebPreferences::setCSSAxisRelativePositionKeywordsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssAxisRelativePositionKeywordsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssAxisRelativePositionKeywordsEnabledKey(), value, false);
}

bool WebPreferences::cssAxisRelativePositionKeywordsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssAxisRelativePositionKeywordsEnabledKey());
}

void WebPreferences::deleteCSSAxisRelativePositionKeywordsEnabled()
{
    deleteKey(WebPreferencesKey::cssAxisRelativePositionKeywordsEnabledKey());
}

void WebPreferences::setCSSBackgroundClipBorderAreaEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssBackgroundClipBorderAreaEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssBackgroundClipBorderAreaEnabledKey(), value, false);
}

bool WebPreferences::cssBackgroundClipBorderAreaEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssBackgroundClipBorderAreaEnabledKey());
}

void WebPreferences::deleteCSSBackgroundClipBorderAreaEnabled()
{
    deleteKey(WebPreferencesKey::cssBackgroundClipBorderAreaEnabledKey());
}

void WebPreferences::setCSSColorLayersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssColorLayersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssColorLayersEnabledKey(), value, false);
}

bool WebPreferences::cssColorLayersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssColorLayersEnabledKey());
}

void WebPreferences::deleteCSSColorLayersEnabled()
{
    deleteKey(WebPreferencesKey::cssColorLayersEnabledKey());
}

void WebPreferences::setCSSContrastColorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssContrastColorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssContrastColorEnabledKey(), value, false);
}

bool WebPreferences::cssContrastColorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssContrastColorEnabledKey());
}

void WebPreferences::deleteCSSContrastColorEnabled()
{
    deleteKey(WebPreferencesKey::cssContrastColorEnabledKey());
}

void WebPreferences::setCSSCornerShapeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssCornerShapeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssCornerShapeEnabledKey(), value, true);
}

bool WebPreferences::cssCornerShapeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssCornerShapeEnabledKey());
}

void WebPreferences::deleteCSSCornerShapeEnabled()
{
    deleteKey(WebPreferencesKey::cssCornerShapeEnabledKey());
}

void WebPreferences::setCSSDPropertyEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssDPropertyEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssDPropertyEnabledKey(), value, false);
}

bool WebPreferences::cssDPropertyEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssDPropertyEnabledKey());
}

void WebPreferences::deleteCSSDPropertyEnabled()
{
    deleteKey(WebPreferencesKey::cssDPropertyEnabledKey());
}

void WebPreferences::setCSSDynamicRangeLimitMixEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssDynamicRangeLimitMixEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssDynamicRangeLimitMixEnabledKey(), value, true);
}

bool WebPreferences::cssDynamicRangeLimitMixEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssDynamicRangeLimitMixEnabledKey());
}

void WebPreferences::deleteCSSDynamicRangeLimitMixEnabled()
{
    deleteKey(WebPreferencesKey::cssDynamicRangeLimitMixEnabledKey());
}

void WebPreferences::setCSSConstrainedDynamicRangeLimitEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssConstrainedDynamicRangeLimitEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssConstrainedDynamicRangeLimitEnabledKey(), value, true);
}

bool WebPreferences::cssConstrainedDynamicRangeLimitEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssConstrainedDynamicRangeLimitEnabledKey());
}

void WebPreferences::deleteCSSConstrainedDynamicRangeLimitEnabled()
{
    deleteKey(WebPreferencesKey::cssConstrainedDynamicRangeLimitEnabledKey());
}

void WebPreferences::setCSSFieldSizingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssFieldSizingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssFieldSizingEnabledKey(), value, false);
}

bool WebPreferences::cssFieldSizingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssFieldSizingEnabledKey());
}

void WebPreferences::deleteCSSFieldSizingEnabled()
{
    deleteKey(WebPreferencesKey::cssFieldSizingEnabledKey());
}

void WebPreferences::setCSSFontVariantEmojiEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssFontVariantEmojiEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssFontVariantEmojiEnabledKey(), value, true);
}

bool WebPreferences::cssFontVariantEmojiEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssFontVariantEmojiEnabledKey());
}

void WebPreferences::deleteCSSFontVariantEmojiEnabled()
{
    deleteKey(WebPreferencesKey::cssFontVariantEmojiEnabledKey());
}

void WebPreferences::setCSSLineClampEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssLineClampEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssLineClampEnabledKey(), value, false);
}

bool WebPreferences::cssLineClampEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssLineClampEnabledKey());
}

void WebPreferences::deleteCSSLineClampEnabled()
{
    deleteKey(WebPreferencesKey::cssLineClampEnabledKey());
}

void WebPreferences::setCSSLineFitEdgeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssLineFitEdgeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssLineFitEdgeEnabledKey(), value, true);
}

bool WebPreferences::cssLineFitEdgeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssLineFitEdgeEnabledKey());
}

void WebPreferences::deleteCSSLineFitEdgeEnabled()
{
    deleteKey(WebPreferencesKey::cssLineFitEdgeEnabledKey());
}

void WebPreferences::setCSSProgressFunctionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssProgressFunctionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssProgressFunctionEnabledKey(), value, false);
}

bool WebPreferences::cssProgressFunctionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssProgressFunctionEnabledKey());
}

void WebPreferences::deleteCSSProgressFunctionEnabled()
{
    deleteKey(WebPreferencesKey::cssProgressFunctionEnabledKey());
}

void WebPreferences::setCSSRandomFunctionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssRandomFunctionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssRandomFunctionEnabledKey(), value, false);
}

bool WebPreferences::cssRandomFunctionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssRandomFunctionEnabledKey());
}

void WebPreferences::deleteCSSRandomFunctionEnabled()
{
    deleteKey(WebPreferencesKey::cssRandomFunctionEnabledKey());
}

void WebPreferences::setCSSRubyAlignEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssRubyAlignEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssRubyAlignEnabledKey(), value, false);
}

bool WebPreferences::cssRubyAlignEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssRubyAlignEnabledKey());
}

void WebPreferences::deleteCSSRubyAlignEnabled()
{
    deleteKey(WebPreferencesKey::cssRubyAlignEnabledKey());
}

void WebPreferences::setCSSRubyOverhangEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssRubyOverhangEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssRubyOverhangEnabledKey(), value, false);
}

bool WebPreferences::cssRubyOverhangEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssRubyOverhangEnabledKey());
}

void WebPreferences::deleteCSSRubyOverhangEnabled()
{
    deleteKey(WebPreferencesKey::cssRubyOverhangEnabledKey());
}

void WebPreferences::setCSSScrollbarColorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssScrollbarColorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssScrollbarColorEnabledKey(), value, true);
}

bool WebPreferences::cssScrollbarColorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssScrollbarColorEnabledKey());
}

void WebPreferences::deleteCSSScrollbarColorEnabled()
{
    deleteKey(WebPreferencesKey::cssScrollbarColorEnabledKey());
}

void WebPreferences::setCSSScrollbarGutterEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssScrollbarGutterEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssScrollbarGutterEnabledKey(), value, false);
}

bool WebPreferences::cssScrollbarGutterEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssScrollbarGutterEnabledKey());
}

void WebPreferences::deleteCSSScrollbarGutterEnabled()
{
    deleteKey(WebPreferencesKey::cssScrollbarGutterEnabledKey());
}

void WebPreferences::setCSSScrollbarWidthEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssScrollbarWidthEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssScrollbarWidthEnabledKey(), value, false);
}

bool WebPreferences::cssScrollbarWidthEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssScrollbarWidthEnabledKey());
}

void WebPreferences::deleteCSSScrollbarWidthEnabled()
{
    deleteKey(WebPreferencesKey::cssScrollbarWidthEnabledKey());
}

void WebPreferences::setCSSShapeFunctionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssShapeFunctionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssShapeFunctionEnabledKey(), value, false);
}

bool WebPreferences::cssShapeFunctionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssShapeFunctionEnabledKey());
}

void WebPreferences::deleteCSSShapeFunctionEnabled()
{
    deleteKey(WebPreferencesKey::cssShapeFunctionEnabledKey());
}

void WebPreferences::setCSSTextAutospaceEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTextAutospaceEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTextAutospaceEnabledKey(), value, false);
}

bool WebPreferences::cssTextAutospaceEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTextAutospaceEnabledKey());
}

void WebPreferences::deleteCSSTextAutospaceEnabled()
{
    deleteKey(WebPreferencesKey::cssTextAutospaceEnabledKey());
}

void WebPreferences::setCSSTextBoxTrimEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTextBoxTrimEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTextBoxTrimEnabledKey(), value, false);
}

bool WebPreferences::cssTextBoxTrimEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTextBoxTrimEnabledKey());
}

void WebPreferences::deleteCSSTextBoxTrimEnabled()
{
    deleteKey(WebPreferencesKey::cssTextBoxTrimEnabledKey());
}

void WebPreferences::setCSSTextGroupAlignEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTextGroupAlignEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTextGroupAlignEnabledKey(), value, true);
}

bool WebPreferences::cssTextGroupAlignEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTextGroupAlignEnabledKey());
}

void WebPreferences::deleteCSSTextGroupAlignEnabled()
{
    deleteKey(WebPreferencesKey::cssTextGroupAlignEnabledKey());
}

void WebPreferences::setCSSTextJustifyEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTextJustifyEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTextJustifyEnabledKey(), value, true);
}

bool WebPreferences::cssTextJustifyEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTextJustifyEnabledKey());
}

void WebPreferences::deleteCSSTextJustifyEnabled()
{
    deleteKey(WebPreferencesKey::cssTextJustifyEnabledKey());
}

void WebPreferences::setCSSTextSpacingTrimEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTextSpacingTrimEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTextSpacingTrimEnabledKey(), value, true);
}

bool WebPreferences::cssTextSpacingTrimEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTextSpacingTrimEnabledKey());
}

void WebPreferences::deleteCSSTextSpacingTrimEnabled()
{
    deleteKey(WebPreferencesKey::cssTextSpacingTrimEnabledKey());
}

void WebPreferences::setCSSTextUnderlinePositionLeftRightEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTextUnderlinePositionLeftRightEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTextUnderlinePositionLeftRightEnabledKey(), value, false);
}

bool WebPreferences::cssTextUnderlinePositionLeftRightEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTextUnderlinePositionLeftRightEnabledKey());
}

void WebPreferences::deleteCSSTextUnderlinePositionLeftRightEnabled()
{
    deleteKey(WebPreferencesKey::cssTextUnderlinePositionLeftRightEnabledKey());
}

void WebPreferences::setCSSTextWrapPrettyEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTextWrapPrettyEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTextWrapPrettyEnabledKey(), value, false);
}

bool WebPreferences::cssTextWrapPrettyEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTextWrapPrettyEnabledKey());
}

void WebPreferences::deleteCSSTextWrapPrettyEnabled()
{
    deleteKey(WebPreferencesKey::cssTextWrapPrettyEnabledKey());
}

void WebPreferences::setCSSTransformStyleSeparatedEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssTransformStyleSeparatedEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssTransformStyleSeparatedEnabledKey(), value, true);
}

bool WebPreferences::cssTransformStyleSeparatedEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssTransformStyleSeparatedEnabledKey());
}

void WebPreferences::deleteCSSTransformStyleSeparatedEnabled()
{
    deleteKey(WebPreferencesKey::cssTransformStyleSeparatedEnabledKey());
}

void WebPreferences::setCacheAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cacheAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cacheAPIEnabledKey(), value, false);
}

bool WebPreferences::cacheAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cacheAPIEnabledKey());
}

void WebPreferences::deleteCacheAPIEnabled()
{
    deleteKey(WebPreferencesKey::cacheAPIEnabledKey());
}

void WebPreferences::setCanvasColorSpaceEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::canvasColorSpaceEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::canvasColorSpaceEnabledKey(), value, false);
}

bool WebPreferences::canvasColorSpaceEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::canvasColorSpaceEnabledKey());
}

void WebPreferences::deleteCanvasColorSpaceEnabled()
{
    deleteKey(WebPreferencesKey::canvasColorSpaceEnabledKey());
}

void WebPreferences::setCanvasFiltersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::canvasFiltersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::canvasFiltersEnabledKey(), value, true);
}

bool WebPreferences::canvasFiltersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::canvasFiltersEnabledKey());
}

void WebPreferences::deleteCanvasFiltersEnabled()
{
    deleteKey(WebPreferencesKey::canvasFiltersEnabledKey());
}

void WebPreferences::setCanvasLayersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::canvasLayersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::canvasLayersEnabledKey(), value, true);
}

bool WebPreferences::canvasLayersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::canvasLayersEnabledKey());
}

void WebPreferences::deleteCanvasLayersEnabled()
{
    deleteKey(WebPreferencesKey::canvasLayersEnabledKey());
}

void WebPreferences::setCanvasUsesAcceleratedDrawing(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::canvasUsesAcceleratedDrawingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::canvasUsesAcceleratedDrawingKey(), value, false);
}

bool WebPreferences::canvasUsesAcceleratedDrawing() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::canvasUsesAcceleratedDrawingKey());
}

void WebPreferences::deleteCanvasUsesAcceleratedDrawing()
{
    deleteKey(WebPreferencesKey::canvasUsesAcceleratedDrawingKey());
}

void WebPreferences::setCanvasPixelFormatEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::canvasPixelFormatEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::canvasPixelFormatEnabledKey(), value, true);
}

bool WebPreferences::canvasPixelFormatEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::canvasPixelFormatEnabledKey());
}

void WebPreferences::deleteCanvasPixelFormatEnabled()
{
    deleteKey(WebPreferencesKey::canvasPixelFormatEnabledKey());
}

void WebPreferences::setChildProcessDebuggabilityEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::childProcessDebuggabilityEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::childProcessDebuggabilityEnabledKey(), value, true);
}

bool WebPreferences::childProcessDebuggabilityEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::childProcessDebuggabilityEnabledKey());
}

void WebPreferences::deleteChildProcessDebuggabilityEnabled()
{
    deleteKey(WebPreferencesKey::childProcessDebuggabilityEnabledKey());
}

void WebPreferences::setClearSiteDataHTTPHeaderEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::clearSiteDataHTTPHeaderEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::clearSiteDataHTTPHeaderEnabledKey(), value, false);
}

bool WebPreferences::clearSiteDataHTTPHeaderEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::clearSiteDataHTTPHeaderEnabledKey());
}

void WebPreferences::deleteClearSiteDataHTTPHeaderEnabled()
{
    deleteKey(WebPreferencesKey::clearSiteDataHTTPHeaderEnabledKey());
}

void WebPreferences::setClearSiteDataExecutionContextsSupportEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::clearSiteDataExecutionContextsSupportEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::clearSiteDataExecutionContextsSupportEnabledKey(), value, true);
}

bool WebPreferences::clearSiteDataExecutionContextsSupportEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::clearSiteDataExecutionContextsSupportEnabledKey());
}

void WebPreferences::deleteClearSiteDataExecutionContextsSupportEnabled()
{
    deleteKey(WebPreferencesKey::clearSiteDataExecutionContextsSupportEnabledKey());
}

void WebPreferences::setCloseWatcherEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::closeWatcherEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::closeWatcherEnabledKey(), value, true);
}

bool WebPreferences::closeWatcherEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::closeWatcherEnabledKey());
}

void WebPreferences::deleteCloseWatcherEnabled()
{
    deleteKey(WebPreferencesKey::closeWatcherEnabledKey());
}

void WebPreferences::setInputTypeColorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inputTypeColorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inputTypeColorEnabledKey(), value, false);
}

bool WebPreferences::inputTypeColorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inputTypeColorEnabledKey());
}

void WebPreferences::deleteInputTypeColorEnabled()
{
    deleteKey(WebPreferencesKey::inputTypeColorEnabledKey());
}

void WebPreferences::setCompositingBordersVisible(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::compositingBordersVisibleKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::compositingBordersVisibleKey(), value, true);
}

bool WebPreferences::compositingBordersVisible() const
{
    if (m_compositingBordersVisibleInspectorOverride)
        return m_compositingBordersVisibleInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::compositingBordersVisibleKey());
}

void WebPreferences::deleteCompositingBordersVisible()
{
    deleteKey(WebPreferencesKey::compositingBordersVisibleKey());
}

void WebPreferences::setCompositingRepaintCountersVisible(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::compositingRepaintCountersVisibleKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::compositingRepaintCountersVisibleKey(), value, true);
}

bool WebPreferences::compositingRepaintCountersVisible() const
{
    if (m_compositingRepaintCountersVisibleInspectorOverride)
        return m_compositingRepaintCountersVisibleInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::compositingRepaintCountersVisibleKey());
}

void WebPreferences::deleteCompositingRepaintCountersVisible()
{
    deleteKey(WebPreferencesKey::compositingRepaintCountersVisibleKey());
}

void WebPreferences::setCompressionStreamEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::compressionStreamEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::compressionStreamEnabledKey(), value, false);
}

bool WebPreferences::compressionStreamEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::compressionStreamEnabledKey());
}

void WebPreferences::deleteCompressionStreamEnabled()
{
    deleteKey(WebPreferencesKey::compressionStreamEnabledKey());
}

void WebPreferences::setContactPickerAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::contactPickerAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::contactPickerAPIEnabledKey(), value, true);
}

bool WebPreferences::contactPickerAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::contactPickerAPIEnabledKey());
}

void WebPreferences::deleteContactPickerAPIEnabled()
{
    deleteKey(WebPreferencesKey::contactPickerAPIEnabledKey());
}

void WebPreferences::setContentInsetBackgroundFillEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::contentInsetBackgroundFillEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::contentInsetBackgroundFillEnabledKey(), value, true);
}

bool WebPreferences::contentInsetBackgroundFillEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::contentInsetBackgroundFillEnabledKey());
}

void WebPreferences::deleteContentInsetBackgroundFillEnabled()
{
    deleteKey(WebPreferencesKey::contentInsetBackgroundFillEnabledKey());
}

void WebPreferences::setCookieConsentAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cookieConsentAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cookieConsentAPIEnabledKey(), value, true);
}

bool WebPreferences::cookieConsentAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cookieConsentAPIEnabledKey());
}

void WebPreferences::deleteCookieConsentAPIEnabled()
{
    deleteKey(WebPreferencesKey::cookieConsentAPIEnabledKey());
}

void WebPreferences::setCookieStoreManagerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cookieStoreManagerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cookieStoreManagerEnabledKey(), value, true);
}

bool WebPreferences::cookieStoreManagerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cookieStoreManagerEnabledKey());
}

void WebPreferences::deleteCookieStoreManagerEnabled()
{
    deleteKey(WebPreferencesKey::cookieStoreManagerEnabledKey());
}

void WebPreferences::setCookieStoreAPIExtendedAttributesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cookieStoreAPIExtendedAttributesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cookieStoreAPIExtendedAttributesEnabledKey(), value, true);
}

bool WebPreferences::cookieStoreAPIExtendedAttributesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cookieStoreAPIExtendedAttributesEnabledKey());
}

void WebPreferences::deleteCookieStoreAPIExtendedAttributesEnabled()
{
    deleteKey(WebPreferencesKey::cookieStoreAPIExtendedAttributesEnabledKey());
}

void WebPreferences::setCookieStoreAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cookieStoreAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cookieStoreAPIEnabledKey(), value, false);
}

bool WebPreferences::cookieStoreAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cookieStoreAPIEnabledKey());
}

void WebPreferences::deleteCookieStoreAPIEnabled()
{
    deleteKey(WebPreferencesKey::cookieStoreAPIEnabledKey());
}

void WebPreferences::setCookieEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cookieEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cookieEnabledKey(), value, false);
}

bool WebPreferences::cookieEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cookieEnabledKey());
}

void WebPreferences::deleteCookieEnabled()
{
    deleteKey(WebPreferencesKey::cookieEnabledKey());
}

void WebPreferences::setInputMethodUsesCorrectKeyEventOrder(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inputMethodUsesCorrectKeyEventOrderKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inputMethodUsesCorrectKeyEventOrderKey(), value, true);
}

bool WebPreferences::inputMethodUsesCorrectKeyEventOrder() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inputMethodUsesCorrectKeyEventOrderKey());
}

void WebPreferences::deleteInputMethodUsesCorrectKeyEventOrder()
{
    deleteKey(WebPreferencesKey::inputMethodUsesCorrectKeyEventOrderKey());
}

void WebPreferences::setCrossDocumentViewTransitionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::crossDocumentViewTransitionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::crossDocumentViewTransitionsEnabledKey(), value, false);
}

bool WebPreferences::crossDocumentViewTransitionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::crossDocumentViewTransitionsEnabledKey());
}

void WebPreferences::deleteCrossDocumentViewTransitionsEnabled()
{
    deleteKey(WebPreferencesKey::crossDocumentViewTransitionsEnabledKey());
}

void WebPreferences::setCrossOriginEmbedderPolicyEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::crossOriginEmbedderPolicyEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::crossOriginEmbedderPolicyEnabledKey(), value, false);
}

bool WebPreferences::crossOriginEmbedderPolicyEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::crossOriginEmbedderPolicyEnabledKey());
}

void WebPreferences::deleteCrossOriginEmbedderPolicyEnabled()
{
    deleteKey(WebPreferencesKey::crossOriginEmbedderPolicyEnabledKey());
}

void WebPreferences::setCrossOriginOpenerPolicyEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::crossOriginOpenerPolicyEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::crossOriginOpenerPolicyEnabledKey(), value, false);
}

bool WebPreferences::crossOriginOpenerPolicyEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::crossOriginOpenerPolicyEnabledKey());
}

void WebPreferences::deleteCrossOriginOpenerPolicyEnabled()
{
    deleteKey(WebPreferencesKey::crossOriginOpenerPolicyEnabledKey());
}

void WebPreferences::setCustomPasteboardDataEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::customPasteboardDataEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::customPasteboardDataEnabledKey(), value, false);
}

bool WebPreferences::customPasteboardDataEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::customPasteboardDataEnabledKey());
}

void WebPreferences::deleteCustomPasteboardDataEnabled()
{
    deleteKey(WebPreferencesKey::customPasteboardDataEnabledKey());
}

void WebPreferences::setDOMPasteAccessRequestsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::domPasteAccessRequestsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::domPasteAccessRequestsEnabledKey(), value, true);
}

bool WebPreferences::domPasteAccessRequestsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::domPasteAccessRequestsEnabledKey());
}

void WebPreferences::deleteDOMPasteAccessRequestsEnabled()
{
    deleteKey(WebPreferencesKey::domPasteAccessRequestsEnabledKey());
}

void WebPreferences::setMutationEventsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mutationEventsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mutationEventsEnabledKey(), value, true);
}

bool WebPreferences::mutationEventsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mutationEventsEnabledKey());
}

void WebPreferences::deleteMutationEventsEnabled()
{
    deleteKey(WebPreferencesKey::mutationEventsEnabledKey());
}

void WebPreferences::setDOMTimersThrottlingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::domTimersThrottlingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::domTimersThrottlingEnabledKey(), value, false);
}

bool WebPreferences::domTimersThrottlingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::domTimersThrottlingEnabledKey());
}

void WebPreferences::deleteDOMTimersThrottlingEnabled()
{
    deleteKey(WebPreferencesKey::domTimersThrottlingEnabledKey());
}

void WebPreferences::setZoomOnDoubleTapWhenRoot(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::zoomOnDoubleTapWhenRootKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::zoomOnDoubleTapWhenRootKey(), value, true);
}

bool WebPreferences::zoomOnDoubleTapWhenRoot() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::zoomOnDoubleTapWhenRootKey());
}

void WebPreferences::deleteZoomOnDoubleTapWhenRoot()
{
    deleteKey(WebPreferencesKey::zoomOnDoubleTapWhenRootKey());
}

void WebPreferences::setAlwaysZoomOnDoubleTap(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::alwaysZoomOnDoubleTapKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::alwaysZoomOnDoubleTapKey(), value, true);
}

bool WebPreferences::alwaysZoomOnDoubleTap() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::alwaysZoomOnDoubleTapKey());
}

void WebPreferences::deleteAlwaysZoomOnDoubleTap()
{
    deleteKey(WebPreferencesKey::alwaysZoomOnDoubleTapKey());
}

void WebPreferences::setDataTransferItemsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::dataTransferItemsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::dataTransferItemsEnabledKey(), value, false);
}

bool WebPreferences::dataTransferItemsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::dataTransferItemsEnabledKey());
}

void WebPreferences::deleteDataTransferItemsEnabled()
{
    deleteKey(WebPreferencesKey::dataTransferItemsEnabledKey());
}

void WebPreferences::setDataListElementEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::dataListElementEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::dataListElementEnabledKey(), value, false);
}

bool WebPreferences::dataListElementEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::dataListElementEnabledKey());
}

void WebPreferences::deleteDataListElementEnabled()
{
    deleteKey(WebPreferencesKey::dataListElementEnabledKey());
}

void WebPreferences::setInputTypeDateEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inputTypeDateEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inputTypeDateEnabledKey(), value, false);
}

bool WebPreferences::inputTypeDateEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inputTypeDateEnabledKey());
}

void WebPreferences::deleteInputTypeDateEnabled()
{
    deleteKey(WebPreferencesKey::inputTypeDateEnabledKey());
}

void WebPreferences::setDateTimeInputsEditableComponentsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::dateTimeInputsEditableComponentsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::dateTimeInputsEditableComponentsEnabledKey(), value, false);
}

bool WebPreferences::dateTimeInputsEditableComponentsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::dateTimeInputsEditableComponentsEnabledKey());
}

void WebPreferences::deleteDateTimeInputsEditableComponentsEnabled()
{
    deleteKey(WebPreferencesKey::dateTimeInputsEditableComponentsEnabledKey());
}

void WebPreferences::setDeclarativeWebPush(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::declarativeWebPushKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::declarativeWebPushKey(), value, false);
}

bool WebPreferences::declarativeWebPush() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::declarativeWebPushKey());
}

void WebPreferences::deleteDeclarativeWebPush()
{
    deleteKey(WebPreferencesKey::declarativeWebPushKey());
}

void WebPreferences::setShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaintKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaintKey(), value, false);
}

bool WebPreferences::shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaintKey());
}

void WebPreferences::deleteShouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaint()
{
    deleteKey(WebPreferencesKey::shouldDeferAsynchronousScriptsUntilAfterDocumentLoadOrFirstPaintKey());
}

void WebPreferences::setDeprecationReportingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::deprecationReportingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::deprecationReportingEnabledKey(), value, true);
}

bool WebPreferences::deprecationReportingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::deprecationReportingEnabledKey());
}

void WebPreferences::deleteDeprecationReportingEnabled()
{
    deleteKey(WebPreferencesKey::deprecationReportingEnabledKey());
}

void WebPreferences::setDetachableMediaSourceEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::detachableMediaSourceEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::detachableMediaSourceEnabledKey(), value, false);
}

bool WebPreferences::detachableMediaSourceEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::detachableMediaSourceEnabledKey());
}

void WebPreferences::deleteDetachableMediaSourceEnabled()
{
    deleteKey(WebPreferencesKey::detachableMediaSourceEnabledKey());
}

void WebPreferences::setUAVisualTransitionDetectionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::uAVisualTransitionDetectionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::uAVisualTransitionDetectionEnabledKey(), value, false);
}

bool WebPreferences::uAVisualTransitionDetectionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::uAVisualTransitionDetectionEnabledKey());
}

void WebPreferences::deleteUAVisualTransitionDetectionEnabled()
{
    deleteKey(WebPreferencesKey::uAVisualTransitionDetectionEnabledKey());
}

void WebPreferences::setDiagnosticLoggingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::diagnosticLoggingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::diagnosticLoggingEnabledKey(), value, false);
}

bool WebPreferences::diagnosticLoggingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::diagnosticLoggingEnabledKey());
}

void WebPreferences::deleteDiagnosticLoggingEnabled()
{
    deleteKey(WebPreferencesKey::diagnosticLoggingEnabledKey());
}

void WebPreferences::setDigitalCredentialsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::digitalCredentialsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::digitalCredentialsEnabledKey(), value, false);
}

bool WebPreferences::digitalCredentialsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::digitalCredentialsEnabledKey());
}

void WebPreferences::deleteDigitalCredentialsEnabled()
{
    deleteKey(WebPreferencesKey::digitalCredentialsEnabledKey());
}

void WebPreferences::setDirectoryUploadEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::directoryUploadEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::directoryUploadEnabledKey(), value, false);
}

bool WebPreferences::directoryUploadEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::directoryUploadEnabledKey());
}

void WebPreferences::deleteDirectoryUploadEnabled()
{
    deleteKey(WebPreferencesKey::directoryUploadEnabledKey());
}

void WebPreferences::setIsThirdPartyCookieBlockingDisabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isThirdPartyCookieBlockingDisabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isThirdPartyCookieBlockingDisabledKey(), value, false);
}

bool WebPreferences::isThirdPartyCookieBlockingDisabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isThirdPartyCookieBlockingDisabledKey());
}

void WebPreferences::deleteIsThirdPartyCookieBlockingDisabled()
{
    deleteKey(WebPreferencesKey::isThirdPartyCookieBlockingDisabledKey());
}

void WebPreferences::setIsFirstPartyWebsiteDataRemovalDisabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalDisabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalDisabledKey(), value, false);
}

bool WebPreferences::isFirstPartyWebsiteDataRemovalDisabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalDisabledKey());
}

void WebPreferences::deleteIsFirstPartyWebsiteDataRemovalDisabled()
{
    deleteKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalDisabledKey());
}

void WebPreferences::setDisableScreenSizeOverride(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::disableScreenSizeOverrideKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::disableScreenSizeOverrideKey(), value, true);
}

bool WebPreferences::disableScreenSizeOverride() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::disableScreenSizeOverrideKey());
}

void WebPreferences::deleteDisableScreenSizeOverride()
{
    deleteKey(WebPreferencesKey::disableScreenSizeOverrideKey());
}

void WebPreferences::setShouldDropNearSuspendedAssertionAfterDelay(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldDropNearSuspendedAssertionAfterDelayKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldDropNearSuspendedAssertionAfterDelayKey(), value, true);
}

bool WebPreferences::shouldDropNearSuspendedAssertionAfterDelay() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldDropNearSuspendedAssertionAfterDelayKey());
}

void WebPreferences::deleteShouldDropNearSuspendedAssertionAfterDelay()
{
    deleteKey(WebPreferencesKey::shouldDropNearSuspendedAssertionAfterDelayKey());
}

void WebPreferences::setUseCGDisplayListsForDOMRendering(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useCGDisplayListsForDOMRenderingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useCGDisplayListsForDOMRenderingKey(), value, true);
}

bool WebPreferences::useCGDisplayListsForDOMRendering() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useCGDisplayListsForDOMRenderingKey());
}

void WebPreferences::deleteUseCGDisplayListsForDOMRendering()
{
    deleteKey(WebPreferencesKey::useCGDisplayListsForDOMRenderingKey());
}

void WebPreferences::setReplayCGDisplayListsIntoBackingStore(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::replayCGDisplayListsIntoBackingStoreKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::replayCGDisplayListsIntoBackingStoreKey(), value, true);
}

bool WebPreferences::replayCGDisplayListsIntoBackingStore() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::replayCGDisplayListsIntoBackingStoreKey());
}

void WebPreferences::deleteReplayCGDisplayListsIntoBackingStore()
{
    deleteKey(WebPreferencesKey::replayCGDisplayListsIntoBackingStoreKey());
}

void WebPreferences::setDynamicSiteInterventionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::dynamicSiteInterventionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::dynamicSiteInterventionsEnabledKey(), value, true);
}

bool WebPreferences::dynamicSiteInterventionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::dynamicSiteInterventionsEnabledKey());
}

void WebPreferences::deleteDynamicSiteInterventionsEnabled()
{
    deleteKey(WebPreferencesKey::dynamicSiteInterventionsEnabledKey());
}

void WebPreferences::setEmbedElementEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::embedElementEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::embedElementEnabledKey(), value, false);
}

bool WebPreferences::embedElementEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::embedElementEnabledKey());
}

void WebPreferences::deleteEmbedElementEnabled()
{
    deleteKey(WebPreferencesKey::embedElementEnabledKey());
}

void WebPreferences::setEnableAccessibilityOnDemand(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::enableAccessibilityOnDemandKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::enableAccessibilityOnDemandKey(), value, true);
}

bool WebPreferences::enableAccessibilityOnDemand() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::enableAccessibilityOnDemandKey());
}

void WebPreferences::deleteEnableAccessibilityOnDemand()
{
    deleteKey(WebPreferencesKey::enableAccessibilityOnDemandKey());
}

void WebPreferences::setAutomaticLiveResizeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::automaticLiveResizeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::automaticLiveResizeEnabledKey(), value, true);
}

bool WebPreferences::automaticLiveResizeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::automaticLiveResizeEnabledKey());
}

void WebPreferences::deleteAutomaticLiveResizeEnabled()
{
    deleteKey(WebPreferencesKey::automaticLiveResizeEnabledKey());
}

void WebPreferences::setCanvasFingerprintingQuirkEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::canvasFingerprintingQuirkEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::canvasFingerprintingQuirkEnabledKey(), value, false);
}

bool WebPreferences::canvasFingerprintingQuirkEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::canvasFingerprintingQuirkEnabledKey());
}

void WebPreferences::deleteCanvasFingerprintingQuirkEnabled()
{
    deleteKey(WebPreferencesKey::canvasFingerprintingQuirkEnabledKey());
}

void WebPreferences::setEnableElementCurrentCSSZoom(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::enableElementCurrentCSSZoomKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::enableElementCurrentCSSZoomKey(), value, false);
}

bool WebPreferences::enableElementCurrentCSSZoom() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::enableElementCurrentCSSZoomKey());
}

void WebPreferences::deleteEnableElementCurrentCSSZoom()
{
    deleteKey(WebPreferencesKey::enableElementCurrentCSSZoomKey());
}

void WebPreferences::setEnumeratingAllNetworkInterfacesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::enumeratingAllNetworkInterfacesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::enumeratingAllNetworkInterfacesEnabledKey(), value, true);
}

bool WebPreferences::enumeratingAllNetworkInterfacesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::enumeratingAllNetworkInterfacesEnabledKey());
}

void WebPreferences::deleteEnumeratingAllNetworkInterfacesEnabled()
{
    deleteKey(WebPreferencesKey::enumeratingAllNetworkInterfacesEnabledKey());
}

void WebPreferences::setEnumeratingVisibleNetworkInterfacesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::enumeratingVisibleNetworkInterfacesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::enumeratingVisibleNetworkInterfacesEnabledKey(), value, true);
}

bool WebPreferences::enumeratingVisibleNetworkInterfacesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::enumeratingVisibleNetworkInterfacesEnabledKey());
}

void WebPreferences::deleteEnumeratingVisibleNetworkInterfacesEnabled()
{
    deleteKey(WebPreferencesKey::enumeratingVisibleNetworkInterfacesEnabledKey());
}

void WebPreferences::setICECandidateFilteringEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::iceCandidateFilteringEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::iceCandidateFilteringEnabledKey(), value, true);
}

bool WebPreferences::iceCandidateFilteringEnabled() const
{
    if (m_iceCandidateFilteringEnabledInspectorOverride)
        return m_iceCandidateFilteringEnabledInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::iceCandidateFilteringEnabledKey());
}

void WebPreferences::deleteICECandidateFilteringEnabled()
{
    deleteKey(WebPreferencesKey::iceCandidateFilteringEnabledKey());
}

void WebPreferences::setLegacyEncryptedMediaAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::legacyEncryptedMediaAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::legacyEncryptedMediaAPIEnabledKey(), value, false);
}

bool WebPreferences::legacyEncryptedMediaAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::legacyEncryptedMediaAPIEnabledKey());
}

void WebPreferences::deleteLegacyEncryptedMediaAPIEnabled()
{
    deleteKey(WebPreferencesKey::legacyEncryptedMediaAPIEnabledKey());
}

void WebPreferences::setMockCaptureDevicesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mockCaptureDevicesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mockCaptureDevicesEnabledKey(), value, true);
}

bool WebPreferences::mockCaptureDevicesEnabled() const
{
    if (m_mockCaptureDevicesEnabledInspectorOverride)
        return m_mockCaptureDevicesEnabledInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::mockCaptureDevicesEnabledKey());
}

void WebPreferences::deleteMockCaptureDevicesEnabled()
{
    deleteKey(WebPreferencesKey::mockCaptureDevicesEnabledKey());
}

void WebPreferences::setModelProcessEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::modelProcessEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::modelProcessEnabledKey(), value, false);
}

bool WebPreferences::modelProcessEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::modelProcessEnabledKey());
}

void WebPreferences::deleteModelProcessEnabled()
{
    deleteKey(WebPreferencesKey::modelProcessEnabledKey());
}

void WebPreferences::setPDFJSViewerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pdfJSViewerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pdfJSViewerEnabledKey(), value, true);
}

bool WebPreferences::pdfJSViewerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pdfJSViewerEnabledKey());
}

void WebPreferences::deletePDFJSViewerEnabled()
{
    deleteKey(WebPreferencesKey::pdfJSViewerEnabledKey());
}

void WebPreferences::setAuxclickEventEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::auxclickEventEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::auxclickEventEnabledKey(), value, false);
}

bool WebPreferences::auxclickEventEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::auxclickEventEnabledKey());
}

void WebPreferences::deleteAuxclickEventEnabled()
{
    deleteKey(WebPreferencesKey::auxclickEventEnabledKey());
}

void WebPreferences::setBackgroundWebContentRunningBoardThrottlingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::backgroundWebContentRunningBoardThrottlingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::backgroundWebContentRunningBoardThrottlingEnabledKey(), value, true);
}

bool WebPreferences::backgroundWebContentRunningBoardThrottlingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::backgroundWebContentRunningBoardThrottlingEnabledKey());
}

void WebPreferences::deleteBackgroundWebContentRunningBoardThrottlingEnabled()
{
    deleteKey(WebPreferencesKey::backgroundWebContentRunningBoardThrottlingEnabledKey());
}

void WebPreferences::setBackgroundFetchAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::backgroundFetchAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::backgroundFetchAPIEnabledKey(), value, true);
}

bool WebPreferences::backgroundFetchAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::backgroundFetchAPIEnabledKey());
}

void WebPreferences::deleteBackgroundFetchAPIEnabled()
{
    deleteKey(WebPreferencesKey::backgroundFetchAPIEnabledKey());
}

void WebPreferences::setEnableDebuggingFeaturesInSandbox(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::enableDebuggingFeaturesInSandboxKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::enableDebuggingFeaturesInSandboxKey(), value, true);
}

bool WebPreferences::enableDebuggingFeaturesInSandbox() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::enableDebuggingFeaturesInSandboxKey());
}

void WebPreferences::deleteEnableDebuggingFeaturesInSandbox()
{
    deleteKey(WebPreferencesKey::enableDebuggingFeaturesInSandboxKey());
}

void WebPreferences::setCFNetworkNetworkLoaderEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cFNetworkNetworkLoaderEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cFNetworkNetworkLoaderEnabledKey(), value, true);
}

bool WebPreferences::cFNetworkNetworkLoaderEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cFNetworkNetworkLoaderEnabledKey());
}

void WebPreferences::deleteCFNetworkNetworkLoaderEnabled()
{
    deleteKey(WebPreferencesKey::cFNetworkNetworkLoaderEnabledKey());
}

void WebPreferences::setExperimentalSandboxEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::experimentalSandboxEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::experimentalSandboxEnabledKey(), value, true);
}

bool WebPreferences::experimentalSandboxEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::experimentalSandboxEnabledKey());
}

void WebPreferences::deleteExperimentalSandboxEnabled()
{
    deleteKey(WebPreferencesKey::experimentalSandboxEnabledKey());
}

void WebPreferences::setNavigatorUserAgentDataJavaScriptAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::navigatorUserAgentDataJavaScriptAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::navigatorUserAgentDataJavaScriptAPIEnabledKey(), value, true);
}

bool WebPreferences::navigatorUserAgentDataJavaScriptAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::navigatorUserAgentDataJavaScriptAPIEnabledKey());
}

void WebPreferences::deleteNavigatorUserAgentDataJavaScriptAPIEnabled()
{
    deleteKey(WebPreferencesKey::navigatorUserAgentDataJavaScriptAPIEnabledKey());
}

void WebPreferences::setBlobFileAccessEnforcementEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blobFileAccessEnforcementEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blobFileAccessEnforcementEnabledKey(), value, false);
}

bool WebPreferences::blobFileAccessEnforcementEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blobFileAccessEnforcementEnabledKey());
}

void WebPreferences::deleteBlobFileAccessEnforcementEnabled()
{
    deleteKey(WebPreferencesKey::blobFileAccessEnforcementEnabledKey());
}

void WebPreferences::setEnterKeyHintEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::enterKeyHintEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::enterKeyHintEnabledKey(), value, true);
}

bool WebPreferences::enterKeyHintEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::enterKeyHintEnabledKey());
}

void WebPreferences::deleteEnterKeyHintEnabled()
{
    deleteKey(WebPreferencesKey::enterKeyHintEnabledKey());
}

void WebPreferences::setEventTimingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::eventTimingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::eventTimingEnabledKey(), value, true);
}

bool WebPreferences::eventTimingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::eventTimingEnabledKey());
}

void WebPreferences::deleteEventTimingEnabled()
{
    deleteKey(WebPreferencesKey::eventTimingEnabledKey());
}

void WebPreferences::setEventHandlerDrivenSmoothKeyboardScrollingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::eventHandlerDrivenSmoothKeyboardScrollingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::eventHandlerDrivenSmoothKeyboardScrollingEnabledKey(), value, true);
}

bool WebPreferences::eventHandlerDrivenSmoothKeyboardScrollingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::eventHandlerDrivenSmoothKeyboardScrollingEnabledKey());
}

void WebPreferences::deleteEventHandlerDrivenSmoothKeyboardScrollingEnabled()
{
    deleteKey(WebPreferencesKey::eventHandlerDrivenSmoothKeyboardScrollingEnabledKey());
}

void WebPreferences::setMediaSessionCoordinatorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaSessionCoordinatorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaSessionCoordinatorEnabledKey(), value, false);
}

bool WebPreferences::mediaSessionCoordinatorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaSessionCoordinatorEnabledKey());
}

void WebPreferences::deleteMediaSessionCoordinatorEnabled()
{
    deleteKey(WebPreferencesKey::mediaSessionCoordinatorEnabledKey());
}

void WebPreferences::setMediaSessionPlaylistEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaSessionPlaylistEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaSessionPlaylistEnabledKey(), value, false);
}

bool WebPreferences::mediaSessionPlaylistEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaSessionPlaylistEnabledKey());
}

void WebPreferences::deleteMediaSessionPlaylistEnabled()
{
    deleteKey(WebPreferencesKey::mediaSessionPlaylistEnabledKey());
}

void WebPreferences::setExposeCaptureDevicesAfterCaptureEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::exposeCaptureDevicesAfterCaptureEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::exposeCaptureDevicesAfterCaptureEnabledKey(), value, true);
}

bool WebPreferences::exposeCaptureDevicesAfterCaptureEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::exposeCaptureDevicesAfterCaptureEnabledKey());
}

void WebPreferences::deleteExposeCaptureDevicesAfterCaptureEnabled()
{
    deleteKey(WebPreferencesKey::exposeCaptureDevicesAfterCaptureEnabledKey());
}

void WebPreferences::setExposeDefaultSpeakerAsSpecificDeviceEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::exposeDefaultSpeakerAsSpecificDeviceEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::exposeDefaultSpeakerAsSpecificDeviceEnabledKey(), value, true);
}

bool WebPreferences::exposeDefaultSpeakerAsSpecificDeviceEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::exposeDefaultSpeakerAsSpecificDeviceEnabledKey());
}

void WebPreferences::deleteExposeDefaultSpeakerAsSpecificDeviceEnabled()
{
    deleteKey(WebPreferencesKey::exposeDefaultSpeakerAsSpecificDeviceEnabledKey());
}

void WebPreferences::setFTPEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::ftpEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::ftpEnabledKey(), value, false);
}

bool WebPreferences::ftpEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::ftpEnabledKey());
}

void WebPreferences::deleteFTPEnabled()
{
    deleteKey(WebPreferencesKey::ftpEnabledKey());
}

void WebPreferences::setPreferFasterClickOverDoubleTap(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::preferFasterClickOverDoubleTapKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::preferFasterClickOverDoubleTapKey(), value, true);
}

bool WebPreferences::preferFasterClickOverDoubleTap() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::preferFasterClickOverDoubleTapKey());
}

void WebPreferences::deletePreferFasterClickOverDoubleTap()
{
    deleteKey(WebPreferencesKey::preferFasterClickOverDoubleTapKey());
}

void WebPreferences::setFasterClicksEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fasterClicksEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fasterClicksEnabledKey(), value, true);
}

bool WebPreferences::fasterClicksEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fasterClicksEnabledKey());
}

void WebPreferences::deleteFasterClicksEnabled()
{
    deleteKey(WebPreferencesKey::fasterClicksEnabledKey());
}

void WebPreferences::setFileSystemEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fileSystemEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fileSystemEnabledKey(), value, false);
}

bool WebPreferences::fileSystemEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fileSystemEnabledKey());
}

void WebPreferences::deleteFileSystemEnabled()
{
    deleteKey(WebPreferencesKey::fileSystemEnabledKey());
}

void WebPreferences::setFileSystemWritableStreamEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fileSystemWritableStreamEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fileSystemWritableStreamEnabledKey(), value, false);
}

bool WebPreferences::fileSystemWritableStreamEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fileSystemWritableStreamEnabledKey());
}

void WebPreferences::deleteFileSystemWritableStreamEnabled()
{
    deleteKey(WebPreferencesKey::fileSystemWritableStreamEnabledKey());
}

void WebPreferences::setFileReaderAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fileReaderAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fileReaderAPIEnabledKey(), value, false);
}

bool WebPreferences::fileReaderAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fileReaderAPIEnabledKey());
}

void WebPreferences::deleteFileReaderAPIEnabled()
{
    deleteKey(WebPreferencesKey::fileReaderAPIEnabledKey());
}

void WebPreferences::setFilterLinkDecorationByDefaultEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::filterLinkDecorationByDefaultEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::filterLinkDecorationByDefaultEnabledKey(), value, false);
}

bool WebPreferences::filterLinkDecorationByDefaultEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::filterLinkDecorationByDefaultEnabledKey());
}

void WebPreferences::deleteFilterLinkDecorationByDefaultEnabled()
{
    deleteKey(WebPreferencesKey::filterLinkDecorationByDefaultEnabledKey());
}

void WebPreferences::setForceLockdownFontParserEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::forceLockdownFontParserEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::forceLockdownFontParserEnabledKey(), value, true);
}

bool WebPreferences::forceLockdownFontParserEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::forceLockdownFontParserEnabledKey());
}

void WebPreferences::deleteForceLockdownFontParserEnabled()
{
    deleteKey(WebPreferencesKey::forceLockdownFontParserEnabledKey());
}

void WebPreferences::setForceAlwaysUserScalable(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::forceAlwaysUserScalableKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::forceAlwaysUserScalableKey(), value, true);
}

bool WebPreferences::forceAlwaysUserScalable() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::forceAlwaysUserScalableKey());
}

void WebPreferences::deleteForceAlwaysUserScalable()
{
    deleteKey(WebPreferencesKey::forceAlwaysUserScalableKey());
}

void WebPreferences::setFormControlRefreshEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::formControlRefreshEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::formControlRefreshEnabledKey(), value, true);
}

bool WebPreferences::formControlRefreshEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::formControlRefreshEnabledKey());
}

void WebPreferences::deleteFormControlRefreshEnabled()
{
    deleteKey(WebPreferencesKey::formControlRefreshEnabledKey());
}

void WebPreferences::setIFrameResourceMonitoringTestingSettingsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::iFrameResourceMonitoringTestingSettingsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::iFrameResourceMonitoringTestingSettingsEnabledKey(), value, true);
}

bool WebPreferences::iFrameResourceMonitoringTestingSettingsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::iFrameResourceMonitoringTestingSettingsEnabledKey());
}

void WebPreferences::deleteIFrameResourceMonitoringTestingSettingsEnabled()
{
    deleteKey(WebPreferencesKey::iFrameResourceMonitoringTestingSettingsEnabledKey());
}

void WebPreferences::setIFrameResourceMonitoringEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::iFrameResourceMonitoringEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::iFrameResourceMonitoringEnabledKey(), value, true);
}

bool WebPreferences::iFrameResourceMonitoringEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::iFrameResourceMonitoringEnabledKey());
}

void WebPreferences::deleteIFrameResourceMonitoringEnabled()
{
    deleteKey(WebPreferencesKey::iFrameResourceMonitoringEnabledKey());
}

void WebPreferences::setFullScreenKeyboardLock(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fullScreenKeyboardLockKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fullScreenKeyboardLockKey(), value, true);
}

bool WebPreferences::fullScreenKeyboardLock() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fullScreenKeyboardLockKey());
}

void WebPreferences::deleteFullScreenKeyboardLock()
{
    deleteKey(WebPreferencesKey::fullScreenKeyboardLockKey());
}

void WebPreferences::setFullScreenEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fullScreenEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fullScreenEnabledKey(), value, false);
}

bool WebPreferences::fullScreenEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fullScreenEnabledKey());
}

void WebPreferences::deleteFullScreenEnabled()
{
    deleteKey(WebPreferencesKey::fullScreenEnabledKey());
}

void WebPreferences::setFullscreenSceneAspectRatioLockingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fullscreenSceneAspectRatioLockingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fullscreenSceneAspectRatioLockingEnabledKey(), value, true);
}

bool WebPreferences::fullscreenSceneAspectRatioLockingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fullscreenSceneAspectRatioLockingEnabledKey());
}

void WebPreferences::deleteFullscreenSceneAspectRatioLockingEnabled()
{
    deleteKey(WebPreferencesKey::fullscreenSceneAspectRatioLockingEnabledKey());
}

void WebPreferences::setFullscreenSceneDimmingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fullscreenSceneDimmingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fullscreenSceneDimmingEnabledKey(), value, true);
}

bool WebPreferences::fullscreenSceneDimmingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fullscreenSceneDimmingEnabledKey());
}

void WebPreferences::deleteFullscreenSceneDimmingEnabled()
{
    deleteKey(WebPreferencesKey::fullscreenSceneDimmingEnabledKey());
}

void WebPreferences::setCaptureAudioInGPUProcessEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::captureAudioInGPUProcessEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::captureAudioInGPUProcessEnabledKey(), value, true);
}

bool WebPreferences::captureAudioInGPUProcessEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::captureAudioInGPUProcessEnabledKey());
}

void WebPreferences::deleteCaptureAudioInGPUProcessEnabled()
{
    deleteKey(WebPreferencesKey::captureAudioInGPUProcessEnabledKey());
}

void WebPreferences::setBlockMediaLayerRehostingInWebContentProcess(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blockMediaLayerRehostingInWebContentProcessKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blockMediaLayerRehostingInWebContentProcessKey(), value, true);
}

bool WebPreferences::blockMediaLayerRehostingInWebContentProcess() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blockMediaLayerRehostingInWebContentProcessKey());
}

void WebPreferences::deleteBlockMediaLayerRehostingInWebContentProcess()
{
    deleteKey(WebPreferencesKey::blockMediaLayerRehostingInWebContentProcessKey());
}

void WebPreferences::setUseGPUProcessForCanvasRenderingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useGPUProcessForCanvasRenderingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useGPUProcessForCanvasRenderingEnabledKey(), value, false);
}

bool WebPreferences::useGPUProcessForCanvasRenderingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useGPUProcessForCanvasRenderingEnabledKey());
}

void WebPreferences::deleteUseGPUProcessForCanvasRenderingEnabled()
{
    deleteKey(WebPreferencesKey::useGPUProcessForCanvasRenderingEnabledKey());
}

void WebPreferences::setManageCaptureStatusBarInGPUProcessEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::manageCaptureStatusBarInGPUProcessEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::manageCaptureStatusBarInGPUProcessEnabledKey(), value, true);
}

bool WebPreferences::manageCaptureStatusBarInGPUProcessEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::manageCaptureStatusBarInGPUProcessEnabledKey());
}

void WebPreferences::deleteManageCaptureStatusBarInGPUProcessEnabled()
{
    deleteKey(WebPreferencesKey::manageCaptureStatusBarInGPUProcessEnabledKey());
}

void WebPreferences::setUseGPUProcessForDOMRenderingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useGPUProcessForDOMRenderingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useGPUProcessForDOMRenderingEnabledKey(), value, false);
}

bool WebPreferences::useGPUProcessForDOMRenderingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useGPUProcessForDOMRenderingEnabledKey());
}

void WebPreferences::deleteUseGPUProcessForDOMRenderingEnabled()
{
    deleteKey(WebPreferencesKey::useGPUProcessForDOMRenderingEnabledKey());
}

void WebPreferences::setUseGPUProcessForMediaEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useGPUProcessForMediaEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useGPUProcessForMediaEnabledKey(), value, false);
}

bool WebPreferences::useGPUProcessForMediaEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useGPUProcessForMediaEnabledKey());
}

void WebPreferences::deleteUseGPUProcessForMediaEnabled()
{
    deleteKey(WebPreferencesKey::useGPUProcessForMediaEnabledKey());
}

void WebPreferences::setUseGPUProcessForDisplayCapture(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useGPUProcessForDisplayCaptureKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useGPUProcessForDisplayCaptureKey(), value, false);
}

bool WebPreferences::useGPUProcessForDisplayCapture() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useGPUProcessForDisplayCaptureKey());
}

void WebPreferences::deleteUseGPUProcessForDisplayCapture()
{
    deleteKey(WebPreferencesKey::useGPUProcessForDisplayCaptureKey());
}

void WebPreferences::setCaptureVideoInGPUProcessEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::captureVideoInGPUProcessEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::captureVideoInGPUProcessEnabledKey(), value, true);
}

bool WebPreferences::captureVideoInGPUProcessEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::captureVideoInGPUProcessEnabledKey());
}

void WebPreferences::deleteCaptureVideoInGPUProcessEnabled()
{
    deleteKey(WebPreferencesKey::captureVideoInGPUProcessEnabledKey());
}

void WebPreferences::setUseGPUProcessForWebGLEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useGPUProcessForWebGLEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useGPUProcessForWebGLEnabledKey(), value, true);
}

bool WebPreferences::useGPUProcessForWebGLEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useGPUProcessForWebGLEnabledKey());
}

void WebPreferences::deleteUseGPUProcessForWebGLEnabled()
{
    deleteKey(WebPreferencesKey::useGPUProcessForWebGLEnabledKey());
}

void WebPreferences::setWebRTCPlatformCodecsInGPUProcessEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCPlatformCodecsInGPUProcessEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCPlatformCodecsInGPUProcessEnabledKey(), value, false);
}

bool WebPreferences::webRTCPlatformCodecsInGPUProcessEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCPlatformCodecsInGPUProcessEnabledKey());
}

void WebPreferences::deleteWebRTCPlatformCodecsInGPUProcessEnabled()
{
    deleteKey(WebPreferencesKey::webRTCPlatformCodecsInGPUProcessEnabledKey());
}

void WebPreferences::setGamepadTriggerRumbleEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::gamepadTriggerRumbleEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::gamepadTriggerRumbleEnabledKey(), value, true);
}

bool WebPreferences::gamepadTriggerRumbleEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::gamepadTriggerRumbleEnabledKey());
}

void WebPreferences::deleteGamepadTriggerRumbleEnabled()
{
    deleteKey(WebPreferencesKey::gamepadTriggerRumbleEnabledKey());
}

void WebPreferences::setGamepadVibrationActuatorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::gamepadVibrationActuatorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::gamepadVibrationActuatorEnabledKey(), value, false);
}

bool WebPreferences::gamepadVibrationActuatorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::gamepadVibrationActuatorEnabledKey());
}

void WebPreferences::deleteGamepadVibrationActuatorEnabled()
{
    deleteKey(WebPreferencesKey::gamepadVibrationActuatorEnabledKey());
}

void WebPreferences::setGamepadsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::gamepadsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::gamepadsEnabledKey(), value, false);
}

bool WebPreferences::gamepadsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::gamepadsEnabledKey());
}

void WebPreferences::deleteGamepadsEnabled()
{
    deleteKey(WebPreferencesKey::gamepadsEnabledKey());
}

void WebPreferences::setGenericCueAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::genericCueAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::genericCueAPIEnabledKey(), value, false);
}

bool WebPreferences::genericCueAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::genericCueAPIEnabledKey());
}

void WebPreferences::deleteGenericCueAPIEnabled()
{
    deleteKey(WebPreferencesKey::genericCueAPIEnabledKey());
}

void WebPreferences::setGeolocationAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::geolocationAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::geolocationAPIEnabledKey(), value, false);
}

bool WebPreferences::geolocationAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::geolocationAPIEnabledKey());
}

void WebPreferences::deleteGeolocationAPIEnabled()
{
    deleteKey(WebPreferencesKey::geolocationAPIEnabledKey());
}

void WebPreferences::setGraphicsContextFiltersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::graphicsContextFiltersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::graphicsContextFiltersEnabledKey(), value, false);
}

bool WebPreferences::graphicsContextFiltersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::graphicsContextFiltersEnabledKey());
}

void WebPreferences::deleteGraphicsContextFiltersEnabled()
{
    deleteKey(WebPreferencesKey::graphicsContextFiltersEnabledKey());
}

void WebPreferences::setAcceleratedDrawingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::acceleratedDrawingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::acceleratedDrawingEnabledKey(), value, true);
}

bool WebPreferences::acceleratedDrawingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::acceleratedDrawingEnabledKey());
}

void WebPreferences::deleteAcceleratedDrawingEnabled()
{
    deleteKey(WebPreferencesKey::acceleratedDrawingEnabledKey());
}

void WebPreferences::setModelElementEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::modelElementEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::modelElementEnabledKey(), value, false);
}

bool WebPreferences::modelElementEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::modelElementEnabledKey());
}

void WebPreferences::deleteModelElementEnabled()
{
    deleteKey(WebPreferencesKey::modelElementEnabledKey());
}

void WebPreferences::setModelDocumentEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::modelDocumentEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::modelDocumentEnabledKey(), value, true);
}

bool WebPreferences::modelDocumentEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::modelDocumentEnabledKey());
}

void WebPreferences::deleteModelDocumentEnabled()
{
    deleteKey(WebPreferencesKey::modelDocumentEnabledKey());
}

void WebPreferences::setInteractiveFormValidationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::interactiveFormValidationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::interactiveFormValidationEnabledKey(), value, false);
}

bool WebPreferences::interactiveFormValidationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::interactiveFormValidationEnabledKey());
}

void WebPreferences::deleteInteractiveFormValidationEnabled()
{
    deleteKey(WebPreferencesKey::interactiveFormValidationEnabledKey());
}

void WebPreferences::setMediaEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaEnabledKey(), value, false);
}

bool WebPreferences::mediaEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaEnabledKey());
}

void WebPreferences::deleteMediaEnabled()
{
    deleteKey(WebPreferencesKey::mediaEnabledKey());
}

void WebPreferences::setInputTypeColorEnhancementsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inputTypeColorEnhancementsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inputTypeColorEnhancementsEnabledKey(), value, false);
}

bool WebPreferences::inputTypeColorEnhancementsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inputTypeColorEnhancementsEnabledKey());
}

void WebPreferences::deleteInputTypeColorEnhancementsEnabled()
{
    deleteKey(WebPreferencesKey::inputTypeColorEnhancementsEnabledKey());
}

void WebPreferences::setDetailsAutoExpandEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::detailsAutoExpandEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::detailsAutoExpandEnabledKey(), value, false);
}

bool WebPreferences::detailsAutoExpandEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::detailsAutoExpandEnabledKey());
}

void WebPreferences::deleteDetailsAutoExpandEnabled()
{
    deleteKey(WebPreferencesKey::detailsAutoExpandEnabledKey());
}

void WebPreferences::setCommandAttributesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::commandAttributesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::commandAttributesEnabledKey(), value, false);
}

bool WebPreferences::commandAttributesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::commandAttributesEnabledKey());
}

void WebPreferences::deleteCommandAttributesEnabled()
{
    deleteKey(WebPreferencesKey::commandAttributesEnabledKey());
}

void WebPreferences::setHTMLLegacyAttributeValueSerializationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::hTMLLegacyAttributeValueSerializationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::hTMLLegacyAttributeValueSerializationEnabledKey(), value, true);
}

bool WebPreferences::hTMLLegacyAttributeValueSerializationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::hTMLLegacyAttributeValueSerializationEnabledKey());
}

void WebPreferences::deleteHTMLLegacyAttributeValueSerializationEnabled()
{
    deleteKey(WebPreferencesKey::hTMLLegacyAttributeValueSerializationEnabledKey());
}

void WebPreferences::setPopoverAttributeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::popoverAttributeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::popoverAttributeEnabledKey(), value, false);
}

bool WebPreferences::popoverAttributeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::popoverAttributeEnabledKey());
}

void WebPreferences::deletePopoverAttributeEnabled()
{
    deleteKey(WebPreferencesKey::popoverAttributeEnabledKey());
}

void WebPreferences::setSwitchControlEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::switchControlEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::switchControlEnabledKey(), value, false);
}

bool WebPreferences::switchControlEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::switchControlEnabledKey());
}

void WebPreferences::deleteSwitchControlEnabled()
{
    deleteKey(WebPreferencesKey::switchControlEnabledKey());
}

void WebPreferences::setHTTPSByDefaultEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::httpSByDefaultEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::httpSByDefaultEnabledKey(), value, true);
}

bool WebPreferences::httpSByDefaultEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::httpSByDefaultEnabledKey());
}

void WebPreferences::deleteHTTPSByDefaultEnabled()
{
    deleteKey(WebPreferencesKey::httpSByDefaultEnabledKey());
}

void WebPreferences::setHiddenPageDOMTimerThrottlingAutoIncreases(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingAutoIncreasesKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingAutoIncreasesKey(), value, false);
}

bool WebPreferences::hiddenPageDOMTimerThrottlingAutoIncreases() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingAutoIncreasesKey());
}

void WebPreferences::deleteHiddenPageDOMTimerThrottlingAutoIncreases()
{
    deleteKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingAutoIncreasesKey());
}

void WebPreferences::setHiddenPageDOMTimerThrottlingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingEnabledKey(), value, false);
}

bool WebPreferences::hiddenPageDOMTimerThrottlingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingEnabledKey());
}

void WebPreferences::deleteHiddenPageDOMTimerThrottlingEnabled()
{
    deleteKey(WebPreferencesKey::hiddenPageDOMTimerThrottlingEnabledKey());
}

void WebPreferences::setHostedBlurMaterialInMediaControlsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::hostedBlurMaterialInMediaControlsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::hostedBlurMaterialInMediaControlsEnabledKey(), value, true);
}

bool WebPreferences::hostedBlurMaterialInMediaControlsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::hostedBlurMaterialInMediaControlsEnabledKey());
}

void WebPreferences::deleteHostedBlurMaterialInMediaControlsEnabled()
{
    deleteKey(WebPreferencesKey::hostedBlurMaterialInMediaControlsEnabledKey());
}

void WebPreferences::setBlockIOKitInWebContentSandbox(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::blockIOKitInWebContentSandboxKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::blockIOKitInWebContentSandboxKey(), value, true);
}

bool WebPreferences::blockIOKitInWebContentSandbox() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::blockIOKitInWebContentSandboxKey());
}

void WebPreferences::deleteBlockIOKitInWebContentSandbox()
{
    deleteKey(WebPreferencesKey::blockIOKitInWebContentSandboxKey());
}

void WebPreferences::setIOSurfaceLosslessCompressionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::iOSurfaceLosslessCompressionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::iOSurfaceLosslessCompressionEnabledKey(), value, true);
}

bool WebPreferences::iOSurfaceLosslessCompressionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::iOSurfaceLosslessCompressionEnabledKey());
}

void WebPreferences::deleteIOSurfaceLosslessCompressionEnabled()
{
    deleteKey(WebPreferencesKey::iOSurfaceLosslessCompressionEnabledKey());
}

void WebPreferences::setIPCTestingAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::ipcTestingAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::ipcTestingAPIEnabledKey(), value, true);
}

bool WebPreferences::ipcTestingAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::ipcTestingAPIEnabledKey());
}

void WebPreferences::deleteIPCTestingAPIEnabled()
{
    deleteKey(WebPreferencesKey::ipcTestingAPIEnabledKey());
}

void WebPreferences::setItpDebugModeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::itpDebugModeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::itpDebugModeEnabledKey(), value, false);
}

bool WebPreferences::itpDebugModeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::itpDebugModeEnabledKey());
}

void WebPreferences::deleteItpDebugModeEnabled()
{
    deleteKey(WebPreferencesKey::itpDebugModeEnabledKey());
}

void WebPreferences::setTextAutosizingUsesIdempotentMode(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::textAutosizingUsesIdempotentModeKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::textAutosizingUsesIdempotentModeKey(), value, false);
}

bool WebPreferences::textAutosizingUsesIdempotentMode() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::textAutosizingUsesIdempotentModeKey());
}

void WebPreferences::deleteTextAutosizingUsesIdempotentMode()
{
    deleteKey(WebPreferencesKey::textAutosizingUsesIdempotentModeKey());
}

void WebPreferences::setIgnoreInvalidMessageWhenIPCTestingAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::ignoreInvalidMessageWhenIPCTestingAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::ignoreInvalidMessageWhenIPCTestingAPIEnabledKey(), value, true);
}

bool WebPreferences::ignoreInvalidMessageWhenIPCTestingAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::ignoreInvalidMessageWhenIPCTestingAPIEnabledKey());
}

void WebPreferences::deleteIgnoreInvalidMessageWhenIPCTestingAPIEnabled()
{
    deleteKey(WebPreferencesKey::ignoreInvalidMessageWhenIPCTestingAPIEnabledKey());
}

void WebPreferences::setIgnoreIframeEmbeddingProtectionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::ignoreIframeEmbeddingProtectionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::ignoreIframeEmbeddingProtectionsEnabledKey(), value, true);
}

bool WebPreferences::ignoreIframeEmbeddingProtectionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::ignoreIframeEmbeddingProtectionsEnabledKey());
}

void WebPreferences::deleteIgnoreIframeEmbeddingProtectionsEnabled()
{
    deleteKey(WebPreferencesKey::ignoreIframeEmbeddingProtectionsEnabledKey());
}

void WebPreferences::setImageAnalysisDuringFindInPageEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::imageAnalysisDuringFindInPageEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::imageAnalysisDuringFindInPageEnabledKey(), value, true);
}

bool WebPreferences::imageAnalysisDuringFindInPageEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::imageAnalysisDuringFindInPageEnabledKey());
}

void WebPreferences::deleteImageAnalysisDuringFindInPageEnabled()
{
    deleteKey(WebPreferencesKey::imageAnalysisDuringFindInPageEnabledKey());
}

void WebPreferences::setImageAnimationControlEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::imageAnimationControlEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::imageAnimationControlEnabledKey(), value, false);
}

bool WebPreferences::imageAnimationControlEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::imageAnimationControlEnabledKey());
}

void WebPreferences::deleteImageAnimationControlEnabled()
{
    deleteKey(WebPreferencesKey::imageAnimationControlEnabledKey());
}

void WebPreferences::setImageCaptureEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::imageCaptureEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::imageCaptureEnabledKey(), value, false);
}

bool WebPreferences::imageCaptureEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::imageCaptureEnabledKey());
}

void WebPreferences::deleteImageCaptureEnabled()
{
    deleteKey(WebPreferencesKey::imageCaptureEnabledKey());
}

void WebPreferences::setImageControlsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::imageControlsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::imageControlsEnabledKey(), value, true);
}

bool WebPreferences::imageControlsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::imageControlsEnabledKey());
}

void WebPreferences::deleteImageControlsEnabled()
{
    deleteKey(WebPreferencesKey::imageControlsEnabledKey());
}

void WebPreferences::setInWindowFullscreenEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inWindowFullscreenEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inWindowFullscreenEnabledKey(), value, true);
}

bool WebPreferences::inWindowFullscreenEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inWindowFullscreenEnabledKey());
}

void WebPreferences::deleteInWindowFullscreenEnabled()
{
    deleteKey(WebPreferencesKey::inWindowFullscreenEnabledKey());
}

void WebPreferences::setIncludeIgnoredInCoreAXTree(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::includeIgnoredInCoreAXTreeKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::includeIgnoredInCoreAXTreeKey(), value, true);
}

bool WebPreferences::includeIgnoredInCoreAXTree() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::includeIgnoredInCoreAXTreeKey());
}

void WebPreferences::deleteIncludeIgnoredInCoreAXTree()
{
    deleteKey(WebPreferencesKey::includeIgnoredInCoreAXTreeKey());
}

void WebPreferences::setIndexedDBAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::indexedDBAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::indexedDBAPIEnabledKey(), value, false);
}

bool WebPreferences::indexedDBAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::indexedDBAPIEnabledKey());
}

void WebPreferences::deleteIndexedDBAPIEnabled()
{
    deleteKey(WebPreferencesKey::indexedDBAPIEnabledKey());
}

void WebPreferences::setInteractionRegionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::interactionRegionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::interactionRegionsEnabledKey(), value, true);
}

bool WebPreferences::interactionRegionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::interactionRegionsEnabledKey());
}

void WebPreferences::deleteInteractionRegionsEnabled()
{
    deleteKey(WebPreferencesKey::interactionRegionsEnabledKey());
}

void WebPreferences::setIsAccessibilityIsolatedTreeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isAccessibilityIsolatedTreeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isAccessibilityIsolatedTreeEnabledKey(), value, false);
}

bool WebPreferences::isAccessibilityIsolatedTreeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isAccessibilityIsolatedTreeEnabledKey());
}

void WebPreferences::deleteIsAccessibilityIsolatedTreeEnabled()
{
    deleteKey(WebPreferencesKey::isAccessibilityIsolatedTreeEnabledKey());
}

void WebPreferences::setJavaScriptEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::javaScriptEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::javaScriptEnabledKey(), value, false);
}

bool WebPreferences::javaScriptEnabled() const
{
    if (m_javaScriptEnabledInspectorOverride)
        return m_javaScriptEnabledInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::javaScriptEnabledKey());
}

void WebPreferences::deleteJavaScriptEnabled()
{
    deleteKey(WebPreferencesKey::javaScriptEnabledKey());
}

void WebPreferences::setKeyboardDismissalGestureEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::keyboardDismissalGestureEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::keyboardDismissalGestureEnabledKey(), value, true);
}

bool WebPreferences::keyboardDismissalGestureEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::keyboardDismissalGestureEnabledKey());
}

void WebPreferences::deleteKeyboardDismissalGestureEnabled()
{
    deleteKey(WebPreferencesKey::keyboardDismissalGestureEnabledKey());
}

void WebPreferences::setLayerBasedSVGEngineEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::layerBasedSVGEngineEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::layerBasedSVGEngineEnabledKey(), value, true);
}

bool WebPreferences::layerBasedSVGEngineEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::layerBasedSVGEngineEnabledKey());
}

void WebPreferences::deleteLayerBasedSVGEngineEnabled()
{
    deleteKey(WebPreferencesKey::layerBasedSVGEngineEnabledKey());
}

void WebPreferences::setLazyIframeLoadingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::lazyIframeLoadingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::lazyIframeLoadingEnabledKey(), value, false);
}

bool WebPreferences::lazyIframeLoadingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::lazyIframeLoadingEnabledKey());
}

void WebPreferences::deleteLazyIframeLoadingEnabled()
{
    deleteKey(WebPreferencesKey::lazyIframeLoadingEnabledKey());
}

void WebPreferences::setLazyImageLoadingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::lazyImageLoadingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::lazyImageLoadingEnabledKey(), value, false);
}

bool WebPreferences::lazyImageLoadingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::lazyImageLoadingEnabledKey());
}

void WebPreferences::deleteLazyImageLoadingEnabled()
{
    deleteKey(WebPreferencesKey::lazyImageLoadingEnabledKey());
}

void WebPreferences::setLegacyOverflowScrollingTouchEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::legacyOverflowScrollingTouchEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::legacyOverflowScrollingTouchEnabledKey(), value, true);
}

bool WebPreferences::legacyOverflowScrollingTouchEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::legacyOverflowScrollingTouchEnabledKey());
}

void WebPreferences::deleteLegacyOverflowScrollingTouchEnabled()
{
    deleteKey(WebPreferencesKey::legacyOverflowScrollingTouchEnabledKey());
}

void WebPreferences::setLegacyLineLayoutVisualCoverageEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::legacyLineLayoutVisualCoverageEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::legacyLineLayoutVisualCoverageEnabledKey(), value, true);
}

bool WebPreferences::legacyLineLayoutVisualCoverageEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::legacyLineLayoutVisualCoverageEnabledKey());
}

void WebPreferences::deleteLegacyLineLayoutVisualCoverageEnabled()
{
    deleteKey(WebPreferencesKey::legacyLineLayoutVisualCoverageEnabledKey());
}

void WebPreferences::setShowModalDialogEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::showModalDialogEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::showModalDialogEnabledKey(), value, false);
}

bool WebPreferences::showModalDialogEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::showModalDialogEnabledKey());
}

void WebPreferences::deleteShowModalDialogEnabled()
{
    deleteKey(WebPreferencesKey::showModalDialogEnabledKey());
}

void WebPreferences::setMediaCaptureRequiresSecureConnection(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaCaptureRequiresSecureConnectionKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaCaptureRequiresSecureConnectionKey(), value, true);
}

bool WebPreferences::mediaCaptureRequiresSecureConnection() const
{
    if (m_mediaCaptureRequiresSecureConnectionInspectorOverride)
        return m_mediaCaptureRequiresSecureConnectionInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaCaptureRequiresSecureConnectionKey());
}

void WebPreferences::deleteMediaCaptureRequiresSecureConnection()
{
    deleteKey(WebPreferencesKey::mediaCaptureRequiresSecureConnectionKey());
}

void WebPreferences::setLimitedMatroskaSupportEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::limitedMatroskaSupportEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::limitedMatroskaSupportEnabledKey(), value, false);
}

bool WebPreferences::limitedMatroskaSupportEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::limitedMatroskaSupportEnabledKey());
}

void WebPreferences::deleteLimitedMatroskaSupportEnabled()
{
    deleteKey(WebPreferencesKey::limitedMatroskaSupportEnabledKey());
}

void WebPreferences::setLinearMediaPlayerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::linearMediaPlayerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::linearMediaPlayerEnabledKey(), value, true);
}

bool WebPreferences::linearMediaPlayerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::linearMediaPlayerEnabledKey());
}

void WebPreferences::deleteLinearMediaPlayerEnabled()
{
    deleteKey(WebPreferencesKey::linearMediaPlayerEnabledKey());
}

void WebPreferences::setLinkSanitizerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::linkSanitizerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::linkSanitizerEnabledKey(), value, true);
}

bool WebPreferences::linkSanitizerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::linkSanitizerEnabledKey());
}

void WebPreferences::deleteLinkSanitizerEnabled()
{
    deleteKey(WebPreferencesKey::linkSanitizerEnabledKey());
}

void WebPreferences::setLinkPreconnectEarlyHintsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::linkPreconnectEarlyHintsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::linkPreconnectEarlyHintsEnabledKey(), value, false);
}

bool WebPreferences::linkPreconnectEarlyHintsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::linkPreconnectEarlyHintsEnabledKey());
}

void WebPreferences::deleteLinkPreconnectEarlyHintsEnabled()
{
    deleteKey(WebPreferencesKey::linkPreconnectEarlyHintsEnabledKey());
}

void WebPreferences::setLinkPrefetchEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::linkPrefetchEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::linkPrefetchEnabledKey(), value, true);
}

bool WebPreferences::linkPrefetchEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::linkPrefetchEnabledKey());
}

void WebPreferences::deleteLinkPrefetchEnabled()
{
    deleteKey(WebPreferencesKey::linkPrefetchEnabledKey());
}

void WebPreferences::setLoadWebArchiveWithEphemeralStorageEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::loadWebArchiveWithEphemeralStorageEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::loadWebArchiveWithEphemeralStorageEnabledKey(), value, false);
}

bool WebPreferences::loadWebArchiveWithEphemeralStorageEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::loadWebArchiveWithEphemeralStorageEnabledKey());
}

void WebPreferences::deleteLoadWebArchiveWithEphemeralStorageEnabled()
{
    deleteKey(WebPreferencesKey::loadWebArchiveWithEphemeralStorageEnabledKey());
}

void WebPreferences::setLocalFileContentSniffingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::localFileContentSniffingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::localFileContentSniffingEnabledKey(), value, true);
}

bool WebPreferences::localFileContentSniffingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::localFileContentSniffingEnabledKey());
}

void WebPreferences::deleteLocalFileContentSniffingEnabled()
{
    deleteKey(WebPreferencesKey::localFileContentSniffingEnabledKey());
}

void WebPreferences::setLocalNetworkAccessEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::localNetworkAccessEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::localNetworkAccessEnabledKey(), value, true);
}

bool WebPreferences::localNetworkAccessEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::localNetworkAccessEnabledKey());
}

void WebPreferences::deleteLocalNetworkAccessEnabled()
{
    deleteKey(WebPreferencesKey::localNetworkAccessEnabledKey());
}

void WebPreferences::setLocalStorageEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::localStorageEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::localStorageEnabledKey(), value, false);
}

bool WebPreferences::localStorageEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::localStorageEnabledKey());
}

void WebPreferences::deleteLocalStorageEnabled()
{
    deleteKey(WebPreferencesKey::localStorageEnabledKey());
}

void WebPreferences::setLockdownFontParserEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::lockdownFontParserEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::lockdownFontParserEnabledKey(), value, false);
}

bool WebPreferences::lockdownFontParserEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::lockdownFontParserEnabledKey());
}

void WebPreferences::deleteLockdownFontParserEnabled()
{
    deleteKey(WebPreferencesKey::lockdownFontParserEnabledKey());
}

void WebPreferences::setLogsPageMessagesToSystemConsoleEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::logsPageMessagesToSystemConsoleEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::logsPageMessagesToSystemConsoleEnabledKey(), value, true);
}

bool WebPreferences::logsPageMessagesToSystemConsoleEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::logsPageMessagesToSystemConsoleEnabledKey());
}

void WebPreferences::deleteLogsPageMessagesToSystemConsoleEnabled()
{
    deleteKey(WebPreferencesKey::logsPageMessagesToSystemConsoleEnabledKey());
}

void WebPreferences::setLoginStatusAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::loginStatusAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::loginStatusAPIEnabledKey(), value, true);
}

bool WebPreferences::loginStatusAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::loginStatusAPIEnabledKey());
}

void WebPreferences::deleteLoginStatusAPIEnabled()
{
    deleteKey(WebPreferencesKey::loginStatusAPIEnabledKey());
}

void WebPreferences::setMainContentUserGestureOverrideEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mainContentUserGestureOverrideEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mainContentUserGestureOverrideEnabledKey(), value, false);
}

bool WebPreferences::mainContentUserGestureOverrideEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mainContentUserGestureOverrideEnabledKey());
}

void WebPreferences::deleteMainContentUserGestureOverrideEnabled()
{
    deleteKey(WebPreferencesKey::mainContentUserGestureOverrideEnabledKey());
}

void WebPreferences::setManagedMediaSourceEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::managedMediaSourceEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::managedMediaSourceEnabledKey(), value, false);
}

bool WebPreferences::managedMediaSourceEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::managedMediaSourceEnabledKey());
}

void WebPreferences::deleteManagedMediaSourceEnabled()
{
    deleteKey(WebPreferencesKey::managedMediaSourceEnabledKey());
}

void WebPreferences::setManagedMediaSourceNeedsAirPlay(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::managedMediaSourceNeedsAirPlayKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::managedMediaSourceNeedsAirPlayKey(), value, false);
}

bool WebPreferences::managedMediaSourceNeedsAirPlay() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::managedMediaSourceNeedsAirPlayKey());
}

void WebPreferences::deleteManagedMediaSourceNeedsAirPlay()
{
    deleteKey(WebPreferencesKey::managedMediaSourceNeedsAirPlayKey());
}

void WebPreferences::setCoreMathMLEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::coreMathMLEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::coreMathMLEnabledKey(), value, true);
}

bool WebPreferences::coreMathMLEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::coreMathMLEnabledKey());
}

void WebPreferences::deleteCoreMathMLEnabled()
{
    deleteKey(WebPreferencesKey::coreMathMLEnabledKey());
}

void WebPreferences::setMediaCapabilitiesExtensionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaCapabilitiesExtensionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaCapabilitiesExtensionsEnabledKey(), value, false);
}

bool WebPreferences::mediaCapabilitiesExtensionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaCapabilitiesExtensionsEnabledKey());
}

void WebPreferences::deleteMediaCapabilitiesExtensionsEnabled()
{
    deleteKey(WebPreferencesKey::mediaCapabilitiesExtensionsEnabledKey());
}

void WebPreferences::setMediaCapabilityGrantsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaCapabilityGrantsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaCapabilityGrantsEnabledKey(), value, false);
}

bool WebPreferences::mediaCapabilityGrantsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaCapabilityGrantsEnabledKey());
}

void WebPreferences::deleteMediaCapabilityGrantsEnabled()
{
    deleteKey(WebPreferencesKey::mediaCapabilityGrantsEnabledKey());
}

void WebPreferences::setMediaPlaybackEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaPlaybackEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaPlaybackEnabledKey(), value, false);
}

bool WebPreferences::mediaPlaybackEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaPlaybackEnabledKey());
}

void WebPreferences::deleteMediaPlaybackEnabled()
{
    deleteKey(WebPreferencesKey::mediaPlaybackEnabledKey());
}

void WebPreferences::setMediaSessionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaSessionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaSessionEnabledKey(), value, false);
}

bool WebPreferences::mediaSessionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaSessionEnabledKey());
}

void WebPreferences::deleteMediaSessionEnabled()
{
    deleteKey(WebPreferencesKey::mediaSessionEnabledKey());
}

void WebPreferences::setMediaSourceEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaSourceEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaSourceEnabledKey(), value, false);
}

bool WebPreferences::mediaSourceEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaSourceEnabledKey());
}

void WebPreferences::deleteMediaSourceEnabled()
{
    deleteKey(WebPreferencesKey::mediaSourceEnabledKey());
}

void WebPreferences::setMediaDevicesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaDevicesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaDevicesEnabledKey(), value, false);
}

bool WebPreferences::mediaDevicesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaDevicesEnabledKey());
}

void WebPreferences::deleteMediaDevicesEnabled()
{
    deleteKey(WebPreferencesKey::mediaDevicesEnabledKey());
}

void WebPreferences::setMediaRecorderEnabledWebM(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledWebMKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledWebMKey(), value, false);
}

bool WebPreferences::mediaRecorderEnabledWebM() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledWebMKey());
}

void WebPreferences::deleteMediaRecorderEnabledWebM()
{
    deleteKey(WebPreferencesKey::mediaRecorderEnabledWebMKey());
}

void WebPreferences::setMediaRecorderEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledKey(), value, false);
}

bool WebPreferences::mediaRecorderEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaRecorderEnabledKey());
}

void WebPreferences::deleteMediaRecorderEnabled()
{
    deleteKey(WebPreferencesKey::mediaRecorderEnabledKey());
}

void WebPreferences::setMediaSessionCaptureToggleAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaSessionCaptureToggleAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaSessionCaptureToggleAPIEnabledKey(), value, false);
}

bool WebPreferences::mediaSessionCaptureToggleAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaSessionCaptureToggleAPIEnabledKey());
}

void WebPreferences::deleteMediaSessionCaptureToggleAPIEnabled()
{
    deleteKey(WebPreferencesKey::mediaSessionCaptureToggleAPIEnabledKey());
}

void WebPreferences::setMediaSourceInWorkerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaSourceInWorkerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaSourceInWorkerEnabledKey(), value, false);
}

bool WebPreferences::mediaSourceInWorkerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaSourceInWorkerEnabledKey());
}

void WebPreferences::deleteMediaSourceInWorkerEnabled()
{
    deleteKey(WebPreferencesKey::mediaSourceInWorkerEnabledKey());
}

void WebPreferences::setMediaSourcePrefersDecompressionSession(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaSourcePrefersDecompressionSessionKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaSourcePrefersDecompressionSessionKey(), value, false);
}

bool WebPreferences::mediaSourcePrefersDecompressionSession() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaSourcePrefersDecompressionSessionKey());
}

void WebPreferences::deleteMediaSourcePrefersDecompressionSession()
{
    deleteKey(WebPreferencesKey::mediaSourcePrefersDecompressionSessionKey());
}

void WebPreferences::setMediaStreamTrackProcessingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mediaStreamTrackProcessingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mediaStreamTrackProcessingEnabledKey(), value, false);
}

bool WebPreferences::mediaStreamTrackProcessingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mediaStreamTrackProcessingEnabledKey());
}

void WebPreferences::deleteMediaStreamTrackProcessingEnabled()
{
    deleteKey(WebPreferencesKey::mediaStreamTrackProcessingEnabledKey());
}

void WebPreferences::setMetaViewportInteractiveWidgetEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::metaViewportInteractiveWidgetEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::metaViewportInteractiveWidgetEnabledKey(), value, true);
}

bool WebPreferences::metaViewportInteractiveWidgetEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::metaViewportInteractiveWidgetEnabledKey());
}

void WebPreferences::deleteMetaViewportInteractiveWidgetEnabled()
{
    deleteKey(WebPreferencesKey::metaViewportInteractiveWidgetEnabledKey());
}

void WebPreferences::setModelNoPortalAttributeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::modelNoPortalAttributeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::modelNoPortalAttributeEnabledKey(), value, true);
}

bool WebPreferences::modelNoPortalAttributeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::modelNoPortalAttributeEnabledKey());
}

void WebPreferences::deleteModelNoPortalAttributeEnabled()
{
    deleteKey(WebPreferencesKey::modelNoPortalAttributeEnabledKey());
}

void WebPreferences::setShouldUseModernAVContentKeySession(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldUseModernAVContentKeySessionKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldUseModernAVContentKeySessionKey(), value, true);
}

bool WebPreferences::shouldUseModernAVContentKeySession() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldUseModernAVContentKeySessionKey());
}

void WebPreferences::deleteShouldUseModernAVContentKeySession()
{
    deleteKey(WebPreferencesKey::shouldUseModernAVContentKeySessionKey());
}

void WebPreferences::setMomentumScrollingAnimatorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::momentumScrollingAnimatorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::momentumScrollingAnimatorEnabledKey(), value, true);
}

bool WebPreferences::momentumScrollingAnimatorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::momentumScrollingAnimatorEnabledKey());
}

void WebPreferences::deleteMomentumScrollingAnimatorEnabled()
{
    deleteKey(WebPreferencesKey::momentumScrollingAnimatorEnabledKey());
}

void WebPreferences::setInputTypeMonthEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inputTypeMonthEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inputTypeMonthEnabledKey(), value, false);
}

bool WebPreferences::inputTypeMonthEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inputTypeMonthEnabledKey());
}

void WebPreferences::deleteInputTypeMonthEnabled()
{
    deleteKey(WebPreferencesKey::inputTypeMonthEnabledKey());
}

void WebPreferences::setMouseEventsSimulationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::mouseEventsSimulationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::mouseEventsSimulationEnabledKey(), value, true);
}

bool WebPreferences::mouseEventsSimulationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::mouseEventsSimulationEnabledKey());
}

void WebPreferences::deleteMouseEventsSimulationEnabled()
{
    deleteKey(WebPreferencesKey::mouseEventsSimulationEnabledKey());
}

void WebPreferences::setMuteCameraOnMicrophoneInterruptionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::muteCameraOnMicrophoneInterruptionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::muteCameraOnMicrophoneInterruptionEnabledKey(), value, true);
}

bool WebPreferences::muteCameraOnMicrophoneInterruptionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::muteCameraOnMicrophoneInterruptionEnabledKey());
}

void WebPreferences::deleteMuteCameraOnMicrophoneInterruptionEnabled()
{
    deleteKey(WebPreferencesKey::muteCameraOnMicrophoneInterruptionEnabledKey());
}

void WebPreferences::setNavigationAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::navigationAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::navigationAPIEnabledKey(), value, true);
}

bool WebPreferences::navigationAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::navigationAPIEnabledKey());
}

void WebPreferences::deleteNavigationAPIEnabled()
{
    deleteKey(WebPreferencesKey::navigationAPIEnabledKey());
}

void WebPreferences::setNeedsInAppBrowserPrivacyQuirks(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::needsInAppBrowserPrivacyQuirksKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::needsInAppBrowserPrivacyQuirksKey(), value, true);
}

bool WebPreferences::needsInAppBrowserPrivacyQuirks() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::needsInAppBrowserPrivacyQuirksKey());
}

void WebPreferences::deleteNeedsInAppBrowserPrivacyQuirks()
{
    deleteKey(WebPreferencesKey::needsInAppBrowserPrivacyQuirksKey());
}

void WebPreferences::setNeedsSiteSpecificQuirks(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::needsSiteSpecificQuirksKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::needsSiteSpecificQuirksKey(), value, false);
}

bool WebPreferences::needsSiteSpecificQuirks() const
{
    if (m_needsSiteSpecificQuirksInspectorOverride)
        return m_needsSiteSpecificQuirksInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::needsSiteSpecificQuirksKey());
}

void WebPreferences::deleteNeedsSiteSpecificQuirks()
{
    deleteKey(WebPreferencesKey::needsSiteSpecificQuirksKey());
}

void WebPreferences::setNeedsStorageAccessFromFileURLsQuirk(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::needsStorageAccessFromFileURLsQuirkKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::needsStorageAccessFromFileURLsQuirkKey(), value, false);
}

bool WebPreferences::needsStorageAccessFromFileURLsQuirk() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::needsStorageAccessFromFileURLsQuirkKey());
}

void WebPreferences::deleteNeedsStorageAccessFromFileURLsQuirk()
{
    deleteKey(WebPreferencesKey::needsStorageAccessFromFileURLsQuirkKey());
}

void WebPreferences::setFlexFormattingContextIntegrationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::flexFormattingContextIntegrationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::flexFormattingContextIntegrationEnabledKey(), value, false);
}

bool WebPreferences::flexFormattingContextIntegrationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::flexFormattingContextIntegrationEnabledKey());
}

void WebPreferences::deleteFlexFormattingContextIntegrationEnabled()
{
    deleteKey(WebPreferencesKey::flexFormattingContextIntegrationEnabledKey());
}

void WebPreferences::setNotificationEventEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::notificationEventEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::notificationEventEnabledKey(), value, true);
}

bool WebPreferences::notificationEventEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::notificationEventEnabledKey());
}

void WebPreferences::deleteNotificationEventEnabled()
{
    deleteKey(WebPreferencesKey::notificationEventEnabledKey());
}

void WebPreferences::setNotificationsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::notificationsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::notificationsEnabledKey(), value, false);
}

bool WebPreferences::notificationsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::notificationsEnabledKey());
}

void WebPreferences::deleteNotificationsEnabled()
{
    deleteKey(WebPreferencesKey::notificationsEnabledKey());
}

void WebPreferences::setObservableEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::observableEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::observableEnabledKey(), value, true);
}

bool WebPreferences::observableEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::observableEnabledKey());
}

void WebPreferences::deleteObservableEnabled()
{
    deleteKey(WebPreferencesKey::observableEnabledKey());
}

void WebPreferences::setAccessibilityThreadTextApisEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::accessibilityThreadTextApisEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::accessibilityThreadTextApisEnabledKey(), value, false);
}

bool WebPreferences::accessibilityThreadTextApisEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::accessibilityThreadTextApisEnabledKey());
}

void WebPreferences::deleteAccessibilityThreadTextApisEnabled()
{
    deleteKey(WebPreferencesKey::accessibilityThreadTextApisEnabledKey());
}

void WebPreferences::setOffscreenCanvasInWorkersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::offscreenCanvasInWorkersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::offscreenCanvasInWorkersEnabledKey(), value, false);
}

bool WebPreferences::offscreenCanvasInWorkersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::offscreenCanvasInWorkersEnabledKey());
}

void WebPreferences::deleteOffscreenCanvasInWorkersEnabled()
{
    deleteKey(WebPreferencesKey::offscreenCanvasInWorkersEnabledKey());
}

void WebPreferences::setOffscreenCanvasEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::offscreenCanvasEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::offscreenCanvasEnabledKey(), value, false);
}

bool WebPreferences::offscreenCanvasEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::offscreenCanvasEnabledKey());
}

void WebPreferences::deleteOffscreenCanvasEnabled()
{
    deleteKey(WebPreferencesKey::offscreenCanvasEnabledKey());
}

void WebPreferences::setOpportunisticSweepingAndGarbageCollectionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::opportunisticSweepingAndGarbageCollectionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::opportunisticSweepingAndGarbageCollectionEnabledKey(), value, true);
}

bool WebPreferences::opportunisticSweepingAndGarbageCollectionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::opportunisticSweepingAndGarbageCollectionEnabledKey());
}

void WebPreferences::deleteOpportunisticSweepingAndGarbageCollectionEnabled()
{
    deleteKey(WebPreferencesKey::opportunisticSweepingAndGarbageCollectionEnabledKey());
}

void WebPreferences::setOptInPartitionedCookiesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::optInPartitionedCookiesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::optInPartitionedCookiesEnabledKey(), value, true);
}

bool WebPreferences::optInPartitionedCookiesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::optInPartitionedCookiesEnabledKey());
}

void WebPreferences::deleteOptInPartitionedCookiesEnabled()
{
    deleteKey(WebPreferencesKey::optInPartitionedCookiesEnabledKey());
}

void WebPreferences::setOverlappingBackingStoreProvidersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::overlappingBackingStoreProvidersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::overlappingBackingStoreProvidersEnabledKey(), value, false);
}

bool WebPreferences::overlappingBackingStoreProvidersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::overlappingBackingStoreProvidersEnabledKey());
}

void WebPreferences::deleteOverlappingBackingStoreProvidersEnabled()
{
    deleteKey(WebPreferencesKey::overlappingBackingStoreProvidersEnabledKey());
}

void WebPreferences::setOverlayRegionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::overlayRegionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::overlayRegionsEnabledKey(), value, true);
}

bool WebPreferences::overlayRegionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::overlayRegionsEnabledKey());
}

void WebPreferences::deleteOverlayRegionsEnabled()
{
    deleteKey(WebPreferencesKey::overlayRegionsEnabledKey());
}

void WebPreferences::setPageVisibilityBasedProcessSuppressionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pageVisibilityBasedProcessSuppressionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pageVisibilityBasedProcessSuppressionEnabledKey(), value, true);
}

bool WebPreferences::pageVisibilityBasedProcessSuppressionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pageVisibilityBasedProcessSuppressionEnabledKey());
}

void WebPreferences::deletePageVisibilityBasedProcessSuppressionEnabled()
{
    deleteKey(WebPreferencesKey::pageVisibilityBasedProcessSuppressionEnabledKey());
}

void WebPreferences::setPermissionsAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::permissionsAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::permissionsAPIEnabledKey(), value, false);
}

bool WebPreferences::permissionsAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::permissionsAPIEnabledKey());
}

void WebPreferences::deletePermissionsAPIEnabled()
{
    deleteKey(WebPreferencesKey::permissionsAPIEnabledKey());
}

void WebPreferences::setPhotoPickerPrefersOriginalImageFormat(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::photoPickerPrefersOriginalImageFormatKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::photoPickerPrefersOriginalImageFormatKey(), value, true);
}

bool WebPreferences::photoPickerPrefersOriginalImageFormat() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::photoPickerPrefersOriginalImageFormatKey());
}

void WebPreferences::deletePhotoPickerPrefersOriginalImageFormat()
{
    deleteKey(WebPreferencesKey::photoPickerPrefersOriginalImageFormatKey());
}

void WebPreferences::setPictureInPicturePlaybackStateEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pictureInPicturePlaybackStateEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pictureInPicturePlaybackStateEnabledKey(), value, true);
}

bool WebPreferences::pictureInPicturePlaybackStateEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pictureInPicturePlaybackStateEnabledKey());
}

void WebPreferences::deletePictureInPicturePlaybackStateEnabled()
{
    deleteKey(WebPreferencesKey::pictureInPicturePlaybackStateEnabledKey());
}

void WebPreferences::setGetCoalescedEventsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::getCoalescedEventsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::getCoalescedEventsEnabledKey(), value, false);
}

bool WebPreferences::getCoalescedEventsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::getCoalescedEventsEnabledKey());
}

void WebPreferences::deleteGetCoalescedEventsEnabled()
{
    deleteKey(WebPreferencesKey::getCoalescedEventsEnabledKey());
}

void WebPreferences::setGetPredictedEventsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::getPredictedEventsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::getPredictedEventsEnabledKey(), value, false);
}

bool WebPreferences::getPredictedEventsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::getPredictedEventsEnabledKey());
}

void WebPreferences::deleteGetPredictedEventsEnabled()
{
    deleteKey(WebPreferencesKey::getPredictedEventsEnabledKey());
}

void WebPreferences::setPointerLockEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pointerLockEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pointerLockEnabledKey(), value, true);
}

bool WebPreferences::pointerLockEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pointerLockEnabledKey());
}

void WebPreferences::deletePointerLockEnabled()
{
    deleteKey(WebPreferencesKey::pointerLockEnabledKey());
}

void WebPreferences::setPointerLockOptionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pointerLockOptionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pointerLockOptionsEnabledKey(), value, false);
}

bool WebPreferences::pointerLockOptionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pointerLockOptionsEnabledKey());
}

void WebPreferences::deletePointerLockOptionsEnabled()
{
    deleteKey(WebPreferencesKey::pointerLockOptionsEnabledKey());
}

void WebPreferences::setPreferPageRenderingUpdatesNear60FPSEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::preferPageRenderingUpdatesNear60FPSEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::preferPageRenderingUpdatesNear60FPSEnabledKey(), value, false);
}

bool WebPreferences::preferPageRenderingUpdatesNear60FPSEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::preferPageRenderingUpdatesNear60FPSEnabledKey());
}

void WebPreferences::deletePreferPageRenderingUpdatesNear60FPSEnabled()
{
    deleteKey(WebPreferencesKey::preferPageRenderingUpdatesNear60FPSEnabledKey());
}

void WebPreferences::setPreferSpatialAudioExperience(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::preferSpatialAudioExperienceKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::preferSpatialAudioExperienceKey(), value, true);
}

bool WebPreferences::preferSpatialAudioExperience() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::preferSpatialAudioExperienceKey());
}

void WebPreferences::deletePreferSpatialAudioExperience()
{
    deleteKey(WebPreferencesKey::preferSpatialAudioExperienceKey());
}

void WebPreferences::setVideoFullsceenPrefersMostVisibleHeuristic(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::videoFullsceenPrefersMostVisibleHeuristicKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::videoFullsceenPrefersMostVisibleHeuristicKey(), value, true);
}

bool WebPreferences::videoFullsceenPrefersMostVisibleHeuristic() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::videoFullsceenPrefersMostVisibleHeuristicKey());
}

void WebPreferences::deleteVideoFullsceenPrefersMostVisibleHeuristic()
{
    deleteKey(WebPreferencesKey::videoFullsceenPrefersMostVisibleHeuristicKey());
}

void WebPreferences::setPrivateClickMeasurementDebugModeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::privateClickMeasurementDebugModeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::privateClickMeasurementDebugModeEnabledKey(), value, false);
}

bool WebPreferences::privateClickMeasurementDebugModeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::privateClickMeasurementDebugModeEnabledKey());
}

void WebPreferences::deletePrivateClickMeasurementDebugModeEnabled()
{
    deleteKey(WebPreferencesKey::privateClickMeasurementDebugModeEnabledKey());
}

void WebPreferences::setPrivateClickMeasurementFraudPreventionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::privateClickMeasurementFraudPreventionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::privateClickMeasurementFraudPreventionEnabledKey(), value, false);
}

bool WebPreferences::privateClickMeasurementFraudPreventionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::privateClickMeasurementFraudPreventionEnabledKey());
}

void WebPreferences::deletePrivateClickMeasurementFraudPreventionEnabled()
{
    deleteKey(WebPreferencesKey::privateClickMeasurementFraudPreventionEnabledKey());
}

void WebPreferences::setPrivateClickMeasurementEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::privateClickMeasurementEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::privateClickMeasurementEnabledKey(), value, false);
}

bool WebPreferences::privateClickMeasurementEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::privateClickMeasurementEnabledKey());
}

void WebPreferences::deletePrivateClickMeasurementEnabled()
{
    deleteKey(WebPreferencesKey::privateClickMeasurementEnabledKey());
}

void WebPreferences::setPrivateTokenUsageByThirdPartyEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::privateTokenUsageByThirdPartyEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::privateTokenUsageByThirdPartyEnabledKey(), value, false);
}

bool WebPreferences::privateTokenUsageByThirdPartyEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::privateTokenUsageByThirdPartyEnabledKey());
}

void WebPreferences::deletePrivateTokenUsageByThirdPartyEnabled()
{
    deleteKey(WebPreferencesKey::privateTokenUsageByThirdPartyEnabledKey());
}

void WebPreferences::setPropagateDamagingInformation(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::propagateDamagingInformationKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::propagateDamagingInformationKey(), value, true);
}

bool WebPreferences::propagateDamagingInformation() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::propagateDamagingInformationKey());
}

void WebPreferences::deletePropagateDamagingInformation()
{
    deleteKey(WebPreferencesKey::propagateDamagingInformationKey());
}

void WebPreferences::setPushAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::pushAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::pushAPIEnabledKey(), value, false);
}

bool WebPreferences::pushAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::pushAPIEnabledKey());
}

void WebPreferences::deletePushAPIEnabled()
{
    deleteKey(WebPreferencesKey::pushAPIEnabledKey());
}

void WebPreferences::setLegacyPluginQuirkForMailSignaturesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::legacyPluginQuirkForMailSignaturesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::legacyPluginQuirkForMailSignaturesEnabledKey(), value, true);
}

bool WebPreferences::legacyPluginQuirkForMailSignaturesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::legacyPluginQuirkForMailSignaturesEnabledKey());
}

void WebPreferences::deleteLegacyPluginQuirkForMailSignaturesEnabled()
{
    deleteKey(WebPreferencesKey::legacyPluginQuirkForMailSignaturesEnabledKey());
}

void WebPreferences::setGoogleAntiFlickerOptimizationQuirkEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::googleAntiFlickerOptimizationQuirkEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::googleAntiFlickerOptimizationQuirkEnabledKey(), value, false);
}

bool WebPreferences::googleAntiFlickerOptimizationQuirkEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::googleAntiFlickerOptimizationQuirkEnabledKey());
}

void WebPreferences::deleteGoogleAntiFlickerOptimizationQuirkEnabled()
{
    deleteKey(WebPreferencesKey::googleAntiFlickerOptimizationQuirkEnabledKey());
}

void WebPreferences::setReadableByteStreamAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::readableByteStreamAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::readableByteStreamAPIEnabledKey(), value, true);
}

bool WebPreferences::readableByteStreamAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::readableByteStreamAPIEnabledKey());
}

void WebPreferences::deleteReadableByteStreamAPIEnabled()
{
    deleteKey(WebPreferencesKey::readableByteStreamAPIEnabledKey());
}

void WebPreferences::setRemoteMediaSessionManagerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::remoteMediaSessionManagerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::remoteMediaSessionManagerEnabledKey(), value, true);
}

bool WebPreferences::remoteMediaSessionManagerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::remoteMediaSessionManagerEnabledKey());
}

void WebPreferences::deleteRemoteMediaSessionManagerEnabled()
{
    deleteKey(WebPreferencesKey::remoteMediaSessionManagerEnabledKey());
}

void WebPreferences::setRemotePlaybackEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::remotePlaybackEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::remotePlaybackEnabledKey(), value, false);
}

bool WebPreferences::remotePlaybackEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::remotePlaybackEnabledKey());
}

void WebPreferences::deleteRemotePlaybackEnabled()
{
    deleteKey(WebPreferencesKey::remotePlaybackEnabledKey());
}

void WebPreferences::setRemoteSnapshottingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::remoteSnapshottingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::remoteSnapshottingEnabledKey(), value, true);
}

bool WebPreferences::remoteSnapshottingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::remoteSnapshottingEnabledKey());
}

void WebPreferences::deleteRemoteSnapshottingEnabled()
{
    deleteKey(WebPreferencesKey::remoteSnapshottingEnabledKey());
}

void WebPreferences::setRemoveBackgroundEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::removeBackgroundEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::removeBackgroundEnabledKey(), value, true);
}

bool WebPreferences::removeBackgroundEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::removeBackgroundEnabledKey());
}

void WebPreferences::deleteRemoveBackgroundEnabled()
{
    deleteKey(WebPreferencesKey::removeBackgroundEnabledKey());
}

void WebPreferences::setRequestVideoFrameCallbackEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requestVideoFrameCallbackEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requestVideoFrameCallbackEnabledKey(), value, false);
}

bool WebPreferences::requestVideoFrameCallbackEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requestVideoFrameCallbackEnabledKey());
}

void WebPreferences::deleteRequestVideoFrameCallbackEnabled()
{
    deleteKey(WebPreferencesKey::requestVideoFrameCallbackEnabledKey());
}

void WebPreferences::setRequireUAGetDisplayMediaPrompt(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requireUAGetDisplayMediaPromptKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requireUAGetDisplayMediaPromptKey(), value, true);
}

bool WebPreferences::requireUAGetDisplayMediaPrompt() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requireUAGetDisplayMediaPromptKey());
}

void WebPreferences::deleteRequireUAGetDisplayMediaPrompt()
{
    deleteKey(WebPreferencesKey::requireUAGetDisplayMediaPromptKey());
}

void WebPreferences::setLoginStatusAPIRequiresWebAuthnEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::loginStatusAPIRequiresWebAuthnEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::loginStatusAPIRequiresWebAuthnEnabledKey(), value, true);
}

bool WebPreferences::loginStatusAPIRequiresWebAuthnEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::loginStatusAPIRequiresWebAuthnEnabledKey());
}

void WebPreferences::deleteLoginStatusAPIRequiresWebAuthnEnabled()
{
    deleteKey(WebPreferencesKey::loginStatusAPIRequiresWebAuthnEnabledKey());
}

void WebPreferences::setSpeakerSelectionRequiresUserGesture(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::speakerSelectionRequiresUserGestureKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::speakerSelectionRequiresUserGestureKey(), value, true);
}

bool WebPreferences::speakerSelectionRequiresUserGesture() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::speakerSelectionRequiresUserGestureKey());
}

void WebPreferences::deleteSpeakerSelectionRequiresUserGesture()
{
    deleteKey(WebPreferencesKey::speakerSelectionRequiresUserGestureKey());
}

void WebPreferences::setFullscreenRequirementForScreenOrientationLockingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::fullscreenRequirementForScreenOrientationLockingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::fullscreenRequirementForScreenOrientationLockingEnabledKey(), value, false);
}

bool WebPreferences::fullscreenRequirementForScreenOrientationLockingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::fullscreenRequirementForScreenOrientationLockingEnabledKey());
}

void WebPreferences::deleteFullscreenRequirementForScreenOrientationLockingEnabled()
{
    deleteKey(WebPreferencesKey::fullscreenRequirementForScreenOrientationLockingEnabledKey());
}

void WebPreferences::setGetUserMediaRequiresFocus(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::getUserMediaRequiresFocusKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::getUserMediaRequiresFocusKey(), value, true);
}

bool WebPreferences::getUserMediaRequiresFocus() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::getUserMediaRequiresFocusKey());
}

void WebPreferences::deleteGetUserMediaRequiresFocus()
{
    deleteKey(WebPreferencesKey::getUserMediaRequiresFocusKey());
}

void WebPreferences::setResourceLoadSchedulingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::resourceLoadSchedulingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::resourceLoadSchedulingEnabledKey(), value, true);
}

bool WebPreferences::resourceLoadSchedulingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::resourceLoadSchedulingEnabledKey());
}

void WebPreferences::deleteResourceLoadSchedulingEnabled()
{
    deleteKey(WebPreferencesKey::resourceLoadSchedulingEnabledKey());
}

void WebPreferences::setResourceUsageOverlayVisible(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::resourceUsageOverlayVisibleKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::resourceUsageOverlayVisibleKey(), value, true);
}

bool WebPreferences::resourceUsageOverlayVisible() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::resourceUsageOverlayVisibleKey());
}

void WebPreferences::deleteResourceUsageOverlayVisible()
{
    deleteKey(WebPreferencesKey::resourceUsageOverlayVisibleKey());
}

void WebPreferences::setRespondToThermalPressureAggressively(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::respondToThermalPressureAggressivelyKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::respondToThermalPressureAggressivelyKey(), value, true);
}

bool WebPreferences::respondToThermalPressureAggressively() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::respondToThermalPressureAggressivelyKey());
}

void WebPreferences::deleteRespondToThermalPressureAggressively()
{
    deleteKey(WebPreferencesKey::respondToThermalPressureAggressivelyKey());
}

void WebPreferences::setSKAttributionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::sKAttributionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::sKAttributionEnabledKey(), value, false);
}

bool WebPreferences::sKAttributionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::sKAttributionEnabledKey());
}

void WebPreferences::deleteSKAttributionEnabled()
{
    deleteKey(WebPreferencesKey::sKAttributionEnabledKey());
}

void WebPreferences::setSafeBrowsingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::safeBrowsingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::safeBrowsingEnabledKey(), value, false);
}

bool WebPreferences::safeBrowsingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::safeBrowsingEnabledKey());
}

void WebPreferences::deleteSafeBrowsingEnabled()
{
    deleteKey(WebPreferencesKey::safeBrowsingEnabledKey());
}

void WebPreferences::setIsSameSiteStrictEnforcementEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isSameSiteStrictEnforcementEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isSameSiteStrictEnforcementEnabledKey(), value, true);
}

bool WebPreferences::isSameSiteStrictEnforcementEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isSameSiteStrictEnforcementEnabledKey());
}

void WebPreferences::deleteIsSameSiteStrictEnforcementEnabled()
{
    deleteKey(WebPreferencesKey::isSameSiteStrictEnforcementEnabledKey());
}

void WebPreferences::setScopedCustomElementRegistryEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scopedCustomElementRegistryEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scopedCustomElementRegistryEnabledKey(), value, false);
}

bool WebPreferences::scopedCustomElementRegistryEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scopedCustomElementRegistryEnabledKey());
}

void WebPreferences::deleteScopedCustomElementRegistryEnabled()
{
    deleteKey(WebPreferencesKey::scopedCustomElementRegistryEnabledKey());
}

void WebPreferences::setScreenOrientationLockingAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::screenOrientationLockingAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::screenOrientationLockingAPIEnabledKey(), value, true);
}

bool WebPreferences::screenOrientationLockingAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::screenOrientationLockingAPIEnabledKey());
}

void WebPreferences::deleteScreenOrientationLockingAPIEnabled()
{
    deleteKey(WebPreferencesKey::screenOrientationLockingAPIEnabledKey());
}

void WebPreferences::setScreenOrientationAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::screenOrientationAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::screenOrientationAPIEnabledKey(), value, false);
}

bool WebPreferences::screenOrientationAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::screenOrientationAPIEnabledKey());
}

void WebPreferences::deleteScreenOrientationAPIEnabled()
{
    deleteKey(WebPreferencesKey::screenOrientationAPIEnabledKey());
}

void WebPreferences::setScreenTimeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::screenTimeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::screenTimeEnabledKey(), value, true);
}

bool WebPreferences::screenTimeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::screenTimeEnabledKey());
}

void WebPreferences::deleteScreenTimeEnabled()
{
    deleteKey(WebPreferencesKey::screenTimeEnabledKey());
}

void WebPreferences::setScreenWakeLockAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::screenWakeLockAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::screenWakeLockAPIEnabledKey(), value, false);
}

bool WebPreferences::screenWakeLockAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::screenWakeLockAPIEnabledKey());
}

void WebPreferences::deleteScreenWakeLockAPIEnabled()
{
    deleteKey(WebPreferencesKey::screenWakeLockAPIEnabledKey());
}

void WebPreferences::setScreenCaptureEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::screenCaptureEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::screenCaptureEnabledKey(), value, false);
}

bool WebPreferences::screenCaptureEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::screenCaptureEnabledKey());
}

void WebPreferences::deleteScreenCaptureEnabled()
{
    deleteKey(WebPreferencesKey::screenCaptureEnabledKey());
}

void WebPreferences::setScriptTrackingPrivacyLoggingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scriptTrackingPrivacyLoggingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scriptTrackingPrivacyLoggingEnabledKey(), value, true);
}

bool WebPreferences::scriptTrackingPrivacyLoggingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scriptTrackingPrivacyLoggingEnabledKey());
}

void WebPreferences::deleteScriptTrackingPrivacyLoggingEnabled()
{
    deleteKey(WebPreferencesKey::scriptTrackingPrivacyLoggingEnabledKey());
}

void WebPreferences::setScriptTrackingPrivacyProtectionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scriptTrackingPrivacyProtectionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scriptTrackingPrivacyProtectionsEnabledKey(), value, true);
}

bool WebPreferences::scriptTrackingPrivacyProtectionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scriptTrackingPrivacyProtectionsEnabledKey());
}

void WebPreferences::deleteScriptTrackingPrivacyProtectionsEnabled()
{
    deleteKey(WebPreferencesKey::scriptTrackingPrivacyProtectionsEnabledKey());
}

void WebPreferences::setScrollingPerformanceTestingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollingPerformanceTestingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollingPerformanceTestingEnabledKey(), value, true);
}

bool WebPreferences::scrollingPerformanceTestingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollingPerformanceTestingEnabledKey());
}

void WebPreferences::deleteScrollingPerformanceTestingEnabled()
{
    deleteKey(WebPreferencesKey::scrollingPerformanceTestingEnabledKey());
}

void WebPreferences::setScrollToTextFragmentFeatureDetectionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollToTextFragmentFeatureDetectionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollToTextFragmentFeatureDetectionEnabledKey(), value, false);
}

bool WebPreferences::scrollToTextFragmentFeatureDetectionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentFeatureDetectionEnabledKey());
}

void WebPreferences::deleteScrollToTextFragmentFeatureDetectionEnabled()
{
    deleteKey(WebPreferencesKey::scrollToTextFragmentFeatureDetectionEnabledKey());
}

void WebPreferences::setScrollToTextFragmentGenerationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollToTextFragmentGenerationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollToTextFragmentGenerationEnabledKey(), value, false);
}

bool WebPreferences::scrollToTextFragmentGenerationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentGenerationEnabledKey());
}

void WebPreferences::deleteScrollToTextFragmentGenerationEnabled()
{
    deleteKey(WebPreferencesKey::scrollToTextFragmentGenerationEnabledKey());
}

void WebPreferences::setScrollToTextFragmentIndicatorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollToTextFragmentIndicatorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollToTextFragmentIndicatorEnabledKey(), value, false);
}

bool WebPreferences::scrollToTextFragmentIndicatorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentIndicatorEnabledKey());
}

void WebPreferences::deleteScrollToTextFragmentIndicatorEnabled()
{
    deleteKey(WebPreferencesKey::scrollToTextFragmentIndicatorEnabledKey());
}

void WebPreferences::setScrollToTextFragmentMarkingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollToTextFragmentMarkingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollToTextFragmentMarkingEnabledKey(), value, false);
}

bool WebPreferences::scrollToTextFragmentMarkingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentMarkingEnabledKey());
}

void WebPreferences::deleteScrollToTextFragmentMarkingEnabled()
{
    deleteKey(WebPreferencesKey::scrollToTextFragmentMarkingEnabledKey());
}

void WebPreferences::setScrollToTextFragmentEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollToTextFragmentEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollToTextFragmentEnabledKey(), value, false);
}

bool WebPreferences::scrollToTextFragmentEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollToTextFragmentEnabledKey());
}

void WebPreferences::deleteScrollToTextFragmentEnabled()
{
    deleteKey(WebPreferencesKey::scrollToTextFragmentEnabledKey());
}

void WebPreferences::setScrollAnimatorEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollAnimatorEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollAnimatorEnabledKey(), value, false);
}

bool WebPreferences::scrollAnimatorEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollAnimatorEnabledKey());
}

void WebPreferences::deleteScrollAnimatorEnabled()
{
    deleteKey(WebPreferencesKey::scrollAnimatorEnabledKey());
}

void WebPreferences::setScrollDrivenAnimationsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollDrivenAnimationsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollDrivenAnimationsEnabledKey(), value, false);
}

bool WebPreferences::scrollDrivenAnimationsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollDrivenAnimationsEnabledKey());
}

void WebPreferences::deleteScrollDrivenAnimationsEnabled()
{
    deleteKey(WebPreferencesKey::scrollDrivenAnimationsEnabledKey());
}

void WebPreferences::setSecureContextChecksEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::secureContextChecksEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::secureContextChecksEnabledKey(), value, true);
}

bool WebPreferences::secureContextChecksEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::secureContextChecksEnabledKey());
}

void WebPreferences::deleteSecureContextChecksEnabled()
{
    deleteKey(WebPreferencesKey::secureContextChecksEnabledKey());
}

void WebPreferences::setSelectionFlippingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::selectionFlippingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::selectionFlippingEnabledKey(), value, false);
}

bool WebPreferences::selectionFlippingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::selectionFlippingEnabledKey());
}

void WebPreferences::deleteSelectionFlippingEnabled()
{
    deleteKey(WebPreferencesKey::selectionFlippingEnabledKey());
}

void WebPreferences::setSelectionHonorsOverflowScrolling(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::selectionHonorsOverflowScrollingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::selectionHonorsOverflowScrollingKey(), value, true);
}

bool WebPreferences::selectionHonorsOverflowScrolling() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::selectionHonorsOverflowScrollingKey());
}

void WebPreferences::deleteSelectionHonorsOverflowScrolling()
{
    deleteKey(WebPreferencesKey::selectionHonorsOverflowScrollingKey());
}

void WebPreferences::setServiceWorkerInstallEventEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::serviceWorkerInstallEventEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::serviceWorkerInstallEventEnabledKey(), value, true);
}

bool WebPreferences::serviceWorkerInstallEventEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::serviceWorkerInstallEventEnabledKey());
}

void WebPreferences::deleteServiceWorkerInstallEventEnabled()
{
    deleteKey(WebPreferencesKey::serviceWorkerInstallEventEnabledKey());
}

void WebPreferences::setServiceWorkerNavigationPreloadEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::serviceWorkerNavigationPreloadEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::serviceWorkerNavigationPreloadEnabledKey(), value, false);
}

bool WebPreferences::serviceWorkerNavigationPreloadEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::serviceWorkerNavigationPreloadEnabledKey());
}

void WebPreferences::deleteServiceWorkerNavigationPreloadEnabled()
{
    deleteKey(WebPreferencesKey::serviceWorkerNavigationPreloadEnabledKey());
}

void WebPreferences::setServiceWorkersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::serviceWorkersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::serviceWorkersEnabledKey(), value, false);
}

bool WebPreferences::serviceWorkersEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::serviceWorkersEnabledKey());
}

void WebPreferences::deleteServiceWorkersEnabled()
{
    deleteKey(WebPreferencesKey::serviceWorkersEnabledKey());
}

void WebPreferences::setShapeDetection(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shapeDetectionKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shapeDetectionKey(), value, true);
}

bool WebPreferences::shapeDetection() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shapeDetectionKey());
}

void WebPreferences::deleteShapeDetection()
{
    deleteKey(WebPreferencesKey::shapeDetectionKey());
}

void WebPreferences::setSiteIsolationSharedProcessEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::siteIsolationSharedProcessEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::siteIsolationSharedProcessEnabledKey(), value, true);
}

bool WebPreferences::siteIsolationSharedProcessEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::siteIsolationSharedProcessEnabledKey());
}

void WebPreferences::deleteSiteIsolationSharedProcessEnabled()
{
    deleteKey(WebPreferencesKey::siteIsolationSharedProcessEnabledKey());
}

void WebPreferences::setSharedWorkerEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::sharedWorkerEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::sharedWorkerEnabledKey(), value, false);
}

bool WebPreferences::sharedWorkerEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::sharedWorkerEnabledKey());
}

void WebPreferences::deleteSharedWorkerEnabled()
{
    deleteKey(WebPreferencesKey::sharedWorkerEnabledKey());
}

void WebPreferences::setShowMediaStatsContextMenuItemEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::showMediaStatsContextMenuItemEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::showMediaStatsContextMenuItemEnabledKey(), value, false);
}

bool WebPreferences::showMediaStatsContextMenuItemEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::showMediaStatsContextMenuItemEnabledKey());
}

void WebPreferences::deleteShowMediaStatsContextMenuItemEnabled()
{
    deleteKey(WebPreferencesKey::showMediaStatsContextMenuItemEnabledKey());
}

void WebPreferences::setShowFrameProcessBordersEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::showFrameProcessBordersEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::showFrameProcessBordersEnabledKey(), value, true);
}

bool WebPreferences::showFrameProcessBordersEnabled() const
{
    if (m_showFrameProcessBordersEnabledInspectorOverride)
        return m_showFrameProcessBordersEnabledInspectorOverride.value();
    return m_store.getBoolValueForKey(WebPreferencesKey::showFrameProcessBordersEnabledKey());
}

void WebPreferences::deleteShowFrameProcessBordersEnabled()
{
    deleteKey(WebPreferencesKey::showFrameProcessBordersEnabledKey());
}

void WebPreferences::setSidewaysWritingModesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::sidewaysWritingModesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::sidewaysWritingModesEnabledKey(), value, false);
}

bool WebPreferences::sidewaysWritingModesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::sidewaysWritingModesEnabledKey());
}

void WebPreferences::deleteSidewaysWritingModesEnabled()
{
    deleteKey(WebPreferencesKey::sidewaysWritingModesEnabledKey());
}

void WebPreferences::setSiteIsolationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::siteIsolationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::siteIsolationEnabledKey(), value, true);
}

bool WebPreferences::siteIsolationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::siteIsolationEnabledKey());
}

void WebPreferences::deleteSiteIsolationEnabled()
{
    deleteKey(WebPreferencesKey::siteIsolationEnabledKey());
}

void WebPreferences::setSpatialImageControlsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::spatialImageControlsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::spatialImageControlsEnabledKey(), value, true);
}

bool WebPreferences::spatialImageControlsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::spatialImageControlsEnabledKey());
}

void WebPreferences::deleteSpatialImageControlsEnabled()
{
    deleteKey(WebPreferencesKey::spatialImageControlsEnabledKey());
}

void WebPreferences::setSpeechRecognitionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::speechRecognitionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::speechRecognitionEnabledKey(), value, false);
}

bool WebPreferences::speechRecognitionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::speechRecognitionEnabledKey());
}

void WebPreferences::deleteSpeechRecognitionEnabled()
{
    deleteKey(WebPreferencesKey::speechRecognitionEnabledKey());
}

void WebPreferences::setSpeechSynthesisAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::speechSynthesisAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::speechSynthesisAPIEnabledKey(), value, false);
}

bool WebPreferences::speechSynthesisAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::speechSynthesisAPIEnabledKey());
}

void WebPreferences::deleteSpeechSynthesisAPIEnabled()
{
    deleteKey(WebPreferencesKey::speechSynthesisAPIEnabledKey());
}

void WebPreferences::setStorageAPIEstimateEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::storageAPIEstimateEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::storageAPIEstimateEnabledKey(), value, false);
}

bool WebPreferences::storageAPIEstimateEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::storageAPIEstimateEnabledKey());
}

void WebPreferences::deleteStorageAPIEstimateEnabled()
{
    deleteKey(WebPreferencesKey::storageAPIEstimateEnabledKey());
}

void WebPreferences::setStorageAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::storageAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::storageAPIEnabledKey(), value, false);
}

bool WebPreferences::storageAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::storageAPIEnabledKey());
}

void WebPreferences::deleteStorageAPIEnabled()
{
    deleteKey(WebPreferencesKey::storageAPIEnabledKey());
}

void WebPreferences::setStorageBlockingPolicy(const uint32_t& value)
{
    if (!m_store.setUInt32ValueForKey(WebPreferencesKey::storageBlockingPolicyKey(), value))
        return;
    updateUInt32ValueForKey(WebPreferencesKey::storageBlockingPolicyKey(), value, false);
}

uint32_t WebPreferences::storageBlockingPolicy() const
{
    return m_store.getUInt32ValueForKey(WebPreferencesKey::storageBlockingPolicyKey());
}

void WebPreferences::deleteStorageBlockingPolicy()
{
    deleteKey(WebPreferencesKey::storageBlockingPolicyKey());
}

void WebPreferences::setSupportHDRCompositorTonemappingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::supportHDRCompositorTonemappingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::supportHDRCompositorTonemappingEnabledKey(), value, true);
}

bool WebPreferences::supportHDRCompositorTonemappingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::supportHDRCompositorTonemappingEnabledKey());
}

void WebPreferences::deleteSupportHDRCompositorTonemappingEnabled()
{
    deleteKey(WebPreferencesKey::supportHDRCompositorTonemappingEnabledKey());
}

void WebPreferences::setSupportHDRDisplayEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::supportHDRDisplayEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::supportHDRDisplayEnabledKey(), value, false);
}

bool WebPreferences::supportHDRDisplayEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::supportHDRDisplayEnabledKey());
}

void WebPreferences::deleteSupportHDRDisplayEnabled()
{
    deleteKey(WebPreferencesKey::supportHDRDisplayEnabledKey());
}

void WebPreferences::setProcessSwapOnCrossSiteNavigationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::processSwapOnCrossSiteNavigationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::processSwapOnCrossSiteNavigationEnabledKey(), value, false);
}

bool WebPreferences::processSwapOnCrossSiteNavigationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::processSwapOnCrossSiteNavigationEnabledKey());
}

void WebPreferences::deleteProcessSwapOnCrossSiteNavigationEnabled()
{
    deleteKey(WebPreferencesKey::processSwapOnCrossSiteNavigationEnabledKey());
}

void WebPreferences::setShouldTakeNearSuspendedAssertions(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shouldTakeNearSuspendedAssertionsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shouldTakeNearSuspendedAssertionsKey(), value, true);
}

bool WebPreferences::shouldTakeNearSuspendedAssertions() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shouldTakeNearSuspendedAssertionsKey());
}

void WebPreferences::deleteShouldTakeNearSuspendedAssertions()
{
    deleteKey(WebPreferencesKey::shouldTakeNearSuspendedAssertionsKey());
}

void WebPreferences::setTextAnimationsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::textAnimationsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::textAnimationsEnabledKey(), value, true);
}

bool WebPreferences::textAnimationsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::textAnimationsEnabledKey());
}

void WebPreferences::deleteTextAnimationsEnabled()
{
    deleteKey(WebPreferencesKey::textAnimationsEnabledKey());
}

void WebPreferences::setTextRecognitionInVideosEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::textRecognitionInVideosEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::textRecognitionInVideosEnabledKey(), value, true);
}

bool WebPreferences::textRecognitionInVideosEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::textRecognitionInVideosEnabledKey());
}

void WebPreferences::deleteTextRecognitionInVideosEnabled()
{
    deleteKey(WebPreferencesKey::textRecognitionInVideosEnabledKey());
}

void WebPreferences::setTextTracksInMSEEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::textTracksInMSEEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::textTracksInMSEEnabledKey(), value, true);
}

bool WebPreferences::textTracksInMSEEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::textTracksInMSEEnabledKey());
}

void WebPreferences::deleteTextTracksInMSEEnabled()
{
    deleteKey(WebPreferencesKey::textTracksInMSEEnabledKey());
}

void WebPreferences::setThreadedAnimationResolutionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::threadedAnimationResolutionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::threadedAnimationResolutionEnabledKey(), value, true);
}

bool WebPreferences::threadedAnimationResolutionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::threadedAnimationResolutionEnabledKey());
}

void WebPreferences::deleteThreadedAnimationResolutionEnabled()
{
    deleteKey(WebPreferencesKey::threadedAnimationResolutionEnabledKey());
}

void WebPreferences::setTiledScrollingIndicatorVisible(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::tiledScrollingIndicatorVisibleKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::tiledScrollingIndicatorVisibleKey(), value, true);
}

bool WebPreferences::tiledScrollingIndicatorVisible() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::tiledScrollingIndicatorVisibleKey());
}

void WebPreferences::deleteTiledScrollingIndicatorVisible()
{
    deleteKey(WebPreferencesKey::tiledScrollingIndicatorVisibleKey());
}

void WebPreferences::setInputTypeTimeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inputTypeTimeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inputTypeTimeEnabledKey(), value, false);
}

bool WebPreferences::inputTypeTimeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inputTypeTimeEnabledKey());
}

void WebPreferences::deleteInputTypeTimeEnabled()
{
    deleteKey(WebPreferencesKey::inputTypeTimeEnabledKey());
}

void WebPreferences::setTopContentInsetBackgroundCanChangeAfterScrolling(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::topContentInsetBackgroundCanChangeAfterScrollingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::topContentInsetBackgroundCanChangeAfterScrollingKey(), value, true);
}

bool WebPreferences::topContentInsetBackgroundCanChangeAfterScrolling() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::topContentInsetBackgroundCanChangeAfterScrollingKey());
}

void WebPreferences::deleteTopContentInsetBackgroundCanChangeAfterScrolling()
{
    deleteKey(WebPreferencesKey::topContentInsetBackgroundCanChangeAfterScrollingKey());
}

void WebPreferences::setTouchInputCompatibilityEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::touchInputCompatibilityEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::touchInputCompatibilityEnabledKey(), value, true);
}

bool WebPreferences::touchInputCompatibilityEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::touchInputCompatibilityEnabledKey());
}

void WebPreferences::deleteTouchInputCompatibilityEnabled()
{
    deleteKey(WebPreferencesKey::touchInputCompatibilityEnabledKey());
}

void WebPreferences::setTrackConfigurationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::trackConfigurationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::trackConfigurationEnabledKey(), value, true);
}

bool WebPreferences::trackConfigurationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::trackConfigurationEnabledKey());
}

void WebPreferences::deleteTrackConfigurationEnabled()
{
    deleteKey(WebPreferencesKey::trackConfigurationEnabledKey());
}

void WebPreferences::setTrustedTypesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::trustedTypesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::trustedTypesEnabledKey(), value, false);
}

bool WebPreferences::trustedTypesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::trustedTypesEnabledKey());
}

void WebPreferences::deleteTrustedTypesEnabled()
{
    deleteKey(WebPreferencesKey::trustedTypesEnabledKey());
}

void WebPreferences::setURLPatternAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::uRLPatternAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::uRLPatternAPIEnabledKey(), value, false);
}

bool WebPreferences::uRLPatternAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::uRLPatternAPIEnabledKey());
}

void WebPreferences::deleteURLPatternAPIEnabled()
{
    deleteKey(WebPreferencesKey::uRLPatternAPIEnabledKey());
}

void WebPreferences::setUndoManagerAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::undoManagerAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::undoManagerAPIEnabledKey(), value, true);
}

bool WebPreferences::undoManagerAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::undoManagerAPIEnabledKey());
}

void WebPreferences::deleteUndoManagerAPIEnabled()
{
    deleteKey(WebPreferencesKey::undoManagerAPIEnabledKey());
}

void WebPreferences::setUnifiedPDFEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::unifiedPDFEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::unifiedPDFEnabledKey(), value, false);
}

bool WebPreferences::unifiedPDFEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::unifiedPDFEnabledKey());
}

void WebPreferences::deleteUnifiedPDFEnabled()
{
    deleteKey(WebPreferencesKey::unifiedPDFEnabledKey());
}

void WebPreferences::setUnifyDamagedRegions(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::unifyDamagedRegionsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::unifyDamagedRegionsKey(), value, true);
}

bool WebPreferences::unifyDamagedRegions() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::unifyDamagedRegionsKey());
}

void WebPreferences::deleteUnifyDamagedRegions()
{
    deleteKey(WebPreferencesKey::unifyDamagedRegionsKey());
}

void WebPreferences::setIPAddressAndLocalhostMixedContentUpgradeTestingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::iPAddressAndLocalhostMixedContentUpgradeTestingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::iPAddressAndLocalhostMixedContentUpgradeTestingEnabledKey(), value, true);
}

bool WebPreferences::iPAddressAndLocalhostMixedContentUpgradeTestingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::iPAddressAndLocalhostMixedContentUpgradeTestingEnabledKey());
}

void WebPreferences::deleteIPAddressAndLocalhostMixedContentUpgradeTestingEnabled()
{
    deleteKey(WebPreferencesKey::iPAddressAndLocalhostMixedContentUpgradeTestingEnabledKey());
}

void WebPreferences::setUpgradeKnownHostsToHTTPSEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::upgradeKnownHostsToHTTPSEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::upgradeKnownHostsToHTTPSEnabledKey(), value, true);
}

bool WebPreferences::upgradeKnownHostsToHTTPSEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::upgradeKnownHostsToHTTPSEnabledKey());
}

void WebPreferences::deleteUpgradeKnownHostsToHTTPSEnabled()
{
    deleteKey(WebPreferencesKey::upgradeKnownHostsToHTTPSEnabledKey());
}

void WebPreferences::setUpgradeMixedContentEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::upgradeMixedContentEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::upgradeMixedContentEnabledKey(), value, false);
}

bool WebPreferences::upgradeMixedContentEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::upgradeMixedContentEnabledKey());
}

void WebPreferences::deleteUpgradeMixedContentEnabled()
{
    deleteKey(WebPreferencesKey::upgradeMixedContentEnabledKey());
}

void WebPreferences::setUseARKitForModel(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useARKitForModelKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useARKitForModelKey(), value, true);
}

bool WebPreferences::useARKitForModel() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useARKitForModelKey());
}

void WebPreferences::deleteUseARKitForModel()
{
    deleteKey(WebPreferencesKey::useARKitForModelKey());
}

void WebPreferences::setUseAVCaptureDeviceRotationCoordinatorAPI(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useAVCaptureDeviceRotationCoordinatorAPIKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useAVCaptureDeviceRotationCoordinatorAPIKey(), value, true);
}

bool WebPreferences::useAVCaptureDeviceRotationCoordinatorAPI() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useAVCaptureDeviceRotationCoordinatorAPIKey());
}

void WebPreferences::deleteUseAVCaptureDeviceRotationCoordinatorAPI()
{
    deleteKey(WebPreferencesKey::useAVCaptureDeviceRotationCoordinatorAPIKey());
}

void WebPreferences::setUseIFCForSVGText(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useIFCForSVGTextKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useIFCForSVGTextKey(), value, true);
}

bool WebPreferences::useIFCForSVGText() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useIFCForSVGTextKey());
}

void WebPreferences::deleteUseIFCForSVGText()
{
    deleteKey(WebPreferencesKey::useIFCForSVGTextKey());
}

void WebPreferences::setUseMicrophoneMuteStatusAPI(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useMicrophoneMuteStatusAPIKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useMicrophoneMuteStatusAPIKey(), value, true);
}

bool WebPreferences::useMicrophoneMuteStatusAPI() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useMicrophoneMuteStatusAPIKey());
}

void WebPreferences::deleteUseMicrophoneMuteStatusAPI()
{
    deleteKey(WebPreferencesKey::useMicrophoneMuteStatusAPIKey());
}

void WebPreferences::setUseSceneKitForModel(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useSceneKitForModelKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useSceneKitForModelKey(), value, true);
}

bool WebPreferences::useSceneKitForModel() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useSceneKitForModelKey());
}

void WebPreferences::deleteUseSceneKitForModel()
{
    deleteKey(WebPreferencesKey::useSceneKitForModelKey());
}

void WebPreferences::setUseGiantTiles(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useGiantTilesKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useGiantTilesKey(), value, false);
}

bool WebPreferences::useGiantTiles() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useGiantTilesKey());
}

void WebPreferences::deleteUseGiantTiles()
{
    deleteKey(WebPreferencesKey::useGiantTilesKey());
}

void WebPreferences::setUseDamagingInformationForCompositing(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::useDamagingInformationForCompositingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::useDamagingInformationForCompositingKey(), value, true);
}

bool WebPreferences::useDamagingInformationForCompositing() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::useDamagingInformationForCompositingKey());
}

void WebPreferences::deleteUseDamagingInformationForCompositing()
{
    deleteKey(WebPreferencesKey::useDamagingInformationForCompositingKey());
}

void WebPreferences::setUserActivationAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::userActivationAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::userActivationAPIEnabledKey(), value, false);
}

bool WebPreferences::userActivationAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::userActivationAPIEnabledKey());
}

void WebPreferences::deleteUserActivationAPIEnabled()
{
    deleteKey(WebPreferencesKey::userActivationAPIEnabledKey());
}

void WebPreferences::setUserGesturePromisePropagationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::userGesturePromisePropagationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::userGesturePromisePropagationEnabledKey(), value, true);
}

bool WebPreferences::userGesturePromisePropagationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::userGesturePromisePropagationEnabledKey());
}

void WebPreferences::deleteUserGesturePromisePropagationEnabled()
{
    deleteKey(WebPreferencesKey::userGesturePromisePropagationEnabledKey());
}

void WebPreferences::setUsesWebContentRestrictionsForFilter(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::usesWebContentRestrictionsForFilterKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::usesWebContentRestrictionsForFilterKey(), value, true);
}

bool WebPreferences::usesWebContentRestrictionsForFilter() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::usesWebContentRestrictionsForFilterKey());
}

void WebPreferences::deleteUsesWebContentRestrictionsForFilter()
{
    deleteKey(WebPreferencesKey::usesWebContentRestrictionsForFilterKey());
}

void WebPreferences::setServiceWorkersUserGestureEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::serviceWorkersUserGestureEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::serviceWorkersUserGestureEnabledKey(), value, true);
}

bool WebPreferences::serviceWorkersUserGestureEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::serviceWorkersUserGestureEnabledKey());
}

void WebPreferences::deleteServiceWorkersUserGestureEnabled()
{
    deleteKey(WebPreferencesKey::serviceWorkersUserGestureEnabledKey());
}

void WebPreferences::setVerifyWindowOpenUserGestureFromUIProcess(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::verifyWindowOpenUserGestureFromUIProcessKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::verifyWindowOpenUserGestureFromUIProcessKey(), value, true);
}

bool WebPreferences::verifyWindowOpenUserGestureFromUIProcess() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::verifyWindowOpenUserGestureFromUIProcessKey());
}

void WebPreferences::deleteVerifyWindowOpenUserGestureFromUIProcess()
{
    deleteKey(WebPreferencesKey::verifyWindowOpenUserGestureFromUIProcessKey());
}

void WebPreferences::setVerticalFormControlsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::verticalFormControlsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::verticalFormControlsEnabledKey(), value, false);
}

bool WebPreferences::verticalFormControlsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::verticalFormControlsEnabledKey());
}

void WebPreferences::deleteVerticalFormControlsEnabled()
{
    deleteKey(WebPreferencesKey::verticalFormControlsEnabledKey());
}

void WebPreferences::setVideoRendererProtectedFallbackDisabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::videoRendererProtectedFallbackDisabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::videoRendererProtectedFallbackDisabledKey(), value, false);
}

bool WebPreferences::videoRendererProtectedFallbackDisabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::videoRendererProtectedFallbackDisabledKey());
}

void WebPreferences::deleteVideoRendererProtectedFallbackDisabled()
{
    deleteKey(WebPreferencesKey::videoRendererProtectedFallbackDisabledKey());
}

void WebPreferences::setVideoRendererUseDecompressionSessionForProtected(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::videoRendererUseDecompressionSessionForProtectedKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::videoRendererUseDecompressionSessionForProtectedKey(), value, false);
}

bool WebPreferences::videoRendererUseDecompressionSessionForProtected() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::videoRendererUseDecompressionSessionForProtectedKey());
}

void WebPreferences::deleteVideoRendererUseDecompressionSessionForProtected()
{
    deleteKey(WebPreferencesKey::videoRendererUseDecompressionSessionForProtectedKey());
}

void WebPreferences::setViewTransitionClassesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::viewTransitionClassesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::viewTransitionClassesEnabledKey(), value, false);
}

bool WebPreferences::viewTransitionClassesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::viewTransitionClassesEnabledKey());
}

void WebPreferences::deleteViewTransitionClassesEnabled()
{
    deleteKey(WebPreferencesKey::viewTransitionClassesEnabledKey());
}

void WebPreferences::setViewTransitionTypesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::viewTransitionTypesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::viewTransitionTypesEnabledKey(), value, false);
}

bool WebPreferences::viewTransitionTypesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::viewTransitionTypesEnabledKey());
}

void WebPreferences::deleteViewTransitionTypesEnabled()
{
    deleteKey(WebPreferencesKey::viewTransitionTypesEnabledKey());
}

void WebPreferences::setViewTransitionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::viewTransitionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::viewTransitionsEnabledKey(), value, false);
}

bool WebPreferences::viewTransitionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::viewTransitionsEnabledKey());
}

void WebPreferences::deleteViewTransitionsEnabled()
{
    deleteKey(WebPreferencesKey::viewTransitionsEnabledKey());
}

void WebPreferences::setViewGestureDebuggingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::viewGestureDebuggingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::viewGestureDebuggingEnabledKey(), value, false);
}

bool WebPreferences::viewGestureDebuggingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::viewGestureDebuggingEnabledKey());
}

void WebPreferences::deleteViewGestureDebuggingEnabled()
{
    deleteKey(WebPreferencesKey::viewGestureDebuggingEnabledKey());
}

void WebPreferences::setVisualTranslationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::visualTranslationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::visualTranslationEnabledKey(), value, true);
}

bool WebPreferences::visualTranslationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::visualTranslationEnabledKey());
}

void WebPreferences::deleteVisualTranslationEnabled()
{
    deleteKey(WebPreferencesKey::visualTranslationEnabledKey());
}

void WebPreferences::setVisualViewportAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::visualViewportAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::visualViewportAPIEnabledKey(), value, false);
}

bool WebPreferences::visualViewportAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::visualViewportAPIEnabledKey());
}

void WebPreferences::deleteVisualViewportAPIEnabled()
{
    deleteKey(WebPreferencesKey::visualViewportAPIEnabledKey());
}

void WebPreferences::setVisuallyContiguousBidiTextSelectionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::visuallyContiguousBidiTextSelectionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::visuallyContiguousBidiTextSelectionEnabledKey(), value, true);
}

bool WebPreferences::visuallyContiguousBidiTextSelectionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::visuallyContiguousBidiTextSelectionEnabledKey());
}

void WebPreferences::deleteVisuallyContiguousBidiTextSelectionEnabled()
{
    deleteKey(WebPreferencesKey::visuallyContiguousBidiTextSelectionEnabledKey());
}

void WebPreferences::setWebAPIStatisticsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAPIStatisticsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAPIStatisticsEnabledKey(), value, true);
}

bool WebPreferences::webAPIStatisticsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAPIStatisticsEnabledKey());
}

void WebPreferences::deleteWebAPIStatisticsEnabled()
{
    deleteKey(WebPreferencesKey::webAPIStatisticsEnabledKey());
}

void WebPreferences::setWebAPIsInShadowRealmEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAPIsInShadowRealmEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAPIsInShadowRealmEnabledKey(), value, true);
}

bool WebPreferences::webAPIsInShadowRealmEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAPIsInShadowRealmEnabledKey());
}

void WebPreferences::deleteWebAPIsInShadowRealmEnabled()
{
    deleteKey(WebPreferencesKey::webAPIsInShadowRealmEnabledKey());
}

void WebPreferences::setWebAnimationsOverallProgressPropertyEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAnimationsOverallProgressPropertyEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAnimationsOverallProgressPropertyEnabledKey(), value, false);
}

bool WebPreferences::webAnimationsOverallProgressPropertyEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAnimationsOverallProgressPropertyEnabledKey());
}

void WebPreferences::deleteWebAnimationsOverallProgressPropertyEnabled()
{
    deleteKey(WebPreferencesKey::webAnimationsOverallProgressPropertyEnabledKey());
}

void WebPreferences::setWebAnimationsCustomEffectsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAnimationsCustomEffectsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAnimationsCustomEffectsEnabledKey(), value, true);
}

bool WebPreferences::webAnimationsCustomEffectsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAnimationsCustomEffectsEnabledKey());
}

void WebPreferences::deleteWebAnimationsCustomEffectsEnabled()
{
    deleteKey(WebPreferencesKey::webAnimationsCustomEffectsEnabledKey());
}

void WebPreferences::setWebAnimationsCustomFrameRateEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAnimationsCustomFrameRateEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAnimationsCustomFrameRateEnabledKey(), value, true);
}

bool WebPreferences::webAnimationsCustomFrameRateEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAnimationsCustomFrameRateEnabledKey());
}

void WebPreferences::deleteWebAnimationsCustomFrameRateEnabled()
{
    deleteKey(WebPreferencesKey::webAnimationsCustomFrameRateEnabledKey());
}

void WebPreferences::setWebArchiveDebugModeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webArchiveDebugModeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webArchiveDebugModeEnabledKey(), value, false);
}

bool WebPreferences::webArchiveDebugModeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webArchiveDebugModeEnabledKey());
}

void WebPreferences::deleteWebArchiveDebugModeEnabled()
{
    deleteKey(WebPreferencesKey::webArchiveDebugModeEnabledKey());
}

void WebPreferences::setWebArchiveTestingModeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webArchiveTestingModeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webArchiveTestingModeEnabledKey(), value, true);
}

bool WebPreferences::webArchiveTestingModeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webArchiveTestingModeEnabledKey());
}

void WebPreferences::deleteWebArchiveTestingModeEnabled()
{
    deleteKey(WebPreferencesKey::webArchiveTestingModeEnabledKey());
}

void WebPreferences::setWebAuthenticationASEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAuthenticationASEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAuthenticationASEnabledKey(), value, false);
}

bool WebPreferences::webAuthenticationASEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAuthenticationASEnabledKey());
}

void WebPreferences::deleteWebAuthenticationASEnabled()
{
    deleteKey(WebPreferencesKey::webAuthenticationASEnabledKey());
}

void WebPreferences::setWebAuthenticationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAuthenticationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAuthenticationEnabledKey(), value, false);
}

bool WebPreferences::webAuthenticationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAuthenticationEnabledKey());
}

void WebPreferences::deleteWebAuthenticationEnabled()
{
    deleteKey(WebPreferencesKey::webAuthenticationEnabledKey());
}

void WebPreferences::setWebCryptoSafeCurvesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webCryptoSafeCurvesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webCryptoSafeCurvesEnabledKey(), value, false);
}

bool WebPreferences::webCryptoSafeCurvesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webCryptoSafeCurvesEnabledKey());
}

void WebPreferences::deleteWebCryptoSafeCurvesEnabled()
{
    deleteKey(WebPreferencesKey::webCryptoSafeCurvesEnabledKey());
}

void WebPreferences::setWebCryptoX25519Enabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webCryptoX25519EnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webCryptoX25519EnabledKey(), value, false);
}

bool WebPreferences::webCryptoX25519Enabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webCryptoX25519EnabledKey());
}

void WebPreferences::deleteWebCryptoX25519Enabled()
{
    deleteKey(WebPreferencesKey::webCryptoX25519EnabledKey());
}

void WebPreferences::setWebLocksAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webLocksAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webLocksAPIEnabledKey(), value, false);
}

bool WebPreferences::webLocksAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webLocksAPIEnabledKey());
}

void WebPreferences::deleteWebLocksAPIEnabled()
{
    deleteKey(WebPreferencesKey::webLocksAPIEnabledKey());
}

void WebPreferences::setWebShareFileAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webShareFileAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webShareFileAPIEnabledKey(), value, false);
}

bool WebPreferences::webShareFileAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webShareFileAPIEnabledKey());
}

void WebPreferences::deleteWebShareFileAPIEnabled()
{
    deleteKey(WebPreferencesKey::webShareFileAPIEnabledKey());
}

void WebPreferences::setWebShareEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webShareEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webShareEnabledKey(), value, false);
}

bool WebPreferences::webShareEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webShareEnabledKey());
}

void WebPreferences::deleteWebShareEnabled()
{
    deleteKey(WebPreferencesKey::webShareEnabledKey());
}

void WebPreferences::setWebAssemblyESMIntegrationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webAssemblyESMIntegrationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webAssemblyESMIntegrationEnabledKey(), value, true);
}

bool WebPreferences::webAssemblyESMIntegrationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webAssemblyESMIntegrationEnabledKey());
}

void WebPreferences::deleteWebAssemblyESMIntegrationEnabled()
{
    deleteKey(WebPreferencesKey::webAssemblyESMIntegrationEnabledKey());
}

void WebPreferences::setWebCodecsAV1Enabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webCodecsAV1EnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webCodecsAV1EnabledKey(), value, false);
}

bool WebPreferences::webCodecsAV1Enabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webCodecsAV1EnabledKey());
}

void WebPreferences::deleteWebCodecsAV1Enabled()
{
    deleteKey(WebPreferencesKey::webCodecsAV1EnabledKey());
}

void WebPreferences::setWebCodecsAudioEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webCodecsAudioEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webCodecsAudioEnabledKey(), value, false);
}

bool WebPreferences::webCodecsAudioEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webCodecsAudioEnabledKey());
}

void WebPreferences::deleteWebCodecsAudioEnabled()
{
    deleteKey(WebPreferencesKey::webCodecsAudioEnabledKey());
}

void WebPreferences::setWebCodecsHEVCEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webCodecsHEVCEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webCodecsHEVCEnabledKey(), value, false);
}

bool WebPreferences::webCodecsHEVCEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webCodecsHEVCEnabledKey());
}

void WebPreferences::deleteWebCodecsHEVCEnabled()
{
    deleteKey(WebPreferencesKey::webCodecsHEVCEnabledKey());
}

void WebPreferences::setWebCodecsVideoEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webCodecsVideoEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webCodecsVideoEnabledKey(), value, false);
}

bool WebPreferences::webCodecsVideoEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webCodecsVideoEnabledKey());
}

void WebPreferences::deleteWebCodecsVideoEnabled()
{
    deleteKey(WebPreferencesKey::webCodecsVideoEnabledKey());
}

void WebPreferences::setWebExtensionBookmarksEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webExtensionBookmarksEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webExtensionBookmarksEnabledKey(), value, true);
}

bool WebPreferences::webExtensionBookmarksEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webExtensionBookmarksEnabledKey());
}

void WebPreferences::deleteWebExtensionBookmarksEnabled()
{
    deleteKey(WebPreferencesKey::webExtensionBookmarksEnabledKey());
}

void WebPreferences::setWebExtensionSidebarEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webExtensionSidebarEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webExtensionSidebarEnabledKey(), value, true);
}

bool WebPreferences::webExtensionSidebarEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webExtensionSidebarEnabledKey());
}

void WebPreferences::deleteWebExtensionSidebarEnabled()
{
    deleteKey(WebPreferencesKey::webExtensionSidebarEnabledKey());
}

void WebPreferences::setWebGLDraftExtensionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webGLDraftExtensionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webGLDraftExtensionsEnabledKey(), value, true);
}

bool WebPreferences::webGLDraftExtensionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webGLDraftExtensionsEnabledKey());
}

void WebPreferences::deleteWebGLDraftExtensionsEnabled()
{
    deleteKey(WebPreferencesKey::webGLDraftExtensionsEnabledKey());
}

void WebPreferences::setWebGLTimerQueriesEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webGLTimerQueriesEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webGLTimerQueriesEnabledKey(), value, false);
}

bool WebPreferences::webGLTimerQueriesEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webGLTimerQueriesEnabledKey());
}

void WebPreferences::deleteWebGLTimerQueriesEnabled()
{
    deleteKey(WebPreferencesKey::webGLTimerQueriesEnabledKey());
}

void WebPreferences::setWebGLEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webGLEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webGLEnabledKey(), value, false);
}

bool WebPreferences::webGLEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webGLEnabledKey());
}

void WebPreferences::deleteWebGLEnabled()
{
    deleteKey(WebPreferencesKey::webGLEnabledKey());
}

void WebPreferences::setWebGPUHDREnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webGPUHDREnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webGPUHDREnabledKey(), value, false);
}

bool WebPreferences::webGPUHDREnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webGPUHDREnabledKey());
}

void WebPreferences::deleteWebGPUHDREnabled()
{
    deleteKey(WebPreferencesKey::webGPUHDREnabledKey());
}

void WebPreferences::setWebXRWebGPUBindingsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webXRWebGPUBindingsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webXRWebGPUBindingsEnabledKey(), value, false);
}

bool WebPreferences::webXRWebGPUBindingsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webXRWebGPUBindingsEnabledKey());
}

void WebPreferences::deleteWebXRWebGPUBindingsEnabled()
{
    deleteKey(WebPreferencesKey::webXRWebGPUBindingsEnabledKey());
}

void WebPreferences::setWebGPUEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webGPUEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webGPUEnabledKey(), value, false);
}

bool WebPreferences::webGPUEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webGPUEnabledKey());
}

void WebPreferences::deleteWebGPUEnabled()
{
    deleteKey(WebPreferencesKey::webGPUEnabledKey());
}

void WebPreferences::setWebInspectorEngineeringSettingsAllowed(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webInspectorEngineeringSettingsAllowedKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webInspectorEngineeringSettingsAllowedKey(), value, true);
}

bool WebPreferences::webInspectorEngineeringSettingsAllowed() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webInspectorEngineeringSettingsAllowedKey());
}

void WebPreferences::deleteWebInspectorEngineeringSettingsAllowed()
{
    deleteKey(WebPreferencesKey::webInspectorEngineeringSettingsAllowedKey());
}

void WebPreferences::setWebRTCAV1CodecEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCAV1CodecEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCAV1CodecEnabledKey(), value, false);
}

bool WebPreferences::webRTCAV1CodecEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCAV1CodecEnabledKey());
}

void WebPreferences::deleteWebRTCAV1CodecEnabled()
{
    deleteKey(WebPreferencesKey::webRTCAV1CodecEnabledKey());
}

void WebPreferences::setWebRTCAudioLatencyAdaptationEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCAudioLatencyAdaptationEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCAudioLatencyAdaptationEnabledKey(), value, true);
}

bool WebPreferences::webRTCAudioLatencyAdaptationEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCAudioLatencyAdaptationEnabledKey());
}

void WebPreferences::deleteWebRTCAudioLatencyAdaptationEnabled()
{
    deleteKey(WebPreferencesKey::webRTCAudioLatencyAdaptationEnabledKey());
}

void WebPreferences::setWebRTCDTMFEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCDTMFEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCDTMFEnabledKey(), value, true);
}

bool WebPreferences::webRTCDTMFEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCDTMFEnabledKey());
}

void WebPreferences::deleteWebRTCDTMFEnabled()
{
    deleteKey(WebPreferencesKey::webRTCDTMFEnabledKey());
}

void WebPreferences::setWebRTCEncodedTransformEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCEncodedTransformEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCEncodedTransformEnabledKey(), value, false);
}

bool WebPreferences::webRTCEncodedTransformEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCEncodedTransformEnabledKey());
}

void WebPreferences::deleteWebRTCEncodedTransformEnabled()
{
    deleteKey(WebPreferencesKey::webRTCEncodedTransformEnabledKey());
}

void WebPreferences::setWebRTCH264HardwareEncoderEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCH264HardwareEncoderEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCH264HardwareEncoderEnabledKey(), value, true);
}

bool WebPreferences::webRTCH264HardwareEncoderEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCH264HardwareEncoderEnabledKey());
}

void WebPreferences::deleteWebRTCH264HardwareEncoderEnabled()
{
    deleteKey(WebPreferencesKey::webRTCH264HardwareEncoderEnabledKey());
}

void WebPreferences::setWebRTCH265CodecEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCH265CodecEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCH265CodecEnabledKey(), value, false);
}

bool WebPreferences::webRTCH265CodecEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCH265CodecEnabledKey());
}

void WebPreferences::deleteWebRTCH265CodecEnabled()
{
    deleteKey(WebPreferencesKey::webRTCH265CodecEnabledKey());
}

void WebPreferences::setWebRTCL4SEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCL4SEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCL4SEnabledKey(), value, true);
}

bool WebPreferences::webRTCL4SEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCL4SEnabledKey());
}

void WebPreferences::deleteWebRTCL4SEnabled()
{
    deleteKey(WebPreferencesKey::webRTCL4SEnabledKey());
}

void WebPreferences::setWebRTCMediaPipelineAdditionalLoggingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCMediaPipelineAdditionalLoggingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCMediaPipelineAdditionalLoggingEnabledKey(), value, true);
}

bool WebPreferences::webRTCMediaPipelineAdditionalLoggingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCMediaPipelineAdditionalLoggingEnabledKey());
}

void WebPreferences::deleteWebRTCMediaPipelineAdditionalLoggingEnabled()
{
    deleteKey(WebPreferencesKey::webRTCMediaPipelineAdditionalLoggingEnabledKey());
}

void WebPreferences::setLegacyWebRTCOfferOptionsEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::legacyWebRTCOfferOptionsEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::legacyWebRTCOfferOptionsEnabledKey(), value, false);
}

bool WebPreferences::legacyWebRTCOfferOptionsEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::legacyWebRTCOfferOptionsEnabledKey());
}

void WebPreferences::deleteLegacyWebRTCOfferOptionsEnabled()
{
    deleteKey(WebPreferencesKey::legacyWebRTCOfferOptionsEnabledKey());
}

void WebPreferences::setPeerConnectionVideoScalingAdaptationDisabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::peerConnectionVideoScalingAdaptationDisabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::peerConnectionVideoScalingAdaptationDisabledKey(), value, false);
}

bool WebPreferences::peerConnectionVideoScalingAdaptationDisabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::peerConnectionVideoScalingAdaptationDisabledKey());
}

void WebPreferences::deletePeerConnectionVideoScalingAdaptationDisabled()
{
    deleteKey(WebPreferencesKey::peerConnectionVideoScalingAdaptationDisabledKey());
}

void WebPreferences::setPeerConnectionEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::peerConnectionEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::peerConnectionEnabledKey(), value, false);
}

bool WebPreferences::peerConnectionEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::peerConnectionEnabledKey());
}

void WebPreferences::deletePeerConnectionEnabled()
{
    deleteKey(WebPreferencesKey::peerConnectionEnabledKey());
}

void WebPreferences::setWebRTCRemoteVideoFrameEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCRemoteVideoFrameEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCRemoteVideoFrameEnabledKey(), value, true);
}

bool WebPreferences::webRTCRemoteVideoFrameEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCRemoteVideoFrameEnabledKey());
}

void WebPreferences::deleteWebRTCRemoteVideoFrameEnabled()
{
    deleteKey(WebPreferencesKey::webRTCRemoteVideoFrameEnabledKey());
}

void WebPreferences::setWebRTCSFrameTransformEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCSFrameTransformEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCSFrameTransformEnabledKey(), value, true);
}

bool WebPreferences::webRTCSFrameTransformEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCSFrameTransformEnabledKey());
}

void WebPreferences::deleteWebRTCSFrameTransformEnabled()
{
    deleteKey(WebPreferencesKey::webRTCSFrameTransformEnabledKey());
}

void WebPreferences::setWebRTCSocketsProxyingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCSocketsProxyingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCSocketsProxyingEnabledKey(), value, true);
}

bool WebPreferences::webRTCSocketsProxyingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCSocketsProxyingEnabledKey());
}

void WebPreferences::deleteWebRTCSocketsProxyingEnabled()
{
    deleteKey(WebPreferencesKey::webRTCSocketsProxyingEnabledKey());
}

void WebPreferences::setWebRTCUDPPortRange(const String& value)
{
    if (!m_store.setStringValueForKey(WebPreferencesKey::webRTCUDPPortRangeKey(), value))
        return;
    updateStringValueForKey(WebPreferencesKey::webRTCUDPPortRangeKey(), value, false);
}

String WebPreferences::webRTCUDPPortRange() const
{
    return m_store.getStringValueForKey(WebPreferencesKey::webRTCUDPPortRangeKey());
}

void WebPreferences::deleteWebRTCUDPPortRange()
{
    deleteKey(WebPreferencesKey::webRTCUDPPortRangeKey());
}

void WebPreferences::setWebRTCVP9Profile0CodecEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCVP9Profile0CodecEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCVP9Profile0CodecEnabledKey(), value, true);
}

bool WebPreferences::webRTCVP9Profile0CodecEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCVP9Profile0CodecEnabledKey());
}

void WebPreferences::deleteWebRTCVP9Profile0CodecEnabled()
{
    deleteKey(WebPreferencesKey::webRTCVP9Profile0CodecEnabledKey());
}

void WebPreferences::setWebRTCVP9Profile2CodecEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCVP9Profile2CodecEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCVP9Profile2CodecEnabledKey(), value, false);
}

bool WebPreferences::webRTCVP9Profile2CodecEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCVP9Profile2CodecEnabledKey());
}

void WebPreferences::deleteWebRTCVP9Profile2CodecEnabled()
{
    deleteKey(WebPreferencesKey::webRTCVP9Profile2CodecEnabledKey());
}

void WebPreferences::setWebRTCInterfaceMonitoringViaNWEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webRTCInterfaceMonitoringViaNWEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webRTCInterfaceMonitoringViaNWEnabledKey(), value, true);
}

bool WebPreferences::webRTCInterfaceMonitoringViaNWEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webRTCInterfaceMonitoringViaNWEnabledKey());
}

void WebPreferences::deleteWebRTCInterfaceMonitoringViaNWEnabled()
{
    deleteKey(WebPreferencesKey::webRTCInterfaceMonitoringViaNWEnabledKey());
}

void WebPreferences::setWebTransportEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webTransportEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webTransportEnabledKey(), value, true);
}

bool WebPreferences::webTransportEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webTransportEnabledKey());
}

void WebPreferences::deleteWebTransportEnabled()
{
    deleteKey(WebPreferencesKey::webTransportEnabledKey());
}

void WebPreferences::setWebXRAugmentedRealityModuleEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webXRAugmentedRealityModuleEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webXRAugmentedRealityModuleEnabledKey(), value, true);
}

bool WebPreferences::webXRAugmentedRealityModuleEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webXRAugmentedRealityModuleEnabledKey());
}

void WebPreferences::deleteWebXRAugmentedRealityModuleEnabled()
{
    deleteKey(WebPreferencesKey::webXRAugmentedRealityModuleEnabledKey());
}

void WebPreferences::setWebXREnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webXREnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webXREnabledKey(), value, false);
}

bool WebPreferences::webXREnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webXREnabledKey());
}

void WebPreferences::deleteWebXREnabled()
{
    deleteKey(WebPreferencesKey::webXREnabledKey());
}

void WebPreferences::setWebXRGamepadsModuleEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webXRGamepadsModuleEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webXRGamepadsModuleEnabledKey(), value, false);
}

bool WebPreferences::webXRGamepadsModuleEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webXRGamepadsModuleEnabledKey());
}

void WebPreferences::deleteWebXRGamepadsModuleEnabled()
{
    deleteKey(WebPreferencesKey::webXRGamepadsModuleEnabledKey());
}

void WebPreferences::setWebXRHandInputModuleEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webXRHandInputModuleEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webXRHandInputModuleEnabledKey(), value, false);
}

bool WebPreferences::webXRHandInputModuleEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webXRHandInputModuleEnabledKey());
}

void WebPreferences::deleteWebXRHandInputModuleEnabled()
{
    deleteKey(WebPreferencesKey::webXRHandInputModuleEnabledKey());
}

void WebPreferences::setWebXRLayersAPIEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webXRLayersAPIEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webXRLayersAPIEnabledKey(), value, false);
}

bool WebPreferences::webXRLayersAPIEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webXRLayersAPIEnabledKey());
}

void WebPreferences::deleteWebXRLayersAPIEnabled()
{
    deleteKey(WebPreferencesKey::webXRLayersAPIEnabledKey());
}

void WebPreferences::setWebPageSpatialBackdropEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::webPageSpatialBackdropEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::webPageSpatialBackdropEnabledKey(), value, true);
}

bool WebPreferences::webPageSpatialBackdropEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::webPageSpatialBackdropEnabledKey());
}

void WebPreferences::deleteWebPageSpatialBackdropEnabled()
{
    deleteKey(WebPreferencesKey::webPageSpatialBackdropEnabledKey());
}

void WebPreferences::setInputTypeWeekEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inputTypeWeekEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inputTypeWeekEnabledKey(), value, false);
}

bool WebPreferences::inputTypeWeekEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inputTypeWeekEnabledKey());
}

void WebPreferences::deleteInputTypeWeekEnabled()
{
    deleteKey(WebPreferencesKey::inputTypeWeekEnabledKey());
}

void WebPreferences::setWheelEventGesturesBecomeNonBlocking(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::wheelEventGesturesBecomeNonBlockingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::wheelEventGesturesBecomeNonBlockingKey(), value, false);
}

bool WebPreferences::wheelEventGesturesBecomeNonBlocking() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::wheelEventGesturesBecomeNonBlockingKey());
}

void WebPreferences::deleteWheelEventGesturesBecomeNonBlocking()
{
    deleteKey(WebPreferencesKey::wheelEventGesturesBecomeNonBlockingKey());
}

void WebPreferences::setPassiveWheelListenersAsDefaultOnDocument(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::passiveWheelListenersAsDefaultOnDocumentKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::passiveWheelListenersAsDefaultOnDocumentKey(), value, false);
}

bool WebPreferences::passiveWheelListenersAsDefaultOnDocument() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::passiveWheelListenersAsDefaultOnDocumentKey());
}

void WebPreferences::deletePassiveWheelListenersAsDefaultOnDocument()
{
    deleteKey(WebPreferencesKey::passiveWheelListenersAsDefaultOnDocumentKey());
}

void WebPreferences::setWorkerAsynchronousURLErrorHandlingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::workerAsynchronousURLErrorHandlingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::workerAsynchronousURLErrorHandlingEnabledKey(), value, false);
}

bool WebPreferences::workerAsynchronousURLErrorHandlingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::workerAsynchronousURLErrorHandlingEnabledKey());
}

void WebPreferences::deleteWorkerAsynchronousURLErrorHandlingEnabled()
{
    deleteKey(WebPreferencesKey::workerAsynchronousURLErrorHandlingEnabledKey());
}

void WebPreferences::setWriteRichTextDataWhenCopyingOrDragging(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::writeRichTextDataWhenCopyingOrDraggingKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::writeRichTextDataWhenCopyingOrDraggingKey(), value, true);
}

bool WebPreferences::writeRichTextDataWhenCopyingOrDragging() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::writeRichTextDataWhenCopyingOrDraggingKey());
}

void WebPreferences::deleteWriteRichTextDataWhenCopyingOrDragging()
{
    deleteKey(WebPreferencesKey::writeRichTextDataWhenCopyingOrDraggingKey());
}

void WebPreferences::setWritingSuggestionsAttributeEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::writingSuggestionsAttributeEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::writingSuggestionsAttributeEnabledKey(), value, false);
}

bool WebPreferences::writingSuggestionsAttributeEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::writingSuggestionsAttributeEnabledKey());
}

void WebPreferences::deleteWritingSuggestionsAttributeEnabled()
{
    deleteKey(WebPreferencesKey::writingSuggestionsAttributeEnabledKey());
}

void WebPreferences::setXSLTEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::xSLTEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::xSLTEnabledKey(), value, true);
}

bool WebPreferences::xSLTEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::xSLTEnabledKey());
}

void WebPreferences::deleteXSLTEnabled()
{
    deleteKey(WebPreferencesKey::xSLTEnabledKey());
}

void WebPreferences::setIsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalLiveOnTestingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalLiveOnTestingEnabledKey(), value, false);
}

bool WebPreferences::isFirstPartyWebsiteDataRemovalLiveOnTestingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalLiveOnTestingEnabledKey());
}

void WebPreferences::deleteIsFirstPartyWebsiteDataRemovalLiveOnTestingEnabled()
{
    deleteKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalLiveOnTestingEnabledKey());
}

void WebPreferences::setIsFirstPartyWebsiteDataRemovalReproTestingEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalReproTestingEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalReproTestingEnabledKey(), value, false);
}

bool WebPreferences::isFirstPartyWebsiteDataRemovalReproTestingEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalReproTestingEnabledKey());
}

void WebPreferences::deleteIsFirstPartyWebsiteDataRemovalReproTestingEnabled()
{
    deleteKey(WebPreferencesKey::isFirstPartyWebsiteDataRemovalReproTestingEnabledKey());
}

void WebPreferences::setAltitudeAngleEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::altitudeAngleEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::altitudeAngleEnabledKey(), value, false);
}

bool WebPreferences::altitudeAngleEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::altitudeAngleEnabledKey());
}

void WebPreferences::deleteAltitudeAngleEnabled()
{
    deleteKey(WebPreferencesKey::altitudeAngleEnabledKey());
}

void WebPreferences::setAzimuthAngleEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::azimuthAngleEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::azimuthAngleEnabledKey(), value, false);
}

bool WebPreferences::azimuthAngleEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::azimuthAngleEnabledKey());
}

void WebPreferences::deleteAzimuthAngleEnabled()
{
    deleteKey(WebPreferencesKey::azimuthAngleEnabledKey());
}

void WebPreferences::setInputTypeDateTimeLocalEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::inputTypeDateTimeLocalEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::inputTypeDateTimeLocalEnabledKey(), value, false);
}

bool WebPreferences::inputTypeDateTimeLocalEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::inputTypeDateTimeLocalEnabledKey());
}

void WebPreferences::deleteInputTypeDateTimeLocalEnabled()
{
    deleteKey(WebPreferencesKey::inputTypeDateTimeLocalEnabledKey());
}

void WebPreferences::setCaretPositionFromPointEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::caretPositionFromPointEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::caretPositionFromPointEnabledKey(), value, true);
}

bool WebPreferences::caretPositionFromPointEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::caretPositionFromPointEnabledKey());
}

void WebPreferences::deleteCaretPositionFromPointEnabled()
{
    deleteKey(WebPreferencesKey::caretPositionFromPointEnabledKey());
}

void WebPreferences::setHiddenUntilFoundEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::hiddenUntilFoundEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::hiddenUntilFoundEnabledKey(), value, false);
}

bool WebPreferences::hiddenUntilFoundEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::hiddenUntilFoundEnabledKey());
}

void WebPreferences::deleteHiddenUntilFoundEnabled()
{
    deleteKey(WebPreferencesKey::hiddenUntilFoundEnabledKey());
}

void WebPreferences::setHTTPEquivEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::httpEquivEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::httpEquivEnabledKey(), value, false);
}

bool WebPreferences::httpEquivEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::httpEquivEnabledKey());
}

void WebPreferences::deleteHTTPEquivEnabled()
{
    deleteKey(WebPreferencesKey::httpEquivEnabledKey());
}

void WebPreferences::setShadowRootReferenceTargetEnabledForAriaOwns(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledForAriaOwnsKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledForAriaOwnsKey(), value, true);
}

bool WebPreferences::shadowRootReferenceTargetEnabledForAriaOwns() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledForAriaOwnsKey());
}

void WebPreferences::deleteShadowRootReferenceTargetEnabledForAriaOwns()
{
    deleteKey(WebPreferencesKey::shadowRootReferenceTargetEnabledForAriaOwnsKey());
}

void WebPreferences::setShadowRootReferenceTargetEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledKey(), value, true);
}

bool WebPreferences::shadowRootReferenceTargetEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::shadowRootReferenceTargetEnabledKey());
}

void WebPreferences::deleteShadowRootReferenceTargetEnabled()
{
    deleteKey(WebPreferencesKey::shadowRootReferenceTargetEnabledKey());
}

void WebPreferences::setRequestIdleCallbackEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requestIdleCallbackEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requestIdleCallbackEnabledKey(), value, true);
}

bool WebPreferences::requestIdleCallbackEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requestIdleCallbackEnabledKey());
}

void WebPreferences::deleteRequestIdleCallbackEnabled()
{
    deleteKey(WebPreferencesKey::requestIdleCallbackEnabledKey());
}

void WebPreferences::setRequestStorageAccessThrowsExceptionUntilReload(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::requestStorageAccessThrowsExceptionUntilReloadKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::requestStorageAccessThrowsExceptionUntilReloadKey(), value, true);
}

bool WebPreferences::requestStorageAccessThrowsExceptionUntilReload() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::requestStorageAccessThrowsExceptionUntilReloadKey());
}

void WebPreferences::deleteRequestStorageAccessThrowsExceptionUntilReload()
{
    deleteKey(WebPreferencesKey::requestStorageAccessThrowsExceptionUntilReloadKey());
}

void WebPreferences::setScrollendEventEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::scrollendEventEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::scrollendEventEnabledKey(), value, true);
}

bool WebPreferences::scrollendEventEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::scrollendEventEnabledKey());
}

void WebPreferences::deleteScrollendEventEnabled()
{
    deleteKey(WebPreferencesKey::scrollendEventEnabledKey());
}

void WebPreferences::setCSSWordBreakAutoPhraseEnabled(const bool& value)
{
    if (!m_store.setBoolValueForKey(WebPreferencesKey::cssWordBreakAutoPhraseEnabledKey(), value))
        return;
    updateBoolValueForKey(WebPreferencesKey::cssWordBreakAutoPhraseEnabledKey(), value, true);
}

bool WebPreferences::cssWordBreakAutoPhraseEnabled() const
{
    return m_store.getBoolValueForKey(WebPreferencesKey::cssWordBreakAutoPhraseEnabledKey());
}

void WebPreferences::deleteCSSWordBreakAutoPhraseEnabled()
{
    deleteKey(WebPreferencesKey::cssWordBreakAutoPhraseEnabledKey());
}


void WebPreferences::setWebSecurityEnabledInspectorOverride(std::optional<bool> webSecurityEnabledInspectorOverride)
{
    if (m_webSecurityEnabledInspectorOverride == webSecurityEnabledInspectorOverride)
        return;
    m_webSecurityEnabledInspectorOverride = webSecurityEnabledInspectorOverride;
    update();
}
void WebPreferences::setAuthorAndUserStylesEnabledInspectorOverride(std::optional<bool> authorAndUserStylesEnabledInspectorOverride)
{
    if (m_authorAndUserStylesEnabledInspectorOverride == authorAndUserStylesEnabledInspectorOverride)
        return;
    m_authorAndUserStylesEnabledInspectorOverride = authorAndUserStylesEnabledInspectorOverride;
    update();
}
void WebPreferences::setCompositingBordersVisibleInspectorOverride(std::optional<bool> compositingBordersVisibleInspectorOverride)
{
    if (m_compositingBordersVisibleInspectorOverride == compositingBordersVisibleInspectorOverride)
        return;
    m_compositingBordersVisibleInspectorOverride = compositingBordersVisibleInspectorOverride;
    update();
}
void WebPreferences::setCompositingRepaintCountersVisibleInspectorOverride(std::optional<bool> compositingRepaintCountersVisibleInspectorOverride)
{
    if (m_compositingRepaintCountersVisibleInspectorOverride == compositingRepaintCountersVisibleInspectorOverride)
        return;
    m_compositingRepaintCountersVisibleInspectorOverride = compositingRepaintCountersVisibleInspectorOverride;
    update();
}
void WebPreferences::setICECandidateFilteringEnabledInspectorOverride(std::optional<bool> iceCandidateFilteringEnabledInspectorOverride)
{
    if (m_iceCandidateFilteringEnabledInspectorOverride == iceCandidateFilteringEnabledInspectorOverride)
        return;
    m_iceCandidateFilteringEnabledInspectorOverride = iceCandidateFilteringEnabledInspectorOverride;
    update();
}
void WebPreferences::setMockCaptureDevicesEnabledInspectorOverride(std::optional<bool> mockCaptureDevicesEnabledInspectorOverride)
{
    if (m_mockCaptureDevicesEnabledInspectorOverride == mockCaptureDevicesEnabledInspectorOverride)
        return;
    m_mockCaptureDevicesEnabledInspectorOverride = mockCaptureDevicesEnabledInspectorOverride;
    update();
}
void WebPreferences::setJavaScriptEnabledInspectorOverride(std::optional<bool> javaScriptEnabledInspectorOverride)
{
    if (m_javaScriptEnabledInspectorOverride == javaScriptEnabledInspectorOverride)
        return;
    m_javaScriptEnabledInspectorOverride = javaScriptEnabledInspectorOverride;
    update();
}
void WebPreferences::setMediaCaptureRequiresSecureConnectionInspectorOverride(std::optional<bool> mediaCaptureRequiresSecureConnectionInspectorOverride)
{
    if (m_mediaCaptureRequiresSecureConnectionInspectorOverride == mediaCaptureRequiresSecureConnectionInspectorOverride)
        return;
    m_mediaCaptureRequiresSecureConnectionInspectorOverride = mediaCaptureRequiresSecureConnectionInspectorOverride;
    update();
}
void WebPreferences::setNeedsSiteSpecificQuirksInspectorOverride(std::optional<bool> needsSiteSpecificQuirksInspectorOverride)
{
    if (m_needsSiteSpecificQuirksInspectorOverride == needsSiteSpecificQuirksInspectorOverride)
        return;
    m_needsSiteSpecificQuirksInspectorOverride = needsSiteSpecificQuirksInspectorOverride;
    update();
}
void WebPreferences::setShowFrameProcessBordersEnabledInspectorOverride(std::optional<bool> showFrameProcessBordersEnabledInspectorOverride)
{
    if (m_showFrameProcessBordersEnabledInspectorOverride == showFrameProcessBordersEnabledInspectorOverride)
        return;
    m_showFrameProcessBordersEnabledInspectorOverride = showFrameProcessBordersEnabledInspectorOverride;
    update();
}

}
