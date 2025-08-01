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
#include "EventTargetHeaders.h"

#include "JSDOMGlobalObject.h"
#include <JavaScriptCore/StructureInlines.h>

namespace WebCore {

JSC::JSValue toJS(JSC::JSGlobalObject* state, JSDOMGlobalObject* globalObject, EventTarget& impl)
{
    switch (impl.eventTargetInterface()) {
    case EventTargetInterfaceType::Invalid:
        ASSERT_NOT_REACHED();
        break;
    case EventTargetInterfaceType::EventTarget:
        break;
    case EventTargetInterfaceType::AbortSignal:
        return toJS(state, globalObject, static_cast<AbortSignal&>(impl));
#if ENABLE(APPLE_PAY)
    case EventTargetInterfaceType::ApplePaySession:
        return toJS(state, globalObject, static_cast<ApplePaySession&>(impl));
#endif
#if ENABLE(WEB_AUDIO)
    case EventTargetInterfaceType::AudioNode:
        return toJS(state, globalObject, static_cast<AudioNode&>(impl));
#endif
#if ENABLE(VIDEO)
    case EventTargetInterfaceType::AudioTrackList:
        return toJS(state, globalObject, static_cast<AudioTrackList&>(impl));
#endif
    case EventTargetInterfaceType::BackgroundFetchRegistration:
        return toJS(state, globalObject, static_cast<BackgroundFetchRegistration&>(impl));
#if ENABLE(WEB_AUDIO)
    case EventTargetInterfaceType::BaseAudioContext:
        return toJS(state, globalObject, static_cast<BaseAudioContext&>(impl));
#endif
    case EventTargetInterfaceType::BroadcastChannel:
        return toJS(state, globalObject, static_cast<BroadcastChannel&>(impl));
    case EventTargetInterfaceType::Clipboard:
        return toJS(state, globalObject, static_cast<Clipboard&>(impl));
    case EventTargetInterfaceType::CloseWatcher:
        return toJS(state, globalObject, static_cast<CloseWatcher&>(impl));
    case EventTargetInterfaceType::CookieStore:
        return toJS(state, globalObject, static_cast<CookieStore&>(impl));
#if ENABLE(DOM_AUDIO_SESSION)
    case EventTargetInterfaceType::DOMAudioSession:
        return toJS(state, globalObject, static_cast<DOMAudioSession&>(impl));
#endif
    case EventTargetInterfaceType::DOMWindow:
        return toJS(state, globalObject, static_cast<DOMWindow&>(impl));
    case EventTargetInterfaceType::DedicatedWorkerGlobalScope:
        return toJS(state, globalObject, static_cast<DedicatedWorkerGlobalScope&>(impl));
    case EventTargetInterfaceType::EventSource:
        return toJS(state, globalObject, static_cast<EventSource&>(impl));
    case EventTargetInterfaceType::FileReader:
        return toJS(state, globalObject, static_cast<FileReader&>(impl));
    case EventTargetInterfaceType::FontFaceSet:
        return toJS(state, globalObject, static_cast<FontFaceSet&>(impl));
    case EventTargetInterfaceType::GPUDevice:
        return toJS(state, globalObject, static_cast<GPUDevice&>(impl));
    case EventTargetInterfaceType::IDBDatabase:
        return toJS(state, globalObject, static_cast<IDBDatabase&>(impl));
    case EventTargetInterfaceType::IDBOpenDBRequest:
        return toJS(state, globalObject, static_cast<IDBOpenDBRequest&>(impl));
    case EventTargetInterfaceType::IDBRequest:
        return toJS(state, globalObject, static_cast<IDBRequest&>(impl));
    case EventTargetInterfaceType::IDBTransaction:
        return toJS(state, globalObject, static_cast<IDBTransaction&>(impl));
#if ENABLE(MEDIA_SOURCE)
    case EventTargetInterfaceType::ManagedMediaSource:
        return toJS(state, globalObject, static_cast<ManagedMediaSource&>(impl));
#endif
#if ENABLE(MEDIA_SOURCE)
    case EventTargetInterfaceType::ManagedSourceBuffer:
        return toJS(state, globalObject, static_cast<ManagedSourceBuffer&>(impl));
#endif
#if ENABLE(VIDEO)
    case EventTargetInterfaceType::MediaController:
        return toJS(state, globalObject, static_cast<MediaController&>(impl));
#endif
#if ENABLE(MEDIA_STREAM)
    case EventTargetInterfaceType::MediaDevices:
        return toJS(state, globalObject, static_cast<MediaDevices&>(impl));
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    case EventTargetInterfaceType::MediaKeySession:
        return toJS(state, globalObject, static_cast<MediaKeySession&>(impl));
#endif
    case EventTargetInterfaceType::MediaQueryList:
        return toJS(state, globalObject, static_cast<MediaQueryList&>(impl));
#if ENABLE(MEDIA_RECORDER)
    case EventTargetInterfaceType::MediaRecorder:
        return toJS(state, globalObject, static_cast<MediaRecorder&>(impl));
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    case EventTargetInterfaceType::MediaSessionCoordinator:
        return toJS(state, globalObject, static_cast<MediaSessionCoordinator&>(impl));
#endif
#if ENABLE(MEDIA_SOURCE)
    case EventTargetInterfaceType::MediaSource:
        return toJS(state, globalObject, static_cast<MediaSource&>(impl));
#endif
#if ENABLE(MEDIA_STREAM)
    case EventTargetInterfaceType::MediaStream:
        return toJS(state, globalObject, static_cast<MediaStream&>(impl));
#endif
#if ENABLE(MEDIA_STREAM)
    case EventTargetInterfaceType::MediaStreamTrack:
        return toJS(state, globalObject, static_cast<MediaStreamTrack&>(impl));
#endif
    case EventTargetInterfaceType::MessagePort:
        return toJS(state, globalObject, static_cast<MessagePort&>(impl));
    case EventTargetInterfaceType::Navigation:
        return toJS(state, globalObject, static_cast<Navigation&>(impl));
    case EventTargetInterfaceType::NavigationHistoryEntry:
        return toJS(state, globalObject, static_cast<NavigationHistoryEntry&>(impl));
    case EventTargetInterfaceType::Node:
        return toJS(state, globalObject, static_cast<Node&>(impl));
#if ENABLE(NOTIFICATIONS)
    case EventTargetInterfaceType::Notification:
        return toJS(state, globalObject, static_cast<Notification&>(impl));
#endif
#if ENABLE(OFFSCREEN_CANVAS)
    case EventTargetInterfaceType::OffscreenCanvas:
        return toJS(state, globalObject, static_cast<OffscreenCanvas&>(impl));
#endif
#if ENABLE(PAYMENT_REQUEST)
    case EventTargetInterfaceType::PaymentRequest:
        return toJS(state, globalObject, static_cast<PaymentRequest&>(impl));
#endif
#if ENABLE(PAYMENT_REQUEST)
    case EventTargetInterfaceType::PaymentResponse:
        return toJS(state, globalObject, static_cast<PaymentResponse&>(impl));
#endif
    case EventTargetInterfaceType::Performance:
        return toJS(state, globalObject, static_cast<Performance&>(impl));
    case EventTargetInterfaceType::PermissionStatus:
        return toJS(state, globalObject, static_cast<PermissionStatus&>(impl));
#if ENABLE(PICTURE_IN_PICTURE_API)
    case EventTargetInterfaceType::PictureInPictureWindow:
        return toJS(state, globalObject, static_cast<PictureInPictureWindow&>(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventTargetInterfaceType::RTCDTMFSender:
        return toJS(state, globalObject, static_cast<RTCDTMFSender&>(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventTargetInterfaceType::RTCDataChannel:
        return toJS(state, globalObject, static_cast<RTCDataChannel&>(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventTargetInterfaceType::RTCDtlsTransport:
        return toJS(state, globalObject, static_cast<RTCDtlsTransport&>(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventTargetInterfaceType::RTCIceTransport:
        return toJS(state, globalObject, static_cast<RTCIceTransport&>(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventTargetInterfaceType::RTCPeerConnection:
        return toJS(state, globalObject, static_cast<RTCPeerConnection&>(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventTargetInterfaceType::RTCRtpSFrameTransform:
        return toJS(state, globalObject, static_cast<RTCRtpSFrameTransform&>(impl));
#endif
#if ENABLE(WEB_RTC)
    case EventTargetInterfaceType::RTCSctpTransport:
        return toJS(state, globalObject, static_cast<RTCSctpTransport&>(impl));
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    case EventTargetInterfaceType::RemotePlayback:
        return toJS(state, globalObject, static_cast<RemotePlayback&>(impl));
#endif
    case EventTargetInterfaceType::ScreenOrientation:
        return toJS(state, globalObject, static_cast<ScreenOrientation&>(impl));
    case EventTargetInterfaceType::ServiceWorker:
        return toJS(state, globalObject, static_cast<ServiceWorker&>(impl));
    case EventTargetInterfaceType::ServiceWorkerContainer:
        return toJS(state, globalObject, static_cast<ServiceWorkerContainer&>(impl));
    case EventTargetInterfaceType::ServiceWorkerGlobalScope:
        return toJS(state, globalObject, static_cast<ServiceWorkerGlobalScope&>(impl));
    case EventTargetInterfaceType::ServiceWorkerRegistration:
        return toJS(state, globalObject, static_cast<ServiceWorkerRegistration&>(impl));
    case EventTargetInterfaceType::SharedWorker:
        return toJS(state, globalObject, static_cast<SharedWorker&>(impl));
    case EventTargetInterfaceType::SharedWorkerGlobalScope:
        return toJS(state, globalObject, static_cast<SharedWorkerGlobalScope&>(impl));
#if ENABLE(MEDIA_SOURCE)
    case EventTargetInterfaceType::SourceBuffer:
        return toJS(state, globalObject, static_cast<SourceBuffer&>(impl));
#endif
#if ENABLE(MEDIA_SOURCE)
    case EventTargetInterfaceType::SourceBufferList:
        return toJS(state, globalObject, static_cast<SourceBufferList&>(impl));
#endif
    case EventTargetInterfaceType::SpeechRecognition:
        return toJS(state, globalObject, static_cast<SpeechRecognition&>(impl));
#if ENABLE(SPEECH_SYNTHESIS)
    case EventTargetInterfaceType::SpeechSynthesis:
        return toJS(state, globalObject, static_cast<SpeechSynthesis&>(impl));
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    case EventTargetInterfaceType::SpeechSynthesisUtterance:
        return toJS(state, globalObject, static_cast<SpeechSynthesisUtterance&>(impl));
#endif
#if ENABLE(VIDEO)
    case EventTargetInterfaceType::TextTrack:
        return toJS(state, globalObject, static_cast<TextTrack&>(impl));
#endif
#if ENABLE(VIDEO)
    case EventTargetInterfaceType::TextTrackCue:
        return toJS(state, globalObject, static_cast<TextTrackCue&>(impl));
#endif
#if ENABLE(VIDEO)
    case EventTargetInterfaceType::TextTrackCueGeneric:
        return toJS(state, globalObject, static_cast<TextTrackCueGeneric&>(impl));
#endif
#if ENABLE(VIDEO)
    case EventTargetInterfaceType::TextTrackList:
        return toJS(state, globalObject, static_cast<TextTrackList&>(impl));
#endif
#if ENABLE(VIDEO)
    case EventTargetInterfaceType::VideoTrackList:
        return toJS(state, globalObject, static_cast<VideoTrackList&>(impl));
#endif
    case EventTargetInterfaceType::VisualViewport:
        return toJS(state, globalObject, static_cast<VisualViewport&>(impl));
    case EventTargetInterfaceType::WakeLockSentinel:
        return toJS(state, globalObject, static_cast<WakeLockSentinel&>(impl));
    case EventTargetInterfaceType::WebAnimation:
        return toJS(state, globalObject, static_cast<WebAnimation&>(impl));
#if ENABLE(WEB_CODECS)
    case EventTargetInterfaceType::WebCodecsAudioDecoder:
        return toJS(state, globalObject, static_cast<WebCodecsAudioDecoder&>(impl));
#endif
#if ENABLE(WEB_CODECS)
    case EventTargetInterfaceType::WebCodecsAudioEncoder:
        return toJS(state, globalObject, static_cast<WebCodecsAudioEncoder&>(impl));
#endif
#if ENABLE(WEB_CODECS)
    case EventTargetInterfaceType::WebCodecsVideoDecoder:
        return toJS(state, globalObject, static_cast<WebCodecsVideoDecoder&>(impl));
#endif
#if ENABLE(WEB_CODECS)
    case EventTargetInterfaceType::WebCodecsVideoEncoder:
        return toJS(state, globalObject, static_cast<WebCodecsVideoEncoder&>(impl));
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    case EventTargetInterfaceType::WebKitMediaKeySession:
        return toJS(state, globalObject, static_cast<WebKitMediaKeySession&>(impl));
#endif
    case EventTargetInterfaceType::WebSocket:
        return toJS(state, globalObject, static_cast<WebSocket&>(impl));
#if ENABLE(WEBXR)
    case EventTargetInterfaceType::WebXRLayer:
        return toJS(state, globalObject, static_cast<WebXRLayer&>(impl));
#endif
#if ENABLE(WEBXR)
    case EventTargetInterfaceType::WebXRSession:
        return toJS(state, globalObject, static_cast<WebXRSession&>(impl));
#endif
#if ENABLE(WEBXR)
    case EventTargetInterfaceType::WebXRSpace:
        return toJS(state, globalObject, static_cast<WebXRSpace&>(impl));
#endif
#if ENABLE(WEBXR)
    case EventTargetInterfaceType::WebXRSystem:
        return toJS(state, globalObject, static_cast<WebXRSystem&>(impl));
#endif
    case EventTargetInterfaceType::Worker:
        return toJS(state, globalObject, static_cast<Worker&>(impl));
    case EventTargetInterfaceType::WorkletGlobalScope:
        return toJS(state, globalObject, static_cast<WorkletGlobalScope&>(impl));
    case EventTargetInterfaceType::XMLHttpRequest:
        return toJS(state, globalObject, static_cast<XMLHttpRequest&>(impl));
    case EventTargetInterfaceType::XMLHttpRequestUpload:
        return toJS(state, globalObject, static_cast<XMLHttpRequestUpload&>(impl));
    }
    return wrap(state, globalObject, impl);
}

} // namespace WebCore
