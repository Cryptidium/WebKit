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

#include "JSWebExtensionAPIWindows.h"
#include "JSWebExtensionAPIWindowsEvent.h"
#include "Logging.h"
#include "WebExtensionAPIWindows.h"
#include "WebExtensionAPIWindowsEvent.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIWindows* toWebExtensionAPIWindows(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIWindows::windowsClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIWindows::windowsClass()))
        return nullptr;
    return static_cast<WebExtensionAPIWindows*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIWindows::windowsClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Windows";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        definition.getPropertyNames = getPropertyNames;
        definition.hasProperty = hasProperty;
        definition.getProperty = getProperty;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIWindows::windowsGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Windows";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIWindows::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "get", get, kJSPropertyAttributeNone },
        { "getCurrent", getCurrent, kJSPropertyAttributeNone },
        { "getLastFocused", getLastFocused, kJSPropertyAttributeNone },
        { "getAll", getAll, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIWindows::staticValues()
{
    static const JSStaticValue values[] = {
        { "WINDOW_ID_NONE", windowIdentifierNone, nullptr, kJSPropertyAttributeNone },
        { "WINDOW_ID_CURRENT", windowIdentifierCurrent, nullptr, kJSPropertyAttributeNone },
        { "onCreated", onCreated, nullptr, kJSPropertyAttributeNone },
        { "onRemoved", onRemoved, nullptr, kJSPropertyAttributeNone },
        { "onFocusChanged", onFocusChanged, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIWindows::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIWindows::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, windowsClass());
}

void JSWebExtensionAPIWindows::getPropertyNames(JSContextRef context, JSObjectRef thisObject, JSPropertyNameAccumulatorRef propertyNames)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl) [[unlikely]]
        return;

    RefPtr page = toWebPage(context);
    if (impl->isPropertyAllowed("create"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("create").get());

    if (impl->isPropertyAllowed("update"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("update").get());

    if (impl->isPropertyAllowed("remove"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("remove").get());

}

bool JSWebExtensionAPIWindows::hasProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl) [[unlikely]]
        return false;

    RefPtr page = toWebPage(context);
    if (JSStringIsEqualToUTF8CString(propertyName, "create"))
        return impl->isPropertyAllowed("create"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "update"))
        return impl->isPropertyAllowed("update"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "remove"))
        return impl->isPropertyAllowed("remove"_s, page.get());

    return false;
}

JSValueRef JSWebExtensionAPIWindows::getProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RefPtr page = toWebPage(context);
    if (JSStringIsEqualToUTF8CString(propertyName, "create") && impl->isPropertyAllowed("create"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, create);

    if (JSStringIsEqualToUTF8CString(propertyName, "update") && impl->isPropertyAllowed("update"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, update);

    if (JSStringIsEqualToUTF8CString(propertyName, "remove") && impl->isPropertyAllowed("remove"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, remove);

    return JSValueMakeUndefined(context);
}

// Functions

JSValueRef JSWebExtensionAPIWindows::create(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function windows.create() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *info;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.create()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.create()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.create()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.create()", @"callback", @"a function is expected");
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

    NSString *exceptionString;
    impl->createWindow(info, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"windows.create()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIWindows::get(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function windows.get() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"windows.get()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double windowID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *properties;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.get()", @"windowID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.get()", @"properties", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.get()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        windowID = JSValueToNumber(context, arguments[0], nullptr);
        properties = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[2], impl->runtime());
    } else {
        JSValueRef currentArgument = nullptr;
        size_t allowedOptionalArgumentCount = argumentCount - requiredArgumentCount;
        size_t processedOptionalArgumentCount = 0;
        argumentIndex = argumentCount - 1;

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if ((JSValueIsObject(context, currentArgument) && JSObjectIsFunction(context, JSValueToObject(context, currentArgument, nullptr))) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                callback = toJSCallbackHandler(context, currentArgument, impl->runtime());
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (isDictionary(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                properties = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (!(JSValueIsNumber(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"windows.get()", @"windowID", @"a number is expected");
                return JSValueMakeUndefined(context);
            }

            windowID = JSValueToNumber(context, currentArgument, nullptr);
            --argumentIndex;
        }
    }

    if (!std::isfinite(windowID)) [[unlikely]] {
        *exception = toJSError(context, @"windows.get()", @"windowID", @"a number is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"windows.get()", nil, @"an unknown argument was provided");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    RefPtr page = toWebPage(context);
    if (!page) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Page could not be found for JSContextRef");
        if (promiseResult)
            promiseResult = toJSRejectedPromise(context, @"windows.get()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->get(page->webPageProxyIdentifier(), windowID, properties, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"windows.get()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIWindows::getCurrent(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function windows.getCurrent() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *info;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getCurrent()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getCurrent()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getCurrent()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getCurrent()", @"callback", @"a function is expected");
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

    RefPtr page = toWebPage(context);
    if (!page) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Page could not be found for JSContextRef");
        if (promiseResult)
            promiseResult = toJSRejectedPromise(context, @"windows.getCurrent()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->getCurrent(page->webPageProxyIdentifier(), info, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"windows.getCurrent()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIWindows::getLastFocused(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function windows.getLastFocused() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *info;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getLastFocused()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getLastFocused()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getLastFocused()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getLastFocused()", @"callback", @"a function is expected");
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

    NSString *exceptionString;
    impl->getLastFocused(info, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"windows.getLastFocused()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIWindows::getAll(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function windows.getAll() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *info;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getAll()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getAll()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getAll()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.getAll()", @"callback", @"a function is expected");
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

    NSString *exceptionString;
    impl->getAll(info, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"windows.getAll()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIWindows::update(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function windows.update() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 2;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"windows.update()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double windowID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *properties;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.update()", @"windowID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.update()", @"properties", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.update()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        windowID = JSValueToNumber(context, arguments[0], nullptr);
        properties = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[2], impl->runtime());
    } else if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.update()", @"windowID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.update()", @"properties", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        windowID = JSValueToNumber(context, arguments[0], nullptr);
        properties = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
    }

    if (!std::isfinite(windowID)) [[unlikely]] {
        *exception = toJSError(context, @"windows.update()", @"windowID", @"a number is expected");
        return JSValueMakeUndefined(context);
    }

    if (!properties) [[unlikely]] {
        *exception = toJSError(context, @"windows.update()", @"properties", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->update(windowID, properties, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"windows.update()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIWindows::remove(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWindows(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function windows.remove() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"windows.remove()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double windowID = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.remove()", @"windowID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.remove()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        windowID = JSValueToNumber(context, arguments[0], nullptr);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"windows.remove()", @"windowID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        windowID = JSValueToNumber(context, arguments[0], nullptr);
    }

    if (!std::isfinite(windowID)) [[unlikely]] {
        *exception = toJSError(context, @"windows.remove()", @"windowID", @"a number is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->remove(windowID, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"windows.remove()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIWindows::windowIdentifierNone(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWindows(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter windows.WINDOW_ID_NONE in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->windowIdentifierNone());
}

JSValueRef JSWebExtensionAPIWindows::windowIdentifierCurrent(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWindows(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter windows.WINDOW_ID_CURRENT in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->windowIdentifierCurrent());
}

JSValueRef JSWebExtensionAPIWindows::onCreated(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWindows(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter windows.onCreated in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onCreated()));
}

JSValueRef JSWebExtensionAPIWindows::onRemoved(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWindows(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter windows.onRemoved in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onRemoved()));
}

JSValueRef JSWebExtensionAPIWindows::onFocusChanged(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWindows(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter windows.onFocusChanged in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onFocusChanged()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
