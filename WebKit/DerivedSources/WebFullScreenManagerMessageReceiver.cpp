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
#if ENABLE(FULLSCREEN_API)
#include "WebFullScreenManager.h"

#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "PageClient.h" // NOLINT
#include "WebFullScreenManagerMessages.h" // NOLINT
#include <WebCore/FrameIdentifier.h> // NOLINT
#include <wtf/Seconds.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebFullScreenManager::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebFullScreenManager::RequestRestoreFullScreen::name())
        return IPC::handleMessageAsync<Messages::WebFullScreenManager::RequestRestoreFullScreen>(connection, decoder, this, &WebFullScreenManager::requestRestoreFullScreen);
    if (decoder.messageName() == Messages::WebFullScreenManager::RequestExitFullScreen::name())
        return IPC::handleMessage<Messages::WebFullScreenManager::RequestExitFullScreen>(connection, decoder, this, &WebFullScreenManager::requestExitFullScreen);
    if (decoder.messageName() == Messages::WebFullScreenManager::SetAnimatingFullScreen::name())
        return IPC::handleMessage<Messages::WebFullScreenManager::SetAnimatingFullScreen>(connection, decoder, this, &WebFullScreenManager::setAnimatingFullScreen);
    if (decoder.messageName() == Messages::WebFullScreenManager::SetFullscreenInsets::name())
        return IPC::handleMessage<Messages::WebFullScreenManager::SetFullscreenInsets>(connection, decoder, this, &WebFullScreenManager::setFullscreenInsets);
    if (decoder.messageName() == Messages::WebFullScreenManager::SetFullscreenAutoHideDuration::name())
        return IPC::handleMessage<Messages::WebFullScreenManager::SetFullscreenAutoHideDuration>(connection, decoder, this, &WebFullScreenManager::setFullscreenAutoHideDuration);
    if (decoder.messageName() == Messages::WebFullScreenManager::EnterFullScreenForOwnerElements::name())
        return IPC::handleMessageAsync<Messages::WebFullScreenManager::EnterFullScreenForOwnerElements>(connection, decoder, this, &WebFullScreenManager::enterFullScreenForOwnerElements);
    if (decoder.messageName() == Messages::WebFullScreenManager::ExitFullScreenInMainFrame::name())
        return IPC::handleMessageAsync<Messages::WebFullScreenManager::ExitFullScreenInMainFrame>(connection, decoder, this, &WebFullScreenManager::exitFullScreenInMainFrame);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFullScreenManager_RequestRestoreFullScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::RequestRestoreFullScreen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebFullScreenManager_RequestRestoreFullScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::RequestRestoreFullScreen::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFullScreenManager_RequestExitFullScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::RequestExitFullScreen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFullScreenManager_SetAnimatingFullScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::SetAnimatingFullScreen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFullScreenManager_SetFullscreenInsets>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::SetFullscreenInsets::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFullScreenManager_SetFullscreenAutoHideDuration>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::SetFullscreenAutoHideDuration::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFullScreenManager_EnterFullScreenForOwnerElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::EnterFullScreenForOwnerElements::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebFullScreenManager_EnterFullScreenForOwnerElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::EnterFullScreenForOwnerElements::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebFullScreenManager_ExitFullScreenInMainFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::ExitFullScreenInMainFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebFullScreenManager_ExitFullScreenInMainFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebFullScreenManager::ExitFullScreenInMainFrame::ReplyArguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(FULLSCREEN_API)
