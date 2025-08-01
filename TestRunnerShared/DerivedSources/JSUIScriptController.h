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
#ifndef JSUIScriptController_h
#define JSUIScriptController_h

#include "JSWrapper.h"

namespace WTR {

class UIScriptController;

class JSUIScriptController : public JSWrapper {
public:
    static JSClassRef uIScriptControllerClass();

private:
    static const JSStaticFunction* staticFunctions();
    static const JSStaticValue* staticValues();

    // Functions

    static JSValueRef doAsyncTask(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef uiScriptComplete(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef doAfterPresentationUpdate(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef doAfterNextStablePresentationUpdate(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ensurePositionInformationIsUpToDateAt(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef doAfterVisibleContentRectUpdate(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef doAfterNextVisibleContentRectAndStablePresentationUpdate(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef doAfterDoubleTapDelay(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef simulateAccessibilitySettingsChangeNotification(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef touchDownAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef liftUpAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef singleTapAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef singleTapAtPointWithModifiers(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef twoFingerSingleTapAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef doubleTapAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef dragFromPointToPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef activateAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef longPressAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stylusDownAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stylusMoveToPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stylusUpAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stylusTapAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stylusTapAtPointWithModifiers(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef enterText(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef typeCharacterUsingHardwareKeyboard(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef keyDown(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef toggleCapsLock(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setContinuousSpellCheckingEnabled(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setSpellCheckerResults(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rawKeyDown(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rawKeyUp(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef sendEventStream(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef beginBackSwipe(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef completeBackSwipe(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef playBackEventStream(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef dismissFormAccessoryView(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef dismissFilePicker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectFormAccessoryPickerRow(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectFormAccessoryHasCheckedItemAtRow(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setTimePickerValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef chooseDateTimePickerValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef activateDataListSuggestion(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setSelectedColorForColorPicker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef keyboardAccessoryBarNext(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef keyboardAccessoryBarPrevious(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectWordForReplacement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef applyAutocorrection(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef contentsOfUserInterfaceItem(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rectForMenuAction(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef chooseMenuAction(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef dismissMenu(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef zoomToScale(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setViewScale(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setMinimumEffectiveWidth(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setAllowsViewportShrinkToFit(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setScrollViewKeyboardAvoidanceEnabled(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setAlwaysBounceVertical(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setAlwaysBounceHorizontal(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef beginInteractiveObscuredInsetsChange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef endInteractiveObscuredInsetsChange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setObscuredInsets(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef becomeFirstResponder(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef resignFirstResponder(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef copyText(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef paste(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollToOffset(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef immediateScrollToOffset(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef immediateZoomToScale(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef immediateScrollElementAtContentPointToOffset(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setDefaultCalendarType(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setKeyboardInputModeIdentifier(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef replaceTextAtRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef mayContainEditableElementsInRect(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef propertiesOfLayerWithID(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollbarStateForScrollingNodeID(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef retrieveSpeakSelectionContent(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef simulateRotation(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef simulateRotationLikeSafari(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef findString(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef presentFindNavigator(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef dismissFindNavigator(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef removeViewFromWindow(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef addViewToWindow(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef resizeWindowTo(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef installTapGestureOnWindow(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef overridePreference(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setSafeAreaInsets(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setAppAccentColor(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef firstResponderSuppressionForWebView(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef makeWindowContentViewFirstResponder(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setHardwareKeyboardAttached(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setWebViewEditable(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef cancelFixedColorExtensionFadeAnimations(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef cookiesForDomain(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setWebViewAllowsMagnification(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attachmentInfo(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef insertAttachmentForFilePath(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef dismissContactPickerWithContacts(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef installFakeMachineReadableCodeResultsForImageAnalysis(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setInlinePrediction(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef acceptInlinePrediction(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef requestTextExtraction(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef requestRenderedTextForFrontmostTarget(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef adjustVisibilityForFrontmostTarget(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef resetVisibilityAdjustments(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef frontmostViewAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);

    // Attributes

    static JSValueRef keyboardWillHideCount(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef keyboardIsAutomaticallyShifted(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef keyboardUpdateForChangedSelectionCount(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isAnimatingDragCancel(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectionCaretBackgroundColor(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef tapHighlightViewRect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef filePickerAcceptedTypeIdentifiers(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef textContentType(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef didStartFormControlInteractionCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidStartFormControlInteractionCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didEndFormControlInteractionCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidEndFormControlInteractionCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didShowContextMenuCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidShowContextMenuCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didDismissContextMenuCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidDismissContextMenuCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef isShowingContextMenu(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectFormPopoverTitle(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef formInputLabel(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef timePickerValueHour(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef timePickerValueMinute(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isShowingDateTimePicker(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef dateTimePickerValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isShowingDataListSuggestions(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef didShowKeyboardCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidShowKeyboardCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didHideKeyboardCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidHideKeyboardCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef isShowingKeyboard(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef hasInputSession(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef willStartInputSessionCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setWillStartInputSessionCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef suppressSoftwareKeyboard(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setSuppressSoftwareKeyboard(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef windowIsKey(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setWindowIsKey(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didShowMenuCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidShowMenuCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didHideMenuCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidHideMenuCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef isDismissingMenu(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isShowingMenu(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef menuRect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef contextMenuRect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef contextMenuPreviewRect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isShowingPopover(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isShowingFormValidationBubble(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef willPresentPopoverCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setWillPresentPopoverCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didDismissPopoverCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidDismissPopoverCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef willBeginZoomingCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setWillBeginZoomingCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didEndZoomingCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidEndZoomingCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef willCreateNewPageCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setWillCreateNewPageCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef isPresentingModally(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef pasteboardChangeCount(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef contentOffsetX(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef contentOffsetY(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef adjustedContentInset(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef scrollUpdatesDisabled(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setScrollUpdatesDisabled(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didEndScrollingCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidEndScrollingCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef zoomScale(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef minimumZoomScale(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef maximumZoomScale(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isZoomingOrScrolling(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef stableStateOverride(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setStableStateOverride(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef contentVisibleRect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectionStartGrabberViewRect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectionEndGrabberViewRect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectionEndGrabberViewShapePathDescription(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectionCaretViewRect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectionCaretViewRectInGlobalCoordinates(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectionRangeViewRects(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef calendarType(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef inputViewBounds(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef scrollingTreeAsText(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef uiViewTreeAsText(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef caLayerTreeAsText(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef accessibilitySpeakSelectionContent(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isWindowContentViewFirstResponder(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isWebContentFirstResponder(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef fixedContainerEdgeColors(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef didShowContactPickerCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidShowContactPickerCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef didHideContactPickerCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static bool setDidHideContactPickerCallback(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*);
    static JSValueRef isShowingContactPicker(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef lastUndoLabel(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef firstRedoLabel(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef countOfUpdatesWithLayerChanges(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef currentImageAnalysisRequestID(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
};
    
UIScriptController* toUIScriptController(JSContextRef, JSValueRef);

} // namespace WTR

#endif // JSUIScriptController_h
