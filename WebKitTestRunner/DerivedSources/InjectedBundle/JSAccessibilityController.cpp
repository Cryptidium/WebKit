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
#include "AccessibilityController.h"
#include "AccessibilityUIElement.h"
#include "JSAccessibilityController.h"
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

AccessibilityController* toAccessibilityController(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSAccessibilityController::accessibilityControllerClass() || !JSValueIsObjectOfClass(context, value, JSAccessibilityController::accessibilityControllerClass()))
        return 0;
    return static_cast<AccessibilityController*>(JSWrapper::unwrap(context, value));
}

JSClassRef JSAccessibilityController::accessibilityControllerClass()
{
    static const JSClassRef jsClass = [] {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "AccessibilityController";
        definition.parentClass = 0;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        return JSClassCreate(&definition);
    }();
    return jsClass;
}

const JSStaticFunction* JSAccessibilityController::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "enableEnhancedAccessibility", enableEnhancedAccessibility, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setIsolatedTreeMode", setIsolatedTreeMode, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setForceDeferredSpellChecking", setForceDeferredSpellChecking, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setRetainedElement", setRetainedElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "retainedElement", retainedElement, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setForceInitialFrameCaching", setForceInitialFrameCaching, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "elementAtPoint", elementAtPoint, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "accessibleElementById", accessibleElementById, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "injectAccessibilityPreference", injectAccessibilityPreference, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "announce", announce, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "addNotificationListener", addNotificationListener, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "removeNotificationListener", removeNotificationListener, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "logFocusEvents", logFocusEvents, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "logValueChangeEvents", logValueChangeEvents, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "logScrollingStartEvents", logScrollingStartEvents, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "logAccessibilityEvents", logAccessibilityEvents, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "resetToConsistentState", resetToConsistentState, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "printTrees", printTrees, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "overrideClient", overrideClient, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0 }
    };
    return functions;
}

const JSStaticValue* JSAccessibilityController::staticValues()
{
    static const JSStaticValue values[] = {
        { "enhancedAccessibilityEnabled", enhancedAccessibilityEnabled, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "platformName", platformName, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rootElement", rootElement, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "focusedElement", focusedElement, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0, 0 }
    };
    return values;
}

// Functions

JSValueRef JSAccessibilityController::enableEnhancedAccessibility(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool enable = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &AccessibilityController::enableEnhancedAccessibility, enable);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::setIsolatedTreeMode(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool enable = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &AccessibilityController::setIsolatedTreeMode, enable);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::setForceDeferredSpellChecking(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool shouldForce = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &AccessibilityController::setForceDeferredSpellChecking, shouldForce);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::setRetainedElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto axElement = argumentCount > 0 ? toAccessibilityUIElement(context, arguments[0]) : nullptr;
    callFunction(context, impl, &AccessibilityController::setRetainedElement, axElement);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::retainedElement(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityController::retainedElement)));
}

JSValueRef JSAccessibilityController::setForceInitialFrameCaching(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool shouldForce = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &AccessibilityController::setForceInitialFrameCaching, shouldForce);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::elementAtPoint(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityController::elementAtPoint, x, y)));
}

JSValueRef JSAccessibilityController::accessibleElementById(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto id = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityController::accessibleElementById, id.get())));
}

JSValueRef JSAccessibilityController::injectAccessibilityPreference(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto domain = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto key = argumentCount > 1 ? createJSString(context, arguments[1]) : JSRetainPtr<JSStringRef>();
    auto value = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &AccessibilityController::injectAccessibilityPreference, domain.get(), key.get(), value.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::announce(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto message = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &AccessibilityController::announce, message.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::addNotificationListener(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto functionCallback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityController::addNotificationListener, functionCallback));
}

JSValueRef JSAccessibilityController::removeNotificationListener(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityController::removeNotificationListener));
}

JSValueRef JSAccessibilityController::logFocusEvents(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityController::logFocusEvents);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::logValueChangeEvents(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityController::logValueChangeEvents);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::logScrollingStartEvents(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityController::logScrollingStartEvents);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::logAccessibilityEvents(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityController::logAccessibilityEvents);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::resetToConsistentState(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityController::resetToConsistentState);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::printTrees(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &AccessibilityController::printTrees);

    return JSValueMakeUndefined(context);
}

JSValueRef JSAccessibilityController::overrideClient(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto clientType = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &AccessibilityController::overrideClient, clientType.get());

    return JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSAccessibilityController::enhancedAccessibilityEnabled(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityController::enhancedAccessibilityEnabled));
}

JSValueRef JSAccessibilityController::platformName(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return makeValue(context, callFunction(context, impl, &AccessibilityController::platformName).get());
}

JSValueRef JSAccessibilityController::rootElement(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityController::rootElement)));
}

JSValueRef JSAccessibilityController::focusedElement(JSContextRef context, JSObjectRef object, JSStringRef, JSValueRef* exception)
{
    AccessibilityController* impl = toAccessibilityController(context, object);
    if (!impl)
        return JSValueMakeUndefined(context);

    return toJS(context, WTF::getPtr(callFunction(context, impl, &AccessibilityController::focusedElement)));
}

} // namespace WTR

