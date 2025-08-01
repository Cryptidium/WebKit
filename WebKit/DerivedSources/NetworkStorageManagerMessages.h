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
#include "FileSystemStorageError.h"
#include "FileSystemSyncAccessHandleInfo.h"
#include "MessageNames.h"
#include <WebCore/DOMCacheEngine.h>
#include <WebCore/DOMCacheIdentifier.h>
#include <WebCore/IndexKey.h>
#include <WebCore/IndexedDB.h>
#include <WebCore/StorageType.h>
#include <optional>
#include <span>
#include <utility>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/HashMap.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
struct FileSystemHandleIdentifierType;
using FileSystemHandleIdentifier = AtomicObjectIdentifier<FileSystemHandleIdentifierType>;
struct FileSystemSyncAccessHandleIdentifierType;
using FileSystemSyncAccessHandleIdentifier = AtomicObjectIdentifier<FileSystemSyncAccessHandleIdentifierType>;
struct FileSystemWritableFileStreamIdentifierType;
using FileSystemWritableFileStreamIdentifier = AtomicObjectIdentifier<FileSystemWritableFileStreamIdentifierType>;
class IDBCursorInfo;
struct IDBDatabaseConnectionIdentifierType;
using IDBDatabaseConnectionIdentifier = AtomicObjectIdentifier<IDBDatabaseConnectionIdentifierType>;
struct IDBIndexIdentifierType;
using IDBIndexIdentifier = AtomicObjectIdentifier<IDBIndexIdentifierType>;
class IDBIndexInfo;
class IDBKeyData;
struct IDBObjectStoreIdentifierType;
using IDBObjectStoreIdentifier = AtomicObjectIdentifier<IDBObjectStoreIdentifierType>;
class IDBObjectStoreInfo;
class IDBOpenRequestData;
class IDBRequestData;
class IDBResourceIdentifier;
class IDBTransactionInfo;
class IDBValue;
class IndexKey;
class ResourceRequest;
enum class FileSystemWriteCloseReason : bool;
enum class FileSystemWriteCommandType : uint8_t;
struct CacheQueryOptions;
struct ClientOrigin;
struct IDBGetAllRecordsData;
struct IDBGetRecordData;
struct IDBIterateCursorData;
struct IDBKeyRangeData;
struct RetrieveRecordsOptions;
struct StorageEstimate;
}

namespace WebKit {
struct StorageAreaIdentifierType;
using StorageAreaIdentifier = AtomicObjectIdentifier<StorageAreaIdentifierType>;
struct StorageAreaImplIdentifierType;
using StorageAreaImplIdentifier = ObjectIdentifier<StorageAreaImplIdentifierType>;
struct StorageAreaMapIdentifierType;
using StorageAreaMapIdentifier = ObjectIdentifier<StorageAreaMapIdentifierType>;
struct StorageNamespaceIdentifierType;
using StorageNamespaceIdentifier = ObjectIdentifier<StorageNamespaceIdentifierType>;
}

namespace Messages {
namespace NetworkStorageManager {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInNetworkProcess());
        }
    );
#endif
    return IPC::ReceiverName::NetworkStorageManager;
}

class Persisted {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_Persisted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_PersistedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit Persisted(const WebCore::ClientOrigin& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class Persist {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_Persist; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_PersistReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit Persist(const WebCore::ClientOrigin& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class Estimate {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_Estimate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_EstimateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::StorageEstimate>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::StorageEstimate>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::StorageEstimate>, IPC::Error>;
    explicit Estimate(const WebCore::ClientOrigin& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class FileSystemGetDirectory {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_FileSystemGetDirectory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_FileSystemGetDirectoryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<WebCore::FileSystemHandleIdentifier>, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<WebCore::FileSystemHandleIdentifier>, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<WebCore::FileSystemHandleIdentifier>, WebKit::FileSystemStorageError>, IPC::Error>;
    explicit FileSystemGetDirectory(const WebCore::ClientOrigin& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class CloseHandle {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CloseHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CloseHandle(const WebCore::FileSystemHandleIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
};

class IsSameEntry {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, WebCore::FileSystemHandleIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_IsSameEntry; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_IsSameEntryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsSameEntry(const WebCore::FileSystemHandleIdentifier& identifier, const WebCore::FileSystemHandleIdentifier& targetIdentifier)
        : m_identifier(identifier)
        , m_targetIdentifier(targetIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_targetIdentifier;
};

class GetFileHandle {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetFileHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_GetFileHandleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::FileSystemHandleIdentifier, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<WebCore::FileSystemHandleIdentifier, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::FileSystemHandleIdentifier, WebKit::FileSystemStorageError>, IPC::Error>;
    GetFileHandle(const WebCore::FileSystemHandleIdentifier& identifier, const String& name, bool createIfNecessary)
        : m_identifier(identifier)
        , m_name(name)
        , m_createIfNecessary(createIfNecessary)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_name;
        encoder << m_createIfNecessary;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    const String& m_name;
    bool m_createIfNecessary;
};

class GetDirectoryHandle {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetDirectoryHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_GetDirectoryHandleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::FileSystemHandleIdentifier, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<WebCore::FileSystemHandleIdentifier, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::FileSystemHandleIdentifier, WebKit::FileSystemStorageError>, IPC::Error>;
    GetDirectoryHandle(const WebCore::FileSystemHandleIdentifier& identifier, const String& name, bool createIfNecessary)
        : m_identifier(identifier)
        , m_name(name)
        , m_createIfNecessary(createIfNecessary)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_name;
        encoder << m_createIfNecessary;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    const String& m_name;
    bool m_createIfNecessary;
};

class RemoveEntry {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_RemoveEntry; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_RemoveEntryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::FileSystemStorageError>, IPC::Error>;
    RemoveEntry(const WebCore::FileSystemHandleIdentifier& identifier, const String& name, bool deleteRecursively)
        : m_identifier(identifier)
        , m_name(name)
        , m_deleteRecursively(deleteRecursively)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_name;
        encoder << m_deleteRecursively;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    const String& m_name;
    bool m_deleteRecursively;
};

class Resolve {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, WebCore::FileSystemHandleIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_Resolve; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_ResolveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<String>, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<Vector<String>, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<String>, WebKit::FileSystemStorageError>, IPC::Error>;
    Resolve(const WebCore::FileSystemHandleIdentifier& identifier, const WebCore::FileSystemHandleIdentifier& targetIdentifier)
        : m_identifier(identifier)
        , m_targetIdentifier(targetIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_targetIdentifier;
};

class Move {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, WebCore::FileSystemHandleIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_Move; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_MoveReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::FileSystemStorageError>, IPC::Error>;
    Move(const WebCore::FileSystemHandleIdentifier& identifier, const WebCore::FileSystemHandleIdentifier& destinationIdentifier, const String& newName)
        : m_identifier(identifier)
        , m_destinationIdentifier(destinationIdentifier)
        , m_newName(newName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_destinationIdentifier;
        encoder << m_newName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_destinationIdentifier;
    const String& m_newName;
};

class GetFile {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetFile; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_GetFileReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<String, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<String, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<String, WebKit::FileSystemStorageError>, IPC::Error>;
    explicit GetFile(const WebCore::FileSystemHandleIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
};

class CreateSyncAccessHandle {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CreateSyncAccessHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CreateSyncAccessHandleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::FileSystemSyncAccessHandleInfo, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<WebKit::FileSystemSyncAccessHandleInfo, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::FileSystemSyncAccessHandleInfo, WebKit::FileSystemStorageError>, IPC::Error>;
    explicit CreateSyncAccessHandle(const WebCore::FileSystemHandleIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
};

class CloseSyncAccessHandle {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, WebCore::FileSystemSyncAccessHandleIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CloseSyncAccessHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CloseSyncAccessHandleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    CloseSyncAccessHandle(const WebCore::FileSystemHandleIdentifier& identifier, const WebCore::FileSystemSyncAccessHandleIdentifier& accessHandleIdentifier)
        : m_identifier(identifier)
        , m_accessHandleIdentifier(accessHandleIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_accessHandleIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemSyncAccessHandleIdentifier& m_accessHandleIdentifier;
};

class RequestNewCapacityForSyncAccessHandle {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, WebCore::FileSystemSyncAccessHandleIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_RequestNewCapacityForSyncAccessHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_RequestNewCapacityForSyncAccessHandleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<uint64_t>>;
    using Reply = CompletionHandler<void(std::optional<uint64_t>&&)>;
    using Promise = WTF::NativePromise<std::optional<uint64_t>, IPC::Error>;
    RequestNewCapacityForSyncAccessHandle(const WebCore::FileSystemHandleIdentifier& identifier, const WebCore::FileSystemSyncAccessHandleIdentifier& accessHandleIdentifier, uint64_t newCapacity)
        : m_identifier(identifier)
        , m_accessHandleIdentifier(accessHandleIdentifier)
        , m_newCapacity(newCapacity)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_accessHandleIdentifier;
        encoder << m_newCapacity;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemSyncAccessHandleIdentifier& m_accessHandleIdentifier;
    uint64_t m_newCapacity;
};

class CreateWritable {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CreateWritable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CreateWritableReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::FileSystemWritableFileStreamIdentifier, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<WebCore::FileSystemWritableFileStreamIdentifier, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::FileSystemWritableFileStreamIdentifier, WebKit::FileSystemStorageError>, IPC::Error>;
    CreateWritable(const WebCore::FileSystemHandleIdentifier& identifier, bool keepExistingData)
        : m_identifier(identifier)
        , m_keepExistingData(keepExistingData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_keepExistingData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    bool m_keepExistingData;
};

class CloseWritable {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, WebCore::FileSystemWritableFileStreamIdentifier, WebCore::FileSystemWriteCloseReason>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CloseWritable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CloseWritableReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::FileSystemStorageError>, IPC::Error>;
    CloseWritable(const WebCore::FileSystemHandleIdentifier& identifier, const WebCore::FileSystemWritableFileStreamIdentifier& streamIdentifier, WebCore::FileSystemWriteCloseReason reason)
        : m_identifier(identifier)
        , m_streamIdentifier(streamIdentifier)
        , m_reason(reason)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_streamIdentifier;
        encoder << m_reason;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemWritableFileStreamIdentifier& m_streamIdentifier;
    WebCore::FileSystemWriteCloseReason m_reason;
};

class ExecuteCommandForWritable {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, WebCore::FileSystemWritableFileStreamIdentifier, WebCore::FileSystemWriteCommandType, std::optional<uint64_t>, std::optional<uint64_t>, std::span<const uint8_t>, bool>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_ExecuteCommandForWritable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_ExecuteCommandForWritableReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::FileSystemStorageError>, IPC::Error>;
    ExecuteCommandForWritable(const WebCore::FileSystemHandleIdentifier& identifier, const WebCore::FileSystemWritableFileStreamIdentifier& streamIdentifier, WebCore::FileSystemWriteCommandType type, const std::optional<uint64_t>& position, const std::optional<uint64_t>& size, const std::span<const uint8_t>& dataBytes, bool hasDataError)
        : m_identifier(identifier)
        , m_streamIdentifier(streamIdentifier)
        , m_type(type)
        , m_position(position)
        , m_size(size)
        , m_dataBytes(dataBytes)
        , m_hasDataError(hasDataError)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_streamIdentifier;
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_position;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dataBytes;
        encoder << m_hasDataError;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemWritableFileStreamIdentifier& m_streamIdentifier;
    WebCore::FileSystemWriteCommandType m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_position;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_size;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_dataBytes;
    bool m_hasDataError;
};

class GetHandleNames {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetHandleNames; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_GetHandleNamesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Vector<String>, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<Vector<String>, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<Vector<String>, WebKit::FileSystemStorageError>, IPC::Error>;
    explicit GetHandleNames(const WebCore::FileSystemHandleIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
};

class GetHandle {
public:
    using Arguments = std::tuple<WebCore::FileSystemHandleIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetHandle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_GetHandleReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::optional<std::pair<WebCore::FileSystemHandleIdentifier, bool>>, WebKit::FileSystemStorageError>>;
    using Reply = CompletionHandler<void(Expected<std::optional<std::pair<WebCore::FileSystemHandleIdentifier, bool>>, WebKit::FileSystemStorageError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::optional<std::pair<WebCore::FileSystemHandleIdentifier, bool>>, WebKit::FileSystemStorageError>, IPC::Error>;
    GetHandle(const WebCore::FileSystemHandleIdentifier& identifier, const String& name)
        : m_identifier(identifier)
        , m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_name;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileSystemHandleIdentifier& m_identifier;
    const String& m_name;
};

class ConnectToStorageArea {
public:
    using Arguments = std::tuple<WebCore::StorageType, WebKit::StorageAreaMapIdentifier, std::optional<WebKit::StorageNamespaceIdentifier>, WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_ConnectToStorageArea; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_ConnectToStorageAreaReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::StorageAreaIdentifier>, HashMap<String, String>, uint64_t>;
    using Reply = CompletionHandler<void(std::optional<WebKit::StorageAreaIdentifier>&&, HashMap<String, String>&&, uint64_t)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebKit::StorageAreaIdentifier>, HashMap<String, String>, uint64_t>, IPC::Error>;
    ConnectToStorageArea(const WebCore::StorageType& type, const WebKit::StorageAreaMapIdentifier& sourceIdentifier, const std::optional<WebKit::StorageNamespaceIdentifier>& namespaceIdentifier, const WebCore::ClientOrigin& origin)
        : m_type(type)
        , m_sourceIdentifier(sourceIdentifier)
        , m_namespaceIdentifier(namespaceIdentifier)
        , m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourceIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_namespaceIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    const WebCore::StorageType& m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaMapIdentifier& m_sourceIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::StorageNamespaceIdentifier>& m_namespaceIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class ConnectToStorageAreaSync {
public:
    using Arguments = std::tuple<WebCore::StorageType, WebKit::StorageAreaMapIdentifier, std::optional<WebKit::StorageNamespaceIdentifier>, WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_ConnectToStorageAreaSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::StorageAreaIdentifier>, HashMap<String, String>, uint64_t>;
    using Reply = CompletionHandler<void(std::optional<WebKit::StorageAreaIdentifier>&&, HashMap<String, String>&&, uint64_t)>;
    ConnectToStorageAreaSync(const WebCore::StorageType& type, const WebKit::StorageAreaMapIdentifier& sourceIdentifier, const std::optional<WebKit::StorageNamespaceIdentifier>& namespaceIdentifier, const WebCore::ClientOrigin& origin)
        : m_type(type)
        , m_sourceIdentifier(sourceIdentifier)
        , m_namespaceIdentifier(namespaceIdentifier)
        , m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourceIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_namespaceIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    const WebCore::StorageType& m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaMapIdentifier& m_sourceIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::StorageNamespaceIdentifier>& m_namespaceIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class CancelConnectToStorageArea {
public:
    using Arguments = std::tuple<WebCore::StorageType, std::optional<WebKit::StorageNamespaceIdentifier>, WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CancelConnectToStorageArea; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelConnectToStorageArea(const WebCore::StorageType& type, const std::optional<WebKit::StorageNamespaceIdentifier>& namespaceIdentifier, const WebCore::ClientOrigin& origin)
        : m_type(type)
        , m_namespaceIdentifier(namespaceIdentifier)
        , m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_namespaceIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    const WebCore::StorageType& m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::StorageNamespaceIdentifier>& m_namespaceIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class DisconnectFromStorageArea {
public:
    using Arguments = std::tuple<WebKit::StorageAreaIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DisconnectFromStorageArea; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DisconnectFromStorageArea(const WebKit::StorageAreaIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaIdentifier& m_identifier;
};

class SetItem {
public:
    using Arguments = std::tuple<WebKit::StorageAreaIdentifier, WebKit::StorageAreaImplIdentifier, String, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_SetItem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_SetItemReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, HashMap<String, String>>;
    using Reply = CompletionHandler<void(bool, HashMap<String, String>&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, HashMap<String, String>>, IPC::Error>;
    SetItem(const WebKit::StorageAreaIdentifier& identifier, const WebKit::StorageAreaImplIdentifier& implIdentifier, const String& key, const String& value, const String& urlString)
        : m_identifier(identifier)
        , m_implIdentifier(implIdentifier)
        , m_key(key)
        , m_value(value)
        , m_urlString(urlString)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_implIdentifier;
        encoder << m_key;
        encoder << m_value;
        encoder << m_urlString;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaImplIdentifier& m_implIdentifier;
    const String& m_key;
    const String& m_value;
    const String& m_urlString;
};

class RemoveItem {
public:
    using Arguments = std::tuple<WebKit::StorageAreaIdentifier, WebKit::StorageAreaImplIdentifier, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_RemoveItem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_RemoveItemReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, HashMap<String, String>>;
    using Reply = CompletionHandler<void(bool, HashMap<String, String>&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, HashMap<String, String>>, IPC::Error>;
    RemoveItem(const WebKit::StorageAreaIdentifier& identifier, const WebKit::StorageAreaImplIdentifier& implIdentifier, const String& key, const String& urlString)
        : m_identifier(identifier)
        , m_implIdentifier(implIdentifier)
        , m_key(key)
        , m_urlString(urlString)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_implIdentifier;
        encoder << m_key;
        encoder << m_urlString;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaImplIdentifier& m_implIdentifier;
    const String& m_key;
    const String& m_urlString;
};

class Clear {
public:
    using Arguments = std::tuple<WebKit::StorageAreaIdentifier, WebKit::StorageAreaImplIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_Clear; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_ClearReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    Clear(const WebKit::StorageAreaIdentifier& identifier, const WebKit::StorageAreaImplIdentifier& implIdentifier, const String& urlString)
        : m_identifier(identifier)
        , m_implIdentifier(implIdentifier)
        , m_urlString(urlString)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_implIdentifier;
        encoder << m_urlString;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::StorageAreaImplIdentifier& m_implIdentifier;
    const String& m_urlString;
};

class OpenDatabase {
public:
    using Arguments = std::tuple<WebCore::IDBOpenRequestData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_OpenDatabase; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit OpenDatabase(const WebCore::IDBOpenRequestData& requestData)
        : m_requestData(requestData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBOpenRequestData& m_requestData;
};

class OpenDBRequestCancelled {
public:
    using Arguments = std::tuple<WebCore::IDBOpenRequestData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_OpenDBRequestCancelled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit OpenDBRequestCancelled(const WebCore::IDBOpenRequestData& requestData)
        : m_requestData(requestData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBOpenRequestData& m_requestData;
};

class DeleteDatabase {
public:
    using Arguments = std::tuple<WebCore::IDBOpenRequestData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DeleteDatabase; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DeleteDatabase(const WebCore::IDBOpenRequestData& requestData)
        : m_requestData(requestData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBOpenRequestData& m_requestData;
};

class EstablishTransaction {
public:
    using Arguments = std::tuple<WebCore::IDBDatabaseConnectionIdentifier, WebCore::IDBTransactionInfo>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_EstablishTransaction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EstablishTransaction(const WebCore::IDBDatabaseConnectionIdentifier& databaseConnectionIdentifier, const WebCore::IDBTransactionInfo& info)
        : m_databaseConnectionIdentifier(databaseConnectionIdentifier)
        , m_info(info)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databaseConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBDatabaseConnectionIdentifier& m_databaseConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBTransactionInfo& m_info;
};

class DatabaseConnectionPendingClose {
public:
    using Arguments = std::tuple<WebCore::IDBDatabaseConnectionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DatabaseConnectionPendingClose; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DatabaseConnectionPendingClose(const WebCore::IDBDatabaseConnectionIdentifier& databaseConnectionIdentifier)
        : m_databaseConnectionIdentifier(databaseConnectionIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databaseConnectionIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBDatabaseConnectionIdentifier& m_databaseConnectionIdentifier;
};

class DatabaseConnectionClosed {
public:
    using Arguments = std::tuple<WebCore::IDBDatabaseConnectionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DatabaseConnectionClosed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DatabaseConnectionClosed(const WebCore::IDBDatabaseConnectionIdentifier& databaseConnectionIdentifier)
        : m_databaseConnectionIdentifier(databaseConnectionIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databaseConnectionIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBDatabaseConnectionIdentifier& m_databaseConnectionIdentifier;
};

class AbortOpenAndUpgradeNeeded {
public:
    using Arguments = std::tuple<WebCore::IDBDatabaseConnectionIdentifier, std::optional<WebCore::IDBResourceIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_AbortOpenAndUpgradeNeeded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AbortOpenAndUpgradeNeeded(const WebCore::IDBDatabaseConnectionIdentifier& databaseConnectionIdentifier, const std::optional<WebCore::IDBResourceIdentifier>& transactionIdentifier)
        : m_databaseConnectionIdentifier(databaseConnectionIdentifier)
        , m_transactionIdentifier(transactionIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databaseConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transactionIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBDatabaseConnectionIdentifier& m_databaseConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::IDBResourceIdentifier>& m_transactionIdentifier;
};

class DidFireVersionChangeEvent {
public:
    using Arguments = std::tuple<WebCore::IDBDatabaseConnectionIdentifier, WebCore::IDBResourceIdentifier, WebCore::IndexedDB::ConnectionClosedOnBehalfOfServer>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DidFireVersionChangeEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFireVersionChangeEvent(const WebCore::IDBDatabaseConnectionIdentifier& databaseConnectionIdentifier, const WebCore::IDBResourceIdentifier& requestIdentifier, const WebCore::IndexedDB::ConnectionClosedOnBehalfOfServer& connectionClosedOnBehalfOfServer)
        : m_databaseConnectionIdentifier(databaseConnectionIdentifier)
        , m_requestIdentifier(requestIdentifier)
        , m_connectionClosedOnBehalfOfServer(connectionClosedOnBehalfOfServer)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databaseConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_connectionClosedOnBehalfOfServer;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBDatabaseConnectionIdentifier& m_databaseConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_requestIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IndexedDB::ConnectionClosedOnBehalfOfServer& m_connectionClosedOnBehalfOfServer;
};

class DidGenerateIndexKeyForRecord {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, WebCore::IDBResourceIdentifier, WebCore::IDBIndexInfo, WebCore::IDBKeyData, WebCore::IndexKey, std::optional<int64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DidGenerateIndexKeyForRecord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidGenerateIndexKeyForRecord(const WebCore::IDBResourceIdentifier& transactionIdentifier, const WebCore::IDBResourceIdentifier& requestIdentifier, const WebCore::IDBIndexInfo& indexInfo, const WebCore::IDBKeyData& key, const WebCore::IndexKey& indexKey, const std::optional<int64_t>& recordID)
        : m_transactionIdentifier(transactionIdentifier)
        , m_requestIdentifier(requestIdentifier)
        , m_indexInfo(indexInfo)
        , m_key(key)
        , m_indexKey(indexKey)
        , m_recordID(recordID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transactionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indexInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_key;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indexKey;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_recordID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_transactionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_requestIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBIndexInfo& m_indexInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBKeyData& m_key;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IndexKey& m_indexKey;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<int64_t>& m_recordID;
};

class DidFinishHandlingVersionChangeTransaction {
public:
    using Arguments = std::tuple<WebCore::IDBDatabaseConnectionIdentifier, WebCore::IDBResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DidFinishHandlingVersionChangeTransaction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishHandlingVersionChangeTransaction(const WebCore::IDBDatabaseConnectionIdentifier& databaseConnectionIdentifier, const WebCore::IDBResourceIdentifier& transactionIdentifier)
        : m_databaseConnectionIdentifier(databaseConnectionIdentifier)
        , m_transactionIdentifier(transactionIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databaseConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transactionIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBDatabaseConnectionIdentifier& m_databaseConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_transactionIdentifier;
};

class AbortTransaction {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_AbortTransaction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AbortTransaction(const WebCore::IDBResourceIdentifier& transactionIdentifier)
        : m_transactionIdentifier(transactionIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transactionIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_transactionIdentifier;
};

class CommitTransaction {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CommitTransaction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CommitTransaction(const WebCore::IDBResourceIdentifier& transactionIdentifier, uint64_t handledRequestResultsCount)
        : m_transactionIdentifier(transactionIdentifier)
        , m_handledRequestResultsCount(handledRequestResultsCount)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transactionIdentifier;
        encoder << m_handledRequestResultsCount;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_transactionIdentifier;
    uint64_t m_handledRequestResultsCount;
};

class CreateObjectStore {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBObjectStoreInfo>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CreateObjectStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateObjectStore(const WebCore::IDBRequestData& requestData, const WebCore::IDBObjectStoreInfo& info)
        : m_requestData(requestData)
        , m_info(info)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBObjectStoreInfo& m_info;
};

class DeleteObjectStore {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DeleteObjectStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DeleteObjectStore(const WebCore::IDBRequestData& requestData, const String& objectStoreName)
        : m_requestData(requestData)
        , m_objectStoreName(objectStoreName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        encoder << m_objectStoreName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    const String& m_objectStoreName;
};

class RenameObjectStore {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBObjectStoreIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_RenameObjectStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RenameObjectStore(const WebCore::IDBRequestData& requestData, const WebCore::IDBObjectStoreIdentifier& objectStoreIdentifier, const String& newName)
        : m_requestData(requestData)
        , m_objectStoreIdentifier(objectStoreIdentifier)
        , m_newName(newName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_objectStoreIdentifier;
        encoder << m_newName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBObjectStoreIdentifier& m_objectStoreIdentifier;
    const String& m_newName;
};

class ClearObjectStore {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBObjectStoreIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_ClearObjectStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearObjectStore(const WebCore::IDBRequestData& requestData, const WebCore::IDBObjectStoreIdentifier& objectStoreIdentifier)
        : m_requestData(requestData)
        , m_objectStoreIdentifier(objectStoreIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_objectStoreIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBObjectStoreIdentifier& m_objectStoreIdentifier;
};

class CreateIndex {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBIndexInfo>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CreateIndex; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateIndex(const WebCore::IDBRequestData& requestData, const WebCore::IDBIndexInfo& info)
        : m_requestData(requestData)
        , m_info(info)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBIndexInfo& m_info;
};

class DeleteIndex {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBObjectStoreIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DeleteIndex; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DeleteIndex(const WebCore::IDBRequestData& requestData, const WebCore::IDBObjectStoreIdentifier& objectStoreIdentifier, const String& indexName)
        : m_requestData(requestData)
        , m_objectStoreIdentifier(objectStoreIdentifier)
        , m_indexName(indexName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_objectStoreIdentifier;
        encoder << m_indexName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBObjectStoreIdentifier& m_objectStoreIdentifier;
    const String& m_indexName;
};

class RenameIndex {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBObjectStoreIdentifier, WebCore::IDBIndexIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_RenameIndex; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RenameIndex(const WebCore::IDBRequestData& requestData, const WebCore::IDBObjectStoreIdentifier& objectStoreIdentifier, const WebCore::IDBIndexIdentifier& indexIdentifier, const String& newName)
        : m_requestData(requestData)
        , m_objectStoreIdentifier(objectStoreIdentifier)
        , m_indexIdentifier(indexIdentifier)
        , m_newName(newName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_objectStoreIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indexIdentifier;
        encoder << m_newName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBObjectStoreIdentifier& m_objectStoreIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBIndexIdentifier& m_indexIdentifier;
    const String& m_newName;
};

class PutOrAdd {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBKeyData, WebCore::IDBValue, WebCore::IndexIDToIndexKeyMap, WebCore::IndexedDB::ObjectStoreOverwriteMode>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_PutOrAdd; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PutOrAdd(const WebCore::IDBRequestData& requestData, const WebCore::IDBKeyData& key, const WebCore::IDBValue& value, const WebCore::IndexIDToIndexKeyMap& indexKeys, const WebCore::IndexedDB::ObjectStoreOverwriteMode& overwriteMode)
        : m_requestData(requestData)
        , m_key(key)
        , m_value(value)
        , m_indexKeys(indexKeys)
        , m_overwriteMode(overwriteMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_key;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
        encoder << m_indexKeys;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_overwriteMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBKeyData& m_key;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBValue& m_value;
    const WebCore::IndexIDToIndexKeyMap& m_indexKeys;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IndexedDB::ObjectStoreOverwriteMode& m_overwriteMode;
};

class GetRecord {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBGetRecordData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetRecord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GetRecord(const WebCore::IDBRequestData& requestData, const WebCore::IDBGetRecordData& getRecordData)
        : m_requestData(requestData)
        , m_getRecordData(getRecordData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_getRecordData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBGetRecordData& m_getRecordData;
};

class GetAllRecords {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBGetAllRecordsData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetAllRecords; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GetAllRecords(const WebCore::IDBRequestData& requestData, const WebCore::IDBGetAllRecordsData& getAllRecordsData)
        : m_requestData(requestData)
        , m_getAllRecordsData(getAllRecordsData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_getAllRecordsData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBGetAllRecordsData& m_getAllRecordsData;
};

class GetCount {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBKeyRangeData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetCount; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GetCount(const WebCore::IDBRequestData& requestData, const WebCore::IDBKeyRangeData& range)
        : m_requestData(requestData)
        , m_range(range)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBKeyRangeData& m_range;
};

class DeleteRecord {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBKeyRangeData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_DeleteRecord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DeleteRecord(const WebCore::IDBRequestData& requestData, const WebCore::IDBKeyRangeData& range)
        : m_requestData(requestData)
        , m_range(range)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBKeyRangeData& m_range;
};

class OpenCursor {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBCursorInfo>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_OpenCursor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    OpenCursor(const WebCore::IDBRequestData& requestData, const WebCore::IDBCursorInfo& info)
        : m_requestData(requestData)
        , m_info(info)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBCursorInfo& m_info;
};

class IterateCursor {
public:
    using Arguments = std::tuple<WebCore::IDBRequestData, WebCore::IDBIterateCursorData>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_IterateCursor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    IterateCursor(const WebCore::IDBRequestData& requestData, const WebCore::IDBIterateCursorData& data)
        : m_requestData(requestData)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBRequestData& m_requestData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBIterateCursorData& m_data;
};

class GetAllDatabaseNamesAndVersions {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_GetAllDatabaseNamesAndVersions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GetAllDatabaseNamesAndVersions(const WebCore::IDBResourceIdentifier& requestIdentifier, const WebCore::ClientOrigin& origin)
        : m_requestIdentifier(requestIdentifier)
        , m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_requestIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class CacheStorageOpenCache {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin, String>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageOpenCache; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CacheStorageOpenCacheReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DOMCacheEngine::CacheIdentifierOrError>;
    using Reply = CompletionHandler<void(WebCore::DOMCacheEngine::CacheIdentifierOrError&&)>;
    using Promise = WTF::NativePromise<WebCore::DOMCacheEngine::CacheIdentifierOrError, IPC::Error>;
    CacheStorageOpenCache(const WebCore::ClientOrigin& origin, const String& cacheName)
        : m_origin(origin)
        , m_cacheName(cacheName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        encoder << m_cacheName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    const String& m_cacheName;
};

class CacheStorageRemoveCache {
public:
    using Arguments = std::tuple<WebCore::DOMCacheIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageRemoveCache; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CacheStorageRemoveCacheReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DOMCacheEngine::RemoveCacheIdentifierOrError>;
    using Reply = CompletionHandler<void(WebCore::DOMCacheEngine::RemoveCacheIdentifierOrError&&)>;
    using Promise = WTF::NativePromise<WebCore::DOMCacheEngine::RemoveCacheIdentifierOrError, IPC::Error>;
    explicit CacheStorageRemoveCache(const WebCore::DOMCacheIdentifier& cacheIdentifier)
        : m_cacheIdentifier(cacheIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheIdentifier;
    }

private:
    const WebCore::DOMCacheIdentifier& m_cacheIdentifier;
};

class CacheStorageAllCaches {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageAllCaches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CacheStorageAllCachesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DOMCacheEngine::CacheInfosOrError>;
    using Reply = CompletionHandler<void(WebCore::DOMCacheEngine::CacheInfosOrError&&)>;
    using Promise = WTF::NativePromise<WebCore::DOMCacheEngine::CacheInfosOrError, IPC::Error>;
    CacheStorageAllCaches(const WebCore::ClientOrigin& origin, uint64_t updateCounter)
        : m_origin(origin)
        , m_updateCounter(updateCounter)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        encoder << m_updateCounter;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    uint64_t m_updateCounter;
};

class CacheStorageReference {
public:
    using Arguments = std::tuple<WebCore::DOMCacheIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageReference; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CacheStorageReference(const WebCore::DOMCacheIdentifier& cacheIdentifier)
        : m_cacheIdentifier(cacheIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheIdentifier;
    }

private:
    const WebCore::DOMCacheIdentifier& m_cacheIdentifier;
};

class CacheStorageDereference {
public:
    using Arguments = std::tuple<WebCore::DOMCacheIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageDereference; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CacheStorageDereference(const WebCore::DOMCacheIdentifier& cacheIdentifier)
        : m_cacheIdentifier(cacheIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheIdentifier;
    }

private:
    const WebCore::DOMCacheIdentifier& m_cacheIdentifier;
};

class LockCacheStorage {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_LockCacheStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit LockCacheStorage(const WebCore::ClientOrigin& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class UnlockCacheStorage {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_UnlockCacheStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UnlockCacheStorage(const WebCore::ClientOrigin& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class CacheStorageRetrieveRecords {
public:
    using Arguments = std::tuple<WebCore::DOMCacheIdentifier, WebCore::RetrieveRecordsOptions>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageRetrieveRecords; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CacheStorageRetrieveRecordsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DOMCacheEngine::CrossThreadRecordsOrError>;
    using Reply = CompletionHandler<void(WebCore::DOMCacheEngine::CrossThreadRecordsOrError&&)>;
    using Promise = WTF::NativePromise<WebCore::DOMCacheEngine::CrossThreadRecordsOrError, IPC::Error>;
    CacheStorageRetrieveRecords(const WebCore::DOMCacheIdentifier& cacheIdentifier, const WebCore::RetrieveRecordsOptions& options)
        : m_cacheIdentifier(cacheIdentifier)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    const WebCore::DOMCacheIdentifier& m_cacheIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RetrieveRecordsOptions& m_options;
};

class CacheStorageRemoveRecords {
public:
    using Arguments = std::tuple<WebCore::DOMCacheIdentifier, WebCore::ResourceRequest, WebCore::CacheQueryOptions>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageRemoveRecords; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CacheStorageRemoveRecordsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DOMCacheEngine::RecordIdentifiersOrError>;
    using Reply = CompletionHandler<void(WebCore::DOMCacheEngine::RecordIdentifiersOrError&&)>;
    using Promise = WTF::NativePromise<WebCore::DOMCacheEngine::RecordIdentifiersOrError, IPC::Error>;
    CacheStorageRemoveRecords(const WebCore::DOMCacheIdentifier& cacheIdentifier, const WebCore::ResourceRequest& request, const WebCore::CacheQueryOptions& options)
        : m_cacheIdentifier(cacheIdentifier)
        , m_request(request)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    const WebCore::DOMCacheIdentifier& m_cacheIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CacheQueryOptions& m_options;
};

class CacheStoragePutRecords {
public:
    using Arguments = std::tuple<WebCore::DOMCacheIdentifier, Vector<WebCore::DOMCacheEngine::CrossThreadRecord>>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStoragePutRecords; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CacheStoragePutRecordsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DOMCacheEngine::RecordIdentifiersOrError>;
    using Reply = CompletionHandler<void(WebCore::DOMCacheEngine::RecordIdentifiersOrError&&)>;
    using Promise = WTF::NativePromise<WebCore::DOMCacheEngine::RecordIdentifiersOrError, IPC::Error>;
    CacheStoragePutRecords(const WebCore::DOMCacheIdentifier& cacheIdentifier, const Vector<WebCore::DOMCacheEngine::CrossThreadRecord>& records)
        : m_cacheIdentifier(cacheIdentifier)
        , m_records(records)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_records;
    }

private:
    const WebCore::DOMCacheIdentifier& m_cacheIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::DOMCacheEngine::CrossThreadRecord>& m_records;
};

class CacheStorageClearMemoryRepresentation {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageClearMemoryRepresentation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CacheStorageClearMemoryRepresentationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit CacheStorageClearMemoryRepresentation(const WebCore::ClientOrigin& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class CacheStorageRepresentation {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_CacheStorageRepresentation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::NetworkStorageManager_CacheStorageRepresentationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    CacheStorageRepresentation()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ResetQuotaUpdatedBasedOnUsageForTesting {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::NetworkStorageManager_ResetQuotaUpdatedBasedOnUsageForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ResetQuotaUpdatedBasedOnUsageForTesting(const WebCore::ClientOrigin& origin)
        : m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

} // namespace NetworkStorageManager
} // namespace Messages
