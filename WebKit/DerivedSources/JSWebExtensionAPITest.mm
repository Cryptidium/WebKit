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

#include "JSWebExtensionAPIEvent.h"
#include "JSWebExtensionAPITest.h"
#include "Logging.h"
#include "WebExtensionAPIEvent.h"
#include "WebExtensionAPITest.h"
#include "WebExtensionUtilities.h"
#include "WebFrame.h"
#include "WebPage.h"
#include <wtf/GetPtr.h>

namespace WebKit {

WebExtensionAPITest* toWebExtensionAPITest(JSContextRef context, JSValueRef value)
{
    if (!context || !value || !JSWebExtensionAPITest::testClass() || !JSValueIsObjectOfClass(context, value, JSWebExtensionAPITest::testClass()))
        return nullptr;
    return static_cast<WebExtensionAPITest*>(JSWebExtensionWrapper::unwrap(context, value));
}

JSClassRef JSWebExtensionAPITest::testClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Test";
        definition.parentClass = nullptr;
        definition.staticValues = staticValues();
        definition.staticFunctions = staticFunctions();
        definition.initialize = initialize;
        definition.finalize = finalize;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

JSClassRef JSWebExtensionAPITest::testGlobalObjectClass()
{
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = "Test";
        definition.staticValues = staticConstants();
        definition.hasInstance = hasInstance;
        jsClass = JSClassCreate(&definition);
    }

    return jsClass;
}

const JSStaticFunction* JSWebExtensionAPITest::staticFunctions()
{
    static const JSStaticFunction functions[] = {
        { "notifyFail", notifyFail, kJSPropertyAttributeNone },
        { "notifyPass", notifyPass, kJSPropertyAttributeNone },
        { "sendMessage", sendMessage, kJSPropertyAttributeNone },
        { "runWithUserGesture", runWithUserGesture, kJSPropertyAttributeNone },
        { "isProcessingUserGesture", isProcessingUserGesture, kJSPropertyAttributeNone },
        { "log", log, kJSPropertyAttributeNone },
        { "fail", fail, kJSPropertyAttributeNone },
        { "succeed", succeed, kJSPropertyAttributeNone },
        { "assertTrue", assertTrue, kJSPropertyAttributeNone },
        { "assertFalse", assertFalse, kJSPropertyAttributeNone },
        { "assertDeepEq", assertDeepEq, kJSPropertyAttributeNone },
        { "assertEq", assertEq, kJSPropertyAttributeNone },
        { "assertRejects", assertRejects, kJSPropertyAttributeNone },
        { "assertResolves", assertResolves, kJSPropertyAttributeNone },
        { "assertThrows", assertThrows, kJSPropertyAttributeNone },
        { "assertSafe", assertSafe, kJSPropertyAttributeNone },
        { "assertSafeResolve", assertSafeResolve, kJSPropertyAttributeNone },
        { "addTest", addTest, kJSPropertyAttributeNone },
        { "runTests", runTests, kJSPropertyAttributeNone },
        { nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return functions;
}

const JSStaticValue* JSWebExtensionAPITest::staticValues()
{
    static const JSStaticValue values[] = {
        { "onMessage", onMessage, nullptr, kJSPropertyAttributeNone },
        { "onTestStarted", onTestStarted, nullptr, kJSPropertyAttributeNone },
        { "onTestFinished", onTestFinished, nullptr, kJSPropertyAttributeNone },
        { nullptr, nullptr, nullptr, kJSPropertyAttributeNone },
    };

    return values;
}

const JSStaticValue* JSWebExtensionAPITest::staticConstants()
{
    return nullptr;
}

bool JSWebExtensionAPITest::hasInstance(JSContextRef ctx, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception)
{
    return JSValueIsObjectOfClass(ctx, possibleInstance, testClass());
}

// Functions

JSValueRef JSWebExtensionAPITest::notifyFail(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.notifyFail() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSString *message;

    if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.notifyFail()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        message = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    impl->notifyFail(context, message);

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::notifyPass(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.notifyPass() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSString *message;

    if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.notifyPass()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        message = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    impl->notifyPass(context, message);

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::sendMessage(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.sendMessage() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.sendMessage()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    NSString *message;
    JSValue *argument;

    if (argumentCount == 2) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.sendMessage()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        message = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
        argument = toJSValue(context, arguments[1]);
    } else if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.sendMessage()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        message = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    if (!message) [[unlikely]] {
        *exception = toJSError(context, @"test.sendMessage()", @"message", @"a string is expected");
        return JSValueMakeUndefined(context);
    }

    impl->sendMessage(context, message, argument);

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::runWithUserGesture(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.runWithUserGesture() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.runWithUserGesture()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *function = toJSValue(context, arguments[0]);

    RefPtr frame = toWebFrame(context);
    if (!frame) [[unlikely]] {
        RELEASE_LOG_ERROR(Extensions, "Frame could not be found for JSContextRef");
        return JSValueMakeUndefined(context);
    }

    return toJSValueRefOrJSNull(context, impl->runWithUserGesture(*frame, function));
}

JSValueRef JSWebExtensionAPITest::isProcessingUserGesture(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.isProcessingUserGesture() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    return JSValueMakeBoolean(context, impl->isProcessingUserGesture());
}

JSValueRef JSWebExtensionAPITest::log(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.log() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.log()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *message = toJSValue(context, arguments[0]);

    impl->log(context, message);

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::fail(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.fail() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSString *message;

    if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.fail()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        message = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    impl->fail(context, message);

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::succeed(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.succeed() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    NSString *message;

    if (argumentCount == 1) {
        if (!(JSValueIsString(context, arguments[0]) || JSValueIsNull(context, arguments[0]) || JSValueIsUndefined(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.succeed()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        message = toNSString(context, arguments[0], NullStringPolicy::NullAndUndefinedAsNullString);
    }

    impl->succeed(context, message);

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::assertTrue(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertTrue() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertTrue()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    bool actualValue = false;
    NSString *message;

    if (argumentCount == 2) {
        if (!(JSValueIsBoolean(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertTrue()", @"actualValue", @"a boolean is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertTrue()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        actualValue = JSValueToBoolean(context, arguments[0]);
        message = toNSString(context, arguments[1], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 1) {
        if (!(JSValueIsBoolean(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertTrue()", @"actualValue", @"a boolean is expected");
            return JSValueMakeUndefined(context);
        }

        actualValue = JSValueToBoolean(context, arguments[0]);
    }

    NSString *exceptionString;
    impl->assertTrue(context, actualValue, message, &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"test.assertTrue()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::assertFalse(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertFalse() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertFalse()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    bool actualValue = false;
    NSString *message;

    if (argumentCount == 2) {
        if (!(JSValueIsBoolean(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertFalse()", @"actualValue", @"a boolean is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertFalse()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        actualValue = JSValueToBoolean(context, arguments[0]);
        message = toNSString(context, arguments[1], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 1) {
        if (!(JSValueIsBoolean(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertFalse()", @"actualValue", @"a boolean is expected");
            return JSValueMakeUndefined(context);
        }

        actualValue = JSValueToBoolean(context, arguments[0]);
    }

    NSString *exceptionString;
    impl->assertFalse(context, actualValue, message, &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"test.assertFalse()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::assertDeepEq(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertDeepEq() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 2;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertDeepEq()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *actualValue;
    JSValue *expectedValue;
    NSString *message;

    if (argumentCount == 3) {
        if (!(JSValueIsString(context, arguments[2]) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertDeepEq()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        actualValue = toJSValue(context, arguments[0]);
        expectedValue = toJSValue(context, arguments[1]);
        message = toNSString(context, arguments[2], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 2) {
        actualValue = toJSValue(context, arguments[0]);
        expectedValue = toJSValue(context, arguments[1]);
    }

    NSString *exceptionString;
    impl->assertDeepEq(context, actualValue, expectedValue, message, &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"test.assertDeepEq()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::assertEq(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertEq() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 2;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertEq()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *actualValue;
    JSValue *expectedValue;
    NSString *message;

    if (argumentCount == 3) {
        if (!(JSValueIsString(context, arguments[2]) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertEq()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        actualValue = toJSValue(context, arguments[0]);
        expectedValue = toJSValue(context, arguments[1]);
        message = toNSString(context, arguments[2], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 2) {
        actualValue = toJSValue(context, arguments[0]);
        expectedValue = toJSValue(context, arguments[1]);
    }

    NSString *exceptionString;
    impl->assertEq(context, actualValue, expectedValue, message, &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"test.assertEq()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::assertRejects(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertRejects() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    size_t argumentIndex = argumentCount;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertRejects()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *promise;
    JSValue *expectedError;
    NSString *message;

    if (argumentCount == 3) {
        if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertRejects()", @"promise", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[2]) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertRejects()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        promise = toJSValue(context, arguments[0]);
        expectedError = toJSValue(context, arguments[1]);
        message = toNSString(context, arguments[2], NullStringPolicy::NullAndUndefinedAsNullString);
    } else {
        JSValueRef currentArgument = nullptr;
        size_t allowedOptionalArgumentCount = argumentCount - requiredArgumentCount;
        size_t processedOptionalArgumentCount = 0;
        argumentIndex = 0;

        if (argumentIndex < argumentCount && (currentArgument = arguments[argumentIndex])) {
            if (!(JSValueIsObject(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"test.assertRejects()", @"promise", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            promise = toJSValue(context, currentArgument);
            ++argumentIndex;
        }

        if (argumentIndex < argumentCount && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (currentArgument) {
                expectedError = toJSValue(context, currentArgument);
                ++processedOptionalArgumentCount;
                ++argumentIndex;
            }
        }

        if (argumentIndex < argumentCount && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsString(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                message = toNSString(context, currentArgument, NullStringPolicy::NullAndUndefinedAsNullString);
                ++processedOptionalArgumentCount;
                ++argumentIndex;
            }
        }
    }

    if (promise && !promise.isObject) [[unlikely]] {
        *exception = toJSError(context, @"test.assertRejects()", @"promise", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex < argumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertRejects()", nil, @"an unknown argument was provided");
        return JSValueMakeUndefined(context);
    }

    return toJSValueRefOrJSNull(context, impl->assertRejects(context, promise, expectedError, message));
}

JSValueRef JSWebExtensionAPITest::assertResolves(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertResolves() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertResolves()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *promise;
    NSString *message;

    if (argumentCount == 2) {
        if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertResolves()", @"promise", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertResolves()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        promise = toJSValue(context, arguments[0]);
        message = toNSString(context, arguments[1], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 1) {
        if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertResolves()", @"promise", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        promise = toJSValue(context, arguments[0]);
    }

    if (promise && !promise.isObject) [[unlikely]] {
        *exception = toJSError(context, @"test.assertResolves()", @"promise", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    return toJSValueRefOrJSNull(context, impl->assertResolves(context, promise, message));
}

JSValueRef JSWebExtensionAPITest::assertThrows(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertThrows() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    size_t argumentIndex = argumentCount;
    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertThrows()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *function;
    JSValue *expectedError;
    NSString *message;

    if (argumentCount == 3) {
        if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertThrows()", @"function", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[2]) || JSValueIsNull(context, arguments[2]) || JSValueIsUndefined(context, arguments[2]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertThrows()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        function = toJSValue(context, arguments[0]);
        expectedError = toJSValue(context, arguments[1]);
        message = toNSString(context, arguments[2], NullStringPolicy::NullAndUndefinedAsNullString);
    } else {
        JSValueRef currentArgument = nullptr;
        size_t allowedOptionalArgumentCount = argumentCount - requiredArgumentCount;
        size_t processedOptionalArgumentCount = 0;
        argumentIndex = 0;

        if (argumentIndex < argumentCount && (currentArgument = arguments[argumentIndex])) {
            if (!(JSValueIsObject(context, currentArgument))) [[unlikely]] {
                *exception = toJSError(context, @"test.assertThrows()", @"function", @"an object is expected");
                return JSValueMakeUndefined(context);
            }

            function = toJSValue(context, currentArgument);
            ++argumentIndex;
        }

        if (argumentIndex < argumentCount && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (currentArgument) {
                expectedError = toJSValue(context, currentArgument);
                ++processedOptionalArgumentCount;
                ++argumentIndex;
            }
        }

        if (argumentIndex < argumentCount && processedOptionalArgumentCount < allowedOptionalArgumentCount && (currentArgument = arguments[argumentIndex])) {
            if (JSValueIsString(context, currentArgument) || JSValueIsNull(context, currentArgument) || JSValueIsUndefined(context, currentArgument)) {
                message = toNSString(context, currentArgument, NullStringPolicy::NullAndUndefinedAsNullString);
                ++processedOptionalArgumentCount;
                ++argumentIndex;
            }
        }
    }

    if (function && !function.isObject) [[unlikely]] {
        *exception = toJSError(context, @"test.assertThrows()", @"function", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    if (argumentIndex < argumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertThrows()", nil, @"an unknown argument was provided");
        return JSValueMakeUndefined(context);
    }

    NSString *exceptionString;
    impl->assertThrows(context, function, expectedError, message, &exceptionString);

    if (exceptionString) [[unlikely]] {
        *exception = toJSError(context, @"test.assertThrows()", nil, exceptionString);
        return JSValueMakeUndefined(context);
    }

    return JSValueMakeUndefined(context);
}

JSValueRef JSWebExtensionAPITest::assertSafe(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertSafe() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertSafe()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *function;
    NSString *message;

    if (argumentCount == 2) {
        if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertSafe()", @"function", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertSafe()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        function = toJSValue(context, arguments[0]);
        message = toNSString(context, arguments[1], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 1) {
        if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertSafe()", @"function", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        function = toJSValue(context, arguments[0]);
    }

    if (function && !function.isObject) [[unlikely]] {
        *exception = toJSError(context, @"test.assertSafe()", @"function", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    return toJSValueRefOrJSNull(context, impl->assertSafe(context, function, message));
}

JSValueRef JSWebExtensionAPITest::assertSafeResolve(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.assertSafeResolve() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.assertSafeResolve()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    JSValue *function;
    NSString *message;

    if (argumentCount == 2) {
        if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertSafeResolve()", @"function", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        if (!(JSValueIsString(context, arguments[1]) || JSValueIsNull(context, arguments[1]) || JSValueIsUndefined(context, arguments[1]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertSafeResolve()", @"message", @"a string is expected");
            return JSValueMakeUndefined(context);
        }

        function = toJSValue(context, arguments[0]);
        message = toNSString(context, arguments[1], NullStringPolicy::NullAndUndefinedAsNullString);
    } else if (argumentCount == 1) {
        if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
            *exception = toJSError(context, @"test.assertSafeResolve()", @"function", @"an object is expected");
            return JSValueMakeUndefined(context);
        }

        function = toJSValue(context, arguments[0]);
    }

    if (function && !function.isObject) [[unlikely]] {
        *exception = toJSError(context, @"test.assertSafeResolve()", @"function", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    return toJSValueRefOrJSNull(context, impl->assertSafeResolve(context, function, message));
}

JSValueRef JSWebExtensionAPITest::addTest(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.addTest() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.addTest()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!(JSValueIsObject(context, arguments[0]))) [[unlikely]] {
        *exception = toJSError(context, @"test.addTest()", @"function", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    JSValue *function = toJSValue(context, arguments[0]);

    if (function && !function.isObject) [[unlikely]] {
        *exception = toJSError(context, @"test.addTest()", @"function", @"an object is expected");
        return JSValueMakeUndefined(context);
    }

    return toJSValueRefOrJSNull(context, impl->addTest(context, function));
}

JSValueRef JSWebExtensionAPITest::runTests(JSContextRef context, JSObjectRef, JSObjectRef thisObject, size_t argumentCount, const JSValueRef unsafeArguments[], JSValueRef* exception)
{
    RefPtr impl = toWebExtensionAPITest(context, thisObject);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called function test.runTests() (%{public}lu %{public}s) in %{public}s world", argumentCount, argumentCount == 1 ? "argument" : "arguments", toDebugString(impl->contentWorldType()).utf8().data());

    auto arguments = unsafeMakeSpan(unsafeArguments, argumentCount);

    constexpr size_t requiredArgumentCount = 1;
    if (argumentCount < requiredArgumentCount) [[unlikely]] {
        *exception = toJSError(context, @"test.runTests()", nil, @"a required argument is missing");
        return JSValueMakeUndefined(context);
    }

    if (!(JSValueIsArray(context, arguments[0]))) [[unlikely]] {
        *exception = toJSError(context, @"test.runTests()", @"tests", @"an array is expected");
        return JSValueMakeUndefined(context);
    }

    NSArray *tests = toNSArray(context, arguments[0], JSValue.class);

    if (!tests) [[unlikely]] {
        *exception = toJSError(context, @"test.runTests()", @"tests", @"an array is expected");
        return JSValueMakeUndefined(context);
    }

    return toJSValueRefOrJSNull(context, impl->runTests(context, tests));
}

// Attributes

JSValueRef JSWebExtensionAPITest::onMessage(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITest(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter test.onMessage in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onMessage()));
}

JSValueRef JSWebExtensionAPITest::onTestStarted(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITest(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter test.onTestStarted in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onTestStarted()));
}

JSValueRef JSWebExtensionAPITest::onTestFinished(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    UNUSED_PARAM(propertyName);

    RefPtr impl = toWebExtensionAPITest(context, object);
    if (!impl) [[unlikely]]
        return JSValueMakeUndefined(context);

    RELEASE_LOG_DEBUG(Extensions, "Called getter test.onTestFinished in %{public}s world", toDebugString(impl->contentWorldType()).utf8().data());

    return toJS(context, getPtr(impl->onTestFinished()));
}

} // namespace WebKit

#endif // ENABLE(WK_WEB_EXTENSIONS)
