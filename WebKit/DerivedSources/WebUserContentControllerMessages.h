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

#include "ArgumentCoders.h"
#include "Connection.h"
#include "ContentWorldData.h"
#include "ContentWorldShared.h"
#include "MessageNames.h"
#include "WebUserContentControllerDataTypes.h"
#include <utility>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/URLHash.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
struct ContentWorldIdentifierType;
using ContentWorldIdentifier = ObjectIdentifier<ContentWorldIdentifierType>;
struct ScriptMessageHandlerIdentifierType;
using ScriptMessageHandlerIdentifier = ObjectIdentifier<ScriptMessageHandlerIdentifierType>;
struct UserScriptIdentifierType;
using UserScriptIdentifier = ObjectIdentifier<UserScriptIdentifierType>;
struct UserStyleSheetIdentifierType;
using UserStyleSheetIdentifier = ObjectIdentifier<UserStyleSheetIdentifierType>;
enum class InjectUserScriptImmediately : bool;
}

namespace Messages {
namespace WebUserContentController {

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
    return IPC::ReceiverName::WebUserContentController;
}

class AddContentWorlds {
public:
    using Arguments = std::tuple<Vector<WebKit::ContentWorldData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_AddContentWorlds; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddContentWorlds(const Vector<WebKit::ContentWorldData>& worlds)
        : m_worlds(worlds)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_worlds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::ContentWorldData>& m_worlds;
};

class RemoveContentWorlds {
public:
    using Arguments = std::tuple<Vector<WebKit::ContentWorldIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveContentWorlds; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveContentWorlds(const Vector<WebKit::ContentWorldIdentifier>& worldIdentifiers)
        : m_worldIdentifiers(worldIdentifiers)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_worldIdentifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::ContentWorldIdentifier>& m_worldIdentifiers;
};

class AddUserScripts {
public:
    using Arguments = std::tuple<Vector<WebKit::WebUserScriptData>, WebKit::InjectUserScriptImmediately>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_AddUserScripts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddUserScripts(const Vector<WebKit::WebUserScriptData>& userScripts, WebKit::InjectUserScriptImmediately immediately)
        : m_userScripts(userScripts)
        , m_immediately(immediately)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userScripts;
        encoder << m_immediately;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebUserScriptData>& m_userScripts;
    WebKit::InjectUserScriptImmediately m_immediately;
};

class RemoveUserScript {
public:
    using Arguments = std::tuple<WebKit::ContentWorldIdentifier, WebKit::UserScriptIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveUserScript; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveUserScript(const WebKit::ContentWorldIdentifier& worldIdentifier, const WebKit::UserScriptIdentifier& identifier)
        : m_worldIdentifier(worldIdentifier)
        , m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_worldIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ContentWorldIdentifier& m_worldIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserScriptIdentifier& m_identifier;
};

class RemoveAllUserScripts {
public:
    using Arguments = std::tuple<Vector<WebKit::ContentWorldIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveAllUserScripts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveAllUserScripts(const Vector<WebKit::ContentWorldIdentifier>& worldIdentifiers)
        : m_worldIdentifiers(worldIdentifiers)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_worldIdentifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::ContentWorldIdentifier>& m_worldIdentifiers;
};

class AddUserStyleSheets {
public:
    using Arguments = std::tuple<Vector<WebKit::WebUserStyleSheetData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_AddUserStyleSheets; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddUserStyleSheets(const Vector<WebKit::WebUserStyleSheetData>& userStyleSheets)
        : m_userStyleSheets(userStyleSheets)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userStyleSheets;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebUserStyleSheetData>& m_userStyleSheets;
};

class RemoveUserStyleSheet {
public:
    using Arguments = std::tuple<WebKit::ContentWorldIdentifier, WebKit::UserStyleSheetIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveUserStyleSheet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveUserStyleSheet(const WebKit::ContentWorldIdentifier& worldIdentifier, const WebKit::UserStyleSheetIdentifier& identifier)
        : m_worldIdentifier(worldIdentifier)
        , m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_worldIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ContentWorldIdentifier& m_worldIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserStyleSheetIdentifier& m_identifier;
};

class RemoveAllUserStyleSheets {
public:
    using Arguments = std::tuple<Vector<WebKit::ContentWorldIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveAllUserStyleSheets; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveAllUserStyleSheets(const Vector<WebKit::ContentWorldIdentifier>& worldIdentifiers)
        : m_worldIdentifiers(worldIdentifiers)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_worldIdentifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::ContentWorldIdentifier>& m_worldIdentifiers;
};

class AddUserScriptMessageHandlers {
public:
    using Arguments = std::tuple<Vector<WebKit::WebScriptMessageHandlerData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_AddUserScriptMessageHandlers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddUserScriptMessageHandlers(const Vector<WebKit::WebScriptMessageHandlerData>& scriptMessageHandlers)
        : m_scriptMessageHandlers(scriptMessageHandlers)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scriptMessageHandlers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebScriptMessageHandlerData>& m_scriptMessageHandlers;
};

class RemoveUserScriptMessageHandler {
public:
    using Arguments = std::tuple<WebKit::ContentWorldIdentifier, WebKit::ScriptMessageHandlerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveUserScriptMessageHandler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveUserScriptMessageHandler(const WebKit::ContentWorldIdentifier& worldIdentifier, const WebKit::ScriptMessageHandlerIdentifier& identifier)
        : m_worldIdentifier(worldIdentifier)
        , m_identifier(identifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_worldIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ContentWorldIdentifier& m_worldIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ScriptMessageHandlerIdentifier& m_identifier;
};

class RemoveAllUserScriptMessageHandlersForWorlds {
public:
    using Arguments = std::tuple<Vector<WebKit::ContentWorldIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveAllUserScriptMessageHandlersForWorlds; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveAllUserScriptMessageHandlersForWorlds(const Vector<WebKit::ContentWorldIdentifier>& worldIdentifiers)
        : m_worldIdentifiers(worldIdentifiers)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_worldIdentifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::ContentWorldIdentifier>& m_worldIdentifiers;
};

class RemoveAllUserScriptMessageHandlers {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveAllUserScriptMessageHandlers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveAllUserScriptMessageHandlers()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(CONTENT_EXTENSIONS)
class AddContentRuleLists {
public:
    using Arguments = std::tuple<Vector<std::pair<WebKit::WebCompiledContentRuleListData, URL>>>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_AddContentRuleLists; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddContentRuleLists(const Vector<std::pair<WebKit::WebCompiledContentRuleListData, URL>>& contentFilters)
        : m_contentFilters(contentFilters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contentFilters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::pair<WebKit::WebCompiledContentRuleListData, URL>>& m_contentFilters;
};
#endif

#if ENABLE(CONTENT_EXTENSIONS)
class RemoveContentRuleList {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveContentRuleList; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveContentRuleList(const String& name)
        : m_name(name)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
    }

private:
    const String& m_name;
};
#endif

#if ENABLE(CONTENT_EXTENSIONS)
class RemoveAllContentRuleLists {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebUserContentController_RemoveAllContentRuleLists; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemoveAllContentRuleLists()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

} // namespace WebUserContentController
} // namespace Messages
