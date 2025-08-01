/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GOOGLE, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "EventHeaders.h"

#include "JSDOMGlobalObject.h"
#include <JavaScriptCore/StructureInlines.h>

namespace WebCore {

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<Event>&& impl)
{
    switch (impl->interfaceType()) {
    case EventInterfaceType::Invalid:
        ASSERT_NOT_REACHED();
        break;
    case EventInterfaceType::AnimationPlaybackEvent:
        return createWrapper<AnimationPlaybackEvent>(globalObject, WTFMove(impl));
#if ENABLE(APPLE_PAY)
    case EventInterfaceType::ApplePayCancelEvent:
        return createWrapper<ApplePayCancelEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(APPLE_PAY_COUPON_CODE)
    case EventInterfaceType::ApplePayCouponCodeChangedEvent:
        return createWrapper<ApplePayCouponCodeChangedEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(APPLE_PAY)
    case EventInterfaceType::ApplePayPaymentAuthorizedEvent:
        return createWrapper<ApplePayPaymentAuthorizedEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(APPLE_PAY)
    case EventInterfaceType::ApplePayPaymentMethodSelectedEvent:
        return createWrapper<ApplePayPaymentMethodSelectedEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(APPLE_PAY)
    case EventInterfaceType::ApplePayShippingContactSelectedEvent:
        return createWrapper<ApplePayShippingContactSelectedEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(APPLE_PAY)
    case EventInterfaceType::ApplePayShippingMethodSelectedEvent:
        return createWrapper<ApplePayShippingMethodSelectedEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(APPLE_PAY)
    case EventInterfaceType::ApplePayValidateMerchantEvent:
        return createWrapper<ApplePayValidateMerchantEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_AUDIO)
    case EventInterfaceType::AudioProcessingEvent:
        return createWrapper<AudioProcessingEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::BackgroundFetchEvent:
        return createWrapper<BackgroundFetchEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::BackgroundFetchUpdateUIEvent:
        return createWrapper<BackgroundFetchUpdateUIEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::Event:
        return createWrapper<Event>(globalObject, WTFMove(impl));
    case EventInterfaceType::BeforeUnloadEvent:
        return createWrapper<BeforeUnloadEvent>(globalObject, WTFMove(impl));
#if ENABLE(MEDIA_RECORDER)
    case EventInterfaceType::BlobEvent:
        return createWrapper<BlobEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(MEDIA_SOURCE)
    case EventInterfaceType::BufferedChangeEvent:
        return createWrapper<BufferedChangeEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::CSSAnimationEvent:
        return createWrapper<CSSAnimationEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::CSSTransitionEvent:
        return createWrapper<CSSTransitionEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::ClipboardEvent:
        return createWrapper<ClipboardEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::CloseEvent:
        return createWrapper<CloseEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::CommandEvent:
        return createWrapper<CommandEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::CompositionEvent:
        return createWrapper<CompositionEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::ContentVisibilityAutoStateChangeEvent:
        return createWrapper<ContentVisibilityAutoStateChangeEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::CookieChangeEvent:
        return createWrapper<CookieChangeEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::CustomEvent:
        return createWrapper<CustomEvent>(globalObject, WTFMove(impl));
#if ENABLE(DEVICE_ORIENTATION)
    case EventInterfaceType::DeviceMotionEvent:
        return createWrapper<DeviceMotionEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(DEVICE_ORIENTATION)
    case EventInterfaceType::DeviceOrientationEvent:
        return createWrapper<DeviceOrientationEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::DragEvent:
        return createWrapper<DragEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::ErrorEvent:
        return createWrapper<ErrorEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::ExtendableCookieChangeEvent:
        return createWrapper<ExtendableCookieChangeEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::ExtendableEvent:
        return createWrapper<ExtendableEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::ExtendableMessageEvent:
        return createWrapper<ExtendableMessageEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::FetchEvent:
        return createWrapper<FetchEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::FocusEvent:
        return createWrapper<FocusEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::FormDataEvent:
        return createWrapper<FormDataEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::GPUUncapturedErrorEvent:
        return createWrapper<GPUUncapturedErrorEvent>(globalObject, WTFMove(impl));
#if ENABLE(GAMEPAD)
    case EventInterfaceType::GamepadEvent:
        return createWrapper<GamepadEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(IOS_GESTURE_EVENTS) || ENABLE(MAC_GESTURE_EVENTS)
    case EventInterfaceType::GestureEvent:
        return createWrapper<GestureEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::HashChangeEvent:
        return createWrapper<HashChangeEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::IDBVersionChangeEvent:
        return createWrapper<IDBVersionChangeEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::InputEvent:
        return createWrapper<InputEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::InstallEvent:
        return createWrapper<InstallEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::KeyboardEvent:
        return createWrapper<KeyboardEvent>(globalObject, WTFMove(impl));
#if ENABLE(ENCRYPTED_MEDIA)
    case EventInterfaceType::MediaEncryptedEvent:
        return createWrapper<MediaEncryptedEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    case EventInterfaceType::MediaKeyMessageEvent:
        return createWrapper<MediaKeyMessageEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::MediaQueryListEvent:
        return createWrapper<MediaQueryListEvent>(globalObject, WTFMove(impl));
#if ENABLE(MEDIA_RECORDER)
    case EventInterfaceType::MediaRecorderErrorEvent:
        return createWrapper<MediaRecorderErrorEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(MEDIA_STREAM)
    case EventInterfaceType::MediaStreamTrackEvent:
        return createWrapper<MediaStreamTrackEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(PAYMENT_REQUEST)
    case EventInterfaceType::MerchantValidationEvent:
        return createWrapper<MerchantValidationEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::MessageEvent:
        return createWrapper<MessageEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::MouseEvent:
        return createWrapper<MouseEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::MutationEvent:
        return createWrapper<MutationEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::NavigateEvent:
        return createWrapper<NavigateEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::NavigationCurrentEntryChangeEvent:
        return createWrapper<NavigationCurrentEntryChangeEvent>(globalObject, WTFMove(impl));
#if ENABLE(NOTIFICATION_EVENT)
    case EventInterfaceType::NotificationEvent:
        return createWrapper<NotificationEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_AUDIO)
    case EventInterfaceType::OfflineAudioCompletionEvent:
        return createWrapper<OfflineAudioCompletionEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(MEDIA_STREAM)
    case EventInterfaceType::OverconstrainedErrorEvent:
        return createWrapper<OverconstrainedErrorEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::OverflowEvent:
        return createWrapper<OverflowEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::PageRevealEvent:
        return createWrapper<PageRevealEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::PageSwapEvent:
        return createWrapper<PageSwapEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::PageTransitionEvent:
        return createWrapper<PageTransitionEvent>(globalObject, WTFMove(impl));
#if ENABLE(PAYMENT_REQUEST)
    case EventInterfaceType::PaymentMethodChangeEvent:
        return createWrapper<PaymentMethodChangeEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(PAYMENT_REQUEST)
    case EventInterfaceType::PaymentRequestUpdateEvent:
        return createWrapper<PaymentRequestUpdateEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(PICTURE_IN_PICTURE_API)
    case EventInterfaceType::PictureInPictureEvent:
        return createWrapper<PictureInPictureEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::PointerEvent:
        return createWrapper<PointerEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::PopStateEvent:
        return createWrapper<PopStateEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::ProgressEvent:
        return createWrapper<ProgressEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::PromiseRejectionEvent:
        return createWrapper<PromiseRejectionEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::PushEvent:
        return createWrapper<PushEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::PushSubscriptionChangeEvent:
        return createWrapper<PushSubscriptionChangeEvent>(globalObject, WTFMove(impl));
#if ENABLE(WEB_RTC)
    case EventInterfaceType::RTCDTMFToneChangeEvent:
        return createWrapper<RTCDTMFToneChangeEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventInterfaceType::RTCDataChannelEvent:
        return createWrapper<RTCDataChannelEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventInterfaceType::RTCErrorEvent:
        return createWrapper<RTCErrorEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventInterfaceType::RTCPeerConnectionIceErrorEvent:
        return createWrapper<RTCPeerConnectionIceErrorEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventInterfaceType::RTCPeerConnectionIceEvent:
        return createWrapper<RTCPeerConnectionIceEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventInterfaceType::RTCRtpSFrameTransformErrorEvent:
        return createWrapper<RTCRtpSFrameTransformErrorEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventInterfaceType::RTCTrackEvent:
        return createWrapper<RTCTrackEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventInterfaceType::RTCTransformEvent:
        return createWrapper<RTCTransformEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::SecurityPolicyViolationEvent:
        return createWrapper<SecurityPolicyViolationEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::SpeechRecognitionErrorEvent:
        return createWrapper<SpeechRecognitionErrorEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::SpeechRecognitionEvent:
        return createWrapper<SpeechRecognitionEvent>(globalObject, WTFMove(impl));
#if ENABLE(SPEECH_SYNTHESIS)
    case EventInterfaceType::SpeechSynthesisErrorEvent:
        return createWrapper<SpeechSynthesisErrorEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    case EventInterfaceType::SpeechSynthesisEvent:
        return createWrapper<SpeechSynthesisEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::StorageEvent:
        return createWrapper<StorageEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::SubmitEvent:
        return createWrapper<SubmitEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::TextEvent:
        return createWrapper<TextEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::ToggleEvent:
        return createWrapper<ToggleEvent>(globalObject, WTFMove(impl));
#if ENABLE(TOUCH_EVENTS)
    case EventInterfaceType::TouchEvent:
        return createWrapper<TouchEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(VIDEO)
    case EventInterfaceType::TrackEvent:
        return createWrapper<TrackEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::UIEvent:
        return createWrapper<UIEvent>(globalObject, WTFMove(impl));
#if ENABLE(WEBGL)
    case EventInterfaceType::WebGLContextEvent:
        return createWrapper<WebGLContextEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    case EventInterfaceType::WebKitMediaKeyMessageEvent:
        return createWrapper<WebKitMediaKeyMessageEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    case EventInterfaceType::WebKitMediaKeyNeededEvent:
        return createWrapper<WebKitMediaKeyNeededEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET_AVAILABILITY_API)
    case EventInterfaceType::WebKitPlaybackTargetAvailabilityEvent:
        return createWrapper<WebKitPlaybackTargetAvailabilityEvent>(globalObject, WTFMove(impl));
#endif
    case EventInterfaceType::WheelEvent:
        return createWrapper<WheelEvent>(globalObject, WTFMove(impl));
    case EventInterfaceType::XMLHttpRequestProgressEvent:
        return createWrapper<XMLHttpRequestProgressEvent>(globalObject, WTFMove(impl));
#if ENABLE(WEBXR)
    case EventInterfaceType::XRInputSourceEvent:
        return createWrapper<XRInputSourceEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEBXR)
    case EventInterfaceType::XRInputSourcesChangeEvent:
        return createWrapper<XRInputSourcesChangeEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEBXR_LAYERS)
    case EventInterfaceType::XRLayerEvent:
        return createWrapper<XRLayerEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEBXR)
    case EventInterfaceType::XRReferenceSpaceEvent:
        return createWrapper<XRReferenceSpaceEvent>(globalObject, WTFMove(impl));
#endif
#if ENABLE(WEBXR)
    case EventInterfaceType::XRSessionEvent:
        return createWrapper<XRSessionEvent>(globalObject, WTFMove(impl));
#endif
    }
    return createWrapper<Event>(globalObject, WTFMove(impl));
}

} // namespace WebCore
