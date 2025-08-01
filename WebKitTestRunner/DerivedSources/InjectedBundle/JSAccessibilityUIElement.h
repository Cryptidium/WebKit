/*
 * Copyright (C) 2011 Apple Inc. All rights reserved.
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
#ifndef JSAccessibilityUIElement_h
#define JSAccessibilityUIElement_h

#include "JSWrapper.h"

namespace WTR {

class AccessibilityUIElement;

class JSAccessibilityUIElement : public JSWrapper {
public:
    static JSClassRef accessibilityUIElementClass();

private:
    static const JSStaticFunction* staticFunctions();
    static const JSStaticValue* staticValues();

    // Functions

    static JSValueRef isEqual(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef elementAtPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef elementAtPointWithRemoteElement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef elementAtPointResolvingRemoteFrame(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef childAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef childAtIndexWithRemoteElement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef indexOfChild(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef linkedUIElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectedChildren(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectedChildAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setSelectedChild(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setSelectedChildAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef removeSelectionAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef clearSelectedChildren(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef titleUIElement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef parentElement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stringDescriptionOfAttributeValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stringAttributeValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef numberAttributeValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef uiElementArrayAttributeValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef uiElementAttributeValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef boolAttributeValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributeValueAsync(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setBoolAttributeValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isAttributeSupported(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isAttributeSettable(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isPressActionSupported(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isIncrementActionSupported(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isDecrementActionSupported(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setValue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef increment(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef decrement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef asyncIncrement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef asyncDecrement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef press(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef syncPress(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef showMenu(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef dismiss(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef allAttributes(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfChildren(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfLinkedUIElements(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfDocumentLinks(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef characterAtOffset(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef wordAtOffset(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef lineAtOffset(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef sentenceAtOffset(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfColumnHeaders(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfRowHeaders(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef columns(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfColumns(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfRows(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfVisibleCells(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributesOfHeader(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef cellForColumnAndRow(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectedRowAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef disclosedByRow(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef disclosedRowAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rowAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef indexInTable(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rowIndexRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef columnIndexRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rowCount(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef columnCount(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef columnHeaders(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rowHeaders(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectedCells(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef controllerElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ariaControlsElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ariaDescribedByElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef descriptionForElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef detailsElements(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ariaDetailsElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef detailsForElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef errorMessageElements(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ariaErrorMessageElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef errorMessageForElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef flowFromElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ariaFlowToElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ariaLabelledByElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef labelForElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ownerElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef ariaOwnsElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef parameterizedAttributeNames(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef lineForIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rangeForLine(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rangeForPosition(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef boundsForRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef boundsForRangeWithPagePosition(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stringForRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributedStringForRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributedStringForElement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributedStringRangeIsMisspelled(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef uiElementCountForSearchPredicate(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef uiElementForSearchPredicate(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectTextWithCriteria(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef searchTextWithCriteria(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef performTextOperation(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setSelectedTextRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollToMakeVisible(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollToGlobalPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollToMakeVisibleWithSubFocus(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef takeFocus(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollPageDown(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollPageUp(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollPageLeft(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef scrollPageRight(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef lineTextMarkerRangeForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rightLineTextMarkerRangeForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef leftLineTextMarkerRangeForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef previousLineStartTextMarkerForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef nextLineEndTextMarkerForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef lineIndexForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef styleTextMarkerRangeForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeForSearchPredicate(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef misspellingTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeForElement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeForMarkers(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeForUnorderedMarkers(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeForRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef selectedTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef resetSelectedTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef replaceTextInRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef insertText(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textInputMarkedTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef startTextMarkerForTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef endTextMarkerForTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef endTextMarkerForBounds(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef startTextMarkerForBounds(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerForPoint(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef previousTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef nextTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef accessibilityElementForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeForLine(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef stringForTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rectsForTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributedStringForTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributedStringForTextMarkerRangeWithDidSpellCheck(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributedStringForTextMarkerRangeWithOptions(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeLength(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef attributedStringForTextMarkerRangeContainsAttribute(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef indexForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isTextMarkerValid(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isTextMarkerRangeValid(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isTextMarkerNull(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerForIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setSelectedTextMarkerRange(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef leftWordTextMarkerRangeForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef rightWordTextMarkerRangeForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef previousWordStartTextMarkerForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef nextWordEndTextMarkerForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef paragraphTextMarkerRangeForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef previousParagraphStartTextMarkerForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef nextParagraphEndTextMarkerForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef sentenceTextMarkerRangeForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef previousSentenceStartTextMarkerForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef nextSentenceEndTextMarkerForTextMarker(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeMatchesTextNearMarkers(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerDebugDescription(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef textMarkerRangeDebugDescription(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef increaseTextSelection(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef decreaseTextSelection(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef linkedElement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef headerElementAtIndex(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assistiveTechnologySimulatedFocus(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef fieldsetAncestorElement(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef focusableAncestor(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef editableAncestor(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef highestEditableAncestor(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef addNotificationListener(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef removeNotificationListener(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);

    // Attributes

    static JSValueRef domIdentifier(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef activeElement(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef role(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef subrole(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef roleDescription(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef computedRoleString(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef title(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef description(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef language(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef helpText(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef valueDescription(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef brailleLabel(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef brailleRoleDescription(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef url(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef speakAs(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef liveRegionRelevant(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef liveRegionStatus(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef orientation(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef numberOfCharacters(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef insertionPointLineNumber(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectedText(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectedTextRange(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef intersectionWithSelectionRange(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef textInputMarkedRange(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef stringValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef dateValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef dateTimeValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef intValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef minValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef maxValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isAtomicLiveRegion(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isBusy(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isEnabled(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isRequired(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isFocused(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isFocusable(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isSelectable(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isSelected(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isSelectedOptionActive(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isMultiSelectable(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isExpanded(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isChecked(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef currentStateValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef sortDirection(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isIndeterminate(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isVisible(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isCollapsed(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef hasPopup(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef popupValue(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isIgnored(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isSingleLine(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isMultiLine(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isOnScreen(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isOffScreen(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isValid(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef hierarchicalLevel(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isGrabbed(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef ariaDropEffects(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef classList(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef embeddedImageDescription(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef imageOverlayElements(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isInsertion(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isDeletion(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isFirstItemInSuggestion(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isLastItemInSuggestion(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isRemoteFrame(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef pageX(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef pageY(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef x(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef y(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef width(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef height(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef clickPointX(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef clickPointY(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef lineRectsAndText(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef children(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef childrenCount(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef selectedChildrenCount(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef rowCount(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef columnCount(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isInCell(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isInTable(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isInLandmark(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isInList(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef customContent(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef horizontalScrollbar(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef verticalScrollbar(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef startTextMarker(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef endTextMarker(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef supportedActions(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef mathPostscriptsDescription(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef mathPrescriptsDescription(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef mathRootRadicand(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef pathDescription(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef identifier(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef traits(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef elementTextPosition(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef elementTextLength(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef stringForSelection(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isSearchField(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isSwitch(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isTextArea(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isMarkAnnotation(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef supportsExpanded(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isInDescriptionListDetail(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef isInDescriptionListTerm(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef hasTextEntryTrait(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef hasTabBarTrait(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef hasMenuItemTrait(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
};
    
AccessibilityUIElement* toAccessibilityUIElement(JSContextRef, JSValueRef);

} // namespace WTR

#endif // JSAccessibilityUIElement_h
