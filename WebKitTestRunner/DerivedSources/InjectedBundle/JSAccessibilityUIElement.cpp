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
#include "config.h"
#include "AccessibilityTextMarker.h"
#include "AccessibilityTextMarkerRange.h"
#include "AccessibilityUIElement.h"
#include "JSAccessibilityTextMarker.h"
#include "JSAccessibilityTextMarkerRange.h"
#include "JSAccessibilityUIElement.h"
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

AccessibilityUIElement* toAccessibilityUIElement(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSAccessibilityUIElement::accessibilityUIElementClass() || !JSValueIsObjectOfClass(context, value, JSAccessibilityUIElement::accessibilityUIElementClass()))
        return 0;
    return static_cast<AccessibilityUIElement*>(JSWrapper::unwrap(context, value));
}

JSClassRef JSAccessibilityUIElement::accessibilityUIElementClass()
{
    static const JSClassRef jsClass = [] {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "AccessibilityUIElement";
        definition.parentClass = 0;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        return JSClassCreate(&definition);
    }();
    return jsClass;
}

const JSStaticFunction* JSAccessibilityUIElement::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "isEqual", isEqual, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "elementAtPoint", elementAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "elementAtPointWithRemoteElement", elementAtPointWithRemoteElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "elementAtPointResolvingRemoteFrame", elementAtPointResolvingRemoteFrame, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "childAtIndex", childAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "childAtIndexWithRemoteElement", childAtIndexWithRemoteElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "indexOfChild", indexOfChild, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "linkedUIElementAtIndex", linkedUIElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectedChildren", selectedChildren, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectedChildAtIndex", selectedChildAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setSelectedChild", setSelectedChild, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setSelectedChildAtIndex", setSelectedChildAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeSelectionAtIndex", removeSelectionAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clearSelectedChildren", clearSelectedChildren, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "titleUIElement", titleUIElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "parentElement", parentElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stringDescriptionOfAttributeValue", stringDescriptionOfAttributeValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stringAttributeValue", stringAttributeValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "numberAttributeValue", numberAttributeValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "uiElementArrayAttributeValue", uiElementArrayAttributeValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "uiElementAttributeValue", uiElementAttributeValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "boolAttributeValue", boolAttributeValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributeValueAsync", attributeValueAsync, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setBoolAttributeValue", setBoolAttributeValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isAttributeSupported", isAttributeSupported, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isAttributeSettable", isAttributeSettable, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isPressActionSupported", isPressActionSupported, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isIncrementActionSupported", isIncrementActionSupported, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isDecrementActionSupported", isDecrementActionSupported, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setValue", setValue, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "increment", increment, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "decrement", decrement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "asyncIncrement", asyncIncrement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "asyncDecrement", asyncDecrement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "press", press, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "syncPress", syncPress, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "showMenu", showMenu, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dismiss", dismiss, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "allAttributes", allAttributes, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfChildren", attributesOfChildren, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfLinkedUIElements", attributesOfLinkedUIElements, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfDocumentLinks", attributesOfDocumentLinks, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "characterAtOffset", characterAtOffset, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "wordAtOffset", wordAtOffset, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lineAtOffset", lineAtOffset, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "sentenceAtOffset", sentenceAtOffset, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfColumnHeaders", attributesOfColumnHeaders, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfRowHeaders", attributesOfRowHeaders, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "columns", columns, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfColumns", attributesOfColumns, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfRows", attributesOfRows, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfVisibleCells", attributesOfVisibleCells, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributesOfHeader", attributesOfHeader, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "cellForColumnAndRow", cellForColumnAndRow, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectedRowAtIndex", selectedRowAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "disclosedByRow", disclosedByRow, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "disclosedRowAtIndex", disclosedRowAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rowAtIndex", rowAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "indexInTable", indexInTable, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rowIndexRange", rowIndexRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "columnIndexRange", columnIndexRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rowCount", rowCount, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "columnCount", columnCount, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "columnHeaders", columnHeaders, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rowHeaders", rowHeaders, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectedCells", selectedCells, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "controllerElementAtIndex", controllerElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ariaControlsElementAtIndex", ariaControlsElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ariaDescribedByElementAtIndex", ariaDescribedByElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "descriptionForElementAtIndex", descriptionForElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "detailsElements", detailsElements, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ariaDetailsElementAtIndex", ariaDetailsElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "detailsForElementAtIndex", detailsForElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "errorMessageElements", errorMessageElements, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ariaErrorMessageElementAtIndex", ariaErrorMessageElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "errorMessageForElementAtIndex", errorMessageForElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "flowFromElementAtIndex", flowFromElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ariaFlowToElementAtIndex", ariaFlowToElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ariaLabelledByElementAtIndex", ariaLabelledByElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "labelForElementAtIndex", labelForElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ownerElementAtIndex", ownerElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ariaOwnsElementAtIndex", ariaOwnsElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "parameterizedAttributeNames", parameterizedAttributeNames, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lineForIndex", lineForIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rangeForLine", rangeForLine, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rangeForPosition", rangeForPosition, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "boundsForRange", boundsForRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "boundsForRangeWithPagePosition", boundsForRangeWithPagePosition, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stringForRange", stringForRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributedStringForRange", attributedStringForRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributedStringForElement", attributedStringForElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributedStringRangeIsMisspelled", attributedStringRangeIsMisspelled, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "uiElementCountForSearchPredicate", uiElementCountForSearchPredicate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "uiElementForSearchPredicate", uiElementForSearchPredicate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectTextWithCriteria", selectTextWithCriteria, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "searchTextWithCriteria", searchTextWithCriteria, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "performTextOperation", performTextOperation, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setSelectedTextRange", setSelectedTextRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollToMakeVisible", scrollToMakeVisible, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollToGlobalPoint", scrollToGlobalPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollToMakeVisibleWithSubFocus", scrollToMakeVisibleWithSubFocus, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "takeFocus", takeFocus, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollPageDown", scrollPageDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollPageUp", scrollPageUp, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollPageLeft", scrollPageLeft, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scrollPageRight", scrollPageRight, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lineTextMarkerRangeForTextMarker", lineTextMarkerRangeForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rightLineTextMarkerRangeForTextMarker", rightLineTextMarkerRangeForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "leftLineTextMarkerRangeForTextMarker", leftLineTextMarkerRangeForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "previousLineStartTextMarkerForTextMarker", previousLineStartTextMarkerForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "nextLineEndTextMarkerForTextMarker", nextLineEndTextMarkerForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lineIndexForTextMarker", lineIndexForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "styleTextMarkerRangeForTextMarker", styleTextMarkerRangeForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeForSearchPredicate", textMarkerRangeForSearchPredicate, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "misspellingTextMarkerRange", misspellingTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeForElement", textMarkerRangeForElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeForMarkers", textMarkerRangeForMarkers, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeForUnorderedMarkers", textMarkerRangeForUnorderedMarkers, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeForRange", textMarkerRangeForRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectedTextMarkerRange", selectedTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resetSelectedTextMarkerRange", resetSelectedTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "replaceTextInRange", replaceTextInRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "insertText", insertText, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textInputMarkedTextMarkerRange", textInputMarkedTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "startTextMarkerForTextMarkerRange", startTextMarkerForTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "endTextMarkerForTextMarkerRange", endTextMarkerForTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "endTextMarkerForBounds", endTextMarkerForBounds, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "startTextMarkerForBounds", startTextMarkerForBounds, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerForPoint", textMarkerForPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "previousTextMarker", previousTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "nextTextMarker", nextTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "accessibilityElementForTextMarker", accessibilityElementForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeForLine", textMarkerRangeForLine, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stringForTextMarkerRange", stringForTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rectsForTextMarkerRange", rectsForTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributedStringForTextMarkerRange", attributedStringForTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributedStringForTextMarkerRangeWithDidSpellCheck", attributedStringForTextMarkerRangeWithDidSpellCheck, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributedStringForTextMarkerRangeWithOptions", attributedStringForTextMarkerRangeWithOptions, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeLength", textMarkerRangeLength, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "attributedStringForTextMarkerRangeContainsAttribute", attributedStringForTextMarkerRangeContainsAttribute, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "indexForTextMarker", indexForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isTextMarkerValid", isTextMarkerValid, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isTextMarkerRangeValid", isTextMarkerRangeValid, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isTextMarkerNull", isTextMarkerNull, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerForIndex", textMarkerForIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setSelectedTextMarkerRange", setSelectedTextMarkerRange, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "leftWordTextMarkerRangeForTextMarker", leftWordTextMarkerRangeForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rightWordTextMarkerRangeForTextMarker", rightWordTextMarkerRangeForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "previousWordStartTextMarkerForTextMarker", previousWordStartTextMarkerForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "nextWordEndTextMarkerForTextMarker", nextWordEndTextMarkerForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "paragraphTextMarkerRangeForTextMarker", paragraphTextMarkerRangeForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "previousParagraphStartTextMarkerForTextMarker", previousParagraphStartTextMarkerForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "nextParagraphEndTextMarkerForTextMarker", nextParagraphEndTextMarkerForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "sentenceTextMarkerRangeForTextMarker", sentenceTextMarkerRangeForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "previousSentenceStartTextMarkerForTextMarker", previousSentenceStartTextMarkerForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "nextSentenceEndTextMarkerForTextMarker", nextSentenceEndTextMarkerForTextMarker, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeMatchesTextNearMarkers", textMarkerRangeMatchesTextNearMarkers, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerDebugDescription", textMarkerDebugDescription, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textMarkerRangeDebugDescription", textMarkerRangeDebugDescription, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "increaseTextSelection", increaseTextSelection, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "decreaseTextSelection", decreaseTextSelection, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "linkedElement", linkedElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "headerElementAtIndex", headerElementAtIndex, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "assistiveTechnologySimulatedFocus", assistiveTechnologySimulatedFocus, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "fieldsetAncestorElement", fieldsetAncestorElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "focusableAncestor", focusableAncestor, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "editableAncestor", editableAncestor, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "highestEditableAncestor", highestEditableAncestor, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addNotificationListener", addNotificationListener, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeNotificationListener", removeNotificationListener, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0 }
    };
    return functions;
}

const JSStaticValue* JSAccessibilityUIElement::staticValues()
{
    static const JSStaticValue values[] = {
        { "domIdentifier", domIdentifier, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "activeElement", activeElement, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "role", role, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "subrole", subrole, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "roleDescription", roleDescription, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "computedRoleString", computedRoleString, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "title", title, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "description", description, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "language", language, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "helpText", helpText, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "valueDescription", valueDescription, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "brailleLabel", brailleLabel, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "brailleRoleDescription", brailleRoleDescription, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "url", url, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "speakAs", speakAs, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "liveRegionRelevant", liveRegionRelevant, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "liveRegionStatus", liveRegionStatus, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "orientation", orientation, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "numberOfCharacters", numberOfCharacters, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "insertionPointLineNumber", insertionPointLineNumber, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectedText", selectedText, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectedTextRange", selectedTextRange, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "intersectionWithSelectionRange", intersectionWithSelectionRange, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textInputMarkedRange", textInputMarkedRange, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stringValue", stringValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dateValue", dateValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "dateTimeValue", dateTimeValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "intValue", intValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "minValue", minValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "maxValue", maxValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isAtomicLiveRegion", isAtomicLiveRegion, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isBusy", isBusy, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isEnabled", isEnabled, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isRequired", isRequired, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isFocused", isFocused, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isFocusable", isFocusable, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isSelectable", isSelectable, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isSelected", isSelected, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isSelectedOptionActive", isSelectedOptionActive, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isMultiSelectable", isMultiSelectable, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isExpanded", isExpanded, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isChecked", isChecked, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "currentStateValue", currentStateValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "sortDirection", sortDirection, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isIndeterminate", isIndeterminate, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isVisible", isVisible, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isCollapsed", isCollapsed, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hasPopup", hasPopup, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "popupValue", popupValue, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isIgnored", isIgnored, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isSingleLine", isSingleLine, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isMultiLine", isMultiLine, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isOnScreen", isOnScreen, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isOffScreen", isOffScreen, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isValid", isValid, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hierarchicalLevel", hierarchicalLevel, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isGrabbed", isGrabbed, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "ariaDropEffects", ariaDropEffects, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "classList", classList, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "embeddedImageDescription", embeddedImageDescription, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "imageOverlayElements", imageOverlayElements, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isInsertion", isInsertion, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isDeletion", isDeletion, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isFirstItemInSuggestion", isFirstItemInSuggestion, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isLastItemInSuggestion", isLastItemInSuggestion, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isRemoteFrame", isRemoteFrame, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "pageX", pageX, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "pageY", pageY, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "x", x, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "y", y, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "width", width, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "height", height, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clickPointX", clickPointX, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "clickPointY", clickPointY, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "lineRectsAndText", lineRectsAndText, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "children", children, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "childrenCount", childrenCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "selectedChildrenCount", selectedChildrenCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rowCount", rowCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "columnCount", columnCount, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isInCell", isInCell, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isInTable", isInTable, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isInLandmark", isInLandmark, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isInList", isInList, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "customContent", customContent, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "horizontalScrollbar", horizontalScrollbar, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "verticalScrollbar", verticalScrollbar, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "startTextMarker", startTextMarker, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "endTextMarker", endTextMarker, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "supportedActions", supportedActions, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mathPostscriptsDescription", mathPostscriptsDescription, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mathPrescriptsDescription", mathPrescriptsDescription, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mathRootRadicand", mathRootRadicand, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "pathDescription", pathDescription, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "identifier", identifier, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "traits", traits, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "elementTextPosition", elementTextPosition, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "elementTextLength", elementTextLength, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "stringForSelection", stringForSelection, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isSearchField", isSearchField, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isSwitch", isSwitch, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isTextArea", isTextArea, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isMarkAnnotation", isMarkAnnotation, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "supportsExpanded", supportsExpanded, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isInDescriptionListDetail", isInDescriptionListDetail, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "isInDescriptionListTerm", isInDescriptionListTerm, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hasTextEntryTrait", hasTextEntryTrait, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hasTabBarTrait", hasTabBarTrait, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "hasMenuItemTrait", hasMenuItemTrait, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0, 0 }
    };
    return values;
}

// Functions

JSValueRef JSAccessibilityUIElement::isEqual(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto otherElement = argumentCount > 0 ? toAccessibilityUIElement(context, arguments[0]) : nullptr;
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isEqual, otherElement));
}

JSValueRef JSAccessibilityUIElement::elementAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::elementAtPoint, x, y)));
}

JSValueRef JSAccessibilityUIElement::elementAtPointWithRemoteElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::elementAtPointWithRemoteElement, x, y)));
}

JSValueRef JSAccessibilityUIElement::elementAtPointResolvingRemoteFrame(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto callbackFunction = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    callFunction(context, impl, &AccessibilityUIElement::elementAtPointResolvingRemoteFrame, x, y, callbackFunction);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::childAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::childAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::childAtIndexWithRemoteElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::childAtIndexWithRemoteElement, index)));
}

JSValueRef JSAccessibilityUIElement::indexOfChild(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto child = argumentCount > 0 ? toAccessibilityUIElement(context, arguments[0]) : nullptr;
    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::indexOfChild, child));
}

JSValueRef JSAccessibilityUIElement::linkedUIElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::linkedUIElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::selectedChildren(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::selectedChildren);
}

JSValueRef JSAccessibilityUIElement::selectedChildAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::selectedChildAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::setSelectedChild(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto element = argumentCount > 0 ? toAccessibilityUIElement(context, arguments[0]) : nullptr;
    callFunction(context, impl, &AccessibilityUIElement::setSelectedChild, element);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::setSelectedChildAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &AccessibilityUIElement::setSelectedChildAtIndex, index);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::removeSelectionAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    callFunction(context, impl, &AccessibilityUIElement::removeSelectionAtIndex, index);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::clearSelectedChildren(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::clearSelectedChildren);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::titleUIElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::titleUIElement)));
}

JSValueRef JSAccessibilityUIElement::parentElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::parentElement)));
}

JSValueRef JSAccessibilityUIElement::stringDescriptionOfAttributeValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::stringDescriptionOfAttributeValue, attr.get()).get());
}

JSValueRef JSAccessibilityUIElement::stringAttributeValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::stringAttributeValue, attr.get()).get());
}

JSValueRef JSAccessibilityUIElement::numberAttributeValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::numberAttributeValue, attr.get()));
}

JSValueRef JSAccessibilityUIElement::uiElementArrayAttributeValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return callFunction(context, impl, &AccessibilityUIElement::uiElementArrayAttributeValue, attr.get());
}

JSValueRef JSAccessibilityUIElement::uiElementAttributeValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::uiElementAttributeValue, attr.get())));
}

JSValueRef JSAccessibilityUIElement::boolAttributeValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::boolAttributeValue, attr.get()));
}

JSValueRef JSAccessibilityUIElement::attributeValueAsync(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attributeName = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto callbackFunction = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    callFunction(context, impl, &AccessibilityUIElement::attributeValueAsync, attributeName.get(), callbackFunction);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::setBoolAttributeValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    bool value = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    callFunction(context, impl, &AccessibilityUIElement::setBoolAttributeValue, attr.get(), value);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::isAttributeSupported(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isAttributeSupported, attr.get()));
}

JSValueRef JSAccessibilityUIElement::isAttributeSettable(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isAttributeSettable, attr.get()));
}

JSValueRef JSAccessibilityUIElement::isPressActionSupported(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isPressActionSupported));
}

JSValueRef JSAccessibilityUIElement::isIncrementActionSupported(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isIncrementActionSupported));
}

JSValueRef JSAccessibilityUIElement::isDecrementActionSupported(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isDecrementActionSupported));
}

JSValueRef JSAccessibilityUIElement::setValue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto value = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &AccessibilityUIElement::setValue, value.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::increment(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::increment);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::decrement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::decrement);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::asyncIncrement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::asyncIncrement);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::asyncDecrement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::asyncDecrement);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::press(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::press);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::syncPress(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::syncPress);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::showMenu(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::showMenu);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::dismiss(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::dismiss));
}

JSValueRef JSAccessibilityUIElement::allAttributes(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::allAttributes).get());
}

JSValueRef JSAccessibilityUIElement::attributesOfChildren(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfChildren).get());
}

JSValueRef JSAccessibilityUIElement::attributesOfLinkedUIElements(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfLinkedUIElements).get());
}

JSValueRef JSAccessibilityUIElement::attributesOfDocumentLinks(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfDocumentLinks).get());
}

JSValueRef JSAccessibilityUIElement::characterAtOffset(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto offset = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::characterAtOffset, offset).get());
}

JSValueRef JSAccessibilityUIElement::wordAtOffset(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto offset = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::wordAtOffset, offset).get());
}

JSValueRef JSAccessibilityUIElement::lineAtOffset(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto offset = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::lineAtOffset, offset).get());
}

JSValueRef JSAccessibilityUIElement::sentenceAtOffset(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto offset = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::sentenceAtOffset, offset).get());
}

JSValueRef JSAccessibilityUIElement::attributesOfColumnHeaders(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfColumnHeaders).get());
}

JSValueRef JSAccessibilityUIElement::attributesOfRowHeaders(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfRowHeaders).get());
}

JSValueRef JSAccessibilityUIElement::columns(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::columns);
}

JSValueRef JSAccessibilityUIElement::attributesOfColumns(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfColumns).get());
}

JSValueRef JSAccessibilityUIElement::attributesOfRows(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfRows).get());
}

JSValueRef JSAccessibilityUIElement::attributesOfVisibleCells(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfVisibleCells).get());
}

JSValueRef JSAccessibilityUIElement::attributesOfHeader(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributesOfHeader).get());
}

JSValueRef JSAccessibilityUIElement::cellForColumnAndRow(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto column = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto row = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::cellForColumnAndRow, column, row)));
}

JSValueRef JSAccessibilityUIElement::selectedRowAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::selectedRowAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::disclosedByRow(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::disclosedByRow)));
}

JSValueRef JSAccessibilityUIElement::disclosedRowAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::disclosedRowAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::rowAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::rowAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::indexInTable(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::indexInTable));
}

JSValueRef JSAccessibilityUIElement::rowIndexRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::rowIndexRange).get());
}

JSValueRef JSAccessibilityUIElement::columnIndexRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::columnIndexRange).get());
}

JSValueRef JSAccessibilityUIElement::rowCount(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::rowCount));
}

JSValueRef JSAccessibilityUIElement::columnCount(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::columnCount));
}

JSValueRef JSAccessibilityUIElement::columnHeaders(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::columnHeaders);
}

JSValueRef JSAccessibilityUIElement::rowHeaders(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::rowHeaders);
}

JSValueRef JSAccessibilityUIElement::selectedCells(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::selectedCells);
}

JSValueRef JSAccessibilityUIElement::controllerElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::controllerElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::ariaControlsElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::ariaControlsElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::ariaDescribedByElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::ariaDescribedByElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::descriptionForElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::descriptionForElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::detailsElements(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::detailsElements);
}

JSValueRef JSAccessibilityUIElement::ariaDetailsElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::ariaDetailsElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::detailsForElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::detailsForElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::errorMessageElements(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::errorMessageElements);
}

JSValueRef JSAccessibilityUIElement::ariaErrorMessageElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::ariaErrorMessageElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::errorMessageForElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::errorMessageForElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::flowFromElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::flowFromElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::ariaFlowToElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::ariaFlowToElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::ariaLabelledByElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::ariaLabelledByElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::labelForElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::labelForElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::ownerElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::ownerElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::ariaOwnsElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::ariaOwnsElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::parameterizedAttributeNames(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::parameterizedAttributeNames).get());
}

JSValueRef JSAccessibilityUIElement::lineForIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::lineForIndex, index));
}

JSValueRef JSAccessibilityUIElement::rangeForLine(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::rangeForLine, index).get());
}

JSValueRef JSAccessibilityUIElement::rangeForPosition(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::rangeForPosition, x, y).get());
}

JSValueRef JSAccessibilityUIElement::boundsForRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto location = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto length = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::boundsForRange, location, length).get());
}

JSValueRef JSAccessibilityUIElement::boundsForRangeWithPagePosition(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto location = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto length = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::boundsForRangeWithPagePosition, location, length).get());
}

JSValueRef JSAccessibilityUIElement::stringForRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto location = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto length = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::stringForRange, location, length).get());
}

JSValueRef JSAccessibilityUIElement::attributedStringForRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto location = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto length = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributedStringForRange, location, length).get());
}

JSValueRef JSAccessibilityUIElement::attributedStringForElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributedStringForElement).get());
}

JSValueRef JSAccessibilityUIElement::attributedStringRangeIsMisspelled(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto location = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto length = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::attributedStringRangeIsMisspelled, location, length));
}

JSValueRef JSAccessibilityUIElement::uiElementCountForSearchPredicate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto startElement = argumentCount > 0 ? toAccessibilityUIElement(context, arguments[0]) : nullptr;
    bool isDirectionNext = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    auto searchKey = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    auto searchText = argumentCount > 3 ? createJSString(context, arguments[3]) : JSRetainPtr<JSStringRef>();
    bool visibleOnly = argumentCount > 4 && JSValueToBoolean(context, arguments[4]);
    bool immediateDescendantsOnly = argumentCount > 5 && JSValueToBoolean(context, arguments[5]);
    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::uiElementCountForSearchPredicate, startElement, isDirectionNext, searchKey, searchText.get(), visibleOnly, immediateDescendantsOnly));
}

JSValueRef JSAccessibilityUIElement::uiElementForSearchPredicate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto startElement = argumentCount > 0 ? toAccessibilityUIElement(context, arguments[0]) : nullptr;
    bool isDirectionNext = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    auto searchKey = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    auto searchText = argumentCount > 3 ? createJSString(context, arguments[3]) : JSRetainPtr<JSStringRef>();
    bool visibleOnly = argumentCount > 4 && JSValueToBoolean(context, arguments[4]);
    bool immediateDescendantsOnly = argumentCount > 5 && JSValueToBoolean(context, arguments[5]);
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::uiElementForSearchPredicate, startElement, isDirectionNext, searchKey, searchText.get(), visibleOnly, immediateDescendantsOnly)));
}

JSValueRef JSAccessibilityUIElement::selectTextWithCriteria(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto ambiguityResolution = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto searchStrings = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto replacementString = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    auto activity = argumentCount > 3 ? createJSString(context, arguments[3]) : JSRetainPtr<JSStringRef>();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::selectTextWithCriteria, ambiguityResolution.get(), searchStrings, replacementString.get(), activity.get()).get());
}

JSValueRef JSAccessibilityUIElement::searchTextWithCriteria(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto searchStrings = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    auto startFrom = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto direction = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    return callFunction(context, impl, &AccessibilityUIElement::searchTextWithCriteria, searchStrings, startFrom.get(), direction.get());
}

JSValueRef JSAccessibilityUIElement::performTextOperation(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto operationType = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto markerRanges = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto replacementStrings = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    bool shouldSmartReplace = argumentCount > 3 && JSValueToBoolean(context, arguments[3]);
    return callFunction(context, impl, &AccessibilityUIElement::performTextOperation, operationType.get(), markerRanges, replacementStrings, shouldSmartReplace);
}

JSValueRef JSAccessibilityUIElement::setSelectedTextRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto location = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto length = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::setSelectedTextRange, location, length));
}

JSValueRef JSAccessibilityUIElement::scrollToMakeVisible(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::scrollToMakeVisible);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::scrollToGlobalPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    callFunction(context, impl, &AccessibilityUIElement::scrollToGlobalPoint, x, y);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::scrollToMakeVisibleWithSubFocus(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto width = argumentCount > 2 ? clampTo<int32_t>(JSValueToNumber(context, arguments[2], nullptr)) : int32_t();
    auto height = argumentCount > 3 ? clampTo<int32_t>(JSValueToNumber(context, arguments[3], nullptr)) : int32_t();
    callFunction(context, impl, &AccessibilityUIElement::scrollToMakeVisibleWithSubFocus, x, y, width, height);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::takeFocus(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::takeFocus);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::scrollPageDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::scrollPageDown));
}

JSValueRef JSAccessibilityUIElement::scrollPageUp(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::scrollPageUp));
}

JSValueRef JSAccessibilityUIElement::scrollPageLeft(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::scrollPageLeft));
}

JSValueRef JSAccessibilityUIElement::scrollPageRight(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::scrollPageRight));
}

JSValueRef JSAccessibilityUIElement::lineTextMarkerRangeForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::lineTextMarkerRangeForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::rightLineTextMarkerRangeForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::rightLineTextMarkerRangeForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::leftLineTextMarkerRangeForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::leftLineTextMarkerRangeForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::previousLineStartTextMarkerForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::previousLineStartTextMarkerForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::nextLineEndTextMarkerForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::nextLineEndTextMarkerForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::lineIndexForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::lineIndexForTextMarker, textMarker));
}

JSValueRef JSAccessibilityUIElement::styleTextMarkerRangeForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::styleTextMarkerRangeForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeForSearchPredicate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto startRange = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    bool forward = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    auto searchKey = argumentCount > 2 ? arguments[2] : JSValueMakeUndefined(context);
    auto searchText = argumentCount > 3 ? createJSString(context, arguments[3]) : JSRetainPtr<JSStringRef>();
    bool visibleOnly = argumentCount > 4 && JSValueToBoolean(context, arguments[4]);
    bool immediateDescendantsOnly = argumentCount > 5 && JSValueToBoolean(context, arguments[5]);
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeForSearchPredicate, startRange, forward, searchKey, searchText.get(), visibleOnly, immediateDescendantsOnly)));
}

JSValueRef JSAccessibilityUIElement::misspellingTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto start = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    bool forward = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::misspellingTextMarkerRange, start, forward)));
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeForElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto element = argumentCount > 0 ? toAccessibilityUIElement(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeForElement, element)));
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeForMarkers(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto startMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    auto endMarker = argumentCount > 1 ? toAccessibilityTextMarker(context, arguments[1]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeForMarkers, startMarker, endMarker)));
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeForUnorderedMarkers(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto startMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    auto endMarker = argumentCount > 1 ? toAccessibilityTextMarker(context, arguments[1]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeForUnorderedMarkers, startMarker, endMarker)));
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeForRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto location = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    auto length = argumentCount > 1 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[1], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeForRange, location, length)));
}

JSValueRef JSAccessibilityUIElement::selectedTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::selectedTextMarkerRange)));
}

JSValueRef JSAccessibilityUIElement::resetSelectedTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::resetSelectedTextMarkerRange);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::replaceTextInRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto string = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto position = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto length = argumentCount > 2 ? clampTo<int32_t>(JSValueToNumber(context, arguments[2], nullptr)) : int32_t();
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::replaceTextInRange, string.get(), position, length));
}

JSValueRef JSAccessibilityUIElement::insertText(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto text = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::insertText, text.get()));
}

JSValueRef JSAccessibilityUIElement::textInputMarkedTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textInputMarkedTextMarkerRange)));
}

JSValueRef JSAccessibilityUIElement::startTextMarkerForTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::startTextMarkerForTextMarkerRange, range)));
}

JSValueRef JSAccessibilityUIElement::endTextMarkerForTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::endTextMarkerForTextMarkerRange, range)));
}

JSValueRef JSAccessibilityUIElement::endTextMarkerForBounds(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto width = argumentCount > 2 ? clampTo<int32_t>(JSValueToNumber(context, arguments[2], nullptr)) : int32_t();
    auto height = argumentCount > 3 ? clampTo<int32_t>(JSValueToNumber(context, arguments[3], nullptr)) : int32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::endTextMarkerForBounds, x, y, width, height)));
}

JSValueRef JSAccessibilityUIElement::startTextMarkerForBounds(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto width = argumentCount > 2 ? clampTo<int32_t>(JSValueToNumber(context, arguments[2], nullptr)) : int32_t();
    auto height = argumentCount > 3 ? clampTo<int32_t>(JSValueToNumber(context, arguments[3], nullptr)) : int32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::startTextMarkerForBounds, x, y, width, height)));
}

JSValueRef JSAccessibilityUIElement::textMarkerForPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerForPoint, x, y)));
}

JSValueRef JSAccessibilityUIElement::previousTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto marker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::previousTextMarker, marker)));
}

JSValueRef JSAccessibilityUIElement::nextTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto marker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::nextTextMarker, marker)));
}

JSValueRef JSAccessibilityUIElement::accessibilityElementForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto marker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::accessibilityElementForTextMarker, marker)));
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeForLine(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto lineIndex = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeForLine, lineIndex)));
}

JSValueRef JSAccessibilityUIElement::stringForTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::stringForTextMarkerRange, range).get());
}

JSValueRef JSAccessibilityUIElement::rectsForTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    auto searchText = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::rectsForTextMarkerRange, range, searchText.get()).get());
}

JSValueRef JSAccessibilityUIElement::attributedStringForTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributedStringForTextMarkerRange, range).get());
}

JSValueRef JSAccessibilityUIElement::attributedStringForTextMarkerRangeWithDidSpellCheck(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributedStringForTextMarkerRangeWithDidSpellCheck, range).get());
}

JSValueRef JSAccessibilityUIElement::attributedStringForTextMarkerRangeWithOptions(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    bool includeSpellCheck = argumentCount > 1 && JSValueToBoolean(context, arguments[1]);
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::attributedStringForTextMarkerRangeWithOptions, range, includeSpellCheck).get());
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeLength(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeLength, range));
}

JSValueRef JSAccessibilityUIElement::attributedStringForTextMarkerRangeContainsAttribute(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto attr = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto range = argumentCount > 1 ? toAccessibilityTextMarkerRange(context, arguments[1]) : nullptr;
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::attributedStringForTextMarkerRangeContainsAttribute, attr.get(), range));
}

JSValueRef JSAccessibilityUIElement::indexForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto marker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::indexForTextMarker, marker));
}

JSValueRef JSAccessibilityUIElement::isTextMarkerValid(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto marker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isTextMarkerValid, marker));
}

JSValueRef JSAccessibilityUIElement::isTextMarkerRangeValid(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto markerRange = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isTextMarkerRangeValid, markerRange));
}

JSValueRef JSAccessibilityUIElement::isTextMarkerNull(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto marker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isTextMarkerNull, marker));
}

JSValueRef JSAccessibilityUIElement::textMarkerForIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textIndex = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerForIndex, textIndex)));
}

JSValueRef JSAccessibilityUIElement::setSelectedTextMarkerRange(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::setSelectedTextMarkerRange, range));
}

JSValueRef JSAccessibilityUIElement::leftWordTextMarkerRangeForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::leftWordTextMarkerRangeForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::rightWordTextMarkerRangeForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::rightWordTextMarkerRangeForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::previousWordStartTextMarkerForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::previousWordStartTextMarkerForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::nextWordEndTextMarkerForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::nextWordEndTextMarkerForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::paragraphTextMarkerRangeForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::paragraphTextMarkerRangeForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::previousParagraphStartTextMarkerForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::previousParagraphStartTextMarkerForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::nextParagraphEndTextMarkerForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::nextParagraphEndTextMarkerForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::sentenceTextMarkerRangeForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::sentenceTextMarkerRangeForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::previousSentenceStartTextMarkerForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::previousSentenceStartTextMarkerForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::nextSentenceEndTextMarkerForTextMarker(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto textMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::nextSentenceEndTextMarkerForTextMarker, textMarker)));
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeMatchesTextNearMarkers(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto text = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto startMarker = argumentCount > 1 ? toAccessibilityTextMarker(context, arguments[1]) : nullptr;
    auto endMarker = argumentCount > 2 ? toAccessibilityTextMarker(context, arguments[2]) : nullptr;
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeMatchesTextNearMarkers, text.get(), startMarker, endMarker)));
}

JSValueRef JSAccessibilityUIElement::textMarkerDebugDescription(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto marker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::textMarkerDebugDescription, marker).get());
}

JSValueRef JSAccessibilityUIElement::textMarkerRangeDebugDescription(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto range = argumentCount > 0 ? toAccessibilityTextMarkerRange(context, arguments[0]) : nullptr;
    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::textMarkerRangeDebugDescription, range).get());
}

JSValueRef JSAccessibilityUIElement::increaseTextSelection(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::increaseTextSelection);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::decreaseTextSelection(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::decreaseTextSelection);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::linkedElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::linkedElement)));
}

JSValueRef JSAccessibilityUIElement::headerElementAtIndex(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto index = argumentCount > 0 ? clampTo<uint32_t>(JSValueToNumber(context, arguments[0], nullptr)) : uint32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::headerElementAtIndex, index)));
}

JSValueRef JSAccessibilityUIElement::assistiveTechnologySimulatedFocus(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityUIElement::assistiveTechnologySimulatedFocus);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityUIElement::fieldsetAncestorElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::fieldsetAncestorElement)));
}

JSValueRef JSAccessibilityUIElement::focusableAncestor(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::focusableAncestor)));
}

JSValueRef JSAccessibilityUIElement::editableAncestor(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::editableAncestor)));
}

JSValueRef JSAccessibilityUIElement::highestEditableAncestor(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::highestEditableAncestor)));
}

JSValueRef JSAccessibilityUIElement::addNotificationListener(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto callbackFunction = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::addNotificationListener, callbackFunction));
}

JSValueRef JSAccessibilityUIElement::removeNotificationListener(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::removeNotificationListener));
}

// Attributes

JSValueRef JSAccessibilityUIElement::domIdentifier(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::domIdentifier).get());
}

JSValueRef JSAccessibilityUIElement::activeElement(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::activeElement)));
}

JSValueRef JSAccessibilityUIElement::role(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::role).get());
}

JSValueRef JSAccessibilityUIElement::subrole(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::subrole).get());
}

JSValueRef JSAccessibilityUIElement::roleDescription(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::roleDescription).get());
}

JSValueRef JSAccessibilityUIElement::computedRoleString(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::computedRoleString).get());
}

JSValueRef JSAccessibilityUIElement::title(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::title).get());
}

JSValueRef JSAccessibilityUIElement::description(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::description).get());
}

JSValueRef JSAccessibilityUIElement::language(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::language).get());
}

JSValueRef JSAccessibilityUIElement::helpText(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::helpText).get());
}

JSValueRef JSAccessibilityUIElement::valueDescription(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::valueDescription).get());
}

JSValueRef JSAccessibilityUIElement::brailleLabel(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::brailleLabel).get());
}

JSValueRef JSAccessibilityUIElement::brailleRoleDescription(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::brailleRoleDescription).get());
}

JSValueRef JSAccessibilityUIElement::url(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::url).get());
}

JSValueRef JSAccessibilityUIElement::speakAs(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::speakAs).get());
}

JSValueRef JSAccessibilityUIElement::liveRegionRelevant(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::liveRegionRelevant).get());
}

JSValueRef JSAccessibilityUIElement::liveRegionStatus(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::liveRegionStatus).get());
}

JSValueRef JSAccessibilityUIElement::orientation(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::orientation).get());
}

JSValueRef JSAccessibilityUIElement::numberOfCharacters(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::numberOfCharacters));
}

JSValueRef JSAccessibilityUIElement::insertionPointLineNumber(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::insertionPointLineNumber));
}

JSValueRef JSAccessibilityUIElement::selectedText(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::selectedText).get());
}

JSValueRef JSAccessibilityUIElement::selectedTextRange(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::selectedTextRange).get());
}

JSValueRef JSAccessibilityUIElement::intersectionWithSelectionRange(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::intersectionWithSelectionRange).get());
}

JSValueRef JSAccessibilityUIElement::textInputMarkedRange(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::textInputMarkedRange).get());
}

JSValueRef JSAccessibilityUIElement::stringValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::stringValue).get());
}

JSValueRef JSAccessibilityUIElement::dateValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::dateValue).get());
}

JSValueRef JSAccessibilityUIElement::dateTimeValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::dateTimeValue).get());
}

JSValueRef JSAccessibilityUIElement::intValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::intValue));
}

JSValueRef JSAccessibilityUIElement::minValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::minValue));
}

JSValueRef JSAccessibilityUIElement::maxValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::maxValue));
}

JSValueRef JSAccessibilityUIElement::isAtomicLiveRegion(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isAtomicLiveRegion));
}

JSValueRef JSAccessibilityUIElement::isBusy(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isBusy));
}

JSValueRef JSAccessibilityUIElement::isEnabled(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isEnabled));
}

JSValueRef JSAccessibilityUIElement::isRequired(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isRequired));
}

JSValueRef JSAccessibilityUIElement::isFocused(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isFocused));
}

JSValueRef JSAccessibilityUIElement::isFocusable(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isFocusable));
}

JSValueRef JSAccessibilityUIElement::isSelectable(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isSelectable));
}

JSValueRef JSAccessibilityUIElement::isSelected(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isSelected));
}

JSValueRef JSAccessibilityUIElement::isSelectedOptionActive(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isSelectedOptionActive));
}

JSValueRef JSAccessibilityUIElement::isMultiSelectable(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isMultiSelectable));
}

JSValueRef JSAccessibilityUIElement::isExpanded(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isExpanded));
}

JSValueRef JSAccessibilityUIElement::isChecked(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isChecked));
}

JSValueRef JSAccessibilityUIElement::currentStateValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::currentStateValue).get());
}

JSValueRef JSAccessibilityUIElement::sortDirection(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::sortDirection).get());
}

JSValueRef JSAccessibilityUIElement::isIndeterminate(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isIndeterminate));
}

JSValueRef JSAccessibilityUIElement::isVisible(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isVisible));
}

JSValueRef JSAccessibilityUIElement::isCollapsed(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isCollapsed));
}

JSValueRef JSAccessibilityUIElement::hasPopup(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::hasPopup));
}

JSValueRef JSAccessibilityUIElement::popupValue(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::popupValue).get());
}

JSValueRef JSAccessibilityUIElement::isIgnored(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isIgnored));
}

JSValueRef JSAccessibilityUIElement::isSingleLine(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isSingleLine));
}

JSValueRef JSAccessibilityUIElement::isMultiLine(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isMultiLine));
}

JSValueRef JSAccessibilityUIElement::isOnScreen(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isOnScreen));
}

JSValueRef JSAccessibilityUIElement::isOffScreen(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isOffScreen));
}

JSValueRef JSAccessibilityUIElement::isValid(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isValid));
}

JSValueRef JSAccessibilityUIElement::hierarchicalLevel(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::hierarchicalLevel));
}

JSValueRef JSAccessibilityUIElement::isGrabbed(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isGrabbed));
}

JSValueRef JSAccessibilityUIElement::ariaDropEffects(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::ariaDropEffects).get());
}

JSValueRef JSAccessibilityUIElement::classList(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::classList).get());
}

JSValueRef JSAccessibilityUIElement::embeddedImageDescription(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::embeddedImageDescription).get());
}

JSValueRef JSAccessibilityUIElement::imageOverlayElements(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::imageOverlayElements);
}

JSValueRef JSAccessibilityUIElement::isInsertion(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isInsertion));
}

JSValueRef JSAccessibilityUIElement::isDeletion(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isDeletion));
}

JSValueRef JSAccessibilityUIElement::isFirstItemInSuggestion(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isFirstItemInSuggestion));
}

JSValueRef JSAccessibilityUIElement::isLastItemInSuggestion(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isLastItemInSuggestion));
}

JSValueRef JSAccessibilityUIElement::isRemoteFrame(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isRemoteFrame));
}

JSValueRef JSAccessibilityUIElement::pageX(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::pageX));
}

JSValueRef JSAccessibilityUIElement::pageY(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::pageY));
}

JSValueRef JSAccessibilityUIElement::x(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::x));
}

JSValueRef JSAccessibilityUIElement::y(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::y));
}

JSValueRef JSAccessibilityUIElement::width(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::width));
}

JSValueRef JSAccessibilityUIElement::height(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::height));
}

JSValueRef JSAccessibilityUIElement::clickPointX(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::clickPointX));
}

JSValueRef JSAccessibilityUIElement::clickPointY(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::clickPointY));
}

JSValueRef JSAccessibilityUIElement::lineRectsAndText(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::lineRectsAndText).get());
}

JSValueRef JSAccessibilityUIElement::children(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::children);
}

JSValueRef JSAccessibilityUIElement::childrenCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::childrenCount));
}

JSValueRef JSAccessibilityUIElement::selectedChildrenCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::selectedChildrenCount));
}

JSValueRef JSAccessibilityUIElement::rowCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::rowCount));
}

JSValueRef JSAccessibilityUIElement::columnCount(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::columnCount));
}

JSValueRef JSAccessibilityUIElement::isInCell(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isInCell));
}

JSValueRef JSAccessibilityUIElement::isInTable(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isInTable));
}

JSValueRef JSAccessibilityUIElement::isInLandmark(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isInLandmark));
}

JSValueRef JSAccessibilityUIElement::isInList(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isInList));
}

JSValueRef JSAccessibilityUIElement::customContent(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::customContent).get());
}

JSValueRef JSAccessibilityUIElement::horizontalScrollbar(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::horizontalScrollbar)));
}

JSValueRef JSAccessibilityUIElement::verticalScrollbar(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::verticalScrollbar)));
}

JSValueRef JSAccessibilityUIElement::startTextMarker(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::startTextMarker)));
}

JSValueRef JSAccessibilityUIElement::endTextMarker(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityUIElement::endTextMarker)));
}

JSValueRef JSAccessibilityUIElement::supportedActions(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::supportedActions).get());
}

JSValueRef JSAccessibilityUIElement::mathPostscriptsDescription(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::mathPostscriptsDescription).get());
}

JSValueRef JSAccessibilityUIElement::mathPrescriptsDescription(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::mathPrescriptsDescription).get());
}

JSValueRef JSAccessibilityUIElement::mathRootRadicand(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &AccessibilityUIElement::mathRootRadicand);
}

JSValueRef JSAccessibilityUIElement::pathDescription(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::pathDescription).get());
}

JSValueRef JSAccessibilityUIElement::identifier(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::identifier).get());
}

JSValueRef JSAccessibilityUIElement::traits(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::traits).get());
}

JSValueRef JSAccessibilityUIElement::elementTextPosition(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::elementTextPosition));
}

JSValueRef JSAccessibilityUIElement::elementTextLength(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeNumber(context, callFunction(context, impl, &AccessibilityUIElement::elementTextLength));
}

JSValueRef JSAccessibilityUIElement::stringForSelection(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityUIElement::stringForSelection).get());
}

JSValueRef JSAccessibilityUIElement::isSearchField(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isSearchField));
}

JSValueRef JSAccessibilityUIElement::isSwitch(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isSwitch));
}

JSValueRef JSAccessibilityUIElement::isTextArea(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isTextArea));
}

JSValueRef JSAccessibilityUIElement::isMarkAnnotation(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isMarkAnnotation));
}

JSValueRef JSAccessibilityUIElement::supportsExpanded(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::supportsExpanded));
}

JSValueRef JSAccessibilityUIElement::isInDescriptionListDetail(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isInDescriptionListDetail));
}

JSValueRef JSAccessibilityUIElement::isInDescriptionListTerm(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::isInDescriptionListTerm));
}

JSValueRef JSAccessibilityUIElement::hasTextEntryTrait(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::hasTextEntryTrait));
}

JSValueRef JSAccessibilityUIElement::hasTabBarTrait(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::hasTabBarTrait));
}

JSValueRef JSAccessibilityUIElement::hasMenuItemTrait(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityUIElement* impl = toAccessibilityUIElement(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityUIElement::hasMenuItemTrait));
}

} // namespace WTR

