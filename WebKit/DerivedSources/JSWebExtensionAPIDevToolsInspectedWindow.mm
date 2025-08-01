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

#if ENABLE(INSPECTOR_EXTENSIONS) && ENABLE(WK_WEB_EXTENSIONS)

#include "JSWebExtensionAPIDevToolsInspectedWindow.h"
#include "Logging.h"
#include "WebExtensionAPIDevToolsInspectedWindow.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIDevToolsInspectedWindow* toWebExtensionAPIDevToolsInspectedWindow(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIDevToolsInspectedWindow::devToolsInspectedWindowClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIDevToolsInspectedWindow::devToolsInspectedWindowClass()))
        return nullptr;
    return static_cast<WebExtensionAPIDevToolsInspectedWindow*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIDevToolsInspectedWindow::devToolsInspectedWindowClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "DevToolsInspectedWindow";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIDevToolsInspectedWindow::devToolsInspectedWindowGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "DevToolsInspectedWindow";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIDevToolsInspectedWindow::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "eval", eval, kJSPropertyAttributeNone },
        { "reload", reload, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIDevToolsInspectedWindow::staticValues()
{
    static const JSStaticValue values[] = {
        { "tabId", tabId, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIDevToolsInspectedWindow::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIDevToolsInspectedWindow::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, devToolsInspectedWindowClass());
}

// Functions

JSValueRef JSWebExtensionAPIDevToolsInspectedWindow::eval(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDevToolsInspectedWindow(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function devtools.inspectedWindow.eval() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    ssize_t argumentIndex = -1;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"devtools.inspectedWindow.eval()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *expression;
    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 3) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.inspectedWindow.eval()", @"expression", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.inspectedWindow.eval()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[2]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[2], nullptr))) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.inspectedWindow.eval()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        expression = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        options = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
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
                options = toNSDictionary(context, currentArgument, NullValuePolicy::NotAllowed);
                ++processedOptionalArgumentCount;
                --argumentIndex;
            }
        }

        if (argumentIndex >= 0 && (currentArgument = arguments[argumentIndex])) {
            if (!(JSValueIsString(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"devtools.inspectedWindow.eval()", @"expression", @"a string is expected");
                return JSValueMakeUndefined(context);
            }

            expression = toNSString(context, currentArgument, NullStringPolicy::NullAndUndefinedAsNullString);
            --argumentIndex;
        }
    }

    if (!expression) [[unlikely]] {
        *exception = toJSError(context, @"devtools.inspectedWindow.eval()", @"expression", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    if (!expression.length) [[unlikely]] {
        *exception = toJSError(context, @"devtools.inspectedWindow.eval()", @"expression", @"it cannot be empty");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex >= 0) [[unlikely]] {
        *exception = toJSError(context, @"devtools.inspectedWindow.eval()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"devtools.inspectedWindow.eval()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->eval(page->webPageProxyIdentifier(), expression, options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"devtools.inspectedWindow.eval()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDevToolsInspectedWindow::reload(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDevToolsInspectedWindow(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function devtools.inspectedWindow.reload() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *options;

    if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.inspectedWindow.reload()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    RefPtr page = toWebPage(context);
    if (!page) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Page could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->reload(page->webPageProxyIdentifier(), options, &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"devtools.inspectedWindow.reload()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIDevToolsInspectedWindow::tabId(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIDevToolsInspectedWindow(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter devtools.inspectedWindow.tabId in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    RefPtr page = toWebPage(context);
    if (!page) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Page could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeNumber(context, impl->tabId(*page));
}

} // namespace WebKit

#endif // ENABLE(INSPECTOR_EXTENSIONS) && ENABLE(WK_WEB_EXTENSIONS)
