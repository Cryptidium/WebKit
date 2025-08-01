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

#if USE(LIBWEBRTC) && PLATFORM(COCOA) && ENABLE(GPU_PROCESS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#if PLATFORM(COCOA)
#include <WebCore/CVUtilities.h>
#endif
#include <span>
#include <wtf/Forward.h>
#include <wtf/RetainPtr.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>

namespace WebCore {
struct PlatformVideoColorSpace;
}

namespace WebKit {
struct VideoDecoderIdentifierType;
using VideoDecoderIdentifier = AtomicObjectIdentifier<VideoDecoderIdentifierType>;
struct VideoEncoderIdentifierType;
using VideoEncoderIdentifier = AtomicObjectIdentifier<VideoEncoderIdentifierType>;
struct RemoteVideoFrameProxyProperties;
}

namespace webrtc {
struct WebKitEncodedFrameInfo;
}

namespace Messages {
namespace LibWebRTCCodecs {

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
    return IPC::ReceiverName::LibWebRTCCodecs;
}

class FailedDecoding {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecs_FailedDecoding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FailedDecoding(const WebKit::VideoDecoderIdentifier& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_identifier;
};

class CompletedDecoding {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier, int64_t, int64_t, WebKit::RemoteVideoFrameProxyProperties>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecs_CompletedDecoding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CompletedDecoding(const WebKit::VideoDecoderIdentifier& identifier, int64_t timeStamp, int64_t timeStampNs, const WebKit::RemoteVideoFrameProxyProperties& frame)
        : m_identifier(identifier)
        , m_timeStamp(timeStamp)
        , m_timeStampNs(timeStampNs)
        , m_frame(frame)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_timeStamp;
        encoder << m_timeStampNs;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frame;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_identifier;
    int64_t m_timeStamp;
    int64_t m_timeStampNs;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteVideoFrameProxyProperties& m_frame;
};

class CompletedDecodingCV {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier, int64_t, int64_t, RetainPtr<CVPixelBufferRef>>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecs_CompletedDecodingCV; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CompletedDecodingCV(const WebKit::VideoDecoderIdentifier& identifier, int64_t timeStamp, int64_t timeStampNs, const RetainPtr<CVPixelBufferRef>& pixelBuffer)
        : m_identifier(identifier)
        , m_timeStamp(timeStamp)
        , m_timeStampNs(timeStampNs)
        , m_pixelBuffer(pixelBuffer)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_timeStamp;
        encoder << m_timeStampNs;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pixelBuffer;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_identifier;
    int64_t m_timeStamp;
    int64_t m_timeStampNs;
    SUPPRESS_FORWARD_DECL_MEMBER const RetainPtr<CVPixelBufferRef>& m_pixelBuffer;
};

class CompletedEncoding {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier, std::span<const uint8_t>, webrtc::WebKitEncodedFrameInfo>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecs_CompletedEncoding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CompletedEncoding(const WebKit::VideoEncoderIdentifier& identifier, const std::span<const uint8_t>& data, const webrtc::WebKitEncodedFrameInfo& info)
        : m_identifier(identifier)
        , m_data(data)
        , m_info(info)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
    SUPPRESS_FORWARD_DECL_MEMBER const webrtc::WebKitEncodedFrameInfo& m_info;
};

class SetEncodingConfiguration {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier, std::span<const uint8_t>, std::optional<WebCore::PlatformVideoColorSpace>>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecs_SetEncodingConfiguration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetEncodingConfiguration(const WebKit::VideoEncoderIdentifier& identifier, const std::span<const uint8_t>& description, const std::optional<WebCore::PlatformVideoColorSpace>& colorSpace)
        : m_identifier(identifier)
        , m_description(description)
        , m_colorSpace(colorSpace)
    {
        ASSERT(isInGPUProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_description;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_colorSpace;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_description;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::PlatformVideoColorSpace>& m_colorSpace;
};

} // namespace LibWebRTCCodecs
} // namespace Messages

#endif // USE(LIBWEBRTC) && PLATFORM(COCOA) && ENABLE(GPU_PROCESS)
