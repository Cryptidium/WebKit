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

#pragma once

#include <wtf/ArgumentCoder.h>
#include <wtf/OptionSet.h>
#include <wtf/Ref.h>
#include <wtf/RetainPtr.h>
#if USE(CF)
#ifdef __swift__
#include <Security/SecTrust.h>
#else
typedef struct CF_BRIDGED_TYPE(id) __SecTrust *SecTrustRef;
#endif
#endif

namespace API {
class Array;
class Data;
class Dictionary;
class Error;
class FrameHandle;
class Size;
class Point;
class Rect;
class Boolean;
class Double;
class UInt64;
class Int64;
class Object;
class PageHandle;
class String;
class URL;
class URLRequest;
class URLResponse;
class UserContentURLPattern;
}

namespace IPC {
enum class MessageFlags : uint8_t;
class ConnectionHandle;
class FormDataReference;
class Signal;
class Semaphore;
class SharedBufferReference;
class SharedFileHandle;
struct StreamServerConnectionHandle;
enum class SyncRequestIDType;
struct AsyncReplyIDType;
}

namespace Inspector {
enum class DebuggableType : uint8_t;
#if ENABLE(INSPECTOR_EXTENSIONS)
enum class ExtensionError : uint8_t;
#endif
#if ENABLE(INSPECTOR_EXTENSIONS)
enum class ExtensionAppearance : bool;
#endif
enum class InspectorTargetType : uint8_t;
}

namespace JSC {
enum class MessageSource : uint8_t;
enum class MessageType : uint8_t;
enum class MessageLevel : uint8_t;
enum class SourceTaintedOrigin : uint8_t;
class ArrayBuffer;
class ArrayBufferContents;
enum class MicrotaskIdentifierType;
}

namespace PAL {
class SessionID;
}

namespace PlatformXR {
#if ENABLE(WEBXR)
enum class Layout : uint8_t;
#endif
#if ENABLE(WEBXR)
enum class SessionFeature : uint8_t;
#endif
#if ENABLE(WEBXR)
enum class SessionMode : uint8_t;
#endif
#if ENABLE(WEBXR)
enum class ReferenceSpaceType : uint8_t;
#endif
#if ENABLE(WEBXR)
enum class VisibilityState : uint8_t;
#endif
#if ENABLE(WEBXR)
enum class XRHandedness : uint8_t;
#endif
#if ENABLE(WEBXR)
enum class XRTargetRayMode : uint8_t;
#endif
#if (ENABLE(WEBXR)) && (USE(OPENXR))
enum class Eye : uint8_t;
#endif
#if ENABLE(WEBXR)
struct RequestData;
#endif
#if ENABLE(WEBXR)
struct FrameData;
#endif
}

namespace TestWebKitAPI {
enum class TestedObjectIdentifierType;
}

namespace WTF {
enum class SystemMemoryPressureStatus : uint8_t;
class URL;
class CString;
class MediaTime;
class Seconds;
class MonotonicTime;
class WallTime;
class AtomString;
class UUID;
struct MemoryPressureHandlerConfiguration;
#if PLATFORM(COCOA)
struct MachSendRightAnnotated;
#endif
class Win32Handle;
}

namespace WTF::JSONImpl {
class Value;
}

namespace WebCore {
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
enum class TextDrawingMode : uint8_t;
#endif
enum class LockHistory : bool;
enum class LockBackForwardList : bool;
enum class SameSiteStrictEnforcementEnabled : bool;
enum class FontWidthVariant : uint8_t;
enum class Kerning : uint8_t;
enum class FontOpticalSizing : bool;
enum class FontStyleAxis : uint8_t;
enum class AllowUserInstalledFonts : bool;
enum class FontVariantEastAsianVariant : uint8_t;
enum class FontVariantEastAsianWidth : uint8_t;
enum class FontVariantEastAsianRuby : uint8_t;
enum class FontVariantLigatures : uint8_t;
enum class FontVariantPosition : uint8_t;
enum class FontVariantCaps : uint8_t;
enum class FontVariantNumericFigure : uint8_t;
enum class FontVariantNumericSpacing : uint8_t;
enum class FontVariantNumericFraction : uint8_t;
enum class TextRenderingMode : uint8_t;
enum class FontSmoothingMode : uint8_t;
enum class FontOrientation : bool;
enum class NonCJKGlyphOrientation : bool;
enum class FontVariantNumericOrdinal : bool;
enum class FontVariantNumericSlashedZero : bool;
enum class FontSynthesisLonghandValue : bool;
enum class FontSmallCaps : bool;
#if ENABLE(APPLE_PAY)
enum class ApplePayFeature : uint8_t;
#endif
#if ENABLE(APPLE_PAY)
enum class ApplePayPaymentTiming : uint8_t;
#endif
#if ENABLE(APPLE_PAY_RECURRING_LINE_ITEM)
enum class ApplePayRecurringPaymentDateUnit : uint8_t;
#endif
enum class ContactProperty : uint8_t;
enum class CookieConsentDecisionResult : uint8_t;
enum class IDBResultType : uint8_t;
enum class IDBTransactionDurability : uint8_t;
enum class IDBTransactionMode : uint8_t;
#if ENABLE(MEDIA_SESSION)
enum class MediaSessionAction : uint8_t;
#endif
#if ENABLE(MEDIA_SESSION)
enum class MediaSessionPlaybackState : uint8_t;
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
enum class MediaSessionCoordinatorState : uint8_t;
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
enum class MediaSessionReadyState : uint8_t;
#endif
enum class RTCErrorDetailType : uint8_t;
enum class NotificationEventType : bool;
enum class PermissionName : uint8_t;
enum class PermissionQuerySource : uint8_t;
enum class PermissionState : uint8_t;
enum class PushPermissionState : uint8_t;
enum class AutofillFieldName : uint8_t;
enum class NonAutofillCredentialType : bool;
enum class EnterKeyHint : uint8_t;
enum class DownloadableBinaryFontTrustedTypes : uint8_t;
enum class LoadSchedulingMode : uint8_t;
enum class ServiceWorkersMode : uint8_t;
enum class ShouldTreatAsContinuingLoad : uint8_t;
enum class ContentSecurityPolicyModeForExtension : uint8_t;
enum class MediaProducerMediaCaptureKind : uint8_t;
enum class ScreenOrientationType : uint8_t;
enum class StorageBlockingPolicy : uint8_t;
enum class HTTPSByDefaultMode : uint8_t;
#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
enum class TranslationContextMenuMode : bool;
#endif
#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
enum class TranslationContextMenuSource : bool;
#endif
#if USE(APPKIT)
enum class AppKitControlSystemImageType : uint8_t;
#endif
enum class ScrollIsAnimated : bool;
enum class ScrollGranularity : uint8_t;
enum class IDBGetRecordDataType : bool;
enum class NavigatorAPIsAccessed : uint64_t;
enum class ScreenAPIsAccessed : uint64_t;
enum class SandboxFlag : uint16_t;
enum class ViewportFit : uint8_t;
enum class ShareDataOriginator : bool;
enum class PositionType : uint8_t;
#if ENABLE(APPLE_PAY)
enum class ApplePayLogoStyle : bool;
#endif
#if ENABLE(APPLE_PAY)
enum class ApplePayErrorContactField : uint8_t;
#endif
#if ENABLE(APPLE_PAY)
enum class ApplePayContactField : uint8_t;
#endif
#if ENABLE(APPLE_PAY)
enum class ApplePayErrorCode : uint8_t;
#endif
#if ENABLE(APPLE_PAY_INSTALLMENTS)
enum class ApplePaySetupFeatureType : bool;
#endif
#if ENABLE(APPLE_PAY_INSTALLMENTS)
enum class ApplePayInstallmentItemType : uint8_t;
#endif
#if ENABLE(APPLE_PAY_INSTALLMENTS)
enum class ApplePayInstallmentRetailChannel : uint8_t;
#endif
enum class ScreenOrientationLockType : uint8_t;
#if ENABLE(WEB_CODECS)
enum class WebCodecsEncodedVideoChunkType : bool;
#endif
#if ENABLE(WEB_CODECS)
enum class WebCodecsEncodedAudioChunkType : bool;
#endif
enum class VideoEncoderScalabilityMode : uint8_t;
enum class SpeechRecognitionErrorType : uint8_t;
enum class WebLockMode : bool;
#if ENABLE(WEB_AUTHN)
enum class AttestationConveyancePreference : uint8_t;
#endif
enum class ShouldPartitionCookie : bool;
enum class RenderingMode : uint8_t;
enum class RenderingPurpose : uint8_t;
enum class ContentsFormat : uint8_t;
enum class RotationDirection : bool;
enum class IsLoggedIn : uint8_t;
enum class AutoplayEvent : uint8_t;
enum class InputMode : uint8_t;
enum class WorkerType : bool;
enum class StoredCredentialsPolicy : uint8_t;
enum class ContentSniffingPolicy : bool;
enum class ContentEncodingSniffingPolicy : bool;
enum class ClientCredentialPolicy : bool;
enum class ShouldRelaxThirdPartyCookieBlocking : bool;
enum class PreflightPolicy : uint8_t;
enum class ScrollSnapStrictness : uint8_t;
enum class LengthType : uint8_t;
enum class OverscrollBehavior : uint8_t;
enum class ScrollPinningBehavior : uint8_t;
enum class WheelScrollGestureState : uint8_t;
enum class DiagnosticLoggingDomain : uint8_t;
enum class MediaCaptureType : uint8_t;
#if ENABLE(ATTACHMENT_ELEMENT)
enum class AttachmentAssociatedElementType : uint8_t;
#endif
enum class TextCheckingProcessType : bool;
enum class ColorSpace : uint8_t;
enum class VideoCodecType : uint8_t;
#if HAVE(SUPPORT_HDR_DISPLAY)
enum class ContentsFormat : uint8_t;
#endif
#if ENABLE(WEB_AUTHN)
enum class AuthenticatorTransport : uint8_t;
#endif
#if ENABLE(WEB_AUTHN)
enum class PublicKeyCredentialType : bool;
#endif
#if PLATFORM(IOS_FAMILY)
enum class SelectionRenderingBehavior : bool;
#endif
enum class DataListSuggestionActivationType : uint8_t;
enum class AlphaPremultiplication : uint8_t;
enum class PixelFormat : uint8_t;
enum class UseLosslessCompression : bool;
enum class ImageBufferPixelFormat : uint8_t;
enum class TextIndicatorLifetime : uint8_t;
enum class HasInsecureContent : bool;
enum class ScrollElasticity : uint8_t;
enum class ScrollbarMode : uint8_t;
enum class NativeScrollbarVisibility : uint8_t;
enum class ScrollUpdateType : uint8_t;
enum class ScrollingLayerPositionAction : uint8_t;
enum class WheelEventProcessingSteps : uint8_t;
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
enum class GraphicsContextGLPowerPreference : uint8_t;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
enum class GraphicsContextGLSimulatedCreationFailure : uint8_t;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
enum class GraphicsContextGLFlipY : bool;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
enum class GraphicsContextGLSimulatedEventForTesting : uint8_t;
#endif
enum class CSSBoxType : uint8_t;
#if ENABLE(WEB_AUTHN)
enum class UserVerificationRequirement : uint8_t;
#endif
#if ENABLE(WEB_AUTHN)
enum class ResidentKeyRequirement : uint8_t;
#endif
#if ENABLE(WEB_AUTHN)
enum class AuthenticatorAttachment : uint8_t;
#endif
enum class ResourceRequestCachePolicy : uint8_t;
enum class ResourceLoadPriority : uint8_t;
enum class ResourceResponseSource : uint8_t;
enum class UsedLegacyTLS : bool;
enum class WasPrivateRelayed : bool;
enum class ReferrerPolicy : uint8_t;
enum class FetchOptionsDestination : uint8_t;
enum class FetchOptionsMode : uint8_t;
enum class FetchOptionsCredentials : uint8_t;
enum class FetchOptionsCache : uint8_t;
enum class FetchOptionsRedirect : uint8_t;
enum class FetchHeadersGuard : uint8_t;
enum class StyleAppearance : uint8_t;
#if ENABLE(APPLE_PAY)
enum class ApplePayButtonType : uint8_t;
#endif
#if ENABLE(APPLE_PAY)
enum class ApplePayButtonStyle : uint8_t;
#endif
enum class ModalContainerDecision : uint8_t;
enum class AutoplayEventFlags : uint8_t;
enum class FocusDirection : uint8_t;
#if ENABLE(GAMEPAD)
enum class GamepadHapticEffectType : uint8_t;
#endif
enum class DOMPasteAccessCategory : uint8_t;
enum class DOMPasteAccessPolicy : uint8_t;
enum class DOMPasteAccessResponse : uint8_t;
enum class DeviceOrientationOrMotionPermissionState : uint8_t;
enum class SecurityPolicyViolationEventDisposition : bool;
enum class VerticalAlignChange : uint8_t;
enum class TextGranularity : uint8_t;
enum class RunAsAsyncFunction : bool;
enum class ForceUserGesture : bool;
enum class RemoveTransientActivation : bool;
enum class WritingDirection : uint8_t;
enum class SelectionDirection : uint8_t;
#if ENABLE(DATA_DETECTION)
enum class DataDetectorType : uint8_t;
#endif
enum class AutocapitalizeType : uint8_t;
enum class CrossOriginEmbedderPolicyValue : bool;
enum class IncludeSecureCookies : bool;
#if ENABLE(ASYNC_SCROLLING)
enum class ScrollingStateNodeProperty : uint64_t;
#endif
enum class ScrollClamping : bool;
enum class ScrollType : bool;
enum class ScrollSnapStop : bool;
#if ENABLE(ENCRYPTED_MEDIA)
enum class CDMEncryptionScheme : bool;
#endif
#if ENABLE(ENCRYPTED_MEDIA)
enum class CDMKeyGroupingStrategy : bool;
#endif
#if ENABLE(ENCRYPTED_MEDIA)
enum class CDMSessionType : uint8_t;
#endif
enum class MediaDecodingType : uint8_t;
enum class MediaEncodingType : bool;
#if ENABLE(VIDEO)
enum class VideoMediaSampleRendererPreference : uint8_t;
#endif
enum class MediaPlayerNetworkState : uint8_t;
enum class MediaPlayerReadyState : uint8_t;
enum class MediaPlayerMovieLoadType : uint8_t;
enum class MediaPlayerPreload : uint8_t;
enum class MediaPlayerVideoGravity : uint8_t;
enum class MediaPlayerSupportsType : uint8_t;
enum class MediaPlayerBufferingPolicy : uint8_t;
enum class MediaPlayerMediaEngineIdentifier : uint8_t;
enum class MediaPlayerWirelessPlaybackTargetType : uint8_t;
enum class MediaPlayerPitchCorrectionAlgorithm : uint8_t;
enum class MediaPlayerSoundStageSize : uint8_t;
#if ENABLE(APP_HIGHLIGHTS)
enum class CreateNewGroupForHighlight : bool;
#endif
#if ENABLE(APP_HIGHLIGHTS)
enum class HighlightRequestOriginatedInApp : bool;
#endif
enum class SpeechRecognitionUpdateType : uint8_t;
enum class CompositeOperator : uint8_t;
enum class BlendMode : uint8_t;
enum class GradientSpreadMethod : uint8_t;
enum class InterpolationQuality : uint8_t;
#if ENABLE(VIDEO)
enum class VideoFrameRotation : uint16_t;
#endif
enum class PreserveResolution : bool;
enum class ColorInterpolationColorSpace : uint8_t;
enum class HueInterpolationMethod : uint8_t;
#if USE(AUDIO_SESSION)
enum class RouteSharingPolicy : uint8_t;
#endif
#if USE(AUDIO_SESSION)
enum class AudioSessionCategory : uint8_t;
#endif
#if USE(AUDIO_SESSION)
enum class AudioSessionMode : uint8_t;
#endif
#if USE(AUDIO_SESSION)
enum class AudioSessionSoundStageSize : uint8_t;
#endif
#if USE(AUDIO_SESSION)
enum class AudioSessionMayResume : bool;
#endif
#if USE(AUDIO_SESSION)
enum class AudioSessionRoutingArbitrationError : uint8_t;
#endif
#if ENABLE(ENCRYPTED_MEDIA)
enum class CDMKeyStatus : uint8_t;
#endif
#if ENABLE(ENCRYPTED_MEDIA)
enum class CDMMessageType : uint8_t;
#endif
#if ENABLE(ENCRYPTED_MEDIA)
enum class CDMRequirement : uint8_t;
#endif
#if ENABLE(ENCRYPTED_MEDIA)
enum class CDMInstanceSessionLoadFailure : uint8_t;
#endif
#if ENABLE(WEB_RTC)
enum class RTCDataChannelState : uint8_t;
#endif
#if ENABLE(WEB_RTC)
enum class RTCPriorityType : uint8_t;
#endif
enum class LineCap : uint8_t;
enum class LineJoin : uint8_t;
enum class StrokeStyle : uint8_t;
enum class TextDrawingMode : uint8_t;
enum class DecodingMode : uint8_t;
enum class DocumentMarkerLineStyleMode : uint8_t;
enum class DrawsHDRContent : uint8_t;
enum class CrossOriginOpenerPolicyValue : uint8_t;
enum class HTTPCookieAcceptPolicy : uint8_t;
enum class NetworkLoadPriority : uint8_t;
enum class PrivacyStance : uint8_t;
enum class ThirdPartyCookieBlockingMode : uint8_t;
enum class FirstPartyWebsiteDataRemovalMode : uint8_t;
enum class DragApplicationFlags : uint8_t;
enum class TextCheckingType : uint8_t;
enum class ServiceWorkerClientType : uint8_t;
enum class ServiceWorkerJobType : uint8_t;
enum class ServiceWorkerRegistrationState : uint8_t;
enum class ServiceWorkerState : uint8_t;
enum class ServiceWorkerClientFrameType : uint8_t;
enum class ServiceWorkerIsInspectable : bool;
enum class ShouldNotifyWhenResolved : bool;
enum class ServiceWorkerUpdateViaCache : uint8_t;
enum class LastNavigationWasAppInitiated : bool;
enum class RouterSourceEnum : uint8_t;
enum class RunningStatus : bool;
enum class StorageAccessWasGranted : uint8_t;
enum class StorageAccessPromptWasShown : bool;
enum class StorageAccessScope : bool;
enum class StorageAccessQuickResult : bool;
#if ENABLE(MEDIA_STREAM)
enum class MediaConstraintType : uint8_t;
#endif
#if ENABLE(MEDIA_STREAM)
enum class VideoFacingMode : uint8_t;
#endif
#if ENABLE(MEDIA_STREAM)
enum class DisplaySurfaceType : uint8_t;
#endif
#if ENABLE(MEDIA_STREAM)
enum class MeteringMode : uint8_t;
#endif
enum class PlatformVideoColorPrimaries : uint8_t;
enum class PlatformVideoTransferCharacteristics : uint8_t;
enum class PlatformVideoMatrixCoefficients : uint8_t;
#if ENABLE(VIDEO)
enum class VideoProjectionMetadataKind : uint8_t;
#endif
enum class PolicyAction : uint8_t;
enum class ReloadOption : uint8_t;
enum class FrameLoadType : uint8_t;
enum class NavigationType : uint8_t;
enum class BrowsingContextGroupSwitchDecision : uint8_t;
enum class ShouldOpenExternalURLsPolicy : uint8_t;
enum class ScheduleLocationChangeResult : uint8_t;
enum class MouseEventPolicy : uint8_t;
enum class ColorSchemePreference : uint8_t;
enum class ModalContainerObservationPolicy : bool;
enum class AllowsContentJavaScript : bool;
enum class AdvancedPrivacyProtections : uint16_t;
enum class ViolationReportType : uint8_t;
enum class COEPDisposition : bool;
enum class LinkIconType : uint8_t;
enum class PasteboardItemPresentationStyle : uint8_t;
#if HAVE(SCREEN_CAPTURE_KIT)
enum class DisplayCapturePromptType : uint8_t;
#endif
enum class TextIndicatorPresentationTransition : uint8_t;
enum class TextIndicatorOption : uint16_t;
enum class StorageType : uint8_t;
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
enum class TransformBox : uint8_t;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
enum class AcceleratedEffectProperty : uint16_t;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
enum class WebAnimationType : uint8_t;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
enum class FillMode : uint8_t;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
enum class PlaybackDirection : uint8_t;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
enum class CompositeOperation : uint8_t;
#endif
#if PLATFORM(MAC)
enum class CaretAnimatorType : uint8_t;
#endif
enum class RenderAsTextFlag : uint16_t;
enum class LayerTreeAsTextOptions : uint16_t;
#if ENABLE(MEDIA_STREAM)
enum class MediaAccessDenialReason : uint8_t;
#endif
#if ENABLE(MEDIA_STREAM)
enum class FillLightMode : uint8_t;
#endif
#if ENABLE(MEDIA_STREAM)
enum class RedEyeReduction : uint8_t;
#endif
#if ENABLE(MODEL_PROCESS)
enum class ModelContextDisablePortal : bool;
#endif
enum class InspectorFrontendClientAppearance : uint8_t;
enum class UserScriptInjectionTime : bool;
enum class UserContentInjectedFrames : bool;
enum class UserContentMatchParentFrame : uint8_t;
enum class WindRule : bool;
enum class ContentSecurityPolicyHeaderType : bool;
enum class WheelEventTestMonitorDeferReason : uint16_t;
enum class HTTPHeadersToKeepFromCleaning : uint8_t;
enum class ExceptionCode : uint8_t;
enum class BackgroundFetchFailureReason : uint8_t;
enum class BackgroundFetchResult : uint8_t;
enum class ResourceErrorBaseType : uint8_t;
enum class CredentialPersistence : uint8_t;
enum class PaginationMode : uint8_t;
enum class RepaintRectCalculation : bool;
#if ENABLE(WEB_AUTHN)
enum class MediationRequirement : uint8_t;
#endif
#if ENABLE(CONTEXT_MENUS)
enum class ContextMenuContextType : uint8_t;
#endif
enum class CrossSiteNavigationDataTransferFlag : uint8_t;
#if ENABLE(VIDEO)
enum class CaptionUserPreferencesDisplayMode : uint8_t;
#endif
enum class InspectorBackendClientDeveloperPreference : uint8_t;
#if HAVE(CORE_MATERIAL)
enum class AppleVisualEffect : uint8_t;
#endif
#if ENABLE(MEDIA_SOURCE)
enum class MediaSourcePrivateAddStatus : uint8_t;
#endif
#if ENABLE(MEDIA_SOURCE)
enum class MediaSourcePrivateEndOfStreamStatus : uint8_t;
#endif
#if ENABLE(MEDIA_SOURCE)
enum class SourceBufferAppendMode : uint8_t;
#endif
enum class WindowProxyProperty : uint8_t;
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
enum class IncludeDynamicContentScalingDisplayList : bool;
#endif
enum class PlatformCursorType : uint8_t;
enum class ContextMenuItemType : uint8_t;
enum class PredefinedColorSpace : uint8_t;
enum class TransformOperationType : uint8_t;
enum class GraphicsContextGLSurfaceBuffer : bool;
enum class CompositeOperationType : uint8_t;
enum class ColorMatrixType : uint8_t;
enum class TurbulenceType : uint8_t;
enum class FilterRenderingMode : uint8_t;
enum class LightType : uint8_t;
enum class ComponentTransferType : uint8_t;
enum class ComponentTransferChannel : uint8_t;
enum class MorphologyOperatorType : uint8_t;
enum class ChannelSelectorType : uint8_t;
enum class EdgeModeType : uint8_t;
enum class ResolvedEmojiPolicy : uint8_t;
enum class ScrollBehaviorForFixedElements : bool;
enum class ContentExtensionDefaultEnablement : bool;
enum class RequiresClipToRect : bool;
enum class HighlightVisibility : bool;
#if ENABLE(VIDEO)
enum class PlatformMediaError : uint8_t;
#endif
enum class NotificationDirection : uint8_t;
enum class CrossOriginMode : bool;
enum class WorkerThreadMode : bool;
enum class WillContinueLoading : bool;
#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
enum class CDMPrivateLocalStorageAccess : bool;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
enum class CDMInstanceAllowPersistentState : bool;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
enum class CDMInstanceSuccessValue : bool;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
enum class CDMInstanceAllowDistinctiveIdentifiers : bool;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
enum class ShouldContinuePolicyCheck : bool;
#endif
#if ENABLE(GAMEPAD)
enum class EventMakesGamepadsVisible : bool;
#endif
#if (ENABLE(GAMEPAD)) && (PLATFORM(VISION))
enum class ShouldRequireExplicitConsentForGamepadAccess : bool;
#endif
enum class WillInternallyHandleFailure : bool;
enum class ApplyTrackingPrevention : bool;
enum class ShouldSample : bool;
enum class FromDownloadAttribute : bool;
enum class RequiresScriptTrackingPrivacy : bool;
#if PLATFORM(COCOA)
enum class ImageDecodingError : uint8_t;
#endif
enum class FileSystemWriteCommandType : uint8_t;
enum class FileSystemWriteCloseReason : bool;
enum class CryptoKeyUsage : uint8_t;
enum class CryptoAlgorithmIdentifier : uint8_t;
enum class CryptoKeyClass : uint8_t;
enum class CryptoKeyType : uint8_t;
#if ENABLE(DOM_AUDIO_SESSION)
enum class DOMAudioSessionType : uint8_t;
#endif
enum class DocumentClass : uint16_t;
#if ENABLE(MODEL_PROCESS)
enum class StageModeOperation : bool;
#endif
enum class PredominantColorType : uint8_t;
enum class ShouldGoToHistoryItem : uint8_t;
enum class ProcessSwapDisposition : uint8_t;
enum class FoundElementInRemoteFrame : bool;
enum class ScriptTrackingPrivacyFlag : uint16_t;
enum class UserInterfaceLayoutDirection : bool;
enum class TextDirection : bool;
#if ENABLE(GPU_PROCESS) && PLATFORM(IOS_FAMILY)
enum class ShouldPause : bool;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(IOS_FAMILY)
enum class HasAvailableTargets : bool;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(IOS_FAMILY)
enum class SupportsAirPlayVideo : bool;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(IOS_FAMILY)
enum class PlayingToAutomotiveHeadUnit : bool;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(IOS_FAMILY)
enum class SuspendedUnderLock : bool;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(IOS_FAMILY)
enum class SupportsSpatialAudioPlayback : bool;
#endif
enum class HTTPHeaderName : uint16_t;
enum class ActivityState : uint16_t;
enum class DragDestinationAction : uint8_t;
enum class DragHandlingMethod : uint8_t;
enum class DragOperation : uint8_t;
enum class DragOperation : uint8_t;
enum class DragSourceAction : uint8_t;
enum class DragSourceAction : uint8_t;
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
enum class InbandTextTrackPrivateMode : uint8_t;
#endif
enum class LayoutMilestone : uint16_t;
enum class MDNSRegisterError : uint8_t;
enum class MediaProducerMediaState : uint32_t;
enum class MediaProducerMutedState : uint8_t;
enum class PlatformEventModifier : uint8_t;
enum class PlatformMediaSessionRemoteControlCommandType : uint8_t;
enum class DynamicRangeMode : uint8_t;
enum class PlatformWheelEventPhase : uint8_t;
enum class ProcessSyncDataType : uint8_t;
enum class ProtectionSpaceBaseServerType : uint8_t;
enum class ProtectionSpaceBaseAuthenticationScheme : uint8_t;
enum class ScrollDirection : uint8_t;
enum class ScrollbarOrientation : uint8_t;
enum class ScrollbarWidth : uint8_t;
enum class RubberBandingBehavior : uint8_t;
enum class ScrollbarOverlayStyle : uint8_t;
struct PathMoveTo;
struct PathLineTo;
struct PathQuadCurveTo;
struct PathBezierCurveTo;
struct PathArcTo;
struct PathArc;
struct PathClosedArc;
struct PathEllipse;
struct PathEllipseInRect;
struct PathRect;
struct PathRoundedRect;
struct PathContinuousRoundedRect;
struct PathDataLine;
struct PathDataQuadCurve;
struct PathDataBezierCurve;
struct PathDataArc;
struct PathCloseSubpath;
class PathSegment;
struct PasteboardImage;
struct PasteboardWebContent;
struct PasteboardURL;
struct PasteboardBuffer;
struct SerializedNode;
#if ENABLE(IMAGE_ANALYSIS)
struct TextRecognitionWordData;
#endif
#if ENABLE(IMAGE_ANALYSIS)
struct TextRecognitionLineData;
#endif
#if ENABLE(IMAGE_ANALYSIS)
struct TextRecognitionBlockData;
#endif
#if ENABLE(IMAGE_ANALYSIS)
struct TextRecognitionResult;
#endif
#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
struct TranslationContextMenuInfo;
#endif
#if USE(APPKIT)
class AppKitControlSystemImage;
#endif
class TransformationMatrix;
struct CacheQueryOptions;
struct CharacterRange;
class AffineTransform;
class FloatPoint;
class FloatPoint3D;
class FloatQuad;
struct IDBCursorRecord;
class IDBCursorInfo;
class IDBError;
struct IDBGetAllRecordsData;
class IDBGetResult;
class IDBGetAllResult;
class IDBDatabaseInfo;
struct IDBKeyRangeData;
class IDBTransactionInfo;
struct IDBGetRecordData;
class IDBIndexInfo;
class IDBObjectStoreInfo;
struct IDBIterateCursorData;
class IDBResourceIdentifier;
class IDBValue;
class IDBOpenRequestData;
class IDBRequestData;
class IDBDatabaseIdentifier;
struct IDBDatabaseNameAndVersion;
class IDBResultData;
class IDBKeyData;
class IndexKey;
class FloatRect;
class LinearTimingFunction;
class CubicBezierTimingFunction;
class StepsTimingFunction;
class SpringTimingFunction;
struct ResourceLoadStatistics;
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
struct GraphicsContextGLActiveInfo;
#endif
struct ShareDataWithParsedURL;
struct ShareData;
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
struct SpatialBackdropSource;
#endif
struct TargetedElementAdjustment;
struct TargetedElementRequest;
struct TargetedElementInfo;
struct RawFile;
class FloatRoundedRect;
class IntRect;
class IntPoint;
class IntSize;
class FloatSize;
class LayoutUnit;
class LayoutPoint;
class LayoutSize;
struct DictionaryPopupInfo;
class PrivateClickMeasurement;
#if ENABLE(APPLE_PAY_RECURRING_PAYMENTS)
struct ApplePayRecurringPaymentRequest;
#endif
#if ENABLE(APPLE_PAY_MULTI_MERCHANT_PAYMENTS)
struct ApplePayPaymentTokenContext;
#endif
#if ENABLE(APPLE_PAY_DEFERRED_PAYMENTS)
struct ApplePayDeferredPaymentRequest;
#endif
#if ENABLE(APPLE_PAY_PAYMENT_ORDER_DETAILS)
struct ApplePayPaymentOrderDetails;
#endif
#if ENABLE(APPLE_PAY_AMS_UI) && ENABLE(PAYMENT_REQUEST)
struct ApplePayAMSUIRequest;
#endif
#if ENABLE(APPLE_PAY_AUTOMATIC_RELOAD_PAYMENTS)
struct ApplePayAutomaticReloadPaymentRequest;
#endif
#if ENABLE(APPLE_PAY_SHIPPING_METHOD_DATE_COMPONENTS_RANGE)
struct ApplePayDateComponents;
#endif
#if ENABLE(APPLE_PAY_SHIPPING_METHOD_DATE_COMPONENTS_RANGE)
struct ApplePayDateComponentsRange;
#endif
#if ENABLE(APPLE_PAY)
struct ApplePaySetupConfiguration;
#endif
#if ENABLE(APPLE_PAY)
struct ApplePayLineItem;
#endif
#if ENABLE(APPLE_PAY)
struct ApplePayShippingMethod;
#endif
#if ENABLE(APPLE_PAY)
class ApplePayError;
#endif
#if ENABLE(APPLE_PAY)
class ApplePayLogoSystemImage;
#endif
#if ENABLE(APPLE_PAY)
struct ApplePayDetailsUpdateBase;
#endif
#if ENABLE(APPLE_PAY)
struct ApplePayPaymentMethodUpdate;
#endif
#if ENABLE(APPLE_PAY)
struct ApplePayShippingContactUpdate;
#endif
#if ENABLE(APPLE_PAY)
struct ApplePayShippingMethodUpdate;
#endif
#if ENABLE(APPLE_PAY)
struct ApplePayPaymentAuthorizationResult;
#endif
#if ENABLE(APPLE_PAY_DISBURSEMENTS)
struct ApplePayDisbursementRequest;
#endif
#if ENABLE(APPLE_PAY_INSTALLMENTS)
struct ApplePayInstallmentConfiguration;
#endif
#if ENABLE(APPLE_PAY_INSTALLMENTS)
class PaymentInstallmentConfiguration;
#endif
#if ENABLE(APPLE_PAY_INSTALLMENTS)
struct ApplePayInstallmentItem;
#endif
#if ENABLE(APPLE_PAY_COUPON_CODE)
struct ApplePayCouponCodeUpdate;
#endif
#if ENABLE(APPLICATION_MANIFEST)
struct ApplicationManifest;
#endif
struct RetrieveRecordsOptions;
struct ContactInfo;
struct ContactsRequestData;
#if ENABLE(MEDIA_SESSION)
struct MediaPositionState;
#endif
#if ENABLE(WEB_RTC)
struct DetachedRTCDataChannel;
#endif
#if ENABLE(WEB_CODECS)
struct WebCodecsEncodedVideoChunkData;
#endif
#if ENABLE(WEB_CODECS)
struct WebCodecsEncodedAudioChunkData;
#endif
struct HTMLModelElementCamera;
struct NotificationData;
struct PermissionDescriptor;
struct PushSubscriptionData;
class DeprecationReportBody;
class Report;
class TestReportBody;
struct SpeechRecognitionError;
struct SpeechRecognitionRequestInfo;
struct SpeechRecognitionAlternativeData;
struct SpeechRecognitionResultData;
struct WebLockManagerSnapshot;
#if ENABLE(WEB_AUTHN)
struct AuthenticatorResponseBaseData;
#endif
#if ENABLE(WEB_AUTHN)
struct AuthenticatorAttestationResponseData;
#endif
#if ENABLE(WEB_AUTHN)
struct AuthenticatorAssertionResponseData;
#endif
#if ENABLE(WEB_AUTHN)
struct AuthenticatorResponseData;
#endif
#if ENABLE(WEB_AUTHN)
struct AuthenticationExtensionsClientInputs;
#endif
#if ENABLE(WEB_AUTHN)
struct CredentialPropertiesOutput;
#endif
#if ENABLE(WEB_AUTHN)
struct AuthenticationExtensionsClientOutputs;
#endif
#if ENABLE(WEB_AUTHN)
struct UnknownCredentialOptions;
#endif
#if ENABLE(WEB_AUTHN)
struct AllAcceptedCredentialsOptions;
#endif
#if ENABLE(WEB_AUTHN)
struct CurrentUserDetailsOptions;
#endif
#if ENABLE(WEB_AUTHN)
struct AuthenticatorSelectionCriteria;
#endif
#if ENABLE(WEB_AUTHN)
struct PublicKeyCredentialEntity;
#endif
#if ENABLE(WEB_AUTHN)
struct PublicKeyCredentialRpEntity;
#endif
#if ENABLE(WEB_AUTHN)
struct PublicKeyCredentialUserEntity;
#endif
#if ENABLE(WEB_AUTHN)
struct PublicKeyCredentialDescriptor;
#endif
struct PublicKeyCredentialCreationOptions;
struct PublicKeyCredentialRequestOptions;
class RegistrableDomain;
class Site;
struct AudioConfiguration;
struct Cookie;
#if ENABLE(VIDEO)
struct VideoFrameMetadata;
#endif
struct NavigationPreloadState;
class PlatformDynamicRangeLimit;
#if ENABLE(CONTENT_FILTERING)
class MockContentFilterSettings;
#endif
class LoginStatus;
struct ExceptionDetails;
template<typename> class RectEdges;
template<typename> class RectEdges;
template<typename> class RectEdges;
class Path;
#if ENABLE(META_VIEWPORT)
struct ViewportArguments;
#endif
class HTTPHeaderMap;
struct ElementContext;
struct ElementAnimationContext;
struct SystemPreviewInfo;
#if USE(SOUP)
struct ResourceRequestPlatformData;
#endif
#if PLATFORM(COCOA)
class ResourceRequest;
#endif
#if USE(CURL)
class ResourceRequest;
#endif
#if !USE(CURL) && !PLATFORM(COCOA)
class ResourceRequest;
#endif
class ResourceError;
#if (!(USE(CG))) && (!(USE(SKIA)))
class PlatformColorSpace;
#endif
class DestinationColorSpace;
struct WindowFeatures;
struct CompositionUnderline;
#if PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
struct GraphicsContextGLExternalImageSourceIOSurfaceHandle;
#endif
#if PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
struct GraphicsContextGLExternalImageSourceMTLSharedTextureHandle;
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
struct SerializedAttachmentData;
#endif
struct FileChooserSettings;
struct GrammarDetail;
struct TextCheckingResult;
class TextCheckingRequestData;
class LayoutRect;
struct ScreenDataOverrides;
class BlobPart;
struct OutOfLineColorDataForIPC;
struct ColorDataForIPC;
class Color;
struct MediaCapabilitiesInfo;
#if ENABLE(MEDIA_STREAM)
struct MediaStreamRequest;
#endif
#if ENABLE(MEDIA_STREAM)
class MediaTrackConstraintSetMap;
#endif
#if ! ENABLE(MEDIA_STREAM)
struct MediaStreamRequest;
#endif
struct MediaCapabilitiesDecodingInfo;
struct MediaCapabilitiesEncodingInfo;
struct FormDataElement;
struct NetworkTransactionInformation;
class ContentType;
struct DateTimeChooserParameters;
struct ScreenData;
struct ScreenProperties;
class PlatformTimeRanges;
#if ENABLE(VIDEO)
struct VideoPlaybackQualityMetrics;
#endif
#if PLATFORM(IOS_FAMILY)
class SelectionGeometry;
#endif
struct DataListSuggestion;
struct DataListSuggestionInformation;
struct ClientOrigin;
struct ImageBufferFormat;
struct PixelBufferFormat;
class TextIndicator;
class CertificateInfo;
class PasteboardCustomData;
class SharedMemoryHandle;
class DatabaseDetails;
struct TextIndicatorData;
#if ENABLE(MEDIA_STREAM)
struct MediaConstraints;
#endif
struct PromisedAttachmentInfo;
struct RecentSearch;
struct EventTrackingRegions;
struct TextManipulationItem;
struct TextManipulationToken;
struct TextManipulationTokenInfo;
struct VelocityData;
struct MimeClassInfo;
class AuthenticationChallenge;
#if ENABLE(DRAG_SUPPORT)
class DragData;
#endif
struct DictationAlternative;
class UserStyleSheet;
struct ScrollableAreaParameters;
struct RequestedKeyboardScrollData;
struct ScrollUpdate;
class AbsolutePositionConstraints;
struct KeyboardScroll;
class NotificationResources;
class IdentityTransformOperation;
class TranslateTransformOperation;
class RotateTransformOperation;
class ScaleTransformOperation;
class SkewTransformOperation;
class PerspectiveTransformOperation;
class MatrixTransformOperation;
class Matrix3DTransformOperation;
#if PLATFORM(COCOA)
class CAAudioStreamDescription;
#endif
class TransformOperations;
class Gradient;
struct PatternParameters;
class ThreadSafeDataBufferImpl;
class ThreadSafeDataBuffer;
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
struct GraphicsContextGLAttributes;
#endif
class TimingFunction;
class TransformOperation;
struct LengthPoint;
struct LengthSize;
class SVGPathByteStream;
class PixelBuffer;
struct MotionPathData;
struct TransformOperationData;
class ReferencePathOperation;
class ShapePathOperation;
class BoxPathOperation;
class RayPathOperation;
class PathOperation;
#if ENABLE(ENCRYPTED_MEDIA)
struct CDMKeySystemConfiguration;
#endif
struct MediaConfiguration;
struct MediaEncodingConfiguration;
struct MediaDecodingConfiguration;
class ResourceResponseBase;
class ResourceResponse;
struct ResourceResponseData;
#if PLATFORM(COCOA)
class ArchiveResource;
#endif
#if PLATFORM(COCOA)
class LegacyWebArchive;
#endif
struct FetchOptions;
struct ControlStyle;
class ControlPart;
class ButtonPart;
class InnerSpinButtonPart;
class MenuListButtonPart;
class MenuListPart;
class SearchFieldPart;
class SliderThumbPart;
class SearchFieldResultsPart;
class SearchFieldCancelButtonPart;
class TextAreaPart;
class TextFieldPart;
class ToggleButtonPart;
#if ENABLE(SERVICE_CONTROLS)
class ImageControlsButtonPart;
#endif
class ColorWellPart;
#if ENABLE(APPLE_PAY)
class ApplePayButtonPart;
#endif
class MeterPart;
class ProgressBarPart;
class SliderTrackPart;
class SwitchThumbPart;
class SwitchTrackPart;
class DistantLightSource;
class PointLightSource;
class SpotLightSource;
class FEBlend;
class FEColorMatrix;
struct ComponentTransferFunction;
class FEComponentTransfer;
class FEComposite;
class FEConvolveMatrix;
class FEDiffuseLighting;
class FEDisplacementMap;
class FEDropShadow;
class FEFlood;
class FEGaussianBlur;
class FEImage;
class FEMerge;
class FEMorphology;
class FEOffset;
class FETile;
class FESpecularLighting;
class FETurbulence;
class SourceAlpha;
class SourceGraphic;
class FilterEffectGeometry;
struct SVGFilterExpressionTerm;
class SVGPreserveAspectRatioValue;
#if ENABLE(GAMEPAD)
struct GamepadEffectParameters;
#endif
struct StorageEstimate;
struct TextList;
struct FontAttributes;
struct CrossOriginEmbedderPolicy;
struct SameSiteInfo;
class SecurityOrigin;
struct CookieRequestHeaderFieldProxy;
class FormData;
struct RequestedScrollData;
#if ENABLE(ENCRYPTED_MEDIA)
struct CDMMediaCapability;
#endif
#if ENABLE(ENCRYPTED_MEDIA)
struct CDMRestrictions;
#endif
struct MediaSelectionOption;
class BufferSource;
struct FontShadow;
struct CompositionHighlight;
class FontChanges;
class FontAttributeChanges;
struct TextManipulationControllerExclusionRule;
struct TextManipulationControllerManipulationFailure;
struct TextManipulationControllerManipulationResult;
struct BackgroundFetchInformation;
struct BackgroundFetchRequest;
struct BackgroundFetchRecordInformation;
struct BackgroundFetchOptions;
struct ImageResource;
struct FourCC;
#if ENABLE(VIDEO)
struct MediaEngineSupportParameters;
#endif
#if ENABLE(VIDEO)
struct SeekTarget;
#endif
#if ENABLE(VIDEO)
struct MediaPlayerLoadOptions;
#endif
class GeolocationPositionData;
#if ENABLE(APP_HIGHLIGHTS)
struct AppHighlight;
#endif
struct MediaDeviceHashSalts;
class SpeechRecognitionUpdate;
#if USE(SYSTEM_PREVIEW)
class ARKitBadgeSystemImage;
#endif
struct AudioIOPosition;
#if ENABLE(VIDEO) && USE(AVFOUNDATION)
class VideoFrameCV;
#endif
struct GradientColorStop;
class GradientColorStops;
struct ImageBufferParameters;
class ProcessIdentity;
struct ColorInterpolationMethod;
struct CompositeMode;
struct DocumentMarkerLineStyle;
struct GraphicsDropShadow;
struct GraphicsGaussianBlur;
struct GraphicsColorMatrix;
struct PlatformMediaSessionRemoteCommandArgument;
class SocketStreamError;
#if ENABLE(VIDEO)
struct GenericCueData;
#endif
struct ImageDecoderFrameInfo;
struct ImageOrientation;
struct Headroom;
struct ImagePaintingOptions;
struct FloatSegment;
struct CanvasActivityRecord;
struct CrossOriginOpenerPolicy;
struct CustomHeaderFields;
class HTTPHeaderField;
struct NavigationRequester;
struct PolicyContainer;
class SubstituteData;
struct ServiceWorkerClientData;
struct ServiceWorkerClientPendingMessage;
struct ServiceWorkerClientQueryOptions;
struct ServiceWorkerData;
struct ServiceWorkerJobData;
struct RouterSourceDict;
struct ServiceWorkerRoutePattern;
struct ServiceWorkerRouteCondition;
struct ServiceWorkerRoute;
struct EventInit;
struct MessageWithMessagePorts;
struct RequestStorageAccessResult;
class Exception;
struct ExceptionData;
struct MessagePortIdentifier;
struct SecurityPolicyViolationEventInit;
class CSPViolationReportBody;
class SecurityOriginData;
#if ENABLE(MEDIA_STREAM)
class MediaConstraint;
#endif
#if ENABLE(MEDIA_STREAM)
class IntConstraint;
#endif
#if ENABLE(MEDIA_STREAM)
class DoubleConstraint;
#endif
#if ENABLE(MEDIA_STREAM)
class BooleanConstraint;
#endif
#if ENABLE(MEDIA_STREAM)
class StringConstraint;
#endif
#if ENABLE(MEDIA_STREAM)
struct FrameRateRange;
#endif
#if ENABLE(MEDIA_STREAM)
struct VideoPresetData;
#endif
#if ENABLE(MEDIA_STREAM)
class RealtimeMediaSourceSupportedConstraints;
#endif
#if ENABLE(MEDIA_STREAM)
class RealtimeMediaSourceSettings;
#endif
#if ENABLE(MEDIA_STREAM)
class CaptureDevice;
#endif
#if ENABLE(MEDIA_STREAM)
struct CaptureDeviceWithCapabilities;
#endif
#if ENABLE(MEDIA_STREAM)
class DoubleCapabilityRange;
#endif
#if ENABLE(MEDIA_STREAM)
class LongCapabilityRange;
#endif
#if ENABLE(MEDIA_STREAM)
class RealtimeMediaSourceCapabilities;
#endif
struct PlatformVideoColorSpace;
#if ENABLE(VIDEO)
struct SpatialVideoMetadata;
#endif
#if ENABLE(VIDEO)
struct VideoProjectionMetadata;
#endif
#if ENABLE(VIDEO)
struct PlatformTrackConfiguration;
#endif
#if ENABLE(VIDEO)
struct PlatformAudioTrackConfiguration;
#endif
#if ENABLE(VIDEO)
struct PlatformVideoTrackConfiguration;
#endif
#if ENABLE(WEB_RTC)
struct RTCDataChannelInit;
#endif
#if ENABLE(CONTENT_EXTENSIONS)
struct ContentRuleListResults;
#endif
class COEPInheritenceViolationReportBody;
class CORPViolationReportBody;
class ReportBody;
class SourceImage;
struct LinkIcon;
struct SupportedPluginIdentifier;
struct CSSValueKey;
struct VideoFrameTimeMetadata;
class EventRegion;
struct PresentationSize;
struct PasteboardItemInfo;
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
struct MediaControlsContextMenuItem;
#endif
struct WorkerOptions;
struct WorkerInitializationData;
struct WorkerFetchResult;
struct SharedWorkerKey;
struct ServiceWorkerRegistrationOptions;
class ServiceWorkerRegistrationKey;
struct ServiceWorkerRegistrationData;
struct ServiceWorkerJobDataIdentifier;
struct ServiceWorkerImportedScript;
#if ENABLE(SHAREABLE_RESOURCE) && PLATFORM(COCOA)
class ScriptBuffer;
#endif
#if !ENABLE(SHAREABLE_RESOURCE) || !PLATFORM(COCOA)
class ScriptBuffer;
#endif
struct ServiceWorkerContextData;
struct GlobalFrameIdentifier;
struct GlobalWindowIdentifier;
struct InteractionRegion;
class Region;
class ISOWebVTTCue;
#if ENABLE(WEB_AUTHN)
struct MockWebAuthenticationConfiguration;
#endif
#if (ENABLE(WEB_AUTHN)) && (HAVE(DIGITAL_CREDENTIALS_UI))
struct OpenID4VPRequest;
#endif
#if (ENABLE(WEB_AUTHN)) && (HAVE(DIGITAL_CREDENTIALS_UI))
struct MobileDocumentRequest;
#endif
#if (ENABLE(WEB_AUTHN)) && (HAVE(DIGITAL_CREDENTIALS_UI))
struct DigitalCredentialsRequestData;
#endif
#if (ENABLE(WEB_AUTHN)) && (HAVE(DIGITAL_CREDENTIALS_UI))
struct DigitalCredentialsResponseData;
#endif
#if ENABLE(MEDIA_STREAM)
struct MockMicrophoneProperties;
#endif
#if ENABLE(MEDIA_STREAM)
struct MockSpeakerProperties;
#endif
#if ENABLE(MEDIA_STREAM)
struct MockCameraProperties;
#endif
#if ENABLE(MEDIA_STREAM)
struct MockDisplayProperties;
#endif
#if ENABLE(MEDIA_STREAM)
struct MockMediaDevice;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
struct AcceleratedEffectValues;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
class WebAnimationTime;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
struct AnimationEffectTiming;
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
class AcceleratedEffect;
#endif
class ProtectionSpace;
#if PLATFORM(COCOA)
class Credential;
#endif
#if USE(SOUP)
class Credential;
#endif
#if USE(CURL)
class Credential;
#endif
#if ENABLE(MEDIA_STREAM)
struct CaptureSourceError;
#endif
#if ENABLE(MEDIA_STREAM)
struct MediaSettingsRange;
#endif
#if ENABLE(MEDIA_STREAM)
struct PhotoCapabilities;
#endif
#if ENABLE(MEDIA_STREAM)
struct PhotoSettings;
#endif
struct CookieStoreGetOptions;
struct CookieChangeSubscription;
class Model;
class ModelPlayerAnimationState;
#if ENABLE(MODEL_PROCESS)
class ModelContext;
#endif
#if PLATFORM(IOS_FAMILY)
class InspectorOverlayLabel;
#endif
#if PLATFORM(IOS_FAMILY)
struct InspectorOverlayHighlight;
#endif
struct DiagnosticLoggingDictionary;
class FixedPositionViewportConstraints;
class StickyPositionViewportConstraints;
class FloatLine;
struct FontCachePrewarmInformation;
struct PrewarmInformation;
class FontSelectionValue;
struct FontSelectionRange;
struct FontSelectionSpecifiedCapabilities;
struct RemoteUserInputEventData;
struct LinkDecorationFilteringData;
struct InspectorFrontendClientSaveData;
#if ENABLE(VIDEO)
struct PlatformTextTrackData;
#endif
struct NotificationPayload;
struct NotificationOptionsPayload;
class NetworkLoadMetrics;
struct AdditionalNetworkLoadMetricsForWebInspector;
struct DisplayUpdate;
struct MediaUsageInfo;
struct NowPlayingInfoArtwork;
struct NowPlayingMetadata;
struct NowPlayingInfo;
struct VideoConfiguration;
class UserScript;
class ContentSecurityPolicyResponseHeaders;
class DragImage;
struct DragItem;
#if PLATFORM(COCOA)
struct KeypressCommand;
#endif
#if !USE(COORDINATED_GRAPHICS)
class FilterOperations;
#endif
class Filter;
class CSSFilter;
class SVGFilter;
class ByteArrayPixelBuffer;
class PixelBufferSourceView;
struct MarkupExclusionRule;
class SystemImage;
#if ENABLE(WEB_CODECS)
class WebCodecsEncodedVideoChunkStorage;
#endif
#if ENABLE(WEB_CODECS)
class WebCodecsEncodedAudioChunkStorage;
#endif
class SerializedScriptValue;
class SharedBuffer;
#if !USE(COORDINATED_GRAPHICS)
class FilterOperation;
#endif
#if !USE(COORDINATED_GRAPHICS)
class BasicColorMatrixFilterOperation;
#endif
#if !USE(COORDINATED_GRAPHICS)
class BasicComponentTransferFilterOperation;
#endif
#if !USE(COORDINATED_GRAPHICS)
class BlurFilterOperation;
#endif
#if !USE(COORDINATED_GRAPHICS)
class DropShadowFilterOperation;
#endif
#if !USE(COORDINATED_GRAPHICS)
class DefaultFilterOperation;
#endif
#if !USE(COORDINATED_GRAPHICS)
class PassthroughFilterOperation;
#endif
class FilterEffect;
#if HAVE(CORE_MATERIAL)
struct AppleVisualEffectData;
#endif
#if ENABLE(MEDIA_SOURCE)
struct SourceBufferEvictionData;
#endif
#if ENABLE(MEDIA_SOURCE)
struct MediaSourceConfiguration;
#endif
struct FontInternalAttributes;
class Cursor;
class LightSource;
class Image;
struct Length;
class FilterFunction;
struct OrganizationStorageAccessPromptQuirk;
#if ENABLE(SHAREABLE_RESOURCE)
class ShareableResourceHandle;
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
class DynamicContentScalingDisplayList;
#endif
#if PLATFORM(COCOA)
struct TextAttachmentMissingImage;
#endif
#if PLATFORM(COCOA)
struct TextAttachmentFileWrapper;
#endif
#if (PLATFORM(COCOA)) && (ENABLE(MULTI_REPRESENTATION_HEIC))
struct MultiRepresentationHEICAttachmentSingleImage;
#endif
#if (PLATFORM(COCOA)) && (ENABLE(MULTI_REPRESENTATION_HEIC))
struct MultiRepresentationHEICAttachmentData;
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(DATA_DETECTION)
struct TextRecognitionDataDetector;
#endif
class ShareableBitmapConfiguration;
class ShareableBitmapHandle;
class ShareableBitmap;
#if ENABLE(DATA_DETECTION)
struct DataDetectorElementInfo;
#endif
#if ENABLE(VIDEO)
class SerializedPlatformDataCueValue;
#endif
class FragmentedSharedBuffer;
class PublicSuffix;
struct WrappedCryptoKey;
class Allowlist;
struct OwnerPermissionsPolicyData;
class PermissionsPolicy;
struct ImageBufferResourceLimits;
struct RsaOtherPrimesInfo;
struct JsonWebKey;
struct CryptoKeyData;
struct FixedContainerEdges;
struct MessageForTesting;
struct HostingContext;
struct FocusEventData;
struct AXDebugInfo;
class Font;
class FontPlatformData;
struct FontPlatformDataAttributes;
struct FontCustomPlatformSerializedData;
#if USE(CURL)
class CurlProxySettings;
#endif
#if USE(SKIA)
struct FontPlatformSerializedCreationData;
#endif
#if USE(SKIA)
struct FontPlatformSerializedData;
#endif
class DocumentSyncData;
class FrameTreeSyncData;
struct ProcessSyncData;
enum class AXIDType;
struct BackgroundFetchRecordIdentifierType;
struct NodeIdentifierType;
struct FetchIdentifierType;
struct ImageDecoderIdentifierType;
enum class ImageOverlayDataDetectionResultIdentifierType;
enum class InbandGenericCueIdentifierType;
struct LayerHostingContextIdentifierType;
enum class MediaSessionGroupIdentifierType;
enum class MediaUniqueIdentifierType;
struct RealtimeMediaSourceIdentifierType;
enum class SWServerToContextConnectionIdentifierType;
struct SharedWorkerIdentifierType;
struct SpeechRecognitionConnectionClientIdentifierType;
enum class TextCheckingRequestIdentifierType;
enum class TextManipulationItemIdentifierType;
enum class TextManipulationTokenIdentifierType;
struct WindowIdentifierType;
enum class WorkletGlobalScopeIdentifierType;
struct AttributedStringTextListIDType;
struct AttributedStringTextTableBlockIDType;
struct AttributedStringTextTableIDType;
struct BackForwardFrameItemIdentifierType;
struct BackForwardItemIdentifierType;
struct DictationContextType;
struct FrameIdentifierType;
struct MediaKeySystemRequestIdentifierType;
struct MediaPlayerIdentifierType;
struct MediaPlayerClientIdentifierType;
struct MediaSessionIdentifierType;
struct ModelPlayerIdentifierType;
struct NavigationIdentifierType;
struct PageIdentifierType;
struct PlatformLayerIdentifierType;
struct PlaybackTargetClientContextIdentifierType;
struct PushSubscriptionIdentifierType;
struct ProcessIdentifierType;
struct ScrollingNodeIDType;
struct SharedWorkerObjectIdentifierType;
struct SleepDisablerIdentifierType;
struct UserGestureTokenIdentifierType;
struct UserMediaRequestIdentifierType;
struct WebTransportStreamIdentifierType;
class ResourceLoader;
class WebSocketChannel;
enum class DOMCacheIdentifierType;
enum class BroadcastChannelIdentifierType;
struct FileSystemWritableFileStreamIdentifierType;
struct IDBDatabaseConnectionIdentifierType;
struct IDBIndexIdentifierType;
struct IDBObjectStoreIdentifierType;
enum class IDBResourceObjectIdentifierType;
struct LibWebRTCSocketIdentifierType;
enum class MainThreadPermissionObserverIdentifierType;
enum class OpaqueOriginIdentifierType;
enum class PortIdentifierType;
enum class RTCDataChannelLocalIdentifierType;
enum class RTCRtpScriptTransformerIdentifierType;
struct RenderingResourceIdentifierType;
struct ResourceLoaderIdentifierType;
struct ServiceWorkerIdentifierType;
struct ServiceWorkerJobIdentifierType;
struct ServiceWorkerRegistrationIdentifierType;
struct SnapshotIdentifierType;
enum class WebLockIdentifierType;
enum class WorkerFileSystemStorageConnectionCallbackIdentifierType;
struct FileSystemHandleIdentifierType;
struct FileSystemSyncAccessHandleIdentifierType;
struct WebSocketIdentifierType;
}

namespace WebCore::DOMCacheEngine {
enum class Error : uint8_t;
struct CacheInfo;
struct CacheInfos;
struct CacheIdentifierOperationResult;
struct CrossThreadRecord;
struct Record;
}

namespace WebCore::DisplayList {
class DrawDotsForDocumentMarker;
}

namespace WebCore::IndexedDB {
enum class KeyType : int8_t;
enum class CursorDirection : uint8_t;
enum class ObjectStoreOverwriteMode : uint8_t;
enum class RequestType : uint8_t;
enum class GetAllType : bool;
enum class IndexRecordType : bool;
enum class ConnectionClosedOnBehalfOfServer : bool;
enum class CursorIterateOption : bool;
enum class CursorSource : bool;
enum class CursorType : bool;
}

namespace WebCore::PCM {
enum class AttributionEphemeral : bool;
enum class WasSent : bool;
struct SourceSite;
struct AttributionDestinationSite;
struct EphemeralNonce;
struct AttributionTriggerData;
struct AttributionTimeToSendData;
struct AttributionSecondsUntilSendData;
}

namespace WebCore::PackedColor {
struct RGBA;
}

namespace WebCore::ShapeDetection {
#if ENABLE(GPU_PROCESS)
enum class BarcodeFormat : uint8_t;
#endif
#if ENABLE(GPU_PROCESS)
enum class LandmarkType : uint8_t;
#endif
#if ENABLE(GPU_PROCESS)
struct BarcodeDetectorOptions;
#endif
#if ENABLE(GPU_PROCESS)
struct DetectedBarcode;
#endif
#if ENABLE(GPU_PROCESS)
struct DetectedFace;
#endif
#if ENABLE(GPU_PROCESS)
struct DetectedText;
#endif
#if ENABLE(GPU_PROCESS)
struct FaceDetectorOptions;
#endif
#if ENABLE(GPU_PROCESS)
struct Landmark;
#endif
}

namespace WebCore::Style {
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
struct OffsetRotate;
#endif
}

namespace WebCore::TextExtraction {
enum class ContainerType : uint8_t;
struct Editable;
struct TextItemData;
struct ScrollableItemData;
struct ImageItemData;
struct Item;
}

namespace WebCore::WebGPU {
enum class TextureFormat : uint8_t;
enum class TextureAspect : uint8_t;
enum class PowerPreference : bool;
enum class PredefinedColorSpace : uint8_t;
#if ENABLE(GPU_PROCESS)
enum class FeatureName : uint8_t;
#endif
enum class ErrorFilter : uint8_t;
enum class IndexFormat : uint8_t;
enum class MapMode : uint8_t;
enum class MapMode : uint8_t;
enum class BlendFactor : uint8_t;
enum class TextureSampleType : uint8_t;
enum class BlendOperation : uint8_t;
enum class CanvasToneMappingMode : uint8_t;
enum class CanvasAlphaMode : uint8_t;
enum class QueryType : uint8_t;
enum class CompareFunction : uint8_t;
enum class FilterMode : uint8_t;
enum class MipmapFilterMode : uint8_t;
enum class TextureDimension : uint8_t;
enum class VertexFormat : uint8_t;
enum class ShaderStage : uint8_t;
enum class ShaderStage : uint8_t;
enum class CompilationMessageType : uint8_t;
enum class StencilOperation : uint8_t;
enum class DeviceLostReason : uint8_t;
enum class AddressMode : uint8_t;
enum class BufferBindingType : uint8_t;
enum class StorageTextureAccess : uint8_t;
enum class FrontFace : uint8_t;
enum class StoreOp : uint8_t;
enum class LoadOp : uint8_t;
enum class ColorWrite : uint8_t;
enum class SamplerBindingType : uint8_t;
enum class PrimitiveTopology : uint8_t;
enum class CullMode : uint8_t;
enum class TextureViewDimension : uint8_t;
enum class VertexStepMode : uint8_t;
enum class XREye : uint8_t;
enum class BufferUsage : uint16_t;
enum class TextureUsage : uint8_t;
enum class TextureUsage : uint8_t;
}

namespace WebCore::WritingTools {
#if ENABLE(WRITING_TOOLS)
enum class Behavior : uint8_t;
#endif
#if ENABLE(WRITING_TOOLS)
enum class Action : uint8_t;
#endif
#if ENABLE(WRITING_TOOLS)
enum class SessionType : uint8_t;
#endif
#if ENABLE(WRITING_TOOLS)
enum class SessionCompositionType : uint8_t;
#endif
#if ENABLE(WRITING_TOOLS)
enum class TextSuggestionState : uint8_t;
#endif
#if ENABLE(WRITING_TOOLS)
struct Session;
#endif
#if ENABLE(WRITING_TOOLS)
struct Context;
#endif
#if ENABLE(WRITING_TOOLS)
struct TextSuggestion;
#endif
}

namespace WebKit {
enum class LoadedWebArchive : bool;
enum class DidFilterKnownLinkDecoration : bool;
enum class ShouldGrandfatherStatistics : bool;
enum class PrivateRelayed : bool;
enum class ContentAsStringIncludesChildFrames : bool;
enum class CallDownloadDidStart : bool;
enum class AllowOverwrite : bool;
enum class UseDownloadPlaceholder : bool;
enum class PreconnectOnly : bool;
enum class NavigatingToAppBoundDomain : bool;
enum class AllowsCellularAccess : bool;
#if USE(SOUP)
enum class SoupCookiePersistentStorageType : bool;
#endif
enum class StorageAccessStatus : uint8_t;
enum class PrivateClickMeasurementAttributionType : bool;
enum class FileSystemStorageError : uint8_t;
#if HAVE(PER_APP_ACCESSIBILITY_PREFERENCES)
enum class WebKitAXValueState : int;
#endif
enum class BackgroundFetchChange : uint8_t;
enum class CacheModel : uint8_t;
enum class ContentWorldOption : uint8_t;
enum class CoordinateSystem : uint8_t;
enum class DragControllerAction : uint8_t;
#if ENABLE(TILED_CA_DRAWING_AREA)
enum class DrawingAreaType : bool;
#endif
enum class EditingRangeIsRelativeTo : uint8_t;
enum class ListType : uint8_t;
enum class TextAlignment : uint8_t;
enum class TypingAttribute : uint8_t;
enum class InputType : uint8_t;
enum class ColorControlSupportsAlpha : bool;
enum class FrameType : bool;
enum class SnapshotOption : uint16_t;
enum class MediaPlaybackState : uint8_t;
enum class SafeBrowsingCheckOngoing : bool;
enum class RemoteWorkerType : uint8_t;
enum class SameDocumentNavigationType : uint8_t;
enum class SyntheticEditingCommandType : uint8_t ;
enum class TextCheckerState : uint8_t;
#if ENABLE(IMAGE_ANALYSIS)
enum class TextRecognitionUpdateResult : uint8_t;
#endif
enum class UndoOrRedo : bool;
#if ENABLE(UI_SIDE_COMPOSITING)
enum class ViewStabilityFlag : uint8_t;
#endif
enum class WebEventModifier : uint8_t;
enum class WebEventType : uint8_t;
enum class WebMouseEventButton : int8_t;
enum class WebMouseEventSyntheticClickType : uint8_t;
enum class GestureWasCancelled : bool;
enum class FindOptions : uint16_t;
enum class FindDecorationStyle : uint8_t;
enum class IsScrollable : uint8_t;
enum class WebsiteMetaViewportPolicy : uint8_t;
enum class WebsiteMediaSourcePolicy : uint8_t;
enum class WebsiteSimulatedMouseEventsDispatchPolicy : uint8_t;
enum class WebsiteLegacyOverflowScrollingTouchPolicy : uint8_t;
enum class WebContentMode : uint8_t;
enum class WebsiteInlineMediaPlaybackPolicy : uint8_t;
enum class AuthenticationChallengeDisposition : uint8_t;
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
enum class WebExtensionActionClickBehavior : uint8_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionContentWorldType : uint8_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionContextInstallReason : uint8_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionEventListenerType : uint8_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionMenuItemType : uint8_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionMenuItemContextType : uint16_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionStorageAccessLevel : uint8_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionDataType : uint8_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionTabImageFormat : uint8_t;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class ReloadFromOrigin : bool;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionWindowTypeFilter : uint8_t;
#endif
enum class WebsiteDataFetchOption : uint8_t;
enum class WebsiteDataType : uint32_t;
#if ENABLE(WK_WEB_EXTENSIONS)
enum class WebExtensionWindowTypeFilter : uint8_t;
#endif
#if ENABLE(GPU_PROCESS)
enum class BufferInSetType : uint8_t;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(IOS_FAMILY)
enum class RespectSelectionAnchor : bool;
#endif
enum class InjectUserScriptImmediately : bool;
#if USE(GRAPHICS_LAYER_WC)
enum class WCLayerChange : uint32_t;
#endif
#if ENABLE(GPU_PROCESS)
struct GPUProcessCreationParameters;
#endif
#if ENABLE(GPU_PROCESS)
struct GPUProcessPreferences;
#endif
#if ENABLE(GPU_PROCESS)
struct GPUProcessSessionParameters;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
struct RemoteGraphicsContextGLInitializationState;
#endif
#if ENABLE(GPU_PROCESS)
struct RemoteGPURequestAdapterResponse;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct AudioTrackPrivateRemoteConfiguration;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
struct InitializationSegmentInfo;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
struct MediaDescriptionInfo;
#endif
#if ENABLE(GPU_PROCESS)
struct RemoteMediaPlayerProxyConfiguration;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct RemoteAudioInfo;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct RemoteVideoInfo;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct TextTrackPrivateRemoteConfiguration;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct TrackPrivateRemoteConfiguration;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct VideoTrackPrivateRemoteConfiguration;
#endif
#if ENABLE(MODEL_PROCESS)
struct ModelProcessCreationParameters;
#endif
struct NetworkProcessCreationParameters;
struct NetworkResourceLoadParameters;
struct NetworkSessionCreationParameters;
struct ITPThirdPartyData;
struct ITPThirdPartyDataForSpecificFirstParty;
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
#endif
#if ENABLE(GPU_PROCESS)
#endif
#if ENABLE(GPU_PROCESS)
#endif
#if ENABLE(GPU_PROCESS)
#endif
struct AccessibilityPreferences;
struct AuxiliaryProcessCreationParameters;
struct BackgroundFetchState;
class CallbackID;
struct ContentWorldData;
#if ENABLE(CONTEXT_MENUS)
class ContextMenuContextData;
#endif
struct DebuggableInfoData;
#if PLATFORM(IOS_FAMILY)
struct DocumentEditingContextRequest;
#endif
#if PLATFORM(IOS_FAMILY)
struct DocumentEditingContext;
#endif
struct EditingRange;
struct EditorState;
struct FileSystemSyncAccessHandleInfo;
#if PLATFORM(IOS_FAMILY)
struct OptionItem;
#endif
#if PLATFORM(IOS_FAMILY)
struct FocusedElementInformation;
#endif
struct FrameInfoData;
struct FrameTreeCreationParameters;
struct FrameTreeNodeData;
struct FullScreenMediaDetails;
#if ENABLE(GPU_PROCESS)
struct GPUProcessConnectionParameters;
#endif
struct GoToBackForwardItemParameters;
struct NodeInfo;
class JavaScriptEvaluationResult;
class LayerTreeContext;
struct LoadParameters;
#if ENABLE(ARKIT_INLINE_PREVIEW)
struct ModelIdentifier;
#endif
#if ENABLE(MODEL_PROCESS)
struct ModelProcessConnectionParameters;
#endif
struct NavigationActionData;
struct NetworkProcessConnectionParameters;
struct PlatformFontInfo;
struct PlatformPopupMenuData;
struct PolicyDecision;
struct PolicyDecisionConsoleMessage;
struct PrintInfo;
struct ProvisionalFrameCreationParameters;
#if USE(LIBWEBRTC)
struct RTCNetwork;
#endif
#if USE(LIBWEBRTC)
struct RTCPacketOptions;
#endif
#if ENABLE(TOUCH_EVENTS)
struct RemoteWebTouchEvent;
#endif
struct RemoteWorkerInitializationData;
struct ResourceLoadInfo;
struct ResourceLoadStatisticsParameters;
class SandboxExtensionHandle;
struct ScriptTrackingPrivacyHost;
struct ScriptTrackingPrivacyRules;
#if ENABLE(MOMENTUM_EVENT_DISPATCHER)
class ScrollingAccelerationCurve;
#endif
struct HTTPBody;
class FrameState;
struct BackForwardListState;
struct URLSchemeTaskParameters;
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
struct UpdateInfo;
#endif
struct UserContentControllerParameters;
class UserData;
#if ENABLE(UI_SIDE_COMPOSITING)
class VisibleContentRectUpdateInfo;
#endif
struct WebBackForwardListCounts;
#if ENABLE(CONTEXT_MENUS)
class WebContextMenuItemData;
#endif
struct RunJavaScriptParameters;
#if ENABLE(CONTENT_EXTENSIONS)
class WebCompiledContentRuleListData;
#endif
class WebEvent;
class WebKeyboardEvent;
#if ENABLE(TOUCH_EVENTS)
class WebTouchEvent;
#endif
#if ENABLE(TOUCH_EVENTS)
class WebPlatformTouchPoint;
#endif
class WebMouseEvent;
#if ENABLE(MAC_GESTURE_EVENTS)
class WebGestureEvent;
#endif
class WebWheelEvent;
struct WebFoundTextRange;
struct WebFrameMetrics;
struct WebHitTestResultData;
class WebImage;
struct WebNavigationDataStore;
struct WebPageCreationParameters;
struct WebPageGroupData;
class WebPageNetworkParameters;
struct WebPopupItem;
struct WebPreferencesStore;
struct WebProcessCreationParameters;
struct WebProcessDataStoreParameters;
struct WebPushMessage;
struct WebUserScriptData;
struct WebUserStyleSheetData;
struct WebScriptMessageHandlerData;
struct WebsiteDataStoreParameters;
struct WebsitePoliciesData;
class WebIDBResult;
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionAlarmParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
struct WebExtensionBookmarksParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionCommandParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionContextParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionControllerParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionCookieParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionCookieFilterParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionScriptInjectionParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionScriptInjectionResultParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionRegisteredScriptParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionFrameParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionMatchedRuleParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionMenuItemParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionMenuItemContextParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionMessageSenderParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionMessageTargetParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
struct WebExtensionSidebarParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionTabParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionTabQueryParameters;
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
struct WebExtensionWindowParameters;
#endif
#if ENABLE(GAMEPAD)
class GamepadData;
#endif
#if ENABLE(GPU_PROCESS)
struct RemoteImageBufferSetConfiguration;
#endif
struct WebsiteData;
#if ENABLE(WEBXR)
struct XRDeviceInfo;
#endif
#if (ENABLE(WEBXR)) && (USE(OPENXR))
struct XRDeviceLayer;
#endif
#if ENABLE(GPU_PROCESS)
struct GPUProcessConnectionInfo;
#endif
#if ENABLE(GPU_PROCESS)
struct BufferIdentifierSet;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(COCOA)
struct ImageBufferSetPrepareBufferForDisplayInputData;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(COCOA)
struct ImageBufferSetPrepareBufferForDisplayOutputData;
#endif
#if ENABLE(GPU_PROCESS)
struct MediaOverridesForTesting;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct MediaTimeUpdateData;
#endif
#if ENABLE(GPU_PROCESS) && USE(AUDIO_SESSION)
struct RemoteAudioSessionConfiguration;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
struct RemoteCDMConfiguration;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
struct RemoteCDMInstanceConfiguration;
#endif
#if ENABLE(GPU_PROCESS)
struct RemoteMediaPlayerConfiguration;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct RemoteMediaPlayerState;
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
struct RemoteVideoFrameProxyProperties;
#endif
#if ENABLE(GPU_PROCESS) && PLATFORM(COCOA) && ENABLE(VIDEO)
struct SharedVideoFrame;
#endif
#if ENABLE(MEDIA_STREAM)
class MediaDeviceSandboxExtensions;
#endif
#if ENABLE(MODEL_PROCESS)
struct ModelProcessConnectionInfo;
#endif
struct NetworkProcessConnectionInfo;
#if ENABLE(SPEECH_SYNTHESIS)
struct WebSpeechSynthesisVoice;
#endif
#if USE(GRAPHICS_LAYER_WC)
class WCBackingStore;
#endif
#if USE(GRAPHICS_LAYER_WC)
struct WCTileUpdate;
#endif
#if USE(GRAPHICS_LAYER_WC)
struct WCLayerUpdateInfo;
#endif
#if USE(GRAPHICS_LAYER_WC)
struct WCUpdateInfo;
#endif
struct SharedPreferencesForWebProcess;
class WebURLSchemeHandler;
struct AudioMediaStreamTrackRendererInternalUnitIdentifierType;
struct ContentWorldIdentifierType;
enum class ImageAnalysisRequestIdentifierType;
enum class MediaDevicePermissionRequestIdentifierType;
enum class RemoteAudioSessionIdentifierType;
struct RemoteCDMIdentifierType;
struct RemoteCDMInstanceIdentifierType;
struct RemoteCDMInstanceSessionIdentifierType;
struct RemoteLegacyCDMIdentifierType;
struct RemoteLegacyCDMSessionIdentifierType;
enum class RemoteMediaSourceIdentifierType;
enum class RemoteSourceBufferIdentifierType;
struct RetrieveRecordResponseBodyCallbackIdentifierType;
struct ShapeDetectionIdentifierType;
struct StorageAreaImplIdentifierType;
struct StorageAreaMapIdentifierType;
struct StorageNamespaceIdentifierType;
struct UserScriptIdentifierType;
struct UserStyleSheetIdentifierType;
enum class VisitedLinkTableIdentifierType;
enum class WCLayerTreeHostIdentifierType;
enum class WebExtensionControllerIdentifierType;
enum class XRDeviceIdentifierType;
struct AuthenticationChallengeIdentifierType;
struct DataTaskIdentifierType;
struct DisplayLinkObserverIDType;
struct DrawingAreaIdentifierType;
struct DownloadIDType;
struct GeolocationIdentifierType;
struct IPCConnectionTesterIdentifierType;
struct IPCStreamTesterIdentifierType;
struct JSObjectIDType;
struct MarkSurfacesAsVolatileRequestIdentifierType;
struct MessageBatchIdentifierType;
struct NetworkResourceLoadIdentifierType;
struct PDFPluginIdentifierType;
struct PageGroupIdentifierType;
struct RemoteAudioDestinationIdentifierType;
struct RemoteAudioHardwareListenerIdentifierType;
struct RemoteImageBufferSetIdentifierType;
struct RemoteMediaResourceIdentifierType;
struct RemoteRemoteCommandListenerIdentifierType;
struct SampleBufferDisplayLayerIdentifierType;
struct ScriptMessageHandlerIdentifierType;
struct TapIdentifierType;
struct TextCheckerRequestType;
struct TransactionIDType;
struct UserContentControllerIdentifierType;
struct WebExtensionContextIdentifierType;
struct WebExtensionFrameIdentifierType;
struct WebExtensionPortChannelIdentifierType;
struct WebExtensionTabIdentifierType;
struct WebExtensionWindowIdentifierType;
struct WebPageProxyIdentifierType;
struct WebTransportSessionIdentifierType;
struct WebURLSchemeHandlerIdentifierType;
struct GPUProcessConnectionIdentifierType;
enum class LegacyCustomProtocolIDType;
struct LibWebRTCResolverIdentifierType;
struct LogStreamIdentifierType;
struct RemoteDisplayListRecorderIdentifierType;
struct RemoteSerializedImageBufferIdentifierType;
struct RemoteVideoFrameIdentifierType;
struct VideoDecoderIdentifierType;
struct VideoEncoderIdentifierType;
enum class WCContentBufferIdentifierType;
struct GraphicsContextGLIdentifierType;
struct QuotaIncreaseRequestIdentifierType;
struct RenderingBackendIdentifierType;
struct StorageAreaIdentifierType;
struct WebGPUIdentifierType;
}

namespace WebKit::PCM {
enum class MessageType : uint8_t;
}

namespace WebKit::WebGPU {
#if ENABLE(GPU_PROCESS)
struct BindGroupDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct BindGroupEntry;
#endif
#if ENABLE(GPU_PROCESS)
struct BindGroupLayoutDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct BindGroupLayoutEntry;
#endif
#if ENABLE(GPU_PROCESS)
struct BlendComponent;
#endif
#if ENABLE(GPU_PROCESS)
struct BlendState;
#endif
#if ENABLE(GPU_PROCESS)
struct BufferBinding;
#endif
#if ENABLE(GPU_PROCESS)
struct BufferBindingLayout;
#endif
#if ENABLE(GPU_PROCESS)
struct BufferDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct CanvasConfiguration;
#endif
#if ENABLE(GPU_PROCESS)
struct ColorDict;
#endif
#if ENABLE(GPU_PROCESS)
struct ColorTargetState;
#endif
#if ENABLE(GPU_PROCESS)
struct CommandBufferDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct CommandEncoderDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct CompilationMessage;
#endif
#if ENABLE(GPU_PROCESS)
struct ComputePassDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct ComputePassTimestampWrites;
#endif
#if ENABLE(GPU_PROCESS)
struct ComputePipelineDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct DepthStencilState;
#endif
#if ENABLE(GPU_PROCESS)
struct DeviceDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct Extent3DDict;
#endif
#if ENABLE(GPU_PROCESS)
struct ExternalTextureBindingLayout;
#endif
#if ENABLE(GPU_PROCESS)
struct ExternalTextureDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct FragmentState;
#endif
#if ENABLE(GPU_PROCESS)
struct ImageCopyBuffer;
#endif
#if ENABLE(GPU_PROCESS)
struct ImageCopyExternalImage;
#endif
#if ENABLE(GPU_PROCESS)
struct ImageCopyTexture;
#endif
#if ENABLE(GPU_PROCESS)
struct ImageCopyTextureTagged;
#endif
#if ENABLE(GPU_PROCESS)
struct ImageDataLayout;
#endif
#if ENABLE(GPU_PROCESS)
struct InternalError;
#endif
#if ENABLE(GPU_PROCESS)
struct MultisampleState;
#endif
#if ENABLE(GPU_PROCESS)
struct ObjectDescriptorBase;
#endif
#if ENABLE(GPU_PROCESS)
struct Origin2DDict;
#endif
#if ENABLE(GPU_PROCESS)
struct Origin3DDict;
#endif
#if ENABLE(GPU_PROCESS)
struct OutOfMemoryError;
#endif
#if ENABLE(GPU_PROCESS)
struct PipelineDescriptorBase;
#endif
#if ENABLE(GPU_PROCESS)
struct PipelineLayoutDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct PresentationContextDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct PrimitiveState;
#endif
#if ENABLE(GPU_PROCESS)
struct ProgrammableStage;
#endif
#if ENABLE(GPU_PROCESS)
struct QuerySetDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct RenderBundleDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct RenderBundleEncoderDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct RenderPassColorAttachment;
#endif
#if ENABLE(GPU_PROCESS)
struct RenderPassDepthStencilAttachment;
#endif
#if ENABLE(GPU_PROCESS)
struct RenderPassDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct RenderPassLayout;
#endif
#if ENABLE(GPU_PROCESS)
struct RenderPassTimestampWrites;
#endif
#if ENABLE(GPU_PROCESS)
struct RenderPipelineDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct RequestAdapterOptions;
#endif
#if ENABLE(GPU_PROCESS)
struct SamplerBindingLayout;
#endif
#if ENABLE(GPU_PROCESS)
struct SamplerDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct ShaderModuleCompilationHint;
#endif
#if ENABLE(GPU_PROCESS)
struct ShaderModuleDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct StencilFaceState;
#endif
#if ENABLE(GPU_PROCESS)
struct StorageTextureBindingLayout;
#endif
#if ENABLE(GPU_PROCESS)
struct SupportedFeatures;
#endif
#if ENABLE(GPU_PROCESS)
struct SupportedLimits;
#endif
#if ENABLE(GPU_PROCESS)
struct TextureBindingLayout;
#endif
#if ENABLE(GPU_PROCESS)
struct TextureDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct TextureViewDescriptor;
#endif
#if ENABLE(GPU_PROCESS)
struct ValidationError;
#endif
#if ENABLE(GPU_PROCESS)
struct VertexAttribute;
#endif
#if ENABLE(GPU_PROCESS)
struct VertexBufferLayout;
#endif
#if ENABLE(GPU_PROCESS)
struct VertexState;
#endif
}

namespace WebKit::WebPushD {
struct WebPushDaemonConnectionConfiguration;
}

namespace WebKit::WebRTCNetwork {
#if USE(LIBWEBRTC)
enum class EcnMarking : int;
#endif
#if USE(LIBWEBRTC)
struct IPAddress;
#endif
#if USE(LIBWEBRTC)
struct InterfaceAddress;
#endif
#if USE(LIBWEBRTC)
struct SocketAddress;
#endif
}

namespace webrtc {
#if (USE(LIBWEBRTC)) && (USE(LIBWEBRTC) && PLATFORM(COCOA))
enum class WebKitEncodedVideoRotation : uint8_t;
#endif
#if (USE(LIBWEBRTC)) && (USE(LIBWEBRTC) && PLATFORM(COCOA))
enum class VideoFrameType : int;
#endif
#if (USE(LIBWEBRTC)) && (USE(LIBWEBRTC) && PLATFORM(COCOA))
enum class VideoContentType : uint8_t;
#endif
#if (USE(LIBWEBRTC)) && (USE(LIBWEBRTC) && PLATFORM(COCOA))
struct WebKitEncodedFrameInfo;
#endif
}

enum class WTFLogLevel : uint8_t;
enum class WTFLogChannelState : uint8_t;
enum class GCGLErrorCode : uint8_t;
#if PLATFORM(COCOA)
struct AudioStreamBasicDescription;
#endif
#if USE(SKIA)
struct hb_feature_t;
#endif
#if USE(SKIA)
template<typename> class sk_sp;
#endif
#if USE(SKIA)
template<typename> class sk_sp;
#endif
#if USE(SKIA)
class SkString;
#endif
class SkFontStyle;

namespace IPC { template<typename> class ObjectIdentifierReference; };
namespace IPC { template<typename> class ObjectIdentifierWriteReference; };
namespace IPC { template<typename> struct ObjectIdentifierReadReference; };
namespace WebCore { using RenderingResourceIdentifier = AtomicObjectIdentifier<RenderingResourceIdentifierType>; };
namespace WebCore { using SnapshotIdentifier = AtomicObjectIdentifier<SnapshotIdentifierType>; };
namespace WebKit { using RemoteVideoFrameIdentifier = AtomicObjectIdentifier<RemoteVideoFrameIdentifierType>; };
namespace WebKit { using RemoteSerializedImageBufferIdentifier = AtomicObjectIdentifier<RemoteSerializedImageBufferIdentifierType>; };
namespace WebKit { struct EditorStateIdentifierType; };
namespace WebKit { struct RenderingUpdateIDType; };
namespace WebKit { struct TransactionIDType; };
namespace WebKit { struct FocusedElementInformationIdentifierType; };
namespace WebCore { using BackForwardFrameItemIdentifierID = ObjectIdentifier<BackForwardFrameItemIdentifierType>; };
namespace WebCore { using BackForwardItemIdentifierID = ObjectIdentifier<BackForwardItemIdentifierType>; };
namespace WebCore { using DOMCacheIdentifierID = AtomicObjectIdentifier<DOMCacheIdentifierType>; };
namespace WebCore { using OpaqueOriginIdentifier = AtomicObjectIdentifier<OpaqueOriginIdentifierType>; };
namespace WebCore { using PlatformLayerIdentifierID = ObjectIdentifier<PlatformLayerIdentifierType>; };
namespace WebCore { using PlaybackTargetClientContextID = ObjectIdentifier<PlaybackTargetClientContextIdentifierType>; };
namespace WebCore { using RTCDataChannelLocalIdentifier =  AtomicObjectIdentifier<RTCDataChannelLocalIdentifierType>; };
namespace WebCore { using ScrollingNodeIdentifier = ObjectIdentifier<ScrollingNodeIDType>; };
namespace WebCore { using SharedWorkerObjectIdentifierID = ObjectIdentifier<SharedWorkerObjectIdentifierType>; };
namespace WebCore { using UserGestureTokenIdentifierID = ObjectIdentifier<UserGestureTokenIdentifierType>; };
namespace WebCore { using WebLockIdentifierID = AtomicObjectIdentifier<WebLockIdentifierType>; };
#if USE(SKIA)
class SkColorSpace;;
#endif
#if USE(SKIA)
class SkData;;
#endif
namespace WebCore {
template<typename> class ProcessQualified;
using BackForwardFrameItemIdentifier = ProcessQualified<BackForwardFrameItemIdentifierID>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using BackForwardItemIdentifier = ProcessQualified<BackForwardItemIdentifierID>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using DOMCacheIdentifier = ProcessQualified<DOMCacheIdentifierID>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using OpaqueOriginIdentifierProcessQualified = ProcessQualified<OpaqueOriginIdentifier>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using PlatformLayerIdentifier = ProcessQualified<PlatformLayerIdentifierID>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using PlaybackTargetClientContextIdentifier = ProcessQualified<PlaybackTargetClientContextID>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using RTCDataChannelIdentifier = ProcessQualified<RTCDataChannelLocalIdentifier>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using SharedWorkerObjectIdentifier = ProcessQualified<SharedWorkerObjectIdentifierID>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using UserGestureTokenIdentifier = ProcessQualified<UserGestureTokenIdentifierID>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using WebLockIdentifier = ProcessQualified<WebLockIdentifierID>;
}
namespace WebCore {
template<typename> class ProcessQualified;
using ScrollingNodeID = ProcessQualified<ScrollingNodeIdentifier>;
}
namespace WebCore {
using ScriptExecutionContextIdentifier = ProcessQualified<WTF::UUID>;
}
namespace WebCore {
template<typename> class RectEdges;
using FloatBoxExtent = RectEdges<float>;
}
namespace WebCore {
template<typename, typename> struct ScrollSnapOffsetsInfo;
using FloatScrollSnapOffsetsInfo = ScrollSnapOffsetsInfo<float, WebCore::FloatRect>;
}
namespace WebCore {
template<typename> struct SnapOffset;
using FloatSnapOffset = SnapOffset<float>;
}
namespace WebCore {
template<typename> class FontTaggedSetting;
using FloatFontTaggedSetting = FontTaggedSetting<float>;
}
namespace WebCore {
template<typename> class FontTaggedSetting;
using IntFontTaggedSetting = FontTaggedSetting<int>;
}
namespace WebCore {
template<typename> class FontTaggedSettings;
using FontVariationSettings = FontTaggedSettings<float>;
}
namespace WebCore {
template<typename> class FontTaggedSettings;
using FontFeatureSettings = FontTaggedSettings<int>;
}
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
namespace WebKit {
using RemoteVideoFrameReference = IPC::ObjectIdentifierReference<WebKit::RemoteVideoFrameIdentifier>;
}
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
namespace WebKit {
using RemoteVideoFrameWriteReference = IPC::ObjectIdentifierWriteReference<WebKit::RemoteVideoFrameIdentifier>;
}
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
namespace WebKit {
using RemoteVideoFrameReadReference = IPC::ObjectIdentifierReadReference<WebKit::RemoteVideoFrameIdentifier>;
}
#endif
#if ENABLE(GPU_PROCESS)
namespace WebKit {
using RemoteSerializedImageBufferReference = IPC::ObjectIdentifierReference<WebKit::RemoteSerializedImageBufferIdentifier>;
}
#endif
#if ENABLE(GPU_PROCESS)
namespace WebKit {
using RemoteSerializedImageBufferWriteReference = IPC::ObjectIdentifierWriteReference<WebKit::RemoteSerializedImageBufferIdentifier>;
}
#endif
#if ENABLE(GPU_PROCESS)
namespace WebKit {
using RemoteSerializedImageBufferReadReference = IPC::ObjectIdentifierReadReference<WebKit::RemoteSerializedImageBufferIdentifier>;
}
#endif
namespace WebKit {
template<typename> class MonotonicObjectIdentifier;
using EditorStateIdentifier = MonotonicObjectIdentifier<EditorStateIdentifierType>;
}
namespace WebKit {
template<typename> class MonotonicObjectIdentifier;
using RenderingUpdateID = MonotonicObjectIdentifier<RenderingUpdateIDType>;
}
namespace WebKit {
template<typename> class MonotonicObjectIdentifier;
using TransactionIdentifier = MonotonicObjectIdentifier<TransactionIDType>;
}
namespace WebKit {
template<typename> class MonotonicObjectIdentifier;
using FocusedElementInformationIdentifier = MonotonicObjectIdentifier<FocusedElementInformationIdentifierType>;
}
namespace WebKit {
using TransactionID = WebCore::ProcessQualified<TransactionIdentifier>;
}
namespace WebKit {
using PlaybackSessionContextIdentifier = WebCore::ProcessQualified<ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>>;
}

namespace IPC {

class Decoder;
class Encoder;
class StreamConnectionEncoder;

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::GPUProcessCreationParameters> {
    static void encode(Encoder&, WebKit::GPUProcessCreationParameters&&);
    static std::optional<WebKit::GPUProcessCreationParameters> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::GPUProcessPreferences> {
    static void encode(Encoder&, const WebKit::GPUProcessPreferences&);
    static std::optional<WebKit::GPUProcessPreferences> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::GPUProcessSessionParameters> {
    static void encode(Encoder&, WebKit::GPUProcessSessionParameters&&);
    static std::optional<WebKit::GPUProcessSessionParameters> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::PathMoveTo> {
    static void encode(Encoder&, const WebCore::PathMoveTo&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathMoveTo&);
    static std::optional<WebCore::PathMoveTo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathLineTo> {
    static void encode(Encoder&, const WebCore::PathLineTo&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathLineTo&);
    static std::optional<WebCore::PathLineTo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathQuadCurveTo> {
    static void encode(Encoder&, const WebCore::PathQuadCurveTo&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathQuadCurveTo&);
    static std::optional<WebCore::PathQuadCurveTo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathBezierCurveTo> {
    static void encode(Encoder&, const WebCore::PathBezierCurveTo&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathBezierCurveTo&);
    static std::optional<WebCore::PathBezierCurveTo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathArcTo> {
    static void encode(Encoder&, const WebCore::PathArcTo&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathArcTo&);
    static std::optional<WebCore::PathArcTo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathArc> {
    static void encode(Encoder&, const WebCore::PathArc&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathArc&);
    static std::optional<WebCore::PathArc> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathClosedArc> {
    static void encode(Encoder&, const WebCore::PathClosedArc&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathClosedArc&);
    static std::optional<WebCore::PathClosedArc> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathEllipse> {
    static void encode(Encoder&, const WebCore::PathEllipse&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathEllipse&);
    static std::optional<WebCore::PathEllipse> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathEllipseInRect> {
    static void encode(Encoder&, const WebCore::PathEllipseInRect&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathEllipseInRect&);
    static std::optional<WebCore::PathEllipseInRect> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathRect> {
    static void encode(Encoder&, const WebCore::PathRect&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathRect&);
    static std::optional<WebCore::PathRect> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathRoundedRect> {
    static void encode(Encoder&, const WebCore::PathRoundedRect&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathRoundedRect&);
    static std::optional<WebCore::PathRoundedRect> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathContinuousRoundedRect> {
    static void encode(Encoder&, const WebCore::PathContinuousRoundedRect&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathContinuousRoundedRect&);
    static std::optional<WebCore::PathContinuousRoundedRect> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathDataLine> {
    static void encode(Encoder&, const WebCore::PathDataLine&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathDataLine&);
    static std::optional<WebCore::PathDataLine> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathDataQuadCurve> {
    static void encode(Encoder&, const WebCore::PathDataQuadCurve&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathDataQuadCurve&);
    static std::optional<WebCore::PathDataQuadCurve> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathDataBezierCurve> {
    static void encode(Encoder&, const WebCore::PathDataBezierCurve&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathDataBezierCurve&);
    static std::optional<WebCore::PathDataBezierCurve> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathDataArc> {
    static void encode(Encoder&, const WebCore::PathDataArc&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathDataArc&);
    static std::optional<WebCore::PathDataArc> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathCloseSubpath> {
    static void encode(Encoder&, const WebCore::PathCloseSubpath&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathCloseSubpath&);
    static std::optional<WebCore::PathCloseSubpath> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathSegment> {
    static void encode(Encoder&, const WebCore::PathSegment&);
    static void encode(StreamConnectionEncoder&, const WebCore::PathSegment&);
    static std::optional<WebCore::PathSegment> decode(Decoder&);
};

#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> struct ArgumentCoder<WebKit::RemoteGraphicsContextGLInitializationState> {
    static void encode(Encoder&, const WebKit::RemoteGraphicsContextGLInitializationState&);
    static std::optional<WebKit::RemoteGraphicsContextGLInitializationState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::RemoteGPURequestAdapterResponse> {
    static void encode(Encoder&, const WebKit::RemoteGPURequestAdapterResponse&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteGPURequestAdapterResponse&);
    static std::optional<WebKit::RemoteGPURequestAdapterResponse> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::AudioTrackPrivateRemoteConfiguration> {
    static void encode(Encoder&, const WebKit::AudioTrackPrivateRemoteConfiguration&);
    static std::optional<WebKit::AudioTrackPrivateRemoteConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
template<> struct ArgumentCoder<WebKit::InitializationSegmentInfo> {
    static void encode(Encoder&, const WebKit::InitializationSegmentInfo&);
    static std::optional<WebKit::InitializationSegmentInfo> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(MEDIA_SOURCE)
template<> struct ArgumentCoder<WebKit::MediaDescriptionInfo> {
    static void encode(Encoder&, const WebKit::MediaDescriptionInfo&);
    static std::optional<WebKit::MediaDescriptionInfo> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::RemoteMediaPlayerProxyConfiguration> {
    static void encode(Encoder&, const WebKit::RemoteMediaPlayerProxyConfiguration&);
    static std::optional<WebKit::RemoteMediaPlayerProxyConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::RemoteAudioInfo> {
    static void encode(Encoder&, const WebKit::RemoteAudioInfo&);
    static std::optional<WebKit::RemoteAudioInfo> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::RemoteVideoInfo> {
    static void encode(Encoder&, const WebKit::RemoteVideoInfo&);
    static std::optional<WebKit::RemoteVideoInfo> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::TextTrackPrivateRemoteConfiguration> {
    static void encode(Encoder&, const WebKit::TextTrackPrivateRemoteConfiguration&);
    static std::optional<WebKit::TextTrackPrivateRemoteConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::TrackPrivateRemoteConfiguration> {
    static void encode(Encoder&, const WebKit::TrackPrivateRemoteConfiguration&);
    static std::optional<WebKit::TrackPrivateRemoteConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::VideoTrackPrivateRemoteConfiguration> {
    static void encode(Encoder&, const WebKit::VideoTrackPrivateRemoteConfiguration&);
    static std::optional<WebKit::VideoTrackPrivateRemoteConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(MODEL_PROCESS)
template<> struct ArgumentCoder<WebKit::ModelProcessCreationParameters> {
    static void encode(Encoder&, WebKit::ModelProcessCreationParameters&&);
    static std::optional<WebKit::ModelProcessCreationParameters> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::NetworkProcessCreationParameters> {
    static void encode(Encoder&, WebKit::NetworkProcessCreationParameters&&);
    static std::optional<WebKit::NetworkProcessCreationParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::NetworkResourceLoadParameters> {
    static void encode(Encoder&, WebKit::NetworkResourceLoadParameters&&);
    static std::optional<WebKit::NetworkResourceLoadParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::NetworkSessionCreationParameters> {
    static void encode(Encoder&, WebKit::NetworkSessionCreationParameters&&);
    static std::optional<WebKit::NetworkSessionCreationParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::ITPThirdPartyData> {
    static void encode(Encoder&, const WebKit::ITPThirdPartyData&);
    static std::optional<WebKit::ITPThirdPartyData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::ITPThirdPartyDataForSpecificFirstParty> {
    static void encode(Encoder&, const WebKit::ITPThirdPartyDataForSpecificFirstParty&);
    static std::optional<WebKit::ITPThirdPartyDataForSpecificFirstParty> decode(Decoder&);
};

template<> struct ArgumentCoder<IPC::ConnectionHandle> {
    static void encode(Encoder&, IPC::ConnectionHandle&&);
    static std::optional<IPC::ConnectionHandle> decode(Decoder&);
};

template<> struct ArgumentCoder<IPC::FormDataReference> {
    static void encode(Encoder&, const IPC::FormDataReference&);
    static std::optional<IPC::FormDataReference> decode(Decoder&);
};

template<> struct ArgumentCoder<IPC::Signal> {
    static void encode(Encoder&, IPC::Signal&&);
    static std::optional<IPC::Signal> decode(Decoder&);
};

template<> struct ArgumentCoder<IPC::Semaphore> {
    static void encode(Encoder&, const IPC::Semaphore&);
    static std::optional<IPC::Semaphore> decode(Decoder&);
};

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::RemoteVideoFrameReference> {
    static void encode(Encoder&, const WebKit::RemoteVideoFrameReference&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteVideoFrameReference&);
    static std::optional<WebKit::RemoteVideoFrameReference> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::RemoteVideoFrameWriteReference> {
    static void encode(Encoder&, const WebKit::RemoteVideoFrameWriteReference&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteVideoFrameWriteReference&);
    static std::optional<WebKit::RemoteVideoFrameWriteReference> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::RemoteVideoFrameReadReference> {
    static void encode(Encoder&, const WebKit::RemoteVideoFrameReadReference&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteVideoFrameReadReference&);
    static std::optional<WebKit::RemoteVideoFrameReadReference> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::RemoteSerializedImageBufferReference> {
    static void encode(Encoder&, const WebKit::RemoteSerializedImageBufferReference&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteSerializedImageBufferReference&);
    static std::optional<WebKit::RemoteSerializedImageBufferReference> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::RemoteSerializedImageBufferWriteReference> {
    static void encode(Encoder&, const WebKit::RemoteSerializedImageBufferWriteReference&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteSerializedImageBufferWriteReference&);
    static std::optional<WebKit::RemoteSerializedImageBufferWriteReference> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::RemoteSerializedImageBufferReadReference> {
    static void encode(Encoder&, const WebKit::RemoteSerializedImageBufferReadReference&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteSerializedImageBufferReadReference&);
    static std::optional<WebKit::RemoteSerializedImageBufferReadReference> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<IPC::SharedBufferReference> {
    static void encode(Encoder&, const IPC::SharedBufferReference&);
    static std::optional<IPC::SharedBufferReference> decode(Decoder&);
};

template<> struct ArgumentCoder<IPC::SharedFileHandle> {
    static void encode(Encoder&, const IPC::SharedFileHandle&);
    static std::optional<IPC::SharedFileHandle> decode(Decoder&);
};

template<> struct ArgumentCoder<IPC::StreamServerConnectionHandle> {
    static void encode(Encoder&, IPC::StreamServerConnectionHandle&&);
    static std::optional<IPC::StreamServerConnectionHandle> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::AccessibilityPreferences> {
    static void encode(Encoder&, const WebKit::AccessibilityPreferences&);
    static std::optional<WebKit::AccessibilityPreferences> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::AuxiliaryProcessCreationParameters> {
    static void encode(Encoder&, const WebKit::AuxiliaryProcessCreationParameters&);
    static std::optional<WebKit::AuxiliaryProcessCreationParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::BackgroundFetchState> {
    static void encode(Encoder&, const WebKit::BackgroundFetchState&);
    static std::optional<WebKit::BackgroundFetchState> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::CallbackID> {
    static void encode(Encoder&, const WebKit::CallbackID&);
    static std::optional<WebKit::CallbackID> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::ContentWorldData> {
    static void encode(Encoder&, const WebKit::ContentWorldData&);
    static std::optional<WebKit::ContentWorldData> decode(Decoder&);
};

#if ENABLE(CONTEXT_MENUS)
template<> struct ArgumentCoder<WebKit::ContextMenuContextData> {
    static void encode(Encoder&, const WebKit::ContextMenuContextData&);
    static std::optional<WebKit::ContextMenuContextData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::DebuggableInfoData> {
    static void encode(Encoder&, const WebKit::DebuggableInfoData&);
    static std::optional<WebKit::DebuggableInfoData> decode(Decoder&);
};

#if PLATFORM(IOS_FAMILY)
template<> struct ArgumentCoder<WebKit::DocumentEditingContextRequest> {
    static void encode(Encoder&, const WebKit::DocumentEditingContextRequest&);
    static std::optional<WebKit::DocumentEditingContextRequest> decode(Decoder&);
};
#endif

#if PLATFORM(IOS_FAMILY)
template<> struct ArgumentCoder<WebKit::DocumentEditingContext> {
    static void encode(Encoder&, const WebKit::DocumentEditingContext&);
    static std::optional<WebKit::DocumentEditingContext> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::EditingRange> {
    static void encode(Encoder&, const WebKit::EditingRange&);
    static std::optional<WebKit::EditingRange> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::EditorState> {
    static void encode(Encoder&, const WebKit::EditorState&);
    static std::optional<WebKit::EditorState> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::FileSystemSyncAccessHandleInfo> {
    static void encode(Encoder&, const WebKit::FileSystemSyncAccessHandleInfo&);
    static std::optional<WebKit::FileSystemSyncAccessHandleInfo> decode(Decoder&);
};

#if PLATFORM(IOS_FAMILY)
template<> struct ArgumentCoder<WebKit::OptionItem> {
    static void encode(Encoder&, const WebKit::OptionItem&);
    static std::optional<WebKit::OptionItem> decode(Decoder&);
};
#endif

#if PLATFORM(IOS_FAMILY)
template<> struct ArgumentCoder<WebKit::FocusedElementInformation> {
    static void encode(Encoder&, const WebKit::FocusedElementInformation&);
    static std::optional<WebKit::FocusedElementInformation> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::FrameInfoData> {
    static void encode(Encoder&, const WebKit::FrameInfoData&);
    static std::optional<WebKit::FrameInfoData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::FrameTreeCreationParameters> {
    static void encode(Encoder&, const WebKit::FrameTreeCreationParameters&);
    static std::optional<WebKit::FrameTreeCreationParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::FrameTreeNodeData> {
    static void encode(Encoder&, const WebKit::FrameTreeNodeData&);
    static std::optional<WebKit::FrameTreeNodeData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::FullScreenMediaDetails> {
    static void encode(Encoder&, WebKit::FullScreenMediaDetails&&);
    static std::optional<WebKit::FullScreenMediaDetails> decode(Decoder&);
};

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::GPUProcessConnectionParameters> {
    static void encode(Encoder&, WebKit::GPUProcessConnectionParameters&&);
    static std::optional<WebKit::GPUProcessConnectionParameters> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::GoToBackForwardItemParameters> {
    static void encode(Encoder&, WebKit::GoToBackForwardItemParameters&&);
    static std::optional<WebKit::GoToBackForwardItemParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::NodeInfo> {
    static void encode(Encoder&, const WebKit::NodeInfo&);
    static std::optional<WebKit::NodeInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::JavaScriptEvaluationResult> {
    static void encode(Encoder&, const WebKit::JavaScriptEvaluationResult&);
    static std::optional<WebKit::JavaScriptEvaluationResult> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::LayerTreeContext> {
    static void encode(Encoder&, const WebKit::LayerTreeContext&);
    static std::optional<WebKit::LayerTreeContext> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::LoadParameters> {
    static void encode(Encoder&, WebKit::LoadParameters&&);
    static std::optional<WebKit::LoadParameters> decode(Decoder&);
};

#if ENABLE(ARKIT_INLINE_PREVIEW)
template<> struct ArgumentCoder<WebKit::ModelIdentifier> {
    static void encode(Encoder&, const WebKit::ModelIdentifier&);
    static std::optional<WebKit::ModelIdentifier> decode(Decoder&);
};
#endif

#if ENABLE(MODEL_PROCESS)
template<> struct ArgumentCoder<WebKit::ModelProcessConnectionParameters> {
    static void encode(Encoder&, WebKit::ModelProcessConnectionParameters&&);
    static std::optional<WebKit::ModelProcessConnectionParameters> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::EditorStateIdentifier> {
    static void encode(Encoder&, const WebKit::EditorStateIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebKit::EditorStateIdentifier&);
    static std::optional<WebKit::EditorStateIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::RenderingUpdateID> {
    static void encode(Encoder&, const WebKit::RenderingUpdateID&);
    static void encode(StreamConnectionEncoder&, const WebKit::RenderingUpdateID&);
    static std::optional<WebKit::RenderingUpdateID> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::TransactionIdentifier> {
    static void encode(Encoder&, const WebKit::TransactionIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebKit::TransactionIdentifier&);
    static std::optional<WebKit::TransactionIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::FocusedElementInformationIdentifier> {
    static void encode(Encoder&, const WebKit::FocusedElementInformationIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebKit::FocusedElementInformationIdentifier&);
    static std::optional<WebKit::FocusedElementInformationIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::NavigationActionData> {
    static void encode(Encoder&, const WebKit::NavigationActionData&);
    static std::optional<WebKit::NavigationActionData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::NetworkProcessConnectionParameters> {
    static void encode(Encoder&, const WebKit::NetworkProcessConnectionParameters&);
    static std::optional<WebKit::NetworkProcessConnectionParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PasteboardImage> {
    static void encode(Encoder&, const WebCore::PasteboardImage&);
    static std::optional<WebCore::PasteboardImage> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PasteboardWebContent> {
    static void encode(Encoder&, const WebCore::PasteboardWebContent&);
    static std::optional<WebCore::PasteboardWebContent> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PasteboardURL> {
    static void encode(Encoder&, const WebCore::PasteboardURL&);
    static std::optional<WebCore::PasteboardURL> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PasteboardBuffer> {
    static void encode(Encoder&, const WebCore::PasteboardBuffer&);
    static std::optional<WebCore::PasteboardBuffer> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::PlatformFontInfo> {
    static void encode(Encoder&, const WebKit::PlatformFontInfo&);
    static std::optional<WebKit::PlatformFontInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::PlatformPopupMenuData> {
    static void encode(Encoder&, const WebKit::PlatformPopupMenuData&);
    static std::optional<WebKit::PlatformPopupMenuData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::PolicyDecision> {
    static void encode(Encoder&, WebKit::PolicyDecision&&);
    static std::optional<WebKit::PolicyDecision> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::PolicyDecisionConsoleMessage> {
    static void encode(Encoder&, const WebKit::PolicyDecisionConsoleMessage&);
    static std::optional<WebKit::PolicyDecisionConsoleMessage> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::PrintInfo> {
    static void encode(Encoder&, const WebKit::PrintInfo&);
    static std::optional<WebKit::PrintInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BackForwardFrameItemIdentifier> {
    static void encode(Encoder&, const WebCore::BackForwardFrameItemIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::BackForwardFrameItemIdentifier&);
    static std::optional<WebCore::BackForwardFrameItemIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BackForwardItemIdentifier> {
    static void encode(Encoder&, const WebCore::BackForwardItemIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::BackForwardItemIdentifier&);
    static std::optional<WebCore::BackForwardItemIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DOMCacheIdentifier> {
    static void encode(Encoder&, const WebCore::DOMCacheIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::DOMCacheIdentifier&);
    static std::optional<WebCore::DOMCacheIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::OpaqueOriginIdentifierProcessQualified> {
    static void encode(Encoder&, const WebCore::OpaqueOriginIdentifierProcessQualified&);
    static void encode(StreamConnectionEncoder&, const WebCore::OpaqueOriginIdentifierProcessQualified&);
    static std::optional<WebCore::OpaqueOriginIdentifierProcessQualified> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PlatformLayerIdentifier> {
    static void encode(Encoder&, const WebCore::PlatformLayerIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::PlatformLayerIdentifier&);
    static std::optional<WebCore::PlatformLayerIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PlaybackTargetClientContextIdentifier> {
    static void encode(Encoder&, const WebCore::PlaybackTargetClientContextIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::PlaybackTargetClientContextIdentifier&);
    static std::optional<WebCore::PlaybackTargetClientContextIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RTCDataChannelIdentifier> {
    static void encode(Encoder&, const WebCore::RTCDataChannelIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::RTCDataChannelIdentifier&);
    static std::optional<WebCore::RTCDataChannelIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SharedWorkerObjectIdentifier> {
    static void encode(Encoder&, const WebCore::SharedWorkerObjectIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::SharedWorkerObjectIdentifier&);
    static std::optional<WebCore::SharedWorkerObjectIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::UserGestureTokenIdentifier> {
    static void encode(Encoder&, const WebCore::UserGestureTokenIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::UserGestureTokenIdentifier&);
    static std::optional<WebCore::UserGestureTokenIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::WebLockIdentifier> {
    static void encode(Encoder&, const WebCore::WebLockIdentifier&);
    static void encode(StreamConnectionEncoder&, const WebCore::WebLockIdentifier&);
    static std::optional<WebCore::WebLockIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ScrollingNodeID> {
    static void encode(Encoder&, const WebCore::ScrollingNodeID&);
    static void encode(StreamConnectionEncoder&, const WebCore::ScrollingNodeID&);
    static std::optional<WebCore::ScrollingNodeID> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ScriptExecutionContextIdentifier> {
    static void encode(Encoder&, const WebCore::ScriptExecutionContextIdentifier&);
    static std::optional<WebCore::ScriptExecutionContextIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::TransactionID> {
    static void encode(Encoder&, const WebKit::TransactionID&);
    static std::optional<WebKit::TransactionID> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::PlaybackSessionContextIdentifier> {
    static void encode(Encoder&, const WebKit::PlaybackSessionContextIdentifier&);
    static std::optional<WebKit::PlaybackSessionContextIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::ProvisionalFrameCreationParameters> {
    static void encode(Encoder&, const WebKit::ProvisionalFrameCreationParameters&);
    static std::optional<WebKit::ProvisionalFrameCreationParameters> decode(Decoder&);
};

#if USE(LIBWEBRTC)
template<> struct ArgumentCoder<WebKit::WebRTCNetwork::IPAddress> {
    static void encode(Encoder&, const WebKit::WebRTCNetwork::IPAddress&);
    static std::optional<WebKit::WebRTCNetwork::IPAddress> decode(Decoder&);
};
#endif

#if USE(LIBWEBRTC)
template<> struct ArgumentCoder<WebKit::WebRTCNetwork::InterfaceAddress> {
    static void encode(Encoder&, const WebKit::WebRTCNetwork::InterfaceAddress&);
    static std::optional<WebKit::WebRTCNetwork::InterfaceAddress> decode(Decoder&);
};
#endif

#if USE(LIBWEBRTC)
template<> struct ArgumentCoder<WebKit::WebRTCNetwork::SocketAddress> {
    static void encode(Encoder&, const WebKit::WebRTCNetwork::SocketAddress&);
    static std::optional<WebKit::WebRTCNetwork::SocketAddress> decode(Decoder&);
};
#endif

#if USE(LIBWEBRTC)
template<> struct ArgumentCoder<WebKit::RTCNetwork> {
    static void encode(Encoder&, const WebKit::RTCNetwork&);
    static std::optional<WebKit::RTCNetwork> decode(Decoder&);
};
#endif

#if (USE(LIBWEBRTC)) && (USE(LIBWEBRTC) && PLATFORM(COCOA))
template<> struct ArgumentCoder<webrtc::WebKitEncodedFrameInfo> {
    static void encode(Encoder&, const webrtc::WebKitEncodedFrameInfo&);
    static std::optional<webrtc::WebKitEncodedFrameInfo> decode(Decoder&);
};
#endif

#if USE(LIBWEBRTC)
template<> struct ArgumentCoder<WebKit::RTCPacketOptions> {
    static void encode(Encoder&, const WebKit::RTCPacketOptions&);
    static std::optional<WebKit::RTCPacketOptions> decode(Decoder&);
};
#endif

#if ENABLE(TOUCH_EVENTS)
template<> struct ArgumentCoder<WebKit::RemoteWebTouchEvent> {
    static void encode(Encoder&, const WebKit::RemoteWebTouchEvent&);
    static std::optional<WebKit::RemoteWebTouchEvent> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::RemoteWorkerInitializationData> {
    static void encode(Encoder&, const WebKit::RemoteWorkerInitializationData&);
    static std::optional<WebKit::RemoteWorkerInitializationData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::ResourceLoadInfo> {
    static void encode(Encoder&, const WebKit::ResourceLoadInfo&);
    static std::optional<WebKit::ResourceLoadInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::ResourceLoadStatisticsParameters> {
    static void encode(Encoder&, WebKit::ResourceLoadStatisticsParameters&&);
    static std::optional<WebKit::ResourceLoadStatisticsParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::SandboxExtensionHandle> {
    static void encode(Encoder&, WebKit::SandboxExtensionHandle&&);
    static std::optional<WebKit::SandboxExtensionHandle> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::ScriptTrackingPrivacyHost> {
    static void encode(Encoder&, const WebKit::ScriptTrackingPrivacyHost&);
    static std::optional<WebKit::ScriptTrackingPrivacyHost> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::ScriptTrackingPrivacyRules> {
    static void encode(Encoder&, const WebKit::ScriptTrackingPrivacyRules&);
    static std::optional<WebKit::ScriptTrackingPrivacyRules> decode(Decoder&);
};

#if ENABLE(MOMENTUM_EVENT_DISPATCHER)
template<> struct ArgumentCoder<WebKit::ScrollingAccelerationCurve> {
    static void encode(Encoder&, const WebKit::ScrollingAccelerationCurve&);
    static std::optional<WebKit::ScrollingAccelerationCurve> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::SerializedNode> {
    static void encode(Encoder&, const WebCore::SerializedNode&);
    static std::optional<WebCore::SerializedNode> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::HTTPBody> {
    static void encode(Encoder&, const WebKit::HTTPBody&);
    static std::optional<WebKit::HTTPBody> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::FrameState> {
    static void encode(Encoder&, const WebKit::FrameState&);
    static std::optional<Ref<WebKit::FrameState>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::BackForwardListState> {
    static void encode(Encoder&, const WebKit::BackForwardListState&);
    static std::optional<WebKit::BackForwardListState> decode(Decoder&);
};

#if ENABLE(IMAGE_ANALYSIS)
template<> struct ArgumentCoder<WebCore::TextRecognitionWordData> {
    static void encode(Encoder&, const WebCore::TextRecognitionWordData&);
    static std::optional<WebCore::TextRecognitionWordData> decode(Decoder&);
};
#endif

#if ENABLE(IMAGE_ANALYSIS)
template<> struct ArgumentCoder<WebCore::TextRecognitionLineData> {
    static void encode(Encoder&, const WebCore::TextRecognitionLineData&);
    static std::optional<WebCore::TextRecognitionLineData> decode(Decoder&);
};
#endif

#if ENABLE(IMAGE_ANALYSIS)
template<> struct ArgumentCoder<WebCore::TextRecognitionBlockData> {
    static void encode(Encoder&, const WebCore::TextRecognitionBlockData&);
    static std::optional<WebCore::TextRecognitionBlockData> decode(Decoder&);
};
#endif

#if ENABLE(IMAGE_ANALYSIS)
template<> struct ArgumentCoder<WebCore::TextRecognitionResult> {
    static void encode(Encoder&, const WebCore::TextRecognitionResult&);
    static std::optional<WebCore::TextRecognitionResult> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::URLSchemeTaskParameters> {
    static void encode(Encoder&, const WebKit::URLSchemeTaskParameters&);
    static std::optional<WebKit::URLSchemeTaskParameters> decode(Decoder&);
};

#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
template<> struct ArgumentCoder<WebKit::UpdateInfo> {
    static void encode(Encoder&, WebKit::UpdateInfo&&);
    static std::optional<WebKit::UpdateInfo> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::UserContentControllerParameters> {
    static void encode(Encoder&, const WebKit::UserContentControllerParameters&);
    static std::optional<WebKit::UserContentControllerParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::UserData> {
    static void encode(Encoder&, const WebKit::UserData&);
    static std::optional<WebKit::UserData> decode(Decoder&);
};

#if ENABLE(UI_SIDE_COMPOSITING)
template<> struct ArgumentCoder<WebKit::VisibleContentRectUpdateInfo> {
    static void encode(Encoder&, const WebKit::VisibleContentRectUpdateInfo&);
    static std::optional<WebKit::VisibleContentRectUpdateInfo> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WTF::URL> {
    static void encode(Encoder&, const WTF::URL&);
    static void encode(StreamConnectionEncoder&, const WTF::URL&);
    static std::optional<WTF::URL> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::CString> {
    static void encode(Encoder&, const WTF::CString&);
    static void encode(StreamConnectionEncoder&, const WTF::CString&);
    static std::optional<WTF::CString> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::MediaTime> {
    static void encode(Encoder&, const WTF::MediaTime&);
    static void encode(StreamConnectionEncoder&, const WTF::MediaTime&);
    static std::optional<WTF::MediaTime> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::Seconds> {
    static void encode(Encoder&, const WTF::Seconds&);
    static void encode(StreamConnectionEncoder&, const WTF::Seconds&);
    static std::optional<WTF::Seconds> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::MonotonicTime> {
    static void encode(Encoder&, const WTF::MonotonicTime&);
    static std::optional<WTF::MonotonicTime> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::WallTime> {
    static void encode(Encoder&, const WTF::WallTime&);
    static std::optional<WTF::WallTime> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomString> {
    static void encode(Encoder&, const WTF::AtomString&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomString&);
    static std::optional<WTF::AtomString> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::UUID> {
    static void encode(Encoder&, const WTF::UUID&);
    static std::optional<WTF::UUID> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::JSONImpl::Value> {
    static void encode(Encoder&, const WTF::JSONImpl::Value&);
    static std::optional<Ref<WTF::JSONImpl::Value>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandler>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::AXIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::AXIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::AXIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::AXIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::BackgroundFetchRecordIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::NodeIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::NodeIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::NodeIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::NodeIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::FetchIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::FetchIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::FetchIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::FetchIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::ImageDecoderIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::ImageOverlayDataDetectionResultIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::InbandGenericCueIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::LayerHostingContextIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::MediaSessionGroupIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::MediaUniqueIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::RealtimeMediaSourceIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::SWServerToContextConnectionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::SharedWorkerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::SpeechRecognitionConnectionClientIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::TextCheckingRequestIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::TextManipulationItemIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::TextManipulationTokenIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::WindowIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::WindowIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::WindowIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::WindowIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::WorkletGlobalScopeIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::AudioMediaStreamTrackRendererInternalUnitIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::ContentWorldIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::ImageAnalysisRequestIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::MediaDevicePermissionRequestIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteAudioSessionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteCDMIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteCDMInstanceSessionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteLegacyCDMSessionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteMediaSourceIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteSourceBufferIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RetrieveRecordResponseBodyCallbackIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::ShapeDetectionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::StorageAreaImplIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::StorageAreaMapIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::StorageNamespaceIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::UserScriptIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::UserStyleSheetIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::VisitedLinkTableIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WCLayerTreeHostIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionControllerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::XRDeviceIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::AttributedStringTextListIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableBlockIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::AttributedStringTextTableIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::BackForwardFrameItemIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::BackForwardItemIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::DictationContextType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::DictationContextType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::DictationContextType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::DictationContextType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::FrameIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::FrameIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::FrameIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::FrameIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::MediaKeySystemRequestIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::MediaPlayerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::MediaPlayerClientIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::MediaSessionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::ModelPlayerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::NavigationIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::PageIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::PageIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::PageIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::PageIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::PlatformLayerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::PlaybackTargetClientContextIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::PushSubscriptionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::ProcessIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::ScrollingNodeIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::SharedWorkerObjectIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::SleepDisablerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::UserGestureTokenIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::UserMediaRequestIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebCore::WebTransportStreamIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::AuthenticationChallengeIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::DataTaskIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::DisplayLinkObserverIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::DrawingAreaIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::DownloadIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::DownloadIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::DownloadIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::DownloadIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::GeolocationIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::IPCConnectionTesterIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::IPCStreamTesterIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::JSObjectIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::JSObjectIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::JSObjectIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::JSObjectIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::MarkSurfacesAsVolatileRequestIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::MessageBatchIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::NetworkResourceLoadIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::PDFPluginIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::PageGroupIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteAudioDestinationIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteAudioHardwareListenerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteImageBufferSetIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteMediaResourceIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::RemoteRemoteCommandListenerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::SampleBufferDisplayLayerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::ScriptMessageHandlerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::TapIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::TapIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::TapIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::TapIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::TextCheckerRequestType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::TransactionIDType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::TransactionIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::TransactionIDType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::TransactionIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::UserContentControllerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionContextIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionFrameIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionPortChannelIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionTabIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebExtensionWindowIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebPageProxyIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebTransportSessionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>> {
    static void encode(Encoder&, const WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>&);
    static std::optional<WTF::ObjectIdentifier<WebKit::WebURLSchemeHandlerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::ResourceLoader>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::WebSocketChannel>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>&);
    static std::optional<WTF::AtomicObjectIdentifier<IPC::SyncRequestIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<JSC::MicrotaskIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<TestWebKitAPI::TestedObjectIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::DOMCacheIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::BroadcastChannelIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::FileSystemWritableFileStreamIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::IDBDatabaseConnectionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::IDBIndexIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::IDBObjectStoreIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::IDBResourceObjectIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::LibWebRTCSocketIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::MainThreadPermissionObserverIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::OpaqueOriginIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::PortIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::RTCDataChannelLocalIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::RTCRtpScriptTransformerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::RenderingResourceIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::ResourceLoaderIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerJobIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::ServiceWorkerRegistrationIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::SnapshotIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::WebLockIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::WorkerFileSystemStorageConnectionCallbackIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::GPUProcessConnectionIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::LegacyCustomProtocolIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::LibWebRTCResolverIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::LogStreamIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::RemoteDisplayListRecorderIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::RemoteSerializedImageBufferIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::RemoteVideoFrameIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::VideoDecoderIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::VideoEncoderIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::WCContentBufferIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>&);
    static std::optional<WTF::AtomicObjectIdentifier<IPC::AsyncReplyIDType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::FileSystemHandleIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::FileSystemSyncAccessHandleIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebCore::WebSocketIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::GraphicsContextGLIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::QuotaIncreaseRequestIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::RenderingBackendIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::StorageAreaIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>> {
    static void encode(Encoder&, const WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>&);
    static void encode(StreamConnectionEncoder&, const WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>&);
    static std::optional<WTF::AtomicObjectIdentifier<WebKit::WebGPUIdentifierType>> decode(Decoder&);
};

template<> struct ArgumentCoder<WTF::MemoryPressureHandlerConfiguration> {
    static void encode(Encoder&, const WTF::MemoryPressureHandlerConfiguration&);
    static std::optional<WTF::MemoryPressureHandlerConfiguration> decode(Decoder&);
};

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WTF::MachSendRightAnnotated> {
    static void encode(Encoder&, const WTF::MachSendRightAnnotated&);
    static std::optional<WTF::MachSendRightAnnotated> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::WebBackForwardListCounts> {
    static void encode(Encoder&, const WebKit::WebBackForwardListCounts&);
    static std::optional<WebKit::WebBackForwardListCounts> decode(Decoder&);
};

#if ENABLE(CONTEXT_MENUS)
template<> struct ArgumentCoder<WebKit::WebContextMenuItemData> {
    static void encode(Encoder&, const WebKit::WebContextMenuItemData&);
    static std::optional<WebKit::WebContextMenuItemData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::DOMCacheEngine::CacheInfo> {
    static void encode(Encoder&, const WebCore::DOMCacheEngine::CacheInfo&);
    static std::optional<WebCore::DOMCacheEngine::CacheInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DOMCacheEngine::CacheInfos> {
    static void encode(Encoder&, const WebCore::DOMCacheEngine::CacheInfos&);
    static std::optional<WebCore::DOMCacheEngine::CacheInfos> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DOMCacheEngine::CacheIdentifierOperationResult> {
    static void encode(Encoder&, const WebCore::DOMCacheEngine::CacheIdentifierOperationResult&);
    static std::optional<WebCore::DOMCacheEngine::CacheIdentifierOperationResult> decode(Decoder&);
};

#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
template<> struct ArgumentCoder<WebCore::TranslationContextMenuInfo> {
    static void encode(Encoder&, const WebCore::TranslationContextMenuInfo&);
    static std::optional<WebCore::TranslationContextMenuInfo> decode(Decoder&);
};
#endif

#if USE(APPKIT)
template<> struct ArgumentCoder<WebCore::AppKitControlSystemImage> {
    static void encode(Encoder&, const WebCore::AppKitControlSystemImage&);
    static void encode(StreamConnectionEncoder&, const WebCore::AppKitControlSystemImage&);
    static std::optional<Ref<WebCore::AppKitControlSystemImage>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::DOMCacheEngine::CrossThreadRecord> {
    static void encode(Encoder&, const WebCore::DOMCacheEngine::CrossThreadRecord&);
    static std::optional<WebCore::DOMCacheEngine::CrossThreadRecord> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TransformationMatrix> {
    static void encode(Encoder&, const WebCore::TransformationMatrix&);
    static void encode(StreamConnectionEncoder&, const WebCore::TransformationMatrix&);
    static std::optional<WebCore::TransformationMatrix> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CacheQueryOptions> {
    static void encode(Encoder&, const WebCore::CacheQueryOptions&);
    static std::optional<WebCore::CacheQueryOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CharacterRange> {
    static void encode(Encoder&, const WebCore::CharacterRange&);
    static std::optional<WebCore::CharacterRange> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::AffineTransform> {
    static void encode(Encoder&, const WebCore::AffineTransform&);
    static void encode(StreamConnectionEncoder&, const WebCore::AffineTransform&);
    static std::optional<WebCore::AffineTransform> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatPoint> {
    static void encode(Encoder&, const WebCore::FloatPoint&);
    static void encode(StreamConnectionEncoder&, const WebCore::FloatPoint&);
    static std::optional<WebCore::FloatPoint> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatPoint3D> {
    static void encode(Encoder&, const WebCore::FloatPoint3D&);
    static void encode(StreamConnectionEncoder&, const WebCore::FloatPoint3D&);
    static std::optional<WebCore::FloatPoint3D> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatQuad> {
    static void encode(Encoder&, const WebCore::FloatQuad&);
    static std::optional<WebCore::FloatQuad> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBCursorRecord> {
    static void encode(Encoder&, const WebCore::IDBCursorRecord&);
    static std::optional<WebCore::IDBCursorRecord> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBCursorInfo> {
    static void encode(Encoder&, const WebCore::IDBCursorInfo&);
    static std::optional<WebCore::IDBCursorInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBError> {
    static void encode(Encoder&, const WebCore::IDBError&);
    static std::optional<WebCore::IDBError> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBGetAllRecordsData> {
    static void encode(Encoder&, const WebCore::IDBGetAllRecordsData&);
    static std::optional<WebCore::IDBGetAllRecordsData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBGetResult> {
    static void encode(Encoder&, const WebCore::IDBGetResult&);
    static std::optional<WebCore::IDBGetResult> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBGetAllResult> {
    static void encode(Encoder&, const WebCore::IDBGetAllResult&);
    static std::optional<WebCore::IDBGetAllResult> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBDatabaseInfo> {
    static void encode(Encoder&, const WebCore::IDBDatabaseInfo&);
    static std::optional<WebCore::IDBDatabaseInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBKeyRangeData> {
    static void encode(Encoder&, const WebCore::IDBKeyRangeData&);
    static std::optional<WebCore::IDBKeyRangeData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBTransactionInfo> {
    static void encode(Encoder&, const WebCore::IDBTransactionInfo&);
    static std::optional<WebCore::IDBTransactionInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBGetRecordData> {
    static void encode(Encoder&, const WebCore::IDBGetRecordData&);
    static std::optional<WebCore::IDBGetRecordData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBIndexInfo> {
    static void encode(Encoder&, const WebCore::IDBIndexInfo&);
    static std::optional<WebCore::IDBIndexInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBObjectStoreInfo> {
    static void encode(Encoder&, const WebCore::IDBObjectStoreInfo&);
    static std::optional<WebCore::IDBObjectStoreInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBIterateCursorData> {
    static void encode(Encoder&, const WebCore::IDBIterateCursorData&);
    static std::optional<WebCore::IDBIterateCursorData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBResourceIdentifier> {
    static void encode(Encoder&, const WebCore::IDBResourceIdentifier&);
    static std::optional<WebCore::IDBResourceIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBValue> {
    static void encode(Encoder&, const WebCore::IDBValue&);
    static std::optional<WebCore::IDBValue> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBOpenRequestData> {
    static void encode(Encoder&, const WebCore::IDBOpenRequestData&);
    static std::optional<WebCore::IDBOpenRequestData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBRequestData> {
    static void encode(Encoder&, const WebCore::IDBRequestData&);
    static std::optional<WebCore::IDBRequestData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBDatabaseIdentifier> {
    static void encode(Encoder&, const WebCore::IDBDatabaseIdentifier&);
    static std::optional<WebCore::IDBDatabaseIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBDatabaseNameAndVersion> {
    static void encode(Encoder&, const WebCore::IDBDatabaseNameAndVersion&);
    static std::optional<WebCore::IDBDatabaseNameAndVersion> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBResultData> {
    static void encode(Encoder&, const WebCore::IDBResultData&);
    static std::optional<WebCore::IDBResultData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IDBKeyData> {
    static void encode(Encoder&, const WebCore::IDBKeyData&);
    static std::optional<WebCore::IDBKeyData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IndexKey> {
    static void encode(Encoder&, const WebCore::IndexKey&);
    static std::optional<WebCore::IndexKey> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatRect> {
    static void encode(Encoder&, const WebCore::FloatRect&);
    static void encode(StreamConnectionEncoder&, const WebCore::FloatRect&);
    static std::optional<WebCore::FloatRect> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LinearTimingFunction> {
    static void encode(Encoder&, const WebCore::LinearTimingFunction&);
    static std::optional<Ref<WebCore::LinearTimingFunction>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CubicBezierTimingFunction> {
    static void encode(Encoder&, const WebCore::CubicBezierTimingFunction&);
    static std::optional<Ref<WebCore::CubicBezierTimingFunction>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::StepsTimingFunction> {
    static void encode(Encoder&, const WebCore::StepsTimingFunction&);
    static std::optional<Ref<WebCore::StepsTimingFunction>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SpringTimingFunction> {
    static void encode(Encoder&, const WebCore::SpringTimingFunction&);
    static std::optional<Ref<WebCore::SpringTimingFunction>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ResourceLoadStatistics> {
    static void encode(Encoder&, const WebCore::ResourceLoadStatistics&);
    static std::optional<WebCore::ResourceLoadStatistics> decode(Decoder&);
};

#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> struct ArgumentCoder<WebCore::GraphicsContextGLActiveInfo> {
    static void encode(Encoder&, const WebCore::GraphicsContextGLActiveInfo&);
    static void encode(StreamConnectionEncoder&, const WebCore::GraphicsContextGLActiveInfo&);
    static std::optional<WebCore::GraphicsContextGLActiveInfo> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::ShareDataWithParsedURL> {
    static void encode(Encoder&, const WebCore::ShareDataWithParsedURL&);
    static std::optional<WebCore::ShareDataWithParsedURL> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ShareData> {
    static void encode(Encoder&, const WebCore::ShareData&);
    static std::optional<WebCore::ShareData> decode(Decoder&);
};

#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
template<> struct ArgumentCoder<WebCore::SpatialBackdropSource> {
    static void encode(Encoder&, const WebCore::SpatialBackdropSource&);
    static std::optional<WebCore::SpatialBackdropSource> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::TargetedElementAdjustment> {
    static void encode(Encoder&, const WebCore::TargetedElementAdjustment&);
    static std::optional<WebCore::TargetedElementAdjustment> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TargetedElementRequest> {
    static void encode(Encoder&, const WebCore::TargetedElementRequest&);
    static std::optional<WebCore::TargetedElementRequest> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TargetedElementInfo> {
    static void encode(Encoder&, const WebCore::TargetedElementInfo&);
    static std::optional<WebCore::TargetedElementInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RawFile> {
    static void encode(Encoder&, const WebCore::RawFile&);
    static std::optional<WebCore::RawFile> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatRoundedRect> {
    static void encode(Encoder&, const WebCore::FloatRoundedRect&);
    static void encode(StreamConnectionEncoder&, const WebCore::FloatRoundedRect&);
    static std::optional<WebCore::FloatRoundedRect> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IntRect> {
    static void encode(Encoder&, const WebCore::IntRect&);
    static void encode(StreamConnectionEncoder&, const WebCore::IntRect&);
    static std::optional<WebCore::IntRect> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IntPoint> {
    static void encode(Encoder&, const WebCore::IntPoint&);
    static void encode(StreamConnectionEncoder&, const WebCore::IntPoint&);
    static std::optional<WebCore::IntPoint> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IntSize> {
    static void encode(Encoder&, const WebCore::IntSize&);
    static void encode(StreamConnectionEncoder&, const WebCore::IntSize&);
    static std::optional<WebCore::IntSize> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatSize> {
    static void encode(Encoder&, const WebCore::FloatSize&);
    static void encode(StreamConnectionEncoder&, const WebCore::FloatSize&);
    static std::optional<WebCore::FloatSize> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LayoutUnit> {
    static void encode(Encoder&, const WebCore::LayoutUnit&);
    static void encode(StreamConnectionEncoder&, const WebCore::LayoutUnit&);
    static std::optional<WebCore::LayoutUnit> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LayoutPoint> {
    static void encode(Encoder&, const WebCore::LayoutPoint&);
    static void encode(StreamConnectionEncoder&, const WebCore::LayoutPoint&);
    static std::optional<WebCore::LayoutPoint> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LayoutSize> {
    static void encode(Encoder&, const WebCore::LayoutSize&);
    static void encode(StreamConnectionEncoder&, const WebCore::LayoutSize&);
    static std::optional<WebCore::LayoutSize> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DictionaryPopupInfo> {
    static void encode(Encoder&, const WebCore::DictionaryPopupInfo&);
    static std::optional<WebCore::DictionaryPopupInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PrivateClickMeasurement> {
    static void encode(Encoder&, const WebCore::PrivateClickMeasurement&);
    static std::optional<WebCore::PrivateClickMeasurement> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PCM::SourceSite> {
    static void encode(Encoder&, const WebCore::PCM::SourceSite&);
    static std::optional<WebCore::PCM::SourceSite> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PCM::AttributionDestinationSite> {
    static void encode(Encoder&, const WebCore::PCM::AttributionDestinationSite&);
    static std::optional<WebCore::PCM::AttributionDestinationSite> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PCM::EphemeralNonce> {
    static void encode(Encoder&, const WebCore::PCM::EphemeralNonce&);
    static std::optional<WebCore::PCM::EphemeralNonce> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PCM::AttributionTriggerData> {
    static void encode(Encoder&, const WebCore::PCM::AttributionTriggerData&);
    static std::optional<WebCore::PCM::AttributionTriggerData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PCM::AttributionTimeToSendData> {
    static void encode(Encoder&, const WebCore::PCM::AttributionTimeToSendData&);
    static std::optional<WebCore::PCM::AttributionTimeToSendData> decode(Decoder&);
};

#if ENABLE(APPLE_PAY_RECURRING_PAYMENTS)
template<> struct ArgumentCoder<WebCore::ApplePayRecurringPaymentRequest> {
    static void encode(Encoder&, const WebCore::ApplePayRecurringPaymentRequest&);
    static std::optional<WebCore::ApplePayRecurringPaymentRequest> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_MULTI_MERCHANT_PAYMENTS)
template<> struct ArgumentCoder<WebCore::ApplePayPaymentTokenContext> {
    static void encode(Encoder&, const WebCore::ApplePayPaymentTokenContext&);
    static std::optional<WebCore::ApplePayPaymentTokenContext> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_DEFERRED_PAYMENTS)
template<> struct ArgumentCoder<WebCore::ApplePayDeferredPaymentRequest> {
    static void encode(Encoder&, const WebCore::ApplePayDeferredPaymentRequest&);
    static std::optional<WebCore::ApplePayDeferredPaymentRequest> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_PAYMENT_ORDER_DETAILS)
template<> struct ArgumentCoder<WebCore::ApplePayPaymentOrderDetails> {
    static void encode(Encoder&, const WebCore::ApplePayPaymentOrderDetails&);
    static std::optional<WebCore::ApplePayPaymentOrderDetails> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_AMS_UI) && ENABLE(PAYMENT_REQUEST)
template<> struct ArgumentCoder<WebCore::ApplePayAMSUIRequest> {
    static void encode(Encoder&, const WebCore::ApplePayAMSUIRequest&);
    static std::optional<WebCore::ApplePayAMSUIRequest> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_AUTOMATIC_RELOAD_PAYMENTS)
template<> struct ArgumentCoder<WebCore::ApplePayAutomaticReloadPaymentRequest> {
    static void encode(Encoder&, const WebCore::ApplePayAutomaticReloadPaymentRequest&);
    static std::optional<WebCore::ApplePayAutomaticReloadPaymentRequest> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_SHIPPING_METHOD_DATE_COMPONENTS_RANGE)
template<> struct ArgumentCoder<WebCore::ApplePayDateComponents> {
    static void encode(Encoder&, const WebCore::ApplePayDateComponents&);
    static std::optional<WebCore::ApplePayDateComponents> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_SHIPPING_METHOD_DATE_COMPONENTS_RANGE)
template<> struct ArgumentCoder<WebCore::ApplePayDateComponentsRange> {
    static void encode(Encoder&, const WebCore::ApplePayDateComponentsRange&);
    static std::optional<WebCore::ApplePayDateComponentsRange> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePaySetupConfiguration> {
    static void encode(Encoder&, const WebCore::ApplePaySetupConfiguration&);
    static std::optional<WebCore::ApplePaySetupConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayLineItem> {
    static void encode(Encoder&, const WebCore::ApplePayLineItem&);
    static std::optional<WebCore::ApplePayLineItem> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayShippingMethod> {
    static void encode(Encoder&, const WebCore::ApplePayShippingMethod&);
    static std::optional<WebCore::ApplePayShippingMethod> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayError> {
    static void encode(Encoder&, const WebCore::ApplePayError&);
    static std::optional<Ref<WebCore::ApplePayError>> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayLogoSystemImage> {
    static void encode(Encoder&, const WebCore::ApplePayLogoSystemImage&);
    static void encode(StreamConnectionEncoder&, const WebCore::ApplePayLogoSystemImage&);
    static std::optional<Ref<WebCore::ApplePayLogoSystemImage>> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayDetailsUpdateBase> {
    static void encode(Encoder&, const WebCore::ApplePayDetailsUpdateBase&);
    static std::optional<WebCore::ApplePayDetailsUpdateBase> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayPaymentMethodUpdate> {
    static void encode(Encoder&, const WebCore::ApplePayPaymentMethodUpdate&);
    static std::optional<WebCore::ApplePayPaymentMethodUpdate> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayShippingContactUpdate> {
    static void encode(Encoder&, const WebCore::ApplePayShippingContactUpdate&);
    static std::optional<WebCore::ApplePayShippingContactUpdate> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayShippingMethodUpdate> {
    static void encode(Encoder&, const WebCore::ApplePayShippingMethodUpdate&);
    static std::optional<WebCore::ApplePayShippingMethodUpdate> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayPaymentAuthorizationResult> {
    static void encode(Encoder&, const WebCore::ApplePayPaymentAuthorizationResult&);
    static std::optional<WebCore::ApplePayPaymentAuthorizationResult> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_DISBURSEMENTS)
template<> struct ArgumentCoder<WebCore::ApplePayDisbursementRequest> {
    static void encode(Encoder&, const WebCore::ApplePayDisbursementRequest&);
    static std::optional<WebCore::ApplePayDisbursementRequest> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_INSTALLMENTS)
template<> struct ArgumentCoder<WebCore::ApplePayInstallmentConfiguration> {
    static void encode(Encoder&, const WebCore::ApplePayInstallmentConfiguration&);
    static std::optional<WebCore::ApplePayInstallmentConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_INSTALLMENTS)
template<> struct ArgumentCoder<WebCore::PaymentInstallmentConfiguration> {
    static void encode(Encoder&, const WebCore::PaymentInstallmentConfiguration&);
    static std::optional<WebCore::PaymentInstallmentConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_INSTALLMENTS)
template<> struct ArgumentCoder<WebCore::ApplePayInstallmentItem> {
    static void encode(Encoder&, const WebCore::ApplePayInstallmentItem&);
    static std::optional<WebCore::ApplePayInstallmentItem> decode(Decoder&);
};
#endif

#if ENABLE(APPLE_PAY_COUPON_CODE)
template<> struct ArgumentCoder<WebCore::ApplePayCouponCodeUpdate> {
    static void encode(Encoder&, const WebCore::ApplePayCouponCodeUpdate&);
    static std::optional<WebCore::ApplePayCouponCodeUpdate> decode(Decoder&);
};
#endif

#if ENABLE(APPLICATION_MANIFEST)
template<> struct ArgumentCoder<WebCore::ApplicationManifest> {
    static void encode(Encoder&, const WebCore::ApplicationManifest&);
    static std::optional<WebCore::ApplicationManifest> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::RetrieveRecordsOptions> {
    static void encode(Encoder&, const WebCore::RetrieveRecordsOptions&);
    static std::optional<WebCore::RetrieveRecordsOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ContactInfo> {
    static void encode(Encoder&, const WebCore::ContactInfo&);
    static std::optional<WebCore::ContactInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ContactsRequestData> {
    static void encode(Encoder&, const WebCore::ContactsRequestData&);
    static std::optional<WebCore::ContactsRequestData> decode(Decoder&);
};

#if ENABLE(MEDIA_SESSION)
template<> struct ArgumentCoder<WebCore::MediaPositionState> {
    static void encode(Encoder&, const WebCore::MediaPositionState&);
    static std::optional<WebCore::MediaPositionState> decode(Decoder&);
};
#endif

#if ENABLE(WEB_RTC)
template<> struct ArgumentCoder<WebCore::DetachedRTCDataChannel> {
    static void encode(Encoder&, const WebCore::DetachedRTCDataChannel&);
    static std::optional<WebCore::DetachedRTCDataChannel> decode(Decoder&);
};
#endif

#if ENABLE(WEB_CODECS)
template<> struct ArgumentCoder<WebCore::WebCodecsEncodedVideoChunkData> {
    static void encode(Encoder&, const WebCore::WebCodecsEncodedVideoChunkData&);
    static std::optional<WebCore::WebCodecsEncodedVideoChunkData> decode(Decoder&);
};
#endif

#if ENABLE(WEB_CODECS)
template<> struct ArgumentCoder<WebCore::WebCodecsEncodedAudioChunkData> {
    static void encode(Encoder&, const WebCore::WebCodecsEncodedAudioChunkData&);
    static std::optional<WebCore::WebCodecsEncodedAudioChunkData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::HTMLModelElementCamera> {
    static void encode(Encoder&, const WebCore::HTMLModelElementCamera&);
    static std::optional<WebCore::HTMLModelElementCamera> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NotificationData> {
    static void encode(Encoder&, const WebCore::NotificationData&);
    static std::optional<WebCore::NotificationData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PermissionDescriptor> {
    static void encode(Encoder&, const WebCore::PermissionDescriptor&);
    static std::optional<WebCore::PermissionDescriptor> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PushSubscriptionData> {
    static void encode(Encoder&, const WebCore::PushSubscriptionData&);
    static std::optional<WebCore::PushSubscriptionData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DeprecationReportBody> {
    static void encode(Encoder&, const WebCore::DeprecationReportBody&);
    static std::optional<Ref<WebCore::DeprecationReportBody>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Report> {
    static void encode(Encoder&, const WebCore::Report&);
    static std::optional<Ref<WebCore::Report>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TestReportBody> {
    static void encode(Encoder&, const WebCore::TestReportBody&);
    static std::optional<Ref<WebCore::TestReportBody>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SpeechRecognitionError> {
    static void encode(Encoder&, const WebCore::SpeechRecognitionError&);
    static std::optional<WebCore::SpeechRecognitionError> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SpeechRecognitionRequestInfo> {
    static void encode(Encoder&, const WebCore::SpeechRecognitionRequestInfo&);
    static std::optional<WebCore::SpeechRecognitionRequestInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SpeechRecognitionAlternativeData> {
    static void encode(Encoder&, const WebCore::SpeechRecognitionAlternativeData&);
    static std::optional<WebCore::SpeechRecognitionAlternativeData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SpeechRecognitionResultData> {
    static void encode(Encoder&, const WebCore::SpeechRecognitionResultData&);
    static std::optional<WebCore::SpeechRecognitionResultData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::WebLockManagerSnapshot> {
    static void encode(Encoder&, const WebCore::WebLockManagerSnapshot&);
    static std::optional<WebCore::WebLockManagerSnapshot> decode(Decoder&);
};

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::AuthenticatorResponseBaseData> {
    static void encode(Encoder&, const WebCore::AuthenticatorResponseBaseData&);
    static std::optional<WebCore::AuthenticatorResponseBaseData> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::AuthenticatorAttestationResponseData> {
    static void encode(Encoder&, const WebCore::AuthenticatorAttestationResponseData&);
    static std::optional<WebCore::AuthenticatorAttestationResponseData> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::AuthenticatorAssertionResponseData> {
    static void encode(Encoder&, const WebCore::AuthenticatorAssertionResponseData&);
    static std::optional<WebCore::AuthenticatorAssertionResponseData> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::AuthenticatorResponseData> {
    static void encode(Encoder&, const WebCore::AuthenticatorResponseData&);
    static std::optional<WebCore::AuthenticatorResponseData> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::AuthenticationExtensionsClientInputs> {
    static void encode(Encoder&, const WebCore::AuthenticationExtensionsClientInputs&);
    static std::optional<WebCore::AuthenticationExtensionsClientInputs> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::CredentialPropertiesOutput> {
    static void encode(Encoder&, const WebCore::CredentialPropertiesOutput&);
    static std::optional<WebCore::CredentialPropertiesOutput> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::AuthenticationExtensionsClientOutputs> {
    static void encode(Encoder&, const WebCore::AuthenticationExtensionsClientOutputs&);
    static std::optional<WebCore::AuthenticationExtensionsClientOutputs> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::UnknownCredentialOptions> {
    static void encode(Encoder&, const WebCore::UnknownCredentialOptions&);
    static std::optional<WebCore::UnknownCredentialOptions> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::AllAcceptedCredentialsOptions> {
    static void encode(Encoder&, const WebCore::AllAcceptedCredentialsOptions&);
    static std::optional<WebCore::AllAcceptedCredentialsOptions> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::CurrentUserDetailsOptions> {
    static void encode(Encoder&, const WebCore::CurrentUserDetailsOptions&);
    static std::optional<WebCore::CurrentUserDetailsOptions> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::AuthenticatorSelectionCriteria> {
    static void encode(Encoder&, const WebCore::AuthenticatorSelectionCriteria&);
    static std::optional<WebCore::AuthenticatorSelectionCriteria> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::PublicKeyCredentialEntity> {
    static void encode(Encoder&, const WebCore::PublicKeyCredentialEntity&);
    static std::optional<WebCore::PublicKeyCredentialEntity> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::PublicKeyCredentialRpEntity> {
    static void encode(Encoder&, const WebCore::PublicKeyCredentialRpEntity&);
    static std::optional<WebCore::PublicKeyCredentialRpEntity> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::PublicKeyCredentialUserEntity> {
    static void encode(Encoder&, const WebCore::PublicKeyCredentialUserEntity&);
    static std::optional<WebCore::PublicKeyCredentialUserEntity> decode(Decoder&);
};
#endif

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::PublicKeyCredentialDescriptor> {
    static void encode(Encoder&, const WebCore::PublicKeyCredentialDescriptor&);
    static std::optional<WebCore::PublicKeyCredentialDescriptor> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::PublicKeyCredentialCreationOptions> {
    static void encode(Encoder&, const WebCore::PublicKeyCredentialCreationOptions&);
    static std::optional<WebCore::PublicKeyCredentialCreationOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PublicKeyCredentialRequestOptions> {
    static void encode(Encoder&, const WebCore::PublicKeyCredentialRequestOptions&);
    static std::optional<WebCore::PublicKeyCredentialRequestOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RegistrableDomain> {
    static void encode(Encoder&, const WebCore::RegistrableDomain&);
    static std::optional<WebCore::RegistrableDomain> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Site> {
    static void encode(Encoder&, const WebCore::Site&);
    static std::optional<WebCore::Site> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::AudioConfiguration> {
    static void encode(Encoder&, const WebCore::AudioConfiguration&);
    static std::optional<WebCore::AudioConfiguration> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Cookie> {
    static void encode(Encoder&, const WebCore::Cookie&);
    static std::optional<WebCore::Cookie> decode(Decoder&);
};

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::VideoFrameMetadata> {
    static void encode(Encoder&, const WebCore::VideoFrameMetadata&);
    static std::optional<WebCore::VideoFrameMetadata> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::NavigationPreloadState> {
    static void encode(Encoder&, const WebCore::NavigationPreloadState&);
    static std::optional<WebCore::NavigationPreloadState> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PlatformDynamicRangeLimit> {
    static void encode(Encoder&, const WebCore::PlatformDynamicRangeLimit&);
    static void encode(StreamConnectionEncoder&, const WebCore::PlatformDynamicRangeLimit&);
    static std::optional<WebCore::PlatformDynamicRangeLimit> decode(Decoder&);
};

#if ENABLE(CONTENT_FILTERING)
template<> struct ArgumentCoder<WebCore::MockContentFilterSettings> {
    static void encode(Encoder&, const WebCore::MockContentFilterSettings&);
    static std::optional<WebCore::MockContentFilterSettings> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::LoginStatus> {
    static void encode(Encoder&, const WebCore::LoginStatus&);
    static std::optional<WebCore::LoginStatus> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ExceptionDetails> {
    static void encode(Encoder&, const WebCore::ExceptionDetails&);
    static std::optional<WebCore::ExceptionDetails> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatBoxExtent> {
    static void encode(Encoder&, const WebCore::FloatBoxExtent&);
    static void encode(StreamConnectionEncoder&, const WebCore::FloatBoxExtent&);
    static std::optional<WebCore::FloatBoxExtent> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RectEdges<bool>> {
    static void encode(Encoder&, const WebCore::RectEdges<bool>&);
    static std::optional<WebCore::RectEdges<bool>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RectEdges<WebCore::Color>> {
    static void encode(Encoder&, const WebCore::RectEdges<WebCore::Color>&);
    static std::optional<WebCore::RectEdges<WebCore::Color>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RectEdges<WebCore::RubberBandingBehavior>> {
    static void encode(Encoder&, const WebCore::RectEdges<WebCore::RubberBandingBehavior>&);
    static std::optional<WebCore::RectEdges<WebCore::RubberBandingBehavior>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Path> {
    static void encode(Encoder&, const WebCore::Path&);
    static void encode(StreamConnectionEncoder&, const WebCore::Path&);
    static std::optional<WebCore::Path> decode(Decoder&);
};

#if ENABLE(META_VIEWPORT)
template<> struct ArgumentCoder<WebCore::ViewportArguments> {
    static void encode(Encoder&, const WebCore::ViewportArguments&);
    static std::optional<WebCore::ViewportArguments> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::HTTPHeaderMap> {
    static void encode(Encoder&, const WebCore::HTTPHeaderMap&);
    static std::optional<WebCore::HTTPHeaderMap> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ElementContext> {
    static void encode(Encoder&, const WebCore::ElementContext&);
    static std::optional<WebCore::ElementContext> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ElementAnimationContext> {
    static void encode(Encoder&, const WebCore::ElementAnimationContext&);
    static std::optional<WebCore::ElementAnimationContext> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SystemPreviewInfo> {
    static void encode(Encoder&, const WebCore::SystemPreviewInfo&);
    static std::optional<WebCore::SystemPreviewInfo> decode(Decoder&);
};

#if USE(SOUP)
template<> struct ArgumentCoder<WebCore::ResourceRequestPlatformData> {
    static void encode(Encoder&, const WebCore::ResourceRequestPlatformData&);
    static std::optional<WebCore::ResourceRequestPlatformData> decode(Decoder&);
};
#endif

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::ResourceRequest> {
    static void encode(Encoder&, const WebCore::ResourceRequest&);
    static std::optional<WebCore::ResourceRequest> decode(Decoder&);
};
#endif

#if USE(CURL)
template<> struct ArgumentCoder<WebCore::ResourceRequest> {
    static void encode(Encoder&, const WebCore::ResourceRequest&);
    static std::optional<WebCore::ResourceRequest> decode(Decoder&);
};
#endif

#if !USE(CURL) && !PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::ResourceRequest> {
    static void encode(Encoder&, const WebCore::ResourceRequest&);
    static std::optional<WebCore::ResourceRequest> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::ResourceError> {
    static void encode(Encoder&, const WebCore::ResourceError&);
    static std::optional<WebCore::ResourceError> decode(Decoder&);
};

#if (!(USE(CG))) && (!(USE(SKIA)))
template<> struct ArgumentCoder<WebCore::PlatformColorSpace> {
    static void encode(Encoder&, const WebCore::PlatformColorSpace&);
    static void encode(StreamConnectionEncoder&, const WebCore::PlatformColorSpace&);
    static std::optional<WebCore::PlatformColorSpace> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::DestinationColorSpace> {
    static void encode(Encoder&, const WebCore::DestinationColorSpace&);
    static void encode(StreamConnectionEncoder&, const WebCore::DestinationColorSpace&);
    static std::optional<WebCore::DestinationColorSpace> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::WindowFeatures> {
    static void encode(Encoder&, const WebCore::WindowFeatures&);
    static std::optional<WebCore::WindowFeatures> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CompositionUnderline> {
    static void encode(Encoder&, const WebCore::CompositionUnderline&);
    static std::optional<WebCore::CompositionUnderline> decode(Decoder&);
};

#if PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> struct ArgumentCoder<WebCore::GraphicsContextGLExternalImageSourceIOSurfaceHandle> {
    static void encode(Encoder&, WebCore::GraphicsContextGLExternalImageSourceIOSurfaceHandle&&);
    static std::optional<WebCore::GraphicsContextGLExternalImageSourceIOSurfaceHandle> decode(Decoder&);
};
#endif

#if PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> struct ArgumentCoder<WebCore::GraphicsContextGLExternalImageSourceMTLSharedTextureHandle> {
    static void encode(Encoder&, WebCore::GraphicsContextGLExternalImageSourceMTLSharedTextureHandle&&);
    static std::optional<WebCore::GraphicsContextGLExternalImageSourceMTLSharedTextureHandle> decode(Decoder&);
};
#endif

#if ENABLE(ATTACHMENT_ELEMENT)
template<> struct ArgumentCoder<WebCore::SerializedAttachmentData> {
    static void encode(Encoder&, const WebCore::SerializedAttachmentData&);
    static std::optional<WebCore::SerializedAttachmentData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::FileChooserSettings> {
    static void encode(Encoder&, const WebCore::FileChooserSettings&);
    static std::optional<WebCore::FileChooserSettings> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::GrammarDetail> {
    static void encode(Encoder&, const WebCore::GrammarDetail&);
    static std::optional<WebCore::GrammarDetail> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextCheckingResult> {
    static void encode(Encoder&, const WebCore::TextCheckingResult&);
    static std::optional<WebCore::TextCheckingResult> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextCheckingRequestData> {
    static void encode(Encoder&, const WebCore::TextCheckingRequestData&);
    static std::optional<WebCore::TextCheckingRequestData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LayoutRect> {
    static void encode(Encoder&, const WebCore::LayoutRect&);
    static std::optional<WebCore::LayoutRect> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ScreenDataOverrides> {
    static void encode(Encoder&, const WebCore::ScreenDataOverrides&);
    static std::optional<WebCore::ScreenDataOverrides> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BlobPart> {
    static void encode(Encoder&, const WebCore::BlobPart&);
    static std::optional<WebCore::BlobPart> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PackedColor::RGBA> {
    static void encode(Encoder&, const WebCore::PackedColor::RGBA&);
    static void encode(StreamConnectionEncoder&, const WebCore::PackedColor::RGBA&);
    static std::optional<WebCore::PackedColor::RGBA> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::OutOfLineColorDataForIPC> {
    static void encode(Encoder&, const WebCore::OutOfLineColorDataForIPC&);
    static void encode(StreamConnectionEncoder&, const WebCore::OutOfLineColorDataForIPC&);
    static std::optional<WebCore::OutOfLineColorDataForIPC> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ColorDataForIPC> {
    static void encode(Encoder&, const WebCore::ColorDataForIPC&);
    static void encode(StreamConnectionEncoder&, const WebCore::ColorDataForIPC&);
    static std::optional<WebCore::ColorDataForIPC> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Color> {
    static void encode(Encoder&, const WebCore::Color&);
    static void encode(StreamConnectionEncoder&, const WebCore::Color&);
    static std::optional<WebCore::Color> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MediaCapabilitiesInfo> {
    static void encode(Encoder&, const WebCore::MediaCapabilitiesInfo&);
    static std::optional<WebCore::MediaCapabilitiesInfo> decode(Decoder&);
};

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MediaStreamRequest> {
    static void encode(Encoder&, const WebCore::MediaStreamRequest&);
    static std::optional<WebCore::MediaStreamRequest> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MediaTrackConstraintSetMap> {
    static void encode(Encoder&, const WebCore::MediaTrackConstraintSetMap&);
    static std::optional<WebCore::MediaTrackConstraintSetMap> decode(Decoder&);
};
#endif

#if ! ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MediaStreamRequest> {
    static void encode(Encoder&, const WebCore::MediaStreamRequest&);
    static std::optional<WebCore::MediaStreamRequest> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::MediaCapabilitiesDecodingInfo> {
    static void encode(Encoder&, const WebCore::MediaCapabilitiesDecodingInfo&);
    static std::optional<WebCore::MediaCapabilitiesDecodingInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MediaCapabilitiesEncodingInfo> {
    static void encode(Encoder&, const WebCore::MediaCapabilitiesEncodingInfo&);
    static std::optional<WebCore::MediaCapabilitiesEncodingInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FormDataElement> {
    static void encode(Encoder&, const WebCore::FormDataElement&);
    static std::optional<WebCore::FormDataElement> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NetworkTransactionInformation> {
    static void encode(Encoder&, const WebCore::NetworkTransactionInformation&);
    static std::optional<WebCore::NetworkTransactionInformation> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ContentType> {
    static void encode(Encoder&, const WebCore::ContentType&);
    static std::optional<WebCore::ContentType> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DateTimeChooserParameters> {
    static void encode(Encoder&, const WebCore::DateTimeChooserParameters&);
    static std::optional<WebCore::DateTimeChooserParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ScreenData> {
    static void encode(Encoder&, const WebCore::ScreenData&);
    static std::optional<WebCore::ScreenData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ScreenProperties> {
    static void encode(Encoder&, const WebCore::ScreenProperties&);
    static std::optional<WebCore::ScreenProperties> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PlatformTimeRanges> {
    static void encode(Encoder&, const WebCore::PlatformTimeRanges&);
    static std::optional<WebCore::PlatformTimeRanges> decode(Decoder&);
};

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::VideoPlaybackQualityMetrics> {
    static void encode(Encoder&, const WebCore::VideoPlaybackQualityMetrics&);
    static std::optional<WebCore::VideoPlaybackQualityMetrics> decode(Decoder&);
};
#endif

#if PLATFORM(IOS_FAMILY)
template<> struct ArgumentCoder<WebCore::SelectionGeometry> {
    static void encode(Encoder&, const WebCore::SelectionGeometry&);
    static std::optional<WebCore::SelectionGeometry> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::DataListSuggestion> {
    static void encode(Encoder&, const WebCore::DataListSuggestion&);
    static std::optional<WebCore::DataListSuggestion> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DataListSuggestionInformation> {
    static void encode(Encoder&, const WebCore::DataListSuggestionInformation&);
    static std::optional<WebCore::DataListSuggestionInformation> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ClientOrigin> {
    static void encode(Encoder&, const WebCore::ClientOrigin&);
    static std::optional<WebCore::ClientOrigin> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ImageBufferFormat> {
    static void encode(Encoder&, const WebCore::ImageBufferFormat&);
    static void encode(StreamConnectionEncoder&, const WebCore::ImageBufferFormat&);
    static std::optional<WebCore::ImageBufferFormat> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PixelBufferFormat> {
    static void encode(Encoder&, const WebCore::PixelBufferFormat&);
    static void encode(StreamConnectionEncoder&, const WebCore::PixelBufferFormat&);
    static std::optional<WebCore::PixelBufferFormat> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextIndicator> {
    static void encode(Encoder&, const WebCore::TextIndicator&);
    static std::optional<Ref<WebCore::TextIndicator>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CertificateInfo> {
    static void encode(Encoder&, const WebCore::CertificateInfo&);
    static std::optional<WebCore::CertificateInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PasteboardCustomData> {
    static void encode(Encoder&, const WebCore::PasteboardCustomData&);
    static std::optional<WebCore::PasteboardCustomData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SharedMemoryHandle> {
    static void encode(Encoder&, WebCore::SharedMemoryHandle&&);
    static std::optional<WebCore::SharedMemoryHandle> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DatabaseDetails> {
    static void encode(Encoder&, const WebCore::DatabaseDetails&);
    static std::optional<WebCore::DatabaseDetails> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextIndicatorData> {
    static void encode(Encoder&, const WebCore::TextIndicatorData&);
    static std::optional<WebCore::TextIndicatorData> decode(Decoder&);
};

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MediaConstraints> {
    static void encode(Encoder&, const WebCore::MediaConstraints&);
    static std::optional<WebCore::MediaConstraints> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::PromisedAttachmentInfo> {
    static void encode(Encoder&, const WebCore::PromisedAttachmentInfo&);
    static std::optional<WebCore::PromisedAttachmentInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RecentSearch> {
    static void encode(Encoder&, const WebCore::RecentSearch&);
    static std::optional<WebCore::RecentSearch> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::EventTrackingRegions> {
    static void encode(Encoder&, const WebCore::EventTrackingRegions&);
    static std::optional<WebCore::EventTrackingRegions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextManipulationItem> {
    static void encode(Encoder&, const WebCore::TextManipulationItem&);
    static std::optional<WebCore::TextManipulationItem> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextManipulationToken> {
    static void encode(Encoder&, const WebCore::TextManipulationToken&);
    static std::optional<WebCore::TextManipulationToken> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextManipulationTokenInfo> {
    static void encode(Encoder&, const WebCore::TextManipulationTokenInfo&);
    static std::optional<WebCore::TextManipulationTokenInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::VelocityData> {
    static void encode(Encoder&, const WebCore::VelocityData&);
    static std::optional<WebCore::VelocityData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MimeClassInfo> {
    static void encode(Encoder&, const WebCore::MimeClassInfo&);
    static std::optional<WebCore::MimeClassInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::AuthenticationChallenge> {
    static void encode(Encoder&, const WebCore::AuthenticationChallenge&);
    static std::optional<WebCore::AuthenticationChallenge> decode(Decoder&);
};

#if ENABLE(DRAG_SUPPORT)
template<> struct ArgumentCoder<WebCore::DragData> {
    static void encode(Encoder&, const WebCore::DragData&);
    static std::optional<WebCore::DragData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::DictationAlternative> {
    static void encode(Encoder&, const WebCore::DictationAlternative&);
    static std::optional<WebCore::DictationAlternative> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::UserStyleSheet> {
    static void encode(Encoder&, const WebCore::UserStyleSheet&);
    static std::optional<WebCore::UserStyleSheet> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ScrollableAreaParameters> {
    static void encode(Encoder&, const WebCore::ScrollableAreaParameters&);
    static std::optional<WebCore::ScrollableAreaParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RequestedKeyboardScrollData> {
    static void encode(Encoder&, const WebCore::RequestedKeyboardScrollData&);
    static std::optional<WebCore::RequestedKeyboardScrollData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ScrollUpdate> {
    static void encode(Encoder&, const WebCore::ScrollUpdate&);
    static std::optional<WebCore::ScrollUpdate> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::AbsolutePositionConstraints> {
    static void encode(Encoder&, const WebCore::AbsolutePositionConstraints&);
    static std::optional<WebCore::AbsolutePositionConstraints> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::KeyboardScroll> {
    static void encode(Encoder&, const WebCore::KeyboardScroll&);
    static std::optional<WebCore::KeyboardScroll> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NotificationResources> {
    static void encode(Encoder&, const WebCore::NotificationResources&);
    static std::optional<Ref<WebCore::NotificationResources>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IdentityTransformOperation> {
    static void encode(Encoder&, const WebCore::IdentityTransformOperation&);
    static std::optional<Ref<WebCore::IdentityTransformOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TranslateTransformOperation> {
    static void encode(Encoder&, const WebCore::TranslateTransformOperation&);
    static std::optional<Ref<WebCore::TranslateTransformOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RotateTransformOperation> {
    static void encode(Encoder&, const WebCore::RotateTransformOperation&);
    static std::optional<Ref<WebCore::RotateTransformOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ScaleTransformOperation> {
    static void encode(Encoder&, const WebCore::ScaleTransformOperation&);
    static std::optional<Ref<WebCore::ScaleTransformOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SkewTransformOperation> {
    static void encode(Encoder&, const WebCore::SkewTransformOperation&);
    static std::optional<Ref<WebCore::SkewTransformOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PerspectiveTransformOperation> {
    static void encode(Encoder&, const WebCore::PerspectiveTransformOperation&);
    static std::optional<Ref<WebCore::PerspectiveTransformOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MatrixTransformOperation> {
    static void encode(Encoder&, const WebCore::MatrixTransformOperation&);
    static std::optional<Ref<WebCore::MatrixTransformOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Matrix3DTransformOperation> {
    static void encode(Encoder&, const WebCore::Matrix3DTransformOperation&);
    static std::optional<Ref<WebCore::Matrix3DTransformOperation>> decode(Decoder&);
};

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<AudioStreamBasicDescription> {
    static void encode(Encoder&, const AudioStreamBasicDescription&);
    static std::optional<AudioStreamBasicDescription> decode(Decoder&);
};
#endif

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::CAAudioStreamDescription> {
    static void encode(Encoder&, const WebCore::CAAudioStreamDescription&);
    static std::optional<WebCore::CAAudioStreamDescription> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::TransformOperations> {
    static void encode(Encoder&, const WebCore::TransformOperations&);
    static std::optional<WebCore::TransformOperations> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Gradient> {
    static void encode(Encoder&, const WebCore::Gradient&);
    static void encode(StreamConnectionEncoder&, const WebCore::Gradient&);
    static std::optional<Ref<WebCore::Gradient>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PatternParameters> {
    static void encode(Encoder&, const WebCore::PatternParameters&);
    static void encode(StreamConnectionEncoder&, const WebCore::PatternParameters&);
    static std::optional<WebCore::PatternParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ThreadSafeDataBufferImpl> {
    static void encode(Encoder&, const WebCore::ThreadSafeDataBufferImpl&);
    static std::optional<Ref<WebCore::ThreadSafeDataBufferImpl>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ThreadSafeDataBuffer> {
    static void encode(Encoder&, const WebCore::ThreadSafeDataBuffer&);
    static std::optional<WebCore::ThreadSafeDataBuffer> decode(Decoder&);
};

#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> struct ArgumentCoder<WebCore::GraphicsContextGLAttributes> {
    static void encode(Encoder&, const WebCore::GraphicsContextGLAttributes&);
    static std::optional<WebCore::GraphicsContextGLAttributes> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::TimingFunction> {
    static void encode(Encoder&, const WebCore::TimingFunction&);
    static std::optional<Ref<WebCore::TimingFunction>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TransformOperation> {
    static void encode(Encoder&, const WebCore::TransformOperation&);
    static std::optional<Ref<WebCore::TransformOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LengthPoint> {
    static void encode(Encoder&, const WebCore::LengthPoint&);
    static std::optional<WebCore::LengthPoint> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LengthSize> {
    static void encode(Encoder&, const WebCore::LengthSize&);
    static std::optional<WebCore::LengthSize> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SVGPathByteStream> {
    static void encode(Encoder&, const WebCore::SVGPathByteStream&);
    static std::optional<WebCore::SVGPathByteStream> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PixelBuffer> {
    static void encode(Encoder&, const WebCore::PixelBuffer&);
    static void encode(StreamConnectionEncoder&, const WebCore::PixelBuffer&);
    static std::optional<Ref<WebCore::PixelBuffer>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MotionPathData> {
    static void encode(Encoder&, const WebCore::MotionPathData&);
    static std::optional<WebCore::MotionPathData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TransformOperationData> {
    static void encode(Encoder&, const WebCore::TransformOperationData&);
    static std::optional<WebCore::TransformOperationData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ReferencePathOperation> {
    static void encode(Encoder&, const WebCore::ReferencePathOperation&);
    static std::optional<Ref<WebCore::ReferencePathOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ShapePathOperation> {
    static void encode(Encoder&, const WebCore::ShapePathOperation&);
    static std::optional<Ref<WebCore::ShapePathOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BoxPathOperation> {
    static void encode(Encoder&, const WebCore::BoxPathOperation&);
    static std::optional<Ref<WebCore::BoxPathOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RayPathOperation> {
    static void encode(Encoder&, const WebCore::RayPathOperation&);
    static std::optional<Ref<WebCore::RayPathOperation>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PathOperation> {
    static void encode(Encoder&, const WebCore::PathOperation&);
    static std::optional<Ref<WebCore::PathOperation>> decode(Decoder&);
};

#if ENABLE(ENCRYPTED_MEDIA)
template<> struct ArgumentCoder<WebCore::CDMKeySystemConfiguration> {
    static void encode(Encoder&, const WebCore::CDMKeySystemConfiguration&);
    static std::optional<WebCore::CDMKeySystemConfiguration> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::MediaConfiguration> {
    static void encode(Encoder&, const WebCore::MediaConfiguration&);
    static std::optional<WebCore::MediaConfiguration> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MediaEncodingConfiguration> {
    static void encode(Encoder&, const WebCore::MediaEncodingConfiguration&);
    static std::optional<WebCore::MediaEncodingConfiguration> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MediaDecodingConfiguration> {
    static void encode(Encoder&, const WebCore::MediaDecodingConfiguration&);
    static std::optional<WebCore::MediaDecodingConfiguration> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ResourceResponseBase> {
    static void encode(Encoder&, const WebCore::ResourceResponseBase&);
    static std::optional<WebCore::ResourceResponseBase> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ResourceResponse> {
    static void encode(Encoder&, const WebCore::ResourceResponse&);
    static std::optional<WebCore::ResourceResponse> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ResourceResponseData> {
    static void encode(Encoder&, const WebCore::ResourceResponseData&);
    static std::optional<WebCore::ResourceResponseData> decode(Decoder&);
};

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::ArchiveResource> {
    static void encode(Encoder&, const WebCore::ArchiveResource&);
    static std::optional<Ref<WebCore::ArchiveResource>> decode(Decoder&);
};
#endif

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::LegacyWebArchive> {
    static void encode(Encoder&, const WebCore::LegacyWebArchive&);
    static std::optional<Ref<WebCore::LegacyWebArchive>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::FetchOptions> {
    static void encode(Encoder&, const WebCore::FetchOptions&);
    static std::optional<WebCore::FetchOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ControlStyle> {
    static void encode(Encoder&, const WebCore::ControlStyle&);
    static void encode(StreamConnectionEncoder&, const WebCore::ControlStyle&);
    static std::optional<WebCore::ControlStyle> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ControlPart> {
    static void encode(Encoder&, const WebCore::ControlPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::ControlPart&);
    static std::optional<Ref<WebCore::ControlPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ButtonPart> {
    static void encode(Encoder&, const WebCore::ButtonPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::ButtonPart&);
    static std::optional<Ref<WebCore::ButtonPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::InnerSpinButtonPart> {
    static void encode(Encoder&, const WebCore::InnerSpinButtonPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::InnerSpinButtonPart&);
    static std::optional<Ref<WebCore::InnerSpinButtonPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MenuListButtonPart> {
    static void encode(Encoder&, const WebCore::MenuListButtonPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::MenuListButtonPart&);
    static std::optional<Ref<WebCore::MenuListButtonPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MenuListPart> {
    static void encode(Encoder&, const WebCore::MenuListPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::MenuListPart&);
    static std::optional<Ref<WebCore::MenuListPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SearchFieldPart> {
    static void encode(Encoder&, const WebCore::SearchFieldPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::SearchFieldPart&);
    static std::optional<Ref<WebCore::SearchFieldPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SliderThumbPart> {
    static void encode(Encoder&, const WebCore::SliderThumbPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::SliderThumbPart&);
    static std::optional<Ref<WebCore::SliderThumbPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SearchFieldResultsPart> {
    static void encode(Encoder&, const WebCore::SearchFieldResultsPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::SearchFieldResultsPart&);
    static std::optional<Ref<WebCore::SearchFieldResultsPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SearchFieldCancelButtonPart> {
    static void encode(Encoder&, const WebCore::SearchFieldCancelButtonPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::SearchFieldCancelButtonPart&);
    static std::optional<Ref<WebCore::SearchFieldCancelButtonPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextAreaPart> {
    static void encode(Encoder&, const WebCore::TextAreaPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::TextAreaPart&);
    static std::optional<Ref<WebCore::TextAreaPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextFieldPart> {
    static void encode(Encoder&, const WebCore::TextFieldPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::TextFieldPart&);
    static std::optional<Ref<WebCore::TextFieldPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ToggleButtonPart> {
    static void encode(Encoder&, const WebCore::ToggleButtonPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::ToggleButtonPart&);
    static std::optional<Ref<WebCore::ToggleButtonPart>> decode(Decoder&);
};

#if ENABLE(SERVICE_CONTROLS)
template<> struct ArgumentCoder<WebCore::ImageControlsButtonPart> {
    static void encode(Encoder&, const WebCore::ImageControlsButtonPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::ImageControlsButtonPart&);
    static std::optional<Ref<WebCore::ImageControlsButtonPart>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::ColorWellPart> {
    static void encode(Encoder&, const WebCore::ColorWellPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::ColorWellPart&);
    static std::optional<Ref<WebCore::ColorWellPart>> decode(Decoder&);
};

#if ENABLE(APPLE_PAY)
template<> struct ArgumentCoder<WebCore::ApplePayButtonPart> {
    static void encode(Encoder&, const WebCore::ApplePayButtonPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::ApplePayButtonPart&);
    static std::optional<Ref<WebCore::ApplePayButtonPart>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::MeterPart> {
    static void encode(Encoder&, const WebCore::MeterPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::MeterPart&);
    static std::optional<Ref<WebCore::MeterPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ProgressBarPart> {
    static void encode(Encoder&, const WebCore::ProgressBarPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::ProgressBarPart&);
    static std::optional<Ref<WebCore::ProgressBarPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SliderTrackPart> {
    static void encode(Encoder&, const WebCore::SliderTrackPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::SliderTrackPart&);
    static std::optional<Ref<WebCore::SliderTrackPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SwitchThumbPart> {
    static void encode(Encoder&, const WebCore::SwitchThumbPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::SwitchThumbPart&);
    static std::optional<Ref<WebCore::SwitchThumbPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SwitchTrackPart> {
    static void encode(Encoder&, const WebCore::SwitchTrackPart&);
    static void encode(StreamConnectionEncoder&, const WebCore::SwitchTrackPart&);
    static std::optional<Ref<WebCore::SwitchTrackPart>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DistantLightSource> {
    static void encode(Encoder&, const WebCore::DistantLightSource&);
    static void encode(StreamConnectionEncoder&, const WebCore::DistantLightSource&);
    static std::optional<Ref<WebCore::DistantLightSource>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PointLightSource> {
    static void encode(Encoder&, const WebCore::PointLightSource&);
    static void encode(StreamConnectionEncoder&, const WebCore::PointLightSource&);
    static std::optional<Ref<WebCore::PointLightSource>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SpotLightSource> {
    static void encode(Encoder&, const WebCore::SpotLightSource&);
    static void encode(StreamConnectionEncoder&, const WebCore::SpotLightSource&);
    static std::optional<Ref<WebCore::SpotLightSource>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEBlend> {
    static void encode(Encoder&, const WebCore::FEBlend&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEBlend&);
    static std::optional<Ref<WebCore::FEBlend>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEColorMatrix> {
    static void encode(Encoder&, const WebCore::FEColorMatrix&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEColorMatrix&);
    static std::optional<Ref<WebCore::FEColorMatrix>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ComponentTransferFunction> {
    static void encode(Encoder&, const WebCore::ComponentTransferFunction&);
    static void encode(StreamConnectionEncoder&, const WebCore::ComponentTransferFunction&);
    static std::optional<WebCore::ComponentTransferFunction> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEComponentTransfer> {
    static void encode(Encoder&, const WebCore::FEComponentTransfer&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEComponentTransfer&);
    static std::optional<Ref<WebCore::FEComponentTransfer>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEComposite> {
    static void encode(Encoder&, const WebCore::FEComposite&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEComposite&);
    static std::optional<Ref<WebCore::FEComposite>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEConvolveMatrix> {
    static void encode(Encoder&, const WebCore::FEConvolveMatrix&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEConvolveMatrix&);
    static std::optional<Ref<WebCore::FEConvolveMatrix>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEDiffuseLighting> {
    static void encode(Encoder&, const WebCore::FEDiffuseLighting&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEDiffuseLighting&);
    static std::optional<Ref<WebCore::FEDiffuseLighting>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEDisplacementMap> {
    static void encode(Encoder&, const WebCore::FEDisplacementMap&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEDisplacementMap&);
    static std::optional<Ref<WebCore::FEDisplacementMap>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEDropShadow> {
    static void encode(Encoder&, const WebCore::FEDropShadow&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEDropShadow&);
    static std::optional<Ref<WebCore::FEDropShadow>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEFlood> {
    static void encode(Encoder&, const WebCore::FEFlood&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEFlood&);
    static std::optional<Ref<WebCore::FEFlood>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEGaussianBlur> {
    static void encode(Encoder&, const WebCore::FEGaussianBlur&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEGaussianBlur&);
    static std::optional<Ref<WebCore::FEGaussianBlur>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEImage> {
    static void encode(Encoder&, const WebCore::FEImage&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEImage&);
    static std::optional<Ref<WebCore::FEImage>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEMerge> {
    static void encode(Encoder&, const WebCore::FEMerge&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEMerge&);
    static std::optional<Ref<WebCore::FEMerge>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEMorphology> {
    static void encode(Encoder&, const WebCore::FEMorphology&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEMorphology&);
    static std::optional<Ref<WebCore::FEMorphology>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FEOffset> {
    static void encode(Encoder&, const WebCore::FEOffset&);
    static void encode(StreamConnectionEncoder&, const WebCore::FEOffset&);
    static std::optional<Ref<WebCore::FEOffset>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FETile> {
    static void encode(Encoder&, const WebCore::FETile&);
    static void encode(StreamConnectionEncoder&, const WebCore::FETile&);
    static std::optional<Ref<WebCore::FETile>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FESpecularLighting> {
    static void encode(Encoder&, const WebCore::FESpecularLighting&);
    static void encode(StreamConnectionEncoder&, const WebCore::FESpecularLighting&);
    static std::optional<Ref<WebCore::FESpecularLighting>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FETurbulence> {
    static void encode(Encoder&, const WebCore::FETurbulence&);
    static void encode(StreamConnectionEncoder&, const WebCore::FETurbulence&);
    static std::optional<Ref<WebCore::FETurbulence>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SourceAlpha> {
    static void encode(Encoder&, const WebCore::SourceAlpha&);
    static void encode(StreamConnectionEncoder&, const WebCore::SourceAlpha&);
    static std::optional<Ref<WebCore::SourceAlpha>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SourceGraphic> {
    static void encode(Encoder&, const WebCore::SourceGraphic&);
    static void encode(StreamConnectionEncoder&, const WebCore::SourceGraphic&);
    static std::optional<Ref<WebCore::SourceGraphic>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FilterEffectGeometry> {
    static void encode(Encoder&, const WebCore::FilterEffectGeometry&);
    static void encode(StreamConnectionEncoder&, const WebCore::FilterEffectGeometry&);
    static std::optional<WebCore::FilterEffectGeometry> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SVGFilterExpressionTerm> {
    static void encode(Encoder&, const WebCore::SVGFilterExpressionTerm&);
    static void encode(StreamConnectionEncoder&, const WebCore::SVGFilterExpressionTerm&);
    static std::optional<WebCore::SVGFilterExpressionTerm> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SVGPreserveAspectRatioValue> {
    static void encode(Encoder&, const WebCore::SVGPreserveAspectRatioValue&);
    static void encode(StreamConnectionEncoder&, const WebCore::SVGPreserveAspectRatioValue&);
    static std::optional<WebCore::SVGPreserveAspectRatioValue> decode(Decoder&);
};

#if ENABLE(GAMEPAD)
template<> struct ArgumentCoder<WebCore::GamepadEffectParameters> {
    static void encode(Encoder&, const WebCore::GamepadEffectParameters&);
    static std::optional<WebCore::GamepadEffectParameters> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::StorageEstimate> {
    static void encode(Encoder&, const WebCore::StorageEstimate&);
    static std::optional<WebCore::StorageEstimate> decode(Decoder&);
};

template<> struct ArgumentCoder<PAL::SessionID> {
    static void encode(Encoder&, const PAL::SessionID&);
    static std::optional<PAL::SessionID> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::RunJavaScriptParameters> {
    static void encode(Encoder&, const WebKit::RunJavaScriptParameters&);
    static std::optional<WebKit::RunJavaScriptParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextList> {
    static void encode(Encoder&, const WebCore::TextList&);
    static std::optional<WebCore::TextList> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontAttributes> {
    static void encode(Encoder&, const WebCore::FontAttributes&);
    static std::optional<WebCore::FontAttributes> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CrossOriginEmbedderPolicy> {
    static void encode(Encoder&, const WebCore::CrossOriginEmbedderPolicy&);
    static std::optional<WebCore::CrossOriginEmbedderPolicy> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SameSiteInfo> {
    static void encode(Encoder&, const WebCore::SameSiteInfo&);
    static std::optional<WebCore::SameSiteInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SecurityOrigin> {
    static void encode(Encoder&, const WebCore::SecurityOrigin&);
    static std::optional<Ref<WebCore::SecurityOrigin>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CookieRequestHeaderFieldProxy> {
    static void encode(Encoder&, const WebCore::CookieRequestHeaderFieldProxy&);
    static std::optional<WebCore::CookieRequestHeaderFieldProxy> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FormData> {
    static void encode(Encoder&, const WebCore::FormData&);
    static std::optional<Ref<WebCore::FormData>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RequestedScrollData> {
    static void encode(Encoder&, const WebCore::RequestedScrollData&);
    static std::optional<WebCore::RequestedScrollData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatScrollSnapOffsetsInfo> {
    static void encode(Encoder&, const WebCore::FloatScrollSnapOffsetsInfo&);
    static std::optional<WebCore::FloatScrollSnapOffsetsInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatSnapOffset> {
    static void encode(Encoder&, const WebCore::FloatSnapOffset&);
    static std::optional<WebCore::FloatSnapOffset> decode(Decoder&);
};

#if ENABLE(ENCRYPTED_MEDIA)
template<> struct ArgumentCoder<WebCore::CDMMediaCapability> {
    static void encode(Encoder&, const WebCore::CDMMediaCapability&);
    static std::optional<WebCore::CDMMediaCapability> decode(Decoder&);
};
#endif

#if ENABLE(ENCRYPTED_MEDIA)
template<> struct ArgumentCoder<WebCore::CDMRestrictions> {
    static void encode(Encoder&, const WebCore::CDMRestrictions&);
    static std::optional<WebCore::CDMRestrictions> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::MediaSelectionOption> {
    static void encode(Encoder&, const WebCore::MediaSelectionOption&);
    static std::optional<WebCore::MediaSelectionOption> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BufferSource> {
    static void encode(Encoder&, const WebCore::BufferSource&);
    static std::optional<WebCore::BufferSource> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontShadow> {
    static void encode(Encoder&, const WebCore::FontShadow&);
    static std::optional<WebCore::FontShadow> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CompositionHighlight> {
    static void encode(Encoder&, const WebCore::CompositionHighlight&);
    static std::optional<WebCore::CompositionHighlight> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontChanges> {
    static void encode(Encoder&, const WebCore::FontChanges&);
    static std::optional<WebCore::FontChanges> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontAttributeChanges> {
    static void encode(Encoder&, const WebCore::FontAttributeChanges&);
    static std::optional<WebCore::FontAttributeChanges> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextManipulationControllerExclusionRule> {
    static void encode(Encoder&, const WebCore::TextManipulationControllerExclusionRule&);
    static std::optional<WebCore::TextManipulationControllerExclusionRule> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextManipulationControllerManipulationFailure> {
    static void encode(Encoder&, const WebCore::TextManipulationControllerManipulationFailure&);
    static std::optional<WebCore::TextManipulationControllerManipulationFailure> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextManipulationControllerManipulationResult> {
    static void encode(Encoder&, const WebCore::TextManipulationControllerManipulationResult&);
    static std::optional<WebCore::TextManipulationControllerManipulationResult> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BackgroundFetchInformation> {
    static void encode(Encoder&, const WebCore::BackgroundFetchInformation&);
    static std::optional<WebCore::BackgroundFetchInformation> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BackgroundFetchRequest> {
    static void encode(Encoder&, const WebCore::BackgroundFetchRequest&);
    static std::optional<WebCore::BackgroundFetchRequest> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BackgroundFetchRecordInformation> {
    static void encode(Encoder&, const WebCore::BackgroundFetchRecordInformation&);
    static std::optional<WebCore::BackgroundFetchRecordInformation> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::BackgroundFetchOptions> {
    static void encode(Encoder&, const WebCore::BackgroundFetchOptions&);
    static std::optional<WebCore::BackgroundFetchOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ImageResource> {
    static void encode(Encoder&, const WebCore::ImageResource&);
    static std::optional<WebCore::ImageResource> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FourCC> {
    static void encode(Encoder&, const WebCore::FourCC&);
    static std::optional<WebCore::FourCC> decode(Decoder&);
};

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::MediaEngineSupportParameters> {
    static void encode(Encoder&, const WebCore::MediaEngineSupportParameters&);
    static std::optional<WebCore::MediaEngineSupportParameters> decode(Decoder&);
};
#endif

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::SeekTarget> {
    static void encode(Encoder&, const WebCore::SeekTarget&);
    static std::optional<WebCore::SeekTarget> decode(Decoder&);
};
#endif

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::MediaPlayerLoadOptions> {
    static void encode(Encoder&, const WebCore::MediaPlayerLoadOptions&);
    static std::optional<WebCore::MediaPlayerLoadOptions> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::GeolocationPositionData> {
    static void encode(Encoder&, const WebCore::GeolocationPositionData&);
    static std::optional<WebCore::GeolocationPositionData> decode(Decoder&);
};

#if ENABLE(APP_HIGHLIGHTS)
template<> struct ArgumentCoder<WebCore::AppHighlight> {
    static void encode(Encoder&, const WebCore::AppHighlight&);
    static std::optional<WebCore::AppHighlight> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::MediaDeviceHashSalts> {
    static void encode(Encoder&, const WebCore::MediaDeviceHashSalts&);
    static std::optional<WebCore::MediaDeviceHashSalts> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SpeechRecognitionUpdate> {
    static void encode(Encoder&, const WebCore::SpeechRecognitionUpdate&);
    static std::optional<WebCore::SpeechRecognitionUpdate> decode(Decoder&);
};

#if USE(SYSTEM_PREVIEW)
template<> struct ArgumentCoder<WebCore::ARKitBadgeSystemImage> {
    static void encode(Encoder&, const WebCore::ARKitBadgeSystemImage&);
    static void encode(StreamConnectionEncoder&, const WebCore::ARKitBadgeSystemImage&);
    static std::optional<Ref<WebCore::ARKitBadgeSystemImage>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::AudioIOPosition> {
    static void encode(Encoder&, const WebCore::AudioIOPosition&);
    static std::optional<WebCore::AudioIOPosition> decode(Decoder&);
};

#if ENABLE(VIDEO) && USE(AVFOUNDATION)
template<> struct ArgumentCoder<WebCore::VideoFrameCV> {
    static void encode(Encoder&, const WebCore::VideoFrameCV&);
    static std::optional<Ref<WebCore::VideoFrameCV>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::GradientColorStop> {
    static void encode(Encoder&, const WebCore::GradientColorStop&);
    static void encode(StreamConnectionEncoder&, const WebCore::GradientColorStop&);
    static std::optional<WebCore::GradientColorStop> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::GradientColorStops> {
    static void encode(Encoder&, const WebCore::GradientColorStops&);
    static void encode(StreamConnectionEncoder&, const WebCore::GradientColorStops&);
    static std::optional<WebCore::GradientColorStops> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ImageBufferParameters> {
    static void encode(Encoder&, const WebCore::ImageBufferParameters&);
    static std::optional<WebCore::ImageBufferParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ProcessIdentity> {
    static void encode(Encoder&, WebCore::ProcessIdentity&&);
    static std::optional<WebCore::ProcessIdentity> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ColorInterpolationMethod> {
    static void encode(Encoder&, const WebCore::ColorInterpolationMethod&);
    static void encode(StreamConnectionEncoder&, const WebCore::ColorInterpolationMethod&);
    static std::optional<WebCore::ColorInterpolationMethod> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CompositeMode> {
    static void encode(Encoder&, const WebCore::CompositeMode&);
    static void encode(StreamConnectionEncoder&, const WebCore::CompositeMode&);
    static std::optional<WebCore::CompositeMode> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DocumentMarkerLineStyle> {
    static void encode(Encoder&, const WebCore::DocumentMarkerLineStyle&);
    static void encode(StreamConnectionEncoder&, const WebCore::DocumentMarkerLineStyle&);
    static std::optional<WebCore::DocumentMarkerLineStyle> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::GraphicsDropShadow> {
    static void encode(Encoder&, const WebCore::GraphicsDropShadow&);
    static void encode(StreamConnectionEncoder&, const WebCore::GraphicsDropShadow&);
    static std::optional<WebCore::GraphicsDropShadow> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::GraphicsGaussianBlur> {
    static void encode(Encoder&, const WebCore::GraphicsGaussianBlur&);
    static void encode(StreamConnectionEncoder&, const WebCore::GraphicsGaussianBlur&);
    static std::optional<WebCore::GraphicsGaussianBlur> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::GraphicsColorMatrix> {
    static void encode(Encoder&, const WebCore::GraphicsColorMatrix&);
    static void encode(StreamConnectionEncoder&, const WebCore::GraphicsColorMatrix&);
    static std::optional<WebCore::GraphicsColorMatrix> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PlatformMediaSessionRemoteCommandArgument> {
    static void encode(Encoder&, const WebCore::PlatformMediaSessionRemoteCommandArgument&);
    static std::optional<WebCore::PlatformMediaSessionRemoteCommandArgument> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SocketStreamError> {
    static void encode(Encoder&, const WebCore::SocketStreamError&);
    static std::optional<WebCore::SocketStreamError> decode(Decoder&);
};

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::GenericCueData> {
    static void encode(Encoder&, const WebCore::GenericCueData&);
    static void encode(StreamConnectionEncoder&, const WebCore::GenericCueData&);
    static std::optional<WebCore::GenericCueData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::ImageDecoderFrameInfo> {
    static void encode(Encoder&, const WebCore::ImageDecoderFrameInfo&);
    static void encode(StreamConnectionEncoder&, const WebCore::ImageDecoderFrameInfo&);
    static std::optional<WebCore::ImageDecoderFrameInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DisplayList::DrawDotsForDocumentMarker> {
    static void encode(Encoder&, const WebCore::DisplayList::DrawDotsForDocumentMarker&);
    static void encode(StreamConnectionEncoder&, const WebCore::DisplayList::DrawDotsForDocumentMarker&);
    static std::optional<WebCore::DisplayList::DrawDotsForDocumentMarker> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ImageOrientation> {
    static void encode(Encoder&, const WebCore::ImageOrientation&);
    static void encode(StreamConnectionEncoder&, const WebCore::ImageOrientation&);
    static std::optional<WebCore::ImageOrientation> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Headroom> {
    static void encode(Encoder&, const WebCore::Headroom&);
    static void encode(StreamConnectionEncoder&, const WebCore::Headroom&);
    static std::optional<WebCore::Headroom> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ImagePaintingOptions> {
    static void encode(Encoder&, const WebCore::ImagePaintingOptions&);
    static void encode(StreamConnectionEncoder&, const WebCore::ImagePaintingOptions&);
    static std::optional<WebCore::ImagePaintingOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatSegment> {
    static void encode(Encoder&, const WebCore::FloatSegment&);
    static void encode(StreamConnectionEncoder&, const WebCore::FloatSegment&);
    static std::optional<WebCore::FloatSegment> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CanvasActivityRecord> {
    static void encode(Encoder&, const WebCore::CanvasActivityRecord&);
    static std::optional<WebCore::CanvasActivityRecord> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PCM::AttributionSecondsUntilSendData> {
    static void encode(Encoder&, const WebCore::PCM::AttributionSecondsUntilSendData&);
    static std::optional<WebCore::PCM::AttributionSecondsUntilSendData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CrossOriginOpenerPolicy> {
    static void encode(Encoder&, const WebCore::CrossOriginOpenerPolicy&);
    static std::optional<WebCore::CrossOriginOpenerPolicy> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CustomHeaderFields> {
    static void encode(Encoder&, const WebCore::CustomHeaderFields&);
    static std::optional<WebCore::CustomHeaderFields> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::HTTPHeaderField> {
    static void encode(Encoder&, const WebCore::HTTPHeaderField&);
    static std::optional<WebCore::HTTPHeaderField> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NavigationRequester> {
    static void encode(Encoder&, const WebCore::NavigationRequester&);
    static std::optional<WebCore::NavigationRequester> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PolicyContainer> {
    static void encode(Encoder&, const WebCore::PolicyContainer&);
    static std::optional<WebCore::PolicyContainer> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SubstituteData> {
    static void encode(Encoder&, const WebCore::SubstituteData&);
    static std::optional<WebCore::SubstituteData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerClientData> {
    static void encode(Encoder&, const WebCore::ServiceWorkerClientData&);
    static std::optional<WebCore::ServiceWorkerClientData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerClientPendingMessage> {
    static void encode(Encoder&, const WebCore::ServiceWorkerClientPendingMessage&);
    static std::optional<WebCore::ServiceWorkerClientPendingMessage> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerClientQueryOptions> {
    static void encode(Encoder&, const WebCore::ServiceWorkerClientQueryOptions&);
    static std::optional<WebCore::ServiceWorkerClientQueryOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerData> {
    static void encode(Encoder&, const WebCore::ServiceWorkerData&);
    static std::optional<WebCore::ServiceWorkerData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerJobData> {
    static void encode(Encoder&, const WebCore::ServiceWorkerJobData&);
    static std::optional<WebCore::ServiceWorkerJobData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RouterSourceDict> {
    static void encode(Encoder&, const WebCore::RouterSourceDict&);
    static std::optional<WebCore::RouterSourceDict> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerRoutePattern> {
    static void encode(Encoder&, const WebCore::ServiceWorkerRoutePattern&);
    static std::optional<WebCore::ServiceWorkerRoutePattern> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerRouteCondition> {
    static void encode(Encoder&, const WebCore::ServiceWorkerRouteCondition&);
    static std::optional<WebCore::ServiceWorkerRouteCondition> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerRoute> {
    static void encode(Encoder&, const WebCore::ServiceWorkerRoute&);
    static std::optional<WebCore::ServiceWorkerRoute> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::EventInit> {
    static void encode(Encoder&, const WebCore::EventInit&);
    static std::optional<WebCore::EventInit> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MessageWithMessagePorts> {
    static void encode(Encoder&, const WebCore::MessageWithMessagePorts&);
    static std::optional<WebCore::MessageWithMessagePorts> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RequestStorageAccessResult> {
    static void encode(Encoder&, const WebCore::RequestStorageAccessResult&);
    static std::optional<WebCore::RequestStorageAccessResult> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Exception> {
    static void encode(Encoder&, const WebCore::Exception&);
    static std::optional<WebCore::Exception> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ExceptionData> {
    static void encode(Encoder&, const WebCore::ExceptionData&);
    static std::optional<WebCore::ExceptionData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MessagePortIdentifier> {
    static void encode(Encoder&, const WebCore::MessagePortIdentifier&);
    static std::optional<WebCore::MessagePortIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SecurityPolicyViolationEventInit> {
    static void encode(Encoder&, const WebCore::SecurityPolicyViolationEventInit&);
    static std::optional<WebCore::SecurityPolicyViolationEventInit> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CSPViolationReportBody> {
    static void encode(Encoder&, const WebCore::CSPViolationReportBody&);
    static std::optional<Ref<WebCore::CSPViolationReportBody>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SecurityOriginData> {
    static void encode(Encoder&, const WebCore::SecurityOriginData&);
    static std::optional<WebCore::SecurityOriginData> decode(Decoder&);
};

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MediaConstraint> {
    static void encode(Encoder&, const WebCore::MediaConstraint&);
    static std::optional<WebCore::MediaConstraint> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::IntConstraint> {
    static void encode(Encoder&, const WebCore::IntConstraint&);
    static std::optional<WebCore::IntConstraint> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::DoubleConstraint> {
    static void encode(Encoder&, const WebCore::DoubleConstraint&);
    static std::optional<WebCore::DoubleConstraint> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::BooleanConstraint> {
    static void encode(Encoder&, const WebCore::BooleanConstraint&);
    static std::optional<WebCore::BooleanConstraint> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::StringConstraint> {
    static void encode(Encoder&, const WebCore::StringConstraint&);
    static std::optional<WebCore::StringConstraint> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::FrameRateRange> {
    static void encode(Encoder&, const WebCore::FrameRateRange&);
    static std::optional<WebCore::FrameRateRange> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::VideoPresetData> {
    static void encode(Encoder&, const WebCore::VideoPresetData&);
    static std::optional<WebCore::VideoPresetData> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::RealtimeMediaSourceSupportedConstraints> {
    static void encode(Encoder&, const WebCore::RealtimeMediaSourceSupportedConstraints&);
    static std::optional<WebCore::RealtimeMediaSourceSupportedConstraints> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::RealtimeMediaSourceSettings> {
    static void encode(Encoder&, const WebCore::RealtimeMediaSourceSettings&);
    static std::optional<WebCore::RealtimeMediaSourceSettings> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::CaptureDevice> {
    static void encode(Encoder&, const WebCore::CaptureDevice&);
    static std::optional<WebCore::CaptureDevice> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::CaptureDeviceWithCapabilities> {
    static void encode(Encoder&, const WebCore::CaptureDeviceWithCapabilities&);
    static std::optional<WebCore::CaptureDeviceWithCapabilities> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::DoubleCapabilityRange> {
    static void encode(Encoder&, const WebCore::DoubleCapabilityRange&);
    static std::optional<WebCore::DoubleCapabilityRange> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::LongCapabilityRange> {
    static void encode(Encoder&, const WebCore::LongCapabilityRange&);
    static std::optional<WebCore::LongCapabilityRange> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::RealtimeMediaSourceCapabilities> {
    static void encode(Encoder&, const WebCore::RealtimeMediaSourceCapabilities&);
    static std::optional<WebCore::RealtimeMediaSourceCapabilities> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::PlatformVideoColorSpace> {
    static void encode(Encoder&, const WebCore::PlatformVideoColorSpace&);
    static void encode(StreamConnectionEncoder&, const WebCore::PlatformVideoColorSpace&);
    static std::optional<WebCore::PlatformVideoColorSpace> decode(Decoder&);
};

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::SpatialVideoMetadata> {
    static void encode(Encoder&, const WebCore::SpatialVideoMetadata&);
    static std::optional<WebCore::SpatialVideoMetadata> decode(Decoder&);
};
#endif

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::VideoProjectionMetadata> {
    static void encode(Encoder&, const WebCore::VideoProjectionMetadata&);
    static std::optional<WebCore::VideoProjectionMetadata> decode(Decoder&);
};
#endif

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::PlatformTrackConfiguration> {
    static void encode(Encoder&, const WebCore::PlatformTrackConfiguration&);
    static std::optional<WebCore::PlatformTrackConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::PlatformAudioTrackConfiguration> {
    static void encode(Encoder&, const WebCore::PlatformAudioTrackConfiguration&);
    static std::optional<WebCore::PlatformAudioTrackConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::PlatformVideoTrackConfiguration> {
    static void encode(Encoder&, const WebCore::PlatformVideoTrackConfiguration&);
    static std::optional<WebCore::PlatformVideoTrackConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(WEB_RTC)
template<> struct ArgumentCoder<WebCore::RTCDataChannelInit> {
    static void encode(Encoder&, const WebCore::RTCDataChannelInit&);
    static std::optional<WebCore::RTCDataChannelInit> decode(Decoder&);
};
#endif

#if ENABLE(CONTENT_EXTENSIONS)
template<> struct ArgumentCoder<WebCore::ContentRuleListResults> {
    static void encode(Encoder&, const WebCore::ContentRuleListResults&);
    static std::optional<WebCore::ContentRuleListResults> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::COEPInheritenceViolationReportBody> {
    static void encode(Encoder&, const WebCore::COEPInheritenceViolationReportBody&);
    static std::optional<Ref<WebCore::COEPInheritenceViolationReportBody>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CORPViolationReportBody> {
    static void encode(Encoder&, const WebCore::CORPViolationReportBody&);
    static std::optional<Ref<WebCore::CORPViolationReportBody>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ReportBody> {
    static void encode(Encoder&, const WebCore::ReportBody&);
    static std::optional<Ref<WebCore::ReportBody>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SourceImage> {
    static void encode(Encoder&, const WebCore::SourceImage&);
    static void encode(StreamConnectionEncoder&, const WebCore::SourceImage&);
    static std::optional<WebCore::SourceImage> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LinkIcon> {
    static void encode(Encoder&, const WebCore::LinkIcon&);
    static std::optional<WebCore::LinkIcon> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SupportedPluginIdentifier> {
    static void encode(Encoder&, const WebCore::SupportedPluginIdentifier&);
    static std::optional<WebCore::SupportedPluginIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CSSValueKey> {
    static void encode(Encoder&, const WebCore::CSSValueKey&);
    static std::optional<WebCore::CSSValueKey> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::VideoFrameTimeMetadata> {
    static void encode(Encoder&, const WebCore::VideoFrameTimeMetadata&);
    static std::optional<WebCore::VideoFrameTimeMetadata> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::EventRegion> {
    static void encode(Encoder&, const WebCore::EventRegion&);
    static std::optional<WebCore::EventRegion> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PresentationSize> {
    static void encode(Encoder&, const WebCore::PresentationSize&);
    static std::optional<WebCore::PresentationSize> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PasteboardItemInfo> {
    static void encode(Encoder&, const WebCore::PasteboardItemInfo&);
    static std::optional<WebCore::PasteboardItemInfo> decode(Decoder&);
};

#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
template<> struct ArgumentCoder<WebCore::MediaControlsContextMenuItem> {
    static void encode(Encoder&, const WebCore::MediaControlsContextMenuItem&);
    static std::optional<WebCore::MediaControlsContextMenuItem> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::WorkerOptions> {
    static void encode(Encoder&, const WebCore::WorkerOptions&);
    static std::optional<WebCore::WorkerOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::WorkerInitializationData> {
    static void encode(Encoder&, const WebCore::WorkerInitializationData&);
    static std::optional<WebCore::WorkerInitializationData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::WorkerFetchResult> {
    static void encode(Encoder&, const WebCore::WorkerFetchResult&);
    static std::optional<WebCore::WorkerFetchResult> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SharedWorkerKey> {
    static void encode(Encoder&, const WebCore::SharedWorkerKey&);
    static std::optional<WebCore::SharedWorkerKey> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerRegistrationOptions> {
    static void encode(Encoder&, const WebCore::ServiceWorkerRegistrationOptions&);
    static std::optional<WebCore::ServiceWorkerRegistrationOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerRegistrationKey> {
    static void encode(Encoder&, const WebCore::ServiceWorkerRegistrationKey&);
    static std::optional<WebCore::ServiceWorkerRegistrationKey> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerRegistrationData> {
    static void encode(Encoder&, const WebCore::ServiceWorkerRegistrationData&);
    static std::optional<WebCore::ServiceWorkerRegistrationData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerJobDataIdentifier> {
    static void encode(Encoder&, const WebCore::ServiceWorkerJobDataIdentifier&);
    static std::optional<WebCore::ServiceWorkerJobDataIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ServiceWorkerImportedScript> {
    static void encode(Encoder&, const WebCore::ServiceWorkerImportedScript&);
    static std::optional<WebCore::ServiceWorkerImportedScript> decode(Decoder&);
};

#if ENABLE(SHAREABLE_RESOURCE) && PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::ScriptBuffer> {
    static void encode(Encoder&, const WebCore::ScriptBuffer&);
    static std::optional<WebCore::ScriptBuffer> decode(Decoder&);
};
#endif

#if !ENABLE(SHAREABLE_RESOURCE) || !PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::ScriptBuffer> {
    static void encode(Encoder&, const WebCore::ScriptBuffer&);
    static std::optional<WebCore::ScriptBuffer> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::ServiceWorkerContextData> {
    static void encode(Encoder&, const WebCore::ServiceWorkerContextData&);
    static std::optional<WebCore::ServiceWorkerContextData> decode(Decoder&);
};

template<> struct ArgumentCoder<JSC::ArrayBuffer> {
    static void encode(Encoder&, const JSC::ArrayBuffer&);
    static std::optional<Ref<JSC::ArrayBuffer>> decode(Decoder&);
};

template<> struct ArgumentCoder<JSC::ArrayBufferContents> {
    static void encode(Encoder&, const JSC::ArrayBufferContents&);
    static std::optional<JSC::ArrayBufferContents> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::GlobalFrameIdentifier> {
    static void encode(Encoder&, const WebCore::GlobalFrameIdentifier&);
    static std::optional<WebCore::GlobalFrameIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::GlobalWindowIdentifier> {
    static void encode(Encoder&, const WebCore::GlobalWindowIdentifier&);
    static std::optional<WebCore::GlobalWindowIdentifier> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::InteractionRegion> {
    static void encode(Encoder&, const WebCore::InteractionRegion&);
    static std::optional<WebCore::InteractionRegion> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Region> {
    static void encode(Encoder&, const WebCore::Region&);
    static void encode(StreamConnectionEncoder&, const WebCore::Region&);
    static std::optional<WebCore::Region> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ISOWebVTTCue> {
    static void encode(Encoder&, const WebCore::ISOWebVTTCue&);
    static std::optional<WebCore::ISOWebVTTCue> decode(Decoder&);
};

#if ENABLE(WEB_AUTHN)
template<> struct ArgumentCoder<WebCore::MockWebAuthenticationConfiguration> {
    static void encode(Encoder&, const WebCore::MockWebAuthenticationConfiguration&);
    static std::optional<WebCore::MockWebAuthenticationConfiguration> decode(Decoder&);
};
#endif

#if (ENABLE(WEB_AUTHN)) && (HAVE(DIGITAL_CREDENTIALS_UI))
template<> struct ArgumentCoder<WebCore::OpenID4VPRequest> {
    static void encode(Encoder&, const WebCore::OpenID4VPRequest&);
    static std::optional<WebCore::OpenID4VPRequest> decode(Decoder&);
};
#endif

#if (ENABLE(WEB_AUTHN)) && (HAVE(DIGITAL_CREDENTIALS_UI))
template<> struct ArgumentCoder<WebCore::MobileDocumentRequest> {
    static void encode(Encoder&, const WebCore::MobileDocumentRequest&);
    static std::optional<WebCore::MobileDocumentRequest> decode(Decoder&);
};
#endif

#if (ENABLE(WEB_AUTHN)) && (HAVE(DIGITAL_CREDENTIALS_UI))
template<> struct ArgumentCoder<WebCore::DigitalCredentialsRequestData> {
    static void encode(Encoder&, const WebCore::DigitalCredentialsRequestData&);
    static std::optional<WebCore::DigitalCredentialsRequestData> decode(Decoder&);
};
#endif

#if (ENABLE(WEB_AUTHN)) && (HAVE(DIGITAL_CREDENTIALS_UI))
template<> struct ArgumentCoder<WebCore::DigitalCredentialsResponseData> {
    static void encode(Encoder&, const WebCore::DigitalCredentialsResponseData&);
    static std::optional<WebCore::DigitalCredentialsResponseData> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MockMicrophoneProperties> {
    static void encode(Encoder&, const WebCore::MockMicrophoneProperties&);
    static std::optional<WebCore::MockMicrophoneProperties> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MockSpeakerProperties> {
    static void encode(Encoder&, const WebCore::MockSpeakerProperties&);
    static std::optional<WebCore::MockSpeakerProperties> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MockCameraProperties> {
    static void encode(Encoder&, const WebCore::MockCameraProperties&);
    static std::optional<WebCore::MockCameraProperties> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MockDisplayProperties> {
    static void encode(Encoder&, const WebCore::MockDisplayProperties&);
    static std::optional<WebCore::MockDisplayProperties> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MockMediaDevice> {
    static void encode(Encoder&, const WebCore::MockMediaDevice&);
    static std::optional<WebCore::MockMediaDevice> decode(Decoder&);
};
#endif

#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> struct ArgumentCoder<WebCore::Style::OffsetRotate> {
    static void encode(Encoder&, const WebCore::Style::OffsetRotate&);
    static std::optional<WebCore::Style::OffsetRotate> decode(Decoder&);
};
#endif

#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> struct ArgumentCoder<WebCore::AcceleratedEffectValues> {
    static void encode(Encoder&, const WebCore::AcceleratedEffectValues&);
    static std::optional<WebCore::AcceleratedEffectValues> decode(Decoder&);
};
#endif

#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> struct ArgumentCoder<WebCore::WebAnimationTime> {
    static void encode(Encoder&, const WebCore::WebAnimationTime&);
    static std::optional<WebCore::WebAnimationTime> decode(Decoder&);
};
#endif

#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> struct ArgumentCoder<WebCore::AnimationEffectTiming> {
    static void encode(Encoder&, const WebCore::AnimationEffectTiming&);
    static std::optional<WebCore::AnimationEffectTiming> decode(Decoder&);
};
#endif

#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> struct ArgumentCoder<WebCore::AcceleratedEffect> {
    static void encode(Encoder&, const WebCore::AcceleratedEffect&);
    static std::optional<Ref<WebCore::AcceleratedEffect>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::ProtectionSpace> {
    static void encode(Encoder&, const WebCore::ProtectionSpace&);
    static std::optional<WebCore::ProtectionSpace> decode(Decoder&);
};

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::Credential> {
    static void encode(Encoder&, const WebCore::Credential&);
    static std::optional<WebCore::Credential> decode(Decoder&);
};
#endif

#if USE(SOUP)
template<> struct ArgumentCoder<WebCore::Credential> {
    static void encode(Encoder&, const WebCore::Credential&);
    static std::optional<WebCore::Credential> decode(Decoder&);
};
#endif

#if USE(CURL)
template<> struct ArgumentCoder<WebCore::Credential> {
    static void encode(Encoder&, const WebCore::Credential&);
    static std::optional<WebCore::Credential> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebCore::ShapeDetection::BarcodeDetectorOptions> {
    static void encode(Encoder&, const WebCore::ShapeDetection::BarcodeDetectorOptions&);
    static void encode(StreamConnectionEncoder&, const WebCore::ShapeDetection::BarcodeDetectorOptions&);
    static std::optional<WebCore::ShapeDetection::BarcodeDetectorOptions> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebCore::ShapeDetection::DetectedBarcode> {
    static void encode(Encoder&, const WebCore::ShapeDetection::DetectedBarcode&);
    static void encode(StreamConnectionEncoder&, const WebCore::ShapeDetection::DetectedBarcode&);
    static std::optional<WebCore::ShapeDetection::DetectedBarcode> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebCore::ShapeDetection::DetectedFace> {
    static void encode(Encoder&, const WebCore::ShapeDetection::DetectedFace&);
    static void encode(StreamConnectionEncoder&, const WebCore::ShapeDetection::DetectedFace&);
    static std::optional<WebCore::ShapeDetection::DetectedFace> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebCore::ShapeDetection::DetectedText> {
    static void encode(Encoder&, const WebCore::ShapeDetection::DetectedText&);
    static void encode(StreamConnectionEncoder&, const WebCore::ShapeDetection::DetectedText&);
    static std::optional<WebCore::ShapeDetection::DetectedText> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebCore::ShapeDetection::FaceDetectorOptions> {
    static void encode(Encoder&, const WebCore::ShapeDetection::FaceDetectorOptions&);
    static void encode(StreamConnectionEncoder&, const WebCore::ShapeDetection::FaceDetectorOptions&);
    static std::optional<WebCore::ShapeDetection::FaceDetectorOptions> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebCore::ShapeDetection::Landmark> {
    static void encode(Encoder&, const WebCore::ShapeDetection::Landmark&);
    static void encode(StreamConnectionEncoder&, const WebCore::ShapeDetection::Landmark&);
    static std::optional<WebCore::ShapeDetection::Landmark> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::TextExtraction::Editable> {
    static void encode(Encoder&, const WebCore::TextExtraction::Editable&);
    static std::optional<WebCore::TextExtraction::Editable> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextExtraction::TextItemData> {
    static void encode(Encoder&, const WebCore::TextExtraction::TextItemData&);
    static std::optional<WebCore::TextExtraction::TextItemData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextExtraction::ScrollableItemData> {
    static void encode(Encoder&, const WebCore::TextExtraction::ScrollableItemData&);
    static std::optional<WebCore::TextExtraction::ScrollableItemData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextExtraction::ImageItemData> {
    static void encode(Encoder&, const WebCore::TextExtraction::ImageItemData&);
    static std::optional<WebCore::TextExtraction::ImageItemData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TextExtraction::Item> {
    static void encode(Encoder&, const WebCore::TextExtraction::Item&);
    static std::optional<WebCore::TextExtraction::Item> decode(Decoder&);
};

#if ENABLE(WRITING_TOOLS)
template<> struct ArgumentCoder<WebCore::WritingTools::Session> {
    static void encode(Encoder&, const WebCore::WritingTools::Session&);
    static std::optional<WebCore::WritingTools::Session> decode(Decoder&);
};
#endif

#if ENABLE(WRITING_TOOLS)
template<> struct ArgumentCoder<WebCore::WritingTools::Context> {
    static void encode(Encoder&, const WebCore::WritingTools::Context&);
    static std::optional<WebCore::WritingTools::Context> decode(Decoder&);
};
#endif

#if ENABLE(WRITING_TOOLS)
template<> struct ArgumentCoder<WebCore::WritingTools::TextSuggestion> {
    static void encode(Encoder&, const WebCore::WritingTools::TextSuggestion&);
    static std::optional<WebCore::WritingTools::TextSuggestion> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::CaptureSourceError> {
    static void encode(Encoder&, const WebCore::CaptureSourceError&);
    static std::optional<WebCore::CaptureSourceError> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::MediaSettingsRange> {
    static void encode(Encoder&, const WebCore::MediaSettingsRange&);
    static std::optional<WebCore::MediaSettingsRange> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::PhotoCapabilities> {
    static void encode(Encoder&, const WebCore::PhotoCapabilities&);
    static std::optional<WebCore::PhotoCapabilities> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebCore::PhotoSettings> {
    static void encode(Encoder&, const WebCore::PhotoSettings&);
    static std::optional<WebCore::PhotoSettings> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::CookieStoreGetOptions> {
    static void encode(Encoder&, const WebCore::CookieStoreGetOptions&);
    static std::optional<WebCore::CookieStoreGetOptions> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CookieChangeSubscription> {
    static void encode(Encoder&, const WebCore::CookieChangeSubscription&);
    static std::optional<WebCore::CookieChangeSubscription> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Model> {
    static void encode(Encoder&, const WebCore::Model&);
    static std::optional<Ref<WebCore::Model>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ModelPlayerAnimationState> {
    static void encode(Encoder&, const WebCore::ModelPlayerAnimationState&);
    static std::optional<WebCore::ModelPlayerAnimationState> decode(Decoder&);
};

#if ENABLE(MODEL_PROCESS)
template<> struct ArgumentCoder<WebCore::ModelContext> {
    static void encode(Encoder&, const WebCore::ModelContext&);
    static std::optional<Ref<WebCore::ModelContext>> decode(Decoder&);
};
#endif

#if PLATFORM(IOS_FAMILY)
template<> struct ArgumentCoder<WebCore::InspectorOverlayLabel> {
    static void encode(Encoder&, const WebCore::InspectorOverlayLabel&);
    static std::optional<WebCore::InspectorOverlayLabel> decode(Decoder&);
};
#endif

#if PLATFORM(IOS_FAMILY)
template<> struct ArgumentCoder<WebCore::InspectorOverlayHighlight> {
    static void encode(Encoder&, const WebCore::InspectorOverlayHighlight&);
    static std::optional<WebCore::InspectorOverlayHighlight> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::DiagnosticLoggingDictionary> {
    static void encode(Encoder&, const WebCore::DiagnosticLoggingDictionary&);
    static std::optional<WebCore::DiagnosticLoggingDictionary> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FixedPositionViewportConstraints> {
    static void encode(Encoder&, const WebCore::FixedPositionViewportConstraints&);
    static std::optional<WebCore::FixedPositionViewportConstraints> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::StickyPositionViewportConstraints> {
    static void encode(Encoder&, const WebCore::StickyPositionViewportConstraints&);
    static std::optional<WebCore::StickyPositionViewportConstraints> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatLine> {
    static void encode(Encoder&, const WebCore::FloatLine&);
    static std::optional<WebCore::FloatLine> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontCachePrewarmInformation> {
    static void encode(Encoder&, const WebCore::FontCachePrewarmInformation&);
    static std::optional<WebCore::FontCachePrewarmInformation> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PrewarmInformation> {
    static void encode(Encoder&, const WebCore::PrewarmInformation&);
    static std::optional<WebCore::PrewarmInformation> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontSelectionValue> {
    static void encode(Encoder&, const WebCore::FontSelectionValue&);
    static std::optional<WebCore::FontSelectionValue> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontSelectionRange> {
    static void encode(Encoder&, const WebCore::FontSelectionRange&);
    static std::optional<WebCore::FontSelectionRange> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontSelectionSpecifiedCapabilities> {
    static void encode(Encoder&, const WebCore::FontSelectionSpecifiedCapabilities&);
    static std::optional<WebCore::FontSelectionSpecifiedCapabilities> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RemoteUserInputEventData> {
    static void encode(Encoder&, const WebCore::RemoteUserInputEventData&);
    static std::optional<WebCore::RemoteUserInputEventData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LinkDecorationFilteringData> {
    static void encode(Encoder&, const WebCore::LinkDecorationFilteringData&);
    static std::optional<WebCore::LinkDecorationFilteringData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::InspectorFrontendClientSaveData> {
    static void encode(Encoder&, const WebCore::InspectorFrontendClientSaveData&);
    static std::optional<WebCore::InspectorFrontendClientSaveData> decode(Decoder&);
};

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::PlatformTextTrackData> {
    static void encode(Encoder&, const WebCore::PlatformTextTrackData&);
    static std::optional<WebCore::PlatformTextTrackData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::NotificationPayload> {
    static void encode(Encoder&, const WebCore::NotificationPayload&);
    static std::optional<WebCore::NotificationPayload> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NotificationOptionsPayload> {
    static void encode(Encoder&, const WebCore::NotificationOptionsPayload&);
    static std::optional<WebCore::NotificationOptionsPayload> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NetworkLoadMetrics> {
    static void encode(Encoder&, const WebCore::NetworkLoadMetrics&);
    static std::optional<WebCore::NetworkLoadMetrics> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::AdditionalNetworkLoadMetricsForWebInspector> {
    static void encode(Encoder&, const WebCore::AdditionalNetworkLoadMetricsForWebInspector&);
    static std::optional<Ref<WebCore::AdditionalNetworkLoadMetricsForWebInspector>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DisplayUpdate> {
    static void encode(Encoder&, const WebCore::DisplayUpdate&);
    static std::optional<WebCore::DisplayUpdate> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MediaUsageInfo> {
    static void encode(Encoder&, const WebCore::MediaUsageInfo&);
    static std::optional<WebCore::MediaUsageInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NowPlayingInfoArtwork> {
    static void encode(Encoder&, const WebCore::NowPlayingInfoArtwork&);
    static std::optional<WebCore::NowPlayingInfoArtwork> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NowPlayingMetadata> {
    static void encode(Encoder&, const WebCore::NowPlayingMetadata&);
    static std::optional<WebCore::NowPlayingMetadata> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::NowPlayingInfo> {
    static void encode(Encoder&, const WebCore::NowPlayingInfo&);
    static std::optional<WebCore::NowPlayingInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::VideoConfiguration> {
    static void encode(Encoder&, const WebCore::VideoConfiguration&);
    static std::optional<WebCore::VideoConfiguration> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FloatFontTaggedSetting> {
    static void encode(Encoder&, const WebCore::FloatFontTaggedSetting&);
    static std::optional<WebCore::FloatFontTaggedSetting> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::IntFontTaggedSetting> {
    static void encode(Encoder&, const WebCore::IntFontTaggedSetting&);
    static std::optional<WebCore::IntFontTaggedSetting> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontVariationSettings> {
    static void encode(Encoder&, const WebCore::FontVariationSettings&);
    static std::optional<WebCore::FontVariationSettings> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontFeatureSettings> {
    static void encode(Encoder&, const WebCore::FontFeatureSettings&);
    static std::optional<WebCore::FontFeatureSettings> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::UserScript> {
    static void encode(Encoder&, const WebCore::UserScript&);
    static std::optional<WebCore::UserScript> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ContentSecurityPolicyResponseHeaders> {
    static void encode(Encoder&, const WebCore::ContentSecurityPolicyResponseHeaders&);
    static std::optional<WebCore::ContentSecurityPolicyResponseHeaders> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DragImage> {
    static void encode(Encoder&, const WebCore::DragImage&);
    static std::optional<WebCore::DragImage> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DragItem> {
    static void encode(Encoder&, const WebCore::DragItem&);
    static std::optional<WebCore::DragItem> decode(Decoder&);
};

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::KeypressCommand> {
    static void encode(Encoder&, const WebCore::KeypressCommand&);
    static std::optional<WebCore::KeypressCommand> decode(Decoder&);
};
#endif

#if !USE(COORDINATED_GRAPHICS)
template<> struct ArgumentCoder<WebCore::FilterOperations> {
    static void encode(Encoder&, const WebCore::FilterOperations&);
    static std::optional<WebCore::FilterOperations> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::Filter> {
    static void encode(Encoder&, const WebCore::Filter&);
    static void encode(StreamConnectionEncoder&, const WebCore::Filter&);
    static std::optional<Ref<WebCore::Filter>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CSSFilter> {
    static void encode(Encoder&, const WebCore::CSSFilter&);
    static void encode(StreamConnectionEncoder&, const WebCore::CSSFilter&);
    static std::optional<Ref<WebCore::CSSFilter>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SVGFilter> {
    static void encode(Encoder&, const WebCore::SVGFilter&);
    static void encode(StreamConnectionEncoder&, const WebCore::SVGFilter&);
    static std::optional<Ref<WebCore::SVGFilter>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ByteArrayPixelBuffer> {
    static void encode(Encoder&, const WebCore::ByteArrayPixelBuffer&);
    static void encode(StreamConnectionEncoder&, const WebCore::ByteArrayPixelBuffer&);
    static std::optional<Ref<WebCore::ByteArrayPixelBuffer>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PixelBufferSourceView> {
    static void encode(Encoder&, const WebCore::PixelBufferSourceView&);
    static void encode(StreamConnectionEncoder&, const WebCore::PixelBufferSourceView&);
    static std::optional<WebCore::PixelBufferSourceView> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MarkupExclusionRule> {
    static void encode(Encoder&, const WebCore::MarkupExclusionRule&);
    static std::optional<WebCore::MarkupExclusionRule> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SystemImage> {
    static void encode(Encoder&, const WebCore::SystemImage&);
    static void encode(StreamConnectionEncoder&, const WebCore::SystemImage&);
    static std::optional<Ref<WebCore::SystemImage>> decode(Decoder&);
};

#if ENABLE(WEB_CODECS)
template<> struct ArgumentCoder<WebCore::WebCodecsEncodedVideoChunkStorage> {
    static void encode(Encoder&, const WebCore::WebCodecsEncodedVideoChunkStorage&);
    static std::optional<Ref<WebCore::WebCodecsEncodedVideoChunkStorage>> decode(Decoder&);
};
#endif

#if ENABLE(WEB_CODECS)
template<> struct ArgumentCoder<WebCore::WebCodecsEncodedAudioChunkStorage> {
    static void encode(Encoder&, const WebCore::WebCodecsEncodedAudioChunkStorage&);
    static std::optional<Ref<WebCore::WebCodecsEncodedAudioChunkStorage>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::SerializedScriptValue> {
    static void encode(Encoder&, const WebCore::SerializedScriptValue&);
    static std::optional<Ref<WebCore::SerializedScriptValue>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SharedBuffer> {
    static void encode(Encoder&, const WebCore::SharedBuffer&);
    static std::optional<Ref<WebCore::SharedBuffer>> decode(Decoder&);
};

#if !USE(COORDINATED_GRAPHICS)
template<> struct ArgumentCoder<WebCore::FilterOperation> {
    static void encode(Encoder&, const WebCore::FilterOperation&);
    static std::optional<Ref<WebCore::FilterOperation>> decode(Decoder&);
};
#endif

#if !USE(COORDINATED_GRAPHICS)
template<> struct ArgumentCoder<WebCore::BasicColorMatrixFilterOperation> {
    static void encode(Encoder&, const WebCore::BasicColorMatrixFilterOperation&);
    static std::optional<Ref<WebCore::BasicColorMatrixFilterOperation>> decode(Decoder&);
};
#endif

#if !USE(COORDINATED_GRAPHICS)
template<> struct ArgumentCoder<WebCore::BasicComponentTransferFilterOperation> {
    static void encode(Encoder&, const WebCore::BasicComponentTransferFilterOperation&);
    static std::optional<Ref<WebCore::BasicComponentTransferFilterOperation>> decode(Decoder&);
};
#endif

#if !USE(COORDINATED_GRAPHICS)
template<> struct ArgumentCoder<WebCore::BlurFilterOperation> {
    static void encode(Encoder&, const WebCore::BlurFilterOperation&);
    static std::optional<Ref<WebCore::BlurFilterOperation>> decode(Decoder&);
};
#endif

#if !USE(COORDINATED_GRAPHICS)
template<> struct ArgumentCoder<WebCore::DropShadowFilterOperation> {
    static void encode(Encoder&, const WebCore::DropShadowFilterOperation&);
    static std::optional<Ref<WebCore::DropShadowFilterOperation>> decode(Decoder&);
};
#endif

#if !USE(COORDINATED_GRAPHICS)
template<> struct ArgumentCoder<WebCore::DefaultFilterOperation> {
    static void encode(Encoder&, const WebCore::DefaultFilterOperation&);
    static std::optional<Ref<WebCore::DefaultFilterOperation>> decode(Decoder&);
};
#endif

#if !USE(COORDINATED_GRAPHICS)
template<> struct ArgumentCoder<WebCore::PassthroughFilterOperation> {
    static void encode(Encoder&, const WebCore::PassthroughFilterOperation&);
    static std::optional<Ref<WebCore::PassthroughFilterOperation>> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::FilterEffect> {
    static void encode(Encoder&, const WebCore::FilterEffect&);
    static void encode(StreamConnectionEncoder&, const WebCore::FilterEffect&);
    static std::optional<Ref<WebCore::FilterEffect>> decode(Decoder&);
};

#if HAVE(CORE_MATERIAL)
template<> struct ArgumentCoder<WebCore::AppleVisualEffectData> {
    static void encode(Encoder&, const WebCore::AppleVisualEffectData&);
    static std::optional<WebCore::AppleVisualEffectData> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_SOURCE)
template<> struct ArgumentCoder<WebCore::SourceBufferEvictionData> {
    static void encode(Encoder&, const WebCore::SourceBufferEvictionData&);
    static std::optional<WebCore::SourceBufferEvictionData> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_SOURCE)
template<> struct ArgumentCoder<WebCore::MediaSourceConfiguration> {
    static void encode(Encoder&, const WebCore::MediaSourceConfiguration&);
    static std::optional<WebCore::MediaSourceConfiguration> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::FontInternalAttributes> {
    static void encode(Encoder&, const WebCore::FontInternalAttributes&);
    static std::optional<WebCore::FontInternalAttributes> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Cursor> {
    static void encode(Encoder&, const WebCore::Cursor&);
    static std::optional<WebCore::Cursor> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::DOMCacheEngine::Record> {
    static void encode(Encoder&, const WebCore::DOMCacheEngine::Record&);
    static std::optional<WebCore::DOMCacheEngine::Record> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::LightSource> {
    static void encode(Encoder&, const WebCore::LightSource&);
    static void encode(StreamConnectionEncoder&, const WebCore::LightSource&);
    static std::optional<Ref<WebCore::LightSource>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Image> {
    static void encode(Encoder&, const WebCore::Image&);
    static std::optional<Ref<WebCore::Image>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Length> {
    static void encode(Encoder&, const WebCore::Length&);
    static std::optional<WebCore::Length> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FilterFunction> {
    static void encode(Encoder&, const WebCore::FilterFunction&);
    static void encode(StreamConnectionEncoder&, const WebCore::FilterFunction&);
    static std::optional<Ref<WebCore::FilterFunction>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::OrganizationStorageAccessPromptQuirk> {
    static void encode(Encoder&, const WebCore::OrganizationStorageAccessPromptQuirk&);
    static std::optional<WebCore::OrganizationStorageAccessPromptQuirk> decode(Decoder&);
};

#if ENABLE(SHAREABLE_RESOURCE)
template<> struct ArgumentCoder<WebCore::ShareableResourceHandle> {
    static void encode(Encoder&, WebCore::ShareableResourceHandle&&);
    static std::optional<WebCore::ShareableResourceHandle> decode(Decoder&);
};
#endif

#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
template<> struct ArgumentCoder<WebCore::DynamicContentScalingDisplayList> {
    static void encode(Encoder&, WebCore::DynamicContentScalingDisplayList&&);
    static std::optional<WebCore::DynamicContentScalingDisplayList> decode(Decoder&);
};
#endif

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::TextAttachmentMissingImage> {
    static void encode(Encoder&, const WebCore::TextAttachmentMissingImage&);
    static std::optional<WebCore::TextAttachmentMissingImage> decode(Decoder&);
};
#endif

#if PLATFORM(COCOA)
template<> struct ArgumentCoder<WebCore::TextAttachmentFileWrapper> {
    static void encode(Encoder&, const WebCore::TextAttachmentFileWrapper&);
    static std::optional<WebCore::TextAttachmentFileWrapper> decode(Decoder&);
};
#endif

#if (PLATFORM(COCOA)) && (ENABLE(MULTI_REPRESENTATION_HEIC))
template<> struct ArgumentCoder<WebCore::MultiRepresentationHEICAttachmentSingleImage> {
    static void encode(Encoder&, const WebCore::MultiRepresentationHEICAttachmentSingleImage&);
    static std::optional<WebCore::MultiRepresentationHEICAttachmentSingleImage> decode(Decoder&);
};
#endif

#if (PLATFORM(COCOA)) && (ENABLE(MULTI_REPRESENTATION_HEIC))
template<> struct ArgumentCoder<WebCore::MultiRepresentationHEICAttachmentData> {
    static void encode(Encoder&, const WebCore::MultiRepresentationHEICAttachmentData&);
    static std::optional<WebCore::MultiRepresentationHEICAttachmentData> decode(Decoder&);
};
#endif

#if ENABLE(IMAGE_ANALYSIS) && ENABLE(DATA_DETECTION)
template<> struct ArgumentCoder<WebCore::TextRecognitionDataDetector> {
    static void encode(Encoder&, const WebCore::TextRecognitionDataDetector&);
    static std::optional<WebCore::TextRecognitionDataDetector> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::ShareableBitmapConfiguration> {
    static void encode(Encoder&, const WebCore::ShareableBitmapConfiguration&);
    static std::optional<WebCore::ShareableBitmapConfiguration> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ShareableBitmapHandle> {
    static void encode(Encoder&, WebCore::ShareableBitmapHandle&&);
    static std::optional<WebCore::ShareableBitmapHandle> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ShareableBitmap> {
    static void encode(Encoder&, const WebCore::ShareableBitmap&);
    static std::optional<Ref<WebCore::ShareableBitmap>> decode(Decoder&);
};

#if ENABLE(DATA_DETECTION)
template<> struct ArgumentCoder<WebCore::DataDetectorElementInfo> {
    static void encode(Encoder&, const WebCore::DataDetectorElementInfo&);
    static std::optional<WebCore::DataDetectorElementInfo> decode(Decoder&);
};
#endif

#if ENABLE(VIDEO)
template<> struct ArgumentCoder<WebCore::SerializedPlatformDataCueValue> {
    static void encode(Encoder&, const WebCore::SerializedPlatformDataCueValue&);
    static std::optional<WebCore::SerializedPlatformDataCueValue> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::FragmentedSharedBuffer> {
    static void encode(Encoder&, const WebCore::FragmentedSharedBuffer&);
    static std::optional<Ref<WebCore::FragmentedSharedBuffer>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PublicSuffix> {
    static void encode(Encoder&, const WebCore::PublicSuffix&);
    static std::optional<WebCore::PublicSuffix> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::WrappedCryptoKey> {
    static void encode(Encoder&, const WebCore::WrappedCryptoKey&);
    static std::optional<WebCore::WrappedCryptoKey> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Allowlist> {
    static void encode(Encoder&, const WebCore::Allowlist&);
    static std::optional<WebCore::Allowlist> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::OwnerPermissionsPolicyData> {
    static void encode(Encoder&, const WebCore::OwnerPermissionsPolicyData&);
    static std::optional<WebCore::OwnerPermissionsPolicyData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::PermissionsPolicy> {
    static void encode(Encoder&, const WebCore::PermissionsPolicy&);
    static std::optional<WebCore::PermissionsPolicy> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ImageBufferResourceLimits> {
    static void encode(Encoder&, const WebCore::ImageBufferResourceLimits&);
    static std::optional<WebCore::ImageBufferResourceLimits> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::RsaOtherPrimesInfo> {
    static void encode(Encoder&, const WebCore::RsaOtherPrimesInfo&);
    static std::optional<WebCore::RsaOtherPrimesInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::JsonWebKey> {
    static void encode(Encoder&, const WebCore::JsonWebKey&);
    static std::optional<WebCore::JsonWebKey> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CryptoKeyData> {
    static void encode(Encoder&, const WebCore::CryptoKeyData&);
    static std::optional<WebCore::CryptoKeyData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FixedContainerEdges> {
    static void encode(Encoder&, const WebCore::FixedContainerEdges&);
    static std::optional<WebCore::FixedContainerEdges> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::MessageForTesting> {
    static void encode(Encoder&, const WebCore::MessageForTesting&);
    static std::optional<WebCore::MessageForTesting> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::HostingContext> {
    static void encode(Encoder&, const WebCore::HostingContext&);
    static std::optional<WebCore::HostingContext> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FocusEventData> {
    static void encode(Encoder&, const WebCore::FocusEventData&);
    static std::optional<WebCore::FocusEventData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::AXDebugInfo> {
    static void encode(Encoder&, const WebCore::AXDebugInfo&);
    static std::optional<WebCore::AXDebugInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::Font> {
    static void encode(Encoder&, const WebCore::Font&);
    static std::optional<Ref<WebCore::Font>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontPlatformData> {
    static void encode(Encoder&, const WebCore::FontPlatformData&);
    static std::optional<WebCore::FontPlatformData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontPlatformDataAttributes> {
    static void encode(Encoder&, const WebCore::FontPlatformDataAttributes&);
    static std::optional<WebCore::FontPlatformDataAttributes> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FontCustomPlatformSerializedData> {
    static void encode(Encoder&, const WebCore::FontCustomPlatformSerializedData&);
    static std::optional<WebCore::FontCustomPlatformSerializedData> decode(Decoder&);
};

#if ENABLE(CONTENT_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebCompiledContentRuleListData> {
    static void encode(Encoder&, const WebKit::WebCompiledContentRuleListData&);
    static std::optional<WebKit::WebCompiledContentRuleListData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::WebEvent> {
    static void encode(Encoder&, const WebKit::WebEvent&);
    static std::optional<WebKit::WebEvent> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebKeyboardEvent> {
    static void encode(Encoder&, const WebKit::WebKeyboardEvent&);
    static std::optional<WebKit::WebKeyboardEvent> decode(Decoder&);
};

#if ENABLE(TOUCH_EVENTS)
template<> struct ArgumentCoder<WebKit::WebTouchEvent> {
    static void encode(Encoder&, const WebKit::WebTouchEvent&);
    static std::optional<WebKit::WebTouchEvent> decode(Decoder&);
};
#endif

#if ENABLE(TOUCH_EVENTS)
template<> struct ArgumentCoder<WebKit::WebPlatformTouchPoint> {
    static void encode(Encoder&, const WebKit::WebPlatformTouchPoint&);
    static std::optional<WebKit::WebPlatformTouchPoint> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::WebMouseEvent> {
    static void encode(Encoder&, const WebKit::WebMouseEvent&);
    static std::optional<WebKit::WebMouseEvent> decode(Decoder&);
};

#if ENABLE(MAC_GESTURE_EVENTS)
template<> struct ArgumentCoder<WebKit::WebGestureEvent> {
    static void encode(Encoder&, const WebKit::WebGestureEvent&);
    static std::optional<WebKit::WebGestureEvent> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::WebWheelEvent> {
    static void encode(Encoder&, const WebKit::WebWheelEvent&);
    static std::optional<WebKit::WebWheelEvent> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebFoundTextRange> {
    static void encode(Encoder&, const WebKit::WebFoundTextRange&);
    static std::optional<WebKit::WebFoundTextRange> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebFrameMetrics> {
    static void encode(Encoder&, const WebKit::WebFrameMetrics&);
    static std::optional<WebKit::WebFrameMetrics> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebHitTestResultData> {
    static void encode(Encoder&, const WebKit::WebHitTestResultData&);
    static std::optional<WebKit::WebHitTestResultData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebImage> {
    static void encode(Encoder&, const WebKit::WebImage&);
    static std::optional<Ref<WebKit::WebImage>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebNavigationDataStore> {
    static void encode(Encoder&, const WebKit::WebNavigationDataStore&);
    static std::optional<WebKit::WebNavigationDataStore> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebPageCreationParameters> {
    static void encode(Encoder&, WebKit::WebPageCreationParameters&&);
    static std::optional<WebKit::WebPageCreationParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebPageGroupData> {
    static void encode(Encoder&, const WebKit::WebPageGroupData&);
    static std::optional<WebKit::WebPageGroupData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebPageNetworkParameters> {
    static void encode(Encoder&, const WebKit::WebPageNetworkParameters&);
    static std::optional<WebKit::WebPageNetworkParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebPopupItem> {
    static void encode(Encoder&, const WebKit::WebPopupItem&);
    static std::optional<WebKit::WebPopupItem> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebPreferencesStore> {
    static void encode(Encoder&, const WebKit::WebPreferencesStore&);
    static std::optional<WebKit::WebPreferencesStore> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebProcessCreationParameters> {
    static void encode(Encoder&, WebKit::WebProcessCreationParameters&&);
    static std::optional<WebKit::WebProcessCreationParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebProcessDataStoreParameters> {
    static void encode(Encoder&, WebKit::WebProcessDataStoreParameters&&);
    static std::optional<WebKit::WebProcessDataStoreParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebPushD::WebPushDaemonConnectionConfiguration> {
    static void encode(Encoder&, const WebKit::WebPushD::WebPushDaemonConnectionConfiguration&);
    static std::optional<WebKit::WebPushD::WebPushDaemonConnectionConfiguration> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebPushMessage> {
    static void encode(Encoder&, const WebKit::WebPushMessage&);
    static std::optional<WebKit::WebPushMessage> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebUserScriptData> {
    static void encode(Encoder&, const WebKit::WebUserScriptData&);
    static std::optional<WebKit::WebUserScriptData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebUserStyleSheetData> {
    static void encode(Encoder&, const WebKit::WebUserStyleSheetData&);
    static std::optional<WebKit::WebUserStyleSheetData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebScriptMessageHandlerData> {
    static void encode(Encoder&, const WebKit::WebScriptMessageHandlerData&);
    static std::optional<WebKit::WebScriptMessageHandlerData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebsiteDataStoreParameters> {
    static void encode(Encoder&, WebKit::WebsiteDataStoreParameters&&);
    static std::optional<WebKit::WebsiteDataStoreParameters> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebsitePoliciesData> {
    static void encode(Encoder&, const WebKit::WebsitePoliciesData&);
    static std::optional<WebKit::WebsitePoliciesData> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Array> {
    static void encode(Encoder&, const API::Array&);
    static std::optional<Ref<API::Array>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Data> {
    static void encode(Encoder&, const API::Data&);
    static std::optional<Ref<API::Data>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Dictionary> {
    static void encode(Encoder&, const API::Dictionary&);
    static std::optional<Ref<API::Dictionary>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Error> {
    static void encode(Encoder&, const API::Error&);
    static std::optional<Ref<API::Error>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::FrameHandle> {
    static void encode(Encoder&, const API::FrameHandle&);
    static std::optional<Ref<API::FrameHandle>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Size> {
    static void encode(Encoder&, const API::Size&);
    static std::optional<Ref<API::Size>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Point> {
    static void encode(Encoder&, const API::Point&);
    static std::optional<Ref<API::Point>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Rect> {
    static void encode(Encoder&, const API::Rect&);
    static std::optional<Ref<API::Rect>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Boolean> {
    static void encode(Encoder&, const API::Boolean&);
    static std::optional<Ref<API::Boolean>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Double> {
    static void encode(Encoder&, const API::Double&);
    static std::optional<Ref<API::Double>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::UInt64> {
    static void encode(Encoder&, const API::UInt64&);
    static std::optional<Ref<API::UInt64>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Int64> {
    static void encode(Encoder&, const API::Int64&);
    static std::optional<Ref<API::Int64>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::Object> {
    static void encode(Encoder&, const API::Object&);
    static std::optional<Ref<API::Object>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::PageHandle> {
    static void encode(Encoder&, const API::PageHandle&);
    static std::optional<Ref<API::PageHandle>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::String> {
    static void encode(Encoder&, const API::String&);
    static std::optional<Ref<API::String>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::URL> {
    static void encode(Encoder&, const API::URL&);
    static std::optional<Ref<API::URL>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::URLRequest> {
    static void encode(Encoder&, const API::URLRequest&);
    static std::optional<Ref<API::URLRequest>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::URLResponse> {
    static void encode(Encoder&, const API::URLResponse&);
    static std::optional<Ref<API::URLResponse>> decode(Decoder&);
};

template<> struct ArgumentCoder<API::UserContentURLPattern> {
    static void encode(Encoder&, const API::UserContentURLPattern&);
    static std::optional<Ref<API::UserContentURLPattern>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::WebIDBResult> {
    static void encode(Encoder&, WebKit::WebIDBResult&&);
    static std::optional<WebKit::WebIDBResult> decode(Decoder&);
};

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionAlarmParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionAlarmParameters&);
    static std::optional<WebKit::WebExtensionAlarmParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
template<> struct ArgumentCoder<WebKit::WebExtensionBookmarksParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionBookmarksParameters&);
    static std::optional<WebKit::WebExtensionBookmarksParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionCommandParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionCommandParameters&);
    static std::optional<WebKit::WebExtensionCommandParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionContextParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionContextParameters&);
    static std::optional<WebKit::WebExtensionContextParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionControllerParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionControllerParameters&);
    static std::optional<WebKit::WebExtensionControllerParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionCookieParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionCookieParameters&);
    static std::optional<WebKit::WebExtensionCookieParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionCookieFilterParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionCookieFilterParameters&);
    static std::optional<WebKit::WebExtensionCookieFilterParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionScriptInjectionParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionScriptInjectionParameters&);
    static std::optional<WebKit::WebExtensionScriptInjectionParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionScriptInjectionResultParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionScriptInjectionResultParameters&);
    static std::optional<WebKit::WebExtensionScriptInjectionResultParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionRegisteredScriptParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionRegisteredScriptParameters&);
    static std::optional<WebKit::WebExtensionRegisteredScriptParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionFrameParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionFrameParameters&);
    static std::optional<WebKit::WebExtensionFrameParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionMatchedRuleParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionMatchedRuleParameters&);
    static std::optional<WebKit::WebExtensionMatchedRuleParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionMenuItemParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionMenuItemParameters&);
    static std::optional<WebKit::WebExtensionMenuItemParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionMenuItemContextParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionMenuItemContextParameters&);
    static std::optional<WebKit::WebExtensionMenuItemContextParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionMessageSenderParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionMessageSenderParameters&);
    static std::optional<WebKit::WebExtensionMessageSenderParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionMessageTargetParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionMessageTargetParameters&);
    static std::optional<WebKit::WebExtensionMessageTargetParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
template<> struct ArgumentCoder<WebKit::WebExtensionSidebarParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionSidebarParameters&);
    static std::optional<WebKit::WebExtensionSidebarParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionTabParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionTabParameters&);
    static std::optional<WebKit::WebExtensionTabParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionTabQueryParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionTabQueryParameters&);
    static std::optional<WebKit::WebExtensionTabQueryParameters> decode(Decoder&);
};
#endif

#if ENABLE(WK_WEB_EXTENSIONS)
template<> struct ArgumentCoder<WebKit::WebExtensionWindowParameters> {
    static void encode(Encoder&, const WebKit::WebExtensionWindowParameters&);
    static std::optional<WebKit::WebExtensionWindowParameters> decode(Decoder&);
};
#endif

#if ENABLE(GAMEPAD)
template<> struct ArgumentCoder<WebKit::GamepadData> {
    static void encode(Encoder&, const WebKit::GamepadData&);
    static std::optional<WebKit::GamepadData> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::RemoteImageBufferSetConfiguration> {
    static void encode(Encoder&, const WebKit::RemoteImageBufferSetConfiguration&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteImageBufferSetConfiguration&);
    static std::optional<WebKit::RemoteImageBufferSetConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BindGroupDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::BindGroupDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BindGroupDescriptor&);
    static std::optional<WebKit::WebGPU::BindGroupDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BindGroupEntry> {
    static void encode(Encoder&, const WebKit::WebGPU::BindGroupEntry&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BindGroupEntry&);
    static std::optional<WebKit::WebGPU::BindGroupEntry> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BindGroupLayoutDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::BindGroupLayoutDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BindGroupLayoutDescriptor&);
    static std::optional<WebKit::WebGPU::BindGroupLayoutDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BindGroupLayoutEntry> {
    static void encode(Encoder&, const WebKit::WebGPU::BindGroupLayoutEntry&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BindGroupLayoutEntry&);
    static std::optional<WebKit::WebGPU::BindGroupLayoutEntry> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BlendComponent> {
    static void encode(Encoder&, const WebKit::WebGPU::BlendComponent&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BlendComponent&);
    static std::optional<WebKit::WebGPU::BlendComponent> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BlendState> {
    static void encode(Encoder&, const WebKit::WebGPU::BlendState&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BlendState&);
    static std::optional<WebKit::WebGPU::BlendState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BufferBinding> {
    static void encode(Encoder&, const WebKit::WebGPU::BufferBinding&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BufferBinding&);
    static std::optional<WebKit::WebGPU::BufferBinding> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BufferBindingLayout> {
    static void encode(Encoder&, const WebKit::WebGPU::BufferBindingLayout&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BufferBindingLayout&);
    static std::optional<WebKit::WebGPU::BufferBindingLayout> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::BufferDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::BufferDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::BufferDescriptor&);
    static std::optional<WebKit::WebGPU::BufferDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::CanvasConfiguration> {
    static void encode(Encoder&, const WebKit::WebGPU::CanvasConfiguration&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::CanvasConfiguration&);
    static std::optional<WebKit::WebGPU::CanvasConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ColorDict> {
    static void encode(Encoder&, const WebKit::WebGPU::ColorDict&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ColorDict&);
    static std::optional<WebKit::WebGPU::ColorDict> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ColorTargetState> {
    static void encode(Encoder&, const WebKit::WebGPU::ColorTargetState&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ColorTargetState&);
    static std::optional<WebKit::WebGPU::ColorTargetState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::CommandBufferDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::CommandBufferDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::CommandBufferDescriptor&);
    static std::optional<WebKit::WebGPU::CommandBufferDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::CommandEncoderDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::CommandEncoderDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::CommandEncoderDescriptor&);
    static std::optional<WebKit::WebGPU::CommandEncoderDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::CompilationMessage> {
    static void encode(Encoder&, const WebKit::WebGPU::CompilationMessage&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::CompilationMessage&);
    static std::optional<WebKit::WebGPU::CompilationMessage> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ComputePassDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::ComputePassDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ComputePassDescriptor&);
    static std::optional<WebKit::WebGPU::ComputePassDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ComputePassTimestampWrites> {
    static void encode(Encoder&, const WebKit::WebGPU::ComputePassTimestampWrites&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ComputePassTimestampWrites&);
    static std::optional<WebKit::WebGPU::ComputePassTimestampWrites> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ComputePipelineDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::ComputePipelineDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ComputePipelineDescriptor&);
    static std::optional<WebKit::WebGPU::ComputePipelineDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::DepthStencilState> {
    static void encode(Encoder&, const WebKit::WebGPU::DepthStencilState&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::DepthStencilState&);
    static std::optional<WebKit::WebGPU::DepthStencilState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::DeviceDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::DeviceDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::DeviceDescriptor&);
    static std::optional<WebKit::WebGPU::DeviceDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::Extent3DDict> {
    static void encode(Encoder&, const WebKit::WebGPU::Extent3DDict&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::Extent3DDict&);
    static std::optional<WebKit::WebGPU::Extent3DDict> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ExternalTextureBindingLayout> {
    static void encode(Encoder&, const WebKit::WebGPU::ExternalTextureBindingLayout&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ExternalTextureBindingLayout&);
    static std::optional<WebKit::WebGPU::ExternalTextureBindingLayout> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ExternalTextureDescriptor> {
    static void encode(Encoder&, WebKit::WebGPU::ExternalTextureDescriptor&&);
    static std::optional<WebKit::WebGPU::ExternalTextureDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::FragmentState> {
    static void encode(Encoder&, const WebKit::WebGPU::FragmentState&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::FragmentState&);
    static std::optional<WebKit::WebGPU::FragmentState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ImageCopyBuffer> {
    static void encode(Encoder&, const WebKit::WebGPU::ImageCopyBuffer&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ImageCopyBuffer&);
    static std::optional<WebKit::WebGPU::ImageCopyBuffer> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ImageCopyExternalImage> {
    static void encode(Encoder&, const WebKit::WebGPU::ImageCopyExternalImage&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ImageCopyExternalImage&);
    static std::optional<WebKit::WebGPU::ImageCopyExternalImage> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ImageCopyTexture> {
    static void encode(Encoder&, const WebKit::WebGPU::ImageCopyTexture&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ImageCopyTexture&);
    static std::optional<WebKit::WebGPU::ImageCopyTexture> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ImageCopyTextureTagged> {
    static void encode(Encoder&, const WebKit::WebGPU::ImageCopyTextureTagged&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ImageCopyTextureTagged&);
    static std::optional<WebKit::WebGPU::ImageCopyTextureTagged> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ImageDataLayout> {
    static void encode(Encoder&, const WebKit::WebGPU::ImageDataLayout&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ImageDataLayout&);
    static std::optional<WebKit::WebGPU::ImageDataLayout> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::InternalError> {
    static void encode(Encoder&, const WebKit::WebGPU::InternalError&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::InternalError&);
    static std::optional<WebKit::WebGPU::InternalError> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::MultisampleState> {
    static void encode(Encoder&, const WebKit::WebGPU::MultisampleState&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::MultisampleState&);
    static std::optional<WebKit::WebGPU::MultisampleState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ObjectDescriptorBase> {
    static void encode(Encoder&, const WebKit::WebGPU::ObjectDescriptorBase&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ObjectDescriptorBase&);
    static std::optional<WebKit::WebGPU::ObjectDescriptorBase> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::Origin2DDict> {
    static void encode(Encoder&, const WebKit::WebGPU::Origin2DDict&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::Origin2DDict&);
    static std::optional<WebKit::WebGPU::Origin2DDict> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::Origin3DDict> {
    static void encode(Encoder&, const WebKit::WebGPU::Origin3DDict&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::Origin3DDict&);
    static std::optional<WebKit::WebGPU::Origin3DDict> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::OutOfMemoryError> {
    static void encode(Encoder&, const WebKit::WebGPU::OutOfMemoryError&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::OutOfMemoryError&);
    static std::optional<WebKit::WebGPU::OutOfMemoryError> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::PipelineDescriptorBase> {
    static void encode(Encoder&, const WebKit::WebGPU::PipelineDescriptorBase&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::PipelineDescriptorBase&);
    static std::optional<WebKit::WebGPU::PipelineDescriptorBase> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::PipelineLayoutDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::PipelineLayoutDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::PipelineLayoutDescriptor&);
    static std::optional<WebKit::WebGPU::PipelineLayoutDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::PresentationContextDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::PresentationContextDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::PresentationContextDescriptor&);
    static std::optional<WebKit::WebGPU::PresentationContextDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::PrimitiveState> {
    static void encode(Encoder&, const WebKit::WebGPU::PrimitiveState&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::PrimitiveState&);
    static std::optional<WebKit::WebGPU::PrimitiveState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ProgrammableStage> {
    static void encode(Encoder&, const WebKit::WebGPU::ProgrammableStage&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ProgrammableStage&);
    static std::optional<WebKit::WebGPU::ProgrammableStage> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::QuerySetDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::QuerySetDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::QuerySetDescriptor&);
    static std::optional<WebKit::WebGPU::QuerySetDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RenderBundleDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::RenderBundleDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RenderBundleDescriptor&);
    static std::optional<WebKit::WebGPU::RenderBundleDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RenderBundleEncoderDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::RenderBundleEncoderDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RenderBundleEncoderDescriptor&);
    static std::optional<WebKit::WebGPU::RenderBundleEncoderDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RenderPassColorAttachment> {
    static void encode(Encoder&, const WebKit::WebGPU::RenderPassColorAttachment&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RenderPassColorAttachment&);
    static std::optional<WebKit::WebGPU::RenderPassColorAttachment> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RenderPassDepthStencilAttachment> {
    static void encode(Encoder&, const WebKit::WebGPU::RenderPassDepthStencilAttachment&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RenderPassDepthStencilAttachment&);
    static std::optional<WebKit::WebGPU::RenderPassDepthStencilAttachment> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RenderPassDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::RenderPassDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RenderPassDescriptor&);
    static std::optional<WebKit::WebGPU::RenderPassDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RenderPassLayout> {
    static void encode(Encoder&, const WebKit::WebGPU::RenderPassLayout&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RenderPassLayout&);
    static std::optional<WebKit::WebGPU::RenderPassLayout> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RenderPassTimestampWrites> {
    static void encode(Encoder&, const WebKit::WebGPU::RenderPassTimestampWrites&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RenderPassTimestampWrites&);
    static std::optional<WebKit::WebGPU::RenderPassTimestampWrites> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RenderPipelineDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::RenderPipelineDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RenderPipelineDescriptor&);
    static std::optional<WebKit::WebGPU::RenderPipelineDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::RequestAdapterOptions> {
    static void encode(Encoder&, const WebKit::WebGPU::RequestAdapterOptions&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::RequestAdapterOptions&);
    static std::optional<WebKit::WebGPU::RequestAdapterOptions> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::SamplerBindingLayout> {
    static void encode(Encoder&, const WebKit::WebGPU::SamplerBindingLayout&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::SamplerBindingLayout&);
    static std::optional<WebKit::WebGPU::SamplerBindingLayout> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::SamplerDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::SamplerDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::SamplerDescriptor&);
    static std::optional<WebKit::WebGPU::SamplerDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ShaderModuleCompilationHint> {
    static void encode(Encoder&, const WebKit::WebGPU::ShaderModuleCompilationHint&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ShaderModuleCompilationHint&);
    static std::optional<WebKit::WebGPU::ShaderModuleCompilationHint> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ShaderModuleDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::ShaderModuleDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ShaderModuleDescriptor&);
    static std::optional<WebKit::WebGPU::ShaderModuleDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::StencilFaceState> {
    static void encode(Encoder&, const WebKit::WebGPU::StencilFaceState&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::StencilFaceState&);
    static std::optional<WebKit::WebGPU::StencilFaceState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::StorageTextureBindingLayout> {
    static void encode(Encoder&, const WebKit::WebGPU::StorageTextureBindingLayout&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::StorageTextureBindingLayout&);
    static std::optional<WebKit::WebGPU::StorageTextureBindingLayout> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::SupportedFeatures> {
    static void encode(Encoder&, const WebKit::WebGPU::SupportedFeatures&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::SupportedFeatures&);
    static std::optional<WebKit::WebGPU::SupportedFeatures> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::SupportedLimits> {
    static void encode(Encoder&, const WebKit::WebGPU::SupportedLimits&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::SupportedLimits&);
    static std::optional<WebKit::WebGPU::SupportedLimits> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::TextureBindingLayout> {
    static void encode(Encoder&, const WebKit::WebGPU::TextureBindingLayout&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::TextureBindingLayout&);
    static std::optional<WebKit::WebGPU::TextureBindingLayout> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::TextureDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::TextureDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::TextureDescriptor&);
    static std::optional<WebKit::WebGPU::TextureDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::TextureViewDescriptor> {
    static void encode(Encoder&, const WebKit::WebGPU::TextureViewDescriptor&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::TextureViewDescriptor&);
    static std::optional<WebKit::WebGPU::TextureViewDescriptor> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::ValidationError> {
    static void encode(Encoder&, const WebKit::WebGPU::ValidationError&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::ValidationError&);
    static std::optional<WebKit::WebGPU::ValidationError> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::VertexAttribute> {
    static void encode(Encoder&, const WebKit::WebGPU::VertexAttribute&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::VertexAttribute&);
    static std::optional<WebKit::WebGPU::VertexAttribute> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::VertexBufferLayout> {
    static void encode(Encoder&, const WebKit::WebGPU::VertexBufferLayout&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::VertexBufferLayout&);
    static std::optional<WebKit::WebGPU::VertexBufferLayout> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::WebGPU::VertexState> {
    static void encode(Encoder&, const WebKit::WebGPU::VertexState&);
    static void encode(StreamConnectionEncoder&, const WebKit::WebGPU::VertexState&);
    static std::optional<WebKit::WebGPU::VertexState> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::WebsiteData> {
    static void encode(Encoder&, const WebKit::WebsiteData&);
    static std::optional<WebKit::WebsiteData> decode(Decoder&);
};

#if ENABLE(WEBXR)
template<> struct ArgumentCoder<PlatformXR::RequestData> {
    static void encode(Encoder&, const PlatformXR::RequestData&);
    static std::optional<PlatformXR::RequestData> decode(Decoder&);
};
#endif

#if ENABLE(WEBXR)
template<> struct ArgumentCoder<PlatformXR::FrameData> {
    static void encode(Encoder&, PlatformXR::FrameData&&);
    static std::optional<PlatformXR::FrameData> decode(Decoder&);
};
#endif

#if ENABLE(WEBXR)
template<> struct ArgumentCoder<WebKit::XRDeviceInfo> {
    static void encode(Encoder&, const WebKit::XRDeviceInfo&);
    static std::optional<WebKit::XRDeviceInfo> decode(Decoder&);
};
#endif

#if (ENABLE(WEBXR)) && (USE(OPENXR))
template<> struct ArgumentCoder<WebKit::XRDeviceLayer> {
    static void encode(Encoder&, const WebKit::XRDeviceLayer&);
    static std::optional<WebKit::XRDeviceLayer> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::GPUProcessConnectionInfo> {
    static void encode(Encoder&, const WebKit::GPUProcessConnectionInfo&);
    static std::optional<WebKit::GPUProcessConnectionInfo> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::BufferIdentifierSet> {
    static void encode(Encoder&, const WebKit::BufferIdentifierSet&);
    static void encode(StreamConnectionEncoder&, const WebKit::BufferIdentifierSet&);
    static std::optional<WebKit::BufferIdentifierSet> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && PLATFORM(COCOA)
template<> struct ArgumentCoder<WebKit::ImageBufferSetPrepareBufferForDisplayInputData> {
    static void encode(Encoder&, const WebKit::ImageBufferSetPrepareBufferForDisplayInputData&);
    static void encode(StreamConnectionEncoder&, const WebKit::ImageBufferSetPrepareBufferForDisplayInputData&);
    static std::optional<WebKit::ImageBufferSetPrepareBufferForDisplayInputData> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && PLATFORM(COCOA)
template<> struct ArgumentCoder<WebKit::ImageBufferSetPrepareBufferForDisplayOutputData> {
    static void encode(Encoder&, WebKit::ImageBufferSetPrepareBufferForDisplayOutputData&&);
    static std::optional<WebKit::ImageBufferSetPrepareBufferForDisplayOutputData> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::MediaOverridesForTesting> {
    static void encode(Encoder&, const WebKit::MediaOverridesForTesting&);
    static std::optional<WebKit::MediaOverridesForTesting> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::MediaTimeUpdateData> {
    static void encode(Encoder&, const WebKit::MediaTimeUpdateData&);
    static std::optional<WebKit::MediaTimeUpdateData> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && USE(AUDIO_SESSION)
template<> struct ArgumentCoder<WebKit::RemoteAudioSessionConfiguration> {
    static void encode(Encoder&, const WebKit::RemoteAudioSessionConfiguration&);
    static std::optional<WebKit::RemoteAudioSessionConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
template<> struct ArgumentCoder<WebKit::RemoteCDMConfiguration> {
    static void encode(Encoder&, const WebKit::RemoteCDMConfiguration&);
    static std::optional<WebKit::RemoteCDMConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(ENCRYPTED_MEDIA)
template<> struct ArgumentCoder<WebKit::RemoteCDMInstanceConfiguration> {
    static void encode(Encoder&, const WebKit::RemoteCDMInstanceConfiguration&);
    static std::optional<WebKit::RemoteCDMInstanceConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS)
template<> struct ArgumentCoder<WebKit::RemoteMediaPlayerConfiguration> {
    static void encode(Encoder&, const WebKit::RemoteMediaPlayerConfiguration&);
    static std::optional<WebKit::RemoteMediaPlayerConfiguration> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::RemoteMediaPlayerState> {
    static void encode(Encoder&, const WebKit::RemoteMediaPlayerState&);
    static std::optional<WebKit::RemoteMediaPlayerState> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::RemoteVideoFrameProxyProperties> {
    static void encode(Encoder&, const WebKit::RemoteVideoFrameProxyProperties&);
    static void encode(StreamConnectionEncoder&, const WebKit::RemoteVideoFrameProxyProperties&);
    static std::optional<WebKit::RemoteVideoFrameProxyProperties> decode(Decoder&);
};
#endif

#if ENABLE(GPU_PROCESS) && PLATFORM(COCOA) && ENABLE(VIDEO)
template<> struct ArgumentCoder<WebKit::SharedVideoFrame> {
    static void encode(Encoder&, WebKit::SharedVideoFrame&&);
    static std::optional<WebKit::SharedVideoFrame> decode(Decoder&);
};
#endif

#if ENABLE(MEDIA_STREAM)
template<> struct ArgumentCoder<WebKit::MediaDeviceSandboxExtensions> {
    static void encode(Encoder&, WebKit::MediaDeviceSandboxExtensions&&);
    static std::optional<WebKit::MediaDeviceSandboxExtensions> decode(Decoder&);
};
#endif

#if ENABLE(MODEL_PROCESS)
template<> struct ArgumentCoder<WebKit::ModelProcessConnectionInfo> {
    static void encode(Encoder&, const WebKit::ModelProcessConnectionInfo&);
    static std::optional<WebKit::ModelProcessConnectionInfo> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebKit::NetworkProcessConnectionInfo> {
    static void encode(Encoder&, WebKit::NetworkProcessConnectionInfo&&);
    static std::optional<WebKit::NetworkProcessConnectionInfo> decode(Decoder&);
};

#if ENABLE(SPEECH_SYNTHESIS)
template<> struct ArgumentCoder<WebKit::WebSpeechSynthesisVoice> {
    static void encode(Encoder&, const WebKit::WebSpeechSynthesisVoice&);
    static std::optional<WebKit::WebSpeechSynthesisVoice> decode(Decoder&);
};
#endif

#if USE(CURL)
template<> struct ArgumentCoder<WebCore::CurlProxySettings> {
    static void encode(Encoder&, const WebCore::CurlProxySettings&);
    static std::optional<WebCore::CurlProxySettings> decode(Decoder&);
};
#endif

#if USE(GRAPHICS_LAYER_WC)
template<> struct ArgumentCoder<WebKit::WCBackingStore> {
    static void encode(Encoder&, const WebKit::WCBackingStore&);
    static std::optional<WebKit::WCBackingStore> decode(Decoder&);
};
#endif

#if USE(GRAPHICS_LAYER_WC)
template<> struct ArgumentCoder<WebKit::WCTileUpdate> {
    static void encode(Encoder&, const WebKit::WCTileUpdate&);
    static std::optional<WebKit::WCTileUpdate> decode(Decoder&);
};
#endif

#if USE(GRAPHICS_LAYER_WC)
template<> struct ArgumentCoder<WebKit::WCLayerUpdateInfo> {
    static void encode(Encoder&, const WebKit::WCLayerUpdateInfo&);
    static std::optional<WebKit::WCLayerUpdateInfo> decode(Decoder&);
};
#endif

#if USE(GRAPHICS_LAYER_WC)
template<> struct ArgumentCoder<WebKit::WCUpdateInfo> {
    static void encode(Encoder&, const WebKit::WCUpdateInfo&);
    static std::optional<WebKit::WCUpdateInfo> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WTF::Win32Handle> {
    static void encode(Encoder&, WTF::Win32Handle&&);
    static std::optional<WTF::Win32Handle> decode(Decoder&);
};

#if USE(SKIA)
template<> struct ArgumentCoder<hb_feature_t> {
    static void encode(Encoder&, const hb_feature_t&);
    static std::optional<hb_feature_t> decode(Decoder&);
};
#endif

#if USE(SKIA)
template<> struct ArgumentCoder<sk_sp<SkColorSpace>> {
    static void encode(Encoder&, const sk_sp<SkColorSpace>&);
    static void encode(StreamConnectionEncoder&, const sk_sp<SkColorSpace>&);
    static std::optional<sk_sp<SkColorSpace>> decode(Decoder&);
};
#endif

#if USE(SKIA)
template<> struct ArgumentCoder<sk_sp<SkData>> {
    static void encode(Encoder&, const sk_sp<SkData>&);
    static void encode(StreamConnectionEncoder&, const sk_sp<SkData>&);
    static std::optional<sk_sp<SkData>> decode(Decoder&);
};
#endif

#if USE(SKIA)
template<> struct ArgumentCoder<SkString> {
    static void encode(Encoder&, const SkString&);
    static std::optional<SkString> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<SkFontStyle> {
    static void encode(Encoder&, const SkFontStyle&);
    static std::optional<SkFontStyle> decode(Decoder&);
};

#if USE(SKIA)
template<> struct ArgumentCoder<WebCore::FontPlatformSerializedCreationData> {
    static void encode(Encoder&, const WebCore::FontPlatformSerializedCreationData&);
    static std::optional<WebCore::FontPlatformSerializedCreationData> decode(Decoder&);
};
#endif

#if USE(SKIA)
template<> struct ArgumentCoder<WebCore::FontPlatformSerializedData> {
    static void encode(Encoder&, const WebCore::FontPlatformSerializedData&);
    static std::optional<WebCore::FontPlatformSerializedData> decode(Decoder&);
};
#endif

template<> struct ArgumentCoder<WebCore::DocumentSyncData> {
    static void encode(Encoder&, const WebCore::DocumentSyncData&);
    static std::optional<Ref<WebCore::DocumentSyncData>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::FrameTreeSyncData> {
    static void encode(Encoder&, const WebCore::FrameTreeSyncData&);
    static std::optional<Ref<WebCore::FrameTreeSyncData>> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::ProcessSyncData> {
    static void encode(Encoder&, const WebCore::ProcessSyncData&);
    static std::optional<WebCore::ProcessSyncData> decode(Decoder&);
};

template<> struct ArgumentCoder<WebKit::SharedPreferencesForWebProcess> {
    static void encode(Encoder&, const WebKit::SharedPreferencesForWebProcess&);
    static std::optional<WebKit::SharedPreferencesForWebProcess> decode(Decoder&);
};

} // namespace IPC


namespace WTF {

#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> bool isValidEnum<WebCore::TextDrawingMode>(uint8_t);
#endif
template<> bool isValidEnum<WebKit::StorageAccessStatus>(uint8_t);
template<> bool isValidEnum<WebKit::PCM::MessageType>(uint8_t);
template<> bool isValidEnum<WebKit::FileSystemStorageError>(uint8_t);
template<> bool isValidOptionSet<IPC::MessageFlags>(OptionSet<IPC::MessageFlags>);
#if HAVE(PER_APP_ACCESSIBILITY_PREFERENCES)
template<> bool isValidEnum<WebKit::WebKitAXValueState>(int);
#endif
template<> bool isValidEnum<WebKit::BackgroundFetchChange>(uint8_t);
template<> bool isValidEnum<WebKit::CacheModel>(uint8_t);
template<> bool isValidOptionSet<WebKit::ContentWorldOption>(OptionSet<WebKit::ContentWorldOption>);
template<> bool isValidEnum<WebKit::CoordinateSystem>(uint8_t);
template<> bool isValidEnum<Inspector::DebuggableType>(uint8_t);
template<> bool isValidEnum<WebKit::DragControllerAction>(uint8_t);
template<> bool isValidEnum<WebKit::EditingRangeIsRelativeTo>(uint8_t);
template<> bool isValidEnum<WebKit::ListType>(uint8_t);
template<> bool isValidEnum<WebKit::TextAlignment>(uint8_t);
template<> bool isValidOptionSet<WebKit::TypingAttribute>(OptionSet<WebKit::TypingAttribute>);
template<> bool isValidEnum<WebKit::InputType>(uint8_t);
template<> bool isValidOptionSet<WebKit::SnapshotOption>(OptionSet<WebKit::SnapshotOption>);
#if ENABLE(INSPECTOR_EXTENSIONS)
template<> bool isValidEnum<Inspector::ExtensionError>(uint8_t);
#endif
template<> bool isValidEnum<JSC::MessageSource>(uint8_t);
template<> bool isValidEnum<JSC::MessageType>(uint8_t);
template<> bool isValidEnum<JSC::MessageLevel>(uint8_t);
template<> bool isValidEnum<JSC::SourceTaintedOrigin>(uint8_t);
template<> bool isValidEnum<Inspector::InspectorTargetType>(uint8_t);
template<> bool isValidEnum<WebKit::MediaPlaybackState>(uint8_t);
#if USE(LIBWEBRTC)
template<> bool isValidEnum<WebKit::WebRTCNetwork::EcnMarking>(int);
#endif
#if (USE(LIBWEBRTC)) && (USE(LIBWEBRTC) && PLATFORM(COCOA))
template<> bool isValidEnum<webrtc::WebKitEncodedVideoRotation>(uint8_t);
#endif
#if (USE(LIBWEBRTC)) && (USE(LIBWEBRTC) && PLATFORM(COCOA))
template<> bool isValidEnum<webrtc::VideoFrameType>(int);
#endif
#if (USE(LIBWEBRTC)) && (USE(LIBWEBRTC) && PLATFORM(COCOA))
template<> bool isValidEnum<webrtc::VideoContentType>(uint8_t);
#endif
template<> bool isValidEnum<WebKit::RemoteWorkerType>(uint8_t);
template<> bool isValidEnum<WebKit::SameDocumentNavigationType>(uint8_t);
template<> bool isValidEnum<WebKit::SyntheticEditingCommandType>(uint8_t );
template<> bool isValidEnum<WebCore::FontWidthVariant>(uint8_t);
template<> bool isValidEnum<WebCore::Kerning>(uint8_t);
template<> bool isValidEnum<WebCore::FontStyleAxis>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantEastAsianVariant>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantEastAsianWidth>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantEastAsianRuby>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantLigatures>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantPosition>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantCaps>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantNumericFigure>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantNumericSpacing>(uint8_t);
template<> bool isValidEnum<WebCore::FontVariantNumericFraction>(uint8_t);
template<> bool isValidEnum<WebCore::TextRenderingMode>(uint8_t);
template<> bool isValidEnum<WebCore::FontSmoothingMode>(uint8_t);
template<> bool isValidOptionSet<WebKit::TextCheckerState>(OptionSet<WebKit::TextCheckerState>);
#if ENABLE(IMAGE_ANALYSIS)
template<> bool isValidEnum<WebKit::TextRecognitionUpdateResult>(uint8_t);
#endif
#if ENABLE(UI_SIDE_COMPOSITING)
template<> bool isValidOptionSet<WebKit::ViewStabilityFlag>(OptionSet<WebKit::ViewStabilityFlag>);
#endif
template<> bool isValidEnum<WTF::SystemMemoryPressureStatus>(uint8_t);
template<> bool isValidEnum<WTFLogLevel>(uint8_t);
#if ENABLE(APPLE_PAY)
template<> bool isValidEnum<WebCore::ApplePayFeature>(uint8_t);
#endif
#if ENABLE(APPLE_PAY)
template<> bool isValidEnum<WebCore::ApplePayPaymentTiming>(uint8_t);
#endif
#if ENABLE(APPLE_PAY_RECURRING_LINE_ITEM)
template<> bool isValidEnum<WebCore::ApplePayRecurringPaymentDateUnit>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::ContactProperty>(uint8_t);
template<> bool isValidEnum<WebCore::CookieConsentDecisionResult>(uint8_t);
template<> bool isValidEnum<WebCore::IDBResultType>(uint8_t);
template<> bool isValidEnum<WebCore::IDBTransactionDurability>(uint8_t);
template<> bool isValidEnum<WebCore::IDBTransactionMode>(uint8_t);
#if ENABLE(MEDIA_SESSION)
template<> bool isValidEnum<WebCore::MediaSessionAction>(uint8_t);
#endif
#if ENABLE(MEDIA_SESSION)
template<> bool isValidEnum<WebCore::MediaSessionPlaybackState>(uint8_t);
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
template<> bool isValidEnum<WebCore::MediaSessionCoordinatorState>(uint8_t);
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
template<> bool isValidEnum<WebCore::MediaSessionReadyState>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::RTCErrorDetailType>(uint8_t);
template<> bool isValidEnum<WebCore::PermissionName>(uint8_t);
template<> bool isValidEnum<WebCore::PermissionQuerySource>(uint8_t);
template<> bool isValidEnum<WebCore::PermissionState>(uint8_t);
template<> bool isValidEnum<WebCore::PushPermissionState>(uint8_t);
template<> bool isValidEnum<WebCore::AutofillFieldName>(uint8_t);
template<> bool isValidEnum<WebCore::EnterKeyHint>(uint8_t);
template<> bool isValidEnum<WebCore::DownloadableBinaryFontTrustedTypes>(uint8_t);
template<> bool isValidEnum<WebCore::LoadSchedulingMode>(uint8_t);
template<> bool isValidEnum<WebCore::ServiceWorkersMode>(uint8_t);
template<> bool isValidEnum<WebCore::ShouldTreatAsContinuingLoad>(uint8_t);
template<> bool isValidEnum<WebCore::ContentSecurityPolicyModeForExtension>(uint8_t);
template<> bool isValidEnum<WebCore::MediaProducerMediaCaptureKind>(uint8_t);
template<> bool isValidEnum<WebCore::ScreenOrientationType>(uint8_t);
template<> bool isValidEnum<WebCore::StorageBlockingPolicy>(uint8_t);
template<> bool isValidEnum<WebCore::HTTPSByDefaultMode>(uint8_t);
#if USE(APPKIT)
template<> bool isValidEnum<WebCore::AppKitControlSystemImageType>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::ScrollGranularity>(uint8_t);
template<> bool isValidEnum<WebCore::IndexedDB::KeyType>(int8_t);
template<> bool isValidEnum<WebCore::IndexedDB::CursorDirection>(uint8_t);
template<> bool isValidEnum<WebCore::IndexedDB::ObjectStoreOverwriteMode>(uint8_t);
template<> bool isValidEnum<WebCore::IndexedDB::RequestType>(uint8_t);
template<> bool isValidOptionSet<WebCore::NavigatorAPIsAccessed>(OptionSet<WebCore::NavigatorAPIsAccessed>);
template<> bool isValidOptionSet<WebCore::ScreenAPIsAccessed>(OptionSet<WebCore::ScreenAPIsAccessed>);
template<> bool isValidOptionSet<WebCore::SandboxFlag>(OptionSet<WebCore::SandboxFlag>);
template<> bool isValidEnum<WebCore::ViewportFit>(uint8_t);
template<> bool isValidEnum<WebCore::PositionType>(uint8_t);
#if ENABLE(APPLE_PAY)
template<> bool isValidEnum<WebCore::ApplePayErrorContactField>(uint8_t);
#endif
#if ENABLE(APPLE_PAY)
template<> bool isValidEnum<WebCore::ApplePayContactField>(uint8_t);
#endif
#if ENABLE(APPLE_PAY)
template<> bool isValidEnum<WebCore::ApplePayErrorCode>(uint8_t);
#endif
#if ENABLE(APPLE_PAY_INSTALLMENTS)
template<> bool isValidEnum<WebCore::ApplePayInstallmentItemType>(uint8_t);
#endif
#if ENABLE(APPLE_PAY_INSTALLMENTS)
template<> bool isValidEnum<WebCore::ApplePayInstallmentRetailChannel>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::ScreenOrientationLockType>(uint8_t);
template<> bool isValidEnum<WebCore::DOMCacheEngine::Error>(uint8_t);
template<> bool isValidEnum<WebCore::VideoEncoderScalabilityMode>(uint8_t);
template<> bool isValidEnum<WebCore::SpeechRecognitionErrorType>(uint8_t);
#if ENABLE(WEB_AUTHN)
template<> bool isValidEnum<WebCore::AttestationConveyancePreference>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::RenderingMode>(uint8_t);
template<> bool isValidEnum<WebCore::RenderingPurpose>(uint8_t);
template<> bool isValidEnum<WebCore::ContentsFormat>(uint8_t);
template<> bool isValidEnum<WebCore::IsLoggedIn>(uint8_t);
template<> bool isValidEnum<WebCore::AutoplayEvent>(uint8_t);
template<> bool isValidEnum<WebCore::InputMode>(uint8_t);
template<> bool isValidEnum<WebCore::StoredCredentialsPolicy>(uint8_t);
template<> bool isValidEnum<WebCore::PreflightPolicy>(uint8_t);
template<> bool isValidEnum<WTFLogChannelState>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollSnapStrictness>(uint8_t);
template<> bool isValidEnum<WebCore::LengthType>(uint8_t);
template<> bool isValidEnum<WebCore::OverscrollBehavior>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollPinningBehavior>(uint8_t);
template<> bool isValidEnum<WebCore::WheelScrollGestureState>(uint8_t);
template<> bool isValidEnum<WebCore::DiagnosticLoggingDomain>(uint8_t);
template<> bool isValidEnum<WebCore::MediaCaptureType>(uint8_t);
#if ENABLE(ATTACHMENT_ELEMENT)
template<> bool isValidEnum<WebCore::AttachmentAssociatedElementType>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::ColorSpace>(uint8_t);
template<> bool isValidEnum<WebCore::VideoCodecType>(uint8_t);
#if HAVE(SUPPORT_HDR_DISPLAY)
template<> bool isValidOptionSet<WebCore::ContentsFormat>(OptionSet<WebCore::ContentsFormat>);
#endif
#if ENABLE(WEB_AUTHN)
template<> bool isValidEnum<WebCore::AuthenticatorTransport>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::DataListSuggestionActivationType>(uint8_t);
template<> bool isValidEnum<WebCore::AlphaPremultiplication>(uint8_t);
template<> bool isValidEnum<WebCore::PixelFormat>(uint8_t);
template<> bool isValidEnum<WebCore::ImageBufferPixelFormat>(uint8_t);
template<> bool isValidEnum<WebCore::TextIndicatorLifetime>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollElasticity>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollbarMode>(uint8_t);
template<> bool isValidEnum<WebCore::NativeScrollbarVisibility>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollUpdateType>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollingLayerPositionAction>(uint8_t);
template<> bool isValidOptionSet<WebCore::WheelEventProcessingSteps>(OptionSet<WebCore::WheelEventProcessingSteps>);
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> bool isValidEnum<WebCore::GraphicsContextGLPowerPreference>(uint8_t);
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> bool isValidEnum<WebCore::GraphicsContextGLSimulatedCreationFailure>(uint8_t);
#endif
#if ENABLE(GPU_PROCESS) && ENABLE(WEBGL)
template<> bool isValidEnum<WebCore::GraphicsContextGLSimulatedEventForTesting>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::CSSBoxType>(uint8_t);
#if ENABLE(WEB_AUTHN)
template<> bool isValidEnum<WebCore::UserVerificationRequirement>(uint8_t);
#endif
#if ENABLE(WEB_AUTHN)
template<> bool isValidEnum<WebCore::ResidentKeyRequirement>(uint8_t);
#endif
#if ENABLE(WEB_AUTHN)
template<> bool isValidEnum<WebCore::AuthenticatorAttachment>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::ResourceRequestCachePolicy>(uint8_t);
template<> bool isValidEnum<WebCore::ResourceLoadPriority>(uint8_t);
template<> bool isValidEnum<WebCore::ResourceResponseSource>(uint8_t);
template<> bool isValidEnum<WebCore::ReferrerPolicy>(uint8_t);
template<> bool isValidEnum<WebCore::FetchOptionsDestination>(uint8_t);
template<> bool isValidEnum<WebCore::FetchOptionsMode>(uint8_t);
template<> bool isValidEnum<WebCore::FetchOptionsCredentials>(uint8_t);
template<> bool isValidEnum<WebCore::FetchOptionsCache>(uint8_t);
template<> bool isValidEnum<WebCore::FetchOptionsRedirect>(uint8_t);
template<> bool isValidEnum<WebCore::FetchHeadersGuard>(uint8_t);
template<> bool isValidEnum<WebCore::StyleAppearance>(uint8_t);
#if ENABLE(APPLE_PAY)
template<> bool isValidEnum<WebCore::ApplePayButtonType>(uint8_t);
#endif
#if ENABLE(APPLE_PAY)
template<> bool isValidEnum<WebCore::ApplePayButtonStyle>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::ModalContainerDecision>(uint8_t);
template<> bool isValidOptionSet<WebCore::AutoplayEventFlags>(OptionSet<WebCore::AutoplayEventFlags>);
template<> bool isValidEnum<WebCore::FocusDirection>(uint8_t);
#if ENABLE(GAMEPAD)
template<> bool isValidEnum<WebCore::GamepadHapticEffectType>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::DOMPasteAccessCategory>(uint8_t);
template<> bool isValidEnum<WebCore::DOMPasteAccessPolicy>(uint8_t);
template<> bool isValidEnum<WebCore::DOMPasteAccessResponse>(uint8_t);
template<> bool isValidEnum<WebCore::DeviceOrientationOrMotionPermissionState>(uint8_t);
template<> bool isValidEnum<WebCore::VerticalAlignChange>(uint8_t);
template<> bool isValidEnum<WebCore::TextGranularity>(uint8_t);
template<> bool isValidEnum<WebCore::WritingDirection>(uint8_t);
template<> bool isValidEnum<WebCore::SelectionDirection>(uint8_t);
#if ENABLE(DATA_DETECTION)
template<> bool isValidOptionSet<WebCore::DataDetectorType>(OptionSet<WebCore::DataDetectorType>);
#endif
template<> bool isValidEnum<WebCore::AutocapitalizeType>(uint8_t);
#if ENABLE(ASYNC_SCROLLING)
template<> bool isValidOptionSet<WebCore::ScrollingStateNodeProperty>(OptionSet<WebCore::ScrollingStateNodeProperty>);
#endif
#if ENABLE(ENCRYPTED_MEDIA)
template<> bool isValidEnum<WebCore::CDMSessionType>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::MediaDecodingType>(uint8_t);
#if ENABLE(VIDEO)
template<> bool isValidOptionSet<WebCore::VideoMediaSampleRendererPreference>(OptionSet<WebCore::VideoMediaSampleRendererPreference>);
#endif
template<> bool isValidEnum<WebCore::MediaPlayerNetworkState>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerReadyState>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerMovieLoadType>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerPreload>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerVideoGravity>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerSupportsType>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerBufferingPolicy>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerMediaEngineIdentifier>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerWirelessPlaybackTargetType>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerPitchCorrectionAlgorithm>(uint8_t);
template<> bool isValidEnum<WebCore::MediaPlayerSoundStageSize>(uint8_t);
template<> bool isValidEnum<WebCore::SpeechRecognitionUpdateType>(uint8_t);
template<> bool isValidEnum<WebCore::CompositeOperator>(uint8_t);
template<> bool isValidEnum<WebCore::BlendMode>(uint8_t);
template<> bool isValidEnum<WebCore::GradientSpreadMethod>(uint8_t);
template<> bool isValidEnum<WebCore::InterpolationQuality>(uint8_t);
#if ENABLE(VIDEO)
template<> bool isValidEnum<WebCore::VideoFrameRotation>(uint16_t);
#endif
template<> bool isValidEnum<WebCore::ColorInterpolationColorSpace>(uint8_t);
template<> bool isValidEnum<WebCore::HueInterpolationMethod>(uint8_t);
#if USE(AUDIO_SESSION)
template<> bool isValidEnum<WebCore::RouteSharingPolicy>(uint8_t);
#endif
#if USE(AUDIO_SESSION)
template<> bool isValidEnum<WebCore::AudioSessionCategory>(uint8_t);
#endif
#if USE(AUDIO_SESSION)
template<> bool isValidEnum<WebCore::AudioSessionMode>(uint8_t);
#endif
#if USE(AUDIO_SESSION)
template<> bool isValidEnum<WebCore::AudioSessionSoundStageSize>(uint8_t);
#endif
#if USE(AUDIO_SESSION)
template<> bool isValidEnum<WebCore::AudioSessionRoutingArbitrationError>(uint8_t);
#endif
#if ENABLE(ENCRYPTED_MEDIA)
template<> bool isValidEnum<WebCore::CDMKeyStatus>(uint8_t);
#endif
#if ENABLE(ENCRYPTED_MEDIA)
template<> bool isValidEnum<WebCore::CDMMessageType>(uint8_t);
#endif
#if ENABLE(ENCRYPTED_MEDIA)
template<> bool isValidEnum<WebCore::CDMRequirement>(uint8_t);
#endif
#if ENABLE(ENCRYPTED_MEDIA)
template<> bool isValidEnum<WebCore::CDMInstanceSessionLoadFailure>(uint8_t);
#endif
#if ENABLE(WEB_RTC)
template<> bool isValidEnum<WebCore::RTCDataChannelState>(uint8_t);
#endif
#if ENABLE(WEB_RTC)
template<> bool isValidEnum<WebCore::RTCPriorityType>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::LineCap>(uint8_t);
template<> bool isValidEnum<WebCore::LineJoin>(uint8_t);
template<> bool isValidEnum<WebCore::StrokeStyle>(uint8_t);
template<> bool isValidOptionSet<WebCore::TextDrawingMode>(OptionSet<WebCore::TextDrawingMode>);
template<> bool isValidEnum<WebCore::DecodingMode>(uint8_t);
template<> bool isValidEnum<WebCore::DocumentMarkerLineStyleMode>(uint8_t);
template<> bool isValidEnum<WebCore::DrawsHDRContent>(uint8_t);
template<> bool isValidEnum<WebCore::CrossOriginOpenerPolicyValue>(uint8_t);
template<> bool isValidEnum<WebCore::HTTPCookieAcceptPolicy>(uint8_t);
template<> bool isValidEnum<WebCore::NetworkLoadPriority>(uint8_t);
template<> bool isValidEnum<WebCore::PrivacyStance>(uint8_t);
template<> bool isValidEnum<WebCore::ThirdPartyCookieBlockingMode>(uint8_t);
template<> bool isValidEnum<WebCore::FirstPartyWebsiteDataRemovalMode>(uint8_t);
template<> bool isValidOptionSet<WebCore::DragApplicationFlags>(OptionSet<WebCore::DragApplicationFlags>);
template<> bool isValidOptionSet<WebCore::TextCheckingType>(OptionSet<WebCore::TextCheckingType>);
template<> bool isValidEnum<WebCore::ServiceWorkerClientType>(uint8_t);
template<> bool isValidEnum<WebCore::ServiceWorkerJobType>(uint8_t);
template<> bool isValidEnum<WebCore::ServiceWorkerRegistrationState>(uint8_t);
template<> bool isValidEnum<WebCore::ServiceWorkerState>(uint8_t);
template<> bool isValidEnum<WebCore::ServiceWorkerClientFrameType>(uint8_t);
template<> bool isValidEnum<WebCore::ServiceWorkerUpdateViaCache>(uint8_t);
template<> bool isValidEnum<WebCore::RouterSourceEnum>(uint8_t);
template<> bool isValidEnum<WebCore::StorageAccessWasGranted>(uint8_t);
#if ENABLE(MEDIA_STREAM)
template<> bool isValidEnum<WebCore::MediaConstraintType>(uint8_t);
#endif
#if ENABLE(MEDIA_STREAM)
template<> bool isValidEnum<WebCore::VideoFacingMode>(uint8_t);
#endif
#if ENABLE(MEDIA_STREAM)
template<> bool isValidEnum<WebCore::DisplaySurfaceType>(uint8_t);
#endif
#if ENABLE(MEDIA_STREAM)
template<> bool isValidEnum<WebCore::MeteringMode>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::PlatformVideoColorPrimaries>(uint8_t);
template<> bool isValidEnum<WebCore::PlatformVideoTransferCharacteristics>(uint8_t);
template<> bool isValidEnum<WebCore::PlatformVideoMatrixCoefficients>(uint8_t);
#if ENABLE(VIDEO)
template<> bool isValidEnum<WebCore::VideoProjectionMetadataKind>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::PolicyAction>(uint8_t);
template<> bool isValidOptionSet<WebCore::ReloadOption>(OptionSet<WebCore::ReloadOption>);
template<> bool isValidEnum<WebCore::FrameLoadType>(uint8_t);
template<> bool isValidEnum<WebCore::NavigationType>(uint8_t);
template<> bool isValidEnum<WebCore::BrowsingContextGroupSwitchDecision>(uint8_t);
template<> bool isValidEnum<WebCore::ShouldOpenExternalURLsPolicy>(uint8_t);
template<> bool isValidEnum<WebCore::ScheduleLocationChangeResult>(uint8_t);
template<> bool isValidEnum<WebCore::MouseEventPolicy>(uint8_t);
template<> bool isValidEnum<WebCore::ColorSchemePreference>(uint8_t);
template<> bool isValidOptionSet<WebCore::AdvancedPrivacyProtections>(OptionSet<WebCore::AdvancedPrivacyProtections>);
template<> bool isValidEnum<WebCore::ViolationReportType>(uint8_t);
template<> bool isValidEnum<WebCore::LinkIconType>(uint8_t);
template<> bool isValidEnum<WebCore::PasteboardItemPresentationStyle>(uint8_t);
#if HAVE(SCREEN_CAPTURE_KIT)
template<> bool isValidEnum<WebCore::DisplayCapturePromptType>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::TextIndicatorPresentationTransition>(uint8_t);
template<> bool isValidOptionSet<WebCore::TextIndicatorOption>(OptionSet<WebCore::TextIndicatorOption>);
template<> bool isValidEnum<WebCore::StorageType>(uint8_t);
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> bool isValidEnum<WebCore::TransformBox>(uint8_t);
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> bool isValidOptionSet<WebCore::AcceleratedEffectProperty>(OptionSet<WebCore::AcceleratedEffectProperty>);
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> bool isValidEnum<WebCore::WebAnimationType>(uint8_t);
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> bool isValidEnum<WebCore::FillMode>(uint8_t);
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> bool isValidEnum<WebCore::PlaybackDirection>(uint8_t);
#endif
#if ENABLE(THREADED_ANIMATION_RESOLUTION)
template<> bool isValidEnum<WebCore::CompositeOperation>(uint8_t);
#endif
#if PLATFORM(MAC)
template<> bool isValidEnum<WebCore::CaretAnimatorType>(uint8_t);
#endif
#if ENABLE(GPU_PROCESS)
template<> bool isValidEnum<WebCore::ShapeDetection::BarcodeFormat>(uint8_t);
#endif
#if ENABLE(GPU_PROCESS)
template<> bool isValidEnum<WebCore::ShapeDetection::LandmarkType>(uint8_t);
#endif
template<> bool isValidOptionSet<WebCore::RenderAsTextFlag>(OptionSet<WebCore::RenderAsTextFlag>);
template<> bool isValidOptionSet<WebCore::LayerTreeAsTextOptions>(OptionSet<WebCore::LayerTreeAsTextOptions>);
template<> bool isValidEnum<WebCore::TextExtraction::ContainerType>(uint8_t);
#if ENABLE(WRITING_TOOLS)
template<> bool isValidEnum<WebCore::WritingTools::Behavior>(uint8_t);
#endif
#if ENABLE(WRITING_TOOLS)
template<> bool isValidEnum<WebCore::WritingTools::Action>(uint8_t);
#endif
#if ENABLE(WRITING_TOOLS)
template<> bool isValidEnum<WebCore::WritingTools::SessionType>(uint8_t);
#endif
#if ENABLE(WRITING_TOOLS)
template<> bool isValidEnum<WebCore::WritingTools::SessionCompositionType>(uint8_t);
#endif
#if ENABLE(WRITING_TOOLS)
template<> bool isValidEnum<WebCore::WritingTools::TextSuggestionState>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::WebGPU::TextureFormat>(uint8_t);
#if ENABLE(MEDIA_STREAM)
template<> bool isValidEnum<WebCore::MediaAccessDenialReason>(uint8_t);
#endif
#if ENABLE(MEDIA_STREAM)
template<> bool isValidEnum<WebCore::FillLightMode>(uint8_t);
#endif
#if ENABLE(MEDIA_STREAM)
template<> bool isValidEnum<WebCore::RedEyeReduction>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::WebGPU::TextureAspect>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::PredefinedColorSpace>(uint8_t);
template<> bool isValidEnum<WebCore::InspectorFrontendClientAppearance>(uint8_t);
template<> bool isValidEnum<WebCore::UserContentMatchParentFrame>(uint8_t);
template<> bool isValidOptionSet<WebCore::WheelEventTestMonitorDeferReason>(OptionSet<WebCore::WheelEventTestMonitorDeferReason>);
template<> bool isValidOptionSet<WebCore::HTTPHeadersToKeepFromCleaning>(OptionSet<WebCore::HTTPHeadersToKeepFromCleaning>);
template<> bool isValidEnum<WebCore::ExceptionCode>(uint8_t);
template<> bool isValidEnum<WebCore::BackgroundFetchFailureReason>(uint8_t);
template<> bool isValidEnum<WebCore::BackgroundFetchResult>(uint8_t);
template<> bool isValidEnum<WebCore::ResourceErrorBaseType>(uint8_t);
template<> bool isValidEnum<WebCore::CredentialPersistence>(uint8_t);
template<> bool isValidEnum<WebCore::PaginationMode>(uint8_t);
#if ENABLE(WEB_AUTHN)
template<> bool isValidEnum<WebCore::MediationRequirement>(uint8_t);
#endif
#if ENABLE(CONTEXT_MENUS)
template<> bool isValidEnum<WebCore::ContextMenuContextType>(uint8_t);
#endif
template<> bool isValidOptionSet<WebCore::CrossSiteNavigationDataTransferFlag>(OptionSet<WebCore::CrossSiteNavigationDataTransferFlag>);
#if ENABLE(VIDEO)
template<> bool isValidEnum<WebCore::CaptionUserPreferencesDisplayMode>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::InspectorBackendClientDeveloperPreference>(uint8_t);
#if HAVE(CORE_MATERIAL)
template<> bool isValidEnum<WebCore::AppleVisualEffect>(uint8_t);
#endif
#if ENABLE(MEDIA_SOURCE)
template<> bool isValidEnum<WebCore::MediaSourcePrivateAddStatus>(uint8_t);
#endif
#if ENABLE(MEDIA_SOURCE)
template<> bool isValidEnum<WebCore::MediaSourcePrivateEndOfStreamStatus>(uint8_t);
#endif
#if ENABLE(MEDIA_SOURCE)
template<> bool isValidEnum<WebCore::SourceBufferAppendMode>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::WindowProxyProperty>(uint8_t);
template<> bool isValidEnum<WebCore::PlatformCursorType>(uint8_t);
template<> bool isValidEnum<WebCore::ContextMenuItemType>(uint8_t);
template<> bool isValidEnum<WebCore::PredefinedColorSpace>(uint8_t);
template<> bool isValidEnum<WebCore::TransformOperationType>(uint8_t);
template<> bool isValidOptionSet<GCGLErrorCode>(OptionSet<GCGLErrorCode>);
template<> bool isValidEnum<WebCore::CompositeOperationType>(uint8_t);
template<> bool isValidEnum<WebCore::ColorMatrixType>(uint8_t);
template<> bool isValidEnum<WebCore::TurbulenceType>(uint8_t);
template<> bool isValidOptionSet<WebCore::FilterRenderingMode>(OptionSet<WebCore::FilterRenderingMode>);
template<> bool isValidEnum<WebCore::LightType>(uint8_t);
template<> bool isValidEnum<WebCore::ComponentTransferType>(uint8_t);
template<> bool isValidEnum<WebCore::ComponentTransferChannel>(uint8_t);
template<> bool isValidEnum<WebCore::MorphologyOperatorType>(uint8_t);
template<> bool isValidEnum<WebCore::ChannelSelectorType>(uint8_t);
template<> bool isValidEnum<WebCore::EdgeModeType>(uint8_t);
template<> bool isValidEnum<WebCore::ResolvedEmojiPolicy>(uint8_t);
#if ENABLE(VIDEO)
template<> bool isValidEnum<WebCore::PlatformMediaError>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::NotificationDirection>(uint8_t);
#if PLATFORM(COCOA)
template<> bool isValidEnum<WebCore::ImageDecodingError>(uint8_t);
#endif
template<> bool isValidEnum<WebCore::FileSystemWriteCommandType>(uint8_t);
template<> bool isValidEnum<WebCore::CryptoKeyUsage>(uint8_t);
template<> bool isValidEnum<WebCore::CryptoAlgorithmIdentifier>(uint8_t);
template<> bool isValidEnum<WebCore::CryptoKeyClass>(uint8_t);
template<> bool isValidEnum<WebCore::CryptoKeyType>(uint8_t);
#if ENABLE(DOM_AUDIO_SESSION)
template<> bool isValidEnum<WebCore::DOMAudioSessionType>(uint8_t);
#endif
template<> bool isValidOptionSet<WebCore::DocumentClass>(OptionSet<WebCore::DocumentClass>);
template<> bool isValidEnum<WebCore::PredominantColorType>(uint8_t);
template<> bool isValidEnum<WebCore::ShouldGoToHistoryItem>(uint8_t);
template<> bool isValidEnum<WebCore::ProcessSwapDisposition>(uint8_t);
template<> bool isValidOptionSet<WebCore::ScriptTrackingPrivacyFlag>(OptionSet<WebCore::ScriptTrackingPrivacyFlag>);
template<> bool isValidOptionSet<WebKit::WebEventModifier>(OptionSet<WebKit::WebEventModifier>);
template<> bool isValidEnum<WebKit::WebEventType>(uint8_t);
template<> bool isValidEnum<WebKit::WebMouseEventButton>(int8_t);
template<> bool isValidEnum<WebKit::WebMouseEventSyntheticClickType>(uint8_t);
template<> bool isValidOptionSet<WebKit::FindOptions>(OptionSet<WebKit::FindOptions>);
template<> bool isValidEnum<WebKit::FindDecorationStyle>(uint8_t);
template<> bool isValidEnum<WebKit::IsScrollable>(uint8_t);
template<> bool isValidEnum<WebKit::WebsiteMetaViewportPolicy>(uint8_t);
template<> bool isValidEnum<WebKit::WebsiteMediaSourcePolicy>(uint8_t);
template<> bool isValidEnum<WebKit::WebsiteSimulatedMouseEventsDispatchPolicy>(uint8_t);
template<> bool isValidEnum<WebKit::WebsiteLegacyOverflowScrollingTouchPolicy>(uint8_t);
template<> bool isValidEnum<WebKit::WebContentMode>(uint8_t);
template<> bool isValidEnum<WebKit::WebsiteInlineMediaPlaybackPolicy>(uint8_t);
template<> bool isValidEnum<WebKit::AuthenticationChallengeDisposition>(uint8_t);
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
template<> bool isValidEnum<WebKit::WebExtensionActionClickBehavior>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidEnum<WebKit::WebExtensionContentWorldType>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidEnum<WebKit::WebExtensionContextInstallReason>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidEnum<WebKit::WebExtensionEventListenerType>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidEnum<WebKit::WebExtensionMenuItemType>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidOptionSet<WebKit::WebExtensionMenuItemContextType>(OptionSet<WebKit::WebExtensionMenuItemContextType>);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidEnum<WebKit::WebExtensionStorageAccessLevel>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidEnum<WebKit::WebExtensionDataType>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidEnum<WebKit::WebExtensionTabImageFormat>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidOptionSet<WebKit::WebExtensionWindowTypeFilter>(OptionSet<WebKit::WebExtensionWindowTypeFilter>);
#endif
#if ENABLE(GPU_PROCESS)
template<> bool isValidEnum<WebCore::WebGPU::FeatureName>(uint8_t);
#endif
template<> bool isValidOptionSet<WebKit::WebsiteDataFetchOption>(OptionSet<WebKit::WebsiteDataFetchOption>);
template<> bool isValidOptionSet<WebKit::WebsiteDataType>(OptionSet<WebKit::WebsiteDataType>);
#if ENABLE(WEBXR)
template<> bool isValidEnum<PlatformXR::Layout>(uint8_t);
#endif
#if ENABLE(WEBXR)
template<> bool isValidEnum<PlatformXR::SessionFeature>(uint8_t);
#endif
#if ENABLE(WEBXR)
template<> bool isValidEnum<PlatformXR::SessionMode>(uint8_t);
#endif
#if ENABLE(WEBXR)
template<> bool isValidEnum<PlatformXR::ReferenceSpaceType>(uint8_t);
#endif
#if ENABLE(WEBXR)
template<> bool isValidEnum<PlatformXR::VisibilityState>(uint8_t);
#endif
#if ENABLE(WEBXR)
template<> bool isValidEnum<PlatformXR::XRHandedness>(uint8_t);
#endif
#if ENABLE(WEBXR)
template<> bool isValidEnum<PlatformXR::XRTargetRayMode>(uint8_t);
#endif
#if (ENABLE(WEBXR)) && (USE(OPENXR))
template<> bool isValidEnum<PlatformXR::Eye>(uint8_t);
#endif
#if ENABLE(WK_WEB_EXTENSIONS)
template<> bool isValidEnum<WebKit::WebExtensionWindowTypeFilter>(uint8_t);
#endif
#if ENABLE(GPU_PROCESS)
template<> bool isValidOptionSet<WebKit::BufferInSetType>(OptionSet<WebKit::BufferInSetType>);
#endif
#if USE(GRAPHICS_LAYER_WC)
template<> bool isValidOptionSet<WebKit::WCLayerChange>(OptionSet<WebKit::WCLayerChange>);
#endif
template<> bool isValidEnum<WebCore::HTTPHeaderName>(uint16_t);
template<> bool isValidOptionSet<WebCore::ActivityState>(OptionSet<WebCore::ActivityState>);
template<> bool isValidOptionSet<WebCore::DragDestinationAction>(OptionSet<WebCore::DragDestinationAction>);
template<> bool isValidEnum<WebCore::DragHandlingMethod>(uint8_t);
template<> bool isValidOptionSet<WebCore::DragOperation>(OptionSet<WebCore::DragOperation>);
template<> bool isValidEnum<WebCore::DragOperation>(uint8_t);
template<> bool isValidEnum<WebCore::DragSourceAction>(uint8_t);
template<> bool isValidOptionSet<WebCore::DragSourceAction>(OptionSet<WebCore::DragSourceAction>);
#if ENABLE(GPU_PROCESS) && ENABLE(VIDEO)
template<> bool isValidEnum<WebCore::InbandTextTrackPrivateMode>(uint8_t);
#endif
template<> bool isValidOptionSet<WebCore::LayoutMilestone>(OptionSet<WebCore::LayoutMilestone>);
template<> bool isValidEnum<WebCore::MDNSRegisterError>(uint8_t);
template<> bool isValidOptionSet<WebCore::MediaProducerMediaState>(OptionSet<WebCore::MediaProducerMediaState>);
template<> bool isValidOptionSet<WebCore::MediaProducerMutedState>(OptionSet<WebCore::MediaProducerMutedState>);
template<> bool isValidOptionSet<WebCore::PlatformEventModifier>(OptionSet<WebCore::PlatformEventModifier>);
template<> bool isValidEnum<WebCore::PlatformMediaSessionRemoteControlCommandType>(uint8_t);
template<> bool isValidEnum<WebCore::DynamicRangeMode>(uint8_t);
template<> bool isValidEnum<WebCore::PlatformWheelEventPhase>(uint8_t);
template<> bool isValidEnum<WebCore::ProcessSyncDataType>(uint8_t);
template<> bool isValidEnum<WebCore::ProtectionSpaceBaseServerType>(uint8_t);
template<> bool isValidEnum<WebCore::ProtectionSpaceBaseAuthenticationScheme>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollDirection>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollbarOrientation>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollbarWidth>(uint8_t);
template<> bool isValidEnum<WebCore::RubberBandingBehavior>(uint8_t);
template<> bool isValidEnum<WebCore::ScrollbarOverlayStyle>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::ErrorFilter>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::IndexFormat>(uint8_t);
template<> bool isValidOptionSet<WebCore::WebGPU::MapMode>(OptionSet<WebCore::WebGPU::MapMode>);
template<> bool isValidEnum<WebCore::WebGPU::MapMode>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::BlendFactor>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::TextureSampleType>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::BlendOperation>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::CanvasToneMappingMode>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::CanvasAlphaMode>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::QueryType>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::CompareFunction>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::FilterMode>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::MipmapFilterMode>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::TextureDimension>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::VertexFormat>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::ShaderStage>(uint8_t);
template<> bool isValidOptionSet<WebCore::WebGPU::ShaderStage>(OptionSet<WebCore::WebGPU::ShaderStage>);
template<> bool isValidEnum<WebCore::WebGPU::CompilationMessageType>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::StencilOperation>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::DeviceLostReason>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::AddressMode>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::BufferBindingType>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::StorageTextureAccess>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::FrontFace>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::StoreOp>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::LoadOp>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::ColorWrite>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::SamplerBindingType>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::PrimitiveTopology>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::CullMode>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::TextureViewDimension>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::VertexStepMode>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::XREye>(uint8_t);
template<> bool isValidEnum<WebCore::WebGPU::BufferUsage>(uint16_t);
template<> bool isValidEnum<WebCore::WebGPU::TextureUsage>(uint8_t);
template<> bool isValidOptionSet<WebCore::WebGPU::TextureUsage>(OptionSet<WebCore::WebGPU::TextureUsage>);

} // namespace WTF
