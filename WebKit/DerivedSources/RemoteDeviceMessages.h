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
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "WebGPUBindGroupDescriptor.h"
#include "WebGPUBindGroupLayoutDescriptor.h"
#include "WebGPUBufferDescriptor.h"
#include "WebGPUCommandEncoderDescriptor.h"
#include "WebGPUComputePipelineDescriptor.h"
#include "WebGPUError.h"
#include "WebGPUExternalTextureDescriptor.h"
#include "WebGPUPipelineLayoutDescriptor.h"
#include "WebGPUQuerySetDescriptor.h"
#include "WebGPURenderBundleEncoderDescriptor.h"
#include "WebGPURenderPipelineDescriptor.h"
#include "WebGPUSamplerDescriptor.h"
#include "WebGPUShaderModuleDescriptor.h"
#include "WebGPUTextureDescriptor.h"
#include <WebCore/SharedMemory.h>
#include <WebCore/WebGPUDeviceLostReason.h>
#include <WebCore/WebGPUErrorFilter.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct MediaPlayerIdentifierType;
using MediaPlayerIdentifier = ObjectIdentifier<MediaPlayerIdentifierType>;
}

namespace WebKit {
struct WebGPUIdentifierType;
using WebGPUIdentifier = AtomicObjectIdentifier<WebGPUIdentifierType>;
}

namespace Messages {
namespace RemoteDevice {

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
    return IPC::ReceiverName::RemoteDevice;
}

class Destroy {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_Destroy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Destroy()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Destruct {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_Destruct; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    Destruct()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CreateXRBinding {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateXRBinding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit CreateXRBinding(const WebKit::WebGPUIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateBuffer {
public:
    using Arguments = std::tuple<WebKit::WebGPU::BufferDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateBuffer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateBuffer(const WebKit::WebGPU::BufferDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::BufferDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateTexture {
public:
    using Arguments = std::tuple<WebKit::WebGPU::TextureDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateTexture(const WebKit::WebGPU::TextureDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::TextureDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateSampler {
public:
    using Arguments = std::tuple<WebKit::WebGPU::SamplerDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateSampler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateSampler(const WebKit::WebGPU::SamplerDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::SamplerDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateBindGroupLayout {
public:
    using Arguments = std::tuple<WebKit::WebGPU::BindGroupLayoutDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateBindGroupLayout; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateBindGroupLayout(const WebKit::WebGPU::BindGroupLayoutDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::BindGroupLayoutDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreatePipelineLayout {
public:
    using Arguments = std::tuple<WebKit::WebGPU::PipelineLayoutDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreatePipelineLayout; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreatePipelineLayout(const WebKit::WebGPU::PipelineLayoutDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::PipelineLayoutDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateBindGroup {
public:
    using Arguments = std::tuple<WebKit::WebGPU::BindGroupDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateBindGroup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateBindGroup(const WebKit::WebGPU::BindGroupDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::BindGroupDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateShaderModule {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ShaderModuleDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateShaderModule; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateShaderModule(const WebKit::WebGPU::ShaderModuleDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ShaderModuleDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateComputePipeline {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ComputePipelineDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateComputePipeline; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateComputePipeline(const WebKit::WebGPU::ComputePipelineDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ComputePipelineDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateRenderPipeline {
public:
    using Arguments = std::tuple<WebKit::WebGPU::RenderPipelineDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateRenderPipeline; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateRenderPipeline(const WebKit::WebGPU::RenderPipelineDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::RenderPipelineDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateComputePipelineAsync {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ComputePipelineDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateComputePipelineAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteDevice_CreateComputePipelineAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, String>;
    using Reply = CompletionHandler<void(bool, String&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, String>, IPC::Error>;
    CreateComputePipelineAsync(const WebKit::WebGPU::ComputePipelineDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::ComputePipelineDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateRenderPipelineAsync {
public:
    using Arguments = std::tuple<WebKit::WebGPU::RenderPipelineDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateRenderPipelineAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteDevice_CreateRenderPipelineAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, String>;
    using Reply = CompletionHandler<void(bool, String&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, String>, IPC::Error>;
    CreateRenderPipelineAsync(const WebKit::WebGPU::RenderPipelineDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::RenderPipelineDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateCommandEncoder {
public:
    using Arguments = std::tuple<std::optional<WebKit::WebGPU::CommandEncoderDescriptor>, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateCommandEncoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateCommandEncoder(const std::optional<WebKit::WebGPU::CommandEncoderDescriptor>& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebGPU::CommandEncoderDescriptor>& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateRenderBundleEncoder {
public:
    using Arguments = std::tuple<WebKit::WebGPU::RenderBundleEncoderDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateRenderBundleEncoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateRenderBundleEncoder(const WebKit::WebGPU::RenderBundleEncoderDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::RenderBundleEncoderDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class CreateQuerySet {
public:
    using Arguments = std::tuple<WebKit::WebGPU::QuerySetDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_CreateQuerySet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    CreateQuerySet(const WebKit::WebGPU::QuerySetDescriptor& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(descriptor)
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_descriptor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPU::QuerySetDescriptor& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};

class PushErrorScope {
public:
    using Arguments = std::tuple<WebCore::WebGPU::ErrorFilter>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_PushErrorScope; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit PushErrorScope(const WebCore::WebGPU::ErrorFilter& errorFilter)
        : m_errorFilter(errorFilter)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_errorFilter;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WebGPU::ErrorFilter& m_errorFilter;
};

class PopErrorScope {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_PopErrorScope; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteDevice_PopErrorScopeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, std::optional<WebKit::WebGPU::Error>>;
    using Reply = CompletionHandler<void(bool, std::optional<WebKit::WebGPU::Error>&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, std::optional<WebKit::WebGPU::Error>>, IPC::Error>;
    PopErrorScope()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ResolveUncapturedErrorEvent {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_ResolveUncapturedErrorEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteDevice_ResolveUncapturedErrorEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, std::optional<WebKit::WebGPU::Error>>;
    using Reply = CompletionHandler<void(bool, std::optional<WebKit::WebGPU::Error>&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, std::optional<WebKit::WebGPU::Error>>, IPC::Error>;
    ResolveUncapturedErrorEvent()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ResolveDeviceLostPromise {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_ResolveDeviceLostPromise; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::RemoteDevice_ResolveDeviceLostPromiseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::WebGPU::DeviceLostReason>;
    using Reply = CompletionHandler<void(WebCore::WebGPU::DeviceLostReason&&)>;
    using Promise = WTF::NativePromise<WebCore::WebGPU::DeviceLostReason, IPC::Error>;
    ResolveDeviceLostPromise()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetLabel {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_SetLabel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit SetLabel(const String& label)
        : m_label(label)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_label;
    }

private:
    const String& m_label;
};

class PauseAllErrorReporting {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_PauseAllErrorReporting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    explicit PauseAllErrorReporting(bool pauseErrorReporting)
        : m_pauseErrorReporting(pauseErrorReporting)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pauseErrorReporting;
    }

private:
    bool m_pauseErrorReporting;
};

#if PLATFORM(COCOA) && ENABLE(VIDEO)
class SetSharedVideoFrameSemaphore {
public:
    using Arguments = std::tuple<IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_SetSharedVideoFrameSemaphore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    explicit SetSharedVideoFrameSemaphore(const IPC::Semaphore& semaphore)
        : m_semaphore(semaphore)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_semaphore;
    }

private:
    const IPC::Semaphore& m_semaphore;
};
#endif

#if PLATFORM(COCOA) && ENABLE(VIDEO)
class SetSharedVideoFrameMemory {
public:
    using Arguments = std::tuple<WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_SetSharedVideoFrameMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    explicit SetSharedVideoFrameMemory(WebCore::SharedMemory::Handle&& storageHandle)
        : m_storageHandle(WTFMove(storageHandle))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_storageHandle);
    }

private:
    WebCore::SharedMemory::Handle&& m_storageHandle;
};
#endif

#if PLATFORM(COCOA) && ENABLE(VIDEO)
class ImportExternalTextureFromVideoFrame {
public:
    using Arguments = std::tuple<WebKit::WebGPU::ExternalTextureDescriptor, WebKit::WebGPUIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_ImportExternalTextureFromVideoFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    ImportExternalTextureFromVideoFrame(WebKit::WebGPU::ExternalTextureDescriptor&& descriptor, const WebKit::WebGPUIdentifier& identifier)
        : m_descriptor(WTFMove(descriptor))
        , m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_descriptor);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    WebKit::WebGPU::ExternalTextureDescriptor&& m_descriptor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_identifier;
};
#endif

#if PLATFORM(COCOA) && ENABLE(VIDEO)
class UpdateExternalTexture {
public:
    using Arguments = std::tuple<WebKit::WebGPUIdentifier, WebCore::MediaPlayerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::RemoteDevice_UpdateExternalTexture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    UpdateExternalTexture(const WebKit::WebGPUIdentifier& externalTextureIdentifier, const WebCore::MediaPlayerIdentifier& mediaIdentifier)
        : m_externalTextureIdentifier(externalTextureIdentifier)
        , m_mediaIdentifier(mediaIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_externalTextureIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mediaIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebGPUIdentifier& m_externalTextureIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerIdentifier& m_mediaIdentifier;
};
#endif

} // namespace RemoteDevice
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
