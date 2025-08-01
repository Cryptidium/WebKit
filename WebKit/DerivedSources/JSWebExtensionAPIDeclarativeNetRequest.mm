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

#include "JSWebExtensionAPIDeclarativeNetRequest.h"
#include "Logging.h"
#include "WebExtensionAPIDeclarativeNetRequest.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIDeclarativeNetRequest* toWebExtensionAPIDeclarativeNetRequest(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIDeclarativeNetRequest::declarativeNetRequestClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIDeclarativeNetRequest::declarativeNetRequestClass()))
        return nullptr;
    return static_cast<WebExtensionAPIDeclarativeNetRequest*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIDeclarativeNetRequest::declarativeNetRequestClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "DeclarativeNetRequest";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIDeclarativeNetRequest::declarativeNetRequestGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "DeclarativeNetRequest";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIDeclarativeNetRequest::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "updateEnabledRulesets", updateEnabledRulesets, kJSPropertyAttributeNone },
        { "getEnabledRulesets", getEnabledRulesets, kJSPropertyAttributeNone },
        { "updateDynamicRules", updateDynamicRules, kJSPropertyAttributeNone },
        { "getDynamicRules", getDynamicRules, kJSPropertyAttributeNone },
        { "updateSessionRules", updateSessionRules, kJSPropertyAttributeNone },
        { "getSessionRules", getSessionRules, kJSPropertyAttributeNone },
        { "getMatchedRules", getMatchedRules, kJSPropertyAttributeNone },
        { "isRegexSupported", isRegexSupported, kJSPropertyAttributeNone },
        { "setExtensionActionOptions", setExtensionActionOptions, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIDeclarativeNetRequest::staticValues()
{
    static const JSStaticValue values[] = {
        { "MAX_NUMBER_OF_STATIC_RULESETS", maxNumberOfStaticRulesets, nullptr, kJSPropertyAttributeNone },
        { "MAX_NUMBER_OF_ENABLED_STATIC_RULESETS", maxNumberOfEnabledRulesets, nullptr, kJSPropertyAttributeNone },
        { "MAX_NUMBER_OF_DYNAMIC_AND_SESSION_RULES", maxNumberOfDynamicAndSessionRules, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIDeclarativeNetRequest::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIDeclarativeNetRequest::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, declarativeNetRequestClass());
}

// Functions

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::updateEnabledRulesets(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.updateEnabledRulesets() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateEnabledRulesets()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateEnabledRulesets()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateEnabledRulesets()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateEnabledRulesets()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!options) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateEnabledRulesets()", @"options", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->updateEnabledRulesets(options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateEnabledRulesets()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::getEnabledRulesets(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.getEnabledRulesets() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getEnabledRulesets()", @"callback", @"a function is expected");
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

    impl->getEnabledRulesets(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::updateDynamicRules(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.updateDynamicRules() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateDynamicRules()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateDynamicRules()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateDynamicRules()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateDynamicRules()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!options) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateDynamicRules()", @"options", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->updateDynamicRules(options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateDynamicRules()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::getDynamicRules(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.getDynamicRules() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *filter;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getDynamicRules()", @"filter", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getDynamicRules()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        filter = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getDynamicRules()", @"filter", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        filter = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getDynamicRules()", @"callback", @"a function is expected");
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

    impl->getDynamicRules(filter, callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::updateSessionRules(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.updateSessionRules() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateSessionRules()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateSessionRules()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateSessionRules()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.updateSessionRules()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!options) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateSessionRules()", @"options", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->updateSessionRules(options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.updateSessionRules()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::getSessionRules(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.getSessionRules() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *filter;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getSessionRules()", @"filter", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getSessionRules()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        filter = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getSessionRules()", @"filter", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        filter = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getSessionRules()", @"callback", @"a function is expected");
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

    impl->getSessionRules(filter, callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::getMatchedRules(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.getMatchedRules() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSDictionary *filter;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getMatchedRules()", @"filter", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getMatchedRules()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        filter = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1 && !((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) {
        if (!(isDictionary(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getMatchedRules()", @"filter", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        filter = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    } else if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.getMatchedRules()", @"callback", @"a function is expected");
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
    impl->getMatchedRules(filter, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.getMatchedRules()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::isRegexSupported(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.isRegexSupported() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.isRegexSupported()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *regexOptions;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.isRegexSupported()", @"regexOptions", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.isRegexSupported()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        regexOptions = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.isRegexSupported()", @"regexOptions", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        regexOptions = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!regexOptions) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.isRegexSupported()", @"regexOptions", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->isRegexSupported(regexOptions, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.isRegexSupported()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::setExtensionActionOptions(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function declarativeNetRequest.setExtensionActionOptions() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.setExtensionActionOptions()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *options;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.setExtensionActionOptions()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.setExtensionActionOptions()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"declarativeNetRequest.setExtensionActionOptions()", @"options", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        options = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!options) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.setExtensionActionOptions()", @"options", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->setExtensionActionOptions(options, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"declarativeNetRequest.setExtensionActionOptions()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::maxNumberOfStaticRulesets(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter declarativeNetRequest.MAX_NUMBER_OF_STATIC_RULESETS in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->maxNumberOfStaticRulesets());
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::maxNumberOfEnabledRulesets(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter declarativeNetRequest.MAX_NUMBER_OF_ENABLED_STATIC_RULESETS in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->maxNumberOfEnabledRulesets());
}

JSValueRef JSWebExtensionAPIDeclarativeNetRequest::maxNumberOfDynamicAndSessionRules(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIDeclarativeNetRequest(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter declarativeNetRequest.MAX_NUMBER_OF_DYNAMIC_AND_SESSION_RULES in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeNumber(context, impl->maxNumberOfDynamicAndSessionRules());
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
