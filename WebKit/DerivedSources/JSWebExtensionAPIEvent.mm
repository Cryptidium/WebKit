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
#include "Logging.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionUtilities.h"
#include "WebFrame.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIEvent* toWebExtensionAPIEvent(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIEvent::eventClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIEvent::eventClass()))
        return nullptr;
    return static_cast<WebExtensionAPIEvent*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIEvent::eventClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Event";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIEvent::eventGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Event";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIEvent::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "addListener", addListener, kJSPropertyAttributeNone },
        { "removeListener", removeListener, kJSPropertyAttributeNone },
        { "hasListener", hasListener, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIEvent::staticValues()
{
    return nullptr;
}

const JSStaticValue* JSWebExtensionAPIEvent::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIEvent::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, eventClass());
}

// Functions

JSValueRef JSWebExtensionAPIEvent::addListener(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIEvent(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function addListener() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"addListener()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))))) [[unlikely]] {
        *exception = toJSError(context, @"addListener()", @"listener", @"a function is expected");
        return JSValueMakeUndefined(context);
    }

    RefPtr<WebExtensionCallbackHandler> listener = toJSCallbackHandler(context, arguments[0], impl->runtime());

    if (!listener) [[unlikely]] {
        *exception = toJSError(context, @"addListener()", @"listener", @"a function is expected");
        return JSValueMakeUndefined(context);
    }

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    impl->addListener(frame->frameID(), listener);

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIEvent::removeListener(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIEvent(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function removeListener() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"removeListener()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))))) [[unlikely]] {
        *exception = toJSError(context, @"removeListener()", @"listener", @"a function is expected");
        return JSValueMakeUndefined(context);
    }

    RefPtr<WebExtensionCallbackHandler> listener = toJSCallbackHandler(context, arguments[0], impl->runtime());

    if (!listener) [[unlikely]] {
        *exception = toJSError(context, @"removeListener()", @"listener", @"a function is expected");
        return JSValueMakeUndefined(context);
    }

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    impl->removeListener(frame->frameID(), listener);

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIEvent::hasListener(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIEvent(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function hasListener() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"hasListener()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!((JSValueIsObject(context, arguments[0]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))))) [[unlikely]] {
        *exception = toJSError(context, @"hasListener()", @"listener", @"a function is expected");
        return JSValueMakeUndefined(context);
    }

    RefPtr<WebExtensionCallbackHandler> listener = toJSCallbackHandler(context, arguments[0], impl->runtime());

    if (!listener) [[unlikely]] {
        *exception = toJSError(context, @"hasListener()", @"listener", @"a function is expected");
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeBoolean(context, impl->hasListener(listener));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
