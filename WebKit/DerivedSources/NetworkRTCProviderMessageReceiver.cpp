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
#if USE(LIBWEBRTC)
#include "NetworkRTCProvider.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "LibWebRTCResolverIdentifier.h" // NOLINT
#include "NetworkRTCProviderMessages.h" // NOLINT
#include "RTCNetwork.h" // NOLINT
#include "RTCPacketOptions.h" // NOLINT
#include "WebPageProxyIdentifier.h" // NOLINT
#include <WebCore/LibWebRTCSocketIdentifier.h> // NOLINT
#include <WebCore/RegistrableDomain.h> // NOLINT
#include <span> // NOLINT
#if PLATFORM(COCOA)
#include <wtf/URLHash.h> // NOLINT
#endif
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void NetworkRTCProvider::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::NetworkRTCProvider::CreateUDPSocket::name())
        return IPC::handleMessage<Messages::NetworkRTCProvider::CreateUDPSocket>(connection, decoder, this, &NetworkRTCProvider::createUDPSocket);
    if (decoder.messageName() == Messages::NetworkRTCProvider::CreateClientTCPSocket::name())
        return IPC::handleMessage<Messages::NetworkRTCProvider::CreateClientTCPSocket>(connection, decoder, this, &NetworkRTCProvider::createClientTCPSocket);
    if (decoder.messageName() == Messages::NetworkRTCProvider::CreateResolver::name())
        return IPC::handleMessage<Messages::NetworkRTCProvider::CreateResolver>(connection, decoder, this, &NetworkRTCProvider::createResolver);
    if (decoder.messageName() == Messages::NetworkRTCProvider::StopResolver::name())
        return IPC::handleMessage<Messages::NetworkRTCProvider::StopResolver>(connection, decoder, this, &NetworkRTCProvider::stopResolver);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::NetworkRTCProvider::GetInterfaceName::name())
        return IPC::handleMessageAsync<Messages::NetworkRTCProvider::GetInterfaceName>(connection, decoder, this, &NetworkRTCProvider::getInterfaceName);
#endif
    if (decoder.messageName() == Messages::NetworkRTCProvider::SendToSocket::name())
        return IPC::handleMessage<Messages::NetworkRTCProvider::SendToSocket>(connection, decoder, this, &NetworkRTCProvider::sendToSocket);
    if (decoder.messageName() == Messages::NetworkRTCProvider::CloseSocket::name())
        return IPC::handleMessage<Messages::NetworkRTCProvider::CloseSocket>(connection, decoder, this, &NetworkRTCProvider::closeSocket);
    if (decoder.messageName() == Messages::NetworkRTCProvider::SetSocketOption::name())
        return IPC::handleMessage<Messages::NetworkRTCProvider::SetSocketOption>(connection, decoder, this, &NetworkRTCProvider::setSocketOption);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkRTCProvider_CreateUDPSocket>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::CreateUDPSocket::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkRTCProvider_CreateClientTCPSocket>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::CreateClientTCPSocket::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkRTCProvider_CreateResolver>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::CreateResolver::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkRTCProvider_StopResolver>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::StopResolver::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkRTCProvider_GetInterfaceName>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::GetInterfaceName::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::NetworkRTCProvider_GetInterfaceName>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::GetInterfaceName::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkRTCProvider_SendToSocket>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::SendToSocket::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkRTCProvider_CloseSocket>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::CloseSocket::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::NetworkRTCProvider_SetSocketOption>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::NetworkRTCProvider::SetSocketOption::Arguments>(globalObject, decoder);
}

}

#endif


#endif // USE(LIBWEBRTC)
