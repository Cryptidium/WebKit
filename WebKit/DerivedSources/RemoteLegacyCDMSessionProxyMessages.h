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

#if ENABLE(GPU_PROCESS) && ENABLE(LEGACY_ENCRYPTED_MEDIA)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <wtf/Forward.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>


namespace Messages {
namespace RemoteLegacyCDMSessionProxy {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInGPUProcess());
        }
    );
#endif
    return IPC::ReceiverName::RemoteLegacyCDMSessionProxy;
}

class GenerateKeyRequest {
public:
    using Arguments = std::tuple<String, RefPtr<WebCore::SharedBuffer>, String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMSessionProxy_GenerateKeyRequest; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>, String, unsigned short, uint32_t>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&, String&&, unsigned short&&, uint32_t)>;
    GenerateKeyRequest(const String& mimeType, const RefPtr<WebCore::SharedBuffer>& initData, const String& mediaKeysHashSalt)
        : m_mimeType(mimeType)
        , m_initData(initData)
        , m_mediaKeysHashSalt(mediaKeysHashSalt)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mimeType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initData;
        encoder << m_mediaKeysHashSalt;
    }

private:
    const String& m_mimeType;
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::SharedBuffer>& m_initData;
    const String& m_mediaKeysHashSalt;
};

class ReleaseKeys {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMSessionProxy_ReleaseKeys; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReleaseKeys()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Update {
public:
    using Arguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMSessionProxy_Update; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, RefPtr<WebCore::SharedBuffer>, unsigned short, uint32_t>;
    using Reply = CompletionHandler<void(bool, RefPtr<WebCore::SharedBuffer>&&, unsigned short&&, uint32_t)>;
    explicit Update(const RefPtr<WebCore::SharedBuffer>& update)
        : m_update(update)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_update;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::SharedBuffer>& m_update;
};

class CachedKeyForKeyID {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteLegacyCDMSessionProxy_CachedKeyForKeyID; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&)>;
    explicit CachedKeyForKeyID(const String& keyId)
        : m_keyId(keyId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_keyId;
    }

private:
    const String& m_keyId;
};

} // namespace RemoteLegacyCDMSessionProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS) && ENABLE(LEGACY_ENCRYPTED_MEDIA)
