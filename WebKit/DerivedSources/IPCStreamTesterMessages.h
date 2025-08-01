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

#if ENABLE(IPC_TESTING_API)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "MessageNames.h"
#include <WebCore/SharedMemory.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>


namespace Messages {
namespace IPCStreamTester {

static inline IPC::ReceiverName messageReceiverName()
{
    return IPC::ReceiverName::IPCStreamTester;
}

class SyncMessage {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_SyncMessage; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    explicit SyncMessage(uint32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    uint32_t m_value;
};

class SyncMessageNotStreamEncodableReply {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_SyncMessageNotStreamEncodableReply; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    explicit SyncMessageNotStreamEncodableReply(uint32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    uint32_t m_value;
};

class SyncMessageNotStreamEncodableBoth {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_SyncMessageNotStreamEncodableBoth; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = false;
    static constexpr bool isReplyStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    explicit SyncMessageNotStreamEncodableBoth(uint32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    uint32_t m_value;
};

class SyncMessageReturningSharedMemory1 {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_SyncMessageReturningSharedMemory1; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = false;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::SharedMemory::Handle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::SharedMemory::Handle>&&)>;
    explicit SyncMessageReturningSharedMemory1(uint32_t byteCount)
        : m_byteCount(byteCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_byteCount;
    }

private:
    uint32_t m_byteCount;
};

class SyncMessageEmptyReply {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_SyncMessageEmptyReply; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    explicit SyncMessageEmptyReply(uint32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    uint32_t m_value;
};

class SyncCrashOnZero {
public:
    using Arguments = std::tuple<int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_SyncCrashOnZero; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    explicit SyncCrashOnZero(int32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    int32_t m_value;
};

class CheckAutoreleasePool {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_CheckAutoreleasePool; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t>;
    using Reply = CompletionHandler<void(int32_t)>;
    CheckAutoreleasePool()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class AsyncPing {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_AsyncPing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isReplyStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::IPCStreamTester_AsyncPingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    using Promise = WTF::NativePromise<uint32_t, IPC::Error>;
    explicit AsyncPing(uint32_t value)
        : m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    uint32_t m_value;
};

class EmptyMessage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::IPCStreamTester_EmptyMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;
    static constexpr bool isStreamEncodable = true;
    static constexpr bool isStreamBatched = false;

    EmptyMessage()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

} // namespace IPCStreamTester
} // namespace Messages

#endif // ENABLE(IPC_TESTING_API)
