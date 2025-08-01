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
#include "JSAccessibilityTextMarker.h"
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

AccessibilityTextMarker* toAccessibilityTextMarker(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSAccessibilityTextMarker::accessibilityTextMarkerClass() || !JSValueIsObjectOfClass(context, value, JSAccessibilityTextMarker::accessibilityTextMarkerClass()))
        return 0;
    return static_cast<AccessibilityTextMarker*>(JSWrapper::unwrap(context, value));
}

JSClassRef JSAccessibilityTextMarker::accessibilityTextMarkerClass()
{
    static const JSClassRef jsClass = [] {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "AccessibilityTextMarker";
        definition.parentClass = 0;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        return JSClassCreate(&definition);
    }();
    return jsClass;
}

const JSStaticFunction* JSAccessibilityTextMarker::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "isEqual", isEqual, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
        { 0, 0, 0 }
    };
    return functions;
}

const JSStaticValue* JSAccessibilityTextMarker::staticValues()
{
    return 0;
}

// Functions

JSValueRef JSAccessibilityTextMarker::isEqual(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    AccessibilityTextMarker* impl = toAccessibilityTextMarker(context, thisObject);
    if (!impl)
        return JSValueMakeUndefined(context);

    auto otherMarker = argumentCount > 0 ? toAccessibilityTextMarker(context, arguments[0]) : nullptr;
    return JSValueMakeBoolean(context, callFunction(context, impl, &AccessibilityTextMarker::isEqual, otherMarker));
}

} // namespace WTR

