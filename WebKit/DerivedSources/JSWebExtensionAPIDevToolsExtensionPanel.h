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

#if ENABLE(INSPECTOR_EXTENSIONS) && ENABLE(WK_WEB_EXTENSIONS)

#include "JSWebExtensionWrapper.h"

namespace WebKit {

using namespace WTF;

class WebExtensionAPIDevToolsExtensionPanel;

class JSWebExtensionAPIDevToolsExtensionPanel : public JSWebExtensionWrapper {
public:
    static JSClassRef devToolsExtensionPanelClass();
    static JSClassRef devToolsExtensionPanelGlobalObjectClass();

private:
    static const JSStaticFunction* staticFunctions();
    static const JSStaticValue* staticValues();
    static const JSStaticValue* staticConstants();
    static bool hasInstance(JSContextRef, JSObjectRef constructor, JSValueRef possibleInstance, JSValueRef* exception);

    // Attributes

    static JSValueRef onShown(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
    static JSValueRef onHidden(JSContextRef, JSObjectRef, JSStringRef, JSValueRef*);
};

WebExtensionAPIDevToolsExtensionPanel* toWebExtensionAPIDevToolsExtensionPanel(JSContextRef, JSValueRef);

} // namespace WebKit

#endif // ENABLE(INSPECTOR_EXTENSIONS) && ENABLE(WK_WEB_EXTENSIONS)

