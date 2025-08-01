/*
 * Copyright (C) 2010-2022 Apple Inc. All rights reserved.
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
#include "JSTestRunner.h"
#include "TestRunner.h"
#include <JavaScriptCore/JSRetainPtr.h>
#include <wtf/GetPtr.h>
#include <wtf/MathExtras.h>

namespace WTR {

template<typename MessageArgumentTypesTuple, typename MethodArgumentTypesTuple> struct MethodSignatureValidationImpl { };

template<typename... MessageArgumentTypes, typename MethodArgumentType, typename... MethodArgumentTypes>
struct MethodSignatureValidationImpl<std::tuple<MessageArgumentTypes...>, std::tuple<MethodArgumentType, MethodArgumentTypes...>>
    : MethodSignatureValidationImpl<std::tuple<MessageArgumentTypes..., MethodArgumentType>, std::tuple<MethodArgumentTypes...>> { };

template<typename... MessageArgumentTypes>
struct MethodSignatureValidationImpl<std::tuple<JSContextRef, MessageArgumentTypes...>, std::tuple<>>
    : MethodSignatureValidationImpl<std::tuple<MessageArgumentTypes...>, std::tuple<>> {
    static constexpr bool expectsContextArgument = true;
};

template<typename... MessageArgumentTypes>
struct MethodSignatureValidationImpl<std::tuple<MessageArgumentTypes...>, std::tuple<>> {
    static constexpr bool expectsContextArgument = false;
    using MessageArguments = std::tuple<std::remove_cvref_t<MessageArgumentTypes>...>;
};

template<typename FunctionType> struct MethodSignatureValidation { 
    static constexpr bool expectsContextArgument = false;
};

template<typename R, typename... MethodArgumentTypes>
struct MethodSignatureValidation<R(MethodArgumentTypes...)>
    : MethodSignatureValidationImpl<std::tuple<>, std::tuple<MethodArgumentTypes...>> { };

template<typename T, typename U, typename MF, typename... Args>
decltype(auto) callFunction(JSContextRef context, T* object, MF U::* function, Args... args)
{
    if constexpr (MethodSignatureValidation<MF>::expectsContextArgument) {
        return std::apply([&](auto&&... args) {
            return (object->*function)(std::forward<decltype(args)>(args)...);
        }, std::tuple_cat(std::make_tuple(context), std::make_tuple(args...)));
    } else {
        return std::apply([&](auto&&... args) {
            return (object->*function)(std::forward<decltype(args)>(args)...);
        }, std::make_tuple(args...));
    }
}

TestRunner* toTestRunner(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSTestRunner::testRunnerClass() || !JSValueIsObjectOfClass(context, value, JSTestRunner::testRunnerClass()))
        return 0;
    return static_cast<TestRunner*>(JSWrapper::unwrap(context, value));
}

JSClassRef JSTestRunner::testRunnerClass()
{
    static const JSClassRef jsClass = [] {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "TestRunner";
        definition.parentClass = 0;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        return JSClassCreate(&definition);
    }();
    return jsClass;
}


// Constants
static JSValueRef getRENDER_TREE_SHOW_ALL_LAYERS(JSContextRef context, JSObjectRef, JSStringRef, JSValueRef*)
{
    return JSValueMakeNumber(context, 1);
}

static JSValueRef getRENDER_TREE_SHOW_LAYER_NESTING(JSContextRef context, JSObjectRef, JSStringRef, JSValueRef*)
{
    return JSValueMakeNumber(context, 2);
}

static JSValueRef getRENDER_TREE_SHOW_COMPOSITED_LAYERS(JSContextRef context, JSObjectRef, JSStringRef, JSValueRef*)
{
    return JSValueMakeNumber(context, 4);
}

static JSValueRef getRENDER_TREE_SHOW_OVERFLOW(JSContextRef context, JSObjectRef, JSStringRef, JSValueRef*)
{
    return JSValueMakeNumber(context, 8);
}

static JSValueRef getRENDER_TREE_SHOW_SVG_GEOMETRY(JSContextRef context, JSObjectRef, JSStringRef, JSValueRef*)
{
    return JSValueMakeNumber(context, 16);
}

static JSValueRef getRENDER_TREE_SHOW_LAYER_FRAGMENTS(JSContextRef context, JSObjectRef, JSStringRef, JSValueRef*)
{
    return JSValueMakeNumber(context, 32);
}

const JSStaticFunction* JSTestRunner::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "dumpAsText", dumpAsText, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpChildFramesAsText", dumpChildFramesAsText, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "waitForPolicyDelegate", waitForPolicyDelegate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "waitUntilDone", waitUntilDone, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "notifyDone", notifyDone, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "preciseTime", preciseTime, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "waitUntilDownloadFinished", waitUntilDownloadFinished, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldLogDownloadCallbacks", setShouldLogDownloadCallbacks, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldLogDownloadSize", setShouldLogDownloadSize, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldLogDownloadExpectedSize", setShouldLogDownloadExpectedSize, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldDownloadContentDispositionAttachments", setShouldDownloadContentDispositionAttachments, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setRenderTreeDumpOptions", setRenderTreeDumpOptions, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpBackForwardList", dumpBackForwardList, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpChildFrameScrollPositions", dumpChildFrameScrollPositions, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpEditingCallbacks", dumpEditingCallbacks, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpSelectionRect", dumpSelectionRect, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpTitleChanges", dumpTitleChanges, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpFullScreenCallbacks", dumpFullScreenCallbacks, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpFrameLoadCallbacks", dumpFrameLoadCallbacks, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpProgressFinishedCallback", dumpProgressFinishedCallback, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpResourceLoadCallbacks", dumpResourceLoadCallbacks, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpResourceResponseMIMETypes", dumpResourceResponseMIMETypes, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpWillCacheResponse", dumpWillCacheResponse, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpApplicationCacheDelegateCallbacks", dumpApplicationCacheDelegateCallbacks, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpDOMAsWebArchive", dumpDOMAsWebArchive, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpPolicyDelegateCallbacks", dumpPolicyDelegateCallbacks, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpResourceLoadStatistics", dumpResourceLoadStatistics, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpPrivateClickMeasurement", dumpPrivateClickMeasurement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearStorage", clearStorage, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearDOMCaches", clearDOMCaches, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearDOMCache", clearDOMCache, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hasDOMCache", hasDOMCache, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "domCacheSize", domCacheSize, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAllowStorageQuotaIncrease", setAllowStorageQuotaIncrease, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setQuota", setQuota, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setOriginQuotaRatioEnabled", setOriginQuotaRatioEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keepWebHistory", keepWebHistory, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAcceptsEditing", setAcceptsEditing, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "preventPopupWindows", preventPopupWindows, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setCustomPolicyDelegate", setCustomPolicyDelegate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "skipPolicyDelegateNotifyDone", skipPolicyDelegateNotifyDone, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addOriginAccessAllowListEntry", addOriginAccessAllowListEntry, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeOriginAccessAllowListEntry", removeOriginAccessAllowListEntry, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setUserStyleSheetEnabled", setUserStyleSheetEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setUserStyleSheetLocation", setUserStyleSheetLocation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setTabKeyCyclesThroughElements", setTabKeyCyclesThroughElements, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setSerializeHTTPLoads", setSerializeHTTPLoads, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dispatchPendingLoadRequests", dispatchPendingLoadRequests, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setCacheModel", setCacheModel, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAsynchronousSpellCheckingEnabled", setAsynchronousSpellCheckingEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPrinting", setPrinting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldDecideNavigationPolicyAfterDelay", setShouldDecideNavigationPolicyAfterDelay, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldDecideResponsePolicyAfterDelay", setShouldDecideResponsePolicyAfterDelay, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setNavigationGesturesEnabled", setNavigationGesturesEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setIgnoresViewportScaleLimits", setIgnoresViewportScaleLimits, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setUseDarkAppearanceForTesting", setUseDarkAppearanceForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldDownloadUndisplayableMIMETypes", setShouldDownloadUndisplayableMIMETypes, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stopLoading", stopLoading, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearBackForwardList", clearBackForwardList, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "execCommand", execCommand, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isCommandEnabled", isCommandEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "windowCount", windowCount, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldAllowDeviceOrientationAndMotionAccess", setShouldAllowDeviceOrientationAndMotionAccess, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "testRepaint", testRepaint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "repaintSweepHorizontally", repaintSweepHorizontally, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "display", display, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "displayAndTrackRepaints", displayAndTrackRepaints, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "displayOnLoadFinish", displayOnLoadFinish, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dontForceRepaint", dontForceRepaint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "forceImmediateCompletion", forceImmediateCompletion, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isPageBoxVisible", isPageBoxVisible, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dumpAllHTTPRedirectedResponseHeaders", dumpAllHTTPRedirectedResponseHeaders, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setValueForUser", setValueForUser, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addUserScript", addUserScript, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addUserStyleSheet", addUserStyleSheet, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearAllDatabases", clearAllDatabases, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setDatabaseQuota", setDatabaseQuota, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "pathToLocalResource", pathToLocalResource, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "syncLocalStorage", syncLocalStorage, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "findString", findString, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "findStringMatchesInPage", findStringMatchesInPage, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "indicateFindMatch", indicateFindMatch, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "replaceFindMatchesAtIndices", replaceFindMatchesAtIndices, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "evaluateScriptInIsolatedWorld", evaluateScriptInIsolatedWorld, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "showWebInspector", showWebInspector, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "closeWebInspector", closeWebInspector, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "evaluateInWebInspector", evaluateInWebInspector, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPOSIXLocale", setPOSIXLocale, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setTextDirection", setTextDirection, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setWillSendRequestReturnsNull", setWillSendRequestReturnsNull, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setWillSendRequestReturnsNullOnRedirect", setWillSendRequestReturnsNullOnRedirect, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setWillSendRequestAddsHTTPBody", setWillSendRequestAddsHTTPBody, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldStayOnPageAfterHandlingBeforeUnload", setShouldStayOnPageAfterHandlingBeforeUnload, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStopProvisionalFrameLoads", setStopProvisionalFrameLoads, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearDidReceiveServerRedirectForProvisionalNavigation", clearDidReceiveServerRedirectForProvisionalNavigation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addChromeInputField", addChromeInputField, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeChromeInputField", removeChromeInputField, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "focusWebView", focusWebView, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setTextInChromeInputField", setTextInChromeInputField, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "getSelectedTextInChromeInputField", getSelectedTextInChromeInputField, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectChromeInputField", selectChromeInputField, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setBackingScaleFactor", setBackingScaleFactor, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setWindowIsKey", setWindowIsKey, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setViewSize", setViewSize, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAlwaysAcceptCookies", setAlwaysAcceptCookies, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setOnlyAcceptFirstPartyCookies", setOnlyAcceptFirstPartyCookies, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeAllCookies", removeAllCookies, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPageVisibility", setPageVisibility, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resetPageVisibility", resetPageVisibility, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "grantWebNotificationPermission", grantWebNotificationPermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "denyWebNotificationPermission", denyWebNotificationPermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "denyWebNotificationPermissionOnPrompt", denyWebNotificationPermissionOnPrompt, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeAllWebNotificationPermissions", removeAllWebNotificationPermissions, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "simulateWebNotificationClick", simulateWebNotificationClick, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "simulateWebNotificationClickForServiceWorkerNotifications", simulateWebNotificationClickForServiceWorkerNotifications, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "getBackgroundFetchIdentifier", getBackgroundFetchIdentifier, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "abortBackgroundFetch", abortBackgroundFetch, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "pauseBackgroundFetch", pauseBackgroundFetch, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resumeBackgroundFetch", resumeBackgroundFetch, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "simulateClickBackgroundFetch", simulateClickBackgroundFetch, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setBackgroundFetchPermission", setBackgroundFetchPermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lastAddedBackgroundFetchIdentifier", lastAddedBackgroundFetchIdentifier, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lastRemovedBackgroundFetchIdentifier", lastRemovedBackgroundFetchIdentifier, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lastUpdatedBackgroundFetchIdentifier", lastUpdatedBackgroundFetchIdentifier, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "backgroundFetchState", backgroundFetchState, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setGeolocationPermission", setGeolocationPermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMockGeolocationPosition", setMockGeolocationPosition, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMockGeolocationPositionUnavailableError", setMockGeolocationPositionUnavailableError, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isGeolocationProviderActive", isGeolocationProviderActive, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setScreenWakeLockPermission", setScreenWakeLockPermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setCameraPermission", setCameraPermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMicrophonePermission", setMicrophonePermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setUserMediaPermission", setUserMediaPermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resetUserMediaPermission", resetUserMediaPermission, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "delayUserMediaRequestDecision", delayUserMediaRequestDecision, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "userMediaPermissionRequestCount", userMediaPermissionRequestCount, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resetUserMediaPermissionRequestCount", resetUserMediaPermissionRequestCount, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAudioResult", setAudioResult, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "callShouldCloseOnWebView", callShouldCloseOnWebView, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "queueBackNavigation", queueBackNavigation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "queueForwardNavigation", queueForwardNavigation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "queueLoad", queueLoad, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "queueLoadHTMLString", queueLoadHTMLString, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "queueReload", queueReload, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "queueLoadingScript", queueLoadingScript, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "queueNonLoadingScript", queueNonLoadingScript, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setRejectsProtectionSpaceAndContinueForAuthenticationChallenges", setRejectsProtectionSpaceAndContinueForAuthenticationChallenges, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setHandlesAuthenticationChallenges", setHandlesAuthenticationChallenges, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldLogCanAuthenticateAgainstProtectionSpace", setShouldLogCanAuthenticateAgainstProtectionSpace, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAuthenticationUsername", setAuthenticationUsername, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAuthenticationPassword", setAuthenticationPassword, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAllowsAnySSLCertificate", setAllowsAnySSLCertificate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldSwapToEphemeralSessionOnNextNavigation", setShouldSwapToEphemeralSessionOnNextNavigation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldSwapToDefaultSessionOnNextNavigation", setShouldSwapToDefaultSessionOnNextNavigation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setBlockAllPlugins", setBlockAllPlugins, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPluginSupportedMode", setPluginSupportedMode, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "failNextNewCodeBlock", failNextNewCodeBlock, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "numberOfDFGCompiles", numberOfDFGCompiles, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "neverInlineFunction", neverInlineFunction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installDidBeginSwipeCallback", installDidBeginSwipeCallback, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installWillEndSwipeCallback", installWillEndSwipeCallback, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installDidEndSwipeCallback", installDidEndSwipeCallback, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installDidRemoveSwipeSnapshotCallback", installDidRemoveSwipeSnapshotCallback, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "imageCountInGeneralPasteboard", imageCountInGeneralPasteboard, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "runUIScript", runUIScript, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "runUIScriptImmediately", runUIScriptImmediately, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "accummulateLogsForChannel", accummulateLogsForChannel, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAllowedMenuActions", setAllowedMenuActions, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMockGamepadDetails", setMockGamepadDetails, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMockGamepadAxisValue", setMockGamepadAxisValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMockGamepadButtonValue", setMockGamepadButtonValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "connectMockGamepad", connectMockGamepad, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "disconnectMockGamepad", disconnectMockGamepad, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearStatisticsDataForDomain", clearStatisticsDataForDomain, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "doesStatisticsDomainIDExistInDatabase", doesStatisticsDomainIDExistInDatabase, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsEnabled", setStatisticsEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsEphemeral", isStatisticsEphemeral, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsDebugMode", setStatisticsDebugMode, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsPrevalentResourceForDebugMode", setStatisticsPrevalentResourceForDebugMode, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsLastSeen", setStatisticsLastSeen, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsMergeStatistic", setStatisticsMergeStatistic, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsExpiredStatistic", setStatisticsExpiredStatistic, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsPrevalentResource", setStatisticsPrevalentResource, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsVeryPrevalentResource", setStatisticsVeryPrevalentResource, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsPrevalentResource", isStatisticsPrevalentResource, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsVeryPrevalentResource", isStatisticsVeryPrevalentResource, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsRegisteredAsSubresourceUnder", isStatisticsRegisteredAsSubresourceUnder, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsRegisteredAsSubFrameUnder", isStatisticsRegisteredAsSubFrameUnder, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsRegisteredAsRedirectingTo", isStatisticsRegisteredAsRedirectingTo, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsHasHadUserInteraction", setStatisticsHasHadUserInteraction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsHasHadUserInteraction", isStatisticsHasHadUserInteraction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsOnlyInDatabaseOnce", isStatisticsOnlyInDatabaseOnce, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsGrandfathered", setStatisticsGrandfathered, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsGrandfathered", isStatisticsGrandfathered, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsSubframeUnderTopFrameOrigin", setStatisticsSubframeUnderTopFrameOrigin, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsSubresourceUnderTopFrameOrigin", setStatisticsSubresourceUnderTopFrameOrigin, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsSubresourceUniqueRedirectTo", setStatisticsSubresourceUniqueRedirectTo, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsSubresourceUniqueRedirectFrom", setStatisticsSubresourceUniqueRedirectFrom, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsTopFrameUniqueRedirectTo", setStatisticsTopFrameUniqueRedirectTo, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsTopFrameUniqueRedirectFrom", setStatisticsTopFrameUniqueRedirectFrom, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsCrossSiteLoadWithLinkDecoration", setStatisticsCrossSiteLoadWithLinkDecoration, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsTimeToLiveUserInteraction", setStatisticsTimeToLiveUserInteraction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsNotifyObserver", statisticsNotifyObserver, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsProcessStatisticsAndDataRecords", statisticsProcessStatisticsAndDataRecords, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsUpdateCookieBlocking", statisticsUpdateCookieBlocking, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsTimeAdvanceForTesting", setStatisticsTimeAdvanceForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsIsRunningTest", setStatisticsIsRunningTest, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsShouldClassifyResourcesBeforeDataRecordsRemoval", setStatisticsShouldClassifyResourcesBeforeDataRecordsRemoval, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsMinimumTimeBetweenDataRecordsRemoval", setStatisticsMinimumTimeBetweenDataRecordsRemoval, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsGrandfatheringTime", setStatisticsGrandfatheringTime, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsMaxStatisticsEntries", setStatisticsMaxStatisticsEntries, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsPruneEntriesDownTo", setStatisticsPruneEntriesDownTo, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsClearInMemoryAndPersistentStore", statisticsClearInMemoryAndPersistentStore, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsClearInMemoryAndPersistentStoreModifiedSinceHours", statisticsClearInMemoryAndPersistentStoreModifiedSinceHours, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsClearThroughWebsiteDataRemoval", statisticsClearThroughWebsiteDataRemoval, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsDeleteCookiesForHost", statisticsDeleteCookiesForHost, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isStatisticsHasLocalStorage", isStatisticsHasLocalStorage, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsCacheMaxAgeCap", setStatisticsCacheMaxAgeCap, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsResetToConsistentState", statisticsResetToConsistentState, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hasStatisticsIsolatedSession", hasStatisticsIsolatedSession, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsShouldDowngradeReferrer", setStatisticsShouldDowngradeReferrer, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsShouldBlockThirdPartyCookies", setStatisticsShouldBlockThirdPartyCookies, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setStatisticsFirstPartyWebsiteDataRemovalMode", setStatisticsFirstPartyWebsiteDataRemovalMode, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsSetToSameSiteStrictCookies", statisticsSetToSameSiteStrictCookies, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsSetFirstPartyHostCNAMEDomain", statisticsSetFirstPartyHostCNAMEDomain, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "statisticsSetThirdPartyCNAMEDomain", statisticsSetThirdPartyCNAMEDomain, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "loadedSubresourceDomains", loadedSubresourceDomains, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "reloadFromOrigin", reloadFromOrigin, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installTextDidChangeInTextFieldCallback", installTextDidChangeInTextFieldCallback, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installTextFieldDidBeginEditingCallback", installTextFieldDidBeginEditingCallback, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installTextFieldDidEndEditingCallback", installTextFieldDidEndEditingCallback, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "getAllStorageAccessEntries", getAllStorageAccessEntries, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setRequestStorageAccessThrowsExceptionUntilReload", setRequestStorageAccessThrowsExceptionUntilReload, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setOpenPanelFiles", setOpenPanelFiles, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setOpenPanelFilesMediaIcon", setOpenPanelFilesMediaIcon, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setShouldDismissJavaScriptAlertsAsynchronously", setShouldDismissJavaScriptAlertsAsynchronously, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "abortModal", abortModal, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setCustomUserAgent", setCustomUserAgent, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "terminateGPUProcess", terminateGPUProcess, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "terminateNetworkProcess", terminateNetworkProcess, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "terminateServiceWorkers", terminateServiceWorkers, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setUseSeparateServiceWorkerProcess", setUseSeparateServiceWorkerProcess, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeAllSessionCredentials", removeAllSessionCredentials, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "getApplicationManifestThen", getApplicationManifestThen, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installFakeHelvetica", installFakeHelvetica, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addMockCameraDevice", addMockCameraDevice, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addMockMicrophoneDevice", addMockMicrophoneDevice, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addMockScreenDevice", addMockScreenDevice, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearMockMediaDevices", clearMockMediaDevices, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeMockMediaDevice", removeMockMediaDevice, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMockMediaDeviceIsEphemeral", setMockMediaDeviceIsEphemeral, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resetMockMediaDevices", resetMockMediaDevices, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMockCameraOrientation", setMockCameraOrientation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isMockRealtimeMediaSourceCenterEnabled", isMockRealtimeMediaSourceCenterEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMockCaptureDevicesInterrupted", setMockCaptureDevicesInterrupted, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "triggerMockCaptureConfigurationChange", triggerMockCaptureConfigurationChange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setCaptureState", setCaptureState, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hasAppBoundSession", hasAppBoundSession, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearAppBoundSession", clearAppBoundSession, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAppBoundDomains", setAppBoundDomains, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "didLoadAppInitiatedRequest", didLoadAppInitiatedRequest, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "didLoadNonAppInitiatedRequest", didLoadNonAppInitiatedRequest, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setManagedDomains", setManagedDomains, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "injectUserScript", injectUserScript, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setServiceWorkerFetchTimeout", setServiceWorkerFetchTimeout, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addTestKeyToKeychain", addTestKeyToKeychain, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "cleanUpKeychain", cleanUpKeychain, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keyExistsInKeychain", keyExistsInKeychain, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearMemoryCache", clearMemoryCache, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearPrivateClickMeasurement", clearPrivateClickMeasurement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearPrivateClickMeasurementsThroughWebsiteDataRemoval", clearPrivateClickMeasurementsThroughWebsiteDataRemoval, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPrivateClickMeasurementOverrideTimerForTesting", setPrivateClickMeasurementOverrideTimerForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "markAttributedPrivateClickMeasurementsAsExpiredForTesting", markAttributedPrivateClickMeasurementsAsExpiredForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPrivateClickMeasurementEphemeralMeasurementForTesting", setPrivateClickMeasurementEphemeralMeasurementForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "simulatePrivateClickMeasurementSessionRestart", simulatePrivateClickMeasurementSessionRestart, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPrivateClickMeasurementTokenPublicKeyURLForTesting", setPrivateClickMeasurementTokenPublicKeyURLForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPrivateClickMeasurementTokenSignatureURLForTesting", setPrivateClickMeasurementTokenSignatureURLForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPrivateClickMeasurementAttributionReportURLsForTesting", setPrivateClickMeasurementAttributionReportURLsForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "markPrivateClickMeasurementsAsExpiredForTesting", markPrivateClickMeasurementsAsExpiredForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPrivateClickMeasurementFraudPreventionValuesForTesting", setPrivateClickMeasurementFraudPreventionValuesForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPrivateClickMeasurementAppBundleIDForTesting", setPrivateClickMeasurementAppBundleIDForTesting, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setIsSpeechRecognitionPermissionGranted", setIsSpeechRecognitionPermissionGranted, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setIsMediaKeySystemPermissionGranted", setIsMediaKeySystemPermissionGranted, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "takeViewPortSnapshot", takeViewPortSnapshot, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "generateTestReport", generateTestReport, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "getAndClearReportedWindowProxyAccessDomains", getAndClearReportedWindowProxyAccessDomains, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "flushConsoleLogs", flushConsoleLogs, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "updatePresentation", updatePresentation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollDuringEnterFullscreen", scrollDuringEnterFullscreen, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "waitBeforeFinishingFullscreenExit", waitBeforeFinishingFullscreenExit, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "finishFullscreenExit", finishFullscreenExit, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "requestExitFullscreenFromUIProcess", requestExitFullscreenFromUIProcess, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setObscuredContentInsets", setObscuredContentInsets, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setPageScaleFactor", setPageScaleFactor, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setResourceMonitorList", setResourceMonitorList, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0 }
    };
    return functions;
}

const JSStaticValue* JSTestRunner::staticValues()
{
    static const JSStaticValue values[] = {
        { "isWebKit2", isWebKit2, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isIOSFamily", isIOSFamily, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isMac", isMac, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isKeyboardImmediatelyAvailable", isKeyboardImmediatelyAvailable, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keyboardAppearsOverContent", keyboardAppearsOverContent, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "haveSecureCodingRequest", haveSecureCodingRequest, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "haveSecureCodingDataDetectors", haveSecureCodingDataDetectors, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "timeout", timeout, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "globalFlag", globalFlag, setGlobalFlag, kJSPropertyAttributeDontDelete },
        { "databaseDefaultQuota", databaseDefaultQuota, setDatabaseDefaultQuota, kJSPropertyAttributeDontDelete },
        { "databaseMaxQuota", databaseMaxQuota, setDatabaseMaxQuota, kJSPropertyAttributeDontDelete },
        { "inspectorTestStubURL", inspectorTestStubURL, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "didReceiveServerRedirectForProvisionalNavigation", didReceiveServerRedirectForProvisionalNavigation, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isDoingMediaCapture", isDoingMediaCapture, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "secureEventInputIsEnabled", secureEventInputIsEnabled, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "serverTrustEvaluationCallbackCallsCount", serverTrustEvaluationCallbackCallsCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "didCancelClientRedirect", didCancelClientRedirect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "userScriptInjectedCount", userScriptInjectedCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "canModifyResourceMonitorList", canModifyResourceMonitorList, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "RENDER_TREE_SHOW_ALL_LAYERS", getRENDER_TREE_SHOW_ALL_LAYERS, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "RENDER_TREE_SHOW_LAYER_NESTING", getRENDER_TREE_SHOW_LAYER_NESTING, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "RENDER_TREE_SHOW_COMPOSITED_LAYERS", getRENDER_TREE_SHOW_COMPOSITED_LAYERS, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "RENDER_TREE_SHOW_OVERFLOW", getRENDER_TREE_SHOW_OVERFLOW, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "RENDER_TREE_SHOW_SVG_GEOMETRY", getRENDER_TREE_SHOW_SVG_GEOMETRY, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "RENDER_TREE_SHOW_LAYER_FRAGMENTS", getRENDER_TREE_SHOW_LAYER_FRAGMENTS, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0, 0 }
    };
    return values;
}

// Functions

JSValueRef JSTestRunner::dumpAsText(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool dumpPixels = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::dumpAsText, dumpPixels);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpChildFramesAsText(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpChildFramesAsText);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::waitForPolicyDelegate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::waitForPolicyDelegate);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::waitUntilDone(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::waitUntilDone);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::notifyDone(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::notifyDone);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::preciseTime(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::preciseTime));
}

JSValueRef JSTestRunner::waitUntilDownloadFinished(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::waitUntilDownloadFinished);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldLogDownloadCallbacks(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldLogDownloadCallbacks, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldLogDownloadSize(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldLogDownloadSize, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldLogDownloadExpectedSize(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldLogDownloadExpectedSize, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldDownloadContentDispositionAttachments(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldDownloadContentDispositionAttachments, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setRenderTreeDumpOptions(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto options = argumentCount > 0 ? clampTo<uint16_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint16_t();
    callFunction(context, impl, &TestRunner::setRenderTreeDumpOptions, options);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpBackForwardList(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpBackForwardList);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpChildFrameScrollPositions(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpChildFrameScrollPositions);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpEditingCallbacks(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpEditingCallbacks);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpSelectionRect(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpSelectionRect);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpTitleChanges(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpTitleChanges);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpFullScreenCallbacks(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpFullScreenCallbacks);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpFrameLoadCallbacks(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpFrameLoadCallbacks);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpProgressFinishedCallback(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpProgressFinishedCallback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpResourceLoadCallbacks(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpResourceLoadCallbacks);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpResourceResponseMIMETypes(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpResourceResponseMIMETypes);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpWillCacheResponse(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpWillCacheResponse);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpApplicationCacheDelegateCallbacks(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpApplicationCacheDelegateCallbacks);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpDOMAsWebArchive(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpDOMAsWebArchive);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpPolicyDelegateCallbacks(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpPolicyDelegateCallbacks);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpResourceLoadStatistics(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpResourceLoadStatistics);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dumpPrivateClickMeasurement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpPrivateClickMeasurement);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearStorage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearStorage);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearDOMCaches(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearDOMCaches);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearDOMCache(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto origin = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::clearDOMCache, origin.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::hasDOMCache(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto origin = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::hasDOMCache, origin.get()));
}

JSValueRef JSTestRunner::domCacheSize(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto origin = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::domCacheSize, origin.get()));
}

JSValueRef JSTestRunner::setAllowStorageQuotaIncrease(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setAllowStorageQuotaIncrease, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setQuota(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto quota = argumentCount > 0 ? clampTo<uint64_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint64_t();
    callFunction(context, impl, &TestRunner::setQuota, quota);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setOriginQuotaRatioEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setOriginQuotaRatioEnabled, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::keepWebHistory(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::keepWebHistory);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAcceptsEditing(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setAcceptsEditing, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::preventPopupWindows(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::preventPopupWindows);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setCustomPolicyDelegate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool enabled = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    bool permissive = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    callFunction(context, impl, &TestRunner::setCustomPolicyDelegate, enabled, permissive);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::skipPolicyDelegateNotifyDone(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::skipPolicyDelegateNotifyDone);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::addOriginAccessAllowListEntry(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto sourceOrigin = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto destinationProtocol = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto destinationHost = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    bool allowDestinationSubdomains = argumentCount > 3 && JSValueToBoolean(context, arguments[3]);
    callFunction(context, impl, &TestRunner::addOriginAccessAllowListEntry, sourceOrigin.get(), destinationProtocol.get(), destinationHost.get(), allowDestinationSubdomains);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::removeOriginAccessAllowListEntry(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto sourceOrigin = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto destinationProtocol = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto destinationHost = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    bool allowDestinationSubdomains = argumentCount > 3 && JSValueToBoolean(context, arguments[3]);
    callFunction(context, impl, &TestRunner::removeOriginAccessAllowListEntry, sourceOrigin.get(), destinationProtocol.get(), destinationHost.get(), allowDestinationSubdomains);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setUserStyleSheetEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setUserStyleSheetEnabled, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setUserStyleSheetLocation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto location = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setUserStyleSheetLocation, location.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setTabKeyCyclesThroughElements(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool enabled = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setTabKeyCyclesThroughElements, enabled);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setSerializeHTTPLoads(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::setSerializeHTTPLoads);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dispatchPendingLoadRequests(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dispatchPendingLoadRequests);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setCacheModel(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto model = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    callFunction(context, impl, &TestRunner::setCacheModel, model);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAsynchronousSpellCheckingEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setAsynchronousSpellCheckingEnabled, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPrinting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::setPrinting);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldDecideNavigationPolicyAfterDelay(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldDecideNavigationPolicyAfterDelay, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldDecideResponsePolicyAfterDelay(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldDecideResponsePolicyAfterDelay, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setNavigationGesturesEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setNavigationGesturesEnabled, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setIgnoresViewportScaleLimits(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setIgnoresViewportScaleLimits, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setUseDarkAppearanceForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool useDarkAppearance = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setUseDarkAppearanceForTesting, useDarkAppearance);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldDownloadUndisplayableMIMETypes(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldDownloadUndisplayableMIMETypes, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::stopLoading(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::stopLoading);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearBackForwardList(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::clearBackForwardList, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::execCommand(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto name = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto showUI = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto value = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::execCommand, name.get(), showUI.get(), value.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::isCommandEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto name = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isCommandEnabled, name.get()));
}

JSValueRef JSTestRunner::windowCount(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::windowCount));
}

JSValueRef JSTestRunner::setShouldAllowDeviceOrientationAndMotionAccess(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldAllowDeviceOrientationAndMotionAccess, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::testRepaint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::testRepaint);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::repaintSweepHorizontally(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::repaintSweepHorizontally);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::display(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::display);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::displayAndTrackRepaints(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::displayAndTrackRepaints, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::displayOnLoadFinish(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::displayOnLoadFinish);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::dontForceRepaint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dontForceRepaint);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::forceImmediateCompletion(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::forceImmediateCompletion);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::isPageBoxVisible(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto pageIndex = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isPageBoxVisible, pageIndex));
}

JSValueRef JSTestRunner::dumpAllHTTPRedirectedResponseHeaders(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::dumpAllHTTPRedirectedResponseHeaders);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setValueForUser(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto element = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    auto value = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setValueForUser, element, value.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::addUserScript(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto source = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool runAtStart = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    bool allFrames = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    callFunction(context, impl, &TestRunner::addUserScript, source.get(), runAtStart, allFrames);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::addUserStyleSheet(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto source = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool allFrames = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    callFunction(context, impl, &TestRunner::addUserStyleSheet, source.get(), allFrames);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearAllDatabases(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearAllDatabases);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setDatabaseQuota(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto quota = argumentCount > 0 ? clampTo<uint64_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint64_t();
    callFunction(context, impl, &TestRunner::setDatabaseQuota, quota);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::pathToLocalResource(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto url = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return makeValue(context, callFunction(context, impl, &TestRunner::pathToLocalResource, url.get()).get());
}

JSValueRef JSTestRunner::syncLocalStorage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::syncLocalStorage);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::findString(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto target = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto optionsArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::findString, target.get(), optionsArray, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::findStringMatchesInPage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto target = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto optionsArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::findStringMatchesInPage, target.get(), optionsArray);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::indicateFindMatch(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto matchIndex = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &TestRunner::indicateFindMatch, matchIndex);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::replaceFindMatchesAtIndices(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto matchIndicesArray = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    auto replacementText = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    bool selectionOnly = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    callFunction(context, impl, &TestRunner::replaceFindMatchesAtIndices, matchIndicesArray, replacementText.get(), selectionOnly);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::evaluateScriptInIsolatedWorld(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto worldID = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto script = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::evaluateScriptInIsolatedWorld, worldID, script.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::showWebInspector(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::showWebInspector);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::closeWebInspector(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::closeWebInspector);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::evaluateInWebInspector(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto script = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::evaluateInWebInspector, script.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPOSIXLocale(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto locale = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setPOSIXLocale, locale.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setTextDirection(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto direction = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setTextDirection, direction.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setWillSendRequestReturnsNull(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool flag = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setWillSendRequestReturnsNull, flag);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setWillSendRequestReturnsNullOnRedirect(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool flag = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setWillSendRequestReturnsNullOnRedirect, flag);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setWillSendRequestAddsHTTPBody(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto body = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setWillSendRequestAddsHTTPBody, body.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldStayOnPageAfterHandlingBeforeUnload(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool flag = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldStayOnPageAfterHandlingBeforeUnload, flag);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStopProvisionalFrameLoads(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::setStopProvisionalFrameLoads);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearDidReceiveServerRedirectForProvisionalNavigation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearDidReceiveServerRedirectForProvisionalNavigation);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::addChromeInputField(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::addChromeInputField, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::removeChromeInputField(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::removeChromeInputField, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::focusWebView(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::focusWebView, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setTextInChromeInputField(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto text = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setTextInChromeInputField, text.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::getSelectedTextInChromeInputField(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::getSelectedTextInChromeInputField, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::selectChromeInputField(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::selectChromeInputField, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setBackingScaleFactor(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto backingScaleFactor = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setBackingScaleFactor, backingScaleFactor, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setWindowIsKey(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool isKey = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setWindowIsKey, isKey);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setViewSize(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto width = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    auto height = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : double();
    callFunction(context, impl, &TestRunner::setViewSize, width, height);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAlwaysAcceptCookies(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool accept = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setAlwaysAcceptCookies, accept);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setOnlyAcceptFirstPartyCookies(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool accept = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setOnlyAcceptFirstPartyCookies, accept);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::removeAllCookies(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::removeAllCookies, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPageVisibility(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto state = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setPageVisibility, state.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::resetPageVisibility(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::resetPageVisibility);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::grantWebNotificationPermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto origin = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::grantWebNotificationPermission, origin.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::denyWebNotificationPermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto origin = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::denyWebNotificationPermission, origin.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::denyWebNotificationPermissionOnPrompt(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto origin = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::denyWebNotificationPermissionOnPrompt, origin.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::removeAllWebNotificationPermissions(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::removeAllWebNotificationPermissions);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::simulateWebNotificationClick(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto notification = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::simulateWebNotificationClick, notification);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::simulateWebNotificationClickForServiceWorkerNotifications(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::simulateWebNotificationClickForServiceWorkerNotifications);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::getBackgroundFetchIdentifier(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &TestRunner::getBackgroundFetchIdentifier).get());
}

JSValueRef JSTestRunner::abortBackgroundFetch(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto identifier = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::abortBackgroundFetch, identifier.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::pauseBackgroundFetch(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto identifier = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::pauseBackgroundFetch, identifier.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::resumeBackgroundFetch(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto identifier = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::resumeBackgroundFetch, identifier.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::simulateClickBackgroundFetch(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto identifier = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::simulateClickBackgroundFetch, identifier.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setBackgroundFetchPermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setBackgroundFetchPermission, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::lastAddedBackgroundFetchIdentifier(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &TestRunner::lastAddedBackgroundFetchIdentifier).get());
}

JSValueRef JSTestRunner::lastRemovedBackgroundFetchIdentifier(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &TestRunner::lastRemovedBackgroundFetchIdentifier).get());
}

JSValueRef JSTestRunner::lastUpdatedBackgroundFetchIdentifier(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &TestRunner::lastUpdatedBackgroundFetchIdentifier).get());
}

JSValueRef JSTestRunner::backgroundFetchState(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto identifier = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return makeValue(context, callFunction(context, impl, &TestRunner::backgroundFetchState, identifier.get()).get());
}

JSValueRef JSTestRunner::setGeolocationPermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setGeolocationPermission, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setMockGeolocationPosition(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto latitude = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    auto longitude = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : double();
    auto accuracy = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : double();
    auto altitude = argumentCount > 3 ? toOptionalDouble(context, arguments[3]) : std::nullopt;
    auto altitudeAccuracy = argumentCount > 4 ? toOptionalDouble(context, arguments[4]) : std::nullopt;
    auto heading = argumentCount > 5 ? toOptionalDouble(context, arguments[5]) : std::nullopt;
    auto speed = argumentCount > 6 ? toOptionalDouble(context, arguments[6]) : std::nullopt;
    auto floorLevel = argumentCount > 7 ? toOptionalDouble(context, arguments[7]) : std::nullopt;
    callFunction(context, impl, &TestRunner::setMockGeolocationPosition, latitude, longitude, accuracy, altitude, altitudeAccuracy, heading, speed, floorLevel);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setMockGeolocationPositionUnavailableError(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto errorMessage = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setMockGeolocationPositionUnavailableError, errorMessage.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::isGeolocationProviderActive(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isGeolocationProviderActive));
}

JSValueRef JSTestRunner::setScreenWakeLockPermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setScreenWakeLockPermission, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setCameraPermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setCameraPermission, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setMicrophonePermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setMicrophonePermission, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setUserMediaPermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setUserMediaPermission, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::resetUserMediaPermission(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::resetUserMediaPermission);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::delayUserMediaRequestDecision(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::delayUserMediaRequestDecision);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::userMediaPermissionRequestCount(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::userMediaPermissionRequestCount));
}

JSValueRef JSTestRunner::resetUserMediaPermissionRequestCount(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::resetUserMediaPermissionRequestCount);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAudioResult(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto data = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setAudioResult, data);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::callShouldCloseOnWebView(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::callShouldCloseOnWebView));
}

JSValueRef JSTestRunner::queueBackNavigation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto howFarBackward = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &TestRunner::queueBackNavigation, howFarBackward);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::queueForwardNavigation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto howFarForward = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &TestRunner::queueForwardNavigation, howFarForward);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::queueLoad(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto url = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto target = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    bool shouldOpenExternalURLs = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    callFunction(context, impl, &TestRunner::queueLoad, url.get(), target.get(), shouldOpenExternalURLs);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::queueLoadHTMLString(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto content = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto baseURL = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto unreachableURL = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::queueLoadHTMLString, content.get(), baseURL.get(), unreachableURL.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::queueReload(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::queueReload);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::queueLoadingScript(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto script = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::queueLoadingScript, script.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::queueNonLoadingScript(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto script = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::queueNonLoadingScript, script.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setRejectsProtectionSpaceAndContinueForAuthenticationChallenges(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setRejectsProtectionSpaceAndContinueForAuthenticationChallenges, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setHandlesAuthenticationChallenges(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setHandlesAuthenticationChallenges, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldLogCanAuthenticateAgainstProtectionSpace(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldLogCanAuthenticateAgainstProtectionSpace, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAuthenticationUsername(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto username = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setAuthenticationUsername, username.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAuthenticationPassword(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto password = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setAuthenticationPassword, password.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAllowsAnySSLCertificate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setAllowsAnySSLCertificate, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldSwapToEphemeralSessionOnNextNavigation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldSwapToEphemeralSessionOnNextNavigation, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldSwapToDefaultSessionOnNextNavigation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldSwapToDefaultSessionOnNextNavigation, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setBlockAllPlugins(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool shouldBlock = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setBlockAllPlugins, shouldBlock);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPluginSupportedMode(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto mode = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setPluginSupportedMode, mode.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::failNextNewCodeBlock(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &TestRunner::failNextNewCodeBlock);
}

JSValueRef JSTestRunner::numberOfDFGCompiles(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto function = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    return callFunction(context, impl, &TestRunner::numberOfDFGCompiles, function);
}

JSValueRef JSTestRunner::neverInlineFunction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto function = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    return callFunction(context, impl, &TestRunner::neverInlineFunction, function);
}

JSValueRef JSTestRunner::installDidBeginSwipeCallback(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::installDidBeginSwipeCallback, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::installWillEndSwipeCallback(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::installWillEndSwipeCallback, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::installDidEndSwipeCallback(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::installDidEndSwipeCallback, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::installDidRemoveSwipeSnapshotCallback(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::installDidRemoveSwipeSnapshotCallback, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::imageCountInGeneralPasteboard(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::imageCountInGeneralPasteboard));
}

JSValueRef JSTestRunner::runUIScript(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto script = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::runUIScript, script.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::runUIScriptImmediately(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto script = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::runUIScriptImmediately, script.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::accummulateLogsForChannel(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto channel = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::accummulateLogsForChannel, channel.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAllowedMenuActions(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto actions = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setAllowedMenuActions, actions);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setMockGamepadDetails(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto id = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto mapping = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    auto axisCount = argumentCount > 3 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[3], nullptr)) : uint32_t();
    auto buttonCount = argumentCount > 4 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[4], nullptr)) : uint32_t();
    bool supportsDualRumble = argumentCount > 5 && JSValueToBoolean(context, arguments[5]);
    callFunction(context, impl, &TestRunner::setMockGamepadDetails, index, id.get(), mapping.get(), axisCount, buttonCount, supportsDualRumble);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setMockGamepadAxisValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto axisIndex = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    auto value = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : double();
    callFunction(context, impl, &TestRunner::setMockGamepadAxisValue, index, axisIndex, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setMockGamepadButtonValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto buttonIndex = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    auto value = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : double();
    callFunction(context, impl, &TestRunner::setMockGamepadButtonValue, index, buttonIndex, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::connectMockGamepad(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &TestRunner::connectMockGamepad, index);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::disconnectMockGamepad(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &TestRunner::disconnectMockGamepad, index);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearStatisticsDataForDomain(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto domain = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::clearStatisticsDataForDomain, domain.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::doesStatisticsDomainIDExistInDatabase(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto domainID = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::doesStatisticsDomainIDExistInDatabase, domainID));
}

JSValueRef JSTestRunner::setStatisticsEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setStatisticsEnabled, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::isStatisticsEphemeral(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsEphemeral));
}

JSValueRef JSTestRunner::setStatisticsDebugMode(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    auto completionHandler = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsDebugMode, value, completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsPrevalentResourceForDebugMode(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto completionHandler = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsPrevalentResourceForDebugMode, hostName.get(), completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsLastSeen(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto seconds = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : double();
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::setStatisticsLastSeen, hostName.get(), seconds, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::setStatisticsMergeStatistic(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto topFrameDomain1 = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto topFrameDomain2 = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    auto lastSeen = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : double();
    bool hadUserInteraction = argumentCount > 4 && JSValueToBoolean(context, arguments[4]);
    auto mostRecentUserInteraction = argumentCount > 5 ? JSValueToNumber(context, arguments[5], nullptr) : double();
    bool isGrandfathered = argumentCount > 6 && JSValueToBoolean(context, arguments[6]);
    bool isPrevalent = argumentCount > 7 && JSValueToBoolean(context, arguments[7]);
    bool isVeryPrevalent = argumentCount > 8 && JSValueToBoolean(context, arguments[8]);
    auto dataRecordsRemoved = argumentCount > 9 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[9], nullptr)) : uint32_t();
    auto completionHandler = argumentCount > 10 ? arguments[10] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsMergeStatistic, hostName.get(), topFrameDomain1.get(), topFrameDomain2.get(), lastSeen, hadUserInteraction, mostRecentUserInteraction, isGrandfathered, isPrevalent, isVeryPrevalent, dataRecordsRemoved, completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsExpiredStatistic(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto numberOfOperatingDaysPassed = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    bool hadUserInteraction = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    bool isScheduledForAllButCookieDataRemoval = argumentCount > 3 && JSValueToBoolean(context, arguments[3]);
    bool isPrevalent = argumentCount > 4 && JSValueToBoolean(context, arguments[4]);
    auto completionHandler = argumentCount > 5 ? arguments[5] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsExpiredStatistic, hostName.get(), numberOfOperatingDaysPassed, hadUserInteraction, isScheduledForAllButCookieDataRemoval, isPrevalent, completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsPrevalentResource(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool value = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    auto completionHandler = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsPrevalentResource, hostName.get(), value, completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsVeryPrevalentResource(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool value = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    auto completionHandler = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsVeryPrevalentResource, hostName.get(), value, completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::isStatisticsPrevalentResource(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsPrevalentResource, hostName.get()));
}

JSValueRef JSTestRunner::isStatisticsVeryPrevalentResource(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsVeryPrevalentResource, hostName.get()));
}

JSValueRef JSTestRunner::isStatisticsRegisteredAsSubresourceUnder(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto subresourceHost = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto topFrameHost = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsRegisteredAsSubresourceUnder, subresourceHost.get(), topFrameHost.get()));
}

JSValueRef JSTestRunner::isStatisticsRegisteredAsSubFrameUnder(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto subFrameHost = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto topFrameHost = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsRegisteredAsSubFrameUnder, subFrameHost.get(), topFrameHost.get()));
}

JSValueRef JSTestRunner::isStatisticsRegisteredAsRedirectingTo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostRedirectedFrom = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto hostRedirectedTo = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsRegisteredAsRedirectingTo, hostRedirectedFrom.get(), hostRedirectedTo.get()));
}

JSValueRef JSTestRunner::setStatisticsHasHadUserInteraction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool value = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    auto completionHandler = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsHasHadUserInteraction, hostName.get(), value, completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::isStatisticsHasHadUserInteraction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsHasHadUserInteraction, hostName.get()));
}

JSValueRef JSTestRunner::isStatisticsOnlyInDatabaseOnce(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto subHost = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto topHost = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsOnlyInDatabaseOnce, subHost.get(), topHost.get()));
}

JSValueRef JSTestRunner::setStatisticsGrandfathered(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool value = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    callFunction(context, impl, &TestRunner::setStatisticsGrandfathered, hostName.get(), value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::isStatisticsGrandfathered(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsGrandfathered, hostName.get()));
}

JSValueRef JSTestRunner::setStatisticsSubframeUnderTopFrameOrigin(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto topFrameHostName = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setStatisticsSubframeUnderTopFrameOrigin, hostName.get(), topFrameHostName.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsSubresourceUnderTopFrameOrigin(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto topFrameHostName = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setStatisticsSubresourceUnderTopFrameOrigin, hostName.get(), topFrameHostName.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsSubresourceUniqueRedirectTo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto hostNameRedirectedTo = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setStatisticsSubresourceUniqueRedirectTo, hostName.get(), hostNameRedirectedTo.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsSubresourceUniqueRedirectFrom(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto hostNameRedirectedTo = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setStatisticsSubresourceUniqueRedirectFrom, hostName.get(), hostNameRedirectedTo.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsTopFrameUniqueRedirectTo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto hostNameRedirectedTo = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setStatisticsTopFrameUniqueRedirectTo, hostName.get(), hostNameRedirectedTo.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsTopFrameUniqueRedirectFrom(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto hostNameRedirectedTo = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setStatisticsTopFrameUniqueRedirectFrom, hostName.get(), hostNameRedirectedTo.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsCrossSiteLoadWithLinkDecoration(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto fromHost = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto toHost = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    bool wasFiltered = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    callFunction(context, impl, &TestRunner::setStatisticsCrossSiteLoadWithLinkDecoration, fromHost.get(), toHost.get(), wasFiltered);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsTimeToLiveUserInteraction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto seconds = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    callFunction(context, impl, &TestRunner::setStatisticsTimeToLiveUserInteraction, seconds);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsNotifyObserver(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::statisticsNotifyObserver, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::statisticsProcessStatisticsAndDataRecords(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::statisticsProcessStatisticsAndDataRecords, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::statisticsUpdateCookieBlocking(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto completionHandler = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::statisticsUpdateCookieBlocking, completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsTimeAdvanceForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto value = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    callFunction(context, impl, &TestRunner::setStatisticsTimeAdvanceForTesting, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsIsRunningTest(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setStatisticsIsRunningTest, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsShouldClassifyResourcesBeforeDataRecordsRemoval(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setStatisticsShouldClassifyResourcesBeforeDataRecordsRemoval, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsMinimumTimeBetweenDataRecordsRemoval(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto seconds = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    callFunction(context, impl, &TestRunner::setStatisticsMinimumTimeBetweenDataRecordsRemoval, seconds);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsGrandfatheringTime(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto seconds = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    callFunction(context, impl, &TestRunner::setStatisticsGrandfatheringTime, seconds);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsMaxStatisticsEntries(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto entries = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &TestRunner::setStatisticsMaxStatisticsEntries, entries);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsPruneEntriesDownTo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto entries = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &TestRunner::setStatisticsPruneEntriesDownTo, entries);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsClearInMemoryAndPersistentStore(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::statisticsClearInMemoryAndPersistentStore, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsClearInMemoryAndPersistentStoreModifiedSinceHours(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hours = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::statisticsClearInMemoryAndPersistentStoreModifiedSinceHours, hours, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsClearThroughWebsiteDataRemoval(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::statisticsClearThroughWebsiteDataRemoval, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsDeleteCookiesForHost(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool includeHttpOnlyCookies = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::statisticsDeleteCookiesForHost, hostName.get(), includeHttpOnlyCookies, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::isStatisticsHasLocalStorage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isStatisticsHasLocalStorage, hostName.get()));
}

JSValueRef JSTestRunner::setStatisticsCacheMaxAgeCap(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto seconds = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    callFunction(context, impl, &TestRunner::setStatisticsCacheMaxAgeCap, seconds);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsResetToConsistentState(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto completionHandler = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::statisticsResetToConsistentState, completionHandler);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::hasStatisticsIsolatedSession(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::hasStatisticsIsolatedSession, hostName.get()));
}

JSValueRef JSTestRunner::setStatisticsShouldDowngradeReferrer(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsShouldDowngradeReferrer, value, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsShouldBlockThirdPartyCookies(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    bool onlyOnSitesWithoutUserInteraction = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    bool onlyUnpartitionedCookies = argumentCount > 3 && JSValueToBoolean(context, arguments[3]);
    callFunction(context, impl, &TestRunner::setStatisticsShouldBlockThirdPartyCookies, value, callback, onlyOnSitesWithoutUserInteraction, onlyUnpartitionedCookies);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setStatisticsFirstPartyWebsiteDataRemovalMode(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setStatisticsFirstPartyWebsiteDataRemovalMode, value, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsSetToSameSiteStrictCookies(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto hostName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::statisticsSetToSameSiteStrictCookies, hostName.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsSetFirstPartyHostCNAMEDomain(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto firstPartyURLString = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto cnameURLString = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::statisticsSetFirstPartyHostCNAMEDomain, firstPartyURLString.get(), cnameURLString.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::statisticsSetThirdPartyCNAMEDomain(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto cnameURLString = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::statisticsSetThirdPartyCNAMEDomain, cnameURLString.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::loadedSubresourceDomains(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::loadedSubresourceDomains, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::reloadFromOrigin(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::reloadFromOrigin);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::installTextDidChangeInTextFieldCallback(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::installTextDidChangeInTextFieldCallback, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::installTextFieldDidBeginEditingCallback(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::installTextFieldDidBeginEditingCallback, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::installTextFieldDidEndEditingCallback(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::installTextFieldDidEndEditingCallback, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::getAllStorageAccessEntries(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::getAllStorageAccessEntries, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setRequestStorageAccessThrowsExceptionUntilReload(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool enabled = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setRequestStorageAccessThrowsExceptionUntilReload, enabled);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setOpenPanelFiles(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto filesArray = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setOpenPanelFiles, filesArray);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setOpenPanelFilesMediaIcon(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto mediaIcon = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setOpenPanelFilesMediaIcon, mediaIcon);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setShouldDismissJavaScriptAlertsAsynchronously(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setShouldDismissJavaScriptAlertsAsynchronously, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::abortModal(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::abortModal);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setCustomUserAgent(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto userAgent = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setCustomUserAgent, userAgent.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::terminateGPUProcess(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::terminateGPUProcess);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::terminateNetworkProcess(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::terminateNetworkProcess);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::terminateServiceWorkers(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::terminateServiceWorkers);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setUseSeparateServiceWorkerProcess(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setUseSeparateServiceWorkerProcess, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::removeAllSessionCredentials(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::removeAllSessionCredentials, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::getApplicationManifestThen(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::getApplicationManifestThen, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::installFakeHelvetica(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto configuration = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::installFakeHelvetica, configuration.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::addMockCameraDevice(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto persistentId = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto label = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto properties = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::addMockCameraDevice, persistentId.get(), label.get(), properties);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::addMockMicrophoneDevice(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto persistentId = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto label = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto properties = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::addMockMicrophoneDevice, persistentId.get(), label.get(), properties);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::addMockScreenDevice(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto persistentId = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto label = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::addMockScreenDevice, persistentId.get(), label.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearMockMediaDevices(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearMockMediaDevices);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::removeMockMediaDevice(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto persistentId = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::removeMockMediaDevice, persistentId.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setMockMediaDeviceIsEphemeral(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto persistentId = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool isEphemeral = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    callFunction(context, impl, &TestRunner::setMockMediaDeviceIsEphemeral, persistentId.get(), isEphemeral);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::resetMockMediaDevices(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::resetMockMediaDevices);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setMockCameraOrientation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto orientation = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto persistentId = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setMockCameraOrientation, orientation, persistentId.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::isMockRealtimeMediaSourceCenterEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isMockRealtimeMediaSourceCenterEnabled));
}

JSValueRef JSTestRunner::setMockCaptureDevicesInterrupted(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool isCameraInterrupted = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    bool isMicrophoneInterrupted = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    callFunction(context, impl, &TestRunner::setMockCaptureDevicesInterrupted, isCameraInterrupted, isMicrophoneInterrupted);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::triggerMockCaptureConfigurationChange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool forCamera = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    bool forMicrophone = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    bool forDisplay = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    callFunction(context, impl, &TestRunner::triggerMockCaptureConfigurationChange, forCamera, forMicrophone, forDisplay);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setCaptureState(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool cameraState = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    bool microphoneState = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    bool displayState = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    callFunction(context, impl, &TestRunner::setCaptureState, cameraState, microphoneState, displayState);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::hasAppBoundSession(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::hasAppBoundSession));
}

JSValueRef JSTestRunner::clearAppBoundSession(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearAppBoundSession);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setAppBoundDomains(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto originsArray = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setAppBoundDomains, originsArray, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::didLoadAppInitiatedRequest(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::didLoadAppInitiatedRequest));
}

JSValueRef JSTestRunner::didLoadNonAppInitiatedRequest(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::didLoadNonAppInitiatedRequest));
}

JSValueRef JSTestRunner::setManagedDomains(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto originsArray = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    auto callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::setManagedDomains, originsArray, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::injectUserScript(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto string = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::injectUserScript, string.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setServiceWorkerFetchTimeout(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto seconds = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    callFunction(context, impl, &TestRunner::setServiceWorkerFetchTimeout, seconds);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::addTestKeyToKeychain(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto privateKeyBase64 = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto attrLabel = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto applicationTagBase64 = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::addTestKeyToKeychain, privateKeyBase64.get(), attrLabel.get(), applicationTagBase64.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::cleanUpKeychain(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attrLabel = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto applicationLabelBase64 = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::cleanUpKeychain, attrLabel.get(), applicationLabelBase64.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::keyExistsInKeychain(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attrLabel = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto applicationLabelBase64 = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::keyExistsInKeychain, attrLabel.get(), applicationLabelBase64.get()));
}

JSValueRef JSTestRunner::clearMemoryCache(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearMemoryCache);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearPrivateClickMeasurement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearPrivateClickMeasurement);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::clearPrivateClickMeasurementsThroughWebsiteDataRemoval(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::clearPrivateClickMeasurementsThroughWebsiteDataRemoval);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPrivateClickMeasurementOverrideTimerForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setPrivateClickMeasurementOverrideTimerForTesting, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::markAttributedPrivateClickMeasurementsAsExpiredForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::markAttributedPrivateClickMeasurementsAsExpiredForTesting);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPrivateClickMeasurementEphemeralMeasurementForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setPrivateClickMeasurementEphemeralMeasurementForTesting, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::simulatePrivateClickMeasurementSessionRestart(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::simulatePrivateClickMeasurementSessionRestart);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPrivateClickMeasurementTokenPublicKeyURLForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto url = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setPrivateClickMeasurementTokenPublicKeyURLForTesting, url.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPrivateClickMeasurementTokenSignatureURLForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto url = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setPrivateClickMeasurementTokenSignatureURLForTesting, url.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPrivateClickMeasurementAttributionReportURLsForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto sourceURLString = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto destinationURLString = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setPrivateClickMeasurementAttributionReportURLsForTesting, sourceURLString.get(), destinationURLString.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::markPrivateClickMeasurementsAsExpiredForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::markPrivateClickMeasurementsAsExpiredForTesting);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPrivateClickMeasurementFraudPreventionValuesForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto unlinkableToken = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto secretToken = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto signature = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    auto keyID = argumentCount > 3 ? createJSString(context, arguments[3]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setPrivateClickMeasurementFraudPreventionValuesForTesting, unlinkableToken.get(), secretToken.get(), signature.get(), keyID.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setPrivateClickMeasurementAppBundleIDForTesting(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto appBundleID = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::setPrivateClickMeasurementAppBundleIDForTesting, appBundleID.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setIsSpeechRecognitionPermissionGranted(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setIsSpeechRecognitionPermissionGranted, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setIsMediaKeySystemPermissionGranted(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &TestRunner::setIsMediaKeySystemPermissionGranted, value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::takeViewPortSnapshot(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::takeViewPortSnapshot, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::generateTestReport(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto message = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto group = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &TestRunner::generateTestReport, message.get(), group.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::getAndClearReportedWindowProxyAccessDomains(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &TestRunner::getAndClearReportedWindowProxyAccessDomains, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::flushConsoleLogs(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::flushConsoleLogs, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::updatePresentation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::updatePresentation, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::scrollDuringEnterFullscreen(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::scrollDuringEnterFullscreen);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::waitBeforeFinishingFullscreenExit(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::waitBeforeFinishingFullscreenExit);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::finishFullscreenExit(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::finishFullscreenExit);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::requestExitFullscreenFromUIProcess(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &TestRunner::requestExitFullscreenFromUIProcess);

    return JSValueMakeUndefined(context);
}

JSValueRef JSTestRunner::setObscuredContentInsets(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto top = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    auto right = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : double();
    auto bottom = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : double();
    auto left = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : double();
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::setObscuredContentInsets, top, right, bottom, left, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::setPageScaleFactor(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto scaleFactor = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    auto x = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto y = argumentCount > 2 ? clampTo<int32_t>(JSValueToNumber(context, arguments[2], nullptr)) : int32_t();
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::setPageScaleFactor, scaleFactor, x, y, resolveFunction);

    return promise;
}

JSValueRef JSTestRunner::setResourceMonitorList(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto rulesText = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &TestRunner::setResourceMonitorList, rulesText.get(), resolveFunction);

    return promise;
}

// Attributes

JSValueRef JSTestRunner::isWebKit2(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isWebKit2));
}

JSValueRef JSTestRunner::isIOSFamily(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isIOSFamily));
}

JSValueRef JSTestRunner::isMac(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isMac));
}

JSValueRef JSTestRunner::isKeyboardImmediatelyAvailable(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isKeyboardImmediatelyAvailable));
}

JSValueRef JSTestRunner::keyboardAppearsOverContent(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::keyboardAppearsOverContent));
}

JSValueRef JSTestRunner::haveSecureCodingRequest(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::haveSecureCodingRequest));
}

JSValueRef JSTestRunner::haveSecureCodingDataDetectors(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::haveSecureCodingDataDetectors));
}

JSValueRef JSTestRunner::timeout(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::timeout));
}

JSValueRef JSTestRunner::globalFlag(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::globalFlag));
}

bool JSTestRunner::setGlobalFlag(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return false;

    impl->setGlobalFlag(JSValueToBoolean(context, value));

    return true;
}

JSValueRef JSTestRunner::databaseDefaultQuota(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::databaseDefaultQuota));
}

bool JSTestRunner::setDatabaseDefaultQuota(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return false;

    impl->setDatabaseDefaultQuota(JSValueToNumber(context, value, nullptr));

    return true;
}

JSValueRef JSTestRunner::databaseMaxQuota(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::databaseMaxQuota));
}

bool JSTestRunner::setDatabaseMaxQuota(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return false;

    impl->setDatabaseMaxQuota(JSValueToNumber(context, value, nullptr));

    return true;
}

JSValueRef JSTestRunner::inspectorTestStubURL(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &TestRunner::inspectorTestStubURL).get());
}

JSValueRef JSTestRunner::didReceiveServerRedirectForProvisionalNavigation(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::didReceiveServerRedirectForProvisionalNavigation));
}

JSValueRef JSTestRunner::isDoingMediaCapture(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::isDoingMediaCapture));
}

JSValueRef JSTestRunner::secureEventInputIsEnabled(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::secureEventInputIsEnabled));
}

JSValueRef JSTestRunner::serverTrustEvaluationCallbackCallsCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::serverTrustEvaluationCallbackCallsCount));
}

JSValueRef JSTestRunner::didCancelClientRedirect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::didCancelClientRedirect));
}

JSValueRef JSTestRunner::userScriptInjectedCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &TestRunner::userScriptInjectedCount));
}

JSValueRef JSTestRunner::canModifyResourceMonitorList(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    TestRunner* impl = toTestRunner(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &TestRunner::canModifyResourceMonitorList));
}

} // namespace WTR

