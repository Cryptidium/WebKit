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
#if ENABLE(GPU_PROCESS)
#include "RemoteTexture.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "RemoteTextureMessages.h" // NOLINT
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "WebGPUIdentifier.h" // NOLINT
#include "WebGPUTextureViewDescriptor.h" // NOLINT
#include <optional> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void RemoteTexture::didReceiveStreamMessage(IPC::StreamServerConnection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess();
    UNUSED_VARIABLE(sharedPreferences);
    if (!sharedPreferences || !sharedPreferences->webGPUEnabled) {
        RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message receiver RemoteTexture", IPC::description(decoder.messageName()).characters());
        decoder.markInvalid();
        return;
    }
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::RemoteTexture::CreateView::name())
        return IPC::handleMessage<Messages::RemoteTexture::CreateView>(connection, decoder, this, &RemoteTexture::createView);
    if (decoder.messageName() == Messages::RemoteTexture::Destroy::name())
        return IPC::handleMessage<Messages::RemoteTexture::Destroy>(connection, decoder, this, &RemoteTexture::destroy);
    if (decoder.messageName() == Messages::RemoteTexture::Undestroy::name())
        return IPC::handleMessage<Messages::RemoteTexture::Undestroy>(connection, decoder, this, &RemoteTexture::undestroy);
    if (decoder.messageName() == Messages::RemoteTexture::Destruct::name())
        return IPC::handleMessage<Messages::RemoteTexture::Destruct>(connection, decoder, this, &RemoteTexture::destruct);
    if (decoder.messageName() == Messages::RemoteTexture::SetLabel::name())
        return IPC::handleMessage<Messages::RemoteTexture::SetLabel>(connection, decoder, this, &RemoteTexture::setLabel);
    RELEASE_LOG_ERROR(IPC, "Unhandled stream message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteTexture_CreateView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteTexture::CreateView::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteTexture_Destroy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteTexture::Destroy::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteTexture_Undestroy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteTexture::Undestroy::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteTexture_Destruct>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteTexture::Destruct::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::RemoteTexture_SetLabel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::RemoteTexture::SetLabel::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(GPU_PROCESS)
