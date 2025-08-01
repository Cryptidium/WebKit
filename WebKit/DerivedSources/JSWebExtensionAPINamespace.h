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

#pragma once

#if ENABLE(WK_WEB_EXTENSIONS)

#include "JSWebExtensionWrapper.h"

namespace WebKit {

using namespace WTF;

class WebExtensionAPINamespace;

class JSWebExtensionAPINamespace : public JSWebExtensionWrapper {
public:
    static JSClassRef namespaceClass();
    static JSClassRef namespaceGlobalObjectClass();

private:
    static const JSStaticFunction* staticFunctions();
    static const JSStaticValue* staticValues();
    static const JSStaticValue* staticConstants();
    static bool hasInstance(JSContextRef, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception);

    // Attributes

    static JSValueRef action(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef alarms(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    static JSValueRef bookmarks(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
#endif // ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    static JSValueRef browserAction(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef cookies(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef commands(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef contextMenus(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef declarativeNetRequest(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
#if ENABLE(INSPECTOR_EXTENSIONS)
    static JSValueRef devtools(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
#endif // ENABLE(INSPECTOR_EXTENSIONS)
    static JSValueRef dom(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef extension(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef i18n(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef runtime(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef menus(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef notifications(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef pageAction(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef permissions(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef scripting(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    static JSValueRef sidebarAction(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    static JSValueRef sidePanel(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
#endif // ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    static JSValueRef storage(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef tabs(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef windows(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef webNavigation(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef webRequest(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef test(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);

    // Dynamic Attributes

    static void getPropertyNames(JSContextRef, JSObjectRef, JSPropertyNameAccumulatorRef);
    static bool hasProperty(JSContextRef, JSObjectRef, JSStringRef);
    static JSValueRef getProperty(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
};

WebExtensionAPINamespace* toWebExtensionAPINamespace(JSContextRef, JSValueRef);

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)

