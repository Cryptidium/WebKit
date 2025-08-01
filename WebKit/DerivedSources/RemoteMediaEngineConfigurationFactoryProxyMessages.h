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
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
struct MediaCapabilitiesDecodingInfo;
struct MediaCapabilitiesEncodingInfo;
struct MediaDecodingConfiguration;
struct MediaEncodingConfiguration;
}

namespace Messages {
namespace RemoteMediaEngineConfigurationFactoryProxy {

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
    return IPC::ReceiverName::RemoteMediaEngineConfigurationFactoryProxy;
}

class CreateDecodingConfiguration {
public:
    using Arguments = std::tuple<WebCore::MediaDecodingConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaEngineConfigurationFactoryProxy_CreateDecodingConfiguration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaEngineConfigurationFactoryProxy_CreateDecodingConfigurationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::MediaCapabilitiesDecodingInfo>;
    using Reply = CompletionHandler<void(WebCore::MediaCapabilitiesDecodingInfo&&)>;
    using Promise = WTF::NativePromise<WebCore::MediaCapabilitiesDecodingInfo, IPC::Error>;
    explicit CreateDecodingConfiguration(const WebCore::MediaDecodingConfiguration& configuration)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaDecodingConfiguration& m_configuration;
};

class CreateEncodingConfiguration {
public:
    using Arguments = std::tuple<WebCore::MediaEncodingConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteMediaEngineConfigurationFactoryProxy_CreateEncodingConfiguration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteMediaEngineConfigurationFactoryProxy_CreateEncodingConfigurationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::MediaCapabilitiesEncodingInfo>;
    using Reply = CompletionHandler<void(WebCore::MediaCapabilitiesEncodingInfo&&)>;
    using Promise = WTF::NativePromise<WebCore::MediaCapabilitiesEncodingInfo, IPC::Error>;
    explicit CreateEncodingConfiguration(const WebCore::MediaEncodingConfiguration& configuration)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaEncodingConfiguration& m_configuration;
};

} // namespace RemoteMediaEngineConfigurationFactoryProxy
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
