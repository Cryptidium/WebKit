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

#include "JSWebExtensionAPIDevToolsExtensionPanel.h"
#include "JSWebExtensionAPIEvent.h"
#include "Logging.h"
#include "WebExtensionAPIDevToolsExtensionPanel.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPIDevToolsExtensionPanel* toWebExtensionAPIDevToolsExtensionPanel(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPIDevToolsExtensionPanel::devToolsExtensionPanelClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPIDevToolsExtensionPanel::devToolsExtensionPanelClass()))
        return nullptr;
    return static_cast<WebExtensionAPIDevToolsExtensionPanel*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPIDevToolsExtensionPanel::devToolsExtensionPanelClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "DevToolsExtensionPanel";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPIDevToolsExtensionPanel::devToolsExtensionPanelGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "DevToolsExtensionPanel";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPIDevToolsExtensionPanel::staticFunctions()
{
    return nullptr;
}

const JSStaticValue* JSWebExtensionAPIDevToolsExtensionPanel::staticValues()
{
    static const JSStaticValue values[] = {
        { "onShown", onShown, nullptr, kJSPropertyAttributeNone },
        { "onHidden", onHidden, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPIDevToolsExtensionPanel::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPIDevToolsExtensionPanel::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, devToolsExtensionPanelClass());
}

// Attributes

JSValueRef JSWebExtensionAPIDevToolsExtensionPanel::onShown(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIDevToolsExtensionPanel(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter onShown in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onShown()));
}

JSValueRef JSWebExtensionAPIDevToolsExtensionPanel::onHidden(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPIDevToolsExtensionPanel(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter onHidden in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onHidden()));
}

} // namespace WebKit

#endif // ENABLE(INSPECTOR_EXTENSIONS) && ENABLE(WK_WEB_EXTENSIONS)
