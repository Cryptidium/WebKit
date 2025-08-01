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

#include "AdditionalFonts.h"
#include "ArgumentCoders.h"
#include "Connection.h"
#include "MediaDeviceSandboxExtensions.h"
#include "MessageNames.h"
#include "SandboxExtension.h"
#include "WebPageCreationParameters.h"
#include "WebProcessCreationParameters.h"
#include "WebProcessDataStoreParameters.h"
#include <WebCore/BackForwardItemIdentifier.h>
#include <WebCore/ProcessIdentity.h>
#include <WebCore/ProcessQualified.h>
#include <WebCore/ScriptExecutionContextIdentifier.h>
#include <optional>
#include <span>
#include <wtf/Forward.h>
#include <wtf/HashMap.h>
#include <wtf/HashSet.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/OptionSet.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/URLHash.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class SharedBufferReference;
}

namespace PAL {
enum class UserInterfaceIdiom : uint8_t;
}

namespace WebCore {
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
class RegistrableDomain;
class Site;
enum class EventMakesGamepadsVisible : bool;
enum class CaptionUserPreferencesDisplayMode : uint8_t;
enum class ThirdPartyCookieBlockingMode : uint8_t;
struct ClientOrigin;
struct DisplayUpdate;
struct MockMediaDevice;
struct PrewarmInformation;
struct ScreenProperties;
}

namespace WebKit {
class GamepadData;
struct PageGroupIdentifierType;
using PageGroupIdentifier = ObjectIdentifier<PageGroupIdentifierType>;
class UserData;
class WebCompiledContentRuleListData;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
enum class CacheModel : uint8_t;
enum class RemoteWorkerType : uint8_t;
struct AccessibilityPreferences;
struct RemoteWorkerInitializationData;
struct ScriptTrackingPrivacyRules;
struct UserMessage;
struct WebPreferencesStore;
struct WebsiteData;
}

namespace Messages {
namespace WebProcess {

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
    return IPC::ReceiverName::WebProcess;
}

class InitializeWebProcess {
public:
    using Arguments = std::tuple<WebKit::WebProcessCreationParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_InitializeWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_InitializeWebProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ProcessIdentity>;
    using Reply = CompletionHandler<void(WebCore::ProcessIdentity&&)>;
    using Promise = WTF::NativePromise<WebCore::ProcessIdentity, IPC::Error>;
    explicit InitializeWebProcess(WebKit::WebProcessCreationParameters&& processCreationParameters)
        : m_processCreationParameters(WTFMove(processCreationParameters))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_processCreationParameters);
    }

private:
    WebKit::WebProcessCreationParameters&& m_processCreationParameters;
};

class SetWebsiteDataStoreParameters {
public:
    using Arguments = std::tuple<WebKit::WebProcessDataStoreParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetWebsiteDataStoreParameters; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetWebsiteDataStoreParameters(WebKit::WebProcessDataStoreParameters&& parameters)
        : m_parameters(WTFMove(parameters))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_parameters);
    }

private:
    WebKit::WebProcessDataStoreParameters&& m_parameters;
};

class CreateWebPage {
public:
    using Arguments = std::tuple<WebCore::PageIdentifier, WebKit::WebPageCreationParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_CreateWebPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateWebPage(const WebCore::PageIdentifier& newPageID, WebKit::WebPageCreationParameters&& pageCreationParameters)
        : m_newPageID(newPageID)
        , m_pageCreationParameters(WTFMove(pageCreationParameters))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newPageID;
        encoder << WTFMove(m_pageCreationParameters);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_newPageID;
    WebKit::WebPageCreationParameters&& m_pageCreationParameters;
};

class PrewarmWithDomainInformation {
public:
    using Arguments = std::tuple<WebCore::PrewarmInformation>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_PrewarmWithDomainInformation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PrewarmWithDomainInformation(const WebCore::PrewarmInformation& prewarmInformation)
        : m_prewarmInformation(prewarmInformation)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_prewarmInformation;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PrewarmInformation& m_prewarmInformation;
};

class SetCacheModel {
public:
    using Arguments = std::tuple<WebKit::CacheModel>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetCacheModel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCacheModel(WebKit::CacheModel cacheModel)
        : m_cacheModel(cacheModel)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_cacheModel;
    }

private:
    WebKit::CacheModel m_cacheModel;
};

class RegisterURLSchemeAsEmptyDocument {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsEmptyDocument; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsEmptyDocument(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class RegisterURLSchemeAsSecure {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsSecure; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsSecure(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class RegisterURLSchemeAsBypassingContentSecurityPolicy {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsBypassingContentSecurityPolicy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsBypassingContentSecurityPolicy(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class SetDomainRelaxationForbiddenForURLScheme {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetDomainRelaxationForbiddenForURLScheme; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDomainRelaxationForbiddenForURLScheme(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class RegisterURLSchemeAsLocal {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsLocal; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsLocal(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

#if ENABLE(ALL_LEGACY_REGISTERED_SPECIAL_URL_SCHEMES)
class RegisterURLSchemeAsNoAccess {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsNoAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsNoAccess(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};
#endif

class RegisterURLSchemeAsDisplayIsolated {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsDisplayIsolated; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsDisplayIsolated(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class RegisterURLSchemeAsCORSEnabled {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsCORSEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsCORSEnabled(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class RegisterURLSchemeAsCachePartitioned {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsCachePartitioned; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsCachePartitioned(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

class RegisterURLSchemeAsCanDisplayOnlyIfCanRequest {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsCanDisplayOnlyIfCanRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsCanDisplayOnlyIfCanRequest(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};

#if ENABLE(WK_WEB_EXTENSIONS)
class RegisterURLSchemeAsWebExtension {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterURLSchemeAsWebExtension; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterURLSchemeAsWebExtension(const String& scheme)
        : m_scheme(scheme)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scheme;
    }

private:
    const String& m_scheme;
};
#endif

class SetDefaultRequestTimeoutInterval {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetDefaultRequestTimeoutInterval; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDefaultRequestTimeoutInterval(double timeoutInterval)
        : m_timeoutInterval(timeoutInterval)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_timeoutInterval;
    }

private:
    double m_timeoutInterval;
};

class SetAlwaysUsesComplexTextCodePath {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetAlwaysUsesComplexTextCodePath; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAlwaysUsesComplexTextCodePath(bool alwaysUseComplexText)
        : m_alwaysUseComplexText(alwaysUseComplexText)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_alwaysUseComplexText;
    }

private:
    bool m_alwaysUseComplexText;
};

class SetDisableFontSubpixelAntialiasingForTesting {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetDisableFontSubpixelAntialiasingForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDisableFontSubpixelAntialiasingForTesting(bool disable)
        : m_disable(disable)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_disable;
    }

private:
    bool m_disable;
};

class SetTrackingPreventionEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetTrackingPreventionEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetTrackingPreventionEnabled(bool enabled)
        : m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enabled;
    }

private:
    bool m_enabled;
};

class ClearResourceLoadStatistics {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ClearResourceLoadStatistics; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearResourceLoadStatistics()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class UserPreferredLanguagesChanged {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_UserPreferredLanguagesChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UserPreferredLanguagesChanged(const Vector<String>& languages)
        : m_languages(languages)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_languages;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_languages;
};

class FullKeyboardAccessModeChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_FullKeyboardAccessModeChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FullKeyboardAccessModeChanged(bool fullKeyboardAccessEnabled)
        : m_fullKeyboardAccessEnabled(fullKeyboardAccessEnabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_fullKeyboardAccessEnabled;
    }

private:
    bool m_fullKeyboardAccessEnabled;
};

class UpdateStorageAccessUserAgentStringQuirks {
public:
    using Arguments = std::tuple<HashMap<WebCore::RegistrableDomain, String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_UpdateStorageAccessUserAgentStringQuirks; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateStorageAccessUserAgentStringQuirks(const HashMap<WebCore::RegistrableDomain, String>& userAgentStringQuirks)
        : m_userAgentStringQuirks(userAgentStringQuirks)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userAgentStringQuirks;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<WebCore::RegistrableDomain, String>& m_userAgentStringQuirks;
};

#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES)
class SetOptInCookiePartitioningEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetOptInCookiePartitioningEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetOptInCookiePartitioningEnabled(bool enabled)
        : m_enabled(enabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enabled;
    }

private:
    bool m_enabled;
};
#endif

#if HAVE(MOUSE_DEVICE_OBSERVATION)
class SetHasMouseDevice {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetHasMouseDevice; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasMouseDevice(bool hasMouseDevice)
        : m_hasMouseDevice(hasMouseDevice)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasMouseDevice;
    }

private:
    bool m_hasMouseDevice;
};
#endif

#if HAVE(STYLUS_DEVICE_OBSERVATION)
class SetHasStylusDevice {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetHasStylusDevice; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasStylusDevice(bool hasStylusDevice)
        : m_hasStylusDevice(hasStylusDevice)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasStylusDevice;
    }

private:
    bool m_hasStylusDevice;
};
#endif

class StartMemorySampler {
public:
    using Arguments = std::tuple<WebKit::SandboxExtensionHandle, String, double>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_StartMemorySampler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartMemorySampler(WebKit::SandboxExtensionHandle&& sampleLogFileHandle, const String& sampleLogFilePath, double interval)
        : m_sampleLogFileHandle(WTFMove(sampleLogFileHandle))
        , m_sampleLogFilePath(sampleLogFilePath)
        , m_interval(interval)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_sampleLogFileHandle);
        encoder << m_sampleLogFilePath;
        encoder << m_interval;
    }

private:
    WebKit::SandboxExtensionHandle&& m_sampleLogFileHandle;
    const String& m_sampleLogFilePath;
    double m_interval;
};

class StopMemorySampler {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_StopMemorySampler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopMemorySampler()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetTextCheckerState {
public:
    using Arguments = std::tuple<OptionSet<WebKit::TextCheckerState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetTextCheckerState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetTextCheckerState(const OptionSet<WebKit::TextCheckerState>& textCheckerState)
        : m_textCheckerState(textCheckerState)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_textCheckerState;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::TextCheckerState>& m_textCheckerState;
};

class SetEnhancedAccessibility {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetEnhancedAccessibility; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetEnhancedAccessibility(bool flag)
        : m_flag(flag)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_flag;
    }

private:
    bool m_flag;
};

class BindAccessibilityFrameWithData {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_BindAccessibilityFrameWithData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BindAccessibilityFrameWithData(const WebCore::FrameIdentifier& frameID, const std::span<const uint8_t>& data)
        : m_frameID(frameID)
        , m_data(data)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class GarbageCollectJavaScriptObjects {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_GarbageCollectJavaScriptObjects; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GarbageCollectJavaScriptObjects()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetJavaScriptGarbageCollectorTimerEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetJavaScriptGarbageCollectorTimerEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetJavaScriptGarbageCollectorTimerEnabled(bool enable)
        : m_enable(enable)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enable;
    }

private:
    bool m_enable;
};

class SetInjectedBundleParameter {
public:
    using Arguments = std::tuple<String, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetInjectedBundleParameter; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetInjectedBundleParameter(const String& parameter, const std::span<const uint8_t>& value)
        : m_parameter(parameter)
        , m_value(value)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_parameter;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
    }

private:
    const String& m_parameter;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_value;
};

class SetInjectedBundleParameters {
public:
    using Arguments = std::tuple<std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetInjectedBundleParameters; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetInjectedBundleParameters(const std::span<const uint8_t>& parameters)
        : m_parameters(parameters)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_parameters;
};

class HandleInjectedBundleMessage {
public:
    using Arguments = std::tuple<String, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_HandleInjectedBundleMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleInjectedBundleMessage(const String& messageName, const WebKit::UserData& messageBody)
        : m_messageName(messageName)
        , m_messageBody(messageBody)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_messageName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_messageBody;
    }

private:
    const String& m_messageName;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_messageBody;
};

class FetchWebsiteData {
public:
    using Arguments = std::tuple<OptionSet<WebKit::WebsiteDataType>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_FetchWebsiteData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_FetchWebsiteDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::WebsiteData>;
    using Reply = CompletionHandler<void(WebKit::WebsiteData&&)>;
    using Promise = WTF::NativePromise<WebKit::WebsiteData, IPC::Error>;
    explicit FetchWebsiteData(const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes)
        : m_websiteDataTypes(websiteDataTypes)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
};

class DeleteWebsiteData {
public:
    using Arguments = std::tuple<OptionSet<WebKit::WebsiteDataType>, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_DeleteWebsiteData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_DeleteWebsiteDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteWebsiteData(const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes, const WallTime& modifiedSince)
        : m_websiteDataTypes(websiteDataTypes)
        , m_modifiedSince(modifiedSince)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiedSince;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_modifiedSince;
};

class DeleteWebsiteDataForOrigins {
public:
    using Arguments = std::tuple<OptionSet<WebKit::WebsiteDataType>, Vector<WebCore::SecurityOriginData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_DeleteWebsiteDataForOrigins; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_DeleteWebsiteDataForOriginsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteWebsiteDataForOrigins(const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes, const Vector<WebCore::SecurityOriginData>& origins)
        : m_websiteDataTypes(websiteDataTypes)
        , m_origins(origins)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origins;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::SecurityOriginData>& m_origins;
};

class DeleteWebsiteDataForOrigin {
public:
    using Arguments = std::tuple<OptionSet<WebKit::WebsiteDataType>, WebCore::ClientOrigin>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_DeleteWebsiteDataForOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_DeleteWebsiteDataForOriginReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteWebsiteDataForOrigin(const OptionSet<WebKit::WebsiteDataType>& websiteDataTypes, const WebCore::ClientOrigin& origin)
        : m_websiteDataTypes(websiteDataTypes)
        , m_origin(origin)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websiteDataTypes;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebsiteDataType>& m_websiteDataTypes;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
};

class ReloadExecutionContextsForOrigin {
public:
    using Arguments = std::tuple<WebCore::ClientOrigin, std::optional<WebCore::FrameIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ReloadExecutionContextsForOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_ReloadExecutionContextsForOriginReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ReloadExecutionContextsForOrigin(const WebCore::ClientOrigin& origin, const std::optional<WebCore::FrameIdentifier>& triggeringFrame)
        : m_origin(origin)
        , m_triggeringFrame(triggeringFrame)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_triggeringFrame;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_origin;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_triggeringFrame;
};

class DeleteAllCookies {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_DeleteAllCookies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_DeleteAllCookiesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    DeleteAllCookies()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetHiddenPageDOMTimerThrottlingIncreaseLimit {
public:
    using Arguments = std::tuple<Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetHiddenPageDOMTimerThrottlingIncreaseLimit; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = true;

    explicit SetHiddenPageDOMTimerThrottlingIncreaseLimit(const Seconds& seconds)
        : m_seconds(seconds)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    void encodeCoalescingKey(IPC::Encoder&) const
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_seconds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_seconds;
};

class SetMemoryCacheDisabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetMemoryCacheDisabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMemoryCacheDisabled(bool disabled)
        : m_disabled(disabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_disabled;
    }

private:
    bool m_disabled;
};

#if ENABLE(SERVICE_CONTROLS)
class SetEnabledServices {
public:
    using Arguments = std::tuple<bool, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetEnabledServices; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetEnabledServices(bool hasImageServices, bool hasSelectionServices, bool hasRichContentServices)
        : m_hasImageServices(hasImageServices)
        , m_hasSelectionServices(hasSelectionServices)
        , m_hasRichContentServices(hasRichContentServices)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasImageServices;
        encoder << m_hasSelectionServices;
        encoder << m_hasRichContentServices;
    }

private:
    bool m_hasImageServices;
    bool m_hasSelectionServices;
    bool m_hasRichContentServices;
};
#endif

class EnsureAutomationSessionProxy {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_EnsureAutomationSessionProxy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit EnsureAutomationSessionProxy(const String& sessionIdentifier)
        : m_sessionIdentifier(sessionIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sessionIdentifier;
    }

private:
    const String& m_sessionIdentifier;
};

class DestroyAutomationSessionProxy {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_DestroyAutomationSessionProxy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DestroyAutomationSessionProxy()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PrepareToSuspend {
public:
    using Arguments = std::tuple<bool, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_PrepareToSuspend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_PrepareToSuspendReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PrepareToSuspend(bool isSuspensionImminent, const MonotonicTime& estimatedSuspendTime)
        : m_isSuspensionImminent(isSuspensionImminent)
        , m_estimatedSuspendTime(estimatedSuspendTime)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isSuspensionImminent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_estimatedSuspendTime;
    }

private:
    bool m_isSuspensionImminent;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_estimatedSuspendTime;
};

class ProcessDidResume {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ProcessDidResume; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProcessDidResume()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class BackgroundResponsivenessPing {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_BackgroundResponsivenessPing; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BackgroundResponsivenessPing()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(GAMEPAD)
class SetInitialGamepads {
public:
    using Arguments = std::tuple<Vector<std::optional<WebKit::GamepadData>>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetInitialGamepads; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetInitialGamepads(const Vector<std::optional<WebKit::GamepadData>>& gamepadDatas)
        : m_gamepadDatas(gamepadDatas)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gamepadDatas;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::optional<WebKit::GamepadData>>& m_gamepadDatas;
};
#endif

#if ENABLE(GAMEPAD)
class GamepadConnected {
public:
    using Arguments = std::tuple<WebKit::GamepadData, WebCore::EventMakesGamepadsVisible>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_GamepadConnected; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GamepadConnected(const WebKit::GamepadData& gamepadData, WebCore::EventMakesGamepadsVisible eventVisibility)
        : m_gamepadData(gamepadData)
        , m_eventVisibility(eventVisibility)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gamepadData;
        encoder << m_eventVisibility;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::GamepadData& m_gamepadData;
    WebCore::EventMakesGamepadsVisible m_eventVisibility;
};
#endif

#if ENABLE(GAMEPAD)
class GamepadDisconnected {
public:
    using Arguments = std::tuple<unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_GamepadDisconnected; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit GamepadDisconnected(const unsigned& index)
        : m_index(index)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_index;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_index;
};
#endif

class EstablishRemoteWorkerContextConnectionToNetworkProcess {
public:
    using Arguments = std::tuple<WebKit::RemoteWorkerType, WebKit::PageGroupIdentifier, WebKit::WebPageProxyIdentifier, WebCore::PageIdentifier, WebKit::WebPreferencesStore, WebCore::Site, std::optional<WebCore::ScriptExecutionContextIdentifier>, WebKit::RemoteWorkerInitializationData>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_EstablishRemoteWorkerContextConnectionToNetworkProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_EstablishRemoteWorkerContextConnectionToNetworkProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    EstablishRemoteWorkerContextConnectionToNetworkProcess(WebKit::RemoteWorkerType workerType, const WebKit::PageGroupIdentifier& pageGroupID, const WebKit::WebPageProxyIdentifier& webPageProxyID, const WebCore::PageIdentifier& pageID, const WebKit::WebPreferencesStore& store, const WebCore::Site& site, const std::optional<WebCore::ScriptExecutionContextIdentifier>& serviceWorkerPageIdentifier, const WebKit::RemoteWorkerInitializationData& initializationData)
        : m_workerType(workerType)
        , m_pageGroupID(pageGroupID)
        , m_webPageProxyID(webPageProxyID)
        , m_pageID(pageID)
        , m_store(store)
        , m_site(site)
        , m_serviceWorkerPageIdentifier(serviceWorkerPageIdentifier)
        , m_initializationData(initializationData)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_workerType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageGroupID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_webPageProxyID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_store;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_site;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_serviceWorkerPageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initializationData;
    }

private:
    WebKit::RemoteWorkerType m_workerType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PageGroupIdentifier& m_pageGroupID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_webPageProxyID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPreferencesStore& m_store;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Site& m_site;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ScriptExecutionContextIdentifier>& m_serviceWorkerPageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RemoteWorkerInitializationData& m_initializationData;
};

class RegisterServiceWorkerClients {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterServiceWorkerClients; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_RegisterServiceWorkerClientsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    RegisterServiceWorkerClients()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetHasSuspendedPageProxy {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetHasSuspendedPageProxy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasSuspendedPageProxy(bool hasSuspendedPageProxy)
        : m_hasSuspendedPageProxy(hasSuspendedPageProxy)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasSuspendedPageProxy;
    }

private:
    bool m_hasSuspendedPageProxy;
};

class SetIsInProcessCache {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetIsInProcessCache; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_SetIsInProcessCacheReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetIsInProcessCache(bool isInProcessCache)
        : m_isInProcessCache(isInProcessCache)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isInProcessCache;
    }

private:
    bool m_isInProcessCache;
};

class MarkIsNoLongerPrewarmed {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_MarkIsNoLongerPrewarmed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    MarkIsNoLongerPrewarmed()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetActivePagesOriginsForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_GetActivePagesOriginsForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_GetActivePagesOriginsForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    using Promise = WTF::NativePromise<Vector<String>, IPC::Error>;
    GetActivePagesOriginsForTesting()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
class SetScreenProperties {
public:
    using Arguments = std::tuple<WebCore::ScreenProperties>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetScreenProperties; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetScreenProperties(const WebCore::ScreenProperties& screenProperties)
        : m_screenProperties(screenProperties)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_screenProperties;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ScreenProperties& m_screenProperties;
};
#endif

#if PLATFORM(MAC)
class ScrollerStylePreferenceChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ScrollerStylePreferenceChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ScrollerStylePreferenceChanged(bool useOvelayScrollbars)
        : m_useOvelayScrollbars(useOvelayScrollbars)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_useOvelayScrollbars;
    }

private:
    bool m_useOvelayScrollbars;
};
#endif

#if PLATFORM(IOS_FAMILY)
class UserInterfaceIdiomDidChange {
public:
    using Arguments = std::tuple<PAL::UserInterfaceIdiom>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_UserInterfaceIdiomDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UserInterfaceIdiomDidChange(PAL::UserInterfaceIdiom idiom)
        : m_idiom(idiom)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_idiom;
    }

private:
    PAL::UserInterfaceIdiom m_idiom;
};
#endif

#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
class BacklightLevelDidChange {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_BacklightLevelDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = true;

    explicit BacklightLevelDidChange(float backlightLevel)
        : m_backlightLevel(backlightLevel)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    void encodeCoalescingKey(IPC::Encoder&) const
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backlightLevel;
    }

private:
    float m_backlightLevel;
};
#endif

#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
class ColorPreferencesDidChange {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ColorPreferencesDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ColorPreferencesDidChange()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class IsJITEnabled {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_IsJITEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_IsJITEnabledReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsJITEnabled()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(COCOA)
class SetMediaMIMETypes {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetMediaMIMETypes; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMediaMIMETypes(const Vector<String>& types)
        : m_types(types)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_types;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_types;
};
#endif

#if (PLATFORM(COCOA) && ENABLE(REMOTE_INSPECTOR))
class EnableRemoteWebInspector {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_EnableRemoteWebInspector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnableRemoteWebInspector()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(MEDIA_STREAM)
class AddMockMediaDevice {
public:
    using Arguments = std::tuple<WebCore::MockMediaDevice>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_AddMockMediaDevice; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddMockMediaDevice(const WebCore::MockMediaDevice& device)
        : m_device(device)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_device;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MockMediaDevice& m_device;
};
#endif

#if ENABLE(MEDIA_STREAM)
class ClearMockMediaDevices {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ClearMockMediaDevices; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearMockMediaDevices()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(MEDIA_STREAM)
class RemoveMockMediaDevice {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RemoveMockMediaDevice; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveMockMediaDevice(const String& persistentId)
        : m_persistentId(persistentId)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_persistentId;
    }

private:
    const String& m_persistentId;
};
#endif

#if ENABLE(MEDIA_STREAM)
class SetMockMediaDeviceIsEphemeral {
public:
    using Arguments = std::tuple<String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetMockMediaDeviceIsEphemeral; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetMockMediaDeviceIsEphemeral(const String& persistentId, bool isEphemeral)
        : m_persistentId(persistentId)
        , m_isEphemeral(isEphemeral)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_persistentId;
        encoder << m_isEphemeral;
    }

private:
    const String& m_persistentId;
    bool m_isEphemeral;
};
#endif

#if ENABLE(MEDIA_STREAM)
class ResetMockMediaDevices {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ResetMockMediaDevices; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResetMockMediaDevices()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if (ENABLE(MEDIA_STREAM) && ENABLE(SANDBOX_EXTENSIONS))
class GrantUserMediaDeviceSandboxExtensions {
public:
    using Arguments = std::tuple<WebKit::MediaDeviceSandboxExtensions>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_GrantUserMediaDeviceSandboxExtensions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit GrantUserMediaDeviceSandboxExtensions(WebKit::MediaDeviceSandboxExtensions&& sandboxExtensions)
        : m_sandboxExtensions(WTFMove(sandboxExtensions))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_sandboxExtensions);
    }

private:
    WebKit::MediaDeviceSandboxExtensions&& m_sandboxExtensions;
};
#endif

#if (ENABLE(MEDIA_STREAM) && ENABLE(SANDBOX_EXTENSIONS))
class RevokeUserMediaDeviceSandboxExtensions {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RevokeUserMediaDeviceSandboxExtensions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RevokeUserMediaDeviceSandboxExtensions(const Vector<String>& sandboxExtensionIDs)
        : m_sandboxExtensionIDs(sandboxExtensionIDs)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sandboxExtensionIDs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_sandboxExtensionIDs;
};
#endif

class ClearCurrentModifierStateForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ClearCurrentModifierStateForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearCurrentModifierStateForTesting()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetBackForwardCacheCapacity {
public:
    using Arguments = std::tuple<unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetBackForwardCacheCapacity; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetBackForwardCacheCapacity(const unsigned& capacity)
        : m_capacity(capacity)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_capacity;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_capacity;
};

class ClearCachedPage {
public:
    using Arguments = std::tuple<WebCore::BackForwardItemIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ClearCachedPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_ClearCachedPageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ClearCachedPage(const WebCore::BackForwardItemIdentifier& backForwardItemID)
        : m_backForwardItemID(backForwardItemID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backForwardItemID;
    }

private:
    const WebCore::BackForwardItemIdentifier& m_backForwardItemID;
};

#if PLATFORM(GTK) || PLATFORM(WPE)
class SendMessageToWebProcessExtension {
public:
    using Arguments = std::tuple<WebKit::UserMessage>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SendMessageToWebProcessExtension; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendMessageToWebProcessExtension(const WebKit::UserMessage& userMessage)
        : m_userMessage(userMessage)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMessage;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserMessage& m_userMessage;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class SetAvailableInputDevices {
public:
    using Arguments = std::tuple<OptionSet<WebKit::AvailableInputDevices>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetAvailableInputDevices; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAvailableInputDevices(const OptionSet<WebKit::AvailableInputDevices>& availableInputDevices)
        : m_availableInputDevices(availableInputDevices)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_availableInputDevices;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::AvailableInputDevices>& m_availableInputDevices;
};
#endif

class SeedResourceLoadStatisticsForTesting {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain, WebCore::RegistrableDomain, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SeedResourceLoadStatisticsForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_SeedResourceLoadStatisticsForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SeedResourceLoadStatisticsForTesting(const WebCore::RegistrableDomain& firstPartyDomain, const WebCore::RegistrableDomain& thirdPartyDomain, bool shouldScheduleNotification)
        : m_firstPartyDomain(firstPartyDomain)
        , m_thirdPartyDomain(thirdPartyDomain)
        , m_shouldScheduleNotification(shouldScheduleNotification)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_firstPartyDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_thirdPartyDomain;
        encoder << m_shouldScheduleNotification;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_firstPartyDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_thirdPartyDomain;
    bool m_shouldScheduleNotification;
};

class SetThirdPartyCookieBlockingMode {
public:
    using Arguments = std::tuple<WebCore::ThirdPartyCookieBlockingMode>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetThirdPartyCookieBlockingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_SetThirdPartyCookieBlockingModeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetThirdPartyCookieBlockingMode(WebCore::ThirdPartyCookieBlockingMode blockingMode)
        : m_blockingMode(blockingMode)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_blockingMode;
    }

private:
    WebCore::ThirdPartyCookieBlockingMode m_blockingMode;
};

class SetDomainsWithUserInteraction {
public:
    using Arguments = std::tuple<HashSet<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetDomainsWithUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDomainsWithUserInteraction(const HashSet<WebCore::RegistrableDomain>& domains)
        : m_domains(domains)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<WebCore::RegistrableDomain>& m_domains;
};

class SetDomainsWithCrossPageStorageAccess {
public:
    using Arguments = std::tuple<HashMap<WebCore::RegistrableDomain, Vector<WebCore::RegistrableDomain>>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetDomainsWithCrossPageStorageAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_SetDomainsWithCrossPageStorageAccessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetDomainsWithCrossPageStorageAccess(const HashMap<WebCore::RegistrableDomain, Vector<WebCore::RegistrableDomain>>& domains)
        : m_domains(domains)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domains;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<WebCore::RegistrableDomain, Vector<WebCore::RegistrableDomain>>& m_domains;
};

class SendResourceLoadStatisticsDataImmediately {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SendResourceLoadStatisticsDataImmediately; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_SendResourceLoadStatisticsDataImmediatelyReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SendResourceLoadStatisticsDataImmediately()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class UpdateDomainsWithStorageAccessQuirks {
public:
    using Arguments = std::tuple<HashSet<WebCore::RegistrableDomain>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_UpdateDomainsWithStorageAccessQuirks; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateDomainsWithStorageAccessQuirks(const HashSet<WebCore::RegistrableDomain>& domainsWithStorageAccessQuirks)
        : m_domainsWithStorageAccessQuirks(domainsWithStorageAccessQuirks)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_domainsWithStorageAccessQuirks;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashSet<WebCore::RegistrableDomain>& m_domainsWithStorageAccessQuirks;
};

class UpdateScriptTrackingPrivacyFilter {
public:
    using Arguments = std::tuple<WebKit::ScriptTrackingPrivacyRules>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_UpdateScriptTrackingPrivacyFilter; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateScriptTrackingPrivacyFilter(const WebKit::ScriptTrackingPrivacyRules& rules)
        : m_rules(rules)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rules;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ScriptTrackingPrivacyRules& m_rules;
};

class GrantAccessToAssetServices {
public:
    using Arguments = std::tuple<Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_GrantAccessToAssetServices; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit GrantAccessToAssetServices(Vector<WebKit::SandboxExtensionHandle>&& assetServicesHandles)
        : m_assetServicesHandles(WTFMove(assetServicesHandles))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_assetServicesHandles);
    }

private:
    Vector<WebKit::SandboxExtensionHandle>&& m_assetServicesHandles;
};

class RevokeAccessToAssetServices {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RevokeAccessToAssetServices; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RevokeAccessToAssetServices()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SwitchFromStaticFontRegistryToUserFontRegistry {
public:
    using Arguments = std::tuple<Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SwitchFromStaticFontRegistryToUserFontRegistry; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SwitchFromStaticFontRegistryToUserFontRegistry(Vector<WebKit::SandboxExtensionHandle>&& fontMachExtensionHandles)
        : m_fontMachExtensionHandles(WTFMove(fontMachExtensionHandles))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_fontMachExtensionHandles);
    }

private:
    Vector<WebKit::SandboxExtensionHandle>&& m_fontMachExtensionHandles;
};

#if PLATFORM(COCOA)
class DisableURLSchemeCheckInDataDetectors {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_DisableURLSchemeCheckInDataDetectors; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DisableURLSchemeCheckInDataDetectors()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class UnblockServicesRequiredByAccessibility {
public:
    using Arguments = std::tuple<Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_UnblockServicesRequiredByAccessibility; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UnblockServicesRequiredByAccessibility(Vector<WebKit::SandboxExtensionHandle>&& handleArray)
        : m_handleArray(WTFMove(handleArray))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handleArray);
    }

private:
    Vector<WebKit::SandboxExtensionHandle>&& m_handleArray;
};
#endif

#if PLATFORM(COCOA)
class PowerSourceDidChange {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_PowerSourceDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PowerSourceDidChange(bool hasAC)
        : m_hasAC(hasAC)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasAC;
    }

private:
    bool m_hasAC;
};
#endif

#if PLATFORM(GTK) && !USE(GTK4) && USE(CAIRO)
class SetUseSystemAppearanceForScrollbars {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetUseSystemAppearanceForScrollbars; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUseSystemAppearanceForScrollbars(bool useSystemAppearanceForScrollbars)
        : m_useSystemAppearanceForScrollbars(useSystemAppearanceForScrollbars)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_useSystemAppearanceForScrollbars;
    }

private:
    bool m_useSystemAppearanceForScrollbars;
};
#endif

#if PLATFORM(COCOA)
class DidWriteToPasteboardAsynchronously {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_DidWriteToPasteboardAsynchronously; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidWriteToPasteboardAsynchronously(const String& pasteboardName)
        : m_pasteboardName(pasteboardName)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
    }

private:
    const String& m_pasteboardName;
};
#endif

#if HAVE(DISPLAY_LINK)
class DisplayDidRefresh {
public:
    using Arguments = std::tuple<uint32_t, WebCore::DisplayUpdate>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_DisplayDidRefresh; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DisplayDidRefresh(uint32_t displayID, const WebCore::DisplayUpdate& update)
        : m_displayID(displayID)
        , m_update(update)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_displayID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_update;
    }

private:
    uint32_t m_displayID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DisplayUpdate& m_update;
};
#endif

#if PLATFORM(MAC)
class SystemWillPowerOn {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SystemWillPowerOn; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SystemWillPowerOn()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(MAC)
class SystemWillSleep {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SystemWillSleep; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SystemWillSleep()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(MAC)
class SystemDidWake {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SystemDidWake; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SystemDidWake()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
class ConsumeAudioComponentRegistrations {
public:
    using Arguments = std::tuple<IPC::SharedBufferReference>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ConsumeAudioComponentRegistrations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ConsumeAudioComponentRegistrations(const IPC::SharedBufferReference& registrationData)
        : m_registrationData(registrationData)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrationData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::SharedBufferReference& m_registrationData;
};
#endif

#if PLATFORM(COCOA)
class AccessibilityPreferencesDidChange {
public:
    using Arguments = std::tuple<WebKit::AccessibilityPreferences>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_AccessibilityPreferencesDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AccessibilityPreferencesDidChange(const WebKit::AccessibilityPreferences& accessibilityPreferences)
        : m_accessibilityPreferences(accessibilityPreferences)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_accessibilityPreferences;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::AccessibilityPreferences& m_accessibilityPreferences;
};
#endif

#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
class SetMediaAccessibilityPreferences {
public:
    using Arguments = std::tuple<WebCore::CaptionUserPreferencesDisplayMode, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetMediaAccessibilityPreferences; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetMediaAccessibilityPreferences(WebCore::CaptionUserPreferencesDisplayMode displayMode, const Vector<String>& languages)
        : m_displayMode(displayMode)
        , m_languages(languages)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_displayMode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_languages;
    }

private:
    WebCore::CaptionUserPreferencesDisplayMode m_displayMode;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_languages;
};
#endif

#if PLATFORM(MAC)
class OpenDirectoryCacheInvalidated {
public:
    using Arguments = std::tuple<WebKit::SandboxExtensionHandle, WebKit::SandboxExtensionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_OpenDirectoryCacheInvalidated; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    OpenDirectoryCacheInvalidated(WebKit::SandboxExtensionHandle&& handle, WebKit::SandboxExtensionHandle&& machBootstrapHandle)
        : m_handle(WTFMove(handle))
        , m_machBootstrapHandle(WTFMove(machBootstrapHandle))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handle);
        encoder << WTFMove(m_machBootstrapHandle);
    }

private:
    WebKit::SandboxExtensionHandle&& m_handle;
    WebKit::SandboxExtensionHandle&& m_machBootstrapHandle;
};
#endif

class ReleaseMemory {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_ReleaseMemory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_ReleaseMemoryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ReleaseMemory()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(NOTIFY_BLOCKING)
class PostNotification {
public:
    using Arguments = std::tuple<String, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_PostNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = true;

    PostNotification(const String& message, const std::optional<uint64_t>& state)
        : m_message(message)
        , m_state(state)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    void encodeCoalescingKey(IPC::Encoder& encoder) const
    {
        encoder << m_message;
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    const String& m_message;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_state;
};
#endif

#if ENABLE(NOTIFY_BLOCKING)
class PostObserverNotification {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_PostObserverNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = true;

    explicit PostObserverNotification(const String& message)
        : m_message(message)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    void encodeCoalescingKey(IPC::Encoder&) const
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
    }

private:
    const String& m_message;
};
#endif

#if ENABLE(NOTIFY_BLOCKING)
class GetNotifyStateForTesting {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_GetNotifyStateForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_GetNotifyStateForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<uint64_t>>;
    using Reply = CompletionHandler<void(std::optional<uint64_t>&&)>;
    using Promise = WTF::NativePromise<std::optional<uint64_t>, IPC::Error>;
    explicit GetNotifyStateForTesting(const String& notificationName)
        : m_notificationName(notificationName)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_notificationName;
    }

private:
    const String& m_notificationName;
};
#endif

#if ENABLE(CONTENT_EXTENSIONS)
class SetResourceMonitorContentRuleList {
public:
    using Arguments = std::tuple<WebKit::WebCompiledContentRuleListData>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetResourceMonitorContentRuleList; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = true;

    explicit SetResourceMonitorContentRuleList(const WebKit::WebCompiledContentRuleListData& ruleListData)
        : m_ruleListData(ruleListData)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    void encodeCoalescingKey(IPC::Encoder&) const
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ruleListData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebCompiledContentRuleListData& m_ruleListData;
};
#endif

#if ENABLE(CONTENT_EXTENSIONS)
class SetResourceMonitorContentRuleListAsync {
public:
    using Arguments = std::tuple<WebKit::WebCompiledContentRuleListData>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_SetResourceMonitorContentRuleListAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebProcess_SetResourceMonitorContentRuleListAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetResourceMonitorContentRuleListAsync(const WebKit::WebCompiledContentRuleListData& ruleListData)
        : m_ruleListData(ruleListData)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_ruleListData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebCompiledContentRuleListData& m_ruleListData;
};
#endif

#if PLATFORM(COCOA)
class RegisterAdditionalFonts {
public:
    using Arguments = std::tuple<WebKit::AdditionalFonts>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterAdditionalFonts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterAdditionalFonts(WebKit::AdditionalFonts&& fonts)
        : m_fonts(WTFMove(fonts))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_fonts);
    }

private:
    WebKit::AdditionalFonts&& m_fonts;
};
#endif

#if PLATFORM(COCOA)
class RegisterFontMap {
public:
    using Arguments = std::tuple<HashMap<String, URL>, HashMap<String, Vector<String>>, Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_RegisterFontMap; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterFontMap(const HashMap<String, URL>& fonts, const HashMap<String, Vector<String>>& fontFamilyMap, Vector<WebKit::SandboxExtensionHandle>&& sandboxExtensions)
        : m_fonts(fonts)
        , m_fontFamilyMap(fontFamilyMap)
        , m_sandboxExtensions(WTFMove(sandboxExtensions))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fonts;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fontFamilyMap;
        encoder << WTFMove(m_sandboxExtensions);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<String, URL>& m_fonts;
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<String, Vector<String>>& m_fontFamilyMap;
    Vector<WebKit::SandboxExtensionHandle>&& m_sandboxExtensions;
};
#endif

#if ENABLE(INITIALIZE_ACCESSIBILITY_ON_DEMAND)
class InitializeAccessibility {
public:
    using Arguments = std::tuple<Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebProcess_InitializeAccessibility; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit InitializeAccessibility(Vector<WebKit::SandboxExtensionHandle>&& handles)
        : m_handles(WTFMove(handles))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handles);
    }

private:
    Vector<WebKit::SandboxExtensionHandle>&& m_handles;
};
#endif

} // namespace WebProcess
} // namespace Messages
