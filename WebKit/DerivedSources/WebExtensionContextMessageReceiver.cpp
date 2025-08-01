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
#include "WebExtensionContext.h"

#include "ArgumentCoders.h" // NOLINT
#include "Decoder.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if ENABLE(INSPECTOR_EXTENSIONS)
#include "InspectorExtensionTypes.h" // NOLINT
#endif
#if ENABLE(INSPECTOR_EXTENSIONS)
#include "JavaScriptEvaluationResult.h" // NOLINT
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
#include "WebExtensionActionClickBehavior.h" // NOLINT
#endif
#include "WebExtensionAlarmParameters.h" // NOLINT
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
#include "WebExtensionBookmarksParameters.h" // NOLINT
#endif
#include "WebExtensionCommandParameters.h" // NOLINT
#include "WebExtensionContentWorldType.h" // NOLINT
#include "WebExtensionContextMessages.h" // NOLINT
#include "WebExtensionCookieParameters.h" // NOLINT
#include "WebExtensionDataType.h" // NOLINT
#include "WebExtensionError.h" // NOLINT
#include "WebExtensionEventListenerType.h" // NOLINT
#include "WebExtensionFrameIdentifier.h" // NOLINT
#include "WebExtensionFrameParameters.h" // NOLINT
#include "WebExtensionMatchedRuleParameters.h" // NOLINT
#include "WebExtensionMenuItemParameters.h" // NOLINT
#include "WebExtensionMessageSenderParameters.h" // NOLINT
#include "WebExtensionMessageTargetParameters.h" // NOLINT
#include "WebExtensionPortChannelIdentifier.h" // NOLINT
#include "WebExtensionRegisteredScriptParameters.h" // NOLINT
#include "WebExtensionScriptInjectionParameters.h" // NOLINT
#include "WebExtensionScriptInjectionResultParameters.h" // NOLINT
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
#include "WebExtensionSidebarParameters.h" // NOLINT
#endif
#include "WebExtensionStorageAccessLevel.h" // NOLINT
#include "WebExtensionTab.h" // NOLINT
#include "WebExtensionTabIdentifier.h" // NOLINT
#include "WebExtensionTabParameters.h" // NOLINT
#include "WebExtensionTabQueryParameters.h" // NOLINT
#include "WebExtensionWindow.h" // NOLINT
#include "WebExtensionWindowIdentifier.h" // NOLINT
#include "WebExtensionWindowParameters.h" // NOLINT
#include "WebPageProxyIdentifier.h" // NOLINT
#include <WebCore/FrameIdentifier.h> // NOLINT
#if ENABLE(INSPECTOR_EXTENSIONS)
#include <WebCore/JSDOMExceptionHandling.h> // NOLINT
#endif
#include <WebCore/PageIdentifier.h> // NOLINT
#include <optional> // NOLINT
#include <pal/SessionID.h> // NOLINT
#include <wtf/Expected.h> // NOLINT
#include <wtf/HashMap.h> // NOLINT
#include <wtf/HashSet.h> // NOLINT
#include <wtf/OptionSet.h> // NOLINT
#include <wtf/Seconds.h> // NOLINT
#include <wtf/URLHash.h> // NOLINT
#include <wtf/Vector.h> // NOLINT
#include <wtf/WallTime.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebExtensionContext::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebExtensionContext::ActionGetTitle::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionGetTitle>(connection, decoder, this, &WebExtensionContext::actionGetTitle);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionSetTitle::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionSetTitle>(connection, decoder, this, &WebExtensionContext::actionSetTitle);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionSetIcon::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionSetIcon>(connection, decoder, this, &WebExtensionContext::actionSetIcon);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionGetPopup::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionGetPopup>(connection, decoder, this, &WebExtensionContext::actionGetPopup);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionSetPopup::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionSetPopup>(connection, decoder, this, &WebExtensionContext::actionSetPopup);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionOpenPopup::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionOpenPopup>(connection, decoder, this, &WebExtensionContext::actionOpenPopup);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionGetBadgeText::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionGetBadgeText>(connection, decoder, this, &WebExtensionContext::actionGetBadgeText);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionSetBadgeText::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionSetBadgeText>(connection, decoder, this, &WebExtensionContext::actionSetBadgeText);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionGetEnabled::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionGetEnabled>(connection, decoder, this, &WebExtensionContext::actionGetEnabled);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ActionSetEnabled::name()) {
        if (!isActionMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ActionSetEnabled>(connection, decoder, this, &WebExtensionContext::actionSetEnabled);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::AlarmsCreate::name()) {
        if (!isAlarmsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionContext::AlarmsCreate>(connection, decoder, this, &WebExtensionContext::alarmsCreate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::AlarmsGet::name()) {
        if (!isAlarmsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::AlarmsGet>(connection, decoder, this, &WebExtensionContext::alarmsGet);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::AlarmsClear::name()) {
        if (!isAlarmsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::AlarmsClear>(connection, decoder, this, &WebExtensionContext::alarmsClear);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::AlarmsGetAll::name()) {
        if (!isAlarmsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::AlarmsGetAll>(connection, decoder, this, &WebExtensionContext::alarmsGetAll);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::AlarmsClearAll::name()) {
        if (!isAlarmsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::AlarmsClearAll>(connection, decoder, this, &WebExtensionContext::alarmsClearAll);
    }
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksCreate::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksCreate>(connection, decoder, this, &WebExtensionContext::bookmarksCreate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksGetTree::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksGetTree>(connection, decoder, this, &WebExtensionContext::bookmarksGetTree);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksGetSubTree::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksGetSubTree>(connection, decoder, this, &WebExtensionContext::bookmarksGetSubTree);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksGet::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksGet>(connection, decoder, this, &WebExtensionContext::bookmarksGet);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksGetChildren::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksGetChildren>(connection, decoder, this, &WebExtensionContext::bookmarksGetChildren);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksGetRecent::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksGetRecent>(connection, decoder, this, &WebExtensionContext::bookmarksGetRecent);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksSearch::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksSearch>(connection, decoder, this, &WebExtensionContext::bookmarksSearch);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksUpdate::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksUpdate>(connection, decoder, this, &WebExtensionContext::bookmarksUpdate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksMove::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksMove>(connection, decoder, this, &WebExtensionContext::bookmarksMove);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksRemove::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksRemove>(connection, decoder, this, &WebExtensionContext::bookmarksRemove);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::BookmarksRemoveTree::name()) {
        if (!isBookmarksMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::BookmarksRemoveTree>(connection, decoder, this, &WebExtensionContext::bookmarksRemoveTree);
    }
#endif
    if (decoder.messageName() == Messages::WebExtensionContext::CommandsGetAll::name()) {
        if (!isCommandsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::CommandsGetAll>(connection, decoder, this, &WebExtensionContext::commandsGetAll);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::CookiesGet::name()) {
        if (!isCookiesMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::CookiesGet>(connection, decoder, this, &WebExtensionContext::cookiesGet);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::CookiesGetAll::name()) {
        if (!isCookiesMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::CookiesGetAll>(connection, decoder, this, &WebExtensionContext::cookiesGetAll);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::CookiesSet::name()) {
        if (!isCookiesMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::CookiesSet>(connection, decoder, this, &WebExtensionContext::cookiesSet);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::CookiesRemove::name()) {
        if (!isCookiesMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::CookiesRemove>(connection, decoder, this, &WebExtensionContext::cookiesRemove);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::CookiesGetAllCookieStores::name()) {
        if (!isCookiesMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::CookiesGetAllCookieStores>(connection, decoder, this, &WebExtensionContext::cookiesGetAllCookieStores);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestGetEnabledRulesets::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestGetEnabledRulesets>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestGetEnabledRulesets);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestUpdateEnabledRulesets::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestUpdateEnabledRulesets>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestUpdateEnabledRulesets);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestDisplayActionCountAsBadgeText::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestDisplayActionCountAsBadgeText>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestDisplayActionCountAsBadgeText);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestIncrementActionCount::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestIncrementActionCount>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestIncrementActionCount);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestGetMatchedRules::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestGetMatchedRules>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestGetMatchedRules);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestGetDynamicRules::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestGetDynamicRules>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestGetDynamicRules);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestUpdateDynamicRules::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestUpdateDynamicRules>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestUpdateDynamicRules);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestGetSessionRules::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestGetSessionRules>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestGetSessionRules);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DeclarativeNetRequestUpdateSessionRules::name()) {
        if (!isDeclarativeNetRequestMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DeclarativeNetRequestUpdateSessionRules>(connection, decoder, this, &WebExtensionContext::declarativeNetRequestUpdateSessionRules);
    }
#if ENABLE(INSPECTOR_EXTENSIONS)
    if (decoder.messageName() == Messages::WebExtensionContext::DevToolsPanelsCreate::name()) {
        if (!isDevToolsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DevToolsPanelsCreate>(connection, decoder, this, &WebExtensionContext::devToolsPanelsCreate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DevToolsInspectedWindowEval::name()) {
        if (!isDevToolsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::DevToolsInspectedWindowEval>(connection, decoder, this, &WebExtensionContext::devToolsInspectedWindowEval);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::DevToolsInspectedWindowReload::name()) {
        if (!isDevToolsMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionContext::DevToolsInspectedWindowReload>(connection, decoder, this, &WebExtensionContext::devToolsInspectedWindowReload);
    }
#endif
    if (decoder.messageName() == Messages::WebExtensionContext::AddListener::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionContext::AddListener>(connection, decoder, this, &WebExtensionContext::addListener);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RemoveListener::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionContext::RemoveListener>(connection, decoder, this, &WebExtensionContext::removeListener);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ExtensionIsAllowedIncognitoAccess::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ExtensionIsAllowedIncognitoAccess>(connection, decoder, this, &WebExtensionContext::extensionIsAllowedIncognitoAccess);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::MenusCreate::name()) {
        if (!isMenusMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::MenusCreate>(connection, decoder, this, &WebExtensionContext::menusCreate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::MenusUpdate::name()) {
        if (!isMenusMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::MenusUpdate>(connection, decoder, this, &WebExtensionContext::menusUpdate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::MenusRemove::name()) {
        if (!isMenusMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::MenusRemove>(connection, decoder, this, &WebExtensionContext::menusRemove);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::MenusRemoveAll::name()) {
        if (!isMenusMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::MenusRemoveAll>(connection, decoder, this, &WebExtensionContext::menusRemoveAll);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::PermissionsGetAll::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::PermissionsGetAll>(connection, decoder, this, &WebExtensionContext::permissionsGetAll);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::PermissionsContains::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::PermissionsContains>(connection, decoder, this, &WebExtensionContext::permissionsContains);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::PermissionsRequest::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::PermissionsRequest>(connection, decoder, this, &WebExtensionContext::permissionsRequest);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::PermissionsRemove::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::PermissionsRemove>(connection, decoder, this, &WebExtensionContext::permissionsRemove);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::PortPostMessage::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionContext::PortPostMessage>(connection, decoder, this, &WebExtensionContext::portPostMessage);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::PortRemoved::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionContext::PortRemoved>(connection, decoder, this, &WebExtensionContext::portRemoved);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeGetBackgroundPage::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::RuntimeGetBackgroundPage>(connection, decoder, this, &WebExtensionContext::runtimeGetBackgroundPage);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeOpenOptionsPage::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::RuntimeOpenOptionsPage>(connection, decoder, this, &WebExtensionContext::runtimeOpenOptionsPage);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeReload::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebExtensionContext::RuntimeReload>(connection, decoder, this, &WebExtensionContext::runtimeReload);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeSendMessage::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::RuntimeSendMessage>(connection, decoder, this, &WebExtensionContext::runtimeSendMessage);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeConnect::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::RuntimeConnect>(connection, decoder, this, &WebExtensionContext::runtimeConnect);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeSendNativeMessage::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::RuntimeSendNativeMessage>(connection, decoder, this, &WebExtensionContext::runtimeSendNativeMessage);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeConnectNative::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::RuntimeConnectNative>(connection, decoder, this, &WebExtensionContext::runtimeConnectNative);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeWebPageSendMessage::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::RuntimeWebPageSendMessage>(connection, decoder, this, &WebExtensionContext::runtimeWebPageSendMessage);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::RuntimeWebPageConnect::name()) {
        if (!isLoaded(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::RuntimeWebPageConnect>(connection, decoder, this, &WebExtensionContext::runtimeWebPageConnect);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ScriptingExecuteScript::name()) {
        if (!isScriptingMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ScriptingExecuteScript>(connection, decoder, this, &WebExtensionContext::scriptingExecuteScript);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ScriptingInsertCSS::name()) {
        if (!isScriptingMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ScriptingInsertCSS>(connection, decoder, this, &WebExtensionContext::scriptingInsertCSS);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ScriptingRemoveCSS::name()) {
        if (!isScriptingMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ScriptingRemoveCSS>(connection, decoder, this, &WebExtensionContext::scriptingRemoveCSS);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ScriptingRegisterContentScripts::name()) {
        if (!isScriptingMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ScriptingRegisterContentScripts>(connection, decoder, this, &WebExtensionContext::scriptingRegisterContentScripts);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ScriptingUpdateRegisteredScripts::name()) {
        if (!isScriptingMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ScriptingUpdateRegisteredScripts>(connection, decoder, this, &WebExtensionContext::scriptingUpdateRegisteredScripts);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ScriptingGetRegisteredScripts::name()) {
        if (!isScriptingMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ScriptingGetRegisteredScripts>(connection, decoder, this, &WebExtensionContext::scriptingGetRegisteredScripts);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::ScriptingUnregisterContentScripts::name()) {
        if (!isScriptingMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::ScriptingUnregisterContentScripts>(connection, decoder, this, &WebExtensionContext::scriptingUnregisterContentScripts);
    }
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarOpen::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarOpen>(connection, decoder, this, &WebExtensionContext::sidebarOpen);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarIsOpen::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarIsOpen>(connection, decoder, this, &WebExtensionContext::sidebarIsOpen);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarClose::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarClose>(connection, decoder, this, &WebExtensionContext::sidebarClose);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarToggle::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarToggle>(connection, decoder, this, &WebExtensionContext::sidebarToggle);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarGetOptions::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarGetOptions>(connection, decoder, this, &WebExtensionContext::sidebarGetOptions);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarSetOptions::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarSetOptions>(connection, decoder, this, &WebExtensionContext::sidebarSetOptions);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarGetTitle::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarGetTitle>(connection, decoder, this, &WebExtensionContext::sidebarGetTitle);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarSetTitle::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarSetTitle>(connection, decoder, this, &WebExtensionContext::sidebarSetTitle);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarSetIcon::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarSetIcon>(connection, decoder, this, &WebExtensionContext::sidebarSetIcon);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarSetActionClickBehavior::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarSetActionClickBehavior>(connection, decoder, this, &WebExtensionContext::sidebarSetActionClickBehavior);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::SidebarGetActionClickBehavior::name()) {
        if (!isSidebarMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::SidebarGetActionClickBehavior>(connection, decoder, this, &WebExtensionContext::sidebarGetActionClickBehavior);
    }
#endif
    if (decoder.messageName() == Messages::WebExtensionContext::StorageGet::name()) {
        if (!isStorageMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::StorageGet>(connection, decoder, this, &WebExtensionContext::storageGet);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::StorageGetKeys::name()) {
        if (!isStorageMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::StorageGetKeys>(connection, decoder, this, &WebExtensionContext::storageGetKeys);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::StorageGetBytesInUse::name()) {
        if (!isStorageMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::StorageGetBytesInUse>(connection, decoder, this, &WebExtensionContext::storageGetBytesInUse);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::StorageSet::name()) {
        if (!isStorageMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::StorageSet>(connection, decoder, this, &WebExtensionContext::storageSet);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::StorageRemove::name()) {
        if (!isStorageMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::StorageRemove>(connection, decoder, this, &WebExtensionContext::storageRemove);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::StorageClear::name()) {
        if (!isStorageMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::StorageClear>(connection, decoder, this, &WebExtensionContext::storageClear);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::StorageSetAccessLevel::name()) {
        if (!isStorageMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::StorageSetAccessLevel>(connection, decoder, this, &WebExtensionContext::storageSetAccessLevel);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsCreate::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsCreate>(connection, decoder, this, &WebExtensionContext::tabsCreate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsUpdate::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsUpdate>(connection, decoder, this, &WebExtensionContext::tabsUpdate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsDuplicate::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsDuplicate>(connection, decoder, this, &WebExtensionContext::tabsDuplicate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsGet::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsGet>(connection, decoder, this, &WebExtensionContext::tabsGet);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsGetCurrent::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsGetCurrent>(connection, decoder, this, &WebExtensionContext::tabsGetCurrent);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsQuery::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsQuery>(connection, decoder, this, &WebExtensionContext::tabsQuery);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsReload::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsReload>(connection, decoder, this, &WebExtensionContext::tabsReload);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsGoBack::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsGoBack>(connection, decoder, this, &WebExtensionContext::tabsGoBack);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsGoForward::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsGoForward>(connection, decoder, this, &WebExtensionContext::tabsGoForward);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsDetectLanguage::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsDetectLanguage>(connection, decoder, this, &WebExtensionContext::tabsDetectLanguage);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsToggleReaderMode::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsToggleReaderMode>(connection, decoder, this, &WebExtensionContext::tabsToggleReaderMode);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsCaptureVisibleTab::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsCaptureVisibleTab>(connection, decoder, this, &WebExtensionContext::tabsCaptureVisibleTab);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsSendMessage::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsSendMessage>(connection, decoder, this, &WebExtensionContext::tabsSendMessage);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsConnect::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsConnect>(connection, decoder, this, &WebExtensionContext::tabsConnect);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsGetZoom::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsGetZoom>(connection, decoder, this, &WebExtensionContext::tabsGetZoom);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsSetZoom::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsSetZoom>(connection, decoder, this, &WebExtensionContext::tabsSetZoom);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsRemove::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsRemove>(connection, decoder, this, &WebExtensionContext::tabsRemove);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsExecuteScript::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsExecuteScript>(connection, decoder, this, &WebExtensionContext::tabsExecuteScript);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsInsertCSS::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsInsertCSS>(connection, decoder, this, &WebExtensionContext::tabsInsertCSS);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::TabsRemoveCSS::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::TabsRemoveCSS>(connection, decoder, this, &WebExtensionContext::tabsRemoveCSS);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::WebNavigationGetAllFrames::name()) {
        if (!isWebNavigationMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::WebNavigationGetAllFrames>(connection, decoder, this, &WebExtensionContext::webNavigationGetAllFrames);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::WebNavigationGetFrame::name()) {
        if (!isWebNavigationMessageAllowed(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::WebNavigationGetFrame>(connection, decoder, this, &WebExtensionContext::webNavigationGetFrame);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::WindowsCreate::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::WindowsCreate>(connection, decoder, this, &WebExtensionContext::windowsCreate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::WindowsGet::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::WindowsGet>(connection, decoder, this, &WebExtensionContext::windowsGet);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::WindowsGetLastFocused::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::WindowsGetLastFocused>(connection, decoder, this, &WebExtensionContext::windowsGetLastFocused);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::WindowsGetAll::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::WindowsGetAll>(connection, decoder, this, &WebExtensionContext::windowsGetAll);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::WindowsUpdate::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::WindowsUpdate>(connection, decoder, this, &WebExtensionContext::windowsUpdate);
    }
    if (decoder.messageName() == Messages::WebExtensionContext::WindowsRemove::name()) {
        if (!isLoadedAndPrivilegedMessage(decoder)) {
            RELEASE_LOG_ERROR(IPC, "Message %s fails validation", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebExtensionContext::WindowsRemove>(connection, decoder, this, &WebExtensionContext::windowsRemove);
    }
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionGetTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionGetTitle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionGetTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionGetTitle::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionSetTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetTitle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionSetTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetTitle::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionSetIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetIcon::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionSetIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetIcon::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionGetPopup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionGetPopup::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionGetPopup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionGetPopup::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionSetPopup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetPopup::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionSetPopup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetPopup::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionOpenPopup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionOpenPopup::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionOpenPopup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionOpenPopup::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionGetBadgeText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionGetBadgeText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionGetBadgeText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionGetBadgeText::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionSetBadgeText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetBadgeText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionSetBadgeText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetBadgeText::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionGetEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionGetEnabled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionGetEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionGetEnabled::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ActionSetEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetEnabled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ActionSetEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ActionSetEnabled::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_AlarmsCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsCreate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_AlarmsGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsGet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_AlarmsGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsGet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_AlarmsClear>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsClear::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_AlarmsClear>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsClear::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_AlarmsGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsGetAll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_AlarmsGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsGetAll::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_AlarmsClearAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsClearAll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_AlarmsClearAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AlarmsClearAll::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksCreate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksCreate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksGetTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGetTree::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksGetTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGetTree::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksGetSubTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGetSubTree::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksGetSubTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGetSubTree::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksGetChildren>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGetChildren::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksGetChildren>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGetChildren::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksGetRecent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGetRecent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksGetRecent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksGetRecent::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksSearch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksSearch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksSearch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksSearch::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksUpdate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksMove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksMove::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksMove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksMove::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksRemove::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksRemove::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_BookmarksRemoveTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksRemoveTree::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_BookmarksRemoveTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::BookmarksRemoveTree::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_CommandsGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CommandsGetAll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_CommandsGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CommandsGetAll::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_CookiesGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesGet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_CookiesGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesGet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_CookiesGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesGetAll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_CookiesGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesGetAll::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_CookiesSet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesSet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_CookiesSet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesSet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_CookiesRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesRemove::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_CookiesRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesRemove::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_CookiesGetAllCookieStores>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesGetAllCookieStores::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_CookiesGetAllCookieStores>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::CookiesGetAllCookieStores::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestGetEnabledRulesets>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestGetEnabledRulesets::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestGetEnabledRulesets>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestGetEnabledRulesets::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestUpdateEnabledRulesets>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestUpdateEnabledRulesets::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestUpdateEnabledRulesets>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestUpdateEnabledRulesets::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestDisplayActionCountAsBadgeText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestDisplayActionCountAsBadgeText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestDisplayActionCountAsBadgeText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestDisplayActionCountAsBadgeText::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestIncrementActionCount>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestIncrementActionCount::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestIncrementActionCount>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestIncrementActionCount::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestGetMatchedRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestGetMatchedRules::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestGetMatchedRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestGetMatchedRules::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestGetDynamicRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestGetDynamicRules::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestGetDynamicRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestGetDynamicRules::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestUpdateDynamicRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestUpdateDynamicRules::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestUpdateDynamicRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestUpdateDynamicRules::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestGetSessionRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestGetSessionRules::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestGetSessionRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestGetSessionRules::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DeclarativeNetRequestUpdateSessionRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestUpdateSessionRules::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DeclarativeNetRequestUpdateSessionRules>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DeclarativeNetRequestUpdateSessionRules::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(INSPECTOR_EXTENSIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DevToolsPanelsCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DevToolsPanelsCreate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DevToolsPanelsCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DevToolsPanelsCreate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DevToolsInspectedWindowEval>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DevToolsInspectedWindowEval::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_DevToolsInspectedWindowEval>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DevToolsInspectedWindowEval::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_DevToolsInspectedWindowReload>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::DevToolsInspectedWindowReload::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_AddListener>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::AddListener::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RemoveListener>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RemoveListener::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ExtensionIsAllowedIncognitoAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ExtensionIsAllowedIncognitoAccess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ExtensionIsAllowedIncognitoAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ExtensionIsAllowedIncognitoAccess::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_MenusCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::MenusCreate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_MenusCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::MenusCreate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_MenusUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::MenusUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_MenusUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::MenusUpdate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_MenusRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::MenusRemove::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_MenusRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::MenusRemove::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_MenusRemoveAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::MenusRemoveAll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_MenusRemoveAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::MenusRemoveAll::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_PermissionsGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PermissionsGetAll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_PermissionsGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PermissionsGetAll::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_PermissionsContains>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PermissionsContains::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_PermissionsContains>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PermissionsContains::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_PermissionsRequest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PermissionsRequest::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_PermissionsRequest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PermissionsRequest::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_PermissionsRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PermissionsRemove::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_PermissionsRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PermissionsRemove::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_PortPostMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PortPostMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_PortRemoved>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::PortRemoved::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeGetBackgroundPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeGetBackgroundPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_RuntimeGetBackgroundPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeGetBackgroundPage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeOpenOptionsPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeOpenOptionsPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_RuntimeOpenOptionsPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeOpenOptionsPage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeReload>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeReload::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeSendMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeSendMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_RuntimeSendMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeSendMessage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeConnect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeConnect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_RuntimeConnect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeConnect::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeSendNativeMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeSendNativeMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_RuntimeSendNativeMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeSendNativeMessage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeConnectNative>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeConnectNative::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_RuntimeConnectNative>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeConnectNative::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeWebPageSendMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeWebPageSendMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_RuntimeWebPageSendMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeWebPageSendMessage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_RuntimeWebPageConnect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeWebPageConnect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_RuntimeWebPageConnect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::RuntimeWebPageConnect::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ScriptingExecuteScript>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingExecuteScript::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ScriptingExecuteScript>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingExecuteScript::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ScriptingInsertCSS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingInsertCSS::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ScriptingInsertCSS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingInsertCSS::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ScriptingRemoveCSS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingRemoveCSS::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ScriptingRemoveCSS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingRemoveCSS::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ScriptingRegisterContentScripts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingRegisterContentScripts::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ScriptingRegisterContentScripts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingRegisterContentScripts::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ScriptingUpdateRegisteredScripts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingUpdateRegisteredScripts::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ScriptingUpdateRegisteredScripts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingUpdateRegisteredScripts::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ScriptingGetRegisteredScripts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingGetRegisteredScripts::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ScriptingGetRegisteredScripts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingGetRegisteredScripts::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_ScriptingUnregisterContentScripts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingUnregisterContentScripts::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_ScriptingUnregisterContentScripts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::ScriptingUnregisterContentScripts::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarOpen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarOpen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarOpen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarOpen::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarIsOpen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarIsOpen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarIsOpen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarIsOpen::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarClose>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarClose::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarClose>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarClose::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarToggle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarToggle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarToggle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarToggle::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarGetOptions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarGetOptions::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarGetOptions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarGetOptions::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarSetOptions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarSetOptions::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarSetOptions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarSetOptions::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarGetTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarGetTitle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarGetTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarGetTitle::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarSetTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarSetTitle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarSetTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarSetTitle::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarSetIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarSetIcon::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarSetIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarSetIcon::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarSetActionClickBehavior>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarSetActionClickBehavior::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarSetActionClickBehavior>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarSetActionClickBehavior::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_SidebarGetActionClickBehavior>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarGetActionClickBehavior::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_SidebarGetActionClickBehavior>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::SidebarGetActionClickBehavior::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_StorageGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageGet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_StorageGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageGet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_StorageGetKeys>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageGetKeys::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_StorageGetKeys>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageGetKeys::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_StorageGetBytesInUse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageGetBytesInUse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_StorageGetBytesInUse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageGetBytesInUse::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_StorageSet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageSet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_StorageSet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageSet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_StorageRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageRemove::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_StorageRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageRemove::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_StorageClear>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageClear::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_StorageClear>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageClear::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_StorageSetAccessLevel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageSetAccessLevel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_StorageSetAccessLevel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::StorageSetAccessLevel::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsCreate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsCreate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsUpdate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsDuplicate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsDuplicate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsDuplicate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsDuplicate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsGetCurrent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGetCurrent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsGetCurrent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGetCurrent::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsQuery>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsQuery::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsQuery>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsQuery::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsReload>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsReload::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsReload>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsReload::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsGoBack>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGoBack::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsGoBack>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGoBack::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsGoForward>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGoForward::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsGoForward>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGoForward::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsDetectLanguage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsDetectLanguage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsDetectLanguage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsDetectLanguage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsToggleReaderMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsToggleReaderMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsToggleReaderMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsToggleReaderMode::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsCaptureVisibleTab>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsCaptureVisibleTab::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsCaptureVisibleTab>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsCaptureVisibleTab::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsSendMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsSendMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsSendMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsSendMessage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsConnect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsConnect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsConnect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsConnect::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsGetZoom>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGetZoom::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsGetZoom>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsGetZoom::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsSetZoom>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsSetZoom::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsSetZoom>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsSetZoom::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsRemove::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsRemove::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsExecuteScript>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsExecuteScript::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsExecuteScript>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsExecuteScript::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsInsertCSS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsInsertCSS::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsInsertCSS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsInsertCSS::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_TabsRemoveCSS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsRemoveCSS::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_TabsRemoveCSS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::TabsRemoveCSS::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_WebNavigationGetAllFrames>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WebNavigationGetAllFrames::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_WebNavigationGetAllFrames>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WebNavigationGetAllFrames::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_WebNavigationGetFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WebNavigationGetFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_WebNavigationGetFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WebNavigationGetFrame::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_WindowsCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsCreate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_WindowsCreate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsCreate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_WindowsGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsGet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_WindowsGet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsGet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_WindowsGetLastFocused>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsGetLastFocused::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_WindowsGetLastFocused>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsGetLastFocused::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_WindowsGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsGetAll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_WindowsGetAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsGetAll::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_WindowsUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_WindowsUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsUpdate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebExtensionContext_WindowsRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsRemove::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebExtensionContext_WindowsRemove>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebExtensionContext::WindowsRemove::ReplyArguments>(globalObject, decoder);
}

}

#endif


#endif // ENABLE(WK_WEB_EXTENSIONS)
