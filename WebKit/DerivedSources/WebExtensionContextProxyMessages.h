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

#pragma once

#if ENABLE(WK_WEB_EXTENSIONS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "InspectorExtensionTypes.h"
#include "MessageNames.h"
#include "WebExtensionContentWorldType.h"
#include "WebExtensionDataType.h"
#include "WebExtensionEventListenerType.h"
#include "WebExtensionFrameParameters.h"
#include "WebExtensionMenuItemContextParameters.h"
#include "WebExtensionMenuItemParameters.h"
#include "WebExtensionTabParameters.h"
#include "WebExtensionWindowParameters.h"
#include <wtf/Forward.h>
#include <wtf/HashCountedSet.h>
#include <wtf/HashMap.h>
#include <wtf/HashSet.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/WallTime.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class FormDataReference;
}

namespace WebCore {
class AuthenticationChallenge;
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
class ResourceError;
class ResourceRequest;
class ResourceResponse;
}

namespace WebKit {
struct WebExtensionPortChannelIdentifierType;
using WebExtensionPortChannelIdentifier = ObjectIdentifier<WebExtensionPortChannelIdentifierType>;
struct WebExtensionTabIdentifierType;
using WebExtensionTabIdentifier = ObjectIdentifier<WebExtensionTabIdentifierType>;
struct WebExtensionWindowIdentifierType;
using WebExtensionWindowIdentifier = ObjectIdentifier<WebExtensionWindowIdentifierType>;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
enum class WebExtensionContextInstallReason : uint8_t;
struct ResourceLoadInfo;
struct WebExtensionAlarmParameters;
struct WebExtensionMessageSenderParameters;
struct WebExtensionMessageTargetParameters;
}

namespace Messages {
namespace WebExtensionContextProxy {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInWebProcess());
        }
    );
#endif
    return IPC::ReceiverName::WebExtensionContextProxy;
}

class DispatchActionClickedEvent {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionTabParameters>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchActionClickedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchActionClickedEvent(const std::optional<WebKit::WebExtensionTabParameters>& tabParameters)
        : m_tabParameters(tabParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabParameters>& m_tabParameters;
};

class DispatchAlarmsEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionAlarmParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchAlarmsEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchAlarmsEvent(const WebKit::WebExtensionAlarmParameters& alarmInfo)
        : m_alarmInfo(alarmInfo)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_alarmInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionAlarmParameters& m_alarmInfo;
};

class DispatchCommandsCommandEvent {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebExtensionTabParameters>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchCommandsCommandEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchCommandsCommandEvent(const String& identifier, const std::optional<WebKit::WebExtensionTabParameters>& tabParameters)
        : m_identifier(identifier)
        , m_tabParameters(tabParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabParameters;
    }

private:
    const String& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabParameters>& m_tabParameters;
};

class DispatchCommandsChangedEvent {
public:
    using Arguments = std::tuple<String, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchCommandsChangedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchCommandsChangedEvent(const String& identifier, const String& oldShortcut, const String& newShortcut)
        : m_identifier(identifier)
        , m_oldShortcut(oldShortcut)
        , m_newShortcut(newShortcut)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        encoder << m_oldShortcut;
        encoder << m_newShortcut;
    }

private:
    const String& m_identifier;
    const String& m_oldShortcut;
    const String& m_newShortcut;
};

class DispatchCookiesChangedEvent {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchCookiesChangedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchCookiesChangedEvent()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(INSPECTOR_EXTENSIONS)
class AddInspectorPageIdentifier {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, std::optional<WebKit::WebExtensionWindowIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_AddInspectorPageIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddInspectorPageIdentifier(const WebCore::PageIdentifier& pageID, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier)
        : m_pageID(pageID)
        , m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
};
#endif

#if ENABLE(INSPECTOR_EXTENSIONS)
class AddInspectorBackgroundPageIdentifier {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, std::optional<WebKit::WebExtensionWindowIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_AddInspectorBackgroundPageIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddInspectorBackgroundPageIdentifier(const WebCore::PageIdentifier& pageID, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier)
        : m_pageID(pageID)
        , m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
};
#endif

#if ENABLE(INSPECTOR_EXTENSIONS)
class DispatchDevToolsExtensionPanelShownEvent {
public:
    using Arguments = std::tuple<Inspector::ExtensionTabID, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchDevToolsExtensionPanelShownEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchDevToolsExtensionPanelShownEvent(const Inspector::ExtensionTabID& identifier, const WebCore::FrameIdentifier& frameIdentifier)
        : m_identifier(identifier)
        , m_frameIdentifier(frameIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameIdentifier;
    }

private:
    const Inspector::ExtensionTabID& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameIdentifier;
};
#endif

#if ENABLE(INSPECTOR_EXTENSIONS)
class DispatchDevToolsExtensionPanelHiddenEvent {
public:
    using Arguments = std::tuple<Inspector::ExtensionTabID>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchDevToolsExtensionPanelHiddenEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchDevToolsExtensionPanelHiddenEvent(const Inspector::ExtensionTabID& identifier)
        : m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
    }

private:
    const Inspector::ExtensionTabID& m_identifier;
};
#endif

#if ENABLE(INSPECTOR_EXTENSIONS)
class DispatchDevToolsNetworkNavigatedEvent {
public:
    using Arguments = std::tuple<URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchDevToolsNetworkNavigatedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchDevToolsNetworkNavigatedEvent(const URL& url)
        : m_url(url)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};
#endif

#if ENABLE(INSPECTOR_EXTENSIONS)
class DispatchDevToolsPanelsThemeChangedEvent {
public:
    using Arguments = std::tuple<Inspector::ExtensionAppearance>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchDevToolsPanelsThemeChangedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchDevToolsPanelsThemeChangedEvent(const Inspector::ExtensionAppearance& appearance)
        : m_appearance(appearance)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_appearance;
    }

private:
    const Inspector::ExtensionAppearance& m_appearance;
};
#endif

class SetBackgroundPageIdentifier {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_SetBackgroundPageIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetBackgroundPageIdentifier(const WebCore::PageIdentifier& pageID)
        : m_pageID(pageID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
};

class AddPopupPageIdentifier {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, std::optional<WebKit::WebExtensionWindowIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_AddPopupPageIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddPopupPageIdentifier(const WebCore::PageIdentifier& pageID, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier)
        : m_pageID(pageID)
        , m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
};

class AddTabPageIdentifier {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, WebKit::WebExtensionTabIdentifier, std::optional<WebKit::WebExtensionWindowIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_AddTabPageIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddTabPageIdentifier(const WebCore::PageIdentifier& pageID, const WebKit::WebExtensionTabIdentifier& tabIdentifier, const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier)
        : m_pageID(pageID)
        , m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
};

class DispatchMenusClickedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionMenuItemParameters, bool, WebKit::WebExtensionMenuItemContextParameters, std::optional<WebKit::WebExtensionTabParameters>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchMenusClickedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchMenusClickedEvent(const WebKit::WebExtensionMenuItemParameters& menuItemParameters, bool wasChecked, const WebKit::WebExtensionMenuItemContextParameters& contextParameters, const std::optional<WebKit::WebExtensionTabParameters>& tabParameters)
        : m_menuItemParameters(menuItemParameters)
        , m_wasChecked(wasChecked)
        , m_contextParameters(contextParameters)
        , m_tabParameters(tabParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_menuItemParameters;
        encoder << m_wasChecked;
        encoder << m_contextParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabParameters;
    }

private:
    const WebKit::WebExtensionMenuItemParameters& m_menuItemParameters;
    bool m_wasChecked;
    const WebKit::WebExtensionMenuItemContextParameters& m_contextParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabParameters>& m_tabParameters;
};

class UpdateGrantedPermissions {
public:
    using Arguments = std::tuple<HashMap<String, WallTime>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_UpdateGrantedPermissions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateGrantedPermissions(const HashMap<String, WallTime>& permissions)
        : m_permissions(permissions)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_permissions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<String, WallTime>& m_permissions;
};

class DispatchPermissionsEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionEventListenerType, HashSet<String>, HashSet<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchPermissionsEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchPermissionsEvent(const WebKit::WebExtensionEventListenerType& type, const HashSet<String>& permissions, const HashSet<String>& origins)
        : m_type(type)
        , m_permissions(permissions)
        , m_origins(origins)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_permissions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origins;
    }

private:
    const WebKit::WebExtensionEventListenerType& m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<String>& m_permissions;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<String>& m_origins;
};

class DispatchPortMessageEvent {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebPageProxyIdentifier>, WebKit::WebExtensionPortChannelIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchPortMessageEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchPortMessageEvent(const std::optional<WebKit::WebPageProxyIdentifier>& sendingPageProxyIdentifier, const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier, const String& messageJSON)
        : m_sendingPageProxyIdentifier(sendingPageProxyIdentifier)
        , m_channelIdentifier(channelIdentifier)
        , m_messageJSON(messageJSON)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sendingPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
        encoder << m_messageJSON;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_sendingPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
    const String& m_messageJSON;
};

class DispatchPortDisconnectEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionPortChannelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchPortDisconnectEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchPortDisconnectEvent(const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier)
        : m_channelIdentifier(channelIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
};

class DispatchRuntimeMessageEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionContentWorldType, String, std::optional<WebKit::WebExtensionMessageTargetParameters>, WebKit::WebExtensionMessageSenderParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchRuntimeMessageEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContextProxy_DispatchRuntimeMessageEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    DispatchRuntimeMessageEvent(const WebKit::WebExtensionContentWorldType& contentWorldType, const String& messageJSON, const std::optional<WebKit::WebExtensionMessageTargetParameters>& targetParameters, const WebKit::WebExtensionMessageSenderParameters& senderParameters)
        : m_contentWorldType(contentWorldType)
        , m_messageJSON(messageJSON)
        , m_targetParameters(targetParameters)
        , m_senderParameters(senderParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contentWorldType;
        encoder << m_messageJSON;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_senderParameters;
    }

private:
    const WebKit::WebExtensionContentWorldType& m_contentWorldType;
    const String& m_messageJSON;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionMessageTargetParameters>& m_targetParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageSenderParameters& m_senderParameters;
};

class DispatchRuntimeConnectEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionContentWorldType, WebKit::WebExtensionPortChannelIdentifier, String, std::optional<WebKit::WebExtensionMessageTargetParameters>, WebKit::WebExtensionMessageSenderParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchRuntimeConnectEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContextProxy_DispatchRuntimeConnectEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<HashCountedSet<WebKit::WebPageProxyIdentifier>>;
    using Reply = CompletionHandler<void(HashCountedSet<WebKit::WebPageProxyIdentifier>&&)>;
    using Promise = WTF::NativePromise<HashCountedSet<WebKit::WebPageProxyIdentifier>, IPC::Error>;
    DispatchRuntimeConnectEvent(const WebKit::WebExtensionContentWorldType& contentWorldType, const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier, const String& name, const std::optional<WebKit::WebExtensionMessageTargetParameters>& targetParameters, const WebKit::WebExtensionMessageSenderParameters& senderParameters)
        : m_contentWorldType(contentWorldType)
        , m_channelIdentifier(channelIdentifier)
        , m_name(name)
        , m_targetParameters(targetParameters)
        , m_senderParameters(senderParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contentWorldType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_senderParameters;
    }

private:
    const WebKit::WebExtensionContentWorldType& m_contentWorldType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionMessageTargetParameters>& m_targetParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageSenderParameters& m_senderParameters;
};

class DispatchRuntimeInstalledEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionContextInstallReason, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchRuntimeInstalledEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchRuntimeInstalledEvent(WebKit::WebExtensionContextInstallReason installReason, const String& previousVersion)
        : m_installReason(installReason)
        , m_previousVersion(previousVersion)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_installReason;
        encoder << m_previousVersion;
    }

private:
    WebKit::WebExtensionContextInstallReason m_installReason;
    const String& m_previousVersion;
};

class DispatchRuntimeStartupEvent {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchRuntimeStartupEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchRuntimeStartupEvent()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetStorageAccessLevel {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_SetStorageAccessLevel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetStorageAccessLevel(bool allowedInContentScripts)
        : m_allowedInContentScripts(allowedInContentScripts)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_allowedInContentScripts;
    }

private:
    bool m_allowedInContentScripts;
};

class DispatchStorageChangedEvent {
public:
    using Arguments = std::tuple<String, WebKit::WebExtensionDataType, WebKit::WebExtensionContentWorldType>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchStorageChangedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchStorageChangedEvent(const String& onChangedJSON, const WebKit::WebExtensionDataType& dataType, const WebKit::WebExtensionContentWorldType& contentWorldType)
        : m_onChangedJSON(onChangedJSON)
        , m_dataType(dataType)
        , m_contentWorldType(contentWorldType)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_onChangedJSON;
        encoder << m_dataType;
        encoder << m_contentWorldType;
    }

private:
    const String& m_onChangedJSON;
    const WebKit::WebExtensionDataType& m_dataType;
    const WebKit::WebExtensionContentWorldType& m_contentWorldType;
};

class DispatchTabsCreatedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsCreatedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchTabsCreatedEvent(const WebKit::WebExtensionTabParameters& tabParameters)
        : m_tabParameters(tabParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_tabParameters;
    }

private:
    const WebKit::WebExtensionTabParameters& m_tabParameters;
};

class DispatchTabsUpdatedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabParameters, WebKit::WebExtensionTabParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsUpdatedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTabsUpdatedEvent(const WebKit::WebExtensionTabParameters& tabParameters, const WebKit::WebExtensionTabParameters& changedParameters)
        : m_tabParameters(tabParameters)
        , m_changedParameters(changedParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_tabParameters;
        encoder << m_changedParameters;
    }

private:
    const WebKit::WebExtensionTabParameters& m_tabParameters;
    const WebKit::WebExtensionTabParameters& m_changedParameters;
};

class DispatchTabsReplacedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionTabIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsReplacedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTabsReplacedEvent(const WebKit::WebExtensionTabIdentifier& replacedTabIdentifier, const WebKit::WebExtensionTabIdentifier& newTabIdentifier)
        : m_replacedTabIdentifier(replacedTabIdentifier)
        , m_newTabIdentifier(newTabIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_replacedTabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newTabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_replacedTabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_newTabIdentifier;
};

class DispatchTabsDetachedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsDetachedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTabsDetachedEvent(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& oldWindowIdentifier, uint64_t oldIndex)
        : m_tabIdentifier(tabIdentifier)
        , m_oldWindowIdentifier(oldWindowIdentifier)
        , m_oldIndex(oldIndex)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_oldWindowIdentifier;
        encoder << m_oldIndex;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_oldWindowIdentifier;
    uint64_t m_oldIndex;
};

class DispatchTabsMovedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsMovedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTabsMovedEvent(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier, uint64_t oldIndex, uint64_t newIndex)
        : m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_oldIndex(oldIndex)
        , m_newIndex(newIndex)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        encoder << m_oldIndex;
        encoder << m_newIndex;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    uint64_t m_oldIndex;
    uint64_t m_newIndex;
};

class DispatchTabsAttachedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsAttachedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTabsAttachedEvent(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& newWindowIdentifier, uint64_t newIndex)
        : m_tabIdentifier(tabIdentifier)
        , m_newWindowIdentifier(newWindowIdentifier)
        , m_newIndex(newIndex)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newWindowIdentifier;
        encoder << m_newIndex;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_newWindowIdentifier;
    uint64_t m_newIndex;
};

class DispatchTabsActivatedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsActivatedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTabsActivatedEvent(const WebKit::WebExtensionTabIdentifier& previousActiveTabIdentifier, const WebKit::WebExtensionTabIdentifier& newActiveTabIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier)
        : m_previousActiveTabIdentifier(previousActiveTabIdentifier)
        , m_newActiveTabIdentifier(newActiveTabIdentifier)
        , m_windowIdentifier(windowIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_previousActiveTabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newActiveTabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_previousActiveTabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_newActiveTabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
};

class DispatchTabsHighlightedEvent {
public:
    using Arguments = std::tuple<Vector<WebKit::WebExtensionTabIdentifier>, WebKit::WebExtensionWindowIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsHighlightedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTabsHighlightedEvent(const Vector<WebKit::WebExtensionTabIdentifier>& tabs, const WebKit::WebExtensionWindowIdentifier& windowIdentifier)
        : m_tabs(tabs)
        , m_windowIdentifier(windowIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabs;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebExtensionTabIdentifier>& m_tabs;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
};

class DispatchTabsRemovedEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, WebKit::WebExtensionContext::WindowIsClosing>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTabsRemovedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTabsRemovedEvent(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier, const WebKit::WebExtensionContext::WindowIsClosing& windowIsClosing)
        : m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_windowIsClosing(windowIsClosing)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIsClosing;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionContext::WindowIsClosing& m_windowIsClosing;
};

class DispatchTestMessageEvent {
public:
    using Arguments = std::tuple<String, String, WebKit::WebExtensionContentWorldType>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTestMessageEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTestMessageEvent(const String& message, const String& argumentJSON, const WebKit::WebExtensionContentWorldType& contentWorldType)
        : m_message(message)
        , m_argumentJSON(argumentJSON)
        , m_contentWorldType(contentWorldType)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_argumentJSON;
        encoder << m_contentWorldType;
    }

private:
    const String& m_message;
    const String& m_argumentJSON;
    const WebKit::WebExtensionContentWorldType& m_contentWorldType;
};

class DispatchTestStartedEvent {
public:
    using Arguments = std::tuple<String, WebKit::WebExtensionContentWorldType>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTestStartedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTestStartedEvent(const String& argumentJSON, const WebKit::WebExtensionContentWorldType& contentWorldType)
        : m_argumentJSON(argumentJSON)
        , m_contentWorldType(contentWorldType)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_argumentJSON;
        encoder << m_contentWorldType;
    }

private:
    const String& m_argumentJSON;
    const WebKit::WebExtensionContentWorldType& m_contentWorldType;
};

class DispatchTestFinishedEvent {
public:
    using Arguments = std::tuple<String, WebKit::WebExtensionContentWorldType>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchTestFinishedEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchTestFinishedEvent(const String& argumentJSON, const WebKit::WebExtensionContentWorldType& contentWorldType)
        : m_argumentJSON(argumentJSON)
        , m_contentWorldType(contentWorldType)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_argumentJSON;
        encoder << m_contentWorldType;
    }

private:
    const String& m_argumentJSON;
    const WebKit::WebExtensionContentWorldType& m_contentWorldType;
};

class DispatchWebNavigationEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionEventListenerType, WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionFrameParameters, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchWebNavigationEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchWebNavigationEvent(const WebKit::WebExtensionEventListenerType& type, const WebKit::WebExtensionTabIdentifier& tabID, const WebKit::WebExtensionFrameParameters& frameParamaters, const WallTime& timestamp)
        : m_type(type)
        , m_tabID(tabID)
        , m_frameParamaters(frameParamaters)
        , m_timestamp(timestamp)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabID;
        encoder << m_frameParamaters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    const WebKit::WebExtensionEventListenerType& m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabID;
    const WebKit::WebExtensionFrameParameters& m_frameParamaters;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class ResourceLoadDidSendRequest {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, WebCore::ResourceRequest, WebKit::ResourceLoadInfo, std::optional<IPC::FormDataReference>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_ResourceLoadDidSendRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidSendRequest(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier, const WebCore::ResourceRequest& request, const WebKit::ResourceLoadInfo& resourceLoadInfo, const std::optional<IPC::FormDataReference>& formData)
        : m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_request(request)
        , m_resourceLoadInfo(resourceLoadInfo)
        , m_formData(formData)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_formData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<IPC::FormDataReference>& m_formData;
};

class ResourceLoadDidPerformHTTPRedirection {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, WebCore::ResourceResponse, WebKit::ResourceLoadInfo, WebCore::ResourceRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_ResourceLoadDidPerformHTTPRedirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidPerformHTTPRedirection(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier, const WebCore::ResourceResponse& response, const WebKit::ResourceLoadInfo& resourceLoadInfo, const WebCore::ResourceRequest& newRequest)
        : m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_response(response)
        , m_resourceLoadInfo(resourceLoadInfo)
        , m_newRequest(newRequest)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newRequest;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_newRequest;
};

class ResourceLoadDidReceiveChallenge {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, WebCore::AuthenticationChallenge, WebKit::ResourceLoadInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_ResourceLoadDidReceiveChallenge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidReceiveChallenge(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier, const WebCore::AuthenticationChallenge& challenge, const WebKit::ResourceLoadInfo& resourceLoadInfo)
        : m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_challenge(challenge)
        , m_resourceLoadInfo(resourceLoadInfo)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_challenge;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AuthenticationChallenge& m_challenge;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
};

class ResourceLoadDidReceiveResponse {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, WebCore::ResourceResponse, WebKit::ResourceLoadInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_ResourceLoadDidReceiveResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidReceiveResponse(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier, const WebCore::ResourceResponse& response, const WebKit::ResourceLoadInfo& resourceLoadInfo)
        : m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_response(response)
        , m_resourceLoadInfo(resourceLoadInfo)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
};

class ResourceLoadDidCompleteWithError {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionWindowIdentifier, WebCore::ResourceResponse, WebCore::ResourceError, WebKit::ResourceLoadInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_ResourceLoadDidCompleteWithError; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResourceLoadDidCompleteWithError(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier, const WebCore::ResourceResponse& response, const WebCore::ResourceError& error, const WebKit::ResourceLoadInfo& resourceLoadInfo)
        : m_tabIdentifier(tabIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_response(response)
        , m_error(error)
        , m_resourceLoadInfo(resourceLoadInfo)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceLoadInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ResourceLoadInfo& m_resourceLoadInfo;
};

class DispatchWindowsEvent {
public:
    using Arguments = std::tuple<WebKit::WebExtensionEventListenerType, std::optional<WebKit::WebExtensionWindowParameters>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContextProxy_DispatchWindowsEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchWindowsEvent(const WebKit::WebExtensionEventListenerType& type, const std::optional<WebKit::WebExtensionWindowParameters>& windowParameters)
        : m_type(type)
        , m_windowParameters(windowParameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowParameters;
    }

private:
    const WebKit::WebExtensionEventListenerType& m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowParameters>& m_windowParameters;
};

} // namespace WebExtensionContextProxy
} // namespace Messages

#endif // ENABLE(WK_WEB_EXTENSIONS)
