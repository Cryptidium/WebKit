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

#include "JSWebExtensionAPIPort.h"
#include "JSWebExtensionAPIWebPageRuntime.h"
#include "Logging.h"
#include "WebExtensionAPIPort.h"
#include "WebExtensionAPIWebPageRuntime.h"
#include "WebExtensionUtilities.h"
#include "WebFrame.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIWebPageRuntime* toWebExtensionAPIWebPageRuntime(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIWebPageRuntime::webPageRuntimeClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIWebPageRuntime::webPageRuntimeClass()))
        return nullptr;
    return static_cast<WebExtensionAPIWebPageRuntime*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIWebPageRuntime::webPageRuntimeClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "WebPageRuntime";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIWebPageRuntime::webPageRuntimeGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "WebPageRuntime";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIWebPageRuntime::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "sendMessage", sendMessage, kJSPropertyAttributeNone },
        { "connect", connect, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIWebPageRuntime::staticValues()
{
    return nullptr;
}

const JSStaticValue* JSWebExtensionAPIWebPageRuntime::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIWebPageRuntime::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, webPageRuntimeClass());
}

// Functions

JSValueRef JSWebExtensionAPIWebPageRuntime::sendMessage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWebPageRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function webPageRuntime.sendMessage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    size_t argumentIndex = argumentCount;
    constexpr size_t requiredArgumentCount = 2;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"webPageRuntime.sendMessage()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *extensionId;
    NSString *message;
    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 4) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"webPageRuntime.sendMessage()", @"extensionId", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((!JSValueIsNull(context, arguments[1]) && !JSValueIsUndefined(context, arguments[1]) && !JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))))) [[unlikely]] {
            *exception = toJSError(context, @"webPageRuntime.sendMessage()", @"message", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[2]) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"webPageRuntime.sendMessage()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[3]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[3], nullptr))) || JSValueIsNull(context, arguments[3]) || JSValueIsUndefined(context, arguments[3]))) [[unlikely]] {
            *exception = toJSError(context, @"webPageRuntime.sendMessage()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        extensionId = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
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
            if (!(JSValueIsString(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"webPageRuntime.sendMessage()", @"extensionId", @"a string is expected");
                return JSValueMakeUndefined(context);
            }

            extensionId = toNSString(context, currentArgument, NullStringPolicy::NullAndUndefinedAsNullString);
            ++argumentIndex;
        }

        if (argumentIndex < argumentCount && (currentArgument = arguments[argumentIndex])) {
            if (!((!JSValueIsNull(context, currentArgument) && !JSValueIsUndefined(context, currentArgument) && !JSObjectIsFunction(context, JSValueToObject(context, currentArgument, nullptr))))) [[unlikely]] {
                *exception = toJSError(context, @"webPageRuntime.sendMessage()", @"message", @"an object is expected");
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

    if (!extensionId) [[unlikely]] {
        *exception = toJSError(context, @"webPageRuntime.sendMessage()", @"extensionId", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    if (*exception) [[unlikely]]
        return JSValueMakeUndefined(context);

    if (!message) [[unlikely]] {
        *exception = toJSError(context, @"webPageRuntime.sendMessage()", @"message", @"a JSON serializable value is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex < argumentCount) [[unlikely]] {
        *exception = toJSError(context, @"webPageRuntime.sendMessage()", nil, @"an unknown argument was provided");
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
            promiseResult = toJSRejectedPromise(context, @"webPageRuntime.sendMessage()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        if (promiseResult)
            promiseResult = toJSRejectedPromise(context, @"webPageRuntime.sendMessage()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->sendMessage(*page, *frame, extensionId, message, options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"webPageRuntime.sendMessage()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIWebPageRuntime::connect(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWebPageRuntime(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function webPageRuntime.connect() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"webPageRuntime.connect()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *extensionId;
    NSDictionary *options;

    if (argumentCount == 2) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"webPageRuntime.connect()", @"extensionId", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(isDictionary(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"webPageRuntime.connect()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        extensionId = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        options = toNSDictionary(context, arguments[1], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"webPageRuntime.connect()", @"extensionId", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        extensionId = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    if (!extensionId) [[unlikely]] {
        *exception = toJSError(context, @"webPageRuntime.connect()", @"extensionId", @"a string is expected");
        return JSValueMakeUndefined(context);
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
    JSValueRef result = toJS(context, getPtr(impl->connect(*page, *frame, context, extensionId, options, &exceptionString)));

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"webPageRuntime.connect()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return result;
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
