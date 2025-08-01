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


#include "config.h"
#include "DocumentSyncData.h"

#include "ProcessSyncData.h"
#include <wtf/EnumTraits.h>

namespace WebCore {

void DocumentSyncData::update(const ProcessSyncData& data)
{
    switch (data.type) {
    case ProcessSyncDataType::IsAutofocusProcessed:
        isAutofocusProcessed = std::get<enumToUnderlyingType(ProcessSyncDataType::IsAutofocusProcessed)>(data.value);
        break;
    case ProcessSyncDataType::UserDidInteractWithPage:
        userDidInteractWithPage = std::get<enumToUnderlyingType(ProcessSyncDataType::UserDidInteractWithPage)>(data.value);
        break;
    case ProcessSyncDataType::IsClosing:
        isClosing = std::get<enumToUnderlyingType(ProcessSyncDataType::IsClosing)>(data.value);
        break;
    case ProcessSyncDataType::DocumentURL:
        documentURL = std::get<enumToUnderlyingType(ProcessSyncDataType::DocumentURL)>(data.value);
        break;
    case ProcessSyncDataType::DocumentSecurityOrigin:
        documentSecurityOrigin = std::get<enumToUnderlyingType(ProcessSyncDataType::DocumentSecurityOrigin)>(data.value);
        break;
    case ProcessSyncDataType::DocumentClasses:
        documentClasses = std::get<enumToUnderlyingType(ProcessSyncDataType::DocumentClasses)>(data.value);
        break;
#if ENABLE(DOM_AUDIO_SESSION)
    case ProcessSyncDataType::AudioSessionType:
        audioSessionType = std::get<enumToUnderlyingType(ProcessSyncDataType::AudioSessionType)>(data.value);
        break;
#endif
    case ProcessSyncDataType::HasInjectedUserScript:
        hasInjectedUserScript = std::get<enumToUnderlyingType(ProcessSyncDataType::HasInjectedUserScript)>(data.value);
        break;
    default:
        RELEASE_ASSERT_NOT_REACHED();
    }
}

DocumentSyncData::DocumentSyncData(
      bool isAutofocusProcessed
    , bool userDidInteractWithPage
    , bool isClosing
    , URL documentURL
    , RefPtr<WebCore::SecurityOrigin> documentSecurityOrigin
    , OptionSet<WebCore::DocumentClass> documentClasses
#if ENABLE(DOM_AUDIO_SESSION)
    , WebCore::DOMAudioSessionType audioSessionType
#endif
    , bool hasInjectedUserScript
)
    : isAutofocusProcessed(isAutofocusProcessed)
    , userDidInteractWithPage(userDidInteractWithPage)
    , isClosing(isClosing)
    , documentURL(documentURL)
    , documentSecurityOrigin(documentSecurityOrigin)
    , documentClasses(documentClasses)
#if ENABLE(DOM_AUDIO_SESSION)
    , audioSessionType(audioSessionType)
#endif
    , hasInjectedUserScript(hasInjectedUserScript)
{
}

} // namespace WebCore
