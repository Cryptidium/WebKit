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
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
struct DebuggableInfoData;
}

namespace Messages {
namespace WebInspectorUI {

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
    return IPC::ReceiverName::WebInspectorUI;
}

class EstablishConnection {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::DebuggableInfoData, bool, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_EstablishConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EstablishConnection(const WebKit::WebPageProxyIdentifier& inspectedPageIdentifier, const WebKit::DebuggableInfoData& debuggableInfo, bool underTest, const unsigned& inspectionLevel)
        : m_inspectedPageIdentifier(inspectedPageIdentifier)
        , m_debuggableInfo(debuggableInfo)
        , m_underTest(underTest)
        , m_inspectionLevel(inspectionLevel)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_inspectedPageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_debuggableInfo;
        encoder << m_underTest;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_inspectionLevel;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_inspectedPageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DebuggableInfoData& m_debuggableInfo;
    bool m_underTest;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_inspectionLevel;
};

class UpdateConnection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_UpdateConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateConnection()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class AttachedBottom {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_AttachedBottom; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AttachedBottom()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class AttachedRight {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_AttachedRight; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AttachedRight()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class AttachedLeft {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_AttachedLeft; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AttachedLeft()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Detached {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_Detached; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Detached()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetDockingUnavailable {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_SetDockingUnavailable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDockingUnavailable(bool unavailable)
        : m_unavailable(unavailable)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_unavailable;
    }

private:
    bool m_unavailable;
};

class SetIsVisible {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_SetIsVisible; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIsVisible(bool visible)
        : m_visible(visible)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_visible;
    }

private:
    bool m_visible;
};

class UpdateFindString {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_UpdateFindString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateFindString(const String& findString)
        : m_findString(findString)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_findString;
    }

private:
    const String& m_findString;
};

#if ENABLE(INSPECTOR_TELEMETRY)
class SetDiagnosticLoggingAvailable {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_SetDiagnosticLoggingAvailable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDiagnosticLoggingAvailable(bool available)
        : m_available(available)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_available;
    }

private:
    bool m_available;
};
#endif

class ShowConsole {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_ShowConsole; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowConsole()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ShowResources {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_ShowResources; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowResources()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ShowMainResourceForFrame {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_ShowMainResourceForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ShowMainResourceForFrame(const String& frameIdentifier)
        : m_frameIdentifier(frameIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_frameIdentifier;
    }

private:
    const String& m_frameIdentifier;
};

class StartPageProfiling {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_StartPageProfiling; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartPageProfiling()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StopPageProfiling {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_StopPageProfiling; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopPageProfiling()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StartElementSelection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_StartElementSelection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartElementSelection()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StopElementSelection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_StopElementSelection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopElementSelection()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SendMessageToFrontend {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_SendMessageToFrontend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendMessageToFrontend(const String& message)
        : m_message(message)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
    }

private:
    const String& m_message;
};

class EvaluateInFrontendForTesting {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebInspectorUI_EvaluateInFrontendForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit EvaluateInFrontendForTesting(const String& expression)
        : m_expression(expression)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_expression;
    }

private:
    const String& m_expression;
};

} // namespace WebInspectorUI
} // namespace Messages
