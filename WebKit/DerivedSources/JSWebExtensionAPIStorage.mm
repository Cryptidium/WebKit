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

#include "JSWebExtensionAPIEvent.h"
#include "JSWebExtensionAPIStorage.h"
#include "JSWebExtensionAPIStorageArea.h"
#include "Logging.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionAPIStorage.h"
#include "WebExtensionAPIStorageArea.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIStorage* toWebExtensionAPIStorage(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIStorage::storageClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIStorage::storageClass()))
        return nullptr;
    return static_cast<WebExtensionAPIStorage*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIStorage::storageClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Storage";
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

JSClassRef JSWebExtensionAPIStorage::storageGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Storage";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIStorage::staticFunctions()
{
    return nullptr;
}

const JSStaticValue* JSWebExtensionAPIStorage::staticValues()
{
    static const JSStaticValue values[] = {
        { "local", local, nullptr, kJSPropertyAttributeNone },
        { "sync", sync, nullptr, kJSPropertyAttributeNone },
        { "onChanged", onChanged, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIStorage::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIStorage::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, storageClass());
}

void JSWebExtensionAPIStorage::getPropertyNames(JSContextRef context, JSObjectRef thisObject, JSPropertyNameAccumulatorRef propertyNames)
{
    RefPtr impl = toWebExtensionAPIStorage(context, thisObject);
    if (!impl) [[unlikely]]
        return;

    RefPtr page = toWebPage(context);
    if (impl->isPropertyAllowed("session"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("session").get());

}

bool JSWebExtensionAPIStorage::hasProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName)
{
    RefPtr impl = toWebExtensionAPIStorage(context, thisObject);
    if (!impl) [[unlikely]]
        return false;

    RefPtr page = toWebPage(context);
    if (JSStringIsEqualToUTF8CString(propertyName, "session"))
        return impl->isPropertyAllowed("session"_s, page.get());

    return false;
}

JSValueRef JSWebExtensionAPIStorage::getProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPIStorage(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RefPtr page = toWebPage(context);
    if (JSStringIsEqualToUTF8CString(propertyName, "session") && impl->isPropertyAllowed("session"_s, page.get()))
        return session(context, thisObject, propertyName, exception);

    return JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPIStorage::local(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorage(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storage.local in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->local()));
}

JSValueRef JSWebExtensionAPIStorage::session(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorage(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storage.session in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->session()));
}

JSValueRef JSWebExtensionAPIStorage::sync(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorage(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storage.sync in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->sync()));
}

JSValueRef JSWebExtensionAPIStorage::onChanged(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIStorage(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter storage.onChanged in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onChanged()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
