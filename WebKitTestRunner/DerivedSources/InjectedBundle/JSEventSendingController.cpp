/*
 * Copyright (C) 2010, 2011, 2014-2015 Apple Inc. All rights reserved.
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
#include "EventSendingController.h"
#include "JSEventSendingController.h"
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

EventSendingController* toEventSendingController(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSEventSendingController::eventSendingControllerClass() || !JSValueIsObjectOfClass(context, value, JSEventSendingController::eventSendingControllerClass()))
        return 0;
    return static_cast<EventSendingController*>(JSWrapper::unwrap(context, value));
}

JSClassRef JSEventSendingController::eventSendingControllerClass()
{
    static const JSClassRef jsClass = [] {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "EventSendingController";
        definition.parentClass = 0;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        return JSClassCreate(&definition);
    }();
    return jsClass;
}

const JSStaticFunction* JSEventSendingController::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "mouseDown", mouseDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mouseUp", mouseUp, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mouseMoveTo", mouseMoveTo, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "asyncMouseDown", asyncMouseDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "asyncMouseUp", asyncMouseUp, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "asyncMouseMoveTo", asyncMouseMoveTo, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mouseForceClick", mouseForceClick, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "startAndCancelMouseForceClick", startAndCancelMouseForceClick, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mouseForceDown", mouseForceDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mouseForceUp", mouseForceUp, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mouseForceChanged", mouseForceChanged, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mouseScrollBy", mouseScrollBy, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "mouseScrollByWithWheelAndMomentumPhases", mouseScrollByWithWheelAndMomentumPhases, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "setWheelHasPreciseDeltas", setWheelHasPreciseDeltas, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "continuousMouseScrollBy", continuousMouseScrollBy, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "contextClick", contextClick, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scheduleAsynchronousClick", scheduleAsynchronousClick, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "leapForward", leapForward, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "keyDown", keyDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rawKeyDown", rawKeyDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "rawKeyUp", rawKeyUp, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "scheduleAsynchronousKeyDown", scheduleAsynchronousKeyDown, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textZoomIn", textZoomIn, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "textZoomOut", textZoomOut, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "zoomPageIn", zoomPageIn, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "zoomPageOut", zoomPageOut, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "monitorWheelEvents", monitorWheelEvents, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "callAfterScrollingCompletes", callAfterScrollingCompletes, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { "smartMagnify", smartMagnify, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0 }
    };
    return functions;
}

const JSStaticValue* JSEventSendingController::staticValues()
{
    return 0;
}

// Functions

JSValueRef JSEventSendingController::mouseDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto buttonNumber = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto modifierArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto pointerType = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &EventSendingController::mouseDown, buttonNumber, modifierArray, pointerType.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::mouseUp(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto buttonNumber = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto modifierArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto pointerType = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &EventSendingController::mouseUp, buttonNumber, modifierArray, pointerType.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::mouseMoveTo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto pointerType = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &EventSendingController::mouseMoveTo, x, y, pointerType.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::asyncMouseDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto buttonNumber = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto modifierArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto pointerType = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &EventSendingController::asyncMouseDown, buttonNumber, modifierArray, pointerType.get(), resolveFunction);

    return promise;
}

JSValueRef JSEventSendingController::asyncMouseUp(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto buttonNumber = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto modifierArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto pointerType = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &EventSendingController::asyncMouseUp, buttonNumber, modifierArray, pointerType.get(), resolveFunction);

    return promise;
}

JSValueRef JSEventSendingController::asyncMouseMoveTo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto pointerType = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    JSObjectRef resolveFunction = nullptr;
    JSObjectRef promise = JSObjectMakeDeferredPromise(context, &resolveFunction, nullptr, nullptr);

    callFunction(context, impl, &EventSendingController::asyncMouseMoveTo, x, y, pointerType.get(), resolveFunction);

    return promise;
}

JSValueRef JSEventSendingController::mouseForceClick(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::mouseForceClick);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::startAndCancelMouseForceClick(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::startAndCancelMouseForceClick);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::mouseForceDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::mouseForceDown);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::mouseForceUp(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::mouseForceUp);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::mouseForceChanged(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto force = argumentCount > 0 ? JSValueToNumber(context, arguments[0], nullptr) : double();
    callFunction(context, impl, &EventSendingController::mouseForceChanged, force);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::mouseScrollBy(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    callFunction(context, impl, &EventSendingController::mouseScrollBy, x, y);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::mouseScrollByWithWheelAndMomentumPhases(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    auto phase = argumentCount > 2 ? createJSString(context, arguments[2]) : JSRetainPtr<JSStringRef>();
    auto momentum = argumentCount > 3 ? createJSString(context, arguments[3]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &EventSendingController::mouseScrollByWithWheelAndMomentumPhases, x, y, phase.get(), momentum.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::setWheelHasPreciseDeltas(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    bool hasPreciseDeltas = argumentCount > 0 && JSValueToBoolean(context, arguments[0]);
    callFunction(context, impl, &EventSendingController::setWheelHasPreciseDeltas, hasPreciseDeltas);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::continuousMouseScrollBy(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto x = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    auto y = argumentCount > 1 ? clampTo<int32_t>(JSValueToNumber(context, arguments[1], nullptr)) : int32_t();
    bool paged = argumentCount > 2 && JSValueToBoolean(context, arguments[2]);
    callFunction(context, impl, &EventSendingController::continuousMouseScrollBy, x, y, paged);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::contextClick(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    return callFunction(context, impl, &EventSendingController::contextClick);
}

JSValueRef JSEventSendingController::scheduleAsynchronousClick(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::scheduleAsynchronousClick);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::leapForward(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto milliseconds = argumentCount > 0 ? clampTo<int32_t>(JSValueToNumber(context, arguments[0], nullptr)) : int32_t();
    callFunction(context, impl, &EventSendingController::leapForward, milliseconds);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::keyDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto key = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto modifierArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto location = argumentCount > 2 ? clampTo<int32_t>(JSValueToNumber(context, arguments[2], nullptr)) : int32_t();
    callFunction(context, impl, &EventSendingController::keyDown, key.get(), modifierArray, location);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::rawKeyDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto key = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto modifierArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto location = argumentCount > 2 ? clampTo<int32_t>(JSValueToNumber(context, arguments[2], nullptr)) : int32_t();
    callFunction(context, impl, &EventSendingController::rawKeyDown, key.get(), modifierArray, location);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::rawKeyUp(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto key = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    auto modifierArray = argumentCount > 1 ? arguments[1] : JSValueMakeUndefined(context);
    auto location = argumentCount > 2 ? clampTo<int32_t>(JSValueToNumber(context, arguments[2], nullptr)) : int32_t();
    callFunction(context, impl, &EventSendingController::rawKeyUp, key.get(), modifierArray, location);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::scheduleAsynchronousKeyDown(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto key = argumentCount > 0 ? createJSString(context, arguments[0]) : JSRetainPtr<JSStringRef>();
    callFunction(context, impl, &EventSendingController::scheduleAsynchronousKeyDown, key.get());

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::textZoomIn(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::textZoomIn);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::textZoomOut(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::textZoomOut);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::zoomPageIn(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::zoomPageIn);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::zoomPageOut(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::zoomPageOut);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::monitorWheelEvents(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto options = argumentCount > 0 ? toMonitorWheelEventsOptions(context, arguments[0]) : nullptr;
    callFunction(context, impl, &EventSendingController::monitorWheelEvents, options);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::callAfterScrollingCompletes(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto functionCallback = argumentCount > 0 ? arguments[0] : JSValueMakeUndefined(context);
    callFunction(context, impl, &EventSendingController::callAfterScrollingCompletes, functionCallback);

    return JSValueMakeUndefined(context);
}

JSValueRef JSEventSendingController::smartMagnify(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    EventSendingController* impl = toEventSendingController(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    callFunction(context, impl, &EventSendingController::smartMagnify);

    return JSValueMakeUndefined(context);
}

} // namespace WTR

