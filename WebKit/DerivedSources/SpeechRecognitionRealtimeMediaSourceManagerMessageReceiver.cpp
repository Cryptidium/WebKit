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
#if ENABLE(MEDIA_STREAM)
#include "SpeechRecognitionRealtimeMediaSourceManager.h"

#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "SpeechRecognitionRealtimeMediaSourceManagerMessages.h" // NOLINT
#include <WebCore/CaptureDevice.h> // NOLINT
#include <WebCore/PageIdentifier.h> // NOLINT
#include <WebCore/RealtimeMediaSourceIdentifier.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void SpeechRecognitionRealtimeMediaSourceManager::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::SpeechRecognitionRealtimeMediaSourceManager::CreateSource::name())
        return IPC::handleMessage<Messages::SpeechRecognitionRealtimeMediaSourceManager::CreateSource>(connection, decoder, this, &SpeechRecognitionRealtimeMediaSourceManager::createSource);
    if (decoder.messageName() == Messages::SpeechRecognitionRealtimeMediaSourceManager::DeleteSource::name())
        return IPC::handleMessage<Messages::SpeechRecognitionRealtimeMediaSourceManager::DeleteSource>(connection, decoder, this, &SpeechRecognitionRealtimeMediaSourceManager::deleteSource);
    if (decoder.messageName() == Messages::SpeechRecognitionRealtimeMediaSourceManager::Start::name())
        return IPC::handleMessage<Messages::SpeechRecognitionRealtimeMediaSourceManager::Start>(connection, decoder, this, &SpeechRecognitionRealtimeMediaSourceManager::start);
    if (decoder.messageName() == Messages::SpeechRecognitionRealtimeMediaSourceManager::Stop::name())
        return IPC::handleMessage<Messages::SpeechRecognitionRealtimeMediaSourceManager::Stop>(connection, decoder, this, &SpeechRecognitionRealtimeMediaSourceManager::stop);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SpeechRecognitionRealtimeMediaSourceManager_CreateSource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SpeechRecognitionRealtimeMediaSourceManager::CreateSource::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SpeechRecognitionRealtimeMediaSourceManager_DeleteSource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SpeechRecognitionRealtimeMediaSourceManager::DeleteSource::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SpeechRecognitionRealtimeMediaSourceManager_Start>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SpeechRecognitionRealtimeMediaSourceManager::Start::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::SpeechRecognitionRealtimeMediaSourceManager_Stop>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::SpeechRecognitionRealtimeMediaSourceManager::Stop::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(MEDIA_STREAM)
