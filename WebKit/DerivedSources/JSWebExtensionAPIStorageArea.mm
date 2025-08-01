/*
 * Copyright (C) 2024 Apple Inc. All rights reserved.
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

#include "JSWebExtensionAPIEvent.h"
#include "JSWebExtensionAPIStorageArea.h"
#include "Logging.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionAPIStorageArea.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIStorageArea* toWebExtensionAPIStorageArea(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIStorageArea::storageAreaClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIStorageArea::storageAreaClass()))
        return nullptr;
    return static_cast<WebExtensionAPIStorageArea*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIStorageArea::storageAreaClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "StorageArea";
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

JSClassRef JSWebExtensionAPIStorageArea::storageAreaGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "StorageArea";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIStorageArea::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "get", get, kJSPropertyAttributeNone },
        { "getKeys", getKeys, kJSPropertyAttributeNone },
        { "getBytesInUse", getBytesInUse, kJSPropertyAttributeNone },
        { "set", set, kJSPropertyAttributeNone },
        { "remove", remove, kJSPropertyAttributeNone },
        { "clear", clear, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIStorageArea::staticValues()
{
    static const JSStaticValue values[] = {
        { "onChanged", onChanged, nullptr, kJSPropertyAttributeNone },
        { "QUOTA_BYTES", quotaBytes, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIStorageArea::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIStorageArea::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, storageAreaClass());
}

void JSWebExtensionAPIStorageArea::getPropertyNames(JSContextRef context, JSObjectRef thisObject, JSPropertyNameAccumulatorRef propertyNames)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return;

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (isForMainWorld && impl->isPropertyAllowed("setAccessLevel"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("setAccessLevel").get());

    if (impl->isPropertyAllowed("QUOTA_BYTES_PER_ITEM"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("QUOTA_BYTES_PER_ITEM").get());

    if (impl->isPropertyAllowed("MAX_ITEMS"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("MAX_ITEMS").get());

    if (impl->isPropertyAllowed("MAX_WRITE_OPERATIONS_PER_HOUR"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("MAX_WRITE_OPERATIONS_PER_HOUR").get());

    if (impl->isPropertyAllowed("MAX_WRITE_OPERATIONS_PER_MINUTE"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("MAX_WRITE_OPERATIONS_PER_MINUTE").get());

}

bool JSWebExtensionAPIStorageArea::hasProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return false;

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (JSStringIsEqualToUTF8CString(propertyName, "setAccessLevel"))
        return isForMainWorld && impl->isPropertyAllowed("setAccessLevel"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "QUOTA_BYTES_PER_ITEM"))
        return impl->isPropertyAllowed("QUOTA_BYTES_PER_ITEM"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "MAX_ITEMS"))
        return impl->isPropertyAllowed("MAX_ITEMS"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "MAX_WRITE_OPERATIONS_PER_HOUR"))
        return impl->isPropertyAllowed("MAX_WRITE_OPERATIONS_PER_HOUR"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "MAX_WRITE_OPERATIONS_PER_MINUTE"))
        return impl->isPropertyAllowed("MAX_WRITE_OPERATIONS_PER_MINUTE"_s, page.get());

    return false;
}

JSValueRef JSWebExtensionAPIStorageArea::getProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (JSStringIsEqualToUTF8CString(propertyName, "QUOTA_BYTES_PER_ITEM") && impl->isPropertyAllowed("QUOTA_BYTES_PER_ITEM"_s, page.get()))
        return quotaBytesPerItem(context, thisObject, propertyName, exception);

    if (JSStringIsEqualToUTF8CString(propertyName, "MAX_ITEMS") && impl->isPropertyAllowed("MAX_ITEMS"_s, page.get()))
        return maxItems(context, thisObject, propertyName, exception);

    if (JSStringIsEqualToUTF8CString(propertyName, "MAX_WRITE_OPERATIONS_PER_HOUR") && impl->isPropertyAllowed("MAX_WRITE_OPERATIONS_PER_HOUR"_s, page.get()))
        return maxWriteOperationsPerHour(context, thisObject, propertyName, exception);

    if (JSStringIsEqualToUTF8CString(propertyName, "MAX_WRITE_OPERATIONS_PER_MINUTE") && impl->isPropertyAllowed("MAX_WRITE_OPERATIONS_PER_MINUTE"_s, page.get()))
        return maxWriteOperationsPerMinute(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "setAccessLevel") && impl->isPropertyAllowed("setAccessLevel"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, setAccessLevel);

    return JSValueMakeUndefined(context);
}

// Functions

JSValueRef JSWebExtensionAPIStorageArea::get(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function storageArea.get() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSObject *items;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.get()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        items = toNSObject(context, arguments[0], Nil, NullValuePolicy::Allowed, ValuePolicy::StopAtTopLevel);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        items = toNSObject(context, arguments[0], Nil, NullValuePolicy::Allowed, ValuePolicy::StopAtTopLevel);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.get()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"storageArea.get()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->get(page->webPageProxyIdentifier(), items, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.get()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIStorageArea::getKeys(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function storageArea.getKeys() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.getKeys()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"storageArea.getKeys()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->getKeys(page->webPageProxyIdentifier(), callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.getKeys()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIStorageArea::getBytesInUse(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function storageArea.getBytesInUse() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSObject *keys;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.getBytesInUse()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        keys = toNSObject(context, arguments[0]);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        keys = toNSObject(context, arguments[0]);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.getBytesInUse()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"storageArea.getBytesInUse()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->getBytesInUse(page->webPageProxyIdentifier(), keys, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.getBytesInUse()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIStorageArea::set(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function storageArea.set() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.set()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *items;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.set()", @"items", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.set()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        items = toNSDictionary(context, arguments[0], NullValuePolicy::Allowed, ValuePolicy::StopAtTopLevel);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.set()", @"items", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        items = toNSDictionary(context, arguments[0], NullValuePolicy::Allowed, ValuePolicy::StopAtTopLevel);
    }

    if (!items) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.set()", @"items", @"an object is expected");
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
            promiseResult = toJSRejectedPromise(context, @"storageArea.set()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->set(page->webPageProxyIdentifier(), items, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.set()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIStorageArea::remove(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function storageArea.remove() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.remove()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSObject *keys;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.remove()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        keys = toNSObject(context, arguments[0]);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        keys = toNSObject(context, arguments[0]);
    }

    if (!keys) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.remove()", @"keys", @"an object is expected");
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
            promiseResult = toJSRejectedPromise(context, @"storageArea.remove()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->remove(page->webPageProxyIdentifier(), keys, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.remove()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIStorageArea::clear(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function storageArea.clear() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.clear()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"storageArea.clear()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    impl->clear(page->webPageProxyIdentifier(), callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIStorageArea::setAccessLevel(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorageArea(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function storageArea.setAccessLevel() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.setAccessLevel()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *accessOptions;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.setAccessLevel()", @"accessOptions", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.setAccessLevel()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        accessOptions = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"storageArea.setAccessLevel()", @"accessOptions", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        accessOptions = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!accessOptions) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.setAccessLevel()", @"accessOptions", @"an object is expected");
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
            promiseResult = toJSRejectedPromise(context, @"storageArea.setAccessLevel()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->setAccessLevel(page->webPageProxyIdentifier(), accessOptions, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"storageArea.setAccessLevel()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIStorageArea::onChanged(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorageArea(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storageArea.onChanged in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onChanged()));
}

JSValueRef JSWebExtensionAPIStorageArea::quotaBytes(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorageArea(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storageArea.QUOTA_BYTES in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->quotaBytes());
}

JSValueRef JSWebExtensionAPIStorageArea::quotaBytesPerItem(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorageArea(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storageArea.QUOTA_BYTES_PER_ITEM in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->quotaBytesPerItem());
}

JSValueRef JSWebExtensionAPIStorageArea::maxItems(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorageArea(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storageArea.MAX_ITEMS in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->maxItems());
}

JSValueRef JSWebExtensionAPIStorageArea::maxWriteOperationsPerHour(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorageArea(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storageArea.MAX_WRITE_OPERATIONS_PER_HOUR in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->maxWriteOperationsPerHour());
}

JSValueRef JSWebExtensionAPIStorageArea::maxWriteOperationsPerMinute(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorageArea(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storageArea.MAX_WRITE_OPERATIONS_PER_MINUTE in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->maxWriteOperationsPerMinute());
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
