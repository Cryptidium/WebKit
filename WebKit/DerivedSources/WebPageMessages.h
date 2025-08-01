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
#include "DrawingAreaInfo.h"
#include "EditorState.h"
#include "FocusedElementInformation.h"
#if PLATFORM(IOS_FAMILY)
#include "GestureTypes.h"
#endif
#include "GoToBackForwardItemParameters.h"
#include "IdentifierTypes.h"
#include "ImageBufferBackendHandle.h"
#include "ImageOptions.h"
#include "LoadParameters.h"
#include "MessageNames.h"
#include "PageClient.h"
#include "SandboxExtension.h"
#include "SessionState.h"
#include "TransactionID.h"
#include "WebFindOptions.h"
#include <JavaScriptCore/InspectorFrontendChannel.h>
#include <WebCore/BackForwardItemIdentifier.h>
#include <WebCore/DictationContext.h>
#include <WebCore/DragActions.h>
#include <WebCore/DragData.h>
#include <WebCore/ElementContext.h>
#include <WebCore/ElementTargetingTypes.h>
#include <WebCore/FrameLoaderTypes.h>
#if PLATFORM(COCOA)
#include <WebCore/ImageUtilities.h>
#endif
#include <WebCore/IntDegrees.h>
#include <WebCore/JSDOMExceptionHandling.h>
#include <WebCore/MediaProducer.h>
#include <WebCore/PlatformEvent.h>
#include <WebCore/PlatformLayerIdentifier.h>
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
#include <WebCore/PlaybackTargetClientContextIdentifier.h>
#endif
#include <WebCore/PointerID.h>
#include <WebCore/ProcessQualified.h>
#include <WebCore/RectEdges.h>
#include <WebCore/RenderTreeAsText.h>
#include <WebCore/ScriptExecutionContextIdentifier.h>
#include <WebCore/ScrollingCoordinatorTypes.h>
#include <WebCore/ScrollingNodeID.h>
#include <WebCore/ShareableBitmapHandle.h>
#include <WebCore/SharedMemory.h>
#include <WebCore/TextCheckerClient.h>
#include <WebCore/TextExtractionTypes.h>
#include <WebCore/WritingToolsTypes.h>
#include <optional>
#include <span>
#include <utility>
#include <wtf/Expected.h>
#include <wtf/Forward.h>
#include <wtf/HashMap.h>
#include <wtf/MachSendRight.h>
#include <wtf/ObjectIdentifier.h>
#include <wtf/OptionSet.h>
#include <wtf/Ref.h>
#include <wtf/RefCounted.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class FormDataReference;
class SharedBufferReference;
}

namespace JSC {
enum class MessageLevel : uint8_t;
enum class MessageSource : uint8_t;
}

namespace WTF {
class UUID;
}

namespace WebCore {
class CaptureDevice;
class Color;
class DragData;
class FloatPoint;
class FloatRect;
class FloatSize;
class FontAttributeChanges;
class FontChanges;
struct FrameIdentifierType;
using FrameIdentifier = ObjectIdentifier<FrameIdentifierType>;
class IntPoint;
class IntRect;
class IntSize;
struct LayerHostingContextIdentifierType;
using LayerHostingContextIdentifier = ObjectIdentifier<LayerHostingContextIdentifierType>;
struct MediaKeySystemRequestIdentifierType;
using MediaKeySystemRequestIdentifier = ObjectIdentifier<MediaKeySystemRequestIdentifierType>;
struct NavigationIdentifierType;
using NavigationIdentifier = ObjectIdentifier<NavigationIdentifierType>;
struct NodeIdentifierType;
using NodeIdentifier = ObjectIdentifier<NodeIdentifierType>;
class ResourceError;
struct ResourceLoaderIdentifierType;
using ResourceLoaderIdentifier = AtomicObjectIdentifier<ResourceLoaderIdentifierType>;
class ResourceRequest;
class ResourceResponse;
class SecurityOriginData;
class SelectionData;
struct SnapshotIdentifierType;
using SnapshotIdentifier = AtomicObjectIdentifier<SnapshotIdentifierType>;
class TransformationMatrix;
struct UserMediaRequestIdentifierType;
using UserMediaRequestIdentifier = ObjectIdentifier<UserMediaRequestIdentifierType>;
enum class CreateNewGroupForHighlight : bool;
enum class EventMakesGamepadsVisible : bool;
enum class HighlightRequestOriginatedInApp : bool;
enum class HighlightVisibility : bool;
enum class ScrollIsAnimated : bool;
enum class CaretAnimatorType : uint8_t;
enum class DragHandlingMethod : uint8_t;
enum class DragOperation : uint8_t;
enum class MediaConstraintType : uint8_t;
enum class MediaProducerMediaCaptureKind : uint8_t;
enum class PaginationMode : uint8_t;
enum class ScheduleLocationChangeResult : uint8_t;
enum class ScrollDirection : uint8_t;
enum class ScrollGranularity : uint8_t;
enum class ScrollPinningBehavior : uint8_t;
enum class ScrollbarMode : uint8_t;
enum class ScrollbarOverlayStyle : uint8_t;
enum class SelectionDirection : uint8_t;
enum class TextGranularity : uint8_t;
enum class ViolationReportType : uint8_t;
enum class WheelScrollGestureState : uint8_t;
enum class WritingDirection : uint8_t;
struct AXDebugInfo;
struct AppHighlight;
struct ApplicationManifest;
struct AttributedString;
struct CharacterRange;
struct DictionaryPopupInfo;
struct ElementContext;
struct FontAttributes;
struct Headroom;
struct MediaDeviceHashSalts;
struct MessageWithMessagePorts;
struct NowPlayingInfo;
struct ProcessSyncData;
struct RemoteUserInputEventData;
struct SecurityPolicyViolationEventInit;
struct SystemPreviewInfo;
struct TargetedElementRequest;
struct TextCheckingResult;
struct TextIndicatorData;
struct TextManipulationControllerManipulationResult;
struct TextRecognitionResult;
struct ViewportArguments;
}

namespace WebKit {
class CallbackID;
struct GeolocationIdentifierType;
using GeolocationIdentifier = ObjectIdentifier<GeolocationIdentifierType>;
class MediaPlaybackTargetContextSerialized;
struct PDFPluginIdentifierType;
using PDFPluginIdentifier = ObjectIdentifier<PDFPluginIdentifierType>;
class RevealItem;
struct TapIdentifierType;
using TapIdentifier = ObjectIdentifier<TapIdentifierType>;
class UserData;
class WebContextMenuItemData;
class WebKeyboardEvent;
class WebMouseEvent;
struct WebPageProxyIdentifierType;
using WebPageProxyIdentifier = ObjectIdentifier<WebPageProxyIdentifierType>;
class WebTouchEvent;
struct WebURLSchemeHandlerIdentifierType;
using WebURLSchemeHandlerIdentifier = ObjectIdentifier<WebURLSchemeHandlerIdentifierType>;
class WebWheelEvent;
enum class ContentAsStringIncludesChildFrames : bool;
enum class RespectSelectionAnchor : bool;
enum class DragControllerAction : uint8_t;
enum class FindDecorationStyle : uint8_t;
enum class GestureRecognizerState : uint8_t;
enum class GestureType : uint8_t;
enum class MediaPlaybackState : uint8_t;
enum class SelectionTouch : uint8_t;
enum class SyntheticEditingCommandType : uint8_t;
enum class TextInteractionSource : uint8_t;
enum class TextRecognitionUpdateResult : uint8_t;
enum class WebEventType : uint8_t;
struct ContentWorldData;
struct CoreIPCAuditToken;
struct DataDetectionResult;
struct DocumentEditingContext;
struct DocumentEditingContextRequest;
struct DragInitiationResult;
struct DynamicViewportSizeUpdate;
struct EditingRange;
struct FrameInfoData;
struct FrameTreeNodeData;
struct HardwareKeyboardState;
struct InsertTextOptions;
struct InteractionInformationRequest;
struct PrintInfo;
struct RunJavaScriptParameters;
struct UserMessage;
struct ViewWindowCoordinates;
struct WebAutocorrectionData;
struct WebFoundTextRange;
struct WebHitTestResultData;
struct WebPreferencesStore;
struct WebsitePoliciesData;
}

namespace Messages {
namespace WebPage {

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
    return IPC::ReceiverName::WebPage;
}

class SetInitialFocus {
public:
    using Arguments = std::tuple<bool, bool, std::optional<WebKit::WebKeyboardEvent>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetInitialFocus; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SetInitialFocusReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetInitialFocus(bool forward, bool isKeyboardEventValid, const std::optional<WebKit::WebKeyboardEvent>& event)
        : m_forward(forward)
        , m_isKeyboardEventValid(isKeyboardEventValid)
        , m_event(event)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_forward;
        encoder << m_isKeyboardEventValid;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    bool m_forward;
    bool m_isKeyboardEventValid;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::WebKeyboardEvent>& m_event;
};

class SetActivityState {
public:
    using Arguments = std::tuple<OptionSet<WebCore::ActivityState>, WebKit::ActivityStateChangeID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetActivityState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SetActivityStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SetActivityState(const OptionSet<WebCore::ActivityState>& activityState, const WebKit::ActivityStateChangeID& activityStateChangeID)
        : m_activityState(activityState)
        , m_activityStateChangeID(activityStateChangeID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_activityState;
        encoder << m_activityStateChangeID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::ActivityState>& m_activityState;
    const WebKit::ActivityStateChangeID& m_activityStateChangeID;
};

class SetBackgroundColor {
public:
    using Arguments = std::tuple<std::optional<WebCore::Color>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetBackgroundColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetBackgroundColor(const std::optional<WebCore::Color>& color)
        : m_color(color)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::Color>& m_color;
};

class AddConsoleMessage {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, JSC::MessageSource, JSC::MessageLevel, String, std::optional<WebCore::ResourceLoaderIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AddConsoleMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddConsoleMessage(const WebCore::FrameIdentifier& frameID, JSC::MessageSource messageSource, JSC::MessageLevel messageLevel, const String& message, const std::optional<WebCore::ResourceLoaderIdentifier>& requestID)
        : m_frameID(frameID)
        , m_messageSource(messageSource)
        , m_messageLevel(messageLevel)
        , m_message(message)
        , m_requestID(requestID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_messageSource;
        encoder << m_messageLevel;
        encoder << m_message;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    JSC::MessageSource m_messageSource;
    JSC::MessageLevel m_messageLevel;
    const String& m_message;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ResourceLoaderIdentifier>& m_requestID;
};

class EnqueueSecurityPolicyViolationEvent {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::SecurityPolicyViolationEventInit>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_EnqueueSecurityPolicyViolationEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnqueueSecurityPolicyViolationEvent(const WebCore::FrameIdentifier& frameID, const WebCore::SecurityPolicyViolationEventInit& eventInit)
        : m_frameID(frameID)
        , m_eventInit(eventInit)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_eventInit;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityPolicyViolationEventInit& m_eventInit;
};

class SendReportToEndpoints {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, URL, Vector<String>, Vector<String>, IPC::FormDataReference, WebCore::ViolationReportType>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SendReportToEndpoints; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SendReportToEndpoints(const WebCore::FrameIdentifier& frameID, const URL& baseURL, const Vector<String>& endpointURIs, const Vector<String>& endpointTokens, const IPC::FormDataReference& reportData, WebCore::ViolationReportType reportType)
        : m_frameID(frameID)
        , m_baseURL(baseURL)
        , m_endpointURIs(endpointURIs)
        , m_endpointTokens(endpointTokens)
        , m_reportData(reportData)
        , m_reportType(reportType)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_baseURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_endpointURIs;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_endpointTokens;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_reportData;
        encoder << m_reportType;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_baseURL;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_endpointURIs;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_endpointTokens;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::FormDataReference& m_reportData;
    WebCore::ViolationReportType m_reportType;
};

class NotifyReportObservers {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, Ref<WebCore::Report>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_NotifyReportObservers; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NotifyReportObservers(const WebCore::FrameIdentifier& frameID, const Ref<WebCore::Report>& report)
        : m_frameID(frameID)
        , m_report(report)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_report;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::Report>& m_report;
};

class TestProcessIncomingSyncMessagesWhenWaitingForSyncReply {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    TestProcessIncomingSyncMessagesWhenWaitingForSyncReply()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(COCOA)
class SetObscuredContentInsetsFenced {
public:
    using Arguments = std::tuple<WebCore::FloatBoxExtent, MachSendRight>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetObscuredContentInsetsFenced; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetObscuredContentInsetsFenced(const WebCore::FloatBoxExtent& obscuredContentInsets, MachSendRight&& machSendRight)
        : m_obscuredContentInsets(obscuredContentInsets)
        , m_machSendRight(WTFMove(machSendRight))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_obscuredContentInsets;
        encoder << WTFMove(m_machSendRight);
    }

private:
    const WebCore::FloatBoxExtent& m_obscuredContentInsets;
    MachSendRight&& m_machSendRight;
};
#endif

#if !PLATFORM(COCOA)
class SetObscuredContentInsets {
public:
    using Arguments = std::tuple<WebCore::FloatBoxExtent>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetObscuredContentInsets; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetObscuredContentInsets(const WebCore::FloatBoxExtent& obscuredContentInsets)
        : m_obscuredContentInsets(obscuredContentInsets)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_obscuredContentInsets;
    }

private:
    const WebCore::FloatBoxExtent& m_obscuredContentInsets;
};
#endif

class SetShouldSuppressHDR {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetShouldSuppressHDR; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = true;

    explicit SetShouldSuppressHDR(bool shouldSuppressHDR)
        : m_shouldSuppressHDR(shouldSuppressHDR)
    {
    }

    void encodeCoalescingKey(IPC::Encoder&) const
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldSuppressHDR;
    }

private:
    bool m_shouldSuppressHDR;
};

class SetUnderlayColor {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetUnderlayColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUnderlayColor(const WebCore::Color& color)
        : m_color(color)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

class SetUnderPageBackgroundColorOverride {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetUnderPageBackgroundColorOverride; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUnderPageBackgroundColorOverride(const WebCore::Color& underPageBackgroundColorOverride)
        : m_underPageBackgroundColorOverride(underPageBackgroundColorOverride)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_underPageBackgroundColorOverride;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_underPageBackgroundColorOverride;
};

class SetNeedsFixedContainerEdgesUpdate {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetNeedsFixedContainerEdgesUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetNeedsFixedContainerEdgesUpdate()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ViewWillStartLiveResize {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ViewWillStartLiveResize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ViewWillStartLiveResize()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ViewWillEndLiveResize {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ViewWillEndLiveResize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ViewWillEndLiveResize()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ExecuteEditCommandWithCallback {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ExecuteEditCommandWithCallback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ExecuteEditCommandWithCallbackReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ExecuteEditCommandWithCallback(const String& name, const String& argument)
        : m_name(name)
        , m_argument(argument)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
        encoder << m_argument;
    }

private:
    const String& m_name;
    const String& m_argument;
};

class KeyEvent {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::WebKeyboardEvent>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_KeyEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    KeyEvent(const WebCore::FrameIdentifier& frameID, const WebKit::WebKeyboardEvent& event)
        : m_frameID(frameID)
        , m_event(event)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebKeyboardEvent& m_event;
};

class MouseEvent {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::WebMouseEvent, std::optional<Vector<WebKit::SandboxExtensionHandle>>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_MouseEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    MouseEvent(const WebCore::FrameIdentifier& frameID, const WebKit::WebMouseEvent& event, std::optional<Vector<WebKit::SandboxExtensionHandle>>&& sandboxExtensions)
        : m_frameID(frameID)
        , m_event(event)
        , m_sandboxExtensions(WTFMove(sandboxExtensions))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
        encoder << WTFMove(m_sandboxExtensions);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebMouseEvent& m_event;
    std::optional<Vector<WebKit::SandboxExtensionHandle>>&& m_sandboxExtensions;
};

class SetLastKnownMousePosition {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::IntPoint, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetLastKnownMousePosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetLastKnownMousePosition(const WebCore::FrameIdentifier& frameID, const WebCore::IntPoint& eventPoint, const WebCore::IntPoint& globalPoint)
        : m_frameID(frameID)
        , m_eventPoint(eventPoint)
        , m_globalPoint(globalPoint)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_eventPoint;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_globalPoint;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_eventPoint;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_globalPoint;
};

#if PLATFORM(IOS_FAMILY)
class SetSceneIdentifier {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetSceneIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSceneIdentifier(const String& sceneIdentifier)
        : m_sceneIdentifier(sceneIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sceneIdentifier;
    }

private:
    const String& m_sceneIdentifier;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetViewportConfigurationViewLayoutSize {
public:
    using Arguments = std::tuple<WebCore::FloatSize, double, double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetViewportConfigurationViewLayoutSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetViewportConfigurationViewLayoutSize(const WebCore::FloatSize& size, double scaleFactor, double minimumEffectiveDeviceWidth)
        : m_size(size)
        , m_scaleFactor(scaleFactor)
        , m_minimumEffectiveDeviceWidth(minimumEffectiveDeviceWidth)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
        encoder << m_scaleFactor;
        encoder << m_minimumEffectiveDeviceWidth;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
    double m_scaleFactor;
    double m_minimumEffectiveDeviceWidth;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetDeviceOrientation {
public:
    using Arguments = std::tuple<WebCore::IntDegrees>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetDeviceOrientation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDeviceOrientation(const WebCore::IntDegrees& deviceOrientation)
        : m_deviceOrientation(deviceOrientation)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_deviceOrientation;
    }

private:
    const WebCore::IntDegrees& m_deviceOrientation;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetOverrideViewportArguments {
public:
    using Arguments = std::tuple<std::optional<WebCore::ViewportArguments>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetOverrideViewportArguments; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetOverrideViewportArguments(const std::optional<WebCore::ViewportArguments>& arguments)
        : m_arguments(arguments)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_arguments;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ViewportArguments>& m_arguments;
};
#endif

#if PLATFORM(IOS_FAMILY)
class DynamicViewportSizeUpdate {
public:
    using Arguments = std::tuple<WebKit::DynamicViewportSizeUpdate>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DynamicViewportSizeUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DynamicViewportSizeUpdate(const WebKit::DynamicViewportSizeUpdate& target)
        : m_target(target)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_target;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DynamicViewportSizeUpdate& m_target;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetScreenIsBeingCaptured {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetScreenIsBeingCaptured; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetScreenIsBeingCaptured(bool captured)
        : m_captured(captured)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_captured;
    }

private:
    bool m_captured;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetInsertionPointColor {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetInsertionPointColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetInsertionPointColor(const WebCore::Color& color)
        : m_color(color)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};
#endif

#if PLATFORM(IOS_FAMILY)
class AttemptSyntheticClick {
public:
    using Arguments = std::tuple<WebCore::IntPoint, OptionSet<WebKit::WebEventModifier>, WebKit::TransactionID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AttemptSyntheticClick; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AttemptSyntheticClick(const WebCore::IntPoint& point, const OptionSet<WebKit::WebEventModifier>& modifiers, const WebKit::TransactionID& lastLayerTreeTransactionId)
        : m_point(point)
        , m_modifiers(modifiers)
        , m_lastLayerTreeTransactionId(lastLayerTreeTransactionId)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiers;
        encoder << m_lastLayerTreeTransactionId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebEventModifier>& m_modifiers;
    const WebKit::TransactionID& m_lastLayerTreeTransactionId;
};
#endif

#if PLATFORM(IOS_FAMILY)
class PotentialTapAtPosition {
public:
    using Arguments = std::tuple<std::optional<WebCore::FrameIdentifier>, WebKit::TapIdentifier, WebCore::FloatPoint, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PotentialTapAtPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PotentialTapAtPositionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::RemoteUserInputEventData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::RemoteUserInputEventData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::RemoteUserInputEventData>, IPC::Error>;
    PotentialTapAtPosition(const std::optional<WebCore::FrameIdentifier>& frameID, const WebKit::TapIdentifier& requestID, const WebCore::FloatPoint& point, bool shouldRequestMagnificationInformation)
        : m_frameID(frameID)
        , m_requestID(requestID)
        , m_point(point)
        , m_shouldRequestMagnificationInformation(shouldRequestMagnificationInformation)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_shouldRequestMagnificationInformation;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::TapIdentifier& m_requestID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point;
    bool m_shouldRequestMagnificationInformation;
};
#endif

#if PLATFORM(IOS_FAMILY)
class CommitPotentialTap {
public:
    using Arguments = std::tuple<std::optional<WebCore::FrameIdentifier>, OptionSet<WebKit::WebEventModifier>, WebKit::TransactionID, WebCore::PointerID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CommitPotentialTap; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CommitPotentialTapReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::FrameIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::FrameIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::FrameIdentifier>, IPC::Error>;
    CommitPotentialTap(const std::optional<WebCore::FrameIdentifier>& frameID, const OptionSet<WebKit::WebEventModifier>& modifiers, const WebKit::TransactionID& lastLayerTreeTransactionId, const WebCore::PointerID& pointerId)
        : m_frameID(frameID)
        , m_modifiers(modifiers)
        , m_lastLayerTreeTransactionId(lastLayerTreeTransactionId)
        , m_pointerId(pointerId)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiers;
        encoder << m_lastLayerTreeTransactionId;
        encoder << m_pointerId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebEventModifier>& m_modifiers;
    const WebKit::TransactionID& m_lastLayerTreeTransactionId;
    const WebCore::PointerID& m_pointerId;
};
#endif

#if PLATFORM(IOS_FAMILY)
class CancelPotentialTap {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CancelPotentialTap; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelPotentialTap()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class TapHighlightAtPosition {
public:
    using Arguments = std::tuple<WebKit::TapIdentifier, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TapHighlightAtPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TapHighlightAtPosition(const WebKit::TapIdentifier& requestID, const WebCore::FloatPoint& point)
        : m_requestID(requestID)
        , m_point(point)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::TapIdentifier& m_requestID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point;
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidRecognizeLongPress {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidRecognizeLongPress; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidRecognizeLongPress()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class HandleDoubleTapForDoubleClickAtPoint {
public:
    using Arguments = std::tuple<WebCore::IntPoint, OptionSet<WebKit::WebEventModifier>, WebKit::TransactionID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HandleDoubleTapForDoubleClickAtPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleDoubleTapForDoubleClickAtPoint(const WebCore::IntPoint& point, const OptionSet<WebKit::WebEventModifier>& modifiers, const WebKit::TransactionID& lastLayerTreeTransactionId)
        : m_point(point)
        , m_modifiers(modifiers)
        , m_lastLayerTreeTransactionId(lastLayerTreeTransactionId)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiers;
        encoder << m_lastLayerTreeTransactionId;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebEventModifier>& m_modifiers;
    const WebKit::TransactionID& m_lastLayerTreeTransactionId;
};
#endif

#if PLATFORM(IOS_FAMILY)
class InspectorNodeSearchMovedToPosition {
public:
    using Arguments = std::tuple<WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_InspectorNodeSearchMovedToPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit InspectorNodeSearchMovedToPosition(const WebCore::FloatPoint& point)
        : m_point(point)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point;
};
#endif

#if PLATFORM(IOS_FAMILY)
class InspectorNodeSearchEndedAtPosition {
public:
    using Arguments = std::tuple<WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_InspectorNodeSearchEndedAtPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit InspectorNodeSearchEndedAtPosition(const WebCore::FloatPoint& point)
        : m_point(point)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point;
};
#endif

#if PLATFORM(IOS_FAMILY)
class BlurFocusedElement {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_BlurFocusedElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BlurFocusedElement()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class SelectWithGesture {
public:
    using Arguments = std::tuple<WebCore::IntPoint, WebKit::GestureType, WebKit::GestureRecognizerState, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SelectWithGesture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SelectWithGestureReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntPoint, WebKit::GestureType, WebKit::GestureRecognizerState, OptionSet<WebKit::SelectionFlags>>;
    using Reply = CompletionHandler<void(WebCore::IntPoint&&, WebKit::GestureType, WebKit::GestureRecognizerState, OptionSet<WebKit::SelectionFlags>&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebCore::IntPoint, WebKit::GestureType, WebKit::GestureRecognizerState, OptionSet<WebKit::SelectionFlags>>, IPC::Error>;
    SelectWithGesture(const WebCore::IntPoint& point, WebKit::GestureType gestureType, WebKit::GestureRecognizerState gestureState, bool isInteractingWithFocusedElement)
        : m_point(point)
        , m_gestureType(gestureType)
        , m_gestureState(gestureState)
        , m_isInteractingWithFocusedElement(isInteractingWithFocusedElement)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_gestureType;
        encoder << m_gestureState;
        encoder << m_isInteractingWithFocusedElement;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    WebKit::GestureType m_gestureType;
    WebKit::GestureRecognizerState m_gestureState;
    bool m_isInteractingWithFocusedElement;
};
#endif

#if PLATFORM(IOS_FAMILY)
class UpdateSelectionWithTouches {
public:
    using Arguments = std::tuple<WebCore::IntPoint, WebKit::SelectionTouch, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateSelectionWithTouches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateSelectionWithTouchesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntPoint, WebKit::SelectionTouch, OptionSet<WebKit::SelectionFlags>>;
    using Reply = CompletionHandler<void(WebCore::IntPoint&&, WebKit::SelectionTouch, OptionSet<WebKit::SelectionFlags>&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebCore::IntPoint, WebKit::SelectionTouch, OptionSet<WebKit::SelectionFlags>>, IPC::Error>;
    UpdateSelectionWithTouches(const WebCore::IntPoint& point, WebKit::SelectionTouch touches, bool baseIsStart)
        : m_point(point)
        , m_touches(touches)
        , m_baseIsStart(baseIsStart)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_touches;
        encoder << m_baseIsStart;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    WebKit::SelectionTouch m_touches;
    bool m_baseIsStart;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SelectWithTwoTouches {
public:
    using Arguments = std::tuple<WebCore::IntPoint, WebCore::IntPoint, WebKit::GestureType, WebKit::GestureRecognizerState>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SelectWithTwoTouches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SelectWithTwoTouchesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntPoint, WebKit::GestureType, WebKit::GestureRecognizerState, OptionSet<WebKit::SelectionFlags>>;
    using Reply = CompletionHandler<void(WebCore::IntPoint&&, WebKit::GestureType, WebKit::GestureRecognizerState, OptionSet<WebKit::SelectionFlags>&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebCore::IntPoint, WebKit::GestureType, WebKit::GestureRecognizerState, OptionSet<WebKit::SelectionFlags>>, IPC::Error>;
    SelectWithTwoTouches(const WebCore::IntPoint& from, const WebCore::IntPoint& to, WebKit::GestureType gestureType, WebKit::GestureRecognizerState gestureState)
        : m_from(from)
        , m_to(to)
        , m_gestureType(gestureType)
        , m_gestureState(gestureState)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_from;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_to;
        encoder << m_gestureType;
        encoder << m_gestureState;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_from;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_to;
    WebKit::GestureType m_gestureType;
    WebKit::GestureRecognizerState m_gestureState;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ExtendSelection {
public:
    using Arguments = std::tuple<WebCore::TextGranularity>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ExtendSelection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ExtendSelectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit ExtendSelection(WebCore::TextGranularity granularity)
        : m_granularity(granularity)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_granularity;
    }

private:
    WebCore::TextGranularity m_granularity;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SelectWordBackward {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SelectWordBackward; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SelectWordBackward()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class ExtendSelectionForReplacement {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ExtendSelectionForReplacement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ExtendSelectionForReplacementReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ExtendSelectionForReplacement()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class MoveSelectionByOffset {
public:
    using Arguments = std::tuple<int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_MoveSelectionByOffset; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_MoveSelectionByOffsetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit MoveSelectionByOffset(int32_t offset)
        : m_offset(offset)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_offset;
    }

private:
    int32_t m_offset;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SelectTextWithGranularityAtPoint {
public:
    using Arguments = std::tuple<WebCore::IntPoint, WebCore::TextGranularity, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SelectTextWithGranularityAtPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SelectTextWithGranularityAtPointReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SelectTextWithGranularityAtPoint(const WebCore::IntPoint& point, WebCore::TextGranularity granularity, bool isInteractingWithFocusedElement)
        : m_point(point)
        , m_granularity(granularity)
        , m_isInteractingWithFocusedElement(isInteractingWithFocusedElement)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_granularity;
        encoder << m_isInteractingWithFocusedElement;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    WebCore::TextGranularity m_granularity;
    bool m_isInteractingWithFocusedElement;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SelectPositionAtBoundaryWithDirection {
public:
    using Arguments = std::tuple<WebCore::IntPoint, WebCore::TextGranularity, WebCore::SelectionDirection, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SelectPositionAtBoundaryWithDirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SelectPositionAtBoundaryWithDirectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SelectPositionAtBoundaryWithDirection(const WebCore::IntPoint& point, WebCore::TextGranularity granularity, WebCore::SelectionDirection direction, bool isInteractingWithFocusedElement)
        : m_point(point)
        , m_granularity(granularity)
        , m_direction(direction)
        , m_isInteractingWithFocusedElement(isInteractingWithFocusedElement)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_granularity;
        encoder << m_direction;
        encoder << m_isInteractingWithFocusedElement;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    WebCore::TextGranularity m_granularity;
    WebCore::SelectionDirection m_direction;
    bool m_isInteractingWithFocusedElement;
};
#endif

#if PLATFORM(IOS_FAMILY)
class MoveSelectionAtBoundaryWithDirection {
public:
    using Arguments = std::tuple<WebCore::TextGranularity, WebCore::SelectionDirection>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_MoveSelectionAtBoundaryWithDirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_MoveSelectionAtBoundaryWithDirectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    MoveSelectionAtBoundaryWithDirection(WebCore::TextGranularity granularity, WebCore::SelectionDirection direction)
        : m_granularity(granularity)
        , m_direction(direction)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_granularity;
        encoder << m_direction;
    }

private:
    WebCore::TextGranularity m_granularity;
    WebCore::SelectionDirection m_direction;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SelectPositionAtPoint {
public:
    using Arguments = std::tuple<WebCore::IntPoint, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SelectPositionAtPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SelectPositionAtPointReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SelectPositionAtPoint(const WebCore::IntPoint& point, bool isInteractingWithFocusedElement)
        : m_point(point)
        , m_isInteractingWithFocusedElement(isInteractingWithFocusedElement)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_isInteractingWithFocusedElement;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    bool m_isInteractingWithFocusedElement;
};
#endif

#if PLATFORM(IOS_FAMILY)
class BeginSelectionInDirection {
public:
    using Arguments = std::tuple<WebCore::SelectionDirection>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_BeginSelectionInDirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_BeginSelectionInDirectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit BeginSelectionInDirection(WebCore::SelectionDirection direction)
        : m_direction(direction)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_direction;
    }

private:
    WebCore::SelectionDirection m_direction;
};
#endif

#if PLATFORM(IOS_FAMILY)
class UpdateSelectionWithExtentPoint {
public:
    using Arguments = std::tuple<WebCore::IntPoint, bool, WebKit::RespectSelectionAnchor>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateSelectionWithExtentPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateSelectionWithExtentPointReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    UpdateSelectionWithExtentPoint(const WebCore::IntPoint& point, bool isInteractingWithFocusedElement, WebKit::RespectSelectionAnchor respectSelectionAnchor)
        : m_point(point)
        , m_isInteractingWithFocusedElement(isInteractingWithFocusedElement)
        , m_respectSelectionAnchor(respectSelectionAnchor)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_isInteractingWithFocusedElement;
        encoder << m_respectSelectionAnchor;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    bool m_isInteractingWithFocusedElement;
    WebKit::RespectSelectionAnchor m_respectSelectionAnchor;
};
#endif

#if PLATFORM(IOS_FAMILY)
class UpdateSelectionWithExtentPointAndBoundary {
public:
    using Arguments = std::tuple<WebCore::IntPoint, WebCore::TextGranularity, bool, WebKit::TextInteractionSource>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateSelectionWithExtentPointAndBoundary; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateSelectionWithExtentPointAndBoundaryReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    UpdateSelectionWithExtentPointAndBoundary(const WebCore::IntPoint& point, WebCore::TextGranularity granularity, bool isInteractingWithFocusedElement, WebKit::TextInteractionSource sources)
        : m_point(point)
        , m_granularity(granularity)
        , m_isInteractingWithFocusedElement(isInteractingWithFocusedElement)
        , m_sources(sources)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        encoder << m_granularity;
        encoder << m_isInteractingWithFocusedElement;
        encoder << m_sources;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    WebCore::TextGranularity m_granularity;
    bool m_isInteractingWithFocusedElement;
    WebKit::TextInteractionSource m_sources;
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidReleaseAllTouchPoints {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidReleaseAllTouchPoints; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReleaseAllTouchPoints()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class ClearSelectionAfterTappingSelectionHighlightIfNeeded {
public:
    using Arguments = std::tuple<WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ClearSelectionAfterTappingSelectionHighlightIfNeeded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ClearSelectionAfterTappingSelectionHighlightIfNeeded(const WebCore::FloatPoint& location)
        : m_location(location)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_location;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_location;
};
#endif

#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
class RequestRVItemInCurrentSelectedRange {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestRVItemInCurrentSelectedRange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestRVItemInCurrentSelectedRangeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::RevealItem>;
    using Reply = CompletionHandler<void(WebKit::RevealItem&&)>;
    using Promise = WTF::NativePromise<WebKit::RevealItem, IPC::Error>;
    RequestRVItemInCurrentSelectedRange()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
class PrepareSelectionForContextMenuWithLocationInView {
public:
    using Arguments = std::tuple<WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PrepareSelectionForContextMenuWithLocationInView; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PrepareSelectionForContextMenuWithLocationInViewReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, WebKit::RevealItem>;
    using Reply = CompletionHandler<void(bool, WebKit::RevealItem&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, WebKit::RevealItem>, IPC::Error>;
    explicit PrepareSelectionForContextMenuWithLocationInView(const WebCore::IntPoint& point)
        : m_point(point)
    {
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
class WillInsertFinalDictationResult {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WillInsertFinalDictationResult; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WillInsertFinalDictationResult()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidInsertFinalDictationResult {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidInsertFinalDictationResult; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidInsertFinalDictationResult()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class ReplaceDictatedText {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ReplaceDictatedText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReplaceDictatedText(const String& oldText, const String& newText)
        : m_oldText(oldText)
        , m_newText(newText)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_oldText;
        encoder << m_newText;
    }

private:
    const String& m_oldText;
    const String& m_newText;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ReplaceSelectedText {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ReplaceSelectedText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReplaceSelectedText(const String& oldText, const String& newText)
        : m_oldText(oldText)
        , m_newText(newText)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_oldText;
        encoder << m_newText;
    }

private:
    const String& m_oldText;
    const String& m_newText;
};
#endif

#if PLATFORM(IOS_FAMILY)
class RequestAutocorrectionData {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestAutocorrectionData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestAutocorrectionDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::WebAutocorrectionData>;
    using Reply = CompletionHandler<void(WebKit::WebAutocorrectionData&&)>;
    using Promise = WTF::NativePromise<WebKit::WebAutocorrectionData, IPC::Error>;
    explicit RequestAutocorrectionData(const String& textForAutocorrection)
        : m_textForAutocorrection(textForAutocorrection)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_textForAutocorrection;
    }

private:
    const String& m_textForAutocorrection;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ApplyAutocorrection {
public:
    using Arguments = std::tuple<String, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ApplyAutocorrection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ApplyAutocorrectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    ApplyAutocorrection(const String& correction, const String& originalText, bool isCandidate)
        : m_correction(correction)
        , m_originalText(originalText)
        , m_isCandidate(isCandidate)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_correction;
        encoder << m_originalText;
        encoder << m_isCandidate;
    }

private:
    const String& m_correction;
    const String& m_originalText;
    bool m_isCandidate;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SyncApplyAutocorrection {
public:
    using Arguments = std::tuple<String, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SyncApplyAutocorrection; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    SyncApplyAutocorrection(const String& correction, const String& originalText, bool isCandidate)
        : m_correction(correction)
        , m_originalText(originalText)
        , m_isCandidate(isCandidate)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_correction;
        encoder << m_originalText;
        encoder << m_isCandidate;
    }

private:
    const String& m_correction;
    const String& m_originalText;
    bool m_isCandidate;
};
#endif

#if PLATFORM(IOS_FAMILY)
class HandleAutocorrectionContextRequest {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HandleAutocorrectionContextRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleAutocorrectionContextRequest()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class RequestEvasionRectsAboveSelection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestEvasionRectsAboveSelection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestEvasionRectsAboveSelectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::FloatRect>>;
    using Reply = CompletionHandler<void(Vector<WebCore::FloatRect>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::FloatRect>, IPC::Error>;
    RequestEvasionRectsAboveSelection()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class RequestPositionInformation {
public:
    using Arguments = std::tuple<WebKit::InteractionInformationRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestPositionInformation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RequestPositionInformation(const WebKit::InteractionInformationRequest& request)
        : m_request(request)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::InteractionInformationRequest& m_request;
};
#endif

#if PLATFORM(IOS_FAMILY)
class StartInteractionWithElementContextOrPosition {
public:
    using Arguments = std::tuple<std::optional<WebCore::ElementContext>, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StartInteractionWithElementContextOrPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartInteractionWithElementContextOrPosition(const std::optional<WebCore::ElementContext>& elementContext, const WebCore::IntPoint& point)
        : m_elementContext(elementContext)
        , m_point(point)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_elementContext;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::ElementContext>& m_elementContext;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
};
#endif

#if PLATFORM(IOS_FAMILY)
class StopInteraction {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StopInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopInteraction()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class PerformActionOnElement {
public:
    using Arguments = std::tuple<uint32_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PerformActionOnElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PerformActionOnElementReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PerformActionOnElement(uint32_t action, const String& authenticationToken)
        : m_action(action)
        , m_authenticationToken(authenticationToken)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_action;
        encoder << m_authenticationToken;
    }

private:
    uint32_t m_action;
    const String& m_authenticationToken;
};
#endif

#if PLATFORM(IOS_FAMILY)
class PerformActionOnElements {
public:
    using Arguments = std::tuple<uint32_t, Vector<WebCore::ElementContext>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PerformActionOnElements; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PerformActionOnElements(uint32_t action, const Vector<WebCore::ElementContext>& elements)
        : m_action(action)
        , m_elements(elements)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_action;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_elements;
    }

private:
    uint32_t m_action;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::ElementContext>& m_elements;
};
#endif

#if PLATFORM(IOS_FAMILY)
class FocusNextFocusedElement {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FocusNextFocusedElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_FocusNextFocusedElementReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit FocusNextFocusedElement(bool isForward)
        : m_isForward(isForward)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isForward;
    }

private:
    bool m_isForward;
};
#endif

#if PLATFORM(IOS_FAMILY)
class AutofillLoginCredentials {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AutofillLoginCredentials; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AutofillLoginCredentials(const String& username, const String& password)
        : m_username(username)
        , m_password(password)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_username;
        encoder << m_password;
    }

private:
    const String& m_username;
    const String& m_password;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetFocusedElementValue {
public:
    using Arguments = std::tuple<WebCore::ElementContext, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetFocusedElementValue; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetFocusedElementValue(const WebCore::ElementContext& context, const String& value)
        : m_context(context)
        , m_value(value)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
        encoder << m_value;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_context;
    const String& m_value;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetFocusedElementSelectedIndex {
public:
    using Arguments = std::tuple<WebCore::ElementContext, uint32_t, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetFocusedElementSelectedIndex; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetFocusedElementSelectedIndex(const WebCore::ElementContext& context, uint32_t index, bool allowMultipleSelection)
        : m_context(context)
        , m_index(index)
        , m_allowMultipleSelection(allowMultipleSelection)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
        encoder << m_index;
        encoder << m_allowMultipleSelection;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_context;
    uint32_t m_index;
    bool m_allowMultipleSelection;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ApplicationWillResignActive {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ApplicationWillResignActive; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ApplicationWillResignActive()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class ApplicationDidEnterBackground {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ApplicationDidEnterBackground; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ApplicationDidEnterBackground(bool isSuspendedUnderLock)
        : m_isSuspendedUnderLock(isSuspendedUnderLock)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isSuspendedUnderLock;
    }

private:
    bool m_isSuspendedUnderLock;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ApplicationDidFinishSnapshottingAfterEnteringBackground {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ApplicationDidFinishSnapshottingAfterEnteringBackground; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ApplicationDidFinishSnapshottingAfterEnteringBackground()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class ApplicationWillEnterForeground {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ApplicationWillEnterForeground; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ApplicationWillEnterForeground(bool isSuspendedUnderLock)
        : m_isSuspendedUnderLock(isSuspendedUnderLock)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isSuspendedUnderLock;
    }

private:
    bool m_isSuspendedUnderLock;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ApplicationDidBecomeActive {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ApplicationDidBecomeActive; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ApplicationDidBecomeActive()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class ApplicationDidEnterBackgroundForMedia {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ApplicationDidEnterBackgroundForMedia; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ApplicationDidEnterBackgroundForMedia(bool isSuspendedUnderLock)
        : m_isSuspendedUnderLock(isSuspendedUnderLock)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isSuspendedUnderLock;
    }

private:
    bool m_isSuspendedUnderLock;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ApplicationWillEnterForegroundForMedia {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ApplicationWillEnterForegroundForMedia; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ApplicationWillEnterForegroundForMedia(bool isSuspendedUnderLock)
        : m_isSuspendedUnderLock(isSuspendedUnderLock)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isSuspendedUnderLock;
    }

private:
    bool m_isSuspendedUnderLock;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ContentSizeCategoryDidChange {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ContentSizeCategoryDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ContentSizeCategoryDidChange(const String& contentSizeCategory)
        : m_contentSizeCategory(contentSizeCategory)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contentSizeCategory;
    }

private:
    const String& m_contentSizeCategory;
};
#endif

#if PLATFORM(IOS_FAMILY)
class GetSelectionContext {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetSelectionContext; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetSelectionContextReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, String, String>;
    using Reply = CompletionHandler<void(String&&, String&&, String&&)>;
    using Promise = WTF::NativePromise<std::tuple<String, String, String>, IPC::Error>;
    GetSelectionContext()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetAllowsMediaDocumentInlinePlayback {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetAllowsMediaDocumentInlinePlayback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAllowsMediaDocumentInlinePlayback(bool allows)
        : m_allows(allows)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_allows;
    }

private:
    bool m_allows;
};
#endif

#if PLATFORM(IOS_FAMILY)
class HandleTwoFingerTapAtPoint {
public:
    using Arguments = std::tuple<WebCore::IntPoint, OptionSet<WebKit::WebEventModifier>, WebKit::TapIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HandleTwoFingerTapAtPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HandleTwoFingerTapAtPoint(const WebCore::IntPoint& point, const OptionSet<WebKit::WebEventModifier>& modifiers, const WebKit::TapIdentifier& requestID)
        : m_point(point)
        , m_modifiers(modifiers)
        , m_requestID(requestID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiers;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_requestID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::WebEventModifier>& m_modifiers;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::TapIdentifier& m_requestID;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetForceAlwaysUserScalable {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetForceAlwaysUserScalable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetForceAlwaysUserScalable(bool userScalable)
        : m_userScalable(userScalable)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_userScalable;
    }

private:
    bool m_userScalable;
};
#endif

#if PLATFORM(IOS_FAMILY)
class GetRectsForGranularityWithSelectionOffset {
public:
    using Arguments = std::tuple<WebCore::TextGranularity, int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetRectsForGranularityWithSelectionOffset; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetRectsForGranularityWithSelectionOffsetReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::SelectionGeometry>>;
    using Reply = CompletionHandler<void(Vector<WebCore::SelectionGeometry>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::SelectionGeometry>, IPC::Error>;
    GetRectsForGranularityWithSelectionOffset(WebCore::TextGranularity granularity, int32_t offset)
        : m_granularity(granularity)
        , m_offset(offset)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_granularity;
        encoder << m_offset;
    }

private:
    WebCore::TextGranularity m_granularity;
    int32_t m_offset;
};
#endif

#if PLATFORM(IOS_FAMILY)
class GetRectsAtSelectionOffsetWithText {
public:
    using Arguments = std::tuple<int32_t, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetRectsAtSelectionOffsetWithText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetRectsAtSelectionOffsetWithTextReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::SelectionGeometry>>;
    using Reply = CompletionHandler<void(Vector<WebCore::SelectionGeometry>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::SelectionGeometry>, IPC::Error>;
    GetRectsAtSelectionOffsetWithText(int32_t offset, const String& text)
        : m_offset(offset)
        , m_text(text)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_offset;
        encoder << m_text;
    }

private:
    int32_t m_offset;
    const String& m_text;
};
#endif

#if PLATFORM(IOS_FAMILY)
class StoreSelectionForAccessibility {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StoreSelectionForAccessibility; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StoreSelectionForAccessibility(bool shouldStore)
        : m_shouldStore(shouldStore)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldStore;
    }

private:
    bool m_shouldStore;
};
#endif

#if PLATFORM(IOS_FAMILY)
class StartAutoscrollAtPosition {
public:
    using Arguments = std::tuple<WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StartAutoscrollAtPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StartAutoscrollAtPosition(const WebCore::FloatPoint& positionInWindow)
        : m_positionInWindow(positionInWindow)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_positionInWindow;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_positionInWindow;
};
#endif

#if PLATFORM(IOS_FAMILY)
class CancelAutoscroll {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CancelAutoscroll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelAutoscroll()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class RequestFocusedElementInformation {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestFocusedElementInformation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestFocusedElementInformationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::FocusedElementInformation>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::FocusedElementInformation>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::FocusedElementInformation>, IPC::Error>;
    RequestFocusedElementInformation()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class HardwareKeyboardAvailabilityChanged {
public:
    using Arguments = std::tuple<WebKit::HardwareKeyboardState>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HardwareKeyboardAvailabilityChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HardwareKeyboardAvailabilityChanged(const WebKit::HardwareKeyboardState& state)
        : m_state(state)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_state;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::HardwareKeyboardState& m_state;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetIsShowingInputViewForFocusedElement {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetIsShowingInputViewForFocusedElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIsShowingInputViewForFocusedElement(bool showingInputView)
        : m_showingInputView(showingInputView)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_showingInputView;
    }

private:
    bool m_showingInputView;
};
#endif

#if PLATFORM(IOS_FAMILY)
class UpdateSelectionWithDelta {
public:
    using Arguments = std::tuple<int64_t, int64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateSelectionWithDelta; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateSelectionWithDeltaReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UpdateSelectionWithDelta(int64_t locationDelta, int64_t lengthDelta)
        : m_locationDelta(locationDelta)
        , m_lengthDelta(lengthDelta)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_locationDelta;
        encoder << m_lengthDelta;
    }

private:
    int64_t m_locationDelta;
    int64_t m_lengthDelta;
};
#endif

#if PLATFORM(IOS_FAMILY)
class RequestDocumentEditingContext {
public:
    using Arguments = std::tuple<WebKit::DocumentEditingContextRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestDocumentEditingContext; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestDocumentEditingContextReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::DocumentEditingContext>;
    using Reply = CompletionHandler<void(WebKit::DocumentEditingContext&&)>;
    using Promise = WTF::NativePromise<WebKit::DocumentEditingContext, IPC::Error>;
    explicit RequestDocumentEditingContext(const WebKit::DocumentEditingContextRequest& request)
        : m_request(request)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::DocumentEditingContextRequest& m_request;
};
#endif

#if PLATFORM(IOS_FAMILY)
class GenerateSyntheticEditingCommand {
public:
    using Arguments = std::tuple<WebKit::SyntheticEditingCommandType>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GenerateSyntheticEditingCommand; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit GenerateSyntheticEditingCommand(WebKit::SyntheticEditingCommandType command)
        : m_command(command)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_command;
    }

private:
    WebKit::SyntheticEditingCommandType m_command;
};
#endif

#if PLATFORM(IOS_FAMILY)
class SetShouldRevealCurrentSelectionAfterInsertion {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetShouldRevealCurrentSelectionAfterInsertion; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldRevealCurrentSelectionAfterInsertion(bool shouldRevealCurrentSelectionAfterInsertion)
        : m_shouldRevealCurrentSelectionAfterInsertion(shouldRevealCurrentSelectionAfterInsertion)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldRevealCurrentSelectionAfterInsertion;
    }

private:
    bool m_shouldRevealCurrentSelectionAfterInsertion;
};
#endif

#if PLATFORM(IOS_FAMILY)
class TextInputContextsInRect {
public:
    using Arguments = std::tuple<WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TextInputContextsInRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_TextInputContextsInRectReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::ElementContext>>;
    using Reply = CompletionHandler<void(Vector<WebCore::ElementContext>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::ElementContext>, IPC::Error>;
    explicit TextInputContextsInRect(const WebCore::FloatRect& rect)
        : m_rect(rect)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
};
#endif

#if PLATFORM(IOS_FAMILY)
class FocusTextInputContextAndPlaceCaret {
public:
    using Arguments = std::tuple<WebCore::ElementContext, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FocusTextInputContextAndPlaceCaret; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_FocusTextInputContextAndPlaceCaretReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    FocusTextInputContextAndPlaceCaret(const WebCore::ElementContext& context, const WebCore::IntPoint& point)
        : m_context(context)
        , m_point(point)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_context;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_point;
};
#endif

#if PLATFORM(IOS_FAMILY)
class ClearServiceWorkerEntitlementOverride {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ClearServiceWorkerEntitlementOverride; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ClearServiceWorkerEntitlementOverrideReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ClearServiceWorkerEntitlementOverride()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class ProcessWillSuspend {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ProcessWillSuspend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProcessWillSuspend()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ProcessDidResume {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ProcessDidResume; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProcessDidResume()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RequestImageBitmap {
public:
    using Arguments = std::tuple<WebCore::ElementContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestImageBitmap; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestImageBitmapReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>, String>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&, String&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::ShareableBitmapHandle>, String>, IPC::Error>;
    explicit RequestImageBitmap(const WebCore::ElementContext& elementContext)
        : m_elementContext(elementContext)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_elementContext;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_elementContext;
};

class SetControlledByAutomation {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetControlledByAutomation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetControlledByAutomation(bool controlled)
        : m_controlled(controlled)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_controlled;
    }

private:
    bool m_controlled;
};

class ConnectInspector {
public:
    using Arguments = std::tuple<String, Inspector::FrontendChannel::ConnectionType>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ConnectInspector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ConnectInspector(const String& targetId, const Inspector::FrontendChannel::ConnectionType& connectionType)
        : m_targetId(targetId)
        , m_connectionType(connectionType)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_targetId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_connectionType;
    }

private:
    const String& m_targetId;
    SUPPRESS_FORWARD_DECL_MEMBER const Inspector::FrontendChannel::ConnectionType& m_connectionType;
};

class DisconnectInspector {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DisconnectInspector; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DisconnectInspector(const String& targetId)
        : m_targetId(targetId)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_targetId;
    }

private:
    const String& m_targetId;
};

class SendMessageToTargetBackend {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SendMessageToTargetBackend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SendMessageToTargetBackend(const String& targetId, const String& message)
        : m_targetId(targetId)
        , m_message(message)
    {
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

#if ENABLE(REMOTE_INSPECTOR)
class SetIndicating {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetIndicating; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIndicating(bool indicating)
        : m_indicating(indicating)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_indicating;
    }

private:
    bool m_indicating;
};
#endif

#if ENABLE(IOS_TOUCH_EVENTS)
class DidBeginTouchPoint {
public:
    using Arguments = std::tuple<WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidBeginTouchPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidBeginTouchPoint(const WebCore::FloatPoint& locationInRootView)
        : m_locationInRootView(locationInRootView)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_locationInRootView;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_locationInRootView;
};
#endif

#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
class TouchEvent {
public:
    using Arguments = std::tuple<WebKit::WebTouchEvent>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TouchEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_TouchEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::WebEventType>, bool>;
    using Reply = CompletionHandler<void(std::optional<WebKit::WebEventType>, bool)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebKit::WebEventType>, bool>, IPC::Error>;
    explicit TouchEvent(const WebKit::WebTouchEvent& event)
        : m_event(event)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebTouchEvent& m_event;
};
#endif

class CancelPointer {
public:
    using Arguments = std::tuple<WebCore::PointerID, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CancelPointer; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelPointer(const WebCore::PointerID& pointerId, const WebCore::IntPoint& documentPoint)
        : m_pointerId(pointerId)
        , m_documentPoint(documentPoint)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pointerId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_documentPoint;
    }

private:
    const WebCore::PointerID& m_pointerId;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_documentPoint;
};

class TouchWithIdentifierWasRemoved {
public:
    using Arguments = std::tuple<WebCore::PointerID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TouchWithIdentifierWasRemoved; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TouchWithIdentifierWasRemoved(const WebCore::PointerID& pointerId)
        : m_pointerId(pointerId)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pointerId;
    }

private:
    const WebCore::PointerID& m_pointerId;
};

class DidEndColorPicker {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidEndColorPicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidEndColorPicker()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidChooseColor {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidChooseColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChooseColor(const WebCore::Color& color)
        : m_color(color)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};

class DidSelectDataListOption {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidSelectDataListOption; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidSelectDataListOption(const String& selectedOption)
        : m_selectedOption(selectedOption)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_selectedOption;
    }

private:
    const String& m_selectedOption;
};

class DidCloseSuggestions {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidCloseSuggestions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCloseSuggestions()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidChooseDate {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidChooseDate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChooseDate(const String& date)
        : m_date(date)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_date;
    }

private:
    const String& m_date;
};

class DidEndDateTimePicker {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidEndDateTimePicker; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidEndDateTimePicker()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ScrollBy {
public:
    using Arguments = std::tuple<WebCore::ScrollDirection, WebCore::ScrollGranularity>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ScrollBy; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ScrollBy(WebCore::ScrollDirection scrollDirection, WebCore::ScrollGranularity scrollGranularity)
        : m_scrollDirection(scrollDirection)
        , m_scrollGranularity(scrollGranularity)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scrollDirection;
        encoder << m_scrollGranularity;
    }

private:
    WebCore::ScrollDirection m_scrollDirection;
    WebCore::ScrollGranularity m_scrollGranularity;
};

class CenterSelectionInVisibleArea {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CenterSelectionInVisibleArea; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CenterSelectionInVisibleArea()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GoToBackForwardItem {
public:
    using Arguments = std::tuple<WebKit::GoToBackForwardItemParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GoToBackForwardItem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit GoToBackForwardItem(WebKit::GoToBackForwardItemParameters&& parameters)
        : m_parameters(WTFMove(parameters))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_parameters);
    }

private:
    WebKit::GoToBackForwardItemParameters&& m_parameters;
};

class GoToBackForwardItemWaitingForProcessLaunch {
public:
    using Arguments = std::tuple<WebKit::GoToBackForwardItemParameters, WebKit::WebPageProxyIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GoToBackForwardItemWaitingForProcessLaunch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GoToBackForwardItemWaitingForProcessLaunch(WebKit::GoToBackForwardItemParameters&& parameters, const WebKit::WebPageProxyIdentifier& pageID)
        : m_parameters(WTFMove(parameters))
        , m_pageID(pageID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_parameters);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
    }

private:
    WebKit::GoToBackForwardItemParameters&& m_parameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
};

class TryRestoreScrollPosition {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TryRestoreScrollPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TryRestoreScrollPosition()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class LoadURLInFrame {
public:
    using Arguments = std::tuple<URL, String, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadURLInFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LoadURLInFrame(const URL& url, const String& referrer, const WebCore::FrameIdentifier& frameID)
        : m_url(url)
        , m_referrer(referrer)
        , m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
        encoder << m_referrer;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
    const String& m_referrer;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class LoadDataInFrame {
public:
    using Arguments = std::tuple<std::span<const uint8_t>, String, String, URL, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadDataInFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LoadDataInFrame(const std::span<const uint8_t>& data, const String& MIMEType, const String& encodingName, const URL& baseURL, const WebCore::FrameIdentifier& frameID)
        : m_data(data)
        , m_MIMEType(MIMEType)
        , m_encodingName(encodingName)
        , m_baseURL(baseURL)
        , m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        encoder << m_MIMEType;
        encoder << m_encodingName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_baseURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
    const String& m_MIMEType;
    const String& m_encodingName;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_baseURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class LoadRequest {
public:
    using Arguments = std::tuple<WebKit::LoadParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadRequest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit LoadRequest(WebKit::LoadParameters&& loadParameters)
        : m_loadParameters(WTFMove(loadParameters))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_loadParameters);
    }

private:
    WebKit::LoadParameters&& m_loadParameters;
};

class LoadDidCommitInAnotherProcess {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::optional<WebCore::LayerHostingContextIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadDidCommitInAnotherProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LoadDidCommitInAnotherProcess(const WebCore::FrameIdentifier& frameID, const std::optional<WebCore::LayerHostingContextIdentifier>& layerHostingContextIdentifier)
        : m_frameID(frameID)
        , m_layerHostingContextIdentifier(layerHostingContextIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_layerHostingContextIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::LayerHostingContextIdentifier>& m_layerHostingContextIdentifier;
};

class LoadRequestWaitingForProcessLaunch {
public:
    using Arguments = std::tuple<WebKit::LoadParameters, URL, WebKit::WebPageProxyIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadRequestWaitingForProcessLaunch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LoadRequestWaitingForProcessLaunch(WebKit::LoadParameters&& loadParameters, const URL& resourceDirectoryURL, const WebKit::WebPageProxyIdentifier& pageID, bool checkAssumedReadAccessToResourceURL)
        : m_loadParameters(WTFMove(loadParameters))
        , m_resourceDirectoryURL(resourceDirectoryURL)
        , m_pageID(pageID)
        , m_checkAssumedReadAccessToResourceURL(checkAssumedReadAccessToResourceURL)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_loadParameters);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_resourceDirectoryURL;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageID;
        encoder << m_checkAssumedReadAccessToResourceURL;
    }

private:
    WebKit::LoadParameters&& m_loadParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_resourceDirectoryURL;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPageProxyIdentifier& m_pageID;
    bool m_checkAssumedReadAccessToResourceURL;
};

class LoadData {
public:
    using Arguments = std::tuple<WebKit::LoadParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit LoadData(WebKit::LoadParameters&& loadParameters)
        : m_loadParameters(WTFMove(loadParameters))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_loadParameters);
    }

private:
    WebKit::LoadParameters&& m_loadParameters;
};

class LoadSimulatedRequestAndResponse {
public:
    using Arguments = std::tuple<WebKit::LoadParameters, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadSimulatedRequestAndResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    LoadSimulatedRequestAndResponse(WebKit::LoadParameters&& loadParameters, const WebCore::ResourceResponse& simulatedResponse)
        : m_loadParameters(WTFMove(loadParameters))
        , m_simulatedResponse(simulatedResponse)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_loadParameters);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_simulatedResponse;
    }

private:
    WebKit::LoadParameters&& m_loadParameters;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_simulatedResponse;
};

class LoadAlternateHTML {
public:
    using Arguments = std::tuple<WebKit::LoadParameters>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadAlternateHTML; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit LoadAlternateHTML(WebKit::LoadParameters&& loadParameters)
        : m_loadParameters(WTFMove(loadParameters))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_loadParameters);
    }

private:
    WebKit::LoadParameters&& m_loadParameters;
};

class CreateRemoteSubframe {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::FrameIdentifier, String, Ref<WebCore::FrameTreeSyncData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CreateRemoteSubframe; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CreateRemoteSubframe(const WebCore::FrameIdentifier& parentID, const WebCore::FrameIdentifier& newChildID, const String& frameName, const Ref<WebCore::FrameTreeSyncData>& frameTreeSyncData)
        : m_parentID(parentID)
        , m_newChildID(newChildID)
        , m_frameName(frameName)
        , m_frameTreeSyncData(frameTreeSyncData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parentID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_newChildID;
        encoder << m_frameName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameTreeSyncData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_parentID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_newChildID;
    const String& m_frameName;
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::FrameTreeSyncData>& m_frameTreeSyncData;
};

class GetFrameTree {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetFrameTree; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetFrameTreeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::FrameTreeNodeData>>;
    using Reply = CompletionHandler<void(std::optional<WebKit::FrameTreeNodeData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebKit::FrameTreeNodeData>, IPC::Error>;
    GetFrameTree()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidFinishLoadInAnotherProcess {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidFinishLoadInAnotherProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidFinishLoadInAnotherProcess(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class FrameWasRemovedInAnotherProcess {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FrameWasRemovedInAnotherProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FrameWasRemovedInAnotherProcess(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class UpdateFrameTreeSyncData {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, Ref<WebCore::FrameTreeSyncData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateFrameTreeSyncData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateFrameTreeSyncData(const WebCore::FrameIdentifier& frameID, const Ref<WebCore::FrameTreeSyncData>& frameTreeSyncData)
        : m_frameID(frameID)
        , m_frameTreeSyncData(frameTreeSyncData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameTreeSyncData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::FrameTreeSyncData>& m_frameTreeSyncData;
};

class ProcessSyncDataChangedInAnotherProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessSyncData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ProcessSyncDataChangedInAnotherProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ProcessSyncDataChangedInAnotherProcess(const WebCore::ProcessSyncData& processSyncData)
        : m_processSyncData(processSyncData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processSyncData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessSyncData& m_processSyncData;
};

class TopDocumentSyncDataChangedInAnotherProcess {
public:
    using Arguments = std::tuple<Ref<WebCore::DocumentSyncData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TopDocumentSyncDataChangedInAnotherProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit TopDocumentSyncDataChangedInAnotherProcess(const Ref<WebCore::DocumentSyncData>& documentSyncData)
        : m_documentSyncData(documentSyncData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_documentSyncData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::DocumentSyncData>& m_documentSyncData;
};

class NavigateToPDFLinkWithSimulatedClick {
public:
    using Arguments = std::tuple<String, WebCore::IntPoint, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_NavigateToPDFLinkWithSimulatedClick; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    NavigateToPDFLinkWithSimulatedClick(const String& url, const WebCore::IntPoint& documentPoint, const WebCore::IntPoint& screenPoint)
        : m_url(url)
        , m_documentPoint(documentPoint)
        , m_screenPoint(screenPoint)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_url;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_documentPoint;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_screenPoint;
    }

private:
    const String& m_url;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_documentPoint;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_screenPoint;
};

class GetPDFFirstPageSize {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetPDFFirstPageSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetPDFFirstPageSizeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::FloatSize>;
    using Reply = CompletionHandler<void(WebCore::FloatSize&&)>;
    using Promise = WTF::NativePromise<WebCore::FloatSize, IPC::Error>;
    explicit GetPDFFirstPageSize(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class Reload {
public:
    using Arguments = std::tuple<WebCore::NavigationIdentifier, OptionSet<WebCore::ReloadOption>, WebKit::SandboxExtensionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_Reload; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Reload(const WebCore::NavigationIdentifier& navigationID, const OptionSet<WebCore::ReloadOption>& reloadOptions, WebKit::SandboxExtensionHandle&& sandboxExtensionHandle)
        : m_navigationID(navigationID)
        , m_reloadOptions(reloadOptions)
        , m_sandboxExtensionHandle(WTFMove(sandboxExtensionHandle))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_navigationID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_reloadOptions;
        encoder << WTFMove(m_sandboxExtensionHandle);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NavigationIdentifier& m_navigationID;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::ReloadOption>& m_reloadOptions;
    WebKit::SandboxExtensionHandle&& m_sandboxExtensionHandle;
};

class StopLoading {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StopLoading; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopLoading()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StopLoadingDueToProcessSwap {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StopLoadingDueToProcessSwap; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopLoadingDueToProcessSwap()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetCurrentHistoryItemForReattach {
public:
    using Arguments = std::tuple<Ref<WebKit::FrameState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCurrentHistoryItemForReattach; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCurrentHistoryItemForReattach(const Ref<WebKit::FrameState>& frameState)
        : m_frameState(frameState)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameState;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebKit::FrameState>& m_frameState;
};

class DidRemoveBackForwardItem {
public:
    using Arguments = std::tuple<WebCore::BackForwardItemIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidRemoveBackForwardItem; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidRemoveBackForwardItem(const WebCore::BackForwardItemIdentifier& backForwardItemID)
        : m_backForwardItemID(backForwardItemID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backForwardItemID;
    }

private:
    const WebCore::BackForwardItemIdentifier& m_backForwardItemID;
};

class UpdateWebsitePolicies {
public:
    using Arguments = std::tuple<WebKit::WebsitePoliciesData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateWebsitePolicies; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateWebsitePolicies(const WebKit::WebsitePoliciesData& websitePolicies)
        : m_websitePolicies(websitePolicies)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_websitePolicies;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebsitePoliciesData& m_websitePolicies;
};

class ClearSelection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ClearSelection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearSelection()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RestoreSelectionInFocusedEditableElement {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RestoreSelectionInFocusedEditableElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RestoreSelectionInFocusedEditableElement()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetContentsAsString {
public:
    using Arguments = std::tuple<WebKit::ContentAsStringIncludesChildFrames>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetContentsAsString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetContentsAsStringReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit GetContentsAsString(WebKit::ContentAsStringIncludesChildFrames inChildFrames)
        : m_inChildFrames(inChildFrames)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_inChildFrames;
    }

private:
    WebKit::ContentAsStringIncludesChildFrames m_inChildFrames;
};

#if PLATFORM(COCOA)
class GetContentsAsAttributedString {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetContentsAsAttributedString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetContentsAsAttributedStringReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::AttributedString>;
    using Reply = CompletionHandler<void(WebCore::AttributedString&&)>;
    using Promise = WTF::NativePromise<WebCore::AttributedString, IPC::Error>;
    GetContentsAsAttributedString()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(MHTML)
class GetContentsAsMHTMLData {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetContentsAsMHTMLData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetContentsAsMHTMLDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<IPC::SharedBufferReference>;
    using Reply = CompletionHandler<void(IPC::SharedBufferReference&&)>;
    using Promise = WTF::NativePromise<IPC::SharedBufferReference, IPC::Error>;
    GetContentsAsMHTMLData()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class GetMainResourceDataOfFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetMainResourceDataOfFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetMainResourceDataOfFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::SharedBufferReference>>;
    using Reply = CompletionHandler<void(std::optional<IPC::SharedBufferReference>&&)>;
    using Promise = WTF::NativePromise<std::optional<IPC::SharedBufferReference>, IPC::Error>;
    explicit GetMainResourceDataOfFrame(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class GetResourceDataFromFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetResourceDataFromFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetResourceDataFromFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::SharedBufferReference>>;
    using Reply = CompletionHandler<void(std::optional<IPC::SharedBufferReference>&&)>;
    using Promise = WTF::NativePromise<std::optional<IPC::SharedBufferReference>, IPC::Error>;
    GetResourceDataFromFrame(const WebCore::FrameIdentifier& frameID, const String& resourceURL)
        : m_frameID(frameID)
        , m_resourceURL(resourceURL)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_resourceURL;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    const String& m_resourceURL;
};

class GetRenderTreeExternalRepresentation {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetRenderTreeExternalRepresentation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetRenderTreeExternalRepresentationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    GetRenderTreeExternalRepresentation()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetSelectionOrContentsAsString {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetSelectionOrContentsAsString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetSelectionOrContentsAsStringReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    GetSelectionOrContentsAsString()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetSelectionAsWebArchiveData {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetSelectionAsWebArchiveData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetSelectionAsWebArchiveDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::SharedBufferReference>>;
    using Reply = CompletionHandler<void(std::optional<IPC::SharedBufferReference>&&)>;
    using Promise = WTF::NativePromise<std::optional<IPC::SharedBufferReference>, IPC::Error>;
    GetSelectionAsWebArchiveData()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetSourceForFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetSourceForFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetSourceForFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    explicit GetSourceForFrame(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class GetWebArchiveOfFrame {
public:
    using Arguments = std::tuple<std::optional<WebCore::FrameIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetWebArchiveOfFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetWebArchiveOfFrameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::SharedBufferReference>>;
    using Reply = CompletionHandler<void(std::optional<IPC::SharedBufferReference>&&)>;
    using Promise = WTF::NativePromise<std::optional<IPC::SharedBufferReference>, IPC::Error>;
    explicit GetWebArchiveOfFrame(const std::optional<WebCore::FrameIdentifier>& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
};

class GetWebArchiveOfFrameWithFileName {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, Vector<WebCore::MarkupExclusionRule>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetWebArchiveOfFrameWithFileName; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetWebArchiveOfFrameWithFileNameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::SharedBufferReference>>;
    using Reply = CompletionHandler<void(std::optional<IPC::SharedBufferReference>&&)>;
    using Promise = WTF::NativePromise<std::optional<IPC::SharedBufferReference>, IPC::Error>;
    GetWebArchiveOfFrameWithFileName(const WebCore::FrameIdentifier& frameID, const Vector<WebCore::MarkupExclusionRule>& markupExclusionRules, const String& fileName)
        : m_frameID(frameID)
        , m_markupExclusionRules(markupExclusionRules)
        , m_fileName(fileName)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_markupExclusionRules;
        encoder << m_fileName;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::MarkupExclusionRule>& m_markupExclusionRules;
    const String& m_fileName;
};

#if PLATFORM(COCOA)
class GetWebArchives {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetWebArchives; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetWebArchivesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<HashMap<WebCore::FrameIdentifier, Ref<WebCore::LegacyWebArchive>>>;
    using Reply = CompletionHandler<void(HashMap<WebCore::FrameIdentifier, Ref<WebCore::LegacyWebArchive>>&&)>;
    using Promise = WTF::NativePromise<HashMap<WebCore::FrameIdentifier, Ref<WebCore::LegacyWebArchive>>, IPC::Error>;
    GetWebArchives()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class RunJavaScriptInFrameInScriptWorld {
public:
    using Arguments = std::tuple<WebKit::RunJavaScriptParameters, std::optional<WebCore::FrameIdentifier>, WebKit::ContentWorldData, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RunJavaScriptInFrameInScriptWorld; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RunJavaScriptInFrameInScriptWorldReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<WebKit::JavaScriptEvaluationResult, std::optional<WebCore::ExceptionDetails>>>;
    using Reply = CompletionHandler<void(Expected<WebKit::JavaScriptEvaluationResult, std::optional<WebCore::ExceptionDetails>>&&)>;
    using Promise = WTF::NativePromise<Expected<WebKit::JavaScriptEvaluationResult, std::optional<WebCore::ExceptionDetails>>, IPC::Error>;
    RunJavaScriptInFrameInScriptWorld(const WebKit::RunJavaScriptParameters& parameters, const std::optional<WebCore::FrameIdentifier>& frameID, const WebKit::ContentWorldData& world, bool wantsResult)
        : m_parameters(parameters)
        , m_frameID(frameID)
        , m_world(world)
        , m_wantsResult(wantsResult)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_parameters;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_world;
        encoder << m_wantsResult;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::RunJavaScriptParameters& m_parameters;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ContentWorldData& m_world;
    bool m_wantsResult;
};

class GetAccessibilityTreeData {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetAccessibilityTreeData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetAccessibilityTreeDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::SharedBufferReference>>;
    using Reply = CompletionHandler<void(std::optional<IPC::SharedBufferReference>&&)>;
    using Promise = WTF::NativePromise<std::optional<IPC::SharedBufferReference>, IPC::Error>;
    GetAccessibilityTreeData()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class UpdateRenderingWithForcedRepaint {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateRenderingWithForcedRepaint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateRenderingWithForcedRepaintReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UpdateRenderingWithForcedRepaint()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SelectAll {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SelectAll; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SelectAll()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ScheduleFullEditorStateUpdate {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ScheduleFullEditorStateUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ScheduleFullEditorStateUpdate()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(COCOA)
class PerformDictionaryLookupAtLocation {
public:
    using Arguments = std::tuple<WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PerformDictionaryLookupAtLocation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PerformDictionaryLookupAtLocation(const WebCore::FloatPoint& point)
        : m_point(point)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point;
};
#endif

#if ENABLE(DATA_DETECTION)
class DetectDataInAllFrames {
public:
    using Arguments = std::tuple<OptionSet<WebCore::DataDetectorType>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DetectDataInAllFrames; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DetectDataInAllFramesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::DataDetectionResult>;
    using Reply = CompletionHandler<void(WebKit::DataDetectionResult&&)>;
    using Promise = WTF::NativePromise<WebKit::DataDetectionResult, IPC::Error>;
    explicit DetectDataInAllFrames(const OptionSet<WebCore::DataDetectorType>& types)
        : m_types(types)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_types;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::DataDetectorType>& m_types;
};
#endif

#if ENABLE(DATA_DETECTION)
class RemoveDataDetectedLinks {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RemoveDataDetectedLinks; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RemoveDataDetectedLinksReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::DataDetectionResult>;
    using Reply = CompletionHandler<void(WebKit::DataDetectionResult&&)>;
    using Promise = WTF::NativePromise<WebKit::DataDetectionResult, IPC::Error>;
    RemoveDataDetectedLinks()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class ChangeFont {
public:
    using Arguments = std::tuple<WebCore::FontChanges>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ChangeFont; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ChangeFont(const WebCore::FontChanges& changes)
        : m_changes(changes)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_changes;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FontChanges& m_changes;
};

class ChangeFontAttributes {
public:
    using Arguments = std::tuple<WebCore::FontAttributeChanges>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ChangeFontAttributes; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ChangeFontAttributes(const WebCore::FontAttributeChanges& changes)
        : m_changes(changes)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_changes;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FontAttributeChanges& m_changes;
};

class PreferencesDidChange {
public:
    using Arguments = std::tuple<WebKit::WebPreferencesStore, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PreferencesDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PreferencesDidChange(const WebKit::WebPreferencesStore& store, const std::optional<uint64_t>& sharedPreferencesVersion)
        : m_store(store)
        , m_sharedPreferencesVersion(sharedPreferencesVersion)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_store;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedPreferencesVersion;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPreferencesStore& m_store;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_sharedPreferencesVersion;
};

class PreferencesDidChangeDuringDOMPrintOperation {
public:
    using Arguments = std::tuple<WebKit::WebPreferencesStore, std::optional<uint64_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PreferencesDidChangeDuringDOMPrintOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PreferencesDidChangeDuringDOMPrintOperation(const WebKit::WebPreferencesStore& store, const std::optional<uint64_t>& sharedPreferencesVersion)
        : m_store(store)
        , m_sharedPreferencesVersion(sharedPreferencesVersion)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_store;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedPreferencesVersion;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebPreferencesStore& m_store;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_sharedPreferencesVersion;
};

class SetUserAgent {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetUserAgent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUserAgent(const String& userAgent)
        : m_userAgent(userAgent)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_userAgent;
    }

private:
    const String& m_userAgent;
};

class SetHasCustomUserAgent {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetHasCustomUserAgent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasCustomUserAgent(bool hasCustomUserAgent)
        : m_hasCustomUserAgent(hasCustomUserAgent)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasCustomUserAgent;
    }

private:
    bool m_hasCustomUserAgent;
};

class SetCustomTextEncodingName {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCustomTextEncodingName; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCustomTextEncodingName(const String& encodingName)
        : m_encodingName(encodingName)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_encodingName;
    }

private:
    const String& m_encodingName;
};

class SuspendActiveDOMObjectsAndAnimations {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SuspendActiveDOMObjectsAndAnimations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SuspendActiveDOMObjectsAndAnimations()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ResumeActiveDOMObjectsAndAnimations {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ResumeActiveDOMObjectsAndAnimations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ResumeActiveDOMObjectsAndAnimations()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Suspend {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_Suspend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SuspendReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    Suspend()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Resume {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_Resume; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ResumeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    Resume()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class Close {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_Close; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    Close()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class TryClose {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TryClose; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_TryCloseReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    TryClose()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetEditable {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetEditable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetEditable(bool editable)
        : m_editable(editable)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_editable;
    }

private:
    bool m_editable;
};

class ValidateCommand {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ValidateCommand; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ValidateCommandReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, int32_t>;
    using Reply = CompletionHandler<void(bool, int32_t)>;
    using Promise = WTF::NativePromise<std::tuple<bool, int32_t>, IPC::Error>;
    explicit ValidateCommand(const String& name)
        : m_name(name)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
    }

private:
    const String& m_name;
};

class ExecuteEditCommand {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ExecuteEditCommand; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ExecuteEditCommand(const String& name, const String& argument)
        : m_name(name)
        , m_argument(argument)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_name;
        encoder << m_argument;
    }

private:
    const String& m_name;
    const String& m_argument;
};

class IncreaseListLevel {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_IncreaseListLevel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    IncreaseListLevel()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DecreaseListLevel {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DecreaseListLevel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DecreaseListLevel()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ChangeListType {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ChangeListType; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ChangeListType()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetBaseWritingDirection {
public:
    using Arguments = std::tuple<WebCore::WritingDirection>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetBaseWritingDirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetBaseWritingDirection(WebCore::WritingDirection direction)
        : m_direction(direction)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_direction;
    }

private:
    WebCore::WritingDirection m_direction;
};

class SetNeedsFontAttributes {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetNeedsFontAttributes; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetNeedsFontAttributes(bool needsFontAttributes)
        : m_needsFontAttributes(needsFontAttributes)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_needsFontAttributes;
    }

private:
    bool m_needsFontAttributes;
};

class RequestFontAttributesAtSelectionStart {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestFontAttributesAtSelectionStart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestFontAttributesAtSelectionStartReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::FontAttributes>;
    using Reply = CompletionHandler<void(WebCore::FontAttributes&&)>;
    using Promise = WTF::NativePromise<WebCore::FontAttributes, IPC::Error>;
    RequestFontAttributesAtSelectionStart()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidRemoveEditCommand {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidRemoveEditCommand; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidRemoveEditCommand(uint64_t commandID)
        : m_commandID(commandID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_commandID;
    }

private:
    uint64_t m_commandID;
};

class ReapplyEditCommand {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ReapplyEditCommand; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ReapplyEditCommand(uint64_t commandID)
        : m_commandID(commandID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_commandID;
    }

private:
    uint64_t m_commandID;
};

class UnapplyEditCommand {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UnapplyEditCommand; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UnapplyEditCommand(uint64_t commandID)
        : m_commandID(commandID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_commandID;
    }

private:
    uint64_t m_commandID;
};

class DidSetPageZoomFactor {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidSetPageZoomFactor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidSetPageZoomFactor(double zoomFactor)
        : m_zoomFactor(zoomFactor)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_zoomFactor;
    }

private:
    double m_zoomFactor;
};

class DidSetTextZoomFactor {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidSetTextZoomFactor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidSetTextZoomFactor(double zoomFactor)
        : m_zoomFactor(zoomFactor)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_zoomFactor;
    }

private:
    double m_zoomFactor;
};

class WindowScreenDidChange {
public:
    using Arguments = std::tuple<uint32_t, std::optional<unsigned>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WindowScreenDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WindowScreenDidChange(uint32_t displayID, const std::optional<unsigned>& nominalFramesPerSecond)
        : m_displayID(displayID)
        , m_nominalFramesPerSecond(nominalFramesPerSecond)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_displayID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nominalFramesPerSecond;
    }

private:
    uint32_t m_displayID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<unsigned>& m_nominalFramesPerSecond;
};

class AccessibilitySettingsDidChange {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AccessibilitySettingsDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AccessibilitySettingsDidChange()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidScalePage {
public:
    using Arguments = std::tuple<double, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidScalePage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidScalePage(double scale, const WebCore::IntPoint& origin)
        : m_scale(scale)
        , m_origin(origin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scale;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    double m_scale;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_origin;
};

class DidScalePageInViewCoordinates {
public:
    using Arguments = std::tuple<double, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidScalePageInViewCoordinates; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidScalePageInViewCoordinates(double scale, const WebCore::IntPoint& origin)
        : m_scale(scale)
        , m_origin(origin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scale;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    double m_scale;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_origin;
};

class DidScalePageRelativeToScrollPosition {
public:
    using Arguments = std::tuple<double, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidScalePageRelativeToScrollPosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidScalePageRelativeToScrollPosition(double scale, const WebCore::IntPoint& origin)
        : m_scale(scale)
        , m_origin(origin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scale;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_origin;
    }

private:
    double m_scale;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_origin;
};

class DidScaleView {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidScaleView; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidScaleView(double scale)
        : m_scale(scale)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scale;
    }

private:
    double m_scale;
};

class SetUseFixedLayout {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetUseFixedLayout; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUseFixedLayout(bool fixed)
        : m_fixed(fixed)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_fixed;
    }

private:
    bool m_fixed;
};

class SetFixedLayoutSize {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetFixedLayoutSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetFixedLayoutSize(const WebCore::IntSize& size)
        : m_size(size)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_size;
};

class SetDefaultUnobscuredSize {
public:
    using Arguments = std::tuple<WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetDefaultUnobscuredSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDefaultUnobscuredSize(const WebCore::FloatSize& size)
        : m_size(size)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
};

class SetMinimumUnobscuredSize {
public:
    using Arguments = std::tuple<WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMinimumUnobscuredSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMinimumUnobscuredSize(const WebCore::FloatSize& size)
        : m_size(size)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
};

class SetMaximumUnobscuredSize {
public:
    using Arguments = std::tuple<WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMaximumUnobscuredSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMaximumUnobscuredSize(const WebCore::FloatSize& size)
        : m_size(size)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
};

class ListenForLayoutMilestones {
public:
    using Arguments = std::tuple<OptionSet<WebCore::LayoutMilestone>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ListenForLayoutMilestones; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ListenForLayoutMilestones(const OptionSet<WebCore::LayoutMilestone>& layoutMilestones)
        : m_layoutMilestones(layoutMilestones)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_layoutMilestones;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::LayoutMilestone>& m_layoutMilestones;
};

class SetSuppressScrollbarAnimations {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetSuppressScrollbarAnimations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSuppressScrollbarAnimations(bool suppressAnimations)
        : m_suppressAnimations(suppressAnimations)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_suppressAnimations;
    }

private:
    bool m_suppressAnimations;
};

class SetEnableVerticalRubberBanding {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetEnableVerticalRubberBanding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetEnableVerticalRubberBanding(bool enableVerticalRubberBanding)
        : m_enableVerticalRubberBanding(enableVerticalRubberBanding)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enableVerticalRubberBanding;
    }

private:
    bool m_enableVerticalRubberBanding;
};

class SetEnableHorizontalRubberBanding {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetEnableHorizontalRubberBanding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetEnableHorizontalRubberBanding(bool enableHorizontalRubberBanding)
        : m_enableHorizontalRubberBanding(enableHorizontalRubberBanding)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enableHorizontalRubberBanding;
    }

private:
    bool m_enableHorizontalRubberBanding;
};

class SetBackgroundExtendsBeyondPage {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetBackgroundExtendsBeyondPage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetBackgroundExtendsBeyondPage(bool backgroundExtendsBeyondPage)
        : m_backgroundExtendsBeyondPage(backgroundExtendsBeyondPage)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_backgroundExtendsBeyondPage;
    }

private:
    bool m_backgroundExtendsBeyondPage;
};

class SetPaginationMode {
public:
    using Arguments = std::tuple<WebCore::PaginationMode>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetPaginationMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPaginationMode(WebCore::PaginationMode mode)
        : m_mode(mode)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mode;
    }

private:
    WebCore::PaginationMode m_mode;
};

class SetPaginationBehavesLikeColumns {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetPaginationBehavesLikeColumns; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPaginationBehavesLikeColumns(bool behavesLikeColumns)
        : m_behavesLikeColumns(behavesLikeColumns)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_behavesLikeColumns;
    }

private:
    bool m_behavesLikeColumns;
};

class SetPageLength {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetPageLength; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetPageLength(double pageLength)
        : m_pageLength(pageLength)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pageLength;
    }

private:
    double m_pageLength;
};

class SetGapBetweenPages {
public:
    using Arguments = std::tuple<double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetGapBetweenPages; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetGapBetweenPages(double gap)
        : m_gap(gap)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_gap;
    }

private:
    double m_gap;
};

class PostInjectedBundleMessage {
public:
    using Arguments = std::tuple<String, WebKit::UserData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PostInjectedBundleMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PostInjectedBundleMessage(const String& messageName, const WebKit::UserData& messageBody)
        : m_messageName(messageName)
        , m_messageBody(messageBody)
    {
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

class FindString {
public:
    using Arguments = std::tuple<String, OptionSet<WebKit::FindOptions>, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FindString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_FindStringReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::FrameIdentifier>, Vector<WebCore::IntRect>, uint32_t, int32_t, bool>;
    using Reply = CompletionHandler<void(std::optional<WebCore::FrameIdentifier>&&, Vector<WebCore::IntRect>&&, uint32_t, int32_t, bool)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::FrameIdentifier>, Vector<WebCore::IntRect>, uint32_t, int32_t, bool>, IPC::Error>;
    FindString(const String& string, const OptionSet<WebKit::FindOptions>& findOptions, const unsigned& maxMatchCount)
        : m_string(string)
        , m_findOptions(findOptions)
        , m_maxMatchCount(maxMatchCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_string;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_findOptions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_maxMatchCount;
    }

private:
    const String& m_string;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::FindOptions>& m_findOptions;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_maxMatchCount;
};

#if ENABLE(IMAGE_ANALYSIS)
class FindStringIncludingImages {
public:
    using Arguments = std::tuple<String, OptionSet<WebKit::FindOptions>, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FindStringIncludingImages; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_FindStringIncludingImagesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::FrameIdentifier>, Vector<WebCore::IntRect>, uint32_t, int32_t, bool>;
    using Reply = CompletionHandler<void(std::optional<WebCore::FrameIdentifier>&&, Vector<WebCore::IntRect>&&, uint32_t, int32_t, bool)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::FrameIdentifier>, Vector<WebCore::IntRect>, uint32_t, int32_t, bool>, IPC::Error>;
    FindStringIncludingImages(const String& string, const OptionSet<WebKit::FindOptions>& findOptions, const unsigned& maxMatchCount)
        : m_string(string)
        , m_findOptions(findOptions)
        , m_maxMatchCount(maxMatchCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_string;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_findOptions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_maxMatchCount;
    }

private:
    const String& m_string;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::FindOptions>& m_findOptions;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_maxMatchCount;
};
#endif

class FindStringMatches {
public:
    using Arguments = std::tuple<String, OptionSet<WebKit::FindOptions>, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FindStringMatches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_FindStringMatchesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<Vector<WebCore::IntRect>>, int32_t>;
    using Reply = CompletionHandler<void(Vector<Vector<WebCore::IntRect>>&&, int32_t)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<Vector<WebCore::IntRect>>, int32_t>, IPC::Error>;
    FindStringMatches(const String& string, const OptionSet<WebKit::FindOptions>& findOptions, const unsigned& maxMatchCount)
        : m_string(string)
        , m_findOptions(findOptions)
        , m_maxMatchCount(maxMatchCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_string;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_findOptions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_maxMatchCount;
    }

private:
    const String& m_string;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::FindOptions>& m_findOptions;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_maxMatchCount;
};

class GetImageForFindMatch {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetImageForFindMatch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit GetImageForFindMatch(uint32_t matchIndex)
        : m_matchIndex(matchIndex)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_matchIndex;
    }

private:
    uint32_t m_matchIndex;
};

class SelectFindMatch {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SelectFindMatch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SelectFindMatch(uint32_t matchIndex)
        : m_matchIndex(matchIndex)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_matchIndex;
    }

private:
    uint32_t m_matchIndex;
};

class IndicateFindMatch {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_IndicateFindMatch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit IndicateFindMatch(uint32_t matchIndex)
        : m_matchIndex(matchIndex)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_matchIndex;
    }

private:
    uint32_t m_matchIndex;
};

class HideFindUI {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HideFindUI; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    HideFindUI()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class CountStringMatches {
public:
    using Arguments = std::tuple<String, OptionSet<WebKit::FindOptions>, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CountStringMatches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CountStringMatchesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint32_t>;
    using Reply = CompletionHandler<void(uint32_t)>;
    using Promise = WTF::NativePromise<uint32_t, IPC::Error>;
    CountStringMatches(const String& string, const OptionSet<WebKit::FindOptions>& findOptions, const unsigned& maxMatchCount)
        : m_string(string)
        , m_findOptions(findOptions)
        , m_maxMatchCount(maxMatchCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_string;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_findOptions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_maxMatchCount;
    }

private:
    const String& m_string;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::FindOptions>& m_findOptions;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_maxMatchCount;
};

class ReplaceMatches {
public:
    using Arguments = std::tuple<Vector<uint32_t>, String, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ReplaceMatches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ReplaceMatchesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    using Promise = WTF::NativePromise<uint64_t, IPC::Error>;
    ReplaceMatches(const Vector<uint32_t>& matchIndices, const String& replacementText, bool selectionOnly)
        : m_matchIndices(matchIndices)
        , m_replacementText(replacementText)
        , m_selectionOnly(selectionOnly)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_matchIndices;
        encoder << m_replacementText;
        encoder << m_selectionOnly;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint32_t>& m_matchIndices;
    const String& m_replacementText;
    bool m_selectionOnly;
};

class FindRectsForStringMatches {
public:
    using Arguments = std::tuple<String, OptionSet<WebKit::FindOptions>, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FindRectsForStringMatches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_FindRectsForStringMatchesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::FloatRect>>;
    using Reply = CompletionHandler<void(Vector<WebCore::FloatRect>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::FloatRect>, IPC::Error>;
    FindRectsForStringMatches(const String& string, const OptionSet<WebKit::FindOptions>& findOptions, const unsigned& maxMatchCount)
        : m_string(string)
        , m_findOptions(findOptions)
        , m_maxMatchCount(maxMatchCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_string;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_findOptions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_maxMatchCount;
    }

private:
    const String& m_string;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::FindOptions>& m_findOptions;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_maxMatchCount;
};

class FindTextRangesForStringMatches {
public:
    using Arguments = std::tuple<String, OptionSet<WebKit::FindOptions>, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FindTextRangesForStringMatches; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_FindTextRangesForStringMatchesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::WebFoundTextRange>>;
    using Reply = CompletionHandler<void(Vector<WebKit::WebFoundTextRange>&&)>;
    using Promise = WTF::NativePromise<Vector<WebKit::WebFoundTextRange>, IPC::Error>;
    FindTextRangesForStringMatches(const String& string, const OptionSet<WebKit::FindOptions>& findOptions, const unsigned& maxMatchCount)
        : m_string(string)
        , m_findOptions(findOptions)
        , m_maxMatchCount(maxMatchCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_string;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_findOptions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_maxMatchCount;
    }

private:
    const String& m_string;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::FindOptions>& m_findOptions;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_maxMatchCount;
};

class ReplaceFoundTextRangeWithString {
public:
    using Arguments = std::tuple<WebKit::WebFoundTextRange, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ReplaceFoundTextRangeWithString; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReplaceFoundTextRangeWithString(const WebKit::WebFoundTextRange& range, const String& string)
        : m_range(range)
        , m_string(string)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
        encoder << m_string;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebFoundTextRange& m_range;
    const String& m_string;
};

class DecorateTextRangeWithStyle {
public:
    using Arguments = std::tuple<WebKit::WebFoundTextRange, WebKit::FindDecorationStyle>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DecorateTextRangeWithStyle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DecorateTextRangeWithStyle(const WebKit::WebFoundTextRange& range, WebKit::FindDecorationStyle style)
        : m_range(range)
        , m_style(style)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
        encoder << m_style;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebFoundTextRange& m_range;
    WebKit::FindDecorationStyle m_style;
};

class ScrollTextRangeToVisible {
public:
    using Arguments = std::tuple<WebKit::WebFoundTextRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ScrollTextRangeToVisible; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ScrollTextRangeToVisible(const WebKit::WebFoundTextRange& range)
        : m_range(range)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebFoundTextRange& m_range;
};

class ClearAllDecoratedFoundText {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ClearAllDecoratedFoundText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearAllDecoratedFoundText()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class DidBeginTextSearchOperation {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidBeginTextSearchOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidBeginTextSearchOperation()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RequestRectForFoundTextRange {
public:
    using Arguments = std::tuple<WebKit::WebFoundTextRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestRectForFoundTextRange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestRectForFoundTextRangeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::FloatRect>;
    using Reply = CompletionHandler<void(WebCore::FloatRect&&)>;
    using Promise = WTF::NativePromise<WebCore::FloatRect, IPC::Error>;
    explicit RequestRectForFoundTextRange(const WebKit::WebFoundTextRange& range)
        : m_range(range)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebFoundTextRange& m_range;
};

class AddLayerForFindOverlay {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AddLayerForFindOverlay; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_AddLayerForFindOverlayReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::PlatformLayerIdentifier>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::PlatformLayerIdentifier>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::PlatformLayerIdentifier>, IPC::Error>;
    AddLayerForFindOverlay()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RemoveLayerForFindOverlay {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RemoveLayerForFindOverlay; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RemoveLayerForFindOverlayReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    RemoveLayerForFindOverlay()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
class PerformDragControllerAction {
public:
    using Arguments = std::tuple<WebKit::DragControllerAction, WebCore::IntPoint, WebCore::IntPoint, OptionSet<WebCore::DragOperation>, WebCore::SelectionData, OptionSet<WebCore::DragApplicationFlags>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PerformDragControllerAction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PerformDragControllerActionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::DragOperation>, WebCore::DragHandlingMethod, bool, unsigned, WebCore::IntRect, WebCore::IntRect, std::optional<WebCore::RemoteUserInputEventData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::DragOperation>, WebCore::DragHandlingMethod, bool, unsigned&&, WebCore::IntRect&&, WebCore::IntRect&&, std::optional<WebCore::RemoteUserInputEventData>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::DragOperation>, WebCore::DragHandlingMethod, bool, unsigned, WebCore::IntRect, WebCore::IntRect, std::optional<WebCore::RemoteUserInputEventData>>, IPC::Error>;
    PerformDragControllerAction(WebKit::DragControllerAction action, const WebCore::IntPoint& clientPosition, const WebCore::IntPoint& globalPosition, const OptionSet<WebCore::DragOperation>& draggingSourceOperationMask, const WebCore::SelectionData& selection, const OptionSet<WebCore::DragApplicationFlags>& flags)
        : m_action(action)
        , m_clientPosition(clientPosition)
        , m_globalPosition(globalPosition)
        , m_draggingSourceOperationMask(draggingSourceOperationMask)
        , m_selection(selection)
        , m_flags(flags)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_action;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_globalPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_draggingSourceOperationMask;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_selection;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_flags;
    }

private:
    WebKit::DragControllerAction m_action;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_clientPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_globalPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::DragOperation>& m_draggingSourceOperationMask;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SelectionData& m_selection;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::DragApplicationFlags>& m_flags;
};
#endif

#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
class PerformDragControllerAction {
public:
    using Arguments = std::tuple<std::optional<WebCore::FrameIdentifier>, WebKit::DragControllerAction, WebCore::DragData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PerformDragControllerAction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PerformDragControllerActionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::DragOperation>, WebCore::DragHandlingMethod, bool, unsigned, WebCore::IntRect, WebCore::IntRect, std::optional<WebCore::RemoteUserInputEventData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::DragOperation>, WebCore::DragHandlingMethod, bool, unsigned&&, WebCore::IntRect&&, WebCore::IntRect&&, std::optional<WebCore::RemoteUserInputEventData>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::DragOperation>, WebCore::DragHandlingMethod, bool, unsigned, WebCore::IntRect, WebCore::IntRect, std::optional<WebCore::RemoteUserInputEventData>>, IPC::Error>;
    PerformDragControllerAction(const std::optional<WebCore::FrameIdentifier>& frameID, WebKit::DragControllerAction action, const WebCore::DragData& dragData)
        : m_frameID(frameID)
        , m_action(action)
        , m_dragData(dragData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_action;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dragData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    WebKit::DragControllerAction m_action;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DragData& m_dragData;
};
#endif

#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
class PerformDragOperation {
public:
    using Arguments = std::tuple<WebCore::DragData, WebKit::SandboxExtensionHandle, Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PerformDragOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PerformDragOperationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    PerformDragOperation(const WebCore::DragData& dragData, WebKit::SandboxExtensionHandle&& sandboxExtensionHandle, Vector<WebKit::SandboxExtensionHandle>&& sandboxExtensionsForUpload)
        : m_dragData(dragData)
        , m_sandboxExtensionHandle(WTFMove(sandboxExtensionHandle))
        , m_sandboxExtensionsForUpload(WTFMove(sandboxExtensionsForUpload))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dragData;
        encoder << WTFMove(m_sandboxExtensionHandle);
        encoder << WTFMove(m_sandboxExtensionsForUpload);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DragData& m_dragData;
    WebKit::SandboxExtensionHandle&& m_sandboxExtensionHandle;
    Vector<WebKit::SandboxExtensionHandle>&& m_sandboxExtensionsForUpload;
};
#endif

#if ENABLE(DRAG_SUPPORT)
class DidStartDrag {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidStartDrag; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidStartDrag()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(DRAG_SUPPORT)
class DragEnded {
public:
    using Arguments = std::tuple<std::optional<WebCore::FrameIdentifier>, WebCore::IntPoint, WebCore::IntPoint, OptionSet<WebCore::DragOperation>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DragEnded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DragEndedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::RemoteUserInputEventData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::RemoteUserInputEventData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::RemoteUserInputEventData>, IPC::Error>;
    DragEnded(const std::optional<WebCore::FrameIdentifier>& frameID, const WebCore::IntPoint& clientPosition, const WebCore::IntPoint& globalPosition, const OptionSet<WebCore::DragOperation>& dragOperationMask)
        : m_frameID(frameID)
        , m_clientPosition(clientPosition)
        , m_globalPosition(globalPosition)
        , m_dragOperationMask(dragOperationMask)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_globalPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dragOperationMask;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_clientPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_globalPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::DragOperation>& m_dragOperationMask;
};
#endif

#if ENABLE(DRAG_SUPPORT)
class DragCancelled {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DragCancelled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DragCancelled()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(MODEL_PROCESS)
class RequestInteractiveModelElementAtPoint {
public:
    using Arguments = std::tuple<WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestInteractiveModelElementAtPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RequestInteractiveModelElementAtPoint(const WebCore::IntPoint& clientPosition)
        : m_clientPosition(clientPosition)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientPosition;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_clientPosition;
};
#endif

#if ENABLE(MODEL_PROCESS)
class StageModeSessionDidUpdate {
public:
    using Arguments = std::tuple<std::optional<WebCore::NodeIdentifier>, WebCore::TransformationMatrix>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StageModeSessionDidUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StageModeSessionDidUpdate(const std::optional<WebCore::NodeIdentifier>& nodeID, const WebCore::TransformationMatrix& transform)
        : m_nodeID(nodeID)
        , m_transform(transform)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nodeID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_transform;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::NodeIdentifier>& m_nodeID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TransformationMatrix& m_transform;
};
#endif

#if ENABLE(MODEL_PROCESS)
class StageModeSessionDidEnd {
public:
    using Arguments = std::tuple<std::optional<WebCore::NodeIdentifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StageModeSessionDidEnd; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit StageModeSessionDidEnd(const std::optional<WebCore::NodeIdentifier>& nodeID)
        : m_nodeID(nodeID)
    {
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

#if ENABLE(MODEL_PROCESS) && ENABLE(DRAG_SUPPORT)
class ModelDragEnded {
public:
    using Arguments = std::tuple<WebCore::NodeIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ModelDragEnded; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ModelDragEnded(const WebCore::NodeIdentifier& nodeID)
        : m_nodeID(nodeID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nodeID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NodeIdentifier& m_nodeID;
};
#endif

#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
class RequestDragStart {
public:
    using Arguments = std::tuple<std::optional<WebCore::FrameIdentifier>, WebCore::IntPoint, WebCore::IntPoint, OptionSet<WebCore::DragSourceAction>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestDragStart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestDragStartReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::DragInitiationResult>;
    using Reply = CompletionHandler<void(WebKit::DragInitiationResult&&)>;
    using Promise = WTF::NativePromise<WebKit::DragInitiationResult, IPC::Error>;
    RequestDragStart(const std::optional<WebCore::FrameIdentifier>& remoteFrameID, const WebCore::IntPoint& clientPosition, const WebCore::IntPoint& globalPosition, const OptionSet<WebCore::DragSourceAction>& allowedActionsMask)
        : m_remoteFrameID(remoteFrameID)
        , m_clientPosition(clientPosition)
        , m_globalPosition(globalPosition)
        , m_allowedActionsMask(allowedActionsMask)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_remoteFrameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_globalPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_allowedActionsMask;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_remoteFrameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_clientPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_globalPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::DragSourceAction>& m_allowedActionsMask;
};
#endif

#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
class RequestAdditionalItemsForDragSession {
public:
    using Arguments = std::tuple<std::optional<WebCore::FrameIdentifier>, WebCore::IntPoint, WebCore::IntPoint, OptionSet<WebCore::DragSourceAction>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestAdditionalItemsForDragSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestAdditionalItemsForDragSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::DragInitiationResult>;
    using Reply = CompletionHandler<void(WebKit::DragInitiationResult&&)>;
    using Promise = WTF::NativePromise<WebKit::DragInitiationResult, IPC::Error>;
    RequestAdditionalItemsForDragSession(const std::optional<WebCore::FrameIdentifier>& rootFrameID, const WebCore::IntPoint& clientPosition, const WebCore::IntPoint& globalPosition, const OptionSet<WebCore::DragSourceAction>& allowedActionsMask)
        : m_rootFrameID(rootFrameID)
        , m_clientPosition(clientPosition)
        , m_globalPosition(globalPosition)
        , m_allowedActionsMask(allowedActionsMask)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rootFrameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_clientPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_globalPosition;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_allowedActionsMask;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FrameIdentifier>& m_rootFrameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_clientPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntPoint& m_globalPosition;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::DragSourceAction>& m_allowedActionsMask;
};
#endif

#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
class InsertDroppedImagePlaceholders {
public:
    using Arguments = std::tuple<Vector<WebCore::IntSize>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_InsertDroppedImagePlaceholders; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_InsertDroppedImagePlaceholdersReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::IntRect>, std::optional<WebCore::TextIndicatorData>>;
    using Reply = CompletionHandler<void(Vector<WebCore::IntRect>&&, std::optional<WebCore::TextIndicatorData>&&)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<WebCore::IntRect>, std::optional<WebCore::TextIndicatorData>>, IPC::Error>;
    explicit InsertDroppedImagePlaceholders(const Vector<WebCore::IntSize>& imageSize)
        : m_imageSize(imageSize)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::IntSize>& m_imageSize;
};
#endif

#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
class DidConcludeDrop {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidConcludeDrop; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidConcludeDrop()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class InsertTextPlaceholder {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_InsertTextPlaceholder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_InsertTextPlaceholderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ElementContext>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ElementContext>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ElementContext>, IPC::Error>;
    explicit InsertTextPlaceholder(const WebCore::IntSize& size)
        : m_size(size)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_size;
};
#endif

#if PLATFORM(COCOA)
class RemoveTextPlaceholder {
public:
    using Arguments = std::tuple<WebCore::ElementContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RemoveTextPlaceholder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RemoveTextPlaceholderReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit RemoveTextPlaceholder(const WebCore::ElementContext& placeholder)
        : m_placeholder(placeholder)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_placeholder;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_placeholder;
};
#endif

class DidChangeSelectedIndexForActivePopupMenu {
public:
    using Arguments = std::tuple<int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidChangeSelectedIndexForActivePopupMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidChangeSelectedIndexForActivePopupMenu(int32_t newIndex)
        : m_newIndex(newIndex)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_newIndex;
    }

private:
    int32_t m_newIndex;
};

class SetTextForActivePopupMenu {
public:
    using Arguments = std::tuple<int32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetTextForActivePopupMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetTextForActivePopupMenu(int32_t index)
        : m_index(index)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_index;
    }

private:
    int32_t m_index;
};

#if PLATFORM(GTK)
class FailedToShowPopupMenu {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FailedToShowPopupMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FailedToShowPopupMenu()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(CONTEXT_MENUS)
class DidDismissContextMenu {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidDismissContextMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidDismissContextMenu()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(CONTEXT_MENUS)
class DidSelectItemFromActiveContextMenu {
public:
    using Arguments = std::tuple<WebKit::WebContextMenuItemData>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidSelectItemFromActiveContextMenu; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidSelectItemFromActiveContextMenu(const WebKit::WebContextMenuItemData& menuItem)
        : m_menuItem(menuItem)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_menuItem;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebContextMenuItemData& m_menuItem;
};
#endif

#if ENABLE(CONTEXT_MENUS)
class ContextMenuForKeyEvent {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ContextMenuForKeyEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ContextMenuForKeyEvent()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidChooseFilesForOpenPanelWithDisplayStringAndIcon {
public:
    using Arguments = std::tuple<Vector<String>, String, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidChooseFilesForOpenPanelWithDisplayStringAndIcon; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidChooseFilesForOpenPanelWithDisplayStringAndIcon(const Vector<String>& fileURLs, const String& displayString, const std::span<const uint8_t>& iconData)
        : m_fileURLs(fileURLs)
        , m_displayString(displayString)
        , m_iconData(iconData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fileURLs;
        encoder << m_displayString;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_iconData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_fileURLs;
    const String& m_displayString;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_iconData;
};
#endif

class DidChooseFilesForOpenPanel {
public:
    using Arguments = std::tuple<Vector<String>, Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidChooseFilesForOpenPanel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidChooseFilesForOpenPanel(const Vector<String>& fileURLs, const Vector<String>& replacementURLs)
        : m_fileURLs(fileURLs)
        , m_replacementURLs(replacementURLs)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fileURLs;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_replacementURLs;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_fileURLs;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_replacementURLs;
};

class DidCancelForOpenPanel {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidCancelForOpenPanel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidCancelForOpenPanel()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(SANDBOX_EXTENSIONS)
class ExtendSandboxForFilesFromOpenPanel {
public:
    using Arguments = std::tuple<Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ExtendSandboxForFilesFromOpenPanel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ExtendSandboxForFilesFromOpenPanel(Vector<WebKit::SandboxExtensionHandle>&& sandboxExtensions)
        : m_sandboxExtensions(WTFMove(sandboxExtensions))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_sandboxExtensions);
    }

private:
    Vector<WebKit::SandboxExtensionHandle>&& m_sandboxExtensions;
};
#endif

class AdvanceToNextMisspelling {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AdvanceToNextMisspelling; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit AdvanceToNextMisspelling(bool startBeforeSelection)
        : m_startBeforeSelection(startBeforeSelection)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_startBeforeSelection;
    }

private:
    bool m_startBeforeSelection;
};

class ChangeSpellingToWord {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ChangeSpellingToWord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ChangeSpellingToWord(const String& word)
        : m_word(word)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_word;
    }

private:
    const String& m_word;
};

class DidFinishCheckingText {
public:
    using Arguments = std::tuple<WebKit::TextCheckerRequestID, Vector<WebCore::TextCheckingResult>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidFinishCheckingText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFinishCheckingText(const WebKit::TextCheckerRequestID& requestID, const Vector<WebCore::TextCheckingResult>& result)
        : m_requestID(requestID)
        , m_result(result)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_requestID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
    }

private:
    const WebKit::TextCheckerRequestID& m_requestID;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::TextCheckingResult>& m_result;
};

class DidCancelCheckingText {
public:
    using Arguments = std::tuple<WebKit::TextCheckerRequestID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidCancelCheckingText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DidCancelCheckingText(const WebKit::TextCheckerRequestID& requestID)
        : m_requestID(requestID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_requestID;
    }

private:
    const WebKit::TextCheckerRequestID& m_requestID;
};

#if USE(APPKIT)
class UppercaseWord {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UppercaseWord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UppercaseWord(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};
#endif

#if USE(APPKIT)
class LowercaseWord {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LowercaseWord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit LowercaseWord(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};
#endif

#if USE(APPKIT)
class CapitalizeWord {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CapitalizeWord; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CapitalizeWord(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};
#endif

#if PLATFORM(COCOA)
class SetSmartInsertDeleteEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetSmartInsertDeleteEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSmartInsertDeleteEnabled(bool isSmartInsertDeleteEnabled)
        : m_isSmartInsertDeleteEnabled(isSmartInsertDeleteEnabled)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isSmartInsertDeleteEnabled;
    }

private:
    bool m_isSmartInsertDeleteEnabled;
};
#endif

#if ENABLE(GEOLOCATION)
class DidReceiveGeolocationPermissionDecision {
public:
    using Arguments = std::tuple<WebKit::GeolocationIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidReceiveGeolocationPermissionDecision; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidReceiveGeolocationPermissionDecision(const WebKit::GeolocationIdentifier& geolocationID, const String& authorizationToken)
        : m_geolocationID(geolocationID)
        , m_authorizationToken(authorizationToken)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_geolocationID;
        encoder << m_authorizationToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::GeolocationIdentifier& m_geolocationID;
    const String& m_authorizationToken;
};
#endif

#if ENABLE(MEDIA_STREAM)
class UserMediaAccessWasGranted {
public:
    using Arguments = std::tuple<WebCore::UserMediaRequestIdentifier, WebCore::CaptureDevice, WebCore::CaptureDevice, WebCore::MediaDeviceHashSalts, Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UserMediaAccessWasGranted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UserMediaAccessWasGrantedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UserMediaAccessWasGranted(const WebCore::UserMediaRequestIdentifier& userMediaID, const WebCore::CaptureDevice& audioDevice, const WebCore::CaptureDevice& videoDevice, const WebCore::MediaDeviceHashSalts& mediaDeviceIdentifierHashSalts, Vector<WebKit::SandboxExtensionHandle>&& sandboxExtensionHandles)
        : m_userMediaID(userMediaID)
        , m_audioDevice(audioDevice)
        , m_videoDevice(videoDevice)
        , m_mediaDeviceIdentifierHashSalts(mediaDeviceIdentifierHashSalts)
        , m_sandboxExtensionHandles(WTFMove(sandboxExtensionHandles))
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMediaID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_audioDevice;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_videoDevice;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mediaDeviceIdentifierHashSalts;
        encoder << WTFMove(m_sandboxExtensionHandles);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::UserMediaRequestIdentifier& m_userMediaID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CaptureDevice& m_audioDevice;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CaptureDevice& m_videoDevice;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaDeviceHashSalts& m_mediaDeviceIdentifierHashSalts;
    Vector<WebKit::SandboxExtensionHandle>&& m_sandboxExtensionHandles;
};
#endif

#if ENABLE(MEDIA_STREAM)
class UserMediaAccessWasDenied {
public:
    using Arguments = std::tuple<WebCore::UserMediaRequestIdentifier, uint64_t, String, WebCore::MediaConstraintType>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UserMediaAccessWasDenied; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UserMediaAccessWasDenied(const WebCore::UserMediaRequestIdentifier& userMediaID, uint64_t reason, const String& messsage, WebCore::MediaConstraintType invalidConstraint)
        : m_userMediaID(userMediaID)
        , m_reason(reason)
        , m_messsage(messsage)
        , m_invalidConstraint(invalidConstraint)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_userMediaID;
        encoder << m_reason;
        encoder << m_messsage;
        encoder << m_invalidConstraint;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::UserMediaRequestIdentifier& m_userMediaID;
    uint64_t m_reason;
    const String& m_messsage;
    WebCore::MediaConstraintType m_invalidConstraint;
};
#endif

#if ENABLE(MEDIA_STREAM)
class CaptureDevicesChanged {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CaptureDevicesChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CaptureDevicesChanged()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(MEDIA_STREAM)
class VoiceActivityDetected {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_VoiceActivityDetected; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    VoiceActivityDetected()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
class SetOrientationForMediaCapture {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetOrientationForMediaCapture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetOrientationForMediaCapture(uint64_t rotation)
        : m_rotation(rotation)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_rotation;
    }

private:
    uint64_t m_rotation;
};
#endif

#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
class SetMockCaptureDevicesInterrupted {
public:
    using Arguments = std::tuple<bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMockCaptureDevicesInterrupted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetMockCaptureDevicesInterrupted(bool isCameraInterrupted, bool isMicrophoneInterrupted)
        : m_isCameraInterrupted(isCameraInterrupted)
        , m_isMicrophoneInterrupted(isMicrophoneInterrupted)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isCameraInterrupted;
        encoder << m_isMicrophoneInterrupted;
    }

private:
    bool m_isCameraInterrupted;
    bool m_isMicrophoneInterrupted;
};
#endif

#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
class TriggerMockCaptureConfigurationChange {
public:
    using Arguments = std::tuple<bool, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TriggerMockCaptureConfigurationChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TriggerMockCaptureConfigurationChange(bool forCamera, bool forMicrophone, bool forDisplay)
        : m_forCamera(forCamera)
        , m_forMicrophone(forMicrophone)
        , m_forDisplay(forDisplay)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_forCamera;
        encoder << m_forMicrophone;
        encoder << m_forDisplay;
    }

private:
    bool m_forCamera;
    bool m_forMicrophone;
    bool m_forDisplay;
};
#endif

#if ENABLE(ENCRYPTED_MEDIA)
class MediaKeySystemWasGranted {
public:
    using Arguments = std::tuple<WebCore::MediaKeySystemRequestIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_MediaKeySystemWasGranted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    MediaKeySystemWasGranted(const WebCore::MediaKeySystemRequestIdentifier& mediaKeySystemID, const String& mediaKeysHashSalt)
        : m_mediaKeySystemID(mediaKeySystemID)
        , m_mediaKeysHashSalt(mediaKeysHashSalt)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mediaKeySystemID;
        encoder << m_mediaKeysHashSalt;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaKeySystemRequestIdentifier& m_mediaKeySystemID;
    const String& m_mediaKeysHashSalt;
};
#endif

#if ENABLE(ENCRYPTED_MEDIA)
class MediaKeySystemWasDenied {
public:
    using Arguments = std::tuple<WebCore::MediaKeySystemRequestIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_MediaKeySystemWasDenied; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    MediaKeySystemWasDenied(const WebCore::MediaKeySystemRequestIdentifier& mediaKeySystemID, const String& message)
        : m_mediaKeySystemID(mediaKeySystemID)
        , m_message(message)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_mediaKeySystemID;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaKeySystemRequestIdentifier& m_mediaKeySystemID;
    const String& m_message;
};
#endif

class RequestMediaPlaybackState {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestMediaPlaybackState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestMediaPlaybackStateReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::MediaPlaybackState>;
    using Reply = CompletionHandler<void(WebKit::MediaPlaybackState)>;
    using Promise = WTF::NativePromise<WebKit::MediaPlaybackState, IPC::Error>;
    RequestMediaPlaybackState()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PauseAllMediaPlayback {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PauseAllMediaPlayback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PauseAllMediaPlaybackReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PauseAllMediaPlayback()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SuspendAllMediaPlayback {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SuspendAllMediaPlayback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SuspendAllMediaPlaybackReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SuspendAllMediaPlayback()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ResumeAllMediaPlayback {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ResumeAllMediaPlayback; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ResumeAllMediaPlaybackReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ResumeAllMediaPlayback()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SwipeAnimationDidStart {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SwipeAnimationDidStart; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SwipeAnimationDidStart()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SwipeAnimationDidEnd {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SwipeAnimationDidEnd; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SwipeAnimationDidEnd()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class BeginPrinting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_BeginPrinting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BeginPrinting(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
};

class BeginPrintingDuringDOMPrintOperation {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_BeginPrintingDuringDOMPrintOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BeginPrintingDuringDOMPrintOperation(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
};

class EndPrinting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_EndPrinting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_EndPrintingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    EndPrinting()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class EndPrintingDuringDOMPrintOperation {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_EndPrintingDuringDOMPrintOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_EndPrintingDuringDOMPrintOperationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    EndPrintingDuringDOMPrintOperation()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ComputePagesForPrinting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ComputePagesForPrinting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ComputePagesForPrintingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::IntRect>, double, WebCore::FloatBoxExtent>;
    using Reply = CompletionHandler<void(Vector<WebCore::IntRect>&&, double, WebCore::FloatBoxExtent&&)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<WebCore::IntRect>, double, WebCore::FloatBoxExtent>, IPC::Error>;
    ComputePagesForPrinting(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
};

class ComputePagesForPrintingDuringDOMPrintOperation {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ComputePagesForPrintingDuringDOMPrintOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ComputePagesForPrintingDuringDOMPrintOperationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::IntRect>, double, WebCore::FloatBoxExtent>;
    using Reply = CompletionHandler<void(Vector<WebCore::IntRect>&&, double, WebCore::FloatBoxExtent&&)>;
    using Promise = WTF::NativePromise<std::tuple<Vector<WebCore::IntRect>, double, WebCore::FloatBoxExtent>, IPC::Error>;
    ComputePagesForPrintingDuringDOMPrintOperation(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
};

#if PLATFORM(COCOA)
class DrawRectToImage {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo, WebCore::IntRect, WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawRectToImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = true;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawRectToImageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ShareableBitmapHandle>, IPC::Error>;
    DrawRectToImage(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo, const WebCore::IntRect& rect, const WebCore::IntSize& imageSize)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
        , m_rect(rect)
        , m_imageSize(imageSize)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_imageSize;
};
#endif

#if PLATFORM(COCOA)
class DrawRectToImageDuringDOMPrintOperation {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo, WebCore::IntRect, WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawRectToImageDuringDOMPrintOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawRectToImageDuringDOMPrintOperationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ShareableBitmapHandle>, IPC::Error>;
    DrawRectToImageDuringDOMPrintOperation(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo, const WebCore::IntRect& rect, const WebCore::IntSize& imageSize)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
        , m_rect(rect)
        , m_imageSize(imageSize)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_rect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_imageSize;
};
#endif

#if PLATFORM(COCOA)
class DrawPagesToPDF {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawPagesToPDF; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawPagesToPDFReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&)>;
    using Promise = WTF::NativePromise<RefPtr<WebCore::SharedBuffer>, IPC::Error>;
    DrawPagesToPDF(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo, uint32_t first, uint32_t count)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
        , m_first(first)
        , m_count(count)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
        encoder << m_first;
        encoder << m_count;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
    uint32_t m_first;
    uint32_t m_count;
};
#endif

#if PLATFORM(COCOA)
class DrawPagesToPDFDuringDOMPrintOperation {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo, uint32_t, uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawPagesToPDFDuringDOMPrintOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawPagesToPDFDuringDOMPrintOperationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&)>;
    using Promise = WTF::NativePromise<RefPtr<WebCore::SharedBuffer>, IPC::Error>;
    DrawPagesToPDFDuringDOMPrintOperation(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo, uint32_t first, uint32_t count)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
        , m_first(first)
        , m_count(count)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
        encoder << m_first;
        encoder << m_count;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
    uint32_t m_first;
    uint32_t m_count;
};
#endif

#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
class ComputePagesForPrintingiOS {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ComputePagesForPrintingiOS; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    ComputePagesForPrintingiOS(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
};
#endif

#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
class DrawToPDFiOS {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawToPDFiOS; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = true;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawToPDFiOSReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&)>;
    using Promise = WTF::NativePromise<RefPtr<WebCore::SharedBuffer>, IPC::Error>;
    DrawToPDFiOS(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo, uint64_t pageCount)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
        , m_pageCount(pageCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
        encoder << m_pageCount;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
    uint64_t m_pageCount;
};
#endif

#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
class DrawToImage {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawToImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = true;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawToImageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ShareableBitmapHandle>, IPC::Error>;
    DrawToImage(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
};
#endif

#if PLATFORM(COCOA)
class DrawToPDF {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::optional<WebCore::FloatRect>, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawToPDF; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawToPDFReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&)>;
    using Promise = WTF::NativePromise<RefPtr<WebCore::SharedBuffer>, IPC::Error>;
    DrawToPDF(const WebCore::FrameIdentifier& frameID, const std::optional<WebCore::FloatRect>& rect, bool allowTransparentBackground)
        : m_frameID(frameID)
        , m_rect(rect)
        , m_allowTransparentBackground(allowTransparentBackground)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        encoder << m_allowTransparentBackground;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatRect>& m_rect;
    bool m_allowTransparentBackground;
};
#endif

#if PLATFORM(COCOA)
class DrawRemoteToPDF {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, std::optional<WebCore::FloatRect>, bool, WebCore::SnapshotIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawRemoteToPDF; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DrawRemoteToPDF(const WebCore::FrameIdentifier& frameID, const std::optional<WebCore::FloatRect>& rect, bool allowTransparentBackground, const WebCore::SnapshotIdentifier& snapshotIdentifier)
        : m_frameID(frameID)
        , m_rect(rect)
        , m_allowTransparentBackground(allowTransparentBackground)
        , m_snapshotIdentifier(snapshotIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
        encoder << m_allowTransparentBackground;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_snapshotIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatRect>& m_rect;
    bool m_allowTransparentBackground;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SnapshotIdentifier& m_snapshotIdentifier;
};
#endif

#if PLATFORM(GTK)
class DrawPagesForPrinting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawPagesForPrinting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawPagesForPrintingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::SharedMemory::Handle>, WebCore::ResourceError>;
    using Reply = CompletionHandler<void(std::optional<WebCore::SharedMemory::Handle>&&, WebCore::ResourceError&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::SharedMemory::Handle>, WebCore::ResourceError>, IPC::Error>;
    DrawPagesForPrinting(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
};
#endif

#if PLATFORM(GTK)
class DrawPagesForPrintingDuringDOMPrintOperation {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::PrintInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DrawPagesForPrintingDuringDOMPrintOperation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DrawPagesForPrintingDuringDOMPrintOperationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::SharedMemory::Handle>, WebCore::ResourceError>;
    using Reply = CompletionHandler<void(std::optional<WebCore::SharedMemory::Handle>&&, WebCore::ResourceError&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::SharedMemory::Handle>, WebCore::ResourceError>, IPC::Error>;
    DrawPagesForPrintingDuringDOMPrintOperation(const WebCore::FrameIdentifier& frameID, const WebKit::PrintInfo& printInfo)
        : m_frameID(frameID)
        , m_printInfo(printInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_printInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::PrintInfo& m_printInfo;
};
#endif

class SetMediaVolume {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMediaVolume; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMediaVolume(float volume)
        : m_volume(volume)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_volume;
    }

private:
    float m_volume;
};

class SetMuted {
public:
    using Arguments = std::tuple<OptionSet<WebCore::MediaProducerMutedState>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMuted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SetMutedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetMuted(const OptionSet<WebCore::MediaProducerMutedState>& muted)
        : m_muted(muted)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_muted;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::MediaProducerMutedState>& m_muted;
};

class SetMayStartMediaWhenInWindow {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMayStartMediaWhenInWindow; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMayStartMediaWhenInWindow(bool mayStartMedia)
        : m_mayStartMedia(mayStartMedia)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mayStartMedia;
    }

private:
    bool m_mayStartMedia;
};

class StopMediaCapture {
public:
    using Arguments = std::tuple<WebCore::MediaProducerMediaCaptureKind>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StopMediaCapture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_StopMediaCaptureReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit StopMediaCapture(WebCore::MediaProducerMediaCaptureKind kind)
        : m_kind(kind)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_kind;
    }

private:
    WebCore::MediaProducerMediaCaptureKind m_kind;
};

class SetCanRunBeforeUnloadConfirmPanel {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCanRunBeforeUnloadConfirmPanel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCanRunBeforeUnloadConfirmPanel(bool canRunBeforeUnloadConfirmPanel)
        : m_canRunBeforeUnloadConfirmPanel(canRunBeforeUnloadConfirmPanel)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_canRunBeforeUnloadConfirmPanel;
    }

private:
    bool m_canRunBeforeUnloadConfirmPanel;
};

class SetCanRunModal {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCanRunModal; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCanRunModal(bool canRunModal)
        : m_canRunModal(canRunModal)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_canRunModal;
    }

private:
    bool m_canRunModal;
};

#if PLATFORM(GTK) || PLATFORM(WPE)
class CancelComposition {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CancelComposition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CancelComposition(const String& text)
        : m_text(text)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
    }

private:
    const String& m_text;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class DeleteSurrounding {
public:
    using Arguments = std::tuple<int64_t, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DeleteSurrounding; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DeleteSurrounding(int64_t offset, const unsigned& characterCount)
        : m_offset(offset)
        , m_characterCount(characterCount)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_offset;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_characterCount;
    }

private:
    int64_t m_offset;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_characterCount;
};
#endif

#if PLATFORM(GTK)
class CollapseSelectionInFrame {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CollapseSelectionInFrame; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit CollapseSelectionInFrame(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};
#endif

class CopyLinkWithHighlight {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CopyLinkWithHighlight; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CopyLinkWithHighlight()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class BindRemoteAccessibilityFrames {
public:
    using Arguments = std::tuple<int, WebCore::FrameIdentifier, Vector<uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_BindRemoteAccessibilityFrames; }
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

class UpdateRemotePageAccessibilityOffset {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateRemotePageAccessibilityOffset; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateRemotePageAccessibilityOffset(const WebCore::FrameIdentifier& frameID, const WebCore::IntPoint& offset)
        : m_frameID(frameID)
        , m_offset(offset)
    {
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

class ResolveAccessibilityHitTestForTesting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ResolveAccessibilityHitTestForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ResolveAccessibilityHitTestForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    ResolveAccessibilityHitTestForTesting(const WebCore::FrameIdentifier& frameID, const WebCore::IntPoint& point)
        : m_frameID(frameID)
        , m_point(point)
    {
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

class EnableAccessibility {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_EnableAccessibility; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnableAccessibility()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if PLATFORM(MAC)
class GetAccessibilityWebProcessDebugInfo {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetAccessibilityWebProcessDebugInfo; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::AXDebugInfo>;
    using Reply = CompletionHandler<void(WebCore::AXDebugInfo&&)>;
    GetAccessibilityWebProcessDebugInfo()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if (PLATFORM(MAC) && ENABLE(ACCESSIBILITY_ISOLATED_TREE))
class ClearAccessibilityIsolatedTree {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ClearAccessibilityIsolatedTree; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearAccessibilityIsolatedTree()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class WindowAndViewFramesChanged {
public:
    using Arguments = std::tuple<WebKit::ViewWindowCoordinates>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WindowAndViewFramesChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit WindowAndViewFramesChanged(const WebKit::ViewWindowCoordinates& coordinates)
        : m_coordinates(coordinates)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_coordinates;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::ViewWindowCoordinates& m_coordinates;
};
#endif

#if PLATFORM(COCOA)
class SetMainFrameIsScrollable {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMainFrameIsScrollable; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMainFrameIsScrollable(bool isScrollable)
        : m_isScrollable(isScrollable)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isScrollable;
    }

private:
    bool m_isScrollable;
};
#endif

#if PLATFORM(COCOA)
class RegisterUIProcessAccessibilityTokens {
public:
    using Arguments = std::tuple<std::span<const uint8_t>, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RegisterUIProcessAccessibilityTokens; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterUIProcessAccessibilityTokens(const std::span<const uint8_t>& elementToken, const std::span<const uint8_t>& windowToken)
        : m_elementToken(elementToken)
        , m_windowToken(windowToken)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_elementToken;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_windowToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_elementToken;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_windowToken;
};
#endif

#if PLATFORM(COCOA)
class GetStringSelectionForPasteboard {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetStringSelectionForPasteboard; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    GetStringSelectionForPasteboard()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class GetDataSelectionForPasteboard {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetDataSelectionForPasteboard; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::SharedBuffer>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::SharedBuffer>&&)>;
    explicit GetDataSelectionForPasteboard(const String& pasteboardType)
        : m_pasteboardType(pasteboardType)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pasteboardType;
    }

private:
    const String& m_pasteboardType;
};
#endif

#if PLATFORM(COCOA)
class ReadSelectionFromPasteboard {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ReadSelectionFromPasteboard; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit ReadSelectionFromPasteboard(const String& pasteboardName)
        : m_pasteboardName(pasteboardName)
    {
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

#if PLATFORM(COCOA)
class ReplaceSelectionWithPasteboardData {
public:
    using Arguments = std::tuple<Vector<String>, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ReplaceSelectionWithPasteboardData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReplaceSelectionWithPasteboardData(const Vector<String>& types, const std::span<const uint8_t>& data)
        : m_types(types)
        , m_data(data)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_types;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_types;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};
#endif

#if (PLATFORM(COCOA) && ENABLE(MULTI_REPRESENTATION_HEIC))
class InsertMultiRepresentationHEIC {
public:
    using Arguments = std::tuple<std::span<const uint8_t>, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_InsertMultiRepresentationHEIC; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    InsertMultiRepresentationHEIC(const std::span<const uint8_t>& data, const String& altText)
        : m_data(data)
        , m_altText(altText)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
        encoder << m_altText;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
    const String& m_altText;
};
#endif

#if PLATFORM(COCOA)
class ShouldDelayWindowOrderingEvent {
public:
    using Arguments = std::tuple<WebKit::WebMouseEvent>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ShouldDelayWindowOrderingEvent; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    explicit ShouldDelayWindowOrderingEvent(const WebKit::WebMouseEvent& event)
        : m_event(event)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebMouseEvent& m_event;
};
#endif

#if PLATFORM(COCOA)
class SetTextAsync {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetTextAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetTextAsync(const String& text)
        : m_text(text)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
    }

private:
    const String& m_text;
};
#endif

#if PLATFORM(COCOA)
class InsertTextAsync {
public:
    using Arguments = std::tuple<String, WebKit::EditingRange, WebKit::InsertTextOptions>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_InsertTextAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    InsertTextAsync(const String& text, const WebKit::EditingRange& replacementRange, const WebKit::InsertTextOptions& options)
        : m_text(text)
        , m_replacementRange(replacementRange)
        , m_options(options)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_replacementRange;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    const String& m_text;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditingRange& m_replacementRange;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::InsertTextOptions& m_options;
};
#endif

#if PLATFORM(COCOA)
class InsertDictatedTextAsync {
public:
    using Arguments = std::tuple<String, WebKit::EditingRange, Vector<WebCore::DictationAlternative>, WebKit::InsertTextOptions>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_InsertDictatedTextAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    InsertDictatedTextAsync(const String& text, const WebKit::EditingRange& replacementRange, const Vector<WebCore::DictationAlternative>& dictationAlternatives, const WebKit::InsertTextOptions& options)
        : m_text(text)
        , m_replacementRange(replacementRange)
        , m_dictationAlternatives(dictationAlternatives)
        , m_options(options)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_replacementRange;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_dictationAlternatives;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    const String& m_text;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditingRange& m_replacementRange;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::DictationAlternative>& m_dictationAlternatives;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::InsertTextOptions& m_options;
};
#endif

#if PLATFORM(COCOA)
class AddDictationAlternative {
public:
    using Arguments = std::tuple<String, WebCore::DictationContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AddDictationAlternative; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_AddDictationAlternativeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    AddDictationAlternative(const String& text, const WebCore::DictationContext& context)
        : m_text(text)
        , m_context(context)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
        encoder << m_context;
    }

private:
    const String& m_text;
    const WebCore::DictationContext& m_context;
};
#endif

#if PLATFORM(COCOA)
class DictationAlternativesAtSelection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DictationAlternativesAtSelection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DictationAlternativesAtSelectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::DictationContext>>;
    using Reply = CompletionHandler<void(Vector<WebCore::DictationContext>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::DictationContext>, IPC::Error>;
    DictationAlternativesAtSelection()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class ClearDictationAlternatives {
public:
    using Arguments = std::tuple<Vector<WebCore::DictationContext>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ClearDictationAlternatives; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ClearDictationAlternatives(const Vector<WebCore::DictationContext>& contexts)
        : m_contexts(contexts)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contexts;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::DictationContext>& m_contexts;
};
#endif

#if PLATFORM(COCOA)
class HasMarkedText {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HasMarkedText; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_HasMarkedTextReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    HasMarkedText()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class GetMarkedRangeAsync {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetMarkedRangeAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetMarkedRangeAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::EditingRange>;
    using Reply = CompletionHandler<void(WebKit::EditingRange&&)>;
    using Promise = WTF::NativePromise<WebKit::EditingRange, IPC::Error>;
    GetMarkedRangeAsync()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class GetSelectedRangeAsync {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetSelectedRangeAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetSelectedRangeAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::EditingRange, WebKit::EditingRange>;
    using Reply = CompletionHandler<void(WebKit::EditingRange&&, WebKit::EditingRange&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebKit::EditingRange, WebKit::EditingRange>, IPC::Error>;
    GetSelectedRangeAsync()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class CharacterIndexForPointAsync {
public:
    using Arguments = std::tuple<WebCore::IntPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CharacterIndexForPointAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CharacterIndexForPointAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    using Promise = WTF::NativePromise<uint64_t, IPC::Error>;
    explicit CharacterIndexForPointAsync(const WebCore::IntPoint& point)
        : m_point(point)
    {
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

#if PLATFORM(COCOA)
class FirstRectForCharacterRangeAsync {
public:
    using Arguments = std::tuple<WebKit::EditingRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FirstRectForCharacterRangeAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_FirstRectForCharacterRangeAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::IntRect, WebKit::EditingRange>;
    using Reply = CompletionHandler<void(WebCore::IntRect&&, WebKit::EditingRange&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebCore::IntRect, WebKit::EditingRange>, IPC::Error>;
    explicit FirstRectForCharacterRangeAsync(const WebKit::EditingRange& range)
        : m_range(range)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditingRange& m_range;
};
#endif

#if PLATFORM(COCOA)
class SetCompositionAsync {
public:
    using Arguments = std::tuple<String, Vector<WebCore::CompositionUnderline>, Vector<WebCore::CompositionHighlight>, HashMap<String, Vector<WebCore::CharacterRange>>, WebKit::EditingRange, WebKit::EditingRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCompositionAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetCompositionAsync(const String& text, const Vector<WebCore::CompositionUnderline>& underlines, const Vector<WebCore::CompositionHighlight>& highlights, const HashMap<String, Vector<WebCore::CharacterRange>>& annotations, const WebKit::EditingRange& selectionRange, const WebKit::EditingRange& replacementRange)
        : m_text(text)
        , m_underlines(underlines)
        , m_highlights(highlights)
        , m_annotations(annotations)
        , m_selectionRange(selectionRange)
        , m_replacementRange(replacementRange)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_underlines;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_highlights;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_annotations;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_selectionRange;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_replacementRange;
    }

private:
    const String& m_text;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::CompositionUnderline>& m_underlines;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::CompositionHighlight>& m_highlights;
    SUPPRESS_FORWARD_DECL_MEMBER const HashMap<String, Vector<WebCore::CharacterRange>>& m_annotations;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditingRange& m_selectionRange;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditingRange& m_replacementRange;
};
#endif

#if PLATFORM(COCOA)
class SetWritingSuggestion {
public:
    using Arguments = std::tuple<String, WebKit::EditingRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetWritingSuggestion; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetWritingSuggestion(const String& text, const WebKit::EditingRange& selectionRange)
        : m_text(text)
        , m_selectionRange(selectionRange)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_text;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_selectionRange;
    }

private:
    const String& m_text;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditingRange& m_selectionRange;
};
#endif

#if PLATFORM(COCOA)
class ConfirmCompositionAsync {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ConfirmCompositionAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ConfirmCompositionAsync()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(MAC)
class AttributedSubstringForCharacterRangeAsync {
public:
    using Arguments = std::tuple<WebKit::EditingRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AttributedSubstringForCharacterRangeAsync; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_AttributedSubstringForCharacterRangeAsyncReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::AttributedString, WebKit::EditingRange>;
    using Reply = CompletionHandler<void(WebCore::AttributedString&&, WebKit::EditingRange&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebCore::AttributedString, WebKit::EditingRange>, IPC::Error>;
    explicit AttributedSubstringForCharacterRangeAsync(const WebKit::EditingRange& range)
        : m_range(range)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::EditingRange& m_range;
};
#endif

#if PLATFORM(MAC)
class RequestAcceptsFirstMouse {
public:
    using Arguments = std::tuple<int, WebKit::WebMouseEvent>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestAcceptsFirstMouse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RequestAcceptsFirstMouse(const int& eventNumber, const WebKit::WebMouseEvent& event)
        : m_eventNumber(eventNumber)
        , m_event(event)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_eventNumber;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_eventNumber;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebMouseEvent& m_event;
};
#endif

#if PLATFORM(MAC)
class SetCaretAnimatorType {
public:
    using Arguments = std::tuple<WebCore::CaretAnimatorType>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCaretAnimatorType; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCaretAnimatorType(WebCore::CaretAnimatorType caretType)
        : m_caretType(caretType)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_caretType;
    }

private:
    WebCore::CaretAnimatorType m_caretType;
};
#endif

#if PLATFORM(MAC)
class SetCaretBlinkingSuspended {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCaretBlinkingSuspended; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCaretBlinkingSuspended(bool blinkSuspended)
        : m_blinkSuspended(blinkSuspended)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_blinkSuspended;
    }

private:
    bool m_blinkSuspended;
};
#endif

#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
class ReplaceImageForRemoveBackground {
public:
    using Arguments = std::tuple<WebCore::ElementContext, Vector<String>, std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ReplaceImageForRemoveBackground; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ReplaceImageForRemoveBackground(const WebCore::ElementContext& context, const Vector<String>& types, const std::span<const uint8_t>& data)
        : m_context(context)
        , m_types(types)
        , m_data(data)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_types;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_context;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_types;
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_data;
};
#endif

#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
class ShouldAllowRemoveBackground {
public:
    using Arguments = std::tuple<WebCore::ElementContext>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ShouldAllowRemoveBackground; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ShouldAllowRemoveBackgroundReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit ShouldAllowRemoveBackground(const WebCore::ElementContext& context)
        : m_context(context)
    {
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

class SetAlwaysShowsHorizontalScroller {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetAlwaysShowsHorizontalScroller; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAlwaysShowsHorizontalScroller(bool alwaysShowsHorizontalScroller)
        : m_alwaysShowsHorizontalScroller(alwaysShowsHorizontalScroller)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_alwaysShowsHorizontalScroller;
    }

private:
    bool m_alwaysShowsHorizontalScroller;
};

class SetAlwaysShowsVerticalScroller {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetAlwaysShowsVerticalScroller; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAlwaysShowsVerticalScroller(bool alwaysShowsVerticalScroller)
        : m_alwaysShowsVerticalScroller(alwaysShowsVerticalScroller)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_alwaysShowsVerticalScroller;
    }

private:
    bool m_alwaysShowsVerticalScroller;
};

class SetMinimumSizeForAutoLayout {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMinimumSizeForAutoLayout; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMinimumSizeForAutoLayout(const WebCore::IntSize& size)
        : m_size(size)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_size;
};

class SetSizeToContentAutoSizeMaximumSize {
public:
    using Arguments = std::tuple<WebCore::IntSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetSizeToContentAutoSizeMaximumSize; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetSizeToContentAutoSizeMaximumSize(const WebCore::IntSize& size)
        : m_size(size)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_size;
};

class SetAutoSizingShouldExpandToViewHeight {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetAutoSizingShouldExpandToViewHeight; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAutoSizingShouldExpandToViewHeight(bool shouldExpand)
        : m_shouldExpand(shouldExpand)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldExpand;
    }

private:
    bool m_shouldExpand;
};

class SetViewportSizeForCSSViewportUnits {
public:
    using Arguments = std::tuple<std::optional<WebCore::FloatSize>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetViewportSizeForCSSViewportUnits; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetViewportSizeForCSSViewportUnits(const std::optional<WebCore::FloatSize>& viewportSize)
        : m_viewportSize(viewportSize)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_viewportSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatSize>& m_viewportSize;
};

#if PLATFORM(COCOA)
class HandleAlternativeTextUIResult {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HandleAlternativeTextUIResult; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HandleAlternativeTextUIResult(const String& result)
        : m_result(result)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_result;
    }

private:
    const String& m_result;
};
#endif

#if PLATFORM(IOS_FAMILY)
class WillStartUserTriggeredZooming {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WillStartUserTriggeredZooming; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WillStartUserTriggeredZooming()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(IOS_FAMILY)
class DidEndUserTriggeredZooming {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidEndUserTriggeredZooming; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidEndUserTriggeredZooming()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class SetScrollPinningBehavior {
public:
    using Arguments = std::tuple<WebCore::ScrollPinningBehavior>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetScrollPinningBehavior; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetScrollPinningBehavior(WebCore::ScrollPinningBehavior pinning)
        : m_pinning(pinning)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pinning;
    }

private:
    WebCore::ScrollPinningBehavior m_pinning;
};

class SetScrollbarOverlayStyle {
public:
    using Arguments = std::tuple<std::optional<WebCore::ScrollbarOverlayStyle>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetScrollbarOverlayStyle; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetScrollbarOverlayStyle(std::optional<WebCore::ScrollbarOverlayStyle> scrollbarStyle)
        : m_scrollbarStyle(scrollbarStyle)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_scrollbarStyle;
    }

private:
    std::optional<WebCore::ScrollbarOverlayStyle> m_scrollbarStyle;
};

class GetBytecodeProfile {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetBytecodeProfile; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetBytecodeProfileReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    GetBytecodeProfile()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetSamplingProfilerOutput {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetSamplingProfilerOutput; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetSamplingProfilerOutputReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    GetSamplingProfilerOutput()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class TakeSnapshot {
public:
    using Arguments = std::tuple<WebCore::IntRect, WebCore::IntSize, OptionSet<WebKit::SnapshotOption>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TakeSnapshot; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_TakeSnapshotReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebKit::ImageBufferBackendHandle>, WebCore::Headroom>;
    using Reply = CompletionHandler<void(std::optional<WebKit::ImageBufferBackendHandle>&&, WebCore::Headroom&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebKit::ImageBufferBackendHandle>, WebCore::Headroom>, IPC::Error>;
    TakeSnapshot(const WebCore::IntRect& snapshotRect, const WebCore::IntSize& bitmapSize, const OptionSet<WebKit::SnapshotOption>& options)
        : m_snapshotRect(snapshotRect)
        , m_bitmapSize(bitmapSize)
        , m_options(options)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_snapshotRect;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bitmapSize;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntRect& m_snapshotRect;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::IntSize& m_bitmapSize;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebKit::SnapshotOption>& m_options;
};

#if PLATFORM(MAC)
class PerformImmediateActionHitTestAtLocation {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PerformImmediateActionHitTestAtLocation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PerformImmediateActionHitTestAtLocation(const WebCore::FrameIdentifier& frameID, const WebCore::FloatPoint& location)
        : m_frameID(frameID)
        , m_location(location)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_location;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_location;
};
#endif

#if PLATFORM(MAC)
class ImmediateActionDidUpdate {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ImmediateActionDidUpdate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ImmediateActionDidUpdate()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(MAC)
class ImmediateActionDidCancel {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ImmediateActionDidCancel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ImmediateActionDidCancel()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(MAC)
class ImmediateActionDidComplete {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ImmediateActionDidComplete; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ImmediateActionDidComplete()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(MAC)
class DataDetectorsDidPresentUI {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DataDetectorsDidPresentUI; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DataDetectorsDidPresentUI(uint64_t pageOverlay)
        : m_pageOverlay(pageOverlay)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pageOverlay;
    }

private:
    uint64_t m_pageOverlay;
};
#endif

#if PLATFORM(MAC)
class DataDetectorsDidChangeUI {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DataDetectorsDidChangeUI; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DataDetectorsDidChangeUI(uint64_t pageOverlay)
        : m_pageOverlay(pageOverlay)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pageOverlay;
    }

private:
    uint64_t m_pageOverlay;
};
#endif

#if PLATFORM(MAC)
class DataDetectorsDidHideUI {
public:
    using Arguments = std::tuple<uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DataDetectorsDidHideUI; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DataDetectorsDidHideUI(uint64_t pageOverlay)
        : m_pageOverlay(pageOverlay)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_pageOverlay;
    }

private:
    uint64_t m_pageOverlay;
};
#endif

#if PLATFORM(MAC)
class HandleAcceptedCandidate {
public:
    using Arguments = std::tuple<WebCore::TextCheckingResult>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HandleAcceptedCandidate; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit HandleAcceptedCandidate(const WebCore::TextCheckingResult& acceptedCandidate)
        : m_acceptedCandidate(acceptedCandidate)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_acceptedCandidate;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TextCheckingResult& m_acceptedCandidate;
};
#endif

#if PLATFORM(MAC)
class SemanticContextDidChange {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SemanticContextDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SemanticContextDidChange(bool useFormSemanticContext)
        : m_useFormSemanticContext(useFormSemanticContext)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_useFormSemanticContext;
    }

private:
    bool m_useFormSemanticContext;
};
#endif

#if PLATFORM(MAC)
class SetHeaderBannerHeight {
public:
    using Arguments = std::tuple<int>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetHeaderBannerHeight; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHeaderBannerHeight(const int& height)
        : m_height(height)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_height;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_height;
};
#endif

#if PLATFORM(MAC)
class SetFooterBannerHeight {
public:
    using Arguments = std::tuple<int>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetFooterBannerHeight; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetFooterBannerHeight(const int& height)
        : m_height(height)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_height;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const int& m_height;
};
#endif

#if PLATFORM(MAC)
class DidBeginMagnificationGesture {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidBeginMagnificationGesture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidBeginMagnificationGesture()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(MAC)
class DidEndMagnificationGesture {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidEndMagnificationGesture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidEndMagnificationGesture()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class StartDeferringResizeEvents {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StartDeferringResizeEvents; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartDeferringResizeEvents()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class FlushDeferredResizeEvents {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FlushDeferredResizeEvents; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FlushDeferredResizeEvents()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StartDeferringScrollEvents {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StartDeferringScrollEvents; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartDeferringScrollEvents()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class FlushDeferredScrollEvents {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FlushDeferredScrollEvents; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FlushDeferredScrollEvents()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class FlushDeferredDidReceiveMouseEvent {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FlushDeferredDidReceiveMouseEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FlushDeferredDidReceiveMouseEvent()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class PerformHitTestForMouseEvent {
public:
    using Arguments = std::tuple<WebKit::WebMouseEvent>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PerformHitTestForMouseEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PerformHitTestForMouseEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::WebHitTestResultData, OptionSet<WebKit::WebEventModifier>, WebKit::UserData>;
    using Reply = CompletionHandler<void(WebKit::WebHitTestResultData&&, OptionSet<WebKit::WebEventModifier>&&, WebKit::UserData&&)>;
    using Promise = WTF::NativePromise<std::tuple<WebKit::WebHitTestResultData, OptionSet<WebKit::WebEventModifier>, WebKit::UserData>, IPC::Error>;
    explicit PerformHitTestForMouseEvent(const WebKit::WebMouseEvent& event)
        : m_event(event)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebMouseEvent& m_event;
};

class SetUseColorAppearance {
public:
    using Arguments = std::tuple<bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetUseColorAppearance; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetUseColorAppearance(bool useDarkAppearance, bool useElevatedUserInterfaceLevel)
        : m_useDarkAppearance(useDarkAppearance)
        , m_useElevatedUserInterfaceLevel(useElevatedUserInterfaceLevel)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_useDarkAppearance;
        encoder << m_useElevatedUserInterfaceLevel;
    }

private:
    bool m_useDarkAppearance;
    bool m_useElevatedUserInterfaceLevel;
};

#if HAVE(APP_ACCENT_COLORS)
class SetAccentColor {
public:
    using Arguments = std::tuple<WebCore::Color>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetAccentColor; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAccentColor(const WebCore::Color& color)
        : m_color(color)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_color;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::Color& m_color;
};
#endif

#if PLATFORM(COCOA)
class RequestActiveNowPlayingSessionInfo {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestActiveNowPlayingSessionInfo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestActiveNowPlayingSessionInfoReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool, WebCore::NowPlayingInfo>;
    using Reply = CompletionHandler<void(bool, WebCore::NowPlayingInfo&&)>;
    using Promise = WTF::NativePromise<std::tuple<bool, WebCore::NowPlayingInfo>, IPC::Error>;
    RequestActiveNowPlayingSessionInfo()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class SetShouldDispatchFakeMouseMoveEvents {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetShouldDispatchFakeMouseMoveEvents; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldDispatchFakeMouseMoveEvents(bool shouldDispatchFakeMouseMoveEvents)
        : m_shouldDispatchFakeMouseMoveEvents(shouldDispatchFakeMouseMoveEvents)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldDispatchFakeMouseMoveEvents;
    }

private:
    bool m_shouldDispatchFakeMouseMoveEvents;
};

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class PlaybackTargetSelected {
public:
    using Arguments = std::tuple<WebCore::PlaybackTargetClientContextIdentifier, WebKit::MediaPlaybackTargetContextSerialized>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PlaybackTargetSelected; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PlaybackTargetSelected(const WebCore::PlaybackTargetClientContextIdentifier& contextId, const WebKit::MediaPlaybackTargetContextSerialized& target)
        : m_contextId(contextId)
        , m_target(target)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contextId;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_target;
    }

private:
    const WebCore::PlaybackTargetClientContextIdentifier& m_contextId;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::MediaPlaybackTargetContextSerialized& m_target;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class PlaybackTargetAvailabilityDidChange {
public:
    using Arguments = std::tuple<WebCore::PlaybackTargetClientContextIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PlaybackTargetAvailabilityDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    PlaybackTargetAvailabilityDidChange(const WebCore::PlaybackTargetClientContextIdentifier& contextId, bool available)
        : m_contextId(contextId)
        , m_available(available)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contextId;
        encoder << m_available;
    }

private:
    const WebCore::PlaybackTargetClientContextIdentifier& m_contextId;
    bool m_available;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class SetShouldPlayToPlaybackTarget {
public:
    using Arguments = std::tuple<WebCore::PlaybackTargetClientContextIdentifier, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetShouldPlayToPlaybackTarget; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = true;

    SetShouldPlayToPlaybackTarget(const WebCore::PlaybackTargetClientContextIdentifier& contextId, bool shouldPlay)
        : m_contextId(contextId)
        , m_shouldPlay(shouldPlay)
    {
    }

    void encodeCoalescingKey(IPC::Encoder& encoder) const
    {
        encoder << m_contextId;
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_contextId;
        encoder << m_shouldPlay;
    }

private:
    const WebCore::PlaybackTargetClientContextIdentifier& m_contextId;
    bool m_shouldPlay;
};
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
class PlaybackTargetPickerWasDismissed {
public:
    using Arguments = std::tuple<WebCore::PlaybackTargetClientContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PlaybackTargetPickerWasDismissed; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PlaybackTargetPickerWasDismissed(const WebCore::PlaybackTargetClientContextIdentifier& contextId)
        : m_contextId(contextId)
    {
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

#if ENABLE(POINTER_LOCK)
class DidLosePointerLock {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidLosePointerLock; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidLosePointerLock()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class SetShouldScaleViewToFitDocument {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetShouldScaleViewToFitDocument; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldScaleViewToFitDocument(bool shouldScaleViewToFitDocument)
        : m_shouldScaleViewToFitDocument(shouldScaleViewToFitDocument)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_shouldScaleViewToFitDocument;
    }

private:
    bool m_shouldScaleViewToFitDocument;
};

class SetUserInterfaceLayoutDirection {
public:
    using Arguments = std::tuple<uint32_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetUserInterfaceLayoutDirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUserInterfaceLayoutDirection(uint32_t direction)
        : m_direction(direction)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_direction;
    }

private:
    uint32_t m_direction;
};

class DidGetLoadDecisionForIcon {
public:
    using Arguments = std::tuple<bool, WebKit::CallbackID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidGetLoadDecisionForIcon; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DidGetLoadDecisionForIconReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<IPC::SharedBufferReference>;
    using Reply = CompletionHandler<void(IPC::SharedBufferReference&&)>;
    using Promise = WTF::NativePromise<IPC::SharedBufferReference, IPC::Error>;
    DidGetLoadDecisionForIcon(bool decision, const WebKit::CallbackID& loadIdentifier)
        : m_decision(decision)
        , m_loadIdentifier(loadIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_decision;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_loadIdentifier;
    }

private:
    bool m_decision;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::CallbackID& m_loadIdentifier;
};

class SetUseIconLoadingClient {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetUseIconLoadingClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetUseIconLoadingClient(bool useIconLoadingClient)
        : m_useIconLoadingClient(useIconLoadingClient)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_useIconLoadingClient;
    }

private:
    bool m_useIconLoadingClient;
};

#if ENABLE(GAMEPAD)
class GamepadActivity {
public:
    using Arguments = std::tuple<Vector<std::optional<WebKit::GamepadData>>, WebCore::EventMakesGamepadsVisible>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GamepadActivity; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GamepadActivity(const Vector<std::optional<WebKit::GamepadData>>& gamepadDatas, WebCore::EventMakesGamepadsVisible eventVisibility)
        : m_gamepadDatas(gamepadDatas)
        , m_eventVisibility(eventVisibility)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_gamepadDatas;
        encoder << m_eventVisibility;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::optional<WebKit::GamepadData>>& m_gamepadDatas;
    WebCore::EventMakesGamepadsVisible m_eventVisibility;
};
#endif

#if (ENABLE(GAMEPAD) && PLATFORM(VISION))
class AllowGamepadAccess {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AllowGamepadAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AllowGamepadAccess()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class RegisterURLSchemeHandler {
public:
    using Arguments = std::tuple<WebKit::WebURLSchemeHandlerIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RegisterURLSchemeHandler; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RegisterURLSchemeHandler(const WebKit::WebURLSchemeHandlerIdentifier& handlerIdentifier, const String& scheme)
        : m_handlerIdentifier(handlerIdentifier)
        , m_scheme(scheme)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_handlerIdentifier;
        encoder << m_scheme;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebURLSchemeHandlerIdentifier& m_handlerIdentifier;
    const String& m_scheme;
};

class URLSchemeTaskWillPerformRedirection {
public:
    using Arguments = std::tuple<WebKit::WebURLSchemeHandlerIdentifier, WebCore::ResourceLoaderIdentifier, WebCore::ResourceResponse, WebCore::ResourceRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_URLSchemeTaskWillPerformRedirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_URLSchemeTaskWillPerformRedirectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ResourceRequest>;
    using Reply = CompletionHandler<void(WebCore::ResourceRequest&&)>;
    using Promise = WTF::NativePromise<WebCore::ResourceRequest, IPC::Error>;
    URLSchemeTaskWillPerformRedirection(const WebKit::WebURLSchemeHandlerIdentifier& handlerIdentifier, const WebCore::ResourceLoaderIdentifier& taskIdentifier, const WebCore::ResourceResponse& response, const WebCore::ResourceRequest& proposedRequest)
        : m_handlerIdentifier(handlerIdentifier)
        , m_taskIdentifier(taskIdentifier)
        , m_response(response)
        , m_proposedRequest(proposedRequest)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_handlerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_taskIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_proposedRequest;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebURLSchemeHandlerIdentifier& m_handlerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_taskIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_proposedRequest;
};

class URLSchemeTaskDidPerformRedirection {
public:
    using Arguments = std::tuple<WebKit::WebURLSchemeHandlerIdentifier, WebCore::ResourceLoaderIdentifier, WebCore::ResourceResponse, WebCore::ResourceRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_URLSchemeTaskDidPerformRedirection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    URLSchemeTaskDidPerformRedirection(const WebKit::WebURLSchemeHandlerIdentifier& handlerIdentifier, const WebCore::ResourceLoaderIdentifier& taskIdentifier, const WebCore::ResourceResponse& response, const WebCore::ResourceRequest& proposedRequest)
        : m_handlerIdentifier(handlerIdentifier)
        , m_taskIdentifier(taskIdentifier)
        , m_response(response)
        , m_proposedRequest(proposedRequest)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_handlerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_taskIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_proposedRequest;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebURLSchemeHandlerIdentifier& m_handlerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_taskIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_proposedRequest;
};

class URLSchemeTaskDidReceiveResponse {
public:
    using Arguments = std::tuple<WebKit::WebURLSchemeHandlerIdentifier, WebCore::ResourceLoaderIdentifier, WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_URLSchemeTaskDidReceiveResponse; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    URLSchemeTaskDidReceiveResponse(const WebKit::WebURLSchemeHandlerIdentifier& handlerIdentifier, const WebCore::ResourceLoaderIdentifier& taskIdentifier, const WebCore::ResourceResponse& response)
        : m_handlerIdentifier(handlerIdentifier)
        , m_taskIdentifier(taskIdentifier)
        , m_response(response)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_handlerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_taskIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebURLSchemeHandlerIdentifier& m_handlerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_taskIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

class URLSchemeTaskDidReceiveData {
public:
    using Arguments = std::tuple<WebKit::WebURLSchemeHandlerIdentifier, WebCore::ResourceLoaderIdentifier, Ref<WebCore::SharedBuffer>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_URLSchemeTaskDidReceiveData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    URLSchemeTaskDidReceiveData(const WebKit::WebURLSchemeHandlerIdentifier& handlerIdentifier, const WebCore::ResourceLoaderIdentifier& taskIdentifier, const Ref<WebCore::SharedBuffer>& data)
        : m_handlerIdentifier(handlerIdentifier)
        , m_taskIdentifier(taskIdentifier)
        , m_data(data)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_handlerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_taskIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_data;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebURLSchemeHandlerIdentifier& m_handlerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_taskIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::SharedBuffer>& m_data;
};

class URLSchemeTaskDidComplete {
public:
    using Arguments = std::tuple<WebKit::WebURLSchemeHandlerIdentifier, WebCore::ResourceLoaderIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_URLSchemeTaskDidComplete; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    URLSchemeTaskDidComplete(const WebKit::WebURLSchemeHandlerIdentifier& handlerIdentifier, const WebCore::ResourceLoaderIdentifier& taskIdentifier, const WebCore::ResourceError& error)
        : m_handlerIdentifier(handlerIdentifier)
        , m_taskIdentifier(taskIdentifier)
        , m_error(error)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_handlerIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_taskIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebURLSchemeHandlerIdentifier& m_handlerIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceLoaderIdentifier& m_taskIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};

class SetIsSuspended {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetIsSuspended; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SetIsSuspendedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<bool>>;
    using Reply = CompletionHandler<void(std::optional<bool>&&)>;
    using Promise = WTF::NativePromise<std::optional<bool>, IPC::Error>;
    explicit SetIsSuspended(bool suspended)
        : m_suspended(suspended)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_suspended;
    }

private:
    bool m_suspended;
};

#if ENABLE(ATTACHMENT_ELEMENT)
class InsertAttachment {
public:
    using Arguments = std::tuple<String, std::optional<uint64_t>, String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_InsertAttachment; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_InsertAttachmentReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    InsertAttachment(const String& identifier, const std::optional<uint64_t>& fileSize, const String& fileName, const String& contentType)
        : m_identifier(identifier)
        , m_fileSize(fileSize)
        , m_fileName(fileName)
        , m_contentType(contentType)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fileSize;
        encoder << m_fileName;
        encoder << m_contentType;
    }

private:
    const String& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_fileSize;
    const String& m_fileName;
    const String& m_contentType;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class UpdateAttachmentAttributes {
public:
    using Arguments = std::tuple<String, std::optional<uint64_t>, String, String, IPC::SharedBufferReference>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateAttachmentAttributes; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateAttachmentAttributesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UpdateAttachmentAttributes(const String& identifier, const std::optional<uint64_t>& fileSize, const String& contentType, const String& fileName, const IPC::SharedBufferReference& associatedElementData)
        : m_identifier(identifier)
        , m_fileSize(fileSize)
        , m_contentType(contentType)
        , m_fileName(fileName)
        , m_associatedElementData(associatedElementData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_fileSize;
        encoder << m_contentType;
        encoder << m_fileName;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_associatedElementData;
    }

private:
    const String& m_identifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<uint64_t>& m_fileSize;
    const String& m_contentType;
    const String& m_fileName;
    SUPPRESS_FORWARD_DECL_MEMBER const IPC::SharedBufferReference& m_associatedElementData;
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
class UpdateAttachmentIcon {
public:
    using Arguments = std::tuple<String, std::optional<WebCore::ShareableBitmapHandle>, WebCore::FloatSize>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateAttachmentIcon; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateAttachmentIcon(const String& identifier, std::optional<WebCore::ShareableBitmapHandle>&& icon, const WebCore::FloatSize& size)
        : m_identifier(identifier)
        , m_icon(WTFMove(icon))
        , m_size(size)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_identifier;
        encoder << WTFMove(m_icon);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_size;
    }

private:
    const String& m_identifier;
    std::optional<WebCore::ShareableBitmapHandle>&& m_icon;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatSize& m_size;
};
#endif

#if ENABLE(APPLICATION_MANIFEST)
class GetApplicationManifest {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetApplicationManifest; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetApplicationManifestReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ApplicationManifest>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ApplicationManifest>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ApplicationManifest>, IPC::Error>;
    GetApplicationManifest()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class GetTextFragmentMatch {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetTextFragmentMatch; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetTextFragmentMatchReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    GetTextFragmentMatch()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
class ZoomPDFIn {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ZoomPDFIn; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ZoomPDFIn(const WebKit::PDFPluginIdentifier& identifier)
        : m_identifier(identifier)
    {
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

#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
class ZoomPDFOut {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ZoomPDFOut; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ZoomPDFOut(const WebKit::PDFPluginIdentifier& identifier)
        : m_identifier(identifier)
    {
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

#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
class SavePDF {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SavePDF; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SavePDFReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, URL, std::span<const uint8_t>>;
    using Reply = CompletionHandler<void(String&&, URL&&, std::span<const uint8_t>&&)>;
    using Promise = WTF::NativePromise<std::tuple<String, URL, std::span<const uint8_t>>, IPC::Error>;
    explicit SavePDF(const WebKit::PDFPluginIdentifier& identifier)
        : m_identifier(identifier)
    {
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

#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
class OpenPDFWithPreview {
public:
    using Arguments = std::tuple<WebKit::PDFPluginIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_OpenPDFWithPreview; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_OpenPDFWithPreviewReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String, std::optional<WebKit::FrameInfoData>, std::span<const uint8_t>>;
    using Reply = CompletionHandler<void(String&&, std::optional<WebKit::FrameInfoData>&&, std::span<const uint8_t>&&)>;
    using Promise = WTF::NativePromise<std::tuple<String, std::optional<WebKit::FrameInfoData>, std::span<const uint8_t>>, IPC::Error>;
    explicit OpenPDFWithPreview(const WebKit::PDFPluginIdentifier& identifier)
        : m_identifier(identifier)
    {
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

class UpdateCurrentModifierState {
public:
    using Arguments = std::tuple<OptionSet<WebCore::PlatformEventModifier>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateCurrentModifierState; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateCurrentModifierState(const OptionSet<WebCore::PlatformEventModifier>& modifiers)
        : m_modifiers(modifiers)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::PlatformEventModifier>& m_modifiers;
};

class SimulateDeviceOrientationChange {
public:
    using Arguments = std::tuple<double, double, double>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SimulateDeviceOrientationChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SimulateDeviceOrientationChange(double alpha, double beta, double gamma)
        : m_alpha(alpha)
        , m_beta(beta)
        , m_gamma(gamma)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_alpha;
        encoder << m_beta;
        encoder << m_gamma;
    }

private:
    double m_alpha;
    double m_beta;
    double m_gamma;
};

#if ENABLE(SPEECH_SYNTHESIS)
class SpeakingErrorOccurred {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SpeakingErrorOccurred; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SpeakingErrorOccurred()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class BoundaryEventOccurred {
public:
    using Arguments = std::tuple<bool, unsigned, unsigned>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_BoundaryEventOccurred; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    BoundaryEventOccurred(bool wordBoundary, const unsigned& charIndex, const unsigned& charLength)
        : m_wordBoundary(wordBoundary)
        , m_charIndex(charIndex)
        , m_charLength(charLength)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_wordBoundary;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_charIndex;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_charLength;
    }

private:
    bool m_wordBoundary;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_charIndex;
    SUPPRESS_FORWARD_DECL_MEMBER const unsigned& m_charLength;
};
#endif

#if ENABLE(SPEECH_SYNTHESIS)
class VoicesDidChange {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_VoicesDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    VoicesDidChange()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class SetCanShowPlaceholder {
public:
    using Arguments = std::tuple<WebCore::ElementContext, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCanShowPlaceholder; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetCanShowPlaceholder(const WebCore::ElementContext& context, bool canShowPlaceholder)
        : m_context(context)
        , m_canShowPlaceholder(canShowPlaceholder)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
        encoder << m_canShowPlaceholder;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_context;
    bool m_canShowPlaceholder;
};

class WasLoadedWithDataTransferFromPrevalentResource {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WasLoadedWithDataTransferFromPrevalentResource; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WasLoadedWithDataTransferFromPrevalentResource()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ClearLoadedSubresourceDomains {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ClearLoadedSubresourceDomains; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ClearLoadedSubresourceDomains()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetLoadedSubresourceDomains {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetLoadedSubresourceDomains; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetLoadedSubresourceDomainsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::RegistrableDomain>>;
    using Reply = CompletionHandler<void(Vector<WebCore::RegistrableDomain>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::RegistrableDomain>, IPC::Error>;
    GetLoadedSubresourceDomains()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if USE(SYSTEM_PREVIEW)
class SystemPreviewActionTriggered {
public:
    using Arguments = std::tuple<WebCore::SystemPreviewInfo, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SystemPreviewActionTriggered; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SystemPreviewActionTriggered(const WebCore::SystemPreviewInfo& previewInfo, const String& message)
        : m_previewInfo(previewInfo)
        , m_message(message)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_previewInfo;
        encoder << m_message;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SystemPreviewInfo& m_previewInfo;
    const String& m_message;
};
#endif

#if PLATFORM(GTK) || PLATFORM(WPE)
class SendMessageToWebProcessExtension {
public:
    using Arguments = std::tuple<WebKit::UserMessage>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SendMessageToWebProcessExtension; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SendMessageToWebProcessExtension(const WebKit::UserMessage& userMessage)
        : m_userMessage(userMessage)
    {
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
class SendMessageToWebProcessExtensionWithReply {
public:
    using Arguments = std::tuple<WebKit::UserMessage>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SendMessageToWebProcessExtensionWithReply; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SendMessageToWebProcessExtensionWithReplyReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::UserMessage>;
    using Reply = CompletionHandler<void(WebKit::UserMessage&&)>;
    using Promise = WTF::NativePromise<WebKit::UserMessage, IPC::Error>;
    explicit SendMessageToWebProcessExtensionWithReply(const WebKit::UserMessage& userMessage)
        : m_userMessage(userMessage)
    {
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

#if PLATFORM(WPE) && USE(GBM) && ENABLE(WPE_PLATFORM)
class PreferredBufferFormatsDidChange {
public:
    using Arguments = std::tuple<Vector<WebKit::RendererBufferFormat>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PreferredBufferFormatsDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit PreferredBufferFormatsDidChange(const Vector<WebKit::RendererBufferFormat>& preferredBufferFormats)
        : m_preferredBufferFormats(preferredBufferFormats)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_preferredBufferFormats;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebKit::RendererBufferFormat>& m_preferredBufferFormats;
};
#endif

class StartTextManipulations {
public:
    using Arguments = std::tuple<Vector<WebCore::TextManipulationControllerExclusionRule>, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StartTextManipulations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_StartTextManipulationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    StartTextManipulations(const Vector<WebCore::TextManipulationControllerExclusionRule>& exclusionRules, bool includeSubframes)
        : m_exclusionRules(exclusionRules)
        , m_includeSubframes(includeSubframes)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_exclusionRules;
        encoder << m_includeSubframes;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::TextManipulationControllerExclusionRule>& m_exclusionRules;
    bool m_includeSubframes;
};

class CompleteTextManipulation {
public:
    using Arguments = std::tuple<Vector<WebCore::TextManipulationItem>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CompleteTextManipulation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CompleteTextManipulationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::TextManipulationControllerManipulationResult>;
    using Reply = CompletionHandler<void(WebCore::TextManipulationControllerManipulationResult&&)>;
    using Promise = WTF::NativePromise<WebCore::TextManipulationControllerManipulationResult, IPC::Error>;
    explicit CompleteTextManipulation(const Vector<WebCore::TextManipulationItem>& items)
        : m_items(items)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_items;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::TextManipulationItem>& m_items;
};

class SetOverriddenMediaType {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetOverriddenMediaType; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetOverriddenMediaType(const String& mediaType)
        : m_mediaType(mediaType)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mediaType;
    }

private:
    const String& m_mediaType;
};

class GetProcessDisplayName {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetProcessDisplayName; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetProcessDisplayNameReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    using Promise = WTF::NativePromise<String, IPC::Error>;
    GetProcessDisplayName()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class UpdateCORSDisablingPatterns {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateCORSDisablingPatterns; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateCORSDisablingPatterns(const Vector<String>& patterns)
        : m_patterns(patterns)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_patterns;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<String>& m_patterns;
};

class SetIsTakingSnapshotsForApplicationSuspension {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetIsTakingSnapshotsForApplicationSuspension; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIsTakingSnapshotsForApplicationSuspension(bool isTakingSnapshotsForApplicationSuspension)
        : m_isTakingSnapshotsForApplicationSuspension(isTakingSnapshotsForApplicationSuspension)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isTakingSnapshotsForApplicationSuspension;
    }

private:
    bool m_isTakingSnapshotsForApplicationSuspension;
};

class SetNeedsDOMWindowResizeEvent {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetNeedsDOMWindowResizeEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetNeedsDOMWindowResizeEvent()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SetHasResourceLoadClient {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetHasResourceLoadClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetHasResourceLoadClient(bool has)
        : m_has(has)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_has;
    }

private:
    bool m_has;
};

class SetCanUseCredentialStorage {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetCanUseCredentialStorage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetCanUseCredentialStorage(bool canUse)
        : m_canUse(canUse)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_canUse;
    }

private:
    bool m_canUse;
};

#if ENABLE(APP_HIGHLIGHTS)
class CreateAppHighlightInSelectedRange {
public:
    using Arguments = std::tuple<WebCore::CreateNewGroupForHighlight, WebCore::HighlightRequestOriginatedInApp>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CreateAppHighlightInSelectedRange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CreateAppHighlightInSelectedRangeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::AppHighlight>;
    using Reply = CompletionHandler<void(WebCore::AppHighlight&&)>;
    using Promise = WTF::NativePromise<WebCore::AppHighlight, IPC::Error>;
    CreateAppHighlightInSelectedRange(WebCore::CreateNewGroupForHighlight createNewGroup, WebCore::HighlightRequestOriginatedInApp requestOrigin)
        : m_createNewGroup(createNewGroup)
        , m_requestOrigin(requestOrigin)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_createNewGroup;
        encoder << m_requestOrigin;
    }

private:
    WebCore::CreateNewGroupForHighlight m_createNewGroup;
    WebCore::HighlightRequestOriginatedInApp m_requestOrigin;
};
#endif

#if ENABLE(APP_HIGHLIGHTS)
class RestoreAppHighlightsAndScrollToIndex {
public:
    using Arguments = std::tuple<Vector<WebCore::SharedMemory::Handle>, std::optional<unsigned>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RestoreAppHighlightsAndScrollToIndex; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RestoreAppHighlightsAndScrollToIndex(Vector<WebCore::SharedMemory::Handle>&& memoryHandles, const std::optional<unsigned>& index)
        : m_memoryHandles(WTFMove(memoryHandles))
        , m_index(index)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_memoryHandles);
        SUPPRESS_FORWARD_DECL_ARG encoder << m_index;
    }

private:
    Vector<WebCore::SharedMemory::Handle>&& m_memoryHandles;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<unsigned>& m_index;
};
#endif

#if ENABLE(APP_HIGHLIGHTS)
class SetAppHighlightsVisibility {
public:
    using Arguments = std::tuple<WebCore::HighlightVisibility>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetAppHighlightsVisibility; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAppHighlightsVisibility(WebCore::HighlightVisibility highlightVisibility)
        : m_highlightVisibility(highlightVisibility)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_highlightVisibility;
    }

private:
    WebCore::HighlightVisibility m_highlightVisibility;
};
#endif

class CreateTextFragmentDirectiveFromSelection {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CreateTextFragmentDirectiveFromSelection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CreateTextFragmentDirectiveFromSelectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<URL>;
    using Reply = CompletionHandler<void(URL&&)>;
    using Promise = WTF::NativePromise<URL, IPC::Error>;
    CreateTextFragmentDirectiveFromSelection()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class GetTextFragmentRanges {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetTextFragmentRanges; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetTextFragmentRangesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebKit::EditingRange>>;
    using Reply = CompletionHandler<void(Vector<WebKit::EditingRange>&&)>;
    using Promise = WTF::NativePromise<Vector<WebKit::EditingRange>, IPC::Error>;
    GetTextFragmentRanges()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class HandleWheelEvent {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::WebWheelEvent, OptionSet<WebCore::WheelEventProcessingSteps>, std::optional<bool>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_HandleWheelEvent; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_HandleWheelEventReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ScrollingNodeID>, std::optional<WebCore::WheelScrollGestureState>, bool, std::optional<WebCore::RemoteUserInputEventData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ScrollingNodeID>&&, std::optional<WebCore::WheelScrollGestureState>, bool, std::optional<WebCore::RemoteUserInputEventData>&&)>;
    using Promise = WTF::NativePromise<std::tuple<std::optional<WebCore::ScrollingNodeID>, std::optional<WebCore::WheelScrollGestureState>, bool, std::optional<WebCore::RemoteUserInputEventData>>, IPC::Error>;
    HandleWheelEvent(const WebCore::FrameIdentifier& frameID, const WebKit::WebWheelEvent& event, const OptionSet<WebCore::WheelEventProcessingSteps>& processingSteps, const std::optional<bool>& willStartSwipe)
        : m_frameID(frameID)
        , m_event(event)
        , m_processingSteps(processingSteps)
        , m_willStartSwipe(willStartSwipe)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processingSteps;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_willStartSwipe;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebWheelEvent& m_event;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::WheelEventProcessingSteps>& m_processingSteps;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<bool>& m_willStartSwipe;
};

#if PLATFORM(IOS_FAMILY)
class DispatchWheelEventWithoutScrolling {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebKit::WebWheelEvent>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DispatchWheelEventWithoutScrolling; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DispatchWheelEventWithoutScrollingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    DispatchWheelEventWithoutScrolling(const WebCore::FrameIdentifier& frameID, const WebKit::WebWheelEvent& event)
        : m_frameID(frameID)
        , m_event(event)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_event;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::WebWheelEvent& m_event;
};
#endif

class LastNavigationWasAppInitiated {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LastNavigationWasAppInitiated; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_LastNavigationWasAppInitiatedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    LastNavigationWasAppInitiated()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if ENABLE(MEDIA_SESSION_COORDINATOR)
class CreateMediaSessionCoordinator {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CreateMediaSessionCoordinator; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CreateMediaSessionCoordinatorReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit CreateMediaSessionCoordinator(const String& identifier)
        : m_identifier(identifier)
    {
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

#if ENABLE(IMAGE_ANALYSIS)
class UpdateWithTextRecognitionResult {
public:
    using Arguments = std::tuple<WebCore::TextRecognitionResult, WebCore::ElementContext, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateWithTextRecognitionResult; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateWithTextRecognitionResultReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebKit::TextRecognitionUpdateResult>;
    using Reply = CompletionHandler<void(WebKit::TextRecognitionUpdateResult)>;
    using Promise = WTF::NativePromise<WebKit::TextRecognitionUpdateResult, IPC::Error>;
    UpdateWithTextRecognitionResult(const WebCore::TextRecognitionResult& result, const WebCore::ElementContext& element, const WebCore::FloatPoint& location)
        : m_result(result)
        , m_element(element)
        , m_location(location)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_result;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_element;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_location;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TextRecognitionResult& m_result;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ElementContext& m_element;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_location;
};
#endif

#if ENABLE(IMAGE_ANALYSIS)
class StartVisualTranslation {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StartVisualTranslation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartVisualTranslation(const String& sourceLanguageIdentifier, const String& targetLanguageIdentifier)
        : m_sourceLanguageIdentifier(sourceLanguageIdentifier)
        , m_targetLanguageIdentifier(targetLanguageIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_sourceLanguageIdentifier;
        encoder << m_targetLanguageIdentifier;
    }

private:
    const String& m_sourceLanguageIdentifier;
    const String& m_targetLanguageIdentifier;
};
#endif

class ScrollToRect {
public:
    using Arguments = std::tuple<WebCore::FloatRect, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ScrollToRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ScrollToRect(const WebCore::FloatRect& targetRect, const WebCore::FloatPoint& origin)
        : m_targetRect(targetRect)
        , m_origin(origin)
    {
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

class SetContentOffset {
public:
    using Arguments = std::tuple<std::optional<int>, std::optional<int>, WebCore::ScrollIsAnimated>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetContentOffset; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetContentOffset(const std::optional<int>& x, const std::optional<int>& y, WebCore::ScrollIsAnimated animated)
        : m_x(x)
        , m_y(y)
        , m_animated(animated)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_x;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_y;
        encoder << m_animated;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<int>& m_x;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<int>& m_y;
    WebCore::ScrollIsAnimated m_animated;
};

class ScrollToEdge {
public:
    using Arguments = std::tuple<WebCore::RectEdges<bool>, WebCore::ScrollIsAnimated>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ScrollToEdge; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ScrollToEdge(const WebCore::RectEdges<bool>& edges, WebCore::ScrollIsAnimated animated)
        : m_edges(edges)
        , m_animated(animated)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_edges;
        encoder << m_animated;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RectEdges<bool>& m_edges;
    WebCore::ScrollIsAnimated m_animated;
};

class NavigateServiceWorkerClient {
public:
    using Arguments = std::tuple<WebCore::ScriptExecutionContextIdentifier, URL>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_NavigateServiceWorkerClient; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_NavigateServiceWorkerClientReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::ScheduleLocationChangeResult>;
    using Reply = CompletionHandler<void(WebCore::ScheduleLocationChangeResult)>;
    using Promise = WTF::NativePromise<WebCore::ScheduleLocationChangeResult, IPC::Error>;
    NavigateServiceWorkerClient(const WebCore::ScriptExecutionContextIdentifier& documentIdentifier, const URL& url)
        : m_documentIdentifier(documentIdentifier)
        , m_url(url)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_documentIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_url;
    }

private:
    const WebCore::ScriptExecutionContextIdentifier& m_documentIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const URL& m_url;
};

#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
class ModelInlinePreviewDidLoad {
public:
    using Arguments = std::tuple<WebCore::PlatformLayerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ModelInlinePreviewDidLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ModelInlinePreviewDidLoad(const WebCore::PlatformLayerIdentifier& layerID)
        : m_layerID(layerID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_layerID;
    }

private:
    const WebCore::PlatformLayerIdentifier& m_layerID;
};
#endif

#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
class ModelInlinePreviewDidFailToLoad {
public:
    using Arguments = std::tuple<WebCore::PlatformLayerIdentifier, WebCore::ResourceError>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ModelInlinePreviewDidFailToLoad; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ModelInlinePreviewDidFailToLoad(const WebCore::PlatformLayerIdentifier& layerID, const WebCore::ResourceError& error)
        : m_layerID(layerID)
        , m_error(error)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_layerID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_error;
    }

private:
    const WebCore::PlatformLayerIdentifier& m_layerID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceError& m_error;
};
#endif

#if HAVE(UIKIT_RESIZABLE_WINDOWS)
class SetIsWindowResizingEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetIsWindowResizingEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetIsWindowResizingEnabled(bool hasResizableWindows)
        : m_hasResizableWindows(hasResizableWindows)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hasResizableWindows;
    }

private:
    bool m_hasResizableWindows;
};
#endif

#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
class SetInteractionRegionsEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetInteractionRegionsEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetInteractionRegionsEnabled(bool enable)
        : m_enable(enable)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_enable;
    }

private:
    bool m_enable;
};
#endif

class SetNeedsScrollGeometryUpdates {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetNeedsScrollGeometryUpdates; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetNeedsScrollGeometryUpdates(bool setNeedsScrollGeometryUpdates)
        : m_setNeedsScrollGeometryUpdates(setNeedsScrollGeometryUpdates)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_setNeedsScrollGeometryUpdates;
    }

private:
    bool m_setNeedsScrollGeometryUpdates;
};

class GenerateTestReport {
public:
    using Arguments = std::tuple<String, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GenerateTestReport; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    GenerateTestReport(const String& message, const String& group)
        : m_message(message)
        , m_group(group)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_message;
        encoder << m_group;
    }

private:
    const String& m_message;
    const String& m_group;
};

#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
class SetLinkDecorationFilteringData {
public:
    using Arguments = std::tuple<Vector<WebCore::LinkDecorationFilteringData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetLinkDecorationFilteringData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetLinkDecorationFilteringData(const Vector<WebCore::LinkDecorationFilteringData>& strings)
        : m_strings(strings)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_strings;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::LinkDecorationFilteringData>& m_strings;
};
#endif

#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
class SetAllowedQueryParametersForAdvancedPrivacyProtections {
public:
    using Arguments = std::tuple<Vector<WebCore::LinkDecorationFilteringData>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetAllowedQueryParametersForAdvancedPrivacyProtections; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetAllowedQueryParametersForAdvancedPrivacyProtections(const Vector<WebCore::LinkDecorationFilteringData>& allowedStrings)
        : m_allowedStrings(allowedStrings)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_allowedStrings;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::LinkDecorationFilteringData>& m_allowedStrings;
};
#endif

#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
class PauseAllAnimations {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PauseAllAnimations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PauseAllAnimationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PauseAllAnimations()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
class PlayAllAnimations {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_PlayAllAnimations; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_PlayAllAnimationsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PlayAllAnimations()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class UseRedirectionForCurrentNavigation {
public:
    using Arguments = std::tuple<WebCore::ResourceResponse>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UseRedirectionForCurrentNavigation; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UseRedirectionForCurrentNavigation(const WebCore::ResourceResponse& response)
        : m_response(response)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_response;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceResponse& m_response;
};

class UpdateFrameScrollingMode {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::ScrollbarMode>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateFrameScrollingMode; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateFrameScrollingMode(const WebCore::FrameIdentifier& frame, WebCore::ScrollbarMode scrollingMode)
        : m_frame(frame)
        , m_scrollingMode(scrollingMode)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frame;
        encoder << m_scrollingMode;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frame;
    WebCore::ScrollbarMode m_scrollingMode;
};

class DispatchLoadEventToFrameOwnerElement {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DispatchLoadEventToFrameOwnerElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit DispatchLoadEventToFrameOwnerElement(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class FrameWasFocusedInAnotherProcess {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FrameWasFocusedInAnotherProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit FrameWasFocusedInAnotherProcess(const WebCore::FrameIdentifier& frameID)
        : m_frameID(frameID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class RemotePostMessage {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String, WebCore::FrameIdentifier, std::optional<WebCore::SecurityOriginData>, WebCore::MessageWithMessagePorts>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RemotePostMessage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RemotePostMessage(const WebCore::FrameIdentifier& source, const String& sourceOrigin, const WebCore::FrameIdentifier& target, const std::optional<WebCore::SecurityOriginData>& targetOrigin, const WebCore::MessageWithMessagePorts& message)
        : m_source(source)
        , m_sourceOrigin(sourceOrigin)
        , m_target(target)
        , m_targetOrigin(targetOrigin)
        , m_message(message)
    {
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

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RenderTreeAsTextForTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    RenderTreeAsTextForTesting(const WebCore::FrameIdentifier& frameID, uint64_t baseIndent, const OptionSet<WebCore::RenderAsTextFlag>& behavior)
        : m_frameID(frameID)
        , m_baseIndent(baseIndent)
        , m_behavior(behavior)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_baseIndent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_behavior;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    uint64_t m_baseIndent;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::RenderAsTextFlag>& m_behavior;
};

class LayerTreeAsTextForTesting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, uint64_t, OptionSet<WebCore::LayerTreeAsTextOptions>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LayerTreeAsTextForTesting; }
    static constexpr bool isSync = true;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<String>;
    using Reply = CompletionHandler<void(String&&)>;
    LayerTreeAsTextForTesting(const WebCore::FrameIdentifier& frameID, uint64_t baseIndent, const OptionSet<WebCore::LayerTreeAsTextOptions>& options)
        : m_frameID(frameID)
        , m_baseIndent(baseIndent)
        , m_options(options)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        encoder << m_baseIndent;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_options;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    uint64_t m_baseIndent;
    SUPPRESS_FORWARD_DECL_MEMBER const OptionSet<WebCore::LayerTreeAsTextOptions>& m_options;
};

class FrameTextForTesting {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FrameTextForTesting; }
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
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
};

class RequestAllTextAndRects {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestAllTextAndRects; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestAllTextAndRectsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<std::pair<String, WebCore::FloatRect>>>;
    using Reply = CompletionHandler<void(Vector<std::pair<String, WebCore::FloatRect>>&&)>;
    using Promise = WTF::NativePromise<Vector<std::pair<String, WebCore::FloatRect>>, IPC::Error>;
    RequestAllTextAndRects()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class RequestTargetedElement {
public:
    using Arguments = std::tuple<WebCore::TargetedElementRequest>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestTargetedElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestTargetedElementReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::TargetedElementInfo>>;
    using Reply = CompletionHandler<void(Vector<WebCore::TargetedElementInfo>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::TargetedElementInfo>, IPC::Error>;
    explicit RequestTargetedElement(const WebCore::TargetedElementRequest& request)
        : m_request(request)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::TargetedElementRequest& m_request;
};

class RequestAllTargetableElements {
public:
    using Arguments = std::tuple<float>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestAllTargetableElements; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestAllTargetableElementsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<Vector<WebCore::TargetedElementInfo>>>;
    using Reply = CompletionHandler<void(Vector<Vector<WebCore::TargetedElementInfo>>&&)>;
    using Promise = WTF::NativePromise<Vector<Vector<WebCore::TargetedElementInfo>>, IPC::Error>;
    explicit RequestAllTargetableElements(float hitTestInterval)
        : m_hitTestInterval(hitTestInterval)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_hitTestInterval;
    }

private:
    float m_hitTestInterval;
};

class RequestTextExtraction {
public:
    using Arguments = std::tuple<std::optional<WebCore::FloatRect>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RequestTextExtraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RequestTextExtractionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::TextExtraction::Item>;
    using Reply = CompletionHandler<void(WebCore::TextExtraction::Item&&)>;
    using Promise = WTF::NativePromise<WebCore::TextExtraction::Item, IPC::Error>;
    explicit RequestTextExtraction(const std::optional<WebCore::FloatRect>& collectionRectInRootView)
        : m_collectionRectInRootView(collectionRectInRootView)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_collectionRectInRootView;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatRect>& m_collectionRectInRootView;
};

#if PLATFORM(IOS_FAMILY)
class ShouldDismissKeyboardAfterTapAtPoint {
public:
    using Arguments = std::tuple<WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ShouldDismissKeyboardAfterTapAtPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ShouldDismissKeyboardAfterTapAtPointReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit ShouldDismissKeyboardAfterTapAtPoint(const WebCore::FloatPoint& point)
        : m_point(point)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point;
};
#endif

#if ENABLE(EXTENSION_CAPABILITIES)
class SetMediaEnvironment {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetMediaEnvironment; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMediaEnvironment(const String& mediaEnvironment)
        : m_mediaEnvironment(mediaEnvironment)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_mediaEnvironment;
    }

private:
    const String& m_mediaEnvironment;
};
#endif

#if ENABLE(WRITING_TOOLS)
class WillBeginWritingToolsSession {
public:
    using Arguments = std::tuple<std::optional<WebCore::WritingTools::Session>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WillBeginWritingToolsSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_WillBeginWritingToolsSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::WritingTools::Context>>;
    using Reply = CompletionHandler<void(Vector<WebCore::WritingTools::Context>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::WritingTools::Context>, IPC::Error>;
    explicit WillBeginWritingToolsSession(const std::optional<WebCore::WritingTools::Session>& session)
        : m_session(session)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_session;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::WritingTools::Session>& m_session;
};
#endif

#if ENABLE(WRITING_TOOLS)
class DidBeginWritingToolsSession {
public:
    using Arguments = std::tuple<WebCore::WritingTools::Session, Vector<WebCore::WritingTools::Context>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidBeginWritingToolsSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidBeginWritingToolsSession(const WebCore::WritingTools::Session& session, const Vector<WebCore::WritingTools::Context>& contexts)
        : m_session(session)
        , m_contexts(contexts)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_session;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_contexts;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Session& m_session;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::WritingTools::Context>& m_contexts;
};
#endif

#if ENABLE(WRITING_TOOLS)
class ProofreadingSessionDidReceiveSuggestions {
public:
    using Arguments = std::tuple<WebCore::WritingTools::Session, Vector<WebCore::WritingTools::TextSuggestion>, WebCore::CharacterRange, WebCore::WritingTools::Context, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ProofreadingSessionDidReceiveSuggestions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ProofreadingSessionDidReceiveSuggestionsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    ProofreadingSessionDidReceiveSuggestions(const WebCore::WritingTools::Session& session, const Vector<WebCore::WritingTools::TextSuggestion>& suggestions, const WebCore::CharacterRange& processedRange, const WebCore::WritingTools::Context& context, bool finished)
        : m_session(session)
        , m_suggestions(suggestions)
        , m_processedRange(processedRange)
        , m_context(context)
        , m_finished(finished)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_session;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_suggestions;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processedRange;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
        encoder << m_finished;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Session& m_session;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::WritingTools::TextSuggestion>& m_suggestions;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CharacterRange& m_processedRange;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Context& m_context;
    bool m_finished;
};
#endif

#if ENABLE(WRITING_TOOLS)
class ProofreadingSessionDidUpdateStateForSuggestion {
public:
    using Arguments = std::tuple<WebCore::WritingTools::Session, WebCore::WritingTools::TextSuggestionState, WebCore::WritingTools::TextSuggestion, WebCore::WritingTools::Context>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ProofreadingSessionDidUpdateStateForSuggestion; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    ProofreadingSessionDidUpdateStateForSuggestion(const WebCore::WritingTools::Session& session, WebCore::WritingTools::TextSuggestionState state, const WebCore::WritingTools::TextSuggestion& suggestion, const WebCore::WritingTools::Context& context)
        : m_session(session)
        , m_state(state)
        , m_suggestion(suggestion)
        , m_context(context)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_session;
        encoder << m_state;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_suggestion;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Session& m_session;
    WebCore::WritingTools::TextSuggestionState m_state;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::TextSuggestion& m_suggestion;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Context& m_context;
};
#endif

#if ENABLE(WRITING_TOOLS)
class WillEndWritingToolsSession {
public:
    using Arguments = std::tuple<WebCore::WritingTools::Session, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WillEndWritingToolsSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_WillEndWritingToolsSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    WillEndWritingToolsSession(const WebCore::WritingTools::Session& session, bool accepted)
        : m_session(session)
        , m_accepted(accepted)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_session;
        encoder << m_accepted;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Session& m_session;
    bool m_accepted;
};
#endif

#if ENABLE(WRITING_TOOLS)
class DidEndWritingToolsSession {
public:
    using Arguments = std::tuple<WebCore::WritingTools::Session, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidEndWritingToolsSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidEndWritingToolsSession(const WebCore::WritingTools::Session& session, bool accepted)
        : m_session(session)
        , m_accepted(accepted)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_session;
        encoder << m_accepted;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Session& m_session;
    bool m_accepted;
};
#endif

#if ENABLE(WRITING_TOOLS)
class CompositionSessionDidReceiveTextWithReplacementRange {
public:
    using Arguments = std::tuple<WebCore::WritingTools::Session, WebCore::AttributedString, WebCore::CharacterRange, WebCore::WritingTools::Context, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CompositionSessionDidReceiveTextWithReplacementRange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CompositionSessionDidReceiveTextWithReplacementRangeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    CompositionSessionDidReceiveTextWithReplacementRange(const WebCore::WritingTools::Session& session, const WebCore::AttributedString& attributedText, const WebCore::CharacterRange& range, const WebCore::WritingTools::Context& context, bool finished)
        : m_session(session)
        , m_attributedText(attributedText)
        , m_range(range)
        , m_context(context)
        , m_finished(finished)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_session;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_attributedText;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_range;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_context;
        encoder << m_finished;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Session& m_session;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::AttributedString& m_attributedText;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CharacterRange& m_range;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Context& m_context;
    bool m_finished;
};
#endif

#if ENABLE(WRITING_TOOLS)
class WritingToolsSessionDidReceiveAction {
public:
    using Arguments = std::tuple<WebCore::WritingTools::Session, WebCore::WritingTools::Action>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WritingToolsSessionDidReceiveAction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WritingToolsSessionDidReceiveAction(const WebCore::WritingTools::Session& session, WebCore::WritingTools::Action action)
        : m_session(session)
        , m_action(action)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_session;
        encoder << m_action;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::WritingTools::Session& m_session;
    WebCore::WritingTools::Action m_action;
};
#endif

#if ENABLE(WRITING_TOOLS)
class ProofreadingSessionSuggestionTextRectsInRootViewCoordinates {
public:
    using Arguments = std::tuple<WebCore::CharacterRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ProofreadingSessionSuggestionTextRectsInRootViewCoordinates; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ProofreadingSessionSuggestionTextRectsInRootViewCoordinatesReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<WebCore::FloatRect>>;
    using Reply = CompletionHandler<void(Vector<WebCore::FloatRect>&&)>;
    using Promise = WTF::NativePromise<Vector<WebCore::FloatRect>, IPC::Error>;
    explicit ProofreadingSessionSuggestionTextRectsInRootViewCoordinates(const WebCore::CharacterRange& enclosingRangeRelativeToSessionRange)
        : m_enclosingRangeRelativeToSessionRange(enclosingRangeRelativeToSessionRange)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_enclosingRangeRelativeToSessionRange;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CharacterRange& m_enclosingRangeRelativeToSessionRange;
};
#endif

#if ENABLE(WRITING_TOOLS)
class UpdateTextVisibilityForActiveWritingToolsSession {
public:
    using Arguments = std::tuple<WebCore::CharacterRange, bool, WTF::UUID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateTextVisibilityForActiveWritingToolsSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateTextVisibilityForActiveWritingToolsSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UpdateTextVisibilityForActiveWritingToolsSession(const WebCore::CharacterRange& rangeRelativeToSessionRange, bool visible, const WTF::UUID& identifier)
        : m_rangeRelativeToSessionRange(rangeRelativeToSessionRange)
        , m_visible(visible)
        , m_identifier(identifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rangeRelativeToSessionRange;
        encoder << m_visible;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CharacterRange& m_rangeRelativeToSessionRange;
    bool m_visible;
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_identifier;
};
#endif

#if ENABLE(WRITING_TOOLS)
class TextPreviewDataForActiveWritingToolsSession {
public:
    using Arguments = std::tuple<WebCore::CharacterRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TextPreviewDataForActiveWritingToolsSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_TextPreviewDataForActiveWritingToolsSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::TextIndicator>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::TextIndicator>&&)>;
    using Promise = WTF::NativePromise<RefPtr<WebCore::TextIndicator>, IPC::Error>;
    explicit TextPreviewDataForActiveWritingToolsSession(const WebCore::CharacterRange& rangeRelativeToSessionRange)
        : m_rangeRelativeToSessionRange(rangeRelativeToSessionRange)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rangeRelativeToSessionRange;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CharacterRange& m_rangeRelativeToSessionRange;
};
#endif

#if ENABLE(WRITING_TOOLS)
class SetSelectionForActiveWritingToolsSession {
public:
    using Arguments = std::tuple<WebCore::CharacterRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetSelectionForActiveWritingToolsSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SetSelectionForActiveWritingToolsSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit SetSelectionForActiveWritingToolsSession(const WebCore::CharacterRange& rangeRelativeToSessionRange)
        : m_rangeRelativeToSessionRange(rangeRelativeToSessionRange)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rangeRelativeToSessionRange;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CharacterRange& m_rangeRelativeToSessionRange;
};
#endif

#if ENABLE(WRITING_TOOLS)
class DecorateTextReplacementsForActiveWritingToolsSession {
public:
    using Arguments = std::tuple<WebCore::CharacterRange>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DecorateTextReplacementsForActiveWritingToolsSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DecorateTextReplacementsForActiveWritingToolsSessionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit DecorateTextReplacementsForActiveWritingToolsSession(const WebCore::CharacterRange& rangeRelativeToSessionRange)
        : m_rangeRelativeToSessionRange(rangeRelativeToSessionRange)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rangeRelativeToSessionRange;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::CharacterRange& m_rangeRelativeToSessionRange;
};
#endif

#if ENABLE(WRITING_TOOLS)
class CreateTextIndicatorForTextAnimationID {
public:
    using Arguments = std::tuple<WTF::UUID>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CreateTextIndicatorForTextAnimationID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CreateTextIndicatorForTextAnimationIDReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::TextIndicator>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::TextIndicator>&&)>;
    using Promise = WTF::NativePromise<RefPtr<WebCore::TextIndicator>, IPC::Error>;
    explicit CreateTextIndicatorForTextAnimationID(const WTF::UUID& uuid)
        : m_uuid(uuid)
    {
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
class UpdateUnderlyingTextVisibilityForTextAnimationID {
public:
    using Arguments = std::tuple<WTF::UUID, bool>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateUnderlyingTextVisibilityForTextAnimationID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_UpdateUnderlyingTextVisibilityForTextAnimationIDReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UpdateUnderlyingTextVisibilityForTextAnimationID(const WTF::UUID& uuid, bool visible)
        : m_uuid(uuid)
        , m_visible(visible)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_uuid;
        encoder << m_visible;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WTF::UUID& m_uuid;
    bool m_visible;
};
#endif

#if ENABLE(WRITING_TOOLS)
class IntelligenceTextAnimationsDidComplete {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_IntelligenceTextAnimationsDidComplete; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    IntelligenceTextAnimationsDidComplete()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if PLATFORM(COCOA)
class CreateTextIndicatorForElementWithID {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CreateTextIndicatorForElementWithID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CreateTextIndicatorForElementWithIDReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::TextIndicatorData>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::TextIndicatorData>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::TextIndicatorData>, IPC::Error>;
    explicit CreateTextIndicatorForElementWithID(const String& elementID)
        : m_elementID(elementID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_elementID;
    }

private:
    const String& m_elementID;
};
#endif

class TakeSnapshotForTargetedElement {
public:
    using Arguments = std::tuple<WebCore::NodeIdentifier, WebCore::ScriptExecutionContextIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_TakeSnapshotForTargetedElement; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_TakeSnapshotForTargetedElementReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ShareableBitmapHandle>, IPC::Error>;
    TakeSnapshotForTargetedElement(const WebCore::NodeIdentifier& nodeID, const WebCore::ScriptExecutionContextIdentifier& documentID)
        : m_nodeID(nodeID)
        , m_documentID(documentID)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_nodeID;
        encoder << m_documentID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::NodeIdentifier& m_nodeID;
    const WebCore::ScriptExecutionContextIdentifier& m_documentID;
};

class ResetVisibilityAdjustmentsForTargetedElements {
public:
    using Arguments = std::tuple<Vector<std::pair<WebCore::NodeIdentifier, WebCore::ScriptExecutionContextIdentifier>>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ResetVisibilityAdjustmentsForTargetedElements; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ResetVisibilityAdjustmentsForTargetedElementsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit ResetVisibilityAdjustmentsForTargetedElements(const Vector<std::pair<WebCore::NodeIdentifier, WebCore::ScriptExecutionContextIdentifier>>& identifiers)
        : m_identifiers(identifiers)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_identifiers;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<std::pair<WebCore::NodeIdentifier, WebCore::ScriptExecutionContextIdentifier>>& m_identifiers;
};

class AdjustVisibilityForTargetedElements {
public:
    using Arguments = std::tuple<Vector<WebCore::TargetedElementAdjustment>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_AdjustVisibilityForTargetedElements; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_AdjustVisibilityForTargetedElementsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit AdjustVisibilityForTargetedElements(const Vector<WebCore::TargetedElementAdjustment>& adjustments)
        : m_adjustments(adjustments)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_adjustments;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<WebCore::TargetedElementAdjustment>& m_adjustments;
};

class NumberOfVisibilityAdjustmentRects {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_NumberOfVisibilityAdjustmentRects; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_NumberOfVisibilityAdjustmentRectsReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    using Promise = WTF::NativePromise<uint64_t, IPC::Error>;
    NumberOfVisibilityAdjustmentRects()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class ContentsToRootViewRect {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::FloatRect>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ContentsToRootViewRect; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ContentsToRootViewRectReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::FloatRect>;
    using Reply = CompletionHandler<void(WebCore::FloatRect&&)>;
    using Promise = WTF::NativePromise<WebCore::FloatRect, IPC::Error>;
    ContentsToRootViewRect(const WebCore::FrameIdentifier& frameID, const WebCore::FloatRect& rect)
        : m_frameID(frameID)
        , m_rect(rect)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_rect;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatRect& m_rect;
};

class ContentsToRootViewPoint {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::FloatPoint>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_ContentsToRootViewPoint; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_ContentsToRootViewPointReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::FloatPoint>;
    using Reply = CompletionHandler<void(WebCore::FloatPoint&&)>;
    using Promise = WTF::NativePromise<WebCore::FloatPoint, IPC::Error>;
    ContentsToRootViewPoint(const WebCore::FrameIdentifier& frameID, const WebCore::FloatPoint& point)
        : m_frameID(frameID)
        , m_point(point)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_point;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FloatPoint& m_point;
};

class RemoteDictionaryPopupInfoToRootView {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::DictionaryPopupInfo>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_RemoteDictionaryPopupInfoToRootView; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_RemoteDictionaryPopupInfoToRootViewReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<WebCore::DictionaryPopupInfo>;
    using Reply = CompletionHandler<void(WebCore::DictionaryPopupInfo&&)>;
    using Promise = WTF::NativePromise<WebCore::DictionaryPopupInfo, IPC::Error>;
    RemoteDictionaryPopupInfoToRootView(const WebCore::FrameIdentifier& frameID, const WebCore::DictionaryPopupInfo& popupInfo)
        : m_frameID(frameID)
        , m_popupInfo(popupInfo)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_frameID;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_popupInfo;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::FrameIdentifier& m_frameID;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::DictionaryPopupInfo& m_popupInfo;
};

#if HAVE(SPATIAL_TRACKING_LABEL)
class SetDefaultSpatialTrackingLabel {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetDefaultSpatialTrackingLabel; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetDefaultSpatialTrackingLabel(const String& label)
        : m_label(label)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_label;
    }

private:
    const String& m_label;
};
#endif

class StartObservingNowPlayingMetadata {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StartObservingNowPlayingMetadata; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StartObservingNowPlayingMetadata()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class StopObservingNowPlayingMetadata {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StopObservingNowPlayingMetadata; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    StopObservingNowPlayingMetadata()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class LoadAndDecodeImage {
public:
    using Arguments = std::tuple<WebCore::ResourceRequest, std::optional<WebCore::FloatSize>, uint64_t>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_LoadAndDecodeImage; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_LoadAndDecodeImageReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<Ref<WebCore::ShareableBitmap>, WebCore::ResourceError>>;
    using Reply = CompletionHandler<void(Expected<Ref<WebCore::ShareableBitmap>, WebCore::ResourceError>&&)>;
    using Promise = WTF::NativePromise<Expected<Ref<WebCore::ShareableBitmap>, WebCore::ResourceError>, IPC::Error>;
    LoadAndDecodeImage(const WebCore::ResourceRequest& request, const std::optional<WebCore::FloatSize>& sizeConstraint, uint64_t maximumBytesFromNetwork)
        : m_request(request)
        , m_sizeConstraint(sizeConstraint)
        , m_maximumBytesFromNetwork(maximumBytesFromNetwork)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_request;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sizeConstraint;
        encoder << m_maximumBytesFromNetwork;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ResourceRequest& m_request;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatSize>& m_sizeConstraint;
    uint64_t m_maximumBytesFromNetwork;
};

#if PLATFORM(COCOA)
class GetInformationFromImageData {
public:
    using Arguments = std::tuple<Vector<uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_GetInformationFromImageData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_GetInformationFromImageDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Expected<std::pair<String, Vector<WebCore::IntSize>>, WebCore::ImageDecodingError>>;
    using Reply = CompletionHandler<void(Expected<std::pair<String, Vector<WebCore::IntSize>>, WebCore::ImageDecodingError>&&)>;
    using Promise = WTF::NativePromise<Expected<std::pair<String, Vector<WebCore::IntSize>>, WebCore::ImageDecodingError>, IPC::Error>;
    explicit GetInformationFromImageData(const Vector<uint8_t>& imageData)
        : m_imageData(imageData)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<uint8_t>& m_imageData;
};
#endif

#if PLATFORM(COCOA)
class CreateBitmapsFromImageData {
public:
    using Arguments = std::tuple<Ref<WebCore::SharedBuffer>, Vector<unsigned>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CreateBitmapsFromImageData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_CreateBitmapsFromImageDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<Vector<Ref<WebCore::ShareableBitmap>>>;
    using Reply = CompletionHandler<void(Vector<Ref<WebCore::ShareableBitmap>>&&)>;
    using Promise = WTF::NativePromise<Vector<Ref<WebCore::ShareableBitmap>>, IPC::Error>;
    CreateBitmapsFromImageData(const Ref<WebCore::SharedBuffer>& imageData, const Vector<unsigned>& lengths)
        : m_imageData(imageData)
        , m_lengths(lengths)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_lengths;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::SharedBuffer>& m_imageData;
    SUPPRESS_FORWARD_DECL_MEMBER const Vector<unsigned>& m_lengths;
};
#endif

#if PLATFORM(COCOA)
class DecodeImageData {
public:
    using Arguments = std::tuple<Ref<WebCore::SharedBuffer>, std::optional<WebCore::FloatSize>>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DecodeImageData; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_DecodeImageDataReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<RefPtr<WebCore::ShareableBitmap>>;
    using Reply = CompletionHandler<void(RefPtr<WebCore::ShareableBitmap>&&)>;
    using Promise = WTF::NativePromise<RefPtr<WebCore::ShareableBitmap>, IPC::Error>;
    DecodeImageData(const Ref<WebCore::SharedBuffer>& imageData, const std::optional<WebCore::FloatSize>& preferredSize)
        : m_imageData(imageData)
        , m_preferredSize(preferredSize)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_imageData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_preferredSize;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const Ref<WebCore::SharedBuffer>& m_imageData;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebCore::FloatSize>& m_preferredSize;
};
#endif

class FrameNameWasChangedInAnotherProcess {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_FrameNameWasChangedInAnotherProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    FrameNameWasChangedInAnotherProcess(const WebCore::FrameIdentifier& frameID, const String& frameName)
        : m_frameID(frameID)
        , m_frameName(frameName)
    {
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

#if ENABLE(VIDEO_PRESENTATION_MODE)
class StartPlayingPredominantVideo {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_StartPlayingPredominantVideo; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_StartPlayingPredominantVideoReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    StartPlayingPredominantVideo()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

class CloseCurrentTypingCommand {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_CloseCurrentTypingCommand; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CloseCurrentTypingCommand()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

class SimulateClickOverFirstMatchingTextInViewportWithUserInteraction {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SimulateClickOverFirstMatchingTextInViewportWithUserInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::WebPage_SimulateClickOverFirstMatchingTextInViewportWithUserInteractionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit SimulateClickOverFirstMatchingTextInViewportWithUserInteraction(const String& targetText)
        : m_targetText(targetText)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_targetText;
    }

private:
    const String& m_targetText;
};

class UpdateOpener {
public:
    using Arguments = std::tuple<WebCore::FrameIdentifier, WebCore::FrameIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_UpdateOpener; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateOpener(const WebCore::FrameIdentifier& frameID, const WebCore::FrameIdentifier& newOpener)
        : m_frameID(frameID)
        , m_newOpener(newOpener)
    {
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

#if HAVE(AUDIT_TOKEN)
class SetPresentingApplicationAuditTokenAndBundleIdentifier {
public:
    using Arguments = std::tuple<WebKit::CoreIPCAuditToken, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_SetPresentingApplicationAuditTokenAndBundleIdentifier; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetPresentingApplicationAuditTokenAndBundleIdentifier(const WebKit::CoreIPCAuditToken& auditToken, const String& bundleIdentifier)
        : m_auditToken(auditToken)
        , m_bundleIdentifier(bundleIdentifier)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_auditToken;
        encoder << m_bundleIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::CoreIPCAuditToken& m_auditToken;
    const String& m_bundleIdentifier;
};
#endif

#if USE(UICONTEXTMENU)
class WillBeginContextMenuInteraction {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_WillBeginContextMenuInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    WillBeginContextMenuInteraction()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

#if USE(UICONTEXTMENU)
class DidEndContextMenuInteraction {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::WebPage_DidEndContextMenuInteraction; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidEndContextMenuInteraction()
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};
#endif

} // namespace WebPage
} // namespace Messages
