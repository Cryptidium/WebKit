/*
 * Copyright (C) 2025 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "DOMAudioSession.h"
#include <wtf/URL.h>
#include "SecurityOrigin.h"
#include "DocumentClasses.h"
#include "SecurityOrigin.h"
#include <variant>

namespace WebCore {

enum class ProcessSyncDataType : uint8_t {
#if ENABLE(DOM_AUDIO_SESSION)
    AudioSessionType = 0,
#endif
    IsAutofocusProcessed = 1,
    UserDidInteractWithPage = 2,
    IsClosing = 3,
    DocumentURL = 4,
    DocumentSecurityOrigin = 5,
    DocumentClasses = 6,
    HasInjectedUserScript = 7,
    FrameCanCreatePaymentSession = 8,
    FrameDocumentSecurityOrigin = 9,
};

static const ProcessSyncDataType allDocumentSyncDataTypes[] = {
    ProcessSyncDataType::IsAutofocusProcessed
    , ProcessSyncDataType::UserDidInteractWithPage
    , ProcessSyncDataType::IsClosing
    , ProcessSyncDataType::DocumentURL
    , ProcessSyncDataType::DocumentSecurityOrigin
    , ProcessSyncDataType::DocumentClasses
#if ENABLE(DOM_AUDIO_SESSION)
    , ProcessSyncDataType::AudioSessionType
#endif
    , ProcessSyncDataType::HasInjectedUserScript
};

static const ProcessSyncDataType allFrameTreeSyncDataTypes[] = {
    ProcessSyncDataType::FrameCanCreatePaymentSession
    , ProcessSyncDataType::FrameDocumentSecurityOrigin
};

#if !ENABLE(DOM_AUDIO_SESSION)
using DOMAudioSessionType = bool;
#endif

using ProcessSyncDataVariant = Variant<
    WebCore::DOMAudioSessionType,
    bool,
    bool,
    bool,
    URL,
    RefPtr<WebCore::SecurityOrigin>,
    OptionSet<WebCore::DocumentClass>,
    bool,
    bool,
    RefPtr<WebCore::SecurityOrigin>
>;

struct ProcessSyncData {
    ProcessSyncDataType type;
    ProcessSyncDataVariant value;
};

}; // namespace WebCore
