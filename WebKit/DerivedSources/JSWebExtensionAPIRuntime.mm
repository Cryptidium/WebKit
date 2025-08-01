/*
 * Copyright (C) 2022 Apple Inc. All rights reserved.
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
#include "JSWebExtensionAPIPort.h"
#include "JSWebExtensionAPIRuntime.h"
#include "Logging.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionAPIPort.h"
#include "WebExtensionAPIRuntime.h"
#include "WebExtensionUtilities.h"
#include "WebFrame.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIRuntime* toWebExtensionAPIRuntime(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIRuntime::runtimeClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIRuntime::runtimeClass()))
        return nullptr;
    return static_cast<WebExtensionAPIRuntime*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIRuntime::runtimeClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Runtime";
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

JSClassRef JSWebExtensionAPIRuntime::runtimeGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Runtime";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIRuntime::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "getURL", getURL, kJSPropertyAttributeNone },
        { "getManifest", getManifest, kJSPropertyAttributeNone },
        { "getFrameId", getFrameId, kJSPropertyAttributeNone },
        { "sendMessage", sendMessage, kJSPropertyAttributeNone },
        { "connect", connect, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIRuntime::staticValues()
{
    static const JSStaticValue values[] = {
        { "id", runtimeIdentifier, nullptr, kJSPropertyAttributeNone },
        { "onConnect", onConnect, nullptr, kJSPropertyAttributeNone },
        { "onMessage", onMessage, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIRuntime::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIRuntime::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, runtimeClass());
}

void JSWebExtensionAPIRuntime::getPropertyNames(JSContextRef context, JSObjectRef thisObject, JSPropertyNameAccumulatorRef propertyNames)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return;

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("getPlatformInfo").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("getBackgroundPage").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("setUninstallURL").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("openOptionsPage").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("reload").get());

    if (isForMainWorld && impl->isPropertyAllowed("sendNativeMessage"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("sendNativeMessage").get());

    if (isForMainWorld && impl->isPropertyAllowed("connectNative"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("connectNative").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("lastError").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("onConnectExternal").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("onMessageExternal").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("onStartup").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("onInstalled").get());

}

bool JSWebExtensionAPIRuntime::hasProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return false;

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (JSStringIsEqualToUTF8CString(propertyName, "getPlatformInfo"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "getBackgroundPage"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "setUninstallURL"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "openOptionsPage"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "reload"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "sendNativeMessage"))
        return isForMainWorld && impl->isPropertyAllowed("sendNativeMessage"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "connectNative"))
        return isForMainWorld && impl->isPropertyAllowed("connectNative"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "lastError"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "onConnectExternal"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "onMessageExternal"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "onStartup"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "onInstalled"))
        return isForMainWorld;

    return false;
}

JSValueRef JSWebExtensionAPIRuntime::getProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "lastError"))
        return lastError(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "onConnectExternal"))
        return onConnectExternal(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "onMessageExternal"))
        return onMessageExternal(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "onStartup"))
        return onStartup(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "onInstalled"))
        return onInstalled(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "getPlatformInfo"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, getPlatformInfo);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "getBackgroundPage"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, getBackgroundPage);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "setUninstallURL"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, setUninstallURL);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "openOptionsPage"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, openOptionsPage);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "reload"))
        return JSObjectMakeFunctionWithCallback(context, propertyName, reload);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "sendNativeMessage") && impl->isPropertyAllowed("sendNativeMessage"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, sendNativeMessage);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "connectNative") && impl->isPropertyAllowed("connectNative"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, connectNative);

    return JSValueMakeUndefined(context);
}

// Functions

JSValueRef JSWebExtensionAPIRuntime::getURL(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.getURL() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"runtime.getURL()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
        *exception = toJSError(context, @"runtime.getURL()", @"resourcePath", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    NSString *resourcePath = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);

    if (!resourcePath) [[unlikely]] {
        *exception = toJSError(context, @"runtime.getURL()", @"resourcePath", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    JSValueRef result = toJSValueRef(context, impl->getURL(resourcePath, &exceptionString), NullOrEmptyString::NullStringAsNull);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"runtime.getURL()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return result;
}

JSValueRef JSWebExtensionAPIRuntime::getManifest(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.getManifest() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRefOrJSNull(context, impl->getManifest());
}

JSValueRef JSWebExtensionAPIRuntime::getFrameId(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.getFrameId() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"runtime.getFrameId()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
        *exception = toJSError(context, @"runtime.getFrameId()", @"target", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSValue *target = toJSValue(context, arguments[0]);

    if (target && !target.isObject) [[unlikely]] {
        *exception = toJSError(context, @"runtime.getFrameId()", @"target", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeNumber(context, impl->getFrameId(target));
}

JSValueRef JSWebExtensionAPIRuntime::getPlatformInfo(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.getPlatformInfo() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.getPlatformInfo()", @"callback", @"a function is expected");
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

    impl->getPlatformInfo(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIRuntime::getBackgroundPage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.getBackgroundPage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.getBackgroundPage()", @"callback", @"a function is expected");
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

    impl->getBackgroundPage(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIRuntime::setUninstallURL(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.setUninstallURL() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"runtime.setUninstallURL()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSURL *url;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.setUninstallURL()", @"url", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.setUninstallURL()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        url = [NSURL URLWithString:toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString)];
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.setUninstallURL()", @"url", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        url = [NSURL URLWithString:toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString)];
    }

    if (!url) [[unlikely]] {
        *exception = toJSError(context, @"runtime.setUninstallURL()", @"url", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    if (url.isFileURL) [[unlikely]] {
        *exception = toJSError(context, @"runtime.setUninstallURL()", @"url", @"it cannot be a local file URL");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    impl->setUninstallURL(url, callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIRuntime::openOptionsPage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.openOptionsPage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.openOptionsPage()", @"callback", @"a function is expected");
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

    impl->openOptionsPage(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIRuntime::reload(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.reload() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    impl->reload();

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIRuntime::sendMessage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.sendMessage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    size_t argumentIndex = argumentCount;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"runtime.sendMessage()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *extensionID;
    NSString *message;
    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 4) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.sendMessage()", @"extensionID", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((!JSValueIsNull(context, arguments[1]) && !JSValueIsUndefined(context, arguments[1]) && !JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.sendMessage()", @"message", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[2]) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.sendMessage()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[3]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[3], nullptr))) || JSValueIsNull(context, arguments[3]) || JSValueIsUndefined(context, arguments[3]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.sendMessage()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        extensionID = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        message = serializeJSObject(context, arguments[1], exception);
        options = toNSDictionary(context, arguments[2], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[3], impl->runtime());
    } else {
        JSValueRef currentArgument = nullptr;
        size_t allowedOptionalArgumentCount = argumentCount - requiredArgumentCount;
        size_t processedOptionalArgumentCount = 0;
        argumentIndex = 0;

        if (allowedOptionalArgumentCount && (currentArgument = arguments[argumentCount - 1]) && ((JSValueIsObject(context, currentArgument) && JSObjectIsFunction(context, JSValueToObject(context, currentArgument, nullptr))) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument))) {
            callback = toJSCallbackHandler(context, currentArgument, impl->runtime());
            --allowedOptionalArgumentCount;
            if (argumentCount)
                --argumentCount;
        }

        if (argumentIndex < argumentCount && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsString(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                extensionID = toNSString(context, currentArgument, NullStringPolicy::NullAndUndefinedAsNullString);
                ++processedOptionalArgumentCount;
                ++argumentIndex;
            }
        }

        if (argumentIndex < argumentCount && (currentArgument = arguments[argumentIndex])) {
            if (!((!JSValueIsNull(context, currentArgument) && !JSValueIsUndefined(context, currentArgument) && !JSObjectIsFunction(context, JSValueToObject(context, currentArgument, nullptr))))) [[unlikely]] {
                *exception = toJSError(context, @"runtime.sendMessage()", @"message", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            message = serializeJSObject(context, currentArgument, exception);
            ++argumentIndex;
        }

        if (argumentIndex < argumentCount && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (isDictionary(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                options = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
                ++processedOptionalArgumentCount;
                ++argumentIndex;
            }
        }
    }

    if (*exception) [[unlikely]]
        return JSValueMakeUndefined(context);

    if (!message) [[unlikely]] {
        *exception = toJSError(context, @"runtime.sendMessage()", @"message", @"a JSON serializable value is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex < argumentCount) [[unlikely]] {
        *exception = toJSError(context, @"runtime.sendMessage()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"runtime.sendMessage()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        if (promiseResult)
            promiseResult = toJSRejectedPromise(context, @"runtime.sendMessage()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->sendMessage(page->webPageProxyIdentifier(), *frame, extensionID, message, options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"runtime.sendMessage()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIRuntime::connect(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.connect() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSString *extensionID;
    NSDictionary *options;

    if (argumentCount == 2) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.connect()", @"extensionID", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.connect()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        extensionID = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        options = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1 && !(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.connect()", @"extensionID", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        extensionID = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.connect()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    RefPtr page = toWebPage(context);
    if (!page) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Page could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    JSValueRef result = toJS(context, getPtr(impl->connect(page->webPageProxyIdentifier(), *frame, context, extensionID, options, &exceptionString)));

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"runtime.connect()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return result;
}

JSValueRef JSWebExtensionAPIRuntime::sendNativeMessage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.sendNativeMessage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"runtime.sendNativeMessage()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *applicationID;
    NSString *message;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.sendNativeMessage()", @"applicationID", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((!JSValueIsNull(context, arguments[1]) && !JSValueIsUndefined(context, arguments[1]) && !JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.sendNativeMessage()", @"message", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.sendNativeMessage()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        applicationID = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        message = serializeJSObject(context, arguments[1], exception);
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

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (!((!JSValueIsNull(context, currentArgument) && !JSValueIsUndefined(context, currentArgument) && !JSObjectIsFunction(context, JSValueToObject(context, currentArgument, nullptr))))) [[unlikely]] {
                *exception = toJSError(context, @"runtime.sendNativeMessage()", @"message", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            message = serializeJSObject(context, currentArgument, exception);
            --argumentIndex;
        }

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsString(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                applicationID = toNSString(context, currentArgument, NullStringPolicy::NullAndUndefinedAsNullString);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }
    }

    if (*exception) [[unlikely]]
        return JSValueMakeUndefined(context);

    if (!message) [[unlikely]] {
        *exception = toJSError(context, @"runtime.sendNativeMessage()", @"message", @"a JSON serializable value is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"runtime.sendNativeMessage()", nil, @"an unknown argument was provided");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        if (promiseResult)
            promiseResult = toJSRejectedPromise(context, @"runtime.sendNativeMessage()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    impl->sendNativeMessage(*frame, applicationID, message, callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIRuntime::connectNative(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function runtime.connectNative() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSString *applicationID;

    if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"runtime.connectNative()", @"applicationID", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        applicationID = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    RefPtr page = toWebPage(context);
    if (!page) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Page could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    return toJS(context, getPtr(impl->connectNative(page->webPageProxyIdentifier(), context, applicationID)));
}

// Attributes

JSValueRef JSWebExtensionAPIRuntime::runtimeIdentifier(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIRuntime(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter runtime.id in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRef(context, impl->runtimeIdentifier(), NullOrEmptyString::NullStringAsEmptyString);
}

JSValueRef JSWebExtensionAPIRuntime::lastError(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIRuntime(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter runtime.lastError in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRefOrJSNull(context, impl->lastError());
}

JSValueRef JSWebExtensionAPIRuntime::onConnect(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIRuntime(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter runtime.onConnect in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onConnect()));
}

JSValueRef JSWebExtensionAPIRuntime::onMessage(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIRuntime(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter runtime.onMessage in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onMessage()));
}

JSValueRef JSWebExtensionAPIRuntime::onConnectExternal(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIRuntime(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter runtime.onConnectExternal in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onConnectExternal()));
}

JSValueRef JSWebExtensionAPIRuntime::onMessageExternal(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIRuntime(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter runtime.onMessageExternal in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onMessageExternal()));
}

JSValueRef JSWebExtensionAPIRuntime::onStartup(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIRuntime(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter runtime.onStartup in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onStartup()));
}

JSValueRef JSWebExtensionAPIRuntime::onInstalled(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIRuntime(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter runtime.onInstalled in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onInstalled()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
