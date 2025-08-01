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

#include "config.h"
#include "MessageNames.h"

namespace IPC::Detail {

const MessageDescriptionsArray messageDescriptions {
    MessageDescription { "AuthenticationManager_CompleteAuthenticationChallenge"_s, ReceiverName::AuthenticationManager, false, false },
#if OS(LINUX)
    MessageDescription { "AuxiliaryProcess_DidReceiveMemoryPressureEvent"_s, ReceiverName::AuxiliaryProcess, false, false },
#endif
    MessageDescription { "AuxiliaryProcess_MainThreadPing"_s, ReceiverName::AuxiliaryProcess, false, false },
#if ENABLE(CFPREFS_DIRECT_MODE)
    MessageDescription { "AuxiliaryProcess_PreferenceDidUpdate"_s, ReceiverName::AuxiliaryProcess, false, false },
#endif
    MessageDescription { "AuxiliaryProcess_SetProcessSuppressionEnabled"_s, ReceiverName::AuxiliaryProcess, false, false },
    MessageDescription { "AuxiliaryProcess_ShutDown"_s, ReceiverName::AuxiliaryProcess, false, false },
    MessageDescription { "DigitalCredentialsCoordinator_ProvideRawDigitalCredentialRequests"_s, ReceiverName::DigitalCredentialsCoordinator, false, false },
    MessageDescription { "DownloadProxy_DecideDestinationWithSuggestedFilename"_s, ReceiverName::DownloadProxy, false, false },
    MessageDescription { "DownloadProxy_DidCreateDestination"_s, ReceiverName::DownloadProxy, false, false },
    MessageDescription { "DownloadProxy_DidFail"_s, ReceiverName::DownloadProxy, false, false },
    MessageDescription { "DownloadProxy_DidFinish"_s, ReceiverName::DownloadProxy, false, false },
    MessageDescription { "DownloadProxy_DidReceiveAuthenticationChallenge"_s, ReceiverName::DownloadProxy, false, false },
    MessageDescription { "DownloadProxy_DidReceiveData"_s, ReceiverName::DownloadProxy, false, false },
#if HAVE(MODERN_DOWNLOADPROGRESS)
    MessageDescription { "DownloadProxy_DidReceiveFinalURL"_s, ReceiverName::DownloadProxy, false, false },
    MessageDescription { "DownloadProxy_DidReceivePlaceholderURL"_s, ReceiverName::DownloadProxy, false, false },
#endif
    MessageDescription { "DownloadProxy_DidStart"_s, ReceiverName::DownloadProxy, false, false },
#if HAVE(MODERN_DOWNLOADPROGRESS)
    MessageDescription { "DownloadProxy_DidStartUpdatingProgress"_s, ReceiverName::DownloadProxy, false, false },
#endif
    MessageDescription { "DownloadProxy_WillSendRequest"_s, ReceiverName::DownloadProxy, false, false },
    MessageDescription { "DrawingAreaProxy_DidFirstLayerFlush"_s, ReceiverName::DrawingAreaProxy, false, false },
    MessageDescription { "DrawingAreaProxy_DispatchPresentationCallbacksAfterFlushingLayers"_s, ReceiverName::DrawingAreaProxy, false, false },
    MessageDescription { "DrawingAreaProxy_EnterAcceleratedCompositingMode"_s, ReceiverName::DrawingAreaProxy, false, false },
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
    MessageDescription { "DrawingAreaProxy_ExitAcceleratedCompositingMode"_s, ReceiverName::DrawingAreaProxy, false, false },
    MessageDescription { "DrawingAreaProxy_Update"_s, ReceiverName::DrawingAreaProxy, false, false },
#endif
    MessageDescription { "DrawingAreaProxy_UpdateAcceleratedCompositingMode"_s, ReceiverName::DrawingAreaProxy, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "DrawingArea_AcceleratedAnimationDidEnd"_s, ReceiverName::DrawingArea, false, false },
    MessageDescription { "DrawingArea_AcceleratedAnimationDidStart"_s, ReceiverName::DrawingArea, false, false },
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK)
    MessageDescription { "DrawingArea_AdjustTransientZoom"_s, ReceiverName::DrawingArea, false, false },
    MessageDescription { "DrawingArea_CommitTransientZoom"_s, ReceiverName::DrawingArea, false, false },
#endif
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
    MessageDescription { "DrawingArea_DidDiscardBackingStore"_s, ReceiverName::DrawingArea, false, false },
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "DrawingArea_DispatchAfterEnsuringDrawing"_s, ReceiverName::DrawingArea, false, false },
#endif
    MessageDescription { "DrawingArea_DisplayDidRefresh"_s, ReceiverName::DrawingArea, false, false },
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
    MessageDescription { "DrawingArea_ForceUpdate"_s, ReceiverName::DrawingArea, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "DrawingArea_SetColorSpace"_s, ReceiverName::DrawingArea, false, false },
#endif
    MessageDescription { "DrawingArea_SetDeviceScaleFactor"_s, ReceiverName::DrawingArea, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "DrawingArea_SetViewExposedRect"_s, ReceiverName::DrawingArea, false, false },
#endif
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER) || PLATFORM(COCOA)
    MessageDescription { "DrawingArea_UpdateGeometry"_s, ReceiverName::DrawingArea, false, false },
#endif
#if USE(GRAPHICS_LAYER_WC)
    MessageDescription { "DrawingArea_UpdateGeometryWC"_s, ReceiverName::DrawingArea, false, false },
#endif
#if HAVE(DISPLAY_LINK)
    MessageDescription { "EventDispatcher_DisplayDidRefresh"_s, ReceiverName::EventDispatcher, false, false },
#endif
#if ENABLE(MAC_GESTURE_EVENTS)
    MessageDescription { "EventDispatcher_GestureEvent"_s, ReceiverName::EventDispatcher, false, false },
#endif
    MessageDescription { "EventDispatcher_PageScreenDidChange"_s, ReceiverName::EventDispatcher, false, false },
#if ENABLE(MOMENTUM_EVENT_DISPATCHER)
    MessageDescription { "EventDispatcher_SetScrollingAccelerationCurve"_s, ReceiverName::EventDispatcher, false, false },
#endif
#if ENABLE(IOS_TOUCH_EVENTS)
    MessageDescription { "EventDispatcher_TouchEvent"_s, ReceiverName::EventDispatcher, false, false },
#endif
    MessageDescription { "EventDispatcher_WheelEvent"_s, ReceiverName::EventDispatcher, false, false },
    MessageDescription { "GPUConnectionToWebProcess_ClearNowPlayingInfo"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
    MessageDescription { "GPUConnectionToWebProcess_ConfigureLoggingChannel"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
    MessageDescription { "GPUConnectionToWebProcess_CreateAudioHardwareListener"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
    MessageDescription { "GPUConnectionToWebProcess_CreateGPU"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#if ENABLE(WEBGL)
    MessageDescription { "GPUConnectionToWebProcess_CreateGraphicsContextGL"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#endif
    MessageDescription { "GPUConnectionToWebProcess_CreateRemoteCommandListener"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
    MessageDescription { "GPUConnectionToWebProcess_CreateRenderingBackend"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    MessageDescription { "GPUConnectionToWebProcess_CreateVisibilityPropagationContextForPage"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
#endif
#if USE(GRAPHICS_LAYER_WC)
    MessageDescription { "GPUConnectionToWebProcess_CreateWCLayerTreeHost"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    MessageDescription { "GPUConnectionToWebProcess_DestroyVisibilityPropagationContextForPage"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
#endif
#if ENABLE(MEDIA_SOURCE)
    MessageDescription { "GPUConnectionToWebProcess_EnableMockMediaSource"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "GPUConnectionToWebProcess_EnsureMediaSessionHelper"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
#endif
    MessageDescription { "GPUConnectionToWebProcess_ReleaseAudioHardwareListener"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
    MessageDescription { "GPUConnectionToWebProcess_ReleaseGPU"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#if ENABLE(WEBGL)
    MessageDescription { "GPUConnectionToWebProcess_ReleaseGraphicsContextGL"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#endif
    MessageDescription { "GPUConnectionToWebProcess_ReleaseRemoteCommandListener"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
    MessageDescription { "GPUConnectionToWebProcess_ReleaseRenderingBackend"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#if USE(GRAPHICS_LAYER_WC)
    MessageDescription { "GPUConnectionToWebProcess_ReleaseWCLayerTreeHost"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
    MessageDescription { "GPUConnectionToWebProcess_SetMediaEnvironment"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
#endif
    MessageDescription { "GPUConnectionToWebProcess_SetMediaOverridesForTesting"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
    MessageDescription { "GPUConnectionToWebProcess_SetNowPlayingInfo"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUConnectionToWebProcess_UpdateSampleBufferDisplayLayerBoundsAndPosition"_s, ReceiverName::GPUConnectionToWebProcess, false, false },
#endif
#if ENABLE(ROUTING_ARBITRATION)
    MessageDescription { "GPUProcessConnection_BeginRoutingArbitrationWithCategory"_s, ReceiverName::GPUProcessConnection, false, false },
#endif
    MessageDescription { "GPUProcessConnection_DidInitialize"_s, ReceiverName::GPUProcessConnection, false, false },
    MessageDescription { "GPUProcessConnection_DidReceiveRemoteCommand"_s, ReceiverName::GPUProcessConnection, false, false },
#if ENABLE(ROUTING_ARBITRATION)
    MessageDescription { "GPUProcessConnection_EndRoutingArbitration"_s, ReceiverName::GPUProcessConnection, false, false },
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(COCOA)
    MessageDescription { "GPUProcessConnection_ResetAudioMediaStreamTrackRendererInternalUnit"_s, ReceiverName::GPUProcessConnection, false, false },
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    MessageDescription { "GPUProcessProxy_DidCreateContextForVisibilityPropagation"_s, ReceiverName::GPUProcessProxy, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "GPUProcessProxy_DidDrawRemoteToPDF"_s, ReceiverName::GPUProcessProxy, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcessProxy_MicrophoneMuteStatusChanged"_s, ReceiverName::GPUProcessProxy, false, false },
#endif
    MessageDescription { "GPUProcessProxy_ProcessIsReadyToExit"_s, ReceiverName::GPUProcessProxy, false, false },
#if ENABLE(AV1)
    MessageDescription { "GPUProcessProxy_SetHasAV1HardwareDecoder"_s, ReceiverName::GPUProcessProxy, false, false },
#endif
#if ENABLE(VP9)
    MessageDescription { "GPUProcessProxy_SetHasVP9HardwareDecoder"_s, ReceiverName::GPUProcessProxy, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcessProxy_StartMonitoringCaptureDeviceRotation"_s, ReceiverName::GPUProcessProxy, false, false },
#endif
#if (ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY))
    MessageDescription { "GPUProcessProxy_StatusBarWasTapped"_s, ReceiverName::GPUProcessProxy, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcessProxy_StopMonitoringCaptureDeviceRotation"_s, ReceiverName::GPUProcessProxy, false, false },
#endif
    MessageDescription { "GPUProcessProxy_TerminateWebProcess"_s, ReceiverName::GPUProcessProxy, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcessProxy_VoiceActivityDetected"_s, ReceiverName::GPUProcessProxy, false, false },
    MessageDescription { "GPUProcess_AddMockMediaDevice"_s, ReceiverName::GPUProcess, false, false },
#endif
    MessageDescription { "GPUProcess_AddSession"_s, ReceiverName::GPUProcess, false, false },
#if HAVE(SCREEN_CAPTURE_KIT)
    MessageDescription { "GPUProcess_CancelGetDisplayMediaPrompt"_s, ReceiverName::GPUProcess, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_ClearMockMediaDevices"_s, ReceiverName::GPUProcess, false, false },
#endif
#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
    MessageDescription { "GPUProcess_ConsumeAudioComponentRegistrations"_s, ReceiverName::GPUProcess, false, false },
#endif
    MessageDescription { "GPUProcess_CreateGPUConnectionToWebProcess"_s, ReceiverName::GPUProcess, true, false },
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    MessageDescription { "GPUProcess_CreateMemoryAttributionIDForTask"_s, ReceiverName::GPUProcess, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_EnableMicrophoneMuteStatusAPI"_s, ReceiverName::GPUProcess, false, false },
#endif
#if HAVE(POWERLOG_TASK_MODE_QUERY)
    MessageDescription { "GPUProcess_EnablePowerLogging"_s, ReceiverName::GPUProcess, false, false },
#endif
    MessageDescription { "GPUProcess_InitializeGPUProcess"_s, ReceiverName::GPUProcess, false, false },
#if PLATFORM(MAC)
    MessageDescription { "GPUProcess_OpenDirectoryCacheInvalidated"_s, ReceiverName::GPUProcess, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "GPUProcess_PostWillTakeSnapshotNotification"_s, ReceiverName::GPUProcess, false, false },
#endif
    MessageDescription { "GPUProcess_PrepareToSuspend"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_ProcessDidResume"_s, ReceiverName::GPUProcess, false, false },
#if HAVE(SCREEN_CAPTURE_KIT)
    MessageDescription { "GPUProcess_PromptForGetDisplayMedia"_s, ReceiverName::GPUProcess, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "GPUProcess_RegisterFonts"_s, ReceiverName::GPUProcess, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_RemoveMockMediaDevice"_s, ReceiverName::GPUProcess, false, false },
#endif
    MessageDescription { "GPUProcess_RemoveSession"_s, ReceiverName::GPUProcess, false, false },
#if ENABLE(VIDEO)
    MessageDescription { "GPUProcess_RequestBitmapImageForCurrentTime"_s, ReceiverName::GPUProcess, false, false },
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    MessageDescription { "GPUProcess_RequestSharedSimulationConnection"_s, ReceiverName::GPUProcess, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_ResetMockMediaDevices"_s, ReceiverName::GPUProcess, false, false },
#endif
#if USE(EXTENSIONKIT)
    MessageDescription { "GPUProcess_ResolveBookmarkDataForCacheDirectory"_s, ReceiverName::GPUProcess, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_RotationAngleForCaptureDeviceChanged"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_SetMockCaptureDevicesEnabled"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_SetMockCaptureDevicesInterrupted"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_SetMockMediaDeviceIsEphemeral"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_SetOrientationForMediaCapture"_s, ReceiverName::GPUProcess, false, false },
#endif
#if HAVE(AUDIT_TOKEN)
    MessageDescription { "GPUProcess_SetPresentingApplicationAuditToken"_s, ReceiverName::GPUProcess, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "GPUProcess_SetScreenProperties"_s, ReceiverName::GPUProcess, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_SetShouldListenToVoiceActivity"_s, ReceiverName::GPUProcess, false, false },
#endif
    MessageDescription { "GPUProcess_SharedPreferencesForWebProcessDidChange"_s, ReceiverName::GPUProcess, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_TriggerMockCaptureConfigurationChange"_s, ReceiverName::GPUProcess, false, false },
#endif
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    MessageDescription { "GPUProcess_UnregisterMemoryAttributionID"_s, ReceiverName::GPUProcess, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_UpdateCaptureAccess"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_UpdateCaptureOrigin"_s, ReceiverName::GPUProcess, false, false },
#endif
    MessageDescription { "GPUProcess_UpdateGPUProcessPreferences"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_UpdateSandboxAccess"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_UserPreferredLanguagesChanged"_s, ReceiverName::GPUProcess, false, false },
    MessageDescription { "GPUProcess_WebProcessConnectionCountForTesting"_s, ReceiverName::GPUProcess, false, false },
#if ENABLE(WEBXR)
    MessageDescription { "GPUProcess_WebXRPromptAccepted"_s, ReceiverName::GPUProcess, false, false },
#endif
    MessageDescription { "IPCConnectionTester_AsyncMessage"_s, ReceiverName::IPCConnectionTester, false, false },
    MessageDescription { "IPCStreamTesterProxy_WasCreated"_s, ReceiverName::IPCStreamTesterProxy, false, false },
    MessageDescription { "IPCStreamTester_AsyncPing"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCStreamTester_EmptyMessage"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCTesterReceiver_AsyncMessage"_s, ReceiverName::IPCTesterReceiver, false, false },
    MessageDescription { "IPCTester_AsyncOptionalExceptionData"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "IPCTester_AsyncPing"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "IPCTester_CreateConnectionTester"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "IPCTester_CreateConnectionTesterAndSendAsyncMessages"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "IPCTester_CreateStreamTester"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "IPCTester_SendAsyncMessageToReceiver"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "IPCTester_SendSameSemaphoreBack"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "IPCTester_SendSemaphoreBackAndSignalProtocol"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "IPCTester_StartMessageTesting"_s, ReceiverName::IPCTester, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_CreateDecoder"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_CreateEncoder"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_DecodeFrame"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_EncodeFrame"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_FlushDecoder"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_FlushEncoder"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_InitializeEncoder"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_ReleaseDecoder"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_ReleaseEncoder"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_SetDecoderFormatDescription"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_SetEncodeRates"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_SetFrameSize"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_SetRTCLoggingLevel"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_SetSharedVideoFrameMemory"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_SetSharedVideoFrameSemaphore"_s, ReceiverName::LibWebRTCCodecsProxy, false, false },
    MessageDescription { "LibWebRTCCodecs_CompletedDecoding"_s, ReceiverName::LibWebRTCCodecs, false, false },
    MessageDescription { "LibWebRTCCodecs_CompletedDecodingCV"_s, ReceiverName::LibWebRTCCodecs, false, false },
    MessageDescription { "LibWebRTCCodecs_CompletedEncoding"_s, ReceiverName::LibWebRTCCodecs, false, false },
    MessageDescription { "LibWebRTCCodecs_FailedDecoding"_s, ReceiverName::LibWebRTCCodecs, false, false },
    MessageDescription { "LibWebRTCCodecs_SetEncodingConfiguration"_s, ReceiverName::LibWebRTCCodecs, false, false },
    MessageDescription { "LibWebRTCNetwork_SignalAddressReady"_s, ReceiverName::LibWebRTCNetwork, false, false },
    MessageDescription { "LibWebRTCNetwork_SignalClose"_s, ReceiverName::LibWebRTCNetwork, false, false },
    MessageDescription { "LibWebRTCNetwork_SignalConnect"_s, ReceiverName::LibWebRTCNetwork, false, false },
    MessageDescription { "LibWebRTCNetwork_SignalReadPacket"_s, ReceiverName::LibWebRTCNetwork, false, false },
    MessageDescription { "LibWebRTCNetwork_SignalSentPacket"_s, ReceiverName::LibWebRTCNetwork, false, false },
    MessageDescription { "LibWebRTCNetwork_SignalUsedInterface"_s, ReceiverName::LibWebRTCNetwork, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_ActiveSourceBuffersChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_AddDataCue"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#if ENABLE(DATACUE_VALUE)
    MessageDescription { "MediaPlayerPrivateRemote_AddDataCueWithType"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
    MessageDescription { "MediaPlayerPrivateRemote_AddGenericCue"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_AddRemoteAudioTrack"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_AddRemoteTextTrack"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_AddRemoteVideoTrack"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_CharacteristicChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_CommitAllTransactions"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    MessageDescription { "MediaPlayerPrivateRemote_CurrentPlaybackTargetIsWirelessChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
    MessageDescription { "MediaPlayerPrivateRemote_CurrentTimeChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_DurationChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_EngineFailedToLoad"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_FirstVideoFrameAvailable"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "MediaPlayerPrivateRemote_GetRawCookies"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    MessageDescription { "MediaPlayerPrivateRemote_InitializationDataEncountered"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "MediaPlayerPrivateRemote_LayerHostingContextChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    MessageDescription { "MediaPlayerPrivateRemote_MediaPlayerKeyNeeded"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
    MessageDescription { "MediaPlayerPrivateRemote_MuteChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_NetworkStateChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_ParseWebVTTCueData"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_ParseWebVTTCueDataStruct"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_ParseWebVTTFileHeader"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_PlaybackStateChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "MediaPlayerPrivateRemote_PushVideoFrameMetadata"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
    MessageDescription { "MediaPlayerPrivateRemote_RateChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_ReadyStateChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RemoteAudioTrackConfigurationChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RemoteTextTrackConfigurationChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RemoteVideoTrackConfigurationChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#if ENABLE(DATACUE_VALUE)
    MessageDescription { "MediaPlayerPrivateRemote_RemoveDataCue"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
    MessageDescription { "MediaPlayerPrivateRemote_RemoveGenericCue"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RemoveRemoteAudioTrack"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RemoveRemoteTextTrack"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RemoveRemoteVideoTrack"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RemoveResource"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RenderingModeChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_ReportGPUMemoryFootprint"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_RequestResource"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_ResourceNotSupported"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_Seeked"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_SendH2Ping"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_SendInternalMessage"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_SizeChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_TimeChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_UpdateCachedState"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#if ENABLE(DATACUE_VALUE)
    MessageDescription { "MediaPlayerPrivateRemote_UpdateDataCue"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
    MessageDescription { "MediaPlayerPrivateRemote_UpdateGenericCue"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_UpdatePlaybackQualityMetrics"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_VolumeChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#if ENABLE(ENCRYPTED_MEDIA)
    MessageDescription { "MediaPlayerPrivateRemote_WaitingForKeyChanged"_s, ReceiverName::MediaPlayerPrivateRemote, false, false },
#endif
    MessageDescription { "MediaSourcePrivateRemoteMessageReceiver_ProxySeekToTime"_s, ReceiverName::MediaSourcePrivateRemoteMessageReceiver, false, false },
    MessageDescription { "MediaSourcePrivateRemoteMessageReceiver_ProxyWaitForTarget"_s, ReceiverName::MediaSourcePrivateRemoteMessageReceiver, false, false },
    MessageDescription { "ModelConnectionToWebProcess_ConfigureLoggingChannel"_s, ReceiverName::ModelConnectionToWebProcess, false, false },
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    MessageDescription { "ModelConnectionToWebProcess_CreateVisibilityPropagationContextForPage"_s, ReceiverName::ModelConnectionToWebProcess, false, false },
    MessageDescription { "ModelConnectionToWebProcess_DestroyVisibilityPropagationContextForPage"_s, ReceiverName::ModelConnectionToWebProcess, false, false },
#endif
    MessageDescription { "ModelProcessConnection_DidInitialize"_s, ReceiverName::ModelProcessConnection, false, false },
    MessageDescription { "ModelProcessConnection_DidUnloadModelPlayer"_s, ReceiverName::ModelProcessConnection, false, false },
    MessageDescription { "ModelProcessModelPlayerManagerProxy_CreateModelPlayer"_s, ReceiverName::ModelProcessModelPlayerManagerProxy, false, false },
    MessageDescription { "ModelProcessModelPlayerManagerProxy_DeleteModelPlayer"_s, ReceiverName::ModelProcessModelPlayerManagerProxy, false, false },
    MessageDescription { "ModelProcessModelPlayer_DidCreateLayer"_s, ReceiverName::ModelProcessModelPlayer, false, false },
    MessageDescription { "ModelProcessModelPlayer_DidFailLoading"_s, ReceiverName::ModelProcessModelPlayer, false, false },
    MessageDescription { "ModelProcessModelPlayer_DidFinishEnvironmentMapLoading"_s, ReceiverName::ModelProcessModelPlayer, false, false },
    MessageDescription { "ModelProcessModelPlayer_DidFinishLoading"_s, ReceiverName::ModelProcessModelPlayer, false, false },
    MessageDescription { "ModelProcessModelPlayer_DidUnload"_s, ReceiverName::ModelProcessModelPlayer, false, false },
    MessageDescription { "ModelProcessModelPlayer_DidUpdateAnimationPlaybackState"_s, ReceiverName::ModelProcessModelPlayer, false, false },
    MessageDescription { "ModelProcessModelPlayer_DidUpdateEntityTransform"_s, ReceiverName::ModelProcessModelPlayer, false, false },
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    MessageDescription { "ModelProcessProxy_DidCreateContextForVisibilityPropagation"_s, ReceiverName::ModelProcessProxy, false, false },
#endif
    MessageDescription { "ModelProcessProxy_ProcessIsReadyToExit"_s, ReceiverName::ModelProcessProxy, false, false },
#if PLATFORM(VISION) && ENABLE(GPU_PROCESS)
    MessageDescription { "ModelProcessProxy_RequestSharedSimulationConnection"_s, ReceiverName::ModelProcessProxy, false, false },
#endif
    MessageDescription { "ModelProcessProxy_TerminateWebProcess"_s, ReceiverName::ModelProcessProxy, false, false },
    MessageDescription { "ModelProcess_AddSession"_s, ReceiverName::ModelProcess, false, false },
    MessageDescription { "ModelProcess_CreateModelConnectionToWebProcess"_s, ReceiverName::ModelProcess, true, false },
    MessageDescription { "ModelProcess_InitializeModelProcess"_s, ReceiverName::ModelProcess, false, false },
    MessageDescription { "ModelProcess_ModelPlayerCountForTesting"_s, ReceiverName::ModelProcess, false, false },
    MessageDescription { "ModelProcess_PrepareToSuspend"_s, ReceiverName::ModelProcess, false, false },
    MessageDescription { "ModelProcess_ProcessDidResume"_s, ReceiverName::ModelProcess, false, false },
    MessageDescription { "ModelProcess_RemoveSession"_s, ReceiverName::ModelProcess, false, false },
    MessageDescription { "ModelProcess_SharedPreferencesForWebProcessDidChange"_s, ReceiverName::ModelProcess, false, false },
    MessageDescription { "ModelProcess_WebProcessConnectionCountForTesting"_s, ReceiverName::ModelProcess, false, false },
    MessageDescription { "NetworkBroadcastChannelRegistry_PostMessage"_s, ReceiverName::NetworkBroadcastChannelRegistry, false, false },
    MessageDescription { "NetworkBroadcastChannelRegistry_RegisterChannel"_s, ReceiverName::NetworkBroadcastChannelRegistry, false, false },
    MessageDescription { "NetworkBroadcastChannelRegistry_UnregisterChannel"_s, ReceiverName::NetworkBroadcastChannelRegistry, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_AddOriginAccessAllowListEntry"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_BrowsingContextRemoved"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#if (PLATFORM(MAC) && ENABLE(LAUNCHSERVICES_SANDBOX_EXTENSION_BLOCKING))
    MessageDescription { "NetworkConnectionToWebProcess_CheckInWebProcess"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_ClearFrameLoadRecordsForStorageAccess"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_ClearPageSpecificData"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CloseSWContextConnection"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CloseSharedWorkerContextConnection"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#if ENABLE(WEB_RTC)
    MessageDescription { "NetworkConnectionToWebProcess_ConnectToRTCDataChannelRemoteSource"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_ConvertMainResourceLoadToDownload"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CookiesEnabled"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CookiesForDOMAsync"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CreateNewMessagePortChannel"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CreateRTCProvider"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CreateSocketChannel"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_DeleteCookie"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_DestroyWebTransportSession"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_DidDeliverMessagePortMessages"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_EntangleLocalPortInThisProcessToRemote"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_EstablishSWContextConnection"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_EstablishSharedWorkerContextConnection"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#if PLATFORM(MAC)
    MessageDescription { "NetworkConnectionToWebProcess_GetProcessDisplayName"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_HasStorageAccess"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_InitializeWebTransportSession"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#if ENABLE(CONTENT_FILTERING)
    MessageDescription { "NetworkConnectionToWebProcess_InstallMockContentFilter"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_IsLoggedIn"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_IsResourceLoadFinished"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_LoadImageForDecoding"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_LoadPing"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_LogUserInteraction"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_MessagePortClosed"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_MessagePortDisentangled"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#if ENABLE(DECLARATIVE_WEB_PUSH)
    MessageDescription { "NetworkConnectionToWebProcess_NavigatorGetPushPermissionState"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_NavigatorGetPushSubscription"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_NavigatorSubscribeToPushService"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_NavigatorUnsubscribeFromPushService"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_PageLoadCompleted"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_PingPongForServiceWorkers"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_PostMessageToRemote"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_PreconnectTo"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_PrefetchDNS"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_PrioritizeResourceLoads"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterBlobPathForTesting"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterBlobURL"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterBlobURLHandle"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterInternalBlobURL"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterInternalBlobURLForSlice"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterInternalBlobURLOptionallyFileBacked"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterInternalFileBlobURL"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterURLSchemesAsCORSEnabled"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RemoveLoadIdentifier"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RemoveOriginAccessAllowListEntry"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RemoveStorageAccessForFrame"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RequestStorageAccess"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RequestStorageAccessUnderOpener"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_ResetOriginAccessAllowLists"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_ResourceLoadStatisticsUpdated"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_ScheduleResourceLoad"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SendH2Ping"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetCORSDisablingPatterns"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetCaptureExtraNetworkLoadMetricsEnabled"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetCookieFromDOMAsync"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetCookiesFromDOM"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetLoginStatus"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetRawCookie"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetResourceLoadSchedulingMode"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "NetworkConnectionToWebProcess_ShouldOffloadIFrameForHost"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_StartDownload"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_StorageAccessQuirkForTopFrameDomain"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    MessageDescription { "NetworkConnectionToWebProcess_SubscribeToCookieChangeNotifications"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_TakeAllMessagesForPort"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_UnregisterBlobURL"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_UnregisterBlobURLHandle"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    MessageDescription { "NetworkConnectionToWebProcess_UnsubscribeFromCookieChangeNotifications"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "NetworkConnectionToWebProcess_UpdateActivePages"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_UseRedirectionForCurrentNavigation"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_WriteBlobsToTemporaryFilesForIndexedDB"_s, ReceiverName::NetworkConnectionToWebProcess, false, false },
    MessageDescription { "NetworkContentRuleListManager_AddContentRuleLists"_s, ReceiverName::NetworkContentRuleListManager, false, false },
    MessageDescription { "NetworkContentRuleListManager_Remove"_s, ReceiverName::NetworkContentRuleListManager, false, false },
    MessageDescription { "NetworkContentRuleListManager_RemoveAllContentRuleLists"_s, ReceiverName::NetworkContentRuleListManager, false, false },
    MessageDescription { "NetworkContentRuleListManager_RemoveContentRuleList"_s, ReceiverName::NetworkContentRuleListManager, false, false },
    MessageDescription { "NetworkMDNSRegister_RegisterMDNSName"_s, ReceiverName::NetworkMDNSRegister, false, false },
    MessageDescription { "NetworkMDNSRegister_UnregisterMDNSNames"_s, ReceiverName::NetworkMDNSRegister, false, false },
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    MessageDescription { "NetworkProcessConnection_AllCookiesDeleted"_s, ReceiverName::NetworkProcessConnection, false, false },
#endif
    MessageDescription { "NetworkProcessConnection_BroadcastConsoleMessage"_s, ReceiverName::NetworkProcessConnection, false, false },
#if ENABLE(WEB_RTC)
    MessageDescription { "NetworkProcessConnection_ConnectToRTCDataChannelRemoteSource"_s, ReceiverName::NetworkProcessConnection, false, false },
#endif
    MessageDescription { "NetworkProcessConnection_CookieAcceptPolicyChanged"_s, ReceiverName::NetworkProcessConnection, false, false },
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    MessageDescription { "NetworkProcessConnection_CookiesAdded"_s, ReceiverName::NetworkProcessConnection, false, false },
    MessageDescription { "NetworkProcessConnection_CookiesDeleted"_s, ReceiverName::NetworkProcessConnection, false, false },
#endif
#if ENABLE(SHAREABLE_RESOURCE)
    MessageDescription { "NetworkProcessConnection_DidCacheResource"_s, ReceiverName::NetworkProcessConnection, false, false },
#endif
    MessageDescription { "NetworkProcessConnection_DidFinishPingLoad"_s, ReceiverName::NetworkProcessConnection, false, false },
    MessageDescription { "NetworkProcessConnection_DidFinishPreconnection"_s, ReceiverName::NetworkProcessConnection, false, false },
    MessageDescription { "NetworkProcessConnection_LoadCancelledDownloadRedirectRequestInFrame"_s, ReceiverName::NetworkProcessConnection, false, false },
    MessageDescription { "NetworkProcessConnection_MessagesAvailableForPort"_s, ReceiverName::NetworkProcessConnection, false, false },
    MessageDescription { "NetworkProcessConnection_SetOnLineState"_s, ReceiverName::NetworkProcessConnection, false, false },
    MessageDescription { "NetworkProcessConnection_UpdateCachedCookiesEnabled"_s, ReceiverName::NetworkProcessConnection, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "NetworkProcessProxy_ContentExtensionRules"_s, ReceiverName::NetworkProcessProxy, false, false },
#endif
    MessageDescription { "NetworkProcessProxy_CookiesDidChange"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DataTaskDidCompleteWithError"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DataTaskDidReceiveData"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DataTaskDidReceiveResponse"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DataTaskReceivedChallenge"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DataTaskWillPerformHTTPRedirection"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DeleteWebsiteDataInUIProcessForRegistrableDomains"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DeleteWebsiteDataInWebProcessesForOrigin"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DidAllowPrivateTokenUsageByThirdPartyForTesting"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DidBlockLoadToKnownTracker"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DidCommitCrossSiteLoadWithDataTransferFromPrevalentResource"_s, ReceiverName::NetworkProcessProxy, false, false },
#if USE(SOUP)
    MessageDescription { "NetworkProcessProxy_DidExceedMemoryLimit"_s, ReceiverName::NetworkProcessProxy, false, false },
#endif
    MessageDescription { "NetworkProcessProxy_DidNegotiateModernTLS"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_DidReceiveAuthenticationChallenge"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_EndServiceWorkerBackgroundProcessing"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_EstablishRemoteWorkerContextConnectionToNetworkProcess"_s, ReceiverName::NetworkProcessProxy, false, false },
#if ENABLE(APP_BOUND_DOMAINS)
    MessageDescription { "NetworkProcessProxy_GetAppBoundDomains"_s, ReceiverName::NetworkProcessProxy, false, false },
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI)
    MessageDescription { "NetworkProcessProxy_GetPaymentCoordinatorEmbeddingUserAgent"_s, ReceiverName::NetworkProcessProxy, false, false },
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI_USES_SCENE)
    MessageDescription { "NetworkProcessProxy_GetWindowSceneAndBundleIdentifierForPaymentPresentation"_s, ReceiverName::NetworkProcessProxy, false, false },
#endif
    MessageDescription { "NetworkProcessProxy_IncreaseQuota"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_LogDiagnosticMessage"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_LogDiagnosticMessageWithResult"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_LogDiagnosticMessageWithValue"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_LogTestingEvent"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_NavigateServiceWorkerClient"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_NegotiatedLegacyTLS"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_NotifyBackgroundFetchChange"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_OpenWindowFromServiceWorker"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_ProcessHasUnresponseServiceWorker"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_RegisterRemoteWorkerClientProcess"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_ReloadExecutionContextsForOrigin"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_RemoteWorkerContextConnectionNoLongerNeeded"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_ReportConsoleMessage"_s, ReceiverName::NetworkProcessProxy, false, false },
#if ENABLE(NETWORK_ISSUE_REPORTING)
    MessageDescription { "NetworkProcessProxy_ReportNetworkIssue"_s, ReceiverName::NetworkProcessProxy, false, false },
#endif
    MessageDescription { "NetworkProcessProxy_RequestBackgroundFetchPermission"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_RequestStorageAccessConfirm"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_ResourceLoadDidCompleteWithError"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_ResourceLoadDidPerformHTTPRedirection"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_ResourceLoadDidReceiveChallenge"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_ResourceLoadDidReceiveResponse"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_ResourceLoadDidSendRequest"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_SetDomainsWithCrossPageStorageAccess"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_SetDomainsWithUserInteraction"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_SetWebProcessHasUploads"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_StartServiceWorkerBackgroundProcessing"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_TerminateWebProcess"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_TriggerBrowsingContextGroupSwitchForNavigation"_s, ReceiverName::NetworkProcessProxy, false, false },
    MessageDescription { "NetworkProcessProxy_UnregisterRemoteWorkerClientProcess"_s, ReceiverName::NetworkProcessProxy, false, false },
#if USE(RUNNINGBOARD)
    MessageDescription { "NetworkProcessProxy_WakeUpWebProcessForIPC"_s, ReceiverName::NetworkProcessProxy, false, false },
#endif
    MessageDescription { "NetworkProcess_AbortBackgroundFetch"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_AddAllowedFirstPartyForCookies"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_AddWebPageNetworkParameters"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_AddWebsiteDataStore"_s, ReceiverName::NetworkProcess, true, false },
    MessageDescription { "NetworkProcess_AllowFileAccessFromWebProcess"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_AllowFilesAccessFromWebProcess"_s, ReceiverName::NetworkProcess, false, false },
#if !PLATFORM(COCOA)
    MessageDescription { "NetworkProcess_AllowSpecificHTTPSCertificateForHost"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_AllowTLSCertificateChainForLocalPCMTesting"_s, ReceiverName::NetworkProcess, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "NetworkProcess_AppPrivacyReportTestingData"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_ApplicationDidEnterBackground"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ApplicationWillEnterForeground"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_CancelDataTask"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_CancelDownload"_s, ReceiverName::NetworkProcess, false, false },
#if ENABLE(APP_BOUND_DOMAINS)
    MessageDescription { "NetworkProcess_ClearAppBoundSession"_s, ReceiverName::NetworkProcess, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "NetworkProcess_ClearAppPrivacyReportTestingData"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_ClearBundleIdentifier"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ClearPrevalentResource"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ClearPrivateClickMeasurement"_s, ReceiverName::NetworkProcess, false, false },
#if HAVE(NW_PROXY_CONFIG)
    MessageDescription { "NetworkProcess_ClearProxyConfigData"_s, ReceiverName::NetworkProcess, false, false },
#endif
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
    MessageDescription { "NetworkProcess_ClearServiceWorkerEntitlementOverride"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_ClearUserInteraction"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ClickBackgroundFetch"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_CloneSessionStorageForWebPage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_CloseITPDatabase"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ClosePCMDatabase"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_CountNonDefaultSessionSets"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_CreateNetworkConnectionToWebProcess"_s, ReceiverName::NetworkProcess, true, false },
    MessageDescription { "NetworkProcess_DataTaskWithRequest"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DeleteCookiesForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DeleteWebsiteData"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DeleteWebsiteDataForOrigins"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DestroySession"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DidCommitCrossSiteLoadWithDataTransfer"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DidIncreaseQuota"_s, ReceiverName::NetworkProcess, false, false },
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
    MessageDescription { "NetworkProcess_DisableServiceWorkerEntitlement"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_DomainIDExistsInDatabase"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DownloadRequest"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DumpPrivateClickMeasurement"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_DumpResourceLoadStatistics"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_EnsureSessionWithDataStoreIdentifierRemoved"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_FetchLocalStorage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_FetchSessionStorage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_FetchWebsiteData"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_FlushCookies"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_GetAllBackgroundFetchIdentifiers"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_GetAllStorageAccessEntries"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_GetAppBadgeForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_GetBackgroundFetchState"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_GetPendingPushMessage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_GetPendingPushMessages"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_GetResourceLoadStatisticsDataSummary"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_GrantStorageAccessForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_HadUserInteraction"_s, ReceiverName::NetworkProcess, false, false },
#if ENABLE(APP_BOUND_DOMAINS)
    MessageDescription { "NetworkProcess_HasAppBoundSession"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_HasIsolatedSession"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_HasLocalStorage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_HasPushSubscriptionForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_InitializeNetworkProcess"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_InsertExpiredStatisticForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_IsGrandfathered"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_IsPrevalentResource"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_IsRegisteredAsRedirectingTo"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_IsRegisteredAsSubFrameUnder"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_IsRegisteredAsSubresourceUnder"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_IsRelationshipOnlyInDatabaseOnce"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_IsResourceLoadStatisticsEphemeral"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_IsVeryPrevalentResource"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_LogFrameNavigation"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_LogUserInteraction"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_MarkAttributedPrivateClickMeasurementsAsExpiredForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_MarkPrivateClickMeasurementsAsExpiredForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_MergeStatisticForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_NotifyMediaStreamingActivity"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_PauseBackgroundFetch"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_PreconnectTo"_s, ReceiverName::NetworkProcess, false, false },
#if USE(SOUP)
    MessageDescription { "NetworkProcess_PrefetchDNS"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_PrepareToSuspend"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ProcessDidResume"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ProcessNotificationEvent"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ProcessPushMessage"_s, ReceiverName::NetworkProcess, false, false },
#if (PLATFORM(COCOA) && HAVE(MODERN_DOWNLOADPROGRESS)) || (PLATFORM(COCOA) && !HAVE(MODERN_DOWNLOADPROGRESS))
    MessageDescription { "NetworkProcess_PublishDownloadProgress"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_RegisterURLSchemeAsBypassingContentSecurityPolicy"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_RegisterURLSchemeAsLocal"_s, ReceiverName::NetworkProcess, false, false },
#if ENABLE(ALL_LEGACY_REGISTERED_SPECIAL_URL_SCHEMES)
    MessageDescription { "NetworkProcess_RegisterURLSchemeAsNoAccess"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_RegisterURLSchemeAsSecure"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_RemovePushSubscriptionsForOrigin"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_RemoveWebPageNetworkParameters"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_RenameOriginInWebsiteData"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ResetCacheMaxAgeCapForPrevalentResources"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ResetCrossSiteLoadsWithLinkDecorationForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ResetParametersToDefaultValues"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ResetQuota"_s, ReceiverName::NetworkProcess, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "NetworkProcess_ResetResourceMonitorThrottlerForTesting"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_ResetStoragePersistedState"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_RestoreLocalStorage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_RestoreSessionStorage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ResumeBackgroundFetch"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ResumeDownload"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_RunningOrTerminatingServiceWorkerCountForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ScheduleClearInMemoryAndPersistent"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ScheduleCookieBlockingUpdate"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_ScheduleStatisticsAndDataRecordsProcessing"_s, ReceiverName::NetworkProcess, false, false },
#if ENABLE(APP_BOUND_DOMAINS)
    MessageDescription { "NetworkProcess_SetAppBoundDomainsForResourceLoadStatistics"_s, ReceiverName::NetworkProcess, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "NetworkProcess_SetBackupExclusionPeriodForTesting"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_SetCacheMaxAgeCapForPrevalentResources"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetCacheModel"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetCrossSiteLoadWithLinkDecorationForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetDefaultRequestTimeoutInterval"_s, ReceiverName::NetworkProcess, false, false },
#if ENABLE(INSPECTOR_NETWORK_THROTTLING)
    MessageDescription { "NetworkProcess_SetEmulatedConditions"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_SetFirstPartyHostCNAMEDomainForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetFirstPartyWebsiteDataRemovalModeForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetGrandfathered"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetGrandfatheringTime"_s, ReceiverName::NetworkProcess, false, false },
#if USE(SOUP)
    MessageDescription { "NetworkProcess_SetIgnoreTLSErrors"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_SetInspectionForServiceWorkersAllowed"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetIsRunningResourceLoadStatisticsTest"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetLastSeen"_s, ReceiverName::NetworkProcess, false, false },
#if ENABLE(MANAGED_DOMAINS)
    MessageDescription { "NetworkProcess_SetManagedDomainsForResourceLoadStatistics"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_SetMaxStatisticsEntries"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetMinimumTimeBetweenDataRecordsRemoval"_s, ReceiverName::NetworkProcess, false, false },
#if USE(SOUP) || USE(CURL)
    MessageDescription { "NetworkProcess_SetNetworkProxySettings"_s, ReceiverName::NetworkProcess, false, false },
#endif
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES)
    MessageDescription { "NetworkProcess_SetOptInCookiePartitioningEnabled"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_SetOriginQuotaRatioEnabledForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPCMFraudPreventionValuesForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPersistedDomains"_s, ReceiverName::NetworkProcess, false, false },
#if USE(SOUP)
    MessageDescription { "NetworkProcess_SetPersistentCredentialStorageEnabled"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_SetPrevalentResource"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPrevalentResourceForDebugMode"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementAppBundleIDForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementAttributionReportURLsForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementDebugMode"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementEphemeralMeasurementForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementOverrideTimerForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementTokenPublicKeyURLForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementTokenSignatureURLForTesting"_s, ReceiverName::NetworkProcess, false, false },
#if HAVE(NW_PROXY_CONFIG)
    MessageDescription { "NetworkProcess_SetProxyConfigData"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_SetPruneEntriesDownTo"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetPushAndNotificationsEnabledForOrigin"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetResourceLoadStatisticsDebugMode"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetResourceLoadStatisticsLogTestingEvent"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetResourceLoadStatisticsTimeAdvanceForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetSessionIsControlledByAutomation"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetShouldClassifyResourcesBeforeDataRecordsRemoval"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetShouldDowngradeReferrerForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetShouldEnbleSameSiteStrictEnforcementForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetShouldRelaxThirdPartyCookieBlockingForPage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetShouldSendPrivateTokenIPCForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetStorageSiteValidationEnabled"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetSubframeUnderTopFrameDomain"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetSubresourceUnderTopFrameDomain"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetSubresourceUniqueRedirectFrom"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetSubresourceUniqueRedirectTo"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetThirdPartyCNAMEDomainForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetThirdPartyCookieBlockingMode"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetTimeToLiveUserInteraction"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetToSameSiteStrictCookiesForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetTopFrameUniqueRedirectFrom"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetTopFrameUniqueRedirectTo"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetTrackingPreventionEnabled"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SetVeryPrevalentResource"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SharedPreferencesForWebProcessDidChange"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SimulatePrivateClickMeasurementSessionRestart"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_StatisticsDatabaseHasAllTables"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_StorePrivateClickMeasurement"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_StoreServiceWorkerRegistrations"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_SyncLocalStorage"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_TerminateIdleServiceWorkers"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_TerminateRemoteWorkerContextConnectionWhenPossible"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_UpdateBundleIdentifier"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_UpdatePrevalentDomainsToBlockCookiesFor"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkProcess_UpdateStorageAccessPromptQuirks"_s, ReceiverName::NetworkProcess, false, false },
#if USE(SOUP)
    MessageDescription { "NetworkProcess_UserPreferredLanguagesChanged"_s, ReceiverName::NetworkProcess, false, false },
#endif
    MessageDescription { "NetworkProcess_WebsiteDataOriginDirectoryForTesting"_s, ReceiverName::NetworkProcess, false, false },
    MessageDescription { "NetworkRTCMonitor_StartUpdatingIfNeeded"_s, ReceiverName::NetworkRTCMonitor, false, false },
    MessageDescription { "NetworkRTCMonitor_StopUpdating"_s, ReceiverName::NetworkRTCMonitor, false, false },
    MessageDescription { "NetworkRTCProvider_CloseSocket"_s, ReceiverName::NetworkRTCProvider, false, false },
    MessageDescription { "NetworkRTCProvider_CreateClientTCPSocket"_s, ReceiverName::NetworkRTCProvider, false, false },
    MessageDescription { "NetworkRTCProvider_CreateResolver"_s, ReceiverName::NetworkRTCProvider, false, false },
    MessageDescription { "NetworkRTCProvider_CreateUDPSocket"_s, ReceiverName::NetworkRTCProvider, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "NetworkRTCProvider_GetInterfaceName"_s, ReceiverName::NetworkRTCProvider, false, false },
#endif
    MessageDescription { "NetworkRTCProvider_SendToSocket"_s, ReceiverName::NetworkRTCProvider, false, false },
    MessageDescription { "NetworkRTCProvider_SetSocketOption"_s, ReceiverName::NetworkRTCProvider, false, false },
    MessageDescription { "NetworkRTCProvider_StopResolver"_s, ReceiverName::NetworkRTCProvider, false, false },
    MessageDescription { "NetworkResourceLoader_ContinueDidReceiveResponse"_s, ReceiverName::NetworkResourceLoader, false, false },
    MessageDescription { "NetworkSocketChannel_Close"_s, ReceiverName::NetworkSocketChannel, false, false },
    MessageDescription { "NetworkSocketChannel_SendData"_s, ReceiverName::NetworkSocketChannel, false, false },
    MessageDescription { "NetworkSocketChannel_SendString"_s, ReceiverName::NetworkSocketChannel, false, false },
    MessageDescription { "NetworkStorageManager_AbortOpenAndUpgradeNeeded"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_AbortTransaction"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageAllCaches"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageClearMemoryRepresentation"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageDereference"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageOpenCache"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStoragePutRecords"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageReference"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageRemoveCache"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageRemoveRecords"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageRepresentation"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageRetrieveRecords"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CancelConnectToStorageArea"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_Clear"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_ClearObjectStore"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CloseHandle"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CloseSyncAccessHandle"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CloseWritable"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CommitTransaction"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_ConnectToStorageArea"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CreateIndex"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CreateObjectStore"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CreateSyncAccessHandle"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_CreateWritable"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DatabaseConnectionClosed"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DatabaseConnectionPendingClose"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DeleteDatabase"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DeleteIndex"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DeleteObjectStore"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DeleteRecord"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DidFinishHandlingVersionChangeTransaction"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DidFireVersionChangeEvent"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DidGenerateIndexKeyForRecord"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_DisconnectFromStorageArea"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_EstablishTransaction"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_Estimate"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_ExecuteCommandForWritable"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_FileSystemGetDirectory"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetAllDatabaseNamesAndVersions"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetAllRecords"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetCount"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetDirectoryHandle"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetFile"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetFileHandle"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetHandle"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetHandleNames"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_GetRecord"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_IsSameEntry"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_IterateCursor"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_LockCacheStorage"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_Move"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_OpenCursor"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_OpenDBRequestCancelled"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_OpenDatabase"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_Persist"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_Persisted"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_PutOrAdd"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_RemoveEntry"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_RemoveItem"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_RenameIndex"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_RenameObjectStore"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_RequestNewCapacityForSyncAccessHandle"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_ResetQuotaUpdatedBasedOnUsageForTesting"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_Resolve"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_SetItem"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkStorageManager_UnlockCacheStorage"_s, ReceiverName::NetworkStorageManager, false, false },
    MessageDescription { "NetworkTransportSession_CancelReceiveStream"_s, ReceiverName::NetworkTransportSession, false, false },
    MessageDescription { "NetworkTransportSession_CancelSendStream"_s, ReceiverName::NetworkTransportSession, false, false },
    MessageDescription { "NetworkTransportSession_CreateBidirectionalStream"_s, ReceiverName::NetworkTransportSession, false, false },
    MessageDescription { "NetworkTransportSession_CreateOutgoingUnidirectionalStream"_s, ReceiverName::NetworkTransportSession, false, false },
    MessageDescription { "NetworkTransportSession_DestroyStream"_s, ReceiverName::NetworkTransportSession, false, false },
    MessageDescription { "NetworkTransportSession_SendDatagram"_s, ReceiverName::NetworkTransportSession, false, false },
    MessageDescription { "NetworkTransportSession_StreamSendBytes"_s, ReceiverName::NetworkTransportSession, false, false },
    MessageDescription { "NetworkTransportSession_Terminate"_s, ReceiverName::NetworkTransportSession, false, false },
#if ENABLE(NOTIFICATIONS)
    MessageDescription { "NotificationManagerMessageHandler_CancelNotification"_s, ReceiverName::NotificationManagerMessageHandler, false, false },
    MessageDescription { "NotificationManagerMessageHandler_ClearNotifications"_s, ReceiverName::NotificationManagerMessageHandler, false, false },
    MessageDescription { "NotificationManagerMessageHandler_DidDestroyNotification"_s, ReceiverName::NotificationManagerMessageHandler, false, false },
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    MessageDescription { "NotificationManagerMessageHandler_GetPermissionState"_s, ReceiverName::NotificationManagerMessageHandler, false, false },
#endif
#if ENABLE(NOTIFICATIONS)
    MessageDescription { "NotificationManagerMessageHandler_PageWasNotifiedOfNotificationPermission"_s, ReceiverName::NotificationManagerMessageHandler, false, false },
    MessageDescription { "NotificationManagerMessageHandler_RequestPermission"_s, ReceiverName::NotificationManagerMessageHandler, false, false },
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    MessageDescription { "NotificationManagerMessageHandler_SetAppBadge"_s, ReceiverName::NotificationManagerMessageHandler, false, false },
#endif
#if ENABLE(NOTIFICATIONS)
    MessageDescription { "NotificationManagerMessageHandler_ShowNotification"_s, ReceiverName::NotificationManagerMessageHandler, false, false },
#endif
    MessageDescription { "PlatformXRSystemProxy_SessionDidEnd"_s, ReceiverName::PlatformXRSystemProxy, false, false },
    MessageDescription { "PlatformXRSystemProxy_SessionDidUpdateVisibilityState"_s, ReceiverName::PlatformXRSystemProxy, false, false },
#if USE(OPENXR)
    MessageDescription { "PlatformXRSystem_CreateLayerProjection"_s, ReceiverName::PlatformXRSystem, false, false },
#endif
    MessageDescription { "PlatformXRSystem_DidCompleteShutdownTriggeredBySystem"_s, ReceiverName::PlatformXRSystem, false, false },
    MessageDescription { "PlatformXRSystem_EnumerateImmersiveXRDevices"_s, ReceiverName::PlatformXRSystem, false, false },
    MessageDescription { "PlatformXRSystem_InitializeTrackingAndRendering"_s, ReceiverName::PlatformXRSystem, false, false },
    MessageDescription { "PlatformXRSystem_RequestFrame"_s, ReceiverName::PlatformXRSystem, false, false },
    MessageDescription { "PlatformXRSystem_RequestPermissionOnSessionFeatures"_s, ReceiverName::PlatformXRSystem, false, false },
    MessageDescription { "PlatformXRSystem_ShutDownTrackingAndRendering"_s, ReceiverName::PlatformXRSystem, false, false },
#if USE(OPENXR) || !USE(OPENXR)
    MessageDescription { "PlatformXRSystem_SubmitFrame"_s, ReceiverName::PlatformXRSystem, false, false },
#endif
    MessageDescription { "PushClientConnection_CancelNotification"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_GetAppBadgeForTesting"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_GetNotifications"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_GetPendingPushMessage"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_GetPendingPushMessages"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_GetPushPermissionState"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_GetPushSubscription"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_GetPushTopicsForTesting"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_IncrementSilentPushCount"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_InitializeConnection"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_InjectEncryptedPushMessageForTesting"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_InjectPushMessageForTesting"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_RemoveAllPushSubscriptions"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_RemovePushSubscriptionsForOrigin"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_RequestPushPermission"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_SetAppBadge"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_SetProtocolVersionForTesting"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_SetPublicTokenForTesting"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_SetPushAndNotificationsEnabledForOrigin"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_SetServiceWorkerIsBeingInspected"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_ShowNotification"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_SubscribeToPushService"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "PushClientConnection_UnsubscribeFromPushService"_s, ReceiverName::PushClientConnection, false, false },
    MessageDescription { "RTCDataChannelRemoteManagerProxy_BufferedAmountIsDecreasing"_s, ReceiverName::RTCDataChannelRemoteManagerProxy, false, false },
    MessageDescription { "RTCDataChannelRemoteManagerProxy_ChangeReadyState"_s, ReceiverName::RTCDataChannelRemoteManagerProxy, false, false },
    MessageDescription { "RTCDataChannelRemoteManagerProxy_Close"_s, ReceiverName::RTCDataChannelRemoteManagerProxy, false, false },
    MessageDescription { "RTCDataChannelRemoteManagerProxy_DetectError"_s, ReceiverName::RTCDataChannelRemoteManagerProxy, false, false },
    MessageDescription { "RTCDataChannelRemoteManagerProxy_ReceiveData"_s, ReceiverName::RTCDataChannelRemoteManagerProxy, false, false },
    MessageDescription { "RTCDataChannelRemoteManagerProxy_SendData"_s, ReceiverName::RTCDataChannelRemoteManagerProxy, false, false },
    MessageDescription { "RTCDataChannelRemoteManager_BufferedAmountIsDecreasing"_s, ReceiverName::RTCDataChannelRemoteManager, false, false },
    MessageDescription { "RTCDataChannelRemoteManager_ChangeReadyState"_s, ReceiverName::RTCDataChannelRemoteManager, false, false },
    MessageDescription { "RTCDataChannelRemoteManager_Close"_s, ReceiverName::RTCDataChannelRemoteManager, false, false },
    MessageDescription { "RTCDataChannelRemoteManager_DetectError"_s, ReceiverName::RTCDataChannelRemoteManager, false, false },
    MessageDescription { "RTCDataChannelRemoteManager_ReceiveData"_s, ReceiverName::RTCDataChannelRemoteManager, false, false },
    MessageDescription { "RTCDataChannelRemoteManager_SendData"_s, ReceiverName::RTCDataChannelRemoteManager, false, false },
    MessageDescription { "RemoteAdapter_Destruct"_s, ReceiverName::RemoteAdapter, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteAudioDestinationManager_AudioSamplesStorageChanged"_s, ReceiverName::RemoteAudioDestinationManager, false, false },
#endif
    MessageDescription { "RemoteAudioDestinationManager_CreateAudioDestination"_s, ReceiverName::RemoteAudioDestinationManager, false, false },
    MessageDescription { "RemoteAudioDestinationManager_DeleteAudioDestination"_s, ReceiverName::RemoteAudioDestinationManager, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "RemoteAudioDestinationManager_SetSceneIdentifier"_s, ReceiverName::RemoteAudioDestinationManager, false, false },
#endif
    MessageDescription { "RemoteAudioDestinationManager_StartAudioDestination"_s, ReceiverName::RemoteAudioDestinationManager, false, false },
    MessageDescription { "RemoteAudioDestinationManager_StopAudioDestination"_s, ReceiverName::RemoteAudioDestinationManager, false, false },
    MessageDescription { "RemoteAudioHardwareListener_AudioHardwareDidBecomeActive"_s, ReceiverName::RemoteAudioHardwareListener, false, false },
    MessageDescription { "RemoteAudioHardwareListener_AudioHardwareDidBecomeInactive"_s, ReceiverName::RemoteAudioHardwareListener, false, false },
    MessageDescription { "RemoteAudioHardwareListener_AudioOutputDeviceChanged"_s, ReceiverName::RemoteAudioHardwareListener, false, false },
    MessageDescription { "RemoteAudioMediaStreamTrackRendererInternalUnitManager_CreateUnit"_s, ReceiverName::RemoteAudioMediaStreamTrackRendererInternalUnitManager, false, false },
    MessageDescription { "RemoteAudioMediaStreamTrackRendererInternalUnitManager_DeleteUnit"_s, ReceiverName::RemoteAudioMediaStreamTrackRendererInternalUnitManager, false, false },
    MessageDescription { "RemoteAudioMediaStreamTrackRendererInternalUnitManager_SetLastDeviceUsed"_s, ReceiverName::RemoteAudioMediaStreamTrackRendererInternalUnitManager, false, false },
    MessageDescription { "RemoteAudioMediaStreamTrackRendererInternalUnitManager_StartUnit"_s, ReceiverName::RemoteAudioMediaStreamTrackRendererInternalUnitManager, false, false },
    MessageDescription { "RemoteAudioMediaStreamTrackRendererInternalUnitManager_StopUnit"_s, ReceiverName::RemoteAudioMediaStreamTrackRendererInternalUnitManager, false, false },
    MessageDescription { "RemoteAudioSessionProxy_BeginInterruptionRemote"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSessionProxy_EndInterruptionRemote"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSessionProxy_SetCategory"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSessionProxy_SetIsPlayingToBluetoothOverride"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSessionProxy_SetPreferredBufferSize"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSessionProxy_SetSceneIdentifier"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSessionProxy_SetSoundStageSize"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSessionProxy_TriggerBeginInterruptionForTesting"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSessionProxy_TriggerEndInterruptionForTesting"_s, ReceiverName::RemoteAudioSessionProxy, false, false },
    MessageDescription { "RemoteAudioSession_BeginInterruptionRemote"_s, ReceiverName::RemoteAudioSession, false, false },
    MessageDescription { "RemoteAudioSession_ConfigurationChanged"_s, ReceiverName::RemoteAudioSession, false, false },
    MessageDescription { "RemoteAudioSession_EndInterruptionRemote"_s, ReceiverName::RemoteAudioSession, false, false },
    MessageDescription { "RemoteAudioSourceProviderManager_AudioSamplesAvailable"_s, ReceiverName::RemoteAudioSourceProviderManager, false, false },
    MessageDescription { "RemoteAudioSourceProviderManager_AudioStorageChanged"_s, ReceiverName::RemoteAudioSourceProviderManager, false, false },
    MessageDescription { "RemoteBarcodeDetector_Detect"_s, ReceiverName::RemoteBarcodeDetector, true, false },
    MessageDescription { "RemoteBindGroupLayout_Destruct"_s, ReceiverName::RemoteBindGroupLayout, true, false },
    MessageDescription { "RemoteBindGroupLayout_SetLabel"_s, ReceiverName::RemoteBindGroupLayout, true, false },
    MessageDescription { "RemoteBindGroup_Destruct"_s, ReceiverName::RemoteBindGroup, true, false },
    MessageDescription { "RemoteBindGroup_SetLabel"_s, ReceiverName::RemoteBindGroup, true, false },
    MessageDescription { "RemoteBuffer_Copy"_s, ReceiverName::RemoteBuffer, true, false },
    MessageDescription { "RemoteBuffer_CopyWithCopy"_s, ReceiverName::RemoteBuffer, true, false },
    MessageDescription { "RemoteBuffer_Destroy"_s, ReceiverName::RemoteBuffer, true, false },
    MessageDescription { "RemoteBuffer_Destruct"_s, ReceiverName::RemoteBuffer, true, false },
    MessageDescription { "RemoteBuffer_MapAsync"_s, ReceiverName::RemoteBuffer, true, false },
    MessageDescription { "RemoteBuffer_SetLabel"_s, ReceiverName::RemoteBuffer, true, false },
    MessageDescription { "RemoteBuffer_Unmap"_s, ReceiverName::RemoteBuffer, true, false },
    MessageDescription { "RemoteCDMFactoryProxy_RemoveInstance"_s, ReceiverName::RemoteCDMFactoryProxy, false, false },
    MessageDescription { "RemoteCDMFactoryProxy_RemoveSession"_s, ReceiverName::RemoteCDMFactoryProxy, false, false },
    MessageDescription { "RemoteCDMInstanceProxy_InitializeWithConfiguration"_s, ReceiverName::RemoteCDMInstanceProxy, false, false },
    MessageDescription { "RemoteCDMInstanceProxy_SetServerCertificate"_s, ReceiverName::RemoteCDMInstanceProxy, false, false },
    MessageDescription { "RemoteCDMInstanceProxy_SetStorageDirectory"_s, ReceiverName::RemoteCDMInstanceProxy, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_CloseSession"_s, ReceiverName::RemoteCDMInstanceSessionProxy, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_LoadSession"_s, ReceiverName::RemoteCDMInstanceSessionProxy, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_RemoveSessionData"_s, ReceiverName::RemoteCDMInstanceSessionProxy, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_RequestLicense"_s, ReceiverName::RemoteCDMInstanceSessionProxy, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_SetLogIdentifier"_s, ReceiverName::RemoteCDMInstanceSessionProxy, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_StoreRecordOfKeyUsage"_s, ReceiverName::RemoteCDMInstanceSessionProxy, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_UpdateLicense"_s, ReceiverName::RemoteCDMInstanceSessionProxy, false, false },
    MessageDescription { "RemoteCDMInstanceSession_SendMessage"_s, ReceiverName::RemoteCDMInstanceSession, false, false },
    MessageDescription { "RemoteCDMInstanceSession_SessionIdChanged"_s, ReceiverName::RemoteCDMInstanceSession, false, false },
    MessageDescription { "RemoteCDMInstanceSession_UpdateKeyStatuses"_s, ReceiverName::RemoteCDMInstanceSession, false, false },
    MessageDescription { "RemoteCDMInstance_UnrequestedInitializationDataReceived"_s, ReceiverName::RemoteCDMInstance, false, false },
    MessageDescription { "RemoteCDMProxy_GetSupportedConfiguration"_s, ReceiverName::RemoteCDMProxy, false, false },
    MessageDescription { "RemoteCDMProxy_LoadAndInitialize"_s, ReceiverName::RemoteCDMProxy, false, false },
    MessageDescription { "RemoteCDMProxy_SetLogIdentifier"_s, ReceiverName::RemoteCDMProxy, false, false },
    MessageDescription { "RemoteCommandBuffer_Destruct"_s, ReceiverName::RemoteCommandBuffer, true, false },
    MessageDescription { "RemoteCommandBuffer_SetLabel"_s, ReceiverName::RemoteCommandBuffer, true, false },
    MessageDescription { "RemoteCommandEncoder_BeginComputePass"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_BeginRenderPass"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_ClearBuffer"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_CopyBufferToBuffer"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_CopyBufferToTexture"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_CopyTextureToBuffer"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_CopyTextureToTexture"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_Destruct"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_Finish"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_InsertDebugMarker"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_PopDebugGroup"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_PushDebugGroup"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_ResolveQuerySet"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_SetLabel"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCommandEncoder_WriteTimestamp"_s, ReceiverName::RemoteCommandEncoder, true, false },
    MessageDescription { "RemoteCompositorIntegration_Destruct"_s, ReceiverName::RemoteCompositorIntegration, true, false },
    MessageDescription { "RemoteCompositorIntegration_UpdateContentsHeadroom"_s, ReceiverName::RemoteCompositorIntegration, true, false },
    MessageDescription { "RemoteComputePassEncoder_Destruct"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_Dispatch"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_DispatchIndirect"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_End"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_InsertDebugMarker"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_PopDebugGroup"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_PushDebugGroup"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_SetBindGroup"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_SetLabel"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePassEncoder_SetPipeline"_s, ReceiverName::RemoteComputePassEncoder, true, false },
    MessageDescription { "RemoteComputePipeline_Destruct"_s, ReceiverName::RemoteComputePipeline, true, false },
    MessageDescription { "RemoteComputePipeline_GetBindGroupLayout"_s, ReceiverName::RemoteComputePipeline, true, false },
    MessageDescription { "RemoteComputePipeline_SetLabel"_s, ReceiverName::RemoteComputePipeline, true, false },
    MessageDescription { "RemoteDevice_CreateBindGroup"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateBindGroupLayout"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateBuffer"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateCommandEncoder"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateComputePipeline"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateComputePipelineAsync"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreatePipelineLayout"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateQuerySet"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateRenderBundleEncoder"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateRenderPipeline"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateRenderPipelineAsync"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateSampler"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateShaderModule"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateTexture"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_CreateXRBinding"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_Destroy"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_Destruct"_s, ReceiverName::RemoteDevice, true, false },
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    MessageDescription { "RemoteDevice_ImportExternalTextureFromVideoFrame"_s, ReceiverName::RemoteDevice, true, false },
#endif
    MessageDescription { "RemoteDevice_PauseAllErrorReporting"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_PopErrorScope"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_PushErrorScope"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_ResolveDeviceLostPromise"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_ResolveUncapturedErrorEvent"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_SetLabel"_s, ReceiverName::RemoteDevice, true, false },
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    MessageDescription { "RemoteDevice_SetSharedVideoFrameMemory"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_SetSharedVideoFrameSemaphore"_s, ReceiverName::RemoteDevice, true, false },
    MessageDescription { "RemoteDevice_UpdateExternalTexture"_s, ReceiverName::RemoteDevice, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_ApplyDeviceScaleFactor"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if USE(CG)
    MessageDescription { "RemoteDisplayListRecorder_ApplyFillPattern"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ApplyStrokePattern"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_BeginPage"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_BeginTransparencyLayer"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_BeginTransparencyLayerWithCompositeMode"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ClearRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_Clip"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ClipOut"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ClipOutRoundedRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ClipOutToPath"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ClipPath"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ClipRoundedRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ClipToImageBuffer"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ConcatCTM"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawControlPart"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawDecomposedGlyphs"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawDotsForDocumentMarker"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawEllipse"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawFilteredImageBuffer"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawFocusRingPath"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawFocusRingRects"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawGlyphs"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawImageBuffer"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawLine"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawLinesForText"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawNativeImage"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawPath"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawPatternImageBuffer"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawPatternNativeImage"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_DrawSystemImage"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    MessageDescription { "RemoteDisplayListRecorder_DrawVideoFrame"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_EndPage"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_EndTransparencyLayer"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if ENABLE(INLINE_PATH_DATA)
    MessageDescription { "RemoteDisplayListRecorder_FillArc"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillBezierCurve"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillClosedArc"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_FillCompositedRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillEllipse"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if ENABLE(INLINE_PATH_DATA)
    MessageDescription { "RemoteDisplayListRecorder_FillLine"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_FillPath"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillPathSegment"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if ENABLE(INLINE_PATH_DATA)
    MessageDescription { "RemoteDisplayListRecorder_FillQuadCurve"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_FillRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillRectWithColor"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillRectWithGradient"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillRectWithGradientAndSpaceTransform"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillRectWithRoundedHole"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_FillRoundedRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_ResetClip"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_Restore"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_Rotate"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_Save"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_Scale"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetAlpha"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetCTM"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetCompositeMode"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetDrawLuminanceMask"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetDropShadow"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetFillCachedGradient"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetFillColor"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetFillGradient"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetFillPackedColor"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetFillPattern"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetFillRule"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetImageInterpolationQuality"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetLineCap"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetLineDash"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetLineJoin"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetMiterLimit"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetShadowsIgnoreTransforms"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    MessageDescription { "RemoteDisplayListRecorder_SetSharedVideoFrameMemory"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetSharedVideoFrameSemaphore"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_SetShouldAntialias"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetShouldSmoothFonts"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetShouldSubpixelQuantizeFonts"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStrokeCachedGradient"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStrokeColor"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStrokeGradient"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStrokePackedColor"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStrokePackedColorAndThickness"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStrokePattern"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStrokeStyle"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStrokeThickness"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetStyle"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetTextDrawingMode"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_SetURLForRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if ENABLE(INLINE_PATH_DATA)
    MessageDescription { "RemoteDisplayListRecorder_StrokeArc"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_StrokeBezierCurve"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_StrokeClosedArc"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_StrokeEllipse"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if ENABLE(INLINE_PATH_DATA)
    MessageDescription { "RemoteDisplayListRecorder_StrokeLine"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_StrokeLineWithColorAndThickness"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_StrokePath"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_StrokePathSegment"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#if ENABLE(INLINE_PATH_DATA)
    MessageDescription { "RemoteDisplayListRecorder_StrokeQuadCurve"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
#endif
    MessageDescription { "RemoteDisplayListRecorder_StrokeRect"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteDisplayListRecorder_Translate"_s, ReceiverName::RemoteDisplayListRecorder, true, false },
    MessageDescription { "RemoteExternalTexture_Destroy"_s, ReceiverName::RemoteExternalTexture, true, false },
    MessageDescription { "RemoteExternalTexture_Destruct"_s, ReceiverName::RemoteExternalTexture, true, false },
    MessageDescription { "RemoteExternalTexture_SetLabel"_s, ReceiverName::RemoteExternalTexture, true, false },
    MessageDescription { "RemoteExternalTexture_Undestroy"_s, ReceiverName::RemoteExternalTexture, true, false },
    MessageDescription { "RemoteFaceDetector_Detect"_s, ReceiverName::RemoteFaceDetector, true, false },
    MessageDescription { "RemoteGPUProxy_WasCreated"_s, ReceiverName::RemoteGPUProxy, false, false },
    MessageDescription { "RemoteGPU_CreateCompositorIntegration"_s, ReceiverName::RemoteGPU, true, false },
    MessageDescription { "RemoteGPU_CreatePresentationContext"_s, ReceiverName::RemoteGPU, true, false },
    MessageDescription { "RemoteGraphicsContextGLProxy_WasCreated"_s, ReceiverName::RemoteGraphicsContextGLProxy, false, false },
    MessageDescription { "RemoteGraphicsContextGLProxy_WasLost"_s, ReceiverName::RemoteGraphicsContextGLProxy, false, false },
    MessageDescription { "RemoteGraphicsContextGLProxy_addDebugMessage"_s, ReceiverName::RemoteGraphicsContextGLProxy, false, false },
    MessageDescription { "RemoteGraphicsContextGL_ActiveTexture"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_AttachShader"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BeginQuery"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BeginQueryEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BeginTransformFeedback"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindAttribLocation"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindBuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindBufferBase"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindBufferRange"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_BindExternalImage"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_BindFramebuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindRenderbuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindSampler"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindTexture"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindTransformFeedback"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BindVertexArray"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendColor"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendEquation"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendEquationSeparate"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendEquationSeparateiOES"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendEquationiOES"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendFunc"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendFuncSeparate"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendFuncSeparateiOES"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlendFunciOES"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BlitFramebuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BufferData0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BufferData1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_BufferSubData"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Clear"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClearBufferfi"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClearBufferfv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClearBufferiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClearBufferuiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClearColor"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClearDepth"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClearStencil"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClipControlEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ColorMask"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ColorMaskiOES"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompileShader"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompressedTexImage2D0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompressedTexImage2D1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompressedTexImage3D0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompressedTexImage3D1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompressedTexSubImage2D0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompressedTexSubImage2D1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompressedTexSubImage3D0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CompressedTexSubImage3D1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CopyBufferSubData"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CopyTexImage2D"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CopyTexSubImage2D"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CopyTexSubImage3D"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateBuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_CreateExternalImage"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateExternalSync"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_CreateFramebuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateProgram"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateQuery"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateQueryEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateRenderbuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateSampler"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateShader"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateTexture"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateTransformFeedback"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CreateVertexArray"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_CullFace"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteBuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_DeleteExternalImage"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_DeleteExternalSync"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteFramebuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteProgram"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteQuery"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteQueryEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteRenderbuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteSampler"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteShader"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteSync"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteTexture"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteTransformFeedback"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DeleteVertexArray"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DepthFunc"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DepthMask"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DepthRange"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DetachShader"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Disable"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_DisableFoveation"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_DisableVertexAttribArray"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DisableiOES"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawArrays"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawArraysInstanced"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawArraysInstancedBaseInstanceANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawBuffers"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawBuffersEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawElements"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawElementsInstanced"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawElementsInstancedBaseVertexBaseInstanceANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_DrawRangeElements"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Enable"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_EnableFoveation"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_EnableVertexAttribArray"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_EnableiOES"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_EndQuery"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_EndQueryEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_EndTransformFeedback"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_EnsureExtensionEnabled"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Finish"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Flush"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_FramebufferDiscard"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_FramebufferRenderbuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_FramebufferResolveRenderbuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_FramebufferTexture2D"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_FramebufferTextureLayer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_FrontFace"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GenerateMipmap"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Hint"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_InvalidateFramebuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_InvalidateSubFramebuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_LineWidth"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_LinkProgram"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_MultiDrawArraysANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_MultiDrawArraysInstancedANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_MultiDrawArraysInstancedBaseInstanceANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_MultiDrawElementsANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_MultiDrawElementsInstancedANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_MultiDrawElementsInstancedBaseVertexBaseInstanceANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_PauseTransformFeedback"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_PixelStorei"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_PolygonModeANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_PolygonOffset"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_PolygonOffsetClampEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ProvokingVertexANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_QueryCounterEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ReadBuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ReadPixelsBufferObject"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_RenderbufferStorage"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_RenderbufferStorageMultisample"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_RenderbufferStorageMultisampleANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Reshape"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ResumeTransformFeedback"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_SampleCoverage"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_SamplerParameterf"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_SamplerParameteri"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Scissor"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_SetDrawingBufferColorSpace"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(VIDEO) && PLATFORM(COCOA)
    MessageDescription { "RemoteGraphicsContextGL_SetSharedVideoFrameMemory"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_SetSharedVideoFrameSemaphore"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_ShaderSource"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_SimulateEventForTesting"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_StencilFunc"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_StencilFuncSeparate"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_StencilMask"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_StencilMaskSeparate"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_StencilOp"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_StencilOpSeparate"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexImage2D0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexImage2D1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexImage3D0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexImage3D1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexParameterf"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexParameteri"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexStorage2D"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexStorage3D"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexSubImage2D0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexSubImage2D1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexSubImage3D0"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TexSubImage3D1"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_TransformFeedbackVaryings"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform1f"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform1fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform1i"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform1iv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform1ui"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform1uiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform2f"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform2fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform2i"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform2iv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform2ui"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform2uiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform3f"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform3fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform3i"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform3iv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform3ui"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform3uiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform4f"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform4fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform4i"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform4iv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform4ui"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Uniform4uiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformBlockBinding"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix2fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix2x3fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix2x4fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix3fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix3x2fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix3x4fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix4fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix4x2fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UniformMatrix4x3fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_UseProgram"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ValidateProgram"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttrib1f"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttrib1fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttrib2f"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttrib2fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttrib3f"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttrib3fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttrib4f"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttrib4fv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttribDivisor"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttribI4i"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttribI4iv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttribI4ui"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttribI4uiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttribIPointer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_VertexAttribPointer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_Viewport"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_WaitSync"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteImageBufferProxy_DidCreateBackend"_s, ReceiverName::RemoteImageBufferProxy, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteImageBufferSetProxy_DidPrepareForDisplay"_s, ReceiverName::RemoteImageBufferSetProxy, false, false },
#endif
    MessageDescription { "RemoteImageBufferSet_EndPrepareForDisplay"_s, ReceiverName::RemoteImageBufferSet, true, false },
    MessageDescription { "RemoteImageBufferSet_UpdateConfiguration"_s, ReceiverName::RemoteImageBufferSet, true, false },
    MessageDescription { "RemoteImageBuffer_ConvertToLuminanceMask"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteImageBuffer_FlushContext"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteImageBuffer_PutPixelBuffer"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteImageBuffer_TransformToColorSpace"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteLegacyCDMFactoryProxy_RemoveSession"_s, ReceiverName::RemoteLegacyCDMFactoryProxy, false, false },
    MessageDescription { "RemoteLegacyCDMProxy_SetPlayerId"_s, ReceiverName::RemoteLegacyCDMProxy, false, false },
    MessageDescription { "RemoteLegacyCDMSessionProxy_ReleaseKeys"_s, ReceiverName::RemoteLegacyCDMSessionProxy, false, false },
    MessageDescription { "RemoteLegacyCDMSession_SendError"_s, ReceiverName::RemoteLegacyCDMSession, false, false },
    MessageDescription { "RemoteLegacyCDMSession_SendMessage"_s, ReceiverName::RemoteLegacyCDMSession, false, false },
    MessageDescription { "RemoteMediaEngineConfigurationFactoryProxy_CreateDecodingConfiguration"_s, ReceiverName::RemoteMediaEngineConfigurationFactoryProxy, false, false },
    MessageDescription { "RemoteMediaEngineConfigurationFactoryProxy_CreateEncodingConfiguration"_s, ReceiverName::RemoteMediaEngineConfigurationFactoryProxy, false, false },
    MessageDescription { "RemoteMediaPlayerManagerProxy_CreateMediaPlayer"_s, ReceiverName::RemoteMediaPlayerManagerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerManagerProxy_DeleteMediaPlayer"_s, ReceiverName::RemoteMediaPlayerManagerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_AcceleratedRenderingStateChanged"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_ApplicationDidBecomeActive"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_ApplicationWillResignActive"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(ENCRYPTED_MEDIA)
    MessageDescription { "RemoteMediaPlayerProxy_AttemptToDecryptWithInstance"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_AudioOutputDeviceChanged"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_AudioTrackSetEnabled"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_BeginSimulatedHDCPError"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_CancelLoad"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(ENCRYPTED_MEDIA)
    MessageDescription { "RemoteMediaPlayerProxy_CdmInstanceAttached"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_CdmInstanceDetached"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
#if ENABLE(WEB_AUDIO)
    MessageDescription { "RemoteMediaPlayerProxy_CreateAudioSourceProvider"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_DidLoadingProgress"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_EndSimulatedHDCPError"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_IsInFullscreenOrPictureInPictureChanged"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    MessageDescription { "RemoteMediaPlayerProxy_KeyAdded"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_Load"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(MEDIA_SOURCE)
    MessageDescription { "RemoteMediaPlayerProxy_LoadMediaSource"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_NotifyActiveSourceBuffersChanged"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_NotifyTrackModeChanged"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_Pause"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_PauseAtHostTime"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_PerformTaskAtTime"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_Play"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_PlayAtHostTime"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_PlayerContentBoxRectChanged"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_PrepareForPlayback"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_PrepareForRendering"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_PrepareToPlay"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_RequestHostingContext"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SeekToTarget"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetBufferingPolicy"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if HAVE(SPATIAL_TRACKING_LABEL)
    MessageDescription { "RemoteMediaPlayerProxy_SetDefaultSpatialTrackingLabel"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_SetHasMessageClientForTesting"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    MessageDescription { "RemoteMediaPlayerProxy_SetLegacyCDMSession"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_SetMuted"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetPageIsVisible"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetPitchCorrectionAlgorithm"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetPlatformDynamicRangeLimit"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetPreferredDynamicRangeMode"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    MessageDescription { "RemoteMediaPlayerProxy_SetPrefersSpatialAudioExperience"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_SetPreload"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetPresentationSize"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetPreservesPitch"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetPrivateBrowsingMode"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetRate"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "RemoteMediaPlayerProxy_SetSceneIdentifier"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_SetShouldCheckHardwareSupport"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(LEGACY_ENCRYPTED_MEDIA) && ENABLE(ENCRYPTED_MEDIA)
    MessageDescription { "RemoteMediaPlayerProxy_SetShouldContinueAfterKeyNeeded"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_SetShouldDisableHDR"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetShouldDisableSleep"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(WEB_AUDIO)
    MessageDescription { "RemoteMediaPlayerProxy_SetShouldEnableAudioSourceProvider"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_SetShouldMaintainAspectRatio"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    MessageDescription { "RemoteMediaPlayerProxy_SetShouldPlayToPlaybackTarget"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_SetSoundStageSize"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if HAVE(SPATIAL_TRACKING_LABEL)
    MessageDescription { "RemoteMediaPlayerProxy_SetSpatialTrackingLabel"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
#if ENABLE(VIDEO_PRESENTATION_MODE)
    MessageDescription { "RemoteMediaPlayerProxy_SetVideoFullscreenGravity"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetVideoFullscreenMode"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "RemoteMediaPlayerProxy_SetVideoLayerSizeFenced"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_SetVideoPlaybackMetricsUpdateInterval"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetVolume"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetVolumeLocked"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    MessageDescription { "RemoteMediaPlayerProxy_SetWirelessPlaybackTarget"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_SetWirelessVideoPlaybackDisabled"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_StartVideoFrameMetadataGathering"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_StopVideoFrameMetadataGathering"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_TextTrackSetMode"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_TracksChanged"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#if ENABLE(VIDEO_PRESENTATION_MODE)
    MessageDescription { "RemoteMediaPlayerProxy_UpdateVideoFullscreenInlineImage"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_VideoFullscreenStandbyChanged"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_VideoTrackSetSelected"_s, ReceiverName::RemoteMediaPlayerProxy, false, false },
    MessageDescription { "RemoteMediaResourceManager_AccessControlCheckFailed"_s, ReceiverName::RemoteMediaResourceManager, false, false },
    MessageDescription { "RemoteMediaResourceManager_DataReceived"_s, ReceiverName::RemoteMediaResourceManager, false, false },
    MessageDescription { "RemoteMediaResourceManager_DataSent"_s, ReceiverName::RemoteMediaResourceManager, false, false },
    MessageDescription { "RemoteMediaResourceManager_LoadFailed"_s, ReceiverName::RemoteMediaResourceManager, false, false },
    MessageDescription { "RemoteMediaResourceManager_LoadFinished"_s, ReceiverName::RemoteMediaResourceManager, false, false },
    MessageDescription { "RemoteMediaResourceManager_RedirectReceived"_s, ReceiverName::RemoteMediaResourceManager, false, false },
    MessageDescription { "RemoteMediaResourceManager_ResponseReceived"_s, ReceiverName::RemoteMediaResourceManager, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_CoordinatePause"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_CoordinatePlay"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_CoordinateSeekTo"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_CoordinateSetTrack"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_Join"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_Leave"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_PlaybackStateChanged"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_PositionStateChanged"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_ReadyStateChanged"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_TrackIdentifierChanged"_s, ReceiverName::RemoteMediaSessionCoordinatorProxy, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_CoordinatorStateChanged"_s, ReceiverName::RemoteMediaSessionCoordinator, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_PauseSession"_s, ReceiverName::RemoteMediaSessionCoordinator, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_PlaySession"_s, ReceiverName::RemoteMediaSessionCoordinator, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_SeekSessionToTime"_s, ReceiverName::RemoteMediaSessionCoordinator, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_SetSessionTrack"_s, ReceiverName::RemoteMediaSessionCoordinator, false, false },
    MessageDescription { "RemoteMediaSourceProxy_BufferedChanged"_s, ReceiverName::RemoteMediaSourceProxy, false, false },
    MessageDescription { "RemoteMediaSourceProxy_DurationChanged"_s, ReceiverName::RemoteMediaSourceProxy, false, false },
    MessageDescription { "RemoteMediaSourceProxy_MarkEndOfStream"_s, ReceiverName::RemoteMediaSourceProxy, false, false },
    MessageDescription { "RemoteMediaSourceProxy_SetMediaPlayerReadyState"_s, ReceiverName::RemoteMediaSourceProxy, false, false },
    MessageDescription { "RemoteMediaSourceProxy_SetTimeFudgeFactor"_s, ReceiverName::RemoteMediaSourceProxy, false, false },
    MessageDescription { "RemoteMediaSourceProxy_Shutdown"_s, ReceiverName::RemoteMediaSourceProxy, false, false },
    MessageDescription { "RemoteMediaSourceProxy_UnmarkEndOfStream"_s, ReceiverName::RemoteMediaSourceProxy, false, false },
    MessageDescription { "RemotePipelineLayout_Destruct"_s, ReceiverName::RemotePipelineLayout, true, false },
    MessageDescription { "RemotePipelineLayout_SetLabel"_s, ReceiverName::RemotePipelineLayout, true, false },
    MessageDescription { "RemotePresentationContext_Configure"_s, ReceiverName::RemotePresentationContext, true, false },
    MessageDescription { "RemotePresentationContext_GetCurrentTexture"_s, ReceiverName::RemotePresentationContext, true, false },
    MessageDescription { "RemotePresentationContext_Present"_s, ReceiverName::RemotePresentationContext, true, false },
    MessageDescription { "RemotePresentationContext_Unconfigure"_s, ReceiverName::RemotePresentationContext, true, false },
    MessageDescription { "RemoteQuerySet_Destroy"_s, ReceiverName::RemoteQuerySet, true, false },
    MessageDescription { "RemoteQuerySet_Destruct"_s, ReceiverName::RemoteQuerySet, true, false },
    MessageDescription { "RemoteQuerySet_SetLabel"_s, ReceiverName::RemoteQuerySet, true, false },
    MessageDescription { "RemoteQueue_CopyExternalImageToTexture"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteQueue_Destruct"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteQueue_OnSubmittedWorkDone"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteQueue_SetLabel"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteQueue_Submit"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteQueue_WriteBuffer"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteQueue_WriteBufferWithCopy"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteQueue_WriteTexture"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteQueue_WriteTextureWithCopy"_s, ReceiverName::RemoteQueue, true, false },
    MessageDescription { "RemoteRemoteCommandListenerProxy_UpdateSupportedCommands"_s, ReceiverName::RemoteRemoteCommandListenerProxy, false, false },
    MessageDescription { "RemoteRemoteCommandListener_DidReceiveRemoteControlCommand"_s, ReceiverName::RemoteRemoteCommandListener, false, false },
    MessageDescription { "RemoteRenderBundleEncoder_Destruct"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_Draw"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_DrawIndexed"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_DrawIndexedIndirect"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_DrawIndirect"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_Finish"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_InsertDebugMarker"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_PopDebugGroup"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_PushDebugGroup"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_SetBindGroup"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_SetIndexBuffer"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_SetLabel"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_SetPipeline"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_SetVertexBuffer"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundleEncoder_UnsetVertexBuffer"_s, ReceiverName::RemoteRenderBundleEncoder, true, false },
    MessageDescription { "RemoteRenderBundle_Destruct"_s, ReceiverName::RemoteRenderBundle, true, false },
    MessageDescription { "RemoteRenderBundle_SetLabel"_s, ReceiverName::RemoteRenderBundle, true, false },
    MessageDescription { "RemoteRenderPassEncoder_BeginOcclusionQuery"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_Destruct"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_Draw"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_DrawIndexed"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_DrawIndexedIndirect"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_DrawIndirect"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_End"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_EndOcclusionQuery"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_ExecuteBundles"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_InsertDebugMarker"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_PopDebugGroup"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_PushDebugGroup"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetBindGroup"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetBlendConstant"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetIndexBuffer"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetLabel"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetPipeline"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetScissorRect"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetStencilReference"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetVertexBuffer"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_SetViewport"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPassEncoder_UnsetVertexBuffer"_s, ReceiverName::RemoteRenderPassEncoder, true, false },
    MessageDescription { "RemoteRenderPipeline_Destruct"_s, ReceiverName::RemoteRenderPipeline, true, false },
    MessageDescription { "RemoteRenderPipeline_GetBindGroupLayout"_s, ReceiverName::RemoteRenderPipeline, true, false },
    MessageDescription { "RemoteRenderPipeline_SetLabel"_s, ReceiverName::RemoteRenderPipeline, true, false },
    MessageDescription { "RemoteRenderingBackendProxy_DidFinalizeRenderingUpdate"_s, ReceiverName::RemoteRenderingBackendProxy, false, false },
    MessageDescription { "RemoteRenderingBackendProxy_DidInitialize"_s, ReceiverName::RemoteRenderingBackendProxy, false, false },
    MessageDescription { "RemoteRenderingBackendProxy_DidMarkLayersAsVolatile"_s, ReceiverName::RemoteRenderingBackendProxy, false, false },
    MessageDescription { "RemoteRenderingBackend_CacheDecomposedGlyphs"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CacheFilter"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CacheFont"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CacheFontCustomPlatformData"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CacheGradient"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CacheNativeImage"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CreateImageBuffer"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CreateImageBufferSet"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CreateRemoteBarcodeDetector"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CreateRemoteFaceDetector"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_CreateRemoteTextDetector"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_DestroyGetPixelBufferSharedMemory"_s, ReceiverName::RemoteRenderingBackend, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteRenderingBackend_DidDrawRemoteToPDF"_s, ReceiverName::RemoteRenderingBackend, true, false },
#endif
    MessageDescription { "RemoteRenderingBackend_FinalizeRenderingUpdate"_s, ReceiverName::RemoteRenderingBackend, true, false },
#if USE(GRAPHICS_LAYER_WC)
    MessageDescription { "RemoteRenderingBackend_Flush"_s, ReceiverName::RemoteRenderingBackend, true, false },
#endif
    MessageDescription { "RemoteRenderingBackend_GetImageBufferResourceLimitsForTesting"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_GetRemoteBarcodeDetectorSupportedFormats"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_MarkSurfacesVolatile"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_MoveToImageBuffer"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_MoveToSerializedBuffer"_s, ReceiverName::RemoteRenderingBackend, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteRenderingBackend_PrepareImageBufferSetsForDisplay"_s, ReceiverName::RemoteRenderingBackend, true, false },
#endif
    MessageDescription { "RemoteRenderingBackend_ReleaseDecomposedGlyphs"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseFilter"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseFont"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseFontCustomPlatformData"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseGradient"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseImageBuffer"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseImageBufferSet"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseMemory"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseNativeImage"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseNativeImages"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseRemoteBarcodeDetector"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseRemoteFaceDetector"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteRenderingBackend_ReleaseRemoteTextDetector"_s, ReceiverName::RemoteRenderingBackend, true, false },
    MessageDescription { "RemoteSampleBufferDisplayLayerManager_CreateLayer"_s, ReceiverName::RemoteSampleBufferDisplayLayerManager, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayerManager_ReleaseLayer"_s, ReceiverName::RemoteSampleBufferDisplayLayerManager, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_ClearVideoFrames"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_EnqueueVideoFrame"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_Flush"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_FlushAndRemoveImage"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_Pause"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_Play"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
#if !RELEASE_LOG_DISABLED
    MessageDescription { "RemoteSampleBufferDisplayLayer_SetLogIdentifier"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
#endif
    MessageDescription { "RemoteSampleBufferDisplayLayer_SetSharedVideoFrameMemory"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_SetSharedVideoFrameSemaphore"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_SetShouldMaintainAspectRatio"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayer_UpdateDisplayMode"_s, ReceiverName::RemoteSampleBufferDisplayLayer, false, false },
    MessageDescription { "RemoteSampler_Destruct"_s, ReceiverName::RemoteSampler, true, false },
    MessageDescription { "RemoteSampler_SetLabel"_s, ReceiverName::RemoteSampler, true, false },
    MessageDescription { "RemoteShaderModule_CompilationInfo"_s, ReceiverName::RemoteShaderModule, true, false },
    MessageDescription { "RemoteShaderModule_Destruct"_s, ReceiverName::RemoteShaderModule, true, false },
    MessageDescription { "RemoteShaderModule_SetLabel"_s, ReceiverName::RemoteShaderModule, true, false },
    MessageDescription { "RemoteSharedResourceCache_ReleaseSerializedImageBuffer"_s, ReceiverName::RemoteSharedResourceCache, false, false },
    MessageDescription { "RemoteSourceBufferProxy_Abort"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_AddTrackBuffer"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_Append"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_AsyncEvictCodedFrames"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_Attach"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_BufferedSamplesForTrackId"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_ClearTrackBuffers"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_ComputeSeekTime"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_Detach"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_EnqueuedSamplesForTrackID"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_MemoryPressure"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_ReenqueueMediaIfNeeded"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_RemoveCodedFrames"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_RemovedFromMediaSource"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_ResetParserState"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_ResetTimestampOffsetInTrackBuffers"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_ResetTrackBuffers"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SeekToTime"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetActive"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetAllTrackBuffersNeedRandomAccess"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetAppendWindowEnd"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetAppendWindowStart"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetGroupStartTimestamp"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetGroupStartTimestampToEndTimestamp"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetMaximumBufferSize"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetMaximumQueueDepthForTrackID"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetMediaSourceEnded"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetMode"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetShouldGenerateTimestamps"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetTimestampOffset"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_StartChangingType"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteSourceBufferProxy_UpdateTrackIds"_s, ReceiverName::RemoteSourceBufferProxy, false, false },
    MessageDescription { "RemoteTextDetector_Detect"_s, ReceiverName::RemoteTextDetector, true, false },
    MessageDescription { "RemoteTextureView_Destruct"_s, ReceiverName::RemoteTextureView, true, false },
    MessageDescription { "RemoteTextureView_SetLabel"_s, ReceiverName::RemoteTextureView, true, false },
    MessageDescription { "RemoteTexture_CreateView"_s, ReceiverName::RemoteTexture, true, false },
    MessageDescription { "RemoteTexture_Destroy"_s, ReceiverName::RemoteTexture, true, false },
    MessageDescription { "RemoteTexture_Destruct"_s, ReceiverName::RemoteTexture, true, false },
    MessageDescription { "RemoteTexture_SetLabel"_s, ReceiverName::RemoteTexture, true, false },
    MessageDescription { "RemoteTexture_Undestroy"_s, ReceiverName::RemoteTexture, true, false },
    MessageDescription { "RemoteVideoFrameObjectHeapProxyProcessor_NewConvertedVideoFrameBuffer"_s, ReceiverName::RemoteVideoFrameObjectHeapProxyProcessor, false, false },
    MessageDescription { "RemoteVideoFrameObjectHeapProxyProcessor_NewVideoFrameBuffer"_s, ReceiverName::RemoteVideoFrameObjectHeapProxyProcessor, false, false },
    MessageDescription { "RemoteVideoFrameObjectHeapProxyProcessor_SetSharedVideoFrameMemory"_s, ReceiverName::RemoteVideoFrameObjectHeapProxyProcessor, false, false },
    MessageDescription { "RemoteVideoFrameObjectHeapProxyProcessor_SetSharedVideoFrameSemaphore"_s, ReceiverName::RemoteVideoFrameObjectHeapProxyProcessor, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteVideoFrameObjectHeap_GetVideoFrameBuffer"_s, ReceiverName::RemoteVideoFrameObjectHeap, true, false },
#endif
    MessageDescription { "RemoteVideoFrameObjectHeap_ReleaseVideoFrame"_s, ReceiverName::RemoteVideoFrameObjectHeap, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteVideoFrameObjectHeap_SetSharedVideoFrameMemory"_s, ReceiverName::RemoteVideoFrameObjectHeap, false, false },
    MessageDescription { "RemoteVideoFrameObjectHeap_SetSharedVideoFrameSemaphore"_s, ReceiverName::RemoteVideoFrameObjectHeap, false, false },
#endif
    MessageDescription { "RemoteWCLayerTreeHost_Update"_s, ReceiverName::RemoteWCLayerTreeHost, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_BringToFront"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_FrontendDidClose"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_FrontendLoaded"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_Load"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_OpenURLExternally"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_PickColorFromScreen"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_Reopen"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_ResetState"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_RevealFileExternally"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_Save"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_SendMessageToBackend"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_SetForcedAppearance"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_SetInspectorPageDeveloperExtrasEnabled"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_SetSheetRect"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_ShowCertificate"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_StartWindowDrag"_s, ReceiverName::RemoteWebInspectorUIProxy, false, false },
    MessageDescription { "RemoteWebInspectorUI_Initialize"_s, ReceiverName::RemoteWebInspectorUI, false, false },
    MessageDescription { "RemoteWebInspectorUI_SendMessageToFrontend"_s, ReceiverName::RemoteWebInspectorUI, false, false },
#if ENABLE(INSPECTOR_TELEMETRY)
    MessageDescription { "RemoteWebInspectorUI_SetDiagnosticLoggingAvailable"_s, ReceiverName::RemoteWebInspectorUI, false, false },
#endif
    MessageDescription { "RemoteWebInspectorUI_ShowConsole"_s, ReceiverName::RemoteWebInspectorUI, false, false },
    MessageDescription { "RemoteWebInspectorUI_ShowResources"_s, ReceiverName::RemoteWebInspectorUI, false, false },
    MessageDescription { "RemoteWebInspectorUI_UpdateFindString"_s, ReceiverName::RemoteWebInspectorUI, false, false },
    MessageDescription { "RemoteWebLockRegistry_DidCompleteLockRequest"_s, ReceiverName::RemoteWebLockRegistry, false, false },
    MessageDescription { "RemoteWebLockRegistry_DidStealLock"_s, ReceiverName::RemoteWebLockRegistry, false, false },
    MessageDescription { "RemoteXRBinding_CreateProjectionLayer"_s, ReceiverName::RemoteXRBinding, true, false },
    MessageDescription { "RemoteXRBinding_Destruct"_s, ReceiverName::RemoteXRBinding, true, false },
    MessageDescription { "RemoteXRBinding_GetViewSubImage"_s, ReceiverName::RemoteXRBinding, true, false },
    MessageDescription { "RemoteXRProjectionLayer_Destruct"_s, ReceiverName::RemoteXRProjectionLayer, true, false },
    MessageDescription { "RemoteXRProjectionLayer_EndFrame"_s, ReceiverName::RemoteXRProjectionLayer, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteXRProjectionLayer_StartFrame"_s, ReceiverName::RemoteXRProjectionLayer, true, false },
#endif
    MessageDescription { "RemoteXRSubImage_Destruct"_s, ReceiverName::RemoteXRSubImage, true, false },
    MessageDescription { "RemoteXRSubImage_GetColorTexture"_s, ReceiverName::RemoteXRSubImage, true, false },
    MessageDescription { "RemoteXRSubImage_GetDepthTexture"_s, ReceiverName::RemoteXRSubImage, true, false },
    MessageDescription { "RemoteXRView_Destruct"_s, ReceiverName::RemoteXRView, true, false },
    MessageDescription { "SampleBufferDisplayLayer_SetDidFail"_s, ReceiverName::SampleBufferDisplayLayer, false, false },
    MessageDescription { "ServiceWorkerDownloadTask_DidFail"_s, ReceiverName::ServiceWorkerDownloadTask, false, false },
    MessageDescription { "ServiceWorkerDownloadTask_DidFinish"_s, ReceiverName::ServiceWorkerDownloadTask, false, false },
    MessageDescription { "ServiceWorkerDownloadTask_DidReceiveData"_s, ReceiverName::ServiceWorkerDownloadTask, false, false },
    MessageDescription { "ServiceWorkerDownloadTask_DidReceiveFormData"_s, ReceiverName::ServiceWorkerDownloadTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_DidFail"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_DidFinish"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_DidNotHandle"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_DidReceiveData"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_DidReceiveFormData"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_DidReceiveRedirectResponse"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_DidReceiveResponse"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_UsePreload"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "ServiceWorkerFetchTask_WorkerClosed"_s, ReceiverName::ServiceWorkerFetchTask, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateBufferedChanged"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidAttach"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidDropSample"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveInitializationSegment"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveRenderingError"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDurationChanged"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateEvictionDataChanged"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateHighestPresentationTimestampChanged"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_TakeOwnershipOfMemory"_s, ReceiverName::SourceBufferPrivateRemoteMessageReceiver, false, false },
    MessageDescription { "SpeechRecognitionRealtimeMediaSourceManager_CreateSource"_s, ReceiverName::SpeechRecognitionRealtimeMediaSourceManager, false, false },
    MessageDescription { "SpeechRecognitionRealtimeMediaSourceManager_DeleteSource"_s, ReceiverName::SpeechRecognitionRealtimeMediaSourceManager, false, false },
    MessageDescription { "SpeechRecognitionRealtimeMediaSourceManager_Start"_s, ReceiverName::SpeechRecognitionRealtimeMediaSourceManager, false, false },
    MessageDescription { "SpeechRecognitionRealtimeMediaSourceManager_Stop"_s, ReceiverName::SpeechRecognitionRealtimeMediaSourceManager, false, false },
    MessageDescription { "SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteAudioSamplesAvailable"_s, ReceiverName::SpeechRecognitionRemoteRealtimeMediaSourceManager, false, false },
    MessageDescription { "SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteCaptureFailed"_s, ReceiverName::SpeechRecognitionRemoteRealtimeMediaSourceManager, false, false },
    MessageDescription { "SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteSourceStopped"_s, ReceiverName::SpeechRecognitionRemoteRealtimeMediaSourceManager, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "SpeechRecognitionRemoteRealtimeMediaSourceManager_SetStorage"_s, ReceiverName::SpeechRecognitionRemoteRealtimeMediaSourceManager, false, false },
#endif
    MessageDescription { "SpeechRecognitionServer_Abort"_s, ReceiverName::SpeechRecognitionServer, false, false },
    MessageDescription { "SpeechRecognitionServer_Invalidate"_s, ReceiverName::SpeechRecognitionServer, false, false },
    MessageDescription { "SpeechRecognitionServer_Start"_s, ReceiverName::SpeechRecognitionServer, false, false },
    MessageDescription { "SpeechRecognitionServer_Stop"_s, ReceiverName::SpeechRecognitionServer, false, false },
    MessageDescription { "StorageAreaMap_ClearCache"_s, ReceiverName::StorageAreaMap, false, false },
    MessageDescription { "StorageAreaMap_DispatchStorageEvent"_s, ReceiverName::StorageAreaMap, false, false },
    MessageDescription { "VisitedLinkStore_AddVisitedLinkHashFromPage"_s, ReceiverName::VisitedLinkStore, false, false },
    MessageDescription { "VisitedLinkTableController_AllVisitedLinkStateChanged"_s, ReceiverName::VisitedLinkTableController, false, false },
    MessageDescription { "VisitedLinkTableController_RemoveAllVisitedLinks"_s, ReceiverName::VisitedLinkTableController, false, false },
    MessageDescription { "VisitedLinkTableController_SetVisitedLinkTable"_s, ReceiverName::VisitedLinkTableController, false, false },
    MessageDescription { "VisitedLinkTableController_VisitedLinkStateChanged"_s, ReceiverName::VisitedLinkTableController, false, false },
    MessageDescription { "WebAutomationSessionProxy_ComputeElementLayout"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_DeleteCookie"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_EvaluateJavaScriptFunction"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_FocusFrame"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_GetComputedLabel"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_GetComputedRole"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_GetCookiesForFrame"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_ResolveChildFrameWithName"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_ResolveChildFrameWithNodeHandle"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_ResolveChildFrameWithOrdinal"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_ResolveParentFrame"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_SelectOptionElement"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_SetFilesForInputFileUpload"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_SnapshotRectForScreenshot"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSessionProxy_TakeScreenshot"_s, ReceiverName::WebAutomationSessionProxy, false, false },
    MessageDescription { "WebAutomationSession_LogEntryAdded"_s, ReceiverName::WebAutomationSession, false, false },
    MessageDescription { "WebBroadcastChannelRegistry_PostMessageToRemote"_s, ReceiverName::WebBroadcastChannelRegistry, false, false },
    MessageDescription { "WebCookieManager_DeleteAllCookies"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_DeleteAllCookiesModifiedSince"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_DeleteCookie"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_DeleteCookiesForHostnames"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_GetAllCookies"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_GetCookies"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_GetHTTPCookieAcceptPolicy"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_GetHostnamesWithCookies"_s, ReceiverName::WebCookieManager, false, false },
#if USE(SOUP)
    MessageDescription { "WebCookieManager_ReplaceCookies"_s, ReceiverName::WebCookieManager, false, false },
#endif
    MessageDescription { "WebCookieManager_SetCookie"_s, ReceiverName::WebCookieManager, false, false },
#if USE(SOUP)
    MessageDescription { "WebCookieManager_SetCookiePersistentStorage"_s, ReceiverName::WebCookieManager, false, false },
#endif
    MessageDescription { "WebCookieManager_SetCookies"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_SetHTTPCookieAcceptPolicy"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_StartObservingCookieChanges"_s, ReceiverName::WebCookieManager, false, false },
    MessageDescription { "WebCookieManager_StopObservingCookieChanges"_s, ReceiverName::WebCookieManager, false, false },
#if ENABLE(INSPECTOR_EXTENSIONS)
    MessageDescription { "WebExtensionContextProxy_AddInspectorBackgroundPageIdentifier"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_AddInspectorPageIdentifier"_s, ReceiverName::WebExtensionContextProxy, false, false },
#endif
    MessageDescription { "WebExtensionContextProxy_AddPopupPageIdentifier"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_AddTabPageIdentifier"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchActionClickedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchAlarmsEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchCommandsChangedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchCommandsCommandEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchCookiesChangedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
#if ENABLE(INSPECTOR_EXTENSIONS)
    MessageDescription { "WebExtensionContextProxy_DispatchDevToolsExtensionPanelHiddenEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchDevToolsExtensionPanelShownEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchDevToolsNetworkNavigatedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchDevToolsPanelsThemeChangedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
#endif
    MessageDescription { "WebExtensionContextProxy_DispatchMenusClickedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchPermissionsEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchPortDisconnectEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchPortMessageEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchRuntimeConnectEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchRuntimeInstalledEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchRuntimeMessageEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchRuntimeStartupEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchStorageChangedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsActivatedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsAttachedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsCreatedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsDetachedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsHighlightedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsMovedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsRemovedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsReplacedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTabsUpdatedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTestFinishedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTestMessageEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchTestStartedEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchWebNavigationEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchWindowsEvent"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_ResourceLoadDidCompleteWithError"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_ResourceLoadDidPerformHTTPRedirection"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_ResourceLoadDidReceiveChallenge"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_ResourceLoadDidReceiveResponse"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_ResourceLoadDidSendRequest"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_SetBackgroundPageIdentifier"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_SetStorageAccessLevel"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContextProxy_UpdateGrantedPermissions"_s, ReceiverName::WebExtensionContextProxy, false, false },
    MessageDescription { "WebExtensionContext_ActionGetBadgeText"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionGetEnabled"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionGetPopup"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionGetTitle"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionOpenPopup"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionSetBadgeText"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionSetEnabled"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionSetIcon"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionSetPopup"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ActionSetTitle"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_AddListener"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_AlarmsClear"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_AlarmsClearAll"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_AlarmsCreate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_AlarmsGet"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_AlarmsGetAll"_s, ReceiverName::WebExtensionContext, false, false },
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    MessageDescription { "WebExtensionContext_BookmarksCreate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGet"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetChildren"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetRecent"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetSubTree"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetTree"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksMove"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksRemove"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksRemoveTree"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksSearch"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_BookmarksUpdate"_s, ReceiverName::WebExtensionContext, false, false },
#endif
    MessageDescription { "WebExtensionContext_CommandsGetAll"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_CookiesGet"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_CookiesGetAll"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_CookiesGetAllCookieStores"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_CookiesRemove"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_CookiesSet"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestDisplayActionCountAsBadgeText"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestGetDynamicRules"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestGetEnabledRulesets"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestGetMatchedRules"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestGetSessionRules"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestIncrementActionCount"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestUpdateDynamicRules"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestUpdateEnabledRulesets"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestUpdateSessionRules"_s, ReceiverName::WebExtensionContext, false, false },
#if ENABLE(INSPECTOR_EXTENSIONS)
    MessageDescription { "WebExtensionContext_DevToolsInspectedWindowEval"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DevToolsInspectedWindowReload"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_DevToolsPanelsCreate"_s, ReceiverName::WebExtensionContext, false, false },
#endif
    MessageDescription { "WebExtensionContext_ExtensionIsAllowedIncognitoAccess"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_MenusCreate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_MenusRemove"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_MenusRemoveAll"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_MenusUpdate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_PermissionsContains"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_PermissionsGetAll"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_PermissionsRemove"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_PermissionsRequest"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_PortPostMessage"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_PortRemoved"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RemoveListener"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeConnect"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeConnectNative"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeGetBackgroundPage"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeOpenOptionsPage"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeReload"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeSendMessage"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeSendNativeMessage"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeWebPageConnect"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_RuntimeWebPageSendMessage"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ScriptingExecuteScript"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ScriptingGetRegisteredScripts"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ScriptingInsertCSS"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ScriptingRegisterContentScripts"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ScriptingRemoveCSS"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ScriptingUnregisterContentScripts"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_ScriptingUpdateRegisteredScripts"_s, ReceiverName::WebExtensionContext, false, false },
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    MessageDescription { "WebExtensionContext_SidebarClose"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarGetActionClickBehavior"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarGetOptions"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarGetTitle"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarIsOpen"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarOpen"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarSetActionClickBehavior"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarSetIcon"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarSetOptions"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarSetTitle"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_SidebarToggle"_s, ReceiverName::WebExtensionContext, false, false },
#endif
    MessageDescription { "WebExtensionContext_StorageClear"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_StorageGet"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_StorageGetBytesInUse"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_StorageGetKeys"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_StorageRemove"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_StorageSet"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_StorageSetAccessLevel"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsCaptureVisibleTab"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsConnect"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsCreate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsDetectLanguage"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsDuplicate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsExecuteScript"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsGet"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsGetCurrent"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsGetZoom"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsGoBack"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsGoForward"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsInsertCSS"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsQuery"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsReload"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsRemove"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsRemoveCSS"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsSendMessage"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsSetZoom"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsToggleReaderMode"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_TabsUpdate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_WebNavigationGetAllFrames"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_WebNavigationGetFrame"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_WindowsCreate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_WindowsGet"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_WindowsGetAll"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_WindowsGetLastFocused"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_WindowsRemove"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionContext_WindowsUpdate"_s, ReceiverName::WebExtensionContext, false, false },
    MessageDescription { "WebExtensionControllerProxy_Load"_s, ReceiverName::WebExtensionControllerProxy, false, false },
    MessageDescription { "WebExtensionControllerProxy_Unload"_s, ReceiverName::WebExtensionControllerProxy, false, false },
    MessageDescription { "WebExtensionController_DidCommitLoadForFrame"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_DidFailLoadForFrame"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_DidFinishLoadForFrame"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_DidStartProvisionalLoadForFrame"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_TestAdded"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_TestEqual"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_TestFinished"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_TestLogMessage"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_TestResult"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_TestSentMessage"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebExtensionController_TestStarted"_s, ReceiverName::WebExtensionController, false, false },
    MessageDescription { "WebFileSystemStorageConnection_InvalidateAccessHandle"_s, ReceiverName::WebFileSystemStorageConnection, false, false },
    MessageDescription { "WebFileSystemStorageConnection_InvalidateWritable"_s, ReceiverName::WebFileSystemStorageConnection, false, false },
    MessageDescription { "WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrame"_s, ReceiverName::WebFrameProxy, false, false },
    MessageDescription { "WebFrameProxy_SetAppBadge"_s, ReceiverName::WebFrameProxy, false, false },
    MessageDescription { "WebFrameProxy_UpdateRemoteFrameSize"_s, ReceiverName::WebFrameProxy, false, false },
    MessageDescription { "WebFrame_CreateProvisionalFrame"_s, ReceiverName::WebFrame, false, false },
    MessageDescription { "WebFrame_DestroyProvisionalFrame"_s, ReceiverName::WebFrame, false, false },
    MessageDescription { "WebFrame_FindFocusableElementDescendingIntoRemoteFrame"_s, ReceiverName::WebFrame, false, false },
    MessageDescription { "WebFrame_GetFrameInfo"_s, ReceiverName::WebFrame, false, false },
    MessageDescription { "WebFrame_UpdateFrameSize"_s, ReceiverName::WebFrame, false, false },
    MessageDescription { "WebFullScreenManagerProxy_BeganEnterFullScreen"_s, ReceiverName::WebFullScreenManagerProxy, false, false },
    MessageDescription { "WebFullScreenManagerProxy_BeganExitFullScreen"_s, ReceiverName::WebFullScreenManagerProxy, false, false },
    MessageDescription { "WebFullScreenManagerProxy_Close"_s, ReceiverName::WebFullScreenManagerProxy, false, false },
    MessageDescription { "WebFullScreenManagerProxy_EnterFullScreen"_s, ReceiverName::WebFullScreenManagerProxy, false, false },
    MessageDescription { "WebFullScreenManagerProxy_ExitFullScreen"_s, ReceiverName::WebFullScreenManagerProxy, false, false },
#if ENABLE(QUICKLOOK_FULLSCREEN)
    MessageDescription { "WebFullScreenManagerProxy_UpdateImageSource"_s, ReceiverName::WebFullScreenManagerProxy, false, false },
#endif
    MessageDescription { "WebFullScreenManager_EnterFullScreenForOwnerElements"_s, ReceiverName::WebFullScreenManager, false, false },
    MessageDescription { "WebFullScreenManager_ExitFullScreenInMainFrame"_s, ReceiverName::WebFullScreenManager, false, false },
    MessageDescription { "WebFullScreenManager_RequestExitFullScreen"_s, ReceiverName::WebFullScreenManager, false, false },
    MessageDescription { "WebFullScreenManager_RequestRestoreFullScreen"_s, ReceiverName::WebFullScreenManager, false, false },
    MessageDescription { "WebFullScreenManager_SetAnimatingFullScreen"_s, ReceiverName::WebFullScreenManager, false, false },
    MessageDescription { "WebFullScreenManager_SetFullscreenAutoHideDuration"_s, ReceiverName::WebFullScreenManager, false, false },
    MessageDescription { "WebFullScreenManager_SetFullscreenInsets"_s, ReceiverName::WebFullScreenManager, false, false },
    MessageDescription { "WebGeolocationManagerProxy_SetEnableHighAccuracy"_s, ReceiverName::WebGeolocationManagerProxy, false, false },
    MessageDescription { "WebGeolocationManagerProxy_StartUpdating"_s, ReceiverName::WebGeolocationManagerProxy, false, false },
    MessageDescription { "WebGeolocationManagerProxy_StopUpdating"_s, ReceiverName::WebGeolocationManagerProxy, false, false },
    MessageDescription { "WebGeolocationManager_DidChangePosition"_s, ReceiverName::WebGeolocationManager, false, false },
    MessageDescription { "WebGeolocationManager_DidFailToDeterminePosition"_s, ReceiverName::WebGeolocationManager, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebGeolocationManager_ResetPermissions"_s, ReceiverName::WebGeolocationManager, false, false },
#endif
    MessageDescription { "WebIDBConnectionToServer_DidAbortTransaction"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidClearObjectStore"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidCloseFromServer"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidCommitTransaction"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidCreateIndex"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidCreateObjectStore"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidDeleteDatabase"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidDeleteIndex"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidDeleteObjectStore"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidDeleteRecord"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidGetAllDatabaseNamesAndVersions"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidGetAllRecords"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidGetCount"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidGetRecord"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidIterateCursor"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidOpenCursor"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidOpenDatabase"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidPutOrAdd"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidRenameIndex"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidRenameObjectStore"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_DidStartTransaction"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_FireVersionChangeEvent"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_GenerateIndexKeyForRecord"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebIDBConnectionToServer_NotifyOpenDBRequestBlocked"_s, ReceiverName::WebIDBConnectionToServer, false, false },
    MessageDescription { "WebInspectorBackendProxy_AttachAvailabilityChanged"_s, ReceiverName::WebInspectorBackendProxy, false, false },
    MessageDescription { "WebInspectorBackendProxy_BringToFront"_s, ReceiverName::WebInspectorBackendProxy, false, false },
    MessageDescription { "WebInspectorBackendProxy_DidClose"_s, ReceiverName::WebInspectorBackendProxy, false, false },
    MessageDescription { "WebInspectorBackendProxy_ElementSelectionChanged"_s, ReceiverName::WebInspectorBackendProxy, false, false },
    MessageDescription { "WebInspectorBackendProxy_RequestOpenLocalInspectorFrontend"_s, ReceiverName::WebInspectorBackendProxy, false, false },
    MessageDescription { "WebInspectorBackendProxy_SetDeveloperPreferenceOverride"_s, ReceiverName::WebInspectorBackendProxy, false, false },
#if ENABLE(INSPECTOR_NETWORK_THROTTLING)
    MessageDescription { "WebInspectorBackendProxy_SetEmulatedConditions"_s, ReceiverName::WebInspectorBackendProxy, false, false },
#endif
    MessageDescription { "WebInspectorBackendProxy_TimelineRecordingChanged"_s, ReceiverName::WebInspectorBackendProxy, false, false },
    MessageDescription { "WebInspectorInterruptDispatcher_NotifyNeedDebuggerBreak"_s, ReceiverName::WebInspectorInterruptDispatcher, false, false },
    MessageDescription { "WebInspectorUIProxy_AttachBottom"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_AttachLeft"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_AttachRight"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_BringToFront"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_Detach"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_DidClose"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_EffectiveAppearanceDidChange"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_FrontendLoaded"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_InspectedURLChanged"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_Load"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_OpenURLExternally"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_PickColorFromScreen"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_Reopen"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_ResetState"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_RevealFileExternally"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_Save"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_SendMessageToBackend"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_SetAttachedWindowHeight"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_SetAttachedWindowWidth"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_SetForcedAppearance"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_SetFrontendConnection"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_SetInspectorPageDeveloperExtrasEnabled"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_SetSheetRect"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_ShowCertificate"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUIProxy_StartWindowDrag"_s, ReceiverName::WebInspectorUIProxy, false, false },
    MessageDescription { "WebInspectorUI_AttachedBottom"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_AttachedLeft"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_AttachedRight"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_Detached"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_EstablishConnection"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_EvaluateInFrontendForTesting"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_SendMessageToFrontend"_s, ReceiverName::WebInspectorUI, false, false },
#if ENABLE(INSPECTOR_TELEMETRY)
    MessageDescription { "WebInspectorUI_SetDiagnosticLoggingAvailable"_s, ReceiverName::WebInspectorUI, false, false },
#endif
    MessageDescription { "WebInspectorUI_SetDockingUnavailable"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_SetIsVisible"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_ShowConsole"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_ShowMainResourceForFrame"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_ShowResources"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_StartElementSelection"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_StartPageProfiling"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_StopElementSelection"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_StopPageProfiling"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_UpdateConnection"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspectorUI_UpdateFindString"_s, ReceiverName::WebInspectorUI, false, false },
    MessageDescription { "WebInspector_Close"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_SetAttached"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_SetFrontendConnection"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_Show"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_ShowConsole"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_ShowMainResourceForFrame"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_ShowResources"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_StartElementSelection"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_StartPageProfiling"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_StopElementSelection"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebInspector_StopPageProfiling"_s, ReceiverName::WebInspector, false, false },
    MessageDescription { "WebLockRegistryProxy_AbortLockRequest"_s, ReceiverName::WebLockRegistryProxy, false, false },
    MessageDescription { "WebLockRegistryProxy_ClientIsGoingAway"_s, ReceiverName::WebLockRegistryProxy, false, false },
    MessageDescription { "WebLockRegistryProxy_ReleaseLock"_s, ReceiverName::WebLockRegistryProxy, false, false },
    MessageDescription { "WebLockRegistryProxy_RequestLock"_s, ReceiverName::WebLockRegistryProxy, false, false },
    MessageDescription { "WebLockRegistryProxy_Snapshot"_s, ReceiverName::WebLockRegistryProxy, false, false },
    MessageDescription { "WebNotificationManager_DidClickNotification"_s, ReceiverName::WebNotificationManager, false, false },
    MessageDescription { "WebNotificationManager_DidCloseNotifications"_s, ReceiverName::WebNotificationManager, false, false },
    MessageDescription { "WebNotificationManager_DidRemoveNotificationDecisions"_s, ReceiverName::WebNotificationManager, false, false },
    MessageDescription { "WebNotificationManager_DidShowNotification"_s, ReceiverName::WebNotificationManager, false, false },
    MessageDescription { "WebNotificationManager_DidUpdateNotificationDecision"_s, ReceiverName::WebNotificationManager, false, false },
#if ENABLE(APPLE_PAY_AMS_UI)
    MessageDescription { "WebPageProxy_AbortApplePayAMSUISession"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(MEDIA_USAGE)
    MessageDescription { "WebPageProxy_AddMediaUsageManagerSession"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_AddMessageToConsoleForTesting"_s, ReceiverName::WebPageProxy, true, false },
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_AddPlaybackTargetPickerClient"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPageProxy_AddTextAnimationForAnimationID"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_AddTextAnimationForAnimationIDWithCompletionHandler"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPageProxy_AssistiveTechnologyMakeFirstResponder"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_BackForwardAddItem"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_BackForwardClearChildren"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_BackForwardSetChildItem"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_BackForwardUpdateItem"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPageProxy_BeginMonitoringCaptureDevices"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if USE(SYSTEM_PREVIEW)
    MessageDescription { "WebPageProxy_BeginSystemPreview"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    MessageDescription { "WebPageProxy_BeginTextRecognitionForVideoInElementFullScreen"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPageProxy_BindAccessibilityTree"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_BroadcastProcessSyncData"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_BroadcastTopDocumentSyncData"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    MessageDescription { "WebPageProxy_CancelTextRecognitionForVideoInElementFullScreen"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPageProxy_ChangeUniversalAccessZoomFocus"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_ClearAllEditCommands"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ClearTextIndicator"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPageProxy_CloneAttachmentData"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_ClosePage"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_CommitPotentialTapFailed"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_CompositionWasCanceled"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ConfigureLoggingChannel"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(CONTENT_FILTERING)
    MessageDescription { "WebPageProxy_ContentFilterDidBlockLoadForFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "WebPageProxy_ContentRuleListNotification"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_CouldNotRestorePageState"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_CreateInspectorTarget"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(PDF_HUD)
    MessageDescription { "WebPageProxy_CreatePDFHUD"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    MessageDescription { "WebPageProxy_CreatePDFPageNumberIndicator"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DecidePolicyForNavigationActionAsync"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DecidePolicyForNewWindowAction"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DecidePolicyForResponse"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DestroyInspectorTarget"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(WINDOW_PROXY_PROPERTY_ACCESS_NOTIFICATION)
    MessageDescription { "WebPageProxy_DidAccessWindowProxyPropertyViaOpenerForFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidAdjustVisibilityWithSelectors"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidApplyLinkDecorationFiltering"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidCancelClientRedirectForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangeContentSize"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangeInspectorFrontendCount"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangeIntrinsicContentSize"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangeMainDocument"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangePageCount"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangeProgress"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangeProvisionalURLForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangeScrollOffsetPinningForMainFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidChangeScrollbarsForMainFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidCommitLoadForFrame"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_DidCompleteSyntheticClick"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    MessageDescription { "WebPageProxy_DidCreateContextInWebProcessForVisibilityPropagation"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidCreateSleepDisabler"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidCreateSubframe"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidDestroyFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidDestroyNavigation"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidDestroySleepDisabler"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidDisplayInsecureContentForFrame"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPageProxy_DidEndPartialIntelligenceTextAnimation"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidExplicitOpenForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFailLoadForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFailProvisionalLoadForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFindTextManipulationItems"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFinishDocumentLoadForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFinishLoadForFrame"_s, ReceiverName::WebPageProxy, false, false },
#if USE(QUICK_LOOK)
    MessageDescription { "WebPageProxy_DidFinishLoadForQuickLookDocumentInMainFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPageProxy_DidFinishLoadForResource"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidFinishLoadingDataForCustomContentProvider"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFinishProgress"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFinishServiceWorkerPageRegistration"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFirstLayoutForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidFirstVisuallyNonEmptyLayoutForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidGetImageForFindMatch"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_DidGetTapHighlightGeometries"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidHandleTapAsHover"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPageProxy_DidInitiateLoadForResource"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPageProxy_DidInsertAttachmentWithIdentifier"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidNavigateWithNavigationData"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_DidNotHandleTapAsClick"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidPerformClientRedirect"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPageProxy_DidPerformDictionaryLookup"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPageProxy_DidPerformImmediateActionHitTest"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidPerformServerRedirect"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_DidProgrammaticallyClearFocusedElement"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidReachLayoutMilestone"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPageProxy_DidReceiveEditDragSnapshot"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidReceiveEventIPC"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(MODEL_PROCESS)
    MessageDescription { "WebPageProxy_DidReceiveInteractiveModelElement"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_DidReceivePositionInformation"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPageProxy_DidReceiveResponseForResource"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidReceiveServerRedirectForProvisionalLoadForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidReceiveTitleForFrame"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPageProxy_DidRemoveAttachmentWithIdentifier"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidResignInputElementStrongPasswordAppearance"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidRestoreScrollPosition"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidRunInsecureContentForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidSameDocumentNavigationForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidSameDocumentNavigationForFrameViaJS"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPageProxy_DidSendRequestForResource"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if USE(QUICK_LOOK)
    MessageDescription { "WebPageProxy_DidStartLoadForQuickLookDocumentInMainFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DidStartProgress"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidStartProvisionalLoadForFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidUpdateActivityState"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidUpdateHistoryTitle"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DidUpdateRenderingAfterCommittingLoad"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_DisableDoubleTapGesturesDuringTapIfNecessary"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DisableInspectorNodeSearch"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPageProxy_DismissCorrectionPanel"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if HAVE(DIGITAL_CREDENTIALS_UI)
    MessageDescription { "WebPageProxy_DismissDigitalCredentialsPicker"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_DispatchLoadEventToFrameOwnerElement"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_DocumentURLForConsoleLog"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_EditorStateChanged"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_ElementDidBlur"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ElementDidFocus"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_EnableAccessibilityForAllProcesses"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_EnableInspectorNodeSearch"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_EndColorPicker"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_EndDataListSuggestions"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_EndDateTimePicker"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_EndNetworkRequestsForPageLoadTiming"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPageProxy_EnumerateMediaDevicesForFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_FixedLayoutSizeDidChange"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_FocusFromServiceWorker"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_FocusRemoteFrame"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_FocusedElementDidChangeInputMode"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_FocusedFrameChanged"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_FrameNameChanged"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(GAMEPAD)
    MessageDescription { "WebPageProxy_GamepadsRecentlyAccessed"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_GetLoadDecisionForIcon"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPageProxy_HandleAcceptsFirstMouse"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_HandleAutoFillButtonClick"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_HandleAutocorrectionContext"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_HandleAutoplayEvent"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(DATA_DETECTION)
    MessageDescription { "WebPageProxy_HandleClickForDataDetectionResult"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
    MessageDescription { "WebPageProxy_HandleContextMenuTranslation"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_HandleKeydownInDataList"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_HandleMessage"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_HandleMessageWithAsyncReply"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    MessageDescription { "WebPageProxy_HandleMouseDownForModelElement"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_HandleMouseMoveForModelElement"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_HandleMouseUpForModelElement"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_HandleSmartMagnificationInformationForPotentialTap"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_HasActiveNowPlayingSessionChanged"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_HideInspectorHighlight"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_HideInspectorIndication"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_HidePopupMenu"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(COCOA) || PLATFORM(GTK)
    MessageDescription { "WebPageProxy_HideValidationMessage"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_IgnoreWord"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ImageOrMediaDocumentSizeChanged"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    MessageDescription { "WebPageProxy_IsAnyAnimationAllowedToPlayDidChange"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_IsPlayingMediaDidChange"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_IsPotentialTapInProgress"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_LearnWord"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_LogDiagnosticMessageFromWebProcess"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_LogDiagnosticMessageWithDomainFromWebProcess"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_LogDiagnosticMessageWithResultFromWebProcess"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_LogDiagnosticMessageWithValueDictionaryFromWebProcess"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_LogDiagnosticMessageWithValueFromWebProcess"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_LogScrollingEvent"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_MainFramePluginHandlesPageScaleGestureDidChange"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPageProxy_MakeFirstResponder"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_MockMediaPlaybackTargetPickerDismissPopup"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    MessageDescription { "WebPageProxy_ModelElementAnimationCurrentTime"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementAnimationDuration"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    MessageDescription { "WebPageProxy_ModelElementCreateRemotePreview"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementDestroyRemotePreview"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    MessageDescription { "WebPageProxy_ModelElementGetCamera"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementHasAudio"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementIsLoopingAnimation"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementIsMuted"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementIsPlayingAnimation"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    MessageDescription { "WebPageProxy_ModelElementLoadRemotePreview"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    MessageDescription { "WebPageProxy_ModelElementSetAnimationCurrentTime"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementSetAnimationIsPlaying"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementSetCamera"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
    MessageDescription { "WebPageProxy_ModelElementSetInteractionEnabled"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    MessageDescription { "WebPageProxy_ModelElementSetIsLoopingAnimation"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelElementSetIsMuted"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    MessageDescription { "WebPageProxy_ModelElementSizeDidChange"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ModelInlinePreviewUUIDs"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_MouseDidMoveOverElement"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_NotifyScrollerThumbIsVisibleInRect"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_NowPlayingMetadataChanged"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_PageDidScroll"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_PageExtendedBackgroundColorDidChange"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_PageScaleFactorDidChange"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_PerformSwitchHapticFeedback"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_PlaybackTargetPickerClientStateDidChange"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_PluginScaleFactorDidChange"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_PluginZoomFactorDidChange"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_PostMessageToRemote"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPageProxy_ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ProofreadingSessionUpdateStateForSuggestionWithID"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_RecommendedScrollbarStyleDidChange"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPageProxy_RecordAutocorrectionResponse"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPageProxy_RegisterAttachmentIdentifier"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RegisterAttachmentIdentifierFromData"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RegisterAttachmentIdentifierFromFilePath"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RegisterAttachmentsFromSerializedData"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_RegisterEditCommandForUndo"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RegisterInsertionUndoGrouping"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPageProxy_RegisterWebProcessAccessibilityToken"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_RelayAccessibilityNotification"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if USE(DICTATION_ALTERNATIVES)
    MessageDescription { "WebPageProxy_RemoveDictationAlternatives"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(MEDIA_USAGE)
    MessageDescription { "WebPageProxy_RemoveMediaUsageManagerSession"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(PDF_HUD)
    MessageDescription { "WebPageProxy_RemovePDFHUD"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    MessageDescription { "WebPageProxy_RemovePDFPageNumberIndicator"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_RemovePlaybackTargetPickerClient"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPageProxy_RemoveTextAnimationForAnimationID"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPageProxy_RequestAttachmentIcon"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_RequestCheckingOfString"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RequestCookieConsent"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RequestGeolocationPermissionForFrame"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(ENCRYPTED_MEDIA)
    MessageDescription { "WebPageProxy_RequestMediaKeySystemPermissionForFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_RequestNotificationPermission"_s, ReceiverName::WebPageProxy, false, false },
#if USE(QUICK_LOOK)
    MessageDescription { "WebPageProxy_RequestPasswordForQuickLookDocumentInMainFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(POINTER_LOCK)
    MessageDescription { "WebPageProxy_RequestPointerLock"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RequestPointerUnlock"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_RequestScrollToRect"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(IMAGE_ANALYSIS)
    MessageDescription { "WebPageProxy_RequestTextRecognition"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPageProxy_RequestUserMediaPermissionForFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_ResolveAccessibilityHitTestForTesting"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_RestorePageCenterAndScale"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RestorePageState"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_RevokeGeolocationAuthorizationToken"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RunModal"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_RunOpenPanel"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SampledPageTopColorChanged"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_SaveImageToLibrary"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SaveRecentSearches"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_ScrollingNodeScrollDidEndScroll"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ScrollingNodeScrollWillStartScroll"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPageProxy_SearchTheWeb"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SendMessageToInspectorFrontend"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPageProxy_SendMessageToWebView"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SendMessageToWebViewWithReply"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SetAllowsLayoutViewportHeightExpansion"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetCanShortCircuitHorizontalWheelEvents"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetColorPickerColor"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetCursor"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetCursorHiddenUntilMouseMoves"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(DATA_DETECTION)
    MessageDescription { "WebPageProxy_SetDataDetectionResult"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPageProxy_SetEditableElementIsFocused"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SetFocus"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetHasActiveAnimatedScrolls"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetHasExecutedAppBoundBehaviorBeforeNavigation"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetHasFocusedElementWithUserInteraction"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPageProxy_SetInputMethodState"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if HAVE(TOUCH_BAR)
    MessageDescription { "WebPageProxy_SetIsNeverRichlyEditableForTouchBar"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SetIsResizable"_s, ReceiverName::WebPageProxy, false, false },
#if HAVE(TOUCH_BAR)
    MessageDescription { "WebPageProxy_SetIsTouchBarUpdateSuppressedForHiddenContentEditable"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SetMenuBarIsVisible"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_SetMockMediaPlaybackTargetPickerEnabled"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetMockMediaPlaybackTargetPickerState"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(VIDEO_PRESENTATION_MODE)
    MessageDescription { "WebPageProxy_SetMockVideoPresentationModeEnabled"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(WEB_AUTHN)
    MessageDescription { "WebPageProxy_SetMockWebAuthenticationConfiguration"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SetNetworkRequestsInProgress"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPageProxy_SetPromisedDataForImage"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SetRenderTreeSize"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPageProxy_SetShouldListenToVoiceActivity"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_SetStatusBarIsVisible"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetTextIndicatorFromFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetToolbarsAreVisible"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SetWindowFrame"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(DEVICE_ORIENTATION)
    MessageDescription { "WebPageProxy_ShouldAllowDeviceOrientationAndMotionAccess"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_ShouldGoToBackForwardListItem"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ShowColorPicker"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ShowContactPicker"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(CONTEXT_MENUS)
    MessageDescription { "WebPageProxy_ShowContextMenuFromFrame"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPageProxy_ShowCorrectionPanel"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_ShowDataDetectorsUIForPositionInformation"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_ShowDataListSuggestions"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ShowDateTimePicker"_s, ReceiverName::WebPageProxy, false, false },
#if USE(DICTATION_ALTERNATIVES)
    MessageDescription { "WebPageProxy_ShowDictationAlternativeUI"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if HAVE(DIGITAL_CREDENTIALS_UI)
    MessageDescription { "WebPageProxy_ShowDigitalCredentialsPicker"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(GTK)
    MessageDescription { "WebPageProxy_ShowEmojiPicker"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_ShowInspectorHighlight"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ShowInspectorIndication"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
    MessageDescription { "WebPageProxy_ShowMediaControlsContextMenu"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    MessageDescription { "WebPageProxy_ShowPDFContextMenu"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_ShowPage"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY) || ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_ShowPlaybackTargetPicker"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_ShowPopupMenuFromFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_ShowShareSheet"_s, ReceiverName::WebPageProxy, false, false },
#if (ENABLE(TELEPHONE_NUMBER_DETECTION) && PLATFORM(MAC))
    MessageDescription { "WebPageProxy_ShowTelephoneNumberMenu"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK)
    MessageDescription { "WebPageProxy_ShowValidationMessage"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    MessageDescription { "WebPageProxy_SpatialBackdropSourceChanged"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    MessageDescription { "WebPageProxy_SpeechSynthesisCancel"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SpeechSynthesisPause"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SpeechSynthesisResetState"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SpeechSynthesisResume"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SpeechSynthesisSetFinishedCallback"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_SpeechSynthesisSpeak"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(APPLE_PAY_AMS_UI)
    MessageDescription { "WebPageProxy_StartApplePayAMSUISession"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT) || (PLATFORM(GTK) || PLATFORM(WPE)) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPageProxy_StartDrag"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_StartNetworkRequestsForPageLoadTiming"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_StartURLSchemeTask"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_StopURLSchemeTask"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_TakeFocus"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
    MessageDescription { "WebPageProxy_TakeModelElementFullscreen"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(MAC) || PLATFORM(WPE) || PLATFORM(GTK)
    MessageDescription { "WebPageProxy_ThemeColorChanged"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_UpdateFocusedElementInformation"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_UpdateInputContextAfterBlurringAndRefocusingElement"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(MEDIA_USAGE)
    MessageDescription { "WebPageProxy_UpdateMediaUsageManagerSessionState"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_UpdateOpener"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(PDF_HUD)
    MessageDescription { "WebPageProxy_UpdatePDFHUDLocation"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    MessageDescription { "WebPageProxy_UpdatePDFPageNumberIndicatorCurrentPage"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_UpdatePDFPageNumberIndicatorLocation"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_UpdateRemoteFrameAccessibilityOffset"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_UpdateSandboxFlags"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_UpdateScrollingMode"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_UpdateSpellingUIWithGrammarString"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_UpdateSpellingUIWithMisspelledWord"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_UpdateStringForFind"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_UpdateTextIndicatorFromFrame"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_UseFixedLayoutDidChange"_s, ReceiverName::WebPageProxy, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPageProxy_ValidateCaptureStateUpdate"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_ViewScaleFactorDidChange"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_WillPerformClientRedirectForFrame"_s, ReceiverName::WebPageProxy, false, false },
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPageProxy_WillReceiveEditDragSnapshot"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageProxy_WillSubmitForm"_s, ReceiverName::WebPageProxy, false, false },
#if (ENABLE(ATTACHMENT_ELEMENT) && PLATFORM(IOS_FAMILY))
    MessageDescription { "WebPageProxy_WritePromisedAttachmentToPasteboard"_s, ReceiverName::WebPageProxy, false, false },
#endif
#if USE(AUTOMATIC_TEXT_REPLACEMENT)
    MessageDescription { "WebPageProxy_toggleAutomaticDashSubstitution"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_toggleAutomaticLinkDetection"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_toggleAutomaticQuoteSubstitution"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_toggleAutomaticTextReplacement"_s, ReceiverName::WebPageProxy, false, false },
    MessageDescription { "WebPageProxy_toggleSmartInsertDelete"_s, ReceiverName::WebPageProxy, false, false },
#endif
    MessageDescription { "WebPageTesting_ClearCachedBackForwardListCounts"_s, ReceiverName::WebPageTesting, false, false },
#if ENABLE(NOTIFICATIONS)
    MessageDescription { "WebPageTesting_ClearNotificationPermissionState"_s, ReceiverName::WebPageTesting, false, false },
#endif
    MessageDescription { "WebPageTesting_ClearWheelEventTestMonitor"_s, ReceiverName::WebPageTesting, false, false },
    MessageDescription { "WebPageTesting_DisplayAndTrackRepaints"_s, ReceiverName::WebPageTesting, false, false },
    MessageDescription { "WebPageTesting_IsLayerTreeFrozen"_s, ReceiverName::WebPageTesting, false, false },
    MessageDescription { "WebPageTesting_ResetStateBetweenTests"_s, ReceiverName::WebPageTesting, false, false },
    MessageDescription { "WebPageTesting_SetObscuredContentInsets"_s, ReceiverName::WebPageTesting, false, false },
    MessageDescription { "WebPageTesting_SetPermissionLevel"_s, ReceiverName::WebPageTesting, false, false },
    MessageDescription { "WebPageTesting_SetTracksRepaints"_s, ReceiverName::WebPageTesting, false, false },
    MessageDescription { "WebPage_AccessibilitySettingsDidChange"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_AddConsoleMessage"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_AddDictationAlternative"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_AddLayerForFindOverlay"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_AdjustVisibilityForTargetedElements"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_AdvanceToNextMisspelling"_s, ReceiverName::WebPage, false, false },
#if (ENABLE(GAMEPAD) && PLATFORM(VISION))
    MessageDescription { "WebPage_AllowGamepadAccess"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ApplicationDidBecomeActive"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ApplicationDidEnterBackground"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ApplicationDidEnterBackgroundForMedia"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ApplicationDidFinishSnapshottingAfterEnteringBackground"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ApplicationWillEnterForeground"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ApplicationWillEnterForegroundForMedia"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ApplicationWillResignActive"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ApplyAutocorrection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_AttemptSyntheticClick"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPage_AttributedSubstringForCharacterRangeAsync"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_AutofillLoginCredentials"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_BeginPrinting"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_BeginPrintingDuringDOMPrintOperation"_s, ReceiverName::WebPage, false, true },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_BeginSelectionInDirection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_BlurFocusedElement"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    MessageDescription { "WebPage_BoundaryEventOccurred"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_CancelAutoscroll"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPage_CancelComposition"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_CancelPointer"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_CancelPotentialTap"_s, ReceiverName::WebPage, false, false },
#endif
#if USE(APPKIT)
    MessageDescription { "WebPage_CapitalizeWord"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPage_CaptureDevicesChanged"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_CenterSelectionInVisibleArea"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ChangeFont"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ChangeFontAttributes"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ChangeListType"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ChangeSpellingToWord"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_CharacterIndexForPointAsync"_s, ReceiverName::WebPage, false, false },
#endif
#if (PLATFORM(MAC) && ENABLE(ACCESSIBILITY_ISOLATED_TREE))
    MessageDescription { "WebPage_ClearAccessibilityIsolatedTree"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ClearAllDecoratedFoundText"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_ClearDictationAlternatives"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ClearLoadedSubresourceDomains"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ClearSelection"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ClearSelectionAfterTappingSelectionHighlightIfNeeded"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ClearServiceWorkerEntitlementOverride"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_Close"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_CloseCurrentTypingCommand"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(GTK)
    MessageDescription { "WebPage_CollapseSelectionInFrame"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_CommitPotentialTap"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_CompleteTextManipulation"_s, ReceiverName::WebPage, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_CompositionSessionDidReceiveTextWithReplacementRange"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ComputePagesForPrinting"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ComputePagesForPrintingDuringDOMPrintOperation"_s, ReceiverName::WebPage, false, true },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_ConfirmCompositionAsync"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ConnectInspector"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ContentSizeCategoryDidChange"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ContentsToRootViewPoint"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ContentsToRootViewRect"_s, ReceiverName::WebPage, false, false },
#if ENABLE(CONTEXT_MENUS)
    MessageDescription { "WebPage_ContextMenuForKeyEvent"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_CopyLinkWithHighlight"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_CountStringMatches"_s, ReceiverName::WebPage, false, false },
#if ENABLE(APP_HIGHLIGHTS)
    MessageDescription { "WebPage_CreateAppHighlightInSelectedRange"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_CreateBitmapsFromImageData"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    MessageDescription { "WebPage_CreateMediaSessionCoordinator"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_CreateRemoteSubframe"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_CreateTextFragmentDirectiveFromSelection"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_CreateTextIndicatorForElementWithID"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_CreateTextIndicatorForTextAnimationID"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPage_DataDetectorsDidChangeUI"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DataDetectorsDidHideUI"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DataDetectorsDidPresentUI"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_DecodeImageData"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DecorateTextRangeWithStyle"_s, ReceiverName::WebPage, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_DecorateTextReplacementsForActiveWritingToolsSession"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DecreaseListLevel"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPage_DeleteSurrounding"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(DATA_DETECTION)
    MessageDescription { "WebPage_DetectDataInAllFrames"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_DictationAlternativesAtSelection"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPage_DidBeginMagnificationGesture"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DidBeginTextSearchOperation"_s, ReceiverName::WebPage, false, false },
#if ENABLE(IOS_TOUCH_EVENTS)
    MessageDescription { "WebPage_DidBeginTouchPoint"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_DidBeginWritingToolsSession"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DidCancelCheckingText"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidCancelForOpenPanel"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidChangeSelectedIndexForActivePopupMenu"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidChooseColor"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidChooseDate"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidChooseFilesForOpenPanel"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_DidChooseFilesForOpenPanelWithDisplayStringAndIcon"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DidCloseSuggestions"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_DidConcludeDrop"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(CONTEXT_MENUS)
    MessageDescription { "WebPage_DidDismissContextMenu"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DidEndColorPicker"_s, ReceiverName::WebPage, false, false },
#if USE(UICONTEXTMENU)
    MessageDescription { "WebPage_DidEndContextMenuInteraction"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DidEndDateTimePicker"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPage_DidEndMagnificationGesture"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_DidEndUserTriggeredZooming"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_DidEndWritingToolsSession"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DidFinishCheckingText"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidFinishLoadInAnotherProcess"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidGetLoadDecisionForIcon"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_DidInsertFinalDictationResult"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(POINTER_LOCK)
    MessageDescription { "WebPage_DidLosePointerLock"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(GEOLOCATION)
    MessageDescription { "WebPage_DidReceiveGeolocationPermissionDecision"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_DidRecognizeLongPress"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidReleaseAllTouchPoints"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DidRemoveBackForwardItem"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidRemoveEditCommand"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidScalePage"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidScalePageInViewCoordinates"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidScalePageRelativeToScrollPosition"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidScaleView"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidSelectDataListOption"_s, ReceiverName::WebPage, false, false },
#if ENABLE(CONTEXT_MENUS)
    MessageDescription { "WebPage_DidSelectItemFromActiveContextMenu"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DidSetPageZoomFactor"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DidSetTextZoomFactor"_s, ReceiverName::WebPage, false, false },
#if ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_DidStartDrag"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_DisconnectInspector"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DispatchLoadEventToFrameOwnerElement"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_DispatchWheelEventWithoutScrolling"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_DragCancelled"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DragEnded"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(GTK)
    MessageDescription { "WebPage_DrawPagesForPrinting"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DrawPagesForPrintingDuringDOMPrintOperation"_s, ReceiverName::WebPage, false, true },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_DrawPagesToPDF"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DrawPagesToPDFDuringDOMPrintOperation"_s, ReceiverName::WebPage, false, true },
    MessageDescription { "WebPage_DrawRectToImage"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_DrawRectToImageDuringDOMPrintOperation"_s, ReceiverName::WebPage, false, true },
    MessageDescription { "WebPage_DrawRemoteToPDF"_s, ReceiverName::WebPage, false, false },
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    MessageDescription { "WebPage_DrawToImage"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_DrawToPDF"_s, ReceiverName::WebPage, false, false },
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    MessageDescription { "WebPage_DrawToPDFiOS"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_DynamicViewportSizeUpdate"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_EnableAccessibility"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_EndPrinting"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_EndPrintingDuringDOMPrintOperation"_s, ReceiverName::WebPage, false, true },
    MessageDescription { "WebPage_EnqueueSecurityPolicyViolationEvent"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ExecuteEditCommand"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ExecuteEditCommandWithCallback"_s, ReceiverName::WebPage, false, false },
#if ENABLE(SANDBOX_EXTENSIONS)
    MessageDescription { "WebPage_ExtendSandboxForFilesFromOpenPanel"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ExtendSelection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ExtendSelectionForReplacement"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(GTK)
    MessageDescription { "WebPage_FailedToShowPopupMenu"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_FindRectsForStringMatches"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_FindString"_s, ReceiverName::WebPage, false, false },
#if ENABLE(IMAGE_ANALYSIS)
    MessageDescription { "WebPage_FindStringIncludingImages"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_FindStringMatches"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_FindTextRangesForStringMatches"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_FirstRectForCharacterRangeAsync"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_FlushDeferredDidReceiveMouseEvent"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_FlushDeferredResizeEvents"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_FlushDeferredScrollEvents"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_FocusNextFocusedElement"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_FocusTextInputContextAndPlaceCaret"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_FrameNameWasChangedInAnotherProcess"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_FrameWasFocusedInAnotherProcess"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_FrameWasRemovedInAnotherProcess"_s, ReceiverName::WebPage, false, false },
#if ENABLE(GAMEPAD)
    MessageDescription { "WebPage_GamepadActivity"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_GenerateSyntheticEditingCommand"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GenerateTestReport"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetAccessibilityTreeData"_s, ReceiverName::WebPage, false, false },
#if ENABLE(APPLICATION_MANIFEST)
    MessageDescription { "WebPage_GetApplicationManifest"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GetBytecodeProfile"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetContentsAsAttributedString"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(MHTML)
    MessageDescription { "WebPage_GetContentsAsMHTMLData"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GetContentsAsString"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetFrameTree"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetImageForFindMatch"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetInformationFromImageData"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GetLoadedSubresourceDomains"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetMainResourceDataOfFrame"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetMarkedRangeAsync"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GetPDFFirstPageSize"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetProcessDisplayName"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_GetRectsAtSelectionOffsetWithText"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetRectsForGranularityWithSelectionOffset"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GetRenderTreeExternalRepresentation"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetResourceDataFromFrame"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetSamplingProfilerOutput"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetSelectedRangeAsync"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GetSelectionAsWebArchiveData"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_GetSelectionContext"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GetSelectionOrContentsAsString"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetSourceForFrame"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetTextFragmentMatch"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetTextFragmentRanges"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetWebArchiveOfFrame"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GetWebArchiveOfFrameWithFileName"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetWebArchives"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_GoToBackForwardItem"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_GoToBackForwardItemWaitingForProcessLaunch"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPage_HandleAcceptedCandidate"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_HandleAlternativeTextUIResult"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_HandleAutocorrectionContextRequest"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_HandleDoubleTapForDoubleClickAtPoint"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_HandleTwoFingerTapAtPoint"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_HandleWheelEvent"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_HardwareKeyboardAvailabilityChanged"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_HasMarkedText"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_HideFindUI"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPage_ImmediateActionDidCancel"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ImmediateActionDidComplete"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ImmediateActionDidUpdate"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_IncreaseListLevel"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_IndicateFindMatch"_s, ReceiverName::WebPage, false, false },
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPage_InsertAttachment"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_InsertDictatedTextAsync"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_InsertDroppedImagePlaceholders"_s, ReceiverName::WebPage, false, false },
#endif
#if (PLATFORM(COCOA) && ENABLE(MULTI_REPRESENTATION_HEIC))
    MessageDescription { "WebPage_InsertMultiRepresentationHEIC"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_InsertTextAsync"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_InsertTextPlaceholder"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_InspectorNodeSearchEndedAtPosition"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_InspectorNodeSearchMovedToPosition"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_IntelligenceTextAnimationsDidComplete"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_KeyEvent"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LastNavigationWasAppInitiated"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ListenForLayoutMilestones"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadAlternateHTML"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadAndDecodeImage"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadData"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadDataInFrame"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadDidCommitInAnotherProcess"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadRequest"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadRequestWaitingForProcessLaunch"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadSimulatedRequestAndResponse"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_LoadURLInFrame"_s, ReceiverName::WebPage, false, false },
#if USE(APPKIT)
    MessageDescription { "WebPage_LowercaseWord"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    MessageDescription { "WebPage_MediaKeySystemWasDenied"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_MediaKeySystemWasGranted"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(MODEL_PROCESS) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_ModelDragEnded"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
    MessageDescription { "WebPage_ModelInlinePreviewDidFailToLoad"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ModelInlinePreviewDidLoad"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_MouseEvent"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_MoveSelectionAtBoundaryWithDirection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_MoveSelectionByOffset"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_NavigateServiceWorkerClient"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_NavigateToPDFLinkWithSimulatedClick"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_NotifyReportObservers"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_NumberOfVisibilityAdjustmentRects"_s, ReceiverName::WebPage, false, false },
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    MessageDescription { "WebPage_OpenPDFWithPreview"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    MessageDescription { "WebPage_PauseAllAnimations"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_PauseAllMediaPlayback"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_PerformActionOnElement"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_PerformActionOnElements"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_PerformDictionaryLookupAtLocation"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(GTK) && ENABLE(DRAG_SUPPORT) || !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_PerformDragControllerAction"_s, ReceiverName::WebPage, false, false },
#endif
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_PerformDragOperation"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_PerformHitTestForMouseEvent"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPage_PerformImmediateActionHitTestAtLocation"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    MessageDescription { "WebPage_PlayAllAnimations"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_PlaybackTargetAvailabilityDidChange"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_PlaybackTargetPickerWasDismissed"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_PlaybackTargetSelected"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_PostInjectedBundleMessage"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_PotentialTapAtPosition"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_PreferencesDidChange"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_PreferencesDidChangeDuringDOMPrintOperation"_s, ReceiverName::WebPage, false, true },
#if PLATFORM(WPE) && USE(GBM) && ENABLE(WPE_PLATFORM)
    MessageDescription { "WebPage_PreferredBufferFormatsDidChange"_s, ReceiverName::WebPage, false, false },
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    MessageDescription { "WebPage_PrepareSelectionForContextMenuWithLocationInView"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ProcessDidResume"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ProcessSyncDataChangedInAnotherProcess"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ProcessWillSuspend"_s, ReceiverName::WebPage, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_ProofreadingSessionDidReceiveSuggestions"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ProofreadingSessionDidUpdateStateForSuggestion"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ProofreadingSessionSuggestionTextRectsInRootViewCoordinates"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ReapplyEditCommand"_s, ReceiverName::WebPage, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_RegisterUIProcessAccessibilityTokens"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_RegisterURLSchemeHandler"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_Reload"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RemoteDictionaryPopupInfoToRootView"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RemotePostMessage"_s, ReceiverName::WebPage, false, false },
#if ENABLE(DATA_DETECTION)
    MessageDescription { "WebPage_RemoveDataDetectedLinks"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_RemoveLayerForFindOverlay"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_RemoveTextPlaceholder"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ReplaceDictatedText"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ReplaceFoundTextRangeWithString"_s, ReceiverName::WebPage, false, false },
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    MessageDescription { "WebPage_ReplaceImageForRemoveBackground"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ReplaceMatches"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ReplaceSelectedText"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_ReplaceSelectionWithPasteboardData"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPage_RequestAcceptsFirstMouse"_s, ReceiverName::WebPage, false, true },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_RequestActiveNowPlayingSessionInfo"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_RequestAdditionalItemsForDragSession"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_RequestAllTargetableElements"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RequestAllTextAndRects"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_RequestAutocorrectionData"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RequestDocumentEditingContext"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_RequestDragStart"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_RequestEvasionRectsAboveSelection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RequestFocusedElementInformation"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_RequestFontAttributesAtSelectionStart"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RequestImageBitmap"_s, ReceiverName::WebPage, false, false },
#if ENABLE(MODEL_PROCESS)
    MessageDescription { "WebPage_RequestInteractiveModelElementAtPoint"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_RequestMediaPlaybackState"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_RequestPositionInformation"_s, ReceiverName::WebPage, false, false },
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    MessageDescription { "WebPage_RequestRVItemInCurrentSelectedRange"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_RequestRectForFoundTextRange"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RequestTargetedElement"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RequestTextExtraction"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ResetVisibilityAdjustmentsForTargetedElements"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ResolveAccessibilityHitTestForTesting"_s, ReceiverName::WebPage, false, false },
#if ENABLE(APP_HIGHLIGHTS)
    MessageDescription { "WebPage_RestoreAppHighlightsAndScrollToIndex"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_RestoreSelectionInFocusedEditableElement"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_Resume"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ResumeActiveDOMObjectsAndAnimations"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ResumeAllMediaPlayback"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_RunJavaScriptInFrameInScriptWorld"_s, ReceiverName::WebPage, false, false },
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    MessageDescription { "WebPage_SavePDF"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ScheduleFullEditorStateUpdate"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ScrollBy"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ScrollTextRangeToVisible"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ScrollToEdge"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ScrollToRect"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SelectAll"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SelectFindMatch"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SelectPositionAtBoundaryWithDirection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SelectPositionAtPoint"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SelectTextWithGranularityAtPoint"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SelectWithGesture"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SelectWithTwoTouches"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SelectWordBackward"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPage_SemanticContextDidChange"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SendMessageToTargetBackend"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPage_SendMessageToWebProcessExtension"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SendMessageToWebProcessExtensionWithReply"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SendReportToEndpoints"_s, ReceiverName::WebPage, false, false },
#if HAVE(APP_ACCENT_COLORS)
    MessageDescription { "WebPage_SetAccentColor"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetActivityState"_s, ReceiverName::WebPage, false, false },
#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
    MessageDescription { "WebPage_SetAllowedQueryParametersForAdvancedPrivacyProtections"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetAllowsMediaDocumentInlinePlayback"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetAlwaysShowsHorizontalScroller"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetAlwaysShowsVerticalScroller"_s, ReceiverName::WebPage, false, false },
#if ENABLE(APP_HIGHLIGHTS)
    MessageDescription { "WebPage_SetAppHighlightsVisibility"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetAutoSizingShouldExpandToViewHeight"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetBackgroundColor"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetBackgroundExtendsBeyondPage"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetBaseWritingDirection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetCanRunBeforeUnloadConfirmPanel"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetCanRunModal"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetCanShowPlaceholder"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetCanUseCredentialStorage"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPage_SetCaretAnimatorType"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetCaretBlinkingSuspended"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_SetCompositionAsync"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetContentOffset"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetControlledByAutomation"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetCurrentHistoryItemForReattach"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetCustomTextEncodingName"_s, ReceiverName::WebPage, false, false },
#if HAVE(SPATIAL_TRACKING_LABEL)
    MessageDescription { "WebPage_SetDefaultSpatialTrackingLabel"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetDefaultUnobscuredSize"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetDeviceOrientation"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetEditable"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetEnableHorizontalRubberBanding"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetEnableVerticalRubberBanding"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetFixedLayoutSize"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetFocusedElementSelectedIndex"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetFocusedElementValue"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPage_SetFooterBannerHeight"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetForceAlwaysUserScalable"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetGapBetweenPages"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetHasCustomUserAgent"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetHasResourceLoadClient"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPage_SetHeaderBannerHeight"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(REMOTE_INSPECTOR)
    MessageDescription { "WebPage_SetIndicating"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetInitialFocus"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetInsertionPointColor"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    MessageDescription { "WebPage_SetInteractionRegionsEnabled"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetIsShowingInputViewForFocusedElement"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetIsSuspended"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetIsTakingSnapshotsForApplicationSuspension"_s, ReceiverName::WebPage, false, false },
#if HAVE(UIKIT_RESIZABLE_WINDOWS)
    MessageDescription { "WebPage_SetIsWindowResizingEnabled"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetLastKnownMousePosition"_s, ReceiverName::WebPage, false, false },
#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
    MessageDescription { "WebPage_SetLinkDecorationFilteringData"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_SetMainFrameIsScrollable"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetMaximumUnobscuredSize"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetMayStartMediaWhenInWindow"_s, ReceiverName::WebPage, false, false },
#if ENABLE(EXTENSION_CAPABILITIES)
    MessageDescription { "WebPage_SetMediaEnvironment"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetMediaVolume"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetMinimumSizeForAutoLayout"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetMinimumUnobscuredSize"_s, ReceiverName::WebPage, false, false },
#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
    MessageDescription { "WebPage_SetMockCaptureDevicesInterrupted"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetMuted"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetNeedsDOMWindowResizeEvent"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetNeedsFixedContainerEdgesUpdate"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetNeedsFontAttributes"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetNeedsScrollGeometryUpdates"_s, ReceiverName::WebPage, false, false },
#if !PLATFORM(COCOA)
    MessageDescription { "WebPage_SetObscuredContentInsets"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_SetObscuredContentInsetsFenced"_s, ReceiverName::WebPage, false, false },
#endif
#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
    MessageDescription { "WebPage_SetOrientationForMediaCapture"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetOverriddenMediaType"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetOverrideViewportArguments"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetPageLength"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetPaginationBehavesLikeColumns"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetPaginationMode"_s, ReceiverName::WebPage, false, false },
#if HAVE(AUDIT_TOKEN)
    MessageDescription { "WebPage_SetPresentingApplicationAuditTokenAndBundleIdentifier"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetSceneIdentifier"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetScreenIsBeingCaptured"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetScrollPinningBehavior"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetScrollbarOverlayStyle"_s, ReceiverName::WebPage, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_SetSelectionForActiveWritingToolsSession"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetShouldDispatchFakeMouseMoveEvents"_s, ReceiverName::WebPage, false, false },
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetShouldPlayToPlaybackTarget"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetShouldRevealCurrentSelectionAfterInsertion"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetShouldScaleViewToFitDocument"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetShouldSuppressHDR"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetSizeToContentAutoSizeMaximumSize"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_SetSmartInsertDeleteEnabled"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetSuppressScrollbarAnimations"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_SetTextAsync"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetTextForActivePopupMenu"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetUnderPageBackgroundColorOverride"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetUnderlayColor"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetUseColorAppearance"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetUseFixedLayout"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetUseIconLoadingClient"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetUserAgent"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SetUserInterfaceLayoutDirection"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SetViewportConfigurationViewLayoutSize"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SetViewportSizeForCSSViewportUnits"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_SetWritingSuggestion"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    MessageDescription { "WebPage_ShouldAllowRemoveBackground"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ShouldDismissKeyboardAfterTapAtPoint"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_SimulateClickOverFirstMatchingTextInViewportWithUserInteraction"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SimulateDeviceOrientationChange"_s, ReceiverName::WebPage, false, false },
#if ENABLE(SPEECH_SYNTHESIS)
    MessageDescription { "WebPage_SpeakingErrorOccurred"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(MODEL_PROCESS)
    MessageDescription { "WebPage_StageModeSessionDidEnd"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_StageModeSessionDidUpdate"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_StartAutoscrollAtPosition"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_StartDeferringResizeEvents"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_StartDeferringScrollEvents"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_StartInteractionWithElementContextOrPosition"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_StartObservingNowPlayingMetadata"_s, ReceiverName::WebPage, false, false },
#if ENABLE(VIDEO_PRESENTATION_MODE)
    MessageDescription { "WebPage_StartPlayingPredominantVideo"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_StartTextManipulations"_s, ReceiverName::WebPage, false, false },
#if ENABLE(IMAGE_ANALYSIS)
    MessageDescription { "WebPage_StartVisualTranslation"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_StopInteraction"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_StopLoading"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_StopLoadingDueToProcessSwap"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_StopMediaCapture"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_StopObservingNowPlayingMetadata"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_StoreSelectionForAccessibility"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_Suspend"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SuspendActiveDOMObjectsAndAnimations"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SuspendAllMediaPlayback"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SwipeAnimationDidEnd"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_SwipeAnimationDidStart"_s, ReceiverName::WebPage, false, false },
#if USE(SYSTEM_PREVIEW)
    MessageDescription { "WebPage_SystemPreviewActionTriggered"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_TakeSnapshot"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_TakeSnapshotForTargetedElement"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_TapHighlightAtPosition"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_TextInputContextsInRect"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_TextPreviewDataForActiveWritingToolsSession"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_TopDocumentSyncDataChangedInAnotherProcess"_s, ReceiverName::WebPage, false, false },
#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
    MessageDescription { "WebPage_TouchEvent"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_TouchWithIdentifierWasRemoved"_s, ReceiverName::WebPage, false, false },
#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
    MessageDescription { "WebPage_TriggerMockCaptureConfigurationChange"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_TryClose"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_TryRestoreScrollPosition"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_URLSchemeTaskDidComplete"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_URLSchemeTaskDidPerformRedirection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_URLSchemeTaskDidReceiveData"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_URLSchemeTaskDidReceiveResponse"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_URLSchemeTaskWillPerformRedirection"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UnapplyEditCommand"_s, ReceiverName::WebPage, true, false },
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPage_UpdateAttachmentAttributes"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateAttachmentIcon"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_UpdateCORSDisablingPatterns"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateCurrentModifierState"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateFrameScrollingMode"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateFrameTreeSyncData"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateOpener"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateRemotePageAccessibilityOffset"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateRenderingWithForcedRepaint"_s, ReceiverName::WebPage, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_UpdateSelectionWithDelta"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateSelectionWithExtentPoint"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateSelectionWithExtentPointAndBoundary"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateSelectionWithTouches"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_UpdateTextVisibilityForActiveWritingToolsSession"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UpdateUnderlyingTextVisibilityForTextAnimationID"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_UpdateWebsitePolicies"_s, ReceiverName::WebPage, false, false },
#if ENABLE(IMAGE_ANALYSIS)
    MessageDescription { "WebPage_UpdateWithTextRecognitionResult"_s, ReceiverName::WebPage, false, false },
#endif
#if USE(APPKIT)
    MessageDescription { "WebPage_UppercaseWord"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_UseRedirectionForCurrentNavigation"_s, ReceiverName::WebPage, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPage_UserMediaAccessWasDenied"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_UserMediaAccessWasGranted"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_ValidateCommand"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ViewWillEndLiveResize"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ViewWillStartLiveResize"_s, ReceiverName::WebPage, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPage_VoiceActivityDetected"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    MessageDescription { "WebPage_VoicesDidChange"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_WasLoadedWithDataTransferFromPrevalentResource"_s, ReceiverName::WebPage, false, false },
#if USE(UICONTEXTMENU)
    MessageDescription { "WebPage_WillBeginContextMenuInteraction"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_WillBeginWritingToolsSession"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_WillEndWritingToolsSession"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_WillInsertFinalDictationResult"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_WillStartUserTriggeredZooming"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_WindowAndViewFramesChanged"_s, ReceiverName::WebPage, false, false },
#endif
    MessageDescription { "WebPage_WindowScreenDidChange"_s, ReceiverName::WebPage, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_WritingToolsSessionDidReceiveAction"_s, ReceiverName::WebPage, false, false },
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    MessageDescription { "WebPage_ZoomPDFIn"_s, ReceiverName::WebPage, false, false },
    MessageDescription { "WebPage_ZoomPDFOut"_s, ReceiverName::WebPage, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_ClearClipboard"_s, ReceiverName::WebPasteboardProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPasteboardProxy_UpdateSupportedTypeIdentifiers"_s, ReceiverName::WebPasteboardProxy, false, false },
    MessageDescription { "WebPasteboardProxy_WriteImageToPasteboard"_s, ReceiverName::WebPasteboardProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY) || USE(LIBWPE) && !PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_WriteStringToPasteboard"_s, ReceiverName::WebPasteboardProxy, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_WriteToClipboard"_s, ReceiverName::WebPasteboardProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPasteboardProxy_WriteURLToPasteboard"_s, ReceiverName::WebPasteboardProxy, false, false },
#endif
#if PLATFORM(IOS_FAMILY) || USE(LIBWPE) && !PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_WriteWebContentToPasteboard"_s, ReceiverName::WebPasteboardProxy, false, false },
#endif
    MessageDescription { "WebPermissionControllerProxy_Query"_s, ReceiverName::WebPermissionControllerProxy, false, false },
    MessageDescription { "WebPermissionController_permissionChanged"_s, ReceiverName::WebPermissionController, false, false },
    MessageDescription { "WebProcessPool_HandleMessage"_s, ReceiverName::WebProcessPool, false, false },
#if ENABLE(GAMEPAD)
    MessageDescription { "WebProcessPool_PlayGamepadEffect"_s, ReceiverName::WebProcessPool, false, false },
#endif
    MessageDescription { "WebProcessPool_ReportWebContentCPUTime"_s, ReceiverName::WebProcessPool, false, false },
#if ENABLE(MODEL_PROCESS)
    MessageDescription { "WebProcessPool_StartedPlayingModels"_s, ReceiverName::WebProcessPool, false, false },
#endif
#if ENABLE(GAMEPAD)
    MessageDescription { "WebProcessPool_StartedUsingGamepads"_s, ReceiverName::WebProcessPool, false, false },
    MessageDescription { "WebProcessPool_StopGamepadEffects"_s, ReceiverName::WebProcessPool, false, false },
#endif
#if ENABLE(MODEL_PROCESS)
    MessageDescription { "WebProcessPool_StoppedPlayingModels"_s, ReceiverName::WebProcessPool, false, false },
#endif
#if ENABLE(GAMEPAD)
    MessageDescription { "WebProcessPool_StoppedUsingGamepads"_s, ReceiverName::WebProcessPool, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebProcessProxy_CacheMediaMIMETypes"_s, ReceiverName::WebProcessProxy, false, false },
#endif
#if ENABLE(GPU_PROCESS)
    MessageDescription { "WebProcessProxy_CreateGPUProcessConnection"_s, ReceiverName::WebProcessProxy, true, false },
#endif
#if ENABLE(MODEL_PROCESS)
    MessageDescription { "WebProcessProxy_CreateModelProcessConnection"_s, ReceiverName::WebProcessProxy, true, false },
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    MessageDescription { "WebProcessProxy_CreateServiceWorkerDebuggable"_s, ReceiverName::WebProcessProxy, false, false },
#endif
    MessageDescription { "WebProcessProxy_CreateSpeechRecognitionServer"_s, ReceiverName::WebProcessProxy, false, false },
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    MessageDescription { "WebProcessProxy_DeleteServiceWorkerDebuggable"_s, ReceiverName::WebProcessProxy, false, false },
#endif
    MessageDescription { "WebProcessProxy_DestroySpeechRecognitionServer"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_DidCollectPrewarmInformation"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_DidDestroyUserGestureToken"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_DidExceedActiveMemoryLimit"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_DidExceedCPULimit"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_DidExceedInactiveMemoryLimit"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_DidExceedMemoryFootprintThreshold"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_DidReceiveBackgroundResponsivenessPing"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_DisableSuddenTermination"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_EnableSuddenTermination"_s, ReceiverName::WebProcessProxy, false, false },
#if ENABLE(GPU_PROCESS)
    MessageDescription { "WebProcessProxy_GPUProcessConnectionDidBecomeUnresponsive"_s, ReceiverName::WebProcessProxy, false, false },
#endif
#if ENABLE(NOTIFICATION_EVENT)
    MessageDescription { "WebProcessProxy_GetNotifications"_s, ReceiverName::WebProcessProxy, false, false },
#endif
    MessageDescription { "WebProcessProxy_MemoryPressureStatusChanged"_s, ReceiverName::WebProcessProxy, false, false },
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    MessageDescription { "WebProcessProxy_SendMessageToInspector"_s, ReceiverName::WebProcessProxy, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebProcessProxy_SendMessageToWebContext"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_SendMessageToWebContextWithReply"_s, ReceiverName::WebProcessProxy, false, false },
#endif
    MessageDescription { "WebProcessProxy_SetAppBadgeFromWorker"_s, ReceiverName::WebProcessProxy, false, false },
#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
    MessageDescription { "WebProcessProxy_SetCaptionDisplayMode"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_SetCaptionLanguage"_s, ReceiverName::WebProcessProxy, false, false },
#endif
#if HAVE(DISPLAY_LINK)
    MessageDescription { "WebProcessProxy_SetDisplayLinkPreferredFramesPerSecond"_s, ReceiverName::WebProcessProxy, false, false },
#endif
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING)) || (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && !ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
    MessageDescription { "WebProcessProxy_SetupLogStream"_s, ReceiverName::WebProcessProxy, false, false },
#endif
#if HAVE(DISPLAY_LINK)
    MessageDescription { "WebProcessProxy_StartDisplayLink"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_StopDisplayLink"_s, ReceiverName::WebProcessProxy, false, false },
#endif
    MessageDescription { "WebProcessProxy_StopResponsivenessTimer"_s, ReceiverName::WebProcessProxy, false, false },
    MessageDescription { "WebProcessProxy_SystemBeep"_s, ReceiverName::WebProcessProxy, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebProcess_AccessibilityPreferencesDidChange"_s, ReceiverName::WebProcess, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebProcess_AddMockMediaDevice"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_BackgroundResponsivenessPing"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
    MessageDescription { "WebProcess_BacklightLevelDidChange"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_BindAccessibilityFrameWithData"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_ClearCachedPage"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_ClearCurrentModifierStateForTesting"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebProcess_ClearMockMediaDevices"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_ClearResourceLoadStatistics"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
    MessageDescription { "WebProcess_ColorPreferencesDidChange"_s, ReceiverName::WebProcess, false, false },
#endif
#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
    MessageDescription { "WebProcess_ConsumeAudioComponentRegistrations"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_CreateWebPage"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_DeleteAllCookies"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_DeleteWebsiteData"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_DeleteWebsiteDataForOrigin"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_DeleteWebsiteDataForOrigins"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_DestroyAutomationSessionProxy"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebProcess_DidWriteToPasteboardAsynchronously"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_DisableURLSchemeCheckInDataDetectors"_s, ReceiverName::WebProcess, false, false },
#endif
#if HAVE(DISPLAY_LINK)
    MessageDescription { "WebProcess_DisplayDidRefresh"_s, ReceiverName::WebProcess, false, false },
#endif
#if (PLATFORM(COCOA) && ENABLE(REMOTE_INSPECTOR))
    MessageDescription { "WebProcess_EnableRemoteWebInspector"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_EnsureAutomationSessionProxy"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_EstablishRemoteWorkerContextConnectionToNetworkProcess"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_FetchWebsiteData"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_FullKeyboardAccessModeChanged"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(GAMEPAD)
    MessageDescription { "WebProcess_GamepadConnected"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_GamepadDisconnected"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_GarbageCollectJavaScriptObjects"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_GetActivePagesOriginsForTesting"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(NOTIFY_BLOCKING)
    MessageDescription { "WebProcess_GetNotifyStateForTesting"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_GrantAccessToAssetServices"_s, ReceiverName::WebProcess, false, false },
#if (ENABLE(MEDIA_STREAM) && ENABLE(SANDBOX_EXTENSIONS))
    MessageDescription { "WebProcess_GrantUserMediaDeviceSandboxExtensions"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_HandleInjectedBundleMessage"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(INITIALIZE_ACCESSIBILITY_ON_DEMAND)
    MessageDescription { "WebProcess_InitializeAccessibility"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_InitializeWebProcess"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_IsJITEnabled"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_MarkIsNoLongerPrewarmed"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebProcess_OpenDirectoryCacheInvalidated"_s, ReceiverName::WebProcess, false, false },
#endif
#if ENABLE(NOTIFY_BLOCKING)
    MessageDescription { "WebProcess_PostNotification"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_PostObserverNotification"_s, ReceiverName::WebProcess, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebProcess_PowerSourceDidChange"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_PrepareToSuspend"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_PrewarmWithDomainInformation"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_ProcessDidResume"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebProcess_RegisterAdditionalFonts"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_RegisterFontMap"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_RegisterServiceWorkerClients"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_RegisterURLSchemeAsBypassingContentSecurityPolicy"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_RegisterURLSchemeAsCORSEnabled"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_RegisterURLSchemeAsCachePartitioned"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_RegisterURLSchemeAsCanDisplayOnlyIfCanRequest"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_RegisterURLSchemeAsDisplayIsolated"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_RegisterURLSchemeAsEmptyDocument"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_RegisterURLSchemeAsLocal"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(ALL_LEGACY_REGISTERED_SPECIAL_URL_SCHEMES)
    MessageDescription { "WebProcess_RegisterURLSchemeAsNoAccess"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_RegisterURLSchemeAsSecure"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(WK_WEB_EXTENSIONS)
    MessageDescription { "WebProcess_RegisterURLSchemeAsWebExtension"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_ReleaseMemory"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_ReloadExecutionContextsForOrigin"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebProcess_RemoveMockMediaDevice"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_ResetMockMediaDevices"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_RevokeAccessToAssetServices"_s, ReceiverName::WebProcess, false, false },
#if (ENABLE(MEDIA_STREAM) && ENABLE(SANDBOX_EXTENSIONS))
    MessageDescription { "WebProcess_RevokeUserMediaDeviceSandboxExtensions"_s, ReceiverName::WebProcess, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebProcess_ScrollerStylePreferenceChanged"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SeedResourceLoadStatisticsForTesting"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebProcess_SendMessageToWebProcessExtension"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SendResourceLoadStatisticsDataImmediately"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetAlwaysUsesComplexTextCodePath"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebProcess_SetAvailableInputDevices"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SetBackForwardCacheCapacity"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetCacheModel"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetDefaultRequestTimeoutInterval"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetDisableFontSubpixelAntialiasingForTesting"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetDomainRelaxationForbiddenForURLScheme"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetDomainsWithCrossPageStorageAccess"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetDomainsWithUserInteraction"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(SERVICE_CONTROLS)
    MessageDescription { "WebProcess_SetEnabledServices"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SetEnhancedAccessibility"_s, ReceiverName::WebProcess, false, false },
#if HAVE(MOUSE_DEVICE_OBSERVATION)
    MessageDescription { "WebProcess_SetHasMouseDevice"_s, ReceiverName::WebProcess, false, false },
#endif
#if HAVE(STYLUS_DEVICE_OBSERVATION)
    MessageDescription { "WebProcess_SetHasStylusDevice"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SetHasSuspendedPageProxy"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetHiddenPageDOMTimerThrottlingIncreaseLimit"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(GAMEPAD)
    MessageDescription { "WebProcess_SetInitialGamepads"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SetInjectedBundleParameter"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetInjectedBundleParameters"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetIsInProcessCache"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetJavaScriptGarbageCollectorTimerEnabled"_s, ReceiverName::WebProcess, false, false },
#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
    MessageDescription { "WebProcess_SetMediaAccessibilityPreferences"_s, ReceiverName::WebProcess, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebProcess_SetMediaMIMETypes"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SetMemoryCacheDisabled"_s, ReceiverName::WebProcess, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebProcess_SetMockMediaDeviceIsEphemeral"_s, ReceiverName::WebProcess, false, false },
#endif
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES)
    MessageDescription { "WebProcess_SetOptInCookiePartitioningEnabled"_s, ReceiverName::WebProcess, false, false },
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "WebProcess_SetResourceMonitorContentRuleList"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetResourceMonitorContentRuleListAsync"_s, ReceiverName::WebProcess, false, false },
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebProcess_SetScreenProperties"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SetTextCheckerState"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetThirdPartyCookieBlockingMode"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SetTrackingPreventionEnabled"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(GTK) && !USE(GTK4) && USE(CAIRO)
    MessageDescription { "WebProcess_SetUseSystemAppearanceForScrollbars"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_SetWebsiteDataStoreParameters"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_StartMemorySampler"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_StopMemorySampler"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SwitchFromStaticFontRegistryToUserFontRegistry"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(MAC)
    MessageDescription { "WebProcess_SystemDidWake"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SystemWillPowerOn"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_SystemWillSleep"_s, ReceiverName::WebProcess, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebProcess_UnblockServicesRequiredByAccessibility"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_UpdateDomainsWithStorageAccessQuirks"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_UpdateScriptTrackingPrivacyFilter"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebProcess_UpdateStorageAccessUserAgentStringQuirks"_s, ReceiverName::WebProcess, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebProcess_UserInterfaceIdiomDidChange"_s, ReceiverName::WebProcess, false, false },
#endif
    MessageDescription { "WebProcess_UserPreferredLanguagesChanged"_s, ReceiverName::WebProcess, false, false },
    MessageDescription { "WebRTCMonitor_NetworksChanged"_s, ReceiverName::WebRTCMonitor, false, false },
    MessageDescription { "WebRTCResolver_ResolvedAddressError"_s, ReceiverName::WebRTCResolver, false, false },
    MessageDescription { "WebRTCResolver_SetResolvedAddress"_s, ReceiverName::WebRTCResolver, false, false },
#if ENABLE(CONTENT_FILTERING)
    MessageDescription { "WebResourceLoader_ContentFilterDidBlockLoad"_s, ReceiverName::WebResourceLoader, false, false },
#endif
    MessageDescription { "WebResourceLoader_DidBlockAuthenticationChallenge"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_DidFailResourceLoad"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_DidFailServiceWorkerLoad"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_DidFinishResourceLoad"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_DidReceiveData"_s, ReceiverName::WebResourceLoader, false, false },
#if ENABLE(SHAREABLE_RESOURCE)
    MessageDescription { "WebResourceLoader_DidReceiveResource"_s, ReceiverName::WebResourceLoader, false, false },
#endif
    MessageDescription { "WebResourceLoader_DidReceiveResponse"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_DidSendData"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_ServiceWorkerDidNotHandle"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_SetWorkerStart"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_StopLoadingAfterXFrameOptionsOrContentSecurityPolicyDenied"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_UpdateResultingClientIdentifier"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebResourceLoader_WillSendRequest"_s, ReceiverName::WebResourceLoader, false, false },
    MessageDescription { "WebSWClientConnection_FireUpdateFoundEvent"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_FocusServiceWorkerClient"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_JobRejectedInServer"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_NotifyClientsOfControllerChange"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_NotifyRecordResponseBodyChunk"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_NotifyRecordResponseBodyEnd"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_PostMessageToServiceWorkerClient"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_RegistrationJobResolvedInServer"_s, ReceiverName::WebSWClientConnection, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "WebSWClientConnection_ReportNetworkUsageToWorkerClient"_s, ReceiverName::WebSWClientConnection, false, false },
#endif
    MessageDescription { "WebSWClientConnection_SetRegistrationLastUpdateTime"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_SetRegistrationUpdateViaCache"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_SetSWOriginTableIsImported"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_SetSWOriginTableSharedMemory"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_SetServiceWorkerClientIsControlled"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_StartScriptFetchForServer"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_UpdateBackgroundFetchRegistration"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_UpdateRegistrationState"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWClientConnection_UpdateWorkerState"_s, ReceiverName::WebSWClientConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_CancelFetch"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_Close"_s, ReceiverName::WebSWContextManagerConnection, false, false },
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    MessageDescription { "WebSWContextManagerConnection_ConnectToInspector"_s, ReceiverName::WebSWContextManagerConnection, false, false },
#endif
    MessageDescription { "WebSWContextManagerConnection_ContinueDidReceiveFetchResponse"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_ConvertFetchToDownload"_s, ReceiverName::WebSWContextManagerConnection, false, false },
#if ENABLE(SHAREABLE_RESOURCE) && PLATFORM(COCOA)
    MessageDescription { "WebSWContextManagerConnection_DidSaveScriptsToDisk"_s, ReceiverName::WebSWContextManagerConnection, false, false },
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    MessageDescription { "WebSWContextManagerConnection_DisconnectFromInspector"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_DispatchMessageFromInspector"_s, ReceiverName::WebSWContextManagerConnection, false, false },
#endif
    MessageDescription { "WebSWContextManagerConnection_FireActivateEvent"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_FireBackgroundFetchClickEvent"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_FireBackgroundFetchEvent"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_FireInstallEvent"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_FireNotificationEvent"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_FirePushEvent"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_FireUpdateFoundEvent"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_InstallServiceWorker"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_NavigationPreloadFailed"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_NavigationPreloadIsReady"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_PostMessageToServiceWorker"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_SetInspectable"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_SetRegistrationLastUpdateTime"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_SetRegistrationUpdateViaCache"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_SetThrottleState"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_SetUserAgent"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_StartFetch"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_TerminateWorker"_s, ReceiverName::WebSWContextManagerConnection, false, false },
#if ((ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)) && ENABLE(REMOTE_INSPECTOR_SERVICE_WORKER_AUTO_INSPECTION))
    MessageDescription { "WebSWContextManagerConnection_UnpauseServiceWorkerForRejectedAutomaticInspection"_s, ReceiverName::WebSWContextManagerConnection, false, false },
#endif
    MessageDescription { "WebSWContextManagerConnection_UpdateAppInitiatedValue"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_UpdatePreferencesStore"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_UpdateRegistrationState"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWContextManagerConnection_UpdateWorkerState"_s, ReceiverName::WebSWContextManagerConnection, false, false },
    MessageDescription { "WebSWServerConnection_AbortBackgroundFetch"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_AddCookieChangeSubscriptions"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_AddRoutes"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_AddServiceWorkerRegistrationInServer"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_BackgroundFetchIdentifiers"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_BackgroundFetchInformation"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_CookieChangeSubscriptions"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_DidResolveRegistrationPromise"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_DisableNavigationPreload"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_EnableNavigationPreload"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_FinishFetchingScriptInServer"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_GetNavigationPreloadState"_s, ReceiverName::WebSWServerConnection, false, false },
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    MessageDescription { "WebSWServerConnection_GetNotifications"_s, ReceiverName::WebSWServerConnection, false, false },
#endif
    MessageDescription { "WebSWServerConnection_GetPushPermissionState"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_GetPushSubscription"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_GetRegistrations"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_MatchBackgroundFetch"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_MatchRegistration"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_PostMessageToServiceWorker"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_RegisterServiceWorkerClient"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_RemoveCookieChangeSubscriptions"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_RemoveServiceWorkerRegistrationInServer"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_RetrieveRecordResponse"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_RetrieveRecordResponseBody"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_ScheduleJobInServer"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_ScheduleUnregisterJobInServer"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_SetNavigationPreloadHeaderValue"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_SetThrottleState"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_StartBackgroundFetch"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_StoreRegistrationsOnDisk"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_SubscribeToPushService"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_TerminateWorkerFromClient"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_UnregisterServiceWorkerClient"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_UnsubscribeFromPushService"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_WhenRegistrationReady"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerConnection_WhenServiceWorkerIsTerminatedForTesting"_s, ReceiverName::WebSWServerConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_Claim"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_DidFailHeartBeatCheck"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_DidFinishActivation"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_DidFinishInstall"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_FindClientByVisibleIdentifier"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_Focus"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_MatchAll"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_Navigate"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_OpenWindow"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_PostMessageToServiceWorkerClient"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_ReportConsoleMessage"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_ScriptContextFailedToStart"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_ScriptContextStarted"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_SetAsInspected"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_SetScriptResource"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_SetServiceWorkerHasPendingEvents"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_SkipWaiting"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebSWServerToContextConnection_WorkerTerminated"_s, ReceiverName::WebSWServerToContextConnection, false, false },
    MessageDescription { "WebScreenOrientationManagerProxy_Lock"_s, ReceiverName::WebScreenOrientationManagerProxy, false, false },
    MessageDescription { "WebScreenOrientationManagerProxy_SetShouldSendChangeNotification"_s, ReceiverName::WebScreenOrientationManagerProxy, false, false },
    MessageDescription { "WebScreenOrientationManagerProxy_Unlock"_s, ReceiverName::WebScreenOrientationManagerProxy, false, false },
    MessageDescription { "WebScreenOrientationManager_OrientationDidChange"_s, ReceiverName::WebScreenOrientationManager, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_Close"_s, ReceiverName::WebSharedWorkerContextManagerConnection, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_LaunchSharedWorker"_s, ReceiverName::WebSharedWorkerContextManagerConnection, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_PostConnectEvent"_s, ReceiverName::WebSharedWorkerContextManagerConnection, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_ResumeSharedWorker"_s, ReceiverName::WebSharedWorkerContextManagerConnection, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_SetUserAgent"_s, ReceiverName::WebSharedWorkerContextManagerConnection, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_SuspendSharedWorker"_s, ReceiverName::WebSharedWorkerContextManagerConnection, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_TerminateSharedWorker"_s, ReceiverName::WebSharedWorkerContextManagerConnection, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_UpdatePreferencesStore"_s, ReceiverName::WebSharedWorkerContextManagerConnection, false, false },
    MessageDescription { "WebSharedWorkerObjectConnection_FetchScriptInClient"_s, ReceiverName::WebSharedWorkerObjectConnection, false, false },
    MessageDescription { "WebSharedWorkerObjectConnection_NotifyWorkerObjectOfLoadCompletion"_s, ReceiverName::WebSharedWorkerObjectConnection, false, false },
    MessageDescription { "WebSharedWorkerObjectConnection_PostErrorToWorkerObject"_s, ReceiverName::WebSharedWorkerObjectConnection, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "WebSharedWorkerObjectConnection_ReportNetworkUsageToWorkerObject"_s, ReceiverName::WebSharedWorkerObjectConnection, false, false },
#endif
    MessageDescription { "WebSharedWorkerServerConnection_RequestSharedWorker"_s, ReceiverName::WebSharedWorkerServerConnection, false, false },
    MessageDescription { "WebSharedWorkerServerConnection_ResumeForBackForwardCache"_s, ReceiverName::WebSharedWorkerServerConnection, false, false },
    MessageDescription { "WebSharedWorkerServerConnection_SharedWorkerObjectIsGoingAway"_s, ReceiverName::WebSharedWorkerServerConnection, false, false },
    MessageDescription { "WebSharedWorkerServerConnection_SuspendForBackForwardCache"_s, ReceiverName::WebSharedWorkerServerConnection, false, false },
    MessageDescription { "WebSharedWorkerServerToContextConnection_PostErrorToWorkerObject"_s, ReceiverName::WebSharedWorkerServerToContextConnection, false, false },
    MessageDescription { "WebSharedWorkerServerToContextConnection_SharedWorkerTerminated"_s, ReceiverName::WebSharedWorkerServerToContextConnection, false, false },
    MessageDescription { "WebSocketChannel_DidClose"_s, ReceiverName::WebSocketChannel, false, false },
    MessageDescription { "WebSocketChannel_DidConnect"_s, ReceiverName::WebSocketChannel, false, false },
    MessageDescription { "WebSocketChannel_DidReceiveBinaryData"_s, ReceiverName::WebSocketChannel, false, false },
    MessageDescription { "WebSocketChannel_DidReceiveHandshakeResponse"_s, ReceiverName::WebSocketChannel, false, false },
    MessageDescription { "WebSocketChannel_DidReceiveMessageError"_s, ReceiverName::WebSocketChannel, false, false },
    MessageDescription { "WebSocketChannel_DidReceiveText"_s, ReceiverName::WebSocketChannel, false, false },
    MessageDescription { "WebSocketChannel_DidSendHandshakeRequest"_s, ReceiverName::WebSocketChannel, false, false },
    MessageDescription { "WebSpeechRecognitionConnection_DidReceiveUpdate"_s, ReceiverName::WebSpeechRecognitionConnection, false, false },
    MessageDescription { "WebTransportSession_ReceiveBidirectionalStream"_s, ReceiverName::WebTransportSession, false, false },
    MessageDescription { "WebTransportSession_ReceiveDatagram"_s, ReceiverName::WebTransportSession, false, false },
    MessageDescription { "WebTransportSession_ReceiveIncomingUnidirectionalStream"_s, ReceiverName::WebTransportSession, false, false },
    MessageDescription { "WebTransportSession_StreamReceiveBytes"_s, ReceiverName::WebTransportSession, false, false },
    MessageDescription { "WebUserContentControllerProxy_DidPostMessage"_s, ReceiverName::WebUserContentControllerProxy, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "WebUserContentController_AddContentRuleLists"_s, ReceiverName::WebUserContentController, false, false },
#endif
    MessageDescription { "WebUserContentController_AddContentWorlds"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_AddUserScriptMessageHandlers"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_AddUserScripts"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_AddUserStyleSheets"_s, ReceiverName::WebUserContentController, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "WebUserContentController_RemoveAllContentRuleLists"_s, ReceiverName::WebUserContentController, false, false },
#endif
    MessageDescription { "WebUserContentController_RemoveAllUserScriptMessageHandlers"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_RemoveAllUserScriptMessageHandlersForWorlds"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_RemoveAllUserScripts"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_RemoveAllUserStyleSheets"_s, ReceiverName::WebUserContentController, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "WebUserContentController_RemoveContentRuleList"_s, ReceiverName::WebUserContentController, false, false },
#endif
    MessageDescription { "WebUserContentController_RemoveContentWorlds"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_RemoveUserScript"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_RemoveUserScriptMessageHandler"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "WebUserContentController_RemoveUserStyleSheet"_s, ReceiverName::WebUserContentController, false, false },
    MessageDescription { "CancelSyncMessageReply"_s, ReceiverName::IPC, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "InitializeConnection"_s, ReceiverName::IPC, false, false },
#endif
    MessageDescription { "LegacySessionState"_s, ReceiverName::IPC, false, false },
    MessageDescription { "ProcessOutOfStreamMessage"_s, ReceiverName::IPC, false, false },
    MessageDescription { "SetStreamDestinationID"_s, ReceiverName::IPC, false, false },
    MessageDescription { "SyncMessageReply"_s, ReceiverName::IPC, false, false },
    MessageDescription { "AuxiliaryProcess_MainThreadPingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "DigitalCredentialsCoordinator_ProvideRawDigitalCredentialRequestsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "DownloadProxy_DecideDestinationWithSuggestedFilenameReply"_s, ReceiverName::AsyncReply, false, false },
#if HAVE(MODERN_DOWNLOADPROGRESS)
    MessageDescription { "DownloadProxy_DidReceivePlaceholderURLReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "DownloadProxy_WillSendRequestReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA) || PLATFORM(GTK)
    MessageDescription { "DrawingArea_CommitTransientZoomReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "DrawingArea_DispatchAfterEnsuringDrawingReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "DrawingArea_SetDeviceScaleFactorReply"_s, ReceiverName::AsyncReply, false, false },
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER) || PLATFORM(COCOA)
    MessageDescription { "DrawingArea_UpdateGeometryReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(MAC_GESTURE_EVENTS)
    MessageDescription { "EventDispatcher_GestureEventReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(IOS_TOUCH_EVENTS)
    MessageDescription { "EventDispatcher_TouchEventReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ROUTING_ARBITRATION)
    MessageDescription { "GPUProcessConnection_BeginRoutingArbitrationWithCategoryReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if (ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY))
    MessageDescription { "GPUProcessProxy_StatusBarWasTappedReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "GPUProcess_CreateGPUConnectionToWebProcessReply"_s, ReceiverName::AsyncReply, false, false },
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    MessageDescription { "GPUProcess_CreateMemoryAttributionIDForTaskReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "GPUProcess_InitializeGPUProcessReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "GPUProcess_PostWillTakeSnapshotNotificationReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "GPUProcess_PrepareToSuspendReply"_s, ReceiverName::AsyncReply, false, false },
#if HAVE(SCREEN_CAPTURE_KIT)
    MessageDescription { "GPUProcess_PromptForGetDisplayMediaReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(VIDEO)
    MessageDescription { "GPUProcess_RequestBitmapImageForCurrentTimeReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    MessageDescription { "GPUProcess_RequestSharedSimulationConnectionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "GPUProcess_SharedPreferencesForWebProcessDidChangeReply"_s, ReceiverName::AsyncReply, false, false },
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    MessageDescription { "GPUProcess_UnregisterMemoryAttributionIDReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "GPUProcess_UpdateCaptureAccessReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "GPUProcess_WebProcessConnectionCountForTestingReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WEBXR)
    MessageDescription { "GPUProcess_WebXRPromptAcceptedReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "IPCStreamTester_AsyncPingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "IPCTesterReceiver_AsyncMessageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "IPCTester_AsyncOptionalExceptionDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "IPCTester_AsyncPingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_CreateDecoderReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_CreateEncoderReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_DecodeFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_EncodeFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_FlushDecoderReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_FlushEncoderReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "LibWebRTCCodecsProxy_SetEncodeRatesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "MediaPlayerPrivateRemote_CommitAllTransactionsReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "MediaPlayerPrivateRemote_GetRawCookiesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "MediaPlayerPrivateRemote_SendH2PingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "MediaSourcePrivateRemoteMessageReceiver_ProxySeekToTimeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "MediaSourcePrivateRemoteMessageReceiver_ProxyWaitForTargetReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(VISION) && ENABLE(GPU_PROCESS)
    MessageDescription { "ModelProcessProxy_RequestSharedSimulationConnectionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "ModelProcess_CreateModelConnectionToWebProcessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "ModelProcess_InitializeModelProcessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "ModelProcess_ModelPlayerCountForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "ModelProcess_PrepareToSuspendReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "ModelProcess_SharedPreferencesForWebProcessDidChangeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "ModelProcess_WebProcessConnectionCountForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkBroadcastChannelRegistry_PostMessageReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WEB_RTC)
    MessageDescription { "NetworkConnectionToWebProcess_ConnectToRTCDataChannelRemoteSourceReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_CookiesEnabledReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CookiesForDOMAsyncReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_CreateRTCProviderReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_DeleteCookieReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_EstablishSWContextConnectionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_EstablishSharedWorkerContextConnectionReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(MAC)
    MessageDescription { "NetworkConnectionToWebProcess_GetProcessDisplayNameReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_HasStorageAccessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_InitializeWebTransportSessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_IsLoggedInReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_IsResourceLoadFinishedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_LoadImageForDecodingReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(DECLARATIVE_WEB_PUSH)
    MessageDescription { "NetworkConnectionToWebProcess_NavigatorGetPushPermissionStateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_NavigatorGetPushSubscriptionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_NavigatorSubscribeToPushServiceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_NavigatorUnsubscribeFromPushServiceReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_PingPongForServiceWorkersReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RegisterBlobPathForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_RequestStorageAccessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_ResourceLoadStatisticsUpdatedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SendH2PingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetCookieFromDOMAsyncReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_SetLoginStatusReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "NetworkConnectionToWebProcess_ShouldOffloadIFrameForHostReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_StorageAccessQuirkForTopFrameDomainReply"_s, ReceiverName::AsyncReply, false, false },
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    MessageDescription { "NetworkConnectionToWebProcess_SubscribeToCookieChangeNotificationsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkConnectionToWebProcess_TakeAllMessagesForPortReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkConnectionToWebProcess_WriteBlobsToTemporaryFilesForIndexedDBReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkMDNSRegister_RegisterMDNSNameReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WEB_RTC)
    MessageDescription { "NetworkProcessConnection_ConnectToRTCDataChannelRemoteSourceReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcessProxy_DataTaskDidReceiveResponseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_DataTaskReceivedChallengeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_DataTaskWillPerformHTTPRedirectionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_DeleteWebsiteDataInUIProcessForRegistrableDomainsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_DeleteWebsiteDataInWebProcessesForOriginReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_EstablishRemoteWorkerContextConnectionToNetworkProcessReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(APP_BOUND_DOMAINS)
    MessageDescription { "NetworkProcessProxy_GetAppBoundDomainsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI)
    MessageDescription { "NetworkProcessProxy_GetPaymentCoordinatorEmbeddingUserAgentReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI_USES_SCENE)
    MessageDescription { "NetworkProcessProxy_GetWindowSceneAndBundleIdentifierForPaymentPresentationReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcessProxy_NavigateServiceWorkerClientReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_OpenWindowFromServiceWorkerReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_ReloadExecutionContextsForOriginReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_RequestBackgroundFetchPermissionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_RequestStorageAccessConfirmReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_SetDomainsWithCrossPageStorageAccessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcessProxy_TriggerBrowsingContextGroupSwitchForNavigationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_AbortBackgroundFetchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_AddAllowedFirstPartyForCookiesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_AllowFileAccessFromWebProcessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_AllowFilesAccessFromWebProcessReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "NetworkProcess_AppPrivacyReportTestingDataReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcess_CancelDataTaskReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_CancelDownloadReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(APP_BOUND_DOMAINS)
    MessageDescription { "NetworkProcess_ClearAppBoundSessionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "NetworkProcess_ClearAppPrivacyReportTestingDataReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcess_ClearBundleIdentifierReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ClearPrevalentResourceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ClearPrivateClickMeasurementReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
    MessageDescription { "NetworkProcess_ClearServiceWorkerEntitlementOverrideReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcess_ClearUserInteractionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ClickBackgroundFetchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_CloseITPDatabaseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ClosePCMDatabaseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_CountNonDefaultSessionSetsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_CreateNetworkConnectionToWebProcessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_DataTaskWithRequestReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_DeleteCookiesForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_DeleteWebsiteDataForOriginsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_DeleteWebsiteDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_DestroySessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_DomainIDExistsInDatabaseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_DumpPrivateClickMeasurementReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_DumpResourceLoadStatisticsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_EnsureSessionWithDataStoreIdentifierRemovedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_FetchLocalStorageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_FetchSessionStorageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_FetchWebsiteDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_FlushCookiesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_GetAllBackgroundFetchIdentifiersReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_GetAllStorageAccessEntriesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_GetAppBadgeForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_GetBackgroundFetchStateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_GetPendingPushMessageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_GetPendingPushMessagesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_GetResourceLoadStatisticsDataSummaryReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_GrantStorageAccessForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_HadUserInteractionReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(APP_BOUND_DOMAINS)
    MessageDescription { "NetworkProcess_HasAppBoundSessionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcess_HasIsolatedSessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_HasLocalStorageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_HasPushSubscriptionForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_InitializeNetworkProcessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_InsertExpiredStatisticForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_IsGrandfatheredReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_IsPrevalentResourceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_IsRegisteredAsRedirectingToReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_IsRegisteredAsSubFrameUnderReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_IsRegisteredAsSubresourceUnderReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_IsRelationshipOnlyInDatabaseOnceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_IsResourceLoadStatisticsEphemeralReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_IsVeryPrevalentResourceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_LogUserInteractionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_MarkAttributedPrivateClickMeasurementsAsExpiredForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_MarkPrivateClickMeasurementsAsExpiredForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_MergeStatisticForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_PauseBackgroundFetchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_PrepareToSuspendReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ProcessNotificationEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ProcessPushMessageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_RemovePushSubscriptionsForOriginReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_RenameOriginInWebsiteDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ResetCacheMaxAgeCapForPrevalentResourcesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ResetCrossSiteLoadsWithLinkDecorationForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ResetParametersToDefaultValuesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ResetQuotaReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "NetworkProcess_ResetResourceMonitorThrottlerForTestingReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcess_ResetStoragePersistedStateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_RestoreLocalStorageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_RestoreSessionStorageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ResumeBackgroundFetchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_RunningOrTerminatingServiceWorkerCountForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ScheduleClearInMemoryAndPersistentReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ScheduleCookieBlockingUpdateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_ScheduleStatisticsAndDataRecordsProcessingReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(APP_BOUND_DOMAINS)
    MessageDescription { "NetworkProcess_SetAppBoundDomainsForResourceLoadStatisticsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "NetworkProcess_SetBackupExclusionPeriodForTestingReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcess_SetCacheMaxAgeCapForPrevalentResourcesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetCrossSiteLoadWithLinkDecorationForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetFirstPartyHostCNAMEDomainForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetFirstPartyWebsiteDataRemovalModeForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetGrandfatheredReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetGrandfatheringTimeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetIsRunningResourceLoadStatisticsTestReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetLastSeenReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(MANAGED_DOMAINS)
    MessageDescription { "NetworkProcess_SetManagedDomainsForResourceLoadStatisticsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkProcess_SetMaxStatisticsEntriesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetMinimumTimeBetweenDataRecordsRemovalReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetOriginQuotaRatioEnabledForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPCMFraudPreventionValuesForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPrevalentResourceForDebugModeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPrevalentResourceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementAppBundleIDForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementAttributionReportURLsForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementEphemeralMeasurementForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementOverrideTimerForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementTokenPublicKeyURLForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPrivateClickMeasurementTokenSignatureURLForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPruneEntriesDownToReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetPushAndNotificationsEnabledForOriginReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetResourceLoadStatisticsDebugModeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetResourceLoadStatisticsTimeAdvanceForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetShouldClassifyResourcesBeforeDataRecordsRemovalReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetShouldDowngradeReferrerForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetShouldEnbleSameSiteStrictEnforcementForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetSubframeUnderTopFrameDomainReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetSubresourceUnderTopFrameDomainReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetSubresourceUniqueRedirectFromReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetSubresourceUniqueRedirectToReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetThirdPartyCNAMEDomainForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetThirdPartyCookieBlockingModeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetTimeToLiveUserInteractionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetToSameSiteStrictCookiesForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetTopFrameUniqueRedirectFromReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetTopFrameUniqueRedirectToReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SetVeryPrevalentResourceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SharedPreferencesForWebProcessDidChangeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SimulatePrivateClickMeasurementSessionRestartReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_StatisticsDatabaseHasAllTablesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_StoreServiceWorkerRegistrationsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_SyncLocalStorageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_TerminateIdleServiceWorkersReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_UpdateBundleIdentifierReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_UpdatePrevalentDomainsToBlockCookiesForReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkProcess_WebsiteDataOriginDirectoryForTestingReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "NetworkRTCProvider_GetInterfaceNameReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "NetworkSocketChannel_SendDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkSocketChannel_SendStringReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageAllCachesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageClearMemoryRepresentationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageOpenCacheReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CacheStoragePutRecordsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageRemoveCacheReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageRemoveRecordsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageRepresentationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CacheStorageRetrieveRecordsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_ClearReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CloseSyncAccessHandleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CloseWritableReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_ConnectToStorageAreaReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CreateSyncAccessHandleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_CreateWritableReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_EstimateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_ExecuteCommandForWritableReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_FileSystemGetDirectoryReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_GetDirectoryHandleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_GetFileHandleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_GetFileReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_GetHandleNamesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_GetHandleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_IsSameEntryReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_MoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_PersistReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_PersistedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_RemoveEntryReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_RemoveItemReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_RequestNewCapacityForSyncAccessHandleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_ResolveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkStorageManager_SetItemReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkTransportSession_CreateBidirectionalStreamReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkTransportSession_CreateOutgoingUnidirectionalStreamReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkTransportSession_SendDatagramReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NetworkTransportSession_StreamSendBytesReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    MessageDescription { "NotificationManagerMessageHandler_GetPermissionStateReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(NOTIFICATIONS)
    MessageDescription { "NotificationManagerMessageHandler_RequestPermissionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "NotificationManagerMessageHandler_ShowNotificationReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "PlatformXRSystem_EnumerateImmersiveXRDevicesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PlatformXRSystem_RequestFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PlatformXRSystem_RequestPermissionOnSessionFeaturesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_GetAppBadgeForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_GetNotificationsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_GetPendingPushMessageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_GetPendingPushMessagesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_GetPushPermissionStateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_GetPushSubscriptionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_GetPushTopicsForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_IncrementSilentPushCountReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_InjectEncryptedPushMessageForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_InjectPushMessageForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_RemoveAllPushSubscriptionsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_RemovePushSubscriptionsForOriginReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_RequestPushPermissionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_SetProtocolVersionForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_SetPublicTokenForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_SetPushAndNotificationsEnabledForOriginReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_SetServiceWorkerIsBeingInspectedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_ShowNotificationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_SubscribeToPushServiceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "PushClientConnection_UnsubscribeFromPushServiceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteAudioDestinationManager_CreateAudioDestinationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteAudioDestinationManager_StartAudioDestinationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteAudioDestinationManager_StopAudioDestinationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteAudioMediaStreamTrackRendererInternalUnitManager_CreateUnitReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteBarcodeDetector_DetectReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteBuffer_CopyReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteBuffer_MapAsyncReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteCDMInstanceProxy_InitializeWithConfigurationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteCDMInstanceProxy_SetServerCertificateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_CloseSessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_LoadSessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_RemoveSessionDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_RequestLicenseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteCDMInstanceSessionProxy_UpdateLicenseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteCDMProxy_GetSupportedConfigurationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteDevice_CreateComputePipelineAsyncReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteDevice_CreateRenderPipelineAsyncReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteDevice_PopErrorScopeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteDevice_ResolveDeviceLostPromiseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteDevice_ResolveUncapturedErrorEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteFaceDetector_DetectReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteLegacyCDMFactoryProxy_RemoveSessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaEngineConfigurationFactoryProxy_CreateDecodingConfigurationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaEngineConfigurationFactoryProxy_CreateEncodingConfigurationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_DidLoadingProgressReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(MEDIA_SOURCE)
    MessageDescription { "RemoteMediaPlayerProxy_LoadMediaSourceReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_LoadReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_PerformTaskAtTimeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaPlayerProxy_RequestHostingContextReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaResourceManager_DataReceivedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaResourceManager_RedirectReceivedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaResourceManager_ResponseReceivedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_CoordinatePauseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_CoordinatePlayReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_CoordinateSeekToReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_CoordinateSetTrackReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinatorProxy_JoinReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_PauseSessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_PlaySessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_SeekSessionToTimeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteMediaSessionCoordinator_SetSessionTrackReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteQueue_OnSubmittedWorkDoneReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteQueue_WriteBufferReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteQueue_WriteTextureReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteRenderingBackend_GetImageBufferResourceLimitsForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteRenderingBackend_GetRemoteBarcodeDetectorSupportedFormatsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteSampleBufferDisplayLayerManager_CreateLayerReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteShaderModule_CompilationInfoReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteSourceBufferProxy_AppendReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteSourceBufferProxy_BufferedSamplesForTrackIdReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteSourceBufferProxy_ComputeSeekTimeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteSourceBufferProxy_EnqueuedSamplesForTrackIDReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteSourceBufferProxy_RemoveCodedFramesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteSourceBufferProxy_SetMaximumBufferSizeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteTextDetector_DetectReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteWCLayerTreeHost_UpdateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_LoadReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "RemoteWebInspectorUIProxy_PickColorFromScreenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateBufferedChangedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidAttachReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveInitializationSegmentReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDurationChangedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_ComputeElementLayoutReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_DeleteCookieReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_EvaluateJavaScriptFunctionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_FocusFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_GetComputedLabelReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_GetComputedRoleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_GetCookiesForFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_ResolveChildFrameWithNameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_ResolveChildFrameWithNodeHandleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_ResolveChildFrameWithOrdinalReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_ResolveParentFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_SelectOptionElementReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_SetFilesForInputFileUploadReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_SnapshotRectForScreenshotReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebAutomationSessionProxy_TakeScreenshotReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebBroadcastChannelRegistry_PostMessageToRemoteReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_DeleteAllCookiesModifiedSinceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_DeleteAllCookiesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_DeleteCookieReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_DeleteCookiesForHostnamesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_GetAllCookiesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_GetCookiesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_GetHTTPCookieAcceptPolicyReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_GetHostnamesWithCookiesReply"_s, ReceiverName::AsyncReply, false, false },
#if USE(SOUP)
    MessageDescription { "WebCookieManager_ReplaceCookiesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebCookieManager_SetCookieReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_SetCookiesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebCookieManager_SetHTTPCookieAcceptPolicyReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchRuntimeConnectEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContextProxy_DispatchRuntimeMessageEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionGetBadgeTextReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionGetEnabledReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionGetPopupReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionGetTitleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionOpenPopupReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionSetBadgeTextReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionSetEnabledReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionSetIconReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionSetPopupReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ActionSetTitleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_AlarmsClearAllReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_AlarmsClearReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_AlarmsGetAllReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_AlarmsGetReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    MessageDescription { "WebExtensionContext_BookmarksCreateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetChildrenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetRecentReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetSubTreeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksGetTreeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksMoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksRemoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksRemoveTreeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksSearchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_BookmarksUpdateReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebExtensionContext_CommandsGetAllReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_CookiesGetAllCookieStoresReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_CookiesGetAllReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_CookiesGetReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_CookiesRemoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_CookiesSetReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestDisplayActionCountAsBadgeTextReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestGetDynamicRulesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestGetEnabledRulesetsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestGetMatchedRulesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestGetSessionRulesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestIncrementActionCountReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestUpdateDynamicRulesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestUpdateEnabledRulesetsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DeclarativeNetRequestUpdateSessionRulesReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(INSPECTOR_EXTENSIONS)
    MessageDescription { "WebExtensionContext_DevToolsInspectedWindowEvalReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_DevToolsPanelsCreateReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebExtensionContext_ExtensionIsAllowedIncognitoAccessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_MenusCreateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_MenusRemoveAllReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_MenusRemoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_MenusUpdateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_PermissionsContainsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_PermissionsGetAllReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_PermissionsRemoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_PermissionsRequestReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_RuntimeConnectNativeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_RuntimeConnectReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_RuntimeGetBackgroundPageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_RuntimeOpenOptionsPageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_RuntimeSendMessageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_RuntimeSendNativeMessageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_RuntimeWebPageConnectReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_RuntimeWebPageSendMessageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ScriptingExecuteScriptReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ScriptingGetRegisteredScriptsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ScriptingInsertCSSReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ScriptingRegisterContentScriptsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ScriptingRemoveCSSReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ScriptingUnregisterContentScriptsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_ScriptingUpdateRegisteredScriptsReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    MessageDescription { "WebExtensionContext_SidebarCloseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarGetActionClickBehaviorReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarGetOptionsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarGetTitleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarIsOpenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarOpenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarSetActionClickBehaviorReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarSetIconReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarSetOptionsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarSetTitleReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_SidebarToggleReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebExtensionContext_StorageClearReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_StorageGetBytesInUseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_StorageGetKeysReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_StorageGetReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_StorageRemoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_StorageSetAccessLevelReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_StorageSetReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsCaptureVisibleTabReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsConnectReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsCreateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsDetectLanguageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsDuplicateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsExecuteScriptReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsGetCurrentReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsGetReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsGetZoomReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsGoBackReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsGoForwardReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsInsertCSSReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsQueryReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsReloadReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsRemoveCSSReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsRemoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsSendMessageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsSetZoomReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsToggleReaderModeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_TabsUpdateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_WebNavigationGetAllFramesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_WebNavigationGetFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_WindowsCreateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_WindowsGetAllReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_WindowsGetLastFocusedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_WindowsGetReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_WindowsRemoveReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebExtensionContext_WindowsUpdateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFrame_FindFocusableElementDescendingIntoRemoteFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFrame_GetFrameInfoReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFullScreenManagerProxy_BeganEnterFullScreenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFullScreenManagerProxy_BeganExitFullScreenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFullScreenManagerProxy_EnterFullScreenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFullScreenManagerProxy_ExitFullScreenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFullScreenManager_EnterFullScreenForOwnerElementsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFullScreenManager_ExitFullScreenInMainFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebFullScreenManager_RequestRestoreFullScreenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebInspectorUIProxy_LoadReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebInspectorUIProxy_PickColorFromScreenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebInspector_ShowReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebLockRegistryProxy_AbortLockRequestReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebLockRegistryProxy_SnapshotReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPageProxy_AddTextAnimationForAnimationIDWithCompletionHandlerReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if USE(SYSTEM_PREVIEW)
    MessageDescription { "WebPageProxy_BeginSystemPreviewReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPageProxy_DecidePolicyForNavigationActionAsyncReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_DecidePolicyForNewWindowActionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_DecidePolicyForResponseReply"_s, ReceiverName::AsyncReply, false, false },
#if HAVE(DIGITAL_CREDENTIALS_UI)
    MessageDescription { "WebPageProxy_DismissDigitalCredentialsPickerReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPageProxy_DocumentURLForConsoleLogReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPageProxy_EnumerateMediaDevicesForFrameReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPageProxy_FocusFromServiceWorkerReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_HandleMessageWithAsyncReplyReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_IsPotentialTapInProgressReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    MessageDescription { "WebPageProxy_ModelElementAnimationCurrentTimeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementAnimationDurationReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    MessageDescription { "WebPageProxy_ModelElementCreateRemotePreviewReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    MessageDescription { "WebPageProxy_ModelElementGetCameraReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementHasAudioReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementIsLoopingAnimationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementIsMutedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementIsPlayingAnimationReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    MessageDescription { "WebPageProxy_ModelElementLoadRemotePreviewReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    MessageDescription { "WebPageProxy_ModelElementSetAnimationCurrentTimeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementSetAnimationIsPlayingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementSetCameraReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementSetIsLoopingAnimationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelElementSetIsMutedReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    MessageDescription { "WebPageProxy_ModelElementSizeDidChangeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ModelInlinePreviewUUIDsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPageProxy_RequestCookieConsentReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_RequestNotificationPermissionReply"_s, ReceiverName::AsyncReply, false, false },
#if USE(QUICK_LOOK)
    MessageDescription { "WebPageProxy_RequestPasswordForQuickLookDocumentInMainFrameReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(POINTER_LOCK)
    MessageDescription { "WebPageProxy_RequestPointerLockReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_RequestPointerUnlockReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(IMAGE_ANALYSIS)
    MessageDescription { "WebPageProxy_RequestTextRecognitionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPageProxy_ResolveAccessibilityHitTestForTestingReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPageProxy_SendMessageToWebViewWithReplyReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(DEVICE_ORIENTATION)
    MessageDescription { "WebPageProxy_ShouldAllowDeviceOrientationAndMotionAccessReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPageProxy_ShouldGoToBackForwardListItemReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_ShowContactPickerReply"_s, ReceiverName::AsyncReply, false, false },
#if HAVE(DIGITAL_CREDENTIALS_UI)
    MessageDescription { "WebPageProxy_ShowDigitalCredentialsPickerReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(GTK)
    MessageDescription { "WebPageProxy_ShowEmojiPickerReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
    MessageDescription { "WebPageProxy_ShowMediaControlsContextMenuReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    MessageDescription { "WebPageProxy_ShowPDFContextMenuReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPageProxy_ShowShareSheetReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(SPEECH_SYNTHESIS)
    MessageDescription { "WebPageProxy_SpeechSynthesisPauseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_SpeechSynthesisResumeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_SpeechSynthesisSetFinishedCallbackReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageProxy_SpeechSynthesisSpeakReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(APPLE_PAY_AMS_UI)
    MessageDescription { "WebPageProxy_StartApplePayAMSUISessionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPageProxy_ValidateCaptureStateUpdateReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPageProxy_WillSubmitFormReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageTesting_ClearCachedBackForwardListCountsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageTesting_DisplayAndTrackRepaintsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageTesting_IsLayerTreeFrozenReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageTesting_SetObscuredContentInsetsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPageTesting_SetTracksRepaintsReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_AddDictationAlternativeReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_AddLayerForFindOverlayReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_AdjustVisibilityForTargetedElementsReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ApplyAutocorrectionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPage_AttributedSubstringForCharacterRangeAsyncReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_BeginSelectionInDirectionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_CharacterIndexForPointAsyncReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ClearServiceWorkerEntitlementOverrideReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_CommitPotentialTapReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_CompleteTextManipulationReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_CompositionSessionDidReceiveTextWithReplacementRangeReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_ComputePagesForPrintingDuringDOMPrintOperationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ComputePagesForPrintingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ContentsToRootViewPointReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ContentsToRootViewRectReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_CountStringMatchesReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(APP_HIGHLIGHTS)
    MessageDescription { "WebPage_CreateAppHighlightInSelectedRangeReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_CreateBitmapsFromImageDataReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    MessageDescription { "WebPage_CreateMediaSessionCoordinatorReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_CreateTextFragmentDirectiveFromSelectionReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_CreateTextIndicatorForElementWithIDReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_CreateTextIndicatorForTextAnimationIDReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_DecodeImageDataReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_DecorateTextReplacementsForActiveWritingToolsSessionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(DATA_DETECTION)
    MessageDescription { "WebPage_DetectDataInAllFramesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_DictationAlternativesAtSelectionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_DidGetLoadDecisionForIconReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_DispatchWheelEventWithoutScrollingReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_DragEndedReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(GTK)
    MessageDescription { "WebPage_DrawPagesForPrintingDuringDOMPrintOperationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_DrawPagesForPrintingReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_DrawPagesToPDFDuringDOMPrintOperationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_DrawPagesToPDFReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_DrawRectToImageDuringDOMPrintOperationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_DrawRectToImageReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    MessageDescription { "WebPage_DrawToImageReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_DrawToPDFReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    MessageDescription { "WebPage_DrawToPDFiOSReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_EndPrintingDuringDOMPrintOperationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_EndPrintingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ExecuteEditCommandWithCallbackReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ExtendSelectionForReplacementReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ExtendSelectionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_FindRectsForStringMatchesReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(IMAGE_ANALYSIS)
    MessageDescription { "WebPage_FindStringIncludingImagesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_FindStringMatchesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_FindStringReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_FindTextRangesForStringMatchesReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_FirstRectForCharacterRangeAsyncReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_FocusNextFocusedElementReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_FocusTextInputContextAndPlaceCaretReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_GetAccessibilityTreeDataReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(APPLICATION_MANIFEST)
    MessageDescription { "WebPage_GetApplicationManifestReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_GetBytecodeProfileReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetContentsAsAttributedStringReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(MHTML)
    MessageDescription { "WebPage_GetContentsAsMHTMLDataReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_GetContentsAsStringReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetFrameTreeReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetInformationFromImageDataReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_GetLoadedSubresourceDomainsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetMainResourceDataOfFrameReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetMarkedRangeAsyncReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_GetPDFFirstPageSizeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetProcessDisplayNameReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_GetRectsAtSelectionOffsetWithTextReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetRectsForGranularityWithSelectionOffsetReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_GetRenderTreeExternalRepresentationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetResourceDataFromFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetSamplingProfilerOutputReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetSelectedRangeAsyncReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_GetSelectionAsWebArchiveDataReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_GetSelectionContextReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_GetSelectionOrContentsAsStringReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetSourceForFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetTextFragmentMatchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetTextFragmentRangesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetWebArchiveOfFrameReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_GetWebArchiveOfFrameWithFileNameReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetWebArchivesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_HandleWheelEventReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_HasMarkedTextReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPage_InsertAttachmentReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_InsertDroppedImagePlaceholdersReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_InsertTextPlaceholderReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_LastNavigationWasAppInitiatedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_LoadAndDecodeImageReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_MoveSelectionAtBoundaryWithDirectionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_MoveSelectionByOffsetReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_NavigateServiceWorkerClientReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_NumberOfVisibilityAdjustmentRectsReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    MessageDescription { "WebPage_OpenPDFWithPreviewReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    MessageDescription { "WebPage_PauseAllAnimationsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_PauseAllMediaPlaybackReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_PerformActionOnElementReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(GTK) && ENABLE(DRAG_SUPPORT) || !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_PerformDragControllerActionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_PerformDragOperationReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_PerformHitTestForMouseEventReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    MessageDescription { "WebPage_PlayAllAnimationsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_PotentialTapAtPositionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    MessageDescription { "WebPage_PrepareSelectionForContextMenuWithLocationInViewReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_ProofreadingSessionDidReceiveSuggestionsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ProofreadingSessionSuggestionTextRectsInRootViewCoordinatesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_RemoteDictionaryPopupInfoToRootViewReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(DATA_DETECTION)
    MessageDescription { "WebPage_RemoveDataDetectedLinksReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_RemoveLayerForFindOverlayReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_RemoveTextPlaceholderReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_ReplaceMatchesReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_RequestActiveNowPlayingSessionInfoReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_RequestAdditionalItemsForDragSessionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_RequestAllTargetableElementsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_RequestAllTextAndRectsReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_RequestAutocorrectionDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_RequestDocumentEditingContextReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    MessageDescription { "WebPage_RequestDragStartReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_RequestEvasionRectsAboveSelectionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_RequestFocusedElementInformationReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_RequestFontAttributesAtSelectionStartReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_RequestImageBitmapReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_RequestMediaPlaybackStateReply"_s, ReceiverName::AsyncReply, false, false },
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    MessageDescription { "WebPage_RequestRVItemInCurrentSelectedRangeReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_RequestRectForFoundTextRangeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_RequestTargetedElementReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_RequestTextExtractionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ResetVisibilityAdjustmentsForTargetedElementsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ResolveAccessibilityHitTestForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ResumeAllMediaPlaybackReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_ResumeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_RunJavaScriptInFrameInScriptWorldReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    MessageDescription { "WebPage_SavePDFReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SelectPositionAtBoundaryWithDirectionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SelectPositionAtPointReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SelectTextWithGranularityAtPointReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SelectWithGestureReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SelectWithTwoTouchesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPage_SendMessageToWebProcessExtensionWithReplyReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_SetActivityStateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SetInitialFocusReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SetIsSuspendedReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SetMutedReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_SetSelectionForActiveWritingToolsSessionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    MessageDescription { "WebPage_ShouldAllowRemoveBackgroundReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_ShouldDismissKeyboardAfterTapAtPointReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_SimulateClickOverFirstMatchingTextInViewportWithUserInteractionReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(VIDEO_PRESENTATION_MODE)
    MessageDescription { "WebPage_StartPlayingPredominantVideoReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_StartTextManipulationsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_StopMediaCaptureReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SuspendAllMediaPlaybackReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_SuspendReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_TakeSnapshotForTargetedElementReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_TakeSnapshotReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_TextInputContextsInRectReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_TextPreviewDataForActiveWritingToolsSessionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
    MessageDescription { "WebPage_TouchEventReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_TryCloseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_URLSchemeTaskWillPerformRedirectionReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPage_UpdateAttachmentAttributesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_UpdateRenderingWithForcedRepaintReply"_s, ReceiverName::AsyncReply, false, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_UpdateSelectionWithDeltaReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_UpdateSelectionWithExtentPointAndBoundaryReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_UpdateSelectionWithExtentPointReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_UpdateSelectionWithTouchesReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_UpdateTextVisibilityForActiveWritingToolsSessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_UpdateUnderlyingTextVisibilityForTextAnimationIDReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(IMAGE_ANALYSIS)
    MessageDescription { "WebPage_UpdateWithTextRecognitionResultReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(MEDIA_STREAM)
    MessageDescription { "WebPage_UserMediaAccessWasGrantedReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPage_ValidateCommandReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WRITING_TOOLS)
    MessageDescription { "WebPage_WillBeginWritingToolsSessionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebPage_WillEndWritingToolsSessionReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebPermissionControllerProxy_QueryReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(GAMEPAD)
    MessageDescription { "WebProcessPool_PlayGamepadEffectReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcessPool_StopGamepadEffectsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcessPool_StoppedUsingGamepadsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    MessageDescription { "WebProcessProxy_CreateServiceWorkerDebuggableReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if ENABLE(NOTIFICATION_EVENT)
    MessageDescription { "WebProcessProxy_GetNotificationsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebProcessProxy_SendMessageToWebContextWithReplyReply"_s, ReceiverName::AsyncReply, false, false },
#endif
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING)) || (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && !ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
    MessageDescription { "WebProcessProxy_SetupLogStreamReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebProcess_ClearCachedPageReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_DeleteAllCookiesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_DeleteWebsiteDataForOriginReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_DeleteWebsiteDataForOriginsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_DeleteWebsiteDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_EstablishRemoteWorkerContextConnectionToNetworkProcessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_FetchWebsiteDataReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_GetActivePagesOriginsForTestingReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(NOTIFY_BLOCKING)
    MessageDescription { "WebProcess_GetNotifyStateForTestingReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebProcess_InitializeWebProcessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_IsJITEnabledReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_PrepareToSuspendReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_RegisterServiceWorkerClientsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_ReleaseMemoryReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_ReloadExecutionContextsForOriginReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_SeedResourceLoadStatisticsForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_SendResourceLoadStatisticsDataImmediatelyReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_SetDomainsWithCrossPageStorageAccessReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebProcess_SetIsInProcessCacheReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(CONTENT_EXTENSIONS)
    MessageDescription { "WebProcess_SetResourceMonitorContentRuleListAsyncReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebProcess_SetThirdPartyCookieBlockingModeReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebResourceLoader_WillSendRequestReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWClientConnection_FocusServiceWorkerClientReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWClientConnection_SetServiceWorkerClientIsControlledReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWContextManagerConnection_FireBackgroundFetchClickEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWContextManagerConnection_FireBackgroundFetchEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWContextManagerConnection_FireNotificationEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWContextManagerConnection_FirePushEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_AbortBackgroundFetchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_AddCookieChangeSubscriptionsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_AddRoutesReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_BackgroundFetchIdentifiersReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_BackgroundFetchInformationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_CookieChangeSubscriptionsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_DisableNavigationPreloadReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_EnableNavigationPreloadReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_GetNavigationPreloadStateReply"_s, ReceiverName::AsyncReply, false, false },
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    MessageDescription { "WebSWServerConnection_GetNotificationsReply"_s, ReceiverName::AsyncReply, false, false },
#endif
    MessageDescription { "WebSWServerConnection_GetPushPermissionStateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_GetPushSubscriptionReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_GetRegistrationsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_MatchBackgroundFetchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_MatchRegistrationReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_RemoveCookieChangeSubscriptionsReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_RetrieveRecordResponseReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_ScheduleUnregisterJobInServerReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_SetNavigationPreloadHeaderValueReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_StartBackgroundFetchReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_StoreRegistrationsOnDiskReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_SubscribeToPushServiceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_TerminateWorkerFromClientReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_UnsubscribeFromPushServiceReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_WhenRegistrationReadyReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerConnection_WhenServiceWorkerIsTerminatedForTestingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerToContextConnection_ClaimReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerToContextConnection_FindClientByVisibleIdentifierReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerToContextConnection_FocusReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerToContextConnection_MatchAllReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerToContextConnection_NavigateReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerToContextConnection_OpenWindowReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSWServerToContextConnection_SkipWaitingReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebScreenOrientationManagerProxy_LockReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSharedWorkerContextManagerConnection_PostConnectEventReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebSharedWorkerObjectConnection_FetchScriptInClientReply"_s, ReceiverName::AsyncReply, false, false },
    MessageDescription { "WebUserContentControllerProxy_DidPostMessageReply"_s, ReceiverName::AsyncReply, false, false },
#if USE(AUDIO_SESSION)
    MessageDescription { "GPUConnectionToWebProcess_EnsureAudioSession"_s, ReceiverName::GPUConnectionToWebProcess, true, false },
#endif
    MessageDescription { "IPCConnectionTester_SyncMessage"_s, ReceiverName::IPCConnectionTester, true, false },
    MessageDescription { "IPCStreamTester_CheckAutoreleasePool"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCStreamTester_SyncCrashOnZero"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCStreamTester_SyncMessage"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCStreamTester_SyncMessageEmptyReply"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCStreamTester_SyncMessageNotStreamEncodableBoth"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCStreamTester_SyncMessageNotStreamEncodableReply"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCStreamTester_SyncMessageReturningSharedMemory1"_s, ReceiverName::IPCStreamTester, true, false },
    MessageDescription { "IPCTester_ReleaseConnectionTester"_s, ReceiverName::IPCTester, true, false },
    MessageDescription { "IPCTester_ReleaseStreamTester"_s, ReceiverName::IPCTester, true, false },
    MessageDescription { "IPCTester_StopMessageTesting"_s, ReceiverName::IPCTester, true, false },
    MessageDescription { "IPCTester_SyncPing"_s, ReceiverName::IPCTester, true, false },
    MessageDescription { "IPCTester_SyncPingEmptyReply"_s, ReceiverName::IPCTester, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_BlobSize"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_BlobType"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_CookieRequestHeaderFieldValue"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_CookiesEnabledSync"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_CookiesForDOM"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_DomCookiesForHost"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_GetNetworkLoadInformationResponse"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_GetNetworkLoadIntermediateInformation"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_GetRawCookies"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_PerformSynchronousLoad"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_TakeNetworkLoadInformationMetrics"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkConnectionToWebProcess_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply"_s, ReceiverName::NetworkConnectionToWebProcess, true, false },
    MessageDescription { "NetworkProcessProxy_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply"_s, ReceiverName::NetworkProcessProxy, true, false },
    MessageDescription { "NetworkProcess_ProcessWillSuspendImminentlyForTestingSync"_s, ReceiverName::NetworkProcess, true, false },
    MessageDescription { "NetworkProcess_ResetServiceWorkerFetchTimeoutForTesting"_s, ReceiverName::NetworkProcess, true, false },
    MessageDescription { "NetworkProcess_SetCacheModelSynchronouslyForTesting"_s, ReceiverName::NetworkProcess, true, false },
    MessageDescription { "NetworkProcess_SetServiceWorkerFetchTimeoutForTesting"_s, ReceiverName::NetworkProcess, true, false },
    MessageDescription { "NetworkStorageManager_ConnectToStorageAreaSync"_s, ReceiverName::NetworkStorageManager, true, false },
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    MessageDescription { "NotificationManagerMessageHandler_GetPermissionStateSync"_s, ReceiverName::NotificationManagerMessageHandler, true, false },
#endif
    MessageDescription { "RemoteAdapter_RequestDevice"_s, ReceiverName::RemoteAdapter, true, false },
    MessageDescription { "RemoteAudioSessionProxy_TryToSetActive"_s, ReceiverName::RemoteAudioSessionProxy, true, false },
    MessageDescription { "RemoteBindGroup_UpdateExternalTextures"_s, ReceiverName::RemoteBindGroup, true, false },
    MessageDescription { "RemoteBuffer_GetMappedRange"_s, ReceiverName::RemoteBuffer, true, false },
    MessageDescription { "RemoteCDMFactoryProxy_CreateCDM"_s, ReceiverName::RemoteCDMFactoryProxy, true, false },
    MessageDescription { "RemoteCDMFactoryProxy_SupportsKeySystem"_s, ReceiverName::RemoteCDMFactoryProxy, true, false },
    MessageDescription { "RemoteCDMInstanceProxy_CreateSession"_s, ReceiverName::RemoteCDMInstanceProxy, true, false },
    MessageDescription { "RemoteCDMProxy_CreateInstance"_s, ReceiverName::RemoteCDMProxy, true, false },
    MessageDescription { "RemoteCompositorIntegration_PaintCompositedResultsToCanvas"_s, ReceiverName::RemoteCompositorIntegration, true, false },
    MessageDescription { "RemoteCompositorIntegration_PrepareForDisplay"_s, ReceiverName::RemoteCompositorIntegration, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteCompositorIntegration_RecreateRenderBuffers"_s, ReceiverName::RemoteCompositorIntegration, true, false },
#endif
    MessageDescription { "RemoteGPU_IsValid"_s, ReceiverName::RemoteGPU, true, false },
    MessageDescription { "RemoteGPU_RequestAdapter"_s, ReceiverName::RemoteGPU, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_AddFoveation"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_CheckFramebufferStatus"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ClientWaitSync"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(VIDEO) && PLATFORM(COCOA)
    MessageDescription { "RemoteGraphicsContextGL_CopyTextureFromVideoFrame"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_DrawSurfaceBufferToImageBuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(WEBXR)
    MessageDescription { "RemoteGraphicsContextGL_EnableRequiredWebXRExtensions"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_FenceSync"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetActiveAttrib"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetActiveUniform"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetActiveUniformBlockName"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetActiveUniformBlockiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetActiveUniforms"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetAttribLocation"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetBooleanv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetBufferParameteri"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetBufferSubDataInline"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetBufferSubDataSharedMemory"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetErrors"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetFloatv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetFragDataLocation"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetFramebufferAttachmentParameteri"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetInteger64"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetInteger64EXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetInteger64i"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetIntegeri_v"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetIntegerv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetInternalformativ"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetProgramInfoLog"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetProgrami"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetQuery"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetQueryObjectiEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetQueryObjectui"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetQueryObjectui64EXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetQueryiEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetRenderbufferParameteri"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetSamplerParameterf"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetSamplerParameteri"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetShaderInfoLog"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetShaderPrecisionFormat"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetShaderSource"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetShaderi"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetString"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetSynci"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetTexParameterf"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetTexParameteri"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetTransformFeedbackVarying"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetTranslatedShaderSourceANGLE"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetUniformBlockIndex"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetUniformIndices"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetUniformLocation"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetUniformfv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetUniformiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetUniformuiv"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_GetVertexAttribOffset"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsBuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsEnabled"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsFramebuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsProgram"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsQuery"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsQueryEXT"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsRenderbuffer"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsSampler"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsShader"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsSync"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsTexture"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsTransformFeedback"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_IsVertexArray"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if PLATFORM(COCOA) || USE(GRAPHICS_LAYER_WC) || USE(GBM) || !PLATFORM(COCOA) && !USE(GRAPHICS_LAYER_WC) && !USE(GBM)
    MessageDescription { "RemoteGraphicsContextGL_PrepareForDisplay"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
    MessageDescription { "RemoteGraphicsContextGL_ReadPixelsInline"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
    MessageDescription { "RemoteGraphicsContextGL_ReadPixelsSharedMemory"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#if ENABLE(MEDIA_STREAM) || ENABLE(WEB_CODECS)
    MessageDescription { "RemoteGraphicsContextGL_SurfaceBufferToVideoFrame"_s, ReceiverName::RemoteGraphicsContextGL, true, false },
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
    MessageDescription { "RemoteImageBufferSet_DynamicContentScalingDisplayList"_s, ReceiverName::RemoteImageBufferSet, true, false },
    MessageDescription { "RemoteImageBuffer_DynamicContentScalingDisplayList"_s, ReceiverName::RemoteImageBuffer, true, false },
#endif
    MessageDescription { "RemoteImageBuffer_FilteredNativeImage"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteImageBuffer_FlushContextSync"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteImageBuffer_GetPixelBuffer"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteImageBuffer_GetPixelBufferWithNewMemory"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteImageBuffer_GetShareableBitmap"_s, ReceiverName::RemoteImageBuffer, true, false },
    MessageDescription { "RemoteLegacyCDMFactoryProxy_CreateCDM"_s, ReceiverName::RemoteLegacyCDMFactoryProxy, true, false },
    MessageDescription { "RemoteLegacyCDMFactoryProxy_SupportsKeySystem"_s, ReceiverName::RemoteLegacyCDMFactoryProxy, true, false },
    MessageDescription { "RemoteLegacyCDMProxy_CreateSession"_s, ReceiverName::RemoteLegacyCDMProxy, true, false },
    MessageDescription { "RemoteLegacyCDMProxy_SupportsMIMEType"_s, ReceiverName::RemoteLegacyCDMProxy, true, false },
    MessageDescription { "RemoteLegacyCDMSessionProxy_CachedKeyForKeyID"_s, ReceiverName::RemoteLegacyCDMSessionProxy, true, false },
    MessageDescription { "RemoteLegacyCDMSessionProxy_GenerateKeyRequest"_s, ReceiverName::RemoteLegacyCDMSessionProxy, true, false },
    MessageDescription { "RemoteLegacyCDMSessionProxy_Update"_s, ReceiverName::RemoteLegacyCDMSessionProxy, true, false },
    MessageDescription { "RemoteMediaPlayerManagerProxy_GetSupportedTypes"_s, ReceiverName::RemoteMediaPlayerManagerProxy, true, false },
    MessageDescription { "RemoteMediaPlayerManagerProxy_SupportsKeySystem"_s, ReceiverName::RemoteMediaPlayerManagerProxy, true, false },
    MessageDescription { "RemoteMediaPlayerManagerProxy_SupportsTypeAndCodecs"_s, ReceiverName::RemoteMediaPlayerManagerProxy, true, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "RemoteMediaPlayerProxy_AccessLog"_s, ReceiverName::RemoteMediaPlayerProxy, true, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "RemoteMediaPlayerProxy_ColorSpace"_s, ReceiverName::RemoteMediaPlayerProxy, true, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "RemoteMediaPlayerProxy_ErrorLog"_s, ReceiverName::RemoteMediaPlayerProxy, true, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_IsCrossOrigin"_s, ReceiverName::RemoteMediaPlayerProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteMediaPlayerProxy_NativeImageForCurrentTime"_s, ReceiverName::RemoteMediaPlayerProxy, true, false },
#endif
    MessageDescription { "RemoteMediaPlayerProxy_VideoFrameForCurrentTimeIfChanged"_s, ReceiverName::RemoteMediaPlayerProxy, true, false },
    MessageDescription { "RemoteMediaSourceProxy_AddSourceBuffer"_s, ReceiverName::RemoteMediaSourceProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteRenderingBackend_PrepareImageBufferSetsForDisplaySync"_s, ReceiverName::RemoteRenderingBackend, true, false },
#endif
    MessageDescription { "RemoteSourceBufferProxy_CanSwitchToType"_s, ReceiverName::RemoteSourceBufferProxy, true, false },
    MessageDescription { "RemoteSourceBufferProxy_EvictCodedFrames"_s, ReceiverName::RemoteSourceBufferProxy, true, false },
    MessageDescription { "RemoteSourceBufferProxy_MinimumUpcomingPresentationTimeForTrackID"_s, ReceiverName::RemoteSourceBufferProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "RemoteVideoFrameObjectHeap_ConvertFrameBuffer"_s, ReceiverName::RemoteVideoFrameObjectHeap, true, false },
    MessageDescription { "RemoteVideoFrameObjectHeap_PixelBuffer"_s, ReceiverName::RemoteVideoFrameObjectHeap, true, false },
#endif
    MessageDescription { "WebPageProxy_AccessibilityScreenToRootView"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_BackForwardGoToItem"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_BackForwardItemAtIndex"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_BackForwardListContainsItem"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_BackForwardListCounts"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_BindRemoteAccessibilityFrames"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_CanUndoRedo"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_CheckGrammarOfString"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_CheckSpellingOfString"_s, ReceiverName::WebPageProxy, true, false },
#if USE(UNIFIED_TEXT_CHECKING)
    MessageDescription { "WebPageProxy_CheckTextOfParagraph"_s, ReceiverName::WebPageProxy, true, false },
#endif
    MessageDescription { "WebPageProxy_CreateNewPage"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_DecidePolicyForNavigationActionSync"_s, ReceiverName::WebPageProxy, true, false },
#if USE(DICTATION_ALTERNATIVES)
    MessageDescription { "WebPageProxy_DictationAlternatives"_s, ReceiverName::WebPageProxy, true, false },
#endif
#if PLATFORM(MAC)
    MessageDescription { "WebPageProxy_DismissCorrectionPanelSoon"_s, ReceiverName::WebPageProxy, true, false },
#endif
    MessageDescription { "WebPageProxy_ExceededDatabaseQuota"_s, ReceiverName::WebPageProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPageProxy_ExecuteSavedCommandBySelector"_s, ReceiverName::WebPageProxy, true, false },
#endif
    MessageDescription { "WebPageProxy_ExecuteUndoRedo"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_FrameTextForTesting"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_GetGuessesForWord"_s, ReceiverName::WebPageProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPageProxy_GetIsSpeaking"_s, ReceiverName::WebPageProxy, true, false },
#endif
    MessageDescription { "WebPageProxy_GetMenuBarIsVisible"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_GetStatusBarIsVisible"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_GetToolbarsAreVisible"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_GetWindowFrame"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_HandleSynchronousMessage"_s, ReceiverName::WebPageProxy, true, false },
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPageProxy_InterpretKeyEvent"_s, ReceiverName::WebPageProxy, true, false },
#endif
    MessageDescription { "WebPageProxy_LayerTreeAsTextForTesting"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_LoadRecentSearches"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_LoadSynchronousURLSchemeTask"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_PrintFrame"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RenderTreeAsTextForTesting"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RequestDOMPasteAccess"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RootViewPointToScreen"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RootViewRectToScreen"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RootViewToAccessibilityScreen"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RunBeforeUnloadConfirmPanel"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RunJavaScriptAlert"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RunJavaScriptConfirm"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_RunJavaScriptPrompt"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_ScreenToRootView"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageProxy_SerializeAndWrapCryptoKey"_s, ReceiverName::WebPageProxy, true, false },
#if ENABLE(ATTACHMENT_ELEMENT)
    MessageDescription { "WebPageProxy_SerializedAttachmentDataForIdentifiers"_s, ReceiverName::WebPageProxy, true, false },
#endif
    MessageDescription { "WebPageProxy_ShouldGoToBackForwardListItemSync"_s, ReceiverName::WebPageProxy, true, false },
#if ENABLE(SPEECH_SYNTHESIS)
    MessageDescription { "WebPageProxy_SpeechSynthesisVoiceList"_s, ReceiverName::WebPageProxy, true, false },
#endif
    MessageDescription { "WebPageProxy_SpellingUIIsShowing"_s, ReceiverName::WebPageProxy, true, false },
#if USE(APPKIT)
    MessageDescription { "WebPageProxy_SubstitutionsPanelIsShowing"_s, ReceiverName::WebPageProxy, true, false },
#endif
    MessageDescription { "WebPageProxy_UnwrapCryptoKey"_s, ReceiverName::WebPageProxy, true, false },
    MessageDescription { "WebPageTesting_IsEditingCommandEnabled"_s, ReceiverName::WebPageTesting, true, false },
    MessageDescription { "WebPage_BindRemoteAccessibilityFrames"_s, ReceiverName::WebPage, true, false },
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    MessageDescription { "WebPage_ComputePagesForPrintingiOS"_s, ReceiverName::WebPage, true, false },
#endif
    MessageDescription { "WebPage_FrameTextForTesting"_s, ReceiverName::WebPage, true, false },
#if PLATFORM(MAC)
    MessageDescription { "WebPage_GetAccessibilityWebProcessDebugInfo"_s, ReceiverName::WebPage, true, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_GetDataSelectionForPasteboard"_s, ReceiverName::WebPage, true, false },
    MessageDescription { "WebPage_GetStringSelectionForPasteboard"_s, ReceiverName::WebPage, true, false },
#endif
    MessageDescription { "WebPage_LayerTreeAsTextForTesting"_s, ReceiverName::WebPage, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_ReadSelectionFromPasteboard"_s, ReceiverName::WebPage, true, false },
#endif
    MessageDescription { "WebPage_RenderTreeAsTextForTesting"_s, ReceiverName::WebPage, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPage_ShouldDelayWindowOrderingEvent"_s, ReceiverName::WebPage, true, false },
#endif
#if PLATFORM(IOS_FAMILY)
    MessageDescription { "WebPage_SyncApplyAutocorrection"_s, ReceiverName::WebPage, true, false },
#endif
    MessageDescription { "WebPage_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply"_s, ReceiverName::WebPage, true, true },
#if PLATFORM(COCOA)
    MessageDescription { "WebPasteboardProxy_AddPasteboardTypes"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
    MessageDescription { "WebPasteboardProxy_AllPasteboardItemInfo"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_ContainsStringSafeForDOMToReadForType"_s, ReceiverName::WebPasteboardProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPasteboardProxy_ContainsURLStringSuitableForLoading"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_GetNumberOfFiles"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_GetPasteboardBufferForType"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_GetPasteboardChangeCount"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPasteboardProxy_GetPasteboardColor"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
    MessageDescription { "WebPasteboardProxy_GetPasteboardItemsCount"_s, ReceiverName::WebPasteboardProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPasteboardProxy_GetPasteboardPathnamesForType"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_GetPasteboardStringForType"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_GetPasteboardStringsForType"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
#if PLATFORM(COCOA) || USE(LIBWPE) && !PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_GetPasteboardTypes"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
#if PLATFORM(COCOA)
    MessageDescription { "WebPasteboardProxy_GetPasteboardURL"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_GetTypes"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
    MessageDescription { "WebPasteboardProxy_InformationForItemAtIndex"_s, ReceiverName::WebPasteboardProxy, true, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_ReadBuffer"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
    MessageDescription { "WebPasteboardProxy_ReadBufferFromPasteboard"_s, ReceiverName::WebPasteboardProxy, true, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_ReadFilePaths"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
    MessageDescription { "WebPasteboardProxy_ReadStringFromPasteboard"_s, ReceiverName::WebPasteboardProxy, true, false },
#if PLATFORM(GTK) || PLATFORM(WPE)
    MessageDescription { "WebPasteboardProxy_ReadText"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
    MessageDescription { "WebPasteboardProxy_ReadURLFromPasteboard"_s, ReceiverName::WebPasteboardProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPasteboardProxy_SetPasteboardBufferForType"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_SetPasteboardColor"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_SetPasteboardStringForType"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_SetPasteboardTypes"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebPasteboardProxy_SetPasteboardURL"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
#if (PLATFORM(COCOA) && ENABLE(IPC_TESTING_API))
    MessageDescription { "WebPasteboardProxy_TestIPCSharedMemory"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
    MessageDescription { "WebPasteboardProxy_TypesSafeForDOMToReadAndWrite"_s, ReceiverName::WebPasteboardProxy, true, false },
#if PLATFORM(COCOA)
    MessageDescription { "WebPasteboardProxy_URLStringSuitableForLoading"_s, ReceiverName::WebPasteboardProxy, true, false },
#endif
    MessageDescription { "WebPasteboardProxy_WriteCustomData"_s, ReceiverName::WebPasteboardProxy, true, false },
    MessageDescription { "WebProcessPool_HandleSynchronousMessage"_s, ReceiverName::WebProcessPool, true, false },
    MessageDescription { "WebProcessProxy_GetNetworkProcessConnection"_s, ReceiverName::WebProcessProxy, true, false },
#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
    MessageDescription { "WebProcessProxy_IsAXAuthenticated"_s, ReceiverName::WebProcessProxy, true, false },
#endif
    MessageDescription { "WebProcessProxy_SerializeAndWrapCryptoKey"_s, ReceiverName::WebProcessProxy, true, false },
    MessageDescription { "WebProcessProxy_ShouldTerminate"_s, ReceiverName::WebProcessProxy, true, false },
    MessageDescription { "WebProcessProxy_UnwrapCryptoKey"_s, ReceiverName::WebProcessProxy, true, false },
    MessageDescription { "WebProcessProxy_WaitForSharedPreferencesForWebProcessToSync"_s, ReceiverName::WebProcessProxy, true, false },
    MessageDescription { "WebScreenOrientationManagerProxy_CurrentOrientation"_s, ReceiverName::WebScreenOrientationManagerProxy, true, false },
    MessageDescription { "WrappedAsyncMessageForTesting"_s, ReceiverName::IPC, true, false },
    MessageDescription { "<invalid message name>"_s, ReceiverName::Invalid, false, false }
};

} // namespace IPC::Detail
