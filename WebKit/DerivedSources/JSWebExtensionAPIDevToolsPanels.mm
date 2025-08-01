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

#include "JSWebExtensionAPIDevToolsPanels.h"
#include "JSWebExtensionAPIEvent.h"
#include "Logging.h"
#include "WebExtensionAPIDevToolsPanels.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIDevToolsPanels* toWebExtensionAPIDevToolsPanels(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIDevToolsPanels::devToolsPanelsClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIDevToolsPanels::devToolsPanelsClass()))
        return nullptr;
    return static_cast<WebExtensionAPIDevToolsPanels*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIDevToolsPanels::devToolsPanelsClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "DevToolsPanels";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIDevToolsPanels::devToolsPanelsGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "DevToolsPanels";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIDevToolsPanels::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "create", create, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPIDevToolsPanels::staticValues()
{
    static const JSStaticValue values[] = {
        { "themeName", themeName, nullptr, kJSPropertyAttributeNone },
        { "onThemeChanged", onThemeChanged, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIDevToolsPanels::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIDevToolsPanels::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, devToolsPanelsClass());
}

// Functions

JSValueRef JSWebExtensionAPIDevToolsPanels::create(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIDevToolsPanels(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function devtools.panels.create() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 3;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"devtools.panels.create()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *title;
    NSString *iconPath;
    NSString *pagePath;
    RefPtr<WebExtensionCallbackHandler> callback;

    if (argumentCount == 4) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.panels.create()", @"title", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.panels.create()", @"iconPath", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.panels.create()", @"pagePath", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!((JSValueIsObject(context, arguments[3]) && JSObjectIsFunction(context, JSValueToObject(context, arguments[3], nullptr))) || JSValueIsNull(context, arguments[3]) || JSValueIsUndefined(context, arguments[3]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.panels.create()", @"callback", @"a function is expected");
            return JSValueMakeUndefined(context);
        }

        title = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        iconPath = toNSString(context, arguments[1], NullStringPolicy::NullAndUndefinedAsNullString);
        pagePath = toNSString(context, arguments[2], NullStringPolicy::NullAndUndefinedAsNullString);
        callback = toJSCallbackHandler(context, arguments[3], impl->runtime());
    } else if (argumentCount == 3) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.panels.create()", @"title", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.panels.create()", @"iconPath", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"devtools.panels.create()", @"pagePath", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        title = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        iconPath = toNSString(context, arguments[1], NullStringPolicy::NullAndUndefinedAsNullString);
        pagePath = toNSString(context, arguments[2], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    if (!title) [[unlikely]] {
        *exception = toJSError(context, @"devtools.panels.create()", @"title", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    if (!title.length) [[unlikely]] {
        *exception = toJSError(context, @"devtools.panels.create()", @"title", @"it cannot be empty");
        return JSValueMakeUndefined(context);
    }

    if (!iconPath) [[unlikely]] {
        *exception = toJSError(context, @"devtools.panels.create()", @"iconPath", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    if (!iconPath.length) [[unlikely]] {
        *exception = toJSError(context, @"devtools.panels.create()", @"iconPath", @"it cannot be empty");
        return JSValueMakeUndefined(context);
    }

    if (!pagePath) [[unlikely]] {
        *exception = toJSError(context, @"devtools.panels.create()", @"pagePath", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    if (!pagePath.length) [[unlikely]] {
        *exception = toJSError(context, @"devtools.panels.create()", @"pagePath", @"it cannot be empty");
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
            promiseResult = toJSRejectedPromise(context, @"devtools.panels.create()", nil, @"an unknown error occurred");
        return promiseResult ?: JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->createPanel(page->webPageProxyIdentifier(), title, iconPath, pagePath, callback.releaseNonNull(), &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"devtools.panels.create()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return promiseResult ?: JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIDevToolsPanels::themeName(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIDevToolsPanels(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter devtools.panels.themeName in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJSValueRef(context, impl->themeName(), NullOrEmptyString::NullStringAsEmptyString);
}

JSValueRef JSWebExtensionAPIDevToolsPanels::onThemeChanged(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIDevToolsPanels(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter devtools.panels.onThemeChanged in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onThemeChanged()));
}

} // namespace WebKit

#endif // ENABLE(INSPECTOR_EXTENSIONS) && ENABLE(WK_WEB_EXTENSIONS)
