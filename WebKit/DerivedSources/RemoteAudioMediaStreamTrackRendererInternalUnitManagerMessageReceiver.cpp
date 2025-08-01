/*
 * Copyright (C) 2021-2023 Apple Inc. All rights reserved.
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
#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_STREAM) && PLATFORM(COCOA)
#include "RemoteAudioMediaStreamTrackRendererInternalUnitManager.h"

#include "ArgumentCoders.h" // NOLINT
#include "AudioMediaStreamTrackRendererInternalUnitIdentifier.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "IPCSemaphore.h" // NOLINT
#include "RemoteAudioMediaStreamTrackRendererInternalUnitManagerMessages.h" // NOLINT
#include "SharedCARingBuffer.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include <WebCore/CAAudioStreamDescription.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteAudioMediaStreamTrackRendererInternalUnitManager::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->useGPUProcessForMediaEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteAudioMediaStreamTrackRendererInternalUnitManager", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::CreateUnit::name())
        return IPC::handleMessageAsync<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::CreateUnit>(connection, decoder, this, &RemoteAudioMediaStreamTrackRendererInternalUnitManager::createUnit);
    if (decoder.messageName() == Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::DeleteUnit::name())
        return IPC::handleMessage<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::DeleteUnit>(connection, decoder, this, &RemoteAudioMediaStreamTrackRendererInternalUnitManager::deleteUnit);
    if (decoder.messageName() == Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::StartUnit::name())
        return IPC::handleMessage<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::StartUnit>(connection, decoder, this, &RemoteAudioMediaStreamTrackRendererInternalUnitManager::startUnit);
    if (decoder.messageName() == Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::StopUnit::name())
        return IPC::handleMessage<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::StopUnit>(connection, decoder, this, &RemoteAudioMediaStreamTrackRendererInternalUnitManager::stopUnit);
    if (decoder.messageName() == Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::SetLastDeviceUsed::name())
        return IPC::handleMessage<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::SetLastDeviceUsed>(connection, decoder, this, &RemoteAudioMediaStreamTrackRendererInternalUnitManager::setLastDeviceUsed);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_CreateUnit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::CreateUnit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_CreateUnit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::CreateUnit::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_DeleteUnit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::DeleteUnit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_StartUnit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::StartUnit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_StopUnit>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::StopUnit::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteAudioMediaStreamTrackRendererInternalUnitManager_SetLastDeviceUsed>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteAudioMediaStreamTrackRendererInternalUnitManager::SetLastDeviceUsed::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS) && ENABLE(MEDIA_STREAM) && PLATFORM(COCOA)
