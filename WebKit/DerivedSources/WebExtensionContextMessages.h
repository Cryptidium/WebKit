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
#include "WebExtensionActionClickBehavior.h"
#include "WebExtensionCommandParameters.h"
#include "WebExtensionContentWorldType.h"
#include "WebExtensionDataType.h"
#include "WebExtensionError.h"
#include "WebExtensionEventListenerType.h"
#include "WebExtensionFrameParameters.h"
#include "WebExtensionMenuItemParameters.h"
#include "WebExtensionRegisteredScriptParameters.h"
#include "WebExtensionScriptInjectionParameters.h"
#include "WebExtensionScriptInjectionResultParameters.h"
#include "WebExtensionStorageAccessLevel.h"
#include "WebExtensionTabParameters.h"
#include "WebExtensionTabQueryParameters.h"
#include "WebExtensionWindow.h"
#include "WebExtensionWindowParameters.h"
#include <WebCore/JSDOMExceptionHandling.h>
#include <optional>
#include <pal/SessionID.h>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/HashMap.h>
#include <wtf/HashSet.h>
#include <wtf/OptionSet.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/URLHash.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace PAL {
class SessionID;
}

namespace WebCore {
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
}

namespace WebKit {
struct WebExtensionFrameIdentifierType;
using WebExtensionFrameIdentifier = ObjectIdentifier<WebExtensionFrameIdentifierType>;
struct WebExtensionPortChannelIdentifierType;
using WebExtensionPortChannelIdentifier = ObjectIdentifier<WebExtensionPortChannelIdentifierType>;
struct WebExtensionTabIdentifierType;
using WebExtensionTabIdentifier = ObjectIdentifier<WebExtensionTabIdentifierType>;
struct WebExtensionWindowIdentifierType;
using WebExtensionWindowIdentifier = ObjectIdentifier<WebExtensionWindowIdentifierType>;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
enum class ReloadFromOrigin : bool;
enum class WebExtensionTabImageFormat : uint8_t;
struct WebExtensionAlarmParameters;
struct WebExtensionCookieFilterParameters;
struct WebExtensionCookieParameters;
struct WebExtensionMessageSenderParameters;
struct WebExtensionMessageTargetParameters;
}

namespace Messages {
namespace WebExtensionContext {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(!isInAuxiliaryProcess());
        }
    );
#endif
    return IPC::ReceiverName::WebExtensionContext;
}

class ActionGetTitle {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionGetTitle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionGetTitleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    ActionGetTitle(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class ActionSetTitle {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionSetTitle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionSetTitleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    ActionSetTitle(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const String& title)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_title(title)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_title;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const String& m_title;
};

class ActionSetIcon {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionSetIcon; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionSetIconReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    ActionSetIcon(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const String& iconsJSON)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_iconsJSON(iconsJSON)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_iconsJSON;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const String& m_iconsJSON;
};

class ActionGetPopup {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionGetPopup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionGetPopupReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    ActionGetPopup(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class ActionSetPopup {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionSetPopup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionSetPopupReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    ActionSetPopup(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const String& popupPath)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_popupPath(popupPath)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_popupPath;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const String& m_popupPath;
};

class ActionOpenPopup {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionOpenPopup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionOpenPopupReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    ActionOpenPopup(const WebKit::WebPageProxyIdentifier& identifier, const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_identifier(identifier)
        , m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class ActionGetBadgeText {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionGetBadgeText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionGetBadgeTextReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    ActionGetBadgeText(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class ActionSetBadgeText {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionSetBadgeText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionSetBadgeTextReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    ActionSetBadgeText(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const String& text)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_text(text)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_text;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const String& m_text;
};

class ActionGetEnabled {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionGetEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionGetEnabledReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<bool, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebKit::WebExtensionError>, IPC::Error>;
    ActionGetEnabled(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class ActionSetEnabled {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionTabIdentifier>, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ActionSetEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ActionSetEnabledReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    ActionSetEnabled(const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, bool enabled)
        : m_tabIdentifier(tabIdentifier)
        , m_enabled(enabled)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    bool m_enabled;
};

class AlarmsCreate {
public:
    using Arguments = std::tuple<String, Seconds, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_AlarmsCreate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AlarmsCreate(const String& name, const Seconds& initialInterval, const Seconds& repeatInterval)
        : m_name(name)
        , m_initialInterval(initialInterval)
        , m_repeatInterval(repeatInterval)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initialInterval;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_repeatInterval;
    }

private:
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_initialInterval;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_repeatInterval;
};

class AlarmsGet {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_AlarmsGet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_AlarmsGetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::WebExtensionAlarmParameters>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::WebExtensionAlarmParameters>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::WebExtensionAlarmParameters>, IPC::Error>;
    explicit AlarmsGet(const String& name)
        : m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
    }

private:
    const String& m_name;
};

class AlarmsClear {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_AlarmsClear; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_AlarmsClearReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit AlarmsClear(const String& name)
        : m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
    }

private:
    const String& m_name;
};

class AlarmsGetAll {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_AlarmsGetAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_AlarmsGetAllReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::WebExtensionAlarmParameters>>;
    using Reply = CompletionHandler<void(Vector<WebKit::WebExtensionAlarmParameters>&&)>;
    using Promise = WTF::NativePromise<Vector<WebKit::WebExtensionAlarmParameters>, IPC::Error>;
    AlarmsGetAll()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class AlarmsClearAll {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_AlarmsClearAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_AlarmsClearAllReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    AlarmsClearAll()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksCreate {
public:
    using Arguments = std::tuple<std::optional<String>, std::optional<uint64_t>, std::optional<String>, std::optional<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksCreate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksCreateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>, IPC::Error>;
    BookmarksCreate(const std::optional<String>& parentId, const std::optional<uint64_t>& index, const std::optional<String>& url, const std::optional<String>& title)
        : m_parentId(parentId)
        , m_index(index)
        , m_url(url)
        , m_title(title)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parentId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_index;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_title;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_parentId;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_index;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_title;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksGetTree {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksGetTree; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksGetTreeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>, IPC::Error>;
    BookmarksGetTree()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksGetSubTree {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksGetSubTree; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksGetSubTreeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit BookmarksGetSubTree(const String& bookmarkId)
        : m_bookmarkId(bookmarkId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bookmarkId;
    }

private:
    const String& m_bookmarkId;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksGet {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksGet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksGetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit BookmarksGet(const Vector<String>& bookmarkId)
        : m_bookmarkId(bookmarkId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bookmarkId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_bookmarkId;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksGetChildren {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksGetChildren; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksGetChildrenReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit BookmarksGetChildren(const String& bookmarkId)
        : m_bookmarkId(bookmarkId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bookmarkId;
    }

private:
    const String& m_bookmarkId;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksGetRecent {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksGetRecent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksGetRecentReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit BookmarksGetRecent(uint64_t count)
        : m_count(count)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_count;
    }

private:
    uint64_t m_count;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksSearch {
public:
    using Arguments = std::tuple<std::optional<String>, std::optional<String>, std::optional<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksSearch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksSearchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionBookmarksParameters>, WebKit::WebExtensionError>, IPC::Error>;
    BookmarksSearch(const std::optional<String>& query, const std::optional<String>& url, const std::optional<String>& title)
        : m_query(query)
        , m_url(url)
        , m_title(title)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_query;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_title;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_query;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_title;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksUpdate {
public:
    using Arguments = std::tuple<String, std::optional<String>, std::optional<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksUpdateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>, IPC::Error>;
    BookmarksUpdate(const String& bookmarkId, const std::optional<String>& url, const std::optional<String>& title)
        : m_bookmarkId(bookmarkId)
        , m_url(url)
        , m_title(title)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bookmarkId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_title;
    }

private:
    const String& m_bookmarkId;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_title;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksMove {
public:
    using Arguments = std::tuple<String, std::optional<String>, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksMove; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksMoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionBookmarksParameters, WebKit::WebExtensionError>, IPC::Error>;
    BookmarksMove(const String& bookmarkId, const std::optional<String>& parentId, const std::optional<uint64_t>& index)
        : m_bookmarkId(bookmarkId)
        , m_parentId(parentId)
        , m_index(index)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bookmarkId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parentId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_index;
    }

private:
    const String& m_bookmarkId;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_parentId;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_index;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksRemove {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksRemove; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksRemoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit BookmarksRemove(const String& bookmarkId)
        : m_bookmarkId(bookmarkId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bookmarkId;
    }

private:
    const String& m_bookmarkId;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
class BookmarksRemoveTree {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_BookmarksRemoveTree; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_BookmarksRemoveTreeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit BookmarksRemoveTree(const String& bookmarkId)
        : m_bookmarkId(bookmarkId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bookmarkId;
    }

private:
    const String& m_bookmarkId;
};
#endif

class CommandsGetAll {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_CommandsGetAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_CommandsGetAllReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::WebExtensionCommandParameters>>;
    using Reply = CompletionHandler<void(Vector<WebKit::WebExtensionCommandParameters>&&)>;
    using Promise = WTF::NativePromise<Vector<WebKit::WebExtensionCommandParameters>, IPC::Error>;
    CommandsGetAll()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CookiesGet {
public:
    using Arguments = std::tuple<std::optional<PAL::SessionID>, String, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_CookiesGet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_CookiesGetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>, IPC::Error>;
    CookiesGet(const std::optional<PAL::SessionID>& sessionID, const String& name, const URL& url)
        : m_sessionID(sessionID)
        , m_name(name)
        , m_url(url)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<PAL::SessionID>& m_sessionID;
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class CookiesGetAll {
public:
    using Arguments = std::tuple<std::optional<PAL::SessionID>, URL, WebKit::WebExtensionCookieFilterParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_CookiesGetAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_CookiesGetAllReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>, IPC::Error>;
    CookiesGetAll(const std::optional<PAL::SessionID>& sessionID, const URL& url, const WebKit::WebExtensionCookieFilterParameters& filterParameters)
        : m_sessionID(sessionID)
        , m_url(url)
        , m_filterParameters(filterParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_filterParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<PAL::SessionID>& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionCookieFilterParameters& m_filterParameters;
};

class CookiesSet {
public:
    using Arguments = std::tuple<std::optional<PAL::SessionID>, WebKit::WebExtensionCookieParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_CookiesSet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_CookiesSetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>, IPC::Error>;
    CookiesSet(const std::optional<PAL::SessionID>& sessionID, const WebKit::WebExtensionCookieParameters& cookie)
        : m_sessionID(sessionID)
        , m_cookie(cookie)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookie;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<PAL::SessionID>& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionCookieParameters& m_cookie;
};

class CookiesRemove {
public:
    using Arguments = std::tuple<std::optional<PAL::SessionID>, String, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_CookiesRemove; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_CookiesRemoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionCookieParameters>, WebKit::WebExtensionError>, IPC::Error>;
    CookiesRemove(const std::optional<PAL::SessionID>& sessionID, const String& name, const URL& url)
        : m_sessionID(sessionID)
        , m_name(name)
        , m_url(url)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<PAL::SessionID>& m_sessionID;
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class CookiesGetAllCookieStores {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_CookiesGetAllCookieStores; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_CookiesGetAllCookieStoresReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<HashMap<PAL::SessionID, Vector<WebKit::WebExtensionTabIdentifier>>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<HashMap<PAL::SessionID, Vector<WebKit::WebExtensionTabIdentifier>>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<HashMap<PAL::SessionID, Vector<WebKit::WebExtensionTabIdentifier>>, WebKit::WebExtensionError>, IPC::Error>;
    CookiesGetAllCookieStores()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DeclarativeNetRequestGetEnabledRulesets {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestGetEnabledRulesets; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestGetEnabledRulesetsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    using Promise = WTF::NativePromise<Vector<String>, IPC::Error>;
    DeclarativeNetRequestGetEnabledRulesets()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DeclarativeNetRequestUpdateEnabledRulesets {
public:
    using Arguments = std::tuple<Vector<String>, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestUpdateEnabledRulesets; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestUpdateEnabledRulesetsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    DeclarativeNetRequestUpdateEnabledRulesets(const Vector<String>& rulesetIdentifiersToEnable, const Vector<String>& rulesetIdentifiersToDisable)
        : m_rulesetIdentifiersToEnable(rulesetIdentifiersToEnable)
        , m_rulesetIdentifiersToDisable(rulesetIdentifiersToDisable)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rulesetIdentifiersToEnable;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rulesetIdentifiersToDisable;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_rulesetIdentifiersToEnable;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_rulesetIdentifiersToDisable;
};

class DeclarativeNetRequestDisplayActionCountAsBadgeText {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestDisplayActionCountAsBadgeText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestDisplayActionCountAsBadgeTextReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit DeclarativeNetRequestDisplayActionCountAsBadgeText(bool result)
        : m_result(result)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_result;
    }

private:
    bool m_result;
};

class DeclarativeNetRequestIncrementActionCount {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, double>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestIncrementActionCount; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestIncrementActionCountReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    DeclarativeNetRequestIncrementActionCount(const WebKit::WebExtensionTabIdentifier& tabIdentifier, double increment)
        : m_tabIdentifier(tabIdentifier)
        , m_increment(increment)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_increment;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    double m_increment;
};

class DeclarativeNetRequestGetMatchedRules {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionTabIdentifier>, std::optional<WallTime>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestGetMatchedRules; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestGetMatchedRulesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionMatchedRuleParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionMatchedRuleParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionMatchedRuleParameters>, WebKit::WebExtensionError>, IPC::Error>;
    DeclarativeNetRequestGetMatchedRules(const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const std::optional<WallTime>& minTimeStamp)
        : m_tabIdentifier(tabIdentifier)
        , m_minTimeStamp(minTimeStamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_minTimeStamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WallTime>& m_minTimeStamp;
};

class DeclarativeNetRequestGetDynamicRules {
public:
    using Arguments = std::tuple<Vector<double>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestGetDynamicRules; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestGetDynamicRulesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    explicit DeclarativeNetRequestGetDynamicRules(const Vector<double>& ruleIDs)
        : m_ruleIDs(ruleIDs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ruleIDs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<double>& m_ruleIDs;
};

class DeclarativeNetRequestUpdateDynamicRules {
public:
    using Arguments = std::tuple<String, Vector<double>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestUpdateDynamicRules; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestUpdateDynamicRulesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    DeclarativeNetRequestUpdateDynamicRules(const String& rulesToAddJSON, const Vector<double>& ruleIdsToRemove)
        : m_rulesToAddJSON(rulesToAddJSON)
        , m_ruleIdsToRemove(ruleIdsToRemove)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_rulesToAddJSON;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ruleIdsToRemove;
    }

private:
    const String& m_rulesToAddJSON;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<double>& m_ruleIdsToRemove;
};

class DeclarativeNetRequestGetSessionRules {
public:
    using Arguments = std::tuple<Vector<double>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestGetSessionRules; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestGetSessionRulesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    explicit DeclarativeNetRequestGetSessionRules(const Vector<double>& ruleIDs)
        : m_ruleIDs(ruleIDs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ruleIDs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<double>& m_ruleIDs;
};

class DeclarativeNetRequestUpdateSessionRules {
public:
    using Arguments = std::tuple<String, Vector<double>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestUpdateSessionRules; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DeclarativeNetRequestUpdateSessionRulesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    DeclarativeNetRequestUpdateSessionRules(const String& rulesToAddJSON, const Vector<double>& ruleIdsToRemove)
        : m_rulesToAddJSON(rulesToAddJSON)
        , m_ruleIdsToRemove(ruleIdsToRemove)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_rulesToAddJSON;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ruleIdsToRemove;
    }

private:
    const String& m_rulesToAddJSON;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<double>& m_ruleIdsToRemove;
};

#if ENABLE(INSPECTOR_EXTENSIONS)
class DevToolsPanelsCreate {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, String, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DevToolsPanelsCreate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DevToolsPanelsCreateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Inspector::ExtensionTabID, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Inspector::ExtensionTabID, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Inspector::ExtensionTabID, WebKit::WebExtensionError>, IPC::Error>;
    DevToolsPanelsCreate(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const String& title, const String& iconPath, const String& pagePath)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_title(title)
        , m_iconPath(iconPath)
        , m_pagePath(pagePath)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_title;
        encoder << m_iconPath;
        encoder << m_pagePath;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const String& m_title;
    const String& m_iconPath;
    const String& m_pagePath;
};
#endif

#if ENABLE(INSPECTOR_EXTENSIONS)
class DevToolsInspectedWindowEval {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, String, std::optional<URL>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DevToolsInspectedWindowEval; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_DevToolsInspectedWindowEvalReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Expected<WebKit::JavaScriptEvaluationResult, std::optional<WebCore::ExceptionDetails>>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Expected<WebKit::JavaScriptEvaluationResult, std::optional<WebCore::ExceptionDetails>>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Expected<WebKit::JavaScriptEvaluationResult, std::optional<WebCore::ExceptionDetails>>, WebKit::WebExtensionError>, IPC::Error>;
    DevToolsInspectedWindowEval(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const String& scriptSource, const std::optional<URL>& frameURL)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_scriptSource(scriptSource)
        , m_frameURL(frameURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_scriptSource;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const String& m_scriptSource;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<URL>& m_frameURL;
};
#endif

#if ENABLE(INSPECTOR_EXTENSIONS)
class DevToolsInspectedWindowReload {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<bool>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_DevToolsInspectedWindowReload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DevToolsInspectedWindowReload(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<bool>& ignoreCache)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_ignoreCache(ignoreCache)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ignoreCache;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<bool>& m_ignoreCache;
};
#endif

class AddListener {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::WebExtensionEventListenerType, WebKit::WebExtensionContentWorldType>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_AddListener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddListener(const WebCore::FrameIdentifier& frameIdentifier, const WebKit::WebExtensionEventListenerType& listenerType, const WebKit::WebExtensionContentWorldType& contentWorldType)
        : m_frameIdentifier(frameIdentifier)
        , m_listenerType(listenerType)
        , m_contentWorldType(contentWorldType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameIdentifier;
        encoder << m_listenerType;
        encoder << m_contentWorldType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameIdentifier;
    const WebKit::WebExtensionEventListenerType& m_listenerType;
    const WebKit::WebExtensionContentWorldType& m_contentWorldType;
};

class RemoveListener {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::WebExtensionEventListenerType, WebKit::WebExtensionContentWorldType, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RemoveListener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveListener(const WebCore::FrameIdentifier& frameIdentifier, const WebKit::WebExtensionEventListenerType& listenerType, const WebKit::WebExtensionContentWorldType& contentWorldType, uint64_t removedCount)
        : m_frameIdentifier(frameIdentifier)
        , m_listenerType(listenerType)
        , m_contentWorldType(contentWorldType)
        , m_removedCount(removedCount)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameIdentifier;
        encoder << m_listenerType;
        encoder << m_contentWorldType;
        encoder << m_removedCount;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameIdentifier;
    const WebKit::WebExtensionEventListenerType& m_listenerType;
    const WebKit::WebExtensionContentWorldType& m_contentWorldType;
    uint64_t m_removedCount;
};

class ExtensionIsAllowedIncognitoAccess {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ExtensionIsAllowedIncognitoAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ExtensionIsAllowedIncognitoAccessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    ExtensionIsAllowedIncognitoAccess()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class MenusCreate {
public:
    using Arguments = std::tuple<WebKit::WebExtensionMenuItemParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_MenusCreate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_MenusCreateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit MenusCreate(const WebKit::WebExtensionMenuItemParameters& parameters)
        : m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_parameters;
    }

private:
    const WebKit::WebExtensionMenuItemParameters& m_parameters;
};

class MenusUpdate {
public:
    using Arguments = std::tuple<String, WebKit::WebExtensionMenuItemParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_MenusUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_MenusUpdateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    MenusUpdate(const String& identifier, const WebKit::WebExtensionMenuItemParameters& parameters)
        : m_identifier(identifier)
        , m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        encoder << m_parameters;
    }

private:
    const String& m_identifier;
    const WebKit::WebExtensionMenuItemParameters& m_parameters;
};

class MenusRemove {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_MenusRemove; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_MenusRemoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit MenusRemove(const String& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
    }

private:
    const String& m_identifier;
};

class MenusRemoveAll {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_MenusRemoveAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_MenusRemoveAllReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    MenusRemoveAll()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PermissionsGetAll {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_PermissionsGetAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_PermissionsGetAllReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>, Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&, Vector<String>&&)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<String>, Vector<String>>, IPC::Error>;
    PermissionsGetAll()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PermissionsContains {
public:
    using Arguments = std::tuple<HashSet<String>, HashSet<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_PermissionsContains; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_PermissionsContainsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    PermissionsContains(const HashSet<String>& permissions, const HashSet<String>& origins)
        : m_permissions(permissions)
        , m_origins(origins)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_permissions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origins;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<String>& m_permissions;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<String>& m_origins;
};

class PermissionsRequest {
public:
    using Arguments = std::tuple<HashSet<String>, HashSet<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_PermissionsRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_PermissionsRequestReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    PermissionsRequest(const HashSet<String>& permissions, const HashSet<String>& origins)
        : m_permissions(permissions)
        , m_origins(origins)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_permissions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origins;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<String>& m_permissions;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<String>& m_origins;
};

class PermissionsRemove {
public:
    using Arguments = std::tuple<HashSet<String>, HashSet<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_PermissionsRemove; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_PermissionsRemoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    PermissionsRemove(const HashSet<String>& permissions, const HashSet<String>& origins)
        : m_permissions(permissions)
        , m_origins(origins)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_permissions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origins;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<String>& m_permissions;
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<String>& m_origins;
};

class PortPostMessage {
public:
    using Arguments = std::tuple<WebKit::WebExtensionContentWorldType, WebKit::WebExtensionContentWorldType, std::optional<WebKit::WebPageProxyIdentifier>, WebKit::WebExtensionPortChannelIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_PortPostMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PortPostMessage(const WebKit::WebExtensionContentWorldType& sourceContentWorldType, const WebKit::WebExtensionContentWorldType& targetContentWorldType, const std::optional<WebKit::WebPageProxyIdentifier>& sendingPageProxyIdentifier, const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier, const String& messageJSON)
        : m_sourceContentWorldType(sourceContentWorldType)
        , m_targetContentWorldType(targetContentWorldType)
        , m_sendingPageProxyIdentifier(sendingPageProxyIdentifier)
        , m_channelIdentifier(channelIdentifier)
        , m_messageJSON(messageJSON)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sourceContentWorldType;
        encoder << m_targetContentWorldType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sendingPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
        encoder << m_messageJSON;
    }

private:
    const WebKit::WebExtensionContentWorldType& m_sourceContentWorldType;
    const WebKit::WebExtensionContentWorldType& m_targetContentWorldType;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_sendingPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
    const String& m_messageJSON;
};

class PortRemoved {
public:
    using Arguments = std::tuple<WebKit::WebExtensionContentWorldType, WebKit::WebExtensionContentWorldType, WebKit::WebPageProxyIdentifier, WebKit::WebExtensionPortChannelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_PortRemoved; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PortRemoved(const WebKit::WebExtensionContentWorldType& sourceContentWorldType, const WebKit::WebExtensionContentWorldType& targetContentWorldType, const WebKit::WebPageProxyIdentifier& pageProxyIdentifier, const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier)
        : m_sourceContentWorldType(sourceContentWorldType)
        , m_targetContentWorldType(targetContentWorldType)
        , m_pageProxyIdentifier(pageProxyIdentifier)
        , m_channelIdentifier(channelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sourceContentWorldType;
        encoder << m_targetContentWorldType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
    }

private:
    const WebKit::WebExtensionContentWorldType& m_sourceContentWorldType;
    const WebKit::WebExtensionContentWorldType& m_targetContentWorldType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
};

class RuntimeGetBackgroundPage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeGetBackgroundPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_RuntimeGetBackgroundPageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::PageIdentifier>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::PageIdentifier>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::PageIdentifier>, WebKit::WebExtensionError>, IPC::Error>;
    RuntimeGetBackgroundPage()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RuntimeOpenOptionsPage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeOpenOptionsPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_RuntimeOpenOptionsPageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    RuntimeOpenOptionsPage()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RuntimeReload {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeReload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RuntimeReload()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RuntimeSendMessage {
public:
    using Arguments = std::tuple<String, String, WebKit::WebExtensionMessageSenderParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeSendMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_RuntimeSendMessageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    RuntimeSendMessage(const String& extensionID, const String& messageJSON, const WebKit::WebExtensionMessageSenderParameters& senderParameters)
        : m_extensionID(extensionID)
        , m_messageJSON(messageJSON)
        , m_senderParameters(senderParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_extensionID;
        encoder << m_messageJSON;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_senderParameters;
    }

private:
    const String& m_extensionID;
    const String& m_messageJSON;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageSenderParameters& m_senderParameters;
};

class RuntimeConnect {
public:
    using Arguments = std::tuple<String, WebKit::WebExtensionPortChannelIdentifier, String, WebKit::WebExtensionMessageSenderParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeConnect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_RuntimeConnectReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    RuntimeConnect(const String& extensionID, const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier, const String& name, const WebKit::WebExtensionMessageSenderParameters& senderParameters)
        : m_extensionID(extensionID)
        , m_channelIdentifier(channelIdentifier)
        , m_name(name)
        , m_senderParameters(senderParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_extensionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_senderParameters;
    }

private:
    const String& m_extensionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageSenderParameters& m_senderParameters;
};

class RuntimeSendNativeMessage {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeSendNativeMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_RuntimeSendNativeMessageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    RuntimeSendNativeMessage(const String& applicationID, const String& messageJSON)
        : m_applicationID(applicationID)
        , m_messageJSON(messageJSON)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_applicationID;
        encoder << m_messageJSON;
    }

private:
    const String& m_applicationID;
    const String& m_messageJSON;
};

class RuntimeConnectNative {
public:
    using Arguments = std::tuple<String, WebKit::WebExtensionPortChannelIdentifier, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeConnectNative; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_RuntimeConnectNativeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    RuntimeConnectNative(const String& applicationID, const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier, const WebKit::WebPageProxyIdentifier& pageProxyIdentifier)
        : m_applicationID(applicationID)
        , m_channelIdentifier(channelIdentifier)
        , m_pageProxyIdentifier(pageProxyIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_applicationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageProxyIdentifier;
    }

private:
    const String& m_applicationID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageProxyIdentifier;
};

class RuntimeWebPageSendMessage {
public:
    using Arguments = std::tuple<String, String, WebKit::WebExtensionMessageSenderParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeWebPageSendMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_RuntimeWebPageSendMessageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    RuntimeWebPageSendMessage(const String& extensionID, const String& messageJSON, const WebKit::WebExtensionMessageSenderParameters& senderParameters)
        : m_extensionID(extensionID)
        , m_messageJSON(messageJSON)
        , m_senderParameters(senderParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_extensionID;
        encoder << m_messageJSON;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_senderParameters;
    }

private:
    const String& m_extensionID;
    const String& m_messageJSON;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageSenderParameters& m_senderParameters;
};

class RuntimeWebPageConnect {
public:
    using Arguments = std::tuple<String, WebKit::WebExtensionPortChannelIdentifier, String, WebKit::WebExtensionMessageSenderParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_RuntimeWebPageConnect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_RuntimeWebPageConnectReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    RuntimeWebPageConnect(const String& extensionID, const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier, const String& name, const WebKit::WebExtensionMessageSenderParameters& senderParameters)
        : m_extensionID(extensionID)
        , m_channelIdentifier(channelIdentifier)
        , m_name(name)
        , m_senderParameters(senderParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_extensionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_senderParameters;
    }

private:
    const String& m_extensionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageSenderParameters& m_senderParameters;
};

class ScriptingExecuteScript {
public:
    using Arguments = std::tuple<WebKit::WebExtensionScriptInjectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ScriptingExecuteScript; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ScriptingExecuteScriptReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionScriptInjectionResultParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionScriptInjectionResultParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionScriptInjectionResultParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit ScriptingExecuteScript(const WebKit::WebExtensionScriptInjectionParameters& parameters)
        : m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_parameters;
    }

private:
    const WebKit::WebExtensionScriptInjectionParameters& m_parameters;
};

class ScriptingInsertCSS {
public:
    using Arguments = std::tuple<WebKit::WebExtensionScriptInjectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ScriptingInsertCSS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ScriptingInsertCSSReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit ScriptingInsertCSS(const WebKit::WebExtensionScriptInjectionParameters& parameters)
        : m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_parameters;
    }

private:
    const WebKit::WebExtensionScriptInjectionParameters& m_parameters;
};

class ScriptingRemoveCSS {
public:
    using Arguments = std::tuple<WebKit::WebExtensionScriptInjectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ScriptingRemoveCSS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ScriptingRemoveCSSReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit ScriptingRemoveCSS(const WebKit::WebExtensionScriptInjectionParameters& parameters)
        : m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_parameters;
    }

private:
    const WebKit::WebExtensionScriptInjectionParameters& m_parameters;
};

class ScriptingRegisterContentScripts {
public:
    using Arguments = std::tuple<Vector<WebKit::WebExtensionRegisteredScriptParameters>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ScriptingRegisterContentScripts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ScriptingRegisterContentScriptsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit ScriptingRegisterContentScripts(const Vector<WebKit::WebExtensionRegisteredScriptParameters>& scripts)
        : m_scripts(scripts)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scripts;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebExtensionRegisteredScriptParameters>& m_scripts;
};

class ScriptingUpdateRegisteredScripts {
public:
    using Arguments = std::tuple<Vector<WebKit::WebExtensionRegisteredScriptParameters>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ScriptingUpdateRegisteredScripts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ScriptingUpdateRegisteredScriptsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit ScriptingUpdateRegisteredScripts(const Vector<WebKit::WebExtensionRegisteredScriptParameters>& scripts)
        : m_scripts(scripts)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scripts;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebExtensionRegisteredScriptParameters>& m_scripts;
};

class ScriptingGetRegisteredScripts {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ScriptingGetRegisteredScripts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ScriptingGetRegisteredScriptsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionRegisteredScriptParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionRegisteredScriptParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionRegisteredScriptParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit ScriptingGetRegisteredScripts(const Vector<String>& scriptIDs)
        : m_scriptIDs(scriptIDs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scriptIDs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_scriptIDs;
};

class ScriptingUnregisterContentScripts {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_ScriptingUnregisterContentScripts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_ScriptingUnregisterContentScriptsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit ScriptingUnregisterContentScripts(const Vector<String>& scriptIDs)
        : m_scriptIDs(scriptIDs)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scriptIDs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_scriptIDs;
};

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarOpen {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarOpen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarOpenReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    SidebarOpen(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarIsOpen {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarIsOpen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarIsOpenReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<bool, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebKit::WebExtensionError>, IPC::Error>;
    explicit SidebarIsOpen(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier)
        : m_windowIdentifier(windowIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarClose {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarClose; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarCloseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    SidebarClose()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarToggle {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarToggle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarToggleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    SidebarToggle()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarGetOptions {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarGetOptions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarGetOptionsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionSidebarParameters, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionSidebarParameters, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionSidebarParameters, WebKit::WebExtensionError>, IPC::Error>;
    SidebarGetOptions(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarSetOptions {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>, std::optional<String>, std::optional<bool>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarSetOptions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarSetOptionsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    SidebarSetOptions(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const std::optional<String>& panelSourcePath, const std::optional<bool>& enabled)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_panelSourcePath(panelSourcePath)
        , m_enabled(enabled)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_panelSourcePath;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_enabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_panelSourcePath;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<bool>& m_enabled;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarGetTitle {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarGetTitle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarGetTitleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    SidebarGetTitle(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarSetTitle {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>, std::optional<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarSetTitle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarSetTitleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    SidebarSetTitle(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const std::optional<String>& title)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_title(title)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_title;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<String>& m_title;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarSetIcon {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebExtensionWindowIdentifier>, std::optional<WebKit::WebExtensionTabIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarSetIcon; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarSetIconReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    SidebarSetIcon(const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const String& iconsJSON)
        : m_windowIdentifier(windowIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_iconsJSON(iconsJSON)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_iconsJSON;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const String& m_iconsJSON;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarSetActionClickBehavior {
public:
    using Arguments = std::tuple<WebKit::WebExtensionActionClickBehavior>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarSetActionClickBehavior; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarSetActionClickBehaviorReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit SidebarSetActionClickBehavior(const WebKit::WebExtensionActionClickBehavior& actionClickBehavior)
        : m_actionClickBehavior(actionClickBehavior)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_actionClickBehavior;
    }

private:
    const WebKit::WebExtensionActionClickBehavior& m_actionClickBehavior;
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
class SidebarGetActionClickBehavior {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_SidebarGetActionClickBehavior; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_SidebarGetActionClickBehaviorReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionActionClickBehavior, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionActionClickBehavior, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionActionClickBehavior, WebKit::WebExtensionError>, IPC::Error>;
    SidebarGetActionClickBehavior()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class StorageGet {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionDataType, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_StorageGet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_StorageGetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    StorageGet(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionDataType& dataType, const Vector<String>& keys)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_dataType(dataType)
        , m_keys(keys)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_dataType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_keys;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const WebKit::WebExtensionDataType& m_dataType;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_keys;
};

class StorageGetKeys {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionDataType>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_StorageGetKeys; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_StorageGetKeysReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<String>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<String>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<String>, WebKit::WebExtensionError>, IPC::Error>;
    StorageGetKeys(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionDataType& dataType)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_dataType(dataType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_dataType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const WebKit::WebExtensionDataType& m_dataType;
};

class StorageGetBytesInUse {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionDataType, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_StorageGetBytesInUse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_StorageGetBytesInUseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<uint64_t, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<uint64_t, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<uint64_t, WebKit::WebExtensionError>, IPC::Error>;
    StorageGetBytesInUse(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionDataType& dataType, const Vector<String>& keys)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_dataType(dataType)
        , m_keys(keys)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_dataType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_keys;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const WebKit::WebExtensionDataType& m_dataType;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_keys;
};

class StorageSet {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionDataType, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_StorageSet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_StorageSetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    StorageSet(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionDataType& dataType, const String& dataJSON)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_dataType(dataType)
        , m_dataJSON(dataJSON)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_dataType;
        encoder << m_dataJSON;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const WebKit::WebExtensionDataType& m_dataType;
    const String& m_dataJSON;
};

class StorageRemove {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionDataType, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_StorageRemove; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_StorageRemoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    StorageRemove(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionDataType& dataType, const Vector<String>& keys)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_dataType(dataType)
        , m_keys(keys)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_dataType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_keys;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const WebKit::WebExtensionDataType& m_dataType;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_keys;
};

class StorageClear {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionDataType>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_StorageClear; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_StorageClearReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    StorageClear(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionDataType& dataType)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_dataType(dataType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_dataType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const WebKit::WebExtensionDataType& m_dataType;
};

class StorageSetAccessLevel {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionDataType, WebKit::WebExtensionStorageAccessLevel>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_StorageSetAccessLevel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_StorageSetAccessLevelReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    StorageSetAccessLevel(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionDataType& dataType, const WebKit::WebExtensionStorageAccessLevel& accessLevel)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_dataType(dataType)
        , m_accessLevel(accessLevel)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_dataType;
        encoder << m_accessLevel;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const WebKit::WebExtensionDataType& m_dataType;
    const WebKit::WebExtensionStorageAccessLevel& m_accessLevel;
};

class TabsCreate {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebPageProxyIdentifier>, WebKit::WebExtensionTabParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsCreate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsCreateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>, IPC::Error>;
    TabsCreate(const std::optional<WebKit::WebPageProxyIdentifier>& webPageProxyIdentifier, const WebKit::WebExtensionTabParameters& creationParameters)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_creationParameters(creationParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_creationParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_webPageProxyIdentifier;
    const WebKit::WebExtensionTabParameters& m_creationParameters;
};

class TabsUpdate {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, WebKit::WebExtensionTabParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsUpdateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>, IPC::Error>;
    TabsUpdate(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const WebKit::WebExtensionTabParameters& updateParameters)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_updateParameters(updateParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_updateParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const WebKit::WebExtensionTabParameters& m_updateParameters;
};

class TabsDuplicate {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionTabParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsDuplicate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsDuplicateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>, IPC::Error>;
    TabsDuplicate(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionTabParameters& creationParameters)
        : m_tabIdentifier(tabIdentifier)
        , m_creationParameters(creationParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_creationParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    const WebKit::WebExtensionTabParameters& m_creationParameters;
};

class TabsGet {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsGet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsGetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit TabsGet(const WebKit::WebExtensionTabIdentifier& tabIdentifier)
        : m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
};

class TabsGetCurrent {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsGetCurrent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsGetCurrentReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit TabsGetCurrent(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
};

class TabsQuery {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionTabQueryParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsQuery; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsQueryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionTabParameters>, WebKit::WebExtensionError>, IPC::Error>;
    TabsQuery(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionTabQueryParameters& queryParameters)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_queryParameters(queryParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        encoder << m_queryParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    const WebKit::WebExtensionTabQueryParameters& m_queryParameters;
};

class TabsReload {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, WebKit::ReloadFromOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsReload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsReloadReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    TabsReload(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, WebKit::ReloadFromOrigin reloadFromOrigin)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_reloadFromOrigin(reloadFromOrigin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_reloadFromOrigin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    WebKit::ReloadFromOrigin m_reloadFromOrigin;
};

class TabsGoBack {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsGoBack; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsGoBackReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    TabsGoBack(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class TabsGoForward {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsGoForward; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsGoForwardReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    TabsGoForward(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class TabsDetectLanguage {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsDetectLanguage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsDetectLanguageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    TabsDetectLanguage(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class TabsToggleReaderMode {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsToggleReaderMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsToggleReaderModeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    TabsToggleReaderMode(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class TabsCaptureVisibleTab {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionWindowIdentifier>, WebKit::WebExtensionTabImageFormat, uint8_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsCaptureVisibleTab; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsCaptureVisibleTabReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<URL, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<URL, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<URL, WebKit::WebExtensionError>, IPC::Error>;
    TabsCaptureVisibleTab(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionWindowIdentifier>& windowIdentifier, WebKit::WebExtensionTabImageFormat imageFormat, uint8_t imageQuality)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_imageFormat(imageFormat)
        , m_imageQuality(imageQuality)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        encoder << m_imageFormat;
        encoder << m_imageQuality;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionWindowIdentifier>& m_windowIdentifier;
    WebKit::WebExtensionTabImageFormat m_imageFormat;
    uint8_t m_imageQuality;
};

class TabsSendMessage {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, String, WebKit::WebExtensionMessageTargetParameters, WebKit::WebExtensionMessageSenderParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsSendMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsSendMessageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::WebExtensionError>, IPC::Error>;
    TabsSendMessage(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const String& messageJSON, const WebKit::WebExtensionMessageTargetParameters& targetParameters, const WebKit::WebExtensionMessageSenderParameters& senderParameters)
        : m_tabIdentifier(tabIdentifier)
        , m_messageJSON(messageJSON)
        , m_targetParameters(targetParameters)
        , m_senderParameters(senderParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_messageJSON;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_senderParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    const String& m_messageJSON;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageTargetParameters& m_targetParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageSenderParameters& m_senderParameters;
};

class TabsConnect {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionPortChannelIdentifier, String, WebKit::WebExtensionMessageTargetParameters, WebKit::WebExtensionMessageSenderParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsConnect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsConnectReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    TabsConnect(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionPortChannelIdentifier& channelIdentifier, const String& name, const WebKit::WebExtensionMessageTargetParameters& targetParameters, const WebKit::WebExtensionMessageSenderParameters& senderParameters)
        : m_tabIdentifier(tabIdentifier)
        , m_channelIdentifier(channelIdentifier)
        , m_name(name)
        , m_targetParameters(targetParameters)
        , m_senderParameters(senderParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_channelIdentifier;
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_senderParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionPortChannelIdentifier& m_channelIdentifier;
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageTargetParameters& m_targetParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionMessageSenderParameters& m_senderParameters;
};

class TabsGetZoom {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsGetZoom; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsGetZoomReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<double, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<double, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<double, WebKit::WebExtensionError>, IPC::Error>;
    TabsGetZoom(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
};

class TabsSetZoom {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, double>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsSetZoom; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsSetZoomReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    TabsSetZoom(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, double zoomFactor)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_zoomFactor(zoomFactor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_zoomFactor;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    double m_zoomFactor;
};

class TabsRemove {
public:
    using Arguments = std::tuple<Vector<WebKit::WebExtensionTabIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsRemove; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsRemoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit TabsRemove(const Vector<WebKit::WebExtensionTabIdentifier>& tabIdentifiers)
        : m_tabIdentifiers(tabIdentifiers)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebExtensionTabIdentifier>& m_tabIdentifiers;
};

class TabsExecuteScript {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, WebKit::WebExtensionScriptInjectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsExecuteScript; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsExecuteScriptReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionScriptInjectionResultParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionScriptInjectionResultParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionScriptInjectionResultParameters>, WebKit::WebExtensionError>, IPC::Error>;
    TabsExecuteScript(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const WebKit::WebExtensionScriptInjectionParameters& parameters)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const WebKit::WebExtensionScriptInjectionParameters& m_parameters;
};

class TabsInsertCSS {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, WebKit::WebExtensionScriptInjectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsInsertCSS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsInsertCSSReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    TabsInsertCSS(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const WebKit::WebExtensionScriptInjectionParameters& parameters)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const WebKit::WebExtensionScriptInjectionParameters& m_parameters;
};

class TabsRemoveCSS {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, std::optional<WebKit::WebExtensionTabIdentifier>, WebKit::WebExtensionScriptInjectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_TabsRemoveCSS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_TabsRemoveCSSReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    TabsRemoveCSS(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const std::optional<WebKit::WebExtensionTabIdentifier>& tabIdentifier, const WebKit::WebExtensionScriptInjectionParameters& parameters)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_tabIdentifier(tabIdentifier)
        , m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebExtensionTabIdentifier>& m_tabIdentifier;
    const WebKit::WebExtensionScriptInjectionParameters& m_parameters;
};

class WebNavigationGetAllFrames {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_WebNavigationGetAllFrames; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_WebNavigationGetAllFramesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionFrameParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionFrameParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionFrameParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit WebNavigationGetAllFrames(const WebKit::WebExtensionTabIdentifier& tabIdentifier)
        : m_tabIdentifier(tabIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
};

class WebNavigationGetFrame {
public:
    using Arguments = std::tuple<WebKit::WebExtensionTabIdentifier, WebKit::WebExtensionFrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_WebNavigationGetFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_WebNavigationGetFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionFrameParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionFrameParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionFrameParameters>, WebKit::WebExtensionError>, IPC::Error>;
    WebNavigationGetFrame(const WebKit::WebExtensionTabIdentifier& tabIdentifier, const WebKit::WebExtensionFrameIdentifier& frameIdentifier)
        : m_tabIdentifier(tabIdentifier)
        , m_frameIdentifier(frameIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_tabIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionTabIdentifier& m_tabIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionFrameIdentifier& m_frameIdentifier;
};

class WindowsCreate {
public:
    using Arguments = std::tuple<WebKit::WebExtensionWindowParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_WindowsCreate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_WindowsCreateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebKit::WebExtensionWindowParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebKit::WebExtensionWindowParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebKit::WebExtensionWindowParameters>, WebKit::WebExtensionError>, IPC::Error>;
    explicit WindowsCreate(const WebKit::WebExtensionWindowParameters& creationParameters)
        : m_creationParameters(creationParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_creationParameters;
    }

private:
    const WebKit::WebExtensionWindowParameters& m_creationParameters;
};

class WindowsGet {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionWindowIdentifier, OptionSet<WebKit::WebExtensionWindowTypeFilter>, WebKit::WebExtensionWindow::PopulateTabs>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_WindowsGet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_WindowsGetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>, IPC::Error>;
    WindowsGet(const WebKit::WebPageProxyIdentifier& webPageProxyIdentifier, const WebKit::WebExtensionWindowIdentifier& windowIdentifier, const OptionSet<WebKit::WebExtensionWindowTypeFilter>& filter, const WebKit::WebExtensionWindow::PopulateTabs& populate)
        : m_webPageProxyIdentifier(webPageProxyIdentifier)
        , m_windowIdentifier(windowIdentifier)
        , m_filter(filter)
        , m_populate(populate)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_filter;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_populate;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebExtensionWindowTypeFilter>& m_filter;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindow::PopulateTabs& m_populate;
};

class WindowsGetLastFocused {
public:
    using Arguments = std::tuple<OptionSet<WebKit::WebExtensionWindowTypeFilter>, WebKit::WebExtensionWindow::PopulateTabs>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_WindowsGetLastFocused; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_WindowsGetLastFocusedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>, IPC::Error>;
    WindowsGetLastFocused(const OptionSet<WebKit::WebExtensionWindowTypeFilter>& filter, const WebKit::WebExtensionWindow::PopulateTabs& populate)
        : m_filter(filter)
        , m_populate(populate)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_filter;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_populate;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebExtensionWindowTypeFilter>& m_filter;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindow::PopulateTabs& m_populate;
};

class WindowsGetAll {
public:
    using Arguments = std::tuple<OptionSet<WebKit::WebExtensionWindowTypeFilter>, WebKit::WebExtensionWindow::PopulateTabs>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_WindowsGetAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_WindowsGetAllReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<WebKit::WebExtensionWindowParameters>, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<Vector<WebKit::WebExtensionWindowParameters>, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<WebKit::WebExtensionWindowParameters>, WebKit::WebExtensionError>, IPC::Error>;
    WindowsGetAll(const OptionSet<WebKit::WebExtensionWindowTypeFilter>& filter, const WebKit::WebExtensionWindow::PopulateTabs& populate)
        : m_filter(filter)
        , m_populate(populate)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_filter;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_populate;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebExtensionWindowTypeFilter>& m_filter;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindow::PopulateTabs& m_populate;
};

class WindowsUpdate {
public:
    using Arguments = std::tuple<WebKit::WebExtensionWindowIdentifier, WebKit::WebExtensionWindowParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_WindowsUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_WindowsUpdateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::WebExtensionWindowParameters, WebKit::WebExtensionError>, IPC::Error>;
    WindowsUpdate(const WebKit::WebExtensionWindowIdentifier& windowIdentifier, const WebKit::WebExtensionWindowParameters& updateParameters)
        : m_windowIdentifier(windowIdentifier)
        , m_updateParameters(updateParameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
        encoder << m_updateParameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
    const WebKit::WebExtensionWindowParameters& m_updateParameters;
};

class WindowsRemove {
public:
    using Arguments = std::tuple<WebKit::WebExtensionWindowIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionContext_WindowsRemove; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebExtensionContext_WindowsRemoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<void, WebKit::WebExtensionError>>;
    using Reply = CompletionHandler<void(Expected<void, WebKit::WebExtensionError>&&)>;
    using Promise = WTF::NativePromise<Expected<void, WebKit::WebExtensionError>, IPC::Error>;
    explicit WindowsRemove(const WebKit::WebExtensionWindowIdentifier& windowIdentifier)
        : m_windowIdentifier(windowIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebExtensionWindowIdentifier& m_windowIdentifier;
};

} // namespace WebExtensionContext
} // namespace Messages

#endif // ENABLE(WK_WEB_EXTENSIONS)
