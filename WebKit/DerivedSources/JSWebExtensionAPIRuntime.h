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

#pragma once

#if ENABLE(WK_WEB_EXTENSIONS)

#include "JSWebExtensionWrapper.h"

namespace WebKit {

using namespace WTF;

class WebExtensionAPIRuntime;

class JSWebExtensionAPIRuntime : public JSWebExtensionWrapper {
public:
    static JSClassRef runtimeClass();
    static JSClassRef runtimeGlobalObjectClass();

private:
    static const JSStaticFunction* staticFunctions();
    static const JSStaticValue* staticValues();
    static const JSStaticValue* staticConstants();
    static bool hasInstance(JSContextRef, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception);

    // Functions

    static JSValueRef getURL(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getManifest(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getFrameId(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getPlatformInfo(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getBackgroundPage(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setUninstallURL(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef openOptionsPage(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef reload(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef sendMessage(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef connect(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef sendNativeMessage(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef connectNative(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);

    // Attributes

    static JSValueRef runtimeIdentifier(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef lastError(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onConnect(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onMessage(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onConnectExternal(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onMessageExternal(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onStartup(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onInstalled(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);

    // Dynamic Attributes

    static void getPropertyNames(JSContextRef, JSObjectRef, JSPropertyNameAccumulatorRef);
    static bool hasProperty(JSContextRef, JSObjectRef, JSStringRef);
    static JSValueRef getProperty(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
};

WebExtensionAPIRuntime* toWebExtensionAPIRuntime(JSContextRef, JSValueRef);

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)

