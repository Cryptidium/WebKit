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

class WebExtensionAPITest;

class JSWebExtensionAPITest : public JSWebExtensionWrapper {
public:
    static JSClassRef testClass();
    static JSClassRef testGlobalObjectClass();

private:
    static const JSStaticFunction* staticFunctions();
    static const JSStaticValue* staticValues();
    static const JSStaticValue* staticConstants();
    static bool hasInstance(JSContextRef, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception);

    // Functions

    static JSValueRef notifyFail(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef notifyPass(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef sendMessage(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef runWithUserGesture(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef isProcessingUserGesture(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef log(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef fail(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef succeed(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertTrue(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertFalse(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertDeepEq(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertEq(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertRejects(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertResolves(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertThrows(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertSafe(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef assertSafeResolve(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef addTest(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
    static JSValueRef runTests(JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);

    // Attributes

    static JSValueRef onMessage(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onTestStarted(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onTestFinished(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
};

WebExtensionAPITest* toWebExtensionAPITest(JSContextRef, JSValueRef);

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)

