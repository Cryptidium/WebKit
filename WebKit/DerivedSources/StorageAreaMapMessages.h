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
struct StorageAreaImplIdentifierType;
using StorageAreaImplIdentifier = ObjectIdentifier<StorageAreaImplIdentifierType>;
}

namespace Messages {
namespace StorageAreaMap {

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
    return IPC::ReceiverName::StorageAreaMap;
}

class DispatchStorageEvent {
public:
    using Arguments = std::tuple<std::optional<WebKit::StorageAreaImplIdentifier>, String, String, String, String, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::StorageAreaMap_DispatchStorageEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DispatchStorageEvent(const std::optional<WebKit::StorageAreaImplIdentifier>& storageAreaImplID, const String& key, const String& oldValue, const String& newValue, const String& urlString, uint64_t messageIdentifier)
        : m_storageAreaImplID(storageAreaImplID)
        , m_key(key)
        , m_oldValue(oldValue)
        , m_newValue(newValue)
        , m_urlString(urlString)
        , m_messageIdentifier(messageIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_storageAreaImplID;
        encoder << m_key;
        encoder << m_oldValue;
        encoder << m_newValue;
        encoder << m_urlString;
        encoder << m_messageIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::StorageAreaImplIdentifier>& m_storageAreaImplID;
    const String& m_key;
    const String& m_oldValue;
    const String& m_newValue;
    const String& m_urlString;
    uint64_t m_messageIdentifier;
};

class ClearCache {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::StorageAreaMap_ClearCache; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ClearCache(uint64_t messageIdentifier)
        : m_messageIdentifier(messageIdentifier)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_messageIdentifier;
    }

private:
    uint64_t m_messageIdentifier;
};

} // namespace StorageAreaMap
} // namespace Messages
