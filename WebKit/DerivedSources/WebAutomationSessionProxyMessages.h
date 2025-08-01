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
#include <WebCore/ShareableBitmapHandle.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class FloatRect;
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
class IntPoint;
class IntRect;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
}

namespace WebKit {
enum class CoordinateSystem : uint8_t;
}

namespace Messages {
namespace WebAutomationSessionProxy {

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
    return IPC::ReceiverName::WebAutomationSessionProxy;
}

class EvaluateJavaScriptFunction {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String, Vector<String>, bool, bool, std::optional<double>>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_EvaluateJavaScriptFunction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_EvaluateJavaScriptFunctionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, String>;
    using Reply = CompletionHandler<void(String&&, String&&)>;
    using Promise = WTF::NativePromise<std::tuple<String, String>, IPC::Error>;
    EvaluateJavaScriptFunction(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& function, const Vector<String>& arguments, bool expectsImplicitCallbackArgument, bool forceUserGesture, const std::optional<double>& callbackTimeout)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_function(function)
        , m_arguments(arguments)
        , m_expectsImplicitCallbackArgument(expectsImplicitCallbackArgument)
        , m_forceUserGesture(forceUserGesture)
        , m_callbackTimeout(callbackTimeout)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_function;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_arguments;
        encoder << m_expectsImplicitCallbackArgument;
        encoder << m_forceUserGesture;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_callbackTimeout;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_function;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_arguments;
    bool m_expectsImplicitCallbackArgument;
    bool m_forceUserGesture;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<double>& m_callbackTimeout;
};

class ResolveChildFrameWithOrdinal {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_ResolveChildFrameWithOrdinal; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_ResolveChildFrameWithOrdinalReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, std::optional<WebCore::FrameIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<String>&&, std::optional<WebCore::FrameIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, std::optional<WebCore::FrameIdentifier>>, IPC::Error>;
    ResolveChildFrameWithOrdinal(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, uint32_t ordinal)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_ordinal(ordinal)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_ordinal;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    uint32_t m_ordinal;
};

class ResolveChildFrameWithNodeHandle {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_ResolveChildFrameWithNodeHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_ResolveChildFrameWithNodeHandleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, std::optional<WebCore::FrameIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<String>&&, std::optional<WebCore::FrameIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, std::optional<WebCore::FrameIdentifier>>, IPC::Error>;
    ResolveChildFrameWithNodeHandle(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& nodeHandle)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_nodeHandle(nodeHandle)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_nodeHandle;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_nodeHandle;
};

class ResolveChildFrameWithName {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_ResolveChildFrameWithName; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_ResolveChildFrameWithNameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, std::optional<WebCore::FrameIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<String>&&, std::optional<WebCore::FrameIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, std::optional<WebCore::FrameIdentifier>>, IPC::Error>;
    ResolveChildFrameWithName(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& name)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_name(name)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_name;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_name;
};

class ResolveParentFrame {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_ResolveParentFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_ResolveParentFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, std::optional<WebCore::FrameIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<String>&&, std::optional<WebCore::FrameIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, std::optional<WebCore::FrameIdentifier>>, IPC::Error>;
    ResolveParentFrame(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID)
        : m_pageID(pageID)
        , m_frameID(frameID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
};

class FocusFrame {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_FocusFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_FocusFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>>;
    using Reply = CompletionHandler<void(std::optional<String>&&)>;
    using Promise = WTF::NativePromise<std::optional<String>, IPC::Error>;
    FocusFrame(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID)
        : m_pageID(pageID)
        , m_frameID(frameID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
};

class ComputeElementLayout {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String, bool, WebKit::CoordinateSystem>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_ComputeElementLayout; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_ComputeElementLayoutReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, WebCore::FloatRect, std::optional<WebCore::IntPoint>, bool>;
    using Reply = CompletionHandler<void(std::optional<String>&&, WebCore::FloatRect&&, std::optional<WebCore::IntPoint>&&, bool)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, WebCore::FloatRect, std::optional<WebCore::IntPoint>, bool>, IPC::Error>;
    ComputeElementLayout(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& nodeHandle, bool scrollIntoViewIfNeeded, WebKit::CoordinateSystem coordinateSystem)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_nodeHandle(nodeHandle)
        , m_scrollIntoViewIfNeeded(scrollIntoViewIfNeeded)
        , m_coordinateSystem(coordinateSystem)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_nodeHandle;
        encoder << m_scrollIntoViewIfNeeded;
        encoder << m_coordinateSystem;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_nodeHandle;
    bool m_scrollIntoViewIfNeeded;
    WebKit::CoordinateSystem m_coordinateSystem;
};

class GetComputedRole {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_GetComputedRole; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_GetComputedRoleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, std::optional<String>>;
    using Reply = CompletionHandler<void(std::optional<String>&&, std::optional<String>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, std::optional<String>>, IPC::Error>;
    GetComputedRole(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& nodeHandle)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_nodeHandle(nodeHandle)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_nodeHandle;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_nodeHandle;
};

class GetComputedLabel {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_GetComputedLabel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_GetComputedLabelReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, std::optional<String>>;
    using Reply = CompletionHandler<void(std::optional<String>&&, std::optional<String>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, std::optional<String>>, IPC::Error>;
    GetComputedLabel(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& nodeHandle)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_nodeHandle(nodeHandle)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_nodeHandle;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_nodeHandle;
};

class SelectOptionElement {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_SelectOptionElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_SelectOptionElementReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>>;
    using Reply = CompletionHandler<void(std::optional<String>&&)>;
    using Promise = WTF::NativePromise<std::optional<String>, IPC::Error>;
    SelectOptionElement(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& nodeHandle)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_nodeHandle(nodeHandle)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_nodeHandle;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_nodeHandle;
};

class SetFilesForInputFileUpload {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_SetFilesForInputFileUpload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_SetFilesForInputFileUploadReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>>;
    using Reply = CompletionHandler<void(std::optional<String>&&)>;
    using Promise = WTF::NativePromise<std::optional<String>, IPC::Error>;
    SetFilesForInputFileUpload(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& nodeHandle, const Vector<String>& filenames)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_nodeHandle(nodeHandle)
        , m_filenames(filenames)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_nodeHandle;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_filenames;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_nodeHandle;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_filenames;
};

class TakeScreenshot {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_TakeScreenshot; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_TakeScreenshotReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>, String>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&, String&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::ShareableBitmapHandle>, String>, IPC::Error>;
    TakeScreenshot(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& nodeHandle, bool scrollIntoViewIfNeeded, bool clipToViewport)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_nodeHandle(nodeHandle)
        , m_scrollIntoViewIfNeeded(scrollIntoViewIfNeeded)
        , m_clipToViewport(clipToViewport)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_nodeHandle;
        encoder << m_scrollIntoViewIfNeeded;
        encoder << m_clipToViewport;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_nodeHandle;
    bool m_scrollIntoViewIfNeeded;
    bool m_clipToViewport;
};

class SnapshotRectForScreenshot {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_SnapshotRectForScreenshot; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_SnapshotRectForScreenshotReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, WebCore::IntRect>;
    using Reply = CompletionHandler<void(std::optional<String>&&, WebCore::IntRect&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, WebCore::IntRect>, IPC::Error>;
    SnapshotRectForScreenshot(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& nodeHandle, bool scrollIntoViewIfNeeded, bool clipToViewport)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_nodeHandle(nodeHandle)
        , m_scrollIntoViewIfNeeded(scrollIntoViewIfNeeded)
        , m_clipToViewport(clipToViewport)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_nodeHandle;
        encoder << m_scrollIntoViewIfNeeded;
        encoder << m_clipToViewport;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_nodeHandle;
    bool m_scrollIntoViewIfNeeded;
    bool m_clipToViewport;
};

class GetCookiesForFrame {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_GetCookiesForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_GetCookiesForFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>, Vector<WebCore::Cookie>>;
    using Reply = CompletionHandler<void(std::optional<String>&&, Vector<WebCore::Cookie>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<String>, Vector<WebCore::Cookie>>, IPC::Error>;
    GetCookiesForFrame(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID)
        : m_pageID(pageID)
        , m_frameID(frameID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
};

class DeleteCookie {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, std::optional<WebCore::FrameIdentifier>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebAutomationSessionProxy_DeleteCookie; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebAutomationSessionProxy_DeleteCookieReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>>;
    using Reply = CompletionHandler<void(std::optional<String>&&)>;
    using Promise = WTF::NativePromise<std::optional<String>, IPC::Error>;
    DeleteCookie(const WebCore::PageIdentifier& pageID, const std::optional<WebCore::FrameIdentifier>& frameID, const String& cookieName)
        : m_pageID(pageID)
        , m_frameID(frameID)
        , m_cookieName(cookieName)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_cookieName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    const String& m_cookieName;
};

} // namespace WebAutomationSessionProxy
} // namespace Messages
