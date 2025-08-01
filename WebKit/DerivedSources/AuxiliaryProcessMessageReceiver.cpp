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
#include "AuxiliaryProcess.h"

#if ENABLE(CFPREFS_DIRECT_MODE)
#include "ArgumentCoders.h" // NOLINT
#endif
#include "AuxiliaryProcessMessages.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if ENABLE(CFPREFS_DIRECT_MODE)
#include <optional> // NOLINT
#endif
#if ENABLE(CFPREFS_DIRECT_MODE)
#include <wtf/text/WTFString.h> // NOLINT
#endif

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void AuxiliaryProcess::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::AuxiliaryProcess::ShutDown::name())
        return IPC::handleMessage<Messages::AuxiliaryProcess::ShutDown>(connection, decoder, this, &AuxiliaryProcess::shutDown);
    if (decoder.messageName() == Messages::AuxiliaryProcess::SetProcessSuppressionEnabled::name())
        return IPC::handleMessage<Messages::AuxiliaryProcess::SetProcessSuppressionEnabled>(connection, decoder, this, &AuxiliaryProcess::setProcessSuppressionEnabled);
    if (decoder.messageName() == Messages::AuxiliaryProcess::MainThreadPing::name())
        return IPC::handleMessageAsync<Messages::AuxiliaryProcess::MainThreadPing>(connection, decoder, this, &AuxiliaryProcess::mainThreadPing);
#if ENABLE(CFPREFS_DIRECT_MODE)
    if (decoder.messageName() == Messages::AuxiliaryProcess::PreferenceDidUpdate::name())
        return IPC::handleMessage<Messages::AuxiliaryProcess::PreferenceDidUpdate>(connection, decoder, this, &AuxiliaryProcess::preferenceDidUpdate);
#endif
#if OS(LINUX)
    if (decoder.messageName() == Messages::AuxiliaryProcess::DidReceiveMemoryPressureEvent::name())
        return IPC::handleMessage<Messages::AuxiliaryProcess::DidReceiveMemoryPressureEvent>(connection, decoder, this, &AuxiliaryProcess::didReceiveMemoryPressureEvent);
#endif
    if (dispatchMessage(connection, decoder))
        return;
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool AuxiliaryProcess::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    Ref protectedThis { *this };
    if (dispatchSyncMessage(connection, decoder, replyEncoder))
        return true;
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::AuxiliaryProcess_ShutDown>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::AuxiliaryProcess::ShutDown::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::AuxiliaryProcess_SetProcessSuppressionEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::AuxiliaryProcess::SetProcessSuppressionEnabled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::AuxiliaryProcess_MainThreadPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::AuxiliaryProcess::MainThreadPing::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::AuxiliaryProcess_MainThreadPing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::AuxiliaryProcess::MainThreadPing::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(CFPREFS_DIRECT_MODE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::AuxiliaryProcess_PreferenceDidUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::AuxiliaryProcess::PreferenceDidUpdate::Arguments>(globalObject, decoder);
}
#endif
#if OS(LINUX)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::AuxiliaryProcess_DidReceiveMemoryPressureEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::AuxiliaryProcess::DidReceiveMemoryPressureEvent::Arguments>(globalObject, decoder);
}
#endif

}

#endif

