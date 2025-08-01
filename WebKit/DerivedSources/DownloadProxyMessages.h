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
#include <span>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class AuthenticationChallenge;
class ResourceError;
class ResourceRequest;
class ResourceResponse;
}

namespace WebKit {
struct AuthenticationChallengeIdentifierType;
using AuthenticationChallengeIdentifier = ObjectIdentifier<AuthenticationChallengeIdentifierType>;
enum class AllowOverwrite : bool;
enum class UseDownloadPlaceholder : bool;
}

namespace Messages {
namespace DownloadProxy {

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
    return IPC::ReceiverName::DownloadProxy;
}

class DidStart {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest, String>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidStart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStart(const WebCore::ResourceRequest& request, const String& suggestedFilename)
        : m_request(request)
        , m_suggestedFilename(suggestedFilename)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        encoder << m_suggestedFilename;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    const String& m_suggestedFilename;
};

class DidReceiveAuthenticationChallenge {
public:
    using Arguments = std::tuple<WebCore::AuthenticationChallenge, WebKit::AuthenticationChallengeIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidReceiveAuthenticationChallenge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveAuthenticationChallenge(const WebCore::AuthenticationChallenge& challenge, const WebKit::AuthenticationChallengeIdentifier& challengeID)
        : m_challenge(challenge)
        , m_challengeID(challengeID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_challenge;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_challengeID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AuthenticationChallenge& m_challenge;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AuthenticationChallengeIdentifier& m_challengeID;
};

class WillSendRequest {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_WillSendRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::DownloadProxy_WillSendRequestReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ResourceRequest>;
    using Reply = CompletionHandler<void(WebCore::ResourceRequest&&)>;
    using Promise = WTF::NativePromise<WebCore::ResourceRequest, IPC::Error>;
    WillSendRequest(const WebCore::ResourceRequest& redirectRequest, const WebCore::ResourceResponse& redirectResponse)
        : m_redirectRequest(redirectRequest)
        , m_redirectResponse(redirectResponse)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectRequest;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectResponse;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_redirectRequest;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_redirectResponse;
};

class DecideDestinationWithSuggestedFilename {
public:
    using Arguments = std::tuple<WebCore::ResourceResponse, String>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DecideDestinationWithSuggestedFilename; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::DownloadProxy_DecideDestinationWithSuggestedFilenameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, WebKit::SandboxExtensionHandle, WebKit::AllowOverwrite, WebKit::UseDownloadPlaceholder, URL, WebKit::SandboxExtensionHandle, std::span<const uint8_t>, std::span<const uint8_t>>;
    using Reply = CompletionHandler<void(String&&, WebKit::SandboxExtensionHandle&&, WebKit::AllowOverwrite, WebKit::UseDownloadPlaceholder, URL&&, WebKit::SandboxExtensionHandle&&, std::span<const uint8_t>&&, std::span<const uint8_t>&&)>;
    using Promise = WTF::NativePromise<std::tuple<String, WebKit::SandboxExtensionHandle, WebKit::AllowOverwrite, WebKit::UseDownloadPlaceholder, URL, WebKit::SandboxExtensionHandle, std::span<const uint8_t>, std::span<const uint8_t>>, IPC::Error>;
    DecideDestinationWithSuggestedFilename(const WebCore::ResourceResponse& response, const String& suggestedFilename)
        : m_response(response)
        , m_suggestedFilename(suggestedFilename)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        encoder << m_suggestedFilename;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    const String& m_suggestedFilename;
};

class DidReceiveData {
public:
    using Arguments = std::tuple<uint64_t, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidReceiveData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveData(uint64_t bytesWritten, uint64_t totalBytesWritten, uint64_t totalBytesExpectedToWrite)
        : m_bytesWritten(bytesWritten)
        , m_totalBytesWritten(totalBytesWritten)
        , m_totalBytesExpectedToWrite(totalBytesExpectedToWrite)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_bytesWritten;
        encoder << m_totalBytesWritten;
        encoder << m_totalBytesExpectedToWrite;
    }

private:
    uint64_t m_bytesWritten;
    uint64_t m_totalBytesWritten;
    uint64_t m_totalBytesExpectedToWrite;
};

class DidCreateDestination {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidCreateDestination; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidCreateDestination(const String& path)
        : m_path(path)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_path;
    }

private:
    const String& m_path;
};

class DidFinish {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidFinish; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinish()
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidFail {
public:
    using Arguments = std::tuple<WebCore::ResourceError, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidFail; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFail(const WebCore::ResourceError& error, const std::span<const uint8_t>& resumeData)
        : m_error(error)
        , m_resumeData(resumeData)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resumeData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_resumeData;
};

#if HAVE(MODERN_DOWNLOADPROGRESS)
class DidReceivePlaceholderURL {
public:
    using Arguments = std::tuple<URL, std::span<const uint8_t>, WebKit::SandboxExtensionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidReceivePlaceholderURL; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::DownloadProxy_DidReceivePlaceholderURLReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DidReceivePlaceholderURL(const URL& placeholderURL, const std::span<const uint8_t>& bookmarkData, WebKit::SandboxExtensionHandle&& handle)
        : m_placeholderURL(placeholderURL)
        , m_bookmarkData(bookmarkData)
        , m_handle(WTFMove(handle))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_placeholderURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bookmarkData;
        encoder << WTFMove(m_handle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_placeholderURL;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_bookmarkData;
    WebKit::SandboxExtensionHandle&& m_handle;
};
#endif

#if HAVE(MODERN_DOWNLOADPROGRESS)
class DidReceiveFinalURL {
public:
    using Arguments = std::tuple<URL, std::span<const uint8_t>, WebKit::SandboxExtensionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidReceiveFinalURL; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveFinalURL(const URL& finalURL, const std::span<const uint8_t>& bookmarkData, WebKit::SandboxExtensionHandle&& handle)
        : m_finalURL(finalURL)
        , m_bookmarkData(bookmarkData)
        , m_handle(WTFMove(handle))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_finalURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bookmarkData;
        encoder << WTFMove(m_handle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_finalURL;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_bookmarkData;
    WebKit::SandboxExtensionHandle&& m_handle;
};
#endif

#if HAVE(MODERN_DOWNLOADPROGRESS)
class DidStartUpdatingProgress {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::DownloadProxy_DidStartUpdatingProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStartUpdatingProgress()
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

} // namespace DownloadProxy
} // namespace Messages
