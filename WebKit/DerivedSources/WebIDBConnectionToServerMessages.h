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
#include "WebIDBResult.h"
#include <WebCore/IDBKeyPath.h>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace WebCore {
struct IDBDatabaseConnectionIdentifierType;
using IDBDatabaseConnectionIdentifier = AtomicObjectIdentifier<IDBDatabaseConnectionIdentifierType>;
class IDBError;
class IDBIndexInfo;
class IDBKeyData;
class IDBResourceIdentifier;
class IDBResultData;
class IDBValue;
}

namespace Messages {
namespace WebIDBConnectionToServer {

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
    return IPC::ReceiverName::WebIDBConnectionToServer;
}

class DidDeleteDatabase {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidDeleteDatabase; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDeleteDatabase(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidOpenDatabase {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidOpenDatabase; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidOpenDatabase(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidAbortTransaction {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, WebCore::IDBError>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidAbortTransaction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidAbortTransaction(const WebCore::IDBResourceIdentifier& transactionIdentifier, const WebCore::IDBError& error)
        : m_transactionIdentifier(transactionIdentifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transactionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_transactionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBError& m_error;
};

class DidCommitTransaction {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, WebCore::IDBError>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidCommitTransaction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCommitTransaction(const WebCore::IDBResourceIdentifier& transactionIdentifier, const WebCore::IDBError& error)
        : m_transactionIdentifier(transactionIdentifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transactionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_transactionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBError& m_error;
};

class DidCreateObjectStore {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidCreateObjectStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidCreateObjectStore(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidDeleteObjectStore {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidDeleteObjectStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDeleteObjectStore(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidRenameObjectStore {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidRenameObjectStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidRenameObjectStore(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidClearObjectStore {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidClearObjectStore; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidClearObjectStore(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidCreateIndex {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidCreateIndex; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidCreateIndex(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidDeleteIndex {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidDeleteIndex; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDeleteIndex(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidRenameIndex {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidRenameIndex; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidRenameIndex(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidPutOrAdd {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidPutOrAdd; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidPutOrAdd(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidGetRecord {
public:
    using Arguments = std::tuple<WebKit::WebIDBResult>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidGetRecord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidGetRecord(WebKit::WebIDBResult&& result)
        : m_result(WTFMove(result))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_result);
    }

private:
    WebKit::WebIDBResult&& m_result;
};

class DidGetAllRecords {
public:
    using Arguments = std::tuple<WebKit::WebIDBResult>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidGetAllRecords; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidGetAllRecords(WebKit::WebIDBResult&& result)
        : m_result(WTFMove(result))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_result);
    }

private:
    WebKit::WebIDBResult&& m_result;
};

class DidGetCount {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidGetCount; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidGetCount(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidDeleteRecord {
public:
    using Arguments = std::tuple<WebCore::IDBResultData>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidDeleteRecord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDeleteRecord(const WebCore::IDBResultData& result)
        : m_result(result)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResultData& m_result;
};

class DidOpenCursor {
public:
    using Arguments = std::tuple<WebKit::WebIDBResult>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidOpenCursor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidOpenCursor(WebKit::WebIDBResult&& result)
        : m_result(WTFMove(result))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_result);
    }

private:
    WebKit::WebIDBResult&& m_result;
};

class DidIterateCursor {
public:
    using Arguments = std::tuple<WebKit::WebIDBResult>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidIterateCursor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidIterateCursor(WebKit::WebIDBResult&& result)
        : m_result(WTFMove(result))
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_result);
    }

private:
    WebKit::WebIDBResult&& m_result;
};

class FireVersionChangeEvent {
public:
    using Arguments = std::tuple<WebCore::IDBDatabaseConnectionIdentifier, WebCore::IDBResourceIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_FireVersionChangeEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FireVersionChangeEvent(const WebCore::IDBDatabaseConnectionIdentifier& databaseConnectionIdentifier, const WebCore::IDBResourceIdentifier& requestIdentifier, uint64_t requestedVersion)
        : m_databaseConnectionIdentifier(databaseConnectionIdentifier)
        , m_requestIdentifier(requestIdentifier)
        , m_requestedVersion(requestedVersion)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databaseConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        encoder << m_requestedVersion;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBDatabaseConnectionIdentifier& m_databaseConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_requestIdentifier;
    uint64_t m_requestedVersion;
};

class GenerateIndexKeyForRecord {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, WebCore::IDBIndexInfo, std::optional<WebCore::IDBKeyPath>, WebCore::IDBKeyData, WebCore::IDBValue, std::optional<int64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_GenerateIndexKeyForRecord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GenerateIndexKeyForRecord(const WebCore::IDBResourceIdentifier& requestIdentifier, const WebCore::IDBIndexInfo& indexInfo, const std::optional<WebCore::IDBKeyPath>& keyPath, const WebCore::IDBKeyData& key, const WebCore::IDBValue& value, const std::optional<int64_t>& recordID)
        : m_requestIdentifier(requestIdentifier)
        , m_indexInfo(indexInfo)
        , m_keyPath(keyPath)
        , m_key(key)
        , m_value(value)
        , m_recordID(recordID)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indexInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_keyPath;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_key;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_recordID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_requestIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBIndexInfo& m_indexInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::IDBKeyPath>& m_keyPath;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBKeyData& m_key;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBValue& m_value;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<int64_t>& m_recordID;
};

class DidStartTransaction {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, WebCore::IDBError>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidStartTransaction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStartTransaction(const WebCore::IDBResourceIdentifier& transactionIdentifier, const WebCore::IDBError& error)
        : m_transactionIdentifier(transactionIdentifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transactionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_transactionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBError& m_error;
};

class DidCloseFromServer {
public:
    using Arguments = std::tuple<WebCore::IDBDatabaseConnectionIdentifier, WebCore::IDBError>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidCloseFromServer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCloseFromServer(const WebCore::IDBDatabaseConnectionIdentifier& databaseConnectionIdentifier, const WebCore::IDBError& error)
        : m_databaseConnectionIdentifier(databaseConnectionIdentifier)
        , m_error(error)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databaseConnectionIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBDatabaseConnectionIdentifier& m_databaseConnectionIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBError& m_error;
};

class NotifyOpenDBRequestBlocked {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_NotifyOpenDBRequestBlocked; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyOpenDBRequestBlocked(const WebCore::IDBResourceIdentifier& requestIdentifier, uint64_t oldVersion, uint64_t newVersion)
        : m_requestIdentifier(requestIdentifier)
        , m_oldVersion(oldVersion)
        , m_newVersion(newVersion)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        encoder << m_oldVersion;
        encoder << m_newVersion;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_requestIdentifier;
    uint64_t m_oldVersion;
    uint64_t m_newVersion;
};

class DidGetAllDatabaseNamesAndVersions {
public:
    using Arguments = std::tuple<WebCore::IDBResourceIdentifier, Vector<WebCore::IDBDatabaseNameAndVersion>>;

    static IPC::MessageName name() { return IPC::MessageName::WebIDBConnectionToServer_DidGetAllDatabaseNamesAndVersions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidGetAllDatabaseNamesAndVersions(const WebCore::IDBResourceIdentifier& requestIdentifier, const Vector<WebCore::IDBDatabaseNameAndVersion>& databases)
        : m_requestIdentifier(requestIdentifier)
        , m_databases(databases)
    {
        ASSERT(isInNetworkProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_databases;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IDBResourceIdentifier& m_requestIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::IDBDatabaseNameAndVersion>& m_databases;
};

} // namespace WebIDBConnectionToServer
} // namespace Messages
