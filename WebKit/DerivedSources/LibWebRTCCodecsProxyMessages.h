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
#include "IPCSemaphore.h"
#include "MessageNames.h"
#include "SharedVideoFrame.h"
#include <WebCore/SharedMemory.h>
#include <span>
#include <utility>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
enum class VideoCodecType : uint8_t;
enum class VideoEncoderScalabilityMode : uint8_t;
}

namespace WebKit {
struct VideoDecoderIdentifierType;
using VideoDecoderIdentifier = AtomicObjectIdentifier<VideoDecoderIdentifierType>;
struct VideoEncoderIdentifierType;
using VideoEncoderIdentifier = AtomicObjectIdentifier<VideoEncoderIdentifierType>;
}

namespace Messages {
namespace LibWebRTCCodecsProxy {

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
    return IPC::ReceiverName::LibWebRTCCodecsProxy;
}

class CreateDecoder {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier, WebCore::VideoCodecType, String, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_CreateDecoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::LibWebRTCCodecsProxy_CreateDecoderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    CreateDecoder(const WebKit::VideoDecoderIdentifier& id, WebCore::VideoCodecType codecType, const String& codecString, bool useRemoteFrames, bool enableAdditionalLogging)
        : m_id(id)
        , m_codecType(codecType)
        , m_codecString(codecString)
        , m_useRemoteFrames(useRemoteFrames)
        , m_enableAdditionalLogging(enableAdditionalLogging)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_codecType;
        encoder << m_codecString;
        encoder << m_useRemoteFrames;
        encoder << m_enableAdditionalLogging;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_id;
    WebCore::VideoCodecType m_codecType;
    const String& m_codecString;
    bool m_useRemoteFrames;
    bool m_enableAdditionalLogging;
};

class ReleaseDecoder {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_ReleaseDecoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseDecoder(const WebKit::VideoDecoderIdentifier& id)
        : m_id(id)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_id;
};

class FlushDecoder {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_FlushDecoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::LibWebRTCCodecsProxy_FlushDecoderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit FlushDecoder(const WebKit::VideoDecoderIdentifier& id)
        : m_id(id)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_id;
};

class SetDecoderFormatDescription {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier, std::span<const uint8_t>, uint16_t, uint16_t>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_SetDecoderFormatDescription; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetDecoderFormatDescription(const WebKit::VideoDecoderIdentifier& id, const std::span<const uint8_t>& description, uint16_t width, uint16_t height)
        : m_id(id)
        , m_description(description)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_description;
        encoder << m_width;
        encoder << m_height;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_id;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_description;
    uint16_t m_width;
    uint16_t m_height;
};

class DecodeFrame {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier, int64_t, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_DecodeFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::LibWebRTCCodecsProxy_DecodeFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    DecodeFrame(const WebKit::VideoDecoderIdentifier& id, int64_t timeStamp, const std::span<const uint8_t>& data)
        : m_id(id)
        , m_timeStamp(timeStamp)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_timeStamp;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_id;
    int64_t m_timeStamp;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class SetFrameSize {
public:
    using Arguments = std::tuple<WebKit::VideoDecoderIdentifier, uint16_t, uint16_t>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_SetFrameSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetFrameSize(const WebKit::VideoDecoderIdentifier& id, uint16_t width, uint16_t height)
        : m_id(id)
        , m_width(width)
        , m_height(height)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_width;
        encoder << m_height;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoDecoderIdentifier& m_id;
    uint16_t m_width;
    uint16_t m_height;
};

class CreateEncoder {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier, WebCore::VideoCodecType, String, Vector<std::pair<String, String>>, bool, bool, WebCore::VideoEncoderScalabilityMode>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_CreateEncoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::LibWebRTCCodecsProxy_CreateEncoderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    CreateEncoder(const WebKit::VideoEncoderIdentifier& id, WebCore::VideoCodecType codecType, const String& codecString, const Vector<std::pair<String, String>>& parameters, bool useLowLatency, bool useAnnexB, WebCore::VideoEncoderScalabilityMode scalabilityMode)
        : m_id(id)
        , m_codecType(codecType)
        , m_codecString(codecString)
        , m_parameters(parameters)
        , m_useLowLatency(useLowLatency)
        , m_useAnnexB(useAnnexB)
        , m_scalabilityMode(scalabilityMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_codecType;
        encoder << m_codecString;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
        encoder << m_useLowLatency;
        encoder << m_useAnnexB;
        encoder << m_scalabilityMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_id;
    WebCore::VideoCodecType m_codecType;
    const String& m_codecString;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::pair<String, String>>& m_parameters;
    bool m_useLowLatency;
    bool m_useAnnexB;
    WebCore::VideoEncoderScalabilityMode m_scalabilityMode;
};

class ReleaseEncoder {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_ReleaseEncoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReleaseEncoder(const WebKit::VideoEncoderIdentifier& id)
        : m_id(id)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_id;
};

class InitializeEncoder {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier, uint16_t, uint16_t, unsigned, unsigned, unsigned, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_InitializeEncoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    InitializeEncoder(const WebKit::VideoEncoderIdentifier& id, uint16_t width, uint16_t height, const unsigned& startBitrate, const unsigned& maxBitrate, const unsigned& minBitrate, uint32_t maxFramerate)
        : m_id(id)
        , m_width(width)
        , m_height(height)
        , m_startBitrate(startBitrate)
        , m_maxBitrate(maxBitrate)
        , m_minBitrate(minBitrate)
        , m_maxFramerate(maxFramerate)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_width;
        encoder << m_height;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_startBitrate;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_maxBitrate;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_minBitrate;
        encoder << m_maxFramerate;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_id;
    uint16_t m_width;
    uint16_t m_height;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_startBitrate;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_maxBitrate;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_minBitrate;
    uint32_t m_maxFramerate;
};

class EncodeFrame {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier, WebKit::SharedVideoFrame, int64_t, std::optional<uint64_t>, bool>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_EncodeFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::LibWebRTCCodecsProxy_EncodeFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    EncodeFrame(const WebKit::VideoEncoderIdentifier& id, WebKit::SharedVideoFrame&& buffer, int64_t timeStamp, const std::optional<uint64_t>& duration, bool shouldEncodeAsKeyFrame)
        : m_id(id)
        , m_buffer(WTFMove(buffer))
        , m_timeStamp(timeStamp)
        , m_duration(duration)
        , m_shouldEncodeAsKeyFrame(shouldEncodeAsKeyFrame)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << WTFMove(m_buffer);
        encoder << m_timeStamp;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_duration;
        encoder << m_shouldEncodeAsKeyFrame;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_id;
    WebKit::SharedVideoFrame&& m_buffer;
    int64_t m_timeStamp;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_duration;
    bool m_shouldEncodeAsKeyFrame;
};

class FlushEncoder {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_FlushEncoder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::LibWebRTCCodecsProxy_FlushEncoderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit FlushEncoder(const WebKit::VideoEncoderIdentifier& id)
        : m_id(id)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_id;
};

class SetEncodeRates {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_SetEncodeRates; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::LibWebRTCCodecsProxy_SetEncodeRatesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetEncodeRates(const WebKit::VideoEncoderIdentifier& id, uint32_t bitRate, uint32_t frameRate)
        : m_id(id)
        , m_bitRate(bitRate)
        , m_frameRate(frameRate)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_bitRate;
        encoder << m_frameRate;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_id;
    uint32_t m_bitRate;
    uint32_t m_frameRate;
};

class SetSharedVideoFrameSemaphore {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier, IPC::Semaphore>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_SetSharedVideoFrameSemaphore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetSharedVideoFrameSemaphore(const WebKit::VideoEncoderIdentifier& id, const IPC::Semaphore& semaphore)
        : m_id(id)
        , m_semaphore(semaphore)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << m_semaphore;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_id;
    const IPC::Semaphore& m_semaphore;
};

class SetSharedVideoFrameMemory {
public:
    using Arguments = std::tuple<WebKit::VideoEncoderIdentifier, WebCore::SharedMemory::Handle>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_SetSharedVideoFrameMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetSharedVideoFrameMemory(const WebKit::VideoEncoderIdentifier& id, WebCore::SharedMemory::Handle&& storageHandle)
        : m_id(id)
        , m_storageHandle(WTFMove(storageHandle))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_id;
        encoder << WTFMove(m_storageHandle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::VideoEncoderIdentifier& m_id;
    WebCore::SharedMemory::Handle&& m_storageHandle;
};

class SetRTCLoggingLevel {
public:
    using Arguments = std::tuple<WTFLogLevel>;

    static IPC::MessageName name() { return IPC::MessageName::LibWebRTCCodecsProxy_SetRTCLoggingLevel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetRTCLoggingLevel(const WTFLogLevel& level)
        : m_level(level)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_level;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WTFLogLevel& m_level;
};

} // namespace LibWebRTCCodecsProxy
} // namespace Messages

#endif // USE(LIBWEBRTC) && PLATFORM(COCOA) && ENABLE(GPU_PROCESS)
