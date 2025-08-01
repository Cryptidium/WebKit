/*
 * Copyright (C) 2015-2018 Apple Inc. All rights reserved.
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
#include "JSUIScriptController.h"
#include "UIScriptController.h"
#include <JavaScriptCore/JSRetainPtr.h>
#include <wtf/GetPtr.h>

namespace WTR {

UIScriptController* toUIScriptController(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSUIScriptController::uIScriptControllerClass() || !JSValueIsObjectOfClass(context, value, JSUIScriptController::uIScriptControllerClass()))
        return 0;
    return static_cast<UIScriptController*>(JSWrapper::unwrap(context, value));
}

JSClassRef JSUIScriptController::uIScriptControllerClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "UIScriptController";
        definition.parentClass = 0;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }
    return jsClass;
}

const JSStaticFunction* JSUIScriptController::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "doAsyncTask", doAsyncTask, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "uiScriptComplete", uiScriptComplete, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "doAfterPresentationUpdate", doAfterPresentationUpdate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "doAfterNextStablePresentationUpdate", doAfterNextStablePresentationUpdate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ensurePositionInformationIsUpToDateAt", ensurePositionInformationIsUpToDateAt, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "doAfterVisibleContentRectUpdate", doAfterVisibleContentRectUpdate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "doAfterNextVisibleContentRectAndStablePresentationUpdate", doAfterNextVisibleContentRectAndStablePresentationUpdate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "doAfterDoubleTapDelay", doAfterDoubleTapDelay, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "simulateAccessibilitySettingsChangeNotification", simulateAccessibilitySettingsChangeNotification, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "touchDownAtPoint", touchDownAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "liftUpAtPoint", liftUpAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "singleTapAtPoint", singleTapAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "singleTapAtPointWithModifiers", singleTapAtPointWithModifiers, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "twoFingerSingleTapAtPoint", twoFingerSingleTapAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "doubleTapAtPoint", doubleTapAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dragFromPointToPoint", dragFromPointToPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "activateAtPoint", activateAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "longPressAtPoint", longPressAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stylusDownAtPoint", stylusDownAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stylusMoveToPoint", stylusMoveToPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stylusUpAtPoint", stylusUpAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stylusTapAtPoint", stylusTapAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stylusTapAtPointWithModifiers", stylusTapAtPointWithModifiers, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "enterText", enterText, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "typeCharacterUsingHardwareKeyboard", typeCharacterUsingHardwareKeyboard, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keyDown", keyDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "toggleCapsLock", toggleCapsLock, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setContinuousSpellCheckingEnabled", setContinuousSpellCheckingEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setSpellCheckerResults", setSpellCheckerResults, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rawKeyDown", rawKeyDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rawKeyUp", rawKeyUp, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "sendEventStream", sendEventStream, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "beginBackSwipe", beginBackSwipe, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "completeBackSwipe", completeBackSwipe, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "playBackEventStream", playBackEventStream, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dismissFormAccessoryView", dismissFormAccessoryView, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dismissFilePicker", dismissFilePicker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectFormAccessoryPickerRow", selectFormAccessoryPickerRow, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectFormAccessoryHasCheckedItemAtRow", selectFormAccessoryHasCheckedItemAtRow, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setTimePickerValue", setTimePickerValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "chooseDateTimePickerValue", chooseDateTimePickerValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "activateDataListSuggestion", activateDataListSuggestion, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setSelectedColorForColorPicker", setSelectedColorForColorPicker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keyboardAccessoryBarNext", keyboardAccessoryBarNext, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keyboardAccessoryBarPrevious", keyboardAccessoryBarPrevious, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectWordForReplacement", selectWordForReplacement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "applyAutocorrection", applyAutocorrection, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "contentsOfUserInterfaceItem", contentsOfUserInterfaceItem, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rectForMenuAction", rectForMenuAction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "chooseMenuAction", chooseMenuAction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dismissMenu", dismissMenu, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "zoomToScale", zoomToScale, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setViewScale", setViewScale, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setMinimumEffectiveWidth", setMinimumEffectiveWidth, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAllowsViewportShrinkToFit", setAllowsViewportShrinkToFit, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setScrollViewKeyboardAvoidanceEnabled", setScrollViewKeyboardAvoidanceEnabled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAlwaysBounceVertical", setAlwaysBounceVertical, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAlwaysBounceHorizontal", setAlwaysBounceHorizontal, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "beginInteractiveObscuredInsetsChange", beginInteractiveObscuredInsetsChange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "endInteractiveObscuredInsetsChange", endInteractiveObscuredInsetsChange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setObscuredInsets", setObscuredInsets, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "becomeFirstResponder", becomeFirstResponder, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resignFirstResponder", resignFirstResponder, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "copyText", copyText, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "paste", paste, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollToOffset", scrollToOffset, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "immediateScrollToOffset", immediateScrollToOffset, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "immediateZoomToScale", immediateZoomToScale, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "immediateScrollElementAtContentPointToOffset", immediateScrollElementAtContentPointToOffset, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setDefaultCalendarType", setDefaultCalendarType, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setKeyboardInputModeIdentifier", setKeyboardInputModeIdentifier, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "replaceTextAtRange", replaceTextAtRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mayContainEditableElementsInRect", mayContainEditableElementsInRect, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "propertiesOfLayerWithID", propertiesOfLayerWithID, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollbarStateForScrollingNodeID", scrollbarStateForScrollingNodeID, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "retrieveSpeakSelectionContent", retrieveSpeakSelectionContent, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "simulateRotation", simulateRotation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "simulateRotationLikeSafari", simulateRotationLikeSafari, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "findString", findString, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "presentFindNavigator", presentFindNavigator, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dismissFindNavigator", dismissFindNavigator, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeViewFromWindow", removeViewFromWindow, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addViewToWindow", addViewToWindow, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resizeWindowTo", resizeWindowTo, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installTapGestureOnWindow", installTapGestureOnWindow, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "overridePreference", overridePreference, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setSafeAreaInsets", setSafeAreaInsets, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setAppAccentColor", setAppAccentColor, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "firstResponderSuppressionForWebView", firstResponderSuppressionForWebView, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "makeWindowContentViewFirstResponder", makeWindowContentViewFirstResponder, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setHardwareKeyboardAttached", setHardwareKeyboardAttached, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setWebViewEditable", setWebViewEditable, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "cancelFixedColorExtensionFadeAnimations", cancelFixedColorExtensionFadeAnimations, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "cookiesForDomain", cookiesForDomain, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setWebViewAllowsMagnification", setWebViewAllowsMagnification, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attachmentInfo", attachmentInfo, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "insertAttachmentForFilePath", insertAttachmentForFilePath, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dismissContactPickerWithContacts", dismissContactPickerWithContacts, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "installFakeMachineReadableCodeResultsForImageAnalysis", installFakeMachineReadableCodeResultsForImageAnalysis, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setInlinePrediction", setInlinePrediction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "acceptInlinePrediction", acceptInlinePrediction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "requestTextExtraction", requestTextExtraction, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "requestRenderedTextForFrontmostTarget", requestRenderedTextForFrontmostTarget, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "adjustVisibilityForFrontmostTarget", adjustVisibilityForFrontmostTarget, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resetVisibilityAdjustments", resetVisibilityAdjustments, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "frontmostViewAtPoint", frontmostViewAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0 }
    };
    return functions;
}

const JSStaticValue* JSUIScriptController::staticValues()
{
    static const JSStaticValue values[] = {
        { "keyboardWillHideCount", keyboardWillHideCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keyboardIsAutomaticallyShifted", keyboardIsAutomaticallyShifted, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keyboardUpdateForChangedSelectionCount", keyboardUpdateForChangedSelectionCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isAnimatingDragCancel", isAnimatingDragCancel, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectionCaretBackgroundColor", selectionCaretBackgroundColor, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "tapHighlightViewRect", tapHighlightViewRect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "filePickerAcceptedTypeIdentifiers", filePickerAcceptedTypeIdentifiers, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textContentType", textContentType, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "didStartFormControlInteractionCallback", didStartFormControlInteractionCallback, setDidStartFormControlInteractionCallback, kJSPropertyAttributeDontDelete },
        { "didEndFormControlInteractionCallback", didEndFormControlInteractionCallback, setDidEndFormControlInteractionCallback, kJSPropertyAttributeDontDelete },
        { "didShowContextMenuCallback", didShowContextMenuCallback, setDidShowContextMenuCallback, kJSPropertyAttributeDontDelete },
        { "didDismissContextMenuCallback", didDismissContextMenuCallback, setDidDismissContextMenuCallback, kJSPropertyAttributeDontDelete },
        { "isShowingContextMenu", isShowingContextMenu, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectFormPopoverTitle", selectFormPopoverTitle, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "formInputLabel", formInputLabel, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "timePickerValueHour", timePickerValueHour, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "timePickerValueMinute", timePickerValueMinute, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isShowingDateTimePicker", isShowingDateTimePicker, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dateTimePickerValue", dateTimePickerValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isShowingDataListSuggestions", isShowingDataListSuggestions, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "didShowKeyboardCallback", didShowKeyboardCallback, setDidShowKeyboardCallback, kJSPropertyAttributeDontDelete },
        { "didHideKeyboardCallback", didHideKeyboardCallback, setDidHideKeyboardCallback, kJSPropertyAttributeDontDelete },
        { "isShowingKeyboard", isShowingKeyboard, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hasInputSession", hasInputSession, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "willStartInputSessionCallback", willStartInputSessionCallback, setWillStartInputSessionCallback, kJSPropertyAttributeDontDelete },
        { "suppressSoftwareKeyboard", suppressSoftwareKeyboard, setSuppressSoftwareKeyboard, kJSPropertyAttributeDontDelete },
        { "windowIsKey", windowIsKey, setWindowIsKey, kJSPropertyAttributeDontDelete },
        { "didShowMenuCallback", didShowMenuCallback, setDidShowMenuCallback, kJSPropertyAttributeDontDelete },
        { "didHideMenuCallback", didHideMenuCallback, setDidHideMenuCallback, kJSPropertyAttributeDontDelete },
        { "isDismissingMenu", isDismissingMenu, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isShowingMenu", isShowingMenu, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "menuRect", menuRect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "contextMenuRect", contextMenuRect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "contextMenuPreviewRect", contextMenuPreviewRect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isShowingPopover", isShowingPopover, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isShowingFormValidationBubble", isShowingFormValidationBubble, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "willPresentPopoverCallback", willPresentPopoverCallback, setWillPresentPopoverCallback, kJSPropertyAttributeDontDelete },
        { "didDismissPopoverCallback", didDismissPopoverCallback, setDidDismissPopoverCallback, kJSPropertyAttributeDontDelete },
        { "willBeginZoomingCallback", willBeginZoomingCallback, setWillBeginZoomingCallback, kJSPropertyAttributeDontDelete },
        { "didEndZoomingCallback", didEndZoomingCallback, setDidEndZoomingCallback, kJSPropertyAttributeDontDelete },
        { "willCreateNewPageCallback", willCreateNewPageCallback, setWillCreateNewPageCallback, kJSPropertyAttributeDontDelete },
        { "isPresentingModally", isPresentingModally, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "pasteboardChangeCount", pasteboardChangeCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "contentOffsetX", contentOffsetX, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "contentOffsetY", contentOffsetY, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "adjustedContentInset", adjustedContentInset, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollUpdatesDisabled", scrollUpdatesDisabled, setScrollUpdatesDisabled, kJSPropertyAttributeDontDelete },
        { "didEndScrollingCallback", didEndScrollingCallback, setDidEndScrollingCallback, kJSPropertyAttributeDontDelete },
        { "zoomScale", zoomScale, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "minimumZoomScale", minimumZoomScale, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "maximumZoomScale", maximumZoomScale, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isZoomingOrScrolling", isZoomingOrScrolling, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stableStateOverride", stableStateOverride, setStableStateOverride, kJSPropertyAttributeDontDelete },
        { "contentVisibleRect", contentVisibleRect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectionStartGrabberViewRect", selectionStartGrabberViewRect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectionEndGrabberViewRect", selectionEndGrabberViewRect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectionEndGrabberViewShapePathDescription", selectionEndGrabberViewShapePathDescription, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectionCaretViewRect", selectionCaretViewRect, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectionCaretViewRectInGlobalCoordinates", selectionCaretViewRectInGlobalCoordinates, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectionRangeViewRects", selectionRangeViewRects, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "calendarType", calendarType, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "inputViewBounds", inputViewBounds, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollingTreeAsText", scrollingTreeAsText, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "uiViewTreeAsText", uiViewTreeAsText, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "caLayerTreeAsText", caLayerTreeAsText, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "accessibilitySpeakSelectionContent", accessibilitySpeakSelectionContent, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isWindowContentViewFirstResponder", isWindowContentViewFirstResponder, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isWebContentFirstResponder", isWebContentFirstResponder, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "fixedContainerEdgeColors", fixedContainerEdgeColors, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "didShowContactPickerCallback", didShowContactPickerCallback, setDidShowContactPickerCallback, kJSPropertyAttributeDontDelete },
        { "didHideContactPickerCallback", didHideContactPickerCallback, setDidHideContactPickerCallback, kJSPropertyAttributeDontDelete },
        { "isShowingContactPicker", isShowingContactPicker, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lastUndoLabel", lastUndoLabel, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "firstRedoLabel", firstRedoLabel, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "countOfUpdatesWithLayerChanges", countOfUpdatesWithLayerChanges, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "currentImageAnalysisRequestID", currentImageAnalysisRequestID, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0, 0 }
    };
    return values;
}

// Functions

JSValueRef JSUIScriptController::doAsyncTask(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->doAsyncTask(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::uiScriptComplete(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> result = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    impl->uiScriptComplete(result.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::doAfterPresentationUpdate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->doAfterPresentationUpdate(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::doAfterNextStablePresentationUpdate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->doAfterNextStablePresentationUpdate(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::ensurePositionInformationIsUpToDateAt(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->ensurePositionInformationIsUpToDateAt(x, y, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::doAfterVisibleContentRectUpdate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->doAfterVisibleContentRectUpdate(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::doAfterNextVisibleContentRectAndStablePresentationUpdate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->doAfterNextVisibleContentRectAndStablePresentationUpdate(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::doAfterDoubleTapDelay(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->doAfterDoubleTapDelay(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::simulateAccessibilitySettingsChangeNotification(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->simulateAccessibilitySettingsChangeNotification(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::touchDownAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double touchCount = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    JSValueRef callback = argumentCount > 3 ? arguments[3] : JSValueMakeUndefined(context);
    impl->touchDownAtPoint(x, y, touchCount, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::liftUpAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double touchCount = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    JSValueRef callback = argumentCount > 3 ? arguments[3] : JSValueMakeUndefined(context);
    impl->liftUpAtPoint(x, y, touchCount, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::singleTapAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->singleTapAtPoint(x, y, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::singleTapAtPointWithModifiers(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef modifierArray = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    JSValueRef callback = argumentCount > 3 ? arguments[3] : JSValueMakeUndefined(context);
    impl->singleTapAtPointWithModifiers(x, y, modifierArray, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::twoFingerSingleTapAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->twoFingerSingleTapAtPoint(x, y, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::doubleTapAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double delay = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    JSValueRef callback = argumentCount > 3 ? arguments[3] : JSValueMakeUndefined(context);
    impl->doubleTapAtPoint(x, y, delay, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::dragFromPointToPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double startX = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double startY = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double endX = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double endY = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    double durationSeconds = argumentCount > 4 ? JSValueToNumber(context, arguments[4], nullptr) : 0;
    JSValueRef callback = argumentCount > 5 ? arguments[5] : JSValueMakeUndefined(context);
    impl->dragFromPointToPoint(startX, startY, endX, endY, durationSeconds, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::activateAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->activateAtPoint(x, y, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::longPressAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->longPressAtPoint(x, y, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::stylusDownAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double azimuthAngle = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double altitudeAngle = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    double pressure = argumentCount > 4 ? JSValueToNumber(context, arguments[4], nullptr) : 0;
    JSValueRef callback = argumentCount > 5 ? arguments[5] : JSValueMakeUndefined(context);
    impl->stylusDownAtPoint(x, y, azimuthAngle, altitudeAngle, pressure, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::stylusMoveToPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double azimuthAngle = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double altitudeAngle = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    double pressure = argumentCount > 4 ? JSValueToNumber(context, arguments[4], nullptr) : 0;
    JSValueRef callback = argumentCount > 5 ? arguments[5] : JSValueMakeUndefined(context);
    impl->stylusMoveToPoint(x, y, azimuthAngle, altitudeAngle, pressure, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::stylusUpAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->stylusUpAtPoint(x, y, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::stylusTapAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double azimuthAngle = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double altitudeAngle = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    double pressure = argumentCount > 4 ? JSValueToNumber(context, arguments[4], nullptr) : 0;
    JSValueRef callback = argumentCount > 5 ? arguments[5] : JSValueMakeUndefined(context);
    impl->stylusTapAtPoint(x, y, azimuthAngle, altitudeAngle, pressure, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::stylusTapAtPointWithModifiers(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double azimuthAngle = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double altitudeAngle = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    double pressure = argumentCount > 4 ? JSValueToNumber(context, arguments[4], nullptr) : 0;
    JSValueRef modifierArray = argumentCount > 5 ? arguments[5] : JSValueMakeUndefined(context);
    JSValueRef callback = argumentCount > 6 ? arguments[6] : JSValueMakeUndefined(context);
    impl->stylusTapAtPointWithModifiers(x, y, azimuthAngle, altitudeAngle, pressure, modifierArray, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::enterText(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> text = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    impl->enterText(text.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::typeCharacterUsingHardwareKeyboard(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> character = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->typeCharacterUsingHardwareKeyboard(character.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::keyDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> character = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSValueRef modifierArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->keyDown(character.get(), modifierArray);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::toggleCapsLock(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->toggleCapsLock(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setContinuousSpellCheckingEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool enabled = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->setContinuousSpellCheckingEnabled(enabled);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setSpellCheckerResults(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef results = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->setSpellCheckerResults(results);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::rawKeyDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> key = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    impl->rawKeyDown(key.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::rawKeyUp(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> key = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    impl->rawKeyUp(key.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::sendEventStream(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> eventsJSON = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->sendEventStream(eventsJSON.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::beginBackSwipe(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->beginBackSwipe(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::completeBackSwipe(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->completeBackSwipe(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::playBackEventStream(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> eventStream = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->playBackEventStream(eventStream.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::dismissFormAccessoryView(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->dismissFormAccessoryView();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::dismissFilePicker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->dismissFilePicker(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::selectFormAccessoryPickerRow(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double rowIndex = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    impl->selectFormAccessoryPickerRow(rowIndex);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::selectFormAccessoryHasCheckedItemAtRow(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double rowIndex = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    return JSValueMakeBoolean(context, impl->selectFormAccessoryHasCheckedItemAtRow(rowIndex));
}

JSValueRef JSUIScriptController::setTimePickerValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double hour = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double minute = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    impl->setTimePickerValue(hour, minute);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::chooseDateTimePickerValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->chooseDateTimePickerValue();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::activateDataListSuggestion(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double index = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->activateDataListSuggestion(index, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setSelectedColorForColorPicker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double red = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double green = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double blue = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    impl->setSelectedColorForColorPicker(red, green, blue);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::keyboardAccessoryBarNext(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->keyboardAccessoryBarNext();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::keyboardAccessoryBarPrevious(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->keyboardAccessoryBarPrevious();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::selectWordForReplacement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->selectWordForReplacement();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::applyAutocorrection(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> newString = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSRetainPtr<JSStringRef> oldString = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    bool underline = argumentCount > 3 && JSValueToBoolean(context, arguments[3]);
    impl->applyAutocorrection(newString.get(), oldString.get(), callback, underline);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::contentsOfUserInterfaceItem(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> interfaceItem = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return impl->contentsOfUserInterfaceItem(interfaceItem.get());
}

JSValueRef JSUIScriptController::rectForMenuAction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> action = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return impl->rectForMenuAction(action.get());
}

JSValueRef JSUIScriptController::chooseMenuAction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> action = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->chooseMenuAction(action.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::dismissMenu(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->dismissMenu();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::zoomToScale(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double scale = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->zoomToScale(scale, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setViewScale(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double scale = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    impl->setViewScale(scale);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setMinimumEffectiveWidth(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double effectiveWidth = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    impl->setMinimumEffectiveWidth(effectiveWidth);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setAllowsViewportShrinkToFit(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool allows = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->setAllowsViewportShrinkToFit(allows);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setScrollViewKeyboardAvoidanceEnabled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool enabled = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->setScrollViewKeyboardAvoidanceEnabled(enabled);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setAlwaysBounceVertical(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->setAlwaysBounceVertical(value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setAlwaysBounceHorizontal(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool value = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->setAlwaysBounceHorizontal(value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::beginInteractiveObscuredInsetsChange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->beginInteractiveObscuredInsetsChange();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::endInteractiveObscuredInsetsChange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->endInteractiveObscuredInsetsChange();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setObscuredInsets(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double top = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double right = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double bottom = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double left = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    impl->setObscuredInsets(top, right, bottom, left);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::becomeFirstResponder(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->becomeFirstResponder();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::resignFirstResponder(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->resignFirstResponder();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::copyText(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> text = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    impl->copyText(text.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::paste(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->paste();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::scrollToOffset(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    ScrollToOptions* options = argumentCount > 2 ? toScrollToOptions(context, arguments[2]) : 0;
    impl->scrollToOffset(x, y, options);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::immediateScrollToOffset(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    ScrollToOptions* options = argumentCount > 2 ? toScrollToOptions(context, arguments[2]) : 0;
    impl->immediateScrollToOffset(x, y, options);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::immediateZoomToScale(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double scale = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    impl->immediateZoomToScale(scale);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::immediateScrollElementAtContentPointToOffset(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double xOffset = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double yOffset = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    impl->immediateScrollElementAtContentPointToOffset(x, y, xOffset, yOffset);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setDefaultCalendarType(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> calendarIdentifier = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSRetainPtr<JSStringRef> localeIdentifier = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    impl->setDefaultCalendarType(calendarIdentifier.get(), localeIdentifier.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setKeyboardInputModeIdentifier(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> identifier = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    impl->setKeyboardInputModeIdentifier(identifier.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::replaceTextAtRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> text = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    double location = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double length = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    impl->replaceTextAtRange(text.get(), location, length);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::mayContainEditableElementsInRect(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double width = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double height = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    return JSValueMakeBoolean(context, impl->mayContainEditableElementsInRect(x, y, width, height));
}

JSValueRef JSUIScriptController::propertiesOfLayerWithID(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double layerID = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    return impl->propertiesOfLayerWithID(layerID);
}

JSValueRef JSUIScriptController::scrollbarStateForScrollingNodeID(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double scrollingNodeID = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double processID = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    bool isVertical = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    return makeValue(context, impl->scrollbarStateForScrollingNodeID(scrollingNodeID, processID, isVertical).get());
}

JSValueRef JSUIScriptController::retrieveSpeakSelectionContent(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->retrieveSpeakSelectionContent(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::simulateRotation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    DeviceOrientation* orientation = argumentCount > 0 ? toDeviceOrientation(context, arguments[0]) : 0;
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->simulateRotation(orientation, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::simulateRotationLikeSafari(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    DeviceOrientation* orientation = argumentCount > 0 ? toDeviceOrientation(context, arguments[0]) : 0;
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->simulateRotationLikeSafari(orientation, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::findString(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> string = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    double options = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double maxCount = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    impl->findString(string.get(), options, maxCount);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::presentFindNavigator(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->presentFindNavigator();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::dismissFindNavigator(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->dismissFindNavigator();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::removeViewFromWindow(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->removeViewFromWindow(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::addViewToWindow(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->addViewToWindow(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::resizeWindowTo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double width = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double height = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    impl->resizeWindowTo(width, height);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::installTapGestureOnWindow(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->installTapGestureOnWindow(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::overridePreference(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> preference = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSRetainPtr<JSStringRef> value = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    impl->overridePreference(preference.get(), value.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setSafeAreaInsets(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double top = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double right = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double bottom = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    double left = argumentCount > 3 ? JSValueToNumber(context, arguments[3], nullptr) : 0;
    impl->setSafeAreaInsets(top, right, bottom, left);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setAppAccentColor(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double red = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double green = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    double blue = argumentCount > 2 ? JSValueToNumber(context, arguments[2], nullptr) : 0;
    impl->setAppAccentColor(red, green, blue);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::firstResponderSuppressionForWebView(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool shouldSuppress = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->firstResponderSuppressionForWebView(shouldSuppress);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::makeWindowContentViewFirstResponder(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->makeWindowContentViewFirstResponder();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setHardwareKeyboardAttached(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool attached = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->setHardwareKeyboardAttached(attached);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setWebViewEditable(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool editable = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->setWebViewEditable(editable);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::cancelFixedColorExtensionFadeAnimations(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->cancelFixedColorExtensionFadeAnimations();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::cookiesForDomain(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> domain = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSValueRef callback = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    impl->cookiesForDomain(domain.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setWebViewAllowsMagnification(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    bool allowsMagnification = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    impl->setWebViewAllowsMagnification(allowsMagnification);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::attachmentInfo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> attachmentIdentifier = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return impl->attachmentInfo(attachmentIdentifier.get());
}

JSValueRef JSUIScriptController::insertAttachmentForFilePath(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> filePath = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    JSRetainPtr<JSStringRef> contentType = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->insertAttachmentForFilePath(filePath.get(), contentType.get(), callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::dismissContactPickerWithContacts(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef contacts = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->dismissContactPickerWithContacts(contacts);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::installFakeMachineReadableCodeResultsForImageAnalysis(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->installFakeMachineReadableCodeResultsForImageAnalysis();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::setInlinePrediction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSRetainPtr<JSStringRef> text = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    double startIndex = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    impl->setInlinePrediction(text.get(), startIndex);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::acceptInlinePrediction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(argumentCount);
    UNUSED_VARIABLE(arguments);
    UNUSED_VARIABLE(exception);
    impl->acceptInlinePrediction();

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::requestTextExtraction(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    TextExtractionOptions* options = argumentCount > 1 ? toTextExtractionOptions(context, arguments[1]) : 0;
    impl->requestTextExtraction(callback, options);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::requestRenderedTextForFrontmostTarget(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->requestRenderedTextForFrontmostTarget(x, y, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::adjustVisibilityForFrontmostTarget(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    JSValueRef callback = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    impl->adjustVisibilityForFrontmostTarget(x, y, callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::resetVisibilityAdjustments(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    JSValueRef callback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    impl->resetVisibilityAdjustments(callback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSUIScriptController::frontmostViewAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UIScriptController* impl = toUIScriptController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    UNUSED_VARIABLE(exception);
    double x = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : 0;
    double y = argumentCount > 1 ? JSValueToNumber(context, arguments[1], nullptr) : 0;
    return makeValue(context, impl->frontmostViewAtPoint(x, y).get());
}

// Attributes

JSValueRef JSUIScriptController::keyboardWillHideCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->keyboardWillHideCount());
}

JSValueRef JSUIScriptController::keyboardIsAutomaticallyShifted(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->keyboardIsAutomaticallyShifted());
}

JSValueRef JSUIScriptController::keyboardUpdateForChangedSelectionCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->keyboardUpdateForChangedSelectionCount());
}

JSValueRef JSUIScriptController::isAnimatingDragCancel(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isAnimatingDragCancel());
}

JSValueRef JSUIScriptController::selectionCaretBackgroundColor(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->selectionCaretBackgroundColor().get());
}

JSValueRef JSUIScriptController::tapHighlightViewRect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->tapHighlightViewRect();
}

JSValueRef JSUIScriptController::filePickerAcceptedTypeIdentifiers(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->filePickerAcceptedTypeIdentifiers();
}

JSValueRef JSUIScriptController::textContentType(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->textContentType().get());
}

JSValueRef JSUIScriptController::didStartFormControlInteractionCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didStartFormControlInteractionCallback();
}

bool JSUIScriptController::setDidStartFormControlInteractionCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidStartFormControlInteractionCallback(value);

    return true;
}

JSValueRef JSUIScriptController::didEndFormControlInteractionCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didEndFormControlInteractionCallback();
}

bool JSUIScriptController::setDidEndFormControlInteractionCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidEndFormControlInteractionCallback(value);

    return true;
}

JSValueRef JSUIScriptController::didShowContextMenuCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didShowContextMenuCallback();
}

bool JSUIScriptController::setDidShowContextMenuCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidShowContextMenuCallback(value);

    return true;
}

JSValueRef JSUIScriptController::didDismissContextMenuCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didDismissContextMenuCallback();
}

bool JSUIScriptController::setDidDismissContextMenuCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidDismissContextMenuCallback(value);

    return true;
}

JSValueRef JSUIScriptController::isShowingContextMenu(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isShowingContextMenu());
}

JSValueRef JSUIScriptController::selectFormPopoverTitle(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->selectFormPopoverTitle().get());
}

JSValueRef JSUIScriptController::formInputLabel(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->formInputLabel().get());
}

JSValueRef JSUIScriptController::timePickerValueHour(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->timePickerValueHour());
}

JSValueRef JSUIScriptController::timePickerValueMinute(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->timePickerValueMinute());
}

JSValueRef JSUIScriptController::isShowingDateTimePicker(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isShowingDateTimePicker());
}

JSValueRef JSUIScriptController::dateTimePickerValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->dateTimePickerValue());
}

JSValueRef JSUIScriptController::isShowingDataListSuggestions(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isShowingDataListSuggestions());
}

JSValueRef JSUIScriptController::didShowKeyboardCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didShowKeyboardCallback();
}

bool JSUIScriptController::setDidShowKeyboardCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidShowKeyboardCallback(value);

    return true;
}

JSValueRef JSUIScriptController::didHideKeyboardCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didHideKeyboardCallback();
}

bool JSUIScriptController::setDidHideKeyboardCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidHideKeyboardCallback(value);

    return true;
}

JSValueRef JSUIScriptController::isShowingKeyboard(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isShowingKeyboard());
}

JSValueRef JSUIScriptController::hasInputSession(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->hasInputSession());
}

JSValueRef JSUIScriptController::willStartInputSessionCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->willStartInputSessionCallback();
}

bool JSUIScriptController::setWillStartInputSessionCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setWillStartInputSessionCallback(value);

    return true;
}

JSValueRef JSUIScriptController::suppressSoftwareKeyboard(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->suppressSoftwareKeyboard());
}

bool JSUIScriptController::setSuppressSoftwareKeyboard(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setSuppressSoftwareKeyboard(JSValueToNumber(context, value, nullptr));

    return true;
}

JSValueRef JSUIScriptController::windowIsKey(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->windowIsKey());
}

bool JSUIScriptController::setWindowIsKey(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setWindowIsKey(JSValueToBoolean(context, value));

    return true;
}

JSValueRef JSUIScriptController::didShowMenuCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didShowMenuCallback();
}

bool JSUIScriptController::setDidShowMenuCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidShowMenuCallback(value);

    return true;
}

JSValueRef JSUIScriptController::didHideMenuCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didHideMenuCallback();
}

bool JSUIScriptController::setDidHideMenuCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidHideMenuCallback(value);

    return true;
}

JSValueRef JSUIScriptController::isDismissingMenu(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isDismissingMenu());
}

JSValueRef JSUIScriptController::isShowingMenu(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isShowingMenu());
}

JSValueRef JSUIScriptController::menuRect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->menuRect();
}

JSValueRef JSUIScriptController::contextMenuRect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->contextMenuRect();
}

JSValueRef JSUIScriptController::contextMenuPreviewRect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->contextMenuPreviewRect();
}

JSValueRef JSUIScriptController::isShowingPopover(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isShowingPopover());
}

JSValueRef JSUIScriptController::isShowingFormValidationBubble(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isShowingFormValidationBubble());
}

JSValueRef JSUIScriptController::willPresentPopoverCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->willPresentPopoverCallback();
}

bool JSUIScriptController::setWillPresentPopoverCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setWillPresentPopoverCallback(value);

    return true;
}

JSValueRef JSUIScriptController::didDismissPopoverCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didDismissPopoverCallback();
}

bool JSUIScriptController::setDidDismissPopoverCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidDismissPopoverCallback(value);

    return true;
}

JSValueRef JSUIScriptController::willBeginZoomingCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->willBeginZoomingCallback();
}

bool JSUIScriptController::setWillBeginZoomingCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setWillBeginZoomingCallback(value);

    return true;
}

JSValueRef JSUIScriptController::didEndZoomingCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didEndZoomingCallback();
}

bool JSUIScriptController::setDidEndZoomingCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidEndZoomingCallback(value);

    return true;
}

JSValueRef JSUIScriptController::willCreateNewPageCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->willCreateNewPageCallback();
}

bool JSUIScriptController::setWillCreateNewPageCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setWillCreateNewPageCallback(value);

    return true;
}

JSValueRef JSUIScriptController::isPresentingModally(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isPresentingModally());
}

JSValueRef JSUIScriptController::pasteboardChangeCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->pasteboardChangeCount());
}

JSValueRef JSUIScriptController::contentOffsetX(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->contentOffsetX());
}

JSValueRef JSUIScriptController::contentOffsetY(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->contentOffsetY());
}

JSValueRef JSUIScriptController::adjustedContentInset(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->adjustedContentInset();
}

JSValueRef JSUIScriptController::scrollUpdatesDisabled(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->scrollUpdatesDisabled());
}

bool JSUIScriptController::setScrollUpdatesDisabled(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setScrollUpdatesDisabled(JSValueToBoolean(context, value));

    return true;
}

JSValueRef JSUIScriptController::didEndScrollingCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didEndScrollingCallback();
}

bool JSUIScriptController::setDidEndScrollingCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidEndScrollingCallback(value);

    return true;
}

JSValueRef JSUIScriptController::zoomScale(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->zoomScale());
}

JSValueRef JSUIScriptController::minimumZoomScale(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->minimumZoomScale());
}

JSValueRef JSUIScriptController::maximumZoomScale(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->maximumZoomScale());
}

JSValueRef JSUIScriptController::isZoomingOrScrolling(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isZoomingOrScrolling());
}

JSValueRef JSUIScriptController::stableStateOverride(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->stableStateOverride());
}

bool JSUIScriptController::setStableStateOverride(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setStableStateOverride(toOptionalBool(context, value));

    return true;
}

JSValueRef JSUIScriptController::contentVisibleRect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->contentVisibleRect();
}

JSValueRef JSUIScriptController::selectionStartGrabberViewRect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->selectionStartGrabberViewRect();
}

JSValueRef JSUIScriptController::selectionEndGrabberViewRect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->selectionEndGrabberViewRect();
}

JSValueRef JSUIScriptController::selectionEndGrabberViewShapePathDescription(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->selectionEndGrabberViewShapePathDescription();
}

JSValueRef JSUIScriptController::selectionCaretViewRect(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->selectionCaretViewRect();
}

JSValueRef JSUIScriptController::selectionCaretViewRectInGlobalCoordinates(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->selectionCaretViewRectInGlobalCoordinates();
}

JSValueRef JSUIScriptController::selectionRangeViewRects(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->selectionRangeViewRects();
}

JSValueRef JSUIScriptController::calendarType(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->calendarType();
}

JSValueRef JSUIScriptController::inputViewBounds(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->inputViewBounds();
}

JSValueRef JSUIScriptController::scrollingTreeAsText(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->scrollingTreeAsText().get());
}

JSValueRef JSUIScriptController::uiViewTreeAsText(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->uiViewTreeAsText().get());
}

JSValueRef JSUIScriptController::caLayerTreeAsText(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->caLayerTreeAsText().get());
}

JSValueRef JSUIScriptController::accessibilitySpeakSelectionContent(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->accessibilitySpeakSelectionContent().get());
}

JSValueRef JSUIScriptController::isWindowContentViewFirstResponder(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isWindowContentViewFirstResponder());
}

JSValueRef JSUIScriptController::isWebContentFirstResponder(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isWebContentFirstResponder());
}

JSValueRef JSUIScriptController::fixedContainerEdgeColors(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->fixedContainerEdgeColors();
}

JSValueRef JSUIScriptController::didShowContactPickerCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didShowContactPickerCallback();
}

bool JSUIScriptController::setDidShowContactPickerCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidShowContactPickerCallback(value);

    return true;
}

JSValueRef JSUIScriptController::didHideContactPickerCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return impl->didHideContactPickerCallback();
}

bool JSUIScriptController::setDidHideContactPickerCallback(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef value, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return false;

    impl->setDidHideContactPickerCallback(value);

    return true;
}

JSValueRef JSUIScriptController::isShowingContactPicker(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, impl->isShowingContactPicker());
}

JSValueRef JSUIScriptController::lastUndoLabel(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->lastUndoLabel().get());
}

JSValueRef JSUIScriptController::firstRedoLabel(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, impl->firstRedoLabel().get());
}

JSValueRef JSUIScriptController::countOfUpdatesWithLayerChanges(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->countOfUpdatesWithLayerChanges());
}

JSValueRef JSUIScriptController::currentImageAnalysisRequestID(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    UNUSED_VARIABLE(exception);
    UIScriptController* impl = toUIScriptController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, impl->currentImageAnalysisRequestID());
}

} // namespace WTR

