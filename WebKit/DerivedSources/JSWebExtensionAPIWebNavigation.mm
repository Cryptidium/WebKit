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

#include "JSWebExtensionAPIWebNavigation.h"
#include "JSWebExtensionAPIWebNavigationEvent.h"
#include "Logging.h"
#include "WebExtensionAPIWebNavigation.h"
#include "WebExtensionAPIWebNavigationEvent.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIWebNavigation* toWebExtensionAPIWebNavigation(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIWebNavigation::webNavigationClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIWebNavigation::webNavigationClass()))
        return nullptr;
    return static_cast<WebExtensionAPIWebNavigation*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIWebNavigation::webNavigationClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "WebNavigation";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIWebNavigation::webNavigationGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "WebNavigation";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIWebNavigation::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "getFrame", getFrame, kJSPropertyAttributeNone },
        { "getAllFrames", getAllFrames, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIWebNavigation::staticValues()
{
    static const JSStaticValue values[] = {
        { "onBeforeNavigate", onBeforeNavigate, nullptr, kJSPropertyAttributeNone },
        { "onCommitted", onCommitted, nullptr, kJSPropertyAttributeNone },
        { "onDOMContentLoaded", onDOMContentLoaded, nullptr, kJSPropertyAttributeNone },
        { "onCompleted", onCompleted, nullptr, kJSPropertyAttributeNone },
        { "onErrorOccurred", onErrorOccurred, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIWebNavigation::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIWebNavigation::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, webNavigationClass());
}

// Functions

JSValueRef JSWebExtensionAPIWebNavigation::getFrame(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWebNavigation(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function webNavigation.getFrame() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"webNavigation.getFrame()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"webNavigation.getFrame()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"webNavigation.getFrame()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"webNavigation.getFrame()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"webNavigation.getFrame()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->getFrame(details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"webNavigation.getFrame()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIWebNavigation::getAllFrames(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIWebNavigation(context, thisObject);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function webNavigation.getAllFrames() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"webNavigation.getAllFrames()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSDictionary *details;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 2) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"webNavigation.getAllFrames()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[1]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[1], nullptr))) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"webNavigation.getAllFrames()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
        callback = toJSCallbackHandler(context, arguments[1], impl->runtime());
    } else if (argumentCount == 1) {
        if (!(isDictionary(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"webNavigation.getAllFrames()", @"details", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        details = toNSDictionary(context, arguments[0], NullValuePolicy::NotAllowed);
    }

    if (!details) [[unlikely]] {
        *exception = toJSError(context, @"webNavigation.getAllFrames()", @"details", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSObjectRef promiseResult = nullptr;
    if (!callback) {
        JSObjectRef resolveFunction, rejectFunction = nullptr;
        promiseResult = JSObjectMakeDeferredPromise(context, &resolveFunction, &rejectFunction, nullptr);
        callback = toJSPromiseCallbackHandler(context, resolveFunction, rejectFunction);
    }

    NSString *exceptionString;
    impl->getAllFrames(details, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"webNavigation.getAllFrames()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIWebNavigation::onBeforeNavigate(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWebNavigation(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter webNavigation.onBeforeNavigate in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onBeforeNavigate()));
}

JSValueRef JSWebExtensionAPIWebNavigation::onCommitted(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWebNavigation(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter webNavigation.onCommitted in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onCommitted()));
}

JSValueRef JSWebExtensionAPIWebNavigation::onDOMContentLoaded(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWebNavigation(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter webNavigation.onDOMContentLoaded in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onDOMContentLoaded()));
}

JSValueRef JSWebExtensionAPIWebNavigation::onCompleted(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWebNavigation(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter webNavigation.onCompleted in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onCompleted()));
}

JSValueRef JSWebExtensionAPIWebNavigation::onErrorOccurred(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIWebNavigation(context, object);
    if (!impl || !impl->isForMainWorld()) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter webNavigation.onErrorOccurred in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onErrorOccurred()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
