/*
 * Copyright (C) 2023 Apple Inc. All rights reserved.
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

#if !__has_feature(objc_arc)
#error This file requires ARC. Add the "-fobjc-arc" compiler flag for this file.
#endif

#include "config.h"

#if ENABLE(WK_WEB_EXTENSIONS)

#include "JSWebExtensionAPIAlarms.h"
#include "JSWebExtensionAPIEvent.h"
#include "Logging.h"
#include "WebExtensionAPIAlarms.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIAlarms* toWebExtensionAPIAlarms(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIAlarms::alarmsClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIAlarms::alarmsClass()))
        return nullptr;
    return static_cast<WebExtensionAPIAlarms*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIAlarms::alarmsClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Alarms";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIAlarms::alarmsGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Alarms";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIAlarms::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "create", create, kJSPropertyAttributeNone },
        { "get", get, kJSPropertyAttributeNone },
        { "getAll", getAll, kJSPropertyAttributeNone },
        { "clear", clear, kJSPropertyAttributeNone },
        { "clearAll", clearAll, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIAlarms::staticValues()
{
    static const JSStaticValue values[] = {
        { "onAlarm", onAlarm, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIAlarms::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIAlarms::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, alarmsClass());
}

// Functions

JSValueRef JSWebExtensionAPIAlarms::create(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIAlarms(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function alarms.create() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"alarms.create()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *name;
    NSDictionary *info;

    if (argumentCount == 2) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.create()", @"name", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.create()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        name = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        info = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
    } else {
        JSValueRef currentArgument = nullptr;
        size_t allowedOptionalArgumentCount = argumentCount - requiredArgumentCount;
        size_t processedOptionalArgumentCount = 0;
        argumentIndex = argumentCount - 1;

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (!(isDictionary(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"alarms.create()", @"info", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            info = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
            --argumentIndex;
        }

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsString(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                name = toNSString(context, currentArgument, NullStringPolicy::NullAndUndefinedAsNullString);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }
    }

    if (!info) [[unlikely]] {
        *exception = toJSError(context, @"alarms.create()", @"info", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"alarms.create()", nil, @"an unknown argument was provided");
        return JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->createAlarm(name, info, &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"alarms.create()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIAlarms::get(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIAlarms(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function alarms.get() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSString *name;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.get()", @"name", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.get()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        name = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.get()", @"name", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        name = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.get()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        callback = toJSCallbackHandler(context, arguments[0], impl->runtime());
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    impl->get(name, callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIAlarms::getAll(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIAlarms(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function alarms.getAll() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.getAll()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        callback = toJSCallbackHandler(context, arguments[0], impl->runtime());
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    impl->getAll(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIAlarms::clear(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIAlarms(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function alarms.clear() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSString *name;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.clear()", @"name", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.clear()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        name = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.clear()", @"name", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        name = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.clear()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        callback = toJSCallbackHandler(context, arguments[0], impl->runtime());
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    impl->clear(name, callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIAlarms::clearAll(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIAlarms(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function alarms.clearAll() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"alarms.clearAll()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        callback = toJSCallbackHandler(context, arguments[0], impl->runtime());
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    impl->clearAll(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIAlarms::onAlarm(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIAlarms(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter alarms.onAlarm in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onAlarm()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
