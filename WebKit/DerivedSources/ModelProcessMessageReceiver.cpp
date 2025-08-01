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
#if ENABLE(MODEL_PROCESS)
#include "ModelProcess.h"

#include "ArgumentCoders.h" // NOLINT
#include "ConnectionHandle.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "ModelProcessConnectionParameters.h" // NOLINT
#include "ModelProcessCreationParameters.h" // NOLINT
#include "ModelProcessMessages.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include <WebCore/ProcessIdentifier.h> // NOLINT
#include <optional> // NOLINT
#include <pal/SessionID.h> // NOLINT
#include <wtf/MonotonicTime.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void ModelProcess::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::ModelProcess::InitializeModelProcess::name())
        return IPC::handleMessageAsync<Messages::ModelProcess::InitializeModelProcess>(connection, decoder, this, &ModelProcess::initializeModelProcess);
    if (decoder.messageName() == Messages::ModelProcess::CreateModelConnectionToWebProcess::name())
        return IPC::handleMessageAsync<Messages::ModelProcess::CreateModelConnectionToWebProcess>(connection, decoder, this, &ModelProcess::createModelConnectionToWebProcess);
    if (decoder.messageName() == Messages::ModelProcess::SharedPreferencesForWebProcessDidChange::name())
        return IPC::handleMessageAsync<Messages::ModelProcess::SharedPreferencesForWebProcessDidChange>(connection, decoder, this, &ModelProcess::sharedPreferencesForWebProcessDidChange);
    if (decoder.messageName() == Messages::ModelProcess::PrepareToSuspend::name())
        return IPC::handleMessageAsync<Messages::ModelProcess::PrepareToSuspend>(connection, decoder, this, &ModelProcess::prepareToSuspend);
    if (decoder.messageName() == Messages::ModelProcess::ProcessDidResume::name())
        return IPC::handleMessage<Messages::ModelProcess::ProcessDidResume>(connection, decoder, this, &ModelProcess::processDidResume);
    if (decoder.messageName() == Messages::ModelProcess::AddSession::name())
        return IPC::handleMessage<Messages::ModelProcess::AddSession>(connection, decoder, this, &ModelProcess::addSession);
    if (decoder.messageName() == Messages::ModelProcess::RemoveSession::name())
        return IPC::handleMessage<Messages::ModelProcess::RemoveSession>(connection, decoder, this, &ModelProcess::removeSession);
    if (decoder.messageName() == Messages::ModelProcess::WebProcessConnectionCountForTesting::name())
        return IPC::handleMessageAsync<Messages::ModelProcess::WebProcessConnectionCountForTesting>(connection, decoder, this, &ModelProcess::webProcessConnectionCountForTesting);
    if (decoder.messageName() == Messages::ModelProcess::ModelPlayerCountForTesting::name())
        return IPC::handleMessageAsync<Messages::ModelProcess::ModelPlayerCountForTesting>(connection, decoder, this, &ModelProcess::modelPlayerCountForTesting);
    AuxiliaryProcess::didReceiveMessage(connection, decoder);
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_InitializeModelProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::InitializeModelProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::ModelProcess_InitializeModelProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::InitializeModelProcess::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_CreateModelConnectionToWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::CreateModelConnectionToWebProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::ModelProcess_CreateModelConnectionToWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::CreateModelConnectionToWebProcess::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_SharedPreferencesForWebProcessDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::SharedPreferencesForWebProcessDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::ModelProcess_SharedPreferencesForWebProcessDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::SharedPreferencesForWebProcessDidChange::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_PrepareToSuspend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::PrepareToSuspend::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::ModelProcess_PrepareToSuspend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::PrepareToSuspend::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_ProcessDidResume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::ProcessDidResume::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_AddSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::AddSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_RemoveSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::RemoveSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_WebProcessConnectionCountForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::WebProcessConnectionCountForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::ModelProcess_WebProcessConnectionCountForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::WebProcessConnectionCountForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::ModelProcess_ModelPlayerCountForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::ModelPlayerCountForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::ModelProcess_ModelPlayerCountForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::ModelProcess::ModelPlayerCountForTesting::ReplyArguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(MODEL_PROCESS)
