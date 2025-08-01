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

#include "JSWebExtensionAPIEvent.h"
#include "JSWebExtensionAPIPort.h"
#include "JSWebExtensionAPITabs.h"
#include "Logging.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionAPIPort.h"
#include "WebExtensionAPITabs.h"
#include "WebExtensionUtilities.h"
#include "WebFrame.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPITabs* toWebExtensionAPITabs(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPITabs::tabsClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPITabs::tabsClass()))
        return nullptr;
    return static_cast<WebExtensionAPITabs*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPITabs::tabsClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Tabs";
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

JSClassRef JSWebExtensionAPITabs::tabsGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Tabs";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPITabs::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "create", create, kJSPropertyAttributeNone },
        { "query", query, kJSPropertyAttributeNone },
        { "get", get, kJSPropertyAttributeNone },
        { "getCurrent", getCurrent, kJSPropertyAttributeNone },
        { "duplicate", duplicate, kJSPropertyAttributeNone },
        { "update", update, kJSPropertyAttributeNone },
        { "remove", remove, kJSPropertyAttributeNone },
        { "reload", reload, kJSPropertyAttributeNone },
        { "goBack", goBack, kJSPropertyAttributeNone },
        { "goForward", goForward, kJSPropertyAttributeNone },
        { "getZoom", getZoom, kJSPropertyAttributeNone },
        { "setZoom", setZoom, kJSPropertyAttributeNone },
        { "detectLanguage", detectLanguage, kJSPropertyAttributeNone },
        { "toggleReaderMode", toggleReaderMode, kJSPropertyAttributeNone },
        { "captureVisibleTab", captureVisibleTab, kJSPropertyAttributeNone },
        { "sendMessage", sendMessage, kJSPropertyAttributeNone },
        { "connect", connect, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPITabs::staticValues()
{
    static const JSStaticValue values[] = {
        { "TAB_ID_NONE", tabIdentifierNone, nullptr, kJSPropertyAttributeNone },
        { "onActivated", onActivated, nullptr, kJSPropertyAttributeNone },
        { "onAttached", onAttached, nullptr, kJSPropertyAttributeNone },
        { "onCreated", onCreated, nullptr, kJSPropertyAttributeNone },
        { "onDetached", onDetached, nullptr, kJSPropertyAttributeNone },
        { "onHighlighted", onHighlighted, nullptr, kJSPropertyAttributeNone },
        { "onMoved", onMoved, nullptr, kJSPropertyAttributeNone },
        { "onRemoved", onRemoved, nullptr, kJSPropertyAttributeNone },
        { "onReplaced", onReplaced, nullptr, kJSPropertyAttributeNone },
        { "onUpdated", onUpdated, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPITabs::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPITabs::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, tabsClass());
}

void JSWebExtensionAPITabs::getPropertyNames(JSContextRef context, JSObjectRef thisObject, JSPropertyNameAccumulatorRef propertyNames)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl) [[unlikely]]
        return;

    RefPtr page = toWebPage(context);
    if (impl->isPropertyAllowed("getSelected"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("getSelected").get());

    if (impl->isPropertyAllowed("executeScript"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("executeScript").get());

    if (impl->isPropertyAllowed("insertCSS"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("insertCSS").get());

    if (impl->isPropertyAllowed("removeCSS"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("removeCSS").get());

}

bool JSWebExtensionAPITabs::hasProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl) [[unlikely]]
        return false;

    RefPtr page = toWebPage(context);
    if (JSStringIsEqualToUTF8CString(propertyName, "getSelected"))
        return impl->isPropertyAllowed("getSelected"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "executeScript"))
        return impl->isPropertyAllowed("executeScript"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "insertCSS"))
        return impl->isPropertyAllowed("insertCSS"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "removeCSS"))
        return impl->isPropertyAllowed("removeCSS"_s, page.get());

    return false;
}

JSValueRef JSWebExtensionAPITabs::getProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RefPtr page = toWebPage(context);
    if (JSStringIsEqualToUTF8CString(propertyName, "getSelected") && impl->isPropertyAllowed("getSelected"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, getSelected);

    if (JSStringIsEqualToUTF8CString(propertyName, "executeScript") && impl->isPropertyAllowed("executeScript"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, executeScript);

    if (JSStringIsEqualToUTF8CString(propertyName, "insertCSS") && impl->isPropertyAllowed("insertCSS"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, insertCSS);

    if (JSStringIsEqualToUTF8CString(propertyName, "removeCSS") && impl->isPropertyAllowed("removeCSS"_s, page.get()))
        return JSObjectMakeFunctionWithCallback(context, propertyName, removeCSS);

    return JSValueMakeUndefined(context);
}

// Functions

JSValueRef JSWebExtensionAPITabs::create(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.create() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.create()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *properties;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.create()", @"properties", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.create()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        properties = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.create()", @"properties", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        properties = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!properties) [[unlikely]] {
        *exception = toJSError(context, @"tabs.create()", @"properties", @"an object is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.create()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->createTab(page->webPageProxyIdentifier(), properties, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.create()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::query(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.query() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.query()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *info;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.query()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.query()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.query()", @"info", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        info = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!info) [[unlikely]] {
        *exception = toJSError(context, @"tabs.query()", @"info", @"an object is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.query()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->query(page->webPageProxyIdentifier(), info, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.query()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::get(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.get() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.get()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.get()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.get()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.get()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
    }

    if (!std::isfinite(tabID)) [[unlikely]] {
        *exception = toJSError(context, @"tabs.get()", @"tabID", @"a number is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->get(tabID, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.get()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::getCurrent(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.getCurrent() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getCurrent()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.getCurrent()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    impl->getCurrent(page->webPageProxyIdentifier(), callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::getSelected(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.getSelected() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    double windowID = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getSelected()", @"windowID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getSelected()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        windowID = JSValueToNumber(context, arguments[0], nullptr);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getSelected()", @"windowID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        windowID = JSValueToNumber(context, arguments[0], nullptr);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getSelected()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.getSelected()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->getSelected(page->webPageProxyIdentifier(), windowID, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.getSelected()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::duplicate(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.duplicate() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.duplicate()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *properties;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.duplicate()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.duplicate()", @"properties", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.duplicate()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
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
                *exception = toJSError(context, @"tabs.duplicate()", @"tabID", @"a number is expected");
                return JSValueMakeUndefined(context);
            }

            tabID = JSValueToNumber(context, currentArgument, nullptr);
            --argumentIndex;
        }
    }

    if (!std::isfinite(tabID)) [[unlikely]] {
        *exception = toJSError(context, @"tabs.duplicate()", @"tabID", @"a number is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"tabs.duplicate()", nil, @"an unknown argument was provided");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->duplicate(tabID, properties, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.duplicate()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::update(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.update() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.update()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *properties;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.update()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.update()", @"properties", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.update()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
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

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (!(isDictionary(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"tabs.update()", @"properties", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            properties = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
            --argumentIndex;
        }

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsNumber(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                tabID = JSValueToNumber(context, currentArgument, nullptr);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }
    }

    if (!properties) [[unlikely]] {
        *exception = toJSError(context, @"tabs.update()", @"properties", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"tabs.update()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.update()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->update(page->webPageProxyIdentifier(), tabID, properties, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.update()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::remove(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.remove() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.remove()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSObject *tabIDs;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.remove()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabIDs = toNSObject(context, arguments[0]);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        tabIDs = toNSObject(context, arguments[0]);
    }

    if (!tabIDs) [[unlikely]] {
        *exception = toJSError(context, @"tabs.remove()", @"tabIDs", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->remove(tabIDs, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.remove()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::reload(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.reload() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    double tabID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *properties;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.reload()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.reload()", @"properties", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.reload()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        properties = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[2], impl->runtime());
    } else {
        JSValueRef currentArgument = nullptr;
        argumentIndex = argumentCount - 1;

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if ((JSValueIsObject(context, currentArgument) && JSObjectIsFunction(context, JSValueToObject(context, currentArgument, nullptr))) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                callback = toJSCallbackHandler(context, currentArgument, impl->runtime());
                --argumentIndex;
            }
        }

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (isDictionary(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                properties = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
                --argumentIndex;
            }
        }

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsNumber(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                tabID = JSValueToNumber(context, currentArgument, nullptr);
                --argumentIndex;
            }
        }
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"tabs.reload()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.reload()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->reload(page->webPageProxyIdentifier(), tabID, properties, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.reload()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::goBack(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.goBack() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    double tabID = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.goBack()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.goBack()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.goBack()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.goBack()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.goBack()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->goBack(page->webPageProxyIdentifier(), tabID, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.goBack()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::goForward(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.goForward() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    double tabID = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.goForward()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.goForward()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.goForward()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.goForward()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.goForward()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->goForward(page->webPageProxyIdentifier(), tabID, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.goForward()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::getZoom(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.getZoom() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    double tabID = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getZoom()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getZoom()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getZoom()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.getZoom()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.getZoom()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->getZoom(page->webPageProxyIdentifier(), tabID, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.getZoom()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::setZoom(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.setZoom() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.setZoom()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    double zoomFactor = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.setZoom()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsNumber(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.setZoom()", @"zoomFactor", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.setZoom()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        zoomFactor = JSValueToNumber(context, arguments[1], nullptr);
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
            if (!(JSValueIsNumber(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"tabs.setZoom()", @"zoomFactor", @"a number is expected");
                return JSValueMakeUndefined(context);
            }

            zoomFactor = JSValueToNumber(context, currentArgument, nullptr);
            --argumentIndex;
        }

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsNumber(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                tabID = JSValueToNumber(context, currentArgument, nullptr);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }
    }

    if (!std::isfinite(zoomFactor)) [[unlikely]] {
        *exception = toJSError(context, @"tabs.setZoom()", @"zoomFactor", @"a number is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"tabs.setZoom()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.setZoom()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->setZoom(page->webPageProxyIdentifier(), tabID, zoomFactor, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.setZoom()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::detectLanguage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.detectLanguage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    double tabID = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.detectLanguage()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.detectLanguage()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.detectLanguage()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.detectLanguage()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.detectLanguage()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->detectLanguage(page->webPageProxyIdentifier(), tabID, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.detectLanguage()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::toggleReaderMode(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.toggleReaderMode() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    double tabID = std::numeric_limits<double>::quiet_NaN();
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.toggleReaderMode()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.toggleReaderMode()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.toggleReaderMode()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.toggleReaderMode()", @"callback", @"a function is expected");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.toggleReaderMode()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->toggleReaderMode(page->webPageProxyIdentifier(), tabID, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.toggleReaderMode()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::captureVisibleTab(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.captureVisibleTab() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    double windowID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.captureVisibleTab()", @"windowID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.captureVisibleTab()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.captureVisibleTab()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        windowID = JSValueToNumber(context, arguments[0], nullptr);
        options = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[2], impl->runtime());
    } else {
        JSValueRef currentArgument = nullptr;
        argumentIndex = argumentCount - 1;

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if ((JSValueIsObject(context, currentArgument) && JSObjectIsFunction(context, JSValueToObject(context, currentArgument, nullptr))) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                callback = toJSCallbackHandler(context, currentArgument, impl->runtime());
                --argumentIndex;
            }
        }

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (isDictionary(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                options = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
                --argumentIndex;
            }
        }

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsNumber(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                windowID = JSValueToNumber(context, currentArgument, nullptr);
                --argumentIndex;
            }
        }
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"tabs.captureVisibleTab()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.captureVisibleTab()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->captureVisibleTab(page->webPageProxyIdentifier(), windowID, options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.captureVisibleTab()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::executeScript(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.executeScript() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.executeScript()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.executeScript()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.executeScript()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.executeScript()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        details = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
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
            if (!(isDictionary(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"tabs.executeScript()", @"details", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            details = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
            --argumentIndex;
        }

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsNumber(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                tabID = JSValueToNumber(context, currentArgument, nullptr);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"tabs.executeScript()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"tabs.executeScript()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.executeScript()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->executeScript(page->webPageProxyIdentifier(), tabID, details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.executeScript()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::insertCSS(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.insertCSS() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.insertCSS()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.insertCSS()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.insertCSS()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.insertCSS()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        details = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
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
            if (!(isDictionary(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"tabs.insertCSS()", @"details", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            details = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
            --argumentIndex;
        }

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsNumber(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                tabID = JSValueToNumber(context, currentArgument, nullptr);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"tabs.insertCSS()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"tabs.insertCSS()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.insertCSS()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->insertCSS(page->webPageProxyIdentifier(), tabID, details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.insertCSS()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::removeCSS(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.removeCSS() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.removeCSS()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsNumber(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.removeCSS()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.removeCSS()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.removeCSS()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        details = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
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
            if (!(isDictionary(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"tabs.removeCSS()", @"details", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            details = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
            --argumentIndex;
        }

        if (argumentIndex >= 0 && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsNumber(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                tabID = JSValueToNumber(context, currentArgument, nullptr);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"tabs.removeCSS()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"tabs.removeCSS()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.removeCSS()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->removeCSS(page->webPageProxyIdentifier(), tabID, details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.removeCSS()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::sendMessage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.sendMessage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    size_t argumentIndex = argumentCount;
    constexpr size_t requiredArgumentCount = 2;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.sendMessage()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    NSString *message;
    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 4) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.sendMessage()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((!JSValueIsNull(context, arguments[1]) && !JSValueIsUndefined(context, arguments[1]) && !JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.sendMessage()", @"message", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[2]) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.sendMessage()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[3]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[3], nullptr))) || JSValueIsNull(context, arguments[3]) || JSValueIsUndefined(context, arguments[3]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.sendMessage()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
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

        if (argumentIndex < argumentCount && (currentArgument = arguments[argumentIndex])) {
            if (!(JSValueIsNumber(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"tabs.sendMessage()", @"tabID", @"a number is expected");
                return JSValueMakeUndefined(context);
            }

            tabID = JSValueToNumber(context, currentArgument, nullptr);
            ++argumentIndex;
        }

        if (argumentIndex < argumentCount && (currentArgument = arguments[argumentIndex])) {
            if (!((!JSValueIsNull(context, currentArgument) && !JSValueIsUndefined(context, currentArgument) && !JSObjectIsFunction(context, JSValueToObject(context, currentArgument, nullptr))))) [[unlikely]] {
                *exception = toJSError(context, @"tabs.sendMessage()", @"message", @"an object is expected");
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

    if (!std::isfinite(tabID)) [[unlikely]] {
        *exception = toJSError(context, @"tabs.sendMessage()", @"tabID", @"a number is expected");
        return JSValueMakeUndefined(context);
    }

    if (*exception) [[unlikely]]
        return JSValueMakeUndefined(context);

    if (!message) [[unlikely]] {
        *exception = toJSError(context, @"tabs.sendMessage()", @"message", @"a JSON serializable value is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex < argumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.sendMessage()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"tabs.sendMessage()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->sendMessage(*frame, tabID, message, options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.sendMessage()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITabs::connect(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITabs(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function tabs.connect() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"tabs.connect()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    double tabID = std::numeric_limits<double>::quiet_NaN();
    NSDictionary *options;

    if (argumentCount == 2) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.connect()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.connect()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
        options = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!(JSValueIsNumber(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"tabs.connect()", @"tabID", @"a number is expected");
            return JSValueMakeUndefined(context);
        }

        tabID = JSValueToNumber(context, arguments[0], nullptr);
    }

    if (!std::isfinite(tabID)) [[unlikely]] {
        *exception = toJSError(context, @"tabs.connect()", @"tabID", @"a number is expected");
        return JSValueMakeUndefined(context);
    }

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    JSValueRef result = toJS(context, getPtr(impl->connect(*frame, context, tabID, options, &exceptionString)));

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"tabs.connect()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return result;
}

// Attributes

JSValueRef JSWebExtensionAPITabs::tabIdentifierNone(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.TAB_ID_NONE in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->tabIdentifierNone());
}

JSValueRef JSWebExtensionAPITabs::onActivated(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onActivated in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onActivated()));
}

JSValueRef JSWebExtensionAPITabs::onAttached(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onAttached in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onAttached()));
}

JSValueRef JSWebExtensionAPITabs::onCreated(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onCreated in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onCreated()));
}

JSValueRef JSWebExtensionAPITabs::onDetached(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onDetached in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onDetached()));
}

JSValueRef JSWebExtensionAPITabs::onHighlighted(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onHighlighted in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onHighlighted()));
}

JSValueRef JSWebExtensionAPITabs::onMoved(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onMoved in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onMoved()));
}

JSValueRef JSWebExtensionAPITabs::onRemoved(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onRemoved in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onRemoved()));
}

JSValueRef JSWebExtensionAPITabs::onReplaced(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onReplaced in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onReplaced()));
}

JSValueRef JSWebExtensionAPITabs::onUpdated(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITabs(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter tabs.onUpdated in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onUpdated()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
