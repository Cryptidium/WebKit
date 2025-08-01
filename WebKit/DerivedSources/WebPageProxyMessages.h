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
#include "FocusedElementInformation.h"
#include "IdentifierTypes.h"
#include "LayerHostingContext.h"
#include "MessageNames.h"
#include "PageClient.h"
#include "SessionState.h"
#include "WebPageCreationParameters.h"
#include <WebCore/AutoplayEvent.h>
#include <WebCore/BackForwardFrameItemIdentifier.h>
#include <WebCore/BackForwardItemIdentifier.h>
#include <WebCore/DiagnosticLoggingDomain.h>
#include <WebCore/DictationContext.h>
#include <WebCore/DragActions.h>
#include <WebCore/MediaProducer.h>
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
#include <WebCore/PlaybackTargetClientContextIdentifier.h>
#endif
#include <WebCore/ProcessQualified.h>
#include <WebCore/RectEdges.h>
#include <WebCore/RenderTreeAsText.h>
#include <WebCore/SandboxFlags.h>
#include <WebCore/ScrollingNodeID.h>
#include <WebCore/SearchPopupMenu.h>
#include <WebCore/ShareableBitmapHandle.h>
#include <WebCore/ShareableResource.h>
#include <WebCore/SharedMemory.h>
#include <WebCore/TextCheckerClient.h>
#include <WebCore/TextChecking.h>
#include <WebCore/WritingToolsTypes.h>
#include <span>
#include <utility>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/MachSendRight.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/OptionSet.h>
#include <wtf/Ref.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/Seconds.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class SharedBufferReference;
}

namespace Inspector {
enum class InspectorTargetType : uint8_t;
}

namespace WTF {
class UUID;
}

namespace WebCore {
class CertificateInfo;
class Color;
class ContentFilterUnblockHandler;
class Cursor;
class Exception;
class FloatPoint;
class FloatRect;
class FloatSize;
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
class IntPoint;
class IntRect;
class IntSize;
class LayoutPoint;
struct MediaKeySystemRequestIdentifierType;
using MediaKeySystemRequestIdentifier = ObjectIdentifier<MediaKeySystemRequestIdentifierType>;
struct MediaPlayerIdentifierType;
using MediaPlayerIdentifier = ObjectIdentifier<MediaPlayerIdentifierType>;
struct MediaSessionIdentifierType;
using MediaSessionIdentifier = ObjectIdentifier<MediaSessionIdentifierType>;
struct NavigationIdentifierType;
using NavigationIdentifier = ObjectIdentifier<NavigationIdentifierType>;
struct NodeIdentifierType;
using NodeIdentifier = ObjectIdentifier<NodeIdentifierType>;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
class ResourceError;
struct ResourceLoaderIdentifierType;
using ResourceLoaderIdentifier = AtomicObjectIdentifier<ResourceLoaderIdentifierType>;
class ResourceRequest;
class ResourceResponse;
class SecurityOriginData;
class SelectionData;
struct SleepDisablerIdentifierType;
using SleepDisablerIdentifier = ObjectIdentifier<SleepDisablerIdentifierType>;
class TextCheckingRequestData;
struct UserMediaRequestIdentifierType;
using UserMediaRequestIdentifier = ObjectIdentifier<UserMediaRequestIdentifierType>;
enum class HasInsecureContent : bool;
enum class LockBackForwardList : bool;
enum class ShouldSample : bool;
enum class WillContinueLoading : bool;
enum class WillInternallyHandleFailure : bool;
enum class AlternativeTextType : uint8_t;
enum class AttachmentAssociatedElementType : uint8_t;
enum class AutocorrectionResponse : uint8_t;
enum class AutoplayEvent : uint8_t;
enum class CookieConsentDecisionResult : uint8_t;
enum class CrossOriginOpenerPolicyValue : uint8_t;
enum class DOMPasteAccessCategory : uint8_t;
enum class DOMPasteAccessResponse : uint8_t;
enum class DeviceOrientationOrMotionPermissionState : uint8_t;
enum class FocusDirection : uint8_t;
enum class FrameLoadType : uint8_t;
enum class InputMode : uint8_t;
enum class MediaPlaybackTargetContextMockState : uint8_t;
enum class MediaProducerMediaCaptureKind : uint8_t;
enum class MouseEventPolicy : uint8_t;
enum class ReasonForDismissingAlternativeText : uint8_t;
enum class ResourceResponseSource : uint8_t;
enum class RouteSharingPolicy : uint8_t;
enum class ScrollbarMode : uint8_t;
enum class ShouldGoToHistoryItem : uint8_t;
enum class TextAnimationRunMode : uint8_t;
enum class TextIndicatorLifetime : uint8_t;
enum class WindowProxyProperty : uint8_t;
struct ApplePayAMSUIRequest;
struct ClientOrigin;
struct ContactsRequestData;
struct ContentRuleListResults;
struct CryptoKeyData;
struct DataDetectorElementInfo;
struct DataListSuggestionInformation;
struct DateTimeChooserParameters;
struct DiagnosticLoggingDictionary;
struct DictionaryPopupInfo;
struct DigitalCredentialsRequestData;
struct DragItem;
struct ElementContext;
struct FileChooserSettings;
struct GrammarDetail;
struct HTMLModelElementCamera;
struct ImageBufferParameters;
struct InspectorOverlayHighlight;
struct LinkIcon;
struct MediaDeviceHashSalts;
struct MediaStreamRequest;
struct MediaUsageInfo;
struct MessageWithMessagePorts;
struct MockWebAuthenticationConfiguration;
struct NowPlayingMetadata;
struct ProcessSyncData;
struct PromisedAttachmentInfo;
struct RemoteUserInputEventData;
struct ShareDataWithParsedURL;
struct SpatialBackdropSource;
struct SystemPreviewInfo;
struct TextAnimationData;
struct TextIndicatorData;
struct TextRecognitionResult;
struct TranslationContextMenuInfo;
struct WindowFeatures;
struct WrappedCryptoKey;
}

namespace WebKit {
class CallbackID;
class ContextMenuContextData;
struct GeolocationIdentifierType;
using GeolocationIdentifier = ObjectIdentifier<GeolocationIdentifierType>;
struct PDFPluginIdentifierType;
using PDFPluginIdentifier = ObjectIdentifier<PDFPluginIdentifierType>;
struct TapIdentifierType;
using TapIdentifier = ObjectIdentifier<TapIdentifierType>;
class UserData;
struct WebURLSchemeHandlerIdentifierType;
using WebURLSchemeHandlerIdentifier = ObjectIdentifier<WebURLSchemeHandlerIdentifierType>;
enum class ColorControlSupportsAlpha : bool;
enum class UndoOrRedo : bool;
enum class SameDocumentNavigationType : uint8_t;
enum class WebEventType : uint8_t;
struct DataDetectionResult;
struct EditorState;
struct FrameInfoData;
struct InputMethodState;
struct InteractionInformationAtPosition;
struct KeyEventInterpretationContext;
struct ModelIdentifier;
struct NavigationActionData;
struct PDFContextMenu;
struct PlatformPopupMenuData;
struct PolicyDecision;
struct URLSchemeTaskParameters;
struct UserMessage;
struct WebAutocorrectionContext;
struct WebBackForwardListCounts;
struct WebHitTestResultData;
struct WebNavigationDataStore;
}

namespace Messages {
namespace WebPageProxy {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(!isInAuxiliaryProcess());
        }
    );
#endif
    return IPC::ReceiverName::WebPageProxy;
}

class CreateNewPage {
public:
    using Arguments = std::tuple<WebCore::WindowFeatures, WebKit::NavigationActionData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CreateNewPage; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::PageIdentifier>, std::optional<WebKit::WebPageCreationParameters>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::PageIdentifier>&&, std::optional<WebKit::WebPageCreationParameters>&&)>;
    CreateNewPage(const WebCore::WindowFeatures& windowFeatures, const WebKit::NavigationActionData& navigationActionData)
        : m_windowFeatures(windowFeatures)
        , m_navigationActionData(navigationActionData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowFeatures;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationActionData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WindowFeatures& m_windowFeatures;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::NavigationActionData& m_navigationActionData;
};

class ShowPage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowPage()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ClosePage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ClosePage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClosePage()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RunJavaScriptAlert {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RunJavaScriptAlert; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    RunJavaScriptAlert(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const String& message)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    const String& m_message;
};

class RunJavaScriptConfirm {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RunJavaScriptConfirm; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    RunJavaScriptConfirm(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const String& message)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    const String& m_message;
};

class RunJavaScriptPrompt {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RunJavaScriptPrompt; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    RunJavaScriptPrompt(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const String& message, const String& defaultValue)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_message(message)
        , m_defaultValue(defaultValue)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        encoder << m_message;
        encoder << m_defaultValue;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    const String& m_message;
    const String& m_defaultValue;
};

class MouseDidMoveOverElement {
public:
    using Arguments = std::tuple<WebKit::WebHitTestResultData, OptionSet<WebKit::WebEventModifier>, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_MouseDidMoveOverElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    MouseDidMoveOverElement(const WebKit::WebHitTestResultData& hitTestResultData, const OptionSet<WebKit::WebEventModifier>& modifiers, const WebKit::UserData& userData)
        : m_hitTestResultData(hitTestResultData)
        , m_modifiers(modifiers)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_hitTestResultData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiers;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebHitTestResultData& m_hitTestResultData;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebEventModifier>& m_modifiers;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidReceiveEventIPC {
public:
    using Arguments = std::tuple<WebKit::WebEventType, bool, std::optional<WebCore::RemoteUserInputEventData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidReceiveEventIPC; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveEventIPC(WebKit::WebEventType eventType, bool handled, const std::optional<WebCore::RemoteUserInputEventData>& remoteUserInputEventData)
        : m_eventType(eventType)
        , m_handled(handled)
        , m_remoteUserInputEventData(remoteUserInputEventData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_eventType;
        encoder << m_handled;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remoteUserInputEventData;
    }

private:
    WebKit::WebEventType m_eventType;
    bool m_handled;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::RemoteUserInputEventData>& m_remoteUserInputEventData;
};

class SetCursor {
public:
    using Arguments = std::tuple<WebCore::Cursor>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetCursor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCursor(const WebCore::Cursor& cursor)
        : m_cursor(cursor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_cursor;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Cursor& m_cursor;
};

class SetCursorHiddenUntilMouseMoves {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetCursorHiddenUntilMouseMoves; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCursorHiddenUntilMouseMoves(bool hiddenUntilMouseMoves)
        : m_hiddenUntilMouseMoves(hiddenUntilMouseMoves)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hiddenUntilMouseMoves;
    }

private:
    bool m_hiddenUntilMouseMoves;
};

class SetFocus {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetFocus; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetFocus(bool focused)
        : m_focused(focused)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_focused;
    }

private:
    bool m_focused;
};

class TakeFocus {
public:
    using Arguments = std::tuple<WebCore::FocusDirection>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_TakeFocus; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TakeFocus(WebCore::FocusDirection direction)
        : m_direction(direction)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_direction;
    }

private:
    WebCore::FocusDirection m_direction;
};

class FocusFromServiceWorker {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_FocusFromServiceWorker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_FocusFromServiceWorkerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    FocusFromServiceWorker()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class FocusedFrameChanged {
public:
    using Arguments = std::tuple<std::optional<WebCore::FrameIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_FocusedFrameChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FocusedFrameChanged(const std::optional<WebCore::FrameIdentifier>& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
};

class SetRenderTreeSize {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetRenderTreeSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetRenderTreeSize(uint64_t treeSize)
        : m_treeSize(treeSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_treeSize;
    }

private:
    uint64_t m_treeSize;
};

class SetToolbarsAreVisible {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetToolbarsAreVisible; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetToolbarsAreVisible(bool toolbarsAreVisible)
        : m_toolbarsAreVisible(toolbarsAreVisible)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_toolbarsAreVisible;
    }

private:
    bool m_toolbarsAreVisible;
};

class GetToolbarsAreVisible {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_GetToolbarsAreVisible; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    GetToolbarsAreVisible()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetMenuBarIsVisible {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetMenuBarIsVisible; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMenuBarIsVisible(bool menuBarIsVisible)
        : m_menuBarIsVisible(menuBarIsVisible)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_menuBarIsVisible;
    }

private:
    bool m_menuBarIsVisible;
};

class GetMenuBarIsVisible {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_GetMenuBarIsVisible; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    GetMenuBarIsVisible()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetStatusBarIsVisible {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetStatusBarIsVisible; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetStatusBarIsVisible(bool statusBarIsVisible)
        : m_statusBarIsVisible(statusBarIsVisible)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_statusBarIsVisible;
    }

private:
    bool m_statusBarIsVisible;
};

class GetStatusBarIsVisible {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_GetStatusBarIsVisible; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    GetStatusBarIsVisible()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetIsResizable {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetIsResizable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIsResizable(bool isResizable)
        : m_isResizable(isResizable)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isResizable;
    }

private:
    bool m_isResizable;
};

class SetWindowFrame {
public:
    using Arguments = std::tuple<WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetWindowFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetWindowFrame(const WebCore::FloatRect& windowFrame)
        : m_windowFrame(windowFrame)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowFrame;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_windowFrame;
};

class GetWindowFrame {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_GetWindowFrame; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::FloatRect>;
    using Reply = CompletionHandler<void(WebCore::FloatRect&&)>;
    GetWindowFrame()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ScreenToRootView {
public:
    using Arguments = std::tuple<WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ScreenToRootView; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntPoint>;
    using Reply = CompletionHandler<void(WebCore::IntPoint&&)>;
    explicit ScreenToRootView(const WebCore::IntPoint& screenPoint)
        : m_screenPoint(screenPoint)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_screenPoint;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_screenPoint;
};

class RootViewPointToScreen {
public:
    using Arguments = std::tuple<WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RootViewPointToScreen; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntPoint>;
    using Reply = CompletionHandler<void(WebCore::IntPoint&&)>;
    explicit RootViewPointToScreen(const WebCore::IntPoint& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_rect;
};

class RootViewRectToScreen {
public:
    using Arguments = std::tuple<WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RootViewRectToScreen; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntRect>;
    using Reply = CompletionHandler<void(WebCore::IntRect&&)>;
    explicit RootViewRectToScreen(const WebCore::IntRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_rect;
};

class AccessibilityScreenToRootView {
public:
    using Arguments = std::tuple<WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_AccessibilityScreenToRootView; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntPoint>;
    using Reply = CompletionHandler<void(WebCore::IntPoint&&)>;
    explicit AccessibilityScreenToRootView(const WebCore::IntPoint& screenPoint)
        : m_screenPoint(screenPoint)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_screenPoint;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_screenPoint;
};

class RootViewToAccessibilityScreen {
public:
    using Arguments = std::tuple<WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RootViewToAccessibilityScreen; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntRect>;
    using Reply = CompletionHandler<void(WebCore::IntRect&&)>;
    explicit RootViewToAccessibilityScreen(const WebCore::IntRect& rect)
        : m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_rect;
};

#if PLATFORM(IOS_FAMILY)
class RelayAccessibilityNotification {
public:
    using Arguments = std::tuple<String, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RelayAccessibilityNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RelayAccessibilityNotification(const String& notificationName, const std::span<const uint8_t>& notificationData)
        : m_notificationName(notificationName)
        , m_notificationData(notificationData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_notificationName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_notificationData;
    }

private:
    const String& m_notificationName;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_notificationData;
};
#endif

class EnableAccessibilityForAllProcesses {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_EnableAccessibilityForAllProcesses; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnableAccessibilityForAllProcesses()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(COCOA) || PLATFORM(GTK)
class ShowValidationMessage {
public:
    using Arguments = std::tuple<WebCore::IntRect, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowValidationMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowValidationMessage(const WebCore::IntRect& anchorRect, const String& message)
        : m_anchorRect(anchorRect)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_anchorRect;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_anchorRect;
    const String& m_message;
};
#endif

#if PLATFORM(COCOA) || PLATFORM(GTK)
class HideValidationMessage {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HideValidationMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HideValidationMessage()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class RunBeforeUnloadConfirmPanel {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RunBeforeUnloadConfirmPanel; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    RunBeforeUnloadConfirmPanel(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const String& message)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    const String& m_message;
};

class PageDidScroll {
public:
    using Arguments = std::tuple<WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PageDidScroll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PageDidScroll(const WebCore::IntPoint& scrollPosition)
        : m_scrollPosition(scrollPosition)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scrollPosition;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_scrollPosition;
};

class SetHasActiveAnimatedScrolls {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetHasActiveAnimatedScrolls; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasActiveAnimatedScrolls(bool hasActiveAnimatedScrolls)
        : m_hasActiveAnimatedScrolls(hasActiveAnimatedScrolls)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasActiveAnimatedScrolls;
    }

private:
    bool m_hasActiveAnimatedScrolls;
};

class RunOpenPanel {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, WebCore::FileChooserSettings>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RunOpenPanel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RunOpenPanel(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const WebCore::FileChooserSettings& parameters)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FileChooserSettings& m_parameters;
};

class ShowShareSheet {
public:
    using Arguments = std::tuple<WebCore::ShareDataWithParsedURL>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowShareSheet; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ShowShareSheetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit ShowShareSheet(const WebCore::ShareDataWithParsedURL& shareData)
        : m_shareData(shareData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_shareData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ShareDataWithParsedURL& m_shareData;
};

class ShowContactPicker {
public:
    using Arguments = std::tuple<WebCore::ContactsRequestData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowContactPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ShowContactPickerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<WebCore::ContactInfo>>>;
    using Reply = CompletionHandler<void(std::optional<Vector<WebCore::ContactInfo>>&&)>;
    using Promise = WTF::NativePromise<std::optional<Vector<WebCore::ContactInfo>>, IPC::Error>;
    explicit ShowContactPicker(const WebCore::ContactsRequestData& requestData)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ContactsRequestData& m_requestData;
};

#if HAVE(DIGITAL_CREDENTIALS_UI)
class ShowDigitalCredentialsPicker {
public:
    using Arguments = std::tuple<WebCore::DigitalCredentialsRequestData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowDigitalCredentialsPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ShowDigitalCredentialsPickerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::DigitalCredentialsResponseData, WebCore::ExceptionData>>;
    using Reply = CompletionHandler<void(Expected<WebCore::DigitalCredentialsResponseData, WebCore::ExceptionData>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::DigitalCredentialsResponseData, WebCore::ExceptionData>, IPC::Error>;
    explicit ShowDigitalCredentialsPicker(const WebCore::DigitalCredentialsRequestData& requestData)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DigitalCredentialsRequestData& m_requestData;
};
#endif

#if HAVE(DIGITAL_CREDENTIALS_UI)
class DismissDigitalCredentialsPicker {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DismissDigitalCredentialsPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_DismissDigitalCredentialsPickerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    DismissDigitalCredentialsPicker()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class PrintFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String, WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PrintFrame; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    PrintFrame(const WebCore::FrameIdentifier& frameID, const String& title, const WebCore::FloatSize& pdfFirstPageSize)
        : m_frameID(frameID)
        , m_title(title)
        , m_pdfFirstPageSize(pdfFirstPageSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_title;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pdfFirstPageSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    const String& m_title;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_pdfFirstPageSize;
};

class RunModal {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RunModal; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RunModal()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class NotifyScrollerThumbIsVisibleInRect {
public:
    using Arguments = std::tuple<WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_NotifyScrollerThumbIsVisibleInRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit NotifyScrollerThumbIsVisibleInRect(const WebCore::IntRect& scrollerThumb)
        : m_scrollerThumb(scrollerThumb)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scrollerThumb;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_scrollerThumb;
};

class RecommendedScrollbarStyleDidChange {
public:
    using Arguments = std::tuple<int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RecommendedScrollbarStyleDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RecommendedScrollbarStyleDidChange(int32_t newStyle)
        : m_newStyle(newStyle)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_newStyle;
    }

private:
    int32_t m_newStyle;
};

class DidChangeScrollbarsForMainFrame {
public:
    using Arguments = std::tuple<bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangeScrollbarsForMainFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidChangeScrollbarsForMainFrame(bool hasHorizontalScrollbar, bool hasVerticalScrollbar)
        : m_hasHorizontalScrollbar(hasHorizontalScrollbar)
        , m_hasVerticalScrollbar(hasVerticalScrollbar)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasHorizontalScrollbar;
        encoder << m_hasVerticalScrollbar;
    }

private:
    bool m_hasHorizontalScrollbar;
    bool m_hasVerticalScrollbar;
};

class DidChangeScrollOffsetPinningForMainFrame {
public:
    using Arguments = std::tuple<WebCore::RectEdges<bool>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangeScrollOffsetPinningForMainFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChangeScrollOffsetPinningForMainFrame(const WebCore::RectEdges<bool>& pinnedState)
        : m_pinnedState(pinnedState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pinnedState;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RectEdges<bool>& m_pinnedState;
};

class DidChangePageCount {
public:
    using Arguments = std::tuple<unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangePageCount; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChangePageCount(const unsigned& pageCount)
        : m_pageCount(pageCount)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageCount;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_pageCount;
};

#if PLATFORM(MAC) || PLATFORM(WPE) || PLATFORM(GTK)
class ThemeColorChanged {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ThemeColorChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ThemeColorChanged(const WebCore::Color& themeColor)
        : m_themeColor(themeColor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_themeColor;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_themeColor;
};
#endif

#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
class SpatialBackdropSourceChanged {
public:
    using Arguments = std::tuple<std::optional<WebCore::SpatialBackdropSource>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpatialBackdropSourceChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SpatialBackdropSourceChanged(const std::optional<WebCore::SpatialBackdropSource>& spatialBackdropSource)
        : m_spatialBackdropSource(spatialBackdropSource)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_spatialBackdropSource;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SpatialBackdropSource>& m_spatialBackdropSource;
};
#endif

class PageExtendedBackgroundColorDidChange {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PageExtendedBackgroundColorDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PageExtendedBackgroundColorDidChange(const WebCore::Color& backgroundColor)
        : m_backgroundColor(backgroundColor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_backgroundColor;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_backgroundColor;
};

class SampledPageTopColorChanged {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SampledPageTopColorChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SampledPageTopColorChanged(const WebCore::Color& sampledPageTopColor)
        : m_sampledPageTopColor(sampledPageTopColor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sampledPageTopColor;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_sampledPageTopColor;
};

class SetCanShortCircuitHorizontalWheelEvents {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetCanShortCircuitHorizontalWheelEvents; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCanShortCircuitHorizontalWheelEvents(bool canShortCircuitHorizontalWheelEvents)
        : m_canShortCircuitHorizontalWheelEvents(canShortCircuitHorizontalWheelEvents)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_canShortCircuitHorizontalWheelEvents;
    }

private:
    bool m_canShortCircuitHorizontalWheelEvents;
};

class DidChangeContentSize {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangeContentSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChangeContentSize(const WebCore::IntSize& newSize)
        : m_newSize(newSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_newSize;
};

class DidChangeIntrinsicContentSize {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangeIntrinsicContentSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChangeIntrinsicContentSize(const WebCore::IntSize& newIntrinsicContentSize)
        : m_newIntrinsicContentSize(newIntrinsicContentSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newIntrinsicContentSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_newIntrinsicContentSize;
};

class ShowColorPicker {
public:
    using Arguments = std::tuple<WebCore::Color, WebCore::IntRect, WebKit::ColorControlSupportsAlpha, Vector<WebCore::Color>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowColorPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowColorPicker(const WebCore::Color& initialColor, const WebCore::IntRect& elementRect, WebKit::ColorControlSupportsAlpha supportsAlpha, const Vector<WebCore::Color>& suggestions)
        : m_initialColor(initialColor)
        , m_elementRect(elementRect)
        , m_supportsAlpha(supportsAlpha)
        , m_suggestions(suggestions)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_initialColor;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_elementRect;
        encoder << m_supportsAlpha;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_suggestions;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_initialColor;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_elementRect;
    WebKit::ColorControlSupportsAlpha m_supportsAlpha;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::Color>& m_suggestions;
};

class SetColorPickerColor {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetColorPickerColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetColorPickerColor(const WebCore::Color& color)
        : m_color(color)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

class EndColorPicker {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_EndColorPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EndColorPicker()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ShowDataListSuggestions {
public:
    using Arguments = std::tuple<WebCore::DataListSuggestionInformation>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowDataListSuggestions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ShowDataListSuggestions(const WebCore::DataListSuggestionInformation& suggestionInformation)
        : m_suggestionInformation(suggestionInformation)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_suggestionInformation;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DataListSuggestionInformation& m_suggestionInformation;
};

class HandleKeydownInDataList {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleKeydownInDataList; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HandleKeydownInDataList(const String& key)
        : m_key(key)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_key;
    }

private:
    const String& m_key;
};

class EndDataListSuggestions {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_EndDataListSuggestions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EndDataListSuggestions()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ShowDateTimePicker {
public:
    using Arguments = std::tuple<WebCore::DateTimeChooserParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowDateTimePicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ShowDateTimePicker(const WebCore::DateTimeChooserParameters& params)
        : m_params(params)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_params;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DateTimeChooserParameters& m_params;
};

class EndDateTimePicker {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_EndDateTimePicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EndDateTimePicker()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DecidePolicyForResponse {
public:
    using Arguments = std::tuple<WebKit::FrameInfoData, std::optional<WebCore::NavigationIdentifier>, WebCore::ResourceResponse, WebCore::ResourceRequest, bool, String, bool, WebCore::CrossOriginOpenerPolicyValue>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DecidePolicyForResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_DecidePolicyForResponseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::PolicyDecision>;
    using Reply = CompletionHandler<void(WebKit::PolicyDecision&&)>;
    using Promise = WTF::NativePromise<WebKit::PolicyDecision, IPC::Error>;
    DecidePolicyForResponse(const WebKit::FrameInfoData& frameInfo, const std::optional<WebCore::NavigationIdentifier>& navigationID, const WebCore::ResourceResponse& response, const WebCore::ResourceRequest& request, bool canShowMIMEType, const String& downloadAttribute, bool isShowingInitialAboutBlank, WebCore::CrossOriginOpenerPolicyValue activeDocumentCOOPValue)
        : m_frameInfo(frameInfo)
        , m_navigationID(navigationID)
        , m_response(response)
        , m_request(request)
        , m_canShowMIMEType(canShowMIMEType)
        , m_downloadAttribute(downloadAttribute)
        , m_isShowingInitialAboutBlank(isShowingInitialAboutBlank)
        , m_activeDocumentCOOPValue(activeDocumentCOOPValue)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        encoder << m_canShowMIMEType;
        encoder << m_downloadAttribute;
        encoder << m_isShowingInitialAboutBlank;
        encoder << m_activeDocumentCOOPValue;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    bool m_canShowMIMEType;
    const String& m_downloadAttribute;
    bool m_isShowingInitialAboutBlank;
    WebCore::CrossOriginOpenerPolicyValue m_activeDocumentCOOPValue;
};

class DecidePolicyForNavigationActionAsync {
public:
    using Arguments = std::tuple<WebKit::NavigationActionData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DecidePolicyForNavigationActionAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_DecidePolicyForNavigationActionAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::PolicyDecision>;
    using Reply = CompletionHandler<void(WebKit::PolicyDecision&&)>;
    using Promise = WTF::NativePromise<WebKit::PolicyDecision, IPC::Error>;
    explicit DecidePolicyForNavigationActionAsync(const WebKit::NavigationActionData& data)
        : m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::NavigationActionData& m_data;
};

class DecidePolicyForNavigationActionSync {
public:
    using Arguments = std::tuple<WebKit::NavigationActionData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DecidePolicyForNavigationActionSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::PolicyDecision>;
    using Reply = CompletionHandler<void(WebKit::PolicyDecision&&)>;
    explicit DecidePolicyForNavigationActionSync(const WebKit::NavigationActionData& data)
        : m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::NavigationActionData& m_data;
};

class DecidePolicyForNewWindowAction {
public:
    using Arguments = std::tuple<WebKit::NavigationActionData, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DecidePolicyForNewWindowAction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_DecidePolicyForNewWindowActionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::PolicyDecision>;
    using Reply = CompletionHandler<void(WebKit::PolicyDecision&&)>;
    using Promise = WTF::NativePromise<WebKit::PolicyDecision, IPC::Error>;
    DecidePolicyForNewWindowAction(const WebKit::NavigationActionData& navigationActionData, const String& frameName)
        : m_navigationActionData(navigationActionData)
        , m_frameName(frameName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationActionData;
        encoder << m_frameName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::NavigationActionData& m_navigationActionData;
    const String& m_frameName;
};

class DidChangeProgress {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangeProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChangeProgress(double value)
        : m_value(value)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_value;
    }

private:
    double m_value;
};

class DidFinishProgress {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFinishProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishProgress()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidStartProgress {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidStartProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStartProgress()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetNetworkRequestsInProgress {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetNetworkRequestsInProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetNetworkRequestsInProgress(bool networkRequestsInProgress)
        : m_networkRequestsInProgress(networkRequestsInProgress)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_networkRequestsInProgress;
    }

private:
    bool m_networkRequestsInProgress;
};

class StartNetworkRequestsForPageLoadTiming {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_StartNetworkRequestsForPageLoadTiming; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StartNetworkRequestsForPageLoadTiming(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class EndNetworkRequestsForPageLoadTiming {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_EndNetworkRequestsForPageLoadTiming; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EndNetworkRequestsForPageLoadTiming(const WebCore::FrameIdentifier& frameID, const WallTime& timestamp)
        : m_frameID(frameID)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class DidCreateSubframe {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::FrameIdentifier, String, WebCore::SandboxFlags, WebCore::ScrollbarMode>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidCreateSubframe; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCreateSubframe(const WebCore::FrameIdentifier& parent, const WebCore::FrameIdentifier& newFrameID, const String& frameName, const WebCore::SandboxFlags& sandboxFlags, WebCore::ScrollbarMode scrollingMode)
        : m_parent(parent)
        , m_newFrameID(newFrameID)
        , m_frameName(frameName)
        , m_sandboxFlags(sandboxFlags)
        , m_scrollingMode(scrollingMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newFrameID;
        encoder << m_frameName;
        encoder << m_sandboxFlags;
        encoder << m_scrollingMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_parent;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_newFrameID;
    const String& m_frameName;
    const WebCore::SandboxFlags& m_sandboxFlags;
    WebCore::ScrollbarMode m_scrollingMode;
};

class DidDestroyFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidDestroyFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDestroyFrame(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class DidStartProvisionalLoadForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, WebCore::ResourceRequest, std::optional<WebCore::NavigationIdentifier>, URL, URL, WebKit::UserData, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidStartProvisionalLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStartProvisionalLoadForFrame(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const WebCore::ResourceRequest& request, const std::optional<WebCore::NavigationIdentifier>& navigationID, const URL& url, const URL& unreachableURL, const WebKit::UserData& userData, const WallTime& timestamp)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_request(request)
        , m_navigationID(navigationID)
        , m_url(url)
        , m_unreachableURL(unreachableURL)
        , m_userData(userData)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_unreachableURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_unreachableURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class DidReceiveServerRedirectForProvisionalLoadForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::optional<WebCore::NavigationIdentifier>, WebCore::ResourceRequest, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidReceiveServerRedirectForProvisionalLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveServerRedirectForProvisionalLoadForFrame(const WebCore::FrameIdentifier& frameID, const std::optional<WebCore::NavigationIdentifier>& navigationID, const WebCore::ResourceRequest& request, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_navigationID(navigationID)
        , m_request(request)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class WillPerformClientRedirectForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String, double, WebCore::LockBackForwardList>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_WillPerformClientRedirectForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WillPerformClientRedirectForFrame(const WebCore::FrameIdentifier& frameID, const String& url, double delay, WebCore::LockBackForwardList lockBackForwardList)
        : m_frameID(frameID)
        , m_url(url)
        , m_delay(delay)
        , m_lockBackForwardList(lockBackForwardList)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_url;
        encoder << m_delay;
        encoder << m_lockBackForwardList;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    const String& m_url;
    double m_delay;
    WebCore::LockBackForwardList m_lockBackForwardList;
};

class DidCancelClientRedirectForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidCancelClientRedirectForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidCancelClientRedirectForFrame(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class DidChangeProvisionalURLForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::optional<WebCore::NavigationIdentifier>, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangeProvisionalURLForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidChangeProvisionalURLForFrame(const WebCore::FrameIdentifier& frameID, const std::optional<WebCore::NavigationIdentifier>& navigationID, const URL& url)
        : m_frameID(frameID)
        , m_navigationID(navigationID)
        , m_url(url)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

class DidFailProvisionalLoadForFrame {
public:
    using Arguments = std::tuple<WebKit::FrameInfoData, WebCore::ResourceRequest, std::optional<WebCore::NavigationIdentifier>, String, WebCore::ResourceError, WebCore::WillContinueLoading, WebKit::UserData, WebCore::WillInternallyHandleFailure>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFailProvisionalLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFailProvisionalLoadForFrame(const WebKit::FrameInfoData& frameInfo, const WebCore::ResourceRequest& request, const std::optional<WebCore::NavigationIdentifier>& navigationID, const String& provisionalURL, const WebCore::ResourceError& error, WebCore::WillContinueLoading willContinueLoading, const WebKit::UserData& userData, WebCore::WillInternallyHandleFailure willInternallyHandleFailure)
        : m_frameInfo(frameInfo)
        , m_request(request)
        , m_navigationID(navigationID)
        , m_provisionalURL(provisionalURL)
        , m_error(error)
        , m_willContinueLoading(willContinueLoading)
        , m_userData(userData)
        , m_willInternallyHandleFailure(willInternallyHandleFailure)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        encoder << m_provisionalURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
        encoder << m_willContinueLoading;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
        encoder << m_willInternallyHandleFailure;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    const String& m_provisionalURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
    WebCore::WillContinueLoading m_willContinueLoading;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
    WebCore::WillInternallyHandleFailure m_willInternallyHandleFailure;
};

class DidCommitLoadForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, WebCore::ResourceRequest, std::optional<WebCore::NavigationIdentifier>, String, bool, WebCore::FrameLoadType, WebCore::CertificateInfo, bool, bool, String, WebCore::ResourceResponseSource, bool, WebCore::HasInsecureContent, WebCore::MouseEventPolicy, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidCommitLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCommitLoadForFrame(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const WebCore::ResourceRequest& request, const std::optional<WebCore::NavigationIdentifier>& navigationID, const String& mimeType, bool hasCustomContentProvider, WebCore::FrameLoadType loadType, const WebCore::CertificateInfo& certificateInfo, bool usedLegacyTLS, bool wasPrivateRelayed, const String& proxyName, WebCore::ResourceResponseSource source, bool containsPluginDocument, WebCore::HasInsecureContent hasInsecureContent, WebCore::MouseEventPolicy mouseEventPolicy, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_request(request)
        , m_navigationID(navigationID)
        , m_mimeType(mimeType)
        , m_hasCustomContentProvider(hasCustomContentProvider)
        , m_loadType(loadType)
        , m_certificateInfo(certificateInfo)
        , m_usedLegacyTLS(usedLegacyTLS)
        , m_wasPrivateRelayed(wasPrivateRelayed)
        , m_proxyName(proxyName)
        , m_source(source)
        , m_containsPluginDocument(containsPluginDocument)
        , m_hasInsecureContent(hasInsecureContent)
        , m_mouseEventPolicy(mouseEventPolicy)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        encoder << m_mimeType;
        encoder << m_hasCustomContentProvider;
        encoder << m_loadType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_certificateInfo;
        encoder << m_usedLegacyTLS;
        encoder << m_wasPrivateRelayed;
        encoder << m_proxyName;
        encoder << m_source;
        encoder << m_containsPluginDocument;
        encoder << m_hasInsecureContent;
        encoder << m_mouseEventPolicy;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    const String& m_mimeType;
    bool m_hasCustomContentProvider;
    WebCore::FrameLoadType m_loadType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CertificateInfo& m_certificateInfo;
    bool m_usedLegacyTLS;
    bool m_wasPrivateRelayed;
    const String& m_proxyName;
    WebCore::ResourceResponseSource m_source;
    bool m_containsPluginDocument;
    WebCore::HasInsecureContent m_hasInsecureContent;
    WebCore::MouseEventPolicy m_mouseEventPolicy;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidFailLoadForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, WebCore::ResourceRequest, std::optional<WebCore::NavigationIdentifier>, WebCore::ResourceError, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFailLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFailLoadForFrame(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const WebCore::ResourceRequest& request, const std::optional<WebCore::NavigationIdentifier>& navigationID, const WebCore::ResourceError& error, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_request(request)
        , m_navigationID(navigationID)
        , m_error(error)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidFinishDocumentLoadForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::optional<WebCore::NavigationIdentifier>, WebKit::UserData, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFinishDocumentLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishDocumentLoadForFrame(const WebCore::FrameIdentifier& frameID, const std::optional<WebCore::NavigationIdentifier>& navigationID, const WebKit::UserData& userData, const WallTime& timestamp)
        : m_frameID(frameID)
        , m_navigationID(navigationID)
        , m_userData(userData)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class DidFinishLoadForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, WebCore::ResourceRequest, std::optional<WebCore::NavigationIdentifier>, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFinishLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishLoadForFrame(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, const WebCore::ResourceRequest& request, const std::optional<WebCore::NavigationIdentifier>& navigationID, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_request(request)
        , m_navigationID(navigationID)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidFirstLayoutForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFirstLayoutForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFirstLayoutForFrame(const WebCore::FrameIdentifier& frameID, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidFirstVisuallyNonEmptyLayoutForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::UserData, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFirstVisuallyNonEmptyLayoutForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFirstVisuallyNonEmptyLayoutForFrame(const WebCore::FrameIdentifier& frameID, const WebKit::UserData& userData, const WallTime& timestamp)
        : m_frameID(frameID)
        , m_userData(userData)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class DidReachLayoutMilestone {
public:
    using Arguments = std::tuple<OptionSet<WebCore::LayoutMilestone>, WallTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidReachLayoutMilestone; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReachLayoutMilestone(const OptionSet<WebCore::LayoutMilestone>& layoutMilestones, const WallTime& timestamp)
        : m_layoutMilestones(layoutMilestones)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_layoutMilestones;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::LayoutMilestone>& m_layoutMilestones;
    SUPPRESS_FORWARD_DECL_MEMBER const WallTime& m_timestamp;
};

class DidReceiveTitleForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidReceiveTitleForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveTitleForFrame(const WebCore::FrameIdentifier& frameID, const String& title, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_title(title)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_title;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    const String& m_title;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidDisplayInsecureContentForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidDisplayInsecureContentForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidDisplayInsecureContentForFrame(const WebCore::FrameIdentifier& frameID, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidRunInsecureContentForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidRunInsecureContentForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidRunInsecureContentForFrame(const WebCore::FrameIdentifier& frameID, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidSameDocumentNavigationForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::optional<WebCore::NavigationIdentifier>, WebKit::SameDocumentNavigationType, URL, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidSameDocumentNavigationForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidSameDocumentNavigationForFrame(const WebCore::FrameIdentifier& frameID, const std::optional<WebCore::NavigationIdentifier>& navigationID, WebKit::SameDocumentNavigationType type, const URL& url, const WebKit::UserData& userData)
        : m_frameID(frameID)
        , m_navigationID(navigationID)
        , m_type(type)
        , m_url(url)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
    WebKit::SameDocumentNavigationType m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidSameDocumentNavigationForFrameViaJS {
public:
    using Arguments = std::tuple<WebKit::SameDocumentNavigationType, URL, WebKit::NavigationActionData, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidSameDocumentNavigationForFrameViaJS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidSameDocumentNavigationForFrameViaJS(WebKit::SameDocumentNavigationType type, const URL& url, const WebKit::NavigationActionData& navigationActionData, const WebKit::UserData& userData)
        : m_type(type)
        , m_url(url)
        , m_navigationActionData(navigationActionData)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationActionData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    WebKit::SameDocumentNavigationType m_type;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::NavigationActionData& m_navigationActionData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidChangeMainDocument {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::optional<WebCore::NavigationIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangeMainDocument; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidChangeMainDocument(const WebCore::FrameIdentifier& frameID, const std::optional<WebCore::NavigationIdentifier>& navigationID)
        : m_frameID(frameID)
        , m_navigationID(navigationID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NavigationIdentifier>& m_navigationID;
};

class DidExplicitOpenForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, URL, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidExplicitOpenForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidExplicitOpenForFrame(const WebCore::FrameIdentifier& frameID, const URL& url, const String& mimeType)
        : m_frameID(frameID)
        , m_url(url)
        , m_mimeType(mimeType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << m_mimeType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    const String& m_mimeType;
};

class DidDestroyNavigation {
public:
    using Arguments = std::tuple<WebCore::NavigationIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidDestroyNavigation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDestroyNavigation(const WebCore::NavigationIdentifier& navigationID)
        : m_navigationID(navigationID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NavigationIdentifier& m_navigationID;
};

class UpdateSandboxFlags {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::SandboxFlags>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateSandboxFlags; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateSandboxFlags(const WebCore::FrameIdentifier& frameID, const WebCore::SandboxFlags& sandboxFlags)
        : m_frameID(frameID)
        , m_sandboxFlags(sandboxFlags)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_sandboxFlags;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    const WebCore::SandboxFlags& m_sandboxFlags;
};

class UpdateOpener {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateOpener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateOpener(const WebCore::FrameIdentifier& frameID, const WebCore::FrameIdentifier& newOpener)
        : m_frameID(frameID)
        , m_newOpener(newOpener)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newOpener;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_newOpener;
};

class UpdateScrollingMode {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::ScrollbarMode>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateScrollingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateScrollingMode(const WebCore::FrameIdentifier& frameID, WebCore::ScrollbarMode scrollingMode)
        : m_frameID(frameID)
        , m_scrollingMode(scrollingMode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_scrollingMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    WebCore::ScrollbarMode m_scrollingMode;
};

class ResolveAccessibilityHitTestForTesting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ResolveAccessibilityHitTestForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ResolveAccessibilityHitTestForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    ResolveAccessibilityHitTestForTesting(const WebCore::FrameIdentifier& frameID, const WebCore::IntPoint& point)
        : m_frameID(frameID)
        , m_point(point)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
};

class MainFramePluginHandlesPageScaleGestureDidChange {
public:
    using Arguments = std::tuple<bool, double, double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_MainFramePluginHandlesPageScaleGestureDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    MainFramePluginHandlesPageScaleGestureDidChange(bool mainFramePluginHandlesPageScaleGesture, double minScale, double maxScale)
        : m_mainFramePluginHandlesPageScaleGesture(mainFramePluginHandlesPageScaleGesture)
        , m_minScale(minScale)
        , m_maxScale(maxScale)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mainFramePluginHandlesPageScaleGesture;
        encoder << m_minScale;
        encoder << m_maxScale;
    }

private:
    bool m_mainFramePluginHandlesPageScaleGesture;
    double m_minScale;
    double m_maxScale;
};

#if PLATFORM(GTK) || PLATFORM(WPE)
class DidInitiateLoadForResource {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier, WebCore::FrameIdentifier, WebCore::ResourceRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidInitiateLoadForResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidInitiateLoadForResource(const WebCore::ResourceLoaderIdentifier& resourceID, const WebCore::FrameIdentifier& frameID, const WebCore::ResourceRequest& request)
        : m_resourceID(resourceID)
        , m_frameID(frameID)
        , m_request(request)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class DidSendRequestForResource {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier, WebCore::FrameIdentifier, WebCore::ResourceRequest, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidSendRequestForResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidSendRequestForResource(const WebCore::ResourceLoaderIdentifier& resourceID, const WebCore::FrameIdentifier& frameID, const WebCore::ResourceRequest& request, const WebCore::ResourceResponse& redirectResponse)
        : m_resourceID(resourceID)
        , m_frameID(frameID)
        , m_request(request)
        , m_redirectResponse(redirectResponse)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_redirectResponse;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_redirectResponse;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class DidReceiveResponseForResource {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier, WebCore::FrameIdentifier, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidReceiveResponseForResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveResponseForResource(const WebCore::ResourceLoaderIdentifier& resourceID, const WebCore::FrameIdentifier& frameID, const WebCore::ResourceResponse& response)
        : m_resourceID(resourceID)
        , m_frameID(frameID)
        , m_response(response)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class DidFinishLoadForResource {
public:
    using Arguments = std::tuple<WebCore::ResourceLoaderIdentifier, WebCore::FrameIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFinishLoadForResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishLoadForResource(const WebCore::ResourceLoaderIdentifier& resourceID, const WebCore::FrameIdentifier& frameID, const WebCore::ResourceError& error)
        : m_resourceID(resourceID)
        , m_frameID(frameID)
        , m_error(error)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_resourceID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};
#endif

class DidNavigateWithNavigationData {
public:
    using Arguments = std::tuple<WebKit::WebNavigationDataStore, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidNavigateWithNavigationData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidNavigateWithNavigationData(const WebKit::WebNavigationDataStore& store, const WebCore::FrameIdentifier& frameID)
        : m_store(store)
        , m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_store;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebNavigationDataStore& m_store;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class DidPerformClientRedirect {
public:
    using Arguments = std::tuple<String, String, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidPerformClientRedirect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidPerformClientRedirect(const String& sourceURLString, const String& destinationURLString, const WebCore::FrameIdentifier& frameID)
        : m_sourceURLString(sourceURLString)
        , m_destinationURLString(destinationURLString)
        , m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sourceURLString;
        encoder << m_destinationURLString;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    const String& m_sourceURLString;
    const String& m_destinationURLString;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class DidPerformServerRedirect {
public:
    using Arguments = std::tuple<String, String, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidPerformServerRedirect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidPerformServerRedirect(const String& sourceURLString, const String& destinationURLString, const WebCore::FrameIdentifier& frameID)
        : m_sourceURLString(sourceURLString)
        , m_destinationURLString(destinationURLString)
        , m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sourceURLString;
        encoder << m_destinationURLString;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    const String& m_sourceURLString;
    const String& m_destinationURLString;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class DidUpdateHistoryTitle {
public:
    using Arguments = std::tuple<String, String, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidUpdateHistoryTitle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidUpdateHistoryTitle(const String& title, const String& url, const WebCore::FrameIdentifier& frameID)
        : m_title(title)
        , m_url(url)
        , m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_title;
        encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    const String& m_title;
    const String& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class DidFinishLoadingDataForCustomContentProvider {
public:
    using Arguments = std::tuple<String, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFinishLoadingDataForCustomContentProvider; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishLoadingDataForCustomContentProvider(const String& suggestedFilename, const std::span<const uint8_t>& data)
        : m_suggestedFilename(suggestedFilename)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_suggestedFilename;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    const String& m_suggestedFilename;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};

class WillSubmitForm {
public:
    using Arguments = std::tuple<WebKit::FrameInfoData, WebKit::FrameInfoData, Vector<std::pair<String, String>>, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_WillSubmitForm; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_WillSubmitFormReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    WillSubmitForm(const WebKit::FrameInfoData& frame, const WebKit::FrameInfoData& sourceFrame, const Vector<std::pair<String, String>>& textFieldValues, const WebKit::UserData& userData)
        : m_frame(frame)
        , m_sourceFrame(sourceFrame)
        , m_textFieldValues(textFieldValues)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frame;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sourceFrame;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_textFieldValues;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frame;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_sourceFrame;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::pair<String, String>>& m_textFieldValues;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

#if PLATFORM(IOS_FAMILY)
class InterpretKeyEvent {
public:
    using Arguments = std::tuple<WebKit::EditorState, WebKit::KeyEventInterpretationContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_InterpretKeyEvent; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    InterpretKeyEvent(const WebKit::EditorState& state, const WebKit::KeyEventInterpretationContext& context)
        : m_state(state)
        , m_context(context)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditorState& m_state;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::KeyEventInterpretationContext& m_context;
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidReceivePositionInformation {
public:
    using Arguments = std::tuple<WebKit::InteractionInformationAtPosition>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidReceivePositionInformation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceivePositionInformation(const WebKit::InteractionInformationAtPosition& information)
        : m_information(information)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_information;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::InteractionInformationAtPosition& m_information;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SaveImageToLibrary {
public:
    using Arguments = std::tuple<WebCore::SharedMemory::Handle, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SaveImageToLibrary; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SaveImageToLibrary(WebCore::SharedMemory::Handle&& handle, const String& authorizationToken)
        : m_handle(WTFMove(handle))
        , m_authorizationToken(authorizationToken)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handle);
        encoder << m_authorizationToken;
    }

private:
    WebCore::SharedMemory::Handle&& m_handle;
    const String& m_authorizationToken;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ShowPlaybackTargetPicker {
public:
    using Arguments = std::tuple<bool, WebCore::IntRect, WebCore::RouteSharingPolicy, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowPlaybackTargetPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowPlaybackTargetPicker(bool hasVideo, const WebCore::IntRect& elementRect, WebCore::RouteSharingPolicy policy, const String& routingContextUID)
        : m_hasVideo(hasVideo)
        , m_elementRect(elementRect)
        , m_policy(policy)
        , m_routingContextUID(routingContextUID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasVideo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_elementRect;
        encoder << m_policy;
        encoder << m_routingContextUID;
    }

private:
    bool m_hasVideo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_elementRect;
    WebCore::RouteSharingPolicy m_policy;
    const String& m_routingContextUID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class CommitPotentialTapFailed {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CommitPotentialTapFailed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CommitPotentialTapFailed()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidNotHandleTapAsClick {
public:
    using Arguments = std::tuple<WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidNotHandleTapAsClick; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidNotHandleTapAsClick(const WebCore::IntPoint& point)
        : m_point(point)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidCompleteSyntheticClick {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidCompleteSyntheticClick; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCompleteSyntheticClick()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidHandleTapAsHover {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidHandleTapAsHover; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidHandleTapAsHover()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class DisableDoubleTapGesturesDuringTapIfNecessary {
public:
    using Arguments = std::tuple<WebKit::TapIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DisableDoubleTapGesturesDuringTapIfNecessary; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DisableDoubleTapGesturesDuringTapIfNecessary(const WebKit::TapIdentifier& requestID)
        : m_requestID(requestID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::TapIdentifier& m_requestID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class HandleSmartMagnificationInformationForPotentialTap {
public:
    using Arguments = std::tuple<WebKit::TapIdentifier, WebCore::FloatRect, bool, double, double, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleSmartMagnificationInformationForPotentialTap; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleSmartMagnificationInformationForPotentialTap(const WebKit::TapIdentifier& requestID, const WebCore::FloatRect& renderRect, bool fitEntireRect, double viewportMinimumScale, double viewportMaximumScale, bool nodeIsRootLevel, bool nodeIsPluginElement)
        : m_requestID(requestID)
        , m_renderRect(renderRect)
        , m_fitEntireRect(fitEntireRect)
        , m_viewportMinimumScale(viewportMinimumScale)
        , m_viewportMaximumScale(viewportMaximumScale)
        , m_nodeIsRootLevel(nodeIsRootLevel)
        , m_nodeIsPluginElement(nodeIsPluginElement)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_renderRect;
        encoder << m_fitEntireRect;
        encoder << m_viewportMinimumScale;
        encoder << m_viewportMaximumScale;
        encoder << m_nodeIsRootLevel;
        encoder << m_nodeIsPluginElement;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::TapIdentifier& m_requestID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_renderRect;
    bool m_fitEntireRect;
    double m_viewportMinimumScale;
    double m_viewportMaximumScale;
    bool m_nodeIsRootLevel;
    bool m_nodeIsPluginElement;
};
#endif

#if PLATFORM(IOS_FAMILY)
class IsPotentialTapInProgress {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_IsPotentialTapInProgress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_IsPotentialTapInProgressReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    IsPotentialTapInProgress()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(DATA_DETECTION)
class SetDataDetectionResult {
public:
    using Arguments = std::tuple<WebKit::DataDetectionResult>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetDataDetectionResult; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDataDetectionResult(const WebKit::DataDetectionResult& dataDetectionResult)
        : m_dataDetectionResult(dataDetectionResult)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dataDetectionResult;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DataDetectionResult& m_dataDetectionResult;
};
#endif

#if ENABLE(DATA_DETECTION)
class HandleClickForDataDetectionResult {
public:
    using Arguments = std::tuple<WebCore::DataDetectorElementInfo, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleClickForDataDetectionResult; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleClickForDataDetectionResult(const WebCore::DataDetectorElementInfo& info, const WebCore::IntPoint& location)
        : m_info(info)
        , m_location(location)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_location;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DataDetectorElementInfo& m_info;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_location;
};
#endif

class PageScaleFactorDidChange {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PageScaleFactorDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PageScaleFactorDidChange(double scaleFactor)
        : m_scaleFactor(scaleFactor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scaleFactor;
    }

private:
    double m_scaleFactor;
};

class ViewScaleFactorDidChange {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ViewScaleFactorDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ViewScaleFactorDidChange(double scaleFactor)
        : m_scaleFactor(scaleFactor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scaleFactor;
    }

private:
    double m_scaleFactor;
};

class PluginScaleFactorDidChange {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PluginScaleFactorDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PluginScaleFactorDidChange(double zoomFactor)
        : m_zoomFactor(zoomFactor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_zoomFactor;
    }

private:
    double m_zoomFactor;
};

class PluginZoomFactorDidChange {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PluginZoomFactorDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PluginZoomFactorDidChange(double zoomFactor)
        : m_zoomFactor(zoomFactor)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_zoomFactor;
    }

private:
    double m_zoomFactor;
};

#if PLATFORM(GTK) || PLATFORM(WPE)
class BindAccessibilityTree {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BindAccessibilityTree; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit BindAccessibilityTree(const String& plugID)
        : m_plugID(plugID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_plugID;
    }

private:
    const String& m_plugID;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class SetInputMethodState {
public:
    using Arguments = std::tuple<std::optional<WebKit::InputMethodState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetInputMethodState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetInputMethodState(const std::optional<WebKit::InputMethodState>& state)
        : m_state(state)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::InputMethodState>& m_state;
};
#endif

class BackForwardAddItem {
public:
    using Arguments = std::tuple<Ref<WebKit::FrameState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BackForwardAddItem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit BackForwardAddItem(const Ref<WebKit::FrameState>& navigatedFrameState)
        : m_navigatedFrameState(navigatedFrameState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigatedFrameState;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebKit::FrameState>& m_navigatedFrameState;
};

class BackForwardSetChildItem {
public:
    using Arguments = std::tuple<WebCore::BackForwardFrameItemIdentifier, Ref<WebKit::FrameState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BackForwardSetChildItem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BackForwardSetChildItem(const WebCore::BackForwardFrameItemIdentifier& frameItemID, const Ref<WebKit::FrameState>& frameState)
        : m_frameItemID(frameItemID)
        , m_frameState(frameState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_frameItemID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameState;
    }

private:
    const WebCore::BackForwardFrameItemIdentifier& m_frameItemID;
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebKit::FrameState>& m_frameState;
};

class BackForwardClearChildren {
public:
    using Arguments = std::tuple<WebCore::BackForwardItemIdentifier, WebCore::BackForwardFrameItemIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BackForwardClearChildren; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BackForwardClearChildren(const WebCore::BackForwardItemIdentifier& itemID, const WebCore::BackForwardFrameItemIdentifier& frameItemID)
        : m_itemID(itemID)
        , m_frameItemID(frameItemID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_itemID;
        encoder << m_frameItemID;
    }

private:
    const WebCore::BackForwardItemIdentifier& m_itemID;
    const WebCore::BackForwardFrameItemIdentifier& m_frameItemID;
};

class BackForwardUpdateItem {
public:
    using Arguments = std::tuple<Ref<WebKit::FrameState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BackForwardUpdateItem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit BackForwardUpdateItem(const Ref<WebKit::FrameState>& frameState)
        : m_frameState(frameState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameState;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebKit::FrameState>& m_frameState;
};

class BackForwardGoToItem {
public:
    using Arguments = std::tuple<WebCore::BackForwardItemIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BackForwardGoToItem; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::WebBackForwardListCounts>;
    using Reply = CompletionHandler<void(WebKit::WebBackForwardListCounts&&)>;
    explicit BackForwardGoToItem(const WebCore::BackForwardItemIdentifier& itemID)
        : m_itemID(itemID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_itemID;
    }

private:
    const WebCore::BackForwardItemIdentifier& m_itemID;
};

class BackForwardItemAtIndex {
public:
    using Arguments = std::tuple<int32_t, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BackForwardItemAtIndex; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebKit::FrameState>>;
    using Reply = CompletionHandler<void(RefPtr<WebKit::FrameState>&&)>;
    BackForwardItemAtIndex(int32_t itemIndex, const WebCore::FrameIdentifier& frameID)
        : m_itemIndex(itemIndex)
        , m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_itemIndex;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    int32_t m_itemIndex;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class BackForwardListContainsItem {
public:
    using Arguments = std::tuple<WebCore::BackForwardItemIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BackForwardListContainsItem; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit BackForwardListContainsItem(const WebCore::BackForwardItemIdentifier& itemID)
        : m_itemID(itemID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_itemID;
    }

private:
    const WebCore::BackForwardItemIdentifier& m_itemID;
};

class BackForwardListCounts {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BackForwardListCounts; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::WebBackForwardListCounts>;
    using Reply = CompletionHandler<void(WebKit::WebBackForwardListCounts&&)>;
    BackForwardListCounts()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ShouldGoToBackForwardListItem {
public:
    using Arguments = std::tuple<WebCore::BackForwardItemIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShouldGoToBackForwardListItem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ShouldGoToBackForwardListItemReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ShouldGoToHistoryItem>;
    using Reply = CompletionHandler<void(WebCore::ShouldGoToHistoryItem)>;
    using Promise = WTF::NativePromise<WebCore::ShouldGoToHistoryItem, IPC::Error>;
    ShouldGoToBackForwardListItem(const WebCore::BackForwardItemIdentifier& itemID, bool inBackForwardCache)
        : m_itemID(itemID)
        , m_inBackForwardCache(inBackForwardCache)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_itemID;
        encoder << m_inBackForwardCache;
    }

private:
    const WebCore::BackForwardItemIdentifier& m_itemID;
    bool m_inBackForwardCache;
};

class ShouldGoToBackForwardListItemSync {
public:
    using Arguments = std::tuple<WebCore::BackForwardItemIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShouldGoToBackForwardListItemSync; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ShouldGoToHistoryItem>;
    using Reply = CompletionHandler<void(WebCore::ShouldGoToHistoryItem)>;
    explicit ShouldGoToBackForwardListItemSync(const WebCore::BackForwardItemIdentifier& itemID)
        : m_itemID(itemID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_itemID;
    }

private:
    const WebCore::BackForwardItemIdentifier& m_itemID;
};

class RegisterEditCommandForUndo {
public:
    using Arguments = std::tuple<uint64_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RegisterEditCommandForUndo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterEditCommandForUndo(uint64_t commandID, const String& label)
        : m_commandID(commandID)
        , m_label(label)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_commandID;
        encoder << m_label;
    }

private:
    uint64_t m_commandID;
    const String& m_label;
};

class ClearAllEditCommands {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ClearAllEditCommands; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearAllEditCommands()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RegisterInsertionUndoGrouping {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RegisterInsertionUndoGrouping; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterInsertionUndoGrouping()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CanUndoRedo {
public:
    using Arguments = std::tuple<WebKit::UndoOrRedo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CanUndoRedo; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit CanUndoRedo(WebKit::UndoOrRedo undoOrRedo)
        : m_undoOrRedo(undoOrRedo)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_undoOrRedo;
    }

private:
    WebKit::UndoOrRedo m_undoOrRedo;
};

class ExecuteUndoRedo {
public:
    using Arguments = std::tuple<WebKit::UndoOrRedo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ExecuteUndoRedo; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    explicit ExecuteUndoRedo(WebKit::UndoOrRedo undoOrRedo)
        : m_undoOrRedo(undoOrRedo)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_undoOrRedo;
    }

private:
    WebKit::UndoOrRedo m_undoOrRedo;
};

class LogDiagnosticMessageFromWebProcess {
public:
    using Arguments = std::tuple<String, String, WebCore::ShouldSample>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LogDiagnosticMessageFromWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessageFromWebProcess(const String& message, const String& description, WebCore::ShouldSample shouldSample)
        : m_message(message)
        , m_description(description)
        , m_shouldSample(shouldSample)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_description;
        encoder << m_shouldSample;
    }

private:
    const String& m_message;
    const String& m_description;
    WebCore::ShouldSample m_shouldSample;
};

class LogDiagnosticMessageWithResultFromWebProcess {
public:
    using Arguments = std::tuple<String, String, uint32_t, WebCore::ShouldSample>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LogDiagnosticMessageWithResultFromWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessageWithResultFromWebProcess(const String& message, const String& description, uint32_t result, WebCore::ShouldSample shouldSample)
        : m_message(message)
        , m_description(description)
        , m_result(result)
        , m_shouldSample(shouldSample)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_description;
        encoder << m_result;
        encoder << m_shouldSample;
    }

private:
    const String& m_message;
    const String& m_description;
    uint32_t m_result;
    WebCore::ShouldSample m_shouldSample;
};

class LogDiagnosticMessageWithValueFromWebProcess {
public:
    using Arguments = std::tuple<String, String, double, unsigned, WebCore::ShouldSample>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LogDiagnosticMessageWithValueFromWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessageWithValueFromWebProcess(const String& message, const String& description, double value, const unsigned& significantFigures, WebCore::ShouldSample shouldSample)
        : m_message(message)
        , m_description(description)
        , m_value(value)
        , m_significantFigures(significantFigures)
        , m_shouldSample(shouldSample)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_description;
        encoder << m_value;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_significantFigures;
        encoder << m_shouldSample;
    }

private:
    const String& m_message;
    const String& m_description;
    double m_value;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_significantFigures;
    WebCore::ShouldSample m_shouldSample;
};

class LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess {
public:
    using Arguments = std::tuple<String, String, WebCore::ShouldSample>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess(const String& message, const String& description, WebCore::ShouldSample shouldSample)
        : m_message(message)
        , m_description(description)
        , m_shouldSample(shouldSample)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_description;
        encoder << m_shouldSample;
    }

private:
    const String& m_message;
    const String& m_description;
    WebCore::ShouldSample m_shouldSample;
};

class LogDiagnosticMessageWithValueDictionaryFromWebProcess {
public:
    using Arguments = std::tuple<String, String, WebCore::DiagnosticLoggingDictionary, WebCore::ShouldSample>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LogDiagnosticMessageWithValueDictionaryFromWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessageWithValueDictionaryFromWebProcess(const String& message, const String& description, const WebCore::DiagnosticLoggingDictionary& value, WebCore::ShouldSample shouldSample)
        : m_message(message)
        , m_description(description)
        , m_value(value)
        , m_shouldSample(shouldSample)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_description;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_value;
        encoder << m_shouldSample;
    }

private:
    const String& m_message;
    const String& m_description;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DiagnosticLoggingDictionary& m_value;
    WebCore::ShouldSample m_shouldSample;
};

class LogDiagnosticMessageWithDomainFromWebProcess {
public:
    using Arguments = std::tuple<String, WebCore::DiagnosticLoggingDomain>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LogDiagnosticMessageWithDomainFromWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogDiagnosticMessageWithDomainFromWebProcess(const String& message, const WebCore::DiagnosticLoggingDomain& domain)
        : m_message(message)
        , m_domain(domain)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_domain;
    }

private:
    const String& m_message;
    const WebCore::DiagnosticLoggingDomain& m_domain;
};

class LogScrollingEvent {
public:
    using Arguments = std::tuple<uint32_t, MonotonicTime, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LogScrollingEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LogScrollingEvent(uint32_t eventType, const MonotonicTime& timestamp, uint64_t data)
        : m_eventType(eventType)
        , m_timestamp(timestamp)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_eventType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
        encoder << m_data;
    }

private:
    uint32_t m_eventType;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_timestamp;
    uint64_t m_data;
};

class EditorStateChanged {
public:
    using Arguments = std::tuple<WebKit::EditorState>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_EditorStateChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit EditorStateChanged(const WebKit::EditorState& editorState)
        : m_editorState(editorState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_editorState;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditorState& m_editorState;
};

class CompositionWasCanceled {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CompositionWasCanceled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CompositionWasCanceled()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetHasFocusedElementWithUserInteraction {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetHasFocusedElementWithUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasFocusedElementWithUserInteraction(bool hasFocusedElement)
        : m_hasFocusedElement(hasFocusedElement)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasFocusedElement;
    }

private:
    bool m_hasFocusedElement;
};

#if ENABLE(IMAGE_ANALYSIS)
class RequestTextRecognition {
public:
    using Arguments = std::tuple<URL, WebCore::ShareableBitmapHandle, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestTextRecognition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_RequestTextRecognitionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::TextRecognitionResult>;
    using Reply = CompletionHandler<void(WebCore::TextRecognitionResult&&)>;
    using Promise = WTF::NativePromise<WebCore::TextRecognitionResult, IPC::Error>;
    RequestTextRecognition(const URL& imageURL, WebCore::ShareableBitmapHandle&& imageData, const String& source, const String& target)
        : m_imageURL(imageURL)
        , m_imageData(WTFMove(imageData))
        , m_source(source)
        , m_target(target)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageURL;
        encoder << WTFMove(m_imageData);
        encoder << m_source;
        encoder << m_target;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_imageURL;
    WebCore::ShareableBitmapHandle&& m_imageData;
    const String& m_source;
    const String& m_target;
};
#endif

#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
class HandleContextMenuTranslation {
public:
    using Arguments = std::tuple<WebCore::TranslationContextMenuInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleContextMenuTranslation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HandleContextMenuTranslation(const WebCore::TranslationContextMenuInfo& info)
        : m_info(info)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TranslationContextMenuInfo& m_info;
};
#endif

#if ENABLE(WRITING_TOOLS)
class ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect {
public:
    using Arguments = std::tuple<WebCore::WritingTools::TextSuggestion::ID, WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect(const WebCore::WritingTools::TextSuggestion::ID& replacementID, const WebCore::IntRect& selectionBoundsInRootView)
        : m_replacementID(replacementID)
        , m_selectionBoundsInRootView(selectionBoundsInRootView)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_replacementID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_selectionBoundsInRootView;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::TextSuggestion::ID& m_replacementID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_selectionBoundsInRootView;
};
#endif

#if ENABLE(WRITING_TOOLS)
class ProofreadingSessionUpdateStateForSuggestionWithID {
public:
    using Arguments = std::tuple<WebCore::WritingTools::TextSuggestionState, WebCore::WritingTools::TextSuggestion::ID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ProofreadingSessionUpdateStateForSuggestionWithID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProofreadingSessionUpdateStateForSuggestionWithID(WebCore::WritingTools::TextSuggestionState state, const WebCore::WritingTools::TextSuggestion::ID& replacementID)
        : m_state(state)
        , m_replacementID(replacementID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_state;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_replacementID;
    }

private:
    WebCore::WritingTools::TextSuggestionState m_state;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::TextSuggestion::ID& m_replacementID;
};
#endif

#if ENABLE(WRITING_TOOLS)
class AddTextAnimationForAnimationID {
public:
    using Arguments = std::tuple<WTF::UUID, WebCore::TextAnimationData, RefPtr<WebCore::TextIndicator>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_AddTextAnimationForAnimationID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddTextAnimationForAnimationID(const WTF::UUID& uuid, const WebCore::TextAnimationData& styleData, const RefPtr<WebCore::TextIndicator>& textIndicator)
        : m_uuid(uuid)
        , m_styleData(styleData)
        , m_textIndicator(textIndicator)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_uuid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_styleData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_textIndicator;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_uuid;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TextAnimationData& m_styleData;
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::TextIndicator>& m_textIndicator;
};
#endif

#if ENABLE(WRITING_TOOLS)
class AddTextAnimationForAnimationIDWithCompletionHandler {
public:
    using Arguments = std::tuple<WTF::UUID, WebCore::TextAnimationData, RefPtr<WebCore::TextIndicator>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_AddTextAnimationForAnimationIDWithCompletionHandler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_AddTextAnimationForAnimationIDWithCompletionHandlerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::TextAnimationRunMode>;
    using Reply = CompletionHandler<void(WebCore::TextAnimationRunMode)>;
    using Promise = WTF::NativePromise<WebCore::TextAnimationRunMode, IPC::Error>;
    AddTextAnimationForAnimationIDWithCompletionHandler(const WTF::UUID& uuid, const WebCore::TextAnimationData& styleData, const RefPtr<WebCore::TextIndicator>& textIndicator)
        : m_uuid(uuid)
        , m_styleData(styleData)
        , m_textIndicator(textIndicator)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_uuid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_styleData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_textIndicator;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_uuid;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TextAnimationData& m_styleData;
    SUPPRESS_FORWARD_DECL_MEMBER const RefPtr<WebCore::TextIndicator>& m_textIndicator;
};
#endif

#if ENABLE(WRITING_TOOLS)
class RemoveTextAnimationForAnimationID {
public:
    using Arguments = std::tuple<WTF::UUID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RemoveTextAnimationForAnimationID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveTextAnimationForAnimationID(const WTF::UUID& uuid)
        : m_uuid(uuid)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_uuid;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_uuid;
};
#endif

#if ENABLE(WRITING_TOOLS)
class DidEndPartialIntelligenceTextAnimation {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidEndPartialIntelligenceTextAnimation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidEndPartialIntelligenceTextAnimation()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
class ShowMediaControlsContextMenu {
public:
    using Arguments = std::tuple<WebCore::FloatRect, Vector<WebCore::MediaControlsContextMenuItem>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowMediaControlsContextMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ShowMediaControlsContextMenuReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::MediaControlsContextMenuItem::ID>;
    using Reply = CompletionHandler<void(WebCore::MediaControlsContextMenuItem::ID&&)>;
    using Promise = WTF::NativePromise<WebCore::MediaControlsContextMenuItem::ID, IPC::Error>;
    ShowMediaControlsContextMenu(const WebCore::FloatRect& targetFrame, const Vector<WebCore::MediaControlsContextMenuItem>& items)
        : m_targetFrame(targetFrame)
        , m_items(items)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetFrame;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_items;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_targetFrame;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::MediaControlsContextMenuItem>& m_items;
};
#endif

#if HAVE(TOUCH_BAR)
class SetIsTouchBarUpdateSuppressedForHiddenContentEditable {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetIsTouchBarUpdateSuppressedForHiddenContentEditable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIsTouchBarUpdateSuppressedForHiddenContentEditable(bool isTouchBarUpdateSuppressed)
        : m_isTouchBarUpdateSuppressed(isTouchBarUpdateSuppressed)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isTouchBarUpdateSuppressed;
    }

private:
    bool m_isTouchBarUpdateSuppressed;
};
#endif

#if HAVE(TOUCH_BAR)
class SetIsNeverRichlyEditableForTouchBar {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetIsNeverRichlyEditableForTouchBar; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIsNeverRichlyEditableForTouchBar(bool isNeverRichlyEditable)
        : m_isNeverRichlyEditable(isNeverRichlyEditable)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isNeverRichlyEditable;
    }

private:
    bool m_isNeverRichlyEditable;
};
#endif

class RequestDOMPasteAccess {
public:
    using Arguments = std::tuple<WebCore::DOMPasteAccessCategory, WebCore::FrameIdentifier, WebCore::IntRect, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestDOMPasteAccess; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DOMPasteAccessResponse>;
    using Reply = CompletionHandler<void(WebCore::DOMPasteAccessResponse)>;
    RequestDOMPasteAccess(WebCore::DOMPasteAccessCategory pasteAccessCategory, const WebCore::FrameIdentifier& frameID, const WebCore::IntRect& elementRect, const String& originIdentifier)
        : m_pasteAccessCategory(pasteAccessCategory)
        , m_frameID(frameID)
        , m_elementRect(elementRect)
        , m_originIdentifier(originIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteAccessCategory;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_elementRect;
        encoder << m_originIdentifier;
    }

private:
    WebCore::DOMPasteAccessCategory m_pasteAccessCategory;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_elementRect;
    const String& m_originIdentifier;
};

class SetTextIndicatorFromFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::TextIndicatorData, WebCore::TextIndicatorLifetime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetTextIndicatorFromFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetTextIndicatorFromFrame(const WebCore::FrameIdentifier& frameID, const WebCore::TextIndicatorData& indicator, WebCore::TextIndicatorLifetime lifetime)
        : m_frameID(frameID)
        , m_indicator(indicator)
        , m_lifetime(lifetime)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indicator;
        encoder << m_lifetime;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TextIndicatorData& m_indicator;
    WebCore::TextIndicatorLifetime m_lifetime;
};

class UpdateTextIndicatorFromFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::TextIndicatorData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateTextIndicatorFromFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateTextIndicatorFromFrame(const WebCore::FrameIdentifier& frameID, const WebCore::TextIndicatorData& indicator)
        : m_frameID(frameID)
        , m_indicator(indicator)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_indicator;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TextIndicatorData& m_indicator;
};

class ClearTextIndicator {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ClearTextIndicator; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearTextIndicator()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidGetImageForFindMatch {
public:
    using Arguments = std::tuple<WebCore::ImageBufferParameters, WebCore::ShareableBitmapHandle, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidGetImageForFindMatch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidGetImageForFindMatch(const WebCore::ImageBufferParameters& parameters, WebCore::ShareableBitmapHandle&& contentImageHandle, uint32_t matchIndex)
        : m_parameters(parameters)
        , m_contentImageHandle(WTFMove(contentImageHandle))
        , m_matchIndex(matchIndex)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
        encoder << WTFMove(m_contentImageHandle);
        encoder << m_matchIndex;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ImageBufferParameters& m_parameters;
    WebCore::ShareableBitmapHandle&& m_contentImageHandle;
    uint32_t m_matchIndex;
};

class ShowPopupMenuFromFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::IntRect, uint64_t, Vector<WebKit::WebPopupItem>, int32_t, WebKit::PlatformPopupMenuData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowPopupMenuFromFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowPopupMenuFromFrame(const WebCore::FrameIdentifier& frameID, const WebCore::IntRect& rect, uint64_t textDirection, const Vector<WebKit::WebPopupItem>& items, int32_t selectedIndex, const WebKit::PlatformPopupMenuData& data)
        : m_frameID(frameID)
        , m_rect(rect)
        , m_textDirection(textDirection)
        , m_items(items)
        , m_selectedIndex(selectedIndex)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        encoder << m_textDirection;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_items;
        encoder << m_selectedIndex;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_rect;
    uint64_t m_textDirection;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::WebPopupItem>& m_items;
    int32_t m_selectedIndex;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PlatformPopupMenuData& m_data;
};

class HidePopupMenu {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HidePopupMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HidePopupMenu()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(CONTEXT_MENUS)
class ShowContextMenuFromFrame {
public:
    using Arguments = std::tuple<WebKit::FrameInfoData, WebKit::ContextMenuContextData, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowContextMenuFromFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowContextMenuFromFrame(const WebKit::FrameInfoData& frameInfo, const WebKit::ContextMenuContextData& contextMenuContextData, const WebKit::UserData& userData)
        : m_frameInfo(frameInfo)
        , m_contextMenuContextData(contextMenuContextData)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contextMenuContextData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ContextMenuContextData& m_contextMenuContextData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};
#endif

class DidFinishServiceWorkerPageRegistration {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFinishServiceWorkerPageRegistration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFinishServiceWorkerPageRegistration(bool success)
        : m_success(success)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_success;
    }

private:
    bool m_success;
};

class ExceededDatabaseQuota {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String, String, String, uint64_t, uint64_t, uint64_t, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ExceededDatabaseQuota; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    ExceededDatabaseQuota(const WebCore::FrameIdentifier& frameID, const String& originIdentifier, const String& databaseName, const String& databaseDisplayName, uint64_t currentQuota, uint64_t currentOriginUsage, uint64_t currentDatabaseUsage, uint64_t expectedUsage)
        : m_frameID(frameID)
        , m_originIdentifier(originIdentifier)
        , m_databaseName(databaseName)
        , m_databaseDisplayName(databaseDisplayName)
        , m_currentQuota(currentQuota)
        , m_currentOriginUsage(currentOriginUsage)
        , m_currentDatabaseUsage(currentDatabaseUsage)
        , m_expectedUsage(expectedUsage)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_originIdentifier;
        encoder << m_databaseName;
        encoder << m_databaseDisplayName;
        encoder << m_currentQuota;
        encoder << m_currentOriginUsage;
        encoder << m_currentDatabaseUsage;
        encoder << m_expectedUsage;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    const String& m_originIdentifier;
    const String& m_databaseName;
    const String& m_databaseDisplayName;
    uint64_t m_currentQuota;
    uint64_t m_currentOriginUsage;
    uint64_t m_currentDatabaseUsage;
    uint64_t m_expectedUsage;
};

class RequestGeolocationPermissionForFrame {
public:
    using Arguments = std::tuple<WebKit::GeolocationIdentifier, WebKit::FrameInfoData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestGeolocationPermissionForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestGeolocationPermissionForFrame(const WebKit::GeolocationIdentifier& geolocationID, const WebKit::FrameInfoData& frameInfo)
        : m_geolocationID(geolocationID)
        , m_frameInfo(frameInfo)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_geolocationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::GeolocationIdentifier& m_geolocationID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
};

class RevokeGeolocationAuthorizationToken {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RevokeGeolocationAuthorizationToken; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RevokeGeolocationAuthorizationToken(const String& authorizationToken)
        : m_authorizationToken(authorizationToken)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_authorizationToken;
    }

private:
    const String& m_authorizationToken;
};

#if ENABLE(MEDIA_STREAM)
class RequestUserMediaPermissionForFrame {
public:
    using Arguments = std::tuple<WebCore::UserMediaRequestIdentifier, WebKit::FrameInfoData, WebCore::SecurityOriginData, WebCore::SecurityOriginData, WebCore::MediaStreamRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestUserMediaPermissionForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestUserMediaPermissionForFrame(const WebCore::UserMediaRequestIdentifier& userMediaID, const WebKit::FrameInfoData& frameInfo, const WebCore::SecurityOriginData& userMediaDocumentOriginIdentifier, const WebCore::SecurityOriginData& topLevelDocumentOriginIdentifier, const WebCore::MediaStreamRequest& request)
        : m_userMediaID(userMediaID)
        , m_frameInfo(frameInfo)
        , m_userMediaDocumentOriginIdentifier(userMediaDocumentOriginIdentifier)
        , m_topLevelDocumentOriginIdentifier(topLevelDocumentOriginIdentifier)
        , m_request(request)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMediaID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMediaDocumentOriginIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topLevelDocumentOriginIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::UserMediaRequestIdentifier& m_userMediaID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_userMediaDocumentOriginIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_topLevelDocumentOriginIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaStreamRequest& m_request;
};
#endif

#if ENABLE(MEDIA_STREAM)
class EnumerateMediaDevicesForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::SecurityOriginData, WebCore::SecurityOriginData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_EnumerateMediaDevicesForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_EnumerateMediaDevicesForFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::CaptureDeviceWithCapabilities>, WebCore::MediaDeviceHashSalts>;
    using Reply = CompletionHandler<void(Vector<WebCore::CaptureDeviceWithCapabilities>&&, WebCore::MediaDeviceHashSalts&&)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<WebCore::CaptureDeviceWithCapabilities>, WebCore::MediaDeviceHashSalts>, IPC::Error>;
    EnumerateMediaDevicesForFrame(const WebCore::FrameIdentifier& frameID, const WebCore::SecurityOriginData& userMediaDocumentOriginIdentifier, const WebCore::SecurityOriginData& topLevelDocumentOriginIdentifier)
        : m_frameID(frameID)
        , m_userMediaDocumentOriginIdentifier(userMediaDocumentOriginIdentifier)
        , m_topLevelDocumentOriginIdentifier(topLevelDocumentOriginIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMediaDocumentOriginIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topLevelDocumentOriginIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_userMediaDocumentOriginIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_topLevelDocumentOriginIdentifier;
};
#endif

#if ENABLE(MEDIA_STREAM)
class BeginMonitoringCaptureDevices {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BeginMonitoringCaptureDevices; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BeginMonitoringCaptureDevices()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(MEDIA_STREAM)
class ValidateCaptureStateUpdate {
public:
    using Arguments = std::tuple<WebCore::UserMediaRequestIdentifier, WebCore::ClientOrigin, WebKit::FrameInfoData, bool, WebCore::MediaProducerMediaCaptureKind>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ValidateCaptureStateUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ValidateCaptureStateUpdateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::Exception>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::Exception>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::Exception>, IPC::Error>;
    ValidateCaptureStateUpdate(const WebCore::UserMediaRequestIdentifier& userMediaID, const WebCore::ClientOrigin& clientOrigin, const WebKit::FrameInfoData& frameInfo, bool isActive, WebCore::MediaProducerMediaCaptureKind kind)
        : m_userMediaID(userMediaID)
        , m_clientOrigin(clientOrigin)
        , m_frameInfo(frameInfo)
        , m_isActive(isActive)
        , m_kind(kind)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMediaID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        encoder << m_isActive;
        encoder << m_kind;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::UserMediaRequestIdentifier& m_userMediaID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_clientOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    bool m_isActive;
    WebCore::MediaProducerMediaCaptureKind m_kind;
};
#endif

#if ENABLE(MEDIA_STREAM)
class SetShouldListenToVoiceActivity {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetShouldListenToVoiceActivity; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldListenToVoiceActivity(bool shouldListen)
        : m_shouldListen(shouldListen)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldListen;
    }

private:
    bool m_shouldListen;
};
#endif

#if ENABLE(ENCRYPTED_MEDIA)
class RequestMediaKeySystemPermissionForFrame {
public:
    using Arguments = std::tuple<WebCore::MediaKeySystemRequestIdentifier, WebCore::FrameIdentifier, WebCore::ClientOrigin, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestMediaKeySystemPermissionForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestMediaKeySystemPermissionForFrame(const WebCore::MediaKeySystemRequestIdentifier& mediaKeySystemID, const WebCore::FrameIdentifier& frameID, const WebCore::ClientOrigin& clientOrigin, const String& keySystem)
        : m_mediaKeySystemID(mediaKeySystemID)
        , m_frameID(frameID)
        , m_clientOrigin(clientOrigin)
        , m_keySystem(keySystem)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mediaKeySystemID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientOrigin;
        encoder << m_keySystem;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaKeySystemRequestIdentifier& m_mediaKeySystemID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ClientOrigin& m_clientOrigin;
    const String& m_keySystem;
};
#endif

class RequestNotificationPermission {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestNotificationPermission; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_RequestNotificationPermissionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit RequestNotificationPermission(const String& originIdentifier)
        : m_originIdentifier(originIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_originIdentifier;
    }

private:
    const String& m_originIdentifier;
};

#if USE(UNIFIED_TEXT_CHECKING)
class CheckTextOfParagraph {
public:
    using Arguments = std::tuple<String, OptionSet<WebCore::TextCheckingType>, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CheckTextOfParagraph; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::TextCheckingResult>>;
    using Reply = CompletionHandler<void(Vector<WebCore::TextCheckingResult>&&)>;
    CheckTextOfParagraph(const String& text, const OptionSet<WebCore::TextCheckingType>& checkingTypes, int32_t insertionPoint)
        : m_text(text)
        , m_checkingTypes(checkingTypes)
        , m_insertionPoint(insertionPoint)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_checkingTypes;
        encoder << m_insertionPoint;
    }

private:
    const String& m_text;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::TextCheckingType>& m_checkingTypes;
    int32_t m_insertionPoint;
};
#endif

class CheckSpellingOfString {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CheckSpellingOfString; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<int32_t, int32_t>;
    using Reply = CompletionHandler<void(int32_t, int32_t)>;
    explicit CheckSpellingOfString(const String& text)
        : m_text(text)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
    }

private:
    const String& m_text;
};

class CheckGrammarOfString {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CheckGrammarOfString; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::GrammarDetail>, int32_t, int32_t>;
    using Reply = CompletionHandler<void(Vector<WebCore::GrammarDetail>&&, int32_t, int32_t)>;
    explicit CheckGrammarOfString(const String& text)
        : m_text(text)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
    }

private:
    const String& m_text;
};

class SpellingUIIsShowing {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpellingUIIsShowing; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    SpellingUIIsShowing()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class UpdateSpellingUIWithMisspelledWord {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateSpellingUIWithMisspelledWord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateSpellingUIWithMisspelledWord(const String& misspelledWord)
        : m_misspelledWord(misspelledWord)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_misspelledWord;
    }

private:
    const String& m_misspelledWord;
};

class UpdateSpellingUIWithGrammarString {
public:
    using Arguments = std::tuple<String, WebCore::GrammarDetail>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateSpellingUIWithGrammarString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateSpellingUIWithGrammarString(const String& badGrammarPhrase, const WebCore::GrammarDetail& grammarDetail)
        : m_badGrammarPhrase(badGrammarPhrase)
        , m_grammarDetail(grammarDetail)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_badGrammarPhrase;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_grammarDetail;
    }

private:
    const String& m_badGrammarPhrase;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::GrammarDetail& m_grammarDetail;
};

class GetGuessesForWord {
public:
    using Arguments = std::tuple<String, String, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_GetGuessesForWord; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    GetGuessesForWord(const String& word, const String& context, int32_t insertionPoint)
        : m_word(word)
        , m_context(context)
        , m_insertionPoint(insertionPoint)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_word;
        encoder << m_context;
        encoder << m_insertionPoint;
    }

private:
    const String& m_word;
    const String& m_context;
    int32_t m_insertionPoint;
};

class LearnWord {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LearnWord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit LearnWord(const String& word)
        : m_word(word)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_word;
    }

private:
    const String& m_word;
};

class IgnoreWord {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_IgnoreWord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit IgnoreWord(const String& word)
        : m_word(word)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_word;
    }

private:
    const String& m_word;
};

class RequestCheckingOfString {
public:
    using Arguments = std::tuple<WebKit::TextCheckerRequestID, WebCore::TextCheckingRequestData, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestCheckingOfString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestCheckingOfString(const WebKit::TextCheckerRequestID& requestID, const WebCore::TextCheckingRequestData& request, int32_t insertionPoint)
        : m_requestID(requestID)
        , m_request(request)
        , m_insertionPoint(insertionPoint)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_requestID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        encoder << m_insertionPoint;
    }

private:
    const WebKit::TextCheckerRequestID& m_requestID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TextCheckingRequestData& m_request;
    int32_t m_insertionPoint;
};

#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT)
class StartDrag {
public:
    using Arguments = std::tuple<WebCore::DragItem, WebCore::ShareableBitmapHandle, std::optional<WebCore::NodeIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_StartDrag; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartDrag(const WebCore::DragItem& dragItem, WebCore::ShareableBitmapHandle&& dragImage, const std::optional<WebCore::NodeIdentifier>& nodeID)
        : m_dragItem(dragItem)
        , m_dragImage(WTFMove(dragImage))
        , m_nodeID(nodeID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dragItem;
        encoder << WTFMove(m_dragImage);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nodeID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DragItem& m_dragItem;
    WebCore::ShareableBitmapHandle&& m_dragImage;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NodeIdentifier>& m_nodeID;
};
#endif

#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT)
class SetPromisedDataForImage {
public:
    using Arguments = std::tuple<String, WebCore::SharedMemory::Handle, String, String, String, String, String, WebCore::SharedMemory::Handle, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetPromisedDataForImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetPromisedDataForImage(const String& pasteboardName, WebCore::SharedMemory::Handle&& imageHandle, const String& filename, const String& extension, const String& title, const String& url, const String& visibleURL, WebCore::SharedMemory::Handle&& archiveHandle, const String& originIdentifier)
        : m_pasteboardName(pasteboardName)
        , m_imageHandle(WTFMove(imageHandle))
        , m_filename(filename)
        , m_extension(extension)
        , m_title(title)
        , m_url(url)
        , m_visibleURL(visibleURL)
        , m_archiveHandle(WTFMove(archiveHandle))
        , m_originIdentifier(originIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardName;
        encoder << WTFMove(m_imageHandle);
        encoder << m_filename;
        encoder << m_extension;
        encoder << m_title;
        encoder << m_url;
        encoder << m_visibleURL;
        encoder << WTFMove(m_archiveHandle);
        encoder << m_originIdentifier;
    }

private:
    const String& m_pasteboardName;
    WebCore::SharedMemory::Handle&& m_imageHandle;
    const String& m_filename;
    const String& m_extension;
    const String& m_title;
    const String& m_url;
    const String& m_visibleURL;
    WebCore::SharedMemory::Handle&& m_archiveHandle;
    const String& m_originIdentifier;
};
#endif

#if (PLATFORM(GTK) || PLATFORM(WPE)) && ENABLE(DRAG_SUPPORT)
class StartDrag {
public:
    using Arguments = std::tuple<WebCore::SelectionData, OptionSet<WebCore::DragOperation>, std::optional<WebCore::ShareableBitmapHandle>, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_StartDrag; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartDrag(const WebCore::SelectionData& selectionData, const OptionSet<WebCore::DragOperation>& dragOperationMask, std::optional<WebCore::ShareableBitmapHandle>&& dragImage, const WebCore::IntPoint& dragImageHotspot)
        : m_selectionData(selectionData)
        , m_dragOperationMask(dragOperationMask)
        , m_dragImage(WTFMove(dragImage))
        , m_dragImageHotspot(dragImageHotspot)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_selectionData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dragOperationMask;
        encoder << WTFMove(m_dragImage);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dragImageHotspot;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SelectionData& m_selectionData;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::DragOperation>& m_dragOperationMask;
    std::optional<WebCore::ShareableBitmapHandle>&& m_dragImage;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_dragImageHotspot;
};
#endif

#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
class WillReceiveEditDragSnapshot {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_WillReceiveEditDragSnapshot; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WillReceiveEditDragSnapshot()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
class DidReceiveEditDragSnapshot {
public:
    using Arguments = std::tuple<std::optional<WebCore::TextIndicatorData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidReceiveEditDragSnapshot; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveEditDragSnapshot(const std::optional<WebCore::TextIndicatorData>& textIndicator)
        : m_textIndicator(textIndicator)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_textIndicator;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::TextIndicatorData>& m_textIndicator;
};
#endif

#if ENABLE(MODEL_PROCESS)
class DidReceiveInteractiveModelElement {
public:
    using Arguments = std::tuple<std::optional<WebCore::NodeIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidReceiveInteractiveModelElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidReceiveInteractiveModelElement(const std::optional<WebCore::NodeIdentifier>& nodeID)
        : m_nodeID(nodeID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nodeID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NodeIdentifier>& m_nodeID;
};
#endif

#if PLATFORM(COCOA)
class DidPerformDictionaryLookup {
public:
    using Arguments = std::tuple<WebCore::DictionaryPopupInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidPerformDictionaryLookup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidPerformDictionaryLookup(const WebCore::DictionaryPopupInfo& dictionaryPopupInfo)
        : m_dictionaryPopupInfo(dictionaryPopupInfo)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dictionaryPopupInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DictionaryPopupInfo& m_dictionaryPopupInfo;
};
#endif

#if PLATFORM(COCOA)
class ExecuteSavedCommandBySelector {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ExecuteSavedCommandBySelector; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit ExecuteSavedCommandBySelector(const String& selector)
        : m_selector(selector)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_selector;
    }

private:
    const String& m_selector;
};
#endif

#if PLATFORM(COCOA)
class RegisterWebProcessAccessibilityToken {
public:
    using Arguments = std::tuple<std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RegisterWebProcessAccessibilityToken; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterWebProcessAccessibilityToken(const std::span<const uint8_t>& data)
        : m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};
#endif

#if PLATFORM(COCOA)
class GetIsSpeaking {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_GetIsSpeaking; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    GetIsSpeaking()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class MakeFirstResponder {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_MakeFirstResponder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    MakeFirstResponder()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class AssistiveTechnologyMakeFirstResponder {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_AssistiveTechnologyMakeFirstResponder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AssistiveTechnologyMakeFirstResponder()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class SearchTheWeb {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SearchTheWeb; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SearchTheWeb(const String& string)
        : m_string(string)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_string;
    }

private:
    const String& m_string;
};
#endif

#if USE(APPKIT)
class SubstitutionsPanelIsShowing {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SubstitutionsPanelIsShowing; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    SubstitutionsPanelIsShowing()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(AUTOMATIC_TEXT_REPLACEMENT)
class toggleSmartInsertDelete {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_toggleSmartInsertDelete; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    toggleSmartInsertDelete()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(AUTOMATIC_TEXT_REPLACEMENT)
class toggleAutomaticQuoteSubstitution {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_toggleAutomaticQuoteSubstitution; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    toggleAutomaticQuoteSubstitution()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(AUTOMATIC_TEXT_REPLACEMENT)
class toggleAutomaticLinkDetection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_toggleAutomaticLinkDetection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    toggleAutomaticLinkDetection()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(AUTOMATIC_TEXT_REPLACEMENT)
class toggleAutomaticDashSubstitution {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_toggleAutomaticDashSubstitution; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    toggleAutomaticDashSubstitution()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(AUTOMATIC_TEXT_REPLACEMENT)
class toggleAutomaticTextReplacement {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_toggleAutomaticTextReplacement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    toggleAutomaticTextReplacement()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(MAC)
class ShowCorrectionPanel {
public:
    using Arguments = std::tuple<WebCore::AlternativeTextType, WebCore::FloatRect, String, String, Vector<String>, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowCorrectionPanel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowCorrectionPanel(WebCore::AlternativeTextType panelType, const WebCore::FloatRect& boundingBoxOfReplacedString, const String& replacedString, const String& replacementString, const Vector<String>& alternativeReplacementStrings, const WebCore::FrameIdentifier& rootFrameID)
        : m_panelType(panelType)
        , m_boundingBoxOfReplacedString(boundingBoxOfReplacedString)
        , m_replacedString(replacedString)
        , m_replacementString(replacementString)
        , m_alternativeReplacementStrings(alternativeReplacementStrings)
        , m_rootFrameID(rootFrameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_panelType;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_boundingBoxOfReplacedString;
        encoder << m_replacedString;
        encoder << m_replacementString;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_alternativeReplacementStrings;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rootFrameID;
    }

private:
    WebCore::AlternativeTextType m_panelType;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_boundingBoxOfReplacedString;
    const String& m_replacedString;
    const String& m_replacementString;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_alternativeReplacementStrings;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_rootFrameID;
};
#endif

#if PLATFORM(MAC)
class DismissCorrectionPanel {
public:
    using Arguments = std::tuple<WebCore::ReasonForDismissingAlternativeText>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DismissCorrectionPanel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DismissCorrectionPanel(WebCore::ReasonForDismissingAlternativeText reason)
        : m_reason(reason)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_reason;
    }

private:
    WebCore::ReasonForDismissingAlternativeText m_reason;
};
#endif

#if PLATFORM(MAC)
class DismissCorrectionPanelSoon {
public:
    using Arguments = std::tuple<WebCore::ReasonForDismissingAlternativeText>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DismissCorrectionPanelSoon; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    explicit DismissCorrectionPanelSoon(WebCore::ReasonForDismissingAlternativeText reason)
        : m_reason(reason)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_reason;
    }

private:
    WebCore::ReasonForDismissingAlternativeText m_reason;
};
#endif

#if PLATFORM(MAC)
class RecordAutocorrectionResponse {
public:
    using Arguments = std::tuple<WebCore::AutocorrectionResponse, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RecordAutocorrectionResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RecordAutocorrectionResponse(WebCore::AutocorrectionResponse response, const String& replacedString, const String& replacementString)
        : m_response(response)
        , m_replacedString(replacedString)
        , m_replacementString(replacementString)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_response;
        encoder << m_replacedString;
        encoder << m_replacementString;
    }

private:
    WebCore::AutocorrectionResponse m_response;
    const String& m_replacedString;
    const String& m_replacementString;
};
#endif

#if PLATFORM(MAC)
class SetEditableElementIsFocused {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetEditableElementIsFocused; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetEditableElementIsFocused(bool editableElementIsFocused)
        : m_editableElementIsFocused(editableElementIsFocused)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_editableElementIsFocused;
    }

private:
    bool m_editableElementIsFocused;
};
#endif

#if PLATFORM(MAC)
class HandleAcceptsFirstMouse {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleAcceptsFirstMouse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HandleAcceptsFirstMouse(bool acceptsFirstMouse)
        : m_acceptsFirstMouse(acceptsFirstMouse)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_acceptsFirstMouse;
    }

private:
    bool m_acceptsFirstMouse;
};
#endif

class DidUpdateRenderingAfterCommittingLoad {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidUpdateRenderingAfterCommittingLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidUpdateRenderingAfterCommittingLoad()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if USE(DICTATION_ALTERNATIVES)
class ShowDictationAlternativeUI {
public:
    using Arguments = std::tuple<WebCore::FloatRect, WebCore::DictationContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowDictationAlternativeUI; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowDictationAlternativeUI(const WebCore::FloatRect& boundingBoxOfDictatedText, const WebCore::DictationContext& dictationContext)
        : m_boundingBoxOfDictatedText(boundingBoxOfDictatedText)
        , m_dictationContext(dictationContext)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_boundingBoxOfDictatedText;
        encoder << m_dictationContext;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_boundingBoxOfDictatedText;
    const WebCore::DictationContext& m_dictationContext;
};
#endif

#if USE(DICTATION_ALTERNATIVES)
class RemoveDictationAlternatives {
public:
    using Arguments = std::tuple<WebCore::DictationContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RemoveDictationAlternatives; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveDictationAlternatives(const WebCore::DictationContext& dictationContext)
        : m_dictationContext(dictationContext)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_dictationContext;
    }

private:
    const WebCore::DictationContext& m_dictationContext;
};
#endif

#if USE(DICTATION_ALTERNATIVES)
class DictationAlternatives {
public:
    using Arguments = std::tuple<WebCore::DictationContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DictationAlternatives; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    explicit DictationAlternatives(const WebCore::DictationContext& dictationContext)
        : m_dictationContext(dictationContext)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_dictationContext;
    }

private:
    const WebCore::DictationContext& m_dictationContext;
};
#endif

#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
class BeginTextRecognitionForVideoInElementFullScreen {
public:
    using Arguments = std::tuple<WebCore::MediaPlayerIdentifier, WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BeginTextRecognitionForVideoInElementFullScreen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BeginTextRecognitionForVideoInElementFullScreen(const WebCore::MediaPlayerIdentifier& identifier, const WebCore::FloatRect& videoBounds)
        : m_identifier(identifier)
        , m_videoBounds(videoBounds)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_videoBounds;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_videoBounds;
};
#endif

#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
class CancelTextRecognitionForVideoInElementFullScreen {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CancelTextRecognitionForVideoInElementFullScreen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelTextRecognitionForVideoInElementFullScreen()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class CouldNotRestorePageState {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CouldNotRestorePageState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CouldNotRestorePageState()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class RestorePageState {
public:
    using Arguments = std::tuple<std::optional<WebCore::FloatPoint>, WebCore::FloatPoint, WebCore::FloatBoxExtent, double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RestorePageState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RestorePageState(const std::optional<WebCore::FloatPoint>& scrollPosition, const WebCore::FloatPoint& scrollOrigin, const WebCore::FloatBoxExtent& obscuredInsetsOnSave, double scale)
        : m_scrollPosition(scrollPosition)
        , m_scrollOrigin(scrollOrigin)
        , m_obscuredInsetsOnSave(obscuredInsetsOnSave)
        , m_scale(scale)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scrollPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_scrollOrigin;
        encoder << m_obscuredInsetsOnSave;
        encoder << m_scale;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatPoint>& m_scrollPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_scrollOrigin;
    const WebCore::FloatBoxExtent& m_obscuredInsetsOnSave;
    double m_scale;
};
#endif

#if PLATFORM(IOS_FAMILY)
class RestorePageCenterAndScale {
public:
    using Arguments = std::tuple<std::optional<WebCore::FloatPoint>, double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RestorePageCenterAndScale; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RestorePageCenterAndScale(const std::optional<WebCore::FloatPoint>& unobscuredCenter, double scale)
        : m_unobscuredCenter(unobscuredCenter)
        , m_scale(scale)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_unobscuredCenter;
        encoder << m_scale;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatPoint>& m_unobscuredCenter;
    double m_scale;
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidGetTapHighlightGeometries {
public:
    using Arguments = std::tuple<WebKit::TapIdentifier, WebCore::Color, Vector<WebCore::FloatQuad>, WebCore::IntSize, WebCore::IntSize, WebCore::IntSize, WebCore::IntSize, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidGetTapHighlightGeometries; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidGetTapHighlightGeometries(const WebKit::TapIdentifier& requestID, const WebCore::Color& color, const Vector<WebCore::FloatQuad>& geometries, const WebCore::IntSize& topLeftRadius, const WebCore::IntSize& topRightRadius, const WebCore::IntSize& bottomLeftRadius, const WebCore::IntSize& bottomRightRadius, bool nodeHasBuiltInClickHandling)
        : m_requestID(requestID)
        , m_color(color)
        , m_geometries(geometries)
        , m_topLeftRadius(topLeftRadius)
        , m_topRightRadius(topRightRadius)
        , m_bottomLeftRadius(bottomLeftRadius)
        , m_bottomRightRadius(bottomRightRadius)
        , m_nodeHasBuiltInClickHandling(nodeHasBuiltInClickHandling)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_geometries;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topLeftRadius;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topRightRadius;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bottomLeftRadius;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bottomRightRadius;
        encoder << m_nodeHasBuiltInClickHandling;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::TapIdentifier& m_requestID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::FloatQuad>& m_geometries;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_topLeftRadius;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_topRightRadius;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_bottomLeftRadius;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_bottomRightRadius;
    bool m_nodeHasBuiltInClickHandling;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ElementDidFocus {
public:
    using Arguments = std::tuple<WebKit::FocusedElementInformation, bool, bool, OptionSet<WebCore::ActivityState>, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ElementDidFocus; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ElementDidFocus(const WebKit::FocusedElementInformation& information, bool userIsInteracting, bool blurPreviousNode, const OptionSet<WebCore::ActivityState>& activityStateChanges, const WebKit::UserData& userData)
        : m_information(information)
        , m_userIsInteracting(userIsInteracting)
        , m_blurPreviousNode(blurPreviousNode)
        , m_activityStateChanges(activityStateChanges)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_information;
        encoder << m_userIsInteracting;
        encoder << m_blurPreviousNode;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_activityStateChanges;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    const WebKit::FocusedElementInformation& m_information;
    bool m_userIsInteracting;
    bool m_blurPreviousNode;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::ActivityState>& m_activityStateChanges;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ElementDidBlur {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ElementDidBlur; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ElementDidBlur()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class UpdateInputContextAfterBlurringAndRefocusingElement {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateInputContextAfterBlurringAndRefocusingElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateInputContextAfterBlurringAndRefocusingElement()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidProgrammaticallyClearFocusedElement {
public:
    using Arguments = std::tuple<WebCore::ElementContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidProgrammaticallyClearFocusedElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidProgrammaticallyClearFocusedElement(const WebCore::ElementContext& context)
        : m_context(context)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_context;
};
#endif

#if PLATFORM(IOS_FAMILY)
class UpdateFocusedElementInformation {
public:
    using Arguments = std::tuple<WebKit::FocusedElementInformation>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateFocusedElementInformation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateFocusedElementInformation(const WebKit::FocusedElementInformation& information)
        : m_information(information)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_information;
    }

private:
    const WebKit::FocusedElementInformation& m_information;
};
#endif

#if PLATFORM(IOS_FAMILY)
class FocusedElementDidChangeInputMode {
public:
    using Arguments = std::tuple<WebCore::InputMode>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_FocusedElementDidChangeInputMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FocusedElementDidChangeInputMode(WebCore::InputMode mode)
        : m_mode(mode)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
    }

private:
    WebCore::InputMode m_mode;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ScrollingNodeScrollWillStartScroll {
public:
    using Arguments = std::tuple<std::optional<WebCore::ScrollingNodeID>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ScrollingNodeScrollWillStartScroll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ScrollingNodeScrollWillStartScroll(const std::optional<WebCore::ScrollingNodeID>& nodeID)
        : m_nodeID(nodeID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nodeID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ScrollingNodeID>& m_nodeID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ScrollingNodeScrollDidEndScroll {
public:
    using Arguments = std::tuple<std::optional<WebCore::ScrollingNodeID>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ScrollingNodeScrollDidEndScroll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ScrollingNodeScrollDidEndScroll(const std::optional<WebCore::ScrollingNodeID>& nodeID)
        : m_nodeID(nodeID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nodeID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ScrollingNodeID>& m_nodeID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ShowInspectorHighlight {
public:
    using Arguments = std::tuple<WebCore::InspectorOverlayHighlight>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowInspectorHighlight; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ShowInspectorHighlight(const WebCore::InspectorOverlayHighlight& highlight)
        : m_highlight(highlight)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_highlight;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::InspectorOverlayHighlight& m_highlight;
};
#endif

#if PLATFORM(IOS_FAMILY)
class HideInspectorHighlight {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HideInspectorHighlight; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HideInspectorHighlight()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class ShowInspectorIndication {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowInspectorIndication; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowInspectorIndication()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class HideInspectorIndication {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HideInspectorIndication; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HideInspectorIndication()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class EnableInspectorNodeSearch {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_EnableInspectorNodeSearch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnableInspectorNodeSearch()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class DisableInspectorNodeSearch {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DisableInspectorNodeSearch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DisableInspectorNodeSearch()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class UpdateStringForFind {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateStringForFind; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateStringForFind(const String& findString)
        : m_findString(findString)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_findString;
    }

private:
    const String& m_findString;
};
#endif

#if PLATFORM(IOS_FAMILY)
class HandleAutocorrectionContext {
public:
    using Arguments = std::tuple<WebKit::WebAutocorrectionContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleAutocorrectionContext; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HandleAutocorrectionContext(const WebKit::WebAutocorrectionContext& context)
        : m_context(context)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebAutocorrectionContext& m_context;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ShowDataDetectorsUIForPositionInformation {
public:
    using Arguments = std::tuple<WebKit::InteractionInformationAtPosition>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowDataDetectorsUIForPositionInformation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ShowDataDetectorsUIForPositionInformation(const WebKit::InteractionInformationAtPosition& information)
        : m_information(information)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_information;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::InteractionInformationAtPosition& m_information;
};
#endif

class DidChangeInspectorFrontendCount {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidChangeInspectorFrontendCount; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChangeInspectorFrontendCount(uint32_t count)
        : m_count(count)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_count;
    }

private:
    uint32_t m_count;
};

class CreateInspectorTarget {
public:
    using Arguments = std::tuple<String, Inspector::InspectorTargetType>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CreateInspectorTarget; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateInspectorTarget(const String& targetId, Inspector::InspectorTargetType type)
        : m_targetId(targetId)
        , m_type(type)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_targetId;
        encoder << m_type;
    }

private:
    const String& m_targetId;
    Inspector::InspectorTargetType m_type;
};

class DestroyInspectorTarget {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DestroyInspectorTarget; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DestroyInspectorTarget(const String& targetId)
        : m_targetId(targetId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_targetId;
    }

private:
    const String& m_targetId;
};

class SendMessageToInspectorFrontend {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SendMessageToInspectorFrontend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SendMessageToInspectorFrontend(const String& targetId, const String& message)
        : m_targetId(targetId)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_targetId;
        encoder << m_message;
    }

private:
    const String& m_targetId;
    const String& m_message;
};

class SaveRecentSearches {
public:
    using Arguments = std::tuple<String, Vector<WebCore::RecentSearch>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SaveRecentSearches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SaveRecentSearches(const String& name, const Vector<WebCore::RecentSearch>& searchItems)
        : m_name(name)
        , m_searchItems(searchItems)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_searchItems;
    }

private:
    const String& m_name;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::RecentSearch>& m_searchItems;
};

class LoadRecentSearches {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LoadRecentSearches; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::RecentSearch>>;
    using Reply = CompletionHandler<void(Vector<WebCore::RecentSearch>&&)>;
    explicit LoadRecentSearches(const String& name)
        : m_name(name)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
    }

private:
    const String& m_name;
};

class DidUpdateActivityState {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidUpdateActivityState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidUpdateActivityState()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SerializeAndWrapCryptoKey {
public:
    using Arguments = std::tuple<WebCore::CryptoKeyData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SerializeAndWrapCryptoKey; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<uint8_t>>>;
    using Reply = CompletionHandler<void(std::optional<Vector<uint8_t>>&&)>;
    explicit SerializeAndWrapCryptoKey(const WebCore::CryptoKeyData& key)
        : m_key(key)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_key;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CryptoKeyData& m_key;
};

class UnwrapCryptoKey {
public:
    using Arguments = std::tuple<WebCore::WrappedCryptoKey>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UnwrapCryptoKey; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<Vector<uint8_t>>>;
    using Reply = CompletionHandler<void(std::optional<Vector<uint8_t>>&&)>;
    explicit UnwrapCryptoKey(const WebCore::WrappedCryptoKey& wrappedKey)
        : m_wrappedKey(wrappedKey)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_wrappedKey;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WrappedCryptoKey& m_wrappedKey;
};

#if (ENABLE(TELEPHONE_NUMBER_DETECTION) && PLATFORM(MAC))
class ShowTelephoneNumberMenu {
public:
    using Arguments = std::tuple<String, WebCore::IntPoint, WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowTelephoneNumberMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowTelephoneNumberMenu(const String& telephoneNumber, const WebCore::IntPoint& point, const WebCore::IntRect& rect)
        : m_telephoneNumber(telephoneNumber)
        , m_point(point)
        , m_rect(rect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_telephoneNumber;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    const String& m_telephoneNumber;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_rect;
};
#endif

#if USE(QUICK_LOOK)
class DidStartLoadForQuickLookDocumentInMainFrame {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidStartLoadForQuickLookDocumentInMainFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStartLoadForQuickLookDocumentInMainFrame(const String& fileName, const String& uti)
        : m_fileName(fileName)
        , m_uti(uti)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_fileName;
        encoder << m_uti;
    }

private:
    const String& m_fileName;
    const String& m_uti;
};
#endif

#if USE(QUICK_LOOK)
class DidFinishLoadForQuickLookDocumentInMainFrame {
public:
    using Arguments = std::tuple<WebCore::ShareableResourceHandle>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFinishLoadForQuickLookDocumentInMainFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFinishLoadForQuickLookDocumentInMainFrame(WebCore::ShareableResourceHandle&& resource)
        : m_resource(WTFMove(resource))
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_resource);
    }

private:
    WebCore::ShareableResourceHandle&& m_resource;
};
#endif

#if USE(QUICK_LOOK)
class RequestPasswordForQuickLookDocumentInMainFrame {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestPasswordForQuickLookDocumentInMainFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_RequestPasswordForQuickLookDocumentInMainFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit RequestPasswordForQuickLookDocumentInMainFrame(const String& fileName)
        : m_fileName(fileName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_fileName;
    }

private:
    const String& m_fileName;
};
#endif

#if ENABLE(CONTENT_FILTERING)
class ContentFilterDidBlockLoadForFrame {
public:
    using Arguments = std::tuple<WebCore::ContentFilterUnblockHandler, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ContentFilterDidBlockLoadForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ContentFilterDidBlockLoadForFrame(const WebCore::ContentFilterUnblockHandler& unblockHandler, const WebCore::FrameIdentifier& frameID)
        : m_unblockHandler(unblockHandler)
        , m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_unblockHandler;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ContentFilterUnblockHandler& m_unblockHandler;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};
#endif

#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
class IsAnyAnimationAllowedToPlayDidChange {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_IsAnyAnimationAllowedToPlayDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit IsAnyAnimationAllowedToPlayDidChange(bool anyAnimationCanPlay)
        : m_anyAnimationCanPlay(anyAnimationCanPlay)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_anyAnimationCanPlay;
    }

private:
    bool m_anyAnimationCanPlay;
};
#endif

class IsPlayingMediaDidChange {
public:
    using Arguments = std::tuple<OptionSet<WebCore::MediaProducerMediaState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_IsPlayingMediaDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit IsPlayingMediaDidChange(const OptionSet<WebCore::MediaProducerMediaState>& state)
        : m_state(state)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::MediaProducerMediaState>& m_state;
};

class HandleAutoplayEvent {
public:
    using Arguments = std::tuple<WebCore::AutoplayEvent, OptionSet<WebCore::AutoplayEventFlags>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleAutoplayEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleAutoplayEvent(WebCore::AutoplayEvent event, const OptionSet<WebCore::AutoplayEventFlags>& flags)
        : m_event(event)
        , m_flags(flags)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_event;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_flags;
    }

private:
    WebCore::AutoplayEvent m_event;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::AutoplayEventFlags>& m_flags;
};

#if PLATFORM(MAC)
class DidPerformImmediateActionHitTest {
public:
    using Arguments = std::tuple<WebKit::WebHitTestResultData, bool, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidPerformImmediateActionHitTest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = true;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidPerformImmediateActionHitTest(const WebKit::WebHitTestResultData& result, bool contentPreventsDefault, const WebKit::UserData& userData)
        : m_result(result)
        , m_contentPreventsDefault(contentPreventsDefault)
        , m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
        encoder << m_contentPreventsDefault;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebHitTestResultData& m_result;
    bool m_contentPreventsDefault;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};
#endif

class HandleMessage {
public:
    using Arguments = std::tuple<String, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleMessage(const String& messageName, const WebKit::UserData& messageBody)
        : m_messageName(messageName)
        , m_messageBody(messageBody)
    {
        ASSERT(isInWebProcess());
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

class HandleMessageWithAsyncReply {
public:
    using Arguments = std::tuple<String, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleMessageWithAsyncReply; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_HandleMessageWithAsyncReplyReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::UserData>;
    using Reply = CompletionHandler<void(WebKit::UserData&&)>;
    using Promise = WTF::NativePromise<WebKit::UserData, IPC::Error>;
    HandleMessageWithAsyncReply(const String& messageName, const WebKit::UserData& messageBody)
        : m_messageName(messageName)
        , m_messageBody(messageBody)
    {
        ASSERT(isInWebProcess());
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

class HandleSynchronousMessage {
public:
    using Arguments = std::tuple<String, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleSynchronousMessage; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::UserData>;
    using Reply = CompletionHandler<void(WebKit::UserData&&)>;
    HandleSynchronousMessage(const String& messageName, const WebKit::UserData& messageBody)
        : m_messageName(messageName)
        , m_messageBody(messageBody)
    {
        ASSERT(isInWebProcess());
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

class HandleAutoFillButtonClick {
public:
    using Arguments = std::tuple<WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleAutoFillButtonClick; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HandleAutoFillButtonClick(const WebKit::UserData& userData)
        : m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class DidResignInputElementStrongPasswordAppearance {
public:
    using Arguments = std::tuple<WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidResignInputElementStrongPasswordAppearance; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidResignInputElementStrongPasswordAppearance(const WebKit::UserData& userData)
        : m_userData(userData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::UserData& m_userData;
};

class PerformSwitchHapticFeedback {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PerformSwitchHapticFeedback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PerformSwitchHapticFeedback()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(CONTENT_EXTENSIONS)
class ContentRuleListNotification {
public:
    using Arguments = std::tuple<URL, WebCore::ContentRuleListResults>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ContentRuleListNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ContentRuleListNotification(const URL& url, const WebCore::ContentRuleListResults& results)
        : m_url(url)
        , m_results(results)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_results;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ContentRuleListResults& m_results;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class AddPlaybackTargetPickerClient {
public:
    using Arguments = std::tuple<WebCore::PlaybackTargetClientContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_AddPlaybackTargetPickerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddPlaybackTargetPickerClient(const WebCore::PlaybackTargetClientContextIdentifier& contextId)
        : m_contextId(contextId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contextId;
    }

private:
    const WebCore::PlaybackTargetClientContextIdentifier& m_contextId;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class RemovePlaybackTargetPickerClient {
public:
    using Arguments = std::tuple<WebCore::PlaybackTargetClientContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RemovePlaybackTargetPickerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemovePlaybackTargetPickerClient(const WebCore::PlaybackTargetClientContextIdentifier& contextId)
        : m_contextId(contextId)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contextId;
    }

private:
    const WebCore::PlaybackTargetClientContextIdentifier& m_contextId;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class ShowPlaybackTargetPicker {
public:
    using Arguments = std::tuple<WebCore::PlaybackTargetClientContextIdentifier, WebCore::FloatRect, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowPlaybackTargetPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ShowPlaybackTargetPicker(const WebCore::PlaybackTargetClientContextIdentifier& contextId, const WebCore::FloatRect& pickerLocation, bool hasVideo)
        : m_contextId(contextId)
        , m_pickerLocation(pickerLocation)
        , m_hasVideo(hasVideo)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contextId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pickerLocation;
        encoder << m_hasVideo;
    }

private:
    const WebCore::PlaybackTargetClientContextIdentifier& m_contextId;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_pickerLocation;
    bool m_hasVideo;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class PlaybackTargetPickerClientStateDidChange {
public:
    using Arguments = std::tuple<WebCore::PlaybackTargetClientContextIdentifier, OptionSet<WebCore::MediaProducerMediaState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PlaybackTargetPickerClientStateDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PlaybackTargetPickerClientStateDidChange(const WebCore::PlaybackTargetClientContextIdentifier& contextId, const OptionSet<WebCore::MediaProducerMediaState>& mediaState)
        : m_contextId(contextId)
        , m_mediaState(mediaState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contextId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mediaState;
    }

private:
    const WebCore::PlaybackTargetClientContextIdentifier& m_contextId;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::MediaProducerMediaState>& m_mediaState;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class SetMockMediaPlaybackTargetPickerEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetMockMediaPlaybackTargetPickerEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMockMediaPlaybackTargetPickerEnabled(bool enabled)
        : m_enabled(enabled)
    {
        ASSERT(isInWebProcess());
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

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class SetMockMediaPlaybackTargetPickerState {
public:
    using Arguments = std::tuple<String, WebCore::MediaPlaybackTargetContextMockState>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetMockMediaPlaybackTargetPickerState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetMockMediaPlaybackTargetPickerState(const String& name, WebCore::MediaPlaybackTargetContextMockState pickerState)
        : m_name(name)
        , m_pickerState(pickerState)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
        encoder << m_pickerState;
    }

private:
    const String& m_name;
    WebCore::MediaPlaybackTargetContextMockState m_pickerState;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class MockMediaPlaybackTargetPickerDismissPopup {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_MockMediaPlaybackTargetPickerDismissPopup; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    MockMediaPlaybackTargetPickerDismissPopup()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(VIDEO_PRESENTATION_MODE)
class SetMockVideoPresentationModeEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetMockVideoPresentationModeEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMockVideoPresentationModeEnabled(bool enabled)
        : m_enabled(enabled)
    {
        ASSERT(isInWebProcess());
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

#if ENABLE(POINTER_LOCK)
class RequestPointerLock {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestPointerLock; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_RequestPointerLockReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    RequestPointerLock()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(POINTER_LOCK)
class RequestPointerUnlock {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestPointerUnlock; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_RequestPointerUnlockReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    RequestPointerUnlock()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class ImageOrMediaDocumentSizeChanged {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ImageOrMediaDocumentSizeChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ImageOrMediaDocumentSizeChanged(const WebCore::IntSize& newSize)
        : m_newSize(newSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_newSize;
};

class UseFixedLayoutDidChange {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UseFixedLayoutDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UseFixedLayoutDidChange(bool useFixedLayout)
        : m_useFixedLayout(useFixedLayout)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_useFixedLayout;
    }

private:
    bool m_useFixedLayout;
};

class FixedLayoutSizeDidChange {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_FixedLayoutSizeDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FixedLayoutSizeDidChange(const WebCore::IntSize& fixedLayoutSize)
        : m_fixedLayoutSize(fixedLayoutSize)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fixedLayoutSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_fixedLayoutSize;
};

class DidRestoreScrollPosition {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidRestoreScrollPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidRestoreScrollPosition()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RequestScrollToRect {
public:
    using Arguments = std::tuple<WebCore::FloatRect, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestScrollToRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestScrollToRect(const WebCore::FloatRect& targetRect, const WebCore::FloatPoint& origin)
        : m_targetRect(targetRect)
        , m_origin(origin)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_targetRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_origin;
};

class GetLoadDecisionForIcon {
public:
    using Arguments = std::tuple<WebCore::LinkIcon, WebKit::CallbackID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_GetLoadDecisionForIcon; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GetLoadDecisionForIcon(const WebCore::LinkIcon& icon, const WebKit::CallbackID& callbackID)
        : m_icon(icon)
        , m_callbackID(callbackID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_icon;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_callbackID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LinkIcon& m_icon;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::CallbackID& m_callbackID;
};

class StartURLSchemeTask {
public:
    using Arguments = std::tuple<WebKit::URLSchemeTaskParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_StartURLSchemeTask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StartURLSchemeTask(const WebKit::URLSchemeTaskParameters& parameters)
        : m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::URLSchemeTaskParameters& m_parameters;
};

class StopURLSchemeTask {
public:
    using Arguments = std::tuple<WebKit::WebURLSchemeHandlerIdentifier, WebCore::ResourceLoaderIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_StopURLSchemeTask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopURLSchemeTask(const WebKit::WebURLSchemeHandlerIdentifier& handlerIdentifier, const WebCore::ResourceLoaderIdentifier& taskIdentifier)
        : m_handlerIdentifier(handlerIdentifier)
        , m_taskIdentifier(taskIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_handlerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_taskIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebURLSchemeHandlerIdentifier& m_handlerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_taskIdentifier;
};

class LoadSynchronousURLSchemeTask {
public:
    using Arguments = std::tuple<WebKit::URLSchemeTaskParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LoadSynchronousURLSchemeTask; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ResourceResponse, WebCore::ResourceError, Vector<uint8_t>>;
    using Reply = CompletionHandler<void(WebCore::ResourceResponse&&, WebCore::ResourceError&&, Vector<uint8_t>&&)>;
    explicit LoadSynchronousURLSchemeTask(const WebKit::URLSchemeTaskParameters& parameters)
        : m_parameters(parameters)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::URLSchemeTaskParameters& m_parameters;
};

#if ENABLE(DEVICE_ORIENTATION)
class ShouldAllowDeviceOrientationAndMotionAccess {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::FrameInfoData, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShouldAllowDeviceOrientationAndMotionAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ShouldAllowDeviceOrientationAndMotionAccessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DeviceOrientationOrMotionPermissionState>;
    using Reply = CompletionHandler<void(WebCore::DeviceOrientationOrMotionPermissionState)>;
    using Promise = WTF::NativePromise<WebCore::DeviceOrientationOrMotionPermissionState, IPC::Error>;
    ShouldAllowDeviceOrientationAndMotionAccess(const WebCore::FrameIdentifier& frameID, const WebKit::FrameInfoData& frameInfo, bool mayPrompt)
        : m_frameID(frameID)
        , m_frameInfo(frameInfo)
        , m_mayPrompt(mayPrompt)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameInfo;
        encoder << m_mayPrompt;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::FrameInfoData& m_frameInfo;
    bool m_mayPrompt;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class RegisterAttachmentIdentifierFromData {
public:
    using Arguments = std::tuple<String, String, String, IPC::SharedBufferReference>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RegisterAttachmentIdentifierFromData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterAttachmentIdentifierFromData(const String& identifier, const String& contentType, const String& preferredFileName, const IPC::SharedBufferReference& data)
        : m_identifier(identifier)
        , m_contentType(contentType)
        , m_preferredFileName(preferredFileName)
        , m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        encoder << m_contentType;
        encoder << m_preferredFileName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    const String& m_identifier;
    const String& m_contentType;
    const String& m_preferredFileName;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::SharedBufferReference& m_data;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class RegisterAttachmentIdentifierFromFilePath {
public:
    using Arguments = std::tuple<String, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RegisterAttachmentIdentifierFromFilePath; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterAttachmentIdentifierFromFilePath(const String& identifier, const String& contentType, const String& filePath)
        : m_identifier(identifier)
        , m_contentType(contentType)
        , m_filePath(filePath)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        encoder << m_contentType;
        encoder << m_filePath;
    }

private:
    const String& m_identifier;
    const String& m_contentType;
    const String& m_filePath;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class RegisterAttachmentIdentifier {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RegisterAttachmentIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterAttachmentIdentifier(const String& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
    }

private:
    const String& m_identifier;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class RegisterAttachmentsFromSerializedData {
public:
    using Arguments = std::tuple<Vector<WebCore::SerializedAttachmentData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RegisterAttachmentsFromSerializedData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterAttachmentsFromSerializedData(const Vector<WebCore::SerializedAttachmentData>& data)
        : m_data(data)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::SerializedAttachmentData>& m_data;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class CloneAttachmentData {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CloneAttachmentData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CloneAttachmentData(const String& fromIdentifier, const String& toIdentifier)
        : m_fromIdentifier(fromIdentifier)
        , m_toIdentifier(toIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_fromIdentifier;
        encoder << m_toIdentifier;
    }

private:
    const String& m_fromIdentifier;
    const String& m_toIdentifier;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class DidInsertAttachmentWithIdentifier {
public:
    using Arguments = std::tuple<String, String, WebCore::AttachmentAssociatedElementType>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidInsertAttachmentWithIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidInsertAttachmentWithIdentifier(const String& identifier, const String& source, WebCore::AttachmentAssociatedElementType associatedElementType)
        : m_identifier(identifier)
        , m_source(source)
        , m_associatedElementType(associatedElementType)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        encoder << m_source;
        encoder << m_associatedElementType;
    }

private:
    const String& m_identifier;
    const String& m_source;
    WebCore::AttachmentAssociatedElementType m_associatedElementType;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class DidRemoveAttachmentWithIdentifier {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidRemoveAttachmentWithIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidRemoveAttachmentWithIdentifier(const String& identifier)
        : m_identifier(identifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
    }

private:
    const String& m_identifier;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class SerializedAttachmentDataForIdentifiers {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SerializedAttachmentDataForIdentifiers; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::SerializedAttachmentData>>;
    using Reply = CompletionHandler<void(Vector<WebCore::SerializedAttachmentData>&&)>;
    explicit SerializedAttachmentDataForIdentifiers(const Vector<String>& identifiers)
        : m_identifiers(identifiers)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_identifiers;
};
#endif

#if (ENABLE(ATTACHMENT_ELEMENT) && PLATFORM(IOS_FAMILY))
class WritePromisedAttachmentToPasteboard {
public:
    using Arguments = std::tuple<WebCore::PromisedAttachmentInfo, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_WritePromisedAttachmentToPasteboard; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WritePromisedAttachmentToPasteboard(const WebCore::PromisedAttachmentInfo& info, const String& authorizationToken)
        : m_info(info)
        , m_authorizationToken(authorizationToken)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
        encoder << m_authorizationToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PromisedAttachmentInfo& m_info;
    const String& m_authorizationToken;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class RequestAttachmentIcon {
public:
    using Arguments = std::tuple<String, String, String, String, WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestAttachmentIcon; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestAttachmentIcon(const String& identifier, const String& contentType, const String& path, const String& title, const WebCore::FloatSize& size)
        : m_identifier(identifier)
        , m_contentType(contentType)
        , m_path(path)
        , m_title(title)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        encoder << m_contentType;
        encoder << m_path;
        encoder << m_title;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    const String& m_identifier;
    const String& m_contentType;
    const String& m_path;
    const String& m_title;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class SpeechSynthesisVoiceList {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpeechSynthesisVoiceList; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::WebSpeechSynthesisVoice>>;
    using Reply = CompletionHandler<void(Vector<WebKit::WebSpeechSynthesisVoice>&&)>;
    SpeechSynthesisVoiceList()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class SpeechSynthesisSpeak {
public:
    using Arguments = std::tuple<String, String, float, float, float, MonotonicTime, String, String, String, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpeechSynthesisSpeak; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_SpeechSynthesisSpeakReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SpeechSynthesisSpeak(const String& text, const String& lang, float volume, float rate, float pitch, const MonotonicTime& startTime, const String& voiceURI, const String& voiceName, const String& voiceLang, bool localService, bool defaultVoice)
        : m_text(text)
        , m_lang(lang)
        , m_volume(volume)
        , m_rate(rate)
        , m_pitch(pitch)
        , m_startTime(startTime)
        , m_voiceURI(voiceURI)
        , m_voiceName(voiceName)
        , m_voiceLang(voiceLang)
        , m_localService(localService)
        , m_defaultVoice(defaultVoice)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
        encoder << m_lang;
        encoder << m_volume;
        encoder << m_rate;
        encoder << m_pitch;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_startTime;
        encoder << m_voiceURI;
        encoder << m_voiceName;
        encoder << m_voiceLang;
        encoder << m_localService;
        encoder << m_defaultVoice;
    }

private:
    const String& m_text;
    const String& m_lang;
    float m_volume;
    float m_rate;
    float m_pitch;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_startTime;
    const String& m_voiceURI;
    const String& m_voiceName;
    const String& m_voiceLang;
    bool m_localService;
    bool m_defaultVoice;
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class SpeechSynthesisSetFinishedCallback {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpeechSynthesisSetFinishedCallback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_SpeechSynthesisSetFinishedCallbackReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SpeechSynthesisSetFinishedCallback()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class SpeechSynthesisCancel {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpeechSynthesisCancel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SpeechSynthesisCancel()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class SpeechSynthesisPause {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpeechSynthesisPause; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_SpeechSynthesisPauseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SpeechSynthesisPause()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class SpeechSynthesisResume {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpeechSynthesisResume; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_SpeechSynthesisResumeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SpeechSynthesisResume()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class SpeechSynthesisResetState {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SpeechSynthesisResetState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SpeechSynthesisResetState()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
class ShowPDFContextMenu {
public:
    using Arguments = std::tuple<WebKit::PDFContextMenu, WebKit::PDFPluginIdentifier, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowPDFContextMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ShowPDFContextMenuReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<int32_t>>;
    using Reply = CompletionHandler<void(std::optional<int32_t>&&)>;
    using Promise = WTF::NativePromise<std::optional<int32_t>, IPC::Error>;
    ShowPDFContextMenu(const WebKit::PDFContextMenu& contextMenu, const WebKit::PDFPluginIdentifier& identifier, const WebCore::FrameIdentifier& frameID)
        : m_contextMenu(contextMenu)
        , m_identifier(identifier)
        , m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contextMenu;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFContextMenu& m_contextMenu;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFPluginIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};
#endif

#if ENABLE(PDF_HUD)
class CreatePDFHUD {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier, WebCore::FrameIdentifier, WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CreatePDFHUD; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreatePDFHUD(const WebKit::PDFPluginIdentifier& identifier, const WebCore::FrameIdentifier& frameID, const WebCore::IntRect& boundingBox)
        : m_identifier(identifier)
        , m_frameID(frameID)
        , m_boundingBox(boundingBox)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_boundingBox;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFPluginIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_boundingBox;
};
#endif

#if ENABLE(PDF_HUD)
class UpdatePDFHUDLocation {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier, WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdatePDFHUDLocation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdatePDFHUDLocation(const WebKit::PDFPluginIdentifier& identifier, const WebCore::IntRect& boundingBox)
        : m_identifier(identifier)
        , m_boundingBox(boundingBox)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_boundingBox;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFPluginIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_boundingBox;
};
#endif

#if ENABLE(PDF_HUD)
class RemovePDFHUD {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RemovePDFHUD; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemovePDFHUD(const WebKit::PDFPluginIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFPluginIdentifier& m_identifier;
};
#endif

#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
class CreatePDFPageNumberIndicator {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier, WebCore::IntRect, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_CreatePDFPageNumberIndicator; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreatePDFPageNumberIndicator(const WebKit::PDFPluginIdentifier& identifier, const WebCore::IntRect& boundingBox, uint64_t pageCount)
        : m_identifier(identifier)
        , m_boundingBox(boundingBox)
        , m_pageCount(pageCount)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_boundingBox;
        encoder << m_pageCount;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFPluginIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_boundingBox;
    uint64_t m_pageCount;
};
#endif

#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
class UpdatePDFPageNumberIndicatorLocation {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier, WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdatePDFPageNumberIndicatorLocation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdatePDFPageNumberIndicatorLocation(const WebKit::PDFPluginIdentifier& identifier, const WebCore::IntRect& boundingBox)
        : m_identifier(identifier)
        , m_boundingBox(boundingBox)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_boundingBox;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFPluginIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_boundingBox;
};
#endif

#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
class UpdatePDFPageNumberIndicatorCurrentPage {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdatePDFPageNumberIndicatorCurrentPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdatePDFPageNumberIndicatorCurrentPage(const WebKit::PDFPluginIdentifier& identifier, uint64_t pageIndex)
        : m_identifier(identifier)
        , m_pageIndex(pageIndex)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_pageIndex;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFPluginIdentifier& m_identifier;
    uint64_t m_pageIndex;
};
#endif

#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
class RemovePDFPageNumberIndicator {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RemovePDFPageNumberIndicator; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemovePDFPageNumberIndicator(const WebKit::PDFPluginIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PDFPluginIdentifier& m_identifier;
};
#endif

class ConfigureLoggingChannel {
public:
    using Arguments = std::tuple<String, WTFLogChannelState, WTFLogLevel>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ConfigureLoggingChannel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ConfigureLoggingChannel(const String& channelName, WTFLogChannelState state, WTFLogLevel level)
        : m_channelName(channelName)
        , m_state(state)
        , m_level(level)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_channelName;
        encoder << m_state;
        encoder << m_level;
    }

private:
    const String& m_channelName;
    WTFLogChannelState m_state;
    WTFLogLevel m_level;
};

#if PLATFORM(GTK)
class ShowEmojiPicker {
public:
    using Arguments = std::tuple<WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ShowEmojiPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ShowEmojiPickerReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit ShowEmojiPicker(const WebCore::IntRect& caretRect)
        : m_caretRect(caretRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_caretRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_caretRect;
};
#endif

#if HAVE(VISIBILITY_PROPAGATION_VIEW)
class DidCreateContextInWebProcessForVisibilityPropagation {
public:
    using Arguments = std::tuple<WebKit::LayerHostingContextID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidCreateContextInWebProcessForVisibilityPropagation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidCreateContextInWebProcessForVisibilityPropagation(const WebKit::LayerHostingContextID& contextID)
        : m_contextID(contextID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contextID;
    }

private:
    const WebKit::LayerHostingContextID& m_contextID;
};
#endif

#if ENABLE(WEB_AUTHN)
class SetMockWebAuthenticationConfiguration {
public:
    using Arguments = std::tuple<WebCore::MockWebAuthenticationConfiguration>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetMockWebAuthenticationConfiguration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMockWebAuthenticationConfiguration(const WebCore::MockWebAuthenticationConfiguration& configuration)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MockWebAuthenticationConfiguration& m_configuration;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class SendMessageToWebView {
public:
    using Arguments = std::tuple<WebKit::UserMessage>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SendMessageToWebView; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendMessageToWebView(const WebKit::UserMessage& userMessage)
        : m_userMessage(userMessage)
    {
        ASSERT(isInWebProcess());
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
class SendMessageToWebViewWithReply {
public:
    using Arguments = std::tuple<WebKit::UserMessage>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SendMessageToWebViewWithReply; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_SendMessageToWebViewWithReplyReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::UserMessage>;
    using Reply = CompletionHandler<void(WebKit::UserMessage&&)>;
    using Promise = WTF::NativePromise<WebKit::UserMessage, IPC::Error>;
    explicit SendMessageToWebViewWithReply(const WebKit::UserMessage& userMessage)
        : m_userMessage(userMessage)
    {
        ASSERT(isInWebProcess());
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

class DidFindTextManipulationItems {
public:
    using Arguments = std::tuple<Vector<WebCore::TextManipulationItem>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidFindTextManipulationItems; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFindTextManipulationItems(const Vector<WebCore::TextManipulationItem>& items)
        : m_items(items)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_items;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::TextManipulationItem>& m_items;
};

#if ENABLE(MEDIA_USAGE)
class AddMediaUsageManagerSession {
public:
    using Arguments = std::tuple<WebCore::MediaSessionIdentifier, String, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_AddMediaUsageManagerSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddMediaUsageManagerSession(const WebCore::MediaSessionIdentifier& identifier, const String& bundleIdentifier, const URL& pageURL)
        : m_identifier(identifier)
        , m_bundleIdentifier(bundleIdentifier)
        , m_pageURL(pageURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_bundleIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaSessionIdentifier& m_identifier;
    const String& m_bundleIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_pageURL;
};
#endif

#if ENABLE(MEDIA_USAGE)
class UpdateMediaUsageManagerSessionState {
public:
    using Arguments = std::tuple<WebCore::MediaSessionIdentifier, WebCore::MediaUsageInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateMediaUsageManagerSessionState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateMediaUsageManagerSessionState(const WebCore::MediaSessionIdentifier& identifier, const WebCore::MediaUsageInfo& info)
        : m_identifier(identifier)
        , m_info(info)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_info;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaSessionIdentifier& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaUsageInfo& m_info;
};
#endif

#if ENABLE(MEDIA_USAGE)
class RemoveMediaUsageManagerSession {
public:
    using Arguments = std::tuple<WebCore::MediaSessionIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RemoveMediaUsageManagerSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveMediaUsageManagerSession(const WebCore::MediaSessionIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaSessionIdentifier& m_identifier;
};
#endif

class SetHasExecutedAppBoundBehaviorBeforeNavigation {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetHasExecutedAppBoundBehaviorBeforeNavigation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetHasExecutedAppBoundBehaviorBeforeNavigation()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(MAC)
class ChangeUniversalAccessZoomFocus {
public:
    using Arguments = std::tuple<WebCore::IntRect, WebCore::IntRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ChangeUniversalAccessZoomFocus; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ChangeUniversalAccessZoomFocus(const WebCore::IntRect& viewRect, const WebCore::IntRect& caretRect)
        : m_viewRect(viewRect)
        , m_caretRect(caretRect)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_viewRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_caretRect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_viewRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_caretRect;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
class TakeModelElementFullscreen {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_TakeModelElementFullscreen; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TakeModelElementFullscreen(const WebKit::ModelIdentifier& modelIdentifier)
        : m_modelIdentifier(modelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
class ModelElementSetInteractionEnabled {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementSetInteractionEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ModelElementSetInteractionEnabled(const WebKit::ModelIdentifier& modelIdentifier, bool isInteractionEnabled)
        : m_modelIdentifier(modelIdentifier)
        , m_isInteractionEnabled(isInteractionEnabled)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
        encoder << m_isInteractionEnabled;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
    bool m_isInteractionEnabled;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
class ModelElementCreateRemotePreview {
public:
    using Arguments = std::tuple<String, WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementCreateRemotePreview; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementCreateRemotePreviewReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::pair<String, uint32_t>, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<std::pair<String, uint32_t>, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::pair<String, uint32_t>, WebCore::ResourceError>, IPC::Error>;
    ModelElementCreateRemotePreview(const String& uuid, const WebCore::FloatSize& size)
        : m_uuid(uuid)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_uuid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    const String& m_uuid;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
class ModelElementLoadRemotePreview {
public:
    using Arguments = std::tuple<String, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementLoadRemotePreview; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementLoadRemotePreviewReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ResourceError>, IPC::Error>;
    ModelElementLoadRemotePreview(const String& uuid, const URL& url)
        : m_uuid(uuid)
        , m_url(url)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_uuid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    const String& m_uuid;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
class ModelElementDestroyRemotePreview {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementDestroyRemotePreview; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ModelElementDestroyRemotePreview(const String& uuid)
        : m_uuid(uuid)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_uuid;
    }

private:
    const String& m_uuid;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
class ModelElementSizeDidChange {
public:
    using Arguments = std::tuple<String, WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementSizeDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementSizeDidChangeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<MachSendRight, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<MachSendRight, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<MachSendRight, WebCore::ResourceError>, IPC::Error>;
    ModelElementSizeDidChange(const String& uuid, const WebCore::FloatSize& size)
        : m_uuid(uuid)
        , m_size(size)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_uuid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    const String& m_uuid;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
class HandleMouseDownForModelElement {
public:
    using Arguments = std::tuple<String, WebCore::LayoutPoint, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleMouseDownForModelElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleMouseDownForModelElement(const String& uuid, const WebCore::LayoutPoint& flippedLocationInElement, const MonotonicTime& timestamp)
        : m_uuid(uuid)
        , m_flippedLocationInElement(flippedLocationInElement)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_uuid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_flippedLocationInElement;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    const String& m_uuid;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LayoutPoint& m_flippedLocationInElement;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_timestamp;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
class HandleMouseMoveForModelElement {
public:
    using Arguments = std::tuple<String, WebCore::LayoutPoint, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleMouseMoveForModelElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleMouseMoveForModelElement(const String& uuid, const WebCore::LayoutPoint& flippedLocationInElement, const MonotonicTime& timestamp)
        : m_uuid(uuid)
        , m_flippedLocationInElement(flippedLocationInElement)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_uuid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_flippedLocationInElement;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    const String& m_uuid;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LayoutPoint& m_flippedLocationInElement;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_timestamp;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
class HandleMouseUpForModelElement {
public:
    using Arguments = std::tuple<String, WebCore::LayoutPoint, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HandleMouseUpForModelElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleMouseUpForModelElement(const String& uuid, const WebCore::LayoutPoint& flippedLocationInElement, const MonotonicTime& timestamp)
        : m_uuid(uuid)
        , m_flippedLocationInElement(flippedLocationInElement)
        , m_timestamp(timestamp)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_uuid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_flippedLocationInElement;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_timestamp;
    }

private:
    const String& m_uuid;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::LayoutPoint& m_flippedLocationInElement;
    SUPPRESS_FORWARD_DECL_MEMBER const MonotonicTime& m_timestamp;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
class ModelInlinePreviewUUIDs {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelInlinePreviewUUIDs; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelInlinePreviewUUIDsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<String>>;
    using Reply = CompletionHandler<void(Vector<String>&&)>;
    using Promise = WTF::NativePromise<Vector<String>, IPC::Error>;
    ModelInlinePreviewUUIDs()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementGetCamera {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementGetCamera; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementGetCameraReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebCore::HTMLModelElementCamera, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<WebCore::HTMLModelElementCamera, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<WebCore::HTMLModelElementCamera, WebCore::ResourceError>, IPC::Error>;
    explicit ModelElementGetCamera(const WebKit::ModelIdentifier& modelIdentifier)
        : m_modelIdentifier(modelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementSetCamera {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier, WebCore::HTMLModelElementCamera>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementSetCamera; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementSetCameraReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    ModelElementSetCamera(const WebKit::ModelIdentifier& modelIdentifier, const WebCore::HTMLModelElementCamera& camera)
        : m_modelIdentifier(modelIdentifier)
        , m_camera(camera)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_camera;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::HTMLModelElementCamera& m_camera;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementIsPlayingAnimation {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementIsPlayingAnimation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementIsPlayingAnimationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<bool, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebCore::ResourceError>, IPC::Error>;
    explicit ModelElementIsPlayingAnimation(const WebKit::ModelIdentifier& modelIdentifier)
        : m_modelIdentifier(modelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementSetAnimationIsPlaying {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementSetAnimationIsPlaying; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementSetAnimationIsPlayingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    ModelElementSetAnimationIsPlaying(const WebKit::ModelIdentifier& modelIdentifier, bool isPlaying)
        : m_modelIdentifier(modelIdentifier)
        , m_isPlaying(isPlaying)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
        encoder << m_isPlaying;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
    bool m_isPlaying;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementIsLoopingAnimation {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementIsLoopingAnimation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementIsLoopingAnimationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<bool, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebCore::ResourceError>, IPC::Error>;
    explicit ModelElementIsLoopingAnimation(const WebKit::ModelIdentifier& modelIdentifier)
        : m_modelIdentifier(modelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementSetIsLoopingAnimation {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementSetIsLoopingAnimation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementSetIsLoopingAnimationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    ModelElementSetIsLoopingAnimation(const WebKit::ModelIdentifier& modelIdentifier, bool isLooping)
        : m_modelIdentifier(modelIdentifier)
        , m_isLooping(isLooping)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
        encoder << m_isLooping;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
    bool m_isLooping;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementAnimationDuration {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementAnimationDuration; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementAnimationDurationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Seconds, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<Seconds, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<Seconds, WebCore::ResourceError>, IPC::Error>;
    explicit ModelElementAnimationDuration(const WebKit::ModelIdentifier& modelIdentifier)
        : m_modelIdentifier(modelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementAnimationCurrentTime {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementAnimationCurrentTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementAnimationCurrentTimeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Seconds, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<Seconds, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<Seconds, WebCore::ResourceError>, IPC::Error>;
    explicit ModelElementAnimationCurrentTime(const WebKit::ModelIdentifier& modelIdentifier)
        : m_modelIdentifier(modelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementSetAnimationCurrentTime {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier, Seconds>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementSetAnimationCurrentTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementSetAnimationCurrentTimeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    ModelElementSetAnimationCurrentTime(const WebKit::ModelIdentifier& modelIdentifier, const Seconds& currentTime)
        : m_modelIdentifier(modelIdentifier)
        , m_currentTime(currentTime)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_currentTime;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Seconds& m_currentTime;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementHasAudio {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementHasAudio; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementHasAudioReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<bool, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebCore::ResourceError>, IPC::Error>;
    explicit ModelElementHasAudio(const WebKit::ModelIdentifier& modelIdentifier)
        : m_modelIdentifier(modelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementIsMuted {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementIsMuted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementIsMutedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<bool, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<bool, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<bool, WebCore::ResourceError>, IPC::Error>;
    explicit ModelElementIsMuted(const WebKit::ModelIdentifier& modelIdentifier)
        : m_modelIdentifier(modelIdentifier)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW)
class ModelElementSetIsMuted {
public:
    using Arguments = std::tuple<WebKit::ModelIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_ModelElementSetIsMuted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_ModelElementSetIsMutedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    ModelElementSetIsMuted(const WebKit::ModelIdentifier& modelIdentifier, bool isMuted)
        : m_modelIdentifier(modelIdentifier)
        , m_isMuted(isMuted)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelIdentifier;
        encoder << m_isMuted;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ModelIdentifier& m_modelIdentifier;
    bool m_isMuted;
};
#endif

#if ENABLE(APPLE_PAY_AMS_UI)
class StartApplePayAMSUISession {
public:
    using Arguments = std::tuple<URL, WebCore::ApplePayAMSUIRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_StartApplePayAMSUISession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_StartApplePayAMSUISessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<bool>>;
    using Reply = CompletionHandler<void(std::optional<bool>&&)>;
    using Promise = WTF::NativePromise<std::optional<bool>, IPC::Error>;
    StartApplePayAMSUISession(const URL& originatingURL, const WebCore::ApplePayAMSUIRequest& request)
        : m_originatingURL(originatingURL)
        , m_request(request)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_originatingURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_originatingURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ApplePayAMSUIRequest& m_request;
};
#endif

#if ENABLE(APPLE_PAY_AMS_UI)
class AbortApplePayAMSUISession {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_AbortApplePayAMSUISession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AbortApplePayAMSUISession()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(SYSTEM_PREVIEW)
class BeginSystemPreview {
public:
    using Arguments = std::tuple<URL, WebCore::SecurityOriginData, WebCore::SystemPreviewInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BeginSystemPreview; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_BeginSystemPreviewReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    BeginSystemPreview(const URL& url, const WebCore::SecurityOriginData& topOrigin, const WebCore::SystemPreviewInfo& systemPreviewInfo)
        : m_url(url)
        , m_topOrigin(topOrigin)
        , m_systemPreviewInfo(systemPreviewInfo)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_topOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_systemPreviewInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_topOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SystemPreviewInfo& m_systemPreviewInfo;
};
#endif

class DidCreateSleepDisabler {
public:
    using Arguments = std::tuple<WebCore::SleepDisablerIdentifier, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidCreateSleepDisabler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCreateSleepDisabler(const WebCore::SleepDisablerIdentifier& identifier, const String& reason, bool display)
        : m_identifier(identifier)
        , m_reason(reason)
        , m_display(display)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_reason;
        encoder << m_display;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SleepDisablerIdentifier& m_identifier;
    const String& m_reason;
    bool m_display;
};

class DidDestroySleepDisabler {
public:
    using Arguments = std::tuple<WebCore::SleepDisablerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidDestroySleepDisabler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidDestroySleepDisabler(const WebCore::SleepDisablerIdentifier& identifier)
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
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SleepDisablerIdentifier& m_identifier;
};

class RequestCookieConsent {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RequestCookieConsent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_RequestCookieConsentReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::CookieConsentDecisionResult>;
    using Reply = CompletionHandler<void(WebCore::CookieConsentDecisionResult)>;
    using Promise = WTF::NativePromise<WebCore::CookieConsentDecisionResult, IPC::Error>;
    RequestCookieConsent()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(WINDOW_PROXY_PROPERTY_ACCESS_NOTIFICATION)
class DidAccessWindowProxyPropertyViaOpenerForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::SecurityOriginData, WebCore::WindowProxyProperty>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidAccessWindowProxyPropertyViaOpenerForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidAccessWindowProxyPropertyViaOpenerForFrame(const WebCore::FrameIdentifier& frameID, const WebCore::SecurityOriginData& openerOrigin, WebCore::WindowProxyProperty property)
        : m_frameID(frameID)
        , m_openerOrigin(openerOrigin)
        , m_property(property)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_openerOrigin;
        encoder << m_property;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_openerOrigin;
    WebCore::WindowProxyProperty m_property;
};
#endif

class DidApplyLinkDecorationFiltering {
public:
    using Arguments = std::tuple<URL, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidApplyLinkDecorationFiltering; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidApplyLinkDecorationFiltering(const URL& originalURL, const URL& adjustedURL)
        : m_originalURL(originalURL)
        , m_adjustedURL(adjustedURL)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_originalURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_adjustedURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_originalURL;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_adjustedURL;
};

class BroadcastProcessSyncData {
public:
    using Arguments = std::tuple<WebCore::ProcessSyncData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BroadcastProcessSyncData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit BroadcastProcessSyncData(const WebCore::ProcessSyncData& processSyncData)
        : m_processSyncData(processSyncData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processSyncData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessSyncData& m_processSyncData;
};

class BroadcastTopDocumentSyncData {
public:
    using Arguments = std::tuple<Ref<WebCore::DocumentSyncData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BroadcastTopDocumentSyncData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit BroadcastTopDocumentSyncData(const Ref<WebCore::DocumentSyncData>& documentSyncData)
        : m_documentSyncData(documentSyncData)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_documentSyncData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::DocumentSyncData>& m_documentSyncData;
};

class DispatchLoadEventToFrameOwnerElement {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DispatchLoadEventToFrameOwnerElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchLoadEventToFrameOwnerElement(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class FocusRemoteFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_FocusRemoteFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FocusRemoteFrame(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class PostMessageToRemote {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String, WebCore::FrameIdentifier, std::optional<WebCore::SecurityOriginData>, WebCore::MessageWithMessagePorts>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_PostMessageToRemote; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostMessageToRemote(const WebCore::FrameIdentifier& source, const String& sourceOrigin, const WebCore::FrameIdentifier& target, const std::optional<WebCore::SecurityOriginData>& targetOrigin, const WebCore::MessageWithMessagePorts& message)
        : m_source(source)
        , m_sourceOrigin(sourceOrigin)
        , m_target(target)
        , m_targetOrigin(targetOrigin)
        , m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_source;
        encoder << m_sourceOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_target;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_targetOrigin;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_source;
    const String& m_sourceOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_target;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::SecurityOriginData>& m_targetOrigin;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MessageWithMessagePorts& m_message;
};

class RenderTreeAsTextForTesting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, uint64_t, OptionSet<WebCore::RenderAsTextFlag>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_RenderTreeAsTextForTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    RenderTreeAsTextForTesting(const WebCore::FrameIdentifier& identifier, uint64_t baseIndent, const OptionSet<WebCore::RenderAsTextFlag>& behavior)
        : m_identifier(identifier)
        , m_baseIndent(baseIndent)
        , m_behavior(behavior)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_baseIndent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_behavior;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_identifier;
    uint64_t m_baseIndent;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::RenderAsTextFlag>& m_behavior;
};

class FrameTextForTesting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_FrameTextForTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    explicit FrameTextForTesting(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class LayerTreeAsTextForTesting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, uint64_t, OptionSet<WebCore::LayerTreeAsTextOptions>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_LayerTreeAsTextForTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    LayerTreeAsTextForTesting(const WebCore::FrameIdentifier& identifier, uint64_t baseIndent, const OptionSet<WebCore::LayerTreeAsTextOptions>& options)
        : m_identifier(identifier)
        , m_baseIndent(baseIndent)
        , m_options(options)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
        encoder << m_baseIndent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_identifier;
    uint64_t m_baseIndent;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::LayerTreeAsTextOptions>& m_options;
};

class AddMessageToConsoleForTesting {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_AddMessageToConsoleForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AddMessageToConsoleForTesting(const String& message)
        : m_message(message)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
    }

private:
    const String& m_message;
};

class BindRemoteAccessibilityFrames {
public:
    using Arguments = std::tuple<int, WebCore::FrameIdentifier, Vector<uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_BindRemoteAccessibilityFrames; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<uint8_t>, int>;
    using Reply = CompletionHandler<void(Vector<uint8_t>&&, int&&)>;
    BindRemoteAccessibilityFrames(const int& processIdentifier, const WebCore::FrameIdentifier& frameID, const Vector<uint8_t>& dataToken)
        : m_processIdentifier(processIdentifier)
        , m_frameID(frameID)
        , m_dataToken(dataToken)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dataToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint8_t>& m_dataToken;
};

class UpdateRemoteFrameAccessibilityOffset {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_UpdateRemoteFrameAccessibilityOffset; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateRemoteFrameAccessibilityOffset(const WebCore::FrameIdentifier& frameID, const WebCore::IntPoint& offset)
        : m_frameID(frameID)
        , m_offset(offset)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_offset;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_offset;
};

class DocumentURLForConsoleLog {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DocumentURLForConsoleLog; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPageProxy_DocumentURLForConsoleLogReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<URL>;
    using Reply = CompletionHandler<void(URL&&)>;
    using Promise = WTF::NativePromise<URL, IPC::Error>;
    explicit DocumentURLForConsoleLog(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class NowPlayingMetadataChanged {
public:
    using Arguments = std::tuple<WebCore::NowPlayingMetadata>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_NowPlayingMetadataChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit NowPlayingMetadataChanged(const WebCore::NowPlayingMetadata& metadata)
        : m_metadata(metadata)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_metadata;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NowPlayingMetadata& m_metadata;
};

class DidAdjustVisibilityWithSelectors {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_DidAdjustVisibilityWithSelectors; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidAdjustVisibilityWithSelectors(const Vector<String>& selectors)
        : m_selectors(selectors)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_selectors;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_selectors;
};

class FrameNameChanged {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_FrameNameChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FrameNameChanged(const WebCore::FrameIdentifier& frameID, const String& frameName)
        : m_frameID(frameID)
        , m_frameName(frameName)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_frameName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    const String& m_frameName;
};

#if ENABLE(GAMEPAD)
class GamepadsRecentlyAccessed {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_GamepadsRecentlyAccessed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GamepadsRecentlyAccessed()
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class HasActiveNowPlayingSessionChanged {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_HasActiveNowPlayingSessionChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HasActiveNowPlayingSessionChanged(bool hasActiveNowPlayingSessionChanged)
        : m_hasActiveNowPlayingSessionChanged(hasActiveNowPlayingSessionChanged)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasActiveNowPlayingSessionChanged;
    }

private:
    bool m_hasActiveNowPlayingSessionChanged;
};

class SetAllowsLayoutViewportHeightExpansion {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPageProxy_SetAllowsLayoutViewportHeightExpansion; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAllowsLayoutViewportHeightExpansion(bool newValue)
        : m_newValue(newValue)
    {
        ASSERT(isInWebProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_newValue;
    }

private:
    bool m_newValue;
};

} // namespace WebPageProxy
} // namespace Messages
