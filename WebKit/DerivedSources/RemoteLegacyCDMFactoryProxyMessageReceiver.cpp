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
#if ENABLE(GPU_PROCESS) && ENABLE(LEGACY_ENCRYPTED_MEDIA)
#include "RemoteLegacyCDMFactoryProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "RemoteLegacyCDMFactoryProxyMessages.h" // NOLINT
#include "RemoteLegacyCDMIdentifier.h" // NOLINT
#include "RemoteLegacyCDMSessionIdentifier.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include <WebCore/MediaPlayerIdentifier.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteLegacyCDMFactoryProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->legacyEncryptedMediaAPIEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteLegacyCDMFactoryProxy", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteLegacyCDMFactoryProxy::RemoveSession::name())
        return IPC::handleMessageAsync<Messages::RemoteLegacyCDMFactoryProxy::RemoveSession>(connection, decoder, this, &RemoteLegacyCDMFactoryProxy::removeSession);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool RemoteLegacyCDMFactoryProxy::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(isInGPUProcess());
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->legacyEncryptedMediaAPIEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteLegacyCDMFactoryProxy", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return false;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteLegacyCDMFactoryProxy::CreateCDM::name())
        return IPC::handleMessageSynchronous<Messages::RemoteLegacyCDMFactoryProxy::CreateCDM>(connection, decoder, replyEncoder, this, &RemoteLegacyCDMFactoryProxy::createCDM);
    if (decoder.messageName() == Messages::RemoteLegacyCDMFactoryProxy::SupportsKeySystem::name())
        return IPC::handleMessageSynchronous<Messages::RemoteLegacyCDMFactoryProxy::SupportsKeySystem>(connection, decoder, replyEncoder, this, &RemoteLegacyCDMFactoryProxy::supportsKeySystem);
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteLegacyCDMFactoryProxy_CreateCDM>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteLegacyCDMFactoryProxy::CreateCDM::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteLegacyCDMFactoryProxy_CreateCDM>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteLegacyCDMFactoryProxy::CreateCDM::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteLegacyCDMFactoryProxy_SupportsKeySystem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteLegacyCDMFactoryProxy::SupportsKeySystem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteLegacyCDMFactoryProxy_SupportsKeySystem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteLegacyCDMFactoryProxy::SupportsKeySystem::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteLegacyCDMFactoryProxy_RemoveSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteLegacyCDMFactoryProxy::RemoveSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::RemoteLegacyCDMFactoryProxy_RemoveSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteLegacyCDMFactoryProxy::RemoveSession::ReplyArguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS) && ENABLE(LEGACY_ENCRYPTED_MEDIA)
