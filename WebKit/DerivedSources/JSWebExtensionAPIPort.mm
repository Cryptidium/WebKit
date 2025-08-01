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
#include "Logging.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionAPIPort.h"
#include "WebExtensionUtilities.h"
#include "WebFrame.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIPort* toWebExtensionAPIPort(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIPort::portClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIPort::portClass()))
        return nullptr;
    return static_cast<WebExtensionAPIPort*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIPort::portClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Port";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIPort::portGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Port";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIPort::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "postMessage", postMessage, kJSPropertyAttributeNone },
        { "disconnect", disconnect, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIPort::staticValues()
{
    static const JSStaticValue values[] = {
        { "name", name, nullptr, kJSPropertyAttributeNone },
        { "sender", sender, nullptr, kJSPropertyAttributeNone },
        { "error", error, nullptr, kJSPropertyAttributeNone },
        { "onDisconnect", onDisconnect, nullptr, kJSPropertyAttributeNone },
        { "onMessage", onMessage, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIPort::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIPort::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, portClass());
}

// Functions

JSValueRef JSWebExtensionAPIPort::postMessage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIPort(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function port.postMessage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"port.postMessage()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!((!JSValueIsNull(context, arguments[0]) && !JSValueIsUndefined(context, arguments[0]) && !JSObjectIsFunction(context, JSValueToObject(context, arguments[0], nullptr))))) [[unlikely]] {
        *exception = toJSError(context, @"port.postMessage()", @"message", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    NSString *message = serializeJSObject(context, arguments[0], exception);

    if (*exception) [[unlikely]]
        return JSValueMakeUndefined(context);

    if (!message) [[unlikely]] {
        *exception = toJSError(context, @"port.postMessage()", @"message", @"a JSON serializable value is expected");
        return JSValueMakeUndefined(context);
    }

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->postMessage(*frame, message, &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"port.postMessage()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPIPort::disconnect(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIPort(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function port.disconnect() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    impl->disconnect();

    return JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIPort::name(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIPort(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter port.name in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRef(context, impl->name(), NullOrEmptyString::NullStringAsEmptyString);
}

JSValueRef JSWebExtensionAPIPort::sender(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIPort(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter port.sender in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRefOrJSNull(context, impl->sender());
}

JSValueRef JSWebExtensionAPIPort::error(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIPort(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter port.error in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRefOrJSNull(context, impl->error());
}

JSValueRef JSWebExtensionAPIPort::onDisconnect(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIPort(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter port.onDisconnect in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onDisconnect()));
}

JSValueRef JSWebExtensionAPIPort::onMessage(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIPort(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter port.onMessage in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onMessage()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
