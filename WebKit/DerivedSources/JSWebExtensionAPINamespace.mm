/*
 * Copyright (C) 2022-2025 Apple Inc. All rights reserved.
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

#include "JSWebExtensionAPIAction.h"
#include "JSWebExtensionAPIAlarms.h"
#include "JSWebExtensionAPIBookmarks.h"
#include "JSWebExtensionAPICommands.h"
#include "JSWebExtensionAPICookies.h"
#include "JSWebExtensionAPIDOM.h"
#include "JSWebExtensionAPIDeclarativeNetRequest.h"
#include "JSWebExtensionAPIDevTools.h"
#include "JSWebExtensionAPIExtension.h"
#include "JSWebExtensionAPILocalization.h"
#include "JSWebExtensionAPIMenus.h"
#include "JSWebExtensionAPINamespace.h"
#include "JSWebExtensionAPINotifications.h"
#include "JSWebExtensionAPIPermissions.h"
#include "JSWebExtensionAPIRuntime.h"
#include "JSWebExtensionAPIScripting.h"
#include "JSWebExtensionAPISidePanel.h"
#include "JSWebExtensionAPISidebarAction.h"
#include "JSWebExtensionAPIStorage.h"
#include "JSWebExtensionAPITabs.h"
#include "JSWebExtensionAPITest.h"
#include "JSWebExtensionAPIWebNavigation.h"
#include "JSWebExtensionAPIWebRequest.h"
#include "JSWebExtensionAPIWindows.h"
#include "Logging.h"
#include "WebExtensionAPIAction.h"
#include "WebExtensionAPIAlarms.h"
#include "WebExtensionAPIBookmarks.h"
#include "WebExtensionAPICommands.h"
#include "WebExtensionAPICookies.h"
#include "WebExtensionAPIDOM.h"
#include "WebExtensionAPIDeclarativeNetRequest.h"
#include "WebExtensionAPIDevTools.h"
#include "WebExtensionAPIExtension.h"
#include "WebExtensionAPILocalization.h"
#include "WebExtensionAPIMenus.h"
#include "WebExtensionAPINamespace.h"
#include "WebExtensionAPINotifications.h"
#include "WebExtensionAPIPermissions.h"
#include "WebExtensionAPIRuntime.h"
#include "WebExtensionAPIScripting.h"
#include "WebExtensionAPISidePanel.h"
#include "WebExtensionAPISidebarAction.h"
#include "WebExtensionAPIStorage.h"
#include "WebExtensionAPITabs.h"
#include "WebExtensionAPITest.h"
#include "WebExtensionAPIWebNavigation.h"
#include "WebExtensionAPIWebRequest.h"
#include "WebExtensionAPIWindows.h"
#include "WebExtensionUtilities.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPINamespace* toWebExtensionAPINamespace(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPINamespace::namespaceClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPINamespace::namespaceClass()))
        return nullptr;
    return static_cast<WebExtensionAPINamespace*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPINamespace::namespaceClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Namespace";
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

JSClassRef JSWebExtensionAPINamespace::namespaceGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Namespace";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPINamespace::staticFunctions()
{
    return nullptr;
}

const JSStaticValue* JSWebExtensionAPINamespace::staticValues()
{
    static const JSStaticValue values[] = {
        { "dom", dom, nullptr, kJSPropertyAttributeNone },
        { "extension", extension, nullptr, kJSPropertyAttributeNone },
        { "i18n", i18n, nullptr, kJSPropertyAttributeNone },
        { "runtime", runtime, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPINamespace::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPINamespace::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, namespaceClass());
}

void JSWebExtensionAPINamespace::getPropertyNames(JSContextRef context, JSObjectRef thisObject, JSPropertyNameAccumulatorRef propertyNames)
{
    RefPtr impl = toWebExtensionAPINamespace(context, thisObject);
    if (!impl) [[unlikely]]
        return;

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (isForMainWorld && impl->isPropertyAllowed("action"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("action").get());

    if (isForMainWorld && impl->isPropertyAllowed("alarms"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("alarms").get());

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    if (isForMainWorld && impl->isPropertyAllowed("bookmarks"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("bookmarks").get());
#endif // ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)

    if (isForMainWorld && impl->isPropertyAllowed("browserAction"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("browserAction").get());

    if (isForMainWorld && impl->isPropertyAllowed("cookies"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("cookies").get());

    if (isForMainWorld && impl->isPropertyAllowed("commands"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("commands").get());

    if (isForMainWorld && impl->isPropertyAllowed("contextMenus"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("contextMenus").get());

    if (isForMainWorld && impl->isPropertyAllowed("declarativeNetRequest"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("declarativeNetRequest").get());

#if ENABLE(INSPECTOR_EXTENSIONS)
    if (impl->isPropertyAllowed("devtools"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("devtools").get());
#endif // ENABLE(INSPECTOR_EXTENSIONS)

    if (isForMainWorld && impl->isPropertyAllowed("menus"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("menus").get());

    if (isForMainWorld && impl->isPropertyAllowed("notifications"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("notifications").get());

    if (isForMainWorld && impl->isPropertyAllowed("pageAction"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("pageAction").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("permissions").get());

    if (isForMainWorld && impl->isPropertyAllowed("scripting"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("scripting").get());

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    if (isForMainWorld && impl->isPropertyAllowed("sidebarAction"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("sidebarAction").get());
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    if (isForMainWorld && impl->isPropertyAllowed("sidePanel"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("sidePanel").get());
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)

    if (impl->isPropertyAllowed("storage"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("storage").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("tabs").get());

    if (isForMainWorld)
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("windows").get());

    if (isForMainWorld && impl->isPropertyAllowed("webNavigation"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("webNavigation").get());

    if (isForMainWorld && impl->isPropertyAllowed("webRequest"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("webRequest").get());

    if (impl->isPropertyAllowed("test"_s, page.get()))
        JSPropertyNameAccumulatorAddName(propertyNames, toJSString("test").get());

}

bool JSWebExtensionAPINamespace::hasProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName)
{
    RefPtr impl = toWebExtensionAPINamespace(context, thisObject);
    if (!impl) [[unlikely]]
        return false;

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (JSStringIsEqualToUTF8CString(propertyName, "action"))
        return isForMainWorld && impl->isPropertyAllowed("action"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "alarms"))
        return isForMainWorld && impl->isPropertyAllowed("alarms"_s, page.get());

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    if (JSStringIsEqualToUTF8CString(propertyName, "bookmarks"))
        return isForMainWorld && impl->isPropertyAllowed("bookmarks"_s, page.get());
#endif // ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)

    if (JSStringIsEqualToUTF8CString(propertyName, "browserAction"))
        return isForMainWorld && impl->isPropertyAllowed("browserAction"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "cookies"))
        return isForMainWorld && impl->isPropertyAllowed("cookies"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "commands"))
        return isForMainWorld && impl->isPropertyAllowed("commands"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "contextMenus"))
        return isForMainWorld && impl->isPropertyAllowed("contextMenus"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "declarativeNetRequest"))
        return isForMainWorld && impl->isPropertyAllowed("declarativeNetRequest"_s, page.get());

#if ENABLE(INSPECTOR_EXTENSIONS)
    if (JSStringIsEqualToUTF8CString(propertyName, "devtools"))
        return impl->isPropertyAllowed("devtools"_s, page.get());
#endif // ENABLE(INSPECTOR_EXTENSIONS)

    if (JSStringIsEqualToUTF8CString(propertyName, "menus"))
        return isForMainWorld && impl->isPropertyAllowed("menus"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "notifications"))
        return isForMainWorld && impl->isPropertyAllowed("notifications"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "pageAction"))
        return isForMainWorld && impl->isPropertyAllowed("pageAction"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "permissions"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "scripting"))
        return isForMainWorld && impl->isPropertyAllowed("scripting"_s, page.get());

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    if (JSStringIsEqualToUTF8CString(propertyName, "sidebarAction"))
        return isForMainWorld && impl->isPropertyAllowed("sidebarAction"_s, page.get());
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    if (JSStringIsEqualToUTF8CString(propertyName, "sidePanel"))
        return isForMainWorld && impl->isPropertyAllowed("sidePanel"_s, page.get());
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)

    if (JSStringIsEqualToUTF8CString(propertyName, "storage"))
        return impl->isPropertyAllowed("storage"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "tabs"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "windows"))
        return isForMainWorld;

    if (JSStringIsEqualToUTF8CString(propertyName, "webNavigation"))
        return isForMainWorld && impl->isPropertyAllowed("webNavigation"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "webRequest"))
        return isForMainWorld && impl->isPropertyAllowed("webRequest"_s, page.get());

    if (JSStringIsEqualToUTF8CString(propertyName, "test"))
        return impl->isPropertyAllowed("test"_s, page.get());

    return false;
}

JSValueRef JSWebExtensionAPINamespace::getProperty(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPINamespace(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RefPtr page = toWebPage(context);
    bool isForMainWorld = impl->isForMainWorld();

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "action") && impl->isPropertyAllowed("action"_s, page.get()))
        return action(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "alarms") && impl->isPropertyAllowed("alarms"_s, page.get()))
        return alarms(context, thisObject, propertyName, exception);

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "bookmarks") && impl->isPropertyAllowed("bookmarks"_s, page.get()))
        return bookmarks(context, thisObject, propertyName, exception);
#endif // ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "browserAction") && impl->isPropertyAllowed("browserAction"_s, page.get()))
        return browserAction(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "cookies") && impl->isPropertyAllowed("cookies"_s, page.get()))
        return cookies(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "commands") && impl->isPropertyAllowed("commands"_s, page.get()))
        return commands(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "contextMenus") && impl->isPropertyAllowed("contextMenus"_s, page.get()))
        return contextMenus(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "declarativeNetRequest") && impl->isPropertyAllowed("declarativeNetRequest"_s, page.get()))
        return declarativeNetRequest(context, thisObject, propertyName, exception);

#if ENABLE(INSPECTOR_EXTENSIONS)
    if (JSStringIsEqualToUTF8CString(propertyName, "devtools") && impl->isPropertyAllowed("devtools"_s, page.get()))
        return devtools(context, thisObject, propertyName, exception);
#endif // ENABLE(INSPECTOR_EXTENSIONS)

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "menus") && impl->isPropertyAllowed("menus"_s, page.get()))
        return menus(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "notifications") && impl->isPropertyAllowed("notifications"_s, page.get()))
        return notifications(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "pageAction") && impl->isPropertyAllowed("pageAction"_s, page.get()))
        return pageAction(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "permissions"))
        return permissions(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "scripting") && impl->isPropertyAllowed("scripting"_s, page.get()))
        return scripting(context, thisObject, propertyName, exception);

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "sidebarAction") && impl->isPropertyAllowed("sidebarAction"_s, page.get()))
        return sidebarAction(context, thisObject, propertyName, exception);
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "sidePanel") && impl->isPropertyAllowed("sidePanel"_s, page.get()))
        return sidePanel(context, thisObject, propertyName, exception);
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)

    if (JSStringIsEqualToUTF8CString(propertyName, "storage") && impl->isPropertyAllowed("storage"_s, page.get()))
        return storage(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "tabs"))
        return tabs(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "windows"))
        return windows(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "webNavigation") && impl->isPropertyAllowed("webNavigation"_s, page.get()))
        return webNavigation(context, thisObject, propertyName, exception);

    if (isForMainWorld && JSStringIsEqualToUTF8CString(propertyName, "webRequest") && impl->isPropertyAllowed("webRequest"_s, page.get()))
        return webRequest(context, thisObject, propertyName, exception);

    if (JSStringIsEqualToUTF8CString(propertyName, "test") && impl->isPropertyAllowed("test"_s, page.get()))
        return test(context, thisObject, propertyName, exception);

    return JSValueMakeUndefined(context);
}

// Attributes

JSValueRef JSWebExtensionAPINamespace::action(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.action in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->action()));
}

JSValueRef JSWebExtensionAPINamespace::alarms(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.alarms in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->alarms()));
}

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
JSValueRef JSWebExtensionAPINamespace::bookmarks(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.bookmarks in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->bookmarks()));
}
#endif // ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)

JSValueRef JSWebExtensionAPINamespace::browserAction(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.browserAction in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->browserAction()));
}

JSValueRef JSWebExtensionAPINamespace::cookies(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.cookies in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->cookies()));
}

JSValueRef JSWebExtensionAPINamespace::commands(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.commands in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->commands()));
}

JSValueRef JSWebExtensionAPINamespace::contextMenus(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.contextMenus in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->contextMenus()));
}

JSValueRef JSWebExtensionAPINamespace::declarativeNetRequest(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.declarativeNetRequest in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->declarativeNetRequest()));
}

#if ENABLE(INSPECTOR_EXTENSIONS)
JSValueRef JSWebExtensionAPINamespace::devtools(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.devtools in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->devtools()));
}
#endif // ENABLE(INSPECTOR_EXTENSIONS)

JSValueRef JSWebExtensionAPINamespace::dom(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.dom in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->dom()));
}

JSValueRef JSWebExtensionAPINamespace::extension(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.extension in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->extension()));
}

JSValueRef JSWebExtensionAPINamespace::i18n(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.i18n in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->i18n()));
}

JSValueRef JSWebExtensionAPINamespace::runtime(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.runtime in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->runtime()));
}

JSValueRef JSWebExtensionAPINamespace::menus(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.menus in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->menus()));
}

JSValueRef JSWebExtensionAPINamespace::notifications(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.notifications in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->notifications()));
}

JSValueRef JSWebExtensionAPINamespace::pageAction(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.pageAction in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->pageAction()));
}

JSValueRef JSWebExtensionAPINamespace::permissions(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.permissions in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->permissions()));
}

JSValueRef JSWebExtensionAPINamespace::scripting(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.scripting in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->scripting()));
}

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
JSValueRef JSWebExtensionAPINamespace::sidebarAction(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.sidebarAction in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->sidebarAction()));
}
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
JSValueRef JSWebExtensionAPINamespace::sidePanel(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.sidePanel in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->sidePanel()));
}
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)

JSValueRef JSWebExtensionAPINamespace::storage(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.storage in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->storage()));
}

JSValueRef JSWebExtensionAPINamespace::tabs(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.tabs in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->tabs()));
}

JSValueRef JSWebExtensionAPINamespace::windows(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.windows in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->windows()));
}

JSValueRef JSWebExtensionAPINamespace::webNavigation(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.webNavigation in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->webNavigation()));
}

JSValueRef JSWebExtensionAPINamespace::webRequest(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.webRequest in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->webRequest()));
}

JSValueRef JSWebExtensionAPINamespace::test(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPINamespace(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter browser.test in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->test()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
