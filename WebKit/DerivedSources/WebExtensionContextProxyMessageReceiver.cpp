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
#if ENABLE(WK_WEB_EXTENSIONS)
#include "WebExtensionContextProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "FormDataReference.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if ENABLE(INSPECTOR_EXTENSIONS)
#include "InspectorExtensionTypes.h" // NOLINT
#endif
#include "ResourceLoadInfo.h" // NOLINT
#include "WebExtensionAlarmParameters.h" // NOLINT
#include "WebExtensionContentWorldType.h" // NOLINT
#include "WebExtensionContext.h" // NOLINT
#include "WebExtensionContextProxyMessages.h" // NOLINT
#include "WebExtensionDataType.h" // NOLINT
#include "WebExtensionEventListenerType.h" // NOLINT
#include "WebExtensionFrameParameters.h" // NOLINT
#include "WebExtensionMenuItemContextParameters.h" // NOLINT
#include "WebExtensionMenuItemParameters.h" // NOLINT
#include "WebExtensionMessageSenderParameters.h" // NOLINT
#include "WebExtensionMessageTargetParameters.h" // NOLINT
#include "WebExtensionPortChannelIdentifier.h" // NOLINT
#include "WebExtensionTabIdentifier.h" // NOLINT
#include "WebExtensionTabParameters.h" // NOLINT
#include "WebExtensionWindowIdentifier.h" // NOLINT
#include "WebExtensionWindowParameters.h" // NOLINT
#include "WebPageProxyIdentifier.h" // NOLINT
#include <WebCore/AuthenticationChallenge.h> // NOLINT
#if ENABLE(INSPECTOR_EXTENSIONS)
#include <WebCore/FrameIdentifier.h> // NOLINT
#endif
#include <WebCore/PageIdentifier.h> // NOLINT
#include <WebCore/ResourceError.h> // NOLINT
#include <WebCore/ResourceRequest.h> // NOLINT
#include <WebCore/ResourceResponse.h> // NOLINT
#include <optional> // NOLINT
#include <wtf/HashCountedSet.h> // NOLINT
#include <wtf/HashMap.h> // NOLINT
#include <wtf/HashSet.h> // NOLINT
#if ENABLE(INSPECTOR_EXTENSIONS)
#include <wtf/URLHash.h> // NOLINT
#endif
#include <wtf/Vector.h> // NOLINT
#include <wtf/WallTime.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebExtensionContextProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchActionClickedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchActionClickedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchActionClickedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchAlarmsEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchAlarmsEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchAlarmsEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchCommandsCommandEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchCommandsCommandEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchCommandsCommandEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchCommandsChangedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchCommandsChangedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchCommandsChangedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchCookiesChangedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchCookiesChangedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchCookiesChangedEvent);
#if ENABLE(INSPECTOR_EXTENSIONS)
    if (decoder.messageName() == Messages::WebExtensionContextProxy::AddInspectorPageIdentifier::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::AddInspectorPageIdentifier>(connection, decoder, this, &WebExtensionContextProxy::addInspectorPageIdentifier);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::AddInspectorBackgroundPageIdentifier::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::AddInspectorBackgroundPageIdentifier>(connection, decoder, this, &WebExtensionContextProxy::addInspectorBackgroundPageIdentifier);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchDevToolsExtensionPanelShownEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchDevToolsExtensionPanelShownEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchDevToolsExtensionPanelShownEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchDevToolsExtensionPanelHiddenEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchDevToolsExtensionPanelHiddenEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchDevToolsExtensionPanelHiddenEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchDevToolsNetworkNavigatedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchDevToolsNetworkNavigatedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchDevToolsNetworkNavigatedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchDevToolsPanelsThemeChangedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchDevToolsPanelsThemeChangedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchDevToolsPanelsThemeChangedEvent);
#endif
    if (decoder.messageName() == Messages::WebExtensionContextProxy::SetBackgroundPageIdentifier::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::SetBackgroundPageIdentifier>(connection, decoder, this, &WebExtensionContextProxy::setBackgroundPageIdentifier);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::AddPopupPageIdentifier::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::AddPopupPageIdentifier>(connection, decoder, this, &WebExtensionContextProxy::addPopupPageIdentifier);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::AddTabPageIdentifier::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::AddTabPageIdentifier>(connection, decoder, this, &WebExtensionContextProxy::addTabPageIdentifier);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchMenusClickedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchMenusClickedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchMenusClickedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::UpdateGrantedPermissions::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::UpdateGrantedPermissions>(connection, decoder, this, &WebExtensionContextProxy::updateGrantedPermissions);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchPermissionsEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchPermissionsEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchPermissionsEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchPortMessageEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchPortMessageEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchPortMessageEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchPortDisconnectEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchPortDisconnectEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchPortDisconnectEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchRuntimeMessageEvent::name())
        return IPC::handleMessageAsync<Messages::WebExtensionContextProxy::DispatchRuntimeMessageEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchRuntimeMessageEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchRuntimeConnectEvent::name())
        return IPC::handleMessageAsync<Messages::WebExtensionContextProxy::DispatchRuntimeConnectEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchRuntimeConnectEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchRuntimeInstalledEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchRuntimeInstalledEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchRuntimeInstalledEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchRuntimeStartupEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchRuntimeStartupEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchRuntimeStartupEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::SetStorageAccessLevel::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::SetStorageAccessLevel>(connection, decoder, this, &WebExtensionContextProxy::setStorageAccessLevel);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchStorageChangedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchStorageChangedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchStorageChangedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsCreatedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsCreatedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsCreatedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsUpdatedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsUpdatedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsUpdatedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsReplacedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsReplacedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsReplacedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsDetachedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsDetachedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsDetachedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsMovedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsMovedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsMovedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsAttachedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsAttachedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsAttachedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsActivatedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsActivatedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsActivatedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsHighlightedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsHighlightedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsHighlightedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTabsRemovedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTabsRemovedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTabsRemovedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTestMessageEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTestMessageEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTestMessageEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTestStartedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTestStartedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTestStartedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchTestFinishedEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchTestFinishedEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchTestFinishedEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchWebNavigationEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchWebNavigationEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchWebNavigationEvent);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::ResourceLoadDidSendRequest::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::ResourceLoadDidSendRequest>(connection, decoder, this, &WebExtensionContextProxy::resourceLoadDidSendRequest);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::ResourceLoadDidPerformHTTPRedirection::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::ResourceLoadDidPerformHTTPRedirection>(connection, decoder, this, &WebExtensionContextProxy::resourceLoadDidPerformHTTPRedirection);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::ResourceLoadDidReceiveChallenge::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::ResourceLoadDidReceiveChallenge>(connection, decoder, this, &WebExtensionContextProxy::resourceLoadDidReceiveChallenge);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::ResourceLoadDidReceiveResponse::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::ResourceLoadDidReceiveResponse>(connection, decoder, this, &WebExtensionContextProxy::resourceLoadDidReceiveResponse);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::ResourceLoadDidCompleteWithError::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::ResourceLoadDidCompleteWithError>(connection, decoder, this, &WebExtensionContextProxy::resourceLoadDidCompleteWithError);
    if (decoder.messageName() == Messages::WebExtensionContextProxy::DispatchWindowsEvent::name())
        return IPC::handleMessage<Messages::WebExtensionContextProxy::DispatchWindowsEvent>(connection, decoder, this, &WebExtensionContextProxy::dispatchWindowsEvent);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchActionClickedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchActionClickedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchAlarmsEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchAlarmsEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchCommandsCommandEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchCommandsCommandEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchCommandsChangedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchCommandsChangedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchCookiesChangedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchCookiesChangedEvent::Arguments>(globalObject, decoder);
}
#if ENABLE(INSPECTOR_EXTENSIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_AddInspectorPageIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::AddInspectorPageIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_AddInspectorBackgroundPageIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::AddInspectorBackgroundPageIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchDevToolsExtensionPanelShownEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchDevToolsExtensionPanelShownEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchDevToolsExtensionPanelHiddenEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchDevToolsExtensionPanelHiddenEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchDevToolsNetworkNavigatedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchDevToolsNetworkNavigatedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchDevToolsPanelsThemeChangedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchDevToolsPanelsThemeChangedEvent::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_SetBackgroundPageIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::SetBackgroundPageIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_AddPopupPageIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::AddPopupPageIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_AddTabPageIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::AddTabPageIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchMenusClickedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchMenusClickedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_UpdateGrantedPermissions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::UpdateGrantedPermissions::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchPermissionsEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchPermissionsEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchPortMessageEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchPortMessageEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchPortDisconnectEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchPortDisconnectEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchRuntimeMessageEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchRuntimeMessageEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContextProxy_DispatchRuntimeMessageEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchRuntimeMessageEvent::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchRuntimeConnectEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchRuntimeConnectEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContextProxy_DispatchRuntimeConnectEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchRuntimeConnectEvent::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchRuntimeInstalledEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchRuntimeInstalledEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchRuntimeStartupEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchRuntimeStartupEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_SetStorageAccessLevel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::SetStorageAccessLevel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchStorageChangedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchStorageChangedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsCreatedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsCreatedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsUpdatedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsUpdatedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsReplacedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsReplacedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsDetachedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsDetachedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsMovedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsMovedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsAttachedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsAttachedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsActivatedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsActivatedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsHighlightedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsHighlightedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTabsRemovedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTabsRemovedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTestMessageEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTestMessageEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTestStartedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTestStartedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchTestFinishedEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchTestFinishedEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchWebNavigationEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchWebNavigationEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_ResourceLoadDidSendRequest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::ResourceLoadDidSendRequest::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_ResourceLoadDidPerformHTTPRedirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::ResourceLoadDidPerformHTTPRedirection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_ResourceLoadDidReceiveChallenge>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::ResourceLoadDidReceiveChallenge::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_ResourceLoadDidReceiveResponse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::ResourceLoadDidReceiveResponse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_ResourceLoadDidCompleteWithError>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::ResourceLoadDidCompleteWithError::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContextProxy_DispatchWindowsEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContextProxy::DispatchWindowsEvent::Arguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(WK_WEB_EXTENSIONS)
