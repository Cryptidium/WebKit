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
#include "ProcessSyncClient.h"

#include "ProcessSyncData.h"
#include <wtf/EnumTraits.h>

namespace WebCore {

#if ENABLE(DOM_AUDIO_SESSION)
void ProcessSyncClient::broadcastAudioSessionTypeToOtherProcesses(const WebCore::DOMAudioSessionType& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::AudioSessionType)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::AudioSessionType, WTFMove(dataVariant) });
}
#endif
void ProcessSyncClient::broadcastIsAutofocusProcessedToOtherProcesses(const bool& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::IsAutofocusProcessed)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::IsAutofocusProcessed, WTFMove(dataVariant) });
}
void ProcessSyncClient::broadcastUserDidInteractWithPageToOtherProcesses(const bool& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::UserDidInteractWithPage)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::UserDidInteractWithPage, WTFMove(dataVariant) });
}
void ProcessSyncClient::broadcastIsClosingToOtherProcesses(const bool& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::IsClosing)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::IsClosing, WTFMove(dataVariant) });
}
void ProcessSyncClient::broadcastDocumentURLToOtherProcesses(const URL& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::DocumentURL)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::DocumentURL, WTFMove(dataVariant) });
}
void ProcessSyncClient::broadcastDocumentSecurityOriginToOtherProcesses(const RefPtr<WebCore::SecurityOrigin>& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::DocumentSecurityOrigin)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::DocumentSecurityOrigin, WTFMove(dataVariant) });
}
void ProcessSyncClient::broadcastDocumentClassesToOtherProcesses(const OptionSet<WebCore::DocumentClass>& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::DocumentClasses)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::DocumentClasses, WTFMove(dataVariant) });
}
void ProcessSyncClient::broadcastHasInjectedUserScriptToOtherProcesses(const bool& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::HasInjectedUserScript)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::HasInjectedUserScript, WTFMove(dataVariant) });
}
void ProcessSyncClient::broadcastFrameCanCreatePaymentSessionToOtherProcesses(const bool& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::FrameCanCreatePaymentSession)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::FrameCanCreatePaymentSession, WTFMove(dataVariant) });
}
void ProcessSyncClient::broadcastFrameDocumentSecurityOriginToOtherProcesses(const RefPtr<WebCore::SecurityOrigin>& data)
{
    ProcessSyncDataVariant dataVariant;
    dataVariant.emplace<enumToUnderlyingType(ProcessSyncDataType::FrameDocumentSecurityOrigin)>(data);
    broadcastProcessSyncDataToOtherProcesses({ ProcessSyncDataType::FrameDocumentSecurityOrigin, WTFMove(dataVariant) });
}

} // namespace WebCore
