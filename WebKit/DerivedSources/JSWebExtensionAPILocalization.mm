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

#include "JSWebExtensionAPILocalization.h"
#include "Logging.h"
#include "WebExtensionAPILocalization.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPILocalization* toWebExtensionAPILocalization(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPILocalization::localizationClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPILocalization::localizationClass()))
        return nullptr;
    return static_cast<WebExtensionAPILocalization*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPILocalization::localizationClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Localization";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPILocalization::localizationGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Localization";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPILocalization::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "getMessage", getMessage, kJSPropertyAttributeNone },
        { "getUILanguage", getUILanguage, kJSPropertyAttributeNone },
        { "getAcceptLanguages", getAcceptLanguages, kJSPropertyAttributeNone },
        { "getPreferredSystemLanguages", getPreferredSystemLanguages, kJSPropertyAttributeNone },
        { "getSystemUILanguage", getSystemUILanguage, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPILocalization::staticValues()
{
    return nullptr;
}

const JSStaticValue* JSWebExtensionAPILocalization::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPILocalization::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, localizationClass());
}

// Functions

JSValueRef JSWebExtensionAPILocalization::getMessage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPILocalization(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function i18n.getMessage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"i18n.getMessage()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *name;
    NSObject *substitutions;

    if (argumentCount == 2) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"i18n.getMessage()", @"name", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        name = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        substitutions = toNSObject(context, arguments[1]);
    } else if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"i18n.getMessage()", @"name", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        name = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    if (!name) [[unlikely]] {
        *exception = toJSError(context, @"i18n.getMessage()", @"name", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    if (!name.length) [[unlikely]] {
        *exception = toJSError(context, @"i18n.getMessage()", @"name", @"it cannot be empty");
        return JSValueMakeUndefined(context);
    }

    return toJSValueRef(context, impl->getMessage(name, substitutions), NullOrEmptyString::NullStringAsEmptyString);
}

JSValueRef JSWebExtensionAPILocalization::getUILanguage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPILocalization(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function i18n.getUILanguage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRef(context, impl->getUILanguage(), NullOrEmptyString::NullStringAsEmptyString);
}

JSValueRef JSWebExtensionAPILocalization::getAcceptLanguages(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPILocalization(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function i18n.getAcceptLanguages() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"i18n.getAcceptLanguages()", @"callback", @"a function is expected");
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

    impl->getAcceptLanguages(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPILocalization::getPreferredSystemLanguages(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPILocalization(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function i18n.getPreferredSystemLanguages() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"i18n.getPreferredSystemLanguages()", @"callback", @"a function is expected");
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

    impl->getPreferredSystemLanguages(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPILocalization::getSystemUILanguage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPILocalization(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function i18n.getSystemUILanguage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 1) {
        if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"i18n.getSystemUILanguage()", @"callback", @"a function is expected");
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

    impl->getSystemUILanguage(callback.releaseNonNull());

    return promiseResult ?: JSValueMakeUndefined(context);
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
