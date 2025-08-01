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
#include "SandboxExtension.h"
#include <WebCore/Pasteboard.h>
#include <WebCore/SharedMemory.h>
#include <wtf/Forward.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class Color;
class SelectionData;
struct PasteboardBuffer;
struct PasteboardImage;
struct PasteboardItemInfo;
struct PasteboardURL;
struct PasteboardWebContent;
}

namespace WebKit {
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
}

namespace Messages {
namespace WebPasteboardProxy {

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
    return IPC::ReceiverName::WebPasteboardProxy;
}

#if PLATFORM(IOS_FAMILY)
class WriteURLToPasteboard {
public:
    using Arguments = std::tuple<WebCore::PasteboardURL, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_WriteURLToPasteboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WriteURLToPasteboard(const WebCore::PasteboardURL& url, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_url(url)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PasteboardURL& m_url;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class WriteWebContentToPasteboard {
public:
    using Arguments = std::tuple<WebCore::PasteboardWebContent, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_WriteWebContentToPasteboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WriteWebContentToPasteboard(const WebCore::PasteboardWebContent& content, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_content(content)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_content;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PasteboardWebContent& m_content;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class WriteImageToPasteboard {
public:
    using Arguments = std::tuple<WebCore::PasteboardImage, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_WriteImageToPasteboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WriteImageToPasteboard(const WebCore::PasteboardImage& pasteboardImage, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardImage(pasteboardImage)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pasteboardImage;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PasteboardImage& m_pasteboardImage;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class WriteStringToPasteboard {
public:
    using Arguments = std::tuple<String, String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_WriteStringToPasteboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WriteStringToPasteboard(const String& pasteboardType, const String& text, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardType(pasteboardType)
        , m_text(text)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardType;
        encoder << m_text;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardType;
    const String& m_text;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class UpdateSupportedTypeIdentifiers {
public:
    using Arguments = std::tuple<Vector<String>, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_UpdateSupportedTypeIdentifiers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateSupportedTypeIdentifiers(const Vector<String>& identifiers, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_identifiers(identifiers)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifiers;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_identifiers;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

class WriteCustomData {
public:
    using Arguments = std::tuple<Vector<WebCore::PasteboardCustomData>, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_WriteCustomData; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    WriteCustomData(const Vector<WebCore::PasteboardCustomData>& data, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_data(data)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::PasteboardCustomData>& m_data;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

class TypesSafeForDOMToReadAndWrite {
public:
    using Arguments = std::tuple<String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_TypesSafeForDOMToReadAndWrite; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    TypesSafeForDOMToReadAndWrite(const String& pasteboardName, const String& origin, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_origin(origin)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    const String& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

class AllPasteboardItemInfo {
public:
    using Arguments = std::tuple<String, int64_t, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_AllPasteboardItemInfo; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<WebCore::PasteboardItemInfo>>>;
    using Reply = CompletionHandler<void(std::optional<Vector<WebCore::PasteboardItemInfo>>&&)>;
    AllPasteboardItemInfo(const String& pasteboardName, int64_t changeCount, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_changeCount(changeCount)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_changeCount;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    int64_t m_changeCount;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

class InformationForItemAtIndex {
public:
    using Arguments = std::tuple<uint64_t, String, int64_t, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_InformationForItemAtIndex; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::PasteboardItemInfo>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::PasteboardItemInfo>&&)>;
    InformationForItemAtIndex(uint64_t index, const String& pasteboardName, int64_t changeCount, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_index(index)
        , m_pasteboardName(pasteboardName)
        , m_changeCount(changeCount)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_pasteboardName;
        encoder << m_changeCount;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    uint64_t m_index;
    const String& m_pasteboardName;
    int64_t m_changeCount;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

class GetPasteboardItemsCount {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardItemsCount; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    GetPasteboardItemsCount(const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

class ReadStringFromPasteboard {
public:
    using Arguments = std::tuple<uint64_t, String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ReadStringFromPasteboard; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    ReadStringFromPasteboard(uint64_t index, const String& pasteboardType, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_index(index)
        , m_pasteboardType(pasteboardType)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_pasteboardType;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    uint64_t m_index;
    const String& m_pasteboardType;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

class ReadURLFromPasteboard {
public:
    using Arguments = std::tuple<uint64_t, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ReadURLFromPasteboard; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, String>;
    using Reply = CompletionHandler<void(String&&, String&&)>;
    ReadURLFromPasteboard(uint64_t index, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_index(index)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    uint64_t m_index;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

class ReadBufferFromPasteboard {
public:
    using Arguments = std::tuple<std::optional<uint64_t>, String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ReadBufferFromPasteboard; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&)>;
    ReadBufferFromPasteboard(const std::optional<uint64_t>& index, const String& pasteboardType, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_index(index)
        , m_pasteboardType(pasteboardType)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_index;
        encoder << m_pasteboardType;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_index;
    const String& m_pasteboardType;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

class ContainsStringSafeForDOMToReadForType {
public:
    using Arguments = std::tuple<String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ContainsStringSafeForDOMToReadForType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    ContainsStringSafeForDOMToReadForType(const String& type, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_type(type)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_type;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};

#if PLATFORM(COCOA)
class GetNumberOfFiles {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetNumberOfFiles; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    GetNumberOfFiles(const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class GetPasteboardTypes {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardTypes; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    GetPasteboardTypes(const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class GetPasteboardPathnamesForType {
public:
    using Arguments = std::tuple<String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardPathnamesForType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>, Vector<WebKit::SandboxExtensionHandle>>;
    using Reply = CompletionHandler<void(Vector<String>&&, Vector<WebKit::SandboxExtensionHandle>&&)>;
    GetPasteboardPathnamesForType(const String& pasteboardName, const String& pasteboardType, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class GetPasteboardStringForType {
public:
    using Arguments = std::tuple<String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardStringForType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    GetPasteboardStringForType(const String& pasteboardName, const String& pasteboardType, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class GetPasteboardStringsForType {
public:
    using Arguments = std::tuple<String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardStringsForType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    GetPasteboardStringsForType(const String& pasteboardName, const String& pasteboardType, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class GetPasteboardBufferForType {
public:
    using Arguments = std::tuple<String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardBufferForType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::PasteboardBuffer>;
    using Reply = CompletionHandler<void(WebCore::PasteboardBuffer&&)>;
    GetPasteboardBufferForType(const String& pasteboardName, const String& pasteboardType, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class GetPasteboardChangeCount {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardChangeCount; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    GetPasteboardChangeCount(const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class GetPasteboardColor {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardColor; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::Color>;
    using Reply = CompletionHandler<void(WebCore::Color&&)>;
    GetPasteboardColor(const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class GetPasteboardURL {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardURL; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    GetPasteboardURL(const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class AddPasteboardTypes {
public:
    using Arguments = std::tuple<String, Vector<String>, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_AddPasteboardTypes; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    AddPasteboardTypes(const String& pasteboardName, const Vector<String>& pasteboardTypes, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardTypes(pasteboardTypes)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pasteboardTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_pasteboardTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class SetPasteboardTypes {
public:
    using Arguments = std::tuple<String, Vector<String>, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_SetPasteboardTypes; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    SetPasteboardTypes(const String& pasteboardName, const Vector<String>& pasteboardTypes, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardTypes(pasteboardTypes)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pasteboardTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_pasteboardTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class SetPasteboardURL {
public:
    using Arguments = std::tuple<WebCore::PasteboardURL, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_SetPasteboardURL; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    SetPasteboardURL(const WebCore::PasteboardURL& pasteboardURL, const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardURL(pasteboardURL)
        , m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pasteboardURL;
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PasteboardURL& m_pasteboardURL;
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class SetPasteboardColor {
public:
    using Arguments = std::tuple<String, WebCore::Color, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_SetPasteboardColor; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    SetPasteboardColor(const String& pasteboardName, const WebCore::Color& color, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_color(color)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class SetPasteboardStringForType {
public:
    using Arguments = std::tuple<String, String, String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_SetPasteboardStringForType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    SetPasteboardStringForType(const String& pasteboardName, const String& pasteboardType, const String& string, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
        , m_string(string)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
        encoder << m_string;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
    const String& m_string;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class SetPasteboardBufferForType {
public:
    using Arguments = std::tuple<String, String, RefPtr<WebCore::SharedBuffer>, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_SetPasteboardBufferForType; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    SetPasteboardBufferForType(const String& pasteboardName, const String& pasteboardType, const RefPtr<WebCore::SharedBuffer>& buffer, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
        , m_buffer(buffer)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_buffer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::SharedBuffer>& m_buffer;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class ContainsURLStringSuitableForLoading {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ContainsURLStringSuitableForLoading; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    ContainsURLStringSuitableForLoading(const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(COCOA)
class URLStringSuitableForLoading {
public:
    using Arguments = std::tuple<String, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_URLStringSuitableForLoading; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, String>;
    using Reply = CompletionHandler<void(String&&, String&&)>;
    URLStringSuitableForLoading(const String& pasteboardName, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if (PLATFORM(COCOA) && ENABLE(IPC_TESTING_API))
class TestIPCSharedMemory {
public:
    using Arguments = std::tuple<String, String, WebCore::SharedMemory::Handle, std::optional<WebKit::WebPageProxyIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_TestIPCSharedMemory; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t, String>;
    using Reply = CompletionHandler<void(int64_t, String&&)>;
    TestIPCSharedMemory(const String& pasteboardName, const String& pasteboardType, WebCore::SharedMemory::Handle&& handle, const std::optional<WebKit::WebPageProxyIdentifier>& pageID)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
        , m_handle(WTFMove(handle))
        , m_pageID(pageID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
        encoder << WTFMove(m_handle);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
    WebCore::SharedMemory::Handle&& m_handle;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebPageProxyIdentifier>& m_pageID;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class GetTypes {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetTypes; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    explicit GetTypes(const String& pasteboardName)
        : m_pasteboardName(pasteboardName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
    }

private:
    const String& m_pasteboardName;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class ReadText {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ReadText; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    ReadText(const String& pasteboardName, const String& pasteboardType)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class ReadFilePaths {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ReadFilePaths; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    explicit ReadFilePaths(const String& pasteboardName)
        : m_pasteboardName(pasteboardName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
    }

private:
    const String& m_pasteboardName;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class ReadBuffer {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ReadBuffer; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&)>;
    ReadBuffer(const String& pasteboardName, const String& pasteboardType)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardType(pasteboardType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << m_pasteboardType;
    }

private:
    const String& m_pasteboardName;
    const String& m_pasteboardType;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class WriteToClipboard {
public:
    using Arguments = std::tuple<String, WebCore::SelectionData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_WriteToClipboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WriteToClipboard(const String& pasteboardName, const WebCore::SelectionData& pasteboardContent)
        : m_pasteboardName(pasteboardName)
        , m_pasteboardContent(pasteboardContent)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pasteboardContent;
    }

private:
    const String& m_pasteboardName;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SelectionData& m_pasteboardContent;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class ClearClipboard {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_ClearClipboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ClearClipboard(const String& pasteboardName)
        : m_pasteboardName(pasteboardName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
    }

private:
    const String& m_pasteboardName;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class GetPasteboardChangeCount {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardChangeCount; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int64_t>;
    using Reply = CompletionHandler<void(int64_t)>;
    explicit GetPasteboardChangeCount(const String& pasteboardName)
        : m_pasteboardName(pasteboardName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
    }

private:
    const String& m_pasteboardName;
};
#endif

#if USE(LIBWPE) && !PLATFORM(WPE)
class GetPasteboardTypes {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_GetPasteboardTypes; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    GetPasteboardTypes()
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

#if USE(LIBWPE) && !PLATFORM(WPE)
class WriteWebContentToPasteboard {
public:
    using Arguments = std::tuple<WebCore::PasteboardWebContent>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_WriteWebContentToPasteboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit WriteWebContentToPasteboard(const WebCore::PasteboardWebContent& content)
        : m_content(content)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_content;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PasteboardWebContent& m_content;
};
#endif

#if USE(LIBWPE) && !PLATFORM(WPE)
class WriteStringToPasteboard {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPasteboardProxy_WriteStringToPasteboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WriteStringToPasteboard(const String& pasteboardType, const String& text)
        : m_pasteboardType(pasteboardType)
        , m_text(text)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardType;
        encoder << m_text;
    }

private:
    const String& m_pasteboardType;
    const String& m_text;
};
#endif

} // namespace WebPasteboardProxy
} // namespace Messages
