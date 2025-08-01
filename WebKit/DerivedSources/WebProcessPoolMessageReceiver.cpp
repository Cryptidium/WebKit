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
#include "WebProcessPool.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "UserData.h" // NOLINT
#include "WebProcessPoolMessages.h" // NOLINT
#if ENABLE(GAMEPAD)
#include <WebCore/GamepadEffectParameters.h> // NOLINT
#endif
#if ENABLE(GAMEPAD)
#include <WebCore/GamepadHapticEffectType.h> // NOLINT
#endif
#include <wtf/Seconds.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebProcessPool::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess(connection);
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebProcessPool::HandleMessage::name())
        return IPC::handleMessage<Messages::WebProcessPool::HandleMessage>(connection, decoder, this, &WebProcessPool::handleMessage);
#if ENABLE(GAMEPAD)
    if (decoder.messageName() == Messages::WebProcessPool::StartedUsingGamepads::name()) {
        if (!(sharedPreferences && sharedPreferences->gamepadsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebProcessPool::StartedUsingGamepads>(connection, decoder, this, &WebProcessPool::startedUsingGamepads);
    }
    if (decoder.messageName() == Messages::WebProcessPool::StoppedUsingGamepads::name()) {
        if (!(sharedPreferences && sharedPreferences->gamepadsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebProcessPool::StoppedUsingGamepads>(connection, decoder, this, &WebProcessPool::stoppedUsingGamepads);
    }
    if (decoder.messageName() == Messages::WebProcessPool::PlayGamepadEffect::name()) {
        if (!(sharedPreferences && sharedPreferences->gamepadsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebProcessPool::PlayGamepadEffect>(connection, decoder, this, &WebProcessPool::playGamepadEffect);
    }
    if (decoder.messageName() == Messages::WebProcessPool::StopGamepadEffects::name()) {
        if (!(sharedPreferences && sharedPreferences->gamepadsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebProcessPool::StopGamepadEffects>(connection, decoder, this, &WebProcessPool::stopGamepadEffects);
    }
#endif
#if ENABLE(MODEL_PROCESS)
    if (decoder.messageName() == Messages::WebProcessPool::StartedPlayingModels::name()) {
        if (!(sharedPreferences && (sharedPreferences->modelElementEnabled && sharedPreferences->modelProcessEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebProcessPool::StartedPlayingModels>(connection, decoder, this, &WebProcessPool::startedPlayingModels);
    }
    if (decoder.messageName() == Messages::WebProcessPool::StoppedPlayingModels::name()) {
        if (!(sharedPreferences && (sharedPreferences->modelElementEnabled && sharedPreferences->modelProcessEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebProcessPool::StoppedPlayingModels>(connection, decoder, this, &WebProcessPool::stoppedPlayingModels);
    }
#endif
    if (decoder.messageName() == Messages::WebProcessPool::ReportWebContentCPUTime::name())
        return IPC::handleMessage<Messages::WebProcessPool::ReportWebContentCPUTime>(connection, decoder, this, &WebProcessPool::reportWebContentCPUTime);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool WebProcessPool::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(!isInAuxiliaryProcess());
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebProcessPool::HandleSynchronousMessage::name())
        return IPC::handleMessageSynchronous<Messages::WebProcessPool::HandleSynchronousMessage>(connection, decoder, replyEncoder, this, &WebProcessPool::handleSynchronousMessage);
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_HandleMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::HandleMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_HandleSynchronousMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::HandleSynchronousMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessPool_HandleSynchronousMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::HandleSynchronousMessage::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(GAMEPAD)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_StartedUsingGamepads>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::StartedUsingGamepads::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_StoppedUsingGamepads>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::StoppedUsingGamepads::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessPool_StoppedUsingGamepads>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::StoppedUsingGamepads::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_PlayGamepadEffect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::PlayGamepadEffect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessPool_PlayGamepadEffect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::PlayGamepadEffect::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_StopGamepadEffects>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::StopGamepadEffects::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebProcessPool_StopGamepadEffects>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::StopGamepadEffects::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(MODEL_PROCESS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_StartedPlayingModels>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::StartedPlayingModels::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_StoppedPlayingModels>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::StoppedPlayingModels::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebProcessPool_ReportWebContentCPUTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebProcessPool::ReportWebContentCPUTime::Arguments>(globalObject, decoder);
}

}

#endif

