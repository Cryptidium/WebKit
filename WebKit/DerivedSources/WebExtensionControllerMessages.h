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
#include "MessageNames.h"
#include "WebExtensionFrameParameters.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebKit {
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
}

namespace Messages {
namespace WebExtensionController {

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
    return IPC::ReceiverName::WebExtensionController;
}

class DidStartProvisionalLoadForFrame {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionFrameParameters, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_DidStartProvisionalLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStartProvisionalLoadForFrame(const WebKit::WebPageProxyIdentifier& pageID, const WebKit::WebExtensionFrameParameters& frameParameters, const WallTime& timestamp)
        : m_pageID(pageID)
        , m_frameParameters(frameParameters)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_frameParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    const WebKit::WebExtensionFrameParameters& m_frameParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class DidCommitLoadForFrame {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionFrameParameters, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_DidCommitLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCommitLoadForFrame(const WebKit::WebPageProxyIdentifier& pageID, const WebKit::WebExtensionFrameParameters& frameParameters, const WallTime& timestamp)
        : m_pageID(pageID)
        , m_frameParameters(frameParameters)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_frameParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    const WebKit::WebExtensionFrameParameters& m_frameParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class DidFinishLoadForFrame {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionFrameParameters, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_DidFinishLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishLoadForFrame(const WebKit::WebPageProxyIdentifier& pageID, const WebKit::WebExtensionFrameParameters& frameParameters, const WallTime& timestamp)
        : m_pageID(pageID)
        , m_frameParameters(frameParameters)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_frameParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    const WebKit::WebExtensionFrameParameters& m_frameParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class DidFailLoadForFrame {
public:
    using Arguments = std::tuple<WebKit::WebPageProxyIdentifier, WebKit::WebExtensionFrameParameters, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_DidFailLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFailLoadForFrame(const WebKit::WebPageProxyIdentifier& pageID, const WebKit::WebExtensionFrameParameters& frameParameters, const WallTime& timestamp)
        : m_pageID(pageID)
        , m_frameParameters(frameParameters)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_frameParameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    const WebKit::WebExtensionFrameParameters& m_frameParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class TestResult {
public:
    using Arguments = std::tuple<bool, String, String, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_TestResult; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TestResult(bool result, const String& message, const String& sourceURL, const unsigned& lineNumber)
        : m_result(result)
        , m_message(message)
        , m_sourceURL(sourceURL)
        , m_lineNumber(lineNumber)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_result;
        encoder << m_message;
        encoder << m_sourceURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
    }

private:
    bool m_result;
    const String& m_message;
    const String& m_sourceURL;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_lineNumber;
};

class TestEqual {
public:
    using Arguments = std::tuple<bool, String, String, String, String, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_TestEqual; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TestEqual(bool result, const String& expected, const String& actual, const String& message, const String& sourceURL, const unsigned& lineNumber)
        : m_result(result)
        , m_expected(expected)
        , m_actual(actual)
        , m_message(message)
        , m_sourceURL(sourceURL)
        , m_lineNumber(lineNumber)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_result;
        encoder << m_expected;
        encoder << m_actual;
        encoder << m_message;
        encoder << m_sourceURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
    }

private:
    bool m_result;
    const String& m_expected;
    const String& m_actual;
    const String& m_message;
    const String& m_sourceURL;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_lineNumber;
};

class TestLogMessage {
public:
    using Arguments = std::tuple<String, String, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_TestLogMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TestLogMessage(const String& message, const String& sourceURL, const unsigned& lineNumber)
        : m_message(message)
        , m_sourceURL(sourceURL)
        , m_lineNumber(lineNumber)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_sourceURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
    }

private:
    const String& m_message;
    const String& m_sourceURL;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_lineNumber;
};

class TestSentMessage {
public:
    using Arguments = std::tuple<String, String, String, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_TestSentMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TestSentMessage(const String& message, const String& argument, const String& sourceURL, const unsigned& lineNumber)
        : m_message(message)
        , m_argument(argument)
        , m_sourceURL(sourceURL)
        , m_lineNumber(lineNumber)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_argument;
        encoder << m_sourceURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
    }

private:
    const String& m_message;
    const String& m_argument;
    const String& m_sourceURL;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_lineNumber;
};

class TestAdded {
public:
    using Arguments = std::tuple<String, String, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_TestAdded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TestAdded(const String& testName, const String& sourceURL, const unsigned& lineNumber)
        : m_testName(testName)
        , m_sourceURL(sourceURL)
        , m_lineNumber(lineNumber)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_testName;
        encoder << m_sourceURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
    }

private:
    const String& m_testName;
    const String& m_sourceURL;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_lineNumber;
};

class TestStarted {
public:
    using Arguments = std::tuple<String, String, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_TestStarted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TestStarted(const String& testName, const String& sourceURL, const unsigned& lineNumber)
        : m_testName(testName)
        , m_sourceURL(sourceURL)
        , m_lineNumber(lineNumber)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_testName;
        encoder << m_sourceURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
    }

private:
    const String& m_testName;
    const String& m_sourceURL;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_lineNumber;
};

class TestFinished {
public:
    using Arguments = std::tuple<String, bool, String, String, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebExtensionController_TestFinished; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TestFinished(const String& testName, bool result, const String& message, const String& sourceURL, const unsigned& lineNumber)
        : m_testName(testName)
        , m_result(result)
        , m_message(message)
        , m_sourceURL(sourceURL)
        , m_lineNumber(lineNumber)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_testName;
        encoder << m_result;
        encoder << m_message;
        encoder << m_sourceURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lineNumber;
    }

private:
    const String& m_testName;
    bool m_result;
    const String& m_message;
    const String& m_sourceURL;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_lineNumber;
};

} // namespace WebExtensionController
} // namespace Messages

#endif // ENABLE(WK_WEB_EXTENSIONS)
