/*
 * Copyright (C) 2022-2023 Apple Inc. All rights reserved.
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

#include "config.h"
#include "GeneratedSerializers.h"
#include "GeneratedWebKitSecureCoding.h"

#include "ArgumentCoders.h"
#include "ConnectionHandle.h"
#include "IPCEvent.h"
#include "IPCSemaphore.h"
#include "MessageFlags.h"
#include "StreamConnectionEncoder.h"
#include "WebPushDaemonConnectionConfiguration.h"
#include "WebPushMessage.h"
#include <WebCore/Color.h>
#include <WebCore/ColorTypes.h>
#include <WebCore/ProtectionSpaceBase.h>

template<size_t...> struct MembersInCorrectOrder;
template<size_t onlyOffset> struct MembersInCorrectOrder<onlyOffset> {
    static constexpr bool value = true;
};
template<size_t firstOffset, size_t secondOffset, size_t... remainingOffsets> struct MembersInCorrectOrder<firstOffset, secondOffset, remainingOffsets...> {
    static constexpr bool value = firstOffset > secondOffset ? false : MembersInCorrectOrder<secondOffset, remainingOffsets...>::value;
};

template<uint64_t...> struct BitsInIncreasingOrder;
template<uint64_t onlyBit> struct BitsInIncreasingOrder<onlyBit> {
    static constexpr bool value = true;
};
template<uint64_t firstBit, uint64_t secondBit, uint64_t... remainingBits> struct BitsInIncreasingOrder<firstBit, secondBit, remainingBits...> {
    static constexpr bool value = firstBit == secondBit >> 1 && BitsInIncreasingOrder<secondBit, remainingBits...>::value;
};

template<bool, bool> struct VirtualTableAndRefCountOverhead;
template<> struct VirtualTableAndRefCountOverhead<true, true> : public RefCounted<VirtualTableAndRefCountOverhead<true, true>> {
    virtual ~VirtualTableAndRefCountOverhead() { }
};
template<> struct VirtualTableAndRefCountOverhead<false, true> : public RefCounted<VirtualTableAndRefCountOverhead<false, true>> { };
template<> struct VirtualTableAndRefCountOverhead<true, false> {
    virtual ~VirtualTableAndRefCountOverhead() { }
};
template<> struct VirtualTableAndRefCountOverhead<false, false> { };

IGNORE_WARNINGS_BEGIN("invalid-offsetof")

namespace IPC {


void ArgumentCoder<IPC::ConnectionHandle>::encode(Encoder& encoder, IPC::ConnectionHandle&& instance)
{
#if USE(UNIX_DOMAIN_SOCKETS)
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.m_handle)>, UnixFileDescriptor>);
#endif
#if OS(WINDOWS)
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.m_handle)>, Win32Handle>);
#endif
#if OS(DARWIN)
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.m_handle)>, MachSendRight>);
#endif
    struct ShouldBeSameSizeAsConnectionHandle : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<IPC::ConnectionHandle>, false> {
#if USE(UNIX_DOMAIN_SOCKETS)
        UnixFileDescriptor m_handle;
#endif
#if OS(WINDOWS)
        Win32Handle m_handle;
#endif
#if OS(DARWIN)
        MachSendRight m_handle;
#endif
    };
    static_assert(sizeof(ShouldBeSameSizeAsConnectionHandle) == sizeof(IPC::ConnectionHandle));
    static_assert(MembersInCorrectOrder < 0
#if USE(UNIX_DOMAIN_SOCKETS)
        , offsetof(IPC::ConnectionHandle, m_handle)
#endif
#if OS(WINDOWS)
        , offsetof(IPC::ConnectionHandle, m_handle)
#endif
#if OS(DARWIN)
        , offsetof(IPC::ConnectionHandle, m_handle)
#endif
    >::value);

#if USE(UNIX_DOMAIN_SOCKETS)
    encoder << WTFMove(instance.m_handle);
#endif
#if OS(WINDOWS)
    encoder << WTFMove(instance.m_handle);
#endif
#if OS(DARWIN)
    encoder << WTFMove(instance.m_handle);
#endif
}

std::optional<IPC::ConnectionHandle> ArgumentCoder<IPC::ConnectionHandle>::decode(Decoder& decoder)
{
#if USE(UNIX_DOMAIN_SOCKETS)
    auto m_handle = decoder.decode<UnixFileDescriptor>();
#endif
#if OS(WINDOWS)
    auto m_handle = decoder.decode<Win32Handle>();
#endif
#if OS(DARWIN)
    auto m_handle = decoder.decode<MachSendRight>();
#endif
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        IPC::ConnectionHandle {
#if USE(UNIX_DOMAIN_SOCKETS)
            WTFMove(*m_handle),
#endif
#if OS(WINDOWS)
            WTFMove(*m_handle),
#endif
#if OS(DARWIN)
            WTFMove(*m_handle)
#endif
        }
    };
}

void ArgumentCoder<IPC::Signal>::encode(Encoder& encoder, IPC::Signal&& instance)
{
#if PLATFORM(COCOA)
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.takeSendRight())>, MachSendRight>);
#endif
#if !PLATFORM(COCOA)
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.semaphore())>, IPC::Semaphore>);
#endif

#if PLATFORM(COCOA)
    encoder << instance.takeSendRight();
#endif
#if !PLATFORM(COCOA)
    encoder << instance.semaphore();
#endif
}

std::optional<IPC::Signal> ArgumentCoder<IPC::Signal>::decode(Decoder& decoder)
{
#if PLATFORM(COCOA)
    auto takeSendRight = decoder.decode<MachSendRight>();
#endif
#if !PLATFORM(COCOA)
    auto semaphore = decoder.decode<IPC::Semaphore>();
#endif
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        IPC::Signal {
#if PLATFORM(COCOA)
            WTFMove(*takeSendRight),
#endif
#if !PLATFORM(COCOA)
            WTFMove(*semaphore)
#endif
        }
    };
}

void ArgumentCoder<IPC::Semaphore>::encode(Encoder& encoder, const IPC::Semaphore& instance)
{
#if PLATFORM(COCOA)
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.createSendRight())>, MachSendRight>);
#endif
#if OS(WINDOWS)
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.win32Handle())>, Win32Handle>);
#endif
#if USE(UNIX_DOMAIN_SOCKETS)
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.duplicateDescriptor())>, UnixFileDescriptor>);
#endif

#if PLATFORM(COCOA)
    encoder << instance.createSendRight();
#endif
#if OS(WINDOWS)
    encoder << instance.win32Handle();
#endif
#if USE(UNIX_DOMAIN_SOCKETS)
    encoder << instance.duplicateDescriptor();
#endif
}

std::optional<IPC::Semaphore> ArgumentCoder<IPC::Semaphore>::decode(Decoder& decoder)
{
#if PLATFORM(COCOA)
    auto createSendRight = decoder.decode<MachSendRight>();
#endif
#if OS(WINDOWS)
    auto win32Handle = decoder.decode<Win32Handle>();
#endif
#if USE(UNIX_DOMAIN_SOCKETS)
    auto duplicateDescriptor = decoder.decode<UnixFileDescriptor>();
#endif
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        IPC::Semaphore {
#if PLATFORM(COCOA)
            WTFMove(*createSendRight),
#endif
#if OS(WINDOWS)
            WTFMove(*win32Handle),
#endif
#if USE(UNIX_DOMAIN_SOCKETS)
            WTFMove(*duplicateDescriptor)
#endif
        }
    };
}

void ArgumentCoder<WTF::URL>::encode(Encoder& encoder, const WTF::URL& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.string())>, String>);

    encoder << instance.string();
}

void ArgumentCoder<WTF::URL>::encode(StreamConnectionEncoder& encoder, const WTF::URL& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.string())>, String>);

    encoder << instance.string();
}

std::optional<WTF::URL> ArgumentCoder<WTF::URL>::decode(Decoder& decoder)
{
    auto string = decoder.decode<String>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::URL {
            WTFMove(*string)
        }
    };
}

void ArgumentCoder<WTF::CString>::encode(Encoder& encoder, const WTF::CString& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.span())>, std::span<const char>>);

    encoder << instance.span();
}

void ArgumentCoder<WTF::CString>::encode(StreamConnectionEncoder& encoder, const WTF::CString& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.span())>, std::span<const char>>);

    encoder << instance.span();
}

std::optional<WTF::CString> ArgumentCoder<WTF::CString>::decode(Decoder& decoder)
{
    auto span = decoder.decode<std::span<const char>>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::CString {
            WTFMove(*span)
        }
    };
}

void ArgumentCoder<WTF::UUID>::encode(Encoder& encoder, const WTF::UUID& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.high())>, uint64_t>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.low())>, uint64_t>);

    encoder << instance.high();
    encoder << instance.low();
}

std::optional<WTF::UUID> ArgumentCoder<WTF::UUID>::decode(Decoder& decoder)
{
    auto high = decoder.decode<uint64_t>();
    auto low = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::UUID::isValid(*high, *low)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::UUID {
            WTFMove(*high),
            WTFMove(*low)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::AXIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::AXIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::AXIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::AXIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::AXIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::AXIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::AXIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::NodeIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::NodeIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::NodeIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::NodeIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::NodeIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::NodeIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::NodeIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::FetchIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::FetchIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::FetchIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::FetchIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::FetchIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::FetchIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::FetchIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::WindowIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::WindowIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::WindowIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::WindowIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::WindowIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::WindowIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::WindowIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::DictationContextType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::DictationContextType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::DictationContextType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::DictationContextType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::DictationContextType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::DictationContextType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::DictationContextType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::FrameIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::FrameIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::FrameIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::FrameIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::FrameIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::FrameIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::FrameIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::NavigationIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::PageIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::PageIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::PageIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::PageIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::PageIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::PageIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::PageIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::ProcessIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::DownloadIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::DownloadIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::DownloadIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::DownloadIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::DownloadIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::DownloadIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::DownloadIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::JSObjectIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::JSObjectIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::JSObjectIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::JSObjectIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::JSObjectIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::JSObjectIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::JSObjectIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::TapIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::TapIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::TapIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::TapIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::TapIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::TapIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::TapIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::TextCheckerRequestType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::TransactionIDType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::TransactionIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::TransactionIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::TransactionIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::TransactionIDType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::TransactionIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::TransactionIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>>::encode(Encoder& encoder, const WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>> ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::ResourceLoader> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>> ArgumentCoder<WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>> ArgumentCoder<WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>>::encode(Encoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

void ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>>::encode(StreamConnectionEncoder& encoder, const WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.toUInt64())>, uint64_t>);

    encoder << instance.toUInt64();
}

std::optional<WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>> ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>>::decode(Decoder& decoder)
{
    auto toUInt64 = decoder.decode<uint64_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;

    if (!(WTF::ObjectIdentifierGenericBase<uint64_t>::isValidIdentifier(*toUInt64)))
        return std::nullopt;
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType> {
            WTFMove(*toUInt64)
        }
    };
}

void ArgumentCoder<WebCore::PackedColor::RGBA>::encode(Encoder& encoder, const WebCore::PackedColor::RGBA& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.value)>, uint32_t>);
    struct ShouldBeSameSizeAsRGBA : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebCore::PackedColor::RGBA>, false> {
        uint32_t value;
    };
    static_assert(sizeof(ShouldBeSameSizeAsRGBA) == sizeof(WebCore::PackedColor::RGBA));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebCore::PackedColor::RGBA, value)
    >::value);

    encoder << instance.value;
}

void ArgumentCoder<WebCore::PackedColor::RGBA>::encode(StreamConnectionEncoder& encoder, const WebCore::PackedColor::RGBA& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.value)>, uint32_t>);
    struct ShouldBeSameSizeAsRGBA : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebCore::PackedColor::RGBA>, false> {
        uint32_t value;
    };
    static_assert(sizeof(ShouldBeSameSizeAsRGBA) == sizeof(WebCore::PackedColor::RGBA));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebCore::PackedColor::RGBA, value)
    >::value);

    encoder << instance.value;
}

std::optional<WebCore::PackedColor::RGBA> ArgumentCoder<WebCore::PackedColor::RGBA>::decode(Decoder& decoder)
{
    auto value = decoder.decode<uint32_t>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WebCore::PackedColor::RGBA {
            WTFMove(*value)
        }
    };
}

void ArgumentCoder<WebCore::OutOfLineColorDataForIPC>::encode(Encoder& encoder, const WebCore::OutOfLineColorDataForIPC& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.colorSpace)>, WebCore::ColorSpace>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.c1)>, float>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.c2)>, float>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.c3)>, float>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.alpha)>, float>);
    struct ShouldBeSameSizeAsOutOfLineColorDataForIPC : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebCore::OutOfLineColorDataForIPC>, false> {
        WebCore::ColorSpace colorSpace;
        float c1;
        float c2;
        float c3;
        float alpha;
    };
    static_assert(sizeof(ShouldBeSameSizeAsOutOfLineColorDataForIPC) == sizeof(WebCore::OutOfLineColorDataForIPC));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebCore::OutOfLineColorDataForIPC, colorSpace)
        , offsetof(WebCore::OutOfLineColorDataForIPC, c1)
        , offsetof(WebCore::OutOfLineColorDataForIPC, c2)
        , offsetof(WebCore::OutOfLineColorDataForIPC, c3)
        , offsetof(WebCore::OutOfLineColorDataForIPC, alpha)
    >::value);

    encoder << instance.colorSpace;
    encoder << instance.c1;
    encoder << instance.c2;
    encoder << instance.c3;
    encoder << instance.alpha;
}

void ArgumentCoder<WebCore::OutOfLineColorDataForIPC>::encode(StreamConnectionEncoder& encoder, const WebCore::OutOfLineColorDataForIPC& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.colorSpace)>, WebCore::ColorSpace>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.c1)>, float>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.c2)>, float>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.c3)>, float>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.alpha)>, float>);
    struct ShouldBeSameSizeAsOutOfLineColorDataForIPC : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebCore::OutOfLineColorDataForIPC>, false> {
        WebCore::ColorSpace colorSpace;
        float c1;
        float c2;
        float c3;
        float alpha;
    };
    static_assert(sizeof(ShouldBeSameSizeAsOutOfLineColorDataForIPC) == sizeof(WebCore::OutOfLineColorDataForIPC));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebCore::OutOfLineColorDataForIPC, colorSpace)
        , offsetof(WebCore::OutOfLineColorDataForIPC, c1)
        , offsetof(WebCore::OutOfLineColorDataForIPC, c2)
        , offsetof(WebCore::OutOfLineColorDataForIPC, c3)
        , offsetof(WebCore::OutOfLineColorDataForIPC, alpha)
    >::value);

    encoder << instance.colorSpace;
    encoder << instance.c1;
    encoder << instance.c2;
    encoder << instance.c3;
    encoder << instance.alpha;
}

std::optional<WebCore::OutOfLineColorDataForIPC> ArgumentCoder<WebCore::OutOfLineColorDataForIPC>::decode(Decoder& decoder)
{
    auto colorSpace = decoder.decode<WebCore::ColorSpace>();
    auto c1 = decoder.decode<float>();
    auto c2 = decoder.decode<float>();
    auto c3 = decoder.decode<float>();
    auto alpha = decoder.decode<float>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WebCore::OutOfLineColorDataForIPC {
            WTFMove(*colorSpace),
            WTFMove(*c1),
            WTFMove(*c2),
            WTFMove(*c3),
            WTFMove(*alpha)
        }
    };
}

void ArgumentCoder<WebCore::ColorDataForIPC>::encode(Encoder& encoder, const WebCore::ColorDataForIPC& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.isSemantic)>, bool>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.usesFunctionSerialization)>, bool>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.data)>, Variant<WebCore::PackedColor::RGBA, WebCore::OutOfLineColorDataForIPC>>);
    struct ShouldBeSameSizeAsColorDataForIPC : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebCore::ColorDataForIPC>, false> {
        bool isSemantic;
        bool usesFunctionSerialization;
        Variant<WebCore::PackedColor::RGBA, WebCore::OutOfLineColorDataForIPC> data;
    };
    static_assert(sizeof(ShouldBeSameSizeAsColorDataForIPC) == sizeof(WebCore::ColorDataForIPC));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebCore::ColorDataForIPC, isSemantic)
        , offsetof(WebCore::ColorDataForIPC, usesFunctionSerialization)
        , offsetof(WebCore::ColorDataForIPC, data)
    >::value);

    encoder << instance.isSemantic;
    encoder << instance.usesFunctionSerialization;
    encoder << instance.data;
}

void ArgumentCoder<WebCore::ColorDataForIPC>::encode(StreamConnectionEncoder& encoder, const WebCore::ColorDataForIPC& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.isSemantic)>, bool>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.usesFunctionSerialization)>, bool>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.data)>, Variant<WebCore::PackedColor::RGBA, WebCore::OutOfLineColorDataForIPC>>);
    struct ShouldBeSameSizeAsColorDataForIPC : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebCore::ColorDataForIPC>, false> {
        bool isSemantic;
        bool usesFunctionSerialization;
        Variant<WebCore::PackedColor::RGBA, WebCore::OutOfLineColorDataForIPC> data;
    };
    static_assert(sizeof(ShouldBeSameSizeAsColorDataForIPC) == sizeof(WebCore::ColorDataForIPC));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebCore::ColorDataForIPC, isSemantic)
        , offsetof(WebCore::ColorDataForIPC, usesFunctionSerialization)
        , offsetof(WebCore::ColorDataForIPC, data)
    >::value);

    encoder << instance.isSemantic;
    encoder << instance.usesFunctionSerialization;
    encoder << instance.data;
}

std::optional<WebCore::ColorDataForIPC> ArgumentCoder<WebCore::ColorDataForIPC>::decode(Decoder& decoder)
{
    auto isSemantic = decoder.decode<bool>();
    auto usesFunctionSerialization = decoder.decode<bool>();
    auto data = decoder.decode<Variant<WebCore::PackedColor::RGBA, WebCore::OutOfLineColorDataForIPC>>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WebCore::ColorDataForIPC {
            WTFMove(*isSemantic),
            WTFMove(*usesFunctionSerialization),
            WTFMove(*data)
        }
    };
}

void ArgumentCoder<WebCore::Color>::encode(Encoder& encoder, const WebCore::Color& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.data())>, std::optional<WebCore::ColorDataForIPC>>);

    encoder << instance.data();
}

void ArgumentCoder<WebCore::Color>::encode(StreamConnectionEncoder& encoder, const WebCore::Color& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.data())>, std::optional<WebCore::ColorDataForIPC>>);

    encoder << instance.data();
}

std::optional<WebCore::Color> ArgumentCoder<WebCore::Color>::decode(Decoder& decoder)
{
    auto data = decoder.decode<std::optional<WebCore::ColorDataForIPC>>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WebCore::Color {
            WTFMove(*data)
        }
    };
}

void ArgumentCoder<WebCore::NotificationPayload>::encode(Encoder& encoder, const WebCore::NotificationPayload& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.defaultActionURL)>, URL>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.title)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.appBadge)>, std::optional<unsigned long long>>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.options)>, std::optional<WebCore::NotificationOptionsPayload>>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.isMutable)>, bool>);
    struct ShouldBeSameSizeAsNotificationPayload : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebCore::NotificationPayload>, false> {
        URL defaultActionURL;
        String title;
        std::optional<unsigned long long> appBadge;
        std::optional<WebCore::NotificationOptionsPayload> options;
        bool isMutable;
    };
    static_assert(sizeof(ShouldBeSameSizeAsNotificationPayload) == sizeof(WebCore::NotificationPayload));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebCore::NotificationPayload, defaultActionURL)
        , offsetof(WebCore::NotificationPayload, title)
        , offsetof(WebCore::NotificationPayload, appBadge)
        , offsetof(WebCore::NotificationPayload, options)
        , offsetof(WebCore::NotificationPayload, isMutable)
    >::value);

    encoder << instance.defaultActionURL;
    encoder << instance.title;
    encoder << instance.appBadge;
    encoder << instance.options;
    encoder << instance.isMutable;
}

std::optional<WebCore::NotificationPayload> ArgumentCoder<WebCore::NotificationPayload>::decode(Decoder& decoder)
{
    auto defaultActionURL = decoder.decode<URL>();
    auto title = decoder.decode<String>();
    auto appBadge = decoder.decode<std::optional<unsigned long long>>();
    auto options = decoder.decode<std::optional<WebCore::NotificationOptionsPayload>>();
    auto isMutable = decoder.decode<bool>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WebCore::NotificationPayload {
            WTFMove(*defaultActionURL),
            WTFMove(*title),
            WTFMove(*appBadge),
            WTFMove(*options),
            WTFMove(*isMutable)
        }
    };
}

void ArgumentCoder<WebCore::NotificationOptionsPayload>::encode(Encoder& encoder, const WebCore::NotificationOptionsPayload& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.dir)>, WebCore::NotificationDirection>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.lang)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.body)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.tag)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.icon)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.dataJSONString)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.silent)>, std::optional<bool>>);
    struct ShouldBeSameSizeAsNotificationOptionsPayload : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebCore::NotificationOptionsPayload>, false> {
        WebCore::NotificationDirection dir;
        String lang;
        String body;
        String tag;
        String icon;
        String dataJSONString;
        std::optional<bool> silent;
    };
    static_assert(sizeof(ShouldBeSameSizeAsNotificationOptionsPayload) == sizeof(WebCore::NotificationOptionsPayload));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebCore::NotificationOptionsPayload, dir)
        , offsetof(WebCore::NotificationOptionsPayload, lang)
        , offsetof(WebCore::NotificationOptionsPayload, body)
        , offsetof(WebCore::NotificationOptionsPayload, tag)
        , offsetof(WebCore::NotificationOptionsPayload, icon)
        , offsetof(WebCore::NotificationOptionsPayload, dataJSONString)
        , offsetof(WebCore::NotificationOptionsPayload, silent)
    >::value);

    encoder << instance.dir;
    encoder << instance.lang;
    encoder << instance.body;
    encoder << instance.tag;
    encoder << instance.icon;
    encoder << instance.dataJSONString;
    encoder << instance.silent;
}

std::optional<WebCore::NotificationOptionsPayload> ArgumentCoder<WebCore::NotificationOptionsPayload>::decode(Decoder& decoder)
{
    auto dir = decoder.decode<WebCore::NotificationDirection>();
    auto lang = decoder.decode<String>();
    auto body = decoder.decode<String>();
    auto tag = decoder.decode<String>();
    auto icon = decoder.decode<String>();
    auto dataJSONString = decoder.decode<String>();
    auto silent = decoder.decode<std::optional<bool>>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WebCore::NotificationOptionsPayload {
            WTFMove(*dir),
            WTFMove(*lang),
            WTFMove(*body),
            WTFMove(*tag),
            WTFMove(*icon),
            WTFMove(*dataJSONString),
            WTFMove(*silent)
        }
    };
}

void ArgumentCoder<WebKit::WebPushD::WebPushDaemonConnectionConfiguration>::encode(Encoder& encoder, const WebKit::WebPushD::WebPushDaemonConnectionConfiguration& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.hostAppAuditTokenData)>, Vector<uint8_t>>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.bundleIdentifierOverride)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.pushPartitionString)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.dataStoreIdentifier)>, std::optional<WTF::UUID>>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.declarativeWebPushEnabled)>, bool>);
    struct ShouldBeSameSizeAsWebPushDaemonConnectionConfiguration : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebKit::WebPushD::WebPushDaemonConnectionConfiguration>, false> {
        Vector<uint8_t> hostAppAuditTokenData;
        String bundleIdentifierOverride;
        String pushPartitionString;
        std::optional<WTF::UUID> dataStoreIdentifier;
        bool declarativeWebPushEnabled;
    };
    static_assert(sizeof(ShouldBeSameSizeAsWebPushDaemonConnectionConfiguration) == sizeof(WebKit::WebPushD::WebPushDaemonConnectionConfiguration));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebKit::WebPushD::WebPushDaemonConnectionConfiguration, hostAppAuditTokenData)
        , offsetof(WebKit::WebPushD::WebPushDaemonConnectionConfiguration, bundleIdentifierOverride)
        , offsetof(WebKit::WebPushD::WebPushDaemonConnectionConfiguration, pushPartitionString)
        , offsetof(WebKit::WebPushD::WebPushDaemonConnectionConfiguration, dataStoreIdentifier)
        , offsetof(WebKit::WebPushD::WebPushDaemonConnectionConfiguration, declarativeWebPushEnabled)
    >::value);

    encoder << instance.hostAppAuditTokenData;
    encoder << instance.bundleIdentifierOverride;
    encoder << instance.pushPartitionString;
    encoder << instance.dataStoreIdentifier;
    encoder << instance.declarativeWebPushEnabled;
}

std::optional<WebKit::WebPushD::WebPushDaemonConnectionConfiguration> ArgumentCoder<WebKit::WebPushD::WebPushDaemonConnectionConfiguration>::decode(Decoder& decoder)
{
    auto hostAppAuditTokenData = decoder.decode<Vector<uint8_t>>();
    auto bundleIdentifierOverride = decoder.decode<String>();
    auto pushPartitionString = decoder.decode<String>();
    auto dataStoreIdentifier = decoder.decode<std::optional<WTF::UUID>>();
    auto declarativeWebPushEnabled = decoder.decode<bool>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WebKit::WebPushD::WebPushDaemonConnectionConfiguration {
            WTFMove(*hostAppAuditTokenData),
            WTFMove(*bundleIdentifierOverride),
            WTFMove(*pushPartitionString),
            WTFMove(*dataStoreIdentifier),
            WTFMove(*declarativeWebPushEnabled)
        }
    };
}

void ArgumentCoder<WebKit::WebPushMessage>::encode(Encoder& encoder, const WebKit::WebPushMessage& instance)
{
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.pushData)>, std::optional<Vector<uint8_t>>>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.pushPartitionString)>, String>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.registrationURL)>, URL>);
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(instance.notificationPayload)>, std::optional<WebCore::NotificationPayload>>);
    struct ShouldBeSameSizeAsWebPushMessage : public VirtualTableAndRefCountOverhead<std::is_polymorphic_v<WebKit::WebPushMessage>, false> {
        std::optional<Vector<uint8_t>> pushData;
        String pushPartitionString;
        URL registrationURL;
        std::optional<WebCore::NotificationPayload> notificationPayload;
    };
    static_assert(sizeof(ShouldBeSameSizeAsWebPushMessage) == sizeof(WebKit::WebPushMessage));
    static_assert(MembersInCorrectOrder < 0
        , offsetof(WebKit::WebPushMessage, pushData)
        , offsetof(WebKit::WebPushMessage, pushPartitionString)
        , offsetof(WebKit::WebPushMessage, registrationURL)
        , offsetof(WebKit::WebPushMessage, notificationPayload)
    >::value);

    encoder << instance.pushData;
    encoder << instance.pushPartitionString;
    encoder << instance.registrationURL;
    encoder << instance.notificationPayload;
}

std::optional<WebKit::WebPushMessage> ArgumentCoder<WebKit::WebPushMessage>::decode(Decoder& decoder)
{
    auto pushData = decoder.decode<std::optional<Vector<uint8_t>>>();
    auto pushPartitionString = decoder.decode<String>();
    auto registrationURL = decoder.decode<URL>();
    auto notificationPayload = decoder.decode<std::optional<WebCore::NotificationPayload>>();
    if (!decoder.isValid()) [[unlikely]]
        return std::nullopt;
    return {
        WebKit::WebPushMessage {
            WTFMove(*pushData),
            WTFMove(*pushPartitionString),
            WTFMove(*registrationURL),
            WTFMove(*notificationPayload)
        }
    };
}

} // namespace IPC

namespace WTF {

template<> bool isValidOptionSet<IPC::MessageFlags>(OptionSet<IPC::MessageFlags> value)
{
    constexpr uint8_t allValidBitsValue = 0
        | static_cast<uint8_t>(IPC::MessageFlags::DispatchMessageWhenWaitingForSyncReply)
        | static_cast<uint8_t>(IPC::MessageFlags::DispatchMessageWhenWaitingForUnboundedSyncReply)
        | static_cast<uint8_t>(IPC::MessageFlags::UseFullySynchronousModeForTesting)
        | static_cast<uint8_t>(IPC::MessageFlags::MaintainOrderingWithAsyncMessages)
#if ENABLE(IPC_TESTING_API)
        | static_cast<uint8_t>(IPC::MessageFlags::SyncMessageDeserializationFailure)
#endif
        | 0;
    return (value.toRaw() | allValidBitsValue) == allValidBitsValue;
}

template<> bool isValidEnum<WebCore::ColorSpace>(uint8_t value)
{
    switch (static_cast<WebCore::ColorSpace>(value)) {
    case WebCore::ColorSpace::A98RGB:
    case WebCore::ColorSpace::DisplayP3:
    case WebCore::ColorSpace::ExtendedA98RGB:
    case WebCore::ColorSpace::ExtendedDisplayP3:
    case WebCore::ColorSpace::ExtendedLinearSRGB:
    case WebCore::ColorSpace::ExtendedProPhotoRGB:
    case WebCore::ColorSpace::ExtendedRec2020:
    case WebCore::ColorSpace::ExtendedSRGB:
    case WebCore::ColorSpace::HSL:
    case WebCore::ColorSpace::HWB:
    case WebCore::ColorSpace::LCH:
    case WebCore::ColorSpace::Lab:
    case WebCore::ColorSpace::LinearSRGB:
    case WebCore::ColorSpace::OKLCH:
    case WebCore::ColorSpace::OKLab:
    case WebCore::ColorSpace::ProPhotoRGB:
    case WebCore::ColorSpace::Rec2020:
    case WebCore::ColorSpace::SRGB:
    case WebCore::ColorSpace::XYZ_D50:
    case WebCore::ColorSpace::XYZ_D65:
        return true;
    default:
        return false;
    }
}

template<> bool isValidEnum<WebCore::NotificationDirection>(uint8_t value)
{
    switch (static_cast<WebCore::NotificationDirection>(value)) {
    case WebCore::NotificationDirection::Auto:
    case WebCore::NotificationDirection::Ltr:
    case WebCore::NotificationDirection::Rtl:
        return true;
    default:
        return false;
    }
}

template<> bool isValidEnum<WebCore::ProtectionSpaceBaseServerType>(uint8_t value)
{
    switch (static_cast<WebCore::ProtectionSpaceBaseServerType>(value)) {
    case WebCore::ProtectionSpaceBaseServerType::HTTP:
    case WebCore::ProtectionSpaceBaseServerType::HTTPS:
    case WebCore::ProtectionSpaceBaseServerType::FTP:
    case WebCore::ProtectionSpaceBaseServerType::FTPS:
    case WebCore::ProtectionSpaceBaseServerType::ProxyHTTP:
    case WebCore::ProtectionSpaceBaseServerType::ProxyHTTPS:
    case WebCore::ProtectionSpaceBaseServerType::ProxyFTP:
    case WebCore::ProtectionSpaceBaseServerType::ProxySOCKS:
        return true;
    default:
        return false;
    }
}

template<> bool isValidEnum<WebCore::ProtectionSpaceBaseAuthenticationScheme>(uint8_t value)
{
    switch (static_cast<WebCore::ProtectionSpaceBaseAuthenticationScheme>(value)) {
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::Default:
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::HTTPBasic:
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::HTTPDigest:
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::HTMLForm:
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::NTLM:
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::Negotiate:
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::ClientCertificateRequested:
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::ServerTrustEvaluationRequested:
#if PLATFORM(COCOA)
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::XMobileMeAuthToken:
#endif
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::OAuth:
#if PLATFORM(COCOA)
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::PrivateAccessToken:
#endif
#if PLATFORM(COCOA)
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::OAuthBearerToken:
#endif
#if USE(GLIB)
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::ClientCertificatePINRequested:
#endif
#if !PLATFORM(COCOA)
    case WebCore::ProtectionSpaceBaseAuthenticationScheme::Unknown:
#endif
        return true;
    default:
        return false;
    }
}

} // namespace WTF

IGNORE_WARNINGS_END
