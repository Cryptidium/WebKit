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

#include "JSWebExtensionAPICookies.h"
#include "JSWebExtensionAPIEvent.h"
#include "Logging.h"
#include "WebExtensionAPICookies.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPICookies* toWebExtensionAPICookies(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPICookies::cookiesClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPICookies::cookiesClass()))
        return nullptr;
    return static_cast<WebExtensionAPICookies*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPICookies::cookiesClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Cookies";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPICookies::cookiesGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Cookies";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPICookies::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "get", get, kJSPropertyAttributeNone },
        { "getAll", getAll, kJSPropertyAttributeNone },
        { "set", set, kJSPropertyAttributeNone },
        { "remove", remove, kJSPropertyAttributeNone },
        { "getAllCookieStores", getAllCookieStores, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPICookies::staticValues()
{
    static const JSStaticValue values[] = {
        { "onChanged", onChanged, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPICookies::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPICookies::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, cookiesClass());
}

// Functions

JSValueRef JSWebExtensionAPICookies::get(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPICookies(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function cookies.get() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"cookies.get()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.get()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.get()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.get()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"cookies.get()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->get(details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"cookies.get()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPICookies::getAll(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPICookies(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function cookies.getAll() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"cookies.getAll()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.getAll()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.getAll()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.getAll()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"cookies.getAll()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->getAll(details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"cookies.getAll()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPICookies::set(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPICookies(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function cookies.set() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"cookies.set()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.set()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.set()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.set()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"cookies.set()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->set(details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"cookies.set()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPICookies::remove(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPICookies(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function cookies.remove() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"cookies.remove()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.remove()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.remove()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.remove()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"cookies.remove()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->remove(details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"cookies.remove()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPICookies::getAllCookieStores(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPICookies(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function cookies.getAllCookieStores() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"cookies.getAllCookieStores()", @"callback", @"a function is expected");
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

    impl->getAllCookieStores(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPICookies::onChanged(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPICookies(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter cookies.onChanged in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onChanged()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
