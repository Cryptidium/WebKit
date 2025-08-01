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

#if ENABLE(GPU_PROCESS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include "WebGPUCanvasConfiguration.h"
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebKit {
struct WebGPUIdentifierType;
using WebGPUIdentifier = AtomicObjectIdentifier<WebGPUIdentifierType>;
}

namespace Messages {
namespace RemotePresentationContext {

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
    return IPC::ReceiverName::RemotePresentationContext;
}

class Configure {
public:
    using Arguments = std::tuple<WebKit::WebGPU::CanvasConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::RemotePresentationContext_Configure; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit Configure(const WebKit::WebGPU::CanvasConfiguration& configuration)
        : m_configuration(configuration)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_configuration;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::CanvasConfiguration& m_configuration;
};

class Unconfigure {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemotePresentationContext_Unconfigure; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Unconfigure()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetCurrentTexture {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemotePresentationContext_GetCurrentTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    GetCurrentTexture(const WebKit::WebGPUIdentifier& identifier, uint32_t frameIndex)
        : m_identifier(identifier)
        , m_frameIndex(frameIndex)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_frameIndex;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
    uint32_t m_frameIndex;
};

class Present {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::RemotePresentationContext_Present; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit Present(uint32_t frameIndex)
        : m_frameIndex(frameIndex)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_frameIndex;
    }

private:
    uint32_t m_frameIndex;
};

} // namespace RemotePresentationContext
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
