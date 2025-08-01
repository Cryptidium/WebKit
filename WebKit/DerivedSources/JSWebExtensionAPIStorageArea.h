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

#pragma once

#if ENABLE(WK_WEB_EXTENSIONS)

#include "JSWebExtensionWrapper.h"

namespace WebKit {

using namespace WTF;

class WebExtensionAPIStorageArea;

class JSWebExtensionAPIStorageArea : public JSWebExtensionWrapper {
public:
    static JSClassRef storageAreaClass();
    static JSClassRef storageAreaGlobalObjectClass();

private:
    static const JSStaticFunction* staticFunctions();
    static const JSStaticValue* staticValues();
    static const JSStaticValue* staticConstants();
    static bool hasInstance(JSContextRef, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception);

    // Functions

    static JSValueRef get(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getKeys(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef getBytesInUse(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef set(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef remove(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef clear(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef setAccessLevel(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);

    // Attributes

    static JSValueRef onChanged(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef quotaBytes(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef quotaBytesPerItem(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef maxItems(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef maxWriteOperationsPerHour(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef maxWriteOperationsPerMinute(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);

    // Dynamic Attributes

    static void getPropertyNames(JSContextRef, JSObjectRef, JSPropertyNameAccumulatorRef);
    static bool hasProperty(JSContextRef, JSObjectRef, JSStringRef);
    static JSValueRef getProperty(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
};

WebExtensionAPIStorageArea* toWebExtensionAPIStorageArea(JSContextRef, JSValueRef);

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)

