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
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace PAL {
class SessionID;
}

namespace WebCore {
enum class HTTPCookieAcceptPolicy : uint8_t;
struct Cookie;
}

namespace WebKit {
enum class SoupCookiePersistentStorageType : bool;
}

namespace Messages {
namespace WebCookieManager {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInNetworkProcess());
        }
    );
#endif
    return IPC::ReceiverName::WebCookieManager;
}

class GetHostnamesWithCookies {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_GetHostnamesWithCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_GetHostnamesWithCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    using Promise = WTF::NativePromise<Vector<String>, IPC::Error>;
    explicit GetHostnamesWithCookies(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class DeleteCookiesForHostnames {
public:
    using Arguments = std::tuple<PAL::SessionID, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_DeleteCookiesForHostnames; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_DeleteCookiesForHostnamesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteCookiesForHostnames(const PAL::SessionID& sessionID, const Vector<String>& hostnames)
        : m_sessionID(sessionID)
        , m_hostnames(hostnames)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_hostnames;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_hostnames;
};

class DeleteAllCookies {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_DeleteAllCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_DeleteAllCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit DeleteAllCookies(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class SetCookie {
public:
    using Arguments = std::tuple<PAL::SessionID, Vector<WebCore::Cookie>, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_SetCookie; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_SetCookieReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetCookie(const PAL::SessionID& sessionID, const Vector<WebCore::Cookie>& cookie, uint64_t cookiesVersion)
        : m_sessionID(sessionID)
        , m_cookie(cookie)
        , m_cookiesVersion(cookiesVersion)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookie;
        encoder << m_cookiesVersion;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::Cookie>& m_cookie;
    uint64_t m_cookiesVersion;
};

class SetCookies {
public:
    using Arguments = std::tuple<PAL::SessionID, Vector<WebCore::Cookie>, URL, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_SetCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_SetCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetCookies(const PAL::SessionID& sessionID, const Vector<WebCore::Cookie>& cookies, const URL& url, const URL& mainDocumentURL)
        : m_sessionID(sessionID)
        , m_cookies(cookies)
        , m_url(url)
        , m_mainDocumentURL(mainDocumentURL)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookies;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mainDocumentURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::Cookie>& m_cookies;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_mainDocumentURL;
};

class GetAllCookies {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_GetAllCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_GetAllCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::Cookie>>;
    using Reply = CompletionHandler<void(Vector<WebCore::Cookie>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::Cookie>, IPC::Error>;
    explicit GetAllCookies(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class GetCookies {
public:
    using Arguments = std::tuple<PAL::SessionID, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_GetCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_GetCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::Cookie>>;
    using Reply = CompletionHandler<void(Vector<WebCore::Cookie>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::Cookie>, IPC::Error>;
    GetCookies(const PAL::SessionID& sessionID, const URL& url)
        : m_sessionID(sessionID)
        , m_url(url)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class DeleteCookie {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::Cookie>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_DeleteCookie; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_DeleteCookieReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteCookie(const PAL::SessionID& sessionID, const WebCore::Cookie& cookie)
        : m_sessionID(sessionID)
        , m_cookie(cookie)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookie;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Cookie& m_cookie;
};

class DeleteAllCookiesModifiedSince {
public:
    using Arguments = std::tuple<PAL::SessionID, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_DeleteAllCookiesModifiedSince; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_DeleteAllCookiesModifiedSinceReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteAllCookiesModifiedSince(const PAL::SessionID& sessionID, const WallTime& time)
        : m_sessionID(sessionID)
        , m_time(time)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_time;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_time;
};

class SetHTTPCookieAcceptPolicy {
public:
    using Arguments = std::tuple<PAL::SessionID, WebCore::HTTPCookieAcceptPolicy>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_SetHTTPCookieAcceptPolicy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_SetHTTPCookieAcceptPolicyReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetHTTPCookieAcceptPolicy(const PAL::SessionID& sessionID, WebCore::HTTPCookieAcceptPolicy policy)
        : m_sessionID(sessionID)
        , m_policy(policy)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_policy;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    WebCore::HTTPCookieAcceptPolicy m_policy;
};

class GetHTTPCookieAcceptPolicy {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_GetHTTPCookieAcceptPolicy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_GetHTTPCookieAcceptPolicyReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::HTTPCookieAcceptPolicy>;
    using Reply = CompletionHandler<void(WebCore::HTTPCookieAcceptPolicy)>;
    using Promise = WTF::NativePromise<WebCore::HTTPCookieAcceptPolicy, IPC::Error>;
    explicit GetHTTPCookieAcceptPolicy(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class StartObservingCookieChanges {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_StartObservingCookieChanges; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StartObservingCookieChanges(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

class StopObservingCookieChanges {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_StopObservingCookieChanges; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StopObservingCookieChanges(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

#if USE(SOUP)
class ReplaceCookies {
public:
    using Arguments = std::tuple<PAL::SessionID, Vector<WebCore::Cookie>>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_ReplaceCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebCookieManager_ReplaceCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ReplaceCookies(const PAL::SessionID& sessionID, const Vector<WebCore::Cookie>& cookies)
        : m_sessionID(sessionID)
        , m_cookies(cookies)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cookies;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::Cookie>& m_cookies;
};
#endif

#if USE(SOUP)
class SetCookiePersistentStorage {
public:
    using Arguments = std::tuple<PAL::SessionID, String, WebKit::SoupCookiePersistentStorageType>;

    static IPC::MessageName name() { return IPC::MessageName::WebCookieManager_SetCookiePersistentStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetCookiePersistentStorage(const PAL::SessionID& sessionID, const String& storagePath, WebKit::SoupCookiePersistentStorageType storageType)
        : m_sessionID(sessionID)
        , m_storagePath(storagePath)
        , m_storageType(storageType)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << m_storagePath;
        encoder << m_storageType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    const String& m_storagePath;
    WebKit::SoupCookiePersistentStorageType m_storageType;
};
#endif

} // namespace WebCookieManager
} // namespace Messages
