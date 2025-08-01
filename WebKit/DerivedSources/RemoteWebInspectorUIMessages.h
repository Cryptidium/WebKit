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
struct DebuggableInfoData;
}

namespace Messages {
namespace RemoteWebInspectorUI {

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
    return IPC::ReceiverName::RemoteWebInspectorUI;
}

class Initialize {
public:
    using Arguments = std::tuple<WebKit::DebuggableInfoData, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteWebInspectorUI_Initialize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Initialize(const WebKit::DebuggableInfoData& debuggableInfo, const String& backendCommandsURL)
        : m_debuggableInfo(debuggableInfo)
        , m_backendCommandsURL(backendCommandsURL)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_debuggableInfo;
        encoder << m_backendCommandsURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DebuggableInfoData& m_debuggableInfo;
    const String& m_backendCommandsURL;
};

class UpdateFindString {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteWebInspectorUI_UpdateFindString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateFindString(const String& findString)
        : m_findString(findString)
    {
        ASSERT(!isInAuxiliaryProcess());
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteWebInspectorUI_SetDiagnosticLoggingAvailable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDiagnosticLoggingAvailable(bool available)
        : m_available(available)
    {
        ASSERT(!isInAuxiliaryProcess());
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteWebInspectorUI_ShowConsole; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowConsole()
    {
        ASSERT(!isInAuxiliaryProcess());
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteWebInspectorUI_ShowResources; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowResources()
    {
        ASSERT(!isInAuxiliaryProcess());
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

    static IPC::MessageName name() { return IPC::MessageName::RemoteWebInspectorUI_SendMessageToFrontend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendMessageToFrontend(const String& message)
        : m_message(message)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
    }

private:
    const String& m_message;
};

} // namespace RemoteWebInspectorUI
} // namespace Messages
