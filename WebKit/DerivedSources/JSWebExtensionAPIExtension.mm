/*
 * Copyright (C) 2022-2023 Apple Inc. All rights reserved.
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

#include "JSWebExtensionAPIExtension.h"
#include "Logging.h"
#include "WebExtensionAPIExtension.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIExtension* toWebExtensionAPIExtension(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIExtension::extensionClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIExtension::extensionClass()))
        return nullptr;
    return static_cast<WebExtensionAPIExtension*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIExtension::extensionClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Extension";
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

JSClassRef JSWebExtensionAPIExtension::extensionGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Extension";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIExtension::staticFunctions()
{
    return nullptr;
}

const JSStaticValue* JSWebExtensionAPIExtension::staticValues()
{
    static const JSStaticValue values[] = {
        { "inIncognitoContext", isInIncognitoContext, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIExtension::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIExtension::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, extensionClass());
}

void JSWebExtensionAPIExtension::getPropertyNames(JSContextRef context, JSObjectRef thisObject, JSPropertyNameAccumulatorRef propertyNames)
{
    RefPtr impl = toWebExtensionAPIExtension(context, thisObject);
    if (!impl) [[unlikely]]
        return;

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (impl->isPropertyAllowed("getURL"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("getURL").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("getBackgroundPage").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("getViews").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("isAllowedIncognitoAccess").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("isAllowedFileSchemeAccess").get());

}

bool JSWebExtensionAPIExtension::hasProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName)
{
    RefPtr impl = toWebExtensionAPIExtension(context, thisObject);
    if (!impl) [[unlikely]]
        return false;

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (JSStringIsEqualToUTF8CString(propertyName, "getURL"))
        return impl->isPropertyAllowed("getURL"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "getBackgroundPage"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "getViews"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "isAllowedIncognitoAccess"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "isAllowedFileSchemeAccess"))
        return isForMainWorld;

    return false;
}

JSValueRef JSWebExtensionAPIExtension::getProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIExtension(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (JSStringIsEqualToUTF8CString(propertyName, "getURL") && impl->isPropertyAllowed("getURL"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, getURL);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "getBackgroundPage"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, getBackgroundPage);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "getViews"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, getViews);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "isAllowedIncognitoAccess"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, isAllowedIncognitoAccess);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "isAllowedFileSchemeAccess"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, isAllowedFileSchemeAccess);

    return JSValueMakeUndefined(context);
}

// Functions

JSValueRef JSWebExtensionAPIExtension::getURL(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIExtension(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function extension.getURL() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"extension.getURL()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
        *exception = toJSError(context, @"extension.getURL()", @"resourcePath", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    NSString *resourcePath = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);

    if (!resourcePath) [[unlikely]] {
        *exception = toJSError(context, @"extension.getURL()", @"resourcePath", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    JSValueRef result = toJSValueRef(context, impl->getURL(resourcePath, &exceptionString), NullOrEmptyString::NullStringAsNull);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"extension.getURL()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return result;
}

JSValueRef JSWebExtensionAPIExtension::getBackgroundPage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIExtension(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function extension.getBackgroundPage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRefOrJSNull(context, impl->getBackgroundPage(context));
}

JSValueRef JSWebExtensionAPIExtension::getViews(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIExtension(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function extension.getViews() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *filter;

    if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"extension.getViews()", @"filter", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        filter = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    NSString *exceptionString;
    JSValueRef result = toJSValueRefOrJSNull(context, impl->getViews(context, filter, &exceptionString));

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"extension.getViews()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return result;
}

JSValueRef JSWebExtensionAPIExtension::isAllowedIncognitoAccess(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIExtension(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function extension.isAllowedIncognitoAccess() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"extension.isAllowedIncognitoAccess()", @"callback", @"a function is expected");
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

    impl->isAllowedIncognitoAccess(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIExtension::isAllowedFileSchemeAccess(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIExtension(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function extension.isAllowedFileSchemeAccess() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"extension.isAllowedFileSchemeAccess()", @"callback", @"a function is expected");
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

    impl->isAllowedFileSchemeAccess(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIExtension::isInIncognitoContext(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIExtension(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter extension.inIncognitoContext in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    RefPtr page = toWebPage(context);
    if (!page) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Page could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeBoolean(context, impl->isInIncognitoContext(*page));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
