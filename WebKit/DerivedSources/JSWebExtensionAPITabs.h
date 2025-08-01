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

#pragma once

#if ENABLE(WK_WEB_EXTENSIONS)

#include "JSWebExtensionWrapper.h"

namespace WebKit {

using namespace WTF;

class WebExtensionAPITabs;

class JSWebExtensionAPITabs : public JSWebExtensionWrapper {
public:
    static JSClassRef tabsClass();
    static JSClassRef tabsGlobalObjectClass();

private:
    static const JSStaticFunction* staticFunctions();
    static const JSStaticValue* staticValues();
    static const JSStaticValue* staticConstants();
    static bool hasInstance(JSContextRef, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception);

    // Functions

    static JSValueRef create(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef query(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef get(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getCurrent(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getSelected(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef duplicate(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef update(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef remove(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef reload(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef goBack(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef goForward(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getZoom(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setZoom(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef detectLanguage(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef toggleReaderMode(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef captureVisibleTab(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef executeScript(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef insertCSS(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef removeCSS(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef sendMessage(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef connect(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);

    // Attributes

    static JSValueRef tabIdentifierNone(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onActivated(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onAttached(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onCreated(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onDetached(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onHighlighted(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onMoved(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onRemoved(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onReplaced(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onUpdated(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);

    // Dynamic Attributes

    static void getPropertyNames(JSContextRef, JSObjectRef, JSPropertyNameAccumulatorRef);
    static bool hasProperty(JSContextRef, JSObjectRef, JSStringRef);
    static JSValueRef getProperty(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
};

WebExtensionAPITabs* toWebExtensionAPITabs(JSContextRef, JSValueRef);

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)

